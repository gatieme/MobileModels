/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2022. All rights reserved.
 * Description: Device driver for schargerV700 adc
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include "scharger_v700_adc.h"
#include "scharger_v700.h"

#include <linux/slab.h>
#include <linux/device.h>
#include <linux/module.h>
#include <linux/io.h>
#include <linux/err.h>
#include <linux/platform_device.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/of_address.h>
#include <linux/of_gpio.h>
#include <linux/regmap.h>
#include <linux/delay.h>
#include <linux/time.h>
#include <securec.h>
#include <linux/power_supply.h>
#include <chipset_common/hwpower/common_module/power_dsm.h>
#include <linux/rtc.h>
#include <linux/timer.h>
#include <linux/time64.h>
#include <linux/timekeeping.h>

#ifndef abs
#define abs(a) ((a) > 0 ? (a) : -(a))  /* Absolute value */
#endif
#define DSM_BUFF_SIZE_MAX       1024
#define TIMESTAMP_STR_SIZE      32
#define SEC_PER_MIN             60
#define BASIC_YEAR              1900
#define BATT_NAME_SIZE_MAX      20
#define DMD_REPORT_INTERVAL     60000
static unsigned long g_dmd_time;

enum adc_mode {
	SINGLE_MODE,
	LOOP_MODE,
	EIS_MODE,
};

struct scharger_adc {
	struct device *dev;
	struct regmap *regmap;
	enum adc_mode mode;
	struct wakeup_source *wake_lock;
	struct mutex adc_conv_lock;
	int batt_temp_compensation_en;
	unsigned int scharger_version;
};

struct scharger_adc *g_adc = NULL;
char batt_l_name[BATT_NAME_SIZE_MAX];
char batt_h_name[BATT_NAME_SIZE_MAX];

/* mode: single = 0, loop = 1 */
static void adc_loop_mode_set(struct scharger_adc *adc , u32 en)
{
	int ret;

	ret = regmap_update_bits
		(adc->regmap, REG_HKADC_CTRL1, SC_HKADC_SEQ_LOOP_MASK, en << SC_HKADC_SEQ_LOOP_SHIFT);
	if(ret)
		dev_err(adc->dev, "%s, en %d error %d\n", __func__, en, ret);
}

/* mode: single, loop */
static void adc_eis_set(struct scharger_adc *adc , int eis_en)
{
	int ret;

	ret = regmap_update_bits
		(adc->regmap, REG_EIS_EN, SC_ADC_EIS_SEL_MASK, eis_en);
	if(ret)
		dev_err(adc->dev, "%s, eis_en %d error %d\n", __func__, eis_en, ret);
}

static void adc_enable(struct scharger_adc *adc , u32 en)
{
	int ret;

	ret = regmap_update_bits
		(adc->regmap, REG_HKADC_EN, SC_HKADC_EN_MASK, en);
	if(ret)
		dev_err(adc->dev, "%s, eis_en %d error %d\n", __func__, en, ret);

	/* close part of adc circuit when adc disable */
	if (adc->scharger_version == CHIP_ID_V700)
		return;
	else
		regmap_update_bits
			(adc->regmap, REG_SCHG_LOGIC_CFG_REG_5, CLOSE_PART_ADC_CIRCUIT_MSK, en << CLOSE_PART_ADC_CIRCUIT_SHIFT);
}

static void adc_loop_channel_set(struct scharger_adc *adc, int en)
{
	int ret = 0;
	unsigned char val_l = 0;
	unsigned char val_h = 0;

	if(en) {
		/* select all channel */
		val_l = 0xff;
		val_h = 0x0f;
	}
	ret += regmap_write(adc->regmap, REG_HKADC_SEQ_CH_L, val_l);
	ret += regmap_write(adc->regmap, REG_HKADC_SEQ_CH_H, val_h);
	if(ret)
		dev_err(adc->dev, "%s, error %d\n", __func__, ret);
}


static void adc_channel_set(struct scharger_adc *adc , unsigned int ch)
{
	u8 val_l = 0x00;
	u8 val_h = 0x00;
	int ret = 0;

	if (ch < CHG_ADC_CH_L_MAX)
		val_l = (1 << ch);
	else
		val_h = (1 << (ch - CHG_ADC_CH_L_MAX));

	if (ch == CHG_ADC_CH_IBUS)
		val_l |= (1 << (CHG_ADC_CH_IBUS_REF));

	ret += regmap_write(adc->regmap, REG_HKADC_SEQ_CH_L, val_l);
	ret += regmap_write(adc->regmap, REG_HKADC_SEQ_CH_H, val_h);
	if(ret)
		dev_err(adc->dev, "%s, ch %d error %d\n", __func__, ch, ret);
}

