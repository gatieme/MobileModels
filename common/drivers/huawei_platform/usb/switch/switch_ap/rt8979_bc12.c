/*
 * rt8979_bc12.c
 *
 * driver file for switch chip
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

#include "rt8979_bc12.h"
#include <linux/delay.h>
#include <linux/gpio.h>
#include <linux/i2c.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/of_gpio.h>
#include <linux/pm_runtime.h>
#include <linux/power_supply.h>
#include <linux/interrupt.h>
#include <linux/bitops.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_i2c.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <huawei_platform/power/huawei_charger_adaptor.h>
#include <huawei_platform/hwpower/common_module/power_platform.h>
#include <huawei_platform/usb/switch/switch_chip_common.h>
#include "rt8979.h"
#include "rt8979_reg.h"
#include "rt8979_accp.h"
#include "switch_chip_i2c.h"

#define HWLOG_TAG rt8979_bc12
HWLOG_REGIST();

#define RT8979_IRQ_ADC_CHG      7
#define RT8979_IRQ_RSV_ATTACH   6
#define RT8979_IRQ_VBUS_CHANGE  5
#define RT8979_IRQ_DEV_CHANGE   4
#define RT8979_IRQ_DETACH       1
#define RT8979_IRQ_ATTACH       0
#define DCD_TIMEOUT 1200
#define SDP_RETRY_COUNT 2

static bool rt8979_dcd_timeout_enabled;

struct rt8979_desc {
	const char *chg_name;
	bool auto_switch;
	bool scp;
	bool dcd;
	u32 dcd_timeout;
	u32 intb_watchdog;
	u32 ovp_sel;
};

enum rt8979_usbsw_state {
	RT8979_USBSW_CHG = 0,
	RT8979_USBSW_USB,
};

static const u8 rt8979_reg_addrs[] = {
	RT8979_REG_DEVICE_ID,
	RT8979_REG_CONTROL,
	RT8979_REG_INTERRUPT_MASK,
	RT8979_REG_ADC,
	RT8979_REG_TIMING_SET_1,
	RT8979_REG_DETACH_CONTROL,
	RT8979_REG_DEVICE_TYPE_1,
	RT8979_REG_DEVICE_TYPE_2,
	RT8979_REG_DEVICE_TYPE_3,
	RT8979_REG_MANUAL_SW_1,
	RT8979_REG_MANUAL_SW_2,
	RT8979_REG_TIMING_SET_2,
	RT8979_REG_CONTROL2,
	RT8979_REG_DEVICE_TYPE_4,
	RT8979_REG_MUIC_CTRL_3,
	RT8979_REG_MUIC_CTRL_4,
	RT8979_REG_MUIC_STATUS1,
	RT8979_REG_MUIC_STATUS2,
	RT8979_REG_RESET,
	RT8979_REG_USBCHGEN,
};

/* ovp voltage table: 6.2V 6.8V 11.5V 14.5V */
static const u32 ovp_sel_tbl[] = { 6200000, 6800000, 11500000, 14500000 };
/* dcd timeout table: 300ms 600ms 900ms 1200ms */
static const u32 dcd_timeout_tbl[] = { 300, 600, 900, 1200 };
/* intb watchdog table: 0ms 250ms 500ms 1000ms */
static const u32 intb_watchdog_tbl[] = { 0, 250, 500, 1000 };

static struct rt8979_desc rt8979_default_desc = {
	.chg_name = "usb_switch",
	.auto_switch = true,
	.scp = false,
	.dcd = true,
	.dcd_timeout = 600, /* 600ms */
	.intb_watchdog = 0, /* disabled */
	.ovp_sel = 6800000, /* 6.8V */
};

static inline int __rt8979_i2c_read_byte(struct rt8979_device_info *chip, u8 cmd, u8 *data)
{
	int ret;
	u8 regval = 0;

	ret = i2c_smbus_read_i2c_block_data(chip->client, cmd, 1, &regval);
	if (ret < 0) {
		hwlog_info("%s reg0x%02X fail %d\n", __func__, cmd, ret);
		return ret;
	}

	hwlog_info("%s reg0x%02X = 0x%02X\n", __func__, cmd, regval);
	*data = regval & 0xFF;
	return 0;
}

static int rt8979_i2c_read_byte(struct rt8979_device_info *chip, u8 cmd, u8 *data)
{
	int ret;

	mutex_lock(&chip->io_lock);
	ret = __rt8979_i2c_read_byte(chip, cmd, data);
	mutex_unlock(&chip->io_lock);

	return ret;
}

static inline int __rt8979_i2c_write_byte(struct rt8979_device_info *chip, u8 cmd, u8 data)
{
	int ret;

	ret = i2c_smbus_write_i2c_block_data(chip->client, cmd, 1, &data);
	if (ret < 0)
		hwlog_info("%s reg0x%02X = 0x%02X fail %d\n", __func__, cmd, data, ret);
	else
		hwlog_info("%s reg0x%02X = 0x%02X\n", __func__, cmd, data);

	return ret;
}

static int rt8979_i2c_write_byte(struct rt8979_device_info *chip, u8 cmd, u8 data)
{
	int ret;

	mutex_lock(&chip->io_lock);
	ret = __rt8979_i2c_write_byte(chip, cmd, data);
	mutex_unlock(&chip->io_lock);

	return ret;
}

