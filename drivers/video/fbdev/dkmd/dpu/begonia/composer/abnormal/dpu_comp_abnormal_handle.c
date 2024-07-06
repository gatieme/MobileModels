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
#include <dpu/dpu_dm.h>
#include <dpu/soc_dpu_define.h>
#include <soc_media1_crg_interface.h>
#include <linux/interrupt.h>
#include "chash.h"
#include "dkmd_listener.h"
#include "dpu_comp_mgr.h"
#include "dpu_conn_mgr.h"
#include "dpu_comp_vactive.h"
#include "dpu_comp_abnormal_handle.h"
#include "dpu_comp_smmu.h"
#include "dpu_opr_config.h"
#include "dpu_dacc.h"
#include "dpu_config_utils.h"
#include "cmdlist_interface.h"
#include "dksm_debug.h"
#include "dpu_cmdlist.h"
#include "dpu_config_utils.h"
#include "mipi_dsi_dev.h"
#include "dkmd_rect.h"
#include "dkmd_base_layer.h"
#include "opr_mgr/operators/opr_format.h"
#include "dpu_debug_dump.h"
#include "dksm_dmd.h"

static int32_t dpu_comp_handle_underflow_clear(struct dpu_composer *dpu_comp)
{
	uint32_t ret = 0, clear_bit = 0;
	uint32_t displaying_scene_id, displayed_scene_id;
	struct dkmd_connector_info *pinfo = dpu_comp->conn_info;
	struct comp_online_present *present = (struct comp_online_present *)dpu_comp->present_data;

	/* 1. after disable ldi and set clear, wait 16ms */
	dpu_pr_warn("underflow clear start");
	clear_bit = BIT(pinfo->sw_post_chn_idx[PRIMARY_CONNECT_CHN_IDX]);
	if (pinfo->sw_post_chn_num > 1)
		clear_bit = clear_bit | BIT(pinfo->sw_post_chn_idx[EXTERNAL_CONNECT_CHN_IDX]);
	outp32(DPU_GLB_RS_CLEAR_ADDR(dpu_comp->comp_mgr->dpu_base + DPU_GLB0_OFFSET), clear_bit);

	mdelay(16);

	/* 2. enable dacc_crg clr_rsicv_start */
	displaying_scene_id = (uint32_t)present->frames[present->displaying_idx].in_frame.scene_id;
	displayed_scene_id = (uint32_t)present->frames[present->displayed_idx].in_frame.scene_id;
	ret |= dpu_dacc_handle_clear(dpu_comp->comp_mgr->dpu_base, displaying_scene_id);
	if (displaying_scene_id != displayed_scene_id)
		ret |= dpu_dacc_handle_clear(dpu_comp->comp_mgr->dpu_base, displayed_scene_id);

	outp32(DPU_GLB_RS_CLEAR_ADDR(dpu_comp->comp_mgr->dpu_base + DPU_GLB0_OFFSET), 0);

	composer_mgr_disable_dimming(dpu_comp->comp_mgr, dpu_comp->comp.index);

	/* 3. check it in vactive_end intr */
	if (ret == 0)
		ret = (uint32_t)pipeline_next_ops_handle(pinfo->conn_device, pinfo,
												 DO_CLEAR, (void *)dpu_comp->comp_mgr->dpu_base);

	if (!is_offline_panel(&dpu_comp->conn_info->base))
		present->vactive_start_flag = 1;

	return ret;
}

