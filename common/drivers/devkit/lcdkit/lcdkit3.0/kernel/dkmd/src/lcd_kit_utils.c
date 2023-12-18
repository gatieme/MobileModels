/*
 * lcd_kit_utils.c
 *
 * lcdkit utils function for lcd driver
 *
 * Copyright (c) 2018-2022 Huawei Technologies Co., Ltd.
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
#include "lcd_kit_parse.h"
#include "lcd_kit_local_hbm.h"
#include "display_engine_interface.h"
#ifdef LCD_FACTORY_MODE
#include "lcd_kit_factory.h"
#endif
#include "lcd_kit_sysfs_dkmd.h"
#include "lcd_kit_adapt.h"
#ifdef CONFIG_CPLD_DRIVER
#include <huawei_platform/hw_cpld/cpld_driver.h>
#endif

#if defined CONFIG_HUAWEI_DSM
extern struct dsm_client *lcd_dclient;
#endif

static char *dsi_name[DSI_MAX] = { "lcd-kit,connector-id0", "lcd-kit,connector-id1", "lcd-kit,connector-id2" };
bool g_skip_power_on_off = false;
unsigned int mipi_err_number = 0;

unsigned int lcd_kit_get_esd_support(int panel_id)
{
	if (runmode_is_factory())
		return common_info->esd.fac_esd_support || disp_info->check_mipi.support;
	else
		return common_info->esd.support;
}

void lcd_esd_enable(int panel_id, unsigned int enable)
{
	if (lcd_kit_get_esd_support(panel_id)) {
		disp_info->esd_enable = enable;
		msleep(LCD_KIT_ESD_TIME);
	}
	LCD_KIT_INFO("esd_enable = %d\n", disp_info->esd_enable);
}

static void lcd_dmd_report_err(uint32_t err_no, const char *info, int info_len)
{
	if (!info) {
		LCD_KIT_ERR("info is NULL Pointer\n");
		return;
	}
#if defined(CONFIG_HUAWEI_DSM)
	if (lcd_dclient && !dsm_client_ocuppy(lcd_dclient)) {
		dsm_client_record(lcd_dclient, info);
		dsm_client_notify(lcd_dclient, err_no);
	} else {
		LCD_KIT_INFO("unocuppy dsm client\n");
		dsm_client_unocuppy(lcd_dclient);
		msleep(3);
		if (!dsm_client_ocuppy(lcd_dclient)) {
			dsm_client_record(lcd_dclient, info);
			dsm_client_notify(lcd_dclient, err_no);
		}
	}
#endif
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
	lcd_dmd_report_err(DSM_LCD_PANEL_CRACK_ERROR_NO, err_info,
		 DMD_ERR_INFO_LEN);
}

static int lcd_kit_judge_pcd_dmd(uint32_t panel_id, uint8_t *read_val,
	uint32_t *expect_val, int cnt, uint32_t compare_mode)
{
	int i;
	uint32_t exp_pcd_value_mask;

	exp_pcd_value_mask = disp_info->pcd_errflag.exp_pcd_mask;
	if (read_val == NULL || expect_val == NULL) {
		LCD_KIT_ERR("read_val or expect_val is NULL\n");
		return LCD_KIT_FAIL;
	}
	LCD_KIT_INFO("pcd check compare mode is %d\n", compare_mode);
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

int lcd_kit_pcd_compare_result(uint32_t panel_id, uint8_t *read_val, int ret)
{
	uint32_t *expect_value = NULL;
	uint32_t expect_value_cnt;
	uint8_t result = PCD_ERRFLAG_SUCCESS;

	expect_value = disp_info->pcd_errflag.pcd_value.buf;
	expect_value_cnt = disp_info->pcd_errflag.pcd_value.cnt;
	if (ret == LCD_KIT_OK) {
		if (lcd_kit_judge_pcd_dmd(panel_id, read_val, expect_value,
			expect_value_cnt,
			disp_info->pcd_errflag.pcd_value_compare_mode) == \
			LCD_KIT_OK) {
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

int lcd_kit_check_pcd_errflag_check(void)
{
	uint8_t result = PCD_ERRFLAG_SUCCESS;
	int ret;
	uint8_t read_pcd[LCD_KIT_PCD_SIZE] = {0};
	uint8_t read_errflag[LCD_KIT_ERRFLAG_SIZE] = {0};
	struct lcd_kit_adapt_ops *adapt_ops = NULL;
	int i;

	int panel_id = lcd_kit_get_active_panel_id();
	adapt_ops = lcd_kit_get_adapt_ops();
	if (!adapt_ops) {
		LCD_KIT_ERR("can not get adapt_ops!\n");
		return LCD_KIT_FAIL;
	}
	if (!adapt_ops->mipi_rx || !adapt_ops->mipi_tx) {
		LCD_KIT_ERR("mipi_rx or mipi_tx is NULL\n");
		return LCD_KIT_FAIL;
	}

	if (!lcd_kit_get_panel_on_state(panel_id)) {
		LCD_KIT_ERR("panel is not power on!\n");
		return LCD_KIT_FAIL;
	}

	if (disp_info->pcd_errflag.pcd_support) {
		/* init code */
		ret = adapt_ops->mipi_rx(panel_id, NULL, read_pcd,
			LCD_KIT_PCD_SIZE - 1,
			&disp_info->pcd_errflag.read_pcd_cmds);
		if (ret) {
			LCD_KIT_ERR("mipi_rx fail\n");
			return ret;
		}
		result = lcd_kit_pcd_compare_result(panel_id, read_pcd, ret);
	}
	/* Reserve interface, redevelop when needed */
	if (disp_info->pcd_errflag.errflag_support) {
		ret = adapt_ops->mipi_rx(panel_id, NULL, read_errflag,
			LCD_KIT_ERRFLAG_SIZE - 1,
			&disp_info->pcd_errflag.read_errflag_cmds);
		if (ret) {
			LCD_KIT_ERR("mipi_rx fail\n");
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

int lcd_kit_judge_value(unsigned int judge_type, char read_value,
	unsigned int expect_value)
{
	int ret = LCD_KIT_OK;

	switch (judge_type) {
	case LCD_KIT_UNEQUAL:
		if (read_value != expect_value)
			ret = LCD_KIT_FAIL;
		break;
	case LCD_KIT_EQUAL:
		if (read_value == expect_value)
			ret = LCD_KIT_FAIL;
		break;
	case LCD_KIT_LESS:
		if (read_value < expect_value)
			ret = LCD_KIT_FAIL;
		break;
	case LCD_KIT_MORE:
		if (read_value >= expect_value)
			ret = LCD_KIT_FAIL;
		break;
	default:
		if (read_value != expect_value)
			ret = LCD_KIT_FAIL;
		break;
	}
	return ret;
}

void lcd_kit_print_mipi_error_reg(int panel_id)
{
	struct lcd_kit_adapt_ops *adapt_ops = NULL;
	char read_value[MAX_MIPI_ERR_READ_COUNT] = {0};
	unsigned int *expect_value = NULL;
	int ret = LCD_KIT_OK;
	int i;

	adapt_ops = lcd_kit_get_adapt_ops();
	if (!adapt_ops || !adapt_ops->mipi_rx) {
		LCD_KIT_ERR("can not register adapt_ops or mipi_rx!\n");
		return;
	}

	ret = adapt_ops->mipi_rx(panel_id, NULL, read_value,
		MAX_MIPI_ERR_READ_COUNT - 1, &disp_info->check_mipi.sub_cmds);
	if (ret) {
		LCD_KIT_INFO("mipi_rx fail\n");
		return;
	}

	expect_value = disp_info->check_mipi.sub_value.buf;
	for (i = 0; i < disp_info->check_mipi.sub_value.cnt; i++)
		LCD_KIT_INFO("check mipi sub%d reg read_value[%d] = 0x%x, expect_value = 0x%x\n",
			i, i, read_value[i], expect_value[i]);
}

void lcd_kit_check_mipi_error(int panel_id)
{
	int ret = LCD_KIT_OK;
	int i;
	unsigned int max_err_number;
	char read_value[MAX_MIPI_ERR_READ_COUNT] = {0};
	unsigned int *expect_value = NULL;
	unsigned int *judge_type = NULL;
	struct lcd_kit_adapt_ops *adapt_ops = NULL;
	char err_info[DMD_ERR_INFO_LEN] = {0};

	adapt_ops = lcd_kit_get_adapt_ops();
	if (!adapt_ops || !adapt_ops->mipi_rx) {
		LCD_KIT_ERR("can not register adapt_ops or mipi_rx!\n");
		return;
	}

	expect_value = disp_info->check_mipi.value.buf;
	judge_type = disp_info->check_mipi.judge_type.buf;
	max_err_number = disp_info->check_mipi.max_number;
	ret = adapt_ops->mipi_rx(panel_id, NULL, read_value,
		MAX_MIPI_ERR_READ_COUNT - 1, &disp_info->check_mipi.cmds);
	if (ret) {
		LCD_KIT_INFO("mipi_rx fail\n");
		return;
	}

	for (i = 0; i < disp_info->check_mipi.value.cnt; i++) {
		LCD_KIT_INFO("check mipi sub%d reg read_value[%d] = 0x%x, expect_value = 0x%x\n",
			i, i, read_value[i], expect_value[i]);
		if (lcd_kit_judge_value(judge_type[i], read_value[i], expect_value[i])) {
			mipi_err_number += 1;
			ret = snprintf(err_info, DMD_ERR_INFO_LEN, "check mipi read_value=0x%x expect_value=0x%x\n",
				read_value[i], expect_value[i]);
			if (mipi_err_number >= max_err_number) {
				mipi_err_number = 0;
				lcd_dmd_report_err(DSM_LCD_MIPI_TRANSMIT_ERROR_NO, err_info, DMD_ERR_INFO_LEN);
				lcd_kit_print_mipi_error_reg(panel_id);
			}
			return;
		}
	}
}

void lcd_kit_ddic_lv_detect_dmd_report(
	u8 reg_val[DETECT_LOOPS][DETECT_NUM][VAL_NUM])
{
#if defined (CONFIG_HUAWEI_DSM) && defined(LCD_FACTORY_MODE)
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
	lcd_dmd_report_err(DSM_LCD_DDIC_LV_DETECT_ERROR_NO, err_info,
		DMD_DET_ERR_LEN);
#else
	(void)reg_val;
#endif
}

int lcd_kit_gpio_pcd_errflag_check(void)
{
	int ret = LCD_KIT_OK;

	return ret;
}

void check_panel_on_state(void)
{
#ifdef CONFIG_CPLD_DRIVER
	cpld_show_all_reg_data();
#endif
	return;
}

bool is_dual_mipi_panel(unsigned int panel_type)
{
	return (panel_type & (LCD_KIT_DUAL_MIPI_VIDEO | LCD_KIT_DUAL_MIPI_CMD));
}


void lcd_kit_disp_on_check_delay(int panel_id)
{
	long delta_time;
	u32 delay_margin;
	struct timespec64 tv;
	u32 max_margin = 200;

	memset(&tv, 0, sizeof(struct timespec64));
	ktime_get_real_ts64(&tv);
	LCD_KIT_INFO("set backlight at %lu seconds %lu mil seconds\n",
		tv.tv_sec, tv.tv_nsec/1000);
	/* change s to ns */
	delta_time = (tv.tv_sec - disp_info->quickly_sleep_out.panel_on_record_tv.tv_sec) * 1000000000 +
		tv.tv_nsec - disp_info->quickly_sleep_out.panel_on_record_tv.tv_nsec;
	/* change ns to ms */
	delta_time /= 1000000;
	if (delta_time >= disp_info->quickly_sleep_out.interval) {
		LCD_KIT_INFO("%lu > %d, no need delay\n", delta_time,
			disp_info->quickly_sleep_out.interval);
		goto check_delay_end;
	}
	delay_margin = disp_info->quickly_sleep_out.interval - (u32)delta_time;
	if (delay_margin > max_margin) {
		LCD_KIT_INFO("something maybe error");
		goto check_delay_end;
	}
	msleep(delay_margin);
check_delay_end:
	disp_info->quickly_sleep_out.panel_on_tag = false;
}

void lcd_kit_disp_on_record_time(int panel_id)
{
	ktime_get_real_ts64(&disp_info->quickly_sleep_out.panel_on_record_tv);
	LCD_KIT_INFO("display on at %lu seconds %lu mil seconds\n",
		disp_info->quickly_sleep_out.panel_on_record_tv.tv_sec,
		disp_info->quickly_sleep_out.panel_on_record_tv.tv_nsec/1000);
	disp_info->quickly_sleep_out.panel_on_tag = true;
}

int lcd_kit_mipi_set_backlight(int panel_id, unsigned int level)
{
	unsigned int bl_level;
	int ret = LCD_KIT_OK;

	bl_level = level;
	ret = common_ops->set_mipi_backlight(panel_id, NULL, bl_level);
	display_engine_brightness_update(bl_level);

	return ret;
}

bool lcd_kit_get_panel_on_state(int panel_id)
{
	return (disp_info->lcd_power_seq == LCD_KIT_POWER_ON);
}

void lcd_kit_recovery_display(int panel_id)
{
	return;
}

void lcd_kit_set_mipi_link(int panel_id, int link_state)
{
	int ret;
	unsigned int connector_id;
	unsigned int cmd_type;
	unsigned int dsi0_index;
	unsigned int dsi1_index;

	connector_id = DPU_PINFO->connector_id;
	cmd_type = DPU_PINFO->type;
	if (is_dual_mipi_panel(cmd_type)) {
		ret = lcd_kit_get_dsi_index(&dsi0_index, connector_id);
		if (ret) {
			LCD_KIT_ERR("get dsi0 index error\n");
			return;
		}
		connector_id &= (~(1 << dsi0_index));
		ret = lcd_kit_get_dsi_index(&dsi1_index, connector_id);
		if (ret) {
			LCD_KIT_ERR("get dsi1 index error\n");
			return;
		}
		LCD_KIT_DEBUG("dual %d %d send cmd\n", dsi0_index, dsi1_index);
		if (link_state == LCD_KIT_DSI_LP_MODE) {
			mipi_dsi_set_lp_mode(dsi0_index, DPU_PINFO->type);
			mipi_dsi_set_lp_mode(dsi1_index, DPU_PINFO->type);
		} else {
			mipi_dsi_set_hs_mode(dsi0_index, DPU_PINFO->type);
			mipi_dsi_set_hs_mode(dsi1_index, DPU_PINFO->type);
		}
	} else {
		ret = lcd_kit_get_dsi_index(&dsi0_index, connector_id);
		if (ret) {
			LCD_KIT_ERR("get dsi0 index error\n");
			return;
		}
		LCD_KIT_DEBUG("single %d send cmd\n", dsi0_index);
		if (link_state == LCD_KIT_DSI_LP_MODE) {
			mipi_dsi_set_lp_mode(dsi0_index, DPU_PINFO->type);
		} else {
			mipi_dsi_set_hs_mode(dsi0_index, DPU_PINFO->type);
		}
	}
}

static void lcd_kit_init_sema(int panel_id)
{
	sema_init(&DISP_LOCK->lcd_kit_sem, 1);
	sema_init(&DISP_LOCK->thp_second_poweroff_sem, 1);
}

static void lcd_kit_parse_quickly_sleep_out(int panel_id, struct device_node *np)
{
	/* quickly sleep out */
	lcd_kit_parse_u32(np, "lcd-kit,quickly-sleep-out-support",
		&disp_info->quickly_sleep_out.support, 0);
	if (disp_info->quickly_sleep_out.support)
		lcd_kit_parse_u32(np, "lcd-kit,quickly-sleep-out-interval",
			&disp_info->quickly_sleep_out.interval, 0);
}

static void lcd_kit_parse_oem_info(int panel_id, struct device_node *np)
{
	lcd_kit_parse_u32(np, "lcd-kit,oem-info-support",
		&disp_info->oeminfo.support, 0);
	if (disp_info->oeminfo.support) {
		lcd_kit_parse_u32(np, "lcd-kit,oem-barcode-2d-support",
			&disp_info->oeminfo.barcode_2d.support, 0);
		if (disp_info->oeminfo.barcode_2d.support) {
			lcd_kit_parse_u32(np,
				"lcd-kit,oem-barcode-2d-block-num",
				&disp_info->oeminfo.barcode_2d.block_num, 3);
			lcd_kit_parse_dcs_cmds(np, "lcd-kit,barcode-2d-cmds",
				"lcd-kit,barcode-2d-cmds-state",
				&disp_info->oeminfo.barcode_2d.cmds);
		}
	}
}

static void parse_fps_char(int panel_id, struct device_node *np)
{
	disp_info->fps.fps_60_cmd = (char *)of_get_property(np,
		"lcd-kit,fps-60-cmd", NULL);
	disp_info->fps.fps_90_cmd = (char *)of_get_property(np,
		"lcd-kit,fps-90-cmd", NULL);
	disp_info->fps.fps_120_cmd = (char *)of_get_property(np,
		"lcd-kit,fps-120-cmd", NULL);
	disp_info->fps.fps_45_cmd = (char *)of_get_property(np,
		"lcd-kit,fps-45-cmd", NULL);
	disp_info->fps.fps_40_cmd = (char *)of_get_property(np,
		"lcd-kit,fps-40-cmd", NULL);
	disp_info->fps.fps_30_cmd = (char *)of_get_property(np,
		"lcd-kit,fps-30-cmd", NULL);
	disp_info->fps.fps_24_cmd = (char *)of_get_property(np,
		"lcd-kit,fps-24-cmd", NULL);
	disp_info->fps.fps_20_cmd = (char *)of_get_property(np,
		"lcd-kit,fps-20-cmd", NULL);
	disp_info->fps.fps_18_cmd = (char *)of_get_property(np,
		"lcd-kit,fps-18-cmd", NULL);
	disp_info->fps.fps_15_cmd = (char *)of_get_property(np,
		"lcd-kit,fps-15-cmd", NULL);
	disp_info->fps.fps_10_cmd = (char *)of_get_property(np,
		"lcd-kit,fps-10-cmd", NULL);
	disp_info->fps.fps_1_cmd = (char *)of_get_property(np,
		"lcd-kit,fps-1-cmd", NULL);
}

static void parse_fps_cmd(int panel_id, struct device_node *np)
{
	lcd_kit_parse_dcs_cmds(np, "lcd-kit,fps-to-1-cmds",	"lcd-kit,fps-to-1-cmds-state",
		&disp_info->fps.fps_to_1_cmds);
	lcd_kit_parse_dcs_cmds(np, "lcd-kit,fps-to-10-cmds", "lcd-kit,fps-to-10-cmds-state",
		&disp_info->fps.fps_to_10_cmds);
	lcd_kit_parse_dcs_cmds(np, "lcd-kit,fps-to-15-cmds", "lcd-kit,fps-to-15-cmds-state",
		&disp_info->fps.fps_to_15_cmds);
	lcd_kit_parse_dcs_cmds(np, "lcd-kit,fps-to-18-cmds", "lcd-kit,fps-to-18-cmds-state",
		&disp_info->fps.fps_to_18_cmds);
	lcd_kit_parse_dcs_cmds(np, "lcd-kit,fps-to-20-cmds", "lcd-kit,fps-to-20-cmds-state",
		&disp_info->fps.fps_to_20_cmds);
	lcd_kit_parse_dcs_cmds(np, "lcd-kit,fps-to-24-cmds", "lcd-kit,fps-to-24-cmds-state",
		&disp_info->fps.fps_to_24_cmds);
	lcd_kit_parse_dcs_cmds(np, "lcd-kit,fps-to-30-cmds", "lcd-kit,fps-to-30-cmds-state",
		&disp_info->fps.fps_to_30_cmds);
	lcd_kit_parse_dcs_cmds(np, "lcd-kit,fps-to-40-cmds", "lcd-kit,fps-to-40-cmds-state",
		&disp_info->fps.fps_to_40_cmds);
	lcd_kit_parse_dcs_cmds(np, "lcd-kit,fps-to-45-cmds", "lcd-kit,fps-to-45-cmds-state",
		&disp_info->fps.fps_to_45_cmds);
	lcd_kit_parse_dcs_cmds(np, "lcd-kit,fps-to-60-cmds", "lcd-kit,fps-to-60-cmds-state",
		&disp_info->fps.fps_to_60_cmds);
	lcd_kit_parse_dcs_cmds(np, "lcd-kit,fps-to-90-cmds", "lcd-kit,fps-to-90-cmds-state",
		&disp_info->fps.fps_to_90_cmds);
	lcd_kit_parse_dcs_cmds(np, "lcd-kit,fps-to-120-cmds", "lcd-kit,fps-to-120-cmds-state",
		&disp_info->fps.fps_to_120_cmds);
	lcd_kit_parse_dcs_cmds(np, "lcd-kit,fps-to-144-cmds", "lcd-kit,fps-to-144-cmds-state",
		&disp_info->fps.fps_to_144_cmds);
	lcd_kit_parse_dcs_cmds(np, "lcd-kit,refresh-cmds", "lcd-kit,refresh-cmds-state",
		&disp_info->fps.refresh_cmds);
}

static void parse_fps_bl(int panel_id, struct device_node *np)
{
	lcd_kit_parse_u32(np, "lcd-kit,bl-to-1-hz",
		&disp_info->fps.bl_to_1_hz, 0);
}

static void parse_fps_aod_bl(int panel_id, struct device_node *np)
{
	lcd_kit_parse_u32(np, "lcd-kit,aod-bl-to-1-hz",
		&disp_info->fps.aod_bl_to_1_hz, 0);
}

struct fps_dsi_timming_table {
	uint32_t fps_rate;
	const char *name;
};

static void parse_fps_mipi(int panel_id, struct device_node *np)
{
	int i;
	int j;
	int table_num;
	struct fps_dsi_timming_table dsi_timming_table[] = {
		{FPS_60, "lcd-kit,fps-60-dsi-timming"},
		{FPS_90, "lcd-kit,fps-90-dsi-timming"},
		{FPS_120, "lcd-kit,fps-120-dsi-timming"},
		{FPS_144, "lcd-kit,fps-144-dsi-timming"},
	};

	table_num = sizeof(dsi_timming_table) / sizeof(dsi_timming_table[0]);
	for (i = 0; i < disp_info->fps.panel_support_fps_list.cnt; i++) {
		for (j = 0; j < table_num; j++) {
			if (dsi_timming_table[j].fps_rate == disp_info->fps.panel_support_fps_list.buf[i])
				lcd_kit_parse_array_data(np, dsi_timming_table[j].name,
					&disp_info->fps.fps_dsi_timming[i]);
		}
	}
}

static void parse_fps(int panel_id, struct device_node *np)
{
	parse_fps_char(panel_id, np);
	parse_fps_cmd(panel_id, np);
	parse_fps_bl(panel_id, np);
	parse_fps_aod_bl(panel_id, np);
	parse_fps_mipi(panel_id, np);
}

static void lcd_kit_parse_fps(int panel_id, struct device_node *np)
{
	lcd_kit_parse_u32(np, "lcd-kit,fps-support",
		&disp_info->fps.support, 0);
	lcd_kit_parse_u32(np, "lcd-kit,default-fps",
		&disp_info->fps.default_fps, 0);
	if (disp_info->fps.support) {
		disp_info->fps.panel_support_fps_list.cnt = SEQ_NUM;
		lcd_kit_parse_array_data(np, "lcd-kit,panel-support-fps-list",
			&disp_info->fps.panel_support_fps_list);
		parse_fps(panel_id, np);
	}
}

static void lcd_kit_parse_disp(int panel_id, struct device_node *np)
{
	/* quickly sleep */
	lcd_kit_parse_quickly_sleep_out(panel_id, np);
	/* lcd oeminfo */
	lcd_kit_parse_oem_info(panel_id, np);
	/* fps */
	lcd_kit_parse_fps(panel_id, np);
}

static void lcd_kit_init_display(int panel_id, struct device_node *np)
{
	if (!np) {
		LCD_KIT_ERR("np is null\n");
		return;
	}

	/* init lcd power seq */
	disp_info->lcd_power_seq = LCD_KIT_POWER_ON;
	/* dubai backlight def 0 */
	disp_info->jank_last_bl_level = 0;
	lcd_kit_parse_disp(panel_id, np);
}

int lcd_kit_get_dsi_index(unsigned int *dsi_index, unsigned int connector_id)
{
	int i;
	unsigned int dsi[DSI_MAX] = { DSI0_INDEX, DSI1_INDEX, DSI2_INDEX };

	for (i = 0; i < DSI_MAX; i++) {
		if ((connector_id & dsi[i]) > 0) {
			*dsi_index = i;
			return LCD_KIT_OK;
		}
	}

	return LCD_KIT_FAIL;
}

static void lcd_kit_parse_connector_id(struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	unsigned int connector_num = 0;
	unsigned int dsi_id = 0;
	unsigned int connector_id = 0;
	int i;

	lcd_kit_parse_u32(np, "lcd-kit,connector-num", &connector_num, 1);
	for (i = 0; i < connector_num; i++) {
		lcd_kit_parse_u32(np, dsi_name[i], &dsi_id, 0);
		connector_id |= (1 << dsi_id);
	}
	pinfo->connector_id = connector_id;

	LCD_KIT_INFO("connector_id = %d!\n", connector_id);
}

static void lcd_kit_parse_base_pinfo(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_parse_u32(np, "lcd-kit,panel-xres",
		&pinfo->xres, 1440);
	lcd_kit_parse_u32(np, "lcd-kit,panel-yres",
		&pinfo->yres, 2560);
	lcd_kit_parse_u32(np, "lcd-kit,panel-width",
		&pinfo->width, 73);
	lcd_kit_parse_u32(np, "lcd-kit,panel-height",
		&pinfo->height, 130);
	lcd_kit_parse_u32(np, "lcd-kit,panel-cmd-type",
		&pinfo->type, 0);
	lcd_kit_parse_u32(np, "lcd-kit,panel-bpp",
		&pinfo->bpp, 0);
	lcd_kit_parse_u32(np, "lcd-kit,panel-bgr-fmt",
		&pinfo->bgr_fmt, 0);
	lcd_kit_parse_u32(np, "lcd-kit,panel-orientation",
		&pinfo->orientation, 0);
	lcd_kit_parse_u32(np, "lcd-kit,panel-vsyn-ctr-type",
		&pinfo->vsync_ctrl_type, 0);
	lcd_kit_parse_u32(np, "lcd-kit,panel-fps",
		&pinfo->fps, 60);
	lcd_kit_parse_u32(np, "lcd-kit,te-index",
		&pinfo->lcd_te_idx, 0);
#ifdef LCD_FACTORY_MODE
	pinfo->aod_enable = 0;
#else
	lcd_kit_parse_u32(np, "lcd-kit,sensorhub-aod-support",
		&pinfo->aod_enable, 0);
#endif
	lcd_kit_parse_u32(np, "lcd-kit,is-fake-panel",
		&pinfo->fake_panel_flag, 0);
	pinfo->lcd_name = common_info->panel_name;
	lcd_kit_parse_connector_id(np, pinfo);
	/* for second panel */
	if (panel_id == SECONDARY_PANEL)
		pinfo->type |= SECONDARY_PANEL_CMD_TYPE;
}

static void lcd_kit_parse_bl_info(struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_parse_u32(np, "lcd-kit,panel-bl-type",
		&pinfo->bl_info.bl_type, 0);
	lcd_kit_parse_u32(np, "lcd-kit,panel-bl-min",
		&pinfo->bl_info.bl_min, 0);
	lcd_kit_parse_u32(np, "lcd-kit,panel-bl-max",
		&pinfo->bl_info.bl_max, 0);
	lcd_kit_parse_u32(np, "lcd-kit,panel-bl-def",
		&pinfo->bl_info.bl_default, 0);
}

static void lcd_kit_parse_mipi(struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	unsigned int pxl_clk_rate = 0;

	lcd_kit_parse_u32(np, "lcd-kit,mipi-h-sync-area", &pinfo->mipi.hsa, 0);
	lcd_kit_parse_u32(np, "lcd-kit,mipi-h-back-porch", &pinfo->mipi.hbp, 0);
	lcd_kit_parse_u32(np, "lcd-kit,mipi-h-line-time", &pinfo->mipi.hline_time, 0);
	lcd_kit_parse_u32(np, "lcd-kit,mipi-dpi-h-size", &pinfo->mipi.dpi_hsize, 0);
	lcd_kit_parse_u32(np, "lcd-kit,mipi-v-sync-area", &pinfo->mipi.vsa, 0);
	lcd_kit_parse_u32(np, "lcd-kit,mipi-v-back-porch", &pinfo->mipi.vbp, 0);
	lcd_kit_parse_u32(np, "lcd-kit,mipi-v-front-porch", &pinfo->mipi.vfp, 0);
	lcd_kit_parse_u32(np, "lcd-kit,mipi-phy-mode", &pinfo->mipi.phy_mode, 0);
	lcd_kit_parse_u8(np, "lcd-kit,mipi-lane-nums", &pinfo->mipi.lane_nums, 0);
	lcd_kit_parse_u8(np, "lcd-kit,mipi-vc", &pinfo->mipi.vc, 0);
	lcd_kit_parse_u32(np, "lcd-kit,mipi-dsi-bit-clk", &pinfo->mipi.dsi_bit_clk, 0);
	lcd_kit_parse_u32(np, "lcd-kit,panel-pxl-clk", &pxl_clk_rate, 0);
	lcd_kit_parse_u32(np, "lcd-kit,panel-pxl-clk-div", &pinfo->mipi.pxl_clk_rate_div, 1);
	lcd_kit_parse_u32(np, "lcd-kit,mipi-dsi-upt-support", &pinfo->mipi.dsi_bit_clk_upt_support, 0);
	lcd_kit_parse_u8(np, "lcd-kit,mipi-non-continue-enable", &pinfo->mipi.non_continue_en, 0);
	lcd_kit_parse_u32(np, "lcd-kit,mipi-clk-post-adjust", &pinfo->mipi.clk_post_adjust, 0);
	lcd_kit_parse_u32(np, "lcd-kit,mipi-clk-pre-adjust", &pinfo->mipi.clk_pre_adjust, 0);
	lcd_kit_parse_u32(np, "lcd-kit,mipi-clk-t-hs-prepare-adjust", &pinfo->mipi.clk_t_hs_prepare_adjust, 0);
	lcd_kit_parse_u32(np, "lcd-kit,mipi-clk-t-lpx-adjust", &pinfo->mipi.clk_t_lpx_adjust, 0);
	lcd_kit_parse_u32(np, "lcd-kit,mipi-data-t-lpx-adjust", &pinfo->mipi.data_t_lpx_adjust, 0);
	lcd_kit_parse_u32(np, "lcd-kit,mipi-clk-t-hs-trail-adjust", &pinfo->mipi.clk_t_hs_trial_adjust, 0);
	lcd_kit_parse_u32(np, "lcd-kit,mipi-clk-t-hs-exit-adjust", &pinfo->mipi.clk_t_hs_exit_adjust, 0);
	lcd_kit_parse_u32(np, "lcd-kit,mipi-clk-t-hs-zero-adjust", &pinfo->mipi.clk_t_hs_zero_adjust, 0);
	lcd_kit_parse_u32(np, "lcd-kit,mipi-data-t-hs-zero-adjust", &pinfo->mipi.data_t_hs_zero_adjust, 0);
	lcd_kit_parse_u32(np, "lcd-kit,mipi-data-t-hs-trail-adjust", &pinfo->mipi.data_t_hs_trial_adjust, 0);
	lcd_kit_parse_u32(np, "lcd-kit,mipi-data-lane-lp2hs-time-adjust",
		&pinfo->mipi.data_lane_lp2hs_time_adjust, 0);
	lcd_kit_parse_u32(np, "lcd-kit,mipi-data-t-hs-prepare-adjust",
		&pinfo->mipi.data_t_hs_prepare_adjust, 0);
	lcd_kit_parse_u8(np, "lcd-kit,mipi-color-mode", &pinfo->mipi.color_mode, 0);
	lcd_kit_parse_u8(np, "lcd-kit,mipi-dsi-version", &pinfo->mipi.dsi_version, 0);
	lcd_kit_parse_u32(np, "lcd-kit,mipi-max-tx-esc-clk", &pinfo->mipi.max_tx_esc_clk, 0);
	lcd_kit_parse_u32(np, "lcd-kit,mipi-burst-mode", &pinfo->mipi.burst_mode, 0);

	pinfo->mipi.pxl_clk_rate = (unsigned long long)pxl_clk_rate;
	// change MHz to Hz
	pinfo->mipi.pxl_clk_rate = pinfo->mipi.pxl_clk_rate * 1000000UL;
	pinfo->mipi.max_tx_esc_clk = pinfo->mipi.max_tx_esc_clk * 1000000;
	pinfo->mipi.dsi_bit_clk_upt = pinfo->mipi.dsi_bit_clk;
	pinfo->mipi.dsi_bit_clk_default = pinfo->mipi.dsi_bit_clk;
}

static void lcd_kit_parse_dsc_param(struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_parse_u32(np, "lcd-kit,vesa-dsc-version",
		&pinfo->input_dsc_info.dsc_version, 0);
	lcd_kit_parse_u32(np, "lcd-kit,vesa-dsc-format",
		&pinfo->input_dsc_info.format, 0);
	lcd_kit_parse_u32(np, "lcd-kit,vesa-dsc-bpc",
		&pinfo->input_dsc_info.dsc_bpc, 0);
	lcd_kit_parse_u32(np, "lcd-kit,vesa-dsc-bpp",
		&pinfo->input_dsc_info.dsc_bpp, 0);
	lcd_kit_parse_u32(np, "lcd-kit,vesa-slice-height",
		&pinfo->input_dsc_info.slice_height, 0);
	lcd_kit_parse_u32(np, "lcd-kit,vesa-slice-width",
		&pinfo->input_dsc_info.slice_width, 0);
	lcd_kit_parse_u32(np, "lcd-kit,vesa-dsc-blk-pred-en",
		&pinfo->input_dsc_info.block_pred_enable, 0);
	lcd_kit_parse_u32(np, "lcd-kit,vesa-dsc-line-buff-depth",
		&pinfo->input_dsc_info.linebuf_depth, 0);
	lcd_kit_parse_u32(np, "lcd-kit,vesa-dsc-gen-rc-params",
		&pinfo->input_dsc_info.gen_rc_params, 0);
	lcd_kit_parse_u32(np, "lcd-kit,panel-ifbc-type",
		&pinfo->ifbc_type, 0);

	pinfo->input_dsc_info.pic_width = pinfo->xres;
	pinfo->input_dsc_info.pic_height = pinfo->yres;
	return;
}

static int lcd_kit_cmds_to_dsi_cmds(struct lcd_kit_dsi_cmd_desc *lcd_kit_cmds, struct dsi_cmd_desc *cmd)
{
	int j;

	if (lcd_kit_cmds == NULL) {
		LCD_KIT_ERR("lcd_kit_cmds is null point!\n");
		return LCD_KIT_FAIL;
	}
	if (cmd == NULL) {
		LCD_KIT_ERR("cmd is null!\n");
		return LCD_KIT_FAIL;
	}
	cmd->dtype = lcd_kit_cmds->dtype;
	cmd->vc =  lcd_kit_cmds->vc;
	cmd->wait = lcd_kit_cmds->wait;
	cmd->waittype =  lcd_kit_cmds->waittype;
	cmd->dlen =  lcd_kit_cmds->dlen;
	cmd->payload = lcd_kit_cmds->payload;
	LCD_KIT_INFO("cmd->dtype 0x%x!\n", cmd->dtype);
	LCD_KIT_INFO("cmd->vc 0x%x!\n", cmd->vc);
	LCD_KIT_INFO("cmd->wait 0x%x!\n", cmd->wait);
	LCD_KIT_INFO("cmd->waittype 0x%x!\n", cmd->waittype);
	LCD_KIT_INFO("cmd->dlen 0x%x!\n", cmd->dlen);
	for (j = 0; j < cmd->dlen; j++)
		LCD_KIT_INFO("cmd->dtype[%d] 0x%x!\n", j, cmd->payload[j]);
	return LCD_KIT_OK;
}

void lcd_kit_get_bl_cmds(int panel_id, int bl_level, struct dsi_cmds *dsi_cmds)
{
	int i;

	switch (common_info->backlight.order) {
	case BL_BIG_ENDIAN:
		if (common_info->backlight.bl_max <= 0xFF) {
			common_info->backlight.bl_cmd.cmds[0].payload[1] = bl_level;
		} else if (common_info->backlight.ext_flag) {
			/* change bl level to dsi cmds */
			common_info->backlight.bl_cmd.cmds[0].payload[1] = common_info->backlight.write_offset;
			common_info->backlight.bl_cmd.cmds[0].payload[2] = (bl_level >> 8) & 0xFF;
			common_info->backlight.bl_cmd.cmds[0].payload[3] = bl_level & 0xFF;
		} else {
			/* change bl level to dsi cmds */
			common_info->backlight.bl_cmd.cmds[0].payload[1] = ((bl_level >> 8) & 0xFF) | common_info->backlight.write_offset;
			common_info->backlight.bl_cmd.cmds[0].payload[2] = bl_level & 0xFF;
		}
		break;
	case BL_LITTLE_ENDIAN:
		if (common_info->backlight.bl_max <= 0xFF) {
			common_info->backlight.bl_cmd.cmds[0].payload[1] = bl_level;
		} else if (common_info->backlight.ext_flag) {
			/* change bl level to dsi cmds */
			common_info->backlight.bl_cmd.cmds[0].payload[1] = bl_level & 0xFF;
			common_info->backlight.bl_cmd.cmds[0].payload[2] = (bl_level >> 8) & 0xFF;
			common_info->backlight.bl_cmd.cmds[0].payload[3] = common_info->backlight.write_offset;
		} else {
			/* change bl level to dsi cmds */
			common_info->backlight.bl_cmd.cmds[0].payload[1] = bl_level & 0xFF;
			common_info->backlight.bl_cmd.cmds[0].payload[2] = ((bl_level >> 8) & 0xFF) | common_info->backlight.write_offset;
		}
		break;
	default:
		LCD_KIT_ERR("not support order\n");
		break;
	}

	for (i = 0; i < common_info->backlight.bl_cmd.cmd_cnt; i++) {
		lcd_kit_cmds_to_dsi_cmds(&common_info->backlight.bl_cmd.cmds[i],
			&dsi_cmds->cmds[i]);
		dsi_cmds->cmd_num += 1;
	}
}

static void parse_ltps_info(int panel_id, struct device_node *np, struct dpu_panel_info *pinfo)
{
	int i;
	struct lcd_kit_array_data *fps_timing;
	LCD_KIT_INFO("+\n");

	lcd_kit_parse_u32(np, "lcd-kit,ltpo-ver", &pinfo->dfr_info.oled_info.ltpo_info.ver, 0);
	lcd_kit_parse_u32(np, "lcd-kit,dfr-mode", &pinfo->dfr_info.dfr_mode, 0);
	LCD_KIT_INFO("pinfo->dfr_info.dfr_mode = %d\n", pinfo->dfr_info.dfr_mode);
	if (pinfo->dfr_info.dfr_mode != DFR_MODE_LONG_V && pinfo->dfr_info.dfr_mode != DFR_MODE_LONG_H) {
		LCD_KIT_INFO("not support ltps fps\n");
		return;
	}
	pinfo->mipi.mipi_frm_rate_mode_num = disp_info->fps.panel_support_fps_list.cnt;
	for (i = 0; i < pinfo->mipi.mipi_frm_rate_mode_num; i++) {
		fps_timing = &disp_info->fps.fps_dsi_timming[i];
		pinfo->mipi.mipi_timing_modes[i].mipi_timing.hsa = fps_timing->buf[FPS_HSA];
		LCD_KIT_INFO("pinfo->mipi.mipi_timing_modes[%d].mipi_timing.hsa = %d\n", i, pinfo->mipi.mipi_timing_modes[i].mipi_timing.hsa);
		pinfo->mipi.mipi_timing_modes[i].mipi_timing.hbp = fps_timing->buf[FPS_HBP];
		LCD_KIT_INFO("pinfo->mipi.mipi_timing_modes[%d].mipi_timing.hbp = %d\n", i, pinfo->mipi.mipi_timing_modes[i].mipi_timing.hbp);
		pinfo->mipi.mipi_timing_modes[i].mipi_timing.dpi_hsize = fps_timing->buf[FPS_HSIZE];
		LCD_KIT_INFO("pinfo->mipi.mipi_timing_modes[%d].mipi_timing.dpi_hsize = %d\n", i, pinfo->mipi.mipi_timing_modes[i].mipi_timing.dpi_hsize);
		pinfo->mipi.mipi_timing_modes[i].mipi_timing.hline_time = fps_timing->buf[FPS_HLINE];
		LCD_KIT_INFO("pinfo->mipi.mipi_timing_modes[%d].mipi_timing.hline_time = %d\n", i, pinfo->mipi.mipi_timing_modes[i].mipi_timing.hline_time);
		pinfo->mipi.mipi_timing_modes[i].mipi_timing.vsa = fps_timing->buf[FPS_VSA];
		LCD_KIT_INFO("pinfo->mipi.mipi_timing_modes[%d].mipi_timing.vsa = %d\n", i, pinfo->mipi.mipi_timing_modes[i].mipi_timing.vsa);
		pinfo->mipi.mipi_timing_modes[i].mipi_timing.vbp = fps_timing->buf[FPS_VBP];
		LCD_KIT_INFO("pinfo->mipi.mipi_timing_modes[%d].mipi_timing.vbp = %d\n", i, pinfo->mipi.mipi_timing_modes[i].mipi_timing.vbp);
		pinfo->mipi.mipi_timing_modes[i].mipi_timing.vfp = fps_timing->buf[FPS_VFP];
		LCD_KIT_INFO("pinfo->mipi.mipi_timing_modes[%d].mipi_timing.vfp = %d\n", i, pinfo->mipi.mipi_timing_modes[i].mipi_timing.vfp);
		pinfo->mipi.mipi_timing_modes[i].dsi_bit_clk_default = fps_timing->buf[FPS_DSI_CLK];
		LCD_KIT_INFO("pinfo->mipi.mipi_timing_modes[%d].dsi_bit_clk_default = %d\n", i, pinfo->mipi.mipi_timing_modes[i].dsi_bit_clk_default);
		pinfo->mipi.mipi_timing_modes[i].frame_rate = disp_info->fps.panel_support_fps_list.buf[i];
		LCD_KIT_INFO("pinfo->mipi.mipi_timing_modes[%d].frame_rate = %d\n", i, pinfo->mipi.mipi_timing_modes[i].frame_rate);
	}
	LCD_KIT_INFO("-\n");
}

static void parse_ltpo_base_cmd(int panel_id, struct device_node *np, struct dpu_panel_info *pinfo)
{
	int i;
	int j;
	int table_num;
	struct lcd_kit_dsi_panel_cmds ltpo_base_cmd[] = {
		disp_info->fps.fps_to_90_cmds,
		disp_info->fps.fps_to_120_cmds,
		disp_info->fps.refresh_cmds,
		disp_info->fps.fps_to_1_cmds,
	};

	table_num = sizeof(ltpo_base_cmd) / sizeof(ltpo_base_cmd[0]);
	for (i = 0; i < table_num; i++) {
		pinfo->dfr_info.oled_info.ltpo_info.dsi_cmds[i].cmd_num = ltpo_base_cmd[i].cmd_cnt;
		LCD_KIT_INFO("cmd %d +\n", i);
		for (j = 0; j < ltpo_base_cmd[i].cmd_cnt; j++)
			lcd_kit_cmds_to_dsi_cmds(&ltpo_base_cmd[i].cmds[j],
				&pinfo->dfr_info.oled_info.ltpo_info.dsi_cmds[i].cmds[j]);
		LCD_KIT_INFO("cmd %d -\n", i);
	}
}

static void safe_fps_cmd_to_dsi_cmds(int panel_id, struct dpu_panel_info *pinfo, unsigned int frame_rate, int num)
{
	int i;
	int j;
	int table_num;
	struct fps_cmd_table fps_safe_cmd[] = {
		{ FPS_120, &disp_info->fps.fps_to_120_cmds },
		{ FPS_90, &disp_info->fps.fps_to_90_cmds },
		{ FPS_60, &disp_info->fps.fps_to_60_cmds },
		{ FPS_45, &disp_info->fps.fps_to_45_cmds },
		{ FPS_40, &disp_info->fps.fps_to_40_cmds },
		{ FPS_30, &disp_info->fps.fps_to_30_cmds },
		{ FPS_24, &disp_info->fps.fps_to_24_cmds },
		{ FPS_20, &disp_info->fps.fps_to_20_cmds },
		{ FPS_18, &disp_info->fps.fps_to_18_cmds },
		{ FPS_15, &disp_info->fps.fps_to_15_cmds },
		{ FPS_10, &disp_info->fps.fps_to_10_cmds },
		{ FPS_1, &disp_info->fps.fps_to_1_cmds },
	};

	table_num = sizeof(fps_safe_cmd) / sizeof(fps_safe_cmd[0]);
	for (i = 0; i < table_num; i++) {
		if (frame_rate == fps_safe_cmd[i].val) {
			pinfo->dfr_info.oled_info.ltpo_info.safe_frm_rates[num].dsi_cmds.cmd_num = fps_safe_cmd[i].cmds->cmd_cnt;
			for (j = 0; j < fps_safe_cmd[i].cmds->cmd_cnt; j++)
				lcd_kit_cmds_to_dsi_cmds(&fps_safe_cmd[i].cmds->cmds[j],
					&pinfo->dfr_info.oled_info.ltpo_info.safe_frm_rates[num].dsi_cmds.cmds[j]);
			break;
		}
	}
}

#define MAX_SAFE_FREQ_COUNT 20
static void parse_ltpo_safe_cmd(int panel_id, struct device_node *np, struct dpu_panel_info *pinfo)
{
	int i;
	struct lcd_kit_array_data safe_freq;

	LCD_KIT_INFO("+\n");
	lcd_kit_parse_array_data(np, "lcd-kit,safe-frame-info", &safe_freq);
	pinfo->dfr_info.oled_info.ltpo_info.safe_frm_rates_num = safe_freq.cnt;
	if (safe_freq.cnt > MAX_SAFE_FREQ_COUNT) {
		LCD_KIT_ERR("safe_freq.cnt is %d too big!\n", safe_freq.cnt);
		return;
	}
	LCD_KIT_INFO("safe_freq.cnt is %d!\n", safe_freq.cnt);
	for (i = 0; i < safe_freq.cnt; i++) {
		pinfo->dfr_info.oled_info.ltpo_info.safe_frm_rates[i].safe_frm_rate = safe_freq.buf[i];
		LCD_KIT_INFO("safe_freq.buf[%d] is %d!\n", i, safe_freq.buf[i]);
		safe_fps_cmd_to_dsi_cmds(panel_id, pinfo, safe_freq.buf[i], i);
	}
	LCD_KIT_INFO("-\n");
}

#define MAX_TE_COUNT 20
static void parse_ltpo1_info(int panel_id, struct device_node *np, struct dpu_panel_info *pinfo)
{
	struct lcd_kit_array_data te_freq;
	int i;
	struct lcd_kit_array_data dimming_seq;
	struct lcd_kit_array_data repeat_num;

	lcd_kit_parse_array_data(np, "lcd-kit,te-freq-info", &te_freq);
	pinfo->dfr_info.oled_info.ltpo_info.te_freq_num = te_freq.cnt;
	if (te_freq.cnt > MAX_TE_COUNT) {
		LCD_KIT_ERR("te_freq.cnt is %d too big!\n", te_freq.cnt);
		return;
	}
	LCD_KIT_INFO("te_freq.cnt is %d!\n", te_freq.cnt);
	for (i = 0; i < te_freq.cnt; i++) {
		pinfo->dfr_info.oled_info.ltpo_info.te_freqs[i] = te_freq.buf[i];
		LCD_KIT_INFO("te_freq.buf[%d] is %d!\n", i, te_freq.buf[i]);
	}

	if ((lcd_kit_parse_array_data(np, "lcd-kit,dimming-seq", &dimming_seq) == LCD_KIT_OK) &&
		(lcd_kit_parse_array_data(np, "lcd-kit,repeat-num", &repeat_num) == LCD_KIT_OK)) {
		pinfo->dfr_info.oled_info.ltpo_info.dimming_sequence[DIMMING_SEQ_120HZ_INDEX].dimming_seq_num = dimming_seq.cnt;
		for (i = 0; i < dimming_seq.cnt; i++) {
			pinfo->dfr_info.oled_info.ltpo_info.dimming_sequence[DIMMING_SEQ_120HZ_INDEX].dimming_seq_list[i].frm_rate = dimming_seq.buf[i];
			pinfo->dfr_info.oled_info.ltpo_info.dimming_sequence[DIMMING_SEQ_120HZ_INDEX].dimming_seq_list[i].repeat_num = repeat_num.buf[i];
			LCD_KIT_INFO("frm_rate[%d] is %d!\n", i, dimming_seq.buf[i]);
			LCD_KIT_INFO("repeat_num[%d] is %d!\n", i, repeat_num.buf[i]);
		}
		pinfo->dfr_info.oled_info.ltpo_info.dimming_sequence[DIMMING_SEQ_120HZ_INDEX].type = DIMMING_SEQ_120HZ_INDEX;
	}
	parse_ltpo_base_cmd(panel_id, np, pinfo);
	parse_ltpo_safe_cmd(panel_id, np, pinfo);
}

static void parse_ltpo2_info(int panel_id, struct device_node *np, struct dpu_panel_info *pinfo)
{
	struct lcd_kit_array_data te_freq;
	int i;
	struct lcd_kit_array_data dimming_seq_120hz;
	struct lcd_kit_array_data repeat_num_120hz;
	struct lcd_kit_array_data dimming_seq_90hz;
	struct lcd_kit_array_data repeat_num_90hz;

	lcd_kit_parse_array_data(np, "lcd-kit,te-freq-info", &te_freq);
	pinfo->dfr_info.oled_info.ltpo_info.te_freq_num = te_freq.cnt;
	for (i = 0; i < te_freq.cnt; i++) {
		pinfo->dfr_info.oled_info.ltpo_info.te_freqs[i] = te_freq.buf[i];
		LCD_KIT_INFO("te_freq.buf[%d] is %d!\n", i, te_freq.buf[i]);
	}
	/* ltpo2 120hz dimming seq */
	if ((lcd_kit_parse_array_data(np, "lcd-kit,dimming-seq", &dimming_seq_120hz) == LCD_KIT_OK) &&
		(lcd_kit_parse_array_data(np, "lcd-kit,repeat-num", &repeat_num_120hz) == LCD_KIT_OK)) {
		pinfo->dfr_info.oled_info.ltpo_info.dimming_sequence[DIMMING_SEQ_120HZ_INDEX].dimming_seq_num = dimming_seq_120hz.cnt;
		for (i = 0; i < dimming_seq_120hz.cnt; i++) {
			pinfo->dfr_info.oled_info.ltpo_info.dimming_sequence[DIMMING_SEQ_120HZ_INDEX].dimming_seq_list[i].frm_rate = dimming_seq_120hz.buf[i];
			pinfo->dfr_info.oled_info.ltpo_info.dimming_sequence[DIMMING_SEQ_120HZ_INDEX].dimming_seq_list[i].repeat_num = repeat_num_120hz.buf[i];
			LCD_KIT_INFO("120hz frm_rate[%d] is %d!\n", i, dimming_seq_120hz.buf[i]);
			LCD_KIT_INFO("120hz repeat_num[%d] is %d!\n", i, repeat_num_120hz.buf[i]);
		}
		pinfo->dfr_info.oled_info.ltpo_info.dimming_sequence[DIMMING_SEQ_120HZ_INDEX].type = DIMMING_SEQ_120HZ_INDEX;
	}
	/* ltpo2 90hz dimming seq */
	if ((lcd_kit_parse_array_data(np, "lcd-kit,90hz-dimming-seq", &dimming_seq_90hz) == LCD_KIT_OK) &&
		(lcd_kit_parse_array_data(np, "lcd-kit,90hz-repeat-num", &repeat_num_90hz) == LCD_KIT_OK)) {
	pinfo->dfr_info.oled_info.ltpo_info.dimming_sequence[DIMMING_SEQ_90HZ_INDEX].dimming_seq_num = dimming_seq_90hz.cnt;
		for (i = 0; i < dimming_seq_90hz.cnt; i++) {
			pinfo->dfr_info.oled_info.ltpo_info.dimming_sequence[DIMMING_SEQ_90HZ_INDEX].dimming_seq_list[i].frm_rate = dimming_seq_90hz.buf[i];
			pinfo->dfr_info.oled_info.ltpo_info.dimming_sequence[DIMMING_SEQ_90HZ_INDEX].dimming_seq_list[i].repeat_num = repeat_num_90hz.buf[i];
			LCD_KIT_INFO("90hz frm_rate[%d] is %d!\n", i, dimming_seq_90hz.buf[i]);
			LCD_KIT_INFO("90hz repeat_num[%d] is %d!\n", i, repeat_num_90hz.buf[i]);
		}
		pinfo->dfr_info.oled_info.ltpo_info.dimming_sequence[DIMMING_SEQ_90HZ_INDEX].type = DIMMING_SEQ_90HZ_INDEX;
	}
	parse_ltpo_base_cmd(panel_id, np, pinfo);
	parse_ltpo_safe_cmd(panel_id, np, pinfo);
}

static void parse_ltpo_info(int panel_id, struct device_node *np, struct dpu_panel_info *pinfo)
{
	unsigned int i;

	lcd_kit_parse_u32(np, "lcd-kit,ltpo-ver", &pinfo->dfr_info.oled_info.ltpo_info.ver, 0);
	lcd_kit_parse_u32(np, "lcd-kit,dfr-mode", &pinfo->dfr_info.dfr_mode, 0);

#ifdef LCD_FACTORY_MODE
	pinfo->dfr_info.dfr_mode = 0;
	pinfo->dfr_info.oled_info.ltpo_info.dimming_enable = 0;
#else
	pinfo->dfr_info.oled_info.ltpo_info.dimming_enable = 1;
#endif
	lcd_kit_parse_u32(np, "lcd-kit,panel-ddic-type", &pinfo->dfr_info.ddic_type, 0);
	for (i = 0; i < pinfo->dfr_info.oled_info.fps_sup_num; i++) {
		pinfo->dfr_info.oled_info.fps_sup_seq[i] = disp_info->fps.panel_support_fps_list.buf[pinfo->dfr_info.oled_info.fps_sup_num - 1 - i];
		LCD_KIT_INFO("pinfo->dfr_info.oled_info.fps_sup_seq[%d] is %d\n", i, pinfo->dfr_info.oled_info.fps_sup_seq[i]);
	}
	if (pinfo->dfr_info.oled_info.ltpo_info.ver == PANEL_LTPO_V1)
		parse_ltpo1_info(panel_id, np, pinfo);
	if (pinfo->dfr_info.oled_info.ltpo_info.ver == PANEL_LTPO_V2)
		parse_ltpo2_info(panel_id, np, pinfo);
}

static void lcd_kit_parse_pinfo_fps(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	int i;

	if (!disp_info->fps.support) {
		LCD_KIT_INFO("not support fps\n");
		return;
	}
	lcd_kit_parse_u32(np, "lcd-kit,oled-type", &pinfo->dfr_info.oled_info.oled_type, 0);
	LCD_KIT_INFO("oled_type %d\n", pinfo->dfr_info.oled_info.oled_type);
	pinfo->fps = disp_info->fps.default_fps;
	disp_info->fps.current_fps = disp_info->fps.default_fps;
	LCD_KIT_INFO("pinfo->fps %d\n", pinfo->fps);
	LCD_KIT_INFO("disp_info->fps.current_fps %d\n", disp_info->fps.current_fps);
	pinfo->dfr_info.oled_info.fps_sup_num = disp_info->fps.panel_support_fps_list.cnt;
	LCD_KIT_INFO("pinfo->dfr_info.oled_info.fps_sup_num %d\n", pinfo->dfr_info.oled_info.fps_sup_num);
	for (i = 0; i < pinfo->dfr_info.oled_info.fps_sup_num; i++) {
		pinfo->dfr_info.oled_info.fps_sup_seq[i] = disp_info->fps.panel_support_fps_list.buf[i];
		LCD_KIT_INFO("pinfo->dfr_info.oled_info.fps_sup_seq[%d] is %d\n", i, pinfo->dfr_info.oled_info.fps_sup_seq[i]);
	}
	if (pinfo->dfr_info.oled_info.oled_type == LTPS)
		parse_ltps_info(panel_id, np, pinfo);
	if (pinfo->dfr_info.oled_info.oled_type == LTPO)
		parse_ltpo_info(panel_id, np, pinfo);
}

static void lcd_kit_parse_utils(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	LCD_KIT_INFO("enter\n");
	/* pcd errflag */
	lcd_kit_parse_u32(np, "lcd-kit,pcd-errflag-check-support",
		&disp_info->pcd_errflag.pcd_errflag_check_support, 0);
	lcd_kit_parse_u32(np, "lcd-kit,gpio-pcd",
		&disp_info->pcd_errflag.gpio_pcd, 0);
	lcd_kit_parse_u32(np, "lcd-kit,gpio-errflag",
		&disp_info->pcd_errflag.gpio_errflag, 0);
	lcd_kit_parse_u32(np, "lcd-kit,pcd-cmds-support",
		&disp_info->pcd_errflag.pcd_support, 0);
	lcd_kit_parse_u32(np, "lcd-kit,pcd-power-on-support",
		&disp_info->pcd_errflag.power_on_support, 1);
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
	lcd_kit_parse_u32(np, "lcd-kit,camera-prox",
		&disp_info->camera_prox, 0);
}

static void lcd_kit_parse_panel_dieid(int panel_id, struct device_node *np)
{
	lcd_kit_parse_u32(np, "lcd-kit,panel-dieid-support",
		&disp_info->panel_dieid_info.support, 0);

	if (disp_info->panel_dieid_info.support)
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,panel-dieid-cmds",
			"lcd-kit,panel-dieid-cmds-state",
				&disp_info->panel_dieid_info.cmds);
}

static void lcd_kit_parse_power_off_optimize(int panel_id, struct device_node *np)
{
	lcd_kit_parse_u32(np, "lcd-kit,pwr-off-time-optimize-support",
		&disp_info->pwr_off_optimize_info.support, 0);

	if (disp_info->pwr_off_optimize_info.support)
		lcd_kit_parse_u32(np, "lcd-kit,pwr-off-time-work-delay",
			&disp_info->pwr_off_optimize_info.delay_time, 100);
}

static void lcd_kit_parse_panel_version_info(int panel_id, struct device_node *np)
{
	lcd_kit_parse_dcs_cmds(np, "lcd-kit,panel-version-enter-cmds",
		"lcd-kit,panel-version-enter-cmds-state",
		&disp_info->panel_version.enter_cmds);
	lcd_kit_parse_dcs_cmds(np, "lcd-kit,panel-version-cmds",
		"lcd-kit,panel-version-cmds-state",
		&disp_info->panel_version.cmds);
	lcd_kit_parse_dcs_cmds(np, "lcd-kit,panel-version-exit-cmds",
		"lcd-kit,panel-version-exit-cmds-state",
		&disp_info->panel_version.exit_cmds);
	lcd_kit_parse_dcs_cmds(np, "lcd-kit,panel-secend-version-enter-cmds",
		"lcd-kit,panel-secend-version-enter-cmds-state",
		&disp_info->panel_version.secend_enter_cmds);
	lcd_kit_parse_dcs_cmds(np, "lcd-kit,panel-secend-version-cmds",
		"lcd-kit,panel-secend-version-cmds-state",
		&disp_info->panel_version.secend_cmds);
	lcd_kit_parse_dcs_cmds(np, "lcd-kit,panel-secend-version-exit-cmds",
		"lcd-kit,panel-secend-version-exit-cmds-state",
		&disp_info->panel_version.secend_exit_cmds);
}

static void lcd_kit_parse_panel_version_value(int panel_id, struct device_node *np)
{
	disp_info->panel_version.value_number = 0;
	if (disp_info->panel_version.cmds.cmds->dlen == 1)
		disp_info->panel_version.value_number = 1;
	if (disp_info->panel_version.cmds.cmds->dlen > 1)
		disp_info->panel_version.value_number = disp_info->panel_version.cmds.cmds->dlen -
			disp_info->panel_version.cmds.cmds->payload[1];
	if (disp_info->panel_version.secend_cmds.cmds != NULL) {
		disp_info->panel_version.secend_value_number =
			disp_info->panel_version.secend_cmds.cmds->dlen -
			disp_info->panel_version.secend_cmds.cmds->payload[1];
		disp_info->panel_version.value_number += disp_info->panel_version.secend_value_number;
		LCD_KIT_INFO("value_num=%d secend_value_number = %d\n",
			disp_info->panel_version.value_number,
			disp_info->panel_version.secend_value_number);
	}
	lcd_kit_parse_arrays_data(np, "lcd-kit,panel-version-value",
		&disp_info->panel_version.value,
		disp_info->panel_version.value_number);
}

static void lcd_kit_parse_panel_version_name(int panel_id, struct device_node *np)
{
	int i;
	int ret = 0;
	char *name[VERSION_NUM_MAX] = {NULL};

	disp_info->panel_version.version_number =
		(u32)disp_info->panel_version.value.cnt;
	LCD_KIT_INFO("Panel version value_num=%d version_num = %d\n",
		disp_info->panel_version.value_number,
		disp_info->panel_version.version_number);
	if (disp_info->panel_version.version_number > 0) {
		ret = lcd_kit_parse_string_array(np,
			"lcd-kit,panel-version",
			(const char **)&name[0],
			disp_info->panel_version.version_number);
		if (ret < 0)
			LCD_KIT_INFO("Panel version parse fail\n");
		for (i = 0; i < (int)disp_info->panel_version.version_number; i++) {
			strncpy(disp_info->panel_version.lcd_version_name[i],
				name[i], LCD_PANEL_VERSION_SIZE - 1);
			LCD_KIT_INFO("Panel version name[%d] = %s\n",
				i, name[i]);
		}
	}
}

static void lcd_kit_parse_panel_version(int panel_id, struct device_node *np)
{
	/* panel version */
	lcd_kit_parse_u32(np, "lcd-kit,panel-version-support",
		&disp_info->panel_version.support, 0);
	if (disp_info->panel_version.support) {
		lcd_kit_parse_u32(np, "lcd-kit,panel-version-read-at-uefi",
			&disp_info->panel_version.read_at_uefi, 0);
		lcd_kit_parse_panel_version_info(panel_id, np);
		lcd_kit_parse_panel_version_value(panel_id, np);
		lcd_kit_parse_panel_version_name(panel_id, np);
	}
}

static void lcd_kit_parse_esd_info(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	unsigned int esd_support;

	esd_support = lcd_kit_get_esd_support(panel_id);
	if (esd_support) {
		pinfo->esd_enable = esd_support;
		disp_info->esd_enable = esd_support;
		lcd_kit_parse_u32(np, "lcd-kit,esd-recovery-max-count",
			&pinfo->esd_info.esd_recovery_max_count, 10);
		/* esd_check_max_count set 3 times as default */
		lcd_kit_parse_u32(np, "lcd-kit,esd-check-max-count",
			&pinfo->esd_info.esd_check_max_count, 3);
		lcd_kit_parse_u8(np, "lcd-kit,esd-timing-ctrl",
			&pinfo->esd_info.esd_timing_ctrl, 0);
		lcd_kit_parse_u32(np, "lcd-kit,esd-check-time-period",
			&pinfo->esd_info.esd_check_time_period, 0);
		lcd_kit_parse_u32(np, "lcd-kit,esd-first-check-delay",
			&pinfo->esd_info.esd_first_check_delay, 0);
	}
}

static void lcd_kit_parse_check_mipi(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_parse_u32(np, "lcd-kit,check-mipi-support",
		&disp_info->check_mipi.support, 0);

	if (!disp_info->check_mipi.support)
		return;

	LCD_KIT_ERR("lcd_kit_parse_check_mipi\n");
	lcd_kit_parse_u32(np, "lcd-kit,check-mipi-max-number",
		&disp_info->check_mipi.max_number, 0);
	lcd_kit_parse_dcs_cmds(np, "lcd-kit,check-mipi-cmds",
		"lcd-kit,check-mipi-cmds-state", &disp_info->check_mipi.cmds);
	lcd_kit_parse_array_data(np, "lcd-kit,check-mipi-value",
		&disp_info->check_mipi.value);
	lcd_kit_parse_array_data(np, "lcd-kit,check-mipi-judge-type",
		&disp_info->check_mipi.judge_type);
	lcd_kit_parse_dcs_cmds(np, "lcd-kit,check-mipi-sub-cmds",
		"lcd-kit,check-mipi-sub-cmds-state", &disp_info->check_mipi.sub_cmds);
	lcd_kit_parse_array_data(np, "lcd-kit,check-mipi-sub-value",
		&disp_info->check_mipi.sub_value);
}

static void lcd_kit_parse_dirty_region(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	if (common_info->dirty_region.support) {
		LCD_KIT_INFO("dirty_region_support = %d %d\n", common_info->dirty_region.support);
		pinfo->user_info.dirty_region_updt_support = common_info->dirty_region.support;
		lcd_kit_parse_dirty_info(np, "lcd-kit,dirty-left-align",
			&pinfo->user_info.left_align);
		lcd_kit_parse_dirty_info(np, "lcd-kit,dirty-right-align",
			&pinfo->user_info.right_align);
		lcd_kit_parse_dirty_info(np, "lcd-kit,dirty-top-align",
			&pinfo->user_info.top_align);
		lcd_kit_parse_dirty_info(np, "lcd-kit,dirty-bott-align",
			&pinfo->user_info.bottom_align);
		lcd_kit_parse_dirty_info(np, "lcd-kit,dirty-width-align",
			&pinfo->user_info.w_align);
		lcd_kit_parse_dirty_info(np, "lcd-kit,dirty-height-align",
			&pinfo->user_info.h_align);
		lcd_kit_parse_dirty_info(np, "lcd-kit,dirty-width-min",
			&pinfo->user_info.w_min);
		lcd_kit_parse_dirty_info(np, "lcd-kit,dirty-height-min",
			&pinfo->user_info.h_min);
		lcd_kit_parse_dirty_info(np, "lcd-kit,dirty-top-start",
			&pinfo->user_info.top_start);
		lcd_kit_parse_dirty_info(np, "lcd-kit,dirty-bott-start",
			&pinfo->user_info.bottom_start);
	}
}

#define LCD_PROJECT_ID_SIZE 32

static void lcd_kit_parse_project_id(int panel_id, struct device_node *np)
{
	int ret = 0;

	lcd_kit_parse_u32(np, "lcd-kit,project-id-support",
		&disp_info->project_id.support, 0);

	if (disp_info->project_id.support) {
		disp_info->project_id.default_project_id = (char *)of_get_property(np,
			"lcd-kit,default-project-id", NULL);
		LCD_KIT_INFO("project_id is %s", disp_info->project_id.default_project_id);
	}
}

static void lcd_kit_init_pinfo(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	if (!pinfo) {
		LCD_KIT_ERR("pinfo is null\n");
		return;
	}

	lcd_kit_parse_base_pinfo(panel_id, np, pinfo);
	lcd_kit_parse_mipi(np, pinfo);
	lcd_kit_parse_bl_info(np, pinfo);
	lcd_kit_parse_dsc_param(np, pinfo);
	lcd_kit_parse_pinfo_fps(panel_id, np, pinfo);
	lcd_kit_parse_utils(panel_id, np, pinfo);
	lcd_kit_parse_panel_dieid(panel_id, np);
	lcd_kit_parse_power_off_optimize(panel_id, np);
	lcd_kit_parse_panel_version(panel_id, np);
	lcd_kit_parse_check_mipi(panel_id, np, pinfo);
	lcd_kit_parse_esd_info(panel_id, np, pinfo);
	lcd_kit_parse_dirty_region(panel_id, np, pinfo);
	lcd_kit_parse_spr_info(panel_id, np, pinfo);
	lcd_kit_parse_project_id(panel_id, np);
}

bool lcd_kit_support(void)
{
	struct device_node *lcdkit_np = NULL;
	const char *support_type = NULL;
	ssize_t ret;

	lcdkit_np = of_find_compatible_node(NULL, NULL, DTS_COMP_LCD_KIT_PANEL_TYPE);
	if (!lcdkit_np) {
		LCD_KIT_ERR("NOT FOUND device node!\n");
		return false;
	}
	ret = of_property_read_string(lcdkit_np, "support_lcd_type", &support_type);
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

static int lcd_kit_get_project_id(char *buff)
{
	int panel_id = lcd_kit_get_active_panel_id();

	if (lcd_kit_get_display_type() != NORMAL_TYPE)
		panel_id = SECONDARY_PANEL;

	if (!buff) {
		LCD_KIT_ERR("buff is null\n");
		return LCD_KIT_FAIL;
	}
	if (!disp_info->project_id.support) {
		LCD_KIT_ERR("project_id is not support\n");
		return LCD_KIT_FAIL;
	}
	if (disp_info->project_id.default_project_id) {
		strncpy(buff, disp_info->project_id.default_project_id, strlen(disp_info->project_id.default_project_id));
		return LCD_KIT_OK;
	}
	return LCD_KIT_FAIL;
}

static int lcd_kit_get_online_status(int panel_id)
{
	int status = LCD_ONLINE;

	if (!strncmp(disp_info->compatible, LCD_KIT_DEFAULT_PANEL,
		strlen(disp_info->compatible)))
		status = LCD_OFFLINE;
	LCD_KIT_INFO("status = %d\n", status);
	return status;
}

int lcd_kit_get_status_by_type(int type, int *status)
{
	int ret;
	int panel_id = lcd_kit_get_active_panel_id();

	if (status == NULL) {
		LCD_KIT_ERR("status is null\n");
		return LCD_KIT_FAIL;
	}
	switch (type) {
	case LCD_ONLINE_TYPE:
		*status = lcd_kit_get_online_status(panel_id);
		ret = LCD_KIT_OK;
		break;
	case PT_STATION_TYPE:
#ifdef LCD_FACTORY_MODE
		*status = lcd_kit_get_pt_station_status(panel_id);
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

void lcd_kit_mipi_error_dmd_report(
	u8 reg_val[MIPI_DETECT_LOOP][MIPI_DETECT_NUM][VAL_NUM])
{
	char err_info[DMD_DET_ERR_LEN] = "lcd mipi error detect error, report dmd";
	LCD_KIT_INFO("mipi detect DMD report\n");
	if (!reg_val) {
		LCD_KIT_ERR("reg_val is NULL\n");
		return;
	}
	lcd_dmd_report_err(DSM_LCD_MIPI_TRANSMIT_ERROR_NO, err_info,
		 DMD_ERR_INFO_LEN);
	LCD_KIT_INFO(" with DSM_LCD_MIPI_TRANSMIT_ERROR_NO \n");
}

void lcd_kit_check_sum2_dmd_report(
	u8 reg_val[MIPI_DETECT_NUM][VAL_NUM])
{
	char err_info[DMD_DET_ERR_LEN] = "lcd check sum2 detect error, report dmd";
	LCD_KIT_INFO("check_sum2 detect DMD report\n");
	if (!reg_val) {
		LCD_KIT_ERR("reg_val is NULL\n");
		return;
	}
	lcd_dmd_report_err(DSM_LCD_CHECKSUM_ERROR_NO, err_info,
		 DMD_ERR_INFO_LEN);
	LCD_KIT_INFO(" with DSM_LCD_CHECKSUM_ERROR_NO \n");
}

void lcd_kit_mbist_detect_dmd_report(
	u8 reg_val[MBIST_LOOPS][DETECT_NUM][VAL_NUM])
{
	char err_info[DMD_DET_ERR_LEN] = "lcd mbist detect error, report dmd";
	if (!reg_val) {
		LCD_KIT_ERR("reg_val is NULL\n");
		return;
	}
	lcd_dmd_report_err(DSM_LCD_ESD_STATUS_ERROR_NO, err_info,
		DMD_DET_ERR_LEN);
	LCD_KIT_INFO(" with DSM_LCD_ESD_STATUS_ERROR_NO \n");
}

void lcd_kit_sn_reprocess(uint32_t panel_id, char *buff, unsigned int len)
{
	int i;
	int j = 0;

	if (!common_info->sn_code.reprocess_support) {
		LCD_KIT_INFO("no need reprocess\n");
		return;
	}

	if (!buff) {
		LCD_KIT_ERR("buff is NULL\n");
		return;
	}

	if (len < SN_CODE_23_NUMB_SIZE) {
		LCD_KIT_ERR("len is error\n");
		return;
	}

	for (i = 0; (i < SN_CODE_23_NUMB_SIZE) && (j < SN_CODE_2_NONE_SIZE); i++) {
		LCD_KIT_INFO("sn read:%d-%d\n", i, buff[i]);
		if (buff[i] == 0) {
			buff[i] = '0';
			LCD_KIT_INFO("sn reprocess:%d-%d\n", i, buff[i]);
			j++;
		}
	}
	return;
}

static int lcd_kit_get_sn_code(int panel_id)
{
	int ret;
	char read_value[OEM_INFO_SIZE_MAX + 1] = {0};

	if (common_info && common_info->sn_code.support) {
		if (disp_info && disp_info->oeminfo.barcode_2d.support) {
			ret = lcd_kit_cmds_rx(panel_id, NULL, read_value,
				OEM_INFO_SIZE_MAX,
				&disp_info->oeminfo.barcode_2d.cmds);
			if (ret != 0) {
				LCD_KIT_ERR("get sn_code error!\n");
				return LCD_KIT_FAIL;
			}
			LCD_KIT_INFO("do lcd_kit_sn_reprocess\n");
			lcd_kit_sn_reprocess(panel_id, read_value, OEM_INFO_SIZE_MAX);
			memcpy(disp_info->sn_code, read_value, LCD_KIT_SN_CODE_LENGTH);
			disp_info->sn_code_length = LCD_KIT_SN_CODE_LENGTH;
			return LCD_KIT_OK;
		}
	}
	return LCD_KIT_FAIL;
}

static int lcd_get_panel_dieid_info(uint32_t panel_id, char *buff)
{
	int ret = LCD_KIT_OK;
	struct lcd_kit_adapt_ops *adapt_ops = lcd_kit_get_adapt_ops();

	if (!adapt_ops) {
		LCD_KIT_ERR("can not get adapt_ops!\n");
		return LCD_KIT_FAIL;
	}
	if (!adapt_ops->mipi_rx) {
		LCD_KIT_ERR("mipi_rx or mipi_tx is NULL\n");
		return LCD_KIT_FAIL;
	}
	if (!buff) {
		LCD_KIT_ERR("buff is NULL\n");
		return LCD_KIT_FAIL;
	}

	ret = adapt_ops->mipi_rx(panel_id, NULL, buff,	PANEL_DIEID_DATA_SIZE_MAX,
		&disp_info->panel_dieid_info.cmds);
	if (ret) {
		LCD_KIT_ERR("get panel dieid info fail\n");
		return LCD_KIT_FAIL;
	}
	return LCD_KIT_OK;
}

int lcd_kit_power_off_event_skip_send(int panel_id)
{
	return disp_info->pwr_off_optimize_info.support && g_skip_power_on_off;
}

void lcd_kit_notify_panel_switch(void)
{
	LCD_KIT_INFO("notify panel switch\n");
	g_skip_power_on_off = true;
}

bool lcd_kit_get_skip_power_on_off(void)
{
	return g_skip_power_on_off;
}

void lcd_kit_set_skip_power_on_off(bool status)
{
	g_skip_power_on_off = status;
}

static int lcd_kit_panel_version_read_secend(uint32_t panel_id, struct lcd_kit_adapt_ops *adapt_ops)
{
	int ret = LCD_KIT_OK;

	if (disp_info->panel_version.secend_enter_cmds.cmds != NULL) {
		ret = adapt_ops->mipi_tx(panel_id, NULL, &disp_info->panel_version.secend_enter_cmds);
		if (ret)
			return LCD_KIT_FAIL;
	}
	if (disp_info->panel_version.secend_cmds.cmds != NULL) {
		ret = adapt_ops->mipi_rx(panel_id, NULL,
			(uint8_t *)disp_info->panel_version.read_value +
				(int)disp_info->panel_version.value_number -
				disp_info->panel_version.secend_value_number,
			VERSION_VALUE_NUM_MAX - 1,
			&disp_info->panel_version.secend_cmds);
		if (ret)
			return LCD_KIT_FAIL;
	}
	if (disp_info->panel_version.secend_exit_cmds.cmds != NULL) {
		ret = adapt_ops->mipi_tx(panel_id, NULL, &disp_info->panel_version.secend_exit_cmds);
		if (ret)
			return LCD_KIT_FAIL;
	}
	return LCD_KIT_OK;
}

static int lcd_kit_panel_version_read(uint32_t panel_id)
{
	int ret = LCD_KIT_OK;
	struct lcd_kit_adapt_ops *adapt_ops = lcd_kit_get_adapt_ops();

	if (panel_id != PRIMARY_PANEL) {
		LCD_KIT_ERR("not support start up to read other panel \n");
		return LCD_KIT_FAIL;
	}
	if (!adapt_ops) {
		LCD_KIT_ERR("can not get adapt_ops!\n");
		return LCD_KIT_FAIL;
	}
	if (!adapt_ops->mipi_rx || !adapt_ops->mipi_tx) {
		LCD_KIT_ERR("mipi_rx or mipi_tx is NULL\n");
		return LCD_KIT_FAIL;
	}

	if (disp_info->panel_version.enter_cmds.cmds != NULL) {
		ret = adapt_ops->mipi_tx(panel_id, NULL, &disp_info->panel_version.enter_cmds);
		if (ret)
			return LCD_KIT_FAIL;
	}
	ret = adapt_ops->mipi_rx(panel_id, NULL, (uint8_t *)disp_info->panel_version.read_value,
		VERSION_VALUE_NUM_MAX - 1, &disp_info->panel_version.cmds);
	if (ret) {
		LCD_KIT_ERR("mipi read panel version info fail\n");
		return LCD_KIT_FAIL;
	}
	if (disp_info->panel_version.exit_cmds.cmds != NULL) {
		ret = adapt_ops->mipi_tx(panel_id, NULL,
			&disp_info->panel_version.exit_cmds);
		if (ret)
			return LCD_KIT_FAIL;
	}
	ret = lcd_kit_panel_version_read_secend(panel_id, adapt_ops);
	return LCD_KIT_OK;
}

static void panel_version_cat(uint32_t panel_id, u32 i)
{
	memcpy(disp_info->panel_version.lcd_panel_version,
		" VER:", strlen(" VER:") + 1);
	strncat(disp_info->panel_version.lcd_panel_version,
		disp_info->panel_version.lcd_version_name[i],
		strlen(disp_info->panel_version.lcd_version_name[i]));
	LCD_KIT_INFO("Panel version is %s\n",
		disp_info->panel_version.lcd_panel_version);
}

static int lcd_kit_parse_panel_version_by_uefi(uint32_t panel_id)
{
	unsigned int panel_version;
	int i;
	int index;

	if (panel_id == PRIMARY_PANEL)
		panel_version = PUBLIC_INFO->primary_panel_version;
	else if (panel_id == SECONDARY_PANEL)
		panel_version = PUBLIC_INFO->secondary_panel_version;

	if (!panel_version) {
		LCD_KIT_ERR("uefi panel version is null\n");
		return LCD_KIT_FAIL;
	}

	for (i = 0; i < disp_info->panel_version.value_number; i++) {
		index = disp_info->panel_version.value_number - i - 1;
		disp_info->panel_version.read_value[index] = panel_version & 0xFF;
		panel_version = panel_version >> 8;
	}

	return LCD_KIT_OK;
}

static int panel_version_compare(uint32_t panel_id)
{
	u32 i;
	u32 j;

	for (i = 0; i < disp_info->panel_version.version_number; i++) {
		for (j = 0; j < disp_info->panel_version.value_number; j++) {
			LCD_KIT_INFO("read_value[%d]:0x%x\n", j,
				disp_info->panel_version.read_value[j]);
			LCD_KIT_INFO("expected_value[%d].buf[%d]:0x%x\n", i, j,
				disp_info->panel_version.value.arry_data[i].buf[j]);
			if (disp_info->panel_version.read_value[j] !=
				disp_info->panel_version.value.arry_data[i].buf[j])
				break;

			if (j == (disp_info->panel_version.value_number - 1)) {
				panel_version_cat(panel_id, i);
				return LCD_KIT_OK;
			}
		}
	}

	LCD_KIT_INFO("panel_version not find\n");
	return LCD_KIT_FAIL;
}

int lcd_kit_panel_version_init(int panel_id)
{
	int ret;
	if (!disp_info->panel_version.support) {
		LCD_KIT_INFO("not support panel version\n");
		return LCD_KIT_FAIL;
	}

	if (disp_info->panel_version.read_at_uefi)
		ret = lcd_kit_parse_panel_version_by_uefi(panel_id);
	else
		ret = lcd_kit_panel_version_read(panel_id);

	if (ret) {
		LCD_KIT_ERR("read panel version cmd fail\n");
		return LCD_KIT_FAIL;
	}
	ret = panel_version_compare(panel_id);
	return ret;
}

static void parse_esd_enable(int panel_id, const char *command)
{
	if (strncmp("esd_enable:", command, strlen("esd_enable:")))
		return;
	if (command[strlen("esd_enable:")] == '0')
		lcd_esd_enable(panel_id, 0);
	else
		lcd_esd_enable(panel_id, 1);
}


int lcd_kit_parse_switch_cmd(int panel_id, const char *command)
{
	parse_esd_enable(panel_id, command);
	return LCD_KIT_OK;
}

int lcd_kit_get_aod_panel_state(int panel_id)
{
#if defined(CONFIG_DKMD_DPU_AOD)
	int aod_state = dkmd_get_lcd_status();

	if (panel_id == PRIMARY_PANEL)
		return aod_state & BIT(PRIMARY_PANEL_AOD_BIT);
	else if (panel_id == SECONDARY_PANEL)
		return aod_state & BIT(SECONDARY_PANEL_AOD_BIT);
	else
		return 0;
#else
	return 0;
#endif
}

void lcd_kit_clean_aod_panel_state(int panel_id)
{
#if defined(CONFIG_DKMD_DPU_AOD)
	if (panel_id == PRIMARY_PANEL)
		dkmd_set_lcd_status(PRIMARY_PANEL_AOD_BIT, 0);
	else if (panel_id == SECONDARY_PANEL)
		dkmd_set_lcd_status(SECONDARY_PANEL_AOD_BIT, 0);
	else
		return;
#else
	return;
#endif
}

static bool lcd_kit_panel_event_skip_delay(int panel_id, void *hld,
	uint32_t event, uint32_t data)
{
	return lcd_kit_get_aod_panel_state(panel_id);
}

int lcd_kit_get_power_status(int panel_id)
{
	return lcd_kit_get_aod_panel_state(panel_id);
}

int lcd_kit_dvdd_hpm_ctrl(void)
{
	int ret = LCD_KIT_OK;
	int panel_id = lcd_kit_get_active_panel_id();

	if (PUBLIC_INFO->dvdd_avs_volt > 0)
		LCD_KIT_INFO("lcd dvdd voltage hpm_val = %d\n", PUBLIC_INFO->dvdd_avs_volt);

	return ret;
}

struct lcd_kit_ops g_lcd_ops = {
	.lcd_kit_support = lcd_kit_support,
	.get_project_id = lcd_kit_get_project_id,
	.get_status_by_type = lcd_kit_get_status_by_type,
#ifdef LCD_FACTORY_MODE
	.get_pt_station_status = lcd_kit_get_pt_station_status,
#endif
	.get_sn_code = lcd_kit_get_sn_code,
	.get_panel_dieid = lcd_get_panel_dieid_info,
	.event_skip_send = lcd_kit_power_off_event_skip_send,
	.notify_panel_switch = lcd_kit_notify_panel_switch,
	.panel_event_skip_delay = lcd_kit_panel_event_skip_delay,
	.get_panel_power_status = lcd_kit_get_power_status,
	.dvdd_hpm_ctrl = lcd_kit_dvdd_hpm_ctrl,
};

int lcd_kit_utils_init(int panel_id, struct device_node *np, struct dpu_panel_info *pinfo)
{
	/* init sem */
	lcd_kit_init_sema(panel_id);
	/* init display */
	lcd_kit_init_display(panel_id, np);
	/* init dpu pinfo */
	lcd_kit_init_pinfo(panel_id, np, pinfo);
	/* register lcd ops */
	lcd_kit_ops_register(&g_lcd_ops);
	/* init display engine params */
	lcd_kit_display_engine_param_init(panel_id, np);
	return LCD_KIT_OK;
}

