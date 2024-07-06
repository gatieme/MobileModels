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

#include <linux/types.h>
#include <linux/interrupt.h>
#include <linux/mutex.h>
#include <linux/clk.h>

#include "dkmd_log.h"
#include "dkmd_object.h"
#include "hdmitx_drv.h"
#include "hdmitx_connector.h"
#include "hdmitx_core_config.h"
#include "dpu_connector.h"

#define HDMI_RST 0x64
#define AON_INTR_MASK 0x30
#define AON_INTR_STATE 0x34
#define AON_STATE 0x28

static irqreturn_t hdmi_hpd_irq(int32_t irq, void *ptr)
{
	uint32_t isr_status;
	struct hdmitx_ctrl *hdmitx = NULL;

	hdmitx = (struct hdmitx_ctrl *)ptr;
	dpu_check_and_return(!hdmitx, IRQ_NONE, err, "connector is null!");

	isr_status = inp32(hdmitx->aon_base + AON_INTR_STATE);
	if ((isr_status & BIT(0)) != 0x1) {
		dpu_pr_info("is not hpd");
		return IRQ_NONE;
	}
	set_reg(hdmitx->aon_base + AON_INTR_STATE, 0x1, 1, 0);
	return IRQ_WAKE_THREAD;
}

static irqreturn_t hdmi_hpd_thread_irq(int32_t irq, void *ptr)
{
	uint32_t isr_status;
	struct hdmitx_ctrl *hdmitx = NULL;

	dpu_pr_info("+");
	hdmitx = (struct hdmitx_ctrl *)ptr;

	dpu_check_and_return(!hdmitx, IRQ_NONE, err, "connector is null!");

	isr_status = inp32(hdmitx->aon_base + AON_STATE);
	mutex_lock(&hdmitx->hdmitx_mutex);
	if ((isr_status & BIT(0)) == BIT(0))
		hdmitx_hotplug();
	else
		hdmitx_hotunplug();
	mutex_unlock(&hdmitx->hdmitx_mutex);
	return 0;
}

static void hdmitx_hpd_setup(struct hdmitx_private *hdmitx_priv)
{
	int32_t ret;

	dpu_pr_info("hpd_irq_no=%#x,+", hdmitx_priv->hpd_irq_no);
	if (hdmitx_priv->hpd_irq_no < 0) {
		dpu_pr_warn("error irq_no: %u", hdmitx_priv->hpd_irq_no);
		return;
	}

	ret = request_threaded_irq(hdmitx_priv->hpd_irq_no, hdmi_hpd_irq, hdmi_hpd_thread_irq,
			0, "hdmitx_hpd", (void *)&hdmitx_priv->hdmitx);
	if (ret) {
		dpu_pr_err("Failed to request press interupt handler");
		return;
	}

	/* default enable irq */
	disable_irq(hdmitx_priv->hpd_irq_no);
	dpu_pr_info("-");
}

struct hdmitx_ctrl *g_hdmitx = NULL;

int hdmitx_aon_init(struct hdmitx_private *hdmitx_priv)
{
	struct hdmitx_ctrl *hdmitx = NULL;

	dpu_check_and_return(!hdmitx_priv, -1, err, "hdmitx_priv is null!");

	hdmitx = &hdmitx_priv->hdmitx;

	//  apb and hdmi reset
	set_reg(hdmitx_priv->hsdt1_sub_harden_base + HDMI_RST, 0x3, 2, 11);

	//  hsdt1 crg reset
	set_reg(hdmitx_priv->hsdt1_crg_base + 0x88, 0x1, 1, 28);

	// pclk enable
	set_reg(hdmitx_priv->hsdt1_sub_harden_base, 0x1, 1, 15);

	//  AON 24MHz clock, use clk_prepare_enable enable 24M clock
	clk_prepare_enable(hdmitx->connector->connector_clk[CLK_DPCTRL_PIXEL]);

	// enable
	set_reg(hdmitx->aon_base + AON_INTR_MASK, 0x1, 1, 0);
	mutex_init(&hdmitx->hdmitx_mutex);
	g_hdmitx = &hdmitx_priv->hdmitx;
	hdmitx_hpd_setup(hdmitx_priv);
	return 0;
}