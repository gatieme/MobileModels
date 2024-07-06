// SPDX-License-Identifier: GPL-2.0
/*
 * direct_charge_turbo.c
 *
 * direct charge turbo driver
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

#include <linux/init.h>
#include <linux/module.h>
#include <linux/workqueue.h>
#include <chipset_common/hwpower/common_module/power_common_macro.h>
#include <chipset_common/hwpower/common_module/power_dts.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/common_module/power_sysfs.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_adapter.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_turbo.h>
#include <securec.h>

#define HWLOG_TAG direct_charge_turbo
HWLOG_REGIST();

#define TURBO_CHARGE_SUPPORT         1
#define TURBO_SYSFS_BUF_SIZE         32
#define TURBO_CHARGE_STATUS_BUF_SIZE 128
#define TIME_PARA_GROUP_MAX_SIZE     3
#define TIME_PARA_NUM_DEFAULT        3

enum direct_charge_turbo_sysfs_type {
	DIRECT_CHARGE_TURBO_SYSFS_BEGIN = 0,
	DIRECT_CHARGE_TURBO_SYSFS_TURBO_SUPPORT = DIRECT_CHARGE_TURBO_SYSFS_BEGIN,
	DIRECT_CHARGE_TURBO_SYSFS_TURBO_CHARGE_STATUS,
	DIRECT_CHARGE_TURBO_SYSFS_END,
};

enum {
	TURBO_CHARGE_DISABLE,
	TURBO_CHARGE_NEED_AGREE,
	TURBO_CHARGE_ENABLE,
	TURBO_CHARGE_PRE_CHECK,
	TURBO_CHARGE_STATUS_END,
};

enum {
	TIME_PARA_GROUP_MODE,
	TIME_PARA_GROUP_TIME,
	TIME_PARA_GROUP_NAME,
	TIME_PARA_GROUP_ADAPTER_MODE,
	TIME_PARA_GROUP_END,
};

struct time_para_group {
	int mode;
	int adapter_mode;
	int time;
	struct direct_charge_time_para time_para[DC_TIME_PARA_LEVEL];
};

struct direct_charge_turbo_dev {
	struct device *dev;
	u32 turbo_charge_status;
	bool time_para_parse_ok;
	struct time_para_group *time_para_group;
	int group_size;
	int time_para_by_adapter_mode;
};

static struct direct_charge_turbo_dev *g_direct_charge_turbo_dev;

void direct_charge_turbo_send_max_power(int value)
{
	struct power_event_notify_data n_data;

	power_ui_event_notify(POWER_UI_NE_INNER_MAX_POWER, &value);
	n_data.event = "BMS_EVT=TURBO_CHARGE";
	n_data.event_len = (int)strlen(n_data.event);
	power_event_report_uevent(&n_data);
	hwlog_info("send turbo charge uevent, inner_max_power=%d\n", value);
}

int direct_charge_turbo_get_time_para(int mode, struct direct_charge_time_para **para, int *size, int adap_mode)
{
	int i;
	struct direct_charge_turbo_dev *l_dev = g_direct_charge_turbo_dev;

	if (!l_dev || (l_dev->turbo_charge_status != TURBO_CHARGE_ENABLE) || !l_dev->time_para_parse_ok)
		return -EINVAL;

	adap_mode = (adap_mode & ADAPTER_SUPPORT_SC4) ? ADAPTER_SUPPORT_SC4 : ADAPTER_SUPPORT_SC;
	for (i = 0; i < l_dev->group_size; i++) {
		if ((mode == l_dev->time_para_group[i].mode) &&
			(!l_dev->time_para_by_adapter_mode ||
			(adap_mode == l_dev->time_para_group[i].adapter_mode))) {
			*para = &l_dev->time_para_group[i].time_para[0];
			*size = DC_TIME_PARA_LEVEL;
			return 0;
		}
	}

	return -EINVAL;
}

int direct_charge_turbo_get_charge_time(int mode, int *time, int adap_mode)
{
	int i;
	struct direct_charge_turbo_dev *l_dev = g_direct_charge_turbo_dev;

	if (!l_dev || (l_dev->turbo_charge_status != TURBO_CHARGE_ENABLE) || !l_dev->time_para_parse_ok)
		return -EINVAL;

	adap_mode = (adap_mode & ADAPTER_SUPPORT_SC4) ? ADAPTER_SUPPORT_SC4 : ADAPTER_SUPPORT_SC;
	for (i = 0; i < l_dev->group_size; i++) {
		if ((mode == l_dev->time_para_group[i].mode) &&
			(!l_dev->time_para_by_adapter_mode ||
			(adap_mode == l_dev->time_para_group[i].adapter_mode)) &&
			(l_dev->time_para_group[i].time > 0)) {
			*time = l_dev->time_para_group[i].time;
			return 0;
		}
	}
	return -EINVAL;
}

static void direct_charge_turbo_set_charge_status(u32 value)
{
	struct power_event_notify_data n_data;
	char temp[TURBO_CHARGE_STATUS_BUF_SIZE] = { 0 };
	struct direct_charge_turbo_dev *l_dev = g_direct_charge_turbo_dev;

	if (!l_dev || (value >= TURBO_CHARGE_STATUS_END)) {
		hwlog_err("%s di is null or value is invalid\n", __func__);
		return;
	}

	if (value == l_dev->turbo_charge_status) {
		hwlog_info("ignore same turbo status, value=%u\n", value);
		return;
	}

	l_dev->turbo_charge_status = value;
	n_data.event_len = snprintf_s(temp, TURBO_CHARGE_STATUS_BUF_SIZE, TURBO_CHARGE_STATUS_BUF_SIZE - 1,
		"TURBO_CHARGE_STATUS=%d", l_dev->turbo_charge_status);

	if (n_data.event_len < 0) {
		hwlog_info("fill turbo charge uevent buffer fail\n");
		return;
	}

	n_data.event = temp;
	power_event_report_uevent(&n_data);
	hwlog_info("set turbo charge status=%u, report turbo charge status uevent\n", l_dev->turbo_charge_status);
}

#ifdef CONFIG_SYSFS
static ssize_t direct_charge_turbo_sysfs_show(struct device *dev, struct device_attribute *attr, char *buf);
static ssize_t direct_charge_turbo_sysfs_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count);

static struct power_sysfs_attr_info direct_charge_turbo_sysfs_field_tbl[] = {
	power_sysfs_attr_ro(direct_charge_turbo, 0440, DIRECT_CHARGE_TURBO_SYSFS_TURBO_SUPPORT, turbo_support),
	power_sysfs_attr_rw(direct_charge_turbo, 0660, DIRECT_CHARGE_TURBO_SYSFS_TURBO_CHARGE_STATUS, turbo_charge_status),
};

#define DIRECT_CHARGE_TURBO_SYSFS_ATTRS_SIZE ARRAY_SIZE(direct_charge_turbo_sysfs_field_tbl)

static struct attribute *direct_charge_turbo_sysfs_attrs[DIRECT_CHARGE_TURBO_SYSFS_ATTRS_SIZE + 1];

static const struct attribute_group direct_charge_turbo_sysfs_attr_group = {
	.attrs = direct_charge_turbo_sysfs_attrs,
};

static ssize_t direct_charge_turbo_sysfs_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct power_sysfs_attr_info *info = NULL;
	struct direct_charge_turbo_dev *l_dev = g_direct_charge_turbo_dev;

	if (!l_dev)
		return -ENODEV;

	info = power_sysfs_lookup_attr(attr->attr.name, direct_charge_turbo_sysfs_field_tbl,
		DIRECT_CHARGE_TURBO_SYSFS_ATTRS_SIZE);
	if (!info)
		return -EINVAL;

	switch (info->name) {
	case DIRECT_CHARGE_TURBO_SYSFS_TURBO_SUPPORT:
		return scnprintf(buf, TURBO_SYSFS_BUF_SIZE, "%d\n", TURBO_CHARGE_SUPPORT);
	case DIRECT_CHARGE_TURBO_SYSFS_TURBO_CHARGE_STATUS:
		return scnprintf(buf, TURBO_SYSFS_BUF_SIZE, "%d\n", l_dev->turbo_charge_status);
	default:
		return 0;
	}
}

static ssize_t direct_charge_turbo_sysfs_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	int val = 0;
	struct power_sysfs_attr_info *info = NULL;
	struct direct_charge_turbo_dev *l_dev = g_direct_charge_turbo_dev;

	if (!l_dev)
		return -ENODEV;

	info = power_sysfs_lookup_attr(attr->attr.name, direct_charge_turbo_sysfs_field_tbl,
		DIRECT_CHARGE_TURBO_SYSFS_ATTRS_SIZE);
	if (!info)
		return -EINVAL;

	switch (info->name) {
	case DIRECT_CHARGE_TURBO_SYSFS_TURBO_CHARGE_STATUS:
		if (kstrtoint(buf, POWER_BASE_DEC, &val))
			return -EINVAL;
		direct_charge_turbo_set_charge_status(val);
		break;
	default:
		break;
	}

	return count;
}

static void direct_charge_turbo_sysfs_create_group(struct device *dev)
{
	power_sysfs_init_attrs(direct_charge_turbo_sysfs_attrs, direct_charge_turbo_sysfs_field_tbl,
		DIRECT_CHARGE_TURBO_SYSFS_ATTRS_SIZE);
	power_sysfs_create_link_group("hw_power", "charger", "direct_charge_turbo", dev,
		&direct_charge_turbo_sysfs_attr_group);
}

static void direct_charge_turbo_sysfs_remove_group(struct device *dev)
{
	power_sysfs_remove_link_group("hw_power", "charger", "direct_charge_turbo", dev,
		&direct_charge_turbo_sysfs_attr_group);
}
#else
static inline void direct_charge_turbo_sysfs_create_group(struct device *dev)
{
}

static inline void direct_charge_turbo_sysfs_remove_group(struct device *dev)
{
}
#endif /* CONFIG_SYSFS */

