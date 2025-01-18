/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2025. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
#include <securec.h>
#include <linux/kernel.h>
#include <linux/platform_device.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include "dpu_frame_rate_static.h"

struct dpu_panel_info * g_panel_info;

static struct frm_rate_gears valid_frm_rate[FRM_RATE_GEARS_NUM] = {{FRM_RATE_1HZ, 1, 1000000},
	{FRM_RATE_10HZ, 10, 100000}, {FRM_RATE_15HZ, 15, 66667}, {FRM_RATE_24HZ, 24, 41667}, {FRM_RATE_30HZ, 30, 33333},
	{FRM_RATE_45HZ, 45, 22222}, {FRM_RATE_60HZ, 60, 16667}, {FRM_RATE_90HZ, 90, 11111}, {FRM_RATE_120HZ, 120, 8333},
	{FRM_RATE_180HZ, 180, 5556}};

static uint32_t find_closest_fps(uint64_t val) {
	uint32_t idx;
	uint32_t distans = UINT_MAX;
	uint32_t final_fps_type = 0;

	for (idx = 0; idx < FRM_RATE_GEARS_NUM; idx++) {
		if ((uint32_t)abs(val - valid_frm_rate[idx].period_us) < distans) {
			distans = (uint32_t)abs(val - valid_frm_rate[idx].period_us);
			final_fps_type = valid_frm_rate[idx].type;
		}
	}

	return final_fps_type;
}

static int32_t refresh_stat_count(uint64_t delta_time_us, struct dpu_frm_rate_static *frame_rate_static)
{
	uint32_t final_fps_type;
	uint32_t self_refresh_cnt;

	if (frame_rate_static->self_refresh_period_us <= 0) {
		DPU_FB_ERR("[static] self refresh period <= 0\n");
		return -1;
	}

	DPU_FB_DEBUG("[static] delta time = %llu us\n", delta_time_us);
	DPU_FB_DEBUG("[static] self_refresh_period_us = %llu us\n", frame_rate_static->self_refresh_period_us);

	/* handle the self-refresh situation */
	self_refresh_cnt = delta_time_us / frame_rate_static->self_refresh_period_us;
	if (self_refresh_cnt > 0) {
		final_fps_type = find_closest_fps((uint64_t)frame_rate_static->self_refresh_period_us);
		frame_rate_static->refresh_stat_info.stat_info.refresh_cnt[final_fps_type] += self_refresh_cnt;
		frame_rate_static->real_frame_rate = PERIOD_US_1HZ / frame_rate_static->self_refresh_period_us;
		DPU_FB_DEBUG("[static] self refresh period = %u us, self refresh cnt = %u",
			frame_rate_static->self_refresh_period_us, self_refresh_cnt);
	}

	/* handle the non self-refresh situation */
	delta_time_us = delta_time_us - self_refresh_cnt * frame_rate_static->self_refresh_period_us;
	if (delta_time_us > 0) {
		final_fps_type = find_closest_fps(delta_time_us);
		frame_rate_static->refresh_stat_info.stat_info.refresh_cnt[final_fps_type]++;
		frame_rate_static->real_frame_rate = PERIOD_US_1HZ / delta_time_us;

		DPU_FB_DEBUG("[static] approximate fps = %u Hz, final fps = %u Hz", frame_rate_static->real_frame_rate,
			valid_frm_rate[final_fps_type].frm_rate);
	}

	return 0;
}

static void stat_clear_case_process(struct dpu_frm_rate_static *frame_rate_static)
{
	int32_t clear_flag;

	// timeout clear
	if (frame_rate_static->total_count_time_us > MAX_RECODE_DURATION_US) {
		DPU_FB_INFO("[static] total_count_time_us > MAX_RECODE_DURATION_US, total_count_time_us = %llu us",
			frame_rate_static->total_count_time_us);

		frame_rate_static->total_count_time_us = 0;
		memset_s(&frame_rate_static->refresh_stat_info.stat_info, sizeof(frame_rate_static->refresh_stat_info.stat_info),
			0, sizeof(frame_rate_static->refresh_stat_info.stat_info));
		return;
	}

	clear_flag = atomic_read(&(frame_rate_static->refresh_stat_info.clear_flag));
	if (clear_flag) {
		frame_rate_static->total_count_time_us = 0;
		memset_s(&frame_rate_static->refresh_stat_info.stat_info, sizeof(frame_rate_static->refresh_stat_info.stat_info),
			0, sizeof(frame_rate_static->refresh_stat_info.stat_info));
		atomic_set(&(frame_rate_static->refresh_stat_info.clear_flag), 0);
		DPU_FB_INFO("[static] refresh_stat_info clear");
		return;
	}

	return;
}

