/*
 * fsa9685_bc12.c
 *
 * bc12 with fsa9685 driver
 *
 * Copyright (c) 2021-2021 Huawei Technologies Co., Ltd.
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

#include "fsa9685_bc12.h"
#include <linux/delay.h>
#include <linux/power_supply.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/adapter/adapter_test.h>
#include <chipset_common/hwpower/common_module/power_devices_info.h>
#include <chipset_common/hwpower/common_module/power_gpio.h>
#include <huawei_platform/hwpower/common_module/power_platform.h>
#include <huawei_platform/power/direct_charger/direct_charger.h>
#include <huawei_platform/power/huawei_charger_adaptor.h>
#include <huawei_platform/power/huawei_charger_common.h>
#include <huawei_platform/usb/switch/fsa9685.h>
#include <huawei_platform/usb/switch/switch_chip_common.h>
#include "fsa9685_reg.h"
#include "switch_chip_i2c.h"
#include "fsa9685_accp.h"

#define HWLOG_TAG fsa9685_bc12
HWLOG_REGIST();

static int g_non_standard_retrycnt;

static int fsa9685_dcd_timeout(bool enable_flag)
{
	int reg_val;
	struct fsa9685_device_info *di = fsa9685_get_dev_info();
	int ret;

	if (!di)
		return SET_DCDTOUT_FAIL;

	enable_flag |= di->dcd_timeout_force_enable;
	reg_val = switch_read_reg(di->client, FSA9685_REG_DEVICE_ID);
	reg_val &= FAS9685_VERSION_ID_BIT_MASK;
	reg_val >>= FAS9685_VERSION_ID_BIT_SHIFT;
	/* 9688c 9683 except 9688 do not support */
	if (reg_val == FSA9688_VERSION_ID)
		return SET_DCDTOUT_FAIL;
	ret = switch_write_reg_mask(di->client, FSA9685_REG_CONTROL2,
		enable_flag, FSA9685_DCD_TIME_OUT_MASK);
	if (ret < 0)
		return SET_DCDTOUT_FAIL;
	hwlog_info("%s enable_flag is %d\n", __func__, enable_flag);
	return SET_DCDTOUT_SUCC;
}

static int fsa9685_dcd_timeout_status(void)
{
	struct fsa9685_device_info *di = fsa9685_get_dev_info();

	if (!di)
		return SET_DCDTOUT_FAIL;

	return di->dcd_timeout_force_enable;
}

static void fsa9685_set_usbsw_state(int state)
{
	hwlog_info("%s state = %d\n", __func__, state);

	if (state == FSA9685_USBSW_CHG)
		charger_detect_init();
	else
		charger_detect_release();
}

static unsigned int fsa9685_get_charger_type(void)
{
	unsigned int chg_type = CHARGER_REMOVED;
	int val;
	struct fsa9685_device_info *di = fsa9685_get_dev_info();

	if (!di || !di->client)
		return chg_type;

	val = switch_read_reg(di->client, FSA9685_REG_DEVICE_TYPE_1);
	if (val < 0) {
		hwlog_err("%s read FSA9685_REG_DEVICE_TYPE_1 error\n", __func__);
		return chg_type;
	}

	if (val & FSA9685_USB_DETECTED)
		chg_type = CHARGER_TYPE_USB;
	else if (val & FSA9685_CDP_DETECTED)
		chg_type = CHARGER_TYPE_BC_USB;
	else if (val & FSA9685_DCP_DETECTED)
		chg_type = CHARGER_TYPE_STANDARD;
	else
		chg_type = CHARGER_TYPE_NON_STANDARD;

	if ((chg_type == CHARGER_REMOVED) && fsa9685_is_accp_charger_type(di)) {
		chg_type = CHARGER_TYPE_STANDARD;
		hwlog_info("%s:update by device type4 charger type is %u\n",
			__func__, chg_type);
	}

	hwlog_info("%s chg_type = %u\n", __func__, chg_type);
	return chg_type;
}

