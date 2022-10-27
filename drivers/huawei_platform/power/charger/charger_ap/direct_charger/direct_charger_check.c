/*
 * direct_charger_check.c
 *
 * direct charger check driver
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

#include <huawei_platform/usb/hw_pd_dev.h>
#include <chipset_common/hwpower/water_detect.h>
#include <huawei_platform/power/battery_voltage.h>
#include <chipset_common/hwpower/battery_temp.h>
#include <chipset_common/hwpower/btb_check.h>
#include <chipset_common/hwpower/power_cmdline.h>
#include <huawei_platform/power/direct_charger/direct_charger.h>
#ifdef CONFIG_HUAWEI_USB_SHORT_CIRCUIT_PROTECT
#include <huawei_platform/power/uscp/usb_short_circuit_protect.h>
#endif
#include <huawei_platform/power/wireless/wireless_tx_pwr_ctrl.h>
#include <huawei_platform/power/huawei_charger_adaptor.h>
#include <huawei_platform/power/common_module/uscp.h>


#ifdef HWLOG_TAG
#undef HWLOG_TAG
#endif

#define HWLOG_TAG direct_charge_check
HWLOG_REGIST();

#define RETYR_TIMES              3

static bool g_dc_can_enter = true;
static bool g_dc_in_mode_check;

static void direct_charge_check_set_succ_flag(int mode)
{
	switch (mode) {
	case LVC_MODE:
		dc_mmi_set_succ_flag(mode, DC_SUCC);
		return;
	case SC_MODE:
	case HSC_MODE:
		dc_mmi_set_succ_flag(mode, DC_ERROR_START_CHARGE);
		return;
	default:
		return;
	}
}

void direct_charge_set_can_enter_status(bool status)
{
	hwlog_info("can_enter_status=%d\n", status);
	g_dc_can_enter = status;
}

bool direct_charge_get_can_enter_status(void)
{
	return g_dc_can_enter;
}

bool direct_charge_check_enable_status(void)
{
	struct direct_charge_device *l_di = direct_charge_get_di();

	if (l_di->sysfs_enable_charger == 0 &&
		!(l_di->sysfs_mainsc_enable_charger ^ l_di->sysfs_auxsc_enable_charger)) {
		dc_mmi_set_succ_flag(l_di->working_mode, DC_ERROR_CHARGE_DISABLED);
		hwlog_info("%d is disabled\n", l_di->working_mode);
		return false;
	}
	return true;
}

static int direct_charge_check_battery_temp(struct direct_charge_device *di)
{
	int bat_temp = 0;
	int bat_temp_cur_max;

	bat_temp_get_temperature(BAT_TEMP_MIXED, &bat_temp);
	di->bat_temp_before_charging = bat_temp;
	if (bat_temp < DC_LOW_TEMP_MAX + di->low_temp_hysteresis) {
		hwlog_info("can not do direct charging again, temp=%d\n",
			bat_temp);
		return -1;
	}
	if (bat_temp >= DC_HIGH_TEMP_MAX - di->high_temp_hysteresis) {
		hwlog_info("can not do direct charging again, temp=%d\n",
			bat_temp);
		return -1;
	}

	bat_temp_cur_max = direct_charge_battery_temp_handler(bat_temp);
	if (bat_temp_cur_max == 0) {
		hwlog_info("can not do direct charging, temp=%d\n", bat_temp);
		return -1;
	}

	return 0;
}

static int direct_charge_check_battery_voltage(struct direct_charge_device *di)
{
	int volt_max = hw_battery_voltage(BAT_ID_MAX);
	int volt_min = hw_battery_voltage(BAT_ID_MIN);

	if (volt_min < di->min_dc_bat_vol ||
		volt_max > di->max_dc_bat_vol) {
		hwlog_info("can not do direct charging, v_min=%d v_max=%d\n",
			volt_min, volt_max);
		return -1;
	}

	return 0;
}

static int direct_charge_check_select_sc_mode(
	struct direct_charge_device *di)
{
	switch (di->working_mode) {
	case LVC_MODE:
		return SC_FBBY_MODE;
	case SC_MODE:
		return SC_F21SC_MODE;
	case HSC_MODE:
		return SC_F41SC_MODE;
	default:
		break;
	}
	return SC_FBBY_MODE;
}

static int direct_charge_check_adapter_voltage_accuracy(
	struct direct_charge_device *di)
{
	int vadapt = 0;
	int ibat = 0;
	int vol_err;
	int i;
	char tmp_buf[ERR_NO_STRING_SIZE] = { 0 };
	int error_flag = 0;
	int sc_mode = direct_charge_check_select_sc_mode(di);
	di->sc_mode = sc_mode;

	dc_ic_set_sc_mode(di->working_mode, di->cur_mode, sc_mode);
	di->adaptor_vset = di->init_adapter_vset;
	dc_set_adapter_voltage(di->adaptor_vset);

	/* delay 500ms */
	usleep_range(500000, 501000);

	/* keep communication with the adaptor within 1 second */
	direct_charge_get_bat_current(&ibat);

	for (i = 0; i < RETYR_TIMES; ++i) {
		if (dc_get_adapter_voltage(&vadapt))
			return -1;

		vol_err = vadapt - di->adaptor_vset;
		if (vol_err < 0)
			vol_err = -vol_err;

		hwlog_info("[%d]: Verr=%d, Verr_th=%d, Vset=%d, Vread=%d, Vbus=%d\n",
			i, vol_err, di->vol_err_th,
			di->adaptor_vset, vadapt, get_charger_vbus_vol());

		if (vol_err > di->vol_err_th) {
			error_flag = 1;
			break;
		}
	}

	if (error_flag == 0) {
		hwlog_err("adapter voltage accuracy check succ\n");
		return 0;
	}

	/* process error report */
	snprintf(tmp_buf, sizeof(tmp_buf),
		"[%d]: Verr=%d > Verr_th=%d, Vset=%d, Vread=%d, Vbus=%d\n",
		i, vol_err, di->vol_err_th,
		di->adaptor_vset, vadapt, get_charger_vbus_vol());

	dc_fill_eh_buf(di->dsm_buff, sizeof(di->dsm_buff),
		DC_EH_APT_VOLTAGE_ACCURACY, tmp_buf);

	power_dsm_dmd_report(POWER_DSM_BATTERY,
		DSM_DIRECT_CHARGE_VOL_ACCURACY, tmp_buf);

	hwlog_err("adapter voltage accuracy check fail\n");
	return -1;
}

