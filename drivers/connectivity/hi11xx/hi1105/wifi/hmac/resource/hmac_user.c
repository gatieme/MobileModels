/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * 功能说明 : hmac_user.c
 * 作    者 :
 * 创建日期 : 2012年10月19日
 */

/* 1 头文件包含 */
#include "oam_stat_wifi.h"
#include "wlan_chip_i.h"
#include "hmac_user.h"
#include "hmac_main.h"
#include "hmac_tx_amsdu.h"
#include "hmac_protection.h"
#include "hmac_smps.h"
#include "hmac_ext_if.h"
#include "hmac_config.h"
#include "hmac_mgmt_ap.h"
#include "hmac_chan_mgmt.h"
#include "hmac_fsm.h"
#include "hmac_sme_sta.h"
#include "hmac_wapi.h"
#include "hmac_roam_main.h"
#include "hmac_blockack.h"
#include "hmac_scan.h"
#include "hmac_dbac.h"
#include "securec.h"
#ifdef _PRE_WLAN_FEATURE_11AX
#include "mac_ie.h"
#endif
#ifdef _PRE_WLAN_FEATURE_HIEX
#include "hmac_hiex.h"
#endif
#include "hmac_ht_self_cure.h"
#include "hmac_host_tx_data.h"
#include "hmac_tid.h"
#include "host_hal_device.h"
#include "hmac_vowifi.h"
#ifdef _PRE_WLAN_FEATURE_TCP_ACK_BUFFER
#include "hmac_tcp_ack_buf.h"
#endif
#include "hmac_11w.h"
#include "plat_pm_wlan.h"
#include "hmac_tid_ring_switch.h"
#ifdef _PRE_WLAN_CHBA_MGMT
#include "hmac_chba_mgmt.h"
#include "hmac_chba_coex.h"
#include "hmac_chba_user.h"
#include "hmac_chba_channel_sequence.h"
#endif
#ifdef _PRE_WLAN_FEATURE_VSP
#include "hmac_vsp_if.h"
#endif
#ifdef _PRE_WLAN_FEATURE_MCAST_AMPDU
#include "hmac_mcast_ampdu.h"
#endif
#include "hmac_tx_ring_alloc.h"
#include "hmac_dyn_pcie.h"
#ifdef _PRE_WLAN_FEATURE_PWL
#include "hmac_pwl.h"
#endif
#include "hmac_pm.h"
#include "hmac_lp_miracast.h"
#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_USER_C

#define MAX_MCS_3 3   /* 最大mcs map */

typedef struct {
    hmac_user_stru *user;
    oal_spin_lock_stru lock;
} hmac_lut_index_tbl_stru;
hmac_lut_index_tbl_stru g_hmac_lut_index_tbl[HAL_MAX_TX_BA_LUT_SIZE];

void hmac_init_user_lut_index_tbl(void)
{
    uint8_t lut_idx;

    memset_s(g_hmac_lut_index_tbl, sizeof(hmac_lut_index_tbl_stru) * HAL_MAX_TX_BA_LUT_SIZE, 0,
        sizeof(hmac_lut_index_tbl_stru) * HAL_MAX_TX_BA_LUT_SIZE);

    for (lut_idx = 0; lut_idx < HAL_MAX_TX_BA_LUT_SIZE; lut_idx++) {
        oal_spin_lock_init(&g_hmac_lut_index_tbl[lut_idx].lock);
    }
}

hmac_user_stru *hmac_get_user_by_lut_index(uint8_t lut_idx)
{
    hmac_user_stru *hmac_user = NULL;
    hmac_lut_index_tbl_stru *entry = &g_hmac_lut_index_tbl[lut_idx];

    oal_spin_lock(&entry->lock);
    hmac_user = g_hmac_lut_index_tbl[lut_idx].user;
    oal_spin_unlock(&entry->lock);

    return hmac_user;
}

OAL_STATIC void hmac_set_user_lut_index_tbl(hmac_user_stru *hmac_user, uint8_t lut_idx)
{
    hmac_lut_index_tbl_stru *entry = &g_hmac_lut_index_tbl[lut_idx];

    oal_spin_lock(&entry->lock);
    g_hmac_lut_index_tbl[lut_idx].user = hmac_user;
    oal_spin_unlock(&entry->lock);
}

