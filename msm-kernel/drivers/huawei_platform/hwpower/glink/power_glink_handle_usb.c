// SPDX-License-Identifier: GPL-2.0
/*
 * power_glink_handle_usb.c
 *
 * glink channel for handle usb
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

#include <linux/device.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <chipset_common/hwpower/common_module/power_ui_ne.h>
#include <chipset_common/hwpower/common_module/power_icon.h>
#include <chipset_common/hwpower/common_module/power_dsm.h>
#include <chipset_common/hwusb/hw_usb.h>
#include <huawei_platform/hwpower/common_module/power_glink.h>
#include <huawei_platform/hwpower/common_module/power_glink_interface.h>
#include <huawei_platform/usb/hw_pd_dev.h>

#define HWLOG_TAG power_glink_handle_usb
HWLOG_REGIST();

static void usb_water_detect_dmd()
{
	int ret;
	char dsm_buff[POWER_DSM_BUF_SIZE_0128] = {0};

	hwlog_info("%s: water detect\n", __func__);
	ret = snprintf(dsm_buff, POWER_DSM_BUF_SIZE_0128, "sbu1 water detected\n");
	if (ret < 0) {
		hwlog_info("snprintf error:%d\n", ret);
		return;
	}
	ret = power_dsm_report_dmd(POWER_DSM_USB, POWER_DSM_ERROR_NO_WATER_CHECK_IN_USB, dsm_buff);
	hwlog_info("usb_water_detect_dmd  ret = %d\n", ret);
}

static void power_glink_handle_usb_connect_message(u32 msg)
{
	u32 data;

	switch (msg) {
	case POWER_GLINK_NOTIFY_VAL_USB_DISCONNECT:
		data = 0;
		power_event_bnc_notify(POWER_BNT_HW_PD, POWER_NE_HW_PD_CHARGER, &data);
		break;
	case POWER_GLINK_NOTIFY_VAL_USB_CONNECT:
		break;
	default:
		break;
	}
}

static void power_glink_handle_usb_dc_connect_message(u32 msg)
{
	u32 data;
	int typec_state = PD_DPM_USB_TYPEC_DEVICE_ATTACHED;

	switch (msg) {
	case POWER_GLINK_NOTIFY_VAL_STOP_CHARGING:
		pd_dpm_chg_event_notify(CHG_EVT_VBUS_DISCONN);
		data = 0;
		power_event_bnc_notify(POWER_BNT_HW_PD, POWER_NE_HW_PD_CHARGER, &data);
		data = PD_DPM_CURR_3A;
		power_event_bnc_notify(POWER_BNT_HW_PD, POWER_NE_HW_PD_SET_EMARK_CURRENT, &data);
		data = 1;
		power_event_bnc_notify(POWER_BNT_HW_PD, POWER_NE_HW_PD_IS_DIRECT_CHARGE_CABLE, &data);
		typec_state = PD_DPM_USB_TYPEC_NONE;
		//pd_dpm_set_typec_state(typec_state);
		break;
	case POWER_GLINK_NOTIFY_VAL_START_CHARGING:
		pd_dpm_chg_event_notify(CHG_EVT_VBUS_CONN);
		//pd_dpm_set_typec_state(typec_state);
		break;
	case POWER_GLINK_NOTIFY_VAL_USB_FORCE_DISCONNECT:
		hwlog_info("USB_FORCE_DISCONNECT ready\n");
		pd_dpm_chg_event_notify(CHG_EVT_USB_FORCE_DISCONNECT);
		break;
	default:
		break;
	}
}

static void power_glink_handle_usb_typec_message(u32 msg)
{
	u32 cc_orientation;
	int typec_state = PD_DPM_USB_TYPEC_DEVICE_ATTACHED;
	u32 data;

	switch (msg) {
	case POWER_GLINK_NOTIFY_VAL_ORIENTATION_CC1:
		cc_orientation = 0;
		power_event_bnc_notify(POWER_BNT_HW_PD, POWER_NE_HW_PD_ORIENTATION_CC,
			&cc_orientation);
		break;
	case POWER_GLINK_NOTIFY_VAL_ORIENTATION_CC2:
		cc_orientation = 1;
		power_event_bnc_notify(POWER_BNT_HW_PD, POWER_NE_HW_PD_ORIENTATION_CC,
			&cc_orientation);
		break;
	case POWER_GLINK_NOTIFY_VAL_DEBUG_ACCESSORY:
		data = 0;
		power_event_bnc_notify(POWER_BNT_HW_PD, POWER_NE_HW_PD_IS_DIRECT_CHARGE_CABLE, &data);
		break;
	case POWER_GLINK_NOTIFY_VAL_UFP:
	case POWER_GLINK_NOTIFY_VAL_POWERCABLE_NOUFP:
	case POWER_GLINK_NOTIFY_VAL_POWERCABLE_UFP:
		power_event_bnc_notify(POWER_BNT_OTG, POWER_NE_OTG_OCP_CHECK_START, NULL);
		hwlog_info("otg insert\n");
		break;
	case POWER_GLINK_NOTIFY_VAL_TYPEC_NONE:
		power_event_bnc_notify(POWER_BNT_OTG, POWER_NE_OTG_OCP_CHECK_STOP, NULL);
		hwlog_info("otg remove\n");
		typec_state = PD_DPM_USB_TYPEC_NONE;
		power_event_bnc_notify(POWER_BNT_HW_PD, POWER_NE_HW_PD_TYPEC_NONE, NULL);
		/* fall through */
	case POWER_GLINK_NOTIFY_VAL_TYPEC_DFP:
		data = 1;
		power_event_bnc_notify(POWER_BNT_HW_PD, POWER_NE_HW_PD_IS_DIRECT_CHARGE_CABLE, &data);
		break;
	case POWER_GLINK_NOTIFY_VAL_TYPEC_SHORT:
		power_event_bnc_notify(POWER_BNT_HW_PD, POWER_NE_HW_PD_CC_PROTECT, NULL);
		break;
	case POWER_GLINK_NOTIFY_VAL_SBU1_SHORT:
		hwlog_info("SBU1 water detected");
		usb_water_detect_dmd();
		break;
	default:
		break;
	}
	//pd_dpm_set_typec_state(typec_state);
}

