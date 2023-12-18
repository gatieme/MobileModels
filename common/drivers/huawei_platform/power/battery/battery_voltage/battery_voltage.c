/*
 * battery_voltage.c
 *
 * battery voltage interface for power module
 *
 * Copyright (c) 2023-2023 Huawei Technologies Co., Ltd.
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

#include <linux/module.h>
#include <linux/err.h>
#include <linux/string.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/platform_device.h>
#include <linux/of.h>
#include <linux/device.h>
#include <huawei_platform/power/huawei_charger.h>
#include <huawei_platform/log/hw_log.h>
#include <huawei_platform/power/battery_voltage.h>
#include <chipset_common/hwpower/common_module/power_sysfs.h>

#define HWLOG_TAG hw_batt_vol
HWLOG_REGIST();

static struct hw_batt_vol_info *g_hw_batt_di;

int hw_battery_get_series_num(void)
{
	struct hw_batt_vol_info *l_di = g_hw_batt_di;
	if (!l_di)
		return HW_ONE_BAT;

	return l_di->batt_series_num;
}
EXPORT_SYMBOL_GPL(hw_battery_get_series_num);

static int hw_battery_voltage_default()
{
	int val = 0;
	int ret;

	ret = power_supply_get_int_property_value("battery",
		POWER_SUPPLY_PROP_VOLTAGE_NOW, &val);
	if (ret)
		return ret;

	return val / POWER_UV_PER_MV; /* convert uv to mv */
}

static int hw_battery_get_max_voltage(void)
{
	void *dev_data = NULL;
	int vol = 0;
	int max = -1;
	int i;
	struct hw_batt_vol_info *l_di = g_hw_batt_di;

	if (!l_di)
		return hw_battery_voltage_default();

	for (i = 0; i < l_di->total_vol; i++) {
		if (l_di->vol_buff[i].batt_id == BAT_ID_ALL)
			continue;

		if (l_di->vol_buff[i].get_batt_vol &&
			l_di->vol_buff[i].dev_data) {
			dev_data = l_di->vol_buff[i].dev_data;
			vol = l_di->vol_buff[i].get_batt_vol(dev_data);
		} else {
			hwlog_err("vol_buff[%d].get_batt_vol is null\n",
				BAT_ID_MAX);
			return -1;
		}

		if (vol < 0) {
			hwlog_err("get_batt_vol fail, batt_id=%d\n",
				BAT_ID_MAX);
			return -1;
		}

		if (vol > max)
			max = vol;
	}

	hwlog_info("get hw_batt_vol_max[%d]=%dmv\n", BAT_ID_MAX, max);

	return max;
}

static int hw_battery_get_min_voltage(void)
{
	void *dev_data = NULL;
	int vol = 0;
	int min = MAX_VOL_MV;
	int i;
	struct hw_batt_vol_info *l_di = g_hw_batt_di;

	if (!l_di)
		return hw_battery_voltage_default();

	for (i = 0; i < l_di->total_vol; i++) {
		if (l_di->vol_buff[i].batt_id == BAT_ID_ALL)
			continue;

		if (l_di->vol_buff[i].get_batt_vol &&
			l_di->vol_buff[i].dev_data) {
			dev_data = l_di->vol_buff[i].dev_data;
			vol = l_di->vol_buff[i].get_batt_vol(dev_data);
		} else {
			hwlog_err("vol_buff[%d].get_batt_vol is null\n",
				BAT_ID_MIN);
			return -1;
		}

		if (vol < 0) {
			hwlog_err("get_batt_vol fail, batt_id=%d\n",
				BAT_ID_MIN);
			return -1;
		}

		if (vol < min)
			min = vol;
	}

	if (min < MAX_VOL_MV) {
		hwlog_info("get hw_batt_vol_min[%d]=%dmv\n",
			BAT_ID_MIN, min);
		return min;
	} else {
		return -1;
	}
}

