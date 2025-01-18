/* SPDX-License-Identifier: GPL-2.0 */
/*
 * hl7136.h
 *
 * hl7136 header file
 *
 * Copyright (c) 2023-2023 Hwat Technologies Co., Ltd.
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

#ifndef _HL7136_H_
#define _HL7136_H_

#include <linux/i2c.h>
#include <linux/device.h>
#include <linux/workqueue.h>
#include <linux/bitops.h>
#include <linux/completion.h>
#include <chipset_common/hwpower/common_module/power_log.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_error_handle.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_ic.h>

#define HL7136_DEV_NAME_LEN           32
#define UFCS_MAX_IRQ_LEN              2
#define DISCHRG_EN                    1
#define DISCHRG_DIS                   0
#define DISWATCHDOG_EN                1
#define DISWATCHDOG_DIS               0
#define HL7136_UFCS_RX_BUF_SIZE       125

#define HL7136_COMP_MAX_NUM           2

enum hl7136_info {
	HL7136_INFO_IC_NAME = 0,
	HL7136_INFO_MAX_IBAT,
	HL7136_INFO_IBUS_OCP,
	HL7136_INFO_TOTAL,
};

struct hl7136_mode_para {
	char ic_name[CHIP_DEV_NAME_LEN];
	int max_ibat;
	int ibus_ocp;
};

struct hl7136_param {
	int scp_support;
	int fcp_support;
	int ufcs_support;
};

struct dump_data {
	int vbus;
	int ibat;
	int temp;
	int ibus;
};

struct hl7136_device_info {
	struct i2c_client *client;
	struct device *dev;
	struct work_struct irq_work;
	struct work_struct charge_work;
	struct delayed_work ufcs_msg_update_work;
	struct workqueue_struct *msg_update_wq;
	struct notifier_block event_nb;
	struct nty_data nty_data;
	struct hl7136_param param_dts;
	struct dc_ic_ops sc_ops;
	struct dc_ic_ops lvc_ops;
	struct dc_batinfo_ops batinfo_ops;
	struct power_log_ops log_ops;
	struct mutex ufcs_node_lock;
	struct mutex ufcs_detect_lock;
	struct dump_data charge_data;
	struct hl7136_mode_para hl7136_sc_para;
	struct completion hl7136_add_msg_completion;
	struct completion hl7136_ufcs_read_msg_completion;
	struct completion hl7136_ufcs_msg_update_completion;
	struct notifier_block otg_nb;
	char name[HL7136_DEV_NAME_LEN];
	int gpio_int;
	int irq_int;
	int irq_active;
	int chip_already_init;
	int device_id;
	int dc_ibus_ucp_happened;
	u32 ic_role;
	u32 hl7136_scp_error_flag;
	bool first_rd;
	int get_rev_time;
	int init_finish_flag;
	int int_notify_enable_flag;
	int switching_frequency;
	int sense_r_actual;
	int sense_r_config;
	int less_leak_cur;
	int ufcs_read_buffer_delay;
	int manual_otg_mode;
	struct mutex scp_detect_lock;
	struct mutex accp_adapter_reg_lock;
	unsigned int adapter_support;
	unsigned int ignore_get_cable_info;
	bool plugged_state;
	bool ufcs_communicating_flag;
	u8 ufcs_irq[UFCS_MAX_IRQ_LEN];
	bool ufcs_msg_ready_flag;
	u8 ufcs_pending_msg[HL7136_UFCS_RX_BUF_SIZE];
	int ufcs_pending_msg_len;
};

#define HL7136_INIT_FINISH                             1
#define HL7136_NOT_INIT                                0
#define HL7136_ENABLE_INT_NOTIFY                       1
#define HL7136_DISABLE_INT_NOTIFY                      0

#define HL7136_DEVICE_ID_GET_FAIL                      (-1)
#define HL7136_REG_RESET                               1
#define HL7136_SWITCHCAP_DISABLE                       0

#define HL7136_LENGTH_OF_BYTE                          8

#define HL7136_ADC_RESOLUTION_4                        4
#define HL7136_ADC_STANDARD_TDIE                       40

#define HL7136_ADC_DISABLE                             0
#define HL7136_ADC_ENABLE                              1

/* DEVICE_ID reg=0x00 */
#define HL7136_DEVICE_ID_REG                           0x00
#define HL7136_DEVICE_ID_DEV_REV_MASK                  (BIT(7) | BIT(6) | BIT(5) | BIT(4))
#define HL7136_DEVICE_ID_DEV_REV_SHIFT                 4
#define HL7136_DEVICE_ID_DEV_ID_MASK                   (BIT(3) | BIT(2) | BIT(1) | BIT(0))
#define HL7136_DEVICE_ID_DEV_ID_SHIFT                  0
#define HL7136_DEVICE_ID_HL7136                        11 // b'1101 HL7136 device ID,b'1010 HL7136 device ID

/* INT_SRC reg=0x01 */
#define HL7136_INT_SRC                                 0x01
#define HL7136_CHARGER_I_MASK                          BIT(7)
#define HL7136_CHARGER_I_SHIFT                         7
#define HL7136_UFCS_I_MASK                             BIT(3)
#define HL7136_UFCS_I_SHIFT                            3
#define HL7136_SCP_I_MASK                              BIT(2)
#define HL7136_SCP_I_SHIFT                             2
#define HL7136_VOOC_I_MASK                             BIT(1)
#define HL7136_VOOC_I_SHIFT                            1
#define HL7136_TRANS_I_MASK                            BIT(0)
#define HL7136_TRANS_I_SHIFT                           0

