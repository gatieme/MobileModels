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
	u32 value0;
	u32 value1;
	u32 time = HVGR_MAX_TRY_TIMES;

	do {
		value0 = hvgr_read_reg(gdev,
			fcp_mb0_reg(gdev, FCP_MB_MCUBOOT_STATUS));
		value1 = hvgr_read_reg(gdev,
			fcp_mb1_reg(gdev, FCP_MB_MCUBOOT_STATUS));
		time--;
	} while ((value0 == 0 || value1 == 0) && (time != 0));

	if (value0 == 0 || value1 == 0) {
		hvgr_err(gdev, HVGR_DM, "fcp wait boot done timeout");
		return -EBUSY;
	}

	time = HVGR_MAX_TRY_TIMES;
	do {
		value0 = hvgr_read_reg(gdev, gpu_control_reg(gdev, GPU_STATUS));
		time--;
	} while ((fcp_active_bits(value0) != 0) && (time != 0));

	if (fcp_active_bits(value0) != 0) {
		hvgr_err(gdev, HVGR_DM, "fcp wait job done timeout");
		return -EBUSY;
	}

	return 0;
}

void hvgr_fcp_store_dma_cfg(struct hvgr_device *gdev, bool interupt)
{
	hvgr_write_reg(gdev, fcp_reg_base(gdev) + FCP_DMA_EDMA2FCM_MASKINT,
		FCP_INT_UNMASK);
	return;
}

void hvgr_fcp_recover_dma_cfg(struct hvgr_device *gdev)
{
	hvgr_write_reg(gdev, fcp_reg_base(gdev) + FCP_DMA_EDMA2FCM_MASKINT,
		FCP_INT_MASK);
	return;
}

void hvgr_fcp_upgrade_start_mcu(struct hvgr_device *gdev)
{
	hvgr_write_reg(gdev, fcp_mb0_reg(gdev, FCP_MB_MCU_CPUWAIT), 0u);
	hvgr_write_reg(gdev, fcp_mb1_reg(gdev, FCP_MB_MCU_CPUWAIT), 0u);
}

bool hvgr_fcp_is_load_needed(struct hvgr_device *gdev)
{
	u32 mcu0_status_reg = fcp_mb0_reg(gdev, FCP_MB_MCU_CPUWAIT);
	u32 val;

	/* some caller will enter here before firmware ready, not return err */
	if (!gdev->dm_dev.fcp_data->fcp_firmware_ready)
		return false;

	val = hvgr_read_reg(gdev, mcu0_status_reg);
	if (!val)
		return false;

	return true;
}

int hvgr_fcp_dma_proc(struct hvgr_device *gdev)
{
	struct fcp_dma_cfg dma_cfg = {0};
	struct hvgr_fcp_data *fcp_data = gdev->dm_dev.fcp_data;
	const struct hvg_fcp_header *header =
		(const struct hvg_fcp_header *)fcp_data->kva;
	u32 jasid = FCP_UPGRADE_DMA_JASID;
	u32 itcm_ch_0 = FCP_DMA_CH_29;
	u32 dtcm_ch_0 = FCP_DMA_CH_28;
	u32 itcm_ch_1 = FCP_DMA_CH_27;
	u32 dtcm_ch_1 = FCP_DMA_CH_26;

	/* 1. update itcm */
	dma_cfg.src_addr = fcp_data->gva + sizeof(*header);
	dma_cfg.dst_addr = FCP_ITCM0_START_ADDR;
	dma_cfg.size = header->size_sub0;
	dma_cfg.jasid = jasid;
	dma_cfg.channel = itcm_ch_0;
	hvgr_fcp_configure_dma(gdev, &dma_cfg);

	/* 2. update dtcm */
	dma_cfg.src_addr += header->size_sub0;
	dma_cfg.dst_addr = FCP_DTCM0_START_ADDR;
	dma_cfg.size = header->size_sub1;
	dma_cfg.channel = dtcm_ch_0;
	hvgr_fcp_configure_dma(gdev, &dma_cfg);

	/* mcu1 */
	dma_cfg.src_addr = fcp_data->gva + sizeof(*header);
	dma_cfg.dst_addr = FCP_ITCM1_START_ADDR;
	dma_cfg.size = header->size_sub0;
	dma_cfg.jasid = jasid;
	dma_cfg.channel = itcm_ch_1;
	hvgr_fcp_configure_dma(gdev, &dma_cfg);

	/* 2. update dtcm */
	dma_cfg.src_addr += header->size_sub0;
	dma_cfg.dst_addr = FCP_DTCM1_START_ADDR;
	dma_cfg.size = header->size_sub1;
	dma_cfg.channel = dtcm_ch_1;
	hvgr_fcp_configure_dma(gdev, &dma_cfg);

	if (hvgr_fcp_wait_dma_finish(gdev, itcm_ch_0) != 0) {
		hvgr_err(gdev, HVGR_DM, "fcp upgrade mcu0 itcm timeout");
		return -EBUSY;
	}

	if (hvgr_fcp_wait_dma_finish(gdev, dtcm_ch_0) != 0) {
		hvgr_err(gdev, HVGR_DM, "fcp upgrade mcu0 dtcm timeout");
		return -EBUSY;
	}

	if (hvgr_fcp_wait_dma_finish(gdev, itcm_ch_1) != 0) {
		hvgr_err(gdev, HVGR_DM, "fcp upgrade mcu1 itcm timeout");
		return -EBUSY;
	}

	if (hvgr_fcp_wait_dma_finish(gdev, dtcm_ch_1) != 0) {
		hvgr_err(gdev, HVGR_DM, "fcp upgrade mcu1 dtcm timeout");
		return -EBUSY;
	}

	return 0;
}