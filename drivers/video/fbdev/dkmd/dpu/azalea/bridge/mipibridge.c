/*
 * mipi_bridge.c
 *
 * driver for mipi2edp bridge
 *
 * Copyright (c) 2024-2024 Huawei Technologies Co., Ltd.
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
/*lint -e548 -e574 -e578*/
#include <linux/clk.h>
#include <linux/clk-provider.h>
#include <securec.h>
#include "lcd_kit_bridge.h"
#include "dpu_fb.h"
#include <platform_include/basicplatform/linux/mfd/pmic_platform.h>
#include <linux/gpio.h>

/*******************************************************************************
 ** LCD VCC
 */
#define VCC_LCDIO_NAME		"bridge-vcc"
#define BANK_LCDIO_NAME		"bridge-bankio"
#define VCCX_LCDIO_NAME		"bridge-vccx"
#define GPIO_BRIDGE_RESET_NAME		"bridge_reset_gpio"
#define DTS_COMP_HUAWEI_LCD_PANEL_TYPE		"huawei,lcd_panel_type"
#define DTS_COMP_LCD_PANEL_TYPE		"lcd_panel_type"
#define LCD_KIT_MIPI_BRIDGE_SUPPORT		"lcd-kit,mipi-bridge-support"

#define BRIDGE_VOLTAGE_VCCX 2100000
#define BRIDGE_VOLTAGE_BANKIO 1800000
#define BRIDGE_VOLTAGE_VCC 1200000

#define VCCX 0
#define BANKIO 1
#define VCC 2
#define CLK 3
#define RESET 4

#define PANEL_IC_NAME_MAX (64)
#define PANEL_DELAY_NUMS (5)

static struct regulator *bridge_vcc;
static struct regulator *bridge_bankio;
static struct regulator *bridge_vccx;

struct mipibridge_panel_info {
	struct platform_device *pdev;
	char panel_name[PANEL_IC_NAME_MAX];
	uint32_t enable_delays[PANEL_DELAY_NUMS];
	uint32_t disable_delays[PANEL_DELAY_NUMS];
	uint32_t pin_rst;
	uint32_t pmu_clk_support;
};

static struct mipibridge_panel_info g_panel_info = {0};

static struct vcc_desc g_bridge_init_cmds[] = {
	{DTYPE_VCC_GET, VCCX_LCDIO_NAME, &bridge_vccx, 0, 0, WAIT_TYPE_MS, 0},
	{DTYPE_VCC_GET, BANK_LCDIO_NAME, &bridge_bankio, 0, 0, WAIT_TYPE_MS, 0},
	{DTYPE_VCC_GET, VCC_LCDIO_NAME, &bridge_vcc, 0, 0, WAIT_TYPE_MS, 0},
	{DTYPE_VCC_SET_VOLTAGE, VCCX_LCDIO_NAME, &bridge_vccx,
		BRIDGE_VOLTAGE_VCCX, BRIDGE_VOLTAGE_VCCX, WAIT_TYPE_MS, 0},
	{DTYPE_VCC_SET_VOLTAGE, BANK_LCDIO_NAME, &bridge_bankio,
		BRIDGE_VOLTAGE_BANKIO, BRIDGE_VOLTAGE_BANKIO, WAIT_TYPE_MS, 0},
	{DTYPE_VCC_SET_VOLTAGE, VCC_LCDIO_NAME, &bridge_vcc,
		BRIDGE_VOLTAGE_VCC, BRIDGE_VOLTAGE_VCC, WAIT_TYPE_MS, 0},
};

/* enable vccx 2.1v bankio 1.8v vcc 1.2v */
static struct vcc_desc g_bridge_enable_cmds[] = {
	{DTYPE_VCC_ENABLE, VCCX_LCDIO_NAME, &bridge_vccx, 0, 0, WAIT_TYPE_MS, 0},
	{DTYPE_VCC_ENABLE, BANK_LCDIO_NAME, &bridge_bankio, 0, 0, WAIT_TYPE_MS, 0},
	{DTYPE_VCC_ENABLE, VCC_LCDIO_NAME, &bridge_vcc, 0, 0, WAIT_TYPE_MS, 0},
};

