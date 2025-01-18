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

#include <linux/module.h>
#include "dpu_dp_dbg.h"
#include "dp_ctrl.h"
#include "dp_aux.h"
#include "dp_drv.h"
#include "dp_ctrl_dev.h"
#include <huawei_platform/dp_source/dp_source_switch.h>
#include "controller/psr/psr_config_base.h"
#include "dp_hdr.h"
#include "dpu_dp_dbg_v740.h"
#include "hidptx/hidptx_reg.h"
#include <platform_include/see/bl31_smc.h>
#include <platform_include/display/linux/dpu_drmdriver.h>
#include <securec.h>

/*******************************************************************************
 * DP GRAPHIC DEBUG TOOL
 */
static int32_t g_dp_id = -1;
int g_clk_hblank_code_enable = 0;
/* 27M, 720*480 */
uint32_t g_pixel_clock = 27000;
uint32_t g_video_code = 3;
uint32_t g_hblank = 138;
/*
 * for debug, S_IRUGO
 * /sys/module/dp_ctrl/parameters
 */
int g_dp_debug_mode_enable = 0;
static uint32_t g_dp_preemphasis_swing[DPTX_COMBOPHY_PARAM_NUM];
int g_dp_pe_sw_length = 0;
static uint32_t g_dp_preemphasis_swing1[DPTX_COMBOPHY_PARAM_NUM];
int g_dp_pe_sw_attach_length = 0;
int g_dp_vactive_pixels_debug = 0;
int g_dp_hactive_pixels_debug = 3840;
int g_dp_same_source_debug = 1;
/* rate and ssc config, rate_coef0, rate_coef1, rate_coef2 */
uint32_t g_dp_rbr_pll1_rate0_coef[4] = {0x6546061C, 0x54600000, 0xA900AB, 0x131};
int g_dp_rbr_pll1_rate0_coef_length = 0;
uint32_t g_dp_hbr_pll1_rate1_coef[4] = {0x64640618, 0x46500000, 0x8C008E, 0x131};
int g_dp_hbr_pll1_rate1_coef_length = 0;
uint32_t g_dp_hbr2_pll1_rate2_coef[4] = {0x64640615, 0x46500000, 0x8C008E, 0x131};
int g_dp_hbr2_pll1_rate2_coef_length = 0;
uint32_t g_dp_hbr3_pll1_rate3_coef[4] = {0x46960610, 0x69780000, 0xD300D5, 0x131};
int g_dp_hbr3_pll1_rate3_coef_length = 0;
uint32_t g_edp_r216_rate0_coef[4] = {0x47083418, 0x70800000, 0xE200E4, 0x131};
int g_edp_r216_rate0_coef_length = 0;
uint32_t g_edp_r243_rate1_coef[4] = {0x63F43418, 0x3F480000, 0x7E0080, 0x131};
int g_edp_r243_rate1_coef_length = 0;
uint32_t g_edp_r324_rate2_coef[4] = {0x65463418, 0x54600000, 0xA900AB, 0x131};
int g_edp_r324_rate2_coef_length = 0;
uint32_t g_edp_r432_rate3_coef[4] = {0x47083414, 0x70800000, 0xE200E4, 0x131};
int g_edp_r432_rate3_coef_length = 0;
uint32_t g_edp_custom_rate4_coef[4] = {0x44103410, 0x69780000, 0xD300D5, 0x131};
int g_edp_custom_rate4_coef_length = 0;

int g_update_region_flag = 0;

#ifdef CONFIG_DKMD_DEBUG_ENABLE
module_param_named(dp_debug_mode_enable, g_dp_debug_mode_enable, int, 0640);
MODULE_PARM_DESC(dp_debug_mode_enable, "dp_debug_mode_enable");

module_param_array_named(dp_preemphasis_swing, g_dp_preemphasis_swing, uint, &g_dp_pe_sw_length, 0640);
MODULE_PARM_DESC(dp_preemphasis_swing, "dp_preemphasis_swing");

module_param_array_named(dp_preemphasis_swing1, g_dp_preemphasis_swing1,
	uint, &g_dp_pe_sw_attach_length, 0640);
MODULE_PARM_DESC(dp_preemphasis_swing1, "dp_preemphasis_swing1");

module_param_named(dp_vactive_pixels, g_dp_vactive_pixels_debug, int, 0640);
MODULE_PARM_DESC(dp_vactive_pixels, "dp_vactive_pixels");

module_param_named(dp_hactive_pixels, g_dp_hactive_pixels_debug, int, 0640);
MODULE_PARM_DESC(dp_hactive_pixels, "dp_hactive_pixels");

module_param_named(dp_same_source_debug, g_dp_same_source_debug, int, 0640);
MODULE_PARM_DESC(dp_same_source_debug, "dp_same_source_debug");

module_param_array_named(dp_rbr_pll1_rate0_coef, g_dp_rbr_pll1_rate0_coef,
	uint, &g_dp_rbr_pll1_rate0_coef_length, 0640);
MODULE_PARM_DESC(dp_rbr_pll1_rate0_coef, "dp_rbr_pll1_rate0_coef");

module_param_array_named(dp_hbr_pll1_rate1_coef, g_dp_hbr_pll1_rate1_coef,
	uint, &g_dp_hbr_pll1_rate1_coef_length, 0640);
MODULE_PARM_DESC(dp_hbr_pll1_rate1_coef, "dp_hbr_pll1_rate1_coef");

module_param_array_named(dp_hbr2_pll1_rate2_coef, g_dp_hbr2_pll1_rate2_coef, uint,
	&g_dp_hbr2_pll1_rate2_coef_length, 0640);
MODULE_PARM_DESC(dp_hbr2_pll1_rate2_coef, "dp_hbr2_pll1_rate2_coef");

module_param_array_named(dp_hbr3_pll1_rate3_coef, g_dp_hbr3_pll1_rate3_coef, uint,
	&g_dp_hbr3_pll1_rate3_coef_length, 0640);
MODULE_PARM_DESC(dp_hbr3_pll1_rate3_coef, "dp_hbr3_pll1_rate3_coef");

module_param_array_named(edp_r216_rate0_coef, g_edp_r216_rate0_coef, uint,
	&g_edp_r216_rate0_coef_length, 0640);
MODULE_PARM_DESC(edp_r216_rate0_coef, "edp_r216_rate0_coef");

module_param_array_named(edp_r243_rate1_coef, g_edp_r243_rate1_coef, uint,
	&g_edp_r243_rate1_coef_length, 0640);
MODULE_PARM_DESC(edp_r243_rate1_coef, "edp_r243_rate1_coef");

module_param_array_named(edp_r324_rate2_coef, g_edp_r324_rate2_coef, uint,
	&g_edp_r324_rate2_coef_length, 0640);
MODULE_PARM_DESC(edp_r324_rate2_coef, "edp_r324_rate2_coef");

module_param_array_named(edp_r432_rate3_coef, g_edp_r432_rate3_coef, uint,
	&g_edp_r432_rate3_coef_length, 0640);
MODULE_PARM_DESC(edp_r432_rate3_coef, "edp_r432_rate3_coef");

module_param_array_named(edp_custom_rate4_coef, g_edp_custom_rate4_coef, uint,
	&g_edp_custom_rate4_coef_length, 0640);
MODULE_PARM_DESC(edp_custom_rate4_coef, "edp_custom_rate4_coef");
#endif

#define DPTX_PHYIF_CTRL_RATE_RBR	0x0
#define DPTX_PHYIF_CTRL_RATE_HBR	0x1
#define DPTX_PHYIF_CTRL_RATE_HBR2	0x2
#define DPTX_PHYIF_CTRL_RATE_HBR3	0x3
#define DPTX_PHYIF_CTRL_EDP_RATE_R216	0x4
#define DPTX_PHYIF_CTRL_EDP_RATE_R243	0x5
#define DPTX_PHYIF_CTRL_EDP_RATE_R324	0x6
#define DPTX_PHYIF_CTRL_EDP_RATE_R432	0x7
#define DPTX_PHYIF_CTRL_EDP_RATE_CUSTOM	0x8
#define DPTX_AUX_CTRL_OFFSET 0x24

struct dp_debug_params {
	int dp_lane_num_debug;
	int dp_lane_rate_debug;
	int dp_mst_enable_debug;
	int dp_ssc_enable_debug;
	int dp_fec_enable_debug;
	int dp_dsc_enable_debug;
	int dp_efm_enable_debug;
	int dp_vactive_pixels_debug;
	int dp_hactive_pixels_debug;
	uint dp_aux_ctrl;

	uint32_t dp_rbr_pll1_rate0_coef[4];
	uint32_t dp_hbr_pll1_rate1_coef[4];
	uint32_t dp_hbr2_pll1_rate2_coef[4];
	uint32_t dp_hbr3_pll1_rate3_coef[4];
	uint32_t edp_r216_rate0_coef[4];
	uint32_t edp_r243_rate1_coef[4];
	uint32_t edp_r324_rate2_coef[4];
	uint32_t edp_r432_rate3_coef[4];
	uint32_t edp_custom_rate4_coef[4];

