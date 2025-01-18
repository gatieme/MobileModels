// SPDX-License-Identifier: GPL-2.0
/*
 * hl7136_scp.c
 *
 * hl7136 protocol driver
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

#include "hl7136_scp.h"
#include "hl7136_i2c.h"
#include <linux/delay.h>
#include <linux/mutex.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/protocol/adapter_protocol.h>
#include <chipset_common/hwpower/protocol/adapter_protocol_scp.h>
#include <chipset_common/hwpower/protocol/adapter_protocol_fcp.h>

#define HWLOG_TAG hl7136_scp
HWLOG_REGIST();

static int hl7136_scp_wdt_reset_by_sw(struct hl7136_device_info *di)
{
	int ret;

	ret = hl7136_write_byte(di, HL7136_SCP_CTL_REG, HL7136_SCP_CTL_WDT_RESET);
	ret += hl7136_write_byte(di, HL7136_UFCS_CTL1_REG, HL7136_UFCS_CTL1_WDT_RESET);
	ret += hl7136_write_byte(di, HL7136_SCP_STIMER_REG, HL7136_SCP_STIMER_WDT_RESET);
	ret += hl7136_write_byte(di, HL7136_RT_BUFFER_0_REG, HL7136_RT_BUFFER_0_WDT_RESET);
	ret += hl7136_write_byte(di, HL7136_RT_BUFFER_1_REG, HL7136_RT_BUFFER_1_WDT_RESET);
	ret += hl7136_write_byte(di, HL7136_RT_BUFFER_2_REG, HL7136_RT_BUFFER_2_WDT_RESET);
	ret += hl7136_write_byte(di, HL7136_RT_BUFFER_3_REG, HL7136_RT_BUFFER_3_WDT_RESET);
	ret += hl7136_write_byte(di, HL7136_RT_BUFFER_4_REG, HL7136_RT_BUFFER_4_WDT_RESET);
	ret += hl7136_write_byte(di, HL7136_RT_BUFFER_5_REG, HL7136_RT_BUFFER_5_WDT_RESET);
	ret += hl7136_write_byte(di, HL7136_RT_BUFFER_6_REG, HL7136_RT_BUFFER_6_WDT_RESET);
	ret += hl7136_write_byte(di, HL7136_RT_BUFFER_7_REG, HL7136_RT_BUFFER_7_WDT_RESET);
	ret += hl7136_write_byte(di, HL7136_RT_BUFFER_8_REG, HL7136_RT_BUFFER_8_WDT_RESET);
	ret += hl7136_write_byte(di, HL7136_RT_BUFFER_9_REG, HL7136_RT_BUFFER_9_WDT_RESET);
	ret += hl7136_write_byte(di, HL7136_RT_BUFFER_10_REG, HL7136_RT_BUFFER_10_WDT_RESET);

	return ret;
}

/* just for reset-DM when slave ping lossed */
static int hl7136_reset_protocol_register(struct hl7136_device_info *di)
{
	int ret;

	ret = hl7136_write_byte(di, HL7136_DP_MAN_CTL_REG, HL7136_MAN_MODE);
	ret += hl7136_write_byte(di, HL7136_FORCE_DPDM_CTL_REG, HL7136_FORCE_DP_P6V);
	ret += hl7136_write_byte(di, HL7136_PASSWORD_0_REG, HL7136_PASSWORD_00_MASK);
	ret += hl7136_write_byte(di, HL7136_PASSWORD_0_REG, HL7136_PASSWORD_01_MASK);
	ret += hl7136_write_byte(di, HL7136_PASSWORD_1_REG, HL7136_PASSWORD_10_MASK);
	ret += hl7136_write_byte(di, HL7136_SCP_CTL_REG, HL7136_SCP_CTL_RESET);
	ret += hl7136_write_byte(di, HL7136_SCP_CTL_REG, HL7136_SCP_CTL_ENABLE_SCP);
	ret += hl7136_write_byte(di, HL7136_PASSWORD_1_REG, HL7136_PASSWORD_1_CLOSE);
	ret += hl7136_write_byte(di, HL7136_PASSWORD_0_REG, HL7136_PASSWORD_0_CLOSE);
	ret += hl7136_write_byte(di, HL7136_FORCE_DPDM_CTL_REG, HL7136_FORCE_DPDM_EXIT);
	ret += hl7136_write_byte(di, HL7136_DP_MAN_CTL_REG, HL7136_DP_MAN_EXIT);

	return ret;
}

