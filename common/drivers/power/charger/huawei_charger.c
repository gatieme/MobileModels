/*
 * huawei_charger.c
 *
 * huawei charger driver
 *
 * Copyright (c) 2012-2019 Huawei Technologies Co., Ltd.
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
#include <linux/usb/otg.h>
#include <linux/io.h>
#include <linux/gpio.h>
#include <linux/power_supply.h>
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/notifier.h>
#include <linux/mutex.h>
#include <linux/spmi.h>
#include <linux/sysfs.h>
#include <linux/kernel.h>
#include <linux/power/huawei_charger.h>
#include <linux/power/huawei_battery.h>
#include <linux/version.h>
#include <chipset_common/hwpower/common_module/power_log.h>
#include <chipset_common/hwpower/common_module/power_sysfs.h>
#include <huawei_platform/power/huawei_charger_adaptor.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <chipset_common/hwpower/common_module/power_interface.h>
#include <chipset_common/hwpower/common_module/power_cmdline.h>
#include <chipset_common/hwpower/common_module/power_common_macro.h>
#include <chipset_common/hwpower/common_module/power_supply.h>
#include <chipset_common/hwpower/common_module/power_supply_interface.h>
#include <chipset_common/hwpower/charger/charge_common_vote.h>
#include <chipset_common/hwpower/wireless_charge/wireless_rx_pmode.h>
#include <chipset_common/hwpower/wireless_charge/wireless_rx_plim.h>
#if IS_ENABLED(CONFIG_HUAWEI_POWER_GLINK_INTERFACE)
#include <huawei_platform/hwpower/common_module/power_glink_interface.h>
#endif /* IS_ENABLED(CONFIG_HUAWEI_POWER_GLINK_INTERFACE) */
#include <huawei_platform/hwpower/common_module/power_platform.h>
#include <huawei_platform/hwpower/common_module/power_platform_macro.h>
#include <huawei_platform/hwpower/charger/charger_loginfo.h>
#include <chipset_common/hwpower/hardware_monitor/ship_mode.h>
#include <chipset_common/hwpower/buck_charge/buck_charge_ic_manager.h>
#include <chipset_common/hwpower/buck_charge/buck_charge_sysfs.h>
#include <chipset_common/hwpower/buck_charge/buck_charge_platform_interface.h>

#ifdef HWLOG_TAG
#undef HWLOG_TAG
#endif
#define HWLOG_TAG huawei_charger
HWLOG_REGIST();
static struct charge_device_info *g_di;

struct device *charge_dev = NULL;
static struct kobject *g_sysfs_poll = NULL;
static struct charge_device_info *g_charger_device_para = NULL;

struct charge_device_info *get_charger_device_info(void)
{
	if (!g_charger_device_para)
		return NULL;
	return g_charger_device_para;
}

bool huawei_charger_get_dc_enable_hiz_status(void)
{
	return false;
}

unsigned int huawei_charger_get_hota_iin_limit(void)
{
	return 0;
}

unsigned int huawei_charger_get_startup_iin_limit(void)
{
	return 0;
}

static ssize_t get_poll_charge_start_event(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct charge_device_info *chip = g_charger_device_para;

	if (!dev || !attr || !buf) {
		pr_err("%s: invalid param, fatal error\n", __func__);
		return -EINVAL;
	}

	if (chip)
		return snprintf(buf, PAGE_SIZE, "%d\n", chip->input_event);
	else
		return 0;
}

#define POLL_CHARGE_EVENT_MAX 3000
static ssize_t set_poll_charge_event(struct device *dev,
			struct device_attribute *attr, const char *buf, size_t count)
{
	struct charge_device_info *chip = g_charger_device_para;
	long val = 0;

	if (!dev || !attr || !buf) {
		pr_err("%s: invalid param, fatal error\n", __func__);
		return -EINVAL;
	}

	if (chip) {
		if ((kstrtol(buf, POWER_BASE_DEC, &val) < 0) ||
			(val < 0) || (val > POLL_CHARGE_EVENT_MAX))
			return -EINVAL;
		chip->input_event = val;
		power_event_notify_sysfs(g_sysfs_poll, NULL, "poll_charge_start_event");
	}
	return count;
}

static DEVICE_ATTR(poll_charge_start_event, (S_IWUSR | S_IRUGO),
				get_poll_charge_start_event,
				set_poll_charge_event);
static ssize_t get_poll_charge_done_event(struct device *dev,
					  struct device_attribute *attr,
					  char *buf)
{
	if (!dev || !attr || !buf) {
		pr_err("%s: invalid param, fatal error\n", __func__);
		return -EINVAL;
	}

	return 0;
}

