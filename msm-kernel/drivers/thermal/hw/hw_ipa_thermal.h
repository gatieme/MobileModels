/*
 * Huawei ipa thermal header
 *
 * Copyright (c) 2022-2022 Huawei Technologies Co., Ltd.
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
#ifndef HW_IPA_THERMAL_H
#define HW_IPA_THERMAL_H

#include <linux/cpu_cooling.h>
#include <linux/debugfs.h>
#include <linux/cpufreq.h>
#include <linux/cpumask.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/thermal.h>
#include <linux/topology.h>
#include <trace/events/thermal_power_allocator.h>
#include <trace/events/thermal.h>
#include <linux/version.h>
#include <linux/slab.h>
#include <linux/cpu.h>
#include <linux/kthread.h>
#include <uapi/linux/sched/types.h>
#include <securec.h>
#include <linux/of_platform.h>
#include <linux/sched/task.h>

#ifdef CONFIG_HW_THERMAL_SPM
#include <linux/string.h>
#endif
#include <linux/hw/hw_thermal.h>

#define IPA_SENSOR	"tsens_max"
#define IPA_SENSOR_SYSTEM_H	"system_h"
#define IPA_SENSOR0_NAME "ipa-sensor@0"
#define IPA_SENSOR1_NAME "ipa-sensor@1"
#define IPA_SENSOR_MAXID	255
#define IPA_INIT_OK	0x05a5a5a5b
#define IPA_SOC_INIT_TEMP	85000
#ifdef CONFIG_HW_THERMAL_SPM
#define MAX_SHOW_STR	5
#endif
#ifdef CONFIG_HW_THERMAL_SHELL
#define NUM_SENSORS	3
#else
#define NUM_SENSORS	2
#endif
#define NUM_TEMP_SCALE_CAPS	5
#define NUM_TZD	2
#define NUM_BOARD_CDEV	3
#define FREQ_BUF_LEN	11UL
#define DECIMAL	10
#define NUM_CAPACITANCES	5
#define MAX_DEV_NUM 40

typedef int (*ipa_get_sensor_id_t)(const char *);

#ifdef CONFIG_HW_THERMAL_SPM
struct spm_t {
	struct device *device;
	bool spm_mode;
	bool vr_mode;
};
#endif

enum {
	SOC = 0,
	BOARD
};

enum {
	HOTPLUG_NONE = 0,
	HOTPLUG_NORMAL,
	HOTPLUG_CRITICAL
};

enum {
	PROFILE_SPM = 0,
	PROFILE_VR,
	PROFILE_MIN
};

struct capacitances {
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
	u32 cluster_dyn_capacitance[CAPACITY_OF_ARRAY][CAPACITY_OF_ARRAY];
	s64 cluster_static_capacitance[CAPACITY_OF_ARRAY][CAPACITY_OF_ARRAY];
#else
	u32 cluster_dyn_capacitance[CAPACITY_OF_ARRAY];
	u32 cluster_static_capacitance[CAPACITY_OF_ARRAY];
#endif
	u32 cache_capacitance[CAPACITY_OF_ARRAY];
	const char *temperature_scale_capacitance[NUM_TEMP_SCALE_CAPS];
	bool initialized;
};

struct ipa_sensor {
	u32 sensor_id;
	s32 prev_temp;
	int alpha;
};

struct ipa_thermal {
	struct ipa_sensor ipa_sensor;
	struct thermal_zone_device *tzd;
	int cdevs_num;
	struct thermal_cooling_device **cdevs;
	struct capacitances *caps;
	int init_flag;
};

struct ipa_sensor_info {
	const char *ipa_sensor_name;
	ipa_get_sensor_id_t ipa_get_sensor_id;
};

#ifdef CONFIG_HW_THERMAL_HOTPLUG
#define MAX_MODE_LEN	15
struct hotplug_t {
	struct device *device;
	int cpu_down_threshold;
	int cpu_up_threshold;
	int critical_cpu_down_threshold;
	int critical_cpu_up_threshold;
	int hotplug_status;
	unsigned int cpu_hotplug_mask;
	unsigned int critical_cpu_hotplug_mask;
	unsigned int control_mask; /* diff mask */
	bool need_down;
	bool need_up;
	long current_temp;
#ifdef CONFIG_HW_HOTPLUG_EMULATION
	int emul_temp;
#endif
	bool cpu_downed;
#ifdef CONFIG_HW_THERMAL_GPU_HOTPLUG
	bool gpu_need_down;
	bool gpu_need_up;
	bool gpu_downed;
	int gpu_down_threshold;
	int gpu_up_threshold;
	unsigned int gpu_limit_cores;
	unsigned int gpu_total_cores;
	long gpu_current_temp;
#endif
#ifdef CONFIG_HW_GPU_HOTPLUG_EMULATION
	int gpu_emul_temp;
#endif
#ifdef CONFIG_HW_THERMAL_NPU_HOTPLUG
	bool npu_need_down;
	bool npu_need_up;
	bool npu_downed;
	int npu_down_threshold;
	int npu_up_threshold;
	unsigned int npu_limit_cores;
	unsigned int npu_total_cores;
	long npu_current_temp;
#endif
#ifdef CONFIG_HW_NPU_HOTPLUG_EMULATION
	int npu_emul_temp;
#endif
	struct task_struct *hotplug_task;
	struct delayed_work poll_work;
	u32 polling_delay;
	u32 polling_delay_passive;
	spinlock_t hotplug_lock;
	bool disabled;
	bool initialized;
};
#endif

struct thermal {
	struct class *hw_thermal_class;
	struct ipa_thermal ipa_thermal[NUM_TZD];
#ifdef CONFIG_HW_THERMAL_SPM
	struct spm_t spm;
#endif
#ifdef CONFIG_HW_THERMAL_HOTPLUG
	struct hotplug_t hotplug;
#endif
};

#ifdef CONFIG_HW_THERMAL_NPU_HOTPLUG
#define NPU_DEV_ID	0
#endif
#endif