static void refresh_stat_isr_handle_work(struct work_struct *work)
{
	uint64_t power_off_duration_us;
	uint64_t delta_time_us;
	uint32_t multiple_cnt;
	uint32_t te_duration_us;
	struct dpu_fb_data_type *dpufd = NULL;
	struct dpu_frm_rate_static *frame_rate_static = NULL;

	dpu_check_and_no_retval(!work, ERR, "work is null");
	dpufd = container_of(work, struct dpu_fb_data_type, frm_rate_static_work);
	dpu_check_and_no_retval(!dpufd, ERR, "dpufd is null");

	frame_rate_static = &dpufd->panel_info.frm_rate_static;

	if (frame_rate_static->first_count_flag) {
		frame_rate_static->pre_refresh_timestamp = frame_rate_static->curr_refresh_timestamp;
		frame_rate_static->first_count_flag = 0;
		DPU_FB_INFO("first count case");
		return;
	}

	delta_time_us = (uint64_t)abs(ktime_to_us(frame_rate_static->curr_refresh_timestamp) -
		ktime_to_us(frame_rate_static->pre_refresh_timestamp));
	if (dpufd->power_off_timestamp > frame_rate_static->pre_refresh_timestamp) {
		power_off_duration_us = (uint64_t)abs(ktime_to_us(dpufd->power_on_timestamp) -
			ktime_to_us(dpufd->power_off_timestamp));
		DPU_FB_DEBUG("[static] power off duration = %llu us", power_off_duration_us);
		delta_time_us = delta_time_us - power_off_duration_us;
	}
	frame_rate_static->total_count_time_us += delta_time_us;
	DPU_FB_DEBUG("[static] real delta time = %llu us\n", delta_time_us);

	if (frame_rate_static->cur_te_rate > 0) {
		te_duration_us = PERIOD_US_1HZ / frame_rate_static->cur_te_rate;
		/* multiple_cnt need round off */
		multiple_cnt = delta_time_us / te_duration_us;
		if ((delta_time_us - multiple_cnt * te_duration_us) > te_duration_us / 2)
			multiple_cnt += 1;

		delta_time_us = multiple_cnt * te_duration_us;
	}

	if (refresh_stat_count(delta_time_us, frame_rate_static) != 0) {
		DPU_FB_ERR("[static] calculation encountered an error");
		return;
	}

	stat_clear_case_process(frame_rate_static);
	frame_rate_static->pre_refresh_timestamp = frame_rate_static->curr_refresh_timestamp;

	return;
}

static void stat_on_sfu_or_refresh(struct dpu_fb_data_type *dpufd)
{
	struct dpu_frm_rate_static *frame_rate_static = &dpufd->panel_info.frm_rate_static;
	frame_rate_static->curr_refresh_timestamp = ktime_get();

	if (dpufd->frm_rate_static_wq != NULL)
		queue_work(dpufd->frm_rate_static_wq, &dpufd->frm_rate_static_work);

	return;
}

void dpu_refresh_stat_init(struct dpu_fb_data_type *dpufd)
{
	struct dpu_frm_rate_static *frame_rate_static = &dpufd->panel_info.frm_rate_static;

	g_panel_info = &dpufd->panel_info;
	frame_rate_static->first_count_flag = 1;
	frame_rate_static->self_refresh_period_us = PERIOD_US_1HZ;
	frame_rate_static->cur_te_rate = FPS_120HZ;
	frame_rate_static->on_static = stat_on_sfu_or_refresh;
	dpufd->frm_rate_static_wq = create_singlethread_workqueue("fb0_frame_rate_static");
	if (dpufd->frm_rate_static_wq == NULL) {
		DPU_FB_ERR("[static] create frm_rate_static_wq workqueue failed!\n");
		return;
	}
	INIT_WORK(&dpufd->frm_rate_static_work , refresh_stat_isr_handle_work);

	return;
}

void dpufb_frame_rate_static_deinit(struct dpu_fb_data_type *dpufd)
{
	if (dpufd->frm_rate_static_wq != NULL) {
		destroy_workqueue(dpufd->frm_rate_static_wq);
		dpufd->frm_rate_static_wq = NULL;
	}
	g_panel_info = NULL;
}

int32_t get_panel_refresh_count(uint32_t panel_id, struct panel_refresh_statistic_info *refresh_stat_info)
{
	void_unused(panel_id);
	if (!g_panel_info)
		return 0;

	*refresh_stat_info = g_panel_info->frm_rate_static.refresh_stat_info.stat_info;
	atomic_set(&(g_panel_info->frm_rate_static.refresh_stat_info.clear_flag), 1);
	DPU_FB_DEBUG("-\n");
	return 0;
}

