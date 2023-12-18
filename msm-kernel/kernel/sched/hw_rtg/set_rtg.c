/*
 * set_rtg.c
 *
 * set rtg sched
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

#include "include/set_rtg.h"

#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/sched/types.h>
#include <../kernel/sched/sched.h>
#include "include/rtg_sched.h"
#include "include/iaware_rtg.h"
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
#include "include/rtg.h"
#endif
#ifdef CONFIG_HW_RTG_RT_THREAD_LIMIT
static atomic_t g_rtg_rt_thread_num = ATOMIC_INIT(0);
void inc_rtg_rt_thread_num(void)
{
	atomic_inc(&g_rtg_rt_thread_num);
}

void dec_rtg_rt_thread_num(void)
{
	atomic_dec_if_positive(&g_rtg_rt_thread_num);
}

int test_and_read_rtg_rt_thread_num(void)
{
	if (atomic_read(&g_rtg_rt_thread_num) >= RTG_MAX_RT_THREAD_NUM)
		atomic_set(&g_rtg_rt_thread_num, get_rtg_rt_thread_num());

	return atomic_read(&g_rtg_rt_thread_num);
}
int read_rtg_rt_thread_num(void)
{
	return atomic_read(&g_rtg_rt_thread_num);
}
#endif

bool is_rtg_rt_task(struct task_struct *task)
{
	bool ret = false;
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	struct walt_task_struct *wts = NULL;
#endif

	if (!task)
		return ret;

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	wts = (struct walt_task_struct *) task->android_vendor_data1;
#endif
	ret = ((task->prio < MAX_RT_PRIO) &&
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	       (wts->rtg_depth == STATIC_RTG_DEPTH));
#else
	       (task->rtg_depth == STATIC_RTG_DEPTH));
#endif

	return ret;
}

static unsigned int _get_rtg_rt_thread_num(struct related_thread_group *grp)
{
	unsigned int rtg_rt_thread_num = 0;
	struct task_struct *p = NULL;
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	struct walt_task_struct *wts= NULL;
#endif

	if (list_empty(&grp->tasks))
		goto out;

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	list_for_each_entry(wts, &grp->tasks, grp_list) {
		p = wts_to_ts(wts);
#else
	list_for_each_entry(p, &grp->tasks, grp_list) {
#endif
#ifdef CONFIG_HW_QOS_THREAD
		if (atomic_read(&p->trans_flags) != 0)
			continue;
#endif
		if (is_rtg_rt_task(p))
			++rtg_rt_thread_num;
	}

out:
	return rtg_rt_thread_num;
}

unsigned int get_rtg_rt_thread_num(void)
{
	struct related_thread_group *grp = NULL;
	unsigned int total_rtg_rt_thread_num = 0;
	unsigned long flag;
#if IS_ENABLED(CONFIG_HW_RTG_MULTI_FRAME)
	unsigned int i;
#endif

	grp = lookup_related_thread_group(DEFAULT_AUX_ID);
	if (grp != NULL) {
		raw_spin_lock_irqsave(&grp->lock, flag);
		total_rtg_rt_thread_num += _get_rtg_rt_thread_num(grp);
		raw_spin_unlock_irqrestore(&grp->lock, flag);
	}

#if IS_ENABLED(CONFIG_HW_RTG_MULTI_FRAME)
	for (i = MULTI_FRAME_ID; i < MULTI_FRAME_ID + MULTI_FRAME_NUM; i++) {
		grp = lookup_related_thread_group(i);
		if (grp == NULL)
			continue;

		raw_spin_lock_irqsave(&grp->lock, flag);
		total_rtg_rt_thread_num += _get_rtg_rt_thread_num(grp);
		raw_spin_unlock_irqrestore(&grp->lock, flag);
	}
#endif

	return total_rtg_rt_thread_num;
}

static int do_set_rtg_sched(struct task_struct *task, bool is_rtg, int grp_id, int prio,
			    bool is_trans)
{
	int err;
	int policy = SCHED_NORMAL;
	int grpid = DEFAULT_RTG_GRP_ID;
	bool is_rt_task = (prio != NOT_RT_PRIO);
	struct sched_param sp = {0};

	if (is_rtg) {
		if (is_rt_task) {
#ifdef CONFIG_HW_RTG_RT_THREAD_LIMIT
			/* do not count the number of trans threads */
			if (!is_trans &&
			    (test_and_read_rtg_rt_thread_num() >= RTG_MAX_RT_THREAD_NUM))
				/* rtg_rt_thread_num is inavailable, set policy to CFS */
				goto skip_setpolicy;
#endif
			policy = SCHED_FIFO | SCHED_RESET_ON_FORK;
			sp.sched_priority = MAX_USER_RT_PRIO - 1 - prio;
		}
#ifdef CONFIG_HW_RTG_RT_THREAD_LIMIT
skip_setpolicy:
#endif
		grpid = grp_id;
	}

	err = sched_setscheduler_nocheck(task, policy, &sp);
	if (err < 0) {
		pr_err("[AWARE_RTG]: %s task:%d setscheduler err:%d\n",
				__func__, task->pid, err);
		return err;
	}

	err = _sched_set_group_id(task, grpid); //lint !e732
	if (err < 0) {
		pr_err("[AWARE_RTG]: %s task:%d set_group_id err:%d\n",
				__func__, task->pid, err);
		if (is_rtg) {
			policy = SCHED_NORMAL;
			sp.sched_priority = 0;
			sched_setscheduler_nocheck(task, policy, &sp);
		}
	}
