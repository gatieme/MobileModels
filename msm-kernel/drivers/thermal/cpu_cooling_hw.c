/*
 * cpu_cooling_hw.c
 *
 * hw cpu cooling enhance
 *
 * Copyright (C) 2020-2021 Huawei Technologies Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#include <linux/version.h>
#ifdef CONFIG_HW_IPA_THERMAL
#include <trace/events/thermal_power_allocator.h>
#ifdef CONFIG_HW_THERMAL_SPM
extern unsigned int get_powerhal_profile(int actor);
extern unsigned int get_minfreq_profile(int actor);
extern bool is_spm_mode_enabled(void);
#endif
extern unsigned int g_ipa_freq_limit[];
extern unsigned int g_ipa_soc_freq_limit[];
extern unsigned int g_ipa_board_freq_limit[];
extern unsigned int g_ipa_board_state[];
extern unsigned int g_ipa_soc_state[];

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
/**
 * get_level: Find the level for a particular frequency
 * @cpufreq_cdev: cpufreq_cdev for which the property is required
 * @freq: Frequency
 *
 * Return: level corresponding to the frequency.
 */
static unsigned long get_level(struct cpufreq_cooling_device *cpufreq_cdev,
		unsigned int freq)
{
	struct freq_table *freq_table = cpufreq_cdev->freq_table;
	unsigned long level;

	for (level = 1; level <= cpufreq_cdev->max_level; level++)
		if (freq > freq_table[level].frequency)
			break;

	return level - 1;
}

static u32 get_idle_power(unsigned int cluster, u32 freq_khz, struct device_node *np)
{
	char prop_name[30];
	int ret, count, i;
	u32 cluster_idle_power[20];

	ret = snprintf_s(prop_name, sizeof(prop_name), (sizeof(prop_name) - 1),
			"huawei,cluster%d_idle_power", cluster);
	if (ret < 0) {
		pr_err("%s ipa snprintf_s err\n", __func__);
		return 0;
	}

	count = of_property_count_u32_elems(np, prop_name);
	if (count <= 0) {
		pr_err("%s ipa %s count = 0\n", __func__, prop_name);
		return 0;
	}

	ret = of_property_read_u32_array(np, prop_name, cluster_idle_power, count);
	if (ret != 0) {
		pr_err("%s ipa get %s fail\n", __func__, prop_name);
		return 0;
	}

	for (i = 0; i < count - 1; i = i + 2) {
		if (freq_khz >= cluster_idle_power[i])
			return cluster_idle_power[i + 1];
	}

	return cluster_idle_power[count - 1];
}
/**
 * update_freq_table() - Update the freq table with power numbers
 * @cpufreq_cdev: the cpufreq cooling device in which to update the table
 * @capacitance: dynamic power coefficient for these cpus
 *
 * Update the freq table with power numbers.  This table will be used in
 * cpu_power_to_freq() and cpu_freq_to_power() to convert between power and
 * frequency efficiently.  Power is stored in mW, frequency in KHz.  The
 * resulting table is in descending order.
 *
 * Return: 0 on success, -EINVAL if there are no OPPs for any CPUs,
 * or -ENOMEM if we run out of memory.
 */
