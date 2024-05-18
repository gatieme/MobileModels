/* SPDX-License-Identifier: GPL-2.0 */
#undef TRACE_SYSTEM
#define TRACE_SYSTEM sched
#define TRACE_INCLUDE_PATH trace/hooks
#if !defined(_TRACE_HOOK_SCHED_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_HOOK_SCHED_H
#include <trace/hooks/vendor_hooks.h>
/*
 * Following tracepoints are not exported in tracefs and provide a
 * mechanism for vendor modules to hook and extend functionality
 */
#ifdef __GENKSYMS__
/* needed for KMI stability */
#include <../kernel/cgroup/cgroup-internal.h>
#endif

DECLARE_RESTRICTED_HOOK(android_rvh_select_task_rq_fair,
	TP_PROTO(struct task_struct *p, int prev_cpu, int sd_flag, int wake_flags, int *new_cpu),
	TP_ARGS(p, prev_cpu, sd_flag, wake_flags, new_cpu), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_select_task_rq_rt,
	TP_PROTO(struct task_struct *p, int prev_cpu, int sd_flag, int wake_flags, int *new_cpu),
	TP_ARGS(p, prev_cpu, sd_flag, wake_flags, new_cpu), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_select_task_rq_dl,
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

DECLARE_RESTRICTED_HOOK(android_rvh_rto_next_cpu,
	TP_PROTO(int rto_cpu, struct cpumask *rto_mask, int *cpu),
	TP_ARGS(rto_cpu, rto_mask, cpu), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_is_cpu_allowed,
	TP_PROTO(struct task_struct *p, int cpu, bool *allowed),
	TP_ARGS(p, cpu, allowed), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_get_nohz_timer_target,
	TP_PROTO(int *cpu, bool *done),
	TP_ARGS(cpu, done), 1);

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

DECLARE_RESTRICTED_HOOK(android_rvh_find_energy_efficient_cpu,
	TP_PROTO(struct task_struct *p, int prev_cpu, int sync, int *new_cpu),
	TP_ARGS(p, prev_cpu, sync, new_cpu), 1);

DECLARE_HOOK(android_vh_set_sugov_sched_attr,
	TP_PROTO(struct sched_attr *attr),
	TP_ARGS(attr));

DECLARE_RESTRICTED_HOOK(android_rvh_set_iowait,
	TP_PROTO(struct task_struct *p, struct rq *rq, int *should_iowait_boost),
	TP_ARGS(p, rq, should_iowait_boost), 1);

struct sugov_policy;
DECLARE_RESTRICTED_HOOK(android_rvh_set_sugov_update,
	TP_PROTO(struct sugov_policy *sg_policy, unsigned int next_freq, bool *should_update),
	TP_ARGS(sg_policy, next_freq, should_update), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_cpu_overutilized,
	TP_PROTO(int cpu, int *overutilized),
	TP_ARGS(cpu, overutilized), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_sched_setaffinity,
	TP_PROTO(struct task_struct *p, const struct cpumask *in_mask, int *retval),
	TP_ARGS(p, in_mask, retval), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_sched_getaffinity,
	TP_PROTO(struct task_struct *p, struct cpumask *in_mask),
	TP_ARGS(p, in_mask), 1);

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

DECLARE_RESTRICTED_HOOK(android_rvh_account_irq_start,
	TP_PROTO(struct task_struct *curr, int cpu, s64 delta),
	TP_ARGS(curr, cpu, delta), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_account_irq_end,
	TP_PROTO(struct task_struct *curr, int cpu, s64 delta),
	TP_ARGS(curr, cpu, delta), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_place_entity,
	TP_PROTO(struct cfs_rq *cfs_rq, struct sched_entity *se, int initial, u64 *vruntime),
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

DECLARE_RESTRICTED_HOOK(android_rvh_sched_fork_init,
	TP_PROTO(struct task_struct *p),
	TP_ARGS(p), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_ttwu_cond,
	TP_PROTO(int cpu, bool *cond),
	TP_ARGS(cpu, cond), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_schedule_bug,
	TP_PROTO(void *unused),
	TP_ARGS(unused), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_sched_exec,
	TP_PROTO(bool *cond),
	TP_ARGS(cond), 1);

DECLARE_HOOK(android_vh_map_util_freq,
	TP_PROTO(unsigned long util, unsigned long freq,
		unsigned long cap, unsigned long *next_freq),
	TP_ARGS(util, freq, cap, next_freq));

struct cpufreq_policy;
DECLARE_HOOK(android_vh_map_util_freq_new,
	TP_PROTO(unsigned long util, unsigned long freq,
		unsigned long cap, unsigned long *next_freq, struct cpufreq_policy *policy,
		bool *need_freq_update),
	TP_ARGS(util, freq, cap, next_freq, policy, need_freq_update));

DECLARE_HOOK(android_vh_em_cpu_energy,
	TP_PROTO(struct em_perf_domain *pd,
		unsigned long max_util, unsigned long sum_util,
		unsigned long *energy),
	TP_ARGS(pd, max_util, sum_util, energy));

DECLARE_HOOK(android_vh_build_sched_domains,
	TP_PROTO(bool has_asym),
	TP_ARGS(has_asym));

DECLARE_RESTRICTED_HOOK(android_rvh_check_preempt_tick,
	TP_PROTO(struct task_struct *p, unsigned long *ideal_runtime, bool *skip_preempt,
			unsigned long delta_exec, struct cfs_rq *cfs_rq, struct sched_entity *curr,
			unsigned int granularity),
	TP_ARGS(p, ideal_runtime, skip_preempt, delta_exec, cfs_rq, curr, granularity), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_check_preempt_wakeup_ignore,
	TP_PROTO(struct task_struct *p, bool *ignore),
	TP_ARGS(p, ignore), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_replace_next_task_fair,
	TP_PROTO(struct rq *rq, struct task_struct **p, struct sched_entity **se, bool *repick,
			bool simple, struct task_struct *prev),
	TP_ARGS(rq, p, se, repick, simple, prev), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_sched_balance_rt,
	TP_PROTO(struct rq *rq, struct task_struct *p, int *done),
	TP_ARGS(rq, p, done), 1);

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

DECLARE_RESTRICTED_HOOK(android_rvh_set_cpus_allowed_ptr_locked,
	TP_PROTO(const struct cpumask *cpu_valid_mask, const struct cpumask *new_mask,
		 unsigned int *dest_cpu),
	TP_ARGS(cpu_valid_mask, new_mask, dest_cpu), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_set_cpus_allowed_by_task,
	TP_PROTO(const struct cpumask *cpu_valid_mask, const struct cpumask *new_mask,
		 struct task_struct *p, unsigned int *dest_cpu),
	TP_ARGS(cpu_valid_mask, new_mask, p, dest_cpu), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_do_sched_yield,
	TP_PROTO(struct rq *rq),
	TP_ARGS(rq), 1);

DECLARE_HOOK(android_vh_free_task,
	TP_PROTO(struct task_struct *p),
	TP_ARGS(p));

DECLARE_HOOK(android_vh_irqtime_account_process_tick,
	TP_PROTO(struct task_struct *p, struct rq *rq, int user_tick, int ticks),
	TP_ARGS(p, rq, user_tick, ticks));

DECLARE_HOOK(android_vh_sched_pelt_multiplier,
	TP_PROTO(unsigned int old, unsigned int cur, int *ret),
	TP_ARGS(old, cur, ret));

/* Conditionally defined upon CONFIG_UCLAMP_TASK */
struct uclamp_se;
DECLARE_RESTRICTED_HOOK(android_rvh_uclamp_eff_get,
	TP_PROTO(struct task_struct *p, enum uclamp_id clamp_id,
		 struct uclamp_se *uclamp_max, struct uclamp_se *uclamp_eff, int *ret),
	TP_ARGS(p, clamp_id, uclamp_max, uclamp_eff, ret), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_after_enqueue_task,
	TP_PROTO(struct rq *rq, struct task_struct *p, int flags),
	TP_ARGS(rq, p, flags), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_after_dequeue_task,
	TP_PROTO(struct rq *rq, struct task_struct *p, int flags),
	TP_ARGS(rq, p, flags), 1);

struct cfs_rq;
struct rq_flags;
DECLARE_RESTRICTED_HOOK(android_rvh_enqueue_entity,
	TP_PROTO(struct cfs_rq *cfs, struct sched_entity *se),
	TP_ARGS(cfs, se), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_dequeue_entity,
	TP_PROTO(struct cfs_rq *cfs, struct sched_entity *se),
	TP_ARGS(cfs, se), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_entity_tick,
	TP_PROTO(struct cfs_rq *cfs_rq, struct sched_entity *se),
	TP_ARGS(cfs_rq, se), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_enqueue_task_fair,
	TP_PROTO(struct rq *rq, struct task_struct *p, int flags),
	TP_ARGS(rq, p, flags), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_dequeue_task_fair,
	TP_PROTO(struct rq *rq, struct task_struct *p, int flags),
	TP_ARGS(rq, p, flags), 1);

DECLARE_HOOK(android_vh_em_dev_register_pd,
	TP_PROTO(bool *cond),
	TP_ARGS(cond));

DECLARE_HOOK(android_vh_sched_stat_runtime_rt,
	TP_PROTO(struct task_struct *tsk, u64 delta),
	TP_ARGS(tsk, delta));

DECLARE_RESTRICTED_HOOK(android_rvh_post_init_entity_util_avg,
	TP_PROTO(struct sched_entity *se),
	TP_ARGS(se), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_find_new_ilb,
	TP_PROTO(struct cpumask *nohz_idle_cpus_mask, int *ilb),
	TP_ARGS(nohz_idle_cpus_mask, ilb), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_util_est_update,
	TP_PROTO(struct cfs_rq *cfs_rq, struct task_struct *p, bool task_sleep, int *ret),
	TP_ARGS(cfs_rq, p, task_sleep, ret), 1);

DECLARE_HOOK(android_vh_setscheduler_uclamp,
	TP_PROTO(struct task_struct *tsk, int clamp_id, unsigned int value),
	TP_ARGS(tsk, clamp_id, value));

DECLARE_HOOK(android_vh_do_wake_up_sync,
	TP_PROTO(struct wait_queue_head *wq_head, int *done),
	TP_ARGS(wq_head, done));

DECLARE_HOOK(android_vh_set_wake_flags,
	TP_PROTO(int *wake_flags, unsigned int *mode),
	TP_ARGS(wake_flags, mode));

DECLARE_RESTRICTED_HOOK(android_rvh_effective_cpu_util,
	TP_PROTO(int cpu, unsigned long util_cfs, unsigned long max, int type,
		 struct task_struct *p, unsigned long *new_util),
	TP_ARGS(cpu, util_cfs, max, type, p, new_util), 1);

DECLARE_HOOK(android_vh_force_compatible_pre,
	TP_PROTO(void *unused),
	TP_ARGS(unused));

DECLARE_HOOK(android_vh_force_compatible_post,
	TP_PROTO(void *unused),
	TP_ARGS(unused));

DECLARE_HOOK(android_vh_dup_task_struct,
	TP_PROTO(struct task_struct *tsk, struct task_struct *orig),
	TP_ARGS(tsk, orig));

DECLARE_HOOK(android_vh_account_task_time,
	TP_PROTO(struct task_struct *p, struct rq *rq, int user_tick),
	TP_ARGS(p, rq, user_tick));

#ifdef CONFIG_HONOR_RTG
DECLARE_RESTRICTED_HOOK(android_rvh_sched_set_group_id,
	TP_PROTO(struct task_struct *p, unsigned int group_id, int *ret),
	TP_ARGS(p, group_id, ret), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_sched_get_rtg_group_thread_num,
	TP_PROTO(unsigned int group_id, int *ret),
	TP_ARGS(group_id, ret), 1);

#ifdef CONFIG_HONOR_RTG_DEBUG
DECLARE_RESTRICTED_HOOK(android_rvh_sched_get_rtg_group_debug_info,
	TP_PROTO(unsigned int group_id, struct seq_file *sfile, int *ret),
	TP_ARGS(group_id, sfile, ret), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_sched_get_all_rtg_groups_info,
	TP_PROTO(struct seq_file *sfile, int *ret),
	TP_ARGS(sfile, ret), 1);
#endif
#endif

#ifdef CONFIG_HONOR_RT_ACTIVE_LB
DECLARE_RESTRICTED_HOOK(android_rvh_sched_honor_capacity_curr_of,
	TP_PROTO(unsigned int cpu, unsigned long *ret),
	TP_ARGS(cpu, ret), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_sched_honor_capacity_of,
	TP_PROTO(unsigned int cpu, unsigned long *ret),
	TP_ARGS(cpu, ret), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_sched_honor_uclamp_task_util,
	TP_PROTO(struct task_struct *task, unsigned long *ret),
	TP_ARGS(task, ret), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_sched_honor_task_fits_capacity,
	TP_PROTO(struct task_struct *task, long capacity, int cpu, bool *ret),
	TP_ARGS(task, capacity, cpu, ret), 1);
#endif

#ifdef CONFIG_HN_QOS_THREAD
DECLARE_RESTRICTED_HOOK(android_rvh_sched_get_group_id,
	TP_PROTO(struct task_struct *p, int *ret),
	TP_ARGS(p, ret), 1);
#endif

#ifdef CONFIG_HN_VIP_THREAD_BUILDIN
DECLARE_RESTRICTED_HOOK(android_rvh_honor_static_vip_set,
	TP_PROTO(struct task_struct *p, unsigned int val, int *ret),
	TP_ARGS(p, val, ret), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_honor_check_task_static_vip,
	TP_PROTO(struct task_struct *p, int *ret),
	TP_ARGS(p, ret), 1);
#endif

#ifdef CONFIG_HN_VIP_TO_TA_BUILDIN
DECLARE_HOOK(android_vh_honor_check_vip_status,
TP_PROTO(int cur_pid, int cur_tgid, struct task_struct* task, int* ret),
TP_ARGS(cur_pid, cur_tgid, task, ret));
#endif

#ifdef CONFIG_HN_SCHED_TRACE_ENHANCEMENT
DECLARE_RESTRICTED_HOOK(android_rvh_walt_task_util,
TP_PROTO(struct task_struct *p, unsigned long *ret),
TP_ARGS(p, ret), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_walt_uclamp_task_util,
TP_PROTO(struct task_struct *p, unsigned long *ret),
TP_ARGS(p, ret), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_hn_get_task_tags,
TP_PROTO(struct task_struct *p, unsigned long long *ret),
TP_ARGS(p, ret), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_hn_get_task_rsum,
TP_PROTO(struct task_struct *p, unsigned long long *ret),
TP_ARGS(p, ret), 1);
#endif

DECLARE_RESTRICTED_HOOK(android_rvh_set_cpus_allowed_comm,
	TP_PROTO(struct task_struct *p, const struct cpumask *new_mask),
	TP_ARGS(p, new_mask), 1);

DECLARE_HOOK(android_vh_sched_setaffinity_early,
	TP_PROTO(struct task_struct *p, const struct cpumask *new_mask, int *retval),
	TP_ARGS(p, new_mask, retval));

#ifdef CONFIG_HONOR_RTG_KEY_LIST
DECLARE_HOOK(android_vh_honor_task_rename,
	TP_PROTO(struct task_struct *p, const char *comm),
	TP_ARGS(p, comm));
#endif

DECLARE_RESTRICTED_HOOK(android_rvh_attach_entity_load_avg,
	TP_PROTO(struct cfs_rq *cfs_rq, struct sched_entity *se),
	TP_ARGS(cfs_rq, se), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_detach_entity_load_avg,
	TP_PROTO(struct cfs_rq *cfs_rq, struct sched_entity *se),
	TP_ARGS(cfs_rq, se), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_update_load_avg,
	TP_PROTO(u64 now, struct cfs_rq *cfs_rq, struct sched_entity *se),
	TP_ARGS(now, cfs_rq, se), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_remove_entity_load_avg,
	TP_PROTO(struct cfs_rq *cfs_rq, struct sched_entity *se),
	TP_ARGS(cfs_rq, se), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_update_blocked_fair,
	TP_PROTO(struct rq *rq),
	TP_ARGS(rq), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_update_rt_rq_load_avg,
	TP_PROTO(u64 now, struct rq *rq, struct task_struct *tsk, int running),
	TP_ARGS(now, rq, tsk, running), 1);

DECLARE_HOOK(android_vh_mmput,
	TP_PROTO(struct mm_struct *mm),
	TP_ARGS(mm));
/* macro versions of hooks are no longer required */

#endif /* _TRACE_HOOK_SCHED_H */
/* This part must be outside protection */
#include <trace/define_trace.h>
