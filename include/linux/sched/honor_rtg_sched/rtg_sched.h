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

#ifndef HONOR_RTG_H
#define HONOR_RTG_H

#ifdef CONFIG_HONOR_RTG

#define honor_walt_cpu_high_irqload sched_cpu_high_irqload

#ifdef CONFIG_HONOR_RTG_DEBUG
extern struct list_head active_related_thread_groups;
#define for_each_related_thread_group(grp) \
	list_for_each_entry(grp, &active_related_thread_groups, list)
#endif

extern struct list_head cluster_head;

int honor_sched_set_group_id_by_pid(pid_t pid, unsigned int group_id);
int honor_sched_set_group_id(struct task_struct *p, unsigned int group_id);

struct rtg_load_mode;
void init_task_rtg(struct task_struct *p);
int sched_set_group_load_mode(struct rtg_load_mode *mode);
void sched_update_rtg_tick(struct task_struct *p);
int sched_set_group_util_invalid_interval(unsigned int grp_id,
					  unsigned int interval);
int sched_set_group_freq_update_interval(unsigned int grp_id,
					 unsigned int interval);
int sched_set_group_window_size(unsigned int grp_id, unsigned int rate);
int sched_set_group_window_rollover(unsigned int grp_id);
#endif

#ifdef CONFIG_HONOR_RTG_NORMALIZED_UTIL
int sched_set_group_preferred_cluster(unsigned int grp_id, int sched_cluster_id);
int sched_set_group_freq(unsigned int grp_id, unsigned int freq);
int sched_set_group_normalized_util(unsigned int grp_id, unsigned long util,
				    unsigned int flag);

struct cpumask *find_rtg_target(struct task_struct *p);
int find_rtg_cpu(struct task_struct *p, struct cpumask *preferred_cpus);
void sched_get_max_group_util(const struct cpumask *query_cpus,
			      unsigned long *util, unsigned int *freq);
#else

static inline int sched_set_group_preferred_cluster(unsigned int grp_id,
						    int sched_cluster_id)
{
	return 0;
}

static inline int sched_set_group_freq(unsigned int grp_id, unsigned int freq)
{
	return 0;
}

static inline int sched_set_group_normalized_util(unsigned int grp_id, unsigned long util,
				    unsigned int flag)
{
	return 0;
}

static inline void sched_get_max_group_util(const struct cpumask *query_cpus,
			      unsigned long *util, unsigned int *freq)
{
}
#endif

struct rtg_ed_params;
#ifdef CONFIG_HONOR_ED_TASK
int sched_set_group_ed_params(struct rtg_ed_params *params);
#else
static inline int sched_set_group_ed_params(struct rtg_ed_params *params)
{
	return -ENODEV;
}
#endif


#ifdef CONFIG_HONOR_RTG_WALT
struct rq;
struct group_cpu_time *group_update_cpu_time(struct rq *rq,
		struct walt_related_thread_group *grp);
#endif


#ifdef CONFIG_HONOR_RTG_NORMALIZED_UTIL
extern int set_task_rtg_min_freq(struct task_struct *p, unsigned int freq);
#else
static inline int set_task_rtg_min_freq(struct task_struct *p, unsigned int freq)
{
	return 0;
}

#ifdef CONFIG_HONOR_RTG_FRAME_USE_MIN_UTIL
void sched_set_group_min_util(struct walt_related_thread_group *grp, int min_util);
#endif

#endif /* CONFIG_HONOR_RTG */

#ifdef CONFIG_CLUSTER_NORMALIZED_UTIL
int init_rtg_global(void);
unsigned int sched_restrict_cluster_freq(const struct cpumask *query_cpus, unsigned int freq,
	int cpu, unsigned int policy_min, unsigned int policy_max);
extern int set_task_rtg_cluster_freq(struct task_struct *p, int cluster_id,
	unsigned int min_freq, unsigned int max_freq);
#else
static inline int set_task_rtg_cluster_freq(struct task_struct *p, int cluster_id,
	unsigned int min_freq, unsigned int max_freq)
{
	return 0;
}
#endif
#endif
