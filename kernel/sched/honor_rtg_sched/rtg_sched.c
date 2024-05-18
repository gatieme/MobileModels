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
 * rtg sched file
 *
 */

#include <linux/cpufreq.h>
#include <linux/sched.h>
#include <trace/events/sched.h>
#include <trace/hooks/sched.h>

#include <../kernel/sched/sched.h>

#include "include/rtg_perf_ctrl.h"
#include "include/rtg_sched.h"

#ifdef HONOR_RTG_PSEUDO_TICK
#include "include/rtg_pseudo.h"
#endif

#if defined(CONFIG_HONOR_RTG_NORMALIZED_UTIL) && defined(CONFIG_HONOR_SCHED_CLUSTER)
#include "../honor_cluster/sched_cluster.h"
#endif

#ifndef for_each_sched_cluster
#define for_each_sched_cluster(cluster) \
	list_for_each_entry_rcu(cluster, &cluster_head, list)
#endif

#ifndef for_each_sched_cluster_reverse
#define for_each_sched_cluster_reverse(cluster) \
	list_for_each_entry_reverse(cluster, &cluster_head, list)
#endif

#define DEFAULT_FREQ_UPDATE_INTERVAL	8000000  /* ns */
#define DEFAULT_UTIL_INVALID_INTERVAL	(~0U) /* ns */
#define DEFAULT_UTIL_UPDATE_TIMEOUT	20000000  /* ns */
#define DEFAULT_GROUP_RATE		60 /* 60FPS */
#define DEFAULT_RTG_CAPACITY_MARGIN	1077 /* 5% */

#ifdef CONFIG_HONOR_RTG_NORMALIZED_UTIL
static DEFINE_RWLOCK(related_thread_group_lock);
#endif

#define ADD_TASK	0
#define REM_TASK	1

extern unsigned long capacity_spare_without(int cpu, struct task_struct *p);

#if 0
void init_task_rtg(struct task_struct *p)
{
	rcu_assign_pointer(p->wts.grp, NULL);
	INIT_LIST_HEAD(&p->wts.grp_list);
}
#endif

#ifdef CONFIG_USE_RTG_FRAME_SCHED
int sched_set_group_window_size(unsigned int grp_id, unsigned int rate)
{
	struct walt_related_thread_group *grp = NULL;
	unsigned long flag;

	if (!rate)
		return -EINVAL;

	grp = lookup_related_thread_group(grp_id);
	if (!grp) {
		pr_err("set window size for group %d fail\n", grp_id);
		return -ENODEV;
	}

	raw_spin_lock_irqsave(&grp->lock, flag);
	grp->window_size = NSEC_PER_SEC / rate;
	raw_spin_unlock_irqrestore(&grp->lock, flag);

	return 0;
}

void group_time_rollover(struct group_time *time)
{
	time->prev_window_load = time->curr_window_load;
	time->curr_window_load = 0;
	time->prev_window_exec = time->curr_window_exec;
	time->curr_window_exec = 0;
}

int sched_set_group_window_rollover(unsigned int grp_id)
{
	struct walt_related_thread_group *grp = NULL;
	u64 wallclock;
	struct task_struct *p = NULL;
	unsigned long flag;
#ifdef CONFIG_HONOR_RTG_BOOST
	int boost;
#endif

	grp = lookup_related_thread_group(grp_id);
	if (!grp) {
		pr_err("set window start for group %d fail\n", grp_id);
		return -ENODEV;
	}

	raw_spin_lock_irqsave(&grp->lock, flag);

	wallclock = sched_ktime_clock();
	grp->prev_window_time = wallclock - grp->window_start;
	grp->window_start = wallclock;

#ifdef CONFIG_HONOR_RTG_BOOST
	grp->max_boost = INT_MIN;
#endif
	list_for_each_entry(p, &grp->tasks, wts.grp_list) {
		p->wts.prev_window_load = p->wts.curr_window_load;
		p->wts.curr_window_load = 0;
		p->wts.prev_window_exec = p->wts.curr_window_exec;
		p->wts.curr_window_exec = 0;

#ifdef CONFIG_HONOR_RTG_BOOST
		boost = schedtune_task_boost(p);
		if (boost > grp->max_boost)
			grp->max_boost = boost;
#endif
	}

	group_time_rollover(&grp->time);
#ifdef CONFIG_HONOR_RTG_NORMALIZED_UTIL
	group_time_rollover(&grp->time_pref_cluster);
#endif
	raw_spin_unlock_irqrestore(&grp->lock, flag);

	return 0;
}
#endif

#ifdef CONFIG_USE_RTG_FRAME_SCHED
int sched_set_group_freq_update_interval(unsigned int grp_id, unsigned int interval)
{
	struct walt_related_thread_group *grp = NULL;
	unsigned long flag;

	if ((signed int)interval <= 0)
		return -EINVAL;

	/* DEFAULT_CGROUP_COLOC_ID is a reserved id */
	if (grp_id == DEFAULT_CGROUP_COLOC_ID ||
	    grp_id >= MAX_NUM_CGROUP_COLOC_ID)
		return -EINVAL;

	grp = lookup_related_thread_group(grp_id);
	if (!grp) {
		pr_err("set update interval for group %d fail\n", grp_id);
		return -ENODEV;
	}

	raw_spin_lock_irqsave(&grp->lock, flag);
	grp->freq_update_interval = interval * NSEC_PER_MSEC;
#ifdef CONFIG_HONOR_RTG_PSEUDO_TICK
	frame_pseudo_update(grp);
#endif
	raw_spin_unlock_irqrestore(&grp->lock, flag);

	return 0;
}
#else
int sched_set_group_freq_update_interval(unsigned int grp_id, unsigned int interval)
{
	return 0;
}
#endif /* CONFIG_USE_RTG_FRAME_SCHED */