static int rt8979_i2c_update_bits(struct rt8979_device_info *chip, u8 cmd, u8 data, u8 mask)
{
	int ret;
	u8 regval = 0;

	mutex_lock(&chip->io_lock);
	ret = __rt8979_i2c_read_byte(chip, cmd, &regval);
	if (ret < 0)
		goto out;

	regval &= ~mask;
	regval |= (data & mask);

	ret = __rt8979_i2c_write_byte(chip, cmd, regval);
out:
	mutex_unlock(&chip->io_lock);
	return ret;
}

static inline int rt8979_set_bit(struct rt8979_device_info *chip, u8 cmd, u8 mask)
{
	return rt8979_i2c_update_bits(chip, cmd, mask, mask);
}

static inline int rt8979_clr_bit(struct rt8979_device_info *chip, u8 cmd, u8 mask)
{
	return rt8979_i2c_update_bits(chip, cmd, 0x00, mask);
}

static inline u8 rt8979_closest_reg_via_tbl(const u32 *tbl, u32 tbl_size, u32 target)
{
	u32 i;

	if (target <= tbl[0])
		return 0;

	for (i = 0; i < tbl_size - 1; i++) {
		if (target >= tbl[i] && target < tbl[i + 1])
			return i;
	}

	return tbl_size - 1;
}

static inline u32 rt8979_closest_value(u32 min, u32 max, u32 step, u8 regval)
{
	u32 val = min + (regval * step);

	if (val > max)
		val = max;

	return val;
}

static int rt8979_enable_auto_switch(struct rt8979_device_info *chip, bool en)
{
	hwlog_info("%s en = %d\n", __func__, en);
	return (en ? rt8979_set_bit : rt8979_clr_bit)
		(chip, RT8979_REG_CONTROL, RT8979_REG_CONTROL_SW_OPEN_MASK);
}

static int rt8979_enable_scp(struct rt8979_device_info *chip, bool en)
{
	int ret;

	hwlog_info("%s en = %d\n", __func__, en);
	if (en) {
		/* set REG_SCP 0x01 as default value */
		ret = rt8979_i2c_write_byte(chip, RT8979_REG_ACCP_CMD, 0x01);
		if (ret < 0)
			return ret;
	}
	return (en ? rt8979_set_bit : rt8979_clr_bit)
		(chip, RT8979_REG_CONTROL2, RT8979_REG_CONTROL2_ACCP_AUTO_EN_MASK);
}

static int rt8979_enable_dcd(struct rt8979_device_info *chip, bool en)
{
	hwlog_info("%s en = %d\n", __func__, en);
	return (en ? rt8979_set_bit : rt8979_clr_bit)
		(chip, RT8979_REG_CONTROL2, RT8979_REG_CONTROL2_DCD_TIMEOUT_EN_MASK);
}

static int rt8979_set_dcd_timeout(struct rt8979_device_info *chip, u32 tout)
{
	u8 regval;

	regval = rt8979_closest_reg_via_tbl(dcd_timeout_tbl,
		ARRAY_SIZE(dcd_timeout_tbl), tout);

	hwlog_info("%s tout = %d 0x%02X\n", __func__, tout, regval);

	return rt8979_i2c_update_bits(chip, RT8979_REG_TIMING_SET_2,
		regval << RT8979_REG_TIMING_SET_2_DCD_TIMEOUT_SET_SHIFT,
		RT8979_REG_TIMING_SET_2_DCD_TIMEOUT_SET_MASK);
}

static int rt8979_set_intb_watchdog(struct rt8979_device_info *chip, u32 wdt)
{
	u8 regval;

	regval = rt8979_closest_reg_via_tbl(intb_watchdog_tbl,
		ARRAY_SIZE(intb_watchdog_tbl), wdt);

	hwlog_info("%s wdt = %d 0x%02X\n", __func__, wdt, regval);

	return rt8979_i2c_update_bits(chip, RT8979_REG_TIMING_SET_2,
		regval << RT8979_REG_TIMING_SET_2_INTB_WATCHDOG_SHIFT,
		RT8979_REG_TIMING_SET_2_INTB_WATCHDOG_MASK);
}

static int rt8979_set_ovp_sel(struct rt8979_device_info *chip, u32 ovp)
{
	u8 regval;

	regval = rt8979_closest_reg_via_tbl(ovp_sel_tbl, ARRAY_SIZE(ovp_sel_tbl), ovp);

	hwlog_info("%s ovp = %d 0x%02X\n", __func__, ovp, regval);

	return rt8979_i2c_update_bits(chip, RT8979_REG_MUIC_CTRL_3,
		regval << RT8979_REG_MUIC_CTRL_3_OVP_SEL_SHIFT,
		RT8979_REG_MUIC_CTRL_3_OVP_SEL_MASK);
}

static int __rt8979_enable_bc12(struct rt8979_device_info *chip, bool en)
{
	hwlog_info("%s en = %d\n", __func__, en);
	return (en ? rt8979_set_bit : rt8979_clr_bit)
		(chip, RT8979_REG_USBCHGEN, RT8979_REG_USBCHGEN_ACCPDET_STAGE1);
}

bool rt8979_get_dcd_timeout_enabled(void)
{
	return rt8979_dcd_timeout_enabled;
}

void rt8979_set_dcd_timeout_enabled(bool flag)
{
	rt8979_dcd_timeout_enabled = flag;
}

