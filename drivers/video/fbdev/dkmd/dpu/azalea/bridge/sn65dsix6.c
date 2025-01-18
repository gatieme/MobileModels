/*
 * sn65dsix6.c
 *
 * operate function for sn65dsix6
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

#include "edp_bridge.h"
#include "sn65dsix6.h"
#include "linux/mfd/hisi_pmic.h"

#define MAX_CHIP_PROBE_TIMES	3

static struct i2c_config g_sn65dsi86_1920_config[] = {
	{0xFF, 0x07, DELAY_MS(0)},
	{0x16, 0x01, DELAY_MS(0)},
	{0xFF, 0x00, DELAY_MS(0)},
	{0x0A, 0x08, DELAY_MS(0)},
	{0x10, 0x26, DELAY_MS(0)},
	{0x12, 0x59, DELAY_MS(0)},
	{0x13, 0x59, DELAY_MS(0)},
	{0x94, 0x82, DELAY_MS(0)},
	{0x0D, 0x01, DELAY_MS(10)},
	{0x5A, 0x04, DELAY_MS(0)},
	{0x93, 0x20, DELAY_MS(0)},
	{0x96, 0x0A, DELAY_MS(20)},
	{0x20, 0x80, DELAY_MS(0)},
	{0x21, 0x07, DELAY_MS(0)},
	{0x22, 0x00, DELAY_MS(0)},
	{0x23, 0x00, DELAY_MS(0)},
	{0x24, 0x38, DELAY_MS(0)},
	{0x25, 0x04, DELAY_MS(0)},
	{0x2C, 0x2C, DELAY_MS(0)},
	{0x2D, 0x00, DELAY_MS(0)},
	{0x30, 0x05, DELAY_MS(0)},
	{0x31, 0x00, DELAY_MS(0)},
	{0x34, 0x94, DELAY_MS(0)},
	{0x36, 0x24, DELAY_MS(0)},
	{0x38, 0x58, DELAY_MS(0)},
	{0x3A, 0x04, DELAY_MS(0)},
	{0x5B, 0x00, DELAY_MS(0)},
	{0x3C, 0x02, DELAY_MS(0)},
	{0x5A, 0x0C, DELAY_MS(100)},
	{0x96, 0x0A, DELAY_MS(0)},
};

static struct i2c_config g_sn65dsi86_1600_config[] = {
	{0xFF, 0x07, DELAY_MS(0)},
	{0x16, 0x01, DELAY_MS(0)},
	{0xFF, 0x00, DELAY_MS(0)},
	{0x0A, 0x08, DELAY_MS(0)},
	{0x10, 0x26, DELAY_MS(0)},
	{0x12, 0x40, DELAY_MS(0)},
	{0x13, 0x40, DELAY_MS(0)},
	{0x94, 0x22, DELAY_MS(0)},
	{0x0D, 0x01, DELAY_MS(10)},
	{0x5A, 0x04, DELAY_MS(0)},
	{0x93, 0x20, DELAY_MS(0)},
	{0x96, 0x0A, DELAY_MS(20)},
	{0x20, 0x40, DELAY_MS(0)},
	{0x21, 0x06, DELAY_MS(0)},
	{0x22, 0x00, DELAY_MS(0)},
	{0x23, 0x00, DELAY_MS(0)},
	{0x24, 0x84, DELAY_MS(0)},
	{0x25, 0x03, DELAY_MS(0)},
	{0x2C, 0x50, DELAY_MS(0)},
	{0x2D, 0x00, DELAY_MS(0)},
	{0x30, 0x03, DELAY_MS(0)},
	{0x31, 0x00, DELAY_MS(0)},
	{0x34, 0x60, DELAY_MS(0)},
	{0x36, 0x60, DELAY_MS(0)},
	{0x38, 0x18, DELAY_MS(0)},
	{0x3A, 0x01, DELAY_MS(0)},
	{0x5B, 0x00, DELAY_MS(0)},
	{0x3C, 0x02, DELAY_MS(0)},
	{0x5A, 0x0C, DELAY_MS(100)},
	{0x96, 0x0A, DELAY_MS(0)},
};

static struct i2c_config g_sn65dsi86_1680_config[] = {
	{0xFF, 0x07, DELAY_MS(0)},
	{0x16, 0x01, DELAY_MS(0)},
	{0xFF, 0x00, DELAY_MS(0)},
	{0x0A, 0x08, DELAY_MS(0)},
	{0x10, 0x26, DELAY_MS(0)},
	{0x12, 0x57, DELAY_MS(0)},
	{0x13, 0x57, DELAY_MS(0)},
	{0x94, 0x82, DELAY_MS(0)},
	{0x0D, 0x01, DELAY_MS(10)},
	{0x5A, 0x04, DELAY_MS(0)},
	{0x93, 0x20, DELAY_MS(0)},
	{0x96, 0x0A, DELAY_MS(20)},
	{0x20, 0x90, DELAY_MS(0)},
	{0x21, 0x06, DELAY_MS(0)},
	{0x22, 0x00, DELAY_MS(0)},
	{0x23, 0x00, DELAY_MS(0)},
	{0x24, 0x1A, DELAY_MS(0)},
	{0x25, 0x04, DELAY_MS(0)},
	{0x2C, 0xB0, DELAY_MS(0)},
	{0x2D, 0x00, DELAY_MS(0)},
	{0x30, 0x06, DELAY_MS(0)},
	{0x31, 0x00, DELAY_MS(0)},
	{0x34, 0xFF, DELAY_MS(0)},
	{0x36, 0x1E, DELAY_MS(0)},
	{0x38, 0x68, DELAY_MS(0)},
	{0x3A, 0x03, DELAY_MS(0)},
	{0x5B, 0x00, DELAY_MS(0)},
	{0x3C, 0x02, DELAY_MS(0)},
	{0x5A, 0x0C, DELAY_MS(100)},
	{0x96, 0x0A, DELAY_MS(0)},
};

static struct i2c_config g_sn65dsi86_1152_config[] = {
	{0xFF, 0x07, DELAY_MS(0)},
	{0x16, 0x01, DELAY_MS(0)},
	{0xFF, 0x00, DELAY_MS(0)},
	{0x0A, 0x08, DELAY_MS(0)},
	{0x10, 0x26, DELAY_MS(0)},
	{0x12, 0x40, DELAY_MS(0)},
	{0x13, 0x40, DELAY_MS(0)},
	{0x94, 0x22, DELAY_MS(0)},
	{0x0D, 0x01, DELAY_MS(10)},
	{0x5A, 0x04, DELAY_MS(0)},
	{0x93, 0x20, DELAY_MS(0)},
	{0x96, 0x0A, DELAY_MS(20)},
	{0x20, 0x80, DELAY_MS(0)},
	{0x21, 0x04, DELAY_MS(0)},
	{0x22, 0x00, DELAY_MS(0)},
	{0x23, 0x00, DELAY_MS(0)},
	{0x24, 0x60, DELAY_MS(0)},
	{0x25, 0x03, DELAY_MS(0)},
	{0x2C, 0x80, DELAY_MS(0)},
	{0x2D, 0x00, DELAY_MS(0)},
	{0x30, 0x03, DELAY_MS(0)},
	{0x31, 0x00, DELAY_MS(0)},
	{0x34, 0xFF, DELAY_MS(0)},
	{0x36, 0x20, DELAY_MS(0)},
	{0x38, 0x40, DELAY_MS(0)},
	{0x3A, 0x01, DELAY_MS(0)},
	{0x5B, 0x00, DELAY_MS(0)},
	{0x3C, 0x02, DELAY_MS(0)},
	{0x5A, 0x0C, DELAY_MS(100)},
	{0x96, 0x0A, DELAY_MS(0)},
};

static struct i2c_config g_sn65dsi86_1024_75_config[] = {
	{0xFF, 0x07, DELAY_MS(0)},
	{0x16, 0x01, DELAY_MS(0)},
	{0xFF, 0x00, DELAY_MS(0)},
	{0x0A, 0x08, DELAY_MS(0)},
	{0x10, 0x26, DELAY_MS(0)},
	{0x12, 0x2F, DELAY_MS(0)},
	{0x13, 0x2F, DELAY_MS(0)},
	{0x94, 0x82, DELAY_MS(0)},
	{0x0D, 0x01, DELAY_MS(10)},
	{0x5A, 0x04, DELAY_MS(0)},
	{0x93, 0x10, DELAY_MS(0)},
	{0x96, 0x0A, DELAY_MS(20)},
	{0x20, 0x00, DELAY_MS(0)},
	{0x21, 0x04, DELAY_MS(0)},
	{0x22, 0x00, DELAY_MS(0)},
	{0x23, 0x00, DELAY_MS(0)},
	{0x24, 0x00, DELAY_MS(0)},
	{0x25, 0x03, DELAY_MS(0)},
	{0x2C, 0x60, DELAY_MS(0)},
	{0x2D, 0x00, DELAY_MS(0)},
	{0x30, 0x03, DELAY_MS(0)},
	{0x31, 0x00, DELAY_MS(0)},
	{0x34, 0xB0, DELAY_MS(0)},
	{0x36, 0x1C, DELAY_MS(0)},
	{0x38, 0x10, DELAY_MS(0)},
	{0x3A, 0x01, DELAY_MS(0)},
	{0x5B, 0x00, DELAY_MS(0)},
	{0x3C, 0x02, DELAY_MS(0)},
	{0x5A, 0x0C, DELAY_MS(100)},
	{0x96, 0x0A, DELAY_MS(0)},
};

static struct i2c_config g_sn65dsi86_1024_60_config[] = {
	{0xFF, 0x07, DELAY_MS(0)},
	{0x16, 0x01, DELAY_MS(0)},
	{0xFF, 0x00, DELAY_MS(0)},
	{0x0A, 0x08, DELAY_MS(0)},
	{0x10, 0x26, DELAY_MS(0)},
	{0x12, 0x27, DELAY_MS(0)},
	{0x13, 0x27, DELAY_MS(0)},
	{0x94, 0x82, DELAY_MS(0)},
	{0x0D, 0x01, DELAY_MS(10)},
	{0x5A, 0x04, DELAY_MS(0)},
	{0x93, 0x10, DELAY_MS(0)},
	{0x96, 0x0A, DELAY_MS(20)},
	{0x20, 0x00, DELAY_MS(0)},
	{0x21, 0x04, DELAY_MS(0)},
	{0x22, 0x00, DELAY_MS(0)},
	{0x23, 0x00, DELAY_MS(0)},
	{0x24, 0x00, DELAY_MS(0)},
	{0x25, 0x03, DELAY_MS(0)},
	{0x2C, 0x88, DELAY_MS(0)},
	{0x2D, 0x00, DELAY_MS(0)},
	{0x30, 0x06, DELAY_MS(0)},
	{0x31, 0x00, DELAY_MS(0)},
	{0x34, 0xA0, DELAY_MS(0)},
	{0x36, 0x1D, DELAY_MS(0)},
	{0x38, 0x18, DELAY_MS(0)},
	{0x3A, 0x03, DELAY_MS(0)},
	{0x5B, 0x00, DELAY_MS(0)},
	{0x3C, 0x02, DELAY_MS(0)},
	{0x5A, 0x0C, DELAY_MS(100)},
	{0x96, 0x0A, DELAY_MS(0)},
};

static struct i2c_config g_sn65dsi86_1280_60_config[] = {
	{0xFF, 0x07, DELAY_MS(0)},
	{0x16, 0x01, DELAY_MS(0)},
	{0xFF, 0x00, DELAY_MS(0)},
	{0x0A, 0x08, DELAY_MS(0)},
	{0x10, 0x26, DELAY_MS(0)},
	{0x12, 0x40, DELAY_MS(0)},
	{0x13, 0x40, DELAY_MS(0)},
	{0x94, 0x22, DELAY_MS(0)},
	{0x0D, 0x01, DELAY_MS(10)},
	{0x5A, 0x04, DELAY_MS(0)},
	{0x93, 0x20, DELAY_MS(0)},
	{0x96, 0x0A, DELAY_MS(20)},
	{0x20, 0x00, DELAY_MS(0)},
	{0x21, 0x05, DELAY_MS(0)},
	{0x22, 0x00, DELAY_MS(0)},
	{0x23, 0x00, DELAY_MS(0)},
	{0x24, 0x00, DELAY_MS(0)},
	{0x25, 0x04, DELAY_MS(0)},
	{0x2C, 0x70, DELAY_MS(0)},
	{0x2D, 0x00, DELAY_MS(0)},
	{0x30, 0x03, DELAY_MS(0)},
	{0x31, 0x00, DELAY_MS(0)},
	{0x34, 0xF8, DELAY_MS(0)},
	{0x36, 0x26, DELAY_MS(0)},
	{0x38, 0x30, DELAY_MS(0)},
	{0x3A, 0x01, DELAY_MS(0)},
	{0x5B, 0x00, DELAY_MS(0)},
	{0x3C, 0x02, DELAY_MS(0)},
	{0x5A, 0x0C, DELAY_MS(100)},
	{0x96, 0x0A, DELAY_MS(0)},
};

static struct i2c_config g_sn65dsi86_1280_75_config[] = {
	{0xFF, 0x07, DELAY_MS(0)},
	{0x16, 0x01, DELAY_MS(0)},
	{0xFF, 0x00, DELAY_MS(0)},
	{0x0A, 0x08, DELAY_MS(0)},
	{0x10, 0x26, DELAY_MS(0)},
	{0x12, 0x51, DELAY_MS(0)},
	{0x13, 0x51, DELAY_MS(0)},
	{0x94, 0x82, DELAY_MS(0)},
	{0x0D, 0x01, DELAY_MS(10)},
	{0x5A, 0x04, DELAY_MS(0)},
	{0x93, 0x20, DELAY_MS(0)},
	{0x96, 0x0A, DELAY_MS(20)},
	{0x20, 0x00, DELAY_MS(0)},
	{0x21, 0x05, DELAY_MS(0)},
	{0x22, 0x00, DELAY_MS(0)},
	{0x23, 0x00, DELAY_MS(0)},
	{0x24, 0x00, DELAY_MS(0)},
	{0x25, 0x04, DELAY_MS(0)},
	{0x2C, 0x90, DELAY_MS(0)},
	{0x2D, 0x00, DELAY_MS(0)},
	{0x30, 0x03, DELAY_MS(0)},
	{0x31, 0x00, DELAY_MS(0)},
	{0x34, 0xF8, DELAY_MS(0)},
	{0x36, 0x26, DELAY_MS(0)},
	{0x38, 0x10, DELAY_MS(0)},
	{0x3A, 0x01, DELAY_MS(0)},
	{0x5B, 0x00, DELAY_MS(0)},
	{0x3C, 0x02, DELAY_MS(0)},
	{0x5A, 0x0C, DELAY_MS(100)},
	{0x96, 0x0A, DELAY_MS(0)},
};

static struct i2c_config_table i2c_config_info_table[]= {
	{((int64_t)1920 << 40) + ((int64_t)1080 << 16) + (int64_t)60, g_sn65dsi86_1920_config},
	{((int64_t)1600 << 40) + ((int64_t)900 << 16) + (int64_t)60, g_sn65dsi86_1600_config},
	{((int64_t)1680 << 40) + ((int64_t)1050 << 16) + (int64_t)60, g_sn65dsi86_1680_config},
	{((int64_t)1152 << 40) + ((int64_t)864 << 16) + (int64_t)75, g_sn65dsi86_1152_config},
	{((int64_t)1024 << 40) + ((int64_t)768 << 16) + (int64_t)75, g_sn65dsi86_1024_75_config},
	{((int64_t)1024 << 40) + ((int64_t)768 << 16) + (int64_t)60, g_sn65dsi86_1024_60_config},
	{((int64_t)1280 << 40) + ((int64_t)1024 << 16) + (int64_t)75, g_sn65dsi86_1280_75_config},
	{((int64_t)1280 << 40) + ((int64_t)1024 << 16) + (int64_t)60, g_sn65dsi86_1280_60_config},
};

int is_sn65dsix6_onboard_klvv(struct mipi2edp *pdata)
{
	int i, ret, reg;

	/* check whether sn65dsix6 chip is on board */
	ret = 0;
	reg = 0;
	for (i = 0; i < MAX_CHIP_PROBE_TIMES; i++) {
		ret = regmap_read(pdata->regmap, SN_DEVICE_REV_REG, &reg);
		if (ret)
			continue;

		HISI_FB_INFO("sn65dsix6 is onboard! device_rev is 0x%x\n", reg);
		return ret;
	}


	HISI_FB_ERR("sn65dsix6 isn't onboard!\n");
	return ret;
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

