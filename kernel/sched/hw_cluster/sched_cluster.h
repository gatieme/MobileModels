/*
 * Honor sched cluster declaration
 *
 * Copyright (c) 2019-2020 Honor Technologies Co., Ltd.
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

#ifndef SCHED_CLUSTER_HW_H
#define SCHED_CLUSTER_HW_H

#ifdef CONFIG_HW_SCHED_CLUSTER

extern struct list_head cluster_head;
#define max_cap_cluster()	\
	list_last_entry(&cluster_head, struct walt_sched_cluster, list)

unsigned int freq_to_util(unsigned int cpu, unsigned int freq);

/*
 * Note that util_to_freq(i, freq_to_util(i, *freq*)) is lower than *freq*.
 * That's ok since we use CPUFREQ_RELATION_L in __cpufreq_driver_target().
 */
unsigned int util_to_freq(unsigned int cpu, unsigned int util);

#endif /* CONFIG_HW_SCHED_CLUSTER */

#endif