/* disable vcc 1.2v bankio 1.8v vccx 2.1v */
static struct vcc_desc g_bridge_disable_cmds[] = {
	{DTYPE_VCC_DISABLE, VCC_LCDIO_NAME, &bridge_vcc, 0, 0, WAIT_TYPE_MS, 0},
	{DTYPE_VCC_DISABLE, BANK_LCDIO_NAME, &bridge_bankio, 0, 0, WAIT_TYPE_MS, 0},
	{DTYPE_VCC_DISABLE, VCCX_LCDIO_NAME, &bridge_vccx, 0, 0, WAIT_TYPE_MS, 0},
};

/* bridge reset gpio */
static struct gpio_desc g_bridge_gpio_request_cmds[] = {
	{DTYPE_GPIO_REQUEST, WAIT_TYPE_MS, 0,
		GPIO_BRIDGE_RESET_NAME, &g_panel_info.pin_rst, 0},
};

static struct gpio_desc g_bridge_gpio_on_cmds[] = {
	{DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 0,
		GPIO_BRIDGE_RESET_NAME, &g_panel_info.pin_rst, 1},
};

static struct gpio_desc g_bridge_gpio_off_cmds[] = {
	{DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 0,
		GPIO_BRIDGE_RESET_NAME, &g_panel_info.pin_rst, 0},
};

static void bridge_pre_enable(void)
{
}

static void bridge_enable(void)
{
	int ret = 0;
	DPU_FB_INFO("+\n");

	if (!g_panel_info.pdev) {
		DPU_FB_ERR("pdev is NULL!\n");
		return;
	}

	// bridge vccx 2.1v bankio 1.8v vcc 1.2v
	ret = vcc_cmds_tx(g_panel_info.pdev, g_bridge_enable_cmds, ARRAY_SIZE(g_bridge_enable_cmds));
	if (ret != 0) {
		DPU_FB_ERR("vcc enable failed!\n");
		return;
	}

	// bridge clk
	if (g_panel_info.pmu_clk_support) {
		DPU_FB_ERR("clk support+\n");
		pmic_write_reg(0xBF, 0x90);
		pmic_write_reg(0x4E, 0x01);
		if (g_panel_info.enable_delays[CLK])
			mdelay(g_panel_info.enable_delays[CLK]);
	}

	// bridge rst
	ret = gpio_cmds_tx(g_bridge_gpio_on_cmds, ARRAY_SIZE(g_bridge_gpio_on_cmds));
	if (ret != 0) {
		DPU_FB_ERR("gpio enable failed!\n");
		return;
	}

	DPU_FB_INFO("-\n");
}

static void bridge_disable(void)
{
	int ret = 0;
	DPU_FB_INFO("+\n");

	if (!g_panel_info.pdev) {
		DPU_FB_ERR("pdev is NULL!\n");
		return;
	}

	// bridge rst
	ret = gpio_cmds_tx(g_bridge_gpio_off_cmds, ARRAY_SIZE(g_bridge_gpio_off_cmds));
	if (ret != 0) {
		DPU_FB_ERR("gpio disable failed!\n");
		return;
	}

	// bridge clk
	if (g_panel_info.pmu_clk_support) {
		DPU_FB_ERR("clk support+\n");
		pmic_write_reg(0xBF, 0x00);
		pmic_write_reg(0x4E, 0x00);
		if (g_panel_info.disable_delays[CLK])
			mdelay(g_panel_info.disable_delays[CLK]);
	}

	// bridge vcc 1.2v bankio 1.8v vccx 2.1v
	ret = vcc_cmds_tx(g_panel_info.pdev, g_bridge_disable_cmds, ARRAY_SIZE(g_bridge_disable_cmds));
	if (ret != 0) {
		DPU_FB_ERR("vcc disable failed!\n");
		return;
	}

	DPU_FB_INFO("-\n");
}

static struct lcd_kit_bridge_ops g_mipi_bridge_ops = {
	.pre_enable = bridge_pre_enable,
	.enable = bridge_enable,
	.disable = bridge_disable,
};

