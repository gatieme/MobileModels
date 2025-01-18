// SPDX-License-Identifier: GPL-2.0
/*
 * hl7136_ufcs.c
 *
 * hl7136 ufcs driver
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

#include "hl7136_ufcs.h"
#include "hl7136_i2c.h"
#include "hl7136.h"
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/protocol/adapter_protocol.h>
#include <chipset_common/hwpower/protocol/adapter_protocol_ufcs.h>
#include <securec.h>

#define HWLOG_TAG hl7136_ufcs
HWLOG_REGIST();

struct hl7136_ufcs_msg_head *g_hl7136_ufcs_msg_head;

int hl7136_ufcs_init_msg_head(struct hl7136_device_info *di)
{
	struct hl7136_ufcs_msg_head *head = NULL;

	if (!di || g_hl7136_ufcs_msg_head)
		return 0;

	mutex_lock(&di->ufcs_node_lock);
	head = kzalloc(sizeof(struct hl7136_ufcs_msg_head), GFP_KERNEL);
	if (!head) {
		mutex_unlock(&di->ufcs_node_lock);
		return -ENOMEM;
	}

	head->num = 0;
	head->next = NULL;
	g_hl7136_ufcs_msg_head = head;
	mutex_unlock(&di->ufcs_node_lock);
	return 0;
}

static struct hl7136_ufcs_msg_node *hl7136_ufcs_create_node(const u8 *data, int len)
{
	struct hl7136_ufcs_msg_node *node = NULL;

	hwlog_info("create node\n");
	if (!data) {
		hwlog_err("data is null\n");
		return NULL;
	}

	node = kzalloc(sizeof(struct hl7136_ufcs_msg_node), GFP_KERNEL);
	if (!node) {
		hwlog_err("create node fail\n");
		return NULL;
	}

	node->len = len;
	if (memcpy_s(node->data, HL7136_UFCS_RX_BUF_SIZE, &data[0], len) != EOK) {
		kfree(node);
		return NULL;
	}

	return node;
}

static void hl7136_ufcs_add_node(struct hl7136_device_info *di,
	struct hl7136_ufcs_msg_node *node)
{
	struct hl7136_ufcs_msg_head *head = g_hl7136_ufcs_msg_head;
	struct hl7136_ufcs_msg_node *check_node = NULL;

	mutex_lock(&di->ufcs_node_lock);
	if (!head || !node) {
		hwlog_err("msg head or node is null\n");
		mutex_unlock(&di->ufcs_node_lock);
		return;
	}

	hwlog_info("add msg\n");
	if (!head->next) {
		head->next = node;
		goto end;
	}

	check_node = head->next;
	while (check_node->next)
		check_node = check_node->next;
	check_node->next = node;

end:
	head->num++;
	hwlog_info("current msg num=%d\n", head->num);
	mutex_unlock(&di->ufcs_node_lock);
}

static void hl7136_ufcs_delete_node(struct hl7136_device_info *di)
{
	struct hl7136_ufcs_msg_head *head = g_hl7136_ufcs_msg_head;
	struct hl7136_ufcs_msg_node *check_node = NULL;

	mutex_lock(&di->ufcs_node_lock);
	if (!head || !head->next) {
		hwlog_err("msg head or node is null\n");
		mutex_unlock(&di->ufcs_node_lock);
		return;
	}

	hwlog_info("delete msg\n");
	check_node = head->next;
	head->next = head->next->next;
	kfree(check_node);
	head->num--;
	hwlog_info("current msg num=%d\n", head->num);
	mutex_unlock(&di->ufcs_node_lock);
}

void hl7136_ufcs_free_node_list(struct hl7136_device_info *di, bool need_free_head)
{
	struct hl7136_ufcs_msg_head *head = g_hl7136_ufcs_msg_head;
	struct hl7136_ufcs_msg_node *free_node = NULL;
	struct hl7136_ufcs_msg_node *temp = NULL;

	if (!di || !head) {
		hwlog_err("di or msg head is null\n");
		return;
	}

	mutex_lock(&di->ufcs_node_lock);
	hwlog_info("free msg\n");
	free_node = head->next;
	while (free_node) {
		temp = free_node->next;
		kfree(free_node);
		free_node = temp;
	}
	head->next = NULL;
	head->num = 0;

	if (need_free_head) {
		kfree(head);
		g_hl7136_ufcs_msg_head = NULL;
	}
	mutex_unlock(&di->ufcs_node_lock);
}

static void hl7136_ufcs_add_commu_delay(struct hl7136_device_info *di)
{
	u32 delay = 0;
	u8 value = 0;
	int ret;

	if (!di)
		return;
	if (!di->ufcs_read_buffer_delay)
		return;

	ret = hl7136_read_byte(di, HL7136_UFCS_CTL1_REG, &value);

	value = (value & HL7136_UFCS_CTL1_BAUD_RATE_MASK) >>
		HL7136_UFCS_CTL1_BAUD_RATE_SHIFT;
	if (!value)
		delay = DT_USLEEP_1MS;
	else
		delay = DT_USLEEP_2MS;

	hwlog_info("ufcs baud rate:%d(115200->0), delay:%d\n", value, delay);
	power_usleep(delay);
}

void hl7136_ufcs_add_msg(struct hl7136_device_info *di)
{
	u8 len = 0;
	int ret;
	u8 data[HL7136_UFCS_RX_BUF_SIZE];
	struct hl7136_ufcs_msg_node *node = NULL;

	if (!di)
		return;

	ret = hl7136_read_byte(di, HL7136_UFCS_RX_LENGTH_REG, &len);
	if (ret)
		return;

	if (!len || len > HL7136_UFCS_RX_BUF_SIZE) {
		hwlog_err("length is %d, invalid\n", len);
		return;
	}

	hl7136_ufcs_add_commu_delay(di);

	ret = hl7136_read_block(di, data, HL7136_UFCS_RX_BUFFER_REG, len);
	if (ret)
		return;

	node = hl7136_ufcs_create_node(data, len);
	if (!node)
		return;

	hl7136_ufcs_add_node(di, node);

	hwlog_info("receive new msg, completion\n");
	complete(&di->hl7136_add_msg_completion);
}

static struct hl7136_ufcs_msg_node *hl7136_ufcs_get_msg(struct hl7136_device_info *di)
{
	struct hl7136_ufcs_msg_head *head = g_hl7136_ufcs_msg_head;

	if (!head || !head->next) {
		hwlog_err("msg head or node is null\n");
		return NULL;
	}

	return head->next;
}

static int hl7136_ufcs_wait(struct hl7136_device_info *di, u8 flag)
{
	u8 reg_val1;
	u8 reg_val2;
	int i;

	for (i = 0; i < HL7136_UFCS_WAIT_RETRY_CYCLE; i++) {
		if (!di->plugged_state)
			break;
		power_usleep(DT_USLEEP_1MS);
		reg_val1 = di->ufcs_irq[0];
		reg_val2 = di->ufcs_irq[1];
		hwlog_info("ufcs_isr1=0x%x, ufcs_isr2=0x%x\n", reg_val1, reg_val2);

		/* isr1[4] must be 0 */
		if ((flag & HWUFCS_WAIT_CRC_ERROR) &&
			(reg_val1 & HL7136_UFCS_ISR1_CRC_ERROR_MASK)) {
			hwlog_err("crc error\n");
			break;
		}

		/* isr2[1] must be 0 */
		if ((flag & HWUFCS_ACK_RECEIVE_TIMEOUT) &&
			(reg_val2 & HL7136_UFCS_ISR2_MSG_TRANS_FAIL_MASK)) {
			hwlog_err("not receive ack after retry\n");
			break;
		}

		/* isr1[3] must be 1 */
		if ((flag & HWUFCS_WAIT_SEND_PACKET_COMPLETE) &&
			!(reg_val2 & HL7136_UFCS_ISR2_RX_ACK_MASK)) {
			hwlog_err("not receive ack\n");
			continue;
		}

		/* isr1[2] must be 1 */
		if ((flag & HWUFCS_WAIT_DATA_READY) &&
			!(reg_val1 & HL7136_UFCS_ISR1_DATA_READY_MASK)) {
			hwlog_err("receive data not ready\n");
			continue;
		}

		hwlog_info("wait succ\n");
		return 0;
	}

	hwlog_err("wait fail\n");
	return -EINVAL;
}

