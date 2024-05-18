/*
 * lcd_panel.c
 *
 * lcd panel function for lcd driver
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
#include "lcd_defs.h"
#include "lcd_sysfs.h"
#include "lcd_kit_core.h"
#ifdef CONFIG_APP_INFO
#include <misc/app_info.h>
#endif
#include <log/log_jank.h>
#include "lcd_panel.h"

#include <linux/input/qpnp-power-on.h>
#include <linux/export.h>
#include <linux/notifier.h>
#include "lcd_defs.h"
#include "lcd_notifier.h"
#include "sde/sde_connector.h"

#if defined(CONFIG_PXLW_IRIS)
#include "../dsi/iris/dsi_iris5_api.h"
#endif

#if IS_ENABLED(CONFIG_DSM)
#include <log/hiview_hievent.h>

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

#define DEFAULT_PANEL_NAME  "Default dsi panel"
#define FB_SYSFS_PATH "/sys/class/graphics"

#define BACKLIGHT_REG 0x52
#define BACKLIGHT_REG_COUNT 2

static struct lcd_kit_ops lcd_ops = {
	.get_status_by_type = panel_get_status_by_type,
};

extern struct ud_fp_lcd_ops* ud_fp_lcd_get_ops(void);
struct ud_fp_lcd_ops {
	void (*ud_fp_on_hbm_completed)(void);
};
void lcdkit_fp_hbm_on(void);

/* panel information */
static struct panel_info *g_panel_info[FB_MAX];
/* current registered fb num */
static int registered_fb_num;
/* notify fp hbm completed */
extern void ud_fp_on_hbm_completed(void);
/* global fb class */
struct class *fb_class = NULL;
/* active panel */
static unsigned int active_panel;

static int read_2d_barcode(struct dsi_panel *panel, bool is_panel_locked);

struct panel_info *get_panel_info(int idx)
{
	if (idx >= FB_MAX) {
		LCD_ERR("idx exceed max fb number\n");
		return NULL;
	}
	return g_panel_info[idx];
}

bool is_dual_panel(void)
{
	bool dual_panel = false;

	if (registered_fb_num > SECONDARY_PANEL)
		dual_panel = true;
	else
		dual_panel = false;
	return dual_panel;
}

int get_active_panel(void)
{
	if ((active_panel & BIT(PRIMARY_PANEL)) &&
		!(active_panel & BIT(SECONDARY_PANEL)))
		return PRIMARY_PANEL;
	if ((active_panel & BIT(SECONDARY_PANEL)) &&
		!(active_panel & BIT(PRIMARY_PANEL)))
		return SECONDARY_PANEL;
	if ((active_panel & BIT(PRIMARY_PANEL)) &&
		(active_panel & BIT(SECONDARY_PANEL)))
		return ALL_PANEL_ACTIVE;
	return NOT_PANEL_ACTIVE;
}

#if IS_ENABLED(CONFIG_DSM)
int lcd_dsm_client_record(struct dsm_client *lcd_dclient, const char *record_buf,
	int lcd_dsm_error_no)
{
	if (!lcd_dclient || !record_buf) {
		LCD_ERR("null pointer!\n");
		return LCD_FAIL;
	}


	if (!dsm_client_ocuppy(lcd_dclient)) {
		dsm_client_record(lcd_dclient, record_buf);
		dsm_client_notify(lcd_dclient, lcd_dsm_error_no);
		return LCD_OK;
	}
	LCD_ERR("dsm_client_ocuppy failed!\n");
	return LCD_FAIL;
}
#endif

static void panel_parse_oem_info(struct dsi_panel *panel, struct panel_info *pinfo)
{
	struct dsi_parser_utils *utils = &panel->utils;

	/* parse oeminfo */
	pinfo->oeminfo.support = utils->read_bool(utils->data,
			"qcom,mdss-dsi-panel-oem-info-enabled");
	if (!pinfo->oeminfo.support) {
		LCD_INFO("not support oem info\n");
		return;
	}

	pinfo->super_wallpaper = utils->read_bool(utils->data,
			"qcom,surport-super-wallpaper-enabled");

	pinfo->oeminfo.barcode_2d.support = utils->read_bool(utils->data,
			"qcom,mdss-dsi-panel-oem-2d-barcode-enabled");
	if (pinfo->oeminfo.barcode_2d.support) {
		if (utils->read_u32(utils->data, "qcom,mdss-dsi-panel-oem-2d-barcode-offset",
				&pinfo->oeminfo.barcode_2d.offset))
			DSI_ERR("failed to read: qcom,mdss-dsi-panel-oem-2d-barcode-offset\n");
	}
	pinfo->oeminfo.sn_data.support = utils->read_bool(utils->data,
			"qcom,mdss-dsi-panel-oem-sn-enabled");
}

static void panel_parse_gamma_info(struct dsi_panel *panel, struct panel_info *pinfo)
{
	struct dsi_parser_utils *utils = &panel->utils;

	/* parse gammainfo */
	pinfo->lcd_panel_gamma_info.support = utils->read_bool(utils->data,
			"qcom,mdss-dsi-panel-gamma-info-enabled");
	if (!pinfo->lcd_panel_gamma_info.support) {
		LCD_INFO("not support gamma info\n");
		return;
	}
}

static void panel_parse_mipi_error_info(struct dsi_panel *panel, struct panel_info *pinfo)
{
	int i = 0;
	int val = 0;
	struct dsi_parser_utils *utils = &panel->utils;

	pinfo->mipi_error.support = utils->read_bool(utils->data,
			"qcom,mdss-dsi-panel-lcd-mipi-error-check-support");
	if (!pinfo->mipi_error.support) {
		LCD_INFO("not support mipi error check\n");
		return;
	}

	pinfo->mipi_error.expect_count = of_property_count_u32_elems(utils->data,
                        "qcom,mdss-dsi-panel-lcd-mipi-error-check-expect_vals");

	pinfo->mipi_error.expect_val = kcalloc(pinfo->mipi_error.expect_count,
			sizeof(int), GFP_KERNEL);
	for (i = 0; i < pinfo->mipi_error.expect_count; i++) {
		of_property_read_u32_index(utils->data,
			"qcom,mdss-dsi-panel-lcd-mipi-error-check-expect_vals", i, &val);
		pinfo->mipi_error.expect_val[i] = val;
	}
}

static void panel_parse_fps(struct panel_info *pinfo,
	struct dsi_parser_utils *utils)
{
	int rc;

	pinfo->fps_list_len = utils->count_u32_elems(utils->data,
				  "qcom,dsi-fps-list");
	if (pinfo->fps_list_len < 1) {
		LCD_ERR("fps list not present\n");
		return;
	}
	pinfo->fps_mmi_colorbar_len = utils->count_u32_elems(utils->data,
				  "qcom,dsi-fps-list-mmi-color-bar");
	if (pinfo->fps_mmi_colorbar_len < 1) {
		LCD_ERR("fps_mmi_colorbar_len not present\n");
		return;
	}
	pinfo->fps_mmi_other_len = utils->count_u32_elems(utils->data,
				  "qcom,dsi-fps-list-mmi-other");
	if (pinfo->fps_mmi_other_len < 1) {
		LCD_ERR("fps_mmi_other_len not present\n");
		return;
	}
	pinfo->fps_rt_image_len = utils->count_u32_elems(utils->data,
				  "qcom,dsi-fps-list-rt-image");
	if (pinfo->fps_rt_image_len < 1) {
		LCD_ERR("fps_rt_image_len not present\n");
		return;
	}
	pinfo->fps_rt_video_len = utils->count_u32_elems(utils->data,
				  "qcom,dsi-fps-list-rt-video");
	if (pinfo->fps_rt_video_len < 1) {
		LCD_ERR("fps_rt_video_len not present\n");
		return;
	}

	pinfo->fps_list = kcalloc(pinfo->fps_list_len, sizeof(u32),
			GFP_KERNEL);
	pinfo->fps_list_mmi_colorbar = kcalloc(pinfo->fps_mmi_colorbar_len, sizeof(u32),
			GFP_KERNEL);
	pinfo->fps_list_mmi_other = kcalloc(pinfo->fps_mmi_other_len, sizeof(u32),
			GFP_KERNEL);
	pinfo->fps_list_rt_image = kcalloc(pinfo->fps_rt_image_len, sizeof(u32),
			GFP_KERNEL);
	pinfo->fps_list_rt_video = kcalloc(pinfo->fps_rt_video_len, sizeof(u32),
			GFP_KERNEL);
	if (!pinfo->fps_list)
		return;

