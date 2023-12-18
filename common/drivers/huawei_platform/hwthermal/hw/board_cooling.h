/*
 * Huawei board cooling header
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
#ifndef BOARD_COOLING_H
#define BOARD_COOLING_H

#include <linux/version.h>
#include <linux/module.h>
#include <linux/thermal.h>
#include <linux/err.h>
#include <linux/cpu.h>
#include <linux/slab.h>
#include <trace/events/thermal.h>
#include <securec.h>

typedef u32 (*get_power_t)(void);

struct board_cooling_device {
	int id;
	struct thermal_cooling_device *cdev;
	unsigned int max_level;
	unsigned int current_level;
	u32 *power_table;
	struct list_head node;
	get_power_t get_power;
};

#endif
