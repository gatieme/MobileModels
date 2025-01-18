/*
 * lcd_kit_get_safe_frm_rate_by_bl.c
 *
 * display engine dkmd safe frm rate function in lcd
 *
 * Copyright (c) 2024-2024 Huawei Technologies Co., Ltd.
 *
 */

#include "lcd_kit_safe_frm_rate.h"

#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/mutex.h>
#include <linux/module.h>
#include <linux/workqueue.h>

#include "lcd_kit_adapt.h"
#include "lcd_kit_parse.h"
#include "lcd_kit_utils.h"
#include "lcd_kit_disp.h"

#define FPS_90HZ 90
#define FPS_120HZ 120
#define FPS_144HZ 144

/* tp safe frm rate tag with touch detected or release */
#define SAFE_FRAMERATE_TP_TOUCH_DETECTED_TAG 1
#define SAFE_FRAMERATE_TP_TOUCH_RELEASE_TAG 0
/* tp safe frm rate with touch detected or release */
#define SAFE_FRAMERATE_TP_TOUCH_DETECTED_HZ 10
#define SAFE_FRAMERATE_TP_TOUCH_RELEASE_HZ 1
/* tp safe frm rate touch release time*/
#define SAFE_FRAMERATE_TP_TOUCH_RELEASE_DELAY_MS 500

struct safe_frm_rate_vsync {
	const char *name;
	struct kthread_worker handle_worker;
	struct kthread_work handle_work_detected;
    struct kthread_work handle_work_release;
	struct task_struct *handle_thread;
};

static struct safe_frm_rate_vsync g_sfr_tp_touch = {
	.name = "safe_frm_rate_vsync_tp_touch",
	.handle_thread = NULL,
};

static struct delayed_work tp_release_delay_work;

/* tp safe frm rate touch detected handler */
static void tp_touch_detected_work_handler(struct kthread_work *work);
/* tp safe frm rate touch release handler */
static void tp_touch_release_work_handler(struct kthread_work *work);
/* tp safe frm rate touch release delay handler */
static void tp_touch_release_delay_work_handler(struct work_struct *work);
static bool safe_frm_rate_init = false;
static struct mutex sfr_mutex;

static bool low_brightness_flag = false;
static bool is_tp_event_init = false;
static int single_panel_id = 0;
/* default sfr value is 1*/
static unsigned int current_brightness_sfr = 1;
static unsigned int current_tp_sfr = 1;

/* get real safe frm rate by current fps */
static unsigned int lcd_kit_get_real_safe_frm_by_fps(int panel_id, unsigned int current_fps)
{
	if (!low_brightness_flag) {
		switch (current_fps) {
		case FPS_144HZ:
			return disp_info->safe_frm_decision.fps_144_safe_frm;
		case FPS_120HZ:
			return disp_info->safe_frm_decision.fps_120_safe_frm;
		case FPS_90HZ:
			return disp_info->safe_frm_decision.fps_90_safe_frm;
		default:
			return current_fps;
		}
	}

	return current_fps;
}

/* update safe frm rate by low brightness status and current fps */
static unsigned int lcd_kit_upt_safe_frm_rate_by_fps(int panel_id, unsigned int safe_frm_rate, unsigned int current_fps)
{
	if (safe_frm_rate != 0) {
		/* notify low brightness status change */
		if (safe_frm_rate == FPS_120HZ) {
			low_brightness_flag = true;
			LCD_KIT_INFO("notify low brightness scene enter\n");
		} else {
			low_brightness_flag = false;
			LCD_KIT_INFO("notify low brightness scene exit\n");
		}
	}
	return lcd_kit_get_real_safe_frm_by_fps(panel_id, current_fps);
}

static unsigned int get_max_sfr_by_brightness_and_tp()
{   
	unsigned int final_safe_frm_rate = current_brightness_sfr > current_tp_sfr ?
		current_brightness_sfr : current_tp_sfr;
	LCD_KIT_DEBUG("current_brightness_sfr:%u current_tp_sfr:%u final_safe_frm_rate%u\n",
		current_brightness_sfr, current_tp_sfr, final_safe_frm_rate);
	return final_safe_frm_rate;
}

/* update safe frm rate by tp */
static void lcd_kit_upt_safe_frm_rate_by_tp(unsigned int safe_frm_rate)
{
	current_tp_sfr = safe_frm_rate;
	LCD_KIT_DEBUG("current_tp_sfr %u\n", current_tp_sfr);
}

