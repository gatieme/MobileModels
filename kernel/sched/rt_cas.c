// SPDX-License-Identifier: GPL-2.0
/*
 * rt_cas.c
 *
 * RT capacity-aware scheduling enhancement
 *
 * Copyright (c) 2021-2021 Huawei Technologies Co., Ltd.
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

#include "sched.h"
#include <trace/events/sched.h>

unsigned int __read_mostly sysctl_sched_enable_rt_cas = 1;

s64 task_delay(struct task_struct *p, struct rq *rq)
{
	u64 lq = p->sched_info.last_queued;

	/*
	 * The double_lock_balance() in push_rt_task() may drop and
	 * reacquire rq lock.
	 */
	if (unlikely(!(rq->clock_update_flags & RQCF_UPDATED)))
		update_rq_clock(rq);

	return lq ? rq_clock(rq) - lq : 0;
}

/*
 * Get available ones before checking prio and util. The checkings in
 * rt_energy_aware_wake_cpu() for-loop are ordered, importantly. This
 * function is about dropping the non-negotiable forbidden cpus.
 *
 * Note that we don't need to check a reserved flag to prevent two misfit
 * running tasks migrating to the same cpu. The push_rt_tasks() will help.
 */
static void get_avail_cpus(struct cpumask *cpus, struct task_struct *p)
{
	int i;

	if (cpumask_empty(cpus))
		return;

	cpumask_and(cpus, cpus, p->cpus_ptr);
	cpumask_and(cpus, cpus, cpu_online_mask);
#ifdef CONFIG_CPU_ISOLATION_OPT
	cpumask_andnot(cpus, cpus, cpu_isolated_mask);
#endif

	for_each_cpu(i, cpus) {
		if (walt_cpu_high_irqload(i))
			goto delete;
		if (cpu_may_not_preemptible(i))
			goto delete;
#ifdef CONFIG_SCHED_SMT_EXPELLING
		if (cpu_should_thread_off(i))
			goto delete;
#endif

		continue;
delete:
		cpumask_clear_cpu(i, cpus);
	}
}

static unsigned long cpu_util_for_rt_pick(int cpu, struct task_struct *p)
{
	struct rq *rq = cpu_rq(cpu);

	if (rq->rt.rt_nr_total == 1 &&
	    rt_task(rq->curr) &&
	    rq->curr != p)
		return task_util(rq->curr);

	return cpu_util_without(cpu, p);
}

static unsigned long sched_core_max_util(int cpu, struct task_struct *p)
{
#ifdef CONFIG_SCHED_SMT
	/* !cookie_match implies rq->is_smt. */
	if (!sched_core_cookie_match(cpu_rq(cpu), p))
		return max(cpu_util_for_rt_pick(cpu, p),
			cpu_util_for_rt_pick(cpu_rq(cpu)->smt_sibling, p));
#endif
	return cpu_util_for_rt_pick(cpu, p);
}

/*
 * 32=256/8, that means we can allow a little bit more than 1/8 util
 * for opp lower than middle core low freq. For example, 1/4 util at
 * little core mid freq (~1.0G) can be treated light loaded.
 */
#define VERY_LOW_UTIL 32UL

static bool cpu_light_loaded(int cpu, struct task_struct *p)
{
	unsigned long util = sched_core_max_util(cpu, p);

	/* <12.8% loaded. */
	if (util < capacity_curr_of(cpu) / 8)
		return true;

	/*
	 * May still need to be energy efficient if p can be placed on
	 * little core. We can tolerate more than cap_curr/8 if it still
	 * looks low utilized.
	 */
	if (util < VERY_LOW_UTIL)
		return true;

	return false;
}

static int sched_core_rt_highest_prio(struct rq *rq, struct task_struct *p)
{
#ifdef CONFIG_SCHED_SMT
	/* !cookie_match implies rq->is_smt. */
	if (!sched_core_cookie_match(rq, p))
		return min(rq->rt.highest_prio.curr,
			cpu_rq(rq->smt_sibling)->rt.highest_prio.curr);
#endif
	return rq->rt.highest_prio.curr;
}

#define SPREAD_DELAYED_RT_NS (4 * NSEC_PER_MSEC)

