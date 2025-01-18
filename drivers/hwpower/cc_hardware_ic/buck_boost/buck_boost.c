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

#include <securec.h>
#include <chipset_common/hwpower/hardware_ic/buck_boost.h>
#include <chipset_common/hwpower/common_module/power_algorithm.h>
#include <chipset_common/hwpower/common_module/power_debug.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/common_module/power_gpio.h>
#include <chipset_common/hwpower/common_module/power_dts.h>
#include <chipset_common/hwpower/common_module/power_vote.h>

#define HWLOG_TAG buck_boost
HWLOG_REGIST();

#define BBST_MODE_VOTE_PREFIX    "bbst_mode_object"
#define BBST_VOUT_VOTE_PREFIX    "bbst_vout_object"

#define BBST_MONITOR_INTERVAL_DEFAULT      10000
#define BBST_MONITOR_WORK_RESUME_DELAY     1000

enum buck_boost_vout_vote_type {
	VOUT_VOTE_TYPE_BEGIN = 0,
	VOUT_VOTE_SET_MAX = VOUT_VOTE_TYPE_BEGIN,
	VOUT_VOTE_SET_MIN,
	VOUT_VOTE_TYPE_END,
};

static struct buck_boost_dev *g_buck_boost_di;

static const char * g_buck_boost_user_data[] = {
	[BBST_USER_LPM]  = "low_power",
	[BBST_USER_CAMERA]  = "camera",
	[BBST_USER_BOOST_5V]  = "boost_5v",
	[BBST_USER_BOOST_RSMC]  = "rsmc",
	[BBST_USER_BOOST_HW_SATE]  = "hw_sate",
	[BBST_USER_BOOST_HX]  = "hx",
	[BBST_USER_BOOST_DISCHG] = "dischg_boost",
	[BBST_USER_BOOST_FAC]  = "factory",
};

static struct buck_boost_context *buck_boost_get_context(unsigned int index)
{
	if (!g_buck_boost_di || !g_buck_boost_di->bbst_context ||
		index >= g_buck_boost_di->path_num) {
		hwlog_err("fail to get bbst context\n");
		return NULL;
	}

	return &g_buck_boost_di->bbst_context[index];
}

int buck_boost_ops_register(struct buck_boost_ops *ops)
{
	struct buck_boost_context *context = NULL;

	if (!ops) {
		hwlog_err("ops is null\n");
		return -EPERM;
	}

	context = buck_boost_get_context(ops->index);
	if (!context || context->ops) {
		hwlog_err("context is null or bbst ops conflict\n");
		return -EINVAL;
	}

	context->ops = ops;
	hwlog_info("ops for path %u register ok\n", ops->index);

	if (context->need_init_vout && ops->set_vout) {
		if (ops->set_vout(context->const_vout, ops->dev_data))
			hwlog_err("fail to init vout for path %u\n", ops->index);
	}

	return 0;
}

static int buck_boost_gpio_set_vout(unsigned int vout, void *dev_data)
{
	int i;
	unsigned int value;
	struct buck_boost_dev *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -ENODEV;
	}

	if (!di->bbst_gpio_vout || !di->vout_table || (di->gpio_vout_num <= 0) ||
		(di->vout_table_size <= 0)) {
		hwlog_info("bbst_gpio_set_vout is ok\n");
		return 0;
	}

	for (i = 0; i < di->vout_table_size; i++) {
		if (vout <= di->vout_table[i].output_voltage) {
			value = di->vout_table[i].gpio_value;
			break;
		}
	}
	if (i >= di->vout_table_size)
		value = di->vout_table[di->vout_table_size - 1].gpio_value;

	for (i = 0; i < di->gpio_vout_num; i++) {
		gpio_set_value(di->bbst_gpio_vout[i], (value & BIT(i)) >> i);
		hwlog_info("set gpio_%d output %u, gpio_val=%d\n", di->bbst_gpio_vout[i],
			(value & BIT(i)) >> i, gpio_get_value(di->bbst_gpio_vout[i]));
	}
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
	.index = BBST_INDEX_DEFAULT,
	.pwr_good = buck_boost_gpio_power_good,
	.set_vout = buck_boost_gpio_set_vout,
	.set_enable = buck_boost_gpio_set_enable,
};

