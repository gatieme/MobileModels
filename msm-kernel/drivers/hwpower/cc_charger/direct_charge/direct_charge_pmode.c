/*
 * direct_charge_pmode.c
 *
 * direct charge pmode driver
 *
 * Copyright (c) 2022-2022 Huawei Technologies Co., Ltd.
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

#include <chipset_common/hwpower/common_module/power_algorithm.h>
#include <chipset_common/hwpower/common_module/power_common_macro.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_common.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_ic.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_pmode.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_turbo.h>
#include <huawei_platform/hwpower/common_module/power_platform.h>
#include <huawei_platform/power/direct_charger/direct_charger.h>
#include <huawei_platform/power/battery_voltage.h>

#ifdef HWLOG_TAG
#undef HWLOG_TAG
#endif

#define HWLOG_TAG direct_charge_pmode
HWLOG_REGIST();

enum pmode_table_para {
	PMODE_LOCAL_MODE = 0,
	PMODE_LOCAL_EN,
	PMODE_ADP_EN,
	PMODE_ADP_MODE = 0,
	PMODE_RATIO,
	PMODE_BASE_VOLT,
	PMODE_MAX_CUR_PRODUCT,
	PMODE_MAX_CUR_ADP,
	PMODE_MAX_CUR_CABLE,
	PMODE_MAX_PWR,
	PMODE_END,
};

struct pmode_table {
	unsigned int local_mode;
	const char *mode_name;
	bool local_en;
	enum dc_dis_flag dis_flag;
	unsigned int adp_mode;
	bool adp_en;
	int ratio;
	int base_volt;
	int max_cur_product;
	int max_cur_adp;
	int max_cur_cable;
	int max_pwr;
};

static struct pmode_table g_pmode_tbl[] = {
	{ LVC_MODE, "lvc_mode", false, 0, ADAPTER_SUPPORT_LVC, false, 1, 0, 0, 0, 0, 0 },
	{ SC_MODE, "sc_mode", false, 0, ADAPTER_SUPPORT_SC, false, 2, 0, 0, 0, 0, 0 },
	{ SC4_MODE, "sc4_mode", false, 0, ADAPTER_SUPPORT_SC4, false, 4, 0, 0, 0, 0, 0 },
};
#define DC_PMODE_TBL_SIZE ARRAY_SIZE(g_pmode_tbl)

static struct pmode_table *dc_get_pmode_table(void)
{
	return g_pmode_tbl;
}

int dc_get_pmode_max_pwr(unsigned int mode)
{
	int i;
	struct pmode_table *tbl = dc_get_pmode_table();

	for (i = 0; i < DC_PMODE_TBL_SIZE; i++) {
		if (tbl[i].local_mode & mode)
			return tbl[i].max_pwr;
	}

	return 0;
}

void dc_clear_pmode_data(void)
{
	int i;
	struct pmode_table *tbl = dc_get_pmode_table();

	hwlog_info("%s\n", __func__);
	for (i = 0; i < DC_PMODE_TBL_SIZE; i++) {
		tbl[i].local_en = false;
		tbl[i].adp_en = false;
		tbl[i].base_volt = 0;
		tbl[i].max_cur_product = 0;
		tbl[i].max_cur_adp = 0;
		tbl[i].max_cur_cable = 0;
		tbl[i].max_pwr = 0;
	}
}

static void dc_updata_local_en(struct pmode_table *tbl, bool cc_safe, bool dfg_online)
{
	int bat_vol = hw_battery_get_series_num() * BAT_RATED_VOLT;
	struct direct_charge_device *l_di = direct_charge_get_di_by_mode(tbl->local_mode);

	if (!l_di || l_di->dc_err_report_flag || l_di->pri_inversion || l_di->force_disable ||
		(l_di->dfg_disable && dfg_online))
		return;

	if ((((tbl->local_mode == LVC_MODE) && (!l_di->cc_protect || cc_safe)) ||
		((tbl->local_mode > LVC_MODE) && (l_di->cc_unsafe_sc_enable || cc_safe))) &&
		(l_di->dc_stage != DC_STAGE_CHARGE_DONE)) {
		l_di->cc_safe = cc_safe;
		tbl->base_volt = l_di->dc_volt_ratio * bat_vol;
		tbl->local_en = true;
	}
}

void dc_enable_mode(unsigned int reason, unsigned int mode)
{
	int i;
	struct pmode_table *tbl = dc_get_pmode_table();

	for (i = 0; i < DC_PMODE_TBL_SIZE; i++) {
		if (tbl[i].local_mode & mode)
			tbl[i].dis_flag &= ~reason;
	}
}

void dc_disable_mode(unsigned int reason, unsigned int mode)
{
	int i;
	struct pmode_table *tbl = dc_get_pmode_table();

	for (i = 0; i < DC_PMODE_TBL_SIZE; i++) {
		if (tbl[i].local_mode & mode)
			tbl[i].dis_flag |= reason;
	}
}

int dc_init_local_mode(void)
{
	unsigned int local_mode;
	bool cc_safe, dfg_online;
	int i;
	struct pmode_table *tbl = dc_get_pmode_table();

	if (direct_charge_check_charge_done())
		return -1;

	if (dc_adpt_get_inherent_info(ADAP_ANTIFAKE_FAILED_CNT) >= DC_ERR_CNT_MAX) {
		hwlog_info("antifake failed exceed %u times, dc is disabled\n",
			DC_ERR_CNT_MAX);
		return -1;
	}

	local_mode = direct_charge_get_local_mode();
	local_mode = direct_charge_update_local_mode(local_mode);
	hwlog_info("local_mode=0x%x\n", local_mode);

	cc_safe = direct_charge_check_port_fault();
	dfg_online = power_platform_check_online_status();

	for (i = 0; i < DC_PMODE_TBL_SIZE; i++) {
		if (!(tbl[i].local_mode & local_mode))
			continue;
		dc_updata_local_en(&tbl[i], cc_safe, dfg_online);
	}

	for (i = 0; i < DC_PMODE_TBL_SIZE; i++) {
		if (tbl[i].local_en)
			return 0;
	}

	direct_charge_set_can_enter_status(false);
	hwlog_info("neither sc4 nor sc nor lvc matched\n");
	return -1;
}

int dc_init_adp_mode(unsigned int *mode)
{
	int i;
	struct pmode_table *tbl = dc_get_pmode_table();

	if (!dc_adpt_detect_ping())
		*mode = dc_adpt_get_adapter_support_mode();

	hwlog_info("adp_mode=0x%x\n", *mode);
	power_event_bnc_notify(POWER_BNT_DC, POWER_NE_DC_ADAPTER_MODE, mode);

	if ((*mode == ADAPTER_TEST_MODE) ||
		(*mode == ADAPTER_SUPPORT_UNDEFINED)) {
		hwlog_info("adapter mode is test mode or undefined mode");
		return -1;
	}

	charge_set_fcp_disable_flag(false, FCP_DISABLE_PLATFORM_VOTER);
	for (i = 0; i < DC_PMODE_TBL_SIZE; i++) {
		if (*mode & tbl[i].adp_mode)
			tbl[i].adp_en = true;
	}

	return 0;
}

void dc_update_mode_power(void)
{
	int i, max_curr;
	struct pmode_table *tbl = dc_get_pmode_table();

	for (i = 0; i < DC_PMODE_TBL_SIZE; i++) {
		if (!(tbl[i].local_en && tbl[i].adp_en))
			continue;

		tbl[i].max_cur_product = direct_charge_get_product_max_current(tbl[i].local_mode) / tbl[i].ratio;
		tbl[i].max_cur_adp = dc_get_adapter_max_current(tbl[i].local_mode, tbl[i].base_volt);

		dc_update_cable_type(tbl[i].local_mode, tbl[i].ratio);
		tbl[i].max_cur_cable = dc_get_cable_max_current(tbl[i].local_mode) / tbl[i].ratio;
		dc_update_cable_max_current(&tbl[i].max_cur_cable);

		hwlog_info("%s %s mode=%d ratio=%d max_cur_product=%d max_cur_adp=%d max_cur_cable=%d\n", __func__,
			tbl[i].mode_name, tbl[i].local_mode, tbl[i].ratio, tbl[i].max_cur_product, tbl[i].max_cur_adp, tbl[i].max_cur_cable);

		max_curr = power_min_positive(tbl[i].max_cur_adp, tbl[i].max_cur_product);
		max_curr = power_min_positive(tbl[i].max_cur_cable, max_curr);
		tbl[i].max_pwr = tbl[i].base_volt * max_curr / POWER_UW_PER_MW;
		hwlog_info("%s %s max_pwr=%d\n", __func__, tbl[i].mode_name, tbl[i].max_pwr);
	}
}

unsigned int dc_get_optimal_mode(void)
{
	int i;
	int max_pwr = 0;
	unsigned int mode = UNDEFINED_MODE;
	struct pmode_table *tbl = dc_get_pmode_table();

	for (i = 0; i < DC_PMODE_TBL_SIZE; i++) {
		if (!(tbl[i].local_en && tbl[i].adp_en))
			continue;

		if (tbl[i].dis_flag) {
			dc_enable_mode(DC_DIS_BY_PRIORITY, tbl[i].local_mode);
			continue;
		}

		if (tbl[i].max_pwr >= max_pwr) {
			max_pwr = tbl[i].max_pwr;
			mode = tbl[i].local_mode;
		}
	}

	hwlog_info("%s mode=%d,max_pwr=%d\n", __func__, mode, max_pwr);
	return mode;
}