#if defined(CONFIG_HONOR_RTG_NORMALIZED_UTIL) || defined(CONFIG_HONOR_RTG_UCLAMP_UTIL)
static bool group_should_update_freq(struct walt_related_thread_group *grp,
			      int cpu, unsigned int flags, u64 now)
{
	if (!grp || grp->id != DEFAULT_RT_FRAME_ID)
		return true;

	if (flags & FRAME_FORCE_UPDATE) {
#ifdef CONFIG_HONOR_CPU_FREQ_GOV_SCHEDUTIL_COMMON
		sugov_mark_util_change(cpu, FRAME_UPDATE);
#endif
		return true;
	} else if (flags & FRAME_NORMAL_UPDATE) {
		if (now - grp->last_freq_update_time >=
		    grp->freq_update_interval) {
#ifdef CONFIG_HONOR_CPU_FREQ_GOV_SCHEDUTIL_COMMON
			sugov_mark_util_change(cpu, FRAME_UPDATE);
#endif
			return true;
		}
	}

	return false;
}
#endif

#ifdef CONFIG_USE_RTG_FRAME_SCHED 
int sched_set_group_load_mode(struct rtg_load_mode *mode)
{
	struct walt_related_thread_group *grp = NULL;
	unsigned long flag;

	if (mode->grp_id <= DEFAULT_CGROUP_COLOC_ID ||
	    mode->grp_id >= MAX_NUM_CGROUP_COLOC_ID) {
		pr_err("grp_id=%d is invalid.\n", mode->grp_id);
		return -EINVAL;
	}

	grp = lookup_related_thread_group(mode->grp_id);
	if (!grp) {
		pr_err("set invalid interval for group %d fail\n", mode->grp_id);
		return -ENODEV;
	}

	raw_spin_lock_irqsave(&grp->lock, flag);
	grp->mode.freq_enabled = !!mode->freq_enabled;
	grp->mode.util_enabled = !!mode->util_enabled;
	raw_spin_unlock_irqrestore(&grp->lock, flag);

	return 0;
}
#endif

#ifdef CONFIG_HONOR_ED_TASK
int sched_set_group_ed_params(struct rtg_ed_params *params)
{
	struct walt_related_thread_group *grp = NULL;
	unsigned long flag;

	if (params->grp_id <= DEFAULT_CGROUP_COLOC_ID ||
	    params->grp_id >= MAX_NUM_CGROUP_COLOC_ID) {
		pr_err("grp_id=%d is invalid.\n", params->grp_id);
		return -EINVAL;
	}

	grp = lookup_related_thread_group(params->grp_id);
	if (!grp) {
		pr_err("set invalid interval for group %d fail\n",
			params->grp_id);
		return -ENODEV;
	}

	raw_spin_lock_irqsave(&grp->lock, flag);
	grp->ed_enabled = params->enabled > 0 ? true : false;
	grp->ed_task_running_duration = params->running_ns;
	grp->ed_task_waiting_duration = params->waiting_ns;
	grp->ed_new_task_running_duration = params->nt_running_ns;
	raw_spin_unlock_irqrestore(&grp->lock, flag);

	return 0;
}
#endif /* CONFIG_HONOR_ED_TASK */

#ifdef CONFIG_HONOR_RTG_CPU_TIME
static struct group_cpu_time *_group_cpu_time(struct walt_related_thread_group *grp,
				       int cpu)
{
	return grp ? per_cpu_ptr(grp->cpu_time, cpu) : NULL;
}

/*
 * A group's window_start may be behind. When moving it forward, flip prev/curr
 * counters. When moving forward > 1 window, prev counter is set to 0
 */
void group_sync_window_start(struct rq *rq, struct group_cpu_time *cpu_time)
{
	u64 delta;
	int nr_windows;
	u64 curr_sum = cpu_time->curr_runnable_sum;

	delta = rq->window_start - cpu_time->window_start;
	if (!delta)
		return;

	nr_windows = div64_u64(delta, walt_ravg_window);
	if (nr_windows > 1)
		curr_sum = 0;

	cpu_time->prev_runnable_sum  = curr_sum;
	cpu_time->curr_runnable_sum  = 0;

	cpu_time->window_start = rq->window_start;
}

struct group_cpu_time *group_update_cpu_time(struct rq *rq,
	struct walt_related_thread_group *grp)
{
	struct group_cpu_time *cpu_time = NULL;

	if (grp) {
		/* cpu_time protected by rq_lock */
		cpu_time = _group_cpu_time(grp, cpu_of(rq));

		/* group window roll over */
		group_sync_window_start(rq, cpu_time);
	}

	return cpu_time;
}

bool group_migrate_task(struct task_struct *p,
			struct rq *src_rq, struct rq *dest_rq)
{
	struct group_cpu_time *cpu_time = NULL;
	struct walt_related_thread_group *grp = p->wts->grp;
	u64 *src_curr_runnable_sum = NULL;
	u64 *dst_curr_runnable_sum = NULL;
	u64 *src_prev_runnable_sum = NULL;
	u64 *dst_prev_runnable_sum = NULL;

