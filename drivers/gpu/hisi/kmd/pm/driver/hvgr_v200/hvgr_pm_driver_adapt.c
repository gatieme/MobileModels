/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2022-2022. All rights reserved.
 * This file is the dvfs implementation of the PM module.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#include <linux/platform_device.h>
#include <linux/delay.h>

#include "hvgr_dm_api.h"
#include "hvgr_log_api.h"
#include "hvgr_pm_api.h"
#include "hvgr_datan_api.h"
#include "hvgr_sch_api.h"
#include "hvgr_platform_api.h"
#include "hvgr_regmap.h"

#include "hvgr_pm_defs.h"
#include "hvgr_pm_dfx.h"

#include "hvgr_pm_policy.h"
#include "hvgr_pm_driver.h"
#include "hvgr_pm_driver_base.h"
#include "hvgr_pm_driver_adapt_defs.h"
#include "hvgr_mmu_api.h"

enum core_status {
	PM_CORE_POWERED_OFF,
	PM_CORE_POWERING_ON,
	PM_CORE_POWERING_OFF,
	PM_CORE_POWERED_ON,
};

#define PM_CORE_STATUS_MASK          0x3
#define HVGR_PM_GPU_FLUSH_TIMEOUT    500

irqreturn_t hvgr_pm_cc_irq(int irq, void *data)
{
	struct hvgr_device *gdev = data;
	uint32_t val;

	if (hvgr_pm_get_gpu_status(gdev) == HVGR_PM_POWER_OFF)
		return IRQ_NONE;

	val = hvgr_read_reg(gdev, gpu_control_reg(gdev, CC_IRQ_STATUS));
	if (val == 0)
		return IRQ_NONE;

	hvgr_write_reg(gdev, gpu_control_reg(gdev, CC_IRQ_CLEAR), val);

	if (val & RESET_COMPLETED) {
		hvgr_info(gdev, HVGR_PM, "Gpu soft reset completed.");
		atomic_set(&gdev->pm_dev.pm_reset.reset_status, GPU_RESET_SOFT_RESET_DONE);
		wake_up(&gdev->pm_dev.pm_reset.reset_done_wait);
	}
	return IRQ_HANDLED;
}

static void hvgr_pm_driver_job_rjd_os_config(struct hvgr_device *gdev,
	uint32_t gpc_mask)
{
	/*
	 * The value of the JOB_RJD_OS_CONFIG register is provided by the
	 * hardware. The mapping between the number of powered-on cores and
	 * the value of the JOB_RJD_OS_CONFIG register is as follows:
	 *
	 *  Powered-on cores          JOB_RJD_OS_CONFIG value
	 *          1                       0x20081008
	 *          2                       0x20081008
	 *          3                       0x0C040602
	 *          4                       0x10040802
	 *          5                       0x14040A02
	 *          6                       0x18040C02
	 *          7                       0x1C040E02
	 *          8                       0x20041002
	 */
	uint32_t gpc_number = hweight32(gpc_mask);
	uint32_t job_rjd_value[] = {
		0x20081008,
		0x20081008,
		0x0C040602,
		0x10040802,
		0x14040A02,
		0x18040C02,
		0x1C040E02,
		0x20041002
	};

	if (!hvgr_is_job_slot_support())
		return;

	if (unlikely(gpc_number == 0 ||
		gpc_number > ARRAY_SIZE(job_rjd_value))) {
		hvgr_err(gdev, HVGR_PM, "gpc number is invalid, gpc number = %d",
			gpc_number);
		return;
	}
	hvgr_write_reg(gdev, job_control_reg(gdev, JOB_RJD_OS_CONFIG),
		job_rjd_value[gpc_number - 1]);
}

static void hvgr_pm_wait_cycle_cnt_oper_done(struct hvgr_device *gdev)
{
	int i = 0;
	uint32_t gpu_irq;

	do {
		gpu_irq = hvgr_read_reg(gdev, gpu_control_reg(gdev, GPU_IRQ_RAWSTAT));
		i++;
	} while ((i < HVGR_OPER_CYCLE_TIMEOUT) && ((gpu_irq & CYCLECOUNT_DONE) == 0));

	if (i == HVGR_OPER_CYCLE_TIMEOUT)
		hvgr_err(gdev, HVGR_PM, "Operate cycle counter time out.");

	hvgr_write_reg(gdev, gpu_control_reg(gdev, GPU_IRQ_CLEAR), CYCLECOUNT_DONE);
	hvgr_info(gdev, HVGR_PM, "%s, wait times = %d, gpu_irq = 0x%x.",
		__func__, i, gpu_irq);
}