	int dp_same_source_debug;
	uint32_t dp_preemphasis_swing[DPTX_PREE_SWING_MAX][DPTX_COMBOPHY_PARAM_NUM];
	int dp_pe_sw_length;
	int dp_pe_sw_attach_length;
	int clk_hblank_code_enable;

	uint64_t pixel_clock_debug;
	uint32_t video_code_debug;
	uint16_t hblank_debug;

	int port_id_sync_debug; // In dual-tx synchronization scenarios, port_id_sync and port_id must be synchronous in v740.
	int dpc_index_selected_debug; // 0/1/2
	bool is_double_tx_sync_debug; // the control flag that double edp or dp sync function in v740
	uint32_t pmcc_pll;
	uint32_t dp_mode;
};

static struct dp_ctrl *g_multi_dp_debug_switch[DPTX_PORT_ID_MAX];
static struct dp_debug_params g_dp_params[DPTX_PORT_ID_MAX];

static struct dp_debug_params default_dp_params = {
	4, 2, 0, 0, 0, 0, 1, 0, 3840, 0x11630,
	{0x6546061C, 0x54600000, 0xA900AB, 0x131},
	{0x64640618, 0x46500000, 0x8C008E, 0x131},
	{0x64640615, 0x46500000, 0x8C008E, 0x131},
	{0x46960610, 0x69780000, 0xD300D5, 0x131},
	{0x47083418, 0x70800000, 0xE200E4, 0x131},
	{0x63F43418, 0x3F480000, 0x7E0080, 0x131},
	{0x65463418, 0x54600000, 0xA900AB, 0x131},
	{0x47083414, 0x70800000, 0xE200E4, 0x131},
	{0x44103410, 0x69780000, 0xD300D5, 0x131},
	1, {{}, {}}, 0, 0, 0, 27000, 3, 138, -1, 0, false, 0x7FF0F0F, 0,
};

static void dp_debug_dpc_pll_index_init(struct dp_ctrl *dptx)
{
	switch (dptx->port_id) {
	case DPTX_PORT_ID_0:
	case DPTX_PORT_ID_1:
		g_dp_params[dptx->port_id].dpc_index_selected_debug = DPTX_DPC_NUM_0;
		break;
	case DPTX_PORT_ID_2:
	case DPTX_PORT_ID_4:
		g_dp_params[dptx->port_id].dpc_index_selected_debug = DPTX_DPC_NUM_1;
		break;
	case DPTX_PORT_ID_3:
	case DPTX_PORT_ID_5:
		g_dp_params[dptx->port_id].dpc_index_selected_debug = DPTX_DPC_NUM_2;
		break;
	default:
		dpu_pr_err("[DP] input error port_id %d not support", dptx->port_id);
		return;
	}
}

void dp_graphic_debug_node_init(struct dp_ctrl *dptx)
{
	if (dptx->port_id < DPTX_PORT_ID_0 || dptx->port_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] index or type is invaild, index %d", dptx->port_id);
		return;
	}
	g_multi_dp_debug_switch[dptx->port_id] = dptx;
	g_dp_params[dptx->port_id] = default_dp_params;
	dp_debug_dpc_pll_index_init(dptx);
}

void dptx_debug_get_double_tx_sync_para(struct dp_ctrl *dptx)
{
	dpu_check_and_no_retval(!dptx, err, "[DP] dptx is null pointor!");

	dptx->is_double_tx_sync = g_dp_params[dptx->port_id].is_double_tx_sync_debug;
	dptx->dpc_index_selected = g_dp_params[dptx->port_id].dpc_index_selected_debug;
	dptx->port_id_sync = g_dp_params[dptx->port_id].port_id_sync_debug;
	dpu_pr_info("[DP] dpc_index is %d, port_id_sync is %d", dptx->dpc_index_selected, dptx->port_id_sync);

	return;
}

static bool dp_lane_num_valid(int dp_lane_num_debug)
{
	if (dp_lane_num_debug == 1 || dp_lane_num_debug == 2 || dp_lane_num_debug == 4)
		return true;

	return false;
}

uint32_t dptx_debug_get_combophy_rate_param(struct dp_ctrl *dptx, int dptx_phyif_ctrl_rate,
	uint32_t *ckgctrl, uint32_t *sscginital, uint32_t *sscgcnt, uint32_t *sscgcnt2)
{
	if (dptx->port_id < DPTX_PORT_ID_0 || dptx->port_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] index or type is invaild, index %d", dptx->port_id);
		return 0xff;
	}
	if (g_multi_dp_debug_switch[dptx->port_id] == NULL) {
		dpu_pr_err("[DP] debug dptx is null!");
		return 0xff;
	}

	switch (dptx_phyif_ctrl_rate) {
	case DPTX_PHYIF_CTRL_RATE_RBR:
		*ckgctrl = g_dp_params[dptx->port_id].dp_rbr_pll1_rate0_coef[0];
		*sscginital = g_dp_params[dptx->port_id].dp_rbr_pll1_rate0_coef[1];
		*sscgcnt= g_dp_params[dptx->port_id].dp_rbr_pll1_rate0_coef[2];
		*sscgcnt2 = g_dp_params[dptx->port_id].dp_rbr_pll1_rate0_coef[3];
		break;
	case DPTX_PHYIF_CTRL_RATE_HBR:
		*ckgctrl = g_dp_params[dptx->port_id].dp_hbr_pll1_rate1_coef[0];
		*sscginital = g_dp_params[dptx->port_id].dp_hbr_pll1_rate1_coef[1];
		*sscgcnt= g_dp_params[dptx->port_id].dp_hbr_pll1_rate1_coef[2];
		*sscgcnt2 = g_dp_params[dptx->port_id].dp_hbr_pll1_rate1_coef[3];
		break;
	case DPTX_PHYIF_CTRL_RATE_HBR2:
		*ckgctrl = g_dp_params[dptx->port_id].dp_hbr2_pll1_rate2_coef[0];
		*sscginital = g_dp_params[dptx->port_id].dp_hbr2_pll1_rate2_coef[1];
		*sscgcnt= g_dp_params[dptx->port_id].dp_hbr2_pll1_rate2_coef[2];
		*sscgcnt2 = g_dp_params[dptx->port_id].dp_hbr2_pll1_rate2_coef[3];
		break;
	case DPTX_PHYIF_CTRL_RATE_HBR3:
		*ckgctrl = g_dp_params[dptx->port_id].dp_hbr3_pll1_rate3_coef[0];
		*sscginital = g_dp_params[dptx->port_id].dp_hbr3_pll1_rate3_coef[1];
		*sscgcnt= g_dp_params[dptx->port_id].dp_hbr3_pll1_rate3_coef[2];
		*sscgcnt2 = g_dp_params[dptx->port_id].dp_hbr3_pll1_rate3_coef[3];
		break;
	case DPTX_PHYIF_CTRL_EDP_RATE_R216:
		*ckgctrl = g_dp_params[dptx->port_id].edp_r216_rate0_coef[0];
		*sscginital = g_dp_params[dptx->port_id].edp_r216_rate0_coef[1];
		*sscgcnt= g_dp_params[dptx->port_id].edp_r216_rate0_coef[2];
		*sscgcnt2 = g_dp_params[dptx->port_id].edp_r216_rate0_coef[3];
		break;
	case DPTX_PHYIF_CTRL_EDP_RATE_R243:
		*ckgctrl = g_dp_params[dptx->port_id].edp_r243_rate1_coef[0];
		*sscginital = g_dp_params[dptx->port_id].edp_r243_rate1_coef[1];
		*sscgcnt= g_dp_params[dptx->port_id].edp_r243_rate1_coef[2];
		*sscgcnt2 = g_dp_params[dptx->port_id].edp_r243_rate1_coef[3];
		break;
	case DPTX_PHYIF_CTRL_EDP_RATE_R324:
		*ckgctrl = g_dp_params[dptx->port_id].edp_r324_rate2_coef[0];
		*sscginital = g_dp_params[dptx->port_id].edp_r324_rate2_coef[1];
		*sscgcnt= g_dp_params[dptx->port_id].edp_r324_rate2_coef[2];
		*sscgcnt2 = g_dp_params[dptx->port_id].edp_r324_rate2_coef[3];
		break;
	case DPTX_PHYIF_CTRL_EDP_RATE_R432:
		*ckgctrl = g_dp_params[dptx->port_id].edp_r432_rate3_coef[0];
		*sscginital = g_dp_params[dptx->port_id].edp_r432_rate3_coef[1];
		*sscgcnt= g_dp_params[dptx->port_id].edp_r432_rate3_coef[2];
		*sscgcnt2 = g_dp_params[dptx->port_id].edp_r432_rate3_coef[3];
		break;
	case DPTX_PHYIF_CTRL_EDP_RATE_CUSTOM:
		*ckgctrl = g_dp_params[dptx->port_id].edp_custom_rate4_coef[0];
		*sscginital = g_dp_params[dptx->port_id].edp_custom_rate4_coef[1];
		*sscgcnt= g_dp_params[dptx->port_id].edp_custom_rate4_coef[2];
		*sscgcnt2 = g_dp_params[dptx->port_id].edp_custom_rate4_coef[3];
		break;
	default:
		dpu_pr_err("[DP] Invalid PHY rate %d", dptx_phyif_ctrl_rate);
		return 0xff;
	}

	return 0;
}

