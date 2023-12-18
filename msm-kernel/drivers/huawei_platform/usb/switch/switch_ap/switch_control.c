/*
 * switch_control.c
 *
 * driver file for switch_control
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

#include "switch_interface.h"
#include <linux/device.h>
#include <linux/delay.h>
#include <linux/fs.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/adapter/adapter_test.h>
#include <chipset_common/hwpower/common_module/power_devices_info.h>
#include <huawei_platform/hwpower/common_module/power_platform.h>
#include <huawei_platform/power/direct_charger/direct_charger.h>
#include <huawei_platform/power/huawei_charger_adaptor.h>
#include <huawei_platform/power/huawei_charger_common.h>

#define HWLOG_TAG switch_control
HWLOG_REGIST();

int switch_control_manual_switch(int input_select)
{
	struct switch_interface_control_ops *ops = switch_interface_get_control_ops();

	if (!ops || !ops->manual_switch) {
		hwlog_err("ops is null or manual_switch is null\n");
		return -1;
	}

	hwlog_info("input_select=%d\n", input_select);
	return ops->manual_switch(input_select);
}

int switch_control_manual_detach(void)
{
	struct switch_interface_di *di = switch_interface_get_device_info();

	if (!di)
		return -EINVAL;

	/* detach work delay 20ms */
	schedule_delayed_work(&di->detach_delayed_work, msecs_to_jiffies(20));

	return 0;
}

void switch_control_manual_detach_work(struct work_struct *work)
{
	struct switch_interface_control_ops *ops = switch_interface_get_control_ops();

	if (!ops || !ops->detach_work) {
		hwlog_err("ops is null or detach_work is null\n");
		return;
	}

	return ops->detach_work();
}

static ssize_t switch_control_dump_regs_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct switch_interface_control_ops *ops = switch_interface_get_control_ops();

	if (!ops || !ops->dump_regs) {
		hwlog_err("error: ops is null or dump_regs is null\n");
		return -1;
	}

	return ops->dump_regs(buf);
}

static DEVICE_ATTR(dump_regs, S_IRUGO, switch_control_dump_regs_show, NULL);

static ssize_t jigpin_ctrl_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t size)
{
	struct switch_interface_control_ops *ops = switch_interface_get_control_ops();
	int jig_val;

	if (!ops || !ops->jigpin_ctrl_store) {
		hwlog_err("ops is null or jigpin_ctrl_store is null\n");
		return -1;
	}

	if (sscanf(buf, "%d", &jig_val) != 1) {
		hwlog_err("unable to parse input %s\n", buf);
		return -1;
	}

	return ops->jigpin_ctrl_store(jig_val);
}

static ssize_t jigpin_ctrl_show(struct device *dev, struct device_attribute *attr,
	char *buf)
{
	struct switch_interface_control_ops *ops = switch_interface_get_control_ops();

	if (!ops || !ops->jigpin_ctrl_show) {
		hwlog_err("error: ops is null or jigpin_ctrl_show is null\n");
		return -1;
	}

	return ops->jigpin_ctrl_show(buf);
}

static DEVICE_ATTR(jigpin_ctrl, S_IRUGO | S_IWUSR, jigpin_ctrl_show, jigpin_ctrl_store);

static ssize_t switchctrl_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t size)
{
	struct switch_interface_control_ops *ops = switch_interface_get_control_ops();
	int action = 0;

	if (!ops || !ops->switchctrl_store) {
		hwlog_err("error: ops is null or switchctrl_store is null!\n");
		return -1;
	}

	if (sscanf(buf, "%d", &action) != 1) {
		hwlog_err("error: unable to parse input:%s!\n", buf);
		return -1;
	}

	return ops->switchctrl_store(action);
}

static ssize_t switchctrl_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct switch_interface_control_ops *ops = switch_interface_get_control_ops();

	if (!ops || !ops->switchctrl_show) {
		hwlog_err("ops is null or switchctrl_show is null\n");
		return -1;
	}

	return ops->switchctrl_show(buf);
}