	rc = utils->read_u32_array(utils->data,
			"qcom,dsi-fps-list",
			pinfo->fps_list,
			pinfo->fps_list_len);
	if (rc) {
		LCD_ERR("fps rate list parse failed\n");
		kfree(pinfo->fps_list);
		pinfo->fps_list = NULL;
	}
	rc = utils->read_u32_array(utils->data,
			"qcom,dsi-fps-list-mmi-color-bar",
			pinfo->fps_list_mmi_colorbar,
			pinfo->fps_mmi_colorbar_len);
	if (rc) {
		LCD_ERR("fps_list_mmi_colorbar parse failed\n");
		kfree(pinfo->fps_list_mmi_colorbar);
		pinfo->fps_list_mmi_colorbar = NULL;
	}
	rc = utils->read_u32_array(utils->data,
			"qcom,dsi-fps-list-mmi-other",
			pinfo->fps_list_mmi_other,
			pinfo->fps_mmi_other_len);
	if (rc) {
		LCD_ERR("fps_list_mmi_other parse failed\n");
		kfree(pinfo->fps_list_mmi_other);
		pinfo->fps_list_mmi_other = NULL;
	}
	rc = utils->read_u32_array(utils->data,
			"qcom,dsi-fps-list-rt-image",
			pinfo->fps_list_rt_image,
			pinfo->fps_rt_image_len);
	if (rc) {
		LCD_ERR("fps_list_rt_image parse failed\n");
		kfree(pinfo->fps_list_rt_image);
		pinfo->fps_list_rt_image = NULL;
	}
	rc = utils->read_u32_array(utils->data,
			"qcom,dsi-fps-list-rt-video",
			pinfo->fps_list_rt_video,
			pinfo->fps_rt_video_len);
	if (rc) {
		LCD_ERR("fps_list_rt_video parse failed\n");
		kfree(pinfo->fps_list_rt_video);
		pinfo->fps_list_rt_video = NULL;
	}
}

static void panel_parse_adjust_backlight_info(struct panel_info *pinfo,
	struct dsi_parser_utils *utils)
{
	uint32_t val = 0;
	int ret;

	pinfo->adjust_backlight_enabled = utils->read_bool(utils->data,
		"qcom,mdss-dsi-panel-adjust-backlight-enabled");
	if (!pinfo->adjust_backlight_enabled)
		return;

	ret = of_property_read_u32(utils->data,
		"qcom,mdss-dsi-panel-low-backlight-high-bound", &val);
	if (ret) {
		LCD_ERR("Invalid qcom,mdss-dsi-panel-low-backlight-high-bound\n");
		return;
	}
	pinfo->low_backlight_high_bound = val;
	ret = of_property_read_u32(utils->data,
		"qcom,mdss-dsi-panel-low-backlight-low-bound", &val);
	if (ret) {
		LCD_ERR("Invalid qcom,mdss-dsi-panel-low-backlight-low-bound\n");
		return;
	}
	pinfo->low_backlight_low_bound = val;
	ret = of_property_read_u32(utils->data,
		"qcom,mdss-dsi-panel-high-backlight-high-bound", &val);
	if (ret) {
		LCD_ERR("Invalid qcom,mdss-dsi-panel-high-backlight-high-bound\n");
		return;
	}
	pinfo->high_backlight_high_bound = val;
}

static void panel_parse_batch_info(struct panel_info *pinfo,
			struct dsi_parser_utils *utils)
{
	int rc;
	int i;

	pinfo->lcd_panel_batch_info.support = utils->read_bool(utils->data,
					"qcom,mdss-dsi-panel-read-batch-info-enabled");
	if (!pinfo->lcd_panel_batch_info.support ) {
		LCD_ERR("not support read panel batch info!\n");
		return;
	}
	pinfo->lcd_panel_batch_info.batch_match_hbm = utils->read_bool(utils->data,
					"qcom,mdss-dsi-panel-batch-match-hbm-enabled");
	if (!pinfo->lcd_panel_batch_info.support ) {
		LCD_INFO("not support panel batch match hbm!\n");
		return;
	}
	pinfo->lcd_panel_batch_info.cnt = of_property_count_u32_elems(utils->data,
			"qcom,mdss-dsi-panel-batch-value");

	pinfo->lcd_panel_batch_info.expect_val = kcalloc(pinfo->lcd_panel_batch_info.cnt,
			sizeof(int), GFP_KERNEL);

	if (!pinfo->lcd_panel_batch_info.expect_val) {
		LCD_ERR("kzalloc expect info fail\n");
		return;
	}

	for (i = 0; i < pinfo->lcd_panel_batch_info.cnt; i++) {
		of_property_read_u32_index(utils->data,
		"qcom,mdss-dsi-panel-batch-value", i, &rc);
		pinfo->lcd_panel_batch_info.expect_val[i] = rc;
		LCD_INFO("%d dts otp value is %d\n",i,rc);
	}
}

static void panel_parse_dsc_pps(struct dsi_panel *panel,
	struct panel_info *pinfo)
{
	int rc = 0;
	struct dsi_parser_utils *utils = &panel->utils;

	rc = utils->read_u32(utils->data, "qcom,mdss-dsi-cust-dsc-pps-type",
		&pinfo->cust_dsc_pps_type);
	if (rc) {
		pinfo->cust_dsc_pps_type = DSC_PPS_DEF;
		return;
	}
	LCD_INFO("use cust dsc pps, type = %d\n", pinfo->cust_dsc_pps_type);
}

static void panel_parse_force_poweroff_info(struct panel_info *pinfo,
			struct dsi_parser_utils *utils)
{
	pinfo->pwrkey_press.support = utils->read_bool(utils->data,
		"qcom,mdss-dsi-panel-force-power-off");
	if (utils->read_u32(utils->data,"qcom,mdss-dsi-panel-force-power-time",
		&pinfo->pwrkey_press.timer_val))
		LCD_ERR("failed to read: com,mdss-dsi-panel-force-power-time\n");
}

static void panel_parse_pre_reset_time_info(struct panel_info *pinfo,
		struct dsi_parser_utils *utils)
{
	int rc = 0;

	rc = utils->read_u32(utils->data,
			"qcom,mdss-dsi-panel-pre-reset-time",
			&pinfo->pre_reset_time);
	if (rc) {
		LCD_INFO("no pre reset delay configed\n");
	} else {
		LCD_INFO("pre reset delay configed : %d\n", pinfo->pre_reset_time);
	}
	return;
}

static int panel_parse(struct dsi_panel *panel, struct panel_info *pinfo)
{
	int rc = 0;
	struct dsi_parser_utils *utils = &panel->utils;

	if (!utils) {
		LCD_ERR("utils is null\n");
		return -1;
	}
	/* parse dt */
	pinfo->lcd_module_name = utils->get_property(utils->data,
		"qcom,mdss-dsi-lcd-module-name", NULL);
	pinfo->lcd_ic_name = utils->get_property(utils->data,
		"qcom,mdss-dsi-lcd-ic-name", NULL);

	pinfo->lcd_model = utils->get_property(utils->data,
		"qcom,mdss-dsi-lcd-model", NULL);
	if (!pinfo->lcd_model)
		pinfo->lcd_model = DEFAULT_PANEL_NAME;

	pinfo->hbm.enabled = utils->read_bool(utils->data,
		"qcom,mdss-dsi-panel-hbm-enabled");
	pinfo->local_hbm_enabled = utils->read_bool(utils->data,
		"qcom,mdss-dsi-panel-local-hbm-enabled");
	pinfo->lhbm_fpr_light_enable = utils->read_bool(utils->data,
		"qcom,mdss-dsi-lhbm-fpr-light-enable");
	pinfo->lhbm_adjust_light_enable = utils->read_bool(utils->data,
		"qcom,mdss-dsi-lhbm-light-adjust-enable");
	rc = utils->read_u32(utils->data, "qcom,mdss-dsi-bl-max-nit",
		&panel->bl_config.bl_max_nit);
	if (rc)
		DSI_ERR("failed to read: qcom,mdss-dsi-bl-max-nit, rc=%d\n", rc);
	pinfo->four_byte_bl = utils->read_bool(utils->data, "qcom,mdss-dsi-bl-four-byte-bl-enabled");
	panel_parse_gamma_info(panel, pinfo);
	panel_parse_oem_info(panel, pinfo);
	panel_parse_fps(pinfo, utils);
	panel_parse_mipi_error_info(panel, pinfo);
	panel_parse_adjust_backlight_info(pinfo, utils);
	panel_parse_batch_info(pinfo, utils);
	panel_parse_dsc_pps(panel, pinfo);
	panel_parse_force_poweroff_info(pinfo, utils);
	panel_parse_pre_reset_time_info(pinfo, utils);
	return 0;
}

