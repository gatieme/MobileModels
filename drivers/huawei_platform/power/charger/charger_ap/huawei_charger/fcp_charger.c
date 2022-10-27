#include <huawei_platform/power/fcp_charger.h>
#include <huawei_platform/power/direct_charger/direct_charger.h>
#include <log/hw_log.h>
#include <huawei_platform/usb/hw_pd_dev.h>
#include <huawei_platform/power/huawei_charger_adaptor.h>
#include <chipset_common/hwpower/adapter_protocol.h>
#include <linux/power/charger-manager.h>
#include <chipset_common/hwpower/power_supply_interface.h>
#include <huawei_platform/power/hihonor_charger_glink.h>
#include <huawei_platform/power/charge_dmd_monitor.h>
#include <huawei_platform/power/common_module/power_platform.h>

#define HWLOG_TAG fcp_charger
HWLOG_REGIST();

static int fcp_charge_flag;
static int fcp_charge_check_cnt;
#ifdef CONFIG_DIRECT_CHARGER
static int fcp_output_vol_retry_cnt;
#endif
static int switch_status_num;

static int output_num;
static int detect_num;
static int fcp_vbus_lower_count;
static int nonfcp_vbus_higher_count;
#define VBUS_REPORT_NUM 4
#define MAX_CNT         2

static enum fcp_check_stage_type fcp_stage = FCP_STAGE_DEFAUTL;
void reset_fcp_flag(void)
{
	output_num = 0;
	detect_num = 0;
	fcp_charge_check_cnt = 0;
#ifdef CONFIG_DIRECT_CHARGER
	fcp_output_vol_retry_cnt = 0;
#endif
}

static int detect_support_fcp_mode(void)
{
	int ret;
	unsigned int scp_adp_mode = ADAPTER_SUPPORT_UNDEFINED;
	int adp_mode = ADAPTER_SUPPORT_UNDEFINED;

	ret = adapter_detect_adapter_support_mode(ADAPTER_PROTOCOL_FCP,
		&adp_mode);
	pr_info("adapter detect: support_mode=%x ret=%d\n", adp_mode, ret);

	if (!direct_charge_is_failed()) {
		fcp_output_vol_retry_cnt = 0;
		if (ret == FCP_ADAPTER_DETECT_FAIL)
			return 1;

		if (ret != FCP_ADAPTER_DETECT_SUCC) {
			pr_err("fcp detect fail\n");
			return -1;
		}

		adapter_get_support_mode(ADAPTER_PROTOCOL_SCP, &scp_adp_mode);
		if ((scp_adp_mode & LVC_MODE) || (scp_adp_mode & SC_MODE))
			return -1;
	}
	if (fcp_output_vol_retry_cnt < MAX_CNT) {
		fcp_output_vol_retry_cnt++;
	} else {
		pr_err("fcp try times =%d, max timers =%d\n",
			fcp_output_vol_retry_cnt, MAX_CNT);
		return -1;
	}
	if (!adp_mode || ret)
		return -1;
	return 0;
}

static void fcp_start_detect_no_hv_mode(void)
{
	int ret;

	ret = detect_support_fcp_mode();
	if (ret == 0)
		dc_send_quick_charging_uevent();
}

enum fcp_check_stage_type fcp_get_stage(void)
{
	return fcp_stage;
}

/**********************************************************
*  Function:       fcp_set_stage_status
*  Description:    set the stage of fcp charge
*  Parameters:     di:charge_device_info
*  return value:   NULL
**********************************************************/
void fcp_set_stage_status(enum fcp_check_stage_type stage_type)
{
	fcp_stage = stage_type;
}

int get_fcp_charging_flag(void)
{
	return fcp_charge_flag;
}

void set_fcp_charging_flag(int val)
{
	fcp_charge_flag = val;
}

/*bool get_pd_charge_flag(void)
{
	unsigned int boot_mode = get_boot_mode();

	if (boot_mode == KERNEL_POWER_OFF_CHARGING_BOOT
	    || boot_mode == LOW_POWER_OFF_CHARGING_BOOT)
	    return true;
	return false;

}*/

