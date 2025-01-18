/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#ifndef HVGR_REGMAP_H
#define HVGR_REGMAP_H

#include <linux/types.h>

#include "hvgr_regmap_fcp.h"
#include "hvgr_regmap_cq.h"

/* Begin Register Offsets */
#define GPU_CONTROL_BASE        0x0
#define MISC_CONTROL_BASE       0x2000

#define GPU_ID                  0x000   /* (RO) GPU and revision identifier */
#define GPU_VERSION             0x004   /* (RO) */
#define L2RW_FEATURES           0x008   /* (RO) Level 2 cache features */
#define L2RO_FEATURES           0x00c   /* (RO) Level 2 cache features */
#define GPU_STATUS              0x010   /* (RO) */
#define GPU_PROT_MODE           0x014   /* (WO) */

#define GROUPS_L2_COHERENT      (1 << 0) /* Cores groups are l2 coherent */
#define NUM_L2_SLICES           1       /* One slice L2 */

#define CC_IRQ_RAWSTAT          0x018   /* (RW) */
#define CC_IRQ_CLEAR            0x01C   /* (WO) */
#define CC_IRQ_MASK             0x020   /* (RW) */
#define CC_IRQ_STATUS           0x024   /* (RO) */

#define GPC_PRESENT             0x400   /* (RO) */
#define BL_PRESENT              0x404   /* (RO) */
#define GPC_PWR_STATUS          0x408   /* (RO) */
#define BL_PWR_STATUS           0x40C   /* (RO) */
#define GPC_PWRON_CMD           0x410   /* (WO) */
#define BL_PWRON_CMD            0x414   /* (WO) */
#define GPC_PWROFF_CMD          0x418   /* (WO) */
#define BL_PWROFF_CMD           0x41C   /* (WO) */
#define SOFT_RESET_CMD          0x420   /* (WO) */

#define PWR_KEY                 0x600   /* (RO) */
#define PWR_OVERRIDE0           0x604   /* (RW) */
#define PWR_OVERRIDE1           0x608   /* (RW) */

#define GPU_TRACE_ADDR          0x800   /* (RW) Trace address configuration */
#define GPU_TRACE_DATA          0x804   /* (RW) Trace data configuration */
#define GPU_TRACE_CTRL          0x808   /* (RW) Trace control configuration */
#define GPU_TRACE_STATUS        0x80C   /* (RO) Trace status configuration */

#define GPU_DBG_CFG             0x810   /* (RW) Debug configuration settings */
#define GPU_DBG_STATUS          0x814   /* (RC) Debug status */
#define GPU_DBG_RDATA           0x818   /* (RO) Debug data */

/* MISC REG */
#define misc_control_reg(r)     (MISC_CONTROL_BASE + (r))
#define GPU_IRQ_RAWSTAT         misc_control_reg(0x000)   /* (RW) */
#define GPU_IRQ_CLEAR           misc_control_reg(0x004)   /* (WO) */
#define GPU_IRQ_MASK            misc_control_reg(0x008)   /* (RW) */
#define GPU_IRQ_STATUS          misc_control_reg(0x00C)   /* (RO) */

/* (RO) GPU exception type and fault status */
#define GPU_FAULTSTATUS         misc_control_reg(0x010)
/* (RO) GPU exception fault address, low word */
#define GPU_FAULTDATA0          misc_control_reg(0x014)
/* (RO) GPU exception fault address, high word */
#define GPU_FAULTDATA1          misc_control_reg(0x018)
/* (RO) GPU exception fault info, low word */
#define GPU_FAULTDATA2          misc_control_reg(0x01C)
/* (RO) GPU exception fault info, high word */
#define GPU_FAULTDATA3          misc_control_reg(0x020)
/* (RO) Job slots present */
#define JS_PRESENT              misc_control_reg(0x110)
/* (RO) GPC features */
#define GPC_FEATURES            misc_control_reg(0x114)
/* (RO) Maximum number of threads per core */
#define THREAD_MAX_THREADS      misc_control_reg(0x120)
/* (RO) Maximum workgroup size */
#define THREAD_MAX_WORKGROUP_SIZE misc_control_reg(0x124)
/* (RO) Maximum threads waiting at a barrier */
#define THREAD_MAX_BARRIER_SIZE misc_control_reg(0x128)
/* (RO) Thread features */
#define THREAD_FEATURES         misc_control_reg(0x12C)
/* (RO) Features of job slot 0 */
#define JS0_FEATURES            misc_control_reg(0x130)
/* (RO) Features of job slot 1 */
#define JS1_FEATURES            misc_control_reg(0x134)
/* (RO) Features of job slot 2 */
#define JS2_FEATURES            misc_control_reg(0x138)
/* (RO) Features of job slot 3 */
#define JS3_FEATURES            misc_control_reg(0x13C)
/* (RO) Features of job slot 4 */
#define JS4_FEATURES            misc_control_reg(0x140)
/* (RO) Features of job slot 5 */
#define JS5_FEATURES            misc_control_reg(0x144)
/* (RO) Features of job slot 6 */
#define JS6_FEATURES            misc_control_reg(0x148)
/* (RO) Features of job slot 7 */
#define JS7_FEATURES            misc_control_reg(0x14C)

