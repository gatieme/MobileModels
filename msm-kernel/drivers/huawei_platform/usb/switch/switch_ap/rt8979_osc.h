/*
 * rt8979_osc.h
 *
 * rt8979_osc header file
 *
 * Copyright (c) 2021-2021 Huawei Technologies Co., Ltd.
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

#ifndef _RT8979_OSC_
#define _RT8979_OSC_

#include <linux/device.h>
#include "rt8979.h"

#define WRITE_OSC_PRETRIM_DELAY_MIN_DEFAULT              30
#define WRITE_OSC_PRETRIM_DELAY_MIN                      50
#define WRITE_OSC_PRETRIM_DELAY_MAX                      80

#define RT8979_OSC_BOUND_MIN                             1
#define RT8979_OSC_BOUND_MAX                             15
#define RT8979_OSC_TRIM_ADJUST_DEFAULT                   0

int rt8979_get_osc_trim_default(void);
void rt8979_set_osc_trim_adjust(int val);
int rt8979_adjust_osc(int8_t val);
int rt8979_init_osc_params(struct rt8979_device_info *di);

#endif /* _RT8979_OSC_ */