static DEVICE_ATTR(switchctrl, S_IRUGO | S_IWUSR, switchctrl_show, switchctrl_store);

static ssize_t fcp_mmi_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	int result;
	unsigned int type = charge_get_charger_type();

	/* judge whether support fcp */
	if (adapter_test_check_protocol_type(ADAPTER_PROTOCOL_FCP)) {
		result = AT_RESULT_NOT_SUPPORT;
		return snprintf(buf, PAGE_SIZE, "%d\n", result);
	}
	/* to avoid the usb port cutoff when CTS test */
	if ((type == CHARGER_TYPE_USB) || (type == CHARGER_TYPE_BC_USB)) {
		result = AT_RESULT_FAIL;
		hwlog_err("fcp detect fail 1,charge type is %u\n", type);
		return snprintf(buf, PAGE_SIZE, "%d\n", result);
	}
	/* fcp adapter detect */
	if (adapter_test_check_support_mode(ADAPTER_PROTOCOL_FCP)) {
		/* 0:sdp 1:cdp 2:dcp 3:unknow 4:none */
		hwlog_err("fcp detect fail 2, charge type is %u\n", switch_interface_get_charger_type());
		result = AT_RESULT_FAIL;
	} else {
		result = AT_RESULT_SUCC;
	}
	hwlog_info("%s: fcp mmi result %d\n", __func__, result);
	return snprintf(buf, PAGE_SIZE, "%d\n", result);
}

static DEVICE_ATTR(fcp_mmi, S_IRUGO, fcp_mmi_show, NULL);

void switch_control_sysfs_init(struct switch_interface_di *di)
{
	struct class *switch_class = NULL;
	struct device *new_dev = NULL;
	int ret;

	ret = device_create_file(di->dev, &dev_attr_dump_regs);
	if (ret < 0) {
		hwlog_err("sysfs device_file create failed\n");
		return;
	}

	/* create a node for phone-off current drain test */
	ret = device_create_file(di->dev, &dev_attr_switchctrl);
	if (ret < 0) {
		hwlog_err("device_create_file error\n");
		goto fail_create_switchctrl;
	}

	ret = device_create_file(di->dev, &dev_attr_jigpin_ctrl);
	if (ret < 0) {
		hwlog_err("device_create_file error\n");
		goto fail_create_jigpin_ctrl;
	}

	ret = device_create_file(di->dev, &dev_attr_fcp_mmi);
	if (ret < 0) {
		hwlog_err("device_create_file error\n");
		goto fail_create_fcp_mmi;
	}

	switch_class = class_create(THIS_MODULE, "usb_switch");
	if (IS_ERR(switch_class)) {
		hwlog_err("create switch class failed\n");
		ret = PTR_ERR(switch_class);
		goto fail_create_link;
	}
	new_dev = device_create(switch_class, NULL, 0, NULL, "switch_ctrl");
	if (!new_dev) {
		hwlog_err("device create failed\n");
		ret = PTR_ERR(new_dev);
		goto fail_create_link;
	}
	ret = sysfs_create_link(&new_dev->kobj, &di->dev->kobj,
		"manual_ctrl");
	if (ret < 0) {
		hwlog_err("create link to switch failed\n");
		goto fail_create_link;
	}

	return;

fail_create_link:
	device_remove_file(di->dev, &dev_attr_fcp_mmi);
fail_create_fcp_mmi:
	device_remove_file(di->dev, &dev_attr_jigpin_ctrl);
fail_create_jigpin_ctrl:
	device_remove_file(di->dev, &dev_attr_switchctrl);
fail_create_switchctrl:
	device_remove_file(di->dev, &dev_attr_dump_regs);
}

void switch_control_sysfs_exit(struct switch_interface_di *di)
{
	device_remove_file(di->dev, &dev_attr_fcp_mmi);
	device_remove_file(di->dev, &dev_attr_dump_regs);
	device_remove_file(di->dev, &dev_attr_switchctrl);
	device_remove_file(di->dev, &dev_attr_jigpin_ctrl);
}
