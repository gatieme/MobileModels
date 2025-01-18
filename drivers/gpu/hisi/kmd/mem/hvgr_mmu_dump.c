/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#include "hvgr_mmu_api.h"

#include <linux/kernel.h>
#include <linux/mm.h>
#include <linux/highmem.h>
#include <linux/slab.h>
#include <linux/statfs.h>
#include <linux/uaccess.h>

#include "hvgr_regmap.h"
#include "hvgr_kmd_defs.h"
#include "hvgr_mmu_entry.h"
#include "hvgr_mmu_struct.h"
#include "hvgr_log_api.h"
#include "hvgr_fcp.h"

#define MMU_FILE_MODE 0644

static void hvgr_mmu_dump_level(struct hvgr_ctx * const ctx, phys_addr_t entry, uint32_t level,
	struct file *data_file, loff_t *pos)
{
	union hvgr_mmu_entry *entry_buf = NULL;
	uint32_t i;
	uint32_t len;
	uint64_t header;

	entry_buf = kmap(phys_to_page(entry));
	if (entry_buf == NULL) {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u MMU dump: kmap fail level%u entry=0x%lx",
			ctx->id, level, entry);
		return;
	}

	header = entry | level;
	len = (uint32_t)sizeof(header);
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
	if (len != vfs_write(data_file, (char *)&header, len, pos)) {
#else
	if (len != (uint32_t)kernel_write(data_file, (char *)&header, len, pos)) {
#endif
		hvgr_err(ctx->gdev, HVGR_MEM,
			"ctx_%u MMU dump: write header fail level%u entry=0x%lx",
			ctx->id, level, entry);
		kunmap(phys_to_page(entry));
		return;
	}

	len = PAGE_SIZE;
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
	if (len != vfs_write(data_file, (char *)entry_buf, len, pos)) {
#else
	if (len != (uint32_t)kernel_write(data_file, (char *)entry_buf, len, pos)) {
#endif
		hvgr_err(ctx->gdev, HVGR_MEM,
			"ctx_%u MMU dump: write body fail level%u entry=0x%lx",
			ctx->id, level, entry);
		kunmap(phys_to_page(entry));
		return;
	}

	if (level >= MMU_LEVEL_3)
		goto done;

	for (i = 0; i < MMU_ENTRY_NUM; i++) {
		if (hvgr_mmu_entry_is_table(&entry_buf[i], level)) {
			phys_addr_t next_entry = entry_to_phys(&entry_buf[i]);

			hvgr_mmu_dump_level(ctx, next_entry, level + 1, data_file, pos);
		}
	}

done:
	kunmap(phys_to_page(entry));
}

long hvgr_mmu_dump(struct hvgr_ctx * const ctx, char *file_path, bool is_fcp)
{
	struct file *data_file = NULL;
	mm_segment_t old_fs;
	loff_t pos = 0;
	uint64_t pgd_pa;
	struct hvgr_fcp_data *fcp_data = NULL;
	struct hvgr_ctx *ctx_fcp = NULL;

	if (ctx == NULL || file_path == NULL)
		return -1;

	old_fs = get_fs();
	set_fs(KERNEL_DS);

	data_file = filp_open(file_path, O_CREAT | O_WRONLY | O_TRUNC, MMU_FILE_MODE);
	if (IS_ERR(data_file)) {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u dump mmu open file fail file_path(%s)",
			ctx->id, file_path);
		set_fs(old_fs);
		return -1;
	}

	if (is_fcp) {
		fcp_data = ctx->gdev->dm_dev.fcp_data;
		ctx_fcp = fcp_data->ctx;
		pgd_pa = ctx_fcp->mem_ctx.pgd_pa;
	} else {
		pgd_pa = ctx->mem_ctx.pgd_pa;
	}

	mutex_lock(&ctx->mem_ctx.mmu_mutex);
	hvgr_mmu_dump_level(ctx, pgd_pa, MMU_LEVEL_0, data_file, &pos);
	mutex_unlock(&ctx->mem_ctx.mmu_mutex);

	(void)vfs_fsync(data_file, 0);
	(void)filp_close(data_file, NULL);
	set_fs(old_fs);

	return 0;
}

