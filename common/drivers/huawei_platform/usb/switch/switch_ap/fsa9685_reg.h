/*
 * fsa9685_reg.h
 *
 * Register head file for fsa9685
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

#ifndef _FSA9685_REG_H_
#define _FSA9685_REG_H_

#include <linux/bitops.h>

/* I2C client addresses */
#define FSA9683_I2C_ADDR                                 0x4c
#define CBTL9689_I2C_ADDR                                0x2e
#define FSA9685_I2C_ADDR                                 0x25
#define RT8979_I2C_ADDR                                  0x25

/* reg=0x01, R, device id */
#define FSA9685_REG_DEVICE_ID                            0x01

#define FSA9685_REG_DEVICE_ID_VERSION_ID_MASK  \
	(BIT(7) | BIT(6) | BIT(5) | BIT(4) | BIT(3))
#define FSA9685_REG_DEVICE_ID_VERSION_ID_SHIFT      3
#define FSA9685_REG_DEVICE_ID_VENDOR_ID_MASK        (BIT(2) | BIT(1) | BIT(0))
#define FSA9685_REG_DEVICE_ID_VENDOR_ID_SHIFT       0

#define FAS9685_VERSION_ID_BIT_MASK  (FSA9685_REG_DEVICE_ID_VERSION_ID_MASK)
#define FAS9685_VERSION_ID_BIT_SHIFT (FSA9685_REG_DEVICE_ID_VERSION_ID_SHIFT)
#define FAS9685_VENDOR_ID_BIT_MASK   (FSA9685_REG_DEVICE_ID_VENDOR_ID_MASK)
#define FAS9685_VENDOR_ID_BIT_SHIFT  (FSA9685_REG_DEVICE_ID_VENDOR_ID_SHIFT)

/* reg=0x02, RW, control 1 */
#define FSA9685_REG_CONTROL                              0x02

#define FSA9685_REG_CONTROL_SW_OPEN_MASK                 BIT(4)
#define FSA9685_REG_CONTROL_SW_OPEN_SHIFT                4
#define FSA9685_REG_CONTROL_RAW_DATA_MASK                BIT(3)
#define FSA9685_REG_CONTROL_RAW_DATA_SHIFT               3
#define FSA9685_REG_CONTROL_MANUAL_SW_MASK               BIT(2)
#define FSA9685_REG_CONTROL_MANUAL_SW_SHIFT              2
#define FSA9685_REG_CONTROL_WAIT_MASK                    BIT(1)
#define FSA9685_REG_CONTROL_WAIT_SHIFT                   1
#define FSA9685_REG_CONTROL_INT_MASK_MASK                BIT(0)
#define FSA9685_REG_CONTROL_INT_MASK_SHIFT               0

#define FSA9685_SWITCH_OPEN                              BIT(4)
#define FSA9685_RAW_DATA                                 BIT(3)
#define FSA9685_MANUAL_SW                                BIT(2)
#define FSA9685_WAIT                                     BIT(1)
#define FSA9685_INT_MASK                                 BIT(0)

/* reg=0x03, RC, interrupt */
#define FSA9685_REG_INTERRUPT                            0x03

#define FSA9685_REG_INTERRUPT_ADC_CHANGE_MASK            BIT(7)
#define FSA9685_REG_INTERRUPT_ADC_CHANGE_SHIFT           7
#define FSA9685_REG_INTERRUPT_RESERVED_ATTACH_MASK       BIT(6)
#define FSA9685_REG_INTERRUPT_RESERVED_ATTACH_SHIFT      6
#define FSA9685_REG_INTERRUPT_VBUS_CHANGE_MASK           BIT(5)
#define FSA9685_REG_INTERRUPT_VBUS_CHANGE_SHIFT          5
#define FSA9685_REG_INTERRUPT_DEVICE_CHANGE_MASK         BIT(4)
#define FSA9685_REG_INTERRUPT_DEVICE_CHANGE_SHIFT        4
#define FSA9685_REG_INTERRUPT_DETACH_MASK                BIT(1)
#define FSA9685_REG_INTERRUPT_DETACH_SHIFT               1
#define FSA9685_REG_INTERRUPT_ATTACH_MASK                BIT(0)
#define FSA9685_REG_INTERRUPT_ATTACH_SHIFT               0

