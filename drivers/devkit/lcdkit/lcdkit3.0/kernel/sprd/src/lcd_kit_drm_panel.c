/*
 * lcd_kit_drm_panel.c
 *
 * lcdkit display function for lcd driver
 *
 * Copyright (c) 2019-2020 Honor Device Co., Ltd.
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
#include "lcd_kit_drm_panel.h"
#include <drm/drm_atomic_helper.h>
#include <linux/component.h>
#include <linux/backlight.h>
#include <linux/notifier.h>
#include <video/mipi_display.h>
#include <video/of_display_timing.h>
#include <video/videomode.h>
#include "sprd_panel.h"
#include "sprd_dpu.h"
#include "dsi/sprd_dsi_api.h"
#include "sysfs/sysfs_display.h"
#ifdef CONFIG_LOG_JANK
#include <honor_platform/log/hwlog_kernel.h>
#endif

#if defined CONFIG_HONOR_DSM
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

#define SPRD_MIPI_DSI_FMT_DSC 0xff
#define LCD_KIT_ESD_MAX 20
#define BL_MAX_STEP 5

static DEFINE_MUTEX(panel_lock);
unsigned int esd_recovery_level = 0;
static const unsigned int g_fps_90hz = 90;
static struct sprd_panel_info lcd_kit_info = {0};
static struct lcd_kit_disp_info g_lcd_kit_disp_info;
static struct blocking_notifier_head bl_level_notifier;

static inline struct sprd_panel *to_sprd_panel(struct drm_panel *panel)
{
	return container_of(panel, struct sprd_panel, base);
}

struct lcd_kit_disp_info *lcd_kit_get_disp_info(void)
{
	return &g_lcd_kit_disp_info;
}

#if defined CONFIG_HONOR_DSM
struct dsm_client *lcd_kit_get_lcd_dsm_client(void)
{
	return lcd_dclient;
}
#endif

struct sprd_panel_info *lcm_get_panel_info(void)
{
	return &lcd_kit_info;
}

struct mutex *lcm_get_panel_lock(void)
{
	return &panel_lock;
}

int is_mipi_cmd_panel(void)
{
	if (lcd_kit_info.panel_dsi_mode == 0)
		return 1;
	return 0;
}

static void lcd_kit_set_thp_proximity_state(int power_state)
{
	if (!common_info->thp_proximity.support) {
		LCD_KIT_INFO("thp_proximity not support!\n");
		return;
	}
	common_info->thp_proximity.panel_power_state = power_state;
}

static void lcd_kit_set_thp_proximity_sem(bool sem_lock)
{
	if (!common_info->thp_proximity.support) {
		LCD_KIT_INFO("thp_proximity not support!\n");
		return;
	}
	if (sem_lock == true)
		down(&disp_info->thp_second_poweroff_sem);
	else
		up(&disp_info->thp_second_poweroff_sem);
}

void lcm_set_panel_state(unsigned int state)
{
	lcd_kit_info.panel_state = state;
}

unsigned int lcm_get_panel_state(void)
{
	return lcd_kit_info.panel_state;
}

unsigned int lcm_get_panel_backlight_max_level(void)
{
	return lcd_kit_info.bl_max;
}

int lcm_rgbw_mode_set_param(struct drm_device *dev, void *data,
	struct drm_file *file_priv)
{
	int ret = LCD_KIT_OK;
	struct display_engine_ddic_rgbw_param *param = NULL;

	if (dev == NULL) {
		LCD_KIT_ERR("dev is null\n");
		return LCD_KIT_FAIL;
	}
	if (data == NULL) {
		LCD_KIT_ERR("data is null\n");
		return LCD_KIT_FAIL;
	}
	param = (struct display_engine_ddic_rgbw_param *)data;
	memcpy(&g_lcd_kit_disp_info.ddic_rgbw_param, param, sizeof(*param));
	ret = lcd_kit_rgbw_set_handle();
	if (ret < 0)
		LCD_KIT_ERR("set rgbw fail\n");
	return ret;
}

int lcm_rgbw_mode_get_param(struct drm_device *dev, void *data,
	struct drm_file *file_priv)
{
	int ret = LCD_KIT_OK;
	struct display_engine_ddic_rgbw_param *param = NULL;

	if (dev == NULL) {
		LCD_KIT_ERR("dev is null\n");
		return LCD_KIT_FAIL;
	}
	if (data == NULL) {
		LCD_KIT_ERR("data is null\n");
		return LCD_KIT_FAIL;
	}
	param = (struct display_engine_ddic_rgbw_param *)data;
	param->ddic_panel_id = g_lcd_kit_disp_info.ddic_rgbw_param.ddic_panel_id;
	param->ddic_rgbw_mode = g_lcd_kit_disp_info.ddic_rgbw_param.ddic_rgbw_mode;
	param->ddic_rgbw_backlight = g_lcd_kit_disp_info.ddic_rgbw_param.ddic_rgbw_backlight;
	param->pixel_gain_limit = g_lcd_kit_disp_info.ddic_rgbw_param.pixel_gain_limit;

	LCD_KIT_INFO("get RGBW parameters success\n");
	return ret;
}

int lcm_display_engine_get_panel_info(struct drm_device *dev, void *data,
	struct drm_file *file_priv)
{
	int ret = LCD_KIT_OK;
	struct display_engine_panel_info_param *param = NULL;

	if (dev == NULL) {
		LCD_KIT_ERR("dev is null\n");
		return LCD_KIT_FAIL;
	}
	if (data == NULL) {
		LCD_KIT_ERR("data is null\n");
		return LCD_KIT_FAIL;
	}
	param = (struct display_engine_panel_info_param *)data;
	param->width = lcd_kit_info.xres;
	param->height = lcd_kit_info.yres;
	param->maxluminance = lcd_kit_info.maxluminance;
	param->minluminance = lcd_kit_info.minluminance;
	param->maxbacklight = lcd_kit_info.bl_max;
	param->minbacklight = lcd_kit_info.bl_min;

	LCD_KIT_INFO("get panel info parameters success\n");
	return ret;
}

int lcm_display_engine_init(struct drm_device *dev, void *data,
	struct drm_file *file_priv)
{
	int ret = LCD_KIT_OK;
	struct display_engine *param = NULL;

	if (dev == NULL) {
		LCD_KIT_ERR("dev is null\n");
		return LCD_KIT_FAIL;
	}
	if (data == NULL) {
		LCD_KIT_ERR("data is null\n");
		return LCD_KIT_FAIL;
	}
	param = (struct display_engine *)data;
	/* 0:no support  1:support */
	if (g_lcd_kit_disp_info.rgbw.support == 0)
		param->ddic_rgbw_support = 0;
	else
		param->ddic_rgbw_support = 1;

	LCD_KIT_INFO("display engine init success\n");
	return ret;
}

