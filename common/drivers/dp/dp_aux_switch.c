/*
 * dp_aux_switch.c
 *
 * dp switch driver
 *
 * Copyright (c) 2021-2022 Huawei Technologies Co., Ltd.
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

#include "dp_aux_switch.h"
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/of.h>
#include <linux/pinctrl/consumer.h>
#include <linux/debugfs.h>
#include <huawei_platform/log/hw_log.h>

#ifdef HWLOG_TAG
#undef HWLOG_TAG
#endif
#define HWLOG_TAG dp_aux_switch
HWLOG_REGIST();

enum {
	DP_ORIENT_NATIVE_CTL_TYPE = 0,
	DP_ORIENT_GPIO_CTL_TYPE,
};

static struct pinctrl *g_pctl = NULL;
static int g_dp_orient_ctl_type;
#ifdef DP_AUX_DEBUG
static struct dentry *g_dp_aux_root;
#endif /* DP_AUX_DEBUG */

static void dp_aux_switch_pinctrl(const char *name)
{
	int ret;
	struct pinctrl_state *state = NULL;

	if (!g_pctl) {
		hwlog_err("%s: pinctrl is null\n", __func__);
		return;
	}

	state = pinctrl_lookup_state(g_pctl, name);
	if (IS_ERR(state)) {
		hwlog_err("%s: set pinctrl state to %s fail ret=%d\n", __func__,
			name, PTR_ERR(state));
		return;
	}

	ret = pinctrl_select_state(g_pctl, state);
	if (ret)
		hwlog_err("%s: set pinctrl state to %s fail ret=%d\n", __func__,
			name, ret);
}

void dp_aux_switch_enable(bool enable)
{
	hwlog_info("%s, %d\n", __func__, enable);

	if(enable) {
		dp_aux_switch_pinctrl("aux_enable");
	} else {
		dp_aux_switch_pinctrl("dp_cc1");
		dp_aux_switch_pinctrl("default");
	}
}
EXPORT_SYMBOL_GPL(dp_aux_switch_enable);

void dp_switch_orient_cc1(void)
{
	if (g_dp_orient_ctl_type == DP_ORIENT_NATIVE_CTL_TYPE)
		return;

	dp_aux_switch_pinctrl("dp_cc1");
}
EXPORT_SYMBOL_GPL(dp_switch_orient_cc1);

void dp_switch_orient_cc2(void)
{
	if (g_dp_orient_ctl_type == DP_ORIENT_NATIVE_CTL_TYPE)
		return;

	dp_aux_switch_pinctrl("dp_cc2");
}
EXPORT_SYMBOL_GPL(dp_switch_orient_cc2);

#ifdef DP_AUX_DEBUG
static int dp_aux_dbg_ctrl(void *data, u64 val)
{
	if (val == 0) { /* aux enable */
		dp_aux_switch_enable(true);
	} else if (val == 1) { /* aux disable */
		dp_aux_switch_enable(false);
	} else if (val == 2) { /* cc1 */
		dp_switch_orient_cc1();
	} else if (val == 3) { /* cc2 */
		dp_switch_orient_cc2();
	}

	hwlog_info("%s: control=%u\n", __func__, val);
	return 0;
}
DEFINE_DEBUGFS_ATTRIBUTE(dp_aux_ctrl_fops,
	NULL, dp_aux_dbg_ctrl, "%llu\n");

static void dp_aux_create_debugfs(void)
{
	struct dentry *root = NULL;

	if (!g_dp_aux_root) {
		root = debugfs_create_dir("dp_aux", NULL);
		if (!root) {
			pr_err("%s: create debugfs root node fail\n", __func__);
			return;
		}
		g_dp_aux_root = root;
	}

	debugfs_create_file("ctrl", 0200, root, NULL, &dp_aux_ctrl_fops);
}
#else
static void dp_aux_create_debugfs(void)
{
}
#endif /* DP_AUX_DEBUG */

static int dp_aux_switch_probe(struct platform_device *pdev)
{
	if (of_property_read_bool(pdev->dev.of_node,
		"switch_orientation_by_gpio")) {
		g_dp_orient_ctl_type = DP_ORIENT_GPIO_CTL_TYPE;
		hwlog_info("%s: switch dp orient by gpio", __func__);
	}

	g_pctl = devm_pinctrl_get(&pdev->dev);
	if (IS_ERR(g_pctl)) {
		hwlog_err("failed %d\n", PTR_ERR(g_pctl));
		g_pctl = NULL;
	}

	dp_aux_create_debugfs();
	return 0;
}

static const struct of_device_id dp_aux_switch_match_table[] = {
	{
		.compatible = "huawei,dp_aux_switch",
		.data = NULL,
	},
	{},
};

static struct platform_driver dp_aux_switch_driver = {
	.probe = dp_aux_switch_probe,
	.driver = {
		.name = "dp_aux_switch",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(dp_aux_switch_match_table),
	},
};

static int __init dp_aux_switch_init(void)
{
	return platform_driver_register(&dp_aux_switch_driver);
}

static void __exit dp_aux_switch_exit(void)
{
	platform_driver_unregister(&dp_aux_switch_driver);
}

fs_initcall(dp_aux_switch_init);
module_exit(dp_aux_switch_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("huawei dp aux switch driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
