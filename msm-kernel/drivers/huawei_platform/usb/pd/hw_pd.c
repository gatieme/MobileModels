/************************************************************
*
* Copyright (C), 1988-1999, Huawei Tech. Co., Ltd.
* FileName: hw_typec.c
* Author: suoandajie(00318894)       Version : 0.1      Date:  2016-5-9
*
* This software is licensed under the terms of the GNU General Public
* License version 2, as published by the Free Software Foundation, and
* may be copied, distributed, and modified under those terms.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
*  Description:    .c file for type-c core layer which is used to handle
*                  pulic logic management for different chips and to
*                  provide interfaces for exteranl modules.
*  Version:
*  Function List:
*  History:
*  <author>  <time>   <version >   <desc>
***********************************************************/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/jiffies.h>
#include <linux/pm_wakeup.h>
#include <linux/io.h>
#include <linux/gpio.h>
#include <linux/of.h>
#include <linux/of_gpio.h>
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/notifier.h>
#include <linux/mutex.h>
#include <linux/regmap.h>
#include <linux/usb/role.h>
#include <linux/gpio/consumer.h>
#include <linux/regulator/consumer.h>
#include <linux/version.h>
#include <linux/console.h>
#include <securec.h>
#include <huawei_platform/log/hw_log.h>
#include <huawei_platform/usb/hw_pd_dev.h>
#include <ana_hs_kit/ana_hs_extern_ops/ana_hs_extern_ops.h>
#include <linux/power/huawei_charger.h>
#include <chipset_common/hwpower/common_module/power_sysfs.h>
#include <chipset_common/hwpower/hardware_monitor/water_detect.h>
#include <huawei_platform/power/direct_charger/direct_charger.h>
#include <chipset_common/hwpower/common_module/power_icon.h>
#include <chipset_common/hwpower/hardware_channel/vbus_channel.h>
#include <chipset_common/hwusb/hw_usb.h>
#include <chipset_common/hwpower/common_module/power_cmdline.h>
#include <chipset_common/hwpower/common_module/power_interface.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <chipset_common/hwpower/common_module/power_dts.h>
#include <chipset_common/hwpower/hardware_ic/boost_5v.h>
#include <chipset_common/hwpower/hardware_channel/vbus_channel.h>
#include <huawei_platform/hwpower/common_module/power_glink.h>
#include <huawei_platform/hwpower/common_module/power_glink_interface.h>
#include <huawei_platform/usb/usb_extra_modem.h>

#define CC_SHORT_DEBOUNCE 50 /* ms */

struct pd_dpm_info *g_pd_di;
static bool g_pd_cc_moisture_status;
static int g_is_direct_charge_cable = 1;
static int g_vconn_enable;
static int g_vbus_enable;
static unsigned int cc_dynamic_protect;
static bool g_otg_attached;
static struct mutex g_vbus_en_lock;

#define PD_DPM_MAX_OCP_COUNT 1000
#define OCP_DELAY_TIME 5000
#define DISABLE_INTERVAL 50
#define GET_IBUS_INTERVAL 1000
#define MMI_PD_TIMES 3
#define MMI_PD_IBUS_MIN 300
#define VBUS_STATE_CONNECT                 1
#define WAIT_DEIAY_QUEUES                      1000 /* 1000 ms */
#define WAIT_DEIAY_SECONDARY_IDENTIFICATION    12000 /* 12000 ms */

#define PD_MISC_GET_CC_STATUS                  0xEE
#define PD_MISC_DATA_CUT_OFF                   0xFF
#define PD_MISC_GET_PROPERTY_VALUE             0xFFFFFFFF

#ifndef HWLOG_TAG
#define HWLOG_TAG huawei_pd
HWLOG_REGIST();
#endif

static bool g_pd_cc_orientation;
static bool g_pd_glink_status;
static int g_pd_dpm_typec_state = PD_DPM_USB_TYPEC_DETACHED;
struct pd_ucsi_ops *g_ucsi_ops;
void (*eusb_reset)(void);

void pd_dpm_ucsi_ops_register(struct pd_ucsi_ops *ops)
{
	if (!ops)
		return;

	g_ucsi_ops = ops;
}