uint32_t hmac_alloc_user_lut_index(hmac_user_stru *hmac_user, mac_chip_stru *mac_chip,
    mac_ap_type_enum_uint16 ap_type)
{
    uint8_t lut_idx;

    if (mac_chip == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* 申请lut index */
    lut_idx = mac_user_get_ra_lut_index(mac_chip->st_lut_table.auc_ra_lut_index_table, 0, WLAN_ASSOC_USER_MAX_NUM);
    if (lut_idx >= mac_chip_get_max_active_user()) {
        oam_warning_log0(0, OAM_SF_ANY, "{hmac_user_add::uc_lut_idx >= WLAN_ASSOC_USER_MAX_NUM.}");
        return OAL_FAIL;
    }

    hmac_user->lut_index = lut_idx;
    hmac_user->en_user_ap_type = ap_type; /* AP类型 */

    hmac_set_user_lut_index_tbl(hmac_user, lut_idx);

    return OAL_SUCC;
}

/*
 * 函 数 名  : mac_res_get_hmac_user_alloc
 * 功能描述  : 获取对应HMAC USER索引的内存,由HMAC层强转为自己的内存解析
 * 1.日    期  : 2015年11月3日
 *   修改内容  : 新生成函数
 */
hmac_user_stru *mac_res_get_hmac_user_alloc(uint16_t us_idx)
{
    hmac_user_stru *pst_hmac_user;

    pst_hmac_user = (hmac_user_stru *)_mac_res_get_hmac_user(us_idx);
    if (pst_hmac_user == NULL) {
        oam_error_log1(0, OAM_SF_UM, "{mac_res_get_hmac_user_init::pst_hmac_user null,user_idx=%d.}", us_idx);
        return NULL;
    }

    /* 重复申请异常,避免影响业务，暂时打印error但正常申请 */
    if (pst_hmac_user->st_user_base_info.uc_is_user_alloced == MAC_USER_ALLOCED) {
        oam_error_log1(0, OAM_SF_UM, "{mac_res_get_hmac_user_init::[E]user has been alloced,user_idx=%d.}", us_idx);
    }

    return pst_hmac_user;
}

/*
 * 函 数 名  : mac_res_get_hmac_user
 * 功能描述  : 获取对应HMAC USER索引的内存,由HMAC层强转为自己的内存解析
 * 1.日    期  : 2015年11月3日
 *   修改内容  : 新生成函数
 */
hmac_user_stru *mac_res_get_hmac_user(uint16_t us_idx)
{
    hmac_user_stru *pst_hmac_user;

    pst_hmac_user = (hmac_user_stru *)_mac_res_get_hmac_user(us_idx);
    if (pst_hmac_user == NULL) {
        return NULL;
    }

    /* 异常: 用户资源已被释放 */
    if (pst_hmac_user->st_user_base_info.uc_is_user_alloced != MAC_USER_ALLOCED) {
        oal_mem_print_funcname(OAL_RET_ADDR);
        /*
         * host侧获取用户时用户已经释放属于正常，返回空指针，
         * 后续调用者查找用户失败，请打印WARNING并直接释放buf，
         * 走其他分支等等
         */
        oam_warning_log1(0, OAM_SF_UM, "{mac_res_get_hmac_user::[E]user has been freed,user_idx=%d.}", us_idx);
        return NULL;
    }

    return pst_hmac_user;
}

/*
 * 函 数 名  : hmac_user_alloc
 * 功能描述  : 创建HMAC用户实体
 * 1.日    期  : 2012年12月11日
 *   修改内容  : 新生成函数
 */
uint32_t hmac_user_alloc(uint16_t *pus_user_idx)
{
    hmac_user_stru *pst_hmac_user = NULL;
    uint32_t rslt;
    uint16_t us_user_idx_temp;

    if (oal_unlikely(pus_user_idx == NULL)) {
        oam_error_log0(0, OAM_SF_UM, "{hmac_user_alloc::pus_user_idx null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* 申请hmac user内存 */
    rslt = mac_res_alloc_hmac_user(&us_user_idx_temp, OAL_OFFSET_OF(hmac_user_stru, st_user_base_info));
    if (rslt != OAL_SUCC) {
        oam_warning_log1(0, OAM_SF_UM, "{hmac_user_alloc::mac_res_alloc_hmac_user failed[%d].}", rslt);
        return rslt;
    }
    pst_hmac_user = mac_res_get_hmac_user_alloc(us_user_idx_temp);
    if (pst_hmac_user == NULL) {
        mac_res_free_mac_user(us_user_idx_temp);
        oam_error_log1(0, OAM_SF_UM, "{hmac_user_alloc::pst_hmac_user null,user_idx=%d.}", us_user_idx_temp);
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* 初始清0 */
    memset_s(pst_hmac_user, sizeof(hmac_user_stru), 0, sizeof(hmac_user_stru));
    /* 标记user资源已被alloc */
    pst_hmac_user->st_user_base_info.uc_is_user_alloced = MAC_USER_ALLOCED;

    *pus_user_idx = us_user_idx_temp;

    return OAL_SUCC;
}

/*
 * 函 数 名  : hmac_user_free
 * 功能描述  : 释放对应HMAC USER的内存
 * 1.日    期  : 2015年11月3日
 *   修改内容  : 新生成函数
 */
uint32_t hmac_user_free(uint16_t us_idx)
{
    hmac_user_stru *pst_hmac_user;
    uint32_t ret;

    pst_hmac_user = mac_res_get_hmac_user(us_idx);
    if (pst_hmac_user == NULL) {
        oam_error_log1(0, OAM_SF_UM, "{hmac_user_free::pst_hmac_user null,user_idx=%d.}", us_idx);
        return OAL_ERR_CODE_PTR_NULL;
    }

    ret = mac_res_free_mac_user(us_idx);
    if (ret == OAL_SUCC) {
        /* 清除alloc标志 */
        pst_hmac_user->st_user_base_info.uc_is_user_alloced = MAC_USER_FREED;
    }

    return ret;
}

/*
 * 函 数 名  : hmac_user_free_asoc_req_ie
 * 功能描述  : 输入参数  : 无
 * 1.日    期  : 2013年9月26日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_user_free_asoc_req_ie(uint16_t us_idx)
{
    hmac_user_stru *pst_hmac_user;

    pst_hmac_user = (hmac_user_stru *)mac_res_get_hmac_user(us_idx);
    if (pst_hmac_user == NULL) {
        oam_warning_log1(0, OAM_SF_ASSOC, "{hmac_vap_free_asoc_req_ie::pst_hmac_user[%d] null.}", us_idx);
        return OAL_ERR_CODE_PTR_NULL;
    }

    if (pst_hmac_user->puc_assoc_req_ie_buff != NULL) {
        oal_mem_free_m(pst_hmac_user->puc_assoc_req_ie_buff, OAL_TRUE);
        pst_hmac_user->puc_assoc_req_ie_buff = NULL;
        pst_hmac_user->assoc_req_ie_len = 0;
    } else {
        pst_hmac_user->assoc_req_ie_len = 0;
    }
    return OAL_SUCC;
}

/*
 * 函 数 名  : hmac_user_set_asoc_req_ie
 * 功能描述  : 输入参数  : 无
 * 1.日    期  : 2016年7月11日
 *   作    者  : wifi
 *   修改内容  : 设置user的assoc
 */
uint32_t hmac_user_set_asoc_req_ie(hmac_user_stru *hmac_user,
                                   uint8_t *payload, uint32_t payload_len, uint8_t reass_flag)
{
    if (reass_flag) {
        hmac_user_clear_defrag_res(hmac_user);
    }
#ifdef _PRE_WINDOWS_SUPPORT
    /* 在Windows系统中，无论是assoc req还是reassoc,都要将所有的Fixed Parameters部分上报给OS */
    hmac_user->puc_assoc_req_ie_buff = oal_mem_alloc_m(OAL_MEM_POOL_ID_LOCAL, (uint16_t)payload_len, OAL_TRUE);
    if (hmac_user->puc_assoc_req_ie_buff == NULL) {
        oam_error_log1(hmac_user->st_user_base_info.uc_vap_id, OAM_SF_ASSOC,
            "{hmac_user_set_asoc_req_ie :: Alloc %u bytes failed for assoc_req_ie_buff.}", (uint16_t)payload_len);
        hmac_user->assoc_req_ie_len = 0;
        return OAL_FAIL;
    }
    if (memcpy_s(hmac_user->puc_assoc_req_ie_buff, payload_len, payload, payload_len) != EOK) {
        oal_mem_free_m(hmac_user->puc_assoc_req_ie_buff, OAL_TRUE);
        oam_error_log0(0, OAM_SF_ASSOC, "hmac_user_set_asoc_req_ie::memcpy fail!");
        return OAL_FAIL;
    }
#else
    /* 重关联比关联请求帧头多了AP的  */
    payload_len -= ((reass_flag == OAL_TRUE) ? WLAN_MAC_ADDR_LEN : 0);
    hmac_user->puc_assoc_req_ie_buff = oal_mem_alloc_m(OAL_MEM_POOL_ID_LOCAL, (uint16_t)payload_len, OAL_TRUE);
    if (hmac_user->puc_assoc_req_ie_buff == NULL) {
        oam_error_log1(hmac_user->st_user_base_info.uc_vap_id, OAM_SF_ASSOC,
            "{hmac_user_set_asoc_req_ie :: Alloc %u bytes failed for assoc_req_ie_buff.}", (uint16_t)payload_len);
        hmac_user->assoc_req_ie_len = 0;
        return OAL_FAIL;
    }
    if (memcpy_s(hmac_user->puc_assoc_req_ie_buff, payload_len,
                 payload + ((reass_flag == OAL_TRUE) ? WLAN_MAC_ADDR_LEN : 0),
                 payload_len) != EOK) {
        oal_mem_free_m(hmac_user->puc_assoc_req_ie_buff, OAL_TRUE);
        oam_error_log0(0, OAM_SF_ASSOC, "hmac_user_set_asoc_req_ie::memcpy fail!");
        return OAL_FAIL;
    }
#endif
    hmac_user->assoc_req_ie_len = payload_len;
    return OAL_SUCC;
}


/*
 * 功能描述 : 初始化hmac user各tid
 * 1.日    期 : 2020年4月26日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
OAL_STATIC void hmac_user_tid_init(hmac_user_stru *hmac_user)
{
    uint32_t tid;
    hmac_ba_tx_stru *tx_ba = NULL;

    hmac_tid_sche_list_dump(HMAC_TID_SCHE_LIST_BEFORE_ADD_USER);

    for (tid = 0; tid < WLAN_TID_MAX_NUM; tid++) {
        hmac_user->ast_tid_info[tid].uc_tid_no = (uint8_t)tid;
        hmac_user->ast_tid_info[tid].us_hmac_user_idx = hmac_user->st_user_base_info.us_assoc_id;

        /* 初始化ba rx操作句柄 */
        hmac_user->ast_tid_info[tid].pst_ba_rx_info = NULL;
        oal_spin_lock_init(&(hmac_user->ast_tid_info[tid].st_ba_tx_info.st_ba_status_lock));
        hmac_user->ast_tid_info[tid].st_ba_tx_info.en_ba_status = DMAC_BA_INIT;
        hmac_user->ast_tid_info[tid].st_ba_tx_info.uc_addba_attemps = 0;
        hmac_user->ast_tid_info[tid].st_ba_tx_info.uc_dialog_token = 0;
        hmac_user->ast_tid_info[tid].st_ba_tx_info.uc_ba_policy = 0;
        hmac_user->ast_tid_info[tid].en_ba_handle_tx_enable = OAL_TRUE;
        hmac_user->ast_tid_info[tid].en_ba_handle_rx_enable = OAL_TRUE;

        /* addba req超时处理函数入参填写 */
        tx_ba = &hmac_user->ast_tid_info[tid].st_ba_tx_info;
        tx_ba->st_alarm_data.pst_ba = (void *)tx_ba;
        tx_ba->st_alarm_data.uc_tid = tid;
        tx_ba->st_alarm_data.us_mac_user_idx = hmac_user->st_user_base_info.us_assoc_id;
        tx_ba->st_alarm_data.uc_vap_id = hmac_user->st_user_base_info.uc_vap_id;

        /* 初始化用户关联请求帧参数 */
        hmac_user->puc_assoc_req_ie_buff = NULL;
        hmac_user->assoc_req_ie_len = 0;

        /* 初始化上一帧的seq num, 防止当前帧seq num为0时被误过滤 */
        hmac_user->qos_last_seq_frag_num[tid] = 0xffff;

        hmac_ring_tx_init(hmac_user, tid);

        oal_netbuf_list_head_init(&(hmac_user->device_rx_list[tid]));

        oal_spin_lock_init(&(hmac_user->ast_tid_info[tid].st_ba_timer_lock));
    }

    hmac_tid_sche_list_dump(HMAC_TID_SCHE_LIST_AFTER_ADD_USER);
}

#ifdef _PRE_WLAN_FEATURE_MCAST_AMPDU
/*
 * 函 数 名  : hmac_mcast_ampdu_rx_ba_init
 * 功能描述  : 初始化聚合组播 rx_ba 信息
 * 1.日    期  : 2020年1月18日
 *   作    者  : wifi7
 *   修改内容  : 新生成函数
 */
void hmac_mcast_ampdu_rx_ba_init(hmac_user_stru *hmac_user, uint8_t tid)
{
    hmac_rx_buf_stru *rx_buff = NULL;
    uint16_t reorder_index;
    hmac_ba_rx_stru *ba_rx_stru = NULL;
    /* 申请内存 */
    ba_rx_stru = (hmac_ba_rx_stru *)oal_mem_alloc_m(OAL_MEM_POOL_ID_LOCAL, (uint16_t)sizeof(hmac_ba_rx_stru), OAL_TRUE);
    if (ba_rx_stru == NULL) {
        oam_error_log1(0, OAM_SF_BA,
            "{hmac_mcast_ampdu_rx_ba_init::alloc fail.tid[%d],baw[%d]}", tid);
        return;
    }

    hmac_user->ast_tid_info[tid].pst_ba_rx_info = ba_rx_stru;
    /* Ba会话参数初始化 */
    ba_rx_stru->en_ba_status = DMAC_BA_COMPLETE;
    ba_rx_stru->uc_ba_policy = MAC_BA_POLICY_IMMEDIATE;
    /* 初始化接收窗口 */
    ba_rx_stru->us_baw_start = 0;
    ba_rx_stru->us_baw_size = WLAN_AMPDU_RX_BUFFER_SIZE;

    /* 初始化reorder队列 */
    for (reorder_index = 0; reorder_index < WLAN_AMPDU_RX_HE_BUFFER_SIZE; reorder_index++) {
        rx_buff = hmac_get_ba_rx_dhl(ba_rx_stru, reorder_index);
        rx_buff->in_use = 0;
        rx_buff->us_seq_num = 0;
        rx_buff->uc_num_buf = 0;
        oal_netbuf_list_head_init(&(rx_buff->st_netbuf_head));
    }

    /* Ba会话参数初始化 */
    ba_rx_stru->us_baw_end = mac_ba_seqno_add(ba_rx_stru->us_baw_start, (ba_rx_stru->us_baw_size - 1));
    ba_rx_stru->us_baw_tail = mac_ba_seqno_sub(ba_rx_stru->us_baw_start, 1);
    ba_rx_stru->us_baw_head = mac_ba_seqno_sub(ba_rx_stru->us_baw_start, HMAC_BA_BMP_SIZE);
    ba_rx_stru->uc_mpdu_cnt = 0;
    ba_rx_stru->en_is_ba = OAL_TRUE;  // Ba session is processing
    ba_rx_stru->en_amsdu_supp = OAL_FALSE;
    ba_rx_stru->en_back_var = MAC_BACK_COMPRESSED;
    ba_rx_stru->puc_transmit_addr = hmac_user->st_user_base_info.auc_user_mac_addr;

    /* 初始化定时器资源 */
    ba_rx_stru->st_alarm_data.pst_ba = ba_rx_stru;
    ba_rx_stru->st_alarm_data.us_mac_user_idx = hmac_user->st_user_base_info.us_assoc_id;
    ba_rx_stru->st_alarm_data.uc_vap_id = hmac_user->st_user_base_info.uc_vap_id;
    ba_rx_stru->st_alarm_data.uc_tid = tid;
    ba_rx_stru->st_alarm_data.us_timeout_times = 0;
    ba_rx_stru->st_alarm_data.en_direction = MAC_RECIPIENT_DELBA;
    ba_rx_stru->en_timer_triggered = OAL_FALSE;

    oal_spin_lock_init(&ba_rx_stru->st_ba_lock);
}
#endif

/*
 * 函 数 名  : hmac_user_init
 * 功能描述  : 初始化HMAC 用户
 * 1.日    期  : 2012年10月19日
 *   修改内容  : 新生成函数
 */
uint32_t hmac_user_init(hmac_user_stru *hmac_user)
{
#ifdef _PRE_WLAN_FEATURE_EDCA_OPT_AP
    uint8_t uc_ac_idx;
    uint8_t uc_data_idx;
#endif
    hmac_vap_stru *hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(hmac_user->st_user_base_info.uc_vap_id);

    /* 初始化tid信息 */
    hmac_user_tid_init(hmac_user);
    if (hmac_vap == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }
#ifdef _PRE_WLAN_FEATURE_MCAST_AMPDU
    /* 初始化聚合组播 rx_ba 信息 */
    if ((mac_get_mcast_ampdu_switch() == OAL_TRUE) &&
        (hmac_vap->st_vap_base_info.en_vap_mode == WLAN_VAP_MODE_BSS_STA)) {
        wlan_chip_mcast_ampdu_rx_ba_init(hmac_user, WLAN_TIDNO_BCAST);
    }
#endif

#ifdef _PRE_WLAN_FEATURE_EDCA_OPT_AP
    for (uc_ac_idx = 0; uc_ac_idx < WLAN_WME_AC_BUTT; uc_ac_idx++) {
        for (uc_data_idx = 0; uc_data_idx < WLAN_TXRX_DATA_BUTT; uc_data_idx++) {
            hmac_user->aaul_txrx_data_stat[uc_ac_idx][uc_data_idx] = 0;
        }
    }
#endif

    hmac_user->pst_defrag_netbuf = NULL;
    hmac_user->user_hisi = OAL_FALSE;
    hmac_user->en_user_bw_limit = OAL_FALSE;
#ifdef _PRE_WLAN_FEATURE_PMF
    hmac_user->st_sa_query_info.sa_query_count = 0;
    hmac_user->st_sa_query_info.sa_query_start_time = 0;
    hmac_user->st_sa_query_info.peer_sta_keep_silent_time = 0;
    hmac_user->st_sa_query_info.rx_sa_req = OAL_FALSE;
#endif
    memset_s(&hmac_user->st_defrag_timer, sizeof(frw_timeout_stru), 0, sizeof(frw_timeout_stru));
    hmac_user->rx_pkt_drop = 0;

    /* 清除usr统计信息 */
    oam_stats_clear_user_stat_info(hmac_user->st_user_base_info.us_assoc_id);

    hmac_user->first_add_time = (uint32_t)oal_time_get_stamp_ms();
    hmac_user->us_clear_judge_count = 0;
    hmac_user->assoc_err_code = 0; /* 去关联 error code */
    hmac_user->assoc_ap_up_tx_auth_req = OAL_FALSE;
    oal_atomic_set(&hmac_user->netdev_tx_suspend, OAL_FALSE);
    hmac_user->attack_mgmt.ap_rx_auth_start_tsf = 0;
#ifdef _PRE_WLAN_FEATURE_TCP_ACK_BUFFER
    hmac_tcp_ack_buf_init_user(hmac_user);
#endif

    return OAL_SUCC;
}

OAL_STATIC uint32_t hmac_user_set__num_spatial_stream_vht_capable(mac_user_stru *pst_mac_user,
    mac_vht_hdl_stru *pst_mac_vht_hdl, wlan_nss_enum_uint8 *pen_user_num_spatial_stream)
{
    if (pst_mac_vht_hdl->st_rx_max_mcs_map.us_max_mcs_4ss != MAX_MCS_3) {
        *pen_user_num_spatial_stream = WLAN_FOUR_NSS;
    } else if (pst_mac_vht_hdl->st_rx_max_mcs_map.us_max_mcs_3ss != MAX_MCS_3) {
        *pen_user_num_spatial_stream = WLAN_TRIPLE_NSS;
    } else if (pst_mac_vht_hdl->st_rx_max_mcs_map.us_max_mcs_2ss != MAX_MCS_3) {
        *pen_user_num_spatial_stream = WLAN_DOUBLE_NSS;
    } else if (pst_mac_vht_hdl->st_rx_max_mcs_map.us_max_mcs_1ss != MAX_MCS_3) {
        *pen_user_num_spatial_stream = WLAN_SINGLE_NSS;
    } else {
        oam_warning_log0(pst_mac_user->uc_vap_id, OAM_SF_ANY,
                         "{hmac_user_set_avail_num_space_stream::invalid vht nss.}");

        return OAL_FAIL;
    }

    return OAL_SUCC;
}

/*
 * 函 数 名  : hmac_user_set_avail_num_space_stream
 * 功能描述  : 获取用户和VAP公共可用的空间流数
 * 1.日    期  : 2013年10月16日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_user_set_avail_num_space_stream(mac_user_stru *pst_mac_user, wlan_nss_enum_uint8 en_vap_nss)
{
    mac_user_ht_hdl_stru *pst_mac_ht_hdl;
    mac_vht_hdl_stru *pst_mac_vht_hdl;
#ifdef _PRE_WLAN_FEATURE_11AX
    mac_he_hdl_stru *pst_mac_he_hdl = MAC_USER_HE_HDL_STRU(pst_mac_user);
#endif
    wlan_nss_enum_uint8 en_user_num_spatial_stream = 0;
    uint32_t ret = OAL_SUCC;

    /* AP(STA)为legacy设备，只支持1根天线，不需要再判断天线个数 */
    /* 获取HT和VHT结构体指针 */
    pst_mac_ht_hdl = &(pst_mac_user->st_ht_hdl);
    pst_mac_vht_hdl = &(pst_mac_user->st_vht_hdl);
#ifdef _PRE_WLAN_FEATURE_11AX
    if (g_wlan_spec_cfg->feature_11ax_is_open && pst_mac_he_hdl->en_he_capable == OAL_TRUE) {
        ret = mac_ie_from_he_cap_get_nss(pst_mac_he_hdl, &en_user_num_spatial_stream);
    } else if (pst_mac_vht_hdl->en_vht_capable == OAL_TRUE) {
#else // ut 11AX宏未打开，待后续修改
    if (pst_mac_vht_hdl->en_vht_capable == OAL_TRUE) {
#endif
        // 降低圈复杂度
        if (hmac_user_set__num_spatial_stream_vht_capable(pst_mac_user, pst_mac_vht_hdl,
            &en_user_num_spatial_stream) != OAL_SUCC) {
            ret = OAL_FAIL;
        }
    } else if (pst_mac_ht_hdl->en_ht_capable == OAL_TRUE) {
        if (pst_mac_ht_hdl->uc_rx_mcs_bitmask[BYTE_OFFSET_3] > 0) {
            en_user_num_spatial_stream = WLAN_FOUR_NSS;
        } else if (pst_mac_ht_hdl->uc_rx_mcs_bitmask[BYTE_OFFSET_2] > 0) {
            en_user_num_spatial_stream = WLAN_TRIPLE_NSS;
        } else if (pst_mac_ht_hdl->uc_rx_mcs_bitmask[BYTE_OFFSET_1] > 0) {
            en_user_num_spatial_stream = WLAN_DOUBLE_NSS;
        } else if (pst_mac_ht_hdl->uc_rx_mcs_bitmask[BYTE_OFFSET_0] > 0) {
            en_user_num_spatial_stream = WLAN_SINGLE_NSS;
        } else {
            oam_warning_log0(pst_mac_user->uc_vap_id, OAM_SF_ANY,
                             "{hmac_user_set_avail_num_space_stream::invalid ht nss.}");

            ret = OAL_FAIL;
        }
    } else {
        en_user_num_spatial_stream = WLAN_SINGLE_NSS;
    }

    /* 赋值给用户结构体变量 */
    mac_user_set_num_spatial_stream(pst_mac_user, en_user_num_spatial_stream);
    mac_user_set_avail_num_spatial_stream(pst_mac_user,
                                          oal_min(pst_mac_user->en_user_max_cap_nss, en_vap_nss));
    mac_user_set_smps_opmode_notify_nss(pst_mac_user, WLAN_NSS_LIMIT);

    return ret;
}

/*
 * 函 数 名  : hmac_user_calculate_num_spatial_stream
 * 功能描述  : 计算user流数
 * 1.日    期  : 2019年4月8日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint8_t hmac_user_calculate_num_spatial_stream(wlan_nss_enum_uint8 *puc_nss1, wlan_nss_enum_uint8 *puc_nss2)
{
    uint8_t uc_nss_valid_flag = OAL_TRUE;

    switch (*puc_nss1) {
        case 0: /* 0流表示不支持 */
            *puc_nss1 = WLAN_NSS_LIMIT;
            break;

        case 1: /* 1流的宏定义WLAN_SINGLE_NSS(值是0) */
            *puc_nss1 = WLAN_SINGLE_NSS;
            break;

        case 2: /* 2流的宏定义WLAN_DOUBLE_NSS(值是1) */
            *puc_nss1 = WLAN_DOUBLE_NSS;
            break;

        default:
            oam_error_log1(0, OAM_SF_ANY, "{hmac_user_calculate_num_spatial_stream::error puc_nss1[%d]}", *puc_nss1);
            uc_nss_valid_flag = OAL_FALSE;
            break;
    }

    switch (*puc_nss2) {
        case 0: /* 0流表示不支持 */
            *puc_nss2 = WLAN_NSS_LIMIT;
            break;

        case 1: /* 1流的宏定义WLAN_SINGLE_NSS(值是0) */
            *puc_nss2 = WLAN_SINGLE_NSS;
            break;

        case 2: /* 2流的宏定义WLAN_DOUBLE_NSS(值是1) */
            *puc_nss2 = WLAN_DOUBLE_NSS;
            break;

        case 3: /* 3流的宏定义WLAN_DOUBLE_NSS(值是2) */
            *puc_nss2 = WLAN_TRIPLE_NSS;
            break;

        default:
            oam_error_log1(0, OAM_SF_ANY, "{hmac_user_calculate_num_spatial_stream::error puc_nss2[%d]}", *puc_nss2);
            uc_nss_valid_flag = OAL_FALSE;
            break;
    }
    return uc_nss_valid_flag;
}