static int rt8979_dcd_timeout(bool enable_flag)
{
	struct rt8979_device_info *di = rt8979_get_dev_info();
	int ret;

	if (!di)
		return SET_DCDTOUT_FAIL;

	enable_flag |= di->dcd_timeout_force_enable;
	rt8979_dcd_timeout_enabled = enable_flag;
	if (enable_flag) {
		ret = switch_write_reg_mask(di->client, RT8979_REG_TIMING_SET_2,
			0, RT8979_REG_TIMING_SET_2_DCD_TIMEOUT_SET_MASK);
		if (ret < 0) {
			hwlog_err("write RT8979_REG_TIMING_SET_2 error\n");
			return SET_DCDTOUT_FAIL;
		}
	} else {
		ret = switch_write_reg_mask(di->client, RT8979_REG_TIMING_SET_2,
			RT8979_REG_TIMING_SET_2_DCD_TIMEOUT_SET_MASK,
			RT8979_REG_TIMING_SET_2_DCD_TIMEOUT_SET_MASK);
		if (ret < 0)
			return SET_DCDTOUT_FAIL;
	}
	ret = switch_write_reg_mask(di->client, RT8979_REG_CONTROL2,
		RT8979_REG_CONTROL2_DCD_TIMEOUT_EN_MASK,
		RT8979_REG_CONTROL2_DCD_TIMEOUT_EN_MASK);
	if (ret < 0) {
		hwlog_err("write FSA9685_REG_CONTROL2 error\n");
		return SET_DCDTOUT_FAIL;
	}
	hwlog_info("enable_flag is %d\n", enable_flag);
	return SET_DCDTOUT_SUCC;
}

static int rt8979_dcd_timeout_status(void)
{
	struct rt8979_device_info *di = rt8979_get_dev_info();

	if (!di)
		return SET_DCDTOUT_FAIL;

	return di->dcd_timeout_force_enable;
}

static unsigned int rt8979_get_charger_type(void)
{
	unsigned int chg_type = CHARGER_REMOVED;
	int val;
	int usb_status;
	int muic_status1;
	struct rt8979_device_info *di = rt8979_get_dev_info();

	if (!di || !di->client)
		return chg_type;

	val = switch_read_reg(di->client, RT8979_REG_DEVICE_TYPE_1);
	if (val < 0) {
		hwlog_err("read RT8979_REG_DEVICE_TYPE_1 error\n");
		return chg_type;
	}

	muic_status1 = switch_read_reg(di->client, RT8979_REG_MUIC_STATUS1);
	usb_status = switch_read_reg(di->client, RT8979_REG_DEVICE_TYPE_1);
	hwlog_info("muic_status1:0x%x usb_status:0x%x\n", muic_status1, usb_status);
	if (usb_status != val)
		chg_type = CHARGER_REMOVED;
	else if (muic_status1 & RT8979_REG_MUIC_STATUS1_DCDT_MASK)
		chg_type = CHARGER_REMOVED;
	else if (val & RT8979_REG_DEVICE_TYPE_1_USB_MASK)
		chg_type = CHARGER_TYPE_USB;
	else if (val & RT8979_REG_DEVICE_TYPE_1_USB_CHARGER_MASK)
		chg_type = CHARGER_TYPE_BC_USB;
	else if (val & RT8979_REG_DEVICE_TYPE_1_DCP_MASK)
		chg_type = CHARGER_TYPE_STANDARD;
	else
		chg_type = CHARGER_REMOVED;

	if ((chg_type == CHARGER_REMOVED) && rt8979_is_accp_charger_type(di)) {
		chg_type = CHARGER_TYPE_STANDARD;
		hwlog_info("update by device type4 charger type is %u\n", chg_type);
	}

	hwlog_info("chg_type = %u\n", chg_type);
	return chg_type;
}

static int rt8979_psy_online_changed(struct rt8979_device_info *di)
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