	if (!grp)
		return false;

	/* Protected by rq_lock */
	cpu_time = _group_cpu_time(grp, cpu_of(src_rq));
	src_curr_runnable_sum = &cpu_time->curr_runnable_sum;
	src_prev_runnable_sum = &cpu_time->prev_runnable_sum;

	/* Protected by rq_lock */
	cpu_time = _group_cpu_time(grp, cpu_of(dest_rq));
	dst_curr_runnable_sum = &cpu_time->curr_runnable_sum;
	dst_prev_runnable_sum = &cpu_time->prev_runnable_sum;

	group_sync_window_start(dest_rq, cpu_time);

	if (p->ravg.curr_window) {
		*src_curr_runnable_sum -= p->ravg.curr_window;
		*dst_curr_runnable_sum += p->ravg.curr_window;
	}

	if (p->ravg.prev_window) {
		*src_prev_runnable_sum -= p->ravg.prev_window;
		*dst_prev_runnable_sum += p->ravg.prev_window;
	}

	return true;
}

/*
 * Task's cpu usage is accounted in:
 *	rq->curr/prev_runnable_sum,  when its ->grp is NULL
 *	grp->cpu_time[cpu]->curr/prev_runnable_sum, when its ->grp is !NULL
 *
 * Transfer task's cpu usage between those counters when transitioning between
 * groups
 */
static void transfer_busy_time(struct rq *rq, struct walt_related_thread_group *grp,
			       struct task_struct *p, int event)
{
	u64 wallclock;
	struct group_cpu_time *cpu_time = NULL;
	u64 *src_curr_runnable_sum = NULL;
	u64 *dst_curr_runnable_sum = NULL;
	u64 *src_prev_runnable_sum = NULL;
	u64 *dst_prev_runnable_sum = NULL;

	wallclock = walt_ktime_clock();

	walt_update_task_ravg(rq->curr, rq, TASK_UPDATE, wallclock, 0);
	walt_update_task_ravg(p, rq, TASK_UPDATE, wallclock, 0);

	raw_spin_lock(&grp->lock);
	/* cpu_time protected by related_thread_group_lock, grp->lock rq_lock */
	cpu_time = _group_cpu_time(grp, cpu_of(rq));
	if (event == ADD_TASK) {
		group_sync_window_start(rq, cpu_time);
		src_curr_runnable_sum = &rq->curr_runnable_sum;
		dst_curr_runnable_sum = &cpu_time->curr_runnable_sum;
		src_prev_runnable_sum = &rq->prev_runnable_sum;
		dst_prev_runnable_sum = &cpu_time->prev_runnable_sum;
	} else {
		/*
		 * In case of REM_TASK, cpu_time->window_start would be
		 * uptodate, because of the update_task_ravg() we called
		 * above on the moving task. Hence no need for
		 * group_sync_window_start()
		 */
		src_curr_runnable_sum = &cpu_time->curr_runnable_sum;
		dst_curr_runnable_sum = &rq->curr_runnable_sum;
		src_prev_runnable_sum = &cpu_time->prev_runnable_sum;
		dst_prev_runnable_sum = &rq->prev_runnable_sum;
	}

	*src_curr_runnable_sum -= p->ravg.curr_window;
	*dst_curr_runnable_sum += p->ravg.curr_window;

	*src_prev_runnable_sum -= p->ravg.prev_window;
	*dst_prev_runnable_sum += p->ravg.prev_window;
	raw_spin_unlock(&grp->lock);
}

void sched_update_group_load(struct rq *rq)
{
	int cpu = cpu_of(rq);
	struct walt_related_thread_group *grp = NULL;
	unsigned long flags;

	/*
	 * This function could be called in timer context, and the
	 * current task may have been executing for a long time. Ensure
	 * that the window stats are current by doing an update.
	 */
	read_lock_irqsave(&related_thread_group_lock, flags);

	for_each_related_thread_group(grp) {
		/* Protected by rq_lock */
		struct group_cpu_time *cpu_time =
					_group_cpu_time(grp, cpu);
		group_sync_window_start(rq, cpu_time);
		rq->group_load += cpu_time->prev_runnable_sum;
	}

	read_unlock_irqrestore(&related_thread_group_lock, flags);
}
#else
#if 0
static inline void group_sync_window_start(struct rq *rq,
			struct group_cpu_time *cpu_time)
{
}

static inline void transfer_busy_time(struct rq *rq,
				      struct walt_related_thread_group *grp,
				      struct task_struct *p, int event)
{
}
#endif
#endif

#ifdef CONFIG_USE_RTG_FRAME_SCHED
int sched_set_group_util_invalid_interval(unsigned int grp_id,
					  unsigned int interval)
{
	struct walt_related_thread_group *grp = NULL;
	unsigned long flag;

	if (interval == 0)
		return -EINVAL;

	/* DEFAULT_CGROUP_COLOC_ID is a reserved id */
	if (grp_id == DEFAULT_CGROUP_COLOC_ID ||
	    grp_id >= MAX_NUM_CGROUP_COLOC_ID)
		return -EINVAL;

	grp = lookup_related_thread_group(grp_id);
	if (!grp) {
		pr_err("set invalid interval for group %d fail\n", grp_id);
		return -ENODEV;
	}

	raw_spin_lock_irqsave(&grp->lock, flag);
	if ((signed int)interval < 0)
		grp->util_invalid_interval = DEFAULT_UTIL_INVALID_INTERVAL;
	else
		grp->util_invalid_interval = interval * NSEC_PER_MSEC;
	raw_spin_unlock_irqrestore(&grp->lock, flag);

	return 0;
}
#endif

