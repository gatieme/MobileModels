/*
 * Copyright (c) 2016, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __PRED_LOAD_H__
#define __PRED_LOAD_H__

#include "walt_common.h"

#ifdef CONFIG_HW_SCHED_PRED_LOAD
#ifdef CONFIG_HAVE_QCOM_SCHED_WALT
unsigned long predict_util(struct rq *rq);
unsigned long task_pred_util(struct task_struct *p);
static inline u64 get_walt_mark_start(struct task_struct *p)
{
	return walt_task_struct_get(p, mark_start);
}
static inline const struct cpumask* get_cluster_cpus(struct rq *rq)
{
	return &(walt_rq_get(rq, cluster))->cpus;
}
#ifdef CONFIG_HW_SCHED_PRED_LOAD_WINDOW_SIZE_TUNNABLE
void pred_load_inc_sum_pred_load(struct rq *rq, struct task_struct *p);
void pred_load_dec_sum_pred_load(struct rq *rq, struct task_struct *p);
unsigned long max_pred_ls(struct rq *rq);
unsigned long cpu_util_pred_min(struct rq *rq);
extern unsigned int predl_jump_load;
extern unsigned int predl_do_predict;
extern unsigned int predl_window_size;
extern unsigned int predl_enable;
#ifdef CONFIG_HW_SCHED_PRED_LOAD_WINDOW_SIZE_SYNC
static DEFINE_SPINLOCK(pred_load_window_lock);
extern unsigned int new_predl_window_size;
extern void predl_window_size_change_handle(u64 wc);
#endif
extern void update_task_predl(struct task_struct *p,
			      struct rq *rq, int event, u64 wallclock);
extern void update_predl_window_start(struct rq *rq, u64 wallclock);
extern void fixup_pred_load(struct rq *rq, s64 pred_load_delta);
#else
static inline unsigned long max_pred_ls(struct rq *rq) { return 0; }
static inline unsigned long cpu_util_pred_min(struct rq *rq) { return 0; }
#endif /* CONFIG_HW_SCHED_PRED_LOAD_WINDOW_SIZE_TUNNABLE */
#else
bool use_pred_load(int cpu);
unsigned long predict_util(struct rq *rq);
unsigned long task_pred_util(struct task_struct *p);
static inline u64 get_walt_mark_start(struct task_struct *p)
{
	return walt_task_struct_get(p, mark_start);
}
static inline const struct cpumask* get_cluster_cpus(struct rq *rq)
{
	return &(walt_rq_get(rq, cluster))->cpus;
}
unsigned long max_pred_ls(struct rq *rq);
unsigned long cpu_util_pred_min(struct rq *rq);
extern unsigned int predl_jump_load;
extern unsigned int predl_do_predict;
extern unsigned int predl_window_size;
extern unsigned int predl_enable;

extern void update_task_predl(struct task_struct *p,
			      struct rq *rq, int event, u64 wallclock);
static void fixup_pred_load(struct rq *rq, s64 pred_load_delta);
extern void update_predl_window_start(struct rq *rq, u64 wallclock);
#endif /* CONFIG_HAVE_QCOM_SCHED_WALT */
#else
static inline bool use_pred_load(int cpu) { return false; }
static inline unsigned long predict_util(struct rq *rq) { return 0; }
static inline unsigned long task_pred_util(struct task_struct *p) { return 0; }
static inline unsigned long max_pred_ls(struct rq *rq) { return 0; }
static inline unsigned long cpu_util_pred_min(struct rq *rq) { return 0; }
#endif /* HW_SCHED_PRED_LOAD */
#endif