#define FSA9685_ADC_CHANGE                               BIT(7)
#define FSA9685_RESERVED_ATTACH                          BIT(6)
#define FSA9685_VBUS_CHANGE                              BIT(5)
#define FSA9685_DEVICE_CHANGE                            BIT(4)
#define FSA9685_DETACH                                   BIT(1)
#define FSA9685_ATTACH                                   BIT(0)

/* reg=0x04, RW, interrupt mask */
#define FSA9685_REG_INTERRUPT_MASK                       0x04

#define FSA9685_REG_INTERRUPT_MASK_ADC_CHANGE_MASK       BIT(7)
#define FSA9685_REG_INTERRUPT_MASK_ADC_CHANGE_SHIFT      7
#define FSA9685_REG_INTERRUPT_MASK_RESERVED_ATTACH_MASK  BIT(6)
#define FSA9685_REG_INTERRUPT_MASK_RESERVED_ATTACH_SHIFT 6
#define FSA9685_REG_INTERRUPT_MASK_VBUS_CHANGE_MASK      BIT(5)
#define FSA9685_REG_INTERRUPT_MASK_VBUS_CHANGE_SHIFT     5
#define FSA9685_REG_INTERRUPT_MASK_DEVICE_CHANGE_MASK    BIT(4)
#define FSA9685_REG_INTERRUPT_MASK_DEVICE_CHANGE_SHIFT   4
#define FSA9685_REG_INTERRUPT_MASK_DETACH_MASK           BIT(1)
#define FSA9685_REG_INTERRUPT_MASK_DETACH_SHIFT          1
#define FSA9685_REG_INTERRUPT_MASK_ATTACH_MASK           BIT(0)
#define FSA9685_REG_INTERRUPT_MASK_ATTACH_SHIFT          0

/* reg=0x05, default=0x00, R, adc value */
#define FSA9685_REG_ADC                                  0x05

/* reg=0x06, RW, timing setting 1 */
#define FSA9685_REG_TIMING_SET_1                         0x06

#define FSA9685_REG_TIMING_SET_1_SW_WAIT_MASK  \
	(BIT(7) | BIT(6) | BIT(5) | BIT(4))
#define FSA9685_REG_TIMING_SET_1_SW_WAIT_SHIFT           4
#define FSA9685_REG_TIMING_SET_1_ADC_DET_TIME_MASK \
	(BIT(3) | BIT(2) | BIT(1) | BIT(0))
#define FSA9685_REG_TIMING_SET_1_ADC_DET_TIME_SHIFT      0

#define FSA9685_SW_WAIT_10MS                             0
#define FSA9685_SW_WAIT_30MS                             1
#define FSA9685_SW_WAIT_50MS                             2
#define FSA9685_SW_WAIT_70MS                             3
#define FSA9685_SW_WAIT_90MS                             4
#define FSA9685_SW_WAIT_110MS                            5
#define FSA9685_SW_WAIT_130MS                            6
#define FSA9685_SW_WAIT_150MS                            7
#define FSA9685_SW_WAIT_170MS                            8
#define FSA9685_SW_WAIT_190MS                            9
#define FSA9685_SW_WAIT_210MS                            10

#define FSA9685_ADC_DET_TIME_50MS                        0
#define FSA9685_ADC_DET_TIME_100MS                       1
#define FSA9685_ADC_DET_TIME_150MS                       2
#define FSA9685_ADC_DET_TIME_200MS                       3
#define FSA9685_ADC_DET_TIME_300MS                       4
#define FSA9685_ADC_DET_TIME_400MS                       5
#define FSA9685_ADC_DET_TIME_500MS                       6
#define FSA9685_ADC_DET_TIME_600MS                       7
#define FSA9685_ADC_DET_TIME_700MS                       8
#define FSA9685_ADC_DET_TIME_800MS                       9
#define FSA9685_ADC_DET_TIME_900MS                       10
#define FSA9685_ADC_DET_TIME_1000MS                      11

