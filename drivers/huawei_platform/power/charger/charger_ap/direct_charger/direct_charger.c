/*
 * direct_charger.c
 *
 * direct charger driver
 *
 * Copyright (c) 2012-2020 Huawei Technologies Co., Ltd.
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

#include <linux/random.h>
#include <chipset_common/hwusb/hw_usb.h>
#include <chipset_common/hwpower/battery/battery_temp.h>
#include <chipset_common/hwpower/battery/battery_cccv.h>
#include <chipset_common/hwpower/common_module/power_algorithm.h>
#include <chipset_common/hwpower/common_module/power_cmdline.h>
#include <chipset_common/hwpower/common_module/power_common_macro.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_dsm.h>
#include <chipset_common/hwpower/common_module/power_interface.h>
#include <chipset_common/hwpower/common_module/power_time.h>
#include <chipset_common/hwpower/common_module/power_wakeup.h>
#include <chipset_common/hwpower/common_module/power_supply_application.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_test.h>
#include <chipset_common/hwpower/hardware_ic/charge_pump.h>
#include <chipset_common/hwpower/protocol/adapter_protocol.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_common.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_pmode.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_turbo.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_sysfs.h>
#include <chipset_common/hwpower/wireless_charge/wireless_tx_pwr_ctrl.h>
#include <chipset_common/hwpower/battery/battery_charge_balance.h>
#include <chipset_common/hwpower/common_module/power_supply_interface.h>
#include <huawei_platform/hwpower/common_module/power_platform.h>
#include <huawei_platform/power/battery_voltage.h>
#include <huawei_platform/power/direct_charger/direct_charger.h>
#include <huawei_platform/usb/hw_pd_dev.h>

#define HWLOG_TAG direct_charge
HWLOG_REGIST();

/* for ops */
static struct direct_charge_device *g_di;

static unsigned int g_dc_mode;

#define CC_UNSAFE_MAX_CURRENT    3000

static const char * const g_dc_stage[DC_STAGE_END] = {
	[DC_STAGE_DEFAULT] = "dc_stage_default",
	[DC_STAGE_ADAPTER_DETECT] = "dc_stage_adapter_detect",
	[DC_STAGE_SWITCH_DETECT] = "dc_stage_switch_detect",
	[DC_STAGE_CHARGE_INIT] = "dc_stage_charge_init",
	[DC_STAGE_SECURITY_CHECK] = "dc_stage_security_check",
	[DC_STAGE_SUCCESS] = "dc_stage_success",
	[DC_STAGE_CHARGING] = "dc_stage_charging",
	[DC_STAGE_CHARGE_DONE] = "dc_stage_charge_done",
};

enum dc_mode_judge_dir {
	UPWARD,
	DOWNWARD,
};

void direct_charge_set_di(struct direct_charge_device *di)
{
	if (di)
		g_di = di;
	else
		hwlog_err("di is null\n");
}

void direct_charge_set_di_by_mode(int mode)
{
	struct direct_charge_device *l_di = NULL;

	switch (mode) {
	case SC4_MODE:
		sc4_get_di(&l_di);
		break;
	case SC_MODE:
		sc_get_di(&l_di);
		break;
	case LVC_MODE:
		lvc_get_di(&l_di);
		break;
	default:
		break;
	}
	g_di = l_di;
}

struct direct_charge_device *direct_charge_get_di(void)
{
	if (!g_di) {
		hwlog_err("g_di is null\n");
		return NULL;
	}

	return g_di;
}

struct direct_charge_device *direct_charge_get_di_by_mode(int mode)
{
	struct direct_charge_device *l_di = NULL;

	switch (mode) {
	case SC4_MODE:
		sc4_get_di(&l_di);
		return l_di;
	case SC_MODE:
		sc_get_di(&l_di);
		return l_di;
	case LVC_MODE:
		lvc_get_di(&l_di);
		return l_di;
	default:
		return NULL;
	}
}

int direct_charge_get_vmax(unsigned int *val)
{
	struct direct_charge_device *l_di = direct_charge_get_di();

	if (!l_di)
		return -ENODEV;

	if (l_di->stage_size > 0)
		*val = l_di->orig_volt_para[l_di->stage_size - 1].vol_th;

	hwlog_info("stage_size=%d, vmax=%d\n", l_di->stage_size, l_di->orig_volt_para[l_di->stage_size - 1]);
	return 0;
}

/* get the stage of direct charge */
unsigned int direct_charge_get_stage_status(void)
{
	struct direct_charge_device *l_di = direct_charge_get_di();

	if (!l_di)
		return DC_STAGE_DEFAULT;

	return l_di->dc_stage;
}

unsigned int direct_charge_get_stage_status_by_mode(int mode)
{
	struct direct_charge_device *l_di = direct_charge_get_di_by_mode(mode);

	if (!l_di)
		return DC_STAGE_DEFAULT;

	return l_di->dc_stage;
}

/* get the stage of direct charge */
const char *direct_charge_get_stage_status_string(unsigned int stage)
{
	if ((stage >= DC_STAGE_BEGIN) && (stage < DC_STAGE_END))
		return g_dc_stage[stage];

	return "illegal stage_status";
}

/* set the stage of direct charge */
void direct_charge_set_stage_status(unsigned int stage)
{
	struct direct_charge_device *l_di = direct_charge_get_di();

	if (!l_di)
		return;

	l_di->dc_stage = stage;

	hwlog_info("set_stage_status: stage=%d\n", l_di->dc_stage);
}

void direct_charge_set_stage_status_default(void)
{
	struct direct_charge_device *lvc_di = NULL;
	struct direct_charge_device *sc_di = NULL;
	struct direct_charge_device *sc4_di = NULL;

	lvc_get_di(&lvc_di);
	sc_get_di(&sc_di);
	sc4_get_di(&sc4_di);

	hwlog_info("set all dc mode to default\n");

	if (lvc_di)
		lvc_di->dc_stage = DC_STAGE_DEFAULT;

	if (sc_di)
		sc_di->dc_stage = DC_STAGE_DEFAULT;

	if (sc4_di)
		sc4_di->dc_stage = DC_STAGE_DEFAULT;
}

int direct_charge_in_charging_stage(void)
{
	if (direct_charge_get_stage_status() == DC_STAGE_CHARGING)
		return DC_IN_CHARGING_STAGE;

	return DC_NOT_IN_CHARGING_STAGE;
}

int direct_charge_get_working_mode(void)
{
	struct direct_charge_device *l_di = direct_charge_get_di();

	if (!l_di)
		return UNDEFINED_MODE;

	return l_di->working_mode;
}

void direct_charge_set_local_mode(int set, unsigned int dc_mode)
{
	if (set == AND_SET)
		g_dc_mode &= dc_mode;

	if (set == OR_SET)
		g_dc_mode |= dc_mode;
}

unsigned int direct_charge_get_local_mode(void)
{
	return g_dc_mode;
}

unsigned int direct_charge_update_local_mode(unsigned int mode)
{
	unsigned int local_mode = mode;
	struct direct_charge_device *lvc_di = NULL;
	struct direct_charge_device *sc_di = NULL;
	struct direct_charge_device *sc4_di = NULL;

	lvc_get_di(&lvc_di);
	sc_get_di(&sc_di);
	sc4_get_di(&sc4_di);
	if (!lvc_di && !sc_di && !sc4_di) {
		hwlog_info("local not support direct_charge\n");
		return UNDEFINED_MODE;
	}
	hwlog_info("original local mode %u\n", mode);

	if (sc4_di) {
		if ((sc4_di->sysfs_enable_charger == 0) &&
			!(sc4_di->sysfs_mainsc_enable_charger ^ sc4_di->sysfs_auxsc_enable_charger)) {
			local_mode &= ~SC4_MODE;
			hwlog_info("disable sc4 mode, local_mode %u\n",
				local_mode);
		}
	}
	if (sc_di) {
		if ((sc_di->sysfs_enable_charger == 0) &&
			!(sc_di->sysfs_mainsc_enable_charger ^ sc_di->sysfs_auxsc_enable_charger)) {
			local_mode &= ~SC_MODE;
			hwlog_info("disable sc mode, local_mode %u\n",
				local_mode);
		}
	}
	if (lvc_di) {
		if (lvc_di->sysfs_enable_charger == 0) {
			local_mode &= ~LVC_MODE;
			hwlog_info("disable lvc mode, local_mode %u\n",
				local_mode);
		}
	}

	return local_mode;
}