int lcd_kit_init(void)
{
	int ret = LCD_KIT_OK;
	struct device_node *np = NULL;

	LCD_KIT_INFO("enter\n");
	if (!lcd_kit_support()) {
		LCD_KIT_INFO("not lcd_kit driver and return\n");
		return ret;
	}

	np = of_find_compatible_node(NULL, NULL, DTS_COMP_LCD_KIT_PANEL_TYPE);
	if (np == NULL) {
		LCD_KIT_ERR("not find device node %s\n", DTS_COMP_LCD_KIT_PANEL_TYPE);
		ret = -1;
		return ret;
	}

	OF_PROPERTY_READ_U32_RETURN(np, "product_id", &disp_info->product_id);
	LCD_KIT_INFO("product_id = %d\n", disp_info->product_id);
	disp_info->compatible = (char *)of_get_property(np, "lcd_panel_type", NULL);
	if (!disp_info->compatible) {
		LCD_KIT_ERR("can not get lcd kit compatible\n");
		return ret;
	}
	LCD_KIT_INFO("compatible: %s\n", disp_info->compatible);

	np = of_find_compatible_node(NULL, NULL, disp_info->compatible);
	if (!np) {
		LCD_KIT_ERR("NOT FOUND device node %s!\n", disp_info->compatible);
		ret = -1;
		return ret;
	}

#if defined CONFIG_HONOR_DSM
	lcd_dclient = dsm_register_client(&dsm_lcd);
#endif
	/* adapt init */
	lcd_kit_adapt_init();
	bias_bl_ops_init();
	/* common init */
	if (common_ops->common_init)
		common_ops->common_init(np);
	/* utils init */
	lcd_kit_utils_init(np, &lcd_kit_info);
	/* init fnode */
	lcd_kit_sysfs_init();
	/* init panel ops */
	lcd_kit_panel_init();
	/* get lcd max brightness */
	lcd_kit_get_bl_max_nit_from_dts();

	lcm_set_panel_state(LCD_POWER_STATE_ON);
	lcd_kit_set_thp_proximity_state(POWER_ON);

	if (common_ops->btb_init) {
		common_ops->btb_init();
		if (common_info->btb_check_type == LCD_KIT_BTB_CHECK_GPIO)
			common_ops->btb_check();
	}

	LCD_KIT_INFO("exit\n");
	return ret;
}

static int panel_get_modes(struct drm_panel *p)
{
	struct drm_display_mode *mode = NULL;
	struct sprd_panel *panel = to_sprd_panel(p);
	int i;
	int mode_count = 0;

	LCD_KIT_INFO("%s()\n", __func__);
		LCD_KIT_INFO("clock %d\n", panel->info.mode.clock);
		LCD_KIT_INFO("hdisplay %d\n", panel->info.mode.hdisplay);
		LCD_KIT_INFO("hsync_start %d\n", panel->info.mode.hsync_start);
		LCD_KIT_INFO("hsync_end %d\n", panel->info.mode.hsync_end);
		LCD_KIT_INFO("htotal %d\n", panel->info.mode.htotal);
		LCD_KIT_INFO("vdisplay %d\n", panel->info.mode.vdisplay);
		LCD_KIT_INFO("vsync_start %d\n", panel->info.mode.vsync_start);
		LCD_KIT_INFO("vsync_end %d\n", panel->info.mode.vsync_end);
		LCD_KIT_INFO("vtotal %d\n", panel->info.mode.vtotal);
				LCD_KIT_INFO("vrefresh %d\n", panel->info.mode.vrefresh);
	mode = drm_mode_duplicate(p->drm, &panel->info.mode);
	if (mode == NULL) {
		LCD_KIT_ERR("failed to alloc mode %s\n", panel->info.mode.name);
		return 0;
	}
	mode->type = DRM_MODE_TYPE_DRIVER | DRM_MODE_TYPE_PREFERRED;
	drm_mode_probed_add(p->connector, mode);
	mode_count++;

	for (i = 1; i < panel->info.num_buildin_modes; i++)	{
		mode = drm_mode_duplicate(p->drm,
			&(panel->info.buildin_modes[i]));
		if (mode == NULL) {
			LCD_KIT_ERR("failed to alloc mode %s\n",
				panel->info.buildin_modes[i].name);
			return 0;
		}
		mode->type = DRM_MODE_TYPE_DRIVER | DRM_MODE_TYPE_DEFAULT;
		drm_mode_probed_add(p->connector, mode);
		mode_count++;
	}

	if (lcd_kit_info.surface_width && lcd_kit_info.surface_height) {
		struct videomode vm = {};

		vm.hactive = lcd_kit_info.surface_width;
		vm.vactive = lcd_kit_info.surface_height;
		vm.pixelclock = lcd_kit_info.surface_width *
			lcd_kit_info.surface_height * 60;

		mode = drm_mode_create(p->drm);

		mode->type = DRM_MODE_TYPE_DRIVER | DRM_MODE_TYPE_BUILTIN |
			DRM_MODE_TYPE_CRTC_C;
		mode->vrefresh = 60;
		drm_display_mode_from_videomode(&vm, mode);
		drm_mode_probed_add(p->connector, mode);
		mode_count++;
	}

	p->connector->display_info.width_mm = panel->info.mode.width_mm;
	p->connector->display_info.height_mm = panel->info.mode.height_mm;

	return mode_count;
}

