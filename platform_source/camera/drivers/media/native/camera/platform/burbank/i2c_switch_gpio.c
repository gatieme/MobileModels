#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/pinctrl/consumer.h>
#include <linux/printk.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/dev_printk.h>
#include <linux/slab.h>
#include <i2c_switch_gpio.h>

#define GROUP_PINCTRL_NUM 3

static i2c_switch_gpio_board_info_t *board_info = NULL;

int32_t i2c_switch_gpio_pinctrl_set(int32_t i2c_index, int32_t gpio_group_index, bool on_off)
{
	int32_t ret = 0;
	if (i2c_index >= I2C_INDEX_MAX || gpio_group_index >= I2C_GPIO_GROUP_NUM ||
		board_info == NULL || board_info->pctrl == NULL ||
		board_info->pinctrl_idle_i2c[i2c_index] == NULL ||
		board_info->pinctrl_def_i2c_group[i2c_index][gpio_group_index] == NULL) {
		dev_err(board_info->dev, "%s dose not need set pctrl i2c_index:%d gpio_group_index:%d.\n",
			__func__, i2c_index, gpio_group_index);
		return -EINVAL;
	}
	if (on_off) {
		ret = pinctrl_select_state(board_info->pctrl,
			board_info->pinctrl_def_i2c_group[i2c_index][gpio_group_index]);
		if (ret)
			dev_err(board_info->dev, "%s pinctrl_def_i2c_group[%d][%d] set fail.\n", __func__, i2c_index, gpio_group_index);
	} else {
		ret = pinctrl_select_state(board_info->pctrl, board_info->pinctrl_idle_i2c[i2c_index]);
		if (ret)
			dev_err(board_info->dev, "%s pinctrl_idle_i2c[%d] set fail.\n", __func__, i2c_index);
	}
	return ret;
}
EXPORT_SYMBOL_GPL(i2c_switch_gpio_pinctrl_set);

static int32_t get_pinctrl_dt_data(i2c_switch_gpio_board_info_t *bd_info,
	int32_t i2c_count, int32_t *i2c_indexs, const char *pinctrl_name[])
{
	int32_t i = 0;
	int32_t ret = 0;
	int32_t i2c_index  = 0;

	for (i = 0; i < i2c_count; i += GROUP_PINCTRL_NUM) {
		i2c_index = i / GROUP_PINCTRL_NUM; // one i2c have three pinctrl, group0,group1,idle

		bd_info->pinctrl_def_i2c_group[i2c_indexs[i2c_index]][0] =
			pinctrl_lookup_state(bd_info->pctrl, pinctrl_name[i]); // get group0 pinctrl
		if (IS_ERR_OR_NULL(bd_info->pinctrl_def_i2c_group[i2c_indexs[i2c_index]][0])) {
			dev_err(bd_info->dev, "Failed to init bd_info pinctrl_def_i2c_group[%d][0]\n", i2c_indexs[i2c_index]);
			ret = -EFAULT;
		}

		bd_info->pinctrl_def_i2c_group[i2c_indexs[i2c_index]][1] =
			pinctrl_lookup_state(bd_info->pctrl, pinctrl_name[i + 1]); // get group1 pinctrl
		if (IS_ERR_OR_NULL(bd_info->pinctrl_def_i2c_group[i2c_indexs[i2c_index]][1])) {
			dev_err(bd_info->dev, "Failed to init bd_info pinctrl_def_i2c_group[%d][1]\n", i2c_indexs[i2c_index]);
			ret = -EFAULT;
		}

		bd_info->pinctrl_idle_i2c[i2c_indexs[i2c_index]] =
			pinctrl_lookup_state(bd_info->pctrl, pinctrl_name[i + 2]); // get idle pinctrl
		if (IS_ERR_OR_NULL(bd_info->pinctrl_idle_i2c[i2c_indexs[i2c_index]])) {
			dev_err(bd_info->dev, "Failed to init bd_info pinctrl_idle_i2c[%d]\n", i2c_indexs[i2c_index]);
			ret = -EFAULT;
		}
	}
	return ret;
}