int direct_charge_is_failed(void)
{
	struct direct_charge_device *lvc_di = NULL;
	struct direct_charge_device *sc_di = NULL;
	struct direct_charge_device *sc4_di = NULL;

	lvc_get_di(&lvc_di);
	sc_get_di(&sc_di);
	sc4_get_di(&sc4_di);

	if (!lvc_di && !sc_di && !sc4_di) {
		hwlog_info("lvc_di sc_di and sc4_di is NULL\n");
		return 1;
	}

	if (direct_charge_get_can_enter_status() == false) {
		hwlog_info("can not enter dc\n");
		return 1;
	}

	if (lvc_di) {
		if (lvc_di->error_cnt >= DC_ERR_CNT_MAX) {
			hwlog_info("lvc error exceed retry max\n");
			return 1;
		} else {
			return 0;
		}
	}

	if (sc_di) {
		if (sc_di->error_cnt >= DC_ERR_CNT_MAX) {
			hwlog_info("sc error exceed retry max\n");
			return 1;
		} else {
			return 0;
		}
	}

	if (sc4_di) {
		if (sc4_di->error_cnt >= DC_ERR_CNT_MAX) {
			hwlog_info("sc4 error exceed retry max\n");
			return 1;
		} else {
			return 0;
		}
	}

	return 0;
}

void direct_charge_set_disable_flags(int val, int type)
{
	lvc_set_disable_flags(val, type);
	sc_set_disable_flags(val, type);
	sc4_set_disable_flags(val, type);
}

int direct_charge_get_info(enum direct_charge_info_type type, int *value)
{
	struct direct_charge_device *l_di = direct_charge_get_di();

	if (!l_di || !value)
		return -1;

	switch (type) {
	case CC_CABLE_DETECT_OK:
		if (dc_get_cable_inherent_info(DC_CABLE_DETECT_OK) == CABLE_DETECT_NOK)
			*value = 0;
		else
			*value = 1;
		return 0;
	default:
		return -1;
	}
}

/* get the maximum current allowed by direct charging at specified temp */
int direct_charge_battery_temp_handler(int value)
{
	int i;
	struct direct_charge_device *l_di = direct_charge_get_di();

	if (!l_di)
		return 0;

	for (i = 0; i < DC_TEMP_LEVEL; ++i) {
		if ((value >= l_di->temp_para[i].temp_min) &&
			(value < l_di->temp_para[i].temp_max))
			return l_di->temp_para[i].temp_cur_max;
	}

	hwlog_err("current temp is illegal, temp=%d\n", value);
	return 0;
}

/* get the maximum current with specified battery */
static int direct_charge_get_battery_max_current(int mode)
{
	int i;
	int max_cur;
	const char *brand = NULL;
	int temp = 25; /* normal temperature is 25c */
	struct direct_charge_device *l_di = direct_charge_get_di_by_mode(mode);

	if (!l_di)
		return -1;

	max_cur = l_di->orig_volt_para_p[0].volt_info[0].cur_th_high;
	brand = power_supply_app_get_bat_brand();

	for (i = 0; i < l_di->stage_group_size; i++) {
		if (!l_di->orig_volt_para_p[i].bat_info.parse_ok)
			continue;

		if (!strstr(brand, l_di->orig_volt_para_p[i].bat_info.batid))
			continue;

		if ((temp >= l_di->orig_volt_para_p[i].bat_info.temp_high) ||
			(temp < l_di->orig_volt_para_p[i].bat_info.temp_low))
			continue;

		max_cur = l_di->orig_volt_para_p[i].volt_info[0].cur_th_high;
		break;
	}

	hwlog_info("stage_group_size=%d, bat_brand=%s, bat_max_cur=%d\n",
		l_di->stage_group_size, brand, max_cur);

	return max_cur;
}

int direct_charge_get_product_max_current(int mode)
{
	int bat_limit;
	int bat_vol = hw_battery_get_series_num() * BAT_RATED_VOLT;
	struct direct_charge_device *l_di = direct_charge_get_di_by_mode(mode);

	if (!l_di)
		return -EINVAL;

	if (l_di->product_max_pwr)
		bat_limit = l_di->product_max_pwr * POWER_UW_PER_MW / bat_vol;
	else
		bat_limit = direct_charge_get_battery_max_current(mode);

	return bat_limit;
}

bool direct_charge_get_stop_charging_complete_flag(void)
{
	struct direct_charge_device *l_di = direct_charge_get_di();

	if (!l_di)
		return true;

	if (l_di->scp_stop_charging_complete_flag) {
		hwlog_info("scp_stop_charging_complete_flag is set\n");
		return true;
	}

	hwlog_info("scp_stop_charging_complete_flag is false\n");
	return false;
}

int direct_charge_get_vbus(void)
{
	struct direct_charge_device *l_di = direct_charge_get_di();

	if (!l_di)
		return 0;

	return l_di->vadapt;
}

int direct_charge_get_ibus(void)
{
	struct direct_charge_device *l_di = direct_charge_get_di();

	if (!l_di)
		return 0;

	return l_di->iadapt;
}

static int direct_charge_get_bat_voltage(int *value)
{
	int btb_vol;
	struct direct_charge_device *l_di = direct_charge_get_di();

	if (!l_di)
		return -1;

	/* last cc&cv use the higher vbat */
	if (l_di->use_higher_vbat && (l_di->cur_stage >= (DOUBLE_SIZE * l_di->stage_size - 2)))
		btb_vol = dcm_get_ic_max_vbtb_with_comp(l_di->working_mode,
			l_di->comp_para.vbat_comp);
	else
		btb_vol = dcm_get_ic_vbtb_with_comp(l_di->working_mode, l_di->cur_mode,
			l_di->comp_para.vbat_comp);

	if (btb_vol <= 0) {
		*value = 0;
		dc_ctrl_fill_eh_buf_and_set_err_flag_true(DC_EH_GET_VBAT, NULL);
		return -1;
	}

	*value = btb_vol;
	return 0;
}

int direct_charge_get_bat_current(int *value)
{
	struct direct_charge_device *l_di = direct_charge_get_di();

	if (!l_di)
		return -1;

	if (dcm_get_total_ibat(l_di->working_mode, l_di->cur_mode, value)) {
		*value = 0;
		dc_ctrl_fill_eh_buf_and_set_err_flag_true(DC_EH_GET_IBAT, NULL);
		return -1;
	}

	return 0;
}

int direct_charge_get_bat_sys_voltage(int *value)
{
	/* default one battery */
	if (hw_battery_get_series_num() == 1)
		return direct_charge_get_bat_voltage(value);

	/* get total voltage for multi battery */
	*value = hw_battery_voltage(BAT_ID_ALL);
	return 0;
}

