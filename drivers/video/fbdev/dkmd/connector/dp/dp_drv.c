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

#include "dp_ctrl.h"
#include "dpu_conn_mgr.h"
#include "dp_drv.h"
#include <linux/types.h>
#include <linux/of.h>
#include "dp_ctrl_config.h"

struct platform_device *g_dkmd_dp_devive[MAX_DPTX_DEV_INDEX] = {};

int dptx_init_dpc_num(struct dp_ctrl *dptx)
{
	dpu_check_and_return(!dptx, -EINVAL, err, "[DP] dptx is null pointer!");

	switch (dptx->port_id) { // usb/dp combophy：port 0~3, dp/edp combophy：port 4~5
	case DPTX_INVALID_PORT_ID: /* history platform don't need to select dpc */
	case DPTX_PORT_ID_0:
	case DPTX_PORT_ID_1:
		dptx->dpc_index_selected = DPTX_DPC_NUM_0;
		break;
	case DPTX_PORT_ID_2:
	case DPTX_PORT_ID_4:
		dptx->dpc_index_selected = DPTX_DPC_NUM_1;
		break;
	case DPTX_PORT_ID_3:
	case DPTX_PORT_ID_5:
		dptx->dpc_index_selected = DPTX_DPC_NUM_2;
		break;
	default:
		dpu_pr_err("[DP] input error port id, not support!");
		return -1;
	}
	dpu_pr_info("[DP] dptx->dpc_index_selected is %d", dptx->dpc_index_selected);
	return 0;
}

int get_dp_devive_index(int port_id, uint32_t *dev_index)
{
	switch (port_id) { // usb/dp combophy：port 0~3, dp/edp combophy：port 4~5
	case DPTX_INVALID_PORT_ID: /* history platform use gfx_dp */
	case DPTX_PORT_ID_0:
	case DPTX_PORT_ID_1:
		*dev_index = GFX_DP;
		break;
	case DPTX_PORT_ID_2:
	case DPTX_PORT_ID_4:
		*dev_index = GFX_DP1;
		break;
	case DPTX_PORT_ID_3:
	case DPTX_PORT_ID_5:
		*dev_index = GFX_DP2;
		break;
	default:
		dpu_pr_err("[DP] input error port id, not support!");
		return -1;
	}
	dpu_pr_info("[DP] get_dp_devive_index: port id is %d, dev_index is %d", port_id, *dev_index);

	return 0;
}