static void dpu_comp_abnormal_dump_dacc(char __iomem *dpu_base, uint32_t scene_id)
{
	char __iomem *module_base = dpu_base + DACC_OFFSET + DMC_OFFSET;

	dpu_pr_warn("DACC:\n\n"
		"CORE_STATUS_REG=%#x\t\tDACC_CORE_MON_PC_REG=%#x\t\tDBG_DEMURA_RLST_CNT=%#x\t\tDBG_SCL_RLST_CNT_01=%#x\n"
		"DBG_SCL_RLST_CNT_23=%#x\t\tDBG_UVUP_RLST_YCNT=%#x\t\tDBG_CST_ALL=%#x\t\tDBG_FSM_MISC=%#x\n"
		"DBG_BUSY_REQ_MISC=%#x\t\tDBG_RESERVED_0=%#x\t\tDBG_RESERVED_1=%#x\n\n",
		inp32(SOC_DACC_CORE_STATUS_REG_ADDR(module_base)), inp32(SOC_DACC_CORE_MON_PC_REG_ADDR(module_base)),
		inp32(SOC_DACC_DBG_DEMURA_RLST_CNT_ADDR(module_base, scene_id)),
		inp32(SOC_DACC_DBG_SCL_RLST_CNT_01_ADDR(module_base, scene_id)),
		inp32(SOC_DACC_DBG_SCL_RLST_CNT_23_ADDR(module_base, scene_id)),
		inp32(SOC_DACC_DBG_UVUP_RLST_YCNT_ADDR(module_base, scene_id)),
		inp32(SOC_DACC_DBG_CST_ALL_ADDR(module_base, scene_id)),
		inp32(SOC_DACC_DBG_FSM_MISC_ADDR(module_base, scene_id)),
		inp32(SOC_DACC_DBG_BUSY_REQ_MISC_ADDR(module_base, scene_id)),
		inp32(SOC_DACC_DBG_RESERVED_0_ADDR(module_base, scene_id)),
		inp32(SOC_DACC_DBG_RESERVED_1_ADDR(module_base, scene_id)));
}

#ifdef CONFIG_DKMD_DEBUG_ENABLE
void dpu_comp_abnormal_dump_cmdlist_dm(void)
{
	uint32_t scene_id = g_last_cmdlist_frm_info.scene_id;
	uint32_t cmdlist_id = g_last_cmdlist_frm_info.cmdlist_id;

	dpu_pr_warn("DM cmdlist dump begin(fram_index:%u):", g_last_cmdlist_frm_info.frame_index);
	dkmd_cmdlist_dump_dm(scene_id, cmdlist_id);
}
#endif

void dpu_comp_abnormal_dump_reg_dm(char __iomem *dpu_base, uint32_t scene_id)
{
	uint32_t i = 0;
	uint32_t inc_step = 4;
	uint32_t val1, val2, val3, val4;
	uint32_t *dm_addr = (uint32_t *)(dpu_base + g_dm_tlb_info[scene_id].dm_data_addr);
	uint32_t dpu_addr_offset = g_dm_tlb_info[scene_id].dm_data_addr;

	dpu_pr_err("DM reg dump begin(scene_id:%d):", scene_id);

	for (; i < ((DM_LAYER_HEIGHT_OFFSET + INPUT_LAYER_OFFSET * INPUT_LAYER_CNT) / (inc_step * 4)); i++) {
		val1 = inp32(dm_addr++);
		val2 = inp32(dm_addr++);
		val3 = inp32(dm_addr++);
		val4 = inp32(dm_addr++);
		dpu_pr_err("dpu_addr_offset:%#x val:0x%08x 0x%08x 0x%08x 0x%08x \n", dpu_addr_offset, val1, val2, val3, val4);
		dpu_addr_offset += inc_step * 4;
	}
}