int fcp_test_is_support(void)
{
	if (adapter_get_protocol_register_state(ADAPTER_PROTOCOL_FCP)) {
		hwlog_err("adapter protocol not ready\n");
		return -1;
	}

	return 0;
}

int fcp_test_detect_adapter(void)
{
	int ret;
	int adp_mode = ADAPTER_SUPPORT_UNDEFINED;

	ret = adapter_get_support_mode(ADAPTER_PROTOCOL_FCP, &adp_mode);
	hwlog_info("adapter detect: support_mode=%x ret=%d\n", adp_mode, ret);

	if (ret || (adp_mode == ADAPTER_SUPPORT_UNDEFINED))
		return -1;

	return 0;
}

int fcp_support_show(void)
{
	int result = FCP_TEST_FAIL;
	enum charger_type type;

	type = mt_get_charger_type();

	/* judge whether support fcp */
	if(fcp_test_is_support())
	{
		result = FCP_TEST_NOT_SUPPORT;
		hwlog_err("fcp support fail\n");
		goto fcp_test_done;
	}
	/*to avoid the usb port cutoff when CTS test*/
	if ((type == CHARGER_TYPE_USB ) || (type == CHARGER_TYPE_BC_USB)) {
		result = FCP_TEST_FAIL;
		hwlog_err("fcp detect fail 1,charge type is %d \n",type);
		goto fcp_test_done;
	}
	/* fcp adapter detect */
	if(fcp_test_detect_adapter()){
		hwlog_err("fcp detect fail 2,charge type is %d \n",type);
		result = FCP_TEST_FAIL;
	}else{
		result = FCP_TEST_SUCC;
	}

fcp_test_done:
	hwlog_info("%s: fcp test result %d\n",__func__,result);
	return result;
}

static int charge_reset_fcp_adapter(struct huawei_battery_info *info)
{
	int i;
	int ret;
	unsigned int vbus;
	int sleep_time = 1000; /* total sleep time is 1000ms */
	int interval = 50; /* sleep interval is 50ms */
	int adp_type = ADAPTER_TYPE_UNKNOWN;

	if (!info) {
		pr_err("di is null\n");
		return -1;
	}

	adapter_get_adp_type(ADAPTER_PROTOCOL_SCP, &adp_type);

	/* 65W adapter not support reset, set output voltage 5V */
	if ((adp_type == ADAPTER_TYPE_20V3P25A_MAX) ||
		(adp_type == ADAPTER_TYPE_20V3P25A)) {
		ret = adapter_set_output_voltage(ADAPTER_PROTOCOL_FCP,
			ADAPTER_5V * 1000); /* 1V=1000mV */
		power_supply_set_int_property_value("usb", POWER_SUPPLY_PROP_ADAPTOR_VOLTAGE,
			ADAPTER_5V);
		if (ret) {
			pr_err("65W adp set 5V fail\n");
			goto soft_reset_adapter;
		}
		pr_info("65W adp set output vol %d V\n", ADAPTER_5V);

		for (i = 0; i < (sleep_time / interval); i++) {
			if (!info->charger_thread_polling) {
				pr_info("adapter remove, stop msleep\n");
				return -1;
			}

			msleep(interval);
		}

		ret = charger_dev_get_vbus(&vbus);
		if (ret < 0) { // to do
			pr_err("65W adp get vbus fail\n");
			goto soft_reset_adapter;
		}
		pr_info("65W adp vbus %d mV\n", vbus);

		/* 4500: lower limit; 5500: upper limit */
		if ((vbus > 5500) || (vbus < 4500)) {
			pr_err("65W adp vbus out of range\n");
			goto soft_reset_adapter;
		}

		return 0;
	}

soft_reset_adapter:
	return adapter_soft_reset_slave(ADAPTER_PROTOCOL_FCP);
}

/**********************************************************
*  Function:       fcp_retry_pre_operate
*  Discription:    pre operate before retry fcp enable
*  Parameters:   di:charge_device_info,type : enum fcp_retry_operate_type
*  return value:  0: fcp pre operate success
*                     -1:fcp pre operate fail
**********************************************************/

