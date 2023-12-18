/*
 * rt8979_reg.h
 *
 * Register head file for rt8979
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

#ifndef _RT8979_REG_H_
#define _RT8979_REG_H_

#include <linux/bitops.h>

/* reg=0x01, R, device id */
#define RT8979_REG_DEVICE_ID                            0x01

#define RT8979_REG_DEVICE_ID_VERSION_ID_MASK  \
	(BIT(7) | BIT(6) | BIT(5) | BIT(4) | BIT(3))
#define RT8979_REG_DEVICE_ID_VERSION_ID_SHIFT           3
#define RT8979_REG_DEVICE_ID_VENDOR_ID_MASK             (BIT(2) | BIT(1) | BIT(0))
#define RT8979_REG_DEVICE_ID_VENDOR_ID_SHIFT            0

/* reg=0x02, RW, control 1 */
#define RT8979_REG_CONTROL                              0x02

#define RT8979_REG_CONTROL_SW_OPEN_MASK                 BIT(4)
#define RT8979_REG_CONTROL_SW_OPEN_SHIFT                4
#define RT8979_REG_CONTROL_RAW_DATA_MASK                BIT(3)
#define RT8979_REG_CONTROL_RAW_DATA_SHIFT               3
#define RT8979_REG_CONTROL_MANUAL_SW_MASK               BIT(2)
#define RT8979_REG_CONTROL_MANUAL_SW_SHIFT              2
#define RT8979_REG_CONTROL_WAIT_MASK                    BIT(1)
#define RT8979_REG_CONTROL_WAIT_SHIFT                   1
#define RT8979_REG_CONTROL_INT_MASK_MASK                BIT(0)
#define RT8979_REG_CONTROL_INT_MASK_SHIFT               0

/* reg=0x03, RC, interrupt */
#define RT8979_REG_INTERRUPT                            0x03

#define RT8979_REG_INTERRUPT_ADC_CHANGE_MASK            BIT(7)
#define RT8979_REG_INTERRUPT_ADC_CHANGE_SHIFT           7
#define RT8979_REG_INTERRUPT_RESERVED_ATTACH_MASK       BIT(6)
#define RT8979_REG_INTERRUPT_RESERVED_ATTACH_SHIFT      6
#define RT8979_REG_INTERRUPT_VBUS_CHANGE_MASK           BIT(5)
#define RT8979_REG_INTERRUPT_VBUS_CHANGE_SHIFT          5
#define RT8979_REG_INTERRUPT_DEVICE_CHANGE_MASK         BIT(4)
#define RT8979_REG_INTERRUPT_DEVICE_CHANGE_SHIFT        4
#define RT8979_REG_INTERRUPT_DETACH_MASK                BIT(1)
#define RT8979_REG_INTERRUPT_DETACH_SHIFT               1
#define RT8979_REG_INTERRUPT_ATTACH_MASK                BIT(0)
#define RT8979_REG_INTERRUPT_ATTACH_SHIFT               0

/* reg=0x04, RW, interrupt mask */
#define RT8979_REG_INTERRUPT_MASK                       0x04

#define RT8979_REG_INTERRUPT_MASK_ADC_CHANGE_MASK       BIT(7)
#define RT8979_REG_INTERRUPT_MASK_ADC_CHANGE_SHIFT      7
#define RT8979_REG_INTERRUPT_MASK_RESERVED_ATTACH_MASK  BIT(6)
#define RT8979_REG_INTERRUPT_MASK_RESERVED_ATTACH_SHIFT 6
#define RT8979_REG_INTERRUPT_MASK_VBUS_CHANGE_MASK      BIT(5)
#define RT8979_REG_INTERRUPT_MASK_VBUS_CHANGE_SHIFT     5
#define RT8979_REG_INTERRUPT_MASK_DEVICE_CHANGE_MASK    BIT(4)
#define RT8979_REG_INTERRUPT_MASK_DEVICE_CHANGE_SHIFT   4
#define RT8979_REG_INTERRUPT_MASK_DETACH_MASK           BIT(1)
#define RT8979_REG_INTERRUPT_MASK_DETACH_SHIFT          1
#define RT8979_REG_INTERRUPT_MASK_ATTACH_MASK           BIT(0)
#define RT8979_REG_INTERRUPT_MASK_ATTACH_SHIFT          0

/* reg=0x05, default=0x00, R, adc value */
#define RT8979_REG_ADC                                  0x05

