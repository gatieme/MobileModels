/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2022-2022. All rights reserved.
 * This file is the dvfs implementation of the PM module.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#include "hvgr_pm_driver_base.h"

#include <linux/pm_runtime.h>
#include <linux/regulator/consumer.h>
#include <linux/delay.h>
#include <linux/platform_device.h>
#include <linux/version.h>

#ifdef CONFIG_GPUFREQ_INDEPDENT
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0)
#include <platform_include/cee/linux/gpufreq_v2.h>
#else
#include <linux/platform_drivers/gpufreq_v2.h>
#endif
#endif

#include "hvgr_dm_api.h"
#include "hvgr_pm_api.h"
#include "hvgr_mem_api.h"
#include "hvgr_platform_api.h"
#include "hvgr_regmap.h"
#include "hvgr_pm_dfx.h"
#include "hvgr_log_api.h"
#include "hvgr_pm_defs.h"
#include "hvgr_pm_policy.h"

#define PM_SCHEDULE_SUSPEND_INTERVAL 50
#define PM_SCHEDULE_SUSPEND_RETRY_TIMES 20

#define HVGR_PM_TRANS_DELAY_TIME 50
#define HVGR_PM_TRANS_RETRY_TIMES 100
#define HVGR_PM_POWER_MAX_RETRY_TIMES 3

bool hvgr_pm_driver_trans_time_out_proc(struct hvgr_device *gdev,
	uint32_t cores, uint32_t trans_reg, hvgr_pm_is_core_trans_end pfunc)
{
	int timeout = HVGR_PM_TRANS_RETRY_TIMES;
	uint32_t core_status;

	do {
		core_status = hvgr_read_reg(gdev, gpu_control_reg(gdev, trans_reg));
		if (pfunc != NULL && pfunc(cores, core_status))
			return true;

		msleep(HVGR_PM_TRANS_DELAY_TIME);
	} while (--timeout > 0);

	hvgr_err(gdev, HVGR_PM,
		"After 5s, Transion core time out [0x%x, 0x%x, 0x%x ].",
		cores, core_status, trans_reg);
	hvgr_pm_dump_reg(gdev, HVGR_LOG_ERROR);
	return false;
}

bool hvgr_pm_driver_wait_core_trans_end(struct hvgr_device *gdev,
	uint32_t cores, uint32_t trans_reg, hvgr_pm_is_core_trans_end pfunc)
{
	int timeout = HVGR_PM_CORE_TRANS_OUT_TIME;
	uint32_t core_status;

	do {
		core_status = hvgr_read_reg(gdev, gpu_control_reg(gdev, trans_reg));
		if (pfunc != NULL && pfunc(cores, core_status)) {
			hvgr_info(gdev, HVGR_PM,
				"Transion core time, [ %d, 0x%x, 0x%x, 0x%x ]",
				HVGR_PM_CORE_TRANS_OUT_TIME - timeout,
				cores, core_status, trans_reg);
			return true;
		}

		udelay(1);
	} while (--timeout > 0);

	hvgr_err(gdev, HVGR_PM,
		"Transion core time out [0x%x, 0x%x, 0x%x ].",
		cores, core_status, trans_reg);
	hvgr_pm_dump_reg(gdev, HVGR_LOG_ERROR);
	return hvgr_pm_driver_trans_time_out_proc(gdev, cores,
		trans_reg, pfunc);
}

void hvgr_pm_config_override(struct hvgr_device *gdev)
{
	hvgr_write_reg(gdev, gpu_control_reg(gdev, PWR_KEY), HVGR_PWR_KEY_VALUE);
	hvgr_write_reg(gdev, gpu_control_reg(gdev, PWR_OVERRIDE0), HVGR_PWR_TRANS_NUM_VALUE);
}