int rt8979_psy_chg_type_changed(void)
{
	int ret;
	union power_supply_propval propval;
	struct rt8979_device_info *di = rt8979_get_dev_info();

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

#ifdef CONFIG_MTK_EXTERNAL_CHARGER_TYPE_DETECT
static bool rt8979_is_vbus_gd(struct rt8979_device_info *chip)
{
	int ret;
	u8 regval = 0;
	bool vbus_gd = false;

	ret = rt8979_i2c_read_byte(chip, RT8979_REG_MUIC_STATUS1, &regval);
	if (ret < 0)
		hwlog_info("%s fail %d\n", __func__, ret);
	else
		vbus_gd = !(regval & RT8979_REG_MUIC_STATUS1_VIN_UVLO_MASK) &&
			!(regval & RT8979_REG_MUIC_STATUS1_VIN_OVP_MASK);

	hwlog_info("%s vbus_gd = %d\n", __func__, vbus_gd);

	return vbus_gd;
}

void rt8979_set_usbsw_state(int state)
{
	hwlog_info("%s state = %d\n", __func__, state);

	if (state == RT8979_USBSW_CHG)
		charger_detect_init();
	else
		charger_detect_release();
}

static inline int rt8979_toggle_bc12(struct rt8979_device_info *chip)
{
	int ret;
	u8 regval = 0;
	u8 bc12_dis[2] = {0};
	u8 bc12_en[2] = {0};
	int retry_times = 3; /* sometimes need retry */
	struct i2c_client *client = chip->client;
	struct i2c_msg msgs[2] = {
		{
			.addr = client->addr,
			.flags = 0,
			.len = 2,
			.buf = bc12_dis,
		},
		{
			.addr = client->addr,
			.flags = 0,
			.len = 2,
			.buf = bc12_en,
		},
	};

	mutex_lock(&chip->io_lock);

	while (retry_times) {
		ret = i2c_smbus_read_i2c_block_data(client, RT8979_REG_USBCHGEN, 1, &regval);
		if (ret >= 0)
			break;
		retry_times--;
		usleep_range(50000, 51000); /* delay 50ms */
	}
	if (retry_times == 0) {
		hwlog_err("%s read reg fail %d\n", __func__, ret);
		goto out;
	}

	ret = i2c_smbus_write_byte_data(client, RT8979_REG_TEST_MODE,
		RT8979_REG_TEST_MODE_VAL1);
	if (ret < 0) {
		hwlog_err("%s enter testmode fail %d\n", __func__, ret);
		goto out;
	}

	ret = i2c_smbus_write_byte_data(client, RT8979_REG_TM_MUIC1, 0x10);
	if (ret < 0) {
		hwlog_err("%s enable manual DCD fail %d\n", __func__, ret);
		goto out;
	}

	/* bc12 disable and then enable */
	bc12_dis[0] = bc12_en[0] = RT8979_REG_USBCHGEN;
	bc12_dis[1] = regval & ~RT8979_REG_USBCHGEN_ACCPDET_STAGE1;
	bc12_en[1] = regval | RT8979_REG_USBCHGEN_ACCPDET_STAGE1;
	ret = i2c_transfer(client->adapter, msgs, 2); /* 2: msgs length */
	if (ret < 0) {
		hwlog_err("%s bc12 dis/en fail %d\n", __func__, ret);
		goto out;
	}

	usleep_range(35000, 36000); /* delay 35ms for bc12 operate */
out:
	ret = i2c_smbus_write_byte_data(client, RT8979_REG_TM_MUIC1, 0x00);
	if (ret < 0)
		hwlog_err("%s disable manual DCD fail %d\n", __func__, ret);
	ret = i2c_smbus_write_byte_data(client, RT8979_REG_TEST_MODE, 0x00);
	if (ret < 0)
		hwlog_err("%s leave testmode fail %d\n", __func__, ret);

	mutex_unlock(&chip->io_lock);
	return (ret < 0) ? ret : 0;
}

static int rt8979_bc12_en_kthread(void *data)
{
	int ret;
	int en;
	struct rt8979_device_info *chip = data;

	hwlog_info("%s\n", __func__);

	if (!chip)
		return -1;
wait:
	wait_event(chip->bc12_en_req, atomic_read(&chip->bc12_en_req_cnt) > 0 ||
		kthread_should_stop());
	if (atomic_read(&chip->bc12_en_req_cnt) <= 0 && kthread_should_stop()) {
		hwlog_info("%s bye bye\n", __func__);
		return 0;
	}
	atomic_dec(&chip->bc12_en_req_cnt);

	mutex_lock(&chip->bc12_en_lock);
	en = chip->bc12_en_buf[chip->bc12_en_buf_idx];
	chip->bc12_en_buf[chip->bc12_en_buf_idx] = -1;
	if (en == -1) {
		chip->bc12_en_buf_idx = 1 - chip->bc12_en_buf_idx;
		en = chip->bc12_en_buf[chip->bc12_en_buf_idx];
		chip->bc12_en_buf[chip->bc12_en_buf_idx] = -1;
	}
	mutex_unlock(&chip->bc12_en_lock);

	hwlog_info("%s en = %d\n", __func__, en);
	if (en == -1)
		goto wait;

	__pm_stay_awake(chip->bc12_en_ws);

	if (en)
		ret = rt8979_toggle_bc12(chip);
	else
		ret = __rt8979_enable_bc12(chip, en);
	if (ret < 0)
		hwlog_info("%s en = %d fail %d\n", __func__, en, ret);
	__pm_relax(chip->bc12_en_ws);
	goto wait;

	return 0;
}

static void rt8979_enable_bc12(struct rt8979_device_info *chip, bool en)
{
	hwlog_info("%s en = %d\n", __func__, en);

	mutex_lock(&chip->bc12_en_lock);
	chip->bc12_en_buf[chip->bc12_en_buf_idx] = en;
	chip->bc12_en_buf_idx = 1 - chip->bc12_en_buf_idx;
	mutex_unlock(&chip->bc12_en_lock);
	atomic_inc(&chip->bc12_en_req_cnt);
	wake_up(&chip->bc12_en_req);
}

static int rt8979_bc12_pre_process(struct rt8979_device_info *chip)
{
	if (atomic_read(&chip->chg_type_det))
		rt8979_enable_bc12(chip, true);

	return 0;
}

static void rt8979_inform_psy_dwork_handler(struct work_struct *work)
{
	struct rt8979_device_info *chip = container_of(work, struct rt8979_device_info, psy_dwork.work);

	rt8979_psy_online_changed(chip);
	rt8979_psy_chg_type_changed();
}

static int rt8979_bc12_post_process(struct rt8979_device_info *chip)
{
	int ret = 0;
	bool attach = false;
	bool inform_psy = true;
	u8 regval = 0;

	attach = atomic_read(&chip->chg_type_det);
	if (chip->attach == attach && !chip->sdp_retried &&
		!chip->nstd_retrying) {
		hwlog_info("%s attach %d is the same\n", __func__, attach);
		inform_psy = !attach;
		goto out;
	}
	chip->attach = attach;
	hwlog_info("%s attach = %d\n", __func__, attach);

	if (!attach)
		goto out_novbus;

	ret = rt8979_i2c_read_byte(chip, RT8979_REG_MUIC_STATUS2, &regval);
	if (ret < 0)
		goto out_novbus;
	else
		chip->us = (regval & RT8979_REG_MUIC_STATUS2_USB_STATE_MASK) >>
			RT8979_REG_MUIC_STATUS2_USB_STATE_SHIFT;

	switch (chip->us) {
	case RT8979_USB_STATUS_NOVBUS:
		goto out_novbus;
	case RT8979_USB_STATUS_UNDER_GOING:
		return 0;
	case RT8979_USB_STATUS_SDP:
		chip->chg_type = CHARGER_TYPE_USB;
		if (chip->sdp_retried < 2) {
			chip->sdp_retried++;
			rt8979_enable_bc12(chip, true);
			return 0;
		}
		break;
	case RT8979_USB_STATUS_DCP:
		chip->chg_type = CHARGER_TYPE_STANDARD;
		rt8979_dcp_accp_init();
		break;
	case RT8979_USB_STATUS_CDP:
		chip->chg_type = CHARGER_TYPE_BC_USB;
		break;
	case RT8979_USB_STATUS_SDP_NSTD:
	default:
		chip->chg_type = CHARGER_TYPE_NON_STANDARD;
		break;
	}
	ret = rt8979_i2c_read_byte(chip, RT8979_REG_MUIC_STATUS1, &regval);
	if (ret < 0)
		goto out_novbus;
	if (regval & RT8979_REG_MUIC_STATUS1_DCDT_MASK)
		chip->chg_type = CHARGER_TYPE_NON_STANDARD;
	if (chip->chg_type == CHARGER_TYPE_NON_STANDARD) {
		inform_psy = !chip->nstd_retrying;
		chip->nstd_retrying = true;
		rt8979_set_dcd_timeout(chip, 1200);
		rt8979_enable_bc12(chip, true);
		goto out_nstd_retrying;
	}
	goto out;
out_novbus:
	chip->us = RT8979_USB_STATUS_NOVBUS;
	chip->chg_type = CHARGER_REMOVED;
out:
	chip->sdp_retried = 0;
	chip->nstd_retrying = false;
	rt8979_set_dcd_timeout(chip, chip->desc->dcd_timeout);
	if (chip->chg_type != CHARGER_TYPE_STANDARD)
		rt8979_enable_bc12(chip, false); /* release usb_phy to soc */
out_nstd_retrying:
	hwlog_info("%s inform_psy=%d\n", __func__, inform_psy);
	if (inform_psy)
		schedule_delayed_work(&chip->psy_dwork, 0);

	return ret;
}
#endif /* CONFIG_MTK_EXTERNAL_CHARGER_TYPE_DETECT */

static int rt8979_enable_chg_type_det(bool en)
{
	int ret;
	struct rt8979_device_info *di = rt8979_get_dev_info();

	if (!di)
		return -EINVAL;

#ifdef CONFIG_MTK_EXTERNAL_CHARGER_TYPE_DETECT
	hwlog_info("%s en = %d\n", __func__, en);

	mutex_lock(&di->bc12_lock);
	atomic_set(&di->chg_type_det, en);
	ret = (en ? rt8979_bc12_pre_process : rt8979_bc12_post_process)(di);
	mutex_unlock(&di->bc12_lock);
	if (ret < 0)
		hwlog_info("%s en bc12 fail %d\n", __func__, ret);
#endif /* CONFIG_MTK_EXTERNAL_CHARGER_TYPE_DETECT */
	return ret;
}

static int rt8979_dump_registers(struct rt8979_device_info *chip)
{
	int ret;
	int i;
	u8 regval = 0;

	for (i = 0; i < ARRAY_SIZE(rt8979_reg_addrs); i++) {
		ret = rt8979_i2c_read_byte(chip, rt8979_reg_addrs[i], &regval);
		if (ret < 0)
			continue;
		hwlog_info("%s reg0x%02X = 0x%02X\n", __func__,
			rt8979_reg_addrs[i], regval);
	}

	return 0;
}

static int rt8979_adc_chg_irq_handler(struct rt8979_device_info *chip)
{
	hwlog_info("%s\n", __func__);
	return 0;
}

static int rt8979_reserved_attach_irq_handler(struct rt8979_device_info *chip)
{
	hwlog_info("%s\n", __func__);
	return 0;
}

static int rt8979_vbus_change_irq_handler(struct rt8979_device_info *chip)
{
	hwlog_info("%s\n", __func__);

#ifdef CONFIG_MTK_EXTERNAL_CHARGER_TYPE_DETECT
	if (!rt8979_is_vbus_gd(chip))
		return 0;

	if (!atomic_read(&chip->chg_type_det) &&
		(mt_get_charger_type() == CHARGER_TYPE_WIRELESS))
		return 0;

	mutex_lock(&chip->bc12_lock);
	rt8979_bc12_post_process(chip);
	hwlog_info("%s usb_status = %d\n", __func__, chip->us);
	mutex_unlock(&chip->bc12_lock);
#endif /* CONFIG_MTK_EXTERNAL_CHARGER_TYPE_DETECT */

	return 0;
}

static int rt8979_device_change_irq_handler(struct rt8979_device_info *chip)
{
	hwlog_info("%s\n", __func__);
	return 0;
}

static int rt8979_detach_irq_handler(struct rt8979_device_info *chip)
{
	hwlog_info("%s\n", __func__);
	return 0;
}

static int rt8979_attach_irq_handler(struct rt8979_device_info *chip)
{
	hwlog_info("%s\n", __func__);
	return 0;
}

struct irq_mapping_tbl {
	const char *name;
	int (*hdlr)(struct rt8979_device_info *chip);
	u8 num;
};

#define rt8979_irq_mapping(_name, _num) \
	{.name = #_name, .hdlr = rt8979_##_name##_irq_handler, .num = _num}

static const struct irq_mapping_tbl rt8979_irq_mapping_tbl[] = {
	rt8979_irq_mapping(adc_chg, RT8979_IRQ_ADC_CHG),
	rt8979_irq_mapping(reserved_attach, RT8979_IRQ_RSV_ATTACH),
	rt8979_irq_mapping(vbus_change, RT8979_IRQ_VBUS_CHANGE),
	rt8979_irq_mapping(device_change, RT8979_IRQ_DEV_CHANGE),
	rt8979_irq_mapping(detach, RT8979_IRQ_DETACH),
	rt8979_irq_mapping(attach, RT8979_IRQ_ATTACH),
};

static irqreturn_t rt8979_irq_handler(int irq, void *data)
{
	int ret;
	int i;
	u8 int_data = 0;
	u8 mask_data = 0;
	struct rt8979_device_info *chip = data;

	hwlog_info("%s\n", __func__);
	mutex_lock(&chip->irq_lock);
	if (!chip->resume_completed) {
		hwlog_info("%s triggered before resume completed\n", __func__);
		disable_irq_nosync(chip->irq);
		chip->irq_waiting = true;
		goto out;
	}
	chip->irq_waiting = false;

	ret = rt8979_i2c_read_byte(chip, RT8979_REG_INTERRUPT, &int_data);
	if (ret < 0)
		goto out;
	ret = rt8979_i2c_read_byte(chip, RT8979_REG_INTERRUPT_MASK, &mask_data);
	if (ret < 0)
		goto out;

	int_data &= ~mask_data;

	for (i = 0; i < ARRAY_SIZE(rt8979_irq_mapping_tbl); i++) {
		if (int_data & BIT(rt8979_irq_mapping_tbl[i].num))
			rt8979_irq_mapping_tbl[i].hdlr(chip);
	}
out:
	mutex_unlock(&chip->irq_lock);
	return IRQ_HANDLED;
}

void rt8979_deal_resume_irq(int irq, void *data)
{
	hwlog_info("%s\n", __func__);
	rt8979_irq_handler(irq, data);
	return;
}

int rt8979_reset(struct rt8979_device_info *chip)
{
	int ret;

	if (!chip)
		return -1;

	hwlog_info("%s\n", __func__);
	mutex_lock(&chip->io_lock);
	ret = __rt8979_i2c_write_byte(chip, RT8979_REG_RESET, RT8979_REG_RESET_ENTIRE_IC);
	if (ret < 0)
		goto out;
	power_usleep(DT_USLEEP_1MS);
	hwlog_info("%s delay\n", __func__);
out:
	mutex_unlock(&chip->io_lock);
	return ret;
}

static inline int rt8979_get_irq_number(struct rt8979_device_info *chip, const char *name)
{
	int i;

	if (!name) {
		hwlog_info("%s null name\n", __func__);
		return -EINVAL;
	}

	for (i = 0; i < ARRAY_SIZE(rt8979_irq_mapping_tbl); i++) {
		if (!strcmp(name, rt8979_irq_mapping_tbl[i].name))
			return rt8979_irq_mapping_tbl[i].num;
	}

	return -EINVAL;
}

static inline const char *rt8979_get_irq_name(int irqnum)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(rt8979_irq_mapping_tbl); i++) {
		if (rt8979_irq_mapping_tbl[i].num == irqnum)
			return rt8979_irq_mapping_tbl[i].name;
	}

	return "not found";
}

