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
 * aux grp debug header
 */

#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <trace/hooks/sched.h>
#include <../kernel/sched/sched.h>

#include "include/aux_info.h"
#include "include/aux.h"
#include "include/rtg_sched.h"
#include "include/rtg.h"
#ifdef CONFIG_HONOR_RTG_FRAME_USE_NORMALIZED_UTIL
#include "../honor_cluster/sched_cluster.h"
#endif

/*
 * This allows printing both to /proc/sched_debug and
 * to the console
 */

#if 0
#define aux_seq_printf(sfile, info...) \
do { \
	if (sfile) \
		seq_printf(sfile, info); \
	else \
		printk(info); \
} while (0)

extern struct walt_related_thread_group* lookup_related_thread_group(unsigned int group_id);

#ifdef CONFIG_AUX_RTG_BOOST_UTIL
static void print_aux_info(struct seq_file *sfile,
	const struct walt_related_thread_group *grp)
{
	struct aux_info *aux_info = (struct aux_info *) grp->aux_info_data;

	aux_seq_printf(sfile, "AUX_INFO    : MIN_UTIL:%d##BOOST_UTIL:%d##PRIO:%d\n",
		aux_info->min_util,
		aux_info->boost_util,
		aux_info->prio);
#ifdef CONFIG_HONOR_RTG_FRAME_USE_NORMALIZED_UTIL
	aux_seq_printf(sfile, "AUX_CLUSTER : %d\n",
		grp->preferred_cluster ? grp->preferred_cluster->id : -1);
#endif
}
#endif

static char aux_task_state_to_char(const struct task_struct *tsk)
{
	static const char state_char[] = "RSDTtXZPI";
	unsigned int tsk_state = READ_ONCE(tsk->state);
	unsigned int state = (tsk_state | tsk->exit_state) & TASK_REPORT;

	BUILD_BUG_ON_NOT_POWER_OF_2(TASK_REPORT_MAX);
	BUILD_BUG_ON(1 + ilog2(TASK_REPORT_MAX) != sizeof(state_char) - 1);

	if (tsk_state == TASK_IDLE)
		state = TASK_REPORT_IDLE;

	return state_char[fls(state)];
}

static void print_aux_task_header(struct seq_file *sfile,
	const char *header, int run, int nr)
{
	aux_seq_printf(sfile,
		"%s   : %d/%d\n"
#ifdef CONFIG_HONOR_RTG_FRAME_USE_MIN_UTIL
		"STATE		COMM	TGID	PID	PRIO	  UTIL		UTIL\n"
#else
		"STATE		COMM	TGID	PID	PRIO	  CPU\n"
#endif
		"---------------------------------------------------------\n",
		header, run, nr);
}

static void print_aux_task(struct seq_file *sfile,
	const struct task_struct *p)
{
#ifdef CONFIG_HONOR_RTG_FRAME_USE_MIN_UTIL
	aux_seq_printf(sfile, "%5c %15s %6d %6d %6d %5d %8d (%*pbl)\n",
#else
	aux_seq_printf(sfile, "%5c %15s %6d %6d %6d %5d (%*pbl)\n",
#endif
		aux_task_state_to_char(p), p->comm,
		p->tgid, p->pid, p->prio, task_cpu(p),
#ifdef CONFIG_HONOR_RTG_FRAME_USE_MIN_UTIL
		p->util_req.min_util,
#endif
		cpumask_pr_args(&p->cpus_mask));
}

static void print_aux_threads(struct seq_file *sfile,
	const struct walt_related_thread_group *grp)
{
	struct task_struct *p = NULL;
	int nr_thread = 0;

	list_for_each_entry(p, &grp->tasks, wts.grp_list) {
		nr_thread++;
	}
#ifdef CONFIG_USE_RTG_FRAME_SCHED
	print_aux_task_header(sfile, "AUX_THREADS", grp->nr_running, nr_thread);
#else
	print_aux_task_header(sfile, "AUX_THREADS", nr_thread, nr_thread);
#endif
	list_for_each_entry(p, &grp->tasks, wts.grp_list) {
		if (!p)
			continue;
		get_task_struct(p);
		print_aux_task(sfile, p);
		put_task_struct(p);
	}
}

static int sched_aux_debug_show(struct seq_file *sfile, void *v)
{
	struct walt_related_thread_group *grp = NULL;
	unsigned long flags;

	grp = lookup_related_thread_group(DEFAULT_AUX_ID);
	if (!grp) {
		aux_seq_printf(sfile, "IPROVISION AUX none\n");
		return 0;
	}

	raw_spin_lock_irqsave(&grp->lock, flags);
	if (list_empty(&grp->tasks)) {
		raw_spin_unlock_irqrestore(&grp->lock, flags);
		aux_seq_printf(sfile, "IPROVISION AUX tasklist empty\n");
		return 0;
	}

#ifdef CONFIG_AUX_RTG_BOOST_UTIL
	print_aux_info(sfile, grp);
#endif
	print_aux_threads(sfile, grp);
	raw_spin_unlock_irqrestore(&grp->lock, flags);

	return 0;
}
#endif

static int collect_rtg_group_debug_info(unsigned int group_id, struct seq_file *sfile)
{
	int ret = -1;
	trace_android_rvh_sched_get_rtg_group_debug_info(group_id, sfile, &ret);
	return ret;
}

static int sched_aux_rtg_debug_show(struct seq_file *sfile, void *v)
{
	return  collect_rtg_group_debug_info(DEFAULT_AUX_ID, sfile);
}

static int sched_aux_debug_release(struct inode *inode, struct file *file)
{
	single_release(inode, file);
	return 0;
}

static int sched_aux_debug_open(struct inode *inode, struct file *filp)
{
	return single_open(filp, sched_aux_rtg_debug_show, NULL);
}

static const struct proc_ops sched_aux_debug_ops = {
	.proc_open = sched_aux_debug_open,
	.proc_read = seq_read,
	.proc_lseek = seq_lseek,
	.proc_release = sched_aux_debug_release,
};

static int __init init_aux_sched_debug_procfs(void)
{
	struct proc_dir_entry *pe = NULL;

	pe = proc_create("sched_aux_debug",
		0444, NULL, &sched_aux_debug_ops);
	if (!pe)
		return -ENOMEM;
	return 0;
}
late_initcall(init_aux_sched_debug_procfs);