static void hl7136_ufcs_handshake_preparation(struct hl7136_device_info *di)
{
	/* disable scp&ufcs */
	hl7136_write_byte(di, HL7136_UFCS_CTL1_REG, 0);

	/* enable DPDM */
	hl7136_write_mask(di, HL7136_CTRL3_REG,
		HL7136_CTRL3_DPDM_CFG_MASK, HL7136_CTRL3_DPDM_CFG_SHIFT, 0);
	/* enable ufcs */
	hl7136_write_mask(di, HL7136_UFCS_CTL1_REG,
		HL7136_UFCS_CTL1_EN_PROTOCOL_MASK,
		HL7136_UFCS_CTL1_EN_PROTOCOL_SHIFT, 2);

	hl7136_write_byte(di, HL7136_UFCS_CTL2_REG, 0);
	hl7136_write_mask(di, HL7136_UFCS_OPT1,
		HL7136_UFCS_PROTOCOL_RESET_MASK,
		HL7136_UFCS_PROTOCOL_RESET_SHIFT, 1);

	hl7136_write_mask(di, HL7136_UFCS_OPT1,
		HL7136_UFCS_STORE_ACK_TO_BUFF_MASK,
		HL7136_UFCS_STORE_ACK_TO_BUFF_SHIFT, 1);

	/* enable handshake */
	hl7136_write_mask(di, HL7136_UFCS_CTL1_REG,
		HL7136_UFCS_CTL1_EN_HANDSHAKE_MASK,
		HL7136_UFCS_CTL1_EN_HANDSHAKE_SHIFT, 1);
}

