/*
 * usb_extra_modem.c
 *
 * file for usb_extra_modem driver
 *
 * Copyright (c) 2022-2022 Huawei Technologies Co., Ltd.
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

#include <huawei_platform/usb/usb_extra_modem.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/gpio.h>
#include <linux/of.h>
#include <linux/of_gpio.h>
#include <linux/of_device.h>
#include <linux/of_address.h>
#include <linux/usb.h>
#include <linux/usb/role.h>
#include <linux/audio_interface.h>
#include <linux/interrupt.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <chipset_common/hwpower/common_module/power_sysfs.h>
#include <chipset_common/hwpower/common_module/power_wakeup.h>
#include <huawei_platform/hwpower/common_module/power_glink_interface.h>
#include <huawei_platform/log/hw_log.h>
#include <huawei_platform/usb/hw_pd_dev.h>
#include <huawei_platform/usb/hwusb_misc.h>
#include <securec.h>
#include <chipset_common/hwpower/charger/charger_common_interface.h>

#define HWLOG_TAG uem
HWLOG_REGIST();

#define UEM_WORK_DELAY_DEF_MS    100

struct uem_store_info {
	ktime_t usb_power_kt;
	int usb_power_val;

	ktime_t host_ctl_kt;
	int host_ctl_val;
};

static struct uem_store_info g_uem_store_info;
static void uem_usb_power_control(int val);
static void uem_host_controller_enable_control(int val);

struct uem_dev_info *g_uem_di;

struct uem_dev_info *uem_get_dev_info(void)
{
	if (!g_uem_di)
		hwlog_err("dev_info is null\n");

	return g_uem_di;
}

static unsigned int uem_update_store_delay_time(ktime_t *cur, ktime_t *last)
{
	s64 sub;
	unsigned int delay = 0;

	*cur = ktime_get();
	sub = ktime_to_ms(ktime_sub(*cur, *last));
	if (sub < 0) {
		*cur = 0;
		*last = 0;
		hwlog_err("wrong ktime val, reset\n");
		return 0;
	} else if (sub < UEM_WORK_DELAY_DEF_MS) {
		delay = (unsigned int)(UEM_WORK_DELAY_DEF_MS - sub);
	}

	hwlog_info("cur=%lldms, last=%lldms, delay=%u\n",
		ktime_to_ms(*cur), ktime_to_ms(*last), delay);

	return delay;
}

static int uem_loadswitch_gpio_enable(int gpio_num)
{
	struct uem_dev_info *di = uem_get_dev_info();

	if (!di)
		return -ENODEV;

	switch (gpio_num) {
	case LOADSWITCH_GPIO_Q4:
		if (!gpio_is_valid(di->gpio_q4))
			return -EINVAL;

		hwlog_info("loadswitch gpio_q4 open\n");
		gpio_set_value(di->gpio_q4, UEM_LOADSWITCH_GPIO_ENABLE);
		break;
	case LOADSWITCH_GPIO_Q5:
		if (!gpio_is_valid(di->gpio_q5))
			return -EINVAL;

		hwlog_info("loadswitch gpio_q5 open\n");
		gpio_set_value(di->gpio_q5, UEM_LOADSWITCH_GPIO_ENABLE);
		break;
	default:
		break;
	}

	return 0;
}

static int uem_loadswitch_gpio_disable(int gpio_num)
{
	struct uem_dev_info *di = uem_get_dev_info();

	if (!di)
		return -ENODEV;

	switch (gpio_num) {
	case LOADSWITCH_GPIO_Q4:
		if (!gpio_is_valid(di->gpio_q4))
			return -EINVAL;

		hwlog_info("loadswitch gpio_q4 close\n");
		gpio_set_value(di->gpio_q4, UEM_LOADSWITCH_GPIO_DISABLE);
		break;
	case LOADSWITCH_GPIO_Q5:
		if (!gpio_is_valid(di->gpio_q5))
			return -EINVAL;

		hwlog_info("loadswitch gpio_q5 close\n");
		gpio_set_value(di->gpio_q5, UEM_LOADSWITCH_GPIO_DISABLE);
		break;
	default:
		break;
	}

	return 0;
}

static void uem_set_online_status(struct uem_dev_info *di, bool flag)
{
	di->attach_status = flag;
	hwlog_info("online status: %d\n", di->attach_status);
}

bool uem_check_online_status(void)
{
	struct uem_dev_info *di = uem_get_dev_info();

	if (!di)
		return false;

	return di->attach_status;
}

unsigned int uem_get_charge_resistance(void)
{
	struct uem_dev_info *di = uem_get_dev_info();

	if (!di)
		return 0;

	if (!uem_check_online_status())
		return 0;

	hwlog_info("charge_resistance: 0x%x\n", di->charge_resistance);
	return di->charge_resistance;
}

unsigned int uem_get_charge_leak_current(void)
{
	struct uem_dev_info *di = uem_get_dev_info();

	if (!di)
		return 0;

	if (!uem_check_online_status())
		return 0;

	hwlog_info("charge_leak_current: 0x%x\n", di->charge_leak_current);
	return di->charge_leak_current;
}

static void uem_charger_regn_adc_register_ctrl(bool flag)
{
	int ret = 0;

	ret = charger_regn_adc_enable(flag, 1, "uem");
	hwlog_info("charger regn adc register enable: %d, ret: %d\n", flag, ret);
}

static void uem_send_uvdm_command(u32 cmd)
{
	int ret;
	u32 data[UEM_UVDM_DATA_SIZE] = { UEM_UVDM_FUNCTION };

	hwlog_info("send uvdm_command %u\n", cmd);
	data[1] = cmd;
	ret = power_glink_interface_set_property_value(POWER_GLINK_PROP_ID_SET_UVDM_FUNC_CMD, data, sizeof(data));
	if (ret != 0)
		hwlog_err("send uvdm_command failed\n");
}

void uem_check_charger_type(u32 msg)
{
	struct uem_dev_info *di = uem_get_dev_info();
	int ret;

	if (!di)
		return;

	if (!uem_check_online_status() || di->charger_check_flag)
		return;

	di->charger_check_flag = true;
	switch (msg) {
	case POWER_GLINK_NOTIFY_VAL_SDP_CHARGER:
	case POWER_GLINK_NOTIFY_VAL_CDP_CHARGER:
		schedule_delayed_work(&di->dr_swap_work, msecs_to_jiffies(UEM_DR_SWAP_DELAY));
		break;
	default:
		ret = pd_dpm_set_usb_role(USB_ROLE_NONE);
		hwlog_info("usb host off, ret = %d\n", ret);
		break;
	}

	power_wakeup_unlock(di->uem_lock, false);
}

static void uem_ext_otg_insert_uevent(struct uem_dev_info *di)
{
	char *envp[UEM_UEVENT_SIZE] = { "UEM=OTGINSERT", NULL };
	kobject_uevent_env(&di->dev->kobj, KOBJ_CHANGE, envp);
	hwlog_info("send otg insert uevent\n");
}

static void uem_ext_otg_disconnect_uevent(struct uem_dev_info *di)
{
	char *envp[UEM_UEVENT_SIZE] = { "UEM=OTGDISCONNECT", NULL };
	kobject_uevent_env(&di->dev->kobj, KOBJ_CHANGE, envp);
	hwlog_info("send otg disconnect uevent\n");
}

static void uem_ext_vbus_insert_uevent(struct uem_dev_info *di)
{
	char *envp[UEM_UEVENT_SIZE] = { "UEM=EXTVBUSINSERT", NULL };
	kobject_uevent_env(&di->dev->kobj, KOBJ_CHANGE, envp);
	hwlog_info("send ext vbus insert uevent\n");
}

static void uem_detach_uevent(struct uem_dev_info *di)
{
	char *envp[UEM_UEVENT_SIZE] = { "UEM=DETACH", NULL };
	kobject_uevent_env(&di->dev->kobj, KOBJ_CHANGE, envp);
	hwlog_info("send detach uevent\n");
}

static void uem_reset_uevent(struct uem_dev_info *di)
{
	char *envp[UEM_UEVENT_SIZE] = { "UEM=RESET", NULL };
	kobject_uevent_env(&di->dev->kobj, KOBJ_CHANGE, envp);
	hwlog_info("send reset uevent\n");
}

static void uem_attach_uevent(struct uem_dev_info *di)
{
	char *envp[UEM_UEVENT_SIZE] = { "UEM=ATTACH", NULL, NULL };
	envp[UEM_UEVENT_ENVP_OFFSET1] = kzalloc(UEM_UEVENT_INFO_LEN, GFP_KERNEL);

	if (!envp[UEM_UEVENT_ENVP_OFFSET1]) {
		hwlog_err("Failed to apply for memory\n");
		return;
	}

	snprintf(envp[UEM_UEVENT_ENVP_OFFSET1], UEM_UEVENT_INFO_LEN, "MODULEID=%s",
		di->module_id);
	kobject_uevent_env(&di->dev->kobj, KOBJ_CHANGE, envp);
	hwlog_info("send attach uevent,module id = %s\n", di->module_id);
	kfree(envp[UEM_UEVENT_ENVP_OFFSET1]);
}

static void uem_otg_insert_work(struct work_struct *work)
{
	hwlog_info("send uvdm command: open q3\n");
	uem_send_uvdm_command(UEM_HWUVDM_CMD_CMOS_Q3_OPEN);
}

static void uem_vbus_insert_work(struct work_struct *work)
{
	hwlog_info("send uvdm command: charge ready\n");
	uem_send_uvdm_command(UEM_HWUVDM_CMD_CHARGE_READY);
}

static void uem_charge_info_work(struct work_struct *work)
{
	hwlog_info("request charge info\n");
	uem_send_uvdm_command(UEM_HWUVDM_CMD_REQUEST_CHARGE_INFO);
}

static void uem_attach_work(struct work_struct *work)
{
	struct uem_dev_info *di = container_of(work, struct uem_dev_info,
		attach_work.work);

	if (!di)
		return;

	uem_send_uvdm_command(UEM_HWUVDM_CMD_CMOS_Q2_CLOSE);
	uem_attach_uevent(di);
}

static void uem_dr_swap_work(struct work_struct *work)
{
	int ret;

	ret = pd_dpm_data_role_swap(DATA_DEVICE);
	hwlog_info("data role swap, ret = %d\n", ret);
}

static void uem_check_otg_status(struct uem_dev_info *di)
{
	mutex_lock(&di->otg_status_lock);
	hwlog_info("%s = %d\n", __func__, di->otg_status);
	if (di->otg_status)
		uem_send_uvdm_command(UEM_HWUVDM_CMD_CMOS_Q3_OPEN);
	else
		power_wakeup_unlock(di->uem_lock, false);

	mutex_unlock(&di->otg_status_lock);
}

static void uem_ncm_enumeration_work(struct work_struct *work)
{
	struct uem_dev_info *di = container_of(work, struct uem_dev_info,
		ncm_enumeration_work.work);

	if (!di)
		return;

	hwlog_info("enumeration time out\n");
	di->enumeration_flag = true;
	uem_check_otg_status(di);
}

static void uem_usb_power_work(struct work_struct *work)
{
	struct uem_dev_info *di = container_of(work, struct uem_dev_info,
		usb_power_work.work);

	if (!di)
		return;

	hwlog_info("Set usb power as %d\n", g_uem_store_info.usb_power_val);
	uem_usb_power_control(g_uem_store_info.usb_power_val);
}

static void uem_host_ctl_work(struct work_struct *work)
{
	struct uem_dev_info *di = container_of(work, struct uem_dev_info,
		host_ctl_work.work);

	if (!di)
		return;

	hwlog_info("Set host controller as %d\n", g_uem_store_info.host_ctl_val);
	uem_host_controller_enable_control(g_uem_store_info.host_ctl_val);
}

static void uem_modem_enable_control(int val)
{
	struct uem_dev_info *di = uem_get_dev_info();

	if (!di)
		return;

	if (!uem_check_online_status()) {
		hwlog_info("not online, stop to set modem\n");
		return;
	}

	if (val) {
		hwlog_info("modem boot up\n");
		di->modem_active_status = true;
		uem_send_uvdm_command(UEM_HWUVDM_CMD_PMU_ENABLE);
	} else {
		hwlog_info("modem shutdown\n");
		di->modem_active_status = false;
		uem_send_uvdm_command(UEM_HWUVDM_CMD_PMU_DISABLE);
	}
}

void uem_switch_vbus_output(int state)
{
	u32 data = 0;

	hwlog_info("switch otg vbus: %d\n", state);
	switch (state) {
	case UEM_VBUS_DISABLE:
		uem_loadswitch_gpio_disable(LOADSWITCH_GPIO_Q4);
		uem_loadswitch_gpio_disable(LOADSWITCH_GPIO_Q5);
		break;
	case UEM_VBUS_ENABLE:
		uem_loadswitch_gpio_enable(LOADSWITCH_GPIO_Q5);
		power_event_bnc_notify(POWER_BNT_HW_PD, POWER_NE_HW_PD_LOW_POWER_VBUS, &data);
		msleep(UEM_OTG_VBUS_DELAY);
		uem_loadswitch_gpio_enable(LOADSWITCH_GPIO_Q4);
		msleep(UEM_OTG_VBUS_DELAY);
		uem_loadswitch_gpio_disable(LOADSWITCH_GPIO_Q5);
		break;
	default:
		break;
	}
}

static void uem_handle_attach_event(struct uem_dev_info *di)
{
	power_wakeup_lock(di->uem_lock, false);
	schedule_delayed_work(&di->ncm_enumeration_work, msecs_to_jiffies(UEM_NCM_ENUMERATION_TIME_OUT));

	hwlog_info("disable usb headphone low power mode\n");
	usb_low_power_enable(0);

	hwlog_info("attach !\n");
	uem_set_online_status(di, true);
	di->modem_active_status = true;
	uem_charger_regn_adc_register_ctrl(false);
	uem_switch_vbus_output(UEM_VBUS_ENABLE);
	pd_dpm_set_is_direct_charge_cable(1);

	if (di->uem_fcp_flag)
		charge_set_fcp_disable_flag(true, FCP_DISABLE_UEM_VOTER);

	schedule_delayed_work(&di->attach_work, msecs_to_jiffies(UEM_ATTACH_WORK_DELAY));
	schedule_delayed_work(&di->charge_info_work, msecs_to_jiffies(UEM_CHARGE_INFO_DELAY));
}

void uem_handle_detach_event(void)
{
	struct uem_dev_info *di = uem_get_dev_info();

	if (!di)
		return;

	if (!uem_check_online_status()) {
		hwlog_info("not online, stop detach event\n");
		return;
	}

	hwlog_info("detach !\n");
	cancel_delayed_work(&di->ncm_enumeration_work);
	uem_set_online_status(di, false);
	uem_charger_regn_adc_register_ctrl(true);
	di->modem_active_status = false;
	di->otg_status = 0;
	di->vbus_status = 0;
	di->wlrx_status = false;
	di->charger_check_flag = false;
	di->enumeration_flag = false;
	uem_detach_uevent(di);
	uem_switch_vbus_output(UEM_VBUS_DISABLE);
	power_wakeup_unlock(di->uem_lock, false);
	hwlog_info("restore usb headphone low power mode\n");
	usb_low_power_enable(1);

	if (di->uem_fcp_flag)
		charge_set_fcp_disable_flag(false, FCP_DISABLE_UEM_VOTER);
}

static void uem_check_usb_speed(struct uem_dev_info *di)
{
	if (!uem_check_online_status())
		return;

	hwlog_info("%s = %d\n", __func__, di->usb_speed);
	switch (di->usb_speed) {
	case USB_SPEED_SUPER:
	case USB_SPEED_SUPER_PLUS:
		di->enumeration_flag = true;
		cancel_delayed_work(&di->ncm_enumeration_work);
		uem_check_otg_status(di);
		break;
	default:
		break;
	}
}

static void uem_send_reset_uevent(struct uem_dev_info *di)
{
	if (!uem_check_online_status())
		return;

	uem_reset_uevent(di);
}

static void uem_handle_event_data(struct uem_dev_info *di, u32 msg)
{
	hwlog_info("handle event msg %u\n", msg);
	switch (msg) {
	case UEM_EVENT_NOTIFY_VAL_ATTACH:
		uem_handle_attach_event(di);
		break;
	case UEM_EVENT_NOTIFY_VAL_DC_CABLE:
		pd_dpm_set_is_direct_charge_cable(0);
		/* go through */
	case UEM_EVENT_NOTIFY_VAL_VBUS_INSERT:
		power_wakeup_lock(di->uem_lock, false);
		di->vbus_status = true;
		uem_charger_regn_adc_register_ctrl(true);
		uem_ext_vbus_insert_uevent(di);
		schedule_delayed_work(&di->vbus_insert_work, msecs_to_jiffies(UEM_VBUS_INSERT_DELAY));
		break;
	case UEM_EVENT_NOTIFY_VAL_OTG_INSERT:
		power_wakeup_lock(di->uem_lock, false);
		mutex_lock(&di->otg_status_lock);
		di->otg_status = true;
		mutex_unlock(&di->otg_status_lock);
		uem_ext_otg_insert_uevent(di);
		if (!di->enumeration_flag)
			return;

		schedule_delayed_work(&di->otg_insert_work, msecs_to_jiffies(UEM_OTG_INSERT_DELAY));
		break;
	case UEM_EVENT_NOTIFY_VAL_OTG_DISCONNECT:
		power_wakeup_unlock(di->uem_lock, false);
		mutex_lock(&di->otg_status_lock);
		di->otg_status = false;
		mutex_unlock(&di->otg_status_lock);
		uem_ext_otg_disconnect_uevent(di);
		break;
	case UEM_EVENT_NOTIFY_VAL_LOADSWITCH_DISABLE:
		uem_switch_vbus_output(UEM_VBUS_DISABLE);
		break;
	case UEM_EVENT_NOTIFY_VAL_AUDIO_INSERT:
		power_event_bnc_notify(POWER_BNT_HW_USB, POWER_NE_HW_USB_HEADPHONE, NULL);
		break;
	case UEM_EVENT_NOTIFY_VAL_AUDIO_DISCONNECT:
		power_event_bnc_notify(POWER_BNT_HW_USB, POWER_NE_HW_USB_HEADPHONE_OUT, NULL);
		break;
	case UEM_EVENT_NOTIFY_VAL_RESET_MESSAGE:
		uem_send_reset_uevent(di);
		break;
	default:
		break;
	}
}

