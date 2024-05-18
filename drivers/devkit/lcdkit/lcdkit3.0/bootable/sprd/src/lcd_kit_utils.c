/*
 * lcd_kit_utils.c
 *
 * lcdkit utils function for lcd driver
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

#include "lcd_kit_utils.h"
#include "lcd_kit_disp.h"
#include "lcd_kit_power.h"
#include "lcd_kit_utils.h"
#include "lcd_kit_panels.h"

#define MAX_DELAY_TIME 200
#define TP_COLOR_ID_LEN 32
#define TP_COLOR_ID_NAME "TP_COLOR="

extern int fdt_chosen_bootargs_append(void *fdt, char *append_args, int force);
u32 lcd_kit_get_blmaxnit(struct sprd_panel_info *pinfo)
{
	u32 bl_max_nit;
	u32 lcd_kit_brightness_ddic_info;

	lcd_kit_brightness_ddic_info =
		pinfo->blmaxnit.lcd_kit_brightness_ddic_info;
	if ((pinfo->blmaxnit.get_blmaxnit_type == GET_BLMAXNIT_FROM_DDIC) &&
		(lcd_kit_brightness_ddic_info > BL_MIN) &&
		(lcd_kit_brightness_ddic_info < BL_MAX)) {
		bl_max_nit =
			(lcd_kit_brightness_ddic_info < BL_REG_NOUSE_VALUE) ?
			(lcd_kit_brightness_ddic_info + pinfo->bl_max_nit_min_value) :
			(lcd_kit_brightness_ddic_info + pinfo->bl_max_nit_min_value - 1);
	} else {
		bl_max_nit = pinfo->bl_max_nit;
	}

	if (pinfo->panel_max_nit_adjust) {
		if (bl_max_nit >= pinfo->panel_max_nit_refer) {
			bl_max_nit = pinfo->bl_max_nit;
		}
	}
	return bl_max_nit;
}

void fdt_fixup_tp_color_id(void *fdt)
{
	char tp_color_buf[TP_COLOR_ID_LEN + 1] = {0};
	int ret;
	struct sprd_panel_info *panel_info = NULL;
	int str_len;

	if (!fdt) {
		LCD_KIT_ERR("fdt is null\n");
		return LCD_KIT_FAIL;
	}
	panel_info = lcm_get_panel_info();
	if (!panel_info) {
		LCD_KIT_ERR("get lcm panel info failed\n");
		return LCD_KIT_FAIL;
	}

	sprintf(tp_color_buf, TP_COLOR_ID_NAME);
	str_len = strlen(tp_color_buf);
	sprintf(&tp_color_buf[str_len], "%d", panel_info->tp_color);
	str_len = strlen(tp_color_buf);
	tp_color_buf[str_len] = '\0';

	ret = fdt_chosen_bootargs_append(fdt, tp_color_buf, 1);
	return ret;
}

char *lcd_kit_get_compatible(uint32_t product_id, uint32_t lcd_id)
{
	uint32_t i;

	for (i = 0; i < ARRAY_SIZE(lcd_kit_map); ++i) {
		if ((lcd_kit_map[i].board_id == product_id) &&
		    (lcd_kit_map[i].gpio_id == lcd_id)) {
			return lcd_kit_map[i].compatible;
		}
	}
	/* use defaut panel */
	return LCD_KIT_DEFAULT_COMPATIBLE;
}

char *lcd_kit_get_lcd_name(uint32_t product_id, uint32_t lcd_id)
{
	uint32_t i;

	for (i = 0; i < ARRAY_SIZE(lcd_kit_map); ++i) {
		if ((lcd_kit_map[i].board_id == product_id) &&
		    (lcd_kit_map[i].gpio_id == lcd_id)) {
			return lcd_kit_map[i].lcd_name;
		}
	}
	/* use defaut panel */
	return LCD_KIT_DEFAULT_PANEL;
}