static int panel_prepare(struct drm_panel *p)
{
	struct sprd_panel *panel = to_sprd_panel(p);

	LCD_KIT_INFO("enter\n");
	if (panel == NULL) {
		LCD_KIT_ERR("sprd panel is null\n");
		return LCD_KIT_OK;
	}

	LCD_KIT_INFO("lcd: %s\n", disp_info->compatible);
	lcd_kit_set_thp_proximity_sem(true);
	if (common_ops->panel_power_on)
		common_ops->panel_power_on(panel->slave);
	lcm_set_panel_state(LCD_POWER_STATE_ON);
	lcd_kit_set_thp_proximity_state(POWER_ON);

	lcd_kit_set_thp_proximity_sem(false);
#ifdef CONFIG_LOG_JANK
	LOG_JANK_D(JLID_KERNEL_LCD_POWER_ON, "%s", "LCD_POWER_ON");
#endif
	/* btb check */
	if (common_ops->btb_check &&
		common_info->btb_check_type == LCD_KIT_BTB_CHECK_GPIO)
		common_ops->btb_check();
	LCD_KIT_INFO("exit\n");
	return LCD_KIT_OK;
}

static int panel_enable(struct drm_panel *p)
{
	struct sprd_panel *panel = to_sprd_panel(p);

	LCD_KIT_INFO("enter\n");
	if (panel == NULL) {
		LCD_KIT_ERR("sprd panel is null\n");
		return LCD_KIT_OK;
	}

	mutex_lock(&panel_lock);
	if (common_ops->panel_on_lp)
		common_ops->panel_on_lp(panel->slave);
	if (panel->info.esd_check_en) {
		schedule_delayed_work(&panel->esd_work,
				      msecs_to_jiffies(panel->info.esd_check_period));
		panel->esd_work_pending = true;
		panel->esd_work_backup = false;
	}
	panel->is_enabled = true;
	mutex_unlock(&panel_lock);

	/* record panel on time */
	if (disp_info->quickly_sleep_out.support)
		lcd_kit_disp_on_record_time();
	LCD_KIT_INFO("exit\n");

	return LCD_KIT_OK;
}

static int panel_disable(struct drm_panel *p)
{
	struct sprd_panel *panel = to_sprd_panel(p);

	LCD_KIT_INFO("enter\n");
	if (panel == NULL) {
		LCD_KIT_ERR("sprd panel is null\n");
		return LCD_KIT_OK;
	}

	/*
	 * FIXME:
	 * The cancel work should be executed before DPU stop,
	 * otherwise the esd check will be failed if the DPU
	 * stopped in video mode and the DSI has not change to
	 * CMD mode yet. Since there is no VBLANK timing for
	 * LP cmd transmission.
	 */
	if (panel->esd_work_pending) {
		cancel_delayed_work_sync(&panel->esd_work);
		panel->esd_work_pending = false;
	}

	mutex_lock(&panel_lock);
	if (common_ops->panel_off_lp)
			common_ops->panel_off_lp(panel->slave);
	panel->is_enabled = false;
	mutex_unlock(&panel_lock);
	LCD_KIT_INFO("exit\n");

	return LCD_KIT_OK;
}

static int panel_unprepare(struct drm_panel *p)
{
	struct sprd_panel *panel = to_sprd_panel(p);

	LCD_KIT_INFO("enter\n");
	lcd_kit_set_thp_proximity_sem(true);
	lcm_set_panel_state(LCD_POWER_STATE_OFF);
	if (common_ops->panel_power_off)
		common_ops->panel_power_off(panel->slave);
	lcd_kit_set_thp_proximity_state(POWER_OFF);
	lcd_kit_set_thp_proximity_sem(false);
#ifdef CONFIG_LOG_JANK
	LOG_JANK_D(JLID_KERNEL_LCD_POWER_OFF, "%s", "LCD_POWER_OFF");
#endif
	LCD_KIT_INFO("exit\n");

	return LCD_KIT_OK;
}

static const struct drm_panel_funcs panel_funcs = {
	.get_modes = panel_get_modes,
	.enable = panel_enable,
	.disable = panel_disable,
	.prepare = panel_prepare,
	.unprepare = panel_unprepare,
};

static int lcd_kit_bl_ic_set_backlight(unsigned int bl_level)
{
	struct lcd_kit_bl_ops *bl_ops = NULL;

	bl_ops = lcd_kit_get_bl_ops();
	if (!bl_ops) {
		LCD_KIT_INFO("bl_ops is null!\n");
		return LCD_KIT_FAIL;
	}
	if (bl_ops->set_backlight)
		bl_ops->set_backlight(bl_level);
	return LCD_KIT_OK;
}