/*
 * 函 数 名  : hmac_user_set_num_spatial_stream_160M
 * 功能描述  : 设置160M带宽下的流数
 * 1.日    期  : 2019年4月8日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void hmac_user_set_num_spatial_stream_160M(mac_user_stru *pst_mac_user)
{
    mac_vht_hdl_stru *pst_mac_vht_hdl = NULL;
    /* 计算结果是实际流数，取值 0 或 1 或 2 */
    wlan_nss_enum_uint8 en_user_num_spatial_stream1 = ((pst_mac_user->en_user_max_cap_nss + 1) >> 1);
    /* 计算结果是实际流数，取值 0 或 1 或 2 或 3  */
    wlan_nss_enum_uint8 en_user_num_spatial_stream2 = (((pst_mac_user->en_user_max_cap_nss + 1) * 3) >> 2);
    wlan_nss_enum_uint8 en_user_num_spatial_stream = WLAN_NSS_LIMIT;
    uint8_t uc_ret;

    uc_ret = hmac_user_calculate_num_spatial_stream(&en_user_num_spatial_stream1, &en_user_num_spatial_stream2);
    if (uc_ret == OAL_FALSE) {
        oam_error_log0(0, OAM_SF_ANY,
                       "{hmac_user_set_num_spatial_stream_160M::hmac_user_calculate_num_spatial_stream error!}");
        return;
    }

    /* 获取HT和VHT结构体指针 */
    pst_mac_vht_hdl = &(pst_mac_user->st_vht_hdl);

    if (pst_mac_vht_hdl->bit_supported_channel_width > WLAN_MIB_VHT_SUPP_WIDTH_80) {
        en_user_num_spatial_stream = pst_mac_user->en_user_max_cap_nss;
    } else {
        switch (pst_mac_vht_hdl->bit_extend_nss_bw_supp) {
            case WLAN_EXTEND_NSS_BW_SUPP0:
                en_user_num_spatial_stream = WLAN_NSS_LIMIT;
                break;

            case WLAN_EXTEND_NSS_BW_SUPP1:
            case WLAN_EXTEND_NSS_BW_SUPP2:
                en_user_num_spatial_stream = en_user_num_spatial_stream1;
                break;

            case WLAN_EXTEND_NSS_BW_SUPP3:
                en_user_num_spatial_stream = en_user_num_spatial_stream2;
                break;

            default:
                oam_warning_log1(0, OAM_SF_ANY,
                                 "{hmac_user_set_num_spatial_stream_160M::error extend_nss_bw_supp[%d]}",
                                 pst_mac_vht_hdl->bit_extend_nss_bw_supp);
                break;
        }
    }
    mac_user_set_num_spatial_stream_160M(pst_mac_user, en_user_num_spatial_stream);
}

/*
 * 函 数 名  : hmac_compability_ap_tpye_identify_for_btcoex
 * 功能描述  : btcoex兼容性问题AP识别
 * 1.日    期  : 2019年3月12日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void hmac_compability_ap_tpye_identify_for_btcoex(mac_vap_stru *pst_mac_vap,
                                                  mac_bss_dscr_stru *pst_bss_dscr, uint8_t *puc_mac_addr,
                                                  mac_ap_type_enum_uint16 *pen_ap_type)
{
    wlan_nss_enum_uint8 en_support_max_nss = WLAN_SINGLE_NSS;
    if (pst_bss_dscr == NULL) {
        oam_warning_log0(pst_mac_vap->uc_vap_id, OAM_SF_COEX,
            "hmac_compability_ap_tpye_identify_for_btcoex:bss_dscr null!");
        return;
    }

    /* 一级生效，直接置self-cts,苹果路由器有其他方案，这里暂时不开 */
    /* 二级生效，需要考虑mac地址约束 */
    if (pst_bss_dscr->en_btcoex_blacklist_chip_oui & MAC_BTCOEX_BLACKLIST_LEV0) {
        /* 关联ap识别: AP OUI + chip OUI + 双流 + 2G 需要dmac侧刷新ps机制时one pkt帧发送类型 */
        if (mac_is_dlink_ap(puc_mac_addr) || mac_is_haier_ap(puc_mac_addr) ||
            mac_is_fast_ap(puc_mac_addr) || mac_is_tplink_845_ap(puc_mac_addr)) {
#ifdef _PRE_WLAN_FEATURE_M2S
            en_support_max_nss = pst_bss_dscr->en_support_max_nss;
#endif
            if (hmac_ap_is_bw_2g_double_nss(en_support_max_nss, pst_mac_vap)) {
                oam_warning_log0(pst_mac_vap->uc_vap_id, OAM_SF_COEX,
                    "hmac_compability_ap_tpye_identify_for_btcoex: lev0 btcoex ps self-cts blacklist!");
                *pen_ap_type |= MAC_AP_TYPE_BTCOEX_PS_BLACKLIST;
            }
        } else if (mac_is_jcg_ap(puc_mac_addr)) {
            /* JCG路由器为了兼容aptxHD和660,需要关闭cts回复功能 */
            oam_warning_log0(pst_mac_vap->uc_vap_id, OAM_SF_COEX,
                "hmac_compability_ap_tpye_identify_for_btcoex: lev0 JCG btcoex disable cts blacklist!");
            *pen_ap_type |= MAC_AP_TYPE_BTCOEX_DISABLE_CTS;
        } else if (mac_is_feixun_k3(puc_mac_addr)) {
            /*  斐讯k3,需要关闭cts回复功能 */
            oam_warning_log0(pst_mac_vap->uc_vap_id, OAM_SF_COEX,
                "hmac_compability_ap_tpye_identify_for_btcoex: lev0 k3 btcoex ps self-cts blacklist!");
            *pen_ap_type |= MAC_AP_TYPE_BTCOEX_PS_BLACKLIST;
        } else if (mac_is_fast_fw450r(puc_mac_addr)) {
            /*  Fast FW450R需要降低SCO部分BT帧的优先级 */
            oam_warning_log0(pst_mac_vap->uc_vap_id, OAM_SF_COEX,
                "hmac_compability_ap_tpye_identify_for_btcoex: lev0 btcoex sco part middle priority!");
            *pen_ap_type |= MAC_AP_TYPE_BTCOEX_SCO_MIDDLE_PRIORITY;
        }
#ifdef _PRE_WLAN_FEATURE_11AX
        if (g_wlan_spec_cfg->feature_11ax_is_open) {
            if (mac_is_ax3000(puc_mac_addr) && (pst_mac_vap->en_protocol == WLAN_HE_MODE)) {
                /*  AX3000关联AX模式的时候不进20dbm */
                oam_warning_log0(pst_mac_vap->uc_vap_id, OAM_SF_COEX,
                    "hmac_compability_ap_tpye_identify_for_btcoex: lev0 btcoex 20dbm blacklist!!");
                *pen_ap_type |= MAC_AP_TYPE_BTCOEX_20DBM_BLACKLIST;
            }
        }
#endif
        /*  TL-WDR2041N/NetGearR2000/WS851需要降低SCO重传帧优先级
            这里使用IF判断是因为WS851与上面的TPINK_845判断条件一致,使用else if会走不进来
        */
        if (mac_is_sco_retry_blacklist(puc_mac_addr)) {
            oam_warning_log0(pst_mac_vap->uc_vap_id, OAM_SF_COEX,
                "hmac_compability_ap_tpye_identify_for_btcoex: lev0 btcoex sco retry middle priority!");
            *pen_ap_type |= MAC_AP_TYPE_BTCOEX_SCO_RETRY_MIDDLE_PRIORITY;
        }
    }
}

OAL_STATIC void hmac_set_rx_stbc_cap(mac_vap_stru *pst_mac_vap, mac_bss_dscr_stru *pst_bss_dscr)
{
#ifdef _PRE_WLAN_FEATURE_11AX
    if (g_wlan_spec_cfg->feature_11ax_is_open) {
        pst_mac_vap->st_cap_flag.bit_rx_stbc = OAL_TRUE;
        if (mac_is_huaweite_ap(pst_bss_dscr)) {
            oam_warning_log0(pst_mac_vap->uc_vap_id, 0, "hmac_get_ap_type: rx stbc blacklist!");
            pst_mac_vap->st_cap_flag.bit_rx_stbc = OAL_FALSE;
        }
    }
#endif
}

/*
 * 功能描述  : 兼容性问题AP识别是否在ddc白名单
 * 1.日    期  : 2020年11月3日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC mac_ap_type_enum_uint16 hmac_get_ap_type_is_in_ddc_white_list(mac_bss_dscr_stru *bss_dscr,
    mac_vap_stru *mac_vap, uint8_t *mac_addr, wlan_nss_enum_uint8 support_max_nss)
{
    mac_ap_type_enum_uint16 ap_type = 0;

    if (bss_dscr->en_atheros_chip_oui == OAL_TRUE) {
        if ((mac_is_netgear_wndr_ap(mac_addr) && support_max_nss == WLAN_DOUBLE_NSS) ||
            ((mac_is_belkin_ap(mac_addr) || mac_is_trendnet_ap(mac_addr)) &&
            (support_max_nss == WLAN_TRIPLE_NSS) && (mac_vap->st_channel.en_band == WLAN_BAND_2G))) {
            oam_warning_log0(mac_vap->uc_vap_id, OAM_SF_ANY,
                "hmac_get_ap_type_is_in_ddc_white_list::is in ddc whitelist!");
            ap_type |= MAC_AP_TYPE_DDC_WHITELIST;
        }
    }

    return ap_type;
}
/*
 * 函 数 名  : hmac_compability_ap_tpye_identify_for_m2s
 * 功能描述  : 兼容性问题AP识别
 * 1.日    期  : 2021年6月10日
 *   作    者  :
 *   修改内容  : 新生成函数
 */
oal_bool_enum_uint8 hmac_compability_ap_tpye_identify_for_m2s(mac_vap_stru *mac_vap, mac_bss_dscr_stru *bss_dscr,
    uint8_t *mac_addr)
{
    /* 后续不能切siso: 360随身wifi;2G下的TP-LINK7300;11ax下的NETGEAR_RAX20; */
    if (mac_is_360_ap0(mac_addr) || mac_is_360_ap1(mac_addr) || mac_is_360_ap2(mac_addr) ||
        (mac_is_tplink_7300(bss_dscr) && (mac_vap->st_channel.en_band == WLAN_BAND_2G))) {
        return OAL_TRUE;
    }
#ifdef _PRE_WLAN_FEATURE_11AX
    /* NETGEAR_RAX20关联AX模式的时候后续不能切siso */
    if (g_wlan_spec_cfg->feature_11ax_is_open &&
        mac_is_netgear_rax20(bss_dscr) && (mac_vap->en_protocol == WLAN_HE_MODE)) {
        return OAL_TRUE;
    }
#endif
    return OAL_FALSE;
}

static mac_ap_type_enum hmac_compability_ap_type_identify_for_keepalive(mac_bss_dscr_stru *bss_dscr, uint8_t *mac_addr)
{
    if (mac_is_fiberhome(mac_addr) == OAL_TRUE && bss_dscr->keepalive_compatible_chip_oui == OAL_TRUE) {
        return MAC_AP_TYPE_KEEPALIVE_COMPATIBLE;
    } else {
        return 0;
    }
}

/*
 * 函 数 名  : hmac_compability_ap_tpye_identify
 * 功能描述  : 兼容性问题AP识别
 * 1.日    期  : 2015年10月7日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
mac_ap_type_enum_uint16 hmac_identify_type_of_ap_with_compatibility_issues(mac_vap_stru *pst_mac_vap,
    uint8_t *puc_mac_addr)
{
    mac_ap_type_enum_uint16 en_ap_type = 0;

#if defined(_PRE_WLAN_MP13_DDC_BUGFIX)
    wlan_nss_enum_uint8 en_support_max_nss = WLAN_SINGLE_NSS;
#endif

    mac_bss_dscr_stru *pst_bss_dscr = NULL;

    pst_bss_dscr = (mac_bss_dscr_stru *)hmac_scan_get_scanned_bss_by_bssid(pst_mac_vap, puc_mac_addr);

    if (mac_is_golden_ap(puc_mac_addr)) {
        en_ap_type |= MAC_AP_TYPE_GOLDENAP;
    }

    if (pst_bss_dscr != NULL) {
#ifdef _PRE_WLAN_MP13_DDC_BUGFIX
        /* DDC白名单: AP OUI + chip OUI + 三流 + 2G */
        if (mac_is_belkin_ap(puc_mac_addr) || mac_is_trendnet_ap(puc_mac_addr) ||
            mac_is_netgear_wndr_ap(puc_mac_addr)) {
#ifdef _PRE_WLAN_FEATURE_M2S
            en_support_max_nss = pst_bss_dscr->en_support_max_nss;
#endif
            en_ap_type |= hmac_get_ap_type_is_in_ddc_white_list(pst_bss_dscr, pst_mac_vap, puc_mac_addr,
                en_support_max_nss);
        }
#endif

        hmac_compability_ap_tpye_identify_for_btcoex(pst_mac_vap, pst_bss_dscr, puc_mac_addr, &en_ap_type);

#ifdef _PRE_WLAN_FEATURE_M2S
        if (hmac_compability_ap_tpye_identify_for_m2s(pst_mac_vap, pst_bss_dscr, puc_mac_addr) == OAL_TRUE) {
            oam_warning_log0(pst_mac_vap->uc_vap_id, OAM_SF_M2S,
                "hmac_compability_ap_tpye_identify_for_m2s: m2s blacklist!");
            en_ap_type |= MAC_AP_TYPE_M2S;
        }
#endif

        /* 关闭时候识别斐讯k3，不能进行漫游 */
        if (mac_is_feixun_k3(puc_mac_addr)) {
            if (pst_bss_dscr->en_roam_blacklist_chip_oui == OAL_TRUE) {
                oam_warning_log0(pst_mac_vap->uc_vap_id, 0, "hmac_compability_ap_tpye_identify: roam blacklist!");
                en_ap_type |= MAC_AP_TYPE_ROAM;
            }
        }

        /* 识别HUAWEI ，不支持rx stbc */
        hmac_set_rx_stbc_cap(pst_mac_vap, pst_bss_dscr);

        /* 更新是否有keepalive兼容性 */
        en_ap_type |= hmac_compability_ap_type_identify_for_keepalive(pst_bss_dscr, puc_mac_addr);

        pst_mac_vap->bit_ap_chip_oui = pst_bss_dscr->chip_oui;

        if ((pst_bss_dscr->en_atheros_chip_oui == OAL_TRUE) && (mac_is_linksys_ea8500_ap(puc_mac_addr))) {
            oam_warning_log0(pst_mac_vap->uc_vap_id, OAM_SF_ROAM,
                             "hmac_compability_ap_tpye_identify: aggr blacklist!");
            en_ap_type |= MAC_AP_TYPE_AGGR_BLACKLIST;
        }
    }

    /* 打桩mp12逻辑 */
    en_ap_type |= MAC_AP_TYPE_NORMAL;

    return en_ap_type;
}

