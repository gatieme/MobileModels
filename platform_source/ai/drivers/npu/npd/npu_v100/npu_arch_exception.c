/*
 * npu_arch_exception.c
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

#include "npu_arch_exception.h"

int npu_exception_svc_init(struct npu_dev_ctx *dev_ctx)
{
	unused(dev_ctx);
	return 0;
}

void npu_exception_svc_deinit(struct npu_dev_ctx *dev_ctx)
{
	unused(dev_ctx);
	return;
}

void npu_hwts_exception_dump(struct npu_dev_ctx *dev_ctx, u8 exception_type,
	u16 hwts_sq_id, u16 channel_id)
{
	unused(dev_ctx);
	unused(exception_type);
	unused(hwts_sq_id);
	unused(channel_id);
}

void npu_ispnn_exception_dump(struct npu_dev_ctx *dev_ctx, u8 exception_type, u16 channel_id)
{
	(void)(dev_ctx);
	unused(exception_type);
	unused(channel_id);
	return;
}

void npu_timeout_exception_dump(struct npu_dev_ctx *dev_ctx)
{
	(void)(dev_ctx);
	return;
}

int npu_plat_switch_hwts_aicore_pool(struct npu_dev_ctx *dev_ctx,
	struct npu_work_mode_info *work_mode_info, uint32_t power_status)
{
	unused(dev_ctx);
	unused(work_mode_info);
	unused(power_status);
	return 0;
}

void npu_autofs_on(void *autofs_crg_vaddr)
{
	unused(autofs_crg_vaddr);
}

void npu_autofs_off(void *autofs_crg_vaddr)
{
	unused(autofs_crg_vaddr);
}

bool npu_plat_is_support_sc(void)
{
	return false;
}

int npu_pm_init(struct npu_dev_ctx *dev_ctx)
{
	unused(dev_ctx);
	return 0;
}