static int hl7136_scp_cmd_transfer_check_1(struct hl7136_device_info *di)
{
	u8 reg_val1 = 0;
	u8 reg_val2 = 0;
	u8 pre_val1 = 0;
	u8 pre_val2 = 0;
	int i = 0;
	int ret0, ret1;

	do {
		usleep_range(50000, 51000); /* ic vendor requirements */
		ret0 = hl7136_read_byte(di, HL7136_SCP_ISR1_REG, &pre_val1);
		ret1 = hl7136_read_byte(di, HL7136_SCP_ISR2_REG, &pre_val2);
		if (ret0 || ret1) {
			hwlog_err("reg read failed\n");
			break;
		}
		hwlog_info("pre_val1(0x%x), pre_val2(0x%x)\n", pre_val1, pre_val2);
		/* save insterrupt value to reg_val1/2 from starting scp cmd to SLV_R_CPL interrupt */
		reg_val1 |= pre_val1;
		reg_val2 |= pre_val2;

		/* check whether slave ping lossed */
		if (((reg_val1 & HL7136_SCP_ISR1_ACK_CRCRX_MASK) ||
			(reg_val1 & HL7136_SCP_ISR1_ACK_PARRX_MASK)) &&
			!(reg_val2 & HL7136_SCP_ISR2_SLV_R_CPL_MASK)) {
			ret0 = hl7136_reset_protocol_register(di);
			hwlog_err("reset protocol, ret0 = %d\n", ret0);
			return -EPERM;
		}
		if (reg_val1 || reg_val2) {
			if (((reg_val2 & HL7136_SCP_ISR2_ACK_MASK) &&
				(reg_val2 & HL7136_SCP_ISR2_CMD_CPL_MASK) &&
				(reg_val2 & HL7136_SCP_ISR2_SLV_R_CPL_MASK)) &&
				!(reg_val1 & (HL7136_SCP_ISR1_ACK_CRCRX_MASK |
				HL7136_SCP_ISR1_ACK_PARRX_MASK | HL7136_SCP_ISR1_ERR_ACK_L_MASK))) {
				return 0;
			} else if (reg_val1 & (HL7136_SCP_ISR1_ACK_CRCRX_MASK |
				HL7136_SCP_ISR1_ENABLE_HAND_NO_RESPOND_MASK)) {
				hwlog_err("scp transfer fail, slave status changed: ISR1 = 0x%x, ISR2 = 0x%x\n",
					reg_val1, reg_val2);
				return -EPERM;
			} else if (reg_val2 & HL7136_SCP_ISR2_NACK_MASK) {
				hwlog_err("scp transfer fail, slave nack: ISR1 = 0x%x, ISR2 = 0x%x\n",
					reg_val1, reg_val2);
				return -EPERM;
			} else if (reg_val1 & (HL7136_SCP_ISR1_ACK_CRCRX_MASK |
				HL7136_SCP_ISR1_ACK_PARRX_MASK |
				HL7136_SCP_ISR1_TRANS_HAND_NO_RESPOND_MASK)) {
				hwlog_err("scp transfer fail, CRCRX_PARRX_ERROR: ISR1 = 0x%x, ISR2 = 0x%x\n",
					reg_val1, reg_val2);
				return -EPERM;
			}
			hwlog_err("scp transfer fail, ISR1 = 0x%x, ISR2 = 0x%x, index = %d\n",
				reg_val1, reg_val2, i);
		}
		i++;
		if (di->dc_ibus_ucp_happened)
			i = HL7136_SCP_ACK_RETRY_CYCLE_1;
	} while (i < HL7136_SCP_ACK_RETRY_CYCLE_1);

	hwlog_err("scp adapter transfer time out\n");
	return -EPERM;
}

