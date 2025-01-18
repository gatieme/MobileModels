/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2022. All rights reserved.
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

#ifndef DFU_DFR_INFO_H
#define DFU_DFR_INFO_H

#include <linux/types.h>

enum panel_oled_type {
	PANEL_OLED_LTPS,
	PANEL_OLED_LTPO,
};

enum panel_ltpo_version {
	PANEL_LTPO_V1,
	PANEL_LTPO_V2,
};

enum panel_ltpo_dsi_cmd_type {
	PANEL_LTPO_DSI_CMD_TE_90HZ,
	PANEL_LTPO_DSI_CMD_TE_120HZ,
	PANEL_LTPO_DSI_CMD_REFRESH,
	PANEL_LTPO_DSI_CMD_REFRESH_1HZ,
	PANEL_LTPO_DSI_CMD_REFRESH_10HZ,
	PANEL_LTPO_DSI_CMD_REFRESH_30HZ,
	PANEL_LTPO_DSI_CMD_90HZ_REFRESH_1HZ,
	PANEL_LTPO_DSI_CMD_90HZ_REFRESH_10HZ,
	PANEL_LTPO_DSI_CMD_90HZ_REFRESH_30HZ,
	PANEL_LTPO_DIS_CMD_INVALID,
};

enum dfr_mode {
	DFR_MODE_CONSTANT,
	DFR_MODE_LONG_V,
	DFR_MODE_LONG_H,
	DFR_MODE_TE_SKIP_BY_MCU,
	DFR_MODE_TE_SKIP_BY_ACPU,
	DFR_MODE_INVALID
};

#define DSI_CMDS_NUM_MAX 15

struct dsi_cmd_desc {
	uint32_t dtype;
	uint32_t vc;
	uint32_t wait;
	uint32_t waittype;
	uint32_t dlen;
	char *payload;
};

struct dsi_cmds {
	uint32_t cmd_num;
	struct dsi_cmd_desc cmds[DSI_CMDS_NUM_MAX];
};

struct safe_frm_rates {
	uint32_t safe_frm_rate;
	struct dsi_cmds dsi_cmds;
};

struct dimming_node {
	uint32_t frm_rate;
	uint32_t repeat_num;
};

#define TE_FREQ_NUM_MAX 2
#define FPS_INFO_NUM_MAX 8
#define DIMMING_SEQ_LEN_MAX 8
#define SAFE_FRM_RATE_MAX_NUM 12

struct panel_ltpo_info {
	/* version only used to print */
	enum panel_ltpo_version ver;

	uint32_t te_freq_num;
	uint32_t te_freqs[TE_FREQ_NUM_MAX];

	bool dimming_enable;
	uint32_t dimming_seq_num;
	uint32_t dimming_seq_90hz_num;
	struct dimming_node dimming_seq_list[DIMMING_SEQ_LEN_MAX];
	struct dimming_node dimming_seq_90hz_list[DIMMING_SEQ_LEN_MAX];

	struct dsi_cmds dsi_cmds[DSI_CMDS_NUM_MAX];

	uint32_t safe_frm_rates_num;
	struct safe_frm_rates safe_frm_rates[SAFE_FRM_RATE_MAX_NUM];
	uint32_t dimming_delay_90hz;
};

struct panel_ltps_info {
	uint32_t reserved;
};

struct panel_oled_info {
	enum panel_oled_type oled_type;
	uint32_t fps_sup_num;
	uint32_t fps_sup_seq[FPS_LEVEL_END];
	union {
		struct panel_ltpo_info ltpo_info;
		struct panel_ltps_info ltps_info;
	};
};

struct dfr_info {
	enum dfr_mode dfr_mode;
	struct panel_oled_info oled_info;
};

#endif