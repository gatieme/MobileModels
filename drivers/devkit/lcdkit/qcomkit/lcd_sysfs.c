/*
 * lcd_sysfs.c
 *
 * lcd sysfs function for lcd driver
 *
 * Copyright (c) 2021-2022 Honor Technologies Co., Ltd.
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
#include <linux/kernel.h>
#include <linux/device.h>
#include "lcd_defs.h"
#include "lcd_panel.h"
#include "lcd_sysfs.h"
#include "sde_trace.h"
#include "lcd_kit_core.h"

/* panel enable od init */
char panel_enable_od_info[PANEL_ENABLE_OD_LEN] = {'\0'};
//EXPORT_SYMBOL(panel_enable_od_info);

/* oem info */
static int oem_info_type = INVALID_TYPE;
static int lcd_get_2d_barcode(struct panel_info *pinfo, char *oem_data, int len);
static int lcd_get_project_id(struct panel_info *pinfo, char *oem_data, int len);
static int lcd_get_barcode(struct panel_info *pinfo, char *oem_data, int len);

static struct oem_info_cmd oem_read_cmds[] = {
	{ PROJECT_ID_TYPE, lcd_get_project_id },
	{ BARCODE_2D_TYPE, lcd_get_2d_barcode },
	{ BARCODE_TYPE, lcd_get_barcode },
};

static int alpm_setting_result = 0;


int get_fb_index(struct device *dev)
{
    if (!dev) {
        LCD_ERR("dev is null\n");
        return 0;
    }

	return dev->id;
}

static int lcd_get_project_id(struct panel_info *pinfo, char *oem_data, int len)
{
	return 0;
}

static int lcd_get_2d_barcode(struct panel_info *pinfo, char *oem_data, int len)
{
	char read_value[OEM_INFO_SIZE_MAX] = {0};

	if (!pinfo->oeminfo.barcode_2d.support) {
		LCD_ERR("not support 2d barcode\n");
		return LCD_FAIL;
	}
	if (!pinfo->power_on) {
		LCD_ERR("panel is off\n");
		return LCD_FAIL;
	}

	oem_data[0] = BARCODE_2D_TYPE;
	oem_data[1] = BARCODE_BLOCK_NUM + pinfo->oeminfo.barcode_2d.offset;
	if (pinfo->oeminfo.barcode_2d.is_sn_read) {
		strncat(oem_data, pinfo->oeminfo.barcode_2d.barcode_data,
			strlen(pinfo->oeminfo.barcode_2d.barcode_data));
	} else {
		dsi_panel_receive_data(pinfo->panel,
			DSI_CMD_READ_OEMINFO, read_value, OEM_INFO_SIZE_MAX - 1);
		strncat(oem_data, read_value, strlen(read_value));
	}

	return LCD_OK;
}

static int lcd_get_barcode(struct panel_info *pinfo, char *oem_data, int len)
{
	if (!pinfo->oeminfo.barcode_2d.support) {
		LCD_ERR("not support 2d barcode\n");
		return LCD_FAIL;
	}
	oem_data[0] = BARCODE_2D_TYPE;
	oem_data[1] = BARCODE_BLOCK_NUM + pinfo->oeminfo.barcode_2d.offset;
	strncat(oem_data, pinfo->oeminfo.barcode_2d.barcode_data,
		strlen(pinfo->oeminfo.barcode_2d.barcode_data));
	return LCD_OK;
}

static ssize_t lcd_model_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	ssize_t ret = 0;
	struct panel_info *pinfo = NULL;

	pinfo = get_panel_info(get_fb_index(dev));
	if (!pinfo) {
		LCD_ERR("pinfo is null\n");
		return -EINVAL;
	}
	if (pinfo->lcd_model)
		ret = snprintf(buf, PAGE_SIZE, "%s\n", pinfo->lcd_model);
	return ret;
}

static ssize_t lcd_type_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	ssize_t ret;

	ret = snprintf(buf, PAGE_SIZE, "panel_index:%d\n", get_active_panel());
	return ret;
}