/* INT reg=0x02 */
#define HL7136_INT1_REG                                0x02
#define HL7136_INT1_REG_INIT                           0xFF
#define HL7136_INT1_STATE_CHG_I_MASK                   BIT(7)
#define HL7136_INT1_STATE_CHG_I_SHIFT                  7
#define HL7136_INT1_REG_I_MASK                         BIT(6)
#define HL7136_INT1_REG_I_SHIFT                        6

#define HL7136_INT1_TS_TEMP_I_MASK                     BIT(2)
#define HL7136_INT1_TS_TEMP_I_SHIFT                    2
#define HL7136_INT1_WDOG_I_MASK                        BIT(1)
#define HL7136_INT1_WDOG_I_SHIFT                       1
#define HL7136_INT1_THSD_I_MASK                        BIT(0)
#define HL7136_INT1_THSD_I_SHIFT                       0

/* INT2_REG=0x03 */
#define HL7136_INT2_REG                                0x03
#define HL7136_INT2_VBUS_OV_I_MASK                     BIT(7)
#define HL7136_INT2_VBUS_OV_I_SHIFT                    7
#define HL7136_INT2_VBUS_UV_I_MASK                     BIT(6)
#define HL7136_INT2_VBUS_UV_I_SHIFT                    6
#define HL7136_INT2_VIN_OV_I_MASK                      BIT(5)
#define HL7136_INT2_VIN_OV_I_SHIFT                     5
#define HL7136_INT2_VIN_UV_I_MASK                      BIT(4)
#define HL7136_INT2_VIN_UV_I_SHIFT                     4
#define HL7136_INT2_TRACK_OV_I_MASK                    BIT(3)
#define HL7136_INT2_TRACK_OV_I_SHIFT                   3
#define HL7136_INT2_TRACK_UV_I_MASK                    BIT(2)
#define HL7136_INT2_TRACK_UV_I_SHIFT                   2
#define HL7136_INT2_VBAT_OV_I_MASK                     BIT(1)
#define HL7136_INT2_VBAT_OV_I_SHIFT                    1
#define HL7136_INT2_VOUT_OV_I_MASK                     BIT(0)
#define HL7136_INT2_VOUT_OV_I_SHIFT                    0

/* INT3_REG=0x04 */
#define HL7136_INT3_REG                                0x04
#define HL7136_INT3_IIN_OCP_I_MASK                     BIT(7)
#define HL7136_INT3_IIN_OCP_I_SHIFT                    7
#define HL7136_INT3_IBAT_OCP_I_MASK                    BIT(6)
#define HL7136_INT3_IBAT_OCP_I_SHIFT                   6
#define HL7136_INT3_FET_SHORT_I_MASK                   BIT(2)
#define HL7136_INT3_FET_SHORT_I_SHIFT                  2
#define HL7136_INT3_CFLY_SHORT_I_MASK                  BIT(1)
#define HL7136_INT3_CFLY_SHORT_I_SHIFT                 1
#define HL7136_INT3_PMID_QUAL_I_MASK                   BIT(0)
#define HL7136_INT3_PMID_QUAL_I_SHIFT                  0

#define HL7136_INT_NUM                                 3

/* INT1_MSK reg=0x05 */
#define HL7136_INT1_MSK_REG                            0x05
#define HL7136_INT1_MSK_STATE_CHG_M_MASK               BIT(7)
#define HL7136_INT1_MSK_STATE_CHG_M_SHIFT              7
#define HL7136_INT1_MSK_REG_M_MASK                     BIT(6)
#define HL7136_INT1_MSK_REG_M_SHIFT                    6

#define HL7136_INT1_MSK_TS_TEMP_M_MASK                 BIT(2)
#define HL7136_INT1_MSK_TS_TEMP_M_SHIFT                2
#define HL7136_INT1_MSK_WDOG_M_MASK                    BIT(1)
#define HL7136_INT1_MSK_WDOG_M_SHIFT                   1
#define HL7136_INT1_MSK_THSD_M_MASK                    BIT(0)
#define HL7136_INT1_MSK_THSD_M_SHIFT                   0

/* INT2_MSK reg=0x06 */
#define HL7136_INT2_MSK_REG                            0x06
#define HL7136_INT2_MSK_VBUS_OV_M_MASK                 BIT(7)
#define HL7136_INT2_MSK_VBUS_OV_M_SHIFT                7
#define HL7136_INT2_MSK_VBUS_UV_M_MASK                 BIT(6)
#define HL7136_INT2_MSK_VBUS_UV_M_SHIFT                6
#define HL7136_INT2_MSK_VIN_OV_M_MASK                  BIT(5)
#define HL7136_INT2_MSK_VIN_OV_M_SHIFT                 5
#define HL7136_INT2_MSK_VIN_UV_M_MASK                  BIT(4)
#define HL7136_INT2_MSK_VIN_UV_M_SHIFT                 4
#define HL7136_INT2_MSK_TRACK_OV_M_MASK                BIT(3)
#define HL7136_INT2_MSK_TRACK_OV_M_SHIFT               3
#define HL7136_INT2_MSK_TRACK_UV_M_MASK                BIT(2)
#define HL7136_INT2_MSK_TRACK_UV_M_SHIFT               2
#define HL7136_INT2_MSK_VBAT_OVP_M_MASK                BIT(1)
#define HL7136_INT2_MSK_VBAT_OVP_M_SHIFT               1
#define HL7136_INT2_MSK_VOUT_OVP_M_MASK                BIT(0)
#define HL7136_INT2_MSK_VOUT_OVP_M_SHIFT               0

