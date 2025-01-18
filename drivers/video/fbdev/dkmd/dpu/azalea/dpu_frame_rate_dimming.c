/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2025. All rights reserved.
 *
 * dpu_frame_rate_dimming.h
 *
 * The driver of adaptive frame rate
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

#include "dpu_frame_rate_dimming.h"
#include "dpu_frame_rate_adaptive.h"
#include <securec.h>
#include "dpu_trace.h"
#ifdef CONFIG_LCD_KIT_DRIVER
#include "lcd_kit_utils.h"
#endif

static void dpu_frm_dimming_list_init(struct dpu_fb_data_type *dpufd, int hw_fps)
{
	uint32_t seq_index = 0;
	uint32_t repeat_index = 0;
	int list_index = 0;
	struct dpu_frm_dimming *frm_rate_dimming = &dpufd->panel_info.frm_rate_dimming;
	struct panel_ltpo_info *ltpo_info = &dpufd->panel_info.dfr_info.oled_info.ltpo_info;

	frm_rate_dimming->idle_list_type = DIMMING_LIST_TYPE_NORMAL;
	switch (hw_fps) {
	case FPS_120HZ:
		for (seq_index = 0; seq_index < ltpo_info->dimming_seq_num; seq_index++) {
			for (repeat_index = 0; repeat_index < ltpo_info->dimming_seq_list[seq_index].repeat_num; repeat_index++) {
				frm_rate_dimming->idle_fps_list[list_index++] = (int)ltpo_info->dimming_seq_list[seq_index].frm_rate;
				if (ltpo_info->dimming_seq_list[seq_index].frm_rate == FPS_10HZ
					&& ltpo_info->dimming_seq_list[seq_index].repeat_num >= IDLE_10HZ_DELAY_REPEAT_CNT) {
					frm_rate_dimming->idle_list_type = DIMMING_LIST_TYPE_DELAY;
					frm_rate_dimming->idle_gear_count = ltpo_info->dimming_seq_list[seq_index].repeat_num;
					break;
				}
			}
		}
		frm_rate_dimming->fps_list_len = list_index;
		break;
	case FPS_90HZ:
		for (seq_index = 0; seq_index < ltpo_info->dimming_seq_90hz_num; seq_index++) {
			for (repeat_index = 0; repeat_index < ltpo_info->dimming_seq_90hz_list[seq_index].repeat_num; repeat_index++) {
				frm_rate_dimming->idle_fps_list[list_index++] =
					(int)ltpo_info->dimming_seq_90hz_list[seq_index].frm_rate;
				if (ltpo_info->dimming_seq_90hz_list[seq_index].frm_rate == FPS_10HZ
					&& ltpo_info->dimming_seq_90hz_list[seq_index].repeat_num >= IDLE_10HZ_DELAY_REPEAT_CNT) {
					frm_rate_dimming->idle_list_type = DIMMING_LIST_TYPE_DELAY;
					frm_rate_dimming->idle_gear_count = ltpo_info->dimming_seq_90hz_list[seq_index].repeat_num;
					break;
				}
			}
		}
		frm_rate_dimming->fps_list_len = list_index;
		break;
	default:
		break;
	}

	DPU_FB_INFO("[dimming] idle_list switch hw_frm_rate %d list_type to %d; 1 is normal, 2 is delay ",
		hw_fps, frm_rate_dimming->idle_list_type);

	return;
}

static void dimming_queue_work(struct dpu_fb_data_type *dpufd, struct delayed_work *work, unsigned long delay)
{
	if (dpufd->frm_rate_dimming_wq != NULL)
		queue_delayed_work(dpufd->frm_rate_dimming_wq, work, delay);
	else
		DPU_FB_ERR("frm_rate_dimming_wq is NULL\n");

	return;
}

