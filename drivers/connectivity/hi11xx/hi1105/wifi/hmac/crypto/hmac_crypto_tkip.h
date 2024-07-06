/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * 功能说明 : hmac_crypto_tkip.c 的头文件
 * 作    者 : wifi
 * 创建日期 : 2014年3月1日
 */

#ifndef HMAC_CRYPTO_FRAME_H
#define HMAC_CRYPTO_FRAME_H

/* 1 其他头文件包含 */
#include "oal_ext_if.h"
#include "mac_vap.h"

/* 2 宏定义 */
#define IEEE80211_WEP_MICLEN 8 /* trailing MIC */

#define IEEE80211_FC1_DIR_NODS   0x00 /* STA->STA */
#define IEEE80211_FC1_DIR_TODS   0x01 /* STA->AP  */
#define IEEE80211_FC1_DIR_FROMDS 0x02 /* AP ->STA */
#define IEEE80211_FC1_DIR_DSTODS 0x03 /* AP ->AP  */

#define IEEE80211_NON_QOS_SEQ     16 /* index for non-QoS (including management) sequence number space */
#define IEEE80211_FC0_TYPE_MASK   0x0c
#define IEEE80211_FC0_SUBTYPE_QOS 0x80
#define IEEE80211_FC0_TYPE_DATA   0x08

#define WEP_IV_FIELD_SIZE 4 /* wep IV field size */
#define EXT_IV_FIELD_SIZE 4 /* ext IV field size */

/* 3 枚举定义 */
/* 4 全局变量声明 */
/* 5 消息头定义 */
/* 6 消息定义 */
/* 7 STRUCT定义 */
/* 8 UNION定义 */
/* 9 OTHERS定义 */
/* 10 函数声明 */
uint32_t hmac_crypto_tkip_enmic(wlan_priv_key_param_stru *pst_key, oal_netbuf_stru *pst_netbuf);
uint32_t hmac_crypto_tkip_demic(wlan_priv_key_param_stru *pst_key, oal_netbuf_stru *pst_netbuf);

#endif /* end of hmac_crypto_tkip.h */