static int uem_loadswitch_gpio_init(struct uem_dev_info *di,
	int *gpio, const char *label)
{
	int ret;

	*gpio = of_get_named_gpio(di->dev->of_node, label, 0);
	if (!gpio_is_valid(*gpio)) {
		hwlog_err("%s is not valid\n", label);
		return *gpio;
	}

	ret = gpio_request(*gpio, label);
	if (ret) {
		hwlog_err("%s request fail\n", label);
		return ret;
	}

	ret = gpio_direction_output(*gpio, UEM_LOADSWITCH_GPIO_DISABLE);
	if (ret) {
		hwlog_err("%s set output fail\n", label);
		return ret;
	}

	hwlog_info("%s init succ\n", label);
	return 0;
}

static void uem_usb_power_control(int val)
{
	struct uem_dev_info *di = uem_get_dev_info();

	if (!di)
		return;

	if (!uem_check_online_status() || di->vbus_status)
		return;

	if (val) {
		hwlog_info("send uvdm command: usb power on\n");
		uem_send_uvdm_command(UEM_HWUVDM_CMD_USB_POWERON);
	} else {
		hwlog_info("send uvdm command: usb power off\n");
		uem_send_uvdm_command(UEM_HWUVDM_CMD_USB_POWEROFF);
		di->enumeration_flag = false;
	}
}

