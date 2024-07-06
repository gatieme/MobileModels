/*
 * lcd_kit_disp.c
 *
 * lcdkit display function for lcd driver
 *
 * Copyright (c) 2022-2024 Huawei Technologies Co., Ltd.
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

#include "lcd_kit_disp.h"
#include "lcd_kit_common.h"
#include "lcd_kit_utils.h"
#include "lcd_kit_parse.h"
#include "lcd_kit_adapt.h"
#include "lcd_kit_sysfs_dkmd.h"
#include "lcd_kit_power.h"
#include "lcd_kit_ioctl.h"
#include "lcd_kit_local_hbm.h"
#ifdef LCD_KIT_DEBUG_ENABLE
#include "lcd_kit_dbg.h"
#endif
#ifdef CONFIG_DFX_ZEROHUNG
#include <platform/trace/hooks/zerohung.h>
#endif
#ifdef LCD_FACTORY_MODE
#include "lcd_kit_fac.h"
#endif
#include <platform_include/basicplatform/linux/mfd/pmic_platform.h>
#include <huawei_platform/comb_key/comb_key_event.h>
#include "dkmd_lcd_interface.h"
#ifdef CONFIG_HUAWEI_DSM
#include <dsm/dsm_pub.h>
#endif
#ifdef CONFIG_INPUTHUB_20
#include <huawei_platform/inputhub/sensor_feima_ext.h>
#endif
#ifdef CONFIG_POWER_DUBAI
#include <huawei_platform/log/log_jank.h>
#endif

#ifdef CONFIG_HUAWEI_DSM
static struct dsm_dev dsm_lcd = {
	.name = "dsm_lcd",
	.device_name = NULL,
	.ic_name = NULL,
	.module_name = NULL,
	.fops = NULL,
	.buff_size = 1024,
};

struct dsm_client *lcd_dclient = NULL;
#endif

static int g_restart_type = PRESS_POWER_VOL_DOWN;
static int init_order[MAX_PANEL] =    { PRIMARY_PANEL, SECONDARY_PANEL };
static char *disp_compatibles[MAX_PANEL] = { "lcd_panel_type", "sec_lcd_panel_type" };
static struct lcd_kit_disp_info g_lcd_kit_disp_info[MAX_PANEL];
static struct dpu_panel_info g_dpu_pinfo[MAX_PANEL];
struct lcd_kit_public_info g_lcd_kit_public_info = {
	NORMAL_TYPE,
	PRIMARY_PANEL,
};
static struct lcd_kit_disp_lock g_lcd_kit_disp_lock[MAX_PANEL];

static struct lcd_kit_panel_params g_lcd_kit_panels[] = {
	{3000, 0x00, "190_c07_7p847"},
	{3000, 0x400, "190_c07_1_7p847"},
	{3000, 0x04, "310_c07_7p847"},
	{3000, 0x404, "310_c07_1_7p847"},
	{3000, 0x04, "310_c07_7p847"},
	{3000, 0x15, "default_7p847"},
};

static int lcd_kit_updt_fps(int panel_id, unsigned int fps);
static void lcd_kit_register_power_key_notify(int panel_id);
static int lcd_kit_updt_fps_te_mode(int panel_id, unsigned int fps, bool is_need_delay);

static int lcd_kit_get_init_display_length()
{
	if (PUBLIC_INFO->product_type == NORMAL_TYPE)
		return 1;
	else
		return MAX_PANEL;
}

#if defined(CONFIG_DKMD_DPU_AOD)
extern uint32_t dpu_aod_get_panel_id(void);
#endif
int lcd_kit_get_active_panel_id(void)
{
	int panel_len = lcd_kit_get_init_display_length();
	int i;
	int panel_id;

	for (i = 0; i < panel_len; i++) {
		panel_id = init_order[i];
		if (lcd_kit_get_panel_on_state(panel_id))
			return panel_id;
	}
#if defined(CONFIG_DKMD_DPU_AOD)
	return dpu_aod_get_panel_id();
#else
	return PRIMARY_PANEL;
#endif
}

int lcd_kit_get_display_type(void)
{
	return PUBLIC_INFO->product_type;
}

struct lcd_kit_disp_info *lcd_kit_get_disp_info(int panel_id)
{
	return &g_lcd_kit_disp_info[panel_id];
}

struct dpu_panel_info *lcd_kit_get_dpu_pinfo(int panel_id)
{
	if (panel_id >= MAX_PANEL || panel_id < 0) {
		LCD_KIT_ERR("not support panel_id %d \n", panel_id);
		return NULL;
	}

	return &g_dpu_pinfo[panel_id];
}

struct lcd_kit_public_info *lcd_kit_get_public_info(void)
{
	return &g_lcd_kit_public_info;
}

struct lcd_kit_disp_lock *lcd_kit_get_disp_lock(int panel_id)
{
	return &g_lcd_kit_disp_lock[panel_id];
}

static int lcd_kit_set_fastboot(int panel_id)
{
	// lcd panel version
	if (disp_info->panel_version.support) {
		if (!lcd_kit_panel_version_init(panel_id))
			LCD_KIT_INFO("read panel version successful\n");
		else
			LCD_KIT_INFO("read panel version fail\n");
	}
	return LCD_KIT_OK;
}

static void lcd_kit_fps_handle_on(int panel_id)
{
	struct dpu_panel_info *pinfo = NULL;

	pinfo = lcd_kit_get_dpu_pinfo(panel_id);
	if (!pinfo) {
		LCD_KIT_ERR("pinfo is null\n");
		return;
	}
	if (!disp_info->fps.support) {
		LCD_KIT_DEBUG("not support fps\n");
		return;
	}
	if (pinfo->dfr_info.oled_info.oled_type == LTPS)
		lcd_kit_updt_fps(panel_id, disp_info->fps.current_fps);

	if (disp_info->updt_fps_te.support)
		lcd_kit_updt_fps_te_mode(panel_id, disp_info->fps.current_fps, true);
}

static void lcd_kit_hs_handle(int panel_id)
{
	/* record panel on time */
	lcd_kit_disp_on_record_time(panel_id);
	/* fps on handle */
	lcd_kit_fps_handle_on(panel_id);
#if defined(CONFIG_DKMD_DPU_AOD)
	/* if aod no panel off, clear lcd status */
	if (lcd_kit_get_power_status(panel_id))
		lcd_kit_clean_aod_panel_state(panel_id);
#endif
	check_panel_on_state();
}