static void adc_start(struct scharger_adc *adc)
{
	int ret;

	ret = regmap_update_bits
		(adc->regmap, REG_EIS_HKADC_START, SC_EIS_HKADC_START_MASK, 1);
	if(ret)
		dev_err(adc->dev, "%s, error %d\n", __func__, ret);
}

static void adc_read_request(struct scharger_adc *adc)
{
	int ret;

	ret = regmap_update_bits(adc->regmap, REG_HKADC_RD_SEQ, SC_HKADC_RD_REQ, 1);
	if(ret)
		dev_err(adc->dev, "%s error %d\n", __func__, ret);
}

static void adc_read_data(struct scharger_adc *adc, int ch, unsigned short *adc_data)
{
	int ret;

	ret = regmap_bulk_read(adc->regmap, REG_ADC_DATA_BASE + (ADC_DATA_LEN * ch),
		adc_data, ADC_DATA_LEN);
	pr_err("%s: ch=%d, adc_data=%u", __func__, ch, *adc_data);
	if(ret){
		dev_err(adc->dev, "%s error %d\n", __func__, ret);
		*adc_data = 0;
	}
}

static void adc_loop_mode_enable(struct scharger_adc * adc, u32 en)
{
	if(adc->mode == (LOOP_MODE ^ en)) {
		dev_err(adc->dev, "%s en %d, pre mode %d\n", __func__, en, adc->mode);
		adc_loop_mode_set(adc, en);
		adc_eis_set(adc, 0);
		adc_enable(adc, en);
		adc_loop_channel_set(adc, en);
		if(en) {
			adc_start(adc);
			adc->mode = LOOP_MODE;
		} else {
			adc->mode = SINGLE_MODE;
		}
	}
}

static int adc_complete(struct scharger_adc * adc)
{
	int ret;
	unsigned int val = 0;
	int time = 10;

	while(!(val & HKADC_DATA_VALID_MASK) && time){
		mdelay(1);
		ret = regmap_read(adc->regmap, REG_HKADC_DATA_VALID, &val);
		time--;
	}

	if(time == 0)
		return -1;
	return 0;
}

static int adc_get_val_single(struct scharger_adc * adc, u32 ch, unsigned short *data)
{
	int timeout;
	int ret = 0;

	adc_eis_set(adc, 0);
	adc_enable(adc, 1);
	adc_channel_set(adc, ch);
	adc_start(adc);

	timeout = adc_complete(adc);
	if(timeout) {
		*data = 0;
		ret = -EINVAL;
		goto out;
	}

	adc_read_data(adc, ch, data);
out:
	adc_enable(adc, 0);
	return ret;
}

static int scharger_get_adc_value(struct scharger_adc * adc, u32 ch, unsigned short *data)
{
	int ret = 0;

	if(!adc) {
		pr_err("%s adc is null.\n", __func__);
		*data = 0;
		return -EINVAL;
	}

	mutex_lock(&adc->adc_conv_lock);
	__pm_stay_awake(adc->wake_lock);

	if(adc->mode == LOOP_MODE) {
		adc_read_request(adc);
		adc_read_data(adc, ch, data);
	} else {
		/* single mode */
		ret = adc_get_val_single(adc, ch, data);
	}

	__pm_relax(adc->wake_lock);
	mutex_unlock(&adc->adc_conv_lock);
	return ret;
}