#ifdef CONFIG_USE_RTG_FRAME_SCHED
static inline bool
group_should_invalid_util(struct walt_related_thread_group *grp, u64 now)
{
	if (grp->util_invalid_interval == DEFAULT_UTIL_INVALID_INTERVAL)
		return false;

	return (now - grp->last_freq_update_time >= grp->util_invalid_interval);
}
#else
#if 0
static inline bool
group_should_invalid_util(struct walt_related_thread_group *grp, u64 now)
{
	return false;
}
#endif
#endif

#ifdef CONFIG_HONOR_RTG_CPU_TIME
static inline void free_group_cputime(struct walt_related_thread_group *grp)
{
	if (grp->cpu_time)
		free_percpu(grp->cpu_time);
}

static int alloc_group_cputime(struct walt_related_thread_group *grp)
{
	int i;
	int ret;
	struct group_cpu_time *cpu_time = NULL;
	int cpu = raw_smp_processor_id();
	struct rq *rq = cpu_rq(cpu);
	u64 window_start = rq->window_start;

	grp->cpu_time = alloc_percpu(struct group_cpu_time);
	if (!grp->cpu_time)
		return -ENOMEM;

	for_each_possible_cpu(i) {
		cpu_time = per_cpu_ptr(grp->cpu_time, i);
		ret = memset_s(cpu_time, sizeof(*cpu_time), 0,
			       sizeof(*cpu_time));
		if (ret != 0) {
			pr_err("memset cpu time fail\n");
			return -ENODEV;
		}

		cpu_time->window_start = window_start;
	}

	return 0;
}
#endif

#if 0
/* group_id == 0: remove task from rtg */
extern int sched_set_group_id(struct task_struct *p, unsigned int group_id);
#endif

int honor_sched_set_group_id(struct task_struct *p, unsigned int group_id)
{
	int ret = -1;
	// Use trace hook to call real function in walt.ko.
	trace_android_rvh_sched_set_group_id(p, group_id, &ret);

	// if trace_hook is not working, ret is -1.
	return ret;
}

int honor_sched_set_group_id_by_pid(pid_t pid, unsigned int group_id)
{
	struct task_struct *p = NULL;
	int ret;

	rcu_read_lock();
	p = find_task_by_vpid(pid);
	if (!p) {
		rcu_read_unlock();
		return -ESRCH;
	}

	/* Prevent p going away */
	get_task_struct(p);
	rcu_read_unlock();

	ret = honor_sched_set_group_id(p, group_id);
	put_task_struct(p);

	return ret;
}

#ifdef CONFIG_USE_RTG_FRAME_SCHED
void sched_update_rtg_tick(struct task_struct *p)
{
	struct walt_related_thread_group *grp = NULL;

	rcu_read_lock();
	grp = task_related_thread_group(p);
	if (!grp || list_empty(&grp->tasks)) {
		rcu_read_unlock();
		return;
	}
	rcu_read_unlock();

	if (grp->rtg_class)
		grp->rtg_class->sched_update_rtg_tick(grp);
}
#endif

#ifdef CONFIG_HONOR_RTG_NORMALIZED_UTIL
unsigned int get_cluster_grp_running(int cluster_id)
{
	struct walt_related_thread_group *grp = NULL;
	unsigned int total_grp_running = 0;
	unsigned long flag, rtg_flag;
	unsigned int i;

	read_lock_irqsave(&related_thread_group_lock, rtg_flag);

	/* grp_id 0 is used for exited tasks */
	for (i = 1; i < MAX_NUM_CGROUP_COLOC_ID; i++) {
		grp = lookup_related_thread_group(i);
		if (!grp)
			continue;

		raw_spin_lock_irqsave(&grp->lock, flag);
		if (grp->preferred_cluster != NULL &&
		    grp->preferred_cluster->id == cluster_id)
			total_grp_running += grp->nr_running;
		raw_spin_unlock_irqrestore(&grp->lock, flag);
	}
	read_unlock_irqrestore(&related_thread_group_lock, rtg_flag);

	return total_grp_running;
}

int sched_set_group_freq(unsigned int grp_id, unsigned int freq)
{
	struct walt_related_thread_group *grp = NULL;
	struct walt_sched_cluster *prefer_cluster = NULL;
	int prefer_cluster_cpu;
	unsigned long flag;
	u64 now;

	/* DEFAULT_CGROUP_COLOC_ID is a reserved id */
	if (grp_id == DEFAULT_CGROUP_COLOC_ID ||
	    grp_id >= MAX_NUM_CGROUP_COLOC_ID)
		return -EINVAL;

	grp = lookup_related_thread_group(grp_id);
	if (!grp) {
		pr_err("set freq for group %d fail\n", grp_id);
		return -ENODEV;
	}
	prefer_cluster = grp->preferred_cluster;
	if (!prefer_cluster) {
		pr_err("set freq for group %d fail, no cluster\n", grp_id);
		return -ENODEV;
	}
	prefer_cluster_cpu = cpumask_first(&prefer_cluster->cpus);

	raw_spin_lock_irqsave(&grp->lock, flag);
	now = ktime_get_ns();
	grp->us_set_min_freq = freq;
	grp->last_freq_update_time = now;
	raw_spin_unlock_irqrestore(&grp->lock, flag);

#ifdef CONFIG_HONOR_CPU_FREQ_GOV_SCHEDUTIL_COMMON
	sugov_mark_util_change(prefer_cluster_cpu, FORCE_UPDATE);
	sugov_check_freq_update(prefer_cluster_cpu);
#endif

	return 0;
}