static void hl7136_scp_protocol_restart(struct hl7136_device_info *di)
{
	u8 reg_val = 0;
	int ret, i;

	mutex_lock(&di->scp_detect_lock);

	/* detect scp charger, wait for ping succ */
	for (i = 0; i < HL7136_SCP_RESTART_TIME; i++) {
		usleep_range(9000, 10000); /* wait 9ms for each cycle */
		ret = hl7136_read_byte(di, HL7136_SCP_STATUS_REG, &reg_val);
		if (ret) {
			hwlog_err("read det attach err, ret: %d\n", ret);
			continue;
		}

		if (reg_val & HL7136_SCP_STATUS_ENABLE_HAND_SUCCESS_MASK)
			break;
	}

	if (i == HL7136_SCP_RESTART_TIME) {
		hwlog_err("wait for slave fail\n");
		mutex_unlock(&di->scp_detect_lock);
		return;
	}
	mutex_unlock(&di->scp_detect_lock);
	hwlog_info("disable and enable scp protocol accp status is 0x%x\n", reg_val);
}

static int hl7136_scp_adapter_reg_read(u8 *val, u8 reg, struct hl7136_device_info *di)
{
	int ret, i;
	u8 reg_val1 = 0;
	u8 reg_val2 = 0;

	mutex_lock(&di->accp_adapter_reg_lock);
	hwlog_info("CMD = 0x%x, REG = 0x%x\n", HL7136_SCP_CMD_SBRRD, reg);
	for (i = 0; i < HL7136_SCP_RETRY_TIME; i++) {
		/* init */
		hl7136_write_mask(di, HL7136_SCP_CTL_REG, HL7136_SCP_CTL_SNDCMD_MASK,
			HL7136_SCP_CTL_SNDCMD_SHIFT, HL7136_SCP_CTL_SNDCMD_RESET);

		/* before send cmd, clear isr interrupt registers */
		ret = hl7136_read_byte(di, HL7136_SCP_ISR1_REG, &reg_val1);
		ret += hl7136_read_byte(di, HL7136_SCP_ISR2_REG, &reg_val2);
		ret += hl7136_write_byte(di, HL7136_RT_BUFFER_0_REG, HL7136_SCP_CMD_SBRRD);
		ret += hl7136_write_byte(di, HL7136_RT_BUFFER_1_REG, reg);
		ret += hl7136_write_byte(di, HL7136_RT_BUFFER_2_REG, 1);
		ret += hl7136_write_mask(di, HL7136_SCP_CTL_REG, HL7136_SCP_CTL_SNDCMD_MASK,
			HL7136_SCP_CTL_SNDCMD_SHIFT, HL7136_SCP_CTL_SNDCMD_START);
		if (ret) {
			hwlog_err("write error, ret is %d\n", ret);
			/* manual init */
			hl7136_write_mask(di, HL7136_SCP_CTL_REG, HL7136_SCP_CTL_SNDCMD_MASK,
				HL7136_SCP_CTL_SNDCMD_SHIFT, HL7136_SCP_CTL_SNDCMD_RESET);
			mutex_unlock(&di->accp_adapter_reg_lock);
			return -EPERM;
		}

		/* check cmd transfer success or fail */
		if (hl7136_scp_cmd_transfer_check_1(di) == 0) {
			/* recived data from adapter */
			ret = hl7136_read_byte(di, HL7136_RT_BUFFER_12_REG, val);
			break;
		}

		hl7136_scp_protocol_restart(di);
		if (di->dc_ibus_ucp_happened)
			i = HL7136_SCP_RETRY_TIME;
	}
	if (i >= HL7136_SCP_RETRY_TIME) {
		hwlog_err("ack error, retry %d times\n", i);
		ret = -1;
	}
	/* manual init */
	hl7136_write_mask(di, HL7136_SCP_CTL_REG, HL7136_SCP_CTL_SNDCMD_MASK,
		HL7136_SCP_CTL_SNDCMD_SHIFT, HL7136_SCP_CTL_SNDCMD_RESET);
	usleep_range(10000, 11000); /* wait 10ms for operate effective */

	mutex_unlock(&di->accp_adapter_reg_lock);

	return ret;
}

