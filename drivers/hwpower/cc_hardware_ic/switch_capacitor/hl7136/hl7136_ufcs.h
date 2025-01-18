/* SPDX-License-Identifier: GPL-2.0 */
/*
 * hl7136_ufcs.h
 *
 * hl7136 ufcs header file
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

#ifndef _HL7136_UFCS_H_
#define _HL7136_UFCS_H_

#include "hl7136.h"

#define HL7136_UFCS_WAIT_RETRY_CYCLE                 80
#define HL7136_UFCS_HANDSHARK_RETRY_CYCLE            10
#define HL7136_UFCS_TX_BUF_WITHOUTHEAD_SIZE          34
#define HL7136_UFCS_RX_BUF_WITHOUTHEAD_SIZE          123
#define HL7136_UFCS_MSG_TIMEOUT                      3000   /* 3s */
#define HL7136_UFCS_WAIT_MSG_UPDATE_TIMEOUT          40

/* CTL2 reg=0x41 */
#define HL7136_UFCS_CTL2_REG                         0x41
#define HL7136_UFCS_CTL2_MSG_NOT_BLOCK_ACK_MASK      BIT(4)
#define HL7136_UFCS_CTL2_MSG_NOT_BLOCK_ACK_SHIFT     4
#define HL7136_UFCS_CTL2_LATE_RX_BUFFER_BUSY_MASK    BIT(3)
#define HL7136_UFCS_CTL2_LATE_RX_BUFFER_BUSY_SHIFT   3
#define HL7136_UFCS_CTL2_DEV_ADDR_ID_MASK            BIT(1)
#define HL7136_UFCS_CTL2_DEV_ADDR_ID_SHIFT           1
#define HL7136_UFCS_CTL2_EN_DM_HIZ_MASK              BIT(0)
#define HL7136_UFCS_CTL2_EN_DM_HIZ_SHIFT             0

#define HL7136_UFCS_CTL2_SOURCE_ADDR                 0
#define HL7136_UFCS_CTL2_CABLE_ADDR                  1

/* ISR1 reg=0x42 */
#define HL7136_UFCS_ISR1_REG                         0x42
#define HL7136_UFCS_ISR1_HANDSHAKE_FAIL_MASK         BIT(7)
#define HL7136_UFCS_ISR1_HANDSHAKE_FAIL_SHIFT        7
#define HL7136_UFCS_ISR1_HANDSHAKE_SUCC_MASK         BIT(6)
#define HL7136_UFCS_ISR1_HANDSHAKE_SUCC_SHIFT        6
#define HL7136_UFCS_ISR1_BAUD_RATE_ERROR_MASK        BIT(5)
#define HL7136_UFCS_ISR1_BAUD_RATE_ERROR_SHIFT       5
#define HL7136_UFCS_ISR1_CRC_ERROR_MASK              BIT(4)
#define HL7136_UFCS_ISR1_CRC_ERROR_SHIFT             4
#define HL7136_UFCS_ISR1_SEND_PACKET_COMPLETE_MASK   BIT(3)
#define HL7136_UFCS_ISR1_SEND_PACKET_COMPLETE_SHIFT  3
#define HL7136_UFCS_ISR1_DATA_READY_MASK             BIT(2)
#define HL7136_UFCS_ISR1_DATA_READY_SHIFT            2
#define HL7136_UFCS_ISR1_HARD_RESET_MASK             BIT(1)
#define HL7136_UFCS_ISR1_HARD_RESET_SHIFT            1
#define HL7136_UFCS_ISR1_ACK_REC_TIMEOUT_MASK        BIT(0)
#define HL7136_UFCS_ISR1_ACK_REC_TIMEOUT_SHIFT       0

/* ISR2 reg=0x43 */
#define HL7136_UFCS_ISR2_REG                         0x43
#define HL7136_UFCS_ISR2_RX_ACK_MASK                 BIT(7)
#define HL7136_UFCS_ISR2_RX_ACK_SHIFT                7
#define HL7136_UFCS_ISR2_RX_BUF_OVERFLOW_MASK        BIT(6)
#define HL7136_UFCS_ISR2_RX_BUF_OVERFLOW_SHIFT       6
#define HL7136_UFCS_ISR2_RX_LEN_ERR_MASK             BIT(5)
#define HL7136_UFCS_ISR2_RX_LEN_ERR_SHIFT            5
#define HL7136_UFCS_ISR2_BAUD_RATE_CHANGE_MASK       BIT(4)
#define HL7136_UFCS_ISR2_BAUD_RATE_CHANGE_SHIFT      4
#define HL7136_UFCS_ISR2_FRAME_REC_TIMEOUT_MASK      BIT(3)
#define HL7136_UFCS_ISR2_FRAME_REC_TIMEOUT_SHIFT     3
#define HL7136_UFCS_ISR2_RX_BUF_BUSY_MASK            BIT(2)
#define HL7136_UFCS_ISR2_RX_BUF_BUSY_SHIFT           2
#define HL7136_UFCS_ISR2_MSG_TRANS_FAIL_MASK         BIT(1)
#define HL7136_UFCS_ISR2_MSG_TRANS_FAIL_SHIFT        1
#define HL7136_UFCS_ISR2_TRA_BYTE_ERR_MASK           BIT(0)
#define HL7136_UFCS_ISR2_TRA_BYTE_ERR_SHIFT          0