/*lint -save -e* */
static int fcp_retry_pre_operate(enum fcp_retry_operate_type type)
{
	int pg_state = 0, ret = -1;
	ret = charger_dev_get_chg_state(&pg_state);
	if (ret < 0) {
		hwlog_err("get_charge_state fail!!ret = 0x%x\n", ret);
		return ret;
	}
	/*check status charger not power good state */
	if (pg_state & CHAGRE_STATE_NOT_PG) {
		hwlog_err("state is not power good \n");
		return -1;
	}
	switch (type) {
	case FCP_RETRY_OPERATE_RESET_ADAPTER:
		hwlog_info("send fcp adapter reset cmd\n");
		ret = adapter_soft_reset_slave(ADAPTER_PROTOCOL_FCP);
		break;
	case FCP_RETRY_OPERATE_RESET_SWITCH:
		hwlog_info("switch_chip_reset\n");
		ret = adapter_soft_reset_master(ADAPTER_PROTOCOL_FCP);
		/* must delay 2000ms to wait adapter reset success */
		msleep(2000);
		break;
	default:
		break;
	}
	return ret;
}
/*lint -restore*/

/**********************************************************
*  Function:       fcp_check_switch_status
*  Description:    check switch chip status
*  Parameters:  void
*  return value:  void
**********************************************************/

/*lint -save -e* */
static void fcp_check_switch_status(void)
{
	int val = -1;
	int reg = 0;
	int ret = -1;
	unsigned int vbus;
	char tmp_buf[ERR_NO_STRING_SIZE] = { 0 };

	/* check usb is on or not ,if not ,can not detect the switch status */
	ret = charger_dev_get_chg_state(&reg);
	if (ret) {
		pr_info("%s:read PG STAT fail.\n", __func__);
		return;
	}
	if (reg & CHAGRE_STATE_NOT_PG) {
		pr_info
		    ("%s:PG NOT GOOD can not check switch status.\n", __func__);
		return;
	}

	val = adapter_get_master_status(ADAPTER_PROTOCOL_FCP);
	if (val) {
		switch_status_num = switch_status_num + 1;
	} else {
		switch_status_num = 0;
	}
	if (switch_status_num >= VBUS_REPORT_NUM) {
		switch_status_num = 0;
		ret = charger_dev_get_vbus(&vbus);
		if (ret < 0) {
			pr_err("%s:read vbus fail.\n", __func__);
			return;
		}
		snprintf(tmp_buf, sizeof(tmp_buf),
			"%s:fcp adapter connect fail,vbus=%d\n", __func__, vbus);
		power_dsm_dmd_report(POWER_DSM_FCP_CHARGE,
			ERROR_SWITCH_ATTACH, tmp_buf);
	}
}

/**********************************************************
*  Function:       fcp_check_adapter_status
*  Description:    check adapter status
*  Parameters:     void
*  return value:  void
**********************************************************/
void fcp_check_adapter_status(struct huawei_battery_info *info)
{
	int val = -1;
	int reg = 0;
	unsigned int vbus;
	unsigned int ibus;
	char tmp_buf[ERR_NO_STRING_SIZE] = { 0 };

	/* check usb is on or not ,if not ,can not detect the switch status */
	if (charger_dev_get_chg_state(&reg)) {
		pr_info("%s:read PG STAT fail.\n", __func__);
		return;
	}
	if (reg & CHAGRE_STATE_NOT_PG) {
		pr_info("%s:PG NOT GOOD can not check adapter status.\n", __func__);
		return;
	}

	val = adapter_get_slave_status(ADAPTER_PROTOCOL_FCP);
	if (val == ADAPTER_OUTPUT_UVP) {
		if (charger_dev_get_vbus(&vbus) < 0) {
			pr_err("%s:read vbus fail.\n", __func__);
			return;
		}
		snprintf(tmp_buf, sizeof(tmp_buf),
			"%s:fcp adapter voltage over high, vbus=%d\n", __func__, vbus);
		power_dsm_dmd_report(POWER_DSM_FCP_CHARGE,
			ERROR_ADAPTER_OVLT, tmp_buf);
	}
	else if (val == ADAPTER_OUTPUT_OCP) {
		if (charger_dev_get_ibus(&ibus) < 0) {
			pr_err("%s:read vbus fail.\n", __func__);
			return;
		}
		snprintf(tmp_buf, sizeof(tmp_buf),
			"%s:fcp adapter current over high, ibus=%d\n", __func__, ibus);
		power_dsm_dmd_report(POWER_DSM_FCP_CHARGE,
			ERROR_ADAPTER_OCCURRENT, tmp_buf);
	}
	else if (val == ADAPTER_OUTPUT_OTP) {
		snprintf(tmp_buf, sizeof(tmp_buf),
			"%s:fcp adapter temp over high\n", __func__);
		power_dsm_dmd_report(POWER_DSM_FCP_CHARGE,
			ERROR_ADAPTER_OTEMP, tmp_buf);
	}
}