static void lcd_kit_instruct_process(int panel_id, uint8_t *read_val, int cnt)
{
	int index;
	int level;
	/* 10 means gamma para transfor */
	level = (int)(((read_val[READ_REG_H_OFFSET] << BYTE_OFFSET) |
		read_val[READ_REG_L_OFFSET]) * disp_info->effect_protect.ratio / 10);
	disp_info->effect_protect.write_cmds.cmds[REG_EFFECT_L_OFFSET + REG_OFFSET].payload[1] =
		level & 0xFF;
	disp_info->effect_protect.write_cmds.cmds[REG_EFFECT_H_OFFSET + REG_OFFSET].payload[1] =
		(level >> BYTE_OFFSET) & 0xFF;

	for (index = 0; index < cnt; index++) {
		if (index != REG_EFFECT_H_OFFSET && index != REG_EFFECT_L_OFFSET)
			disp_info->effect_protect.write_cmds.cmds[index + REG_OFFSET].payload[1] =
				read_val[index];
	}
}

static void lcd_kit_get_effect_cmd(int panel_id)
{
	int ret = LCD_KIT_OK;
	uint8_t read_array[MAX_READ_SIZE] = {0};
	struct lcd_kit_adapt_ops *adapt_ops = NULL;

	adapt_ops = lcd_kit_get_adapt_ops();
	if (!adapt_ops) {
		LCD_KIT_ERR("can not register adapt_ops!\n");
		return;
	}
	/* get effect cmd */
	if (disp_info->effect_protect.support) {
		ret = adapt_ops->mipi_rx(panel_id, NULL, read_array, MAX_READ_SIZE - 1,
			&disp_info->effect_protect.read_cmds);
		lcd_kit_instruct_process(panel_id, read_array, MAX_READ_SIZE);
		for (int i = 0; i < MAX_READ_SIZE; i++)
			LCD_KIT_DEBUG("read_array[%d] = 0x%x\n", i, read_array[i]);
	}
}

static void lcd_kit_effect_protect(int panel_id)
{
	int ret = LCD_KIT_OK;
	struct lcd_kit_adapt_ops *adapt_ops = NULL;

	adapt_ops = lcd_kit_get_adapt_ops();
	if (!adapt_ops) {
		LCD_KIT_ERR("can not register adapt_ops!\n");
		return;
	}

	if (disp_info->effect_protect.write_cmds.cmds != NULL)
		ret = adapt_ops->mipi_tx(panel_id, NULL, &disp_info->effect_protect.write_cmds);
	if (ret)
		LCD_KIT_ERR("send effect cmd fail!\n");
}

static int lcd_kit_on(int panel_id)
{
	int ret = LCD_KIT_OK;

	LCD_KIT_INFO("fb%d, +!\n", panel_id);
	if (disp_info->lcd_power_seq == LCD_KIT_POWER_OFF)
		disp_info->lcd_power_seq = LCD_KIT_POWER_ON_SEQ;

	if (disp_info->lcd_power_seq == LCD_KIT_POWER_ON &&
		common_ops->panel_mipi_switch)
		disp_info->lcd_power_seq = LCD_KIT_POWER_DBL_ON_SEQ;

	switch (disp_info->lcd_power_seq) {
	case LCD_KIT_POWER_ON_SEQ:
		wait_power_off_done(panel_id);
		/* send power on */
		if (common_ops->panel_power_on)
			ret = common_ops->panel_power_on(panel_id, NULL);
		LCD_KIT_INFO("lcd_name is %s\n", disp_info->compatible);

		/* set next step */
		disp_info->lcd_power_seq = LCD_KIT_POWER_ON_LP_SEQ;
#ifdef CONFIG_POWER_DUBAI
		LOG_JANK_D(JLID_KERNEL_LCD_POWER_ON, "%s", "LCD_POWER_ON");
#endif
		break;
	case LCD_KIT_POWER_ON_LP_SEQ:
		/* send mipi command by low power */
		if (common_ops->panel_on_lp)
			ret = common_ops->panel_on_lp(panel_id, NULL);
		if (!lcd_kit_get_aod_panel_state(panel_id) && disp_info->effect_protect.support)
			lcd_kit_effect_protect(panel_id);
		/* set next step */
		disp_info->lcd_power_seq = LCD_KIT_POWER_ON_HS_SEQ;
		break;
	case LCD_KIT_POWER_ON_HS_SEQ:
		/* send mipi command by high speed */
		if (common_ops->panel_on_hs)
			ret = common_ops->panel_on_hs(panel_id, NULL);
		/* set next step */
		disp_info->lcd_power_seq = LCD_KIT_POWER_ON;
		lcd_kit_hs_handle(panel_id);
		break;
	case LCD_KIT_POWER_DBL_ON_SEQ:
		disp_info->lcd_power_seq = LCD_KIT_POWER_DBL_ON_LP_SEQ;
#ifdef CONFIG_POWER_DUBAI
		LOG_JANK_D(JLID_KERNEL_LCD_POWER_ON, "%s", "LCD_POWER_ON");
#endif
		ret = common_ops->panel_mipi_switch(panel_id, NULL);
		break;
	case LCD_KIT_POWER_DBL_ON_LP_SEQ:
		disp_info->lcd_power_seq = LCD_KIT_POWER_DBL_ON_HS_SEQ;
		break;
	case LCD_KIT_POWER_DBL_ON_HS_SEQ:
		disp_info->lcd_power_seq = LCD_KIT_POWER_ON;
		break;
	default:
		break;
	}

	// clean skip power off
	lcd_kit_set_skip_power_on_off(false);
	LCD_KIT_INFO("fb%d, -!\n", panel_id);
	return ret;
}

static void lcd_kit_hs_off_handle(int panel_id)
{
#if defined(CONFIG_DKMD_DPU_AOD)
	/* if aod no panel off, clear lcd status */
	if (lcd_kit_get_power_status(panel_id))
		lcd_kit_clean_aod_panel_state(panel_id);
#endif
}

