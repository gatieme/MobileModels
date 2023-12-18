/* SPDX-License-Identifier: GPL-2.0 */
/*
 * power_glink_interface.h
 *
 * glink interface for power module
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

#ifndef _POWER_GLINK_INTERFACE_H_
#define _POWER_GLINK_INTERFACE_H_

/* define property id for power module */
enum power_glink_property_id {
	POWER_GLINK_PROP_ID_BEGIN = 0,
	POWER_GLINK_PROP_ID_TEST = POWER_GLINK_PROP_ID_BEGIN,
	POWER_GLINK_PROP_ID_SET_INPUT_SUSPEND,
	POWER_GLINK_PROP_ID_SET_CHARGE_ENABLE,
	POWER_GLINK_PROP_ID_SET_VBOOST,
	POWER_GLINK_PROP_ID_SET_OTG,
	POWER_GLINK_PROP_ID_SET_WLSBST,
	POWER_GLINK_PROP_ID_SET_USB_ICL,
	POWER_GLINK_PROP_ID_SET_SHIP_MODE_TIMING,
	POWER_GLINK_PROP_ID_SET_SHIP_MODE,
	POWER_GLINK_PROP_ID_SET_FV_FOR_BASP,
	POWER_GLINK_PROP_ID_SET_REGISTER_VALUE, /* 10 */
	POWER_GLINK_PROP_ID_GET_REGISTER_VALUE,
	POWER_GLINK_PROP_ID_SET_VBUS_CTRL,
	POWER_GLINK_PROP_ID_SET_FFC_FV_DELTA,
	POWER_GLINK_PROP_ID_SET_FFC_ITERM,
	POWER_GLINK_PROP_ID_SET_TIME_SYNC,
	POWER_GLINK_PROP_ID_GET_ADSP_INIT_STATUS,
	POWER_GLINK_PROP_ID_SET_INIT_DATA,
	POWER_GLINK_PROP_ID_GET_CC_SHORT_STATUS,
	POWER_GLINK_PROP_ID_GET_PLUGIN_STATUS,
	POWER_GLINK_PROP_ID_SET_PORT_ROLE,  /* 20 */
	POWER_GLINK_PROP_ID_SET_USB_MODE,
	POWER_GLINK_PROP_ID_SET_PD_DISABLE_FLAG,
	POWER_GLINK_PROP_ID_SET_SYS_MIN,
	POWER_GLINK_PROP_ID_SET_IBAT,
	POWER_GLINK_PROP_ID_SET_VTERM,
	POWER_GLINK_PROP_ID_SET_JEITA_TABLE,
	POWER_GLINK_PROP_ID_GET_CHARGE_STATUS,
	POWER_GLINK_PROP_ID_CURR_CALI,
	POWER_GLINK_PROP_ID_LAST_CAP_REG_VALUE,
	POWER_GLINK_PROP_ID_SET_UVDM_FUNC_CMD, /* 30 */
	POWER_GLINK_PROP_ID_SET_USB_PHY_HIZ,
	POWER_GLINK_PROP_ID_GET_VOLTAGE_SYS,
	POWER_GLINK_PROP_ID_SET_IBATT_FULL,
	POWER_GLINK_PROP_ID_SET_RETRIGGER_APSD,
	POWER_GLINK_PROP_ID_SET_CC_INTERRUPT,
	POWER_GLINK_PROP_ID_SET_VBUS_ONLY_IGNORE,
	POWER_GLINK_PROP_ID_SET_MISC_CMD,
	POWER_GLINK_PROP_ID_SET_INPUT_SUSPEND_WLS,
	POWER_GLINK_PROP_ID_SET_CUTOFF_VOLTAGE_FOR_BASP,
	POWER_GLINK_PROP_ID_GET_BATTERY_ID,
	POWER_GLINK_PROP_ID_END,
};

/* define notify id for power module */
enum power_glink_notify_id {
	POWER_GLINK_NOTIFY_ID_BEGIN = 0,
	POWER_GLINK_NOTIFY_ID_USB_CONNECT_EVENT = POWER_GLINK_NOTIFY_ID_BEGIN,
	POWER_GLINK_NOTIFY_ID_DC_CONNECT_EVENT,
	POWER_GLINK_NOTIFY_ID_TYPEC_EVENT,
	POWER_GLINK_NOTIFY_ID_PD_EVENT,
	POWER_GLINK_NOTIFY_ID_APSD_EVENT,
	POWER_GLINK_NOTIFY_ID_WLS2WIRED,
	POWER_GLINK_NOTIFY_ID_WLSIN_VBUS,
	POWER_GLINK_NOTIFY_ID_EMARK_EVENT,
	POWER_GLINK_NOTIFY_ID_QBG_EVENT,
	POWER_GLINK_NOTIFY_ID_UEM_EVENT,
	POWER_GLINK_NOTIFY_ID_USB_DMD_EVENT,
	POWER_GLINK_NOTIFY_ID_END,
};

/* define notify msg for power module */
enum power_glink_notify_value {
	POWER_GLINK_NOTIFY_VAL_USB_DISCONNECT,
	POWER_GLINK_NOTIFY_VAL_USB_CONNECT,
	POWER_GLINK_NOTIFY_VAL_STOP_CHARGING,
	POWER_GLINK_NOTIFY_VAL_START_CHARGING,
	POWER_GLINK_NOTIFY_VAL_USB_FORCE_DISCONNECT,
};