void dpu_comp_abnormal_dsm_dump_reg_layer(uint32_t *dm_addr, uint32_t start_layer_index,
		uint32_t layer_cnt, uint32_t ldi_vstate)
{
	uint32_t i = 0;
	uint32_t cnt = 0;
	uint32_t *current_addr = NULL;
	uint32_t layer_index = 0;
	uint32_t inc_step = 4;
	uint32_t val1, val2, val3, val4;

	while((dsm_client_ocuppy(dsm_lcd_client) != 0) && (cnt < DSM_OCCUPY_RETRY_TIMES)) {
		dpu_pr_warn("dsm_client_ocuppy failed, retry %d times", ++cnt);
		usleep_range(500, 600);
	}

	if (cnt == DSM_OCCUPY_RETRY_TIMES) {
		dpu_pr_warn("dsm_client_ocuppy failed");
		return;
	}

	for (layer_index = start_layer_index; layer_index < layer_cnt; ++layer_index) {
		current_addr = dm_addr + (DM_LAYER_HEIGHT_OFFSET + layer_index * INPUT_LAYER_OFFSET) / 4;
		for (i = (DM_LAYER_HEIGHT_OFFSET + layer_index * INPUT_LAYER_OFFSET) / (inc_step * 4);
				i < (DM_LAYER_HEIGHT_OFFSET + layer_index * INPUT_LAYER_OFFSET + VALID_DUMP_LAYER_INFO) / (inc_step * 4); ++i) {
			val1 = inp32(current_addr++);
			val2 = inp32(current_addr++);
			val3 = inp32(current_addr++);
			val4 = inp32(current_addr++);
			dsm_client_record(dsm_lcd_client, "%x|%x|%x|%x|", val1, val2, val3, val4);
		}
	}

	if (ldi_vstate == LDI_VSTATE_V_WAIT_TE0)
		dsm_client_notify(dsm_lcd_client, DSM_LCD_TE_TIME_OUT_ERROR_NO);
	else
		dsm_client_notify(dsm_lcd_client, DSM_LCD_LDI_UNDERFLOW_NO);
}

void dpu_comp_abnormal_dsm_dump_reg_dm(char __iomem *dpu_base, uint32_t scene_id)
{
	uint32_t i = 0;
	uint32_t dump_cnt= 0;
	uint32_t layer_index = 0;
	uint32_t inc_step = 4;
	uint32_t val1, val2, val3, val4, ldi_vstate;
	uint32_t *dm_addr = NULL;
	uint32_t *current_addr = NULL;
	uint32_t cnt = 0;
	uint32_t layer_cnt = 0;
	uint64_t timestamp;
	struct timespec64 tv;
	DPU_DM_LAYER_NUMBER_UNION reg_layer_number;

	if (unlikely(scene_id >= DPU_SCENE_MAX)) {
		dpu_pr_err("scene_id = %u is out of range", scene_id);
		return;
	}

	dm_addr = (uint32_t *)(dpu_base + g_dm_tlb_info[scene_id].dm_data_addr);

	reg_layer_number.value = inp32(DPU_DM_LAYER_NUMBER_ADDR(
								(char __iomem *)(dpu_base + g_dm_tlb_info[scene_id].dm_data_addr)));
	layer_cnt = reg_layer_number.reg.layer_number;

	dpu_check_and_no_retval(!dsm_lcd_client, info, "dsm_lcd_client is null!");

	while((dsm_client_ocuppy(dsm_lcd_client) != 0) && (cnt < DSM_OCCUPY_RETRY_TIMES)) {
		dpu_pr_warn("dsm_client_ocuppy failed, retry %d times", ++cnt);
		usleep_range(500, 600);
	}

	if (cnt == DSM_OCCUPY_RETRY_TIMES) {
		dpu_pr_warn("dsm_client_ocuppy failed");
		return;
	}

	ktime_get_real_ts64(&tv);
	timestamp = (tv.tv_sec * 1000 * 1000) + (tv.tv_nsec / 1000);

	ldi_vstate = inp32(DPU_DSI_VSTATE_ADDR(dpu_base));
	dsm_client_record(dsm_lcd_client, "dpu_dmd %llu|%d|%d|%d|", timestamp, ldi_vstate, scene_id, layer_cnt);

	for (dump_cnt = 0; dump_cnt < dpu_comp_get_dsm_dm_dump_cnt(); ++dump_cnt) {
		current_addr = dm_addr + dsm_dm_dump_range[dump_cnt].start_addr / 4;
		for (i = dsm_dm_dump_range[dump_cnt].start_addr / (inc_step * 4);
				i < (dsm_dm_dump_range[dump_cnt].end_addr / (inc_step * 4)); ++i) {
			val1 = inp32(current_addr++);
			val2 = inp32(current_addr++);
			val3 = inp32(current_addr++);
			val4 = inp32(current_addr++);
			dsm_client_record(dsm_lcd_client, "%x|%x|%x|%x|", val1, val2, val3, val4);
		}
	}

	for (layer_index = 0; layer_index < MAX_DUMP_LAYER_CNT; ++layer_index) {
		current_addr = dm_addr + (DM_LAYER_HEIGHT_OFFSET + layer_index * INPUT_LAYER_OFFSET) / 4;
		for (i = (DM_LAYER_HEIGHT_OFFSET + layer_index * INPUT_LAYER_OFFSET) / (inc_step * 4);
				i < (DM_LAYER_HEIGHT_OFFSET + layer_index * INPUT_LAYER_OFFSET + VALID_DUMP_LAYER_INFO) / (inc_step * 4); ++i) {
			val1 = inp32(current_addr++);
			val2 = inp32(current_addr++);
			val3 = inp32(current_addr++);
			val4 = inp32(current_addr++);
			dsm_client_record(dsm_lcd_client, "%x|%x|%x|%x|", val1, val2, val3, val4);
		}
	}

	if (ldi_vstate == LDI_VSTATE_V_WAIT_TE0)
		dsm_client_notify(dsm_lcd_client, DSM_LCD_TE_TIME_OUT_ERROR_NO);
	else
		dsm_client_notify(dsm_lcd_client, DSM_LCD_LDI_UNDERFLOW_NO);

	if (layer_cnt >= MAX_DUMP_LAYER_CNT)
		dpu_comp_abnormal_dsm_dump_reg_layer(dm_addr, MAX_DUMP_LAYER_CNT, layer_cnt, ldi_vstate);
}