static void hvgr_pm_start_cycle_count(struct hvgr_device *gdev)
{
	hvgr_write_reg(gdev, gpu_control_reg(gdev, GPU_COMMAND), GPU_COMMAND_CYCLE_COUNT_START);
	hvgr_pm_wait_cycle_cnt_oper_done(gdev);
}

static void hvgr_pm_stop_cycle_count(struct hvgr_device *gdev)
{
	hvgr_write_reg(gdev, gpu_control_reg(gdev, GPU_COMMAND), GPU_COMMAND_CYCLE_COUNT_STOP);
	hvgr_pm_wait_cycle_cnt_oper_done(gdev);
}

static bool hvgr_pm_is_core_stable(uint32_t cores, uint32_t core_status,
	uint32_t dst_stat)
{
	uint32_t bit_pos;

	while (cores) {
		bit_pos = (uint32_t)ffs((int)cores) - 1;
		if (((core_status >> (bit_pos * 2)) & PM_CORE_STATUS_MASK)
			!= dst_stat)
			return false;

		cores &= ~((uint32_t)1 << bit_pos);
	}
	return true;
}

void hvgr_dump_registers(struct hvgr_device *gdev)
{
	unsigned int i, j, jc_idx;

	hvgr_err(gdev, HVGR_PM, "Register state:");
	hvgr_err(gdev, HVGR_PM, "  GPU_IRQ_RAWSTAT=0x%08x GPU_STATUS=0x%08x",
		hvgr_read_reg(gdev, gpu_control_reg(gdev, GPU_IRQ_RAWSTAT)),
		hvgr_read_reg(gdev, gpu_control_reg(gdev, GPU_STATUS)));

	hvgr_err(gdev, HVGR_PM, "  JOB_IRQ_STATUS=0x%08x",
		hvgr_read_reg(gdev, job_control_reg(gdev, JOB_IRQ_STATUS)));

	for (i = 0; i < MAX_JOB_SLOT_NR; i++) {
		hvgr_err(gdev, HVGR_PM, "  JS%u_IRQ_STATUS=0x%08x ", i,
			hvgr_read_reg(gdev, job_slot_x_reg(gdev, i, JSX_IRQ_STATUS)));

		for (j = 0; j < MAX_JOB_SLOT_CHAIN_NR; j++) {
			jc_idx = (i << 2) + j;
			hvgr_err(gdev, HVGR_PM,
				"  JS%u_JC%u_HEAD_LO=0x%08x ", i, j,
				hvgr_read_reg(gdev,
					job_jc_y_reg(gdev, jc_idx, JSX_JCY_HEAD_LO)));
		}
	}

	hvgr_err(gdev, HVGR_PM, "  MMU_IRQ_RAWSTAT=0x%08x GPU_FAULTSTATUS=0x%08x",
		hvgr_read_reg(gdev, mmu_control_reg(gdev, MMU_IRQ_RAWSTAT)),
		hvgr_read_reg(gdev, gpu_control_reg(gdev, GPU_FAULTSTATUS)));

	hvgr_err(gdev, HVGR_PM,
		"  GPU_IRQ_MASK=0x%08x    MMU_IRQ_MASK=0x%08x",
		hvgr_read_reg(gdev, gpu_control_reg(gdev, GPU_IRQ_MASK)),
		hvgr_read_reg(gdev, mmu_control_reg(gdev, MMU_IRQ_MASK)));
	for (i = 0; i < MAX_JOB_SLOT_NR; i++)
		hvgr_err(gdev, HVGR_PM,
			"  JS%u_IRQ_MASK=0x%08x ", i,
			hvgr_read_reg(gdev, job_slot_x_reg(gdev, i, JSX_IRQ_MASK)));

	hvgr_err(gdev, HVGR_PM, "  PWR_OVERRIDE0=0x%08x   PWR_OVERRIDE1=0x%08x",
		hvgr_read_reg(
			gdev, gpu_control_reg(gdev, PWR_OVERRIDE0)),
		hvgr_read_reg(
			gdev, gpu_control_reg(gdev, PWR_OVERRIDE1)));
	hvgr_err(gdev, HVGR_PM, "  SHADER_CONFIG=0x%08x   L2_MMU_CONFIG=0x%08x",
		hvgr_read_reg(gdev, gpu_control_reg(gdev, GPC_CONFIG_0)),
		hvgr_read_reg(
			gdev, gpu_control_reg(gdev, L2_MMU_CONFIG_0)));
	hvgr_err(gdev, HVGR_PM, "  TILER_CONFIG=0x%08x    JM_CONFIG=0x%08x",
		hvgr_read_reg(gdev, gpu_control_reg(gdev, BTC_CONFIG_0)),
		hvgr_read_reg(gdev, gpu_control_reg(gdev, JM_CONFIG)));

	hvgr_err(gdev, HVGR_PM, "\tGPC pwr status = 0x%08x",
		hvgr_read_reg(gdev, gpu_control_reg(gdev, GPC_PWR_STATUS)));
	hvgr_err(gdev, HVGR_PM, "\tBL pwr status = 0x%08x",
		hvgr_read_reg(gdev, gpu_control_reg(gdev, BL_PWR_STATUS)));
	hvgr_err(gdev, HVGR_PM, "\tAS state = 0x%08x.",
		hvgr_read_reg(gdev, mmu_control_reg(gdev, MMU_CMD_DONE)));
	hvgr_err(gdev, HVGR_PM, "\tMMU cmd warn = 0x%08x.",
		hvgr_read_reg(gdev, mmu_control_reg(gdev, MMU_CMD_CFG_WARN)));
	hvgr_err(gdev, HVGR_PM, "\tMMU invalid state = 0x%08x.",
		hvgr_read_reg(gdev, mmu_control_reg(gdev, MMU_INVALID_STATE)));
	hvgr_sch_reset(gdev, HVGR_SCH_DUMP_REGISTER);
}