static void get_battery_name(struct scharger_adc * adc)
{
	int ret = 0;
	struct device_node *coul_np = NULL;
	struct device_node *batt_l_np = NULL;
	struct device_node *batt_h_np = NULL;
	const char *batt_l = NULL;
	const char *batt_h = NULL;

	if (adc == NULL) {
		scharger_err("%s scharger_adc is NULL!\n", __func__);
		return;
	}
	coul_np = of_find_compatible_node(NULL, NULL, "hisilicon,schargerV700_coul");
	if (coul_np == NULL) {
		scharger_err("%s hisilicon,schargerV700_coul unfind\n", __func__);
		return;
	}
	batt_l_np = of_find_node_by_name(coul_np, "batt_l");
	if (batt_l_np == NULL) {
		scharger_err("%s batt_l not define in dts tree!", __func__);
		return;
	}
	batt_h_np = of_find_node_by_name(coul_np, "batt_h");
	if (batt_h_np == NULL) {
		scharger_err("%s batt_h not define in dts tree!", __func__);
		return;
	}

	ret = of_property_read_string(batt_l_np, "batt_name", &batt_l);
	if (ret) {
		(void)strcpy_s(batt_l_name, BATT_NAME_SIZE_MAX, "battery_gauge_aux");
		scharger_err("%s get batt_l_name fail, set default value %s\n", __func__, "battery_gauge_aux");
	} else {
		(void)strcpy_s(batt_l_name, BATT_NAME_SIZE_MAX, batt_l);
	}
	ret = of_property_read_string(batt_h_np, "batt_name", &batt_h);
	if (ret) {
		(void)strcpy_s(batt_h_name, BATT_NAME_SIZE_MAX, "battery_gauge");
		scharger_err("%s get batt_h_name fail, set default value %s\n", __func__, "battery_gauge");
	} else {
		(void)strcpy_s(batt_h_name, BATT_NAME_SIZE_MAX, batt_h);
	}
}

static int get_coul_vbat(const char *batt_name, int *vbat)
{
	int ret;
	struct power_supply *psy = NULL;
	union power_supply_propval val = {0};

	if (vbat == NULL)
		return -EINVAL;

	psy = power_supply_get_by_name(batt_name);
	if (!psy) {
		scharger_err("power supply %s not exist\n", batt_name);
		return -EINVAL;
	}

	ret = power_supply_get_property(psy, POWER_SUPPLY_PROP_VOLTAGE_NOW, &val);
	power_supply_put(psy);

	/* divide by 1000 for convert vbat unit to mv */
	*vbat = val.intval / 1000;
	return ret;
}

static int scharger_get_timestamp(char *str, int len)
{
	struct timespec64 tv = {0};
	struct rtc_time tm = {0};

	if (str == NULL) {
		scharger_err("%s input para is null\n", __func__);
		return -EINVAL;
	}

	ktime_get_real_ts64(&tv);
	tv.tv_sec -= (long)sys_tz.tz_minuteswest * SEC_PER_MIN;
	rtc_time64_to_tm(tv.tv_sec, &tm);

	(void)sprintf_s(str, len, "%04d-%02d-%02d %02d:%02d:%02d",
		 tm.tm_year + BASIC_YEAR, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour,
		 tm.tm_min, tm.tm_sec);

	return strlen(str);
}

static int scharger_dsm_report_coul_vbat_info(int err_num, const char *buff)
{
#ifdef CONFIG_HUAWEI_DSM
	char timestamp[TIMESTAMP_STR_SIZE] = {0};
	char dsm_buf[DSM_BUFF_SIZE_MAX] = {0};
	int tmp_len = 0;

	if (buff == NULL)
		return -1;

	scharger_get_timestamp(timestamp, TIMESTAMP_STR_SIZE);
	tmp_len += sprintf_s(dsm_buf, DSM_BUFF_SIZE_MAX, "%s\n", timestamp);
	tmp_len += sprintf_s(dsm_buf + tmp_len, DSM_BUFF_SIZE_MAX - tmp_len,
		"%s\n", buff);

	return power_dsm_report_dmd(POWER_DSM_BATTERY, err_num, dsm_buf);
#else
	return 0;
#endif
}

#ifdef CONFIG_HUAWEI_DSM
static void vbat_jump_report(const char *batt_name, int adc_vbat)
{
	int coul_vbat;
	int ret;
	char buff[DSM_BUFF_SIZE_MAX] = {0};
	unsigned long time;

	ret = get_coul_vbat(batt_name, &coul_vbat);
	if (ret) {
		scharger_err("%s get coul vbat fail\n", __func__);
		return;
	}

	/* The difference between adc_vbat and coul_vbat is greater than 40mv */
	if (adc_vbat > 3800 && abs(adc_vbat - coul_vbat) > 400) {
		scharger_inf("%s %s adc_vbat:%d, coul_vbat:%d, abnormal!\n", __func__,
			 batt_name, adc_vbat, coul_vbat);

		if (g_dmd_time != 0) {
			time = jiffies;
			if (!time_after(time, g_dmd_time + msecs_to_jiffies(DMD_REPORT_INTERVAL)))
				return;
		}
		g_dmd_time = jiffies;

		ret = sprintf_s(buff, (size_t)DSM_BUFF_SIZE_MAX,
			"[coul vbat jump]%s adc_vbat:%d, coul_vbat%d", batt_name, adc_vbat, coul_vbat);
		if (ret < 0) {
			scharger_err("%s sprintf_s fail\n", __func__);
			return;
		}

		scharger_dsm_report_coul_vbat_info(POWER_DSM_CHARGE_SCHARGER_FUEL_GAUGE_PRECISION_WARNING, buff);
	}
}
#endif