static inline bool valid_normalized_util(struct walt_related_thread_group *grp)
{
	struct task_struct *p = NULL;
	cpumask_t rtg_cpus = CPU_MASK_NONE;
	bool valid = false;

	if (grp->nr_running != 0) {
		list_for_each_entry(p, &grp->tasks, wts.grp_list) {
			get_task_struct(p);
			if (p->state == TASK_RUNNING)
				cpumask_set_cpu(task_cpu(p), &rtg_cpus);
			trace_sched_rtg_task_each(grp->id, grp->nr_running, p);
			put_task_struct(p);
		}

		valid = cpumask_intersects(&rtg_cpus,
					  &grp->preferred_cluster->cpus);
	}

	trace_sched_rtg_valid_normalized_util(grp->id, grp->nr_running, &rtg_cpus, valid);
	return valid;
}

void sched_get_max_group_util(const struct cpumask *query_cpus,
			      unsigned long *util, unsigned int *freq)
{
	struct walt_related_thread_group *grp = NULL;
	unsigned long max_grp_util = 0;
	unsigned int max_grp_freq = 0;
	u64 now = ktime_get_ns();
	unsigned long rtg_flag;
	unsigned long flag;

	/*
	 *  sum the prev_runnable_sum for each rtg,
	 *  return the max rtg->load
	 */
	read_lock_irqsave(&related_thread_group_lock, rtg_flag);
	if (list_empty(&active_related_thread_groups))
		goto unlock;

	for_each_related_thread_group(grp) {
		raw_spin_lock_irqsave(&grp->lock, flag);
		if (!list_empty(&grp->tasks) &&
		    grp->preferred_cluster != NULL &&
		    cpumask_intersects(query_cpus,
				       &grp->preferred_cluster->cpus) &&
		    !group_should_invalid_util(grp, now)) {
			if (grp->us_set_min_freq > max_grp_freq)
				max_grp_freq = grp->us_set_min_freq;

			if (grp->time.normalized_util > max_grp_util &&
			    valid_normalized_util(grp))
				max_grp_util = grp->time.normalized_util;
		}
		raw_spin_unlock_irqrestore(&grp->lock, flag);
	}

unlock:
	read_unlock_irqrestore(&related_thread_group_lock, rtg_flag);

	*freq = max_grp_freq;
	*util = max_grp_util;
}

#if 0
int preferred_cluster(struct walt_sched_cluster *cluster, struct task_struct *p)
{
	struct related_thread_group *grp = NULL;
	int rc = 1;

	rcu_read_lock();

	grp = task_related_thread_group(p);
	if (grp != NULL)
		rc = (grp->preferred_cluster == cluster);

	rcu_read_unlock();
	return rc;
}
#endif

static void _honor_set_preferred_cluster(struct walt_related_thread_group *grp,
				   int sched_cluster_id)
{
	struct walt_sched_cluster *cluster = NULL;
	struct walt_sched_cluster *cluster_found = NULL;

	if (sched_cluster_id == -1) {
		grp->preferred_cluster = NULL;
		return;
	}

	for_each_sched_cluster_reverse(cluster) {
		if (cluster->id == sched_cluster_id) {
			cluster_found = cluster;
			break;
		}
	}

	if (cluster_found != NULL)
		grp->preferred_cluster = cluster_found;
	else
		pr_err("cannot found sched_cluster_id=%d\n", sched_cluster_id);
}

/*
 * sched_cluster_id == -1: grp will set to NULL
 */
static void honor_set_preferred_cluster(struct walt_related_thread_group *grp,
				  int sched_cluster_id)
{
	unsigned long flag;

	raw_spin_lock_irqsave(&grp->lock, flag);
	_honor_set_preferred_cluster(grp, sched_cluster_id);
	raw_spin_unlock_irqrestore(&grp->lock, flag);
}

int sched_set_group_preferred_cluster(unsigned int grp_id, int sched_cluster_id)
{
	struct walt_related_thread_group *grp = NULL;

	/* DEFAULT_CGROUP_COLOC_ID is a reserved id */
	if (grp_id == DEFAULT_CGROUP_COLOC_ID ||
	    grp_id >= MAX_NUM_CGROUP_COLOC_ID)
		return -EINVAL;

	grp = lookup_related_thread_group(grp_id);
	if (!grp) {
		pr_err("set preferred cluster for group %d fail\n", grp_id);
		return -ENODEV;
	}
	honor_set_preferred_cluster(grp, sched_cluster_id);

	return 0;
}

#if defined(CONFIG_HONOR_RTG_BOOST) && defined(CONFIG_SCHED_TUNE)
#ifdef CONFIG_MTK_PLATFORM
extern long schedtune_margin(int cpu, unsigned long signal, long boost);
#else
extern long schedtune_margin(unsigned long signal, long boost);
#endif
int schedtune_grp_margin(unsigned long util, struct walt_related_thread_group *grp)
{
	int boost = grp->max_boost;
	if (boost == 0)
		return 0;

#ifdef CONFIG_MTK_PLATFORM
	return schedtune_margin(-1, util, boost);
#else
	return schedtune_margin(util, boost);
#endif
}
#else
static inline int schedtune_grp_margin(unsigned long util,
				       struct walt_related_thread_group *grp)
{
	return 0;
}
#endif

