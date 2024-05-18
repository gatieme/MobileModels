/*
 * Copyright (c) Honor Device Co., Ltd. 2019-2020. All rights reserved.
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
 * frame freq timer header
 */

#ifndef FRAME_TIMER_H
#define FRAME_TIMER_H

#include <linux/cred.h>

void frame_timer_boost_init(void);
void frame_timer_boost_stop(void);
void frame_timer_boost_start(u32 duration, u32 min_util);

#endif