static int lcd_kit_dsi_panel_update_backlight(struct sprd_panel *panel,
	unsigned int level)
{
	ssize_t ret = 0;
	struct mipi_dsi_device *dsi = NULL;
	unsigned char bl_tb_short[] = { 0x51, 0xFF };
	unsigned char bl_tb_long[] = { 0x51, 0xFF, 0xFF };

	if (!panel || (level > 0xffff)) {
		LCD_KIT_ERR("invalid params\n");
		return -EINVAL;
	}
	dsi = panel->slave;
	if (dsi == NULL) {
		LCD_KIT_ERR("dsi is NULL\n");
		return -EINVAL;
	}
	switch (common_info->backlight.order) {
	case BL_BIG_ENDIAN:
		if (common_info->backlight.bl_max <= 0xFF) {
			common_info->backlight.bl_cmd.cmds[0].payload[1] = level;
		} else {
			/* change bl level to dsi cmds */
			common_info->backlight.bl_cmd.cmds[0].payload[1] =
				(level >> 8) & 0xFF;
			common_info->backlight.bl_cmd.cmds[0].payload[2] =
				level & 0xFF;
		}
		break;
	case BL_LITTLE_ENDIAN:
		if (common_info->backlight.bl_max <= 0xFF) {
			common_info->backlight.bl_cmd.cmds[0].payload[1] = level;
		} else {
			/* change bl level to dsi cmds */
			common_info->backlight.bl_cmd.cmds[0].payload[1] =
				level & 0xFF;
			common_info->backlight.bl_cmd.cmds[0].payload[2] =
				(level >> 8) & 0xFF;
		}
		break;
	default:
		LCD_KIT_ERR("not support order\n");
		break;
	}
	if(common_info->backlight.bl_max <= 0xFF) {
		bl_tb_short[0] = common_info->backlight.bl_cmd.cmds[0].payload[0];
		bl_tb_short[1] = common_info->backlight.bl_cmd.cmds[0].payload[1];
		if (panel->info.use_dcs)
			mipi_dsi_dcs_write_buffer(dsi, bl_tb_short, sizeof(bl_tb_short));
		else
			mipi_dsi_generic_write(dsi, bl_tb_short, sizeof(bl_tb_short));
	} else {
		bl_tb_long[0] = common_info->backlight.bl_cmd.cmds[0].payload[0];
		bl_tb_long[1] = common_info->backlight.bl_cmd.cmds[0].payload[1];
		bl_tb_long[2] = common_info->backlight.bl_cmd.cmds[0].payload[2];
		if (panel->info.use_dcs)
			mipi_dsi_dcs_write_buffer(dsi, bl_tb_long, sizeof(bl_tb_long));
		else
			mipi_dsi_generic_write(dsi, bl_tb_long, sizeof(bl_tb_long));
	}
	if (ret < 0)
		LCD_KIT_ERR("failed to update dcs backlight:%d\n", level);
	return ret;
}

int lcd_kit_get_cur_backlight_level(void)
{
	int cur_level = common_info->bl_level_max;

	if (lcd_kit_info.bldev != NULL) {
		mutex_lock(&lcd_kit_info.bldev->update_lock);
		cur_level = lcd_kit_info.bldev->props.brightness;
		mutex_unlock(&lcd_kit_info.bldev->update_lock);
	}
	return cur_level;
}
EXPORT_SYMBOL(lcd_kit_get_cur_backlight_level);

int backlight_level_notifier_register(struct notifier_block *nb)
{
        return blocking_notifier_chain_register(&bl_level_notifier, nb);
}
EXPORT_SYMBOL(backlight_level_notifier_register);

int backlight_level_notifier_unregister(struct notifier_block *nb)
{
        return blocking_notifier_chain_unregister(&bl_level_notifier, nb);
}
EXPORT_SYMBOL(backlight_level_notifier_unregister);


int lcd_kit_get_max_backlight_level(void)
{
	return common_info->bl_level_max;
}

int lcd_kit_cabc_backlight_update(int level)
{
	int rc = 0;
	struct sprd_panel *panel = NULL;
	static int last_level = 0xFFFFFF;

	if (lcd_kit_info.bldev == NULL) {
		LCD_KIT_ERR("backlight device is NULL\n");
		return rc;
	}
	panel = bl_get_data(lcd_kit_info.bldev);
	if (panel == NULL) {
		LCD_KIT_ERR("panel is NULL\n");
		return rc;
	}
	if (last_level == level)
		return rc;
	LCD_KIT_INFO("cabc brightness is %d\n", level);
	last_level = level;
	mutex_lock(&lcd_kit_info.bldev->update_lock);
	switch (lcd_kit_info.bl_set_type) {
	case DSI_BACKLIGHT_DCS:
		rc = lcd_kit_dsi_panel_update_backlight(panel, level);
		break;
	case DSI_BACKLIGHT_PWM:
		//rc = dsi_panel_update_pwm_backlight(panel, level);
		break;
	case DSI_BACKLIGHT_I2C_IC:
		rc = lcd_kit_bl_ic_set_backlight(level);
		break;
	case DSI_BACKLIGHT_DCS_I2C_IC:
		rc = lcd_kit_dsi_panel_update_backlight(panel, level);
		rc = lcd_kit_bl_ic_set_backlight(level);
		break;
	default:
		LCD_KIT_ERR("Backlight type(%d) not supported\n", lcd_kit_info.bl_set_type);
		rc = -ENOTSUPP;
		break;
	}
	mutex_unlock(&lcd_kit_info.bldev->update_lock);
	return rc;
}