static int hl7136_ufcs_detect_adapter(void *dev_data)
{
	struct hl7136_device_info *di = dev_data;
	u8 reg_val = 0;
	int ret, i;

	if (!di) {
		hwlog_err("di is null\n");
		return HWUFCS_DETECT_OTHER;
	}

	di->ufcs_irq[0] = 0;
	di->ufcs_irq[1] = 0;
	mutex_lock(&di->ufcs_detect_lock);

	hl7136_ufcs_handshake_preparation(di);
	(void)power_usleep(DT_USLEEP_20MS);
	/* waiting for handshake */
	for (i = 0; i < HL7136_UFCS_HANDSHARK_RETRY_CYCLE; i++) {
		if (!di->plugged_state)
			break;
		(void)power_usleep(DT_USLEEP_5MS);
		ret = hl7136_read_byte(di, HL7136_UFCS_ISR1_REG, &reg_val);
		if (ret) {
			hwlog_err("read isr reg[%x] fail\n", HL7136_UFCS_ISR1_REG);
			continue;
		}

		reg_val |= di->ufcs_irq[0];
		hwlog_info("ufcs_isr1=0x%x\n", reg_val);
		if (reg_val & HL7136_UFCS_ISR1_HANDSHAKE_FAIL_MASK) {
			i = HL7136_UFCS_HANDSHARK_RETRY_CYCLE;
			break;
		}

		if (reg_val & HL7136_UFCS_ISR1_HANDSHAKE_SUCC_MASK)
			break;
	}

	mutex_unlock(&di->ufcs_detect_lock);

	if (i == HL7136_UFCS_HANDSHARK_RETRY_CYCLE) {
		hwlog_err("handshake fail\n");
		return HWUFCS_DETECT_FAIL;
	}

	(void)hl7136_write_mask(di, HL7136_UFCS_CTL2_REG,
		HL7136_UFCS_CTL2_DEV_ADDR_ID_MASK,
		HL7136_UFCS_CTL2_DEV_ADDR_ID_SHIFT, HL7136_UFCS_CTL2_SOURCE_ADDR);

	hwlog_info("handshake succ\n");
	queue_delayed_work(di->msg_update_wq, &di->ufcs_msg_update_work, 0);
	return HWUFCS_DETECT_SUCC;
}

static int hl7136_ufcs_write_msg(void *dev_data, u8 *data, u8 len, u8 flag)
{
	struct hl7136_device_info *di = dev_data;
	int ret;

	if (!di || !data) {
		hwlog_err("di or data is null\n");
		return -ENODEV;
	}

	if (len > HL7136_UFCS_TX_BUF_WITHOUTHEAD_SIZE) {
		hwlog_err("invalid length=%u\n", len);
		return -EINVAL;
	}

	di->ufcs_irq[0] = 0;
	di->ufcs_irq[1] = 0;

	ret = hl7136_write_byte(di, HL7136_UFCS_TX_LENGTH_REG, len);
	ret += hl7136_write_block(di, HL7136_UFCS_TX_BUFFER_REG,
		data, len);
	ret += hl7136_write_mask(di, HL7136_UFCS_CTL1_REG,
		HL7136_UFCS_CTL1_SEND_MASK, HL7136_UFCS_CTL1_SEND_SHIFT, 1);

	ret += hl7136_ufcs_wait(di, flag);

	return ret;
}

