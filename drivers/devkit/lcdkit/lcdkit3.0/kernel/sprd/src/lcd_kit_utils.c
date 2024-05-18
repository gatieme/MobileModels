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
#include <linux/time.h>
#include "lcd_kit_common.h"
#include "lcd_kit_parse.h"
#include "lcd_kit_adapt.h"
#include "lcd_kit_core.h"
#include "lcd_kit_sysfs_sprd.h"
#include "lcd_kit_drm_panel.h"
#ifdef LCD_FACTORY_MODE
#include "lcd_kit_factory.h"
#endif

#define MAX_DELAY_TIME 200
#define AOD_V_START_MASK 0xFFFF0000
#define ALPM_SETTING_CASE_MASK 0xFFFF
#if defined CONFIG_HONOR_DSM
extern struct dsm_client *lcd_dclient;
#endif
/* pcd add detect number */
static uint32_t error_num_pcd;

bool lcd_kit_support(void)
{
	struct device_node *lcdkit_np = NULL;
	const char *support_type = NULL;
	ssize_t ret;

	lcdkit_np = of_find_compatible_node(NULL, NULL,
		DTS_COMP_LCD_KIT_PANEL_TYPE);
	if (!lcdkit_np) {
		LCD_KIT_ERR("NOT FOUND device node!\n");
		return false;
	}
	ret = of_property_read_string(lcdkit_np, "support_lcd_type",
		&support_type);
	if (ret) {
		LCD_KIT_ERR("failed to get support_type\n");
		return false;
	}
	if (!strncmp(support_type, "LCD_KIT", strlen("LCD_KIT"))) {
		LCD_KIT_INFO("lcd_kit is support!\n");
		return true;
	}
	LCD_KIT_INFO("lcd_kit is not support!\n");
	return false;
}

int lcd_kit_lread_reg(void *pdata, uint32_t *out,
	struct lcd_kit_dsi_cmd_desc *cmds, uint32_t len)
{
	return LCD_KIT_OK;
}

static int lcd_kit_check_project_id(void)
{
	int i;

	for (i = 0; i < PROJECTID_LEN; i++) {
		if (isalnum((disp_info->project_id.id)[i]) == 0 &&
			isdigit((disp_info->project_id.id)[i]) == 0)
			return LCD_KIT_FAIL;
	}

	return LCD_KIT_OK;
}

int lcd_kit_read_project_id(void)
{
	int ret;
	if (!disp_info) {
		LCD_KIT_ERR("disp_info is null\n");
		return LCD_KIT_FAIL;
	}

	if (disp_info->project_id.support) {
		memset(disp_info->project_id.id, 0,
			sizeof(disp_info->project_id.id));
		ret = lcd_kit_dsi_cmds_extern_rx(disp_info->project_id.id,
			&disp_info->project_id.cmds, LCD_DDIC_INFO_LEN - 1);
		if (ret) {
			LCD_KIT_ERR("read project id fail\n");
			return LCD_KIT_FAIL;
		}

		if (lcd_kit_check_project_id() == LCD_KIT_OK) {
			LCD_KIT_ERR("project id check fail\n");
			return LCD_KIT_FAIL;
		}

		LCD_KIT_INFO("read project id is %s\n",
			disp_info->project_id.id);
		return LCD_KIT_OK;
	} else {
		LCD_KIT_ERR("project id is not support!\n");
		return LCD_KIT_FAIL;
	}
}

int lcd_kit_updt_fps(struct platform_device *pdev)
{
	return LCD_KIT_OK;
}

int lcd_kit_updt_fps_scence(struct platform_device *pdev, uint32_t scence)
{
	return LCD_KIT_OK;
}

void lcd_kit_disp_on_check_delay(void)
{
	long delta_time_bl_to_panel_on;
	unsigned int delay_margin;
	struct timeval tv = {0};
	int max_delay_margin = MAX_DELAY_TIME;

	if (disp_info == NULL) {
		LCD_KIT_INFO("disp_info is NULL\n");
		return;
	}
	memset(&tv, 0, sizeof(struct timeval));
	do_gettimeofday(&tv);
	/* change s to us */
	delta_time_bl_to_panel_on = (tv.tv_sec - disp_info->quickly_sleep_out.panel_on_record_tv.tv_sec) *
		1000000 + tv.tv_usec - disp_info->quickly_sleep_out.panel_on_record_tv.tv_usec;
	/* change us to ms */
	delta_time_bl_to_panel_on /= 1000;
	if (delta_time_bl_to_panel_on >= disp_info->quickly_sleep_out.interval) {
		LCD_KIT_INFO("%lu > %d, no need delay\n",
			delta_time_bl_to_panel_on,
			disp_info->quickly_sleep_out.interval);
		disp_info->quickly_sleep_out.panel_on_tag = false;
		return;
	}
	delay_margin = disp_info->quickly_sleep_out.interval -
		delta_time_bl_to_panel_on;
	if (delay_margin > max_delay_margin) {
		LCD_KIT_INFO("something maybe error");
		disp_info->quickly_sleep_out.panel_on_tag = false;
		return;
	}
	msleep(delay_margin);
	LCD_KIT_INFO("backlight on delay %u ms\n", delay_margin);
	disp_info->quickly_sleep_out.panel_on_tag = false;
}

void lcd_kit_disp_on_record_time(void)
{
	if (disp_info == NULL) {
		LCD_KIT_INFO("disp_info is NULL\n");
		return;
	}
	do_gettimeofday(&disp_info->quickly_sleep_out.panel_on_record_tv);
	LCD_KIT_INFO("display on at %lu seconds %lu mil seconds\n",
		disp_info->quickly_sleep_out.panel_on_record_tv.tv_sec,
		disp_info->quickly_sleep_out.panel_on_record_tv.tv_usec);
	disp_info->quickly_sleep_out.panel_on_tag = true;
}

