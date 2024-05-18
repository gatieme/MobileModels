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
 * Frame info declaration
 *
 */

#ifndef FRAME_INFO_EXTERN_H
#define FRAME_INFO_EXTERN_H

#include <linux/cpumask.h>
#include <linux/sched.h>
#include <linux/spinlock.h>
#include <linux/types.h>

#include "frame.h"
#include "include/rtg_sched.h"

#include <../kernel/sched/sched.h>
#if 0
#include <../kernel/sched/walt/walt.h>
#endif

#define FRAME_START (1 << 0)
#define FRAME_END (1 << 1)
#define FRAME_INVALID (1 << 2)
#define FRAME_USE_MARGIN_IMME (1 << 4)
#define FRAME_TIMESTAMP_SKIP_START (1 << 5)
#define FRAME_TIMESTAMP_SKIP_END (1 << 6)
#define FRAME_SETTIME (FRAME_START | FRAME_END | \
	FRAME_USE_MARGIN_IMME)
#define FRAME_SETTIME_PARAM (-1)

#ifdef CONFIG_USE_RTG_FRAME_SCHED
struct frame_info {
	/*
	 * use rtg load tracking in frame_info
	 * rtg->curr_window_load  -=> the workload of current frame
	 * rtg->prev_window_load  -=> the workload of last frame
	 * rtg->curr_window_exec  -=> the thread's runtime of current frame
	 * rtg->prev_window_exec  -=> the thread's runtime of last frame
	 * rtg->prev_window_time  -=> the actual time of the last frame
	 */
	struct walt_related_thread_group *rtg;

	unsigned int qos_frame; // frame rate
	u64 qos_frame_time;

	/*
	 * frame_vload : the emergency level of current frame.
	 * max_vload_time : the timeline frame_load increase to FRAME_MAX_VLOAD
	 * it's always equal to 2 * qos_frame_time / NSEC_PER_MSEC
	 *
	 * The closer to the deadline, the higher emergency of current
	 * frame, so the frame_vload is only related to frame time,
	 * and grown with time.
	 */
	u64 frame_vload;
	int vload_margin;
	int max_vload_time;

	unsigned long prev_fake_load_util;
	unsigned long prev_frame_load_util;
	unsigned long prev_frame_time;
	unsigned long prev_frame_exec;
	unsigned long prev_frame_load;

	u64 frame_util;

	unsigned long status;
	unsigned int frame_min_util;
	unsigned int frame_max_util;
	unsigned int prev_min_util;
	unsigned int prev_max_util;
	unsigned int frame_boost_min_util;

	bool margin_imme;
	bool timestamp_skipped;
};

static inline struct walt_related_thread_group *frame_rtg(void)
{
	return lookup_related_thread_group(DEFAULT_RT_FRAME_ID);
}

static inline struct walt_related_thread_group *frame_info_rtg(
	const struct frame_info *frame_info)
{
	return frame_info->rtg;
}

static inline struct group_time *frame_info_rtg_load(
	const struct frame_info *frame_info)
{
	return &frame_info_rtg(frame_info)->time;
}

void update_frame_info_tick_common(struct walt_related_thread_group *grp);
#endif // CONFIG_USE_RTG_FRAME_SCHED
#endif // FRAME_INFO_EXTERN_H
