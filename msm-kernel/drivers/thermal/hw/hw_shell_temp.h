/*
 * Huawei shell temp header
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
#ifndef HW_SHELL_TEMP_H
#define HW_SHELL_TEMP_H
#include <linux/module.h>
#include <linux/err.h>
#include <linux/string.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/platform_device.h>
#include <linux/of.h>
#include <linux/device.h>
#include <asm/page.h>
#include <linux/power_supply.h>
#include <linux/thermal.h>
#include <linux/hw/hw_thermal.h>
#ifdef CONFIG_HW_THERMAL_PERIPHERAL
#include "hw_peripheral_tm.h"
#include <linux/power/hw/coul/hw_coul_drv.h> /* for hw_battery_temperature */
#endif

#define CREATE_TRACE_POINTS

#include <trace/events/shell_temp.h>
#include <securec.h>
#define MUTIPLY_FACTOR				100000
#define BATTERY_NAME				"battery"
#define INVALID_TEMP_OUT_OF_RANGE		1
#define DEFAULT_TSENS_MAX_TEMP			100000
#define DEFAULT_TSENS_MIN_TEMP			0
#define DEFAULT_TSENS_STEP_RANGE		4000
#define DEFAULT_NTC_MAX_TEMP			80000
#define DEFAULT_NTC_MIN_TEMP			(-20000)
#define DEFAULT_NTC_STEP_RANGE			2000
#define DEFAULT_SHELL_TEMP_STEP_RANGE		400
#define DEFAULT_SHELL_TEMP_STEP			200
#define DEFAULT_INTERVAL			5000
#define IS_TRANSFER				1
#define IS_FRAMEWORK				1
#define PSY_BATTERY_NAME			"battery"
#define PSY_USB_NAME				"usb"
#define CHAGING_STAT				"Charging"
#define DISCHAGING_STAT				"Discharging"
#define TEMPERATURE_DATA_RANGE			10
#define MIN_TEMPERATURE				(-40000)
#define MAX_TEMPERATURE				145000
#define DECIMAL					10

enum {
	THERMAL_INFO_CHG_ON = 0,
	THERMAL_INFO_BAT_STAT = 1,
	THERMAL_INFO_IBUS = 2,
	THERMAL_INFO_VBUS = 3,
	THERMAL_INFO_IBAT = 4,
	THERMAL_INFO_VBAT = 5,
	THERMAL_INFO_CAP = 6,
	THERMAL_INFO_GPU_DDR_CUR = 7,
	THERMAL_INFO_GPU_DDR_MAX = 8,
};

struct temperature_node_t {
	struct device *device;
	int ambient;
};

struct hw_thermal_class {
	struct class *thermal_class;
	struct temperature_node_t temperature_node;
};

struct hw_shell_t {
	int sensor_count;
	int sample_count;
	int tsensor_temp_step;
	int tsensor_max_temp;
	int tsensor_min_temp;
	int ntc_temp_step;
	int ntc_max_temp;
	int ntc_min_temp;
	int shell_temp_step_range;
	int shell_temp_step;
	u32 interval;
	int bias;
	int temp;
	int old_temp;
	int index;
	int valid_flag;
	int is_framework;
	int flag;
	int is_transfer;
#ifdef CONFIG_HW_SHELL_TEMP_DEBUG
	int channel;
	int debug_temp;
#endif
	struct thermal_zone_device *tz_dev;
};

#endif