static void hvgr_pm_driver_platform_on(struct hvgr_device *gdev)
{
	uint64_t start_time;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;
	int try_times = 0;
	int ret;

	if (unlikely(pm_pwr->regulator == NULL) ||
		unlikely(gdev->subsys_ops->regulator_enable == NULL))
		return;

	start_time = hvgr_start_timing();
	do {
		ret = gdev->subsys_ops->regulator_enable(pm_pwr->regulator);
		try_times++;
		if (unlikely(ret))
			hvgr_err(gdev, HVGR_PM, "Failed to enable regulator , try_times = %d.",
				try_times);
	} while (unlikely(ret) && try_times < HVGR_PM_POWER_MAX_RETRY_TIMES);
	hvgr_end_timing_and_log(gdev, HVGR_PM, start_time, "Regulator enable");
	if (unlikely(ret)) {
		hvgr_err(gdev, HVGR_PM, "Driver Buck on failed.");
		WARN_ON(1);
	} else {
		hvgr_info(gdev, HVGR_PM, "Driver Buck on succeeded.");
	}

	start_time = hvgr_start_timing();

#ifdef CONFIG_LIBLINUX
	(void)hvgr_platform_smmu_bypass(gdev, HVGR_PF_P1);
	if (unlikely(hvgr_platform_smmu_tcu_on(gdev) != 0))
		hvgr_err(gdev, HVGR_PM, "driver platform on:smmu tcu on failed.");
	(void)hvgr_platform_sec_cfg(gdev, HVGR_PF_PALL);
#else
	(void)hvgr_platform_smmu_bypass(gdev, HVGR_PF_P0);
	if (unlikely(hvgr_platform_smmu_tcu_on(gdev) != 0))
		hvgr_err(gdev, HVGR_PM, "driver platform on:smmu tcu on failed.");
	if (unlikely(hvgr_platform_smmu_tbu_connect(gdev) != 0))
		hvgr_err(gdev, HVGR_PM, "driver platform on:smmu tbu connect failed.");
	(void)hvgr_platform_sec_cfg(gdev, HVGR_PF_P0);
#endif
	(void)hvgr_platform_set_qos(gdev);
#ifdef HVGR_FEATURE_SYSTEM_CACHE
	hvgr_sc_config_remap_register(gdev);
#endif

#ifdef CONFIG_GPUFREQ_INDEPDENT
	gpufreq_devfreq_resume();
#endif

	hvgr_end_timing_and_log(gdev, HVGR_PM, start_time, "Init tbu");
}

static void hvgr_pm_driver_platform_off(struct hvgr_device *gdev)
{
	uint64_t start_time;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;
	int try_times = 0;
	int ret;

	if (unlikely(pm_pwr->regulator == NULL) ||
		unlikely(gdev->subsys_ops->regulator_disable == NULL))
		return;

	start_time = hvgr_start_timing();
#ifdef CONFIG_GPUFREQ_INDEPDENT
	gpufreq_devfreq_suspend();
#endif

	if (unlikely(hvgr_platform_smmu_tbu_disconnect(gdev) != 0))
		hvgr_err(gdev, HVGR_PM, "platform off:smmu tbu disconnect failed.");
	if (unlikely(hvgr_platform_smmu_tcu_off(gdev) != 0))
		hvgr_err(gdev, HVGR_PM, "platform off:smmu tcu off failed.");

	do {
		ret = gdev->subsys_ops->regulator_disable(pm_pwr->regulator);
		try_times++;
		if (unlikely(ret))
			hvgr_err(gdev, HVGR_PM, "Failed to disable regulator , try_times = %d.",
				try_times);
	} while (unlikely(ret) && try_times < HVGR_PM_POWER_MAX_RETRY_TIMES);
	hvgr_end_timing_and_log(gdev, HVGR_PM, start_time, "Regulator disable");
	if (unlikely(ret)) {
		hvgr_err(gdev, HVGR_PM, "Driver Buck off failed.");
	} else {
		hvgr_info(gdev, HVGR_PM, "Driver Buck off succeeded.");
	}
}

#ifdef CONFIG_HVGR_GPU_RT_PM
int hvgr_pm_driver_runtime_suspend(struct hvgr_device *gdev)
{
#ifdef CONFIG_GPUFREQ_INDEPDENT
	gpufreq_devfreq_suspend();
#endif
	hvgr_pm_driver_platform_off(gdev);
	return 0;
}