static int lcd_kit_off(int panel_id)
{
	int ret = LCD_KIT_OK;

	LCD_KIT_INFO("fb%d, +!\n", panel_id);
	if (disp_info->lcd_power_seq == LCD_KIT_POWER_ON)
		disp_info->lcd_power_seq = LCD_KIT_POWER_OFF_HS_SEQ;

	switch (disp_info->lcd_power_seq) {
	case LCD_KIT_POWER_OFF_HS_SEQ:
		/* send mipi command by high speed */
		if (disp_info->effect_protect.first_off_flag) {
			lcd_kit_get_effect_cmd(panel_id);
			disp_info->effect_protect.first_off_flag = 0;
		}
		if (common_ops->panel_off_hs)
			ret = common_ops->panel_off_hs(panel_id, NULL);

		/* set next step */
		disp_info->lcd_power_seq = LCD_KIT_POWER_OFF_LP_SEQ;
#ifdef CONFIG_POWER_DUBAI
		LOG_JANK_D(JLID_KERNEL_LCD_POWER_OFF, "%s", "LCD_POWER_OFF");
#endif
		break;
	case LCD_KIT_POWER_OFF_LP_SEQ:
		/* send mipi command by low power */
		if (common_ops->panel_off_lp)
			ret = common_ops->panel_off_lp(panel_id, NULL);

		/* set next step */
		disp_info->lcd_power_seq = LCD_KIT_POWER_OFF_SEQ;
		break;
	case LCD_KIT_POWER_OFF_SEQ:
		lcd_kit_power_off_optimize_handle(panel_id);
		/* send mipi command by high speed */
		if (common_ops->panel_power_off)
			ret = common_ops->panel_power_off(panel_id, NULL);
		lcd_kit_hs_off_handle(panel_id);
		/* set next step */
		disp_info->lcd_power_seq = LCD_KIT_POWER_OFF;
		break;
	default:
		break;
	}

	LCD_KIT_INFO("fb%d, -!\n", panel_id);
	return ret;
}

#ifdef CONFIG_POWER_DUBAI
static void lcd_kit_set_dubai_backlight(int panel_id, unsigned int bl_level)
{
	if ((disp_info->jank_last_bl_level == 0) && (bl_level != 0)) {
		LOG_JANK_D(JLID_KERNEL_LCD_BACKLIGHT_ON, "LCD_BACKLIGHT_ON,%u", bl_level);
		disp_info->jank_last_bl_level = bl_level;
	} else if ((disp_info->jank_last_bl_level != 0) && (bl_level == 0)) {
		LOG_JANK_D(JLID_KERNEL_LCD_BACKLIGHT_OFF, "LCD_BACKLIGHT_OFF");
		disp_info->jank_last_bl_level = bl_level;
	}
}
#endif

static int lcd_kit_hbm_backlight_handle(int panel_id, unsigned int bl_level)
{
	int ret = LCD_KIT_OK;
	unsigned int hbm_level;
	unsigned int bl_max = common_info->backlight.bl_max;

	if (bl_level > common_info->hbm_backlight.normal_bl_max) {
		hbm_level = display_engine_get_hbm_bl(panel_id, bl_level);
		if (common_ops->enter_hbm && common_info->hbm_backlight.hbm_status == LCD_KIT_HBM_OFF)
			ret = common_ops->enter_hbm(panel_id, NULL);
		if (common_ops->set_hbm_backlight)
			ret = common_ops->set_hbm_backlight(panel_id, NULL, hbm_level);
	} else {
		if (common_ops->exit_hbm && common_info->hbm_backlight.hbm_status == LCD_KIT_HBM_ON)
			ret = common_ops->exit_hbm(panel_id, NULL);
		common_info->backlight.bl_max = common_info->hbm_backlight.normal_bl_max;
		ret = lcd_kit_mipi_set_backlight(panel_id, bl_level);
		common_info->backlight.bl_max = bl_max;
	}

	return ret;
}

static int lcd_kit_set_backlight(int panel_id, unsigned int bl_level)
{
	int ret = LCD_KIT_OK;

	if (!lcd_kit_get_panel_on_state(panel_id)) {
		LCD_KIT_ERR("panel is power off\n");
		return LCD_KIT_FAIL;
	}

	if (disp_info->quickly_sleep_out.support) {
		if (disp_info->quickly_sleep_out.panel_on_tag)
			lcd_kit_disp_on_check_delay(panel_id);
	}

	if (common_info->hbm_backlight.support)
		ret = lcd_kit_hbm_backlight_handle(panel_id, bl_level);
	else
		ret = lcd_kit_mipi_set_backlight(panel_id, bl_level);

#ifdef CONFIG_DFX_ZEROHUNG
	if (ret == LCD_KIT_OK)
		trace_hck_hung_wp_screen_setbl(bl_level);
#endif
#ifdef CONFIG_INPUTHUB_20
	save_light_to_sensorhub_panel_id(bl_level, bl_level, panel_id);
#endif
#ifdef CONFIG_POWER_DUBAI
	lcd_kit_set_dubai_backlight(panel_id, bl_level);
#endif
	LCD_KIT_INFO("backlight_level%d = %d\n", panel_id, bl_level);

	return ret;
}

static int lcd_kit_get_ddic_cmds(int panel_id,
	const struct disp_effect_params* effect_params, struct dsi_cmds *dsi_cmds)
{
	int i;
	struct disp_effect_item item;
	int bl_level;

	if (!effect_params || !dsi_cmds) {
		LCD_KIT_ERR("effect_params or dsi_cmds is null\n");
		return LCD_KIT_FAIL;
	}

	if (effect_params->effect_num > EFFECT_PARAMS_MAX_NUM) {
		LCD_KIT_ERR("effect num abnormal, %u\n", effect_params->effect_num);
		return LCD_KIT_FAIL;
	}

	LCD_KIT_INFO("effect_num is %u\n", effect_params->effect_num);

	for (i = 0; i < effect_params->effect_num; i++) {
		item =  effect_params->params[i];
		if (item.effect_type == DISP_EFFECT_WITH_BL) {
			bl_level = item.effect_values[0];
			lcd_kit_get_bl_cmds(panel_id, bl_level, dsi_cmds);
		}
	}

	return LCD_KIT_OK;
}

static int lcd_kit_trace_screen_bl(int panel_id, unsigned int bl_level)
{
#ifdef CONFIG_DFX_ZEROHUNG
	trace_hck_hung_wp_screen_setbl(bl_level);
#endif
#ifdef CONFIG_INPUTHUB_20
	save_light_to_sensorhub_panel_id(bl_level, bl_level, panel_id);
#endif
#ifdef CONFIG_POWER_DUBAI
	lcd_kit_set_dubai_backlight(panel_id, bl_level);
#endif
	LCD_KIT_INFO("backlight_level%d = %d\n", panel_id, bl_level);
	display_engine_brightness_update(bl_level);

	return LCD_KIT_OK;
}

static int lcd_kit_post_process(struct device *dev)
{
	/* create sysfs */
	LCD_KIT_INFO("post process begin\n");
	lcd_kit_sysfs_init(dev);

	LCD_KIT_INFO("post process end\n");
	return LCD_KIT_OK;
}

static int lcd_kit_esd_check(int panel_id)
{
	int ret = LCD_KIT_OK;
	unsigned int esd_support;

	if (!disp_info->esd_enable) {
		LCD_KIT_INFO("ESD disable\n");
		return ret;
	}

	if (runmode_is_factory())
		esd_support = common_info->esd.fac_esd_support;
	else
		esd_support = common_info->esd.support;

	if (esd_support && common_ops->esd_handle)
		ret = common_ops->esd_handle(panel_id, NULL);

	if (runmode_is_factory() && disp_info->check_mipi.support) {
		LCD_KIT_INFO("check mipi start\n");
		lcd_kit_check_mipi_error(panel_id);
	}

	return ret;
}

