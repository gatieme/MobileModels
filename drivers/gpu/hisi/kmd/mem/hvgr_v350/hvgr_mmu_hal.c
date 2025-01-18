/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */
#include <linux/kernel.h>
#include <linux/bitops.h>

#include "hvgr_regmap.h"
#include "hvgr_kmd_defs.h"
#include "hvgr_dm_api.h"
#include "hvgr_mmu_base.h"
#include "hvgr_mmu_struct.h"
#include "hvgr_mmu_driver.h"
#include "dm/fcp/hvgr_fcp.h"
#include "hvgr_mem_api.h"
#include "hvgr_mmu_api.h"
#include "hvgr_log_api.h"
#include "hvgr_datan_api.h"

long hvgr_mmu_hal_enable(struct hvgr_ctx *ctx)
{
	int ret;
	ctx->ssid = ctx->asid;
	ret = hvgr_mmu_init_cd(ctx);
	if (ret != 0) {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u mmu init cd failed %u", ctx->id, ctx->ssid);
		return ret;
	}

	datan_jobtrace_global_reg_dump(ctx);
	datan_jobtrace_upgrade_fw(ctx);

	hvgr_mmu_set_cd_valid(ctx, true);

	ret = hvgr_mmu_cmdq_cd_invalid(ctx, ctx->gdev, ctx->ssid);
	if (ret != 0) {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u mmu cmdq invalid cd failed %u", ctx->id, ctx->ssid);
		return ret;
	}

	hvgr_datan_jobtrace(ctx, JOBTRACE_TYPE_OBJ, KDATAN_JD_DUMP_CD, ctx);

	return hvgr_mmu_cmdq_tlb_invalid_asid(ctx, ctx->gdev, ctx->asid);
}

long hvgr_mmu_hal_flush_pt(struct hvgr_ctx *ctx, uint64_t gva, uint32_t pages)
{
	return hvgr_mmu_cmdq_tlb_invalid_va(ctx, ctx->gdev, ctx->asid, gva, pages);
}

long hvgr_mmu_hal_disable(struct hvgr_ctx *ctx)
{
	int ret;

	hvgr_mmu_set_cd_valid(ctx, false);

	ret = hvgr_mmu_cmdq_tlb_invalid_asid(ctx, ctx->gdev, ctx->asid);
	if (ret != 0) {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u mmu cmdq invalid asid failed %u", ctx->id, ctx->asid);
		return ret;
	}

	ret = hvgr_mmu_cmdq_cd_invalid(ctx, ctx->gdev, ctx->ssid);
	if (ret != 0) {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u mmu cmdq invalid cd failed %u", ctx->id, ctx->ssid);
		return ret;
	}

	return ret;
}

void hvgr_mmu_cbit_config(struct hvgr_device *gdev)
{
	hvgr_mmu_global_reg_init(gdev);
}

void hvgr_mmu_flush_l2_caches(struct hvgr_device *gdev)
{
	return;
}