static DEVICE_ATTR(poll_charge_done_event, (S_IWUSR | S_IRUGO),
		   get_poll_charge_done_event, NULL);
static ssize_t get_poll_fcc_learn_event(struct device *dev,
					  struct device_attribute *attr,
					  char *buf)
{
	if (!dev || !attr || !buf) {
		pr_err("%s: invalid param, fatal error\n", __func__);
		return -EINVAL;
	}

	return 0;
}

static DEVICE_ATTR(poll_fcc_learn_event, (S_IWUSR | S_IRUGO),
		   get_poll_fcc_learn_event, NULL);

static int charge_event_poll_register(struct device *dev)
{
	int ret;

	if (!dev) {
		pr_err("%s: invalid param, fatal error\n", __func__);
		return -EINVAL;
	}

	ret = sysfs_create_file(&dev->kobj, &dev_attr_poll_charge_start_event.attr);
	if (ret) {
		pr_err("fail to create poll node for %s\n", dev->kobj.name);
		return ret;
	}
	ret = sysfs_create_file(&dev->kobj, &dev_attr_poll_charge_done_event.attr);
	if (ret) {
		pr_err("fail to create poll node for %s\n", dev->kobj.name);
		return ret;
	}
	ret = sysfs_create_file(&dev->kobj, &dev_attr_poll_fcc_learn_event.attr);
	if (ret) {
		pr_err("fail to create poll node for %s\n", dev->kobj.name);
		return ret;
	}

	g_sysfs_poll = &dev->kobj;
	return ret;
}

void cap_learning_event_done_notify(void)
{
	struct charge_device_info *chip = g_charger_device_para;

	if (!chip) {
		hwlog_info("smb device is not init, do nothing!\n");
		return;
	}

	power_event_notify_sysfs(g_sysfs_poll, NULL, "poll_fcc_learn_event");
}

void cap_charge_done_event_notify(void)
{
	struct charge_device_info *chip = g_charger_device_para;

	if (!chip) {
		hwlog_info("smb device is not init, do nothing\n");
		return;
	}

	power_event_notify_sysfs(g_sysfs_poll, NULL, "poll_charge_done_event");
}

static void charge_event_notify(unsigned int event)
{
	struct charge_device_info *chip = g_charger_device_para;

	if (!chip) {
		hwlog_info("smb device is not init, do nothing!\n");
		return;
	}
	/* avoid notify charge stop event continuously without charger inserted */
	if ((chip->input_event != event) || (event == SMB_START_CHARGING)) {
		chip->input_event = event;
		power_event_notify_sysfs(g_sysfs_poll, NULL, "poll_charge_start_event");
	}
}

static int huawei_charger_set_hz_mode(struct charge_device_info *di, int val)
{
	if (!di)
		return -EINVAL;

	charge_set_hiz_enable(val);
	charge_sysfs_set_sysfs_value(CHARGE_SYSFS_HIZ, val);
	return 0;
}

void huawei_charger_set_rsmc_limit(int val)
{
	int iin = (val > 0) ? val : BUCK_CHARGE_DEFAULT_IIN_THL;

	hwlog_info("set rsmc limit %d\n", iin);
	(void)chg_vote_set(VOTE_OBJ_TYPE_BUCK, VOTE_OBJ_USB_ICL, VOTE_CLIENT_RSMC,
		true, iin);
}
EXPORT_SYMBOL(huawei_charger_set_rsmc_limit);

void huawei_charger_set_dc_disable_flags(bool disable, int type)
{
	int val = disable ? DC_SET_DISABLE_FLAGS : DC_CLEAR_DISABLE_FLAGS;

	direct_charge_set_disable_flags(val, type);
	if (disable)
		wlrx_plim_set_src(WLTRX_DRV_MAIN, WLRX_PLIM_SRC_RSMC);
	else
		wlrx_plim_clear_src(WLTRX_DRV_MAIN, WLRX_PLIM_SRC_RSMC);
}
EXPORT_SYMBOL(huawei_charger_set_dc_disable_flags);

bool huawei_charger_in_dc_path(void)
{
	return (direct_charge_get_stage_status() > DC_STAGE_SWITCH_DETECT) ||
		wlrx_pmode_in_dc_mode(WLTRX_DRV_MAIN);
}
EXPORT_SYMBOL(huawei_charger_in_dc_path);

int huawei_charger_get_ibus(void)
{
	return charge_get_ibus();
}
EXPORT_SYMBOL(huawei_charger_get_ibus);