static bool dp_lane_rate_valid(int dp_lane_rate_debug)
{
	if (dp_lane_rate_debug >= 0 && dp_lane_rate_debug <= DPTX_PHYIF_CTRL_EDP_RATE_R432)
		return true;
	dpu_pr_err("[DP] Invalid rate %d", dp_lane_rate_debug);
	return false;
}

void dptx_debug_set_params(struct dp_ctrl *dptx)
{
	int i;

	dpu_check_and_no_retval(!dptx, err, "[DP] dptx is null pointor!");

	if (g_dp_debug_mode_enable == 0)
		return;

	if (dptx->port_id < DPTX_PORT_ID_0 || dptx->port_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] index or type is invaild, index %d", dptx->port_id);
		return;
	}
	if (g_multi_dp_debug_switch[dptx->port_id] == NULL) {
		dpu_pr_err("[DP] debug dptx is null!");
		return;
	}

	if (dp_lane_num_valid(g_dp_params[dptx->port_id].dp_lane_num_debug))
		dptx->max_lanes = (uint8_t)g_dp_params[dptx->port_id].dp_lane_num_debug;

	if (dp_lane_rate_valid(g_dp_params[dptx->port_id].dp_lane_rate_debug)) {
		dptx->max_rate = (uint8_t)g_dp_params[dptx->port_id].dp_lane_rate_debug;
		dpu_pr_info("[DP] set rate %d", dptx->max_rate);
	}

	dptx->mst = (bool)g_dp_params[dptx->port_id].dp_mst_enable_debug;
	dptx->ssc_en = (bool)g_dp_params[dptx->port_id].dp_ssc_enable_debug;
	dptx->fec = (bool)g_dp_params[dptx->port_id].dp_fec_enable_debug;
	dptx->dsc = (bool)g_dp_params[dptx->port_id].dp_dsc_enable_debug;
	dptx->efm_en = (bool)g_dp_params[dptx->port_id].dp_efm_enable_debug;

	dptx->connector->conn_info->base.mode = g_dp_params[dptx->port_id].dp_mode;
	dpu_pr_info("[DP] set dp_mode : %d, ssc:%d", dptx->connector->conn_info->base.mode, dptx->ssc_en);

	if (g_dp_params[dptx->port_id].dp_pe_sw_length == DPTX_COMBOPHY_PARAM_NUM) {
		for (i = 0; i < g_dp_params[dptx->port_id].dp_pe_sw_length; i++)
			dptx->combophy_pree_swing[DPTX_PREE_SWING_DEFAULT][i] =
				g_dp_params[dptx->port_id].dp_preemphasis_swing[DPTX_PREE_SWING_DEFAULT][i];
	}
	if (g_dp_params[dptx->port_id].dp_pe_sw_attach_length == DPTX_COMBOPHY_PARAM_NUM) {
		for (i = 0; i < g_dp_params[dptx->port_id].dp_pe_sw_attach_length; i++)
			dptx->combophy_pree_swing[DPTX_PREE_SWING_EXTERA][i] =
				g_dp_params[dptx->port_id].dp_preemphasis_swing[DPTX_PREE_SWING_EXTERA][i];
	}
}

bool dp_debug_get_clk_hblank_enable(struct dp_ctrl *dptx)
{
	if (dptx->port_id < DPTX_PORT_ID_0 || dptx->port_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] index or type is invaild, index %d", dptx->port_id);
		return false;
	}
	if (g_multi_dp_debug_switch[dptx->port_id] == NULL) {
		dpu_pr_err("[DP] debug dptx is null!");
		return false;
	}
	if (g_dp_params[dptx->port_id].clk_hblank_code_enable)
		return true;

	return false;
}

uint dp_debug_get_aux_ctrl_param(struct dp_ctrl *dptx)
{
	if (dptx->port_id < DPTX_PORT_ID_0 || dptx->port_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] index or type is invaild, index %d", dptx->port_id);
		return 0xff;
	}
	if (g_multi_dp_debug_switch[dptx->port_id] == NULL) {
		dpu_pr_err("[DP] debug dptx is null!");
		return 0xff;
	}

	return g_dp_params[dptx->port_id].dp_aux_ctrl;
}

void dp_debug_get_clk_hblank_params(struct dp_ctrl *dptx, uint64_t *pixel_clock,
	uint32_t *video_code, uint16_t *hblank)
{
	*pixel_clock = g_pixel_clock;
	*video_code = g_video_code;
	*hblank = g_hblank;

	if (dptx->port_id < DPTX_PORT_ID_0 || dptx->port_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] index or type is invaild, index %d", dptx->port_id);
		return;
	}
	if (g_multi_dp_debug_switch[dptx->port_id] == NULL) {
		dpu_pr_err("[DP] debug dptx is null!");
		return;
	}

	*pixel_clock = g_dp_params[dptx->port_id].pixel_clock_debug;
	*video_code = g_dp_params[dptx->port_id].video_code_debug;
	*hblank = g_dp_params[dptx->port_id].hblank_debug;
}

int dp_debug_set_double_tx_sync_para(bool is_double_tx_sync, int dpc_index_selected, int port_id_sync)
{
	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] port id %d is invaild, please reset!", g_dp_id);
		return 0xff;
	}

	g_dp_params[g_dp_id].is_double_tx_sync_debug = is_double_tx_sync;
	g_dp_params[g_dp_id].dpc_index_selected_debug = dpc_index_selected;
	g_dp_params[g_dp_id].port_id_sync_debug = port_id_sync;
	dpu_pr_info("[DP] dp_debug_set_double_tx_sync_para set is_double_tx_sync: %d, dpc_index_selected:%d, port_id_sync:%d",
		is_double_tx_sync?1:0, dpc_index_selected, port_id_sync);
	return 0;
}

int dp_debug_set_lane_num(int lane_num)
{
	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] port id %d is invaild, please reset!", g_dp_id);
		return 0xff;
	}

	if (lane_num > 4 || lane_num < 1) {
		dpu_pr_err("[DP] lane_num is invaild, lane_num %d", lane_num);
		return 0xff;
	}

	g_dp_params[g_dp_id].dp_lane_num_debug = lane_num;
	dpu_pr_info("[DP] dp_debug_set_lane_num set lane_num: %d", lane_num);
	return 0;
}

int dp_debug_get_lane_num(void)
{
	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] port id %d is invaild, please reset!", g_dp_id);
		return 0xff;
	}
	dpu_pr_info("[DP] dp_debug_get_lane_num get dp_lane_num_debug: %d", g_dp_params[g_dp_id].dp_lane_num_debug);
	return g_dp_params[g_dp_id].dp_lane_num_debug;
}

int dp_debug_set_pll_value(uint32_t value)
{
	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] port id %d is invaild, please reset!", g_dp_id);
		return 0xff;
	}
	g_dp_params[g_dp_id].pmcc_pll = value;
	dpu_pr_info("[DP] dp_debug_set_pll_value set lane_num: %u", value);
	return 0;
}

uint32_t dp_debug_get_pll_value(void)
{
	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] port id %d is invaild, please reset!", g_dp_id);
		return 0xff;
	}
	dpu_pr_info("[DP] dp_debug_get_pll_value get pmcc_pll: %u", g_dp_params[g_dp_id].pmcc_pll);
	return g_dp_params[g_dp_id].pmcc_pll;
}

int dp_debug_set_lane_rate(int lane_rate)
{
	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] port id %d is invaild, please reset!", g_dp_id);
		return 0xff;
	}
	g_dp_params[g_dp_id].dp_lane_rate_debug = lane_rate;
	dpu_pr_info("[DP] dp_debug_set_lane_rate set lane_rate: %d", lane_rate);
	return 0;
}

int dp_debug_get_lane_rate(void)
{
	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] port id %d is invaild, please reset!", g_dp_id);
		return 0xff;
	}
	dpu_pr_info("[DP] dp_debug_get_lane_rate get dp_lane_rate_debug: %d", g_dp_params[g_dp_id].dp_lane_rate_debug);
	return g_dp_params[g_dp_id].dp_lane_rate_debug;
}

