/*
 * shell temp calculation
 *
 * Copyright (c) 2017-2021 Huawei Technologies Co., Ltd.
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

#include "hw_shell_temp.h"

static struct power_supply *g_batt_psy = NULL;
static struct power_supply *g_usb_psy = NULL;
struct hw_thermal_class hw_thermal_info;

static ssize_t
hw_shell_show_temp(struct device *dev, struct device_attribute *devattr,
		char *buf)
{
	struct hw_shell_t *hw_shell = NULL;

	if (dev == NULL || devattr == NULL || buf == NULL)
		return 0;

	if (dev->driver_data == NULL)
		return 0;

	hw_shell = dev->driver_data;

	return snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%d\n",
			  hw_shell->temp);
}

static ssize_t
hw_shell_store_temp(struct device *dev, struct device_attribute *devattr,
			const char *buf, size_t count)
{
	int temp;
	struct platform_device *pdev = NULL;
	struct hw_shell_t *hw_shell = NULL;

	if (dev == NULL || devattr == NULL || buf == NULL)
		return 0;

	if (kstrtoint(buf, DECIMAL, &temp) != 0) {
		pr_err("%s Invalid input para\n", __func__);
		return -EINVAL;
	}

	if (temp < MIN_TEMPERATURE || temp > MAX_TEMPERATURE)
		return -EINVAL;

	pdev = container_of(dev, struct platform_device, dev);
	hw_shell = platform_get_drvdata(pdev);
	if (hw_shell->is_framework < IS_FRAMEWORK) {
		pr_err("%s Cannot input because of non-framework\n", __func__);
		return -EINVAL;
	}

	hw_shell->temp = temp;
	return (ssize_t)count;
}
static DEVICE_ATTR(temp, S_IWUSR | S_IRUGO,
		hw_shell_show_temp, hw_shell_store_temp);

static bool check_batt_psy(void)
{
	if (g_batt_psy)
		return true;

	g_batt_psy = power_supply_get_by_name(PSY_BATTERY_NAME);
	if (!g_batt_psy) {
		pr_err("Failed to get battery power supply");
		return false;
	}
	pr_info("Get battery power supply");
	return true;
}

static bool check_usb_psy(void)
{
	if (g_usb_psy)
		return true;

	g_usb_psy = power_supply_get_by_name(PSY_USB_NAME);
	if (!g_usb_psy) {
		pr_err("Failed to get usb power supply");
		return false;
	}
	pr_info("Get usb power supply");
	return true;
}

static int get_psy_property(struct power_supply *psy, enum power_supply_property psp,
	union power_supply_propval *val)
{
	int ret;

	ret = power_supply_get_property(psy, psp, val);
	if (ret != 0) {
		pr_err("Failed to get power supply property: %d, ret: %d", psp, ret);
		return -1;
	}
	return 0;
}

static int get_batt_int_prop(enum power_supply_property psp, int defval)
{
	int ret;
	union power_supply_propval propval;

	if (!check_batt_psy())
		return defval;

	ret = get_psy_property(g_batt_psy, psp, &propval);
	return (ret == 0) ? propval.intval : defval;
}

static int get_usb_int_prop(enum power_supply_property psp, int defval)
{
	int ret;
	union power_supply_propval propval;

	if (!check_usb_psy())
		return defval;

	ret = get_psy_property(g_usb_psy, psp, &propval);
	return (ret == 0) ? propval.intval : defval;
}

static int get_power_supply_info(int flag, char *buf)
{
	int value = 0;
	switch (flag) {
	case THERMAL_INFO_CHG_ON:
		value = get_usb_int_prop(POWER_SUPPLY_PROP_ONLINE, -1);
		break;
	case THERMAL_INFO_BAT_STAT:
		value = get_batt_int_prop(POWER_SUPPLY_PROP_STATUS, -1);
		if (value == POWER_SUPPLY_STATUS_CHARGING)
			return snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%s\n", CHAGING_STAT);
		return snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%s\n", DISCHAGING_STAT);
	case THERMAL_INFO_IBUS:
		value = get_usb_int_prop(POWER_SUPPLY_PROP_CURRENT_NOW, -1);
		break;
	case THERMAL_INFO_VBUS:
		value = get_usb_int_prop(POWER_SUPPLY_PROP_VOLTAGE_NOW, -1);
		break;
	case THERMAL_INFO_IBAT:
		value = get_batt_int_prop(POWER_SUPPLY_PROP_CURRENT_NOW, -1);
		break;
	case THERMAL_INFO_VBAT:
		value = get_batt_int_prop(POWER_SUPPLY_PROP_VOLTAGE_NOW, -1);
		break;
	case THERMAL_INFO_CAP:
		value = get_batt_int_prop(POWER_SUPPLY_PROP_CAPACITY, -1);
		break;
	default:
		pr_err("Exp node flag err.\n");
		value = 0;
	}
	return value;
}

static int get_other_driver_info(int flag)
{
	int value = 0;
	switch (flag) {
	case THERMAL_INFO_GPU_DDR_CUR:
		break;
	case THERMAL_INFO_GPU_DDR_MAX:
		break;
	default:
		pr_err("Exp node flag err.\n");
		value = 0;
	}
	return value;
}

static ssize_t hw_shell_show_exp_node(struct device *dev, struct device_attribute *devattr, char *buf)
{
	int value = 0;
	struct hw_shell_t *exp_node = NULL;

	if (dev == NULL || devattr == NULL || buf == NULL)
		return 0;

	if (dev->driver_data == NULL)
		return 0;
	exp_node = dev->driver_data;

	pr_info("shell exp node show, flag: %d", exp_node->flag);
	if (exp_node->flag < THERMAL_INFO_GPU_DDR_CUR) {
		value = get_power_supply_info(exp_node->flag, buf);
	} else {
		value = get_other_driver_info(exp_node->flag);
	}

	return snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%d\n", value);
}

static ssize_t
hw_shell_store_exp_node(struct device *dev, struct device_attribute *devattr, const char *buf, size_t count)
{
	return 0;
}

static DEVICE_ATTR(exp_node, S_IWUSR | S_IRUGO, hw_shell_show_exp_node, hw_shell_store_exp_node);

static bool check_register_thermal_zone(struct hw_shell_t *hw_shell)
{
	return (hw_shell->is_framework > IS_FRAMEWORK) ? true : false;
}

#ifdef CONFIG_HW_SHELL_TEMP_DEBUG
static ssize_t
hw_shell_store_debug_temp(struct device *dev, struct device_attribute *devattr,
				const char *buf, size_t count)
{
	int channel, temp;
	struct platform_device *pdev = NULL;
	struct hw_shell_t *hw_shell = NULL;

	if (dev == NULL || devattr == NULL || buf == NULL)
		return 0;

	if (sscanf_s(buf, "%d %d\n", &channel, &temp) != 2) {
		pr_err("%s Invalid input para\n", __func__);
		return -EINVAL;
	}

	pdev = container_of(dev, struct platform_device, dev);
	hw_shell = platform_get_drvdata(pdev);

	hw_shell->channel = channel;
	hw_shell->debug_temp = temp;

	return (ssize_t)count;
}
static DEVICE_ATTR(debug_temp, S_IWUSR, NULL, hw_shell_store_debug_temp);
#endif

static struct attribute *hw_shell_attributes[] = {
	&dev_attr_temp.attr,
#ifdef CONFIG_HW_SHELL_TEMP_DEBUG
	&dev_attr_debug_temp.attr,
#endif
	NULL
};

static struct attribute_group hw_shell_attribute_group = {
	.attrs = hw_shell_attributes,
};

static BLOCKING_NOTIFIER_HEAD(ambient_chain_head);
int register_ambient_notifier(struct notifier_block *nb)
{
	return blocking_notifier_chain_register(&ambient_chain_head, nb);
}
EXPORT_SYMBOL_GPL(register_ambient_notifier);

int unregister_ambient_notifier(struct notifier_block *nb)
{
	return blocking_notifier_chain_unregister(&ambient_chain_head, nb);
}
EXPORT_SYMBOL_GPL(unregister_ambient_notifier);

int ambient_notifier_call_chain(int val)
{
	return blocking_notifier_call_chain(&ambient_chain_head, 0, &val);
}

static ssize_t show_ambient(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	if (dev == NULL || attr == NULL || buf == NULL)
		return 0;

	return snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%d\n",
		(int)hw_thermal_info.temperature_node.ambient);
}

static ssize_t store_ambient(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	int ambient = 0;
	int prev_temp;

	if (dev == NULL || attr == NULL || buf == NULL)
		return 0;

	if (kstrtoint(buf, 10, &ambient))
		return -EINVAL;

	prev_temp = hw_thermal_info.temperature_node.ambient;
	hw_thermal_info.temperature_node.ambient = ambient;
	if (ambient != prev_temp)
		ambient_notifier_call_chain(ambient);

	return (ssize_t)count;
}

static DEVICE_ATTR(ambient, S_IWUSR | S_IRUSR | S_IRGRP | S_IWGRP,
		   show_ambient, store_ambient);

int hw_get_shell_temp(struct thermal_zone_device *thermal, int *temp)
{
	struct hw_shell_t *hw_shell = thermal->devdata;

	if (hw_shell == NULL || temp == NULL)
		return -EINVAL;

	*temp = hw_shell->temp;

	return 0;
}

struct thermal_zone_device_ops shell_thermal_zone_ops = {
	.get_temp = hw_get_shell_temp,
};

static void get_shell_dts_para(struct device_node *dev_node,
	struct hw_shell_t *hw_shell)
{
	int ret;
	ret = of_property_read_s32(dev_node, "shell_temp_step_range",
				   &hw_shell->shell_temp_step_range);
	if (ret != 0) {
		pr_err("%s shell_temp_step_range read err\n", __func__);
		hw_shell->shell_temp_step_range = DEFAULT_SHELL_TEMP_STEP_RANGE;
	}

	ret = of_property_read_s32(dev_node, "shell_temp_step",
				   &hw_shell->shell_temp_step);
	if (ret != 0) {
		pr_err("%s shell_temp_step read err\n", __func__);
		hw_shell->shell_temp_step = DEFAULT_SHELL_TEMP_STEP;
	}

	ret = of_property_read_s32(dev_node, "is_framework", &hw_shell->is_framework);
	if (ret != 0) {
		pr_err("%s is_framework read err\n", __func__);
		hw_shell->is_framework = IS_FRAMEWORK;
	}

	hw_shell->tsensor_temp_step = DEFAULT_TSENS_STEP_RANGE;
	hw_shell->tsensor_max_temp = DEFAULT_TSENS_MAX_TEMP;
	hw_shell->tsensor_min_temp = DEFAULT_TSENS_MIN_TEMP;
	hw_shell->ntc_temp_step = DEFAULT_NTC_STEP_RANGE;
	hw_shell->ntc_max_temp = DEFAULT_NTC_MAX_TEMP;
	hw_shell->ntc_min_temp = DEFAULT_NTC_MIN_TEMP;
	hw_shell->interval = DEFAULT_INTERVAL;
	hw_shell->index = 0;
	hw_shell->valid_flag = 0;
	hw_shell->old_temp = 0;
	hw_shell->sensor_count = 0;
	hw_shell->sample_count = 0;
	hw_shell->is_transfer = 0;
	hw_shell->flag = 0;
	hw_shell->bias = 0;
#ifdef CONFIG_HW_SHELL_TEMP_DEBUG
	hw_shell->channel = 0;
	hw_shell->debug_temp = 0;
#endif
}

static int create_file_node(struct platform_device *pdev, struct attribute_group *attr)
{
	struct device *dev = &pdev->dev;
	struct device_node *dev_node = dev->of_node;
	int ret;
	ret = sysfs_create_link(&hw_thermal_info.temperature_node.device->kobj, &pdev->dev.kobj, dev_node->name);
	if (ret != 0) {
		pr_err("%s: create hw_thermal device file error: %d\n", dev_node->name, ret);
		return -EINVAL;
	}
	ret = sysfs_create_group(&pdev->dev.kobj, attr);
	if (ret != 0) {
		pr_err("%s: create shell file error: %d\n", dev_node->name, ret);
		sysfs_remove_link(&hw_thermal_info.temperature_node.device->kobj, dev_node->name);
		return -EINVAL;
	}
	return 0;
}

static int create_framework_file_node(struct platform_device *pdev)
{
	int ret;
	struct hw_shell_t *hw_shell = NULL;

	hw_shell = platform_get_drvdata(pdev);
	ret = create_file_node(pdev, &hw_shell_attribute_group);
	if (ret == 0)
		pr_err("hw shell framework node create ok!\n");
	return ret;
}

static int create_exp_node(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct device_node *dev_node = dev->of_node;
	int ret;
	ret = sysfs_create_link(&hw_thermal_info.temperature_node.device->kobj, &pdev->dev.kobj, dev_node->name);
	if (ret != 0) {
		pr_err("%s: create hw_thermal device file error: %d\n", dev_node->name, ret);
		return -EINVAL;
	}
	ret = sysfs_create_file(&pdev->dev.kobj, &dev_attr_exp_node.attr);
	if (ret != 0) {
		pr_err("%s: create shell file error: %d\n", dev_node->name, ret);
		sysfs_remove_link(&hw_thermal_info.temperature_node.device->kobj, dev_node->name);
		return -EINVAL;
	}
	return 0;
}

static int handle_exp_node(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct device_node *dev_node = dev->of_node;
	struct hw_shell_t *node_data;
	int ret;
	int flag = 0;

	node_data = kzalloc(sizeof(*node_data), GFP_KERNEL);
	if (node_data == NULL) {
		pr_err("Not enough memory for node_data.\n");
		return -ENODEV;
	}

	ret = of_property_read_s32(dev_node, "node_type", &flag);
	if (ret != 0) {
		pr_err("%s node_type read err.\n", __func__);
		return -ENODEV;
	}
	node_data->is_transfer = IS_TRANSFER;
	node_data->flag = flag;

	platform_set_drvdata(pdev, node_data);
	ret = create_exp_node(pdev);
	return ret;
}

static int handle_shell_node(struct platform_device *pdev, struct device *dev,
	struct device_node *dev_node)
{
	int ret;
	struct hw_shell_t *hw_shell = NULL;
	hw_shell = kzalloc(sizeof(struct hw_shell_t), GFP_KERNEL);
	if (hw_shell == NULL) {
		ret = -ENOMEM;
		pr_err("no enough memory\n");
		return ret;
	}

	get_shell_dts_para(dev_node, hw_shell);

	if (check_register_thermal_zone(hw_shell)) {
		hw_shell->tz_dev
			= thermal_zone_device_register(dev_node->name, 0, 0, hw_shell, &shell_thermal_zone_ops, NULL, 0, 0);
		if (IS_ERR(hw_shell->tz_dev)) {
			dev_err(dev, "register thermal zone for shell failed.\n");
			ret = -ENODEV;
			goto free_mem;
		}
	}

	// TEMPERATURE_DATA_RANGE for shell_cover(eg.)
	if (hw_shell->shell_temp_step_range <= TEMPERATURE_DATA_RANGE) {
		hw_shell->temp = 0;
	} else {
		hw_shell->temp = hw_battery_temperature();
	}
	pr_info("%s: temp %d\n", dev_node->name, hw_shell->temp);

	platform_set_drvdata(pdev, hw_shell);
	ret = create_framework_file_node(pdev);
	if (ret != 0)
		goto cancel_work;
	return 0;

cancel_work:
	if (check_register_thermal_zone(hw_shell))
		thermal_zone_device_unregister(hw_shell->tz_dev);
free_mem:
	kfree(hw_shell);
	return ret;
}

static int hw_shell_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct device_node *dev_node = dev->of_node;
	int ret;
	int is_transfer = 0;

	if (!of_device_is_available(dev_node)) {
		dev_err(dev, "HW shell dev not found\n");
		return -ENODEV;
	}

	ret = of_property_read_s32(dev_node, "is_transfer", &is_transfer);
	if (ret == 0) {
		if (is_transfer == IS_TRANSFER) {
			ret = handle_exp_node(pdev);
			return ret;
		}
	}

	ret = handle_shell_node(pdev, dev, dev_node);
	return ret;
}

static int hw_shell_remove(struct platform_device *pdev)
{
	struct hw_shell_t *hw_shell = platform_get_drvdata(pdev);

	if (hw_shell != NULL) {
		platform_set_drvdata(pdev, NULL);
		if (hw_shell->is_transfer == 0 && check_register_thermal_zone(hw_shell))
			thermal_zone_device_unregister(hw_shell->tz_dev);
		kfree(hw_shell);
	}

	return 0;
}

/*lint -e785*/
static struct of_device_id hw_shell_of_match[] = {
	{ .compatible = "hw,shell-temp" },
	{},
};