#define js_features_reg(p, n) \
	gpu_control_reg((p), (JS0_FEATURES + ((u32)(n) << 2)))

#define GPU_COMMAND             misc_control_reg(0x160)   /* (WO) */
#define PWR_CMD_INFO0           misc_control_reg(0x164)
#define PWR_CMD_INFO1           misc_control_reg(0x168)
#define PWR_CMD_STATUS          misc_control_reg(0x16C)

/* (RW) Performance counter memory region base address, low word */
#define PRFCNT_BASE_LO          misc_control_reg(0x170)
/* (RW) Performance counter memory region base address, high word */
#define PRFCNT_BASE_HI          misc_control_reg(0x174)
/* (RW) Performance counter configuration */
#define PRFCNT_CONFIG           misc_control_reg(0x178)
/* (RW) Performance counter enable flags for Job Manager */
#define PRFCNT_JM_EN            misc_control_reg(0x17C)
/* (RW) Performance counter enable flags for shader cores */
#define PRFCNT_GPC_EN           misc_control_reg(0x180)
/* (RW) Performance counter enable flags for tiler */
#define PRFCNT_BTC_EN           misc_control_reg(0x184)
/* (RW) Performance counter enable flags for BVH */
#define PRFCNT_BVH_EN           misc_control_reg(0x188)
/* (RW) Performance counter enable flags for MMU/L2 cache */
#define PRFCNT_MMU_L2_EN        misc_control_reg(0x18C)
/* (RW) Power meter mode dump time interval */
#define PRFCNT_TIME_SPAN        misc_control_reg(0x190)
/* (RW) Power meter mode ep mask register */
#define PRFCNT_EP_MASK          misc_control_reg(0x194)
/* (RO) Cycle counter register */
#define CYCLE_COUNT_LO          misc_control_reg(0x1A0)
#define CYCLE_COUNT_HI          misc_control_reg(0x1A4)
/* (RO) Global time stamp counter */
#define TIMESTAMP_LO            misc_control_reg(0x1A8)
#define TIMESTAMP_HI            misc_control_reg(0x1AC)
/* (RW) Job Manager configuration register (Implementation specific register) */

#define JM_CONFIG               misc_control_reg(0x200)
#define JM_CONFIG_1             misc_control_reg(0x204)
#define JM_CONFIG_2             misc_control_reg(0x208)
#define JM_CONFIG_3             misc_control_reg(0x20C)

