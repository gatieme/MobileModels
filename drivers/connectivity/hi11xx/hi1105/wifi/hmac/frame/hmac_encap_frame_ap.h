/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * 功能说明 : hmac_encap_frame_ap.c 的头文件
 * 作    者 : wifi
 * 创建日期 : 2013年6月28日
 */

#ifndef HMAC_ENCAP_FRAME_AP_H
#define HMAC_ENCAP_FRAME_AP_H

#include "oal_ext_if.h"
#include "mac_vap.h"
#include "hmac_user.h"
#include "hmac_vap.h"
#include "securec.h"
#include "securectype.h"
#include "oal_util.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#define MAC_CHALLENGE_OFFSET 6
#define MAC_CHTXT_LEN_OFFSET 7
#define MAC_CHTXT_PAYLOAD_OFFSET 8
#define HMAC_AP_RX_FRAME_NO_RSP_MAX_TIME 100
#define HMAC_REJECT_AUTH_STATISTICS_PERIOD 1000 /* 拒绝auth的统计周期,单位ms */
#define HMAC_NO_FILTER_REJECT_AUTH_CNT 20 /* 统计周期内不被过滤的auth个数 */
#define HMAC_NO_FILTER_REJECT_AUTH_GAP_TIME 100 /* 统计周期内不被过滤auth的最小间隔,单位ms */
typedef enum {
    /* 加密方式为open */
    HMAC_AP_AUTH_SEQ1_OPEN_ANY = 0,
    /* 加密方式为wep,处理重传帧 */
    HMAC_AP_AUTH_SEQ1_WEP_NOT_RESEND,
    /* 加密方式为wep,处理非重传帧 */
    HMAC_AP_AUTH_SEQ1_WEP_RESEND,
    /* 加密方式为open */
    HMAC_AP_AUTH_SEQ3_OPEN_ANY,
    /* 加密方式为WEP,assoc状态为auth comlete */
    HMAC_AP_AUTH_SEQ3_WEP_COMPLETE,
    /* 加密方式为WEP,assoc状态为assoc */
    HMAC_AP_AUTH_SEQ3_WEP_ASSOC,
    /* 什么也不做 */
    HMAC_AP_AUTH_DUMMY,

    HMAC_AP_AUTH_BUTT
} hmac_ap_auth_process_code_enum;

typedef struct tag_hmac_auth_rsp_param_stru {
    /* 收到auth request是否为重传帧 */
    uint8_t uc_auth_resend;
    /* 记录是否为wep */
    oal_bool_enum_uint8 en_is_wep_allowed;
    /* 记录认证的类型 */
    uint16_t us_auth_type;
    /* 记录函数处理前，user的关联状态 */
    mac_user_asoc_state_enum_uint8 en_user_asoc_state;
    uint8_t uc_pad[NUM_3_BYTES];
} hmac_auth_rsp_param_stru;

typedef hmac_ap_auth_process_code_enum (*hmac_auth_rsp_fun)(mac_vap_stru *pst_mac_vap,
    hmac_auth_rsp_param_stru *pst_auth_rsp_param, uint8_t *puc_code, hmac_user_stru *hmac_user_sta);

typedef struct tag_hmac_auth_rsp_handle_stru {
    hmac_auth_rsp_param_stru st_auth_rsp_param;
    hmac_auth_rsp_fun st_auth_rsp_fun;
} hmac_auth_rsp_handle_stru;

OAL_STATIC OAL_INLINE void hmac_mgmt_encap_chtxt(uint8_t *puc_frame, uint8_t *puc_chtxt, uint16_t *pus_auth_rsp_len,
    hmac_user_stru *pst_hmac_user_sta)
{
    int32_t l_ret;

    /* Challenge Text Element                  */
    /* --------------------------------------- */
    /* |Element ID | Length | Challenge Text | */
    /* --------------------------------------- */
    /* | 1         |1       |1 - 253         | */
    /* --------------------------------------- */
    puc_frame[MAC_CHALLENGE_OFFSET] = MAC_EID_CHALLENGE;
    puc_frame[MAC_CHTXT_LEN_OFFSET] = WLAN_CHTXT_SIZE;

    /* 将challenge text拷贝到帧体中去 */
    l_ret = memcpy_s(&puc_frame[MAC_CHTXT_PAYLOAD_OFFSET],
        (WLAN_MEM_NETBUF_SIZE2 - ((*pus_auth_rsp_len) + MAC_IE_HDR_LEN)), puc_chtxt, WLAN_CHTXT_SIZE);

    /* 认证帧长度增加Challenge Text Element的长度 */
    *pus_auth_rsp_len += (WLAN_CHTXT_SIZE + MAC_IE_HDR_LEN);

    /* 保存明文的challenge text */
    l_ret += memcpy_s(pst_hmac_user_sta->auc_ch_text, sizeof(pst_hmac_user_sta->auc_ch_text),
        &puc_frame[MAC_CHTXT_PAYLOAD_OFFSET], WLAN_CHTXT_SIZE);
    if (l_ret != EOK) {
        oam_error_log0(0, OAM_SF_ANY, "hmac_mgmt_encap_chtxt::memcpy fail!");
    }
}

uint16_t hmac_encap_auth_rsp(mac_vap_stru *pst_mac_vap, oal_netbuf_stru *pst_auth_rsp, oal_netbuf_stru *pst_auth_req,
    uint8_t *puc_chtxt, uint8_t uc_chtxt_len);

#if defined(_PRE_WLAN_FEATURE_SAE)
oal_err_code_enum hmac_encap_auth_rsp_get_user_idx(mac_vap_stru *pst_mac_vap, uint8_t *puc_mac_addr, uint8_t uc_mac_len,
    uint8_t uc_is_seq1, uint8_t *puc_auth_resend, uint16_t *pus_user_index);
#endif
uint32_t hmac_mgmt_encap_asoc_rsp_ap(mac_vap_stru *mac_ap, const unsigned char *sta_addr,
    uint16_t assoc_id, mac_status_code_enum_uint16 status_code, uint8_t *asoc_rsp, uint16_t type);
void hmac_set_supported_rates_ie_asoc_rsp(mac_user_stru *pst_mac_user, uint8_t *puc_buffer, uint8_t *puc_ie_len);
void hmac_set_exsup_rates_ie_asoc_rsp(mac_user_stru *pst_mac_user, uint8_t *puc_buffer, uint8_t *puc_ie_len);
oal_bool_enum_uint8 hmac_ap_rx_filter_dup_auth_req(hmac_user_stru *hmac_user, uint16_t auth_type,
    uint16_t auth_seq, uint8_t auth_resend);
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* end of hmac_encap_frame_ap.h */
