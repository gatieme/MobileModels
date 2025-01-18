
// SPDX-License-Identifier: GPL-2.0
/*
 * hl7136.c
 *
 * hl7136 driver
 *
 * Copyright (c) 2023-2023 Hwat Technologies Co., Ltd.
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

#include "hl7136.h"
#include "hl7136_i2c.h"
#include "hl7136_scp.h"
#include "hl7136_ufcs.h"
#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/delay.h>
#include <linux/jiffies.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/io.h>
#include <linux/gpio.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/of_address.h>
#include <linux/of_gpio.h>
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/notifier.h>
#include <linux/mutex.h>
#include <linux/raid/pq.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/common_module/power_gpio.h>
#include <chipset_common/hwpower/direct_charge/direct_charger.h>
#include <huawei_platform/power/huawei_charger_common.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_pinctrl.h>
#include <chipset_common/hwpower/common_module/power_common_macro.h>
#include <securec.h>

#define HWLOG_TAG hl7136_chg
HWLOG_REGIST();

#define BUF_LEN                             80
#define HL7136_PAGE0_NUM                    0x12
#define HL7136_PAGE1_NUM                    0x07
#define HL7136_PAGE0_BASE                   HL7136_DEVICE_ID_REG
#define HL7136_PAGE1_BASE                   HL7136_SCP_CTL_REG
#define HL7136_DBG_VAL_SIZE                 6

static void hl7136_dump_register(struct hl7136_device_info *di)
{
	u8 i;
	int ret;
	u8 val = 0;

	for (i = HL7136_VBUS_OVP_REG; i <= HL7136_TRACK_OV_UV_REG; i++) {
		ret = hl7136_read_byte(di, i, &val);
		if (ret)
			hwlog_err("dump_register read fail\n");
		hwlog_info("reg [%x]=0x%x\n", i, val);
	}
}

static int hl7136_reg_reset(struct hl7136_device_info *di)
{
	int ret;
	u8 reg = 0;

	hl7136_write_mask(di, HL7136_CTRL2_REG, HL7136_CTRL2_SFT_RST_MASK,
		HL7136_CTRL2_SFT_RST_SHIFT, HL7136_CTRL2_SFT_RST_ENABLE);
	power_usleep(DT_USLEEP_10MS); /* wait soft reset ready */
	ret = hl7136_read_byte(di, HL7136_CTRL2_REG, &reg);
	if (ret)
		return -EPERM;

	hwlog_info("reg_reset [%x]=0x%x\n", HL7136_CTRL2_REG, reg);
	return 0;
}

static int hl7136_discharge(int enable, void *dev_data)
{
	int ret;
	u8 reg = 0;
	u8 value = enable ? DISCHRG_EN : DISCHRG_DIS;
	struct hl7136_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -EPERM;
	}

	/* VBUS_PD : 0(auto working), 1(manual pull down) */
	ret = hl7136_write_mask(di, HL7136_VIN_OVP_REG,
		HL7136_VBUS_OVP_VIN_PD_EN_MASK,
		HL7136_VBUS_OVP_VIN_PD_EN_SHIFT, value);
	if (ret)
		return -EPERM;

	ret = hl7136_read_byte(di, HL7136_VBUS_OVP_REG, &reg);
	if (ret)
		return -EPERM;

	hwlog_info("discharge [%x]=0x%x\n", HL7136_VBUS_OVP_REG, reg);
	return 0;
}

static int hl7136_is_device_close(void *dev_data)
{
	int ret;
	u8 reg = 0;
	struct hl7136_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -EPERM;
	}

	ret = hl7136_read_byte(di, HL7136_CTRL0_REG, &reg);
	if (ret)
		return -EPERM;

	if (reg & HL7136_CTRL0_CHG_EN_MASK)
		return 0;

	return 1;
}

static int hl7136_get_device_id(void *dev_data)
{
	int ret;
	u8 part_info = 0;
	struct hl7136_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -EPERM;
	}

	if (di->first_rd)
		return di->device_id;

	ret = hl7136_read_byte(di, HL7136_DEVICE_ID_REG, &part_info);
	if (ret) {
		hwlog_err("get_device_id read fail\n");
		return -EPERM;
	}
	hwlog_info("get_device_id [%x]=0x%x\n", HL7136_DEVICE_ID_REG, part_info);
	di->first_rd = true;

	part_info = part_info & HL7136_DEVICE_ID_DEV_ID_MASK;
	switch (part_info) {
	case HL7136_DEVICE_ID_HL7136:
		di->device_id = SWITCHCAP_HL7136;
		break;
	default:
		di->device_id = DC_DEVICE_ID_END;
		hwlog_err("switchcap get dev_id fail\n");
		break;
	}

	hwlog_info("device_id=0x%x\n", di->device_id);

	return di->device_id;
}

static int hl7136_get_sc_max_ibat(void *dev_data, int *ibat)
{
	struct hl7136_device_info *di = dev_data;

	if (!ibat || !di) {
		hwlog_err("ibat or di is null\n");
		return -ENODEV;
	}

	if (di->hl7136_sc_para.max_ibat <= 0) {
		hwlog_err("sc_max_ibat read fail\n");
		return -EPERM;
	}

	*ibat = di->hl7136_sc_para.max_ibat;
	hwlog_info("sc_max_ibat=%d\n", di->hl7136_sc_para.max_ibat);

	return 0;
}

static int hl7136_get_vbat_mv(void *dev_data)
{
	s16 voltage;
	u8 reg_high;
	u8 reg_low;
	u8 val[HL7136_ADC_REG_NUM] = {0}; /* read two bytes */
	struct hl7136_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -EPERM;
	}

	/* get the values of two registers: vbat_high and vbat_low */
	if (hl7136_read_block(di, val, HL7136_ADC_VBAT_0_REG, HL7136_ADC_REG_NUM))
		return -EPERM;
	reg_high = val[HL7136_ADC_REG_HIGH];
	reg_low = val[HL7136_ADC_REG_LOW] & HL7136_ADC_GET_VALID_NUM;

	/* VBAT ADC LBS: 1.25mV, vbat_low: bit4 to bit7 is null */
	voltage = ((reg_high << HL7136_ADC_INVALID_BIT) + reg_low) * 125 / 100;
	hwlog_info("vbat_high=0x%x, vbat_low=0x%x, voltage=%d\n", reg_high, reg_low, voltage);

	return (int)voltage;
}

static int hl7136_get_ibat_ma(int *ibat, void *dev_data)
{
	s16 curr;
	u8 reg_high;
	u8 reg_low;
	u8 val[HL7136_ADC_REG_NUM] = {0}; /* read two bytes */
	int sense_r_actual;
	struct hl7136_device_info *di = dev_data;

	if (!ibat || !di) {
		hwlog_err("ibat or di is null\n");
		return -EPERM;
	}

	/* get the values of two registers: ibat_high and ibat_low */
	if (hl7136_read_block(di, val, HL7136_ADC_IBAT_0_REG, HL7136_ADC_REG_NUM))
		return -EPERM;
	reg_high = val[HL7136_ADC_REG_HIGH];
	reg_low = val[HL7136_ADC_REG_LOW] & HL7136_ADC_GET_VALID_NUM;

	/* IBAT ADC LBS: 2.2mA, ibat_low: bit4 to bit7 is null */
	curr = ((reg_high << HL7136_ADC_INVALID_BIT) + reg_low) * 220 / 100;
	sense_r_actual = di->sense_r_actual > 0 ? di->sense_r_actual : SENSE_R_5_MOHM;
	*ibat = ((int)curr) * di->sense_r_config / sense_r_actual;
	hwlog_info("ibat_high=0x%x, ibat_low=0x%x, ibat=%d\n", reg_high, reg_low, *ibat);

	return 0;
}