static void uem_modem_wakeup_control(int val)
{
	struct uem_dev_info *di = uem_get_dev_info();

	if (!di)
		return;

	if (!uem_check_online_status() || di->vbus_status)
		return;

	if (val) {
		hwlog_info("send uvdm command: modem wakeup\n");
		uem_send_uvdm_command(UEM_HWUVDM_CMD_MODEM_WAKEUP);
	}
}

static void uem_host_controller_enable_control(int val)
{
	int ret;
	struct uem_dev_info *di = uem_get_dev_info();

	if (!di)
		return;

	if (!uem_check_online_status() || di->vbus_status)
		return;

	if (!val)
		di->enumeration_flag = false;

	ret = pd_dpm_set_usb_role(val ? USB_ROLE_HOST : USB_ROLE_NONE);
	hwlog_info("host controller enable val: %d, ret: %d\n", val, ret);
}

static void uem_otg_vbus_switch_control(int val)
{
	u32 data = 1;

	if (!uem_check_online_status())
		return;

	if (val) {
		hwlog_info("vbus switch to Q6\n");
		uem_loadswitch_gpio_enable(LOADSWITCH_GPIO_Q5);
		msleep(UEM_OTG_VBUS_DELAY);
		uem_loadswitch_gpio_disable(LOADSWITCH_GPIO_Q4);
		power_event_bnc_notify(POWER_BNT_HW_PD, POWER_NE_HW_PD_SOURCE_VBUS, &data);
		msleep(UEM_VBUS_SWITCH2Q6_DELAY);
		uem_loadswitch_gpio_disable(LOADSWITCH_GPIO_Q5);
	} else {
		hwlog_info("vbus switch to Q4\n");
		uem_switch_vbus_output(UEM_VBUS_ENABLE);
	}
}

