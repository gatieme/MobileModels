/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#ifndef HVGR_CQ_DEBUG_SWITCH_H
#define HVGR_CQ_DEBUG_SWITCH_H

#include "hvgr_defs.h"

#define CQ_DEBUG_BUFF_LEN                    100
#define CQ_WORK_MODE_DEBUG                   0x1
#define CQ_WORK_MODE_NORMAL                  0x0
#define CQ_ENABLE_TIMEOUT_SWITCH             0x1
#define CQ_DISABLE_TIMEOUT_SWITCH            0x0
#define CQ_DISABLE_MULTI_CHAIN               0x1
#define CQ_ENABLE_MULTI_CHAIN                0x0
#define CQ_BIND_WAITCYCLE_DEFAULT            0x400
#define CQ_AFFITNITY_DEFAULT                 0xFF
#define CQ_DEBUGFS_NAME_LEN_MAX              32

#define cq_get_u32_bit4(value)               (((value) >> 4) & 1)
#define cq_set_u32_bit4(data, value)         data = (((data) & 0xffffffef) | ((value) << 4))

struct hvgr_cq_debugfs_files {
	char name[CQ_DEBUGFS_NAME_LEN_MAX];
	umode_t mode;
	const struct file_operations *fops;
};

int hvgr_cq_debugfs_init(struct hvgr_device * const gdev);

#endif
