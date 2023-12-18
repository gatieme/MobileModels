/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: local hbm interface.
 * Author: zouzhiting z00808450
 * Create: 2023-03-14
 */

#ifndef __LCD_KIT_LOCAL_HBM__
#define __LCD_KIT_LOCAL_HBM__

#include <linux/kernel.h>

#include "lcd_kit_common.h"

void display_engine_local_hbm_init(void);
int display_engine_brightness_update(unsigned int bl_level);
int display_engine_local_hbm_set(int grayscale);
uint32_t display_engine_local_hbm_get_support(void);
void lcd_kit_local_hbm_cmds_parse(int panel_id, struct device_node *np);
void display_engine_local_hbm_workqueue_handler(struct kthread_work *work);

#endif
