/*
 * lcd_kit_utils.h
 *
 * lcdkit utils function head file for lcd driver
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

#ifndef __LCD_KIT_UTILS_H_
#define __LCD_KIT_UTILS_H_
#include "lcd_kit_common.h"
#include "lcd_kit_adapt.h"
#include "lcd_kit_panel.h"

#define DTS_LCD_PANEL_TYPE  "/honor,lcd_panel"
#define LCD_KIT_DEFAULT_PANEL	"/honor,lcd_config/lcd_kit_default_auo_otm1901a_5p2_1080p_video_default"
#define LCD_KIT_DEFAULT_COMPATIBLE	"auo_otm1901a_5p2_1080p_video_default"
#define LCD_DDIC_INFO_LEN	64

#define REG61H_VALUE_FOR_RGBW	3800

/* dcs read/write */
#define DTYPE_DCS_WRITE		0x05 /* short write, 0 parameter */
#define DTYPE_DCS_WRITE1	0x15 /* short write, 1 parameter */
#define DTYPE_DCS_READ		0x06 /* read */
#define DTYPE_DCS_LWRITE	0x39 /* long write */
#define DTYPE_DSC_LWRITE	0x0A /* dsc dsi1.2 vesa3x long write */

/* generic read/write */
#define DTYPE_GEN_WRITE		0x03 /* short write, 0 parameter */
#define DTYPE_GEN_WRITE1	0x13 /* short write, 1 parameter */
#define DTYPE_GEN_WRITE2	0x23 /* short write, 2 parameter */
#define DTYPE_GEN_LWRITE	0x29 /* long write */
#define DTYPE_GEN_READ		0x04 /* long read, 0 parameter */
#define DTYPE_GEN_READ1		0x14 /* long read, 1 parameter */
#define DTYPE_GEN_READ2		0x24 /* long read, 2 parameter */

#define BL_MIN	0
#define BL_MAX	256
#define BL_NIT	400
#define BL_REG_NOUSE_VALUE	128
#define BL_BOOT_DEF 255

#define GPIO_OUT_ZERO 0
#define GPIO_OUT_ONE 1

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(array)	((sizeof(array)) / (sizeof(array[0])))
#endif

/* get blmaxnit */
enum {
	GET_BLMAXNIT_FROM_DDIC = 1,
};

enum {
	WAIT_TYPE_US = 0,
	WAIT_TYPE_MS,
};

/* dtype for gpio */
enum {
	DTYPE_GPIO_REQUEST,
	DTYPE_GPIO_FREE,
	DTYPE_GPIO_INPUT,
	DTYPE_GPIO_OUTPUT,
};
/* gpio desc */
struct gpio_desc {
	int dtype;
	int waittype;
	int wait;
	char *label;
	uint32_t *gpio;
	int value;
};

/* get blmaxnit */
struct lcd_kit_blmaxnit {
	u32 get_blmaxnit_type;
	u32 lcd_kit_brightness_ddic_info;
	struct lcd_kit_dsi_panel_cmds bl_maxnit_cmds;
};

struct mipi_panel_info {
	u32 lane_nums;
	u32 dsi_color_format;
	u32 dsi_bit_clk;
	u32 burst_mode;
	u32 non_continue_en;
	u32 phy_mode;  /* 0: DPHY, 1:CPHY */
};

struct sprd_panel_info {
	u32 panel_interface;
	u32 panel_dsi_mode;
	u32 width; /* mm */
	u32 height;
	u32 bl_set_type;
	u32 bl_min;
	u32 bl_max;
	/* default max nit */
	u32 bl_max_nit;
	/* actual max nit */
	u32 actual_bl_max_nit;
	u32 bl_boot;
	u32 bl_ic_ctrl_mode;
	u32 bias_ic_ctrl_mode;
	u32 data_rate;
	u32 mipi_read_gcs_support;
	u32 tp_color;
	struct mipi_panel_info mipi;
	/* get_blmaxnit */
	struct lcd_kit_blmaxnit blmaxnit;
	u8 bias_bl_ic_checked;
	u32 bl_max_nit_min_value;
	u32 panel_max_nit_adjust;
	u32 panel_max_nit_refer;
};

struct lcd_kit_quickly_sleep_out_desc {
	uint32_t support;
	uint32_t interval;
	uint32_t panel_on_tag;
	unsigned long panel_on_record;
};

struct lcd_kit_tp_color_desc {
	uint32_t support;
	struct lcd_kit_dsi_panel_cmds cmds;
};

struct lcd_kit_snd_disp {
	u32 support;
	struct lcd_kit_dsi_panel_cmds on_cmds;
	struct lcd_kit_dsi_panel_cmds off_cmds;
};

enum bl_type {
	DSI_BACKLIGHT_PWM = 0,
	DSI_BACKLIGHT_DCS,
    DSI_BACKLIGHT_I2C_IC,
	DSI_BACKLIGHT_DCS_I2C_IC,
	DSI_BACKLIGHT_MAX
};

enum backlight_ctrl_mode {
  	BL_I2C_ONLY_MODE = 0,
    BL_PWM_ONLY_MODE = 1,
    BL_MUL_RAMP_MODE = 2,
    BL_RAMP_MUL_MODE = 3,
    BL_PWM_I2C_MODE = 4,
    BL_MIPI_IC_PWM_MODE = 5
};

enum bias_control_mode {
	PMIC_ONLY_MODE = 1,
	GPIO_ONLY_MODE,
	GPIO_THEN_I2C_MODE,
	LCD_BIAS_COMMON_MODE,
};
int lcd_kit_adapt_init(void);
int lcd_kit_dsi_fifo_is_full(uint32_t dsi_base);
char *lcd_kit_get_compatible(uint32_t product_id, uint32_t lcd_id);
char *lcd_kit_get_lcd_name(uint32_t product_id, uint32_t lcd_id);
int lcd_kit_dsi_cmds_tx(void *hld, struct lcd_kit_dsi_panel_cmds *cmds);
u32 lcd_kit_get_blmaxnit(struct sprd_panel_info *pinfo);
struct sprd_panel_info *lcm_get_panel_info(void);
int lcd_kit_utils_init(struct sprd_panel_info *pinfo,
	const void *fdt, int nodeoffset);
void lcd_kit_disp_on_check_delay(void);
void lcd_kit_disp_on_record_time(void);
#endif
