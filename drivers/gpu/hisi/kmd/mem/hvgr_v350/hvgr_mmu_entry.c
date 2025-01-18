/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2021. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */
#include "hvgr_mmu_entry.h"

#include <linux/kernel.h>
#include <linux/mm.h>
#include <linux/slab.h>

#include "hvgr_defs.h"
#include "hvgr_regmap.h"
#include "hvgr_ioctl_mem.h"

#define ENTRY_TYPE_MASK         3ull
#define ENTRY_IS_BLOCK          1ull
#define ENTRY_IS_INVAL          2ull
#define ENTRY_IS_TABLE          3ull
#define ENTRY_IS_PAGE           3ull

#define ENTRY_ATTR_ACE           ((uint64_t)3 << 2)
#define ENTRY_ATTR_OUTER_RW_ALLOCATE ((uint64_t)7 << 2)
#define ENTRY_ATTR_OUTER_RD_ALLOCATE ((uint64_t)6 << 2)
#define ENTRY_ATTR_OUTER_WR_ALLOCATE ((uint64_t)5 << 2)

/* bit[7:6]:01:read/write, 11:readonly, other none */
#define ENTRY_RD_BITS            ((uint64_t)3 << 6)
#define ENTRY_RW_BITS            ((uint64_t)1 << 6)
#define ENTRY_SHARE_BOTH_BITS    ((uint64_t)2 << 8)
#define ENTRY_SHARE_INNER_BITS   ((uint64_t)3 << 8)
#define ENTRY_ACCESS_FLAG_BIT    ((uint64_t)1 << 10)
#define ENTRY_PROT_BIT           ((uint64_t)1 << 42)
#define ENTRY_NX_BIT             ((uint64_t)1 << 54)
#define ENTRY_SPARSE_BITS        ((uint64_t)1 << 63)
#define ENTRY_GID_BIT_START      36U
#define ENTRY_GID_MASK           ((uint64_t)0xFF << ENTRY_GID_BIT_START)    /* bits 36:43 */
#define ENTRY_PBHA_BIT0_3_START  59U
#define ENTRY_PBHA_BIT0_3_MASK   ((uint64_t)0xF << ENTRY_PBHA_BIT0_3_START)    /* bits 59:62 */
#define ENTRY_PBHA_BIT4_7_START  40U
#define ENTRY_PBHA_BIT4_7_MASK   ((uint64_t)0xF << ENTRY_PBHA_BIT4_7_START)    /* bits 40:43 */

/*
 * Next level table address
 * 4K£ºbit[38:12]--nxt table addr
 * 16K£ºbit[38:14]--nxt table addr£¬bit[13:12]--rsv
 * 64K£ºbit[38:16]--nxt table addr£¬bit[15:12]--rsv
 * the phy addr mast be 4k/16k/64k aligned, so just mask bit[0~11]
 */
#define TABLE_RESERVED_MASK ((((uint64_t)0xFFFFF) << 44) | (uint64_t)0xFFF)

#define PAGE_BLOCK_RESERVED_MASK (((uint64_t)0xF << 55) | ((uint64_t)0x3FF << 44))

#ifdef HVGR_FEATURE_SYSTEM_CACHE
void hvgr_mmu_clear_sc_flag(struct hvgr_device *gdev, uint64_t *flag)
{
	if (gdev->mem_dev.sc_data.pbha_mode != 0)
		*flag &= (~(ENTRY_PBHA_BIT0_3_MASK | ENTRY_PBHA_BIT4_7_MASK));
	else
		*flag &= (~ENTRY_GID_MASK);
}

void hvgr_mmu_set_sc_flag(struct hvgr_device *gdev, uint64_t *flag, uint32_t sc_id)
{
	if (gdev->mem_dev.sc_data.pbha_mode != 0) {
		*flag |= ((uint64_t)(sc_id & 0xFu) << ENTRY_PBHA_BIT0_3_START);
		*flag |= ((uint64_t)((sc_id >> 4u) & 0xFu) << ENTRY_PBHA_BIT4_7_START);
	} else {
		*flag |= ((uint64_t)(sc_id & 0xFFu) << ENTRY_GID_BIT_START);
	}
}
#endif