void dpu_send_idle_control_cmd_inner(struct dpu_fb_data_type *dpufd, uint32_t cmd_type)
{
	struct dpu_panel_info *pinfo = NULL;
	char __iomem *mipi_dsi_base = NULL;
	struct dsi_cmd_desc *dsi_cmd;
	uint32_t cmd_num = 0;

	DPU_ATRACE_BEGIN_WITH_GID_VALUE("dpu_send_idle_control_cmd", dpufd->panel_info.dpu_task, cmd_type);
	DPU_FB_INFO("enter dpu_send_idle_control_cmd %u\n", cmd_type);
#ifdef CONFIG_LCD_KIT_DRIVER
	lcd_kit_notify_send_idle_cmd_begin();
#endif

	pinfo = &(dpufd->panel_info);

	mipi_dsi_base = get_mipi_dsi_base(dpufd);

	dsi_cmd = pinfo->dfr_info.oled_info.ltpo_info.dsi_cmds[cmd_type].cmds;
	cmd_num = pinfo->dfr_info.oled_info.ltpo_info.dsi_cmds[cmd_type].cmd_num;

	if (cmd_type == PANEL_LTPO_DSI_CMD_REFRESH && dsi_cmd->payload[0] == 0x5E)
		dsi_cmd->payload[1] = (dsi_cmd->payload[1] == 1 ? 0 : 1);

	dpufb_set_vsync_activate_state(dpufd, true);
	dpufb_activate_vsync(dpufd);

	mipi_dsi_cmds_tx(dsi_cmd, cmd_num, mipi_dsi_base);

	dpufb_set_vsync_activate_state(dpufd, false);
	dpufb_deactivate_vsync(dpufd);
#ifdef CONFIG_LCD_KIT_DRIVER
	lcd_kit_notify_send_idle_cmd_end();
#endif

	DPU_ATRACE_END_WITH_GID_VALUE("dpu_send_idle_control_cmd", dpufd->panel_info.dpu_task, cmd_type);
}

void dpu_send_idle_control_cmd(struct dpu_fb_data_type *dpufd, uint32_t cmd_type)
{
	dpu_check_and_no_retval(!dpufd, ERR, "[dimming] dpufd is NULL!\n");

	if (!dpufd->panel_power_on) {
		DPU_FB_WARNING("enter dpu_send_idle_control_cmd %u, but panel_power_on false\n", cmd_type);
		return;
	}

	if (cmd_type >= PANEL_LTPO_DIS_CMD_INVALID) {
		DPU_FB_WARNING("cmd_type %u >= PANEL_LTPO_DIS_CMD_INVALID\n", cmd_type);
		return;
	}

	if ((dpufd->panel_info.fps_updt != dpufd->panel_info.fps ||
		dpufd->panel_info.frm_rate_ctrl.status != FRM_UPDT_DONE) &&
		cmd_type != PANEL_LTPO_DSI_CMD_REFRESH) {
		DPU_FB_WARNING("do not set, is in te switch %d -> %d\n", dpufd->panel_info.fps, dpufd->panel_info.fps_updt);
		return;
	}

	dpu_send_idle_control_cmd_inner(dpufd, cmd_type);

	if (cmd_type == PANEL_LTPO_DSI_CMD_REFRESH_1HZ || cmd_type == PANEL_LTPO_DSI_CMD_90HZ_REFRESH_1HZ ||
	cmd_type == PANEL_LTPO_DSI_CMD_REFRESH) {
		if (dpufd->panel_info.frm_rate_static.on_static)
			dpufd->panel_info.frm_rate_static.on_static(dpufd);
	}
	if (cmd_type == PANEL_LTPO_DSI_CMD_REFRESH_1HZ || cmd_type == PANEL_LTPO_DSI_CMD_90HZ_REFRESH_1HZ) {
		DPU_FB_DEBUG("[dimming] set self_refresh_period_us 1HZ\n");
		dpufd->panel_info.frm_rate_static.self_refresh_period_us = PERIOD_US_1HZ;
	}
	if (cmd_type == PANEL_LTPO_DSI_CMD_REFRESH_10HZ || cmd_type == PANEL_LTPO_DSI_CMD_90HZ_REFRESH_10HZ) {
		DPU_FB_DEBUG("[dimming] set self_refresh_period_us 10HZ\n");
		dpufd->panel_info.frm_rate_static.self_refresh_period_us = PERIOD_US_10HZ;
	}
	if (cmd_type == PANEL_LTPO_DSI_CMD_REFRESH_30HZ || cmd_type == PANEL_LTPO_DSI_CMD_90HZ_REFRESH_30HZ) {
		DPU_FB_DEBUG("[dimming] set self_refresh_period_us 30HZ\n");
		dpufd->panel_info.frm_rate_static.self_refresh_period_us = PERIOD_US_30HZ;
	}
	if (cmd_type == PANEL_LTPO_DSI_CMD_TE_90HZ) {
		DPU_FB_DEBUG("[dimming] set self_refresh_period_us 90HZ\n");
		dpufd->panel_info.frm_rate_static.self_refresh_period_us = PERIOD_US_90HZ;
	}
	if (cmd_type == PANEL_LTPO_DSI_CMD_TE_120HZ) {
		DPU_FB_DEBUG("[dimming] set self_refresh_period_us 120HZ\n");
		dpufd->panel_info.frm_rate_static.self_refresh_period_us = PERIOD_US_120HZ;
	}

	return;
}

