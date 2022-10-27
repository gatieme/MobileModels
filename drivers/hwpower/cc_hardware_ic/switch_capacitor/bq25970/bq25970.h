/*
 * bq25970.h
 *
 * bq25970 driver
 *
 * Copyright (c) 2020-2020 Huawei Technologies Co., Ltd.
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

#ifndef _BQ25970_H_
#define _BQ25970_H_

#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/i2c.h>
#include <linux/gpio.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/of_address.h>
#include <linux/of_gpio.h>
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/raid/pq.h>
#include <linux/bitops.h>
#include <huawei_platform/power/direct_charger/direct_charger.h>

/*************************struct define area***************************/

#define SCP_MAX_DATA_LEN           32

struct bq25970_device_info {
	struct i2c_client *client;
	struct device *dev;
	struct work_struct irq_work;
	struct nty_data nty_data;
	struct mutex scp_detect_lock;
	struct mutex accp_adapter_reg_lock;
	struct notifier_block nb;
	int gpio_int;
	int irq_int;
	int irq_active;
	int chip_already_init;
	int device_id;
	int tsbus_high_r_kohm;
	int tsbus_low_r_kohm;
	int switching_frequency;
	int special_freq_shift;
	u32 ic_role;
	int sense_r_actual;
	int sense_r_config;
	u32 chrg_ctl_reg_init;
	u32 adc_fn_reg_init;
	int get_id_time;
	int init_finish_flag;
	int int_notify_enable_flag;
	u32 adc_accuracy;
	int adc_v_ref;
	int v_pullup;
	int r_pullup;
	int r_comp;
	int i2c_recovery_addr;
	atomic_t pm_suspend;
	int ibus_ocp_th;
	int dts_scp_support;
	int dts_fcp_support;
	u32 scp_error_flag;
	u8 scp_data[SCP_MAX_DATA_LEN];
	u8 scp_op;
	u8 scp_op_num;
	bool scp_trans_done;
	bool fcp_support;
	int default_config_frequency_shift;
};

/*************************marco define area***************************/
#define BQ2597X_INIT_FINISH                1
#define BQ2597X_NOT_INIT                   0
#define BQ2597X_ENABLE_INT_NOTIFY          1
#define BQ2597X_DISABLE_INT_NOTIFY         0

#define BQ2597X_NOT_USED                   0
#define BQ2597X_USED                       1
#define BQ2597X_DEVICE_ID_GET_FAIL         (-1)
#define BQ2597X_REG_RESET                  1
#define BQ2597X_SWITCHCAP_DISABLE          0

#define BQ2597X_LOW_BYTE_INIT              0xFF
#define BQ2597X_LENTH_OF_BYTE              8
#define BQ2597X_TDIE_SCALE                 2

#define BQ2597X_ADC_DISABLE                0
#define BQ2597X_ADC_ENABLE                 1

#define BQ2597X_ALM_DISABLE                0
#define BQ2597X_ALM_ENABLE                 1

#define BQ2597X_AC_OVP_THRESHOLD_INIT      12000  /* 12v */
#define BQ2597X_VBUS_OVP_THRESHOLD_INIT    12000  /* 12v */
#define BQ2597X_IBUS_OCP_THRESHOLD_INIT    4750   /* 4.75a */
#define BQ2597X_VBAT_OVP_THRESHOLD_INIT    5000   /* 5v */
#define BQ2597X_IBAT_OCP_THRESHOLD_INIT    10000  /* 10a */

#define BQ2597X_RESISTORS_10KOHM           10     /* for Rhi and Rlo */
#define BQ2597X_RESISTORS_100KOHM          100    /* for Rhi and Rlo */
#define BQ2597X_RESISTORS_KILO             1000   /* kilo */

/*
 * BAT_OVP reg=0x00
 * default=4.35v [b10 0010], BAT_OVP=3.5v + bat_ovp[5:0]*25mv
 */
#define BQ2597X_BAT_OVP_REG                0x00
#define BQ2597X_BAT_OVP_MASK               (BIT(0) | BIT(1) | BIT(2) | \
	BIT(3) | BIT(4) | BIT(5))
#define BQ2597X_BAT_OVP_SHIFT              0
#define BQ2597X_BAT_OVP_MAX_5075MV         5075   /* 5.075v */
#define BQ2597X_BAT_OVP_BASE_3500MV        3500   /* 3.5v */
#define BQ2597X_BAT_OVP_DEFAULT            4350   /* 4.35v */
#define BQ2597X_BAT_OVP_STEP               25     /* 25mv */

#define BQ2597X_BAT_OVP_DIS_MASK           BIT(7)
#define BQ2597X_BAT_OVP_DIS_SHIFT          7

/*
 * BAT_OVP_ALM reg=0x01
 * default=4.20v [b01 1100], BAT_OVP_ALM=3.5v + bat_ovp_alm[5:0]*25mv
 */
#define BQ2597X_BAT_OVP_ALM_REG            0x01
#define BQ2597X_BAT_OVP_ALM_MASK           (BIT(0) | BIT(1) | BIT(2) | \
	BIT(3) | BIT(4) | BIT(5))
#define BQ2597X_BAT_OVP_ALM_SHIFT          0
#define BQ2597X_BAT_OVP_ALM_MAX            5075   /* 5.075v */
#define BQ2597X_BAT_OVP_ALM_BASE           3500   /* 3.5v */
#define BQ2597X_BAT_OVP_ALM_DEFAULT        4200   /* 4.2v */
#define BQ2597X_BAT_OVP_ALM_STEP           25     /* 25mv */

#define BQ2597X_BAT_OVP_ALM_DIS_MASK       BIT(7)
#define BQ2597X_BAT_OVP_ALM_DIS_SHIFT      7

/*
 * BAT_OCP reg=0x02
 * default=8.1a [b011 1101], BAT_OCP=2a + bat_ocp[6:0]*100ma
 */
#define BQ2597X_BAT_OCP_REG                0x02
#define BQ2597X_BAT_OCP_MASK               (BIT(0) | BIT(1) | BIT(2) | \
	BIT(3) | BIT(4) | BIT(5) | BIT(6))
#define BQ2597X_BAT_OCP_SHIFT              0
#define BQ2597X_BAT_OCP_MAX_14700MA        14700  /* 14.7a */
#define BQ2597X_BAT_OCP_BASE_2000MA        2000   /* 2.0a */
#define BQ2597X_BAT_OCP_DEFAULT            8100   /* 8.1a */
#define BQ2597X_BAT_OCP_STEP               100    /* 100ma */

#define BQ2597X_BAT_OCP_DIS_MASK           BIT(7)
#define BQ2597X_BAT_OCP_DIS_SHIFT          7

/*
 * BAT_OCP_ALM reg=0x03
 * default=8.0a [b011 1100], BAT_OCP_ALM=2a + bat_ocp_alm[6:0]*100ma
 */
