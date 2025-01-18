/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#ifndef HVGR_REGMAP_CQ_H
#define HVGR_REGMAP_CQ_H

/* CQ register */
#define CQ_REG_BASE     0x8000

#define CQ_IRQ_TOP               (0x0)
#define CQ_IRQ_TOP_RAWSTAT       (0x10)
#define CQ_IRQ_TOP_CLEAR         (0x14)
#define CQ_IRQ_TOP_MASK          (0x18)
#define CQ_IRQ_TOP_STATUS        (0x1c)
#define CQ_ENABLE                (0x30)
#define CQ_DBG_EN                (0x34)
#define CQ_QM_NUM                (0x38)
#define CQ_JOBCHANIN_SEND_MODE   (0x3c)
#define CQ_ENTRY_DONE_BUF_EN     (0x4c)
#define CQ_SEM_WAIT_POLLING_MODE (0x50)
#define CQ_ENTRYS_WEIGHT         (0x5c)
#define CQ_ENTRYS_REALTIME       (0x60)
#define CQ_ENTRYS_OS             (0x64)
#define CQ_BINNING_RAM_SIZE      (0x68)
#define CQ_RENDER_RAM_SIZE       (0x6c)
#define CQ_COMPUTE_RAM_SIZE      (0x70)
#define CQ_BVH_RAM_SIZE          (0x74)
#define CQ_RT_RAM_SIZE           (0x78)
#define CQ_DFX_CONFIG            (0x7c)
#define CQ_MAX_VB_SHARP_COUNT    (0x80)
#define CQ_MAX_RMU_COUNT         (0x84)
#define CQ_MAX_RMU_SLICE_COUNT   (0x88)
#define CQ_INTERNAL_UNIFORM_SIZE (0x8c)
#define CQ_RENDER_NODE_STYPE     (0x90)
#define CQ_MESH_NODE_STYPE       (0x94)
#define CQ_HTS_EVENT_LS_ADDR_L   (0x100)
#define CQ_HTS_EVENT_LS_ADDR_H   (0x104)
#define CQ_HTS_EVENT_CMD         (0x10c)
#define CQ_HTS_EVENT_CMD_DONE    (0x110)
#define COMMON_USE_SSID          (0x120)
#define COMMON_USE_SSID_STATUS   (0x124)
#define GPC_PWR_TIMEOUT          (0x128)
#define CQ_BC_SEND_MODE          CQ_JOBCHANIN_SEND_MODE

/* CQ_DFX_CONFIG */
#define CQ_PRINT_ORDER_EN_BIT         0
#define CQ_PRINT_SYNC_EN_BIT          1
#define CQ_ENTRY_BOUNDARY_EN_BIT      2
#define CQ_VCQ_PASSIVE_MODE_EN_BIT    3
#define CQ_PRINT_ORDER_EN            (1u << CQ_PRINT_ORDER_EN_BIT)
#define CQ_PRINT_SYNC_EN             (1u << CQ_PRINT_SYNC_EN_BIT)
#define CQ_ENTRY_BOUNDARY_EN         (1u << CQ_ENTRY_BOUNDARY_EN_BIT)
#define CQ_VCQ_PASSIVE_MODE_EN       (1u << CQ_VCQ_PASSIVE_MODE_EN_BIT)

#define CQ_SUBMIT                (0x1000)
#define CQ_DOORBELL              (0x1004)
#define CQ_ISSUEQ_CONTEXT_UPDATE (0x1004)

#define cq_hts_wait_event_ram(r)     (0x800 + (r) * 0x4)

#define cq_irq_rawstat(chn)     (0x2000 + (chn) * 0x100)
#define cq_irq_clear(chn)       (0x2004 + (chn) * 0x100)
#define cq_irq_mask(chn)        (0x2008 + (chn) * 0x100)
#define cq_irq_status(chn)      (0x200c + (chn) * 0x100)
#define cq_bind_addr_lo(chn)    (0x2010 + (chn) * 0x100)
#define cq_bind_addr_hi(chn)    (0x2014 + (chn) * 0x100)
#define cq_bind_asid(chn)       (0x2018 + (chn) * 0x100)
#define cq_bind_queue_id(chn)   (0x201c + (chn) * 0x100)

#define cq_bind_aff_bin(chn, n)    (0x2020 + (chn) * 0x100 + (n) * 0x4)
#define cq_bind_config(chn, n)     (0x2040 + (chn) * 0x100 + (n) * 0x4)

#define cq_bind_jd_msb(chn)            (0x2060 + (chn) * 0x100)
#define cq_bind_waitcycle(chn)         (0x2064 + (chn) * 0x100)
#define cq_bind_empty_timeout(chn)     (0x2068 + (chn) * 0x100)
#define cq_bind_sem_wait_timeout(chn)  (0x206c + (chn) * 0x100)

#define cq_bind_cmd(chn)               (0x2080 + (chn) * 0x100)
#define cq_bind_end_flush_l2(chn)      (0x2088 + (chn) * 0x100)

#define cq_bind_entry_exe_status(chn)  (0x2094 + (chn) * 0x100)

#define cq_bind_subchn_os(chn)         (0x20a0 + (chn) * 0x100)