/*lint +e785*/
MODULE_DEVICE_TABLE(of, hw_shell_of_match);

int shell_temp_pm_resume(struct platform_device *pdev)
{
	struct hw_shell_t *hw_shell = NULL;

	pr_info("%s+\n", __func__);
	hw_shell = platform_get_drvdata(pdev);
	if (hw_shell != NULL && hw_shell->is_transfer == 0) {
		// TEMPERATURE_DATA_RANGE for shell_cover(eg.)
		if (hw_shell->shell_temp_step_range <= TEMPERATURE_DATA_RANGE) {
			hw_shell->temp = 0;
		} else {
			hw_shell->temp = hw_battery_temperature();
		}
		hw_shell->index = 0;
		hw_shell->valid_flag = 0;
		hw_shell->old_temp = 0;
#ifdef CONFIG_HW_SHELL_TEMP_DEBUG
		hw_shell->channel = 0;
		hw_shell->debug_temp = 0;
#endif
	}
	pr_info("%s-\n", __func__);

	return 0;
}

/*lint -e64 -e785 -esym(64,785,*)*/
static struct platform_driver hw_shell_platdrv = {
	.driver = {
		.name = "hw-shell-temp",
		.owner = THIS_MODULE,
		.of_match_table = hw_shell_of_match,
	},
	.probe = hw_shell_probe,
	.remove = hw_shell_remove,
	.resume = shell_temp_pm_resume,
};