static void power_glink_handle_usb_pd_message(u32 msg)
{
	u32 data;
	u32 vconn_enable;
	u32 vbus_enable;
	u32 uem_event_val;

	switch (msg) {
	case POWER_GLINK_NOTIFY_VAL_PD_CHARGER:
		data = 1;
		power_event_bnc_notify(POWER_BNT_HW_PD, POWER_NE_HW_PD_CHARGER, &data);
		break;
	case POWER_GLINK_NOTIFY_VAL_PD_VCONN_ENABLE:
		vconn_enable = 1;
		power_event_bnc_notify(POWER_BNT_HW_PD, POWER_NE_HW_PD_SOURCE_VCONN, &vconn_enable);
		break;
	case POWER_GLINK_NOTIFY_VAL_PD_VCONN_DISABLE:
		vconn_enable = 0;
		power_event_bnc_notify(POWER_BNT_HW_PD, POWER_NE_HW_PD_SOURCE_VCONN, &vconn_enable);
		break;
	case POWER_GLINK_NOTIFY_VAL_PD_VBUS_ENABLE:
		vbus_enable = 1;
		power_event_bnc_notify(POWER_BNT_HW_PD, POWER_NE_HW_PD_SOURCE_VBUS, &vbus_enable);
		break;
	case POWER_GLINK_NOTIFY_VAL_PD_VBUS_DISABLE:
		vbus_enable = 0;
		uem_event_val = 6; /* 6: UEM_EVENT_NOTIFY_VAL_LOADSWITCH_DISABLE */
		power_event_bnc_notify(POWER_BNT_HW_PD, POWER_NE_HW_PD_SOURCE_VBUS, &vbus_enable);
		power_event_bnc_notify(POWER_BNT_USB_EXT_MODEM, POWER_NE_UEM_RECEIVE_UVDM_DATA, &uem_event_val);
		break;
	case POWER_GLINK_NOTIFY_VAL_PD_QUICK_CHARGE:
		if (power_icon_inquire() == ICON_TYPE_SUPER)
			break;

		data = 1;
		power_event_bnc_notify(POWER_BNT_HW_PD, POWER_NE_HW_PD_QUCIK_CHARGE, &data);
		break;
	default:
		break;
	}
}

void power_glink_handle_usb_notify_message(u32 id, u32 msg)
{
	switch (id) {
	case POWER_GLINK_NOTIFY_ID_USB_CONNECT_EVENT:
		power_glink_handle_usb_connect_message(msg);
		break;
	case POWER_GLINK_NOTIFY_ID_DC_CONNECT_EVENT:
		power_glink_handle_usb_dc_connect_message(msg);
		break;
	case POWER_GLINK_NOTIFY_ID_TYPEC_EVENT:
		power_glink_handle_usb_typec_message(msg);
		break;
	case POWER_GLINK_NOTIFY_ID_PD_EVENT:
		power_glink_handle_usb_pd_message(msg);
		break;
	case POWER_GLINK_NOTIFY_ID_EMARK_EVENT:
		power_event_bnc_notify(POWER_BNT_HW_PD, POWER_NE_HW_PD_SET_EMARK_CURRENT, &msg);
		break;
	case POWER_GLINK_NOTIFY_ID_APSD_EVENT:
		power_event_bnc_notify(POWER_BNT_HW_PD, POWER_NE_HW_PD_BC12_RESULT, &msg);
		break;
	case POWER_GLINK_NOTIFY_ID_UEM_EVENT:
		power_event_bnc_notify(POWER_BNT_USB_EXT_MODEM, POWER_NE_UEM_RECEIVE_UVDM_DATA, &msg);
		break;
	case POWER_GLINK_NOTIFY_ID_USB_DMD_EVENT:
		power_event_bnc_notify(POWER_BNT_HW_PD, POWER_NE_HW_PD_DMD, &msg);
		break;
	default:
		break;
	}
}
