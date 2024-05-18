/*
 * lcd_kit_power.h
 *
 * lcdkit power function head file for lcd driver
 *
 * Copyright (c) 2018-2019 Honor Device Co., Ltd.
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

#ifndef _LCD_KIT_POWER_H_
#define _LCD_KIT_POWER_H_
#include "lcd_kit_utils.h"
/*
 * macro
 */
#define GPIO_NAME	"gpio"
#define ENABLE	        1
#define DISABLE	        0

#define POWER_MODE	0
#define POWER_NUMBER	1
#define POWER_VOLTAGE	2

enum gpio_operator {
	GPIO_REQ,
	GPIO_RELEASE,
	GPIO_HIGH,
	GPIO_LOW,
};
/*
 * struct
 */
struct event_callback {
	uint32_t event;
	int (*func)(void *data);
};
struct gpio_power_arra {
	enum gpio_operator oper;
	int num;
	struct gpio_desc *cm;
};
/* vcc desc */
struct regulate_bias_desc {
	unsigned int min_uV;
	unsigned int max_uV;
	unsigned int waittype;
	unsigned int wait;
};

struct str_ldo_desc {
	uint32_t ldo_num;
	uint32_t ldo_value;
	uint32_t ldo_addr;
	uint32_t ldo_data;
	uint32_t ldo_mask;
	uint32_t ldo_shift;
};

struct lcd_kit_mtk_regulate_ops {
	int (*reguate_init)(void);
	int (*reguate_vsp_set_voltage)(struct regulate_bias_desc vsp);
	int (*reguate_vsp_on_delay)(struct regulate_bias_desc vsp);
	int (*reguate_vsp_enable)(struct regulate_bias_desc vsp);
	int (*reguate_vsp_disable)(struct regulate_bias_desc vsp);
	int (*reguate_vsn_set_voltage)(struct regulate_bias_desc vsn);
	int (*reguate_vsn_on_delay)(struct regulate_bias_desc vsn);
	int (*reguate_vsn_enable)(struct regulate_bias_desc vsn);
	int (*reguate_vsn_disable)(struct regulate_bias_desc vsn);
};

#define MT6368_PMIC_RG_LDO_VFP_EN_ADDR              (0x1c4d)
#define MT6368_PMIC_RG_LDO_VFP_EN_MASK              0x1
#define MT6368_PMIC_RG_LDO_VFP_EN_SHIFT             0
#define MT6368_PMIC_RG_VFP_VOCAL_ADDR               (0x1da0)
#define MT6368_PMIC_RG_VFP_VOCAL_MASK               0xF
#define MT6368_PMIC_RG_LDO_VFP_EN_SHIFT             0
#define MT6368_PMIC_RG_VFP_VOSEL_ADDR               (0x1da1)
#define MT6368_PMIC_RG_VFP_VOSEL_MASK               0xF
#define MT6368_PMIC_RG_LDO_VFP_EN_SHIFT             4

#define MT6373_PMIC_RG_VAUD18_VOCAL_ADDR            0x1e88
#define MT6373_PMIC_RG_VAUD18_VOCAL_MASK            0xF
#define MT6373_PMIC_RG_VAUD18_VOSEL_ADDR            0x1e89
#define MT6373_PMIC_RG_VAUD18_VOSEL_MASK            0xF
#define MT6373_PMIC_RG_LDO_VAUD18_EN_ADDR           0x1b87
#define MT6373_PMIC_RG_LDO_VAUD18_EN_SHIFT          0

#define MT6373_PMIC_RG_LDO_VFP_EN_ADDR              0x1d15
#define MT6373_PMIC_RG_LDO_VFP_EN_SHIFT             0
#define MT6373_PMIC_RG_VFP_VOCAL_ADDR               0x1e30
#define MT6373_PMIC_RG_VFP_VOCAL_MASK               0xF
#define MT6373_PMIC_RG_VFP_VOSEL_ADDR               0x1e31
#define MT6373_PMIC_RG_VFP_VOSEL_MASK               0xF

int lcd_kit_vci_power_ctrl(int enable);
int lcd_kit_iovcc_power_ctrl(int enable);
int lcd_kit_vsp_power_ctrl(int enable);
int lcd_kit_vsn_power_ctrl(int enable);
int lcd_kit_reset_power_ctrl(int enable);
int lcd_kit_bl_power_ctrl(int enable);
void lcd_kit_gpio_tx(uint32_t type, uint32_t op);
int lcd_kit_power_init(void);
int lcd_kit_pmu_ctrl(uint32_t type, uint32_t enable);
int lcd_kit_charger_ctrl(uint32_t type, uint32_t enable);
#endif
