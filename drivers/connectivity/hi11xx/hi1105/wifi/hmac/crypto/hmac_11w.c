/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * 功能说明 : PMF
 * 创建日期 : 2020年07月30日
 */

#include "hmac_11w.h"
#include "hmac_resource.h"
#include "mac_resource.h"
#include "hmac_mgmt_ap.h"
#include "hmac_mgmt_sta.h"
#include "hmac_encap_frame.h"
#include "mac_ie.h"
#include "mac_mib.h"
#include "mac_frame_inl.h"
#include "hmac_mgmt_sta_up.h"
#include "hmac_roam_alg.h"
#ifdef _PRE_WLAN_FEATURE_PMF
#include "hmac_roam_connect.h"
#endif
#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_11W_C

#ifdef _PRE_WLAN_FEATURE_PMF
void hmac_pmf_update_pmf_black_list(mac_vap_stru *pst_mac_vap, mac_bss_dscr_stru *pst_bss_dscr,
                                    mac_nl80211_mfp_enum_uint8 en_conn_pmf_enable)
{
    uint16_t us_rsn_cap_info;
    hmac_device_stru *pst_hmac_dev;

    us_rsn_cap_info = mac_get_rsn_capability(pst_bss_dscr->puc_rsn_ie);
    if ((MAC_NL80211_MFP_NO == en_conn_pmf_enable) && mac_is_rsn_pmf_only_enable(us_rsn_cap_info)) {
        pst_hmac_dev = hmac_res_get_mac_dev(pst_mac_vap->uc_device_id);
        if (pst_hmac_dev == NULL) {
            oam_error_log0(pst_mac_vap->uc_vap_id, OAM_SF_ANY,
                           "hmac_pmf_update_pmf_black_list:: hmac device not find.");
            return;
        }
        hmac_device_pmf_add_black_list(pst_hmac_dev, pst_bss_dscr->auc_mac_addr);
    }
}

/*
 * 函 数 名  : hmac_config_chiptest_enable_pmf
 * 功能描述  : chip test强制配置pmf能力，且对关联后的vap也生效
 * 1.日    期  : 2015年1月13日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_enable_pmf(mac_vap_stru *pst_mac_vap, uint8_t *puc_param)
{
    oal_bool_enum_uint8 en_pmf_active;
    wlan_pmf_cap_status_uint8 *puc_pmf_cap;
    oal_dlist_head_stru *pst_entry;
    mac_user_stru *pst_user_tmp;

    oal_io_print("hmac_enable_pmf: func start!");
    if (oal_any_null_ptr2(pst_mac_vap, puc_param)) {
        oam_error_log0(0, OAM_SF_ANY, "hmac_enable_pmf::pst_mac_vap or puc_param is null");
        return OAL_ERR_CODE_PTR_NULL;
    }

    puc_pmf_cap = (wlan_pmf_cap_status_uint8 *)puc_param;

    switch (*puc_pmf_cap) {
        case MAC_PMF_DISABLED:
            mac_mib_set_dot11RSNAMFPC(pst_mac_vap, OAL_FALSE);
            mac_mib_set_dot11RSNAMFPR(pst_mac_vap, OAL_FALSE);
            mac_mib_set_rsnaactivated(pst_mac_vap, OAL_FALSE);
            en_pmf_active = OAL_FALSE;
            break;
        case MAC_PMF_ENABLED:
            mac_mib_set_dot11RSNAMFPC(pst_mac_vap, OAL_TRUE);
            mac_mib_set_dot11RSNAMFPR(pst_mac_vap, OAL_FALSE);
            mac_mib_set_rsnaactivated(pst_mac_vap, OAL_TRUE);
            return OAL_SUCC;
        case MAC_PMF_REQUIRED:
            mac_mib_set_dot11RSNAMFPC(pst_mac_vap, OAL_TRUE);
            mac_mib_set_dot11RSNAMFPR(pst_mac_vap, OAL_TRUE);
            mac_mib_set_rsnaactivated(pst_mac_vap, OAL_TRUE);
            en_pmf_active = OAL_TRUE;
            break;
        default:
            oal_io_print("hmac_enable_pmf: commend error!");
            return OAL_FAIL;
    }

    if (pst_mac_vap->en_vap_state == MAC_VAP_STATE_UP) {
        oal_dlist_search_for_each(pst_entry, &(pst_mac_vap->st_mac_user_list_head)) {
            pst_user_tmp = oal_dlist_get_entry(pst_entry, mac_user_stru, st_user_dlist);
            if (pst_user_tmp == NULL) {
                oam_error_log0(0, OAM_SF_ANY, "hmac_enable_pmf:: pst_user_tmp is null");
                return OAL_ERR_CODE_PTR_NULL;
            }

            mac_user_set_pmf_active(pst_user_tmp, en_pmf_active);
        }
    }

    oal_io_print("hmac_enable_pmf: func end!");

    return OAL_SUCC;
}

/*
 * 函 数 名  : hmac_config_vap_pmf_cap
 * 功能描述  : 更新vap中的PMF能力并同步到device
 * 1.日    期  : 2019.3.19
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_config_vap_pmf_cap(mac_vap_stru *pst_mac_vap, wlan_pmf_cap_status_uint8 en_pmf_cap)
{
    uint32_t ret;
    uint16_t us_len;

    mac_vap_pmf_mab_stru ast_mac_vap_pmf_tbl[MAC_PMF_BUTT] = {
        { OAL_FALSE, OAL_FALSE },
        { OAL_TRUE,  OAL_FALSE },
        { OAL_TRUE,  OAL_TRUE },
    };

    mac_mib_set_dot11RSNAMFPC(pst_mac_vap, ast_mac_vap_pmf_tbl[en_pmf_cap].en_mac_mib_dot11RSNAMFPC);
    mac_mib_set_dot11RSNAMFPR(pst_mac_vap, ast_mac_vap_pmf_tbl[en_pmf_cap].en_mac_mib_dot11RSNAMFPR);

    pst_mac_vap->en_user_pmf_cap = (en_pmf_cap != MAC_PMF_DISABLED) ? OAL_TRUE : OAL_FALSE;

    oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_CFG, "hmac_config_vap_pmf_cap::vap pmf cap [%d]", en_pmf_cap);

    /***************************************************************************
        抛事件到DMAC层, 同步DMAC数据
    ***************************************************************************/
    us_len = sizeof(en_pmf_cap);

    ret = hmac_config_send_event(pst_mac_vap, WLAN_CFGID_PMF_CAP, us_len, &en_pmf_cap);
    if (oal_unlikely(ret != OAL_SUCC)) {
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_CFG,
            "{hmac_config_vap_pmf_cap::hmac_config_send_event failed[%d].}", ret);
    }

    return ret;
}