int pd_dpm_data_role_swap(enum pd_dpm_data_role role)
{
	if (!g_ucsi_ops || !g_ucsi_ops->dr_swap_set)
		return -EINVAL;

	return g_ucsi_ops->dr_swap_set(role);
}

int pd_dpm_set_usb_role(int role)
{
	if (!g_ucsi_ops || !g_ucsi_ops->set_usb_con)
		return -EINVAL;

	return g_ucsi_ops->set_usb_con(role);
}

void pd_dpm_get_typec_state(int *typec_state)
{
	hwlog_info("%s  = %d\n", __func__, g_pd_dpm_typec_state);

       *typec_state = g_pd_dpm_typec_state;
}

void pd_dpm_set_typec_state(int typec_state)
{
       hwlog_info("%s pd_dpm_set_typec_state  = %d\n", __func__, typec_state);
       g_pd_dpm_typec_state = typec_state;

       if ((g_pd_dpm_typec_state == PD_DPM_USB_TYPEC_NONE) ||
	       (g_pd_dpm_typec_state == PD_DPM_USB_TYPEC_DETACHED) ||
	       (g_pd_dpm_typec_state == PD_DPM_USB_TYPEC_AUDIO_DETACHED)) {
	       hwlog_info("%s report detach, stop ovp & start res detect\n", __func__);
	       ana_hs_fsa4480_stop_ovp_detect(1);
	       ana_hs_fsa4480_start_res_detect(1);
       } else {
	       hwlog_info("%s report attach, stop res & start ovp detect\n", __func__);
	       ana_hs_fsa4480_stop_res_detect(0);
	       ana_hs_fsa4480_start_ovp_detect(0);
       }
}

void pd_dpm_set_glink_status(void)
{
	struct pd_dpm_info *di = g_pd_di;

	if (g_pd_glink_status)
		return;

	g_pd_glink_status = true;
	if (!di)
		return;

	schedule_work(&di->pd_work);
	schedule_delayed_work(&di->cc_interrupt_work, msecs_to_jiffies(1));
}

bool pd_dpm_get_ctc_cable_flag(void)
{
	if (g_pd_di)
		return g_pd_di->ctc_cable_flag;

	return false;
}
bool pd_dpm_check_cc_vbus_short(void)
{
	unsigned int cc = 2; /* defatult set to 2 incase can not get correct value */

	hwlog_info("%s: check cc state begin\n", __func__);
	(void)power_glink_interface_get_property_value(POWER_GLINK_PROP_ID_GET_CC_SHORT_STATUS, &cc, 1);
	hwlog_info("%s: check cc state cc is %d\n", __func__, cc);
	return cc <= 1 ? true : false;
}

bool pd_dpm_get_cc_moisture_status(void)
{
	return g_pd_cc_moisture_status;
}

enum cur_cap pd_dpm_get_cvdo_cur_cap(void)
{
	if (!g_pd_di)
		return PD_DPM_CURR_3A;

	hwlog_info("%s, cur_cap = %d\n", __func__, g_pd_di->cable_vdo);
	return g_pd_di->cable_vdo;
}

void pd_dpm_ignore_vbus_only_event(bool flag)
{
}

int pd_dpm_notify_direct_charge_status(bool dc)
{
	hwlog_info("%s, not thridpart pd", __func__);
	return 0;
}

static int usb_rdy;
void set_usb_rdy(void)
{
	usb_rdy = 1;
}

bool is_usb_rdy(void)
{
	if (usb_rdy)
		return true;
	else
		return false;
}

void pd_dpm_set_cc_orientation(int cc_orientation)
{
	g_pd_cc_orientation = cc_orientation;
}

bool pd_dpm_get_cc_orientation(void)
{
	return g_pd_cc_orientation;
}

void pd_dpm_set_pd_charger_status(void *data)
{
	if (!data || !g_pd_di)
		return;

	g_pd_di->ctc_cable_flag = *(u32 *)data;
}

bool pd_dpm_check_pd_charger(void)
{
	if (!g_pd_di)
		return false;

	return g_pd_di->ctc_cable_flag;
}

static ssize_t pd_dpm_cc_orientation_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	return scnprintf(buf, PAGE_SIZE, "%s\n", pd_dpm_get_cc_orientation() ? "2" : "1");
}

static ssize_t pd_dpm_pd_state_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	return scnprintf(buf, PAGE_SIZE, "%s\n", pd_dpm_check_pd_charger() ? "0" : "1");
}