static int hl7136_ufcs_wait_msg_ready(void *dev_data, u8 flag)
{
	struct hl7136_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -ENODEV;
	}

	return hl7136_ufcs_wait(di, flag);
}

static int hl7136_ufcs_get_rx_len(void *dev_data, u8 *len)
{
	struct hl7136_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		*len = 0;
		return -ENODEV;
	}

	if (!di->ufcs_msg_ready_flag) {
		reinit_completion(&di->hl7136_ufcs_msg_update_completion);
		if (!wait_for_completion_timeout(&di->hl7136_ufcs_msg_update_completion,
			msecs_to_jiffies(HL7136_UFCS_WAIT_MSG_UPDATE_TIMEOUT))) {
			hwlog_err("wait for updating msg timeout\n");
			*len = 0;
			return -ENODEV;;
		}
	}

	*len = di->ufcs_pending_msg_len;
	return 0;
}

static int hl7136_ufcs_read_msg(void *dev_data, u8 *data, u8 len)
{
	struct hl7136_device_info *di = dev_data;

	if (!di || !data) {
		hwlog_err("di or data is null\n");
		return -ENODEV;
	}

	if (!di->ufcs_msg_ready_flag) {
		hwlog_err("msg is not ready\n");
		return -EINVAL;
	}

	if (len > HL7136_UFCS_RX_BUF_WITHOUTHEAD_SIZE) {
		hwlog_err("invalid length=%u\n", len);
		return -EINVAL;
	}

	if (memcpy_s(data, HL7136_UFCS_RX_BUF_WITHOUTHEAD_SIZE, &di->ufcs_pending_msg[0], len) != EOK)
		return -ENOMEM;

	di->ufcs_irq[0] = 0;
	di->ufcs_irq[1] = 0;
	return 0;
}

static int hl7136_ufcs_end_read_msg(void *dev_data)
{
	struct hl7136_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -ENODEV;
	}

	di->ufcs_msg_ready_flag = false;
	complete(&di->hl7136_ufcs_read_msg_completion);
	return 0;
}

void hl7136_ufcs_pending_msg_update_work(struct work_struct *work)
{
	struct hl7136_ufcs_msg_node *msg;
	struct hl7136_device_info *di = NULL;

	if (!work)
		return;

	di = container_of(work, struct hl7136_device_info, ufcs_msg_update_work.work);
	if (!di || !di->client)
		return;

	hwlog_info("start pending msg update work\n");

	/* init msg list */
	hl7136_ufcs_free_node_list(di, true);
	if (hl7136_ufcs_init_msg_head(di)) {
		hwlog_err("msg list init fail\n");
		return;
	}

	reinit_completion(&di->hl7136_add_msg_completion);
	reinit_completion(&di->hl7136_ufcs_read_msg_completion);

	while (1) {
		if (g_hl7136_ufcs_msg_head->num <= 0) {
			if (!wait_for_completion_timeout(&di->hl7136_add_msg_completion,
				msecs_to_jiffies(HL7136_UFCS_MSG_TIMEOUT))) {
				hwlog_err("wait for adding msg timeout\n");
				break;
			}
			reinit_completion(&di->hl7136_add_msg_completion);
		}

		msg = hl7136_ufcs_get_msg(di);
		if (!msg) {
			hwlog_err("msg is null\n");
			break;
		}
		di->ufcs_pending_msg_len = msg->len;
		if (memcpy_s(di->ufcs_pending_msg, HL7136_UFCS_RX_BUF_SIZE, &msg->data[0], di->ufcs_pending_msg_len) != EOK)
			break;
		di->ufcs_msg_ready_flag = true;
		hl7136_ufcs_delete_node(di);
		complete(&di->hl7136_ufcs_msg_update_completion);

		hwlog_info("pending msg updated\n");

		if (!di->ufcs_communicating_flag && di->ufcs_msg_ready_flag)
			power_event_bnc_notify(POWER_BNT_UFCS,
				POWER_NE_UFCS_REC_UNSOLICITED_DATA, NULL);

		if (!wait_for_completion_timeout(&di->hl7136_ufcs_read_msg_completion,
			msecs_to_jiffies(HL7136_UFCS_MSG_TIMEOUT))) {
			hwlog_err("wait for reading msg timeout\n");
			break;
		}
		reinit_completion(&di->hl7136_ufcs_read_msg_completion);
	}

	hl7136_ufcs_free_node_list(di, true);
}