#define BQ2597X_BAT_OCP_ALM_REG            0x03
#define BQ2597X_BAT_OCP_ALM_MASK           (BIT(0) | BIT(1) | BIT(2) | \
	BIT(3) | BIT(4) | BIT(5) | BIT(6))
#define BQ2597X_BAT_OCP_ALM_SHIFT          0
#define BQ2597X_BAT_OCP_ALM_MAX            14700  /* 14.7a */
#define BQ2597X_BAT_OCP_ALM_BASE           2000   /* 2.0a */
#define BQ2597X_BAT_OCP_ALM_DEFAULT        8000   /* 8.0a */
#define BQ2597X_BAT_OCP_ALM_STEP           100    /* 100ma */

#define BQ2597X_BAT_OCP_ALM_DIS_MASK       BIT(7)
#define BQ2597X_BAT_OCP_ALM_DIS_SHIFT      7

/*
 * BAT_UCP_ALM reg=0x04
 * default=2.0a [b010 1000], BAT_UCP_ALM=bat_ucp_alm[6:0]*50ma
 */
#define BQ2597X_BAT_UCP_ALM_REG            0x04
#define BQ2597X_BAT_UCP_ALM_MASK           (BIT(0) | BIT(1) | BIT(2) | \
	BIT(3) | BIT(4) | BIT(5) | BIT(6))
#define BQ2597X_BAT_UCP_ALM_SHIFT          0
#define BQ2597X_BAT_UCP_ALM_MAX            6350   /* 6.35a */
#define BQ2597X_BAT_UCP_ALM_BASE           0      /* 0a */
#define BQ2597X_BAT_UCP_ALM_DEFAULT        2000   /* 2a */
#define BQ2597X_BAT_UCP_ALM_STEP           50     /* 50ma */

#define BQ2597X_BAT_UCP_ALM_DIS_MASK       BIT(7)
#define BQ2597X_BAT_UCP_ALM_DIS_SHIFT      7

/*
 * AC_PROTECTION reg=0x05
 * default=14.0v [b111], AC_OVP=11v + ac_ovp[2:0]*1v
 */
#define BQ2597X_AC_OVP_REG                 0x05
#define BQ2597X_AC_OVP_MASK                (BIT(0) | BIT(1) | BIT(2))
#define BQ2597X_AC_OVP_SHIFT               0
#define BQ2597X_AC_OVP_MAX_18000MV         18000  /* 18v */
#define BQ2597X_AC_OVP_BASE_11000MV        11000  /* 11v */
#define BQ2597X_AC_OVP_DEFAULT             14000  /* 14v */
#define BQ2597X_AC_OVP_STEP                1000   /* 1v */

#define BQ2597X_AC_OVP_STAT_MASK           BIT(7)
#define BQ2597X_AC_OVP_STAT_SHIFT          7
#define BQ2597X_AC_OVP_FLAG_MASK           BIT(6)
#define BQ2597X_AC_OVP_FLAG_SHIFT          6
#define BQ2597X_AC_OVP_MASK_MASK           BIT(5)
#define BQ2597X_AC_OVP_MASK_SHIFT          5

/*
 * BUS_OVP reg=0x06
 * default=8.9v [b011 1010], BUS_OVP=6v + bus_ovp[6:0]*50mv
 */
#define BQ2597X_BUS_OVP_REG                0x06
#define BQ2597X_BUS_OVP_MASK               (BIT(0) | BIT(1) | BIT(2) | \
	BIT(3) | BIT(4) | BIT(5) | BIT(6))
#define BQ2597X_BUS_OVP_SHIFT              0
#define BQ2597X_BUS_OVP_MAX_12350MV        12350  /* 12.35v */
#define BQ2597X_BUS_OVP_BASE_6000MV        6000   /* 6v */
#define BQ2597X_BUS_OVP_DEFAULT            8900   /* 8.9v */
#define BQ2597X_BUS_OVP_STEP               50     /* 50mv */

/*
 * BUS_OVP_ALM reg=0x07
 * default=8.8v [b011 1000], BUS_OVP_ALM=6v + bus_ovp_alm[6:0]*50mv
 */
#define BQ2597X_BUS_OVP_ALM_REG            0x07
#define BQ2597X_BUS_OVP_ALM_MASK           (BIT(0) | BIT(1) | BIT(2) | \
	BIT(3) | BIT(4) | BIT(5) | BIT(6))
#define BQ2597X_BUS_OVP_ALM_SHIFT          0
#define BQ2597X_BUS_OVP_ALM_MAX            12350  /* 12.35v */
#define BQ2597X_BUS_OVP_ALM_BASE           6000   /* 6v */
#define BQ2597X_BUS_OVP_ALM_DEFAULT        8800   /* 8.8v */
#define BQ2597X_BUS_OVP_ALM_STEP           50     /* 50mv */

#define BQ2597X_BUS_OVP_ALM_DIS_MASK       BIT(7)
#define BQ2597X_BUS_OVP_ALM_DIS_SHIFT      7

/*
 * BUS_OCP_UCP reg=0x08
 * default=4.25a [b1101], BUS_OCP_UCP=1a + bus_ocp[3:0]*250ma
 */
#define BQ2597X_BUS_OCP_UCP_REG            0x08
#define BQ2597X_BUS_OCP_MASK               (BIT(0) | BIT(1) | BIT(2) | BIT(3))
#define BQ2597X_BUS_OCP_SHIFT              0
#define BQ2597X_BUS_OCP_MAX_4750MA         4750  /* 4.75a */
#define BQ2597X_BUS_OCP_BASE_1000MA        1000  /* 1a */
#define BQ2597X_BUS_OCP_DEFAULT            4250  /* 4.25a */
#define BQ2597X_BUS_OCP_STEP               250   /* 250ma */

#define BQ2597X_BUS_OCP_DIS_MASK           BIT(7)
#define BQ2597X_BUS_OCP_DIS_SHIFT          7
#define BQ2597X_IBUS_UCP_RISE_FLAG_MASK    BIT(6)
#define BQ2597X_IBUS_UCP_RISE_FLAG_SHIFT   6
#define BQ2597X_IBUS_UCP_RISE_MASK_MASK    BIT(5)
#define BQ2597X_IBUS_UCP_RISE_MASK_SHIFT   5
#define BQ2597X_IBUS_UCP_FALL_FLAG_MASK    BIT(4)
#define BQ2597X_IBUS_UCP_FALL_FLAG_SHIFT   4

/*
 * BUS_OCP_ALM reg=0x09
 * default=4.0a [b101 0000], BUS_OCP_ALM=bus_ocp_alm[6:0]*50ma
 */
#define BQ2597X_BUS_OCP_ALM_REG            0x09
#define BQ2597X_BUS_OCP_ALM_MASK           (BIT(0) | BIT(1) | BIT(2) | \
	BIT(3) | BIT(4) | BIT(5) | BIT(6))