/* reg=0x07, R, detach status */
#define FSA9685_REG_DETACH_CONTROL                       0x07

#define FSA9685_REG_DETACH_CONTROL_ACC_DETACH_MASK       BIT(0)
#define FSA9685_REG_DETACH_CONTROL_ACC_DETACH_SHIFT      0

/* reg=0x08, R, device type list 1 of id & bcd detection */
#define FSA9685_REG_DEVICE_TYPE_1                        0x08

#define FSA9685_REG_DEVICE_TYPE_1_USBOTG_MASK            BIT(7)
#define FSA9685_REG_DEVICE_TYPE_1_USBOTG_SHIFT           7
#define FSA9685_REG_DEVICE_TYPE_1_DCP_MASK               BIT(6)
#define FSA9685_REG_DEVICE_TYPE_1_DCP_SHIFT              6
#define FSA9685_REG_DEVICE_TYPE_1_USB_CHARGER_MASK       BIT(5)
#define FSA9685_REG_DEVICE_TYPE_1_USB_CHARGER_SHIFT      5
#define FSA9685_REG_DEVICE_TYPE_1_UART_MASK              BIT(3)
#define FSA9685_REG_DEVICE_TYPE_1_UART_SHIFT             3
#define FSA9685_REG_DEVICE_TYPE_1_USB_MASK               BIT(2)
#define FSA9685_REG_DEVICE_TYPE_1_USB_SHIFT              2
#define FSA9685_REG_DEVICE_TYPE_1_JIG_RF_CALI_CP_MASK    BIT(1)
#define FSA9685_REG_DEVICE_TYPE_1_JIG_RF_CALI_CP_SHIFT   1
#define FSA9685_REG_DEVICE_TYPE_1_JIG_USBON_CP_MASK      BIT(0)
#define FSA9685_REG_DEVICE_TYPE_1_JIG_USBON_CP_SHIFT     0

#define FSA9685_USBOTG_DETECTED                          BIT(7)
#define FSA9685_DCP_DETECTED                             BIT(6)
#define FSA9685_CDP_DETECTED                             BIT(5)
#define FSA9685_UART_DETECTED                            BIT(3)
#define FSA9685_USB_DETECTED                             BIT(2)
#define FSA9685_FC_RF_DETECTED                           BIT(1)
#define FSA9685_FC_USB_DETECTED                          BIT(0)

#define FSA9685_DEVICE_TYPE1_UNAVAILABLE                 0x0a

/* reg=0x09, R, device type list 2 of id & bcd detection */
#define FSA9685_REG_DEVICE_TYPE_2                        0x09

#define FSA9685_REG_DEVICE_TYPE_2_JIG_RF_CALI_MASK       BIT(7)
#define FSA9685_REG_DEVICE_TYPE_2_JIG_RF_CALI_SHIFT      7
#define FSA9685_REG_DEVICE_TYPE_2_JIG_BAT_DISCHG_MASK    BIT(6)
#define FSA9685_REG_DEVICE_TYPE_2_JIG_BAT_DISCHG_SHIFT   6
#define FSA9685_REG_DEVICE_TYPE_2_JIG_BAT_CHG_MASK       BIT(5)
#define FSA9685_REG_DEVICE_TYPE_2_JIG_BAT_CHG_SHIFT      5
#define FSA9685_REG_DEVICE_TYPE_2_FORCE_DN_WO_BAT_MASK   BIT(3)
#define FSA9685_REG_DEVICE_TYPE_2_FORCE_DN_WO_BAT_SHIFT  3
#define FSA9685_REG_DEVICE_TYPE_2_JIG_UART_ON_MASK       BIT(2)
#define FSA9685_REG_DEVICE_TYPE_2_JIG_UART_ON_SHIFT      2
#define FSA9685_REG_DEVICE_TYPE_2_FORCE_DN_WI_BAT_MASK   BIT(1)
#define FSA9685_REG_DEVICE_TYPE_2_FORCE_DN_WI_BAT_SHIFT  1
#define FSA9685_REG_DEVICE_TYPE_2_JIG_USBON_MASK         BIT(0)
#define FSA9685_REG_DEVICE_TYPE_2_JIG_USBON_SHIFT        0

