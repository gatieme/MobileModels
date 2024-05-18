/*
 * Honor Sched Cluster File
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
#include "sched_cluster.h"
#include "../kernel/sched/sched.h"

int num_clusters;

unsigned int freq_to_util(unsigned int cpu, unsigned int freq)
{
	unsigned int util = 0U;
#if 0
	util = arch_scale_cpu_capacity(cpu) *
		(unsigned long)freq / cpu_rq(cpu)->wrq.cluster->max_freq;
	util = clamp(util, 0U, (unsigned int)SCHED_CAPACITY_SCALE);
#endif
	return util;
}

/*
 * Note that util_to_freq(i, freq_to_util(i, *freq*)) is lower than *freq*.
 * That's ok since we use CPUFREQ_RELATION_L in __cpufreq_driver_target().
 */
unsigned int util_to_freq(unsigned int cpu, unsigned int util)
{
	unsigned int freq = 0U;
#if 0
	unsigned int max_freq = arch_get_cpu_max_freq(cpu);

	freq = cpu_rq(cpu)->wrq.cluster->max_freq *
		(unsigned long)util / arch_scale_cpu_capacity(cpu);
	freq = clamp(freq, 0U, max_freq);
#endif
	return freq;
}

#ifdef CONFIG_HONOR_SCHED_VIP
void kick_load_balance(struct rq *rq)
{
	struct walt_sched_cluster *cluster = NULL;
	struct walt_sched_cluster *kick_cluster = NULL;
	int kick_cpu;

	/* Find the prev cluster. */
	for_each_sched_cluster(cluster) {
		if (cluster == rq->wrq.cluster)
			break;
		kick_cluster = cluster;
	}

	if (!kick_cluster)
		return;

	/* Find first unisolated idle cpu in the cluster. */
	for_each_cpu(kick_cpu, &kick_cluster->cpus) {
		if (!cpu_online(kick_cpu) || cpu_isolated(kick_cpu))
			continue;
		if (!idle_cpu(kick_cpu))
			continue;
		break;
	}

	if (kick_cpu >= nr_cpu_ids)
		return;

	reset_balance_interval(kick_cpu);
	vip_balance_set_overutilized(cpu_of(rq));
	if (test_and_set_bit(NOHZ_BALANCE_KICK, nohz_flags(kick_cpu)))
		return;
	smp_send_reschedule(kick_cpu);
}
#else
void kick_load_balance(struct rq *rq) { }
#endif
