/* SPDX-License-Identifier: GPL-2.0 */
/*
 * rhc32l110_fw.h
 *
 * rhc32l110 firmware header file
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

#ifndef _RHC32L110_FW_H_
#define _RHC32L110_FW_H_

#define RHC32L110_FW_DEV_ID_REG              0xE0

#define RHC32L110_FW_VER_ID_REG              0xE1

/* main_ver reg=0x02 */
#define RHC32L110_FW_SUB_VER_REG             0x02

/* sub_ver reg=0x03 */
#define RHC32L110_FW_PATCH_VER_REG           0x03

#define RHC32L110_FW_PAGE_SIZE               128
#define RHC32L110_FW_CMD_SIZE                2
#define RHC32L110_FW_ERASE_SIZE              3
#define RHC32L110_FW_ADDR_SIZE               5
#define RHC32L110_FW_ACK_COUNT               10
#define RHC32L110_FW_RETRY_COUNT             3
#define RHC32L110_FW_ERASE_ACK_COUNT         2

/* cmd */
#define RHC32L110_FW_MTP_ADDR                0x00002800
#define RHC32L110_FW_GET_VER_CMD             0x01FE
#define RHC32L110_FW_WRITE_CMD               0x32CD
#define RHC32L110_FW_ERASE_CMD               0x45BA
#define RHC32L110_FW_GO_CMD                  0x21DE
#define RHC32L110_FW_ACK_VAL                 0x79

int rhc32l110_fw_get_ver_id(struct rstm32g031_device_info *di);
int rhc32l110_fw_update_empty_mtp(struct rstm32g031_device_info *di);
int rhc32l110_fw_update_latest_mtp(struct rstm32g031_device_info *di);
int rhc32l110_fw_update_online_mtp(struct rstm32g031_device_info *di,
	u8 *mtp_data, int mtp_size, int ver_id);

#endif /* _RHC32L110_FW_H_ */
