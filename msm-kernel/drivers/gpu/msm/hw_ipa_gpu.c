/*
 * hw_ipa_gpu.c
 *
 * hw ipa for gpufreq driver
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
#include <linux/devfreq.h>
#define CAPACITANCES_NUM 5
#define GPU_TZ_NUMBER 2
#define MIN_TEMP -40000
#define MAX_TEMP 145000
#define MAX_CAP 0xFFFFFF
#define DECIMAL 10
#define MAX_LOAD 100

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
#include <trace/hooks/thermal.h>
static unsigned int g_gpu_dyn_cap_item_num = 8;
static s64 dynamic_capacitance[CAPACITANCES_NUM * 2] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
static unsigned int g_gpu_voltage_scale_num = 5;
static s64 voltage_scale[CAPACITANCES_NUM] = {0, 0, 0, 0, 1};
#else
static u32 dynamic_capacitance = 1;
#endif
const char *temp_capacitances[CAPACITANCES_NUM] = {0};
const char *gpu_tz_name[GPU_TZ_NUMBER];

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
static void get_gpu_power_params(void *unused,
				 unsigned int *voltage_scale_num, s64 *volt_scale,
				 unsigned int *dyn_cap_item_num, s64 *dyn_cap,
				 int array_size, int *ret)
{
	int i;

	if (g_gpu_voltage_scale_num > array_size) {
		pr_err("%s, ipa g_gpu_voltage_scale_num > vol_scale_size", __func__);
		*ret = -EINVAL;
		return;
	}
	for (i = 0; i < g_gpu_voltage_scale_num; i++) {
		volt_scale[i] = voltage_scale[i];
		pr_debug("%s, ipa volt_scale[%d] = %d", __func__, i, volt_scale[i]);
	}
	*voltage_scale_num = g_gpu_voltage_scale_num;

	if (g_gpu_dyn_cap_item_num > array_size) {
		pr_err("%s, ipa g_gpu_dyn_cap_item_num > dyn_cap_size", __func__);
		*ret = -EINVAL;
		return;
	}
	for (i = 0; i < g_gpu_dyn_cap_item_num; i++) {
		dyn_cap[i] = dynamic_capacitance[i];
		pr_debug("%s, ipa dyn_cap[%d] = %d", __func__, i, dyn_cap[i]);
	}
	*dyn_cap_item_num = g_gpu_dyn_cap_item_num;

	*ret = 0;
}
#endif

static bool parse_gpu_temp_scale(struct device_node *dev_node)
{
	int ret, i;
	for (i = 0; i < CAPACITANCES_NUM; i++) {
		ret = of_property_read_string_index(dev_node, "huawei,gpu_temp_scale_capacitance",
						i, &temp_capacitances[i]);
		if (ret != 0) {
			pr_err("%s gpu_temp_scale_capacitance %d read err\n", __func__, i);
				return false;
		}
	}
	of_node_put(dev_node);
	pr_info("%s parse_gpu_temp_scale succ\n", __func__);
	return true;
}

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
static bool parse_gpu_capacitance(struct device_node *dev_node)
{
	int ret, i;
	const char *cap_tmp;

	ret = of_property_read_u32(dev_node, "huawei,gpu_voltage_scale_num",
				   &g_gpu_voltage_scale_num);
	if (ret != 0) {
		pr_err("%s g_gpu_voltage_scale_num read err\n", __func__);
		return false;
	}

	for (i = 0; i < g_gpu_voltage_scale_num; i++) {
		ret = of_property_read_string_index(dev_node, "huawei,gpu_voltage_scale",
						    i, &cap_tmp);
		if (ret != 0) {
			pr_err("%s huawei,gpu_voltage_scale read err\n", __func__);
			return false;
		}

		ret = kstrtoll(cap_tmp, DECIMAL, &voltage_scale[i]);
		if (ret != 0)
			return false;

		pr_debug("%s gpu_voltage_scale[%d]=%ld", __func__, i, voltage_scale[i]);
	}

	ret = of_property_read_u32(dev_node, "huawei,gpu_dyn_cap_item_num",
				   &g_gpu_dyn_cap_item_num);
	if (ret != 0) {
		pr_err("%s g_dyn_cap_item_num read err\n", __func__);
		return false;
	}

	for (i = 0; i < g_gpu_dyn_cap_item_num; i++) {
		ret = of_property_read_string_index(dev_node, "huawei,gpu_dyn_capacitance",
						    i, &cap_tmp);
		if (ret != 0) {
			pr_err("%s huawei,gpu_dyn_capacitance read err\n", __func__);
			return false;
		}

		ret = kstrtoll(cap_tmp, DECIMAL, &dynamic_capacitance[i]);
		if (ret != 0)
			return false;

		pr_debug("%s gpu_dyn_capacitance[%d]=%ld", __func__, i, dynamic_capacitance[i]);
	}
	pr_info("%s parse_gpu_capacitance succ\n", __func__);
	return parse_gpu_temp_scale(dev_node);
}
#else
static bool parse_gpu_capacitance(struct device_node *dev_node)
{
	int ret;
	ret = of_property_read_u32(dev_node, "huawei,gpu_dyn_capacitance",
				&dynamic_capacitance);
	if (ret != 0) {
		pr_err("%s gpu_dyn_capacitance read err\n", __func__);
		return false;
	}
	pr_info("%s parse_gpu_capacitance succ\n", __func__);
	return parse_gpu_temp_scale(dev_node);
}
#endif

static bool parse_gpu_tz_num(struct device_node *dev_node)
{
	u32 gpu_tz_num;
	int ret, i;
	ret = of_property_read_u32(dev_node, "huawei,gpu_tz_num", &gpu_tz_num);
	if (ret != 0) {
		pr_err("%s gpu_tz_num read err\n", __func__);
		return false;
	}
	for (i = 0; i < gpu_tz_num; i++) {
		ret = of_property_read_string_index(dev_node, "huawei,gpu_tz_name",
					i, &gpu_tz_name[i]);
		if (ret != 0) {
			pr_err("%s gpu_tz_name%d read err\n", __func__, i);
			return false;
		}
	}
	pr_info("%s parse_gpu_tz_num succ\n", __func__);
	return true;
}

static void ipa_gpu_init(void)
{
	struct device_node *dev_node = NULL;
	int ret;

	dev_node = of_find_node_by_name(NULL, "capacitances");
	if (dev_node == NULL) {
		pr_err("%s capacitances node not found\n", __func__);
		return;
	}
	if (!parse_gpu_capacitance(dev_node)) {
		goto node_put;
	}

	dev_node = of_find_node_by_name(NULL, "tz_info");
	if (dev_node == NULL) {
		pr_err("%s tz_info node not found\n", __func__);
		return;
	}
	if (!parse_gpu_tz_num(dev_node)) {
		goto node_put;
	}

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
	ret = register_trace_android_vh_get_gpu_power_params(get_gpu_power_params, NULL);
	pr_info("%s register_trace_android_vh_get_gpu_power_params ret=%d\n", __func__, ret);
#endif

	pr_info("%s ipa_gpu_init succ\n", __func__);

node_put:
	of_node_put(dev_node);
}

extern unsigned int ipa_get_gpu_temp(const char **tz_name);
static unsigned long
hw_model_static_power(struct devfreq *devfreq __maybe_unused,
	unsigned long voltage)
{
	int capacitance[CAPACITANCES_NUM] = {0};
	int temperature;
	int ret, i, cap;
	int t_exp = 1;
	long long t_scale = 0;
	unsigned long m_volt = voltage;
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
	struct devfreq_dev_status *status = &devfreq->last_status;
	int load;

	if (status->total_time)
		load = 100 * status->busy_time / status->total_time;
	else
		return 0;

	load = clamp_val(load, 0, MAX_LOAD);
#else
	unsigned long v_scale;

	v_scale = m_volt * m_volt * m_volt / 1000000;
#endif

	temperature = ipa_get_gpu_temp(gpu_tz_name);
	temperature /= 1000;

	temperature = clamp_val(temperature, MIN_TEMP, MAX_TEMP);
	for (i = 0; i < CAPACITANCES_NUM - 1; i++) {
		ret = kstrtoint(temp_capacitances[i], DECIMAL, &cap);
		if (ret != 0) {
			pr_warn("%s kstortoint is failed\n", __func__);
			return 0;
		}
		capacitance[i] = clamp_val(cap, -MAX_CAP, MAX_CAP);
		t_scale += (long long)capacitance[i] * t_exp;
		t_exp *= temperature;
	}

	t_scale = clamp_val(t_scale, 0, UINT_MAX);
	ret = kstrtoint(temp_capacitances[CAPACITANCES_NUM - 1],
			DECIMAL, &capacitance[CAPACITANCES_NUM - 1]);
	if (ret != 0) {
		pr_warn("%s kstortoint is failed\n", __func__);
		return 0;
	}

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
	trace_gpu_static_power(temperature, t_scale, m_volt, load,
		t_scale * m_volt * load / capacitance[CAPACITANCES_NUM - 1] / 1000000);

	return (unsigned long)(t_scale * m_volt * load / capacitance[CAPACITANCES_NUM - 1]) / 1000000;
#else
	trace_cpu_static_power(1, temperature, t_scale, v_scale,
		(capacitance[CAPACITANCES_NUM - 1] * v_scale * t_scale) / 1000000);

	return (unsigned long)(capacitance[CAPACITANCES_NUM - 1] * v_scale * t_scale) / 1000000;
#endif
}

static unsigned long
hw_model_dynamic_power(struct devfreq *devfreq __maybe_unused,
	unsigned long freq, unsigned long voltage)
{
	/* The inputs: freq (f) is in Hz, and voltage (v) in mV.
	 * The coefficient (c) is in mW/(MHz mV mV).
	 *
	 * This function calculates the dynamic power after this formula:
	 * Pdyn (mW) = c (mW/(MHz*mV*mV)) * v (mV) * v (mV) * f (MHz)
	 * unsigned long v2 = (voltage * voltage) / 1000;
	 */
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
	struct devfreq_dev_status *status = &devfreq->last_status;
	int i;
	s64 v_scale = 0, load_exp = 1;
	s64 dynamic_cap = 0;
	int load;
	unsigned long freq_khz = freq / 1000;

	if (status->total_time == 0)
		return 0;

	load = 100 * status->busy_time / status->total_time;
	load = clamp_val(load, 0, MAX_LOAD);

	for (i = 0; i < g_gpu_voltage_scale_num - 1; i++) {
		v_scale += voltage_scale[i] * load_exp;
		load_exp *= load;
	}
	v_scale = (v_scale < 0) ? 0 : v_scale;
	v_scale = v_scale / 10000 * voltage / voltage_scale[g_gpu_voltage_scale_num - 1];

	load_exp = 1;
	for (i = 0; i < g_gpu_dyn_cap_item_num / 2 - 1; i++)
		load_exp *= load;

	for (i = 0; i < g_gpu_dyn_cap_item_num / 2; i++) {
		dynamic_cap += load_exp * dynamic_capacitance[i];
		dynamic_cap /= dynamic_capacitance[i + g_gpu_dyn_cap_item_num / 2];
		load_exp /= load;
	}
	dynamic_cap = (dynamic_cap < 0) ? 0 : dynamic_cap;

	return ((freq_khz * v_scale * v_scale / 1000000) * dynamic_cap) / 10000000;
