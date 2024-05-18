/*
 * power_time.h
 *
 * time operation for power module
 *
 * Copyright (c) 2020-2020 Honor Device Co., Ltd.
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

#ifndef _POWER_TIME_H_
#define _POWER_TIME_H_

#include <linux/time.h>
#include <linux/version.h>

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 4, 0)
#define TIME_T_MAX	(long)((1UL << ((sizeof(long) << 3) - 1)) - 1)
struct timespec64 current_kernel_time(void);
struct timespec64 current_kernel_time64(void);
#endif /* LINUX_VERSION_CODE */

struct timespec64 charger_timespec64_add_safe(const struct timespec64 lhs, const struct timespec64 rhs);

#endif /* _POWER_TIME_H_ */

