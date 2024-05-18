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
 * rtg sched header
 *
 */

#ifndef HONOR_RTG_COMMON_H
#define HONOR_RTG_COMMON_H

#ifdef CONFIG_HONOR_RTG_CPU_TIME
struct group_cpu_time {
	u64 window_start;
	u64 curr_runnable_sum;
	u64 prev_runnable_sum;
};
#endif

#ifdef CONFIG_USE_RTG_FRAME_SCHED
struct group_time {
	unsigned long curr_window_load;
	unsigned long curr_window_exec;
	unsigned long prev_window_load;
	unsigned long prev_window_exec;
	unsigned long normalized_util;
};
#endif

enum RTG_GRP_ID {
	DEFAULT_RTG_GRP_ID,
	DEFAULT_CGROUP_COLOC_ID = 1,
	DEFAULT_AI_ID = 2,
	DEFAULT_AI_RENDER_THREAD_ID = 3,
	DEFAULT_AI_OTHER_THREAD_ID = 4,
	DEFAULT_RT_FRAME_ID = 8,
	DEFAULT_AUX_ID = 9,
	DEFAULT_GAME_ID = 10,
	MAX_NUM_CGROUP_COLOC_ID,
};

struct grp_load_mode {
	bool freq_enabled;
	bool util_enabled;
};

enum rtg_freq_update_flags {
	FRAME_FORCE_UPDATE = (1 << 0),
	FRAME_NORMAL_UPDATE = (1 << 1),
	AI_FORCE_UPDATE = (1 << 2),
};

#endif