/* INT3_MSK reg=0x07 */
#define HL7136_INT3_MSK_REG                            0x07
#define HL7136_INT3_MSK_IIN_OCP_M_MASK                 BIT(7)
#define HL7136_INT3_MSK_IIN_OCP_M_SHIFT                7
#define HL7136_INT3_MSK_IBAT_OCP_M_MASK                BIT(6)
#define HL7136_INT3_MSK_IBAT_OCP_M_SHIFT               6
#define HL7136_INT3_MSK_IIN_UCP_M_MASK                 BIT(5)
#define HL7136_INT3_MSK_IIN_UCP_M_SHIFT                5
#define HL7136_INT3_MSK_FET_SHORT_M_MASK               BIT(2)
#define HL7136_INT3_MSK_FET_SHORT_M_SHIFT              2
#define HL7136_INT3_MSK_CFY_SHORT_M_MASK               BIT(1)
#define HL7136_INT3_MSK_CFY_SHORT_M_SHIFT              1
#define HL7136_INT3_MSK_PMID_QUAL_I_M_MASK             BIT(0)
#define HL7136_INT3_MSK_PMID_QUAL_I_M_SHIFT            0

/* INT_STS_A reg=0x08 */
#define HL7136_INT_STS_A_REG                           0x08
#define HL7136_INT_STS_A_STATE_CHG_STS_MASK            (BIT(7) | BIT(6))
#define HL7136_INT_STS_A_STATE_CHG_STS_SHIFT           6
#define HL7136_INT_STS_A_REG_STS_MASK                  (BIT(5) | BIT(4) | BIT(3) | BIT(2))
#define HL7136_INT_STS_A_REG_STS_SIFT                  2
#define HL7136_INT_STS_A_TS_TEMP_STS_MASK              BIT(1)
#define HL7136_INT_STS_A_TS_TEMP_STS_SHIFT             1
#define HL7136_INT_STS_A_WDOG_STS_MASK                 BIT(0)
#define HL7136_INT_STS_A_WDOG_STS_SHIFT                0

/* INT_STS_B reg=0x09 */
#define HL7136_INT_STS_B_REG                           0x09
#define HL7136_INT_STS_B_VBUS_OV_STS_MASK              BIT(7)
#define HL7136_INT_STS_B_VBUS_OV_STS_SHIFT             7
#define HL7136_INT_STS_B_VBUS_UV_STS_MASK              BIT(6)
#define HL7136_INT_STS_B_VBUS_UV_STS_SIFT              6
#define HL7136_INT_STS_B_VIN_OV_STS_MASK               BIT(5)
#define HL7136_INT_STS_B_VIN_OV_STS_SHIFT              5
#define HL7136_INT_STS_B_VIN_UV_STS_MASK               BIT(4)
#define HL7136_INT_STS_B_VIN_UV_STS_SHIFT              4
#define HL7136_INT_STS_B_TRACK_OV_STS_MASK             BIT(3)
#define HL7136_INT_STS_B_TRACK_OV_STS_SHIFT            3
#define HL7136_INT_STS_B_TRACK_UV_STS_MASK             BIT(2)
#define HL7136_INT_STS_B_TRACK_UV_STS_SIFT             2
#define HL7136_INT_STS_B_VBAT_OVP_STS_MASK             BIT(1)
#define HL7136_INT_STS_B_VBAT_OVP_STS_SHIFT            1
#define HL7136_INT_STS_B_VOUT_OVP_STS_MASK             BIT(0)
#define HL7136_INT_STS_B_VOUT_OVP_STS_SHIFT            0

/* VBUS_OVP reg=0x0B */
#define HL7136_VBUS_OVP_REG                            0x0B
#define HL7136_VBUS_OVP_EXT_NFET_USE_MASK              (BIT(7) | BIT(6))
#define HL7136_VBUS_OVP_EXT_NFET_USE_SHIFT             6
#define HL7136_VBUS_OVP_VCTL_OFF_MASK                  BIT(5)
#define HL7136_VBUS_OVP_VCTL_OFF_SHIFT                 5
#define HL7136_VBUS_OVP_VGS_SEL_MASK                   BIT(4)
#define HL7136_VBUS_OVP_VGS_SEL_SHIFT                  4
#define HL7136_VBUS_OVP_VBUS_OVP_TH_MASK               (BIT(3) | BIT(2) | BIT(1) | BIT(0))
#define HL7136_VBUS_OVP_VBUS_OVP_SHIFT                 0
#define HL7136_VBUS_OVP_AUTO                           0
#define HL7136_VBUS_OVP_DISABLED                       1
#define HL7136_VBUS_OVP_ENABLED                        2

