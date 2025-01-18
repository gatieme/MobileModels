/*
 * edp_bridge.c
 *
 * i2c driver for mipi2edp bridge
 *
 * Copyright (c) 2018-2019 Huawei Technologies Co., Ltd.
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
#include <securec.h>

#include <linux/component.h>
#include <linux/pm_runtime.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/leds.h>
#include <linux/of_gpio.h>
#include <linux/err.h>
#include <linux/delay.h>
#include <linux/uaccess.h>
#include <linux/interrupt.h>
#include <linux/regmap.h>
#include <linux/semaphore.h>
#include <linux/backlight.h>
#include <linux/clk.h>
#include "linux/mfd/hisi_pmic.h"
#include "edp_bridge.h"
#include "sn65dsix6.h"
#include "lt9711a.h"
#include "lcd_kit_bridge.h"


#define  GPIO_ID_HIGH 0x01
#define  GPIO_ID_LOW  0x0

struct mipi2edp *g_bridge_pdata;

static struct mipi_info mipi2edp_panel_info_init_1920_1080 = {
	.dsi_bit_clk = 448,
	.hsa = 33,
	.hbp = 111,
	.hline_time = 1652,
	.vsa = 5,
	.vbp = 36,
	.vfp = 4,
	.dpi_hsize = 1442,
	.vactive_line = 1080
};

static struct mipi_info mipi2edp_panel_info_init_1920_1200_60 = {
	.dsi_bit_clk = 587,
	.hsa = 150,
	.hbp = 252,
	.hline_time = 1946,
	.vsa = 6,
	.vbp = 36,
	.vfp = 3,
	.dpi_hsize = 1442,
	.vactive_line = 1200
};

static struct mipi_info mipi2edp_panel_info_init_1680_1050_60 = {
	.dsi_bit_clk = 443,
	.hsa = 132,
	.hbp = 210,
	.hline_time = 1682,
	.vsa = 6,
	.vbp = 30,
	.vfp = 3,
	.dpi_hsize = 1262,
	.vactive_line = 1050
};

static struct mipi_info mipi2edp_panel_info_init_1600_900_60 = {
	.dsi_bit_clk = 328,
	.hsa = 60,
	.hbp = 72,
	.hline_time = 1352,
	.vsa = 3,
	.vbp = 96,
	.vfp = 1,
	.dpi_hsize = 1202,
	.vactive_line = 900
};

static struct mipi_info mipi2edp_panel_info_init_1280_1024_75 = {
	.dsi_bit_clk = 407,
	.hsa = 108,
	.hbp = 186,
	.hline_time = 1268,
	.vsa = 3,
	.vbp = 38,
	.vfp = 1,
	.dpi_hsize = 962,
	.vactive_line = 1024
};

static struct mipi_info mipi2edp_panel_info_init_1280_1024_60 = {
	.dsi_bit_clk = 328,
	.hsa = 84,
	.hbp = 186,
	.hline_time = 1268,
	.vsa = 3,
	.vbp = 38,
	.vfp = 1,
	.dpi_hsize = 962,
	.vactive_line = 1024
};

static struct mipi_info mipi2edp_panel_info_init_1152_864_75 = {
	.dsi_bit_clk = 328,
	.hsa = 96,
	.hbp = 192,
	.hline_time = 1202,
	.vsa = 3,
	.vbp = 32,
	.vfp = 1,
	.dpi_hsize = 866,
	.vactive_line = 864
};

static struct mipi_info mipi2edp_panel_info_init_1024_768_75 = {
	.dsi_bit_clk = 239,
	.hsa = 72,
	.hbp = 132,
	.hline_time = 986,
	.vsa = 3,
	.vbp = 28,
	.vfp = 1,
	.dpi_hsize = 770,
	.vactive_line = 768
};

static struct mipi_info mipi2edp_panel_info_init_1024_768_60 = {
	.dsi_bit_clk = 197,
	.hsa = 102,
	.hbp = 120,
	.hline_time = 1010,
	.vsa = 6,
	.vbp = 29,
	.vfp = 3,
	.dpi_hsize = 770,
	.vactive_line = 768
};

struct config_table mipi2edp_config_table[] = {
	{((int64_t)1920 << 40) + ((int64_t)1080 << 16) + (int64_t)60, &mipi2edp_panel_info_init_1920_1080},
	{((int64_t)1920 << 40) + ((int64_t)1200 << 16) + (int64_t)60, &mipi2edp_panel_info_init_1920_1200_60},
	{((int64_t)1680 << 40) + ((int64_t)1050 << 16) + (int64_t)60, &mipi2edp_panel_info_init_1680_1050_60},
	{((int64_t)1600 << 40) + ((int64_t)900 << 16) + (int64_t)60, &mipi2edp_panel_info_init_1600_900_60},
	{((int64_t)1280 << 40) + ((int64_t)1024 << 16) + (int64_t)75, &mipi2edp_panel_info_init_1280_1024_75},
	{((int64_t)1280 << 40) + ((int64_t)1024 << 16) + (int64_t)60, &mipi2edp_panel_info_init_1280_1024_60},
	{((int64_t)1152 << 40) + ((int64_t)864 << 16) + (int64_t)75, &mipi2edp_panel_info_init_1152_864_75},
	{((int64_t)1024 << 40) + ((int64_t)768 << 16) + (int64_t)75, &mipi2edp_panel_info_init_1024_768_75},
	{((int64_t)1024 << 40) + ((int64_t)768 << 16) + (int64_t)60, &mipi2edp_panel_info_init_1024_768_60}
};

static int ti_get_edid(struct mipi2edp *pdata, char *edid, int len)
{
	char res;
	int i;
	int top = 0;

	ti_i2c_send_byte(0x2C, 0x60, 0xA1);

	for(i = 0;i < len;i++) {
		ti_i2c_recv_byte(0x50, i, &res);
		edid[top++] = res;
		HISI_FB_ERR("edid regoffset=%d value=%d \n", i, res);
	}
	return 0;
}

int mipi2edp_panel_info_config(struct mipi2edp *pdata) {
	int64_t key;
	int count;
	int len;
	HISI_FB_INFO("+");
	if (!pdata) {
		HISI_FB_ERR("pdata is nullptr!");
		return -EINVAL;
	}
	len = sizeof(mipi2edp_config_table) / sizeof(mipi2edp_config_table[0]);
	key = (((int64_t)(pdata->output_hdisplay)) << 40) + (((int64_t)(pdata->output_vdisplay)) << 16) + (int64_t)(pdata->output_vrefresh);
	for (count = 0; count < len; count++) {
		if (key == mipi2edp_config_table[count].key) {
			mipi2edp_panel_diff_info_init(pdata, *(mipi2edp_config_table[count].mipi_config_info));
			return 0;
		}
	}
	HISI_FB_INFO("output_hdisplay = %d, output_vdisplay = %d, output_vrefresh = %d", pdata->output_hdisplay, pdata->output_vdisplay, pdata->output_vrefresh);
	HISI_FB_INFO("-");
	return -EINVAL;
}

int mipi2edp_panel_diff_info_init(struct mipi2edp *pdata, struct mipi_info mipi2edp_panel_info_init_data) {
	struct hisi_panel_info *pinfo = NULL;
	if (!pdata) {
		HISI_FB_ERR("pdata is nullptr!");
		return -EINVAL;
	}
	pinfo = &(pdata->panel_info);
	pinfo->mipi.dsi_bit_clk = mipi2edp_panel_info_init_data.dsi_bit_clk;
	pinfo->mipi.dsi_bit_clk_upt = mipi2edp_panel_info_init_data.dsi_bit_clk;
	pinfo->mipi.hsa = mipi2edp_panel_info_init_data.hsa;
	pinfo->mipi.hbp = mipi2edp_panel_info_init_data.hbp;
	pinfo->mipi.hline_time = mipi2edp_panel_info_init_data.hline_time;
	pinfo->mipi.vsa = mipi2edp_panel_info_init_data.vsa;
	pinfo->mipi.vbp = mipi2edp_panel_info_init_data.vbp;
	pinfo->mipi.vfp = mipi2edp_panel_info_init_data.vfp;
	pinfo->mipi.dpi_hsize = mipi2edp_panel_info_init_data.dpi_hsize;
	pinfo->mipi.vactive_line = mipi2edp_panel_info_init_data.vactive_line;
	HISI_FB_INFO("dsi_bit_clk = %d, hsa = %d, hbp = %d,hline_time = %d ,vsa= %d ,vbp= %d , \
	vfp= %d ,dpi_hsize= %d ,vactive_line= %d",pinfo->mipi.dsi_bit_clk, pinfo->mipi.hsa, pinfo->mipi.hbp, \
	pinfo->mipi.hline_time, pinfo->mipi.vsa, pinfo->mipi.vbp, pinfo->mipi.vfp, pinfo->mipi.dpi_hsize, pinfo->mipi.vactive_line);
	HISI_FB_INFO("type = %d, dsi_bit_clk_upt = %d, non_continue_en = %d, lane_nums = %d, color_mode = %d, vc = %d, \
	max_tx_esc_clk = %d, burst_mode = %d, phy_mode = %d, dsi_version = %d, dsi_timing_support = %d, ifbc_type = %d, pxl_clk_rate_div = %d",\
	pinfo->type, pinfo->mipi.dsi_bit_clk_upt, pinfo->mipi.non_continue_en, pinfo->mipi.lane_nums, pinfo->mipi.color_mode, \
	pinfo->mipi.vc, pinfo->mipi.max_tx_esc_clk, pinfo->mipi.burst_mode, pinfo->mipi.phy_mode, pinfo->mipi.dsi_version, \
	pinfo->mipi.dsi_timing_support, pinfo->ifbc_type, pinfo->pxl_clk_rate_div);
	return 0;
}

int mipi2edp_panel_comon_info_init(struct mipi2edp *pdata) {
	struct hisi_panel_info *pinfo = NULL;
	if (!pdata) {
		HISI_FB_ERR("pdata is nullptr!");
		return -EINVAL;
	}
	pinfo = &(pdata->panel_info);
	pinfo->type = PANEL_MIPI_VIDEO;
	pinfo->mipi.dsi_bit_clk_upt = pinfo->mipi.dsi_bit_clk;
	pinfo->mipi.non_continue_en = 0;
	pinfo->mipi.lane_nums = DSI_4_LANES;
	pinfo->mipi.color_mode = DSI_24BITS_1;
	pinfo->mipi.vc = 0;
	pinfo->mipi.max_tx_esc_clk = 10 * 1000000;
	pinfo->mipi.burst_mode = DSI_NON_BURST_SYNC_PULSES;
	pinfo->mipi.phy_mode = DPHY_MODE;
	pinfo->mipi.dsi_version = DSI_1_1_VERSION;
	pinfo->ifbc_type = IFBC_TYPE_NONE;
	pinfo->pxl_clk_rate_div = 1;
	return 0;
}

static void set_refclk1(int enable)
{
	if(enable) {
		/* enable 38M4 clock for bridge from pmu */
		hisi_pmic_reg_write(0xBF, 0x92);
		hisi_pmic_reg_write(0x42, 0x1);
		hisi_pmic_reg_write(0xa7, 0x5);
		hisi_pmic_reg_write(0x823, 0x0);
	} else {
		/* disable 38M4 clock for bridge from pmu */
		hisi_pmic_reg_write(0x42, 0x0);
		hisi_pmic_reg_write(0xa7, 0x0);
	}
}

