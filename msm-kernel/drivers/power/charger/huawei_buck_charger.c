/* SPDX-License-Identifier: GPL-2.0 */
/*
 * huawei_buck_charger
 *
 * huawei buck charger driver
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

#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/jiffies.h>
#include <linux/hrtimer.h>
#include <linux/usb/otg.h>
#include <linux/io.h>
#include <linux/gpio.h>
#include <linux/power_supply.h>
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/notifier.h>
#include <linux/mutex.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <charging_core.h>
#include <huawei_platform/log/hw_log.h>
#include <huawei_platform/log/hwlog_kernel.h>
#include <huawei_platform/usb/switch/usbswitch_common.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_common_macro.h>
#include <chipset_common/hwpower/common_module/power_icon.h>
#include <chipset_common/hwpower/common_module/power_time.h>
#include <chipset_common/hwpower/common_module/power_wakeup.h>
#include <huawei_platform/hwpower/common_module/power_platform.h>
#include <huawei_platform/hwpower/common_module/power_platform_macro.h>
#include <chipset_common/hwpower/common_module/power_cmdline.h>
#include <chipset_common/hwpower/common_module/power_interface.h>
#include <chipset_common/hwpower/hardware_channel/vbus_channel.h>
#include <chipset_common/hwpower/charger/charger_common_interface.h>
#include <chipset_common/hwpower/common_module/power_supply.h>
#include <chipset_common/hwpower/common_module/power_supply_interface.h>
#include <chipset_common/hwpower/common_module/power_sysfs.h>
#include <chipset_common/hwpower/common_module/power_dsm.h>
#ifdef CONFIG_TCPC_CLASS
#include <huawei_platform/usb/hw_pd_dev.h>
#endif
#include <huawei_platform/power/huawei_charger.h>
#include <chipset_common/hwpower/hardware_monitor/uscp.h>
#include <huawei_platform/power/battery_voltage.h>
#include <chipset_common/hwpower/battery/battery_temp.h>
#include <chipset_common/hwpower/hardware_ic/boost_5v.h>
#include <chipset_common/hwpower/adapter/adapter_detect.h>
#include <chipset_common/hwpower/hvdcp_charge/hvdcp_charge.h>
#include <huawei_platform/power/huawei_charger_adaptor.h>
#include <chipset_common/hwpower/charger/charge_manager.h>
#include <chipset_common/hwpower/hardware_monitor/ffc_control.h>

#define HWLOG_TAG huawei_buck_charger
HWLOG_REGIST();

#define VBUS_REPORT_NUM                     4

extern struct charge_device_ops *g_ops;
static struct charge_device_info *g_buck_di;
struct charge_init_data g_init_crit;

static int vbus_flag;
static int nonfcp_vbus_higher_count;
static int fcp_vbus_lower_count;
static int pd_vbus_abnormal_cnt;

bool charge_support_thirdparty_buck(void)
{
	return g_buck_di != NULL;
}

int get_charge_done_type(void)
{
	struct charge_device_info *di = g_buck_di;

	if (!di) {
		hwlog_err("%s g_di is null\n", __func__);
		return CHARGE_DONE_NON;
	}

	if (di->sysfs_data.charge_done_status == CHARGE_DONE)
		return CHARGE_DONE;
	else
		return CHARGE_DONE_NON;
}

static int buck_get_iin_thermal_type(void)
{
	if (g_init_crit.charger_type == CHARGER_TYPE_WIRELESS)
		return (g_init_crit.vbus == ADAPTER_5V) ?
			IIN_THERMAL_WLCURRENT_5V : IIN_THERMAL_WLCURRENT_9V;

	return (g_init_crit.vbus == ADAPTER_5V) ?
		IIN_THERMAL_WCURRENT_5V : IIN_THERMAL_WCURRENT_9V;
}

int charge_set_input_current(int iin)
{
	struct charge_device_info *di = g_buck_di;

	if (!di)
		return -EPERM;

	hwlog_info("%s: iin = %d, di->input_current = %d\n", __func__, iin, di->input_current);
	iin = (iin < di->input_current) ? iin : di->input_current;

	return charge_set_dev_iin(iin);
}

int charge_set_iin_rt_curr(int iin_rt_curr)
{
	struct charge_device_info *di = g_buck_di;

	if (!di) {
		hwlog_err("g_buck_di is null\n");
		return -1;
	}

	di->sysfs_data.iin_rt_curr = iin_rt_curr;
	return 0;
}

int charge_set_input_current_max(void)
{
	int ret;
	struct charge_device_info *di = g_buck_di;

	if (!di)
		return -EPERM;

	di->input_current = di->core_data->iin_max;
	ret = charge_set_dev_iin(di->input_current);
	if (ret) {
		hwlog_err("%s:set input current %d fail\n", __func__, di->input_current);
		return -1;
	}
	hwlog_info("%s:set input current %d succ\n", __func__, di->input_current);
	return 0;
}

int charge_get_input_current_max(void)
{
	struct charge_device_info *di = g_buck_di;

	if (!di)
		return 500; /* 500:default max input current for usb */

	return di->input_current;
}

static void charge_vbus_voltage_check(struct charge_device_info *di)
{
}

void buck_charge_set_pd_vbus_state(struct pd_dpm_vbus_state *vbus_state)
{
	struct charge_device_info *di = g_buck_di;

	if (!di || !vbus_state)
		return;

	/* 100:converted into mv */
	di->pd_input_current = vbus_state->ma;
	di->pd_charge_current = (vbus_state->mv * vbus_state->ma *
		di->pd_cur_trans_ratio) / (100 * di->core_data->vterm);
}