int check_frm_rate_valid_and_send(struct dpu_fb_data_type *dpufd)
{
	struct dpu_frm_dimming *frm_rate_dimming = &dpufd->panel_info.frm_rate_dimming;
	int cmd_type = PANEL_LTPO_DIS_CMD_INVALID;

	if (FPS_120HZ == frm_rate_dimming->base_hw_fps) {
		switch(frm_rate_dimming->safe_frame_rate) {
		case FPS_1HZ:
			cmd_type = PANEL_LTPO_DSI_CMD_REFRESH_1HZ;
			break;
		case FPS_10HZ:
			cmd_type = PANEL_LTPO_DSI_CMD_REFRESH_10HZ;
			break;
		case FPS_30HZ:
			cmd_type = PANEL_LTPO_DSI_CMD_REFRESH_30HZ;
			break;
		case FPS_120HZ:
		case SAFE_FRM_RATE_MAX:
			cmd_type = PANEL_LTPO_DSI_CMD_TE_120HZ;
			break;
		default:
			DPU_FB_WARNING("not support safe frame rate %d cmd %d base_hw_fps %d", frm_rate_dimming->safe_frame_rate,
				cmd_type, frm_rate_dimming->base_hw_fps);
			break;
		}
	} else if (FPS_90HZ == frm_rate_dimming->base_hw_fps) {
		switch(frm_rate_dimming->safe_frame_rate) {
		case FPS_1HZ:
			cmd_type = PANEL_LTPO_DSI_CMD_90HZ_REFRESH_1HZ;
			break;
		case FPS_10HZ:
			cmd_type = PANEL_LTPO_DSI_CMD_90HZ_REFRESH_10HZ;
			break;
		case FPS_30HZ:
			cmd_type = PANEL_LTPO_DSI_CMD_90HZ_REFRESH_30HZ;
			break;
		case FPS_90HZ:
		case SAFE_FRM_RATE_MAX:
			cmd_type = PANEL_LTPO_DSI_CMD_TE_90HZ;
			break;
		default:
			DPU_FB_WARNING("not support safe frame rate %d cmd %d base_hw_fps %d", frm_rate_dimming->safe_frame_rate,
				cmd_type, frm_rate_dimming->base_hw_fps);
			break;
		}
	}

	return cmd_type;
}

