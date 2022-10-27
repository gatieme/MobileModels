/*
 * bq25970.c
 *
 * bq25970 driver
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

#include "bq25970.h"
#include <securec.h>
#include <huawei_platform/power/common_module/power_platform.h>
#include <chipset_common/hwpower/power_i2c.h>
#include <chipset_common/hwpower/power_gpio.h>
#include <chipset_common/hwpower/power_log.h>
#include <chipset_common/hwpower/power_thermalzone.h>
#include <chipset_common/hwpower/power_algorithm.h>
#include <chipset_common/hwpower/power_delay.h>
#include <chipset_common/hwpower/power_printk.h>
#include <chipset_common/hwpower/power_event_ne.h>

#define HWLOG_TAG bq25970
#define INTERRUPT_HAPPENED_GPIO_VALUE 0

HWLOG_REGIST();

static int sc8551s_scp_adapter_reg_read(u8 *val, u8 reg, void *dev_data);
static int sc8551s_scp_adapter_reg_write(u8 val, u8 reg, void *dev_data);
static bool adp_plugout;

static void bq25970_fault_event_notify(unsigned long event, void *data);

static void bq25970_report_i2c_error(struct bq25970_device_info *di)
{
	struct nty_data *data = NULL;

	data = &(di->nty_data);
	data->addr = di->client->addr;
	data->ic_name = dc_get_device_name(di->device_id);
	data->ic_role = di->ic_role;
	bq25970_fault_event_notify(DC_FAULT_I2C_ERROR, data);
	return;
}

static int bq25970_write_byte(struct bq25970_device_info *di, u8 reg, u8 value)
{
	if (!di || (di->chip_already_init == 0)) {
		hwlog_err("chip not init\n");
		return -EIO;
	}

	if (power_i2c_u8_write_byte(di->client, reg, value)) {
		bq25970_report_i2c_error(di);
		return -1;
	}

	return 0;
}

static int bq25970_read_byte(struct bq25970_device_info *di, u8 reg, u8 *value)
{
	if (!di || (di->chip_already_init == 0)) {
		hwlog_err("chip not init\n");
		return -EIO;
	}

	if (power_i2c_u8_read_byte(di->client, reg, value)) {
		bq25970_report_i2c_error(di);
		return -1;
	}

	return 0;
}

static int bq25970_read_word(struct bq25970_device_info *di, u8 reg, s16 *value)
{
	u16 data = 0;

	if (!di || (di->chip_already_init == 0)) {
		hwlog_err("chip not init\n");
		return -EIO;
	}

	if (power_i2c_u8_read_word(di->client, reg, &data, true)) {
		bq25970_report_i2c_error(di);
		return -1;
	}

	*value = (s16)data;
	return 0;
}

static int bq25970_write_mask(struct bq25970_device_info *di,
	u8 reg, u8 mask, u8 shift, u8 value)
{
	int ret;
	u8 val = 0;

	ret = bq25970_read_byte(di, reg, &val);
	if (ret < 0)
		return ret;

	val &= ~mask;
	val |= ((value << shift) & mask);

	return bq25970_write_byte(di, reg, val);
}

static void bq25970_dump_register(struct bq25970_device_info *di)
{
	u8 i;
	int ret;
	u8 val = 0;

	if (!di)
		return;

	for (i = 0; i <= BQ2597X_DEGLITCH_REG; ++i) {
		ret = bq25970_read_byte(di, i, &val);
		if (ret)
			hwlog_err("dump_register read fail\n");

		hwlog_info("[ic:%d]reg [%x]=0x%x\n", di->ic_role, i, val);
	}
}

static int bq25970_reg_reset(struct bq25970_device_info *di)
{
	int ret;
	u8 reg = 0;

	ret = bq25970_write_mask(di, BQ2597X_CONTROL_REG,
		BQ2597X_REG_RST_MASK, BQ2597X_REG_RST_SHIFT,
		BQ2597X_REG_RST_ENABLE);
	if (ret)
		return -1;

	ret = bq25970_read_byte(di, BQ2597X_CONTROL_REG, &reg);
	if (ret)
		return -1;

	hwlog_info("[ic:%d]reg_reset [%x]=0x%x\n", di->ic_role, BQ2597X_CONTROL_REG, reg);
	return 0;
}

static int bq25970_fault_clear(struct bq25970_device_info *di)
{
	int ret;
	u8 reg = 0;

	ret = bq25970_read_byte(di, BQ2597X_FLT_FLAG_REG, &reg);
	if (ret)
		return -1;

	hwlog_info("[ic:%d]fault_flag [%x]=0x%x\n", di->ic_role, BQ2597X_FLT_FLAG_REG, reg);
	return 0;
}

static int bq25970_charge_enable(int enable, void *dev_data)
{
	int ret;
	u8 reg = 0;
	u8 value = enable ? 0x1 : 0x0;
	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;

	if (!di)
		return -1;

	ret = bq25970_write_mask(di, BQ2597X_CHRG_CTL_REG,
		BQ2597X_CHARGE_EN_MASK, BQ2597X_CHARGE_EN_SHIFT,
		value);
	if (ret)
		return -1;

	ret = bq25970_read_byte(di, BQ2597X_CHRG_CTL_REG, &reg);
	if (ret)
		return -1;

	hwlog_info("[ic:%d]charge_enable [%x]=0x%x\n", di->ic_role, BQ2597X_CHRG_CTL_REG, reg);
	return 0;
}

static int bq25970_adc_enable(int enable, void *dev_data)
{
	int ret;
	u8 reg = 0;
	u8 value = enable ? 0x1 : 0x0;
	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;

	if (!di)
		return -1;

	ret = bq25970_write_mask(di, BQ2597X_ADC_CTRL_REG,
		BQ2597X_ADC_CTRL_EN_MASK, BQ2597X_ADC_CTRL_EN_SHIFT,
		value);
	if (ret)
		return -1;

	ret = bq25970_read_byte(di, BQ2597X_ADC_CTRL_REG, &reg);
	if (ret)
		return -1;

	hwlog_info("[ic:%d]adc_enable [%x]=0x%x\n", di->ic_role, BQ2597X_ADC_CTRL_REG, reg);
	return 0;
}

static bool bq25970_is_adc_disabled(struct bq25970_device_info *di)
{
	u8 reg = 0;
	int ret;

	ret = bq25970_read_byte(di, BQ2597X_ADC_CTRL_REG, &reg);
	if (ret || !(reg & BQ2597X_ADC_CTRL_EN_MASK))
		return true;

	return false;
}

static int bq25970_discharge(int enable, void *dev_data)
{
	return 0;
}

static int bq25970_is_device_close(void *dev_data)
{
	u8 reg = 0;
	int ret;
	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;

	if (!di)
		return 1;

	ret = bq25970_read_byte(di, BQ2597X_CHRG_CTL_REG, &reg);
	if (ret)
		return 1;

	if (reg & BQ2597X_CHARGE_EN_MASK)
		return 0;

	return 1;
}

static int bq25970_get_device_id(void *dev_data)
{
	u8 part_info = 0;
	int ret;
	int read_devid_again_flag = 0;
	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;

	if (!di)
		return -1;

	if (di->get_id_time == BQ2597X_USED)
		return di->device_id;
read:
	di->get_id_time = BQ2597X_USED;
	ret = bq25970_read_byte(di, BQ2597X_PART_INFO_REG, &part_info);
	/* slave addr may not accces, try backup addr */
	if ((ret) && (di->i2c_recovery_addr)) {
		hwlog_err("read id fail, try to read other i2c addr %x\n", di->i2c_recovery_addr);
		di->client->addr = di->i2c_recovery_addr;
		ret = bq25970_read_byte(di, BQ2597X_PART_INFO_REG, &part_info);
	}
	if (ret) {
		di->get_id_time = BQ2597X_NOT_USED;
		hwlog_err("get_device_id read fail\n");
		return -1;
	}
	hwlog_info("[ic:%d]get_device_id [%x]=0x%x\n", di->ic_role,
		BQ2597X_PART_INFO_REG, part_info);

	part_info = part_info & BQ2597X_DEVICE_ID_MASK;
	switch (part_info) {
	case BQ2597X_DEVICE_ID_RT9759:
		return -1;
	case BQ2597X_DEVICE_ID_BQ25970:
		di->device_id = SWITCHCAP_TI_BQ25970;
		break;
	case BQ2597X_DEVICE_ID_SC8551:
		di->device_id = SWITCHCAP_SC8551;
		break;
	case BQ2597X_DEVICE_ID_HL1530:
		di->device_id = SWITCHCAP_HL1530;
		break;
	case BQ2597X_DEVICE_ID_SYH69637:
		di->device_id = SWITCHCAP_SYH69637;
		break;
	case BQ2597X_DEVICE_ID_NU2105:
		di->device_id = SWITCHCAP_NU2105;
		break;
	case BQ2597X_DEVICE_ID_SC8551A:
	case BQ2597X_DEVICE_ID_SC8551S:
		di->device_id = SWITCHCAP_SC8551A;
		break;
	default:
		if (!read_devid_again_flag && !bq25970_reg_reset(di)) {
			read_devid_again_flag = 1;
			hwlog_err("reg reset, read device id again\n");
			goto read;
		}
		di->device_id = -1;
		hwlog_err("device id not match\n");
		break;
	}

	return di->device_id;
}

static int bq2597x_get_adc_data(struct bq25970_device_info *di, const u8 reg, s16 *data) {
	u8 highData = 0;
	u8 lowData = 0;
	u16 tempData = 0;
	int ret = 0;
	ret = bq25970_read_byte(di, reg, &highData);
	ret += bq25970_read_byte(di, reg + 1, &lowData);
	if (ret)
		return -1;
	tempData = (highData << 8) + lowData;
	*data = (s16)tempData;
	return 0;
}

static int bq25970_get_vbat_mv(void *dev_data)
{
	s16 data = 0;
	s16 data2 = 0;
	int ret;
	int vbat;
	int vbat2;
	int result;
	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;

	if (!di)
		return -1;

	if (bq25970_is_adc_disabled(di))
		return 0;

	if (di->device_id == SWITCHCAP_NU2105) {
		ret = bq2597x_get_adc_data(di, BQ2597X_VBAT_ADC1_REG, &data);
		ret = bq2597x_get_adc_data(di, BQ2597X_VBAT_ADC1_REG, &data2);
	} else {
		ret = bq25970_read_word(di, BQ2597X_VBAT_ADC1_REG, &data);
		ret = bq25970_read_word(di, BQ2597X_VBAT_ADC1_REG, &data2);
	}
	if (ret)
		return -1;

	hwlog_info("[ic:%d]VBAT_ADC=0x%x\n", di->ic_role, data);
	vbat = (int)(data);

	hwlog_info("[ic:%d]VBAT_ADC=0x%x\n", di->ic_role, data2);
	vbat2 = (int)(data2);

	result = vbat < vbat2 ? vbat : vbat2;
	if (di->device_id == SWITCHCAP_SC8551 || di->device_id == SWITCHCAP_SC8551A)
		return result * SC8551_VBAT_ADC_STEP / SC8551_BASE_RATIO_UNIT;
	if (di->device_id == SWITCHCAP_SYH69637)
		return result * SYH69637_VBAT_ADC_STEP / SYH69637_BASE_RATIO_UNIT;

	return result;
}

