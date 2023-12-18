/*
 * devfreq_cooling_hw.c
 *
 * hw devfreq cooling enhance
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

#ifdef CONFIG_HW_IPA_THERMAL
#define PROP_NAME_LEN 20
#include <trace/events/thermal_power_allocator.h>
#include <securec.h>
#include <linux/version.h>

#include <trace/hooks/thermal.h>

extern unsigned int g_ipa_freq_limit[];
extern unsigned int g_ipa_soc_freq_limit[];
extern unsigned int g_ipa_board_freq_limit[];
extern unsigned int g_ipa_board_state[];
extern unsigned int g_ipa_soc_state[];
extern int update_devfreq(struct devfreq *devfreq);
extern int ipa_set_thermal_pwrlevel(struct kgsl_device *device, u32 new_level);

static inline unsigned long get_total_power(struct devfreq_cooling_device *dfc,
					unsigned long freq,
					unsigned long voltage);
static unsigned long get_static_power(struct devfreq_cooling_device *dfc,
					unsigned long freq);
static unsigned long get_dynamic_power(struct devfreq_cooling_device *dfc,
					unsigned long freq,
					unsigned long voltage);

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
static unsigned long get_full_dynamic_power(unsigned long busy_time, unsigned long total_time,
					    unsigned long voltage, unsigned long frequency);
#endif
static unsigned long get_voltage(struct devfreq_cooling_device *dfc, unsigned long freq)
{
	int index;
	unsigned long voltage;

	for (index = 1; index < dfc->freq_table_size; index++) {
		if (freq > dfc->freq_table[index])
			break;
	}
	voltage = dfc->voltage_table[index - 1];

	return voltage / 1000; /* mV */
}

static void ipa_power_debug_print(struct devfreq_cooling_device *dfc,
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
				  unsigned long freq, unsigned long voltage,
				  int get_gpu_power_err)
#else
				  unsigned long freq, unsigned long voltage)
#endif
{
	unsigned long power_static;
	unsigned long power_dyn;

	power_static = get_static_power(dfc, freq);
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
	power_dyn = (get_gpu_power_err == 1) ? 0 :
		     get_full_dynamic_power(1, 1, voltage, freq / 1000);
#else
	power_dyn = get_dynamic_power(dfc, freq, voltage / 1000);
#endif
	pr_err("%s: %lu MHz @ %lu mV: %lu + %lu = %lu mW\n",
		 __func__, freq / 1000000, voltage / 1000,
		 power_dyn, power_static, power_dyn + power_static);
}

static int of_parse_gpu_opp(int idx, struct device_node *np, unsigned long freq)
{
	int ret;
	char prop_name[PROP_NAME_LEN];
	int freq_volt[2];
	unsigned long tmp = 0;

	ret = snprintf_s(prop_name, sizeof(prop_name), (sizeof(prop_name) - 1),
			"huawei,gpu_opp_%d", idx);
	if (ret < 0) {
		pr_err("%s, snprintf_s error.\n", __func__);
		return tmp;
	}

	ret = of_property_read_u32_array(np, prop_name, freq_volt, 2);
	if (!ret) {
		if (freq_volt[0] == freq)
			tmp = freq_volt[1];
		else
			pr_err("%s, freq is not equal\n", __func__);
	} else {
		pr_err("%s, get gpu_opp_%d err\n", __func__, idx);
	}

	return tmp;
}

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
static unsigned int voltage_scale_num, dyn_cap_item_num;
static s64 volt_scale[CAPACITY_OF_ARRAY], dyn_cap[CAPACITY_OF_ARRAY];
static int get_gpu_power_params()
{
	int ret = -EINVAL;

	trace_android_vh_get_gpu_power_params(&voltage_scale_num, volt_scale,
					      &dyn_cap_item_num, dyn_cap,
					      CAPACITY_OF_ARRAY, &ret);

	return ret;
}
#endif
/**
 * devfreq_cooling_gen_tables() - Generate power and freq tables.
 * @dfc: Pointer to devfreq cooling device.
 *
 * Generate power and frequency tables: the power table hold the
 * device's maximum power usage at each cooling state (OPP).  The
 * static and dynamic power using the appropriate voltage and
 * frequency for the state, is acquired from the struct
 * devfreq_cooling_power, and summed to make the maximum power draw.
 *
 * The frequency table holds the frequencies in descending order.
 * That way its indexed by cooling device state.
 *
 * The tables are malloced, and pointers put in dfc.  They must be
 * freed when unregistering the devfreq cooling device.
 *
 * Return: 0 on success, negative error code on failure.
 */
