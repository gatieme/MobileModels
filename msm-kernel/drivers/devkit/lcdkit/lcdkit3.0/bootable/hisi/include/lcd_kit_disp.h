/*
 * lcd_kit_disp.h
 *
 * lcdkit display function head file for lcd driver
 *
 * Copyright (c) 2018-2019 Huawei Technologies Co., Ltd.
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

#ifndef _LCD_KIT_DISP_H_
#define _LCD_KIT_DISP_H_
#include "hisi_fb.h"
#include "lcd_kit_utils.h"
#include "lcd_kit_effect.h"

/*
 * macro
 */
#define DTS_COMP_LCD_KIT_PANEL_TYPE     "huawei,lcd_panel_type"
#define LCD_KIT_MODULE_NAME          lcd_kit
#define LCD_KIT_MODULE_NAME_STR     "lcd_kit"
// elvdd detect type
#define ELVDD_MIPI_CHECK_MODE   1
#define ELVDD_GPIO_CHECK_MODE   2
#define ELVDD_GPIO_CHECK_MODE_AP 3
#define ELVDD_SH_MIPI_AP_GPIO_CHECK_MODE 4
#define RECOVERY_TIMES          3
#define HISI_DISPLAY_ON_STATUS  1
#define LCD_NV_READ 1
#define LCD_NV_WRITE 0
#define LCD_NV_NUMBER 451
#define LCD_NV_SN_CODE_LEN 21

extern struct fdt_operators *lcd_fdt_ops;

int lcd_kit_get_elvss_info(struct hisi_fb_data_type *hisifd);
void add_status_disabled(void);
struct lcd_kit_disp_desc *lcd_kit_get_disp_info(void);
#define disp_info	lcd_kit_get_disp_info()
struct hisi_fb_data_type *lcd_kit_get_ext_data(void);
#define LCD_KIT_EXT_DATA	lcd_kit_get_ext_data()

enum lcd_gpio_type {
	NORMAL_GPIO_TYPE,
	EXTEND_GPIO_TYPE,
};

struct elvdd_detect {
	uint32_t support;
	uint32_t detect_type;
	uint32_t detect_gpio;
	uint32_t detect_gpio_type;
	uint32_t exp_value;
	uint32_t exp_value_mask;
	uint32_t delay;
	/* elvdd detect gpio in DTS */
	uint32_t detect_gpio_dts;
	struct lcd_kit_dsi_panel_cmds cmds;
};

enum sot_repair_mode {
	SOT_REPAIR_NONE,
	SOT_REPAIR_11V = 1,
	SOT_REPAIR_12V,
	SOT_REPAIR_BUTT,
};

struct lcd_kit_sot_err_check {
	uint32_t support;
	enum sot_repair_mode dsi0_repair_flag;
	enum sot_repair_mode dsi1_repair_flag;
	struct lcd_kit_dsi_panel_cmds repair11_cmds;
	struct lcd_kit_dsi_panel_cmds repair12_cmds;
};

/* nv info 104 byte */
struct lcd_kit_nv_sot_cfg {
	u8 panel0_sncode[LCD_NV_SN_CODE_LEN];
	u8 panel1_sncode[LCD_NV_SN_CODE_LEN];
	u8 panel0_dsi0_flag;
	u8 panel0_dsi1_flag;
	u8 panel1_dsi0_flag;
};

/*
 * struct
 */
struct lcd_kit_disp_desc {
	char *lcd_name;
	char *compatible;
	uint32_t lcd_id;
	uint32_t product_id;
	uint32_t gpio_id0;
	uint32_t gpio_id1;
	uint32_t gpio_te;
	uint32_t gpio_backlight;
	uint32_t dynamic_gamma_support;
	/* PPS parameters calc algorithm support */
	uint32_t calc_mode;
	/* read little endian data support */
	uint32_t little_endian_support;
	/* brightness and color uniform */
	struct lcd_kit_brightness_color_uniform brightness_color_uniform;
	/* second display */
	struct lcd_kit_snd_disp snd_display;
	/* quickly sleep out */
	struct lcd_kit_quickly_sleep_out_desc quickly_sleep_out;
	/* sn code */
	struct lcd_kit_sn_code sn_code;
	/* tp color */
	struct lcd_kit_tp_color_desc tp_color;
	/* rgbw */
	struct lcd_kit_rgbw rgbw;
	/* aod */
	struct lcd_kit_aod aod;
	/* hbm elvss */
	struct lcd_kit_hbm_elvss elvss;
	/* pwm pulse switch */
	struct lcd_kit_pwm_pulse_switch pwm;
	/* panel version */
	struct lcd_kit_panel_version panel_version;
	/* aod cmds version */
	struct aod_cmds_version aod_version;
	/* hbm */
	struct lcd_kit_hbm hbm;
	/* logo checksum */
	struct lcd_kit_logo_checksum logo_checksum;
	/* elvdd detect */
	struct elvdd_detect elvdd_detect;
	/* project id */
	struct lcd_kit_project_id project_id;
	/* fps */
	struct lcd_kit_fps fps;
	/* otp */
	struct lcd_kit_otp otp;
	char *bl_name;
	char *bias_name;
	/* sot error irc check */
	struct lcd_kit_sot_err_check sot_err_check;
	/* flash erase */
	struct lcd_kit_flash_erase flash_erase;
};
#endif