#define FSA9685_JIG_UART                                 BIT(2)
#define FSA9685_DEVICE_TYPE2_UNAVAILABLE                 0xf8

/* reg=0x0a, R, device type list 3 of id & bcd detection */
#define FSA9685_REG_DEVICE_TYPE_3                        0x0a

#define FSA9685_REG_DEVICE_TYPE_3_CUST_ACC_7_MASK        BIT(7)
#define FSA9685_REG_DEVICE_TYPE_3_CUST_ACC_7_SHIFT       7
#define FSA9685_REG_DEVICE_TYPE_3_CUST_ACC_6_MASK        BIT(6)
#define FSA9685_REG_DEVICE_TYPE_3_CUST_ACC_6_SHIFT       6
#define FSA9685_REG_DEVICE_TYPE_3_CUST_ACC_5_MASK        BIT(5)
#define FSA9685_REG_DEVICE_TYPE_3_CUST_ACC_5_SHIFT       5
#define FSA9685_REG_DEVICE_TYPE_3_CUST_ACC_4_MASK        BIT(4)
#define FSA9685_REG_DEVICE_TYPE_3_CUST_ACC_4_SHIFT       4
#define FSA9685_REG_DEVICE_TYPE_3_CUST_ACC_3_MASK        BIT(3)
#define FSA9685_REG_DEVICE_TYPE_3_CUST_ACC_3_SHIFT       3
#define FSA9685_REG_DEVICE_TYPE_3_CUST_ACC_2_MASK        BIT(2)
#define FSA9685_REG_DEVICE_TYPE_3_CUST_ACC_2_SHIFT       2
#define FSA9685_REG_DEVICE_TYPE_3_CUST_ACC_1_MASK        BIT(1)
#define FSA9685_REG_DEVICE_TYPE_3_CUST_ACC_1_SHIFT       1
#define FSA9685_REG_DEVICE_TYPE_3_PHONEOFF_CUR_MASK      BIT(0)
#define FSA9685_REG_DEVICE_TYPE_3_PHONEOFF_CUR_SHIFT     0

#define FSA9685_CUSTOMER_ACCESSORY7                      BIT(7)
#define FSA9685_CUSTOMER_ACCESSORY6                      BIT(6)
#define FSA9685_CUSTOMER_ACCESSORY5                      BIT(5)
#define FSA9685_FM8_ACCESSORY                            BIT(0)
#define FSA9685_DEVICE_TYPE3_UNAVAILABLE                 0x5e

/* reg=0x0b, RW manually switching control 1 */
#define FSA9685_REG_MANUAL_SW_1                          0x0b

#define FSA9685_REG_MANUAL_SW_1_DM_CON_SW_MASK \
	(BIT(7) | BIT(6) | BIT(5))
#define FSA9685_REG_MANUAL_SW_1_DM_CON_SW_SHIFT          5
#define FSA9685_REG_MANUAL_SW_1_DP_CON_SW_MASK \
	(BIT(4) | BIT(3) | BIT(2))
#define FSA9685_REG_MANUAL_SW_1_DP_CON_SW_SHIFT          2
#define FSA9685_REG_MANUAL_SW_1_ID_CON_SW_MASK           (BIT(1) | BIT(0))
#define FSA9685_REG_MANUAL_SW_1_ID_CON_SW_SHIFT          0

#define FSA9685_DM_CON_SW_OPEN_ALL_SW                    0
#define FSA9685_DM_CON_SW_TO_USB1                        1
#define FSA9685_DM_CON_SW_TO_USB2                        2
#define FSA9685_DM_CON_SW_TO_UART                        3

#define FSA9685_DP_CON_SW_OPEN_ALL_SW                    0
#define FSA9685_DP_CON_SW_TO_USB1                        1
#define FSA9685_DP_CON_SW_TO_USB2                        2
#define FSA9685_DP_CON_SW_TO_UART                        3