static void dpu_idle_control_fps_work_cb(struct work_struct *work)
{
	struct dpu_fb_data_type *dpufd = NULL;
	struct dpu_frm_dimming *frm_rate_dimming = NULL;
	int idle_fps;
	int cmd_type;
	u32 sleep = 1000;

	dpu_check_and_no_retval(!work, ERR, "[dimming] work is NULL!\n");
	dpufd = container_of(to_delayed_work(work), struct dpu_fb_data_type, async_cmd_work);
	frm_rate_dimming = &dpufd->panel_info.frm_rate_dimming;
	idle_fps =  frm_rate_dimming->idle_fps_list[frm_rate_dimming->idle_cur_index];
	DPU_FB_DEBUG("[dimming] ready to send cmd current fps is %d", idle_fps);
	frm_rate_dimming->rd_refresh_flag = true;

	if (frm_rate_dimming->base_hw_fps == FPS_90HZ)
		sleep = dpufd->panel_info.dfr_info.oled_info.ltpo_info.dimming_delay_90hz; // for 90hz TE high Volt 2.8ms

	if (sleep > 0)
		usleep_range(sleep, sleep);

	if (!dpufd->panel_info.dfr_info.oled_info.ltpo_info.dimming_enable) {
		DPU_FB_DEBUG("[dimming] dimming switch is off, exit!!");
		return;
	}

	// send refresh cmd
	if (dpu_get_panel_product_type() != PANEL_DUAL_PANEL_TYPE ||
		frm_rate_dimming->te_idle_count != 0)
		dpu_send_idle_control_cmd(dpufd, PANEL_LTPO_DSI_CMD_REFRESH);

	if (frm_rate_dimming->idle_cur_index == 0) {
		DPU_FB_DEBUG("[dimming] 1st enter dimming, set safe frm fps is %d", frm_rate_dimming->safe_frame_rate);
		cmd_type = check_frm_rate_valid_and_send(dpufd);
		dpu_send_idle_control_cmd(dpufd, cmd_type);
	}

	if (frm_rate_dimming->idle_cur_index >= frm_rate_dimming->idle_target_index - 1) {
		DPU_FB_DEBUG("[dimming] enter idle, frm_rate_dimming->idle_list_type = %d", frm_rate_dimming->idle_list_type);
		frm_rate_dimming->rd_idle_state = true;
		cmd_type = check_frm_rate_valid_and_send(dpufd);
		if (frm_rate_dimming->idle_list_type == DIMMING_LIST_TYPE_DELAY && frm_rate_dimming->safe_frame_rate == FPS_1HZ) {
			if (FPS_120HZ == frm_rate_dimming->base_hw_fps)
				cmd_type = PANEL_LTPO_DSI_CMD_REFRESH_10HZ;
			if (FPS_90HZ == frm_rate_dimming->base_hw_fps)
				cmd_type = PANEL_LTPO_DSI_CMD_90HZ_REFRESH_10HZ;
		}
		dpu_send_idle_control_cmd(dpufd, cmd_type);

		if (frm_rate_dimming->idle_fps_list[frm_rate_dimming->idle_target_index] == FPS_1HZ
			&& frm_rate_dimming->idle_list_type == DIMMING_LIST_TYPE_DELAY) {
			DPU_FB_DEBUG("[dimming] enter DIMMING_LIST_TYPE_DELAY");
			dimming_queue_work(dpufd, &dpufd->idle_work,
				msecs_to_jiffies(frm_rate_dimming->idle_gear_count * IDLE_INTERVAL_100MS - IDLE_SENDCMD_DIFF_MS));
			frm_rate_dimming->is_idle_work = true;
		}
	}
	return;
}

static void control_min_idle_fps_work(struct work_struct *work)
{
	int cmd_type;
	struct dpu_fb_data_type *dpufd = NULL;
	struct dpu_frm_dimming *frm_rate_dimming = NULL;

	DPU_FB_DEBUG("[dimming] enter 1HZ kthread");
	dpu_check_and_no_retval(!work, ERR, "work is NULL!\n");

	dpufd = container_of(to_delayed_work(work), struct dpu_fb_data_type, idle_work);
	if (!dpufd->panel_power_on)
		return;

	if (!dpufd->panel_info.dfr_info.oled_info.ltpo_info.dimming_enable) {
		DPU_FB_DEBUG("[dimming] dimming switch is off, exit!!");
		return;
	}

	frm_rate_dimming = &dpufd->panel_info.frm_rate_dimming;
	cmd_type = PANEL_LTPO_DSI_CMD_REFRESH_1HZ;
	if (FPS_90HZ == frm_rate_dimming->base_hw_fps)
		cmd_type = PANEL_LTPO_DSI_CMD_90HZ_REFRESH_1HZ;
	dpu_send_idle_control_cmd(dpufd, cmd_type);
	return;
}