void sn65dsi86_pre_enable(struct mipi2edp *pdata)
{
	HISI_FB_ERR("+");
	if (!pdata) {
		HISI_FB_ERR("pdata is nullptr!");
		return;
	}

	if (pdata->output == OUTPUT_VGA)
		return;

	/* wait for sn65dsi86 power up! */
	mdelay(1);
	/* configure bridge ref_clk */
	regmap_write(pdata->regmap, SN_DPPLL_SRC_REG, 0x08);

	regmap_update_bits(pdata->regmap, SN_HPD_DISABLE_REG, HPD_DISABLE,
		   HPD_DISABLE);
	/* wait for LCD inital finish! */

	mdelay(100);
	/* aux */
	regmap_write(pdata->regmap, SN_AUX_WDATA_REG(0), 0x01);
	regmap_write(pdata->regmap, SN_AUX_ADDR_19_16_REG, 0x00);
	regmap_write(pdata->regmap, SN_AUX_ADDR_15_8_REG, 0x01);
	regmap_write(pdata->regmap, SN_AUX_ADDR_7_0_REG, 0x0A);
	regmap_write(pdata->regmap, SN_AUX_LENGTH_REG, 0x01);
	regmap_write(pdata->regmap, SN_AUX_CMD_REG, 0x81);
	HISI_FB_ERR("-");
}

