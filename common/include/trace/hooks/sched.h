/* SPDX-License-Identifier: GPL-2.0 */
#undef TRACE_SYSTEM
#define TRACE_SYSTEM sched
#define TRACE_INCLUDE_PATH trace/hooks
#if !defined(_TRACE_HOOK_SCHED_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_HOOK_SCHED_H
#include <linux/tracepoint.h>
#include <trace/hooks/vendor_hooks.h>
/*
 * Following tracepoints are not exported in tracefs and provide a
 * mechanism for vendor modules to hook and extend functionality
 */
struct cgroup_taskset;
#ifdef __GENKSYMS__
struct cgroup_subsys_state;
struct cpufreq_policy;
struct em_perf_domain;
enum uclamp_id;
struct sched_entity;
struct task_struct;
struct uclamp_se;
#else
/* struct cgroup_subsys_state */
#include <linux/cgroup-defs.h>
/* struct cpufreq_policy */
#include <linux/cpufreq.h>
/* struct em_perf_domain */
#include <linux/energy_model.h>
/* enum uclamp_id, struct sched_entity, struct task_struct, struct uclamp_se */
#include <linux/sched.h>
#endif /* __GENKSYMS__ */
DECLARE_RESTRICTED_HOOK(android_rvh_select_task_rq_fair,
	TP_PROTO(struct task_struct *p, int prev_cpu, int sd_flag, int wake_flags, int *new_cpu),
	TP_ARGS(p, prev_cpu, sd_flag, wake_flags, new_cpu), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_select_task_rq_rt,
	TP_PROTO(struct task_struct *p, int prev_cpu, int sd_flag, int wake_flags, int *new_cpu),
	TP_ARGS(p, prev_cpu, sd_flag, wake_flags, new_cpu), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_select_fallback_rq,
	TP_PROTO(int cpu, struct task_struct *p, int *new_cpu),
	TP_ARGS(cpu, p, new_cpu), 1);

struct rq;
DECLARE_HOOK(android_vh_scheduler_tick,
	TP_PROTO(struct rq *rq),
	TP_ARGS(rq));

DECLARE_RESTRICTED_HOOK(android_rvh_enqueue_task,
	TP_PROTO(struct rq *rq, struct task_struct *p, int flags),
	TP_ARGS(rq, p, flags), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_dequeue_task,
	TP_PROTO(struct rq *rq, struct task_struct *p, int flags),
	TP_ARGS(rq, p, flags), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_can_migrate_task,
	TP_PROTO(struct task_struct *p, int dst_cpu, int *can_migrate),
	TP_ARGS(p, dst_cpu, can_migrate), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_find_lowest_rq,
	TP_PROTO(struct task_struct *p, struct cpumask *local_cpu_mask,
			int ret, int *lowest_cpu),
	TP_ARGS(p, local_cpu_mask, ret, lowest_cpu), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_prepare_prio_fork,
	TP_PROTO(struct task_struct *p),
	TP_ARGS(p), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_finish_prio_fork,
	TP_PROTO(struct task_struct *p),
	TP_ARGS(p), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_rtmutex_prepare_setprio,
	TP_PROTO(struct task_struct *p, struct task_struct *pi_task),
	TP_ARGS(p, pi_task), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_set_user_nice,
	TP_PROTO(struct task_struct *p, long *nice, bool *allowed),
	TP_ARGS(p, nice, allowed), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_setscheduler,
	TP_PROTO(struct task_struct *p),
	TP_ARGS(p), 1);

struct sched_group;
DECLARE_RESTRICTED_HOOK(android_rvh_find_busiest_group,
	TP_PROTO(struct sched_group *busiest, struct rq *dst_rq, int *out_balance),
		TP_ARGS(busiest, dst_rq, out_balance), 1);

DECLARE_HOOK(android_vh_dump_throttled_rt_tasks,
	TP_PROTO(int cpu, u64 clock, ktime_t rt_period, u64 rt_runtime,
			s64 rt_period_timer_expires),
	TP_ARGS(cpu, clock, rt_period, rt_runtime, rt_period_timer_expires));