static DEVICE_ATTR(cc_orientation, S_IRUGO, pd_dpm_cc_orientation_show, NULL);
static DEVICE_ATTR(pd_state, S_IRUGO, pd_dpm_pd_state_show, NULL);

static struct attribute *pd_dpm_ctrl_attributes[] = {
	&dev_attr_cc_orientation.attr,
	&dev_attr_pd_state.attr,
	NULL,
};

static const struct attribute_group pd_dpm_attr_group = {
	.attrs = pd_dpm_ctrl_attributes,
};

static void pd_dpm_parse_orientation_cc(void *data)
{
	if (!data)
		return;

	pd_dpm_set_cc_orientation(*(u32 *)data);
}

void pd_dpm_cc_dynamic_protect(void)
{
	struct pd_dpm_info *di = g_pd_di;

	if (!di)
		return;
	schedule_delayed_work(&di->cc_short_work, msecs_to_jiffies(CC_SHORT_DEBOUNCE));
}

static void pd_dpm_sent_otg_src_type(struct pd_dpm_info *di)
{
	u32 otg_src[PD_OTG_SRC_TYPE_LEN];

	otg_src[PD_OTG_SRC_VCONN] = di->src_vconn;
	otg_src[PD_OTG_SRC_VBUS] = di->src_vbus;
	power_glink_interface_set_property_value(POWER_GLINK_PROP_ID_SET_OTG, otg_src,
		PD_OTG_SRC_TYPE_LEN);
}

static void pd_dpm_ctrl_vconn(void *data)
{
	struct pd_dpm_info *di = g_pd_di;

	if (!di || !data)
		return;

	g_vconn_enable = *(u32 *)data;
	schedule_delayed_work(&di->vconn_src_work, msecs_to_jiffies(PD_OTG_VCONN_DELAY));
}

static void pd_dpm_ctrl_vbus(void *data)
{
	struct pd_dpm_info *di = g_pd_di;

	if (!di || !data)
		return;

	mutex_lock(&g_vbus_en_lock);
	g_vbus_enable = *(u32 *)data;
	if (!g_otg_attached && g_vbus_enable) {
		pr_err("otg not attached, stop enable vbus\n");
		mutex_unlock(&g_vbus_en_lock);
		return;
	}

	schedule_delayed_work(&di->vbus_src_work, msecs_to_jiffies(PD_OTG_VBUS_DELAY));
}

static void pd_dpm_vbus_close(struct pd_dpm_info *di)
{
	unsigned int val;
	bool vbus_flag = true;

	switch (di->src_vbus) {
	case PD_OTG_5VBST:
		if (di->vbus_mode == LOW_POWER)
			vbus_flag = false;

		vbus_ch_close(VBUS_CH_USER_PD, VBUS_CH_TYPE_BOOST_GPIO, vbus_flag, false);
		break;
	case PD_OTG_PMIC:
		val = 0;
		power_glink_interface_set_property_value(POWER_GLINK_PROP_ID_SET_VBUS_CTRL, &val, 1);
		break;
	default:
		break;
	}
}

static void pd_dpm_ctrl_vconn_work(struct work_struct *work)
{
	boost_5v_enable(g_vconn_enable, BOOST_CTRL_PD_VCONN);
}

static void pd_dpm_ctrl_vbus_work(struct work_struct *work)
{
	struct pd_dpm_info *di = container_of(work, struct pd_dpm_info,
		vbus_src_work.work);

	if (!di) {
		mutex_unlock(&g_vbus_en_lock);
		return;
	}

	if (g_vbus_enable)
		vbus_ch_open(VBUS_CH_USER_PD, VBUS_CH_TYPE_BOOST_GPIO, false);
	else
		pd_dpm_vbus_close(di);

	mutex_unlock(&g_vbus_en_lock);
}

static void pd_dpm_quick_charge(void *data)
{
	if (!data)
		return;

	power_icon_notify(ICON_TYPE_QUICK);
}

static void pd_dpm_event_work(struct work_struct *work)
{
	struct pd_dpm_info *di = container_of(work, struct pd_dpm_info,
		pd_work);

	if (!di)
		return;

	pd_dpm_sent_otg_src_type(di);
}

