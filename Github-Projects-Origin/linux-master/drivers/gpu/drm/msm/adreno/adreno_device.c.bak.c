#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
/*
 * Copyright (C) 2013-2014 Red Hat
 * Author: Rob Clark <robdclark@gmail.com>
 *
 * Copyright (c) 2014,2017 The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "adreno_gpu.h"

#define ANY_ID 0xff

bool hang_debug = false;
MODULE_PARM_DESC(hang_debug, "Dump registers when hang is detected (can be slow!)");
module_param_named(hang_debug, hang_debug, bool, 0600);

static const struct adreno_info gpulist[] = {
	{
		.rev   = ADRENO_REV(3, 0, 5, ANY_ID),
		.revn  = 305,
		.name  = "A305",
		.pm4fw = "a300_pm4.fw",
		.pfpfw = "a300_pfp.fw",
		.gmem  = SZ_256K,
		.init  = a3xx_gpu_init,
	}, {
		.rev   = ADRENO_REV(3, 0, 6, 0),
		.revn  = 307,        /* because a305c is revn==306 */
		.name  = "A306",
		.pm4fw = "a300_pm4.fw",
		.pfpfw = "a300_pfp.fw",
		.gmem  = SZ_128K,
		.init  = a3xx_gpu_init,
	}, {
		.rev   = ADRENO_REV(3, 2, ANY_ID, ANY_ID),
		.revn  = 320,
		.name  = "A320",
		.pm4fw = "a300_pm4.fw",
		.pfpfw = "a300_pfp.fw",
		.gmem  = SZ_512K,
		.init  = a3xx_gpu_init,
	}, {
		.rev   = ADRENO_REV(3, 3, 0, ANY_ID),
		.revn  = 330,
		.name  = "A330",
		.pm4fw = "a330_pm4.fw",
		.pfpfw = "a330_pfp.fw",
		.gmem  = SZ_1M,
		.init  = a3xx_gpu_init,
	}, {
		.rev   = ADRENO_REV(4, 2, 0, ANY_ID),
		.revn  = 420,
		.name  = "A420",
		.pm4fw = "a420_pm4.fw",
		.pfpfw = "a420_pfp.fw",
		.gmem  = (SZ_1M + SZ_512K),
		.init  = a4xx_gpu_init,
	}, {
		.rev   = ADRENO_REV(4, 3, 0, ANY_ID),
		.revn  = 430,
		.name  = "A430",
		.pm4fw = "a420_pm4.fw",
		.pfpfw = "a420_pfp.fw",
		.gmem  = (SZ_1M + SZ_512K),
		.init  = a4xx_gpu_init,
	}, {
		.rev = ADRENO_REV(5, 3, 0, 2),
		.revn = 530,
		.name = "A530",
		.pm4fw = "a530_pm4.fw",
		.pfpfw = "a530_pfp.fw",
		.gmem = SZ_1M,
		.quirks = ADRENO_QUIRK_TWO_PASS_USE_WFI |
			ADRENO_QUIRK_FAULT_DETECT_MASK,
		.init = a5xx_gpu_init,
		.gpmufw = "a530v3_gpmu.fw2",
		.zapfw = "a530_zap.mdt",
	},
};

MODULE_FIRMWARE("qcom/a300_pm4.fw");
MODULE_FIRMWARE("qcom/a300_pfp.fw");
MODULE_FIRMWARE("qcom/a330_pm4.fw");
MODULE_FIRMWARE("qcom/a330_pfp.fw");
MODULE_FIRMWARE("qcom/a420_pm4.fw");
MODULE_FIRMWARE("qcom/a420_pfp.fw");
MODULE_FIRMWARE("qcom/a530_pm4.fw");
MODULE_FIRMWARE("qcom/a530_pfp.fw");
MODULE_FIRMWARE("qcom/a530v3_gpmu.fw2");
MODULE_FIRMWARE("qcom/a530_zap.mdt");
MODULE_FIRMWARE("qcom/a530_zap.b00");
MODULE_FIRMWARE("qcom/a530_zap.b01");
MODULE_FIRMWARE("qcom/a530_zap.b02");

static inline bool _rev_match(uint8_t entry, uint8_t id)
{
	return (entry == ANY_ID) || (entry == id);
}

const struct adreno_info *adreno_info(struct adreno_rev rev)
{
	int i;

	/* identify gpu: */
	for (i = 0; i < ARRAY_SIZE(gpulist); i++) {
		const struct adreno_info *info = &gpulist[i];
		if (_rev_match(info->rev.core, rev.core) &&
				_rev_match(info->rev.major, rev.major) &&
				_rev_match(info->rev.minor, rev.minor) &&
				_rev_match(info->rev.patchid, rev.patchid))
			return info;
	}

	return NULL;
}

struct msm_gpu *adreno_load_gpu(struct drm_device *dev)
{
	struct msm_drm_private *priv = dev->dev_private;
	struct platform_device *pdev = priv->gpu_pdev;
	struct msm_gpu *gpu = NULL;
	int ret;

	if (pdev)
		gpu = platform_get_drvdata(pdev);

	if (!gpu) {
		dev_err_once(dev->dev, "no GPU device was found\n");
		return NULL;
	}

