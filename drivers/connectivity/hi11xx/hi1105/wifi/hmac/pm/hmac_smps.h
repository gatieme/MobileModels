/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * 功能说明 : hmac_smps.c 的头文件
 * 作    者 : wifi
 * 创建日期 : 2014年4月17日
 */

#ifndef HMAC_SMPS_H
#define HMAC_SMPS_H

#ifdef _PRE_WLAN_FEATURE_SMPS

/* 1 其他头文件包含 */
#include "oal_ext_if.h"
#include "hmac_main.h"
#include "oam_ext_if.h"
#include "mac_resource.h"

#include "mac_device.h"
#include "mac_vap.h"
#include "hmac_vap.h"
#include "mac_user.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_SMPS_H
/* 2 宏定义 */
/* 3 枚举定义 */
/* 4 全局变量声明 */
/* 5 消息头定义 */
/* 6 消息定义 */
/* 7 STRUCT定义 */
/* 8 UNION定义 */
/* 9 OTHERS定义 */
/* 10 函数声明 */
uint32_t hmac_mgmt_rx_smps_frame(mac_vap_stru *pst_mac_vap,
                                 hmac_user_stru *pst_hmac_user,
                                 uint8_t *puc_data);
uint32_t hmac_smps_update_user_status(mac_vap_stru *pst_mac_vap, mac_user_stru *pst_mac_user);

#endif /* end of _PRE_WLAN_FEATURE_SMPS */
#endif /* end of hmac_smps.h */