bool hvgr_pm_is_core_ready(uint32_t cores, uint32_t core_status)
{
	return hvgr_pm_is_core_stable(cores, core_status, PM_CORE_POWERED_ON);
}

bool hvgr_pm_is_core_off(uint32_t cores, uint32_t core_status)
{
	return hvgr_pm_is_core_stable(cores, core_status, PM_CORE_POWERED_OFF);
}

bool hvgr_pm_driver_unreset_cores(struct hvgr_device *gdev)
{
	uint32_t cores;
	uint64_t start_time;
	uint64_t dfx_time;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	start_time = hvgr_start_timing();
	dfx_time = hvgr_pm_dfx_get_curtime(gdev);
	/* 1. Load jmcp firmeware */
	(void)hvgr_fcp_load_by_poll(gdev);
	/* 2. Un reset GPC */
	cores = pm_pwr->present_cores[HVGR_PM_CORE_GPC];
	cores &= pm_pwr->core_mask_cur;
	hvgr_write_reg(gdev, gpu_control_reg(gdev, GPC_PWRON_CMD), cores);
	if (unlikely(!hvgr_pm_driver_wait_core_trans_end(gdev, cores,
		GPC_PWR_STATUS, hvgr_pm_is_core_ready))) {
		hvgr_err(gdev, HVGR_PM, "Unreset GPC failed.");
		return false;
	}
	hvgr_pm_start_cycle_count(gdev);
	hvgr_pm_dfx_core_on_statistics(gdev, dfx_time);
	hvgr_end_timing_and_log(gdev, HVGR_PM, start_time, "Unreset core");
	hvgr_info(gdev, HVGR_PM, "Unreset GPC succeeded.");
	return true;
}

bool hvgr_pm_driver_reset_cores(struct hvgr_device *gdev)
{
	uint32_t cores;
	uint64_t start_time;
	uint64_t dfx_time;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	dfx_time = hvgr_pm_dfx_get_curtime(gdev);
	start_time = hvgr_start_timing();

	hvgr_pm_stop_cycle_count(gdev);
	/* 1. Reset GPC */
	cores = pm_pwr->present_cores[HVGR_PM_CORE_GPC];
	cores &= pm_pwr->core_mask_cur;
	hvgr_write_reg(gdev, gpu_control_reg(gdev, GPC_PWROFF_CMD), cores);

	hvgr_pm_dfx_core_off_statistics(gdev, dfx_time);
	hvgr_end_timing_and_log(gdev, HVGR_PM, start_time, "Reset core");
	hvgr_info(gdev, HVGR_PM, "Reset GPC ongoing, cores 0x%x", cores);
	return true;
}