#define BQ2597X_BUS_OCP_ALM_SHIFT          0
#define BQ2597X_BUS_OCP_ALM_MAX            6350  /* 6.35a */
#define BQ2597X_BUS_OCP_ALM_BASE           0     /* 0a */
#define BQ2597X_BUS_OCP_ALM_DEFAULT        4000  /* 4a */
#define BQ2597X_BUS_OCP_ALM_STEP           50    /* 50ma */

#define BQ2597X_BUS_OCP_ALM_DIS_MASK       BIT(7)
#define BQ2597X_BUS_OCP_ALM_DIS_SHIFT      7

/* CONVERTER_STATE reg=0x0a */
#define BQ2597X_CONVERTER_STATE_REG        0x0A

#define BQ2597X_TSHUT_FLAG_MASK            BIT(7)
#define BQ2597X_TSHUT_FLAG_SHIFT           7
#define BQ2597X_TSHUT_STAT_MASK            BIT(6)
#define BQ2597X_TSHUT_STAT_SHIFT           6
#define BQ2597X_VBUS_ERRORLO_STAT_MASK     BIT(5)
#define BQ2597X_VBUS_ERRORLO_STAT_SHIFT    5
#define BQ2597X_VBUS_ERRORHI_STAT_MASK     BIT(4)
#define BQ2597X_VBUS_ERRORHI_STAT_SHIFT    4
#define BQ2597X_SS_TIMEOUT_FLAG_MASK       BIT(3)
#define BQ2597X_SS_TIMEOUT_FLAG_SHIFT      3
#define BQ2597X_WD_TIMEOUT_FLAG_MASK       BIT(2)
#define BQ2597X_WD_TIMEOUT_FLAG_SHIFT      2
#define BQ2597X_CONV_OCP_FLAG_MASK         BIT(1)
#define BQ2597X_CONV_OCP_FLAG_SHIFT        1
#define BQ2597X_PIN_DIAG_FAIL_FLAG_MASK    BIT(0)
#define BQ2597X_PIN_DIAG_FAIL_FLAG_SHIFT   0

/* CONTROL reg=0x0b */
#define BQ2597X_CONTROL_REG                0x0B
/* 0x46=disable watchdog, switching freq 550khz */
#define BQ2597X_CONTROL_REG_INIT           0x46

#define BQ2597X_REG_RST_MASK               BIT(7)
#define BQ2597X_REG_RST_SHIFT              7
#define BQ2597X_FSW_SET_MASK               (BIT(4) | BIT(5) | BIT(6))
#define BQ2597X_FSW_SET_SHIFT              4
#define BQ2597X_VBUS_PD_EN_MASK            BIT(3)
#define BQ2597X_VBUS_PD_EN_SHIFT           3
#define BQ2597X_WATCHDOG_DIS_MASK          BIT(2)
#define BQ2597X_WATCHDOG_DIS_SHIFT         2
#define BQ2597X_WATCHDOG_CONFIG_MASK       (BIT(0) | BIT(1))
#define BQ2597X_WATCHDOG_CONFIG_SHIFT      0

#define BQ2597X_REG_RST_ENABLE             1

#define BQ2597X_SW_FREQ_450KHZ             450
#define BQ2597X_SW_FREQ_500KHZ             500
#define BQ2597X_SW_FREQ_550KHZ             550
#define BQ2597X_SW_FREQ_675KHZ             675
#define BQ2597X_SW_FREQ_750KHZ             750
#define BQ2597X_SW_FREQ_825KHZ             825
#define BQ2597X_SW_FREQ_1MHZ              1000

#define BQ2597X_FSW_SET_SW_FREQ_187P5KHZ   0x0
#define BQ2597X_FSW_SET_SW_FREQ_250KHZ     0x1
#define BQ2597X_FSW_SET_SW_FREQ_300KHZ     0x2
#define BQ2597X_FSW_SET_SW_FREQ_375KHZ     0x3
#define BQ2597X_FSW_SET_SW_FREQ_500KHZ     0x4
#define BQ2597X_FSW_SET_SW_FREQ_750KHZ     0x5
#define BQ2597X_FSW_SET_SW_FREQ_1MHZ       0x6

#define BQ2597X_WTD_CONFIG_TIMING_500MS    500
#define BQ2597X_WTD_CONFIG_TIMING_1000MS   1000
#define BQ2597X_WTD_CONFIG_TIMING_5000MS   5000
#define BQ2597X_WTD_CONFIG_TIMING_30000MS  30000

#define BQ2597X_WTD_SET_500MS              0
#define BQ2597X_WTD_SET_1000MS             1
#define BQ2597X_WTD_SET_5000MS             2
#define BQ2597X_WTD_SET_30000MS            3

/* CHRG_CTRL reg=0x0c */
#define BQ2597X_CHRG_CTL_REG               0x0C
#define BQ2597X_CHRG_CTL_REG_INIT          0x0e

#define BQ2597X_CHARGE_EN_MASK             BIT(7)
#define BQ2597X_CHARGE_EN_SHIFT            7
#define BQ2597X_MS_MASK                    (BIT(5) | BIT(6))
#define BQ2597X_MS_SHIFT                   5
#define BQ2597X_FREQ_SHIFT_MASK            (BIT(3) | BIT(4))
#define BQ2597X_FREQ_SHIFT_SHIFT           3
#define BQ2597X_TSBUS_DIS_MASK             BIT(2)
#define BQ2597X_TSBUS_DIS_SHIFT            2
#define BQ2597X_TSBAT_DIS_MASK             BIT(1)
#define BQ2597X_TSBAT_DIS_SHIFT            1
#define BQ2597X_TDIE_DIS_MASK              BIT(0)
#define BQ2597X_TDIE_DIS_SHIFT             0

#define BQ2597X_SW_FREQ_SHIFT_NORMAL       0
#define BQ2597X_SW_FREQ_SHIFT_P_P10        1  /* +10% */
#define BQ2597X_SW_FREQ_SHIFT_M_P10        2  /* -10% */
#define BQ2597X_SW_FREQ_SHIFT_MP_P10       3  /* +/-10% */

/* INT_STAT reg=0x0d */
#define BQ2597X_INT_STAT_REG               0x0D

#define BQ2597X_BAT_OVP_ALM_STAT_MASK      BIT(7)
#define BQ2597X_BAT_OVP_ALM_STAT_SHIFT     7
#define BQ2597X_BAT_OCP_ALM_STAT_MASK      BIT(6)
#define BQ2597X_BAT_OCP_ALM_STAT_SHIFT     6
#define BQ2597X_BUS_OVP_ALM_STAT_MASK      BIT(5)
#define BQ2597X_BUS_OVP_ALM_STAT_SHIFT     5
#define BQ2597X_BUS_OCP_ALM_STAT_MASK      BIT(4)
#define BQ2597X_BUS_OCP_ALM_STAT_SHIFT     4
#define BQ2597X_BAT_UCP_ALM_STAT_MASK      BIT(3)
#define BQ2597X_BAT_UCP_ALM_STAT_SHIFT     3
#define BQ2597X_ADAPTER_INSERT_STAT_MASK   BIT(2)
#define BQ2597X_ADAPTER_INSERT_STAT_SHIFT  2
#define BQ2597X_VBAT_INSERT_STAT_MASK      BIT(1)
#define BQ2597X_VBAT_INSERT_STAT_SHIFT     1
#define BQ2597X_ADC_DONE_STAT_MASK         BIT(0)
#define BQ2597X_ADC_DONE_STAT_SHIFT        0