int direct_charge_get_device_vbus(int *value)
{
	struct direct_charge_device *l_di = direct_charge_get_di();

	if (!l_di)
		return -1;

	if (dcm_get_ic_vbus(l_di->working_mode, l_di->cur_mode, value)) {
		*value = 0;
		dc_ctrl_fill_eh_buf_and_set_err_flag_true(DC_EH_GET_DEVICE_VBUS, NULL);
		return -1;
	}

	return 0;
}

int direct_charge_get_device_temp(int *value)
{
	struct direct_charge_device *l_di = direct_charge_get_di();

	if (!l_di)
		return -1;

	if (dcm_get_ic_temp(l_di->working_mode, l_di->cur_mode, value)) {
		*value = 0;
		dc_ctrl_fill_eh_buf_and_set_err_flag_true(DC_EH_GET_DEVICE_TEMP, NULL);
		return -1;
	}

	return 0;
}

int direct_charge_get_device_close_status(void)
{
	struct direct_charge_device *l_di = direct_charge_get_di();

	if (!l_di)
		return 1;

	if (dcm_is_ic_close(l_di->working_mode, l_di->cur_mode)) {
		dc_ctrl_fill_eh_buf_and_set_err_flag_true(DC_EH_DEVICE_IS_CLOSE, NULL);
		return 1;
	}

	return 0;
}

static int direct_charge_get_vbus_vbat(int *vbus, int *vbat)
{
	struct direct_charge_device *l_di = direct_charge_get_di();

	if (!l_di)
		return -1;

	if (dcm_get_ic_status(l_di->working_mode, l_di->cur_mode)) {
		msleep(DC_LS_RECOVERY_DELAY);
		*vbus = power_supply_app_get_usb_voltage_now();
		*vbat = power_supply_app_get_bat_voltage_now();
		hwlog_err("device error, vbus=%d, vbat=%d\n", *vbus, *vbat);
		return 0;
	}

	direct_charge_get_device_vbus(vbus);
	direct_charge_get_bat_voltage(vbat);

	hwlog_info("device_vbus=%d, vbat=%d\n", *vbus, *vbat);
	return 0;
}

void direct_charge_force_disable_dc_path(void)
{
	struct direct_charge_device *l_di = direct_charge_get_di();

	if (!l_di)
		return;

	dcm_enable_ic(l_di->working_mode, l_di->cur_mode, DC_IC_DISABLE);
	dc_close_aux_wired_channel();
}

extern void pmic_set_buckboost_mode(int mode);
int direct_charge_init_adapter_and_device(void)
{
	char tmp_buf[ERR_NO_STRING_SIZE] = { 0 };
	int ret;
	struct direct_charge_device *l_di = direct_charge_get_di();

	if (!l_di)
		return -1;

	power_platform_notify_direct_charge_status(true);

	ret = dc_init_adapter(l_di->local_mode, 5000); /* 5000:adapter init vset */
	if (ret) {
		snprintf(tmp_buf, sizeof(tmp_buf), "adapter data init fail\n");
		goto fail_init;
	}

	if (dcm_set_ic_threshold_enable(l_di->working_mode, CHARGE_MULTI_IC, 1))
		hwlog_info("direct charge set ic threshold error\n");

	if (dcm_init_ic(l_di->working_mode, l_di->cur_mode)) {
		snprintf(tmp_buf, sizeof(tmp_buf), "device ls init fail\n");
		goto fail_init;
	}

	if (dcm_init_batinfo(l_di->working_mode, l_di->cur_mode)) {
		snprintf(tmp_buf, sizeof(tmp_buf), "device bi init fail\n");
		goto fail_init;
	}

	/*
	 * Fix a hardware issue, need set pmu buckboost ccm mode during sc4 charging,
	 * and restore to default mode when direct_charge_stop_charging.
	 */
	if (l_di->pmu_mode_set_flag)
		pmic_set_buckboost_mode(0);

	hwlog_info("direct charge init succ\n");
	return 0;

fail_init:
	power_platform_notify_direct_charge_status(false);

	dc_fill_eh_buf(l_di->dsm_buff, sizeof(l_di->dsm_buff),
		DC_EH_INIT_DIRECT_CHARGE, tmp_buf);

	return -1;
}

/* switch charging path to normal charging path */
int direct_charge_switch_path_to_normal_charging(void)
{
	int ret;

	msleep(WAIT_LS_DISCHARGE); /* need to wait device discharge */

	/* no need to check the return value in here */
	hw_usb_ldo_supply_disable(HW_USB_LDO_CTRL_DIRECT_CHARGE);

	ret = dc_close_dc_channel();

	if (pmic_vbus_irq_is_enabled())
		charge_ignore_plug_event(false);

	return ret;
}

/* switch charging path to lvc or sc charging path */
int direct_charge_switch_path_to_dc_charging(void)
{
	struct direct_charge_device *l_di = direct_charge_get_di();

	if (!l_di)
		return -1;

	if (pmic_vbus_irq_is_enabled()) {
		l_di->cutoff_normal_flag = 1;
		charge_ignore_plug_event(true);
	}

	hw_usb_ldo_supply_enable(HW_USB_LDO_CTRL_DIRECT_CHARGE);

	if (l_di->scp_work_on_charger) {
		dc_adapter_protocol_power_supply(ENABLE);
		charge_set_hiz_enable_by_direct_charge(HIZ_MODE_ENABLE);
	}

	msleep(DT_MSLEEP_100MS);
	return dc_open_dc_channel();
}

static int dc_open_charging_path_fail_handler(char *buf, int len,
	struct direct_charge_device *di)
{
	int soc = power_platform_get_battery_ui_capacity();

	dc_fill_eh_buf(di->dsm_buff, sizeof(di->dsm_buff),
		DC_EH_OPEN_DIRECT_CHARGE_PATH, buf);
	if (soc >= BATTERY_CAPACITY_HIGH_TH) {
		di->dc_open_retry_cnt += 1;
		hwlog_info("current battery capacity is %d, over threshold %d\n",
			soc, BATTERY_CAPACITY_HIGH_TH);
	}

	dc_show_realtime_charging_info(di->working_mode, di->cur_mode);
	hwlog_err("charging path open fail\n");
	return -1;
}

static void dc_set_adapter_before_open_charging_path(
	struct direct_charge_device *di)
{
	int vbat = 0;

	direct_charge_get_bat_sys_voltage(&vbat);
	di->adaptor_vset = vbat * di->dc_volt_ratio + di->init_delt_vset;
	di->adaptor_iset = CURRENT_SET_FOR_RES_DETECT + di->init_delt_iset +
		dc_get_gain_ibus();
	dc_set_adapter_voltage_step_by_step(di->local_mode, di->cur_mode, STEP_VOL_START, di->adaptor_vset);
	dc_set_adapter_current(di->local_mode, di->adaptor_iset);
}

static bool dc_open_charging_path_succ(char *buf, int len,
	struct direct_charge_device *di)
{
	int ibus = 0;
	int vbat = 0;
	int max_dc_bat_vol;
	int adjust_times = MAX_TIMES_FOR_SET_ADAPTER_VOL;
	int vbat_max = power_supply_app_get_bat_voltage_max();

	max_dc_bat_vol = vbat_max > di->max_dc_bat_vol ?
		vbat_max : di->max_dc_bat_vol;
	dc_get_device_ibus(&ibus);
	hwlog_info("[%d]: Vapt_set=%d, Ibus_ls=%d Vbat_max=%d\n",
		adjust_times, di->adaptor_vset, ibus, max_dc_bat_vol);