static int hl7136_scp_adapter_reg_read_block(u8 reg, u8 *val, u8 num,
	void *dev_data)
{
	int ret, i;
	u8 reg_val1 = 0;
	u8 reg_val2 = 0;
	u8 *p = val;
	u8 data_len = (num < HL7136_SCP_DATA_LEN) ? num : HL7136_SCP_DATA_LEN;
	struct hl7136_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -ENOMEM;
	}
	mutex_lock(&di->accp_adapter_reg_lock);

	hwlog_info("CMD = 0x%x, REG = 0x%x, Num = 0x%x\n",
		HL7136_SCP_CMD_MBRRD, reg, data_len);

	for (i = 0; i < HL7136_SCP_RETRY_TIME; i++) {
		/* init */
		hl7136_write_mask(di, HL7136_SCP_CTL_REG, HL7136_SCP_CTL_SNDCMD_MASK,
			HL7136_SCP_CTL_SNDCMD_SHIFT, HL7136_SCP_CTL_SNDCMD_RESET);

		/* before sending cmd, clear isr registers */
		ret = hl7136_read_byte(di, HL7136_SCP_ISR1_REG, &reg_val1);
		ret += hl7136_read_byte(di, HL7136_SCP_ISR2_REG, &reg_val2);
		ret += hl7136_write_byte(di, HL7136_RT_BUFFER_0_REG, HL7136_SCP_CMD_MBRRD);
		ret += hl7136_write_byte(di, HL7136_RT_BUFFER_1_REG, reg);
		ret += hl7136_write_byte(di, HL7136_RT_BUFFER_2_REG, data_len);
		ret += hl7136_write_mask(di, HL7136_SCP_CTL_REG, HL7136_SCP_CTL_SNDCMD_MASK,
			HL7136_SCP_CTL_SNDCMD_SHIFT, HL7136_SCP_CTL_SNDCMD_START);
		if (ret) {
			hwlog_err("read error ret is %d\n", ret);
			/* manual init */
			hl7136_write_mask(di, HL7136_SCP_CTL_REG, HL7136_SCP_CTL_SNDCMD_MASK,
				HL7136_SCP_CTL_SNDCMD_SHIFT, HL7136_SCP_CTL_SNDCMD_RESET);
			mutex_unlock(&di->accp_adapter_reg_lock);
			return -EPERM;
		}

		/* check cmd transfer success or fail */
		if (hl7136_scp_cmd_transfer_check_1(di) == 0) {
			/* recived data from adapter */
			ret = hl7136_read_block(di, p, HL7136_RT_BUFFER_12_REG, data_len);
			break;
		}

		hl7136_scp_protocol_restart(di);
		if (di->dc_ibus_ucp_happened)
			i = HL7136_SCP_RETRY_TIME;
	}
	if (i >= HL7136_SCP_RETRY_TIME) {
		hwlog_err("ack error, retry %d times\n", i);
		ret = -1;
	}
	mutex_unlock(&di->accp_adapter_reg_lock);

	if (ret) {
		/* manual init */
		hl7136_write_mask(di, HL7136_SCP_CTL_REG, HL7136_SCP_CTL_SNDCMD_MASK,
			HL7136_SCP_CTL_SNDCMD_SHIFT, HL7136_SCP_CTL_SNDCMD_RESET);
		return ret;
	}

	num -= data_len;
	/* max is HL7136_SCP_DATA_LEN. remaining data is read in below */
	if (num) {
		p += data_len;
		reg += data_len;
		ret = hl7136_scp_adapter_reg_read_block(reg, p, num, di);
		if (ret) {
			/* manual init */
			hl7136_write_mask(di, HL7136_SCP_CTL_REG, HL7136_SCP_CTL_SNDCMD_MASK,
				HL7136_SCP_CTL_SNDCMD_SHIFT, HL7136_SCP_CTL_SNDCMD_RESET);
			hwlog_err("read error, ret is %d\n", ret);
			return -EPERM;
		}
	}
	/* manual init */
	hl7136_write_mask(di, HL7136_SCP_CTL_REG, HL7136_SCP_CTL_SNDCMD_MASK,
		HL7136_SCP_CTL_SNDCMD_SHIFT, HL7136_SCP_CTL_SNDCMD_RESET);
	usleep_range(10000, 11000); /* wait 10ms for operate effective */

	return 0;
}