static ssize_t uem_gpio_enable_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	long val = 0;

	if (kstrtol(buf, UEM_BASE_DEC, &val) < 0) {
		hwlog_err("gpio enable val invalid\n");
		return -EINVAL;
	}

	uem_loadswitch_gpio_enable((int)val);
	return count;
}
static DEVICE_ATTR(uem_gpio_enable, 0664, NULL, uem_gpio_enable_store);

static ssize_t uem_gpio_disable_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	long val = 0;

	if (kstrtol(buf, UEM_BASE_DEC, &val) < 0) {
		hwlog_err("gpio disable val invalid\n");
		return -EINVAL;
	}

	uem_loadswitch_gpio_disable((int)val);
	return count;
}
static DEVICE_ATTR(uem_gpio_disable, 0664, NULL, uem_gpio_disable_store);

static ssize_t uem_modem_active_status_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct uem_dev_info *di = uem_get_dev_info();

	if (!di)
		return -EINVAL;

	return snprintf(buf, PAGE_SIZE, "%u\n", di->modem_active_status);
}
static DEVICE_ATTR(modem_active_status, 0664, uem_modem_active_status_show, NULL);

static ssize_t uem_modem_enable_control_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	long val = 0;

	if (kstrtol(buf, UEM_BASE_DEC, &val) < 0) {
		hwlog_err("modem_enable control val invalid\n");
		return -EINVAL;
	}

	uem_modem_enable_control((int)val);
	return count;
}
static DEVICE_ATTR(modem_enable, 0664, NULL, uem_modem_enable_control_store);