static int bq25970_get_ibat_ma(int *ibat, void *dev_data)
{
	int ret;
	s16 data = 0;
	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;

	if (!ibat || !di)
		return -1;

	if (bq25970_is_adc_disabled(di)) {
		*ibat = 0;
		return 0;
	}
	if (di->device_id == SWITCHCAP_NU2105)
		ret = bq2597x_get_adc_data(di, BQ2597X_IBAT_ADC1_REG, &data);
	else
		ret = bq25970_read_word(di, BQ2597X_IBAT_ADC1_REG, &data);
	if (ret)
		return -1;

	hwlog_info("[ic:%d]IBAT_ADC=0x%x\n", di->ic_role, data);

	if (di->device_id == SWITCHCAP_SC8551 || di->device_id == SWITCHCAP_SC8551A)
		*ibat = (int)data * SC8551_IBAT_ADC_STEP /
			SC8551_BASE_RATIO_UNIT * di->sense_r_config;
	else if (di->device_id == SWITCHCAP_SYH69637)
		*ibat = (int)data * SYH69637_IBAT_ADC_STEP /
			SYH69637_BASE_RATIO_UNIT * di->sense_r_config;
	else
		*ibat = (int)data * di->sense_r_config;
	*ibat /= di->sense_r_actual;

	return 0;
}

static int bq25970_get_ibus_ma(int *ibus, void *dev_data)
{
	s16 data = 0;
	int ret;
	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;

	if (!di || !ibus)
		return -1;

	if (bq25970_is_adc_disabled(di)) {
		*ibus = 0;
		return 0;
	}
	if (di->device_id == SWITCHCAP_NU2105)
		ret = bq2597x_get_adc_data(di, BQ2597X_IBUS_ADC1_REG, &data);
	else
		ret = bq25970_read_word(di, BQ2597X_IBUS_ADC1_REG, &data);

	if (ret)
		return -1;

	hwlog_info("[ic:%d]IBUS_ADC=0x%x\n", di->ic_role, data);

	if (di->device_id == SWITCHCAP_SC8551 || di->device_id == SWITCHCAP_SC8551A)
		*ibus = (int)data * SC8551_IBUS_ADC_STEP / SC8551_BASE_RATIO_UNIT;
	else if (di->device_id == SWITCHCAP_SYH69637)
		*ibus = (int)data * SYH69637_IBUS_ADC_STEP / SYH69637_BASE_RATIO_UNIT;
	else
		*ibus = (int)data;

	return 0;
}

static int bq25970_get_vbus_mv(int *vbus, void *dev_data)
{
	int ret;
	s16 data = 0;
	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;

	if (!di || !vbus)
		return -1;

	if (bq25970_is_adc_disabled(di)) {
		*vbus = 0;
		return 0;
	}
	if (di->device_id == SWITCHCAP_NU2105)
		ret = bq2597x_get_adc_data(di, BQ2597X_VBUS_ADC1_REG, &data);
	else
		ret = bq25970_read_word(di, BQ2597X_VBUS_ADC1_REG, &data);
	if (ret)
		return -1;

	hwlog_info("[ic:%d]VBUS_ADC=0x%x\n", di->ic_role, data);

	if (di->device_id == SWITCHCAP_SC8551 || di->device_id == SWITCHCAP_SC8551A)
		*vbus = (int)data * SC8551_VBUS_ADC_STEP / SC8551_BASE_RATIO_UNIT;
	else
		*vbus = (int)data;

	return 0;
}

static int bq25970_get_tsbus_percentage(struct bq25970_device_info *di,
	long *tsbus_per)
{
	int ret;
	s16 data = 0;
	s16 adc_value;
	if (di->device_id == SWITCHCAP_NU2105)
		ret = bq2597x_get_adc_data(di, BQ2597X_TSBUS_ADC1_REG, &data);
	else
		ret = bq25970_read_word(di, BQ2597X_TSBUS_ADC1_REG, &data);
	if (ret)
		return -1;

	if (bq25970_is_adc_disabled(di)) {
		*tsbus_per = 0;
		return 0;
	}

	hwlog_info("[ic:%d]TSBUS_ADC=0x%x\n", di->ic_role, data);

	adc_value = data & ((BQ2597X_TDIE_ADC1_MASK <<
		BQ2597X_LENTH_OF_BYTE) | BQ2597X_LOW_BYTE_INIT);
	if (di->device_id == SWITCHCAP_SYH69637)
		*tsbus_per = (long)(adc_value * SYH69637_TSBUS_ADC_STEP);
	else
		*tsbus_per = (long)(adc_value * BQ2597X_TSBUS_ADC_STEP);

	return 0;
}

static int bq25970_get_adc_raw_data(struct bq25970_device_info *di,
	int adc_channel)
{
	int adc_value;
	struct adc_comp_data comp_data = { 0 };

	adc_value = power_platform_get_adc_sample(adc_channel);
	if (adc_value < 0)
		return -1;

	comp_data.adc_accuracy = di->adc_accuracy;
	comp_data.adc_v_ref = di->adc_v_ref;
	comp_data.v_pullup = di->v_pullup;
	comp_data.r_pullup = di->r_pullup;
	comp_data.r_comp = di->r_comp;

	return power_get_adc_compensation_value(adc_value, &comp_data);
}

static int bq25970_get_raw_data(int adc_channel, long *data, void *dev_data)
{
	int ret;
	long tsbus_per = 0;
	long r_temp;
	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;

	if (!di || !data)
		return -1;

	if (adc_channel) {
		*data = (long)bq25970_get_adc_raw_data(di, adc_channel);
		if (*data < 0)
			return -1;

		return 0;
	}

	ret = bq25970_get_tsbus_percentage(di, &tsbus_per);
	if (ret)
		return -1;

	/*
	 * Rt = 1 / ((1 / Rntc) + (1 / Rlow))
	 * Vtsbus / Vout =  Rt / (Rhigh + Rt)
	 * r_temp = (tsbus_per * tsbus_high_r_kohm) / (BQ2597X_TSBUS_PER_MAX - tsbus_per)
	 * data = (r_temp * tsbus_low_r_kohm) / (tsbus_low_r_kohm - r_temp)
	 */
	r_temp = ((BQ2597X_TSBUS_PER_MAX * di->tsbus_low_r_kohm) -
		tsbus_per * (di->tsbus_low_r_kohm + di->tsbus_high_r_kohm));
	if (r_temp <= 0) {
		hwlog_err("get tsbus ntc resistor failed\n");
		return -1;
	}

	*data = ((di->tsbus_high_r_kohm * di->tsbus_low_r_kohm * tsbus_per) /
		r_temp * BQ2597X_RESISTORS_KILO);

	return 0;
}

static int bq25970_is_tsbat_disabled(void *dev_data)
{
	u8 reg = 0;
	int ret;
	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;

	if (!di)
		return -1;

	ret = bq25970_read_byte(di, BQ2597X_CHRG_CTL_REG, &reg);
	if (ret)
		return -1;

	hwlog_info("[ic:%d]is_tsbat_disabled [%x]=0x%x\n", di->ic_role, BQ2597X_CHRG_CTL_REG, reg);

	if (di->device_id == SWITCHCAP_HL1530)
		return (reg & BQ2597X_TSBAT_DIS_MASK) ? -1 : 0;
	return (reg & BQ2597X_TSBAT_DIS_MASK) ? 0 : -1;
}

static int bq25970_get_device_temp(int *temp, void *dev_data)
{
	s16 data = 0;
	s16 temperature;
	int ret;
	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;

	if (!temp || !di)
		return -1;

	if (bq25970_is_adc_disabled(di)) {
		*temp = 0;
		return 0;
	}

	if (di->device_id == SWITCHCAP_NU2105)
		ret = bq2597x_get_adc_data(di, BQ2597X_TDIE_ADC1_REG, &data);
	else
		ret = bq25970_read_word(di, BQ2597X_TDIE_ADC1_REG, &data);

	if (ret)
		return -1;

	hwlog_info("[ic:%d]TDIE_ADC=0x%x\n", di->ic_role, data);

	temperature = data & ((BQ2597X_TDIE_ADC1_MASK <<
		BQ2597X_LENTH_OF_BYTE) | BQ2597X_LOW_BYTE_INIT);
	*temp = (int)(temperature / BQ2597X_TDIE_SCALE);

	return 0;
}

static int bq25970_get_vusb_mv(int *vusb, void *dev_data)
{
	int ret;
	s16 data = 0;
	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;

	if (!vusb || !di)
		return -1;

	if (bq25970_is_adc_disabled(di)) {
		*vusb = 0;
		return 0;
	}

	if (di->device_id == SWITCHCAP_NU2105)
		ret = bq2597x_get_adc_data(di, BQ2597X_VAC_ADC1_REG, &data);
	else
		ret = bq25970_read_word(di, BQ2597X_VAC_ADC1_REG, &data);

	if (ret)
		return -1;

	hwlog_info("[ic:%d]VAC_ADC=0x%x\n", di->ic_role, data);

	if (di->device_id == SWITCHCAP_SC8551 || di->device_id == SWITCHCAP_SC8551A)
		*vusb = (int)(data) * SC8551_VAC_ADC_STEP;
	else
		*vusb = (int)(data);

	return 0;
}

static int bq25970_get_vout_mv(int *vout, void *dev_data)
{
	int ret;
	s16 data = 0;
	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;

	if (!vout || !di)
		return -1;

	if (bq25970_is_adc_disabled(di)) {
		*vout = 0;
		return 0;
	}

	if (di->device_id == SWITCHCAP_NU2105)
		ret = bq2597x_get_adc_data(di, BQ2597X_VOUT_ADC1_REG, &data);
	else
		ret = bq25970_read_word(di, BQ2597X_VOUT_ADC1_REG, &data);

	if (ret)
		return -1;

	hwlog_info("[ic:%d]VOUT_ADC=0x%x\n", di->ic_role, data);

	if (di->device_id == SWITCHCAP_SC8551 || di->device_id == SWITCHCAP_SC8551A)
		*vout = (int)data * SC8551_VOUT_ADC_STEP / SC8551_BASE_RATIO_UNIT;
	else if (di->device_id == SWITCHCAP_SYH69637)
		*vout = (int)data * SYH69637_VOUT_ADC_STEP / SYH69637_BASE_RATIO_UNIT;
	else
		*vout = (int)data;

	return 0;
}

static bool is_support_fcp_scp(struct bq25970_device_info *di)
{
	bool ret = false;

	ret = ((di->dts_scp_support) || (di->dts_fcp_support));

	return ret;
}

