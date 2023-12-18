/*
 * switch_chip_common.h
 *
 * switch_chip_common header file
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

#ifndef _SWITCH_CHIP_COMMON_
#define _SWITCH_CHIP_COMMON_

#define ENABLE                                1
#define DISABLE                               0

/* accp related definitions */
#define ACCP_ADAPTOR_DETECT_OTHER             (-1)
#define ACCP_ADAPTOR_DETECT_SUCC              0
#define ACCP_ADAPTOR_DETECT_FAIL              1
#define ACCP_DETECT_MAX_COUT                  20
#define ACCP_POLL_TIME                        100 /* ms */
#define ACCP_RETRY_MAX_TIMES                  3

#define ADAPTOR_BC12_TYPE_MAX_CHECK_TIME      100
#define WAIT_FOR_BC12_DELAY                   5
#define ACCP_NOT_PREPARE_OK                   (-1)
#define ACCP_PREPARE_OK                       0

#define SET_DCDTOUT_FAIL                      (-1)
#define SET_DCDTOUT_SUCC                      0
#define MUIC_ACCP_INT_MAX_COUNT               5
#define ACCP_MAX_TRYCOUNT                     2

/* usb state */
#define SWITCH_CHIP_OPEN                      0
#define SWITCH_CHIP_USB1_ID_TO_IDBYPASS       1
#define SWITCH_CHIP_USB2_ID_TO_IDBYPASS       2
#define SWITCH_CHIP_UART_ID_TO_IDBYPASS       3
#define SWITCH_CHIP_USB1_ID_TO_VBAT           5

#define SWITCH_CHIP_RD_BUF_SIZE               32
#define SWITCH_CHIP_WR_BUF_SIZE               64

/* jig pin control for battery cut test */
#define SWITCH_CHIP_JIG_PULL_DEFAULT_DOWN     0
#define SWITCH_CHIP_JIG_PULL_UP               1

/* for phone-off current drain test */
#define MANUAL_DETACH                         0
#define MANUAL_SWITCH                         1

/* switch reg value */
#define REG_VAL_SWITCH_CHIP_OPEN              0
#define REG_VAL_USB1_ID_TO_IDBYPASS \
	((2 << 0) | (1 << 2) | (1 << 5))
#define REG_VAL_USB2_ID_TO_IDBYPASS \
	((2 << 0) | (2 << 2) | (2 << 5))
#define REG_VAL_UART_ID_TO_IDBYPASS \
	((2 << 0) | (3 << 2) | (3 << 5))
#define REG_VAL_USB1_ID_TO_VBAT \
	((1 << 0) | (1 << 2) | (1 << 5))
#define REG_VAL_JIG_DEFAULT_DOWN              0x03
#define REG_VAL_JIG_UP                        0x02

enum switch_chip_err_oprt_reg_num {
	ERR_REG_MANUAL_SW_1 = 1,
	ERR_READ_REG_CONTROL = 2,
	ERR_WRITE_REG_CONTROL = 3,
};

enum err_oprt_irq_num {
	ERR_REQUEST_THREADED_IRQ = 50,
	ERR_GPIO_DIRECTION_INPUT,
	ERR_GPIO_REQUEST,
	ERR_GPIO_TO_IRQ,
	ERR_OF_GET_NAME_GPIO,
	ERR_SWITCH_USB_DEV_REGISTER,
	ERR_NO_DEV,
};

enum switch_chip_device_id {
	USBSWITCH_ID_FSA9683 = 0,
	USBSWITCH_ID_FSA9685,
	USBSWITCH_ID_FSA9688,
	USBSWITCH_ID_FSA9688C,
	USBSWITCH_ID_RT8979,
};

#define CONFIG_MTK_EXTERNAL_CHARGER_TYPE_DETECT 1

#endif /* _SWITCH_CHIP_COMMON_ */