static ssize_t panel_info_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	ssize_t ret;
	char panel_type[10] = {0};
	struct panel_info *pinfo = NULL;
	struct dsi_panel *panel;

	pinfo = get_panel_info(get_fb_index(dev));
	if (!pinfo || !pinfo->panel) {
		LCD_ERR("null pointer\n");
		return -EINVAL;
	}
	panel = pinfo->panel;
	if (panel->panel_type == DSI_DISPLAY_PANEL_TYPE_LCD)
		strncpy(panel_type, "LCD", strlen("LCD"));
	else if (panel->panel_type == DSI_DISPLAY_PANEL_TYPE_OLED)
		strncpy(panel_type, "AMOLED", strlen("AMOLED"));
	else
		strncpy(panel_type, "INVALID", strlen("INVALID"));
	ret = snprintf(buf, PAGE_SIZE, "blmax:%u,blmin:%u,blmax_nit_actual:%d,blmax_nit_standard:%d,lcdtype:%s\n",
		panel->bl_config.bl_max_level, panel->bl_config.bl_min_level,
		panel->bl_config.bl_actual_max_nit, panel->bl_config.bl_max_nit,
		panel_type);
	return ret;
}

static ssize_t	lcd_voltage_enable_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	return count;
}

static ssize_t amoled_acl_ctrl_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	ssize_t ret = 0;

	return ret;
}

static ssize_t	amoled_acl_ctrl_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	return count;
}

static ssize_t amoled_vr_mode_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	ssize_t ret = 0;

	return ret;
}

static ssize_t	amoled_vr_mode_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	return count;
}

static ssize_t lcd_support_mode_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	ssize_t ret = 0;

	return ret;
}

static ssize_t	lcd_support_mode_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	return count;
}

static ssize_t	gamma_dynamic_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	return count;
}

static ssize_t frame_count_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	ssize_t ret = 0;

	return ret;
}

static ssize_t frame_update_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	ssize_t ret = 0;

	return ret;
}

static ssize_t	frame_update_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	return count;
}

static int lcd_low_fps_handle(struct dsi_panel *panel, u32 cur_fps)
{
	int ret = 0;

	if (cur_fps == FPS_90_SCENCE)
		ret = dsi_panel_set_cmd(panel, DSI_CMD_SET_120FPS);
	return ret;
}

static int lcd_60fps_handle(struct dsi_panel *panel, u32 cur_fps)
{
	int ret = 0;

	if (cur_fps == FPS_90_SCENCE)
		ret = dsi_panel_set_cmd(panel, DSI_CMD_SET_120FPS);
	else if (cur_fps < FPS_60_SCENCE)
		ret = dsi_panel_set_cmd(panel, DSI_CMD_SET_60FPS);
	return ret;
}

static int lcd_90fps_handle(struct dsi_panel *panel, u32 cur_fps)
{
	int ret = 0;

	if (cur_fps > FPS_90_SCENCE)
		ret = dsi_panel_set_cmd(panel, DSI_CMD_SET_90FPS);
	return ret;
}

static int lcd_120fps_handle(struct dsi_panel *panel, u32 cur_fps)
{
	int ret = 0;

	if (cur_fps == FPS_90_SCENCE)
		ret = dsi_panel_set_cmd(panel, DSI_CMD_SET_120FPS);
	return ret;
}

static void lcd_fps_setting(unsigned int mode, struct dsi_panel *panel)
{
	int ret;
	u32 cur_fps;
	char atrace_buf[32];
	unsigned int adj_fps;

	if (!panel->cur_mode)
		return;
	adj_fps = mode;
	cur_fps = panel->cur_mode->timing.refresh_rate;
	snprintf(atrace_buf, sizeof(atrace_buf),
		"displaySetFps:%d, cur_fps:%d", adj_fps, cur_fps);
	SDE_ATRACE_BEGIN(atrace_buf);
	switch (adj_fps) {
	case FPS_60_SET:
		ret = lcd_60fps_handle(panel, cur_fps);
		break;
	case FPS_90_SET:
		ret = lcd_90fps_handle(panel, cur_fps);
		break;
	case FPS_120_SET:
		ret = lcd_120fps_handle(panel, cur_fps);
		break;
	default:
		ret = lcd_low_fps_handle(panel, cur_fps);
		break;
	}
	if (ret)
		LCD_ERR("set mode: %d failed\n", adj_fps);
	SDE_ATRACE_END(atrace_buf);
}