int hw_battery_voltage(enum hw_batt_id batt_id)
{
	int i;
	int vol = 0;
	void *dev_data = NULL;
	struct hw_batt_vol_info *l_di = g_hw_batt_di;

	if (!l_di)
		return hw_battery_voltage_default();

	if (l_di->total_vol == HW_BATT_VOL_SINGLE_BATTERY &&
		l_di->vol_buff[0].dev_data) {
		dev_data = l_di->vol_buff[0].dev_data;
		return l_di->vol_buff[0].get_batt_vol(dev_data);
	} else if (l_di->total_vol == 0) {
		hwlog_err("use default battery_voltage\n");
		return hw_battery_voltage_default();
	}

	switch (batt_id) {
	case BAT_ID_0:
	case BAT_ID_1:
	case BAT_ID_ALL:
		for (i = 0; i < l_di->total_vol; i++) {
			if (l_di->vol_buff[i].batt_id != batt_id)
				continue;

			if (l_di->vol_buff[i].get_batt_vol &&
				l_di->vol_buff[i].dev_data) {
				dev_data = l_di->vol_buff[i].dev_data;
				vol = l_di->vol_buff[i].get_batt_vol(dev_data);
			} else {
				hwlog_err("vol_buff[%d].get_batt_vol is null\n",
					batt_id);
				return -1;
			}

			hwlog_info("get hw_batt_vol[%d]=%dmv\n", batt_id, vol);
			return vol;
		}
		break;
	case BAT_ID_MAX:
		return hw_battery_get_max_voltage();
	case BAT_ID_MIN:
		return hw_battery_get_min_voltage();
	default:
		hwlog_err("invalid batt_id:%d\n", batt_id);
		break;
	}

	return -1;
}
EXPORT_SYMBOL_GPL(hw_battery_voltage);

int hw_battery_voltage_ops_register(struct hw_batt_vol_ops *ops,
	char *ops_name)
{
	int i;
	struct hw_batt_vol_info *l_di = g_hw_batt_di;

	if (!l_di || !ops || !ops->dev_data) {
		hwlog_err("l_di or ops is null\n");
		return -EPERM;
	}

	for (i = 0; i < l_di->total_vol; i++) {
		if (!strncmp(ops_name, l_di->vol_buff[i].ops_name,
			strlen(l_di->vol_buff[i].ops_name))) {
			l_di->vol_buff[i].get_batt_vol =
				ops->get_batt_vol;
			l_di->vol_buff[i].dev_data = ops->dev_data;
			break;
		}
	}

	if (i >= l_di->total_vol) {
		hwlog_err("%s ops register fail\n", ops_name);
		return -EPERM;
	}

	hwlog_info("%s ops register ok\n", ops_name);
	return 0;
}
EXPORT_SYMBOL_GPL(hw_battery_voltage_ops_register);

#ifdef CONFIG_SYSFS
static ssize_t hw_batt_vol_sysfs_show(struct device *dev,
	struct device_attribute *attr, char *buf);

static struct power_sysfs_attr_info hw_batt_vol_sysfs_field_tbl[] = {
	power_sysfs_attr_ro(hw_batt_vol, 0440, HW_BATT_VOL_SYSFS_BAT_ID_0, bat_id_0),
	power_sysfs_attr_ro(hw_batt_vol, 0440, HW_BATT_VOL_SYSFS_BAT_ID_1, bat_id_1),
	power_sysfs_attr_ro(hw_batt_vol, 0440, HW_BATT_VOL_SYSFS_BAT_ID_ALL, bat_id_all),
	power_sysfs_attr_ro(hw_batt_vol, 0440, HW_BATT_VOL_SYSFS_BAT_ID_MAX, bat_id_max),
	power_sysfs_attr_ro(hw_batt_vol, 0440, HW_BATT_VOL_SYSFS_BAT_ID_MIN, bat_id_min),
};

#define HW_BATT_VOL_SYSFS_ATTRS_SIZE  ARRAY_SIZE(hw_batt_vol_sysfs_field_tbl)

static struct attribute *hw_batt_vol_sysfs_attrs[HW_BATT_VOL_SYSFS_ATTRS_SIZE + 1];

static const struct attribute_group hw_batt_vol_sysfs_attr_group = {
	.attrs = hw_batt_vol_sysfs_attrs,
};

static ssize_t hw_batt_vol_sysfs_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct power_sysfs_attr_info *info = NULL;
	int len = 0;

	info = power_sysfs_lookup_attr(attr->attr.name,
		hw_batt_vol_sysfs_field_tbl, HW_BATT_VOL_SYSFS_ATTRS_SIZE);
	if (!info)
		return -EINVAL;

	len = snprintf(buf, PAGE_SIZE, "%d\n", hw_battery_voltage(info->name));

	return len;
}