oal_bool_enum_uint8 hmac_device_pmf_find_black_list(hmac_device_stru *pst_hmac_dev, uint8_t *puc_mac_addr)
{
    uint8_t uc_loop_idx;

    for (uc_loop_idx = 0; uc_loop_idx < pst_hmac_dev->st_pmf_black_list.uc_cnt; ++uc_loop_idx) {
        if (0 == oal_memcmp(pst_hmac_dev->st_pmf_black_list.auc_black_list[uc_loop_idx],
                            puc_mac_addr, WLAN_MAC_ADDR_LEN)) {
            return OAL_TRUE;
        }
    }

    return OAL_FALSE;
}

void hmac_device_pmf_add_black_list(hmac_device_stru *pst_hmac_dev, uint8_t *puc_mac_addr)
{
    uint8_t uc_black_add_pos;

    if (OAL_TRUE == hmac_device_pmf_find_black_list(pst_hmac_dev, puc_mac_addr)) {
        return;
    }

    /* 黑名单列表未满，插入到列表末尾，更新黑名单总数，否则覆盖最早的一个 */
    if (pst_hmac_dev->st_pmf_black_list.uc_cnt < PMF_BLACK_LIST_MAX_CNT) {
        uc_black_add_pos = pst_hmac_dev->st_pmf_black_list.uc_cnt++;
    } else {
        uc_black_add_pos = pst_hmac_dev->st_pmf_black_list.uc_first_idx++;
        pst_hmac_dev->st_pmf_black_list.uc_first_idx %= PMF_BLACK_LIST_MAX_CNT;
    }

    if (EOK != memcpy_s(pst_hmac_dev->st_pmf_black_list.auc_black_list[uc_black_add_pos],
                        WLAN_MAC_ADDR_LEN, puc_mac_addr, WLAN_MAC_ADDR_LEN)) {
        oam_error_log0(0, OAM_SF_ANY, "hmac_pmf_add_black_list::memcpy fail!");
        return;
    }

    oam_warning_log4(0, OAM_SF_ANY, "hmac_pmf_add_black_list::cnt[%d] mac addr %02X:xx:xx:xx:%02X:%02X",
        pst_hmac_dev->st_pmf_black_list.uc_cnt, puc_mac_addr[0], puc_mac_addr[4], puc_mac_addr[5]); // mac地址的0,4,5字节
}

/*
 * 函 数 名  : mac_get_assoc_comeback_time
 * 功能描述  : 计算得到 assoc rsp 中所需的assoc comeback time
 * 1.日    期  : 2014年4月28日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_get_assoc_comeback_time(mac_vap_stru *pst_mac_vap, hmac_user_stru *pst_hmac_user)
{
    uint32_t timeout = 0;
    uint32_t now_time;
    uint32_t passed_time;
    uint32_t sa_query_maxtimeout;

    /* 获取现在时间 */
    now_time = (uint32_t)oal_time_get_stamp_ms();

    /* 设置ASSOCIATION_COMEBACK_TIME，使STA在AP完成SA Query流程之后再发送关联请求 */
    /* 获得sa Query Max timeout值 */
    sa_query_maxtimeout = mac_mib_get_dot11AssociationSAQueryMaximumTimeout(pst_mac_vap);
    /* 是否现在有sa Query流程正在进行 */
    if ((pst_hmac_user->st_sa_query_info.sa_query_count != 0) &&
        (uint32_t)oal_time_get_runtime(pst_hmac_user->st_sa_query_info.sa_query_start_time, now_time) >= 0) {
        /* 待现有SA Query流程结束后才可以接受STA发过来的关联帧 */
        passed_time = (uint32_t)oal_time_get_runtime(pst_hmac_user->st_sa_query_info.sa_query_start_time, now_time);
        if (passed_time >= sa_query_maxtimeout) {
            timeout = sa_query_maxtimeout;
        } else {
            timeout = sa_query_maxtimeout - passed_time;
        }
    } else {
        /* 给接下来的SA Query流程预留时间 */
        timeout = sa_query_maxtimeout;
    }
    /* 更新keep silent时间，供PMF SA使用，其他场景不使用此值 */
    pst_hmac_user->st_sa_query_info.peer_sta_keep_silent_time = timeout;
    return timeout;
}