static int direct_charge_turbo_parse_time_para(struct device_node *np, const char *name,
	struct direct_charge_time_para *para)
{
	int len;

	len = power_dts_read_string_array(power_dts_tag(HWLOG_TAG), np, name,
		(int *)para, DC_TIME_PARA_LEVEL, DC_TIME_INFO_MAX);

	return (len < 0) ? len : 0;
}

static int direct_charge_turbo_parse_time_para_group(struct device_node *np, struct direct_charge_turbo_dev *di)
{
	int i, row, col, len, idata, para_num;
	const char *tmp_string = NULL;

	para_num = di->time_para_by_adapter_mode ? TIME_PARA_GROUP_END : TIME_PARA_NUM_DEFAULT;
	len = power_dts_read_count_strings(power_dts_tag(HWLOG_TAG), np, "time_para_group",
		TIME_PARA_GROUP_MAX_SIZE, para_num);
	if (len < 0)
		return -EPERM;

	di->time_para_group = kzalloc(sizeof(struct time_para_group) * len / para_num, GFP_KERNEL);
	if (!di->time_para_group)
		return -ENOMEM;

	for (i = 0; i < len; i++) {
		if (power_dts_read_string_index(power_dts_tag(HWLOG_TAG), np, "time_para_group", i, &tmp_string))
			goto err_out;
		row = i / para_num;
		col = i % para_num;
		switch (col) {
		case TIME_PARA_GROUP_MODE:
			if (kstrtoint(tmp_string, POWER_BASE_DEC, &idata))
				goto err_out;
			if ((idata > SC4_MODE) || (idata <= 0))
				goto err_out;
			di->time_para_group[row].mode = idata;
			break;
		case TIME_PARA_GROUP_TIME:
			if (kstrtoint(tmp_string, POWER_BASE_DEC, &idata))
				goto err_out;
			di->time_para_group[row].time = idata;
			break;
		case TIME_PARA_GROUP_NAME:
			if (direct_charge_turbo_parse_time_para(np, tmp_string,
				di->time_para_group[row].time_para))
				goto err_out;
			break;
		case TIME_PARA_GROUP_ADAPTER_MODE:
			if (kstrtoint(tmp_string, POWER_BASE_DEC, &idata))
				goto err_out;
			di->time_para_group[row].adapter_mode = idata;
			break;
		}
	}

	di->group_size = len / para_num;
	di->time_para_parse_ok = true;
	return 0;

err_out:
	kfree(di->time_para_group);
	return -EPERM;
}

