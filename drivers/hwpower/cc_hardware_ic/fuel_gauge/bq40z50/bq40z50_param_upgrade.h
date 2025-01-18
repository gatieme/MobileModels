/* SPDX-License-Identifier: GPL-2.0 */
/*
 * bq40z50_param_upgrade.h
 *
 * bq40z50 param upgrade
 *
 * Copyright (c) 2024-2024 Huawei Technologies Co., Ltd.
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

#include <linux/jiffies.h>
#include "bq40z50.h"

#ifndef _BQ40Z50_PARAM_UPGRADE_H_
#define _BQ40Z50_PARAM_UPGRADE_H_

/* bq40z50 gauge update param */
#define BQ40Z50_REG_LOCK                                0x30 /* batt lock */
#define BQ40Z50_GAUGE_VERSION_INVALID                   0x00
#define BQ40Z50_GAUGE_BATT_SEAL_STATUS                  0x3
#define BQ40Z50_GAUGE_A_BATT_UNSEAL_STATUS              0x1
#define BQ40Z50_GAUGE_C_BATT_UNSEAL_STATUS              0x0
#define BQ40Z50_SUB_CMD_READ_BLOCK_LEN_MAX              35
#define BQ40Z50_SUB_CMD_WIRTE_VERSION_SIZE              4
#define BQ40Z50_SUB_CMD_OP_STATUS                       0x0054  /* operation status sub commond */
#define BQ40Z50_SUB_CMD_MFI                             0x0070  /* manufacturer info sub commond */
#define BQ40Z50_SUB_CMD_VERSION                         0x4060  /* version sub commond */
#define BQ40Z50_SUB_CMD_SING_BYTE_MASK                  0xFF
#define BQ40Z50_SUB_CMD_SING_BYTE_LEN                   8
#define BQ40Z50_SUB_CMD_WIRTE_VERSION_LEN               0x03
#define BQ40Z50_SUB_CMD_READ_GAUGE_PARAM_FIRST_INDEX    3      /* gauge param first index */
#define BQ40Z50_SUB_CMD_READ_VERSION_INDEX              34     /* version index */
#define BQ40Z50_SUB_CMD_READ_SEAL_STATUS_INDEX          4      /* lock status index of read operation status data array */
#define BQ40Z50_SUB_CMD_READ_SEAL_STATUS_BIT_SCOPE      0x3    /* lock status bit scope of read operation status data */
#define BQ40Z50_GAUGE_UPGRADE_FAIL_STATUS               1
#define BQ40Z50_GAUGE_UPGRADE_SUCCESS_STATUS            0
#define BQ40Z50_PARAM_UPGRADE_DMD_REPORT_ID             930001022
#define BQ40Z50_OCV_UPGRADE_DMD_DELAY_REPORT_TIME60S    60000
#define BQ40Z50_UNSEAL_WORD_SING_BYTE_MASK              0xFFFF
#define BQ40Z50_UNSEAL_WORD_SING_BYTE_LEN               16
#define BQ40Z50_C_RESET                                 0x41
#define UPGRADE_PARAM_DTSI_TITLE_LEN                    100
#define GAUGE_VERSION_STRING_LEN                        8
#define GAUGE_REPORT_PARAM_SIZE                         4
#define UPDATE_RESULT_INDEX                             0
#define GAUGE_VERSION_INDEX                             1
#define DEVICE_NAME_INDEX                               2
#define MANUFAC_NAME_INDEX                              3

/* coul manufacturer_name judge factory */
#define BQ40Z50_MANUFACTURE_NAME_VERSION_INDEX          1

/* bq40z50 process update param */
#define INDEX_TYPE                                      0
#define OPERATE_WRITE                                   2
#define OPERATE_COMPARE                                 3
#define OPERATE_WAIT                                    4
#define OPERATE_LINE_LEN                                4
#define OPERATE_BUF_LEN_INDEX                           3
#define OPERATE_BUF_START_INDEX                         4
#define OPERATE_COMPARE_A_LINE_LEN                      5
#define OPERATE_COMPARE_A_BUF_LEN_INDEX                 4
#define OPERATE_COMPARE_A_BUF_START_INDEX               5
#define COMPARE_BUF_FIRST_INDEX                         3
#define OPERATE_WAIT_BUF_HIGH_INDEX                     2
#define OPERATE_WAIT_BUF_LOW_INDEX                      3
#define OPERATE_WAIT_BUF_LEN_INDEX                      1
#define OPERATE_WAIT_BUF_LEN                            2
#define BYTE_HIGH_TO_LOW                                256
#define REG_CMD_INDEX                                   2

void bq40z50_creat_param_upgrade_delay_work(struct bq40z50_device_info *di);
void bq40z50_cancel_param_upgrade_delay_work(struct bq40z50_device_info *di);

#endif /* _BQ40Z50_PARAM_UPGRADE_H_ */