#define HL7136_UFCS_ISR_NUM                          2
#define HL7136_UFCS_ISR_HIGH                         0
#define HL7136_UFCS_ISR_LOW                          1

/* MASK1 reg=0x44 */
#define HL7136_UFCS_MASK1_REG                        0x44
#define HL7136_UFCS_MASK1_HANDSHAKE_FAIL_MASK        BIT(7)
#define HL7136_UFCS_MASK1_HANDSHAKE_FAIL_SHIFT       7
#define HL7136_UFCS_MASK1_HANDSHAKE_SUCC_MASK        BIT(6)
#define HL7136_UFCS_MASK1_HANDSHAKE_SUCC_SHIFT       6
#define HL7136_UFCS_MASK1_BAUD_RATE_ERROR_MASK       BIT(5)
#define HL7136_UFCS_MASK1_BAUD_RATE_ERROR_SHIFT      5
#define HL7136_UFCS_MASK1_CRC_ERROR_MASK             BIT(4)
#define HL7136_UFCS_MASK1_CRC_ERROR_SHIFT            4
#define HL7136_UFCS_MASK1_SEND_PACKET_COMPLETE_MASK  BIT(3)
#define HL7136_UFCS_MASK1_SEND_PACKET_COMPLETE_SHIFT 3
#define HL7136_UFCS_MASK1_DATA_READY_MASK            BIT(2)
#define HL7136_UFCS_MASK1_DATA_READY_SHIFT           2
#define HL7136_UFCS_MASK1_HARD_RESET_MASK            BIT(1)
#define HL7136_UFCS_MASK1_HARD_RESET_SHIFT           1
#define HL7136_UFCS_MASK1_ACK_REC_TIMEOUT_MASK       BIT(0)
#define HL7136_UFCS_MASK1_ACK_REC_TIMEOUT_SHIFT      0

/* MASK2 reg=0x45 */
#define HL7136_UFCS_MASK2_REG                        0x45
#define HL7136_UFCS_MASK2_RX_BUF_OVERFLOW_MASK       BIT(6)
#define HL7136_UFCS_MASK2_RX_BUF_OVERFLOW_SHIFT      6
#define HL7136_UFCS_MASK2_RX_LEN_ERR_MASK            BIT(5)
#define HL7136_UFCS_MASK2_RX_LEN_ERR_SHIFT           5
#define HL7136_UFCS_MASK2_BAUD_RATE_CHANGE_MASK      BIT(4)
#define HL7136_UFCS_MASK2_BAUD_RATE_CHANGE_SHIFT     4
#define HL7136_UFCS_MASK2_FRAME_REC_TIMEOUT_MASK     BIT(3)
#define HL7136_UFCS_MASK2_FRAME_REC_TIMEOUT_SHIFT    3
#define HL7136_UFCS_MASK2_RX_BUF_BUSY_MASK           BIT(2)
#define HL7136_UFCS_MASK2_RX_BUF_BUSY_SHIFT          2
#define HL7136_UFCS_MASK2_MSG_TRANS_FAIL_MASK        BIT(1)
#define HL7136_UFCS_MASK2_MSG_TRANS_FAIL_SHIFT       1
#define HL7136_UFCS_MASK2_TRA_BYTE_ERR_MASK          BIT(0)
#define HL7136_UFCS_MASK2_TRA_BYTE_ERR_SHIFT         0

#define HL7136_UFCS_OPT1                             0xEA
#define HL7136_UFCS_STORE_ACK_TO_BUFF_MASK           BIT(6)
#define HL7136_UFCS_STORE_ACK_TO_BUFF_SHIFT          6
#define HL7136_UFCS_CLEAR_RX_BUFF_MASK               (BIT(5) | BIT (4))
#define HL7136_UFCS_CLEAR_RX_BUFF_SHIFT              4
#define HL7136_UFCS_PROTOCOL_RESET_MASK              BIT(2)
#define HL7136_UFCS_PROTOCOL_RESET_SHIFT             2

/* TX_LENGTH reg=0x47 */
#define HL7136_UFCS_TX_LENGTH_REG                    0x47

/* TX_BUFFER reg=0x4A */
#define HL7136_UFCS_TX_BUFFER_REG                    0x48

/* RX_LENGTH reg=0x6C */
#define HL7136_UFCS_RX_LENGTH_REG                    0x6C

/* RX_BUFFER reg=0x6F */
#define HL7136_UFCS_RX_BUFFER_REG                    0x6D

struct hl7136_ufcs_msg_node {
	int len;
	u8 data[HL7136_UFCS_RX_BUF_SIZE];
	struct hl7136_ufcs_msg_node *next;
};

struct hl7136_ufcs_msg_head {
	int num;
	struct hl7136_ufcs_msg_node *next;
};

int hl7136_ufcs_ops_register(struct hl7136_device_info *di);
void hl7136_ufcs_work(struct work_struct *work);
int hl7136_ufcs_init_msg_head(struct hl7136_device_info *di);
void hl7136_ufcs_free_node_list(struct hl7136_device_info *di, bool need_free_head);
void hl7136_ufcs_add_msg(struct hl7136_device_info *di);
void hl7136_ufcs_pending_msg_update_work(struct work_struct *work);
void hl7136_ufcs_cancel_msg_update_work(struct hl7136_device_info *di);

#endif /* _HL7136_UFCS_H_ */