static ssize_t lcd_fps_scence_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	int ret;
	char str[BUF_MAX] = {0};
	char tmp[10] = {0};
	int i;
	u32 fps;
	struct panel_info *pinfo = NULL;
	struct dsi_panel *panel = NULL;

	pinfo = get_panel_info(get_fb_index(dev));
	if (!pinfo || !pinfo->panel) {
		LCD_ERR("pinfo or panel is null\n");
		return -EINVAL;
	}
	panel = pinfo->panel;
	if (pinfo->fps_list_len && pinfo->fps_list) {
		if (!panel->cur_mode)
			ret = snprintf(str, sizeof(str), "current_fps:%d;default_fps:%d",
				pinfo->fps_list[0], pinfo->fps_list[0]);
		else
			ret = snprintf(str, sizeof(str), "current_fps:%d;default_fps:%d",
				panel->cur_mode->timing.refresh_rate, pinfo->fps_list[0]);
		strncat(str, ";support_fps_list:", strlen(";support_fps_list:"));
		for (i = 0; i < pinfo->fps_list_len; i++) {
			fps = pinfo->fps_list[i];
			if (i > 0)
				strncat(str, ",", strlen(","));
			ret += snprintf(tmp, sizeof(tmp), "%d", fps);
			strncat(str, tmp, strlen(tmp));
		}
		ret = snprintf(buf, PAGE_SIZE, "%s\n", str);
	} else {
		fps = 60;
		ret = snprintf(buf, sizeof(str), "current_fps:%d;default_fps:%d;support_fps_list:%d",
			fps, fps, fps);
	}
	if (panel->ltpo_feature)
		panel->hidl_pid = current->pid;
	LCD_INFO("%s\n", str);
	return ret;
}

static void lcd_fps_set_order(unsigned int mode, struct panel_info *pinfo)
{
	switch (mode) {
	case MMI_COLORBAR:
		pinfo->fps_order = MMI_COLOR_BAR;
		break;
	case MMI_DEFAULT:
	case MMI_RED:
	case MMI_GREEN:
	case MMI_BLUE:
	case MMI_L32:
	case MMI_L3:
	case MMI_WHITE:
	case MMI_L255:
	case MMI_HBM:
	case MMI_TP:
		pinfo->fps_order = MMI_OTHER;
		break;
	case FPS_IMAGE:
		pinfo->fps_order = RT_IMAGE;
		break;
	case FPS_VIDEO:
		pinfo->fps_order = RT_VIDEO;
		break;
	case MMI_L0:
		pinfo->fps_order = MMI_L0_P;
		break;
	default:
		LCD_ERR("not support fps:%d\n", mode);
		break;
	}
}

static ssize_t	lcd_fps_scence_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	ssize_t ret;
	unsigned int mode = 0;
	struct panel_info *pinfo = NULL;
	struct dsi_panel *panel = NULL;

	pinfo = get_panel_info(get_fb_index(dev));
	if (!pinfo) {
		LCD_ERR("pinfo is null\n");
		return -EINVAL;
	}

	panel = pinfo->panel;
	if (!panel) {
		LCD_ERR("panel is null\n");
		return -EINVAL;
	}

	ret = sscanf(buf, "%u", &mode);
	if (!ret) {
		LCD_ERR("sscanf return invaild:%d\n", ret);
		return -EINVAL;
	}
	LCD_INFO("set fps:%d\n", mode);

	mutex_lock(&panel->panel_lock);
	if (!panel->pdata->pinfo->power_on) {
		mutex_unlock(&panel->panel_lock);
		LCD_ERR("not power on\n");
		return count;
	}

	if (mode < FPS_MODE_MAX) {
		lcd_fps_setting(mode, panel);
		mutex_unlock(&panel->panel_lock);
		return count;
	}

	/* set fps test order */
	lcd_fps_set_order(mode, pinfo);
	mutex_unlock(&panel->panel_lock);
	return count;
}

