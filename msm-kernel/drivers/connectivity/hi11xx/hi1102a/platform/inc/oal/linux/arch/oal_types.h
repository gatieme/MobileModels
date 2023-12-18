/*
 * 版权所有 (c) 华为技术有限公司 2012-2018
 * 功能说明   : oal_types.h 的头文件,基本数据类型定义
 * 作者       : c59720
 * 创建日期   : 2012年9月7日
 */

#ifndef __OAL_LINUX_TYPES_H__
#define __OAL_LINUX_TYPES_H__

/* 其他头文件包含 */
/* 基本数据类型定义 */
typedef signed char oal_int8;          /* 数据前缀:c */
typedef signed short oal_int16;        /* 数据前缀:s */
typedef signed int oal_int32;          /* 数据前缀:l */
typedef signed long long oal_int64;    /* 数据前缀:ll */
typedef unsigned char oal_uint8;       /* 数据前缀:uc */
typedef unsigned short oal_uint16;     /* 数据前缀:us */
typedef unsigned int oal_uint32;       /* 数据前缀:ul */
typedef unsigned long long oal_uint64; /* 数据前缀:ull */
typedef void oal_void;

/* 宏定义 */
#ifdef INLINE_TO_FORCEINLINE
#define OAL_INLINE __forceinline
#else
#define OAL_INLINE inline
#endif

#define OAL_STATIC static

#if defined(_PRE_PC_LINT) /* 仅适用于PC_LINT工程时 */
#define OAL_VOLATILE
#else
#define OAL_VOLATILE volatile
#endif

#endif /* end of oal_types.h */

