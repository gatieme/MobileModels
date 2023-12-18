/*
 * trans_rtg.c
 *
 * trans rtg thread
 *
 * Copyright (c) 2019-2021 Huawei Technologies Co., Ltd.
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

#include "include/trans_rtg.h"

#include <linux/sched.h>
#include <linux/slab.h>
#include <uapi/linux/sched/types.h>
#include <../kernel/sched/sched.h>
#include <trace/events/sched.h>

#include "include/iaware_rtg.h"
#include "include/set_rtg.h"
#include "include/rtg_sched.h"
#include "include/frame.h"
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
#include <../kernel/sched/walt/trace.h>
#endif
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
static atomic_t g_rtg_thread_num = ATOMIC_INIT(0);

void set_trans_config(int depth, int max_threads)
{
	if ((depth != INVALID_VALUE) && (depth >= 0))
		g_trans_depth = depth;
	if ((max_threads != INVALID_VALUE) && (max_threads >= 0))
		g_max_thread_num = max_threads;
}

static bool is_depth_valid(const struct task_struct *from)
{
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	struct walt_task_struct *wts = (struct walt_task_struct *) from->android_vendor_data1;
#endif
	if (g_trans_depth != DEFAULT_TRANS_DEPTH && g_trans_depth <= 0)
		return false;

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	if ((g_trans_depth > 0) && (wts->rtg_depth != STATIC_RTG_DEPTH) &&
		(wts->rtg_depth >= g_trans_depth))
#else
	if ((g_trans_depth > 0) && (from->rtg_depth != STATIC_RTG_DEPTH) &&
		(from->rtg_depth >= g_trans_depth))
#endif
		return false;

	// if from is not in rtg, invalid
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	if (wts->rtg_depth == 0)
#else
	if (from->rtg_depth == 0)
#endif
		return false;

	return true;
}

static void trans_vip_and_min_util(struct task_struct *task,
	struct task_struct *from)
{
#ifdef CONFIG_VIP_SCHED_OPT
	task->restore_params.vip_prio = task->vip_prio;
	if (from->vip_prio > task->vip_prio)
		set_thread_vip_prio(task, from->vip_prio);
#endif

#if IS_ENABLED(CONFIG_HW_RTG_FRAME_USE_MIN_UTIL) && !IS_ENABLED(CONFIG_HUAWEI_SCHED_VIP) && \
	IS_ENABLED(CONFIG_SCHED_TASK_UTIL_CLAMP)
	task->restore_params.min_util = task->util_req.min_util;
	if (from->util_req.min_util > task->util_req.min_util)
		set_task_min_util(task, from->util_req.min_util);
#endif
}

void trans_rtg_sched_enqueue(struct task_struct *task,
	struct task_struct *from, unsigned int type)
{
	int ret;
	unsigned int grpid;
	int prio;
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	struct walt_task_struct *wts = NULL;
	struct walt_task_struct *wts_from = NULL;
#endif

#ifdef CONFIG_HW_QOS_THREAD
	if (!task || !from || type != DYNAMIC_QOS_BINDER)
		return;
#endif

	if (!is_depth_valid(from))
		return;

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	wts = (struct walt_task_struct *) task->android_vendor_data1;
	wts_from = (struct walt_task_struct *) from->android_vendor_data1;
#endif
	// if task is already rtg, return
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	if (wts->rtg_depth == STATIC_RTG_DEPTH || wts->rtg_depth > 0)
#else
	if (task->rtg_depth == STATIC_RTG_DEPTH || task->rtg_depth > 0)
#endif
		return;

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	if (wts_from->rtg_depth == STATIC_RTG_DEPTH)
		wts->rtg_depth = 1;
#else
	if (from->rtg_depth == STATIC_RTG_DEPTH)
		task->rtg_depth = 1;
#endif
	else
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
		wts->rtg_depth = wts_from->rtg_depth + 1;
#else
		task->rtg_depth = from->rtg_depth + 1;
#endif

	if (get_enable_type() == TRANS_ENABLE)
		return;

	grpid = sched_get_group_id(from);
	if (is_frame_rtg(grpid)) {
		if (g_max_thread_num != DEFAULT_MAX_THREADS &&
			atomic_read(&g_rtg_thread_num) >= g_max_thread_num) {
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
			wts->rtg_depth = 0;
#else
			task->rtg_depth = 0;
#endif
			return;
		}
		prio = get_frame_prio_by_id(grpid);
	} else if (grpid == DEFAULT_AUX_ID) {
		prio = (from->prio < MAX_RT_PRIO ? from->prio : NOT_RT_PRIO);
	} else {
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
		wts->rtg_depth = 0;
#else
		task->rtg_depth = 0;
#endif
		return;
	}

	get_task_struct(task);
	ret = set_rtg_sched(task, true, grpid, prio, true);
	if (ret < 0) {
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
		wts->rtg_depth = 0;
#else
		task->rtg_depth = 0;
#endif
		put_task_struct(task);
		return;
	}

	trans_vip_and_min_util(task, from);
	if (is_frame_rtg(grpid))
		atomic_inc(&g_rtg_thread_num);

	put_task_struct(task);

	trace_sched_rtg(task, from, type, OPERATION_RTG_ENQUEUE);
}

void trans_rtg_sched_dequeue(struct task_struct *task, unsigned int type)
{
	int ret;
	unsigned int grpid;
	int depth;
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	struct walt_task_struct *wts = NULL;
#endif

#ifdef CONFIG_HW_QOS_THREAD
	if (!task || type != DYNAMIC_QOS_BINDER)
		return;
#endif

	// if task is not rtg or task is orig task, return
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	wts = (struct walt_task_struct *) task->android_vendor_data1;
	if (wts->rtg_depth == 0 || wts->rtg_depth == STATIC_RTG_DEPTH)
#else
	if (task->rtg_depth == 0 || task->rtg_depth == STATIC_RTG_DEPTH)
#endif
		return;

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	depth = wts->rtg_depth;
	wts->rtg_depth = 0;
#else
	depth = task->rtg_depth;
	task->rtg_depth = 0;
#endif

	if (get_enable_type() == TRANS_ENABLE)
		return;

	get_task_struct(task);
	ret = set_rtg_sched(task, false, 0, DEFAULT_RT_PRIO, true);
	if (ret < 0) {
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
		wts->rtg_depth = depth;
#else
		task->rtg_depth = depth;
#endif
		put_task_struct(task);
		return;
	}

#ifdef CONFIG_VIP_SCHED_OPT
	set_thread_vip_prio(task, task->restore_params.vip_prio);
	task->restore_params.vip_prio = 0;
#endif
#if IS_ENABLED(CONFIG_HW_RTG_FRAME_USE_MIN_UTIL) && !IS_ENABLED(CONFIG_HUAWEI_SCHED_VIP) && \
	IS_ENABLED(CONFIG_SCHED_TASK_UTIL_CLAMP)
	set_task_min_util(task, task->restore_params.min_util);

	task->restore_params.min_util = 0;
#endif

	grpid = sched_get_group_id(task);
	if (is_frame_rtg(grpid) &&
		(atomic_read(&g_rtg_thread_num) > 0))
		atomic_dec(&g_rtg_thread_num);

	put_task_struct(task);

	trace_sched_rtg(task, NULL, type, OPERATION_RTG_DEQUEUE);
}
