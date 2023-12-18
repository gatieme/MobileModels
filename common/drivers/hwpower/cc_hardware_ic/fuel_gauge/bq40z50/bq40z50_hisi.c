// SPDX-License-Identifier: GPL-2.0
/*
 * bq40z50_hisi.c
 *
 * bq40z50_hisi driver
 *
 * Copyright (c) 2023-2023 Huawei Technologies Co., Ltd.
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

#include "bq40z50.h"
#include <huawei_platform/hwpower/common_module/power_platform.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/common_module/power_common_macro.h>
#include <chipset_common/hwpower/common_module/power_log.h>
#include "platform_include/basicplatform/linux/power/platform/coul/coul_merge_drv.h"
#ifdef CONFIG_HUAWEI_BATTERY_VOLTAGE
#include <huawei_platform/power/battery_voltage.h>
#endif

#define HWLOG_TAG bq40z50
HWLOG_REGIST();

static struct bq40z50_device_info *g_bq40z50_dev;

static struct bq40z50_device_info *bq40z50_get_di(void)
{
	if (!g_bq40z50_dev) {
		hwlog_err("chip not init\n");
		return NULL;
	}

	return g_bq40z50_dev;
}

void bq40z50_set_di(struct bq40z50_device_info *di)
{
	g_bq40z50_dev = di;
}

static int bq40z50_is_ready(void *dev_data)
{
	return (g_bq40z50_dev == NULL) ? 0 : 1;
}

static int bq40z50_get_battery_temp(void *dev_data)
{
	/* unit degree */
	return bq40z50_get_battery_temp_base(dev_data) / 10;
}

static int bq40z50_get_cell1_temp(void *dev_data)
{
	return bq40z50_get_battery_temp(dev_data);
}

static int bq40z50_get_cell2_temp(void *dev_data)
{
	return bq40z50_get_battery_temp(dev_data);
}

#ifdef CONFIG_HLTHERM_RUNTEST
static int bq40z50_is_battery_exist(void *dev_data)
{
	return 0;
}
#else
static int bq40z50_is_battery_exist(void *dev_data)
{
	return bq40z50_is_battery_exist_base(dev_data);
}
#endif /* CONFIG_HLTHERM_RUNTEST */

static bool bq40z50_is_abnormal_low_capacity(s16 cur, u16 vol)
{
	u16 cell1_vol;
	u16 cell2_vol;
	u16 cell3_vol;
	int ret;
	int cell_vol;
	int vol_offset;
	struct bq40z50_device_info *di = bq40z50_get_di();

	if ((cur >= 0) || (vol >= BQ40Z50_LOW_CAPACITY_MONITOR_VOL))
		return false;

	vol_offset = -cur * BQ40Z50_BATT_RESISTANCE / BQ40Z50_RESISTANCE_SCALE;

	ret = bq40z50_read_word(di, BQ40Z50_REG_CELL1_VOLT, &cell1_vol);
	if (!ret) {
		cell_vol = cell1_vol + vol_offset;
		if (cell_vol < BQ40Z50_LOW_CAPACITY_CELL_VOL)
			return true;
	}

	ret = bq40z50_read_word(di, BQ40Z50_REG_CELL2_VOLT, &cell2_vol);
	if (!ret) {
		cell_vol = cell2_vol + vol_offset;
		if (cell_vol < BQ40Z50_LOW_CAPACITY_CELL_VOL)
			return true;
	}

	ret = bq40z50_read_word(di, BQ40Z50_REG_CELL3_VOLT, &cell3_vol);
	if (!ret) {
		cell_vol = cell3_vol + vol_offset;
		if (cell_vol < BQ40Z50_LOW_CAPACITY_CELL_VOL)
			return true;
	}

	return false;
}