#define FSA9685_ID_CON_SW_OPEN_ALL_SW                    0
#define FSA9685_ID_CON_SW_TO_VBAT                        1
#define FSA9685_ID_CON_SW_TO_ID_BYPASS                   2
#define FSA9685_ID_CON_SW_TO_CBUS                        3

/* reg=0x0c, RW, manually switching control 2 */
#define FSA9685_REG_MANUAL_SW_2                          0x0c

#define FSA9685_REG_MANUAL_SW_2_CHG_DET_MASK             BIT(2)
#define FSA9685_REG_MANUAL_SW_2_CHG_DET_SHIFT            2
#define FSA9685_REG_MANUAL_SW_2_BOOT_SW_MASK             BIT(1)
#define FSA9685_REG_MANUAL_SW_2_BOOT_SW_SHIFT            1
#define FSA9685_REG_MANUAL_SW_2_JIG_ON_MASK              BIT(0)
#define FSA9685_REG_MANUAL_SW_2_JIG_ON_SHIFT             0

#define FSA9685_REG_JIG_MASK                             0x01

#define FSA9683_REG_JIG_DEFAULT_DOWN                     0x02
#define FSA9683_REG_JIG_UP                               0x03

/* reg=0x0d, RW, timing setting 2 */
#define FSA9685_REG_TIMING_SET_2                         0x0d

#define FSA9685_REG_TIMING_SET_2_PHONEOFF_WAITTIME_MASK  (BIT(2) | \
	BIT(1) | BIT(0))
#define FSA9685_REG_TIMING_SET_2_PHONEOFF_WAITTIME_SHIFT 0

/* reg=0x0e, RW, control 2 */
#define FSA9685_REG_CONTROL2                             0x0e

#define FSA9685_REG_CONTROL2_ACCP_EN_MASK                BIT(7)
#define FSA9685_REG_CONTROL2_ACCP_EN_SHIFT               7
#define FSA9685_REG_CONTROL2_ACCP_AUTO_EN_MASK           BIT(6)
#define FSA9685_REG_CONTROL2_ACCP_AUTO_EN_SHIFT          6
#define FSA9685_REG_CONTROL2_ACCP_OSC_EN_MASK            BIT(5)
#define FSA9685_REG_CONTROL2_ACCP_OSC_EN_SHIFT           5
#define FSA9685_REG_CONTROL2_FM1_EN_MASK                 BIT(1)
#define FSA9685_REG_CONTROL2_FM1_EN_SHIFT                1
#define FSA9685_REG_CONTROL2_DCD_TIMEOUT_EN_MASK         BIT(0)
#define FSA9685_REG_CONTROL2_DCD_TIMEOUT_EN_SHIFT        0

#define FSA9685_DCD_TIME_OUT_MASK                        BIT(0)

#define FSA9685_ACCP_DISABLE                             (0 << 7)
#define FSA9685_ACCP_ENABLE                              BIT(7)

#define FSA9685_ACCP_AUTO_DISABLE                        (0 << 6)
#define FSA9685_ACCP_AUTO_ENABLE                         BIT(6)

#define FSA9685_ACCP_OSC_DISABLE                         (0 << 5)
#define FSA9685_ACCP_OSC_ENABLE                          BIT(5)

/* reg=0x0f, R, device type 4 */
#define FSA9685_REG_DEVICE_TYPE_4                        0x0f

#define FSA9685_REG_DEVICE_TYPE_4_ACCP_CHARGER_MASK      BIT(7)
#define FSA9685_REG_DEVICE_TYPE_4_ACCP_CHARGER_SHIFT     7
#define FSA9685_REG_DEVICE_TYPE_4_NONACCP_CHARGER_MASK   BIT(6)
#define FSA9685_REG_DEVICE_TYPE_4_NONACCP_CHARGER_SHIFT  6

#define FSA9685_ACCP_CHARGER_DET                         BIT(7)

/* reg=0x19, RWC, reset */
#define FSA9685_REG_RESET                                0x19