/* JM_MISC_CTRL CBIT REG */
/* (RW) Configuration of the L2 cache and MMU */
#define L2_MMU_CONFIG_0         misc_control_reg(0x400)
#define L2_MMU_CONFIG_1         misc_control_reg(0x404)
#define L2_MMU_CONFIG_2         misc_control_reg(0x408)
#define L2_MMU_CONFIG_3         misc_control_reg(0x40C)
/* (RW) BTC core configuration settings */
#define BTC_CONFIG_0            misc_control_reg(0x420)
#define BTC_CONFIG_1            misc_control_reg(0x424)
#define BTC_CONFIG_2            misc_control_reg(0x428)
#define BTC_CONFIG_3            misc_control_reg(0x42C)
#define BTC_CONFIG_4            misc_control_reg(0x430)
#define BTC_CONFIG_5            misc_control_reg(0x434)
#define BTC_CONFIG_6            misc_control_reg(0x438)
#define BTC_CONFIG_7            misc_control_reg(0x43C)
/* (RW) BVH core configuration settings */
#define BVH_CONFIG_0            misc_control_reg(0x440)
#define BVH_CONFIG_1            misc_control_reg(0x444)
#define BVH_CONFIG_2            misc_control_reg(0x448)
#define BVH_CONFIG_3            misc_control_reg(0x44C)
#define BVH_CONFIG_4            misc_control_reg(0x450)
#define BVH_CONFIG_5            misc_control_reg(0x454)
#define BVH_CONFIG_6            misc_control_reg(0x458)
#define BVH_CONFIG_7            misc_control_reg(0x45C)
/* (RW) GPC configuration settings */
#define GPC_CONFIG_0            misc_control_reg(0x480)
#define GPC_CONFIG_1            misc_control_reg(0x484)
#define GPC_CONFIG_2            misc_control_reg(0x488)
#define GPC_CONFIG_3            misc_control_reg(0x48C)
#define GPC_CONFIG_4            misc_control_reg(0x490)
#define GPC_CONFIG_5            misc_control_reg(0x494)
#define GPC_CONFIG_6            misc_control_reg(0x498)
#define GPC_CONFIG_7            misc_control_reg(0x49C)
#define GPC_CONFIG_8            misc_control_reg(0x4A0)
#define GPC_CONFIG_9            misc_control_reg(0x4A4)
#define GPC_CONFIG_10           misc_control_reg(0x4A8)
#define GPC_CONFIG_11           misc_control_reg(0x4AC)
/* (RW) FF TU core configuration settings */
#define FF_CONFIG_0             misc_control_reg(0x4B0)
#define FF_CONFIG_1             misc_control_reg(0x4B4)
#define FF_CONFIG_2             misc_control_reg(0x4B8)
#define FF_CONFIG_3             misc_control_reg(0x4BC)
#define FF_CONFIG_4             misc_control_reg(0x4C0)
#define FF_CONFIG_5             misc_control_reg(0x4C4)
#define FF_CONFIG_6             misc_control_reg(0x4C8)
#define TU_CONFIG_0             misc_control_reg(0x4D0)
/* (RW) XBI configuration settings */
#define CCE_CBI_CBIT            misc_control_reg(0x4E0)

#define JOB_CONTROL_BASE        0x4000

#define JOB_IRQ_STATUS          0x000   /* Interrupt status register */
#define JOB_RJD_OS_CONFIG       0xF00

#define MAX_JOB_SLOT_NR              8
#define MAX_JOB_SLOT_CHAIN_NR        4

#define job_slot_x_reg(p, x, r) \
	((p)->dm_dev.reg_base.job_reg_base + ((x) << 5) + (r))

#define JSX_IRQ_RAWSTAT         0x04
#define JSX_IRQ_MASK            0x08
#define JSX_IRQ_CLEAR           0x0C
#define JSX_IRQ_STATUS          0x10
#define JSX_STOP_COMMAND        0x14

#define job_jc_y_reg(p, y, r) \
	((p)->dm_dev.reg_base.job_reg_base + 0x200 + \
	((y) << 5) + ((y) << 4) + (r))

#define JSX_JCY_HEAD_LO         0x00
#define JSX_JCY_HEAD_HI         0x04
#define JSX_JCY_AFFINITY        0x08
#define JSX_JCY_CONFIG          0x0C
#define JSX_JCY_COMMAND         0x10
#define JSX_JCY_JCD_LO          0x14
#define JSX_JCY_JCD_HI          0x18
#define JSX_JCY_JD_MSB          0x1C
#define JSX_JCY_WAIT_CYCLE      0x20

#define JS_COMMAND_START        0x01
#define JS_N_CONFIG_BARRIER                        (1u << 4)
#define JS_N_CONFIG_END_FLUSH_L2_CLEAN_INVALIDATE  (3u << 8)
#define JS_N_CONFIG_END_FLUSH_L1_CLEAN_INVALIDATE  (3u << 14)
#define JS_CONFIG_END_FLUSH_BINNING                (1u << 10)
#define JS_CONFIG_END_FLUSH_RENDERING              (1u << 11)
#define JS_CONFIG_END_FLUSH_COMPUTE                (1u << 12)
#define JS_CONFIG_END_FLUSH_RAYTRACING             (1u << 13)
#define JS_CONFIG_END_FLUSH_NO_OPERATION            0u
#define JS_CONFIG_END_FLUSH_ALL                    (0xFu << 10)