static bool sc8551s_scp_check_data(void *dev_data)
{
	int ret;
	int i;
	u8 scp_stat = 0;
	u8 fifo_stat = 0;
	u8 data_num;
	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;

	ret = bq25970_read_byte(di, SC8551S_SCP_STAT_REG, &scp_stat);
	ret += bq25970_read_byte(di, SC8551S_SCP_FIFO_STAT_REG, &fifo_stat);
	if (ret)
		return false;

	data_num = fifo_stat & SC8551S_RX_FIFO_CNT_STAT_MASK;
	for (i = 0 ; i < data_num; i++) {
		(void)bq25970_read_byte(di, SC8551S_SCP_RX_DATA_REG,
			&di->scp_data[i]);
		hwlog_info("read scp_data=0x%x\n", di->scp_data[i]);
	}
	hwlog_info("scp_stat=0x%x,fifo_stat=0x%x,rx_num=%d\n",
		scp_stat, fifo_stat, data_num);
	hwlog_info("scp_op_num=%d,scp_op=%d\n", di->scp_op_num, di->scp_op);

	/* first scp data should be ack(0x08 or 0x88) */
	if (((di->scp_data[0] & 0x0F) == SC8551S_SCP_ACK) &&
		(scp_stat == SC8551S_SCP_NO_ERR) &&
		(((di->scp_op == SC8551S_SCP_WRITE_OP) &&
		(data_num == SC8551S_SCP_ACK_AND_CRC_LEN)) ||
		((di->scp_op == SC8551S_SCP_READ_OP) &&
		(data_num == di->scp_op_num + SC8551S_SCP_ACK_AND_CRC_LEN))))
		return true;

	return false;
}

static int sc8551s_scp_cmd_transfer_check(void *dev_data)
{
	int cnt = 0;

	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;

	if (!di)
		return -ENODEV;

	do {
		if (adp_plugout) {
			hwlog_err("transfer check fail, adp plugout\n");
			return -EINVAL;
		}
		(void)power_msleep(DT_MSLEEP_50MS, 0, NULL);
		if (di->scp_trans_done) {
			if (sc8551s_scp_check_data(di)) {
				hwlog_info("scp_trans success\n");
				return 0;
			}
			hwlog_info("scp_trans_done, but data err\n");
			return -EINVAL;
		}
		cnt++;
	} while (cnt < SC8551S_SCP_ACK_RETRY_TIME);

	hwlog_info("scp adapter trans time out\n");
	return -EINVAL;
}

static int sc8551s_fcp_adapter_detct_dpdm_stat(struct bq25970_device_info *di)
{
	int cnt;
	int ret;
	u8 stat = 0;

	for (cnt = 0; cnt < SC8551S_CHG_SCP_DETECT_MAX_CNT; cnt++) {
		if (adp_plugout) {
			hwlog_err("dpdm stat detect fail, adp plugout\n");
			return -EINVAL;
		}
		ret = bq25970_read_byte(di, SC8551S_DPDM_STAT_REG, &stat);
		hwlog_info("scp_dpdm_stat=0x%x\n", stat);
		if (ret) {
			hwlog_err("read dpdm_stat_reg fail\n");
			continue;
		}

		(void)power_msleep(DT_MSLEEP_100MS, 0, NULL);
		/* 0: DM voltage < 0.325v */
		if ((stat & SC8551S_VDM_RD_MASK) >> SC8551S_VDM_RD_SHIFT == 0)
			break;
	}
	if (cnt == SC8551S_CHG_SCP_DETECT_MAX_CNT) {
		hwlog_err("CHG_SCP_ADAPTER_DETECT_OTHER\n");
		return -EINVAL;
	}

	return 0;
}

static int sc8551s_scp_adapter_reg_read(u8 *val, u8 reg, void *dev_data)
{
	int ret;
	int i;
	struct bq25970_device_info *di =  (struct bq25970_device_info *)dev_data;

	if (!di)
		return -ENODEV;

	mutex_lock(&di->accp_adapter_reg_lock);
	hwlog_info("%s, CMD=0x%x, REG=0x%x\n", __func__,
		SC8551S_CHG_SCP_CMD_SBRRD, reg);

	/* clear scp data */
	memset_s(di->scp_data, sizeof(di->scp_data), 0, sizeof(di->scp_data));

	di->scp_op = SC8551S_SCP_READ_OP;
	di->scp_op_num = SC8551S_SCP_SBRWR_NUM;
	di->scp_trans_done = false;
	for (i = 0; i < SC8551S_SCP_RETRY_TIME; i++) {
		if (adp_plugout) {
			mutex_unlock(&di->accp_adapter_reg_lock);
			return -ENODEV;
		}

		/* clear tx/rx fifo */
		ret = bq25970_write_mask(di, SC8551S_SCP_CTRL_REG,
			SC8551S_CLR_TX_FIFO_MASK, SC8551S_CLR_TX_FIFO_SHIFT, 1);
		ret += bq25970_write_mask(di, SC8551S_SCP_CTRL_REG,
			SC8551S_CLR_RX_FIFO_MASK, SC8551S_CLR_RX_FIFO_SHIFT, 1);
		/* write data */
		ret += bq25970_write_byte(di, SC8551S_SCP_TX_DATA_REG,
			SC8551S_CHG_SCP_CMD_SBRRD);
		ret += bq25970_write_byte(di, SC8551S_SCP_TX_DATA_REG, reg);
		/* start trans */
		ret += bq25970_write_mask(di, SC8551S_SCP_CTRL_REG,
			SC8551S_SND_START_TRANS_MASK,
			SC8551S_SND_START_TRANS_SHIFT, 1);
		if (ret) {
			hwlog_err("[ic:%d] enter 6.5 %s\n", di->ic_role, __func__);
			mutex_unlock(&di->accp_adapter_reg_lock);
			return -EIO;
		}
		/* check cmd transfer success or fail */
		if (sc8551s_scp_cmd_transfer_check(di) == 0) {
			memcpy_s(val, SC8551S_MULTI_READ_LEN, &di->scp_data[1], di->scp_op_num);
			break;
		}
	}
	if (i >= SC8551S_SCP_RETRY_TIME) {
		hwlog_err("ack error,retry %d times\n", i);
		ret = -EINVAL;
	}

	mutex_unlock(&di->accp_adapter_reg_lock);

	return ret;
}

static int sc8551s_scp_adapter_multi_reg_read(u8 reg, u8 *val, u8 num, void *dev_data)
{
	int ret;
	int i;
	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;

	if (!di)
		return -ENODEV;

	mutex_lock(&di->accp_adapter_reg_lock);
	hwlog_info("%s,CMD=0x%x,REG=0x%x,NUM=%d\n",
		__func__, SC8551S_CHG_SCP_CMD_MBRRD, reg, num);

	/* clear scp data */
	memset_s(di->scp_data, sizeof(di->scp_data), 0, sizeof(di->scp_data));

	di->scp_op = SC8551S_SCP_READ_OP;
	di->scp_op_num = num;
	di->scp_trans_done = false;
	for (i = 0; i < SC8551S_SCP_RETRY_TIME; i++) {
		if (adp_plugout) {
			mutex_unlock(&di->accp_adapter_reg_lock);
			return -ENODEV;
		}

		/* clear tx/rx fifo */
		ret = bq25970_write_mask(di, SC8551S_SCP_CTRL_REG,
			SC8551S_CLR_TX_FIFO_MASK, SC8551S_CLR_TX_FIFO_SHIFT, 1);
		ret += bq25970_write_mask(di, SC8551S_SCP_CTRL_REG,
			SC8551S_CLR_RX_FIFO_MASK, SC8551S_CLR_RX_FIFO_SHIFT, 1);
		/* write cmd, reg, num */
		ret += bq25970_write_byte(di, SC8551S_SCP_TX_DATA_REG,
			SC8551S_CHG_SCP_CMD_MBRRD);
		ret += bq25970_write_byte(di, SC8551S_SCP_TX_DATA_REG, reg);
		ret += bq25970_write_byte(di, SC8551S_SCP_TX_DATA_REG, num);
		/* start trans */
		ret += bq25970_write_mask(di, SC8551S_SCP_CTRL_REG,
			SC8551S_SND_START_TRANS_MASK,
			SC8551S_SND_START_TRANS_SHIFT, 1);
		if (ret) {
			mutex_unlock(&di->accp_adapter_reg_lock);
			return -EIO;
		}
		/* check cmd transfer success or fail, ignore ack data */
		if (sc8551s_scp_cmd_transfer_check(di) == 0) {
			memcpy_s(val, SC8551S_MULTI_READ_LEN, &di->scp_data[1], SC8551S_MULTI_READ_LEN);
			break;
		}
	}
	if (i >= SC8551S_SCP_RETRY_TIME) {
		hwlog_err("ack error,retry %d times\n", i);
		ret = -EINVAL;
	}

	mutex_unlock(&di->accp_adapter_reg_lock);

	return ret;
}

static int sc8551s_scp_adapter_reg_read_block(u8 reg, u8 *val, u8 num,
	void *dev_data)
{
	int ret;
	int i, j;
	u8 data[SC8551S_MULTI_READ_LEN] = { 0 };
	u8 data_len = (num < SC8551S_MULTI_READ_LEN) ? num : SC8551S_MULTI_READ_LEN;
	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;

	if (!di || !val)
		return -EINVAL;

	di->scp_error_flag = SC8551S_SCP_NO_ERR;

	if ((reg == SCP_PROTOCOL_POWER_CURVE_BASE0) ||
		(reg == SCP_PROTOCOL_POWER_CURVE_BASE1)) {
		data_len = 1;
	}

	for (i = 0; i < num; i += data_len) {
		if (data_len > 1) {
			ret = sc8551s_scp_adapter_multi_reg_read(reg + i, data, data_len, dev_data);
		} else {
			ret = sc8551s_scp_adapter_reg_read(data, reg + i, dev_data);
		}
		if (ret) {
			hwlog_err("scp read failed, reg=0x%x\n", reg + i);
			return -EINVAL;
		}
		for (j = 0; j < data_len; j++) {
			val[i + j] = data[j];
		}
	}

	return 0;
}

static int sc8551s_scp_adapter_reg_write(u8 val, u8 reg, void *dev_data)
{
	int ret = 0;
	int i;
	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;

	if (!di)
		return -ENODEV;

	mutex_lock(&di->accp_adapter_reg_lock);
	hwlog_info("%s,CMD=0x%x,REG=0x%x,VAL=0x%x\n",
		__func__, SC8551S_CHG_SCP_CMD_SBRWR, reg, val);

	/* clear scp data */
	memset_s(di->scp_data, sizeof(di->scp_data), 0, sizeof(di->scp_data));

	di->scp_op = SC8551S_SCP_WRITE_OP;
	di->scp_op_num = SC8551S_SCP_SBRWR_NUM;
	di->scp_trans_done = false;
	for (i = 0; i < SC8551S_SCP_RETRY_TIME; i++) {
		if (adp_plugout) {
			mutex_unlock(&di->accp_adapter_reg_lock);
			return -ENODEV;
		}

		/* clear tx/rx fifo */
		bq25970_write_mask(di, SC8551S_SCP_CTRL_REG,
			SC8551S_CLR_TX_FIFO_MASK, SC8551S_CLR_TX_FIFO_SHIFT, 1);
		bq25970_write_mask(di, SC8551S_SCP_CTRL_REG,
			SC8551S_CLR_RX_FIFO_MASK, SC8551S_CLR_RX_FIFO_SHIFT, 1);
		/* write data */
		ret += bq25970_write_byte(di, SC8551S_SCP_TX_DATA_REG,
			SC8551S_CHG_SCP_CMD_SBRWR);
		ret += bq25970_write_byte(di, SC8551S_SCP_TX_DATA_REG, reg);
		ret += bq25970_write_byte(di, SC8551S_SCP_TX_DATA_REG, val);
		/* start trans */
		ret += bq25970_write_mask(di, SC8551S_SCP_CTRL_REG,
			SC8551S_SND_START_TRANS_MASK,
			SC8551S_SND_START_TRANS_SHIFT, 1);
		if (ret) {
			mutex_unlock(&di->accp_adapter_reg_lock);
			return -EIO;
		}
		/* check cmd transfer success or fail */
		if (sc8551s_scp_cmd_transfer_check(di) == 0)
			break;

	}
	if (i >= SC8551S_SCP_RETRY_TIME) {
		hwlog_err("ack error,retry %d times\n", i);
		ret = -EINVAL;
	}

	mutex_unlock(&di->accp_adapter_reg_lock);

	return ret;
}