	pm_runtime_get_sync(&pdev->dev);
	mutex_lock(&dev->struct_mutex);
	ret = msm_gpu_hw_init(gpu);
	mutex_unlock(&dev->struct_mutex);
	pm_runtime_put_sync(&pdev->dev);
	if (ret) {
		dev_err(dev->dev, "gpu hw init failed: %d\n", ret);
		return NULL;
	}

	return gpu;
}

static void set_gpu_pdev(struct drm_device *dev,
		struct platform_device *pdev)
{
	struct msm_drm_private *priv = dev->dev_private;
	priv->gpu_pdev = pdev;
}

static int find_chipid(struct device *dev, struct adreno_rev *rev)
{
	struct device_node *node = dev->of_node;
	const char *compat;
	int ret;
	u32 chipid;

	/* first search the compat strings for qcom,adreno-XYZ.W: */
	ret = of_property_read_string_index(node, "compatible", 0, &compat);
	if (ret == 0) {
		unsigned int r, patch;

		if (sscanf(compat, "qcom,adreno-%u.%u", &r, &patch) == 2) {
			rev->core = r / 100;
			r %= 100;
			rev->major = r / 10;
			r %= 10;
			rev->minor = r;
			rev->patchid = patch;

			return 0;
		}
	}

	/* and if that fails, fall back to legacy "qcom,chipid" property: */
	ret = of_property_read_u32(node, "qcom,chipid", &chipid);
	if (ret) {
		dev_err(dev, "could not parse qcom,chipid: %d\n", ret);
		return ret;
	}

	rev->core = (chipid >> 24) & 0xff;
	rev->major = (chipid >> 16) & 0xff;
	rev->minor = (chipid >> 8) & 0xff;
	rev->patchid = (chipid & 0xff);

	dev_warn(dev, "Using legacy qcom,chipid binding!\n");
	dev_warn(dev, "Use compatible qcom,adreno-%u%u%u.%u instead.\n",
		rev->core, rev->major, rev->minor, rev->patchid);

	return 0;
}

static int adreno_bind(struct device *dev, struct device *master, void *data)
{
	static struct adreno_platform_config config = {};
	const struct adreno_info *info;
	struct drm_device *drm = dev_get_drvdata(master);
	struct msm_gpu *gpu;
	int ret;

	ret = find_chipid(dev, &config.rev);
	if (ret)
		return ret;

	dev->platform_data = &config;
	set_gpu_pdev(drm, to_platform_device(dev));

	info = adreno_info(config.rev);

	if (!info) {
		dev_warn(drm->dev, "Unknown GPU revision: %u.%u.%u.%u\n",
			config.rev.core, config.rev.major,
			config.rev.minor, config.rev.patchid);
		return -ENXIO;
	}

	DBG("Found GPU: %u.%u.%u.%u", config.rev.core, config.rev.major,
		config.rev.minor, config.rev.patchid);

	gpu = info->init(drm);
	if (IS_ERR(gpu)) {
		dev_warn(drm->dev, "failed to load adreno gpu\n");
		return PTR_ERR(gpu);
	}

	dev_set_drvdata(dev, gpu);

	return 0;
}

static void adreno_unbind(struct device *dev, struct device *master,
		void *data)
{
	struct msm_gpu *gpu = dev_get_drvdata(dev);

	gpu->funcs->pm_suspend(gpu);
	gpu->funcs->destroy(gpu);

	set_gpu_pdev(dev_get_drvdata(master), NULL);
}

static const struct component_ops a3xx_ops = {
		.bind   = adreno_bind,
		.unbind = adreno_unbind,
};

static int adreno_probe(struct platform_device *pdev)
{
	return component_add(&pdev->dev, &a3xx_ops);
}

static int adreno_remove(struct platform_device *pdev)
{
	component_del(&pdev->dev, &a3xx_ops);
	return 0;
}

static const struct of_device_id dt_match[] = {
	{ .compatible = "qcom,adreno" },
	{ .compatible = "qcom,adreno-3xx" },
	/* for backwards compat w/ downstream kgsl DT files: */
	{ .compatible = "qcom,kgsl-3d0" },
	{}
};

#ifdef CONFIG_PM
static int adreno_resume(struct device *dev)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct msm_gpu *gpu = platform_get_drvdata(pdev);

	return gpu->funcs->pm_resume(gpu);
}

static int adreno_suspend(struct device *dev)
{
	struct platform_device *pdev = to_platform_device(dev);
	struct msm_gpu *gpu = platform_get_drvdata(pdev);

	return gpu->funcs->pm_suspend(gpu);
}
#endif

static const struct dev_pm_ops adreno_pm_ops = {
	SET_RUNTIME_PM_OPS(adreno_suspend, adreno_resume, NULL)
};

static struct platform_driver adreno_driver = {
	.probe = adreno_probe,
	.remove = adreno_remove,
	.driver = {
		.name = "adreno",
		.of_match_table = dt_match,
		.pm = &adreno_pm_ops,
	},
};

void __init adreno_register(void)
{
	platform_driver_register(&adreno_driver);
}

void __exit adreno_unregister(void)
{
	platform_driver_unregister(&adreno_driver);
}