/**********************************************************
*  Function:       fcp_start_charging
*  Description:    enter fcp charging mode
*  Parameters:   di:charge_device_info
*  return value:  0: fcp start success
*                    -1:fcp start fail
**********************************************************/

/*lint -save -e* */
static int fcp_start_charging(struct huawei_battery_info *info)
{
	int ret = -1;

	fcp_set_stage_status(FCP_STAGE_SUPPORT_DETECT);

	/*check whether support fcp detect */
	if (adapter_get_protocol_register_state(ADAPTER_PROTOCOL_FCP)) {
		pr_err("not support fcp\n");
		return -1;
	}
	/*To avoid to effect accp detect , input current need to be lower than 1A,we set 0.5A */
	/*pdata->input_current_limit = CHARGE_CURRENT_0500_MA;
	charger_dev_set_input_current(info->chg1_dev,
		pdata->input_current_limit);*/

	/*detect fcp adapter */
	fcp_set_stage_status(FCP_STAGE_ADAPTER_DETECT);
	ret = detect_support_fcp_mode();
	if (ret != 0)
		return ret;
	chg_set_adaptor_test_result(TYPE_FCP,DETECT_SUCC);
	fcp_set_stage_status(FCP_STAGE_ADAPTER_ENABLE);

	/* set fcp adapter output voltage, 1000: v to mv */
	ret = adapter_set_output_voltage(ADAPTER_PROTOCOL_FCP,
		ADAPTER_9V * 1000);
	if (ret) {
		pr_err("fcp set vol fail!\n");
		ret = adapter_soft_reset_master(ADAPTER_PROTOCOL_FCP);
		return 1;
	}
	pr_info("output vol = %d\n", ADAPTER_9V);
	power_supply_set_int_property_value("usb", POWER_SUPPLY_PROP_ADAPTOR_VOLTAGE, ADAPTER_9V);

#ifdef CONFIG_DIRECT_CHARGER
	fcp_output_vol_retry_cnt = 0;
#endif
	if (!info->charger_thread_polling) {
		fcp_set_stage_status(FCP_STAGE_DEFAUTL);
		pr_info("[%s] charge already stop\n", __func__);
		return 0;
	}
	chg_set_adaptor_test_result(TYPE_FCP, PROTOCOL_FINISH_SUCC);
#ifdef CONFIG_DIRECT_CHARGER
	dc_send_quick_charging_uevent();
#endif
	charge_send_icon_uevent(ICON_TYPE_QUICK);
	info->chr_type = CHARGER_TYPE_FCP;
	fcp_set_stage_status(FCP_STAGE_SUCESS);
	set_fcp_charging_flag(1);
	(void)power_supply_set_int_property_value("usb",
 		POWER_SUPPLY_PROP_REAL_TYPE, info->chr_type);
#ifndef CONFIG_PMIC_AP_CHARGER
	hihonor_charger_glink_set_charger_type(info->chr_type);
#endif
	msleep(CHIP_RESP_TIME);
	pr_info("fcp charging start success!\n");
	return 0;
}