void lcd_kit_pinfo_init(struct device_node *np, struct sprd_panel_info *pinfo)
{
	if (pinfo == NULL || np == NULL) {
		LCD_KIT_ERR("pinfo or np is null\n");
		return;
	}
	pinfo->np = np;
	OF_PROPERTY_READ_U32_DEFAULT(np, "lcd-kit,panel-xres",
		&pinfo->xres, 1440);
	OF_PROPERTY_READ_U32_DEFAULT(np, "lcd-kit,panel-yres",
		&pinfo->yres, 2560);
	OF_PROPERTY_READ_U32_DEFAULT(np, "lcd-kit,panel-width",
		&pinfo->width, 73);
	OF_PROPERTY_READ_U32_DEFAULT(np, "lcd-kit,panel-height",
		&pinfo->height, 130);
	OF_PROPERTY_READ_U32_DEFAULT(np, "lcd-kit,panel-bl-type",
		&pinfo->bl_set_type, 0);
	OF_PROPERTY_READ_U32_DEFAULT(np, "lcd-kit,panel-bl-min",
		&pinfo->bl_min, 0);
	OF_PROPERTY_READ_U32_DEFAULT(np, "lcd-kit,panel-bl-max",
		&pinfo->bl_max, 0);
	OF_PROPERTY_READ_U32_DEFAULT(np, "lcd-kit,panel-cmd-type",
		&pinfo->type, 0);
	OF_PROPERTY_READ_U32_DEFAULT(np, "lcd-kit,panel-bl-ic-ctrl-type",
		&pinfo->bl_ic_ctrl_mode, 0);
	OF_PROPERTY_READ_U32_DEFAULT(np, "lcd-kit,panel-gpio-offset",
		&pinfo->gpio_offset, 0);
	OF_PROPERTY_READ_U32_DEFAULT(np, "lcd-kit,imax-lcd-luminance",
		&pinfo->maxluminance, 0);
	OF_PROPERTY_READ_U32_DEFAULT(np, "lcd-kit,imin-lcd-luminance",
		&pinfo->minluminance, 0);

	/* mipi info */
	OF_PROPERTY_READ_U32_RETURN(np, "lcd-kit,h-back-porch",
	&pinfo->mipi.h_back_porch);
	OF_PROPERTY_READ_U32_RETURN(np, "lcd-kit,h-front-porch",
		&pinfo->mipi.h_front_porch);
	OF_PROPERTY_READ_U32_RETURN(np, "lcd-kit,h-pulse-width",
		&pinfo->mipi.h_pulse_width);
	OF_PROPERTY_READ_U32_RETURN(np, "lcd-kit,v-back-porch",
		&pinfo->mipi.v_back_porch);
	OF_PROPERTY_READ_U32_RETURN(np, "lcd-kit,v-front-porch",
		&pinfo->mipi.v_front_porch);
	OF_PROPERTY_READ_U32_RETURN(np, "lcd-kit,v-pulse-width",
		&pinfo->mipi.v_pulse_width);
	OF_PROPERTY_READ_U8_DEFAULT(np, "lcd-kit,mipi-lane-nums",
		&pinfo->mipi.lane_nums, 0);
	OF_PROPERTY_READ_U8_DEFAULT(np, "lcd-kit,mipi-non-continue-enable",
		&pinfo->mipi.non_continue_en, 0);
	OF_PROPERTY_READ_U8_DEFAULT(np, "lcd-kit,mipi-use-dcs-write",
		&pinfo->mipi.use_dcs, 0);
	OF_PROPERTY_READ_U32_DEFAULT(np, "lcd-kit,mipi-dsi-color-format",
		&pinfo->mipi.dsi_color_format, 0);

	OF_PROPERTY_READ_U8_DEFAULT(np, "lcd-kit,mipi-color-mode",
		&pinfo->mipi.color_mode, 0);
	OF_PROPERTY_READ_U32_DEFAULT(np, "lcd-kit,mipi-burst-mode",
		&pinfo->mipi.burst_mode, 0);
	OF_PROPERTY_READ_U32_DEFAULT(np, "lcd-kit,mipi-dsi-bit-clk",
		&pinfo->mipi.dsi_bit_clk, 0);
	OF_PROPERTY_READ_U32_DEFAULT(np, "lcd-kit,mipi-phy-mode",
		&pinfo->mipi.phy_mode, 0);


	OF_PROPERTY_READ_U32_DEFAULT(np, "lcd-kit,panel-interface",
		&pinfo->panel_interface, 0);
	OF_PROPERTY_READ_U32_DEFAULT(np, "lcd-kit,panel-dsi-mode",
		&pinfo->panel_dsi_mode, 0);

	/* frame rate */
	OF_PROPERTY_READ_U32_DEFAULT(np, "lcd-kit,vetical-refresh",
		&pinfo->vrefresh, 60);
	/* project id */
	OF_PROPERTY_READ_U32_DEFAULT(np, "lcd-kit,project-id-support",
		&disp_info->project_id.support, 0);
	if (disp_info->project_id.support) {
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,project-id-cmds",
			"lcd-kit,project-id-cmds-state",
			&disp_info->project_id.cmds);

		disp_info->project_id.default_project_id = (char*)of_get_property(np,
			"lcd-kit,default-project-id", NULL);
	}

	/* oem information */
	OF_PROPERTY_READ_U32_DEFAULT(np, "lcd-kit,oem-info-support",
		&disp_info->oeminfo.support, 0);

	if (disp_info->oeminfo.support) {
		OF_PROPERTY_READ_U32_DEFAULT(np, "lcd-kit,oem-barcode-2d-support",
			&disp_info->oeminfo.barcode_2d.support, 0);
		OF_PROPERTY_READ_U32_DEFAULT(np, "lcd-kit,oem-barcode-2d-num-offset",
			&disp_info->oeminfo.barcode_2d.number_offset, 0);
		if (disp_info->oeminfo.barcode_2d.support)
			lcd_kit_parse_dcs_cmds(np, "lcd-kit,barcode-2d-cmds",
				"lcd-kit,barcode-2d-cmds-state",
				&disp_info->oeminfo.barcode_2d.cmds);
	}

	/* for btb check */
	common_info->gpio_offset = pinfo->gpio_offset;
	if (common_info->esd.support) {
		pinfo->esd_enable = 1;
		OF_PROPERTY_READ_U8_DEFAULT(np,
			"lcd-kit,skip-poweron-esd-check",
			&disp_info->lcd_kit_skip_poweron_esd_check, 0);
		OF_PROPERTY_READ_U32_DEFAULT(np,
			"lcd-kit,again-esd-check-delay",
			&disp_info->lcd_kit_again_esd_check_delay, 0);
		OF_PROPERTY_READ_U32_DEFAULT(np,
			"lcd-kit,esd-check-delay",
			&disp_info->lcd_kit_esd_check_delay, 0);
		OF_PROPERTY_READ_U8_DEFAULT(np,
			"lcd-kit,skip-esd-check-cnt",
			&disp_info->lcd_kit_skip_esd_check_cnt, 0);
	}
}

void lcd_kit_parse_running(struct device_node *np)
{
}

void lcd_kit_parse_effect(struct device_node *np)
{
	/* rgbw */
	lcd_kit_parse_u32(np, "lcd-kit,rgbw-support",
		&disp_info->rgbw.support, 0);
	if (disp_info->rgbw.support) {
		lcd_kit_parse_u32(np, "lcd-kit,rgbw-bl-max",
			&disp_info->rgbw.rgbw_bl_max, 0);
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,rgbw-mode1-cmds",
			"lcd-kit,rgbw-mode1-cmds-state",
			&disp_info->rgbw.mode1_cmds);
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,rgbw-mode2-cmds",
			"lcd-kit,rgbw-mode2-cmds-state",
			&disp_info->rgbw.mode2_cmds);
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,rgbw-mode3-cmds",
			"lcd-kit,rgbw-mode3-cmds-state",
			&disp_info->rgbw.mode3_cmds);
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,rgbw-mode4-cmds",
			"lcd-kit,rgbw-mode4-cmds-state",
			&disp_info->rgbw.mode4_cmds);
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,rgbw-backlight-cmds",
			"lcd-kit,rgbw-backlight-cmds-state",
			&disp_info->rgbw.backlight_cmds);
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,rgbw-pixel-gain-limit-cmds",
			"lcd-kit,rgbw-pixel-gain-limit-cmds-state",
			&disp_info->rgbw.pixel_gain_limit_cmds);
	}
}

