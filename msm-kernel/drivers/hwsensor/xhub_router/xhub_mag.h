/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2019. All rights reserved.
 * Team:    Huawei DIVS
 * Date:    2020.07.20
 * Description: xhub logbuff module
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
#include <linux/of.h>
#include <linux/pm.h>
#include <linux/platform_device.h>
#include <linux/completion.h>

#define MAG_IOCTL_PKG_HEADER 16
#define READ_CURRENT_INTERVAL 500
#define MAG_CURRENT_FAC_RAIO 1000000
#define MAG_ROUND_FAC 500000
#define CURRENT_MAX_VALUE 10000
#define CURRENT_MIN_VALUE 2000
#define COEF_VALUE 1

typedef struct mag_buf_to_hal {
	uint8_t sensor_type;
	uint8_t cmd;
	uint8_t subcmd;
	uint8_t reserved;
	int current_offset_x;
	int current_offset_y;
	int current_offset_z;
	int current_value;
} mag_buf_to_hal_t;