static int lcd_kit_parse_disp_info(const void *fdt, int nodeoffset)
{
	if (fdt == NULL) {
		LCD_KIT_ERR("fdt is null\n");
		return LCD_KIT_FAIL;
	}

	/* quickly sleep out */
	lcd_kit_get_dts_u32_default(fdt, nodeoffset,
		"lcd-kit,quickly-sleep-out-support",
		&disp_info->quickly_sleep_out.support, 0);
	if (disp_info->quickly_sleep_out.support)
		lcd_kit_get_dts_u32_default(fdt, nodeoffset,
			"lcd-kit,quickly-sleep-out-interval",
			&disp_info->quickly_sleep_out.interval, 0);
	/* tp color support */
	lcd_kit_get_dts_u32_default(fdt, nodeoffset, "lcd-kit,tp-color-support",
		&disp_info->tp_color.support, 0);
	if (disp_info->tp_color.support)
		lcd_kit_parse_dts_dcs_cmds(fdt, nodeoffset, "lcd-kit,tp-color-cmds",
			"lcd-kit,tp-color-cmds-state",
			&disp_info->tp_color.cmds);

	return LCD_KIT_OK;
}


static int lcd_kit_pinfo_init(const void *fdt, int nodeoffset,
	struct sprd_panel_info *pinfo)
{
	int ret = LCD_KIT_OK;

	if (fdt == NULL) {
		LCD_KIT_ERR("fdt is null\n");
		return LCD_KIT_FAIL;
	}
	if (pinfo == NULL) {
		LCD_KIT_ERR("pinfo is null\n");
		return LCD_KIT_FAIL;
	}
	/* panel info */
	lcd_kit_get_dts_u32_default(fdt, nodeoffset, "lcd-kit,panel-width",
		&pinfo->width, 0);
	lcd_kit_get_dts_u32_default(fdt, nodeoffset, "lcd-kit,panel-height",
		&pinfo->height, 0);
	/*no define*/
	lcd_kit_get_dts_u32_default(fdt, nodeoffset, "lcd-kit,panel-bl-type",
		&pinfo->bl_set_type, 0);
	lcd_kit_get_dts_u32_default(fdt, nodeoffset, "lcd-kit,panel-bl-min",
		&pinfo->bl_min, 0);
	lcd_kit_get_dts_u32_default(fdt, nodeoffset, "lcd-kit,panel-bl-max",
		&pinfo->bl_max, 0);
	lcd_kit_get_dts_u32_default(fdt, nodeoffset, "sprd,phy-bit-clock",
		&pinfo->data_rate, 0);
	lcd_kit_get_dts_u32_default(fdt, nodeoffset, "lcd-kit,mipi-lane-nums",
		&pinfo->mipi.lane_nums, 0);
	lcd_kit_get_dts_u32_default(fdt, nodeoffset,
		"lcd-kit,panel-interface",
		&pinfo->panel_interface, 0);
	lcd_kit_get_dts_u32_default(fdt, nodeoffset,
		"lcd-kit,mipi-phy-mode",
		&pinfo->mipi.phy_mode, 0);
	lcd_kit_get_dts_u32_default(fdt, nodeoffset,
		"lcd-kit,mipi-non-continue-enable",
		&pinfo->mipi.non_continue_en, 0);
	lcd_kit_get_dts_u32_default(fdt, nodeoffset,
		"lcd-kit,panel-dsi-mode",
		&pinfo->panel_dsi_mode, 0);
	lcd_kit_get_dts_u32_default(fdt, nodeoffset,
		"lcd-kit,panel-bl-ic-ctrl-type",
		&pinfo->bl_ic_ctrl_mode, 0);
	lcd_kit_get_dts_u32_default(fdt, nodeoffset,
		"lcd-kit,panel-bias-ic-ctrl-type",
		&pinfo->bias_ic_ctrl_mode, 0);
	lcd_kit_get_dts_u32_default(fdt, nodeoffset,
		"lcd-kit,panel-bl-max-nit",
		&pinfo->bl_max_nit, 0);
	lcd_kit_get_dts_u32_default(fdt, nodeoffset,
		"lcd-kit,panel-bl-boot",
		&pinfo->bl_boot, BL_BOOT_DEF);
	lcd_kit_get_dts_u32_default(fdt, nodeoffset,
		"lcd-kit,panel-getblmaxnit-type",
		&pinfo->blmaxnit.get_blmaxnit_type, 0);
	if (pinfo->blmaxnit.get_blmaxnit_type == GET_BLMAXNIT_FROM_DDIC)
		lcd_kit_parse_dts_dcs_cmds(fdt, nodeoffset,
			"lcd-kit,panel-bl-maxnit-command",
			"lcd-kit,panel-bl-maxnit-command-state",
			&pinfo->blmaxnit.bl_maxnit_cmds);
	lcd_kit_get_dts_u32_default(fdt, nodeoffset,
		"lcd-kit,panel-max-nit-adjust",
		&pinfo->panel_max_nit_adjust, 0);
	lcd_kit_get_dts_u32_default(fdt, nodeoffset,
		"lcd-kit,panel-max-nit-refer",
		&pinfo->panel_max_nit_refer, 0);
	lcd_kit_get_dts_u32_default(fdt, nodeoffset,
		"lcd-kit,mipi-read-gerneric",
		&pinfo->mipi_read_gcs_support, 1);
	lcd_kit_get_dts_u32_default(fdt, nodeoffset,
		"lcd-kit,panel-blmaxnit-min-value",
		&pinfo->bl_max_nit_min_value, BL_NIT);
	return ret;
}