static void hw_batt_vol_sysfs_create_group(struct device *dev)
{
	power_sysfs_init_attrs(hw_batt_vol_sysfs_attrs,
		hw_batt_vol_sysfs_field_tbl, HW_BATT_VOL_SYSFS_ATTRS_SIZE);
	power_sysfs_create_link_group("hw_power", "charger", "hw_batt_vol",
		dev, &hw_batt_vol_sysfs_attr_group);
}

static void hw_batt_vol_sysfs_remove_group(struct device *dev)
{
	power_sysfs_remove_link_group("hw_power", "charger", "hw_batt_vol",
		dev, &hw_batt_vol_sysfs_attr_group);
}
#else
static inline void hw_batt_vol_sysfs_create_group(struct device *dev)
{
}

static inline void hw_batt_vol_sysfs_remove_group(struct device *dev)
{
}
#endif /* CONFIG_SYSFS */

static int hw_batt_vol_parse_dts(struct device_node *np,
	struct hw_batt_vol_info *di)
{
	int i = 0;
	const char *ops_name = NULL;
	struct device_node *child_node = NULL;

	di->total_vol = of_get_child_count(np);
	if (di->total_vol <= 0) {
		hwlog_err("total_vol dts read failed\n");
		return -EINVAL;
	}

	for_each_child_of_node(np, child_node) {
		if (power_dts_read_u32(power_dts_tag(HWLOG_TAG),
			child_node, "batt_id", &di->vol_buff[i].batt_id, 0))
			return -EINVAL;

		if (power_dts_read_string(power_dts_tag(HWLOG_TAG),
			child_node, "ops_name", &ops_name))
			return -EINVAL;

		strncpy(di->vol_buff[i].ops_name, ops_name,
			(HW_BATT_VOL_STR_MAX_LEM - 1));

		i++;
	}

	for (i = 0; i < di->total_vol; i++)
		hwlog_info("para[%d]: ops_name:%s, batt_id:%d\n",
			i, di->vol_buff[i].ops_name, di->vol_buff[i].batt_id);

	return 0;
}

static int hw_batt_vol_probe(struct platform_device *pdev)
{
	struct hw_batt_vol_info *di = NULL;
	struct device_node *np = NULL;
	struct device_node *dev_node = NULL;
	int ret = -1;

	if (!pdev || !pdev->dev.of_node)
		return -ENODEV;

	di = devm_kzalloc(&pdev->dev, sizeof(*di), GFP_KERNEL);
	if (!di)
		return -ENOMEM;

	g_hw_batt_di = di;
	di->pdev = pdev;
	di->dev = &pdev->dev;
	np = pdev->dev.of_node;

	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"batt_series_num", &di->batt_series_num, 1);

	dev_node = of_find_node_by_name(np, "batt_vol");
	if (!dev_node) {
		hwlog_err("batt_vol dts read failed\n");
		goto fail_free_mem;
	}

	ret = hw_batt_vol_parse_dts(dev_node, di);
	if (ret)
		goto fail_parse_dts;

	hw_batt_vol_sysfs_create_group(di->dev);
	platform_set_drvdata(pdev, di);

	return 0;

fail_parse_dts:
	of_node_put(dev_node);
fail_free_mem:
	devm_kfree(&pdev->dev, di);
	g_hw_batt_di = NULL;

	return ret;
}

static int hw_batt_vol_remove(struct platform_device *pdev)
{
	struct hw_batt_vol_info *info = platform_get_drvdata(pdev);

	if (!info)
		return -ENODEV;

	hw_batt_vol_sysfs_remove_group(info->dev);
	platform_set_drvdata(pdev, NULL);
	devm_kfree(&pdev->dev, info);
	g_hw_batt_di = NULL;

	return 0;
}

static const struct of_device_id hw_batt_vol_match_table[] = {
	{
		.compatible = "huawei,battery_voltage",
		.data = NULL,
	},
	{},
};

static struct platform_driver hw_batt_vol_driver = {
	.probe = hw_batt_vol_probe,
	.remove = hw_batt_vol_remove,
	.driver = {
		.name = "huawei,battery_voltage",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(hw_batt_vol_match_table),
	},
};

static int __init hw_batt_vol_init(void)
{
	return platform_driver_register(&hw_batt_vol_driver);
}

static void __exit hw_batt_vol_exit(void)
{
	platform_driver_unregister(&hw_batt_vol_driver);
}

fs_initcall(hw_batt_vol_init);
module_exit(hw_batt_vol_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("huawei battery voltage module driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