#define MEMORY_MANAGEMENT_BASE  0x1000

#define MMU_IDR0                0x00
#define MMU_CR0                 0x04
#define MMU_CR1                 0x08
#define MMU_IRQ_MASK            0x0c
#define MMU_IRQ_RAWSTAT         0x10
#define MMU_IRQ_RPT             0x14
#define MMU_IRQ_CLEAR           0x18
#define MMU_CMDQ_BASE_L         0x1c
#define MMU_CMDQ_BASE_H         0x20
#define MMU_CMDQ_PROD           0x24
#define MMU_CMDQ_CONS           0x28
#define MMU_EVENTQ_BASE_L       0x2C
#define MMU_EVENTQ_BASE_H       0x30
#define MMU_EVENTQ_PROD         0x34
#define MMU_EVENTQ_CONS         0x38
#define MMU_CD_BASE_L           0x3c
#define MMU_CD_BASE_H           0x40
#define MMU_CD_CFG              0x44

#define MMU_FEATURES            MMU_IDR0

#define MMU_IRQ_CMD_SYNC_MASK           0x4U
#define MMU_IRQ_EVENTQ_ERR_MASK         0x2U
#define MMU_IRQ_CMDQ_ERR_MASK           0x1U

#define MMU_ADRMODE_4K                  0x0
#define MMU_ADRMODE_16K                 0x1
#define MMU_ADRMODE_64K                 0x2

#define mmu_as_reg(n, r)         (((n) << 7) + (r))
/* (WO) MMU command register for address space n */
#define AS_COMMAND              0x34
/* (RW) Translation table configuration for address space n, low word */
#define AS_TRANSCFG_LO          0x38
/* (RW) Translation Table Base Address for address space n, low word */
#define AS_TRANSTAB_LO          0x40
/* (RW) Translation Table Base Address for address space n, high word */
#define AS_TRANSTAB_HI          0x44

/* (RW) MMU transcfg for address space n, high word */
#define AS_TRANSCFG_HI          0x48
/* (RW) Memory attributes for address space n, low word */
#define AS_MEMATTR_LO           0x50
/* (RW) Memory attributes for address space n, high word */
#define AS_MEMATTR_HI           0x54
/* (RW) Lock region start address for address space n, low word */
#define AS_LOCK_START_ADDR      0x60
/* (RW) Lock region end address for address space n, low word */
#define AS_LOCK_END_ADDR        0x64
/* (RO) MMU fault status register for address space n */
#define AS_FAULTSTATUS          0x68
/* (RO) Fault Address for address space n, low word */
#define AS_FAULTADDRESS_LO      0x70
/* (RO) Fault Address for address space n, high word */
#define AS_FAULTADDRESS_HI      0x74

/* Begin COM register vaulues */
/* GPU_STATUS values */
/* Set if protected mode is active */
#define GPU_STATUS_PROTECTED_MODE_ACTIVE   ((u32)1 << 11)
/* DBGEN wire status */
#define GPU_DBGEN                          ((u32)1 << 12)

/* GPU_PROT_MODE values */
/* Places the GPU in protected mode */
#define GPU_COMMAND_SET_PROTECTED_MODE 0x01

/* CC IRQ flags */
#define GPC_PWRUP_DONE          ((u32)1 << 0)
#define GPC_PWROFF_DONE         ((u32)1 << 8)
#define BL_PWRUP_DONE           ((u32)1 << 16)
#define BL_PWROFF_DONE          ((u32)1 << 17)
/*
 * Set when all cores have finished powering up or down
 * and the power manager is idle.
 */
#define POWER_CHANGED_ALL       ((u32)1 << 18)
/*
 * Set when a reset has completed. Intended to use with SOFT_RESET
 * commands which may take time.
 */
#define RESET_COMPLETED         ((u32)1 << 19)

#define CC_IRQ_REG_ALL          (RESET_COMPLETED)
/* SOFT_RESET_CMD values */
/* Stop all external bus interfaces, and then reset the entire GPU */
#define GPU_COMMAND_SOFT_RESET         0x01

