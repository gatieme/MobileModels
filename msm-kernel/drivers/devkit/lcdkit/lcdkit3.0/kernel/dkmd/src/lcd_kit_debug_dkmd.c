/*
 * lcd_kit_debug_dkmd.c
 *
 * lcdkit debug function for lcd driver of dkmd
 *
 * Copyright (c) 2019-2020 Huawei Technologies Co., Ltd.
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

#include "lcd_kit_common.h"
#include "lcd_kit_ddic_ram.h"
#include "lcd_kit_disp.h"
#include "lcd_kit_dbg.h"
#include "lcd_kit_adapt.h"
#include "lcd_kit_utils.h"
#include "base/base.h"

static int dbg_dsi_cmds_rx(uint8_t *out, int out_len,
	struct lcd_kit_dsi_panel_cmds *cmds)
{
	uint32_t panel_id = lcd_kit_get_active_panel_id();

	if (!out || !cmds) {
		LCD_KIT_ERR("out is null or cmds is null\n");
		return LCD_KIT_FAIL;
	}

	if (lcd_kit_get_panel_on_state(panel_id) == 0) {
		LCD_KIT_ERR("panel state is not on!\n");
		return LCD_KIT_FAIL;
	}

	return lcd_kit_cmds_rx(panel_id, NULL, out, out_len, cmds);
}

static bool dbg_panel_power_on(void)
{
	LCD_KIT_INFO("power on: %d\n", common_ops->panel_power_on);
	return common_ops->panel_power_on;
}

static struct lcd_kit_dbg_ops dkmd_dbg_ops = {
	.dbg_mipi_rx = dbg_dsi_cmds_rx,
	.panel_power_on = dbg_panel_power_on,
	.read_ddic_bin = lcd_kit_ddic_ram_read_bin,
	.write_ddic_bin = lcd_kit_ddic_ram_write_bin,
};

int lcd_kit_debug_init(void)
{
	LCD_KIT_INFO("enter\n");
	return lcd_kit_debug_register(&dkmd_dbg_ops);
}