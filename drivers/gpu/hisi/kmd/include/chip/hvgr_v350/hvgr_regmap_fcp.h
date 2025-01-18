/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#ifndef HVGR_REGMAP_FCP_H
#define HVGR_REGMAP_FCP_H

/* Begin Register Offsets */
#define FCP_BASE                   0x10000
#define FCP_START_CODE             0
#define FCP_DTCM_START_ADDR        0x5000
#define FCP_ITCM_CQ_START_ADDR     0x8000
#define FCP_DTCM0_CQ_START_ADDR    0x9000
#define FCP_DTCM1_CQ_START_ADDR    0xB000

#define FCP_ITCM0_START_ADDR       0x0000
#define FCP_DTCM0_START_ADDR       0x6000
#define FCP_ITCM1_START_ADDR       0xa000
#define FCP_DTCM1_START_ADDR       0x10000

#define FCP_MB0_REG_BASE_ADDR               0xd000
#define FCP_MB1_REG_BASE_ADDR               0xd400

#define FCP_MB_MCUVECTOR_ADDR               0x000
#define FCP_MB_MCU_CPUWAIT                  0x004
#define FCP_MB_MCUBOOT_STATUS               0x008
#define FCP_MB_MCUSLEEP_STATUS              0x010
#define FCP_MB_FIRMWARE_CORE_ID             0x014
#define FCP_MB_MCU_REG_ADDR                 0x030
#define FCP_MB_MCU_REG_WDATA                0x034
#define FCP_MB_MCU_REG_RDATA                0x038
#define FCP_MB_MCU_REG_CTRL                 0x03c
#define FCP_MB_REG_STATUS                   0x040
#define FCP_MB_MCU_IRQ                      0x100
#define FCP_MB_JOB_INFO0                    0x104
#define FCP_MB_JOB_INFO1                    0x108
#define FCP_MB_MCU_ADDR                     0x10c
#define FCP_MB_MCU_IRQ_CLR                  0x110
#define FCP_MB_MCU_DONE                     0x114

#define FCP_MB_MCU_DDR_MAP_BASE             0x20


#define FCP_DMA_CHANEL_BASE                 0xd800

#define FCP_DMA_CH_INT_TCRAW                0x00
#define FCP_DMA_CX_CNT                      0x20
#define FCP_DMA_CX_SRC_ADDR_L               0x24
#define FCP_DMA_CX_SRC_ADDR_H               0x28
#define FCP_DMA_CX_DES_ADDR_L               0x2C
#define FCP_DMA_CX_DES_ADDR_H               0x30
#define FCP_DMA_CX_CONFIG                   0x34
#define FCP_DMA_BUFDATA                     0x38

#define FCP_DMA_EDMA2MCU0_MASKINT           0xdd00
#define FCP_DMA_EDMA2MCU1_MASKINT           0xdd04
#define FCP_DMA_EDMA2FCM_MASKINT            0xdd08
#define FCP_DMA_EDMA2HOST_MASKINT           0xdd0c

#define FCP_INT_UNMASK                      0x0
#define FCP_INT_MASK                        0x3fffffff

/* (RW) Read action of FCP control configuration */
#define GPU_FCP_CFG_READ  1
#define GPU_FCP_CFG_WRITE 0   /* (RW) Write action of control configuration */
/*
 * Maximum number of loops for completed in reading/writing FCP registers
 * before we assume it must have completed
 */
#define GPU_FCP_CFG_TRY_COUNT  100000
/* Set when a cache clean operation has completed. */
#define GPU_FCP_CFG_COMPLETED  ((u32)1 << 0)

#define fcp_dma_cfg_val(jasid, enable) ((jasid) << 4 | (enable))

#define fcp_active_bits(val) (((val) >> 3) & 0x3)

#define fcp_reg_base(p) ((p)->dm_dev.reg_base.fcp_base.fcp_reg_base)


#define fcp_reg_mb0_offset(p) \
	((p)->dm_dev.reg_base.fcp_base.fcp_reg_mb0_offset)

#define fcp_mb0_reg(p, r) (fcp_reg_base(p) + fcp_reg_mb0_offset(p) + (r))

#define fcp_reg_mb1_offset(p) \
	((p)->dm_dev.reg_base.fcp_base.fcp_reg_mb1_offset)

#define fcp_mb1_reg(p, r) (fcp_reg_base(p) + fcp_reg_mb1_offset(p) + (r))


#define fcp_reg_dma_offset(p) \
	((p)->dm_dev.reg_base.fcp_base.fcp_reg_dma_offset)

#define fcp_dma_reg(p, r) (fcp_reg_base(p) + fcp_reg_dma_offset(p) + (r))

#define fcp_dma_chanel_reg(p, n, r) ((fcp_reg_base(p) + \
	fcp_reg_dma_offset(p) + ((u32)(n) << 5)) + (r))


#endif /* HVGR_REGMAP_FCP_H */