/* GPU IRQ flags */
#define JOB_FAULT               ((u32)1 << 0)
#define CQ_FAULT                ((u32)1 << 1)
#define JMCP_FAULT              ((u32)1 << 2)
#define JMCP_CTRL_FAULT         ((u32)1 << 3)
#define MISC_CTRL_FAULT         ((u32)1 << 4)
#define CYCLECOUNT_DONE         ((u32)1 << 5)
/* Set when a performance count sample has completed. */
#define PRFCNT_SAMPLE_COMPLETED ((u32)1 << 6)
/* Set when a cache clean operation has completed. */
#define CLEAN_CACHES_COMPLETED  ((u32)1 << 7)
/* A GPU Fault has occurred */
#define GPU_FAULT               (JOB_FAULT | \
	CQ_FAULT | JMCP_FAULT | JMCP_CTRL_FAULT | MISC_CTRL_FAULT)

#define GPU_IRQ_MASK_CONFIG (JOB_FAULT | CQ_FAULT | JMCP_FAULT | JMCP_CTRL_FAULT | \
	MISC_CTRL_FAULT | PRFCNT_SAMPLE_COMPLETED | CLEAN_CACHES_COMPLETED)

#define MULTIPLE_GPU_FAULTS     0       /* More than one GPU Fault occurred. */

/* Begin CONFIG register values */
#define BTC_CFG4_TOP_MUX_SEL_2V                 ((u32)1 << 24)
#define GPC_CFG6_LSC_NONGPC_STORE_MASK_DISABLE  ((u32)1 << 5)
#define GPC_CFG6_LSC_PUSH_VTC_GTC_PROP          ((u32)7 << 15)
#define L2_CFG0_MIF_TRACE_DISABLE_BYPASS        ((u32)1 << 8)
#define FCM_CFG0_TIMESTAMP_SEL                  ((u32)1 << 5)
#define FCM_CFG0_TIMESTAMP_OVERRIDE             ((u32)1 << 0)
#define FCM_CFG0_CALL_EN                        ((u32)1 << 17)

/*
 * MMU_IRQ_RAWSTAT register values. Values are valid also for
 * MMU_IRQ_CLEAR, MMU_IRQ_MASK, MMU_IRQ_STATUS registers.
 */
#define MMU_PAGE_FAULT_FLAGS    8

/*
 * Macros returning a bitmask to retrieve page fault or bus error flags from
 * MMU registers
 */
#define mmu_page_fault(n)      ((u32)1 << (n))
#define mmu_bus_error(n)       ((u32)1 << ((n) + MMU_PAGE_FAULT_FLAGS))
#define AS_N_TRANSTAB_LPAE_ADDR_SPACE_MASK   0xfffffff0

/*
 * Begin MMU_CONFIG register values
 */
#define MMU_DIS_IN   ((u32)1 << 1)
#define MMU_DIS_OUT  ((u32)1 << 2)
#define MMU_SC_MODE_OFFSET  10
#define MMU_MEM_ATTRIDX_MASK ((u32)0xFFu << 11)
#define MMU_MEM_ATTRIDX_BITMAP ((u32)0xFFu << 11)

/*
 * Begin AARCH64 MMU TRANSTAB register values
 */
#define AS_TRANSTAB_ADDR_SPACE_MASK   ((u64)0x7ffffffff0u)
#define MMU_HW_OUTA_BITS        40
#define AS_TRANSTAB_BASE_MASK  ((1ULL << MMU_HW_OUTA_BITS) - (1ULL << 4))

/*
 * Begin MMU STATUS register values
 */
#define AS_STATUS_AS_ACTIVE     1

#define AS_EXCEPTION_CODE_OFFSET    15
#define AS_EXCEPTION_CODE_MASK      0xFFu
#define AS_SOURCE_ID_OFFSET         11
#define AS_SOURCE_ID_MASK           0xFu

#define TRANSLATION_FAULT_LOW    0xC1
#define TRANSLATION_FAULT_HIGH   0xC3
#define PERMISSION_FAULT_LOW     0xC9
#define PERMISSION_FAULT_HIGH    0xCB
#define ADDR_SZ_FAULT            0xE4
#define BLOCK_AT_SL_FAULT        0xC5
#define ACCESS_FLAG_FAULT_LOW    0xD9
#define ACCESS_FLAG_FAULT_HIGH   0xDB
#define MEMATTR_INDEX_FAULT_LOW  0xE9
#define MEMATTR_INDEX_FAULT_HIGH 0xEB