/*
 * 1.日    期  : 2014年4月21日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC uint32_t hmac_sa_query_del_user(mac_vap_stru *pst_mac_vap, hmac_user_stru *pst_hmac_user)
{
    wlan_vap_mode_enum_uint8 en_vap_mode;
    hmac_vap_stru *pst_hmac_vap = NULL;
    uint32_t ret;
    hmac_sa_query_stru *pst_sa_query_info;
    hmac_disconnect disconnect;

    if (oal_any_null_ptr2(pst_mac_vap, pst_hmac_user)) {
        oam_error_log0(0, OAM_SF_PMF, "{hmac_sa_query_del_user::pst_mac_vap or pst_hmac_user is null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    pst_hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(pst_mac_vap->uc_vap_id);
    if (pst_hmac_vap == NULL) {
        oam_error_log0(pst_mac_vap->uc_device_id, OAM_SF_PMF, "{hmac_sa_query_del_user::pst_hmac_vap null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* pending SA Query requests 计数器清零 & sa query流程开始时间清零 */
    pst_sa_query_info = &pst_hmac_user->st_sa_query_info;
    pst_sa_query_info->sa_query_count = 0;
    pst_sa_query_info->sa_query_start_time = 0;

    /* 修改 state & 删除 user */
    en_vap_mode = pst_mac_vap->en_vap_mode;
    switch (en_vap_mode) {
        case WLAN_VAP_MODE_BSS_AP: {
            /* 抛事件上报内核，已经去关联某个STA */
            hmac_handle_disconnect_rsp_ap(pst_hmac_vap, pst_hmac_user);
            break;
        }

        case WLAN_VAP_MODE_BSS_STA: {
            /* 上报内核sta已经和某个ap去关联 */
            disconnect.reason_code = MAC_DEAUTH_LV_SS;
            disconnect.type = WLAN_FC0_SUBTYPE_DISASSOC;
            disconnect.is_roam = OAL_FALSE;
            hmac_sta_handle_disassoc_rsp(pst_hmac_vap, &disconnect);
            break;
        }
        default:
            break;
    }

    /* 删除user */
    ret = hmac_user_del(&pst_hmac_vap->st_vap_base_info, pst_hmac_user);
    if (ret != OAL_SUCC) {
        oam_error_log1(pst_mac_vap->uc_device_id, OAM_SF_PMF,
                       "{hmac_sa_query_del_user::hmac_user_del failed[%d].}", ret);
        return OAL_FAIL;
    }
    return OAL_SUCC;
}

/*
 * 1.日    期  : 2014年4月21日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC uint32_t hmac_send_sa_query_req(mac_vap_stru *pst_mac_vap, hmac_user_stru *pst_hmac_user,
    oal_bool_enum_uint8 en_is_protected, uint16_t us_init_trans_id)
{
    uint16_t us_sa_query_len;
    oal_netbuf_stru *pst_sa_query = NULL;
    mac_tx_ctl_stru *pst_tx_ctl = NULL;
    uint32_t ret;

    if (oal_any_null_ptr2(pst_mac_vap, pst_hmac_user)) {
        oam_error_log0(0, OAM_SF_PMF, "{hmac_send_sa_query_req::pst_mac_vap or pst_hmac_user is null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* 申请SA Query 帧空间 */
    pst_sa_query = (oal_netbuf_stru *)oal_mem_netbuf_alloc(OAL_NORMAL_NETBUF,
                                                           WLAN_MEM_NETBUF_SIZE2,
                                                           OAL_NETBUF_PRIORITY_MID);
    if (pst_sa_query == NULL) {
        oam_error_log0(pst_mac_vap->uc_vap_id, OAM_SF_PMF, "{hmac_send_sa_query_req::pst_sa_query null.}");
        return OAL_ERR_CODE_ALLOC_MEM_FAIL;
    }

    /* 封装SA Query request帧 */
    memset_s(oal_netbuf_cb(pst_sa_query), oal_netbuf_cb_size(), 0, oal_netbuf_cb_size());
    us_sa_query_len = hmac_encap_sa_query_req(pst_mac_vap, (uint8_t *)oal_netbuf_header(pst_sa_query),
        pst_hmac_user->st_user_base_info.auc_user_mac_addr, pst_hmac_user->st_sa_query_info.us_sa_query_trans_id);

    /* 单播管理帧加密 */
    if (en_is_protected == OAL_TRUE) {
        mac_set_protectedframe((uint8_t *)oal_netbuf_header(pst_sa_query));
    }

    pst_tx_ctl = (mac_tx_ctl_stru *)oal_netbuf_cb(pst_sa_query); /* 获取cb结构体 */
    mac_get_cb_mpdu_len(pst_tx_ctl) = us_sa_query_len;           /* dmac发送需要的mpdu长度 */
    /* 发送完成需要获取user结构体 */
    mac_get_cb_tx_user_idx(pst_tx_ctl) = pst_hmac_user->st_user_base_info.us_assoc_id;

    oal_netbuf_put(pst_sa_query, us_sa_query_len);

    /* Buffer this frame in the Memory Queue for transmission */
    ret = hmac_tx_mgmt_send_event(pst_mac_vap, pst_sa_query, us_sa_query_len);
    if (ret != OAL_SUCC) {
        oal_netbuf_free(pst_sa_query);
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_PMF,
                         "{hmac_send_sa_query_req::hmac_tx_mgmt_send_event failed[%d].}", ret);
        return ret;
    }

    return OAL_SUCC;
}
/*
 * 1.日    期  : 2014年6月25日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_pmf_check_err_code(mac_vap_stru *mac_vap, mac_user_stru *pst_user_base_info,
    oal_bool_enum_uint8 en_is_protected, uint8_t *puc_mac_hdr)
{
    oal_bool_enum_uint8 en_aim_err_code;
    uint16_t us_err_code;

#ifdef _PRE_WLAN_FEATURE_PWL
    /* PWL模式下不进行PMF流程 */
    if (mac_vap->pwl_enable == OAL_TRUE) {
        return OAL_FAIL;
    }
#endif
    us_err_code = oal_make_word16(puc_mac_hdr[MAC_80211_FRAME_LEN], puc_mac_hdr[MAC_80211_FRAME_LEN + 1]);
    en_aim_err_code = ((us_err_code == MAC_NOT_AUTHED) || (us_err_code == MAC_NOT_ASSOCED)) ? OAL_TRUE : OAL_FALSE;

    if ((pst_user_base_info->st_cap_info.bit_pmf_active == OAL_TRUE) &&
        (en_aim_err_code == OAL_TRUE || en_is_protected == OAL_FALSE)) {
        return OAL_SUCC;
    }

    return OAL_FAIL;
}
#define HMAC_AP_PMF_RX_ROBUST_FRAME_MAX_CNT 20
static void hmac_pmf_clear_attack_rx_cnt(hmac_user_stru *hmac_user)
{
    hmac_user->attack_mgmt.pmf_rx_asoc_cnt = 0;
    hmac_user->attack_mgmt.pmf_rx_deauth_cnt = 0;
    hmac_user->attack_mgmt.pmf_rx_disasoc_cnt = 0;
}