static ssize_t uem_attach_status_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct uem_dev_info *di = uem_get_dev_info();

	if (!di)
		return -EINVAL;

	return snprintf(buf, PAGE_SIZE, "%u\n", di->attach_status);
}
static DEVICE_ATTR(attach_status, 0664, uem_attach_status_show, NULL);

static ssize_t uem_otg_status_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct uem_dev_info *di = uem_get_dev_info();

	if (!di)
		return -EINVAL;

	return snprintf(buf, PAGE_SIZE, "%u\n", di->otg_status);
}
static DEVICE_ATTR(otg_status, 0664, uem_otg_status_show, NULL);

static ssize_t uem_vbus_status_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct uem_dev_info *di = uem_get_dev_info();

	if (!di)
		return -EINVAL;

	return snprintf(buf, PAGE_SIZE, "%u\n", di->vbus_status);
}
static DEVICE_ATTR(vbus_status, 0664, uem_vbus_status_show, NULL);

static ssize_t uem_modem_wakeup_control_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	long val = 0;

	if (kstrtol(buf, UEM_BASE_DEC, &val) < 0) {
		hwlog_err("modem_wakeup control val invalid\n");
		return -EINVAL;
	}

	uem_modem_wakeup_control((int)val);
	return count;
}
static DEVICE_ATTR(modem_wakeup, 0664, NULL, uem_modem_wakeup_control_store);