static int direct_charge_check_charging_path_leakage_current(
	struct direct_charge_device *di)
{
	int iadapt = 0;
	int ibus = 0;
	int leak_current;
	char tmp_buf[ERR_NO_STRING_SIZE] = { 0 };
	int error_flag = 0;

	switch (di->adaptor_vendor_id) {
	case ADAPTER_CHIP_IWATT:
		di->adaptor_iset = 400; /* default 400ma */
		if (dc_set_adapter_current(di->adaptor_iset))
			return -1;
		if (!direct_charge_check_enable_status())
			return -1;

		/* delay 100ms */
		msleep(100);

		leak_current = dc_get_adapter_port_leakage_current();
		if (leak_current) {
			error_flag = 1;

			snprintf(tmp_buf, sizeof(tmp_buf),
				"iwatt_adapter usb port current leak, Vbus=%d\n",
				get_charger_vbus_vol());
		}

		break;
	default:
		if (direct_charge_get_device_ibus(&ibus))
			return -1;

		if (dc_get_adapter_current(&iadapt))
			return -1;

		hwlog_info("Iapt=%d, Ileakage_cur_th=%d, Ibus_ls=%d, Vbus=%d\n",
			iadapt, di->adaptor_leakage_current_th, ibus,
			get_charger_vbus_vol());

		if (iadapt > di->adaptor_leakage_current_th) {
			error_flag = 1;

			snprintf(tmp_buf, sizeof(tmp_buf),
				"Iapt=%d > Ileakage_cur_th=%d, Ibus_ls=%d, Vbus=%d\n",
				iadapt, di->adaptor_leakage_current_th, ibus,
				get_charger_vbus_vol());
		}

		break;
	}

