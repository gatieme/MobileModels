/*
 * favor_small_hw.h
 *
 * Copyright (c) 2019-2021 Honor Technologies Co., Ltd.
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
#ifndef __SCHED_FAVOR_SMALL_CAP_H__
#define __SCHED_FAVOR_SMALL_CAP_H__

#include <linux/sched.h>

#ifdef CONFIG_HW_FAVOR_SMALL_CAP
int find_slow_cpu(struct task_struct *p);
#endif

#endif