/* VGS_SEL(V) = 7V + DEC[5:4] * 0.5V */
#define HL7136_VGS_SEL_MIN                             7000
#define HL7136_VGS_SEL_MAX                             8500
#define HL7136_VGS_SEL_BASE_STEP                       500
#define HL7136_VGS_SEL_INIT                            7000

/* VBUS_OVP(V) = 4V + DEC[3:0] * 1V */
#define HL7136_VBUS_OVP_MIN                            4000
#define HL7136_VBUS_OVP_MAX                            19000
#define HL7136_VBUS_OVP_STEP                           1000
#define HL7136_VBUS_OVP_INIT                           12000

/* VIN_OVP reg=0x0C */
#define HL7136_VIN_OVP_REG                             0x0C
#define HL7136_VBUS_OVP_VIN_PD_EN_MASK                 BIT(7)
#define HL7136_VBUS_OVP_VIN_PD_EN_SHIFT                7
#define HL7136_VIN_OVP_VIN_PD_CFG_MASK                 BIT(5)
#define HL7136_VIN_OVP_VIN_PD_CFG_SHIFT                5
#define HL7136_VIN_OVP_VIN_OVP_DIS_MASK                BIT(4)
#define HL7136_VIN_OVP_VIN_OVP_DIS_SHIFT               4
#define HL7136_VIN_OVP_VIN_OVP_MASK                    (BIT(3) | BIT(2) | BIT(1) | BIT(0))
#define HL7136_VIN_OVP_VIN_OVP_SHIFT                   0

/* CPMODE VIN_OVP(V)= 10.2V + DEC[3:0] * 0.1V */
#define HL7136_VIN_OVP_CP_MIN                          10200
#define HL7136_VIN_OVP_CP_MAX                          11700
#define HL7136_VIN_OVP_CP_STEP                         100
#define HL7136_VIN_OVP_CP_INIT                         11700

/* BPMODE VIN_OVP(V)= 5.1V + DEC[3:0] * 50mV */
#define HL7136_VIN_OVP_BP_MIN                          5100
#define HL7136_VIN_OVP_BP_MAX                          5850
#define HL7136_VIN_OVP_BP_STEP                         50
#define HL7136_VIN_OVP_BP_INIT                         5250

/* VBAT_REG reg=0x0D */
#define HL7136_VBAT_REG_REG                            0x0D
#define HL7136_VBAT_REG_VBAT_OVP_DIS_MASK              BIT(7)
#define HL7136_VBAT_REG_VBAT_OVP_DIS_SHIFT             7
#define HL7136_VBAT_REG_TVBAT_OVP_DEB_MASK             BIT(6)
#define HL7136_VBAT_REG_TVBAT_OVP_DEB_SHIFT            6
#define HL7136_VBAT_REG_VBAT_REG_TH_MASK               (BIT(5) | BIT(4) | BIT(3) | BIT(2) | BIT(1) | BIT(0))
#define HL7136_VBAT_REG_VBAT_REG_TH_SHIFT              0

/* VBAT_OVP(V) = 4.15V + DEC[5:0] * 10mV */
#define HL7136_VBAT_OVP_MIN                            4150
#define HL7136_VBAT_OVP_MAX                            4780
#define HL7136_VBAT_OVP_STEP                           10
#define HL7136_VBAT_OVP_INIT                           4780


/* IBAT_REG reg=0x0E */
#define HL7136_IBAT_REG_REG                            0x0E
#define HL7136_IBAT_REG_IBAT_OCP_DIS_MASK              BIT(7)
#define HL7136_IBAT_REG_IBAT_OCP_DIS_SHIFT             7
#define HL7136_IBAT_REG_TIBAT_OCP_DEB_MASK             BIT(6)
#define HL7136_IBAT_REG_TIBAT_OCP_DEB_SHIFT            6
#define HL7136_IBAT_REG_IBAT_REG_TH_MASK               (BIT(5) | BIT(4) | BIT(3) | BIT(2) | BIT(1) | BIT(0))
#define HL7136_IBAT_REG_IBAT_REG_TH_SHIFT              0

/* IBAT_OCP(A) = 4A + DEC[5:0] * 0.1A */
#define HL7136_IBAT_OCP_MIN                            4000
#define HL7136_IBAT_OCP_MAX                            9200
#define HL7136_IBAT_OCP_STEP                           100
#define HL7136_IBAT_OCP_INIT                           9200


/* IIN_REG reg=0x0F */
#define HL7136_IIN_REG_REG                             0x0F
#define HL7136_IIN_REG_IIN_OCP_DIS_MASK                BIT(7)
#define HL7136_IIN_REG_IIN_OCP_DIS_SHIFT               7
#define HL7136_IIN_REG_IIN_OCP_DEB_MASK                BIT(6)
#define HL7136_IIN_REG_IIN_OCP_DEB_SHIFT               6
#define HL7136_IIN_REG_IIN_REG_TH_MASK                 (BIT(5) | BIT(4) | BIT(3) | BIT(2) | BIT(1) | BIT(0))
#define HL7136_IIN_REG_IIN_REG_TH_SHIFT                0

/* CPMODE IIN_OCP(A) = 1.8A + DEC[5:0] * 50mA */
#define HL7136_IIN_OCP_CP_MIN                          1800
#define HL7136_IIN_OCP_CP_MAX                          4550
#define HL7136_IIN_OCP_CP_STEP                         50
#define HL7136_IIN_OCP_CP_INIT                         4550