DECLARE_HOOK(android_vh_jiffies_update,
	TP_PROTO(void *unused),
	TP_ARGS(unused));

struct rq_flags;
DECLARE_RESTRICTED_HOOK(android_rvh_sched_newidle_balance,
	TP_PROTO(struct rq *this_rq, struct rq_flags *rf,
		 int *pulled_task, int *done),
	TP_ARGS(this_rq, rf, pulled_task, done), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_sched_nohz_balancer_kick,
	TP_PROTO(struct rq *rq, unsigned int *flags, int *done),
	TP_ARGS(rq, flags, done), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_sched_rebalance_domains,
	TP_PROTO(struct rq *rq, int *continue_balancing),
	TP_ARGS(rq, continue_balancing), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_find_busiest_queue,
	TP_PROTO(int dst_cpu, struct sched_group *group,
		 struct cpumask *env_cpus, struct rq **busiest,
		 int *done),
	TP_ARGS(dst_cpu, group, env_cpus, busiest, done), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_migrate_queued_task,
	TP_PROTO(struct rq *rq, struct rq_flags *rf,
		 struct task_struct *p, int new_cpu,
		 int *detached),
	TP_ARGS(rq, rf, p, new_cpu, detached), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_resume_cpus,
	TP_PROTO(struct cpumask *cpus, int *err),
	TP_ARGS(cpus, err), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_find_energy_efficient_cpu,
	TP_PROTO(struct task_struct *p, int prev_cpu, int sync, int *new_cpu),
	TP_ARGS(p, prev_cpu, sync, new_cpu), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_set_iowait,
	TP_PROTO(struct task_struct *p, int *should_iowait_boost),
	TP_ARGS(p, should_iowait_boost), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_cpu_overutilized,
	TP_PROTO(int cpu, int *overutilized),
	TP_ARGS(cpu, overutilized), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_sched_setaffinity,
	TP_PROTO(struct task_struct *p, const struct cpumask *in_mask, int *retval),
	TP_ARGS(p, in_mask, retval), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_update_cpus_allowed,
	TP_PROTO(struct task_struct *p, cpumask_var_t cpus_requested,
		 const struct cpumask *new_mask, int *ret),
	TP_ARGS(p, cpus_requested, new_mask, ret), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_set_task_cpu,
	TP_PROTO(struct task_struct *p, unsigned int new_cpu),
	TP_ARGS(p, new_cpu), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_try_to_wake_up,
	TP_PROTO(struct task_struct *p),
	TP_ARGS(p), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_try_to_wake_up_success,
	TP_PROTO(struct task_struct *p),
	TP_ARGS(p), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_sched_fork,
	TP_PROTO(struct task_struct *p),
	TP_ARGS(p), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_wake_up_new_task,
	TP_PROTO(struct task_struct *p),
	TP_ARGS(p), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_new_task_stats,
	TP_PROTO(struct task_struct *p),
	TP_ARGS(p), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_flush_task,
	TP_PROTO(struct task_struct *prev),
	TP_ARGS(prev), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_tick_entry,
	TP_PROTO(struct rq *rq),
	TP_ARGS(rq), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_schedule,
	TP_PROTO(struct task_struct *prev, struct task_struct *next, struct rq *rq),
	TP_ARGS(prev, next, rq), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_sched_cpu_starting,
	TP_PROTO(int cpu),
	TP_ARGS(cpu), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_sched_cpu_dying,
	TP_PROTO(int cpu),
	TP_ARGS(cpu), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_account_irq,
	TP_PROTO(struct task_struct *curr, int cpu, s64 delta),
	TP_ARGS(curr, cpu, delta), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_place_entity,
	TP_PROTO(struct cfs_rq *cfs_rq, struct sched_entity *se, int initial, u64 vruntime),
	TP_ARGS(cfs_rq, se, initial, vruntime), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_build_perf_domains,
	TP_PROTO(bool *eas_check),
	TP_ARGS(eas_check), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_update_cpu_capacity,
	TP_PROTO(int cpu, unsigned long *capacity),
	TP_ARGS(cpu, capacity), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_update_misfit_status,
	TP_PROTO(struct task_struct *p, struct rq *rq, bool *need_update),
	TP_ARGS(p, rq, need_update), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_cpu_cgroup_attach,
	TP_PROTO(struct cgroup_taskset *tset),
	TP_ARGS(tset), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_cpu_cgroup_can_attach,
	TP_PROTO(struct cgroup_taskset *tset, int *retval),
	TP_ARGS(tset, retval), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_cpu_cgroup_online,
	TP_PROTO(struct cgroup_subsys_state *css),
	TP_ARGS(css), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_sched_fork_init,
	TP_PROTO(struct task_struct *p),
	TP_ARGS(p), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_ttwu_cond,
	TP_PROTO(bool *cond),
	TP_ARGS(cond), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_schedule_bug,
	TP_PROTO(struct task_struct *p),
	TP_ARGS(p), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_sched_exec,
	TP_PROTO(bool *cond),
	TP_ARGS(cond), 1);