/* INT_FLAG reg=0x0e */
#define BQ2597X_INT_FLAG_REG               0x0E

#define BQ2597X_BAT_OVP_ALM_FLAG_MASK      BIT(7)
#define BQ2597X_BAT_OVP_ALM_FLAG_SHIFT     7
#define BQ2597X_BAT_OCP_ALM_FLAG_MASK      BIT(6)
#define BQ2597X_BAT_OCP_ALM_FLAG_SHIFT     6
#define BQ2597X_BUS_OVP_ALM_FLAG_MASK      BIT(5)
#define BQ2597X_BUS_OVP_ALM_FLAG_SHIFT     5
#define BQ2597X_BUS_OCP_ALM_FLAG_MASK      BIT(4)
#define BQ2597X_BUS_OCP_ALM_FLAG_SHIFT     4
#define BQ2597X_BAT_UCP_ALM_FLAG_MASK      BIT(3)
#define BQ2597X_BAT_UCP_ALM_FLAG_SHIFT     3
#define BQ2597X_ADAPTER_INSERT_FLAG_MASK   BIT(2)
#define BQ2597X_ADAPTER_INSERT_FLAG_SHIFT  2
#define BQ2597X_VBAT_INSERT_FLAG_MASK      BIT(1)
#define BQ2597X_VBAT_INSERT_FLAG_SHIFT     1
#define BQ2597X_ADC_DONE_FLAG_MASK         BIT(0)
#define BQ2597X_ADC_DONE_FLAG_SHIFT        0

/* INT_MASK reg=0x0f */
#define BQ2597X_INT_MASK_REG               0x0F
#define BQ2597X_INT_MASK_REG_INIT          0xF8

#define BQ2597X_BAT_OVP_ALM_MASK_MASK      BIT(7)
#define BQ2597X_BAT_OVP_ALM_MASK_SHIFT     7
#define BQ2597X_BAT_OCP_ALM_MASK_MASK      BIT(6)
#define BQ2597X_BAT_OCP_ALM_MASK_SHIFT     6
#define BQ2597X_BUS_OVP_ALM_MASK_MASK      BIT(5)
#define BQ2597X_BUS_OVP_ALM_MASK_SHIFT     5
#define BQ2597X_BUS_OCP_ALM_MASK_MASK      BIT(4)
#define BQ2597X_BUS_OCP_ALM_MASK_SHIFT     4
#define BQ2597X_BAT_UCP_ALM_MASK_MASK      BIT(3)
#define BQ2597X_BAT_UCP_ALM_MASK_SHIFT     3
#define BQ2597X_ADAPTER_INSERT_MASK_MASK   BIT(2)
#define BQ2597X_ADAPTER_INSERT_MASK_SHIFT  2
#define BQ2597X_VBAT_INSERT_MASK_MASK      BIT(1)
#define BQ2597X_VBAT_INSERT_MASK_SHIFT     1
#define BQ2597X_ADC_DONE_MASK_MASK         BIT(0)
#define BQ2597X_ADC_DONE_MASK_SHIFT        0

/* FLT_STAT reg=0x10 */
#define BQ2597X_FLT_STAT_REG               0x10

#define BQ2597X_BAT_OVP_FLT_STAT_MASK      BIT(7)
#define BQ2597X_BAT_OVP_FLT_STAT_SHIFT     7
#define BQ2597X_BAT_OCP_FLT_STAT_MASK      BIT(6)
#define BQ2597X_BAT_OCP_FLT_STAT_SHIFT     6
#define BQ2597X_BUS_OVP_FLT_STAT_MASK      BIT(5)
#define BQ2597X_BUS_OVP_FLT_STAT_SHIFT     5
#define BQ2597X_BUS_OCP_FLT_STAT_MASK      BIT(4)
#define BQ2597X_BUS_OCP_FLT_STAT_SHIFT     4
#define BQ2597X_TSBUS_TSBAT_ALM_STAT_MASK  BIT(3)
#define BQ2597X_TSBUS_TSBAT_ALM_STAT_SHIFT 3
#define BQ2597X_TSBAT_FLT_STAT_MASK        BIT(2)
#define BQ2597X_TSBAT_FLT_STAT_SHIFT       2
#define BQ2597X_TSBUS_FLT_STAT_MASK        BIT(1)
#define BQ2597X_TSBUS_FLT_STAT_SHIFT       1
#define BQ2597X_TDIE_ALM_STAT_MASK         BIT(0)
#define BQ2597X_TDIE_ALM_STAT_SHIFT        0

/* FLT_FLAG reg=0x11 */
#define BQ2597X_FLT_FLAG_REG               0x11

#define BQ2597X_BAT_OVP_FLT_FLAG_MASK      BIT(7)
#define BQ2597X_BAT_OVP_FLT_FLAG_SHIFT     7
#define BQ2597X_BAT_OCP_FLT_FLAG_MASK      BIT(6)
#define BQ2597X_BAT_OCP_FLT_FLAG_SHIFT     6
#define BQ2597X_BUS_OVP_FLT_FLAG_MASK      BIT(5)
#define BQ2597X_BUS_OVP_FLT_FLAG_SHIFT     5
#define BQ2597X_BUS_OCP_FLT_FLAG_MASK      BIT(4)
#define BQ2597X_BUS_OCP_FLT_FLAG_SHIFT     4
#define BQ2597X_TSBUS_TSBAT_ALM_FLAG_MASK  BIT(3)
#define BQ2597X_TSBUS_TSBAT_ALM_FLAG_SHIFT 3
#define BQ2597X_TSBAT_FLT_FLAG_MASK        BIT(2)
#define BQ2597X_TSBAT_FLT_FLAG_SHIFT       2
#define BQ2597X_TSBUS_FLT_FLAG_MASK        BIT(1)
#define BQ2597X_TSBUS_FLT_FLAG_SHIFT       1
#define BQ2597X_TDIE_ALM_FLAG_MASK         BIT(0)
#define BQ2597X_TDIE_ALM_FLAG_SHIFT        0

/* FLT_MASK reg=0x12 */
#define BQ2597X_FLT_MASK_REG               0x12
#define BQ2597X_FLT_MASK_REG_INIT          0x0F