static int lcd_kit_set_display_region(int panel_id, struct dkmd_rect *dirty)
{
	int ret = LCD_KIT_OK;

	LCD_KIT_INFO("set display_region\n");
	if (common_ops->dirty_region_handle)
		ret = common_ops->dirty_region_handle(panel_id, NULL,
			(struct region_rect *)dirty);

	return ret;
}

static int lcd_kit_common_probe(int panel_id,
	struct device_node *np)
{
	struct dpu_panel_info *pinfo = NULL;

	pinfo = lcd_kit_get_dpu_pinfo(panel_id);
	if (!pinfo) {
		LCD_KIT_ERR("pinfo is null\n");
		return LCD_KIT_FAIL;
	}

	memset(pinfo, 0, sizeof(struct dpu_panel_info));
	pinfo->product_type = PUBLIC_INFO->product_type;
	/* common init */
	if (common_ops->common_init)
		common_ops->common_init(panel_id, np);

	/* utils init */
	lcd_kit_utils_init(panel_id, np, pinfo);
#ifdef LCD_FACTORY_MODE
	lcd_factory_init(panel_id, np);
#endif
#ifdef LCD_KIT_DEBUG_ENABLE
	/* debugfs init */
	lcd_kit_debug_init();
	lcd_kit_debugfs_init();
#endif
	lcd_kit_register_power_key_notify(panel_id);

	return LCD_KIT_OK;
}

static int lcd_kit_set_fps_scence(int panel_id, unsigned int current_fps)
{
	LCD_KIT_INFO("current_fps = %u\n", current_fps);
	disp_info->fps.current_fps = current_fps;
	common_info->fps_on.current_fps = disp_info->fps.current_fps;
	return LCD_KIT_OK;
}

#define FPS_144 144
#define FPS_120 120
#define FPS_90  90
#define FPS_60  60
#define FPS_45  45
#define FPS_40  40
#define FPS_30  30
#define FPS_24  24
#define FPS_20  20
#define FPS_18  18
#define FPS_15  15
#define FPS_10  10
#define FPS_1   1

struct ltps_fps_cmd_table {
	int val;
	struct lcd_kit_dsi_panel_cmds *cmds;
} ltps_fps_cmd_table;

static int fps_cmd_send(int panel_id, struct lcd_kit_dsi_panel_cmds *cmds)
{
	struct lcd_kit_adapt_ops *adapt_ops = NULL;
	adapt_ops = lcd_kit_get_adapt_ops();
	if (!adapt_ops) {
		LCD_KIT_ERR("can not get adapt_ops!\n");
		return LCD_KIT_FAIL;
	}
	if (!lcd_kit_get_panel_on_state(panel_id)) {
		LCD_KIT_ERR("panel is power off\n");
		return LCD_KIT_FAIL;
	}
	if (adapt_ops->mipi_tx_no_lock == NULL) {
		LCD_KIT_ERR("mipi_tx_no_lock is NULL\n");
		return LCD_KIT_FAIL;
	}

	return adapt_ops->mipi_tx_no_lock(panel_id, NULL, cmds);
}

static int lcd_kit_updt_fps(int panel_id, unsigned int fps)
{
	int ret = LCD_KIT_OK;
	int table_num;
	int i;
	struct ltps_fps_cmd_table fps_lock_cmd[] = {
		{ FPS_144, &disp_info->fps.fps_to_144_cmds },
		{ FPS_120, &disp_info->fps.fps_to_120_cmds },
		{ FPS_90, &disp_info->fps.fps_to_90_cmds },
		{ FPS_60, &disp_info->fps.fps_to_60_cmds },
	};

	LCD_KIT_INFO("fps = %u\n", fps);
	table_num = sizeof(fps_lock_cmd) / sizeof(fps_lock_cmd[0]);
	for (i = 0; i < table_num; i++) {
		if (fps == fps_lock_cmd[i].val)
			ret = fps_cmd_send(panel_id, fps_lock_cmd[i].cmds);
	}
	LCD_KIT_INFO("ret = %d\n", ret);
	if (ret == LCD_KIT_OK) {
		disp_info->fps.current_fps = fps;
		common_info->fps_on.current_fps = disp_info->fps.current_fps;
	}
	return ret;
}

static int te_config_cmd_send(int panel_id, struct lcd_kit_dsi_panel_cmds *cmds)
{
	struct lcd_kit_adapt_ops *adapt_ops = NULL;

	adapt_ops = lcd_kit_get_adapt_ops();
	if (!adapt_ops) {
		LCD_KIT_ERR("can not get adapt_ops!\n");
		return LCD_KIT_FAIL;
	}

	if (!lcd_kit_get_panel_on_state(panel_id)) {
		LCD_KIT_ERR("panel is power off\n");
		return LCD_KIT_FAIL;
	}

	if (adapt_ops->mipi_tx == NULL) {
		LCD_KIT_ERR("mipi_tx_no_lock is NULL\n");
		return LCD_KIT_FAIL;
	}

	return adapt_ops->mipi_tx(panel_id, NULL, cmds);
}

static int lcd_kit_updt_fps_te_mode(int panel_id, unsigned int fps, bool is_need_delay)
{
	int ret = LCD_KIT_OK;
	int table_num;
	int i;
	struct ltps_fps_cmd_table te_config_cmd[] = {
		{ FPS_60, &disp_info->updt_fps_te.fps_60_cmds },
		{ FPS_120, &disp_info->updt_fps_te.fps_120_cmds },
		{ FPS_144, &disp_info->updt_fps_te.fps_144_cmds },
	};

	if (!disp_info->updt_fps_te.support) {
		LCD_KIT_INFO("not support updt_fps_te\n");
		return ret;
	}

	table_num = ARRAY_SIZE(te_config_cmd);
	for (i = 0; i < table_num; i++) {
		if (fps == te_config_cmd[i].val)
			ret = te_config_cmd_send(panel_id, te_config_cmd[i].cmds);
	}

	if (is_need_delay && disp_info->updt_fps_te.cmds_delay)
		lcd_kit_delay(disp_info->updt_fps_te.cmds_delay, LCD_KIT_WAIT_MS, true);

	return ret;
}

static int lcd_kit_primary_set_fastboot(void)
{
	return lcd_kit_set_fastboot(PRIMARY_PANEL);
}

static int lcd_kit_primary_on(void)
{
	return lcd_kit_on(PRIMARY_PANEL);
}

