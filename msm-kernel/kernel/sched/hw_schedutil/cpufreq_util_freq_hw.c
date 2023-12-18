/*
 * cpufreq_util_freq_hw.c
 *
 * Copyright (c) 2021-2022 Huawei Technologies Co., Ltd
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

static unsigned int arch_get_cpu_max_freq(unsigned int cpu)
{
	struct sugov_cpu *sg_cpu = NULL;
	struct sugov_policy *sg_policy = NULL;
	struct cpufreq_policy *policy = NULL;

	if (cpu >= nr_cpu_ids)
		return 0;

	sg_cpu = &per_cpu(sugov_cpu, cpu);
	if (!sg_cpu)
		return 0;

	sg_policy = sg_cpu->sg_policy;
	if (!sg_policy)
		return 0;

	policy = sg_policy->policy;
	if (!policy)
		return 0;

	return policy->cpuinfo.max_freq;
}

unsigned int hw_freq_to_util(unsigned int cpu, unsigned int freq)
{
	struct sugov_cpu *sg_cpu = NULL;
	struct sugov_policy *sg_policy = NULL;
	if (cpu > nr_cpu_ids) {
		return 0;
	}

	sg_cpu = &per_cpu(sugov_cpu, cpu);
	if (!sg_cpu) {
	return 0;
	}

	sg_policy = sg_cpu->sg_policy;
	if (!sg_policy) {
		return 0;
	}

	return (unsigned int)freq_to_util(sg_policy, freq);
}

/*
 * Note that hw_util_to_freq(i, hw_freq_to_util(i, *freq*)) is lower than *freq*.
 * That's ok since we use CPUFREQ_RELATION_L in __cpufreq_driver_target().
 */
unsigned int hw_util_to_freq(unsigned int cpu, unsigned int util)
{
	unsigned int max_freq = arch_get_cpu_max_freq(cpu);
	unsigned int freq = 0U;

	freq = cpu_rq(cpu)->cluster->max_freq *
		(unsigned long)util / arch_scale_cpu_capacity(NULL, cpu);
	freq = clamp(freq, 0U, max_freq);

	return freq;
}