int scharger_get_sbu1_res(void)
{
	int val = 0;
	int ret = 0;

	if(!g_adc) {
		pr_err("%s adc is null.\n", __func__);
		return 0;
	}

	ret += regmap_write(g_adc->regmap, REG_SBU_DET_CFG, SBU1_10UA_DET);
	(void)scharger_get_adc_value(g_adc, CHG_ADC_CH_SBU, (unsigned short*)&val);
	ret += regmap_write(g_adc->regmap, REG_SBU_DET_CFG, SBU_DET_DIS);

	scharger_inf("[%s] %d\n", __func__, val);
	return val;
}

int scharger_get_sbu2_res(void)
{
	int val = 0;
	int ret = 0;

	if(!g_adc) {
		pr_err("%s adc is null.\n", __func__);
		return 0;
	}

	ret += regmap_write(g_adc->regmap, REG_SBU_DET_CFG, SBU2_10UA_DET);
	(void)scharger_get_adc_value(g_adc, CHG_ADC_CH_SBU, (unsigned short*)&val);
	ret += regmap_write(g_adc->regmap, REG_SBU_DET_CFG, SBU_DET_DIS);

	scharger_inf("[%s] %d\n", __func__, val);
	return val;
}

int scharger_get_dp_res(void)
{
	int val = 0;
	int ret = 0;

	if(!g_adc) {
		pr_err("%s adc is null.\n", __func__);
		return 0;
	}

	ret += regmap_write(g_adc->regmap, REG_DP_DET_CFG, DP_1UA_DET);
	(void)scharger_get_adc_value(g_adc, CHG_ADC_CH_VDP, (unsigned short*)&val);
	ret += regmap_write(g_adc->regmap, REG_DP_DET_CFG, DP_DET_DIS);

	scharger_inf("[%s] %d\n", __func__, val);
	return val;
}

int scharger_get_ibat_h(void)
{
	int val = 0;

	(void)scharger_get_adc_value(g_adc, CHG_ADC_CH_IBATH, (unsigned short*)&val);
	return val;
}

int scharger_get_ibat_l(void)
{
	int val = 0;

	(void)scharger_get_adc_value(g_adc, CHG_ADC_CH_IBATL, (unsigned short*)&val);
	return val;
}

int scharger_get_vbat_h(void)
{
	int val = 0;

	(void)scharger_get_adc_value(g_adc, CHG_ADC_CH_VBATH, (unsigned short*)&val);
	scharger_dbg("%s val %d\n", __func__, val);

#ifdef CONFIG_HUAWEI_DSM
	vbat_jump_report(batt_h_name, val);
#endif

	return val;
}

int scharger_get_vbat_l(void)
{
	int val = 0;

	(void)scharger_get_adc_value(g_adc, CHG_ADC_CH_VBATL, (unsigned short*)&val);
	scharger_dbg("%s val %d\n", __func__, val);

#ifdef CONFIG_HUAWEI_DSM
	vbat_jump_report(batt_l_name, val);
#endif

	return val;
}

int get_vbat_h(int *vbat)
{
	if (vbat == NULL) {
		pr_err("%s: input ibat is NULL\n", __func__);
		return -ENOMEM;
	}
	return scharger_get_adc_value(g_adc, CHG_ADC_CH_VBATH, (unsigned short*)vbat);
}

int get_vbat_l(int *vbat)
{
	if (vbat == NULL) {
		pr_err("%s: input ibat is NULL\n", __func__);
		return -ENOMEM;
	}
	return scharger_get_adc_value(g_adc, CHG_ADC_CH_VBATL, (unsigned short*)vbat);
}