#define RT8979_REG_ADC_VALUE_MASK                       (BIT(4) | BIT(3) | \
	BIT(2) | BIT(1) | BIT(0))
#define RT8979_REG_ADC_VALUE_SHIFT                      0

/* reg=0x06, RW, timing setting 1 */
#define RT8979_REG_TIMING_SET_1                         0x06

#define RT8979_REG_TIMING_SET_1_SW_WAIT_MASK  \
	(BIT(7) | BIT(6) | BIT(5) | BIT(4))
#define RT8979_REG_TIMING_SET_1_SW_WAIT_SHIFT           4
#define RT8979_REG_TIMING_SET_1_ADC_DET_TIME_MASK \
	(BIT(3) | BIT(2) | BIT(1) | BIT(0))
#define RT8979_REG_TIMING_SET_1_ADC_DET_TIME_SHIFT      0

/* reg=0x07, R, detach status */
#define RT8979_REG_DETACH_CONTROL                       0x07

#define RT8979_REG_DETACH_CONTROL_ACC_DETACH_MASK       BIT(0)
#define RT8979_REG_DETACH_CONTROL_ACC_DETACH_SHIFT      0

/* reg=0x08, R, device type list 1 of id & bcd detection */
#define RT8979_REG_DEVICE_TYPE_1                        0x08

#define RT8979_REG_DEVICE_TYPE_1_USBOTG_MASK            BIT(7)
#define RT8979_REG_DEVICE_TYPE_1_USBOTG_SHIFT           7
#define RT8979_REG_DEVICE_TYPE_1_DCP_MASK               BIT(6)
#define RT8979_REG_DEVICE_TYPE_1_DCP_SHIFT              6
#define RT8979_REG_DEVICE_TYPE_1_USB_CHARGER_MASK       BIT(5)
#define RT8979_REG_DEVICE_TYPE_1_USB_CHARGER_SHIFT      5
#define RT8979_REG_DEVICE_TYPE_1_UART_MASK              BIT(3)
#define RT8979_REG_DEVICE_TYPE_1_UART_SHIFT             3
#define RT8979_REG_DEVICE_TYPE_1_USB_MASK               BIT(2)
#define RT8979_REG_DEVICE_TYPE_1_USB_SHIFT              2
#define RT8979_REG_DEVICE_TYPE_1_JIG_RF_CALI_CP_MASK    BIT(1)
#define RT8979_REG_DEVICE_TYPE_1_JIG_RF_CALI_CP_SHIFT   1
#define RT8979_REG_DEVICE_TYPE_1_JIG_USBON_CP_MASK      BIT(0)
#define RT8979_REG_DEVICE_TYPE_1_JIG_USBON_CP_SHIFT     0

/* reg=0x09, R, device type list 2 of id & bcd detection */
#define RT8979_REG_DEVICE_TYPE_2                        0x09

#define RT8979_REG_DEVICE_TYPE_2_JIG_RF_CALI_MASK       BIT(7)
#define RT8979_REG_DEVICE_TYPE_2_JIG_RF_CALI_SHIFT      7
#define RT8979_REG_DEVICE_TYPE_2_JIG_BAT_DISCHG_MASK    BIT(6)
#define RT8979_REG_DEVICE_TYPE_2_JIG_BAT_DISCHG_SHIFT   6
#define RT8979_REG_DEVICE_TYPE_2_JIG_BAT_CHG_MASK       BIT(5)
#define RT8979_REG_DEVICE_TYPE_2_JIG_BAT_CHG_SHIFT      5
#define RT8979_REG_DEVICE_TYPE_2_FORCE_DN_WO_BAT_MASK   BIT(3)
#define RT8979_REG_DEVICE_TYPE_2_FORCE_DN_WO_BAT_SHIFT  3
#define RT8979_REG_DEVICE_TYPE_2_JIG_UART_ON_MASK       BIT(2)
#define RT8979_REG_DEVICE_TYPE_2_JIG_UART_ON_SHIFT      2
#define RT8979_REG_DEVICE_TYPE_2_FORCE_DN_WI_BAT_MASK   BIT(1)
#define RT8979_REG_DEVICE_TYPE_2_FORCE_DN_WI_BAT_SHIFT  1
#define RT8979_REG_DEVICE_TYPE_2_JIG_USBON_MASK         BIT(0)
#define RT8979_REG_DEVICE_TYPE_2_JIG_USBON_SHIFT        0

/* reg=0x0a, R, device type list 3 of id & bcd detection */
#define RT8979_REG_DEVICE_TYPE_3                        0x0a

