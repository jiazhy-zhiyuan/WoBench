#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
/*
 * Copyright (c) 2018 Paul B Mahol
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include <float.h>

#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/opt.h"
#include "audio.h"
#include "avfilter.h"
#include "internal.h"

typedef struct ThreadData {
    AVFrame *in, *out;
} ThreadData;

typedef struct Pair {
    int a, b;
} Pair;

typedef struct BiquadContext {
    double a0, a1, a2;
    double b0, b1, b2;
    double i1, i2;
    double o1, o2;
} BiquadContext;

typedef struct IIRChannel {
    int nb_ab[2];
    double *ab[2];
    double g;
    double *cache[2];
    BiquadContext *biquads;
    int clippings;
} IIRChannel;

typedef struct AudioIIRContext {
    const AVClass *class;
    char *a_str, *b_str, *g_str;
    double dry_gain, wet_gain;
    int format;
    int process;
    int precision;

    IIRChannel *iir;
    int channels;
    enum AVSampleFormat sample_format;

    int (*iir_channel)(AVFilterContext *ctx, void *arg, int ch, int nb_jobs);
} AudioIIRContext;

static int query_formats(AVFilterContext *ctx)
{
    AudioIIRContext *s = ctx->priv;
    AVFilterFormats *formats;
    AVFilterChannelLayouts *layouts;
    enum AVSampleFormat sample_fmts[] = {
        AV_SAMPLE_FMT_DBLP,
        AV_SAMPLE_FMT_NONE
    };
    int ret;

    layouts = ff_all_channel_counts();
    if (!layouts)
        return AVERROR(ENOMEM);
    ret = ff_set_common_channel_layouts(ctx, layouts);
    if (ret < 0)
        return ret;

    sample_fmts[0] = s->sample_format;
    formats = ff_make_format_list(sample_fmts);
    if (!formats)
        return AVERROR(ENOMEM);
    ret = ff_set_common_formats(ctx, formats);
    if (ret < 0)
        return ret;

    formats = ff_all_samplerates();
    if (!formats)
        return AVERROR(ENOMEM);
    return ff_set_common_samplerates(ctx, formats);
}

#define IIR_CH(name, type, min, max, need_clipping)                     \
static int iir_ch_## name(AVFilterContext *ctx, void *arg, int ch, int nb_jobs)  \
{                                                                       \
    AudioIIRContext *s = ctx->priv;                                     \
    const double ig = s->dry_gain;                                      \
    const double og = s->wet_gain;                                      \
    ThreadData *td = arg;                                               \
    AVFrame *in = td->in, *out = td->out;                               \
    const type *src = (const type *)in->extended_data[ch];              \
    double *ic = (double *)s->iir[ch].cache[0];                         \
    double *oc = (double *)s->iir[ch].cache[1];                         \
    const int nb_a = s->iir[ch].nb_ab[0];                               \
    const int nb_b = s->iir[ch].nb_ab[1];                               \
    const double *a = s->iir[ch].ab[0];                                 \
    const double *b = s->iir[ch].ab[1];                                 \
    int *clippings = &s->iir[ch].clippings;                             \
    type *dst = (type *)out->extended_data[ch];                         \
    int n;                                                              \
                                                                        \
    for (n = 0; n < in->nb_samples; n++) {                              \
        double sample = 0.;                                             \
        int x;                                                          \
                                                                        \
        memmove(&ic[1], &ic[0], (nb_b - 1) * sizeof(*ic));              \
        memmove(&oc[1], &oc[0], (nb_a - 1) * sizeof(*oc));              \
        ic[0] = src[n] * ig;                                            \
        for (x = 0; x < nb_b; x++)                                      \
            sample += b[x] * ic[x];                                     \
                                                                        \
        for (x = 1; x < nb_a; x++)                                      \
            sample -= a[x] * oc[x];                                     \
                                                                        \
        oc[0] = sample;                                                 \
        sample *= og;                                                   \
        if (need_clipping && sample < min) {                            \
            (*clippings)++;                                             \
            dst[n] = min;                                               \
        } else if (need_clipping && sample > max) {                     \
            (*clippings)++;                                             \
            dst[n] = max;                                               \
        } else {                                                        \
            dst[n] = sample;                                            \
        }                                                               \
    }                                                                   \
                                                                        \
    return 0;                                                           \
}

IIR_CH(s16p, int16_t, INT16_MIN, INT16_MAX, 1)
IIR_CH(s32p, int32_t, INT32_MIN, INT32_MAX, 1)
IIR_CH(fltp, float,         -1.,        1., 0)
IIR_CH(dblp, double,        -1.,        1., 0)

#define SERIAL_IIR_CH(name, type, min, max, need_clipping)                  \
static int iir_ch_serial_## name(AVFilterContext *ctx, void *arg, int ch, int nb_jobs)  \
{                                                                       \
    AudioIIRContext *s = ctx->priv;                                     \
    const double ig = s->dry_gain;                                      \
    const double og = s->wet_gain;                                      \
    ThreadData *td = arg;                                               \
    AVFrame *in = td->in, *out = td->out;                               \
    const type *src = (const type *)in->extended_data[ch];              \
    type *dst = (type *)out->extended_data[ch];                         \
    IIRChannel *iir = &s->iir[ch];                                      \
    int *clippings = &iir->clippings;                                   \
    int nb_biquads = (FFMAX(iir->nb_ab[0], iir->nb_ab[1]) + 1) / 2;     \
    int n, i;                                                           \
                                                                        \
    for (i = 0; i < nb_biquads; i++) {                                  \
        const double a1 = -iir->biquads[i].a1;                          \
        const double a2 = -iir->biquads[i].a2;                          \
        const double b0 = iir->biquads[i].b0;                           \
        const double b1 = iir->biquads[i].b1;                           \
        const double b2 = iir->biquads[i].b2;                           \
        double i1 = iir->biquads[i].i1;                                 \
        double i2 = iir->biquads[i].i2;                                 \
        double o1 = iir->biquads[i].o1;                                 \
        double o2 = iir->biquads[i].o2;                                 \
                                                                        \
        for (n = 0; n < in->nb_samples; n++) {                          \
            double sample = ig * (i ? dst[n] : src[n]);                 \
            double o0 = sample * b0 + i1 * b1 + i2 * b2 + o1 * a1 + o2 * a2; \
                                                                        \
            i2 = i1;                                                    \
            i1 = src[n];                                                \
            o2 = o1;                                                    \
            o1 = o0;                                                    \
            o0 *= og;                                                   \
                                                                        \
            if (need_clipping && o0 < min) {                            \
                (*clippings)++;                                         \
                dst[n] = min;                                           \
            } else if (need_clipping && o0 > max) {                     \
                (*clippings)++;                                         \
                dst[n] = max;                                           \
            } else {                                                    \
                dst[n] = o0;                                            \
            }                                                           \
        }                                                               \
        iir->biquads[i].i1 = i1;                                        \
        iir->biquads[i].i2 = i2;                                        \
        iir->biquads[i].o1 = o1;                                        \
        iir->biquads[i].o2 = o2;                                        \
    }                                                                   \
                                                                        \
    return 0;                                                           \
}

SERIAL_IIR_CH(s16p, int16_t, INT16_MIN, INT16_MAX, 1)
SERIAL_IIR_CH(s32p, int32_t, INT32_MIN, INT32_MAX, 1)
SERIAL_IIR_CH(fltp, float,         -1.,        1., 0)
SERIAL_IIR_CH(dblp, double,        -1.,        1., 0)

static void count_coefficients(char *item_str, int *nb_items)
{
    char *p;

    if (!item_str)
        return;

    *nb_items = 1;
    for (p = item_str; *p && *p != '|'; p++) {
        if (*p == ' ')
            (*nb_items)++;
    }
}

static int read_gains(AVFilterContext *ctx, char *item_str, int nb_items)
{
    AudioIIRContext *s = ctx->priv;
    char *p, *arg, *old_str, *prev_arg = NULL, *saveptr = NULL;
    int i;

    p = old_str = av_strdup(item_str);
    if (!p)
        return AVERROR(ENOMEM);
    for (i = 0; i < nb_items; i++) {
        if (!(arg = av_strtok(p, "|", &saveptr)))
            arg = prev_arg;

        if (!arg) {
            av_freep(&old_str);
            return AVERROR(EINVAL);
        }

        p = NULL;
        if (sscanf(arg, "%lf", &s->iir[i].g) != 1) {
            av_log(ctx, AV_LOG_ERROR, "Invalid gains supplied: %s\n", arg);
            av_freep(&old_str);
            return AVERROR(EINVAL);
        }

        prev_arg = arg;
    }

    av_freep(&old_str);

    return 0;
}

static int read_tf_coefficients(AVFilterContext *ctx, char *item_str, int nb_items, double *dst)
{
    char *p, *arg, *old_str, *saveptr = NULL;
    int i;

    p = old_str = av_strdup(item_str);
    if (!p)
        return AVERROR(ENOMEM);
    for (i = 0; i < nb_items; i++) {
        if (!(arg = av_strtok(p, " ", &saveptr)))
            break;

        p = NULL;
        if (sscanf(arg, "%lf", &dst[i]) != 1) {
            av_log(ctx, AV_LOG_ERROR, "Invalid coefficients supplied: %s\n", arg);
            av_freep(&old_str);
            return AVERROR(EINVAL);
        }
    }

    av_freep(&old_str);

    return 0;
}

static int read_zp_coefficients(AVFilterContext *ctx, char *item_str, int nb_items, double *dst, const char *format)
{
    char *p, *arg, *old_str, *saveptr = NULL;
    int i;

    p = old_str = av_strdup(item_str);
    if (!p)
        return AVERROR(ENOMEM);
    for (i = 0; i < nb_items; i++) {
        if (!(arg = av_strtok(p, " ", &saveptr)))
            break;

        p = NULL;
        if (sscanf(arg, format, &dst[i*2], &dst[i*2+1]) != 2) {
            av_log(ctx, AV_LOG_ERROR, "Invalid coefficients supplied: %s\n", arg);
            av_freep(&old_str);
            return AVERROR(EINVAL);
        }
    }

    av_freep(&old_str);

    return 0;
}

static const char *format[] = { "%lf", "%lf %lfi", "%lf %lfr", "%lf %lfd" };

static int read_channels(AVFilterContext *ctx, int channels, uint8_t *item_str, int ab)
{
    AudioIIRContext *s = ctx->priv;
    char *p, *arg, *old_str, *prev_arg = NULL, *saveptr = NULL;
    int i, ret;

    p = old_str = av_strdup(item_str);
    if (!p)
        return AVERROR(ENOMEM);
    for (i = 0; i < channels; i++) {
        IIRChannel *iir = &s->iir[i];

        if (!(arg = av_strtok(p, "|", &saveptr)))
            arg = prev_arg;

        if (!arg) {
            av_freep(&old_str);
            return AVERROR(EINVAL);
        }

        count_coefficients(arg, &iir->nb_ab[ab]);

        p = NULL;
        iir->cache[ab] = av_calloc(iir->nb_ab[ab] + 1, sizeof(double));
        iir->ab[ab] = av_calloc(iir->nb_ab[ab] * (!!s->format + 1), sizeof(double));
        if (!iir->ab[ab] || !iir->cache[ab]) {
            av_freep(&old_str);
            return AVERROR(ENOMEM);
        }

        if (s->format) {
            ret = read_zp_coefficients(ctx, arg, iir->nb_ab[ab], iir->ab[ab], format[s->format]);
        } else {
            ret = read_tf_coefficients(ctx, arg, iir->nb_ab[ab], iir->ab[ab]);
        }
        if (ret < 0) {
            av_freep(&old_str);
            return ret;
        }
        prev_arg = arg;
    }

    av_freep(&old_str);

    return 0;
}

static void multiply(double wre, double wim, int npz, double *coeffs)
{
    double nwre = -wre, nwim = -wim;
    double cre, cim;
    int i;

    for (i = npz; i >= 1; i--) {
        cre = coeffs[2 * i + 0];
        cim = coeffs[2 * i + 1];

        coeffs[2 * i + 0] = (nwre * cre - nwim * cim) + coeffs[2 * (i - 1) + 0];
        coeffs[2 * i + 1] = (nwre * cim + nwim * cre) + coeffs[2 * (i - 1) + 1];
    }

    cre = coeffs[0];
    cim = coeffs[1];
    coeffs[0] = nwre * cre - nwim * cim;
    coeffs[1] = nwre * cim + nwim * cre;
}

static int expand(AVFilterContext *ctx, double *pz, int nb, double *coeffs)
{
    int i;

    coeffs[0] = 1.0;
    coeffs[1] = 0.0;

    for (i = 0; i < nb; i++) {
        coeffs[2 * (i + 1)    ] = 0.0;
        coeffs[2 * (i + 1) + 1] = 0.0;
    }

    for (i = 0; i < nb; i++)
        multiply(pz[2 * i], pz[2 * i + 1], nb, coeffs);

    for (i = 0; i < nb + 1; i++) {
        if (fabs(coeffs[2 * i + 1]) > FLT_EPSILON) {
            av_log(ctx, AV_LOG_ERROR, "coeff: %lf of z^%d is not real; poles/zeros are not complex conjugates.\n",
                   coeffs[2 * i + 1], i);
            return AVERROR(EINVAL);
        }
    }

    return 0;
}

static int convert_zp2tf(AVFilterContext *ctx, int channels)
{
    AudioIIRContext *s = ctx->priv;
    int ch, i, j, ret = 0;

    for (ch = 0; ch < channels; ch++) {
        IIRChannel *iir = &s->iir[ch];
        double *topc, *botc;

        topc = av_calloc((iir->nb_ab[0] + 1) * 2, sizeof(*topc));
        botc = av_calloc((iir->nb_ab[1] + 1) * 2, sizeof(*botc));
        if (!topc || !botc) {
            ret = AVERROR(ENOMEM);
            goto fail;
        }

        ret = expand(ctx, iir->ab[0], iir->nb_ab[0], botc);
        if (ret < 0) {
            goto fail;
        }

        ret = expand(ctx, iir->ab[1], iir->nb_ab[1], topc);
        if (ret < 0) {
            goto fail;
        }

        for (j = 0, i = iir->nb_ab[1]; i >= 0; j++, i--) {
            iir->ab[1][j] = topc[2 * i];
        }
        iir->nb_ab[1]++;

        for (j = 0, i = iir->nb_ab[0]; i >= 0; j++, i--) {
            iir->ab[0][j] = botc[2 * i];
        }
        iir->nb_ab[0]++;

fail:
        av_free(topc);
        av_free(botc);
        if (ret < 0)
            break;
    }

    return ret;
}

static int decompose_zp2biquads(AVFilterContext *ctx, int channels)
{
    AudioIIRContext *s = ctx->priv;
    int ch, ret;

    for (ch = 0; ch < channels; ch++) {
        IIRChannel *iir = &s->iir[ch];
        int nb_biquads = (FFMAX(iir->nb_ab[0], iir->nb_ab[1]) + 1) / 2;
        int current_biquad = 0;

        iir->biquads = av_calloc(nb_biquads, sizeof(BiquadContext));
        if (!iir->biquads)
            return AVERROR(ENOMEM);

        while (nb_biquads--) {
            Pair outmost_pole = { -1, -1 };
            Pair nearest_zero = { -1, -1 };
            double zeros[4] = { 0 };
            double poles[4] = { 0 };
            double b[6] = { 0 };
            double a[6] = { 0 };
            double min_distance = DBL_MAX;
            double max_mag = 0;
            int i;

            for (i = 0; i < iir->nb_ab[0]; i++) {
                double mag;

                if (isnan(iir->ab[0][2 * i]) || isnan(iir->ab[0][2 * i + 1]))
                    continue;
                mag = hypot(iir->ab[0][2 * i], iir->ab[0][2 * i + 1]);

                if (mag > max_mag) {
                    max_mag = mag;
                    outmost_pole.a = i;
                }
            }

            for (i = 0; i < iir->nb_ab[1]; i++) {
                if (isnan(iir->ab[0][2 * i]) || isnan(iir->ab[0][2 * i + 1]))
                    continue;

                if (iir->ab[0][2 * i    ] ==  iir->ab[0][2 * outmost_pole.a    ] &&
                    iir->ab[0][2 * i + 1] == -iir->ab[0][2 * outmost_pole.a + 1]) {
                    outmost_pole.b = i;
                    break;
                }
            }

            av_log(ctx, AV_LOG_VERBOSE, "outmost_pole is %d.%d\n", outmost_pole.a, outmost_pole.b);

            if (outmost_pole.a < 0 || outmost_pole.b < 0)
                return AVERROR(EINVAL);

            for (i = 0; i < iir->nb_ab[1]; i++) {
                double distance;

                if (isnan(iir->ab[1][2 * i]) || isnan(iir->ab[1][2 * i + 1]))
                    continue;
                distance = hypot(iir->ab[0][2 * outmost_pole.a    ] - iir->ab[1][2 * i    ],
                                 iir->ab[0][2 * outmost_pole.a + 1] - iir->ab[1][2 * i + 1]);

                if (distance < min_distance) {
                    min_distance = distance;
                    nearest_zero.a = i;
                }
            }

            for (i = 0; i < iir->nb_ab[1]; i++) {
                if (isnan(iir->ab[1][2 * i]) || isnan(iir->ab[1][2 * i + 1]))
                    continue;

                if (iir->ab[1][2 * i    ] ==  iir->ab[1][2 * nearest_zero.a    ] &&
                    iir->ab[1][2 * i + 1] == -iir->ab[1][2 * nearest_zero.a + 1]) {
                    nearest_zero.b = i;
                    break;
                }
            }

            av_log(ctx, AV_LOG_VERBOSE, "nearest_zero is %d.%d\n", nearest_zero.a, nearest_zero.b);

            if (nearest_zero.a < 0 || nearest_zero.b < 0)
                return AVERROR(EINVAL);

            poles[0] = iir->ab[0][2 * outmost_pole.a    ];
            poles[1] = iir->ab[0][2 * outmost_pole.a + 1];

            zeros[0] = iir->ab[1][2 * nearest_zero.a    ];
            zeros[1] = iir->ab[1][2 * nearest_zero.a + 1];

            if (nearest_zero.a == nearest_zero.b && outmost_pole.a == outmost_pole.b) {
                zeros[2] = 0;
                zeros[3] = 0;

                poles[2] = 0;
                poles[3] = 0;
            } else {
                poles[2] = iir->ab[0][2 * outmost_pole.b    ];
                poles[3] = iir->ab[0][2 * outmost_pole.b + 1];

                zeros[2] = iir->ab[1][2 * nearest_zero.b    ];
                zeros[3] = iir->ab[1][2 * nearest_zero.b + 1];
            }

            ret = expand(ctx, zeros, 2, b);
            if (ret < 0)
                return ret;

            ret = expand(ctx, poles, 2, a);
            if (ret < 0)
                return ret;

            iir->ab[0][2 * outmost_pole.a] = iir->ab[0][2 * outmost_pole.a + 1] = NAN;
            iir->ab[0][2 * outmost_pole.b] = iir->ab[0][2 * outmost_pole.b + 1] = NAN;
            iir->ab[1][2 * nearest_zero.a] = iir->ab[1][2 * nearest_zero.a + 1] = NAN;
            iir->ab[1][2 * nearest_zero.b] = iir->ab[1][2 * nearest_zero.b + 1] = NAN;

            iir->biquads[current_biquad].a0 = 1.0;
            iir->biquads[current_biquad].a1 = a[2] / a[4];
            iir->biquads[current_biquad].a2 = a[0] / a[4];
            iir->biquads[current_biquad].b0 = b[4] / a[4] * (current_biquad ? 1.0 : iir->g);
            iir->biquads[current_biquad].b1 = b[2] / a[4] * (current_biquad ? 1.0 : iir->g);
            iir->biquads[current_biquad].b2 = b[0] / a[4] * (current_biquad ? 1.0 : iir->g);

            av_log(ctx, AV_LOG_VERBOSE, "a=%lf %lf %lf:b=%lf %lf %lf\n",
                   iir->biquads[current_biquad].a0,
                   iir->biquads[current_biquad].a1,
                   iir->biquads[current_biquad].a2,
                   iir->biquads[current_biquad].b0,
                   iir->biquads[current_biquad].b1,
                   iir->biquads[current_biquad].b2);

            current_biquad++;
        }
    }

    return 0;
}

static void convert_pr2zp(AVFilterContext *ctx, int channels)
{
    AudioIIRContext *s = ctx->priv;
    int ch;

    for (ch = 0; ch < channels; ch++) {
        IIRChannel *iir = &s->iir[ch];
        int n;

        for (n = 0; n < iir->nb_ab[0]; n++) {
            double r = iir->ab[0][2*n];
            double angle = iir->ab[0][2*n+1];

            iir->ab[0][2*n]   = r * cos(angle);
            iir->ab[0][2*n+1] = r * sin(angle);
        }

        for (n = 0; n < iir->nb_ab[1]; n++) {
            double r = iir->ab[1][2*n];
            double angle = iir->ab[1][2*n+1];

            iir->ab[1][2*n]   = r * cos(angle);
            iir->ab[1][2*n+1] = r * sin(angle);
        }
    }
}

static void convert_pd2zp(AVFilterContext *ctx, int channels)
{
    AudioIIRContext *s = ctx->priv;
    int ch;

    for (ch = 0; ch < channels; ch++) {
        IIRChannel *iir = &s->iir[ch];
        int n;

        for (n = 0; n < iir->nb_ab[0]; n++) {
            double r = iir->ab[0][2*n];
            double angle = M_PI*iir->ab[0][2*n+1]/180.;

            iir->ab[0][2*n]   = r * cos(angle);
            iir->ab[0][2*n+1] = r * sin(angle);
        }

        for (n = 0; n < iir->nb_ab[1]; n++) {
            double r = iir->ab[1][2*n];
            double angle = M_PI*iir->ab[1][2*n+1]/180.;

            iir->ab[1][2*n]   = r * cos(angle);
            iir->ab[1][2*n+1] = r * sin(angle);
        }
    }
}

static int config_output(AVFilterLink *outlink)
{
    AVFilterContext *ctx = outlink->src;
    AudioIIRContext *s = ctx->priv;
    AVFilterLink *inlink = ctx->inputs[0];
    int ch, ret, i;

    s->channels = inlink->channels;
    s->iir = av_calloc(s->channels, sizeof(*s->iir));
    if (!s->iir)
        return AVERROR(ENOMEM);

    ret = read_gains(ctx, s->g_str, inlink->channels);
    if (ret < 0)
        return ret;

    ret = read_channels(ctx, inlink->channels, s->a_str, 0);
    if (ret < 0)
        return ret;

    ret = read_channels(ctx, inlink->channels, s->b_str, 1);
    if (ret < 0)
        return ret;

    if (s->format == 2) {
        convert_pr2zp(ctx, inlink->channels);
    } else if (s->format == 3) {
        convert_pd2zp(ctx, inlink->channels);
    }

    if (s->format == 0)
        av_log(ctx, AV_LOG_WARNING, "tf coefficients format is not recommended for too high number of zeros/poles.\n");

    if (s->format > 0 && s->process == 0) {
        av_log(ctx, AV_LOG_WARNING, "Direct processsing is not recommended for zp coefficients format.\n");

        ret = convert_zp2tf(ctx, inlink->channels);
        if (ret < 0)
            return ret;
    } else if (s->format == 0 && s->process == 1) {
        av_log(ctx, AV_LOG_ERROR, "Serial cascading is not implemented for transfer function.\n");
        return AVERROR_PATCHWELCOME;
    } else if (s->format > 0 && s->process == 1) {
        if (inlink->format == AV_SAMPLE_FMT_S16P)
            av_log(ctx, AV_LOG_WARNING, "Serial cascading is not recommended for i16 precision.\n");

        ret = decompose_zp2biquads(ctx, inlink->channels);
        if (ret < 0)
            return ret;
    }

    for (ch = 0; ch < inlink->channels; ch++) {
        IIRChannel *iir = &s->iir[ch];

        for (i = 1; i < iir->nb_ab[0]; i++) {
            iir->ab[0][i] /= iir->ab[0][0];
        }

        for (i = 0; i < iir->nb_ab[1]; i++) {
            iir->ab[1][i] *= iir->g / iir->ab[0][0];
        }
    }

    switch (inlink->format) {
    case AV_SAMPLE_FMT_DBLP: s->iir_channel = s->process == 1 ? iir_ch_serial_dblp : iir_ch_dblp; break;
    case AV_SAMPLE_FMT_FLTP: s->iir_channel = s->process == 1 ? iir_ch_serial_fltp : iir_ch_fltp; break;
    case AV_SAMPLE_FMT_S32P: s->iir_channel = s->process == 1 ? iir_ch_serial_s32p : iir_ch_s32p; break;
    case AV_SAMPLE_FMT_S16P: s->iir_channel = s->process == 1 ? iir_ch_serial_s16p : iir_ch_s16p; break;
    }

    return 0;
}

static int filter_frame(AVFilterLink *inlink, AVFrame *in)
{
    AVFilterContext *ctx = inlink->dst;
    AudioIIRContext *s = ctx->priv;
    AVFilterLink *outlink = ctx->outputs[0];
    ThreadData td;
    AVFrame *out;
    int ch;

    if (av_frame_is_writable(in)) {
        out = in;
    } else {
        out = ff_get_audio_buffer(outlink, in->nb_samples);
        if (!out) {
            av_frame_free(&in);
            return AVERROR(ENOMEM);
        }
        av_frame_copy_props(out, in);
    }

    td.in  = in;
    td.out = out;
    ctx->internal->execute(ctx, s->iir_channel, &td, NULL, outlink->channels);

    for (ch = 0; ch < outlink->channels; ch++) {
        if (s->iir[ch].clippings > 0)
            av_log(ctx, AV_LOG_WARNING, "Channel %d clipping %d times. Please reduce gain.\n",
                   ch, s->iir[ch].clippings);
        s->iir[ch].clippings = 0;
    }

    if (in != out)
        av_frame_free(&in);

    return ff_filter_frame(outlink, out);
}

static av_cold int init(AVFilterContext *ctx)
{
    AudioIIRContext *s = ctx->priv;

    if (!s->a_str || !s->b_str || !s->g_str) {
        av_log(ctx, AV_LOG_ERROR, "Valid coefficients are mandatory.\n");
        return AVERROR(EINVAL);
    }

    switch (s->precision) {
    case 0: s->sample_format = AV_SAMPLE_FMT_DBLP; break;
    case 1: s->sample_format = AV_SAMPLE_FMT_FLTP; break;
    case 2: s->sample_format = AV_SAMPLE_FMT_S32P; break;
    case 3: s->sample_format = AV_SAMPLE_FMT_S16P; break;
    default: return AVERROR_BUG;
    }

    return 0;
}

static av_cold void uninit(AVFilterContext *ctx)
{
    AudioIIRContext *s = ctx->priv;
    int ch;

    if (s->iir) {
        for (ch = 0; ch < s->channels; ch++) {
            IIRChannel *iir = &s->iir[ch];
            av_freep(&iir->ab[0]);
            av_freep(&iir->ab[1]);
            av_freep(&iir->cache[0]);
            av_freep(&iir->cache[1]);
            av_freep(&iir->biquads);
        }
    }
    av_freep(&s->iir);
}

static const AVFilterPad inputs[] = {
    {
        .name         = "default",
        .type         = AVMEDIA_TYPE_AUDIO,
        .filter_frame = filter_frame,
    },
    { NULL }
};

static const AVFilterPad outputs[] = {
    {
        .name         = "default",
        .type         = AVMEDIA_TYPE_AUDIO,
        .config_props = config_output,
    },
    { NULL }
};

#define OFFSET(x) offsetof(AudioIIRContext, x)
#define AF AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM

static const AVOption aiir_options[] = {
    { "z", "set B/numerator/zeros coefficients",   OFFSET(b_str),    AV_OPT_TYPE_STRING, {.str="1+0i 1-0i"}, 0, 0, AF },
    { "p", "set A/denominator/poles coefficients", OFFSET(a_str),    AV_OPT_TYPE_STRING, {.str="1+0i 1-0i"}, 0, 0, AF },
    { "k", "set channels gains",                   OFFSET(g_str),    AV_OPT_TYPE_STRING, {.str="1|1"}, 0, 0, AF },
    { "dry", "set dry gain",                       OFFSET(dry_gain), AV_OPT_TYPE_DOUBLE, {.dbl=1},     0, 1, AF },
    { "wet", "set wet gain",                       OFFSET(wet_gain), AV_OPT_TYPE_DOUBLE, {.dbl=1},     0, 1, AF },
    { "f", "set coefficients format",              OFFSET(format),   AV_OPT_TYPE_INT,    {.i64=1},     0, 3, AF, "format" },
    { "tf", "transfer function",                   0,                AV_OPT_TYPE_CONST,  {.i64=0},     0, 0, AF, "format" },
    { "zp", "Z-plane zeros/poles",                 0,                AV_OPT_TYPE_CONST,  {.i64=1},     0, 0, AF, "format" },
    { "pr", "Z-plane zeros/poles (polar radians)", 0,                AV_OPT_TYPE_CONST,  {.i64=2},     0, 0, AF, "format" },
    { "pd", "Z-plane zeros/poles (polar degrees)", 0,                AV_OPT_TYPE_CONST,  {.i64=3},     0, 0, AF, "format" },
    { "r", "set kind of processing",               OFFSET(process),  AV_OPT_TYPE_INT,    {.i64=1},     0, 1, AF, "process" },
    { "d", "direct",                               0,                AV_OPT_TYPE_CONST,  {.i64=0},     0, 0, AF, "process" },
    { "s", "serial cascading",                     0,                AV_OPT_TYPE_CONST,  {.i64=1},     0, 0, AF, "process" },
    { "e", "set precision",                        OFFSET(precision),AV_OPT_TYPE_INT,    {.i64=0},     0, 3, AF, "precision" },
    { "dbl", "double-precision floating-point",    0,                AV_OPT_TYPE_CONST,  {.i64=0},     0, 0, AF, "precision" },
    { "flt", "single-precision floating-point",    0,                AV_OPT_TYPE_CONST,  {.i64=1},     0, 0, AF, "precision" },
    { "i32", "32-bit integers",                    0,                AV_OPT_TYPE_CONST,  {.i64=2},     0, 0, AF, "precision" },
    { "i16", "16-bit integers",                    0,                AV_OPT_TYPE_CONST,  {.i64=3},     0, 0, AF, "precision" },
    { NULL },
};

AVFILTER_DEFINE_CLASS(aiir);

AVFilter ff_af_aiir = {
    .name          = "aiir",
    .description   = NULL_IF_CONFIG_SMALL("Apply Infinite Impulse Response filter with supplied coefficients."),
    .priv_size     = sizeof(AudioIIRContext),
    .priv_class    = &aiir_class,
    .init          = init,
    .uninit        = uninit,
    .query_formats = query_formats,
    .inputs        = inputs,
    .outputs       = outputs,
    .flags         = AVFILTER_FLAG_SLICE_THREADS,
};