static int dpu_find_fps_index(int* dimming_list, int list_len, int target_fps)
{
	int i;

	for (i = 0; i < list_len; i++) {
		if (dimming_list[i] == target_fps)
			break;
	}
	if (i >= list_len) {
		DPU_FB_DEBUG("not find target_fps %d, set index 0\n", target_fps);
		i = 0;
	}

	return i;
}

void dpu_reset_idle_para(struct dpu_fb_data_type *dpufd, enum IDLE_RESET_TYPE type)
{
	struct dpu_frm_dimming *frm_rate_dimming = NULL;
	uint32_t cur_frm_rate = 0;
	struct panel_ltpo_info *ltpo_info = NULL;
	uint32_t last_panel_fps = 0;

	if (dpufd == NULL)
		return;
	frm_rate_dimming = &dpufd->panel_info.frm_rate_dimming;
	cur_frm_rate = dpufd->panel_info.adaptive_frm_rate.cur_frm_rate;
	ltpo_info = &dpufd->panel_info.dfr_info.oled_info.ltpo_info;

	DPU_FB_DEBUG("[dimming] type is %d cur_frm_rate %d cur te %d\n", type, cur_frm_rate, frm_rate_dimming->base_hw_fps);

	if (dpufd->panel_info.frm_rate_static.on_static)
		dpufd->panel_info.frm_rate_static.on_static(dpufd);

	if (!ltpo_info->dimming_enable) {
		DPU_FB_DEBUG("[dimming] dimming switch is off, exit!!");
		return;
	}

	if (frm_rate_dimming->is_idle_work) {
		frm_rate_dimming->is_idle_work = false;
		cancel_delayed_work(&dpufd->idle_work);
	}

	cur_frm_rate = frm_rate_dimming->base_hw_fps / 2 <= cur_frm_rate ? frm_rate_dimming->base_hw_fps / 2 : cur_frm_rate;

	if (frm_rate_dimming->rd_idle_state) {
		frm_rate_dimming->idle_index =
			dpu_find_fps_index(frm_rate_dimming->idle_fps_list, frm_rate_dimming->fps_list_len, cur_frm_rate);
		frm_rate_dimming->te_idle_count = 0;
	}

	if (frm_rate_dimming->te_idle_count != 0) {
		frm_rate_dimming->idle_index = dpu_find_fps_index(frm_rate_dimming->idle_fps_list,
			frm_rate_dimming->fps_list_len, cur_frm_rate);
		last_panel_fps = frm_rate_dimming->base_hw_fps / frm_rate_dimming->te_idle_count;
		DPU_FB_DEBUG("[dimming] real-time fps %d", last_panel_fps);

		if (last_panel_fps >= FPS_30HZ && last_panel_fps <= FPS_60HZ)
			frm_rate_dimming->idle_index = dpu_find_fps_index(frm_rate_dimming->idle_fps_list,
				frm_rate_dimming->fps_list_len, FPS_30HZ <= cur_frm_rate ? FPS_30HZ : cur_frm_rate);
	}

	frm_rate_dimming->te_idle_count = 0;
	frm_rate_dimming->rd_idle_state = false;
}

static void dpu_reset_safe_frame_rate(struct dpu_fb_data_type *dpufd)
{
	struct dpu_frm_dimming *frm_rate_dimming = NULL;

	frm_rate_dimming = &dpufd->panel_info.frm_rate_dimming;

	if (frm_rate_dimming->safe_frame_rate == g_debug_safe_frame_rate || g_debug_safe_frame_rate == 0)
		return;

	DPU_FB_DEBUG("[dimming] org sfr is %d, switch to %d", frm_rate_dimming->safe_frame_rate, g_debug_safe_frame_rate);
	frm_rate_dimming->safe_frame_rate = g_debug_safe_frame_rate;
}