int panel_mipi_error_check(struct dsi_panel *panel)
{
	int i = 0;
	int rc = 0;
	int tot = 0;
	u32 *exp_val = NULL;
	u32 judge_result = 1;
	uint8_t type = 0;
	u8 *val_str = NULL;
	u8 *exp_val_str[2] = { "expect_val", "err_mask" };
	uint8_t read_value[MIPI_ERROR_CHECK_LENGTH] = {0};
	int8_t record_buf[DMD_RECORD_BUF_LEN * MAX_REG_READ_COUNT] = {'\0'};
	struct panel_info *pinfo = NULL;

	pinfo = panel->pdata->pinfo;
	if (!pinfo) {
		LCD_ERR("pinfo is null\n");
		return LCD_FAIL;
	}

	if (!pinfo->mipi_error.support) {
		LCD_INFO("not support mipi error check\n");
		return rc;
	}

	if (MIPI_ERROR_CHECK_LENGTH < pinfo->mipi_error.expect_count) {
		LCD_INFO("mipi error check expect value > maxlen:%d.\n", MIPI_ERROR_CHECK_LENGTH);
		return rc;
	}

	exp_val = pinfo->mipi_error.expect_val;
	rc = dsi_panel_receive_data_nolock(panel, DSI_CMD_MIPI_ERROR_CHECK,
		read_value, pinfo->mipi_error.expect_count);
	if (rc) {
		LCD_ERR("read mipi error check fail\n");
		return rc;
	}

	for (i = 0; i < pinfo->mipi_error.expect_count; i++) {
		type = exp_val[i] >> 8;
		if (type == 0) {
			judge_result &= (read_value[i] == (exp_val[i] & 0xFF));
			val_str = exp_val_str[0];
		} else {
			judge_result &= (read_value[i] & (exp_val[i] & 0xFF)) ? false : true;
			val_str = exp_val_str[1];
		}

		if (i % 2) {
			LCD_INFO("l-bit read_val[%u]:0x%x, %s[%u]:0x%x.\n",
				i, read_value[i], val_str, i, exp_val[i] & 0xFF);
		} else {
			LCD_INFO("h-bit read_val[%u]:0x%x, %s[%u]:0x%x.\n",
				i, read_value[i], val_str, i, exp_val[i] & 0xFF);
		}
	}

	if (!judge_result) {
		tot = scnprintf(record_buf, DMD_RECORD_BUF_LEN * MAX_REG_READ_COUNT,
			"panel:%d mipi error check failed:\n", pinfo->panel_id);
		for (i = 0; i < pinfo->mipi_error.expect_count; i++) {
			tot += scnprintf(record_buf + tot, DMD_RECORD_BUF_LEN * MAX_REG_READ_COUNT - tot,
			"read_value[%d]:0x%x, expect_val[%d]:0x%x!\n",
			i, read_value[i], i, exp_val[i] & 0xFF);
		}
		(void)lcd_dsm_client_record(lcd_dclient, record_buf,
				DSM_LCD_MIPI_TRANSMIT_ERROR_NO);
		LCD_ERR("[%s] mipi error check is failed!\n", panel->name);
	} else {
		LCD_INFO("[%s] mipi error check is OK!\n", panel->name);
	}

	return rc;
}

static int create_fb_sysfs(int num)
{
	static bool inited = false;
	struct device *fb_dev = NULL;
	int ret;

	if (!inited) {
		fb_class = class_create(THIS_MODULE, "graphics");
		if (IS_ERR(fb_class))
			return PTR_ERR(fb_class);
		inited = true;
		LCD_INFO("create fb sysfs path!\n");
	}
	fb_dev = device_create(fb_class, NULL, 0, NULL, "fb%d", num);
	if (IS_ERR(fb_dev)){
		LCD_ERR("device_create fb%d failed\n", num);
		return -1;
	}

	fb_dev->id = num;
	ret = lcd_create_sysfs(&fb_dev->kobj);
	LCD_INFO("create fb%d sysfs success!\n", num);
	return 0;
}


extern int lcd_powerkey_register_notifier(struct notifier_block *nb);
extern int lcd_powerkey_unregister_notifier(struct notifier_block *nb);
extern int lcd_call_powerkey_notifiers(unsigned long val, void *v);
extern void lcd_register_power_key_notify(void);

int pwrkey_press_event_notifier(struct notifier_block *pwrkey_event_nb,
	unsigned long event, void *data)
{
	struct notifier_block *p = NULL;
	struct panel_info *pinfo = get_panel_info(get_active_panel());
	void *pd = NULL;
	unsigned int time;
	p = pwrkey_event_nb;
	pd = data;

	if (!pinfo)
		return LCD_FAIL;
	time = pinfo->pwrkey_press.timer_val;
	switch (event) {
	case PON_PRESS_KEY_S1:
		pinfo->pwrkey_press.long_press_flag = true;
		LCD_ERR("PON_PRESS_KEY_S1 time:%d\n", time);
		schedule_delayed_work(&pinfo->pwrkey_press.pf_work,
			msecs_to_jiffies(time));
		break;
	case PON_PRESS_KEY_UP:
		if (pinfo->pwrkey_press.long_press_flag == false) {
			LCD_INFO("pwrkey_press_event_notifier power_key up\n");
			break;
		}
		pinfo->pwrkey_press.long_press_flag = false;
		cancel_delayed_work_sync(&pinfo->pwrkey_press.pf_work);
		break;
	default:
		break;
	}
	return LCD_OK;
}

void power_off_work(struct work_struct *work)
{
	int rc = 0;
	struct panel_info *pinfo = get_panel_info(get_active_panel());
	struct dsi_panel *panel = pinfo->panel;
	if (!pinfo) {
		LCD_ERR("pinfo is null\n");
		return;
	}

	DSI_INFO("power_off_work");

	lcd_sde_panel_recovery(pinfo->sde_connector, false);

	if (rc)
		DSI_ERR("[%s] failed to set DSI panel backlight, rc=%d\n",
			panel->name, rc);
	return;
}

void lcd_register_power_key_notify(void)
{
	int ret;
  	int i;
	for (i = 0;i<2;i++)
	{
		struct delayed_work *p_work = NULL;
		struct panel_info *pinfo = get_panel_info(i);

		LCD_ERR("power_key notifier!\n");
		if (!pinfo)
			return;
		p_work = &pinfo->pwrkey_press.pf_work;
		INIT_DELAYED_WORK(p_work, power_off_work);
		pinfo->pwrkey_press.nb.notifier_call =
			pwrkey_press_event_notifier;
		ret = lcd_powerkey_register_notifier(
			&pinfo->pwrkey_press.nb);
		if (ret < 0)
			LCD_ERR("register power_key notifier failed!\n");
        }
}
#if IS_ENABLED(CONFIG_DSM)
static void panel_handle_te_check(struct work_struct *work)
{
	struct dsi_panel_te_check *te_check;
	struct hiview_hievent *event = NULL;
	int8_t record_buf[DMD_RECORD_BUF_LEN + 1] = {0};

	te_check = container_of(work, struct dsi_panel_te_check, work);
	if (!te_check) {
		LCD_ERR("te_check is null\n");
		return;
	}
	event = hiview_hievent_create(DSM_LCD_SWITCH_FPS_ERROR_NO);
	if (!event) {
		LCD_ERR("create hievent failed: %d \n", DSM_LCD_SWITCH_FPS_ERROR_NO);
		return;
	}

	/* current fps */
	hiview_hievent_put_integral(event, "CURDVRFPS", te_check->old_fps);
	/* next fps */
	hiview_hievent_put_integral(event, "NXTDVRFPS", te_check->cur_fps);
	/* start switch fps timestamp */
	memset(record_buf, 0, DMD_RECORD_BUF_LEN);
	(void)snprintf(record_buf, DMD_RECORD_BUF_LEN, "%llu\n",
		ktime_to_ms(te_check->timestamp_start));
	hiview_hievent_put_string(event, "FPSDRVSTART", record_buf);
	/* end switch fps timestamp */
	memset(record_buf, 0, DMD_RECORD_BUF_LEN);
	(void)snprintf(record_buf, DMD_RECORD_BUF_LEN, "%llu\n",
		ktime_to_ms(te_check->timestamp_end));
	hiview_hievent_put_string(event, "FPSDRVEND", record_buf);
	/* report dsm log */
	hiview_hievent_report(event);
	hiview_hievent_destroy(event);
	LCD_INFO("CurDrvFPS:%d NxtDrvFPS:%d FPSDrvStart:%lld FPSDrvEnd:%lld\n",
		te_check->old_fps, te_check->cur_fps,
		te_check->timestamp_start, te_check->timestamp_end);
}

static void panel_register_fps_error_handler(struct dsi_panel *panel)
{
	INIT_WORK(&panel->te_check.work, panel_handle_te_check);
}
#endif