OAL_STATIC uint32_t hmac_sa_query_time_beyond_maxinum_process(hmac_vap_stru *hmac_vap, hmac_user_stru *hmac_user)
{
    uint32_t relt, now, passed;

    now = (uint32_t)oal_time_get_stamp_ms();
    passed = (uint32_t)oal_time_get_runtime(hmac_user->st_sa_query_info.sa_query_start_time, now);
    if (passed >= mac_mib_get_dot11AssociationSAQueryMaximumTimeout(&(hmac_vap->st_vap_base_info))) {
        // 超时判断是否为robust攻击帧场景，1s内收到超过20个帧则认为是攻击
        if (hmac_user->attack_mgmt.pmf_rx_asoc_cnt > HMAC_AP_PMF_RX_ROBUST_FRAME_MAX_CNT ||
            hmac_user->attack_mgmt.pmf_rx_deauth_cnt > HMAC_AP_PMF_RX_ROBUST_FRAME_MAX_CNT ||
            hmac_user->attack_mgmt.pmf_rx_disasoc_cnt > HMAC_AP_PMF_RX_ROBUST_FRAME_MAX_CNT) {
            oam_warning_log4(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_ANY, "{hmac_sa_query_interval_timeout:: \
                passed[%d]ms rx attack frame cnt asoc[%d], deauth[%d], disasoc[%d], restart timer.}",
                passed, hmac_user->attack_mgmt.pmf_rx_asoc_cnt, hmac_user->attack_mgmt.pmf_rx_deauth_cnt,
                hmac_user->attack_mgmt.pmf_rx_disasoc_cnt);
            // 重新记录sa起始时间戳，重启定时器继续query
            hmac_user->st_sa_query_info.sa_query_start_time = (uint32_t)oal_time_get_stamp_ms();
            // 清理计数，开启新一轮攻击场景识别
            hmac_pmf_clear_attack_rx_cnt(hmac_user);
        } else {
            /* change state & sa_query_count=0 */
            oam_warning_log0(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_ANY,
                "{hmac_sa_query_interval_timeout::Deleting user.}");
            relt = hmac_sa_query_del_user(&(hmac_vap->st_vap_base_info), hmac_user);
            if (relt != OAL_SUCC) {
                oam_error_log1(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_ANY,
                    "{hmac_sa_query_interval_timeout::hmac_sa_query_del_user failed[%d].}", relt);
                return OAL_ERR_CODE_PMF_SA_QUERY_DEL_USER_FAIL;
            }
            return OAL_FAIL;
        }
    }
    return OAL_SUCC;
}
/*
 * 1.日    期  : 2014年4月21日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_sa_query_interval_timeout(void *p_arg)
{
    hmac_user_stru *hmac_user;
    hmac_vap_stru *hmac_vap;
    uint32_t relt, retry_timeout;

    hmac_user = (hmac_user_stru *)p_arg;
    if (hmac_user == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "{hmac_sa_query_interval_timeout::invalid param.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(hmac_user->st_user_base_info.uc_vap_id);
    if (hmac_vap == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    if (hmac_user->st_user_base_info.en_user_asoc_state != MAC_USER_STATE_ASSOC) {
        hmac_user->st_sa_query_info.sa_query_count = 0;
        oam_warning_log1(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_ANY,
            "{hmac_sa_query_interval_timeout::USER UNEXPECTED STATE[%d].}",
            hmac_user->st_user_base_info.en_user_asoc_state);
        return OAL_SUCC;
    }
    relt = hmac_sa_query_time_beyond_maxinum_process(hmac_vap, hmac_user);
    if (relt != OAL_SUCC) {
        return relt;
    }

    /* 再发送一帧sa query request */
    hmac_user->st_sa_query_info.us_sa_query_trans_id += 1;
    hmac_user->st_sa_query_info.sa_query_count += 1;
    oam_warning_log1(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_ANY,
        "{hmac_sa_query_interval_timeout::SA query, trans_id %d.}", hmac_user->st_sa_query_info.us_sa_query_trans_id);

    retry_timeout = mac_mib_get_dot11AssociationSAQueryRetryTimeout(&(hmac_vap->st_vap_base_info));

    /* 设置间隔定时器 */
    frw_timer_create_timer_m(&(hmac_user->st_sa_query_info.st_sa_query_interval_timer), hmac_sa_query_interval_timeout,
        retry_timeout, (void *)hmac_user, OAL_FALSE, OAM_MODULE_ID_HMAC, hmac_vap->st_vap_base_info.core_id);

    relt = hmac_send_sa_query_req(&(hmac_vap->st_vap_base_info), hmac_user, hmac_user->st_sa_query_info.en_is_protected,
        hmac_user->st_sa_query_info.us_sa_query_trans_id);
    if (relt != OAL_SUCC) {
        oam_error_log1(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_ANY,
            "{hmac_sa_query_interval_timeout::hmac_send_sa_query_req failed[%d].}", relt);
        return OAL_ERR_CODE_PMF_SA_QUERY_REQ_SEND_FAIL;
    }
    return OAL_SUCC;
}