static int update_freq_table(struct cpufreq_cooling_device *cpufreq_cdev,
		u32 *capacitance)
{
	struct freq_table *freq_table = cpufreq_cdev->freq_table;
	struct dev_pm_opp *opp;
	struct device *dev = NULL;
	int num_opps = 0;
	int cpu = cpufreq_cdev->policy->cpu;
	int i, j;
	struct device_node *np = NULL;
	int ret = 0;
	int clustermask[MAX_THERMAL_CLUSTER_NUM] = {0};
	unsigned tmp, cur_cluster;

	ipa_get_clustermask(clustermask, MAX_THERMAL_CLUSTER_NUM);
	tmp = (unsigned int)topology_physical_package_id(cpu);
	cur_cluster = clustermask[tmp];

	dev = get_cpu_device(cpu);
	if (unlikely(!dev)) {
		pr_warn("No cpu device for cpu %d\n", cpu);
		return -ENODEV;
	}

	num_opps = dev_pm_opp_get_opp_count(dev);
	if (num_opps < 0)
		return num_opps;

	/*
	 * The cpufreq table is also built from the OPP table and so the count
	 * should match.
	 */
	if (num_opps != cpufreq_cdev->max_level + 1) {
		dev_warn(dev, "Number of OPPs not matching with max_levels\n");
		return -EINVAL;
	}

	np = of_find_node_by_name(NULL, "cluster_idle_power");
	if (np == NULL) {
		pr_err("%s ipa get cluster_idle_power fail\n", __func__);
		return -ENODEV;
	}

	for (i = 0; i <= cpufreq_cdev->max_level; i++) {
		unsigned long freq = freq_table[i].frequency * 1000;
		u32 freq_khz = freq_table[i].frequency;
		u64 power;
		u32 voltage_mv;
		u32 cap = 0;
		u32 idle_power = 0;

		/*
		 * Find ceil frequency as 'freq' may be slightly lower than OPP
		 * freq due to truncation while converting to kHz.
		 */
		opp = dev_pm_opp_find_freq_ceil(dev, &freq);
		if (IS_ERR(opp)) {
			dev_err(dev, "failed to get opp for %lu frequency\n",
				freq);
			goto node_put;
		}

		voltage_mv = dev_pm_opp_get_voltage(opp) / 1000;
		dev_pm_opp_put(opp);

		j = 0;
		while (freq_khz < capacitance[j])
			j += 2;
		cap = capacitance[j + 1];

		idle_power = get_idle_power(cur_cluster, freq_khz, np);
		/*
		 * Do the multiplication with MHz and millivolt so as
		 * to not overflow.
		 */
		power = (u64)freq_khz * voltage_mv * voltage_mv / 100000;
		power = (u64)cap * power / 100000 / 1000000;
		power += idle_power;

		pr_err("%s, cpu%d, capacitance=%ld, freq=%lu, voltage=%lu,\
			idle_power=%u, power=%lu\n", __func__, cpu, cap,
			freq, voltage_mv, idle_power, power);

		/* power is stored in mW */
		freq_table[i].power = power;
	}

	of_node_put(np);
	return 0;

node_put:
	of_node_put(np);

	return -EINVAL;
}

static u32 cpu_freq_to_power(struct cpufreq_cooling_device *cpufreq_cdev,
		u32 freq)
{
	int i;
	struct freq_table *freq_table = cpufreq_cdev->freq_table;

	for (i = 1; i <= cpufreq_cdev->max_level; i++)
		if (freq > freq_table[i].frequency)
			break;

	return freq_table[i - 1].power;
}

static u32 cpu_power_to_freq(struct cpufreq_cooling_device *cpufreq_cdev,
		u32 power)
{
	int i;
	struct freq_table *freq_table = cpufreq_cdev->freq_table;

	for (i = 0; i < cpufreq_cdev->max_level; i++)
		if (power >= freq_table[i].power)
			break;

	return freq_table[i].frequency;
}

static unsigned int find_next_max(struct cpufreq_frequency_table *table,
	unsigned int prev_max)
{
	struct cpufreq_frequency_table *pos;
	unsigned int max = 0;

	cpufreq_for_each_valid_entry(pos, table) {
		if (pos->frequency > max && pos->frequency < prev_max)
			max = pos->frequency;
	}

	return max;
}

static unsigned int find_exact_freq(struct cpufreq_cooling_device *cpufreq_cdev,
	unsigned int freq)
{
	int i;
	struct freq_table *freq_table = cpufreq_cdev->freq_table;

	for (i = 0; i <= cpufreq_cdev->max_level - 2; i++)
		if (freq >= freq_table[i].frequency)
			return freq_table[i + 2].frequency;;

	return freq_table[cpufreq_cdev->max_level].frequency;
}
#endif