void lcd_kit_parse_fps(struct device_node *np)
{
	int index;
	int i;

	lcd_kit_parse_array_data(np, "lcd-kit,panel-support-fps-list",
		&disp_info->fps.panel_support_fps_list);

	if (disp_info->fps.panel_support_fps_list.buf == NULL ||
		disp_info->fps.panel_support_fps_list.cnt == 0) {
		LCD_KIT_ERR("support list is null\n");
		return;
	}

	/* hopping */
	lcd_kit_parse_u32(np, "lcd-kit,mipi-hop-support",
		&disp_info->fps.hop_support, 0);

	for (i = 0; i < disp_info->fps.panel_support_fps_list.cnt; i++) {
		index = disp_info->fps.panel_support_fps_list.buf[i];
		if (index == LCD_FPS_SCENCE_60) {
			lcd_kit_parse_dcs_cmds(np, "lcd-kit,fps-to-normal-60-cmds",
				"lcd-kit,fps-to-normal-60-cmds-state",
				&disp_info->fps.fps_to_cmds[index]);
			lcd_kit_parse_array_data(np, "lcd-kit,fps-normal-60-dsi-timming",
				&disp_info->fps.fps_dsi_timming[index]);
			/* hopping */
			if (disp_info->fps.hop_support)
				lcd_kit_parse_array_data(np, "lcd-kit,fps-normal-60-mipi-hopping",
					&disp_info->fps.hop_info[index]);
		} else if (index == LCD_FPS_SCENCE_H60) {
			lcd_kit_parse_dcs_cmds(np, "lcd-kit,fps-to-high-60-cmds",
				"lcd-kit,fps-to-high-60-cmds-state",
				&disp_info->fps.fps_to_cmds[index]);
			lcd_kit_parse_array_data(np, "lcd-kit,fps-high-60-dsi-timming",
				&disp_info->fps.fps_dsi_timming[index]);
			/* hopping */
			if (disp_info->fps.hop_support)
				lcd_kit_parse_array_data(np, "lcd-kit,fps-high-60-mipi-hopping",
					&disp_info->fps.hop_info[index]);
		} else if (index == LCD_FPS_SCENCE_90) {
			lcd_kit_parse_dcs_cmds(np, "lcd-kit,fps-to-90-cmds",
				"lcd-kit,fps-to-90-cmds-state",
				&disp_info->fps.fps_to_cmds[index]);
			lcd_kit_parse_array_data(np, "lcd-kit,fps-90-dsi-timming",
				&disp_info->fps.fps_dsi_timming[index]);
			/* hopping */
			if (disp_info->fps.hop_support)
				lcd_kit_parse_array_data(np, "lcd-kit,fps-90-mipi-hopping",
					&disp_info->fps.hop_info[index]);
		} else if (index == LCD_FPS_SCENCE_120) {
			lcd_kit_parse_dcs_cmds(np, "lcd-kit,fps-to-120-cmds",
				"lcd-kit,fps-to-120-cmds-state",
				&disp_info->fps.fps_to_cmds[index]);
			lcd_kit_parse_array_data(np, "lcd-kit,fps-120-dsi-timming",
				&disp_info->fps.fps_dsi_timming[index]);
			/* hopping */
			if (disp_info->fps.hop_support)
				lcd_kit_parse_array_data(np, "lcd-kit,fps-120-mipi-hopping",
					&disp_info->fps.hop_info[index]);
		}
	}
}

void lcd_kit_parse_alpm(struct device_node *np)
{
	lcd_kit_parse_u32(np, "lcd-kit,aod-need-reset",
		&disp_info->alpm.need_reset, 0);
	lcd_kit_parse_dcs_cmds(np, "lcd-kit,panel-enter-aod-cmds",
		"lcd-kit,panel-enter-aod-cmds-state",
		&disp_info->alpm.off_cmds);
	lcd_kit_parse_dcs_cmds(np, "lcd-kit,panel-exit-aod-cmds",
		"lcd-kit,panel-exit-aod-cmds-state",
		&disp_info->alpm.exit_cmds);
	lcd_kit_parse_dcs_cmds(np, "lcd-kit,panel-aod-high-brightness-cmds",
		"lcd-kit,panel-aod-high-brightness-cmds-state",
		&disp_info->alpm.high_light_cmds);
	lcd_kit_parse_dcs_cmds(np, "lcd-kit,panel-aod-low-brightness-cmds",
		"lcd-kit,panel-aod-low-brightness-cmds-state",
		&disp_info->alpm.low_light_cmds);
	lcd_kit_parse_dcs_cmds(np, "lcd-kit,panel-aod-on-double-clock-cmds",
		"lcd-kit,panel-aod-on-double-clock-cmds-state",
		&disp_info->alpm.double_clock_cmds);
	lcd_kit_parse_dcs_cmds(np, "lcd-kit,panel-aod-on-single-clock-cmds",
		"lcd-kit,panel-aod-on-single-clock-cmds-state",
		&disp_info->alpm.single_clock_cmds);
	lcd_kit_parse_u32(np, "lcd-kit,ap-aod-doze-delay",
		&disp_info->alpm.doze_delay, 1);
	lcd_kit_parse_dcs_cmds(np, "lcd-kit,panel-aod-middle-brightness-cmds",
		"lcd-kit,panel-aod-middle-brightness-cmds-state",
		&disp_info->alpm.middle_light_cmds);
}

void lcd_kit_parse_util(struct device_node *np)
{
	if (np == NULL) {
		LCD_KIT_ERR("np is null\n");
		return;
	}
	/* pre power off */
	lcd_kit_parse_u32(np, "lcd-kit,panel-pre-power-off",
		&disp_info->pre_power_off, 0);
	/* quickly sleep out */
	lcd_kit_parse_u32(np, "lcd-kit,quickly-sleep-out-support",
		&disp_info->quickly_sleep_out.support, 0);
	if (disp_info->quickly_sleep_out.support)
		lcd_kit_parse_u32(np,
			"lcd-kit,quickly-sleep-out-interval",
			&disp_info->quickly_sleep_out.interval, 0);

	/* fps */
	lcd_kit_parse_u32(np, "lcd-kit,fps-support",
		&disp_info->fps.support, 0);
	if (disp_info->fps.support)
		lcd_kit_parse_fps(np);

	/* alpm */
	lcd_kit_parse_u32(np, "lcd-kit,ap-aod-support",
		&disp_info->alpm.support, 0);
	if (disp_info->alpm.support)
		lcd_kit_parse_alpm(np);
	/* hbm set*/
	lcd_kit_parse_u32(np, "lcd-kit,fphbm-entry-delay-afterBL",
		&disp_info->hbm_entry_delay, 0);
	lcd_kit_parse_u32(np, "lcd-kit,te-interval-time-us",
		&disp_info->te_interval_us, 0);
	lcd_kit_parse_u32(np, "lcd-kit,hbm-en-times",
		&disp_info->hbm_en_times, 2);
	lcd_kit_parse_u32(np, "lcd-kit,hbm-dis-times",
		&disp_info->hbm_dis_times, 1);

	/* regulator name */
	disp_info->vci_regulator_name = (char *)of_get_property(np,
		"lcd-kit,vci-name", NULL);
	disp_info->iovcc_regulator_name = (char *)of_get_property(np,
		"lcd-kit,iovcc-name", NULL);
	disp_info->vdd_regulator_name = (char *)of_get_property(np,
		"lcd-kit,vdd-name", NULL);
	/* elvdd detect */
	lcd_kit_parse_u32(np, "lcd-kit,elvdd-detect-support",
		&disp_info->elvdd_detect.support, 0);
	if (disp_info->elvdd_detect.support) {
		lcd_kit_parse_u32(np, "lcd-kit,elvdd-detect-type",
			&disp_info->elvdd_detect.detect_type, 0);
		if (disp_info->elvdd_detect.detect_type ==
			ELVDD_MIPI_CHECK_MODE)
			lcd_kit_parse_dcs_cmds(np, "lcd-kit,elvdd-detect-cmds",
				"lcd-kit,elvdd-detect-cmds-state",
				&disp_info->elvdd_detect.cmds);
		else
			lcd_kit_parse_u32(np,
				"lcd-kit,elvdd-detect-gpio",
				&disp_info->elvdd_detect.detect_gpio, 0);
		lcd_kit_parse_u32(np,
			"lcd-kit,elvdd-detect-value",
			&disp_info->elvdd_detect.exp_value, 0);
		lcd_kit_parse_u32(np,
			"lcd-kit,elvdd-value-mask",
			&disp_info->elvdd_detect.exp_value_mask, 0);
		lcd_kit_parse_u32(np,
			"lcd-kit,elvdd-delay",
			&disp_info->elvdd_detect.delay, 0);
	}
}