	/* adjust adapter voltage until current to 800ma */
	while (ibus < MIN_CURRENT_FOR_RES_DETECT) {
		direct_charge_get_bat_voltage(&vbat);
		if ((di->battery_connect_mode != BAT_SERIAL_MODE) &&
			max_dc_bat_vol < vbat) {
			snprintf(buf, len - 1, "vbat too high, Vapt_set=%d\n", vbat);
			return false;
		}

		if (!(adjust_times % DC_OPEN_CHECK_IC_CYCLE) &&
			dcm_is_ic_close(di->working_mode, di->cur_mode)) {
			hwlog_info("ic is closed, need open\n");
			if (dcm_enable_ic(di->working_mode, di->cur_mode, DC_IC_ENABLE)) {
				snprintf(buf, len - 1, "ls enable fail\n");
				return false;
			}
		}

		adjust_times--;
		if (adjust_times == 0) {
			snprintf(buf, len - 1,
				"try too many times, Ibus_ls=%d\n", ibus);
			return false;
		}

		di->adaptor_vset += di->vstep;
		dc_set_adapter_voltage(di->working_mode, &di->adaptor_vset);
		if (dc_need_exit() || dc_get_stop_charging_flag())
			return false;
		/* delay 5ms */
		usleep_range(5000, 5100);
		dc_get_device_ibus(&ibus);
		hwlog_info("[%d]: Vapt_set=%d, Ibus_ls=%d\n",
			adjust_times, di->adaptor_vset, ibus);
	}

	return true;
}

int direct_charge_open_charging_path(void)
{
	char buf[ERR_NO_STRING_SIZE] = { 0 };
	struct direct_charge_device *l_di = direct_charge_get_di();

	if (!l_di)
		return -1;

	dc_set_adapter_before_open_charging_path(l_di);
	if (dc_get_stop_charging_flag())
		return -1;

	power_msleep(DT_MSLEEP_50MS, DT_MSLEEP_25MS, dc_need_exit);

	/* second: enable lvc or sc device */
	dc_open_aux_wired_channel();
	if (dcm_enable_ic(l_di->working_mode, l_di->cur_mode, DC_IC_ENABLE)) {
		snprintf(buf, sizeof(buf), "ls enable fail\n");
		return dc_open_charging_path_fail_handler(buf, sizeof(buf), l_di);
	}
	if (dc_get_stop_charging_flag())
		return -1;

	if (dc_adpt_skip_security_check(l_di->local_mode)) {
		hwlog_info("iwatt lvc skip security check\n");
		return 0;
	}

	power_usleep(DT_USLEEP_10MS);
	if (!dc_open_charging_path_succ(buf, sizeof(buf), l_di))
		return dc_open_charging_path_fail_handler(buf, sizeof(buf), l_di);

	hwlog_info("charging path open succ\n");
	return 0;
}

int direct_charge_detect_adapter_again(void)
{
	int ret;
	struct direct_charge_device *l_di = direct_charge_get_di();

	if (!l_di)
		return -1;

	ret = dc_adpt_detect_ping();
	if (ret) {
		direct_charge_set_stage_status(DC_STAGE_DEFAULT);
		return -1;
	}

	dc_test_set_adapter_test_result(l_di->working_mode, AT_DETECT_SUCC);
	return 0;
}

static void direct_charge_reset_para_in_stop(struct direct_charge_device *di)
{
	if (!di)
		return;

	di->error_cnt = 0;
	di->otp_cnt = 0;
	di->adp_otp_cnt = 0;
	di->reverse_ocp_cnt = 0;
	di->dc_open_retry_cnt = 0;
	dc_mmi_set_succ_flag(di->working_mode, DC_ERROR_ADAPTER_DETECT);
	dc_mmi_set_test_flag(false);
	di->dc_succ_flag = DC_ERROR;
	di->dc_err_report_flag = FALSE;
	di->sc_conv_ocp_count = 0;
	di->low_temp_hysteresis = 0;
	di->high_temp_hysteresis = 0;
	di->max_pwr = 0;
	di->pri_inversion = false;
	dc_clear_cable_mode_info(di->local_mode);
	dc_clean_eh_buf(di->dsm_buff, sizeof(di->dsm_buff));
	dc_reset_err_type_cnt(di->err_type_cnt, sizeof(di->err_type_cnt));
	di->cc_safe = true;
}

static void direct_charge_reset_para_in_exit(struct direct_charge_device *di)
{
	if (!di)
		return;

	dc_mmi_set_succ_flag(di->working_mode, DC_ERROR_ADAPTER_DETECT);
	dc_mmi_set_test_flag(false);
	dc_set_stop_charging_flag(false);
	di->dc_succ_flag = DC_ERROR;
	di->scp_stop_charging_flag_info = 0;
	di->cur_stage = 0;
	di->pre_stage = 0;
	di->vbat = 0;
	di->ibat = 0;
	di->vadapt = 0;
	di->iadapt = 0;
	di->ls_vbus = 0;
	di->ls_ibus = 0;
	di->compensate_v = 0;
	di->ibat_abnormal_cnt = 0;
	di->dc_open_retry_cnt = 0;
	di->otp_cnt = 0;
	di->adp_otp_cnt = 0;
	di->reverse_ocp_cnt = 0;
	di->dc_err_report_flag = FALSE;
	di->cc_safe = true;
	di->low_temp_hysteresis = 0;
	di->high_temp_hysteresis = 0;
	di->max_pwr = 0;
	di->pri_inversion = false;
	di->multi_ic_check_info.limit_current = di->iin_thermal_default;
	di->multi_ic_error_cnt = 0;
	di->lvc_mos_dts.err_cnt = 0;
	dc_adpt_clear_inherent_info();
	dc_clear_cable_mode_info(di->local_mode);
	dc_clean_eh_buf(di->dsm_buff, sizeof(di->dsm_buff));
	power_if_kernel_sysfs_set(POWER_IF_OP_TYPE_ADAPTER_PROTOCOL, POWER_IF_SYSFS_ADAPTER_PROTOCOL, 0);
	memset(di->multi_ic_check_info.report_info, 0,
		sizeof(di->multi_ic_check_info.report_info));
	memset(di->multi_ic_check_info.ibus_error_num, 0,
		sizeof(di->multi_ic_check_info.ibus_error_num));
	memset(di->multi_ic_check_info.vbat_error_num, 0,
		sizeof(di->multi_ic_check_info.vbat_error_num));
	memset(di->multi_ic_check_info.tbat_error_num, 0,
		sizeof(di->multi_ic_check_info.tbat_error_num));
	memset(di->multi_ic_mode_para.ic_error_cnt, 0,
		sizeof(di->multi_ic_mode_para.ic_error_cnt));
}

void direct_charge_exit(void)
{
	struct direct_charge_device *lvc_di = NULL;
	struct direct_charge_device *sc_di = NULL;
	struct direct_charge_device *sc4_di = NULL;

	hwlog_info("exit\n");

	lvc_get_di(&lvc_di);
	sc_get_di(&sc_di);
	sc4_get_di(&sc4_di);

	if (!lvc_di && !sc_di && !sc4_di) {
		hwlog_info("local not support direct_charge\n");
		return;
	}

	if (!power_cmdline_is_factory_mode())
		direct_charge_set_disable_flags(DC_CLEAR_DISABLE_FLAGS,
			DC_DISABLE_SYS_NODE);

	direct_charge_set_can_enter_status(true);
	direct_charge_reset_para_in_exit(lvc_di);
	direct_charge_reset_para_in_exit(sc_di);
	direct_charge_reset_para_in_exit(sc4_di);
	dc_clear_cable_inherent_info_in_exit();
	dc_adpt_clear_inherent_info();
	dc_pmode_clear_data_in_exit();
	dc_comm_set_first_check_completed(false);
}

int direct_charge_get_cutoff_normal_flag(void)
{
	struct direct_charge_device *l_di = direct_charge_get_di();

	if (!l_di)
		return 0;

	return l_di->cutoff_normal_flag;
}