#ifdef CONFIG_HW_IPA_THERMAL_DEBUG
static void print_cpu_freq_table(struct cpufreq_cooling_device *cdev)
{
	u32 *f_table, *p_table;
	int i;

	f_table = kcalloc(cdev->max_level + 1, sizeof(u32), GFP_KERNEL);
	p_table = kcalloc(cdev->max_level + 1, sizeof(u32), GFP_KERNEL);

	for (i = 0; i <= cdev->max_level; i++) {
		if (f_table != NULL)
			f_table[i] = cdev->freq_table[i].frequency;
		if (p_table != NULL)
			p_table[i] = cdev->freq_table[i].power;
	}

	if (f_table != NULL && p_table != NULL)
		trace_xpu_freq_table(f_table, p_table, cdev->max_level + 1);

	if (f_table != NULL)
		kfree(f_table);
	if (p_table != NULL)
		kfree(p_table);
}
#endif

static void ipa_calc_static_power(struct cpufreq_cooling_device *cpufreq_cdev,
				  u32 voltage_mv, u32 freq_mhz, u64 freq_power)
{
	u32 static_power;
	int nr_cpus;

	nr_cpus = (int)cpumask_weight(cpufreq_cdev->policy->related_cpus);
	if (nr_cpus == 0)
		nr_cpus = 1;
	if (cpufreq_cdev->plat_get_static_power == NULL) {
		static_power = 0;
		pr_err("%s, %u MHz @ %u mV :  %u + %u = %u mW, nr_cpus = %d\n",
		   __func__, freq_mhz, voltage_mv, freq_power, static_power,
		   freq_power + static_power, nr_cpus);
		return;
	}
	cpufreq_cdev->plat_get_static_power(cpufreq_cdev->policy->related_cpus,
					    0,
					    (unsigned long)(voltage_mv * 1000),
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
					    (unsigned long)freq_mhz, &static_power);
#else
					    &static_power);
#endif

	/* hw static_power givern in cluster */
	static_power = static_power / (u32) nr_cpus;

	pr_err("%s, %u MHz @ %u mV :  %u + %u = %u mW, nr_cpus = %d\n",
	       __func__, freq_mhz, voltage_mv, freq_power, static_power,
	       freq_power + static_power, nr_cpus);
}

static bool ipa_check_dev_offline(struct device *dev, u32 * power)
{
	if (dev == NULL) {
		*power = 0;
		return true;
	}

	device_lock(dev);
	if (dev->offline == true) {
		*power = 0;
		device_unlock(dev);
		return true;
	}
	device_unlock(dev);
	return false;
}

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
static unsigned int get_state_freq(struct cpufreq_cooling_device *cpufreq_cdev,
	unsigned long state);
#endif
static unsigned long ipa_cpufreq_set_cur_state(struct cpufreq_cooling_device
					       *cpufreq_cdev,
					       unsigned long state)
{
	unsigned int cpu = cpumask_any(cpufreq_cdev->policy->related_cpus);
	unsigned int cur_cluster, tmp;
	unsigned long limit_state;
	int clustermask[MAX_THERMAL_CLUSTER_NUM] = {0};

	ipa_get_clustermask(clustermask, MAX_THERMAL_CLUSTER_NUM);
	tmp = (unsigned int)topology_physical_package_id(cpu);
	cur_cluster = clustermask[tmp];

	if (g_ipa_soc_state[cur_cluster] <= cpufreq_cdev->max_level)
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
		g_ipa_soc_freq_limit[cur_cluster] =
		    get_state_freq(cpufreq_cdev, g_ipa_soc_state[cur_cluster]);
#else
		g_ipa_soc_freq_limit[cur_cluster] =
		    cpufreq_cdev->freq_table[g_ipa_soc_state[cur_cluster]].
		    frequency;
#endif

	if (g_ipa_board_state[cur_cluster] <= cpufreq_cdev->max_level)
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
		g_ipa_board_freq_limit[cur_cluster] =
		    get_state_freq(cpufreq_cdev, g_ipa_board_state[cur_cluster]);
#else
		g_ipa_board_freq_limit[cur_cluster] =
		    cpufreq_cdev->freq_table[g_ipa_board_state[cur_cluster]].
		    frequency;
#endif

	limit_state =
	    max(g_ipa_soc_state[cur_cluster], g_ipa_board_state[cur_cluster]);
	/* only change new state when limit_state less than max_level */
	if (!WARN_ON(limit_state > cpufreq_cdev->max_level))
		state = max(state, limit_state);

	trace_set_cur_state(cur_cluster, g_ipa_soc_state[cur_cluster],
			g_ipa_board_state[cur_cluster], g_ipa_soc_freq_limit[cur_cluster],
			g_ipa_board_freq_limit[cur_cluster], limit_state, state);

	return state;
}