static int hl7136_scp_adapter_reg_write(u8 val, u8 reg, void *dev_data)
{
	int ret, i;
	u8 reg_val1 = 0;
	u8 reg_val2 = 0;
	struct hl7136_device_info *di = dev_data;

	mutex_lock(&di->accp_adapter_reg_lock);
	hwlog_info("CMD = 0x%x, REG = 0x%x, val = 0x%x\n",
		HL7136_SCP_CMD_SBRWR, reg, val);
	for (i = 0; i < HL7136_SCP_RETRY_TIME; i++) {
		/* init */
		hl7136_write_mask(di, HL7136_SCP_CTL_REG, HL7136_SCP_CTL_SNDCMD_MASK,
			HL7136_SCP_CTL_SNDCMD_SHIFT, HL7136_SCP_CTL_SNDCMD_RESET);

		/* before send cmd, clear accp interrupt registers */
		ret = hl7136_read_byte(di, HL7136_SCP_ISR1_REG, &reg_val1);
		ret += hl7136_read_byte(di, HL7136_SCP_ISR2_REG, &reg_val2);
		ret += hl7136_write_byte(di, HL7136_RT_BUFFER_0_REG, HL7136_SCP_CMD_SBRWR);
		ret += hl7136_write_byte(di, HL7136_RT_BUFFER_1_REG, reg);
		ret += hl7136_write_byte(di, HL7136_RT_BUFFER_2_REG, 1);
		ret += hl7136_write_byte(di, HL7136_RT_BUFFER_3_REG, val);
		ret += hl7136_write_mask(di, HL7136_SCP_CTL_REG, HL7136_SCP_CTL_SNDCMD_MASK,
			HL7136_SCP_CTL_SNDCMD_SHIFT, HL7136_SCP_CTL_SNDCMD_START);
		if (ret) {
			hwlog_err("write error, ret is %d\n", ret);
			/* manual init */
			hl7136_write_mask(di, HL7136_SCP_CTL_REG, HL7136_SCP_CTL_SNDCMD_MASK,
				HL7136_SCP_CTL_SNDCMD_SHIFT, HL7136_SCP_CTL_SNDCMD_RESET);
			mutex_unlock(&di->accp_adapter_reg_lock);
			return -EPERM;
		}

		/* check cmd transfer success or fail */
		if (hl7136_scp_cmd_transfer_check_1(di) == 0)
			break;

		hl7136_scp_protocol_restart(di);
		if (di->dc_ibus_ucp_happened)
			i = HL7136_SCP_RETRY_TIME;
	}
	if (i >= HL7136_SCP_RETRY_TIME) {
		hwlog_err("ack error, retry %d times\n", i);
		ret = -1;
	}
	/* manual init */
	hl7136_write_mask(di, HL7136_SCP_CTL_REG, HL7136_SCP_CTL_SNDCMD_MASK,
		HL7136_SCP_CTL_SNDCMD_SHIFT, HL7136_SCP_CTL_SNDCMD_RESET);
	usleep_range(10000, 11000); /* wait 10ms for operate effective */

	mutex_unlock(&di->accp_adapter_reg_lock);
	return ret;
}

