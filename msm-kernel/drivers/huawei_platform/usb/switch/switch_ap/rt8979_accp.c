/*
 * rt8979_accp.c
 *
 * accp with rt8979 driver
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

#include "rt8979_accp.h"
#include <linux/delay.h>
#include <linux/of_gpio.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_power_supply.h>
#ifdef CONFIG_BOOST_5V
#include <chipset_common/hwpower/hardware_ic/boost_5v.h>
#endif /* CONFIG_BOOST_5V */
#include <huawei_platform/usb/switch/switch_chip_common.h>
#include "rt8979.h"
#include "rt8979_reg.h"
#include "rt8979_bc12.h"
#include "rt8979_osc.h"
#include "usbswitch_rt8979.h"
#include "switch_chip_i2c.h"

#define HWLOG_TAG rt8979_accp
HWLOG_REGIST();

int rt8979_sw_open(bool open)
{
	struct rt8979_device_info *di = rt8979_get_dev_info();

	if (!di)
		return -EINVAL;

	hwlog_info("%s : %s\n", __func__, open ? "open" : "auto");
	return switch_write_reg_mask(di->client, RT8979_REG_CONTROL,
		open ? 0 : RT8979_REG_CONTROL_SW_OPEN_MASK, RT8979_REG_CONTROL_SW_OPEN_MASK);
}

void rt8979_disable_accp_intr(struct rt8979_device_info *di)
{
	int ret = 0;
	int reg_ctl;

	if (rt8979_is_support_fcp(di))
		return;

	/* if support fcp, disable accp interrupt */
	ret += switch_write_reg_mask(di->client, RT8979_REG_CONTROL2, 0,
		RT8979_REG_CONTROL2_ACCP_OSC_EN_MASK);
	ret += switch_write_reg(di->client, RT8979_REG_ACCP_INTERRUPT_MASK1, RT8979_REG_ALLMASK);
	ret += switch_write_reg(di->client, RT8979_REG_ACCP_INTERRUPT_MASK2, RT8979_REG_ALLMASK);
	if (ret < 0)
		hwlog_err("accp interrupt mask write failed\n");

	reg_ctl = switch_read_reg(di->client, RT8979_REG_DEVICE_TYPE_1);
	hwlog_info("DEV_TYPE1 = 0x%x\n", reg_ctl);

	switch_write_reg(di->client, RT8979_REG_EXT3, RT8979_REG_EXT3_VAL);
	switch_write_reg(di->client, RT8979_REG_MUIC_CTRL_3,
		RT8979_REG_MUIC_CTRL_3_DISABLEID_FUNCTION);
	reg_ctl = switch_read_reg(di->client, RT8979_REG_DEVICE_TYPE_1);
	hwlog_info("DEV_TYPE1 = 0x%x\n", reg_ctl);
	reg_ctl = switch_read_reg(di->client, RT8979_REG_DEVICE_TYPE_4);
	hwlog_info("DEV_TYPE4 = 0x%x\n", reg_ctl);
}

void rt8979_dcp_accp_init(void)
{
	struct rt8979_device_info *di = rt8979_get_dev_info();

	if (!di)
		return;

	/* should clear accp reg */
	switch_write_reg(di->client, RT8979_REG_ACCP_CMD, RT8979_ACCP_CMD_SBRWR);
	switch_write_reg(di->client, RT8979_REG_ACCP_ADDR, RT8979_REG_ACCP_ADDR_VAL1);
	rt8979_set_osc_trim_adjust(rt8979_get_osc_trim_default());
	rt8979_adjust_osc(0);
}

int rt8979_accp_enable(struct rt8979_device_info *di, bool en)
{
	return switch_write_reg_mask(di->client, RT8979_REG_CONTROL2, en ?
		RT8979_REG_CONTROL2_ACCP_AUTO_EN_MASK : 0,
		RT8979_REG_CONTROL2_ACCP_AUTO_EN_MASK);
}

static inline void rt8979_accp_sleep(void)
{
	/* sleep ACCP_POLL_TIME ms */
	usleep_range(ACCP_POLL_TIME * 1000, (ACCP_POLL_TIME + 1) * 1000);
}

static void rt8979_accp_adaptor_reg_lock(struct rt8979_device_info *di)
{
	mutex_lock(&di->accp_adaptor_reg_lock);
	hwlog_info("accp_adaptor_reg_lock lock\n");
}