static int lcd_kit_backlight_update(struct backlight_device *bd)
{
	int bl_lvl;
    int rc = 0;
	static last_level = 0;
#if defined(CONFIG_LOG_JANK)
	static uint32_t jank_last_bl_level;
#endif
	struct sprd_panel *panel = NULL;

	if (bd == NULL) {
		LCD_KIT_ERR("backlight device is NULL\n");
		return rc;
	}
	panel = bl_get_data(bd);
	if (panel == NULL) {
		LCD_KIT_ERR("panel is NULL\n");
		return rc;
	}
	bl_lvl = bd->props.brightness;
	if (bl_lvl > last_level) {
		if (bl_lvl - last_level > BL_MAX_STEP)
			LCD_KIT_INFO("last brightness is %d cur brightness is %d\n", last_level, bd->props.brightness);
	} else if (bl_lvl < last_level) {
		if (last_level - bl_lvl > BL_MAX_STEP)
			LCD_KIT_INFO("last brightness is %d cur brightness is %d\n", last_level, bd->props.brightness);
	}
	last_level = bl_lvl;
#if defined(CONFIG_LOG_JANK)
	if ((jank_last_bl_level == 0) && (bl_lvl != 0)) {
		LOG_JANK_D(JLID_KERNEL_LCD_BACKLIGHT_ON, "LCD_BACKLIGHT_ON,%u", bl_lvl);
		jank_last_bl_level = bl_lvl;
	} else if ((bl_lvl == 0) && (jank_last_bl_level != 0)) {
		LOG_JANK_D(JLID_KERNEL_LCD_BACKLIGHT_OFF, "LCD_BACKLIGHT_OFF");
		jank_last_bl_level = bl_lvl;
	}
#endif

	if (disp_info->quickly_sleep_out.support) {
		if (disp_info->quickly_sleep_out.panel_on_tag &&
			bl_lvl > 0)
			lcd_kit_disp_on_check_delay();
		}
	if (bl_lvl > 0)
		panel->esd_recovery_bl_level = bl_lvl;

	blocking_notifier_call_chain(&bl_level_notifier, bl_lvl, bd);
	switch (lcd_kit_info.bl_set_type) {
	case DSI_BACKLIGHT_DCS:
		rc = lcd_kit_dsi_panel_update_backlight(panel, bl_lvl);
		break;
	case DSI_BACKLIGHT_PWM:
		//rc = dsi_panel_update_pwm_backlight(panel, bl_lvl);
		break;
	case DSI_BACKLIGHT_I2C_IC:
		rc = lcd_kit_bl_ic_set_backlight(bl_lvl);
		break;
	case DSI_BACKLIGHT_DCS_I2C_IC:
		rc = lcd_kit_dsi_panel_update_backlight(panel, bl_lvl);
		rc = lcd_kit_bl_ic_set_backlight(bl_lvl);
		break;
	default:
		LCD_KIT_ERR("Backlight type(%d) not supported\n", lcd_kit_info.bl_set_type);
		rc = -ENOTSUPP;
		break;
	}

	return rc;
}

static const struct backlight_ops backlight_ops = {
	.update_status = lcd_kit_backlight_update,
};

static int lcd_kit_backlight_setup(struct sprd_panel *panel,
	struct device *dev)
{
	struct backlight_properties props;

	props.type = BACKLIGHT_RAW;
	props.power = FB_BLANK_UNBLANK;
	props.max_brightness = common_info->bl_level_max;
	props.brightness = common_info->bl_level_max;

	panel->backlight = devm_backlight_device_register(dev,
			"sprd_backlight", dev, panel,
			&backlight_ops, &props);
	if (IS_ERR(panel->backlight)) {
		LCD_KIT_ERR("failed to register backlight ops\n");
		return PTR_ERR(panel->backlight);
	}
	lcd_kit_info.bldev = panel->backlight;
	return LCD_KIT_OK;
}

static int of_parse_buildin_modes(struct panel_info *info,
	struct device_node *lcd_node)
{
	int i;
	int ret;
	int num_timings;
	struct device_node *timings_np = NULL;


	timings_np = of_get_child_by_name(lcd_node, "display-timings");
	if (timings_np == NULL) {
		LCD_KIT_ERR("can not find display-timings node\n");
		return -ENODEV;
	}

	num_timings = of_get_child_count(timings_np);
	if (num_timings == 0) {
		LCD_KIT_ERR("no timings specified\n");
		goto done;
	}

	info->buildin_modes = kzalloc(sizeof(struct drm_display_mode) *
				num_timings, GFP_KERNEL);
	if (info->buildin_modes == NULL) {
		LCD_KIT_ERR("timngs alloc mem fail\n");
		goto done;
	}

	for (i = 0; i < num_timings; i++) {
		ret = of_get_drm_display_mode(lcd_node,
			&info->buildin_modes[i], NULL, i);
		if (ret) {
			LCD_KIT_ERR("get display timing failed\n");
			goto entryfail;
		}

		info->buildin_modes[i].width_mm = info->mode.width_mm;
		info->buildin_modes[i].height_mm = info->mode.height_mm;
		info->buildin_modes[i].vrefresh = info->mode.vrefresh;
	}
	info->num_buildin_modes = num_timings;
	LCD_KIT_INFO("info->num_buildin_modes = %d\n", num_timings);
	goto done;

entryfail:
	kfree(info->buildin_modes);
done:
	of_node_put(timings_np);

	return LCD_KIT_OK;
}

