/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2025. All rights reserved.
 *
 * dpu_frame_rate_adaptive.h
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
#ifndef DPU_FRAME_RATE_ADAPTIVE_H
#define DPU_FRAME_RATE_ADAPTIVE_H

#include "dpu_fb.h"
#include <stdbool.h>

#ifdef CONFIG_DPU_FRAME_SKIP_LTPO1
extern uint32_t g_last_target_frm_rate;
#endif

void dpu_adaptive_frame_rate_init(struct dpu_fb_data_type *dpufd);
void dpu_afr_update_fps(struct dpu_fb_data_type *dpufd, uint32_t frameFps);
bool dpu_afr_vsync_handle(struct dpu_fb_data_type *dpufd);
void dpu_afr_power_on(struct dpu_fb_data_type *dpufd);
void dpu_afr_power_off(struct dpu_fb_data_type *dpufd);
bool dpu_afr_need_update_single_frame(struct dpu_fb_data_type *dpufd);
void dpu_afr_vsync_single_frame_update(struct dpu_fb_data_type *dpufd);
void dpufb_frame_rate_deinit(struct dpu_fb_data_type *dpufd);
void dfr_switch_cur_te_rate(struct dpu_fb_data_type *dpufd, uint32_t cur_te_rate);

#ifdef CONFIG_DPU_FRAME_SKIP_LTPO1
int32_t dfr_init_set_last_frm_rate(struct dpu_fb_data_type *dpufd, uint32_t frame_rate);
#endif

#endif  /* DPU_FRAME_RATE_ADAPTIVE_H */