static int sc8551s_fcp_master_reset(void *dev_data)
{
	int ret;
	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;

	if (!di)
		return -ENODEV;

	ret = bq25970_write_mask(di, SC8551S_SCP_CTRL_REG,
		SC8551S_SCP_SOFT_RST_MASK, SC8551S_SCP_SOFT_RST_SHIFT, 1);
	power_usleep(DT_USLEEP_10MS);

	return ret;
}

static int sc8551s_fcp_adapter_reset(void *dev_data)
{
	int ret;
	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;

	if (!di)
		return -ENODEV;

	ret = bq25970_write_mask(di, SC8551S_SCP_CTRL_REG,
		SC8551S_SND_RST_TRANS_MASK, SC8551S_SND_RST_TRANS_SHIFT, 1);
	power_usleep(DT_USLEEP_20MS);
	return ret;
}

static int sc8551s_fcp_read_switch_status(void *dev_data)
{
	return 0;
}

static int sc8551s_is_fcp_charger_type(void *dev_data)
{
	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;

	if (!di)
		return 0;

	if (di->dts_fcp_support == 0) {
		hwlog_err("%s:NOT SUPPORT FCP\n", __func__);
		return 0;
	}

	if (di->fcp_support)
		return 1;

	return 0;
}

static void sc8551s_fcp_adapter_detect_reset(struct bq25970_device_info *di)
{
	int ret;

	ret = sc8551s_fcp_adapter_reset(di);
	ret = bq25970_write_mask(di, SC8551S_DPDM_CTRL1_REG,
		SC8551S_DPDM_EN_MASK, SC8551S_DPDM_EN_SHIFT, FALSE);
	ret += bq25970_write_mask(di, SC8551S_DPDM_CTRL2_REG,
		SC8551S_DP_BUFF_EN_MASK, SC8551S_DP_BUFF_EN_SHIFT, FALSE);
	ret += bq25970_write_mask(di, SC8551S_SCP_CTRL_REG, SC8551S_SCP_EN_MASK,
		SC8551S_SCP_EN_SHIFT, FALSE);
	if (ret)
		hwlog_err("fcp_adapter_reset fail\n");
}

static int sc8551s_fcp_adapter_detect_enable(struct bq25970_device_info *di)
{
	int ret;

	ret = bq25970_write_mask(di, SC8551S_SCP_CTRL_REG, SC8551S_SCP_EN_MASK,
		SC8551S_SCP_EN_SHIFT, TRUE);
	ret += bq25970_write_mask(di, SC8551S_DPDM_CTRL1_REG, SC8551S_DPDM_EN_MASK,
		SC8551S_DPDM_EN_SHIFT, TRUE);
	ret += bq25970_write_mask(di, SC8551S_DPDM_CTRL2_REG,
		SC8551S_DP_BUFF_EN_MASK, SC8551S_DP_BUFF_EN_SHIFT, TRUE);
	ret += bq25970_write_byte(di, SC8551S_SCP_FLAG_MASK_REG,
		SC8551S_SCP_FLAG_MASK_REG_INIT);
	if (ret) {
		hwlog_err("%s fail\n", __func__);
		return -EIO;
	}

	return 0;
}

static int sc8551s_fcp_adapter_detect_ping_stat(struct bq25970_device_info *di)
{
	int cnt;
	int ret;
	u8 scp_stat = 0;

	for (cnt = 0; cnt < SC8551S_CHG_SCP_PING_DETECT_MAX_CNT; cnt++) {
		if (adp_plugout) {
			hwlog_err("adapter detect fail, adp plugout\n");
			return -EINVAL;
		}
		/* wait 82ms for every 5-ping */
		if ((cnt % 5) == 0)
			power_msleep(82, 0, NULL);

		ret = bq25970_write_mask(di, SC8551S_SCP_CTRL_REG,
			SC8551S_SND_START_TRANS_MASK,
			SC8551S_SND_START_TRANS_SHIFT, TRUE);
		if (ret)
			return -EIO;

		/* wait 10ms for every ping */
		power_usleep(DT_USLEEP_10MS);

		bq25970_read_byte(di, SC8551S_SCP_STAT_REG, &scp_stat);
		hwlog_info("scp ping detect,scp_stat:0x%x\n", scp_stat);
		if (((scp_stat & SC8551S_NO_FIRST_SLAVE_PING_STAT_MASK) == 0) &&
			!adp_plugout) {
			hwlog_info("scp adapter detect ok\n");
			di->fcp_support = true;
			break;
		}
	}
	if (cnt == SC8551S_CHG_SCP_PING_DETECT_MAX_CNT) {
		hwlog_err("CHG_SCP_ADAPTER_DETECT_OTHER\n");
		return -EINVAL;
	}

	return 0;
}

static bool sc8551s_is_vbus_ok(struct bq25970_device_info *di)
{
	int ret;
	u8 irqStat;

	ret = bq25970_read_byte(di, BQ2597X_INT_FLAG_REG, &irqStat);
	if (irqStat & BQ2597X_ADAPTER_INSERT_FLAG_MASK) {
		return true;
	}

	return false;
}

static int sc8551s_fcp_adapter_detect(struct bq25970_device_info *di)
{
	int ret;
	int i = 0;
	int wait_hvdcp_count = 100;

	if ((adp_plugout == true) && sc8551s_is_vbus_ok(di)) {
		adp_plugout = false;
	}

	mutex_lock(&di->scp_detect_lock);

	di->init_finish_flag = BQ2597X_INIT_FINISH;

	if (di->fcp_support) {
		mutex_unlock(&di->scp_detect_lock);
		return ADAPTER_DETECT_SUCC;
	}

	/* transmit Vdp_src_BC1.2 signal */
	ret = sc8551s_fcp_adapter_detect_enable(di);
	if (ret) {
		sc8551s_fcp_adapter_detect_reset(di);
		mutex_unlock(&di->scp_detect_lock);
		return ADAPTER_DETECT_OTHER;
	}

	/* Waiting for hvdcp */
	for (i = 0; i < wait_hvdcp_count; i++) {
		if (adp_plugout) {
			sc8551s_fcp_adapter_detect_reset(di);
			mutex_unlock(&di->scp_detect_lock);
			return ADAPTER_DETECT_OTHER;
		}
		power_usleep(DT_USLEEP_10MS);
	}

	/* detect dpdm stat */
	ret = sc8551s_fcp_adapter_detct_dpdm_stat(di);
	if (ret) {
		sc8551s_fcp_adapter_detect_reset(di);
		mutex_unlock(&di->scp_detect_lock);
		return ADAPTER_DETECT_OTHER;
	}

	/* detect ping stat */
	ret = sc8551s_fcp_adapter_detect_ping_stat(di);
	if (ret) {
		sc8551s_fcp_adapter_detect_reset(di);
		mutex_unlock(&di->scp_detect_lock);
		return ADAPTER_DETECT_OTHER;
	}

	mutex_unlock(&di->scp_detect_lock);
	return ADAPTER_DETECT_SUCC;
}

static int sc8551s_fcp_stop_charge_config(void *dev_data)
{
	int ret;
	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;

	if (!di)
		return -ENODEV;

	ret = sc8551s_fcp_master_reset(di);
	ret += bq25970_write_mask(di, SC8551S_SCP_CTRL_REG, SC8551S_SCP_EN_MASK,
		SC8551S_SCP_EN_SHIFT, 0);
	ret += bq25970_write_mask(di, SC8551S_DPDM_CTRL1_REG, SC8551S_DPDM_EN_MASK,
		SC8551S_DPDM_EN_SHIFT, 0);
	if (ret)
		return -EINVAL;

	di->fcp_support = false;

	hwlog_info("bq25970_fcp_master_reset");
	return ret;
}

static int scp_adapter_reg_read(u8 *val, u8 reg, void *dev_data)
{
	int ret;
	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;

	if (!di)
		return -ENODEV;

	if (di->scp_error_flag) {
		hwlog_err("scp timeout happened, do not read reg=0x%x\n", reg);
		return -EINVAL;
	}

	ret = sc8551s_scp_adapter_reg_read(val, reg, dev_data);
	if (ret) {
		hwlog_err("error reg=0x%x\n", reg);
		if (reg != SCP_PROTOCOL_ADP_TYPE0)
			di->scp_error_flag = SC8551S_SCP_IS_ERR;

		return -EINVAL;
	}

	return 0;
}

static int scp_adapter_reg_write(u8 val, u8 reg, void *dev_data)
{
	int ret;
	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;

	if (!di)
		return -ENODEV;

	if (di->scp_error_flag) {
		hwlog_err("scp timeout happened, do not write reg=0x%x\n", reg);
		return -EINVAL;
	}

	ret = sc8551s_scp_adapter_reg_write(val, reg, dev_data);
	if (ret) {
		hwlog_err("error reg=0x%x\n", reg);
		di->scp_error_flag = SC8551S_SCP_IS_ERR;
		return -EINVAL;
	}

	return 0;
}

static int sc8551s_self_check(void *dev_data)
{
	return 0;
}

static int sc8551s_scp_chip_reset(void *dev_data)
{
	int ret;

	ret = sc8551s_fcp_master_reset(dev_data);
	if (ret) {
		hwlog_err("bq25970_fcp_master_reset fail\n");
		return -EINVAL;
	}

	return 0;
}

static int sc8551s_scp_reg_read_block(int reg, int *val, int num,
	void *dev_data)
{
	int ret;
	int i;
	u8 data = 0;
	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;

	if (!di || !val)
		return -EINVAL;

	di->scp_error_flag = SC8551S_SCP_NO_ERR;

	for (i = 0; i < num; i++) {
		ret = scp_adapter_reg_read(&data, reg + i, dev_data);
		if (ret) {
			hwlog_err("scp read failed, reg=0x%x\n", reg + i);
			return -EINVAL;
		}
		val[i] = data;
	}

	return 0;
}

static int sc8551s_scp_reg_write_block(int reg, const int *val, int num,
	void *dev_data)
{
	int ret;
	int i;
	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;

	if (!di || !val)
		return -EINVAL;

	di->scp_error_flag = SC8551S_SCP_NO_ERR;

	for (i = 0; i < num; i++) {
		ret = scp_adapter_reg_write(val[i], reg + i, dev_data);
		if (ret) {
			hwlog_err("scp write failed, reg=0x%x\n", reg + i);
			return -EINVAL;
		}
	}

	return 0;
}

static int sc8551s_scp_detect_adapter(void *dev_data)
{
	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;
	hwlog_err("[ic:%d] enter %s\n", di->ic_role, __func__);
	if (!di)
		return -ENODEV;

	return sc8551s_fcp_adapter_detect(di);
}