static int bq40z50_get_battery_soc(void *dev_data)
{
	int ret;
	u16 soc = 0;
	struct bq40z50_device_info *di = dev_data;

	if (!di)
		return (int)soc;

	if (di->charge_status == BQ40Z50_CHARGE_STATE_CHRG_DONE) {
		hwlog_info("charge done, force soc to full\n");
		return BQ40Z50_BATT_CAPACITY_FULL;
	}

	ret = bq40z50_read_word(di, BQ40Z50_REG_SOC, &soc);
	if (ret)
		soc = di->cache.soc;
	else
		di->cache.soc = soc;

	if (di->cell_count == BQ40Z50_BATT_3CELL &&
	    bq40z50_is_abnormal_low_capacity(di->cache.curr, di->cache.vol)) {
		hwlog_info("soc %u is abnormal\n", soc);
		soc = BQ40Z50_ABNORMAL_LOW_CAPACITY;
	}

	if (di->prevent_low_cap) {
		hwlog_info("real soc=%u\n", soc);
		/* Prevent boot up fail when low capacity, 20% capacity mapped to 0% capacity */
		if (soc < BQ40Z50_LOW_CAPACITY_MAP_SOC)
			soc = BQ40Z50_LOW_CAPACITY_MAP_SOC;
		soc = DIV_ROUND_CLOSEST((soc - BQ40Z50_LOW_CAPACITY_MAP_SOC) * BQ40Z50_BATT_CAPACITY_FULL,
		    (BQ40Z50_BATT_CAPACITY_FULL - BQ40Z50_LOW_CAPACITY_MAP_SOC));
	}

	hwlog_info("soc=%u\n", soc);
	return (int)soc;
}

static int bq40z50_is_battery_reach_threshold(void *dev_data)
{
	int soc;

	if (!bq40z50_is_battery_exist(dev_data))
		return 0;

	soc = bq40z50_get_battery_soc(dev_data);
	if (soc > BQ40Z50_BATT_CAPACITY_WARNING_LVL)
		return 0;
	else if (soc > BQ40Z50_BATT_CAPACITY_LOW_LVL)
		return BQ_FLAG_SOC1;

	return BQ_FLAG_LOCK;
}

static char *bq40z50_get_battery_brand(void *dev_data)
{
	struct bq40z50_device_info *di = dev_data;

	if (!di)
		return "UNKNOWN";

	switch (di->device_id) {
	case BATTERY_FUEL_BQ40Z50:
		return "BITCGLT";
	case BATTERY_FUEL_SH366006:
		return "BITCGLS";
	default:
		return "UNKNOWN";
	}
}

static int bq40z50_get_battery_vol(void *dev_data)
{
	struct bq40z50_device_info *di = dev_data;

	if (!di)
		return 0;

	/* vbat / 2 when use converter */
	return bq40z50_get_battery_vol_base(di) / (di->use_converter ? 2 : 1);
}

static int bq40z50_get_cell1_vbat_mv(void)
{
	struct bq40z50_device_info *di = bq40z50_get_di();

	if (!di)
		return 0;

	return bq40z50_get_cell_vbat_mv_base(di, BQ40Z50_REG_CELL1_VOLT, &(di->cache.cell1_vol));
}

static int bq40z50_get_cell2_vbat_mv(void)
{
	struct bq40z50_device_info *di = bq40z50_get_di();

	if (!di)
		return 0;

	return bq40z50_get_cell_vbat_mv_base(di, BQ40Z50_REG_CELL2_VOLT, &(di->cache.cell2_vol));
}

static int bq40z50_get_all_vbat_mv(void)
{
	return bq40z50_get_battery_vol_base(bq40z50_get_di());
}

static int bq40z50_get_battery_cell1_vol(void *dev_data)
{
	return bq40z50_get_cell1_vbat_mv();
}

static int bq40z50_get_battery_cell2_vol(void *dev_data)
{
	return bq40z50_get_cell2_vbat_mv();
}

static int bq40z50_get_battery_vol_uv(void *dev_data)
{
	return POWER_UV_PER_MV * bq40z50_get_battery_vol(dev_data);
}

static int bq40z50_get_battery_cell1_vol_uv(void *dev_data)
{
	return POWER_UV_PER_MV * bq40z50_get_battery_cell1_vol(dev_data);
}