#define BQ2597X_BAT_OVP_FLT_MASK_MASK      BIT(7)
#define BQ2597X_BAT_OVP_FLT_MASK_SHIFT     7
#define BQ2597X_BAT_OCP_FLT_MASK_MASK      BIT(6)
#define BQ2597X_BAT_OCP_FLT_MASK_SHIFT     6
#define BQ2597X_BUS_OVP_FLT_MASK_MASK      BIT(5)
#define BQ2597X_BUS_OVP_FLT_MASK_SHIFT     5
#define BQ2597X_BUS_OCP_FLT_MASK_MASK      BIT(4)
#define BQ2597X_BUS_OCP_FLT_MASK_SHIFT     4
#define BQ2597X_TSBUS_TSBAT_ALM_MASK_MASK  BIT(3)
#define BQ2597X_TSBUS_TSBAT_ALM_MASK_SHIFT 3
#define BQ2597X_TSBAT_FLT_MASK_MASK        BIT(2)
#define BQ2597X_TSBAT_FLT_MASK_SHIFT       2
#define BQ2597X_TSBUS_FLT_MASK_MASK        BIT(1)
#define BQ2597X_TSBUS_FLT_MASK_SHIFT       1
#define BQ2597X_TDIE_ALM_MASK_MASK         BIT(0)
#define BQ2597X_TDIE_ALM_MASK_SHIFT        0

/* PART_INFO reg=0x13 */
#define BQ2597X_PART_INFO_REG              0x13

#define BQ2597X_DEVICE_REV_MASK            (BIT(4) | BIT(5) | BIT(6) | BIT(7))
#define BQ2597X_DEVICE_REV_SHIFT           4
#define BQ2597X_DEVICE_ID_MASK             0xFF
#define BQ2597X_DEVICE_ID_SHIFT            0

#define BQ2597X_DEVICE_ID_BQ25970          0x10
#define BQ2597X_DEVICE_ID_SC8551           0
#define BQ2597X_DEVICE_ID_SC8551A          0x51
#define BQ2597X_DEVICE_ID_SC8551S          0x3
#define BQ2597X_DEVICE_ID_HL1530           0x1A
#define BQ2597X_DEVICE_ID_SYH69637         0x0E
#define BQ2597X_DEVICE_ID_NU2105           0xC0
#define BQ2597X_DEVICE_ID_RT9759           0x8

/* ADC_CTRL reg=0x14 */
#define BQ2597X_ADC_CTRL_REG               0x14
#define BQ2597X_ADC_CTRL_REG_INIT          0x80

#define BQ2597X_ADC_CTRL_EN_MASK           BIT(7)
#define BQ2597X_ADC_CTRL_EN_SHIFT          7
#define BQ2597X_ADC_RATE_MASK              BIT(6)
#define BQ2597X_ADC_RATE_SHIFT             6
#define BQ2597X_ADC_AVG_MASK               BIT(5)
#define BQ2597X_ADC_AVG_SHIFT              5
#define BQ2597X_ADC_AVG_INT_MASK           BIT(4)
#define BQ2597X_ADC_AVG_INT_SHIFT          4
#define BQ2597X_ADC_SAMPLE_MASK            (BIT(2) | BIT(3))
#define BQ2597X_ADC_SAMPLE_SHIFT           2
#define BQ2597X_IBUS_ADC_DIS_MASK          BIT(0)
#define BQ2597X_IBUS_ADC_DIS_SHIFT         0

#define BQ2597X_ADC_SAMPLE_SPEED_15BIT     0x0
#define BQ2597X_ADC_SAMPLE_SPEED_14BIT     0x1
#define BQ2597X_ADC_SAMPLE_SPEED_13BIT     0x2
#define BQ2597X_ADC_SAMPLE_SPEED_12BIT     0x3

/* ADC_FN_DISABLE reg=0x15 */
#define BQ2597X_ADC_FN_DIS_REG             0x15
#define BQ2597X_ADC_FN_DIS_REG_INIT        0x02

#define BQ2597X_VBUS_ADC_DIS_MASK          BIT(7)
#define BQ2597X_VBUS_ADC_DIS_SHIFT         7
#define BQ2597X_VAC_ADC_DIS_MASK           BIT(6)
#define BQ2597X_VAC_ADC_DIS_SHIFT          6
#define BQ2597X_VOUT_ADC_DIS_MASK          BIT(5)
#define BQ2597X_VOUT_ADC_DIS_SHIFT         5
#define BQ2597X_VBAT_ADC_DIS_MASK          BIT(4)
#define BQ2597X_VBAT_ADC_DIS_SHIFT         4
#define BQ2597X_IBAT_ADC_DIS_MASK          BIT(3)
#define BQ2597X_IBAT_ADC_DIS_SHIFT         3
#define BQ2597X_TSBUS_ADC_DIS_MASK         BIT(2)
#define BQ2597X_TSBUS_ADC_DIS_SHIFT        2
#define BQ2597X_TSBAT_ADC_DIS_MASK         BIT(1)
#define BQ2597X_TSBAT_ADC_DIS_SHIFT        1
#define BQ2597X_TDIE_ADC_DIS_MASK          BIT(0)
#define BQ2597X_TDIE_ADC_DIS_SHIFT         0

/* IBUS_ADC1 reg=0x16 IBUS=ibus_adc[8:0]*1ma */
/* IBUS_ADC0 reg=0x17 */
#define BQ2597X_IBUS_ADC1_REG              0x16
#define BQ2597X_IBUS_ADC0_REG              0x17

#define BQ2597X_IBUS_ADC_STEP              1     /* 1ma */

/* VBUS_ADC1 reg=0x18 VBUS=vbus_adc[8:0]*1mv */
/* VBUS_ADC0 reg=0x19 */
#define BQ2597X_VBUS_ADC1_REG              0x18
#define BQ2597X_VBUS_ADC0_REG              0x19

#define BQ2597X_VBUS_ADC_STEP              1     /* 1mv */

/* VAC_ADC1 reg=0x1A VAC=vac_adc[8:0]*1mv */
/* VAC_ADC0 reg=0x1B */
#define BQ2597X_VAC_ADC1_REG               0x1A
#define BQ2597X_VAC_ADC0_REG               0x1B

#define BQ2597X_VAC_ADC_STEP               1     /* 1mv */

/* VOUT_ADC1 reg=0x1C VOUT=vout_adc[8:0]*1mv */
/* VOUT_ADC0 reg=0x1D */
#define BQ2597X_VOUT_ADC1_REG              0x1C
#define BQ2597X_VOUT_ADC0_REG              0x1D

#define BQ2597X_VOUT_ADC_STEP              1     /* 1mv */

/* VBAT_ADC1 reg=0x1E VBAT=vbat_adc[8:0]*1mv */
/* VBAT_ADC0 reg=0x1F */
#define BQ2597X_VBAT_ADC1_REG              0x1E
#define BQ2597X_VBAT_ADC0_REG              0x1F

#define BQ2597X_VBAT_ADC_STEP              1     /* 1mv */

/* IBAT_ADC1 reg=0x20 IBAT=ibat_adc[8:0]*1ma */
/* IBAT_ADC0 reg=0x21 */
#define BQ2597X_IBAT_ADC1_REG              0x20
#define BQ2597X_IBAT_ADC0_REG              0x21