bool hvgr_pm_wait_gpc_poweroff_ready(struct hvgr_device *gdev)
{
	uint32_t cores;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	cores = pm_pwr->present_cores[HVGR_PM_CORE_GPC];
	cores &= pm_pwr->core_mask_cur;

	if (unlikely(!hvgr_pm_driver_wait_core_trans_end(gdev, cores,
		GPC_PWR_STATUS, hvgr_pm_is_core_off))) {
		hvgr_err(gdev, HVGR_PM, "Reset GPC failed when powering off gpc.");
		return false;
	}

	hvgr_info(gdev, HVGR_PM, "Reset core succeeded.");
	return true;
}

static void hvgr_pm_wait_clean_flush_end(struct hvgr_device *gdev)
{
	unsigned long time_out;
	struct hvgr_pm_dev *pm_dev = &gdev->pm_dev;
	bool ret = false;

	time_out = jiffies + msecs_to_jiffies(HVGR_PM_GPU_FLUSH_TIMEOUT);
	do {
		if (atomic_read(&pm_dev->pm_pwr.flush_status) == GPU_FLUSH_CLEAN_DONE) {
			ret = true;
			break;
		}
		udelay(1); /* delay 1 us */
	} while (time_before(jiffies, time_out));

	if (ret)
		hvgr_info(gdev, HVGR_PM, "Gpu clean flush success!");
	else
		hvgr_err(gdev, HVGR_PM, "Gpu clean flush time out!");

	hvgr_write_reg(gdev, gpu_control_reg(gdev, GPU_IRQ_MASK), 0);
	hvgr_write_reg(gdev, gpu_control_reg(gdev, GPU_IRQ_CLEAR), 0xFFFFFFFF);
}

static void hvgr_pm_clean_flush(struct hvgr_device *gdev)
{
	atomic_set(&gdev->pm_dev.pm_pwr.flush_status, GPU_FLUSH_CLEAN_ACTIVE);
	hvgr_write_reg(gdev, gpu_control_reg(gdev, GPU_IRQ_MASK), CLEAN_CACHES_COMPLETED);
	hvgr_write_reg(gdev, gpu_control_reg(gdev, GPU_COMMAND), GPU_COMMAND_CLEAN_CACHES);
	hvgr_pm_wait_clean_flush_end(gdev);
}

void hvgr_pm_driver_reset_gpc_and_bl(struct hvgr_device *gdev)
{
	uint32_t cores;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	(void)hvgr_pm_driver_reset_cores(gdev);
	cores = pm_pwr->present_cores[HVGR_PM_CORE_GPC];
	cores &= pm_pwr->core_mask_cur;
	/* GPC is powering off */
	if (unlikely(!hvgr_pm_driver_wait_core_trans_end(gdev, cores,
		GPC_PWR_STATUS, hvgr_pm_is_core_off))) {
		hvgr_err(gdev, HVGR_PM, "Reset GPC failed when reset gpc and bl.");
		return;
	}

	if (hvgr_hw_has_issue(gdev, HVGR_HW_ISSUE_50210)) {
		hvgr_pm_clean_flush(gdev);
	} else {
		cores = pm_pwr->present_cores[HVGR_PM_CORE_BL];
		hvgr_write_reg(gdev, gpu_control_reg(gdev, BL_PWROFF_CMD), cores);
		if (unlikely(!hvgr_pm_driver_wait_core_trans_end(gdev, cores,
			BL_PWR_STATUS, hvgr_pm_is_core_off)))
			hvgr_err(gdev, HVGR_PM, "Reset BL failed.");
	}
}