	if (error_flag == 0) {
		hwlog_err("usb port leakage current check succ\n");
		return 0;
	}

	/* process error report */
	if (di->cc_cable_detect_ok == 1) {
		dc_fill_eh_buf(di->dsm_buff, sizeof(di->dsm_buff),
			DC_EH_USB_PORT_LEAGAGE_CURR, tmp_buf);

		power_dsm_dmd_report(POWER_DSM_BATTERY,
			DSM_DIRECT_CHARGE_USB_PORT_LEAKAGE_CURRENT, tmp_buf);
	}

	hwlog_err("usb port leakage current check fail\n");
	return -1;
}

static int direct_charge_skip_check_resistance(struct direct_charge_device *di)
{
	if (power_cmdline_is_factory_mode() && di->ignore_full_path_res) {
		di->ignore_full_path_res = false;
		di->full_path_resistance = 0;
		hwlog_info("skip check full path resist\n");
		return 1;
	}
	return 0;
}

static int direct_charge_check_full_path_resistance(
	struct direct_charge_device *di)
{
	int vadapt = 0;
	int rpath = 0;
	char tmp_buf[ERR_NO_STRING_SIZE] = { 0 };
	int rpath_th = di->full_path_res_thld;
	int resist_cur_max;

	if (direct_charge_skip_check_resistance(di))
		return 0;
	if (!direct_charge_check_enable_status())
		return -1;
	/* delay 500ms */
	usleep_range(500000, 501000);

	/* keep communication with the adapter within 1 second */
	if (dc_get_adapter_voltage(&vadapt))
		return -1;

	/* keep communication with device within 1 second */
	if (direct_charge_get_device_close_status())
		return -1;
	if (!direct_charge_check_enable_status())
		return -1;
	/* delay 400ms */
	usleep_range(400000, 401000);
	if (dc_calculate_path_resistance(&rpath))
		return -1;

	di->full_path_resistance = rpath;
	hwlog_info("average Rpath=%d, Rpath_threshold=[%d,%d]\n",
		rpath, -rpath_th, rpath_th);

	if (rpath <= rpath_th) {
		resist_cur_max = dc_resist_handler(di->working_mode, rpath);
		hwlog_err("resist_cur_max=%d\n", resist_cur_max);
		if ((di->cc_cable_detect_ok == 0) && (resist_cur_max != 0)) {
			if (pd_dpm_get_ctc_cable_flag())
				di->max_current_for_ctc_cable =
					resist_cur_max;
			else
				di->max_current_for_nonstd_cable =
					resist_cur_max;
		}
		if (di->cc_cable_detect_ok == 0)
			dc_send_icon_uevent();

		hwlog_err("full path resistance check succ\n");
		return 0;
	}

	/* process error report */
	if (di->cc_cable_detect_ok == 1) {
		snprintf(tmp_buf, sizeof(tmp_buf),
			"full_res %d is out of[%d, %d]\n",
			rpath, -rpath_th, rpath_th);

		dc_fill_eh_buf(di->dsm_buff,
			sizeof(di->dsm_buff),
			DC_EH_FULL_PATH_RESISTANCE, tmp_buf);

		power_dsm_dmd_report(POWER_DSM_BATTERY,
			DSM_DIRECT_CHARGE_FULL_PATH_RESISTANCE, tmp_buf);
	}

	hwlog_err("full path resistance check fail\n");
	return -1;
}

