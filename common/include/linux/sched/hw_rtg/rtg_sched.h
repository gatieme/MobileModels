/*
 * rtg_sched.h
 *
 * rtg sched header
 *
 * Copyright (c) 2020-2020 Huawei Technologies Co., Ltd.
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

#ifndef HW_RTG_H
#define HW_RTG_H

#if IS_ENABLED(CONFIG_HW_RTG)
#include <linux/version.h>
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
#include <../kernel/sched/walt/walt.h>
#include <linux/sched/walt.h>
#include "rtg.h"
#endif

#if IS_ENABLED(CONFIG_HW_RTG_DEBUG)
extern struct list_head active_related_thread_groups;
#define for_each_related_thread_group(grp) \
	list_for_each_entry(grp, &active_related_thread_groups, list)
#endif

#if IS_ENABLED(CONFIG_UCLAMP_TASK) && !IS_ENABLED(CONFIG_SCHED_TUNE)
#define schedtune_task_boost uclamp_boosted
#define schedtune_prefer_idle uclamp_latency_sensitive
#endif

int alloc_related_thread_groups(void);
int sched_set_group_id(pid_t pid, unsigned int group_id);
int _sched_set_group_id(struct task_struct *p, unsigned int group_id);
struct related_thread_group *lookup_related_thread_group(unsigned int group_id);
int sched_set_group_window_size(unsigned int grp_id, unsigned int rate);
int sched_set_group_window_rollover(unsigned int grp_id);
int sched_set_group_freq_update_interval(unsigned int grp_id,
					 unsigned int interval);
int sched_set_group_util_invalid_interval(unsigned int grp_id,
					  unsigned int interval);
struct rtg_load_mode;
int sched_set_group_load_mode(struct rtg_load_mode *mode);
unsigned int sched_get_group_id(struct task_struct *p);
void add_new_task_to_grp(struct task_struct *new);
void sched_update_rtg_tick(struct rtg_tick_info *tick_info);
void init_task_rtg(struct task_struct *p);
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 4, 0))
int preferred_cluster(struct walt_sched_cluster *cluster, struct task_struct *p);
#else
int preferred_cluster(struct sched_cluster *cluster, struct task_struct *p);
#endif

static inline
struct related_thread_group *task_related_thread_group(struct task_struct *p)
{
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	struct walt_task_struct *wts = (struct walt_task_struct *) p->android_vendor_data1;
	return rcu_dereference(wts->grp);
#else
	return rcu_dereference(p->grp);
#endif
}
#endif

#if IS_ENABLED(CONFIG_HW_RTG_NORMALIZED_UTIL)
int sched_set_group_preferred_cluster(unsigned int grp_id, int sched_cluster_id);
int sched_set_group_freq(unsigned int grp_id, unsigned int freq);
int sched_set_group_normalized_util(unsigned int grp_id, unsigned long util,
				    unsigned int flag);

struct cpumask *find_rtg_target(struct task_struct *p);
int find_rtg_cpu(struct task_struct *p, struct cpumask *preferred_cpus);
#ifndef CONFIG_HW_AI_SCHED_QCOM_DDR_CONTROL
void sched_get_max_group_util(const struct cpumask *query_cpus,
			      unsigned long *util, unsigned int *freq);
#else
void sched_get_max_group_util(const struct cpumask *query_cpus,
			      unsigned long *util, unsigned int *freq,
			      struct ff_frame_info *ff_info);
#endif
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
#ifndef CONFIG_HW_AI_SCHED_QCOM_DDR_CONTROL
static inline void sched_get_max_group_util(const struct cpumask *query_cpus,
			      unsigned long *util, unsigned int *freq)
#else
static inline void sched_get_max_group_util(const struct cpumask *query_cpus,
				unsigned long *util, unsigned int *freq,
				struct ff_frame_info *ff_info)
#endif
{
}
#endif

struct rtg_ed_params;
#ifdef CONFIG_HW_ED_TASK
int sched_set_group_ed_params(struct rtg_ed_params *params);
#else
static inline int sched_set_group_ed_params(struct rtg_ed_params *params)
{
	return -ENODEV;
}
#endif


#if IS_ENABLED(CONFIG_HW_RTG_WALT)
struct rq;
struct group_cpu_time *group_update_cpu_time(struct rq *rq,
	struct related_thread_group *grp);
#endif


#if IS_ENABLED(CONFIG_HW_RTG_NORMALIZED_UTIL)
#ifndef CONFIG_HW_AI_SCHED_QCOM_DDR_CONTROL
extern int set_task_rtg_min_freq(struct task_struct *p, unsigned int freq);
#else
extern int set_task_rtg_min_freq(struct task_struct *p, unsigned int freq,
				 unsigned int cur_ff_frame);
#endif
#else
#ifndef CONFIG_HW_AI_SCHED_QCOM_DDR_CONTROL
static inline int set_task_rtg_min_freq(struct task_struct *p, unsigned int freq)
{
	return 0;
}
#else
static inline int set_task_rtg_min_freq(struct task_struct *p,
					unsigned int freq,
					unsigned int cur_ff_frame)
{
	return 0;
}
#endif

#ifdef CONFIG_HW_RTG_FRAME_USE_MIN_UTIL
void sched_set_group_min_util(struct related_thread_group *grp, int min_util);
#endif

#endif /* CONFIG_HW_RTG_NORMALIZED_UTIL */

#include "rtg_cgroup.h"
#endif /* CONFIG_HW_RTG */