static void hvgr_pm_driver_cbit_config(struct hvgr_device *gdev)
{
	uint32_t btc_cfg_4;
	uint32_t gpc_cfg_6;
	uint32_t cores;
	uint32_t gpc_cfg_4;
	uint32_t gpc_cfg_0;
	uint32_t gpc_cfg_2;
	uint32_t gpc_cfg_5;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	btc_cfg_4 = hvgr_read_reg(gdev, gpu_control_reg(gdev, BTC_CONFIG_4));
	btc_cfg_4 = btc_cfg_4 | BTC_CFG4_TOP_MUX_SEL_2V;
	hvgr_write_reg(gdev, gpu_control_reg(gdev, BTC_CONFIG_4), btc_cfg_4);

	gpc_cfg_6 = hvgr_read_reg(gdev, gpu_control_reg(gdev, GPC_CONFIG_6));
	gpc_cfg_6 |= GPC_CFG6_LSC_NONGPC_STORE_MASK_DISABLE;

	gpc_cfg_6 |= GPC_CFG6_LSC_PUSH_VTC_GTC_PROP;
	hvgr_write_reg(gdev, gpu_control_reg(gdev, GPC_CONFIG_6), gpc_cfg_6);

	if (!hvgr_hw_has_issue(gdev, HVGR_HW_ISSUE_50300)) {
		if (hvgr_is_fpga(gdev)) {
			gpc_cfg_4 = hvgr_read_reg(gdev, gpu_control_reg(gdev, GPC_CONFIG_4));
			gpc_cfg_4 |= (0x2A << 8); /* mask GPC0~2's SP1 */
			hvgr_write_reg(gdev, gpu_control_reg(gdev, GPC_CONFIG_4), gpc_cfg_4);
		}
	}

	if (hvgr_hw_has_issue(gdev, HVGR_HW_ISSUE_00031)) {
		gpc_cfg_0 = hvgr_read_reg(gdev, gpu_control_reg(gdev, GPC_CONFIG_0));
		gpc_cfg_0 |= SHADER_CONFIG_0_ICG;
		hvgr_write_reg(gdev, gpu_control_reg(gdev, GPC_CONFIG_0), gpc_cfg_0);

		gpc_cfg_2 = hvgr_read_reg(gdev, gpu_control_reg(gdev, GPC_CONFIG_2));
		gpc_cfg_2 |= SHADER_CONFIG_2_ICG;
		hvgr_write_reg(gdev, gpu_control_reg(gdev, GPC_CONFIG_2), gpc_cfg_2);

		gpc_cfg_5 = hvgr_read_reg(gdev, gpu_control_reg(gdev, GPC_CONFIG_5));
		gpc_cfg_5 |= SHADER_CONFIG_5_ICG;
		hvgr_write_reg(gdev, gpu_control_reg(gdev, GPC_CONFIG_5), gpc_cfg_5);
	}

	hvgr_write_reg(gdev, fcp_mb_reg(gdev, FCP_MB_EDMA2MCU_CF_MASKINT),
		FCP_INT_MASK); /* DMA channel 0~31 default mask */
	hvgr_write_reg(gdev, fcp_mb_reg(gdev, FCP_MB_EDMA2MCU_CQ_MASKINT),
		FCP_INT_MASK); /* DMA channel 0~31 default mask */
	hvgr_write_reg(gdev, fcp_mb_reg(gdev, FCP_MB_EDMA2JM_MASKINT),
		FCP_INT_UNMASK); /* DMA channel 0~31 default unmask */
	hvgr_write_reg(gdev, fcp_mb_reg(gdev, FCP_MB_EDMA2HOST_MASKINT),
		FCP_INT_MASK); /* DMA channel 0~31 default mask */

	hvgr_datan_cbit_config(gdev);
	cores = pm_pwr->present_cores[HVGR_PM_CORE_GPC];
	cores &= pm_pwr->core_mask_cur;
	hvgr_pm_driver_job_rjd_os_config(gdev, cores);

	hvgr_mmu_cbit_config(gdev);

	hvgr_platform_timestamp_cbit_config(gdev);
}

int hvgr_pm_driver_clock_on(struct hvgr_device *gdev)
{
	uint32_t cores;
	uint64_t start_time;
	uint64_t dfx_time;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	dfx_time = hvgr_pm_dfx_get_curtime(gdev);
	start_time = hvgr_start_timing();
	hvgr_pm_driver_buck_on(gdev);
	hvgr_platform_enable_icg_clk(gdev);

#if defined(HVGR_USE_PCIE) && HVGR_USE_PCIE
	(void)hvgr_crg_reset(gdev);
#endif

	cores = pm_pwr->present_cores[HVGR_PM_CORE_BL];
	hvgr_write_reg(gdev, gpu_control_reg(gdev, BL_PWRON_CMD), cores);
	if (unlikely(!hvgr_pm_driver_wait_core_trans_end(gdev, cores,
		BL_PWR_STATUS, hvgr_pm_is_core_ready))) {
		hvgr_err(gdev, HVGR_PM, "Unreset BL failed.");
		return HVGR_PM_CORE_FAIL;
	}
	hvgr_info(gdev, HVGR_PM, "Unreset BL succeeded.");
	hvgr_pm_driver_cbit_config(gdev);
	hvgr_sch_set_mode(gdev, HVGR_SCH_MODE_CQ, HVGR_SCH_SUBMIT_IGNORE);
	hvgr_enable_interrupts(gdev);

	hvgr_pm_dfx_buck_on_statistics(gdev, dfx_time);
	hvgr_end_timing_and_log(gdev, HVGR_PM, start_time, "Clock on");
	return HVGR_PM_OK;
}

