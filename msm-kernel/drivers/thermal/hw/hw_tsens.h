/*
 * Huawei tsensor header
 *
 * Copyright (c) 2022-2022 Huawei Technologies Co., Ltd.
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
#ifndef HW_TSENS_H
#define HW_TSENS_H

#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/thermal.h>
#include <linux/interrupt.h>
#include <linux/delay.h>
#include <linux/kernel.h>
#include <linux/io.h>
#include <linux/slab.h>
#include <linux/err.h>
#include <linux/of.h>
#include <linux/of_irq.h>
#include <linux/hw/hw_rproc.h>
#include <asm/compiler.h>
#include <linux/compiler.h>
#include <securec.h>

#define TSENS_DRIVER_NAME		"hw-tsens"
#define READTEMP_SVC_REG_RD		0xc5009900UL
#define CAPACITY_OF_TSENSOR_ARRAY	10
#define MAX_SENSOR_NUM			40
#define TSENSOR_8BIT			8
#define TSENS_THRESHOLD_MIN_CODE	0x0
#define TSENS_TEMP_START_VALUE		(-40) /* -40 deg C */
#define TSENS_TEMP_END_VALUE		125

/* Trips: warm and cool */
enum tsens_trip_type {
	TSENS_TRIP_ORIGNUM = 0,
#ifdef CONFIG_HW_THERMAL_TRIP
	TSENS_TRIP_THROTTLING = TSENS_TRIP_ORIGNUM,
	TSENS_TRIP_SHUTDOWN,
	TSENS_TRIP_BELOW_VR_MIN,
	TSENS_TRIP_NUM,
#endif
};

enum sensor_type {
	TYPE_TSENSOR = 0,
	TYPE_PVTSENSOR,
};

struct tsens_tm_device_sensor {
	struct thermal_zone_device *tz_dev;
	enum thermal_device_mode mode;
	int reg_no;
	unsigned int sensor_num;
	int sensor_type;
#ifdef CONFIG_HW_THERMAL_TRIP
	s32 temp_throttling;
	s32 temp_shutdown;
	s32 temp_below_vr_min;
#endif
};

struct tsens_tm_device {
	struct platform_device *pdev;
	int tsens_num_sensor;
	u32 adc_start_value;
	u32 adc_end_value;
	u32 pvtsensor_adc_start_value;
	u32 pvtsensor_adc_end_value;
	struct tsens_tm_device_sensor sensor[0];
};

#endif