static void direct_charge_turbo_parse_dts(struct device_node *np, struct direct_charge_turbo_dev *di)
{
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"time_para_by_adapter_mode", &di->time_para_by_adapter_mode, 0);
	if (direct_charge_turbo_parse_time_para_group(np, di))
		hwlog_err("turbo time_para parse fail\n");
}

static int direct_charge_turbo_probe(struct platform_device *pdev)
{
	struct direct_charge_turbo_dev *l_dev = NULL;
	struct device_node *np = NULL;

	if (!pdev || !pdev->dev.of_node)
		return -ENODEV;

	hwlog_info("%s start\n", __func__);
	l_dev = kzalloc(sizeof(*l_dev), GFP_KERNEL);
	if (!l_dev)
		return -ENOMEM;

	l_dev->dev = &pdev->dev;
	np = l_dev->dev->of_node;

	direct_charge_turbo_parse_dts(np, l_dev);
	direct_charge_turbo_sysfs_create_group(l_dev->dev);
	g_direct_charge_turbo_dev = l_dev;
	platform_set_drvdata(pdev, l_dev);

	hwlog_info("%s ok\n", __func__);
	return 0;
}

static int direct_charge_turbo_remove(struct platform_device *pdev)
{
	struct direct_charge_turbo_dev *l_dev = platform_get_drvdata(pdev);

	if (!l_dev)
		return -ENODEV;

	direct_charge_turbo_sysfs_remove_group(l_dev->dev);
	platform_set_drvdata(pdev, NULL);
	kfree(l_dev->time_para_group);
	kfree(l_dev);
	g_direct_charge_turbo_dev = NULL;
	return 0;
}

static const struct of_device_id direct_charge_turbo_match_table[] = {
	{
		.compatible = "huawei,direct_charge_turbo",
		.data = NULL,
	},
	{},
};

static struct platform_driver direct_charge_turbo_driver = {
	.probe = direct_charge_turbo_probe,
	.remove = direct_charge_turbo_remove,
	.driver = {
		.name = "huawei,direct_charge_turbo",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(direct_charge_turbo_match_table),
	},
};

static int __init direct_charge_turbo_init(void)
{
	return platform_driver_register(&direct_charge_turbo_driver);
}

static void __exit direct_charge_turbo_exit(void)
{
	platform_driver_unregister(&direct_charge_turbo_driver);
}

late_initcall(direct_charge_turbo_init);
module_exit(direct_charge_turbo_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("direct charge turbo driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