static inline void rt8979_irq_unmask(struct rt8979_device_info *chip, int irqnum)
{
	hwlog_info("%s irq %d, %s\n", __func__, irqnum,
		rt8979_get_irq_name(irqnum));
	chip->irq_mask &= ~BIT(irqnum);
}

static int rt8979_parse_dt(struct rt8979_device_info *chip)
{
	int ret;
	int irqcnt;
	int irqnum;
	struct device_node *np = chip->dev->of_node;
	struct rt8979_desc *desc = NULL;
	const char *name = NULL;

	hwlog_info("%s\n", __func__);

	chip->desc = &rt8979_default_desc;

	if (!np) {
		dev_notice(chip->dev, "%s no device node\n", __func__);
		return -EINVAL;
	}

	desc = devm_kmemdup(chip->dev, &rt8979_default_desc,
		sizeof(rt8979_default_desc), GFP_KERNEL);
	if (!desc)
		return -ENOMEM;
	chip->desc = desc;

	ret = of_get_named_gpio(np, "fairchild_fsa9685,gpio-intb", 0);
	if (ret < 0)
		hwlog_info("%s no rt,intr_gpio %d\n", __func__, ret);
	else
		chip->intr_gpio = ret;

	hwlog_info("%s intr_gpio = %u\n", __func__, chip->intr_gpio);

	desc->auto_switch = of_property_read_bool(np, "auto_switch");
	desc->scp = of_property_read_bool(np, "scp");
	desc->dcd = of_property_read_bool(np, "dcd");

	ret = of_property_read_u32(np, "dcd_timeout", &desc->dcd_timeout);
	if (ret < 0)
		hwlog_info("%s no dcd_timeout %d\n", __func__, ret);

	ret = of_property_read_u32(np, "intb_watchdog", &desc->intb_watchdog);
	if (ret < 0)
		hwlog_info("%s no intb_watchdog %d\n", __func__, ret);

	ret = of_property_read_u32(np, "ovp_sel", &desc->ovp_sel);
	if (ret < 0)
		hwlog_info("%s no ovp_sel %d\n", __func__, ret);

	chip->irq_mask = 0xFF;
	for (irqcnt = 0; ; irqcnt++) {
		ret = of_property_read_string_index(np, "interrupt-names", irqcnt, &name);
		if (ret < 0)
			break;
		irqnum = rt8979_get_irq_number(chip, name);
		if (irqnum >= 0)
			rt8979_irq_unmask(chip, irqnum);
	}

	return 0;
}