int sc8551s_fcp_reg_read_block(int reg, int *val, int num, void *dev_data)
{
	int ret, i;
	u8 data = 0;
	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;

	if (!di || !val)
		return -EINVAL;

	di->scp_error_flag = SC8551S_SCP_NO_ERR;

	for (i = 0; i < num; i++) {
		ret = scp_adapter_reg_read(&data, reg + i, dev_data);
		if (ret) {
			hwlog_err("fcp read failed, reg=0x%x\n", reg + i);
			return -EINVAL;
		}
		val[i] = data;
	}
	return 0;
}

static int sc8551s_fcp_reg_write_block(int reg, const int *val, int num,
	void *dev_data)
{
	int ret, i;
	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;

	if (!di || !val)
		return -EINVAL;

	di->scp_error_flag = SC8551S_SCP_NO_ERR;

	for (i = 0; i < num; i++) {
		ret = scp_adapter_reg_write(val[i], reg + i, dev_data);
		if (ret) {
			hwlog_err("fcp write failed, reg=0x%x\n", reg + i);
			return -EINVAL;
		}
	}

	return 0;
}

static int sc8551s_fcp_detect_adapter(void *dev_data)
{
	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;

	if (!di)
		return -ENODEV;

	return sc8551s_fcp_adapter_detect(di);
}

static int sc8551s_pre_init(void *dev_data)
{
	int ret;
	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;

	if (!di)
		return -ENODEV;

	ret = sc8551s_self_check(di);
	if (ret) {
		hwlog_err("sc8551s_self_check fail\n");
		return ret;
	}

	return ret;
}

static int sc8551s_scp_adapter_reset(void *dev_data)
{
	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;

	if (!di)
		return -ENODEV;

	return sc8551s_fcp_adapter_reset(di);
}

static int sc8551s_power_event_call(struct notifier_block *nb,
	unsigned long event, void *data)
{
	struct bq25970_device_info *di = (struct bq25970_device_info *)data;

	if (!di || !(is_support_fcp_scp(di)))
		return NOTIFY_OK;
	hwlog_info("%s event: %d", __func__, event);
	/*
	 * after receiving the message of non-stop charging,
	 * we set the event to start, otherwise set the event to stop
	 */
	switch (event) {
	case POWER_NE_USB_CONNECT:
		adp_plugout = false;
		break;
	case POWER_NE_USB_DISCONNECT:
		/* ignore repeat event */
		adp_plugout = true;
		break;
	default:
		break;
	}

	return NOTIFY_OK;
}

static int bq25970_get_register_head(char *buffer, int size, void *dev_data)
{
	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;

	if (!buffer || !di)
		return -1;

	if (di->ic_role == CHARGE_IC_TYPE_MAIN)
		snprintf(buffer, size,
			"      Ibus   Vbus   Ibat   Vusb   Vout   Vbat   Temp");
	else
		snprintf(buffer, size,
			"   Ibus1  Vbus1  Ibat1  Vusb1  Vout1  Vbat1  Temp1");

	return 0;
}

static int bq25970_value_dump(char *buffer, int size, void *dev_data)
{
	int ibus = 0;
	int vbus = 0;
	int ibat = 0;
	int vusb = 0;
	int vout = 0;
	int temp = 0;
	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;

	if (!buffer || !di)
		return -1;

	bq25970_get_ibus_ma(&ibus, dev_data);
	bq25970_get_vbus_mv(&vbus, dev_data);
	bq25970_get_ibat_ma(&ibat, dev_data);
	bq25970_get_vusb_mv(&vusb, dev_data);
	bq25970_get_vout_mv(&vout, dev_data);
	bq25970_get_device_temp(&temp, dev_data);

	if (di->ic_role == CHARGE_IC_TYPE_MAIN)
		snprintf(buffer, size,
			"     %-7d%-7d%-7d%-7d%-7d%-7d%-7d",
			ibus, vbus, ibat, vusb, vout,
			bq25970_get_vbat_mv(dev_data), temp);
	else
		snprintf(buffer, size,
			"%-7d%-7d%-7d%-7d%-7d%-7d%-7d  ",
			ibus, vbus, ibat, vusb, vout,
			bq25970_get_vbat_mv(dev_data), temp);

	return 0;
}

static int bq25970_config_watchdog_ms(int time, void *dev_data)
{
	u8 val;
	u8 reg;
	int ret;
	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;

	if (!di)
		return -1;

	if (time >= BQ2597X_WTD_CONFIG_TIMING_30000MS)
		val = BQ2597X_WTD_SET_30000MS;
	else if (time >= BQ2597X_WTD_CONFIG_TIMING_5000MS)
		val = BQ2597X_WTD_SET_30000MS;
	else if (time >= BQ2597X_WTD_CONFIG_TIMING_1000MS)
		val = BQ2597X_WTD_SET_30000MS;
	else
		val = BQ2597X_WTD_SET_30000MS;

	ret = bq25970_write_mask(di, BQ2597X_CONTROL_REG,
		BQ2597X_WATCHDOG_CONFIG_MASK, BQ2597X_WATCHDOG_CONFIG_SHIFT,
		val);
	if (ret)
		return -1;

	ret = bq25970_read_byte(di, BQ2597X_CONTROL_REG, &reg);
	if (ret)
		return -1;

	hwlog_info("[ic:%d]config_watchdog_ms [%x]=0x%x\n", di->ic_role, BQ2597X_CONTROL_REG, reg);

	return 0;
}

static u8 bq25970_select_vbat_ovp_threshold(struct bq25970_device_info *di,
	int ovp_threshold)
{
	if (di->device_id == SWITCHCAP_HL1530) {
		if (ovp_threshold < HL1530_BAT_OVP_BASE)
			ovp_threshold = HL1530_BAT_OVP_BASE;
		if (ovp_threshold > HL1530_BAT_OVP_MAX)
			ovp_threshold = HL1530_BAT_OVP_MAX;

		return (u8)((ovp_threshold - HL1530_BAT_OVP_BASE) /
			BQ2597X_BAT_OVP_STEP);
	} else {
		if (ovp_threshold < BQ2597X_BAT_OVP_BASE_3500MV)
			ovp_threshold = BQ2597X_BAT_OVP_BASE_3500MV;
		if (ovp_threshold > BQ2597X_BAT_OVP_MAX_5075MV)
			ovp_threshold = BQ2597X_BAT_OVP_MAX_5075MV;

		return (u8)((ovp_threshold - BQ2597X_BAT_OVP_BASE_3500MV) /
			BQ2597X_BAT_OVP_STEP);
	}
}

static int bq25970_config_vbat_ovp_threshold_mv(struct bq25970_device_info *di,
	int ovp_threshold)
{
	u8 value;
	int ret;

	value = bq25970_select_vbat_ovp_threshold(di, ovp_threshold);
	ret = bq25970_write_mask(di, BQ2597X_BAT_OVP_REG,
		BQ2597X_BAT_OVP_MASK, BQ2597X_BAT_OVP_SHIFT,
		value);
	if (ret)
		return -1;

	hwlog_info("[ic:%d]config_vbat_ovp_threshold_mv [%x]=0x%x\n", di->ic_role,
		BQ2597X_BAT_OVP_REG, value);

	return 0;
}

static int bq25970_config_ibat_ocp_threshold_ma(struct bq25970_device_info *di,
	int ocp_threshold)
{
	u8 value;
	int ret;

	if (ocp_threshold < BQ2597X_BAT_OCP_BASE_2000MA)
		ocp_threshold = BQ2597X_BAT_OCP_BASE_2000MA;

	if (ocp_threshold > BQ2597X_BAT_OCP_MAX_14700MA)
		ocp_threshold = BQ2597X_BAT_OCP_MAX_14700MA;

	value = (u8)((ocp_threshold - BQ2597X_BAT_OCP_BASE_2000MA) /
		BQ2597X_BAT_OCP_STEP);
	ret = bq25970_write_mask(di, BQ2597X_BAT_OCP_REG,
		BQ2597X_BAT_OCP_MASK, BQ2597X_BAT_OCP_SHIFT,
		value);
	if (ret)
		return -1;

	hwlog_info("[ic:%d]config_ibat_ocp_threshold_ma [%x]=0x%x\n", di->ic_role,
		BQ2597X_BAT_OCP_REG, value);

	return 0;
}

static u8 bq25970_select_ac_ovp_threshold(struct bq25970_device_info *di,
	int ovp_threshold)
{
	if ((di->device_id == SWITCHCAP_HL1530) ||
		(di->device_id == SWITCHCAP_SYH69637) ||
		(di->device_id == SWITCHCAP_NU2105)) {
		if (ovp_threshold == HL1530_AC_OVP_BASE_MIN)
			ovp_threshold = BQ2597X_AC_OVP_MAX_18000MV;
		else if (ovp_threshold < BQ2597X_AC_OVP_BASE_11000MV)
			ovp_threshold = BQ2597X_AC_OVP_BASE_11000MV;
		else if (ovp_threshold > HL1530_AC_OVP_BASE_MAX)
			ovp_threshold = HL1530_AC_OVP_BASE_MAX;
	} else {
		if (ovp_threshold < BQ2597X_AC_OVP_BASE_11000MV)
			ovp_threshold = BQ2597X_AC_OVP_BASE_11000MV;
		else if (ovp_threshold > BQ2597X_AC_OVP_MAX_18000MV)
			ovp_threshold = BQ2597X_AC_OVP_MAX_18000MV;
	}

	return (u8)((ovp_threshold - BQ2597X_AC_OVP_BASE_11000MV) /
		BQ2597X_AC_OVP_STEP);
}

static int bq25970_config_ac_ovp_threshold_mv(struct bq25970_device_info *di,
	int ovp_threshold)
{
	u8 value;
	int ret;

	value = bq25970_select_ac_ovp_threshold(di, ovp_threshold);
	ret = bq25970_write_mask(di, BQ2597X_AC_OVP_REG,
		BQ2597X_AC_OVP_MASK, BQ2597X_AC_OVP_SHIFT,
		value);
	if (ret)
		return -1;

	hwlog_info("[ic:%d]config_ac_ovp_threshold_mv [%x]=0x%x\n", di->ic_role,
		BQ2597X_AC_OVP_REG, value);

	return 0;
}

static int bq25970_config_vbus_ovp_threshold_mv(struct bq25970_device_info *di,
	int ovp_threshold)
{
	u8 value;
	int ret;

	if (ovp_threshold < BQ2597X_BUS_OVP_BASE_6000MV)
		ovp_threshold = BQ2597X_BUS_OVP_BASE_6000MV;

	if (ovp_threshold > BQ2597X_BUS_OVP_MAX_12350MV)
		ovp_threshold = BQ2597X_BUS_OVP_MAX_12350MV;

	value = (u8)((ovp_threshold - BQ2597X_BUS_OVP_BASE_6000MV) /
		BQ2597X_BUS_OVP_STEP);
	ret = bq25970_write_mask(di, BQ2597X_BUS_OVP_REG,
		BQ2597X_BUS_OVP_MASK, BQ2597X_BUS_OVP_SHIFT,
		value);
	if (ret)
		return -1;

	hwlog_info("[ic:%d]config_vbus_ovp_threshold_mv [%x]=0x%x\n", di->ic_role,
		BQ2597X_BUS_OVP_REG, value);

	return 0;
}