#define FSA9685_RESET_CHIP                               0x89

#define FSA9685_REG_RESET_RESET_MASK                     BIT(0)
#define FSA9685_REG_RESET_RESET_SHIFT                    0

#define FSA9685_REG_RESET_ENTIRE_IC                      BIT(0)

/* reg=0x1b, R, vbus status */
#define FSA9685_REG_VBUS_STATUS                          0x1b

/* reg=0x1f, RW, dcd */
#define FSA9685_REG_DCD                                  0x1f
#define FSA9685_REG_DCD_STATUS_INIT_VAL                  0x0c

/* reg=0x30, RW, watchdog control */
#define FSA9685_REG_WD_CTRL                              0x30

#define FSA9685_REG_WD_CTRL_JIG_MANUAL_EN_MASK           BIT(2)
#define FSA9685_REG_WD_CTRL_JIG_MANUAL_EN_SHIFT          2

#define FSA9685_WD_CTRL_JIG_MANUAL_EN                    BIT(2)

/* reg=0x40, RW, scp status */
#define FSA9685_REG_ACCP_STATUS                          0x40

#define FSA9685_REG_ACCP_STATUS_DVC_MASK                 (BIT(7) | BIT(6))
#define FSA9685_REG_ACCP_STATUS_DVC_SHIFT                6
#define FSA9685_REG_ACCP_STATUS_ATTACH_MASK              BIT(0)
#define FSA9685_REG_ACCP_STATUS_ATTACH_SHIFT             0

#define FSA9688_ACCP_STATUS_MASK                         (BIT(7) | \
	BIT(6) | BIT(0))
#define FSA9688_ACCP_STATUS_SLAVE_GOOD                   (BIT(7) | \
	BIT(6) | BIT(0))
#define FAS9685_ACCP_SLAVE_DET                           (BIT(7) | \
	BIT(6))
#define FSA9685_ACCP_DEV_ATTACH                          BIT(0)

/* reg=0x41, RWC, accp control register for starting communction */
#define FSA9685_REG_ACCP_CNTL                            0x41

#define FSA9685_REG_ACCP_CNTL_ENABLE_MASK                BIT(3)
#define FSA9685_REG_ACCP_CNTL_ENABLE_SHIFT               3
#define FSA9685_REG_ACCP_CNTL_MSTR_RST_MASK              BIT(2)
#define FSA9685_REG_ACCP_CNTL_MSTR_RST_SHIFT             2
#define FSA9685_REG_ACCP_CNTL_SNDCMD_MASK                BIT(0)
#define FSA9685_REG_ACCP_CNTL_SNDCMD_SHIFT               0

#define FSA9685_ACCP_IS_ENABLE                           BIT(3)
#define FSA9685_ACCP_MSTR_RST                            BIT(2)
#define FAS9685_ACCP_SENDCMD                             BIT(0)
#define FAS9685_ACCP_CNTL_MASK                           (BIT(0) | \
	BIT(2) | BIT(3))

/* reg=0x44, RW, accp command for transmission */
#define FSA9685_REG_ACCP_CMD                             0x44

#define FSA9685_ACCP_CMD_SBRRD                           0x0c
#define FSA9685_ACCP_CMD_SBRWR                           0x0b

/* reg=0x47, RW, accp address for transmission */
#define FSA9685_REG_ACCP_ADDR                            0x47

/* reg=0x48, RW, accp data for transmission or received data 1 */
#define FSA9685_REG_ACCP_DATA                            0x48

/* reg=0x59, default=0x08, R, accp interrupt status 1 */
#define FSA9685_REG_ACCP_INTERRUPT1                      0x59

#define FSA9685_REG_ACCP_INTERRUPT1_CMDCPL_MASK          BIT(7)
#define FSA9685_REG_ACCP_INTERRUPT1_CMDCPL_SHIFT         7
#define FSA9685_REG_ACCP_INTERRUPT1_ACK_MASK             BIT(6)
#define FSA9685_REG_ACCP_INTERRUPT1_ACK_SHIFT            6
#define FSA9685_REG_ACCP_INTERRUPT1_NACK_MASK            BIT(4)
#define FSA9685_REG_ACCP_INTERRUPT1_NACK_SHIFT           4
#define FSA9685_REG_ACCP_INTERRUPT1_CRCPAR_MASK          BIT(3)
#define FSA9685_REG_ACCP_INTERRUPT1_CRCPAR_SHIFT         3