static ssize_t dual_panel_display_setting_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct panel_info *pinfo = NULL;

	if (!buf) {
		LCD_ERR("NULL_PTR ERROR!\n");
		return -EINVAL;
	}

	pinfo = get_panel_info(get_fb_index(dev));
	if (!pinfo) {
		LCD_ERR("pinfo is null\n");
		return -EINVAL;
	}

	return (ssize_t)snprintf(buf, PAGE_SIZE, "%d\n", pinfo->dual_panel_display);
}

static int ts_power_notify_secondary(struct dsi_panel *panel,
		enum lcd_kit_ts_pm_type type, int sync)
{
	int ret = 0;
	struct ts_kit_ops *ts_ops = ts_kit_get_ops();

	if((panel->pdata->pinfo->panel_id != SECONDARY_PANEL)) {
		LCD_INFO("Don't notify TP, not secondary\n");
		return -1;
	}

	if (ts_ops && ts_ops->ts_multi_power_notify) {
		ret = ts_ops->ts_multi_power_notify(type, sync,
				panel->pdata->pinfo->panel_id);
	}

	return 0;
}

static ssize_t dual_panel_display_setting_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	struct panel_info *pinfo = NULL;
	struct dsi_panel *panel = NULL;
	char *after;
	int rc = 0;

	pinfo = get_panel_info(get_fb_index(dev));
	if (!pinfo) {
		LCD_ERR("pinfo is null\n");
		return -EINVAL;
	}

	panel = pinfo->panel;
	if (!panel) {
		LCD_ERR("panel is null\n");
		return -EINVAL;
	}

	pinfo->dual_panel_display = simple_strtoul(buf, &after, 10);
	LCD_INFO("dual_panel_display = %lu\n", pinfo->dual_panel_display);

	if (!pinfo->dual_panel_display) {
		rc = ts_power_notify_secondary(panel, TS_RESUME_DEVICE, NO_SYNC);
		if (rc) {
			LCD_ERR("TS_RESUME_DEVICE failed\n");
		}
	}

	if (pinfo->dual_panel_display != SINGLE_DISPLAY_MODE && pinfo->dual_panel_display != DUAL_DISPLAY_MODE) {
		LCD_ERR("set display mode fail!\n");
		return -EINVAL;
	}

	return count;
}

static ssize_t alpm_setting_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	if (!buf) {
		LCD_ERR("NULL_PTR ERROR!\n");
		return -EINVAL;
	}
	return (ssize_t)snprintf(buf, PAGE_SIZE, "%d\n", alpm_setting_result);
}