static int mipi_bridge_parse_device_dts(struct device_node *np)
{
	int ret = 0;
	int i = 0;
	struct device_node *dn = NULL;
	DPU_FB_INFO("+\n");

	if (!np) {
		DPU_FB_ERR("NOT FOUND device node %s!\n", "huawei,mipibridge_panel");
		return -ENODEV;
	}

	dn = of_get_child_by_name(np, g_panel_info.panel_name);
	if (!dn) {
		DPU_FB_ERR("NOT FOUND child node!\n");
		return -ENODEV;
	}

	for (i = 0; i < PANEL_DELAY_NUMS; i++) {
		ret = of_property_read_u32_index(dn, "enable_delays", i, &g_panel_info.enable_delays[i]);
		if (ret < 0) {
			DPU_FB_ERR("failed to get mipibridge enable_delays[%d]!\n", i);
			return -EINVAL;
		}
		ret = of_property_read_u32_index(dn, "disable_delays", i, &g_panel_info.disable_delays[i]);
		if (ret < 0) {
			DPU_FB_ERR("failed to get mipibridge disable_delays[%d]!\n", i);
			return -EINVAL;
		}
	}

	ret = of_property_read_u32(dn, "pmu_clk_support", &g_panel_info.pmu_clk_support);
	if (ret < 0) {
		DPU_FB_ERR("failed to get mipibridge pmu_clk_support!\n");
		return -EINVAL;
	}

	DPU_FB_INFO("-\n");
	return 0;
}

static int mipi_bridge_probe_support(void)
{
	int ret = 0;
	struct device_node *dn = NULL;
	int support = 0;
	char *lcd_name = NULL;

	dn = of_find_compatible_node(NULL, NULL, DTS_COMP_HUAWEI_LCD_PANEL_TYPE);
	if (!dn) {
		DPU_FB_ERR("NOT FOUND device node %s!\n", "huawei,lcd_panel_type");
		return -ENODEV;
	}

	lcd_name = (char *)of_get_property(dn, DTS_COMP_LCD_PANEL_TYPE, NULL);
	if (!lcd_name) {
		DPU_FB_ERR("NOT FOUND panel name !\n");
		return -ENODEV;
	}

	dn = of_find_compatible_node(NULL, NULL, lcd_name);
	if (!dn) {
		DPU_FB_ERR("NOT FOUND device node %s!\n", lcd_name);
		return -ENODEV;
	}

	ret = of_property_read_u32(dn, LCD_KIT_MIPI_BRIDGE_SUPPORT, &support);
	if (ret != 0) {
		DPU_FB_ERR("dts get support fail");
		return -EINVAL;
	}

	if (support) {
		DPU_FB_ERR("panel support bridge!\n");
		return 0;
	}
	DPU_FB_ERR("panel not support bridge!\n");
	return -EINVAL;
}

static int mipi_bridge_parse_dts(struct device_node *np)
{
	int ret = 0;
	char *panel_type = NULL;
	int len = 0;
	DPU_FB_INFO("+\n");

	if (!np) {
		DPU_FB_ERR("NOT FOUND device node %s!\n", "huawei,mipibridge_panel");
		return -ENODEV;
	}

	panel_type = (char *)of_get_property(np, "mipibridge_panel_type", NULL);
	if (!panel_type) {
		DPU_FB_ERR("NOT FOUND mipibridge_panel_type!\n");
		return -EINVAL;
	} else {
		len = strlen(panel_type);
		if (len > PANEL_IC_NAME_MAX - 1)
			len = PANEL_IC_NAME_MAX - 1;
		ret = strncpy_s(g_panel_info.panel_name, PANEL_IC_NAME_MAX, panel_type, len);
		if (ret != EOK) {
			DPU_FB_ERR("strncpy_s fail\n");
			return -EINVAL;
		}
		g_panel_info.panel_name[PANEL_IC_NAME_MAX - 1] = 0;
	}

	if (!strcmp(g_panel_info.panel_name, "hv6100")) {
		DPU_FB_INFO("bridge tyepe 0\n");
	} else if (!strcmp(g_panel_info.panel_name, "ug1009")) {
		DPU_FB_INFO("bridge tyepe 1\n");
	} else {
		DPU_FB_ERR("not find bridge type!\n");
		return -EINVAL;
	}

	ret = of_property_read_u32(np, "pin_rst", &g_panel_info.pin_rst);
	if (ret != 0) {
		DPU_FB_ERR("dts get pin_rst fail");
		return -EINVAL;
	}

	ret = mipi_bridge_parse_device_dts(np);
	if (ret != 0) {
		DPU_FB_ERR("mipi_bridge_parse_device_dts fail");
		return -EINVAL;
	}

	DPU_FB_INFO("-\n");
	return 0;
}