static int devfreq_cooling_gen_tables(struct devfreq_cooling_device *dfc)
{
	struct device_node *np = NULL;
	struct devfreq *df = dfc->devfreq;
	struct device *dev = df->dev.parent;
	int ret, num_opps;
	unsigned long freq;
	u32 *power_table = NULL;
	u32 *freq_table = NULL;
	u32 *voltage_table = NULL;
	int i;
	bool found = true;
	bool use_parse = false;
	int parse_num = 0;
	unsigned long power, voltage;
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
	int get_gpu_power_err = 0;
#endif

	np = of_find_node_by_name(NULL, "gpu_opp");
	if (np != NULL) {
		ret = of_property_read_u32(np, "huawei,gpu_opp_num", &parse_num);
		if (ret)
			pr_err("%s, parse gpu_opp_num err\n", __func__);
	} else {
		pr_err("%s, gpu_opp node not found\n", __func__);
		found = false;
	}

	num_opps = dev_pm_opp_get_opp_count(dev);
	if (found && (parse_num == num_opps))
		use_parse = true;
	if (dfc->power_ops) {
		power_table = kcalloc(num_opps, sizeof(*power_table),
				      GFP_KERNEL);
		if (!power_table) {
			if (np)
				of_node_put(np);
			return -ENOMEM;
		}
	}

	freq_table = kcalloc(num_opps, sizeof(*freq_table),
			     GFP_KERNEL);
	if (!freq_table) {
		ret = -ENOMEM;
		goto free_power_table;
	}

	voltage_table = kcalloc(num_opps, sizeof(*voltage_table),
				GFP_KERNEL);
	if (!voltage_table) {
		ret = -ENOMEM;
		goto free_freq_tables;
	}

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
	ret = get_gpu_power_params();
	if (ret != 0)
		get_gpu_power_err = 1;
#endif

	for (i = 0, freq = ULONG_MAX; i < num_opps; i++, freq--) {
		struct dev_pm_opp *opp;

		opp = dev_pm_opp_find_freq_floor(dev, &freq);
		if (IS_ERR(opp)) {
			ret = PTR_ERR(opp);
			goto free_tables;
		}

		if (use_parse)
			voltage = of_parse_gpu_opp(i, np, freq); /* uV */
		else
			voltage = dev_pm_opp_get_voltage(opp); /* mV */
		dev_pm_opp_put(opp);

		voltage_table[i] = voltage;  /* uV */
		voltage /= 1000; /* mV */

		if (dfc->power_ops) {
			if (dfc->power_ops->get_real_power)
				power = get_total_power(dfc, freq, voltage);
			else
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
				power = (get_gpu_power_err == 1) ? 0 :
					get_full_dynamic_power(1, 1, voltage_table[i], freq / 1000);
#else
				power = get_dynamic_power(dfc, freq, voltage);
#endif
			power_table[i] = power;
		}

		freq_table[i] = freq;
	}

	if (dfc->power_ops)
		dfc->power_table = power_table;

	dfc->freq_table = freq_table;
	dfc->freq_table_size = num_opps;
	dfc->voltage_table = voltage_table;

	for (i = 0; i < dfc->freq_table_size; i++) {
		freq = dfc->freq_table[i];
		voltage = dfc->voltage_table[i];
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
		ipa_power_debug_print(dfc, freq, voltage, get_gpu_power_err);
#else
		ipa_power_debug_print(dfc, freq);
#endif
	}

	if (np)
		of_node_put(np);

	return 0;

free_tables:
	kfree(voltage_table);
free_freq_tables:
	kfree(freq_table);
free_power_table:
	kfree(power_table);
	if (np)
		of_node_put(np);
	return ret;
}

