/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#ifndef HVGR_MMU_STRUCT_H
#define HVGR_MMU_STRUCT_H

#include <linux/types.h>

#define MMU_PTW_SH_MEMATTR_OUT_SHAREABLE            2
#define MMU_PTW_MEMATTR_NON_CACHEABLE               ((u32)0xCC)

#define HVGR_PACKED __attribute__((packed))

union hvgr_mmu_context_descriptor {
	uint32_t value[8];
	struct {
		uint32_t adrmode : 2;
		uint32_t valid : 1;
		uint32_t ptw_memattr : 8;
		uint32_t ptw_sh : 2;
		uint32_t ptw_pbha : 4;
		uint32_t affd : 1;
		uint32_t rsv1 : 1;
		uint32_t write_execute_never : 1;
		uint32_t rsv2 : 12;
		uint32_t asid : 8;
		uint32_t rsv3 : 24;
		uint32_t ttb0_l;
		uint32_t ttb0_h : 8;
		uint32_t rsv4 : 24;
		uint64_t memattr;
	} st;
};

#define MMU_CMD_CFGI_CD         0x05
#define MMU_CMD_CFGI_CD_ALL     0x06
#define MMU_CMD_TLBI_NH_ALL     0x10
#define MMU_CMD_TLBI_NH_ASID    0x11
#define MMU_CMD_TLBI_NH_VA      0x12
#define MMU_CMD_RESUME          0x44
#define MMU_CMD_SYNC            0x46

struct hvgr_mmu_cmd_cfgi_cd {
	uint32_t reserve1 : 8;
	uint32_t ssid : 12;
	uint32_t reserve2 : 4;
	uint32_t reserve3[3];
} HVGR_PACKED;

struct hvgr_mmu_cmd_tlbi_nh_asid {
	uint32_t reserve1 : 8;
	uint32_t asid : 8;
	uint32_t reserve2 : 8;
	uint32_t reserve3[3];
} HVGR_PACKED;

struct hvgr_mmu_cmd_tlbi_nh_va {
	uint32_t reserve1 : 8;
	uint32_t asid : 8;
	uint32_t reserve2 : 8;
	uint32_t reserve3;
	uint32_t va_start : 27;
	uint32_t granule : 2;
	uint32_t reserve4 : 3;
	uint32_t va_end : 27;
	uint32_t reserve5 : 5;
} HVGR_PACKED;

struct hvgr_mmu_cmd_resume {
	uint32_t reserve1 : 8;
	uint32_t asid : 8;
	uint32_t reserve2 : 8;
	uint32_t reserve3;
	union {
		uint32_t stag;
		struct {
			uint32_t reserve4 : 20;
			uint32_t level : 2;
			uint32_t cacheline_idx : 10;
		} stag_detail;
	} stag_info;
	uint32_t reserve5;
} HVGR_PACKED;

struct hvgr_mmu_cmd_info {
	uint32_t opcode : 8;
	union {
		struct hvgr_mmu_cmd_cfgi_cd cdi;
		struct hvgr_mmu_cmd_tlbi_nh_asid tlbi_asid;
		struct hvgr_mmu_cmd_tlbi_nh_va tlbi_va;
		struct hvgr_mmu_cmd_resume resume;
	} op_data;
} HVGR_PACKED;

#define MMU_EVENT_C_BAD_STE         0x04
#define MMU_EVENT_C_BAD_CD          0x0a
#define MMU_EVENT_F_TRANSLATION     0x10
#define MMU_EVENT_F_ACCESS          0x12
#define MMU_EVENT_F_PERMISSION      0x13
#define MMU_EVENT_MEMATTR_IDX       0xe0

struct hvgr_mmu_event_c_bad_ste {
	uint32_t reserve1 : 8;
	uint32_t ssid : 12;
	uint32_t reserve2 : 4;
	uint32_t reserve3[2];
} HVGR_PACKED;

struct hvgr_mmu_event_c_bad_cd {
	uint32_t reserve1 : 8;
	uint32_t ssid : 12;
	uint32_t reserve2 : 4;
	uint32_t err_type : 1;
	uint32_t reserve3 : 31;
	uint32_t reserve4;
} HVGR_PACKED;

