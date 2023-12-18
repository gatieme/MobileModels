// SPDX-License-Identifier: GPL-2.0
/*
 * battery_charge_balance.c
 *
 * huawei battery charge balance driver
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

#include <securec.h>
#include <chipset_common/hwpower/battery/battery_charge_balance.h>
#include <chipset_common/hwpower/battery/battery_temp.h>
#include <chipset_common/hwpower/common_module/power_dts.h>
#include <chipset_common/hwpower/common_module/power_log.h>
#include <chipset_common/hwpower/common_module/power_printk.h>

#define HWLOG_TAG battery_charge_balance
HWLOG_REGIST();

#define BAL_CCCV_TAB_COL        2
#define BAL_TEMP_TAB_COL        2

static struct bat_chg_bal_device *g_bat_chg_bal_dev;

static int bat_chg_bal_get_cccv_node(int bat_id,
	struct bat_chg_balance_info info, struct bat_cccv_node *node)
{
	int i;
	struct bat_chg_bal_device *di = g_bat_chg_bal_dev;
	struct bat_param *param = NULL;
	struct bat_temp_cccv *temp_cccv = NULL;

	if (!di)
		return -ENODEV;

	param = &di->param_tab[bat_id];
	for (i = 0; i < param->len; i++) {
		if (info.temp < param->temp_tab[i].temp)
			break;
	}
	if (i >= param->len)
		i = param->len - 1;
	temp_cccv = &param->temp_tab[i];
	for (i = 0; i < temp_cccv->len; i++) {
		if (info.vol < temp_cccv->cccv_tab[i].vol)
			break;
	}
	if (i >= temp_cccv->len)
		i = temp_cccv->len - 1;
	*node = temp_cccv->cccv_tab[i];
	return 0;
}

int bat_chg_balance_get_cur_info(struct bat_chg_balance_info *info,
	u32 info_len, struct bat_chg_balance_cur *result, int mode)
{
	struct bat_cccv_node cccv_node[BAT_BALANCE_COUNT];
	struct bat_chg_bal_device *di = g_bat_chg_bal_dev;

	if (!di)
		return -ENODEV;

	bat_chg_bal_get_cccv_node(BAT_MAIN, info[BAT_MAIN], &cccv_node[BAT_MAIN]);
	bat_chg_bal_get_cccv_node(BAT_AUX, info[BAT_AUX], &cccv_node[BAT_AUX]);

	if (mode == BAT_PARALLEL_MODE)
		return bat_chg_bal_parallel_get_cur_info(di, info, info_len,
			cccv_node, BAT_BALANCE_COUNT, result);
	else if (mode == BAT_SERIAL_MODE)
		return bat_chg_bal_serial_get_cur_info(di, info, info_len,
			cccv_node, BAT_BALANCE_COUNT, result);
	else
		hwlog_err("%s invalid mode\n", __func__);

	return -EINVAL;
}

static int bat_chg_bal_get_log_head(char *buffer, int size, void *dev_data)
{
	struct bat_chg_bal_device *di = dev_data;

	if (!di || !buffer)
		return -EPERM;

	snprintf_s(buffer, size, size - 1, "bal_cur  req_cur0 req_cur1 ");

	return 0;
}

static int bat_chg_bal_dump_log_data(char *buffer, int size, void *dev_data)
{
	struct bat_chg_bal_device *di = dev_data;

	if (!di || !buffer)
		return -EPERM;

	snprintf_s(buffer, size, size - 1, "%-9d%-9d%-9d",
		di->bal_cur, di->req_cur[BAT_MAIN], di->req_cur[BAT_AUX]);

	return 0;
}

static struct power_log_ops bat_chg_bal_log_ops = {
	.dev_name = "bat_balance",
	.dump_log_head = bat_chg_bal_get_log_head,
	.dump_log_content = bat_chg_bal_dump_log_data,
};

static int bat_chg_bal_cccv_tab_dts(struct device_node *node,
	const char *tab_name,
	struct bat_temp_cccv *temp_cccv)
{
	int i, len;
	u32 data;

	len = power_dts_read_u32_count(power_dts_tag(HWLOG_TAG), node,
			tab_name, BAL_CCCV_TAB_LEN, BAL_CCCV_TAB_COL);
	if (len <= 0) {
		hwlog_err("cccv_tab_dts get failed\n");
		return -ENODEV;
	}
	temp_cccv->len = len / BAL_CCCV_TAB_COL;
	for (i = 0; i < len; i++) {
		if (power_dts_read_u32_index(power_dts_tag(HWLOG_TAG),
			node, tab_name, i, &data))
			return -ENODEV;
		if ((i % BAL_CCCV_TAB_COL) == 0)
			temp_cccv->cccv_tab[i / BAL_CCCV_TAB_COL].vol = (int)data;
		else
			temp_cccv->cccv_tab[i / BAL_CCCV_TAB_COL].cur = (int)data;
	}
	return 0;
}

static int bat_chg_bal_parse_bat_dts(int bat_id, struct bat_chg_bal_device *di,
	struct device_node *node)
{
	int ret;
	int i, len;
	int idata = 0;
	const char *string = NULL;

	ret = power_dts_read_u32(power_dts_tag(HWLOG_TAG), node,
		"weight", &di->param_tab[bat_id].weight, 2000); /* 2000mAH default */
	if (ret) {
		hwlog_err("batt %d weight failed\n", bat_id);
		return ret;
	}
	len = power_dts_read_count_strings(power_dts_tag(HWLOG_TAG), node,
		"temp_tab", BAL_TEMP_TAB_LEN, BAL_TEMP_TAB_COL);
	if (len < 0)
		return -ENODEV;
	di->param_tab[bat_id].len = len / BAL_TEMP_TAB_COL;
	for (i = 0; i < len; i++) {
		if (power_dts_read_string_index(power_dts_tag(HWLOG_TAG),
			node, "temp_tab", i, &string))
			return -ENODEV;

		if ((i % BAL_TEMP_TAB_COL) == 0) {
			if (kstrtoint(string, POWER_BASE_DEC, &idata))
				return -ENODEV;
			di->param_tab[bat_id].temp_tab[i / BAL_TEMP_TAB_COL].temp =
				idata;
			hwlog_info("bat_id %d temp_tab temp:%d\n", bat_id, idata);
		} else {
			if (bat_chg_bal_cccv_tab_dts(node, string,
				&di->param_tab[bat_id].temp_tab[i / BAL_TEMP_TAB_COL]))
				return -ENODEV;
		}
	}
	return 0;
}

