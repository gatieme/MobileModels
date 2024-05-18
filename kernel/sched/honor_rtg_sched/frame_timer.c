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
 * frame freq timer
 */

#define pr_fmt(fmt) "[IPROVISION-FRAME_TIMER]: " fmt

#include "include/frame_timer.h"

#include <linux/version.h>
#include <linux/timer.h>
#include <linux/kthread.h>
#include <trace/events/sched.h>
#include <linux/wait_bit.h>

#include "include/aux.h"
#include "include/frame.h"
#include "include/proc_state.h"

#include <../kernel/sched/sched.h>


struct timer_list g_frame_timer_boost;
atomic_t g_timer_boost_on = ATOMIC_INIT(0);

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 15, 0)
static void frame_timer_boost_func(unsigned long data)
#else
static void frame_timer_boost_func(struct timer_list *t)
#endif
{
#ifdef CONFIG_USE_RTG_FRAME_SCHED
	set_frame_min_util(0, true);
#endif /* CONFIG_USE_RTG_FRAME_SCHED */
#ifdef CONFIG_AUX_RTG_BOOST_UTIL 
	set_aux_boost_util(0);
#endif
	set_boost_thread_min_util(0);
	if (!is_frame_freq_enable())
		set_frame_sched_state(false);

	trace_rtg_frame_sched("frame_timer_boost", 0);

	pr_debug("frame timer boost HANDLER\n");
}

void frame_timer_boost_init(void)
{
	if (atomic_read(&g_timer_boost_on) == 1)
		return;

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 15, 0)
	setup_timer(&g_frame_timer_boost, frame_timer_boost_func, 0);
#else
	timer_setup(&g_frame_timer_boost, frame_timer_boost_func, 0);
#endif

	atomic_set(&g_timer_boost_on, 1);

	pr_debug("frame timer boost INIT\n");
}

void frame_timer_boost_stop(void)
{
	if (atomic_read(&g_timer_boost_on) == 0)
		return;

	atomic_set(&g_timer_boost_on, 0);
	del_timer_sync(&g_frame_timer_boost);
	pr_debug("frame timer boost STOP\n");
}

void frame_timer_boost_start(u32 duration, u32 min_util)
{
	unsigned long dur = msecs_to_jiffies(duration);

	if (atomic_read(&g_timer_boost_on) == 0)
		return;

	if (timer_pending(&g_frame_timer_boost) &&
		time_after(g_frame_timer_boost.expires, jiffies + dur))
		return;

#ifdef CONFIG_USE_RTG_FRAME_SCHED
	set_frame_min_util(min_util, true);
#endif // CONFIG_USE_RTG_FRAME_SCHED
#ifdef CONFIG_AUX_RTG_BOOST_UTIL 
	set_aux_boost_util(min_util);
#endif
	set_boost_thread_min_util(min_util);
	mod_timer(&g_frame_timer_boost, jiffies + dur);
	trace_rtg_frame_sched("frame_timer_boost", dur);
	pr_debug("frame timer boost START, duration = %ums, min_util = %u\n", duration, min_util);
}
