/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * 功能说明 : hmac_mgmt_ap.c 的头文件
 * 作    者 :
 * 创建日期 : 2013年6月18日
 */

#ifndef HMAC_MGMT_AP_H
#define HMAC_MGMT_AP_H

/* 1 其他头文件包含 */
#include "oal_ext_if.h"
#include "wlan_spec.h"
#include "mac_frame.h"
#include "hmac_vap.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_MGMT_AP_H
/* 2 宏定义 */
/* 3 枚举定义 */
/* 4 全局变量声明 */
/* 5 消息头定义 */
/* 6 消息定义 */
/* 7 STRUCT定义 */
/* 8 UNION定义 */
/* 9 OTHERS定义 */
/* 10 函数声明 */
uint32_t hmac_ap_up_rx_mgmt(hmac_vap_stru *pst_hmac_vap, void *p_param);
uint32_t hmac_ap_up_misc(hmac_vap_stru *pst_hmac_vap, void *p_param);
uint32_t hmac_ap_wait_start_rx_mgmt(hmac_vap_stru *pst_hmac_vap, void *p_param);
uint32_t hmac_ap_wait_start_misc(hmac_vap_stru *pst_hmac_vap, void *p_param);
uint32_t hmac_mgmt_timeout_ap(void *p_param);
void hmac_handle_disconnect_rsp_ap(hmac_vap_stru *pst_hmac_vap,
                                   hmac_user_stru *pst_hmac_user);
oal_bool_enum hmac_user_is_connecting(mac_vap_stru *pst_mac_vap);
uint32_t hmac_ap_clean_bss(hmac_vap_stru *pst_hmac_vap);
uint32_t hmac_ap_send_assoc_rsp(hmac_vap_stru *pst_hmac_vap,
                                hmac_user_stru *pst_hmac_user,
                                const unsigned char *puc_sta_addr,
                                uint8_t uc_mgmt_frm_type,
                                mac_status_code_enum_uint16 *pen_status_code);
uint32_t hmac_ap_save_user_assoc_req(hmac_user_stru *pst_hmac_user, uint8_t *puc_payload,
                                     uint32_t payload_len, uint8_t uc_mgmt_frm_type);
void hmac_handle_connect_rsp_ap(hmac_vap_stru *pst_hmac_vap, hmac_user_stru *pst_hmac_user);
void hmac_mgmt_update_auth_mib(hmac_vap_stru *pst_hmac_vap, oal_netbuf_stru *pst_auth_rsp);
void hmac_mgmt_reset_psm(mac_vap_stru *pst_vap, uint16_t us_user_id);
void hmac_user_sort_op_rates(hmac_user_stru *hmac_user);
void hmac_ap_up_update_legacy_capability(hmac_vap_stru *hmac_vap, hmac_user_stru *hmac_user,
    uint16_t us_cap_info);
uint32_t hmac_mgmt_update_vht_cap(mac_vap_stru *mac_vap, hmac_user_stru *hmac_user,
    hmac_vap_stru *hmac_vap, uint8_t *payload, uint32_t msg_len);
uint16_t hmac_check_rsn_ap(mac_vap_stru *pst_mac_vap, mac_user_stru *mac_user,
    uint8_t *payload, uint32_t msg_len);
uint32_t hmac_mgmt_updata_protocol_cap(mac_vap_stru *mac_vap, hmac_user_stru *hmac_user,
    mac_user_stru *mac_user);
void hmac_mgmt_update_bandwidth_cap(mac_user_stru *mac_user, hmac_vap_stru *hmac_vap,
    mac_vap_stru *mac_vap);
uint32_t hmac_mgmt_update_spatial_stream_cap(hmac_vap_stru *hmac_vap, hmac_user_stru *hmac_user,
    uint8_t *mac_hdr, uint8_t *payload, uint32_t msg_len);
void hmac_ap_up_update_he_cap(hmac_user_stru *hmac_user, mac_vap_stru *mac_vap,
    uint8_t *ie_tmp, uint8_t *payload, uint32_t msg_len);
void hmac_action_category_ba(uint8_t *data, hmac_vap_stru *hmac_vap, hmac_user_stru *hmac_user,
    uint32_t frame_body_len);
#endif /* end of hmac_mgmt_ap.h */