static int fsa9685_psy_online_changed(struct fsa9685_device_info *di)
{
	int ret;
	union power_supply_propval propval;

	/* Get chg type det power supply */
	if (!di->ac_psy)
		di->ac_psy = power_supply_get_by_name("usb");
	if (!di->ac_psy) {
		hwlog_info("%s: get ac power supply failed\n", __func__);
		return -EINVAL;
	}

	if (!di->usb_psy)
		di->usb_psy = power_supply_get_by_name("pc_port");
	if (!di->usb_psy) {
		hwlog_info("%s: get usb power supply failed\n", __func__);
		return -EINVAL;
	}

	propval.intval = di->attach;
	if (di->attach == 0) {
		ret = power_supply_set_property(di->ac_psy, POWER_SUPPLY_PROP_ONLINE, &propval);
		if (ret < 0)
			hwlog_err("%s: ac psy online fail %d\n", __func__, ret);
		ret += power_supply_set_property(di->usb_psy, POWER_SUPPLY_PROP_ONLINE, &propval);
		if (ret < 0)
			hwlog_err("%s: usb psy online fail %d\n", __func__, ret);

		power_supply_changed(di->ac_psy);
		power_supply_changed(di->usb_psy);
		return ret;
	}

	if ((di->chg_type == CHARGER_TYPE_USB) || (di->chg_type == CHARGER_TYPE_BC_USB)) {
		ret = power_supply_set_property(di->usb_psy, POWER_SUPPLY_PROP_ONLINE, &propval);
		power_supply_changed(di->usb_psy);
	} else {
		ret = power_supply_set_property(di->ac_psy, POWER_SUPPLY_PROP_ONLINE, &propval);
		power_supply_changed(di->ac_psy);
	}
	if (ret < 0)
		hwlog_err("%s: psy online fail %d\n", __func__, ret);
	else
		hwlog_info("%s: pwr_rdy = %d\n",  __func__, di->attach);

	return ret;
}

int fsa9685_psy_chg_type_changed(void)
{
	int ret;
	union power_supply_propval propval;
	struct fsa9685_device_info *di = fsa9685_get_dev_info();

	if (!di)
		return -EINVAL;

	/* Get chg type det power supply */
	if (!di->ac_psy)
		di->ac_psy = power_supply_get_by_name("usb");
	if (!di->ac_psy) {
		hwlog_info("%s: get power supply failed\n", __func__);
		return -EINVAL;
	}

	propval.intval = di->chg_type;
	ret = power_supply_set_property(di->ac_psy, POWER_SUPPLY_PROP_REAL_TYPE, &propval);
	if (ret < 0)
		hwlog_err("%s: psy type failed, ret = %d\n", __func__, ret);
	else
		hwlog_info("%s: chg_type = %d\n", __func__, di->chg_type);

	return ret;
}

static void fsa9685_resume_irq(void)
{
	int reg_ctl;
	int ret;
	struct fsa9685_device_info *di = fsa9685_get_dev_info();

	if (!di)
		return;

	/* clear INT MASK */
	reg_ctl = switch_read_reg(di->client, FSA9685_REG_CONTROL);
	if (reg_ctl < 0) {
		hwlog_err("read reg FSA9685_REG_CONTROL failed\n");
		return;
	}
	hwlog_info("read FSA9685_REG_CONTROL. reg_ctl=0x%x\n", reg_ctl);

	reg_ctl &= ~FSA9685_INT_MASK;
	ret = switch_write_reg(di->client, FSA9685_REG_CONTROL, reg_ctl);
	hwlog_info("write FSA9685_REG_CONTROL. reg_ctl=0x%x, ret=%d\n", reg_ctl, ret);

	/* 0x0c: DMD status init */
	ret = switch_write_reg(di->client, FSA9685_REG_DCD, FSA9685_REG_DCD_STATUS_INIT_VAL);
	hwlog_info("write FSA9685_REG_DCD. reg_DCD=0x%x, ret=%d\n",
		FSA9685_REG_DCD_STATUS_INIT_VAL, ret);

	/* disable dcd time out */
	switch_write_reg_mask(di->client, FSA9685_REG_CONTROL2, 0, FSA9685_DCD_TIME_OUT_MASK);
	hwlog_info("dcd time out 0x0e=0x%x\n", switch_read_reg(di->client, FSA9685_REG_CONTROL2));
}

void fsa9685_update_nstd_chg_type(unsigned int chg_type)
{
	struct fsa9685_device_info *di = fsa9685_get_dev_info();

	if (!di)
		return;

	if (di->chg_type != CHARGER_TYPE_NON_STANDARD)
		return;

	hwlog_info("%s: update chg_type %d to %d\n", __func__, di->chg_type, chg_type);
	di->chg_type = chg_type;
	if (chg_type == CHARGER_TYPE_USB) {
		hwlog_info("%s: if sdp recheck type\n", __func__);
		schedule_delayed_work(&di->update_type_work, msecs_to_jiffies(0));
		return;
	}

	fsa9685_psy_chg_type_changed();
}