static int32_t dp_panel_parse_dt(struct dp_private *priv, struct device_node *np)
{
	int ret;
	uint32_t connector_count = 0;
	uint32_t value = 0;
	const __be32 *p = NULL;
	struct property *prop = NULL;
	struct dp_ctrl *dptx0 = &priv->dp[0];
	struct dp_ctrl *dptx1 = &priv->dp[1];
	struct dkmd_connector_info *pinfo = &priv->connector_info;

	if (init_dpctrl_pixel_clk(dptx0, NULL, np))
		return -ENXIO;

	dptx0->hidptx_base = of_iomap(np, REG_HIDPTX_BASE);
	if (!dptx0->hidptx_base) {
		dpu_pr_err("[DP] failed to get hidptx_base!\n");
		return -ENXIO;
	}

	priv->hsdt1_crg_base = of_iomap(np, REG_HSDT1_CRG_BASE);
	if (!priv->hsdt1_crg_base) {
		dpu_pr_err("[DP] failed to get hsdt1_crg_base!\n");
		return -ENXIO;
	}

	dptx0->combo_phy_base = of_iomap(np, REG_COMBOPHY_BASE);
	if (!dptx0->combo_phy_base) {
		dpu_pr_err("[DP] failed to get combo_phy_base!\n");
		return -ENXIO;
	}

	/* v740 adjust difference add */
	if (init_dpctrl_16m_clk(dptx0, np))
		return -ENXIO;

	if (init_hsdt1_sysctrl_base(priv, np))
		return -ENXIO;

	if (init_sub_harden_crg_base(priv, np))
		return -ENXIO;

	if (init_dp_sctrl(priv, np))
		return -ENXIO;

	ret = of_property_read_u32(np, "fpga_flag", &pinfo->base.fpga_flag);
	if (ret) {
		dpu_pr_info("[DP] get fpga_flag failed!\n");
		pinfo->base.fpga_flag = 0;
	}
	dpu_pr_info("[DP] fpga_flag=%#x", pinfo->base.fpga_flag);

	ret = of_property_read_string(np, "gfx_dp_dev_name", &pinfo->base.name);
	if (ret) {
		dpu_pr_info("[DP] get gfx_dp_dev_name failed!\n");
		pinfo->base.name = DTS_GFX_DP_NAME;
	}
	dpu_pr_info("[DP] pinfo->base.name=%s\n", pinfo->base.name);

	ret = of_property_read_u32(np, "pipe_sw_itfch_idx", &pinfo->base.pipe_sw_itfch_idx);
	if (ret) {
		dpu_pr_info("[DP] get pipe_sw_itfch_idx failed!\n");
		pinfo->base.pipe_sw_itfch_idx = PIPE_SW_PRE_ITFCH1;
	}
	dpu_pr_info("[DP] pipe_sw_pre_itfch_idx=%#x", pinfo->base.pipe_sw_itfch_idx);

	ret = of_property_read_u32(np, "support_async_online", &pinfo->base.enable_async_online);
	if (ret) {
		dpu_pr_info("[DP] get enable_async_online failed!\n");
		pinfo->base.enable_async_online = 0;
	}
	dpu_pr_info("[DP] support_async_online=%#x", pinfo->base.enable_async_online);

	ret = of_property_read_u32(np, "fake_panel_flag", &pinfo->base.fake_panel_flag);
	if (ret)
		pinfo->base.fake_panel_flag = 0;
	dpu_pr_info("[DP] fake_panel_flag=%#x", pinfo->base.fake_panel_flag);

	ret = of_property_read_u32(np, "mode", &pinfo->base.mode);
	if (ret)
		pinfo->base.mode = 0;
	dpu_pr_info("[DP] dptx_mode=%#x", pinfo->base.mode);

	ret = of_property_read_u32(np, "channel_id", &pinfo->base.id);
	if (ret)
		pinfo->base.id = 0;
	dpu_pr_info("[DP] dptx_id=%#x", pinfo->base.id);

	of_property_for_each_u32(np, "connector_id", prop, p, value) {
		if (connector_count >= MAX_CONNECT_CHN_NUM)
			break;

		++connector_count;
	}

	dptx0->is_dual_tx = false;
	dptx1->is_dual_tx = false;
	if (connector_count > EXTERNAL_CONNECT_CHN_IDX) {
		if (init_dpctrl_pixel_clk(NULL, dptx1, np))
			return -ENXIO;

		dptx1->hidptx_base = of_iomap(np, REG_HIDPTX_EXTERNAL_BASE);
		if (!dptx1->hidptx_base) {
			dpu_pr_err("[DP] failed to get hidptx_base!\n");
			return -ENXIO;
		}

		dptx1->combo_phy_base = of_iomap(np, REG_COMBOPHY_EXTERNAL_BASE);
		if (!dptx1->combo_phy_base) {
			dpu_pr_err("[DP] failed to get combo_phy_base!\n");
			return -ENXIO;
		}

		dptx0->is_dual_tx = true;
		dptx1->is_dual_tx = true;
	}

	base_panel_connector_dts_parse(pinfo, np);

	return 0;
}

static const struct of_device_id dp_device_match_table[] = {
	{
		.compatible = DTS_COMP_DP,
		.data = NULL,
	},
	{
		.compatible = DTS_COMP_DP1,
		.data = NULL,
	},
	{
		.compatible = DTS_COMP_DP2,
		.data = NULL,
	},
	{},
};
MODULE_DEVICE_TABLE(of, dp_device_match_table);

static void dp_save_device(struct platform_device *pdev, struct dp_private *priv)
{
	int dev_index = 0;

	if (priv == NULL || pdev == NULL) {
		dpu_pr_err("[DP] pdev or priv is null ptr, error return!\n");
		return;
	}

	if (strcmp(priv->connector_info.base.name, DTS_GFX_DP_NAME) == 0) {
		dev_index = GFX_DP;
	} else if (strcmp(priv->connector_info.base.name, DTS_GFX_DP1_NAME) == 0) {
		dev_index = GFX_DP1;
	} else if (strcmp(priv->connector_info.base.name, DTS_GFX_DP2_NAME) == 0) {
		dev_index = GFX_DP2;
	} else {
		dpu_pr_err("[DP] gfx dp name is invalid!!!\n");
		return;
	}

	g_dkmd_dp_devive[dev_index] = pdev;

	return;
}