void hl7136_ufcs_cancel_msg_update_work(struct hl7136_device_info *di)
{
	if (!di)
		return;

	complete(&di->hl7136_add_msg_completion);
	complete(&di->hl7136_ufcs_read_msg_completion);
	cancel_delayed_work(&di->ufcs_msg_update_work);
}

static int hl7136_ufcs_clear_rx_buff(void *dev_data)
{
	struct hl7136_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -ENODEV;
	}

	di->ufcs_irq[0] = 0;
	di->ufcs_irq[1] = 0;
	hl7136_ufcs_free_node_list(di, false);
	reinit_completion(&di->hl7136_add_msg_completion);
	return hl7136_ufcs_end_read_msg(di);
}

static int hl7136_ufcs_soft_reset_master(void *dev_data)
{
	struct hl7136_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -ENODEV;
	}

	di->ufcs_irq[0] = 0;
	di->ufcs_irq[1] = 0;
	hl7136_ufcs_cancel_msg_update_work(di);
	return hl7136_write_mask(di, HL7136_UFCS_CTL1_REG,
		HL7136_UFCS_CTL1_EN_PROTOCOL_MASK,
		HL7136_UFCS_CTL1_EN_PROTOCOL_SHIFT, 0);
}

static int hl7136_ufcs_set_communicating_flag(void *dev_data, bool flag)
{
	struct hl7136_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -ENODEV;
	}

	if (di->ufcs_communicating_flag && flag) {
		hwlog_err("is communicating, wait\n");
		return -EINVAL;
	}

	di->ufcs_communicating_flag = flag;
	return 0;
}

static int hl7136_ufcs_config_baud_rate(void *dev_data, int baud_rate)
{
	struct hl7136_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -ENODEV;
	}

	return hl7136_write_mask(di, HL7136_UFCS_CTL1_REG,
		HL7136_UFCS_CTL1_BAUD_RATE_MASK,
		HL7136_UFCS_CTL1_BAUD_RATE_SHIFT, (u8)baud_rate);
}

static int hl7136_ufcs_hard_reset_cable(void *dev_data)
{
	struct hl7136_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -ENODEV;
	}

	power_usleep(DT_USLEEP_10MS);
	return hl7136_write_mask(di, HL7136_UFCS_CTL1_REG,
		HL7136_UFCS_CTL1_CABLE_HARDRESET_MASK,
		HL7136_UFCS_CTL1_CABLE_HARDRESET_SHIFT, 1);
}

static bool hl7136_ufcs_need_check_ack(void *dev_data)
{
	return false;
}

static bool hl7136_ignore_detect_cable_info(void *dev_data)
{
	struct hl7136_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return false;
	}

	hwlog_info("ignore_get_cable_info = %d\n", di->ignore_get_cable_info);
	if (di->ignore_get_cable_info == 1)
		return true;
	else
		return false;
}

static struct hwufcs_ops hl7136_hwufcs_ops = {
	.chip_name = "hl7136",
	.detect_adapter = hl7136_ufcs_detect_adapter,
	.write_msg = hl7136_ufcs_write_msg,
	.wait_msg_ready = hl7136_ufcs_wait_msg_ready,
	.read_msg = hl7136_ufcs_read_msg,
	.end_read_msg = hl7136_ufcs_end_read_msg,
	.clear_rx_buff = hl7136_ufcs_clear_rx_buff,
	.soft_reset_master = hl7136_ufcs_soft_reset_master,
	.get_rx_len = hl7136_ufcs_get_rx_len,
	.set_communicating_flag = hl7136_ufcs_set_communicating_flag,
	.config_baud_rate = hl7136_ufcs_config_baud_rate,
	.hard_reset_cable = hl7136_ufcs_hard_reset_cable,
	.need_check_ack = hl7136_ufcs_need_check_ack,
	.ignore_detect_cable_info = hl7136_ignore_detect_cable_info,
};

int hl7136_ufcs_ops_register(struct hl7136_device_info *di)
{
	hl7136_hwufcs_ops.dev_data = (void *)di;
	return hwufcs_ops_register(&hl7136_hwufcs_ops);
}