/* BPMODE IIN_OCP(A) = 3.6A + DEC[5:0] * 100mA */
#define HL7136_IIN_OCP_BP_MIN                          3600
#define HL7136_IIN_OCP_BP_MAX                          9100
#define HL7136_IIN_OCP_BP_STEP                         100
#define HL7136_IIN_OCP_BP_INIT                         6500

/* REG_CTRL_0 reg=0x10 */
#define HL7136_REG_CTRL0_REG                           0x10
#define HL7136_REG_CTRL0_VBAT_REG_DIS_MASK             BIT(7)
#define HL7136_REG_CTRL0_VBAT_REG_DIS_SHIFT            7
#define HL7136_REG_CTRL0_IBAT_REG_DIS_MASK             BIT(6)
#define HL7136_REG_CTRL0_IBAT_REG_DIS_SHIFT            6
#define HL7136_REG_CTRL0_VBAT_REG_TH_MASK              (BIT(5) | BIT(4))
#define HL7136_REG_CTRL0_VBAT_REG_TH_SHIFT             4
#define HL7136_REG_CTRL0_IBAT_REG_TH_MASK              (BIT(3) | BIT(2))
#define HL7136_REG_CTRL0_IBAT_REG_TH_SHIFT             2
#define HL7136_REG_CTRL0_SPREAD_EN_MASK                BIT(1)
#define HL7136_REG_CTRL0_SPREAD_EN_SHIFT               1
#define HL7136_REG_CTRL0_SPREAD_MAG_MASK               BIT(0)
#define HL7136_REG_CTRL0_SPREAD_MAG_SHIFT              0
#define HL7136_REG_CTRL0_VBAT_REGULATION_OFF           1
#define HL7136_REG_CTRL0_VBAT_REGULATION_ON            0
#define HL7136_REG_CTRL0_IBAT_REGULATION_OFF           1
#define HL7136_REG_CTRL0_IBAT_REGULATION_ON            0


/* REG_CTRL_1 reg=0x11 */
#define HL7136_REG_CTRL1_REG                           0x11
#define HL7136_REG_CTRL1_TDIE_REG_DIS_MASK             BIT(7)
#define HL7136_REG_CTRL1_TDIE_REG_DIS_SHIFT            7
#define HL7136_REG_CTRL1_IDIE_REGULATION_OFF           1
#define HL7136_REG_CTRL1_IDIE_REGULATION_ON            0
#define HL7136_REG_CTRL1_IIN_REG_DIS_MASK              BIT(6)
#define HL7136_REG_CTRL1_IIN_REG_DIS_SHIFT             6
#define HL7136_REG_CTRL1_IIN_REGULATION_OFF            1
#define HL7136_REG_CTRL1_IIN_REGULATION_ON             0
#define HL7136_REG_CTRL1_TDIE_REG_TH_MASK              (BIT(5) | BIT(4))
#define HL7136_REG_CTRL1_TDIE_REG_TH_SHIFT             4
#define HL7136_REG_CTRL1_IIN_REG_TH_MASK               (BIT(3) | BIT(2))
#define HL7136_REG_CTRL1_IIN_REG_TH_SHIFT              2

/* VBAT_OVP(V) = 80mV + DEC[5:4] * 10mV */
#define HL7136_VBAT_OVP_TH_ABOVE_50MV                  50
#define HL7136_VBAT_OVP_TH_ABOVE_100MV                 100
#define HL7136_VBAT_OVP_TH_ABOVE_150MV                 150
#define HL7136_VBAT_OVP_TH_ABOVE_200MV                 200
#define HL7136_VBAT_OVP_TH_ABOVE_STEP                  50

/* IBAT_OVP(A) = 200mA + DEC[3:2] * 100mA */
#define HL7136_IBAT_OCP_TH_ABOVE_200MA                 200
#define HL7136_IBAT_OCP_TH_ABOVE_300MA                 300
#define HL7136_IBAT_OCP_TH_ABOVE_400MA                 400
#define HL7136_IBAT_OCP_TH_ABOVE_500MA                 500
#define HL7136_IBAT_OCP_TH_ABOVE_STEP                  100

/* CTRL_0 reg=0x12 */
#define HL7136_CTRL0_REG                               0x12
#define HL7136_CTRL0_CHG_EN_MASK                       BIT(7)
#define HL7136_CTRL0_CHG_EN_SHIFT                      7
#define HL7136_CTRL0_CHG_EN                            1
#define HL7136_CTRL0_CHG_OFF                           0
#define HL7136_CTRL0_FSW_SET_MASK                      (BIT(6) | BIT(5) | BIT(4) | BIT(3))
#define HL7136_CTRL0_FSW_SET_SHIFT                     3
#define HL7136_CTRL0_UNPLUG_DET_EN_MASK                BIT(2)
#define HL7136_CTRL0_UNPLUG_DET_EN_SHIFT               2
#define HL7136_CTRL0_IIN_UCP_TH_MASK                   (BIT(1) | BIT(0))
#define HL7136_CTRL0_IIN_UCP_TH_SHIFT                  0

