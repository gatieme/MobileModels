/*
 * lcd_kit_displayengine.c
 *
 * display engine dkmd function in lcd
 *
 * Copyright (c) 2023-2023 Huawei Technologies Co., Ltd.
 *
 */

#include <linux/kernel.h>
#include <linux/workqueue.h>

#include "lcd_kit_adapt.h"
#include "lcd_kit_common.h"
#include "lcd_kit_utils.h"
#include "lcd_kit_disp.h"
#include "display_engine_interface.h"
#include "display_engine_kernel.h"
#include "lcd_kit_local_hbm.h"
#include "lcd_kit_panel_irc.h"

#define SN_TEXT_SIZE 128

struct display_engine_vsync {
	const char *name;
	bool is_inited;
	struct kthread_worker handle_worker;
	struct task_struct *handle_thread;
	struct kthread_work handle_work;
};

static struct display_engine_vsync g_de_vsync_ctrl = {
	.name = "display_engine_vsync",
	.is_inited = false,
	.handle_thread = NULL,
};

/* Common function define */
static int copy_buf(char *dst, uint32_t dst_size, char *src, uint32_t src_size);
static int copy_str(char *dst, uint32_t dst_size, char *src, uint32_t src_size);
static uint32_t display_engine_panel_id_to_lcdkit(uint32_t de_id);
static void print_sn_code(unsigned char sn_code[SN_CODE_LEN_MAX], unsigned int sn_code_length);

/* Feature function define */
static int display_engine_panel_info_get(uint32_t panel_id, struct display_engine_panel_info *info);
static void display_engine_workqueue_init(void);
static bool display_engine_workqueue_init_support(void);
static void display_engine_vsync_workqueue_handler(struct kthread_work *work);

static uint32_t display_engine_panel_id_to_lcdkit(uint32_t de_id)
{
	switch (de_id) {
	case DISPLAY_ENGINE_PANEL_INNER:
		return PRIMARY_PANEL;
	case DISPLAY_ENGINE_PANEL_OUTER:
		return SECONDARY_PANEL;
	default:
		LCD_KIT_WARNING("unknown display engine panel id [%d]!\n", de_id);
		break;
	}
	return PRIMARY_PANEL;
}

int display_engine_get_param(void __user *argp)
{
	size_t size = sizeof(struct display_engine_param);
	struct display_engine_param de_param;
	int ret = 0;
	if (!argp) {
		LCD_KIT_ERR("argp is nullptr\n");
		return -1;
	}
	ret = (int)copy_from_user(&de_param, argp, size);
	if (ret) {
		LCD_KIT_ERR("copy_from_user failed, ret:%d!\n", ret);
		return -1;
	}
	if (de_param.modules & DISPLAY_ENGINE_PANEL_INFO) {
		if (display_engine_panel_info_get(de_param.panel_id, &de_param.panel_info)) {
			LCD_KIT_WARNING("display_engine_panel_info_get() failed!\n");
			return -1;
		}
	}

	ret = (int)copy_to_user(argp, &de_param, size);
	if (ret) {
		LCD_KIT_ERR("copy_to_user failed, ret:%d!\n", ret);
		return -1;
	}
	return 0;
}

int display_engine_set_param(void __user *argp)
{
	size_t size = sizeof(struct display_engine_param);
	struct display_engine_param de_param;
	int ret = 0;
	if (!argp) {
		LCD_KIT_ERR("argp is nullptr\n");
		return -1;
	}
	ret = (int)copy_from_user(&de_param, argp, size);
	if (ret) {
		LCD_KIT_ERR("copy_from_user failed, ret:%d!\n", ret);
		return -1;
	}
	if (de_param.modules & DISPLAY_ENGINE_DDIC_IRC) {
		if (display_engine_set_param_irc(de_param.panel_id, de_param.ddic_irc_enable)) {
			LCD_KIT_WARNING("display_engine_set_param_irc() failed!\n");
			return -1;
		}
	}
	if (de_param.modules & DISPLAY_ENGINE_LOCAL_HBM_ALPHA_MAP) {
		if (display_engine_set_param_aplha_map(de_param.panel_id, &de_param.alpha_map)) {
			LCD_KIT_WARNING("display_engine_set_param_aplha_map() failed!\n");
			return -1;
		}
	}
	return 0;
}

static void print_sn_code(unsigned char sn_code[SN_CODE_LEN_MAX], unsigned int sn_code_length)
{
	char sn_text[SN_TEXT_SIZE];
	uint32_t i;

	if (sn_code_length > SN_CODE_LEN_MAX || sn_code_length >= SN_TEXT_SIZE / 2) {
		LCD_KIT_INFO("sn_code_length:%d is not right, max{SN_CODE_LEN_MAX:%d, SN_TEXT_SIZE/2:%d}\n",
			sn_code_length, SN_CODE_LEN_MAX, SN_TEXT_SIZE / 2);
		return;
	}

	for (i = 0; i < sn_code_length; i++)
		sprintf(sn_text + (i << 1), "%02x", sn_code[i]);

	i <<= 1;
	sn_text[i] = '\0';
	LCD_KIT_DEBUG("sn[%u]=\'%s\'\n", sn_code_length, sn_text);
}

static int copy_buf(char *dst, uint32_t dst_size, char *src, uint32_t src_size)
{
	uint32_t len = (dst_size > src_size) ? src_size : dst_size;

	if (!src || !dst) {
		LCD_KIT_ERR("point is null \n");
		return -1;
	}

	if (dst_size == 0 || src_size == 0) {
		LCD_KIT_WARNING("dst_size:%u, src_size:%u\n", dst_size, src_size);
		return -1;
	}

	memcpy(dst, src, len);
	return (int)len;
}

