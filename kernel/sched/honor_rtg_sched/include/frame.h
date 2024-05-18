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
 * Frame declaration
 */

#ifndef FRAME_EXTERN_H
#define FRAME_EXTERN_H

/* FPS value : [1, 120] */
#define DEFAULT_FRAME_RATE 60
#define MIN_FRAME_RATE 1
#define MAX_FRAME_RATE 120

/* MARGIN value : [-100, 100] */
#define DEFAULT_VLOAD_MARGIN 16
#define MIN_VLOAD_MARGIN (-100)
#define MAX_VLOAD_MARGIN 0xffff

#define FRAME_MAX_VLOAD SCHED_CAPACITY_SCALE
#define FRAME_MAX_LOAD SCHED_CAPACITY_SCALE
#define FRAME_UTIL_INVALID_FACTOR 4
#define FRAME_DEFAULT_MIN_UTIL 0
#define FRAME_DEFAULT_MAX_UTIL SCHED_CAPACITY_SCALE
#define FRAME_DEFAULT_MIN_PREV_UTIL 0
#define FRAME_DEFAULT_MAX_PREV_UTIL SCHED_CAPACITY_SCALE

#ifdef CONFIG_HONOR_RTG_FRAME_USE_NORMALIZED_UTIL
#define INVALID_PREFERRED_CLUSTER 10
#endif

bool is_frame_task(struct task_struct *task);
int set_frame_rate(int rate);
int set_frame_margin(int margin);
int set_frame_status(unsigned long status);
void set_frame_sched_state(bool enable);
int set_frame_timestamp(unsigned long timestamp);
int set_frame_min_util(int min_util, bool is_boost);
int set_frame_min_util_and_margin(int min_util, int margin);
int set_frame_max_util(int max_util);
void update_frame_thread(int pid, int tid, int hwuitask0_tid, int hwuitask1_tid);
int update_frame_isolation(void);
int set_frame_min_prev_util(int min_util);
int set_frame_max_prev_util(int max_util);

#endif // FRAME_EXTERN_H
