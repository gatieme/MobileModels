/*
 * fsa9685_accp.c
 *
 * accp with fsa9685 driver
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

#include "fsa9685_accp.h"
#include <linux/delay.h>
#include <linux/of_gpio.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_power_supply.h>
#ifdef CONFIG_BOOST_5V
#include <chipset_common/hwpower/hardware_ic/boost_5v.h>
#endif /* CONFIG_BOOST_5V */
#include <huawei_platform/usb/switch/fsa9685.h>
#include <huawei_platform/usb/switch/switch_chip_common.h>
#include "fsa9685_reg.h"
#include "switch_chip_i2c.h"

#define HWLOG_TAG fsa9685_accp
HWLOG_REGIST();

void fsa9685_disable_accp_intr(struct fsa9685_device_info *di)
{
	int ret = 0;
	int reg_ctl;

	if (fsa9685_is_support_fcp(di))
		return;

	/* if support fcp, disable accp interrupt */
	ret += switch_write_reg_mask(di->client, FSA9685_REG_CONTROL2, 0,
		FSA9685_ACCP_OSC_ENABLE);
	ret += switch_write_reg(di->client, FSA9685_REG_ACCP_INTERRUPT_MASK1, 0xFF);
	ret += switch_write_reg(di->client, FSA9685_REG_ACCP_INTERRUPT_MASK2, 0xFF);
	if (ret < 0)
		hwlog_err("accp interrupt mask write failed\n");

	reg_ctl = switch_read_reg(di->client, FSA9685_REG_DEVICE_TYPE_1);
	hwlog_info("DEV_TYPE1 = 0x%x\n", reg_ctl);
}

static inline void fsa9685_accp_sleep(void)
{
	/* sleep ACCP_POLL_TIME ms */
	usleep_range(ACCP_POLL_TIME * 1000, (ACCP_POLL_TIME + 1) * 1000);
}

static void fsa9685_accp_adaptor_reg_lock(struct fsa9685_device_info *di)
{
	mutex_lock(&di->accp_adaptor_reg_lock);
	hwlog_info("accp_adaptor_reg_lock lock\n");
}

static void fsa9685_accp_adaptor_reg_unlock(struct fsa9685_device_info *di)
{
	mutex_unlock(&di->accp_adaptor_reg_lock);
	hwlog_info("accp_adaptor_reg_lock unlock\n");
}

static void fsa9685_accp_detect_lock(struct fsa9685_device_info *di)
{
	mutex_lock(&di->accp_detect_lock);
	hwlog_info("accp_detect_lock lock\n");
}

static void fsa9685_accp_detect_unlock(struct fsa9685_device_info *di)
{
	mutex_unlock(&di->accp_detect_lock);
	hwlog_info("accp_detect_lock unlock\n");
}

static int fsa9685_accp_cmd_transfer_check(struct fsa9685_device_info *di)
{
	int reg_val1;
	int reg_val2;
	int i = 0;

	/* read accp interrupt registers until value is not zero */
	do {
		usleep_range(30000, 31000); /* 30000, 31000: sleep 30ms */
		reg_val1 = switch_read_reg(di->client, FSA9685_REG_ACCP_INTERRUPT1);
		reg_val2 = switch_read_reg(di->client, FSA9685_REG_ACCP_INTERRUPT2);
		i++;
	} while ((i < MUIC_ACCP_INT_MAX_COUNT) && (reg_val1 == 0) && (reg_val2 == 0));

	if ((reg_val1 < 0) || (reg_val2 < 0)) {
		hwlog_err("read error reg_val1=%d,reg_val2=%d\n", reg_val1, reg_val2);
		return -1;
	}

	/* if something changed print reg info */
	if (reg_val2 & (FAS9685_PROSTAT | FAS9685_DSDVCSTAT))
		hwlog_info("ACCP state changed,reg 0x59=0x%x,reg 0x5A=0x%x\n",
			reg_val1, reg_val2);

	/* judge if cmd transfer success */
	if ((reg_val1 & FAS9685_ACK) && (reg_val1 & FAS9685_CMDCPL) &&
		!(reg_val1 & FAS9685_CRCPAR) &&
		!(reg_val2 & (FAS9685_CRCRX | FAS9685_PARRX)))
		return 0;

	hwlog_err("reg 0x59=0x%x,reg 0x5A=0x%x\n", reg_val1, reg_val2);
	return -1;
}