static bool pd_dpm_is_cc_protection(void)
{
	if (!cc_dynamic_protect)
		return false;
	hwlog_info("[CHECK]cc_dynamic_protect is %u\n", cc_dynamic_protect);
#ifdef CONFIG_DIRECT_CHARGER
	if (direct_charge_in_charging_stage() != DC_IN_CHARGING_STAGE)
		return false;
#endif /* CONFIG_DIRECT_CHARGER */
	hwlog_info("cc short\n");
	return true;
}

static void pd_dpm_cc_short_action(void)
{
	unsigned int notifier_type = POWER_ANT_LVC_FAULT;
	int mode = direct_charge_get_working_mode();

	/* cc_dynamic_protect-0: disabled 1: only SC; 2: for SC and LVC */
	if (mode == SC_MODE)
		notifier_type = POWER_ANT_SC_FAULT;
	else if (mode == SC4_MODE)
		notifier_type = POWER_ANT_SC4_FAULT;
	else if (mode == LVC_MODE && cc_dynamic_protect == 2)
		notifier_type = POWER_ANT_LVC_FAULT;
	hwlog_info("[CHECK]check notifier_type is %u\n", notifier_type);
	power_event_anc_notify(notifier_type, POWER_NE_DC_FAULT_CC_SHORT, NULL);
	hwlog_info("cc_short_action\n");
}

static void pd_dpm_cc_short_work(struct work_struct *work)
{
 	hwlog_info("cc_short_work\n");
	if (!pd_dpm_is_cc_protection())
		return;

	pd_dpm_cc_short_action();
}

static void pd_dpm_set_cc_interrupt(struct pd_dpm_info *di, int val)
{
	int ret;
	static int last = -EIO;

	if (!di->cc_interrupt_enable) {
		hwlog_info("set cc not support\n");
		return;
	}

	if (val == last) {
		hwlog_info("set cc same op\n");
		return;
	}

	ret = power_glink_interface_set_property_value(POWER_GLINK_PROP_ID_SET_CC_INTERRUPT, &val, 1);
	if (ret == 0)
		last = val;
	else
		last = -EIO;
	hwlog_info("set cc %d ret %d\n", val, ret);
}

static void pd_dpm_set_vbus_only_ignore(struct pd_dpm_info *di, int val)
{
	int ret;

	if (!di->vbus_only_ignore) {
		hwlog_info("set vbus_noly ignore not support\n");
		return;
	}

	ret = power_glink_interface_set_property_value(POWER_GLINK_PROP_ID_SET_VBUS_ONLY_IGNORE, &val, 1);
	hwlog_info("set vbus_noly ignore %d ret %d\n", val, ret);
}

static void pd_dpm_cc_interrupt_work(struct work_struct *work)
{
	struct pd_dpm_info *di = container_of(work, struct pd_dpm_info,
		cc_interrupt_work.work);

	pd_dpm_set_vbus_only_ignore(di, 1);
	if (!di->wireless_status)
		return;
	pd_dpm_set_cc_interrupt(di, 1);
	hwlog_info("%s cc_interrupt_work\n", __func__);
}

void pd_dpm_set_emark_current(int cur)
{
	if (!g_pd_di)
		return;

	g_pd_di->cable_vdo = cur;
	hwlog_info("pd_dpm_get_emark_current cur=%d\n", g_pd_di->cable_vdo);
}

struct otg_ocp_para *pd_dpm_get_otg_ocp_check_para(void)
{
	if (!g_pd_di)
		return NULL;

	if (g_pd_di->otg_ocp_check_enable == 0)
		return NULL;

	return &g_pd_di->otg_ocp_check_para;
}

static void pd_dpm_handle_dmd(void *data)
{
	int no;
	int ret;
	char dsm_buff[POWER_DSM_BUF_SIZE_0128] = {0};

	if (!data)
		return;

	no = *(int *)data;
	hwlog_info("%s: dmdno = %u\n", __func__, no);
	ret = snprintf_s(dsm_buff, POWER_DSM_BUF_SIZE_0128, POWER_DSM_BUF_SIZE_0128 - 1,
		"%s: \n", __func__);
	if (ret < 0) {
		hwlog_info("snprintf_s error:%d\n", ret);
		return;
	}
	ret = power_dsm_report_dmd(POWER_DSM_USB, no, dsm_buff);
	hwlog_info("%s:power_dsm_report_dmd  ret = %d\n", __func__, ret);
}