static void pd_charge_check(struct charge_device_info *di)
{
#ifdef CONFIG_TCPC_CLASS
	if (charge_get_pd_charge_flag())
		return;
	if (charge_get_monitor_work_flag() == CHARGE_MONITOR_WORK_NEED_STOP)
		return;

	if ((charge_get_charger_type() != CHARGER_TYPE_PD) || !power_platform_is_battery_exit())
		return;

	if (dc_adpt_get_inherent_info(ADPT_ANTIFAKE_RESULT) == ADAPTER_ANTIFAKE_FAIL) {
		hwlog_info("[%s] adapter is fake\n", __func__);
		return;
	}

	if (pd_dpm_get_high_voltage_charging_status() == true) {
		g_init_crit.vbus = ADAPTER_9V;
		power_icon_notify(ICON_TYPE_QUICK);
	} else {
		g_init_crit.vbus = ADAPTER_5V;
	}
	g_init_crit.charger_type = charge_get_charger_type();
	(void)charge_init_chip(&g_init_crit);

	if (pd_dpm_get_high_voltage_charging_status())
		(void)charge_set_vbus_vset(ADAPTER_9V);
	else
		(void)charge_set_vbus_vset(ADAPTER_5V);

	hwlog_info("%s: ok\n", __func__);
	charge_set_pd_charge_flag(true);
#endif
}

static void charge_select_charging_current(struct charge_device_info *di)
{
	int idx;
#ifndef CONFIG_HLTHERM_RUNTEST
	static unsigned int first_in = 1;
#endif

	if (charge_get_monitor_work_flag() == CHARGE_MONITOR_WORK_NEED_STOP)
		return;

	switch (charge_get_charger_type()) {
	case CHARGER_TYPE_USB:
		di->input_current = di->core_data->iin_usb;
		di->charge_current = di->core_data->ichg_usb;
		break;
	case CHARGER_TYPE_NON_STANDARD:
		di->input_current = di->core_data->iin_nonstd;
		di->charge_current = di->core_data->ichg_nonstd;
		break;
	case CHARGER_TYPE_BC_USB:
		di->input_current = di->core_data->iin_bc_usb;
		di->charge_current = di->core_data->ichg_bc_usb;
		break;
	case CHARGER_TYPE_STANDARD:
		di->input_current = di->core_data->iin_ac;
		di->charge_current = di->core_data->ichg_ac;
		break;
	case CHARGER_TYPE_VR:
		di->input_current = di->core_data->iin_vr;
		di->charge_current = di->core_data->ichg_vr;
		break;
	case CHARGER_TYPE_FCP:
		di->input_current = di->core_data->iin_fcp;
		di->charge_current = di->core_data->ichg_fcp;
		break;
	case CHARGER_TYPE_PD:
		di->input_current = di->pd_input_current;
		di->charge_current = di->pd_charge_current;
		hwlog_info("CHARGER_TYPE_PD input_current %d  charge_current = %d",
			di->input_current, di->charge_current);
		if (di->charge_current > di->core_data->ichg_fcp)
			di->charge_current = di->core_data->ichg_fcp;
		break;
	default:
		di->input_current = CHARGE_CURRENT_0500_MA;
		di->charge_current = CHARGE_CURRENT_0500_MA;
		break;
	}

#ifndef CONFIG_HLTHERM_RUNTEST
	if (power_cmdline_is_factory_mode() && !power_platform_is_battery_exit()) {
		if (first_in) {
			hwlog_info("facory_version and battery not exist, enable charge\n");
			first_in = 0;
		}
	} else {
#endif
		if (di->sysfs_data.charge_limit == TRUE) {
			idx = buck_get_iin_thermal_type();
			di->sysfs_data.iin_thl = di->sysfs_data.iin_thl_array[idx];
			hwlog_info("iin_thermal=%u, type_id=%d, input_current = %d, iin = %d, iin_rt_curr = %d\n",
				di->sysfs_data.iin_thl, idx, di->input_current, di->core_data->iin,
				di->sysfs_data.iin_rt_curr);
			di->input_current = (di->input_current < di->core_data->iin) ?
				di->input_current : di->core_data->iin;
			di->input_current = (di->input_current < di->sysfs_data.iin_thl) ?
				di->input_current : di->sysfs_data.iin_thl;
			/* hisi:iin_runningtest other platform:iin_rt_curr */
			di->input_current = (di->input_current < di->sysfs_data.iin_rt_curr) ?
				di->input_current : di->sysfs_data.iin_rt_curr;
			di->charge_current = (di->charge_current < di->core_data->ichg) ?
				di->charge_current : di->core_data->ichg;
			di->charge_current = (di->charge_current < di->sysfs_data.ichg_thl) ?
				di->charge_current : di->sysfs_data.ichg_thl;
			di->charge_current = (di->charge_current < di->sysfs_data.ichg_rt) ?
				di->charge_current : di->sysfs_data.ichg_rt;
		}
#ifndef CONFIG_HLTHERM_RUNTEST
	}
#endif

	if (di->sysfs_data.inputcurrent != 0)
		di->input_current = min(di->input_current,
			(unsigned int)di->sysfs_data.inputcurrent);

	if (di->sysfs_data.batfet_disable == 1)
		di->input_current = CHARGE_CURRENT_2000_MA;
}