int hvgr_pm_driver_runtime_resume(struct hvgr_device *gdev)
{
	hvgr_pm_driver_platform_on(gdev);
#ifdef CONFIG_GPUFREQ_INDEPDENT
	gpufreq_devfreq_resume();
#endif
	return 0;
}

int hvgr_pm_driver_runtime_idle(struct hvgr_device *gdev)
{
	return 1;
}

void hvgr_pm_driver_runtime_init(struct hvgr_device *gdev)
{
	pm_suspend_ignore_children(gdev->dev, true);
	pm_runtime_enable(gdev->dev);
}

void hvgr_pm_driver_runtime_term(struct hvgr_device *gdev)
{
	pm_runtime_disable(gdev->dev);
}
#endif

void hvgr_pm_driver_buck_on(struct hvgr_device *gdev)
{
#ifdef CONFIG_HVGR_GPU_RT_PM
	int ret;
	struct device *dev = gdev->dev;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	hvgr_info(gdev, HVGR_PM, "%s Enter.", __func__);

	if (pm_pwr->powered_off_directly) {
		pm_pwr->powered_off_directly = false;
		hvgr_info(gdev, HVGR_PM,
			"%s Gpu is not runtime suspend.", __func__);
		hvgr_pm_driver_runtime_resume(gdev);
		return;
	}

	if (unlikely(dev->power.disable_depth > 0)) {
		hvgr_info(gdev, HVGR_PM,
			"%s Run time is not enable.", __func__);
		hvgr_pm_driver_platform_on(gdev);
		return;
	}
	ret = pm_runtime_resume(dev);
	if (unlikely(ret == -EAGAIN)) {
		hvgr_info(gdev, HVGR_PM,
			"%s runtime resume failed and buck on dricetly.",
			__func__);
		hvgr_pm_driver_platform_on(gdev);
		return;
	}

	if (unlikely(ret < 0)) {
		hvgr_err(gdev, HVGR_PM,
			"%s runtime resume failed %d", __func__, ret);
		return;
	}
	hvgr_info(gdev, HVGR_PM, "%s Run time resume succeeded.", __func__);
	return;
#else
	hvgr_pm_driver_platform_on(gdev);
	return;
#endif
}

#ifdef CONFIG_HVGR_GPU_RT_PM
static int hvgr_pm_driver_do_buck_off(struct hvgr_device *gdev)
{
	int ret = 0;
	struct device *dev = gdev->dev;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	ret = pm_runtime_suspend(dev);
	if (ret == -EAGAIN) {
#if defined(HVGR_USE_PCIE) && HVGR_USE_PCIE
		hvgr_info(gdev, HVGR_PM,
			"%s schedule suspend failed and pci-e do not needed to try again.",
			__func__);
		return 0;
#endif
		/*
		 * If suspend or resume is not being processed, Call
		 * pm_runtime_suspend to power off the gpu again.
		 * Therefore, -EAGAIN needs to be returned.
		 */
		if (atomic_read(&pm_pwr->sr_state) ==
			HVGR_PM_ACTIVE) {
			hvgr_info(gdev, HVGR_PM,
				"%s schedule suspend failed and try again.",
				__func__);
			msleep(PM_SCHEDULE_SUSPEND_INTERVAL);
			return -EAGAIN;
		}

		hvgr_info(gdev, HVGR_PM,
			"%s Enter suspending.", __func__);
		if (pm_runtime_status_suspended(gdev->dev)) {
			hvgr_info(gdev, HVGR_PM,
				"%s The GPU is powered off when the GPU suspend.",
				__func__);
			return 0;
		}
		pm_pwr->powered_off_directly = true;
		/*
		 * If the buck is powered off during suspend or resume,
		 * pm_runtime_suspend returns -EAGAIN. The
		 * hvgr_pm_driver_runtime_suspend needs to be called to
		 * directly power off the buck. You do not need to call
		 * pm_runtime_suspend again.
		 */
		hvgr_pm_driver_runtime_suspend(gdev);
		hvgr_info(gdev, HVGR_PM,
			"%s gpu powered off succeeded.", __func__);
		return 0;
	}

	if (unlikely(ret < 0)) {
		hvgr_err(gdev, HVGR_PM,
			"schedule suspend failed %d", ret);
		WARN_ON(1);
		return ret;
	}

	return 0;
}
#endif