/**********************************************************
 *  Function:       mipi2edp_bridge_pre_enable
 *  Discription:    pre_enable mopi2edp_bridge moudule
 *  Parameters:     struct drm_bridge *bridge
 *  return value:   none
 **********************************************************/
void mipi2edp_bridge_pre_enable(struct mipi2edp *pdata)
{

	HISI_FB_INFO("+");

	if (pdata->chip.pre_enable)
		pdata->chip.pre_enable(pdata);

	HISI_FB_INFO("-");
}


void mipi2edp_bridge_enable(struct mipi2edp *pdata)
{
	int ret;

	HISI_FB_INFO("+");

	if (pdata->chip.enable) {
		ret = pdata->chip.enable(pdata);
		if (ret)
			HISI_FB_INFO("bridge chip enable failed !!!");
	}
	if (pdata->output == OUTPUT_LCD) {

	} else if (pdata->output == OUTPUT_VGA){
		if (pdata->type == SN65DSIX6) {
			mdelay(20);
			ti_get_edid(pdata, pdata->edid_array, EDID_LEN);
		} else if (pdata->type == LT9711A) {
			mdelay(20);
			lt9711a_get_edid(pdata->edid_array, EDID_LEN);
		}
	}

	HISI_FB_INFO("-");
}


void mipi2edp_bridge_disable(struct mipi2edp *pdata)
{

	HISI_FB_INFO("+");
	if (pdata->chip.disable) {
		pdata->chip.disable(pdata);
	}
	HISI_FB_INFO("-");
}

