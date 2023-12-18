/*
 * lcd_kit_fac.c
 *
 * lcdkit factory function for lcd driver
 *
 * Copyright (c) 2022-2024 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */
#include "lcd_kit_fac.h"
#include "lcd_kit_factory.h"
#include "lcd_kit_parse.h"

static void parse_dt_checksum(int panel_id, struct device_node *np)
{
	/* check sum */
	lcd_kit_parse_u32(np, "lcd-kit,checksum-support",
		&FACT_INFO->checksum.support, 0);
	if (FACT_INFO->checksum.support) {
		lcd_kit_parse_u32(np,
			"lcd-kit,checksum-special-support",
			&FACT_INFO->checksum.special_support, 0);
		lcd_kit_parse_u32(np, "lcd-kit,checksum-need-clear-sram",
			&FACT_INFO->checksum.clear_sram, 0);
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,checksum-enable-cmds",
			"lcd-kit,checksum-enable-cmds-state",
			&FACT_INFO->checksum.enable_cmds);
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,checksum-disable-cmds",
			"lcd-kit,checksum-disable-cmds-state",
			&FACT_INFO->checksum.disable_cmds);
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,checksum-cmds",
			"lcd-kit,checksum-cmds-state",
			&FACT_INFO->checksum.checksum_cmds);
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,checksum-clear-sram-cmds",
			"lcd-kit,checksum-clear-sram-cmds-state",
			&FACT_INFO->checksum.clear_sram_cmds);
		lcd_kit_parse_arrays_data(np, "lcd-kit,checksum-value",
			&FACT_INFO->checksum.value, CHECKSUM_VALUE_SIZE);
		lcd_kit_parse_arrays_data(np, "lcd-kit,checksum-dsi1-value",
			&FACT_INFO->checksum.dsi1_value, CHECKSUM_VALUE_SIZE);
		/* checksum stress test */
		lcd_kit_parse_u32(np,
			"lcd-kit,checksum-stress-test-support",
			&FACT_INFO->checksum.stress_test_support, 0);
		if (FACT_INFO->checksum.stress_test_support) {
			lcd_kit_parse_u32(np,
				"lcd-kit,checksum-stress-test-vdd",
				&FACT_INFO->checksum.vdd, 0);
			lcd_kit_parse_u32(np,
				"lcd-kit,checksum-stress-test-mipi",
				&FACT_INFO->checksum.mipi_clk, 0);
		}
	}
}

static void parse_dt_pcd_errflag(int panel_id, struct device_node *np)
{
	/* pcd errflag check */
	lcd_kit_parse_u32(np, "lcd-kit,pcd-errflag-check-support",
		&FACT_INFO->pcd_errflag_check.pcd_errflag_check_support, 0);
	if (FACT_INFO->pcd_errflag_check.pcd_errflag_check_support) {
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,pcd-detect-open-cmds",
			"lcd-kit,pcd-read-cmds-state",
			&FACT_INFO->pcd_errflag_check.pcd_detect_open_cmds);
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,pcd-detect-close-cmds",
			"lcd-kit,pcd-read-cmds-state",
			&FACT_INFO->pcd_errflag_check.pcd_detect_close_cmds);
	}
}