static void ipa_set_freq_limit(struct cpufreq_cooling_device *cpufreq_cdev,
			       unsigned int clip_freq)
{
	unsigned int cpu = cpumask_any(cpufreq_cdev->policy->related_cpus);
	unsigned int cur_cluster, tmp;
	int clustermask[MAX_THERMAL_CLUSTER_NUM] = {0};

	ipa_get_clustermask(clustermask, MAX_THERMAL_CLUSTER_NUM);
	tmp = (unsigned int)topology_physical_package_id(cpu);
	cur_cluster = clustermask[tmp];
	g_ipa_freq_limit[cur_cluster] = clip_freq;
	trace_set_freq_limit(cur_cluster, g_ipa_freq_limit[cur_cluster]);
}

/**
 * get_static_power() - calculate the static power consumed by the cpus
 * @cpufreq_cdev:	struct &cpufreq_cooling_device for this cpu cdev
 * @tz:		thermal zone device in which we're operating
 * @freq:	frequency in KHz
 * @power:	pointer in which to store the calculated static power
 *
 * Calculate the static power consumed by the cpus described by
 * @cpu_actor running at frequency @freq.  This function relies on a
 * platform specific function that should have been provided when the
 * actor was registered.  If it wasn't, the static power is assumed to
 * be negligible.  The calculated static power is stored in @power.
 *
 * Return: 0 on success, -E* on failure.
 */
static int get_static_power(struct cpufreq_cooling_device *cpufreq_cdev,
			    struct thermal_zone_device *tz, unsigned long freq,
			    u32 *power)
{
	struct dev_pm_opp *opp = NULL;
	unsigned long voltage;
	struct cpufreq_policy *policy = cpufreq_cdev->policy;
	struct cpumask *cpumask = policy->related_cpus;
	unsigned long freq_hz = freq * 1000;
	struct device *dev = NULL;
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
	unsigned int num_cpus;
	int ret;
#endif
	if (!cpufreq_cdev->plat_get_static_power) {
		*power = 0;
		return 0;
	}

	dev = get_cpu_device(policy->cpu);
	WARN_ON(!dev);

	if (ipa_check_dev_offline(dev, power) == true)
		return 0;

	opp = dev_pm_opp_find_freq_exact(dev, freq_hz, true);
	if (IS_ERR(opp)) {
		dev_warn_ratelimited(dev, "Failed to find OPP for frequency %lu: %ld\n",
				     freq_hz, PTR_ERR(opp));
		return -EINVAL;
	}

	voltage = dev_pm_opp_get_voltage(opp);
	dev_pm_opp_put(opp);

	if (voltage == 0) {
		dev_err_ratelimited(dev, "Failed to get voltage for frequency %lu\n",
				    freq_hz);
		return -EINVAL;
	}
	trace_cpu_freq_voltage(policy->cpu, freq_hz, voltage);

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
	num_cpus = cpumask_weight(cpumask);
	ret = cpufreq_cdev->plat_get_static_power(cpumask, 0, voltage, freq_hz / 1000000, power);
	if (ret)
		return ret;

	if (num_cpus != 0)
		*power = (*power) * cpufreq_cdev->last_load / 100 / num_cpus;

	return 0;
#else
	return cpufreq_cdev->plat_get_static_power(cpumask, 0, voltage, power);
#endif
}
#endif