void force_stop_fcp_charging(struct huawei_battery_info *info)
{
	int ret;

	if (fcp_get_stage() != FCP_STAGE_SUCESS)
		return;
	if (info->enable_hv_charging && !get_reset_adapter())
		return;

	/* set mivr 4.6V when disable hv charging */
	charger_dev_set_mivr(4600000);
	if (charge_reset_fcp_adapter(info)) {
		hwlog_err("adapter reset failed\n");
		return;
	}
	hwlog_info("reset adapter by user\n");
	fcp_set_stage_status(FCP_STAGE_RESET_ADAPTOR);

	ret = charger_dev_set_vbus_vset(ADAPTER_5V);
	if(ret)
		hwlog_err("set vbus_vset fail\n");

	info->chr_type = CHARGER_TYPE_STANDARD;

	/* Get chg type det power supply */
	(void)power_supply_set_int_property_value("usb",
 		POWER_SUPPLY_PROP_REAL_TYPE, info->chr_type);

	msleep(CHIP_RESP_TIME);
}

static void fcp_check_vbus_voltage(struct huawei_battery_info *info)
{
	int ret;
	int vbus_vol;
	static int vbus_flag;
	char tmp_buf[ERR_NO_STRING_SIZE] = { 0 };

	ret = charger_dev_get_vbus(&vbus_vol);
	if (ret < 0) {
		hwlog_err("%s:read vbus fail.\n", __func__);
		return;
	}

	/* fcp stage : vbus must be higher than 7000 mV */
	if (vbus_vol < VBUS_VOLTAGE_7000_MV) {
		fcp_vbus_lower_count += 1;
		hwlog_err("[%s]fcp output vol =%d mV, lower 7000 mV , fcp_vbus_lower_count =%d!!\n",
			__func__, vbus_vol, fcp_vbus_lower_count);
	} else {
		fcp_vbus_lower_count = 0;
	}
	/* check continuous abnormal vbus cout  */
	if (fcp_vbus_lower_count >= VBUS_VOLTAGE_ABNORMAL_MAX_COUNT) {
		vbus_flag = vbus_flag + 1;
		fcp_check_adapter_status(info);
		fcp_set_stage_status(FCP_STAGE_DEFAUTL);
		info->chr_type = CHARGER_TYPE_STANDARD;
		if (adapter_soft_reset_slave(ADAPTER_PROTOCOL_FCP))
			hwlog_err("adapter reset failed\n");
			ret = adapter_set_output_voltage(ADAPTER_PROTOCOL_FCP, ADAPTER_5V * 1000);
		if (ret) {
			pr_err("fcp set vol fail!\n");
			return;
		}
			fcp_vbus_lower_count = VBUS_VOLTAGE_ABNORMAL_MAX_COUNT;
	}
	if (VBUS_REPORT_NUM <= vbus_flag) {
		vbus_flag = 0;
		snprintf(tmp_buf, sizeof(tmp_buf),
			"%s:fcp vbus is low, vol=%d\n", __func__, vbus_vol);
		power_dsm_dmd_report(POWER_DSM_FCP_CHARGE,
				ERROR_FCP_VOL_OVER_HIGH, tmp_buf);
	}
	nonfcp_vbus_higher_count = 0;
}

static void non_fcp_check_vbus_voltage(struct huawei_battery_info *info)
{
	int ret;
	int vbus_vol;
	char tmp_buf[ERR_NO_STRING_SIZE] = { 0 };

	ret = charger_dev_get_vbus(&vbus_vol);
	if (ret < 0) {
		hwlog_err("%s:read vbus fail.\n", __func__);
		return;
	}

	/* non fcp stage : vbus must be lower than 6500 mV */
	if (vbus_vol > VBUS_VOLTAGE_6500_MV) {
		nonfcp_vbus_higher_count += 1;
		hwlog_info("[%s]non standard fcp and vbus voltage is %d mv, over 6500mv ,nonfcp_vbus_higher_count =%d!!\n",
			__func__, vbus_vol, nonfcp_vbus_higher_count);
	} else {
		nonfcp_vbus_higher_count = 0;
	}
	/* check continuous abnormal vbus cout  */
	if (nonfcp_vbus_higher_count >= VBUS_VOLTAGE_ABNORMAL_MAX_COUNT) {
		nonfcp_vbus_higher_count = VBUS_VOLTAGE_ABNORMAL_MAX_COUNT;
		snprintf(tmp_buf, sizeof(tmp_buf),
			"%s:fcp vbus is high, vol=%d\n", __func__, vbus_vol);
		power_dsm_dmd_report(POWER_DSM_FCP_CHARGE,
			ERROR_FCP_VOL_OVER_HIGH, tmp_buf);
		if (adapter_is_accp_charger_type(ADAPTER_PROTOCOL_FCP)) {
			if (adapter_soft_reset_slave(ADAPTER_PROTOCOL_FCP))
				hwlog_err("adapter reset failed\n");
			hwlog_info("[%s]is fcp adapter\n", __func__);
		} else {
			hwlog_info("[%s] is not fcp adapter\n", __func__);
		}
	}
	fcp_vbus_lower_count = 0;
}