static int bq40z50_get_battery_cell2_vol_uv(void *dev_data)
{
	return POWER_UV_PER_MV * bq40z50_get_battery_cell2_vol(dev_data);
}

static int bq40z50_get_battery_curr(void *dev_data)
{
	return -bq40z50_get_battery_curr_base(dev_data);
}

static int bq40z50_get_battery_avgcurr(void *dev_data)
{
	return bq40z50_get_battery_avgcurr_base(dev_data);
}

static int bq40z50_get_battery_resistance(void *dev_data)
{
	return 0;
}

static int bq40z50_get_battery_rm(void *dev_data)
{
	struct bq40z50_device_info *di = dev_data;

	if (!di)
		return 0;

	/* rm * 2 when use converter */
	return bq40z50_get_battery_rm_base(dev_data) * (di->use_converter ? 2 : 1);
}

static int bq40z50_get_battery_cell_rm(void *dev_data)
{
	struct bq40z50_device_info *di = dev_data;

	if (!di || !di->cell_count)
		return 0;

	return bq40z50_get_battery_rm(di) / di->cell_count;
}

static int bq40z50_get_battery_dc(void *dev_data)
{
	struct bq40z50_device_info *di = dev_data;

	if (!di)
		return 0;

	/* dc * 2 when use converter */
	return bq40z50_get_battery_dc_base(dev_data) * (di->use_converter ? 2 : 1);
}

static int bq40z50_get_battery_cell_dc(void *dev_data)
{
	struct bq40z50_device_info *di = dev_data;

	if (!di || !di->cell_count)
		return 0;

	return bq40z50_get_battery_dc(di) / di->cell_count;
}

static int bq40z50_get_battery_fcc(void *dev_data)
{
	struct bq40z50_device_info *di = dev_data;

	if (!di)
		return 0;

	/* fcc * 2 when use converter */
	return bq40z50_get_battery_fcc_base(dev_data) * (di->use_converter ? 2 : 1);
}

static int bq40z50_get_battery_cell_fcc(void *dev_data)
{
	struct bq40z50_device_info *di = dev_data;

	if (!di || !di->cell_count)
		return 0;

	return bq40z50_get_battery_fcc(di) / di->cell_count;
}

static int bq40z50_get_battery_soh(void *dev_data)
{
	u16 soh = 0;
	int ret;
	struct bq40z50_device_info *di = dev_data;

	if (!di)
		return (int)soh;

	ret = bq40z50_read_word(di, BQ40Z50_REG_SOH, &soh);
	if (ret)
		soh = di->cache.soh;
	else
		di->cache.soh = soh;

	hwlog_info("battery_soh=%u\n", soh);
	return (int)soh;
}

static int bq40z50_get_battery_tte(void *dev_data)
{
	u16 tte = 0;
	int ret;
	struct bq40z50_device_info *di = dev_data;

	if (!di)
		return (int)tte;

	ret = bq40z50_read_word(di, BQ40Z50_REG_TTE, &tte);
	if (ret)
		tte = di->cache.tte;
	else
		di->cache.tte = tte;

	if (tte == BQ40Z50_REG_MAX_VAL) {
		hwlog_err("the battery is not being discharged\n");
		return -EPERM;
	}

	hwlog_info("battery_tte=%u\n", tte);
	return (int)tte;
}

static int bq40z50_get_battery_ttf(void *dev_data)
{
	u16 ttf = 0;
	int ret;
	struct bq40z50_device_info *di = dev_data;

	if (!di)
		return (int)ttf;

	ret = bq40z50_read_word(di, BQ40Z50_REG_TTF, &ttf);
	if (ret)
		ttf = di->cache.ttf;
	else
		di->cache.ttf = ttf;

	if (ttf == BQ40Z50_REG_MAX_VAL) {
		hwlog_err("the battery is not being charged\n");
		return -EPERM;
	}

	hwlog_info("battery_ttf=%u\n", ttf);
	return (int)ttf;
}