void direct_charge_update_cutoff_normal_flag(void)
{
	struct direct_charge_device *lvc_di = NULL;
	struct direct_charge_device *sc_di = NULL;
	struct direct_charge_device *sc4_di = NULL;
	int cutoff_normal_flag = 0;

	hwlog_info("update_cutoff_normal_flag\n");

	lvc_get_di(&lvc_di);
	sc_get_di(&sc_di);
	sc4_get_di(&sc4_di);

	if (lvc_di)
		cutoff_normal_flag += lvc_di->cutoff_normal_flag;

	if (sc_di)
		cutoff_normal_flag += sc_di->cutoff_normal_flag;

	if (sc4_di)
		cutoff_normal_flag += sc4_di->cutoff_normal_flag;

	if (cutoff_normal_flag && pmic_vbus_irq_is_enabled()) {
		if (lvc_di) {
			if (lvc_di->cutoff_normal_flag) {
				lvc_di->cutoff_normal_flag = 0;
				hwlog_info("clear lvc cutoff_normal_flag\n");
			}
		}

		if (sc_di) {
			if (sc_di->cutoff_normal_flag) {
				sc_di->cutoff_normal_flag = 0;
				hwlog_info("clear sc cutoff_normal_flag\n");
			}
		}

		if (sc4_di) {
			if (sc4_di->cutoff_normal_flag) {
				sc4_di->cutoff_normal_flag = 0;
				hwlog_info("clear sc4 cutoff_normal_flag\n");
			}
		}
	} else {
		if (lvc_di)
			direct_charge_reset_para_in_stop(lvc_di);

		if (sc_di)
			direct_charge_reset_para_in_stop(sc_di);

		if (sc4_di)
			direct_charge_reset_para_in_stop(sc4_di);
		dc_adpt_clear_inherent_info();
	}
}

static int direct_charge_get_imax_with_cur_mode(struct direct_charge_device *di)
{
	int ibat = 0;

	if (di->multi_ic_mode_para.support_multi_ic && di->cur_mode != CHARGE_MULTI_IC) {
		dcm_get_ic_max_ibat(di->working_mode, di->cur_mode, &ibat);
		if (!ibat)
			ibat = DC_SINGLEIC_CURRENT_LIMIT;
	}

	return ibat;
}

bool direct_charge_check_timeout(void)
{
	u32 delta_time;
	struct direct_charge_device *l_di = direct_charge_get_di();
	int time = 0;

	if (!l_di)
		return false;

	delta_time = power_get_current_kernel_time().tv_sec - dc_ctrl_get_start_time();
	if (direct_charge_turbo_get_charge_time(l_di->working_mode, &time, l_di->adapter_type))
		time = l_di->charge_time;

	if ((time > 0) && (delta_time > time))
		return true;

	return false;
}

static int direct_charge_get_imax_by_time(struct direct_charge_device *di)
{
	u32 delta_time;
	int i;
	struct direct_charge_time_para *para = NULL;
	int size = 0;

	if (direct_charge_turbo_get_time_para(di->working_mode, &para, &size, di->adapter_type)) {
		if (!di->time_para_parse_ok)
			return 0;
		para = di->time_para;
		size = DC_TIME_PARA_LEVEL;
	}

	if (!para || !size)
		return 0;

	delta_time = power_get_current_kernel_time().tv_sec - dc_ctrl_get_start_time();
	for (i = 0; i < size; i++) {
		if (delta_time >= para[i].time_th)
			break;
	}

	if (i >= size)
		return 0;

	hwlog_info("%s ibat_max=%d\n", __func__, para[i].ibat_max);
	return para[i].ibat_max;
}

static int direct_charge_get_imax_by_batt_balance(struct direct_charge_device *di)
{
	struct bat_chg_balance_info info[BAT_BALANCE_COUNT];
	u32 bat_num = 1; /* default one battery */
	struct bat_chg_balance_cur result;
	struct power_supply *psy = NULL;

	if (!power_supply_check_psy_available("battery_gauge", &psy))
		return 0;

	/* update 1st battery info */
	power_supply_get_int_property_value("battery_gauge",
		POWER_SUPPLY_PROP_CURRENT_NOW, &info[0].cur);
	info[0].vol = dcm_get_ic_vbtb_with_comp(di->working_mode, CHARGE_IC_MAIN,
		di->multi_ic_check_info.vbat_comp);
	bat_temp_get_temperature(BTB_TEMP_0, &info[0].temp);

	if (power_supply_check_psy_available("battery_gauge_aux", &psy)) {
		bat_num = 2; /* 2: two battery */
		power_supply_get_int_property_value("battery_gauge_aux",
			POWER_SUPPLY_PROP_CURRENT_NOW, &info[1].cur);
		info[1].vol = dcm_get_ic_vbtb_with_comp(di->working_mode, CHARGE_IC_AUX,
			di->multi_ic_check_info.vbat_comp);
		if (info[1].vol < 0)
			info[1].vol = info[0].vol;
		bat_temp_get_temperature(BTB_TEMP_1, &info[1].temp);
	}

	if (bat_chg_balance_get_cur_info(info, bat_num, &result, di->battery_connect_mode))
		return 0;

	hwlog_info("batt_balance_limit = %d", result.total_cur);
	return result.total_cur;
}