void dpu_comp_abnormal_debug_dump(struct dpu_composer *dpu_comp, uint32_t scene_id)
{
	uint32_t i;
	char __iomem *module_base = NULL;
	if (!dpu_comp) {
		dpu_pr_err("dpu_comp is null");
		return;
	}
	module_base = dpu_comp->comp_mgr->dpu_base + DPU_GLB0_OFFSET;

	dpu_pr_warn("scene_id=%u ip_status: DBG_IP_STATE0=%#x DBG_IP_STATE1=%#x", scene_id,
		inp32(DPU_GLB_DBG_IP_STATE0_ADDR(module_base)), inp32(DPU_GLB_DBG_IP_STATE1_ADDR(module_base)));

	dpu_print_dvfs_vote_status();

	dpu_pr_warn("OV:\n"
		"\tDBG_OV_YCNT0=%#x\tDBG_OV_YCNT1=%#x\tDBG_OV_YCNT2=%#x\tDBG_OV_YCNT3=%#x\n\n",
		inp32(DPU_GLB_DBG_OV_YCNT0_ADDR(module_base)), inp32(DPU_GLB_DBG_OV_YCNT1_ADDR(module_base)),
		inp32(DPU_GLB_DBG_OV_YCNT2_ADDR(module_base)), inp32(DPU_GLB_DBG_OV_YCNT3_ADDR(module_base)));

	for (i = 0; i < OPR_SDMA_NUM; ++i)
		dpu_pr_warn("SDMA[%u]:\n"
			"\tSDMA_DBG_MONITOR0=%#x\t\tSDMA_DBG_MONITOR1=%#x\n\tSDMA_DBG_MONITOR2=%#x\t\tSDMA_DBG_MONITOR3=%#x\n"
			"\tSDMA_DBG_MONITOR4=%#x\t\tSDMA_DBG_MONITOR5=%#x\n\tSDMA_W_DBG0=%#x\t\tSDMA_W_DBG1=%#x\n"
			"\tSDMA_W_DBG2=%#x\t\tSDMA_W_DBG3=%#x\n\n", i,
			inp32(DPU_GLB_SDMA_DBG_MONITOR0_ADDR(module_base, i)), inp32(DPU_GLB_SDMA_DBG_MONITOR1_ADDR(module_base, i)),
			inp32(DPU_GLB_SDMA_DBG_MONITOR2_ADDR(module_base, i)), inp32(DPU_GLB_SDMA_DBG_MONITOR3_ADDR(module_base, i)),
			inp32(DPU_GLB_SDMA_DBG_MONITOR4_ADDR(module_base, i)), inp32(DPU_GLB_SDMA_DBG_MONITOR5_ADDR(module_base, i)),
			inp32(DPU_GLB_SDMA_W_DBG0_ADDR(module_base, i)), inp32(DPU_GLB_SDMA_W_DBG1_ADDR(module_base, i)),
			inp32(DPU_GLB_SDMA_W_DBG2_ADDR(module_base, i)), inp32(DPU_GLB_SDMA_W_DBG3_ADDR(module_base, i)));

	for (i = 0; i < OPR_CLD_NUM; ++i) {
		module_base = dpu_comp->comp_mgr->dpu_base + g_cld_offset[i];
		dpu_pr_warn("CLD[%u]:\n"
			"\tR_LB_DEBUG0=%#x\t\tR_LB_DEBUG1=%#x\t\tR_LB_DEBUG2=%#x\t\tR_LB_DEBUG3=%#x\n"
			"\tW_LB_DEBUG0=%#x\t\tW_LB_DEBUG1=%#x\t\tW_LB_DEBUG2=%#x\t\tW_LB_DEBUG3=%#x\n\n", i,
			inp32(DPU_CLD_R_LB_DEBUG0_ADDR(module_base)), inp32(DPU_CLD_R_LB_DEBUG0_ADDR(module_base)),
			inp32(DPU_CLD_R_LB_DEBUG0_ADDR(module_base)), inp32(DPU_CLD_R_LB_DEBUG0_ADDR(module_base)),
			inp32(DPU_CLD_W_LB_DEBUG0_ADDR(module_base)), inp32(DPU_CLD_W_LB_DEBUG0_ADDR(module_base)),
			inp32(DPU_CLD_W_LB_DEBUG0_ADDR(module_base)), inp32(DPU_CLD_W_LB_DEBUG0_ADDR(module_base)));
	}

	module_base = dpu_comp->comp_mgr->dpu_base + DPU_DBCU_OFFSET;
	dpu_pr_warn("DBCU:\n"
		"\tMONITOR_OS_R0=%#x\t\tMONITOR_OS_R1=%#x\t\tMONITOR_OS_R2=%#x\t\tMONITOR_OS_R3=%#x\t\tMONITOR_OS_R4=%#x\n"
		"\tMONITOR_OS_W0=%#x\t\tMONITOR_OS_W1=%#x\t\tMONITOR_OS_W2=%#x\t\tMONITOR_OS_W3=%#x\n"
		"\tAIF_STAT_0=%#x\t\tAIF_STAT_1=%#x\t\tAIF_STAT_2=%#x\t\tAIF_STAT_3=%#x\n"
		"\tAIF_STAT_4=%#x\t\tAIF_STAT_5=%#x\t\tAIF_STAT_6=%#x\t\tAIF_STAT_7=%#x\n"
		"\tAIF_STAT_8=%#x\t\tAIF_STAT_9=%#x\t\tAIF_STAT_10=%#x\t\tAIF_STAT_11=%#x\n"
		"\tAIF_STAT_12=%#x\t\tAIF_STAT_13=%#x\t\tAIF_STAT_14=%#x\t\tAIF_STAT_15=%#x\n\n",
		inp32(DPU_DBCU_MONITOR_OS_R0_ADDR(module_base)), inp32(DPU_DBCU_MONITOR_OS_R1_ADDR(module_base)),
		inp32(DPU_DBCU_MONITOR_OS_R2_ADDR(module_base)), inp32(DPU_DBCU_MONITOR_OS_R3_ADDR(module_base)),
		inp32(DPU_DBCU_MONITOR_OS_R4_ADDR(module_base)),
		inp32(DPU_DBCU_MONITOR_OS_W0_ADDR(module_base)), inp32(DPU_DBCU_MONITOR_OS_W1_ADDR(module_base)),
		inp32(DPU_DBCU_MONITOR_OS_W2_ADDR(module_base)), inp32(DPU_DBCU_MONITOR_OS_W3_ADDR(module_base)),
		inp32(DPU_DBCU_AIF_STAT_0_ADDR(module_base)), inp32(DPU_DBCU_AIF_STAT_1_ADDR(module_base)),
		inp32(DPU_DBCU_AIF_STAT_2_ADDR(module_base)), inp32(DPU_DBCU_AIF_STAT_3_ADDR(module_base)),
		inp32(DPU_DBCU_AIF_STAT_4_ADDR(module_base)), inp32(DPU_DBCU_AIF_STAT_5_ADDR(module_base)),
		inp32(DPU_DBCU_AIF_STAT_6_ADDR(module_base)), inp32(DPU_DBCU_AIF_STAT_7_ADDR(module_base)),
		inp32(DPU_DBCU_AIF_STAT_8_ADDR(module_base)), inp32(DPU_DBCU_AIF_STAT_9_ADDR(module_base)),
		inp32(DPU_DBCU_AIF_STAT_10_ADDR(module_base)), inp32(DPU_DBCU_AIF_STAT_11_ADDR(module_base)),
		inp32(DPU_DBCU_AIF_STAT_12_ADDR(module_base)), inp32(DPU_DBCU_AIF_STAT_13_ADDR(module_base)),
		inp32(DPU_DBCU_AIF_STAT_14_ADDR(module_base)), inp32(DPU_DBCU_AIF_STAT_15_ADDR(module_base)));

	if (scene_id <= DPU_SCENE_ONLINE_3) {
		module_base = dpu_comp->comp_mgr->dpu_base + g_itfsw_offset[scene_id];
		dpu_pr_warn("ITFSW:\n"
			"\tR_LB_DEBUG0=%#x\t\tR_LB_DEBUG1=%#x\t\tR_LB_DEBUG2=%#x\t\tR_LB_DEBUG3=%#x\n\n",
			inp32(DPU_ITF_CH_R_LB_DEBUG0_ADDR(module_base)), inp32(DPU_ITF_CH_R_LB_DEBUG1_ADDR(module_base)),
			inp32(DPU_ITF_CH_R_LB_DEBUG2_ADDR(module_base)), inp32(DPU_ITF_CH_R_LB_DEBUG3_ADDR(module_base)));
	}

	dpu_comp_abnormal_dump_lbuf(dpu_comp->comp_mgr->dpu_base);
	dpu_comp_abnormal_dump_dacc(dpu_comp->comp_mgr->dpu_base, scene_id);
}