/*
 * 1.日    期  : 2014年4月21日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_start_sa_query(mac_vap_stru *pst_mac_vap,
    hmac_user_stru *pst_hmac_user, oal_bool_enum_uint8 en_is_protected)
{
    uint32_t retry_timeout;
    hmac_vap_stru *pst_hmac_vap = NULL;
    uint32_t ret;
    uint16_t us_init_trans_id = 0;
    uint32_t now = 0;
    /* 入参判断 */
    if (oal_any_null_ptr2(pst_mac_vap, pst_hmac_user)) {
        oam_error_log0(0, OAM_SF_ANY, "{hmac_start_sa_query::pst_mac_vap or pst_hmac_user is null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* 判断vap有无pmf能力 */
    if (pst_hmac_user->st_user_base_info.st_cap_info.bit_pmf_active != OAL_TRUE) {
        oam_error_log0(pst_mac_vap->uc_vap_id, OAM_SF_ANY, "{hmac_start_sa_query::bit_pmf_active is down.}");
        return OAL_ERR_CODE_PMF_DISABLED;
    }

    /* 避免重复启动SA Query流程 */
    if (pst_hmac_user->st_sa_query_info.sa_query_count != 0) {
        now = (uint32_t)oal_time_get_stamp_ms();
        /* 已触发了sa，对端发起assoc aput回复的rsp携带了timeout ie指示对端静默时间，不超过静默时间不响应关联请求 */
        /* 如果不是收到assoc/reassoc req帧，silence时间为0，此时sa已启动则返回fail */
        if (pst_hmac_user->st_sa_query_info.peer_sta_keep_silent_time != 0 &&
            (uint32_t)oal_time_get_runtime(pst_hmac_user->st_sa_query_info.sa_query_start_time, now) <=
            pst_hmac_user->st_sa_query_info.peer_sta_keep_silent_time) {
            oam_warning_log2(pst_hmac_user->st_user_base_info.us_assoc_id, OAM_SF_ANY,
                "{hmac_start_sa_query::sta need keep silent[%d]ms, pass time[%d]ms, do not need assoc rsp.}",
                pst_hmac_user->st_sa_query_info.peer_sta_keep_silent_time,
                (uint32_t)oal_time_get_runtime(pst_hmac_user->st_sa_query_info.sa_query_start_time, now));
            return OAL_FAIL;
        }
        return OAL_SUCC;
    }

    /* 获得hmac vap 结构指针 */
    pst_hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(pst_mac_vap->uc_vap_id);
    if (pst_hmac_vap == NULL) {
        oam_error_log0(pst_mac_vap->uc_vap_id, OAM_SF_ANY, "{hmac_start_sa_query::pst_hmac_vap null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    retry_timeout = mac_mib_get_dot11AssociationSAQueryRetryTimeout(pst_mac_vap);

    /* 记录sa query流程开始时间,单位ms */
    pst_hmac_user->st_sa_query_info.sa_query_start_time = (uint32_t)oal_time_get_stamp_ms();
    /* 获得初始trans_id */
    pst_hmac_user->st_sa_query_info.us_sa_query_trans_id = (uint16_t)oal_time_get_stamp_ms();

    pst_hmac_user->st_sa_query_info.sa_query_count = 1;
    pst_hmac_user->st_sa_query_info.en_is_protected = en_is_protected;

    oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_ANY, "{hmac_start_sa_query::SA query, trans_id %d.}",
                     pst_hmac_user->st_sa_query_info.us_sa_query_trans_id);

    /* 设置间隔定时器 */
    frw_timer_create_timer_m(&(pst_hmac_user->st_sa_query_info.st_sa_query_interval_timer),
        hmac_sa_query_interval_timeout, retry_timeout, (void *)pst_hmac_user,
        OAL_FALSE, OAM_MODULE_ID_HMAC, pst_mac_vap->core_id);

    /* 发送SA Query request，开始查询流程 */
    ret = hmac_send_sa_query_req(pst_mac_vap, pst_hmac_user, en_is_protected, us_init_trans_id);
    if (ret != OAL_SUCC) {
        oam_error_log1(pst_mac_vap->uc_vap_id, 0, "{hmac_start_sa_query::hmac_send_sa_query_req failed[%d].}", ret);
        return OAL_ERR_CODE_PMF_SA_QUERY_REQ_SEND_FAIL;
    }

    return OAL_SUCC;
}

/*
 * 1.日    期  : 2014年4月21日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void hmac_send_sa_query_rsp(mac_vap_stru *pst_mac_vap, uint8_t *pst_hdr, oal_bool_enum_uint8 en_is_protected)
{
    uint16_t us_sa_query_len;
    oal_netbuf_stru *pst_sa_query = 0;
    mac_tx_ctl_stru *pst_tx_ctl = NULL;
    uint16_t us_user_idx = g_wlan_spec_cfg->invalid_user_id;
    uint32_t ret;

    if (oal_any_null_ptr2(pst_mac_vap, pst_hdr)) {
        oam_error_log0(0, OAM_SF_ANY, "{hmac_send_sa_query_rsp::param null.}");
        return;
    }
    oam_info_log0(pst_mac_vap->uc_vap_id, OAM_SF_ANY, "{hmac_send_sa_query_rsp::AP ready to TX a sa query rsp.}");

    pst_sa_query = (oal_netbuf_stru *)oal_mem_netbuf_alloc(OAL_NORMAL_NETBUF,
                                                           WLAN_MEM_NETBUF_SIZE2,
                                                           OAL_NETBUF_PRIORITY_MID);
    if (pst_sa_query == NULL) {
        oam_error_log0(pst_mac_vap->uc_vap_id, OAM_SF_ANY, "{hmac_send_sa_query_rsp::pst_sa_query null.}");
        return;
    }

    memset_s(oal_netbuf_cb(pst_sa_query), oal_netbuf_cb_size(), 0, oal_netbuf_cb_size());
    us_sa_query_len = hmac_encap_sa_query_rsp(pst_mac_vap, pst_hdr, (uint8_t *)oal_netbuf_header(pst_sa_query));

    /* 单播管理帧加密 */
    if (en_is_protected == OAL_TRUE) {
        mac_set_protectedframe((uint8_t *)oal_netbuf_header(pst_sa_query));
    }

    /* 填写正确的assoc id */
    ret = mac_vap_find_user_by_macaddr(pst_mac_vap, ((mac_ieee80211_frame_stru *)pst_hdr)->auc_address2, &us_user_idx);
    if (ret != OAL_SUCC) {
        oam_error_log1(pst_mac_vap->uc_vap_id, OAM_SF_ANY,
                       "{hmac_send_sa_query_rsp::mac_vap_find_user_by_macaddr fail,error_code=%d.}", ret);
        oal_netbuf_free(pst_sa_query);
        return;
    }

    pst_tx_ctl = (mac_tx_ctl_stru *)oal_netbuf_cb(pst_sa_query); /* 获取cb结构体 */
    mac_get_cb_mpdu_len(pst_tx_ctl) = us_sa_query_len;           /* dmac发送需要的mpdu长度 */
    mac_get_cb_tx_user_idx(pst_tx_ctl) = us_user_idx;            /* 发送完成需要获取user结构体 */

    oal_netbuf_put(pst_sa_query, us_sa_query_len);

    /* Buffer this frame in the Memory Queue for transmission */
    ret = hmac_tx_mgmt_send_event(pst_mac_vap, pst_sa_query, us_sa_query_len);
    if (ret != OAL_SUCC) {
        oal_netbuf_free(pst_sa_query);
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_ANY,
                         "{hmac_send_sa_query_rsp::hmac_tx_mgmt_send_event failed[%d].}", ret);
    }

    return;
}