static int bq40z50_get_battery_cycle(void *dev_data)
{
	return bq40z50_get_battery_cycle_base(dev_data);
}

static void bq40z50_set_last_capacity(void *dev_data, int capacity)
{
}

static int bq40z50_get_last_capacity(void *dev_data)
{
	int soc_at_term, ui_cap_zero_offset, cap;
	struct bq40z50_device_info *di = dev_data;

	if (!di)
		return -EPERM;

	(void)power_dts_read_u32_compatible(power_dts_tag(HWLOG_TAG),
		"hisilicon,bci_battery", "bci_soc_at_term", &soc_at_term, BQ40Z50_BATT_CAPACITY_FULL);
	(void)power_dts_read_u32_compatible(power_dts_tag(HWLOG_TAG),
		"hisilicon,bci_battery", "ui_cap_zero_offset", &ui_cap_zero_offset, 0);

	/* no customize register, use current soc and terminate soc algorithm */
	cap = bq40z50_get_battery_soc(di);
	/* uisoc = soc/soc_at_term - ui_cap_zero_offset */
	if (soc_at_term)
		cap = DIV_ROUND_CLOSEST((cap * BQ40Z50_BATT_CAPACITY_FULL), soc_at_term) - ui_cap_zero_offset;

	if (cap < 0)
		cap = 0;
	else if (cap > BQ40Z50_BATT_CAPACITY_FULL)
		cap = BQ40Z50_BATT_CAPACITY_FULL;

	return cap;
}

static int bq40z50_battery_unfiltered_soc(void *dev_data)
{
	return bq40z50_get_battery_soc(dev_data);
}

static bool bq40z50_check_undervoltage(struct bq40z50_device_info *di)
{
	if (bq40z50_get_battery_vol(di) < di->cutoff_vol)
		di->low_vol_cnt++;
	else
		di->low_vol_cnt = 0;

	if (di->low_vol_cnt > BQ40Z50_CUTOFF_RETRY_COUNT) {
		hwlog_err("battery low, cutoff");
		return true;
	}

	return false;
}

static int bq40z50_get_battery_health(void *dev_data)
{
	int temp;
	int status = POWER_SUPPLY_HEALTH_GOOD;
	struct bq40z50_device_info *di = dev_data;

	if (!bq40z50_is_battery_exist(dev_data))
		return 0;

	temp = bq40z50_get_battery_temp(dev_data);
	if (bq40z50_check_undervoltage(di))
		status = POWER_SUPPLY_HEALTH_UNDERVOLTAGE;
	else if (temp < BQ40Z50_BATT_TEMP_ABNORMAL_LOW)
		status = POWER_SUPPLY_HEALTH_COLD;
	else if (temp > BQ40Z50_BATT_TEMP_ABNORMAL_HIGH)
		status = POWER_SUPPLY_HEALTH_OVERHEAT;

	hwlog_info("battery_health=%d\n", status);
	return status;
}

static int bq40z50_get_battery_capacity_level(void *dev_data)
{
	int capacity;
	int level;

	if (!bq40z50_is_battery_exist(dev_data))
		return 0;

	capacity = bq40z50_get_battery_soc(dev_data);
	if ((capacity < BQ40Z50_BATT_CAPACITY_ZERO) ||
		(capacity > BQ40Z50_BATT_CAPACITY_FULL))
		level = POWER_SUPPLY_CAPACITY_LEVEL_UNKNOWN;
	else if (capacity <= BQ40Z50_BATT_CAPACITY_CRITICAL)
		level = POWER_SUPPLY_CAPACITY_LEVEL_CRITICAL;
	else if (capacity <= BQ40Z50_BATT_CAPACITY_LOW)
		level = POWER_SUPPLY_CAPACITY_LEVEL_LOW;
	else if (capacity < BQ40Z50_BATT_CAPACITY_HIGH)
		level = POWER_SUPPLY_CAPACITY_LEVEL_NORMAL;
	else if (capacity < BQ40Z50_BATT_CAPACITY_FULL)
		level = POWER_SUPPLY_CAPACITY_LEVEL_HIGH;
	else
		level = POWER_SUPPLY_CAPACITY_LEVEL_FULL;

	hwlog_info("battery_cap_level=%d\n", level);
	return level;
}