static int hl7136_get_ibus_ma(int *iin, void *dev_data)
{
	s16 curr;
	u8 reg_high;
	u8 reg_low;
	int flag;
	u8 value = 0;
	u8 val[HL7136_ADC_REG_NUM] = {0}; /* read two bytes */
	struct hl7136_device_info *di = dev_data;

	if (!iin || !di) {
		hwlog_err("iin or di is null\n");
		return -EPERM;
	}

	/* get the values of two registers: ibus_high and ibus_low */
	if (hl7136_read_block(di, val, HL7136_ADC_IIN_0_REG, HL7136_ADC_REG_NUM))
		return -EPERM;
	reg_high = val[HL7136_ADC_REG_HIGH];
	reg_low = val[HL7136_ADC_REG_LOW] & HL7136_ADC_GET_VALID_NUM;

	/* ibus_low: bit4 to bit7 is null */
	curr = (reg_high << HL7136_ADC_INVALID_BIT) + reg_low;
	hl7136_read_byte(di, HL7136_CTRL3_REG, &value);
	flag = (value & HL7136_CTRL3_DEV_MODE_MASK) >> HL7136_CTRL3_DEV_MODE_SHIFT;
	if (flag == HL7136_CTRL3_BPMODE)
		*iin = (int)curr * 215 / 100; /* IBUS ADC LBS: 2.15mA */
	if (flag == HL7136_CTRL3_CPMODE)
		*iin = (int)curr * 110 / 100; /* IBUS ADC LBS: 1.1mA */
	hwlog_info("ibus_high=0x%x, ibus_low=0x%x, iin=%d\n", reg_high, reg_low, *iin);

	return 0;
}

int hl7136_get_vbus_mv(int *vin, void *dev_data)
{
	s16 voltage;
	u8 reg_high;
	u8 reg_low;
	u8 val[HL7136_ADC_REG_NUM] = {0}; /* read two bytes */
	struct hl7136_device_info *di = dev_data;

	if (!vin || !di) {
		hwlog_err("vin or di is null\n");
		return -EPERM;
	}

	/* get the values of two registers: vbus_high and vbus_low */
	if (hl7136_read_block(di, val, HL7136_ADC_VIN_0_REG, HL7136_ADC_REG_NUM))
		return -EPERM;
	reg_high = val[HL7136_ADC_REG_HIGH];
	reg_low = val[HL7136_ADC_REG_LOW] & HL7136_ADC_GET_VALID_NUM;

	/* VBUS ADC LBS: 4mV, vbus_low: bit4 to bit7 is null */
	voltage = ((reg_high << HL7136_ADC_INVALID_BIT) + reg_low) * HL7136_ADC_RESOLUTION_4;
	*vin = (int)voltage;
	hwlog_info("vbus_high=0x%x, vbus_low=0x%x, vin=%d\n", reg_high, reg_low, *vin);

	return 0;
}

static int hl7136_get_device_temp(int *temp, void *dev_data)
{
	int ret;
	u8 reg = 0;
	struct hl7136_device_info *di = dev_data;

	if (!temp || !di) {
		hwlog_err("temp or di is null\n");
		return -EPERM;
	}

	ret = hl7136_read_byte(di, HL7136_ADC_TDIE_0_REG, &reg);
	if (ret)
		return -EPERM;

	/* TDIE_ADC LSB: 0.0625C */
	*temp = (int)reg * 625 / 1000;
	hwlog_info("ADC_TDIE=0x%x, temp=%d\n", reg, *temp);

	return 0;
}

static int hl7136_set_nwatchdog(int disable, void *dev_data)
{
	int ret;
	u8 reg = 0;
	u8 value = disable ? DISWATCHDOG_EN : DISWATCHDOG_DIS;
	struct hl7136_device_info *di = dev_data;

	ret = hl7136_write_mask(di, HL7136_CTRL2_REG, HL7136_CTRL2_WD_DIS_MASK,
		HL7136_CTRL2_WD_DIS_SHIFT, value);
	if (ret)
		return -EPERM;

	ret = hl7136_read_byte(di, HL7136_CTRL2_REG, &reg);
	if (ret)
		return -EPERM;

	hwlog_info("watchdog [%x]=0x%x\n", HL7136_CTRL2_REG, reg);
	return 0;
}

static int hl7136_config_watchdog_ms(int time, void *dev_data)
{
	u8 val;
	int ret;
	u8 reg = 0;
	struct hl7136_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -EPERM;
	}

	if ((time == HL7136_WD_TMR_DISABLE) || (time > HL7136_WD_TMR_40000MS)) {
		hl7136_set_nwatchdog(1, di);
		return 0;
	}

	if (time > HL7136_WD_TMR_20000MS)
		val = HL7136_WD_SET_40000MS;
	else if (time > HL7136_WD_TMR_10000MS)
		val = HL7136_WD_SET_20000MS;
	else if (time > HL7136_WD_TMR_5000MS)
		val = HL7136_WD_SET_10000MS;
	else if (time > HL7136_WD_TMR_2000MS)
		val = HL7136_WD_SET_5000MS;
	else if (time > HL7136_WD_TMR_1000MS)
		val = HL7136_WD_SET_2000MS;
	else if (time > HL7136_WD_TMR_500MS)
		val = HL7136_WD_SET_1000MS;
	else if (time > HL7136_WD_TMR_200MS)
		val = HL7136_WD_SET_500MS;
	else
		val = HL7136_WD_SET_200MS;

	ret = hl7136_write_mask(di, HL7136_CTRL2_REG, HL7136_CTRL2_WD_TMR_MASK,
		HL7136_CTRL2_WD_TMR_SHIFT, val);
	ret += hl7136_read_byte(di, HL7136_CTRL2_REG, &reg);
	if (ret)
		return -EPERM;

	hl7136_set_nwatchdog(0, di);

	hwlog_info("config_watchdog_ms [%x]=0x%x\n", HL7136_CTRL2_REG, reg);
	return 0;
}

static int hl7136_config_rlt_uvp_ref(int rltuvp_rate, struct hl7136_device_info *di)
{
	u8 value;
	int ret;

	if (rltuvp_rate >= HL7136_TRACK_OV_UV_TRACK_UV_MAX)
		rltuvp_rate = HL7136_TRACK_OV_UV_TRACK_UV_MAX;

	value = (u8)((rltuvp_rate - HL7136_TRACK_OV_UV_TRACK_UV_MIN) /
		HL7136_TRACK_OV_UV_TRACK_UV_STEP);

	ret = hl7136_write_mask(di, HL7136_TRACK_OV_UV_REG, HL7136_TRACK_OV_UV_TRACK_UV_MASK,
		HL7136_TRACK_OV_UV_TRACK_UV_SHIFT, value);
	if (ret)
		return -EPERM;

	hwlog_info("config_rlt_uvp_ref [%x]=0x%x\n", HL7136_TRACK_OV_UV_REG, value);
	return 0;
}

static int hl7136_config_rlt_ovp_ref(int rltovp_rate, struct hl7136_device_info *di)
{
	u8 value;
	int ret;

	if (rltovp_rate >= HL7136_TRACK_OV_UV_TRACK_OV_MAX)
		rltovp_rate = HL7136_TRACK_OV_UV_TRACK_OV_MAX;

	value = (u8)((rltovp_rate - HL7136_TRACK_OV_UV_TRACK_OV_MIN) /
		HL7136_TRACK_OV_UV_TRACK_OV_STEP);

	ret = hl7136_write_mask(di, HL7136_TRACK_OV_UV_REG, HL7136_TRACK_OV_UV_TRACK_OV_MASK,
		HL7136_TRACK_OV_UV_TRACK_OV_SHIFT, value);
	if (ret)
		return -EPERM;

	hwlog_info("config_rlt_ovp_ref [%x]=0x%x\n", HL7136_TRACK_OV_UV_REG, value);
	return 0;
}

static int hl7136_config_vbat_ovp_ref_mv(int ovp_threshold, struct hl7136_device_info *di)
{
	u8 value;
	int ret;

	if (ovp_threshold < HL7136_VBAT_OVP_MIN)
		ovp_threshold = HL7136_VBAT_OVP_MIN;

	if (ovp_threshold > HL7136_VBAT_OVP_MAX)
		ovp_threshold = HL7136_VBAT_OVP_MAX;

	value = (u8)((ovp_threshold - HL7136_VBAT_OVP_MIN) /
		HL7136_VBAT_OVP_STEP);

	ret = hl7136_write_mask(di, HL7136_VBAT_REG_REG, HL7136_VBAT_REG_VBAT_REG_TH_MASK,
		HL7136_VBAT_REG_VBAT_REG_TH_SHIFT, value);
	if (ret)
		return -EPERM;

	hwlog_info("config_vbat_ovp_ref_mv [%x]=0x%x\n", HL7136_VBAT_REG_REG, value);
	return 0;
}