static ssize_t alpm_setting_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	ssize_t ret;
	unsigned int mode = 0;
	struct panel_info *pinfo = NULL;
	struct dsi_panel *panel = NULL;

	alpm_setting_result = -1;
	pinfo = get_panel_info(get_fb_index(dev));
	if (!pinfo) {
		LCD_ERR("pinfo is null\n");
		return -EINVAL;
	}

	panel = pinfo->panel;
	if (!panel) {
		LCD_ERR("panel is null\n");
		return -EINVAL;
	}

	ret = sscanf(buf, "%u", &mode);
	if (!ret) {
		LCD_ERR("sscanf return invaild:%d\n", ret);
		return -EINVAL;
	}
	LCD_INFO("alpm mode:%d\n", mode);
	LCD_INFO("power_mode:%d\n", panel->power_mode);

	if (mode == ALPM_LOW_LIGHT || mode == ALPM_MIDDLE_LIGHT || mode == ALPM_HIGH_LIGHT) {
		switch (mode) {
			case ALPM_LOW_LIGHT:
				pinfo->aod_mod = DSI_CMD_SET_ALPM_LOW_LIGHT;
				break;
			case ALPM_MIDDLE_LIGHT:
				pinfo->aod_mod = DSI_CMD_SET_ALPM_MIDDLE_LIGHT;
				break;
			case ALPM_HIGH_LIGHT:
				pinfo->aod_mod = DSI_CMD_SET_ALPM_HIGH_LIGHT;
				break;
			default:
				LCD_WARN("invalid parameter\n");
				break;
		}
	}

	mutex_lock(&panel->panel_lock);
	if (!panel->pdata->pinfo->power_on) {
		mutex_unlock(&panel->panel_lock);
		LCD_WARN("not power on\n");
		return count;
	}
	if (panel->power_mode != SDE_MODE_DPMS_LP1 &&
		panel->power_mode != SDE_MODE_DPMS_LP2 &&
		panel->aod_lk_bl != AOD_LK_BL) {
		mutex_unlock(&panel->panel_lock);
		LCD_WARN("not in alpm mode\n");
		return count;
	}
	switch (mode) {
	case ALPM_LOW_LIGHT:
		ret = dsi_panel_set_cmd(panel, DSI_CMD_SET_ALPM_LOW_LIGHT);
		break;
	case ALPM_MIDDLE_LIGHT:
		ret = dsi_panel_set_cmd(panel, DSI_CMD_SET_ALPM_MIDDLE_LIGHT);
		break;
	case ALPM_HIGH_LIGHT:
		ret = dsi_panel_set_cmd(panel, DSI_CMD_SET_ALPM_HIGH_LIGHT);
		break;
	case ALPM_LOCK_LIGHT:
		ret = dsi_panel_set_cmd(panel, DSI_CMD_SET_NOLP);
		break;
	case ALPM_UNLOCK_LIGHT:
		ret = dsi_panel_set_cmd(panel, DSI_CMD_SET_LP1);
		break;
	default:
		LCD_ERR("not support alpm mode:%d\n", mode);
		break;
	}
	alpm_setting_result = ret;
	mutex_unlock(&panel->panel_lock);
	return count;
}

static ssize_t lcd_func_switch_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	ssize_t ret = 0;

	return ret;
}

static ssize_t	lcd_func_switch_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	return count;
}

static ssize_t lcd_reg_read_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	ssize_t ret = 0;

	return ret;
}

static ssize_t lcd_reg_read_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	return count;
}

static ssize_t ddic_oem_info_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	int i;
	int j;
	int ret = -1;
	int length;
	int start = 0;
	char oem_info_data[OEM_INFO_SIZE_MAX] = {0};
	char str_oem[OEM_INFO_SIZE_MAX + 1] = {0};
	struct panel_info *pinfo = NULL;

	pinfo = get_panel_info(get_fb_index(dev));
	if (!pinfo) {
		LCD_ERR("pinfo is null\n");
		return -EINVAL;
	}

	if (!pinfo->oeminfo.support) {
		LCD_ERR("oem info is not support\n");
		return LCD_FAIL;
	}

	if (oem_info_type <= INVALID_TYPE || oem_info_type >= MAX_OEM_TYPE) {
		LCD_ERR("oem_info_type is invalid, write ddic_oem_info again, then read\n");
		return LCD_FAIL;
	}

	length = sizeof(oem_read_cmds) / sizeof(oem_read_cmds[0]);
	for (i = 0; i < length; i++) {
		if (oem_info_type == oem_read_cmds[i].type) {
			LCD_INFO("cmd = %d\n", oem_info_type);
			if (oem_read_cmds[i].func) {
				ret = (*oem_read_cmds[i].func)(pinfo, oem_info_data,
					OEM_INFO_SIZE_MAX);
				break;
			}
		}
	}
	if (ret) {
		LCD_ERR("oem read failed\n");
		return LCD_FAIL;
	}

	/* parse data */
	for (i = 0; i < oem_info_data[1]; i++) {
		for (j = 0; j < BARCODE_BLOCK_LEN; j++) {
			snprintf(str_oem + start, sizeof(str_oem) - start, "%d,",
				oem_info_data[i * BARCODE_BLOCK_LEN + j]);
			while (str_oem[start] != 0)
				++start;
		}
	}

	LCD_INFO("str_oem = %s\n", str_oem);
	ret = snprintf(buf, PAGE_SIZE, "%s\n", str_oem);
	return ret;
}

