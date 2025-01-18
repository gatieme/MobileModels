/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * 功能说明 : hmac_sme_sta.c 的头文件
 * 作    者 : wifi
 * 创建日期 : 2013年6月28日
 */

#ifndef HMAC_SME_STA_H
#define HMAC_SME_STA_H

#include "oal_types.h"
#include "hmac_vap.h"
#include "hmac_mgmt_sta.h"
#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_SME_STA_H

typedef void (*hmac_sme_handle_rsp_func)(hmac_vap_stru *hmac_vap, uint8_t *msg);

/* 上报给SME结果 类型定义 */
typedef enum {
    HMAC_SME_SCAN_RSP,
    HMAC_SME_JOIN_RSP,
    HMAC_SME_AUTH_RSP,
    HMAC_SME_ASOC_RSP,
    HMAC_SME_RSP_BUTT
} hmac_sme_rsp_enum;

typedef enum {
    HMAC_AP_SME_START_RSP = 0,
    HMAC_AP_SME_RSP_BUTT
} hmac_ap_sme_rsp_enum;

#define     MAX_AUTH_CNT        5
#define     MAX_PREAUTH_CNT     3
#define     MAX_ASOC_CNT        5

void hmac_send_rsp_to_sme_sta(hmac_vap_stru *hmac_vap, hmac_sme_rsp_enum type, uint8_t *msg);
void hmac_handle_scan_rsp_sta(hmac_vap_stru *hmac_vap, uint8_t *msg);
void hmac_handle_join_rsp_sta(hmac_vap_stru *hmac_vap, uint8_t *msg);
void hmac_handle_auth_rsp_sta(hmac_vap_stru *hmac_vap, uint8_t *msg);
void hmac_handle_asoc_rsp_sta(hmac_vap_stru *hmac_vap, uint8_t *msg);
void hmac_prepare_join_req(hmac_join_req_stru *join_req, mac_bss_dscr_stru *bss_dscr);
uint32_t hmac_sta_update_join_req_params(hmac_vap_stru *hmac_vap, hmac_join_req_stru *join_req);

#ifdef _PRE_WLAN_FEATURE_SAE
uint32_t hmac_report_external_auth_req(hmac_vap_stru *hmac_vap, oal_nl80211_external_auth_action action,
    oal_bool_enum_uint8 roam_report);
#endif /* _PRE_WLAN_FEATURE_SAE */
void hmac_handle_connect_failed_result(hmac_vap_stru *hmac_vap, uint16_t status, uint8_t *user_addr);
void hmac_handle_asoc_rsp_succ_sta(hmac_vap_stru *hmac_vap, uint8_t *msg, hmac_asoc_rsp_stru *asoc_rsp);
void hmac_report_connect_failed_result(hmac_vap_stru *hmac_vap, mac_status_code_enum_uint16 reason_code,
    uint8_t *peer_addr);
void hmac_prepare_auth_req(hmac_vap_stru *pst_hmac_vap, hmac_auth_req_stru *pst_auth_req);
void hmac_send_connect_result_to_dmac_sta(hmac_vap_stru *hmac_vap, uint32_t result);
void hmac_free_scan_param_resource(mac_cfg80211_scan_param_stru *scan_param);
uint32_t hmac_connect_gc_join_wait_noa_end(frw_event_mem_stru *event_mem);
#endif /* end of hmac_sme_sta.h */
