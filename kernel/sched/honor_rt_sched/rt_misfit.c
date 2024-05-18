// SPDX-License-Identifier: GPL-2.0
/*
 * Real-Time Scheduling Class (mapped to the SCHED_FIFO and SCHED_RR
 * policies)
 */

#ifdef CONFIG_HONOR_RT_ACTIVE_LB


#ifdef CONFIG_HONOR_RTG
#include <linux/sched/honor_rtg_sched/rtg_sched.h>

unsigned int sysctl_sched_enable_rt_active_lb = 1;
#else
unsigned int sysctl_sched_enable_rt_active_lb = 0;
#endif

#include <trace/hooks/sched.h>

static int rt_active_load_balance_cpu_stop(void *data)
{
	struct rq *busiest_rq = data;
	struct task_struct *next_task = busiest_rq->rt_push_task;
	struct rq *lowest_rq = NULL;
	unsigned long flags;

	raw_spin_lock_irqsave(&busiest_rq->__lock, flags);
	busiest_rq->rt_active_balance = 0;

	if (next_task->nr_cpus_allowed == 1 || is_migration_disabled(next_task))
		goto out;

	/* find_lock_lowest_rq locks the rq if found */
	lowest_rq = find_lock_lowest_rq(next_task, busiest_rq);
	if (!lowest_rq)
		goto out;

	if (capacity_orig_of(cpu_of(lowest_rq)) <= capacity_orig_of(task_cpu(next_task)))
		goto unlock;

	deactivate_task(busiest_rq, next_task, 0);
	set_task_cpu(next_task, lowest_rq->cpu);
	activate_task(lowest_rq, next_task, 0);

	resched_curr(lowest_rq);

unlock:
	double_unlock_balance(busiest_rq, lowest_rq);

out:
	put_task_struct(next_task);
	raw_spin_unlock_irqrestore(&busiest_rq->__lock, flags);

	return 0;
}

unsigned long honor_capacity_curr_of(unsigned int cpu)
{
	unsigned long ret;
	trace_android_rvh_sched_honor_capacity_curr_of(cpu, &ret);
	return ret;
}

unsigned long honor_capacity_orig_of(int cpu)
{
	return capacity_orig_of(cpu);
}

unsigned long honor_capacity_of(unsigned int cpu)
{
	unsigned long ret;
	trace_android_rvh_sched_honor_capacity_of(cpu, &ret);
	return ret;
}

unsigned long honor_uclamp_task_util(struct task_struct *task)
{
	unsigned long ret;
	trace_android_rvh_sched_honor_uclamp_task_util(task, &ret);
	return ret;
}

void check_for_rt_migration(struct rq *rq, struct task_struct *p)
{
	bool need_actvie_lb = false;
	bool misfit_task = false;
	int cpu = task_cpu(p);
	unsigned long cpu_orig_cap;
#ifdef CONFIG_HONOR_RTG_NORMALIZED_UTIL
	struct cpumask *rtg_target = NULL;
#endif

	if (!sysctl_sched_enable_rt_active_lb)
		return;

	if (p->nr_cpus_allowed == 1 || is_migration_disabled(p))
		return;

	cpu_orig_cap = capacity_orig_of(cpu);
	/* cpu has max capacity, no need to do balance */
#if 0
	if (cpu_orig_cap == rq->rd->max_cpu_capacity.val)
		return;
#else
	if (cpu_orig_cap == rq->rd->max_cpu_capacity)
		return;
#endif

#ifdef CONFIG_HONOR_RTG_NORMALIZED_UTIL
	rtg_target = find_rtg_target(p);
	if (rtg_target)
		misfit_task = capacity_orig_of(cpumask_first(rtg_target)) >
					cpu_orig_cap;
	else
		misfit_task = !rt_task_fits_capacity(p, cpu);
#else
	trace_android_rvh_sched_honor_task_fits_capacity(p, capacity_orig_of(cpu), cpu, &misfit_task);
	misfit_task = !misfit_task;
#endif

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 15, 0)
	trace_sched_rt_misfit_check(p, boosted_task_util(p), cpu, misfit_task);
#else
	trace_sched_rt_misfit_check(p, honor_uclamp_task_util(p), cpu, misfit_task);
#endif

	if (misfit_task) {
		raw_spin_lock(&rq->__lock);
		if (!rq->active_balance && !rq->rt_active_balance) {
			rq->rt_active_balance = 1;
			rq->rt_push_task = p;
			get_task_struct(p);
			need_actvie_lb = true;
		}
		raw_spin_unlock(&rq->__lock);

		if (need_actvie_lb)
			stop_one_cpu_nowait(task_cpu(p),
						rt_active_load_balance_cpu_stop,
						rq, &rq->rt_active_balance_work);
	}
}
#endif