static int hl7136_fcp_master_reset(void *dev_data)
{
	struct hl7136_device_info *di = dev_data;
	int ret;

	if (!di) {
		hwlog_err("di is null\n");
		return -EPERM;
	}

	ret = hl7136_scp_wdt_reset_by_sw(di);
	if (ret)
		return -EPERM;

	usleep_range(10000, 11000); /* wait 10ms for operate effective */

	return 0;
}

static int hl7136_fcp_adapter_reset(void *dev_data)
{
	int ret;
	struct hl7136_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -EPERM;
	}

	ret = hl7136_write_mask(di, HL7136_SCP_CTL_REG, HL7136_SCP_CTL_MSTR_RST_MASK,
		HL7136_SCP_CTL_MSTR_RST_SHIFT, 1);
	if (ret)
		return -EPERM;
	usleep_range(20000, 21000); /* wait 20ms for operate effective */

	return hl7136_scp_wdt_reset_by_sw(di);
}

static int hl7136_fcp_read_switch_status(void *dev_data)
{
	return 0;
}

static int hl7136_is_fcp_charger_type(void *dev_data)
{
	u8 reg_val = 0;
	int ret;
	struct hl7136_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -EPERM;
	}

	if (!di->param_dts.fcp_support)
		return 0;

	ret = hl7136_read_byte(di, HL7136_SCP_STATUS_REG, &reg_val);
	if (ret)
		return 0;

	if (reg_val & HL7136_SCP_STATUS_ENABLE_HAND_SUCCESS_MASK)
		return 1;
	return 0;
}

static int hl7136_fcp_adapter_detect(struct hl7136_device_info *di)
{
	u8 reg_val = 0;
	int vbus_uvp, i, ret;

	mutex_lock(&di->scp_detect_lock);

	/* confirm enable hand success status */
	if (reg_val & HL7136_SCP_STATUS_ENABLE_HAND_SUCCESS_MASK) {
		mutex_unlock(&di->scp_detect_lock);
		hwlog_info("scp adapter detect ok\n");
		return ADAPTER_DETECT_SUCC;
	}
	ret = hl7136_write_mask(di, HL7136_UFCS_CTL1_REG, HL7136_UFCS_CTL1_EN_PROTOCOL_MASK,
		HL7136_UFCS_CTL1_EN_PROTOCOL_SHIFT, 0x01);
	ret += hl7136_write_mask(di, HL7136_SCP_CTL_REG, HL7136_SCP_CTL_SCP_DET_EN_MASK,
		HL7136_SCP_CTL_SCP_DET_EN_SHIFT, 1);
	if (ret) {
		hwlog_err("SCP enable detect fail, ret is %d\n", ret);
		hl7136_write_mask(di, HL7136_SCP_CTL_REG, HL7136_SCP_CTL_EN_SCP_MASK,
			HL7136_SCP_CTL_EN_SCP_SHIFT, 0);
		hl7136_write_mask(di, HL7136_SCP_CTL_REG, HL7136_SCP_CTL_SCP_DET_EN_MASK,
			HL7136_SCP_CTL_SCP_DET_EN_SHIFT, 0);
		/* reset scp registers when EN_SCP is changed to 0 */
		hl7136_scp_wdt_reset_by_sw(di);
		hl7136_fcp_adapter_reset(di);
		mutex_unlock(&di->scp_detect_lock);
		return -EPERM;
	}
	/* waiting for scp set */
	for (i = 0; i < HL7136_SCP_DETECT_MAX_COUT; i++) {
		ret = hl7136_read_byte(di, HL7136_SCP_STATUS_REG, &reg_val);
		vbus_uvp = 0;
		hwlog_info("HL7136_SCP_STATUS_REG 0x%x\n", reg_val);
		if (ret) {
			hwlog_err("read det attach err, ret:%d\n", ret);
			continue;
		}
		if (vbus_uvp) {
			hwlog_err("0x%x vbus uv happen, adapter plug out\n", vbus_uvp);
			break;
		}
		if (reg_val & HL7136_SCP_STATUS_ENABLE_HAND_SUCCESS_MASK)
			break;
		msleep(HL7136_SCP_POLL_TIME);
	}
	if ((i == HL7136_SCP_DETECT_MAX_COUT) || vbus_uvp) {
		hl7136_write_mask(di, HL7136_SCP_CTL_REG, HL7136_SCP_CTL_EN_SCP_MASK,
			HL7136_SCP_CTL_EN_SCP_SHIFT, 0);
		hl7136_write_mask(di, HL7136_SCP_CTL_REG, HL7136_SCP_CTL_SCP_DET_EN_MASK,
			HL7136_SCP_CTL_SCP_DET_EN_SHIFT, 0);
		/* reset scp registers when EN_SCP is changed to 0 */
		hl7136_scp_wdt_reset_by_sw(di);
		hl7136_fcp_adapter_reset(di);
		hwlog_err("CHG_SCP_ADAPTER_DETECT_OTHER return\n");
		mutex_unlock(&di->scp_detect_lock);
		return ADAPTER_DETECT_OTHER;
	}

	mutex_unlock(&di->scp_detect_lock);
	return ret;
}

