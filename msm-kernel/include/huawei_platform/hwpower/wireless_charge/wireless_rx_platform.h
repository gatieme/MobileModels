/* SPDX-License-Identifier: GPL-2.0 */
/*
 * wireless_rx_platform.h
 *
 * platform interface for wireless charging
 *
 * Copyright (c) 2021-2021 Huawei Technologies Co., Ltd.
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

#ifndef _WIRELESS_RX_PLATFORM_
#define _WIRELESS_RX_PLATFORM_

#include <chipset_common/hwpower/wireless_charge/wireless_buck_ictrl.h>
#include <chipset_common/hwpower/common_module/power_icon.h>
#include <linux/types.h>

struct wlrx_pmode;

bool wlrx_bst_rst_completed(void);
int wireless_charge_get_rx_iout_limit(void);
int charge_set_wls_icl(int iin_ma);
bool wlc_pmode_final_judge(unsigned int drv_type, int pid, struct wlrx_pmode *pcfg);

static inline int wlrx_buck_set_dev_iin(int iin_ma)
{
	return charge_set_wls_icl(iin_ma);
}

static inline int wlrx_buck_get_iin_regval(unsigned int drv_type)
{
	return wlrx_buck_get_iset(drv_type);
}

static inline void wireless_connect_send_icon_uevent(int icon_type)
{
	power_icon_notify(icon_type);
}

#endif /* _WIRELESS_RX_PLATFORM_ */