static int32_t dp_probe(struct platform_device *pdev)
{
	struct dp_private *priv = NULL;
	struct dp_ctrl *dptx = NULL;

	if (unlikely(!pdev)) {
		dpu_pr_warn("pdev is null");
		return -1;
	}

	if (!is_connector_manager_available())
		return -EPROBE_DEFER;

	priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
	if (!priv) {
		dpu_pr_err("[DP] alloc offline driver private data failed!\n");
		return -EINVAL;
	}

	priv->device = pdev;
	if (dp_panel_parse_dt(priv, pdev->dev.of_node)){
		dpu_pr_err("[DP] parse dts error!\n");
		return -EINVAL;
	}

	if (priv->connector_info.base.name == NULL) {
		dpu_pr_warn("[DP] get priv->connector_info.base.name from dtsi failed!");
		return -EINVAL;
	}

	/* this is the tail device */
	priv->connector_info.base.peri_device = pdev;
	priv->connector_info.base.type = PANEL_DP;
	priv->connector_info.base.dptx_connect_mutex = devm_kzalloc(&pdev->dev, sizeof(struct mutex), GFP_KERNEL);
	if (!priv->connector_info.base.dptx_connect_mutex) {
		dpu_pr_warn("[DP] alloc dptx_connect_mutex failed!\n");
		return -EINVAL;
	}
	mutex_init(priv->connector_info.base.dptx_connect_mutex);

	/* add private data to device */
	platform_set_drvdata(pdev, &priv->connector_info);

	/* will create chrdev: /dev/gfx_dpX  */
	if (register_connector(&priv->connector_info) != 0) {
		dpu_pr_warn("[DP] device register failed, need retry!\n");
		devm_kfree(&pdev->dev, priv);
		return -EPROBE_DEFER;
	}

	dptx = &priv->dp[MASTER_DPTX_IDX];
	// register dp hpd devive
	if (switch_dev_register(&dptx->sdev) < 0)
		dpu_pr_err("[DP] dp switch register [%s] failed!", dptx->sdev.name);
	// register hdmi_audio hpd devive
	if (switch_dev_register(&dptx->dp_switch) < 0)
		dpu_pr_err("[DP] dp switch register [%s] failed!", dptx->dp_switch.name);

	/* save dp_private to list */
	dp_save_device(pdev, priv);

	return 0;
}

/**
 * Clear resource when device removed but not for devicetree device
 */
static int32_t dp_remove(struct platform_device *pdev)
{
	struct dp_private *priv = platform_get_drvdata(pdev);
	struct dp_ctrl *dptx = NULL;

	if (!priv) {
		dpu_pr_err("[DP] get dsi private data failed!\n");
		return -EINVAL;
	}
	unregister_connector(&priv->connector_info);

	dptx = &priv->dp[MASTER_DPTX_IDX];
	// unregister dp hpd devive
	switch_dev_unregister(&dptx->sdev);
	// unregister hdmi_audio hpd devive
	switch_dev_unregister(&dptx->dp_switch);

	dpu_pr_info("[DP] %s remove complete!\n", priv->connector_info.base.name);

	return 0;
}

static struct platform_driver dp_platform_driver = {
	.probe  = dp_probe,
	.remove = dp_remove,
	.driver = {
		.name  = DEV_NAME_DP,
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(dp_device_match_table),
	}
};

static int32_t __init dp_register(void)
{
	return platform_driver_register(&dp_platform_driver);
}

static void __exit dp_unregister(void)
{
	platform_driver_unregister(&dp_platform_driver);
}

late_initcall(dp_register);
module_exit(dp_unregister);

MODULE_AUTHOR("Graphics Display");
MODULE_DESCRIPTION("DP Module Driver");
MODULE_LICENSE("GPL");