static int bq25970_config_ibus_ocp_threshold_ma(struct bq25970_device_info *di,
	int ocp_threshold)
{
	u8 value;
	int ret;

	if (ocp_threshold < BQ2597X_BUS_OCP_BASE_1000MA)
		ocp_threshold = BQ2597X_BUS_OCP_BASE_1000MA;

	if (ocp_threshold > BQ2597X_BUS_OCP_MAX_4750MA)
		ocp_threshold = BQ2597X_BUS_OCP_MAX_4750MA;

	value = (u8)((ocp_threshold - BQ2597X_BUS_OCP_BASE_1000MA) /
		BQ2597X_BUS_OCP_STEP);
	ret = bq25970_write_mask(di, BQ2597X_BUS_OCP_UCP_REG,
		BQ2597X_BUS_OCP_MASK, BQ2597X_BUS_OCP_SHIFT,
		value);
	if (ret)
		return -1;

	hwlog_info("[ic:%d]config_ibus_ocp_threshold_ma [%x]=0x%x\n", di->ic_role,
		BQ2597X_BUS_OCP_UCP_REG, value);

	return 0;
}

static int bq25970_config_switching_frequency_shift(int data, void *dev_data)
{
	int freq_shift;
	int ret;
	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;

	if (data) {
		freq_shift = BQ2597X_SW_FREQ_SHIFT_MP_P10;
	} else {
		freq_shift = di->default_config_frequency_shift;
	}

	ret = bq25970_write_mask(di, BQ2597X_CHRG_CTL_REG,
		BQ2597X_FREQ_SHIFT_MASK, BQ2597X_FREQ_SHIFT_SHIFT, freq_shift);
	if (ret)
		return -1;

	hwlog_info("[ic:%d] config_switching_frequency_shift[%x]=0x%x\n",
		di->ic_role, BQ2597X_CHRG_CTL_REG, freq_shift);

	return 0;
}

static int bq25970_config_switching_frequency(struct bq25970_device_info *di,
	int data)
{
	int freq;
	int freq_shift;
	int ret;

	switch (data) {
	case BQ2597X_SW_FREQ_450KHZ:
		freq = BQ2597X_FSW_SET_SW_FREQ_500KHZ;
		freq_shift = BQ2597X_SW_FREQ_SHIFT_M_P10;
		break;
	case BQ2597X_SW_FREQ_500KHZ:
		freq = BQ2597X_FSW_SET_SW_FREQ_500KHZ;
		freq_shift = BQ2597X_SW_FREQ_SHIFT_NORMAL;
		break;
	case BQ2597X_SW_FREQ_550KHZ:
		freq = BQ2597X_FSW_SET_SW_FREQ_500KHZ;
		freq_shift = BQ2597X_SW_FREQ_SHIFT_P_P10;
		break;
	case BQ2597X_SW_FREQ_675KHZ:
		freq = BQ2597X_FSW_SET_SW_FREQ_750KHZ;
		freq_shift = BQ2597X_SW_FREQ_SHIFT_M_P10;
		break;
	case BQ2597X_SW_FREQ_750KHZ:
		freq = BQ2597X_FSW_SET_SW_FREQ_750KHZ;
		freq_shift = BQ2597X_SW_FREQ_SHIFT_NORMAL;
		break;
	case BQ2597X_SW_FREQ_825KHZ:
		freq = BQ2597X_FSW_SET_SW_FREQ_750KHZ;
		freq_shift = BQ2597X_SW_FREQ_SHIFT_P_P10;
		break;
	case BQ2597X_SW_FREQ_1MHZ:
		freq = BQ2597X_FSW_SET_SW_FREQ_1MHZ;
		freq_shift = BQ2597X_SW_FREQ_SHIFT_NORMAL;
	default:
		freq = BQ2597X_FSW_SET_SW_FREQ_500KHZ;
		freq_shift = BQ2597X_SW_FREQ_SHIFT_P_P10;
		break;
	}

	ret = bq25970_write_mask(di, BQ2597X_CONTROL_REG,
		BQ2597X_FSW_SET_MASK, BQ2597X_FSW_SET_SHIFT,
		freq);
	if (ret)
		return -1;

	ret = bq25970_write_mask(di, BQ2597X_CHRG_CTL_REG,
		BQ2597X_FREQ_SHIFT_MASK, BQ2597X_FREQ_SHIFT_SHIFT,
		freq_shift);
	if (ret)
		return -1;

	if (di->special_freq_shift)
		freq_shift = BQ2597X_SW_FREQ_SHIFT_MP_P10;
	di->default_config_frequency_shift = freq_shift;

	hwlog_info("[ic:%d]config_switching_frequency [%x]=0x%x, [%x]=0x%x\n",
		di->ic_role, BQ2597X_CONTROL_REG, freq, BQ2597X_CHRG_CTL_REG, freq_shift);

	return 0;
}

static int bq25970_config_ibat_sns_res(struct bq25970_device_info *di, int data)
{
	int res_config;

	if (data == SENSE_R_2_MOHM)
		res_config = BQ2597X_IBAT_SNS_RES_2MOHM;
	else
		res_config = BQ2597X_IBAT_SNS_RES_5MOHM;

	return bq25970_write_mask(di, BQ2597X_PULSE_MODE_REG,
		BQ2597X_IBAT_SNS_RES_MASK, BQ2597X_IBAT_SNS_RES_SHIFT,
		res_config);
}

static int bq25970_reg_init(struct bq25970_device_info *di)
{
	int ret;

	ret = bq25970_write_byte(di, BQ2597X_CONTROL_REG,
		BQ2597X_CONTROL_REG_INIT);
	if ((di->device_id == SWITCHCAP_HL1530) ||
		(di->device_id == SWITCHCAP_SYH69637))
		ret += bq25970_write_mask(di, BQ2597X_BUS_OVP_REG,
			HL1530_BUS_PD_EN_MASK, HL1530_BUS_PD_EN_SHIFT,
			BQ2597X_ALM_DISABLE);
	ret += bq25970_write_byte(di, BQ2597X_CHRG_CTL_REG,
		di->chrg_ctl_reg_init);
	ret += bq25970_write_byte(di, BQ2597X_INT_MASK_REG,
		BQ2597X_INT_MASK_REG_INIT);
	ret += bq25970_write_byte(di, BQ2597X_FLT_MASK_REG,
		BQ2597X_FLT_MASK_REG_INIT);
	ret += bq25970_write_byte(di, BQ2597X_ADC_CTRL_REG,
		BQ2597X_ADC_CTRL_REG_INIT);
	ret += bq25970_write_byte(di, BQ2597X_ADC_FN_DIS_REG,
		di->adc_fn_reg_init);
	ret += bq25970_write_mask(di, BQ2597X_BAT_OVP_ALM_REG,
		BQ2597X_BAT_OVP_ALM_DIS_MASK, BQ2597X_BAT_OVP_ALM_DIS_SHIFT,
		BQ2597X_ALM_DISABLE);
	ret += bq25970_write_mask(di, BQ2597X_BAT_OCP_ALM_REG,
		BQ2597X_BAT_OCP_ALM_DIS_MASK, BQ2597X_BAT_OCP_ALM_DIS_SHIFT,
		BQ2597X_ALM_DISABLE);
	ret += bq25970_write_mask(di, BQ2597X_BAT_UCP_ALM_REG,
		BQ2597X_BAT_UCP_ALM_DIS_MASK, BQ2597X_BAT_UCP_ALM_DIS_SHIFT,
		BQ2597X_ALM_DISABLE);
	ret += bq25970_write_mask(di, BQ2597X_BUS_OVP_ALM_REG,
		BQ2597X_BUS_OVP_ALM_DIS_MASK, BQ2597X_BUS_OVP_ALM_DIS_SHIFT,
		BQ2597X_ALM_DISABLE);
	ret += bq25970_write_mask(di, BQ2597X_BUS_OCP_ALM_REG,
		BQ2597X_BUS_OCP_ALM_DIS_MASK, BQ2597X_BUS_OCP_ALM_DIS_SHIFT,
		BQ2597X_ALM_DISABLE);
	ret += bq25970_config_vbat_ovp_threshold_mv(di,
		BQ2597X_VBAT_OVP_THRESHOLD_INIT);
	ret += bq25970_config_ibat_ocp_threshold_ma(di,
		BQ2597X_IBAT_OCP_THRESHOLD_INIT);
	ret += bq25970_config_ac_ovp_threshold_mv(di,
		BQ2597X_AC_OVP_THRESHOLD_INIT);
	ret += bq25970_config_vbus_ovp_threshold_mv(di,
		BQ2597X_VBUS_OVP_THRESHOLD_INIT);
	ret += bq25970_config_ibus_ocp_threshold_ma(di, di->ibus_ocp_th);
	ret += bq25970_config_switching_frequency(di, di->switching_frequency);
	ret += bq25970_config_ibat_sns_res(di, di->sense_r_config);
		/* for wireless sc abnormal close */
	ret += bq25970_write_mask(di, BQ2597X_DEGLITCH_REG,
			BQ2597X_IBUS_UCP_FALL_DEGLTICH_MASK, BQ2597X_IBUS_UCP_FALL_DEGLTICH_SHIFT,
			BQ2597X_IBUS_UCP_FALL_5MS);
	if (di->device_id == SWITCHCAP_SC8551 || di->device_id == SWITCHCAP_SC8551A)
		ret += bq25970_write_byte(di, BQ2597X_ADC_ACCU_REG,
			BQ2597X_ADC_ACCU_REG_INIT);
	if ((di->ic_role == CHARGE_IC_TYPE_MAIN) && (is_support_fcp_scp(di))) {
		ret += bq25970_write_mask(di, SC8551S_DPDM_CTRL2_REG,
			SC8551S_DM_3P3_EN_MASK, SC8551S_DM_3P3_EN_SHIFT, 0);
		ret += bq25970_write_mask(di, SC8551S_DPDM_CTRL2_REG,
			SC8551S_DP_BUFF_EN_MASK, SC8551S_DP_BUFF_EN_SHIFT, 1);
		ret += bq25970_write_byte(di, SC8551S_SCP_FLAG_MASK_REG,
			SC8551S_SCP_FLAG_MASK_REG_INIT);
	}
	return ret;
}

static int bq25970_charge_init(void *dev_data)
{
	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -1;
	}

	if (bq25970_reg_init(di))
		return -1;

	di->device_id = bq25970_get_device_id(dev_data);
	if (di->device_id == -1)
		return -1;

	hwlog_info("[ic:%d]device id is %d\n", di->ic_role, di->device_id);

	di->init_finish_flag = BQ2597X_INIT_FINISH;
	return 0;
}

static int bq25970_charge_exit(void *dev_data)
{
	int ret;
	struct bq25970_device_info *di = (struct bq25970_device_info *)dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -1;
	}

	ret = bq25970_charge_enable(BQ2597X_SWITCHCAP_DISABLE, dev_data);
	di->fcp_support = false;

	di->init_finish_flag = BQ2597X_NOT_INIT;
	di->int_notify_enable_flag = BQ2597X_DISABLE_INT_NOTIFY;

	power_usleep(DT_USLEEP_10MS);

	return ret;
}

static int bq25970_batinfo_exit(void *dev_data)
{
	return 0;
}

static int bq25970_batinfo_init(void *dev_data)
{
	return 0;
}

static void bq25970_fault_event_notify(unsigned long event, void *data)
{
	struct atomic_notifier_head *fault_event_notifier_list = NULL;

	sc_get_fault_notifier(&fault_event_notifier_list);
	atomic_notifier_call_chain(fault_event_notifier_list, event, data);
}