static void fsa9685_accp_protocol_restart(struct fsa9685_device_info *di)
{
	int reg_val;
	int ret = 0;
	int slave_good, accp_status_mask;

	slave_good = FSA9688_ACCP_STATUS_SLAVE_GOOD;
	accp_status_mask = FSA9688_ACCP_STATUS_MASK;

	/* disable accp protocol */
	switch_write_reg_mask(di->client, FSA9685_REG_ACCP_CNTL, 0,
		FAS9685_ACCP_CNTL_MASK);
	usleep_range(100000, 101000); /* 100000, 101000: sleep 100ms */
	reg_val = switch_read_reg(di->client, FSA9685_REG_ACCP_STATUS);
	if (slave_good == (reg_val & accp_status_mask))
		hwlog_err("disable accp enable bit failed ,accp status [0x40]=0x%x\n",
			reg_val);

	/* enable accp protocol */
	switch_write_reg_mask(di->client, FSA9685_REG_ACCP_CNTL, FSA9685_ACCP_IS_ENABLE,
		FAS9685_ACCP_CNTL_MASK);
	usleep_range(100000, 101000); /* 100000, 101000: sleep 100ms */
	reg_val = switch_read_reg(di->client, FSA9685_REG_ACCP_STATUS);
	if (slave_good != (reg_val & accp_status_mask))
		hwlog_err("enable accp enable bit failed, accp status [0x40]=0x%x\n",
			reg_val);

	/* disable accp interrupt */
	ret |= switch_write_reg_mask(di->client, FSA9685_REG_CONTROL2,
		FSA9685_ACCP_OSC_ENABLE, FSA9685_ACCP_OSC_ENABLE);
	ret += switch_write_reg(di->client, FSA9685_REG_ACCP_INTERRUPT_MASK1, 0xFF);
	ret += switch_write_reg(di->client, FSA9685_REG_ACCP_INTERRUPT_MASK2, 0xFF);
	if (ret < 0)
		hwlog_err("accp interrupt mask write failed\n");

	hwlog_info("disable and enable accp protocol accp status  is 0x%x\n", reg_val);
}

static int fsa9685_check_accp_ic_status(struct fsa9685_device_info *di)
{
	int check_times;
	int reg_dev_type1;
#ifdef CONFIG_BOOST_5V
	int ret;

	if (di->power_by_5v) {
		ret = boost_5v_enable(ENABLE, BOOST_CTRL_FCP);
		ret |= dc_set_bst_ctrl(ENABLE);
		if (ret) {
			hwlog_err("5v boost open fail!\n");
			return ACCP_NOT_PREPARE_OK;
		}
		hwlog_info("5v boost open!\n");
	}
#endif /* CONFIG_BOOST_5V */

	for (check_times = 0; check_times < ADAPTOR_BC12_TYPE_MAX_CHECK_TIME;
		check_times++) {
		reg_dev_type1 = switch_read_reg(di->client, FSA9685_REG_DEVICE_TYPE_1);
		if (reg_dev_type1 >= 0) {
			if (reg_dev_type1 & FSA9685_DCP_DETECTED) {
				hwlog_info("FSA9685_DCP_DETECTED\n");
				break;
			}
		}
		hwlog_info("reg_dev_type1 = 0x%x,check_times = %d!\n", reg_dev_type1,
			check_times);
		/* 1000: sleep WAIT_FOR_BC12_DELAY * 1000 ms */
		usleep_range(WAIT_FOR_BC12_DELAY * 1000, (WAIT_FOR_BC12_DELAY + 1) * 1000);
	}
	hwlog_info("accp is ok, check_times = %d!\n", check_times);

#ifdef CONFIG_BOOST_5V
	if (check_times >= ADAPTOR_BC12_TYPE_MAX_CHECK_TIME) {
		if (di->power_by_5v) {
			boost_5v_enable(DISABLE, BOOST_CTRL_FCP);
			dc_set_bst_ctrl(DISABLE);
		}
	}
#endif /* CONFIG_BOOST_5V */

	return ACCP_PREPARE_OK;
}

