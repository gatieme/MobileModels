/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#ifndef HVGR_MMU_DRIVER_H
#define HVGR_MMU_DRIVER_H

#include <linux/kernel.h>
#include "hvgr_regmap.h"
#include "hvgr_mmu_api.h"
#include "hvgr_mmu_struct.h"

#define MMU_CD_INFO_SIZE            (32u)
#define MMU_CD_MAX_CNT              (4096u)
#define MMU_CD_LOG2SIZE             (12u)
#define MMU_CD_CNT_PER_PAGE         (4096 / MMU_CD_INFO_SIZE)
#define MMU_CD_PAGES_CNT            (MMU_CD_MAX_CNT / MMU_CD_CNT_PER_PAGE)
#define MMU_CD_ORDER                (5u)
#define MMU_TTB0_PA_OFFSET_L        (4u)
#define MMU_TTB0_PA_OFFSET_H        (36u)
#define MMU_TTB0_PA_MASK_L          (0xffffffff)
#define MMU_TTB0_PA_MASK_H          (0xff)

#define MMU_CMDQ_INFO_SIZE          (16u)
#define MMU_CMDQ_MAX_CNT            (256u)
#define MMU_CMDQ_LOG2SIZE           (8u)
#define mmu_cmdq_set_wrap(x)        ((x) << MMU_CMDQ_LOG2SIZE)
#define mmu_cmdq_get_idx(x)         ((x) & (0x1ff >> (9 - MMU_CMDQ_LOG2SIZE)))
#define mmu_cmdq_get_wrap(x)        (((x) >> MMU_CMDQ_LOG2SIZE) & 0x1)

#define MMU_EVENTQ_INFO_SIZE        (32u)
#define MMU_EVENTQ_MAX_CNT          (128u)
#define MMU_EVENTQ_LOG2SIZE         (7u)
#define mmu_eventq_set_wrap(x)      ((x) << MMU_EVENTQ_LOG2SIZE)
#define MMU_EVENTQ_IDX_MASK         (0x1ff >> (9 - MMU_EVENTQ_LOG2SIZE))
#define mmu_eventq_get_idx(x)       ((x) & (0x1ff >> (9 - MMU_EVENTQ_LOG2SIZE)))
#define mmu_eventq_get_wrap(x)      (((x) >> MMU_EVENTQ_LOG2SIZE) & 0x1)

struct hvgr_mmu_event_info *hvgr_mmu_get_event(struct hvgr_device * const gdev);

void hvgr_mmu_event_done(struct hvgr_device * const gdev);

int hvgr_mmu_cmdq_resume(struct hvgr_ctx * const ctx, struct hvgr_device * const gdev, uint32_t asid, uint32_t stag);

int hvgr_mmu_init_cd(struct hvgr_ctx *ctx);

int hvgr_mmu_cmdq_tlb_invalid_va(struct hvgr_ctx * const ctx, struct hvgr_device * const gdev, uint32_t asid,
	uint64_t gva, uint32_t pages);

int hvgr_mmu_cmdq_sync(struct hvgr_ctx * const ctx, struct hvgr_device * const gdev);

int hvgr_mmu_global_reg_init(struct hvgr_device * const gdev);

int hvgr_mmu_cmdq_tlb_invalid_asid(struct hvgr_ctx * const ctx, struct hvgr_device * const gdev, uint32_t asid);

int hvgr_mmu_cmdq_cd_invalid(struct hvgr_ctx * const ctx, struct hvgr_device * const gdev, uint32_t ssid);

void hvgr_mmu_set_cd_valid(struct hvgr_ctx *ctx, bool valid);

#endif