#define MMU_ACCESS_TYPE_ATOMIC               0
#define MMU_ACCESS_TYPE_EXECUTE              1
#define MMU_ACCESS_TYPE_READ                 2
#define MMU_ACCESS_TYPE_WRITE                3

/*
 * Begin MMU TRANSCFG register values
 */
#define AS_TRANSCFG_PTW_MEMATTR_MASK              ((u32)0xFF)
#define AS_TRANSCFG_PTW_MEMATTR_NON_CACHEABLE     ((u32)0xCC)
#define AS_TRANSCFG_PTW_MEMATTR_WRITE_BACK        ((u32)0xC7)
#define AS_TRANSCFG_PTW_MEMATTR_SHAREABLE_MASK    ((u32)3 << 17)
#define AS_TRANSCFG_PTW_MEMATTR_OUT_SHAREABLE     ((u32)2 << 17)
#define AS_TRANSCFG_PTW_SC_MASK                   ((u32)0xF << 24)
#define as_transcfg_ptw_sc_id(id)                 ((u32)(id) << 24)

#define AS_TRANSCFG_ADRMODE_UNMAPPED      1
#define AS_TRANSCFG_ADRMODE_IDENTITY      2
#define AS_TRANSCFG_ADRMODE_AARCH64_4K    6
#define AS_TRANSCFG_ADRMODE_AARCH64_16K   7
#define AS_TRANSCFG_ADRMODE_AARCH64_64K   8
#define AS_TRANSCFG_ADRMODE_LEGACY_TABLE  15
#define AS_TRANSCFG_ADRMODE_MASK          0xF
#define AS_TRANSCFG_LPAE_READ_INNER       (1u << 19)

#define AS_MEMATTR_ENTRY_BITS_SIZE      8
/*
 * Begin AS Command Values
 */
#define AS_MMU_COMMAND_DONE     0xFF

/* AS_COMMAND register commands */
#define AS_COMMAND_NOP          0x00    /* NOP Operation */
/* Broadcasts the values in ASn_TRANSTAB and ASn_MEMATTR to all MMUs */
#define AS_COMMAND_UPDATE       0x01
#define AS_COMMAND_LOCK         0x02    /* Issue a lock region command to all MMUs */
#define AS_COMMAND_UNLOCK       0x03    /* Issue a flush region command to all MMUs */
/*
 * Flush all L2 caches then issue a flush region command to all MMUs
 * (deprecated - only for use with T60x)
 */
#define AS_COMMAND_FLUSH        0x04
/* Flush all L2 caches then issue a flush region command to all MMUs */
#define AS_COMMAND_FLUSH_PT     0x04
/*
 * Wait for memory accesses to complete, flush all the L1s cache then
 * flush all L2 caches then issue a flush region command to all MMUs
 */
#define AS_COMMAND_FLUSH_MEM    0x05

/* GPU_COMMAND values */
/* No operation, nothing happens */
#define GPU_COMMAND_NOP                0x00
/* Starts the cycle counter, and system timestamp propagation */
#define GPU_COMMAND_CYCLE_COUNT_START  0x01
/* Stops the cycle counter, and system timestamp propagation */
#define GPU_COMMAND_CYCLE_COUNT_STOP   0x02
/* Config all performance counters */
#define GPU_COMMAND_PRFCNT_CONFIG      0x03
/* Clear all performance counters, setting them all to zero. */
#define GPU_COMMAND_PRFCNT_CLEAR       0x04
/* Sample all performance counters, writing them out to memory */
#define GPU_COMMAND_PRFCNT_SAMPLE      0x05
/* Clean all caches */
#define GPU_COMMAND_CLEAN_CACHES       0x06
/* Clean and invalidate all caches */
#define GPU_COMMAND_CLEAN_INV_CACHES   0x07

#define GPU_FLUSH_BINNING_ENABLE       (1 << 4)
#define GPU_FLUSH_RENDER_ENABLE        (1 << 5)
#define GPU_FLUSH_COMPUTE_ENABLE       (1 << 6)
#define GPU_FLUSH_RAYTRACING_ENABLE    (1 << 7)