static int hl7136_config_ibat_ocp_ref_ma(int ocp_threshold, struct hl7136_device_info *di)
{
	u8 value;
	int ret;

	if (ocp_threshold < HL7136_IBAT_OCP_MIN)
		ocp_threshold = HL7136_IBAT_OCP_MIN;

	if (ocp_threshold > HL7136_IBAT_OCP_MAX)
		ocp_threshold = HL7136_IBAT_OCP_MAX;

	value = (u8)((ocp_threshold - HL7136_IBAT_OCP_MIN) /
		HL7136_IBAT_OCP_STEP);
	ret = hl7136_write_mask(di, HL7136_IBAT_REG_REG, HL7136_IBAT_REG_IBAT_REG_TH_MASK,
		HL7136_IBAT_REG_IBAT_REG_TH_SHIFT, value);
	if (ret)
		return -EPERM;

	hwlog_info("config_ibat_ocp_ref_ma [%x]=0x%x\n", HL7136_IBAT_REG_REG, value);
	return 0;
}

static int hl7136_config_ibat_reg_ref_ma(int ibat_regulation, struct hl7136_device_info *di)
{
	u8 value;
	int ret;

	if (ibat_regulation < HL7136_IBAT_OCP_TH_ABOVE_200MA)
		ibat_regulation = HL7136_IBAT_OCP_TH_ABOVE_200MA;

	if (ibat_regulation > HL7136_IBAT_OCP_TH_ABOVE_500MA)
		ibat_regulation = HL7136_IBAT_OCP_TH_ABOVE_500MA;

	value = (ibat_regulation - HL7136_IBAT_OCP_TH_ABOVE_200MA) / HL7136_IBAT_OCP_TH_ABOVE_STEP;
	ret = hl7136_write_mask(di, HL7136_REG_CTRL0_REG, HL7136_REG_CTRL0_IBAT_REG_TH_MASK,
		HL7136_REG_CTRL0_IBAT_REG_TH_SHIFT, value);
	if (ret)
		return -EPERM;

	hwlog_info("config_ibat_reg_regulation_mv [%x]=0x%x\n", HL7136_REG_CTRL0_REG, value);
	return 0;
}

int hl7136_config_vbuscon_ovp_ref_mv(int ovp_threshold, struct hl7136_device_info *di)
{
	u8 value;
	int ret;

	if (ovp_threshold < HL7136_VGS_SEL_MIN)
		ovp_threshold = HL7136_VGS_SEL_MIN;

	if (ovp_threshold > HL7136_VGS_SEL_MAX)
		ovp_threshold = HL7136_VGS_SEL_MAX;

	value = (u8)((ovp_threshold - HL7136_VGS_SEL_MIN) /
		HL7136_VGS_SEL_BASE_STEP);
	ret = hl7136_write_mask(di, HL7136_VBUS_OVP_REG, HL7136_VBUS_OVP_VGS_SEL_MASK,
		HL7136_VBUS_OVP_VGS_SEL_SHIFT, value);
	if (ret)
		return -EPERM;

	hwlog_info("config_ac_ovp_threshold_mv [%x]=0x%x\n", HL7136_VBUS_OVP_REG, value);
	return 0;
}

int hl7136_config_vbus_ovp_ref_mv(int ovp_threshold, struct hl7136_device_info *di)
{
	u8 value;
	int ret;

	if (ovp_threshold < HL7136_VBUS_OVP_MIN)
		ovp_threshold = HL7136_VBUS_OVP_MIN;

	if (ovp_threshold > HL7136_VBUS_OVP_MAX)
		ovp_threshold = HL7136_VBUS_OVP_MAX;

	value = (u8)((ovp_threshold - HL7136_VBUS_OVP_MIN) /
		HL7136_VBUS_OVP_STEP);
	ret = hl7136_write_mask(di, HL7136_VBUS_OVP_REG, HL7136_VBUS_OVP_VBUS_OVP_TH_MASK,
		HL7136_VBUS_OVP_VBUS_OVP_SHIFT, value);
	if (ret)
		return -EPERM;

	hwlog_info("config_vbus_ovp_ref_mv [%x]=0x%x\n", HL7136_VBUS_OVP_REG, value);
	return 0;
}

static int hl7136_config_ibus_ocp_ref_ma(int ocp_threshold, int chg_mode, struct hl7136_device_info *di)
{
	u8 value;
	int ret;

	if (chg_mode == LVC_MODE) {
		if (ocp_threshold < HL7136_IIN_OCP_BP_MIN)
			ocp_threshold = HL7136_IIN_OCP_BP_MIN;

		if (ocp_threshold > HL7136_IIN_OCP_BP_MAX)
			ocp_threshold = HL7136_IIN_OCP_BP_MAX;

		value = (u8)((ocp_threshold - HL7136_IIN_OCP_BP_MIN) /
			HL7136_IIN_OCP_BP_STEP);
	} else if (chg_mode == SC_MODE) {
		if (ocp_threshold < HL7136_IIN_OCP_CP_MIN)
			ocp_threshold = HL7136_IIN_OCP_CP_MIN;

		if (ocp_threshold > HL7136_IIN_OCP_CP_MAX)
			ocp_threshold = HL7136_IIN_OCP_CP_MAX;

		value = (u8)((ocp_threshold - HL7136_IIN_OCP_CP_MIN) /
			HL7136_IIN_OCP_CP_STEP);
	} else {
		hwlog_err("chg mode error:chg_mode=%d\n", chg_mode);
		return -EPERM;
	}

	ret = hl7136_write_mask(di, HL7136_IIN_REG_REG,
		HL7136_IIN_REG_IIN_REG_TH_MASK,
		HL7136_IIN_REG_IIN_REG_TH_SHIFT, value);
	if (ret)
		return -EPERM;

	hwlog_info("config_ibus_ocp_threshold_ma [%x]=0x%x\n",
		HL7136_IIN_REG_REG, value);
	return 0;
}

static int hl7136_config_vin_ovp_ref_ma(int ocp_threshold, int chg_mode, struct hl7136_device_info *di)
{
	u8 value;
	int ret;

	if (chg_mode == LVC_MODE) {
		if (ocp_threshold < HL7136_VIN_OVP_BP_MIN)
			ocp_threshold = HL7136_VIN_OVP_BP_MIN;

		if (ocp_threshold > HL7136_VIN_OVP_BP_MAX)
			ocp_threshold = HL7136_VIN_OVP_BP_MAX;

		value = (u8)((ocp_threshold - HL7136_VIN_OVP_BP_MIN) /
			HL7136_VIN_OVP_BP_STEP);
	} else if (chg_mode == SC_MODE) {
		if (ocp_threshold < HL7136_VIN_OVP_CP_MIN)
			ocp_threshold = HL7136_VIN_OVP_CP_MIN;

		if (ocp_threshold > HL7136_VIN_OVP_CP_MAX)
			ocp_threshold = HL7136_VIN_OVP_CP_MAX;

		value = (u8)((ocp_threshold - HL7136_VIN_OVP_CP_MIN) /
			HL7136_VIN_OVP_CP_STEP);
	} else {
		hwlog_err("chg mode error:chg_mode=%d\n", chg_mode);
		return -EPERM;
	}

	ret = hl7136_write_mask(di, HL7136_VIN_OVP_REG,
		HL7136_VIN_OVP_VIN_OVP_MASK,
		HL7136_VIN_OVP_VIN_OVP_SHIFT, value);
	if (ret)
		return -EPERM;

	hwlog_info("hl7136_config_vin_ovp_ref_ma [%x]=0x%x\n",
		HL7136_VIN_OVP_REG, value);
	return 0;
}

static int hl7136_config_switching_frequency(int data, void *dev_data)
{
	u8 freq;
	int ret;
	struct hl7136_device_info *di = dev_data;

	if (data < HL7136_SW_FREQ_MIN)
		data = HL7136_SW_FREQ_MIN;

	if (data > HL7136_SW_FREQ_MAX)
		data = HL7136_SW_FREQ_MAX;

	freq = (u8)((data - HL7136_SW_FREQ_MIN) / HL7136_SW_FREQ_STEP);

	ret = hl7136_write_mask(di, HL7136_CTRL0_REG, HL7136_CTRL0_FSW_SET_MASK,
		HL7136_CTRL0_FSW_SET_SHIFT, freq);
	if (ret)
		return -EPERM;

	hwlog_info("config_switching_frequency [%x]=0x%x\n",
		HL7136_CTRL0_REG, freq);

	return 0;
}