void direct_charge_select_charging_param(void)
{
	int cur_th_high;
	int vbat_th;
	int vol_th;
	int tbat = 0;
	int tbat_max_cur;
	int mode_max_cur;
	int time_max_cur;
	int cable_max_cur;
	int adp_max_cur;
	int ichg_thermal_cur;
	int batt_cccv_cur;
	int batt_limit;
	struct direct_charge_device *l_di = direct_charge_get_di();

	if (!l_di)
		return;

	if (l_di->cur_stage == 0) {
		/* 500: unit is 500ma */
		l_di->volt_para[0].cur_th_high -= l_di->sc_conv_ocp_count * 500;
		hwlog_info("sc_conv_ocp_count=%d, cur_th_high[0]=%d\n",
			l_di->sc_conv_ocp_count,
			l_di->volt_para[0].cur_th_high);
	}

	/* unit: mv */
	l_di->compensate_v = l_di->ibat * l_di->compensate_r / POWER_UV_PER_MV;
	/* cur_stage include cc and cv stage so divide 2 */
	vbat_th = l_di->volt_para[l_di->cur_stage / 2].vol_th +
		l_di->compensate_v;
	vol_th = l_di->volt_para[l_di->stage_size - 1].vol_th;
	if (l_di->all_stage_compensate_r_en)
		l_di->cur_vbat_th = vbat_th;
	else
		l_di->cur_vbat_th = vbat_th < vol_th ? vbat_th : vol_th;

	/* cur_stage include cc and cv stage so divide 2 */
	l_di->cur_ibat_th_low = l_di->volt_para[l_di->cur_stage / 2].cur_th_low;

	/* cur_stage include cc and cv stage so divide 2 */
	cur_th_high = l_di->volt_para[l_di->cur_stage / 2].cur_th_high;

	/* step-1: get max current with specified temp */
	bat_temp_get_temperature(BAT_TEMP_MIXED, &tbat);
	tbat_max_cur = direct_charge_battery_temp_handler(tbat);
	if (tbat_max_cur == 0) {
		hwlog_info("temp=%d, can not do direct charging\n", tbat);
		if (tbat < DC_LOW_TEMP_MAX)
			l_di->low_temp_hysteresis = l_di->orig_low_temp_hysteresis;
		if (tbat >= DC_HIGH_TEMP_MAX)
			l_di->high_temp_hysteresis = l_di->orig_high_temp_hysteresis;
		l_di->scp_stop_charging_flag_info = 1;
		power_event_bnc_notify(POWER_BNT_DC, POWER_NE_DC_TEMP_ERR, NULL);
	}
	cur_th_high = cur_th_high > tbat_max_cur ? tbat_max_cur : cur_th_high;

	/* step-2: get max current with adapter */
	adp_max_cur = dc_adpt_get_curr(l_di->local_mode, l_di->adaptor_vset) * l_di->dc_volt_ratio;
	cur_th_high = power_min_positive(cur_th_high, adp_max_cur);
	hwlog_info("adp_max_cur=%d, cur_th_high=%d\n", adp_max_cur, cur_th_high);

	/* step-3: get max current with cable type */
	cable_max_cur = dc_get_cable_curr();
	cur_th_high = power_min_positive(cur_th_high, cable_max_cur);
	hwlog_info("cc_cable=%d, cable_max_cur=%d, cur_th_high=%d\n",
		dc_get_cable_inherent_info(DC_CABLE_DETECT_OK), cable_max_cur, cur_th_high);

	/* step-5: get max current with cur_mode */
	mode_max_cur = direct_charge_get_imax_with_cur_mode(l_di);
	if (mode_max_cur > 0)
		cur_th_high = cur_th_high > mode_max_cur ? mode_max_cur : cur_th_high;

	/* step-6: get max current with time limit */
	time_max_cur = direct_charge_get_imax_by_time(l_di);
	if (time_max_cur > 0)
		cur_th_high = cur_th_high > time_max_cur ? time_max_cur : cur_th_high;

	/* step-7: error check limit current, only multi mode effected */
	if (l_di->multi_ic_check_info.limit_current > 0 && l_di->cur_mode == CHARGE_MULTI_IC)
		cur_th_high = (cur_th_high > l_di->multi_ic_check_info.limit_current) ?
			l_di->multi_ic_check_info.limit_current : cur_th_high;

	/* step-8: get max current with thermal */
	ichg_thermal_cur = dc_sysfs_get_ichg_thermal(l_di->local_mode, l_di->cur_mode);
	if (!dc_mmi_get_test_flag())
		cur_th_high = (cur_th_high > ichg_thermal_cur) ?
			ichg_thermal_cur : cur_th_high;

	/* step-9: get max current with battery cccv */
	batt_cccv_cur = bat_cccv_get_ichg(l_di->vbat);
	cur_th_high = power_min_positive(batt_cccv_cur, cur_th_high);
	hwlog_info("batt_cccv_cur=%d, cur_th_high=%d\n", batt_cccv_cur, cur_th_high);

	batt_limit = direct_charge_get_imax_by_batt_balance(l_di);
	if (batt_limit > 0)
		cur_th_high = cur_th_high > batt_limit ? batt_limit : cur_th_high;

	l_di->cur_ibat_th_high = cur_th_high;

	/* enable sc and limit cur to 3000mA even when cc is unsafe when cc_unsafe_sc_enable is true */
	if (l_di->cc_unsafe_sc_enable && !l_di->cc_safe)
		l_di->cur_ibat_th_high = l_di->cur_ibat_th_high > CC_UNSAFE_MAX_CURRENT ?
			CC_UNSAFE_MAX_CURRENT : l_di->cur_ibat_th_high;
}

static int direct_charge_jump_stage_if_need(int cur_stage)
{
	int i;
	struct direct_charge_device *l_di = direct_charge_get_di();

	if (!l_di)
		return -1;

	/* 2: cc & cv */
	for (i = 0; i < 2 * l_di->stage_size; ++i) {
		if (l_di->stage_need_to_jump[i] == -1)
			return cur_stage;

		if (cur_stage == l_di->stage_need_to_jump[i]) {
			hwlog_info("jump stage to %d\n", cur_stage);
			return direct_charge_jump_stage_if_need(cur_stage + 1);
		}
	}

	return cur_stage;
}

void direct_charge_select_charging_stage(void)
{
	int i;
	int vbat_th;
	int cur_stage = 0;
	int stage_size;
	int vbat = 0;
	int ibat = 0;
	struct direct_charge_device *l_di = direct_charge_get_di();

	if (!l_di)
		return;

	direct_charge_get_bat_voltage(&vbat);
	direct_charge_get_bat_current(&ibat);

	stage_size = l_di->stage_size;
	l_di->vbat = vbat;
	l_di->ibat = ibat;

	if (dc_ctrl_is_ibat_abnormal(l_di->local_mode, l_di->ibat_abnormal_th, &l_di->ibat_abnormal_cnt))
		return;

	l_di->pre_stage = l_di->cur_stage;
	for (i = stage_size - 1; i >= 0; --i) {
		vbat_th = l_di->volt_para[i].vol_th + l_di->compensate_v;
		if (!l_di->all_stage_compensate_r_en)
			vbat_th = (vbat_th > l_di->volt_para[stage_size - 1].vol_th) ?
				l_di->volt_para[stage_size - 1].vol_th : vbat_th;
		/* 0: cc stage, 1: cv stage, 2: max stage */
		if ((vbat >= vbat_th) && (ibat <= l_di->volt_para[i].cur_th_low)) {
			cur_stage = 2 * i + 2;
			break;
		} else if (vbat >= vbat_th) {
			cur_stage = 2 * i + 1;
			break;
		}
	}

	if (i < 0)
		cur_stage = 0;

	if (cur_stage < l_di->pre_stage)
		cur_stage = l_di->pre_stage;

	dc_ctrl_revise_stage(&cur_stage);

	if (cur_stage != l_di->cur_stage)
		l_di->cur_stage = direct_charge_jump_stage_if_need(cur_stage);
}

void direct_charge_soh_policy(void)
{
	int i;
	int volt_max;
	int cur_max;
	bool print = false;
	struct direct_charge_device *l_di = direct_charge_get_di();

	if (!l_di)
		return;

	if ((l_di->stage_size < 1) || (l_di->stage_size > DC_VOLT_LEVEL)) {
		hwlog_err("stage_size %d out of range\n", l_di->stage_size);
		return;
	}

	volt_max = l_di->orig_volt_para[l_di->stage_size - 1].vol_th -
		l_di->vterm_dec;
	if (l_di->volt_para[l_di->stage_size - 1].vol_th != volt_max) {
		l_di->volt_para[l_di->stage_size - 1].vol_th = volt_max;
		print = true;
	}

	for (i = 0; i < l_di->stage_size - 1; i++)
		l_di->volt_para[i].vol_th =
			(l_di->orig_volt_para[i].vol_th < volt_max) ?
			l_di->orig_volt_para[i].vol_th : volt_max;

	if (l_di->ichg_ratio == 0)
		l_di->ichg_ratio = BASP_PARA_SCALE;
	cur_max = l_di->orig_volt_para[0].cur_th_high *
		l_di->ichg_ratio / BASP_PARA_SCALE;
	if (l_di->volt_para[0].cur_th_high != cur_max) {
		l_di->volt_para[0].cur_th_high = cur_max;
		print = true;
	}
	l_di->volt_para[0].cur_th_low =
		l_di->orig_volt_para[0].cur_th_low;

	for (i = 1; i < l_di->stage_size; i++) {
		l_di->volt_para[i].cur_th_high =
			(l_di->orig_volt_para[i].cur_th_high <= cur_max) ?
			l_di->orig_volt_para[i].cur_th_high : cur_max;
		l_di->volt_para[i].cur_th_low =
			l_di->orig_volt_para[i].cur_th_low;
	}

	if (!print)
		return;

	hwlog_info("dc_volt_dec:%u, dc_cur_ratio:%u\n",
		l_di->vterm_dec, l_di->ichg_ratio);
	for (i = 0; i < l_di->stage_size; i++)
		hwlog_info("volt_para[%d]: vol_th:%d cur_th_high:%d cur_th_low:%d\n",
			i, l_di->volt_para[i].vol_th,
			l_di->volt_para[i].cur_th_high,
			l_di->volt_para[i].cur_th_low);
}