int buck_boost_set_pwm_enable(unsigned int enable, unsigned int index)
{
	struct buck_boost_context *context = buck_boost_get_context(index);
	struct buck_boost_ops *l_ops = NULL;

	if (!context)
		return -EPERM;

	l_ops = context->ops;
	if (!l_ops || !l_ops->set_pwm_enable) {
		hwlog_err("ops or set_pwm_enable is null\n");
		return -EPERM;
	}

	return l_ops->set_pwm_enable(enable, l_ops->dev_data);
}

int buck_boost_set_vout(unsigned int vol, unsigned int user)
{
	return buckboost_set_vout(vol, user, BBST_INDEX_DEFAULT);
}
EXPORT_SYMBOL(buck_boost_set_vout);

int buckboost_set_vout(unsigned int vol, unsigned int user, unsigned int index)
{
	struct buck_boost_context *context = buck_boost_get_context(index);
	const char *client = NULL;

	if (!context || (user < BBST_USER_BEGIN) || (user >= BBST_USER_END))
		return -EPERM;

	client = g_buck_boost_user_data[user];

	if (power_vote_get_client_value_locked(context->mode_vote_object,
		client, true) <= 0)
		return -EINVAL;

	return power_vote_set(context->vout_vote_object, client, true, vol);
}
EXPORT_SYMBOL(buckboost_set_vout);

bool buck_boost_pwr_good(unsigned int type)
{
	struct buck_boost_context *context = buck_boost_get_context(BBST_INDEX_DEFAULT);
	struct buck_boost_ops *l_ops = NULL;

	if (!context)
		return -EPERM;

	l_ops = context->ops;
	if (!l_ops || !l_ops->pwr_good) {
		hwlog_err("ops or pwr_good is null\n");
		return false;
	}

	return l_ops->pwr_good(l_ops->dev_data);
}

bool buck_boost_set_enable(unsigned int enable, unsigned int user)
{
	return buckboost_set_enable(enable, user, BBST_INDEX_DEFAULT);
}
EXPORT_SYMBOL(buck_boost_set_enable);

bool buckboost_set_enable(unsigned int enable, unsigned int user, unsigned int index)
{
	struct buck_boost_context *context = buck_boost_get_context(index);
	const char *client = NULL;

	if (!context || (user < BBST_USER_BEGIN) || (user >= BBST_USER_END))
		return false;

	client = g_buck_boost_user_data[user];

	if (enable)
		return !power_vote_set(context->mode_vote_object, client, true, 1);

	power_vote_set(context->vout_vote_object, client, false, 0);
	return !power_vote_set(context->mode_vote_object, client, false, 0);
}
EXPORT_SYMBOL(buckboost_set_enable);

static void buckboost_monitor_work(struct work_struct *work)
{
	struct buck_boost_dev *di = container_of(work,
		struct buck_boost_dev, monitor_work.work);
	struct buck_boost_context *context = NULL;
	int i;

	if (!di)
		return;

	for (i = 0; i < di->path_num; i++) {
		context = buck_boost_get_context(i);
		if (!context || !context->ops || !context->ops->monitor_state) {
			hwlog_err("context or ops or monitor_state is null");
			continue;
		}
		context->ops->monitor_state(context->ops->dev_data);
	}

	queue_delayed_work(system_freezable_power_efficient_wq,
		&di->monitor_work, msecs_to_jiffies(di->delay_ms));
}

static int buck_boost_parse_bbst_vout_table(struct device_node *np,
	struct buck_boost_dev *di)
{
	int i, len, size;

	len = power_dts_read_u32_count(power_dts_tag(HWLOG_TAG), np, "gpio_vout_table",
		BBST_VOUT_TABLE_MAX_SIZE, BBST_GPIO_VOUT_END);
	if (len <= 0)
		return -EINVAL;

	size = sizeof(*di->vout_table) * (len / BBST_GPIO_VOUT_END);
	di->vout_table = kzalloc(size, GFP_KERNEL);
	if (!di->vout_table)
		return -ENOMEM;

	if (power_dts_read_u32_array(power_dts_tag(HWLOG_TAG), np,
		"gpio_vout_table", (u32 *)di->vout_table, len)) {
		kfree(di->vout_table);
		return -EINVAL;
	}

