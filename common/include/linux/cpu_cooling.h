/* SPDX-License-Identifier: GPL-2.0-only */
/*
 *  linux/include/linux/cpu_cooling.h
 *
 *  Copyright (C) 2012	Samsung Electronics Co., Ltd(http://www.samsung.com)
 *  Copyright (C) 2012  Amit Daniel <amit.kachhap@linaro.org>
 *
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */

#ifndef __CPU_COOLING_H__
#define __CPU_COOLING_H__

#include <linux/of.h>
#include <linux/thermal.h>
#include <linux/cpumask.h>

struct cpufreq_policy;

#ifdef CONFIG_CPU_FREQ_THERMAL
#ifdef CONFIG_HW_IPA_THERMAL
typedef int (*get_static_t)(cpumask_t *cpumask, int interval,
			    unsigned long voltage, unsigned long freq_mhz,
			    u32 *power);
#endif

/**
 * cpufreq_cooling_register - function to create cpufreq cooling device.
 * @policy: cpufreq policy.
 */
struct thermal_cooling_device *
cpufreq_cooling_register(struct cpufreq_policy *policy);

/**
 * cpufreq_cooling_unregister - function to remove cpufreq cooling device.
 * @cdev: thermal cooling device pointer.
 */
void cpufreq_cooling_unregister(struct thermal_cooling_device *cdev);

/**
 * of_cpufreq_cooling_register - create cpufreq cooling device based on DT.
 * @policy: cpufreq policy.
 */
struct thermal_cooling_device *
of_cpufreq_cooling_register(struct cpufreq_policy *policy);

#ifdef CONFIG_HW_IPA_THERMAL
struct thermal_cooling_device *
of_cpufreq_power_cooling_register(struct device_node *np,
				  struct cpufreq_policy *policy,
				  u32 *capacitance,
				  get_static_t plat_static_func);
#endif
#else /* !CONFIG_CPU_FREQ_THERMAL */
static inline struct thermal_cooling_device *
cpufreq_cooling_register(struct cpufreq_policy *policy)
{
	return ERR_PTR(-ENOSYS);
}

static inline
void cpufreq_cooling_unregister(struct thermal_cooling_device *cdev)
{
	return;
}

static inline struct thermal_cooling_device *
of_cpufreq_cooling_register(struct cpufreq_policy *policy)
{
	return NULL;
}

#ifdef CONFIG_HW_IPA_THERMAL
struct thermal_cooling_device *
of_cpufreq_power_cooling_register(struct device_node *np,
				  struct cpufreq_policy *policy,
				  u32 *capacitance,
				  get_static_t plat_static_func)
{
	return NULL;
}
#endif
#endif /* CONFIG_CPU_FREQ_THERMAL */

struct cpuidle_driver;

#ifdef CONFIG_CPU_IDLE_THERMAL
void cpuidle_cooling_register(struct cpuidle_driver *drv);
#else /* CONFIG_CPU_IDLE_THERMAL */
static inline void cpuidle_cooling_register(struct cpuidle_driver *drv)
{
}
#endif /* CONFIG_CPU_IDLE_THERMAL */

#endif /* __CPU_COOLING_H__ */