static void dpu_comp_abnormal_notify_ldi_status_invalid(struct dpu_composer *dpu_comp, int32_t ldi_status)
{
	dpu_check_and_no_retval(!dsm_lcd_client, info, "dsm_lcd_client is null!");

	if (dsm_client_ocuppy(dsm_lcd_client) == 0) {
		dsm_client_record(dsm_lcd_client, "ldi status %d is invalid", ldi_status);
		dsm_client_notify(dsm_lcd_client, DSM_LCD_VACTIVE_TIMEOUT_ERROR_NO);
		return;
	}

	dsm_client_unocuppy(dsm_lcd_client);
	usleep_range(500, 600);
	if (dsm_client_ocuppy(dsm_lcd_client) == 0) {
		dsm_client_record(dsm_lcd_client, "ldi status %d is invalid", ldi_status);
		dsm_client_notify(dsm_lcd_client, DSM_LCD_VACTIVE_TIMEOUT_ERROR_NO);
		return;
	}

	dpu_pr_warn("dsm_client_ocuppy failed");
}

static void dpu_comp_abnormal_handle_work(struct kthread_work *work)
{
	int32_t ret;
	uint64_t tv0;
	struct comp_online_present *present = NULL;
	struct dpu_composer *dpu_comp = NULL;

	present = container_of(work, struct comp_online_present, abnormal_handle_work);
	if (!present || !present->dpu_comp) {
		dpu_pr_err("present_data or dpu_comp is null");
		return;
	}
	dpu_comp = present->dpu_comp;
	dpu_trace_ts_begin(&tv0);

	if ((dpu_comp->comp.comp_err_status & ABNORMAL_CHECK_LDI_FAILED) != 0) {
		dpu_pr_err("ldi status %d is invalid, notify to dsm", present->vactive_ldi_status);
		dpu_comp_abnormal_notify_ldi_status_invalid(dpu_comp, present->vactive_ldi_status);
		present->vactive_ldi_status = 0;
		dpu_comp->comp.comp_err_status &= ~ABNORMAL_CHECK_LDI_FAILED;
	}

	if (dpu_comp->comp.comp_err_status == 0)
		return;

	composer_manager_power_down(dpu_comp);
	if (unlikely(dpu_comp->comp_mgr->power_status.status == 0)) {
		dpu_pr_info("already power off, do not need handle underflow clear!");
		composer_manager_power_up(dpu_comp);
		return;
	}

#ifdef CONFIG_DKMD_DEBUG_ENABLE
	if (g_cmdlist_dump_enable)
		dpu_comp_abnormal_dump_cmdlist_dm();
#endif

	if (g_debug_underflow_dump_enable) {
		dpu_comp_abnormal_debug_dump(dpu_comp, present->frames[present->displayed_idx].in_frame.scene_id);
		dpu_comp_abnormal_dump_reg_dm(dpu_comp->comp_mgr->dpu_base,
					present->frames[present->displayed_idx].in_frame.scene_id);
		dpu_parse_layer_info(dpu_comp->comp_mgr->dpu_base, present->frames[present->displayed_idx].in_frame.scene_id);
		dpu_comp_abnormal_dsm_dump_reg_dm(dpu_comp->comp_mgr->dpu_base,
					present->frames[present->displayed_idx].in_frame.scene_id);
	}

	/* dump panel info */
	(void)pipeline_next_ops_handle(dpu_comp->conn_info->conn_device, dpu_comp->conn_info, DUMP_EXCEPTION_INFO, NULL);

	dpu_comp->isr_ctrl.handle_func(&dpu_comp->isr_ctrl, DKMD_ISR_DISABLE);
	if (dpu_comp->conn_info->disable_ldi)
		dpu_comp->conn_info->disable_ldi(dpu_comp->conn_info);

	ret = dpu_comp_handle_underflow_clear(dpu_comp);
	if (ret != 0) {
		dpu_pr_warn("underflow clear failed, reset hardware!!");
		/* to balance isr_enable in reset hardware, we need enable isr here */
		dpu_comp->isr_ctrl.handle_func(&dpu_comp->isr_ctrl, DKMD_ISR_ENABLE);
		composer_manager_reset_hardware(dpu_comp);
		dpu_comp->isr_ctrl.handle_func(&dpu_comp->isr_ctrl, DKMD_ISR_DISABLE);
	} else {
		dpu_pr_warn("underflow clear successfully!");
		if (dpu_comp->clear_succ_frame_index_queue[0] && dpu_comp->clear_succ_frame_index_queue[1] &&
			(dpu_comp->comp.comp_frame_index - dpu_comp->clear_succ_frame_index_queue[1] <=
				COMP_TIMEOUT_FRAME_COUNT)) {
			dpu_pr_warn("underflow clear occurs continuously, need reset hardware");
			dpu_comp->isr_ctrl.handle_func(&dpu_comp->isr_ctrl, DKMD_ISR_ENABLE);
			composer_manager_reset_hardware(dpu_comp);
			dpu_comp->isr_ctrl.handle_func(&dpu_comp->isr_ctrl, DKMD_ISR_DISABLE);
			dpu_comp->clear_succ_frame_index_queue[0] = 0;
		} else {
			dpu_comp->clear_succ_frame_index_queue[1] = dpu_comp->clear_succ_frame_index_queue[0];
			dpu_comp->clear_succ_frame_index_queue[0] = dpu_comp->comp.comp_frame_index;
		}
	}

	dpu_comp->isr_ctrl.handle_func(&dpu_comp->isr_ctrl, DKMD_ISR_ENABLE);
	dpu_comp->comp.comp_err_status = 0;

	composer_manager_power_up(dpu_comp);

	dpu_trace_ts_end(&tv0, "handle underflow clear");
}