static void parse_dt_pcd(struct device_node *np)
{
	/* pcd errflag */
	lcd_kit_parse_u32(np, "lcd-kit,pcd-errflag-check-support",
		&disp_info->pcd_errflag.pcd_errflag_check_support, 0);
	lcd_kit_parse_u32(np, "lcd-kit,gpio-pcd",
		&disp_info->pcd_errflag.gpio_pcd, 0);
	lcd_kit_parse_u32(np, "lcd-kit,gpio-errflag",
		&disp_info->pcd_errflag.gpio_errflag, 0);
	lcd_kit_parse_u32(np, "lcd-kit,pcd-cmds-support",
		&disp_info->pcd_errflag.pcd_support, 0);
	if (disp_info->pcd_errflag.pcd_support) {
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,start-pcd-check-cmds",
			"lcd-kit,start-pcd-check-cmds-state",
			&disp_info->pcd_errflag.start_pcd_check_cmds);
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,pcd-read-cmds",
			"lcd-kit,pcd-read-cmds-state",
			&disp_info->pcd_errflag.read_pcd_cmds);
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,switch-page-cmds",
			"lcd-kit,switch-page-cmds-state",
			&disp_info->pcd_errflag.switch_page_cmds);
		lcd_kit_parse_array_data(np, "lcd-kit,pcd-check-reg-value",
			&disp_info->pcd_errflag.pcd_value);
		lcd_kit_parse_u32(np, "lcd-kit,pcd-check-reg-value-compare-mode",
			&disp_info->pcd_errflag.pcd_value_compare_mode, 0);
		lcd_kit_parse_u32(np, "lcd-kit,exp-pcd-mask",
			&disp_info->pcd_errflag.exp_pcd_mask, 0);
		lcd_kit_parse_u32(np, "lcd-kit,pcd-det-num",
			&disp_info->pcd_errflag.pcd_det_num, 1);
	}
	lcd_kit_parse_u32(np, "lcd-kit,errflag-cmds-support",
		&disp_info->pcd_errflag.errflag_support, 0);
	if (disp_info->pcd_errflag.errflag_support)
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,errflag-read-cmds",
			"lcd-kit,errflag-read-cmds-state",
			&disp_info->pcd_errflag.read_errflag_cmds);
}

#ifdef LCD_FACTORY_MODE
static void parse_dt_pcd_errflag(struct device_node *np)
{
	/* pcd errflag check */
	lcd_kit_parse_u32(np, "lcd-kit,pcd-errflag-check-support",
		&FACT_INFO->pcd_errflag_check.pcd_errflag_check_support, 0);
	if (FACT_INFO->pcd_errflag_check.pcd_errflag_check_support) {
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,pcd-detect-open-cmds",
			"lcd-kit,pcd-read-cmds-state",
			&FACT_INFO->pcd_errflag_check.pcd_detect_open_cmds);
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,pcd-detect-close-cmds",
			"lcd-kit,pcd-read-cmds-state",
			&FACT_INFO->pcd_errflag_check.pcd_detect_close_cmds);
	}
}
#endif

void lcd_kit_parse_dt(struct device_node *np)
{
	if (!np) {
		LCD_KIT_ERR("np is null\n");
		return;
	}
	/* parse running test */
	lcd_kit_parse_running(np);
	/* parse effect info */
	lcd_kit_parse_effect(np);
	/* parse normal function */
	lcd_kit_parse_util(np);
	/* parse pcd errflag test */
	parse_dt_pcd(np);
#ifdef LCD_FACTORY_MODE
	parse_dt_pcd_errflag(np);
#endif
}

int lcd_kit_get_bl_max_nit_from_dts(void)
{
	int ret;
	struct device_node *np = NULL;

	np = of_find_compatible_node(NULL, NULL,
		DTS_COMP_LCD_KIT_PANEL_TYPE);
	if (!np) {
		LCD_KIT_ERR("NOT FOUND device node %s!\n",
			DTS_COMP_LCD_KIT_PANEL_TYPE);
		ret = -1;
		return ret;
	}
	OF_PROPERTY_READ_U32_RETURN(np, "panel_ddic_max_brightness",
		&common_info->actual_bl_max_nit);
	LCD_KIT_INFO("max nit is %d\n", common_info->actual_bl_max_nit);

	return LCD_KIT_OK;
}

static int lcd_kit_get_project_id(char *buff)
{
	if (buff == NULL) {
		LCD_KIT_ERR("buff is null\n");
		return LCD_KIT_FAIL;
	}

	if (!disp_info) {
		LCD_KIT_ERR("disp_info is null\n");
		return LCD_KIT_FAIL;
	}

	/* use read project id */
	if (disp_info->project_id.support &&
		(strlen(disp_info->project_id.id) > 0)) {
		strncpy(buff, disp_info->project_id.id,
			strlen(disp_info->project_id.id));
		LCD_KIT_INFO("use read project id is %s\n",
			disp_info->project_id.id);
		return LCD_KIT_OK;
	}

	/* use default project id */
	if (disp_info->project_id.support &&
		disp_info->project_id.default_project_id) {
		strncpy(buff, disp_info->project_id.default_project_id,
			PROJECTID_LEN);
		LCD_KIT_INFO("use default project id:%s\n",
			disp_info->project_id.default_project_id);
		return LCD_KIT_OK;
	}

	LCD_KIT_ERR("not support get project id\n");
	return LCD_KIT_FAIL;
}

int lcd_kit_get_online_status(void)
{
	int status = LCD_ONLINE;

	if (!strncmp(disp_info->compatible, LCD_KIT_DEFAULT_PANEL,
		strlen(disp_info->compatible)))
		/* panel is online */
		status = LCD_OFFLINE;
	LCD_KIT_INFO("status = %d\n", status);
	return status;
}