static struct walt_sched_cluster *best_cluster(struct walt_related_thread_group *grp)
{
	struct walt_sched_cluster *cluster = NULL;
	struct walt_sched_cluster *max_cluster = NULL;
	int cpu;
	unsigned long util = grp->time.normalized_util;
	unsigned long boosted_grp_util = util + schedtune_grp_margin(util, grp);
	unsigned long max_cap = 0;
	unsigned long cap = 0;

#ifdef CONFIG_HONOR_RTG_BOOST
	if (grp->max_boost > 0)
		return max_cap_cluster();
#endif

	/* find new cluster */
	for_each_sched_cluster(cluster) {
		cpu = cpumask_first(&cluster->cpus);
		cap = capacity_orig_of(cpu);
		if (cap > max_cap) {
			max_cap = cap;
			max_cluster = cluster;
		}

		if (boosted_grp_util <= cap)
			return cluster;
	}

	return max_cluster;
}

int sched_set_group_normalized_util(unsigned int grp_id, unsigned long util,
				    unsigned int flag)
{
	struct walt_related_thread_group *grp = NULL;
	bool need_update_prev_freq = false;
	bool need_update_next_freq = false;
	u64 now;
	unsigned long flags;
	struct walt_sched_cluster *preferred_cluster = NULL;
	int prev_cpu;
	int next_cpu;

	grp = lookup_related_thread_group(grp_id);
	if (!grp) {
		pr_err("set normalized util for group %d fail\n", grp_id);
		return -ENODEV;
	}

	raw_spin_lock_irqsave(&grp->lock, flags);

	if (list_empty(&grp->tasks)) {
		raw_spin_unlock_irqrestore(&grp->lock, flags);
		return 0;
	}

	grp->time.normalized_util = util;

	preferred_cluster = best_cluster(grp);

	/* update prev_cluster force when preferred_cluster changed */
	if (!grp->preferred_cluster) {
		grp->preferred_cluster = preferred_cluster;
	} else if (grp->preferred_cluster != preferred_cluster) {
		prev_cpu = cpumask_first(&grp->preferred_cluster->cpus);
		grp->preferred_cluster = preferred_cluster;

		need_update_prev_freq = true;
	}

	if (grp->preferred_cluster != NULL)
		next_cpu = cpumask_first(&grp->preferred_cluster->cpus);
	else
		next_cpu = 0;

	now = ktime_get_ns();
	grp->last_util_update_time = now;
	need_update_next_freq =
		group_should_update_freq(grp, next_cpu, flag, now);
	if (need_update_next_freq)
		grp->last_freq_update_time = now;

	raw_spin_unlock_irqrestore(&grp->lock, flags);

	if (need_update_prev_freq) {
#ifdef CONFIG_HONOR_CPU_FREQ_GOV_SCHEDUTIL_COMMON
		sugov_mark_util_change(prev_cpu, FRAME_UPDATE); //lint !e644
		sugov_check_freq_update(prev_cpu);
#endif
	}
	if (need_update_next_freq) {
#ifdef CONFIG_HONOR_CPU_FREQ_GOV_SCHEDUTIL_COMMON
		sugov_check_freq_update(next_cpu);
#endif
	}

	return 0;
}


struct cpumask *find_rtg_target(struct task_struct *p)
{
	struct walt_related_thread_group *grp = NULL;
	struct walt_sched_cluster *preferred_cluster = NULL;
	struct cpumask *rtg_target = NULL;

	rcu_read_lock();
	grp = task_related_thread_group(p);
	rcu_read_unlock();

	if (!grp)
		return NULL;

	preferred_cluster = grp->preferred_cluster;
	if (!preferred_cluster)
		return NULL;

	rtg_target = &preferred_cluster->cpus;
#ifdef CONFIG_HONOR_EAS_SCHED
	if (!task_fits_max(p, cpumask_first(rtg_target)))
		return NULL;
#endif
	return rtg_target;
}

int find_rtg_cpu(struct task_struct *p, struct cpumask *preferred_cpus)
{
	int i;
	cpumask_t search_cpus = CPU_MASK_NONE;
	int max_spare_cap_cpu =-1;
	unsigned long max_spare_cap = 0;
	int idle_backup_cpu = -1;

	cpumask_and(&search_cpus, &p->cpus_mask, cpu_online_mask);
	cpumask_andnot(&search_cpus, &search_cpus, cpu_isolated_mask);

	/* search the perferred idle cpu */
	for_each_cpu_and(i, &search_cpus, preferred_cpus) {
		if (is_reserved(i))
			continue;

		if (idle_cpu(i) || (i == task_cpu(p) && p->state == TASK_RUNNING)) {
			trace_find_rtg_cpu(p, preferred_cpus, "prefer_idle", i);
			return i;
		}
	}

	for_each_cpu(i, &search_cpus) {
		unsigned long spare_cap;

		if (honor_walt_cpu_high_irqload(i))
			continue;

		if (is_reserved(i))
			continue;

		/* take the Active LB CPU as idle_backup_cpu */
		if (idle_cpu(i) || (i == task_cpu(p) && p->state == TASK_RUNNING)) {
			/* find the idle_backup_cpu with max capacity */
			if (idle_backup_cpu == -1 ||
				capacity_orig_of(i) > capacity_orig_of(idle_backup_cpu))
				idle_backup_cpu = i;

			continue;
		}

		spare_cap = capacity_spare_without(i, p);
		if (spare_cap > max_spare_cap) {
			max_spare_cap = spare_cap;
			max_spare_cap_cpu = i;
		}
	}

	if (idle_backup_cpu != -1) {
		trace_find_rtg_cpu(p, preferred_cpus, "idle_backup", idle_backup_cpu);
		return idle_backup_cpu;
	}

	trace_find_rtg_cpu(p, preferred_cpus, "max_spare", max_spare_cap_cpu);

	return max_spare_cap_cpu;
}
#else /* CONFIG_HONOR_RTG_NORMALIZED_UTIL */
#if 0
static inline void _set_preferred_cluster(struct walt_related_thread_group *grp,
					  int sched_cluster_id)
{
}
#endif
#endif /* CONFIG_HONOR_RTG_NORMALIZED_UTIL */