DECLARE_HOOK(android_vh_map_util_freq,
	TP_PROTO(unsigned long util, unsigned long freq,
		unsigned long cap, unsigned long *next_freq, struct cpufreq_policy *policy,
		bool *need_freq_update),
	TP_ARGS(util, freq, cap, next_freq, policy, need_freq_update));

DECLARE_HOOK(android_vh_set_top_task_hist_size,
	TP_PROTO(struct rq *rq, unsigned int val),
	TP_ARGS(rq, val));

DECLARE_HOOK(android_vh_set_top_task_stats_policy,
	TP_PROTO(struct rq *rq, unsigned int val),
	TP_ARGS(rq, val));

DECLARE_HOOK(android_vh_set_top_task_stats_empty_window,
	TP_PROTO(struct rq *rq, unsigned int val),
	TP_ARGS(rq, val));

DECLARE_HOOK(android_vh_em_cpu_energy,
	TP_PROTO(struct em_perf_domain *pd,
		unsigned long max_util, unsigned long sum_util,
		unsigned long *energy),
	TP_ARGS(pd, max_util, sum_util, energy));

DECLARE_RESTRICTED_HOOK(android_rvh_sched_balance_rt,
	TP_PROTO(struct rq *rq, struct task_struct *p, int *done),
	TP_ARGS(rq, p, done), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_dequeue_task_idle,
	TP_PROTO(struct task_struct *p),
	TP_ARGS(p), 1);

struct cfs_rq;
DECLARE_RESTRICTED_HOOK(android_rvh_pick_next_entity,
	TP_PROTO(struct cfs_rq *cfs_rq, struct sched_entity *curr,
		 struct sched_entity **se),
	TP_ARGS(cfs_rq, curr, se), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_check_preempt_wakeup,
	TP_PROTO(struct rq *rq, struct task_struct *p, bool *preempt, bool *nopreempt,
			int wake_flags, struct sched_entity *se, struct sched_entity *pse,
			int next_buddy_marked, unsigned int granularity),
	TP_ARGS(rq, p, preempt, nopreempt, wake_flags, se, pse, next_buddy_marked,
			granularity), 1);

DECLARE_HOOK(android_vh_do_wake_up_sync,
	TP_PROTO(struct wait_queue_head *wq_head, int *done),
	TP_ARGS(wq_head, done));

DECLARE_HOOK(android_vh_set_wake_flags,
	TP_PROTO(int *wake_flags, unsigned int *mode),
	TP_ARGS(wake_flags, mode));

/* Conditionally defined upon CONFIG_UCLAMP_TASK */
struct uclamp_se;
DECLARE_RESTRICTED_HOOK(android_rvh_uclamp_eff_get,
	TP_PROTO(struct task_struct *p, enum uclamp_id clamp_id,
		 struct uclamp_se *uclamp_max, struct uclamp_se *uclamp_eff, int *ret),
	TP_ARGS(p, clamp_id, uclamp_max, uclamp_eff, ret), 1);

DECLARE_HOOK(android_vh_build_sched_domains,
	TP_PROTO(bool has_asym),
	TP_ARGS(has_asym));
