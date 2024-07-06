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

#include "dp_ctrl_config.h"
#include <platform_include/see/ffa/ffa_msg_id.h>
#include <platform_include/display/linux/dpu_drmdriver.h>
#include "hidptx/hidptx_reg.h"

static int dptx_ctrl_clk_enable(struct dp_ctrl *dptx)
{
	dpu_check_and_return(!dptx, -EINVAL, err, "[DP] dptx is NULL!");

	/* enable clock */
	if (clk_prepare_enable(dptx->connector->connector_clk[CLK_DPCTRL_16M]) != 0) {
		dpu_pr_err("[DP] enable dpctrl 16m clk failed!\n");
		return -1;
	}

	if (clk_prepare_enable(dptx->connector->connector_clk[CLK_DPCTRL_PCLK]) != 0) {
		dpu_pr_err("[DP] enable dpctrl pclk failed!\n");
		return -1;
	}

	if (clk_prepare_enable(dptx->clk_dpctrl_pixel) != 0) {
		dpu_pr_err("[DP] enable dpctrl pixel clk failed!\n");
		return -1;
	}

	return 0;
}

int dptx_pixel_pll_preinit(void)
{
	return 0;
}

int dptx_pixel_pll_init(struct dp_ctrl *dptx, uint64_t pixel_clock)
{
	void_unused(dptx);
	void_unused(pixel_clock);
	return 0;
}

int dptx_pixel_pll_deinit(struct dp_ctrl *dptx)
{
	void_unused(dptx);
	return 0;
}

void enable_dptx_timing_gen(struct dp_ctrl *dptx)
{
	uint32_t val;

	if (unlikely(!dptx)) {
		dpu_pr_warn("dptx is null");
		return;
	}

	dptx_writel(dptx, dptx_dp_color_bar_stream(0), 0);

	if (dptx->dptx_triger_media_transfer)
		dptx->dptx_triger_media_transfer(dptx, true);

	val = dptx_readl(dptx, DPTX_GCTL0);
	val |= DPTX_CFG_TIMING_GEN_ENABLE;
	dptx_writel(dptx, DPTX_GCTL0, val);
	dpu_pr_info("dptx timing gen enabled!");
}

int32_t init_dp_sctrl(struct dp_private *priv, struct device_node *np)
{
	priv->dp_sctrl_base = of_iomap(np, REG_DP_SCTRL_BASE);
	if (!priv->dp_sctrl_base) {
		dpu_pr_err("[DP] failed to get dp_sctrl_base!\n");
		return -ENXIO;
	}
	return 0;
}

int32_t init_dpctrl_pixel_clk(struct dp_ctrl *dptx0, struct dp_ctrl *dptx1, struct device_node *np)
{
	if (dptx0 != NULL) {
		dptx0->clk_dpctrl_pixel = of_clk_get(np, DPTX0_PIXEL_CLOCK);
		if (IS_ERR_OR_NULL(dptx0->clk_dpctrl_pixel)) {
			dpu_pr_err("[DP] failed to get dptx0 clk_dpctrl_pixel!\n");
			return -ENXIO;
		}
	}
	/* for dual edp-tx */
	if (dptx1 != NULL) {
		dptx1->clk_dpctrl_pixel = of_clk_get(np, DPTX1_PIXEL_CLOCK);
		if (IS_ERR_OR_NULL(dptx1->clk_dpctrl_pixel)) {
			dpu_pr_err("[DP] failed to get dptx1 clk_dpctrl_pixel!\n");
			return -ENXIO;
		}
	}

	return 0;
}

int32_t init_dpctrl_16m_clk(struct dp_ctrl *dptx, struct device_node *np)
{
	void_unused(dptx);
	void_unused(np);
	return 0;
}

int32_t init_hsdt1_sysctrl_base(struct dp_private *priv, struct device_node *np)
{
	void_unused(priv);
	void_unused(np);
	return 0;
}

int32_t init_sub_harden_crg_base(struct dp_private *priv, struct device_node *np)
{
	void_unused(priv);
	void_unused(np);
	return 0;
}

static void dptx_hdcp_enable_video_transform(struct dp_ctrl *dptx, bool enable)
{
	configure_dss_service_security(FID_BL31_DISPLAY_FN_SUB_ID_HDCP_CTRL, DSS_HDCP_DP_ENABLE, enable, 0);
	return;
}

void dp_ctrl_config_init(struct dp_ctrl *dptx)
{
	dptx->is_all_pll_config_by_dp_soft = false;
	dptx->dptx_ctrl_clk_enable = dptx_ctrl_clk_enable;
	dptx->dptx_hdcp_enable_video_transform = dptx_hdcp_enable_video_transform;

	return;
}

bool dp_ctrl_is_bypass_by_pg(uint32_t dp_id)
{
	void_unused(dp_id);
	return false;
}