void mipi2edp_bridge_post_disable(
	struct mipi2edp *pdata)
{
	HISI_FB_INFO("+");

	if(pdata->output == OUTPUT_LCD) {
		mdelay(500);
	}

	HISI_FB_INFO("-");
}

void bridge_power_off()
{
	HISI_FB_INFO("+\n");
	gpio_set_value(179, 0);
	mipi2edp_bridge_disable(g_bridge_pdata);
	gpio_set_value(180, 0);
	mdelay(2);
	gpio_set_value(2, 0);
	gpio_request(180, "lcd_en");
	gpio_direction_output(180, 0);
	gpio_direction_output(55, 0);
	mdelay(10);
	gpio_direction_output(102, 0);
	mdelay(10);
	gpio_set_value(15, 0);
	gpio_request(15, "3V3");
	gpio_direction_output(15, 0);
	HISI_FB_INFO("-\n");
}

void  mipi2edp_bridge_resume(struct device *dev)
{
	struct mipi2edp *pdata = dev_get_drvdata(dev);

	HISI_FB_INFO("mipi2edp bridge resume start");
	gpio_request(102, "1V2");
	gpio_direction_output(102, 1);
	gpio_set_value(102, 1);
	mdelay(10);

	gpio_request(55, "1V8");
	gpio_direction_output(55, 1);
	gpio_set_value(55, 1);
	mdelay(10);

	gpio_request(180, "lcd_en");
	gpio_direction_output(180, 1);
	gpio_set_value(180, 1);

	mdelay(15);

	gpio_request(2, "reset");
	gpio_direction_output(2, 1);
	gpio_set_value(2, 1);
	mdelay(2);

	HISI_FB_INFO("mipi2edp bridge resume end");
}