DECLARE_RESTRICTED_HOOK(android_rvh_check_preempt_tick,
	TP_PROTO(struct task_struct *p, unsigned long *ideal_runtime, bool *skip_preempt,
			unsigned long delta_exec, struct cfs_rq *cfs_rq, struct sched_entity *curr,
			unsigned int granularity),
	TP_ARGS(p, ideal_runtime, skip_preempt, delta_exec, cfs_rq, curr, granularity), 1);
DECLARE_RESTRICTED_HOOK(android_rvh_replace_next_task_fair,
	TP_PROTO(struct rq *rq, struct task_struct **p, struct sched_entity **se, bool *repick,
			bool simple, struct task_struct *prev),
	TP_ARGS(rq, p, se, repick, simple, prev), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_do_sched_yield,
	TP_PROTO(struct rq *rq),
	TP_ARGS(rq), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_util_est_update,
	TP_PROTO(struct cfs_rq *cfs_rq, struct task_struct *p, bool task_sleep, int *ret),
	TP_ARGS(cfs_rq, p, task_sleep, ret), 1);

DECLARE_HOOK(android_vh_account_task_time,
	TP_PROTO(struct task_struct *p, struct rq *rq, int user_tick),
	TP_ARGS(p, rq, user_tick));

DECLARE_HOOK(android_vh_irqtime_account_process_tick,
	TP_PROTO(struct task_struct *p, struct rq *rq, int user_tick, int ticks),
	TP_ARGS(p, rq, user_tick, ticks));

DECLARE_RESTRICTED_HOOK(android_rvh_post_init_entity_util_avg,
	TP_PROTO(struct sched_entity *se),
	TP_ARGS(se), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_set_cpus_allowed_comm,
	TP_PROTO(struct task_struct *p, const struct cpumask *new_mask),
	TP_ARGS(p, new_mask), 1);

DECLARE_HOOK(android_vh_sched_setaffinity_early,
	TP_PROTO(struct task_struct *p, const struct cpumask *new_mask, int *retval),
	TP_ARGS(p, new_mask, retval));

DECLARE_HOOK(android_vh_free_task,
	TP_PROTO(struct task_struct *p),
	TP_ARGS(p));

DECLARE_RESTRICTED_HOOK(android_rvh_after_enqueue_task,
	TP_PROTO(struct rq *rq, struct task_struct *p),
	TP_ARGS(rq, p), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_after_dequeue_task,
	TP_PROTO(struct rq *rq, struct task_struct *p),
	TP_ARGS(rq, p), 1);

struct cfs_rq;
struct rq_flags;
DECLARE_RESTRICTED_HOOK(android_rvh_enqueue_entity,
	TP_PROTO(struct cfs_rq *cfs, struct sched_entity *se),
	TP_ARGS(cfs, se), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_dequeue_entity,
	TP_PROTO(struct cfs_rq *cfs, struct sched_entity *se),
	TP_ARGS(cfs, se), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_enqueue_task_fair,
	TP_PROTO(struct rq *rq, struct task_struct *p, int flags),
	TP_ARGS(rq, p, flags), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_dequeue_task_fair,
	TP_PROTO(struct rq *rq, struct task_struct *p, int flags),
	TP_ARGS(rq, p, flags), 1);

DECLARE_HOOK(android_vh_prepare_update_load_avg_se,
	TP_PROTO(struct sched_entity *se, int flags),
	TP_ARGS(se, flags));

DECLARE_HOOK(android_vh_sched_stat_runtime_rt,
	TP_PROTO(struct task_struct *tsk, u64 delta),
	TP_ARGS(tsk, delta));

DECLARE_HOOK(android_vh_finish_update_load_avg_se,
	TP_PROTO(struct sched_entity *se, int flags),
	TP_ARGS(se, flags));

DECLARE_HOOK(android_vh_dup_task_struct,
	TP_PROTO(struct task_struct *tsk, struct task_struct *orig),
	TP_ARGS(tsk, orig));