static int hl7136_fcp_stop_charge_config(void *dev_data)
{
	struct hl7136_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -EPERM;
	}

	hl7136_fcp_master_reset(di);
	hl7136_write_mask(di, HL7136_SCP_CTL_REG, HL7136_SCP_CTL_SCP_DET_EN_MASK,
		HL7136_SCP_CTL_SCP_DET_EN_SHIFT, 0);

	return 0;
}

static int hl7136_scp_reg_read(u8 *val, u8 reg, void *dev_data)
{
	int ret;
	struct hl7136_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -EPERM;
	}

	if (di->hl7136_scp_error_flag) {
		hwlog_err("scp timeout happened, do not read reg = 0x%x\n", reg);
		return -EPERM;
	}

	ret = hl7136_scp_adapter_reg_read(val, reg, dev_data);
	if (ret) {
		hwlog_err("error reg = 0x%x\n", reg);
		if (reg != HWSCP_ADP_TYPE0)
			di->hl7136_scp_error_flag = HL7136_SCP_IS_ERR;

		return -EPERM;
	}

	return 0;
}

static int hl7136_scp_reg_write(u8 val, u8 reg, void *dev_data)
{
	int ret;
	struct hl7136_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -EPERM;
	}

	if (di->hl7136_scp_error_flag) {
		hwlog_err("scp timeout happened, do not write reg = 0x%x\n", reg);
		return -EPERM;
	}

	ret = hl7136_scp_adapter_reg_write(val, reg, dev_data);
	if (ret) {
		hwlog_err("error reg = 0x%x\n", reg);
		di->hl7136_scp_error_flag = HL7136_SCP_IS_ERR;
		return -EPERM;
	}

	return 0;
}

static int hl7136_self_check(void *dev_data)
{
	return 0;
}

static int hl7136_scp_chip_reset(void *dev_data)
{
	return hl7136_fcp_master_reset(dev_data);
}

static int hl7136_scp_reg_read_block(int reg, int *val, int num,
	void *dev_data)
{
	int ret;
	int i;
	u8 data = 0;

	struct hl7136_device_info *di = dev_data;

	if (!val || !di) {
		hwlog_err("val or di is null\n");
		return -EPERM;
	}

	di->hl7136_scp_error_flag = HL7136_SCP_NO_ERR;

	for (i = 0; i < num; i++) {
		ret = hl7136_scp_reg_read(&data, reg + i, dev_data);
		if (ret) {
			hwlog_err("scp read failed, reg=0x%x\n", reg + i);
			return -EPERM;
		}
		val[i] = data;
	}

	return 0;
}

