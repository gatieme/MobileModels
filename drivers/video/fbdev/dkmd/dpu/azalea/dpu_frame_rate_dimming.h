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
#ifndef DPU_FRAME_RATE_DIMMING_H
#define DPU_FRAME_RATE_DIMMING_H

#include "dpu_fb.h"
#include <stdbool.h>

#define IDLE_INTERVAL_100MS 100
#define IDLE_SENDCMD_DIFF_MS 30
#define IDLE_10HZ_DELAY_REPEAT_CNT 5
#define SAFE_FRM_RATE_MAX 0xffff

enum IDLE_RESET_TYPE {
	BL_TYPE,  // backlight change
	FRM_UPDATE, // frame update
};

void dpu_frm_rate_dimming_init(struct dpu_fb_data_type *dpufd);
void dpufb_frame_rate_dimming_deinit(struct dpu_fb_data_type *dpufd);
void dpu_reset_idle_para(struct dpu_fb_data_type *dpufd,enum IDLE_RESET_TYPE type);
void dpu_vsync_dimming_handle(struct dpu_fb_data_type *dpufd);
void dpu_reset_dimming_idle_list(struct dpu_fb_data_type *dpufd, int hw_frm_rate);
int check_frm_rate_valid_and_send(struct dpu_fb_data_type *dpufd);
void dpu_send_idle_control_cmd(struct dpu_fb_data_type *dpufd, uint32_t cmd_type);
void dpu_send_idle_control_cmd_inner(struct dpu_fb_data_type *dpufd, uint32_t cmd_type);
#endif  /* DPU_FRAME_RATE_DIMMING_H */