#define HL7136_SW_FREQ_MIN                             500
#define HL7136_SW_FREQ_MAX                             1600
#define HL7136_SW_FREQ_STEP                            100
#define HL7136_SW_FREQ_900KHZ                          900
#define HL7136_SW_FREQ_1300KHZ                         1300
#define HL7136_FSW_SET_SW_FREQ_1000KHZ                 0x05

/* CPMODE IIN_UCP(A) = 0.1A + DEC[1:0] * 50mA */
#define HL7136_IIN_UCP_TH_CP_MIN                       100
#define HL7136_IIN_UCP_TH_CP_MAX                       250
#define HL7136_IIN_UCP_TH_CP_STEP                      50

/* BPMODE IIN_OVP(A) = 0.2A + DEC[1:0] * 100mA */
#define HL7136_IIN_UCP_TH_BP_MIN                       200
#define HL7136_IIN_UCP_TH_BP_MAX                       500
#define HL7136_IIN_UCP_TH_BP_STEP                      100

/* CTRL_1 reg=0x13 */
#define HL7136_CTRL1_REG                               0x13
#define HL7136_CTRL1_UCP_DEB_SEL_MASK                  (BIT(7) | BIT(6))
#define HL7136_CTRL1_UCP_DEB_SEL_SHIFT                 6
#define HL7136_CTRL1_VOUT_OVP_DIS_MASK                 BIT(5)
#define HL7136_CTRL1_VOUT_OVP_DIS_SHIFT                5
#define HL7136_CTRL1_TS_PROT_EN_MASK                   BIT(4)
#define HL7136_CTRL1_TS_PROT_EN_SHIFT                  4
#define HL7136_CTRL1_AUTO_V_REC_EN_MASK                BIT(2)
#define HL7136_CTRL1_AUTO_V_REC_EN_SHIFT               2
#define HL7136_CTRL1_AUTO_I_REC_EN_MASK                BIT(1)
#define HL7136_CTRL1_AUTO_I_REC_EN_SHIFT               1
#define HL7136_CTRL1_AUTO_UCP_REC_EN_MASK              BIT(0)
#define HL7136_CTRL1_AUTO_UCP_REC_EN_SHIFT             0

#define HL7136_UCP_DEB_SEL_10MS                        10
#define HL7136_UCP_DEB_SEL_100MS                       100
#define HL7136_UCP_DEB_SEL_500MS                       500
#define HL7136_UCP_DEB_SEL_1000MS                      1000

/* CTRL_2 reg=0x14 */
#define HL7136_CTRL2_REG                               0x14
#define HL7136_CTRL2_SFT_RST_MASK                      (BIT(7) | BIT(6) | BIT(5) | BIT(4))
#define HL7136_CTRL2_SFT_RST_SHIFT                     4
#define HL7136_CTRL2_WD_DIS_MASK                       BIT(3)
#define HL7136_CTRL2_WD_DIS_SHIFT                      3
#define HL7136_CTRL2_WD_TMR_MASK                       (BIT(2) | BIT(1) | BIT(0))
#define HL7136_CTRL2_WD_TMR_SHIFT                      0

#define HL7136_CTRL2_SFT_RST_ENABLE                    0x0c
#define HL7136_WD_TMR_DISABLE                          0
#define HL7136_WD_TMR_200MS                            200
#define HL7136_WD_TMR_500MS                            500
#define HL7136_WD_TMR_1000MS                           1000
#define HL7136_WD_TMR_2000MS                           2000
#define HL7136_WD_TMR_5000MS                           5000
#define HL7136_WD_TMR_10000MS                          10000
#define HL7136_WD_TMR_20000MS                          20000
#define HL7136_WD_TMR_40000MS                          40000
#define HL7136_WD_SET_200MS                            0
#define HL7136_WD_SET_500MS                            1
#define HL7136_WD_SET_1000MS                           2
#define HL7136_WD_SET_2000MS                           3
#define HL7136_WD_SET_5000MS                           4
#define HL7136_WD_SET_10000MS                          5
#define HL7136_WD_SET_20000MS                          6
#define HL7136_WD_SET_40000MS                          7

/* CTRL_3 reg=0x15 */
#define HL7136_CTRL3_REG                               0x15
#define HL7136_CTRL3_DEV_MODE_MASK                     BIT(7)
#define HL7136_CTRL3_DEV_MODE_SHIFT                    7
#define HL7136_CTRL3_DPDM_CFG_MASK                     BIT(2)
#define HL7136_CTRL3_DPDM_CFG_SHIFT                    2
#define HL7136_CTRL3_GPP_CFG_MASK                      (BIT(1) | BIT(0))
#define HL7136_CTRL3_GPP_CFG_SHIFT                     0

#define HL7136_CTRL3_CPMODE                            0
#define HL7136_CTRL3_BPMODE                            1

/* TRACK_OV_UV reg=0x16 */
#define HL7136_TRACK_OV_UV_REG                         0x16
#define HL7136_TRACK_OV_UV_TRACK_OV_DIS_MASK           BIT(7)
#define HL7136_TRACK_OV_UV_TRACK_OV_DIS_SHIFT          7
#define HL7136_TRACK_OV_UV_TRACK_UV_DIS_MASK           BIT(6)
#define HL7136_TRACK_OV_UV_TRACK_UV_DIS_SHIFT          6
#define HL7136_TRACK_OV_UV_TRACK_OV_MASK               (BIT(5) | BIT(4) | BIT(3))
#define HL7136_TRACK_OV_UV_TRACK_OV_SHIFT              3
#define HL7136_TRACK_OV_UV_TRACK_UV_MASK               (BIT(2) | BIT(1) | BIT(0))
#define HL7136_TRACK_OV_UV_TRACK_UV_SHIFT              0

