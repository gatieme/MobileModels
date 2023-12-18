/*
 * 版权所有 (c) 华为技术有限公司 2013-2018
 * 功能说明   : 硬件平台相关功能接口封装
 * 作者       : t00231215
 * 创建日期   : 2013年1月26日
 */

/* 头文件包含 */
#include "oal_hardware.h"
#include "oal_schedule.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_OAL_HARDWARE_C

/* 全局变量定义 */
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
oal_hi_timer_reg_stru *g_reg_timer;

oal_uint32 g_irq_save_time[MAX_NUM_CORES][OAL_TIMER_IRQ_TYPE_MAX_NUM] = {{0}, {0}};

oal_module_symbol(g_irq_save_time);
oal_module_symbol(g_reg_timer);

#endif