static int rt8979_init_setting(struct rt8979_device_info *chip)
{
	int ret;
	struct rt8979_desc *desc = chip->desc;

	hwlog_info("%s\n", __func__);
	if (!desc)
		return -1;

	ret = rt8979_enable_auto_switch(chip, desc->auto_switch);
	if (ret < 0)
		hwlog_info("%s enable auto_switch fail %d\n", __func__, ret);

	ret = rt8979_enable_scp(chip, desc->scp);
	if (ret < 0)
		hwlog_info("%s enable scp fail %d\n", __func__, ret);

	ret = rt8979_enable_dcd(chip, desc->dcd);
	if (ret < 0)
		hwlog_info("%s enable dcd fail %d\n", __func__, ret);

	ret = rt8979_set_dcd_timeout(chip, desc->dcd_timeout);
	if (ret < 0)
		hwlog_info("%s set dcd_timeout fail %d\n", __func__, ret);

	ret = rt8979_set_intb_watchdog(chip, desc->intb_watchdog);
	if (ret < 0)
		hwlog_info("%s set intb_watchdog fail %d\n", __func__, ret);

	ret = rt8979_set_ovp_sel(chip, desc->ovp_sel);
	if (ret < 0)
		hwlog_info("%s set ovp_sel fail %d\n", __func__, ret);

	ret = __rt8979_enable_bc12(chip, true);
	if (ret < 0)
		hwlog_info("%s dis bc12 fail %d\n", __func__, ret);

	return 0;
}

