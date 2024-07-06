/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2022-2022.
 * All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */
#ifndef HVGR_EXTERNAL_BASE_H
#define HVGR_EXTERNAL_BASE_H

#include <linux/regulator/consumer.h>

struct hvgr_device;
typedef u32 (*platform_reset_callback)(void *date);

struct hvgr_platform_subsys_ops {
	int (*regulator_enable)(struct regulator *regulator);
	int (*regulator_disable)(struct regulator *regulator);
	int (*gpufreq_callback_register)(struct hvgr_device *gdev);
	bool (*is_ace_guest)(void);
	unsigned long (*get_gpu_id)(void);
	bool (*pm_is_always_on)(struct hvgr_device * const gdev);
	int (*platform_reset)(void);
	int (*platform_reset_register)(platform_reset_callback callback, void *date);
};

struct hvgr_platform_subsys_ops *hvgr_subsys_ops_get(void);
#endif
