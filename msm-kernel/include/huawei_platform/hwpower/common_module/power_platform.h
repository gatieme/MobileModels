/* SPDX-License-Identifier: GPL-2.0 */
/*
 * power_platform.h
 *
 * differentiated interface related to chip platform
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

#ifndef _POWER_PLATFORM_H_
#define _POWER_PLATFORM_H_

#include <linux/errno.h>
#include <linux/notifier.h>
#include <linux/kernel_stat.h>
#include <linux/time64.h>
#include <chipset_common/hwpower/common_module/power_supply_interface.h>
#include <huawei_platform/power/huawei_charger_common.h>
#include <huawei_platform/power/huawei_charger_adaptor.h>
#include <huawei_platform/power/direct_charger/direct_charger.h>
#include <huawei_platform/hwpower/power_proxy.h>
#include <huawei_platform/hwpower/common_module/power_glink_interface.h>
#include <linux/power/huawei_battery.h>
#include <huawei_platform/power/huawei_charger.h>
#include <huawei_platform/power/batt_info_pub.h>
#include <huawei_platform/usb/hw_pd_dev.h>
#include <huawei_platform/usb/usb_extra_modem.h>

static inline int power_platform_get_filter_soc(int base)
{
	return power_proxy_get_filter_sum(base);
}

static inline void power_platform_sync_filter_soc(int rep_soc,
	int round_soc, int base)
{
	power_proxy_sync_filter_soc(rep_soc, round_soc, base);
}

static inline void power_platform_cancle_capacity_work(void)
{
	power_proxy_cancle_capacity_work();
}

static inline void power_platform_restart_capacity_work(void)
{
	power_proxy_restart_capacity_work();
}

static inline int power_platform_get_adc_sample(int adc_channel)
{
	return -EPERM;
}

static inline int power_platform_get_adc_voltage(int adc_channel)
{
	return -EPERM;
}

static inline int power_platform_get_battery_id_voltage(void)
{
	return 0;
}

static inline int power_platform_get_battery_ui_capacity(void)
{
	int val = 0;

	(void)power_supply_get_int_property_value("battery",
		POWER_SUPPLY_PROP_CAPACITY, &val);
	return val;
}

static inline int power_platform_get_battery_temperature(void)
{
	int val = -400; /* default is -40 centigrade */

	(void)power_supply_get_int_property_value("battery",
		POWER_SUPPLY_PROP_TEMP, &val);
	return val / 10; /* 10: convert temperature unit */
}

static inline int power_platform_get_rt_battery_temperature(void)
{
	return power_platform_get_battery_temperature();
}

static inline int power_platform_get_battery_current(void)
{
	return battery_get_bat_current();
}

static inline int power_platform_is_battery_removed(void)
{
	return 0;
}

static inline int power_platform_is_battery_changed(void)
{
	return check_battery_sn_changed();
}

static inline int power_platform_is_battery_exit(void)
{
	return 1;
}

static inline int power_platform_get_vbus_status(void)
{
	int vbus = 0;

	charge_get_vbus(&vbus);
	/* 1: exist if vbus > 2.8V, otherwise 0: not exist */
	return (vbus >= 2800) ? 1 : 0;
}

static inline int power_platform_enable_ext_pmic_boost(int value)
{
	return 0;
}

#if IS_ENABLED(CONFIG_HUAWEI_POWER_GLINK_INTERFACE)
static inline int power_platform_enable_int_pmic_boost(int value)
{
	return power_glink_interface_haptics_enable_hboost_5v(value); /* value set enable status */
}
#else
static inline int power_platform_enable_int_pmic_boost(int value)
{
	return 0;
}
#endif /* IS_ENABLED(CONFIG_HUAWEI_POWER_GLINK_INTERFACE) && defined(CONFIG_INPUT_QCOM_HV_HAPTICS) */

static inline bool power_platform_usb_state_is_host(void)
{
	return false;
}

static inline bool power_platform_pogopin_is_support(void)
{
	return false;
}

static inline bool power_platform_pogopin_otg_from_buckboost(void)
{
	return false;
}

static inline int power_platform_powerkey_register_notifier(struct notifier_block *nb)
{
	return 0;
}

static inline int power_platform_powerkey_unregister_notifier(struct notifier_block *nb)
{
	return 0;
}

static inline bool power_platform_is_powerkey_up(unsigned long event)
{
	return false;
}

static inline bool power_platform_get_sysfs_wdt_disable_flag(void)
{
	return false;
}

static inline void power_platform_charge_stop_sys_wdt(void)
{
}

static inline void power_platform_charge_feed_sys_wdt(unsigned int timeout)
{
}

static inline int power_platform_set_max_input_current(void)
{
	return -EPERM;
}

static inline void power_platform_start_acr_calc(void)
{
}

static inline int power_platform_get_acr_resistance(int *acr_value)
{
	return -EPERM;
}

static inline bool power_platform_in_dc_charging_stage(void)
{
	return direct_charge_in_charging_stage() == DC_IN_CHARGING_STAGE;
}

static inline void power_platform_set_charge_hiz(int enable)
{
	charge_set_hiz_enable(enable);
}

static inline int power_platform_get_cv_limit(void)
{
	return 0;
}

static inline void power_platform_buck_vbus_change_handler(int vbus)
{
}

static inline void power_platform_charge_enable_sys_wdt(void)
{
}

static inline bool power_platform_check_online_status(void)
{
	return uem_check_online_status();
}

static inline unsigned int power_platform_get_uem_leak_current(void)
{
	return uem_get_charge_leak_current();
}

static inline unsigned int power_platform_get_uem_resistance(void)
{
	return uem_get_charge_resistance();
}

static inline struct otg_ocp_para *power_platform_get_otg_ocp_check_para(void)
{
	return pd_dpm_get_otg_ocp_check_para();
}

static inline void power_platform_get_idle_time(struct timespec64 *idle)
{
	u64 idle_nsec = 0;
	u32 rem = 0;
	int i;

	for_each_possible_cpu(i) {
		struct kernel_cpustat kcs;

		kcpustat_cpu_fetch(&kcs, i);
		idle_nsec += get_idle_time(&kcs, i);
	}
	idle->tv_sec = div_u64_rem(idle_nsec, NSEC_PER_SEC, &rem);
	idle->tv_nsec = rem;
}

static inline int power_platform_notify_direct_charge_status(bool dc)
{
	return 0;
}

static inline int power_platform_get_index_by_volt(int *value)
{
	/* value get bat id */
	return power_glink_interface_get_property_value(POWER_GLINK_PROP_ID_GET_BATTERY_ID, value, 1);
}

static inline int power_platform_support_pmic_detection(void)
{
	return 0;
}

#endif /* _POWER_PLATFORM_H_ */
