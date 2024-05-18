/*
 * Copyright (c) 2021, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __WALT_QC_H
#define __WALT_QC_H

//#include "walt/walt.h"

#ifdef CONFIG_SCHED_WALT

u64 walt_ktime_clock(void)
{
	return sched_ktime_clock();
}

#else

static inline u64 walt_ktime_clock(void)
{
	return ktime_get_ns();
}

#endif /* CONFIG_SCHED_WALT */

#endif