static void lcd_kit_parse_power(const void *fdt, int nodeoffset)
{
	if (fdt == NULL) {
		LCD_KIT_ERR("fdt is null\n");
		return LCD_KIT_FAIL;
	}
	if (power_hdl == NULL) {
		LCD_KIT_ERR("power_hdl is null\n");
		return;
	}
	/* vci */
	if (power_hdl->lcd_vci.buf == NULL)
		lcd_kit_parse_dts_array(fdt, nodeoffset, "lcd-kit,lcd-vci",
			&power_hdl->lcd_vci);
	/* iovcc */
	if (power_hdl->lcd_iovcc.buf == NULL)
		lcd_kit_parse_dts_array(fdt, nodeoffset, "lcd-kit,lcd-iovcc",
			&power_hdl->lcd_iovcc);
	/* vsp */
	if (power_hdl->lcd_vsp.buf == NULL)
		lcd_kit_parse_dts_array(fdt, nodeoffset, "lcd-kit,lcd-vsp",
			&power_hdl->lcd_vsp);
	/* vsn */
	if (power_hdl->lcd_vsn.buf == NULL)
		lcd_kit_parse_dts_array(fdt, nodeoffset, "lcd-kit,lcd-vsn",
			&power_hdl->lcd_vsn);
	/* lcd reset */
	if (power_hdl->lcd_rst.buf == NULL)
		lcd_kit_parse_dts_array(fdt, nodeoffset, "lcd-kit,lcd-reset",
			&power_hdl->lcd_rst);
	/* backlight */
	if (power_hdl->lcd_backlight.buf == NULL)
		lcd_kit_parse_dts_array(fdt, nodeoffset, "lcd-kit,lcd-backlight",
			&power_hdl->lcd_backlight);
	/* TE0 */
	if (power_hdl->lcd_te0.buf == NULL)
		lcd_kit_parse_dts_array(fdt, nodeoffset, "lcd-kit,lcd-te0",
			&power_hdl->lcd_te0);
	/* tp reset */
	if (power_hdl->tp_rst.buf == NULL)
		lcd_kit_parse_dts_array(fdt, nodeoffset, "lcd-kit,tp-reset",
			&power_hdl->tp_rst);
	/* lcd vdd */
	if (power_hdl->lcd_vdd.buf == NULL)
		lcd_kit_parse_dts_array(fdt, nodeoffset, "lcd-kit,lcd-vdd",
			&power_hdl->lcd_vdd);
	if (power_hdl->lcd_aod.buf == NULL)
		lcd_kit_parse_dts_array(fdt, nodeoffset, "lcd-kit,lcd-aod",
			&power_hdl->lcd_aod);
	if (power_hdl->lcd_poweric.buf == NULL)
		lcd_kit_parse_dts_array(fdt, nodeoffset, "lcd-kit,lcd-poweric",
			&power_hdl->lcd_poweric);
}