#ifdef CONFIG_HONOR_RTG_UCLAMP_UTIL
static inline int set_task_min_util_tick(struct walt_related_thread_group *grp,
				struct task_struct *p, unsigned int new_util)
{
	struct rq *rq = NULL;
	unsigned int old_util;
	int cpu;
	bool should_update_freq = false;
	bool need_update_freq = false;
	u64 now = ktime_get_ns();
	unsigned long flag;

	if (!p || new_util > SCHED_CAPACITY_SCALE) {
		pr_err("%s invalid arg %u\n", __func__, new_util);
		return -EINVAL;
	}

	rq = task_rq(p);
	cpu = cpu_of(rq);

	old_util = p->util_req.min_util;
	p->util_req.min_util = new_util;
#ifdef CONFIG_SCHED_TASK_UTIL_CLAMP
	trace_task_min_util(p);
#endif
	/*
	 * Nothing more to do for sleeping tasks or no change.
	 * Protected by p->pi_lock, we can safely check p->on_rq
	 * and check p's old min_util.
	 * Protected by rq->lock, we can safely manipulate rq's
	 * min_util_req list.
	 */
	if (task_on_rq_queued(p) && new_util != old_util) {
		if (new_util > old_util &&
			new_util > capacity_curr_of(cpu))
			should_update_freq = true;

		write_lock_irqsave(&rq->util_lock, flag);
		if (old_util == 0) {
			if (likely(list_empty(&p->util_req.min_util_entry)))
				list_add(&p->util_req.min_util_entry, &rq->min_util_req);
		}

		if (new_util == 0) {
			if (likely(!list_empty(&p->util_req.min_util_entry)))
				list_del_init(&p->util_req.min_util_entry);
		}
		write_unlock_irqrestore(&rq->util_lock, flag);
	}

	if (!should_update_freq)
		return 0;

	need_update_freq = group_should_update_freq(grp, cpu,
			FRAME_NORMAL_UPDATE,
			ktime_get_ns());

	if (need_update_freq) {
		grp->last_freq_update_time = now;
		read_lock_irqsave(&rq->util_lock, flag);
#ifdef CONFIG_HONOR_CPU_FREQ_GOV_SCHEDUTIL_COMMON
		sugov_check_freq_update(cpu);
#endif
		read_unlock_irqrestore(&rq->util_lock, flag);
	}

	return 0;
}

void sched_set_group_min_util(struct walt_related_thread_group *grp, int min_util)
{
	struct task_struct *p = NULL;
	unsigned long flags;
	u64 now;

	if (min_util < 0 || min_util > SCHED_CAPACITY_SCALE)
		return;

	raw_spin_lock_irqsave(&grp->lock, flags);
	if (list_empty(&grp->tasks))
		goto unlock;

	list_for_each_entry(p, &grp->tasks, wts.grp_list)
		set_task_min_util_tick(grp, p, min_util);

	now = ktime_get_ns();
	grp->last_util_update_time = now;

unlock:
	raw_spin_unlock_irqrestore(&grp->lock, flags);
}
#endif

#if defined(CONFIG_HONOR_RTG_NORMALIZED_UTIL) || defined(CONFIG_SCHED_TASK_UTIL_CLAMP) \
	|| defined(CONFIG_CLUSTER_NORMALIZED_UTIL)
unsigned int honor_freq_to_util(unsigned int cpu, unsigned int freq)
{
	unsigned long util = 0UL;

	util = arch_scale_cpu_capacity(cpu) *
		(unsigned long)freq / cpu_rq(cpu)->wrq.cluster->max_possible_freq;
	util = clamp(util, 0UL, (unsigned long)SCHED_CAPACITY_SCALE);

	return util;
}
#endif