static void video_param_config(struct mipi2edp *pdata)
{
	regmap_write(pdata->regmap, 0x20, 0x70);
	regmap_write(pdata->regmap, 0x21, 0x08);
	regmap_write(pdata->regmap, 0x22, 0x00);
	regmap_write(pdata->regmap, 0x23, 0x00);
	regmap_write(pdata->regmap, 0x24, 0xA0);
	regmap_write(pdata->regmap, 0x25, 0x05);
	regmap_write(pdata->regmap, 0x2C, 0x20);
	regmap_write(pdata->regmap, 0x2D, 0x00);
	regmap_write(pdata->regmap, 0x30, 0x0A);
	regmap_write(pdata->regmap, 0x31, 0x00);
	regmap_write(pdata->regmap, 0x34, 0x50);
	regmap_write(pdata->regmap, 0x36, 0x1B);
	regmap_write(pdata->regmap, 0x38, 0x30);
	regmap_write(pdata->regmap, 0x3A, 0x03);
	regmap_write(pdata->regmap, 0x5B, 0x00);
	regmap_write(pdata->regmap, 0x3C, 0x00);
}

int sn65dsi86_config(struct mipi2edp *pdata)
{
	int64_t key;
	int count;
	int len;
	if (!pdata) {
		HISI_FB_ERR("pdata is nullptr!");
		return -EINVAL;
	}
	key = (((int64_t)(pdata->output_hdisplay)) << 40) + (((int64_t)(pdata->output_vdisplay)) << 16) + (int64_t)(pdata->output_vrefresh);
	len = sizeof(i2c_config_info_table) / sizeof(i2c_config_info_table[0]);
	HISI_FB_INFO("TI : sn65dsi86_hdisplay=%d_vrefresh=%d", pdata->output_hdisplay, pdata->output_vrefresh);
	for (count = 0; count < len; count++) {
		if (key == i2c_config_info_table[count].key) {
			sn65dsi86_config_i2c(pdata, i2c_config_info_table[count].config, SN65DSI86_CONFIG_LENGTH);
			HISI_FB_INFO("TI : sn65dsi86_config_i2c");
			return 0;
		}
	}
	HISI_FB_ERR("output_mode invalid");
	return -EINVAL;
}