#define GPU_FLUSH_ALL_SHADER_TYPE (GPU_FLUSH_BINNING_ENABLE | \
	GPU_FLUSH_RENDER_ENABLE | GPU_FLUSH_COMPUTE_ENABLE | \
	GPU_FLUSH_RAYTRACING_ENABLE)

/* PRFCNT_CONFIG register values */
#define PRFCNT_CONFIG_MODE_SHIFT       0    /* Counter mode position. */
#define PRFCNT_CONFIG_AS_SHIFT         4    /* Address space bitmap position. */
#define PRFCNT_CONFIG_SETSELECT_SHIFT  8    /* Set select position. */
#define PRFCNT_CONFIG_MAXSET_NUM       18    /* Set select num. */

/* The performance counters are disabled */
#define PRFCNT_CONFIG_MODE_OFF         0
/*
 * The performance counters are enabled, but are only written out when a
 * PRFCNT_SAMPLE command is issued using the GPU_COMMAND register
 */
#define PRFCNT_CONFIG_MODE_MANUAL      1
/*
 * The perfromance counters are enabled, perf counters of BTC and SC0(default)
 * will be written out per millisecond
 */
#define PRFCNT_CONFIG_MODE_MANUAL_NOCLEAR   2

#define PRFCNT_CONFIG_MODE_POWER_METER      3

/* checkbit register config in JM_CONFIG_0 */
#define POWER_METER_ENABLE              ((u32)1 << 23)
#define JM_CFG0_JMCP_SELECT_NEW_DMA_IP  ((u32)1 << 24)

/* main clock of power meter */
#define POWER_METER_CLOCK    35000

#define HVGR_PWR_KEY_VALUE             0x2968a819

#define HVGR_ICG_CLK_ON                0x1000

/* AS<n>_MEMATTR values */
#define AS_MEMATTR_AARCH64                    ((u64)0xCCCCCCCCC7CCCCCC)

/*
 * THREAD_* registers
 * THREAD_FEATURES IMPLEMENTATION_TECHNOLOGY values
 */
#define IMPLEMENTATION_SILICON           0
#define IMPLEMENTATION_FPGA              1

/* only v210/v211 effective */
#define SHADER_CONFIG_0_ICG        0
#define SHADER_CONFIG_2_ICG        0
#define SHADER_CONFIG_5_ICG        0
/* End SHADER_CONFIG register */

#define JOB_HEADER_ID_MAX                 0xffff

#define GPU_IRQ_BITMAP 7

#define GPU_FAULT_SET (GPU_FAULT)

#define GPU_CONTROL_BASE_ADDR (GPU_CONTROL_BASE)

#define MMU_STREAM_ID_OFFSET      2u
#define MMU_STREAM_ID_MASK        0x1Fu
#define MMU_UTLB_ID_OFFSET        7u
#define MMU_UTLB_ID_MASK          0xFu
#define MMU_ADRMODE_OFFSET        23u
#define MMU_ADRMODE_MASK          0xFu
#define MMU_MEM_INFO_OFFSET       27u
#define MMU_MEM_INFO_MASK         0x7u

/*
 * Bits 11 of PWR_OVERRIDE0 are bvh clk gate enable, so
 * the power trans number value is 0x800.
 */
#define HVGR_PWR_TRANS_NUM_VALUE 0x800

#define GPU_FAULT_REG_STRIDE 0x20

/* macro stub for v1xx compile */
#define GPU_CONTROL_BASE_BEFORE_V120 0u
#define JOB_CONTROL_BASE_BEFORE_V120 0u
#define MEMORY_MANAGEMENT_BASE_BEFORE_V120 0u
#define JMCP_DTCM_START_ADDR_BEFORE_120 0u
#define JMCP_BASE_BEFORE_120 0u
#define JMCP_MB_MCU_KEY_BEFORE_120 0u
#define JMCP_DMA_CHANEL_BASE_BEFORE_120 0u
#define JMCP_TIMER_LOAD_BASE_BEFORE_120 0u
#define JMCP_UART_LOAD_BASE_BEFORE_120 0u
#define JMCP_UART_LOAD_BASE 0u

static inline bool hvgr_is_job_slot_support(void)
{
	return false;
}

#define HVGR_MMU_SID_START_OFFSET 0
#define HVGR_MMU_SID_END_OFFSET 3

#endif /* HVGR_REGMAP_H */
