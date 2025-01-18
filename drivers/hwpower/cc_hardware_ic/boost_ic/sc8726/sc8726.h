/* SPDX-License-Identifier: GPL-2.0 */
/*
 * sc8726.h
 *
 * sc8726 header file
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

#ifndef _SC8726_H_
#define _SC8726_H_

#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/i2c.h>
#include <linux/gpio.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/of_address.h>
#include <linux/of_gpio.h>
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/bitops.h>
#include <chipset_common/hwpower/common_module/power_log.h>
#include <chipset_common/hwpower/reverse_charge/reverse_charge.h>

#define CHIP_DEV_NAME_LEN                     32
#define SC8726_BUF_LEN                        80
#define BUF_LEN                               26
#define SC8726_REG_NUM                        10

#define SC8726_IDLE_STATE                     1
#define SC8726_NORMAL_STATE                   0
#define SC8726_R_SENSE_MOHM                   5
#define SC8726_R_CSO_KOHM                     64
#define SC8726_REVERSE_5V                     5000
#define SC8726_REVERSE_9V                     9000
#define SC8726_REVERSE_3A                     3000
#define SC8726_REVERSE_2A                     2000

struct sc8726_device_info {
	struct i2c_client *client;
	struct device *dev;
	struct work_struct irq_work;
	struct workqueue_struct *int_wq;
	struct power_log_ops log_ops;
	struct boost_ops bst_ops;
	char name[CHIP_DEV_NAME_LEN];
	int vbus_comp;
	int r_sensor_mohm;
	int r_cso_kohm;
	int chip_already_init;
	int boost_en;
	int pwrbank_en;
	int in_sleep;
};

/* CSO_SET reg=0x01 */
#define SC8726_CSO_SET_REG                    0x01
#define SC8726_CSO_SET_MASK                   0xFF
#define SC8726_CSO_SET_SHIFT                  0

/* VBUS_SET_MSB reg=0x03 */
#define SC8726_VBUS_SET_MSB_REG               0x03
#define SC8726_VBUS_SET_MSB_MASK              0xFF
#define SC8726_VBUS_SET_MSB_SHIFT             0

/* VBUS_SET reg=0x04 */
#define SC8726_VOUT_SET_REG                   0x04
#define SC8726_FB_SEL_MASK                    BIT(4)
#define SC8726_FB_SEL_SHIFT                   4
#define SC8726_FB_ON_MASK                     BIT(3)
#define SC8726_FB_ON_SHIFT                    3
#define SC8726_FB_DIR_MASK                    BIT(2)
#define SC8726_FB_DIR_SHIFT                   2
#define SC8726_VBUS_SET_LSB_MASK              (BIT(1) | BIT(0))
#define SC8726_VBUS_SET_LSB_SHIFT             0
#define SC8726_VBUS_LSB                       20
#define SC8726_VBUS_LOW_BITS                  2
#define SC8726_VBUS_BASE                      5000

/* GLOBAL_CTRL reg=0x05 */
#define SC8726_GLOBAL_CTRL_REG                0x05
#define SC8726_DIS_DCDC_MASK                  BIT(2)
#define SC8726_DIS_DCDC_SHIFT                 2
#define SC8726_LOAD_MASK                      BIT(1)
#define SC8726_LOAD_SHIFT                     1
#define SC8726_LOAD_ENABLE                    1

/* SYS_SET reg=0x06 */
#define SC8726_SYS_SET_REG                    0x06
#define SC8726_EN_PWM_MASK                    BIT(7)
#define SC8726_EN_PWM_SHIFT                   7
#define SC8726_EXT_DT_MASK                    BIT(6)
#define SC8726_EXT_DT_SHIFT                   6
#define SC8726_EN_VINREG_MASK                 BIT(4)
#define SC8726_EN_VINREG_SHIFT                4

/* FREQ_SET reg=0x08 */
#define SC8726_FREQ_SET_REG                   0x08
#define SC8726_FREQ_SET_MASK                  (BIT(1) | BIT(0))
#define SC8726_FREQ_SET_SHIFT                 0

/* STATUS_1 reg=0x09 */
#define SC8726_STATUS_1_REG                   0x09
#define SC8726_VIN_OVP_MASK                   BIT(7)
#define SC8726_VIN_OVP_SHIFT                  7
#define SC8726_VINREG_FLAG_MASK               BIT(2)
#define SC8726_VINREG_FLAG_SHIFT              2
#define SC8726_IBUS_FLAG_MASK                 BIT(1)
#define SC8726_IBUS_FLAG_SHIFT                1

/* STATUS_2 reg=0x0A */
#define SC8726_STATUS_2_REG                   0x0A
#define SC8726_VOUT_SHORT_MASK                BIT(7)
#define SC8726_VOUT_SHORT_SHIFT               7
#define SC8726_VOUT_H_MASK                    BIT(6)
#define SC8726_VOUT_H_SHIFT                   6
#define SC8726_LOW_CURRENT_MASK               BIT(4)
#define SC8726_LOW_CURRENT_SHIFT              4
#define SC8726_THD_MASK                       BIT(3)
#define SC8726_THD_SHIFT                      3
#define SC8726_OCP_MASK                       BIT(0)
#define SC8726_OCP__SHIFT                     0
#endif /* _SC8726_H_ */
