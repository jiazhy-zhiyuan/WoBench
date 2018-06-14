#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
/*
 * STMicroelectronics gyroscopes driver
 *
 * Copyright 2012-2013 STMicroelectronics Inc.
 *
 * Denis Ciocca <denis.ciocca@st.com>
 *
 * Licensed under the GPL-2.
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/spi/spi.h>
#include <linux/iio/iio.h>

#include <linux/iio/common/st_sensors.h>
#include <linux/iio/common/st_sensors_spi.h>
#include "st_gyro.h"

#ifdef CONFIG_OF
/*
 * For new single-chip sensors use <device_name> as compatible string.
 * For old single-chip devices keep <device_name>-gyro to maintain
 * compatibility
 */
static const struct of_device_id st_gyro_of_match[] = {
	{
		.compatible = "st,l3g4200d-gyro",
		.data = L3G4200D_GYRO_DEV_NAME,
	},
	{
		.compatible = "st,lsm330d-gyro",
		.data = LSM330D_GYRO_DEV_NAME,
	},
	{
		.compatible = "st,lsm330dl-gyro",
		.data = LSM330DL_GYRO_DEV_NAME,
	},
	{
		.compatible = "st,lsm330dlc-gyro",
		.data = LSM330DLC_GYRO_DEV_NAME,
	},
	{
		.compatible = "st,l3gd20-gyro",
		.data = L3GD20_GYRO_DEV_NAME,
	},
	{
		.compatible = "st,l3gd20h-gyro",
		.data = L3GD20H_GYRO_DEV_NAME,
	},
	{
		.compatible = "st,l3g4is-gyro",
		.data = L3G4IS_GYRO_DEV_NAME,
	},
	{
		.compatible = "st,lsm330-gyro",
		.data = LSM330_GYRO_DEV_NAME,
	},
	{
		.compatible = "st,lsm9ds0-gyro",
		.data = LSM9DS0_GYRO_DEV_NAME,
	},
	{},
};
MODULE_DEVICE_TABLE(of, st_gyro_of_match);
#else
#define st_gyro_of_match	NULL
#endif

static int st_gyro_spi_probe(struct spi_device *spi)
{
	struct iio_dev *indio_dev;
	struct st_sensor_data *gdata;
	int err;

	indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*gdata));
	if (!indio_dev)
		return -ENOMEM;

	gdata = iio_priv(indio_dev);

	st_sensors_of_name_probe(&spi->dev, st_gyro_of_match,
				 spi->modalias, sizeof(spi->modalias));
	st_sensors_spi_configure(indio_dev, spi, gdata);

	err = st_gyro_common_probe(indio_dev);
	if (err < 0)
		return err;

	return 0;
}

static int st_gyro_spi_remove(struct spi_device *spi)
{
	st_gyro_common_remove(spi_get_drvdata(spi));

	return 0;
}

static const struct spi_device_id st_gyro_id_table[] = {
	{ L3G4200D_GYRO_DEV_NAME },
	{ LSM330D_GYRO_DEV_NAME },
	{ LSM330DL_GYRO_DEV_NAME },
	{ LSM330DLC_GYRO_DEV_NAME },
	{ L3GD20_GYRO_DEV_NAME },
	{ L3GD20H_GYRO_DEV_NAME },
	{ L3G4IS_GYRO_DEV_NAME },
	{ LSM330_GYRO_DEV_NAME },
	{ LSM9DS0_GYRO_DEV_NAME },
	{},
};
MODULE_DEVICE_TABLE(spi, st_gyro_id_table);

static struct spi_driver st_gyro_driver = {
	.driver = {
		.name = "st-gyro-spi",
		.of_match_table = of_match_ptr(st_gyro_of_match),
	},
	.probe = st_gyro_spi_probe,
	.remove = st_gyro_spi_remove,
	.id_table = st_gyro_id_table,
};
module_spi_driver(st_gyro_driver);

MODULE_AUTHOR("Denis Ciocca <denis.ciocca@st.com>");
MODULE_DESCRIPTION("STMicroelectronics gyroscopes spi driver");
MODULE_LICENSE("GPL v2");