static void get_lowest_pri_cpus(struct cpumask *cpus, struct task_struct *p)
{
	int i;
	cpumask_t lowest_cpus = CPU_MASK_NONE;
	int lowest_prio = 0;
	bool delayed = false;

	if (cpumask_empty(cpus))
		return;

	delayed = this_cpu_read(check_delayed_task) &&
		  task_delay(p, cpu_rq(smp_processor_id())) > SPREAD_DELAYED_RT_NS;

	for_each_cpu(i, cpus) {
		struct rq *rq = cpu_rq(i);
		int prio = sched_core_rt_highest_prio(rq, p);

		/*
		 * P can preempt.
		 * Non-energy_efficient rt tasks always want preemptible cpus
		 * if possible.
		 * This check is not correct when we are migrating running
		 * task but we do not really want to take the current cpu into
		 * consideration. Besides, the new cpu for running task will
		 * be checked by the caller.
		 */
		if (p->prio < prio)
			goto pick;

#ifdef CONFIG_RT_ENERGY_EFFICIENT_SUPPORT
		/*
		 * P must wait if placed on that cpu.
		 * In energy efficient case, we can tolerate a little bit delay.
		 */
		if (test_tsk_thread_flag(p, TIF_ENERGY_EFFICIENT) &&
		    cpu_light_loaded(i, p)) {
			if (p->state == TASK_WAKING)
				goto pick;

			if (p->state == TASK_RUNNING &&
			    i == task_cpu(p) &&
			    !delayed)
				goto pick;
		}
#endif

		/* Not a suitable cpu. */
		continue;
pick:
		if (prio > lowest_prio) {
			lowest_prio = prio;
			cpumask_clear(&lowest_cpus);
			cpumask_set_cpu(i, &lowest_cpus);
		} else if (prio == lowest_prio) {
			cpumask_set_cpu(i, &lowest_cpus);
		}
	}

	cpumask_copy(cpus, &lowest_cpus);
}

/*
 * Now find better candidates in cpus with same rt pri in the same cluster.
 * Why prefer max spare cap?
 * spare_cap(i) = capacity_of(i) - cpu_util(i)
 *              = core_cap(i) - cpu_util(sibling) - cpu_util(i)
 * If p fit cpus, max spare cap cpu hurt others less.
 * If p misfit, probably max capcity_of is preffered. But in fact, sibling
 * cpu won't enter idle when it finishes cpu_util(sibling). At least it will
 * pull loads from this cpu. In this perspective we still prefer max spare_cap.
 */
static void get_max_spare_cap_cpus(struct cpumask *cpus, struct task_struct *p)
{
	int i;
	long max_spare = LONG_MIN;
	unsigned int min_exit_lat = UINT_MAX;
	cpumask_t best_cpus = CPU_MASK_NONE;
	bool task_is_smt_expeller = task_expeller_type(p) > 0;

	if (cpumask_weight(cpus) <= 1)
		return;

	for_each_cpu(i, cpus) {
		struct cpuidle_state *idle = idle_get_state(cpu_rq(i));
		unsigned int exit_lat = idle ? idle->exit_latency : 0;
		long cap = task_is_smt_expeller ? capacity_orig_of(i)
						: capacity_of(i);
		long spare_cap = max(cap - cpu_util_without(i, p), 0L);

		/*
		 * No spare cap left. Let the one with more tasks have
		 * less spare cap. That prevents rt tasks to cumulate
		 * on lower cpu ids and helps to stay away from an
		 * unbalanced cpu due to cpuset.
		 */
		if (spare_cap == 0)
			spare_cap -= cpu_rq(i)->rt.rt_nr_total;

		if (spare_cap > max_spare ||
		    (spare_cap == max_spare && exit_lat < min_exit_lat)) {
			max_spare = spare_cap;
			min_exit_lat = exit_lat;
			cpumask_clear(&best_cpus);
			cpumask_set_cpu(i, &best_cpus);
		} else if (spare_cap == max_spare && exit_lat == min_exit_lat) {
			cpumask_set_cpu(i, &best_cpus);
		}
	}

	cpumask_copy(cpus, &best_cpus);
}

static void honor_prev_cpu(struct cpumask *cpus, struct task_struct *p)
{
	if (cpumask_test_cpu(task_cpu(p), cpus)) {
		cpumask_clear(cpus);
		cpumask_set_cpu(task_cpu(p), cpus);
	}
}