static int32_t dpu_comp_abnormal_handle_isr_notify(struct notifier_block *self, unsigned long action, void *data)
{
	uint32_t displaying_scene_id, displayed_scene_id;
	uint32_t displaying_frame_index, displayed_frame_index;
	uint32_t vstate;
	uint32_t phy_status;
	struct comp_online_present *present = NULL;
	struct dkmd_listener_data *listener_data = (struct dkmd_listener_data *)data;
	struct dpu_composer *dpu_comp = (struct dpu_composer *)(listener_data->data);
	struct dpu_connector *connector = get_primary_connector(dpu_comp->conn_info);

	dpu_check_and_return(!dpu_comp, -1, err, "dpu_comp is NULL!");
	present = (struct comp_online_present *)dpu_comp->present_data;
	displaying_frame_index = present->frames[present->displaying_idx].in_frame.frame_index;
	displayed_frame_index = present->frames[present->displayed_idx].in_frame.frame_index;

	dpu_pr_warn("action=%#x enter, frame_index=%u, displaying_frame_index = %u, displayed_frame_index = %u,\
		dpp_dbg=0x%x, vcount=0x%x, vstate=0x%x",
		action, dpu_comp->comp.comp_frame_index,
		displaying_frame_index, displayed_frame_index,
		inp32(DPU_DPP_CH_DBG_CNT_ADDR(dpu_comp->comp_mgr->dpu_base + DPU_DPP0_OFFSET)),
		inp32(DPU_DSI_VCOUNT_ADDR(connector->connector_base)),
		inp32(DPU_DSI_VSTATE_ADDR(connector->connector_base)));

	dpu_comp->isr_ctrl.unmask |= DSI_INT_UNDER_FLOW;

	displaying_scene_id = (uint32_t)(present->frames[present->displaying_idx].in_frame.scene_id);
	displayed_scene_id = (uint32_t)(present->frames[present->displayed_idx].in_frame.scene_id);

	dpu_comp_abnormal_debug_dump(dpu_comp, displaying_scene_id);
	if (displaying_scene_id != displayed_scene_id) {
		dpu_pr_info("scene_id has changed: %d --> %d", displayed_scene_id, displaying_scene_id);
		dpu_comp_abnormal_debug_dump(dpu_comp, displayed_scene_id);
	}

	vstate = inp32(DPU_DSI_VSTATE_ADDR(connector->connector_base));
	phy_status = inp32(DPU_DSI_CDPHY_STATUS_ADDR(connector->connector_base));
	if (vstate == LDI_VSTATE_V_WAIT_TE0 || (!mipi_panel_check_reg(connector) && (phy_status & BIT(1)))) {
		if (dpu_comp->conn_info->esd_enable) {
			dpu_comp->esd_ctrl.esd_recover_state = ESD_RECOVER_STATE_START;
			if (dpu_comp->esd_ctrl.esd_check_wq)
				queue_work(dpu_comp->esd_ctrl.esd_check_wq, &(dpu_comp->esd_ctrl.esd_check_work));
		}
	}

	if (g_debug_dpu_clear_enable) {
		dpu_comp->comp.comp_err_status |= ABNORMAL_UNDERFLOW;
		kthread_queue_work(&dpu_comp->handle_worker, &present->abnormal_handle_work);
	}

	return 0;
}

static struct notifier_block abnormal_handle_isr_notifier = {
	.notifier_call = dpu_comp_abnormal_handle_isr_notify,
};

void dpu_comp_abnormal_handle_init(struct dkmd_isr *isr, struct dpu_composer *dpu_comp, uint32_t listening_bit)
{
	struct comp_online_present *present = (struct comp_online_present *)dpu_comp->present_data;

	kthread_init_work(&present->abnormal_handle_work, dpu_comp_abnormal_handle_work);

	dkmd_isr_register_listener(isr, &abnormal_handle_isr_notifier, listening_bit, dpu_comp);
}

void dpu_comp_abnormal_handle_deinit(struct dkmd_isr *isr, uint32_t listening_bit)
{
	dkmd_isr_unregister_listener(isr, &abnormal_handle_isr_notifier, listening_bit);
}