static int rt8979_register_irq(struct rt8979_device_info *chip)
{
	int ret;

	hwlog_info("%s\n", __func__);

	ret = devm_gpio_request_one(chip->dev, chip->intr_gpio, GPIOF_DIR_IN,
		devm_kasprintf(chip->dev, GFP_KERNEL,
		"rt8979_intr_gpio.%s", dev_name(chip->dev)));
	if (ret < 0) {
		hwlog_info("%s gpio request fail %d\n",
			__func__, ret);
		return ret;
	}
	chip->irq = gpio_to_irq(chip->intr_gpio);
	if (chip->irq < 0) {
		hwlog_info("%s gpio2irq fail %d\n",
			__func__, chip->irq);
		return chip->irq;
	}
	hwlog_info("%s irq = %d\n", __func__, chip->irq);

	/* Request threaded IRQ */
	ret = devm_request_threaded_irq(chip->dev, chip->irq, NULL,
		rt8979_irq_handler, IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
		devm_kasprintf(chip->dev, GFP_KERNEL, "rt8979_irq.%s",
		dev_name(chip->dev)), chip);
	if (ret < 0) {
		hwlog_info("%s request threaded irq fail %d\n",
			__func__, ret);
		return ret;
	}
	device_init_wakeup(chip->dev, true);
	hwlog_info("%s enable_irq_wake\n", __func__);
	enable_irq_wake(chip->irq);
	return ret;
}

int rt8979_init_irq(struct rt8979_device_info *chip)
{
	int ret;

	hwlog_info("%s\n", __func__);

	ret = rt8979_i2c_write_byte(chip, RT8979_REG_INTERRUPT_MASK,
		chip->irq_mask);
	if (ret < 0)
		return ret;
	return rt8979_clr_bit(chip, RT8979_REG_CONTROL,
		RT8979_REG_CONTROL_INT_MASK_MASK);
}

static void rt8979_mutex_init(struct rt8979_device_info *chip)
{
	mutex_init(&chip->io_lock);
#ifdef CONFIG_MTK_EXTERNAL_CHARGER_TYPE_DETECT
	mutex_init(&chip->bc12_lock);
	mutex_init(&chip->bc12_en_lock);
#endif /* CONFIG_MTK_EXTERNAL_CHARGER_TYPE_DETECT */
	mutex_init(&chip->hidden_mode_lock);
	mutex_init(&chip->irq_lock);
}