#define RT8979_REG_DEVICE_TYPE_3_CUST_ACC_7_MASK        BIT(7)
#define RT8979_REG_DEVICE_TYPE_3_CUST_ACC_7_SHIFT       7
#define RT8979_REG_DEVICE_TYPE_3_CUST_ACC_6_MASK        BIT(6)
#define RT8979_REG_DEVICE_TYPE_3_CUST_ACC_6_SHIFT       6
#define RT8979_REG_DEVICE_TYPE_3_CUST_ACC_5_MASK        BIT(5)
#define RT8979_REG_DEVICE_TYPE_3_CUST_ACC_5_SHIFT       5
#define RT8979_REG_DEVICE_TYPE_3_CUST_ACC_4_MASK        BIT(4)
#define RT8979_REG_DEVICE_TYPE_3_CUST_ACC_4_SHIFT       4
#define RT8979_REG_DEVICE_TYPE_3_CUST_ACC_3_MASK        BIT(3)
#define RT8979_REG_DEVICE_TYPE_3_CUST_ACC_3_SHIFT       3
#define RT8979_REG_DEVICE_TYPE_3_CUST_ACC_2_MASK        BIT(2)
#define RT8979_REG_DEVICE_TYPE_3_CUST_ACC_2_SHIFT       2
#define RT8979_REG_DEVICE_TYPE_3_CUST_ACC_1_MASK        BIT(1)
#define RT8979_REG_DEVICE_TYPE_3_CUST_ACC_1_SHIFT       1
#define RT8979_REG_DEVICE_TYPE_3_PHONEOFF_CUR_MASK      BIT(0)
#define RT8979_REG_DEVICE_TYPE_3_PHONEOFF_CUR_SHIFT     0

/* reg=0x0b, RW manually switching control 1 */
#define RT8979_REG_MANUAL_SW_1                          0x0b

#define RT8979_REG_MANUAL_SW_1_DM_CON_SW_MASK \
	(BIT(7) | BIT(6) | BIT(5))
#define RT8979_REG_MANUAL_SW_1_DM_CON_SW_SHIFT          5
#define RT8979_REG_MANUAL_SW_1_DP_CON_SW_MASK \
	(BIT(4) | BIT(3) | BIT(2))
#define RT8979_REG_MANUAL_SW_1_DP_CON_SW_SHIFT          2
#define RT8979_REG_MANUAL_SW_1_ID_CON_SW_MASK           (BIT(1) | BIT(0))
#define RT8979_REG_MANUAL_SW_1_ID_CON_SW_SHIFT          0

/* reg=0x0c, RW, manually switching control 2 */
#define RT8979_REG_MANUAL_SW_2                          0x0c

#define RT8979_REG_MANUAL_SW_2_CHG_DET_MASK             BIT(2)
#define RT8979_REG_MANUAL_SW_2_CHG_DET_SHIFT            2
#define RT8979_REG_MANUAL_SW_2_BOOT_SW_MASK             BIT(1)
#define RT8979_REG_MANUAL_SW_2_BOOT_SW_SHIFT            1
#define RT8979_REG_MANUAL_SW_2_JIG_ON_MASK              BIT(0)
#define RT8979_REG_MANUAL_SW_2_JIG_ON_SHIFT             0

/* reg=0x0d, RW, muic timing setting 2 */
#define RT8979_REG_TIMING_SET_2                         0x0d

#define RT8979_REG_TIMING_SET_2_INTB_WATCHDOG_MASK      (BIT(7) | BIT(6))
#define RT8979_REG_TIMING_SET_2_INTB_WATCHDOG_SHIFT     6
#define RT8979_REG_TIMING_SET_2_DCD_TIMEOUT_SET_MASK    (BIT(5) | BIT(4))
#define RT8979_REG_TIMING_SET_2_DCD_TIMEOUT_SET_SHIFT   4
#define RT8979_REG_TIMING_SET_2_CHGDET_ONTIME_MASK      BIT(3)
#define RT8979_REG_TIMING_SET_2_CHGDET_ONTIME_SHIFT     3
#define RT8979_REG_TIMING_SET_2_PHONEOFF_WAITTIME_MASK  (BIT(2) | BIT(1) | \
	BIT(0))
#define RT8979_REG_TIMING_SET_2_PHONEOFF_WAITTIME_SHIFT 0

/* reg=0x0e, RW, control 2 */
#define RT8979_REG_CONTROL2                             0x0e