static int lcd_get_2d_barcode(char *buff)
{
	int ret;

	if (!buff) {
		LCD_KIT_ERR("buff is NULL\n");
		return LCD_KIT_FAIL;
	}

	if (!disp_info) {
		LCD_KIT_ERR("disp_info is null\n");
		return LCD_KIT_FAIL;
	}

	if (!disp_info->oeminfo.support) {
		LCD_KIT_ERR("oem info is not support\n");
		return LCD_KIT_FAIL;
	}
	ret = lcd_kit_dsi_cmds_extern_rx(buff,
		&disp_info->oeminfo.barcode_2d.cmds, LCD_KIT_SN_CODE_LENGTH);
	if (ret) {
		LCD_KIT_ERR("get 2d barcode fail\n");
		return LCD_KIT_FAIL;
	} else {
		LCD_KIT_INFO("get 2d barcode success! %s\n", buff);
		return LCD_KIT_OK;
	}
}

void lcd_kit_recovery_display(void)
{
	uint32_t bl_level_cur;
	struct sprd_panel_info *pinfo = NULL;

	pinfo = lcm_get_panel_info();
	if (!pinfo) {
		LCD_KIT_ERR("pinfo is null!\n");
		return;
	}
	LCD_KIT_INFO("recovery display.\n");
	if (!common_ops->set_mipi_backlight
		|| !common_ops->panel_power_on
		|| !common_ops->panel_power_off) {
		LCD_KIT_ERR("common_ops parameter null!\n");
		return;
	}

	bl_level_cur = pinfo->bl_current;
	/* backlight on */
	common_ops->set_mipi_backlight(NULL, 0);
	/* lcd panel off */
	common_ops->panel_power_off(NULL);
	pinfo->panel_state = LCD_POWER_STATE_OFF;
	msleep(100);
	/* lcd panel on */
	common_ops->panel_power_on(NULL);
	pinfo->panel_state = LCD_POWER_STATE_ON;
	/* backlight on */
	common_ops->set_mipi_backlight(NULL, bl_level_cur);
	return;
}

void lcd_esd_enable(int enable)
{
	struct sprd_panel_info *pinfo = NULL;

	pinfo = lcm_get_panel_info();
	if (!pinfo) {
		LCD_KIT_ERR("pinfo is null!\n");
		return;
	}
	if (common_info->esd.support) {
		pinfo->esd_enable = enable;
		msleep(500);
	}
	LCD_KIT_INFO("pinfo->esd_enable = %d\n", pinfo->esd_enable);
}

void lcd_kit_ddic_lv_detect_dmd_report(
	u8 reg_val[DETECT_LOOPS][DETECT_NUM][VAL_NUM])
{
	int i;
	int ret;
	unsigned int len;
	char err_info[DMD_DET_ERR_LEN] = {0};

	if (!reg_val) {
		LCD_KIT_ERR("reg_val is NULL\n");
		return;
	}
	for (i = 0; i < DETECT_LOOPS; i++) {
		len = strlen(err_info);
		if (len >= DMD_DET_ERR_LEN) {
			LCD_KIT_ERR("strlen error\n");
			return;
		}
		ret = snprintf(err_info + len, DMD_DET_ERR_LEN - len,
			"%d: %x %x, %x %x, %x %x, %x %x ",
			i + DET_START,
			reg_val[i][DET1_INDEX][VAL_1],
			reg_val[i][DET1_INDEX][VAL_0],
			reg_val[i][DET2_INDEX][VAL_1],
			reg_val[i][DET2_INDEX][VAL_0],
			reg_val[i][DET3_INDEX][VAL_1],
			reg_val[i][DET3_INDEX][VAL_0],
			reg_val[i][DET4_INDEX][VAL_1],
			reg_val[i][DET4_INDEX][VAL_0]);
		if (ret < 0) {
			LCD_KIT_ERR("snprintf error\n");
			return;
		}
	}
#if defined(CONFIG_HONOR_DSM)
	if (lcd_dclient && !dsm_client_ocuppy(lcd_dclient)) {
		dsm_client_record(lcd_dclient, err_info);
		dsm_client_notify(lcd_dclient, DSM_LCD_DDIC_LV_DETECT_ERROR_NO);
	}
#endif
}

int lcd_kit_rgbw_set_mode(int mode)
{
	int ret = LCD_KIT_OK;
	static int old_rgbw_mode;
	int rgbw_mode;

	if (disp_info == NULL) {
		LCD_KIT_ERR("disp_info is null\n");
		return LCD_KIT_FAIL;
	}
	rgbw_mode = disp_info->ddic_rgbw_param.ddic_rgbw_mode;
	if (rgbw_mode != old_rgbw_mode) {
		switch (mode) {
		case RGBW_SET1_MODE:
			ret = lcd_kit_dsi_cmds_extern_tx(&disp_info->rgbw.mode1_cmds);
			break;
		case RGBW_SET2_MODE:
			ret = lcd_kit_dsi_cmds_extern_tx(&disp_info->rgbw.mode2_cmds);
			break;
		case RGBW_SET3_MODE:
			ret = lcd_kit_dsi_cmds_extern_tx(&disp_info->rgbw.mode3_cmds);
			break;
		case RGBW_SET4_MODE:
			ret = lcd_kit_dsi_cmds_extern_tx(&disp_info->rgbw.mode4_cmds);
			break;
		default:
			LCD_KIT_ERR("mode err: %d\n", disp_info->ddic_rgbw_param.ddic_rgbw_mode);
			ret = LCD_KIT_FAIL;
			break;
		}
	}
	LCD_KIT_DEBUG("rgbw_mode=%d,rgbw_mode_old=%d!\n", rgbw_mode, old_rgbw_mode);
	old_rgbw_mode = rgbw_mode;
	return ret;
}

int lcd_kit_rgbw_set_backlight(int bl_level)
{
	int ret;
	unsigned int level;

	if (bl_level < 0)
		bl_level = 0;
	level = (unsigned int)bl_level;
	/* change bl level to dsi cmds */
	disp_info->rgbw.backlight_cmds.cmds[0].payload[1] = (level >> 8) & 0xff;
	disp_info->rgbw.backlight_cmds.cmds[0].payload[2] = level & 0xff;
	ret = lcd_kit_dsi_cmds_extern_tx(&disp_info->rgbw.backlight_cmds);
	return ret;
}

static int lcd_kit_rgbw_pix_gain(void)
{
	unsigned int pix_gain;
	static unsigned int pix_gain_old;
	int rgbw_mode;
	int ret = LCD_KIT_OK;

	if (disp_info->rgbw.pixel_gain_limit_cmds.cmds == NULL) {
		LCD_KIT_INFO("RGBW not support pixel_gain_limit\n");
		return ret;
	}
	rgbw_mode = disp_info->ddic_rgbw_param.ddic_rgbw_mode;
	pix_gain = (unsigned int)disp_info->ddic_rgbw_param.pixel_gain_limit;
	if ((pix_gain != pix_gain_old) && (rgbw_mode == RGBW_SET4_MODE)) {
		disp_info->rgbw.pixel_gain_limit_cmds.cmds[0].payload[1] = pix_gain;
		ret = lcd_kit_dsi_cmds_extern_tx(&disp_info->rgbw.pixel_gain_limit_cmds);
		LCD_KIT_DEBUG("RGBW pixel_gain=%u,pix_gain_old=%u\n",
			pix_gain, pix_gain_old);
		pix_gain_old = pix_gain;
	}
	return ret;
}