int dp_debug_set_mst_mode(int mst_mode)
{
	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] port id %d is invaild, please reset!", g_dp_id);
		return 0xff;
	}
	g_dp_params[g_dp_id].dp_mst_enable_debug = mst_mode;
	dpu_pr_info("[DP] dp_debug_set_mst_mode set mst_mode: %d", mst_mode);
	return 0;
}

int dp_debug_get_mst_mode(void)
{
	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] port id %d is invaild, please reset!", g_dp_id);
		return 0xff;
	}
	dpu_pr_info("[DP] dp_debug_get_mst_mode get dp_mst_enable_debug: %d", g_dp_params[g_dp_id].dp_mst_enable_debug);
	return g_dp_params[g_dp_id].dp_mst_enable_debug;
}

int dp_debug_set_ssc_mode(int ssc_mode)
{
	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] port id %d is invaild, please reset!", g_dp_id);
		return 0xff;
	}
	g_dp_params[g_dp_id].dp_ssc_enable_debug = ssc_mode;
	dpu_pr_info("[DP] dp_debug_set_ssc_mode set ssc_mode: %d", ssc_mode);
	return 0;
}

int dp_debug_get_ssc_mode(void)
{
	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] port id %d is invaild, please reset!", g_dp_id);
		return 0xff;
	}
	dpu_pr_info("[DP] dp_debug_get_ssc_mode get dp_ssc_enable_debug: %d", g_dp_params[g_dp_id].dp_ssc_enable_debug);
	return g_dp_params[g_dp_id].dp_ssc_enable_debug;
}

int dp_debug_set_fec_mode(int fec_mode)
{
	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] port id %d is invaild, please reset!", g_dp_id);
		return 0xff;
	}
	g_dp_params[g_dp_id].dp_fec_enable_debug = fec_mode;
	dpu_pr_info("[DP] dp_debug_set_fec_mode set fec_mode: %d", fec_mode);
	return 0;
}

int dp_debug_get_fec_mode(void)
{
	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] port id %d is invaild, please reset!", g_dp_id);
		return 0xff;
	}
	dpu_pr_info("[DP] dp_debug_get_fec_mode get dp_fec_enable_debug: %d", g_dp_params[g_dp_id].dp_fec_enable_debug);
	return g_dp_params[g_dp_id].dp_fec_enable_debug;
}

int dp_debug_set_dsc_mode(int dsc_mode)
{
	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] port id %d is invaild, please reset!", g_dp_id);
		return 0xff;
	}
	g_dp_params[g_dp_id].dp_dsc_enable_debug = dsc_mode;
	dpu_pr_info("[DP] dp_debug_set_dsc_mode set dsc_mode: %d", dsc_mode);
	return 0;
}

int dp_debug_get_dsc_mode(void)
{
	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] port id %d is invaild, please reset!", g_dp_id);
		return 0xff;
	}
	dpu_pr_info("[DP] dp_debug_get_dsc_mode get dp_dsc_enable_debug: %d", g_dp_params[g_dp_id].dp_dsc_enable_debug);
	return g_dp_params[g_dp_id].dp_dsc_enable_debug;
}

int dp_debug_set_dp_mode(int dp_mode)
{
	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] port id %d is invaild, please reset!", g_dp_id);
		return 0xff;
	}
	g_dp_params[g_dp_id].dp_mode = (uint32_t)dp_mode;
	dpu_pr_info("[DP] dp_debug_set_dp_mode set dp_mode: %d", dp_mode);
	return 0;
}

int dp_debug_get_dp_mode(void)
{
	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] port id %d is invaild, please reset!", g_dp_id);
		return 0xff;
	}
	dpu_pr_info("[DP] dp_debug_get_dp_mode get dp_mode_enable_debug: %d", g_dp_params[g_dp_id].dp_mode);
	return (int)g_dp_params[g_dp_id].dp_mode;
}

int dp_debug_combophy_set_rate(void)
{
	int i;

	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] port id %d is invaild, please reset!", g_dp_id);
		return 0xff;
	}
	dpu_pr_info("[DP] dp_debug_combophy_set_rate port id %d, length:%d", g_dp_id, g_dp_rbr_pll1_rate0_coef_length);
	for (i = 0; i < g_dp_rbr_pll1_rate0_coef_length; i++) {
		g_dp_params[g_dp_id].dp_rbr_pll1_rate0_coef[i] = g_dp_rbr_pll1_rate0_coef[i];
		g_dp_params[g_dp_id].dp_hbr_pll1_rate1_coef[i] = g_dp_hbr_pll1_rate1_coef[i];
		g_dp_params[g_dp_id].dp_hbr2_pll1_rate2_coef[i] = g_dp_hbr2_pll1_rate2_coef[i];
		g_dp_params[g_dp_id].dp_hbr3_pll1_rate3_coef[i] = g_dp_hbr3_pll1_rate3_coef[i];
		g_dp_params[g_dp_id].edp_r216_rate0_coef[i] = g_edp_r216_rate0_coef[i];
		g_dp_params[g_dp_id].edp_r243_rate1_coef[i] = g_edp_r243_rate1_coef[i];
		g_dp_params[g_dp_id].edp_r324_rate2_coef[i] = g_edp_r324_rate2_coef[i];
		g_dp_params[g_dp_id].edp_r432_rate3_coef[i] = g_edp_r432_rate3_coef[i];
		g_dp_params[g_dp_id].edp_custom_rate4_coef[i] = g_edp_custom_rate4_coef[i];
		dpu_pr_info("[DP] [%d]dp_debug_combophy_set_rate set rate: 1. %llx, 2. %llx, 3. %llx, 4. %llx, 5. %llx, \
			6. %llx, 7. %llx, 8. %llx, 9. %llx", i, g_dp_rbr_pll1_rate0_coef[i], g_dp_hbr_pll1_rate1_coef[i],
			g_dp_hbr2_pll1_rate2_coef[i], g_dp_hbr3_pll1_rate3_coef[i], g_edp_r216_rate0_coef[i],
			g_edp_r243_rate1_coef[i], g_edp_r324_rate2_coef[i], g_edp_r432_rate3_coef[i], g_edp_custom_rate4_coef[i]);
	}
	return 0;
}

int dp_debug_set_efm_mode(int efm_mode)
{
	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] port id %d is invaild, please reset!", g_dp_id);
		return 0xff;
	}
	if (g_multi_dp_debug_switch[g_dp_id] == NULL) {
		dpu_pr_err("[DP] debug dptx is null!");
		return 0xff;
	}
	g_dp_params[g_dp_id].dp_efm_enable_debug = efm_mode;
	dpu_pr_info("[DP] dp_debug_set_efm_mode set efm_mode: %d, g_dp_id:%d", efm_mode, g_dp_id);
	return 0;
}

int dp_debug_get_efm_mode(void)
{
	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] port id %d is invaild, please reset!", g_dp_id);
		return 0xff;
	}
	if (g_multi_dp_debug_switch[g_dp_id] == NULL) {
		dpu_pr_err("[DP] debug dptx is null!");
		return 0xff;
	}
	dpu_pr_info("[DP] dp_debug_get_efm_mode get dp_efm_enable_debug: %d", g_dp_params[g_dp_id].dp_efm_enable_debug);
	return g_dp_params[g_dp_id].dp_efm_enable_debug;
}

int dp_debug_set_aux_ctrl(uint aux_ctrl)
{
	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] port id %d is invaild, please reset!", g_dp_id);
		return 0xff;
	}
	if (g_multi_dp_debug_switch[g_dp_id] == NULL) {
		dpu_pr_err("[DP] debug dptx is null!");
		return 0xff;
	}
	g_dp_params[g_dp_id].dp_aux_ctrl = aux_ctrl;
	dpu_pr_info("[DP] dp_debug_set_aux_ctrl set aux_ctrl: %u, g_dp_id:%d", aux_ctrl, g_dp_id);
	return 0;
}

int dp_debug_get_aux_ctrl(void)
{
	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] port id %d is invaild, please reset!", g_dp_id);
		return 0xff;
	}
	if (g_multi_dp_debug_switch[g_dp_id] == NULL) {
		dpu_pr_err("[DP] debug dptx is null!");
		return 0xff;
	}
	dpu_pr_info("[DP] dp_debug_get_aux_ctrl get dp_aux_ctrl: %u", g_dp_params[g_dp_id].dp_aux_ctrl);
	return (int)g_dp_params[g_dp_id].dp_aux_ctrl;
}