static void hl7136_lvc_opt_regs(struct hl7136_device_info *di)
{
	/* needed setting value */
	hl7136_config_rlt_ovp_ref(HL7136_TRACK_OV_UV_TRACK_OV_MAX, di);
	hl7136_config_rlt_uvp_ref(HL7136_TRACK_OV_UV_TRACK_UV_INIT, di);
	hl7136_config_vbuscon_ovp_ref_mv(HL7136_VGS_SEL_INIT, di);
	hl7136_config_vbus_ovp_ref_mv(HL7136_VBUS_OVP_INIT, di);
	hl7136_config_vin_ovp_ref_ma(HL7136_VIN_OVP_BP_INIT, LVC_MODE, di);
	hl7136_config_ibus_ocp_ref_ma(HL7136_IIN_OCP_BP_INIT, LVC_MODE, di); /* 6.5A */
	hl7136_config_vbat_ovp_ref_mv(HL7136_VBAT_OVP_INIT, di); /* 4.78V */
	hl7136_config_ibat_ocp_ref_ma(HL7136_IBAT_OCP_INIT, di); /* 8.3A  */
	hl7136_config_ibat_reg_ref_ma(HL7136_IBAT_OCP_TH_ABOVE_500MA, di);
}

static void hl7136_sc_opt_regs(struct hl7136_device_info *di)
{
	int ibus_ocp;

	/* needed setting value */
	ibus_ocp = (di->hl7136_sc_para.ibus_ocp > 0) ? di->hl7136_sc_para.ibus_ocp : HL7136_IIN_OCP_CP_INIT;

	hl7136_config_rlt_ovp_ref(HL7136_TRACK_OV_UV_TRACK_OV_MAX, di);
	hl7136_config_rlt_uvp_ref(HL7136_TRACK_OV_UV_TRACK_UV_INIT, di);
	hl7136_config_vbuscon_ovp_ref_mv(HL7136_VGS_SEL_INIT, di);
	hl7136_config_vbus_ovp_ref_mv(HL7136_VBUS_OVP_INIT, di);
	hl7136_config_vin_ovp_ref_ma(HL7136_VIN_OVP_CP_INIT, SC_MODE, di);
	hl7136_config_ibus_ocp_ref_ma(ibus_ocp, SC_MODE, di); /* 4.55A */
	hl7136_config_vbat_ovp_ref_mv(HL7136_VBAT_OVP_INIT, di); /* 4.78V */
	hl7136_config_ibat_ocp_ref_ma(HL7136_IBAT_OCP_INIT, di); /* 8.3A  */
	hl7136_config_ibat_reg_ref_ma(HL7136_IBAT_OCP_TH_ABOVE_500MA, di);
}

static int hl7136_lvc_charge_enable(int enable, void *dev_data)
{
	int ret;
	struct hl7136_device_info *di = dev_data;
	u8 value = enable ? HL7136_CTRL0_CHG_EN : HL7136_CTRL0_CHG_OFF;

	if (!di) {
		hwlog_err("di is null\n");
		return -EPERM;
	}

	if (enable)
		hl7136_lvc_opt_regs(di);
	else
		hl7136_dump_register(di);

	ret = hl7136_write_mask(di, HL7136_CTRL3_REG, HL7136_CTRL3_DEV_MODE_MASK,
		HL7136_CTRL3_DEV_MODE_SHIFT, HL7136_CTRL3_BPMODE);
	if (ret)
		return -EPERM;

	ret = hl7136_write_mask(di, HL7136_CTRL0_REG, HL7136_CTRL0_CHG_EN_MASK,
		HL7136_CTRL0_CHG_EN_SHIFT, value);
	if (ret)
		return -EPERM;

	return 0;
}

static int hl7136_sc_charge_enable(int enable, void *dev_data)
{
	int ret;
	u8 reg = 0;
	struct hl7136_device_info *di = dev_data;
	u8 value = enable ? HL7136_CTRL0_CHG_EN : HL7136_CTRL0_CHG_OFF;

	if (!di) {
		hwlog_err("di is null\n");
		return -EPERM;
	}

	if (enable)
		hl7136_sc_opt_regs(di);
	else
		hl7136_dump_register(di);

	ret = hl7136_write_mask(di, HL7136_CTRL3_REG, HL7136_CTRL3_DEV_MODE_MASK,
		HL7136_CTRL3_DEV_MODE_SHIFT, HL7136_CTRL3_CPMODE);
	if (ret)
		return -EPERM;

	ret = hl7136_write_mask(di, HL7136_CTRL0_REG, HL7136_CTRL0_CHG_EN_MASK,
		HL7136_CTRL0_CHG_EN_SHIFT, value);
	if (ret)
		return -EPERM;

	ret = hl7136_read_byte(di, HL7136_CTRL0_REG, &reg);
	hwlog_info("charge_enable [%x]=0x%x\n", HL7136_CTRL0_REG, reg);

	return 0;
}

static int hl7136_reg_less_leakage_current(struct hl7136_device_info *di)
{
	int ret;
	u8 reg = 0;
	u8 reg1 = 0;

	if (!di) {
		hwlog_err("di is null\n");
		return -EPERM;
	}

	ret = hl7136_write_mask(di, HL7136_CTRL2_REG, HL7136_CTRL2_WD_DIS_MASK,
		HL7136_CTRL2_WD_DIS_SHIFT, 0);
	ret += hl7136_write_mask(di, HL7136_CTRL2_REG, HL7136_CTRL2_WD_TMR_MASK,
		HL7136_CTRL2_WD_TMR_SHIFT, HL7136_WD_SET_2000MS);
	if (ret)
		return -EPERM;

	power_usleep(DT_USLEEP_10MS);
	ret = hl7136_write_mask(di, HL7136_ADC_CTRL0_REG, HL7136_ADC_CTRL0_ADC_MODE_CFG_MASK,
		HL7136_ADC_CTRL0_ADC_MODE_CFG_SHIFT, 1);
	if (ret)
		return -EPERM;

	ret = hl7136_read_byte(di, HL7136_CTRL2_REG, &reg);
	ret += hl7136_read_byte(di, HL7136_ADC_CTRL0_REG, &reg1);
	if (ret)
		return -EPERM;

	hwlog_info("leakage_current [%x] = 0x%x, [%x] = 0x%x\n",
		HL7136_CTRL2_REG, reg, HL7136_ADC_CTRL0_REG, reg1);

	return 0;
}

static int hl7136_chip_init(void *dev_data)
{
	return 0;
}

static int hl7136_threshold_reg_init(struct hl7136_device_info *di)
{
	int ret;

	ret = hl7136_config_rlt_ovp_ref(HL7136_TRACK_OV_UV_TRACK_OV_MIN, di);
	ret += hl7136_config_rlt_uvp_ref(HL7136_TRACK_OV_UV_TRACK_UV_MAX, di);
	ret += hl7136_config_vbat_ovp_ref_mv(HL7136_VBAT_OVP_INIT, di); /* VBAT_OVP 5V */
	ret += hl7136_config_ibat_ocp_ref_ma(HL7136_IBAT_OCP_INIT, di); /* IBAT_OCP 6.6A */
	ret += hl7136_config_vbuscon_ovp_ref_mv(HL7136_VGS_SEL_INIT, di);
	ret += hl7136_config_vbus_ovp_ref_mv(HL7136_VBUS_OVP_INIT, di);
	ret += hl7136_config_ibat_reg_ref_ma(HL7136_IBAT_OCP_TH_ABOVE_500MA, di);

	return ret;
}

