/*
 * 版权所有 (c) 华为技术有限公司 2013-2018
 * 功能说明   : infusion静态检查宏定义
 * 作者       : 邹嵘
 * 创建日期   : 2013年12月26日
 */

#ifndef __OAL_INFUSION_H__
#define __OAL_INFUSION_H__

/* 宏定义 */
#define OAL_STATIC static
#ifdef INLINE_TO_FORCEINLINE
#define OAL_INLINE __forceinline
#else
#define OAL_INLINE inline
#endif

#endif /* end of oal_ext_if.h */
