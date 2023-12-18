// SPDX-License-Identifier: GPL-2.0
/*
 * buck_boost.c
 *
 * buck_boost driver
 *
 * Copyright (c) 2020-2020 Huawei Technologies Co., Ltd.
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

#include <chipset_common/hwpower/hardware_ic/buck_boost.h>
#include <chipset_common/hwpower/common_module/power_algorithm.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/common_module/power_gpio.h>
#include <chipset_common/hwpower/common_module/power_dts.h>

#define HWLOG_TAG buck_boost
HWLOG_REGIST();

enum buck_boost_vout_vote_type {
	VOUT_VOTE_TYPE_BEGIN = 0,
	VOUT_VOTE_SET_MAX = VOUT_VOTE_TYPE_BEGIN,
	VOUT_VOTE_SET_MIN,
	VOUT_VOTE_TYPE_END,
};

static struct buck_boost_dev *g_buck_boost_di;

static const struct buck_boost_device_data g_buck_boost_device_data[] = {
	{ BBST_DEVICE_ID_TPS63810_MAIN, "tps63810" },
	{ BBST_DEVICE_ID_TPS63810_AUX, "tps63810_aux" },
	{ BBST_DEVICE_ID_MAX77813_MAIN, "max77813" },
	{ BBST_DEVICE_ID_BBST_GPIO, "bbst_gpio" },
};

static const struct buck_boost_device_data g_buck_boost_user_data[] = {
	{ BBST_USER_LPM, "low_power" },
	{ BBST_USER_CAMERA, "camera" },
	{ BBST_USER_BOOST_5V, "boost_5v" },
	{ BBST_USER_BOOST_RSMC, "rsmc" },
	{ BBST_USER_BOOST_HW_SATE, "hw_sate" },
};

static int buck_boost_get_device_id(const char *str)
{
	unsigned int i;

	for (i = 0; i < ARRAY_SIZE(g_buck_boost_device_data); i++) {
		if (!strncmp(str, g_buck_boost_device_data[i].name,
			strlen(str)) && !g_buck_boost_di->t_ops[i])
			return g_buck_boost_device_data[i].id;
	}

	return -EINVAL;
}

static int buck_boost_get_ops_id(unsigned int type)
{
	int i;
	struct buck_boost_ops *ops = NULL;

	for (i = 0; i < BBST_DEVICE_ID_END; i++) {
		ops = g_buck_boost_di->t_ops[i];
		if (!ops || !(ops->bbst_type & type))
			continue;
		break;
	}
	if (i >= BBST_DEVICE_ID_END)
		return -EPERM;

	return i;
}

static struct buck_boost_ops *buck_boost_get_ops(unsigned int type)
{
	int id;

	if (!g_buck_boost_di) {
		hwlog_err("g_buck_boost_di is null\n");
		return NULL;
	}
	if (g_buck_boost_di->ops && (g_buck_boost_di->ops->bbst_type & type))
		return g_buck_boost_di->ops;

	if (g_buck_boost_di->retry_cnt >= BBST_GET_OPS_RETRY_CNT) {
		hwlog_err("retry too many times\n");
		return NULL;
	}

	id = buck_boost_get_ops_id(type);
	if (id < 0) {
		g_buck_boost_di->retry_cnt++;
		return NULL;
	}

	g_buck_boost_di->retry_cnt = 0;
	g_buck_boost_di->ops = g_buck_boost_di->t_ops[id];
	return g_buck_boost_di->ops;
}

int buck_boost_ops_register(struct buck_boost_ops *ops)
{
	int dev_id;

	if (!g_buck_boost_di || !ops || !ops->bbst_name) {
		hwlog_err("g_buck_boost_di or ops or chip_name is null\n");
		return -EPERM;
	}

	dev_id = buck_boost_get_device_id(ops->bbst_name);
	if (dev_id < 0) {
		hwlog_err("%s ops register fail\n", ops->bbst_name);
		return -EINVAL;
	}

	g_buck_boost_di->t_ops[dev_id] = ops;
	hwlog_info("%d:%s ops register ok\n", dev_id, ops->bbst_name);
	return 0;
}

static int buck_boost_gpio_set_vout(unsigned int vout, void *dev_data)
{
	struct buck_boost_dev *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -ENODEV;
	}

	if (!di->vout_set_by_gpio[BBST_VOUT_SET_BY_GPIO_EN]) {
		hwlog_info("bbst_gpio_set_vout is ok\n");
		return 0;
	}

	if (vout > di->vout_set_by_gpio[BBST_VOUT_SET_VOL_TH])
		gpio_set_value(di->vout_set_by_gpio[BBST_VOUT_SET_GPIO_NUM],
			!di->vout_set_by_gpio[BBST_VOUT_SET_GPIO_VAL]);
	else
		gpio_set_value(di->vout_set_by_gpio[BBST_VOUT_SET_GPIO_NUM],
			di->vout_set_by_gpio[BBST_VOUT_SET_GPIO_VAL]);

	hwlog_info("set vout=%u, vth=%u, gpio_val=%d", vout,
		di->vout_set_by_gpio[BBST_VOUT_SET_VOL_TH],
		gpio_get_value(di->vout_set_by_gpio[BBST_VOUT_SET_GPIO_NUM]));
	return 0;
}

static bool buck_boost_gpio_power_good(void *dev_data)
{
	struct buck_boost_dev *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return false;
	}

	hwlog_info("bbst_gpio_power_good is ok\n");
	return true;
}

static bool buck_boost_gpio_set_enable(unsigned int value, void *dev_data)
{
	int gpio_val;
	struct buck_boost_dev *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return false;
	}

	if (!gpio_is_valid(di->bbst_gpio_en))
		return false;

	gpio_set_value(di->bbst_gpio_en, value);
	gpio_val = gpio_get_value(di->bbst_gpio_en);
	if ((int)value != gpio_val) {
		hwlog_err("set bbst_gpio_enable gpio fail\n");
		return false;
	}

	hwlog_info("bbst_gpio_enable gpio %s now\n", gpio_val ? "high" : "low");
	return true;
}

static struct buck_boost_ops buck_boost_gpio_ops = {
	.bbst_type = BBST_TYPE_MAIN,
	.bbst_name = "bbst_gpio",
	.pwr_good = buck_boost_gpio_power_good,
	.set_vout = buck_boost_gpio_set_vout,
	.set_enable = buck_boost_gpio_set_enable,
};

int buck_boost_set_pwm_enable(unsigned int enable, unsigned int type)
{
	struct buck_boost_ops *l_ops = buck_boost_get_ops(type);

	if (!l_ops)
		return -EPERM;

	if (!l_ops->set_pwm_enable) {
		hwlog_err("set_pwm_enable is null\n");
		return -EPERM;
	}

	return l_ops->set_pwm_enable(enable, l_ops->dev_data);
}

int buck_boost_set_vout(unsigned int vol, unsigned int user)
{
	int i;
	unsigned int temp_vol = 0;
	struct buck_boost_ops *l_ops = buck_boost_get_ops(BBST_TYPE_MAIN);
	struct buck_boost_dev *di = g_buck_boost_di;

	if (!di || !l_ops || (user < BBST_USER_BEGIN) || (user >= BBST_USER_END) ||
		(di->vout_vote_type >= VOUT_VOTE_TYPE_END))
		return -EPERM;

	if (!l_ops->set_vout) {
		hwlog_err("set_vout is null\n");
		return -EPERM;
	}

	hwlog_info("%s vol=%u, user=%u\n", __func__, vol, user);
	di->user_vol[user] = vol;
	for (i = 0; i < BBST_USER_END; i++) {
		if (!test_bit(i, &di->user))
			continue;
		if (di->vout_vote_type == VOUT_VOTE_SET_MIN)
			temp_vol = (unsigned int)power_min_positive(temp_vol, di->user_vol[i]);
		else
			temp_vol = (temp_vol > di->user_vol[i]) ?
				temp_vol : di->user_vol[i];
	}

	hwlog_info("buck_boost set vol = %u\n", temp_vol);
	return l_ops->set_vout(temp_vol, l_ops->dev_data);
}
EXPORT_SYMBOL(buck_boost_set_vout);

bool buck_boost_pwr_good(unsigned int type)
{
	struct buck_boost_ops *l_ops = buck_boost_get_ops(type);

	if (!l_ops)
		return false;

	if (!l_ops->pwr_good) {
		hwlog_err("pwr_good is null\n");
		return false;
	}

	return l_ops->pwr_good(l_ops->dev_data);
}

bool buck_boost_set_enable(unsigned int enable, unsigned int user)
{
	struct buck_boost_ops *l_ops = buck_boost_get_ops(BBST_TYPE_MAIN);
	struct buck_boost_dev *di = g_buck_boost_di;

	if (!di || !l_ops || (user < BBST_USER_BEGIN) || (user >= BBST_USER_END))
		return false;

	if (!l_ops->set_enable) {
		hwlog_err("set_enable is null\n");
		return false;
	}

	if (enable) {
		set_bit(user, &di->user);
		hwlog_info("user:%s open\n", g_buck_boost_user_data[user].name);
		return l_ops->set_enable(enable, l_ops->dev_data);
	} else {
		clear_bit(user, &di->user);
		buck_boost_set_vout(0, user);
		hwlog_info("user:%s close\n", g_buck_boost_user_data[user].name);
		if (di->user == BBST_NO_USER) {
			hwlog_info("buck_boost close\n");
			return l_ops->set_enable(enable, l_ops->dev_data);
		}
	}

	return true;
}
EXPORT_SYMBOL(buck_boost_set_enable);

static void buck_boost_parse_vout_set_by_gpio(struct device_node *np,
	struct buck_boost_dev *di)
{
	int ret;

	ret = power_dts_read_u32_array(power_dts_tag(HWLOG_TAG), np,
		"vout_set_by_gpio", di->vout_set_by_gpio,
		BBST_VOUT_SET_BY_GPIO_END);
	if (ret) {
		hwlog_info("vout_set_by_gpio parse failed\n");
		return;
	}

	if (!di->vout_set_by_gpio[BBST_VOUT_SET_BY_GPIO_EN])
		return;

	ret = power_gpio_config_output(np, "bbst_vout_gpio", "bbst_vout_gpio",
		&di->vout_set_by_gpio[BBST_VOUT_SET_GPIO_NUM],
		di->vout_set_by_gpio[BBST_VOUT_SET_GPIO_VAL]);
	if (ret) {
		hwlog_err("bbst_vout_gpio init failed\n");
		di->vout_set_by_gpio[BBST_VOUT_SET_BY_GPIO_EN] = 0;
		return;
	}

	hwlog_info("%s en=%u gpio_num=%u vol_th=%u gpio_val=%u\n", __func__,
		di->vout_set_by_gpio[BBST_VOUT_SET_BY_GPIO_EN],
		di->vout_set_by_gpio[BBST_VOUT_SET_GPIO_NUM],
		di->vout_set_by_gpio[BBST_VOUT_SET_VOL_TH],
		di->vout_set_by_gpio[BBST_VOUT_SET_GPIO_VAL]);
}

static void buck_boost_dts_parse(struct buck_boost_dev *di)
{
	struct device_node *np = NULL;

	if (!di || !di->dev || !di->dev->of_node) {
		hwlog_err("di is null\n");
		return;
	}

	np = di->dev->of_node;
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"boost_use_gpio", &di->boost_use_gpio, 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"vout_vote_type", &di->vout_vote_type, VOUT_VOTE_SET_MAX);
	buck_boost_parse_vout_set_by_gpio(np, di);
}

static int buck_boost_gpio_init(struct buck_boost_dev *di)
{
	int ret;
	struct device_node *np = NULL;

	if (!di || !di->dev || !di->dev->of_node) {
		hwlog_err("di is null\n");
		return -ENODEV;
	}

	np = di->dev->of_node;
	ret = power_gpio_config_output(np, "bbst_gpio_en",
		"bbst_gpio_en", &di->bbst_gpio_en, 0);
	if (ret) {
		hwlog_err("bbst_gpio_en init fail\n");
		return ret;
	}

	return 0;
}

static int buck_boost_gpio_ops_register(struct buck_boost_dev *di)
{
	int ret;

	buck_boost_gpio_ops.dev_data = (void *)di;
	ret = buck_boost_ops_register(&buck_boost_gpio_ops);
	if (ret) {
		hwlog_err("buck_boost_gpio_ops register fail\n");
		return ret;
	}

	return 0;
}

static int buck_boost_gpio_check(struct buck_boost_dev *di)
{
	int ret;

	ret = buck_boost_gpio_init(di);
	if (ret)
		return ret;

	ret = buck_boost_gpio_ops_register(di);
	if (ret)
		return ret;

	return 0;
}

static int buck_boost_probe(struct platform_device *pdev)
{
	int ret;
	struct buck_boost_dev *di = NULL;

	if (!pdev || !pdev->dev.of_node)
		return -ENODEV;

	di = devm_kzalloc(&pdev->dev, sizeof(*di), GFP_KERNEL);
	if (!di)
		return -ENOMEM;

	g_buck_boost_di = di;
	di->dev = &pdev->dev;
	buck_boost_dts_parse(di);
	if (di->boost_use_gpio) {
		ret = buck_boost_gpio_check(di);
		if (ret) {
			hwlog_err("buck boost gpio check fail\n");
			devm_kfree(&pdev->dev, di);
			g_buck_boost_di = NULL;
			return ret;
		}
	}

	platform_set_drvdata(pdev, di);
	return 0;
}

static int buck_boost_remove(struct platform_device *pdev)
{
	struct buck_boost_dev *di = platform_get_drvdata(pdev);

	if (!di)
		return -ENODEV;

	platform_set_drvdata(pdev, NULL);
	g_buck_boost_di = NULL;
	return 0;
}

static const struct of_device_id buck_boost_match_table[] = {
	{
		.compatible = "huawei, buck_boost",
		.data = NULL,
	},
	{},
};

static struct platform_driver buck_boost_driver = {
	.probe = buck_boost_probe,
	.remove = buck_boost_remove,
	.driver = {
		.name = "huawei, buck_boost",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(buck_boost_match_table),
	},
};

static int __init buck_boost_init(void)
{
	return platform_driver_register(&buck_boost_driver);
}

static void __exit buck_boost_exit(void)
{
	platform_driver_unregister(&buck_boost_driver);
}

fs_initcall_sync(buck_boost_init);
module_exit(buck_boost_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("buck_boost module driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