static void panel_handle_backlight_check(struct work_struct *work)
{
	int ret = 0;
	char read_value[BACKLIGHT_REG_COUNT] = {0};
	struct delayed_work *dw = to_delayed_work(work);
	struct dsi_backlight_reg_check *backlight_check;
	struct dsi_panel *panel;
	int8_t record_buf[DMD_RECORD_BUF_LEN] = {'\0'};

	backlight_check = container_of(dw, struct dsi_backlight_reg_check, work);
	if (!backlight_check) {
		LCD_ERR("backlight_check is null\n");
		return;
	}
	panel = container_of(backlight_check, struct dsi_panel, backlight_check);
	if (!panel) {
		LCD_ERR("panel is null\n");
		return;
	}

	mutex_lock(&panel->panel_lock);
	if (panel->pdata->pinfo->brightness) {
		ret = dsi_backlight_reg_read(panel, BACKLIGHT_REG, read_value, BACKLIGHT_REG_COUNT);
		if (ret < 0)
			LCD_ERR("backlight reg read error\n");

		snprintf(record_buf, DMD_RECORD_BUF_LEN, "set backlight reg =0x%x%x", read_value[0], read_value[1]);
		LCD_INFO("set backlight backlight= 0x%x%x\n", read_value[0],read_value[1]);
		if (read_value[0] == 0 && read_value[1] == 0) {
			(void)lcd_dsm_client_record(lcd_dclient, record_buf,
					DSM_LCD_BACKLIGHT_REG_ERROR_NO);
			dsi_panel_set_backlight(panel, panel->pdata->pinfo->brightness);
		}
	}
	mutex_unlock(&panel->panel_lock);
}


static void panel_register_backlight_check_handler(struct dsi_panel *panel)
{
	INIT_DELAYED_WORK(&panel->backlight_check.work, panel_handle_backlight_check);
}


static void panel_register_work_handler(struct dsi_panel *panel)
{
	panel->panel_workq = create_singlethread_workqueue("panel_workq");
	if (!panel->panel_workq) {
		DSI_ERR("failed to create panel workq!\n");
		return;
	}
	panel_register_backlight_check_handler(panel);
#if IS_ENABLED(CONFIG_DSM)
	panel_register_fps_error_handler(panel);
#endif
}

static int panel_init(struct dsi_panel *panel)
{
	int ret;
	static bool dclient_init = false;
	struct panel_info *pinfo = NULL;

	if (!panel || !panel->name || !panel->pdata) {
		LCD_ERR("null pointer\n");
		return -1;
	}
	panel->enable_esd_check = true;
	pinfo = kzalloc(sizeof(struct panel_info), GFP_KERNEL);
	if (!pinfo) {
		LCD_ERR("kzalloc pinfo fail\n");
		return -1;
	}
	pinfo->power_on = true;
	pinfo->panel_state = LCD_POWER_ON;
	/* panel dtsi parse */
	ret = panel_parse(panel, pinfo);
	if (ret)
		LCD_ERR("panel parse failed\n");
#ifdef CONFIG_LCD_FACTORY
	ret = factory_init(panel, pinfo);
	if (ret)
		LCD_ERR("factory init failed\n");
#endif
#ifdef CONFIG_APP_INFO
	/* set app_info */
	ret = app_info_set("lcd type", panel->name);
	if (ret)
		LCD_ERR("set app info failed\n");
#endif
#if IS_ENABLED(CONFIG_DSM)

        if (pinfo->lcd_module_name == NULL) {
                LCD_ERR("lcd_module_name not exist\n");
        } else {
                dsm_lcd.module_name = pinfo->lcd_module_name;
                LCD_INFO("dmd log report lcd module_name=%s\n", dsm_lcd.module_name);
        }

        if (pinfo->lcd_ic_name == NULL) {
                LCD_ERR("lcd_ic_name not exist\n");
        } else {
                dsm_lcd.ic_name = pinfo->lcd_ic_name;
                LCD_INFO("dmd log report lcd ic_name=%s\n", dsm_lcd.ic_name);
        }

	if (!dclient_init) {
		lcd_dclient = dsm_register_client(&dsm_lcd);
		dclient_init = true;
	}
#endif

#if defined(CONFIG_PXLW_IRIS)
	// No need extern callback and fb sysfs for Iris dual channel.
	if (iris_is_dual_supported() && panel->is_secondary) {
		LCD_INFO("IRIS_LOG secondary panel done\n");
		panel->pdata->pinfo = pinfo;
		pinfo->panel = panel;
		return 0;
	}
#endif

	pinfo->aod_mod = 0;

	/* register extern callback */
	lcd_kit_ops_register(&lcd_ops);
	/* register work handler */
	panel_register_work_handler(panel);

	/* create fb sysfs */
	ret = create_fb_sysfs(registered_fb_num);
	if (ret) {
		kfree(pinfo);
		LCD_ERR("create fb sysfs failed!\n");
		return -1;
	}

	panel->pdata->pinfo = pinfo;
	if (registered_fb_num >= FB_MAX) {
		kfree(pinfo);
		LCD_ERR("exceed max fb number\n");
		return -1;
	}
	pinfo->panel_id = registered_fb_num;
	pinfo->panel = panel;
	g_panel_info[registered_fb_num++] = pinfo;

	if (pinfo->pwrkey_press.support){
		lcd_register_power_key_notify();
		LCD_ERR("pwrkey_press.support\n");
	}

#ifdef CONFIG_LCD_DEBUG
	debugfs_init();
#endif
	return 0;
}

static int panel_hbm_mmi_set(struct dsi_panel *panel, int level)
{
	struct hbm_desc *hbm = NULL;

	hbm = &(panel->pdata->pinfo->hbm);
	if (!hbm->enabled)
		return 0;
	if (level == 0) {
		dsi_panel_set_hbm_level(panel, panel->bl_config.bl_level);
		hbm->mode = HBM_EXIT;
		return 0;
	}
	dsi_panel_set_hbm_level(panel, level);
	hbm->mode = HBM_ENTER;
	return 0;
}

static int panel_hbm_set_handle(struct dsi_panel *panel, int dimming,
	int level)
{
	int rc;
	static int last_level = 0;
	struct hbm_desc *hbm = NULL;

	hbm = &(panel->pdata->pinfo->hbm);
	if (!hbm->enabled)
		return 0;
	if ((level < 0) || (level > HBM_SET_MAX_LEVEL)) {
		LCD_ERR("input param invalid, hbm_level %d!\n", level);
		return -1;
	}
	if (level > 0) {
		if (last_level == 0) {
			/* enable hbm */
			rc = dsi_panel_set_cmd(panel, DSI_CMD_SET_HBM_ENABLE);
			if (rc)
				LCD_ERR("set hbm enable failed\n");
			if (!dimming) {
				rc = dsi_panel_set_cmd(panel, DSI_CMD_SET_HBM_DIMM_OFF);
				if (rc)
					LCD_ERR("set hbm dimming off failed\n");
			}
			hbm->mode = HBM_ENTER;
		}
	} else {
		if (last_level == 0) {
			/* disable dimming */
			rc = dsi_panel_set_cmd(panel, DSI_CMD_SET_HBM_DIMM_OFF);
			if (rc)
				LCD_ERR("set hbm dimming off failed\n");
		} else {
			/* exit hbm */
			if (dimming) {
				rc = dsi_panel_set_cmd(panel, DSI_CMD_SET_HBM_DIMM_ON);
				if (rc)
					LCD_ERR("set hbm dimming on failed\n");
			} else {
				rc = dsi_panel_set_cmd(panel, DSI_CMD_SET_HBM_DIMM_OFF);
				if (rc)
					LCD_ERR("set hbm dimming off failed\n");
			}
			rc = dsi_panel_set_cmd(panel, DSI_CMD_SET_HBM_DISABLE);
			if (rc)
				LCD_ERR("set hbm disable failed\n");
			hbm->mode = HBM_EXIT;
		}
	}
	/* set hbm level */
	rc = dsi_panel_set_hbm_level(panel, level);
	if (rc)
		LCD_ERR("set backlight failed\n");
	last_level = level;
	return 0;
}

static int panel_local_hbm_mmi_set(struct dsi_panel *panel, int level)
{
	LCD_INFO("local_hbm_enabled:%d\n",panel->pdata->pinfo->local_hbm_enabled);
	if (!panel->pdata->pinfo->local_hbm_enabled)
		return -1;

	if (level == 0) {
		dsi_panel_set_cmd(panel, DSI_CMD_SET_LHBM_DISABLE);
		return 0;
	}

	if (panel->power_mode == SDE_MODE_DPMS_LP1 ||
		panel->power_mode == SDE_MODE_DPMS_LP2) {
		LCD_INFO("current mode is aod and lhbm return\n");
		return -1;
	}

	dsi_panel_set_cmd(panel, DSI_CMD_SET_LHBM_ON_ENABLE);
	return 0;
}

void lcdkit_fp_hbm_on(void)
{
	struct ud_fp_lcd_ops *fp_hbm_handle = NULL;

	fp_hbm_handle = ud_fp_lcd_get_ops();
	if (!fp_hbm_handle || !fp_hbm_handle->ud_fp_on_hbm_completed) {
		LCD_ERR("point is NULL!!\n");
		return;
	}
	fp_hbm_handle->ud_fp_on_hbm_completed();
	LCD_INFO("ud_fp_on_hbm_completed!\n");
}