void fsa9685_update_type_work(struct work_struct *work)
{
	struct fsa9685_device_info *di = fsa9685_get_dev_info();
	unsigned int chg_type;

	if (!di)
		return;

	hwlog_info("%s: +\n", __func__);
	fsa9685_set_usbsw_state(0); /* set usb_phy chg_state */
	switch_write_reg(di->client, FSA9685_REG_RESET, FSA9685_RESET_CHIP);
	msleep(DELAY_FOR_RESET);

	chg_type = fsa9685_get_charger_type();
	if (chg_type != CHARGER_REMOVED) {
		di->chg_type = chg_type;
		fsa9685_psy_chg_type_changed();
		/* notify online */
		fsa9685_psy_online_changed(di);
	}
	fsa9685_resume_irq();
	hwlog_info("%s: -\n", __func__);
}

void fsa9685_chg_det_work(struct work_struct *work)
{
	int ret;
	unsigned int chg_type;
	struct fsa9685_device_info *di = fsa9685_get_dev_info();

	if (!di)
		return;

	/* attach */
	di->attach = 1;
	chg_type = fsa9685_get_charger_type();
	if (chg_type == CHARGER_TYPE_USB) {
		/* work redo bc12 */
		schedule_delayed_work(&di->update_type_work, msecs_to_jiffies(DELAY_FOR_SDP_RETRY));
		/* notify online */
		ret = fsa9685_psy_online_changed(di);
		if (ret < 0)
			hwlog_err("%s: sdp online report fail\n", __func__);

		hwlog_info("%s: sdp schedule work to redo bc12\n", __func__);
		return;
	} else if (chg_type == CHARGER_REMOVED) {
		goto chg_det_fail;
	} else if (chg_type == CHARGER_TYPE_NON_STANDARD) {
		hwlog_info("%s: bc12 g_non_standard_retrycnt:%d\n", __func__,
			g_non_standard_retrycnt);
		if (g_non_standard_retrycnt < FSA9688_NON_STANDARD_RETRY_MAX) {
			schedule_delayed_work(&di->chg_det_work,
				msecs_to_jiffies(DELAY_FOR_BC12_REG));
			g_non_standard_retrycnt++;
			return;
		}
	}

	g_non_standard_retrycnt = 0;
	di->chg_type = chg_type;
	/* notify online */
	ret = fsa9685_psy_online_changed(di);
	if (ret < 0)
		goto chg_det_fail;

	ret = fsa9685_psy_chg_type_changed();
	if (ret < 0)
		goto chg_det_fail;

	hwlog_info("%s: charger type:%d\n", __func__, di->chg_type);
	return;

chg_det_fail:
	hwlog_err("%s: chg type err\n", __func__);
	/* release usb_phy to soc */
	fsa9685_set_usbsw_state(1);
	return;
}

static int fsa9685_chg_type_det(bool en)
{
	int ret;
	struct fsa9685_device_info *di = fsa9685_get_dev_info();

	if (!di)
		return -EINVAL;

	atomic_set(&di->chg_type_det, en);
	/* attach */
	if (en) {
		fsa9685_set_usbsw_state(0); /* set usb_phy chg_state */
		schedule_delayed_work(&di->chg_det_work, msecs_to_jiffies(DELAY_FOR_BC12_REG));
		hwlog_info("%s: schedule work to get bc12 result\n", __func__);
		return 0;
	}

	cancel_delayed_work_sync(&di->chg_det_work);
	cancel_delayed_work_sync(&di->update_type_work);

	/* detach */
	hwlog_info("%s: detach\n", __func__);
	fsa9685_set_usbsw_state(1); /* release usb_phy to soc */
	di->attach = 0;
	di->chg_type = CHARGER_REMOVED;
	ret = fsa9685_psy_online_changed(di);
	if (ret < 0)
		goto psy_notify_fail;
	ret = fsa9685_psy_chg_type_changed();
	if (ret < 0)
		goto psy_notify_fail;

	return 0;

psy_notify_fail:
	hwlog_err("%s: chg type err\n", __func__);
	return -1;
}

static struct switch_interface_bc12_ops fsa9685_bc12_ops = {
	.get_charger_type = fsa9685_get_charger_type,
	.chg_type_det = fsa9685_chg_type_det,
	.dcd_timeout = fsa9685_dcd_timeout,
	.dcd_timeout_status = fsa9685_dcd_timeout_status,
};

struct switch_interface_bc12_ops *fas9685_get_bc12_ops(void)
{
	return &fsa9685_bc12_ops;
}