static int bq40z50_get_battery_technology(void *dev_data)
{
	/* default technology is "Li-poly" */
	return POWER_SUPPLY_TECHNOLOGY_LIPO;
}

static int bq40z50_get_battery_vbat_max(void *dev_data)
{
	struct bq40z50_device_info *di = dev_data;

	if (!di)
		return 0;

	/* vbat / 2 when use converter */
	return bq40z50_get_battery_vbat_max_base(dev_data) / (di->use_converter ? 2 : 1);
}

static int bq40z50_is_fcc_debounce(void *dev_data)
{
	return 0;
}

static int bq40z50_device_check(void *dev_data)
{
	return 0;
}

static void bq40z50_charger_event_process(struct bq40z50_device_info *di,
	unsigned int event)
{
	if (!di)
		return;

	hwlog_info("receive charge event=%u\n", event);
	switch (event) {
	case VCHRG_START_USB_CHARGING_EVENT:
	case VCHRG_START_AC_CHARGING_EVENT:
	case VCHRG_START_CHARGING_EVENT:
		di->charge_status = BQ40Z50_CHARGE_STATE_START_CHARGING;
		break;
	case VCHRG_STOP_CHARGING_EVENT:
		di->charge_status = BQ40Z50_CHARGE_STATE_STOP_CHARGING;
		break;
	case VCHRG_CHARGE_DONE_EVENT:
		di->charge_status = BQ40Z50_CHARGE_STATE_CHRG_DONE;
		break;
	case VCHRG_NOT_CHARGING_EVENT:
		di->charge_status = BQ40Z50_CHARGE_STATE_NOT_CHARGING;
		break;
	case VCHRG_POWER_SUPPLY_OVERVOLTAGE:
		di->charge_status = BQ40Z50_CHARGE_STATE_NOT_CHARGING;
		break;
	case VCHRG_POWER_SUPPLY_WEAKSOURCE:
		di->charge_status = BQ40Z50_CHARGE_STATE_NOT_CHARGING;
		break;
	default:
		di->charge_status = BQ40Z50_CHARGE_STATE_NOT_CHARGING;
		break;
	}
}

static int bq40z50_battery_charger_event_rcv(void *dev_data, unsigned int evt)
{
	struct bq40z50_device_info *di = dev_data;

	if (!di || !bq40z50_is_battery_exist(di))
		return 0;

	bq40z50_charger_event_process(di, evt);

	return 0;
}

struct chrg_para_lut *bq40z50_get_battery_charge_params(void *dev_data)
{
	struct bq40z50_device_info *di = dev_data;

	if (!di)
		return NULL;

	return di->para_batt_data;
}

static int bq40z50_get_battery_status(void *dev_data)
{
	return bq40z50_get_battery_status_base(dev_data);
}

static int bq40z50_get_desired_charging_current(void *dev_data)
{
	return bq40z50_get_desired_charging_current_base(dev_data);
}

static int bq40z50_get_desired_charging_voltage(void *dev_data)
{
	return bq40z50_get_desired_charging_voltage_base(dev_data);
}

static int bq40z50_is_smart_battery(void *dev_data)
{
	return bq40z50_is_smart_battery_base(dev_data) ? 1 : 0;
}

static int bq40z50_is_battery_full_charged(void *dev_data)
{
	int status;

	status = bq40z50_get_battery_status(dev_data);
	if ((status >= 0) && (status & BQ40Z50_BATT_STATUS_FC))
		return true;

	return false;
}

static int bq40z50_get_battery_id_vol(void *dev_data)
{
	return 0;
}