static void panel_init_drm_mipi(struct sprd_panel *panel)
{
	struct sprd_panel_info *pinfo = &lcd_kit_info;
	int rc;

	if (panel == NULL) {
		LCD_KIT_ERR("panel is null\n");
		return;
	}
	panel->info.of_node = pinfo->np;
	LCD_KIT_ERR("of_node is %p\n", pinfo->np);
	panel->info.lanes = pinfo->mipi.lane_nums;
	switch (pinfo->mipi.dsi_color_format) {
	case PIXEL_24BIT_RGB888:
		panel->info.format = MIPI_DSI_FMT_RGB888;
		break;
	case LOOSELY_PIXEL_18BIT_RGB666:
		panel->info.format = MIPI_DSI_FMT_RGB666;
		break;
	case PACKED_PIXEL_18BIT_RGB666:
		panel->info.format = MIPI_DSI_FMT_RGB666_PACKED;
		break;
	case PIXEL_16BIT_RGB565:
		panel->info.format = MIPI_DSI_FMT_RGB565;
		break;
	case PIXEL_SPRD_DSC:
		panel->info.format = SPRD_MIPI_DSI_FMT_DSC;
		break;
	default:
		panel->info.format = MIPI_DSI_FMT_RGB888;
		break;
	}
	switch (pinfo->panel_dsi_mode) {
	case DSI_CMD_MODE:
		panel->info.mode_flags = 0;
		break;
	case DSI_SYNC_PULSE_VDO_MODE:
		panel->info.mode_flags = MIPI_DSI_MODE_VIDEO;
		panel->info.mode_flags |= MIPI_DSI_MODE_VIDEO_SYNC_PULSE;
		break;
	case DSI_SYNC_EVENT_VDO_MODE:
		panel->info.mode_flags = MIPI_DSI_MODE_VIDEO;
		break;
	case DSI_BURST_VDO_MODE:
		panel->info.mode_flags = MIPI_DSI_MODE_VIDEO;
		panel->info.mode_flags |= MIPI_DSI_MODE_VIDEO_BURST;
		break;
	default:
		panel->info.mode_flags = MIPI_DSI_MODE_VIDEO;
		panel->info.mode_flags |= MIPI_DSI_MODE_VIDEO_BURST;
		break;
	}
	if (pinfo->mipi.non_continue_en)
		panel->info.mode_flags |= MIPI_DSI_CLOCK_NON_CONTINUOUS;
	panel->info.mode.width_mm = pinfo->width;
	panel->info.mode.height_mm = pinfo->height;
	if (pinfo->mipi.use_dcs)
		panel->info.use_dcs = true;
	else
		panel->info.use_dcs = false;

	rc = of_get_drm_display_mode(pinfo->np, &panel->info.mode, 0,
				     OF_USE_NATIVE_MODE);
	if (rc) {
		LCD_KIT_ERR("get display timing failed\n");
		return;
	}
	panel->info.mode.vrefresh = drm_mode_vrefresh(&panel->info.mode);
	of_parse_buildin_modes(&panel->info, pinfo->np);
}

/*
 * FIXME:
 * Adding the following interfaces is just for fbdev emulation support.
 * Put panel into component match lists. drm just bind after panel probe.
 */
static int sprd_panel_bind(struct device *dev,
			struct device *master, void *data)
{
	/* do nothing */
	LCD_KIT_INFO("%s()\n", __func__);
	return LCD_KIT_OK;
}

static void sprd_panel_unbind(struct device *dev,
			struct device *master, void *data)
{
	/* do nothing */
	LCD_KIT_INFO("%s()\n", __func__);
}

static const struct component_ops panel_component_ops = {
	.bind	= sprd_panel_bind,
	.unbind	= sprd_panel_unbind,
};

static int panel_device_create(struct device *parent,
				    struct sprd_panel *panel)
{
	panel->dev.class = display_class;
	panel->dev.parent = parent;
	panel->dev.of_node = panel->info.of_node;
	dev_set_name(&panel->dev, "panel0");
	dev_set_drvdata(&panel->dev, panel);
	LCD_KIT_ERR("of_node is %p\n", panel->dev.of_node);

	return device_register(&panel->dev);
}

static int lcd_kit_panel_esd_check(struct sprd_panel *panel)
{
	struct panel_info *info = NULL;
	unsigned char read_len = 0;
	unsigned char offset = 0;
	unsigned char i = 0;
	unsigned char j = 0;
	unsigned char read_buf[MAX_ID_REG_SIZE] = {0xff};

	if (panel == NULL) {
		LCD_KIT_ERR("esd: input panel is NULL\n");
		return LCD_KIT_OK;
	}
	info = &panel->info;
	mutex_lock(&panel_lock);
	if (!panel->is_enabled) {
		LCD_KIT_INFO("panel is not enabled, skip esd check\n");
		mutex_unlock(&panel_lock);
		return 0;
	}
	mipi_dsi_set_maximum_return_packet_size(panel->slave, MAX_ID_REG_SIZE);
	for (i = 0; i < info->esd.reg_items; i++) {
		memset(read_buf, 0xff, sizeof(read_buf));
		read_len = mipi_dsi_dcs_read(panel->slave, info->esd.reg_seq[i],
					     read_buf, info->esd.read_len[i]);
		if(read_len <= 0) {
			LCD_KIT_ERR("mipi dsi read no data: %d\n",  read_len);
			mutex_unlock(&panel_lock);
			return 0;
		}

		for(j = 0; j < info->esd.read_len[i]; j++) {
			if (info->esd.val_seq[offset] != read_buf[j]) {
				LCD_KIT_ERR("val_seq is 0x%x, read_buf is 0x%x\n",
					info->esd.val_seq[offset], read_buf[j]);
				mutex_unlock(&panel_lock);
#if defined(CONFIG_HONOR_DSM)
				if (lcd_dclient && !dsm_client_ocuppy(lcd_dclient)) {
					dsm_client_record(lcd_dclient,
						"lcd esd recovery, value is 0x%x, but read is 0x%x\n",
						info->esd.val_seq[offset], read_buf[j]);
					dsm_client_notify(lcd_dclient, DSM_LCD_ESD_STATUS_ERROR_NO);
				}
#endif
				return -EINVAL;
			}
			offset++;
		}
	}
	mutex_unlock(&panel_lock);

	return LCD_KIT_OK;
}

