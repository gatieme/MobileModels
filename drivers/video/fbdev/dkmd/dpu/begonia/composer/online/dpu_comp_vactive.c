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

#include <linux/delay.h>

#include "dkmd_listener.h"
#include "dpu_comp_mgr.h"
#include "dpu_comp_vactive.h"
#include "panel_mgr.h"
#include "dpu_conn_mgr.h"
#include "mipi_dsi_dev.h"
#include "dpu_comp_config_utils.h"
#include "mipi_dsi_bit_clk_upt_helper.h"
#include "dpu_comp_abnormal_handle.h"
#include "dksm_dmd.h"

static int32_t dpu_comp_vactive_isr_notify(struct notifier_block *self, unsigned long action, void *data)
{
	struct dkmd_listener_data *listener_data = NULL;
	struct dpu_composer *dpu_comp = NULL;
	struct comp_online_present *present = NULL;
	if (!data) {
		dpu_pr_err("data is null pointer\n");
		return -1;
	}

	listener_data = (struct dkmd_listener_data *)data;
	dpu_comp = (struct dpu_composer *)(listener_data->data);
	present = (struct comp_online_present *)dpu_comp->present_data;

	++present->vactive_start_flag;

#ifdef CONFIG_DKMD_DEBUG_ENABLE
	present->buffers--;
	trace_buffer_num(present->buffers);
#endif

	if (is_mipi_cmd_panel(&dpu_comp->conn_info->base)) {
		/* disable mipi ldi */
		dpu_comp->conn_info->disable_ldi(dpu_comp->conn_info);
		dpu_pr_debug("vactive start disable ldi!");
		dpu_pr_debug("panel id is %d, compose index = %d",
			dpu_comp->conn_info->base.id, dpu_comp->comp.index);
		if (dpu_comp->conn_info->check_ldi_status) {
			present->vactive_ldi_status = dpu_comp->conn_info->check_ldi_status(dpu_comp->conn_info);
			if (present->vactive_ldi_status != 0) {
				dpu_comp->comp.comp_err_status |= ABNORMAL_CHECK_LDI_FAILED;
				kthread_queue_work(&dpu_comp->handle_worker, &present->abnormal_handle_work);
			}
		}
	}

	dpu_check_dbuf_state(dpu_comp->comp_mgr->dpu_base, dpu_comp->conn_info->base.pipe_sw_itfch_idx);

	wake_up_interruptible_all(&present->vactive_start_wq);
	return 0;
}

static struct notifier_block vactive_isr_notifier = {
	.notifier_call = dpu_comp_vactive_isr_notify,
};

void dpu_comp_vactive_init(struct dkmd_isr *isr, struct dpu_composer *dpu_comp, uint32_t listening_bit)
{
	struct comp_online_present *present = NULL;
	if (!isr) {
		dpu_pr_err("isr is null pointer\n");
		return;
	}
	if (!dpu_comp) {
		dpu_pr_err("dpu_comp is null pointer\n");
		return;
	}

	present = (struct comp_online_present *)dpu_comp->present_data;

	init_waitqueue_head(&present->vactive_start_wq);
	present->vactive_start_flag = 1;

	dkmd_isr_register_listener(isr, &vactive_isr_notifier, listening_bit, dpu_comp);
}

void dpu_comp_vactive_deinit(struct dkmd_isr *isr, uint32_t listening_bit)
{
	if (!isr) {
		dpu_pr_err("pointer isr is nullptr!\n");
		return;
	}
	dkmd_isr_unregister_listener(isr, &vactive_isr_notifier, listening_bit);
}

static void dpu_comp_dsm_client_notify_timeout(struct dpu_composer *dpu_comp)
{
	uint32_t cnt = 0;
	struct dpu_connector *connector = NULL;

	dpu_check_and_no_retval(!dsm_lcd_client, info, "dsm_lcd_client is null!");

	while((dsm_client_ocuppy(dsm_lcd_client) != 0) && (cnt < DSM_OCCUPY_RETRY_TIMES)) {
		dpu_pr_warn("dsm_client_ocuppy failed, retry %d times", ++cnt);
		usleep_range(500, 600);
	}

	if (cnt == DSM_OCCUPY_RETRY_TIMES) {
		dpu_pr_warn("dsm_client_ocuppy failed");
		return;
	}

	connector = get_primary_connector(dpu_comp->conn_info);
	dsm_client_record(dsm_lcd_client, "pipe_sw_itfch_idx=%d online compose wait vactive_start timeout!"
		"dpp_dbg=0x%x, vcount=0x%x, vstate=0x%x",
		dpu_comp->conn_info->base.pipe_sw_itfch_idx,
		inp32(DPU_DPP_CH_DBG_CNT_ADDR(dpu_comp->comp_mgr->dpu_base + DPU_DPP0_OFFSET)),
		inp32(DPU_DSI_VCOUNT_ADDR(connector->connector_base)),
		inp32(DPU_DSI_VSTATE_ADDR(connector->connector_base)));

	dsm_client_notify(dsm_lcd_client, DSM_LCD_TE_TIME_OUT_ERROR_NO);
}