static ssize_t uem_usb_power_control_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	long val = 0;
	unsigned int delay;
	struct uem_dev_info *di = uem_get_dev_info();

	if (!di)
		return count;

	if (kstrtol(buf, UEM_BASE_DEC, &val) < 0) {
		hwlog_err("usb_power control val invalid\n");
		return -EINVAL;
	}

	hwlog_info("store usb power val as %ld\n", val);
	g_uem_store_info.usb_power_val = (int)val;
	delay = uem_update_store_delay_time(
		&g_uem_store_info.usb_power_kt, &g_uem_store_info.host_ctl_kt);
	schedule_delayed_work(&di->usb_power_work, msecs_to_jiffies(delay));

	return count;
}
static DEVICE_ATTR(usb_power, 0664, NULL, uem_usb_power_control_store);

static ssize_t uem_host_controller_control_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	long val = 0;
	unsigned int delay;
	struct uem_dev_info *di = uem_get_dev_info();

	if (!di)
		return count;

	if (kstrtol(buf, UEM_BASE_DEC, &val) < 0) {
		hwlog_err("host_controller_enable control val invalid\n");
		return -EINVAL;
	}

	hwlog_info("store host controller val as %ld\n", val);
	g_uem_store_info.host_ctl_val = (int)val;
	delay = uem_update_store_delay_time(
		&g_uem_store_info.host_ctl_kt, &g_uem_store_info.usb_power_kt);
	schedule_delayed_work(&di->host_ctl_work, msecs_to_jiffies(delay));

	return count;
}
static DEVICE_ATTR(host_controller_enable, 0664, NULL, uem_host_controller_control_store);

static ssize_t uem_dwc3_irq_affinity_bind(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	unsigned int irq = 0;
	unsigned long cpus = 0xF0; /* f0:bind to 4,5,6,7 cpu */

	if (kstrtou32(buf, UEM_BASE_DEC, &irq) < 0) {
		hwlog_err("dwc3_irq_affinity control irq invalid\n");
		return -EINVAL;
	}

	irq_set_affinity_hint(irq, to_cpumask(&cpus));
	return count;
}
static DEVICE_ATTR(dwc3_irq_affinity_bind, 0664, NULL, uem_dwc3_irq_affinity_bind);

