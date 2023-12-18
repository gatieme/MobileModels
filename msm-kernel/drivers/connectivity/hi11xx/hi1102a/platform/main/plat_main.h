/*
 * 版权所有 (c) 华为技术有限公司 2014-2018
 * 功能说明   : 驱动入口接口文件
 * 作者       : z00273164
 * 创建日期   : 2014年10月10日
 */

#ifndef __PLAT_MAIN_H__
#define __PLAT_MAIN_H__
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/* 其他头文件包含 */
#include "oal_ext_if.h"
#include "oam_ext_if.h"
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
#include "sdt_drv.h"
#endif
#include "frw_ext_if.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_PLAT_MAIN_H

extern oal_int32 plat_init(oal_void);
extern oal_void plat_exit(oal_void);
#ifdef CONFIG_HI110X_GPS_REFCLK
extern int hi_gps_plat_init(void);
extern void hi_gps_plat_exit(void);
#endif
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