#if defined(CONFIG_HONOR_RTG_NORMALIZED_UTIL)
int set_task_rtg_min_freq(struct task_struct *p, unsigned int freq)
{
	unsigned int cluster_cpu;
	struct walt_related_thread_group *grp = NULL;
	struct walt_sched_cluster *prefer_cluster = NULL;
#ifdef CONFIG_SCHED_TASK_UTIL_CLAMP
	unsigned int util;
#endif
	unsigned long flags;
	int ret = 0;

	if (!p)
		return -EINVAL;

	rcu_read_lock();
	grp = task_related_thread_group(p);
	rcu_read_unlock();

	if (!grp)
		return -ENODEV;
	prefer_cluster = grp->preferred_cluster;
	if (!prefer_cluster)
		return -ENODEV;

	raw_spin_lock_irqsave(&grp->lock, flags);
	grp->us_set_min_freq = freq;
	grp->last_freq_update_time = ktime_get_ns();
	raw_spin_unlock_irqrestore(&grp->lock, flags);

	cluster_cpu = cpumask_first(&prefer_cluster->cpus);

#ifdef CONFIG_HONOR_CPU_FREQ_GOV_SCHEDUTIL_COMMON
	sugov_mark_util_change(cluster_cpu, FORCE_UPDATE);
#endif

#ifdef CONFIG_SCHED_TASK_UTIL_CLAMP
	util = honor_freq_to_util(cluster_cpu, freq);
	ret = set_task_min_util(p, util);
#endif

#ifdef CONFIG_HONOR_CPU_FREQ_GOV_SCHEDUTIL_COMMON
	sugov_check_freq_update(cluster_cpu);
#endif

	return ret;
}
#endif

#ifdef CONFIG_CLUSTER_NORMALIZED_UTIL
#define RTG_FREQ_INVALID_INTERVAL 50000000 // 50ms

struct rtg_global {
	raw_spinlock_t lock;
	struct walt_sched_cluster *preferred_cluster;
	u64 last_freq_update_time;
	unsigned int us_set_min_freq;
	unsigned int us_set_max_freq;
};

struct rtg_global *global;

int init_rtg_global(void)
{
	global = kzalloc(sizeof(*global), GFP_NOWAIT);
	if (!global) {
		return -ENOMEM;
	}

	global->preferred_cluster = NULL;
	global->last_freq_update_time = 0;
	global->us_set_min_freq = 0;
	global->us_set_max_freq = 0;
	raw_spin_lock_init(&global->lock);
	return 0;
}

static inline bool
cluster_should_invalid_freq(u64 now)
{
	return (now - global->last_freq_update_time >= RTG_FREQ_INVALID_INTERVAL);
}

unsigned int sched_restrict_cluster_freq(const struct cpumask *query_cpus, unsigned int freq,
	int cpu, unsigned int policy_min, unsigned int policy_max)
{
	u64 now = ktime_get_ns();
	unsigned long flag;
	unsigned int next_f = freq;

	raw_spin_lock_irqsave(&global->lock, flag);
	if (global->preferred_cluster != NULL &&
		cpumask_intersects(query_cpus, &global->preferred_cluster->cpus) &&
		!cluster_should_invalid_freq(now)) {
		next_f = max(global->us_set_min_freq, next_f);
		if (global->us_set_max_freq)
			next_f = min(global->us_set_max_freq, next_f);
		trace_sugov_freq_update(cpu, freq, global->us_set_min_freq, global->us_set_max_freq, next_f,
			policy_min, policy_max);
	}

	raw_spin_unlock_irqrestore(&global->lock, flag);
	return next_f;
}

static void _honor_set_global_preferred_cluster(int sched_cluster_id)
{
	struct walt_sched_cluster *cluster = NULL;
	struct walt_sched_cluster *cluster_found = NULL;

	if (sched_cluster_id == -1) {
		global->preferred_cluster = NULL;
		return;
	}

	for_each_sched_cluster_reverse(cluster) {
		if (cluster->id == sched_cluster_id) {
			cluster_found = cluster;
			break;
		}
	}

	if (cluster_found != NULL)
		global->preferred_cluster = cluster_found;
	else
		pr_err("cannot found sched_cluster_id=%d\n", sched_cluster_id);
}

static void honor_set_global_preferred_cluster(int sched_cluster_id)
{
	unsigned long flag;

	raw_spin_lock_irqsave(&global->lock, flag);
	_honor_set_global_preferred_cluster(sched_cluster_id);
	raw_spin_unlock_irqrestore(&global->lock, flag);
}

int set_task_rtg_cluster_freq(struct task_struct *p, int cluster_id, unsigned int min_freq, unsigned int max_freq)
{
	unsigned int cluster_cpu;
	struct walt_sched_cluster *prefer_cluster = NULL;
#ifdef CONFIG_SCHED_TASK_UTIL_CLAMP
	unsigned int util;
#endif
	unsigned long flags;
	int ret = 0;

	if (!p)
		return -EINVAL;

	honor_set_global_preferred_cluster(cluster_id);

	prefer_cluster = global->preferred_cluster;
	if (!prefer_cluster)
		return -ENODEV;

	raw_spin_lock_irqsave(&global->lock, flags);
	global->us_set_min_freq = min_freq;
	global->us_set_max_freq = max_freq;
	global->last_freq_update_time = ktime_get_ns();
	trace_rtg_global_update(global->preferred_cluster ? global->preferred_cluster->id : -1,
		global->last_freq_update_time, global->us_set_min_freq, global->us_set_max_freq);
	raw_spin_unlock_irqrestore(&global->lock, flags);

	cluster_cpu = cpumask_first(&prefer_cluster->cpus);

#ifdef CONFIG_HONOR_CPU_FREQ_GOV_SCHEDUTIL_COMMON
	sugov_mark_util_change(cluster_cpu, FORCE_UPDATE);
#endif

#ifdef CONFIG_SCHED_TASK_UTIL_CLAMP
	util = honor_freq_to_util(cluster_cpu, min_freq);
	ret = set_task_min_util(p, util);
#endif

#ifdef CONFIG_HONOR_CPU_FREQ_GOV_SCHEDUTIL_COMMON
	sugov_check_freq_update(cluster_cpu);
#endif

	return ret;
}
#endif
