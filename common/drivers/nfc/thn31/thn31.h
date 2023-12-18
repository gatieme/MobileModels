/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2022. All rights reserved.
 */
/*
 * Copyright (c) 2013 NXP Semiconductors N.V.
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef THN31_H
#define THN31_H

#define THN31_MAGIC 0xE9

/*
 * THN31 power control via ioctl
 * THN31_SET_PWR(0): power off
 * THN31_SET_PWR(1): power on
 * THN31_SET_PWR(>1): power on with firmware download enabled
 */
#define THN31_SET_PWR _IOW(THN31_MAGIC, 0x01, unsigned int)
#define ESE_SET_PWR _IOW(THN31_MAGIC, 0x02, unsigned int)
#define ESE_GET_PWR _IOR(THN31_MAGIC, 0x03, unsigned int)
#define THN31_GET_CHIP_TYPE _IOW(THN31_MAGIC, 0x04, unsigned int)

#define NFC_DMD_NUMBER_MIN 923002000
#define NFC_DMD_NUMBER_MAX 923002016
#define NFC_DMD_I2C_READ_ERROR_NO 923002001
#define CHAR_0 48
#define MAX_DETECT_SE_SIZE 32

#define MTK_SIP_KERNEL_ESE_CONF_TO_TEE_ADDR_AARCH32 0x820002C4
#define MTK_SIP_KERNEL_ESE_CONF_TO_TEE_ADDR_AARCH64 0xC20002C4
#define OFFSET_8 8
#define OFFSET_16 16
#define ESE_MAGIC_NUM 0x66BB
#define MIN_NCI_CMD_LEN_WITH_BANKCARD_NUM 14
#define BANKCARD_NUM_LEN 16
#define BANKCARD_NUM_HEAD_LEN 2
#define BANKCARD_NUM_VALUE_LEN (BANKCARD_NUM_LEN - BANKCARD_NUM_HEAD_LEN)
#define BANKCARD_NUM_OVERRIDE_LEN 8
#define BANKCARD_NUM_OVERRIDE_OFFSET 4
#define MIN_NCI_CMD_LEN_WITH_DOOR_NUM 10
#define FIRST_LINE_NCI_LEN 3
#define NFC_A_PASSIVE 3
#define NFCID_LEN 9
#define DOORCARD_MIN_LEN 4
#define BYTE_CHAR_LEN 2
#define DOORCARD_OVERRIDE_LEN 20
#define MIFARE_DATA_UID_OFFSET 2
#define NCI_CMD_HEAD_OFFSET 0
#define FWUPDATE_ON_OFFSET 38  // (NFC_ERASER_OFFSET +1)

#define NFC_CLK_SRC_CPU 0
#define NFC_CLK_SRC_PMU 1
#define NFC_CLK_SRC_PMU_HI6555 2
#define NFC_CLK_SRC_PMU_HI6421V600 3
#define NFC_CLK_SRC_XTAL 4

enum {
    MODE_POWER_OFF = 0x00,
    MODE_POWER_ON,
    MODE_FW_DWNLD_WITH_VEN,
    MODE_ISO_RST,
    MODE_FW_DWND_HIGH,
    MODE_POWER_RESET,
    MODE_FW_GPIO_LOW,
    MODE_RF_GPIO_HIGH,
    MODE_RF_GPIO_LOW,
    MODE_THN31_VEN_HIGH = 0x0A,
    MODE_THN31_VEN_LOW,
    MODE_THN31_FW_DWND_HIGH,
    MODE_THN31_FW_DWND_LOW,
    MODE_THN31_NFC_DLD_FLUSH,
};

struct thn31_i2c_platform_data {
    int irq_gpio;
    int fwdl_en_gpio;
    int clk_req_gpio;
    int ven_gpio;
    int rf_gpio;
};

/*
 * NFCC can wired different eSEs by SWP/DWP
 * default NFCC don't wired eSE.
 * NFC_WITHOUT_ESE: NFCC don't wired eSE
 * NFC_ESE_THD89: use tms thd89 as eSE
 * NFC_ESE_HISEE: use hisi se as eSE
 */
enum NFC_ESE_TYPE {
    NFC_WITHOUT_ESE = 0,
    NFC_ESE_THD89,
    NFC_ESE_HISEE,
};

enum ese_ioctl_request {
    /* eSE POWER ON */
    ESE_POWER_ON = 0,
    /* eSE POWER OFF */
    ESE_POWER_OFF,
    /* eSE COLD RESET */
    ESE_COLD_RESET,
    /* eSE POWER STATE */
    ESE_POWER_STATE
};

#endif