/*
 * 1.日    期  : 2014年4月09日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void hmac_rx_sa_query_req(hmac_vap_stru *pst_hmac_vap,
    oal_netbuf_stru *pst_netbuf, oal_bool_enum_uint8 en_is_protected)
{
    uint8_t *puc_sa;
    hmac_user_stru *pst_hmac_user = NULL;
    uint8_t *puc_mac_hdr = NULL;
    mac_rx_ctl_stru *rx_ctl = NULL;

    if (oal_any_null_ptr2(pst_hmac_vap, pst_netbuf)) {
        oam_error_log0(0, OAM_SF_RX, "{hmac_rx_sa_query_req::pst_hmac_vap or pst_netbuf is null.}");
        return;
    }

    rx_ctl = (mac_rx_ctl_stru *)oal_netbuf_cb(pst_netbuf);
    if (rx_ctl == NULL) {
        return;
    }

    puc_mac_hdr = oal_netbuf_header(pst_netbuf);
    if (puc_mac_hdr == NULL || mac_get_rx_cb_frame_len(rx_ctl) < MAC_80211_FRAME_LEN + MAC_SA_QUERY_LEN) {
        oam_error_log1(pst_hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_RX,
            "{hmac_rx_sa_query_req::mac_hdr null or frame_len[%d] too short.}", mac_get_rx_cb_frame_len(rx_ctl));
        return;
    }

    mac_rx_get_sa((mac_ieee80211_frame_stru *)puc_mac_hdr, &puc_sa);
    pst_hmac_user = mac_vap_get_hmac_user_by_addr(&pst_hmac_vap->st_vap_base_info, puc_sa, WLAN_MAC_ADDR_LEN);
    if (pst_hmac_user == NULL) {
        oam_error_log0(pst_hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_RX,
                       "{hmac_rx_sa_query_req::pst_hmac_user null.}");
        return;
    }

    /* 如果该用户的管理帧加密属性不一致，丢弃该报文 */
    if (en_is_protected != pst_hmac_user->st_user_base_info.st_cap_info.bit_pmf_active) {
        oam_warning_log0(pst_hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_RX,
                         "{hmac_rx_sa_query_req::PMF check failed.}");
        return;
    }
    pst_hmac_user->st_sa_query_info.rx_sa_req = OAL_TRUE;
    /* sa Query rsp发送 */
    hmac_send_sa_query_rsp(&pst_hmac_vap->st_vap_base_info, puc_mac_hdr, en_is_protected);

    return;
}
/*
 * 1.日    期  : 2014年4月09日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void hmac_rx_sa_query_rsp(hmac_vap_stru *pst_hmac_vap,
    oal_netbuf_stru *pst_netbuf, oal_bool_enum_uint8 en_is_protected)
{
    uint8_t *puc_mac_hdr = NULL;
    uint8_t *puc_sa;
    hmac_user_stru *pst_hmac_user = NULL;
    uint16_t *pus_trans_id;
    hmac_sa_query_stru *pst_sa_query_info;
    mac_rx_ctl_stru *rx_ctrl = NULL;

    if (oal_any_null_ptr2(pst_hmac_vap, pst_netbuf)) {
        oam_error_log0(0, OAM_SF_AMPDU, "{hmac_rx_sa_query_rsp::pst_hmac_vap or pst_netbuf is null.}");
        return;
    }
    rx_ctrl = (mac_rx_ctl_stru *)oal_netbuf_cb(pst_netbuf);
    if (rx_ctrl == NULL) {
        return;
    }
    /* 获取帧头信息 */
    puc_mac_hdr = oal_netbuf_header(pst_netbuf);
    if ((puc_mac_hdr == NULL) || (mac_get_rx_cb_frame_len(rx_ctrl) < MAC_80211_FRAME_LEN + MAC_SA_QUERY_LEN)) {
        oam_error_log1(pst_hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_AMPDU,
            "{hmac_rx_sa_query_rsp::mac_hdr null or frame_len[%d] too short.}", mac_get_rx_cb_frame_len(rx_ctrl));
        return;
    }

    mac_rx_get_sa((mac_ieee80211_frame_stru *)puc_mac_hdr, &puc_sa);
    pst_hmac_user = mac_vap_get_hmac_user_by_addr(&pst_hmac_vap->st_vap_base_info, puc_sa, WLAN_MAC_ADDR_LEN);
    if (pst_hmac_user == NULL) {
        oam_error_log0(pst_hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_AMPDU,
                       "{hmac_rx_sa_query_rsp::pst_hmac_user null.}");
        return;
    }

    /* 如果该用户的管理帧加密属性不一致，丢弃该报文 */
    if (en_is_protected != pst_hmac_user->st_user_base_info.st_cap_info.bit_pmf_active) {
        oam_error_log0(pst_hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_AMPDU,
                       "{hmac_rx_sa_query_rsp::PMF check failed.}");
        return;
    }

    /* 对比trans_id */
    pus_trans_id = (uint16_t *)(puc_mac_hdr + MAC_80211_FRAME_LEN + 2); /* duration 2 byte */
    pst_sa_query_info = &pst_hmac_user->st_sa_query_info;

    /* 收到有效的SA query reqponse，保留这条有效的SA */
    if (oal_memcmp(pus_trans_id, &(pst_sa_query_info->us_sa_query_trans_id), 2) == OAL_SUCC) { /* size is 2 */
        /* pending SA Query requests 计数器清零 & sa query流程开始时间清零 */
        pst_sa_query_info->sa_query_count = 0;
        pst_sa_query_info->sa_query_start_time = 0;
        pst_sa_query_info->peer_sta_keep_silent_time = 0;
        hmac_pmf_clear_attack_rx_cnt(pst_hmac_user);
        /* 删除timer */
        if (pst_sa_query_info->st_sa_query_interval_timer.en_is_registerd != OAL_FALSE) {
            frw_timer_immediate_destroy_timer_m(&(pst_sa_query_info->st_sa_query_interval_timer));
        }
    }

    return;
}