static bool need_bypass_pushing_up(struct task_struct *p, unsigned long cap)
{
#ifdef CONFIG_SCHED_VIP_FALLBACK_WORKAROUND
#ifdef CONFIG_SCHED_RUNNING_AVG
	bool is_misfit_task = p->heavy_task;
#else
	bool is_misfit_task = !task_fit_cpu(p, task_cpu(p));
#endif
	/*
	 * Do not push a runnable and energy-efficient task up to bigger cpu
	 * imediately when preempted by higher prio rt.
	 * P would either:
	 * 1. Be pushed to the same or smaller cap cpus if p can preempt.
	 * 2. Wait for running or pulling or pushing in tick.
	 *
	 * Similar policy should (but not already) be implemented when p is
	 * waking up.
	 * But vip sched are not designed to act like that, even for runnable
	 * tasks. We may take a more complex approach in the future to improve
	 * energy efficiency. Definitely not this way.
	 * Now do what the old vip sched did as a workaround to silence
	 * some comparisions.
	 *
	 * Note that considering each ways calling us:
	 * 1. Waking.
	 * 2. Higher prio rt preempt and push.
	 * 3. Checking migrating misfit running task in tick.
	 * 4. Doing migrating misfit task by stopper raised by 3.
	 * 5. Migrating delayed runnable tasks in tick.
	 * The below checks will hit 2.
	 */
	return test_tsk_thread_flag(p, TIF_ENERGY_EFFICIENT) &&
	       cap > capacity_orig_of(task_cpu(p)) &&
	       p->state == TASK_RUNNING &&
	       !is_misfit_task &&
	       !this_cpu_read(check_delayed_task);
#else
	return false;
#endif
}

#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
#define uclamp_boosted(p) (schedtune_task_boost(p) > 0)
#endif

int rt_energy_aware_wake_cpu(struct task_struct *p)
{
	struct sched_cluster *cluster = NULL;
	int cpu;
	int best_cpu = -1;
	unsigned long best_capacity;
	bool check_cap = true;
	bool boosted = false;
	cpumask_t fit_cpus;

	if (unlikely(!sysctl_sched_enable_rt_cas))
		return -1;

	boosted = global_boost_enable && uclamp_boosted(p);
#ifdef CONFIG_RT_ENERGY_EFFICIENT_SUPPORT
	boosted = boosted && test_tsk_thread_flag(p, TIF_EXPECTED_HEAVY);
#endif

	get_task_fit_cpus(p, &fit_cpus);

	/* For idle_get_state() and visiting rq->curr. */
	rcu_read_lock();
retry:
	best_capacity = boosted ? 0 : ULONG_MAX;

	for_each_sched_cluster(cluster) {
		int fcpu = cpumask_first(&cluster->cpus);
		unsigned long capacity_orig = capacity_orig_of(fcpu);
		cpumask_t candidate_cpus;

		if ((boosted && capacity_orig < best_capacity) ||
		    (!boosted && capacity_orig > best_capacity))
			continue;

		if (need_bypass_pushing_up(p, capacity_orig))
			continue;

		if (check_cap)
			cpumask_and(&candidate_cpus, &cluster->cpus, &fit_cpus);
		else
			cpumask_andnot(&candidate_cpus, &cluster->cpus, &fit_cpus);

		get_avail_cpus(&candidate_cpus, p);
		get_lowest_pri_cpus(&candidate_cpus, p);
		get_max_spare_cap_cpus(&candidate_cpus, p);
		honor_prev_cpu(&candidate_cpus, p);

		cpu = cpumask_first(&candidate_cpus);
		if (cpu < nr_cpu_ids) {
			best_cpu = cpu;
			best_capacity = capacity_orig;
		}
	}

	if (best_cpu == -1 && check_cap) {
		/* Find max possible one in the left misfit cpus. */
		check_cap = false;
		boosted = true;
		goto retry;
	}

	rcu_read_unlock();
	trace_perf(rt_energy_aware_wake_cpu, p, boosted, check_cap, best_cpu);
	return best_cpu;
}

#ifdef CONFIG_RT_ENERGY_EFFICIENT_SUPPORT
bool is_energy_efficient_migration(struct rq *src_rq, struct rq *dst_rq)
{
	int src_cpu = cpu_of(src_rq), dst_cpu = cpu_of(dst_rq);

	/* Don't care about energy efficiency and let fast cpus to pull. */
	if (global_boost_enable && test_fast_cpu(dst_cpu))
		return true;

	/*
	 * Don't pull task between slow and fast cpus.
	 * It might harm performance if pulled from fast to slow. There
	 * could be a chance of scheduling later in fast cpus.
	 * And it will harm power efficiency if pulled from slow to fast.
	 * If there are really many tasks waiting, we don't want the
	 * pull logic to help but the wakeup logic. It's a little bit
	 * like the newidle_balance() logic in cfs when app start.
	 */
	return (test_slow_cpu(src_cpu) && test_slow_cpu(dst_cpu)) ||
	       (test_fast_cpu(src_cpu) && test_fast_cpu(dst_cpu));
}

/*
 * NOTE: users must call mark_rt_heavy() (if needed) **after**
 * sched_setscheduler*(). See __setscheduler()->dynamic_prio_clear().
 */
void mark_rt_heavy(struct task_struct *p)
{
	set_tsk_thread_flag(p, TIF_EXPECTED_HEAVY);
}