static int hl7136_scp_reg_write_block(int reg, const int *val, int num,
	void *dev_data)
{
	int ret, i;

	struct hl7136_device_info *di = dev_data;

	if (!val || !di) {
		hwlog_err("val or di is null\n");
		return -EPERM;
	}

	di->hl7136_scp_error_flag = HL7136_SCP_NO_ERR;

	for (i = 0; i < num; i++) {
		ret = hl7136_scp_reg_write(val[i], reg + i, dev_data);
		if (ret) {
			hwlog_err("scp write failed, reg=0x%x\n", reg + i);
			return -EPERM;
		}
	}

	return 0;
}

static int hl7136_scp_detect_adapter(void *dev_data)
{
	struct hl7136_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -EPERM;
	}

	return hl7136_fcp_adapter_detect(di);
}

static int hl7136_fcp_reg_read_block(int reg, int *val, int num,
	void *dev_data)
{
	int ret, i;
	u8 data = 0;

	struct hl7136_device_info *di = dev_data;

	if (!val || !di) {
		hwlog_err("val or di is null\n");
		return -EPERM;
	}

	di->hl7136_scp_error_flag = HL7136_SCP_NO_ERR;

	for (i = 0; i < num; i++) {
		ret = hl7136_scp_reg_read(&data, reg + i, dev_data);
		if (ret) {
			hwlog_err("fcp read failed, reg=0x%x\n", reg + i);
			return -EPERM;
		}
		val[i] = data;
	}
	return 0;
}

static int hl7136_fcp_reg_write_block(int reg, const int *val, int num,
	void *dev_data)
{
	int ret, i;

	struct hl7136_device_info *di = dev_data;

	if (!val || !di) {
		hwlog_err("val or di is null\n");
		return -EPERM;
	}

	di->hl7136_scp_error_flag = HL7136_SCP_NO_ERR;

	for (i = 0; i < num; i++) {
		ret = hl7136_scp_reg_write(val[i], reg + i, dev_data);
		if (ret) {
			hwlog_err("fcp write failed, reg=0x%x\n", reg + i);
			return -EPERM;
		}
	}

	return 0;
}

static int hl7136_fcp_detect_adapter(void *dev_data)
{
	struct hl7136_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -EPERM;
	}

	return hl7136_fcp_adapter_detect(di);
}

static int hl7136_pre_init(void *dev_data)
{
	struct hl7136_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -EPERM;
	}

	return hl7136_self_check(di);
}

static int hl7136_scp_adapter_reset(void *dev_data)
{
	struct hl7136_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -EPERM;
	}

	return hl7136_fcp_adapter_reset(di);
}

static struct hwscp_ops hl7136_hwscp_ops = {
	.chip_name = "hl7136",
	.reg_read = hl7136_scp_reg_read_block,
	.reg_write = hl7136_scp_reg_write_block,
	.reg_multi_read = hl7136_scp_adapter_reg_read_block,
	.detect_adapter = hl7136_scp_detect_adapter,
	.soft_reset_master = hl7136_scp_chip_reset,
	.soft_reset_slave = hl7136_scp_adapter_reset,
	.pre_init = hl7136_pre_init,
};

static struct hwfcp_ops hl7136_hwfcp_ops = {
	.chip_name = "hl7136",
	.reg_read = hl7136_fcp_reg_read_block,
	.reg_write = hl7136_fcp_reg_write_block,
	.detect_adapter = hl7136_fcp_detect_adapter,
	.soft_reset_master = hl7136_fcp_master_reset,
	.soft_reset_slave = hl7136_fcp_adapter_reset,
	.get_master_status = hl7136_fcp_read_switch_status,
	.stop_charging_config = hl7136_fcp_stop_charge_config,
	.is_accp_charger_type = hl7136_is_fcp_charger_type,
};

int hl7136_hwscp_register(struct hl7136_device_info *di)
{
	hl7136_hwscp_ops.dev_data = (void *)di;
	return hwscp_ops_register(&hl7136_hwscp_ops);
}

int hl7136_hwfcp_register(struct hl7136_device_info *di)
{
	hl7136_hwfcp_ops.dev_data = (void *)di;
	return hwfcp_ops_register(&hl7136_hwfcp_ops);
}
