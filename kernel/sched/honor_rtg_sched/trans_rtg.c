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
 * trans rtg thread
 */

#include "include/trans_rtg.h"

#include <linux/sched.h>
#include <linux/slab.h>
#include <uapi/linux/sched/types.h>
#include <../kernel/sched/sched.h>
#include <trace/events/sched.h>
#ifdef CONFIG_HN_QOS_THREAD
#include <trace/hooks/sched.h>
#endif

#include "include/iaware_rtg.h"
#include "include/set_rtg.h"
#include "include/rtg_sched.h"
#include "include/rtg.h"

#ifdef CONFIG_VIP_SCHED_OPT
#include <chipset_common/hwcfs/hwcfs_common.h>
#endif

enum SCHED_CLASS {
	RT_SCHED,
	FAIR_SCHED,
	INVALID_SCHED,
};

enum OPRATION_TYPE {
	OPERATION_RTG_ENQUEUE,
	OPERATION_RTG_DEQUEUE,
};

static int g_trans_depth = DEFAULT_TRANS_DEPTH;
static int g_max_thread_num = DEFAULT_MAX_THREADS;
#ifdef CONFIG_HN_QOS_THREAD
static atomic_t g_rtg_thread_num = ATOMIC_INIT(0);
#endif


#ifdef CONFIG_HN_QOS_THREAD
unsigned int honor_get_group_id(struct task_struct *p)
{
	unsigned int ret = 0;
	trace_android_rvh_sched_get_group_id(p, &ret);
	return ret;
}
#endif

void set_trans_config(int depth, int max_threads)
{
	if ((depth != INVALID_VALUE) && (depth >= 0))
		g_trans_depth = depth;
	if ((max_threads != INVALID_VALUE) && (max_threads >= 0))
		g_max_thread_num = max_threads;
}

#ifdef CONFIG_HN_QOS_THREAD
static bool is_depth_valid(const struct task_struct *from, int qos)
{
	if (g_trans_depth != DEFAULT_TRANS_DEPTH && g_trans_depth <= 0)
		return false;

	if ((g_trans_depth > 0) && (from->rtg_depth != STATIC_RTG_DEPTH) &&
		(from->rtg_depth >= g_trans_depth))
		return false;

	// if from is not in rtg, invalid
	if (from->rtg_depth == 0 &&
		(from->prio != DEFAULT_RT_PRIO + 1 || qos != VALUE_QOS_CRITICAL))
		return false;

	return true;
}
#endif

#ifdef CONFIG_HN_QOS_THREAD
static void trans_vip_and_min_util(struct task_struct *task,
	struct task_struct *from)
{
#ifdef CONFIG_VIP_SCHED_OPT
	task->restore_params.vip_prio = task->vip_prio;
	if (from->vip_prio > task->vip_prio)
		set_thread_vip_prio(task, from->vip_prio);
#endif

#if defined(CONFIG_HONOR_RTG_FRAME_USE_MIN_UTIL) && !defined(CONFIG_HONOR_SCHED_VIP) && \
    defined(CONFIG_SCHED_TASK_UTIL_CLAMP)
	task->restore_params.min_util = task->util_req.min_util;
	if (from->util_req.min_util > task->util_req.min_util)
		set_task_min_util(task, from->util_req.min_util);
#endif
}
#endif

#ifdef CONFIG_HN_QOS_THREAD
void trans_rtg_sched_enqueue(struct task_struct *task,
	struct task_struct *from, unsigned int type, int qos)
{
	int ret;
	unsigned int grpid;
	int prio;
#ifdef CONFIG_HN_SET_ASYNC_BINDER_RT
	int policy = SCHED_NORMAL;
	struct sched_param sp = {0};
#endif

#ifdef CONFIG_HN_QOS_THREAD
	if (!task || !from || type != DYNAMIC_QOS_BINDER)
		return;
#endif

	if (!is_depth_valid(from, qos))
	{
#ifdef CONFIG_RTG_DEBUG_LOG
		pr_err("RTG-XXXXX - trans_rtg_sched_enqueue !is_depth_valid\n");
#endif
		return;
	}

	// if task is already rtg, return
	if (task->rtg_depth == STATIC_RTG_DEPTH || task->rtg_depth > 0)
	{
#ifdef CONFIG_RTG_DEBUG_LOG
		pr_err("RTG-XXXXX - trans_rtg_sched_enqueue STATIC_RTG_DEPTH or rtg_depth > 0 \n");
#endif
		return;
	}

	if (from->rtg_depth == STATIC_RTG_DEPTH)
		task->rtg_depth = 1;
	else
		task->rtg_depth = from->rtg_depth + 1;

