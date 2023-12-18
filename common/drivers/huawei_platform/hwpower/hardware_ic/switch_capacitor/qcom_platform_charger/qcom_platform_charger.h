/* SPDX-License-Identifier: GPL-2.0 */
/*
 * qcom_platform_charger.h
 *
 * qcom_platform_charger driver
 *
 * Copyright (c) 2023-2023 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#ifndef _QPLAT_CHARGER_H_
#define _QPLAT_CHARGER_H_

#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/of_address.h>
#include <huawei_platform/hwpower/common_module/power_platform.h>
#include <chipset_common/hwpower/common_module/power_log.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_error_handle.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_ic.h>
#include <chipset_common/hwpower/charger/charger_common_interface.h>

struct qplat_charger_device_info {
	struct device *dev;
	struct dc_ic_ops sc_ops;
	struct dc_batinfo_ops batinfo_ops;
	char name[CHIP_DEV_NAME_LEN];
	int device_id;
	u32 ic_role;
	int sc_max_input_current;
	int sc_max_charge_current;
	int use_buck_as_sc;
	int use_buck_as_sc4;
};

/*************************marco define area***************************/
#define DEFAULT_SC_MAX_INPUT_CURRENT         1200
#define DEFAULT_SC_MAX_CHARGE_CURRENT        2000
#define DEFAULT_FAKE_SC_TEMP                 30

#endif /* _qplat_charger_H_ */