static int hl7136_reg_init(struct hl7136_device_info *di)
{
	int ret;

	ret = hl7136_config_watchdog_ms(HL7136_WD_TMR_5000MS, di);
	ret += hl7136_set_nwatchdog(1, di);
	ret += hl7136_threshold_reg_init(di);
	ret += hl7136_config_switching_frequency(di->switching_frequency, di);
	ret += hl7136_write_byte(di, HL7136_INT1_MSK_REG, 0);
	ret += hl7136_write_byte(di, HL7136_INT2_MSK_REG, 0);
	ret += hl7136_write_byte(di, HL7136_INT3_MSK_REG, 0);

	/* mask scp protocol interrupts */
	ret += hl7136_write_byte(di, HL7136_SCP_MASK1_REG, HL7136_SCP_MASK);
	ret += hl7136_write_byte(di, HL7136_SCP_MASK2_REG, HL7136_SCP_MASK);

	ret += hl7136_write_mask(di, HL7136_VBUS_OVP_REG,
		HL7136_VBUS_OVP_VCTL_OFF_MASK, HL7136_VBUS_OVP_VCTL_OFF_SHIFT, 1);
	ret += hl7136_write_mask(di, HL7136_VIN_OVP_REG,
		HL7136_VIN_OVP_VIN_OVP_MASK, HL7136_VIN_OVP_VIN_OVP_SHIFT, 0x6);

	/* enable ENADC */
	ret += hl7136_write_mask(di, HL7136_ADC_CTRL0_REG,
		HL7136_ADC_CTRL0_ADC_AVG_TIME_MASK, HL7136_ADC_CTRL0_ADC_AVG_TIME_SHIFT, 2);
	ret += hl7136_write_mask(di, HL7136_ADC_CTRL0_REG,
		HL7136_ADC_CTRL0_ADC_READ_EN_MASK, HL7136_ADC_CTRL0_ADC_READ_EN_SHIFT, 1);

	/* enable automatic VBUS_PD */
	ret += hl7136_write_mask(di, HL7136_VIN_OVP_REG,
		HL7136_VBUS_OVP_VIN_PD_EN_MASK, HL7136_VBUS_OVP_VIN_PD_EN_SHIFT, 1);

	/* disable regulation */
	ret += hl7136_write_mask(di, HL7136_REG_CTRL0_REG, HL7136_REG_CTRL0_VBAT_REG_DIS_MASK,
		HL7136_REG_CTRL0_VBAT_REG_DIS_SHIFT, HL7136_REG_CTRL0_VBAT_REGULATION_OFF);
	ret += hl7136_write_mask(di, HL7136_REG_CTRL0_REG, HL7136_REG_CTRL0_IBAT_REG_DIS_MASK,
		HL7136_REG_CTRL0_IBAT_REG_DIS_SHIFT, HL7136_REG_CTRL0_IBAT_REGULATION_OFF);
	ret += hl7136_write_mask(di, HL7136_REG_CTRL1_REG, HL7136_REG_CTRL1_TDIE_REG_TH_MASK,
		HL7136_REG_CTRL1_TDIE_REG_TH_SHIFT, 3);
	ret += hl7136_write_mask(di, HL7136_CTRL1_REG, HL7136_CTRL1_VOUT_OVP_DIS_MASK,
		HL7136_CTRL1_VOUT_OVP_DIS_SHIFT, 1);

	ret += hl7136_write_mask(di, HL7136_CTRL1_REG, HL7136_CTRL1_UCP_DEB_SEL_MASK,
		HL7136_CTRL1_UCP_DEB_SEL_SHIFT, 1);
	ret += hl7136_write_mask(di, HL7136_CTRL0_REG, HL7136_CTRL0_IIN_UCP_TH_MASK,
		HL7136_CTRL0_IIN_UCP_TH_SHIFT, 1);
	ret += hl7136_write_mask(di, HL7136_UFCS_MASK1_REG, HL7136_UFCS_MASK1_SEND_PACKET_COMPLETE_MASK,
		HL7136_UFCS_MASK1_SEND_PACKET_COMPLETE_SHIFT, 1);

	ret += hl7136_write_mask(di, HL7136_VBAT_REG_REG, HL7136_VBAT_REG_TVBAT_OVP_DEB_MASK,
		HL7136_VBAT_REG_TVBAT_OVP_DEB_SHIFT, 1);
	ret += hl7136_write_mask(di, HL7136_IIN_REG_REG, HL7136_IIN_REG_IIN_OCP_DEB_MASK,
		HL7136_IIN_REG_IIN_OCP_DEB_SHIFT, 1);
	ret += hl7136_write_mask(di, HL7136_IBAT_REG_REG, HL7136_IBAT_REG_TIBAT_OCP_DEB_MASK,
		HL7136_IBAT_REG_TIBAT_OCP_DEB_SHIFT, 1);
	if (ret) {
		hwlog_err("reg_init fail\n");
		return -EPERM;
	}

	return 0;
}

static int hl7136_charge_init(void *dev_data)
{
	struct hl7136_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -EPERM;
	}

	if (hl7136_reg_init(di))
		return -EPERM;

	di->init_finish_flag = HL7136_INIT_FINISH;
	return 0;
}

static int hl7136_charge_exit(void *dev_data)
{
	int ret;
	struct hl7136_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -EPERM;
	}

	ret = hl7136_sc_charge_enable(HL7136_SWITCHCAP_DISABLE, di);
	di->init_finish_flag = HL7136_NOT_INIT;
	di->int_notify_enable_flag = HL7136_DISABLE_INT_NOTIFY;

	return ret;
}

static int hl7136_batinfo_exit(void *dev_data)
{
	return 0;
}

static int hl7136_batinfo_init(void *dev_data)
{
	struct hl7136_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -EPERM;
	}

	if (hl7136_chip_init(di)) {
		hwlog_err("batinfo init fail\n");
		return -EPERM;
	}

	return 0;
}

static int hl7136_db_value_dump(struct hl7136_device_info *di,
	char *reg_value, int size)
{
	int ret;
	char buff[BUF_LEN] = {0};
	int len = 0;
	u8 reg = 0;

	(void)hl7136_get_vbus_mv(&di->charge_data.vbus, di);
	(void)hl7136_get_ibat_ma(&di->charge_data.ibat, di);
	(void)hl7136_get_ibus_ma(&di->charge_data.ibus, di);
	(void)hl7136_get_device_temp(&di->charge_data.temp, di);
	(void)hl7136_read_byte(di, HL7136_CTRL3_REG, &reg);

	if (hl7136_is_device_close(di))
		ret = snprintf_s(buff, sizeof(buff), sizeof(buff) - 1, "%s", "OFF    ");
	else if (((reg & HL7136_CTRL3_DEV_MODE_MASK) >> HL7136_CTRL3_DEV_MODE_SHIFT) ==
		HL7136_CTRL3_BPMODE)
		ret = snprintf_s(buff, sizeof(buff), sizeof(buff) - 1, "%s", "LVC    ");
	else if (((reg & HL7136_CTRL3_DEV_MODE_MASK) >> HL7136_CTRL3_DEV_MODE_SHIFT) ==
		HL7136_CTRL3_CPMODE)
		ret = snprintf_s(buff, sizeof(buff), sizeof(buff) - 1, "%s", "SC     ");
	else
		ret = snprintf_s(buff, sizeof(buff), sizeof(buff) - 1, "%s", "BUCK   ");
	if (ret < 0)
		return 0;

	len += strlen(buff);
	if ((len < size) && (strncat_s(reg_value, size - 1, buff, strlen(buff)) != EOK))
		return 0;

	ret = snprintf_s(buff, sizeof(buff), sizeof(buff) - 1, "%-7d%-7d%-7d%-7d%-7d",
		di->charge_data.ibus, di->charge_data.vbus, di->charge_data.ibat,
		hl7136_get_vbat_mv(di), di->charge_data.temp);
	if (ret < 0)
		return 0;

	len += ret;
	if (strncat_s(reg_value, size - 1, buff, strlen(buff)) != EOK)
		return 0;

	return len;
}

static int hl7136_dump_reg_value(char *reg_value, int size, void *dev_data)
{
	int i;
	int len;
	int tmp;
	u8 reg_val = 0;
	int ret = 0;
	char buff[BUF_LEN] = {0};
	struct hl7136_device_info *di = dev_data;

	if (!di || !reg_value) {
		hwlog_err("di or reg_value is null\n");
		return -EPERM;
	}

	len = snprintf_s(reg_value, size, size - 1, "%-10s", di->name);
	if (len < 0)
		return -ENOMEM;
	len += hl7136_db_value_dump(di, buff, BUF_LEN);
	if ((len < size) && (strncat_s(reg_value, size - 1, buff, strlen(buff)) != EOK))
		return -ENOMEM;

	for (i = 0; i < HL7136_PAGE0_NUM; i++) {
		tmp = HL7136_PAGE0_BASE + i;
		if ((tmp == HL7136_INT1_REG) || (tmp == HL7136_INT_STS_A_REG) ||
			(tmp == HL7136_INT_STS_B_REG))
			continue;
		ret = ret || hl7136_read_byte(di, tmp, &reg_val);
		if (snprintf_s(buff, sizeof(buff), sizeof(buff) - 1, "0x%-7x", reg_val) < 0)
			return -ENOMEM;
		len += strlen(buff);
		if ((len < size) && (strncat_s(reg_value, size - 1, buff, strlen(buff)) != EOK))
			return -ENOMEM;
	}
	if (memset_s(buff, sizeof(buff), 0, sizeof(buff)) != EOK)
		return -ENOMEM;
	for (i = 0; i < HL7136_PAGE1_NUM; i++) {
		tmp = HL7136_PAGE1_BASE + i;
		if ((tmp == HL7136_SCP_ISR1_REG) || (tmp == HL7136_SCP_ISR2_REG))
			continue;
		ret = ret || hl7136_read_byte(di, tmp, &reg_val);
		if (snprintf_s(buff, sizeof(buff), sizeof(buff) - 1, "0x%-7x", reg_val) < 0)
			return -ENOMEM;
		len += strlen(buff);
		if ((len < size) && (strncat_s(reg_value, size - 1, buff, strlen(buff)) != EOK))
			return -ENOMEM;
	}

	return 0;
}