int lcd_kit_rgbw_set_handle(void)
{
	int ret;
	static int old_rgbw_backlight;
	int rgbw_backlight;
	int rgbw_bl_level;
	struct sprd_panel_info *panel_info = NULL;

	if (disp_info == NULL) {
		LCD_KIT_ERR("disp_info is null\n");
		return LCD_KIT_FAIL;
	}
	panel_info = lcm_get_panel_info();
	if (panel_info == NULL) {
		LCD_KIT_ERR("panel_info is NULL\n");
		return LCD_KIT_FAIL;
	}
	/* set mode */
	ret = lcd_kit_rgbw_set_mode(disp_info->ddic_rgbw_param.ddic_rgbw_mode);
	if (ret < 0) {
		LCD_KIT_ERR("RGBW set mode fail\n");
		return LCD_KIT_FAIL;
	}

	/* set backlight */
	rgbw_backlight = disp_info->ddic_rgbw_param.ddic_rgbw_backlight;
	if (disp_info->rgbw.backlight_cmds.cmds &&
		(panel_info->bl_current != 0) &&
		(rgbw_backlight != old_rgbw_backlight)) {
		rgbw_bl_level = rgbw_backlight * disp_info->rgbw.rgbw_bl_max /
			panel_info->bl_max;
		ret = lcd_kit_rgbw_set_backlight(rgbw_bl_level);
		if (ret < 0) {
			LCD_KIT_ERR("RGBW set backlight fail\n");
			return LCD_KIT_FAIL;
		}
	}
	old_rgbw_backlight = rgbw_backlight;

	/* set gain */
	ret = lcd_kit_rgbw_pix_gain();
	if (ret) {
		LCD_KIT_INFO("RGBW set pix_gain fail\n");
		return LCD_KIT_FAIL;
	}
	return ret;
}

static int lcd_kit_gpio_pcd_errflag_read(const int gpio_no, int *read_value)
{
	if (!gpio_no) {
		/* only pcd check or only errflag check */
		LCD_KIT_INFO("gpio_no is 0\n");
		return LCD_KIT_OK;
	}

	if (gpio_request(gpio_no, GPIO_PCD_ERRFLAG_NAME)) {
		LCD_KIT_ERR("pcd_errflag_gpio[%d] request fail!\n", gpio_no);
		return LCD_KIT_FAIL;
	}
	if (gpio_direction_input(gpio_no)) {
		gpio_free(gpio_no);
		LCD_KIT_ERR("pcd_errflag_gpio[%d] direction set fail!\n",
			gpio_no);
		return LCD_KIT_FAIL;
	}
	*read_value = gpio_get_value(gpio_no);
	gpio_free(gpio_no);
	return LCD_KIT_OK;
}

int lcd_kit_gpio_pcd_errflag_check(void)
{
	int pcd_gpio = disp_info->pcd_errflag.gpio_pcd;
	int errflag_gpio = disp_info->pcd_errflag.gpio_errflag;
	int pcd_gpio_value = 0;
	int errflag_gpio_value = 0;

	if (!disp_info->pcd_errflag.pcd_errflag_check_support) {
		LCD_KIT_INFO("no support pcd_errflag check, default pass\n");
		return PCD_ERRFLAG_SUCCESS;
	}

	if (!pcd_gpio && !errflag_gpio) {
		LCD_KIT_INFO("pcd_errflag gpio is 0, default pass\n");
		return PCD_ERRFLAG_SUCCESS;
	}

	if (lcd_kit_gpio_pcd_errflag_read(pcd_gpio, &pcd_gpio_value))
		return PCD_ERRFLAG_SUCCESS;

	if (lcd_kit_gpio_pcd_errflag_read(errflag_gpio,
		&errflag_gpio_value))
		return PCD_ERRFLAG_SUCCESS;

	LCD_KIT_INFO("pcd_gpio[%d]=%d, errflag_gpio[%d]=%d\n",
		pcd_gpio, pcd_gpio_value,
		errflag_gpio, errflag_gpio_value);
	if ((pcd_gpio_value == GPIO_HIGH_PCDERRFLAG) &&
		(errflag_gpio_value == GPIO_LOW_PCDERRFLAG))
		return PCD_FAIL;
	else if ((pcd_gpio_value == GPIO_LOW_PCDERRFLAG) &&
		(errflag_gpio_value == GPIO_HIGH_PCDERRFLAG))
		return ERRFLAG_FAIL;
	else if ((pcd_gpio_value == GPIO_HIGH_PCDERRFLAG) &&
		(errflag_gpio_value == GPIO_HIGH_PCDERRFLAG))
		return PCD_ERRFLAG_FAIL;

	return PCD_ERRFLAG_SUCCESS;
}

#if defined(CONFIG_HONOR_DSM)
static void lcd_dmd_report_err(uint32_t err_no, const char *info, int info_len)
{
	if (!info) {
		LCD_KIT_ERR("info is NULL Pointer\n");
		return;
	}

	if (lcd_dclient && !dsm_client_ocuppy(lcd_dclient)) {
		dsm_client_record(lcd_dclient, info);
		dsm_client_notify(lcd_dclient, err_no);
	}
}
#endif

int lcd_kit_start_pcd_check(void *hld)
{

	struct lcd_kit_adapt_ops *adapt_ops = NULL;
	int ret = LCD_KIT_OK;
	int i;
	if (disp_info->pcd_errflag.pcd_support) {
		for (i = 0; i < disp_info->pcd_errflag.start_pcd_check_cmds.cmd_cnt; i++)
		adapt_ops = lcd_kit_get_adapt_ops();
		if (!adapt_ops) {
			LCD_KIT_ERR("can not register adapt_ops!\n");
			return LCD_KIT_FAIL;
		}
		/* init code */
		if (adapt_ops->mipi_tx) {
			LCD_KIT_INFO("enter 44_2 pcd mipi_tx\n");
			ret = adapt_ops->mipi_tx(hld, &disp_info->pcd_errflag.start_pcd_check_cmds);
			if (ret)
				LCD_KIT_ERR("send PCD panel on cmds error\n");
			LCD_KIT_INFO("pcd cmd tx successfully\n");
		}
	}
	return ret;
}

static int lcd_kit_judge_pcd_dmd(uint8_t *read_val,
	uint32_t *expect_val, int cnt, uint32_t compare_mode)
{
	int i;
	uint32_t exp_pcd_value_mask;

	exp_pcd_value_mask = disp_info->pcd_errflag.exp_pcd_mask;
	if (read_val == NULL || expect_val == NULL) {
		LCD_KIT_ERR("read_val or expect_val is NULL\n");
		return LCD_KIT_FAIL;
	}
	if (compare_mode == PCD_COMPARE_MODE_EQUAL) {
		for (i = 0; i < cnt; i++) {
			if ((uint32_t)read_val[i] != expect_val[i])
				return LCD_KIT_FAIL;
		}
	} else if (compare_mode == PCD_COMPARE_MODE_BIGGER) {
		if ((uint32_t)read_val[0] < expect_val[0])
			return LCD_KIT_FAIL;
	} else if (compare_mode == PCD_COMPARE_MODE_MASK) {
		if (((uint32_t)read_val[0] & exp_pcd_value_mask) == expect_val[0])
			return LCD_KIT_FAIL;
	}
	return LCD_KIT_OK;
}

