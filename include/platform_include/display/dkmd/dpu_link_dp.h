/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
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

#include <linux/types.h>

struct screen_info {
	uint32_t h_active_pixels;
	uint32_t v_active_pixels;
};

struct dp_ext_disp_info {
	int port_id;
	uint8_t screen_num;
	struct screen_info *sinfo;
	uint32_t edid_blocks;
	uint8_t *edid;
};

struct dp_connect_ctrl_info {
	int port_id;
	bool is_dprx_ready;

	int(*get_ext_disp_info)(struct dp_ext_disp_info *, int);
};

// for dptx obtain dprx info such as edid that not support
extern int dpu_dptx_register_ext_disp_callback(struct dp_connect_ctrl_info *dinfo);