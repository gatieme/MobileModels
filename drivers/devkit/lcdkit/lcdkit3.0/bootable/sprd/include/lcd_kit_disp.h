/*
 * lcd_kit_disp.h
 *
 * lcdkit display function head file for lcd driver
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

#ifndef _LCD_KIT_DISP_H_
#define _LCD_KIT_DISP_H_
#include "lcd_kit_utils.h"
#include "lcd_kit_panels.h"
/*
 * macro
 */
struct lcd_kit_disp_desc *lcd_kit_get_disp_info(void);
#define disp_info	lcd_kit_get_disp_info()

#define DTS_COMP_LCD_KIT_PANEL_TYPE	"honor,lcd_panel_type"
#define LCD_KIT_MODULE_NAME		lcd_kit
#define LCD_KIT_MODULE_NAME_STR		"lcd_kit"

enum LCM_DSI_MODE {
	DSI_CMD_MODE = 0,
	DSI_BURST_VDO_MODE = 1,
	DSI_SYNC_PULSE_VDO_MODE = 2,
	DSI_SYNC_EVENT_VDO_MODE = 3
};

enum LCM_DSI_PIXEL_FORMAT {
	PIXEL_24BIT_RGB888 = 0,
	LOOSELY_PIXEL_18BIT_RGB666 = 1,
	PACKED_PIXEL_18BIT_RGB666 = 2,
	PIXEL_16BIT_RGB565 = 3,
	PIXEL_SPRD_DSC = 4
};

/*
 * struct
 */
struct lcd_kit_disp_desc {
	char *lcd_name;
	char *compatible;
	uint32_t lcd_id;
	uint32_t product_id;
	uint32_t gpio_te;
	uint32_t gpio_id0;
	uint32_t gpio_id1;
	/* second display */
	struct lcd_kit_snd_disp snd_display;
	/* quickly sleep out */
	struct lcd_kit_quickly_sleep_out_desc quickly_sleep_out;
	/* tp color */
	struct lcd_kit_tp_color_desc tp_color;
};
void lcd_kit_change_display_dts(void *fdt);
#endif