/* define notify id for usb module */
enum power_glink_usbtypec_notify_value {
	POWER_GLINK_NOTIFY_VAL_DEBUG_ACCESSORY,
	POWER_GLINK_NOTIFY_VAL_TYPEC_DFP = 2,
	POWER_GLINK_NOTIFY_VAL_UFP = 6,
	POWER_GLINK_NOTIFY_VAL_POWERCABLE_NOUFP = 7,
	POWER_GLINK_NOTIFY_VAL_POWERCABLE_UFP = 8,
	POWER_GLINK_NOTIFY_VAL_ORIENTATION_CC1 = 9,
	POWER_GLINK_NOTIFY_VAL_ORIENTATION_CC2 = 10,
	POWER_GLINK_NOTIFY_VAL_TYPEC_SHORT = 12,
	POWER_GLINK_NOTIFY_VAL_SBU1_SHORT = 13,
	POWER_GLINK_NOTIFY_VAL_TYPEC_NONE = 14,
};

/* define notify id for pd module */
enum power_glink_usbpd_notify_value {
	POWER_GLINK_NOTIFY_VAL_PD_CHARGER,
	POWER_GLINK_NOTIFY_VAL_PD_VCONN_ENABLE,
	POWER_GLINK_NOTIFY_VAL_PD_VCONN_DISABLE,
	POWER_GLINK_NOTIFY_VAL_PD_VBUS_ENABLE,
	POWER_GLINK_NOTIFY_VAL_PD_VBUS_DISABLE,
	POWER_GLINK_NOTIFY_VAL_PD_QUICK_CHARGE,
};

enum power_glink_charge_type_notify_value {
	POWER_GLINK_NOTIFY_VAL_SDP_CHARGER,
	POWER_GLINK_NOTIFY_VAL_CDP_CHARGER,
	POWER_GLINK_NOTIFY_VAL_DCP_CHARGER,
	POWER_GLINK_NOTIFY_VAL_NONSTANDARD_CHARGER,
	POWER_GLINK_NOTIFY_VAL_INVALID_CHARGER,
};

enum power_glink_qbg_event_notify_value {
	POWER_GLINK_NOTIFY_QBG_TEST,
	POWER_GLINK_NOTIFY_QBG_CHARGE_DONE,
	POWER_GLINK_NOTIFY_QBG_CHARGE_RECHARGE,
};

enum power_glink_msg_data_num {
	GLINK_DATA_ZERO,
	GLINK_DATA_ONE,
	GLINK_DATA_TWO,
	GLINK_DATA_THREE,
	GLINK_DATA_FOUR,
	GLINK_DATA_FIVE,
	GLINK_DATA_SIX,
	GLINK_DATA_SEVEN,
};

enum aggregator_vote_type {
	AGGREGATOR_VOTE_DISABLE,
	AGGREGATOR_VOTE_ENABLE,
	AGGREGATOR_VOTE_OVERRIDE,
	AGGREGATOR_VOTE_INVALID,
};

enum charge_cable_status {
	CHG_CABLE_STATUS_NONE,
	CHG_CABLE_STATUS_USBIN,
	CHG_CABLE_STATUS_WLSIN,
	CHG_CABLE_STATUS_BOTH,
};

enum battery_charge_status {
	CHG_INHIBIT,
	CHG_TRICKLE,
	CHG_PRECHAGE,
	CHG_FULLON,
	CHG_TAPER,
	CHG_TERMINATION,
	CHG_PAUSED,
	CHG_DISABLED,
	CHG_INVALID
};

struct power_glink_interface_ops {
	int (*power_glink_get_property_value)(u32 prop_id, u32 *data_buffer, u32 data_size);
	int (*power_glink_set_property_value)(u32 prop_id, u32 *data_buffer, u32 data_size);
	int (*power_glink_support_fcp_pd_icl)(void);
	bool (*is_dcp_ever_detected)(void);
	void (*power_glink_handle_dc_connect_message)(u32 msg);
	void (*power_glink_handle_charge_type_message)(u32 msg);
	int (*haptics_enable_hboost_5v)(int value);
};

#ifdef CONFIG_HUAWEI_POWER_GLINK_INTERFACE
int power_glink_interface_get_property_value(u32 prop_id, u32 *data_buffer, u32 data_size);
int power_glink_interface_set_property_value(u32 prop_id, u32 *data_buffer, u32 data_size);
int power_glink_interface_support_fcp_pd_icl(void);
bool power_glink_interface_is_dcp_ever_detected(void);
void power_glink_interface_handle_dc_connect_message(u32 msg);
void power_glink_interface_handle_charge_type_message(u32 msg);
int power_glink_interface_haptics_enable_hboost_5v(int value);
int power_glink_interface_ops_register(struct power_glink_interface_ops *ops);
#else
static inline int power_glink_interface_get_property_value(u32 prop_id, u32 *data_buffer, u32 data_size)
{
	return 0;
}

static inline int power_glink_interface_set_property_value(u32 prop_id, u32 *data_buffer, u32 data_size)
{
	return 0;
}

static inline int power_glink_interface_support_fcp_pd_icl(void)
{
	return 0;
}

static inline bool power_glink_interface_is_dcp_ever_detected(void)
{
	return false;
}

static inline void power_glink_interface_handle_dc_connect_message(u32 msg)
{
}

static inline void power_glink_interface_handle_charge_type_message(u32 msg)
{
}

static inline int power_glink_interface_haptics_enable_hboost_5v(int value)
{
	return 0;
}

static inline int power_glink_interface_ops_register(struct power_glink_interface_ops *ops)
{
	return 0;
}
#endif /* CONFIG_HUAWEI_POWER_GLINK_INTERFACE */

#endif /* _POWER_GLINK_INTERFACE_H_ */