static int hl7136_reg_head(char *reg_head, int size, void *dev_data)
{
	int i;
	int tmp;
	int len = 0;
	char buff[BUF_LEN] = {0};
	const char *half_head = "dev       mode   Ibus   Vbus   Ibat   Vbat   Temp   ";
	struct hl7136_device_info *di = dev_data;

	if (!di || !reg_head) {
		hwlog_err("di or reg_head is null\n");
		return -EPERM;
	}

	if (snprintf_s(reg_head, size, size - 1, half_head) < 0)
		return -ENOMEM;
	len += strlen(half_head);

	if (memset_s(buff, sizeof(buff), 0, sizeof(buff)) != EOK)
		return -ENOMEM;
	for (i = 0; i < HL7136_PAGE0_NUM; i++) {
		tmp = HL7136_PAGE0_BASE + i;
		if ((tmp == HL7136_INT1_REG) || (tmp == HL7136_INT_STS_A_REG) ||
			(tmp == HL7136_INT_STS_B_REG))
			continue;
		if (snprintf_s(buff, sizeof(buff), sizeof(buff) - 1, "R[0x%3x] ", tmp) < 0)
			return -ENOMEM;
		len += strlen(buff);
		if ((len < size) && (strncat_s(reg_head, size - 1, buff, strlen(buff)) != EOK))
			return -ENOMEM;
	}

	if (memset_s(buff, sizeof(buff), 0, sizeof(buff)) != EOK)
		return -ENOMEM;
	for (i = 0; i < HL7136_PAGE1_NUM; i++) {
		tmp = HL7136_PAGE1_BASE + i;
		if ((tmp == HL7136_SCP_ISR1_REG) || (tmp == HL7136_SCP_ISR2_REG))
			continue;
		if (snprintf_s(buff, sizeof(buff), sizeof(buff) - 1, "R[0x%3x] ", tmp) < 0)
			return -ENOMEM;
		len += strlen(buff);
		if ((len < size) && (strncat_s(reg_head,  size - 1, buff, strlen(buff)) != EOK))
			return -ENOMEM;
	}

	return 0;
}

static int hl7136_reg_reset_and_init(void *dev_data)
{
	int ret;
	struct hl7136_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -EPERM;
	}

	ret = hl7136_reg_reset(di);
	ret += hl7136_reg_init(di);

	return ret;
}

static struct dc_ic_ops hl7136_lvc_ops = {
	.dev_name = "hl7136",
	.ic_init = hl7136_charge_init,
	.ic_exit = hl7136_charge_exit,
	.ic_enable = hl7136_lvc_charge_enable,
	.ic_discharge = hl7136_discharge,
	.is_ic_close = hl7136_is_device_close,
	.get_ic_id = hl7136_get_device_id,
	.config_ic_watchdog = hl7136_config_watchdog_ms,
	.ic_reg_reset_and_init = hl7136_reg_reset_and_init,
};

static struct dc_ic_ops hl7136_sc_ops = {
	.dev_name = "hl7136",
	.ic_init = hl7136_charge_init,
	.ic_exit = hl7136_charge_exit,
	.ic_enable = hl7136_sc_charge_enable,
	.ic_discharge = hl7136_discharge,
	.is_ic_close = hl7136_is_device_close,
	.get_ic_id = hl7136_get_device_id,
	.config_ic_watchdog = hl7136_config_watchdog_ms,
	.ic_reg_reset_and_init = hl7136_reg_reset_and_init,
	.get_max_ibat = hl7136_get_sc_max_ibat,
};

static struct dc_batinfo_ops hl7136_batinfo_ops = {
	.init = hl7136_batinfo_init,
	.exit = hl7136_batinfo_exit,
	.get_bat_btb_voltage = hl7136_get_vbat_mv,
	.get_bat_package_voltage = hl7136_get_vbat_mv,
	.get_vbus_voltage = hl7136_get_vbus_mv,
	.get_bat_current = hl7136_get_ibat_ma,
	.get_ic_ibus = hl7136_get_ibus_ma,
	.get_ic_temp = hl7136_get_device_temp,
};

static struct power_log_ops hl7136_log_ops = {
	.dev_name = "hl7136",
	.dump_log_head = hl7136_reg_head,
	.dump_log_content = hl7136_dump_reg_value,
};

static void hl7136_init_ops_dev_data(struct hl7136_device_info *di)
{
	if (memcpy_s(&di->lvc_ops, sizeof(struct dc_ic_ops), &hl7136_lvc_ops, sizeof(struct dc_ic_ops)) == EOK)
		di->lvc_ops.dev_data = (void *)di;
	if (memcpy_s(&di->sc_ops, sizeof(struct dc_ic_ops), &hl7136_sc_ops, sizeof(struct dc_ic_ops)) == EOK)
		di->sc_ops.dev_data = (void *)di;
	if (memcpy_s(&di->batinfo_ops, sizeof(struct dc_batinfo_ops),
		&hl7136_batinfo_ops, sizeof(struct dc_batinfo_ops)) == EOK)
		di->batinfo_ops.dev_data = (void *)di;
	if (memcpy_s(&di->log_ops, sizeof(struct power_log_ops), &hl7136_log_ops, sizeof(struct power_log_ops)) == EOK)
		di->log_ops.dev_data = (void *)di;

	if (!di->ic_role) {
		if (snprintf_s(di->name, HL7136_DEV_NAME_LEN, HL7136_DEV_NAME_LEN - 1, "hl7136") < 0)
			hwlog_err("dev name set fail\n");
	} else {
		if (snprintf_s(di->name, HL7136_DEV_NAME_LEN, HL7136_DEV_NAME_LEN - 1, "hl7136_%d", di->ic_role) < 0)
			hwlog_err("dev name set fail\n");
		di->lvc_ops.dev_name = di->name;
		di->sc_ops.dev_name = di->name;
		di->log_ops.dev_name = di->name;
	}
}

static void hl7136_ops_register(struct hl7136_device_info *di)
{
	int ret;

	hl7136_init_ops_dev_data(di);

	ret = dc_ic_ops_register(LVC_MODE, di->ic_role, &di->lvc_ops);
	ret += dc_ic_ops_register(SC_MODE, di->ic_role, &di->sc_ops);
	ret += dc_batinfo_ops_register(di->ic_role, &di->batinfo_ops, di->device_id);
	if (ret)
		hwlog_err("sysinfo ops register fail\n");

	ret = 0;
	if (di->param_dts.scp_support)
		ret = hl7136_hwscp_register(di);
	if (di->param_dts.fcp_support)
		ret += hl7136_hwfcp_register(di);
	if (di->param_dts.ufcs_support)
		ret += hl7136_ufcs_ops_register(di);
	if (ret)
		hwlog_err("scp or fcp or ufcs ops register fail\n");

	power_log_ops_register(&di->log_ops);
}

static void hl7136_fault_handle(struct hl7136_device_info *di,
	struct nty_data *data)
{
	int val = 0;
	u8 flag0 = data->event1;
	u8 flag1 = data->event2;
	u8 flag2 = data->event3;