static void lcd_kit_parse_power_seq(const void *fdt, int nodeoffset)
{
	if (fdt == NULL) {
		LCD_KIT_ERR("fdt is null\n");
		return LCD_KIT_FAIL;
	}
	if (power_seq == NULL) {
		LCD_KIT_ERR("power_seq is null\n");
		return;
	}
	/* here 3 means 3 arrays */
	lcd_kit_parse_dts_arrays(fdt, nodeoffset, "lcd-kit,power-on-stage",
		&power_seq->power_on_seq, 3);
	lcd_kit_parse_dts_arrays(fdt, nodeoffset, "lcd-kit,lp-on-stage",
		&power_seq->panel_on_lp_seq, 3);
	lcd_kit_parse_dts_arrays(fdt, nodeoffset, "lcd-kit,hs-on-stage",
		&power_seq->panel_on_hs_seq, 3);
	lcd_kit_parse_dts_arrays(fdt, nodeoffset, "lcd-kit,power-off-stage",
		&power_seq->power_off_seq, 3);
	lcd_kit_parse_dts_arrays(fdt, nodeoffset, "lcd-kit,hs-off-stage",
		&power_seq->panel_off_hs_seq, 3);
	lcd_kit_parse_dts_arrays(fdt, nodeoffset, "lcd-kit,lp-off-stage",
		&power_seq->panel_off_lp_seq, 3);
}

static void lcd_kit_parse_common_info(const void *fdt, int nodeoffset)
{
	if (fdt == NULL) {
		LCD_KIT_ERR("fdt is null\n");
		return LCD_KIT_FAIL;
	}
	if (common_info == NULL) {
		LCD_KIT_ERR("common_info is null\n");
		return;
	}
	/* panel cmds */
	lcd_kit_parse_dts_dcs_cmds(fdt, nodeoffset, "lcd-kit,panel-on-cmds",
		"lcd-kit,panel-on-cmds-state", &common_info->panel_on_cmds);
	lcd_kit_parse_dts_dcs_cmds(fdt, nodeoffset, "lcd-kit,panel-off-cmds",
		"lcd-kit,panel-off-cmds-state", &common_info->panel_off_cmds);
	/* backlight */
	lcd_kit_parse_dts_dcs_cmds(fdt, nodeoffset, "lcd-kit,backlight-cmds",
	"lcd-kit,backlight-cmds-state", &common_info->backlight.bl_cmd);
	lcd_kit_get_dts_u32_default(fdt, nodeoffset, "lcd-kit,backlight-order",
		&common_info->backlight.order, 0);
	lcd_kit_get_dts_u32_default(fdt, nodeoffset, "lcd-kit,panel-bl-max",
		&common_info->backlight.bl_max, 0);
	lcd_kit_get_dts_u32_default(fdt, nodeoffset, "lcd-kit,panel-bl-min",
		&common_info->backlight.bl_min, 0);
	/* check backlight short/open */
	lcd_kit_get_dts_u32_default(fdt, nodeoffset, "lcd-kit,check-bl-support",
		&common_info->check_bl_support, 0);
	/* check reg on */
	lcd_kit_get_dts_u32_default(fdt, nodeoffset,
		"lcd-kit,check-reg-on-support",
		&common_info->check_reg_on.support, 0);
	if (common_info->check_reg_on.support) {
		lcd_kit_parse_dts_dcs_cmds(fdt, nodeoffset, "lcd-kit,check-reg-on-cmds",
			"lcd-kit,check-reg-on-cmds-state",
			&common_info->check_reg_on.cmds);
		lcd_kit_parse_dts_array(fdt, nodeoffset, "lcd-kit,check-reg-on-value",
			&common_info->check_reg_on.value);
		lcd_kit_get_dts_u32_default(fdt, nodeoffset,
			"lcd-kit,check-reg-on-support-dsm-report",
			&common_info->check_reg_on.support_dsm_report, 0);
	}
	/* check reg off */
	lcd_kit_get_dts_u32_default(fdt, nodeoffset,
		"lcd-kit,check-reg-off-support",
		&common_info->check_reg_off.support, 0);
	if (common_info->check_reg_off.support) {
		lcd_kit_parse_dts_dcs_cmds(fdt, nodeoffset, "lcd-kit,check-reg-off-cmds",
			"lcd-kit,check-reg-off-cmds-state",
			&common_info->check_reg_off.cmds);
		lcd_kit_parse_dts_array(fdt, nodeoffset, "lcd-kit,check-reg-off-value",
			&common_info->check_reg_off.value);
		lcd_kit_get_dts_u32_default(fdt, nodeoffset,
			"lcd-kit,check-reg-off-support-dsm-report",
			&common_info->check_reg_off.support_dsm_report, 0);
	}
}