#define LHBM_FPS_NOT_120 2
#define FPS_120_HZ 120
static int panel_local_hbm_identify_on_set(struct dsi_panel *panel, int level)
{
	LCD_INFO("Panel on, local_hbm_enabled:%d, level = %d\n",
			panel->pdata->pinfo->local_hbm_enabled, level);
	if (!panel->pdata->pinfo->local_hbm_enabled)
		return -1;

	if (level == 0) {
		dsi_panel_set_cmd(panel, DSI_CMD_SET_LHBM_DISABLE);
		dsi_panel_set_cmd(panel, DSI_CMD_SET_TIMING_SWITCH);
		panel->lhbm_state = 0;
		/*if (panel->power_mode != SDE_MODE_DPMS_LP1 &&
			panel->power_mode != SDE_MODE_DPMS_LP2) {
			LCD_INFO("current mode is not aod and LhbmExit\n");
			dsi_panel_set_cmd(panel, DSI_CMD_SET_TIMING_SWITCH);
		}*/
		return 0;
	}

	if ((level == HBM_ENTER) && (panel->cur_mode->timing.refresh_rate != FPS_120_HZ)
		&& (panel->power_mode != SDE_MODE_DPMS_LP1
		&& panel->power_mode != SDE_MODE_DPMS_LP2)) {
		LCD_INFO("%s: fps = %d\n", __func__, panel->cur_mode->timing.refresh_rate);
		return LHBM_FPS_NOT_120;
	}

	if (panel->pdata->pinfo->lhbm_fpr_light_enable) {
		uint8_t bl_value[BACKLIGHT_LENGTH] = {0xDF};
		uint8_t i;
		struct dsi_display_mode *mode;
		struct dsi_cmd_desc *cmds;
		u32 count;
		u32 backlight;

		if (!panel || !panel->cur_mode)
			return -EINVAL;

		mode = panel->cur_mode;

		backlight = panel->backlight;
		if (panel->bl_config.bl_inverted_dbv)
			backlight = (backlight >> 8) | ((backlight & 0xFF) << 8);
		LCD_INFO("fsr backlight:%d\n", backlight);
		if (panel->pdata->pinfo->lhbm_light_changed) {
			cmds = mode->priv_info->cmd_sets[DSI_CMD_SET_LHBM_LIGHT].cmds;
			++cmds;
			if (backlight > 3515) {
				backlight = 4000;
				cmds->msg.tx_buf = panel->pdata->pinfo->lhbm_light_origin;
			} else {
				cmds->msg.tx_buf = panel->pdata->pinfo->lhbm_light_adjust;
			}
			LCD_INFO("lhbm D0 changed backlight:%d\n", backlight);
			dsi_panel_set_cmd(panel, DSI_CMD_SET_LHBM_LIGHT);
		}
		backlight <<= 2;
		bl_value[1] = backlight >> 8;
		bl_value[2] = backlight & 0xFF;

		count = mode->priv_info->cmd_sets[DSI_CMD_SET_LHBM_FSR_LIGHT].count;
		cmds = mode->priv_info->cmd_sets[DSI_CMD_SET_LHBM_FSR_LIGHT].cmds;
		for (i = 0; i < count - 1; i++) {
			++cmds;
		}
		cmds->msg.tx_buf = bl_value;
		dsi_panel_set_cmd(panel, DSI_CMD_SET_LHBM_FSR_LIGHT);
	}
	dsi_panel_set_cmd(panel, DSI_CMD_SET_LHBM_ON_ENABLE);
	panel->lhbm_state = 1;
	lcdkit_fp_hbm_on();
	return 0;
}

static int panel_local_hbm_identify_off_set(struct dsi_panel *panel, int level)
{
	LCD_INFO("Panel off, local_hbm_enabled:%d, level = %d, power mode = %d\n",
			 panel->pdata->pinfo->local_hbm_enabled, level, panel->power_mode);
	if (!panel->pdata->pinfo->local_hbm_enabled)
		return -1;

	if (level == 0) {
		dsi_panel_set_cmd(panel, DSI_CMD_SET_LHBM_DISABLE);
		dsi_panel_set_cmd(panel, DSI_CMD_SET_TIMING_SWITCH);
		panel->lhbm_state = 0;
		/*if (panel->power_mode != SDE_MODE_DPMS_LP1 &&
			panel->power_mode != SDE_MODE_DPMS_LP2) {
			LCD_INFO("current mode is not aod and LhbmExit\n");
			dsi_panel_set_cmd(panel, DSI_CMD_SET_TIMING_SWITCH);
		}*/
		return 0;
	}

	if ((level == HBM_ENTER) && (panel->cur_mode->timing.refresh_rate != FPS_120_HZ)
		&& (panel->power_mode != SDE_MODE_DPMS_LP1
		&& panel->power_mode != SDE_MODE_DPMS_LP2)) {
		LCD_INFO("%s: fps = %d\n", __func__, panel->cur_mode->timing.refresh_rate);
		return LHBM_FPS_NOT_120;
	}

	if (panel->pdata->pinfo->lhbm_fpr_light_enable) {
		uint8_t bl_value[BACKLIGHT_LENGTH] = {0xDF};
		uint8_t i;
		struct dsi_display_mode *mode;
		struct dsi_cmd_desc *cmds;
		u32 count;
		u32 backlight;

		if (!panel || !panel->cur_mode)
			return -EINVAL;

		mode = panel->cur_mode;

		backlight = panel->backlight;
		if (panel->bl_config.bl_inverted_dbv)
			backlight = (backlight >> 8) | ((backlight & 0xFF) << 8);
		LCD_INFO("fsr backlight:%d\n", backlight);
		if (panel->pdata->pinfo->lhbm_light_changed) {
			cmds = mode->priv_info->cmd_sets[DSI_CMD_SET_LHBM_LIGHT].cmds;
			++cmds;
			if (backlight > 3515) {
				backlight = 4000;
				cmds->msg.tx_buf = panel->pdata->pinfo->lhbm_light_origin;
			} else {
				cmds->msg.tx_buf = panel->pdata->pinfo->lhbm_light_adjust;
			}
			LCD_INFO("lhbm D0 changed backlight:%d\n", backlight);
			dsi_panel_set_cmd(panel, DSI_CMD_SET_LHBM_LIGHT);
		}
		backlight <<= 2;
		bl_value[1] = backlight >> 8;
		bl_value[2] = backlight & 0xFF;

		count = mode->priv_info->cmd_sets[DSI_CMD_SET_LHBM_FSR_LIGHT].count;
		cmds = mode->priv_info->cmd_sets[DSI_CMD_SET_LHBM_FSR_LIGHT].cmds;
		for (i = 0; i < count - 1; i++) {
			++cmds;
		}
		cmds->msg.tx_buf = bl_value;
		dsi_panel_set_cmd(panel, DSI_CMD_SET_LHBM_FSR_LIGHT);
	}

	dsi_panel_set_cmd(panel, DSI_CMD_SET_LHBM_OFF_ENABLE);
	panel->lhbm_state = 1;
	lcdkit_fp_hbm_on();
	return 0;
}

static int panel_hbm_set(struct dsi_panel *panel,
	struct display_engine_ddic_hbm_param *hbm_cfg)
{
	int rc;

	if (!panel || !panel->pdata || !panel->pdata->pinfo) {
		LCD_ERR("panel have null pointer\n");
		return -EINVAL;
	}
	if (!hbm_cfg) {
		LCD_ERR("hbm_cfg is null\n");
		return -EINVAL;
	}
	LCD_INFO("hbm tpye:%d, level:%d, dimming:%d\n", hbm_cfg->type,
		hbm_cfg->level, hbm_cfg->dimming);
	mutex_lock(&panel->panel_lock);
	switch (hbm_cfg->type) {
	case HBM_FOR_MMI:
		rc = panel_hbm_mmi_set(panel, hbm_cfg->level);
		break;
	case HBM_FOR_LIGHT:
		rc = panel_hbm_set_handle(panel, hbm_cfg->level, hbm_cfg->dimming);
		break;
	case LOCAL_HBM_FOR_MMI:
		rc = panel_local_hbm_mmi_set(panel, hbm_cfg->level);
		break;
	case LOCAL_HBM_FOR_IDENTIFY_ON:
		rc = panel_local_hbm_identify_on_set(panel, hbm_cfg->level);
		break;
	case LOCAL_HBM_FOR_IDENTIFY_OFF:
		rc = panel_local_hbm_identify_off_set(panel, hbm_cfg->level);
		break;
	default:
		LCD_ERR("not support type:%d\n", hbm_cfg->type);
		rc = -1;
	}
	mutex_unlock(&panel->panel_lock);
	return rc;
}

static int ts_power_notify(struct dsi_panel *panel,
	enum lcd_kit_ts_pm_type type, int sync)
{
	int ret = 0;
	struct ts_kit_ops *ts_ops = ts_kit_get_ops();