#define RT8979_REG_CONTROL2_ACCP_EN_MASK                BIT(7)
#define RT8979_REG_CONTROL2_ACCP_EN_SHIFT               7
#define RT8979_REG_CONTROL2_ACCP_AUTO_EN_MASK           BIT(6)
#define RT8979_REG_CONTROL2_ACCP_AUTO_EN_SHIFT          6
#define RT8979_REG_CONTROL2_ACCP_OSC_EN_MASK            BIT(5)
#define RT8979_REG_CONTROL2_ACCP_OSC_EN_SHIFT           5
#define RT8979_REG_CONTROL2_FM1_EN_MASK                 BIT(1)
#define RT8979_REG_CONTROL2_FM1_EN_SHIFT                1
#define RT8979_REG_CONTROL2_DCD_TIMEOUT_EN_MASK         BIT(0)
#define RT8979_REG_CONTROL2_DCD_TIMEOUT_EN_SHIFT        0

/* reg=0x0f, R, device type 4 */
#define RT8979_REG_DEVICE_TYPE_4                        0x0f

#define RT8979_REG_DEVICE_TYPE_4_ACCP_CHARGER_MASK      BIT(7)
#define RT8979_REG_DEVICE_TYPE_4_ACCP_CHARGER_SHIFT     7
#define RT8979_REG_DEVICE_TYPE_4_NONACCP_CHARGER_MASK   BIT(6)
#define RT8979_REG_DEVICE_TYPE_4_NONACCP_CHARGER_SHIFT  6

/* reg=0x10, RW, muic control 3 */
#define RT8979_REG_MUIC_CTRL_3                          0x10

#define RT8979_REG_MUIC_CTRL_3_VBUS_PD_MASK             BIT(7)
#define RT8979_REG_MUIC_CTRL_3_VBUS_PD_SHIFT            7
#define RT8979_REG_MUIC_CTRL_3_OVP_SEL_MASK             (BIT(5) | BIT(4))
#define RT8979_REG_MUIC_CTRL_3_OVP_SEL_SHIFT            4
#define RT8979_REG_MUIC_CTRL_3_ID_FLT_DEGLITCH_MASK     (BIT(3) | BIT(2))
#define RT8979_REG_MUIC_CTRL_3_ID_FLT_DEGLITCH_SHIFT    2

#define RT8979_REG_MUIC_CTRL_3_DISABLEID_FUNCTION       0x28

/* reg=0x11, RW, muic control 4 */
#define RT8979_REG_MUIC_CTRL_4                          0x11

#define RT8979_REG_MUIC_CTRL_4_IDFET_OCP_OFF_MASK       BIT(4)
#define RT8979_REG_MUIC_CTRL_4_IDFET_OCP_OFF_SHIFT      4
#define RT8979_REG_MUIC_CTRL_4_SWEN_IDBAT1_MASK         BIT(1)
#define RT8979_REG_MUIC_CTRL_4_SWEN_IDBAT1_SHIFT        1
#define RT8979_REG_MUIC_CTRL_4_SWEN_IDBAT2_MASK         BIT(0)
#define RT8979_REG_MUIC_CTRL_4_SWEN_IDBAT2_SHIFT        0

#define RT8979_REG_MUIC_CTRL_4_ENABLEID2_FUNCTION       0xFD

/* reg=0x12, R, muic status 1 */
#define RT8979_REG_MUIC_STATUS1                         0x12

#define RT8979_REG_MUIC_STATUS1_FMEN_MASK               BIT(5)
#define RT8979_REG_MUIC_STATUS1_FMEN_SHIFT              5
#define RT8979_REG_MUIC_STATUS1_CHGDET_MASK             BIT(4)
#define RT8979_REG_MUIC_STATUS1_CHGDET_SHIFT            4
#define RT8979_REG_MUIC_STATUS1_DCDT_MASK               BIT(3)
#define RT8979_REG_MUIC_STATUS1_DCDT_SHIFT              3
#define RT8979_REG_MUIC_STATUS1_VIN_UVLO_MASK           BIT(2)
#define RT8979_REG_MUIC_STATUS1_VIN_UVLO_SHIFT          2
#define RT8979_REG_MUIC_STATUS1_OTP_MASK                BIT(1)
#define RT8979_REG_MUIC_STATUS1_OTP_SHIFT               1
#define RT8979_REG_MUIC_STATUS1_VIN_OVP_MASK            BIT(0)
#define RT8979_REG_MUIC_STATUS1_VIN_OVP_SHIFT           0