int dp_debug_set_preemphasis_swing(void)
{
	int i;

	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] port id %d is invaild, please reset!", g_dp_id);
		return 0xff;
	}
	g_dp_params[g_dp_id].dp_pe_sw_length = g_dp_pe_sw_length;
	for (i = 0; i < g_dp_pe_sw_length; i++) {
		g_dp_params[g_dp_id].dp_preemphasis_swing[DPTX_PREE_SWING_DEFAULT][i] =
			g_dp_preemphasis_swing[i];
		dpu_pr_info("[DP] dp_debug_set_preemphasis_swing set swing[%d]: %llx", i, g_dp_preemphasis_swing[i]);
	}

	g_dp_params[g_dp_id].dp_pe_sw_attach_length = g_dp_pe_sw_attach_length;
	for (i = 0; i < g_dp_pe_sw_attach_length; i++) {
		g_dp_params[g_dp_id].dp_preemphasis_swing[DPTX_PREE_SWING_EXTERA][i] =
			g_dp_preemphasis_swing1[i];
		dpu_pr_info("[DP] dp_debug_set_preemphasis_swing set swing[%d]: %llx", i, g_dp_preemphasis_swing1[i]);
	}

	return 0;
}

int dp_debug_dptx_connected(void)
{
	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] port id %d is invaild, please reset!", g_dp_id);
		return 0xff;
	}
	dpu_pr_err("[DP] dp_debug_dptx_connected");
	if (g_multi_dp_debug_switch[g_dp_id]->video_transfer_enable)
		return 1;

	return 0;
}

int dp_debug_read_dpcd(uint32_t addr)
{
	uint8_t byte = 0;
	int retval;
	struct dp_ctrl *dptx = NULL;

	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] port id %d is invaild, please reset!", g_dp_id);
		return 0xff;
	}
	dptx = g_multi_dp_debug_switch[g_dp_id];
	if (!dptx || !dptx->dptx_enable || dptx->power_saving_mode) {
		dpu_pr_err("[DP] port id %d not exist or has already been off!", g_dp_id);
		return 0xff;
	}
	dpu_pr_info("[DP] dp_debug_read_dpcd g_dp_id:%d flag\n", g_dp_id);
	retval = dptx_read_dpcd(dptx, addr, &byte);
	if (retval) {
		   dpu_pr_err("[DP] read dpcd fail");
		   return retval;
	}
	dpu_pr_info("[DP] dp_debug_read_dpcd port id is %d ", g_dp_id);
	return (int)byte;
}

int dp_debug_write_dpcd(uint32_t addr, uint8_t byte)
{
	int retval;
	struct dp_ctrl *dptx = NULL;

	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] port id %d is invaild, please reset!", g_dp_id);
		return 0xff;
	}
	dptx = g_multi_dp_debug_switch[g_dp_id];
	if (!dptx || !dptx->dptx_enable || dptx->power_saving_mode) {
		dpu_pr_err("[DP] port id %d not exist or has already been off!", g_dp_id);
		return 0xff;
	}
	retval = dptx_write_dpcd(dptx, addr, byte);
	if (retval) {
		dpu_pr_err("[DP] write dpcd fail");
		return retval;
	}
	dpu_pr_info("[DP] dp_debug_write_dpcd port id is %d ", g_dp_id);
	return 0;
}

int set_dp_rx_tx_mode(uint32_t dp_rx_tx_mode)
{
	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] port id %d is invaild, please reset!", g_dp_id);
		return 0xff;
	}
	g_multi_dp_debug_switch[g_dp_id]->source_is_external = dp_rx_tx_mode;
	return 0;
}

int set_dp_rx_tx_arsr_mode(uint32_t dp_rx_tx_arsr_mode)
{
	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] port id %d is invaild, please reset!", g_dp_id);
		return 0xff;
	}
	g_multi_dp_debug_switch[g_dp_id]->arsr_enable = dp_rx_tx_arsr_mode;
	dpu_pr_info("[DP] set_dp_rx_tx_arsr_mode set dp_rx_tx_arsr_mode: %u", dp_rx_tx_arsr_mode);
	return 0;
}

int set_dp_mode(uint32_t mode)
{
	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] port id %d is invaild, please reset!", g_dp_id);
		return 0xff;
	}
	if (mode >= DP_MODE_MAX)
		mode = DP_MODE;

	g_multi_dp_debug_switch[g_dp_id]->connector->conn_info->base.mode = mode;
	dpu_pr_info("[DP] set_dp_mode set dp_mode: %u", mode);
	return 0;
}

int set_clk_hblank_code(uint32_t clock, uint32_t hblank, uint32_t code)
{
	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] port id %d is invaild, please reset!", g_dp_id);
		return 0xff;
	}
	g_dp_params[g_dp_id].pixel_clock_debug = clock;
	g_dp_params[g_dp_id].hblank_debug = hblank;
	g_dp_params[g_dp_id].video_code_debug = code;
	dpu_pr_info("[DP] set_clk_hblank_code set pixel_clock_debug: %u, pixel_clock_debug: %u, pixel_clock_debug: %u",
		clock, hblank, code);
	return 0;
}

int set_dp_psr_mode(uint32_t mode)
{
	struct dp_ctrl *dptx = NULL;

	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] index or type is invaild, index %d", g_dp_id);
		return 0xff;
	}

	if (g_multi_dp_debug_switch[g_dp_id] == NULL) {
		dpu_pr_err("[DP] debug dptx is null!");
		return 0xff;
	}

	dptx = g_multi_dp_debug_switch[g_dp_id];
	if (!dptx || !dptx->dptx_enable || dptx->power_saving_mode) {
		dpu_pr_err("[DP] port id %d not exist or has already been off!", g_dp_id);
		return 0xff;
	}

	if (mode > PSR_EXIT)
		dptx_psr_entry(g_multi_dp_debug_switch[g_dp_id]);
	else
		dptx_change_psr_status(g_multi_dp_debug_switch[g_dp_id], mode);
	dpu_pr_info("[DP] set_dp_psr_mode mode:%u", mode);
	return 0;
}

int select_dp_port(int port_id)
{
	if (port_id < DPTX_PORT_ID_0 || port_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] index or type is invaild, index %d", port_id);
		return 0xff;
	}

	if (g_multi_dp_debug_switch[port_id] == NULL) {
		dpu_pr_err("[DP] debug dptx is null!");
		return 0xff;
	}

	dpu_pr_info("[DP] select_dp_port port_id:%d", port_id);
	return g_dp_id = port_id;
}

int dpu_dp_get_current_dp_source_mode(void)
{
	return get_current_dp_source_mode();
}

// ---------------------------- PSR ---------------------------------

void dptx_psr_hdcp_status_test(bool enable)
{
	struct dp_ctrl *dptx = NULL;

	uint32_t status;
	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] index or type is invaild, index %d", g_dp_id);
		return;
	}

	if (g_multi_dp_debug_switch[g_dp_id] == NULL) {
		dpu_pr_err("[DP] debug dptx is null!");
		return;
	}

	dptx = g_multi_dp_debug_switch[g_dp_id];
	if (!dptx || !dptx->dptx_enable || dptx->power_saving_mode) {
		dpu_pr_err("[DP] port id %d not exist or has already been off!", g_dp_id);
		return;
	}

	status = enable ? 1 : 0;
	dpu_pr_info("[DP] [port_id:%d] status:%d", g_dp_id, status);
	configure_dss_service_security(FID_BL31_DISPLAY_HSDT_PLL_DP_CONFIG, g_dp_id, status, 0);

	return;
}

void dptx_psr_entry_test(void)
{
	struct dp_ctrl *dptx = NULL;

	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] index or type is invaild, index %d", g_dp_id);
		return;
	}

	if (g_multi_dp_debug_switch[g_dp_id] == NULL) {
		dpu_pr_err("[DP] debug dptx is null!");
		return;
	}

	dptx = g_multi_dp_debug_switch[g_dp_id];
	if (!dptx || !dptx->dptx_enable || dptx->power_saving_mode) {
		dpu_pr_err("[DP] port id %d not exist or has already been off!", g_dp_id);
		return;
	}

	g_multi_dp_debug_switch[g_dp_id]->psr_params.psr_version = 1;
	dpu_pr_info("[DP] dptx_psr_entry_test start");
	dptx_psr_entry(g_multi_dp_debug_switch[g_dp_id]);
}

void dptx_psr_update_test(void)
{
	struct dp_ctrl *dptx = NULL;

	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] index or type is invaild, index %d", g_dp_id);
		return;
	}

	if (g_multi_dp_debug_switch[g_dp_id] == NULL) {
		dpu_pr_err("[DP] debug dptx is null!");
		return;
	}

	dptx = g_multi_dp_debug_switch[g_dp_id];
	if (!dptx || !dptx->dptx_enable || dptx->power_saving_mode) {
		dpu_pr_err("[DP] port id %d not exist or has already been off!", g_dp_id);
		return;
	}

	dpu_pr_info("[DP] dptx_psr_update_test start");
	dptx_change_psr_status(g_multi_dp_debug_switch[g_dp_id], PSR_UPDATE);
}

