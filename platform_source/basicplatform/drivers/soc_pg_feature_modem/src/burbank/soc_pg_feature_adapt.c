/*
 * parse soc pg feature
 *
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2022. All rights reserved.
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
#include <soc_pg_feature_adapt.h>
#include <linux/export.h>
#include <linux/of.h>
#include <linux/printk.h>
#include <linux/string.h>
#include <platform_include/see/efuse_driver.h>
#include <linux/platform_drivers/soc_pg_feature.h>
#include "soc_spec_info.h"

static const char *get_pg_soc_chip_type(void)
{
	const char *soc_spec = NULL;
	struct device_node *np = of_find_compatible_node(NULL, NULL, "hisilicon, soc_spec");

	if (!np) {
		pr_err("no soc_spec dts node");
		return MODEM_CHIP_TYPE_CS;
	}

	if (of_property_read_string(np, "soc_spec_set", &soc_spec)) {
		pr_err("no soc_spec_set dts info\n");
		of_node_put(np);
		return EFUSE_SOC_ERROR;
	}
	of_node_put(np);
	pr_err("%s: soc_spec_set is %s\n",__func__, soc_spec);

	return soc_spec;
}

int get_pg_soc_is_modem_need_load(void)
{
	const char *dts_str = NULL;

	dts_str = get_pg_soc_chip_type();
	if (strncmp(dts_str, EFUSE_SOC_ERROR, strlen(EFUSE_SOC_ERROR)) == 0 ||
			is_have_modem(dts_str) == 0) {
		pr_err("%s: not load modem!!\n", __func__);
		return NOT_LOAD_MODEM;
	}

	return NEED_LOAD_MODEM;
}
EXPORT_SYMBOL(get_pg_soc_is_modem_need_load);

/*
 * Description: Get soc chip level.
 *              The soc level info passed by cmd line from bootloader.
 *              interface for modem
 * Input:
 *        void
 * Return:
 *        int soc chip level
 *        LEVEL1   -- return 0
 *        LEVEL2 -- return 1
 *        do not support feature --return -1
 */
int get_soc_modem_regulator_strategy(void)
{
	return NEED_NOTHING;
}
EXPORT_SYMBOL(get_soc_modem_regulator_strategy);

u32 get_kernel_chip_version(void)
{
	u32 chip_version;
	struct device_node *np = of_find_compatible_node(NULL, NULL, "hisilicon, chip_version");

	if (!np) {
		pr_err("no chip_version dts node");
		return VERSION_V110;
	}

	if (of_property_read_u32(np, "chip_version_set", &chip_version)) {
		pr_err("no chip_version_set dts info\n");
		of_node_put(np);
		return VERSION_V110;
	}
	of_node_put(np);
	pr_err("%s: chip_version_set is %u\n",__func__, chip_version);

	return chip_version;
}
EXPORT_SYMBOL(get_kernel_chip_version);