	if (is_dual_panel()) {
		if((panel->pdata->pinfo->panel_id == SECONDARY_PANEL) && (panel->pdata->pinfo->dual_panel_display == DUAL_DISPLAY_MODE)) {
			LCD_INFO("Don't notify TP \n");
			goto out;
		}
		if (ts_ops && ts_ops->ts_multi_power_notify)
			ret = ts_ops->ts_multi_power_notify(type, sync,
				panel->pdata->pinfo->panel_id);
			LCD_INFO("dual panel, panel_id = %d\n", panel->pdata->pinfo->panel_id);
	} else {
		if (ts_ops && ts_ops->ts_power_notify)
			ret = ts_ops->ts_power_notify(type, sync);
			LCD_INFO("single panel\n");
	}

out:
	return ret;
}

static int usb_power_notify(struct dsi_panel *panel,
	enum lcd_kit_usb_pm_type type, int sync)
{
	int ret = 0;
	struct usb_kit_ops *usb_ops = usb_kit_get_ops();

	if (is_dual_panel()) {
		if (usb_ops && usb_ops->usb_multi_power_notify) {
			ret = usb_ops->usb_multi_power_notify(type, sync,
				panel->pdata->pinfo->panel_id);
			LCD_INFO("dual panel, panel_id = %d\n", panel->pdata->pinfo->panel_id);
		}
	} else {
		if (usb_ops && usb_ops->usb_power_notify) {
			ret = usb_ops->usb_power_notify(type, sync);
			LCD_INFO("single panel\n");
		}
	}
	return ret;
}

static int bat_heating_notify(struct dsi_panel *panel,
	enum lcd_kit_bat_heating_type type, int sync)
{
	int ret = 0;
	struct bat_heating_ops *bat_heating_ops_handle = bat_heating_get_ops();

	if (is_dual_panel()) {
		if (bat_heating_ops_handle && bat_heating_ops_handle->bat_heating_multi_notify) {
			ret = bat_heating_ops_handle->bat_heating_multi_notify(type, sync,
				panel->pdata->pinfo->panel_id);
			LCD_INFO("%s,dual panel, panel_id = %d,type = %d\n",__FUNCTION__,panel->pdata->pinfo->panel_id,type);
		}
	} else {
		if (bat_heating_ops_handle && bat_heating_ops_handle->bat_heating_notify) {
			ret = bat_heating_ops_handle->bat_heating_notify(type, sync);
			LCD_INFO("%s,single panel,%d\n",__FUNCTION__,type);
		}
	}
	return ret;
}

static int bat_leakage_notify(struct dsi_panel *panel,
	enum lcd_kit_bat_leakage_type type, int sync)
{
	int ret = 0;
	struct bat_leakage_kit_ops *bat_leakage_ops_handle = bat_leakage_kit_get_ops();

	if (is_dual_panel()) {
		if (bat_leakage_ops_handle && bat_leakage_ops_handle->bat_leakage_multi_notify) {
			ret = bat_leakage_ops_handle->bat_leakage_multi_notify(type, sync,
				panel->pdata->pinfo->panel_id);
			LCD_INFO("dual panel, panel_id = %d,type = %d\n", panel->pdata->pinfo->panel_id,type);
		}
	} else {
		if (bat_leakage_ops_handle && bat_leakage_ops_handle->bat_leakage_notify) {
			ret = bat_leakage_ops_handle->bat_leakage_notify(type, sync);
			LCD_INFO("single panel\n");
		}
	}
	return ret;
}

static void set_active_panel(struct panel_info *pinfo, bool active)
{
	if (pinfo->panel_id == PRIMARY_PANEL) {
		if (active)
			active_panel |= BIT(PRIMARY_PANEL);
		else
			active_panel &= (~BIT(PRIMARY_PANEL));
	} else {
		if (active)
			active_panel |= BIT(SECONDARY_PANEL);
		else
			active_panel &= (~BIT(SECONDARY_PANEL));
	}
}

static int panel_on(struct dsi_panel *panel, int step)
{
	int rc = 0;

	if (!panel || !panel->pdata || !panel->pdata->pinfo) {
		LCD_ERR("pointer is null\n");
		return -1;
	}
#if defined(CONFIG_PXLW_IRIS)
	if (iris_is_dual_supported() && panel->is_secondary) {
		LCD_INFO("IRIS_LOG secondary panel on\n");
		return rc;
	}
#endif
	switch (step) {
	case PANEL_INIT_NONE:
		LCD_INFO("panel init none step\n");
		LCD_INFO("dsi panel: %s\n", panel->name);
		LOG_JANK_D(JLID_KERNEL_LCD_POWER_ON, "%s", "LCD_POWER_ON");
		break;
	case PANEL_INIT_POWER_ON:
		LCD_INFO("panel init power on step\n");
		panel->pdata->pinfo->panel_state = LCD_POWER_ON;
		rc = ts_power_notify(panel, TS_RESUME_DEVICE, NO_SYNC);
		if (rc)
			LCD_ERR("TS_RESUME_DEVICE failed\n");
		rc = usb_power_notify(panel, USB_RESUME_DEVICE, NO_SYNC);
		if (rc)
			LCD_ERR("USB_RESUME_DEVICE failed\n");
		rc = bat_heating_notify(panel, BAT_HEATING_LCD_ON, NO_SYNC);
		if (rc)
			LCD_ERR("BAT_HEATING_LCD_ON failed\n");
		rc = bat_leakage_notify(panel, BAT_LEAKAGE_LCD_ON, NO_SYNC);
		if (rc)
			LCD_ERR("BAT_LEAKAGE_LCD_ON failed\n");
		break;
	case PANEL_INIT_MIPI_LP_SEND_SEQUENCE:
		LCD_INFO("panel init mipi lp step\n");
		panel->pdata->pinfo->power_on = true;
		panel->pdata->pinfo->panel_state = LCD_LP_ON;
		rc = ts_power_notify(panel, TS_AFTER_RESUME, NO_SYNC);
		if (rc)
			LCD_ERR("TS_AFTER_RESUME failed\n");
#ifdef CONFIG_LCD_FACTORY
		if (atomic_read(&panel->pdata->pinfo->lcd_noti_comp))
			complete(&panel->pdata->pinfo->lcd_test_comp);
#endif
		set_active_panel(panel->pdata->pinfo, true);
		break;
	case PANEL_INIT_MIPI_HS_SEND_SEQUENCE:
		LCD_INFO("panel init mipi hs step\n");
#ifdef CONFIG_LCD_FACTORY
		if (!(panel->pdata->pinfo->inited)) {
			/* read panel sn code */
			read_2d_barcode(panel, mutex_is_locked(&panel->panel_lock));
			panel->pdata->pinfo->inited = true;
		}
#endif
		panel->pdata->pinfo->panel_state = LCD_HS_ON;
		break;
	default:
		LCD_ERR("not support step:%d\n", step);
		rc = -1;
		break;
	}
	return rc;
}

static int panel_off(struct dsi_panel *panel, int step)
{
	int rc = 0;

	if (!panel || !panel->pdata || !panel->pdata->pinfo) {
		LCD_ERR("pointer is null\n");
		return -1;
	}
#if defined(CONFIG_PXLW_IRIS)
	if (iris_is_dual_supported() && panel->is_secondary) {
		LCD_INFO("IRIS_LOG secondary panel off\n");
		return rc;
	}
#endif
	switch (step) {
	case PANEL_UNINIT_NONE:
		panel_mipi_error_check(panel);
		LCD_INFO("panel uninit none step\n");
		break;
	case PANEL_UNINIT_MIPI_HS_SEND_SEQUENCE:
		LCD_INFO("panel uninit mipi hs step\n");
		panel->pdata->pinfo->power_on = false;
		rc = ts_power_notify(panel, TS_EARLY_SUSPEND, NO_SYNC);
		if (rc)
			LCD_ERR("TS_EARLY_SUSPEND failed\n");
		break;
	case PANEL_UNINIT_MIPI_LP_SEND_SEQUENCE:
		LCD_INFO("panel uninit mipi lp step\n");
		break;
	case PANEL_UNINIT_POWER_OFF:
		panel->pdata->pinfo->panel_state = LCD_POWER_OFF;
		panel->pdata->pinfo->hbm.mode = HBM_EXIT;
		LCD_INFO("panel uninit power off step\n");
		rc = ts_power_notify(panel, TS_BEFORE_SUSPEND, NO_SYNC);
		if (rc)
			LCD_ERR("TS_BEFORE_SUSPEND failed\n");
		rc = ts_power_notify(panel, TS_SUSPEND_DEVICE, NO_SYNC);
		if (rc)
			LCD_ERR("TS_SUSPEND_DEVICE failed\n");
		rc = usb_power_notify(panel, USB_SUSPEND_DEVICE, NO_SYNC);
		if (rc)
			LCD_ERR("USB_SUSPEND_DEVICE failed\n");
		rc = bat_heating_notify(panel, BAT_HEATING_LCD_OFF, NO_SYNC);
		if (rc)
			LCD_ERR("BAT_HEATING_LCD_OFF failed\n");
		rc = bat_leakage_notify(panel, BAT_LEAKAGE_LCD_OFF, NO_SYNC);
		if (rc)
			LCD_ERR("BAT_LEAKAGE_LCD_OFF failed\n");

		set_active_panel(panel->pdata->pinfo, false);
		LOG_JANK_D(JLID_KERNEL_LCD_POWER_OFF, "%s", "LCD_POWER_OFF");
		break;
	default:
		LCD_ERR("not support step:%d\n", step);
		rc = -1;
		break;
	}
	return rc;
}

