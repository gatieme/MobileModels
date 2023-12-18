/*
 * 版权所有 (c) 华为技术有限公司 2019-2020
 * 功能说明 : hmac_location_ram.c 的头文件
 * 作    者 : zwx5321421
 * 创建日期 : 2020年9月10日
 */

#ifndef __HMAC_LOCATION_RAM_H__
#define __HMAC_LOCATION_RAM_H__

/* 1 其他头文件包含 */
#include "hmac_chan_mgmt.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_LOCATION_RAM_H

/*  函数声明 */
#ifdef _PRE_WLAN_FEATURE_LOCATION_RAM
extern oal_uint32 hmac_huawei_action_process(hmac_vap_stru *pst_hmac_vap,
                                             oal_netbuf_stru *pst_netbuf,
                                             oal_uint8 uc_type);
extern oal_void hmac_sta_up_rx_action_nonuser(hmac_vap_stru *pst_hmac_vap, oal_netbuf_stru *pst_netbuf);
#endif


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