#ifdef CONFIG_HW_RTG_RT_THREAD_LIMIT
	if ((err == 0) && !is_trans) {
		if (is_rtg) {
			if (policy != SCHED_NORMAL)
				inc_rtg_rt_thread_num();
		} else {
			dec_rtg_rt_thread_num();
		}
	}
#endif
	return err;
}

int set_rtg_sched(struct task_struct *task, bool is_rtg, int grp_id, int prio, bool is_trans)
{
	int err = -1;
	bool is_rt_task = (prio != NOT_RT_PRIO);

	if (get_enable_type() == TRANS_ENABLE)
		return err;

	if (!task)
		return err;

	if (is_rt_task && is_rtg && ((prio < 0) ||
		(prio > MAX_USER_RT_PRIO - 1)))
		return err;

	/*
	 * if CONFIG_HW_FUTEX_PI is set, task->prio and task->sched_class
	 * may be modified by rtmutex. So we use task->policy instead.
	 */
	if (is_rtg && (!fair_policy(task->policy) || (task->flags & PF_EXITING)))
		return err;

	if (in_interrupt()) {
		pr_err("[AWARE_RTG]: %s is in interrupt\n", __func__);
		return err;
	}

	return do_set_rtg_sched(task, is_rtg, grp_id, prio, is_trans);
}

#if IS_ENABLED(CONFIG_SCHED_TASK_UTIL_CLAMP) && IS_ENABLED(CONFIG_HW_RTG_AUX)
static void set_aux_task_min_util(struct task_struct *task, int min_util)
{
	int ret;

	if (get_enable_type() == TRANS_ENABLE)
		return;

	if (!task)
		return;

	if (min_util < 0)
		min_util = 0;

	ret = set_task_min_util(task, min_util);
	if (ret < 0)
		pr_warn("[AWARE_RTG] %s fail to set minutil, errno = %d\n",
			__func__, ret);
}

static void reset_aux_task_min_util(struct task_struct *task)
{
	int ret;

	if (get_enable_type() == TRANS_ENABLE)
		return;

	if (!task)
		return;
	ret = set_task_min_util(task, 0);
	if (ret < 0)
		pr_warn("[AWARE_RTG] %s fail to reset minutil, errno = %d\n",
			__func__, ret);
}
#else
static void set_aux_task_min_util(struct task_struct *task, int min_util) {}
static void reset_aux_task_min_util(struct task_struct *task) {}
#endif

static bool is_param_valid(pid_t tid, bool is_rtg, int grp_id, int prio)
{
	if ((grp_id < DEFAULT_RTG_GRP_ID) ||
		(grp_id >= MAX_NUM_CGROUP_COLOC_ID))
		return false;

	if ((prio != NOT_RT_PRIO) && is_rtg &&
		(prio < 0 || prio > MAX_USER_RT_PRIO - 1))
		return false;

	if (tid <= 0)
		return false;

	return true;
}

int set_rtg_grp(pid_t tid, bool is_rtg, int grp_id, int prio, int task_util)
{
	struct task_struct *task = NULL;
	int err = -1;
	int depth;
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	struct walt_task_struct *wts = NULL;
#endif
	if (!is_param_valid(tid, is_rtg, grp_id, prio))
		return err;

	rcu_read_lock();
	task = find_task_by_vpid(tid);
	if (!task) {
		pr_err("[AWARE_RTG] %s tid:%d task is null\n", __func__, tid);
		rcu_read_unlock();
		return err;
	}
	get_task_struct(task);
	rcu_read_unlock();

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	wts = (struct walt_task_struct *) task->android_vendor_data1;
	depth = wts->rtg_depth;
#else
	depth = task->rtg_depth;
#endif
	if (is_rtg) {
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
		wts->rtg_depth = STATIC_RTG_DEPTH;
#else
		task->rtg_depth = STATIC_RTG_DEPTH;
#endif
		set_aux_task_min_util(task, task_util);
	} else {
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
		wts->rtg_depth = 0;
#else
		task->rtg_depth = 0;
#endif
		reset_aux_task_min_util(task);
	}

	if (get_enable_type() == TRANS_ENABLE) {
		put_task_struct(task);
		return err;
	}

	if (set_rtg_sched(task, is_rtg, grp_id, prio, false) < 0) {
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
		wts->rtg_depth = depth;
#else
		task->rtg_depth = depth;
#endif
		put_task_struct(task);
		return err;
	}

	put_task_struct(task);
	return 0;
}

void set_frame_rtg_thread(int grp_id, struct task_struct *task, bool is_rtg, int prio)
{
	int depth;
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	struct walt_task_struct *wts = NULL;
#endif

	if (!task)
		return;

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	wts = (struct walt_task_struct *) task->android_vendor_data1;
	depth = wts->rtg_depth;
#else
	depth = task->rtg_depth;
#endif

	if (is_rtg)
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
		wts->rtg_depth = STATIC_RTG_DEPTH;
#else
		task->rtg_depth = STATIC_RTG_DEPTH;
#endif
	else
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
		wts->rtg_depth = 0;
#else
		task->rtg_depth = 0;
#endif

	if (get_enable_type() == TRANS_ENABLE)
		return;

	if (set_rtg_sched(task, is_rtg, grp_id, prio, false) < 0) {
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
		wts->rtg_depth = depth;
#else
		task->rtg_depth = depth;
#endif
		return;
	}
}