static int lcd_kit_panel_te_check(struct sprd_panel *panel)
{
	static int te_wq_inited;
	struct sprd_dpu *dpu = NULL;
	int ret;
	bool irq_occur = false;

	if (!panel ||
		!panel->base.connector ||
	    !panel->base.connector->encoder ||
	    !panel->base.connector->encoder->crtc) {
		return 0;
	}

	dpu = container_of(panel->base.connector->encoder->crtc,
		struct sprd_dpu, crtc);

	if (!te_wq_inited) {
		init_waitqueue_head(&dpu->ctx.te_wq);
		te_wq_inited = 1;
		dpu->ctx.evt_te = false;
		LCD_KIT_INFO("%s init te waitqueue\n", __func__);
	}

	/* DPU TE irq maybe enabled in kernel */
	if (!dpu->ctx.is_inited)
		return 0;

	dpu->ctx.te_check_en = true;

	/* wait for TE interrupt */
	ret = wait_event_interruptible_timeout(dpu->ctx.te_wq,
		dpu->ctx.evt_te, msecs_to_jiffies(500));
	if (!ret) {
		/* double check TE interrupt through dpu_int_raw register */
		if (dpu->core && dpu->core->check_raw_int) {
			down(&dpu->ctx.refresh_lock);
			if (dpu->ctx.is_inited)
				irq_occur = dpu->core->check_raw_int(&dpu->ctx,
					DISPC_INT_TE_MASK);
			up(&dpu->ctx.refresh_lock);
			if (!irq_occur) {
				LCD_KIT_ERR("TE esd timeout.\n");
				ret = -1;
			} else
				LCD_KIT_ERR("TE occur, but isr schedule delay\n");
		} else {
			LCD_KIT_ERR("TE esd timeout.\n");
			ret = -1;
		}
	}

	dpu->ctx.te_check_en = false;
	dpu->ctx.evt_te = false;

	return ret < 0 ? ret : 0;
}

static void lcd_kit_panel_esd_work_func(struct work_struct *work)
{
	struct sprd_panel *panel = container_of(work, struct sprd_panel,
						esd_work.work);
	struct panel_info *info = &panel->info;
	int ret;
	static int esd_fail_count = 0;

	LCD_KIT_INFO("esd work enter\n");
	if (info->esd_check_mode == ESD_MODE_REG_CHECK) {
		ret = lcd_kit_panel_esd_check(panel);
	} else if (info->esd_check_mode == ESD_MODE_TE_CHECK) {
		ret = lcd_kit_panel_te_check(panel);
	} else {
		LCD_KIT_ERR("unknown esd check mode:%d\n", info->esd_check_mode);
		return;
	}

	if (ret && panel->base.connector && panel->base.connector->encoder) {
		const struct drm_encoder_helper_funcs *funcs = NULL;
		struct drm_encoder *encoder = NULL;

		encoder = panel->base.connector->encoder;
		funcs = encoder->helper_private;
		panel->esd_work_pending = false;

		if (!encoder || !funcs) {
			LCD_KIT_ERR("encoder or funcs is NULL\n");
		}

		if (!encoder->crtc || (encoder->crtc->state &&
		    !encoder->crtc->state->active)) {
		    panel->esd_work_backup = true;
			LCD_KIT_INFO("skip esd recovery during panel suspend\n");
			return;
		}

		esd_fail_count++;
		if (esd_fail_count >= LCD_KIT_ESD_MAX) {
			LCD_KIT_ERR("esd continue fail %d, so disable esd function\n", esd_fail_count);
			panel->info.esd_check_en = false;
			return;
		}
		LCD_KIT_INFO("esd recovery start\n");
		funcs->disable(encoder);
		funcs->enable(encoder);
		if (!panel->esd_work_pending && panel->is_enabled)
			schedule_delayed_work(&panel->esd_work,
				msecs_to_jiffies(info->esd_check_period));
		if (panel->backlight && encoder->crtc && encoder->crtc->state &&
			encoder->crtc->state->active) {
			panel->backlight->props.brightness = panel->esd_recovery_bl_level;
			backlight_update_status(panel->backlight);
		}
		LCD_KIT_INFO("esd recovery end\n");
	} else {
		esd_fail_count = 0;
		schedule_delayed_work(&panel->esd_work,
			msecs_to_jiffies(info->esd_check_period));
	}
}