int huawei_charger_get_vterm_dec(unsigned int *value)
{
	struct charge_device_info *di = g_charger_device_para;

	if (!di || !value)
		return -EINVAL;

	*value = di->vterm_dec;
	return 0;
}

#if IS_ENABLED(CONFIG_HUAWEI_POWER_GLINK_INTERFACE)
void huawei_charger_set_fcp_current_limit(unsigned int value)
{
	int fcp_pd_support_icl = power_glink_interface_support_fcp_pd_icl();

	if (fcp_pd_support_icl == 1) {
		chg_vote_set(VOTE_OBJ_TYPE_BUCK, VOTE_OBJ_USB_ICL, VOTE_CLIENT_FCP, true, value);
		hwlog_info("[%s]:set fcp limit %u\n", __func__, value);
	}
}

int huawei_charger_get_iin_thermal_charge_type(void)
{
	int vol = 0;
	struct charge_device_info *di = g_charger_device_para;

	if (!di)
		return CHARGE_SYSFS_IIN_THERMAL_WCURRENT_5V;

	if (charge_get_charger_type() == CHARGER_TYPE_WIRELESS) {
		power_supply_get_int_property_value("Wireless",
			POWER_SUPPLY_PROP_VOLTAGE_NOW, &vol);
		return (vol / POWER_UV_PER_MV / POWER_MV_PER_V < ADAPTER_7V) ?
			CHARGE_SYSFS_IIN_THERMAL_WLCURRENT_5V : CHARGE_SYSFS_IIN_THERMAL_WLCURRENT_9V;
	} else {
		power_supply_get_int_property_value("usb",
			POWER_SUPPLY_PROP_VOLTAGE_NOW, &vol);
		return (vol / POWER_UV_PER_MV / POWER_MV_PER_V < ADAPTER_7V) ?
			CHARGE_SYSFS_IIN_THERMAL_WCURRENT_5V : CHARGE_SYSFS_IIN_THERMAL_WCURRENT_9V;
	}
}
#else
void huawei_charger_set_fcp_current_limit(unsigned int value)
{
}

int huawei_charger_get_iin_thermal_charge_type(void)
{
	int vol = 0;
	struct charge_device_info *di = g_charger_device_para;

	if (!di)
		return CHARGE_SYSFS_IIN_THERMAL_WCURRENT_5V;

	power_supply_get_int_prop(POWER_PLATFORM_USB_PSY_NAME,
		POWER_SUPPLY_PROP_VOLTAGE_NOW, &vol, 0, POWER_UV_PER_MV);

	if (charge_get_charger_type() == CHARGER_TYPE_WIRELESS)
		return (vol / POWER_MV_PER_V < ADAPTER_7V) ?
			CHARGE_SYSFS_IIN_THERMAL_WLCURRENT_5V : CHARGE_SYSFS_IIN_THERMAL_WLCURRENT_9V;

	return (vol / POWER_MV_PER_V < ADAPTER_7V) ?
		CHARGE_SYSFS_IIN_THERMAL_WCURRENT_5V : CHARGE_SYSFS_IIN_THERMAL_WCURRENT_9V;
}
#endif /* IS_ENABLED(CONFIG_HUAWEI_POWER_GLINK_INTERFACE) */

static void update_iin_thermal(struct charge_device_info *di)
{
	int iin_thl;

	if (!di || !power_supply_check_psy_available("huawei_charge", &di->chg_psy)) {
		pr_err("%s: invalid param, fatal error\n", __func__);
		return;
	}

	iin_thl = charge_sysfs_get_sysfs_value(CHARGE_SYSFS_IIN_THERMAL);
	buck_charge_set_iin_thermal_limit(iin_thl);
	hwlog_info("update iin_thermal current: %d\n", iin_thl);
}

static void smb_update_status(struct charge_device_info *di)
{
	unsigned int events = 0;
	int charging_enabled;
	int battery_present;

	if (!di || !power_supply_check_psy_available("battery", &di->batt_psy)) {
		pr_err("%s: invalid param, fatal error\n", __func__);
		return;
	}

	charging_enabled = power_supply_return_int_property_value_with_psy(
		di->batt_psy, POWER_SUPPLY_PROP_CHARGING_ENABLED);
	battery_present = power_supply_return_int_property_value_with_psy(
		di->batt_psy, POWER_SUPPLY_PROP_PRESENT);
	if (!battery_present)
		events = SMB_STOP_CHARGING;
	if (!events) {
		if (charging_enabled && battery_present)
			events = SMB_START_CHARGING;
	}
	charge_event_notify(events);
	update_iin_thermal(di);
}