static ssize_t uem_dwc3_irq_affinity_unbind(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	unsigned int irq = 0;
	unsigned long cpus = 0xFF; /* ff:bind to all cpu */

	if (kstrtou32(buf, UEM_BASE_DEC, &irq) < 0) {
		hwlog_err("dwc3_irq_affinity control irq invalid\n");
		return -EINVAL;
	}

	irq_set_affinity_hint(irq, to_cpumask(&cpus));
	return count;
}
static DEVICE_ATTR(dwc3_irq_affinity_unbind, 0664, NULL, uem_dwc3_irq_affinity_unbind);

static ssize_t uem_otg_vbus_switch_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	long val = 0;

	if (kstrtol(buf, UEM_BASE_DEC, &val) < 0) {
		hwlog_err("otg_vbus_switch val invalid\n");
		return -EINVAL;
	}

	uem_otg_vbus_switch_control((int)val);
	return count;
}
static DEVICE_ATTR(otg_vbus_switch, 0664, NULL, uem_otg_vbus_switch_store);

static struct attribute *uem_sysfs_attributes[] = {
	&dev_attr_uem_gpio_enable.attr,
	&dev_attr_uem_gpio_disable.attr,
	&dev_attr_modem_active_status.attr,
	&dev_attr_modem_enable.attr,
	&dev_attr_attach_status.attr,
	&dev_attr_otg_status.attr,
	&dev_attr_vbus_status.attr,
	&dev_attr_modem_wakeup.attr,
	&dev_attr_usb_power.attr,
	&dev_attr_host_controller_enable.attr,
	&dev_attr_dwc3_irq_affinity_bind.attr,
	&dev_attr_dwc3_irq_affinity_unbind.attr,
	&dev_attr_otg_vbus_switch.attr,
	NULL,
};

static const struct attribute_group uem_attr_group = {
	.attrs = uem_sysfs_attributes,
};

static void uem_event_work(struct work_struct *work)
{
	struct uem_dev_info *di = container_of(work, struct uem_dev_info,
		event_work);

	if (!di)
		return;

	hwlog_info("work event_type = %d\n", di->event_type);
	switch (di->event_type) {
	case POWER_NE_UEM_RECEIVE_UVDM_DATA:
		uem_handle_event_data(di, di->event_data);
		break;
	case POWER_NE_HW_USB_SPEED:
		uem_check_usb_speed(di);
		break;
	case POWER_NE_WIRELESS_CONNECT:
		if (!uem_check_online_status())
			return;

		di->wlrx_status = true;
		uem_charger_regn_adc_register_ctrl(true);
		break;
	case POWER_NE_WIRELESS_DISCONNECT:
		if (!uem_check_online_status())
			return;

		di->wlrx_status = false;
		uem_charger_regn_adc_register_ctrl(false);
		break;
	default:
		break;
	}
}

static int uem_notifier_call(struct notifier_block *nb,
	unsigned long event, void *data)
{
	struct uem_dev_info *di = uem_get_dev_info();

	if (!di)
		return NOTIFY_OK;

	mutex_lock(&di->notifier_lock);
	switch (event) {
	case POWER_NE_UEM_RECEIVE_UVDM_DATA:
		if (!data)
			goto notify_ok;

		di->event_data = *(u32 *)data;
		break;
	case POWER_NE_HW_USB_SPEED:
		if (!data)
			goto notify_ok;

		di->usb_speed = *(unsigned int *)data;
		break;
	case POWER_NE_WIRELESS_CONNECT:
		break;
	case POWER_NE_WIRELESS_DISCONNECT:
		break;
	default:
		goto notify_ok;
	}

	di->event_type = event;
	schedule_work(&di->event_work);

notify_ok:
	mutex_unlock(&di->notifier_lock);
	return NOTIFY_OK;
}

static void uem_parse_dts(struct device_node* np, struct uem_dev_info *di)
{
	int ret;

	ret = of_property_read_u32(np, "charge_resistance", &di->charge_resistance);
	if (ret)
		di->charge_resistance = 0;

	ret = of_property_read_u32(np, "charge_leak_current", &di->charge_leak_current);
	if (ret)
		di->charge_leak_current = 0;

	ret = of_property_read_string(np, "module_id", &di->module_id);
	if (ret)
		di->module_id = "none";

	ret = of_property_read_u32(np, "uem_fcp_flag", &di->uem_fcp_flag);
	if (ret)
		di->uem_fcp_flag = 0;
}

