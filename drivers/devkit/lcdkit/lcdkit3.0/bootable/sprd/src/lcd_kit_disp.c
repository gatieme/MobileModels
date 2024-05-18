/*
 * lcd_kit_disp.c
 *
 * lcdkit display function for lcd driver
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

#include "sprd_panel.h"
#include "sprd_dsi.h"
#include "sprd_dphy.h"
#include <libfdt.h>
#include "lcd_kit_disp.h"
#include "bias_bl_utils.h"
#include "bias_ic_common.h"
#include "lcd_kit_utils.h"
#include "lcd_kit_common.h"
#include "lcd_kit_power.h"
#include "lcd_kit_adapt.h"
#include "rt4801h.h"
#include "tps65132.h"
#include "lm3697.h"
#include "ktd3133.h"
#include "sgm37603a.h"
#include "ktz8864.h"
#include "lm36274.h"
#include "nt50356.h"
#include "rt4831.h"
#include "aw99703.h"
#include "sm5109.h"
#include "sm5350.h"
#include "ktd3136.h"
#include "lp8556.h"
#include "rt8555.h"

DECLARE_GLOBAL_DATA_PTR;
#define FRAME_WIDTH	720
#define FRAME_HEIGHT	1440
#define BL_LEVEL_FULL_LK 255
#define OFFSET_DEF_VAL (-1)

static struct sprd_panel_info lcd_kit_pinfo = {0};

#define DETECT_ERR	(-1)
#define DETECT_GPIOID	0
#define DETECT_CHIPID	1
#define DETECT_LCD_TYPE	2
#define DEFAULT_LCD_ID	0x0A
static struct lcd_kit_disp_desc g_lcd_kit_disp_info;

extern void set_backlight(uint32_t brightness);
extern int lcd_kit_set_backlight(int bl_level);
struct lcd_kit_disp_desc *lcd_kit_get_disp_info(void)
{
	return &g_lcd_kit_disp_info;
}

struct sprd_panel_info *lcm_get_panel_info(void)
{
	return &lcd_kit_pinfo;
}

void lcd_kit_uboot_setbacklight(unsigned int level)
{
	int ret = LCD_KIT_OK;
	struct sprd_dsi *dsi = &dsi_device;

	level = 255;
	switch (lcd_kit_pinfo.bl_set_type) {
	case DSI_BACKLIGHT_DCS:
		ret = common_ops->set_mipi_backlight(dsi, level);
		break;
	case DSI_BACKLIGHT_PWM:
		set_backlight(level);
		break;
	case DSI_BACKLIGHT_I2C_IC:
		ret = lcd_kit_set_backlight(level);
		break;
	case DSI_BACKLIGHT_DCS_I2C_IC:
		ret = common_ops->set_mipi_backlight(dsi, level);
		ret = lcd_kit_set_backlight(level);
		break;
	default:
		LCD_KIT_ERR("Backlight type(%d) not supported\n", lcd_kit_pinfo.bl_set_type);
		break;
	}
	LCD_KIT_INFO("backlight: level = %d, ret is %d\n", level, ret);
}

void lcd_kit_change_display_dts(void *fdt)
{
	int lcd_type;
	struct sprd_panel_info *panel_info = NULL;

	panel_info = &lcd_kit_pinfo;
	if (panel_info == NULL) {
		LCD_KIT_ERR("panel info is NULL\n");
		return;
	}
	if (fdt == NULL) {
		LCD_KIT_ERR("fdt is NULL\n");
		return;
	}

	/* bias ic change dts status */
	if (panel_info->bias_ic_ctrl_mode == GPIO_THEN_I2C_MODE) {
		tps65132_set_bias_status(fdt);
		rt4801h_set_bias_status(fdt);
		sm5109_set_bias_status(fdt);
	}
	/* backlight ic dts status */
	if (panel_info->bl_ic_ctrl_mode == BL_I2C_ONLY_MODE) {
		lm3697_set_backlight_status(fdt);
		ktd3133_set_backlight_status(fdt);
		lm36923_set_backlight_status(fdt);
		ktz8864_set_backlight_status(fdt);
		rt4831_set_backlight_status(fdt);
		lm36274_set_backlight_status(fdt);
		nt50356_set_backlight_status(fdt);
		sgm37603a_set_backlight_status(fdt);
		aw99703_set_backlight_status(fdt);
		ktd3136_set_backlight_status(fdt);
		sm5350_set_backlight_status(fdt);
		ktd3133_set_backlight_status(fdt);
		lp8556_set_backlight_status(fdt);
		rt8555_set_backlight_status(fdt);
	} else if (panel_info->bl_ic_ctrl_mode == BL_MIPI_IC_PWM_MODE) {
		lm36274_set_backlight_status(fdt);
		nt50356_set_backlight_status(fdt);
		rt4831_set_backlight_status(fdt);
		ktz8864_set_backlight_status(fdt);
	} else if (panel_info->bl_ic_ctrl_mode == BL_PWM_I2C_MODE) {
		lp8556_set_backlight_status(fdt);
		rt8555_set_backlight_status(fdt);
	}
	/* lcd display info dts status */
	lcd_type = lcd_kit_get_lcd_type();
	if (lcd_type == LCD_KIT)
		lcdkit_set_lcd_panel_type(fdt, disp_info->compatible);
	lcdkit_set_lcd_ddic_max_brightness(fdt,
		lcd_kit_get_blmaxnit(&lcd_kit_pinfo));
}