int direct_charge_get_vstep(int mode)
{
	int i;
	int ibat = 0;
	struct direct_charge_device *l_di = direct_charge_get_di_by_mode(mode);

	if (!l_di)
		return -EINVAL;

	/* only cc stage support increase vstep except for the last cc */
	if (l_di->cur_stage % 2 || (l_di->cur_stage >= (l_di->stage_size - 1) * 2))
		return l_di->vstep;

	if (direct_charge_get_bat_current(&ibat))
		return l_di->vstep;

	for (i = 0; i < DC_VSTEP_PARA_LEVEL; i++) {
		if (l_di->vstep_para[i].curr_gap == 0)
			break;
		if (l_di->cur_ibat_th_high - ibat > l_di->vstep_para[i].curr_gap)
			return l_di->vstep_para[i].vstep;
	}

	return l_di->vstep;
}

static bool direct_charge_mode_judge(int mode, unsigned int orientation)
{
	int r_cur, vbat, adap_max_cur;
	struct direct_charge_device *other = direct_charge_get_di_by_mode(mode);
	struct direct_charge_device *l_di = direct_charge_get_di();
	int other_sysfs_iin_thermal;
	int sysfs_iin_thermal;

	if (!l_di || !other || other->dc_err_report_flag ||
		!((direct_charge_get_local_mode() & l_di->adapter_type) & mode))
		return false;

	direct_charge_get_bat_voltage(&vbat);
	if ((vbat < other->min_dc_bat_vol) || (vbat > other->max_dc_bat_vol))
		return false;

	sysfs_iin_thermal = dc_sysfs_get_iin_thermal(l_di->local_mode);
	other_sysfs_iin_thermal = dc_sysfs_get_iin_thermal(mode);

	switch (orientation) {
	case UPWARD:
		if (!other->pri_inversion || (other_sysfs_iin_thermal <= other->cur_inversion) ||
			(other_sysfs_iin_thermal <= l_di->cur_ibat_th_high))
			return false;

		hwlog_info("trigger inversion, %d switch to %d\n", l_di->working_mode, mode);
		l_di->pri_inversion = true;
		other->pri_inversion = false;
		return true;
	case DOWNWARD:
		adap_max_cur = dc_adpt_get_inherent_info(ADAP_MAX_CUR);
		if ((sysfs_iin_thermal == l_di->iin_thermal_default) || (sysfs_iin_thermal == 0) ||
			(sysfs_iin_thermal > l_di->cur_inversion) ||
			(sysfs_iin_thermal > l_di->cur_ibat_th_high) ||
			(adap_max_cur && (sysfs_iin_thermal > (adap_max_cur * l_di->dc_volt_ratio))))
			return false;

		if (other_sysfs_iin_thermal && sysfs_iin_thermal >= other_sysfs_iin_thermal)
			return false;
		if ((dc_get_cable_inherent_info(DC_CABLE_DETECT_OK) == CABLE_DETECT_NOK) &&
			sysfs_iin_thermal > (int)dc_get_cable_mode_info(mode, MAX_CURR_FOR_NONSTD_CABLE))
			return false;
		r_cur = dc_resist_handler(mode, dc_get_cable_mode_info(mode, CABLE_FULL_PATH_RES));
		if (r_cur && sysfs_iin_thermal > r_cur)
			return false;

		hwlog_info("trigger inversion, %d switch to %d\n", l_di->working_mode, mode);
		l_di->pri_inversion = true;
		other->pri_inversion = false;
		return true;
	default:
		return false;
	}
}

bool direct_charge_check_priority_inversion(void)
{
	struct direct_charge_device *l_di = direct_charge_get_di();

	if (!l_di)
		return false;

	if (l_di->working_mode == SC4_MODE) {
		if (direct_charge_mode_judge(SC_MODE, DOWNWARD))
			return true;
		return direct_charge_mode_judge(LVC_MODE, DOWNWARD);
	} else if (l_di->working_mode == SC_MODE) {
		if (direct_charge_mode_judge(SC4_MODE, UPWARD))
			return true;
		return direct_charge_mode_judge(LVC_MODE, DOWNWARD);
	} else if (l_di->working_mode == LVC_MODE) {
		if (direct_charge_mode_judge(SC4_MODE, UPWARD))
			return true;
		return direct_charge_mode_judge(SC_MODE, UPWARD);
	}
	return false;
}

bool direct_charge_is_priority_inversion(void)
{
	struct direct_charge_device *lvc_di = NULL;
	struct direct_charge_device *sc_di = NULL;
	struct direct_charge_device *sc4_di = NULL;

	lvc_get_di(&lvc_di);
	sc_get_di(&sc_di);
	sc4_get_di(&sc4_di);

	if ((!lvc_di && !sc_di) || (!lvc_di && !sc4_di) || (!sc_di && !sc4_di))
		return false;

	if (lvc_di && lvc_di->pri_inversion)
		return true;
	if (sc_di && sc_di->pri_inversion)
		return true;
	if (sc4_di && sc4_di->pri_inversion)
		return true;

	return false;
}

void direct_charge_update_charge_info(void)
{
	struct direct_charge_device *l_di = direct_charge_get_di();

	if (!l_di || dc_get_stop_charging_flag())
		return;

	if (!l_di->multi_ic_mode_para.support_multi_ic)
		l_di->curr_info.channel_num = 1;
	else if (l_di->cur_mode == CHARGE_MULTI_IC)
		l_di->curr_info.channel_num = CHARGE_PATH_MAX_NUM;
	else
		return;

	dc_update_charging_info(l_di->working_mode, &l_di->curr_info, l_di->comp_para.vbat_comp);
}

int direct_charge_fault_notifier_call(struct notifier_block *nb,
	unsigned long event, void *data)
{
	struct direct_charge_device *di = NULL;
	int mode = direct_charge_get_working_mode();
	unsigned int stage = direct_charge_get_stage_status();

	if (!nb) {
		hwlog_err("nb is null\n");
		return NOTIFY_OK;
	}

	di = container_of(nb, struct direct_charge_device, fault_nb);
	if (!di) {
		hwlog_err("di is null\n");
		return NOTIFY_OK;
	}

	if ((di->working_mode != mode) ||
		(stage < DC_STAGE_SECURITY_CHECK) || (stage == DC_STAGE_CHARGE_DONE)) {
		hwlog_err("ignore notifier when not in direct charging\n");
		return NOTIFY_OK;
	}

	di->charge_fault = event;
	di->fault_data = (struct nty_data *)data;
	schedule_work(&di->fault_work);

	return NOTIFY_OK;
}

static bool direct_charge_adapter_plugout_msleep_exit(void)
{
	unsigned int type = charge_get_charger_type();

	if (type == CHARGER_REMOVED)
		return true;

	return false;
}