/*
 * 函 数 名  : hmac_dbdc_need_kick_user
 * 功能描述  : dbdc场景下，一路入网，另外一路踢用户的场景下，需要优先踢入网用户
 * 1.日    期  : 2018年8月16日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void hmac_dbdc_need_kick_user(mac_vap_stru *pst_mac_vap, mac_device_stru *pst_mac_dev)
{
    uint8_t uc_vap_idx;
    mac_vap_stru *pst_another_vap = NULL;
    mac_cfg_kick_user_param_stru st_kick_user_param;
    uint8_t auc_mac_addr[WLAN_MAC_ADDR_LEN] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };

    if (pst_mac_dev->en_dbdc_running == OAL_FALSE) {
        return;
    }

    /* DBDC状态下，优先踢掉处于关联状态的用户 */
    for (uc_vap_idx = 0; uc_vap_idx < pst_mac_dev->uc_vap_num; uc_vap_idx++) {
        pst_another_vap = mac_res_get_mac_vap(pst_mac_dev->auc_vap_id[uc_vap_idx]);
        if (pst_another_vap == NULL) {
            continue;
        }

        if (pst_another_vap->uc_vap_id == pst_mac_vap->uc_vap_id) {
            continue;
        }

        if (pst_another_vap->en_vap_state >= MAC_VAP_STATE_STA_JOIN_COMP &&
            pst_another_vap->en_vap_state <= MAC_VAP_STATE_STA_WAIT_ASOC) {
            oam_warning_log2(pst_another_vap->uc_vap_id, OAM_SF_UM,
                             "hmac_dbdc_need_kick_user::vap mode[%d] state[%d] kick user",
                             pst_another_vap->en_vap_mode, pst_another_vap->en_vap_state);

            st_kick_user_param.us_reason_code = MAC_UNSPEC_REASON;
            st_kick_user_param.send_disassoc_immediately = OAL_TRUE;
            oal_set_mac_addr(st_kick_user_param.auc_mac_addr, auc_mac_addr);
            hmac_config_kick_user(pst_another_vap, sizeof(uint32_t), (uint8_t *)&st_kick_user_param);

            return;
        }
    }
}
OAL_STATIC void hmac_user_del_destroy_timer(hmac_user_stru *pst_hmac_user)
{
    if (pst_hmac_user->st_mgmt_timer.en_is_registerd == OAL_TRUE) {
        frw_timer_immediate_destroy_timer_m(&pst_hmac_user->st_mgmt_timer);
    }
#ifdef _PRE_WLAN_CHBA_MGMT
    if (pst_hmac_user->chba_user.connect_info.assoc_waiting_timer.en_is_registerd == OAL_TRUE) {
        frw_timer_immediate_destroy_timer_m(&(pst_hmac_user->chba_user.connect_info.assoc_waiting_timer));
    }
#endif

    /* 删除user时停止kick user定时器 */
    if (pst_hmac_user->kick_user_timer.en_is_registerd == OAL_TRUE) {
        frw_timer_immediate_destroy_timer_m(&pst_hmac_user->kick_user_timer);
    }
}
#ifdef _PRE_WLAN_FEATURE_PSM_ABN_PKTS_STAT
OAL_STATIC void hmac_abn_pkts_stat_clean(mac_vap_stru *pst_mac_vap)
{
    hmac_device_stru *pst_hmac_device;

    pst_hmac_device = hmac_res_get_mac_dev(pst_mac_vap->uc_device_id);
    if (oal_unlikely(pst_hmac_device == NULL)) {
        oam_error_log0(pst_mac_vap->uc_vap_id, OAM_SF_UM, "{hmac_user_del::pst_hmac_device null.}");
        return;
    }
    if (mac_is_primary_legacy_sta(pst_mac_vap)) {
        pst_hmac_device->addba_req_cnt = 0;
        pst_hmac_device->group_rekey_cnt = 0;
    }
}
#endif
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
static void hmac_user_del_update_hal_lut(uint8_t hal_dev_id, uint8_t user_index)
{
    hal_host_device_stru *haldev = NULL;
    uint8_t loop;

    haldev = hal_get_host_device(hal_dev_id);
    if (haldev == NULL) {
        return;
    }

    for (loop = 0; loop < HAL_MAX_LUT; loop++) {
        if (haldev->user_sts_info[loop].user_id == user_index) {
            haldev->user_sts_info[loop].user_valid = 0;
            oam_warning_log2(hal_dev_id, OAM_SF_ANY, "{hmac_update_hal_lut::lut[%d] user_index[%x]}",
                             loop, user_index);
            return;
        }
    }
    oam_warning_log1(hal_dev_id, OAM_SF_ANY, "{hmac_update_hal_lut::user_index[%x]}", user_index);
    return;
}
#endif

#ifdef _PRE_WLAN_FEATURE_WMMAC
/*
 * 函 数 名  : hmac_user_del_addts_timer
 * 功能描述  : 删除发送addts req的超时定时器
 * 1.日    期  : 2020年06月6日
 *   修改内容  : 新生成函数
 */
OAL_STATIC void hmac_user_del_addts_timer(hmac_user_stru *pst_hmac_user)
{
    uint8_t uc_ac_index;
    for (uc_ac_index = 0; uc_ac_index < WLAN_WME_AC_BUTT; uc_ac_index++) {
        if (pst_hmac_user->st_user_base_info.st_ts_info[uc_ac_index].st_addts_timer.en_is_registerd == OAL_TRUE) {
            frw_timer_immediate_destroy_timer_m(
                &(pst_hmac_user->st_user_base_info.st_ts_info[uc_ac_index].st_addts_timer));
        }

        memset_s(&(pst_hmac_user->st_user_base_info.st_ts_info[uc_ac_index]), sizeof(mac_ts_stru), 0,
                 sizeof(mac_ts_stru));
        pst_hmac_user->st_user_base_info.st_ts_info[uc_ac_index].uc_tsid = 0xFF;
    }
}
#endif
#ifdef _PRE_PLAT_FEATURE_CUSTOMIZE
#define USED_MEM_STR_LEN  5
void hmac_custom_set_mult_user_flowctrl(mac_vap_stru *mac_vap)
{
    uint8_t pc_param[NUM_16_BYTES] = { 0 };
    int8_t pc_tmp[NUM_8_BYTES] = { 0 };
    struct wlan_flow_ctrl_params flow_ctrl = {0, 0};
    /* AP用户达到5时，调整流控参数为配置文件原有值 */
    if (mac_vap->us_user_nums != 5) {
        return;
    }
    wlan_chip_get_flow_ctrl_used_mem(&flow_ctrl);
    oal_itoa(flow_ctrl.start, pc_param, USED_MEM_STR_LEN);
    oal_itoa(flow_ctrl.stop, pc_tmp, USED_MEM_STR_LEN);

    pc_param[OAL_STRLEN(pc_param)] = ' ';
    if (memcpy_s(pc_param + OAL_STRLEN(pc_param), sizeof(pc_param) - OAL_STRLEN(pc_param),
        pc_tmp, OAL_STRLEN(pc_tmp)) != EOK) {
        oam_error_log0(0, OAM_SF_UM, "hmac_custom_set_mult_user_flowctrl::memcpy fail!");
        return;
    }
    hmac_config_sdio_flowctrl(mac_vap, (uint16_t)(OAL_STRLEN(pc_param) + 1), pc_param);
}
#endif

static void hmac_user_del_vap_init(hmac_vap_stru *hmac_vap, mac_device_stru *mac_device, hmac_user_stru *hmac_user)
{
    if (hmac_vap->st_vap_base_info.en_vap_mode == WLAN_VAP_MODE_BSS_STA) {
        hmac_fsm_change_state(hmac_vap, MAC_VAP_STATE_STA_FAKE_UP);
    } else if (hmac_vap->st_vap_base_info.en_vap_mode == WLAN_VAP_MODE_BSS_AP) {
        mac_vap_csa_support_set(&hmac_vap->st_vap_base_info, FALSE);
        if (hmac_user->assoc_err_code != MAC_IEEE_802_1X_AUTH_FAIL) {
            hmac_dbac_ap_flow_other_vap_channel_handle(mac_device);
        }
    }
    hmac_user->assoc_err_code = 0; // 清除错误标志
    hmac_vap->en_roam_prohibit_on = OAL_FALSE;
    hmac_user_del_dyn_pcie_vote(&hmac_vap->st_vap_base_info);
}
// add_key流程中清除user下的分片缓存，防止重关联或者rekey流程报文重组攻击
void hmac_user_clear_defrag_res(hmac_user_stru *hmac_user)
{
    if (hmac_user == NULL) {
        return;
    }
    oam_warning_log2(hmac_user->st_user_base_info.uc_vap_id, OAM_SF_ASSOC,
        "{hmac_user_clear_defrag_res :: timer[%d] netbuf NULL[%d] .}",
        hmac_user->st_defrag_timer.en_is_registerd, (hmac_user->pst_defrag_netbuf == NULL));
    if (hmac_user->st_defrag_timer.en_is_registerd == OAL_TRUE) {
        frw_timer_immediate_destroy_timer_m(&hmac_user->st_defrag_timer);
    }

    if (hmac_user->pst_defrag_netbuf != NULL) {
        oal_netbuf_free(hmac_user->pst_defrag_netbuf);
        hmac_user->pst_defrag_netbuf = NULL;
    }
}
uint32_t hmac_user_del_sync_dmac(mac_vap_stru *mac_vap, mac_user_stru *mac_user)
{
    uint32_t ret;
    frw_event_mem_stru *event_mem = NULL;
    frw_event_stru *event = NULL;
    dmac_ctx_del_user_stru *pst_del_user_payload = NULL;
    mac_ap_type_enum_uint16 ap_type = MAC_AP_TYPE_NORMAL;

    if (mac_vap->en_vap_mode == WLAN_VAP_MODE_BSS_STA) {
        ap_type = hmac_identify_type_of_ap_with_compatibility_issues(mac_vap, mac_user->auc_user_mac_addr);
    }
    /* 抛事件到DMAC层, 删除dmac用户 */
    event_mem = frw_event_alloc_m(sizeof(dmac_ctx_del_user_stru));
    if (oal_unlikely(event_mem == NULL)) {
        oam_error_log0(mac_vap->uc_vap_id, OAM_SF_UM, "{hmac_user_del::event_mem null.}");
        return OAL_ERR_CODE_ALLOC_MEM_FAIL;
    }

    event = frw_get_event_stru(event_mem);
    pst_del_user_payload = (dmac_ctx_del_user_stru *)event->auc_event_data;
    pst_del_user_payload->us_user_idx = mac_user->us_assoc_id;
    pst_del_user_payload->en_ap_type = ap_type;

    /* 添加此操作51DMT异常，暂看不出异常原因 */
    /* 用户 mac地址和idx 需至少一份有效，供dmac侧查找待删除的用户 */
    if (memcpy_s(pst_del_user_payload->auc_user_mac_addr, WLAN_MAC_ADDR_LEN,
        mac_user->auc_user_mac_addr, WLAN_MAC_ADDR_LEN) != EOK) {
        oam_error_log0(0, OAM_SF_UM, "{hmac_user_del::memcpy auc_user_mac_addr fail}");
    }
    /* 填充事件头 */
    frw_event_hdr_init(&(event->st_event_hdr), FRW_EVENT_TYPE_WLAN_CTX, DMAC_WLAN_CTX_EVENT_SUB_TYPE_DEL_USER,
                       sizeof(dmac_ctx_del_user_stru), FRW_EVENT_PIPELINE_STAGE_1,  mac_vap->uc_chip_id,
                       mac_vap->uc_device_id, mac_vap->uc_vap_id);

    ret = frw_event_dispatch_event(event_mem);
    frw_event_free_m(event_mem);
    if (oal_unlikely(ret != OAL_SUCC)) {
        /* 做维测，如果删除用户失败，前面清hmac资源的操作本身已经异常，需要定位 */
        oam_error_log1(mac_vap->uc_vap_id, OAM_SF_UM, "{hmac_user_del::dispatch_event failed[%d].}", ret);
    }
    return ret;
}
OAL_STATIC void hmac_sta_del_user(mac_device_stru *mac_device, hmac_vap_stru *hmac_vap)
{
    mac_vap_stru *mac_vap = &hmac_vap->st_vap_base_info;
    if (mac_vap->en_vap_mode != WLAN_VAP_MODE_BSS_STA) {
        return;
    }
    hmac_config_close_lp_miracast(mac_vap);
    /* 每次STA去关联时，都重新调整随机mac地址 */
    hmac_device_create_random_mac_addr(mac_device, mac_vap);
    /*  host删用户时mac vap下的关联id清零 */
    mac_vap_set_aid(mac_vap, 0);
    /* fastsleep可能修改ps mode，去关联时重置 */
    hmac_vap->uc_ps_mode = g_wlan_ps_mode;
    hmac_vap->uc_cfg_sta_pm_manual = OAL_FALSE;
    hmac_vap->ipaddr_obtained = OAL_FALSE;
    /*  STA删除用户之前需要先设置被删除的标志
     * 避免先删除用户，后接收到删除通知，导致device ip_addr_obtained标识未被清除，一直允许漫游 */
    hmac_roam_wpas_connect_state_notify(hmac_vap, WPAS_CONNECT_STATE_IPADDR_REMOVED);
    hmac_roam_exit(hmac_vap);
}
#ifdef _PRE_WLAN_FEATURE_WAPI
uint32_t hmac_user_del_reset_wapi(mac_device_stru *mac_device, mac_vap_stru *mac_vap, hmac_user_stru *hmac_user)
{
    hmac_user_stru *hmac_user_multi = NULL;
    hmac_user_wapi_deinit(hmac_user);
    /* STA模式下，清组播wapi加密端口 */
    hmac_user_multi = (hmac_user_stru *)mac_res_get_hmac_user(mac_vap->us_multi_user_idx);
    if (hmac_user_multi == NULL) {
        oam_error_log0(mac_vap->uc_vap_id, OAM_SF_ANY, "{hmac_user_del_reset_wapi::get user failed!}");
        return OAL_ERR_CODE_PTR_NULL;
    }
    hmac_wapi_set_port(&hmac_user_multi->st_wapi, OAL_FALSE);
    mac_device->uc_wapi = OAL_FALSE;
    return OAL_SUCC;
}
#endif
OAL_STATIC void hmac_user_del_vowifi_report(mac_vap_stru *mac_vap)
{
    if (mac_vap->pst_vowifi_cfg_param == NULL) {
        return;
    }
    if (mac_vap->pst_vowifi_cfg_param->en_vowifi_mode != VOWIFI_LOW_THRES_REPORT) {
        return;
    }
    /* 针对漫游和去关联场景,切换vowifi语音状态 */
    hmac_config_vowifi_report(mac_vap, 0, NULL);
}
static uint32_t hmac_user_del_feature_process(mac_device_stru *mac_device, hmac_vap_stru *hmac_vap,
    hmac_user_stru *hmac_user)
{
    mac_vap_stru *mac_vap = &hmac_vap->st_vap_base_info;
    uint16_t user_index = hmac_user->st_user_base_info.us_assoc_id;
#ifdef _PRE_WLAN_FEATURE_HIEX
    hmac_hiex_user_exit(hmac_user);
#endif
/* 删除user时候，需要更新保护机制 */
    hmac_protection_del_user(mac_vap, &(hmac_user->st_user_base_info));
    /* 删除hmac user 的关联请求帧空间 */
    hmac_user_free_asoc_req_ie(user_index);
#ifdef _PRE_WLAN_FEATURE_PMF
    hmac_stop_sa_query_timer(hmac_user);
#endif
    hmac_user_tx_ring_deinit(hmac_user);
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    hmac_user_del_update_hal_lut(hmac_vap->hal_dev_id, user_index);
#endif
    hmac_user_del_vowifi_report(mac_vap);
#ifdef _PRE_WLAN_FEATURE_WAPI
    if (hmac_user_del_reset_wapi(mac_device, mac_vap, hmac_user) != OAL_SUCC) {
        return OAL_FAIL;
    }
#endif
#ifdef _PRE_WLAN_FEATURE_PWL
    hmac_user_del_reset_pwl(hmac_user);
    mac_vap->soft_encrypt_mode = PWL_HOST_ENCRYPT;
    mac_vap->soft_decrypt_mode = PWL_HOST_DECRYPT;
#endif
#ifdef _PRE_WLAN_FEATURE_TCP_ACK_BUFFER
    hmac_del_user_reset_tcp_ack_buf(hmac_vap, hmac_user);
#endif
#ifdef _PRE_WLAN_FEATURE_PSM_ABN_PKTS_STAT
    hmac_abn_pkts_stat_clean(mac_vap);
#endif
#ifdef _PRE_WLAN_FEATURE_VSP
    hmac_vsp_stop(hmac_user);
#endif
#ifdef _PRE_WLAN_FEATURE_SMPS
    /* 删除用户，更新SMPS能力 */
    mac_user_set_sm_power_save(&hmac_user->st_user_base_info, 0);
#endif
#if defined(_PRE_WLAN_FEATURE_WMMAC)
    /* 删除user时删除发送addts req超时定时器 */
    hmac_user_del_addts_timer(hmac_user);
#endif  // defined(_PRE_WLAN_FEATURE_WMMAC)
    return OAL_SUCC;
}
OAL_STATIC void hmac_user_del_refresh_lut(mac_chip_stru *mac_chip, hmac_user_stru *hmac_user)
{
    hmac_set_user_lut_index_tbl(NULL, hmac_user->lut_index);
    mac_user_del_ra_lut_index(mac_chip->st_lut_table.auc_ra_lut_index_table, hmac_user->lut_index);
    hmac_user->lut_index = WLAN_ASSOC_USER_MAX_NUM;
}
void hmac_user_del_free_res(mac_chip_stru *mac_chip, uint16_t user_index)
{
    uint32_t ret;
    /* 释放用户内存 */
    ret = hmac_user_free(user_index);
    if (ret == OAL_SUCC) {
        /* chip下已关联user个数-- */
        mac_chip_dec_assoc_user(mac_chip);
    } else {
        oam_error_log1(0, OAM_SF_UM, "{hmac_user_del::mac_res_free_mac_user fail[%d].}", ret);
    }
}
#ifdef _PRE_WLAN_CHBA_MGMT
/* add user时将对应的bitmap置位 */
static void hmac_user_add_update_vap_user_bitmap(hmac_vap_stru *hmac_vap, uint16_t assoc_id)
{
    if (!is_ap(&hmac_vap->st_vap_base_info) || assoc_id >= g_wlan_spec_cfg->max_user_limit) {
        return;
    }
    hmac_vap->user_id_bitmap |= BIT(assoc_id);
    oam_warning_log2(hmac_vap->st_vap_base_info.uc_vap_id, 0,
        "hmac_user_add_update_vap_user_bitmap::user_id_bitmap[0x%x], add_user_id[%d]",
        hmac_vap->user_id_bitmap, assoc_id);
    return;
}
/* del user时将对应的bitmap清零 */
static void hmac_user_del_clear_vap_user_bitmap(hmac_vap_stru *hmac_vap, uint16_t assoc_id)
{
    if (!is_ap(&hmac_vap->st_vap_base_info) || assoc_id >= g_wlan_spec_cfg->max_user_limit) {
        return;
    }
    hmac_vap->user_id_bitmap &= ~(BIT(assoc_id));
    oam_warning_log2(hmac_vap->st_vap_base_info.uc_vap_id, 0,
        "hmac_user_del_clear_vap_user_bitmap::user_id_bitmap[0x%x], del_user_id[%d]",
        hmac_vap->user_id_bitmap, assoc_id);
    return;
}
#endif