static void rt8979_accp_adaptor_reg_unlock(struct rt8979_device_info *di)
{
	mutex_unlock(&di->accp_adaptor_reg_lock);
	hwlog_info("accp_adaptor_reg_lock unlock\n");
}

static void rt8979_accp_detect_lock(struct rt8979_device_info *di)
{
	mutex_lock(&di->accp_detect_lock);
	hwlog_info("accp_detect_lock lock\n");
}

static void rt8979_accp_detect_unlock(struct rt8979_device_info *di)
{
	mutex_unlock(&di->accp_detect_lock);
	hwlog_info("accp_detect_lock unlock\n");
}

static void rt8979_regs_dump(void)
{
	const int reg_addr[] = {
		RT8979_REG_CONTROL,
		RT8979_REG_MUIC_EXT1,
		RT8979_REG_MUIC_STATUS1,
		RT8979_REG_MUIC_STATUS2,
		RT8979_REG_ACCP_STATUS,
		RT8979_REG_EXT3,
		RT8979_REG_USBCHGEN,
		RT8979_REG_MUIC_EXT2,
		RT8979_REG_CONTROL2,
		RT8979_REG_DEVICE_TYPE_1,
		RT8979_REG_DEVICE_TYPE_2,
		RT8979_REG_DEVICE_TYPE_3,
		RT8979_REG_DEVICE_TYPE_4,
	};
	int regval;
	int i;
	struct rt8979_device_info *di = rt8979_get_dev_info();

	if (!di)
		return;

	for (i = 0; i < ARRAY_SIZE(reg_addr); i++) {
		regval = switch_read_reg(di->client, reg_addr[i]);
		hwlog_info("reg[0x%02x] = 0x%02x\n", reg_addr[i], regval);
	}
}

static int rt8979_accp_cmd_transfer_check(struct rt8979_device_info *di)
{
	const int wait_time = RT8979_ACCP_DM_TRANSFER_CHECK_WAIT_TIME;
	int reg_val1;
	int reg_val2;
	int i = -1;
	int scp_status;
	/* read accp interrupt registers until value is not zero */

	scp_status = switch_read_reg(di->client, RT8979_REG_ACCP_STATUS);
	if (scp_status == 0)
		return -1;
	do {
		usleep_range(30000, 31000); /* 30000, 31000: sleep 30ms */
		reg_val1 = switch_read_reg(di->client, RT8979_REG_ACCP_INTERRUPT1);
		reg_val2 = switch_read_reg(di->client, RT8979_REG_ACCP_INTERRUPT2);
		i++;
	} while ((i < MUIC_ACCP_INT_MAX_COUNT) && (reg_val1 == 0) && (reg_val2 == 0));

	if ((reg_val1 == 0) && (reg_val2 == 0))
		hwlog_info("read accp interrupt time out,total time is %d ms\n", wait_time);

	if ((reg_val1 < 0) || (reg_val2 < 0)) {
		hwlog_err("read  error!!! reg_val1=%d,reg_val2=%d \n", reg_val1, reg_val2);
		return -1;
	}

	/* if something  changed print reg info */
	if (reg_val2 & (RT8979_REG_ACCP_INTERRUPT2_PROSTAT_MASK |
		RT8979_REG_ACCP_INTERRUPT2_DSDVCSTAT_MASK))
		hwlog_info("ACCP state changed  ,reg[0x59]=0x%x,reg[0x5A]=0x%x\n",
			reg_val1, reg_val2);

	if (reg_val2 == 0) {
		if (reg_val1 == RT8979_REG_ACCP_INTERRUPT1_CMDCPL_MASK) {
			/* increase OSC */
			hwlog_info("increase OSC\n");
			if (rt8979_adjust_osc(-1) == 0)
				return -RT8979_RETRY;
		} else if (reg_val1 == (RT8979_REG_ACCP_INTERRUPT1_CMDCPL_MASK |
			RT8979_REG_ACCP_INTERRUPT1_CRCPAR_MASK)) {
			/* decrease OSC */
			hwlog_info("decrease OSC\n");
			if (rt8979_adjust_osc(1) == 0)
				return -RT8979_RETRY;
		} else if (reg_val1 == (RT8979_REG_ACCP_INTERRUPT1_CMDCPL_MASK |
			RT8979_REG_ACCP_INTERRUPT1_ACK_MASK |
			RT8979_REG_ACCP_INTERRUPT1_CRCPAR_MASK)) {
			hwlog_info("decrease OSC\n");
			if (rt8979_adjust_osc(1) == 0)
				return -RT8979_FAIL;
		}
	}

	if ((reg_val1 & RT8979_REG_ACCP_INTERRUPT1_CMDCPL_MASK) &&
		(reg_val1 & RT8979_REG_ACCP_INTERRUPT1_ACK_MASK) &&
		!(reg_val1 & RT8979_REG_ACCP_INTERRUPT1_CRCPAR_MASK) &&
		!(reg_val2 & (RT8979_REG_ACCP_INTERRUPT2_CRCRX_MASK |
		RT8979_REG_ACCP_INTERRUPT2_PAPRX_MASK)))
		return 0;

	hwlog_err("reg[0x59]=0x%x,reg[0x5A]=0x%x\n", reg_val1, reg_val2);
	return -1;
}

