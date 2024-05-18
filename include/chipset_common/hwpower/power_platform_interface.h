/*
 * power_interface.h
 *
 * interface for power module
 *
 * Copyright (c) 2020-2020 Honor Device Co., Ltd.
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

#ifndef _POWER_PLATFORM_INTERFACE_H_
#define _POWER_PLATFORM_INTERFACE_H_

#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/err.h>
#include <linux/workqueue.h>
#include <linux/notifier.h>
#include <linux/platform_device.h>
#include <linux/jiffies.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <hwpower/power_time.h>
#include <power_manager/power/direct_charger/direct_charger.h>

/* power interface operator */
struct power_platform_if_chipset_ops {
	int (*set_enable_charger)(unsigned int value);
};

struct power_platform_if_chipset_mmi_ops {
	void (*set_test_flag)(bool flag);
	bool (*get_test_flag)(void);
	void (*set_succ_flag)(int mode, int value);
};

struct power_platform_if_qcom_ops {
	int (*set_enable_charger)(unsigned int value);
};

struct power_platform_if_dc_cable_ops {
	int (*dc_get_cable_max_current)(void);
	void (*dc_detect_cable)(void);
	int (*dc_calculate_path_resistance)(int *rpath);
	int (*dc_calculate_second_path_resistance)(void);
	int (*dc_resist_handler)(int mode, int value);
	int (*dc_second_resist_handler)(void);
};

struct power_platform_if_dc_adapter_ops {
	int (*dc_get_adapter_voltage)(int *value);
	int (*dc_get_adapter_max_voltage)(int *value);
	int (*dc_get_adapter_current)(int *value);
	int (*dc_get_adapter_current_set)(int *value);
	int (*dc_get_adapter_power_curve)(void);
	int (*dc_get_adapter_max_current)(int value);
	int (*dc_get_protocol_register_state)(void);
	int (*dc_check_adapter_antifake)(void);
};

struct power_platform_if_path_switch_ops {
	int (*dc_open_wired_channel)(void);
	int (*dc_close_wired_channel)(void);
	void (*dc_open_aux_wired_channel)(void);
	void (*dc_close_aux_wired_channel)(void);
	void (*dc_select_charge_path)(void);
	int (*dc_switch_charging_path)(unsigned int path, int hv_flag);
};

struct power_platform_if_dc_uevent_ops {
	void (*dc_send_normal_charging_uevent)(void);
	void (*dc_send_quick_charging_uevent)(void);
	void (*dc_send_icon_uevent)(void);
};

struct power_platform_if_usb_glink_ops {
	int (*usb_glink_get_cable_type)(void);
	int (*dc_hihonor_usb_glink_check_cc_vbus_short)(void);
	bool (*wltx_hihonor_usb_glink_is_otg)(void);
};

struct power_platform_if_wireless_charge_ops {
	bool (*dc_get_disable_wired_dc)(void);
	void (*dc_wltx_dc_adaptor_handler)(void);
};

struct power_platform_if_uscp_ops {
	bool (*dc_get_uscp_is_in_rt_protect_mode)(void);
};

struct power_platform_if_honor_battery_ops {
	bool (*honor_battery_is_battery2s)(void);
};

struct power_platform_dc_charger_ops{
	bool (*hihonor_direct_charge_in_charging_stage)(void);
	unsigned int (*hihonor_direct_charge_get_stage_status)(void);
};

struct power_platform_sc_get_fault_notifier_ops{
	void (*hihonor_sc_get_fault_notifier)(struct atomic_notifier_head **notifier_list);
};

struct power_platform_lvc_get_fault_notifier_ops{
	void (*hihonor_lvc_get_fault_notifier)(struct atomic_notifier_head **notifier_list);
};

struct power_platform_wlc_ilimit_notifier_ops{
	void (*wlc_set_input_limit)(int);
	bool (*wlchonor_wldc_in_charging_stage)(void);
};

/* power interface info */
struct power_platform_if_info {
	struct power_platform_if_chipset_ops *chipst_ops;
	struct power_platform_if_chipset_mmi_ops *chipst_mmi_ops;
	struct power_platform_if_qcom_ops *qcom_ops;
	struct power_platform_if_dc_cable_ops *dc_cable_ops;
	struct power_platform_if_dc_adapter_ops *dc_adapter_ops;
	struct power_platform_if_path_switch_ops *path_switch_ops;
	struct power_platform_if_dc_uevent_ops *dc_uevent_ops;
	struct power_platform_if_usb_glink_ops *usb_glink_ops;
	struct power_platform_if_wireless_charge_ops *disable_wired_ops;
	struct power_platform_if_uscp_ops *usdp_ops;
	struct power_platform_if_honor_battery_ops *honor_battery_ops;
	struct power_platform_dc_charger_ops *dc_charger_ops;
	struct power_platform_sc_get_fault_notifier_ops *sc_get_fault_notifier_ops;
	struct power_platform_lvc_get_fault_notifier_ops *lvc_get_fault_notifier_ops;
	struct power_platform_wlc_ilimit_notifier_ops *wlc_set_input_limit_notifier_ops;
};

