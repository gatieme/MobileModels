/*
 * rt_cap.h
 *
 * rt cap header file
 *
 * Copyright (c) 2020-2021 Huawei Technologies Co., Ltd.
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
#ifndef __HW_CAPACITY_AWARE_H__
#define __HW_CAPACITY_AWARE_H__

#ifdef CONFIG_HW_RT_CAS
extern unsigned int sysctl_sched_enable_rt_cas;
#endif
#ifdef CONFIG_HW_RT_ACTIVE_LB
extern unsigned int sysctl_sched_enable_rt_active_lb;
#endif

extern unsigned int sysctl_sched_rt_capacity_margin;

#endif