void dptx_psr_exit_test(void)
{
	struct dp_ctrl *dptx = NULL;

	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] index or type is invaild, index %d", g_dp_id);
		return;
	}

	if (g_multi_dp_debug_switch[g_dp_id] == NULL) {
		dpu_pr_err("[DP] debug dptx is null!");
		return;
	}

	dptx = g_multi_dp_debug_switch[g_dp_id];
	if (!dptx || !dptx->dptx_enable || dptx->power_saving_mode) {
		dpu_pr_err("[DP] port id %d not exist or has already been off!", g_dp_id);
		return;
	}

	dpu_pr_info("[DP] dptx_psr_update_test start");
	dptx_change_psr_status(g_multi_dp_debug_switch[g_dp_id], PSR_EXIT);
}

void dptx_burst_psr_update(void)
{
	struct dp_ctrl *dptx = NULL;

	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] index or type is invaild, index %d", g_dp_id);
		return;
	}

	if (g_multi_dp_debug_switch[g_dp_id] == NULL) {
		dpu_pr_err("[DP] debug dptx is null!");
		return;
	}

	dptx = g_multi_dp_debug_switch[g_dp_id];
	if (!dptx || !dptx->dptx_enable || dptx->power_saving_mode) {
		dpu_pr_err("[DP] port id %d not exist or has already been off!", g_dp_id);
		return;
	}

	g_dptx_psr_burst_update_flag = 1;
	dpu_pr_info("[DP] dptx_burst_psr_update start");
	dptx_change_psr_status(g_multi_dp_debug_switch[g_dp_id], PSR_UPDATE);
}

void dptx_psr_update_after_entry_test(void)
{
	struct dp_ctrl *dptx = NULL;

	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] index or type is invaild, index %d", g_dp_id);
		return;
	}

	if (g_multi_dp_debug_switch[g_dp_id] == NULL) {
		dpu_pr_err("[DP] debug dptx is null!");
		return;
	}

	dptx = g_multi_dp_debug_switch[g_dp_id];
	if (!dptx || !dptx->dptx_enable || dptx->power_saving_mode) {
		dpu_pr_err("[DP] port id %d not exist or has already been off!", g_dp_id);
		return;
	}

	g_dptx_psr_update_after_entry_flag = 1;
	dpu_pr_info("[DP] dptx_psr_update_after_entry_test start");
	dptx_psr_entry(g_multi_dp_debug_switch[g_dp_id]);
}

void dptx_psr_exit_after_update_test(void)
{
	struct dp_ctrl *dptx = NULL;

	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] index or type is invaild, index %d", g_dp_id);
		return;
	}

	if (g_multi_dp_debug_switch[g_dp_id] == NULL) {
		dpu_pr_err("[DP] debug dptx is null!");
		return;
	}

	dptx = g_multi_dp_debug_switch[g_dp_id];
	if (!dptx || !dptx->dptx_enable || dptx->power_saving_mode) {
		dpu_pr_err("[DP] port id %d not exist or has already been off!", g_dp_id);
		return;
	}

	g_dptx_psr_exit_after_update_flag = 1;
	dpu_pr_info("[DP] dptx_psr_exit_after_update_test start");
	dptx_change_psr_status(g_multi_dp_debug_switch[g_dp_id], PSR_UPDATE);
}

void dptx_psr_pre_test(void)
{
	uint32_t i = 4;
	dpu_pr_info("[DP] dptx_psr_pre_test start");
	while(1) {
		if (i > 1000)
			i = 4;
		dptx_psr_entry_test();
		msleep(i);
		dptx_psr_update_test();
		msleep(i);
		dptx_psr_exit_test();
		msleep(i);
		dptx_psr_update_after_entry_test();
		msleep(i);
		dptx_burst_psr_update();
		msleep(i);
		dptx_psr_exit_after_update_test();
		msleep(i);
		dpu_pr_info("[DP] dptx_psr_pre_test finish %u", i);
		i++;
	}
}

void dptx_psr2_entry_test(struct dp_ctrl *dptx)
{
	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] index or type is invaild, index %d", g_dp_id);
		return;
	}

	if (g_multi_dp_debug_switch[g_dp_id] == NULL) {
		dpu_pr_err("[DP] debug dptx is null!");
		return;
	}

	g_multi_dp_debug_switch[g_dp_id]->psr_params.psr2_enable = true;
	g_psr2_entry_flag = 1;
	g_dptx_psr2_burst_update_times = 0;
}

void dptx_psr2_full_frame_update(void)
{
	g_update_region_flag = 0;
}

void dptx_psr2_half_frame_update(void)
{
	g_update_region_flag = 1;
}

void dptx_psr2_su_update(void)
{
	g_update_region_flag = 2;
}

uint16_t g_top_x = 0;
uint16_t g_top_y = 0;
uint16_t g_bottom_x = 0;
uint16_t g_bottom_y = 0;

void dptx_psr2_index_config(uint16_t top_x, uint16_t top_y, uint16_t bottom_x, uint16_t bottom_y)
{
	g_top_x = top_x;
	g_top_y = top_y;
	g_bottom_x = bottom_x;
	g_bottom_y = bottom_y;
	dpu_pr_err("[DP] dptx_psr2_index_config g_dp_id:%d g_top_x:%d g_top_y:%d g_bottom_x:%d g_bottom_y:%d",
		g_dp_id, g_top_x, g_top_y, g_bottom_x, g_bottom_y);
}

static void dptx_psr2_config_su_region(struct dp_ctrl *dptx)
{
	uint32_t reg = 0;

	if (!dptx || !dptx->dptx_enable || dptx->power_saving_mode) {
		dpu_pr_err("[DP] port id %d not exist or has already been off!", g_dp_id);
		return;
	}

	if (g_bottom_y) {
		reg = dptx_readl(g_multi_dp_debug_switch[g_dp_id], DPTX_SU_COO_TL);
		reg &= ~DPTX_CFG_SU_COO_BR_X_MASK;
		reg &= ~DPTX_CFG_SU_COO_BR_Y_MASK;
		reg |= g_top_x;
		reg |= (g_top_y << 16);
		dptx_writel(g_multi_dp_debug_switch[g_dp_id], DPTX_SU_COO_TL, reg);
		dpu_pr_err("[DP] set start region: 0x%x, g_top_x:%d, g_top_y:%d", reg, g_top_x, g_top_y);

		reg = dptx_readl(g_multi_dp_debug_switch[g_dp_id], DPTX_SU_COO_BR);
		reg &= ~DPTX_CFG_SU_COO_BR_X_MASK;
		reg &= ~DPTX_CFG_SU_COO_BR_Y_MASK;
		reg |= g_bottom_x;
		reg |= (g_bottom_y << 16);
		dptx_writel(g_multi_dp_debug_switch[g_dp_id], DPTX_SU_COO_BR, reg);
		dpu_pr_err("[DP] set end region: 0x%x, g_bottom_x:%d, g_bottom_y:%d", reg, g_bottom_x, g_bottom_y);
	} else {
		reg = dptx_readl(g_multi_dp_debug_switch[g_dp_id], DPTX_SU_COO_TL);
		reg &= ~DPTX_CFG_SU_COO_BR_X_MASK;
		reg &= ~DPTX_CFG_SU_COO_BR_Y_MASK;
		reg |= 0;
		reg |= (0 << 16);
		dptx_writel(g_multi_dp_debug_switch[g_dp_id], DPTX_SU_COO_TL, reg);
		dpu_pr_err("[DP] set start region: 0x%x, 0-0", reg);

		reg = dptx_readl(g_multi_dp_debug_switch[g_dp_id], DPTX_SU_COO_BR);
		reg &= ~DPTX_CFG_SU_COO_BR_X_MASK;
		reg &= ~DPTX_CFG_SU_COO_BR_Y_MASK;
		if (g_update_region_flag == 2) {
			reg |= (1919 << 0);
			reg |= (31 << 16);
			dpu_pr_err("[DP] set 2 region: 0x%x, 1919, 31", reg);
		} else if (g_update_region_flag == 1) {
			reg |= (1919 << 0);
			reg |= (599 << 16);
			dpu_pr_err("[DP] set 1 region: 0x%x, 1919, 599", reg);
		} else {
			reg |= (1919 << 0);
			reg |= (1199 << 16);
			dpu_pr_err("[DP] set 0 region: 0x%x, 1919, 1199", reg);
		}
		dptx_writel(g_multi_dp_debug_switch[g_dp_id], DPTX_SU_COO_BR, reg);
	}
}

void dptx_psr2_update_test(void)
{
	uint32_t reg;

	struct dp_ctrl *dptx = dpu_get_dptx_by_portid(g_dp_id);
	if (dptx == NULL) {
		dpu_pr_err("[DP] debug dptx is null!");
		return;
	}
	// TODO add dptx_psr2_config_su_region

	reg = dptx_readl(dptx, DPTX_PSR_CTRL);
	reg |= DPTX_CFG_SU_UPDATE_ENABLE;
	dptx_writel(dptx, DPTX_PSR_CTRL, reg);
}