oal_bool_enum_uint8 hmac_sta_roam_pmf_in_blacklist(hmac_device_stru *hmac_dev, mac_bss_dscr_stru *mac_bss_dscr,
    uint16_t rsn_cap_info)
{
    if ((OAL_TRUE == hmac_device_pmf_find_black_list(hmac_dev, mac_bss_dscr->auc_mac_addr)) &&
        mac_is_rsn_pmf_only_enable(rsn_cap_info)) {
        oam_warning_log3(0, OAM_SF_ANY,
            "hmac_sta_roam_pmf_in_blacklist::black list mac addr %02X:xx:xx:xx:%02X:%02X",
            mac_bss_dscr->auc_mac_addr[MAC_ADDR_0],
            mac_bss_dscr->auc_mac_addr[MAC_ADDR_4],
            mac_bss_dscr->auc_mac_addr[MAC_ADDR_5]);
        return OAL_TRUE;
    }

    return OAL_FALSE;
}

/*
 * 函 数 名  : hmac_sta_update_pmf_cap
 * 功能描述  : 漫游时，根据对端pmf能力更新vap的pmf能力
 * 1.日    期  : 2019.3.19
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void hmac_sta_roam_update_pmf(hmac_vap_stru *pst_hmac_vap, mac_bss_dscr_stru *pst_mac_bss_dscr)
{
    uint8_t match_suite2 = 0xff;
    uint8_t match_suite3 = 0xff;
    mac_crypto_settings_stru st_crypto = {0};
    uint16_t us_rsn_cap_info;
    wlan_pmf_cap_status_uint8 en_pmf_cap;
    hmac_device_stru *pst_hmac_dev;

    if (pst_hmac_vap->st_vap_base_info.en_vap_state != MAC_VAP_STATE_ROAMING) {
        return;
    }

    memset_s(&st_crypto, sizeof(mac_crypto_settings_stru), 0, sizeof(mac_crypto_settings_stru));

    if (pst_mac_bss_dscr->puc_rsn_ie != NULL) {
        mac_ie_get_rsn_cipher(pst_mac_bss_dscr->puc_rsn_ie, &st_crypto);

        match_suite2 = mac_rsn_ie_akm_match_suites_s(st_crypto.aul_akm_suite,
            sizeof(st_crypto.aul_akm_suite), MAC_RSN_AKM_PSK);
        if (match_suite2 == 0xff) {
            match_suite2 = mac_rsn_ie_akm_match_suites_s(st_crypto.aul_akm_suite,
                sizeof(st_crypto.aul_akm_suite), MAC_RSN_AKM_PSK_SHA256);
        }

        match_suite3 = mac_rsn_ie_akm_match_suites_s(st_crypto.aul_akm_suite,
            sizeof(st_crypto.aul_akm_suite), MAC_RSN_AKM_TBPEKE);
        if (match_suite3 == 0xff) {
            match_suite3 = mac_rsn_ie_akm_match_suites_s(st_crypto.aul_akm_suite,
                sizeof(st_crypto.aul_akm_suite), MAC_RSN_AKM_SAE);
        }
    }

    us_rsn_cap_info = mac_get_rsn_capability(pst_mac_bss_dscr->puc_rsn_ie);

    if (((mac_mib_get_AuthenticationMode(&pst_hmac_vap->st_vap_base_info) == WLAN_WITP_AUTH_SAE) ||
        (mac_mib_get_AuthenticationMode(&pst_hmac_vap->st_vap_base_info) == WLAN_WITP_AUTH_TBPEKE) ||
        (pst_hmac_vap->en_sae_connect == OAL_TRUE)) && (match_suite3 != 0xff)) {
        en_pmf_cap = mac_rsn_cap_to_pmf(us_rsn_cap_info); // wpa3方式漫游，需要支持PMF
    } else {
        en_pmf_cap = mac_is_rsn_enable_pmf(us_rsn_cap_info); // wpa/wpa2, wpa2 and wpa2/wpa3 mixed
    }

    pst_hmac_dev = hmac_res_get_mac_dev(pst_hmac_vap->st_vap_base_info.uc_device_id);
    if (pst_hmac_vap->en_sae_connect == OAL_FALSE &&
        hmac_sta_roam_pmf_in_blacklist(pst_hmac_dev, pst_mac_bss_dscr, us_rsn_cap_info) == OAL_TRUE) {
        /* 非WPA3 方式漫游，需要检查PMF黑名单；WPA3 方式漫游，需要支持PMF，不用检查PMF黑名单 */
        en_pmf_cap = MAC_PMF_DISABLED;
    }