static ssize_t	ddic_oem_info_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	struct panel_info *pinfo = get_panel_info(get_fb_index(dev));

	if (!buf || !pinfo) {
		LCD_ERR("pointer is NULL\n");
		return -EINVAL;
	}

	if (!pinfo->oeminfo.support) {
		LCD_ERR("oem info is not support\n");
		return LCD_FAIL;
	}

	oem_info_type = (unsigned char)strtoul(buf, NULL, 0);
	LCD_INFO("write Type = %d\n", oem_info_type);
	return count;
}

static ssize_t effect_bl_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	ssize_t ret = 0;

	return ret;
}

static ssize_t	effect_bl_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	return count;
}

static int lcd_fps_get_scence(int fps)
{
	int ret_fps;

	switch (fps) {
	case FPS_60_SCENCE:
		ret_fps = FPS_60_INDEX;
		break;
	case FPS_90_SCENCE:
		ret_fps = FPS_90_INDEX;
		break;
	case FPS_120_SCENCE:
		ret_fps = FPS_120_INDEX;
		break;
	default:
		ret_fps = FPS_60_INDEX;
		break;
	}
	return ret_fps;
}

static ssize_t lcd_fps_order_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	int ret;
	char str[BUF_MAX] = {0};
	char tmp[10] = {0};
	int i;
	int fps_index;
	struct panel_info *pinfo = NULL;

	pinfo = get_panel_info(get_fb_index(dev));
	if (!pinfo || !pinfo->panel) {
		LCD_ERR("pinfo or panel is null\n");
		return -EINVAL;
	}
	if (pinfo->fps_list_len < 1 || !pinfo->fps_list) {
		ret = snprintf(buf, PAGE_SIZE, "0\n");
		return ret;
	}
	if (pinfo->fps_list_len <= 3) {
		ret = snprintf(str, sizeof(str), "1,%d,%d", 60,
			pinfo->fps_list_len);
		for (i = 0; i < pinfo->fps_list_len; i++) {
			fps_index = lcd_fps_get_scence(pinfo->fps_list[i]);
			if (i == 0)
				strncat(str, ",", strlen(","));
			else
				strncat(str, ";", strlen(";"));
			ret += snprintf(tmp, sizeof(tmp), "%d:%d", pinfo->fps_list[i], ORDER_DELAY);
			strncat(str, tmp, strlen(tmp));
		}
	} else {
		u32 orer_delay = 0;
		switch (pinfo->fps_order) {
			case MMI_COLOR_BAR:
				orer_delay = 200;
				ret = snprintf(str, sizeof(str), "1,%d,%d", 120,
					pinfo->fps_mmi_colorbar_len);
				for (i = 0; i < (pinfo->fps_mmi_colorbar_len); i++) {
					if (i == 0)
						strncat(str, ",", strlen(","));
					else
						strncat(str, ";", strlen(";"));
					ret += snprintf(tmp, sizeof(tmp), "%d:%d", pinfo->fps_list_mmi_colorbar[i], orer_delay);
					strncat(str, tmp, strlen(tmp));
				}
				break;
			case MMI_L0_P:
				ret = snprintf(str, sizeof(str), "1,120,2,120:1000;10:1000");
				break;
			case MMI_OTHER:
				orer_delay = 200;
				ret = snprintf(str, sizeof(str), "1,%d,%d", 120,
					pinfo->fps_mmi_other_len);
				for (i = 0; i < pinfo->fps_mmi_other_len; i++) {
					if (i == 0)
						strncat(str, ",", strlen(","));
					else
						strncat(str, ";", strlen(";"));
					ret += snprintf(tmp, sizeof(tmp), "%d:%d", pinfo->fps_list_mmi_other[i], orer_delay);
					strncat(str, tmp, strlen(tmp));
				}
				break;
			case RT_IMAGE:
				orer_delay = 6000;
				ret = snprintf(str, sizeof(str), "1,%d,%d", 120,
					pinfo->fps_rt_image_len);
				for (i = 0; i < pinfo->fps_rt_image_len; i++) {
					if (i == 0)
						strncat(str, ",", strlen(","));
					else
						strncat(str, ";", strlen(";"));
					ret += snprintf(tmp, sizeof(tmp), "%d:%d", pinfo->fps_list_rt_image[i], orer_delay);
					strncat(str, tmp, strlen(tmp));
				}
				break;
			case RT_VIDEO:
				orer_delay = 6000;
				ret = snprintf(str, sizeof(str), "1,%d,%d", 120,
					pinfo->fps_rt_video_len);
				for (i = 0; i < pinfo->fps_rt_video_len; i++) {
					if (i == 0)
						strncat(str, ",", strlen(","));
					else
						strncat(str, ";", strlen(";"));
					ret += snprintf(tmp, sizeof(tmp), "%d:%d", pinfo->fps_list_rt_video[i], orer_delay);
					strncat(str, tmp, strlen(tmp));
				}
				break;
		}
	}
	LCD_INFO("%s\n", str);
	ret = snprintf(buf, PAGE_SIZE, "%s\n", str);
	return ret;
}