void clear_rt_heavy(struct task_struct *p)
{
	clear_tsk_thread_flag(p, TIF_EXPECTED_HEAVY);
}
#endif

void init_rt_cas_flags(struct task_struct *p)
{
#ifdef CONFIG_RT_ENERGY_EFFICIENT_SUPPORT
	clear_tsk_thread_flag(p, TIF_ENERGY_EFFICIENT);
	clear_tsk_thread_flag(p, TIF_EXPECTED_HEAVY);
#endif
#ifdef CONFIG_RT_PRIO_EXTEND_VIP
	clear_tsk_thread_flag(p, TIF_NO_EXTEND);
#endif
#ifdef CONFIG_SCHED_DYNAMIC_PRIO
	clear_tsk_thread_flag(p, TIF_DYN_PRIO);
#endif
#ifdef CONFIG_RT_SOFTINT_OPTIMIZATION
	clear_tsk_thread_flag(p, TIF_LONG_NONPREEMPTIBLE);
#endif
}

static int rt_active_load_balance_cpu_stop(void *data)
{
	struct rq *rq = data;

	raw_spin_rq_lock_irq(rq);
	rq->active_balance = 0;
	raw_spin_rq_unlock_irq(rq);

	return 0;
}

/* Define a new callback_head for fewer changes in rt.c. */
static DEFINE_PER_CPU(struct callback_head, rt_push_head);
static DEFINE_PER_CPU(struct cpu_stop_work, active_balance_work);
DEFINE_PER_CPU(bool, check_delayed_task);

/*
 * Called from scheduler_tick() with rq_lock.
 * Both check for the current and the runnable ones.
 */
void check_for_rt_migration(struct rq *rq, struct task_struct *curr)
{
	int cpu = cpu_of(rq);
	bool misfit = false;

	if (curr->sched_class != &rt_sched_class)
		return;

	if (unlikely(!sysctl_sched_enable_rt_cas))
		return;

	lockdep_assert_rq_held(rq);

	misfit = !task_fit_cpu(curr, cpu);

#ifdef CONFIG_SCHED_RUNNING_AVG
	update_nr_heavy_running(rq, curr, misfit);
#endif

#ifdef CONFIG_RT_SWITCH_CFS_IF_TOO_LONG
	if (check_long_rt(curr))
		return;
#endif

	if (misfit && !need_resched()) {
		/*
		 * Migrate misfit running task.
		 * Check if it is possible to prevent unnecessary scheduling.
		 */
		int new_cpu = rt_energy_aware_wake_cpu(curr);

		if (new_cpu >= 0 &&
#ifdef CONFIG_SCHED_SMT
		    higher_cpu_capacity(new_cpu, cpu) &&
#else
		    capacity_orig_of(new_cpu) > capacity_orig_of(cpu) &&
#endif
		    curr->prio < cpu_rq(new_cpu)->rt.highest_prio.curr &&
		    !rq->active_balance) {
			rq->active_balance = 1;
			/*
			 * To make it simple, we raise an empty stop task to
			 * make the curr rt task runnable and call the push
			 * function after next schedule().
			 * Stop task appears like a SCHED_FIFO task with
			 * highest priority. The only thing we need to take
			 * care is rq->rt.overloaded in push_rt_task().
			 */
			queue_balance_callback(rq, &per_cpu(rt_push_head, cpu),
					       push_rt_tasks);

			raw_spin_rq_unlock(rq);
			stop_one_cpu_nowait(cpu, rt_active_load_balance_cpu_stop,
					    rq, &per_cpu(active_balance_work, cpu));
			raw_spin_rq_lock(rq);

			/* Refactoring on the way. */
			if (unlikely(!(rq->clock_update_flags & RQCF_UPDATED)))
				update_rq_clock(rq);
			return;
		}
	}

#ifdef CONFIG_VIP_RAISE_BINDED_KTHREAD
	check_delayed_kthread(rq);
#endif

	/*
	 * Always try pushing the runnable tasks at each scheduler_tick()
	 * in case they haven't got chances of pulling or pushing for a
	 * long time.
	 * In order to access rq_clock in the easiest way, denote the path
	 * with a this cpu var.
	 */
	__this_cpu_write(check_delayed_task, true);
	push_rt_tasks(rq);
	__this_cpu_write(check_delayed_task, false);

	/*
	 * The double_lock_balance() in push_rt_task() may drop and
	 * reacquire rq lock. Do not break following rq_lock() users.
	 */
	if (unlikely(!(rq->clock_update_flags & RQCF_UPDATED)))
		update_rq_clock(rq);
}