static void rt8979_accp_protocol_restart(struct rt8979_device_info *di)
{
	int slave_good, accp_status_mask;

	slave_good = RT8979_ACCP_STATUS_SLAVE_GOOD;
	accp_status_mask =  RT8979_ACCP_STATUS_MASK;
	rt8979_sw_open(true);
	rt8979_regs_dump();
	/* RT8979 didn't support accp_protocol_restart */
	return;
}

static int rt8979_check_accp_ic_status(void)
{
	struct rt8979_device_info *di = rt8979_get_dev_info();
	int check_times;
	int reg_dev_type1;
#ifdef CONFIG_BOOST_5V
	int ret;

	if (!di)
		return ACCP_NOT_PREPARE_OK;

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

	if (!di)
		return ACCP_NOT_PREPARE_OK;

	for (check_times = 0; check_times < ADAPTOR_BC12_TYPE_MAX_CHECK_TIME;
		check_times++) {
		reg_dev_type1 = switch_read_reg(di->client, RT8979_REG_DEVICE_TYPE_1);
		if (reg_dev_type1 >= 0) {
			if (reg_dev_type1 & RT8979_REG_DEVICE_TYPE_1_DCP_MASK) {
				hwlog_info("FSA9685_DCP_DETECTED\n");
				break;
			}
		}
		hwlog_info("reg_dev_type1 = 0x%x,check_times = %d!\n", reg_dev_type1,
			check_times);
		/* 1000: sleep WAIT_FOR_BC12_DELAY * 1000 ms */
		usleep_range(WAIT_FOR_BC12_DELAY * 1000, (WAIT_FOR_BC12_DELAY + 1) * 1000);
	}
	hwlog_info("accp is ok,check_times = %d!\n", check_times);

#ifdef CONFIG_BOOST_5V
	if (check_times >= ADAPTOR_BC12_TYPE_MAX_CHECK_TIME) {
		if (!di)
			return ACCP_PREPARE_OK;

		if (di->power_by_5v) {
			boost_5v_enable(DISABLE, BOOST_CTRL_FCP);
			dc_set_bst_ctrl(DISABLE);
		}
	}
#endif /* CONFIG_BOOST_5V */

	return ACCP_PREPARE_OK;
}

static void rt8979_auto_restart_accp_det(void)
{
	int ret;
	struct rt8979_device_info *di = rt8979_get_dev_info();

	if (!di)
		return;

	hwlog_info("%s-%d +++\n", __func__, __LINE__);

	ret = switch_read_reg(di->client, RT8979_REG_CONTROL2);
	if (ret < 0) {
		hwlog_err("switch_read_reg fail\n");
		return;
	}

	if ((ret & RT8979_REG_CONTROL2_ACCP_AUTO_EN_MASK) == 0) {
		hwlog_info("do restart accp det\n");
		rt8979_sw_open(true);
		rt8979_accp_enable(di, true);
		msleep(30); /* 30: sleep 30ms */
		switch_write_reg_mask(di->client, RT8979_REG_USBCHGEN, 0,
			RT8979_REG_USBCHGEN_ACCPDET_STAGE1);
		switch_write_reg_mask(di->client, RT8979_REG_CONTROL2, 0,
			RT8979_REG_CONTROL2_DCD_TIMEOUT_EN_MASK);
		switch_write_reg_mask(di->client, RT8979_REG_USBCHGEN,
			RT8979_REG_USBCHGEN_ACCPDET_STAGE1,
			RT8979_REG_USBCHGEN_ACCPDET_STAGE1);
		msleep(300); /* 300: sleep 300ms */
		rt8979_sw_open(false);
		switch_write_reg_mask(di->client, RT8979_REG_CONTROL2,
			RT8979_REG_CONTROL2_DCD_TIMEOUT_EN_MASK,
			RT8979_REG_CONTROL2_DCD_TIMEOUT_EN_MASK);
	}
}