static int copy_str(char *dst, uint32_t dst_size, char *src, uint32_t src_size)
{
	uint32_t len = (dst_size > src_size) ? (src_size - 1) : (dst_size - 1);

	if (!src || !dst) {
		LCD_KIT_ERR("point is null\n");
		return -1;
	}

	if (dst_size == 0 || src_size == 0) {
		LCD_KIT_WARNING("dst_size:%u, src_size:%u\n", dst_size, src_size);
		return -1;
	}

	strncpy(dst, src, len);
	dst[len] = '\0';
	return (int)len;
}

/* Panel information: */
static int display_engine_panel_info_get(uint32_t panel_id, struct display_engine_panel_info *info)
{
	uint32_t lcd_panel_id = display_engine_panel_id_to_lcdkit(panel_id);
	struct dpu_panel_info *panel_info = lcd_kit_get_dpu_pinfo(lcd_panel_id);
	struct lcd_kit_disp_info *disp_info_p = lcd_kit_get_disp_info(lcd_panel_id);
	int ret = 0;

	if (!panel_info || !info) {
		LCD_KIT_ERR("NULL point: panel_info=%p\n", panel_info);
		return LCD_KIT_FAIL;
	}

	info->width = panel_info->xres;
	info->height = panel_info->yres;
	info->max_backlight = panel_info->bl_info.bl_max;
	info->min_backlight = panel_info->bl_info.bl_min;

	/* get panel name */
	ret = copy_str(info->panel_name, PANEL_NAME_LEN, common_info->panel_name, DISPLAY_PANEL_NAME_MAX_LEN);
	if (ret < 0)
		LCD_KIT_WARNING("panel_name copy fail, ret:%d", ret);

	/* get panel version */
	ret = copy_str(info->panel_version, PANEL_VERSION_LEN, disp_info_p->panel_version.lcd_panel_version,
		LCD_PANEL_VERSION_SIZE);
	if (ret < 0)
		LCD_KIT_WARNING("panel_version copy fail, ret:%d", ret);

	/* get sn code */
	info->sn_code_length = (disp_info_p->sn_code_length > SN_CODE_LENGTH_MAX) ?
		SN_CODE_LENGTH_MAX : disp_info_p->sn_code_length;
	ret = copy_buf(info->sn_code, SN_CODE_LEN_MAX, disp_info_p->sn_code, info->sn_code_length);
	if (ret < 0) {
		memset(info->sn_code, 0, sizeof(info->sn_code));
		LCD_KIT_INFO("sn is empty, ret:%d\n", ret);
	} else {
		print_sn_code(info->sn_code, info->sn_code_length);
	}

#ifdef LCD_FACTORY_MODE
	info->is_factory = true;
#else
	info->is_factory = false;
#endif
	info->local_hbm_support = display_engine_local_hbm_get_support();
	info->oled_type = common_info->oled_type;

	LCD_KIT_INFO("panel_id=%u res(w=%u,h=%u) bl(min=%u,max=%u) name=%s local_hbm_support=%d oled_type=%d\n",
		panel_id, info->width, info->height, info->min_backlight, info->max_backlight, info->panel_name,
		info->local_hbm_support, info->oled_type);
	return LCD_KIT_OK;
}

static void display_engine_vsync_workqueue_handler(struct kthread_work *work)
{
	display_engine_local_hbm_workqueue_handler(work);
}

static bool display_engine_workqueue_init_support(void)
{
	if (display_engine_local_hbm_get_support())
		return true;
	return false;
}

void display_engine_workqueue_init(void)
{
	if (g_de_vsync_ctrl.is_inited) {
		LCD_KIT_INFO("vsync_ctrl is inited\n");
		return;
	}

	if (!display_engine_workqueue_init_support()) {
		LCD_KIT_WARNING("workqueue init not support\n");
		return;
	}

	kthread_init_worker(&g_de_vsync_ctrl.handle_worker);
	g_de_vsync_ctrl.handle_thread = kthread_create(kthread_worker_fn,
		&g_de_vsync_ctrl.handle_worker, g_de_vsync_ctrl.name);
	if (!g_de_vsync_ctrl.handle_thread) {
		LCD_KIT_ERR("%s failed to create handle_thread!\n",
			g_de_vsync_ctrl.name);
		return;
	}

	kthread_init_work(&g_de_vsync_ctrl.handle_work,
		display_engine_vsync_workqueue_handler);
	wake_up_process(g_de_vsync_ctrl.handle_thread);
	g_de_vsync_ctrl.is_inited = true;
	LCD_KIT_INFO("workqueue inited\n");
}

/* queue work function called in vsync interrrupt and cannot be blocked */
void display_engine_vsync_queue_work(void)
{
	if (!g_de_vsync_ctrl.is_inited) {
		LCD_KIT_DEBUG("vsync_ctrl is not inited\n");
		return;
	}

	kthread_queue_work(&g_de_vsync_ctrl.handle_worker,
		&g_de_vsync_ctrl.handle_work);
}

void lcd_kit_display_engine_param_init(int panel_id, struct device_node *np)
{
	/* parse panel irc */
	lcd_kit_parse_ddic_irc(panel_id, np);
}

void display_engine_init(void)
{
	display_engine_workqueue_init();
	display_engine_local_hbm_init();
}