	if (get_enable_type() == TRANS_ENABLE)
	{
#ifdef CONFIG_RTG_DEBUG_LOG
		pr_err("RTG-XXXXX - trans_rtg_sched_enqueue TRANS_ENABLE \n");
#endif
		return;
	}

	grpid = honor_get_group_id(from);
	if (grpid == DEFAULT_RT_FRAME_ID || grpid == DEFAULT_CGROUP_COLOC_ID ||
		(qos == VALUE_QOS_CRITICAL &&
		(from->prio == DEFAULT_RT_PRIO || from->prio == DEFAULT_RT_PRIO + 1))) {
		if (g_max_thread_num != DEFAULT_MAX_THREADS &&
			atomic_read(&g_rtg_thread_num) >= g_max_thread_num) {
			task->rtg_depth = 0;
			pr_err("RTG-XXXXX - trans_rtg_sched_enqueue >= g_max_thread_num\n");
			return;
		}
		prio = DEFAULT_RT_PRIO;
	} else if (grpid == DEFAULT_AUX_ID) {
		prio = (from->prio < MAX_RT_PRIO ? from->prio : NOT_RT_PRIO);
	} else {
		task->rtg_depth = 0;
		pr_err("RTG-XXXXX - trans_rtg_sched_enqueue >= unknow \n");
		return;
	}

	if (grpid ==  DEFAULT_RT_FRAME_ID ||
		(qos == VALUE_QOS_CRITICAL &&
		(from->prio == DEFAULT_RT_PRIO || from->prio == DEFAULT_RT_PRIO + 1))) {
		grpid =  DEFAULT_CGROUP_COLOC_ID;
	}

	get_task_struct(task);
#ifdef CONFIG_HN_SET_ASYNC_BINDER_RT
	// qos will transfer rtg for the task, restore the prio set by async binder rt before
	if ((prio >= DEFAULT_RT_PRIO && prio < MAX_RT_PRIO) && task->need_next_recovery) {
		task->need_next_recovery = false;
		sched_setscheduler_nocheck(task, policy, &sp);
	}
#endif
	ret = set_rtg_sched(task, true, grpid, prio);
	if (ret < 0) {
		task->rtg_depth = 0;
		put_task_struct(task);
		if (ret != SET_RTG_SCHED_ERR_CLASS_INVALID) {
			pr_err("RTG-XXXXX - trans_rtg_sched_enqueue >= failed set_rtg_sched() ret = %d\n", ret);
		}
		return;
	}

	trans_vip_and_min_util(task, from);
	if (grpid == DEFAULT_RT_FRAME_ID)
		atomic_inc(&g_rtg_thread_num);

	put_task_struct(task);

	trace_sched_rtg(task, from, type, OPERATION_RTG_ENQUEUE);
}
#endif

#ifdef CONFIG_HN_QOS_THREAD
void trans_rtg_sched_dequeue(struct task_struct *task, unsigned int type)
{
	int ret;
	unsigned int grpid;
	int depth;

#ifdef CONFIG_HN_QOS_THREAD
	if (!task || type != DYNAMIC_QOS_BINDER)
		return;
#endif

	// if task is not rtg or task is orig task, return
	if (task->rtg_depth == 0 || task->rtg_depth == STATIC_RTG_DEPTH)
		return;

	depth = task->rtg_depth;
	task->rtg_depth = 0;

	if (get_enable_type() == TRANS_ENABLE)
		return;

	get_task_struct(task);
	ret = set_rtg_sched(task, false, 0, DEFAULT_RT_PRIO);
	if (ret < 0) {
		task->rtg_depth = depth;
		put_task_struct(task);
		return;
	}

#ifdef CONFIG_VIP_SCHED_OPT
	set_thread_vip_prio(task, task->restore_params.vip_prio);
	task->restore_params.vip_prio = 0;
#endif
#if defined(CONFIG_HONOR_RTG_FRAME_USE_MIN_UTIL) && !defined(CONFIG_HONOR_SCHED_VIP) && \
    defined(CONFIG_SCHED_TASK_UTIL_CLAMP)
	set_task_min_util(task, task->restore_params.min_util);

	task->restore_params.min_util = 0;
#endif

	grpid = honor_get_group_id(task);
	if ((grpid == DEFAULT_RT_FRAME_ID) &&
		(atomic_read(&g_rtg_thread_num) > 0))
		atomic_dec(&g_rtg_thread_num);

	put_task_struct(task);

	trace_sched_rtg(task, NULL, type, OPERATION_RTG_DEQUEUE);
}
#endif