typedef struct {
    mac_chip_stru *mac_chip;
    mac_device_stru *mac_device;
    hmac_vap_stru *hmac_vap;
    mac_user_stru *mac_user;
} hmac_user_del_ctx;
uint32_t hmac_user_del_updatectx(mac_vap_stru *mac_vap, hmac_user_stru *hmac_user, hmac_user_del_ctx *ctx)
{
    if (oal_unlikely(oal_any_null_ptr2(mac_vap, hmac_user))) {
        oam_error_log0(0, OAM_SF_UM, "{hmac_user_del::param null}");
        return OAL_ERR_CODE_PTR_NULL;
    }
    ctx->mac_user = (mac_user_stru *)(&hmac_user->st_user_base_info);
    ctx->mac_device = mac_res_get_dev(mac_vap->uc_device_id);
    ctx->hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(mac_vap->uc_vap_id);
    ctx->mac_chip = hmac_res_get_mac_chip(mac_vap->uc_chip_id);
    if (oal_unlikely(oal_any_null_ptr3(ctx->mac_chip, ctx->mac_device, ctx->hmac_vap))) {
        return OAL_ERR_CODE_PTR_NULL;
    }
    return OAL_SUCC;
}

/*
 * 功能描述  : 删除user
 */
uint32_t hmac_user_del(mac_vap_stru *mac_vap, hmac_user_stru *hmac_user)
{
    uint16_t user_index;
    hmac_user_del_ctx ctx;

    if (hmac_user_del_updatectx(mac_vap, hmac_user, &ctx) != OAL_SUCC) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    user_index = hmac_user->st_user_base_info.us_assoc_id;
    hmac_user->assoc_ap_up_tx_auth_req = OAL_FALSE;
    hmac_dbdc_need_kick_user(mac_vap, ctx.mac_device);
    oam_warning_log3(mac_vap->uc_vap_id, OAM_SF_UM, "{hmac_user_del::user mac:%02X:XX:XX:XX:%02X:%02X}",
        ctx.mac_user->auc_user_mac_addr[MAC_ADDR_0],
        ctx.mac_user->auc_user_mac_addr[MAC_ADDR_4], ctx.mac_user->auc_user_mac_addr[MAC_ADDR_5]);
    oam_warning_log2(mac_vap->uc_vap_id, OAM_SF_UM, "{hmac_user_del::del user[%d] start,is multi user[%d]}",
        ctx.mac_user->us_assoc_id, ctx.mac_user->en_is_multi_user);
    if (hmac_user_del_feature_process(ctx.mac_device, ctx.hmac_vap, hmac_user) != OAL_SUCC) {
        return OAL_FAIL;
    }
    hmac_sta_del_user(ctx.mac_device, ctx.hmac_vap);
    if (hmac_user_del_sync_dmac(mac_vap, ctx.mac_user) != OAL_SUCC) {
        return OAL_FAIL;
    }
    hmac_tid_clear(mac_vap, hmac_user);
    hmac_user_del_destroy_timer(hmac_user);
    hmac_user_clear_defrag_res(hmac_user);
#ifdef _PRE_WLAN_CHBA_MGMT
    hmac_chba_del_user_proc(ctx.hmac_vap, hmac_user);
#endif
    /* 从vap中删除用户 */
    mac_vap_del_user(mac_vap, user_index);
    hmac_arp_probe_destory(ctx.hmac_vap, hmac_user);
    hmac_chan_update_40m_intol_user(mac_vap);
#ifdef _PRE_PLAT_FEATURE_CUSTOMIZE
    hmac_custom_set_mult_user_flowctrl(mac_vap);
#endif
    hmac_user_del_refresh_lut(ctx.mac_chip, hmac_user);
    /* 清除tx switch ring list中的TID节点 */
    hmac_tid_ring_switch_disable(hmac_user);
#ifdef _PRE_WLAN_CHBA_MGMT
    hmac_update_chba_vap_info(ctx.hmac_vap, hmac_user);
    hmac_user_del_clear_vap_user_bitmap(ctx.hmac_vap, user_index);
#endif
    /* 释放用户内存 */
    hmac_user_del_free_res(ctx.mac_chip, user_index);
    hmac_user_del_vap_init(ctx.hmac_vap, ctx.mac_device, hmac_user);

    return OAL_SUCC;
}

/*
 * 函 数 名  : hmac_user_add_post_event
 * 功能描述  : 大函数拆分
 * 1.日    期  : 2020年05月5日
 *   作    者  :
 *   修改内容  : 新生成函数
 */
OAL_STATIC uint32_t hmac_user_add_post_event(mac_vap_stru *pst_mac_vap, hmac_user_stru *pst_hmac_user,
                                             uint8_t *puc_mac_addr, uint16_t us_user_idx)
{
    frw_event_mem_stru *pst_event_mem = NULL;
    frw_event_stru *pst_event = NULL;
    dmac_ctx_add_user_stru *pst_add_user_payload = NULL;
    mac_bss_dscr_stru *pst_bss_dscr = NULL;
    uint32_t ret;

    pst_event_mem = frw_event_alloc_m(sizeof(dmac_ctx_add_user_stru));
    if (oal_unlikely(pst_event_mem == NULL)) {
        oam_error_log0(pst_mac_vap->uc_vap_id, OAM_SF_UM, "{hmac_user_add::pst_event_mem null.}");
        return OAL_ERR_CODE_ALLOC_MEM_FAIL;
    }

    pst_event = frw_get_event_stru(pst_event_mem);
    pst_add_user_payload = (dmac_ctx_add_user_stru *)pst_event->auc_event_data;
    pst_add_user_payload->us_user_idx = us_user_idx;
    pst_add_user_payload->en_ap_type = pst_hmac_user->en_user_ap_type;
    pst_add_user_payload->lut_index = pst_hmac_user->lut_index;
    oal_set_mac_addr(pst_add_user_payload->auc_user_mac_addr, puc_mac_addr);

    /* 获取扫描的bss信息 */
    pst_bss_dscr = (mac_bss_dscr_stru *)hmac_scan_get_scanned_bss_by_bssid(pst_mac_vap, puc_mac_addr);
    pst_add_user_payload->c_rssi = (pst_bss_dscr != NULL) ?
                                   pst_bss_dscr->c_rssi : oal_get_real_rssi((int16_t)OAL_RSSI_INIT_MARKER);

    /* 填充事件头 */
    frw_event_hdr_init(&(pst_event->st_event_hdr),
                       FRW_EVENT_TYPE_WLAN_CTX,
                       DMAC_WLAN_CTX_EVENT_SUB_TYPE_ADD_USER,
                       sizeof(dmac_ctx_add_user_stru),
                       FRW_EVENT_PIPELINE_STAGE_1,
                       pst_mac_vap->uc_chip_id,
                       pst_mac_vap->uc_device_id,
                       pst_mac_vap->uc_vap_id);

    ret = frw_event_dispatch_event(pst_event_mem);

    frw_event_free_m(pst_event_mem);
    return ret;
}