static int uem_probe(struct platform_device *pdev)
{
	struct uem_dev_info *di = NULL;
	int ret;

	di = kzalloc(sizeof(*di), GFP_KERNEL);
	if (!di)
		return -ENOMEM;

	g_uem_di = di;
	di->dev = &pdev->dev;
	platform_set_drvdata(pdev, di);
	ret = uem_loadswitch_gpio_init(di, &di->gpio_q4, "gpio_q4");
	hwlog_info("gpio q4 init ret = %d\n", ret);
	if (ret == -EPROBE_DEFER)
		goto gpio_q4_init_fail;

	ret = uem_loadswitch_gpio_init(di, &di->gpio_q5, "gpio_q5");
	hwlog_info("gpio q5 init ret = %d\n", ret);
	if (ret == -EPROBE_DEFER)
		goto gpio_q5_init_fail;

	uem_parse_dts(di->dev->of_node, di);
	mutex_init(&di->notifier_lock);
	mutex_init(&di->otg_status_lock);
	INIT_WORK(&di->event_work, uem_event_work);
	INIT_DELAYED_WORK(&di->charge_info_work, uem_charge_info_work);
	INIT_DELAYED_WORK(&di->vbus_insert_work, uem_vbus_insert_work);
	INIT_DELAYED_WORK(&di->otg_insert_work, uem_otg_insert_work);
	INIT_DELAYED_WORK(&di->attach_work, uem_attach_work);
	INIT_DELAYED_WORK(&di->dr_swap_work, uem_dr_swap_work);
	INIT_DELAYED_WORK(&di->ncm_enumeration_work, uem_ncm_enumeration_work);
	INIT_DELAYED_WORK(&di->usb_power_work, uem_usb_power_work);
	INIT_DELAYED_WORK(&di->host_ctl_work, uem_host_ctl_work);
	memset_s(&g_uem_store_info, sizeof(g_uem_store_info), 0, sizeof(g_uem_store_info));
	di->uem_lock = power_wakeup_source_register(di->dev, "uem_wakelock");
	di->ext_modem_nb.notifier_call = uem_notifier_call;
	ret = power_event_bnc_register(POWER_BNT_USB_EXT_MODEM, &di->ext_modem_nb);
	di->connect_nb.notifier_call = uem_notifier_call;
	ret = power_event_bnc_register(POWER_BNT_CONNECT, &di->connect_nb);
	di->hw_usb_nb.notifier_call = uem_notifier_call;
	ret = power_event_bnc_register(POWER_BNT_HW_USB, &di->hw_usb_nb);
	power_sysfs_create_group("hw_usb", "usb_extra_modem", &uem_attr_group);
	hwlog_info("probe end\n");

	return 0;

gpio_q5_init_fail:
	gpio_free(di->gpio_q4);
gpio_q4_init_fail:
	platform_set_drvdata(pdev, NULL);
	g_uem_di = NULL;
	kfree(di);
	return ret;
}

static int uem_remove(struct platform_device *pdev)
{
	struct uem_dev_info *di = platform_get_drvdata(pdev);

	if (!di)
		return 0;

	power_sysfs_remove_group(di->dev, &uem_attr_group);
	power_wakeup_source_unregister(di->uem_lock);
	gpio_free(di->gpio_q4);
	gpio_free(di->gpio_q5);
	platform_set_drvdata(pdev, NULL);
	mutex_destroy(&di->notifier_lock);
	mutex_destroy(&di->otg_status_lock);
	g_uem_di = NULL;
	kfree(di);

	return 0;
}

static void uem_pm_complete(struct device *dev)
{
	struct uem_dev_info *di = uem_get_dev_info();

	if (!di)
		return;

	if (!uem_check_online_status() || di->vbus_status || di->wlrx_status) {
		hwlog_info("pm complete\n");
		uem_charger_regn_adc_register_ctrl(true);
	}
}

static const struct dev_pm_ops uem_pm_ops = {
	.complete = uem_pm_complete,
};
#define UEM_PM_OPS (&uem_pm_ops)

static const struct of_device_id uem_match_table[] = {
	{
		.compatible = "huawei,usb_extra_modem",
		.data = NULL,
	},
	{},
};

static struct platform_driver uem_driver = {
	.probe = uem_probe,
	.remove = uem_remove,
	.driver = {
		.name = "huawei,usb_extra_modem",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(uem_match_table),
		.pm = UEM_PM_OPS,
	},
};

static int __init uem_init(void)
{
	return platform_driver_register(&uem_driver);
}

static void __exit uem_exit(void)
{
	platform_driver_unregister(&uem_driver);
}

module_init(uem_init);
module_exit(uem_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("huawei usb extra modem driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