	if (flag1 & HL7136_INT2_VBAT_OV_I_MASK) {
		val = hl7136_get_vbat_mv(di);
		if (val >=  HL7136_VBAT_OVP_INIT) {
			hwlog_info("VBAT_OVP happened\n");
			power_event_anc_notify(POWER_ANT_DC_FAULT,
				POWER_NE_DC_FAULT_VBAT_OVP, data);
		}
	}
	if (flag2 & HL7136_INT3_IBAT_OCP_I_MASK) {
		hwlog_info("IBAT_OCP happened\n");
		power_event_anc_notify(POWER_ANT_DC_FAULT,
			POWER_NE_DC_FAULT_IBAT_OCP, data);
	}
	if (flag1 & HL7136_INT2_VIN_OV_I_MASK) {
		hwlog_info("VIN_OVP happened\n");
		power_event_anc_notify(POWER_ANT_DC_FAULT,
			POWER_NE_DC_FAULT_VBUS_OVP, data);
	}
	if (flag2 & HL7136_INT3_IIN_OCP_I_MASK) {
		hwlog_info("IIN_REG happened\n");
		power_event_anc_notify(POWER_ANT_DC_FAULT,
			POWER_NE_DC_FAULT_IBUS_OCP, data);
	}
	if (flag0 & HL7136_INT1_TS_TEMP_I_MASK)
		hwlog_info("STATUS_B_THSD_STS happened\n");
}

static void hl7136_interrupt_clear(struct hl7136_device_info *di)
{
	u8 flag[5] = {0}; /* 5:read 5 byte */

	hwlog_info("irq_clear start\n");

	/* to confirm the interrupt */
	(void)hl7136_read_byte(di, HL7136_INT1_REG, &flag[0]);
	(void)hl7136_read_byte(di, HL7136_INT_STS_A_REG, &flag[1]);
	(void)hl7136_read_byte(di, HL7136_INT_STS_B_REG, &flag[2]);
	/* to confirm the scp interrupt */
	(void)hl7136_read_byte(di, HL7136_SCP_ISR1_REG, &flag[3]);
	(void)hl7136_read_byte(di, HL7136_SCP_ISR2_REG, &flag[4]);

	hwlog_info("INT_REG [%x]=0x%x, STATUS_A_REG [%x]=0x%x, STATUS_B_REG [%x]=0x%x\n",
		HL7136_INT1_REG, flag[0], HL7136_INT_STS_A_REG, flag[1], HL7136_INT_STS_B_REG, flag[2]);
	hwlog_info("ISR1 [%x]=0x%x, ISR2 [%x]=0x%x\n",
		HL7136_SCP_ISR1_REG, flag[3], HL7136_SCP_ISR2_REG, flag[4]);

	hwlog_info("irq_clear end\n");
}

static void hl7136_charge_work(struct work_struct *work)
{
	struct hl7136_device_info *di = NULL;
	struct nty_data *data = NULL;
	u8 int_data[3] = {0};
	u8 charger_int = 0;

	if (!work)
		return;

	di = container_of(work, struct hl7136_device_info, charge_work);
	if (!di || !di->client)
		return;

	(void)hl7136_read_byte(di, HL7136_INT_SRC, &charger_int);

	if (charger_int & HL7136_CHARGER_I_MASK) {
		(void) hl7136_read_block(di, int_data, HL7136_INT1_REG, HL7136_INT_NUM);
		data = &(di->nty_data);
		data->event1 = int_data[0];
		data->event2 = int_data[1];
		data->event3 = int_data[2];
		data->addr = di->client->addr;

		if (di->int_notify_enable_flag == HL7136_ENABLE_INT_NOTIFY) {
			hl7136_fault_handle(di, data);
			hwlog_info("INT_REG [%x]=0x%x, INT_REG [%x]=0x%x, INT_REG [%x]=0x%x\n",
				HL7136_INT1_REG, int_data[0], HL7136_INT2_REG, int_data[1],
				HL7136_INT3_REG, int_data[2]);
		}
	}
}

static void hl7136_interrupt_work(struct work_struct *work)
{
	struct hl7136_device_info *di = NULL;
	u8 ufcs_irq_int[2] = { 0 }; /* 2: two interrupt regs */
	u8 ufcs_irq[2] = {0};

	if (!work)
		return;

	di = container_of(work, struct hl7136_device_info, irq_work);
	if (!di || !di->client) {
		hwlog_err("di is null\n");
		return;
	}

	enable_irq(di->irq_int);

	if (hl7136_read_block(di, ufcs_irq_int, HL7136_UFCS_ISR1_REG, HL7136_UFCS_ISR_NUM))
		return;
	ufcs_irq[0] = ufcs_irq_int[HL7136_UFCS_ISR_HIGH];
	ufcs_irq[1] = ufcs_irq_int[HL7136_UFCS_ISR_LOW];

	if (ufcs_irq[0] & HL7136_UFCS_ISR1_HARD_RESET_MASK)
		power_event_bnc_notify(POWER_ANT_DC_FAULT,
			POWER_NE_DC_FAULT_AC_HARD_RESET, NULL);

	if (ufcs_irq[0] & HL7136_UFCS_ISR1_DATA_READY_MASK)
		hl7136_ufcs_add_msg(di);

	di->ufcs_irq[0] |= ufcs_irq[0];
	di->ufcs_irq[1] |= ufcs_irq[1];
	hwlog_info("UFCS_ISR1 [0x%x]=0x%x, UFCS_ISR2 [0x%x]=0x%x\n",
			HL7136_UFCS_ISR1_REG, ufcs_irq[0], HL7136_UFCS_ISR2_REG, ufcs_irq[1]);
	schedule_work(&di->charge_work);
}

static irqreturn_t hl7136_interrupt(int irq, void *_di)
{
	struct hl7136_device_info *di = _di;

	if (!di) {
		hwlog_err("di is null\n");
		return IRQ_HANDLED;
	}

	if (di->init_finish_flag == HL7136_INIT_FINISH)
		di->int_notify_enable_flag = HL7136_ENABLE_INT_NOTIFY;

	hwlog_info("int happened\n");

	disable_irq_nosync(di->irq_int);
	queue_work(system_highpri_wq, &di->irq_work);

	return IRQ_HANDLED;
}

static int hl7136_notifier_call(struct notifier_block *nb,
	unsigned long event, void *data)
{
	struct hl7136_device_info *di = container_of(nb, struct hl7136_device_info, event_nb);

	if (!di)
		return NOTIFY_OK;

	switch (event) {
	case POWER_NE_USB_DISCONNECT:
		di->ufcs_irq[0] = 0;
		di->ufcs_irq[1] = 0;
		di->plugged_state = false;
		hwlog_info("reset ic\n");
		break;
	case POWER_NE_USB_CONNECT:
		di->plugged_state = true;
		hl7136_ufcs_cancel_msg_update_work(di);
		break;
	default:
		break;
	}

	return NOTIFY_OK;
}

static int hl7136_irq_init(struct hl7136_device_info *di,
	struct device_node *np)
{
	int ret;

	INIT_WORK(&di->irq_work, hl7136_interrupt_work);
	INIT_WORK(&di->charge_work, hl7136_charge_work);

	ret = power_gpio_config_interrupt(np, "intr_gpio", "hl7136_gpio_int",
		&(di->gpio_int), &(di->irq_int));
	if (ret)
		return ret;

	ret = request_irq(di->irq_int, hl7136_interrupt,
		IRQF_TRIGGER_FALLING, "hl7136_int_irq", di);
	if (ret) {
		hwlog_err("gpio irq request failed\n");
		di->irq_int = -1;
		gpio_free(di->gpio_int);
		return ret;
	}

	enable_irq_wake(di->irq_int);
	return 0;
}

static void hl7136_parse_dts(struct device_node *np, struct hl7136_device_info *di)
{
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"switching_frequency", &di->switching_frequency,
		HL7136_SW_FREQ_900KHZ);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "scp_support",
		(u32 *)&(di->param_dts.scp_support), 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "fcp_support",
		(u32 *)&(di->param_dts.fcp_support), 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "ic_role",
		(u32 *)&(di->ic_role), IC_ONE);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"sense_r_config", &di->sense_r_config, SENSE_R_5_MOHM);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"sense_r_actual", &di->sense_r_actual, SENSE_R_5_MOHM);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "ufcs_support",
		(u32 *)&(di->param_dts.ufcs_support), 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "ignore_get_cable_info",
		(u32 *)&(di->ignore_get_cable_info), 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "less_leak_cur",
		(u32 *)&(di->less_leak_cur), 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "ufcs_read_buffer_delay",
		(u32 *)&(di->ufcs_read_buffer_delay), 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"manual_otg_mode", &di->manual_otg_mode, 0);
}

static void hl7136_init_lock_mutex(struct hl7136_device_info *di)
{
	mutex_init(&di->scp_detect_lock);
	mutex_init(&di->ufcs_detect_lock);
	mutex_init(&di->ufcs_node_lock);
	mutex_init(&di->accp_adapter_reg_lock);
}