static int direct_charge_security_check(void)
{
	int ret;
	struct direct_charge_device *l_di = direct_charge_get_di();

	if (!l_di)
		return -1;

	dc_mmi_set_succ_flag(l_di->working_mode, DC_ERROR_ADAPTER_VOLTAGE_ACCURACY);
	ret = direct_charge_check_adapter_voltage_accuracy(l_di);
	if (ret)
		return -1;

	dc_mmi_set_succ_flag(l_di->working_mode, DC_ERROR_USB_PORT_LEAKAGE_CURRENT);
	ret = direct_charge_check_charging_path_leakage_current(l_di);
	if (ret)
		return -1;

	dc_mmi_set_succ_flag(l_di->working_mode, DC_ERROR_OPEN_CHARGE_PATH);
	ret = direct_charge_open_charging_path();
	if (ret)
		return -1;

	dc_mmi_set_succ_flag(l_di->working_mode, DC_ERROR_FULL_REISISTANCE);
	ret = direct_charge_check_full_path_resistance(l_di);
	if (ret)
		return -1;

	return 0;
}

bool direct_charge_check_charge_done(void)
{
	int charge_done_status = get_charge_done_type();
	struct direct_charge_device *lvc_di = NULL;
	struct direct_charge_device *sc_di = NULL;
	struct direct_charge_device *hsc_di = NULL;

	lvc_get_di(&lvc_di);
	sc_get_di(&sc_di);
	hsc_get_di(&hsc_di);

	if (!lvc_di && !sc_di &&!hsc_di)
		return true;

	if (charge_done_status == CHARGE_DONE) {
		hwlog_info("charge done");
		return true;
	}

	if (lvc_di && (lvc_di->dc_stage == DC_STAGE_CHARGE_DONE)) {
		hwlog_info("lvc charge done");
		return true;
	}

	if (sc_di && (sc_di->dc_stage == DC_STAGE_CHARGE_DONE)) {
		hwlog_info("sc charge done");
		return true;
	}

	return false;
}

static bool direct_charge_check_port_fault(void)
{
	bool cc_vbus_short = false;
	bool cc_moisture_status = false;
	bool intruded_status = false;
	char tmp_buf[ERR_NO_STRING_SIZE] = { 0 };

	/* cc rp 3.0 can not do high voltage charge */
	cc_vbus_short = pd_dpm_check_cc_vbus_short();
	if (cc_vbus_short) {
		hwlog_err("cc match rp3.0, can not do sc charge\n");
		snprintf(tmp_buf, sizeof(tmp_buf), "cc vbus short happend\n");
		power_dsm_dmd_report(POWER_DSM_BATTERY, ERROR_NO_TYPEC_VBUS_SBU_SHORT, tmp_buf);
	}

	cc_moisture_status = pd_dpm_get_cc_moisture_status();
	if (cc_moisture_status)
		hwlog_err("cc moisture detected\n");

	intruded_status = water_detect_get_intruded_status();
	if (intruded_status)
		hwlog_err("water detect intruded detected\n");

	return !cc_vbus_short && !cc_moisture_status && !intruded_status;
}

static bool direct_charge_check_sbu_fault(void)
{
	bool sbu_vbus_short = false;

	/* sbu vbus short can not do high voltage charge */
	sbu_vbus_short = pd_dpm_check_sbu_vbus_short();
	if (sbu_vbus_short)
		hwlog_err("sbu short detect, can not do sc charge\n");

	return !sbu_vbus_short;
}

static void direct_charge_rework_priority_inversion(
	struct direct_charge_device *lvc_di,
	struct direct_charge_device *sc_di)
{
	if (!lvc_di || !sc_di)
		return;

	/* if any path error occur, disable pri_inversion function */
	if (lvc_di->dc_err_report_flag || sc_di->dc_err_report_flag) {
		lvc_di->pri_inversion = false;
		sc_di->pri_inversion = false;
	}
}

static void direct_charge_rt_set_aux_mode(struct direct_charge_device *di)
{
	if (power_cmdline_is_factory_mode() && ((di->working_mode == SC_MODE) || (di->working_mode == HSC_MODE)) &&
		((di->sysfs_auxsc_enable_charger == 1) &&
		(di->sysfs_mainsc_enable_charger == 0))) {
		if (di->multi_ic_mode_para.ic_error_cnt[CHARGE_IC_TYPE_AUX] < DC_MULTI_ERR_CNT_MAX) {
			di->cur_mode = CHARGE_IC_AUX;
			hwlog_info("RT aux sc charge mode test\n");
		} else {
			hwlog_err("aux sc error happened\n");
		}
	}
}