#ifdef CONFIG_TCPC_CLASS
static int charge_update_pd_vbus_check(struct charge_device_info *di)
{
	int ret;
	unsigned int vbus_vol = 0;

	if (!di) {
		hwlog_err("input para is null, just return false\n");
		return FALSE;
	}
	if (charge_get_charger_type() == CHARGER_TYPE_PD) {
		if (di->ops && di->ops->get_vbus) {
			ret = di->ops->get_vbus(&vbus_vol);
		} else {
			hwlog_err("not support vbus check\n");
			ret = FALSE;
		}
		if (ret) {
			hwlog_err("[%s]vbus vol read fail\n", __func__);
			ret = pd_dpm_get_high_power_charging_status() ? TRUE : FALSE;
		} else {
			ret = (vbus_vol > VBUS_VOLTAGE_7000_MV) ? TRUE : FALSE;
		}
		return ret;
	}
	return FALSE;
}
#endif

static void charge_update_vindpm(struct charge_device_info *di)
{
	int ret;
	int vindpm = CHARGE_VOLTAGE_4520_MV;

	if (charge_get_monitor_work_flag() == CHARGE_MONITOR_WORK_NEED_STOP)
		return;
	if ((hvdcp_get_charging_stage() == HVDCP_STAGE_SUCCESS)
#ifdef CONFIG_TCPC_CLASS
	|| charge_update_pd_vbus_check(di)
#endif
	) {
		vindpm = di->fcp_vindpm;
	} else if (charge_get_charger_source() == POWER_SUPPLY_TYPE_MAINS) {
		vindpm = di->core_data->vdpm;
	} else if (charge_get_charger_source() == POWER_SUPPLY_TYPE_USB) {
		if (di->core_data->vdpm > CHARGE_VOLTAGE_4520_MV)
			vindpm = di->core_data->vdpm;
	}

	hwlog_info("update_vindpm %dmv\n", vindpm);
	if (di->ops->set_dpm_voltage) {
		ret = di->ops->set_dpm_voltage(vindpm);
		if (ret > 0) {
			hwlog_info("dpm voltage is out of range:%dmV\n", ret);
			ret = di->ops->set_dpm_voltage(ret);
			if (ret < 0)
				hwlog_err("set dpm voltage fail\n");
		} else if (ret < 0) {
			hwlog_err("set dpm voltage fail\n");
		}
	}
}

static void charge_update_external_setting(struct charge_device_info *di)
{
	unsigned int batfet_disable = FALSE;
	unsigned int watchdog_timer = CHAGRE_WDT_80S;

	if (charge_get_monitor_work_flag() == CHARGE_MONITOR_WORK_NEED_STOP)
		return;

	/* update batfet setting */
	if (di->sysfs_data.batfet_disable == TRUE)
		batfet_disable = TRUE;

	(void)charge_set_batfet_disable(batfet_disable);

	/* update watch dog timer setting */
	if (di->sysfs_data.wdt_disable == TRUE)
		watchdog_timer = CHAGRE_WDT_DISABLE;

	(void)charge_set_watchdog(watchdog_timer);
}

void buck_charge_update_iterm(int iterm)
{
	struct charge_device_info *di = g_buck_di;

	if (!di || !di->core_data || (iterm == 0))
		return;
	hwlog_info("%s, iterm = %d\n", __func__, iterm);
	di->core_data->iterm = iterm;
}

static int charge_is_charging_full(struct charge_device_info *di)
{
	int ichg = -power_platform_get_battery_current();
	int ichg_avg = charge_get_battery_current_avg();
	int val = FALSE;
	int term_allow = FALSE;
	int bat_cap = 0;

	if (!di->charge_enable || !power_platform_is_battery_exit())
		return val;

	if (((ichg > MIN_CHARGING_CURRENT_OFFSET) && (ichg_avg > MIN_CHARGING_CURRENT_OFFSET)) ||
		di->core_data->warm_triggered)
		term_allow = TRUE;
	hwlog_info("term_allow = %d, ichg = %d, ichg_avg = %d, iterm = %d", (int)term_allow,
		ichg, ichg_avg, (int)di->core_data->iterm);
	if (term_allow && (ichg < (int)di->core_data->iterm) &&
		(ichg_avg < (int)di->core_data->iterm)) {
		di->check_full_count++;
		if (di->check_full_count >= BATTERY_FULL_CHECK_TIMIES) {
			di->check_full_count = BATTERY_FULL_CHECK_TIMIES;
			val = TRUE;
			power_supply_get_int_prop(POWER_PLATFORM_BAT_PSY_NAME,
				POWER_SUPPLY_PROP_CAPACITY, &bat_cap,
				POWER_SUPPLY_DEFAULT_CAPACITY, 1);
			hwlog_info("capacity = %d, ichg = %d, ichg_avg = %d\n",
				bat_cap, ichg, ichg_avg);
		}
	} else {
		di->check_full_count = 0;
	}

	return val;
}