static int lcd_kit_primary_off(void)
{
	return lcd_kit_off(PRIMARY_PANEL);
}

static int lcd_kit_primary_set_backlight(unsigned int bl_level)
{
	return lcd_kit_set_backlight(PRIMARY_PANEL, bl_level);
}

struct dpu_panel_info *lcd_kit_get_primary_dpu_pinfo(void)
{
	return lcd_kit_get_dpu_pinfo(PRIMARY_PANEL);
}

static int lcd_kit_primary_post_process(struct device *dev)
{
	return lcd_kit_post_process(dev);
}

static int lcd_kit_primary_dump_info(void)
{
	check_panel_on_state();
	return LCD_KIT_OK;
}

static int lcd_kit_set_primary_fps_scence(unsigned int current_fps)
{
	return lcd_kit_set_fps_scence(PRIMARY_PANEL, current_fps);
}

static int lcd_kit_primary_get_ddic_cmds(const struct disp_effect_params* effect_params,
	struct dsi_cmds *dsi_cmds)
{
	return lcd_kit_get_ddic_cmds(PRIMARY_PANEL, effect_params, dsi_cmds);
}

static int lcd_kit_primary_trace_screen_bl(unsigned int bl_level)
{
	return lcd_kit_trace_screen_bl(PRIMARY_PANEL, bl_level);
}

static int lcd_kit_primary_updt_fps(unsigned int fps)
{
	return lcd_kit_updt_fps(PRIMARY_PANEL, fps);
}

static int lcd_kit_primary_esd_check(void)
{
	return lcd_kit_esd_check(PRIMARY_PANEL);
}

static int lcd_kit_primary_set_display_region(struct dkmd_rect *dirty)
{
	return lcd_kit_set_display_region(PRIMARY_PANEL, dirty);
}
static int lcd_kit_primary_updt_fps_te_mode(unsigned int fps)
{
	return lcd_kit_updt_fps_te_mode(PRIMARY_PANEL, fps, false);
}

static struct dpu_panel_ops primary_dpu_panel_data = {
	.set_fastboot = lcd_kit_primary_set_fastboot,
	.on = lcd_kit_primary_on,
	.off = lcd_kit_primary_off,
	.esd_handle = lcd_kit_primary_esd_check,
	.set_backlight = lcd_kit_primary_set_backlight,
	.get_panel_info = lcd_kit_get_primary_dpu_pinfo,
	.disp_postprocess = lcd_kit_primary_post_process,
	.dump_exception_info = lcd_kit_primary_dump_info,
	.set_current_fps = lcd_kit_set_primary_fps_scence,
	.get_ddic_cmds = lcd_kit_primary_get_ddic_cmds,
	.trace_screen_bl = lcd_kit_primary_trace_screen_bl,
	.update_lcd_fps = lcd_kit_primary_updt_fps,
	.set_display_region = lcd_kit_primary_set_display_region,
	.update_fps_te_mode = lcd_kit_primary_updt_fps_te_mode,
};

static int lcd_kit_io_crtl(uint32_t cmd, uint64_t arg)
{
	int ret = 0;
	void __user *argp = (void __user *)(uintptr_t)arg;
	if (unlikely(!argp))
		return -1;
	switch (cmd) {
	case LCDKIT_IOCTL_DISPLAY_ENGINE_PARAM_GET:
		ret = display_engine_get_param(argp);
		break;
	case LCDKIT_IOCTL_DISPLAY_ENGINE_PARAM_SET:
		ret = display_engine_set_param(argp);
		break;
	default:
		LCD_KIT_ERR("unknow cmd %u\n", cmd);
		return -1;
	}
	return ret;
}

static struct product_display_ops product_io_ops = {
	.fb_ioctl = lcd_kit_io_crtl,
};

/* uefi dmd report */
static void lcd_kit_primary_probe_dmd_report(void)
{
	if (!lcd_dclient)
		return;

	if (PUBLIC_INFO->dvdd_avs_dmd && strlen(PUBLIC_INFO->dvdd_avs_dmd) > 0) {
		if (dsm_client_ocuppy(lcd_dclient))
			return;
		/* lcdHpmDmd */
		LCD_KIT_ERR("report dvdd_avs_dmd\n");
		dsm_client_record(lcd_dclient,
			"lcd dvdd_avs_dmd hpm invalid:%s\n",
			PUBLIC_INFO->dvdd_avs_dmd);
		dsm_client_notify(lcd_dclient, DSM_LCD_POWER_STATUS_ERROR_NO);
	}
}

static void lcd_kit_completion_init(int panel_id)
{
	init_completion(&disp_info->lcd_completion.tx_no_lock_done);
	disp_info->lcd_completion.is_in_tx_no_lock = false;
}

static int lcd_kit_primary_probe(struct platform_device *pdev)
{
	struct device_node *np = NULL;
	struct lcd_kit_ops *lcd_ops = NULL;
	int ret;

	np = pdev->dev.of_node;
	if (!np) {
		LCD_KIT_ERR("not find device node\n");
		return LCD_KIT_FAIL;
	}

	LCD_KIT_INFO("primary panel porbe+\n");
	lcd_kit_adapt_init();
	lcd_kit_completion_init(PRIMARY_PANEL);

	ret = lcd_kit_common_probe(PRIMARY_PANEL, np);
	if (ret) {
		LCD_KIT_ERR("primary panel common probe fail\n");
		return LCD_KIT_FAIL;
	}
	lcd_kit_power_init(PRIMARY_PANEL, pdev);
	/* register to dkmd */
	ret = register_panel(&primary_dpu_panel_data, PRIMARY_PANEL);
	if (ret) {
		LCD_KIT_ERR("dpu_add_driver failed!\n");
		goto err_device_put;
	}

	/* register product_io_ops to dkmd */
	ret = regitster_product_ops(&product_io_ops);
	if (ret) {
		LCD_KIT_ERR("regitster_product_ops failed!\n");
		goto err_device_put;
	}

#ifdef CONFIG_HUAWEI_DSM
	lcd_dclient = dkmd_get_dmd_client();
	lcd_kit_primary_probe_dmd_report();
#endif

	/* get sn code */
	lcd_ops = lcd_kit_get_ops();
	if (lcd_ops) {
		if (lcd_ops->get_sn_code) {
			ret = lcd_ops->get_sn_code(PRIMARY_PANEL);
			if (ret < 0)
				LCD_KIT_ERR("get sn code failed!\n");
		}
	}

	LCD_KIT_INFO("primary panel porbe-\n");
	return LCD_KIT_OK;
err_device_put:
	return -EPROBE_DEFER;
}

static int lcd_kit_secondary_set_fastboot(void)
{
	return lcd_kit_set_fastboot(SECONDARY_PANEL);
}