void hvgr_pm_driver_buck_off(struct hvgr_device *gdev)
{
#ifdef CONFIG_HVGR_GPU_RT_PM
	struct device *dev = gdev->dev;
	int ret = 0;
	int retry = 0;

	if (unlikely(dev->power.disable_depth > 0)) {
		hvgr_info(gdev, HVGR_PM,
			"%s Run time is not enable.", __func__);
		hvgr_pm_driver_platform_off(gdev);
		return;
	}

	do {
		ret = hvgr_pm_driver_do_buck_off(gdev);
		if (ret != -EAGAIN)
			return;
	} while (++retry < PM_SCHEDULE_SUSPEND_RETRY_TIMES);

	hvgr_err(gdev, HVGR_PM, "%s Run time suspend time out.", __func__);
#else
	hvgr_pm_driver_platform_off(gdev);
#endif
}

int hvgr_pm_driver_soft_init(struct hvgr_device *gdev)
{
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	pm_pwr->regulator = devm_regulator_get(gdev->dev, "gpu");
	if (unlikely(IS_ERR(pm_pwr->regulator))) {
		hvgr_err(gdev, HVGR_PM, "Failed to get regulator\n");
		return -EINVAL;
	}

	return 0;
}

void hvgr_pm_driver_soft_term(struct hvgr_device *gdev)
{
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	if (likely(pm_pwr->regulator)) {
		devm_regulator_put(pm_pwr->regulator);
		pm_pwr->regulator = NULL;
	}
}

void hvgr_pm_driver_request_cycle_counter(struct hvgr_device *gdev)
{
	hvgr_info(gdev, HVGR_PM, "%s enter ref = %d.",
		__func__, atomic_read(&gdev->pm_dev.cycle_counter_ref));
	if (atomic_inc_return(&gdev->pm_dev.cycle_counter_ref) != 1)
		return;
	hvgr_info(gdev, HVGR_PM, "Cycle counter enable.");
	hvgr_write_reg(gdev, gpu_control_reg(gdev, GPU_COMMAND),
		GPU_COMMAND_CYCLE_COUNT_START);
}

void hvgr_pm_driver_release_cycle_counter(struct hvgr_device *gdev)
{
	hvgr_info(gdev, HVGR_PM, "%s enter ref = %d.",
		__func__, atomic_read(&gdev->pm_dev.cycle_counter_ref));
	if (atomic_dec_return(&gdev->pm_dev.cycle_counter_ref) != 0)
		return;
	hvgr_info(gdev, HVGR_PM, "Cycle counter disable.");
	hvgr_write_reg(gdev, gpu_control_reg(gdev, GPU_COMMAND),
		GPU_COMMAND_CYCLE_COUNT_STOP);
}

void hvgr_pm_driver_re_enable_cycle_counter(struct hvgr_device *gdev)
{
	if (atomic_read(&gdev->pm_dev.cycle_counter_ref) == 0)
		return;

	hvgr_write_reg(gdev, gpu_control_reg(gdev, GPU_COMMAND),
		GPU_COMMAND_CYCLE_COUNT_START);
}

void hvgr_pm_driver_gpu_reset_timeout_proc(struct hvgr_device *gdev)
{
	hvgr_dmd_msg_set(gdev, DMD_HARD_RESET, "Higpu hard reset failed");
	hvgr_dmd_msg_report(gdev);
}

void hvgr_pm_driver_clock_off_pre_proc(struct hvgr_device *gdev)
{
	uint32_t gpu_status;

	hvgr_synchronize_irqs(gdev);
	hvgr_flush_mmu_faults(gdev);
	gpu_status = hvgr_read_reg(gdev, gpu_control_reg(gdev, GPU_STATUS));
	if (gpu_status != 0)
		hvgr_info(gdev, HVGR_PM, "%s , gpu_status = 0x%x",
			__func__, gpu_status);
}