static int32_t i2c_switch_gpio_get_dt_data(struct platform_device *pdev, i2c_switch_gpio_board_info_t *bd_info)
{
	int32_t ret = 0;
	int32_t *i2c_indexs = NULL;
	int32_t count = 0;
	struct device_node *dev_node = NULL;
	const char *pinctrl_name[I2C_INDEX_MAX] = {};
	int32_t i2c_count = 0;

	if (bd_info->pctrl != NULL) {
		dev_err(bd_info->dev, "%s pctrl had got", __func__);
		return -EINVAL;
	}

	bd_info->pctrl = devm_pinctrl_get(&pdev->dev);
	if (IS_ERR_OR_NULL(bd_info->pctrl)) {
		dev_err(bd_info->dev, "Failed to get pctrl\n");
		return -EFAULT;
	}

	dev_node = pdev->dev.of_node;
	if (dev_node == NULL) {
		dev_err(bd_info->dev, "%s dev_node is NULL", __func__);
		return -EINVAL;
	}

	count = of_property_count_strings(dev_node, "pinctrl-names");
	if (count <= 0) {
		dev_err(bd_info->dev, "%s:%d pinctrl-names have not set, count:%d", __func__, __LINE__, count);
		return -EFAULT;
	}

	// count / GROUP_PINCTRL_NUM is count of i2c need to switch gpio
	i2c_count = count / GROUP_PINCTRL_NUM;

	i2c_indexs = kzalloc(sizeof(int32_t) * i2c_count, GFP_KERNEL);
	if (!i2c_indexs) {
		dev_err(bd_info->dev, "%s failed %d", __func__, __LINE__);
		return -ENOMEM;
	}

	ret = of_property_read_u32_array(dev_node, "huawei,i2c_index", i2c_indexs, i2c_count);
	if (ret < 0) {
		dev_err(bd_info->dev, "%s:%d i2c index not to config count:%d", __func__, __LINE__, count);
		goto I2C_INDEX_FREE;
	}

	ret = of_property_read_string_array(dev_node, "pinctrl-names", pinctrl_name, count);
	if (ret != count) {
		dev_err(bd_info->dev, "Failed to parse pinctrl-names!\n");
		ret = -EFAULT;
		goto I2C_INDEX_FREE;
	}

	ret = get_pinctrl_dt_data(bd_info, count, i2c_indexs, pinctrl_name);
	if (ret) {
		dev_err(bd_info->dev, "%s:%d get pinctrl dt data fail", __func__, __LINE__);
		goto I2C_INDEX_FREE;
	}

I2C_INDEX_FREE:
	if (i2c_indexs != NULL) {
		kfree(i2c_indexs);
		i2c_indexs = NULL;
	}

	return ret;
}

static int32_t i2c_switch_gpio_platform_probe(struct platform_device *pdev)
{
	int32_t rc = 0;

	if (pdev == NULL)
		return -EINVAL;

	dev_info(&pdev->dev, "%s enter", __func__);

	board_info = kzalloc(sizeof(i2c_switch_gpio_board_info_t), GFP_KERNEL);
	if (!board_info)
		return -ENOMEM;

	rc = i2c_switch_gpio_get_dt_data(pdev, board_info);
	if (rc < 0) {
		dev_err(board_info->dev, "%s:%d no dt data rc %d", __func__, __LINE__, rc);
		rc = -ENODEV;
		goto BOARD_INFO_FREE;
	}
	board_info->dev = &pdev->dev;

	return rc;

BOARD_INFO_FREE:

	if (board_info != NULL) {
		kfree(board_info);
		board_info = NULL;
	}

	return rc;
}

static int32_t i2c_switch_gpio_platform_remove(struct platform_device *pdev)
{
	if (pdev == NULL) {
		dev_err(board_info->dev, "%s:%d pdev is null\n", __func__, __LINE__);
		return -EINVAL;
	}

	if (board_info != NULL) {
		kfree(board_info);
		board_info = NULL;
	}
	return 0;
}

static const struct of_device_id i2c_switch_gpio_dt_match[] = {
	{
		.compatible = "huawei,i2c_switch_gpio",
	},
	{
	},
};

MODULE_DEVICE_TABLE(of, i2c_switch_gpio_dt_match);

static struct platform_driver i2c_switch_gpio_platform_driver = {
	.driver = {
		.name           = "huawei,i2c_switch_gpio",
		.owner          = THIS_MODULE,
		.of_match_table = i2c_switch_gpio_dt_match,
	},

	.probe = i2c_switch_gpio_platform_probe,
	.remove = i2c_switch_gpio_platform_remove,
};

static int __init i2c_switch_gpio_init_module(void)
{
	return platform_driver_register(&i2c_switch_gpio_platform_driver);
}

static void __exit i2c_switch_gpio_exit_module(void)
{
	platform_driver_unregister(&i2c_switch_gpio_platform_driver);
}

module_init(i2c_switch_gpio_init_module);
module_exit(i2c_switch_gpio_exit_module);
MODULE_DESCRIPTION("i2c_switch_gpio");
MODULE_LICENSE("GPL v2");