/* reg=0x13, R, muic status 2 */
#define RT8979_REG_MUIC_STATUS2                         0x13

#define RT8979_REG_MUIC_STATUS2_USB_STATE_MASK          (BIT(6) | BIT(5) | \
	BIT(4))
#define RT8979_REG_MUIC_STATUS2_USB_STATE_SHIFT         4
#define RT8979_REG_MUIC_STATUS2_VAL_MASK                0x07
#define RT8979_REG_MUIC_STATUS2_ID_STATUS_MASK          (BIT(1) | BIT(0))
#define RT8979_REG_MUIC_STATUS2_ID_STATUS_SHIFT         0

/* reg=0x19, RWC, reset */
#define RT8979_REG_RESET                                0x19
#define RT8979_REG_RESET_ENTIRE_IC                      BIT(0)

/* reg=0x1f, RW, dcd */
#define RT8979_REG_DCD                                  0x1f
#define RT8979_REG_DCD_STATUS_INIT_VAL                  0x0c

/* reg=0x40, RW, scp status */
#define RT8979_REG_ACCP_STATUS                          0x40

#define RT8979_REG_ACCP_STATUS_DVC_MASK                 (BIT(7) | BIT(6))
#define RT8979_REG_ACCP_STATUS_DVC_SHIFT                6
#define RT8979_REG_ACCP_STATUS_ATTACH_MASK              BIT(0)
#define RT8979_REG_ACCP_STATUS_ATTACH_SHIFT             0
#define RT8979_ACCP_STATUS_MASK                         (BIT(7) | BIT(6))
#define RT8979_ACCP_STATUS_SLAVE_GOOD                   (BIT(7) | BIT(6))

/* reg=0x41, RWC, accp control register for starting communction */
#define RT8979_REG_ACCP_CNTL                            0x41

#define RT8979_REG_ACCP_CNTL_ENABLE_MASK                BIT(3)
#define RT8979_REG_ACCP_CNTL_ENABLE_SHIFT               3
#define RT8979_REG_ACCP_CNTL_MSTR_RST_MASK              BIT(2)
#define RT8979_REG_ACCP_CNTL_MSTR_RST_SHIFT             2
#define RT8979_REG_ACCP_CNTL_SNDCMD_MASK                BIT(0)
#define RT8979_REG_ACCP_CNTL_SNDCMD_SHIFT               0
#define RT8979_ACCP_CNTL_MASK                           (BIT(0) | BIT(2) | BIT(3))

/* reg=0x44, RW, accp command for transmission */
#define RT8979_REG_ACCP_CMD                             0x44

#define RT8979_ACCP_CMD_SBRRD                           0x0c
#define RT8979_ACCP_CMD_SBRWR                           0x0b

/* reg=0x47, RW, accp address for transmission */
#define RT8979_REG_ACCP_ADDR                            0x47
#define RT8979_REG_ACCP_ADDR_VAL1                       0x00

/* reg=0x48, RW, accp data for transmission or received data 1 */
#define RT8979_REG_ACCP_DATA                            0x48

/* reg=0x59, default=0x08, R, accp interrupt status 1 */
#define RT8979_REG_ACCP_INTERRUPT1                      0x59

#define RT8979_REG_ACCP_INTERRUPT1_CMDCPL_MASK          BIT(7)
#define RT8979_REG_ACCP_INTERRUPT1_CMDCPL_SHIFT         7
#define RT8979_REG_ACCP_INTERRUPT1_ACK_MASK             BIT(6)
#define RT8979_REG_ACCP_INTERRUPT1_ACK_SHIFT            6
#define RT8979_REG_ACCP_INTERRUPT1_NACK_MASK            BIT(4)
#define RT8979_REG_ACCP_INTERRUPT1_NACK_SHIFT           4
#define RT8979_REG_ACCP_INTERRUPT1_CRCPAR_MASK          BIT(3)
#define RT8979_REG_ACCP_INTERRUPT1_CRCPAR_SHIFT         3

/* reg=0x5a, default=0x08, R, accp interrupt status 2 */
#define RT8979_REG_ACCP_INTERRUPT2                      0x5a