static void direct_charge_mode_check(struct direct_charge_device *di, int hv_flag)
{
	unsigned int stage;
	unsigned int local_mode;
	unsigned int path;

	if (di->working_mode == LVC_MODE) {
		path = PATH_LVC;
		hwlog_info("lvc mode check begin\n");
	} else if ((di->working_mode == SC_MODE) || (di->working_mode == HSC_MODE)) {
		path = PATH_SC;
		hwlog_info("sc mode check begin\n");
	} else {
		hwlog_info("illegal mode\n");
		return;
	}
	power_event_notify(POWER_NT_DC, POWER_NE_DC_CHECK_START, NULL);

	/* step-1: check local mode */
	local_mode = direct_charge_get_local_mode();
	if (!(local_mode & di->working_mode)) {
		hwlog_err("local mode not support %d\n", di->working_mode);
		return;
	}

	/* step-2: check dc error and report dmd */
	if (di->error_cnt >= DC_ERR_CNT_MAX) {
		hwlog_info("error exceed %d times, dc is disabled\n",
			DC_ERR_CNT_MAX);

		dc_mmi_set_succ_flag(di->working_mode, DC_ERROR_CHARGE_DISABLED);
		dc_send_normal_charging_uevent();

		if ((di->dc_err_report_flag == FALSE) &&
			(di->dc_open_retry_cnt <= DC_OPEN_RETRY_CNT_MAX)) {
			dc_show_eh_buf(di->dsm_buff);

			if (di->cc_cable_detect_ok)
				dc_report_eh_buf(di->dsm_buff,
					DSM_DIRECT_CHARGE_ERR_WITH_STD_CABLE);
			else
				dc_report_eh_buf(di->dsm_buff,
					DSM_DIRECT_CHARGE_ERR_WITH_NONSTD_CABLE);

			dc_clean_eh_buf(di->dsm_buff,
				sizeof(di->dsm_buff));
			di->dc_err_report_flag = TRUE;
		}

		return;
	}

	if (multi_ic_check_select_init_mode(&di->multi_ic_mode_para, &di->cur_mode)) {
		dc_mmi_set_succ_flag(di->working_mode, DC_ERROR_BTB_CHECK);
		return;
	}
	/* rt test set aux sc mode */
	direct_charge_rt_set_aux_mode(di);

	/* step-3: check enable status */
	if (!direct_charge_check_enable_status())
		return;

	/* step-4: check scp protocol status */
	stage = direct_charge_get_stage_status();
	if (stage == DC_STAGE_DEFAULT) {
		if (dc_get_protocol_register_state())
			return;
	}

#ifdef CONFIG_HUAWEI_USB_SHORT_CIRCUIT_PROTECT
	/* step-5: check uscp status */
	if (uscp_is_in_protect_mode()) {
		direct_charge_set_stage_status(DC_STAGE_DEFAULT);
		dc_mmi_set_succ_flag(di->working_mode, DC_ERROR_CHARGE_DISABLED);
		hwlog_err("%d is disabled by uscp\n", di->working_mode);
		return;
	}
#endif /* CONFIG_HUAWEI_USB_SHORT_CIRCUIT_PROTECT */

	/* get adapter power curve */
	if (dc_get_adapter_power_curve())
		hwlog_info("adapter not support power curve\n");

	/* step-6: detect cable */
	if (direct_charge_get_stage_status() == DC_STAGE_ADAPTER_DETECT) {
		dc_mmi_set_succ_flag(di->working_mode, DC_ERROR_ADAPTER_DETECT);
		di->adapter_detect_flag = DC_ADAPTER_DETECT;
		dc_detect_cable();
	}

	if (di->orig_cable_type == DC_STD_CABLE)
		wltx_dc_adaptor_handler();
	if (!direct_charge_check_enable_status())
		return;

	/* step-7: update adapter info */
	dc_update_adapter_info();

	/* step-8: check battery temp */
	if (direct_charge_check_battery_temp(di)) {
		dc_mmi_set_succ_flag(di->working_mode, DC_ERROR_BAT_TEMP);
		direct_charge_set_stage_status(DC_STAGE_DEFAULT);
		di->bat_temp_err_flag = true;
		hwlog_err("temp out of range, try next loop\n");
		return;
	} else {
		di->bat_temp_err_flag = false;
	}

	/* step-9: check battery voltage */
	if (direct_charge_check_battery_voltage(di)) {
		dc_mmi_set_succ_flag(di->working_mode, DC_ERROR_BAT_VOL);
		direct_charge_set_stage_status(DC_STAGE_DEFAULT);
		di->bat_temp_err_flag = true;// avoid rt chargemode high volt
		hwlog_err("volt out of range, try next loop\n");
		return;
	} else {
		di->bat_temp_err_flag = false;
	}

	/* step-10: check adapter antifake */
	if (dc_check_adapter_antifake()) {
		dc_mmi_set_succ_flag(di->working_mode, DC_ERROR_ADAPTER_ANTI_FAKE);
		direct_charge_set_stage_status(DC_STAGE_DEFAULT);
		di->error_cnt += 1;
		hwlog_err("adapter antifake check failed\n");
		return;
	}

	/* step-11: switch buck charging path to dc charging path */
	if (direct_charge_get_stage_status() == DC_STAGE_SWITCH_DETECT) {
		di->scp_stop_charging_complete_flag = 0;
		dc_mmi_set_succ_flag(di->working_mode, DC_ERROR_SWITCH);
		if (!direct_charge_check_enable_status())
			return;
		if (dc_switch_charging_path(path, hv_flag) == 0) {
			direct_charge_set_stage_status(DC_STAGE_CHARGE_INIT);
		} else {
			hwlog_err("direct_charge path switch failed\n");
			goto err_out;
		}
	}

	/* step-12: init scp adapter and device */
	if (direct_charge_get_stage_status() == DC_STAGE_CHARGE_INIT) {
		dc_mmi_set_succ_flag(di->working_mode, DC_ERROR_INIT);
		if (!direct_charge_check_enable_status())
			goto err_out;
		if (direct_charge_init_adapter_and_device(hv_flag) == 0) {
			direct_charge_set_stage_status(DC_STAGE_SECURITY_CHECK);
		} else {
			hwlog_err("direct_charge init failed\n");
			multi_ic_check_set_ic_error_flag(di->cur_mode, &di->multi_ic_mode_para);
			goto err_out;
		}
	}

	/* step-13: direct charging security check */
	if (direct_charge_get_stage_status() == DC_STAGE_SECURITY_CHECK) {
		if (!direct_charge_check_enable_status())
			goto err_out;
		if (direct_charge_security_check() == 0) {
			direct_charge_set_stage_status(DC_STAGE_SUCCESS);
		} else {
			hwlog_err("direct_charge security check failed\n");
			multi_ic_check_set_ic_error_flag(di->cur_mode, &di->multi_ic_mode_para);
			goto err_out;
		}
	}

	/* step-14: start direct charging */
	if (direct_charge_get_stage_status() == DC_STAGE_SUCCESS) {
		direct_charge_check_set_succ_flag(di->working_mode);
		di->dc_succ_flag = DC_SUCCESS;
		if (!direct_charge_check_enable_status())
			goto err_out;
		if (direct_charge_start_charging())
			goto err_out;
	}

	/* step-15: end */
	power_event_notify(POWER_NT_DC, POWER_NE_DC_CHECK_SUCC, NULL);
	goto end;

err_out:
	direct_charge_set_stop_charging_flag(1);
	direct_charge_stop_charging();
end:
	stage = direct_charge_get_stage_status();
	hwlog_info("direct_charge stage=%d,%s\n", stage,
		direct_charge_get_stage_status_string(stage));
}