DECLARE_RESTRICTED_HOOK(android_rvh_find_new_ilb,
	TP_PROTO(struct cpumask *nohz_idle_cpus_mask, int *ilb),
	TP_ARGS(nohz_idle_cpus_mask, ilb), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_force_compatible_pre,
	TP_PROTO(void *unused),
	TP_ARGS(unused), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_force_compatible_post,
	TP_PROTO(void *unused),
	TP_ARGS(unused), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_find_rtg_target,
	TP_PROTO(struct task_struct *p, struct cpumask **rtg_target),
	TP_ARGS(p, rtg_target), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_walt_cpu_high_irqload,
	TP_PROTO(int num, unsigned long *util),
	TP_ARGS(num, util), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_schedtune_prefer_idle,
	TP_PROTO(struct task_struct *p, unsigned long *util),
	TP_ARGS(p, util), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_is_reserved,
	TP_PROTO(int cpu, unsigned long *util),
	TP_ARGS(cpu, util), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_cpu_isolated,
	TP_PROTO(int cpu, int *util),
	TP_ARGS(cpu, util), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_capacity_curr_of,
	TP_PROTO(int cpu, unsigned long *util),
	TP_ARGS(cpu, util), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_is_min_capacity_cpu,
	TP_PROTO(int cpu, unsigned long *util),
	TP_ARGS(cpu, util), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_unisolated_cpu,
	TP_PROTO(struct rq *rq, int *util),
	TP_ARGS(rq, util), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_cpumask_andnot,
	TP_PROTO(struct cpumask *dstp,  const struct cpumask *src1p),
	TP_ARGS(dstp, src1p), 1);

DECLARE_HOOK(android_vh_setscheduler_uclamp,
	TP_PROTO(struct task_struct *tsk, int clamp_id, unsigned int value),
	TP_ARGS(tsk, clamp_id, value));

DECLARE_RESTRICTED_HOOK(android_rvh_sched_stat_yield_init,
	TP_PROTO(struct task_struct *p),
	TP_ARGS(p), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_sched_stat_yield_update,
	TP_PROTO(struct task_struct *p),
	TP_ARGS(p), 1);

DECLARE_HOOK(android_vh_corectl_check,
	TP_PROTO(int cpu, struct rq *rq),
	TP_ARGS(cpu, rq));

DECLARE_HOOK(android_vh_cpu_util_pred_min,
	TP_PROTO(struct rq *rq, unsigned long *util),
	TP_ARGS(rq, util));

DECLARE_RESTRICTED_HOOK(android_rvh_get_cluster_max_freq,
	TP_PROTO(int cpu, unsigned int *freq),
	TP_ARGS(cpu, freq), 1);

DECLARE_HOOK(android_vh_get_cpu_util,
	TP_PROTO(int cpu, unsigned long *util),
	TP_ARGS(cpu, util));

DECLARE_RESTRICTED_HOOK(android_rvh_get_wrq_window_start,
	TP_PROTO(struct rq *rq, u64 *freq),
	TP_ARGS(rq, freq), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_get_wts_mark_start,
	TP_PROTO(struct rq *rq, u64 *freq),
	TP_ARGS(rq, freq), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_get_wts_last_enqueued_ts,
	TP_PROTO(struct task_struct *p, u64 *time),
	TP_ARGS(p, time), 1);

DECLARE_HOOK(android_vh_max_pred_ls,
	TP_PROTO(struct rq *rq, unsigned long *util),
	TP_ARGS(rq, util));

DECLARE_HOOK(android_vh_predict_util,
	TP_PROTO(struct rq *rq, unsigned long *util),
	TP_ARGS(rq, util));

DECLARE_HOOK(android_vh_top_task_util,
	TP_PROTO(struct rq *rq, unsigned long *util),
	TP_ARGS(rq, util));

DECLARE_RESTRICTED_HOOK(android_rvh_walt_ktime_clock,
	TP_PROTO(u64 *wallclock),
	TP_ARGS(wallclock), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_walt_update_task_ravg,
	TP_PROTO(struct task_struct *p, struct rq *rq, int event, u64 wallclock, u64 irqtime),
	TP_ARGS(p, rq, event, wallclock, irqtime), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_get_top_task_skip_hispeed,
	TP_PROTO(bool *defined),
	TP_ARGS(defined), 1);

DECLARE_HOOK(android_vh_use_pelt_freq,
	TP_PROTO(bool *flag),
	TP_ARGS(flag));