static uint32_t hmac_user_sub_feature_init(mac_vap_stru *mac_vap, uint8_t *mac_addr,
    hmac_user_stru *hmac_user, uint16_t user_idx)
{
#ifdef _PRE_WLAN_FEATURE_WAPI
    mac_device_stru *mac_device = NULL;
#endif
    /* 初始化mac_user_stru */
    mac_user_init(&(hmac_user->st_user_base_info), user_idx, mac_addr,
        mac_vap->uc_chip_id, mac_vap->uc_device_id, mac_vap->uc_vap_id);
    mac_user_init_rom(&(hmac_user->st_user_base_info), user_idx);

#ifdef _PRE_WLAN_FEATURE_WAPI
    mac_device = mac_res_get_dev(mac_vap->uc_device_id);
    if (mac_device == NULL) {
        oam_warning_log0(mac_vap->uc_vap_id, OAM_SF_UM, "{hmac_user_sub_feature_init::pst_mac_device null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }
    /* 初始化单播wapi对象 */
    hmac_user_wapi_init(hmac_user, OAL_TRUE);
    mac_device->uc_wapi = OAL_FALSE;
#endif
#ifdef _PRE_WLAN_FEATURE_PWL
    hmac_user_add_init_pwl(hmac_user);
#endif

#ifdef _PRE_WLAN_FEATURE_HIEX
    if (g_wlan_spec_cfg->feature_hiex_is_open) {
        hmac_hiex_user_init(hmac_user);
    }
#endif

    /* 设置amsdu域 */
    hmac_amsdu_init_user(hmac_user);
    return OAL_SUCC;
}

static void hmac_add_user_set_80211_mgmt_frame_features(mac_vap_stru *mac_vap, uint8_t *mac_addr)
{
    mac_cfg_80211_ucast_switch_stru st_80211_ucast_switch = { 0 };

    /* 打开80211单播管理帧开关，观察关联过程，关联成功了就关闭 */
    st_80211_ucast_switch.en_frame_direction = OAM_OTA_FRAME_DIRECTION_TYPE_TX;
    st_80211_ucast_switch.en_frame_type = OAM_USER_TRACK_FRAME_TYPE_MGMT;
    st_80211_ucast_switch.en_frame_switch = OAL_SWITCH_ON;
    st_80211_ucast_switch.en_cb_switch = OAL_SWITCH_ON;
    st_80211_ucast_switch.en_dscr_switch = OAL_SWITCH_ON;
    memcpy_s(st_80211_ucast_switch.auc_user_macaddr, sizeof(st_80211_ucast_switch.auc_user_macaddr),
        (const void *)mac_addr, sizeof(st_80211_ucast_switch.auc_user_macaddr));
    hmac_config_80211_ucast_switch(mac_vap, sizeof(st_80211_ucast_switch), (uint8_t *)&st_80211_ucast_switch);

    st_80211_ucast_switch.en_frame_direction = OAM_OTA_FRAME_DIRECTION_TYPE_RX;
    st_80211_ucast_switch.en_frame_type = OAM_USER_TRACK_FRAME_TYPE_MGMT;
    st_80211_ucast_switch.en_frame_switch = OAL_SWITCH_ON;
    st_80211_ucast_switch.en_cb_switch = OAL_SWITCH_ON;
    st_80211_ucast_switch.en_dscr_switch = OAL_SWITCH_ON;
    hmac_config_80211_ucast_switch(mac_vap, sizeof(st_80211_ucast_switch), (uint8_t *)&st_80211_ucast_switch);
}

static uint32_t hmac_check_p2p_cl_user_num(mac_vap_stru *mac_vap, hmac_vap_stru *hmac_vap)
{
    if (mac_vap == NULL || hmac_vap == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    if (mac_vap->en_vap_mode == WLAN_VAP_MODE_BSS_STA) {
        if (is_p2p_cl(mac_vap)) {
            /*  P2P作为CL时可以添加2个用户，一个用于发送管理帧，一个用户发送数据帧 */
            if (hmac_vap->st_vap_base_info.us_user_nums >= 2) {
                oam_warning_log0(mac_vap->uc_vap_id, OAM_SF_UM, "hmac_user_add::a STA can only associated with 2 ap");
                return OAL_FAIL;
            }
        } else {
            if (hmac_vap->st_vap_base_info.us_user_nums >= 1) {
                oam_warning_log0(mac_vap->uc_vap_id, OAM_SF_UM, "hmac_user_add::a STA can only associated with 1 ap");
                return OAL_FAIL;
            }
        }
    }

    return OAL_SUCC;
}

OAL_STATIC mac_ap_type_enum_uint16 hmac_get_ap_type(mac_vap_stru *mac_vap, uint8_t *mac_addr)
{
    mac_ap_type_enum_uint16 ap_type = 0;
    if (mac_vap->en_vap_mode == WLAN_VAP_MODE_BSS_STA) {
        if (!is_p2p_cl(mac_vap)) {
            ap_type = hmac_identify_type_of_ap_with_compatibility_issues(mac_vap, mac_addr);
        }
    }
    return ap_type;
}

/* 根据用户数配置流控信息 */
OAL_STATIC void hmac_set_sdio_flowctrl_by_user_num(mac_vap_stru *mac_vap)
{
#ifdef _PRE_PLAT_FEATURE_CUSTOMIZE
    int8_t pc_param[] = "30 25";
    uint16_t us_len;

    /* AP用户达到6时，调整流控参数为Stop为25，Start为30 */
    if (mac_vap->us_user_nums == 6) {
        us_len = (uint16_t)(OAL_STRLEN(pc_param) + 1);
        hmac_config_sdio_flowctrl(mac_vap, us_len, pc_param);
    }
#endif
}

/* 检查add user前置条件 */
OAL_STATIC uint32_t hmac_check_add_user_conditions(mac_vap_stru *mac_vap, uint8_t *mac_addr)
{
    uint32_t ret;
    uint16_t user_idx;
    mac_chip_stru *mac_chip = hmac_res_get_mac_chip(mac_vap->uc_chip_id);
    hmac_vap_stru *hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(mac_vap->uc_vap_id);

    if (hmac_vap == NULL || mac_chip == NULL) {
        oam_warning_log0(0, OAM_SF_UM, "hmac_chba_work_channel_switch::hmac_vap or mac_chip NULL");
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* chip级别最大用户数判断 */
    if (mac_chip->uc_assoc_user_cnt >= mac_chip_get_max_asoc_user(mac_chip->uc_chip_id)) {
        oam_warning_log1(0, OAM_SF_UM, "{hmac_user_add::invalid uc_assoc_user_cnt[%d].}", mac_chip->uc_assoc_user_cnt);
        return OAL_ERR_CODE_CONFIG_EXCEED_SPEC;
    }

    if (hmac_vap->st_vap_base_info.us_user_nums >= mac_mib_get_MaxAssocUserNums(mac_vap)) {
        oam_warning_log2(mac_vap->uc_vap_id, OAM_SF_UM,
                         "{hmac_user_add::invalid us_user_nums[%d], us_user_nums_max[%d].}",
                         hmac_vap->st_vap_base_info.us_user_nums, mac_mib_get_MaxAssocUserNums(mac_vap));
        return OAL_ERR_CODE_CONFIG_EXCEED_SPEC;
    }

    /* 如果此用户已经创建，则返回失败 */
    ret = mac_vap_find_user_by_macaddr(mac_vap, mac_addr, &user_idx);
    if (ret == OAL_SUCC) {
        oam_warning_log1(mac_vap->uc_vap_id, OAM_SF_UM,
                         "{hmac_user_add::mac_vap_find_user_by_macaddr success[%d].}", ret);
        return OAL_FAIL;
    }

    if (hmac_check_p2p_cl_user_num(mac_vap, hmac_vap) != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_UM, "{hmac_user_add::the number of associated ap exceeds the upper limit}");
        return OAL_FAIL;
    }

    return OAL_SUCC;
}

/* 申请单播用户 */
OAL_STATIC hmac_user_stru *hmac_alloc_unicast_user(mac_vap_stru *mac_vap, uint8_t *mac_addr, uint16_t *user_index)
{
    uint32_t ret;
    uint16_t user_idx;
    hmac_user_stru *hmac_user = NULL;
    mac_chip_stru *mac_chip = NULL;

    mac_chip = hmac_res_get_mac_chip(mac_vap->uc_chip_id);
    /* 申请hmac用户内存，并初始清0 */
    ret = hmac_user_alloc(&user_idx);
    if (ret != OAL_SUCC) {
        oam_warning_log1(mac_vap->uc_vap_id, OAM_SF_UM, "{hmac_user_add::hmac_user_alloc failed[%d].}", ret);
        return NULL;
    }

    /* 单播用户不能使用userid为0，需重新申请一个。将userid作为aid分配给对端，处理psm时会出错 */
    if (user_idx == 0) {
        hmac_user_free(user_idx);
        ret = hmac_user_alloc(&user_idx);
        if ((ret != OAL_SUCC) || (user_idx == 0)) {
            oam_warning_log2(mac_vap->uc_vap_id, OAM_SF_UM,
                "{hmac_user_add::hmac_user_alloc failed ret[%d] us_user_idx[%d].}", ret, user_idx);
            return NULL;
        }
    }
    *user_index = user_idx; /* 出参赋值 */
    hmac_user = (hmac_user_stru *)mac_res_get_hmac_user(user_idx);
    if (hmac_user == NULL) {
        hmac_user_free(user_idx);
        oam_warning_log1(mac_vap->uc_vap_id, OAM_SF_UM, "{hmac_user_add::pst_hmac_user[%d] null}", user_idx);
        return NULL;
    }
    /* 申请lut index */
    if (hmac_alloc_user_lut_index(hmac_user, mac_chip, hmac_get_ap_type(mac_vap, mac_addr)) != OAL_SUCC) {
        hmac_user_free(user_idx);
        return NULL;
    }
    return hmac_user;
}

static void hmac_user_add_feature_proc(hmac_vap_stru *hmac_vap, hmac_user_stru *hmac_user, uint8_t *mac_addr,
    uint16_t user_index)
{
#ifdef _PRE_WLAN_CHBA_MGMT
    hmac_user_add_update_vap_user_bitmap(hmac_vap, user_index);
#endif
#ifdef _PRE_WLAN_FEATURE_MCAST_AMPDU_HW
    /* sta需额外增加一个组播用户 */
    wlan_chip_mcast_ampdu_sta_add_multi_user(&(hmac_vap->st_vap_base_info), mac_addr);
#endif
#ifdef _PRE_WLAN_FEATURE_PWL
    hmac_user_add_pwl_pre_pairwise_key(&(hmac_vap->st_vap_base_info), hmac_user, user_index);
#endif
}

/*
 * 函 数 名  : hmac_user_add
 * 功能描述  : 添加用户配置命令
 * 1.日    期  : 2013年6月5日
 *   作    者  :
 *   修改内容  : 新生成函数
 */
uint32_t hmac_user_add(mac_vap_stru *mac_vap, uint8_t *mac_addr, uint16_t *user_index)
{
    hmac_vap_stru *hmac_vap = NULL;
    hmac_user_stru *hmac_user = NULL;
    uint32_t ret;
    mac_chip_stru *mac_chip = NULL;

    if (oal_unlikely(oal_any_null_ptr3(mac_vap, mac_addr, user_index))) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(mac_vap->uc_vap_id);
    mac_chip = hmac_res_get_mac_chip(mac_vap->uc_chip_id);
    ret = hmac_check_add_user_conditions(mac_vap, mac_addr);
    if (ret != OAL_SUCC) {
        return ret;
    }

    /* add user 时需要对roam 进行初始化操作 */
    hmac_roam_init(hmac_vap);

    /* 获取hmac user */
    hmac_user = hmac_alloc_unicast_user(mac_vap, mac_addr, user_index);
    if (hmac_user == NULL) {
        oam_warning_log1(mac_vap->uc_vap_id, OAM_SF_UM, "{hmac_user_add::pst_hmac_user[%d] null}", *user_index);
        return OAL_ERR_CODE_PTR_NULL;
    }

    if (hmac_user_sub_feature_init(mac_vap, mac_addr, hmac_user, *user_index) != OAL_SUCC) {
        hmac_user_free(*user_index);
        return OAL_FAIL;
    }

    /***************************************************************************
        抛事件到DMAC层, 创建dmac用户
    ***************************************************************************/
    if (hmac_user_add_post_event(mac_vap, hmac_user, mac_addr, *user_index) != OAL_SUCC) {
        /* 异常处理，释放内存，device下关联用户数还没有++，这里不需要判断返回值做--操作 */
        hmac_user_free(*user_index);
        /* 不应该出现用户添加失败，失败需要定位具体原因 */
        oam_error_log0(mac_vap->uc_vap_id, OAM_SF_UM, "{hmac_user_add::frw_event_dispatch_event failed.}");
        return OAL_FAIL;
    }

    /* 添加用户到MAC VAP */
    if (mac_vap_add_assoc_user(mac_vap, *user_index) != OAL_SUCC) {
        oam_warning_log0(mac_vap->uc_vap_id, OAM_SF_UM, "{hmac_user_add::mac_vap_add_assoc_user failed.}");

        /* 异常处理，释放内存，device下关联用户数还没有++，这里不需要判断返回值做--操作 */
        hmac_user_free(*user_index);
        return OAL_FAIL;
    }

    /* 根据用户数配置流控信息 */
    hmac_set_sdio_flowctrl_by_user_num(mac_vap);

    /* 初始话hmac user部分信息 */
    hmac_user_init(hmac_user);
    hmac_arp_probe_init(hmac_vap, hmac_user);

    /* device下关联用户数++ */
    mac_chip_inc_assoc_user(mac_chip);

    /* 打开80211单播管理帧开关，观察关联过程，关联成功了就关闭 */
    hmac_add_user_set_80211_mgmt_frame_features(mac_vap, mac_addr);

    hmac_vap->en_roam_prohibit_on = (hmac_user->en_user_ap_type & MAC_AP_TYPE_ROAM) ? OAL_TRUE : OAL_FALSE;

    hmac_user_add_feature_proc(hmac_vap, hmac_user, mac_addr, *user_index);

    oam_warning_log4(mac_vap->uc_vap_id, OAM_SF_UM, "{hmac_user_add::user[%d] mac:%02X:XX:XX:XX:%02X:%02X}",
        *user_index, mac_addr[MAC_ADDR_0], mac_addr[MAC_ADDR_4], mac_addr[MAC_ADDR_5]);
    return OAL_SUCC;
}

void hmac_add_and_clear_repeat_op_rates(uint8_t *puc_ie_rates,
    uint8_t uc_ie_num_rates, hmac_rate_stru *pst_op_rates);

void hmac_user_sort_op_rates(hmac_user_stru *hmac_user);

uint32_t hmac_mgmt_updata_protocol_cap(mac_vap_stru *mac_vap, hmac_user_stru *hmac_user, mac_user_stru *mac_user);

void hmac_ap_up_update_legacy_capability(hmac_vap_stru *hmac_vap,
    hmac_user_stru *hmac_user, uint16_t us_cap_info);
/*
 * 函 数 名  : hmac_config_user_set_ht_hdl
 * 功能描述  : 配置命令添加用户,设置ht信息
 * 1.日    期  : 2021年1月27日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
static void hmac_config_user_set_ht_hdl(mac_vap_stru *mac_vap, hmac_user_stru *hmac_user,
    mac_cfg_add_user_param_stru *add_user)
{
    mac_user_ht_hdl_stru st_ht_hdl = { 0 };
    mac_user_get_ht_hdl(&hmac_user->st_user_base_info, &st_ht_hdl);
    st_ht_hdl.en_ht_capable = add_user->en_ht_cap;

    if (add_user->en_ht_cap == OAL_TRUE) {
        hmac_user->st_user_base_info.en_cur_protocol_mode = WLAN_HT_MODE;
        hmac_user->st_user_base_info.en_avail_protocol_mode = WLAN_HT_MODE;
    }

    /* 设置HT相关的信息:应该在关联的时候赋值 这个值配置的合理性有待考究 2012->page:786 */
    st_ht_hdl.uc_min_mpdu_start_spacing = mac_mib_get_min_mpdu_start_spacing(mac_vap);
    st_ht_hdl.uc_max_rx_ampdu_factor = mac_mib_get_min_mpdu_start_spacing(mac_vap);
    /* 设置ht速率集 */
    st_ht_hdl.bit_short_gi_20mhz = mac_mib_get_ShortGIOptionInTwentyImplemented(mac_vap);
    st_ht_hdl.bit_short_gi_40mhz = mac_mib_get_ShortGIOptionInFortyImplemented(mac_vap);
    st_ht_hdl.bit_tx_stbc = mac_mib_get_TxSTBCOptionImplemented(mac_vap);
    st_ht_hdl.bit_rx_stbc = mac_mib_get_RxSTBCOptionImplemented(mac_vap);
    st_ht_hdl.bit_ht_delayed_block_ack = mac_mib_get_dot11DelayedBlockAckOptionImplemented(mac_vap);
    st_ht_hdl.bit_max_amsdu_length = mac_mib_get_max_amsdu_length(mac_vap);
    /* 设置"40MHz不容许"，只在2.4GHz下有效 */
    if (mac_vap->st_channel.en_band == WLAN_BAND_2G) {
        st_ht_hdl.bit_forty_mhz_intolerant = mac_mib_get_FortyMHzIntolerant(mac_vap);
    } else {
        /* 5G 40MHz不容忍设置为0 */
        st_ht_hdl.bit_forty_mhz_intolerant = OAL_FALSE;
    }
    /* 配置user 速率 */
    memcpy_s(st_ht_hdl.uc_rx_mcs_bitmask, WLAN_HT_MCS_BITMASK_LEN, mac_mib_get_SupportedMCSRx(mac_vap),
        WLAN_HT_MCS_BITMASK_LEN);
    mac_user_set_ht_hdl(&hmac_user->st_user_base_info, &st_ht_hdl);
}
/*
 * 函 数 名  : hmac_config_user_set_vht_hdl
 * 功能描述  : 配置命令添加用户,设置vht信息
 * 1.日    期  : 2021年1月27日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
static void hmac_config_user_set_vht_hdl(mac_vap_stru *mac_vap, hmac_user_stru *hmac_user,
    mac_cfg_add_user_param_stru *add_user)
{
    mac_vht_hdl_stru     st_vht_hdl = { 0 };
    mac_user_get_vht_hdl(&hmac_user->st_user_base_info, &st_vht_hdl);
    st_vht_hdl.en_vht_capable = add_user->en_ht_cap;
    st_vht_hdl.bit_max_mpdu_length = mac_mib_get_maxmpdu_length(mac_vap);
    /* 设置"所支持的信道宽度集"，0:neither 160 nor 80+80:; 1:160MHz; 2:160/80+80MHz */
    st_vht_hdl.bit_supported_channel_width = mac_mib_get_VHTChannelWidthOptionImplemented(mac_vap);
    st_vht_hdl.bit_rx_ldpc = mac_mib_get_VHTLDPCCodingOptionImplemented(mac_vap);
    st_vht_hdl.bit_short_gi_80mhz = mac_mib_get_VHTShortGIOptionIn80Implemented(mac_vap);
    st_vht_hdl.bit_short_gi_160mhz = mac_mib_get_VHTShortGIOptionIn160and80p80Implemented(mac_vap);
    st_vht_hdl.bit_tx_stbc = mac_mib_get_VHTTxSTBCOptionImplemented(mac_vap);
    st_vht_hdl.bit_rx_stbc = 0;
    st_vht_hdl.bit_su_beamformer_cap = mac_mib_get_VHTSUBeamformerOptionImplemented(mac_vap);
    st_vht_hdl.bit_su_beamformee_cap = mac_mib_get_VHTSUBeamformeeOptionImplemented(mac_vap);
    st_vht_hdl.bit_num_bf_ant_supported = mac_mib_get_VHTBeamformeeNTxSupport(mac_vap) - 1;

    /* sounding dim是bfer的能力 */
    st_vht_hdl.bit_num_sounding_dim = mac_mib_get_VHTNumberSoundingDimensions(mac_vap);

    st_vht_hdl.bit_mu_beamformer_cap = mac_mib_get_VHTMUBeamformerOptionImplemented(mac_vap);
    st_vht_hdl.bit_mu_beamformee_cap = mac_mib_get_VHTMUBeamformeeOptionImplemented(mac_vap);
    st_vht_hdl.bit_vht_txop_ps = mac_mib_get_txopps(mac_vap);
    st_vht_hdl.bit_htc_vht_capable = mac_mib_get_vht_ctrl_field_cap(mac_vap);
    st_vht_hdl.bit_max_ampdu_len_exp = mac_mib_get_vht_max_rx_ampdu_factor(mac_vap);
    if (memcpy_s(&st_vht_hdl.st_rx_max_mcs_map, sizeof(mac_rx_max_mcs_map_stru),  \
        (mac_mib_get_ptr_vht_rx_mcs_map(mac_vap)), sizeof(mac_rx_max_mcs_map_stru)) != EOK) {
        return;
    }
    st_vht_hdl.bit_rx_highest_rate = mac_mib_get_us_rx_highest_rate(mac_vap);
    if (memcpy_s(&st_vht_hdl.st_tx_max_mcs_map, sizeof(mac_tx_max_mcs_map_stru),  \
        (mac_mib_get_ptr_vht_tx_mcs_map(mac_vap)), sizeof(mac_tx_max_mcs_map_stru)) != EOK) {
        return;
    }
    st_vht_hdl.bit_tx_highest_rate = mac_mib_get_us_tx_highest_rate(mac_vap);
    /* 用于指示VHT  DL  MU MIMO场景下支持的最大Nsts,如果设置为0,那么由Beamformee  STS  Capability决定 */
    st_vht_hdl.bit_user_num_spatial_stream_160m =  WLAN_NSS_LIMIT;
    mac_user_set_vht_hdl(&hmac_user->st_user_base_info, &st_vht_hdl);
}
/*
 * 函 数 名  : hmac_config_user_sync_info
 * 功能描述  : 设置用户带宽、速率、空间流信息
 * 1.日    期  : 2021年1月27日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
static void hmac_config_user_sync_info(hmac_user_stru *hmac_user, hmac_vap_stru *hmac_vap, mac_vap_stru *mac_vap,
    uint16_t user_index)
{
    uint32_t rslt;
    uint8_t tmp_rate[] = {0x8c, 0x12, 0x98, 0x24, 0xb0, 0x48, 0x60, 0x6c};
    /* 更新关联用户的legacy速率集合 */
    hmac_user_init_rates(hmac_user);
    hmac_add_and_clear_repeat_op_rates(tmp_rate, 8, &(hmac_user->st_op_rates)); /* 8:legacy速率长度 */
    oam_warning_log1(mac_vap->uc_vap_id, OAM_SF_UM, "{hmac_config_add_user::%d.}", hmac_user->st_op_rates.uc_rs_nrates);
    /* 按一定顺序重新排列速率 */
    hmac_user_sort_op_rates(hmac_user);
    /* 获取用户和VAP 可支持的11a/b/g 速率交集 */
    hmac_vap_set_user_avail_rates(&hmac_vap->st_vap_base_info, hmac_user);
    /* 设置空间流 */
    mac_user_set_num_spatial_stream(&(hmac_user->st_user_base_info), WLAN_DOUBLE_NSS);
    mac_user_set_avail_num_spatial_stream(&(hmac_user->st_user_base_info),
        oal_min(hmac_user->st_user_base_info.en_user_max_cap_nss, WLAN_DOUBLE_NSS));
    mac_user_set_smps_opmode_notify_nss(&(hmac_user->st_user_base_info), WLAN_NSS_LIMIT);
    /* 设置协议模式 */
    hmac_set_user_protocol_mode(mac_vap, hmac_user);
    hmac_mgmt_updata_protocol_cap(&(hmac_vap->st_vap_base_info), hmac_user, &hmac_user->st_user_base_info);
    hmac_config_user_num_spatial_stream_cap_syn(mac_vap, &(hmac_user->st_user_base_info));
    /* 设置带宽 */
    mac_user_set_bandwidth_info(&(hmac_user->st_user_base_info), WLAN_BW_CAP_80M, WLAN_BW_CAP_80M);
    oam_warning_log4(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_ASSOC,
        "{hmac_config_user_sync_info::usr idx[%d], protocol[%d] nss[%d] bw[%d].}",
        hmac_user->st_user_base_info.us_assoc_id, hmac_user->st_user_base_info.en_avail_protocol_mode,
        hmac_user->st_user_base_info.en_avail_num_spatial_stream, hmac_user->st_user_base_info.en_cur_bandwidth);
    oam_warning_log1(mac_vap->uc_vap_id, OAM_SF_UM,
        "{hmac_config_user_sync_info::cipher type: %d.}", hmac_user->st_user_base_info.st_key_info.en_cipher_type);

    /* 根据用户支持带宽能力，协商出当前带宽，dmac offload架构下，同步带宽信息到device */
    rslt = hmac_config_user_info_syn(&(hmac_vap->st_vap_base_info), &hmac_user->st_user_base_info);
    if (rslt != OAL_SUCC) {
        oam_error_log1(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_ASSOC,
            "{hmac_config_user_sync_info::usr_info_syn failed[%d].}", rslt);
    }
    /* AP检测STA成功，允许其关联成功 */
    rslt = hmac_config_user_rate_info_syn(&(hmac_vap->st_vap_base_info), &hmac_user->st_user_base_info);
    if (rslt != OAL_SUCC) {
        oam_error_log1(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_ASSOC,
            "{hmac_config_user_sync_info::hmac_config_user_rate_info_syn failed[%d].}", rslt);
    }
    /* 增加用户后通知算法初始化用户结构体 */
    hmac_user_add_notify_alg(&hmac_vap->st_vap_base_info, user_index);
    mac_user_set_port(&hmac_user->st_user_base_info, 1);
}