static int panel_hbm_fp_set(struct dsi_panel *panel, int mode)
{
	int bl_level;

	if (!panel->pdata->pinfo) {
		LCD_ERR("pinfo is null\n");
		return -1;
	}
	if (mode == HBM_MODE_ON) {
		dsi_panel_set_cmd(panel, DSI_CMD_SET_FP_HBM_ENABLE);
		panel->pdata->pinfo->hbm.mode = HBM_ENTER;
		lcdkit_fp_hbm_on();
	} else {
		dsi_panel_set_cmd(panel, DSI_CMD_SET_FP_HBM_DISABLE);
		panel->pdata->pinfo->hbm.mode = HBM_EXIT;
		bl_level = panel->bl_config.bl_level;
		LCD_INFO("restore bl_level = %d\n", bl_level);
		dsi_panel_set_hbm_level(panel, bl_level);
	}
	return 0;
}

static int print_backlight(struct dsi_panel *panel, u32 bl_lvl)
{
	static int last_level = 0;

	if (last_level == 0 && bl_lvl != 0) {
		LCD_INFO("screen on, backlight level = %d\n", bl_lvl);
		LOG_JANK_D(JLID_KERNEL_LCD_BACKLIGHT_ON, "LCD_BACKLIGHT_ON,%u", bl_lvl);
		queue_delayed_work(panel->panel_workq, &panel->backlight_check.work, usecs_to_jiffies(8300));/*delay one frame of 120hz*/
	} else if (last_level !=0 && bl_lvl == 0) {
		LCD_INFO("screen off, backlight level = %d\n", bl_lvl);
		LOG_JANK_D(JLID_KERNEL_LCD_BACKLIGHT_OFF, "LCD_BACKLIGHT_OFF");
	}
	LCD_INFO("backlight level = %d\n", bl_lvl);
	last_level = bl_lvl;
	return 0;
}

int panel_get_status_by_type(int type, int *status)
{
	int ret;
	struct panel_info *pinfo = NULL;

	if (!status) {
		LCD_ERR("status is null\n");
		return LCD_FAIL;
	}
	pinfo = get_panel_info(0);
	if (!pinfo) {
		LCD_ERR("pinfo is null\n");
		return LCD_FAIL;
	}
	switch (type) {
	case PT_STATION_TYPE:
#ifdef CONFIG_LCD_FACTORY
		if (!pinfo->fact_info) {
			LCD_ERR("fact_info is null\n");
			return LCD_FAIL;
		}
		LCD_INFO("pt_flag = %d\n", pinfo->fact_info->pt_flag);
		*status = pinfo->fact_info->pt_flag;
#endif
		ret = LCD_OK;
		break;
	default:
		LCD_ERR("not support type\n");
		ret = LCD_FAIL;
		break;
	}
	return ret;
}

static int gamma_read(struct dsi_panel *panel, int type, struct dsi_panel_cmd_set *cmd_set,
		uint8_t *data, int len, uint8_t BF)
{
	int rc = 0;
	struct dsi_cmd_desc *cmds;
	uint8_t *buf = NULL;

	buf = kzalloc(2, GFP_KERNEL);
	buf[0] = 0xBF;
	buf[1] = BF;

	cmds = cmd_set->cmds;
	++cmds;

	kfree(cmds->msg.tx_buf);

	cmds->msg.tx_buf = buf;

	rc = dsi_panel_receive_data_nolock_cmd(panel, type,
				cmd_set, data, len);
	if (rc) {
		LCD_ERR("read gamma type:%d failed, BF:0x%x\n", type, BF);
		return rc;
	}

	return rc;
}

static void gamma_code_prepare(struct dsi_panel *panel, int src_fre, int des_fre, uint8_t BF)
{
	int i, j, k;
	u32 reg;
	u32 count;
	u32 cnt;
	struct dsi_cmd_desc *cmds;
	uint8_t *buf = NULL;

	j = 0;
	reg = REG_BEGIN;
	count = panel->gamma_info.gamma_set_cmd[des_fre].count;
	cmds = panel->gamma_info.gamma_set_cmd[des_fre].cmds;

	++cmds;

	buf = kzalloc(2, GFP_KERNEL);
	if (!buf) {
		LCD_ERR("kzalloc err \n");
		return;
	}
	buf[0] = 0xBF;
	buf[1] = BF;

	kfree(cmds->msg.tx_buf);
	cmds->msg.tx_buf = buf;

	++cmds;
	++cmds;

	for (i = SET_NOR3_CMD_BEGIN; i < count - 2; i++) {
		uint8_t *tmp;
		//int m;
		k = 1;
		kfree(cmds->msg.tx_buf);
		cnt = cmds->msg.tx_len;
		tmp = kzalloc(cnt, GFP_KERNEL);
		if (!tmp) {
			LCD_ERR("kzalloc err \n");
			return;
		}
		tmp[0] = reg++;
		--cnt;
		while (cnt--) {
			tmp[k++] = panel->gamma_info.gamma_data_set[src_fre][j++];
		}
		//for (m = 0; m < cmds->msg.tx_len; m++)
			//LCD_INFO("tmp[%d]:0x%x\n", m, tmp[m]);
		cmds->msg.tx_buf = tmp;
		++cmds;
	}
}

static int gamma_code_cal(struct dsi_panel *panel, int fre)
{
	u8 data[2][LCD_GAMMA_CODE_LENGTH] = {0};
	uint8_t RGB255[LCD_GAMMA_RGB_LENGTH] = {0};
	int rc = 0;
	int i;
	int cnt;

	u32 RGB255_ratio[3] = {0};
	int gamma_nor1 = fre == SET_GAMMA_120HZ_NOR3 ? GAMMA_120HZ_NOR1 : GAMMA_90HZ_NOR1;
	int gamma_nor3 = fre == SET_GAMMA_120HZ_NOR3 ? GAMMA_120HZ_NOR3 : GAMMA_90HZ_NOR3;
	int gamma_nor5 = fre == SET_GAMMA_120HZ_NOR3 ? GAMMA_120HZ_NOR5 : GAMMA_90HZ_NOR5;

	rc = gamma_read(panel, DSI_CMD_READ_GAMMA_8, &panel->gamma_info.gamma_read_8_cmd,
				data[0], LCD_GAMMA_CODE_LENGTH, gamma_nor1);
	if (rc) {
		LCD_ERR("read GAMMA1 reg failed\n");
		return rc;
	}

	rc = gamma_read(panel, DSI_CMD_READ_GAMMA_3, &panel->gamma_info.gamma_read_3_cmd,
				RGB255, LCD_GAMMA_RGB_LENGTH, gamma_nor3);
	if (rc) {
		LCD_ERR("read GAMMA3 reg failed\n");
		return rc;
	}

	rc = gamma_read(panel, DSI_CMD_READ_GAMMA_8, &panel->gamma_info.gamma_read_8_cmd,
				data[1], LCD_GAMMA_CODE_LENGTH, gamma_nor5);
	if (rc) {
		LCD_ERR("read GAMMA5 reg failed\n");
		return rc;
	}

	RGB255_ratio[0] = LCD_GAMMA_RATIO * (RGB255[12] << 8 | RGB255[13]) * 2 /
						((data[0][48] << 8 | data[0][49]) + (data[1][48] << 8 | data[1][49]));
	RGB255_ratio[1] = LCD_GAMMA_RATIO * (RGB255[26] << 8 | RGB255[27]) * 2 /
						((data[0][98] << 8 | data[0][99]) + (data[1][98] << 8 | data[1][99]));
	RGB255_ratio[2] = LCD_GAMMA_RATIO * (RGB255[40] << 8 | RGB255[41]) * 2 /
						((data[0][148] << 8 | data[0][149]) + (data[1][148] << 8 | data[1][149]));

	LCD_INFO("gamma ratio:%d %d %d\n", RGB255_ratio[0], RGB255_ratio[1], RGB255_ratio[2]);

	cnt = sizeof(data[0]) / 2;
	for (i = 0; i < cnt; i++) {
		uint16_t data1, data5, data3;
		data1 = (data[0][2 * i] << 8) | (data[0][2 * i + 1] & 0xFF);
		data5 = (data[1][2 * i] << 8) | (data[1][2 * i + 1] & 0xFF);
		data3 = (data1 + data5) * RGB255_ratio[i / 25] / (2 * LCD_GAMMA_RATIO);
		panel->gamma_info.gamma_data_set[fre][2 * i] = data3 >> 8;
		panel->gamma_info.gamma_data_set[fre][2 * i + 1] = data3 & 0xFF;
		//LCD_ERR("xxy:data1[%d]=0x%x,data5[%d]=0x%x,average=0x%x,data3[%d]=0x%x\n", i, data1, i, data5, (data1 + data5) / 2, i, data3);
	}

	gamma_code_prepare(panel, fre, fre, gamma_nor3);

	return rc;
};

