/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
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

#ifndef DPU_FRAME_RATE_STATIC_H
#define DPU_FRAME_RATE_STATIC_H

#include "dpu_fb.h"

void dpu_refresh_stat_init(struct dpu_fb_data_type *dpufd);
void dpufb_frame_rate_static_deinit(struct dpu_fb_data_type *dpufd);
int32_t get_panel_refresh_count(uint32_t panel_id, struct panel_refresh_statistic_info *refresh_stat_info);

#endif