#define PCD_READ_LEN 3
static void lcd_kit_pcd_dmd_report(uint8_t *pcd_read_val, uint32_t val_len)
{
	int ret;
	char err_info[DMD_ERR_INFO_LEN] = {0};

	if (val_len < PCD_READ_LEN) {
		LCD_KIT_ERR("val len err\n");
		return;
	}
	if (!pcd_read_val) {
		LCD_KIT_ERR("pcd_read_val is NULL\n");
		return;
	}
	ret = snprintf(err_info, DMD_ERR_INFO_LEN,
		"PCD REG Value is 0x%x 0x%x 0x%x\n",
		pcd_read_val[0], pcd_read_val[1], pcd_read_val[2]);
	if (ret < 0) {
		LCD_KIT_ERR("snprintf error\n");
		return;
	}
#if defined(CONFIG_HONOR_DSM)
	lcd_dmd_report_err(DSM_LCD_PANEL_CRACK_ERROR_NO, err_info,
		 DMD_ERR_INFO_LEN);
#endif
}

void pcd_test(uint8_t *result, uint8_t *pcd_read_val)
{
	error_num_pcd++;
	LCD_KIT_INFO("enter pcd_test, pcd_num = %d\n", error_num_pcd);
	if (error_num_pcd >= disp_info->pcd_errflag.pcd_det_num) {
		LCD_KIT_INFO("pcd detect num = %d\n", error_num_pcd);
		lcd_kit_pcd_dmd_report(pcd_read_val, LCD_KIT_PCD_SIZE);
		*result |= PCD_FAIL;
		error_num_pcd = 0;
	}
}

int lcd_kit_pcd_compare_result(uint8_t *read_val, int ret)
{
	uint32_t *expect_value = NULL;
	uint32_t expect_value_cnt;
	uint8_t result = PCD_ERRFLAG_SUCCESS;

	expect_value = disp_info->pcd_errflag.pcd_value.buf;
	expect_value_cnt = disp_info->pcd_errflag.pcd_value.cnt;
	if (ret == LCD_KIT_OK) {
		if (lcd_kit_judge_pcd_dmd(read_val, expect_value, expect_value_cnt,
			disp_info->pcd_errflag.pcd_value_compare_mode) == LCD_KIT_OK) {
			lcd_kit_pcd_dmd_report(read_val, LCD_KIT_PCD_SIZE);
			result |= PCD_FAIL;
		}
	} else {
		LCD_KIT_ERR("read pcd err\n");
	}
	LCD_KIT_INFO("pcd REG read result is 0x%x 0x%x 0x%x\n",
		read_val[0], read_val[1], read_val[2]);
	LCD_KIT_INFO("pcd check result is %d\n", result);
	return (int)result;
}

int lcd_kit_check_pcd_errflag_check(void *hld)
{
	struct lcd_kit_adapt_ops *adapt_ops = NULL;
	uint8_t result = PCD_ERRFLAG_SUCCESS;
	int ret = LCD_KIT_FAIL;
	uint8_t read_pcd[LCD_KIT_PCD_SIZE] = {0};
	uint8_t read_errflag[LCD_KIT_ERRFLAG_SIZE] = {0};
	int i;

	if (disp_info->pcd_errflag.pcd_support) {
		adapt_ops = lcd_kit_get_adapt_ops();
		if (!adapt_ops) {
			LCD_KIT_ERR("can not register adapt_ops!\n");
			return LCD_KIT_FAIL;
		}
		if (adapt_ops->mipi_tx) {
			ret = adapt_ops->mipi_tx(hld, &disp_info->pcd_errflag.switch_page_cmds);
			if (ret)
				LCD_KIT_ERR("mipi_tx fail\n");
		}
		/* init code */
		if (adapt_ops->mipi_rx) {
			ret = adapt_ops->mipi_rx(hld, read_pcd, LCD_KIT_PCD_SIZE - 1,
				&disp_info->pcd_errflag.read_pcd_cmds);
			if (ret) {
				LCD_KIT_INFO("mipi_rx fail\n");
				return ret;
			}
		}
		result = lcd_kit_pcd_compare_result(read_pcd, ret);
	}
	/* Reserve interface, redevelop when needed */
	if (disp_info->pcd_errflag.errflag_support) {
		adapt_ops = lcd_kit_get_adapt_ops();
		if (!adapt_ops) {
			LCD_KIT_ERR("can not register adapt_ops!\n");
			return LCD_KIT_FAIL;
		}
		if (adapt_ops->mipi_rx)
			ret = adapt_ops->mipi_rx(hld, read_errflag, LCD_KIT_ERRFLAG_SIZE - 1,
				&disp_info->pcd_errflag.read_errflag_cmds);
		if (ret) {
			LCD_KIT_INFO("mipi_rx fail\n");
			return ret;
		}
		for (i = 0; i < LCD_KIT_ERRFLAG_SIZE; i++) {
			if (read_errflag[i] != 0) {
				result |= ERRFLAG_FAIL;
				break;
			}
		}
	}
	return (int)result;
}

int lcd_kit_check_pcd_errflag_check_fac(void)
{
	uint8_t result = PCD_ERRFLAG_SUCCESS;
	int ret;
	uint8_t read_pcd[LCD_KIT_PCD_SIZE] = {0};
	uint8_t read_errflag[LCD_KIT_ERRFLAG_SIZE] = {0};
	uint32_t *expect_value = NULL;
	uint32_t expect_value_cnt;
	int i;

	if (disp_info->pcd_errflag.pcd_support) {
		(void)lcd_kit_dsi_cmds_extern_tx(&disp_info->pcd_errflag.switch_page_cmds);
		ret = lcd_kit_dsi_cmds_extern_rx(read_pcd,
			&disp_info->pcd_errflag.read_pcd_cmds, LCD_KIT_PCD_SIZE - 1);
		expect_value = disp_info->pcd_errflag.pcd_value.buf;
		expect_value_cnt = disp_info->pcd_errflag.pcd_value.cnt;
		if (ret == LCD_KIT_OK) {
			if (lcd_kit_judge_pcd_dmd(read_pcd, expect_value, expect_value_cnt,
				disp_info->pcd_errflag.pcd_value_compare_mode) == LCD_KIT_OK) {
				pcd_test(&result, read_pcd);
			} else {
				LCD_KIT_INFO("pcd detect num = %d\n", error_num_pcd);
				error_num_pcd = 0;
			}
		} else {
			LCD_KIT_ERR("read pcd err\n");
		}
		LCD_KIT_INFO("pcd REG read result is 0x%x 0x%x 0x%x\n",
			read_pcd[0], read_pcd[1], read_pcd[2]);
		LCD_KIT_INFO("pcd check result is %d\n", result);
	}
	/* Reserve interface, redevelop when needed */
	if (disp_info->pcd_errflag.errflag_support) {
		lcd_kit_dsi_cmds_extern_rx(read_errflag,
			&disp_info->pcd_errflag.read_errflag_cmds, LCD_KIT_ERRFLAG_SIZE - 1);
		for (i = 0; i < LCD_KIT_ERRFLAG_SIZE; i++) {
			if (read_errflag[i] != 0) {
				result |= ERRFLAG_FAIL;
				break;
			}
		}
	}
	return (int)result;
}