static int bridge_init(void)
{
	int ret = 0;

	DPU_FB_INFO("+\n");
	if (!g_panel_info.pdev) {
		DPU_FB_ERR("pdev is NULL!\n");
		return -ENODEV;
	}

	g_bridge_enable_cmds[VCCX].wait = g_panel_info.enable_delays[VCCX];
	g_bridge_enable_cmds[BANKIO].wait = g_panel_info.enable_delays[BANKIO];
	g_bridge_enable_cmds[VCC].wait = g_panel_info.enable_delays[VCC];
	g_bridge_gpio_on_cmds[0].wait = g_panel_info.enable_delays[RESET];

	g_bridge_disable_cmds[VCCX].wait = g_panel_info.disable_delays[VCCX];
	g_bridge_disable_cmds[BANKIO].wait = g_panel_info.disable_delays[BANKIO];
	g_bridge_disable_cmds[VCC].wait = g_panel_info.disable_delays[VCC];
	g_bridge_gpio_off_cmds[0].wait = g_panel_info.disable_delays[RESET];

	ret = vcc_cmds_tx(g_panel_info.pdev, g_bridge_init_cmds, ARRAY_SIZE(g_bridge_init_cmds));
	if (ret != 0) {
		DPU_FB_ERR("vcc init failed!\n");
		return -EIO;
	}

	ret = vcc_cmds_tx(g_panel_info.pdev, g_bridge_enable_cmds, ARRAY_SIZE(g_bridge_enable_cmds));
	if (ret != 0) {
		DPU_FB_ERR("vcc enable failed!\n");
		return -EIO;
	}

	ret = gpio_cmds_tx(g_bridge_gpio_request_cmds, ARRAY_SIZE(g_bridge_gpio_request_cmds));
	if (ret != 0) {
		DPU_FB_ERR("gpio request failed!\n");
		return -EIO;
	}

	DPU_FB_INFO("-\n");
	return 0;
}

static int mipi_bridge_panel_probe(struct platform_device *pdev)
{
	DPU_FB_INFO("+\n");
	g_panel_info.pdev = pdev;

	if (!g_panel_info.pdev) {
		DPU_FB_ERR("pdev is NULL!\n");
		return -EINVAL;
	}

	if (mipi_bridge_probe_support() < 0) {
		DPU_FB_ERR("mipi bridge probe not support !\n");
		return -EINVAL;
	}

	if (mipi_bridge_parse_dts(pdev->dev.of_node) < 0) {
		DPU_FB_ERR("mipi_bridge_parse_dts failed!\n");
		return -EINVAL;
	}

	if (bridge_init() < 0) {
		DPU_FB_ERR("bridge_init failed!\n");
		return -EINVAL;
	}

#ifdef CONFIG_LCD_KIT_DRIVER
	lcd_kit_bridge_register(&g_mipi_bridge_ops);
#endif

	DPU_FB_INFO("-\n");
	return 0;
}

static const struct of_device_id mipi_bridge_match_table[] = {
	{
		.compatible = "huawei,mipibridge_panel",
		.data = NULL,
	},
	{},
};
MODULE_DEVICE_TABLE(of, mipi_bridge_match_table);

static struct platform_driver this_driver = {
	.probe = mipi_bridge_panel_probe,
	.remove = NULL,
	.driver = {
		.name = "mipibridge_panel",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(mipi_bridge_match_table),
	},
};

static int __init mipi_bridge_panel_init(void)
{
	int ret = 0;

	ret = platform_driver_register(&this_driver);
	if (ret) {
		DPU_FB_ERR("platform_driver_register failed, error=%d!\n", ret);
		return ret;
	}

	return 0;
}

/*lint -restore*/
module_init(mipi_bridge_panel_init);