static void rt8979_mutex_destroy(struct rt8979_device_info *chip)
{
	mutex_destroy(&chip->io_lock);
#ifdef CONFIG_MTK_EXTERNAL_CHARGER_TYPE_DETECT
	mutex_destroy(&chip->bc12_lock);
	mutex_destroy(&chip->bc12_en_lock);
#endif /* CONFIG_MTK_EXTERNAL_CHARGER_TYPE_DETECT */
	mutex_destroy(&chip->hidden_mode_lock);
	mutex_destroy(&chip->irq_lock);
}

static void rt8979_info_init(struct rt8979_device_info *chip)
{
	chip->hidden_mode_cnt = 0;
#ifdef CONFIG_MTK_EXTERNAL_CHARGER_TYPE_DETECT
	INIT_DELAYED_WORK(&chip->psy_dwork, rt8979_inform_psy_dwork_handler);
	atomic_set(&chip->chg_type_det, 0);
	chip->attach = false;
	chip->us = RT8979_USB_STATUS_NOVBUS;
	chip->chg_type = CHARGER_REMOVED;
	chip->sdp_retried = 0;
#endif /* CONFIG_MTK_EXTERNAL_CHARGER_TYPE_DETECT */
	chip->resume_completed = true;
	chip->irq_waiting = false;
}

void rt8979_re_init(struct rt8979_device_info *chip)
{
	(void)rt8979_init_setting(chip);
	(void)rt8979_init_irq(chip);
}

int rt8979_init_early(struct rt8979_device_info *chip)
{
	int ret;

	if (!chip)
		return -1;

	hwlog_info("%s +\n", __func__);

	rt8979_mutex_init(chip);
	rt8979_info_init(chip);

	ret = rt8979_reset(chip);
	if (ret < 0)
		hwlog_info("%s reset fail %d\n", __func__, ret);

	ret = rt8979_parse_dt(chip);
	if (ret < 0)
		hwlog_info("%s parse dt fail %d\n", __func__, ret);

	ret = rt8979_init_setting(chip);
	if (ret < 0) {
		hwlog_info("%s init fail %d\n", __func__, ret);
		goto init_fail;
	}

	hwlog_info("%s -\n", __func__);
	return 0;

init_fail:
	rt8979_mutex_destroy(chip);
	return ret;
}

int rt8979_init_later(struct rt8979_device_info *chip)
{
	int ret;

	hwlog_info("%s +\n", __func__);

#ifdef CONFIG_MTK_EXTERNAL_CHARGER_TYPE_DETECT
	chip->bc12_en_ws = wakeup_source_register(devm_kasprintf(chip->dev,
		GFP_KERNEL, "rt8979_bc12_en_ws.%s", dev_name(chip->dev)));
	if (!(chip->bc12_en_ws)) {
		hwlog_err("%s wake source register fail\n", __func__);
		goto kthread_run_fail;
	}
	chip->bc12_en_buf[0] = chip->bc12_en_buf[1] = -1;
	chip->bc12_en_buf_idx = 0;
	atomic_set(&chip->bc12_en_req_cnt, 0);
	init_waitqueue_head(&chip->bc12_en_req);
	chip->bc12_en_kthread = kthread_run(rt8979_bc12_en_kthread, chip, "%s",
		devm_kasprintf(chip->dev, GFP_KERNEL,
		"rt8979_bc12_en_kthread.%s", dev_name(chip->dev)));
	if (IS_ERR_OR_NULL(chip->bc12_en_kthread)) {
		ret = PTR_ERR(chip->bc12_en_kthread);
		hwlog_err("%s kthread run fail %d\n", __func__, ret);
		goto kthread_run_fail;
	}
#endif /* CONFIG_MTK_EXTERNAL_CHARGER_TYPE_DETECT */

	ret = rt8979_register_irq(chip);
	if (ret < 0) {
		hwlog_err("%s register irq fail %d\n", __func__, ret);
		goto irq_fail;
	}

	ret = rt8979_init_irq(chip);
	if (ret < 0) {
		hwlog_err("%s init irq fail %d\n", __func__, ret);
		goto irq_fail;
	}

	rt8979_dump_registers(chip);
	hwlog_info("%s -\n", __func__);
	return 0;

irq_fail:
#ifdef CONFIG_MTK_EXTERNAL_CHARGER_TYPE_DETECT
	cancel_delayed_work_sync(&chip->psy_dwork);
	if (chip->ac_psy)
		power_supply_put(chip->ac_psy);

	kthread_stop(chip->bc12_en_kthread);
	wakeup_source_unregister(chip->bc12_en_ws);
kthread_run_fail:
#endif /* CONFIG_MTK_EXTERNAL_CHARGER_TYPE_DETECT */
	rt8979_mutex_destroy(chip);
	return ret;
}

static struct switch_interface_bc12_ops rt8979_bc12_ops = {
	.get_charger_type = rt8979_get_charger_type,
	.chg_type_det = rt8979_enable_chg_type_det,
	.dcd_timeout = rt8979_dcd_timeout,
	.dcd_timeout_status = rt8979_dcd_timeout_status,
};

struct switch_interface_bc12_ops *rt8979_get_bc12_ops(void)
{
	return &rt8979_bc12_ops;
}