static int pd_dpm_event_notifier_call(struct notifier_block *nb,
	unsigned long event, void *data)
{
	struct pd_dpm_info *di = container_of(nb, struct pd_dpm_info, usb_nb);

	pr_info("%s,%d, event = %d\n", __func__, __LINE__, event);
	if (!di)
		return NOTIFY_OK;

	switch (event) {
	case POWER_NE_HW_PD_ORIENTATION_CC:
		g_otg_attached = true;
		pd_dpm_parse_orientation_cc(data);
		break;
	case POWER_NE_HW_PD_CHARGER:
		pd_dpm_set_pd_charger_status(data);
		break;
	case POWER_NE_HW_PD_SOURCE_VCONN:
		pd_dpm_ctrl_vconn(data);
		break;
	case POWER_NE_HW_PD_SOURCE_VBUS:
		di->vbus_mode = NORMAL;
		pd_dpm_ctrl_vbus(data);
		break;
	case POWER_NE_HW_PD_LOW_POWER_VBUS:
		di->vbus_mode = LOW_POWER;
		pd_dpm_ctrl_vbus(data);
		break;
	case POWER_NE_HW_PD_QUCIK_CHARGE:
		pd_dpm_quick_charge(data);
		break;
	case POWER_NE_HW_PD_CC_PROTECT:
		pd_dpm_cc_dynamic_protect();
		break;
	case POWER_NE_HW_PD_IS_DIRECT_CHARGE_CABLE:
		pd_dpm_set_is_direct_charge_cable(*((int *)data));
		break;
	case POWER_NE_HW_PD_SET_EMARK_CURRENT:
		pd_dpm_set_emark_current(*((int *)data));
		break;
	case POWER_NE_HW_PD_SET_GLINK_STATUS:
		pd_dpm_set_glink_status();
		break;
	case POWER_NE_HW_PD_BC12_RESULT:
		uem_check_charger_type(*((u32 *)data));
		break;
	case POWER_NE_HW_PD_TYPEC_NONE:
		g_otg_attached = false;
		uem_handle_detach_event();
		break;
	case POWER_NE_HW_PD_DMD:
		pd_dpm_handle_dmd(data);
		break;
	default:
		break;
	}

	return NOTIFY_OK;
}

static int pd_dpm_connect_notifier_call(struct notifier_block *nb,
	unsigned long event, void *data)
{
	struct pd_dpm_info *di = container_of(nb, struct pd_dpm_info, connect_nb);
	unsigned int val;

	if (!di)
		return NOTIFY_OK;
	pr_info("%s, event = %d\n", __func__, event);
	switch (event) {
	case POWER_NE_WIRELESS_CONNECT:
		di->wireless_status = 1;
		hwlog_info("enable cc interrupt reg\n");
		pd_dpm_set_cc_interrupt(di, 1);
		break;
	case POWER_NE_WIRELESS_DISCONNECT:
	case POWER_NE_WIRELESS_TX_STOP:
		di->wireless_status = 0;
		hwlog_info("disable cc interrupt reg\n");
		pd_dpm_set_cc_interrupt(di, 0);
		break;
	default:
		break;
	}

	return NOTIFY_OK;
}

static int pd_dpm_wireless_tx_notifier_call(struct notifier_block *nb,
	unsigned long event, void *data)
{
	struct pd_dpm_info *di = container_of(nb, struct pd_dpm_info, wltx_nb);
	unsigned int val;

	if (!di)
		return NOTIFY_OK;
	pr_info("%s, event = %d\n", __func__, event);
	switch (event) {
	case POWER_NE_WLTX_PING_RX:
		di->wireless_status = 1;
		hwlog_info("enable cc interrupt reg\n");
		pd_dpm_set_cc_interrupt(di, 1);
		break;
	default:
		break;
	}

	return NOTIFY_OK;
}

