/**
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 *
 * Description:Encapsulation of functional interfaces related to the hardware platform
 * Author: @CompanyNameTag
 */

/* 头文件包含 */
#include "oal_hardware.h"
#include "oal_schedule.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_OAL_HARDWARE_C

/* 全局变量定义 */
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
oal_hi_timer_reg_stru *g_reg_timer;

uint32_t g_irq_save_time[MAX_NUM_CORES][OAL_TIMER_IRQ_TYPE_MAX_NUM] = {{0}, {0}};

oal_module_symbol(g_irq_save_time);
oal_module_symbol(g_reg_timer);

#endif