int sn65dsi86_config_i2c(struct mipi2edp *pdata, struct i2c_config *sn65dsi86_config, int len)
{
	int count;
	mdelay(DELAY_MS(100));
	for (count = 0; count < len; count++) {
		regmap_write(pdata->regmap, sn65dsi86_config[count].registers, sn65dsi86_config[count].value);
		HISI_FB_INFO("TI : sn65dsi86_config_i2c count =%d registers=%d value=%d", count, sn65dsi86_config[count].registers, sn65dsi86_config[count].value);
		mdelay(sn65dsi86_config[count].delayms);
		if (sn65dsi86_config[count].delayms == DELAY_MS(10)) {
			HISI_FB_INFO("TI - sn65dsi86_enable! \n");
		}
	}
	return 0;
}

int sn65dsi86_enable(struct mipi2edp *pdata)
{
	int val = 0;
	int ret = 0;
	if (!pdata) {
		HISI_FB_ERR("pdata is nullptr!");
		return -EINVAL;
	}

	if (pdata->output == OUTPUT_VGA) {
		ret = sn65dsi86_config(pdata);
		return ret;
	}
	HISI_FB_ERR("+");
	/* DSI_A lane config */
	regmap_update_bits(pdata->regmap, SN_DSI_LANES_REG,
		CHA_DSI_LANES_MASK, 0x26);
	/* EQ for improve signal quality! */
	regmap_write(pdata->regmap, 0x11, 0xff);

	/* DP lane config */
	regmap_update_bits(pdata->regmap, SN_SSC_CONFIG_REG,
		DP_NUM_LANES_MASK, 0x34);
	regmap_update_bits(pdata->regmap, SN_DATARATE_CONFIG_REG,
		DP_DATARATE_MASK, 0x20);

	/* set dsi/dp clk frequency value */
	regmap_write(pdata->regmap, SN_DSIA_CLK_FREQ_REG,
		0x7C); /* 0x96 */

	/* regmap_update_bits(pdata->regmap, SN_DATARATE_CONFIG_REG,
	 * DP_DATARATE_MASK, DP_DATARATE(i))
	 */

	/* enable DP PLL */
	regmap_write(pdata->regmap, SN_PLL_ENABLE_REG, 1);

	ret = regmap_read_poll_timeout(pdata->regmap, SN_DPPLL_SRC_REG,
		val, val & DPPLL_SRC_DP_PLL_LOCK, 1000, 100 * 1000);
	if (ret) {
		HISI_FB_ERR("DP_PLL_LOCK polling failed, ret=%d!", ret);
		return ret;
	}

	/**
	 * The SN65DSI86 only supports ASSR Display Authentication method and
	 * this method is enabled by default. An eDP panel must support this
	 * authentication method. We need to enable this method in the eDP panel
	 * at DisplayPort address 0x0010A prior to link training.
	 */

	regmap_write(pdata->regmap, 0x95, 0x00);

	/* Semi auto link training mode */
	regmap_write(pdata->regmap, 0x5A, 0x05);
	regmap_write(pdata->regmap, 0x96, 0x02);
	regmap_write(pdata->regmap, 0x93, 0x34);

	regmap_write(pdata->regmap, 0x96, 0x0A);
	mdelay(10);
	regmap_write(pdata->regmap, 0x96, 0x0A);
	mdelay(10);

	ret = regmap_read_poll_timeout(pdata->regmap, SN_ML_TX_MODE_REG, val,
		val == ML_TX_MAIN_LINK_OFF || val == ML_TX_NORMAL_MODE,
		1000, 500 * 1000);
	if (ret) {
		HISI_FB_ERR("Training complete polling failed, ret=%d!", ret);
		return ret;
	} else if (val == ML_TX_MAIN_LINK_OFF) {
		HISI_FB_ERR("Link training failed, link is off, ret=%d!", ret);
		return ret;
	}

	regmap_write(pdata->regmap, SN_DATARATE_CONFIG_REG, 0x21);

	HISI_FB_INFO("Link training OK!");

	/* config video parameters */
	video_param_config(pdata);
	/* enable video stream */
	regmap_write(pdata->regmap, 0x5A, 0x0D);

	HISI_FB_ERR("-");
	return ret;
}

