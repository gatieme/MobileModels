/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: safe frame rate control decision interface.
 */

#ifndef __LCD_KIT_SAFE_FRM_RATE_
#define __LCD_KIT_SAFE_FRM_RATE_

#include <linux/kernel.h>

#include "lcd_kit_common.h"
#include "dkmd_lcd_interface.h"

int lcd_kit_safe_frm_rate_ctrl(int panel_id, const struct panel_update_safe_frm_rate_info *safe_frm_info);
void lcd_kit_safe_frm_init(int panel_id, struct device_node *np);
void safe_frm_rate_vsync_workqueue_init(int panel_id);
#endif