/*lint -e64 -e785 +esym(64,785,*)*/
#ifdef CONFIG_HW_IPA_THERMAL
extern struct class *ipa_get_thermal_class(void);
#endif

static int __init hw_shell_init(void)
{
	int ret;
	struct class *class = NULL;

	/* create huawei thermal class */
#ifdef CONFIG_HW_IPA_THERMAL
	class = ipa_get_thermal_class();
#endif
	if (!class) {
		hw_thermal_info.thermal_class = class_create(THIS_MODULE, "hw_thermal"); /*lint !e64*/
		if (IS_ERR(hw_thermal_info.thermal_class)) {
			pr_err("Huawei thermal class create error\n");
			return PTR_ERR(hw_thermal_info.thermal_class);
		}
	} else {
		hw_thermal_info.thermal_class = class;
	}

	/* create device "temp" */
	hw_thermal_info.temperature_node.device =
		device_create(hw_thermal_info.thermal_class, NULL, 0, NULL, "temp");
	if (IS_ERR(hw_thermal_info.temperature_node.device)) {
		pr_err("hw_thermal:temperature_node device create error\n");
		if (!class)
			class_destroy(hw_thermal_info.thermal_class);
		hw_thermal_info.thermal_class = NULL;
		return PTR_ERR(hw_thermal_info.temperature_node.device);
	}
	/* create an ambient node for thermal-daemon. */
	ret = device_create_file(hw_thermal_info.temperature_node.device,
				 &dev_attr_ambient);
	if (ret != 0) {
		pr_err("hw_thermal:ambient node create error\n");
		device_destroy(hw_thermal_info.thermal_class, 0);
		if (!class)
			class_destroy(hw_thermal_info.thermal_class);
		hw_thermal_info.thermal_class = NULL;
		return ret;
	}

	return platform_driver_register(&hw_shell_platdrv); /*lint !e64*/
}

static void __exit hw_shell_exit(void)
{
	if (hw_thermal_info.thermal_class != NULL) {
		device_destroy(hw_thermal_info.thermal_class, 0);
#ifdef CONFIG_HW_IPA_THERMAL
		if (!ipa_get_thermal_class())
			class_destroy(hw_thermal_info.thermal_class);
#else
		class_destroy(hw_thermal_info.thermal_class);
#endif
	}
	if (g_batt_psy) {
		power_supply_put(g_batt_psy);
		g_batt_psy = NULL;
	}
	if (g_usb_psy) {
		power_supply_put(g_usb_psy);
		g_usb_psy = NULL;
	}
	platform_driver_unregister(&hw_shell_platdrv);
}

/*lint -e528 -esym(528,*)*/
late_initcall(hw_shell_init);
module_exit(hw_shell_exit);
/*lint -e528 +esym(528,*)*/

/*lint -e753 -esym(753,*)*/
MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("thermal shell temp module driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
/*lint -e753 +esym(753,*)*/