static void charge_full_handle(struct charge_device_info *di)
{
	int ret;
	int is_battery_full = charge_is_charging_full(di);
	int bat_cap = 0;

	if (charge_get_monitor_work_flag() == CHARGE_MONITOR_WORK_NEED_STOP)
		return;

	if (!di || !di->ops || !di->ops->set_term_enable ||
		!di->ops->set_terminal_voltage ||
		!di->ops->set_charge_current) {
		hwlog_err("di or ops is null\n");
		return;
	}

	if (di->ops->set_term_enable) {
		ret = di->ops->set_term_enable(is_battery_full);
		if (ret)
			hwlog_err("set term enable fail\n");
	}

	/* set terminal current */
	ret = di->ops->set_terminal_current(di->core_data->iterm);
	if (ret > 0)
		di->ops->set_terminal_current(ret);
	else if (ret < 0)
		hwlog_err("set terminal current fail\n");

	/*
	 * reset adapter to 5v after fcp charge done(soc is 100),
	 * avoid long-term at high voltage
	 */
	power_supply_get_int_prop(POWER_PLATFORM_BAT_PSY_NAME,
		POWER_SUPPLY_PROP_CAPACITY, &bat_cap,
		POWER_SUPPLY_DEFAULT_CAPACITY, 1);
	if (is_battery_full && (bat_cap == 100)) {
		if (hvdcp_get_charging_stage() == HVDCP_STAGE_RESET_ADAPTER) {
			hvdcp_set_charging_stage(HVDCP_STAGE_CHARGE_DONE);
			hwlog_info("reset adapter to 5v already\n");
		} else if (hvdcp_get_charging_stage() == HVDCP_STAGE_SUCCESS) {
			if ((di->charge_done_maintain_fcp == 1) &&
				!power_cmdline_is_powerdown_charging_mode()) {
				hwlog_info("fcp charge done, no reset adapter to 5v\n");
			} else {
				(void)hvdcp_decrease_adapter_voltage_to_5v();
				hvdcp_set_charging_stage(HVDCP_STAGE_CHARGE_DONE);
				(void)charge_set_vbus_vset(ADAPTER_5V);
				hwlog_info("fcp charge done, reset adapter to 5v\n");
			}
		}
	}
}

static int set_charge_state(int state)
{
	int old_state;
	int chg_en;
	struct charge_device_info *di = g_buck_di;

	if (!di || ((state != 0) && (state != 1)) || !di->ops->get_charge_enable_status)
		return -1;

	old_state = di->ops->get_charge_enable_status();
	chg_en = state;
	di->ops->set_charge_enable(chg_en);

	return old_state;
}

bool charge_get_hiz_state(void)
{
	bool ret = false;
	struct charge_device_info *di = g_buck_di;

	if (!di)
		return false;
	mutex_lock(&di->mutex_hiz);
	if (di->hiz_ref)
		ret = true;
	else
		ret = false;
	mutex_unlock(&di->mutex_hiz);
	return ret;
}

int charge_set_hiz_enable_by_direct_charge(int enable)
{
	struct charge_device_info *di = g_buck_di;

	if (!di)
		return -1;

	if (enable)
		di->is_dc_enable_hiz = true;
	else
		di->is_dc_enable_hiz = false;
	return charge_set_hiz_enable(enable);
}

int set_charger_disable_flags(int val, int type)
{
	struct charge_device_info *di = g_buck_di;
	int i;
	int disable = 0;

	if (!di) {
		hwlog_err("NULL pointer(di) found in %s\n", __func__);
		return -1;
	}

	if ((type < 0) || (type >= __MAX_DISABLE_CHAGER)) {
		hwlog_err("invalid disable_type=%d\n", type);
		return -1;
	}

	di->sysfs_data.disable_charger[type] = val;
	for (i = 0; i < __MAX_DISABLE_CHAGER; i++)
		disable |= di->sysfs_data.disable_charger[i];

	if (di->sysfs_data.charge_enable == disable) {
		di->sysfs_data.charge_enable = !disable;
		if (!di->sysfs_data.charge_enable)
			di->ops->set_charge_enable(di->sysfs_data.charge_enable);
	}
	return 0;
}

int buck_sysfs_set_dcp_enable_charger(int val)
{
	int ret;
	int usb_in = 0;
	int wls_in = 0;
	int tbatt = DEFAULT_NORMAL_TEMP;
	struct charge_device_info *di = g_buck_di;

	if (!di || (val < 0) || (val > 1))
		return -EINVAL;

	ret = set_charger_disable_flags(
		val ? CHARGER_CLEAR_DISABLE_FLAGS : CHARGER_SET_DISABLE_FLAGS,
		CHARGER_SYS_NODE);
	if (ret < 0)
		return -EINVAL;

	di->sysfs_data.charge_limit = TRUE;

	hwlog_info("set_dcp_enable_charger: en=%d\n", di->sysfs_data.charge_enable);

	bat_temp_get_rt_temperature(BAT_TEMP_MIXED, &tbatt);

	if (di->sysfs_data.charge_enable) {
		if (((tbatt > BATT_EXIST_TEMP_LOW) && (tbatt <= NO_CHG_TEMP_LOW)) ||
			(tbatt >= NO_CHG_TEMP_HIGH)) {
			hwlog_err("battery temp is %d, abandon enable_charge\n", tbatt);
			return -EINVAL;
		}
	}
	di->ops->set_charge_enable(di->sysfs_data.charge_enable);

	(void)power_supply_get_int_property_value("usb",
		POWER_SUPPLY_PROP_ONLINE, &usb_in);
	(void)power_supply_get_int_property_value("Wireless",
		POWER_SUPPLY_PROP_ONLINE, &wls_in);

	hwlog_err("set_dcp_enable_charger: usb_in=%d, wls_in=%d\n", usb_in, wls_in);
	if (usb_in || wls_in) {
		if (val)
			power_event_bnc_notify(POWER_BNT_CHARGING,
				POWER_NE_CHARGING_START, NULL);
		else
			power_event_bnc_notify(POWER_BNT_CHARGING,
				POWER_NE_CHARGING_SUSPEND, NULL);
	} else {
		power_event_bnc_notify(POWER_BNT_CHARGING,
			POWER_NE_CHARGING_STOP, NULL);
	}

	return 0;
}

