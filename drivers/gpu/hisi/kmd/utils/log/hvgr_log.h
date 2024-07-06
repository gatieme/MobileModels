/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2022-2022. All rights reserved.
 * This file is the dvfs implementation of the PM module.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#ifndef HVGR_LOG_H
#define HVGR_LOG_H
#include <linux/device.h>
#include <linux/types.h>

struct hvgr_log_dev {
	unsigned long log_flag;
	bool dumpstack_flag;
	bool timing_flag;
};

/*
 * enum HVGR_LOG_LEVEL - The types of log level
 */
enum HVGR_LOG_LEVEL {
	HVGR_LOG_INFO,
	HVGR_LOG_ERROR,
	HVGR_LOG_MAX,
};

bool hvgr_log_is_enable(enum HVGR_LOG_LEVEL level, uint32_t module);
char *hvgr_log_get_module_name(uint32_t module);

#define hvgr_log(gdev, module, level, fmt, ...) do { \
	if (hvgr_log_is_enable(level, module)) \
		dev_err(gdev->dev, "[%s] " fmt, hvgr_log_get_module_name(module), ##__VA_ARGS__); \
} while (0)
#endif