bool hvgr_pm_driver_gpu_config(struct hvgr_device *gdev)
{
	uint32_t cores;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	hvgr_platform_enable_icg_clk(gdev);
	cores = pm_pwr->present_cores[HVGR_PM_CORE_BL];
	hvgr_write_reg(gdev, gpu_control_reg(gdev, BL_PWRON_CMD), cores);
	if (unlikely(!hvgr_pm_driver_wait_core_trans_end(gdev, cores,
		BL_PWR_STATUS, hvgr_pm_is_core_ready))) {
		hvgr_err(gdev, HVGR_PM, "Unreset BL failed.");
		return false;
	}
	hvgr_info(gdev, HVGR_PM, "Unreset BL succeeded.");
	hvgr_pm_driver_cbit_config(gdev);
	return true;
}

int hvgr_pm_driver_clock_off(struct hvgr_device *gdev)
{
	uint32_t cores;
	uint64_t start_time;
	uint64_t dfx_time;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	dfx_time = hvgr_pm_dfx_get_curtime(gdev);
	start_time = hvgr_start_timing();
	hvgr_disable_interrupts(gdev);
	hvgr_pm_driver_clock_off_pre_proc(gdev);

	if (hvgr_hw_has_issue(gdev, HVGR_HW_ISSUE_50210)) {
		hvgr_pm_clean_flush(gdev);
	} else {
		cores = pm_pwr->present_cores[HVGR_PM_CORE_BL];
		hvgr_write_reg(gdev, gpu_control_reg(gdev, BL_PWROFF_CMD), cores);
		if (unlikely(!hvgr_pm_driver_wait_core_trans_end(gdev, cores,
			BL_PWR_STATUS, hvgr_pm_is_core_off))) {
			hvgr_err(gdev, HVGR_PM, "Reset BL failed.");
			hvgr_sch_set_mode(gdev, HVGR_SCH_MODE_CQ, HVGR_SCH_SUBMIT_IGNORE);
			hvgr_enable_interrupts(gdev);
			return HVGR_PM_CORE_FAIL;
		}
		hvgr_info(gdev, HVGR_PM, "Reset BL succeeded.");
	}

	hvgr_pm_driver_buck_off(gdev);
	hvgr_pm_dfx_buck_off_statistics(gdev, dfx_time);
	hvgr_end_timing_and_log(gdev, HVGR_PM, start_time, "Clock off");
	return HVGR_PM_OK;
}

void hvgr_pm_driver_hw_init(struct hvgr_device *gdev)
{
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	pm_pwr->present_cores[HVGR_PM_CORE_BL] =
		hvgr_read_reg(gdev, gpu_control_reg(gdev, BL_PRESENT));
	pm_pwr->present_cores[HVGR_PM_CORE_GPC] =
		hvgr_read_reg(gdev, gpu_control_reg(gdev, GPC_PRESENT));

	if (pm_pwr->gpc_present_mask != 0)
		pm_pwr->present_cores[HVGR_PM_CORE_GPC] &= pm_pwr->gpc_present_mask;

	pm_pwr->core_mask_cur =
		pm_pwr->core_mask_desire =
		pm_pwr->present_cores[HVGR_PM_CORE_GPC];

	/* Register cc irq */
	if (hvgr_register_irq(gdev, CC_IRQ, hvgr_pm_cc_irq) != 0)
		hvgr_err(gdev, HVGR_PM, "Regiser cc irq failed.");
}

