/*
 * favor_small_hw.c
 *
 * Copyright (c) 2019-2021 Honor Technologies Co., Ltd.
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

#include <linux/cpumask.h>
#include "favor_small_hw.h"
#include <../kernel/sched/sched.h>

extern unsigned long capacity_spare_without(int cpu, struct task_struct *p);

/*
 * Find the smallest cap cpus with spared capacity and pick the
 * max spared capacity one.
 */
int find_slow_cpu(struct task_struct *p)
{
	cpumask_t search_cpus;
	unsigned long target_cap = ULONG_MAX;
	unsigned long max_spare_cap = 0;
	int i;
	int target_cpu = -1;

	if (p->state != TASK_WAKING)
		return -1;

	cpumask_and(&search_cpus, &p->cpus_mask, cpu_online_mask);
	cpumask_andnot(&search_cpus, &search_cpus, cpu_isolated_mask);

	for_each_cpu(i, &search_cpus) {
		unsigned long cap_orig, spare_cap;

		cap_orig = capacity_orig_of(i);
		if (cap_orig > target_cap)
			continue;

		spare_cap = capacity_spare_without(i, p);
		if (spare_cap <= max_spare_cap)
			continue;

		target_cpu = i;
		target_cap = cap_orig;
		max_spare_cap = spare_cap;
	}

	return target_cpu;
}