int scharger_get_vbus(void)
{
	int val = 0;

	(void)scharger_get_adc_value(g_adc, CHG_ADC_CH_VBUS, (unsigned short*)&val);
	return val;
}

int scharger_adc_get_vbus(unsigned int *val)
{
	int ret;

	if (val == NULL) {
		pr_err("%s: input val is NULL\n", __func__);
		return -ENOMEM;
	}
	ret = scharger_get_adc_value(g_adc, CHG_ADC_CH_VBUS, (unsigned short*)val);

	scharger_dbg("%s val %d\n", __func__, *val);
	return ret;
}

int scharger_get_vpsw(void)
{
	int val = 0;

	(void)scharger_get_adc_value(g_adc, CHG_ADC_CH_VPSW, (unsigned short*)&val);
	return val;
}

int scharger_get_vusb(void)
{
	int val = 0;

	(void)scharger_get_adc_value(g_adc, CHG_ADC_CH_VUSB, (unsigned short*)&val);
	return val;
}

int scharger_adc_get_vusb(int *val)
{
	int ret;

	if (val == NULL) {
		pr_err("%s: input val is NULL\n", __func__);
		return -ENOMEM;
	}
	ret = scharger_get_adc_value(g_adc, CHG_ADC_CH_VUSB, (unsigned short*)val);

	scharger_dbg("%s val %d\n", __func__, val);

	return ret;
}

/* NTC Table */
static int t_v_table[][2] = {
	{ -273, 4095}, { -40, 3764}, { -36, 3689}, { -32, 3602}, { -28, 3500},
	{ -24, 3387}, { -20, 3261}, { -16, 3122}, { -12, 2973}, { -8, 2814},
	{ -4, 2650}, { 0, 2480}, { 4, 2308}, { 8, 2136}, { 12, 1967},
	{ 16, 1803}, { 20, 1646}, { 24, 1497}, { 28, 1360}, { 32, 1230},
	{ 36, 1111}, { 40, 1001}, { 44, 903}, { 48, 812}, { 52, 729},
	{ 56, 655}, { 60, 590}, { 64, 531}, { 74, 406}, { 84, 313},
	{ 125, 110}, { 0, 0},
};

static int charger_adc_to_temp(int temp_volt)
{
	int temprature = 0;
	int i;

	if (temp_volt >= t_v_table[0][1])
		return t_v_table[0][0];

	if (temp_volt <= t_v_table[T_V_ARRAY_LENGTH - 1][1])
		return t_v_table[T_V_ARRAY_LENGTH - 1][0];

	/* else */
	for (i = 0; i < T_V_ARRAY_LENGTH; i++) {
		if (temp_volt == t_v_table[i][1])
			return t_v_table[i][0];

		if (temp_volt > t_v_table[i][1])
			break;
	}
	if (i == 0)
		return t_v_table[0][0];

	if ((t_v_table[i][1] - t_v_table[i - 1][1]) != 0)
		temprature = t_v_table[i - 1][0] +
			(long)(temp_volt - t_v_table[i - 1][1]) *
				(t_v_table[i][0] - t_v_table[i - 1][0]) /
				(t_v_table[i][1] - t_v_table[i - 1][1]);

	return temprature;
}

static u32 battery_temp_compensation(struct scharger_adc *di,
	u32 adc_code)
{
	if (di->batt_temp_compensation_en == 0)
		goto no_compensation;

no_compensation:
	return adc_code;
}

static int _scharger_get_tsbat(u32 ch)
{
	int ret = 0;
	u32 adc_code = 0;
	u32 adc_code_new;
	int tbat;

	if (g_adc == NULL ) {
		scharger_err("[%s]\n", __func__);
		return 0;
	}

	ret = scharger_get_adc_value(g_adc, ch, (unsigned short*)&adc_code);
	if (ret) {
		scharger_err("[%s]get ts_bat fail,ret:%d\n", __func__, ret);
		return 0;
	}

	adc_code_new = battery_temp_compensation(g_adc, adc_code);
	tbat = charger_adc_to_temp(adc_code_new);
	scharger_inf("[%s]adc_code %d, adc_code_new %d, ts_bat %d\n",
			     __func__, adc_code, adc_code_new, tbat);
	return tbat;
}


int scharger_get_tsbat_h(void)
{
	int tsbat = 0;

	tsbat = _scharger_get_tsbat(CHG_ADC_CH_TSBATH);

	return tsbat;
}

