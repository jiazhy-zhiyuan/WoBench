#include "config.h"
#include "hwdec.h"
#include "libmpv_gpu.h"
#include "video.h"
#include "video/out/libmpv.h"

static const struct libmpv_gpu_context_fns *context_backends[] = {
#if HAVE_GL
    &libmpv_gpu_context_gl,
#endif
    NULL
};

struct priv {
    struct libmpv_gpu_context *context;

    struct gl_video *renderer;
};

static int init(struct render_backend *ctx, mpv_render_param *params)
{
    ctx->priv = talloc_zero(NULL, struct priv);
    struct priv *p = ctx->priv;

    char *api = get_mpv_render_param(params, MPV_RENDER_PARAM_API_TYPE, NULL);
    if (!api)
        return MPV_ERROR_INVALID_PARAMETER;

    for (int n = 0; context_backends[n]; n++) {
        const struct libmpv_gpu_context_fns *backend = context_backends[n];
        if (strcmp(backend->api_name, api) == 0) {
            p->context = talloc_zero(NULL, struct libmpv_gpu_context);
            *p->context = (struct libmpv_gpu_context){
                .global = ctx->global,
                .log = ctx->log,
                .fns = backend,
            };
            break;
        }
    }

    if (!p->context)
        return MPV_ERROR_INVALID_PARAMETER;

    int err = p->context->fns->init(p->context, params);
    if (err < 0)
        return err;

    p->renderer = gl_video_init(p->context->ra, ctx->log, ctx->global);

    ctx->hwdec_devs = hwdec_devices_create();
    gl_video_load_hwdecs(p->renderer, ctx->hwdec_devs, true);
    ctx->driver_caps = VO_CAP_ROTATE90;
    return 0;
}

static bool check_format(struct render_backend *ctx, int imgfmt)
{
    struct priv *p = ctx->priv;

    return gl_video_check_format(p->renderer, imgfmt);
}

static int set_parameter(struct render_backend *ctx, mpv_render_param param)
{
    struct priv *p = ctx->priv;

    switch (param.type) {
    case MPV_RENDER_PARAM_ICC_PROFILE: {
        mpv_byte_array *data = param.data;
        gl_video_set_icc_profile(p->renderer, (bstr){data->data, data->size});
        return 0;
    }
    case MPV_RENDER_PARAM_AMBIENT_LIGHT: {
        int lux = *(int *)param.data;
        gl_video_set_ambient_lux(p->renderer, lux);
        return 0;
    }
    default:
        return MPV_ERROR_NOT_IMPLEMENTED;
    }
}

static void reconfig(struct render_backend *ctx, struct mp_image_params *params)
{
    struct priv *p = ctx->priv;

    gl_video_config(p->renderer, params);
}

static void reset(struct render_backend *ctx)
{
    struct priv *p = ctx->priv;

    gl_video_reset(p->renderer);
}

static void update_external(struct render_backend *ctx, struct vo *vo)
{
    struct priv *p = ctx->priv;

    gl_video_set_osd_source(p->renderer, vo ? vo->osd : NULL);
    if (vo)
        gl_video_configure_queue(p->renderer, vo);
}

static void resize(struct render_backend *ctx, struct mp_rect *src,
                   struct mp_rect *dst, struct mp_osd_res *osd)
{
    struct priv *p = ctx->priv;

    gl_video_resize(p->renderer, src, dst, osd);
}

static int get_target_size(struct render_backend *ctx, mpv_render_param *params,
                           int *out_w, int *out_h)
{
    struct priv *p = ctx->priv;

    // Mapping the surface is cheap, better than adding new backend entrypoints.
    struct ra_tex *tex;
    int err = p->context->fns->wrap_fbo(p->context, params, &tex);
    if (err < 0)
        return err;
    *out_w = tex->params.w;
    *out_h = tex->params.h;
    return 0;
}

static int render(struct render_backend *ctx, mpv_render_param *params,
                  struct vo_frame *frame)
{
    struct priv *p = ctx->priv;

    // Mapping the surface is cheap, better than adding new backend entrypoints.
    struct ra_tex *tex;
    int err = p->context->fns->wrap_fbo(p->context, params, &tex);
    if (err < 0)
        return err;

    int depth = *(int *)get_mpv_render_param(params, MPV_RENDER_PARAM_DEPTH,
                                             &(int){0});
    gl_video_set_fb_depth(p->renderer, depth);

    bool flip = *(int *)get_mpv_render_param(params, MPV_RENDER_PARAM_FLIP_Y,
                                             &(int){0});

    struct ra_fbo target = {.tex = tex, .flip = flip};
    gl_video_render_frame(p->renderer, frame, target, RENDER_FRAME_DEF);
    p->context->fns->done_frame(p->context, frame->display_synced);

    return 0;
}

static void destroy(struct render_backend *ctx)
{
    struct priv *p = ctx->priv;

    if (p->renderer)
        gl_video_uninit(p->renderer);

    hwdec_devices_destroy(ctx->hwdec_devs);

    if (p->context) {
        p->context->fns->destroy(p->context);
        talloc_free(p->context->priv);
        talloc_free(p->context);
    }
}

const struct render_backend_fns render_backend_gpu = {
    .init = init,
    .check_format = check_format,
    .set_parameter = set_parameter,
    .reconfig = reconfig,
    .reset = reset,
    .update_external = update_external,
    .resize = resize,
    .get_target_size = get_target_size,
    .render = render,
    .destroy = destroy,
};