OAL_STATIC uint32_t hmac_config_del_added_user(mac_vap_stru *mac_vap, uint16_t us_user_index)
{
    uint32_t rslt;
    mac_device_stru *mac_device = NULL;
    mac_chip_stru *mac_chip = NULL;

    /* 异常处理，释放内存 */
    rslt = hmac_user_free(us_user_index);
    if (rslt == OAL_SUCC) {
        mac_device = mac_res_get_dev(mac_vap->uc_device_id);
        if (mac_device == NULL) {
            oam_warning_log0(mac_vap->uc_vap_id, OAM_SF_UM, "{hmac_config_add_user::mac_device null.}");
            return OAL_ERR_CODE_PTR_NULL;
        }

        mac_chip = hmac_res_get_mac_chip(mac_device->uc_chip_id);
        if (mac_chip == NULL) {
            oam_warning_log0(mac_vap->uc_vap_id, OAM_SF_UM, "{hmac_user_add::mac_chip null.}");
            return OAL_ERR_CODE_PTR_NULL;
        }

        /* hmac_add_user成功时chip下关联用户数已经++, 这里的chip下已关联user个数要-- */
        mac_chip_dec_assoc_user(mac_chip);
    }
    return OAL_SUCC;
}

/*
 * 函 数 名  : hmac_config_add_user
 * 功能描述  : 配置命令添加用户
 * 1.日    期  : 2013年6月5日
 *   作    者  :
 *   修改内容  : 新生成函数
 */
uint32_t hmac_config_add_user(mac_vap_stru *pst_mac_vap, uint16_t us_len, uint8_t *puc_param)
{
    mac_cfg_add_user_param_stru *pst_add_user = NULL;
    uint16_t us_user_index = 0;
    hmac_vap_stru *pst_hmac_vap = NULL;
    hmac_user_stru *pst_hmac_user = NULL;
    uint32_t ret;

    pst_add_user = (mac_cfg_add_user_param_stru *)puc_param;

    pst_hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(pst_mac_vap->uc_vap_id);
    if (pst_hmac_vap == NULL) {
        oam_warning_log0(0, OAM_SF_UM, "{hmac_config_add_user::pst_hmac_vap null.}");
        return OAL_FAIL;
    }

    ret = hmac_user_add(pst_mac_vap, pst_add_user->auc_mac_addr, &us_user_index);
    if (ret != OAL_SUCC) {
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_UM, "{hmac_config_add_user::hmac_user_add failed.}", ret);
        return ret;
    }

    pst_hmac_user = (hmac_user_stru *)mac_res_get_hmac_user(us_user_index);
    if (pst_hmac_user == NULL) {
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_UM, "{pst_hmac_user[%d] null.}", us_user_index);
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* hmac_config_add_user 此接口删除，相应调用需要整改，& */
    /* 设置qos域，后续如有需要可以通过配置命令参数配置 */
    mac_user_set_qos(&pst_hmac_user->st_user_base_info, OAL_TRUE);

    /* 设置HT域 */
    hmac_config_user_set_ht_hdl(pst_mac_vap, pst_hmac_user, pst_add_user);
    /* 设置vht域 */
    hmac_config_user_set_vht_hdl(pst_mac_vap, pst_hmac_user, pst_add_user);
    mac_user_set_asoc_state(&pst_hmac_user->st_user_base_info, MAC_USER_STATE_ASSOC);

    /* 设置amsdu域 */
    hmac_amsdu_init_user(pst_hmac_user);

    /***************************************************************************
        抛事件到DMAC层, 同步DMAC数据
    ***************************************************************************/
    /* 重新设置DMAC需要的参数 */
    pst_add_user->us_user_idx = us_user_index;

    ret = hmac_config_send_event(&pst_hmac_vap->st_vap_base_info, WLAN_CFGID_ADD_USER, us_len, puc_param);
    if (oal_unlikely(ret != OAL_SUCC)) {
        /* 异常处理，释放内存 */
        if (hmac_config_del_added_user(pst_mac_vap, us_user_index) != OAL_SUCC) {
            return OAL_ERR_CODE_PTR_NULL;
        }
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_UM, "{hmac_config_send_event failed[%d].}", ret);
        return ret;
    }
    /* 设置、同步速率、带宽、空间流信息 */
    hmac_config_user_sync_info(pst_hmac_user, pst_hmac_vap, pst_mac_vap, us_user_index);

    if (is_legacy_vap(pst_mac_vap)) { //  添加用户后，对于P2P 不需要修改vap 状态
        mac_vap_state_change(pst_mac_vap, MAC_VAP_STATE_UP);
    }

    return OAL_SUCC;
}

/*
 * 函 数 名  : hmac_config_del_user
 * 功能描述  : 配置命令删除用户
 * 1.日    期  : 2013年6月5日
 *   作    者  :
 *   修改内容  : 新生成函数
 */
uint32_t hmac_config_del_user(mac_vap_stru *pst_mac_vap, uint16_t us_len, uint8_t *puc_param)
{
    mac_cfg_del_user_param_stru *pst_del_user = NULL;
    hmac_user_stru *pst_hmac_user = NULL;
    hmac_vap_stru *pst_hmac_vap;
    uint16_t us_user_index;
    uint32_t ret;

    pst_del_user = (mac_cfg_add_user_param_stru *)puc_param;

    pst_hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(pst_mac_vap->uc_vap_id);
    if (pst_hmac_vap == NULL) {
        oam_warning_log0(pst_mac_vap->uc_vap_id, OAM_SF_UM, "{hmac_config_del_user::pst_hmac_vap null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* 获取用户对应的索引 */
    ret = mac_vap_find_user_by_macaddr(pst_mac_vap, pst_del_user->auc_mac_addr, &us_user_index);
    if (ret != OAL_SUCC) {
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_UM,
                         "{hmac_config_del_user::mac_vap_find_user_by_macaddr failed[%d].}", ret);
        return ret;
    }

    /* 获取hmac用户 */
    pst_hmac_user = (hmac_user_stru *)mac_res_get_hmac_user(us_user_index);
    if (pst_hmac_user == NULL) {
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_UM,
                         "{hmac_config_del_user::pst_hmac_user[%d] null.}", us_user_index);
        return OAL_ERR_CODE_PTR_NULL;
    }

    ret = hmac_user_del(pst_mac_vap, pst_hmac_user);
    if (ret != OAL_SUCC) {
        oam_warning_log2(pst_mac_vap->uc_vap_id, OAM_SF_UM,
                         "{hmac_config_del_user::hmac_user_del failed[%d] device_id[%d].}",
                         ret, pst_mac_vap->uc_device_id);
        return ret;
    }
    return OAL_SUCC;
}

/*
 * 函 数 名  : hmac_add_multi_user
 * 功能描述  : hmac层创建组播用户
 * 1.日    期  : 2013年8月23日
 *   作    者  :
 *   修改内容  : 新生成函数
 */
uint32_t hmac_user_add_multi_user(mac_vap_stru *pst_mac_vap, uint16_t *pus_user_index, uint8_t *multi_user_lut_idx)
{
    uint32_t ret;
    uint16_t us_user_index;
    mac_user_stru *pst_mac_user = NULL;
    hmac_user_stru *pst_hmac_user = NULL;

    ret = hmac_user_alloc(&us_user_index);
    if (ret != OAL_SUCC) {
        oam_error_log1(pst_mac_vap->uc_vap_id, OAM_SF_UM,
                       "{hmac_user_add_multi_user::hmac_user_alloc failed[%d].}", ret);
        return ret;
    }

    /* 初始化组播用户基本信息 */
    pst_mac_user = (mac_user_stru *)mac_res_get_mac_user(us_user_index);
    if (pst_mac_user == NULL) {
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_UM,
                         "{hmac_user_add_multi_user::pst_mac_user[%d] null.}", us_user_index);
        return OAL_ERR_CODE_PTR_NULL;
    }

    mac_user_init(pst_mac_user, us_user_index, NULL,
                  pst_mac_vap->uc_chip_id, pst_mac_vap->uc_device_id, pst_mac_vap->uc_vap_id);
    mac_user_init_rom(pst_mac_user, us_user_index);
#ifdef _PRE_WLAN_FEATURE_MCAST_AMPDU
    /* 初始化用户支持qos */
    if (mac_get_mcast_ampdu_switch() == OAL_TRUE) {
        mac_user_set_qos(pst_mac_user, OAL_TRUE);
    }