struct hvgr_mmu_event_common {
	uint32_t asid : 8;
	uint32_t ssid : 12;
	uint32_t reserve1 : 4;
	uint32_t reserve2;
	union {
		uint32_t stag;
		struct {
			uint32_t reserve4 : 20;
			uint32_t level : 2;
			uint32_t cacheline_idx : 10;
		} stag_detail;
	} stag_info;
} HVGR_PACKED;

struct hvgr_mmu_event_info {
	uint32_t opcode : 8;
	union {
		struct hvgr_mmu_event_c_bad_ste bad_ste;
		struct hvgr_mmu_event_c_bad_cd bad_cd;
		struct hvgr_mmu_event_common translation;
		struct hvgr_mmu_event_common faccess;
		struct hvgr_mmu_event_common permission;
		struct hvgr_mmu_event_common memattr;
	} op_data;
	uint32_t reserve1[2];
	uint32_t utlb_id : 4;
	uint32_t source_id : 5;
	uint32_t stream_id : 5;
	uint32_t access_type : 2;
	uint32_t mem_info : 3;
	uint32_t reserve2 : 13;
	uint32_t va : 27;
	uint32_t jasid : 3;
	uint32_t reserve3 : 2;
	uint32_t reserve4;
} HVGR_PACKED;


// combine with v300 todo

/*
 * 4K:
 * | 38 ~ 30 | 29 ~ 21 | 20 ~ 12 | 11 ~ 0
 *     L1         L2        L3      offset
 *
 * 16K:
 * | 38 ~ 36 | 35 ~ 25 | 24 ~ 14 | 13 ~ 0
 *     L1         L2        L3      offset
 *
 * 64K:
 * | 38 ~ 29 | 28 ~ 16 | 15 ~ 0
 *     L2         L3       offset
 */
#define MMU_LEVEL_0 0u
#define MMU_LEVEL_1 0u
#define MMU_LEVEL_2 1u
#define MMU_LEVEL_3 2u
#define MMU_LEVEL_NUM 3u

#define HVGR_PAGE_SHIFT 12u /* 4K */
#define HVGR_PAGE_SIZE (1u << HVGR_PAGE_SHIFT)
#define MMU_ENTRY_SIZE 8u
#define MMU_ENTRY_NUM (HVGR_PAGE_SIZE / MMU_ENTRY_SIZE)
#define MMU_PTE_MASK (MMU_ENTRY_NUM - 1)

#define va_to_vpfn(va) ((va) >> HVGR_PAGE_SHIFT)
/* (HVGR_PAGE_SHIFT - 3) is each level bit nums for 4k/16k/64k */
#define mmu_level_offset(level) ((MMU_LEVEL_3 - (level)) * (HVGR_PAGE_SHIFT - 3))
#define mmu_get_level_idx(vpfn, level) (((vpfn) >> mmu_level_offset(level)) & MMU_PTE_MASK)

/* 16k/64k phy addr must be aligned, so shift 12 is correct */
#define entry_to_phys(p_entry) (((uint64_t)((p_entry)->entry.addr)) << 12)
#define entry_to_page(p_entry) (phys_to_page(entry_to_phys(p_entry)))

static inline bool is_64k_granule(void)
{
	return (HVGR_PAGE_SHIFT == 16u);
}

union hvgr_mmu_entry {
	struct {
		uint64_t flag : 2;
		uint64_t attr_idx : 3;
		uint64_t ignore1 : 1;
		uint64_t access_permisions : 2;
		uint64_t share_ablility : 2;
		uint64_t access_flag : 1;
		uint64_t ignored2 : 1;
		/*
		 * PA bit[0:35].
		 * PA mode/PBHA mode cfg in flag cfg func, not in addr area.
		 * PA mode: bit[36:43] GID. The PBHA area bit[59:62] rsvd.
		 * bit	43	42	41	40	39	38	37	36
		 *		G7	G6	G5	G4	G3	G2	G1	G0
		 * PBHA mode: bit[40:43] GID4-7, bit[59:62] GID0-3.
		 * bit	62	61	60	59 ... 43  42  41  40
		 *		G3	G2	G1	G0	   G7  G6  G5  G4
		 * 16K/64K bit[13:12]/[15:12] are rsved, the phy addr must be aligned,
		 * so the rsved bits are zero, can be shift by 12 to get phy addr correctlly.
		 */
		uint64_t addr : 24;
	} entry;
	uint64_t value;
};


#endif