static ssize_t panel_sncode_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	int i;
	ssize_t ret;
	char str_tmp[OEM_INFO_SIZE_MAX] = {0};
	char str_oem[OEM_INFO_SIZE_MAX] = {0};
	struct panel_info *pinfo = NULL;

	pinfo = get_panel_info(get_fb_index(dev));
	if (!pinfo || !buf) {
		LCD_ERR("point is null\n");
		return -EINVAL;
	}

	if (!pinfo->oeminfo.sn_data.support) {
		LCD_ERR("not support sn data\n");
		return LCD_FAIL;
	}
	for(i = 0; i < sizeof(pinfo->oeminfo.sn_data.sn_code); i++) {
		memset(str_tmp, 0, sizeof(str_tmp));
		ret = snprintf(str_tmp, sizeof(str_tmp), "%d,",
				pinfo->oeminfo.sn_data.sn_code[i]);
		if (ret < 0) {
			LCD_ERR("snprintf fail\n");
			return LCD_FAIL;
		}
		strncat(str_oem, str_tmp, strlen(str_tmp));
	}
	ret = snprintf(buf, PAGE_SIZE, "%s\n", str_oem);
	if (ret < 0) {
		LCD_ERR("snprintf fail\n");
		return LCD_FAIL;
	}
	LCD_INFO("%s\n", buf);
	return ret;
}

static ssize_t brightness_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	ssize_t ret;
	struct panel_info *pinfo = NULL;
	pinfo = get_panel_info(get_fb_index(dev));
	if (!pinfo || !buf) {
		LCD_ERR("point is null\n");
		return -EINVAL;
	}

	ret = snprintf(buf, PAGE_SIZE, "%d\n", pinfo->brightness);
	if (ret < 0) {
		LCD_ERR("snprintf fail\n");
		return LCD_FAIL;
	}

	return ret;
}

static ssize_t is_sn_read_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	ssize_t ret;
	struct panel_info *pinfo = NULL;

	pinfo = get_panel_info(get_fb_index(dev));
	if (!pinfo || !buf) {
		LCD_ERR("point is null\n");
		return -EINVAL;
	}

	ret = snprintf(buf, PAGE_SIZE, "%d\n", pinfo->oeminfo.barcode_2d.is_sn_read);
	if (ret < 0) {
		LCD_ERR("snprintf fail\n");
		return LCD_FAIL;
	}
	return ret;
}

static ssize_t panel_enable_od_init_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	int ret;

	if (!strcmp(panel_enable_od_info, "na"))
		ret = snprintf(buf, PAGE_SIZE, "%s\n", "");
	else
		ret = snprintf(buf, PAGE_SIZE, "%s\n", panel_enable_od_info);
	LCD_INFO("panel_enable_od_info:%s\n", panel_enable_od_info);
	return ret;
}

static DEVICE_ATTR(lcd_model, 0644, lcd_model_show, NULL);
static DEVICE_ATTR(lcd_display_type, 0644, lcd_type_show, NULL);
static DEVICE_ATTR(panel_info, 0644, panel_info_show, NULL);
static DEVICE_ATTR(lcd_voltage_enable, 0200, NULL,
	lcd_voltage_enable_store);