static int fsa9685_accp_adapter_reg_read(int* val, int reg)
{
	int reg_val1;
	int reg_val2;
	int i;
	int ret = 0;
	int accp_check_ret;
	struct fsa9685_device_info *di = fsa9685_get_dev_info();

	if (!di)
		return -EINVAL;

	fsa9685_accp_adaptor_reg_lock(di);
	for (i = 0; (i < ACCP_RETRY_MAX_TIMES); i++) {
		/* before send cmd, read and clear accp interrupt registers */
		reg_val1 = switch_read_reg(di->client, FSA9685_REG_ACCP_INTERRUPT1);
		reg_val2 = switch_read_reg(di->client, FSA9685_REG_ACCP_INTERRUPT2);
		ret += switch_write_reg(di->client, FSA9685_REG_ACCP_CMD,
			FSA9685_ACCP_CMD_SBRRD);
		ret += switch_write_reg(di->client, FSA9685_REG_ACCP_ADDR, reg);
		ret |= switch_write_reg_mask(di->client, FSA9685_REG_ACCP_CNTL,
			FSA9685_ACCP_IS_ENABLE | FAS9685_ACCP_SENDCMD, FAS9685_ACCP_CNTL_MASK);
		if (ret) {
			hwlog_err("write error ret is %d \n", ret);
			fsa9685_accp_adaptor_reg_unlock(di);
			return -1;
		}

		/* check cmd transfer success or fail */
		accp_check_ret = fsa9685_accp_cmd_transfer_check(di);
		if (accp_check_ret == 0) {
			/* recived data from adapter */
			*val = switch_read_reg(di->client, FSA9685_REG_ACCP_DATA);
			break;
		}
		/* if transfer failed, restart accp protocol */
		fsa9685_accp_protocol_restart(di);
		hwlog_err("adapter register read fail times=%d, register=0x%x, data=0x%x,"
			"reg[0x59]=0x%x, reg[0x5A]=0x%x\n", i, reg, *val, reg_val1, reg_val2);
	}

	hwlog_debug("adapter register retry times=%d, register=0x%x, data=0x%x,"
		"reg[0x59]=0x%x, reg[0x5A]=0x%x\n", i, reg, *val, reg_val1, reg_val2);
	if (i == ACCP_RETRY_MAX_TIMES) {
		hwlog_err("ack error,retry %d times", i);
		ret = -1;
	} else {
		ret = 0;
	}
	fsa9685_accp_adaptor_reg_unlock(di);
	return ret;
}

static int fsa9685_accp_adapter_reg_write(int val, int reg)
{
	int reg_val1;
	int reg_val2;
	int i;
	int ret = 0;
	int accp_check_ret;
	struct fsa9685_device_info *di = fsa9685_get_dev_info();

	if (!di)
		return -EINVAL;

	fsa9685_accp_adaptor_reg_lock(di);
	for (i = 0; (i < ACCP_RETRY_MAX_TIMES); i++) {
		/* before send cmd, clear accp interrupt registers */
		reg_val1 = switch_read_reg(di->client, FSA9685_REG_ACCP_INTERRUPT1);
		reg_val2 = switch_read_reg(di->client, FSA9685_REG_ACCP_INTERRUPT2);
		ret |= switch_write_reg(di->client, FSA9685_REG_ACCP_CMD, FSA9685_ACCP_CMD_SBRWR);
		ret |= switch_write_reg(di->client, FSA9685_REG_ACCP_ADDR, reg);
		ret |= switch_write_reg(di->client, FSA9685_REG_ACCP_DATA, val);
		ret |= switch_write_reg_mask(di->client, FSA9685_REG_ACCP_CNTL,
			FSA9685_ACCP_IS_ENABLE | FAS9685_ACCP_SENDCMD, FAS9685_ACCP_CNTL_MASK);
		if (ret < 0) {
			hwlog_err("write error ret is %d \n", ret);
			fsa9685_accp_adaptor_reg_unlock(di);
			return -1;
		}

		/* check cmd transfer success or fail */
		accp_check_ret = fsa9685_accp_cmd_transfer_check(di);
		if (accp_check_ret == 0) {
			break;
		}
		/* if transfer failed, restart accp protocol */
		fsa9685_accp_protocol_restart(di);
		hwlog_err("adapter register write fail times=%d, register=0x%x, data=0x%x,"
			"reg[0x59]=0x%x, reg[0x5A]=0x%x \n", i, reg, val, reg_val1, reg_val2);
	}
	hwlog_debug("adapter register retry times=%d, register=0x%x, data=0x%x,"
		"reg[0x59]=0x%x, reg[0x5A]=0x%x\n", i, reg, val, reg_val1, reg_val2);
	if (i == ACCP_RETRY_MAX_TIMES) {
		hwlog_err("ack error,retry %d times \n", i);
		ret = -1;
	} else {
		ret = 0;
	}
	fsa9685_accp_adaptor_reg_unlock(di);
	return ret;
}