void dptx_psr2_exit_test(void)
{
	uint32_t reg;
	struct dp_ctrl *dptx = NULL;

	dptx = dpu_get_dptx_by_portid(g_dp_id);
	if (dptx == NULL) {
		dpu_pr_err("[DP] debug dptx is null!");
		return;
	}

	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] index or type is invaild, index %d", g_dp_id);
		return;
	}

	if (dptx->psr_params.psr2_enable == false) {
		dpu_pr_err("[DP] psr2 has been disable!");
		return;
	}

	if (!dptx || !dptx->dptx_enable || dptx->power_saving_mode) {
		dpu_pr_err("[DP] port id %d not exist or has already been off!", g_dp_id);
		return;
	}

	dptx->psr_params.psr2_enable = false;
	reg = dptx_readl(dptx, DPTX_PSR_CTRL);
	reg |= DPTX_CFG_PSR_EXIT;
	dptx_writel(dptx, DPTX_PSR_CTRL, reg);
}

void dptx_psr2_burst_update_test(void)
{
	uint32_t reg;
	struct dp_ctrl *dptx = NULL;
	g_update_region_flag = 2;

	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] index or type is invaild, index %d", g_dp_id);
		return;
	}

	dptx = dpu_get_dptx_by_portid(g_dp_id);
	if (!dptx || !dptx->dptx_enable || dptx->power_saving_mode) {
		dpu_pr_err("[DP] port id %d not exist or has already been off!", g_dp_id);
		return;
	}

	dptx_psr2_config_su_region(dptx);
	g_dptx_psr2_burst_update_flag = 1;

	reg = dptx_readl(dptx, DPTX_PSR_CTRL);
	reg |= DPTX_CFG_SU_UPDATE_ENABLE;
	dptx_writel(dptx, DPTX_PSR_CTRL, reg);
}

void dptx_psr2_update_after_entry_test(void)
{
	struct dp_ctrl *dptx = NULL;

	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] index or type is invaild, index %d", g_dp_id);
		return;
	}

	dptx = dpu_get_dptx_by_portid(g_dp_id);
	if (dptx == NULL) {
		dpu_pr_err("[DP] debug dptx is null!");
		return;
	}

	dptx->psr_params.psr2_enable = true;
	g_dptx_psr2_update_after_entry_flag = 1;
	g_psr2_entry_flag = 1;
}

void dptx_psr2_exit_after_update_test(void)
{
	struct dp_ctrl *dptx = NULL;

	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] index or type is invaild, index %d", g_dp_id);
		return;
	}

	dptx = dpu_get_dptx_by_portid(g_dp_id);
	if (dptx == NULL) {
		dpu_pr_err("[DP] debug dptx is null!");
		return;
	}

	if (!dptx || !dptx->dptx_enable || dptx->power_saving_mode) {
		dpu_pr_err("[DP] port id %d not exist or has already been off!", g_dp_id);
		return;
	}

	g_dptx_psr2_exit_after_update_flag = 1;
	dptx_psr2_update_test();
}

void dptx_debug_enable_timegen(void)
{
	uint32_t reg;
	struct dp_ctrl *dptx = NULL;

	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] index or type is invaild, index %d", g_dp_id);
		return;
	}

	dptx = dpu_get_dptx_by_portid(g_dp_id);
	if (dptx == NULL) {
		dpu_pr_err("[DP] debug dptx is null!");
		return;
	}

	if (!dptx || !dptx->dptx_enable || dptx->power_saving_mode) {
		dpu_pr_err("[DP] port id %d not exist or has already been off!", g_dp_id);
		return;
	}

	reg = dptx_readl(dptx, DPTX_GCTL0);
	reg |= DPTX_CFG_TIMING_GEN_ENABLE;
	dptx_writel(dptx, DPTX_GCTL0, reg);
}

// ---------------- psr end -------------------------------------------

int dptx_infoframe_sdp_manul_send_debug(void)
{
	uint32_t reg;
	struct dp_ctrl *dptx = NULL;

	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] port id %d is invaild, please reset!", g_dp_id);
		return 0xff;
	}

	dptx = g_multi_dp_debug_switch[g_dp_id];
	if (!dptx || !dptx->dptx_enable || dptx->power_saving_mode) {
		dpu_pr_err("[DP] port id %d not exist or has already been off!", g_dp_id);
		return 0xff;
	}

	reg = readl(g_multi_dp_debug_switch[g_dp_id]->hidptx_base + 0x12c);
	reg |= GENMASK(20, 13);
	writel(reg, g_multi_dp_debug_switch[g_dp_id]->hidptx_base + 0x12c);
	dpu_pr_info("[DP] dptx_infoframe_sdp_manul_send_debug set ok: %llx", reg);
	return 0;
}

uint32_t dptx_infoframe_sdp_config_debug(int mode)
{
	uint32_t reg;
	struct dp_ctrl *dptx = NULL;

	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] port id %d is invaild, please reset!", g_dp_id);
		return 0xff;
	}

	dptx = g_multi_dp_debug_switch[g_dp_id];
	if (!dptx || !dptx->dptx_enable || dptx->power_saving_mode) {
		dpu_pr_err("[DP] port id %d not exist or has already been off!", g_dp_id);
		return 0xff;
	}

	reg = (uint32_t)readl(g_multi_dp_debug_switch[g_dp_id]->hidptx_base + 0x12c);
	if (mode == 1) // manual
		reg |= GENMASK(9, 2);
	else
		reg &= ~GENMASK(9, 2);
	writel(reg, g_multi_dp_debug_switch[g_dp_id]->hidptx_base + 0x12c);
	dpu_pr_info("[DP] dptx_infoframe_sdp_config_debug set ok: %llx", reg);
	return reg;
}

static void dptx_hdr_calculate_infoframe_data(struct dp_ctrl *dptx)
{
	dpu_check_and_no_retval(!dptx, err, "[DP] dptx is NULL!\n");

	dptx->hdr_infoframe.data[HDR_INFOFRAME_EOTF_BYTE_NUM] =
		(uint8_t)dptx->hdr_metadata.electro_optical_transfer_function;
	dptx->hdr_infoframe.data[HDR_INFOFRAME_METADATA_ID_BYTE_NUM] =
		(uint8_t)dptx->hdr_metadata.static_metadata_descriptor_id;
	dptx->hdr_infoframe.data[HDR_INFOFRAME_DISP_PRI_X_0_LSB] = dptx->hdr_metadata.red_primary_x & LSB_MASK;
	dptx->hdr_infoframe.data[HDR_INFOFRAME_DISP_PRI_X_0_MSB] =
		(uint8_t)((dptx->hdr_metadata.red_primary_x & MSB_MASK) >> SHIFT_8BIT);
	dptx->hdr_infoframe.data[HDR_INFOFRAME_DISP_PRI_Y_0_LSB] = dptx->hdr_metadata.red_primary_y & LSB_MASK;
	dptx->hdr_infoframe.data[HDR_INFOFRAME_DISP_PRI_Y_0_MSB] =
		(uint8_t)((dptx->hdr_metadata.red_primary_y & MSB_MASK) >> SHIFT_8BIT);
	dptx->hdr_infoframe.data[HDR_INFOFRAME_DISP_PRI_X_1_LSB] = dptx->hdr_metadata.green_primary_x & LSB_MASK;
	dptx->hdr_infoframe.data[HDR_INFOFRAME_DISP_PRI_X_1_MSB] =
		(uint8_t)((dptx->hdr_metadata.green_primary_x & MSB_MASK) >> SHIFT_8BIT);
	dptx->hdr_infoframe.data[HDR_INFOFRAME_DISP_PRI_Y_1_LSB] = dptx->hdr_metadata.green_primary_y & LSB_MASK;
	dptx->hdr_infoframe.data[HDR_INFOFRAME_DISP_PRI_Y_1_MSB] =
		(uint8_t)((dptx->hdr_metadata.green_primary_y & MSB_MASK) >> SHIFT_8BIT);
	dptx->hdr_infoframe.data[HDR_INFOFRAME_DISP_PRI_X_2_LSB] = dptx->hdr_metadata.blue_primary_x & LSB_MASK;
	dptx->hdr_infoframe.data[HDR_INFOFRAME_DISP_PRI_X_2_MSB] =
		(uint8_t)((dptx->hdr_metadata.blue_primary_x & MSB_MASK) >> SHIFT_8BIT);
	dptx->hdr_infoframe.data[HDR_INFOFRAME_DISP_PRI_Y_2_LSB] = dptx->hdr_metadata.blue_primary_y & LSB_MASK;
	dptx->hdr_infoframe.data[HDR_INFOFRAME_DISP_PRI_Y_2_MSB] =
		(uint8_t)((dptx->hdr_metadata.blue_primary_y & MSB_MASK) >> SHIFT_8BIT);
	dptx->hdr_infoframe.data[HDR_INFOFRAME_WHITE_POINT_X_LSB] = dptx->hdr_metadata.white_point_x & LSB_MASK;
	dptx->hdr_infoframe.data[HDR_INFOFRAME_WHITE_POINT_X_MSB] =
		(uint8_t)((dptx->hdr_metadata.white_point_x & MSB_MASK) >> SHIFT_8BIT);
	dptx->hdr_infoframe.data[HDR_INFOFRAME_WHITE_POINT_Y_LSB] = dptx->hdr_metadata.white_point_y & LSB_MASK;
	dptx->hdr_infoframe.data[HDR_INFOFRAME_WHITE_POINT_Y_MSB] =
		(uint8_t)((dptx->hdr_metadata.white_point_y & MSB_MASK) >> SHIFT_8BIT);
	dptx->hdr_infoframe.data[HDR_INFOFRAME_MAX_LUMI_LSB] =
		dptx->hdr_metadata.max_display_mastering_luminance & LSB_MASK;
	dptx->hdr_infoframe.data[HDR_INFOFRAME_MAX_LUMI_MSB] =
		(uint8_t)((dptx->hdr_metadata.max_display_mastering_luminance & MSB_MASK) >> SHIFT_8BIT);
	dptx->hdr_infoframe.data[HDR_INFOFRAME_MIN_LUMI_LSB] =
		dptx->hdr_metadata.min_display_mastering_luminance & LSB_MASK;
	dptx->hdr_infoframe.data[HDR_INFOFRAME_MIN_LUMI_MSB] =
		(uint8_t)((dptx->hdr_metadata.min_display_mastering_luminance & MSB_MASK) >> SHIFT_8BIT);
	dptx->hdr_infoframe.data[HDR_INFOFRAME_MAX_LIGHT_LEVEL_LSB] =
		dptx->hdr_metadata.max_content_light_level & LSB_MASK;
	dptx->hdr_infoframe.data[HDR_INFOFRAME_MAX_LIGHT_LEVEL_MSB] =
		(uint8_t)((dptx->hdr_metadata.max_content_light_level & MSB_MASK) >> SHIFT_8BIT);
	dptx->hdr_infoframe.data[HDR_INFOFRAME_MAX_AVERAGE_LEVEL_LSB] =
		dptx->hdr_metadata.max_frame_average_light_level & LSB_MASK;
	dptx->hdr_infoframe.data[HDR_INFOFRAME_MAX_AVERAGE_LEVEL_MSB] =
		(uint8_t)((dptx->hdr_metadata.max_frame_average_light_level & MSB_MASK) >> SHIFT_8BIT);
}

