/*
 * power_event_ne.h
 *
 * notifier event for power module
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

#ifndef _POWER_EVENT_NE_H_
#define _POWER_EVENT_NE_H_

#define POWER_EVENT_NOTIFY_SIZE 1024
#define POWER_EVENT_NOTIFY_NUM  2

/* define notifier type for power module */
enum power_event_notifier_type {
	POWER_NT_BEGIN = 0,
	POWER_NT_CONNECT = POWER_NT_BEGIN,
	POWER_NT_CHARGING,
	POWER_NT_SOC_DECIMAL,
	POWER_NT_WD,
	POWER_NT_UVDM,
	POWER_NT_DC,
	POWER_NT_LIGHTSTRAP,
	POWER_NT_OTG,
	POWER_NT_WLC,
	POWER_NT_WLTX_AUX,
	POWER_NT_WLRX,
	POWER_NT_WLTX,
	POWER_NT_CHG,
	POWER_NT_COUL,
	POWER_NT_CHG_TYPE,
	POWER_NT_END,
};

/* define notifier event for power module */
enum power_event_notifier_list {
	POWER_NE_BEGIN = 0,
	/* section: for connect */
	POWER_NE_USB_DISCONNECT = POWER_NE_BEGIN,
	POWER_NE_USB_CONNECT,
	POWER_NE_PD_DISCONNECT,
	POWER_NE_PD_CONNECT,
	POWER_NE_WIRELESS_DISCONNECT,
	POWER_NE_WIRELESS_CONNECT,
	POWER_NE_WIRELESS_TX_START,
	POWER_NE_WIRELESS_TX_STOP,
	/* section: for charging */
	POWER_NE_START_CHARGING,
	POWER_NE_STOP_CHARGING,
	POWER_NE_SUSPEND_CHARGING,
	/* section: for soc decimal */
	POWER_NE_SOC_DECIMAL_DC,
	POWER_NE_SOC_DECIMAL_WL_DC,
	/* section: for water detect */
	POWER_NE_WD_REPORT_DMD,
	POWER_NE_WD_REPORT_UEVENT,
	POWER_NE_WD_DETECT_BY_USB_DP_DN,
	POWER_NE_WD_DETECT_BY_USB_ID,
	POWER_NE_WD_DETECT_BY_USB_GPIO,
	POWER_NE_WD_DETECT_BY_AUDIO_DP_DN,
	/* section: for uvdm */
	POWER_NE_UVDM_RECEIVE,
	/* section: for direct charger */
	POWER_NE_DC_CHECK_START,
	POWER_NE_DC_CHECK_SUCC,
	POWER_NE_DC_LVC_CHARGING,
	POWER_NE_DC_SC_CHARGING,
	POWER_NE_DC_STOP_CHARGE,
	/* section: for lightstrap */
	POWER_NE_LIGHTSTRAP_ON,
	POWER_NE_LIGHTSTRAP_OFF,
	POWER_NE_LIGHTSTRAP_GET_PRODUCT_TYPE,
	POWER_NE_LIGHTSTRAP_EPT,
	/* section: for otg */
	POWER_NE_OTG_SC_CHECK_STOP,
	POWER_NE_OTG_SC_CHECK_START,
	POWER_NE_OTG_OCP_HANDLE,
	/* section: for wireless charger */
	POWER_NE_WLC_CHARGER_VBUS,
	POWER_NE_WLC_ICON_TYPE,
	POWER_NE_WLC_TX_VSET,
	POWER_NE_WLC_READY,
	POWER_NE_WLC_HS_SUCC,
	POWER_NE_WLC_TX_CAP_SUCC,
	POWER_NE_WLC_CERT_SUCC,
	POWER_NE_WLC_DC_START_CHARGING,
	/* section: for wireless tx */
	POWER_NE_WLTX_BEGIN,
	POWER_NE_WLTX_GET_CFG = POWER_NE_WLTX_BEGIN,
	POWER_NE_WLTX_HANDSHAKE_SUCC,
	POWER_NE_WLTX_CHARGEDONE,
	POWER_NE_WLTX_CEP_TIMEOUT,
	POWER_NE_WLTX_EPT_CMD,
	POWER_NE_WLTX_OVP,
	POWER_NE_WLTX_OCP,
	POWER_NE_WLTX_PING_RX,
	POWER_NE_WLTX_HALL_APPROACH,
	POWER_NE_WLTX_HALL_AWAY_FROM,
	POWER_NE_WLTX_ACC_DEV_CONNECTED,
	POWER_NE_WLTX_RCV_DPING,
	POWER_NE_WLTX_ASK_SET_VTX,
	POWER_NE_WLTX_GET_TX_CAP,
	POWER_NE_WLTX_TX_FOD,
	POWER_NE_WLTX_RP_DM_TIMEOUT,
	POWER_NE_WLTX_TX_INIT,
	POWER_NE_WLTX_TX_AP_ON,
	POWER_NE_WLTX_IRQ_SET_VTX,
	POWER_NE_WLTX_GET_RX_PRODUCT_TYPE,
	POWER_NE_WLTX_GET_RX_MAX_POWER,
	POWER_NE_WLTX_ASK_RX_EVT,
	POWER_NE_WLTX_DEV_ATTCH_EVT,
	POWER_NE_WLTX_DEV_KP_BT_EVT,
	POWER_NE_WLTX_DEV_KP_CHAN_SWITCH,
	POWER_NE_WLTX_PING_OCP_OVP,
	/* section: for wireless rx */
	POWER_NE_WLRX_BEGIN,
	POWER_NE_WLRX_PWR_ON = POWER_NE_WLRX_BEGIN,
	POWER_NE_WLRX_READY,
	POWER_NE_WLRX_OCP,
	POWER_NE_WLRX_OVP,
	POWER_NE_WLRX_OTP,
	POWER_NE_WLRX_LDO_OFF,
	POWER_NE_WLRX_TX_ALARM,
	POWER_NE_WLRX_TX_BST_ERR,
	POWER_NE_WLRX_SCP,
	/* section: for charger */
	POWER_NE_CHG_START_CHARGING,
	POWER_NE_CHG_STOP_CHARGING,
	POWER_NE_CHG_CHARGING_DONE,
	POWER_NE_CHG_PRE_STOP_CHARGING,
	POWER_NE_CHG_BC12_CHARGER_TYPE,
	POWER_NE_CHG_REAL_CHARGER_TYPE,
	/* section: for coul */
	POWER_NE_COUL_LOW_VOL,
	POWER_NE_END,
};

struct power_event_notify_data {
	const char *event;
	int event_len;
};

int power_event_nc_cond_register(unsigned int type, struct notifier_block *nb);
int power_event_nc_register(unsigned int type, struct notifier_block *nb);
int power_event_nc_unregister(unsigned int type, struct notifier_block *nb);
void power_event_notify(unsigned int type, unsigned long event, void *data);
void power_event_report_uevent(const struct power_event_notify_data *n_data);

#endif /* _POWER_EVENT_NE_H_ */