static int bq40z50_read_dts_string_array(const char *prop,
	long *data, u32 row, u32 col)
{
	int i, len;
	const char *tmp_string = NULL;

	len = power_dts_read_count_strings_compatible(power_dts_tag(HWLOG_TAG),
		"bq40z50_battery", prop, row, col);
	if (len < 0)
		return -EINVAL;

	for (i = 0; i < len; i++) {
		if (power_dts_read_string_index_compatible(power_dts_tag(HWLOG_TAG),
			"bq40z50_battery", prop, i, &tmp_string))
			return -EINVAL;

		if (kstrtol(tmp_string, 0, &data[i]))
			return -EINVAL;
	}

	return len;
}

static int bq40z50_get_temp_para_data(struct chrg_para_lut *pdata)
{
	int len;

	if (!pdata)
		return -EINVAL;

	len = bq40z50_read_dts_string_array("temp_para", &pdata->temp_data[0][0],
		TEMP_PARA_LEVEL, TEMP_PARA_TOTAL);
	if (len < 0)
		return -EINVAL;

	pdata->temp_len = len;
	return 0;
}

static int bq40z50_get_vbat_para_data(struct chrg_para_lut *pdata)
{
	int len;

	if (!pdata)
		return -EINVAL;

	len = bq40z50_read_dts_string_array("vbat_para", &pdata->volt_data[0][0],
		VOLT_PARA_LEVEL, VOLT_PARA_TOTAL);
	if (len < 0)
		return -EINVAL;

	pdata->volt_len = len;
	return 0;
}

static int bq40z50_get_segment_para_data(struct chrg_para_lut *pdata)
{
	int len;

	if (!pdata)
		return -EINVAL;

	len = bq40z50_read_dts_string_array("segment_para", &pdata->segment_data[0][0],
		SEGMENT_PARA_LEVEL, SEGMENT_PARA_TOTAL);
	if (len < 0)
		return -EINVAL;

	pdata->segment_len = len;
	return 0;
}

int bq40z50_get_para_data(struct bq40z50_device_info *di)
{
	struct chrg_para_lut *para_data = NULL;
	int ret;

	di->para_batt_data = kzalloc(sizeof(struct chrg_para_lut), GFP_KERNEL);
	if (!di->para_batt_data)
		return -EINVAL;

	para_data = di->para_batt_data;

	ret = bq40z50_get_temp_para_data(para_data);
	if (ret)
		goto alloc_mem_fail;
	ret = bq40z50_get_vbat_para_data(para_data);
	if (ret)
		goto alloc_mem_fail;
	ret = bq40z50_get_segment_para_data(para_data);
	if (ret)
		goto alloc_mem_fail;

	return 0;

alloc_mem_fail:
	kfree(di->para_batt_data);
	di->para_batt_data = NULL;
	return  -EINVAL;
}

static int bq40z50_dump_log_data(char *buffer, int size, void *dev_data)
{
	struct bq40z50_device_info *di = dev_data;
	struct bq40z50_log_data log_data;

	if (!buffer || !di)
		return -EPERM;

	log_data.vbat = bq40z50_get_battery_vol_base(di);
	log_data.ibat = bq40z50_get_battery_curr_base(di);
	log_data.avg_ibat = bq40z50_get_battery_avgcurr_base(di);
	log_data.rm = bq40z50_get_battery_rm_base(di);
	log_data.temp = bq40z50_get_battery_temp_base(di);
	log_data.soc = bq40z50_get_battery_soc(di);
	log_data.fcc = bq40z50_get_battery_fcc_base(di);
	log_data.ibat_th = bq40z50_get_desired_charging_current_base(di);
	log_data.vbat_th = bq40z50_get_desired_charging_voltage_base(di);
	log_data.cycle_count = bq40z50_get_battery_cycle_base(di);
	log_data.cell1_vol = bq40z50_get_cell1_vbat_mv();
	log_data.cell2_vol = bq40z50_get_cell2_vbat_mv();
	log_data.bat_status = bq40z50_get_battery_status_base(di);
	log_data.safe_status = bq40z50_get_safety_status_base(di);
	log_data.pf_status = bq40z50_get_pf_status_base(di);
	log_data.op_status = bq40z50_get_operation_status_base(di);

	snprintf(buffer, size, "%-7d%-7d%-7d%-7d%-7d%-7d%-7d%-7d%-7d"
		"%-7d%-7d%-7d%-7d%-10x%-10x%-10x",
		log_data.temp, log_data.vbat, log_data.ibat,
		log_data.avg_ibat, log_data.rm, log_data.soc,
		log_data.fcc, log_data.ibat_th, log_data.vbat_th, log_data.cycle_count,
		log_data.cell1_vol, log_data.cell2_vol, log_data.bat_status, log_data.safe_status,
		log_data.pf_status, log_data.op_status);

	return 0;
}