int scharger_get_tsbat_l(void)
{
	int tsbat = 0;

	tsbat = _scharger_get_tsbat(CHG_ADC_CH_TSBATL);
	return tsbat;
}

int scharger_get_tdie(void)
{
	int val = 0;

	(void)scharger_get_adc_value(g_adc, CHG_ADC_CH_TDIE, (unsigned short*)&val);

	/*
	 * code val to actual val
	 * 2500: total range of temperature;
	 * 4096: 12 bits to record temperature, 2^12 = 4096;
	 * 1437277872: base value, for chip set
	 * 1000000: conversion scale
	 * 3406962: the reference value
	 */
	val = (2500 * val) / 4096;
	val = (int)(1437277872 - val * 1000000) / (3406962);

	return val;
}

int scharger_get_ibus(void)
{
	int val = 0;
	unsigned int ilimit = 0;
	int ret;

	ret = scharger_get_adc_value(g_adc, CHG_ADC_CH_IBUS, (unsigned short*)&val);
	if (ret) {
		scharger_err("[%s]get ibus fail,ret:%d\n", __func__, ret);
		return -1;
	}

	(void)regmap_read(g_adc->regmap, CHG_INPUT_SOURCE_REG, &ilimit);
	ilimit &= CHG_ILIMIT_MSK;
	ilimit >>= CHG_ILIMIT_SHIFT;
	if (ilimit < CHG_ILIMIT_600MA)
			val = val / CHG_IBUS_DIV;

	/* multiplied by 1045/1000 for IBUS ADC optimization precision */
	if (g_adc->scharger_version == CHIP_ID_V700)
		return val;
	else
		val = val * 1045 / 1000;

	return val;
}

int get_ibus(int *ibus)
{
	if (ibus == NULL) {
		pr_err("%s: input ibus is NULL\n", __func__);
		return -ENOMEM;
	}

	return scharger_get_adc_value(g_adc, CHG_ADC_CH_IBUS, (unsigned short*)ibus);
}

static unsigned int get_device_version(struct scharger_adc *adc)
{
	unsigned int scharger_version = 0;

	if (adc == NULL) {
		pr_err("%s scharger is null\n", __func__);
		return -EINVAL;
	}

	/* byte length of version 0 is 2 */
	(void)regmap_bulk_read(adc->regmap, CHIP_VERSION_4,
				&scharger_version, 2);

	pr_info("%s, chip version is 0x%x\n", __func__, scharger_version);
	return scharger_version;
}

static int scharger_adc_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct scharger_adc *adc = NULL;
	int ret = 0;

	adc = devm_kzalloc(dev, sizeof(*adc), GFP_KERNEL);
	if (!adc) {
		dev_err(dev, "[%s]adc is null.\n", __func__);
		return -ENOMEM;
	}

	adc->wake_lock = wakeup_source_register(dev, "scharger adc wakelock");
	mutex_init(&adc->adc_conv_lock);

	adc->dev = dev;
	adc->regmap = dev_get_regmap(dev->parent, NULL);
	if (!adc->regmap) {
		dev_err(dev, "Parent regmap unavailable.\n");
		return -ENXIO;
	}

	adc->scharger_version = get_device_version(adc);
	get_battery_name(adc);

	adc_loop_mode_enable(adc, 0);
	g_adc = adc;

	pr_err("[%s] succ\n", __func__);
	return ret;
}

static int scharger_adc_remove(struct platform_device *pdev)
{
	 g_adc = NULL;
	 return 0;
}

const static struct of_device_id scharger_v700_adc_of_match[] = {
	{
		.compatible = "hisilicon,scharger-v700-adc",
		.data = NULL,
	},
	{},
};

static struct platform_driver scharger_v700_adc_driver = {
	.driver = {
		.name	= "scharger_v700_adc",
		.owner  = THIS_MODULE,
		.of_match_table = scharger_v700_adc_of_match,
	},
	.probe	= scharger_adc_probe,
	.remove	= scharger_adc_remove,
};

static int __init scharger_adc_init(void)
{
	return platform_driver_register(&scharger_v700_adc_driver);
}

static void __exit scharger_adc_exit(void)
{
	platform_driver_unregister(&scharger_v700_adc_driver);
}

fs_initcall(scharger_adc_init);
module_exit(scharger_adc_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("schargerV700 adc driver");
