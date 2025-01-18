/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2022-2022. All rights reserved.
 * This file is the dvfs implementation of the PM module.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */
 
#include "hvgr_dm_api.h"
#include "hvgr_log_api.h"
#include "hvgr_pm_api.h"
 
#include "hvgr_regmap.h"
#include "hvgr_dm_ctx.h"
 
#include "hvgr_pm_defs.h"
#include "hvgr_pm_dfx.h"
 
#include "hvgr_pm_driver.h"
#include "hvgr_pm_driver_base.h"
#include "hvgr_pm_driver_adapt_defs.h"

/*
 * ITCM size is 24K, the reg default value is 0x3000.
 * we set 0x4000 here means that reserve 16K for firmware self,
 * and the other 8k for const folding job.
 * If changed this value, the jmcp and compiler must be checked.
 */
#define ITCM_CFJ_START_ADDR		0x4000

bool hvgr_pm_driver_unreset_cores(struct hvgr_device *gdev)
{
	bool ret = true;
	uint64_t start_time;
	uint64_t dfx_time;

	start_time = hvgr_start_timing();
	dfx_time = hvgr_pm_dfx_get_curtime(gdev);

	ret = hvgr_pm_driver_gpc_pwr_on_by_sw(gdev);

	hvgr_pm_dfx_core_on_statistics(gdev, dfx_time);
	hvgr_end_timing_and_log(gdev, HVGR_PM, start_time, "Unreset core");

	return ret;
}

bool hvgr_pm_driver_reset_cores(struct hvgr_device *gdev)
{
	bool ret = true;
	uint64_t start_time;
	uint64_t dfx_time;

	dfx_time = hvgr_pm_dfx_get_curtime(gdev);
	start_time = hvgr_start_timing();

	ret = hvgr_pm_driver_gpc_pwr_off_by_sw(gdev);

	hvgr_pm_dfx_core_off_statistics(gdev, dfx_time);
	hvgr_end_timing_and_log(gdev, HVGR_PM, start_time, "Reset core");

	return ret;
}

bool hvgr_pm_wait_gpc_poweroff_ready(struct hvgr_device *gdev)
{
	return hvgr_pm_driver_wait_gpc_pwr_off_by_sw(gdev);
}

bool hvgr_pm_driver_gpu_config(struct hvgr_device *gdev)
{
	if (!hvgr_pm_driver_gpu_config_by_sw(gdev))
		return false;

	/* register should be set after config_common */
	hvgr_ctx_common_ctx_enable(gdev);

	return true;
}

void hvgr_pm_driver_set_core_mask(struct hvgr_device *gdev)
{
	hvgr_pm_driver_set_core_mast_by_sw(gdev);
}

static void hvgr_pm_driver_cbit_call_en(struct hvgr_device *gdev)
{
	uint32_t fcm_cfg;

	fcm_cfg = hvgr_read_reg(gdev, gpu_control_reg(gdev, JM_CONFIG));
	fcm_cfg |= FCM_CFG0_CALL_EN;
	hvgr_write_reg(gdev, gpu_control_reg(gdev, JM_CONFIG), fcm_cfg);
}

static void hvgr_pm_driver_set_itcm_cfj_start(struct hvgr_device *gdev)
{
	hvgr_write_reg(gdev, gpu_control_reg(gdev, JM_CONFIG_2), ITCM_CFJ_START_ADDR);
}

void hvgr_pm_driver_cbit_config(struct hvgr_device *gdev)
{
	hvgr_pm_driver_cbit_config_by_sw(gdev);

	hvgr_pm_driver_cbit_call_en(gdev);
	hvgr_pm_driver_set_itcm_cfj_start(gdev);

	hvgr_write_reg(gdev, fcp_reg_base(gdev) + FCP_DMA_EDMA2MCU0_MASKINT,
		FCP_INT_UNMASK);
	hvgr_write_reg(gdev, fcp_reg_base(gdev) + FCP_DMA_EDMA2MCU1_MASKINT,
		FCP_INT_UNMASK);
	hvgr_write_reg(gdev, fcp_reg_base(gdev) + FCP_DMA_EDMA2FCM_MASKINT,
		FCP_INT_MASK);
	hvgr_write_reg(gdev, fcp_reg_base(gdev) + FCP_DMA_EDMA2HOST_MASKINT,
		FCP_INT_UNMASK);
}

int hvgr_pm_driver_clock_on(struct hvgr_device *gdev)
{
	if (hvgr_pm_driver_clock_on_by_sw(gdev) != HVGR_PM_OK)
		return HVGR_PM_CORE_FAIL;

	/* register should be set after clock_on_common */
	hvgr_ctx_common_ctx_enable(gdev);

	return HVGR_PM_OK;
}

int hvgr_pm_driver_clock_off(struct hvgr_device *gdev)
{
	return hvgr_pm_driver_clock_off_by_sw(gdev);
}