bool direct_charge_in_mode_check(void)
{
	return g_dc_in_mode_check;
}

static void direct_charge_enter_specified_mode(struct direct_charge_device *di,
	int mode, int type, int hv_flag)
{
	di->adaptor_test_result_type = type;
	di->working_mode = mode;

	direct_charge_set_di(di);
	chg_set_adaptor_test_result(type, DETECT_SUCC);

	g_dc_in_mode_check = true;
	direct_charge_mode_check(di, hv_flag);
	g_dc_in_mode_check = false;
	if (direct_charge_in_charging_stage() == DC_IN_CHARGING_STAGE) {
		if (mode == LVC_MODE)
			power_event_notify(POWER_NT_DC, POWER_NE_DC_LVC_CHARGING, NULL);
		else if (mode == SC_MODE)
			power_event_notify(POWER_NT_DC, POWER_NE_DC_SC_CHARGING, NULL);
	}
}

static void direct_detect_icon(void)
{
	int ret;
	bool cc_moisture_status = false;
	int adapter_type = ADAPTER_TYPE_UNKNOWN;
	enum cur_cap c_cap;
	struct direct_charge_device *di = direct_charge_get_di();

	if (!di || di->cc_cable_detect_ok)
		return;

	/* 10v2a and 10v2.25a no need check cable */
	adapter_get_adp_type(ADAPTER_PROTOCOL_SCP, &adapter_type);
	if ((adapter_type == ADAPTER_TYPE_10V2A) ||
		(adapter_type == ADAPTER_TYPE_10V2P25A)) {
		di->cc_cable_detect_ok = 1; /* detect success flag */
		di->full_path_res_thld = di->std_cable_full_path_res_max;
		hwlog_info("%s %d\n", __func__, di->cc_cable_detect_ok);
		dc_send_icon_uevent();
		return;
	}
	if (!di->cd_ops || !di->cd_ops->cable_detect) {
		hwlog_err("cd_ops or cable_detect is null\n");
		direct_charge_set_stage_status(DC_STAGE_DEFAULT);
		return;
	}
	ret = di->cd_ops->cable_detect();
	cc_moisture_status = pd_dpm_get_cc_moisture_status();
	c_cap = pd_dpm_get_cvdo_cur_cap();
	if (ret && !cc_moisture_status && (c_cap < PD_DPM_CURR_5A)) {
		di->cc_cable_detect_ok = 0; /* detect not success flag */
	} else {
		hwlog_info("%s stdandard cable detect ok\n", __func__);
		di->cable_type = DC_STD_CABLE;
		di->cc_cable_detect_ok = 1; /* detect success flag */
		di->full_path_res_thld = di->std_cable_full_path_res_max;
		dc_send_icon_uevent();
	}
}