/* TRACK_OV(V) = 200mV + DEC[5:3] * 100mV */
#define HL7136_TRACK_OV_UV_TRACK_OV_MIN                200
#define HL7136_TRACK_OV_UV_TRACK_OV_MAX                900
#define HL7136_TRACK_OV_UV_TRACK_OV_INIT               600
#define HL7136_TRACK_OV_UV_TRACK_OV_STEP               100

/* TRACK_UV(V) = 50mV + DEC[2:0] * 50mV */
#define HL7136_TRACK_OV_UV_TRACK_UV_MIN                50
#define HL7136_TRACK_OV_UV_TRACK_UV_MAX                400
#define HL7136_TRACK_OV_UV_TRACK_UV_INIT               250
#define HL7136_TRACK_OV_UV_TRACK_UV_STEP               50

/* TS_TH reg=0x17 */
#define HL7136_TS_TH_REG                               0x17
#define HL7136_TS_TH_TS_TH_MASK                        0xFF
#define HL7136_TS_TH_TS_TH_SHIFT                       0

/* ADC_CTRL0 reg=0xED */
#define HL7136_ADC_CTRL0_REG                           0xED
#define HL7136_ADC_CTRL0_ADC_REG_COPY_MASK             BIT(7)
#define HL7136_ADC_CTRL0_ADC_REG_COPY_SHIFT            7
#define HL7136_ADC_CTRL0_ADC_MAN_COPY_MASK             BIT(6)
#define HL7136_ADC_CTRL0_ADC_MAN_COPY_SHIFT            6
#define HL7136_ADC_CTRL0_ADC_MODE_CFG_MASK             (BIT(4) | BIT(3))
#define HL7136_ADC_CTRL0_ADC_MODE_CFG_SHIFT            3
#define HL7136_ADC_CTRL0_ADC_AVG_TIME_MASK             (BIT(2) | BIT(1))
#define HL7136_ADC_CTRL0_ADC_AVG_TIME_SHIFT            1
#define HL7136_ADC_CTRL0_ADC_READ_EN_MASK              BIT(0)
#define HL7136_ADC_CTRL0_ADC_READ_EN_SHIFT             0

/* ADC_CTRL1 reg=0xEF */
#define HL7136_ADC_CTRL1_REG                           0xEF
#define HL7136_ADC_CTRL1_VIN_ADC_DIS_MASK              BIT(7)
#define HL7136_ADC_CTRL1_VIN_ADC_DIS_SHIFT             7
#define HL7136_ADC_CTRL1_IIN_ADC_DIS_MASK              BIT(6)
#define HL7136_ADC_CTRL1_IIN_ADC_DIS_SHIFT             6
#define HL7136_ADC_CTRL1_VBAT_ADC_DIS_MASK             BIT(5)
#define HL7136_ADC_CTRL1_VBAT_ADC_DIS_SHIFT            5
#define HL7136_ADC_CTRL1_IBAT_ADC_DIS_MASK             BIT(4)
#define HL7136_ADC_CTRL1_IBAT_ADC_DIS_SHIFT            4
#define HL7136_ADC_CTRL1_TS_ADC_DIS_MASK               BIT(3)
#define HL7136_ADC_CTRL1_TS_ADC_DIS_SHIFT              3
#define HL7136_ADC_CTRL1_TDIE_ADC_DIS_MASK             BIT(2)
#define HL7136_ADC_CTRL1_TDIE_ADC_DIS_SHIFT            2
#define HL7136_ADC_CTRL1_VOUT_ADC_DIS_MASK             BIT(1)
#define HL7136_ADC_CTRL1_VOUT_ADC_DIS_SHIFT            1

/* ADC_VIN_0 reg=0xF0 */
#define HL7136_ADC_VIN_0_REG                           0xF0
#define HL7136_ADC_VIN_0_ADC_VIN_MASK                  0xFF
#define HL7136_ADC_VIN_0_ADC_VIN_SHIFT                 0

/* ADC_VIN_1 reg=0xF1 */
#define HL7136_ADC_VIN_1_REG                           0xF1
#define HL7136_ADC_VIN_1_ADC_VIN_MASK                  (BIT(3) | BIT(2) | BIT(1) | BIT(0))
#define HL7136_ADC_VIN_1_ADC_VIN_SHIFT                 0

/* ADC_IIN_0 reg=0xF2 */
#define HL7136_ADC_IIN_0_REG                           0xF2
#define HL7136_ADC_IIN_0_ADC_IIN_MASK                  0xFF
#define HL7136_ADC_IIN_0_ADC_IIN_SHIFT                 0

/* ADC_IIN_1 reg=0xF3 */
#define HL7136_ADC_IIN_1_REG                           0xF3
#define HL7136_ADC_IIN_1_ADC_IIN_MASK                  (BIT(3) | BIT(2) | BIT(1) | BIT(0))
#define HL7136_ADC_IIN_1_ADC_IIN_SHIFT                 0