#ifndef CONFIG_HLTHERM_RUNTEST
static int buck_dcp_set_iin_thermal_array(unsigned int idx, unsigned int val)
{
	struct charge_device_info *di = g_buck_di;

	if (!di || (val > di->core_data->iin_max))
		return -EINVAL;

	/* 100 : iin_thl_min 100mA */
	if ((val == 0) || (val == 1))
		di->sysfs_data.iin_thl_array[idx] = di->core_data->iin_max;
	else if ((val > 1) && (val <= 100))
		di->sysfs_data.iin_thl_array[idx] = 100;
	else
		di->sysfs_data.iin_thl_array[idx] = val;
	hwlog_info("thermal set input current = %d, type: %u\n", di->sysfs_data.iin_thl_array[idx], idx);

	if (idx != buck_get_iin_thermal_type())
		return 0;

	charge_select_charging_current(di);
	(void)charge_set_input_current(di->input_current);
	hwlog_info("thermal set input current = %d\n",
		di->sysfs_data.iin_thl);
	return 0;
}
#else
static int buck_dcp_set_iin_thermal_array(unsigned int idx, unsigned int val)
{
	return 0;
}
#endif /* CONFIG_HLTHERM_RUNTEST */

int buck_sysfs_set_dcp_iin_thermal_array(unsigned int idx, unsigned int val)
{
	if (idx >= IIN_THERMAL_CHARGE_TYPE_END) {
		hwlog_err("error index: %u, out of boundary\n", idx);
		return -1;
	}
	return buck_dcp_set_iin_thermal_array(idx, val);
}

void buck_charge_init_chip(void)
{
	/* chip init */
	g_init_crit.vbus = ADAPTER_5V;
	g_init_crit.charger_type = charge_get_charger_type();
	(void)charge_init_chip(&g_init_crit);
	power_platform_charge_enable_sys_wdt();
}

void buck_charge_stop_charging(void)
{
	int ret;
	struct charge_device_info *di = g_buck_di;

	if (!di)
		return;

	di->sysfs_data.adc_conv_rate = 0;
	di->sysfs_data.charge_done_status = CHARGE_DONE_NON;
	di->weaksource_cnt = 0;
	di->core_data->iterm = di->core_data->initial_iterm;
#ifdef CONFIG_TCPC_CLASS
	di->pd_input_current = 0;
	di->pd_charge_current = 0;
#endif

	if (adapter_set_default_param(ADAPTER_PROTOCOL_FCP))
		hwlog_err("fcp set default param failed\n");

	vbus_flag = 0;
	nonfcp_vbus_higher_count = 0;
	fcp_vbus_lower_count = 0;
	pd_vbus_abnormal_cnt = 0;
	hvdcp_reset_flags();
	if (di->ops->set_adc_conv_rate)
		di->ops->set_adc_conv_rate(di->sysfs_data.adc_conv_rate);
	di->check_full_count = 0;
	ret = di->ops->set_charge_enable(FALSE);
	if (ret)
		hwlog_err("[%s]set charge enable fail\n", __func__);

	/* when the charger is plug out, disable watch dog */
	if (charge_set_watchdog(CHAGRE_WDT_DISABLE))
		hwlog_err("set watchdog timer fail\n");

	if (di->ops->stop_charge_config) {
		if (di->ops->stop_charge_config())
			hwlog_err("stop charge config failed\n");
	}

	if (adapter_stop_charging_config(ADAPTER_PROTOCOL_FCP))
		hwlog_err("fcp stop charge config failed\n");

	hvdcp_set_charging_stage(HVDCP_STAGE_DEFAUTL);
	hvdcp_set_charging_flag(false);
}

static void charge_pd_voltage_change_work(struct work_struct *work)
{
#ifdef CONFIG_TCPC_CLASS_BAK
	int vset;
	int ret;

	if (charge_get_reset_adapter_source())
		vset = ADAPTER_5V * POWER_MV_PER_V;
	else
		vset = ADAPTER_9V * POWER_MV_PER_V;

	if (vset != last_vset) {
		ret = adapter_set_output_voltage(ADAPTER_PROTOCOL_PD, vset);
		if (ret)
			hwlog_err("[%s]set voltage failed\n", __func__);
	}
#endif
}

static void charge_fault_work(struct work_struct *work)
{
	struct charge_device_info *di = container_of(work, struct charge_device_info, fault_work);

	switch (di->charge_fault) {
	case POWER_NE_CHG_FAULT_BOOST_OCP:
		if (charge_check_charger_otg_state()) {
			hwlog_err("vbus overloaded in boost mode,close otg mode\n");
			vbus_ch_close(VBUS_CH_USER_WIRED_OTG,
				VBUS_CH_TYPE_CHARGER, false, true);
			di->charge_fault = POWER_NE_CHG_FAULT_NON;
		}
		break;
	case POWER_NE_CHG_FAULT_VBAT_OVP:
		if (!di->core_data->warm_triggered) {
			hwlog_err("vbat_ovp happend\n");
			di->charge_fault = POWER_NE_CHG_FAULT_NON;
		}
		break;
	case POWER_NE_CHG_FAULT_WEAKSOURCE:
		hwlog_err("Weaksource happened\n");
		di->charge_fault = POWER_NE_CHG_FAULT_NON;
		break;
	case POWER_NE_CHG_FAULT_CHARGE_DONE:
		hwlog_info("charge done happened\n");
		break;
	default:
		break;
	}
}