static int gamma_code_copy(struct dsi_panel *panel, int src_fre, int des_fre, uint8_t src_BF, uint8_t des_BF)
{
	int rc = 0;

	rc = gamma_read(panel, DSI_CMD_READ_GAMMA_8, &panel->gamma_info.gamma_read_8_cmd,
			panel->gamma_info.gamma_data_set[src_fre], LCD_GAMMA_CODE_LENGTH, src_BF);

	gamma_code_prepare(panel, src_fre, des_fre, des_BF);

	return rc;
}

int gamma_code(struct dsi_panel *panel)
{
	int rc = 0;
	uint8_t batch[5] = {0};

	if (!panel || !panel->host) {
		LCD_ERR("panel is null\n");
		return LCD_FAIL;
	}

	if (!panel->gamma_info.support) {
		LCD_INFO("gamma info is not support\n");
		return rc;
	}

	rc = dsi_panel_receive_data_nolock_cmd(panel, DSI_CMD_GAMMA_BATCH,
				&panel->gamma_info.batch_cmd, batch, LCD_GAMMA_BATCH_LENGTH);
	if (rc) {
		LCD_ERR("read batch reg failed\n");
		return rc;
	}

	LCD_INFO("gamma batch: D6 0x%x DF 0x%x\n", batch[3], batch[4]);
	if (batch[4] == 0x00 && (batch[3] == 0x31 || batch[3] == 0x32))
		panel->gamma_info.enable = true;
	else {
		panel->gamma_info.enable = false;
		return rc;
	}

	gamma_code_cal(panel, SET_GAMMA_120HZ_NOR3);
	gamma_code_cal(panel, SET_GAMMA_90HZ_NOR3);
	gamma_code_copy(panel, SET_GAMMA_LHBM_NOR2, SET_GAMMA_LHBM_NOR2, GAMMA_120HZ_NOR2, GAMMA_LHBM_NOR2);
	gamma_code_prepare(panel, SET_GAMMA_120HZ_NOR3, SET_GAMMA_LHBM_NOR3, GAMMA_LHBM_NOR3);
	gamma_code_copy(panel, SET_GAMMA_LHBM_NOR4, SET_GAMMA_LHBM_NOR4, GAMMA_120HZ_NOR4, GAMMA_LHBM_NOR4);

	return rc;
}

static int read_sn_code(struct dsi_panel *panel)
{
	struct panel_info *pinfo = NULL;
	int rc = 0;

	pinfo = panel->pdata->pinfo;
	if (!pinfo) {
		LCD_ERR("pinfo is null\n");
		return LCD_FAIL;
	}
	if (!pinfo->oeminfo.sn_data.support)
		return rc;
	rc = dsi_panel_receive_data(panel, DSI_CMD_READ_OEMINFO,
		pinfo->oeminfo.sn_data.sn_code, LCD_SN_CODE_LENGTH);
	if (rc) {
		LCD_ERR("read sn reg failed\n");
		return rc;
	}
	LCD_INFO("sn: %s\n", panel->pdata->pinfo->oeminfo.sn_data.sn_code);
	return rc;
}

static int read_batch_match(struct dsi_panel *panel)
{
	struct panel_info *pinfo = NULL;
	uint8_t read_value = 0;
	int rc = LCD_OK;
	int i;

	pinfo = panel->pdata->pinfo;
	if (!pinfo) {
		LCD_ERR("pinfo is null\n");
		return LCD_FAIL;
	}
	if (!pinfo->lcd_panel_batch_info.support ||
		!pinfo->lcd_panel_batch_info.batch_match_hbm)
		return rc;
	rc = dsi_panel_receive_data(panel, DSI_CMD_READ_BATCHINFO,
		&read_value, MAX_REG_READ_COUNT);
	if (rc) {
		LCD_ERR("read batch reg failed\n");
		return rc;
	}
	LCD_INFO("LHBM OTP batch value: %d\n", read_value);
	for (i = 0; i < pinfo->lcd_panel_batch_info.cnt; i++) {
		if (pinfo->lcd_panel_batch_info.expect_val[i] == read_value) {
			break;
		}
	}

	if (i >= pinfo->lcd_panel_batch_info.cnt) {
		LCD_INFO("LHBM is not supported\n");
		pinfo->local_hbm_enabled = false;
	}

	if (pinfo->lhbm_adjust_light_enable && (read_value == 0x40 || read_value == 0x49)) {
		uint32_t rgb[3] = {0};
		int i;
		u8 *tmp;

		pinfo->lhbm_light_changed = true;
		pinfo->lhbm_light_origin = kzalloc(MAX_READ_LHBM_LIGHT_LENGTH + 1, GFP_KERNEL);
		tmp = pinfo->lhbm_light_origin;
		++tmp;
		pinfo->lhbm_light_origin[0] = 0xD0;
		rc = dsi_panel_receive_data(panel, DSI_CMD_READ_LHBM_LIGHT,
			tmp, MAX_READ_LHBM_LIGHT_LENGTH);
		if (rc) {
			LCD_ERR("read lhbm light reg failed\n");
			kfree(pinfo->lhbm_light_origin);
			pinfo->lhbm_light_changed = false;
			return rc;
		}

		pinfo->lhbm_light_adjust = kzalloc(MAX_READ_LHBM_LIGHT_LENGTH + 1, GFP_KERNEL);
		pinfo->lhbm_light_adjust[0] = 0xD0;
		for (i = 0; i < MAX_READ_LHBM_LIGHT_LENGTH / 2; i++) {
			rgb[i] = ((pinfo->lhbm_light_origin[i * 2 + 1] << 8 |
					pinfo->lhbm_light_origin[i * 2 + 2])) * 49 / 39;
			pinfo->lhbm_light_adjust[i * 2 + 1] = rgb[i] >> 8;
			pinfo->lhbm_light_adjust[i * 2 + 2] = rgb[i] & 0xFF;
		}
	}

	return rc;
}

static int read_2d_barcode(struct dsi_panel *panel, bool is_panel_locked)
{
	struct panel_info *pinfo = NULL;
	int rc = 0;

	pinfo = panel->pdata->pinfo;
	if (!pinfo) {
		LCD_ERR("pinfo is null\n");
		return LCD_FAIL;
	}
	if (!pinfo->oeminfo.barcode_2d.support)
		return rc;
	if (is_panel_locked) {
		rc = dsi_panel_receive_data_nolock(panel, DSI_CMD_READ_OEMINFO,
			pinfo->oeminfo.barcode_2d.barcode_data, OEM_INFO_SIZE_MAX - 1);
	} else {
		rc = dsi_panel_receive_data(panel, DSI_CMD_READ_OEMINFO,
			pinfo->oeminfo.barcode_2d.barcode_data, OEM_INFO_SIZE_MAX - 1);
	}
	if (rc) {
		LCD_ERR("read sn reg failed\n");
		return rc;
	}
	pinfo->oeminfo.barcode_2d.is_sn_read = true;
	LCD_INFO("barcode_data: %s\n", pinfo->oeminfo.barcode_2d.barcode_data);
	return rc;
}

static int panel_set_boot(struct dsi_panel *panel)
{
	struct panel_info *pinfo = NULL;

	if (!panel || !panel->pdata) {
		LCD_ERR("panel is null\n");
		return LCD_FAIL;
	}
	pinfo = panel->pdata->pinfo;
	if (!pinfo) {
		LCD_ERR("pinfo is null\n");
		return LCD_FAIL;
	}

	if (!pinfo->inited) {
		/* read panel sn code */
		read_sn_code(panel);
		/* read panel batch value */
		read_batch_match(panel);
		/* read 2d barcode */
		read_2d_barcode(panel, mutex_is_locked(&panel->panel_lock));
		pinfo->inited = true;
	}
	set_active_panel(pinfo, true);
	return 0;
}

struct panel_data g_panel_data = {
	.panel_init = panel_init,
	.panel_hbm_set = panel_hbm_set,
	.panel_hbm_fp_set = panel_hbm_fp_set,
	.on = panel_on,
	.off = panel_off,
	.print_bkl = print_backlight,
	.boot_set = panel_set_boot,
};