static void pd_dpm_parse_dts(struct pd_dpm_info *di)
{
	unsigned int flag = 0;
	int ret;

	ret = power_dts_read_u32(power_dts_tag(HWLOG_TAG), di->dev->of_node,
		"usb_monitor_flag", &flag, 0);
	if (ret == 0)
		hw_usb_monitor_set_flag(flag);

	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), di->dev->of_node,
		"src_vconn", &di->src_vconn, PD_OTG_SRC_VCONN_DEFAULT);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), di->dev->of_node,
		"src_vbus", &di->src_vbus, PD_OTG_SRC_VBUS_DEFAULT);

	/* fix a hardware issue, has ocp when open otg */
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), di->dev->of_node,
		"otg_ocp_check_enable", &di->otg_ocp_check_enable, 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), di->dev->of_node,
		"otg_ocp_vol_mv", &di->otg_ocp_check_para.vol_mv,
		OTG_OCP_VOL_MV);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), di->dev->of_node,
		"otg_ocp_check_times", &di->otg_ocp_check_para.check_times,
		OTG_OCP_CHECK_TIMES);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), di->dev->of_node,
		"otg_ocp_check_delayed_time", &di->otg_ocp_check_para.delayed_time,
		OTG_OCP_CHECK_DELAYED_TIME);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), di->dev->of_node,
		"cc_dynamic_protect", &cc_dynamic_protect, 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), di->dev->of_node,
		"quirks_fix_flag", &di->quirks_fix_flg, 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), di->dev->of_node,
		"cc_interrupt_enable", &di->cc_interrupt_enable, 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), di->dev->of_node,
		"vbus_only_ignore", &di->vbus_only_ignore, 0);
}

void pd_dpm_set_is_direct_charge_cable(int ret)
{
	g_is_direct_charge_cable = ret;
}

static int direct_charge_cable_detect(void)
{
#ifdef CONFIG_HUAWEI_POWER_EMBEDDED_ISOLATION
	unsigned int ret;
	hwlog_info("direct_charge_cable_detect %d\n", g_is_direct_charge_cable);
	if (g_is_direct_charge_cable) {
		ret = (unsigned int)pd_dpm_send_misc_cmd(PD_MISC_CMD_GET_STATUS, 0);
		if ((ret & PD_MISC_DATA_CUT_OFF) == PD_MISC_GET_CC_STATUS) {
			hwlog_info("redetect charger cable\n");
			g_is_direct_charge_cable = 0;
		}
	}
#endif
	return g_is_direct_charge_cable;
}

static struct dc_cable_ops cable_detect_ops = {
	.detect = direct_charge_cable_detect,
};

static void pd_dpm_chg_retrigger_dmd(void)
{
	int ret;
	char dsm_buff[POWER_DSM_BUF_SIZE_0128] = {0};

	hwlog_info("%s: BC1.2 secondary identification\n", __func__);
	ret = snprintf_s(dsm_buff, POWER_DSM_BUF_SIZE_0128, POWER_DSM_BUF_SIZE_0128 - 1,
		"%s: BC1.2 secondary identification\n", __func__);
	if (ret < 0) {
		hwlog_info("snprintf_s error:%d\n", ret);
		return;
	}
	ret = power_dsm_report_dmd(POWER_DSM_USB, DSM_USB_RETRIGGER_APSD, dsm_buff);
	hwlog_info("%s:power_dsm_report_dmd  ret = %d\n", __func__, ret);
}

static void pd_dpm_chg_retrigger_work(struct work_struct *work)
{
	int ret;
	bool recon = false;
	unsigned int val = 0;

	if (!g_pd_di)
		return;

	hwlog_info("%s: start work\n", __func__);
	(*eusb_reset)();
	if (g_ucsi_ops && g_ucsi_ops->get_usb_con && g_ucsi_ops->set_usb_con) {
		ret = g_ucsi_ops->get_usb_con();
		if (ret == USB_ROLE_DEVICE) {
			ret = g_ucsi_ops->set_usb_con(USB_ROLE_NONE);
			hwlog_info("set_usb_con USB_ROLE_NONE %d\n", ret);
			recon = (ret == 0);
			msleep(WAIT_DEIAY_QUEUES);
		}
	}
	if (g_pd_di->vbus_conn == 0) {
		hwlog_info("%s: USB_STATE=DISCONNECTED\n", __func__);
		return;
	}

	ret = power_glink_interface_set_property_value (
		POWER_GLINK_PROP_ID_SET_RETRIGGER_APSD, &val, GLINK_DATA_ONE);
	hwlog_info("power_glink_interface_set_property_value return %d\n", ret);
	pd_dpm_chg_retrigger_dmd();
	if (recon) {
		msleep(WAIT_DEIAY_SECONDARY_IDENTIFICATION);
		if (g_pd_di->vbus_conn == 0) {
			hwlog_info("%s: USB_STATE=DISCONNECTED\n", __func__);
			return;
		}
		ret = g_ucsi_ops->set_usb_con(USB_ROLE_DEVICE);
		hwlog_info("set_usb_con USB_ROLE_DEVICE %d\n", ret);
	}
}

