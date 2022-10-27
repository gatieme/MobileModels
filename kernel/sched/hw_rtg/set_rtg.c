/*
 * set_rtg.c
 *
 * set rtg sched
 *
 * Copyright (c) 2019-2020 Huawei Technologies Co., Ltd.
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
#include <../kernel/sched/walt/walt.h>
#include "include/rtg_sched.h"
#include "include/iaware_rtg.h"
#include <trace/events/sched.h>

extern int sched_set_group_id(struct task_struct *p, unsigned int group_id);

int set_rtg_sched(struct task_struct *task, bool is_rtg, int grp_id, int prio)
{
	int err = -1;
	int policy = SCHED_NORMAL;
	int grpid = DEFAULT_RTG_GRP_ID;
	bool is_rt_task = (prio != NOT_RT_PRIO);
	struct sched_param sp = {0};
	static int g_pid_launcher = 0;
	int is_launcher = 0;

	if (get_enable_type() == TRANS_ENABLE)
		return err;

	if (!task)
		return err;

	if (is_rt_task && is_rtg && ((prio < 0) ||
		(prio > MAX_USER_RT_PRIO - 1)))
		return err;

	if (is_rtg && (task->sched_class != &fair_sched_class))
		return err;

	if (in_interrupt()) {
		pr_err("[AWARE_RTG]: %s is in interrupt\n", __func__);
		return err;
	}

	if (is_rtg) {
		if (is_rt_task) {
			policy = SCHED_FIFO | SCHED_RESET_ON_FORK;
			sp.sched_priority = MAX_USER_RT_PRIO - 1 - prio;
		}
		grpid = grp_id;
		if (grpid == DEFAULT_RT_FRAME_ID) {
			grpid = DEFAULT_CGROUP_COLOC_ID;
		}
	} else {
		/* keep policy of launcher (ui render) as SCHED_FIFO:
		 * its prio will be 98 when launcher is dequeued from RTG.
		 */
		if (strncmp("ndroid.launcher", task->comm, TASK_COMM_LEN) == 0) {
			g_pid_launcher = task->pid;
			is_launcher = 1;
			trace_rtg_frame_sched("launcher_pid", g_pid_launcher);
		} else if (task->tgid == g_pid_launcher && g_pid_launcher > 0 &&
             (strncmp("RenderThread", task->comm, TASK_COMM_LEN) == 0 ||
             strncmp("hwuiTask0", task->comm, TASK_COMM_LEN) == 0 ||
             strncmp("hwuiTask1", task->comm, TASK_COMM_LEN) == 0)) {
			is_launcher = 1;
			trace_rtg_frame_sched("launcher_tid", task->pid);
		}

		if (is_launcher == 1) {
			policy = SCHED_FIFO | SCHED_RESET_ON_FORK;
			sp.sched_priority = MAX_USER_RT_PRIO - 2 - prio;
		}
	}

	err = sched_setscheduler_nocheck(task, policy, &sp);
	if (err < 0) {
		pr_err("[AWARE_RTG]: %s task:%d setscheduler err:%d\n",
				__func__, task->pid, err);
		return err;
	}

	if (task->add_rtg_from_cgroup == 1 && grpid == DEFAULT_RTG_GRP_ID) {
		pr_err("[AWARE_RTG]: %s remove task:%d from rtg Abandon !\n", __func__, task->pid);
		return 0;
	}

	err = sched_set_group_id(task, grpid); //lint !e732
	if (err < 0) {
		pr_err("[AWARE_RTG]: %s task:%d set_group_id err:%d\n",
				__func__, task->pid, err);
		if (is_rtg) {
			policy = SCHED_NORMAL;
			sp.sched_priority = 0;
			sched_setscheduler_nocheck(task, policy, &sp);
		}
	}
	return err;
}

#if defined(CONFIG_SCHED_TASK_UTIL_CLAMP) && defined(CONFIG_HW_RTG_AUX)
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

int set_rtg_grp(pid_t tid, bool is_rtg, int grp_id, int prio, int task_util)
{
	struct task_struct *task = NULL;
	int err = -1;
	int depth;

	if ((grp_id < DEFAULT_RTG_GRP_ID) ||
		(grp_id >= MAX_NUM_CGROUP_COLOC_ID))
		return err;

	if ((prio != NOT_RT_PRIO) && is_rtg &&
		(prio < 0 || prio > MAX_USER_RT_PRIO - 1))
		return err;

	if (tid <= 0)
		return err;
	rcu_read_lock();
	task = find_task_by_vpid(tid);
	if (!task) {
		pr_err("[AWARE_RTG] %s tid:%d task is null\n", __func__, tid);
		rcu_read_unlock();
		return err;
	}

	if (task->state == TASK_DEAD) {
		pr_err("[AWARE_RTG] %s task->state == TASK_DEAD !\n", __func__);
		rcu_read_unlock();
		return err;
	}

	get_task_struct(task);
	rcu_read_unlock();

	depth = task->wts.rtg_depth;
	if (is_rtg) {
		task->wts.rtg_depth = STATIC_RTG_DEPTH;
		set_aux_task_min_util(task, task_util);
	} else {
		task->wts.rtg_depth = 0;
		reset_aux_task_min_util(task);
	}

	if (get_enable_type() == TRANS_ENABLE) {
		put_task_struct(task);
		return err;
	}

	if (set_rtg_sched(task, is_rtg, grp_id, prio) < 0) {
		put_task_struct(task);
		task->wts.rtg_depth = depth;
		return err;
	}

	put_task_struct(task);
	return 0;
}

void set_frame_rtg_thread(struct task_struct *task, bool is_rtg)
{
	int depth;

	if (!task)
		return;

	if (task->state == TASK_DEAD) {
		pr_err("[AWARE_RTG] %s task->state == TASK_DEAD !\n", __func__);
		return;
	}

	depth = task->wts.rtg_depth;

	if (is_rtg)
		task->wts.rtg_depth = STATIC_RTG_DEPTH;
	else
		task->wts.rtg_depth = 0;

	if (get_enable_type() == TRANS_ENABLE)
		return;

	if (set_rtg_sched(task, is_rtg, DEFAULT_RT_FRAME_ID,
		DEFAULT_RT_PRIO) < 0) {
		task->wts.rtg_depth = depth;
		return;
	}
}