static void ipa_set_current_load_freq(struct thermal_cooling_device *cdev,
				      struct thermal_zone_device *tz,
				      u32 dyn_power, u32 static_power,
				      u32 * power)
{
	struct devfreq_cooling_device *dfc = cdev->devdata;
	struct devfreq *df = dfc->devfreq;
	struct devfreq_dev_status *status = &df->last_status;
	unsigned long load = 0;
	unsigned long freq = status->current_frequency;

	if (status->total_time)
		load = 100 * status->busy_time / status->total_time;

	trace_IPA_actor_gpu_get_power((freq / 1000), load, dyn_power,
				      static_power, *power);

	cdev->current_load = load;
	cdev->current_freq = freq;
}

static void print_gpu_freq_table(struct devfreq_cooling_device *dfc)
{
	trace_xpu_freq_table(dfc->freq_table, dfc->power_table, dfc->freq_table_size);
}

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
static unsigned long ipa_devfreq_set_cur_state(struct devfreq_cooling_device *dfc,
					       unsigned long state)
{
	int gpu_id;
	unsigned long limit_state;

	gpu_id = ipa_get_actor_id("gpu");
	if (gpu_id < 0)
		return state;

	if (g_ipa_soc_state[gpu_id] < dfc->freq_table_size)
		g_ipa_soc_freq_limit[gpu_id] =
			dfc->freq_table[g_ipa_soc_state[gpu_id]];

	if (g_ipa_board_state[gpu_id] < dfc->freq_table_size)
		g_ipa_board_freq_limit[gpu_id] =
			dfc->freq_table[g_ipa_board_state[gpu_id]];

	limit_state = max(g_ipa_soc_state[gpu_id], g_ipa_board_state[gpu_id]);
	if (limit_state < dfc->freq_table_size)
		state = max(state, limit_state);

	trace_set_cur_state(gpu_id, g_ipa_soc_state[gpu_id], g_ipa_board_state[gpu_id],
		g_ipa_soc_freq_limit[gpu_id], g_ipa_board_freq_limit[gpu_id],
		limit_state, state);

	return state;
}

static void ipa_set_devfreq_limit(struct devfreq_cooling_device *dfc,
	unsigned int clip_freq, unsigned long state)
{
	int gpu_id;
	struct devfreq *df = dfc->devfreq;
	struct device *dev = df->dev.parent;

	gpu_id = ipa_get_actor_id("gpu");
	if (gpu_id < 0)
		return;

	g_ipa_freq_limit[gpu_id] = clip_freq;

	trace_IPA_actor_gpu_cooling(clip_freq / 1000, state);
	trace_set_freq_limit(gpu_id, g_ipa_freq_limit[gpu_id]);

	df->profile->get_dev_status(dev, &df->last_status);
}

/*
 * voltage: uV
 * frequency: kHZ
 */
static unsigned long get_full_dynamic_power(unsigned long busy_time, unsigned long total_time,
	unsigned long voltage, unsigned long frequency)
{
	int i;
	unsigned long volt = voltage / 1000;  /* mV */
	int load = 100 * busy_time / total_time;
	s64 v_scale = 0;
	s64 load_exp = 1;
	s64 dynamic_cap = 0;
	int ret = 0;

	for (i = 0; i < voltage_scale_num - 1; i++) {
		v_scale += volt_scale[i] * load_exp;
		load_exp *= load;
	}
	v_scale = (v_scale < 0) ? 0 : v_scale;
	v_scale = v_scale / 10000 * volt / volt_scale[voltage_scale_num - 1];

	load_exp = 1;
	for (i = 0; i < dyn_cap_item_num / 2 - 1; i++)
		load_exp *= load;

	for (i = 0; i < dyn_cap_item_num / 2; i++) {
		dynamic_cap += load_exp * dyn_cap[i];
		dynamic_cap /= dyn_cap[i + dyn_cap_item_num / 2];
		load_exp /= load;
	}
	dynamic_cap = (dynamic_cap < 0) ? 0 : dynamic_cap;

	return ((frequency * v_scale * v_scale / 1000000) * dynamic_cap) / 10000000;
}
#endif

#endif