static int lcd_kit_secondary_on(void)
{
	return lcd_kit_on(SECONDARY_PANEL);
}

static int lcd_kit_secondary_off(void)
{
	return lcd_kit_off(SECONDARY_PANEL);
}

static int lcd_kit_secondary_set_backlight(unsigned int bl_level)
{
	return lcd_kit_set_backlight(SECONDARY_PANEL, bl_level);
}

struct dpu_panel_info *lcd_kit_get_secondary_dpu_pinfo(void)
{
	return lcd_kit_get_dpu_pinfo(SECONDARY_PANEL);
}

static int lcd_kit_secondary_get_ddic_cmds(const struct disp_effect_params* effect_params,
	struct dsi_cmds *dsi_cmds)
{
	return lcd_kit_get_ddic_cmds(SECONDARY_PANEL, effect_params, dsi_cmds);
}

static int lcd_kit_secondary_dump_info(void)
{
	check_panel_on_state();
	return LCD_KIT_OK;
}

static int lcd_kit_set_secondary_fps_scence(unsigned int current_fps)
{
	return lcd_kit_set_fps_scence(SECONDARY_PANEL, current_fps);
}

static int lcd_kit_secondary_trace_screen_bl(unsigned int bl_level)
{
	return lcd_kit_trace_screen_bl(SECONDARY_PANEL, bl_level);
}

static int lcd_kit_second_updt_fps(unsigned int fps)
{
	return lcd_kit_updt_fps(SECONDARY_PANEL, fps);
}

static int lcd_kit_secondary_esd_check(void)
{
	return lcd_kit_esd_check(SECONDARY_PANEL);
}

static int lcd_kit_secondary_set_display_region(struct dkmd_rect *dirty)
{
	return lcd_kit_set_display_region(SECONDARY_PANEL, dirty);
}

static struct dpu_panel_ops secondary_dpu_panel_data = {
	.set_fastboot = lcd_kit_secondary_set_fastboot,
	.on = lcd_kit_secondary_on,
	.off = lcd_kit_secondary_off,
	.esd_handle = lcd_kit_secondary_esd_check,
	.set_backlight = lcd_kit_secondary_set_backlight,
	.get_panel_info = lcd_kit_get_secondary_dpu_pinfo,
	.dump_exception_info = lcd_kit_secondary_dump_info,
	.set_current_fps = lcd_kit_set_secondary_fps_scence,
	.get_ddic_cmds = lcd_kit_secondary_get_ddic_cmds,
	.trace_screen_bl = lcd_kit_secondary_trace_screen_bl,
	.update_lcd_fps = lcd_kit_second_updt_fps,
	.set_display_region = lcd_kit_secondary_set_display_region,
};

static int lcd_kit_secondary_probe(struct platform_device *pdev)
{
	struct device_node *np = NULL;
	int ret;

	LCD_KIT_INFO("secondary panel porbe+");
	np = pdev->dev.of_node;
	if (!np) {
		LCD_KIT_ERR("not find device node\n");
		return LCD_KIT_FAIL;
	}

	ret = lcd_kit_common_probe(SECONDARY_PANEL, np);
	if (ret) {
		LCD_KIT_ERR("secondary panel common probe fail\n");
		return LCD_KIT_FAIL;
	}

	/* register to dkmd */
	ret = register_panel(&secondary_dpu_panel_data, SECONDARY_PANEL);
	if (ret) {
		LCD_KIT_ERR("dpu_add_driver failed!\n");
		goto err_device_put;
	}

	lcd_kit_register_power_off_optimize();
	lcd_kit_completion_init(SECONDARY_PANEL);
	// lcd panel version
	lcd_kit_panel_version_init(SECONDARY_PANEL);
	LCD_KIT_INFO("secondary panel porbe-");
	return LCD_KIT_OK;
err_device_put:
	return -EPROBE_DEFER;
}

// primary panel probe match table
static struct of_device_id lcd_kit_primary_match_table[] = {
	{
		.compatible = "auo_otm1901a_5p2_1080p_video",
		.data = NULL,
	},
	{},
};

// secondary panel probe match table
static struct of_device_id lcd_kit_secondary_match_table[] = {
	{
		.compatible = "lcd_ext_panel_default",
		.data = NULL,
	},
	{},
};

// panel platform driver
static struct platform_driver lcd_kit_panel_driver[MAX_PANEL] = {
	{
		.probe = lcd_kit_primary_probe,
		.remove = NULL,
		.suspend = NULL,
		.resume = NULL,
		.shutdown = NULL,
		.driver = {
			.name = "lcd_kit_mipi_panel",
			.of_match_table = lcd_kit_primary_match_table,
		},
	},
	{
		.probe = lcd_kit_secondary_probe,
		.remove = NULL,
		.suspend = NULL,
		.resume = NULL,
		.shutdown = NULL,
		.driver = {
			.name = "lcd_kit_sec_mipi_panel",
			.of_match_table = lcd_kit_secondary_match_table,
		},
	},
};

static int lcd_kit_get_comp(int panel_id, struct device_node *np, int index)
{
	unsigned int pinid = 0;
	int i;
	unsigned int gpio_value;
	int panel_length = sizeof(g_lcd_kit_panels) / sizeof(g_lcd_kit_panels[0]);
	struct lcd_kit_array_data lcd_ids;
	unsigned int poweric_det_support = 0;
	unsigned int poweric_gpio = POWERIC_DEFAULT_GPIO;

	if (index == 0)
		lcd_kit_parse_array_data(np, "gpio_id", &lcd_ids);
	else
		lcd_kit_parse_array_data(np, "sec_gpio_id", &lcd_ids);

	for (i = 0; i < lcd_ids.cnt; i++) {
		gpio_value = lcd_kit_get_pinid(lcd_ids.buf[i]);
		pinid |= (gpio_value << (2 * i));
	}

	if (index == 0) {
		/* ext idpin config */
		lcd_kit_parse_u32(np, "poweric_det_support", &poweric_det_support, 0);
		lcd_kit_parse_u32(np, "poweric_gpio_id", &poweric_gpio, 0);
	} else {
		/* ext idpin config */
		lcd_kit_parse_u32(np, "sec_poweric_det_support", &poweric_det_support, 0);
		lcd_kit_parse_u32(np, "sec_poweric_gpio_id", &poweric_gpio, 0);
	}
	pinid |= lcd_kit_get_ext_pinid(np, poweric_det_support, poweric_gpio);

	/* sec panel panid */
	pinid |= (0x40 * index);

	LCD_KIT_INFO("pinid = %u\n", pinid);
	for (i = 0; i < panel_length; i++) {
		if (g_lcd_kit_panels[i].product_id == disp_info->product_id &&
			g_lcd_kit_panels[i].pin_id == pinid) {
			LCD_KIT_INFO("lcd has matched panel table, panel_name is %s\n",
				g_lcd_kit_panels[i].panel_name);
			disp_info->compatible = (char *)g_lcd_kit_panels[i].panel_name;
			return LCD_KIT_OK;
		}
	}

	return LCD_KIT_FAIL;
}