static void bq25970_fault_handle(struct bq25970_device_info *di,
	struct nty_data *data)
{
	int val = 0;
	u8 fault_flag = data->event1;
	u8 ac_protection = data->event2;
	u8 converter_state = data->event3;
	u8 scp_flag = data->event4;

	if (ac_protection & BQ2597X_AC_OVP_FLAG_MASK) {
		hwlog_info("[ic:%d]AC OVP happened\n", di->ic_role);
		bq25970_fault_event_notify(DC_FAULT_AC_OVP, data);
	} else if (fault_flag & BQ2597X_BAT_OVP_FLT_FLAG_MASK) {
		val = bq25970_get_vbat_mv(di);
		hwlog_info("[ic:%d]BAT OVP happened, vbat=%d mv\n", di->ic_role, val);
		if (val >= BQ2597X_VBAT_OVP_THRESHOLD_INIT)
			bq25970_fault_event_notify(DC_FAULT_VBAT_OVP, data);
	} else if (fault_flag & BQ2597X_BAT_OCP_FLT_FLAG_MASK) {
		bq25970_get_ibat_ma(&val, di);
		hwlog_info("[ic:%d]BAT OCP happened, ibat=%d ma\n", di->ic_role, val);
		if (val >= BQ2597X_IBAT_OCP_THRESHOLD_INIT)
			bq25970_fault_event_notify(DC_FAULT_IBAT_OCP, data);
	} else if (fault_flag & BQ2597X_BUS_OVP_FLT_FLAG_MASK) {
		bq25970_get_vbus_mv(&val, di);
		hwlog_info("[ic:%d]BUS OVP happened, vbus=%d mv\n", di->ic_role, val);
		if (val >= BQ2597X_VBUS_OVP_THRESHOLD_INIT)
			bq25970_fault_event_notify(DC_FAULT_VBUS_OVP, data);
	} else if (fault_flag & BQ2597X_BUS_OCP_FLT_FLAG_MASK) {
		bq25970_get_ibus_ma(&val, di);
		hwlog_info("[ic:%d]BUS OCP happened, ibus=%d ma\n", di->ic_role, val);
		if (val >= BQ2597X_IBUS_OCP_THRESHOLD_INIT)
			bq25970_fault_event_notify(DC_FAULT_IBUS_OCP, data);
	} else if (fault_flag & BQ2597X_TSBAT_FLT_FLAG_MASK) {
		hwlog_info("[ic:%d]BAT TEMP OTP happened\n", di->ic_role);
		bq25970_fault_event_notify(DC_FAULT_TSBAT_OTP, data);
	} else if (fault_flag & BQ2597X_TSBUS_FLT_FLAG_MASK) {
		hwlog_info("[ic:%d]BUS TEMP OTP happened\n", di->ic_role);
		bq25970_fault_event_notify(DC_FAULT_TSBUS_OTP, data);
	} else if (fault_flag & BQ2597X_TDIE_ALM_FLAG_MASK) {
		hwlog_info("[ic:%d]DIE TEMP OTP happened\n", di->ic_role);
	}

	if (converter_state & BQ2597X_CONV_OCP_FLAG_MASK) {
		hwlog_info("[ic:%d]CONV OCP happened\n", di->ic_role);
		bq25970_fault_event_notify(DC_FAULT_CONV_OCP, data);
	}

	if ((di->ic_role == CHARGE_IC_TYPE_MAIN) && (is_support_fcp_scp(di))) {
		if (scp_flag & SC8551S_TRANS_DONE_FLAG_MASK)
			di->scp_trans_done = true;
	}
}

static void bq25970_interrupt_work(struct work_struct *work)
{
	struct bq25970_device_info *di = NULL;
	struct nty_data *data = NULL;
	u8 converter_state = 0;
	u8 fault_flag = 0;
	u8 ac_protection = 0;
	u8 ibus_ucp = 0;
	u8 scp_flag_mask = 0;
	int ret;
	int retry_cnt;

	if (!work)
		return;

	di = container_of(work, struct bq25970_device_info, irq_work);
	if (!di || !di->client) {
		hwlog_err("di is null\n");
		return;
	}

	for (retry_cnt = 0; retry_cnt < 10; retry_cnt++) {
		if (atomic_read(&di->pm_suspend)) {
			hwlog_info("irq_thread wait resume\n");
			msleep(10); /* 10: wait resume */
		} else {
			break;
		}
	}

	data = &(di->nty_data);

	ret = bq25970_read_byte(di, BQ2597X_AC_OVP_REG, &ac_protection);
	ret |= bq25970_read_byte(di, BQ2597X_BUS_OCP_UCP_REG, &ibus_ucp);
	ret |= bq25970_read_byte(di, BQ2597X_FLT_FLAG_REG, &fault_flag);
	ret |= bq25970_read_byte(di, BQ2597X_CONVERTER_STATE_REG,
		&converter_state);
	if ((di->ic_role == CHARGE_IC_TYPE_MAIN) && (is_support_fcp_scp(di))) {
		ret |= bq25970_read_byte(di, SC8551S_SCP_FLAG_MASK_REG, &scp_flag_mask);
	}
	if (ret)
		hwlog_err("irq_work read fail\n");

	data->event1 = fault_flag;
	data->event2 = ac_protection;
	data->event3 = converter_state;
	data->event4 = scp_flag_mask;
	data->addr = di->client->addr;

	if (di->int_notify_enable_flag == BQ2597X_ENABLE_INT_NOTIFY) {
		bq25970_fault_handle(di, data);
		bq25970_dump_register(di);
	}

	hwlog_info("ic_role is %d\n", di->ic_role);
	hwlog_info("ac_ovp_reg [%x]=0x%x\n", BQ2597X_AC_OVP_REG, ac_protection);
	hwlog_info("bus_ocp_ucp_reg [%x]=0x%x\n", BQ2597X_BUS_OCP_UCP_REG,
		ibus_ucp);
	hwlog_info("flt_flag_reg [%x]=0x%x\n", BQ2597X_FLT_FLAG_REG,
		fault_flag);
	hwlog_info("converter_state_reg [%x]=0x%x\n",
		BQ2597X_CONVERTER_STATE_REG, converter_state);

	/* clear irq */
	enable_irq(di->irq_int);
}

static irqreturn_t bq25970_interrupt(int irq, void *_di)
{
	struct bq25970_device_info *di = _di;

	if (!di) {
		hwlog_err("di is null\n");
		return IRQ_HANDLED;
	}

	if (di->chip_already_init == 0)
		hwlog_err("chip not init\n");

	if (di->init_finish_flag == BQ2597X_INIT_FINISH)
		di->int_notify_enable_flag = BQ2597X_ENABLE_INT_NOTIFY;

	hwlog_info("[ic:%d]int happened\n", di->ic_role);
	disable_irq_nosync(di->irq_int);
	schedule_work(&di->irq_work);
	return IRQ_HANDLED;
}

static int bq25970_irq_init(struct bq25970_device_info *di,
	struct device_node *np)
{
	int ret;

	ret = power_gpio_config_interrupt(np,
		"gpio_int", "bq25970_gpio_int", &di->gpio_int, &di->irq_int);
	if (ret)
		return ret;

	ret = request_irq(di->irq_int, bq25970_interrupt,
		IRQF_TRIGGER_FALLING, "bq25970_int_irq", di);
	if (ret) {
		hwlog_err("gpio irq request fail\n");
		di->irq_int = -1;
		gpio_free(di->gpio_int);
		return ret;
	}

	disable_irq_nosync(di->irq_int);
	INIT_WORK(&di->irq_work, bq25970_interrupt_work);
	return 0;
}

static int bq25970_reg_reset_and_init(struct bq25970_device_info *di)
{
	int ret;

	ret = bq25970_reg_reset(di);
	if (ret) {
		hwlog_err("reg reset fail\n");
		return ret;
	}

	ret = bq25970_fault_clear(di);
	if (ret) {
		hwlog_err("fault clear fail\n");
		return ret;
	}

	ret = bq25970_reg_init(di);
	if (ret) {
		hwlog_err("reg init fail\n");
		return ret;
	}

	return 0;
}

static void bq25970_parse_dts(struct device_node *np,
	struct bq25970_device_info *di)
{
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"tsbus_high_r_kohm", &di->tsbus_high_r_kohm,
		BQ2597X_RESISTORS_100KOHM);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"tsbus_low_r_kohm", &di->tsbus_low_r_kohm,
		BQ2597X_RESISTORS_100KOHM);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"switching_frequency", &di->switching_frequency,
		BQ2597X_SW_FREQ_550KHZ);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"special_freq_shift", &di->special_freq_shift, 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"ic_role", &di->ic_role, CHARGE_IC_TYPE_MAIN);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"sense_r_config", &di->sense_r_config, SENSE_R_2_MOHM);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"sense_r_actual", &di->sense_r_actual, SENSE_R_2_MOHM);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"chrg_ctl_reg_init", &di->chrg_ctl_reg_init,
		BQ2597X_CHRG_CTL_REG_INIT);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"adc_fn_reg_init", &di->adc_fn_reg_init,
		BQ2597X_ADC_FN_DIS_REG_INIT);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"adc_accuracy", &di->adc_accuracy, 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"adc_v_ref", &di->adc_v_ref, 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"v_pullup", &di->v_pullup, 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"r_pullup", &di->r_pullup, 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"r_comp", &di->r_comp, 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"i2c_recovery_addr", &di->i2c_recovery_addr, 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"ibus_ocp_th", &di->ibus_ocp_th, BQ2597X_IBUS_OCP_THRESHOLD_INIT);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "scp_support",
		(u32 *)&(di->dts_scp_support), 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "fcp_support",
		(u32 *)&(di->dts_fcp_support), 0);
}

static void sc8551s_lock_mutex_init(struct bq25970_device_info *di)
{
	if (is_support_fcp_scp(di)) {
		mutex_init(&di->scp_detect_lock);
		mutex_init(&di->accp_adapter_reg_lock);
	}
}

static void sc8551s_lock_mutex_destroy(struct bq25970_device_info *di)
{
	if (is_support_fcp_scp(di)) {
		mutex_destroy(&di->scp_detect_lock);
		mutex_destroy(&di->accp_adapter_reg_lock);
	}
}

static struct dc_ic_ops bq25970_sysinfo_ops = {
	.dev_name = "bq25970",
	.ic_init = bq25970_charge_init,
	.ic_exit = bq25970_charge_exit,
	.ic_enable = bq25970_charge_enable,
	.ic_adc_enable = bq25970_adc_enable,
	.ic_discharge = bq25970_discharge,
	.is_ic_close = bq25970_is_device_close,
	.get_ic_id = bq25970_get_device_id,
	.config_ic_watchdog = bq25970_config_watchdog_ms,
	.get_ic_status = bq25970_is_tsbat_disabled,
	.ic_config_freq_shift = bq25970_config_switching_frequency_shift,
};

static struct dc_batinfo_ops bq25970_batinfo_ops = {
	.init = bq25970_batinfo_init,
	.exit = bq25970_batinfo_exit,
	.get_bat_btb_voltage = bq25970_get_vbat_mv,
	.get_bat_package_voltage = bq25970_get_vbat_mv,
	.get_vbus_voltage = bq25970_get_vbus_mv,
	.get_bat_current = bq25970_get_ibat_ma,
	.get_ic_ibus = bq25970_get_ibus_ma,
	.get_ic_temp = bq25970_get_device_temp,
	.get_ic_vusb = bq25970_get_vusb_mv,
	.get_ic_vout = bq25970_get_vout_mv,
};