static void smb_charger_work(struct work_struct *work)
{
	struct charge_device_info *chip = NULL;

	if (!work) {
		pr_err("%s: invalid param, fatal error\n", __func__);
		return;
	}

	chip = container_of(work, struct charge_device_info, smb_charger_work.work);
	if (!chip) {
		pr_err("%s: Cannot get chip, fatal error\n", __func__);
		return;
	}

	smb_update_status(chip);
	schedule_delayed_work(&chip->smb_charger_work,
				msecs_to_jiffies(QPNP_SMBCHARGER_TIMEOUT));
}

int huawei_handle_charger_event(unsigned long event)
{
	struct charge_device_info *di = NULL;
    /* give a chance for bootup with usb present case */
	static int smb_charge_work_flag = 1;
	bool flag = TRUE;

	di = g_charger_device_para;
	if (!di) {
		pr_err(" %s charge ic  is unregister !\n", __func__);
		return -EINVAL;
	}
	if ((event != POWER_NE_THIRDPLAT_CHARGING_STOP) && smb_charge_work_flag) {
		charge_event_notify(SMB_START_CHARGING);
		flag = schedule_delayed_work(&di->smb_charger_work, msecs_to_jiffies(0));
		if (!flag) {
			cancel_delayed_work_sync(&di->smb_charger_work);
			flag = schedule_delayed_work(&di->smb_charger_work, msecs_to_jiffies(0));
			hwlog_info("%s: flag = %d\n", __func__, flag);
		}
		smb_charge_work_flag = 0;
		hwlog_info("start charge work, event %lu\n", event);
	}
	if (event == POWER_NE_THIRDPLAT_CHARGING_STOP) {
		charge_event_notify(SMB_STOP_CHARGING);
		cancel_delayed_work_sync(&di->smb_charger_work);
		smb_charge_work_flag = 1;
		hwlog_info("stop charge work, event %lu\n", event);
	}
	return 0;
}

void huawei_charger_update_iin_thermal(void)
{
	struct charge_device_info *di = g_charger_device_para;

	if (!di)
		return;

	update_iin_thermal(di);
}

static int charger_plug_notifier_call(struct notifier_block *nb, unsigned long event, void *data)
{
	if (huawei_handle_charger_event(event))
		return NOTIFY_BAD;
	hwlog_info("charger plug in or out\n");
	return NOTIFY_OK;
}

static bool hw_charger_init_psy(struct charge_device_info *di)
{
	int ret = 0;

	di->bk_batt_psy = power_supply_get_by_name("bk_battery");
	if (!di->bk_batt_psy) {
		pr_err("%s: bk_batt_psy is null\n", __func__);
		ret += -EINVAL;
	}
	di->pc_port_psy = power_supply_get_by_name("pc_port");
	if (!di->pc_port_psy) {
		pr_err("%s: pc_port_psy is null\n", __func__);
		ret += -EINVAL;
	}

	di->batt_psy = power_supply_get_by_name("battery");
	if (!di->batt_psy) {
		pr_err("%s: batt_psy is null\n", __func__);
		ret += -EINVAL;
	}

	di->chg_psy = power_supply_get_by_name("huawei_charge");
	if (!di->chg_psy) {
		pr_err("%s: chg_psy is null\n", __func__);
		ret += -EINVAL;
	}

	di->bms_psy = power_supply_get_by_name("bms");
	if (!di->bms_psy) {
		pr_err("%s: bms_psy is null\n", __func__);
		ret += -EINVAL;
	}

	if (ret < 0)
		return false;

	return true;
}

#if IS_ENABLED(CONFIG_HUAWEI_POWER_GLINK_INTERFACE)
static void huawei_charger_set_entry_time(unsigned int time, void *dev_data)
{
	u32 id = POWER_GLINK_PROP_ID_SET_SHIP_MODE_TIMING;
	u32 value = time;

	if (!dev_data)
		return;

	(void)power_glink_interface_set_property_value(id, &value, GLINK_DATA_ONE);
	pr_err("set_entry_time: value=%u\n", value);
}

static void huawei_charger_set_work_mode(unsigned int mode, void *dev_data)
{
	u32 id = POWER_GLINK_PROP_ID_SET_SHIP_MODE;
	u32 value;

	if (!dev_data)
		return;

	if ((mode == SHIP_MODE_IN_SHIP) || (mode == SHIP_MODE_IN_SHUTDOWN_SHIP))
		value = 0;
	else
		return;

	(void)power_glink_interface_set_property_value(id, &value, GLINK_DATA_ONE);
	pr_err("set_work_mode: value=%u\n", value);
}