uint64_t hvgr_mmu_get_flags(struct hvgr_device *gdev, uint64_t attr)
{
	uint64_t flag;

	if ((attr & HVGR_MEM_ATTR_OUTER_RD_ALLOCATE) != 0 &&
		(attr & HVGR_MEM_ATTR_OUTER_WR_ALLOCATE) != 0)
		flag = ENTRY_ATTR_OUTER_RW_ALLOCATE;
	else if ((attr & HVGR_MEM_ATTR_OUTER_RD_ALLOCATE) != 0)
		flag = ENTRY_ATTR_OUTER_RD_ALLOCATE;
	else if ((attr & HVGR_MEM_ATTR_OUTER_WR_ALLOCATE) != 0)
		flag = ENTRY_ATTR_OUTER_WR_ALLOCATE;
	else if ((attr & HVGR_MEM_ATTR_GPU_CACHEABLE) != 0)
		flag = ENTRY_ATTR_ACE;
	else
		flag = 0u;

	if ((attr & HVGR_MEM_ATTR_GPU_WR) != 0)
		flag |= ENTRY_RW_BITS;
	else if ((attr & HVGR_MEM_ATTR_GPU_RD) != 0)
		flag |= ENTRY_RD_BITS;

	flag |= (attr & HVGR_MEM_ATTR_GPU_EXEC) ? 0 : ENTRY_NX_BIT;
	flag |= (attr & HVGR_MEM_ATTR_MEM_SPARSE) ? ENTRY_SPARSE_BITS : 0;
#ifdef HVGR_FEATURE_SYSTEM_CACHE
	hvgr_mmu_set_sc_flag(gdev, &flag, hvgr_mem_get_sc_id(attr));
#endif
	flag |= (attr & HVGR_MEM_ATTR_COHERENT_SYSTEM) ? ENTRY_SHARE_BOTH_BITS : 0;
	flag |= ((attr & HVGR_MEM_ATTR_COHERENT_SYSTEM) == 0 &&
		(attr & HVGR_MEM_ATTR_COHERENT_LOCAL) != 0) ? ENTRY_SHARE_INNER_BITS : 0;

	return flag;
}

void hvgr_mmu_entry_invalid(union hvgr_mmu_entry *entry)
{
	entry->value = ENTRY_IS_INVAL;
}

bool hvgr_mmu_entry_is_page(union hvgr_mmu_entry *entry, uint32_t level)
{
	return level == MMU_LEVEL_3 && ((entry->value & ENTRY_TYPE_MASK) == ENTRY_IS_PAGE);
}

bool hvgr_mmu_entry_is_block(union hvgr_mmu_entry *entry, uint32_t level)
{
	return (level == MMU_LEVEL_1 || level == MMU_LEVEL_2) &&
		((entry->value & ENTRY_TYPE_MASK) == ENTRY_IS_BLOCK);
}

bool hvgr_mmu_entry_is_table(union hvgr_mmu_entry *entry, uint32_t level)
{
	return (level == MMU_LEVEL_1 || level == MMU_LEVEL_2) &&
		((entry->value & ENTRY_TYPE_MASK) == ENTRY_IS_TABLE);
}

void hvgr_mmu_entry_set_table(union hvgr_mmu_entry *entry, phys_addr_t phy_addr)
{
	uint64_t value = (phy_addr & ~(TABLE_RESERVED_MASK)) | ENTRY_IS_TABLE;

	entry->value = value;
}

static void hvgr_mmu_entry_set_entry(union hvgr_mmu_entry *entry, struct page *page, uint64_t mmu_flag,
	uint64_t flags, uint64_t entry_type)
{
	uint64_t value = (uint64_t)page_to_phys(page) & PAGE_MASK;
	/*
	 * If ENTRY_SPARSE_BITS is setted before means current page
	 * is sparse zero page. HVGR_MEM_AREA_FLAG_SPARSE_CACHE is set means
	 * current operation is to change the attribute of area, mapping
	 * of zero page will not be modified.
	 */
	if ((entry->value & ENTRY_SPARSE_BITS) != 0 &&
		(flags & HVGR_MEM_AREA_FLAG_SPARSE_CACHE) != 0)
		return;

	value |= mmu_flag;
	value |= entry_type;
	value &= ~(PAGE_BLOCK_RESERVED_MASK);

	entry->value = value;
}

void hvgr_mmu_entry_set_blook(union hvgr_mmu_entry *entry, struct page *page, uint64_t mmu_flag,
	uint64_t flags)
{
	hvgr_mmu_entry_set_entry(entry, page, mmu_flag, flags, ENTRY_IS_BLOCK);
}

void hvgr_mmu_entry_set_page(union hvgr_mmu_entry *entry, struct page *page, uint64_t mmu_flag,
	uint64_t flags)
{
	hvgr_mmu_entry_set_entry(entry, page, mmu_flag, flags, ENTRY_IS_PAGE);
}