void lcd_kit_parse_timing_param(struct panel_info *pinfo,
	const void *fdt, int nodeoffset)
{
	int ret;

	if (pinfo == NULL) {
		LCD_KIT_ERR("pinfo is NULL!\n");
		return;
	}
	if (fdt == NULL) {
		LCD_KIT_ERR("fdt is NULL!\n");
		return;
	}

	ret = of_parse_timing(fdt, nodeoffset, pinfo);
	if (ret < 0)
		LCD_KIT_ERR("parse panel timing fail\n");
	return;
}

int lcd_kit_read_bl_maxnit(struct sprd_dsi *dsi)
{
	int ret = LCD_KIT_OK;
	uint8_t read_value = 0;
	struct lcd_kit_adapt_ops *adapt_ops = NULL;

	if (dsi == NULL) {
		LCD_KIT_ERR("dsi is NULL\n");
		return LCD_KIT_FAIL;
	}
	adapt_ops = lcd_kit_get_adapt_ops();
	if (adapt_ops == NULL) {
		LCD_KIT_ERR("can not register adapt_ops!\n");
		return LCD_KIT_FAIL;
	}

	if (lcd_kit_pinfo.blmaxnit.get_blmaxnit_type ==
 		GET_BLMAXNIT_FROM_DDIC) {
		if (adapt_ops->mipi_rx)
			ret = adapt_ops->mipi_rx(dsi, &read_value, 1,
				&lcd_kit_pinfo.blmaxnit.bl_maxnit_cmds);
		lcd_kit_pinfo.blmaxnit.lcd_kit_brightness_ddic_info = read_value;
		LCD_KIT_INFO("lcd_kit_brightness_ddic_info = 0x%x\n",
			lcd_kit_pinfo.blmaxnit.lcd_kit_brightness_ddic_info);
	}
	return ret;
}

int lcd_kit_get_tp_color(struct sprd_dsi *dsi)
{
	int ret = LCD_KIT_OK;
	uint8_t read_value = 0;
	struct lcd_kit_adapt_ops *adapt_ops = NULL;

	if (dsi == NULL) {
		LCD_KIT_ERR("dsi is NULL\n");
		return LCD_KIT_FAIL;
	}

	adapt_ops = lcd_kit_get_adapt_ops();
	if (adapt_ops == NULL) {
		LCD_KIT_ERR("can not register adapt_ops!\n");
		return LCD_KIT_FAIL;
	}

	if (disp_info->tp_color.support) {
		if (adapt_ops->mipi_rx)
			ret = adapt_ops->mipi_rx(dsi, &read_value, 1,
				&disp_info->tp_color.cmds);
		if (ret)
			lcd_kit_pinfo.tp_color = 0;
		else
			lcd_kit_pinfo.tp_color = read_value;
		LCD_KIT_INFO("tp color = %d\n", lcd_kit_pinfo.tp_color);
	} else {
		LCD_KIT_INFO("Not support tp color\n");
	}
	return ret;
}