int32_t dpu_comp_vactive_wait_event(struct comp_online_present *present)
{
	int32_t ret = 0;
	int32_t timeout = ASIC_EVENT_TIMEOUT_MS;
	uint32_t prev_vactive_start_flag;
	uint64_t vactive_tv;
	uint32_t vstate;
	uint32_t phy_status;
	struct dpu_composer *dpu_comp = present->dpu_comp;
	struct dpu_connector *connector = NULL;
	int times = 0;

	connector = get_primary_connector(dpu_comp->conn_info);
	dpu_trace_ts_begin(&vactive_tv);
	if (dpu_comp->conn_info->base.fpga_flag)
		timeout = FPGA_EVENT_TIMEOUT_MS;

	present = (struct comp_online_present *)dpu_comp->present_data;
	while (true) {
		if (is_mipi_cmd_panel(&dpu_comp->conn_info->base)) {
			ret = wait_event_interruptible_timeout(present->vactive_start_wq,
				present->vactive_start_flag,
				msecs_to_jiffies(timeout));
		} else {
			prev_vactive_start_flag = present->vactive_start_flag;
			ret = (int32_t)wait_event_interruptible_timeout(present->vactive_start_wq,
				(prev_vactive_start_flag != present->vactive_start_flag) ||
				(present->vactive_start_flag == 1),
				msecs_to_jiffies(timeout));
		}

		if ((ret == -ERESTARTSYS) && (times++ < 50))
			mdelay(10);
		else
			break;
	}

	if (ret > 0) {
		if (is_mipi_cmd_panel(&dpu_comp->conn_info->base))
			present->vactive_start_flag = 0;
		dpu_trace_ts_end(&vactive_tv, "online compose wait vactive");
		return 0;
	}

	dpu_pr_warn("pipe_sw_itfch_idx=%d online compose wait vactive_start timeout!"
		"dpp_dbg=0x%x, vcount=0x%x, vstate=0x%x",
		dpu_comp->conn_info->base.pipe_sw_itfch_idx,
		inp32(DPU_DPP_CH_DBG_CNT_ADDR(dpu_comp->comp_mgr->dpu_base + DPU_DPP0_OFFSET)),
		inp32(DPU_DSI_VCOUNT_ADDR(connector->connector_base)),
		inp32(DPU_DSI_VSTATE_ADDR(connector->connector_base)));

	vstate = inp32(DPU_DSI_VSTATE_ADDR(connector->connector_base));
	phy_status = inp32(DPU_DSI_CDPHY_STATUS_ADDR(connector->connector_base));

	dpu_comp_abnormal_dump_axi(dpu_comp->comp_mgr->dpu_base);

	if (dpu_comp->comp_mgr->media1_ctrl_base)
		dpu_comp_abnormal_dump_qic(dpu_comp->comp_mgr->media1_ctrl_base);
	else
		dpu_pr_warn("no media1 ctrl base\n");

	if (g_debug_present_hold) {
		dpu_pr_warn("composer present hold start");
		mdelay(DPU_COMPOSER_HOLD_TIME);
		dpu_pr_warn("composer present hold end");
	}

	if (vstate == LDI_VSTATE_V_WAIT_TE0 || (!mipi_panel_check_reg(connector) && (phy_status & BIT(1)))) {
		if (dpu_comp->conn_info->esd_enable) {
			dpu_comp->esd_ctrl.esd_recover_state = ESD_RECOVER_STATE_START;
			if (dpu_comp->esd_ctrl.esd_check_wq)
				queue_work(dpu_comp->esd_ctrl.esd_check_wq, &(dpu_comp->esd_ctrl.esd_check_work));
		}
	}

	if (g_debug_dpu_clear_enable) {
		dpu_comp->comp.comp_err_status |= ABNORMAL_WAIT_VACTIVE_TIMEOUT;
		kthread_queue_work(&dpu_comp->handle_worker, &present->abnormal_handle_work);
	}

	dpu_trace_ts_end(&vactive_tv, "online compose wait vactive");
	return (ret > 0) ? 0 : -1;
}

static int32_t dpu_comp_vactive_end_isr_notify(struct notifier_block *self, unsigned long action, void *data)
{
	struct dkmd_listener_data *listener_data = (struct dkmd_listener_data *)data;
	struct dpu_composer *dpu_comp = (struct dpu_composer *)(listener_data->data);
	struct comp_online_present *present = (struct comp_online_present *)dpu_comp->present_data;
	struct dpu_comp_dfr_ctrl *dfr_ctrl = &present->dfr_ctrl;
	struct dpu_connector * connector = get_primary_connector(dpu_comp->conn_info);

	if (dfr_ctrl->update_frm_rate_isr_handler)
		dfr_ctrl->update_frm_rate_isr_handler(dfr_ctrl);

	mipi_dsi_bit_clk_upt_isr_handler(connector);
	return 0;
}

static struct notifier_block vactive_end_isr_notifier = {
	.notifier_call = dpu_comp_vactive_end_isr_notify,
};

void dpu_comp_vactive_end_init(struct dkmd_isr *isr, struct dpu_composer *dpu_comp, uint32_t listening_bit)
{
	dkmd_isr_register_listener(isr, &vactive_end_isr_notifier, listening_bit, dpu_comp);
}

void dpu_comp_vactive_end_deinit(struct dkmd_isr *isr, uint32_t listening_bit)
{
	dkmd_isr_unregister_listener(isr, &vactive_end_isr_notifier, listening_bit);
}