static struct power_tz_ops bq25970_temp_sensing_ops = {
	.get_raw_data = bq25970_get_raw_data,
};

static struct power_log_ops bq25970_log_ops = {
	.dev_name = "bq25970",
	.dump_log_head = bq25970_get_register_head,
	.dump_log_content = bq25970_value_dump,
};

static struct dc_ic_ops bq25970_aux_sysinfo_ops = {
	.dev_name = "bq25970_aux",
	.ic_init = bq25970_charge_init,
	.ic_exit = bq25970_charge_exit,
	.ic_enable = bq25970_charge_enable,
	.ic_adc_enable = bq25970_adc_enable,
	.ic_discharge = bq25970_discharge,
	.is_ic_close = bq25970_is_device_close,
	.get_ic_id = bq25970_get_device_id,
	.config_ic_watchdog = bq25970_config_watchdog_ms,
	.get_ic_status = bq25970_is_tsbat_disabled,
};

static struct dc_batinfo_ops bq25970_aux_batinfo_ops = {
	.init = bq25970_batinfo_init,
	.exit = bq25970_batinfo_exit,
	.get_bat_btb_voltage = bq25970_get_vbat_mv,
	.get_bat_package_voltage = bq25970_get_vbat_mv,
	.get_vbus_voltage = bq25970_get_vbus_mv,
	.get_bat_current = bq25970_get_ibat_ma,
	.get_ic_ibus = bq25970_get_ibus_ma,
	.get_ic_temp = bq25970_get_device_temp,
	.get_ic_vusb = bq25970_get_vusb_mv,
	.get_ic_vout = bq25970_get_vout_mv,
};

static struct power_tz_ops bq25970_aux_temp_sensing_ops = {
	.get_raw_data = bq25970_get_raw_data,
};

static struct power_log_ops bq25970_aux_log_ops = {
	.dev_name = "bq25970_aux",
	.dump_log_head = bq25970_get_register_head,
	.dump_log_content = bq25970_value_dump,
};

static struct scp_protocol_ops g_bq25970_scp_protocol_ops = {
	.chip_name = "sc8551s",
	.reg_read = sc8551s_scp_reg_read_block,
	.reg_write = sc8551s_scp_reg_write_block,
	.reg_multi_read = sc8551s_scp_adapter_reg_read_block,
	.detect_adapter = sc8551s_scp_detect_adapter,
	.soft_reset_master = sc8551s_scp_chip_reset,
	.soft_reset_slave = sc8551s_scp_adapter_reset,
	.pre_init = sc8551s_pre_init,
};

static struct fcp_protocol_ops g_bq25970_fcp_protocol_ops = {
	.chip_name = "sc8551s",
	.reg_read = sc8551s_fcp_reg_read_block,
	.reg_write = sc8551s_fcp_reg_write_block,
	.detect_adapter = sc8551s_fcp_detect_adapter,
	.soft_reset_master = sc8551s_fcp_master_reset,
	.soft_reset_slave = sc8551s_fcp_adapter_reset,
	.get_master_status = sc8551s_fcp_read_switch_status,
	.stop_charging_config = sc8551s_fcp_stop_charge_config,
	.is_accp_charger_type = sc8551s_is_fcp_charger_type,
};

static void bq25970_init_ops_dev_data(struct bq25970_device_info *di)
{
	if (di->ic_role == CHARGE_IC_TYPE_MAIN) {
		bq25970_sysinfo_ops.dev_data = (void *)di;
		bq25970_batinfo_ops.dev_data = (void *)di;
		bq25970_temp_sensing_ops.dev_data = (void *)di;
		bq25970_log_ops.dev_data = (void *)di;
		if (di->dts_scp_support) {
			g_bq25970_scp_protocol_ops.dev_data = (void *)di;
		}
		if (di->dts_fcp_support) {
			g_bq25970_fcp_protocol_ops.dev_data = (void *)di;
		}
	} else {
		bq25970_aux_sysinfo_ops.dev_data = (void *)di;
		bq25970_aux_batinfo_ops.dev_data = (void *)di;
		bq25970_aux_temp_sensing_ops.dev_data = (void *)di;
		bq25970_aux_log_ops.dev_data = (void *)di;
	}
}

static int bq25970_protocol_ops_register(struct bq25970_device_info *di)
{
	int ret;

	if (di->dts_scp_support) {
		ret = scp_protocol_ops_register(&g_bq25970_scp_protocol_ops);
		if (ret)
			return -EINVAL;
	}
	if (di->dts_fcp_support) {
		ret = fcp_protocol_ops_register(&g_bq25970_fcp_protocol_ops);
		if (ret)
			return -EINVAL;
	}

	return 0;
}

static int bq25970_ops_register(struct bq25970_device_info *di)
{
	int ret;

	bq25970_init_ops_dev_data(di);

	if (di->ic_role == CHARGE_IC_TYPE_MAIN) {
		ret = dc_ic_ops_register(SC_MODE, di->ic_role,
			&bq25970_sysinfo_ops);
		ret |= dc_batinfo_ops_register(SC_MODE, di->ic_role,
			&bq25970_batinfo_ops);
		ret |= bq25970_protocol_ops_register(di);
	} else {
		ret = dc_ic_ops_register(SC_MODE, di->ic_role,
			&bq25970_aux_sysinfo_ops);
		ret |= dc_batinfo_ops_register(SC_MODE, di->ic_role,
			&bq25970_aux_batinfo_ops);
	}
	if (ret) {
		hwlog_err("sysinfo ops register fail\n");
		return ret;
	}

	if (di->ic_role == CHARGE_IC_TYPE_MAIN) {
		ret = power_tz_ops_register(&bq25970_temp_sensing_ops,
			"bq25970");
		ret |= power_log_ops_register(&bq25970_log_ops);
	} else {
		ret = power_tz_ops_register(&bq25970_aux_temp_sensing_ops,
			"bq25970_aux");
		ret |= power_log_ops_register(&bq25970_aux_log_ops);
	}
	if (ret)
		hwlog_err("thermalzone or power log ops register fail\n");

	return 0;
}

static int bq25970_probe(struct i2c_client *client,
	const struct i2c_device_id *id)
{
	int ret;
	struct bq25970_device_info *di = NULL;
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

	bq25970_parse_dts(np, di);
	sc8551s_lock_mutex_init(di);

	ret = bq25970_get_device_id(di);
	if (ret < 0)
		goto bq25970_fail_0;

	ret = bq25970_irq_init(di, np);
	if (ret)
		goto bq25970_fail_0;

	ret = bq25970_reg_reset_and_init(di);
	if (ret)
		goto bq25970_fail_1;

	di->nb.notifier_call = sc8551s_power_event_call;
	ret = power_event_nc_register(POWER_NT_CONNECT, &di->nb);
	if (ret)
		goto bq25970_fail_1;

	bq25970_ops_register(di);
	i2c_set_clientdata(client, di);
	if (gpio_get_value(di->gpio_int) == INTERRUPT_HAPPENED_GPIO_VALUE)
		schedule_work(&di->irq_work);
	else
		enable_irq(di->irq_int);

	return 0;

bq25970_fail_1:
	free_irq(di->irq_int, di);
	gpio_free(di->gpio_int);
bq25970_fail_0:
	sc8551s_lock_mutex_destroy(di);
	di->chip_already_init = 0;
	devm_kfree(&client->dev, di);

	return ret;
}

static int bq25970_remove(struct i2c_client *client)
{
	struct bq25970_device_info *di = i2c_get_clientdata(client);

	if (!di)
		return -ENODEV;

	if (di->irq_int)
		free_irq(di->irq_int, di);

	if (di->gpio_int)
		gpio_free(di->gpio_int);

	sc8551s_lock_mutex_destroy(di);

	return 0;
}

static void bq25970_shutdown(struct i2c_client *client)
{
	struct bq25970_device_info *di = i2c_get_clientdata(client);

	if (!di)
		return;

	bq25970_reg_reset(di);

	if (di->device_id == SWITCHCAP_SC8551 || di->device_id == SWITCHCAP_SC8551A)
		bq25970_adc_enable(0, (void *)di);
}

#ifdef CONFIG_PM
static int bq25970_i2c_suspend(struct device *dev)
{
	struct i2c_client *client = to_i2c_client(dev);
	struct bq25970_device_info *di = NULL;

	if (!client)
		return 0;

	di = i2c_get_clientdata(client);
	if (di)
		bq25970_adc_enable(0, (void *)di);

	atomic_set(&di->pm_suspend, 1); /* 1: set flag */
	return 0;
}

#ifdef CONFIG_I2C_OPERATION_IN_COMPLETE
static void bq25970_i2c_complete(struct device *dev)
{
	struct i2c_client *client = to_i2c_client(dev);
	struct bq25970_device_info *di = NULL;

	if (!client)
		return;

	hwlog_info("sc complete enter\n");
	di = i2c_get_clientdata(client);
	if (di)
		bq25970_adc_enable(1, (void *)di);
	atomic_set(&di->pm_suspend, 0);
}

static int bq25970_i2c_resume(struct device *dev)
{
	return 0;
}
#else
static int bq25970_i2c_resume(struct device *dev)
{
	struct i2c_client *client = to_i2c_client(dev);
	struct bq25970_device_info *di = NULL;

	if (!client)
		return 0;

	di = i2c_get_clientdata(client);
	if (di)
		bq25970_adc_enable(1, (void *)di);
	atomic_set(&di->pm_suspend, 0);
	return 0;
}
#endif /* CONFIG_I2C_OPERATION_IN_COMPLETE */

static const struct dev_pm_ops bq25970_pm_ops = {
	SET_SYSTEM_SLEEP_PM_OPS(bq25970_i2c_suspend, bq25970_i2c_resume)
#ifdef CONFIG_I2C_OPERATION_IN_COMPLETE
	.complete = bq25970_i2c_complete,
#endif /* CONFIG_I2C_OPERATION_IN_COMPLETE */
};
#define BQ25970_PM_OPS (&bq25970_pm_ops)
#else
#define BQ25970_PM_OPS (NULL)
#endif /* CONFIG_PM */

MODULE_DEVICE_TABLE(i2c, bq25970);
static const struct of_device_id bq25970_of_match[] = {
	{
		.compatible = "bq25970",
		.data = NULL,
	},
	{},
};

static const struct i2c_device_id bq25970_i2c_id[] = {
	{ "bq25970", 0 },
	{}
};

static struct i2c_driver bq25970_driver = {
	.probe = bq25970_probe,
	.remove = bq25970_remove,
	.shutdown = bq25970_shutdown,
	.id_table = bq25970_i2c_id,
	.driver = {
		.owner = THIS_MODULE,
		.name = "bq25970",
		.of_match_table = of_match_ptr(bq25970_of_match),
		.pm = BQ25970_PM_OPS,
	},
};

static int __init bq25970_init(void)
{
	return i2c_add_driver(&bq25970_driver);
}

static void __exit bq25970_exit(void)
{
	i2c_del_driver(&bq25970_driver);
}

module_init(bq25970_init);
module_exit(bq25970_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("bq25970 module driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");