static int dpu_judge_dimming_list_type(struct dpu_fb_data_type *dpufd)
{
	int i;
	int res = 0;
	int temp_count = 0;
	int type = DIMMING_LIST_TYPE_NORMAL;
	struct dpu_frm_dimming *frm_rate_dimming = &dpufd->panel_info.frm_rate_dimming;

	for (i = 0; i < frm_rate_dimming->fps_list_len; i++) {
		if (FPS_10HZ == frm_rate_dimming->idle_fps_list[i]) {
			temp_count++;
		} else {
			res = temp_count;
			temp_count = 0;
		}
	}
	if (res >= IDLE_10HZ_DELAY_REPEAT_CNT) {
		type = DIMMING_LIST_TYPE_DELAY;
		frm_rate_dimming->idle_gear_count = res;
		frm_rate_dimming->fps_list_len = frm_rate_dimming->fps_list_len - res + 1;
		frm_rate_dimming->idle_fps_list[frm_rate_dimming->fps_list_len - 1] = FPS_1HZ;
	}
	return type;
}

void dpu_reset_dimming_idle_list(struct dpu_fb_data_type *dpufd, int hw_frm_rate)
{
	struct dpu_frm_dimming *frm_rate_dimming = &dpufd->panel_info.frm_rate_dimming;

	frm_rate_dimming->base_hw_fps = (int)hw_frm_rate;

	dpu_frm_dimming_list_init(dpufd, frm_rate_dimming->base_hw_fps);

	frm_rate_dimming->te_idle_count = 0;
	frm_rate_dimming->rd_refresh_flag = false;
	frm_rate_dimming->idle_cur_index = 0;
	frm_rate_dimming->idle_index = 0;
	frm_rate_dimming->rd_idle_state = false;

	return;
}

static void dpu_setup_dimming_list(struct dpu_fb_data_type *dpufd)
{
	struct dpu_frm_dimming *frm_rate_dimming = NULL;

	frm_rate_dimming = &dpufd->panel_info.frm_rate_dimming;
	frm_rate_dimming->fps_list_len = frm_rate_dimming->debug_list_len;
	for (int i = 0; i < frm_rate_dimming->debug_list_len; i++)
		*(frm_rate_dimming->idle_fps_list + i) = frm_rate_dimming->debug_dimming_list[i];

	frm_rate_dimming->idle_list_type = dpu_judge_dimming_list_type(dpufd);
	frm_rate_dimming->setup_dimming_list = false;

	return;
}

void dpu_vsync_dimming_handle(struct dpu_fb_data_type *dpufd)
{
	int hw_fps;
	int count_threshold;
	struct dpu_frm_dimming *frm_rate_dimming = NULL;
	struct panel_ltpo_info *ltpo_info = NULL;

	if (dpufd == NULL)
		return;
	if (!dpufd->panel_power_on)
		return;

	frm_rate_dimming = &dpufd->panel_info.frm_rate_dimming;
	ltpo_info = &dpufd->panel_info.dfr_info.oled_info.ltpo_info;

	if (!ltpo_info->dimming_enable) {
		frm_rate_dimming->rd_idle_state = true;
		DPU_FB_DEBUG("[dimming] dimming switch is off, exit!!");
		return;
	}

	if (frm_rate_dimming->rd_idle_state) {
		DPU_FB_DEBUG("[dimming] cause idle, do not enter dimming");
		return;
	}

	if (frm_rate_dimming->setup_dimming_list)
		dpu_setup_dimming_list(dpufd);

	dpu_reset_safe_frame_rate(dpufd);

	hw_fps = frm_rate_dimming->base_hw_fps;

	frm_rate_dimming->idle_target_index = dpu_find_fps_index(frm_rate_dimming->idle_fps_list,
		frm_rate_dimming->fps_list_len, frm_rate_dimming->safe_frame_rate);

	if (frm_rate_dimming->rd_refresh_flag) {
		frm_rate_dimming->te_idle_count = 0;
		frm_rate_dimming->rd_refresh_flag = false;
	}

	frm_rate_dimming->te_idle_count++;
	DPU_FB_DEBUG("[dimming] dpufd->te_idle_count = %d", frm_rate_dimming->te_idle_count);

	count_threshold = hw_fps / frm_rate_dimming->idle_fps_list[frm_rate_dimming->idle_index];

	if (frm_rate_dimming->te_idle_count == count_threshold ||
	frm_rate_dimming->te_idle_count == hw_fps / frm_rate_dimming->safe_frame_rate) {
		frm_rate_dimming->idle_cur_index = frm_rate_dimming->idle_index;
		dimming_queue_work(dpufd, &dpufd->async_cmd_work, 0);
		frm_rate_dimming->idle_index++;
		DPU_FB_DEBUG("[dimming] idle_index++ = %d", frm_rate_dimming->idle_index);
	}
	return;
}