void sn65dsi86_disable(struct mipi2edp *pdata)
{
	/* disable video stream */
	regmap_update_bits(pdata->regmap, SN_ENH_FRAME_REG, VSTREAM_ENABLE, 0);
	/* semi auto link training mode OFF */
	regmap_write(pdata->regmap, SN_ML_TX_MODE_REG, 0);
	/* disable DP PLL */
	regmap_write(pdata->regmap, SN_PLL_ENABLE_REG, 0);
}

int ti_i2c_send_byte(char devaddr, const char regoffset, const char value)
{
	struct i2c_adapter *adap;
	int ret;
	char data[I2C_TRANSFER_LEN];
	struct i2c_msg msg[1];
	adap = i2c_get_adapter(I2C_CONTROLLER);
	if (!adap) {
		HISI_FB_ERR("ti_i2c_send_byte i2c_get_adapter err");
		return -ENODEV;
	}

	msg->addr = devaddr;
	msg->flags = 0;
	msg->len = I2C_TRANSFER_LEN;
	msg->buf = data;
	data[0] = regoffset;
	data[1] = value;

	ret = i2c_transfer(adap, msg, 1);
	HISI_FB_DEBUG("ti_i2c_send_byte regoffset = %d value=%d ret = %d \n", regoffset, value, ret);
	i2c_put_adapter(adap);
	if (ret == 1) {
		return 0;
	}
	return ret;
}

int ti_i2c_recv_byte(char devaddr, const char regoffset, char *value)
{
	struct i2c_adapter *adap;
	int ret;
	struct i2c_msg msg[2];

	adap = i2c_get_adapter(I2C_CONTROLLER);
	if (!adap) {
		HISI_FB_ERR("ti_i2c_recv_byte i2c_get_adapter err");
		return -ENODEV;
	}

	msg[0].addr = devaddr;
	msg[0].flags = 0;
	msg[0].len = 1;
	msg[0].buf = (__u8 *)&regoffset;

	msg[1].addr = devaddr;
	msg[1].flags = I2C_M_RD;
	msg[1].len = 1;
	msg[1].buf = value;
	ret = i2c_transfer(adap, msg, 2);
	HISI_FB_DEBUG("ti_i2c_send_byte regoffset=%d value=%d ret = %d \n", regoffset,value[0],ret);
	i2c_put_adapter(adap);
	if (ret == 2) {
		return 0;
	}
	return ret;
}
