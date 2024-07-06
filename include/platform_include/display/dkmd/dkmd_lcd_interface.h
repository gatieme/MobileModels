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

#ifndef DKMD_LCD_INTERFACE_H
#define DKMD_LCD_INTERFACE_H

#include <dsm/dsm_pub.h>
#include "dkmd_dpu.h"
#include "dkmd_mipi_panel_info.h"
#include "dkmd_esd_panel_info.h"
#include "dkmd_user_panel_info.h"
#include "dkmd_dsc_info.h"
#include "dkmd_bl_info.h"
#include "dkmd_dfr_info.h"
#include "dkmd_spr_info.h"

enum frm_rate_type {
	FRM_RATE_1HZ,
	FRM_RATE_10HZ,
	FRM_RATE_15HZ,
	FRM_RATE_24HZ,
	FRM_RATE_30HZ,
	FRM_RATE_45HZ,
	FRM_RATE_60HZ,
	FRM_RATE_90HZ,
	FRM_RATE_120HZ,
	FRM_RATE_180HZ,
	FRM_RATE_GEARS_NUM
};

struct frm_rate_gears {
	uint32_t type;
	uint32_t frm_rate;
	uint32_t period_us;
};

struct panel_refresh_statistic_info {
	uint32_t refresh_cnt[FRM_RATE_GEARS_NUM];
};

struct panel_refresh_statistic_rslt {
	struct panel_refresh_statistic_info stat_info;
	atomic_t clear_flag;
};

enum product_type {
	PANEL_NORMAL,
	PANEL_FOLD, // used for left & right fold panel
	PANEL_FLIP, // used for top & bottom fold panel
};

struct panel_special_config {
	uint8_t lcd_updt_fps_te_support;
	uint8_t lcd_updt_fps_pfm_support;
};

struct dpu_panel_info {
	const char *lcd_name;
	uint32_t xres;
	uint32_t yres;
	uint32_t width;
	uint32_t height;
	uint32_t type;
	uint32_t fps;
	uint32_t bpp;
	uint32_t bgr_fmt;
	uint32_t orientation;
	uint32_t ifbc_type;
	uint32_t vsync_ctrl_type;
	uint32_t connector_id;
	uint32_t lcd_te_idx; /* 0: te0, 1: te1 */
	uint8_t aod_enable;
	uint8_t update_core_clk_support;
	uint8_t rsv[2];
	uint32_t fake_panel_flag;
	uint32_t esd_enable;
	enum product_type product_type;
	struct esd_panel_info esd_info;
	struct mipi_panel_info mipi;
	struct user_panel_info user_info;
	struct input_dsc_info input_dsc_info;
	struct bl_info bl_info;
	struct dfr_info dfr_info;
	struct panel_refresh_statistic_rslt stat_rslt;
	struct spr_info spr;
	struct panel_special_config panel_spcl_cfg;
};

struct dpu_panel_ops {
	int32_t (*set_fastboot)(void);
	int32_t (*on)(void);
	int32_t (*off)(void);
	int32_t (*set_backlight)(uint32_t bl_level);
	struct dpu_panel_info *(*get_panel_info)(void);
	int (*set_display_region)(struct dkmd_rect *dirty);
	int32_t (*disp_postprocess)(struct device *dev);
	int32_t (*dump_exception_info)(void);
	int32_t (*set_current_fps)(uint32_t current_fps);
	int32_t (*check_lcd_status)(void);
	int32_t (*get_ddic_cmds)(const struct disp_effect_params *effect_params, struct dsi_cmds *dsi_cmds);
	int32_t (*trace_screen_bl)(uint32_t bl_level);
	int32_t (*update_lcd_fps)(uint32_t target_fps);
	int32_t (*esd_handle)(void);
	int32_t (*update_fps_te_mode)(uint32_t target_fps);
	int32_t (*update_fps_pfm_mode)(uint32_t target_fps);
};

struct product_display_ops {
	int32_t (*fb_ioctl)(uint32_t cmd, uint64_t arg);
};

enum {
	MIPI_DSI_INDEX0 = 0,
	MIPI_DSI_INDEX1,
	MIPI_DSI_INDEX2,
	MIPI_DSI_INDEX_MAX,
};

void mipi_dsi_set_lp_mode(uint32_t dsi_idx, uint32_t panel_type);
void mipi_dsi_set_hs_mode(uint32_t dsi_idx, uint32_t panel_type);

int32_t mipi_dsi_cmds_tx_for_usr(uint32_t dsi_idx, struct dsi_cmd_desc *cmds, int32_t cnt, uint32_t panel_type);
int32_t mipi_dsi_cmds_tx_for_usr_isr_safe(uint32_t dsi_idx, struct dsi_cmd_desc *cmds, int32_t cnt,
	uint32_t panel_type);
int32_t mipi_dsi_cmds_rx_for_usr(uint32_t dsi_idx, uint8_t *out,
	int out_len, struct dsi_cmd_desc *cm, bool little_endian_support,  uint32_t panel_type);

int32_t mipi_dual_dsi_cmds_tx_for_usr(uint32_t dsi_idx0, struct dsi_cmd_desc *cmds0,
	int32_t cnt0, uint32_t dsi_idx1, struct dsi_cmd_desc *cmds1, int32_t cnt1, uint8_t tx_mode, uint32_t panel_type);
int32_t mipi_dual_dsi_cmds_tx_for_usr_isr_safe(uint32_t dsi_idx0, struct dsi_cmd_desc *cmds0,
	int32_t cnt0, uint32_t dsi_idx1, struct dsi_cmd_desc *cmds1, int32_t cnt1, uint8_t tx_mode, uint32_t panel_type);
int32_t mipi_dual_dsi_cmds_rx_for_usr(uint32_t dsi_idx0, uint8_t *dsi_out0, uint32_t dsi_idx1, uint8_t *dsi_out1,
	int out_len, struct dsi_cmd_desc *cm, bool little_endian_support, uint32_t panel_type);

uint32_t dkmd_get_lcd_status(void);
void dkmd_set_lcd_status(uint32_t bit, uint32_t bit_value);
extern struct dsm_client* dkmd_get_dmd_client(void);

extern int32_t register_panel(struct dpu_panel_ops *pops, uint32_t panel_id);
extern int32_t get_panel_refresh_count(uint32_t panel_id, struct panel_refresh_statistic_info *refresh_stat_info);
extern int32_t regitster_product_ops(struct product_display_ops* ops);

#endif