static void charge_update_status(struct charge_device_info *di)
{
	enum charge_status_event events;
	unsigned int state = CHAGRE_STATE_NORMAL;
	int ret;
	static bool last_warm_triggered;

	if (charge_get_monitor_work_flag() == CHARGE_MONITOR_WORK_NEED_STOP)
		return;
#ifdef CONFIG_DIRECT_CHARGER
	if (charge_need_ignore_plug_event())
		return;
#endif
	ret = di->ops->get_charge_state(&state);
	if (ret < 0) {
		hwlog_err("get_charge_state fail ret = 0x%x\n", ret);
		return;
	}

	/* check status charger ovp err */
	if (state & CHAGRE_STATE_VBUS_OVP) {
		hwlog_err("VCHRG_POWER_SUPPLY_OVERVOLTAGE\n");
		events = VCHRG_POWER_SUPPLY_OVERVOLTAGE;
		charge_send_uevent(events);
		return;
	}
	/* check status watchdog timer expiration */
	if (state & CHAGRE_STATE_WDT_FAULT) {
		hwlog_err("CHAGRE_STATE_WDT_TIMEOUT\n");
		/* init chip register when watchdog timeout */
		g_init_crit.vbus = ADAPTER_5V;
		g_init_crit.charger_type = charge_get_charger_type();
		(void)charge_init_chip(&g_init_crit);
		events = VCHRG_STATE_WDT_TIMEOUT;
		charge_send_uevent(events);
	}
	/* check status battery ovp */
	if (state & CHAGRE_STATE_BATT_OVP)
		hwlog_err("CHAGRE_STATE_BATT_OVP\n");

	/* check status charge done, ac charge and usb charge */
	if (di->charge_enable && power_platform_is_battery_exit()) {
		di->sysfs_data.charge_done_status = CHARGE_DONE_NON;
		if (last_warm_triggered ^ di->core_data->warm_triggered) {
			last_warm_triggered = di->core_data->warm_triggered;
			ret = di->ops->set_charge_enable(FALSE);
			msleep(DT_MSLEEP_100MS);
			ret |= di->ops->set_charge_enable(TRUE & di->sysfs_data.charge_enable);
			if (ret)
				hwlog_err("[%s]set charge enable fail\n", __func__);
			hwlog_info("warm status changed, resume charging\n");
			return;
		}

		if ((state & CHAGRE_STATE_CHRG_DONE) && !di->core_data->warm_triggered) {
			if (charge_get_charger_type() == CHARGER_REMOVED)
				return;

			events = VCHRG_CHARGE_DONE_EVENT;
			hwlog_info("VCHRG_CHARGE_DONE_EVENT\n");
			di->sysfs_data.charge_done_status = CHARGE_DONE;
			if (di->release_lock_support)
				charge_manager_release_charge_lock();
			power_event_bnc_notify(POWER_BNT_CHG, POWER_NE_CHG_CHARGING_DONE, NULL);
		} else if (charge_get_charger_source() == POWER_SUPPLY_TYPE_MAINS) {
			events = VCHRG_START_AC_CHARGING_EVENT;
		} else if (charge_get_charger_source() == POWER_SUPPLY_TYPE_BATTERY) {
			events = VCHRG_NOT_CHARGING_EVENT;
			hwlog_info("VCHRG_NOT_CHARGING_EVENT, power_supply: BATTERY\n");
		} else {
			events = VCHRG_START_USB_CHARGING_EVENT;
		}
	} else {
		events = VCHRG_NOT_CHARGING_EVENT;
		hwlog_info("VCHRG_NOT_CHARGING_EVENT\n");
	}
	if (charge_get_monitor_work_flag() == CHARGE_MONITOR_WORK_NEED_STOP)
		return;

	if (charge_get_charger_type() == CHARGER_REMOVED)
		return;

	charge_send_uevent(events);
}

static void charge_turn_on_charging(struct charge_device_info *di)
{
	int ret;
	unsigned int vterm = BATTERY_VOLTAGE_4500_MV;
	int increase_volt;

	if (charge_get_monitor_work_flag() == CHARGE_MONITOR_WORK_NEED_STOP)
		return;

	if (!di || !di->ops || !di->core_data || !di->ops->set_charge_current ||
		!di->ops->set_terminal_voltage) {
		hwlog_err("di or ops is null\n");
		return;
	}

	di->charge_enable = TRUE;
	charge_vbus_voltage_check(di);
	(void)charge_set_input_current(di->input_current);

	if (di->charge_current == CHARGE_CURRENT_0000_MA) {
		di->charge_enable = FALSE;
		hwlog_info("charge current is set 0mA, turn off charging\n");
	} else {
		/* set CC charge current */
		ret = di->ops->set_charge_current(di->charge_current);
		if (ret > 0) {
			hwlog_info("charge current is out of range:%dmA\n", ret);
			di->ops->set_charge_current(ret);
		} else if (ret < 0) {
			hwlog_err("set charge current fail\n");
		}

		/* set CV terminal voltage */
		if (power_cmdline_is_factory_mode() && !power_platform_is_battery_exit()) {
			if (power_supply_check_psy_available("battery", &di->batt_psy))
				(void)power_supply_get_int_property_value_with_psy(di->batt_psy,
					POWER_SUPPLY_PROP_VOLTAGE_MAX_DESIGN, &vterm);
			hwlog_info("facory_version and battery not exist, vterm is set to %d\n", vterm);
		} else {
			vterm = ((di->core_data->vterm < di->sysfs_data.vterm_rt) ?
				di->core_data->vterm : di->sysfs_data.vterm_rt);
		}

		increase_volt = ffc_ctrl_get_incr_vterm();
		vterm += increase_volt;
		hwlog_info("set vterm %d, increase_volt = %d\n", vterm, increase_volt);
		ret = di->ops->set_terminal_voltage(vterm);
		if (ret > 0) {
			hwlog_info("terminal voltage is out of range:%dmV\n", ret);
			di->ops->set_terminal_voltage(ret);
		} else if (ret < 0) {
			hwlog_err("set terminal voltage fail\n");
		}
	}

	/* enable/disable charge */
	di->charge_enable &= di->sysfs_data.charge_enable;
	ret = di->ops->set_charge_enable(di->charge_enable);
	if (!di->sysfs_data.charge_enable)
		hwlog_info("Disable flags: sysnode = %d, isc = %d",
			di->sysfs_data.disable_charger[CHARGER_SYS_NODE],
			di->sysfs_data.disable_charger[CHARGER_FATAL_ISC_TYPE]);
	if (ret)
		hwlog_err("set charge enable fail\n");
	hwlog_info("turn_on_charging iin=%d ichg=%d vterm=%d chg_en=%d\n",
		di->input_current, di->charge_current, vterm, di->charge_enable);
}