static int lcd_kit_init(struct panel_info *pinfo)
{
	int lcd_type;
	int detect_type;
	int ret;
	int offset;
	void *pfdt = NULL;

	/* adapt init */
	lcd_kit_adapt_init();

	/* init lcd id invaild */
	disp_info->lcd_id = 0xff;

	detect_type = lcd_kit_get_detect_type();
	switch (detect_type) {
	case DETECT_LCD_TYPE:
		lcd_kit_get_lcdname();
		break;
	default:
		LCD_KIT_ERR("lcd: error detect_type\n");
		lcd_kit_set_lcd_name_to_no_lcd();
		return LCD_KIT_FAIL;
	}

	if (pinfo == NULL) {
		LCD_KIT_ERR("panel info is NULL\n");
		return LCD_KIT_FAIL;
	}

	lcd_type = lcd_kit_get_lcd_type();

	if  (lcd_type == LCD_KIT) {
		/* init lcd id */
		disp_info->lcd_id = lcdkit_get_lcd_id();
		disp_info->product_id = lcd_kit_get_product_id();
		disp_info->compatible = lcd_kit_get_compatible(
			disp_info->product_id, disp_info->lcd_id);
		disp_info->lcd_name = lcd_kit_get_lcd_name(
			disp_info->product_id, disp_info->lcd_id);
		LCD_KIT_ERR(
			"lcd_id:%d, product_id:%d, compatible:%s, lcd_name:%s\n",
			disp_info->lcd_id, disp_info->product_id,
			disp_info->compatible, disp_info->lcd_name);
	} else {
		LCD_KIT_INFO("lcd type is not LCD_KIT.\n");
		return LCD_KIT_FAIL;
	}
	pfdt = gd->fdt_blob;
	if (pfdt == NULL) {
		LCD_KIT_ERR("pfdt is NULL!\n");
		return LCD_KIT_FAIL;
	}
	offset = fdt_node_offset_by_compatible(pfdt,
		OFFSET_DEF_VAL, disp_info->compatible);
	if (offset < 0) {
		LCD_KIT_INFO("can not find %s node by compatible\n",
			disp_info->compatible);
		return LCD_KIT_FAIL;
	}

	/* utils init */
	lcd_kit_utils_init(&lcd_kit_pinfo, pfdt, offset);
	/* panel init */
	lcd_kit_panel_init();
	/* power init */
	lcd_kit_power_init();
	/* panel timing init */
	lcd_kit_parse_timing_param(pinfo, pfdt, offset);
	/* bias ic init */
	bias_bl_ops_init();
	if (lcd_kit_pinfo.bias_ic_ctrl_mode == GPIO_THEN_I2C_MODE) {
		tps65132_init();
		rt4801h_init();
		sm5109_init();
	}

	if (lcd_kit_pinfo.bias_ic_ctrl_mode == LCD_BIAS_COMMON_MODE) {
		ret = bias_ic_init();
		if (ret < 0)
			LCD_KIT_INFO("bias ic common init fail\n");
	}

	/* backlight ic init */
	switch (lcd_kit_pinfo.bl_ic_ctrl_mode) {
	case BL_I2C_ONLY_MODE:
		lm36923_init();
		sgm37603a_init();
		ktz8864_init(&lcd_kit_pinfo);
		lm36274_init(&lcd_kit_pinfo);
		rt4831_init(&lcd_kit_pinfo);
		aw99703_init(&lcd_kit_pinfo);
		sm5350_init(&lcd_kit_pinfo);
		ktd3136_init(&lcd_kit_pinfo);
		nt50356_init(&lcd_kit_pinfo);
		break;
	case BL_MIPI_IC_PWM_MODE:
		lm36274_init(&lcd_kit_pinfo);
		nt50356_init(&lcd_kit_pinfo);
		rt4831_init(&lcd_kit_pinfo);
		ktz8864_init(&lcd_kit_pinfo);
		break;
	case BL_PWM_I2C_MODE:
		lp8556_init(&lcd_kit_pinfo);
		rt8555_init(&lcd_kit_pinfo);
	default:
		break;
	}

	return LCD_KIT_OK;
}

static void lcd_kit_panel_power(int on)
{
	struct sprd_dsi *dsi = &dsi_device;

	if (common_ops->panel_power_on)
		common_ops->panel_power_on((void *)dsi);
}

static void lcd_kit_pane_lp(int on)
{
	struct sprd_dsi *dsi = &dsi_device;
	int ret = LCD_KIT_OK;

	mipi_dsi_lp_cmd_enable(dsi, true);
	if (common_ops->panel_on_lp)
		common_ops->panel_on_lp((void *)dsi);
	ret = lcd_kit_read_bl_maxnit(dsi);
	if (ret)
		LCD_KIT_ERR("read bl maxnit fail\n");
	ret = lcd_kit_get_tp_color(dsi);
	if (ret)
		LCD_KIT_ERR("read tp color fail\n");
}