#ifdef _PRE_WLAN_FEATURE_PWL
    /* PWL模式下管理帧加解密必然开启 */
    if (pst_hmac_vap->st_vap_base_info.pwl_enable == OAL_TRUE) {
        en_pmf_cap = MAC_PMF_REQUIRED;
    }
#endif
    hmac_config_vap_pmf_cap(&(pst_hmac_vap->st_vap_base_info), en_pmf_cap);
}

/*
 * 函 数 名  : hmac_stop_sa_query_timer
 * 功能描述  : 删除sa query timer
 * 1.日    期  : 2015年2月27日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void hmac_stop_sa_query_timer(hmac_user_stru *pst_hmac_user)
{
    frw_timeout_stru *pst_sa_query_interval_timer;

    pst_sa_query_interval_timer = &(pst_hmac_user->st_sa_query_info.st_sa_query_interval_timer);
    if (pst_sa_query_interval_timer->en_is_registerd != OAL_FALSE) {
        frw_timer_immediate_destroy_timer_m(pst_sa_query_interval_timer);
    }
}

/*
 * 函 数 名  : mac_get_pmf_cap
 * 功能描述  : 从RSN ie中获取pmf能力信息
 * 1.日    期  : 2015年2月7日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
wlan_pmf_cap_status_uint8 mac_get_pmf_cap(uint8_t *puc_ie, uint32_t ie_len)
{
    uint8_t *puc_rsn_ie = NULL;
    uint16_t us_rsn_cap;

    if (oal_unlikely(puc_ie == NULL)) {
        return MAC_PMF_DISABLED;
    }

    /* 查找RSN信息元素,如果没有RSN信息元素,则按照不支持处理 */
    puc_rsn_ie = mac_find_ie(MAC_EID_RSN, puc_ie, (int32_t)(ie_len));
    if (puc_rsn_ie == NULL) {
        return MAC_PMF_DISABLED;
    }

    /* 根据RSN信息元素, 判断RSN能力是否匹配 */
    us_rsn_cap = mac_get_rsn_capability(puc_rsn_ie);
    if ((us_rsn_cap & BIT6) && (us_rsn_cap & BIT7)) {
        return MAC_PMF_REQUIRED;
    }

    if (us_rsn_cap & BIT7) {
        return MAC_PMF_ENABLED;
    }
    return MAC_PMF_DISABLED;
}

/*
 * 功能描述  : 获取pmf的配置能力
 * 1.日    期  : 2015年2月7日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 * 2.日    期  : 2015年2月7日
 *   作    者  : wifi
 *   修改内容  :  pmf由wpa控制 不依赖RSN, 删除RSN MIB判断
 */
uint32_t mac_vap_init_pmf(mac_vap_stru *pst_mac_vap, uint8_t uc_pmf_cap, uint8_t uc_mgmt_proteced)
{
    switch (uc_pmf_cap) {
        case MAC_PMF_DISABLED: {
            mac_mib_set_dot11RSNAMFPC(pst_mac_vap, OAL_FALSE);
            mac_mib_set_dot11RSNAMFPR(pst_mac_vap, OAL_FALSE);
            break;
        }
        case MAC_PMF_ENABLED: {
            mac_mib_set_dot11RSNAMFPC(pst_mac_vap, OAL_TRUE);
            mac_mib_set_dot11RSNAMFPR(pst_mac_vap, OAL_FALSE);
            break;
        }
        case MAC_PMF_REQUIRED: {
            mac_mib_set_dot11RSNAMFPC(pst_mac_vap, OAL_TRUE);
            mac_mib_set_dot11RSNAMFPR(pst_mac_vap, OAL_TRUE);
            break;
        }
        default: {
            return OAL_FAIL;
        }
    }

    if (uc_mgmt_proteced == MAC_NL80211_MFP_REQUIRED) {
        pst_mac_vap->en_user_pmf_cap = OAL_TRUE;
    } else {
        pst_mac_vap->en_user_pmf_cap = OAL_FALSE;
    }

    return OAL_SUCC;
}

void hmac_mgmt_sta_roam_rx_sa_query(hmac_vap_stru *hmac_vap, oal_netbuf_stru *netbuf,
    uint8_t *data, oal_bool_enum_uint8 is_protected)
{
    switch (data[MAC_ACTION_OFFSET_ACTION]) {
        case MAC_SA_QUERY_ACTION_REQUEST:
            hmac_rx_sa_query_req(hmac_vap, netbuf, is_protected);
#ifdef _PRE_WLAN_FEATURE_PMF
            hmac_roam_notify_wpas_port_authed(hmac_vap);
#endif
            break;
        default:
            break;
    }
}

uint32_t hmac_mgmt_pmf_frame_filter(
    mac_vap_stru *mac_vap, mac_user_stru *mac_user,
    mac_ieee80211_frame_stru *mac_hdr, oal_bool_enum_uint8 is_protected)
{
    uint8_t *da = NULL;
    if ((mac_vap == NULL) || (mac_user == NULL) || (mac_hdr == NULL)) {
        oam_error_log0(0, OAM_SF_ANY, "{hmac_mgmt_pmf_frame_filter::params is NULL.}");
        return OAL_FAIL;
    }
    mac_rx_get_da(mac_hdr, &da);
#ifdef _PRE_WLAN_FEATURE_PWL
    if ((ether_is_multicast(da) != OAL_TRUE) && (is_protected != mac_user->st_cap_info.bit_pmf_active) &&
        (mac_vap->pwl_enable != OAL_TRUE)) {
#else
    if ((ether_is_multicast(da) != OAL_TRUE) && (is_protected != mac_user->st_cap_info.bit_pmf_active)) {
#endif
        oam_error_log0(0, OAM_SF_ANY, "{hmac_mgmt_pmf_frame_filter::PMF check failed.}");
        return OAL_FAIL;
    }
    return OAL_SUCC;
}

#endif