static DEVICE_ATTR(amoled_acl, 0644, amoled_acl_ctrl_show,
	amoled_acl_ctrl_store);
static DEVICE_ATTR(amoled_vr_mode, 0644, amoled_vr_mode_show,
	amoled_vr_mode_store);
static DEVICE_ATTR(lcd_support_mode, 0644, lcd_support_mode_show,
	lcd_support_mode_store);
static DEVICE_ATTR(gamma_dynamic, 0644, NULL, gamma_dynamic_store);
static DEVICE_ATTR(frame_count, 0444, frame_count_show, NULL);
static DEVICE_ATTR(frame_update, 0644, frame_update_show,
	frame_update_store);
static DEVICE_ATTR(lcd_fps_scence, 0644, lcd_fps_scence_show,
	lcd_fps_scence_store);
static DEVICE_ATTR(dual_panel_display, 0644, dual_panel_display_setting_show, dual_panel_display_setting_store);
static DEVICE_ATTR(alpm_setting, 0644, alpm_setting_show,
	alpm_setting_store);
static DEVICE_ATTR(lcd_func_switch, 0644, lcd_func_switch_show,
	lcd_func_switch_store);
static DEVICE_ATTR(lcd_reg_read, 0600, lcd_reg_read_show,
	lcd_reg_read_store);
static DEVICE_ATTR(ddic_oem_info, 0644, ddic_oem_info_show,
	ddic_oem_info_store);
static DEVICE_ATTR(effect_bl, 0644, effect_bl_show,
	effect_bl_store);
static DEVICE_ATTR(lcd_fps_order, 0644, lcd_fps_order_show,
	NULL);
static DEVICE_ATTR(panel_sncode, 0644, panel_sncode_show, NULL);

static DEVICE_ATTR(brightness, 0644, brightness_show, NULL);

static DEVICE_ATTR(is_sn_read, 0644, is_sn_read_show, NULL);

static DEVICE_ATTR(panel_enable_od_init, 0644, panel_enable_od_init_show,
	NULL);

struct attribute *lcd_sysfs_attrs[] = {
	&dev_attr_lcd_model.attr,
	&dev_attr_lcd_display_type.attr,
	&dev_attr_panel_info.attr,
	&dev_attr_lcd_voltage_enable.attr,
	&dev_attr_amoled_acl.attr,
	&dev_attr_amoled_vr_mode.attr,
	&dev_attr_lcd_support_mode.attr,
	&dev_attr_gamma_dynamic.attr,
	&dev_attr_frame_count.attr,
	&dev_attr_frame_update.attr,
	&dev_attr_lcd_fps_scence.attr,
	&dev_attr_dual_panel_display.attr,
	&dev_attr_alpm_setting.attr,
	&dev_attr_lcd_func_switch.attr,
	&dev_attr_lcd_reg_read.attr,
	&dev_attr_ddic_oem_info.attr,
	&dev_attr_effect_bl.attr,
	&dev_attr_lcd_fps_order.attr,
	&dev_attr_panel_sncode.attr,
	&dev_attr_brightness.attr,
	&dev_attr_is_sn_read.attr,
	&dev_attr_panel_enable_od_init.attr,
	NULL,
};

struct attribute_group lcd_sysfs_attr_group = {
	.attrs = lcd_sysfs_attrs,
};

int lcd_create_sysfs(struct kobject *obj)
{
	int rc;

	rc = sysfs_create_group(obj, &lcd_sysfs_attr_group);
	if (rc) {
		LCD_ERR("sysfs group creation failed, rc=%d\n", rc);
		return rc;
	}
#ifdef CONFIG_LCD_FACTORY
	rc = lcd_create_fact_sysfs(obj);
	if (rc) {
		LCD_ERR("factory sysfs group creation failed, rc=%d\n", rc);
		return rc;
	}
#endif
	return rc;
}

module_param_string(panel_enable_od_init, panel_enable_od_info, PANEL_ENABLE_OD_LEN, 0600);
MODULE_PARM_DESC(panel_enable_od_init, "OD cmdlineinfo");