#define BQ2597X_IBAT_ADC_STEP              1     /* 1ma */

/* TSBUS_ADC1 reg=0x22 TSBUS=tsbus_adc[8:0]*0.09766% */
/* TSBUS_ADC0 reg=0x23 */
#define BQ2597X_TSBUS_ADC1_REG             0x22
#define BQ2597X_TSBUS_ADC1_MASK            (BIT(0) | BIT(1) | BIT(7))

#define BQ2597X_TSBUS_ADC0_REG             0x23

#define BQ2597X_TSBUS_ADC_STEP             9766  /* 0.09766% */
#define BQ2597X_TSBUS_PER_MAX              10000000

/* TSBAT_ADC1 reg=0x24 TSBAT=tsbat_adc[8:0]*0.09766% */
/* TSBAT_ADC0 reg=0x25 */
#define BQ2597X_TSBAT_ADC1_REG             0x24
#define BQ2597X_TSBAT_ADC1_MASK            (BIT(0) | BIT(1) | BIT(7))

#define BQ2597X_TSBAT_ADC0_REG             0x25

#define BQ2597X_TSBAT_ADC_STEP             9766 /* 0.09766% */

/* TDIE_ADC1 reg=0x26 TDIE=tdie_adc[8:0]*0.5c */
/* TDIE_ADC0 reg=0x27 */
#define BQ2597X_TDIE_ADC1_REG              0x26
#define BQ2597X_TDIE_ADC1_MASK             (BIT(0) | BIT(7))

#define BQ2597X_TDIE_ADC0_REG              0x27

#define BQ2597X_TDIE_ADC_STEP              5        /* 0.5c */

/*
 * TSBUS_FLT1 reg=0x28
 * default=4.1% [b0001 0101], TSBUS_FLT=tsbus_flt[7:0] * 0.19531%
 */
#define BQ2597X_TSBUS_FLT_REG              0x28

#define BQ2597X_TSBUS_FLT_MAX              4980405  /* 49.80405% */
#define BQ2597X_TSBUS_FLT_BASE             0
#define BQ2597X_TSBUS_FLT_DEFAULT          410151   /* 4.10151% */
#define BQ2597X_TSBUS_FLT_STEP             19531    /* 0.19531% */

/*
 * TSBAT_FLT0 reg=0x29
 * default=4.1% [b0001 0101],  TSBUS_FLT=tsbus_flt[7:0] * 0.19531%
 */
#define BQ2597X_TSBAT_FLT_REG              0x29

#define BQ2597X_TSBAT_FLT_MAX              4980405  /* 49.80405% */
#define BQ2597X_TSBAT_FLT_BASE             0
#define BQ2597X_TSBAT_FLT_DEFAULT          410151   /* 4.10151% */
#define BQ2597X_TSBAT_FLT_STEP             19531    /* 0.19531% */

/*
 * TDIE_ALM reg=0x2a
 * default=125c [b1100 1000], TDIE_ALM=25+tdie_alm[7:0]*0.5c
 */
#define BQ2597X_TDIE_ALM_REG               0x2A

#define BQ2597X_TDIE_ALM_MAX               1525     /* 152.5c */
#define BQ2597X_TDIE_ALM_BASE              250      /* 25c */
#define BQ2597X_TDIE_ALM_DEFAULT           1250     /* 12c */
#define BQ2597X_TDIE_ALM_STEP              5        /* 0.5c */

/* PULSE_MODE reg=0x2b */
#define BQ2597X_PULSE_MODE_REG             0x2B

#define BQ2597X_PULSE_EN_MASK              BIT(7)
#define BQ2597X_PULSE_EN_SHIFT             7

#define BQ2597X_PULSE_LENGTH_MASK          (BIT(3) | BIT(4) | BIT(5) | BIT(6))
#define BQ2597X_PULSE_LENGTH_SHIFT         3

#define BQ2597X_PULSE_SPARE_MASK           (BIT(0) | BIT(1) | BIT(2))
#define BQ2597X_PULSE_SPARE_SHIFT          0

#define BQ2597X_IBAT_SNS_RES_MASK          BIT(1)
#define BQ2597X_IBAT_SNS_RES_SHIFT         1
#define BQ2597X_IBAT_SNS_RES_2MOHM         0
#define BQ2597X_IBAT_SNS_RES_5MOHM         1

/* DEGLITCH reg=0x2e */
#define BQ2597X_DEGLITCH_REG               0x2E
#define BQ2597X_IBUS_UCP_FALL_DEGLTICH_MASK      BIT(3)
#define BQ2597X_IBUS_UCP_FALL_DEGLTICH_SHIFT     3
#define BQ2597X_IBUS_UCP_FALL_5MS                1

/* scp */
#define SC8551S_SCP_ACK_RETRY_TIME              10
#define SC8551S_RESTART_TIME                    4
#define SC8551S_SCP_RETRY_TIME                  3
#define SC8551S_CHG_SCP_POLL_TIME               100 /* ms */
#define SC8551S_CHG_SCP_DETECT_MAX_CNT          25
#define SC8551S_CHG_SCP_PING_DETECT_MAX_CNT     15
#define SC8551S_SCP_NO_ERR                      0
#define SC8551S_SCP_IS_ERR                      1
#define SC8551S_SCP_WRITE_OP                    0
#define SC8551S_SCP_READ_OP                     1
#define SC8551S_MULTI_READ_LEN                  2
#define SC8551S_SCP_ACK_AND_CRC_LEN             2
#define SC8551S_SCP_SBRWR_NUM                   1

#define SC8551S_CHG_SCP_CMD_SBRRD               0x0c
#define SC8551S_CHG_SCP_CMD_SBRWR               0x0b
#define SC8551S_CHG_SCP_CMD_MBRRD               0x1c
#define SC8551S_CHG_SCP_CMD_MBRWR               0x1b

#define SC8551S_SCP_ACK                         0x08
#define SC8551S_SCP_NACK                        0x03

/* fcp adapter vol value */
#define SC8551S_FCP_ADAPTER_MAX_VOL             12000
#define SC8551S_FCP_ADAPTER_MIN_VOL             5000
#define SC8551S_FCP_ADAPTER_RST_VOL             5000
#define SC8551S_FCP_ADAPTER_ERR_VOL             500
#define SC8551S_FCP_ADAPTER_VOL_CHECK_TIME      10