void charge_vbus_voltage_check(struct huawei_battery_info *info)
{
	int ret;
	int vbus_vol;
	int vbus_ovp_cnt = 0;
	int i;
	char tmp_buf[ERR_NO_STRING_SIZE] = { 0 };

	if (!info)
		return;

	for (i = 0; i < VBUS_VOL_READ_CNT; ++i) {
		ret = charger_dev_get_vbus(&vbus_vol);
		if (ret)
			hwlog_err("vbus vol read fail\n");
		hwlog_info("vbus vbus_vol:%u\n", vbus_vol);

		if (vbus_vol > VBUS_VOLTAGE_13400_MV) {
			if (!get_charge_not_pg())
				vbus_ovp_cnt++; // if power ok, then count plus one.
				msleep(25); // Wait for chargerIC to be in stable state
		} else {
			break;
		}
	}
	if (vbus_ovp_cnt == VBUS_VOL_READ_CNT) {
		hwlog_err("[%s]vbus_vol = %u\n", __func__, vbus_vol);
		snprintf(tmp_buf, sizeof(tmp_buf),
			"%s:vbus over 13400mv, vol = %d\n", __func__, vbus_vol);
		power_dsm_dmd_report(POWER_DSM_QCOM_BUCK, ERROR_VBUS_VOL_OVER_13400MV, tmp_buf);
	}

	if (FCP_STAGE_SUCESS == fcp_get_stage())
		fcp_check_vbus_voltage(info);
	else
		non_fcp_check_vbus_voltage(info);
}

