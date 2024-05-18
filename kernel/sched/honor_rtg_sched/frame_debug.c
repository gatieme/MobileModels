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
 * Frame debug info implementation
 *
 */

#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <trace/hooks/sched.h>

#include "include/frame_info.h"
#include "include/rtg.h"
#ifdef CONFIG_HONOR_RTG_FRAME_USE_NORMALIZED_UTIL
#include "../honor_cluster/sched_cluster.h"
#endif

/*
 * This allows printing both to /proc/sched_debug and to the console
 */

#if 0
#define seq_printf_frame(m, x...) \
do { \
	if (m) \
		seq_printf(m, x); \
	else \
		printk(x); \
} while (0)

#ifdef CONFIG_USE_RTG_FRAME_SCHED
static void print_frame_info(struct seq_file *file,
	const struct walt_related_thread_group *grp)
{
	struct frame_info *frame_info = (struct frame_info *)grp->private_data;

	u64 now = ktime_get_ns();
	u64 frame_end = grp->window_start;

	seq_printf_frame(file, "FRAME_INFO      : QOS:%u#MARGIN:%dSTATE:%lu\n",
		frame_info->qos_frame,
		frame_info->vload_margin,
		frame_info->status);
	seq_printf_frame(file, "FRAME_CLAMP     : PREV:%u/%u#UTIL:%u/%u\n",
		frame_info->prev_min_util, frame_info->prev_max_util,
		frame_info->frame_min_util, frame_info->frame_max_util);
	seq_printf_frame(file, "FRAME_LOAD_MODE : %s/%s\n",
		grp->mode.util_enabled ? "true" : "false",
		grp->mode.freq_enabled ? "true" : "false");
	seq_printf_frame(file, "FRAME_INTERVAL  : UPDATE:%ldms#INVALID:%ldms\n",
		grp->freq_update_interval / NSEC_PER_MSEC,
		grp->util_invalid_interval / NSEC_PER_MSEC);
	seq_printf_frame(file,
		"FRAME_TIMESTAMP : timestamp:%llu#now:%llu#delta:%llu\n",
		frame_end, now, now - frame_end);
	seq_printf_frame(file, "FRAME_LAST_TIME : %llu/%llu\n",
		(unsigned long long)frame_info->prev_frame_exec,
		(unsigned long long)frame_info->prev_frame_time);
#ifdef CONFIG_HONOR_RTG_FRAME_USE_NORMALIZED_UTIL
	seq_printf_frame(file, "FRAME_CLUSTER   : %d\n",
		grp->preferred_cluster ? grp->preferred_cluster->id : -1);
#endif
}
#endif /* CONFIG_USE_RTG_FRAME_SCHED */

static char frame_task_state_to_char(const struct task_struct *tsk)
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

static inline void print_frame_task_header(struct seq_file *file,
	const char *header, int run, int nr)
{
	seq_printf_frame(file,
		"%s   : %d/%d\n"
		"STATE		COMM	   PID	PRIO	CPU\n"
		"---------------------------------------------------------\n",
		header, run, nr);
}

static inline void print_frame_task(struct seq_file *file,
	const struct task_struct *tsk)
{
	seq_printf_frame(file, "%5c %15s %5d %5d %5d(%*pbl)\n",
		frame_task_state_to_char(tsk), tsk->comm, tsk->pid, tsk->prio,
		task_cpu(tsk), cpumask_pr_args(&tsk->cpus_mask));
}

static void print_frame_threads(struct seq_file *file,
	const struct walt_related_thread_group *grp)
{
	struct task_struct *tsk = NULL;
	int nr_thread = 0;

	list_for_each_entry(tsk, &grp->tasks, wts.grp_list) {
		nr_thread++;
	}
#ifdef CONFIG_USE_RTG_FRAME_SCHED
	print_frame_task_header(file, "FRAME_THREADS",
		grp->nr_running, nr_thread);
#else
	print_frame_task_header(file, "FRAME_THREADS",
		nr_thread, nr_thread);
#endif
	list_for_each_entry(tsk, &grp->tasks, wts.grp_list) {
		if (unlikely(!tsk))
			continue;
		get_task_struct(tsk);
		print_frame_task(file, tsk);
		put_task_struct(tsk);
	}
}

static int sched_frame_debug_show(struct seq_file *file, void *param)
{
	struct walt_related_thread_group *grp = NULL;
	unsigned long flags;

	grp = lookup_related_thread_group(DEFAULT_RT_FRAME_ID);
	if (unlikely(!grp)) {
		seq_printf_frame(file, "IPROVISION RTG none\n");
		return 0;
	}

	raw_spin_lock_irqsave(&grp->lock, flags);
	if (list_empty(&grp->tasks)) {
		raw_spin_unlock_irqrestore(&grp->lock, flags);
		seq_printf_frame(file, "IPROVISION RTG tasklist empty\n");
		return 0;
	}

#ifdef CONFIG_USE_RTG_FRAME_SCHED
	print_frame_info(file, grp);
#endif

	print_frame_threads(file, grp);
	raw_spin_unlock_irqrestore(&grp->lock, flags);
	return 0;
}
#endif

static int collect_frame_rtg_group_debug_info(unsigned int group_id, struct seq_file *sfile)
{
	int ret = -1;
	trace_android_rvh_sched_get_rtg_group_debug_info(group_id, sfile, &ret);
	return ret;
}

static int sched_frame_rtg_debug_show(struct seq_file *sfile, void *v)
{
	return collect_frame_rtg_group_debug_info(DEFAULT_RT_FRAME_ID, sfile);
}

static int sched_frame_debug_release(struct inode *inode, struct file *file)
{
	seq_release(inode, file);
	return 0;
}

static int sched_frame_debug_open(struct inode *inode, struct file *filp)
{
	return single_open(filp, sched_frame_rtg_debug_show, NULL);
}

static const struct proc_ops sched_frame_debug_ops = {
	.proc_open = sched_frame_debug_open,
	.proc_read = seq_read,
	.proc_lseek = seq_lseek,
	.proc_release = sched_frame_debug_release,
};

static int __init init_sched_debug_procfs(void)
{
	struct proc_dir_entry *pe = NULL;

	pe = proc_create("sched_frame_debug",
		0444, NULL, &sched_frame_debug_ops);
	if (unlikely(!pe))
		return -ENOMEM;
	return 0;
}
late_initcall(init_sched_debug_procfs);