	di->vout_table_size = len / BBST_GPIO_VOUT_END;
	for (i = 0; i < di->vout_table_size; i++)
		hwlog_info("vout_table[%d], output_voltage: %d gpio_value: %d\n", i,
			di->vout_table[i].output_voltage, di->vout_table[i].gpio_value);
	return 0;
}

static void buck_boost_parse_bbst_vout_gpios(struct device_node *np,
	struct buck_boost_dev *di)
{
	int i;
	struct power_gpio_group gpio_group[BBST_VOUT_TABLE_MAX_SIZE] = { 0 };

	if (power_gpio_config_gpio_group(np, "bbst_vout_gpios", gpio_group, BBST_VOUT_TABLE_MAX_SIZE, &di->gpio_vout_num)) {
		hwlog_err("%s config gpio group failed\n", __func__);
		return;
	}

	di->bbst_gpio_vout = kzalloc(sizeof(*di->bbst_gpio_vout) * di->gpio_vout_num, GFP_KERNEL);
	if (!di->bbst_gpio_vout)
		return;

	for (i = 0; i < di->gpio_vout_num; i++)
		di->bbst_gpio_vout[i] = gpio_group[i].gpio;
}

static void buck_boost_dts_parse(struct device_node *np,
	struct buck_boost_dev *di)
{
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"boost_use_gpio", &di->boost_use_gpio, 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"path_num", &di->path_num, 1);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"need_monitor_state", &di->need_monitor_state, 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"monitor_delay", &di->delay_ms, BBST_MONITOR_INTERVAL_DEFAULT);
	if (di->boost_use_gpio) {
		buck_boost_parse_bbst_vout_gpios(np, di);
		buck_boost_parse_bbst_vout_table(np, di);
	}
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

#ifdef CONFIG_HUAWEI_POWER_DEBUG
static ssize_t buck_boost_dbg_test_flag_show(void *dev_data, char *buf, size_t size)
{
	struct buck_boost_dev *di = dev_data;

	if (!buf || !di) {
		hwlog_err("buf or di is null\n");
		return -EINVAL;
	}

	return scnprintf(buf, size, "buck_boost_test_flag=0x%x\n", di->test_flag);
}

static ssize_t buck_boost_dbg_test_flag_store(void *dev_data, const char *buf, size_t size)
{
	struct buck_boost_dev *di = dev_data;
	int test_flag = 0;

	if (!buf || !di) {
		hwlog_err("buf or di is null\n");
		return -EINVAL;
	}

	if (sscanf_s(buf, "0x%x", &test_flag) != 1) {
		hwlog_err("%s sscanf_s failed\n", __func__);
		return -EINVAL;
	}

	di->test_flag = test_flag;
	hwlog_info("test_flag=0x%x\n", test_flag);
	return size;
}

static ssize_t buck_boost_dbg_set_enable_store(void *dev_data, const char *buf, size_t size)
{
	struct buck_boost_dev *di = dev_data;
	int value = 0;
	int user_id = 0;
	int index = 0;

	if (!buf || !di) {
		hwlog_err("buf or di is null\n");
		return -EINVAL;
	}

	if (di->test_flag != DBG_BUCK_BOOST_FLAG) {
		hwlog_err("test_flag=0x%x is invalid\n", di->test_flag);
		return -EINVAL;
	}

	if (sscanf_s(buf, "%d %d %d", &index, &value, &user_id) != 3) {
		hwlog_err("%s sscanf_s failed\n", __func__);
		return -EINVAL;
	}

	if (((value != 0) && (value != 1)) || (index >= di->path_num) ||
		(user_id < BBST_USER_BEGIN) || (user_id >= BBST_USER_END)) {
		hwlog_err("index or value or user_id is invalid index=%d value=%d user_id=%d\n", index, value, user_id);
		return -EINVAL;
	}

	hwlog_info("%s, index=%d value=%d user_id=%d\n", __func__, index, value, user_id);
	buckboost_set_enable(value, user_id, index);
	return size;
}

