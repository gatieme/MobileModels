/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */
#include "hvgr_dm_api.h"
#include "hvgr_fcp.h"
#include "hvgr_regmap_fcp.h"
#include "hvgr_log_api.h"

bool hvgr_fcp_is_dev_ready(struct hvgr_device *gdev)
{
	(void)gdev;

	return true;
}

int hvgr_fcp_wait_boot_done(struct hvgr_device *gdev)
{
	u32 value;
	u32 time = HVGR_MAX_TRY_TIMES;

	do {
		value = hvgr_read_reg(gdev,
			fcp_mb_reg(gdev, FCP_MB_MCUBOOT_STATUS));
		time--;
	} while ((value == 0) && (time != 0));

	if (value == 0) {
		hvgr_err(gdev, HVGR_DM, "fcp wait boot done timeout");
		return -EBUSY;
	}

	time = HVGR_MAX_TRY_TIMES;
	do {
		value = hvgr_read_reg(gdev, gpu_control_reg(gdev, GPU_STATUS));
		time--;
	} while ((fcp_active_bits(value) != 0) && (time != 0));

	if (fcp_active_bits(value) != 0) {
		hvgr_err(gdev, HVGR_DM, "fcp wait job done timeout");
		return -EBUSY;
	}

	return 0;
}

void hvgr_fcp_store_dma_cfg(struct hvgr_device *gdev, bool interupt)
{
	hvgr_write_reg(gdev, fcp_mb_reg(gdev, FCP_MB_EDMA2MCU_CF_MASKINT),
		FCP_INT_MASK); /* DMA channel 0~31 all masked */
	hvgr_write_reg(gdev, fcp_mb_reg(gdev, FCP_MB_EDMA2MCU_CQ_MASKINT),
		FCP_INT_MASK); /* DMA channel 0~31 all masked */
	hvgr_write_reg(gdev, fcp_mb_reg(gdev, FCP_MB_EDMA2JM_MASKINT),
		FCP_INT_MASK); /* DMA channel 0~31 all masked */
	hvgr_write_reg(gdev, fcp_mb_reg(gdev, FCP_MB_EDMA2HOST_MASKINT),
		FCP_INT_MASK); /* DMA channel 0~31 all masked */
}

void hvgr_fcp_recover_dma_cfg(struct hvgr_device *gdev)
{
	hvgr_write_reg(gdev, fcp_mb_reg(gdev, FCP_MB_EDMA2MCU_CF_MASKINT),
		FCP_INT_MASK); /* DMA channel 0~31 default mask */
	hvgr_write_reg(gdev, fcp_mb_reg(gdev, FCP_MB_EDMA2MCU_CQ_MASKINT),
		FCP_INT_MASK); /* DMA channel 0~31 default mask */
	hvgr_write_reg(gdev, fcp_mb_reg(gdev, FCP_MB_EDMA2JM_MASKINT),
		FCP_INT_UNMASK); /* DMA channel 0~31 default unmask */
	hvgr_write_reg(gdev, fcp_mb_reg(gdev, FCP_MB_EDMA2HOST_MASKINT),
		FCP_INT_MASK); /* DMA channel 0~31 default mask */
}