#define cq_bind_subq0_entry_info(chn)  (0x20b0 + (chn) * 0x100)
#define cq_bind_subq1_entry_info(chn)  (0x20b4 + (chn) * 0x100)
#define cq_bind_subq2_entry_info(chn)  (0x20b8 + (chn) * 0x100)
#define cq_bind_subq3_entry_info(chn)  (0x20bc + (chn) * 0x100)
#define cq_bind_subq4_entry_info(chn)  (0x20c0 + (chn) * 0x100)
#define cq_bind_subq5_entry_info(chn)  (0x20c4 + (chn) * 0x100)
#define cq_bind_subq6_entry_info(chn)  (0x20c8 + (chn) * 0x100)
#define cq_bind_subq7_entry_info(chn)  (0x20cc + (chn) * 0x100)

#define cq_bind_top_notify_info(chn)         (0x20d0 + (chn) * 0x100)
#define cq_bind_entry_boundary_info(chn)     (0x20d4 + (chn) * 0x100)

#define CQ_MCU_IRQ_RAWSTAT     (0x4000)
#define CQ_MCU_IRQ_CLEAR       (0x4004)
#define CQ_MCU_IRQ_MASK        (0x4008)
#define CQ_MCU_IRQ_STATUS      (0x400c)

#define cq_bind_status_subq(chn, sub_chn)   \
	(cq_bind_subq0_entry_info(chn) + 4 * (sub_chn))
#define cq_bind_affinity_sub_channel(chn, sub_chn) \
	cq_bind_aff_bin(chn, sub_chn)

#define CQ_SUBMIT_FOR_UMD       (CQ_REG_BASE + 0x1000)

#define CQ_CMD_START    1
#define CQ_CMD_STOP     2

#define CQ_IRQ_STATUS_SUBQ_BIT_START  3
#define CQ_IRQ_STATUS_SUBQ_BIT_NUMS   8
#define CQ_IRQ_STATUS_SUBQ_BIG_MASK \
	(((1 << CQ_IRQ_STATUS_SUBQ_BIT_NUMS) - 1) << CQ_IRQ_STATUS_SUBQ_BIT_START)

#define CQ_IRQ_SYNC_BUF_FULL_BIT    11
#define CQ_IRQ_ORDER_BUF_FULL_BIT   12
#define CQ_IRQ_ENTRY_BOUNDARY_BIT   13

union reg_cq_irq {
	struct {
		uint32_t notify : 1;
		uint32_t stop : 1;

		uint32_t timeout_wait : 1;

		uint32_t subq0 : 1;
		uint32_t subq1 : 1;
		uint32_t subq2 : 1;
		uint32_t subq3 : 1;
		uint32_t subq4 : 1;
		uint32_t subq5 : 1;
		uint32_t subq6 : 1;
		uint32_t subq7 : 1;

		uint32_t sync_buf_full : 1;
		uint32_t order_buf_full : 1;
		uint32_t entry_boundary : 1;
		uint32_t entry_exe_empty : 1;
		uint32_t resv : 17;
	} st;
	uint32_t value;
};

union reg_cq_bind_status_subq {
	struct {
		uint32_t entry_id : 14;
		uint32_t entry_type : 3;
		uint32_t entry_info_vld : 1;
	} st;
	uint32_t value;
};

union reg_cq_bind_status_notify {
	struct {
		uint32_t entry_id : 14;
		uint32_t resv : 2;
		uint32_t hold_en : 1;
		uint32_t entry_info_vld : 1;
	} st;
	uint32_t value;
};

#define CQ_JOB_CHAIN_STATUS_START      (0u)
#define CQ_JOB_CHAIN_STATUS_DONE       (1u)
#define CQ_JOB_CHAIN_STATUS_STOP       (3u)

union reg_cq_bind_status_boundary {
	struct {
		uint32_t entry_id : 14;
		uint32_t entry_type : 3;
		uint32_t entry_info_vld : 1;
		uint32_t job_chain_status : 2;
	} st;
	uint32_t value;
};

union reg_cq_bind_entry_exe_status {
	struct {
		uint32_t hts_wait_status : 1;
		uint32_t sem_wait_status : 1;
		uint32_t fence_en_sem_wait_status : 1;
		uint32_t entry_exe_empty : 1;
		uint32_t queue_entry_empty : 1;
		uint32_t resv : 27;
	} st;
	uint32_t value;
};

#define CQ_BIND_BARRIER_ENABLE        (1u)
#define CQ_BIND_BARRIER_DISABLE       (0u)
#define CQ_BIND_ENDFLUSH_NO                      (0u)
#define CQ_BIND_ENDFLUSH_CLEAN                   (1u)
#define CQ_BIND_ENDFLUSH_CLEAN_AND_INVALIDATE    (3u)

union reg_cq_bind_config {
	struct {
		uint32_t resv1 : 4;
		uint32_t barrier : 1;
		uint32_t resv2 : 3;
		uint32_t end_flush_l2 : 2;
		uint32_t end_flush_shader_type : 4;
		uint32_t end_flush_l1 : 2;
		uint32_t resv3 : 4;
		uint32_t split_order : 1;
	} st;
	uint32_t value;
};

#endif /* HVGR_REGMAP_CQ_H */