static int bat_chg_bal_parse_dts(struct bat_chg_bal_device *di)
{
	struct device_node *np = di->dev->of_node;
	int ret;
	struct device_node *bat_node = NULL;

	ret = power_dts_read_u32_array(power_dts_tag(HWLOG_TAG), np,
		"unbalance_th", di->unbalance_th, BAL_UNBAL_TAB_LEN);
	if (ret)
		return ret;

	bat_node = of_find_node_by_name(np, "battery0");
	if (!bat_node) {
		hwlog_err("batt0 find failed\n");
		return -ENODEV;
	}
	ret = bat_chg_bal_parse_bat_dts(BAT_MAIN, di, bat_node);
	if (ret) {
		hwlog_err("batt0 para read failed\n");
		return ret;
	}

	bat_node = of_find_node_by_name(np, "battery1");
	if (!bat_node) {
		hwlog_err("batt1 find failed\n");
		return -ENODEV;
	}
	ret = bat_chg_bal_parse_bat_dts(BAT_AUX, di, bat_node);
	if (ret) {
		hwlog_err("batt1 para read failed\n");
		return ret;
	}
	return 0;
}

static int bat_chg_bal_probe(struct platform_device *pdev)
{
	struct bat_chg_bal_device *di = NULL;
	int ret;

	if (!pdev || !pdev->dev.of_node)
		return -ENODEV;
	di = devm_kzalloc(&pdev->dev, sizeof(*di), GFP_KERNEL);
	if (!di)
		return -ENOMEM;
	di->dev = &pdev->dev;
	ret = bat_chg_bal_parse_dts(di);
	if (ret) {
		hwlog_err("parse dts err\n");
		return ret;
	}
	g_bat_chg_bal_dev = di;

	bat_chg_bal_log_ops.dev_data = (void *)di;
	power_log_ops_register(&bat_chg_bal_log_ops);

	hwlog_info("%s ok\n", __func__);
	return 0;
}

static int bat_chg_bal_remove(struct platform_device *pdev)
{
	struct bat_chg_bal_device *di = platform_get_drvdata(pdev);

	if (!di)
		return -ENODEV;
	g_bat_chg_bal_dev = NULL;
	return 0;
}

static const struct of_device_id bat_chg_bal_match_table[] = {
	{
		.compatible = "huawei,battery_charge_balance",
		.data = NULL,
	},
	{},
};

static struct platform_driver bat_chg_bal_driver = {
	.probe = bat_chg_bal_probe,
	.remove = bat_chg_bal_remove,
	.driver = {
		.name = "huawei,battery_charge_balance",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(bat_chg_bal_match_table),
	},
};

static int __init bat_chg_bal_init(void)
{
	return platform_driver_register(&bat_chg_bal_driver);
}

static void __exit bat_chg_bal_exit(void)
{
	platform_driver_unregister(&bat_chg_bal_driver);
}

late_initcall_sync(bat_chg_bal_init);
module_exit(bat_chg_bal_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("battery charge balance driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