int lcd_kit_get_status_by_type(int type, int *status)
{
	int ret;

	if (status == NULL) {
		LCD_KIT_ERR("status is null\n");
		return LCD_KIT_FAIL;
	}
	switch (type) {
	case LCD_ONLINE_TYPE:
		*status = lcd_kit_get_online_status();
		ret = LCD_KIT_OK;
		break;
	case PT_STATION_TYPE:
#ifdef LCD_FACTORY_MODE
		*status = lcd_kit_get_pt_station_status();
#endif
		ret = LCD_KIT_OK;
		break;
	default:
		LCD_KIT_ERR("not support type\n");
		ret = LCD_KIT_FAIL;
		break;
	}
	return ret;
}

void lcd_kit_set_bl_cmd(uint32_t level)
{
	if (common_info->backlight.order != BL_BIG_ENDIAN &&
		common_info->backlight.order != BL_LITTLE_ENDIAN) {
		LCD_KIT_ERR("not support order\n");
		return;
	}
	if (common_info->backlight.order == BL_BIG_ENDIAN) {
		if (common_info->backlight.bl_max <= 0xFF) {
			common_info->backlight.bl_cmd.cmds[0].payload[1] = level;
			return;
		}
		/* change bl level to dsi cmds */
		common_info->backlight.bl_cmd.cmds[0].payload[1] =
			(level >> 8) & 0xFF;
		common_info->backlight.bl_cmd.cmds[0].payload[2] = level & 0xFF;
		return;
	}
	if (common_info->backlight.bl_max <= 0xFF) {
		common_info->backlight.bl_cmd.cmds[0].payload[1] = level;
		return;
	}
	/* change bl level to dsi cmds */
	common_info->backlight.bl_cmd.cmds[0].payload[1] = level & 0xFF;
	common_info->backlight.bl_cmd.cmds[0].payload[2] = (level >> 8) & 0xFF;
}

static int lcd_create_sysfs(struct kobject *obj)
{
	int rc = LCD_KIT_FAIL;

	if (obj == NULL) {
		LCD_KIT_ERR("create sysfs fail, obj is NULL\n");
		return rc;
	}

	rc = lcd_kit_create_sysfs(obj);
	if (rc) {
		LCD_KIT_ERR("create sysfs fail\n");
		return rc;
	}
#ifdef LCD_FACTORY_MODE
	rc = lcd_create_fact_sysfs(obj);
	if (rc) {
		LCD_KIT_ERR("create fact sysfs fail\n");
		return rc;
	}
#endif
	return rc;
}

static int lcd_kit_proximity_power_off(void)
{
	LCD_KIT_INFO("[Proximity_feature] lcd_kit_proximity_power_off enter!\n");
	if (!common_info->thp_proximity.support) {
		LCD_KIT_INFO("[Proximity_feature] thp_proximity not support exit!\n");
		return LCD_KIT_FAIL;
	}
	if (lcd_kit_get_pt_mode()) {
		LCD_KIT_INFO("[Proximity_feature] pt test mode exit!\n");
		return LCD_KIT_FAIL;
	}
	down(&disp_info->thp_second_poweroff_sem);
	if (common_info->thp_proximity.panel_power_state == POWER_ON) {
		LCD_KIT_INFO("[Proximity_feature] power state is on exit!\n");
		up(&disp_info->thp_second_poweroff_sem);
		return LCD_KIT_FAIL;
	}
	if (common_info->thp_proximity.panel_power_state == POWER_TS_SUSPEND) {
		LCD_KIT_INFO("[Proximity_feature] power off suspend state exit!\n");
		up(&disp_info->thp_second_poweroff_sem);
		return LCD_KIT_OK;
	}
	if (common_info->thp_proximity.work_status == TP_PROXMITY_DISABLE) {
		LCD_KIT_INFO("[Proximity_feature] thp_proximity has been disabled exit!\n");
		up(&disp_info->thp_second_poweroff_sem);
		return LCD_KIT_FAIL;
	}
	common_info->thp_proximity.work_status = TP_PROXMITY_DISABLE;
	if (common_ops->panel_only_power_off)
		common_ops->panel_only_power_off(NULL);
	up(&disp_info->thp_second_poweroff_sem);
	LCD_KIT_INFO("[Proximity_feature] lcd_kit_proximity_power_off exit!\n");
	return LCD_KIT_OK;
}

static int lcd_kit_get_sn_code(void)
{
	int ret;
	struct sprd_panel_info *pinfo = NULL;
	struct lcd_kit_panel_ops *panel_ops = NULL;
	char read_value[OEM_INFO_SIZE_MAX + 1] = {0};

	pinfo = lcm_get_panel_info();
	if (pinfo == NULL) {
		LCD_KIT_ERR("pinfo is null\n");
		return LCD_KIT_FAIL;
	}
	if (common_info && common_info->sn_code.support) {
		panel_ops = lcd_kit_panel_get_ops();
		if (panel_ops && panel_ops->lcd_get_2d_barcode) {
			ret = panel_ops->lcd_get_2d_barcode(read_value);
			if (ret != 0) {
				LCD_KIT_ERR("get sn_code error!\n");
				return LCD_KIT_FAIL;
			}
			memcpy(pinfo->sn_code, read_value + 2, LCD_KIT_SN_CODE_LENGTH);
			pinfo->sn_code_length = LCD_KIT_SN_CODE_LENGTH;
			return LCD_KIT_OK;
		}
		if (disp_info && disp_info->oeminfo.barcode_2d.support) {
			ret = lcd_kit_dsi_cmds_extern_rx(read_value,
				&disp_info->oeminfo.barcode_2d.cmds,
				LCD_KIT_SN_CODE_LENGTH);
			if (ret != 0) {
				LCD_KIT_ERR("get sn_code error!\n");
				return LCD_KIT_FAIL;
			}
			memcpy(pinfo->sn_code, read_value, LCD_KIT_SN_CODE_LENGTH);
			pinfo->sn_code_length = LCD_KIT_SN_CODE_LENGTH;
			return LCD_KIT_OK;
		}
	}
	return LCD_KIT_OK;
}

struct lcd_kit_ops g_lcd_ops = {
	.lcd_kit_support = lcd_kit_support,
	.get_project_id = lcd_kit_get_project_id,
	.create_sysfs = lcd_create_sysfs,
	.read_project_id = lcd_kit_read_project_id,
	.get_2d_barcode = lcd_get_2d_barcode,
	.get_status_by_type = lcd_kit_get_status_by_type,
	.proximity_power_off = lcd_kit_proximity_power_off,
#ifdef LCD_FACTORY_MODE
	.get_pt_station_status = lcd_kit_get_pt_station_status,
#endif
	.get_sn_code = lcd_kit_get_sn_code,
};

int lcd_kit_utils_init(struct device_node *np, struct sprd_panel_info *pinfo)
{
	/* init sem */
	sema_init(&disp_info->blank_sem, 1);
	sema_init(&disp_info->lcd_kit_sem, 1);
	sema_init(&disp_info->thp_second_poweroff_sem, 1);
	/* init mipi lock */
	mutex_init(&disp_info->mipi_lock);
	/* parse display dts */
	lcd_kit_parse_dt(np);
#ifdef LCD_FACTORY_MODE
	lcd_kit_fact_init(np);
#endif
	/* init pinfo */
	lcd_kit_pinfo_init(np, pinfo);
	lcd_kit_ops_register(&g_lcd_ops);
	return LCD_KIT_OK;
}