void direct_charge_check(int hv_flag)
{
	unsigned int adp_mode;
	unsigned int local_mode;
	bool cc_safe = false;
	bool sbu_safe = false;
	struct direct_charge_device *lvc_di = NULL;
	struct direct_charge_device *sc_di = NULL;
	struct direct_charge_device *hsc_di = NULL;

	hwlog_info("check\n");

	lvc_get_di(&lvc_di);
	sc_get_di(&sc_di);
	hsc_get_di(&hsc_di);

	if (!lvc_di && !sc_di && !hsc_di) {
		hwlog_info("local not support direct_charge");
		return;
	}

	if (direct_charge_check_charge_done())
		return;

	local_mode = direct_charge_get_local_mode();

	/* update local mode to switch sc/lvc mode for rt adapter test */
	if (power_cmdline_is_factory_mode())
		local_mode = direct_charge_update_local_mode(local_mode);

	adp_mode = direct_charge_detect_adapter_support_mode();
	hwlog_info("local_mode=%x adapter_mode=%x\n", local_mode, adp_mode);

	if (adp_mode == UNDEFINED_MODE) {
		hwlog_info("undefined adapter mode");
		if (hv_flag == 0) {
			set_first_insert(1); /* not dectect success go next */
			hwlog_info("undefined adapter go next\n");
		}
		return;
	}

	direct_charge_rework_priority_inversion(lvc_di, sc_di);
	cc_safe = direct_charge_check_port_fault();
	sbu_safe = direct_charge_check_sbu_fault();
	if (sc_di) {
		sc_di->cc_safe = cc_safe;
		hwlog_info("sc_di->cc_unsafe_sc_enable = %u, sc_di->sbu_unsafe_sc_enable = %u\n",
			sc_di->cc_unsafe_sc_enable, sc_di->sbu_unsafe_sc_enable);
	}
	if(hsc_di) {
		hsc_di->cc_safe = cc_safe;
		hwlog_info("hsc_di->cc_unsafe_sc_enable = %u, hsc_di->sbu_unsafe_sc_enable = %u\n",
			hsc_di->cc_unsafe_sc_enable, hsc_di->sbu_unsafe_sc_enable);
	}
	hwlog_info("cc_safe = %d, sbu_safe = %d\n", cc_safe, sbu_safe);
	/* Enable sc and limit cur to 3000mA even when cc is unsafe when cc_unsafe_sc_enable is true */
	if (hsc_di && hsc_di->sysfs_enable_charger &&
		((local_mode & adp_mode) & HSC_MODE) &&
		!hsc_di->dc_err_report_flag && (hsc_di->cc_unsafe_sc_enable || cc_safe) &&
		!hsc_di->pri_inversion && (hsc_di->dc_stage != DC_STAGE_CHARGE_DONE)
		&& (hsc_di->sbu_unsafe_sc_enable || sbu_safe)) {
		sc_di->adapter_type = adp_mode;
		direct_charge_set_can_enter_status(true);
		direct_charge_enter_specified_mode(hsc_di, HSC_MODE, TYPE_HSC, hv_flag);
	} else if (sc_di && sc_di->sysfs_enable_charger &&
		((local_mode & adp_mode) & SC_MODE) &&
		!sc_di->dc_err_report_flag && (sc_di->cc_unsafe_sc_enable || cc_safe) &&
		!sc_di->pri_inversion && (sc_di->sbu_unsafe_sc_enable || sbu_safe)) {
		if ((hv_flag == 0) && sc_di->cam_flash_stop) {
			direct_charge_set_di(sc_di);
			direct_detect_icon();
		} else {
			sc_di->adapter_type = adp_mode;
			direct_charge_set_can_enter_status(true);
			direct_charge_enter_specified_mode(sc_di,
				SC_MODE, TYPE_SC, hv_flag);
		}
	} else if (lvc_di && lvc_di->sysfs_enable_charger &&
		((local_mode & adp_mode) & LVC_MODE) &&
		!lvc_di->dc_err_report_flag &&
		(!lvc_di->cc_protect || cc_safe)) {
		if ((hv_flag == 0) && sc_di->cam_flash_stop) {
			direct_charge_set_di(sc_di);
			direct_detect_icon();
		} else {
			lvc_di->adapter_type = adp_mode;
			direct_charge_set_can_enter_status(true);
			direct_charge_enter_specified_mode(lvc_di,
				LVC_MODE, TYPE_SCP, hv_flag);
		}
	} else {
		direct_charge_set_can_enter_status(false);
		hwlog_info("neither sc nor lvc matched");
	}
}

int direct_charge_pre_check(void)
{
	unsigned int local_mode;
	unsigned int adp_mode = 0;
	enum charger_type chr_type;

	hwlog_info("pre_check\n");

	chr_type = mt_get_charger_type();
	if (chr_type != CHARGER_TYPE_STANDARD) {
		hwlog_err("pre_check adapter not STANDARD_CHARGER\n");
		return -1;
	}

	local_mode = direct_charge_get_local_mode();
	adapter_get_support_mode(ADAPTER_PROTOCOL_SCP, &adp_mode);
	if (adp_mode & local_mode) {
		hwlog_info("adapter support lvc or sc\n");
		return 0;
	}

	hwlog_info("adapter not support lvc or sc\n");
	return -1;
}