static void lcd_kit_panel_hs(int on)
{
	struct sprd_dsi *dsi = &dsi_device;
	struct sprd_dphy *dphy = &dphy_device;

	if (dsi->panel == NULL) {
		LCD_KIT_ERR("panel is NULL!\n");
		return 0;
	}
		
	if (dsi->panel->work_mode == SPRD_MIPI_MODE_CMD)
		mipi_dsi_set_work_mode(dsi, SPRD_MIPI_MODE_CMD);
	else
		mipi_dsi_set_work_mode(dsi, SPRD_MIPI_MODE_VIDEO);

	mipi_dsi_state_reset(dsi);
	mipi_dphy_hs_clk_en(dphy, true);

	if (common_ops->panel_on_hs)
		common_ops->panel_on_hs((void *)dsi);
}

void lcd_kit_sprd_params(struct panel_info *pinfo)
{
	if (pinfo == NULL) {
		LCD_KIT_ERR("pinfo is NULL!\n");
		return;
	}
	pinfo->type = lcd_kit_pinfo.panel_interface;
	pinfo->lane_num = lcd_kit_pinfo.mipi.lane_nums;
	if (lcd_kit_pinfo.mipi.non_continue_en)
		pinfo->nc_clk_en = true;
	else
		pinfo->nc_clk_en = false;
	pinfo->phy_freq = lcd_kit_pinfo.data_rate;
	switch (lcd_kit_pinfo.mipi.dsi_color_format) {
	case PIXEL_24BIT_RGB888:
		pinfo->bpp = 24;
		break;
	case LOOSELY_PIXEL_18BIT_RGB666:
	case PACKED_PIXEL_18BIT_RGB666:
		pinfo->bpp = 18;
		break;
	case PIXEL_16BIT_RGB565:
		pinfo->bpp = 16;
		break;
	case PIXEL_SPRD_DSC:
		pinfo->bpp = 24;
		break;
	default:
		pinfo->bpp = 24;
		break;
	}
	switch (lcd_kit_pinfo.panel_dsi_mode) {
	case DSI_CMD_MODE:
		pinfo->work_mode = SPRD_MIPI_MODE_CMD;
		pinfo->burst_mode = PANEL_VIDEO_BURST_MODE;
		break;
	case DSI_SYNC_PULSE_VDO_MODE:
		pinfo->work_mode = SPRD_MIPI_MODE_VIDEO;
		pinfo->burst_mode = PANEL_VIDEO_NON_BURST_SYNC_PULSES;
		break;
	case DSI_SYNC_EVENT_VDO_MODE:
		pinfo->work_mode = SPRD_MIPI_MODE_VIDEO;
		pinfo->burst_mode = PANEL_VIDEO_NON_BURST_SYNC_EVENTS;
		break;
	case DSI_BURST_VDO_MODE:
		pinfo->work_mode = SPRD_MIPI_MODE_VIDEO;
		pinfo->burst_mode = PANEL_VIDEO_BURST_MODE;
		break;
	default:
		pinfo->work_mode = SPRD_MIPI_MODE_VIDEO;
		pinfo->burst_mode = PANEL_VIDEO_BURST_MODE;
		break;
	}
	panel_info.vl_row = pinfo->height;
	panel_info.vl_col = pinfo->width;
}

static int lcd_kit_panel_if_init(struct panel_info *pinfo)
{
	int type = SPRD_PANEL_TYPE_MIPI;

	if (pinfo == NULL)
		LCD_KIT_ERR("pinfo is NULL!\n");
	type = pinfo->type;
	switch (type) {
	case SPRD_PANEL_TYPE_MIPI:
		sprd_dsi_probe();
		sprd_dphy_probe();
		return 0;

	case SPRD_PANEL_TYPE_SPI:
		return 0;

	case SPRD_PANEL_TYPE_RGB:
		return 0;

	default:
		LCD_KIT_ERR("doesn't support current interface type %d\n", type);
		return -1;
	}
}


int lcd_kit_panel_probe(struct panel_driver *pdriver)
{
	int ret;

	ret = lcd_kit_init(pdriver->info);
	if (ret < 0) {
		LCD_KIT_ERR("lcd kit init fail!\n");
		return LCD_KIT_FAIL;
	}

	lcd_kit_sprd_params(pdriver->info);
	lcd_kit_panel_if_init(pdriver->info);
	lcd_kit_panel_power(true);
	lcd_kit_pane_lp(true);
	lcd_kit_panel_hs(true);
	return ret;
}

