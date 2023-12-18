/*
 * rt_misfit.c
 *
 * rt misfit file
 *
 * Copyright (c) 2020-2021 Huawei Technologies Co., Ltd.
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
#if IS_ENABLED(CONFIG_HW_RT_ACTIVE_LB)


#if IS_ENABLED(CONFIG_HW_RTG)
#include <linux/sched/hw_rtg/rtg_sched.h>

unsigned int sysctl_sched_enable_rt_active_lb = 1;
#else
unsigned int sysctl_sched_enable_rt_active_lb = 0;
#endif

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
extern struct rq *find_lock_lowest_rq(struct task_struct *task, struct rq *rq);
#endif
static int rt_active_load_balance_cpu_stop(void *data)
{
	struct rq *busiest_rq = data;
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
	struct walt_rq *wrq = (struct walt_rq *) busiest_rq->android_vendor_data1;
	struct task_struct *next_task = wrq->rt_push_task;
#else
	struct task_struct *next_task = busiest_rq->rt_push_task;
#endif
	struct rq *lowest_rq = NULL;
	unsigned long flags;

	raw_spin_lock_irqsave(&busiest_rq->lock, flags);
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
	wrq->rt_active_balance = 0;
#else
	busiest_rq->rt_active_balance = 0;
#endif
	/* find_lock_lowest_rq locks the rq if found */
	lowest_rq = find_lock_lowest_rq(next_task, busiest_rq);
	if (!lowest_rq)
		goto out;

	if (capacity_orig_of(cpu_of(lowest_rq)) <= capacity_orig_of(task_cpu(next_task)))
		goto unlock;

	deactivate_task(busiest_rq, next_task, 0);
	next_task->on_rq = TASK_ON_RQ_MIGRATING;
	set_task_cpu(next_task, lowest_rq->cpu);
	next_task->on_rq = TASK_ON_RQ_QUEUED;
	activate_task(lowest_rq, next_task, 0);

	resched_curr(lowest_rq);

unlock:
	double_unlock_balance(busiest_rq, lowest_rq);

out:
	put_task_struct(next_task);
	raw_spin_unlock_irqrestore(&busiest_rq->lock, flags);

	return 0;
}

void check_for_rt_migration(struct rq *rq, struct task_struct *p)
{
	bool need_actvie_lb = false;
	bool misfit_task = false;
	int cpu = task_cpu(p);
	unsigned long cpu_orig_cap;
#if IS_ENABLED(CONFIG_HW_RTG_NORMALIZED_UTIL)
	struct cpumask *rtg_target = NULL;
#endif
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
	struct walt_rq *wrq = (struct walt_rq *) rq->android_vendor_data1;
#endif

	if (!sysctl_sched_enable_rt_active_lb)
		return;

	if (p->nr_cpus_allowed == 1)
		return;

	cpu_orig_cap = capacity_orig_of(cpu);
	/* cpu has max capacity, no need to do balance */

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
	if (cpu_orig_cap == rq->rd->max_cpu_capacity)
#else
	if (cpu_orig_cap == rq->rd->max_cpu_capacity.val)
#endif
		return;

#if IS_ENABLED(CONFIG_HW_RTG_NORMALIZED_UTIL)
	rtg_target = find_rtg_target(p);
	if (rtg_target)
		misfit_task = capacity_orig_of(cpumask_first(rtg_target)) >
					cpu_orig_cap;
	else
		misfit_task = !rt_task_fits_capacity(p, cpu);
#else
	misfit_task = !rt_task_fits_capacity(p, cpu);
#endif
	trace_sched_rt_misfit_check(p, boosted_task_util(p), cpu, misfit_task);

	if (misfit_task) {
		raw_spin_lock(&rq->lock);
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
		if (!rq->active_balance && !wrq->rt_active_balance) {
			wrq->rt_active_balance = 1;
			wrq->rt_push_task = p;
#else
		if (!rq->active_balance && !rq->rt_active_balance) {
			rq->rt_active_balance = 1;
			rq->rt_push_task = p;
#endif
			get_task_struct(p);
			need_actvie_lb = true;
		}
		raw_spin_unlock(&rq->lock);

		if (need_actvie_lb)
			stop_one_cpu_nowait(task_cpu(p),
						rt_active_load_balance_cpu_stop,
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
						rq, &wrq->rt_active_balance_work);
#else
						rq, &rq->rt_active_balance_work);
#endif
	}
}
#endif