static void buck_charge_fcp_check(void)
{
	int last_type = charge_get_charger_type();
	int curr_type;

	fcp_charge_entry();

	curr_type = charge_get_charger_type();
	if ((last_type != CHARGER_TYPE_FCP) && (curr_type == CHARGER_TYPE_FCP)) {
		g_init_crit.vbus = ADAPTER_9V;
		g_init_crit.charger_type = curr_type;
		(void)charge_init_chip(&g_init_crit);
	} else if ((last_type == CHARGER_TYPE_FCP) && (curr_type != CHARGER_TYPE_FCP)) {
		g_init_crit.vbus = ADAPTER_5V;
		g_init_crit.charger_type = curr_type;
		(void)charge_init_chip(&g_init_crit);
	}
}

void buck_charge_entry(void)
{
	struct charge_device_info *di = g_buck_di;

	if (!di) {
		hwlog_err("[%s], info is NULL\n", __func__);
		return;
	}

	hwlog_info("%s enter\n", __func__);

	pd_charge_check(di);
	if (charge_get_pd_init_flag())
		hwlog_info("wait pd init\n");
	else
		buck_charge_fcp_check();

	di->core_data = charge_core_get_params();
	if (!di->core_data) {
		hwlog_err("[%s], di->core_data is NULL\n", __func__);
		return;
	}

	charge_select_charging_current(di);
	charge_turn_on_charging(di);
	charge_full_handle(di);
	charge_update_vindpm(di);
	charge_update_external_setting(di);
	charge_update_status(di);
	charge_kick_watchdog();
}

static int huawei_get_charge_current_max(void)
{
	struct charge_device_info *di = g_buck_di;

	if (!di) {
		hwlog_err("[%s]di is NULL\n", __func__);
		return 0;
	}
	return di->charge_current;
}

static int charge_fault_notifier_call(struct notifier_block *fault_nb,
	unsigned long event, void *data)
{
	struct charge_device_info *di = container_of(fault_nb, struct charge_device_info, fault_nb);

	if (!di)
		return NOTIFY_OK;

	di->charge_fault = event;
	schedule_work(&di->fault_work);
	return NOTIFY_OK;
}

static bool charge_check_otg_state(void)
{
	int mode = VBUS_CH_NOT_IN_OTG_MODE;

	vbus_ch_get_mode(VBUS_CH_USER_WIRED_OTG, VBUS_CH_TYPE_CHARGER, &mode);
	return (bool)mode;
}

static void parse_extra_module_dts(struct charge_device_info *di)
{
}

static void charger_dts_read_u32(struct charge_device_info *di,
	struct device_node *np)
{
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"charge_done_maintain_fcp", &di->charge_done_maintain_fcp, 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"fcp_vindpm", &di->fcp_vindpm, CHARGE_VOLTAGE_4600_MV);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"scp_adp_normal_chg", &di->scp_adp_normal_chg, 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"startup_iin_limit", &di->startup_iin_limit, 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"hota_iin_limit", &di->hota_iin_limit, di->startup_iin_limit);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"increase_term_volt_en", &di->increase_term_volt_en, 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"smart_charge_support", &di->smart_charge_support, 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"pd_cur_trans_ratio", &di->pd_cur_trans_ratio, 88);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
                "release_lock_support", &di->release_lock_support, 0);
}

static inline void charger_dts_read_bool(struct device_node *np)
{
}

static void parse_charger_module_dts(struct charge_device_info *di,
	struct device_node *np)
{
	charger_dts_read_u32(di, np);
	charger_dts_read_bool(np);
}

static inline void charge_parse_dts(struct charge_device_info *di,
	struct device_node *np)
{
	parse_extra_module_dts(di);
	parse_charger_module_dts(di, np);
}

static struct charge_extra_ops huawei_charge_extra_ops = {
	.check_ts = NULL,
	.check_otg_state = charge_check_otg_state,
	.set_state = set_charge_state,
	.get_charge_current = huawei_get_charge_current_max,
};