#endif

    *pus_user_index = us_user_index;
    pst_hmac_user = (hmac_user_stru *)mac_res_get_hmac_user(us_user_index);
    if (pst_hmac_user == NULL) {
        oam_error_log1(pst_mac_vap->uc_vap_id, OAM_SF_ANY,
                       "{hmac_user_add_multi_user::hmac_user[%d] null.}", us_user_index);
        return OAL_ERR_CODE_PTR_NULL;
    }

#ifdef _PRE_WLAN_FEATURE_WAPI
    /* 初始化wapi对象 */
    hmac_user_wapi_init(pst_hmac_user, OAL_FALSE);
#endif
#ifdef _PRE_WLAN_FEATURE_PWL
    hmac_user_add_init_pwl(pst_hmac_user);
#endif
#ifdef _PRE_WLAN_FEATURE_MCAST_AMPDU
    /* 组播聚合场景初始化tid、ring信息 */
    if (mac_get_mcast_ampdu_switch() == OAL_TRUE) {
        hmac_mcast_ampdu_user_tid_init(pst_mac_vap, pst_hmac_user, multi_user_lut_idx);
    }
#endif
    oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_ANY,
                     "{hmac_user_add_multi_user, user index[%d].}", us_user_index);

    return OAL_SUCC;
}

/*
 * 函 数 名  : hmac_user_del_multi_user
 * 功能描述  : hmac层删除multiuser
 * 1.日    期  : 2015年7月23日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_user_del_multi_user(mac_vap_stru *pst_mac_vap)
{
    uint32_t ret;

#if (defined(_PRE_WLAN_FEATURE_WAPI) || defined(_PRE_WLAN_FEATURE_PWL))
    hmac_user_stru *pst_hmac_user;
    pst_hmac_user = (hmac_user_stru *)mac_res_get_hmac_user(pst_mac_vap->us_multi_user_idx);
    if (pst_hmac_user == NULL) {
        oam_error_log1(pst_mac_vap->uc_vap_id, OAM_SF_ANY, "{hmac_user_del_multi_user::get hmac_user[%d] null.}",
                       pst_mac_vap->us_multi_user_idx);
        return OAL_ERR_CODE_PTR_NULL;
    }
#endif
#ifdef _PRE_WLAN_FEATURE_WAPI
    hmac_user_wapi_deinit(pst_hmac_user);
#endif
#ifdef _PRE_WLAN_FEATURE_PWL
    hmac_user_del_reset_pwl(pst_hmac_user);
#endif

    ret = hmac_user_free(pst_mac_vap->us_multi_user_idx);
    if (ret != OAL_SUCC) {
        oam_warning_log0(pst_mac_vap->uc_vap_id, OAM_SF_ANY, "{hmac_user_del_multi_user::hmac_user_free failed!}");
    }

    return OAL_SUCC;
}

/*
 * 函 数 名  : hmac_user_is_wapi_connected
 * 功能描述  : 判断wapi设备是否关连
 * 1.日    期  : 2015年12月23日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
#ifdef _PRE_WLAN_FEATURE_WAPI
uint8_t hmac_user_is_wapi_connected(uint8_t uc_device_id)
{
    uint8_t uc_vap_idx;
    hmac_user_stru *pst_hmac_user_multi = NULL;
    mac_device_stru *pst_mac_device = NULL;
    mac_vap_stru *pst_mac_vap = NULL;

    pst_mac_device = mac_res_get_dev(uc_device_id);
    if (oal_unlikely(pst_mac_device == NULL)) {
        oam_error_log1(0, OAM_SF_UM, "{hmac_user_is_wapi_connected::pst_mac_device null.id %u}", uc_device_id);
        return OAL_FALSE;
    }

    for (uc_vap_idx = 0; uc_vap_idx < pst_mac_device->uc_vap_num; uc_vap_idx++) {
        pst_mac_vap = mac_res_get_mac_vap(pst_mac_device->auc_vap_id[uc_vap_idx]);
        if (oal_unlikely(pst_mac_vap == NULL)) {
            oam_warning_log1(0, OAM_SF_CFG, "vap is null! vap id is %d", pst_mac_device->auc_vap_id[uc_vap_idx]);
            continue;
        }

        if (!is_sta(pst_mac_vap)) {
            continue;
        }

        pst_hmac_user_multi = (hmac_user_stru *)mac_res_get_hmac_user(pst_mac_vap->us_multi_user_idx);
        if ((pst_hmac_user_multi != NULL)
            && (wapi_port_flag(&pst_hmac_user_multi->st_wapi) == OAL_TRUE)) {
            return OAL_TRUE;
        }
    }

    return OAL_FALSE;
}
#endif /* #ifdef _PRE_WLAN_FEATURE_WAPI */

/*
 * 函 数 名  : hmac_user_add_notify_alg
 * 功能描述  : 抛事件给dmac，让其在dmac挂算法钩子
 * 1.日    期  : 2013年11月25日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_user_add_notify_alg(mac_vap_stru *pst_mac_vap, uint16_t us_user_idx)
{
    frw_event_mem_stru *pst_event_mem = NULL;
    frw_event_stru *pst_event = NULL;
    dmac_ctx_add_user_stru *pst_add_user_payload = NULL;
    uint32_t ret;
    hmac_user_stru *pst_hmac_user = NULL;

#ifdef _PRE_WLAN_CHBA_MGMT
    /* 关联成功，更新CHBA第二工作信道 */
    if (mac_is_chba_mode(pst_mac_vap)) {
        hmac_chba_update_channel_seq_when_connect();
    }
#endif /* _PRE_WLAN_CHBA_MGMT */

    /* 抛事件给Dmac，在dmac层挂用户算法钩子 */
    pst_event_mem = frw_event_alloc_m(sizeof(dmac_ctx_add_user_stru));
    if (oal_unlikely(pst_event_mem == NULL)) {
        oam_error_log0(pst_mac_vap->uc_vap_id, OAM_SF_ANY, "{hmac_user_add_notify_alg::pst_event_mem null.}");
        return OAL_ERR_CODE_ALLOC_MEM_FAIL;
    }

    pst_event = frw_get_event_stru(pst_event_mem);
    pst_add_user_payload = (dmac_ctx_add_user_stru *)pst_event->auc_event_data;
    pst_add_user_payload->us_user_idx = us_user_idx;
    pst_add_user_payload->us_sta_aid = pst_mac_vap->us_sta_aid;
    pst_hmac_user = (hmac_user_stru *)mac_res_get_hmac_user(us_user_idx);
    if (oal_unlikely(pst_hmac_user == NULL)) {
        oam_error_log1(0, OAM_SF_CFG, "{hmac_user_add_notify_alg::null param,pst_hmac_user[%d].}", us_user_idx);
        frw_event_free_m(pst_event_mem);
        return OAL_ERR_CODE_PTR_NULL;
    }

    mac_user_get_vht_hdl(&pst_hmac_user->st_user_base_info, &pst_add_user_payload->st_vht_hdl);
    mac_user_get_ht_hdl(&pst_hmac_user->st_user_base_info, &pst_add_user_payload->st_ht_hdl);
    /* 填充事件头 */
    frw_event_hdr_init(&(pst_event->st_event_hdr),
                       FRW_EVENT_TYPE_WLAN_CTX,
                       DMAC_WLAN_CTX_EVENT_SUB_TYPE_NOTIFY_ALG_ADD_USER,
                       sizeof(dmac_ctx_add_user_stru),
                       FRW_EVENT_PIPELINE_STAGE_1,
                       pst_mac_vap->uc_chip_id,
                       pst_mac_vap->uc_device_id,
                       pst_mac_vap->uc_vap_id);

    ret = frw_event_dispatch_event(pst_event_mem);
    if (oal_unlikely(ret != OAL_SUCC)) {
        /* 异常处理，释放内存 */
        frw_event_free_m(pst_event_mem);

        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_ANY,
                         "{hmac_user_add_notify_alg::frw_event_dispatch_event failed[%d].}", ret);
        return ret;
    }
    frw_event_free_m(pst_event_mem);

    return OAL_SUCC;
}

/*
 * 函 数 名  : mac_vap_get_hmac_user_by_addr
 * 功能描述  : 根据mac地址获取mac_user指针
 * 1.日    期  : 2015年1月8日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
hmac_user_stru *mac_vap_get_hmac_user_by_addr(mac_vap_stru *pst_mac_vap, uint8_t *puc_mac_addr, uint8_t mac_addr_len)
{
    uint32_t ret;
    uint16_t us_user_idx = 0xffff;
    hmac_user_stru *pst_hmac_user = NULL;

    /* 根据mac addr找sta索引 */
    ret = mac_vap_find_user_by_macaddr(pst_mac_vap, puc_mac_addr, &us_user_idx);
    if (ret != OAL_SUCC) {
        oam_warning_log1(0, OAM_SF_ANY,
                         "{mac_vap_get_hmac_user_by_addr::find_user_by_macaddr failed[%d].}", ret);
        if (puc_mac_addr != NULL) {
            oam_warning_log3(0, OAM_SF_ANY, "{mac_vap_get_hmac_user_by_addr:: mac_addr[%02x XX XX XX %02x %02x]!.}",
                             puc_mac_addr[MAC_ADDR_0], puc_mac_addr[MAC_ADDR_4], puc_mac_addr[MAC_ADDR_5]);
        }
        return NULL;
    }

    /* 根据sta索引找到user内存区域 */
    pst_hmac_user = mac_res_get_hmac_user(us_user_idx);
    if (pst_hmac_user == NULL) {
        oam_error_log1(0, OAM_SF_ANY, "{mac_vap_get_hmac_user_by_addr::user[%d] ptr null.}", us_user_idx);
    }
    return pst_hmac_user;
}

/*
 * 函 数 名  : hmac_user_set_amsdu_level
 * 功能描述  : 设置 user 的en_amsdu_level值
 * 1.日    期  : 2019年10月9日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void hmac_user_set_amsdu_level(hmac_user_stru *hmac_user,
                               wlan_tx_amsdu_enum_uint8 amsdu_level)
{
    hmac_user->amsdu_level = amsdu_level;
    hmac_user->st_user_base_info.st_cap_info.bit_amsdu_level = amsdu_level;

    oam_warning_log1(0, OAM_SF_ANY, "{hmac_user_set_amsdu_level::en_amsdu_level=[%d].}",
                     hmac_user->amsdu_level);
}
void hmac_user_set_amsdu_maxsize(hmac_user_stru *hmac_user, uint16_t max_size)
{
    hmac_user->amsdu_maxsize = max_size;

    oam_warning_log1(0, OAM_SF_ANY, "{hmac_user_set_amsdu_maxsize::us_amsdu_maxsize=[%d].}",
                     hmac_user->amsdu_maxsize);
}

/*
 * 函 数 名  : hmac_user_set_amsdu_level_by_max_mpdu_len
 * 功能描述  : 根据user的 max mpdu len 配置en_amsdu_level
 * 1.日    期  : 2019年10月9日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void hmac_user_set_amsdu_level_by_max_mpdu_len(hmac_user_stru *hmac_user,
                                               uint16_t max_mpdu_len)
{
    wlan_tx_amsdu_enum_uint8 amsdu_level;

    if (max_mpdu_len == 3895) { /* 3895: 根据user的max_mpdu_len配置amsdu_level */
        amsdu_level = WLAN_TX_AMSDU_BY_2;
    } else {
        amsdu_level = WLAN_TX_AMSDU_BY_4;
    }

    hmac_user_set_amsdu_maxsize(hmac_user, max_mpdu_len);
    hmac_user_set_amsdu_level(hmac_user, amsdu_level);
}

void hmac_user_set_close_ht_flag(mac_vap_stru *p_mac_vap, hmac_user_stru *p_hmac_user)
{
    if (g_wlan_spec_cfg->feature_ht_self_cure_is_open == OAL_FALSE ||
        p_mac_vap->en_protocol >= WLAN_HT_MODE) {
        return;
    }

    /* 首次入网 */
    if (p_mac_vap->en_vap_state != MAC_VAP_STATE_ROAMING) {
        if (hmac_ht_self_cure_in_blacklist(p_hmac_user->st_user_base_info.auc_user_mac_addr)) {
            p_hmac_user->close_ht_flag = OAL_TRUE;
            oam_warning_log4(0, OAM_SF_SCAN, "hmac_user_set_close_ht_flag::closeHtFalg=%d, %02X:XX:XX:XX:%02X:%02X",
                             p_hmac_user->close_ht_flag,
                             p_hmac_user->st_user_base_info.auc_user_mac_addr[0],  /* 0 mac地址第0字节 */
                             p_hmac_user->st_user_base_info.auc_user_mac_addr[4],  /* 4 mac地址第4字节 */
                             p_hmac_user->st_user_base_info.auc_user_mac_addr[5]); /* 5 mac地址第5字节 */
        }
    }
}

void hmac_user_cap_update_by_hisi_cap_ie(hmac_user_stru *pst_hmac_user, uint8_t *puc_payload, uint32_t msg_len)
{
    mac_hisi_cap_vendor_ie_stru st_hisi_cap_ie = {0};

    if (mac_get_hisi_cap_vendor_ie(puc_payload, msg_len, &st_hisi_cap_ie) != OAL_SUCC) {
        return;
    }
#ifdef _PRE_WLAN_FEATURE_11AX
    if ((g_wlan_spec_cfg->feature_11ax_is_open) && (st_hisi_cap_ie.bit_11ax_support != OAL_FALSE)) {
        pst_hmac_user->st_user_base_info.st_cap_info.bit_dcm_cap = st_hisi_cap_ie.bit_dcm_support;
    }
#endif
    pst_hmac_user->st_user_base_info.st_cap_info.bit_p2p_support_csa = st_hisi_cap_ie.bit_p2p_csa_support;
    pst_hmac_user->st_user_base_info.st_cap_info.bit_p2p_scenes = st_hisi_cap_ie.bit_p2p_scenes;
    if (memcpy_s(&pst_hmac_user->st_user_base_info.hisi_priv_cap,
        sizeof(mac_hisi_cap_vendor_ie_stru), &st_hisi_cap_ie, sizeof(mac_hisi_cap_vendor_ie_stru)) != EOK) {
        oam_warning_log0(0, OAM_SF_SCAN, "hmac_user_cap_update_by_hisi_cap_ie:: memcpy fail");
    }

    oam_warning_log4(0, OAM_SF_SCAN,
        "hmac_user_cap_update_by_hisi_cap_ie::1024qam_cap=%d, 4096qam_cap=%d, sgi_400ns_cap=%d, 3nss_80m_mcs6=%d",
        pst_hmac_user->st_user_base_info.hisi_priv_cap.bit_1024qam_cap,
        pst_hmac_user->st_user_base_info.hisi_priv_cap.bit_4096qam_cap,
        pst_hmac_user->st_user_base_info.hisi_priv_cap.bit_sgi_400ns_cap,
        pst_hmac_user->st_user_base_info.hisi_priv_cap.bit_vht_3nss_80m_mcs6);
    oam_warning_log1(0, OAM_SF_SCAN, "hmac_user_cap_update_by_hisi_cap_ie::he_ltf_repeat=%d",
        pst_hmac_user->st_user_base_info.hisi_priv_cap.bit_he_ltf_repeat);
}