void eusb_repeater_register(void (*reset_func)(void))
{
	eusb_reset = reset_func;
	hwlog_info("%s ok\n", __func__);
}
EXPORT_SYMBOL(eusb_repeater_register);

void pd_dpm_chg_event_notify(int event)
{
	int ret;
	static int vcon = false;

	if (!g_pd_di || !g_pd_di->quirks_fix_flg)
		return;

	if (event == CHG_EVT_USB_FORCE_DISCONNECT) {
		if (!g_ucsi_ops->force_usb_disc)
			return;

		ret = g_ucsi_ops->force_usb_disc();
		hwlog_info("%s: g_ucsi_force role is %d\n", __func__, ret);
		return;
	}

	hwlog_info("%s: vcon=%d, evt=%d\n", __func__, vcon, event);
	if (delayed_work_pending(&g_pd_di->chg_retrigger_work)) {
		hwlog_info("%s: cancel work\n", __func__);
		cancel_delayed_work(&g_pd_di->chg_retrigger_work);
	}
	if (event == CHG_EVT_VBUS_CONN) {
		g_pd_di->vbus_conn = VBUS_STATE_CONNECT;
		vcon = true;
		return;
	}

	if (event == CHG_EVT_VBUS_DISCONN)
		g_pd_di->vbus_conn = 0;

	if (vcon && (event == CHG_EVT_SDP)) {
		hwlog_info("%s: start work\n", __func__);
		schedule_delayed_work(&g_pd_di->chg_retrigger_work,
			msecs_to_jiffies(WAIT_DEIAY_SECONDARY_IDENTIFICATION));
	}
	vcon = false;
}
EXPORT_SYMBOL(pd_dpm_chg_event_notify);

int pd_dpm_send_misc_cmd(unsigned int cmd, unsigned int param)
{
	int ret;
	u32 misc_cmd[PD_MISCCMD_DWORD_LEN];

	misc_cmd[0] = (u32)cmd;     /* DWORD 0 for cmd */
	misc_cmd[1] = (u32)param;   /* DWORD 1 for param */

#ifdef CONFIG_HUAWEI_POWER_EMBEDDED_ISOLATION
	if (cmd == PD_MISC_CMD_GET_STATUS) {
		misc_cmd[0] = PD_MISC_GET_PROPERTY_VALUE;
		ret = power_glink_interface_get_property_value(POWER_GLINK_PROP_ID_SET_MISC_CMD,
			misc_cmd, PD_MISCCMD_DWORD_LEN);
		hwlog_info("%s send cmd=%u, param=%u, return %d, val=%x-%x\n",
			__func__, cmd, param, ret, misc_cmd[0], misc_cmd[1]);
		return (int)misc_cmd[0];
	}
#endif
	ret = power_glink_interface_set_property_value(POWER_GLINK_PROP_ID_SET_MISC_CMD,
		misc_cmd, PD_MISCCMD_DWORD_LEN);
	hwlog_info("%s send cmd=%u, param=%u, return %d\n", __func__, cmd, param, ret);

	return ret;
}
EXPORT_SYMBOL(pd_dpm_send_misc_cmd);

static void pd_dpm_otg_restore_work(struct work_struct *work)
{
	struct pd_dpm_info *di = g_pd_di;

	if (!di)
		return;

	pd_dpm_vbus_close(di);
}