void direct_charge_stop_charging(void)
{
	int ret;
	int vbus = 0;
	int vbat = 0;
	int vadp = 0;
	bool to_set_default = false;
	bool need_recheck_flag;
	struct direct_charge_device *lvc_di = NULL;
	struct direct_charge_device *sc_di = NULL;
	struct direct_charge_device *sc4_di = NULL;
	struct direct_charge_device *l_di = direct_charge_get_di();

	hwlog_info("stop_charging\n");

	if (!l_di)
		return;

	lvc_get_di(&lvc_di);
	sc_get_di(&sc_di);
	sc4_get_di(&sc4_di);

	if (!lvc_di && !sc_di && !sc4_di) {
		hwlog_info("local not support direct_charge");
		return;
	}

	if (dc_get_stop_charging_flag() &&
		l_di->hv_flag == 0) /* ignore error */
		l_di->error_cnt += 1;

	need_recheck_flag = l_di->pri_inversion || dc_comm_get_need_recheck_flag();
	if (dc_get_stop_charging_flag() ||
		l_di->scp_stop_charging_flag_info ||
		(l_di->sysfs_enable_charger == 0) ||
		l_di->force_disable) {
		if (!power_cmdline_is_factory_mode())
			direct_charge_set_stage_status(DC_STAGE_DEFAULT);
		else
			to_set_default = true;
	} else if (need_recheck_flag) {
		hwlog_info("pri_inversion or recheck,set state in function exit\n");
	} else {
		direct_charge_set_stage_status(DC_STAGE_CHARGE_DONE);
	}

	if (wltx_need_disable_wired_dc())
		direct_charge_set_disable_flags(DC_SET_DISABLE_FLAGS,
			DC_DISABLE_WIRELESS_TX);

	dc_preparation_before_stop();

	ret = dcm_enable_ic(l_di->working_mode, l_di->cur_mode, DC_IC_DISABLE);
	if (ret)
		hwlog_err("ls enable fail\n");

	ret = dc_set_adapter_default();
	if (ret)
		hwlog_err("set adapter default state fail\n");

	/*
	 * Fix a hardware issue, need set pmu buckboost ccm mode during sc4 charging,
	 * and restore to default mode when direct_charge_stop_charging.
	 */
	if (l_di->pmu_mode_set_flag)
		pmic_set_buckboost_mode(1);

	dcm_set_ic_threshold_enable(l_di->working_mode, CHARGE_MULTI_IC, 0);
	power_platform_notify_direct_charge_status(false);

	/* when vbat is above 4.4v to sleep 15s avoid current backward to adapter */
	if (l_di->stop_charging_sleep_enable && (power_supply_app_get_bat_voltage_now() > 4400))
		power_msleep(DT_MSLEEP_15S, DT_MSLEEP_50MS, direct_charge_adapter_plugout_msleep_exit);

	if (l_di->scp_work_on_charger) {
		dc_adapter_protocol_power_supply(DISABLE);
		charge_set_hiz_enable_by_direct_charge(HIZ_MODE_DISABLE);
	}

	/* 1: enable discharge with device */
	ret = dcm_discharge_ic(l_di->working_mode, l_di->cur_mode, DC_IC_ENABLE);
	if (ret)
		hwlog_err("ls enable discharge fail\n");
	else
		hwlog_info("ls enable discharge succ\n");

	if (pmic_vbus_irq_is_enabled())
		charge_update_charger_remove_type();

	/* switch to normal charging path */
	direct_charge_switch_path_to_normal_charging();
	power_event_bnc_notify(POWER_BNT_CHANNEL, POWER_NE_BUCK_CHANNEL, NULL);

	/* 0: disable discharge with device */
	dcm_discharge_ic(l_di->working_mode, l_di->cur_mode, DC_IC_DISABLE);
	if (ret)
		hwlog_err("ls disable discharge fail\n");
	else
		hwlog_info("ls disable discharge succ\n");

	msleep(DT_MSLEEP_20MS);

	/* judging whether the adapter is disconnect */
	direct_charge_get_vbus_vbat(&vbus, &vbat);
	if ((vbus < VBUS_ON_THRESHOLD) ||
		(vbat - vbus) > VBAT_VBUS_DIFFERENCE) {
		hwlog_info("direct charger disconnect\n");

		if (!power_cmdline_is_factory_mode())
			direct_charge_set_disable_flags(DC_CLEAR_DISABLE_FLAGS,
				DC_DISABLE_SYS_NODE);

		direct_charge_set_disable_flags(DC_CLEAR_DISABLE_FLAGS,
			DC_DISABLE_WIRELESS_TX);
		dc_adpt_clear_inherent_info();
		dc_pmode_clear_data_in_exit();
		dc_comm_set_first_check_completed(false);
		direct_charge_reset_para_in_stop(lvc_di);
		direct_charge_reset_para_in_stop(sc_di);
		direct_charge_reset_para_in_stop(sc4_di);

		wired_disconnect_send_icon_uevent();
#ifdef CONFIG_WIRELESS_CHARGER
		direct_charger_disconnect_event();
#endif /* CONFIG_WIRELESS_CHARGER */

		/*
		 * if pd not available, when pmic regn connected
		 * do disconnect here
		 */
		if (pmic_vbus_is_connected())
			pmic_vbus_disconnect_process();
	}

	ret = dcm_exit_ic(l_di->working_mode, CHARGE_MULTI_IC);
	if (ret)
		hwlog_err("ls exit fail\n");

	if (dcm_exit_batinfo(l_di->working_mode, l_di->cur_mode))
		hwlog_err("bi exit fail\n");

	ret = dc_reset_operate(DC_RESET_MASTER);
	if (ret)
		hwlog_err("soft reset master fail\n");

	if (to_set_default)
		direct_charge_set_stage_status(DC_STAGE_DEFAULT);

	/* cancel threshold timer and work */
	dcm_config_ic_watchdog(l_di->working_mode, CHARGE_MULTI_IC, 0); /* 0:wdt disable */
	hrtimer_cancel(&l_di->calc_thld_timer);
	cancel_work_sync(&l_di->calc_thld_work);
	hrtimer_cancel(&l_di->anomaly_det_timer);
	cancel_work_sync(&l_di->anomaly_det_work);

	/* cancel watchdog timer and work */
	hrtimer_cancel(&l_di->kick_wtd_timer);
	cancel_work_sync(&l_di->kick_wtd_work);

	/* reset parameter and release resource */
	dc_close_aux_wired_channel();
	dc_close_lvc_mos_channel();
	dc_set_stop_charging_flag(false);
	dc_mmi_set_test_flag(false);
	dc_clear_cable_inherent_info();
	l_di->scp_stop_charging_flag_info = 0;
	l_di->cur_stage = 0;
	l_di->pre_stage = 0;
	l_di->vbat = 0;
	l_di->ibat = 0;
	l_di->vadapt = 0;
	l_di->iadapt = 0;
	l_di->ls_vbus = 0;
	l_di->ls_ibus = 0;
	l_di->compensate_v = 0;
	l_di->ibat_abnormal_cnt = 0;
	l_di->multi_ic_check_info.force_single_path_flag = false;
	power_wakeup_unlock(l_di->charging_lock, false);
	l_di->scp_stop_charging_complete_flag = 1;
	l_di->working_mode = UNDEFINED_MODE;
	l_di->hv_flag = 0;
	l_di->cur_mode = CHARGE_IC_MAIN;
	if (l_di->multi_ic_check_info.limit_current < 0)
		l_di->multi_ic_check_info.limit_current = l_di->iin_thermal_default;
	power_if_kernel_sysfs_set(POWER_IF_OP_TYPE_ADAPTER_PROTOCOL, POWER_IF_SYSFS_ADAPTER_PROTOCOL, 0);

	power_event_bnc_notify(POWER_BNT_DC, POWER_NE_DC_STOP_CHARGE, NULL);

	if (direct_charge_check_switch_sc4_to_sc_mode())
		goto recheck;

	if (need_recheck_flag) {
		direct_charge_set_stage_status(DC_STAGE_DEFAULT);
		dc_comm_set_need_recheck_flag(false);
		goto recheck;
	}

	return;

recheck:
	charge_request_charge_monitor();
}

int direct_charge_get_succ_flag(void)
{
	struct direct_charge_device *di = direct_charge_get_di();

	if (!di)
		return 0;

	return di->dc_succ_flag;
}
