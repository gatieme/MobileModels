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
 * aux grp info header
 */

#include "include/aux_info.h"
#include "include/frame.h"
#include "include/aux.h"
#include "include/proc_state.h"
#include "include/set_rtg.h"
#include "include/rtg_sched.h"
#include "include/rtg.h"
#include <../kernel/sched/sched.h>

#include <trace/events/sched.h>
#include <trace/hooks/sched.h>

#define RTG_FRAME_PRIO 1
#define MAX_RT_AUX_THREADS 5

atomic_t g_aux_thread_num = ATOMIC_INIT(0);
atomic_t g_rt_aux_thread_num = ATOMIC_INIT(0);

struct aux_task_list {
	struct list_head list;
	struct task_struct *task;
};

#ifdef CONFIG_AUX_RTG_BOOST_UTIL
static inline struct walt_related_thread_group *aux_rtg(void)
{
	return lookup_related_thread_group(DEFAULT_AUX_ID);
}

static inline struct aux_info *__rtg_aux_info(struct walt_related_thread_group *grp)
{
	return (struct aux_info *) grp->aux_info_data;
}

static struct aux_info *rtg_aux_info(void)
{
	struct aux_info *aux_info = NULL;
	struct walt_related_thread_group *grp = aux_rtg();

	if (!grp)
		return NULL;

	aux_info = __rtg_aux_info(grp);
	return aux_info;
}
#endif /* CONFIG_AUX_RTG_BOOST_UTIL */

#if 0
static bool is_rt_task(struct task_struct *task)
{
	bool ret = false;

	if (!task)
		return ret;

	ret = (task->prio < MAX_RT_PRIO) &&
		(task->android_oem_data1[0] == STATIC_RTG_DEPTH);
	return ret;
}

static int get_rt_thread_num(void)
{
	int ret = 0;
	struct task_struct *p = NULL;
	struct walt_related_thread_group *grp = NULL;
	unsigned long flags;

	grp = aux_rtg();
	if (!grp)
		return ret;

	raw_spin_lock_irqsave(&grp->lock, flags);
	if (list_empty(&grp->tasks)) {
		raw_spin_unlock_irqrestore(&grp->lock, flags);
		return ret;
	}

	list_for_each_entry(p, &grp->tasks, wts.grp_list) {
		if (is_rt_task(p))
			++ret;
	}
	raw_spin_unlock_irqrestore(&grp->lock, flags);
	return ret;
}
#endif
static int get_aux_rtg_thread_num(void)
{
	int ret = -1;
	trace_android_rvh_sched_get_rtg_group_thread_num(DEFAULT_AUX_ID, &ret);
	return ret;
}

int sched_rtg_aux(int tid, int enable, const struct aux_info *info)
{
	int err;
	int thread_num = -1;

	if (!info)
		return -INVALID_ARG;

	// prio: [0, 1], 0 represents 97, 1 represents RT prio 98
	if ((info->prio < 0) ||
		(info->prio + 2 > MAX_RT_PRIO - DEFAULT_RT_PRIO))
		return -INVALID_ARG;

	if (enable < 0 || enable > 1)
		return -INVALID_ARG;

	if ((enable == 1) &&
		(atomic_read(&g_rt_aux_thread_num) == MAX_RT_AUX_THREADS)) {	
		err = set_rtg_grp(tid, enable == 1,
				DEFAULT_AUX_ID, NOT_RT_PRIO, info->min_util);
	}
	else {
		err = set_rtg_grp(tid, enable == 1, DEFAULT_AUX_ID,
				DEFAULT_RT_PRIO + info->prio, info->min_util);
	}

	if (err != 0)
		return -ERR_SET_AUX_RTG;

	if ((enable == 1) &&
		(atomic_read(&g_rt_aux_thread_num) < MAX_RT_AUX_THREADS)) {
		atomic_inc(&g_rt_aux_thread_num);
	}
	else {
		thread_num = get_aux_rtg_thread_num();
		if (thread_num >= 0) {
			atomic_set(&g_rt_aux_thread_num, thread_num);
		}
	}

	trace_rtg_frame_sched("AUX_SCHED_ENABLE",
		atomic_read(&g_rt_aux_thread_num));

	return SUCC;
}

#ifdef CONFIG_AUX_RTG_BOOST_UTIL
int set_aux_boost_util(int util)
{
	struct aux_info *aux_info = rtg_aux_info();

	if (!aux_info)
		return -INVALID_ARG;

	if ((util < 0) || (util > DEFAULT_MAX_UTIL))
		return -INVALID_ARG;

	aux_info->boost_util = util;
	return SUCC;
}

static struct aux_info g_aux_info;
static int __init init_aux_info(void)
{
	struct walt_related_thread_group *grp = NULL;
	struct aux_info *aux_info = NULL;
	unsigned long flags;

	aux_info = &g_aux_info;
	memset(aux_info, 0, sizeof(*aux_info));

	grp = aux_rtg();

	raw_spin_lock_irqsave(&grp->lock, flags);
	grp->aux_info_data= aux_info;
#ifdef CONFIG_USE_RTG_FRAME_SCHED
	grp->rtg_class = NULL;
#endif
	raw_spin_unlock_irqrestore(&grp->lock, flags);

	return 0;
}
late_initcall(init_aux_info);
#endif /* CONFIG_AUX_RTG_BOOST_UTIL */