DECLARE_HOOK(android_vh_sched_update_rtg_tick,
	TP_PROTO(struct rq *rq, unsigned int *old_load),
	TP_ARGS(rq, old_load));

DECLARE_RESTRICTED_HOOK(android_rvh_find_cas_cpu,
	TP_PROTO(struct sched_domain *sd, struct task_struct *task,
		 struct cpumask *lowest_mask, int ret, int *cpu),
	TP_ARGS(sd, task, lowest_mask, ret, cpu), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_sched_enable_rt_cas,
	TP_PROTO(unsigned int *enable_rt_cas),
	TP_ARGS(enable_rt_cas), 1);

DECLARE_HOOK(android_vh_check_for_rt_migration,
	TP_PROTO(struct rq *rq, struct task_struct *curr),
	TP_ARGS(rq, curr));

DECLARE_RESTRICTED_HOOK(android_rvh_hwrtg_fork_prio,
	TP_PROTO(struct task_struct *curr, struct task_struct *p),
	TP_ARGS(curr, p), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_proc_rtg_open,
	TP_PROTO(struct inode *inode, struct file *filp, int *ret),
	TP_ARGS(inode, filp, ret), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_proc_rtg_compat_ioctl,
	TP_PROTO(struct file *file, unsigned int cmd,
		 unsigned long arg, long *ret),
	TP_ARGS(file, cmd, arg, ret), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_proc_rtg_ioctl,
	TP_PROTO(struct file *file, unsigned int cmd,
		 unsigned long arg, long *ret),
	TP_ARGS(file, cmd, arg, ret), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_trans_rtg_sched_enqueue,
	TP_PROTO(struct task_struct *task, struct task_struct *from,
		 unsigned int type),
	TP_ARGS(task, from, type), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_trans_rtg_sched_dequeue,
	TP_PROTO(struct task_struct *task, unsigned int type),
	TP_ARGS(task, type), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_hwrtg_task_load,
	TP_PROTO(struct task_struct *curr, unsigned int *old_load),
	TP_ARGS(curr, old_load), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_is_key_aux_comm,
	TP_PROTO(const struct task_struct *task, const char *comm, bool *ret),
	TP_ARGS(task, comm, ret), 1);

#ifndef CONFIG_HW_AI_SCHED_QCOM_DDR_CONTROL
DECLARE_HOOK(android_vh_get_max_group_util,
	TP_PROTO(const struct cpumask *query_cpus, unsigned long *util,
		 unsigned int *freq),
	TP_ARGS(query_cpus, util, freq));
#else
struct ff_frame_info;
DECLARE_HOOK(android_vh_get_max_group_util,
	TP_PROTO(const struct cpumask *query_cpus, unsigned long *util,
		 unsigned int *freq, struct ff_frame_info *ff_info),
	TP_ARGS(query_cpus, util, freq, ff_info));
#endif

DECLARE_HOOK(android_vh_ravg_sum,
	TP_PROTO(struct seq_file *file, struct task_struct *task),
	TP_ARGS(file, task));

DECLARE_RESTRICTED_HOOK(android_rvh_sched_group_id_open,
	TP_PROTO(struct inode *inode, struct file *filp, int *ret),
	TP_ARGS(inode, filp, ret), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_sched_group_id_write,
	TP_PROTO(struct file *file, const char __user *buf, size_t count,
		loff_t *offset, ssize_t *ret),
	TP_ARGS(file, buf, count, offset, ret), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_init_new_task_load,
	TP_PROTO(struct task_struct *p),
	TP_ARGS(p), 1);

DECLARE_HOOK(android_vh_rt_task_fits_capacity,
	TP_PROTO(struct task_struct *p, unsigned int cpu, int *ret),
	TP_ARGS(p, cpu, ret));

DECLARE_HOOK(android_vh_sched_pelt_multiplier,
	TP_PROTO(unsigned int old, unsigned int cur, int *ret),
	TP_ARGS(old, cur, ret));
/* macro versions of hooks are no longer required */

#endif /* _TRACE_HOOK_SCHED_H */
/* This part must be outside protection */
#include <trace/define_trace.h>