static void hl7136_destroy_lock_mutex(struct hl7136_device_info *di)
{
	mutex_destroy(&di->scp_detect_lock);
	mutex_destroy(&di->ufcs_detect_lock);
	mutex_destroy(&di->ufcs_node_lock);
	mutex_destroy(&di->accp_adapter_reg_lock);
}

static int hl7136_parse_mode_para_dts(struct device_node *np,
	struct hl7136_mode_para *data, const char *name, int id)
{
	int array_len, col, row, idata;
	int index = -1; /* -1 : illegal value */
	const char *device_name = dc_get_device_name_without_mode(id);
	const char *tmp_string = NULL;

	array_len = power_dts_read_count_strings(power_dts_tag(HWLOG_TAG), np,
		name, HL7136_COMP_MAX_NUM, HL7136_INFO_TOTAL);
	if (array_len < 0)
		return -EPERM;

	for (row = 0; row < array_len / HL7136_INFO_TOTAL; row++) {
		col = row * HL7136_INFO_TOTAL + HL7136_INFO_IC_NAME;
		if (power_dts_read_string_index(power_dts_tag(HWLOG_TAG),
			np, name, col, &tmp_string))
			return -EPERM;

		if (!strcmp(tmp_string, device_name)) {
			if (strncpy_s(data->ic_name, CHIP_DEV_NAME_LEN, tmp_string, CHIP_DEV_NAME_LEN - 1) != EOK)
				return -ENOMEM;
			index = row;
			break;
		}

		if (!strcmp(tmp_string, "default")) {
			if (strncpy_s(data->ic_name, CHIP_DEV_NAME_LEN, tmp_string, CHIP_DEV_NAME_LEN - 1) != EOK)
				return -ENOMEM;
			index = row;
		}
	}

	if (index >= 0) {
		col = index * HL7136_INFO_TOTAL + HL7136_INFO_MAX_IBAT;
		power_dts_read_string_index(power_dts_tag(HWLOG_TAG),
			np, name, col, &tmp_string);
		kstrtoint(tmp_string, POWER_BASE_DEC, &idata);
		data->max_ibat = idata;
		col = index * HL7136_INFO_TOTAL + HL7136_INFO_IBUS_OCP;
		power_dts_read_string_index(power_dts_tag(HWLOG_TAG),
			np, name, col, &tmp_string);
		kstrtoint(tmp_string, POWER_BASE_DEC, &idata);
		data->ibus_ocp = idata;
	}

	return 0;
}

static int hl7136_otg_enable(struct hl7136_device_info *di, bool enable)
{
	int ret;
	u8 otg_en = enable ? HL7136_VBUS_OVP_ENABLED : HL7136_VBUS_OVP_AUTO;

	ret = hl7136_write_mask(di, HL7136_VBUS_OVP_REG,
		HL7136_VBUS_OVP_EXT_NFET_USE_MASK, HL7136_VBUS_OVP_EXT_NFET_USE_SHIFT, otg_en);
	if (ret)
		hwlog_err("otg enable fail enable = %d\n", enable);

	return ret;
}

static int hl7136_otg_notifier_call(struct notifier_block *nb, unsigned long event, void *data)
{
	struct hl7136_device_info *di = container_of(nb, struct hl7136_device_info, otg_nb);

	if (!di)
		return NOTIFY_OK;

	switch (event) {
	case POWER_NE_OTG_INSERT:
		hl7136_otg_enable(di, true);
		break;
	case POWER_NE_OTG_REMOVE:
		hl7136_otg_enable(di, false);
		break;
	default:
		break;
	}
	return NOTIFY_OK;
}

static int hl7136_notifier_register(struct hl7136_device_info *di)
{
	int ret;

	di->event_nb.notifier_call = hl7136_notifier_call;
	ret = power_event_bnc_register(POWER_BNT_CONNECT, &di->event_nb);
	if (ret)
		return ret;

	if (di->manual_otg_mode) {
		di->otg_nb.notifier_call = hl7136_otg_notifier_call;
		ret = power_event_bnc_register(POWER_BNT_OTG, &di->otg_nb);
		if (ret) {
			(void)power_event_bnc_unregister(POWER_BNT_CONNECT, &di->event_nb);
			return ret;
		}
	}

	return 0;
}

static int hl7136_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	int ret;
	struct hl7136_device_info *di = NULL;
	struct device_node *np = NULL;

	if (!client || !client->dev.of_node || !id)
		return -ENODEV;

	di = devm_kzalloc(&client->dev, sizeof(*di), GFP_KERNEL);
	if (!di)
		return -ENOMEM;

	di->dev = &client->dev;
	np = di->dev->of_node;
	di->client = client;
	di->chip_already_init = 1;
	hl7136_parse_dts(np, di);

	ret = hl7136_get_device_id(di);
	if ((ret < 0) || (ret == DC_DEVICE_ID_END))
		goto hl7136_fail_0;

	hl7136_parse_mode_para_dts(np, &di->hl7136_sc_para, "sc_para", di->device_id);

	hl7136_init_lock_mutex(di);
	hl7136_interrupt_clear(di);

	if (hl7136_notifier_register(di))
		goto hl7136_fail_1;

	ret = hl7136_reg_reset(di);
	ret += hl7136_reg_init(di);
	if (ret)
		goto hl7136_fail_2;

	init_completion(&di->hl7136_add_msg_completion);
	init_completion(&di->hl7136_ufcs_read_msg_completion);
	init_completion(&di->hl7136_ufcs_msg_update_completion);
	(void)power_pinctrl_config(di->dev, "pinctrl-names", 1); /* 1:pinctrl-names length */
	ret = hl7136_irq_init(di, np);
	if (ret)
		goto hl7136_fail_2;

	di->msg_update_wq = create_singlethread_workqueue("ufcs_msg_update_wq");
	INIT_DELAYED_WORK(&di->ufcs_msg_update_work, hl7136_ufcs_pending_msg_update_work);
	hl7136_ops_register(di);
	i2c_set_clientdata(client, di);
	return 0;

hl7136_fail_2:
	if (di->manual_otg_mode)
		(void)power_event_bnc_unregister(POWER_BNT_OTG, &di->otg_nb);
	(void)power_event_bnc_unregister(POWER_BNT_CONNECT, &di->event_nb);
hl7136_fail_1:
	hl7136_destroy_lock_mutex(di);
hl7136_fail_0:
	di->chip_already_init = 0;
	devm_kfree(&client->dev, di);

	return ret;
}

static int hl7136_remove(struct i2c_client *client)
{
	struct hl7136_device_info *di = i2c_get_clientdata(client);

	if (!di)
		return -ENODEV;

	if (di->manual_otg_mode)
		(void)power_event_bnc_unregister(POWER_BNT_OTG, &di->otg_nb);
	hl7136_reg_reset(di);

	if (di->irq_int)
		free_irq(di->irq_int, di);
	if (di->gpio_int)
		gpio_free(di->gpio_int);

	hl7136_ufcs_free_node_list(di, true);
	hl7136_destroy_lock_mutex(di);

	return 0;
}

static void hl7136_shutdown(struct i2c_client *client)
{
	struct hl7136_device_info *di = i2c_get_clientdata(client);

	if (!di)
		return;

	hl7136_reg_reset(di);

	if (di->less_leak_cur)
		hl7136_reg_less_leakage_current(di);

	if (di->irq_int)
		free_irq(di->irq_int, di);
	if (di->gpio_int)
		gpio_free(di->gpio_int);
}

MODULE_DEVICE_TABLE(i2c, hl7136);
static const struct of_device_id hl7136_of_match[] = {
	{
		.compatible = "hl7136",
		.data = NULL,
	},
	{},
};

static const struct i2c_device_id hl7136_i2c_id[] = {
	{ "hl7136", 0 }, {}
};

static struct i2c_driver hl7136_driver = {
	.probe = hl7136_probe,
	.remove = hl7136_remove,
	.shutdown = hl7136_shutdown,
	.id_table = hl7136_i2c_id,
	.driver = {
		.owner = THIS_MODULE,
		.name = "hl7136",
		.of_match_table = of_match_ptr(hl7136_of_match),
	},
};

static int __init hl7136_init(void)
{
	return i2c_add_driver(&hl7136_driver);
}

static void __exit hl7136_exit(void)
{
	i2c_del_driver(&hl7136_driver);
}

module_init(hl7136_init);
module_exit(hl7136_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("hl7136 module driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