extern void set_rt_test_result(bool flag);
extern u32 get_rt_curr_th(void);
void fcp_charge_check(struct huawei_battery_info *info)
{
	int ret = 0, i = 0;
	bool cc_vbus_short = false;
	bool sbu_vbus_short = false;
	unsigned int vbus;
	char tmp_buf[ERR_NO_STRING_SIZE] = { 0 };

	hwlog_err("in fcp_charge_check, hv = %d, stage = %d, success=%d\n",
		info->enable_hv_charging, fcp_get_stage(), FCP_STAGE_SUCESS);

	if (!info->charger_thread_polling) {
		hwlog_info("[%s] charge already stop\n", __func__);
		return;
	}

	/* cc rp 3.0 can not do high voltage charge */
	//cc_vbus_short = pd_dpm_check_cc_vbus_short();
	if (cc_vbus_short) {
		hwlog_err("cc match rp3.0, can not do fcp charge\n");
		return;
	}

	/* sbu vbus short can not do high voltage charge */
	sbu_vbus_short = pd_dpm_check_sbu_vbus_short();
	if (sbu_vbus_short) {
		hwlog_err("sbu vbus short, can not do fcp charge\n");
		return;
	}

	if (FCP_STAGE_SUCESS == fcp_get_stage())
		fcp_check_switch_status();

	hwlog_info("[%s] info->chr_type = %d, stand = %d, fcp = %d\n", __func__,
		info->chr_type, CHARGER_TYPE_STANDARD, POWER_SUPPLY_TYPE_FCP);
	if (info->chr_type != CHARGER_TYPE_STANDARD &&
		info->chr_type != CHARGER_TYPE_FCP)
		return;

	if ((info->enable_hv_charging == false) && (get_first_insert() == 1)) {
		hwlog_info("fcp first insert direct check\n");
		fcp_start_detect_no_hv_mode();
		set_first_insert(0);
		return;
	}

	/* record rt adapter test result when test succ */
	if (strstr(saved_command_line, "androidboot.swtype=factory")) {
		if (fcp_charge_flag &&
			((-battery_get_bat_current()) >= (int)get_rt_curr_th()))
			set_rt_test_result(true);
	}
	if (direct_charge_is_failed() &&
		(fcp_get_stage() < FCP_STAGE_SUCESS))
		fcp_set_stage_status(FCP_STAGE_DEFAUTL);
	/*if(get_pd_charge_flag() == true){
		msleep(FCP_DETECT_DELAY_IN_POWEROFF_CHARGE);
	}*/
	if (info->enable_hv_charging &&
		((fcp_get_stage() == FCP_STAGE_DEFAUTL &&
		!(get_reset_adapter() & (1 << RESET_ADAPTER_WIRELESS_TX))) ||
		((fcp_get_stage() == FCP_STAGE_RESET_ADAPTOR) &&
		(get_reset_adapter() == 0)))) {
		ret = fcp_start_charging(info);
		for (i = 0; i < 3 && ret == 1; i++) {
			/* reset adapter and try again */
			if (fcp_retry_pre_operate(FCP_RETRY_OPERATE_RESET_ADAPTER) < 0) {
				hwlog_err("reset adapter failed\n");
				break;
			}
			ret = fcp_start_charging(info);
		}
		if (ret == 1) {
			/* reset fsa9688 chip and try again */
			if (fcp_retry_pre_operate(FCP_RETRY_OPERATE_RESET_SWITCH) == 0) {
				ret = fcp_start_charging(info);
			} else {
				hwlog_err("%s : fcp_retry_pre_operate failed \n", __func__);
			}
		}
		if (ret == 1 && ++fcp_charge_check_cnt <= FCP_CHECK_CNT_MAX) {
			hwlog_err("fcp_charge_check_cnt = %d\n", fcp_charge_check_cnt);
			fcp_set_stage_status(FCP_STAGE_DEFAUTL);
			return;
		}

		if (ret == 1) {
			if (FCP_STAGE_ADAPTER_ENABLE == fcp_get_stage())
				output_num = output_num + 1;
			else
				output_num = 0;

			if (output_num >= VBUS_REPORT_NUM) {
				if (!direct_charge_is_failed()) {
					ret = charger_dev_get_vbus(&vbus);
					if (ret < 0) {
						pr_err("%s:read vbus fail.\n", __func__);
						return;
					}
					snprintf(tmp_buf, sizeof(tmp_buf),
						"%s:fcp boost failed, vbus=%d\n", __func__, vbus);
					power_dsm_dmd_report(POWER_DSM_FCP_CHARGE,
						ERROR_FCP_OUTPUT, tmp_buf);
				}
			}
			if (FCP_STAGE_ADAPTER_DETECT == fcp_get_stage())
				detect_num = detect_num + 1;
			else
				detect_num = 0;

			if (detect_num >= VBUS_REPORT_NUM) {
				ret = charger_dev_get_vbus(&vbus);
				if (ret < 0) {
					pr_err("%s:read vbus fail.\n", __func__);
					return;
				}
				snprintf(tmp_buf, sizeof(tmp_buf),
					"%s:fcp detect failed, vbus=%d\n", __func__, vbus);
				power_dsm_dmd_report(POWER_DSM_FCP_CHARGE,
					ERROR_FCP_DETECT, tmp_buf);
			}
			if(VBUS_REPORT_NUM > output_num && VBUS_REPORT_NUM > detect_num)
				fcp_set_stage_status(FCP_STAGE_DEFAUTL);
		}

		hwlog_info("[%s]fcp stage  %s !!! \n", __func__,
			   fcp_check_stage[fcp_get_stage()]);
	}

	force_stop_fcp_charging(info);
}