static int pd_set_rtb_success(unsigned int val)
{
	struct pd_dpm_info *di = g_pd_di;
	int typec_state = PD_DPM_USB_TYPEC_NONE;

	/* 1:set board running test result success */
	if (!di || (val <= 0))
		return -1;

	if (!power_cmdline_is_factory_mode())
		return 0;

	pd_dpm_get_typec_state(&typec_state);
	if (typec_state == PD_DPM_USB_TYPEC_HOST_ATTACHED ||
		typec_state == PD_DPM_USB_TYPEC_DEVICE_ATTACHED ||
		typec_state == PD_DPM_USB_TYPEC_AUDIO_ATTACHED) {
		hwlog_err("typec port is attached, can not open vbus\n");
		return -1;
	}

	vbus_ch_open(VBUS_CH_USER_PD, VBUS_CH_TYPE_BOOST_GPIO, false);
	cancel_delayed_work_sync(&di->otg_restore_work);
	/* delay val*1000 ms */
	schedule_delayed_work(&di->otg_restore_work,
		msecs_to_jiffies(val * 1000));
	return 0;
}


static struct power_if_ops pd_if_ops = {
	.set_rtb_success = pd_set_rtb_success,
	.type_name = "pd",
};

static int pd_dpm_probe(struct platform_device *pdev)
{
	struct pd_dpm_info *di = NULL;
	int ret;

	di = devm_kzalloc(&pdev->dev, sizeof(*di), GFP_KERNEL);
	if (!di)
		return -ENOMEM;

	di->dev = &pdev->dev;
	g_pd_di = di;
	pd_dpm_parse_dts(di);
	if (g_pd_glink_status)
		pd_dpm_sent_otg_src_type(di);

	g_pd_di->cable_vdo = 0;
	g_pd_di->ctc_cable_flag = false;
	platform_set_drvdata(pdev, di);

	dc_cable_ops_register(&cable_detect_ops);

	mutex_init(&g_vbus_en_lock);
	INIT_WORK(&di->pd_work, pd_dpm_event_work);
	INIT_DELAYED_WORK(&di->vconn_src_work, pd_dpm_ctrl_vconn_work);
	INIT_DELAYED_WORK(&di->vbus_src_work, pd_dpm_ctrl_vbus_work);
	INIT_DELAYED_WORK(&di->cc_short_work, pd_dpm_cc_short_work);
	INIT_DELAYED_WORK(&di->otg_restore_work, pd_dpm_otg_restore_work);
	INIT_DELAYED_WORK(&di->chg_retrigger_work, pd_dpm_chg_retrigger_work);
	INIT_DELAYED_WORK(&di->cc_interrupt_work, pd_dpm_cc_interrupt_work);
	power_if_ops_register(&pd_if_ops);
	di->usb_nb.notifier_call = pd_dpm_event_notifier_call;
	ret = power_event_bnc_register(POWER_BNT_HW_PD, &di->usb_nb);
	if (ret)
		goto notifier_regist_fail;
	di->connect_nb.notifier_call = pd_dpm_connect_notifier_call;
	ret = power_event_bnc_register(POWER_BNT_CONNECT, &di->connect_nb);
	if (ret)
		goto con_notifier_fail;

	di->wltx_nb.notifier_call = pd_dpm_wireless_tx_notifier_call;
	ret = power_event_bnc_register(POWER_BNT_WLTX, &di->wltx_nb);
	if (ret)
		goto wltx_notifier_fail;

	power_sysfs_create_group("hw_typec", "typec", &pd_dpm_attr_group);
	return 0;
wltx_notifier_fail:
	power_event_bnc_unregister(POWER_BNT_CONNECT, &di->connect_nb);
con_notifier_fail:
	power_event_bnc_unregister(POWER_BNT_HW_PD, &di->usb_nb);
notifier_regist_fail:
	mutex_destroy(&g_vbus_en_lock);
	kfree(di);
	g_pd_di = NULL;
	platform_set_drvdata(pdev, NULL);
	return ret;
}

static const struct of_device_id pd_dpm_callback_match_table[] = {
	{
		.compatible = "huawei,huawei_pd",
		.data = NULL,
	},
	{},
};

static struct platform_driver pd_dpm_callback_driver = {
	.probe = pd_dpm_probe,
	.remove = NULL,
	.driver = {
		.name = "huawei,huawei_pd",
		.owner = THIS_MODULE,
		.of_match_table = pd_dpm_callback_match_table,
	}
};

static int __init pd_dpm_init(void)
{
	return platform_driver_register(&pd_dpm_callback_driver);
}

static void __exit pd_dpm_exit(void)
{
	platform_driver_unregister(&pd_dpm_callback_driver);
}

module_init(pd_dpm_init);
module_exit(pd_dpm_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("pd dpm logic driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