#define HL7136_ADC_REG_NUM                             2
#define HL7136_ADC_REG_HIGH                            0
#define HL7136_ADC_REG_LOW                             1
#define HL7136_ADC_GET_VALID_NUM                       0x0F
#define HL7136_ADC_INVALID_BIT                         4

/* ADC_VBAT_0 reg=0xF4 */
#define HL7136_ADC_VBAT_0_REG                          0xF4
#define HL7136_ADC_VBAT_0_ADC_VBAT_MASK                0xFF
#define HL7136_ADC_VBAT_0_ADC_VBAT_SHIFT               0

/* ADC_VBAT_1 reg=0xF5 */
#define HL7136_ADC_VBAT_1_REG                          0xF5
#define HL7136_ADC_VBAT_1_ADC_VBAT_MASK                (BIT(3) | BIT(2) | BIT(1) | BIT(0))
#define HL7136_ADC_VBAT_1_ADC_VBAT_SHIFT               0

/* ADC_IBAT_0 reg=0xF6 */
#define HL7136_ADC_IBAT_0_REG                          0xF6
#define HL7136_ADC_IBAT_0_ADC_IBAT_MASK                0xFF
#define HL7136_ADC_IBAT_0_ADC_IBAT_SHIFT               0

/* ADC_IBAT_1 reg=0xF7 */
#define HL7136_ADC_IBAT_1_REG                          0xF7
#define HL7136_ADC_IBAT_1_ADC_IBAT_MASK                (BIT(3) | BIT(2) | BIT(1) | BIT(0))
#define HL7136_ADC_IBAT_1_ADC_IBAT_SHIFT               0

/* ADC_VTS_0 reg=0xF8 */
#define HL7136_ADC_VTS_0_REG                           0xF8
#define HL7136_ADC_VTS_0_ADC_VTS_MASK                  0xFF
#define HL7136_ADC_VTS_0_ADC_VTS_SHIFT                 0

/* ADC_VTS_1 reg=0xF9 */
#define HL7136_ADC_VTS_1_REG                           0xF9
#define HL7136_ADC_VTS_1_ADC_VTS_MASK                  (BIT(3) | BIT(2) | BIT(1) | BIT(0))
#define HL7136_ADC_VTS_1_ADC_VTS_SHIFT                 0

/* ADC_VOUT_0 reg=0xFA */
#define HL7136_ADC_VOUT_0_REG                          0xFA
#define HL7136_ADC_VOUT_0_ADC_VOUT_MASK                0xFF
#define HL7136_ADC_VOUT_0_ADC_VOUT_SHIFT               0

/* ADC_VOUT_1 reg=0xFB */
#define HL7136_ADC_VOUT_1_REG                          0xFB
#define HL7136_ADC_VOUT_1_ADC_VOUT_MASK                (BIT(3) | BIT(2) | BIT(1) | BIT(0))
#define HL7136_ADC_VOUT_1_ADC_VOUT_SHIFT               0

/* ADC_TDIE_0 reg=0xFC */
#define HL7136_ADC_TDIE_0_REG                          0xFC
#define HL7136_ADC_TDIE_0_ADC_TDIE_MASK                0xFF
#define HL7136_ADC_TDIE_0_ADC_TDIE_SHIFT               0

/* ADC_TDIE_1 reg=0xFD */
#define HL7136_ADC_TDIE_1_REG                          0xFD
#define HL7136_ADC_TDIE_1_ADC_TDIE_MASK                (BIT(3) | BIT(2) | BIT(1) | BIT(0))
#define HL7136_ADC_TDIE_1_ADC_TDIE_SHIFT               0

/* CTL1 reg=0x40 */
#define HL7136_UFCS_CTL1_REG                           0x40
#define HL7136_UFCS_CTL1_EN_PROTOCOL_MASK              (BIT(7) | BIT(6))
#define HL7136_UFCS_CTL1_EN_PROTOCOL_SHIFT             6
#define HL7136_UFCS_CTL1_EN_HANDSHAKE_MASK             BIT(5)
#define HL7136_UFCS_CTL1_EN_HANDSHAKE_SHIFT            5
#define HL7136_UFCS_CTL1_BAUD_RATE_MASK                (BIT(4) | BIT(3))
#define HL7136_UFCS_CTL1_BAUD_RATE_SHIFT               3
#define HL7136_UFCS_CTL1_SEND_MASK                     BIT(2)
#define HL7136_UFCS_CTL1_SEND_SHIFT                    2
#define HL7136_UFCS_CTL1_CABLE_HARDRESET_MASK          BIT(1)
#define HL7136_UFCS_CTL1_CABLE_HARDRESET_SHIFT         1
#define HL7136_UFCS_CTL1_SOUR_HARDRESET_MASK           BIT(0)
#define HL7136_UFCS_CTL1_SOUR_HARDRESET_SHIFT          0
#define HL7136_UFCS_CTL1_WDT_RESET                     0

int hl7136_config_vbuscon_ovp_ref_mv(int ovp_threshold, struct hl7136_device_info *di);
int hl7136_config_vbus_ovp_ref_mv(int ovp_threshold, struct hl7136_device_info *di);
int hl7136_get_vbus_mv(int *vbus, void *dev_data);
#endif /* _HL7136_H_ */