static int charge_probe(struct platform_device *pdev)
{
	int ret;
	struct charge_device_info *di = NULL;
	struct device_node *np = NULL;

	if (!pdev || !pdev->dev.of_node)
		return -ENODEV;

	di = kzalloc(sizeof(*di), GFP_KERNEL);
	if (!di)
		return -ENOMEM;

	di->core_data = charge_core_get_params();
	if (!di->core_data) {
		hwlog_err("di->core_data is NULL\n");
		ret = -EINVAL;
		goto charge_fail_0;
	}
	di->dev = &pdev->dev;
	np = di->dev->of_node;
	di->ops = g_ops;
	if (!di->ops || !di->ops->chip_init ||
		!di->ops->set_charge_current ||
		!di->ops->set_charge_enable ||
		!di->ops->set_terminal_current ||
		!di->ops->set_terminal_voltage ||
		!di->ops->get_charge_state ||
		!di->ops->reset_watchdog_timer) {
		hwlog_err("charge ops is NULL\n");
		ret = -EINVAL;
		goto charge_fail_1;
	}

	charge_parse_dts(di, np);

	INIT_DELAYED_WORK(&di->pd_voltage_change_work, charge_pd_voltage_change_work);
	INIT_WORK(&di->fault_work, charge_fault_work);

	di->fault_nb.notifier_call = charge_fault_notifier_call;
	ret = power_event_anc_register(POWER_ANT_CHARGE_FAULT, &di->fault_nb);
	if (ret < 0)
		goto charge_fail_1;

	di->sysfs_data.adc_conv_rate = 0;
	di->sysfs_data.iin_thl = di->core_data->iin_max;
	di->sysfs_data.iin_thl_array[IIN_THERMAL_WCURRENT_5V] = di->core_data->iin_max;
	di->sysfs_data.iin_thl_array[IIN_THERMAL_WCURRENT_9V] = di->core_data->iin_max;
	di->sysfs_data.iin_thl_array[IIN_THERMAL_WLCURRENT_5V] = di->core_data->iin_max;
	di->sysfs_data.iin_thl_array[IIN_THERMAL_WLCURRENT_9V] = di->core_data->iin_max;
	di->sysfs_data.ichg_thl = di->core_data->ichg_max;
	di->sysfs_data.iin_rt_curr = di->core_data->iin_max;
	di->sysfs_data.ichg_rt = di->core_data->ichg_max;
	di->sysfs_data.vterm_rt = BATTERY_VOLTAGE_4500_MV;
	if (power_supply_check_psy_available("battery", &di->batt_psy))
		(void)power_supply_get_int_property_value_with_psy(di->batt_psy,
			POWER_SUPPLY_PROP_VOLTAGE_MAX_DESIGN, &di->sysfs_data.vterm_rt);
	di->sysfs_data.charge_enable = TRUE;
	di->sysfs_data.fcp_charge_enable = TRUE;
	di->sysfs_data.batfet_disable = FALSE;
	di->sysfs_data.wdt_disable = FALSE;
	di->sysfs_data.charge_limit = TRUE;
	di->sysfs_data.charge_done_status = CHARGE_DONE_NON;
	di->sysfs_data.charge_done_sleep_status = CHARGE_DONE_SLEEP_DISABLED;
	di->sysfs_data.vr_charger_type = CHARGER_TYPE_NONE;
	di->sysfs_data.dbc_charge_control = CHARGER_NOT_DBC_CONTROL;
	di->sysfs_data.support_ico = 1;
	mutex_init(&di->mutex_hiz);
	di->charge_fault = POWER_NE_CHG_FAULT_NON;
	di->check_full_count = 0;
	di->weaksource_cnt = 0;

	ret = charge_extra_ops_register(&huawei_charge_extra_ops);
	if (ret)
		hwlog_err("register extra charge ops failed\n");

	platform_set_drvdata(pdev, di);
	g_buck_di = di;
	hwlog_info("huawei buck charger probe ok\n");
	return 0;

charge_fail_1:
	di->ops = NULL;
charge_fail_0:
	platform_set_drvdata(pdev, NULL);
	kfree(di);
	di = NULL;
	g_ops = NULL;
	g_buck_di = NULL;
	return ret;
}

static int charge_remove(struct platform_device *pdev)
{
	struct charge_device_info *di = platform_get_drvdata(pdev);

	if (!di)
		return -ENODEV;

#ifdef CONFIG_TCPC_CLASS_BAK
	chip_charger_type_notifier_unregister(&di->usb_nb);
#endif
	power_event_anc_unregister(POWER_ANT_CHARGE_FAULT, &di->fault_nb);
	if (di->ops) {
		di->ops = NULL;
		g_ops = NULL;
	}

	kfree(di);
	di = NULL;
	g_buck_di = NULL;
	return 0;
}

static void charge_shutdown(struct platform_device *pdev)
{
	struct charge_device_info *di = platform_get_drvdata(pdev);

	hwlog_info("%s ++\n", __func__);
	if (!di) {
		hwlog_err("[%s]di is NULL\n", __func__);
		return;
	}

	if (hvdcp_get_charging_stage() == HVDCP_STAGE_SUCCESS)
		(void)charge_set_vbus_vset(ADAPTER_5V);

	power_event_anc_unregister(POWER_ANT_CHARGE_FAULT, &di->fault_nb);

	hwlog_info("%s --\n", __func__);

	return;
}

static struct of_device_id charge_match_table[] = {
	{
		.compatible = "huawei,buck_charger",
		.data = NULL,
	},
	{},
};

static struct platform_driver charge_driver = {
	.probe = charge_probe,
	.remove = charge_remove,
	.shutdown = charge_shutdown,
	.driver = {
		.name = "huawei,buck_charger",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(charge_match_table),
	},
};

static int __init charge_init(void)
{
	return platform_driver_register(&charge_driver);
}

static void __exit charge_exit(void)
{
	platform_driver_unregister(&charge_driver);
}

late_initcall(charge_init);
module_exit(charge_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("huawei charger module driver");
MODULE_AUTHOR("HUAWEI Inc");