static int fsa9865_accp_adapter_detect(void *dev_data)
{
	int reg_val1;
	int reg_val2;
	int i;
	int slave_good;
	int accp_status_mask;
	struct fsa9685_device_info *di = fsa9685_get_dev_info();

	if (!di || !di->client)
		return ACCP_ADAPTOR_DETECT_OTHER;

	slave_good = FSA9688_ACCP_STATUS_SLAVE_GOOD;
	accp_status_mask = FSA9688_ACCP_STATUS_MASK;

	if (fsa9685_check_accp_ic_status(di) == ACCP_NOT_PREPARE_OK) {
		hwlog_err("check_accp_ic_status not prepare ok\n");
		return ACCP_ADAPTOR_DETECT_OTHER;
	}
	fsa9685_accp_detect_lock(di);
	/* check accp status */
	reg_val1 = switch_read_reg(di->client, FSA9685_REG_DEVICE_TYPE_4);
	reg_val2 = switch_read_reg(di->client, FSA9685_REG_ACCP_STATUS);
	if ((reg_val1 & FSA9685_ACCP_CHARGER_DET) &&
		(slave_good == (reg_val2 & accp_status_mask))) {
		hwlog_info("accp adapter detect ok\n");
		fsa9685_accp_detect_unlock(di);
		return ACCP_ADAPTOR_DETECT_SUCC;
	}

	/* enable accp */
	reg_val1 = switch_read_reg(di->client, FSA9685_REG_CONTROL2);
	reg_val1 |= FSA9685_ACCP_ENABLE;
	switch_write_reg(di->client, FSA9685_REG_CONTROL2, reg_val1);

	hwlog_info("accp_adapter_detect 0x0e=0x%x\n", reg_val1);

	/* detect accp charger */
	for (i = 0; i < ACCP_DETECT_MAX_COUT; i++) {
		reg_val1 = switch_read_reg(di->client, FSA9685_REG_DEVICE_TYPE_4);
		reg_val2 = switch_read_reg(di->client, FSA9685_REG_ACCP_STATUS);
		if ((reg_val1 & FSA9685_ACCP_CHARGER_DET) &&
			(slave_good == (reg_val2 & accp_status_mask)))
			break;
		fsa9685_accp_sleep();
	}
	/* clear accp interrupt */
	hwlog_info("read accp interrupt reg 0x59=0x%x,reg 0x5A =0x%x\n",
		switch_read_reg(di->client, FSA9685_REG_ACCP_INTERRUPT1),
		switch_read_reg(di->client, FSA9685_REG_ACCP_INTERRUPT2));
	if (i == ACCP_DETECT_MAX_COUT) {
		fsa9685_accp_detect_unlock(di);
		hwlog_info("not accp adapter reg 0x0f=0x%x reg 0x40=0x%x\n",
			reg_val1, reg_val2);
		if (reg_val1 & FSA9685_ACCP_CHARGER_DET)
			return ACCP_ADAPTOR_DETECT_FAIL;

		return ACCP_ADAPTOR_DETECT_OTHER; /* not fcp adapter */
	}
	hwlog_info("accp adapter detect ok take %d ms\n", i * ACCP_POLL_TIME);
	fsa9685_accp_detect_unlock(di);
	return ACCP_ADAPTOR_DETECT_SUCC;
}

static int fsa9685_adapter_reset(void *dev_data)
{
	int ret;
	int val;
	struct fsa9685_device_info *di = fsa9685_get_dev_info();

	if (!di)
		return -EINVAL;

	val = FSA9685_ACCP_MSTR_RST | FAS9685_ACCP_SENDCMD |
		FSA9685_ACCP_IS_ENABLE;
	ret = switch_write_reg_mask(di->client, FSA9685_REG_ACCP_CNTL, val,
		FAS9685_ACCP_CNTL_MASK);
	hwlog_info("send accp adapter reset %s\n", (ret < 0) ? "fail" : "sucess");
	return ret;
}