#ifdef CONFIG_HW_THERMAL_SPM
int cpufreq_update_policies(void)
{
	struct cpufreq_cooling_device *cpufreq_cdev = NULL;
	struct cpufreq_policy *policy = NULL;
	unsigned int state, freq, min_freq;
	unsigned long clipped_freq;
	int actor;
	int num = 0;
	int clustermask[MAX_THERMAL_CLUSTER_NUM] = {0};

	mutex_lock(&cooling_cpufreq_lock);
	list_for_each_entry(cpufreq_cdev, &cpufreq_cdev_list, node) {
		if (num >= (int)g_cluster_num)
			break;

		policy = cpufreq_cdev->policy;
		state = cpufreq_cdev->cpufreq_state;
		clipped_freq = cpufreq_cdev->freq_table[state].frequency;

		ipa_get_clustermask(clustermask, MAX_THERMAL_CLUSTER_NUM);
		if (is_spm_mode_enabled()) {
			actor = topology_physical_package_id(policy->cpu);
			freq = get_powerhal_profile(clustermask[actor]);
			min_freq = get_minfreq_profile(clustermask[actor]);

			freq_qos_update_request(&cpufreq_cdev->qos_req,
				freq);
			freq_qos_update_request(&cpufreq_cdev->qos_req_min,
				min_freq);
		} else {
			freq_qos_update_request(&cpufreq_cdev->qos_req,
				clipped_freq);
		}
		num++;
	}
	mutex_unlock(&cooling_cpufreq_lock);

	return 0;
}
EXPORT_SYMBOL(cpufreq_update_policies);
#endif

#ifdef CONFIG_HW_IPA_THERMAL
static struct thermal_cooling_device *
__cpufreq_cooling_register(struct device_node *np,
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
		struct cpufreq_policy *policy, struct em_perf_domain *em,
		get_static_t plat_static_func, bool is_ipa, u32 *capacitance);
#else
		struct cpufreq_policy *policy, u32 capacitance,
		get_static_t plat_static_func, bool is_ipa);
#endif

/**
 * of_cpufreq_power_cooling_register() - create cpufreq cooling device with power extensions
 * @np:	a valid struct device_node to the cooling device device tree node
 * @policy: cpufreq policy
 * @capacitance:	dynamic power coefficient for these cpus
 * @plat_static_func:	function to calculate the static power consumed by these
 *			cpus (optional)
 *
 * This interface function registers the cpufreq cooling device with
 * the name "thermal-cpufreq-%x".  This api can support multiple
 * instances of cpufreq cooling devices.  Using this API, the cpufreq
 * cooling device will be linked to the device tree node provided.
 * Using this function, the cooling device will implement the power
 * extensions by using a simple cpu power model.  The cpus must have
 * registered their OPPs using the OPP library.
 *
 * An optional @plat_static_func may be provided to calculate the
 * static power consumed by these cpus.  If the platform's static
 * power consumption is unknown or negligible, make it NULL.
 *
 * Return: a valid struct thermal_cooling_device pointer on success,
 * on failure, it returns a corresponding ERR_PTR().
 */
struct thermal_cooling_device *
of_cpufreq_power_cooling_register(struct device_node *np,
				  struct cpufreq_policy *policy,
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
				  u32 *capacitance,
#else
				  u32 capacitance,
#endif
				  get_static_t plat_static_func)
{
	if (!np)
		return ERR_PTR(-EINVAL);

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
	return __cpufreq_cooling_register(np, policy, em_cpu_get(policy->cpu),
				plat_static_func, true, capacitance);
#else
	return __cpufreq_cooling_register(np, policy, capacitance,
				plat_static_func, true);
#endif
}
EXPORT_SYMBOL(of_cpufreq_power_cooling_register);
#endif
