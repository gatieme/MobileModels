/*
 * 版权所有 (c) 华为技术有限公司 2015-2018
 * 功能说明   : oneimage驱动判断device芯片类型
 * 作者       : C00351912
 * 创建日期   : 2015年05月30日
 */

#ifndef __HISI__ONEIMAGE_H__
#define __HISI__ONEIMAGE_H__

#include <linux/version.h>
#ifdef CONFIG_HWCONNECTIVITY
#if (LINUX_VERSION_CODE < KERNEL_VERSION(4, 1, 0))
#include <linux/huawei/hw_connectivity.h>
#include <linux/huawei/gps/huawei_gps.h>
#else
#include <huawei_platform/connectivity/hw_connectivity.h>
#include <huawei_platform/connectivity/huawei_gps.h>
#endif
#endif

#endif