#define FAS9685_CMDCPL                                   BIT(7)
#define FAS9685_ACK                                      BIT(6)
#define FAS9685_NACK                                     BIT(4)
#define FAS9685_CRCPAR                                   BIT(3)

/* reg=0x5a, default=0x08, R, accp interrupt status 2 */
#define FSA9685_REG_ACCP_INTERRUPT2                      0x5a

#define FSA9685_REG_ACCP_INTERRUPT2_CRCRX_MASK           BIT(4)
#define FSA9685_REG_ACCP_INTERRUPT2_CRCRX_SHIFT          4
#define FSA9685_REG_ACCP_INTERRUPT2_PAPRX_MASK           BIT(3)
#define FSA9685_REG_ACCP_INTERRUPT2_PAPRX_SHIFT          3
#define FSA9685_REG_ACCP_INTERRUPT2_PROSTAT_MASK         BIT(1)
#define FSA9685_REG_ACCP_INTERRUPT2_PROSTAT_SHIFT        1
#define FSA9685_REG_ACCP_INTERRUPT2_DSDVCSTAT_MASK       BIT(0)
#define FSA9685_REG_ACCP_INTERRUPT2_DSDVCSTAT_SHIFT      0

#define FAS9685_CRCRX                                    BIT(4)
#define FAS9685_PARRX                                    BIT(3)
#define FAS9685_PROSTAT                                  BIT(1)
#define FAS9685_DSDVCSTAT                                BIT(0)

/* reg=0x5b, default=0x08, R, accp interrupt mask 1 */
#define FSA9685_REG_ACCP_INTERRUPT_MASK1                 0x5b

#define FSA9685_REG_ACCP_INTERRUPT_MASK1_CMDCPL_MASK     BIT(7)
#define FSA9685_REG_ACCP_INTERRUPT_MASK1_CMDCPL_SHIFT    7
#define FSA9685_REG_ACCP_INTERRUPT_MASK1_ACK_MASK        BIT(6)
#define FSA9685_REG_ACCP_INTERRUPT_MASK1_ACK_SHIFT       6
#define FSA9685_REG_ACCP_INTERRUPT_MASK1_NACK_MASK       BIT(4)
#define FSA9685_REG_ACCP_INTERRUPT_MASK1_NACK_SHIFT      4
#define FSA9685_REG_ACCP_INTERRUPT_MASK1_CRCPAR_MASK     BIT(3)
#define FSA9685_REG_ACCP_INTERRUPT_MASK1_CRCPAR_SHIFT    3

/* reg=0x5c, default=0x08, R, accp interrupt mask 2 */
#define FSA9685_REG_ACCP_INTERRUPT_MASK2                 0x5c

#define FSA9685_REG_ACCP_INTERRUPT_MASK2_CRCRX_MASK      BIT(4)
#define FSA9685_REG_ACCP_INTERRUPT_MASK2_CRCRX_SHIFT     4
#define FSA9685_REG_ACCP_INTERRUPT_MASK2_PARRX_MASK      BIT(3)
#define FSA9685_REG_ACCP_INTERRUPT_MASK2_PARRX_SHIFT     3
#define FSA9685_REG_ACCP_INTERRUPT_MASK2_PROSTAT_MASK    BIT(1)
#define FSA9685_REG_ACCP_INTERRUPT_MASK2_PROSTAT_SHIFT   1
#define FSA9685_REG_ACCP_INTERRUPT_MASK2_DSDVCSTAT_MASK  BIT(0)
#define FSA9685_REG_ACCP_INTERRUPT_MASK2_DSDVCSTAT_SHIFT 0

#define FSA9685_REG_ALLMASK                              0xFF

#endif /* FSA9685_REG_H */