static int mipi2edp_probe_init(struct i2c_client *client, struct device **dev,
	struct mipi2edp **pdata)
{
	struct i2c_adapter *adapter = NULL;

	adapter = client->adapter;
	if (!i2c_check_functionality(adapter, I2C_FUNC_I2C)) {
		HISI_FB_ERR("failed to i2c_check_functionality!");
		return -EOPNOTSUPP;
	}
	*dev = &client->dev;
	*pdata = devm_kzalloc(*dev, sizeof(struct mipi2edp), GFP_KERNEL);
	if (!(*pdata)) {
		HISI_FB_ERR("failed to alloc i2c!");
		return -ENOMEM;
	}

	return 0;
}


static int get_func_ptr_for_chip(struct i2c_client *client, struct mipi2edp *pdata)
{
	if (client->addr == SN65DSIX6_I2C_ADDR) {
		pdata->type = SN65DSIX6;
		pdata->regmap_config = &sn65dsix6_regmap;
		pdata->chip.is_chip_onboard = is_sn65dsix6_onboard_klvv;
		pdata->chip.pre_enable = sn65dsi86_pre_enable;
		pdata->chip.enable = sn65dsi86_enable;
		pdata->chip.disable = sn65dsi86_disable;
		pdata->chip.post_disable = NULL;
	} else if (client->addr == LT9711A_I2C_ADDR) {
		pdata->type = LT9711A;
		pdata->regmap_config = &lt9711a_regmap;
		pdata->chip.is_chip_onboard = is_lt9711a_onboard_klvv;
		pdata->chip.pre_enable = NULL;
		pdata->chip.enable = NULL;
		pdata->chip.disable = NULL;
		pdata->chip.post_disable = NULL;
	} else {
		HISI_FB_ERR("i2c addr 0x%x is invalid!", client->addr);
		return -1;
	}
	return 0;
}

static int mipi2edp_regmap_init(struct i2c_client *client, struct mipi2edp *pdata)
{
	int ret = 0;

	pdata->regmap = devm_regmap_init_i2c(client, pdata->regmap_config);
	if (IS_ERR(pdata->regmap)) {
		HISI_FB_ERR("failed to regmap iit i2c!");
		ret = -ENOMEM;
	}
	return ret;
}

static int check_mipi2edp_onboard(struct mipi2edp *pdata)
{
	/* assume the chip is enaable in UEFI.
	 * check whether the mipi2edp bridge chip is onboard
	 */
	int ret = 0;

	if (pdata->chip.is_chip_onboard) {
		ret = pdata->chip.is_chip_onboard(pdata);
		if (ret < 0)
			HISI_FB_ERR("failed to find the bridge chip!");

	}
	return ret;
}

static int pdata_config(struct i2c_client *client, struct mipi2edp *pdata)
{
	int ret;

	ret = get_func_ptr_for_chip(client, pdata);
	if (ret)
		return ret;

	ret = mipi2edp_regmap_init(client, pdata);
	if (ret)
		return ret;

	ret = check_mipi2edp_onboard(pdata);
	if (ret)
		return ret;

	return 0;

}