static int fsa9685_chip_reset(void *dev_data)
{
	int ret, reg_ctl, gpio_value;
	struct fsa9685_device_info *di = fsa9685_get_dev_info();

	if (!di || !di->client)
		return -1;

	hwlog_info("%s++", __func__);

	ret = switch_write_reg(di->client, 0x19, 0x89);
	if (ret < 0)
		hwlog_err("reset fsa9688 failed \n");

	ret = switch_write_reg(di->client, FSA9685_REG_DETACH_CONTROL, 1);
	if (ret < 0)
		hwlog_err("write FSA9685_REG_DETACH_CONTROL error!!! ret=%d", ret);

	/* disable accp interrupt */
	ret |= switch_write_reg_mask(di->client, FSA9685_REG_CONTROL2,
		FSA9685_ACCP_OSC_ENABLE, FSA9685_ACCP_OSC_ENABLE);
	ret |= switch_write_reg_mask(di->client, FSA9685_REG_CONTROL2,
		di->dcd_timeout_force_enable, FSA9685_DCD_TIME_OUT_MASK);
	ret += switch_write_reg(di->client, FSA9685_REG_ACCP_INTERRUPT_MASK1, 0xFF);
	ret += switch_write_reg(di->client, FSA9685_REG_ACCP_INTERRUPT_MASK2, 0xFF);
	if (ret < 0)
		hwlog_err("accp interrupt mask write failed \n");

	/* clear INT MASK */
	reg_ctl = switch_read_reg(di->client, FSA9685_REG_CONTROL);
	if (reg_ctl < 0) {
		hwlog_err("read FSA9685_REG_CONTROL error!!! reg_ctl=%d.\n", reg_ctl);
		return -1;
	}
	hwlog_info("read FSA9685_REG_CONTROL. reg_ctl=0x%x.\n", reg_ctl);

	reg_ctl &= (~FSA9685_INT_MASK);
	ret = switch_write_reg(di->client, FSA9685_REG_CONTROL, reg_ctl);
	if (ret < 0) {
		hwlog_err("write FSA9685_REG_CONTROL error!!! reg_ctl=%d.\n",
			reg_ctl);
		return -1;
	}
	hwlog_info("write FSA9685_REG_CONTROL. reg_ctl=0x%x.\n", reg_ctl);

	ret = switch_write_reg(di->client, FSA9685_REG_DCD, FSA9685_REG_DCD_STATUS_INIT_VAL);
	if (ret < 0) {
		hwlog_err("write FSA9685_REG_DCD error!!! reg_DCD=0x%x.\n", 0x08);
		return -1;
	}
	hwlog_info("write FSA9685_REG_DCD. reg_DCD=0x%x.\n", FSA9685_REG_DCD_STATUS_INIT_VAL);
	gpio_value = gpio_get_value(fsa9685_get_gpio());
	hwlog_info("intb=%d after clear MASK.\n", gpio_value);
	if (gpio_value == 0)
		schedule_work(&di->intb_work);

	hwlog_info("%s--", __func__);
	return 0;
}

static int fsa9685_accp_read_master_status(void *dev_data)
{
	int reg_val;
	int slave_good;
	int accp_status_mask;
	struct fsa9685_device_info *di = fsa9685_get_dev_info();

	if (!di)
		return -EINVAL;

	slave_good = FSA9688_ACCP_STATUS_SLAVE_GOOD;
	accp_status_mask = FSA9688_ACCP_STATUS_MASK;
	reg_val = switch_read_reg(di->client, FSA9685_REG_ACCP_STATUS);
	if (reg_val < 0) {
		hwlog_err("reg_val fail\n");
		return -1;
	}

	if ((slave_good != (reg_val & accp_status_mask)))
		return -1;

	return 0;
}

int fsa9685_is_accp_charger_type(void *dev_data)
{
	int reg_val;
	struct fsa9685_device_info *di = fsa9685_get_dev_info();

	if (!di)
		return 0;

	if (fsa9685_is_support_fcp(di))
		return 0;

	reg_val = switch_read_reg(di->client, FSA9685_REG_DEVICE_TYPE_4);
	if (reg_val < 0) {
		hwlog_err("read FSA9685_REG_DEVICE_TYPE_4 error\n");
		return 0;
	}
	if (reg_val & FSA9685_ACCP_CHARGER_DET)
		return 1;

	return 0;
}

static struct switch_interface_charger_ops fsa9685_accp_ops = {
	.accp_adapter_reg_read = fsa9685_accp_adapter_reg_read,
	.accp_adapter_reg_write = fsa9685_accp_adapter_reg_write,
	.accp_adapter_detect = fsa9865_accp_adapter_detect,
	.accp_adapter_reset = fsa9685_adapter_reset,
	.accp_chip_reset = fsa9685_chip_reset,
	.accp_read_master_status = fsa9685_accp_read_master_status,
	.is_accp_charger_type = fsa9685_is_accp_charger_type,
};

struct switch_interface_charger_ops *fas9685_get_accp_ops(void)
{
	return &fsa9685_accp_ops;
}