static ssize_t buck_boost_dbg_set_vout_store(void *dev_data, const char *buf, size_t size)
{
	struct buck_boost_dev *di = dev_data;
	int user_id = 0;
	int vol = 0;
	int index = 0;

	if (!buf || !di) {
		hwlog_err("buf or di is null\n");
		return -EINVAL;
	}

	if (di->test_flag != DBG_BUCK_BOOST_FLAG) {
		hwlog_err("test_flag=0x%x is invalid\n", di->test_flag);
		return -EINVAL;
	}

	if (sscanf_s(buf, "%d %d %d", &index, &vol, &user_id) != 3) {
		hwlog_err("%s sscanf_s failed\n", __func__);
		return -EINVAL;
	}

	if ((vol < 0) || (index >= di->path_num) ||
		(user_id < BBST_USER_BEGIN) || (user_id >= BBST_USER_END)) {
		hwlog_err("index or user_id is invalid index=%d user_id=%d\n", index, user_id);
		return -EINVAL;
	}

	hwlog_info("%s, index=%d vol=%d user_id=%d\n", __func__, index, vol, user_id);
	buckboost_set_vout(vol, user_id, index);
	return size;
}
#endif /* CONFIG_HUAWEI_POWER_DEBUG */

static void buck_boost_register_power_debug(struct buck_boost_dev *di)
{
#ifdef CONFIG_HUAWEI_POWER_DEBUG
	power_dbg_ops_register("buck_boost", "test_flag", di,
		buck_boost_dbg_test_flag_show, buck_boost_dbg_test_flag_store);
	power_dbg_ops_register("buck_boost", "set_enable", di,
		NULL, buck_boost_dbg_set_enable_store);
	power_dbg_ops_register("buck_boost", "set_vout", di,
		NULL, buck_boost_dbg_set_vout_store);
#endif /* CONFIG_HUAWEI_POWER_DEBUG */
}

static int buck_boost_mode_vote_cb(struct power_vote_object *obj,
	void *data, int result, const char *client_str)
{
	struct buck_boost_context *context = data;
	struct buck_boost_ops *l_ops = NULL;

	if (!context) {
		hwlog_err("context is null\n");
		return -EINVAL;
	}

	l_ops = context->ops;
	if (!l_ops || !l_ops->set_enable) {
		hwlog_err("ops or set_enable is null\n");
		return -EINVAL;
	}

	hwlog_info("path %u set enable:%u\n", l_ops->index, result);

	if (!l_ops->set_enable(result, l_ops->dev_data))
		return -EPERM;

	return 0;
}

static int buck_boost_vout_vote_cb(struct power_vote_object *obj,
	void *data, int result, const char *client_str)
{
	struct buck_boost_context *context = data;
	struct buck_boost_ops *l_ops = NULL;

	if (!context) {
		hwlog_err("context is null\n");
		return -EINVAL;
	}

	l_ops = context->ops;
	if (!l_ops || !l_ops->set_vout) {
		hwlog_err("ops or set_vout is null\n");
		return -EINVAL;
	}

	if (result < 0)
		result = context->const_vout;

	hwlog_info("path %u set vout:%u\n", l_ops->index, result);

	return l_ops->set_vout(result, l_ops->dev_data);
}

static int buck_boost_init_context(struct device_node *np,
	struct buck_boost_dev *di)
{
	int i, len, type;
	struct buck_boost_context *context = NULL;
	int ret;

	di->bbst_context = kzalloc(sizeof(*di->bbst_context) * di->path_num, GFP_KERNEL);
	if (!di->bbst_context)
		return -ENOMEM;

	for (i = 0; i < di->path_num; i++) {
		context = &di->bbst_context[i];
		(void)power_dts_read_u32_index_dflt(power_dts_tag(HWLOG_TAG), np,
			"const_vout", i, &context->const_vout, 0);
		(void)power_dts_read_u32_index_dflt(power_dts_tag(HWLOG_TAG), np,
			"vout_vote_type", i, &type, VOUT_VOTE_SET_MAX);
		(void)power_dts_read_u32_index_dflt(power_dts_tag(HWLOG_TAG), np,
			"need_init_vout", i, &context->need_init_vout, 0);
		snprintf_s(context->mode_vote_object, BBST_VOTE_NAME_LEN,
			BBST_VOTE_NAME_LEN - 1, "%s_%d", BBST_MODE_VOTE_PREFIX, i);
		snprintf_s(context->vout_vote_object, BBST_VOTE_NAME_LEN,
			BBST_VOTE_NAME_LEN - 1, "%s_%d", BBST_VOUT_VOTE_PREFIX, i);
		if (power_vote_create_object(context->mode_vote_object,
			POWER_VOTE_SET_ANY, buck_boost_mode_vote_cb, (void *)context))
			return -EINVAL;
		if (power_vote_create_object(context->vout_vote_object,
			(type == VOUT_VOTE_SET_MIN) ? POWER_VOTE_SET_MIN : POWER_VOTE_SET_MAX,
			buck_boost_vout_vote_cb, (void *)context))
			return -EINVAL;
	}