static int gpio_set_config(struct mipi2edp *pdata, struct i2c_client *client)
{
	struct device_node *np = NULL;
	int ret = 0;

	pdata->output = OUTPUT_LCD;
	return ret;

}

static void bri_pre_enable(void) {
	mipi2edp_bridge_pre_enable(g_bridge_pdata);
}

static void bri_enable(void) {
	mipi2edp_bridge_enable(g_bridge_pdata);
}

static void bri_disable(void) {
	mipi2edp_bridge_disable(g_bridge_pdata);
}

static void bri_set_refclk(void) {
	if (g_bridge_pdata->type == SN65DSIX6)
		set_refclk1(1);
}

static void bri_refclk_off(void) {
	if (g_bridge_pdata->type == SN65DSIX6)
		set_refclk1(0);
}

static struct lcd_kit_bridge_ops bridge_ops = {
	.pre_enable = bri_pre_enable,
	.enable = bri_enable,
	.disable = bri_disable,
	.refclk_on = bri_set_refclk,
	.refclk_off = bri_refclk_off,
};

static int mipi2edp_i2c_probe(
	struct i2c_client *client,
	const struct i2c_device_id *id)
{
	struct mipi2edp *pdata = NULL;
	struct device *dev = NULL;
	int ret = -1;
	int error = 0;

	HISI_FB_INFO("+");

	ret = mipi2edp_probe_init(client, &dev, &pdata);
	if (ret)
		return ret;

	ret = pdata_config(client, pdata);
	if (ret < 0)
		goto err_out;

	pdata->client = client;
	i2c_set_clientdata(client, pdata);
	ret = gpio_set_config(pdata, client);
	if (ret < 0)
		goto err_out;

	g_bridge_pdata = pdata;
	HISI_FB_INFO("bridge type:%d\n",pdata->type);

#ifdef CONFIG_LCD_KIT_DRIVER
	lcd_kit_bridge_register(&bridge_ops);
#endif

	HISI_FB_INFO("-");

	return ret;

err_out:
	devm_kfree(&client->dev, pdata);

	return ret;
}

static int mipi2edp_i2c_remove(struct i2c_client *client)
{
	HISI_FB_INFO("+");

	if (!client) {
		HISI_FB_ERR("client is nullptr!");
		return -EINVAL;
	}

	HISI_FB_INFO("-");

	return 0;
}

static void mipi2edp_i2c_shutdown(struct i2c_client *client)
{
	struct device *dev = NULL;
	struct mipi2edp *pdata = NULL;

	HISI_FB_INFO("+");
    return;

	HISI_FB_INFO("-");
}


static const struct i2c_device_id mipi2edp_i2c_ids[] = {
	{ "ti,sn65dsix6_klvv", 0 },
	{ "lt,lt9711a_klvv", 0 },
	{ "lm36923", 0 },
	{}
};

static const struct of_device_id mipi2edp_i2c_of_ids[] = {
	{.compatible = "ti,sn65dsix6_klvv"},
	{.compatible = "lt,lt9711a_klvv"},
	{.compatible = "ti,lm36923"},
	{}
};


static struct i2c_driver mipi2edp_i2c_driver_klvv = {
	.driver = {
		.name = "mipi2edp_klvv",
		.of_match_table = mipi2edp_i2c_of_ids,
	},
	.id_table = mipi2edp_i2c_ids,
	.probe = mipi2edp_i2c_probe,
	.remove = mipi2edp_i2c_remove,
	.shutdown = mipi2edp_i2c_shutdown,
};


static int __init mipi2edp_init(void)
{
	int ret = 0;

	HISI_FB_INFO("+.");

	ret = i2c_add_driver(&mipi2edp_i2c_driver_klvv);
	if (ret) {
		HISI_FB_ERR("failed to i2c_add_driver, ret=%d!", ret);
		return ret;
	}

	HISI_FB_INFO("-.");

	return ret;
}
late_initcall(mipi2edp_init);

static void __exit mipi2edp_exit(void)
{
	HISI_FB_INFO("+.");
	i2c_del_driver(&mipi2edp_i2c_driver_klvv);
	HISI_FB_INFO("-.");
}
module_exit(mipi2edp_exit);

MODULE_ALIAS("huawei mipi2edp bridge module");
MODULE_DESCRIPTION("huawei mipi2edp bridge driver");
MODULE_LICENSE("GPL");

/*lint +e548 +e574 +e578*/