static int bq40z50_get_log_head(char *buffer, int size, void *dev_data)
{
	struct bq40z50_device_info *di = dev_data;

	if (!buffer || !di)
		return -EPERM;

	snprintf(buffer, size,
		"Temp   Vbat   Ibat   AIbat  Rm     Soc    Fcc    dIbat  dVbat  cycle"
		"  Vcell1 Vcell2 batS   safeS     pfS       opS       ");

	return 0;
}

static struct power_log_ops bq40z50_log_ops = {
	.dev_name = "bq40z50",
	.dump_log_head = bq40z50_get_log_head,
	.dump_log_content = bq40z50_dump_log_data,
};

static struct coul_merge_drv_ops bq40z50_merge_cell1_ops = {
	.is_coul_ready = bq40z50_is_ready,
	.is_battery_exist = bq40z50_is_battery_exist,
	.is_battery_reach_threshold = bq40z50_is_battery_reach_threshold,
	.battery_brand = bq40z50_get_battery_brand,
	.battery_voltage = bq40z50_get_battery_cell1_vol,
	.battery_voltage_uv = bq40z50_get_battery_cell1_vol_uv,
	.battery_current = bq40z50_get_battery_curr,
	.fifo_avg_current = bq40z50_get_battery_curr,
	.battery_current_avg = bq40z50_get_battery_avgcurr,
	.battery_resistance = bq40z50_get_battery_resistance,
	.battery_unfiltered_capacity = bq40z50_battery_unfiltered_soc,
	.battery_capacity = bq40z50_get_battery_soc,
	.battery_temperature = bq40z50_get_cell1_temp,
	.battery_temperature_for_charger = bq40z50_get_cell1_temp,
	.battery_rm = bq40z50_get_battery_cell_rm,
	.battery_fcc = bq40z50_get_battery_cell_fcc,
	.battery_fcc_design = bq40z50_get_battery_cell_dc,
	.battery_tte = bq40z50_get_battery_tte,
	.battery_ttf = bq40z50_get_battery_ttf,
	.battery_health = bq40z50_get_battery_health,
	.battery_technology = bq40z50_get_battery_technology,
	.battery_charge_params = bq40z50_get_battery_charge_params,
	.battery_vbat_max = bq40z50_get_battery_vbat_max,
	.battery_cycle_count = bq40z50_get_battery_cycle,
	.charger_event_rcv = bq40z50_battery_charger_event_rcv,
	.get_battery_limit_fcc = bq40z50_get_battery_cell_fcc,
	.coul_is_fcc_debounce = bq40z50_is_fcc_debounce,
	.set_hltherm_flag = NULL,
	.get_hltherm_flag = NULL,
	.battery_cc = bq40z50_get_battery_cell_rm,
	.get_qmax = bq40z50_get_battery_cell_dc,
	.get_desired_charging_current = bq40z50_get_desired_charging_current,
	.get_desired_charging_voltage = bq40z50_get_desired_charging_voltage,
	.get_last_soc = bq40z50_get_last_capacity,
	.set_last_soc = bq40z50_set_last_capacity,
	.is_smart_battery = bq40z50_is_smart_battery,
};

