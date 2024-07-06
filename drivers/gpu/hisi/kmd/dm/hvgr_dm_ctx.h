/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#ifndef HVGR_DM_CTX_H
#define HVGR_DM_CTX_H

#include "hvgr_defs.h"

struct hvgr_ctx *hvgr_open_context(struct hvgr_device * const gdev,
	struct file *kfile);

void hvgr_close_context(struct hvgr_ctx * const ctx);

#endif