int power_platform_if_chipset_ops_register(struct power_platform_if_chipset_ops *ops);
int power_platform_if_chipset_mmi_ops_register(struct power_platform_if_chipset_mmi_ops *ops);
int power_platform_if_qcom_ops_register(struct power_platform_if_qcom_ops *ops);
int power_platform_if_dc_cable_ops_register(struct power_platform_if_dc_cable_ops *ops);
int power_platform_if_dc_adapter_ops_register(struct power_platform_if_dc_adapter_ops *ops);
int power_platform_if_path_switch_ops_register(struct power_platform_if_path_switch_ops *ops);
int power_platform_if_dc_uevent_ops_register(struct power_platform_if_dc_uevent_ops *ops);
int power_platform_if_usb_glink_ops_register(struct power_platform_if_usb_glink_ops *ops);
int power_platform_if_wireless_charge_ops_register(struct power_platform_if_wireless_charge_ops *ops);
int power_platform_if_uscp_ops_register(struct power_platform_if_uscp_ops *ops);
int power_platform_if_honor_battery_ops_register(struct power_platform_if_honor_battery_ops *ops);
int power_platform_dc_charger_ops_register(struct power_platform_dc_charger_ops *ops);
int power_platform_sc_get_fault_notifier_ops_register(struct power_platform_sc_get_fault_notifier_ops *ops);
int power_platform_lvc_get_fault_notifier_ops_register(struct power_platform_lvc_get_fault_notifier_ops *ops);
int power_platform_wlc_ilimit_notifier_ops_register(struct power_platform_wlc_ilimit_notifier_ops *ops);


/* chipset mmi ops for qcom honor charger */
void power_platform_dc_mmi_set_test_flag(bool flag);
bool power_platform_dc_mmi_get_test_flag(void);
void power_platform_dc_mmi_set_succ_flag(int mode, int value);

/* power atomic notifier call chain */
static inline void power_atomic_notifier_call_chain(struct atomic_notifier_head *nh, unsigned long val, void *v)
{
	if (nh)
		atomic_notifier_call_chain(nh, val, v);
}

/* common interface */
int usb_charger_register_notifier(struct notifier_block *nb);
int usb_charger_notifier_unregister(struct notifier_block *nb);

/* direct_charger module */
enum dc_device_id {
	DC_DEVICE_ID_BEGIN,
	LOADSWITCH_RICHTEK = DC_DEVICE_ID_BEGIN,
	LOADSWITCH_TI,
	LOADSWITCH_FAIRCHILD,
	LOADSWITCH_NXP,
	LOADSWITCH_SCHARGERV600,
	LOADSWITCH_FPF2283,
	SWITCHCAP_TI_BQ25970,
	SWITCHCAP_SCHARGERV600,
	SWITCHCAP_LTC7820,
	SWITCHCAP_MULTI_SC,
	SWITCHCAP_RT9759,
	SWITCHCAP_SM_SM5450,
	SWITCHCAP_SC8551,
	SWITCHCAP_HL1530,
	SWITCHCAP_SYH69637,
	SWITCHCAP_SC8545,
	SWITCHCAP_NU2105,
	SWITCHCAP_AW32280,
	SWITCHCAP_SC8551A,
	SWITCHCAP_SC8562,
	SWITCHCAP_SM_HL7139,
	SWITCHCAP_RT9756A,
	SWITCHCAP_SC8546,
	SWITCHCAP_SGM41600A,
	DC_DEVICE_ID_END,
};
const char *dc_get_device_name(int id);

/* direct charge cable */
int dc_get_cable_max_current(void);
void dc_detect_cable(void);
int dc_calculate_path_resistance(int *rpath);
int dc_calculate_second_path_resistance(void);
int dc_resist_handler(int mode, int value);
int dc_second_resist_handler(void);


/*direct charge adapter */
int dc_get_adapter_voltage(int *value);
int dc_get_adapter_max_voltage(int *value);
int dc_get_adapter_current(int *value);
int dc_get_adapter_current_set(int *value);
int dc_get_adapter_power_curve(void);
int dc_get_adapter_max_current(int value);
int dc_get_protocol_register_state(void);
int dc_check_adapter_antifake(void);

/* path switch */
int dc_open_wired_channel(void);
int dc_close_wired_channel(void);
void dc_open_aux_wired_channel(void);
void dc_close_aux_wired_channel(void);
void dc_select_charge_path(void);
int dc_switch_charging_path(unsigned int path, int hv_flag);

/* direct charge uevent */
void dc_send_normal_charging_uevent(void);
void dc_send_quick_charging_uevent(void);
void dc_send_icon_uevent(void);

/* wireless charge */
bool dc_get_disable_wired_dc(void);
void dc_wltx_dc_adaptor_handler(void);
void wlc_set_input_limit(int);
bool wldc_in_charging_stage(void);

/* uscp */
bool dc_get_uscp_is_in_rt_protect_mode(void);

/* usb_glink */
int dc_hihonor_usb_glink_check_cc_vbus_short(void);

bool wltx_hihonor_usb_glink_is_otg(void);

/* honor battery */
bool power_platform_is_battery2s(void);

#if !IS_ENABLED(CONFIG_DIRECT_CHARGER_DECOUP)
/* charging stage*/
bool direct_charge_in_charging_stage(void);
unsigned int power_interface_dc_get_stage_status(void);

/* sc get fault notifier */
void sc_get_fault_notifier(struct atomic_notifier_head **notifier_list);

/* lvc get fault notifier */
void lvc_get_fault_notifier(struct atomic_notifier_head **notifier_list);
#endif /* CONFIG_DIRECT_CHARGER_DECOUP */

struct direct_charge_cd_ops* power_platform_if_get_cd_ops(void);

#endif /* _POWER_PLATFORM_INTERFACE_H_ */