static void rt8979_force_restart_accp_det(bool open)
{
	struct rt8979_device_info *di = rt8979_get_dev_info();
	int ret;

	if (!di)
		return;

	ret = rt8979_sw_open(true);
	if (ret < 0)
		hwlog_err("rt8979_sw_open fail\n");

	ret = rt8979_accp_enable(di, true);
	if (ret < 0)
		hwlog_err("rt8979_accp_enable fail\n");

	usleep_range(950, 1050); /* 950, 1050: sleep range from 950ms to 1050ms */
	switch_write_reg_mask(di->client, RT8979_REG_USBCHGEN, 0,
		RT8979_REG_USBCHGEN_ACCPDET_STAGE1);
	switch_write_reg_mask(di->client, RT8979_REG_CONTROL2, 0,
		RT8979_REG_CONTROL2_DCD_TIMEOUT_EN_MASK);
	switch_write_reg_mask(di->client, RT8979_REG_USBCHGEN,
		RT8979_REG_USBCHGEN_ACCPDET_STAGE1,
		RT8979_REG_USBCHGEN_ACCPDET_STAGE1);
	msleep(300); /* 300: sleep 300 ms */
	ret = rt8979_sw_open(open);
	if (ret < 0)
		hwlog_err("rt8979_sw_open fail\n");

	switch_write_reg_mask(di->client, RT8979_REG_CONTROL2,
		RT8979_REG_CONTROL2_DCD_TIMEOUT_EN_MASK,
		RT8979_REG_CONTROL2_DCD_TIMEOUT_EN_MASK);
}