static int dpu_set_safe_frm_rate(struct dpu_fb_data_type *dpufd, const void __user *argp)
{
	int ret = 0;
	int safe_frm_rate = FPS_1HZ;
	struct dpu_frm_dimming *frm_rate_dimming = NULL;

	if (!dpufd || !argp) {
		DPU_FB_ERR("dpufd or argp is NULL\n");
		return -EINVAL;
	}

	frm_rate_dimming = &dpufd->panel_info.frm_rate_dimming;

	ret = copy_from_user(&safe_frm_rate, argp, sizeof(safe_frm_rate));
	if (ret) {
		DPU_FB_ERR("[afr]copy_from_user(safe_frm_rate) failed, ret = %d\n", ret);
		return -EFAULT;
	}
	if (safe_frm_rate == 0) {
		DPU_FB_ERR("[afr] invalid safe_frm_rate\n");
		return -EINVAL;
	}

	frm_rate_dimming->safe_frame_rate = safe_frm_rate;

	DPU_FB_INFO("[afr] safe_frm_rate = %d\n", safe_frm_rate);
	return ret;
}

void dpu_frm_rate_dimming_init(struct dpu_fb_data_type *dpufd)
{
	struct dpu_frm_dimming *frm_rate_dimming = &dpufd->panel_info.frm_rate_dimming;

	frm_rate_dimming->te_idle_count = 0;
	frm_rate_dimming->setup_dimming_list = false;
	frm_rate_dimming->rd_refresh_flag = false;
	frm_rate_dimming->debug_list_len = 0;
	frm_rate_dimming->idle_cur_index = 0;
	frm_rate_dimming->idle_index = 0;
	frm_rate_dimming->safe_frame_rate = FPS_1HZ;
	frm_rate_dimming->rd_idle_state = false;
	frm_rate_dimming->base_hw_fps = FPS_120HZ;
	frm_rate_dimming->is_idle_work = false;
	dpu_frm_dimming_list_init(dpufd, frm_rate_dimming->base_hw_fps);
	frm_rate_dimming->idle_target_index = frm_rate_dimming->fps_list_len - 1;
	frm_rate_dimming->set_safe_frm_rate = dpu_set_safe_frm_rate;
	dpufd->frm_rate_dimming_wq = alloc_ordered_workqueue("fb0_frame_rate_dimming", WQ_HIGHPRI | WQ_MEM_RECLAIM);

	if (dpufd->frm_rate_dimming_wq == NULL) {
		DPU_FB_ERR("[dimming] create frm_rate_dimming_wq workqueue failed!\n");
		return;
	}
	INIT_DELAYED_WORK(&dpufd->async_cmd_work, dpu_idle_control_fps_work_cb);
	INIT_DELAYED_WORK(&dpufd->idle_work, control_min_idle_fps_work);

	return;
}

void dpufb_frame_rate_dimming_deinit(struct dpu_fb_data_type *dpufd)
{
	if (dpufd->frm_rate_dimming_wq != NULL) {
		destroy_workqueue(dpufd->frm_rate_dimming_wq);
		dpufd->frm_rate_dimming_wq = NULL;
	}
}