#else
	unsigned long v2 = voltage * voltage / 1000;
	unsigned long f_mhz = freq / 1000000;

	return (dynamic_capacitance * v2 * f_mhz) / 1000000;
#endif
}

static struct devfreq_cooling_power hw_model_ops = {
	.get_static_power = hw_model_static_power,
	.get_dynamic_power = hw_model_dynamic_power,
	.get_real_power = NULL,
};

#if (LINUX_VERSION_CODE < KERNEL_VERSION(5,10,0))
int ipa_set_thermal_pwrlevel(struct kgsl_device *device, u32 level)
{
	int min_level, max_level, thermal_level;
	struct kgsl_pwrctrl *pwr = NULL;
	struct device *dev = NULL;
	struct dev_pm_opp *opp = NULL;
	unsigned long min_freq, max_freq;
	int index;

	if (!device)
		return -ENODEV;

	pwr = &device->pwrctrl;
	if (!pwr)
		return -ENODEV;

	min_freq = 0;
	max_freq = pwr->pwrlevels[0].gpu_freq;
	dev = &device->pdev->dev;

	opp = dev_pm_opp_find_freq_ceil(dev, &min_freq);
	if (IS_ERR(opp))
		min_freq = pwr->pwrlevels[pwr->min_pwrlevel].gpu_freq;
	else
		dev_pm_opp_put(opp);

	opp = dev_pm_opp_find_freq_floor(dev, &max_freq);
	if (IS_ERR(opp))
		return PTR_ERR(opp);
	dev_pm_opp_put(opp);

	mutex_lock(&device->mutex);

	if (level >= pwr->num_pwrlevels)
		level = pwr->num_pwrlevels - 1;

	min_level = pwr->thermal_pwrlevel_floor;
	max_level = pwr->thermal_pwrlevel;
	for (index = 0; index < pwr->num_pwrlevels; index++) {
		if (min_freq == pwr->pwrlevels[index].gpu_freq)
			min_level = index;
		if (max_freq == pwr->pwrlevels[index].gpu_freq)
			max_level = index;
	}

	thermal_level = level < pwr->sysfs_thermal_pwrlevel ? pwr->sysfs_thermal_pwrlevel : level;
	thermal_level = thermal_level < pwr->cooling_thermal_pwrlevel ? pwr->cooling_thermal_pwrlevel : thermal_level;
	pwr->thermal_pwrlevel = thermal_level < max_level ? max_level : thermal_level;
	pwr->thermal_pwrlevel_floor = min_level > pwr->thermal_pwrlevel_floor ? pwr->thermal_pwrlevel_floor : min_level;
	kgsl_pwrctrl_pwrlevel_change(device, pwr->active_pwrlevel);

	trace_set_thermal_pwrlevel(min_freq, max_freq, min_level, max_level,
		pwr->thermal_pwrlevel, pwr->thermal_pwrlevel_floor);

	mutex_unlock(&device->mutex);

	return 0;
}
EXPORT_SYMBOL(ipa_set_thermal_pwrlevel);
#endif
#else
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
void get_gpu_power_params(void *unused,
			  unsigned int *voltage_scale_num, int *volt_scale,
			  unsigned int *dyn_cap_item_num, int *dyn_cap,
			  int *ret)
{
	*ret = -EINVAL;
}
#endif
#endif /* CONFIG_HW_IPA_THERMAL */