static struct ship_mode_ops huawei_charger_ship_mode_ops = {
	.ops_name = "huawei_charger",
	.set_entry_time = huawei_charger_set_entry_time,
	.set_work_mode = huawei_charger_set_work_mode,
};
#endif /* IS_ENABLED(CONFIG_HUAWEI_POWER_GLINK_INTERFACE) */

static int charge_probe(struct platform_device *pdev)
{
	int ret;
	struct charge_device_info *di = NULL;
	int usb_pre;

	if (!pdev)
		return -EINVAL;

	di = kzalloc(sizeof(*di), GFP_KERNEL);
	if (!di)
		return -ENOMEM;

	ret = of_property_read_u32(pdev->dev.of_node, "huawei,fcp-test-delay", &di->fcp_test_delay);
	if (ret) {
		pr_info("There is no fcp test delay setting, use default time: 1s\n");
		di->fcp_test_delay = DEFAULT_FCP_TEST_DELAY;
	}

	INIT_DELAYED_WORK(&di->smb_charger_work, smb_charger_work);
	di->dev = &(pdev->dev);
	dev_set_drvdata(&(pdev->dev), di);

	charge_sysfs_init(&pdev->dev);

	charge_set_reset_adapter_source(RESET_ADAPTER_DIRECT_MODE, FALSE);
	g_di = di;
	di->nb.notifier_call = charger_plug_notifier_call;
	ret = power_event_bnc_register(POWER_BNT_THIRDPLAT_CHARGING, &di->nb);
	if (ret < 0)
		pr_err("usb charger register notify failed\n");

	charge_event_poll_register(charge_dev);
	g_charger_device_para = di;

	if (power_supply_check_psy_available("usb", &di->usb_psy)) {
		usb_pre = power_supply_return_int_property_value_with_psy(
			di->usb_psy, POWER_SUPPLY_PROP_ONLINE);
		if (usb_pre) {
			ret = charger_plug_notifier_call(&di->nb, 0, NULL);
			if (ret != NOTIFY_OK)
				pr_err("charger plug notifier call failed\n");
		}
	}
	if (!hw_charger_init_psy(di))
		pr_err("psy init failed\n");

	charger_loginfo_register(di);

#if IS_ENABLED(CONFIG_HUAWEI_POWER_GLINK_INTERFACE)
	huawei_charger_ship_mode_ops.dev_data = di;
	ship_mode_ops_register(&huawei_charger_ship_mode_ops, SHIP_MODE_IC_TYPE_PLATFORM);
#endif /* IS_ENABLED(CONFIG_HUAWEI_POWER_GLINK_INTERFACE) */

	pr_info("huawei charger probe ok!\n");
	return 0;
}

static void charge_event_poll_unregister(struct device *dev)
{
	if (!dev) {
		pr_err("%s: invalid param, fatal error\n", __func__);
		return;
	}

	sysfs_remove_file(&dev->kobj, &dev_attr_poll_charge_start_event.attr);
	g_sysfs_poll = NULL;
}

static int charge_remove(struct platform_device *pdev)
{
	struct charge_device_info *di = NULL;

	if (!pdev)
		return -EINVAL;

	di = dev_get_drvdata(&pdev->dev);
	if (!di)
		return -EINVAL;

	power_event_bnc_unregister(POWER_BNT_THIRDPLAT_CHARGING, &di->nb);
	cancel_delayed_work_sync(&di->smb_charger_work);
	charge_event_poll_unregister(charge_dev);
	charge_sysfs_remove(&pdev->dev);
	kfree(di);
	di = NULL;
	g_di = NULL;
	g_charger_device_para = NULL;

	return 0;
}

static void charge_shutdown(struct platform_device  *pdev)
{
	return;
}

#ifdef CONFIG_PM
static int charge_suspend(struct platform_device *pdev, pm_message_t state)
{
	return 0;
}

static int charge_resume(struct platform_device *pdev)
{
	return 0;
}
#endif

static struct of_device_id charge_match_table[] = {
	{
		.compatible = "huawei,charger",
		.data = NULL,
	},
	{
	},
};

static struct platform_driver charge_driver = {
	.probe = charge_probe,
	.remove = charge_remove,
#ifdef CONFIG_PM
	.suspend = charge_suspend,
	.resume = charge_resume,
#endif
	.shutdown = charge_shutdown,
	.driver = {
		.name = "huawei,charger",
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

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("huawei charger module driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