static void lcd_kit_parse_effect(const void *fdt, int nodeoffset)
{
	if (fdt == NULL) {
		LCD_KIT_ERR("fdt is null\n");
		return LCD_KIT_FAIL;
	}
	if (common_info == NULL) {
		LCD_KIT_ERR("common_info is null\n");
		return;
	}
	/* effect on support */
	lcd_kit_get_dts_u32_default(fdt, nodeoffset, "lcd-kit,effect-on-support",
		&common_info->effect_on.support, 0);
	if (common_info->effect_on.support)
		lcd_kit_parse_dts_dcs_cmds(fdt, nodeoffset, "lcd-kit,effect-on-cmds",
			"lcd-kit,effect-on-cmds-state",
			&common_info->effect_on.cmds);
}

static void lcd_kit_parse_btb_check(const void *fdt, int nodeoffset)
{
	lcd_kit_get_dts_u32_default(fdt, nodeoffset, "lcd-kit,lcd-btb-support",
		&common_info->btb_support, 0);

	if (common_info->btb_support) {
		lcd_kit_get_dts_u32_default(fdt, nodeoffset, "lcd-kit,lcd-btb-check-type",
			&common_info->btb_check_type, 0);

		lcd_kit_parse_dts_array(fdt, nodeoffset, "lcd-kit,lcd-btb-gpio",
			&common_info->lcd_btb_gpio);
	}
}

static void lcd_kit_common_info_init(const void *fdt, int nodeoffset)
{
	if (fdt == NULL) {
		LCD_KIT_ERR("fdt is null\n");
		return;
	}
	lcd_kit_parse_common_info(fdt, nodeoffset);
	lcd_kit_parse_power_seq(fdt, nodeoffset);
	lcd_kit_parse_power(fdt, nodeoffset);
	lcd_kit_parse_effect(fdt, nodeoffset);
	/* btb check */
	lcd_kit_parse_btb_check(fdt, nodeoffset);
}

void lcd_kit_disp_on_check_delay(void)
{
	unsigned long delta_time;
	unsigned int delay_margin;
	int max_delay_margin = MAX_DELAY_TIME;

	if (disp_info == NULL) {
		LCD_KIT_INFO("disp_info is NULL\n");
		return;
	}
	delta_time = get_timer(disp_info->quickly_sleep_out.panel_on_record);
	if (delta_time >= disp_info->quickly_sleep_out.interval) {
		LCD_KIT_INFO("%lu > %d, no need delay\n",
			delta_time,
			disp_info->quickly_sleep_out.interval);
		disp_info->quickly_sleep_out.panel_on_tag = false;
		return;
	}
	delay_margin = disp_info->quickly_sleep_out.interval -
		delta_time;
	if (delay_margin > max_delay_margin) {
		LCD_KIT_INFO("something maybe error");
		disp_info->quickly_sleep_out.panel_on_tag = false;
		return;
	}
	mdelay(delay_margin);
	disp_info->quickly_sleep_out.panel_on_tag = false;
}

void lcd_kit_disp_on_record_time(void)
{
	if (disp_info == NULL) {
		LCD_KIT_INFO("disp_info is NULL\n");
		return;
	}
	disp_info->quickly_sleep_out.panel_on_record = get_timer(0);
	LCD_KIT_INFO("display on at %lu mil seconds\n",
		disp_info->quickly_sleep_out.panel_on_record);
	disp_info->quickly_sleep_out.panel_on_tag = true;
}

int lcd_kit_utils_init(struct sprd_panel_info *pinfo,
	const void *fdt, int nodeoffset)
{
	int ret = LCD_KIT_OK;

	if (pinfo == NULL) {
		LCD_KIT_ERR("pinfo is NULL!\n");
		return LCD_KIT_FAIL;
	}
	if (fdt == NULL) {
		LCD_KIT_ERR("fdt is NULL!\n");
		return LCD_KIT_FAIL;
	}
	/* common init */
	lcd_kit_common_info_init(fdt, nodeoffset);
	/* pinfo init */
	lcd_kit_pinfo_init(fdt, nodeoffset, pinfo);
	/* parse panel dts */
	lcd_kit_parse_disp_info(fdt, nodeoffset);
	return ret;
}