/* update safe frm rate by brightness */
static void lcd_kit_upt_safe_frm_rate_by_brightness(unsigned int safe_frm_rate)
{
	if (safe_frm_rate == 0)
		return ;
	current_brightness_sfr = safe_frm_rate;
	LCD_KIT_DEBUG("current_brightness_sfr %u\n", current_brightness_sfr);
}

/* update final safe frm rate */
static unsigned int lcd_kit_upt_safe_frm_rate(int panel_id, const struct panel_update_safe_frm_rate_info *safe_frm_info)
{
	int ret;
	unsigned int dsi0_index;
	unsigned int connector_id;
	unsigned int final_safe_frm_rate;

	if (!safe_frm_info) {
		LCD_KIT_ERR("safe_frm_info is null\n");
		return 0;
	}
	
	mutex_lock(&sfr_mutex);
	lcd_kit_upt_safe_frm_rate_by_brightness(safe_frm_info->update_safe_frm_rate);
	final_safe_frm_rate = current_brightness_sfr;
	mutex_unlock(&sfr_mutex);

	/* update safe frame rate by TP */
	if (disp_info->safe_frm_decision.tp_support) {
		mutex_lock(&sfr_mutex);
		final_safe_frm_rate = get_max_sfr_by_brightness_and_tp();
		mutex_unlock(&sfr_mutex);
	}

	/* update safe frame rate by FPS */
	if (disp_info->safe_frm_decision.fps_support)
		final_safe_frm_rate = lcd_kit_upt_safe_frm_rate_by_fps(panel_id,
			safe_frm_info->update_safe_frm_rate, safe_frm_info->update_frm_rate);
		
	LCD_KIT_INFO("lcdkit decision mode support tp:%u fps:%u, final safe frm rate:%u\n",
		disp_info->safe_frm_decision.tp_support, disp_info->safe_frm_decision.fps_support, final_safe_frm_rate);

	return final_safe_frm_rate;
}

/* send final safe frm rate */
static unsigned int lcd_kit_send_safe_frm_rate(int panel_id, unsigned int safe_frm_rate)
{
	int ret;
	unsigned int dsi0_index;
	unsigned int connector_id;

	connector_id = DPU_PINFO->connector_id;
	ret = lcd_kit_get_dsi_index(&dsi0_index, connector_id);
	if (ret) {
		LCD_KIT_ERR("get dsi0 index error\n");
		return LCD_KIT_FAIL;
	}
	dkmd_dfr_send_safe_frm_rate(dsi0_index, DPU_PINFO->type, safe_frm_rate);

	return LCD_KIT_OK;
}

/* safe frame rate second decision, time delay is not allowed in this function */
int lcd_kit_safe_frm_rate_ctrl(int panel_id, const struct panel_update_safe_frm_rate_info *safe_frm_info)
{
	if (!safe_frm_rate_init)
		return LCD_KIT_FAIL;
	
	int ret;
	unsigned int final_safe_frm_rate;

	final_safe_frm_rate = lcd_kit_upt_safe_frm_rate(panel_id, safe_frm_info);
	if (!final_safe_frm_rate) {
		LCD_KIT_ERR("update safe frm rate fail\n");
		return LCD_KIT_FAIL;
	}

	ret = lcd_kit_send_safe_frm_rate(panel_id, final_safe_frm_rate);
	if (ret) {
		LCD_KIT_ERR("send safe frm rate fail\n");
		return LCD_KIT_FAIL;
	}

	return LCD_KIT_OK;
}

/* parse safe frm rate decsion info */
void lcd_kit_safe_frm_init(int panel_id, struct device_node *np)
{
	LCD_KIT_INFO("DISPLAY_ENGINE_SAFE_FRM_INFO parse panel xml data");
	lcd_kit_parse_u32(np, "lcd-kit,safe-frm-decision-by-tp-support", &disp_info->safe_frm_decision.tp_support, 0);
	lcd_kit_parse_u32(np, "lcd-kit,safe-frm-decision-by-fps-support", &disp_info->safe_frm_decision.fps_support, 0);
	if (disp_info->safe_frm_decision.fps_support) {
		lcd_kit_parse_u32(np, "lcd-kit,fps-144-safe-frm", &disp_info->safe_frm_decision.fps_144_safe_frm, 0);
		lcd_kit_parse_u32(np, "lcd-kit,fps-120-safe-frm", &disp_info->safe_frm_decision.fps_120_safe_frm, 0);
		lcd_kit_parse_u32(np, "lcd-kit,fps-90-safe-frm", &disp_info->safe_frm_decision.fps_90_safe_frm, 0);
	}
	mutex_init(&sfr_mutex);
	safe_frm_rate_init = true;
}