static void lcd_kit_set_esd_config(struct sprd_panel *panel)
{
	int i;
	struct lcd_kit_dsi_cmd_desc *esd_cmds = NULL;
	u8 *tmp_buffer = NULL;
	u8 *len_buffer = NULL;

	if (panel == NULL) {
		LCD_KIT_ERR("panel is null\n");
		return;
	}

	if (common_info->esd.support)
		panel->info.esd_check_en = true;
	else
		panel->info.esd_check_en = false;

	panel->info.esd_check_mode = (u8)common_info->esd.esd_check_mode;
	panel->info.esd_check_period = (u16)common_info->esd.esd_check_period;

	LCD_KIT_INFO("set esd config\n");
	if (common_info->esd.cmds.cmds == NULL) {
		LCD_KIT_INFO("esd not config, use default\n");
		tmp_buffer = (u8 *)kzalloc(sizeof(char), GFP_KERNEL);
		if (tmp_buffer == NULL) {
			LCD_KIT_ERR("reg_seq kzalloc fail\n");
			return;
		}
		*tmp_buffer = 0x0A;
		panel->info.esd.reg_seq = tmp_buffer;
		panel->info.esd.reg_items = 1;
		tmp_buffer = (u8 *)kzalloc(sizeof(char), GFP_KERNEL);
		if (tmp_buffer == NULL) {
			LCD_KIT_ERR("val_seq kzalloc fail\n");
			kfree(panel->info.esd.reg_seq);
			panel->info.esd.reg_seq = NULL;
			return;
		}
		*tmp_buffer = 0x9C;
		panel->info.esd.val_seq = tmp_buffer;
		tmp_buffer = (u8 *)kzalloc(sizeof(char), GFP_KERNEL);
		if (tmp_buffer == NULL) {
			LCD_KIT_ERR("val_seq kzalloc fail\n");
			kfree(panel->info.esd.reg_seq);
			panel->info.esd.reg_seq = NULL;
			kfree(panel->info.esd.val_seq);
			panel->info.esd.val_seq = NULL;
			return;
		}
		*tmp_buffer = 1;
		panel->info.esd.read_len = tmp_buffer;
		return;
	}

	tmp_buffer = (u8 *)kzalloc(sizeof(char) * common_info->esd.cmds.cmd_cnt,
		GFP_KERNEL);
	if (tmp_buffer == NULL) {
		LCD_KIT_ERR("reg_seq kzalloc fail\n");
		return;
	}
	len_buffer = (u8 *)kzalloc(sizeof(char) * common_info->esd.cmds.cmd_cnt,
		GFP_KERNEL);
	if (len_buffer == NULL) {
		LCD_KIT_ERR("len_buffer kzalloc fail\n");
		kfree(tmp_buffer);
		return;
	}
	esd_cmds = common_info->esd.cmds.cmds;
	for (i = 0; i < common_info->esd.cmds.cmd_cnt; i++) {
		*(tmp_buffer + i) = esd_cmds->payload[0];
		*(len_buffer + i) = esd_cmds->dlen;
		esd_cmds++;
	}
	panel->info.esd.reg_seq = tmp_buffer;
	panel->info.esd.read_len = len_buffer;
	panel->info.esd.reg_items = common_info->esd.cmds.cmd_cnt;
	tmp_buffer = (u8 *)kzalloc(sizeof(char) * common_info->esd.value.cnt,
		GFP_KERNEL);
	if (tmp_buffer == NULL) {
		LCD_KIT_ERR("val_seq kzalloc fail\n");
		kfree(panel->info.esd.reg_seq);
		panel->info.esd.reg_seq = NULL;
		kfree(panel->info.esd.read_len);
		panel->info.esd.read_len = NULL;
		return;
	}
	for (i = 0; i < common_info->esd.value.cnt; i++)
		*(tmp_buffer + i) = common_info->esd.value.buf[i] & 0xFF;
	panel->info.esd.val_seq = tmp_buffer;
	if (common_info->bl_level_max > 0)
		panel->esd_recovery_bl_level = common_info->bl_level_max;
	else
		panel->esd_recovery_bl_level = 255;
}

static int lcm_probe(struct mipi_dsi_device *slave)
{
	struct device *dev = &slave->dev;
	struct sprd_panel *panel = NULL;
	int ret;

	LCD_KIT_INFO("enter\n");
	panel = devm_kzalloc(dev, sizeof(struct sprd_panel), GFP_KERNEL);
	if (!panel)
		return -ENOMEM;

	INIT_DELAYED_WORK(&panel->esd_work, lcd_kit_panel_esd_work_func);
	panel_init_drm_mipi(panel);
	ret = panel_device_create(&slave->dev, panel);
	if (ret) {
		LCD_KIT_ERR("panel device create failed\n");
		return ret;
	}
	ret = lcd_kit_backlight_setup(panel, &slave->dev);
	if (ret) {
		LCD_KIT_ERR("backlight setup failed\n");
		return ret;
	}

	panel->base.dev = &panel->dev;
	panel->base.funcs = &panel_funcs;
	drm_panel_init(&panel->base);

	ret = drm_panel_add(&panel->base);
	if (ret) {
		LCD_KIT_ERR("drm_panel_add() failed\n");
		return ret;
	}
	slave->lanes = lcd_kit_info.mipi.lane_nums;
	slave->format = lcd_kit_info.mipi.dsi_color_format;
	slave->mode_flags = panel->info.mode_flags;

	ret = mipi_dsi_attach(slave);
	if (ret) {
		LCD_KIT_ERR("failed to attach dsi panel to host\n");
		drm_panel_remove(&panel->base);
		return ret;
	}
	lcd_kit_info.slave = slave;
	panel->slave = slave;

	sprd_panel_sysfs_init(&panel->dev);
	mipi_dsi_set_drvdata(slave, panel);
	/*
	 * FIXME:
	 * The esd check work should not be scheduled in probe
	 * function. It should be scheduled in the enable()
	 * callback function. But the dsi encoder will not call
	 * drm_panel_enable() the first time in encoder_enable().
	 */
	lcd_kit_set_esd_config(panel);
	if (panel->info.esd_check_en) {
		schedule_delayed_work(&panel->esd_work,
			msecs_to_jiffies(panel->info.esd_check_period));
		panel->esd_work_pending = true;
	}

	panel->is_enabled = true;
	LCD_KIT_INFO("exit\n");
	return component_add(&slave->dev, &panel_component_ops);
}

static int lcm_remove(struct mipi_dsi_device *slave)
{
	struct sprd_panel *panel = mipi_dsi_get_drvdata(slave);
	int ret;

	component_del(&slave->dev, &panel_component_ops);

	ret = mipi_dsi_detach(slave);
	if (ret < 0)
		LCD_KIT_ERR("failed to detach from DSI host: %d\n", ret);

	drm_panel_detach(&panel->base);
	drm_panel_remove(&panel->base);

	return LCD_KIT_OK;
}

static const struct of_device_id lcm_of_match[] = {
	{ .compatible = "kit_panel_common", },
	{ }
};

MODULE_DEVICE_TABLE(of, lcm_of_match);

static struct mipi_dsi_driver lcm_driver = {
	.probe = lcm_probe,
	.remove = lcm_remove,
	.driver = {
		.name = "kit_panel_common",
		.owner = THIS_MODULE,
		.of_match_table = lcm_of_match,
	},
};

module_mipi_dsi_driver(lcm_driver);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("Panel driver for mtk drm arch");
MODULE_AUTHOR("Honor Device Co., Ltd.");
