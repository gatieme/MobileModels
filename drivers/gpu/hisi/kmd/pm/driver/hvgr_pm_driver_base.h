/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2022-2022. All rights reserved.
 * This file is the dvfs implementation of the PM module.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */
#ifndef HVGR_PM_DRIVER_BASE_H
#define HVGR_PM_DRIVER_BASE_H
#include <linux/types.h>

#include "hvgr_pm_defs.h"
#include "hvgr_pm_driver_adapt_defs.h"

/* Power-on/off timeout interval of the GPU core, in us. */
#define HVGR_PM_CORE_TRANS_OUT_TIME 20000

/*
 * hvgr_pm_driver_buck_on - Power on the buck
 *
 * @param gdev - The gdev object pointer.
 *
 * @date - 2021-02-03
 */
void hvgr_pm_driver_buck_on(struct hvgr_device *gdev);

/*
 * hvgr_pm_driver_buck_off - Power off the buck
 *
 * @param gdev - The gdev object pointer.
 *
 * @date - 2021-02-03
 */
void hvgr_pm_driver_buck_off(struct hvgr_device *gdev);

/*
 * The V2xx and V1xx use different methods to determine whether the
 * core power-on or power-off is complete. Therefore, a function pointer
 * is defined.
 */
typedef bool (*hvgr_pm_is_core_trans_end) (uint32_t cores,
	uint32_t core_status);

/*
 * hvgr_pm_driver_wait_core_trans_end - Wait until the core is powered on
 * or powered off.
 *
 * @param gdev - The gdev object pointer.
 * @cores - Core bitmap expected to be powered on or powered off.
 * @trans_reg - Reg address.
 * @pfunc - Power-on or power-off completion decision function.
 *
 * @return: True if Complete power-on and power-off within the specified time.
 *          False if Power-on/off timeout and the gpu will be reset.
 *
 * @date - 2021-02-03
 */
bool hvgr_pm_driver_wait_core_trans_end(struct hvgr_device *gdev,
	uint32_t cores, uint32_t trans_reg, hvgr_pm_is_core_trans_end pfunc);

/*
 * hvgr_pm_config_override -Config the override register.
 *
 * @param gdev - The gdev object pointer.
 *
 * @date - 2021-02-03
 */
void hvgr_pm_config_override(struct hvgr_device *gdev);

/*
 * hvgr_pm_driver_clock_off_pre_proc -Pretreatment before clock off.
 *
 * @param gdev - The gdev object pointer.
 *
 * @date - 2021-02-03
 */
void hvgr_pm_driver_clock_off_pre_proc(struct hvgr_device *gdev);

#endif