static void parse_dt_mipi_error_detect(uint32_t panel_id, struct device_node *np)
{
	/* mipi error detect */
	lcd_kit_parse_u32(np, "lcd-kit,mipi-detect-support",
		&FACT_INFO->mipi_detect.support, 0);

	if (FACT_INFO->mipi_detect.support) {
		FACT_INFO->mipi_detect.pic_index = INVALID_INDEX;
		lcd_kit_parse_u32(np, "lcd-kit,mipi-detect-threshold",
			&FACT_INFO->mipi_detect.threshold, 0);
		lcd_kit_parse_u32(np, "lcd-kit,mipi-detect-dual-check",
			&FACT_INFO->mipi_detect.dual_check, 0);
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,mipi-detect-enter1-cmds",
			"lcd-kit,mipi-detect-enter1-cmds-state",
			&FACT_INFO->mipi_detect.enter_cmds[DET1_INDEX]);
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,mipi-detect-enter2-cmds",
			"lcd-kit,mipi-detect-enter2-cmds-state",
			&FACT_INFO->mipi_detect.enter_cmds[DET2_INDEX]);
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,mipi-detect-enter3-cmds",
			"lcd-kit,mipi-detect-enter3-cmds-state",
			&FACT_INFO->mipi_detect.enter_cmds[DET3_INDEX]);
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,mipi-detect-enter4-cmds",
			"lcd-kit,mipi-detect-enter4-cmds-state",
			&FACT_INFO->mipi_detect.enter_cmds[DET4_INDEX]);
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,mipi-detect-rd1-cmds",
			"lcd-kit,mipi-detect-rd1-cmds-state",
			&FACT_INFO->mipi_detect.rd_cmds[DET1_INDEX]);
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,mipi-detect-rd2-cmds",
			"lcd-kit,mipi-detect-rd2-cmds-state",
			&FACT_INFO->mipi_detect.rd_cmds[DET2_INDEX]);
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,mipi-detect-rd3-cmds",
			"lcd-kit,mipi-detect-rd3-cmds-state",
			&FACT_INFO->mipi_detect.rd_cmds[DET3_INDEX]);
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,mipi-detect-rd4-cmds",
			"lcd-kit,mipi-detect-rd4-cmds-state",
			&FACT_INFO->mipi_detect.rd_cmds[DET4_INDEX]);
		lcd_kit_parse_array_data(np, "lcd-kit,mipi-detect-value1",
			&FACT_INFO->mipi_detect.value[DET1_INDEX]);
		lcd_kit_parse_array_data(np, "lcd-kit,mipi-detect-value2",
			&FACT_INFO->mipi_detect.value[DET2_INDEX]);
		lcd_kit_parse_array_data(np, "lcd-kit,mipi-detect-value3",
			&FACT_INFO->mipi_detect.value[DET3_INDEX]);
		lcd_kit_parse_array_data(np, "lcd-kit,mipi-detect-value4",
			&FACT_INFO->mipi_detect.value[DET4_INDEX]);
	}
}

static void parse_dt_check_sum2_detect(uint32_t panel_id, struct device_node *np)
{
	/* check sum2 detect */
	lcd_kit_parse_u32(np, "lcd-kit,check-sum2-detect-support",
		&FACT_INFO->check_sum2_detect.support, 0);

	if (FACT_INFO->check_sum2_detect.support) {
		FACT_INFO->check_sum2_detect.loop_index = INVALID_INDEX;
		lcd_kit_parse_u32(np, "lcd-kit,check-sum2-detect-threshold",
			&FACT_INFO->check_sum2_detect.threshold, 0);
		lcd_kit_parse_u32(np, "lcd-kit,check-sum2-detect-delay",
			&FACT_INFO->check_sum2_detect.delay, 0);
		lcd_kit_parse_u32(np, "lcd-kit,check-sum2-detect-time",
			&FACT_INFO->check_sum2_detect.time, 0);
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,check-sum2-detect-enter1-cmds",
			"lcd-kit,check-sum2-detect-enter1-cmds-state",
			&FACT_INFO->check_sum2_detect.enter_cmds[DET1_INDEX]);
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,check-sum2-detect-rd1-cmds",
			"lcd-kit,check-sum2-detect-rd1-cmds-state",
			&FACT_INFO->check_sum2_detect.rd_cmds[DET1_INDEX]);
		lcd_kit_parse_array_data(np, "lcd-kit,check-sum2-detect-value1",
			&FACT_INFO->check_sum2_detect.value[DET1_INDEX]);
		lcd_kit_parse_u32(np, "lcd-kit,check-sum2-detect-dual-dsi-support",
			&FACT_INFO->check_sum2_detect.dual_dsi_support, 0);
	}
}