int dptx_hdr_infoframe_sdp_send_debug(int data)
{
	int i;

	if (g_dp_id < DPTX_PORT_ID_0 || g_dp_id >= DPTX_PORT_ID_MAX) {
		dpu_pr_err("[DP] port id %d is invaild, please reset!", g_dp_id);
		return 0xff;
	}

	g_multi_dp_debug_switch[g_dp_id]->hdr_infoframe.type_code = INFOFRAME_PACKET_TYPE_HDR;
	g_multi_dp_debug_switch[g_dp_id]->hdr_infoframe.version_number = HDR_INFOFRAME_VERSION;
	g_multi_dp_debug_switch[g_dp_id]->hdr_infoframe.length = HDR_INFOFRAME_LENGTH;

	memset_s(g_multi_dp_debug_switch[g_dp_id]->hdr_infoframe.data, HDR_INFOFRAME_LENGTH, 0, HDR_INFOFRAME_LENGTH);
	g_multi_dp_debug_switch[g_dp_id]->hdr_metadata.static_metadata_descriptor_id = (uint32_t)data;
	dptx_hdr_calculate_infoframe_data(g_multi_dp_debug_switch[g_dp_id]);

	for (i = 0; i < HDR_INFOFRAME_LENGTH; i++)
		dpu_pr_info("[DP] hdrinfoframe data[%d]: 0x%02x", i, g_multi_dp_debug_switch[g_dp_id]->hdr_infoframe.data[i]);

	mutex_lock(&g_multi_dp_debug_switch[g_dp_id]->dptx_mutex);

	if (g_multi_dp_debug_switch[g_dp_id]->dptx_hdr_infoframe_set_reg)
		g_multi_dp_debug_switch[g_dp_id]->dptx_hdr_infoframe_set_reg(g_multi_dp_debug_switch[g_dp_id], 1);

	mutex_unlock(&g_multi_dp_debug_switch[g_dp_id]->dptx_mutex);

	return 0;
}

#ifdef CONFIG_DKMD_DEBUG_ENABLE
EXPORT_SYMBOL_GPL(dp_debug_set_double_tx_sync_para);
EXPORT_SYMBOL_GPL(dp_debug_set_lane_num);
EXPORT_SYMBOL_GPL(dp_debug_get_lane_num);
EXPORT_SYMBOL_GPL(dp_debug_set_pll_value);
EXPORT_SYMBOL_GPL(dp_debug_get_pll_value);
EXPORT_SYMBOL_GPL(dp_debug_set_lane_rate);
EXPORT_SYMBOL_GPL(dp_debug_get_lane_rate);
EXPORT_SYMBOL_GPL(dp_debug_set_mst_mode);
EXPORT_SYMBOL_GPL(dp_debug_get_mst_mode);
EXPORT_SYMBOL_GPL(dp_debug_set_ssc_mode);
EXPORT_SYMBOL_GPL(dp_debug_get_ssc_mode);
EXPORT_SYMBOL_GPL(dp_debug_set_fec_mode);
EXPORT_SYMBOL_GPL(dp_debug_get_fec_mode);
EXPORT_SYMBOL_GPL(dp_debug_set_dsc_mode);
EXPORT_SYMBOL_GPL(dp_debug_get_dsc_mode);
EXPORT_SYMBOL_GPL(dp_debug_set_dp_mode);
EXPORT_SYMBOL_GPL(dp_debug_get_dp_mode);
EXPORT_SYMBOL_GPL(dp_debug_combophy_set_rate);
EXPORT_SYMBOL_GPL(dp_debug_set_efm_mode);
EXPORT_SYMBOL_GPL(dp_debug_get_efm_mode);
EXPORT_SYMBOL_GPL(dp_debug_set_aux_ctrl);
EXPORT_SYMBOL_GPL(dp_debug_get_aux_ctrl);
EXPORT_SYMBOL_GPL(dp_debug_set_preemphasis_swing);
EXPORT_SYMBOL_GPL(dp_debug_dptx_connected);
EXPORT_SYMBOL_GPL(dp_debug_read_dpcd);
EXPORT_SYMBOL_GPL(dp_debug_write_dpcd);
EXPORT_SYMBOL_GPL(set_dp_rx_tx_mode);
EXPORT_SYMBOL_GPL(set_dp_rx_tx_arsr_mode);
EXPORT_SYMBOL_GPL(set_dp_mode);
EXPORT_SYMBOL_GPL(set_clk_hblank_code);
EXPORT_SYMBOL_GPL(set_dp_psr_mode);
EXPORT_SYMBOL_GPL(select_dp_port);
EXPORT_SYMBOL_GPL(dptx_infoframe_sdp_manul_send_debug);
EXPORT_SYMBOL_GPL(dptx_infoframe_sdp_config_debug);
EXPORT_SYMBOL_GPL(dptx_hdr_infoframe_sdp_send_debug);

/* psr test start */
EXPORT_SYMBOL_GPL(dptx_psr_hdcp_status_test);
EXPORT_SYMBOL_GPL(dptx_psr_entry_test);
EXPORT_SYMBOL_GPL(dptx_psr_update_test);
EXPORT_SYMBOL_GPL(dptx_psr_exit_test);
EXPORT_SYMBOL_GPL(dptx_psr_update_after_entry_test);
EXPORT_SYMBOL_GPL(dptx_psr_exit_after_update_test);
EXPORT_SYMBOL_GPL(dptx_psr_pre_test);
EXPORT_SYMBOL_GPL(dptx_psr2_entry_test);
EXPORT_SYMBOL_GPL(dptx_psr2_full_frame_update);
EXPORT_SYMBOL_GPL(dptx_psr2_half_frame_update);
EXPORT_SYMBOL_GPL(dptx_psr2_su_update);
EXPORT_SYMBOL_GPL(dptx_psr2_index_config);
EXPORT_SYMBOL_GPL(dptx_psr2_update_test);
EXPORT_SYMBOL_GPL(dptx_psr2_exit_test);
EXPORT_SYMBOL_GPL(dptx_psr2_burst_update_test);
EXPORT_SYMBOL_GPL(dptx_psr2_update_after_entry_test);
EXPORT_SYMBOL_GPL(dptx_psr2_exit_after_update_test);
EXPORT_SYMBOL_GPL(dptx_debug_enable_timegen);
/* psr test end */
#endif