static int rt8979_accp_adapter_reg_read(int* val, int reg)
{
	int reg_val1;
	int reg_val2;
	int i;
	int ret = 0;
	int adjust_osc_count = 0;
	int accp_check_ret;
	struct rt8979_device_info *di = rt8979_get_dev_info();

	if (!di)
		return -EINVAL;

	rt8979_accp_adaptor_reg_lock(di);
	for (i = 0; (i < ACCP_RETRY_MAX_TIMES) && (adjust_osc_count <
		RT8979_ADJ_OSC_MAX_COUNT); i++) {
		/* before send cmd, read and clear accp interrupt registers */
		reg_val1 = switch_read_reg(di->client, RT8979_REG_ACCP_INTERRUPT1);
		reg_val2 = switch_read_reg(di->client, RT8979_REG_ACCP_INTERRUPT2);
		ret += switch_write_reg(di->client, RT8979_REG_ACCP_CMD,
			RT8979_ACCP_CMD_SBRRD);
		ret += switch_write_reg(di->client, RT8979_REG_ACCP_ADDR, reg);
		ret |= switch_write_reg_mask(di->client, RT8979_REG_ACCP_CNTL,
			RT8979_REG_ACCP_CNTL_ENABLE_MASK | RT8979_REG_ACCP_CNTL_SNDCMD_MASK,
			RT8979_ACCP_CNTL_MASK);
		if (ret) {
			hwlog_err("write error ret is %d \n", ret);
			rt8979_accp_adaptor_reg_unlock(di);
			return -1;
		}

		/* check cmd transfer success or fail */
		accp_check_ret = rt8979_accp_cmd_transfer_check(di);
		if (accp_check_ret == 0) {
			/* recived data from adapter */
			*val = switch_read_reg(di->client, RT8979_REG_ACCP_DATA);
			break;
		} else if (accp_check_ret == -RT8979_RETRY) {
			adjust_osc_count++;
			i--; /* do retry, so decrease the retry count */
		}
		/* if transfer failed, restart accp protocol */
		rt8979_accp_protocol_restart(di);
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
	rt8979_accp_adaptor_reg_unlock(di);
	return ret;
}

static int rt8979_accp_adapter_reg_write(int val, int reg)
{
	int reg_val1;
	int reg_val2;
	int i;
	int ret = 0;
	int adjust_osc_count = 0;
	int accp_check_ret;
	struct rt8979_device_info *di = rt8979_get_dev_info();

	if (!di)
		return -EINVAL;

	rt8979_accp_adaptor_reg_lock(di);
	for (i = 0; (i < ACCP_RETRY_MAX_TIMES) && (adjust_osc_count <
		RT8979_ADJ_OSC_MAX_COUNT); i++) {
		/* before send cmd, clear accp interrupt registers */
		reg_val1 = switch_read_reg(di->client, RT8979_REG_ACCP_INTERRUPT1);
		reg_val2 = switch_read_reg(di->client, RT8979_REG_ACCP_INTERRUPT2);
		ret |= switch_write_reg(di->client, RT8979_REG_ACCP_CMD, RT8979_ACCP_CMD_SBRWR);
		ret |= switch_write_reg(di->client, RT8979_REG_ACCP_ADDR, reg);
		ret |= switch_write_reg(di->client, RT8979_REG_ACCP_DATA, val);
		ret |= switch_write_reg_mask(di->client, RT8979_REG_ACCP_CNTL,
			RT8979_REG_ACCP_CNTL_ENABLE_MASK | RT8979_REG_ACCP_CNTL_SNDCMD_MASK,
			RT8979_ACCP_CNTL_MASK);
		if (ret < 0) {
			hwlog_err("write error ret is %d \n", ret);
			rt8979_accp_adaptor_reg_unlock(di);
			return -1;
		}

		/* check cmd transfer success or fail */
		accp_check_ret = rt8979_accp_cmd_transfer_check(di);
		if (accp_check_ret == 0) {
			break;
		} else if (accp_check_ret == -RT8979_RETRY) {
			adjust_osc_count++;
			i--; /* do retry, so decrease the retry count */
		}
		/* if transfer failed, restart accp protocol */
		rt8979_accp_protocol_restart(di);
		hwlog_err("adapter register write fail times=%d, register=0x%x, data=0x%x,"
			"reg[0x59]=0x%x, reg[0x5A]=0x%x\n", i, reg, val, reg_val1, reg_val2);
	}

	hwlog_debug("adapter register retry times=%d, register=0x%x, data=0x%x,"
		"reg[0x59]=0x%x, reg[0x5A]=0x%x\n", i, reg, val, reg_val1, reg_val2);

	if (i == ACCP_RETRY_MAX_TIMES) {
		hwlog_err("ack error,retry %d times \n", i);
		ret = -1;
	} else {
		ret = 0;
	}
	rt8979_accp_adaptor_reg_unlock(di);
	return ret;
}

static int rt8979_accp_adapter_detect(void *dev_data)
{
	int reg_val1;
	int reg_val2;
	int i;
	int j;
	bool vbus_present = false;
	struct rt8979_device_info *di = rt8979_get_dev_info();

	if (!di || !di->client)
		return ACCP_ADAPTOR_DETECT_OTHER;

	if (rt8979_check_accp_ic_status() == ACCP_NOT_PREPARE_OK) {
		hwlog_err("check_accp_ic_status not prepare ok\n");
		return ACCP_ADAPTOR_DETECT_OTHER;
	}

	rt8979_regs_dump();
	rt8979_accp_detect_lock(di);
	reg_val1 = switch_read_reg(di->client, RT8979_REG_DEVICE_TYPE_4);
	reg_val2 = switch_read_reg(di->client, RT8979_REG_ACCP_STATUS);
	if ((reg_val1 & RT8979_REG_DEVICE_TYPE_4_ACCP_CHARGER_MASK) &&
		((reg_val2 & RT8979_ACCP_STATUS_MASK) ==
		RT8979_ACCP_STATUS_SLAVE_GOOD)) {
		hwlog_info("accp adapter detect ok\n");
		rt8979_sw_open(true);
		rt8979_accp_detect_unlock(di);
		return ACCP_ADAPTOR_DETECT_SUCC;
	}
	rt8979_auto_restart_accp_det();
	rt8979_regs_dump();
	vbus_present = (switch_read_reg(di->client, RT8979_REG_MUIC_STATUS1) &
		RT8979_REG_MUIC_STATUS1_DCDT_MASK) ? false : true;
	for (j = 0; (j < ACCP_MAX_TRYCOUNT) && vbus_present; j++) {
		for (i = 0; i < ACCP_DETECT_MAX_COUT; i++) {
			reg_val1 = switch_read_reg(di->client, RT8979_REG_DEVICE_TYPE_4);
			reg_val2 = switch_read_reg(di->client, RT8979_REG_ACCP_STATUS);
			if ((reg_val1 & RT8979_REG_DEVICE_TYPE_4_ACCP_CHARGER_MASK) &&
				((reg_val2 & RT8979_ACCP_STATUS_MASK) ==
				RT8979_ACCP_STATUS_SLAVE_GOOD))
				break;
			rt8979_accp_sleep();
		}
		hwlog_info("reg 0x59=0x%x,reg 0x5A=0x%x, reg 0xA7=0x%x\n",
			switch_read_reg(di->client, RT8979_REG_ACCP_INTERRUPT1),
			switch_read_reg(di->client, RT8979_REG_ACCP_INTERRUPT2),
			switch_read_reg(di->client, RT8979_REG_MUIC_EXT2));
		if (i == ACCP_DETECT_MAX_COUT) {
			rt8979_accp_detect_unlock(di);
			hwlog_info("not accp adapter reg 0xf=0x%x reg 0x40=0x%x\n",
				reg_val1, reg_val2);
			if (reg_val1 & RT8979_REG_DEVICE_TYPE_4_ACCP_CHARGER_MASK)
				return ACCP_ADAPTOR_DETECT_FAIL;

			rt8979_regs_dump();
			vbus_present = (switch_read_reg(di->client, RT8979_REG_MUIC_STATUS1) &
				RT8979_REG_MUIC_STATUS1_DCDT_MASK) ? false : true;
			if (vbus_present)
				rt8979_force_restart_accp_det(true);
		} else {
			hwlog_info("accp adapter detect ok,take %d ms\n", i * ACCP_POLL_TIME);
			rt8979_sw_open(true);
			rt8979_accp_detect_unlock(di);
			return ACCP_ADAPTOR_DETECT_SUCC;
		}
	}
	rt8979_accp_detect_unlock(di);
	return ACCP_ADAPTOR_DETECT_OTHER; /* not fcp adapter */
}

static int rt8979_adapter_reset(void *dev_data)
{
	int ret;
	int val;
	struct rt8979_device_info *di = rt8979_get_dev_info();

	if (!di)
		return -EINVAL;

	switch_write_reg_mask(di->client, RT8979_REG_ACCP_CNTL, 0,
		RT8979_ACCP_CNTL_MASK);
	val = RT8979_REG_ACCP_CNTL_MSTR_RST_MASK;
	ret = switch_write_reg_mask(di->client, RT8979_REG_ACCP_CNTL, val,
		RT8979_ACCP_CNTL_MASK);
	hwlog_info("send fcp adapter reset %s\n", (ret < 0) ? "fail" : "sucess");
	return ret;
}

static int rt8979_chip_reset(void *dev_data)
{
	int ret, reg_ctl;
	struct rt8979_device_info *di = rt8979_get_dev_info();

	if (!di || !di->client)
		return -1;

	hwlog_info("%s++", __func__);

	disable_irq(di->irq);
	ret = switch_write_reg(di->client, RT8979_REG_RESET, 0x89);
	if (ret < 0)
		hwlog_err("reset fsa9688 failed \n");

	msleep(1);
	rt8979_accp_enable(di, true);
	switch_write_reg_mask(di->client, RT8979_REG_TIMING_SET_2,
		RT8979_REG_TIMING_SET_2_DCD_TIMEOUT_SET_MASK,
		RT8979_REG_TIMING_SET_2_DCD_TIMEOUT_SET_MASK);
	rt8979_set_dcd_timeout_enabled(false);
	ret = switch_write_reg(di->client, RT8979_REG_DETACH_CONTROL, 1);
	if (ret < 0)
		hwlog_err("write FSA9685_REG_DETACH_CONTROL error!!! ret=%d", ret);

	/* disable accp interrupt */
	ret |= switch_write_reg_mask(di->client, RT8979_REG_CONTROL2,
		RT8979_REG_CONTROL2_ACCP_OSC_EN_MASK, RT8979_REG_CONTROL2_ACCP_OSC_EN_MASK);
	ret += switch_write_reg(di->client, RT8979_REG_ACCP_INTERRUPT_MASK1, RT8979_REG_ALLMASK);
	ret += switch_write_reg(di->client, RT8979_REG_ACCP_INTERRUPT_MASK2, RT8979_REG_ALLMASK);
	if (ret < 0)
		hwlog_err("accp interrupt mask write failed \n");

	/* clear INT MASK */
	reg_ctl = switch_read_reg(di->client, RT8979_REG_CONTROL);
	if (reg_ctl < 0) {
		hwlog_err("read FSA9685_REG_CONTROL error!!! reg_ctl=%d.\n", reg_ctl);
		enable_irq(di->irq);
		return -1;
	}
	hwlog_info("read FSA9685_REG_CONTROL. reg_ctl=0x%x.\n", reg_ctl);

	reg_ctl &= (~RT8979_REG_CONTROL_INT_MASK_MASK);
	ret = switch_write_reg(di->client, RT8979_REG_CONTROL, reg_ctl);
	if (ret < 0) {
		hwlog_err("write FSA9685_REG_CONTROL error!!! reg_ctl=%d.\n", reg_ctl);
		enable_irq(di->irq);
		return -1;
	}
	hwlog_info("write FSA9685_REG_CONTROL. reg_ctl=0x%x.\n", reg_ctl);

	ret = switch_write_reg(di->client, RT8979_REG_DCD,
		RT8979_REG_DCD_STATUS_INIT_VAL);
	if (ret < 0) {
		hwlog_err("write FSA9685_REG_DCD error!!! reg_DCD=0x%x.\n", 0x08);
		enable_irq(di->irq);
		return -1;
	}
	hwlog_info("write FSA9685_REG_DCD. reg_DCD=0x%x.\n",
		RT8979_REG_DCD_STATUS_INIT_VAL);

	enable_irq(di->irq);
	rt8979_re_init(di);
	hwlog_info("%s--", __func__);
	return 0;
}

static int rt8979_accp_read_master_status(void *dev_data)
{
	int reg_val;
	int slave_good;
	int accp_status_mask;
	struct rt8979_device_info *di = rt8979_get_dev_info();

	if (!di)
		return -EINVAL;

	slave_good = RT8979_ACCP_STATUS_SLAVE_GOOD;
	accp_status_mask = RT8979_ACCP_STATUS_MASK;
	reg_val = switch_read_reg(di->client, RT8979_REG_ACCP_STATUS);
	if (reg_val < 0) {
		hwlog_err("reg_val fail\n");
		return -1;
	}

	if ((slave_good != (reg_val & accp_status_mask)))
		return -1;

	return 0;
}

int rt8979_is_accp_charger_type(void *dev_data)
{
	int reg_val;
	struct rt8979_device_info *di = rt8979_get_dev_info();

	if (!di)
		return 0;

	if (rt8979_is_support_fcp(di))
		return 0;

	reg_val = switch_read_reg(di->client, RT8979_REG_DEVICE_TYPE_4);
	if (reg_val < 0) {
		hwlog_err("read FSA9685_REG_DEVICE_TYPE_4 error\n");
		return 0;
	}
	if (reg_val & RT8979_REG_DEVICE_TYPE_4_ACCP_CHARGER_MASK)
		return 1;

	return 0;
}

static struct switch_interface_charger_ops rt8979_accp_ops = {
	.accp_adapter_reg_read = rt8979_accp_adapter_reg_read,
	.accp_adapter_reg_write = rt8979_accp_adapter_reg_write,
	.accp_adapter_detect = rt8979_accp_adapter_detect,
	.accp_adapter_reset = rt8979_adapter_reset,
	.accp_chip_reset = rt8979_chip_reset,
	.accp_read_master_status = rt8979_accp_read_master_status,
	.is_accp_charger_type = rt8979_is_accp_charger_type,
};

struct switch_interface_charger_ops *rt8979_get_accp_ops(void)
{
	return &rt8979_accp_ops;
}
