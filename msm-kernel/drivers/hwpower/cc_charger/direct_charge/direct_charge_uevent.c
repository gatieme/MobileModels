// SPDX-License-Identifier: GPL-2.0
/*
 * direct_charge_uevent.c
 *
 * uevent handle for direct charge
 *
 * Copyright (c) 2020-2020 Huawei Technologies Co., Ltd.
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

#include <huawei_platform/power/direct_charger/direct_charger.h>
#include <huawei_platform/power/battery_voltage.h>
#include <chipset_common/hwpower/common_module/power_common_macro.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_common.h>

#define HWLOG_TAG direct_charge_uevent
HWLOG_REGIST();

#define CTC_EMARK_CURR_5A         5000

static int dc_get_max_current(void)
{
	int adp_limit;
	int cable_limit;
	int bat_limit;
	int max_cur;
	int bat_vol = hw_battery_get_series_num() * BAT_RATED_VOLT;
	struct direct_charge_device *l_di = direct_charge_get_di();

	if (!l_di)
		return 0;

	/* get max current by adapter */
	adp_limit = dc_get_adapter_max_current(l_di->local_mode, bat_vol * l_di->dc_volt_ratio);
	adp_limit *= l_di->dc_volt_ratio;

	/* get max current by battery */
	bat_limit = direct_charge_get_product_max_current(l_di->working_mode);

	/* get max current by cable */
	cable_limit = dc_get_cable_curr();
	dc_update_cable_max_current(&cable_limit);
	if (cable_limit > 0)
		max_cur = (bat_limit < cable_limit) ? bat_limit : cable_limit;
	else
		max_cur = bat_limit;

	if (adp_limit)
		max_cur = (max_cur < adp_limit) ? max_cur : adp_limit;

	l_di->max_pwr = max_cur * bat_vol;
	l_di->max_pwr /= POWER_UW_PER_MW;

	hwlog_info("l_adp=%d, l_cable=%d, l_bat=%d, m_cur=%d, m_pwr=%d\n",
		adp_limit, cable_limit, bat_limit, max_cur, l_di->max_pwr);

	return max_cur;
}

void dc_send_icon_uevent(void)
{
	struct direct_charge_device *l_di = direct_charge_get_di();
	int max_cur = dc_get_max_current();

	if (!l_di)
		return;

	if (direct_charge_is_priority_inversion() || dc_comm_get_icon_send_flag()) {
		hwlog_info("icon type already send\n");
		return;
	}

	if (max_cur >= l_di->super_ico_current)
		wired_connect_send_icon_uevent(ICON_TYPE_SUPER);
	else
		wired_connect_send_icon_uevent(ICON_TYPE_QUICK);
	dc_comm_set_icon_send_flag(true);
}

void dc_send_max_power_uevent(void)
{
	struct direct_charge_device *l_di = direct_charge_get_di();

	if (!l_di || l_di->ui_max_pwr <= 0)
		return;

	if (l_di->max_pwr >= l_di->ui_max_pwr)
		power_ui_event_notify(POWER_UI_NE_MAX_POWER, &l_di->max_pwr);
}

void dc_send_soc_decimal_uevent(void)
{
	struct direct_charge_device *l_di = direct_charge_get_di();

	if (!l_di)
		return;

	power_event_bnc_notify(POWER_BNT_SOC_DECIMAL, POWER_NE_SOC_DECIMAL_DC, &l_di->max_pwr);
}
