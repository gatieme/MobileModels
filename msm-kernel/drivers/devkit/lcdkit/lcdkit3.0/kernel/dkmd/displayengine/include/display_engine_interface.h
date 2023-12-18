/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: displayengine interface definitions.
 * Author: dangqipeng 00452637
 * Create: 2023-03-07
 */

#ifndef __DISPLAY_ENGINE_INTERFACE_H__
#define __DISPLAY_ENGINE_INTERFACE_H__

int display_engine_get_param(void __user *argp);
int display_engine_set_param(void __user *argp);
void display_engine_init(void);
void lcd_kit_display_engine_param_init(int panel_id, struct device_node *np);
void display_engine_vsync_queue_work(void);

#endif