static int lcd_kit_parse_comp(int panel_id, struct device_node *np, int index)
{
	unsigned int uefi_bypass;
	int ret;

	lcd_kit_parse_u32(np, "uefi_bypass", &uefi_bypass, 0);
	if (uefi_bypass) {
		ret = lcd_kit_get_comp(panel_id, np, index);
		if (ret) {
			LCD_KIT_ERR("get lcd compatible error\n");
			return ret;
		}
	} else {
		disp_info->compatible = (char *)of_get_property(np,
			disp_compatibles[index], NULL);
		if (!disp_info->compatible) {
			LCD_KIT_ERR("can not get lcd kit compatible\n");
			return LCD_KIT_FAIL;
		}
	}

	return LCD_KIT_OK;
}

static void lcd_kit_parse_public_info(struct device_node *np)
{
	/* parse product_type */
	lcd_kit_parse_u32(np, "product_type", &PUBLIC_INFO->product_type, 0);
	LCD_KIT_INFO("product_type = %d", PUBLIC_INFO->product_type);
	lcd_kit_parse_u32(np, "dvdd_avs_volt", &PUBLIC_INFO->dvdd_avs_volt, 0);
	LCD_KIT_INFO("dvdd_avs_volt = %d", PUBLIC_INFO->dvdd_avs_volt);
	lcd_kit_parse_string(np, "dvdd_avs_dmd", (const char **)&PUBLIC_INFO->dvdd_avs_dmd);
	if (PUBLIC_INFO->dvdd_avs_dmd)
		LCD_KIT_INFO("dvdd_avs_dmd = %s", PUBLIC_INFO->dvdd_avs_dmd);

	/* parse panel version */
	lcd_kit_parse_u32(np, "primary_panel_version",
		&PUBLIC_INFO->primary_panel_version, 0);
	lcd_kit_parse_u32(np, "secondary_panel_version",
		&PUBLIC_INFO->secondary_panel_version, 0);
}

static int __init lcd_kit_init(void)
{
	int ret = LCD_KIT_OK;
	int init_length, len, i;
	int panel_id;
	struct device_node *np = NULL;

	if (!lcd_kit_support()) {
		LCD_KIT_INFO("not lcd_kit driver and return\n");
		return ret;
	}

	np = of_find_compatible_node(NULL, NULL, DTS_COMP_LCD_KIT_PANEL_TYPE);
	if (!np) {
		LCD_KIT_ERR("NOT FOUND device node %s!\n", DTS_COMP_LCD_KIT_PANEL_TYPE);
		return LCD_KIT_FAIL;
	}

	lcd_kit_parse_public_info(np);
	init_length = lcd_kit_get_init_display_length();

	for (i = 0; i < init_length; i++) {
		panel_id = init_order[i];

		lcd_kit_parse_u32(np, "board_version", &disp_info->board_version, 0);
		LCD_KIT_INFO("board_version = %u", disp_info->board_version);
		lcd_kit_parse_u32(np, "product_id", &disp_info->product_id, 0);
		LCD_KIT_INFO("product_id = %u", disp_info->product_id);

		ret = lcd_kit_parse_comp(panel_id, np, i);
		if (ret) {
			LCD_KIT_ERR("get compatible is null and return\n");
			return ret;
		}

		LCD_KIT_INFO("disp_info->compatible = %s\n", disp_info->compatible);
		len = strlen(disp_info->compatible);

		memset((char *)lcd_kit_panel_driver[i].driver.of_match_table->compatible, 0, LCD_KIT_PANEL_COMP_LENGTH);

		strncpy((char *)lcd_kit_panel_driver[i].driver.of_match_table->compatible,
				disp_info->compatible, len > (LCD_KIT_PANEL_COMP_LENGTH - 1) ?
				(LCD_KIT_PANEL_COMP_LENGTH - 1) : len);

		/* register driver */
		ret = platform_driver_register(&lcd_kit_panel_driver[i]);
		if (ret) {
			LCD_KIT_ERR("driver register failed, error = %d!\n", ret);
			return ret;
		}

		LCD_KIT_INFO("%s platform driver register success\n", disp_info->compatible);
	}

	return LCD_KIT_OK;
}

module_init(lcd_kit_init);

/*
 * Forced power-off will cause display error,
 * so need to send 10 command
 * before the long press power off first
 */
static void power_off_work(struct work_struct *work)
{
	int panel_id = lcd_kit_get_active_panel_id();
	struct lcd_kit_adapt_ops *ops = NULL;
	int ret;

	(void *)work;
	if (!disp_info) {
		LCD_KIT_ERR("disp info null!\n");
		return;
	}
	if (disp_info->pwrkey_press.long_press_flag == false) {
		LCD_KIT_INFO("long press flag false!\n");
		return;
	}
	ops = lcd_kit_get_adapt_ops();
	if (!ops) {
		LCD_KIT_ERR("get adapt ops null!\n");
		return;
	}
	if (!lcd_kit_get_panel_on_state(panel_id)) {
		LCD_KIT_INFO("lcd is power off, stop send commands!\n");
		return;
	}
	LCD_KIT_INFO("long press, power off lcd!\n");
	if (disp_info->pwrkey_press.esd_status == PWR_OFF_NEED_DISABLE_ESD) {
		LCD_KIT_INFO("pwr key disabled esd!\n");
		disp_info->esd_enable = 0;
		disp_info->pwrkey_press.esd_status = PWR_OFF_DISABLED_ESD;
	}

	if (ops->mipi_tx) {
		ret = ops->mipi_tx(panel_id, NULL,
			&disp_info->pwrkey_press.cmds);
		LCD_KIT_DEBUG("ret is %d\n", ret);
	}
	if (disp_info->pwrkey_press.power_off_flag) {
		LCD_KIT_INFO("lcd need power off!\n");
		if (common_ops->panel_off_lp)
			common_ops->panel_off_lp(panel_id, NULL);
		if (common_ops->panel_power_off)
			common_ops->panel_power_off(panel_id, NULL);
	}
}

