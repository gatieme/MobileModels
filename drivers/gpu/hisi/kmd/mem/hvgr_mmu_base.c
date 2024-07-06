/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2022-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#include "hvgr_mmu_base.h"

#include <linux/kernel.h>
#include <linux/highmem.h>
#include <linux/mm.h>
#include <securec.h>

#include "hvgr_regmap.h"
#include "hvgr_mem_api.h"
#include "hvgr_mmu_entry.h"
#include "hvgr_mmu_struct.h"
#include "hvgr_mem_pool.h"
#include "hvgr_log_api.h"

void hvgr_mmu_sync_pte(struct hvgr_ctx * const ctx, struct page *page, uint32_t offset,
	size_t size)
{
	dma_addr_t dma_addr = hvgr_mem_get_page_dma_addr(page);

	dma_addr += offset;
	if (!hvgr_mem_is_cpu_coherent(ctx->gdev))
		dma_sync_single_for_device(ctx->gdev->dev, dma_addr, size, DMA_TO_DEVICE);
}

uint64_t hvgr_mmu_alloc_entry(struct hvgr_ctx * const ctx)
{
	union hvgr_mmu_entry *pt = NULL;
	struct page *page = NULL;
	uint32_t idx;

	page = hvgr_mem_pool_ctx_alloc_pt(ctx);
	if (page == NULL)
		return 0ULL;

	pt = kmap(page);
	if (pt == NULL) {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u MMU alloc entry fail", ctx->id);
		hvgr_mem_pool_ctx_free_pt(ctx, page);
		return 0ULL;
	}

	for (idx = 0; idx < MMU_ENTRY_NUM; idx++)
		hvgr_mmu_entry_invalid(&pt[idx]);

	hvgr_mmu_sync_pte(ctx, page, 0, PAGE_SIZE);
	kunmap(page);

	ctx->gdev->mem_dev.statics.mmu_alloc_pages++;
	return page_to_phys(page);
}

void hvgr_mmu_free_entry(struct hvgr_ctx * const ctx, phys_addr_t entry)
{
	union hvgr_mmu_entry *pt = NULL;
	struct page *page = phys_to_page(entry);
	uint32_t idx;

	pt = kmap(page);
	if (likely(pt != NULL)) {
		for (idx = 0; idx < MMU_ENTRY_NUM; idx++)
			hvgr_mmu_entry_invalid(&pt[idx]);
		kunmap(page);
	}

	hvgr_mem_pool_ctx_free_pt(ctx, page);
	ctx->gdev->mem_dev.statics.mmu_free_pages++;
}

long hvgr_mmu_grow_pool(struct hvgr_ctx * const ctx, uint32_t nums)
{
	return hvgr_mem_pool_ctx_grow_pt(ctx, nums);
}

