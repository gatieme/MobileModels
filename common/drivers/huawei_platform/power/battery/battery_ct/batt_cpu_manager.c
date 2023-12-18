// SPDX-License-Identifier: GPL-2.0
/*
 * batt_cpu_manager.c
 *
 * cpu manager for batt_ct
 *
 * Copyright (c) 2021-2021 Huawei Technologies Co., Ltd.
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

#include "batt_cpu_manager.h"
#include <linux/cpu.h>
#include <linux/version.h>
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
#include <linux/delay.h>
#include <linux/err.h>
#endif /* LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0) */
#include <linux/sched.h>
#include <uapi/linux/sched/types.h>
#include <chipset_common/hwpower/common_module/power_dts.h>
#include <huawei_platform/hwpower/common_module/power_platform.h>

#define HWLOG_TAG batt_cpu_manager
HWLOG_REGIST();

struct batt_cpu_manager {
	struct mutex manager_lock;
	int one_core_id;
};

static struct batt_cpu_manager *g_di;

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
static int batt_cpu_hotplug(bool plug, unsigned int cpu)
{
	int cnt = 20; /* retry count for cpu plug */
	int ret;

	do {
		if (plug)
			ret = add_cpu(cpu);
		else
			ret = remove_cpu(cpu);

		if (ret == -EBUSY) {
			hwlog_info("cpu %d busy\n", cpu);
			usleep_range(5000, 5100); /* delay 5ms for cpu ready */
		} else {
			return ret;
		}
	} while (--cnt > 0);

	return ret;
}
#else
static int batt_cpu_hotplug(bool plug, unsigned int cpu)
{
	int cnt = 3; /* retry count for cpu isolate */
	int ret;

	do {
		if (plug)
			ret = sched_unisolate_cpu(cpu);
		else
			ret = sched_isolate_cpu(cpu);

		if (!ret)
			return ret;
	} while (--cnt > 0);

	return ret;
}
#endif /* LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0) */

static inline bool need_keep_cpu_running(struct batt_cpu_manager *di,
	int cpu_id)
{
	return cpu_id == di->one_core_id;
}

int batt_cpu_single_core_set(void)
{
	int cpu_id;
	int ret;

	if (!g_di) {
		hwlog_err("[%s] g_di NULL\n", __func__);
		return -EINVAL;
	}

	hwlog_info("[%s] begin locking\n", __func__);
	mutex_lock(&g_di->manager_lock);
	hwlog_info("[%s] locking\n", __func__);

	for (cpu_id = 0; cpu_id < BATT_CORE_NUM; cpu_id++) {
		if (need_keep_cpu_running(g_di, cpu_id))
			continue;

		ret = batt_cpu_hotplug(false, cpu_id);
		if (ret) {
			hwlog_err("[%s] cpu down fail, id %d : ret %d\n",
				__func__, cpu_id, ret);
			return ret;
		}
	}
	hwlog_info("[%s] batt_cpu_single_core_set sucess\n", __func__);

	return 0;
}

void batt_turn_on_all_cpu_cores(void)
{
	int cpu_id;
	int ret;

	if (!g_di) {
		hwlog_err("[%s] g_di NULL\n", __func__);
		return;
	}

	for (cpu_id = 0; cpu_id < BATT_CORE_NUM; cpu_id++) {
		if (need_keep_cpu_running(g_di, cpu_id))
			continue;

		ret = batt_cpu_hotplug(true, cpu_id);
		if (ret)
			hwlog_err("[%s] cpu up fail, id %d : ret %d\n",
				__func__, cpu_id, ret);
	}

	mutex_unlock(&g_di->manager_lock);
	hwlog_info("[%s] batt_turn_on_all_cpu_cores end\n", __func__);
}

static void batt_cpu_set_core(struct batt_cpu_manager *di, int core_id)
{
	hwlog_info("[%s] core_id = %d\n", __func__, core_id);
	if ((0 <= core_id) && (core_id < BATT_CORE_NUM))
		di->one_core_id = core_id;
	else
		di->one_core_id = 0;
}

static int batt_cpu_parse_dts(struct batt_cpu_manager *di)
{
	unsigned int core_id = 0;
	struct device_node *batt_info_node = of_find_node_by_name(NULL,
		"huawei_batt_info");

	if (!batt_info_node) {
		hwlog_err("[%s] batt_info_node null\n", __func__);
		return -EINVAL;
	}

	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), batt_info_node,
		"core_id", &core_id, 0);
	batt_cpu_set_core(di, (int)core_id);
	return 0;
}

static int __init batt_cpu_manager_init(void)
{
	int ret;
	struct batt_cpu_manager *di = NULL;

	di = kzalloc(sizeof(struct batt_cpu_manager), GFP_KERNEL);
	if (!di) {
		hwlog_err("[%s] di null\n", __func__);
		return -EINVAL;
	}

	ret = batt_cpu_parse_dts(di);
	if (ret) {
		hwlog_err("[%s] batt_cpu_parse_dts failed %d\n", __func__, ret);
		kfree(di);
		return ret;
	}

	mutex_init(&di->manager_lock);
	g_di = di;
	return 0;
}

static void __exit batt_cpu_manager_exit(void)
{
	kfree(g_di);
	g_di = NULL;
	return;
}

subsys_initcall_sync(batt_cpu_manager_init);
module_exit(batt_cpu_manager_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("batt cpu manager module driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