static uint32_t hvgr_pm_drier_get_ready_cores(struct hvgr_device *gdev)
{
	uint32_t status;
	uint32_t present;
	uint32_t ready = 0;
	uint32_t bit_pos;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	present = pm_pwr->present_cores[HVGR_PM_CORE_GPC];
	status = hvgr_read_reg(gdev, gpu_control_reg(gdev, GPC_PWR_STATUS));

	while (present) {
		bit_pos = (uint32_t)ffs((int)present) - 1;
		if (((status >> (bit_pos * 2)) & PM_CORE_STATUS_MASK) ==
			PM_CORE_POWERED_ON)
			ready |= (uint32_t)1 << bit_pos;

		present &= ~((uint32_t)1 << bit_pos);
	}
	return ready;
}

void hvgr_pm_driver_set_core_mask(struct hvgr_device *gdev)
{
	uint32_t desire_mask, ready, unreset_mask, reset_mask;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	desire_mask = pm_pwr->core_mask_desire;
	ready = hvgr_pm_drier_get_ready_cores(gdev);
	unreset_mask = ~ready & desire_mask;
	reset_mask = ready & ~desire_mask;

	hvgr_pm_stop_cycle_count(gdev);
	if (unreset_mask) {
		hvgr_write_reg(gdev, gpu_control_reg(gdev, GPC_PWRON_CMD), unreset_mask);
		(void)hvgr_pm_driver_wait_core_trans_end(gdev, unreset_mask, GPC_PWR_STATUS,
			hvgr_pm_is_core_ready);
	}

	if (reset_mask) {
		hvgr_write_reg(gdev, gpu_control_reg(gdev, GPC_PWROFF_CMD), reset_mask);
		(void)hvgr_pm_driver_wait_core_trans_end(gdev, reset_mask, GPC_PWR_STATUS,
			hvgr_pm_is_core_off);
	}

	hvgr_pm_start_cycle_count(gdev);
	ready = hvgr_pm_drier_get_ready_cores(gdev);
	hvgr_pm_driver_job_rjd_os_config(gdev, ready);
}

void hvgr_pm_driver_gpu_soft_reset(struct hvgr_device *gdev)
{
	hvgr_write_reg(gdev, gpu_control_reg(gdev, SOFT_RESET_CMD), GPU_COMMAND_SOFT_RESET);
	/* Unmask the reset complete interrupt only */
	hvgr_write_reg(gdev, gpu_control_reg(gdev, CC_IRQ_MASK), RESET_COMPLETED);
}

int hvgr_pm_driver_hw_access_enable(struct hvgr_device *gdev)
{
	uint32_t l2_present;

	hvgr_pm_driver_buck_on(gdev);
	hvgr_platform_enable_icg_clk(gdev);
	/* Init GPU control register baseaddr. */
	if (hvgr_init_control_baseaddr(gdev) != 0)
		return -1;
	if (hvgr_hw_set_issues_mask(gdev) != 0)
		return -1;
	l2_present = hvgr_read_reg(gdev, gpu_control_reg(gdev, BL_PRESENT));
	hvgr_write_reg(gdev, gpu_control_reg(gdev, BL_PWRON_CMD), l2_present);
	(void)hvgr_pm_driver_wait_core_trans_end(gdev, l2_present, BL_PWR_STATUS,
		hvgr_pm_is_core_ready);
	return 0;
}

void hvgr_pm_driver_hw_access_disable(struct hvgr_device *gdev)
{
	uint32_t l2_present;

	l2_present = hvgr_read_reg(gdev, gpu_control_reg(gdev, BL_PRESENT));

	hvgr_write_reg(gdev, gpu_control_reg(gdev, BL_PWROFF_CMD), l2_present);

	(void)hvgr_pm_driver_wait_core_trans_end(gdev, l2_present, BL_PWR_STATUS,
		hvgr_pm_is_core_off);

	hvgr_pm_driver_buck_off(gdev);

#ifdef CONFIG_HVGR_GPU_RT_PM
	hvgr_pm_driver_runtime_init(gdev);
#endif
}

void hvgr_pm_gate_icg_clk(struct hvgr_device *gdev)
{
	uint32_t val;

	if (!hvgr_hw_has_issue(gdev, HVGR_HW_ISSUE_00030))
		return;

	val = hvgr_read_reg(gdev, gpu_control_reg(gdev, PWR_OVERRIDE0));
	hvgr_write_reg(gdev, gpu_control_reg(gdev, PWR_KEY), HVGR_PWR_KEY_VALUE);
	hvgr_write_reg(gdev, gpu_control_reg(gdev, PWR_OVERRIDE0), val & (~HVGR_ICG_CLK_ON));
}
