/*
 * 版权所有 (c) 华为技术有限公司 2012-2018
 * 功能说明   : wlan产品规格宏定义，里面划分各个模块的spec的定义
 *              请新加规格的人负责分清所属模块，不要乱放
 *              本规格规定了WiTP MPW0 + 5115H的版本
 * 作者       : 康国昌
 * 创建日期   : 2012年9月26日
 */

#ifndef __PLATFORM_SPEC_H__
#define __PLATFORM_SPEC_H__

/* 其他头文件包含 */
#include "oal_types.h"
#if ((_PRE_PRODUCT_ID == _PRE_PRODUCT_ID_HI1102_DEV) || (_PRE_PRODUCT_ID == _PRE_PRODUCT_ID_HI1102_HOST))
#include "platform_spec_1102.h"
#elif ((_PRE_PRODUCT_ID == _PRE_PRODUCT_ID_HI1102A_DEV) || (_PRE_PRODUCT_ID == _PRE_PRODUCT_ID_HI1102A_HOST))
#include "platform_spec_1102a.h"
#elif ((_PRE_PRODUCT_ID == _PRE_PRODUCT_ID_HI1103_DEV) || (_PRE_PRODUCT_ID == _PRE_PRODUCT_ID_HI1103_HOST))
#include "platform_spec_1103.h"
#endif

#endif /* end of wlan_spec.h */