/* DPDM_CTRL1 reg=0x40 */
#define SC8551S_DPDM_CTRL1_REG                  0x40
#define SC8551S_DM_500K_PD_EN_MASK              BIT(7)
#define SC8551S_DM_500K_PD_EN_SHIFT             7
#define SC8551S_DP_500K_PD_EN_MASK              BIT(6)
#define SC8551S_DP_500K_PD_EN_SHIFT             6
#define SC8551S_DM_20K_PD_EN_MASK               BIT(5)
#define SC8551S_DM_20K_PD_EN_SHIFT              5
#define SC8551S_DP_20K_PD_EN_MASK               BIT(4)
#define SC8551S_DP_20K_PD_EN_SHIFT              4
#define SC8551S_DM_SINK_EN_MASK                 BIT(3)
#define SC8551S_DM_SINK_EN_SHIFT                3
#define SC8551S_DP_SINK_EN_MASK                 BIT(2)
#define SC8551S_DP_SINK_EN_SHIFT                2
#define SC8551S_DP_SRC_10UA_MASK                BIT(1)
#define SC8551S_DP_SRC_10UA_SHIFT               1
#define SC8551S_DPDM_EN_MASK                    BIT(0)
#define SC8551S_DPDM_EN_SHIFT                   0

/* DPDM_CTRL2 reg=0x41 */
#define SC8551S_DPDM_CTRL2_REG                  0x41
#define SC8551S_DM_3P3_EN_MASK               	BIT(7)
#define SC8551S_DM_3P3_EN_SHIFT              	7
#define SC8551S_DPDM_OVP_DIS_MASK               BIT(6)
#define SC8551S_DPDM_OVP_DIS_SHIFT              6
#define SC8551S_DM_BUF_MASK                     (BIT(5) | BIT(4))
#define SC8551S_DM_BUF_SHIFT                    4
#define SC8551S_DP_BUF_MASK                     (BIT(3) | BIT(2))
#define SC8551S_DP_BUF_SHIFT                    2
#define SC8551S_DM_SINK_EN_MASK                 BIT(3)
#define SC8551S_DM_SINK_EN_SHIFT                3
#define SC8551S_DP_SINK_EN_MASK                 BIT(2)
#define SC8551S_DP_SINK_EN_SHIFT                2
#define SC8551S_DM_BUFF_EN_MASK                 BIT(1)
#define SC8551S_DM_BUFF_EN_SHIFT                1
#define SC8551S_DP_BUFF_EN_MASK                 BIT(0)
#define SC8551S_DP_BUFF_EN_SHIFT                0

/* DPDM_STAT reg=0x42 */
#define SC8551S_DPDM_STAT_REG                   0x42
#define SC8551S_VDM_RD_MASK                     (BIT(5) | BIT(4) | BIT(3))
#define SC8551S_VDM_RD_SHIFT                    3
#define SC8551S_VDP_RD_MASK                     (BIT(2) | BIT(1) | BIT(0))
#define SC8551S_VDP_RD_SHIFT                    0

/* DPDM_FLAG_MASK reg=0x43 */
#define SC8551S_DPDM_FLAG_MASK_REG              0x43
#define SC8551S_DM_LOW_MSK_MASK                 BIT(6)
#define SC8551S_DM_LOW_MSK_SHIFT                6
#define SC8551S_DM_LOW_FLAG_MASK                BIT(5)
#define SC8551S_DM_LOW_FLAG_SHIFT               5
#define SC8551S_DP_LOW_MSK_MASK                 BIT(4)
#define SC8551S_DP_LOW_MSK_SHIFT                4
#define SC8551S_DP_LOW_FLAG_MASK                BIT(3)
#define SC8551S_DP_LOW_FLAG_SHIFT               3
#define SC8551S_DPDM_OVP_MSK_MASK               BIT(2)
#define SC8551S_DPDM_OVP_MASK_SHIFT             2
#define SC8551S_DPDM_OVP_FLAG_MASK              BIT(1)
#define SC8551S_DPDM_OVP_FLAG_SHIFT             1
#define SC8551S_DPDM_OVP_STAT_MASK              BIT(0)
#define SC8551S_DPDM_OVP_STAT_SHIFT             0

/* SCP_CTRL reg=0x44 */
#define SC8551S_SCP_CTRL_REG                    0x44
#define SC8551S_SCP_EN_MASK                     BIT(7)
#define SC8551S_SCP_EN_SHIFT                    7
#define SC8551S_SCP_SOFT_RST_MASK               BIT(6)
#define SC8551S_SCP_SOFT_RST_SHIFT              6
#define SC8551S_TX_CRC_DIS_MASK                 BIT(5)
#define SC8551S_TX_CRC_DIS_SHIFT                5
#define SC8551S_CLR_TX_FIFO_MASK                BIT(3)
#define SC8551S_CLR_TX_FIFO_SHIFT               3
#define SC8551S_CLR_RX_FIFO_MASK                BIT(2)
#define SC8551S_CLR_RX_FIFO_SHIFT               2
#define SC8551S_SND_RST_TRANS_MASK              BIT(1)
#define SC8551S_SND_RST_TRANS_SHIFT             1
#define SC8551S_SND_START_TRANS_MASK            BIT(0)
#define SC8551S_SND_START_TRANS_SHIFT           0

#define SC8551S_SCP_ENABLE                      1
#define SC8551S_SCP_DISABLE                     0
#define SC8551S_SCP_TRANS_RESET                 1

/* SCP_WDATA reg=0x45 */
#define SC8551S_SCP_TX_DATA_REG                 0x45
#define SC8551S_SCP_TX_DATA_RST                 0

/* SCP_RDATA reg=0x46 */
#define SC8551S_SCP_RX_DATA_REG                 0x46
#define SC8551S_SCP_RX_DATA_RST                 0
/* SCP_FIFO_STAT reg=0x47 */
#define SC8551S_SCP_FIFO_STAT_REG               0x47
#define SC8551S_DM_BUSY_STAT_MASK               BIT(7)
#define SC8551S_DM_BUSY_STAT_SHIFT              7
#define SC8551S_TX_FIFO_CNT_STAT_MASK           (BIT(5) | BIT(4) | BIT(3))
#define SC8551S_TX_FIFO_CNT_STAT_SHIFT          3
#define SC8551S_RX_FIFO_CNT_STAT_MASK           (BIT(2) | BIT(1) | BIT(0))
#define SC8551S_RX_FIFO_CNT_STAT_SHIFT          0

#define SC8551S_FIFO_DEEPTH                     5

/* SCP_STAT reg=0x48 */
#define SC8551S_SCP_STAT_REG                    0x48
#define SC8551S_FIRST_PING_DET_STAT             0x78
#define SC8551S_NO_FIRST_SLAVE_PING_STAT_MASK   BIT(7)
#define SC8551S_NO_FIRST_SLAVE_PING_STAT_SHIFT  7
#define SC8551S_NO_MED_SLAVE_PING_STAT_MASK     BIT(6)
#define SC8551S_NO_MED_SLAVE_PING_STAT_SHIFT    6
#define SC8551S_NO_LAST_SLAVE_PING_STAT_MASK    BIT(5)
#define SC8551S_NO_LAST_SLAVE_PING_STAT_SHIFT   5
#define SC8551S_NO_RX_PKT_STAS_MASK             BIT(4)
#define SC8551S_NO_RX_PKT_STAS_SHIFT            4
#define SC8551S_NO_TX_PKT_STAT_MASK             BIT(3)
#define SC8551S_NO_TX_PKT_STAT_SHIFT            3
#define SC8551S_WDT_EXPIRED_STAT_MASK           BIT(2)
#define SC8551S_WDT_EXPIRED_STAT_SHIFT          2
#define SC8551S_RX_CRC_ERR_STAT_MASK            BIT(1)
#define SC8551S_RX_CRC_ERR_STAT_SHIFT           1
#define SC8551S_RX_PAR_ERR_STAT_MASK            BIT(0)
#define SC8551S_RX_PAR_ERR_STAT_SHIFT           0