	return 0;
}

static void buck_boost_release_context(struct buck_boost_dev *di)
{
	int i;
	struct buck_boost_context *context = NULL;

	if (!di->bbst_context)
		return;

	for (i = 0; i < di->path_num; i++) {
		context = &di->bbst_context[i];
		if (!context)
			continue;
		power_vote_destroy_object(context->mode_vote_object);
		power_vote_destroy_object(context->vout_vote_object);
	}

	kfree(di->bbst_context);
}

static void buck_boost_release_resources(struct platform_device *pdev)
{
	struct buck_boost_dev *di = platform_get_drvdata(pdev);

	if (!di)
		return;

	kfree(di->bbst_gpio_vout);
	kfree(di->vout_table);
	buck_boost_release_context(di);
	devm_kfree(&pdev->dev, di);
	g_buck_boost_di = NULL;
}

static int buck_boost_probe(struct platform_device *pdev)
{
	struct buck_boost_dev *di = NULL;
	struct device_node *np = NULL;

	if (!pdev || !pdev->dev.of_node)
		return -ENODEV;

	di = devm_kzalloc(&pdev->dev, sizeof(*di), GFP_KERNEL);
	if (!di)
		return -ENOMEM;

	np = pdev->dev.of_node;
	di->dev = &pdev->dev;
	INIT_DELAYED_WORK(&di->monitor_work, buckboost_monitor_work);
	buck_boost_dts_parse(np, di);
	if (buck_boost_init_context(np, di))
		goto fail;
	platform_set_drvdata(pdev, di);
	g_buck_boost_di = di;
	if (di->boost_use_gpio && buck_boost_gpio_check(di))
		goto fail;
	buck_boost_register_power_debug(di);
	if (di->need_monitor_state)
		queue_delayed_work(system_freezable_power_efficient_wq,
			&di->monitor_work, msecs_to_jiffies(0));

	return 0;

fail:
	buck_boost_release_resources(pdev);
	return -EINVAL;
}

static int buck_boost_remove(struct platform_device *pdev)
{
	struct buck_boost_dev *l_dev = platform_get_drvdata(pdev);

	if (!l_dev)
		return 0;

	cancel_delayed_work(&l_dev->monitor_work);
	buck_boost_release_resources(pdev);
	return 0;
}

static void buck_boost_shutdown(struct platform_device *pdev)
{
	struct buck_boost_dev *l_dev = platform_get_drvdata(pdev);

	if (!l_dev)
		return;

	cancel_delayed_work(&l_dev->monitor_work);
	buck_boost_release_resources(pdev);
}

#ifdef CONFIG_PM
static int buck_boost_resume(struct platform_device *pdev)
{
	struct buck_boost_dev *l_dev = platform_get_drvdata(pdev);

	if (!l_dev)
		return -ENODEV;

	if (l_dev->need_monitor_state)
		queue_delayed_work(system_freezable_power_efficient_wq,
			&l_dev->monitor_work, msecs_to_jiffies(BBST_MONITOR_WORK_RESUME_DELAY));
	return 0;
}

static int buck_boost_suspend(struct platform_device *pdev, pm_message_t msg)
{
	struct buck_boost_dev *l_dev = platform_get_drvdata(pdev);

	if (!l_dev)
		return -ENODEV;

	cancel_delayed_work(&l_dev->monitor_work);
	return 0;
}
#endif /* CONFIG_PM */

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
	.shutdown = buck_boost_shutdown,
#ifdef CONFIG_PM
	.resume = buck_boost_resume,
	.suspend = buck_boost_suspend,
#endif
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