static struct coul_merge_drv_ops bq40z50_merge_cell2_ops = {
	.is_coul_ready = bq40z50_is_ready,
	.is_battery_exist = bq40z50_is_battery_exist,
	.is_battery_reach_threshold = bq40z50_is_battery_reach_threshold,
	.battery_brand = bq40z50_get_battery_brand,
	.battery_voltage = bq40z50_get_battery_cell2_vol,
	.battery_voltage_uv = bq40z50_get_battery_cell2_vol_uv,
	.battery_current = bq40z50_get_battery_curr,
	.fifo_avg_current = bq40z50_get_battery_curr,
	.battery_current_avg = bq40z50_get_battery_avgcurr,
	.battery_resistance = bq40z50_get_battery_resistance,
	.battery_unfiltered_capacity = bq40z50_battery_unfiltered_soc,
	.battery_capacity = bq40z50_get_battery_soc,
	.battery_temperature = bq40z50_get_cell2_temp,
	.battery_temperature_for_charger = bq40z50_get_cell2_temp,
	.battery_rm = bq40z50_get_battery_cell_rm,
	.battery_fcc = bq40z50_get_battery_cell_fcc,
	.battery_fcc_design = bq40z50_get_battery_cell_dc,
	.battery_tte = bq40z50_get_battery_tte,
	.battery_ttf = bq40z50_get_battery_ttf,
	.battery_health = bq40z50_get_battery_health,
	.battery_technology = bq40z50_get_battery_technology,
	.battery_vbat_max = bq40z50_get_battery_vbat_max,
	.battery_cycle_count = bq40z50_get_battery_cycle,
	.charger_event_rcv = bq40z50_battery_charger_event_rcv,
	.get_battery_limit_fcc = bq40z50_get_battery_cell_fcc,
	.coul_is_fcc_debounce = bq40z50_is_fcc_debounce,
	.set_hltherm_flag = NULL,
	.get_hltherm_flag = NULL,
	.battery_cc = bq40z50_get_battery_cell_rm,
	.get_qmax = bq40z50_get_battery_cell_dc,
	.get_desired_charging_current = bq40z50_get_desired_charging_current,
	.get_desired_charging_voltage = bq40z50_get_desired_charging_voltage,
	.get_last_soc = bq40z50_get_last_capacity,
	.set_last_soc = bq40z50_set_last_capacity,
};

#ifdef CONFIG_HUAWEI_BATTERY_VOLTAGE
struct hw_batt_vol_ops bq40z50_cell1_vbatt_ops = {
	.get_batt_vol = bq40z50_get_cell1_vbat_mv,
};

struct hw_batt_vol_ops bq40z50_cell2_vbatt_ops = {
	.get_batt_vol = bq40z50_get_cell2_vbat_mv,
};

struct hw_batt_vol_ops bq40z50_all_vbatt_ops = {
	.get_batt_vol = bq40z50_get_all_vbat_mv,
};
#endif /* CONFIG_HUAWEI_BATTERY_VOLTAGE */

int bq40z50_ops_register_hisi(struct bq40z50_device_info *di)
{
	int ret = 0;

	bq40z50_log_ops.dev_data = (void *)di;
	power_log_ops_register(&bq40z50_log_ops);

#ifdef CONFIG_HUAWEI_BATTERY_VOLTAGE
	ret += hw_battery_voltage_ops_register(&bq40z50_cell1_vbatt_ops, "cell1");
	ret += hw_battery_voltage_ops_register(&bq40z50_cell2_vbatt_ops, "cell2");
	ret += hw_battery_voltage_ops_register(&bq40z50_all_vbatt_ops, "cell_all");
#endif /* CONFIG_HUAWEI_BATTERY_VOLTAGE */

	ret += coul_merge_drv_coul_ops_register(&bq40z50_merge_cell1_ops, di, 0, "battery_gauge");
	ret += coul_merge_drv_coul_ops_register(&bq40z50_merge_cell2_ops, di, 1, "battery_gauge_aux");

	return ret;
}