static int __init early_parse_restart_type_cmdline(char *arg)
{
	if (!arg) {
		LCD_KIT_ERR("arg is NULL\n");
		return 0;
	}
	if (strncmp(arg, "0", 1) == 0)
		g_restart_type = PRESS_POWER_ONLY;
	else if (strncmp(arg, "1", 1) == 0)
		g_restart_type = PRESS_POWER_VOL_DOWN;
	else if (strncmp(arg, "2", 1) == 0)
		g_restart_type = PRESS_POWER_VOL_UP;

	LCD_KIT_INFO("g_restart_type = %d\n", g_restart_type);
	return 0;
}
early_param(POWERKEY_RESTART_TYPE_PROP, early_parse_restart_type_cmdline);

static unsigned int get_power_off_timer_val(int panel_id)
{
	unsigned int ret_time;
	unsigned int press_time;
	unsigned int val;
	unsigned int addr;

	if (!disp_info)
		return LONG_PRESS_10S_LCD_TIMER_LEN;
	addr = disp_info->pwrkey_press.rst_addr;
	press_time = pmic_read_reg(addr);
	LCD_KIT_INFO("press_time %u!\n", press_time);
	val = press_time & LONG_PRESS_RST_CONFIG_BIT;
	switch (val) {
	case LONG_PRESS_RST_CONFIG1:
		if (disp_info->pwrkey_press.configtime1)
			ret_time = disp_info->pwrkey_press.configtime1;
		else
			ret_time = LONG_PRESS_8S_LCD_TIMER_LEN;
		break;
	case LONG_PRESS_RST_CONFIG2:
		if (disp_info->pwrkey_press.configtime2)
			ret_time = disp_info->pwrkey_press.configtime2;
		else
			ret_time = LONG_PRESS_10S_LCD_TIMER_LEN;
		break;
	case LONG_PRESS_RST_CONFIG3:
		if (disp_info->pwrkey_press.configtime3)
			ret_time = disp_info->pwrkey_press.configtime3;
		else
			ret_time = LONG_PRESS_30S_LCD_TIMER_LEN;
		break;
	case LONG_PRESS_RST_CONFIG4:
		if (disp_info->pwrkey_press.configtime4)
			ret_time = disp_info->pwrkey_press.configtime4;
		else
			ret_time = LONG_PRESS_60S_LCD_TIMER_LEN;
		break;
	default:
		ret_time = LONG_PRESS_60S_LCD_TIMER_LEN;
		break;
	}
	return ret_time;
}

static int pwrkey_press_event_notifier(struct notifier_block *pwrkey_event_nb,
	unsigned long event, void *data)
{
	struct notifier_block *p = NULL;
	void *pd = NULL;
	unsigned int time;
	p = pwrkey_event_nb;
	pd = data;
	int panel_id = lcd_kit_get_active_panel_id();

	if (!disp_info)
		return LCD_KIT_OK;
	if (disp_info->pwrkey_press.support == false) {
		LCD_KIT_INFO("not support this func!\n");
		return LCD_KIT_OK;
	}
	time = disp_info->pwrkey_press.timer_val;
	switch (event) {
	case PRESS_KEY_6S:
		disp_info->pwrkey_press.long_press_flag = true;
		schedule_delayed_work(&disp_info->pwrkey_press.pf_work,
			msecs_to_jiffies(time));
		break;
	case PRESS_KEY_UP:
		if (disp_info->pwrkey_press.long_press_flag == false)
			break;
		if (disp_info->pwrkey_press.esd_status == PWR_OFF_DISABLED_ESD) {
			disp_info->pwrkey_press.esd_status = PWR_OFF_NEED_DISABLE_ESD;
			disp_info->esd_enable = 1;
			LCD_KIT_INFO("pwr key enable esd!\n");
		}
		disp_info->pwrkey_press.long_press_flag = false;
		cancel_delayed_work_sync(&disp_info->pwrkey_press.pf_work);
		break;
	default:
		break;
	}
	return LCD_KIT_OK;
}

static int comb_key_press_event_notifier(struct notifier_block *pwrkey_event_nb,
	unsigned long event, void *data)
{
	struct notifier_block *p = NULL;
	void *pd = NULL;
	unsigned int time;
	p = pwrkey_event_nb;
	pd = data;
	int panel_id = lcd_kit_get_active_panel_id();

	if (!disp_info)
		return LCD_KIT_OK;
	if (disp_info->pwrkey_press.support == false) {
		LCD_KIT_INFO("not support this func!\n");
		return LCD_KIT_OK;
	}
	time = disp_info->pwrkey_press.timer_val + 6000; /* 6s */
	switch (event) {
	case COMB_KEY_PRESS_DOWN:
		disp_info->pwrkey_press.long_press_flag = true;
		schedule_delayed_work(&disp_info->pwrkey_press.pf_work,
			msecs_to_jiffies(time));
		break;
	case COMB_KEY_PRESS_RELEASE:
		if (disp_info->pwrkey_press.long_press_flag == false)
			break;
		if (disp_info->pwrkey_press.esd_status == PWR_OFF_DISABLED_ESD) {
			disp_info->pwrkey_press.esd_status = PWR_OFF_NEED_DISABLE_ESD;
			disp_info->esd_enable = 1;
			LCD_KIT_INFO("pwr key enable esd!\n");
		}
		disp_info->pwrkey_press.long_press_flag = false;
		cancel_delayed_work_sync(&disp_info->pwrkey_press.pf_work);
		break;
	default:
		break;
	}
	return LCD_KIT_OK;
}

static void lcd_kit_register_power_key_notify(int panel_id)
{
	int ret;
	struct delayed_work *p_work = NULL;
	static bool pwroff_config_flag = false;

	if (!disp_info)
		return;
	if (disp_info->pwrkey_press.support == false)
		return;

	p_work = &disp_info->pwrkey_press.pf_work;
	INIT_DELAYED_WORK(p_work, power_off_work);
	disp_info->pwrkey_press.timer_val = get_power_off_timer_val(panel_id);
	if (pwroff_config_flag) {
		LCD_KIT_ERR("power_key notifier has been registed!\n");
		return;
	}
	if (g_restart_type == PRESS_POWER_ONLY) {
		disp_info->pwrkey_press.nb.notifier_call = pwrkey_press_event_notifier;
		ret = powerkey_register_notifier(&disp_info->pwrkey_press.nb);
		if (ret < 0)
			LCD_KIT_ERR("register power_key notifier failed!\n");
	} else {
#ifdef CONFIG_POWERKEY_SPMI
#ifdef CONFIG_KEYBOARD_PMIC_VOLUME_KEY
		disp_info->pwrkey_press.nb.notifier_call = comb_key_press_event_notifier;
		ret = comb_key_register_notifier(&disp_info->pwrkey_press.nb);
		if (ret < 0)
			LCD_KIT_ERR("register comb_key notifier failed!\n");
#endif
#endif
	}
	pwroff_config_flag = true;
}