void safe_frm_rate_vsync_workqueue_init(int panel_id)
{
	if (is_tp_event_init)
		return;
	if (!disp_info->safe_frm_decision.tp_support) {
		LCD_KIT_INFO("not support tp event\n");
		return;
	}

    kthread_init_worker(&g_sfr_tp_touch.handle_worker);
    g_sfr_tp_touch.handle_thread = kthread_create(kthread_worker_fn,
        &g_sfr_tp_touch.handle_worker, g_sfr_tp_touch.name);
    if (!g_sfr_tp_touch.handle_thread) {
        LCD_KIT_ERR("%s failed to create handle_thread!\n",
            g_sfr_tp_touch.name);
        return;
    }
    kthread_init_work(&g_sfr_tp_touch.handle_work_detected, tp_touch_detected_work_handler);
    kthread_init_work(&g_sfr_tp_touch.handle_work_release, tp_touch_release_work_handler);
    wake_up_process(g_sfr_tp_touch.handle_thread);

    LCD_KIT_INFO("tp workqueue inited\n");

	INIT_DELAYED_WORK(&tp_release_delay_work, tp_touch_release_delay_work_handler);
	single_panel_id = panel_id;
	is_tp_event_init = true;
}

static void tp_touch_release_delay_work_handler(struct work_struct *work)
{
	int ret;
	int panel_id = single_panel_id;
	unsigned int final_safe_frm_rate;

	if (!work) {
		LCD_KIT_ERR("work struct is null\n");
		return;
	}

	mutex_lock(&sfr_mutex);
	lcd_kit_upt_safe_frm_rate_by_tp(SAFE_FRAMERATE_TP_TOUCH_RELEASE_HZ);
	final_safe_frm_rate = get_max_sfr_by_brightness_and_tp();
	mutex_unlock(&sfr_mutex);

	LCD_KIT_DEBUG("tp touch release send safe frm rate %u\n", final_safe_frm_rate);
	ret = lcd_kit_send_safe_frm_rate(panel_id, final_safe_frm_rate);
	if (ret)
		LCD_KIT_ERR("tp touch release send safe frm rate fail\n");
	else
		LCD_KIT_DEBUG("tp touch release send safe frm rate sucess\n");
}

static void tp_touch_release_work_handler(struct kthread_work *work)
{
	if (!work) {
		LCD_KIT_ERR("kthread work is null\n");
		return;
	}

	cancel_delayed_work_sync(&tp_release_delay_work);
	schedule_delayed_work(&tp_release_delay_work,
		msecs_to_jiffies(SAFE_FRAMERATE_TP_TOUCH_RELEASE_DELAY_MS));
}

static void tp_touch_detected_work_handler(struct kthread_work *work)
{
	int ret;
	unsigned int final_safe_frm_rate;
	int panel_id = single_panel_id;

	if (!work) {
		LCD_KIT_ERR("kthread work is null\n");
		return;
	}

	cancel_delayed_work_sync(&tp_release_delay_work);

	mutex_lock(&sfr_mutex);
	lcd_kit_upt_safe_frm_rate_by_tp(SAFE_FRAMERATE_TP_TOUCH_DETECTED_HZ);
	final_safe_frm_rate = get_max_sfr_by_brightness_and_tp();
	mutex_unlock(&sfr_mutex);

	LCD_KIT_DEBUG("tp touch detected send safe frm rate %u\n", final_safe_frm_rate);
	ret = lcd_kit_send_safe_frm_rate(panel_id, final_safe_frm_rate);
	if (ret)
		LCD_KIT_ERR("tp touch detected send safe frm rate fail\n");
    else
        LCD_KIT_DEBUG("tp touch detected send safe frm rate sucess\n");
}

void lcd_kit_tp_notify_de_event(int val, int panel_id)
{
	if (!disp_info->safe_frm_decision.tp_support)
		return;
	if (!is_tp_event_init || !safe_frm_rate_init)
		return;
	if (panel_id != single_panel_id) {
		LCD_KIT_ERR("only support single panel\n");
		return;
	}
	if (val == SAFE_FRAMERATE_TP_TOUCH_DETECTED_TAG)
		kthread_queue_work(&g_sfr_tp_touch.handle_worker, &g_sfr_tp_touch.handle_work_detected);
	else if (val == SAFE_FRAMERATE_TP_TOUCH_RELEASE_TAG)
		kthread_queue_work(&g_sfr_tp_touch.handle_worker, &g_sfr_tp_touch.handle_work_release);
}
