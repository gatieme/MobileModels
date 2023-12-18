/*
 * 版权所有 (c) 华为技术有限公司 2020-2020
 * 功能说明   : bfgx_platform_msg_handle.c头文件
 * 作者       : z00299054
 * 创建日期   : 2020年5月26日
 */
#ifndef __BFGX_PLATFORM_MSG_HANDLE_H__
#define __BFGX_PLATFORM_MSG_HANDLE_H__

#include "hw_bfg_ps.h"

typedef enum {
    THREAD_FLAG_INIT = 0x00,
    THREAD_FLAG_EXIT = 0x01,
    THREAD_FLAG_BUTT = 0x02,
} bfgx_thread_flag_enum;

int32 ps_exe_sys_func(struct ps_core_s *ps_core_d, uint8 *buf_ptr);
#endif /* __BFGX_PLATFORM_MSG_HANDLE_H__ */