/* SCP_FLAG_MASK reg=0x49 */
#define SC8551S_SCP_FLAG_MASK_REG               0x49
#define SC8551S_SCP_FLAG_MASK_REG_INIT          0x28
#define SC8551S_TX_FIFO_EMPTY_MSK_MASK          BIT(5)
#define SC8551S_TX_FIFO_EMPTY_MSK_SHIFT         5
#define SC8551S_TX_FIFO_EMPTY_FLAG_MASK         BIT(4)
#define SC8551S_TX_FIFO_EMPTY_FLAG_SHIFT        4
#define SC8551S_RX_FIFO_FULL_MSK_MASK           BIT(3)
#define SC8551S_RX_FIFO_FULL_MSK_SHIFT          3
#define SC8551S_RX_FIFO_FULL_FLAG_MASK          BIT(2)
#define SC8551S_RX_FIFO_FULL_FLAG_SHIFT         2
#define SC8551S_TRANS_DONE_MSK_MASK             BIT(1)
#define SC8551S_TRANS_DONE_MSK_SHIFT            1
#define SC8551S_TRANS_DONE_FLAG_MASK            BIT(0)
#define SC8551S_TRANS_DONE_FLAG_SHIFT           0

/* SCP ADAPTOR REG */
#define SCP_PROTOCOL_POWER_CURVE_BASE0         0xd0
#define SCP_PROTOCOL_POWER_CURVE_BASE1         0xe0

/* scp transfer failed when dm busy */
#define SCP_TRANS_DM_BUSY                      0x80
#define SCP_RESET_DP_DELAY_TIME                200
#define SCP_UP_DP_DELAY_TIME                   2
#define SCP_OUTPUT_MODE_ENABLE_DELAY           20
#define SCP_PROTOCOL_CTRL_BYTE0                0xa0
#define SCP_OUTPUT_MODE_ENABLE                 1
#define SCP_PROTOCOL_OUTPUT_MODE_SHIFT         6
#define SCP_PROTOCOL_OUTPUT_MODE_MASK          BIT(6)

/* Hidden register, to improve ADC accuracy */
#define BQ2597X_ADC_ACCU_REG               0x34
#define BQ2597X_ADC_ACCU_REG_INIT          0x01

/*
 * BAT_OVP reg=0x00
 * default=4.325v [b10 0010], BAT_OVP=3.475v + bat_ovp[5:0]*25mv
 */
#define HL1530_BAT_OVP_BASE                3475 /* 3.475v */
#define HL1530_BAT_OVP_MAX                 5050 /* 5.05v */

/*
 * AC_PROTECTION reg=0x05
 * default=14.0v [b111], AC_OVP=11v + ac_ovp[2:0]*1v
 * all bits to 1b set 6.5v
 */
#define HL1530_AC_OVP_BASE_MIN             6500 /* 6.5v */
#define HL1530_AC_OVP_BASE_MAX             17000 /* 17v */

/* BUS_OVP reg=0x06 BIT(7):PD_EN */
#define HL1530_BUS_PD_EN_MASK              BIT(7)
#define HL1530_BUS_PD_EN_SHIFT             7

/* SYH69637 ADC reg base ratio */
#define SYH69637_BASE_RATIO_UNIT           10000

/* IBUS_ADC1 reg=0x16 IBUS=ibus_adc[8:0]*0.3152 */
/* IBUS_ADC0 reg=0x17 */
#define SYH69637_IBUS_ADC_STEP             3125 /* 0.3125ma */

/* VOUT_ADC1 reg=0x1C VOUT=vout_adc[8:0]*0.5mv */
/* VOUT_ADC0 reg=0x1D */
#define SYH69637_VOUT_ADC_STEP             5000 /* 0.5mv */

/* VBAT_ADC1 reg=0x1E VBAT=vbat_adc[8:0]*0.5mv */
/* VBAT_ADC0 reg=0x1F */
#define SYH69637_VBAT_ADC_STEP             5000 /* 0.5mv */

/* IBAT_ADC1 reg=0x20 IBAT=ibat_adc[8:0]*0.625ma */
/* IBAT_ADC0 reg=0x21 */
#define SYH69637_IBAT_ADC_STEP             6250 /* 0.625ma */

/* TSBUS_ADC1 reg=0x22 TSBUS=tsbus_adc[8:0]*0.19531% */
/* TSBUS_ADC0 reg=0x23 */
#define SYH69637_TSBUS_ADC_STEP            19531 /* 0.19531% */

/* SC8551 ADC reg base ratio */
#define SC8551_BASE_RATIO_UNIT             10000

/* IBUS_ADC1 reg=0x16 IBUS=ibus_adc[8:0]*1.5625ma */
/* IBUS_ADC0 reg=0x17 */
#define SC8551_IBUS_ADC_STEP               15625 /* 1.5625ma */

/* VBUS_ADC1 reg=0x18 VBUS=vbus_adc[8:0]*3.75mv */
/* VBUS_ADC0 reg=0x19 */
#define SC8551_VBUS_ADC_STEP               37500 /* 3.75mv */

/* VAC_ADC1 reg=0x1A VAC=vac_adc[8:0]*5mv */
/* VAC_ADC0 reg=0x1B */
#define SC8551_VAC_ADC_STEP                5 /* 5mv */

/* VOUT_ADC1 reg=0x1C VOUT=vout_adc[8:0]*1.25mv */
/* VOUT_ADC0 reg=0x1D */
#define SC8551_VOUT_ADC_STEP               12500 /* 1.25mv */

/* VBAT_ADC1 reg=0x1E VBAT=vbat_adc[8:0]*1.25mv */
/* VBAT_ADC0 reg=0x1F */
#define SC8551_VBAT_ADC_STEP               12500 /* 1.25mv */

/* IBAT_ADC1 reg=0x20 IBAT=ibat_adc[8:0]*3.125ma */
/* IBAT_ADC0 reg=0x21 */
#define SC8551_IBAT_ADC_STEP               31250 /* 3.125ma */

// nu2105 config start

/*
 * TDIE_ALM reg=0x2a
 * default=120℃ [b1100 1000], TDIE_ALM=20+tdie_alm[7:0]*0.5℃
 */

#define NU2105_TDIE_ALM_MAX               1475     /* 147.5℃ */
#define NU2105_TDIE_ALM_BASE              200      /* 20℃ */
#define NU2105_TDIE_ALM_DEFAULT           1200     /* 120℃ */

// nu2105 config end


#endif /* _BQ25970_H_ */