static void parse_dt_mbist_detect(uint32_t panel_id, struct device_node *np)
{
	/* mbist detect test */
	lcd_kit_parse_u32(np, "lcd-kit,mbist-det-support",
		&FACT_INFO->mbist_detect.support, 0);
	if (FACT_INFO->mbist_detect.support) {
		FACT_INFO->mbist_detect.pic_index = INVALID_INDEX;
		lcd_kit_parse_u32(np, "lcd-kit,mbist-detect-threshold",
			&FACT_INFO->mbist_detect.threshold, 0);
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,mbist-det-enter1-cmds",
			"lcd-kit,mbist-det-enter1-cmds-state",
			&FACT_INFO->mbist_detect.enter_cmds[DET1_INDEX]);
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,mbist-det-enter2-cmds",
			"lcd-kit,mbist-det-enter2-cmds-state",
			&FACT_INFO->mbist_detect.enter_cmds[DET2_INDEX]);
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,mbist-det-enter3-cmds",
			"lcd-kit,mbist-det-enter3-cmds-state",
			&FACT_INFO->mbist_detect.enter_cmds[DET3_INDEX]);
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,mbist-det-enter4-cmds",
			"lcd-kit,mbist-det-enter4-cmds-state",
			&FACT_INFO->mbist_detect.enter_cmds[DET4_INDEX]);
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,mbist-det-rd1-cmds",
			"lcd-kit,mbist-det-rd1-cmds-state",
			&FACT_INFO->mbist_detect.rd_cmds[DET1_INDEX]);
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,mbist-det-rd2-cmds",
			"lcd-kit,mbist-det-rd2-cmds-state",
			&FACT_INFO->mbist_detect.rd_cmds[DET2_INDEX]);
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,mbist-det-rd3-cmds",
			"lcd-kit,mbist-det-rd3-cmds-state",
			&FACT_INFO->mbist_detect.rd_cmds[DET3_INDEX]);
		lcd_kit_parse_dcs_cmds(np, "lcd-kit,mbist-det-rd4-cmds",
			"lcd-kit,mbist-det-rd4-cmds-state",
			&FACT_INFO->mbist_detect.rd_cmds[DET4_INDEX]);
		lcd_kit_parse_array_data(np, "lcd-kit,mbist-det-value1",
			&FACT_INFO->mbist_detect.value[DET1_INDEX]);
		lcd_kit_parse_array_data(np, "lcd-kit,mbist-det-value2",
			&FACT_INFO->mbist_detect.value[DET2_INDEX]);
		lcd_kit_parse_array_data(np, "lcd-kit,mbist-det-value3",
			&FACT_INFO->mbist_detect.value[DET3_INDEX]);
		lcd_kit_parse_array_data(np, "lcd-kit,mbist-det-value4",
			&FACT_INFO->mbist_detect.value[DET4_INDEX]);
		lcd_kit_parse_u32(np, "lcd-kit,mbist-det-dual-dsi-support",
			&FACT_INFO->mbist_detect.dual_dsi_support, 0);
	}
}

static void parse_factory_dts(int panel_id, struct device_node *np)
{
	/* parse pcd errflag */
	parse_dt_pcd_errflag(panel_id, np);
	/* parse checksum */
	parse_dt_checksum(panel_id, np);
	/* mipi detect parse */
	parse_dt_mipi_error_detect(panel_id, np);
	/* check sum2 detect parse */
	parse_dt_check_sum2_detect(panel_id, np);
	/* mbist detect parse */
	parse_dt_mbist_detect(panel_id, np);
	return;
}

int lcd_factory_init(int panel_id, struct device_node *np)
{
	lcd_kit_fact_init(panel_id, np);
	parse_factory_dts(panel_id, np);
	
	return LCD_KIT_OK;
}