#define RT8979_REG_ACCP_INTERRUPT2_CRCRX_MASK           BIT(4)
#define RT8979_REG_ACCP_INTERRUPT2_CRCRX_SHIFT          4
#define RT8979_REG_ACCP_INTERRUPT2_PAPRX_MASK           BIT(3)
#define RT8979_REG_ACCP_INTERRUPT2_PAPRX_SHIFT          3
#define RT8979_REG_ACCP_INTERRUPT2_PROSTAT_MASK         BIT(1)
#define RT8979_REG_ACCP_INTERRUPT2_PROSTAT_SHIFT        1
#define RT8979_REG_ACCP_INTERRUPT2_DSDVCSTAT_MASK       BIT(0)
#define RT8979_REG_ACCP_INTERRUPT2_DSDVCSTAT_SHIFT      0

/* reg=0x5b, default=0x08, R, accp interrupt mask 1 */
#define RT8979_REG_ACCP_INTERRUPT_MASK1                 0x5b

#define RT8979_REG_ACCP_INTERRUPT_MASK1_CMDCPL_MASK     BIT(7)
#define RT8979_REG_ACCP_INTERRUPT_MASK1_CMDCPL_SHIFT    7
#define RT8979_REG_ACCP_INTERRUPT_MASK1_ACK_MASK        BIT(6)
#define RT8979_REG_ACCP_INTERRUPT_MASK1_ACK_SHIFT       6
#define RT8979_REG_ACCP_INTERRUPT_MASK1_NACK_MASK       BIT(4)
#define RT8979_REG_ACCP_INTERRUPT_MASK1_NACK_SHIFT      4
#define RT8979_REG_ACCP_INTERRUPT_MASK1_CRCPAR_MASK     BIT(3)
#define RT8979_REG_ACCP_INTERRUPT_MASK1_CRCPAR_SHIFT    3

/* reg=0x5c, default=0x08, R, accp interrupt mask 2 */
#define RT8979_REG_ACCP_INTERRUPT_MASK2                 0x5c

#define RT8979_REG_ACCP_INTERRUPT_MASK2_CRCRX_MASK      BIT(4)
#define RT8979_REG_ACCP_INTERRUPT_MASK2_CRCRX_SHIFT     4
#define RT8979_REG_ACCP_INTERRUPT_MASK2_PARRX_MASK      BIT(3)
#define RT8979_REG_ACCP_INTERRUPT_MASK2_PARRX_SHIFT     3
#define RT8979_REG_ACCP_INTERRUPT_MASK2_PROSTAT_MASK    BIT(1)
#define RT8979_REG_ACCP_INTERRUPT_MASK2_PROSTAT_SHIFT   1
#define RT8979_REG_ACCP_INTERRUPT_MASK2_DSDVCSTAT_MASK  BIT(0)
#define RT8979_REG_ACCP_INTERRUPT_MASK2_DSDVCSTAT_SHIFT 0

#define RT8979_REG_ALLMASK                              0xFF

/* reg=0xa0 R */
#define RT8979_REG_EXT3                                 0xa0
#define RT8979_REG_TEST_MODE                            0xa0
#define RT8979_REG_EXT3_VAL                             0x38
#define RT8979_REG_TEST_MODE_VAL1                       0x38
#define RT8979_REG_TEST_MODE_DEFAULT_VAL                0x00

/* reg=0xa1 RW */
#define RT8979_REG_TM_MUIC1                             0xa1

/* reg=0xa4, R */
#define RT8979_REG_USBCHGEN                             0xa4

#define RT8979_REG_USBCHGEN_DETACH_STAGE1               0x86
#define RT8979_REG_USBCHGEN_DETACH_STAGE2               0xc6
#define RT8979_REG_USBCHGEN_ACCPDET_STAGE1              BIT(6)

/* reg=0xa7, R */
#define RT8979_REG_MUIC_EXT2                            0xa7

/* reg=0xab, R */
#define RT8979_REG_MUIC_EXT1                            0xab

/* reg=0xd0, R */
#define RT8979_REG_EFUSE_PRETRIM_DATA                   0xd0
#define RT8979_REG_EFUSE_PRETRIM_DATA_VAL               0x08

/* reg=0xd1, R */
#define RT8979_REG_EFUSE_CTRL                           0xd1
#define RT8979_REG_EFUSE_CTRL_VAL                       0x0a

/* reg=0xd2, R */
#define RT8979_REG_EFUSE_PRETRIM_ENABLE                 0xd2

#define RT8979_REG_EFUSE_PRETRIM_ENABLE_VAL             0x20
#define RT8979_REG_EFUSE_PRETRIM_ENABLE_VAL1            0x40

/* reg=0xd3, default=0x00, R */
#define RT8979_REG_EFUSE_READ_DATA                      0xd3

#endif /* _RT8979_REG_H_ */
