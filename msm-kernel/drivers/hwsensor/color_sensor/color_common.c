/*
 * color_common.c
 *
 * code for color sensor
 *
 * Copyright (c) 2022 Huawei Technologies Co., Ltd.
 *
 * Description: code for color sensor init/exit
 * Author: hufan
 * Create: 2021-10-18
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/i2c.h>
#include <linux/device.h>
#include <huawei_platform/log/hw_log.h>
#include "color_sensor.h"

#ifdef HWLOG_TAG
#undef HWLOG_TAG
#endif
#define HWLOG_TAG color_sensor
HWLOG_REGIST();

extern struct i2c_driver ams_as7341_driver;
extern struct i2c_driver sy3132cs_driver;

static int __init rgb_sensor_init(void)
{
	int rc;

	hwlog_info("%s\n", __func__);

	color_sensor_init();
	rc = i2c_add_driver(&ams_as7341_driver);
	if (rc) {
		hwlog_info("%s ams_as7341_driver failed %d\n", __func__, rc);
		return rc;
	}
	rc = i2c_add_driver(&sy3132cs_driver);
	if (rc) {
		hwlog_info("%s sy3132cs_driver failed %d\n", __func__, rc);
		return rc;
	}
	hwlog_info("%s i2c driver failed", __func__);
	return rc;
}

static void __exit rgb_sensor_exit(void)
{
	hwlog_info("%s\n", __func__);
	color_sensor_exit();
	i2c_del_driver(&ams_as7341_driver);
	i2c_del_driver(&sy3132cs_driver);
}

module_init(rgb_sensor_init);
module_exit(rgb_sensor_exit);
