/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * 功能说明 : hmac_nrcoex.c文件
 * 作    者 : wifi
 * 创建日期 : 2020年09月17日
 */

/* 1 头文件包含 */
#include "mac_frame_inl.h"
#include "hmac_sme_sta.h"
#include "hmac_mgmt_join.h"
#include "hmac_encap_frame_sta.h"
#include "hmac_p2p.h"
#include "hmac_11i.h"
#include "hmac_sae.h"
#include "hmac_scan.h"
#include "plat_pm_wlan.h"
#ifdef _PRE_WLAN_FEATURE_SNIFFER
#ifdef CONFIG_HW_SNIFFER
#include <hwnet/ipv4/sysctl_sniffer.h>
#endif
#endif
#include "oam_event_wifi.h"
#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_MGMT_JOIN_C
/*
 * 功能描述  : 输入参数  : 无
 * 1.日    期  : 2013年7月8日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_mgmt_timeout_sta(void *arg)
{
    hmac_vap_stru *hmac_vap = NULL;
    hmac_mgmt_timeout_param_stru *timeout_param;

    timeout_param = (hmac_mgmt_timeout_param_stru *)arg;
    if (timeout_param == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(timeout_param->uc_vap_id);
    if (hmac_vap == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    return hmac_fsm_call_func_sta(hmac_vap, HMAC_FSM_INPUT_TIMER0_OUT, timeout_param);
}

/*
 * 功能描述  : 在join之前，根据join request更新相关20/40共存参数(主要是更新带宽模式)
 * 1.日    期  : 2014年2月26日
  *   修改内容  : 新生成函数
 */
void hmac_update_join_req_params_2040(mac_vap_stru *mac_vap, mac_bss_dscr_stru *bss_dscr)
{
    /* 如果STA或者AP不支持HT且不支持VHT，则直接返回 */
    if (((mac_mib_get_HighThroughputOptionImplemented(mac_vap) == OAL_FALSE) &&
        (mac_mib_get_VHTOptionImplemented(mac_vap) == OAL_FALSE)) ||
        ((bss_dscr->en_ht_capable == OAL_FALSE) && (bss_dscr->en_vht_capable == OAL_FALSE))) {
        mac_vap->st_channel.en_bandwidth = WLAN_BAND_WIDTH_20M;
        return;
    }

    /* 使能40MHz */
    /* (1) 用户开启"40MHz运行"特性(即STA侧 dot11FortyMHzOperationImplemented为true) */
    /* (2) AP在40MHz运行 */
    if (OAL_TRUE == mac_mib_get_FortyMHzOperationImplemented(mac_vap)) {
        switch (bss_dscr->en_channel_bandwidth) {
            case WLAN_BAND_WIDTH_40PLUS:
            case WLAN_BAND_WIDTH_80PLUSPLUS:
            case WLAN_BAND_WIDTH_80PLUSMINUS:
                mac_vap->st_channel.en_bandwidth = WLAN_BAND_WIDTH_40PLUS;
                break;

            case WLAN_BAND_WIDTH_40MINUS:
            case WLAN_BAND_WIDTH_80MINUSPLUS:
            case WLAN_BAND_WIDTH_80MINUSMINUS:
                mac_vap->st_channel.en_bandwidth = WLAN_BAND_WIDTH_40MINUS;
                break;

            default:
                mac_vap->st_channel.en_bandwidth = WLAN_BAND_WIDTH_20M;
                break;
        }
    }

    /* 更新STA侧带宽与AP一致 */
    /* (1) STA AP均支持11AC */
    /* (2) STA支持40M带宽(FortyMHzOperationImplemented为TRUE)，
           定制化禁止2GHT40时，2G下FortyMHzOperationImplemented=FALSE，不更新带宽 */
    /* (3) STA支持80M带宽(即STA侧 dot11VHTChannelWidthOptionImplemented为0) */
    if ((OAL_TRUE == mac_mib_get_VHTOptionImplemented(mac_vap)) &&
        (bss_dscr->en_vht_capable == OAL_TRUE)) {
        if (OAL_TRUE == mac_mib_get_FortyMHzOperationImplemented(mac_vap)) {
            /* 不超过mac device最大带宽能力 */
            mac_vap->st_channel.en_bandwidth = mac_vap_get_bandwith(mac_mib_get_dot11VapMaxBandWidth(mac_vap),
                bss_dscr->en_channel_bandwidth);
        }
    }

    oam_warning_log2(mac_vap->uc_vap_id, OAM_SF_2040,
                     "{hmac_update_join_req_params_2040::en_channel_bandwidth=%d, mac vap bw[%d].}",
                     bss_dscr->en_channel_bandwidth, mac_vap->st_channel.en_bandwidth);

    /* 如果AP和STA同时支持20/40共存管理功能，则使能STA侧频谱管理功能 */
    if ((OAL_TRUE == mac_mib_get_2040BSSCoexistenceManagementSupport(mac_vap)) &&
        (bss_dscr->uc_coex_mgmt_supp == 1)) {
        mac_mib_set_SpectrumManagementImplemented(mac_vap, OAL_TRUE);
    }
}

/*
 * 功能描述  : 在join之前更新协议相关的参数
 * 1.日    期  : 2013年10月23日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void hmac_update_join_req_params_prot_sta(hmac_vap_stru *hmac_vap, hmac_join_req_stru *join_req)
{
    if (WLAN_MIB_DESIRED_BSSTYPE_INFRA == mac_mib_get_DesiredBSSType(&hmac_vap->st_vap_base_info)) {
        hmac_vap->st_vap_base_info.st_cap_flag.bit_wmm_cap = join_req->st_bss_dscr.uc_wmm_cap;
        mac_vap_set_uapsd_cap(&hmac_vap->st_vap_base_info, join_req->st_bss_dscr.uc_uapsd_cap);
    }

    hmac_update_join_req_params_2040(&(hmac_vap->st_vap_base_info), &(join_req->st_bss_dscr));
}

/*
 * 功能描述  : 在join之前，根据信道约束，更新带宽参数
 *             主要是基于协议约束，
 *            (0)暂时不考虑2G 40M情况，主要根据锁频能正常配置为准
 *            (1)165不支持80M
 *            (2)部分信道不支持40M,参考g_ast_pll_5g40m_info  针对锁频配置的带宽剔除
 *            JUMP: CH64 - CH100, 此间不可能存在40M信道
 *            JUMP:CH144 - CH149, 此间不存在40M信道
 *            JUMP:CH161 - CH184, 此间不可能存在40M信道
 *            int allowed[] = { 36, 44, 52, 60, 100, 108, 116, 124, 132, 140,149, 157, 184, 192 };
 * 1.日    期  : 2018年6月28日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void hmac_sta_bandwidth_down_by_channel(mac_vap_stru *mac_vap)
{
    oal_bool_enum_uint8 bandwidth_change_to_20m = OAL_FALSE;

    switch (mac_vap->st_channel.en_bandwidth) {
        case WLAN_BAND_WIDTH_40PLUS:
            /* 1. 64 144 161信道不支持40+ */
            if ((mac_vap->st_channel.uc_chan_number >= 64 && mac_vap->st_channel.uc_chan_number < 100) ||  // 64-100CH
                (mac_vap->st_channel.uc_chan_number >= 144 && mac_vap->st_channel.uc_chan_number < 149) || // 144-149CH
                (mac_vap->st_channel.uc_chan_number >= 161 && mac_vap->st_channel.uc_chan_number < 184)) { // 161-184CH
                bandwidth_change_to_20m = OAL_TRUE;
            }
            break;

        case WLAN_BAND_WIDTH_40MINUS:
            /* 1. 100 149 184信道不支持40- */
            if ((mac_vap->st_channel.uc_chan_number > 64 && mac_vap->st_channel.uc_chan_number <= 100) ||  // 64-100CH
                (mac_vap->st_channel.uc_chan_number > 144 && mac_vap->st_channel.uc_chan_number <= 149) || // 144-149CH
                (mac_vap->st_channel.uc_chan_number > 161 && mac_vap->st_channel.uc_chan_number <= 184)) { // 161-184CH
                bandwidth_change_to_20m = OAL_TRUE;
            }
            break;

        case WLAN_BAND_WIDTH_80PLUSPLUS:
        case WLAN_BAND_WIDTH_80PLUSMINUS:
        case WLAN_BAND_WIDTH_80MINUSPLUS:
        case WLAN_BAND_WIDTH_80MINUSMINUS:
            /* 165信道不支持80M, 暂时不考虑出现更多信道异常问题 */
            if (mac_vap->st_channel.uc_chan_number == 165) {
                bandwidth_change_to_20m = OAL_TRUE;
            }
            break;

        /* 160M的带宽校验暂时不考虑 */
        default:
            break;
    }

    /* 需要降带宽 */
    if (bandwidth_change_to_20m == OAL_TRUE) {
        oam_warning_log2(mac_vap->uc_vap_id, OAM_SF_SCAN,
            "{hmac_sta_bandwidth_down_by_channel:: channel[%d] not support bandwidth[%d], need to change to 20M.}",
            mac_vap->st_channel.uc_chan_number, mac_vap->st_channel.en_bandwidth);

        mac_vap->st_channel.en_bandwidth = WLAN_BAND_WIDTH_20M;
    }
}

/*
 * 功能描述  : 判断是否支持某种速率
 * 1.日    期  : 2016年3月31日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
oal_bool_enum_uint8 hmac_is_rate_support(uint8_t *rates, uint8_t rate_num, uint8_t rate)
{
    oal_bool_enum_uint8 rate_is_supp = OAL_FALSE;
    uint8_t loop;

    if (rates == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "{hmac_is_rate_support::rates null}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    for (loop = 0; loop < rate_num; loop++) {
        if ((rates[loop] & 0x7F) == rate) {
            rate_is_supp = OAL_TRUE;
            break;
        }
    }

    return rate_is_supp;
}

/*
 * 功能描述  : 是否支持11g速率
 * 1.日    期  : 2016年3月31日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
oal_bool_enum_uint8 hmac_is_support_11grate(uint8_t *rates, uint8_t rate_num)
{
    if (rates == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "{hmac_is_rate_support::rates null}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    if ((OAL_TRUE == hmac_is_rate_support(rates, rate_num, 0x0C))
        || (OAL_TRUE == hmac_is_rate_support(rates, rate_num, 0x12))
        || (OAL_TRUE == hmac_is_rate_support(rates, rate_num, 0x18))
        || (OAL_TRUE == hmac_is_rate_support(rates, rate_num, 0x24))
        || (OAL_TRUE == hmac_is_rate_support(rates, rate_num, 0x30))
        || (OAL_TRUE == hmac_is_rate_support(rates, rate_num, 0x48))
        || (OAL_TRUE == hmac_is_rate_support(rates, rate_num, 0x60))
        || (OAL_TRUE == hmac_is_rate_support(rates, rate_num, 0x6C))) {
        return OAL_TRUE;
    }

    return OAL_FALSE;
}

/*
 * 功能描述  : 是否支持11b速率
 * 1.日    期  : 2016年3月31日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
oal_bool_enum_uint8 hmac_is_support_11brate(uint8_t *rates, uint8_t rate_num)
{
    if (rates == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "{hmac_is_support_11brate::rates null}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    if ((hmac_is_rate_support(rates, rate_num, 0x02) == OAL_TRUE)
        || (hmac_is_rate_support(rates, rate_num, 0x04) == OAL_TRUE)
        || (hmac_is_rate_support(rates, rate_num, 0x0B) == OAL_TRUE)
        || (hmac_is_rate_support(rates, rate_num, 0x16) == OAL_TRUE)) {
        return OAL_TRUE;
    }

    return OAL_FALSE;
}
void hmac_sta_get_user_protocol_by_sup_rate(mac_bss_dscr_stru *bss_dscr,
    wlan_protocol_enum_uint8 *protocol_mode)
{
    if (hmac_is_support_11grate(bss_dscr->auc_supp_rates, bss_dscr->uc_num_supp_rates) == OAL_TRUE) {
        *protocol_mode = WLAN_LEGACY_11G_MODE;
        if (hmac_is_support_11brate(bss_dscr->auc_supp_rates, bss_dscr->uc_num_supp_rates) == OAL_TRUE) {
            *protocol_mode = WLAN_MIXED_ONE_11G_MODE;
        }
    } else if (hmac_is_support_11brate(bss_dscr->auc_supp_rates, bss_dscr->uc_num_supp_rates) == OAL_TRUE) {
        *protocol_mode = WLAN_LEGACY_11B_MODE;
    } else {
        oam_warning_log0(0, OAM_SF_ANY, "{hmac_sta_get_user_protocol::get user protocol failed.}");
    }
}

void hmac_sta_get_user_protocol(mac_bss_dscr_stru *bss_dscr,
    wlan_protocol_enum_uint8 *protocol_mode)
{
    if (g_wlan_spec_cfg->feature_11ax_is_open && (bss_dscr->en_he_capable == OAL_TRUE)) {
        *protocol_mode = WLAN_HE_MODE;
    } else if (bss_dscr->en_vht_capable == OAL_TRUE) {
        *protocol_mode = WLAN_VHT_MODE;
    } else if (bss_dscr->en_ht_capable == OAL_TRUE) {
        *protocol_mode = WLAN_HT_MODE;
    } else {
        if (bss_dscr->st_channel.en_band == WLAN_BAND_5G) { /* 判断是否是5G */
            *protocol_mode = WLAN_LEGACY_11A_MODE;
        } else {
            /* 嵌套深度优化封装 */
            hmac_sta_get_user_protocol_by_sup_rate(bss_dscr, protocol_mode);
        }
    }
}

/*
 * 功能描述  : 获取用户的协议模式
 * 1.日    期  : 2014年8月27日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_sta_get_user_protocol_etc(mac_bss_dscr_stru *bss_dscr,
    wlan_protocol_enum_uint8 *protocol_mode)
{
    /* 入参保护 */
    if (oal_any_null_ptr2(bss_dscr, protocol_mode)) {
        oam_error_log0(0, OAM_SF_SCAN, "{hmac_sta_get_user_protocol_etc::bss_dscr or protocol_mode is null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    hmac_sta_get_user_protocol(bss_dscr, protocol_mode);

    return OAL_SUCC;
}

/*
 * 功能描述  : STA发送WEP SHARE KEY AUTH 序列号为3的帧(降圈复杂度)
 * 1.日    期  : 2019年1月29日
  *   修改内容  : 新生成函数
 */
OAL_STATIC uint32_t hmac_sta_send_auth_seq3(hmac_vap_stru *sta, uint8_t *mac_hdr, mac_rx_ctl_stru *rx_ctl)
{
    oal_netbuf_stru *auth_frame = NULL;
    hmac_user_stru *hmac_user_ap = NULL;
    mac_tx_ctl_stru *tx_ctl = NULL;

    uint16_t auth_frame_len;
    uint32_t ret;

    /* 准备seq = 3的认证帧 */
    auth_frame = oal_mem_netbuf_alloc(OAL_NORMAL_NETBUF, WLAN_MEM_NETBUF_SIZE2, OAL_NETBUF_PRIORITY_MID);
    if (auth_frame == NULL) {
        oam_error_log0(sta->st_vap_base_info.uc_vap_id, OAM_SF_AUTH, "{hmac_wait_auth_sta::pst_auth_frame null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }
    oal_mem_netbuf_trace(auth_frame, OAL_TRUE);

    memset_s(oal_netbuf_cb(auth_frame), oal_netbuf_cb_size(), 0, oal_netbuf_cb_size());

    auth_frame_len = hmac_mgmt_encap_auth_req_seq3(sta, (uint8_t *)oal_netbuf_header(auth_frame), mac_hdr, rx_ctl);
    oal_netbuf_put(auth_frame, auth_frame_len);

    hmac_user_ap = mac_res_get_hmac_user(sta->st_vap_base_info.us_assoc_vap_id);
    if (hmac_user_ap == NULL) {
        oal_netbuf_free(auth_frame);
        oam_error_log1(sta->st_vap_base_info.uc_vap_id, OAM_SF_AUTH,
                       "{hmac_wait_auth_sta::pst_hmac_user[%d] null.}",
                       sta->st_vap_base_info.us_assoc_vap_id);
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* 填写发送和发送完成需要的参数 */
    tx_ctl = (mac_tx_ctl_stru *)oal_netbuf_cb(auth_frame);
    mac_get_cb_mpdu_len(tx_ctl) = auth_frame_len;                                 /* 发送需要帧长度 */
    mac_get_cb_tx_user_idx(tx_ctl) = hmac_user_ap->st_user_base_info.us_assoc_id; /* 发送完成要获取用户 */

    /* 抛事件给dmac发送 */
    ret = hmac_tx_mgmt_send_event(&sta->st_vap_base_info, auth_frame, auth_frame_len);
    if (ret != OAL_SUCC) {
        oal_netbuf_free(auth_frame);
        oam_warning_log1(sta->st_vap_base_info.uc_vap_id, OAM_SF_AUTH,
                         "{hmac_wait_auth_sta::hmac_tx_mgmt_send_event failed[%d].}", ret);
        return ret;
    }

    /*  收到seq = 2 的认证帧，并且正常处理，取消定时器 */
    frw_timer_immediate_destroy_timer_m(&sta->st_mgmt_timer);

    /* 更改状态为MAC_VAP_STATE_STA_WAIT_AUTH_SEQ4，并启动定时器 */
    hmac_fsm_change_state(sta, MAC_VAP_STATE_STA_WAIT_AUTH_SEQ4);

    frw_timer_create_timer_m(&sta->st_mgmt_timer, hmac_mgmt_timeout_sta, sta->st_mgmt_timer.timeout,
        &sta->st_mgmt_timetout_param, OAL_FALSE, OAM_MODULE_ID_HMAC, sta->st_vap_base_info.core_id);
    return OAL_SUCC;
}

/*
 * 功能描述  : 将dtim参数配置到dmac
 * 1.日    期  : 2020年3月31日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_sta_wait_join_dtim_config(hmac_vap_stru *hmac_sta, hmac_join_req_stru *join_req)
{
    dmac_ctx_set_dtim_tsf_reg_stru *set_dtim_tsf_reg_params = NULL;
    frw_event_mem_stru *event_mem = NULL;
    frw_event_stru *event = NULL;
    uint32_t ret;

    /* 抛事件到DMAC, 申请事件内存 */
    event_mem = frw_event_alloc_m(sizeof(dmac_ctx_set_dtim_tsf_reg_stru));
    if (event_mem == NULL) {
        oam_error_log1(hmac_sta->st_vap_base_info.uc_vap_id, OAM_SF_ASSOC,
                       "{hmac_sta_wait_join_dtim_config::event_mem alloc null, size[%d].}",
                       sizeof(dmac_ctx_set_dtim_tsf_reg_stru));
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* 填写事件 */
    event = frw_get_event_stru(event_mem);

    frw_event_hdr_init(&(event->st_event_hdr),
                       FRW_EVENT_TYPE_WLAN_CTX,
                       DMAC_WLAN_CTX_EVENT_SUB_TYPE_JOIN_DTIM_TSF_REG,
                       sizeof(dmac_ctx_set_dtim_tsf_reg_stru),
                       FRW_EVENT_PIPELINE_STAGE_1,
                       hmac_sta->st_vap_base_info.uc_chip_id,
                       hmac_sta->st_vap_base_info.uc_device_id,
                       hmac_sta->st_vap_base_info.uc_vap_id);

    set_dtim_tsf_reg_params = (dmac_ctx_set_dtim_tsf_reg_stru *)event->auc_event_data;

    /* 将Ap bssid和tsf REG 设置值保存在事件payload中 */
    set_dtim_tsf_reg_params->dtim_cnt = join_req->st_bss_dscr.uc_dtim_cnt;
    set_dtim_tsf_reg_params->dtim_period = join_req->st_bss_dscr.uc_dtim_period;
    set_dtim_tsf_reg_params->us_tsf_bit0 = BIT0;
    memcpy_s(set_dtim_tsf_reg_params->auc_bssid, WLAN_MAC_ADDR_LEN,
             hmac_sta->st_vap_base_info.auc_bssid, WLAN_MAC_ADDR_LEN);

    /* 分发事件 */
    ret = frw_event_dispatch_event(event_mem);
    frw_event_free_m(event_mem);
    return ret;
}

/*
 * 功能描述  : gc关联时，判断关联的go是否使能了NOA
 * 返回值：OAL_TRUE : GC关联的GO使能了NOA;  OAL_FALSE : GC关联的GO未使能NOA
 */
static oal_bool_enum_uint8 hmac_connect_is_p2p_gc_connect_noa_go(hmac_vap_stru *hmac_vap, hmac_join_req_stru *join_req)
{
    uint8_t *ie = NULL;
    uint8_t *p2p_ie = NULL;
    uint8_t *p2p_noa_attribute = NULL;
    uint16_t ie_len;
    mac_device_stru *mac_device = NULL;
    mac_bss_dscr_stru *bss_dscr = NULL;

    if (is_p2p_cl(&(hmac_vap->st_vap_base_info)) != OAL_TRUE) {
        return OAL_FALSE;
    }

    mac_device = mac_res_get_mac_dev();
    if (mac_device_calc_up_vap_num(mac_device) > 0) {
        return OAL_FALSE;
    }

    /* 获取扫描的bss信息 */
    bss_dscr = (mac_bss_dscr_stru *)hmac_scan_get_scanned_bss_by_bssid(&(hmac_vap->st_vap_base_info),
        join_req->st_bss_dscr.auc_bssid);
    if (bss_dscr == NULL) {
        return OAL_FALSE;
    }

    if (bss_dscr->mgmt_len < MAC_80211_QOS_HTC_4ADDR_FRAME_LEN) {
        return OAL_FALSE;
    }
    ie = bss_dscr->auc_mgmt_frame_body;
    ie_len = bss_dscr->mgmt_len - MAC_80211_QOS_HTC_4ADDR_FRAME_LEN;
    while (ie_len != 0) {
        /* 遍历查找P2P IE信息 */
        p2p_ie = mac_find_vendor_ie(MAC_WLAN_OUI_WFA, MAC_WLAN_OUI_TYPE_WFA_P2P, ie, ie_len);
        if (p2p_ie == NULL) {
            return OAL_FALSE;
        }

        if (p2p_ie[1] < MAC_P2P_MIN_IE_LEN) {
            return OAL_FALSE;
        }

        /* 查找P2P NOA信息 */
        /* 4：OUI长度 + Vendor Specific OUI Type长度 */
        p2p_noa_attribute = mac_find_p2p_attribute(MAC_P2P_ATTRIBUTE_NOA,
            p2p_ie + BYTE_OFFSET_6,
            p2p_ie[1] - BYTE_OFFSET_4);
        if (p2p_noa_attribute != NULL) {
            oam_warning_log0(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_ASSOC,
                "{hmac_sta_wait_join::find noa attribute!}");
            return OAL_TRUE;
        }

        if (ie_len < (p2p_ie - ie + p2p_ie[1] + MAC_IE_HDR_LEN)) {
            return OAL_FALSE;
        }
        ie_len -= (p2p_ie - ie + p2p_ie[1] + MAC_IE_HDR_LEN);
        ie = p2p_ie + p2p_ie[1] + MAC_IE_HDR_LEN;
    }

    return OAL_FALSE;
}

/*
 * 功能描述  : 处理SME发送过来的JOIN_REQ命令，启动JOIN流程，将STA状态设置为WAIT_JOIN
 * 1.日    期  : 2013年7月1日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_sta_wait_join(hmac_vap_stru *hmac_sta, void *msg)
{
    hmac_join_req_stru *join_req = NULL;
    hmac_join_rsp_stru join_rsp;
    uint16_t user_index = 0xFF;
    uint32_t ret;

    if (oal_any_null_ptr2(hmac_sta, msg)) {
        oam_error_log0(0, OAM_SF_SCAN, "{hmac_sta_wait_join::hmac_sta or msg is null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* P2PSTA共存 更新参数失败的话需要返回而不是继续下发Join动作 */
    ret = hmac_check_can_enter_state(&(hmac_sta->st_vap_base_info), HMAC_FSM_INPUT_ASOC_REQ, OAL_FALSE);
    if (ret != OAL_SUCC) {
        /* 不能进入监听状态，返回设备忙 */
        oam_warning_log1(hmac_sta->st_vap_base_info.uc_vap_id, OAM_SF_ASSOC,
            "{hmac_sta_wait_join fail,device busy: ret=%d}", ret);
        return OAL_ERR_CODE_CONFIG_BUSY;
    }

    join_req = (hmac_join_req_stru *)msg;
    /* 更新JOIN REG params 到MIB及MAC寄存器 */
    ret = hmac_sta_update_join_req_params(hmac_sta, join_req);
    if (ret != OAL_SUCC) {
        oam_error_log1(hmac_sta->st_vap_base_info.uc_vap_id, OAM_SF_ASSOC,
            "{hmac_sta_wait_join::get hmac_sta_update_join_req_params fail[%d]!}", ret);
        return ret;
    }

    /* 非proxy sta模式时，需要将dtim参数配置到dmac */
    ret = hmac_sta_wait_join_dtim_config(hmac_sta, join_req);
    if (ret != OAL_SUCC) {
        oam_error_log1(hmac_sta->st_vap_base_info.uc_vap_id, OAM_SF_ASSOC,
            "{hmac_sta_wait_join::get hmac_sta_wait_join_dtim_config fail[%d]!}", ret);
        return ret;
    }

    join_rsp.en_result_code = HMAC_MGMT_SUCCESS;
    /* 切换STA状态到JOIN_COMP */
    hmac_fsm_change_state(hmac_sta, MAC_VAP_STATE_STA_JOIN_COMP);

    if (hmac_connect_is_p2p_gc_connect_noa_go(hmac_sta, join_req) == OAL_TRUE) {
        /* GC关联的GO使能了NOA,需要等待GC 同步上GO的noa时隙，再执行关联 */
        /* 由于修改vap_state影响device rom，不能增加WAIT_JOIN状态，采用join_comp状态等价于WAIT_JOIN状态 */
        /* 启动join 定时器,超时调用 hmac_sta_wait_join_timeout,继续关联 */
        /* 不超时，则执行 hmac_sta_wait_join_misc */
        hmac_sta->st_mgmt_timetout_param.uc_vap_id = hmac_sta->st_vap_base_info.uc_vap_id;
        frw_timer_create_timer_m(&hmac_sta->st_mgmt_timer,
            hmac_mgmt_timeout_sta,
            join_req->timeout,
            &hmac_sta->st_mgmt_timetout_param,
            OAL_FALSE, OAM_MODULE_ID_HMAC, hmac_sta->st_vap_base_info.core_id);
        /* 由于需要noa控制用户收发，提前添加用户 */
        hmac_user_add(&(hmac_sta->st_vap_base_info), join_req->st_bss_dscr.auc_bssid, &user_index);
    } else {
        /* 发送JOIN成功消息给SME hmac_handle_join_rsp_sta */
        hmac_send_rsp_to_sme_sta(hmac_sta, HMAC_SME_JOIN_RSP, (uint8_t *)&join_rsp);
    }

    oam_warning_log4(hmac_sta->st_vap_base_info.uc_vap_id, OAM_SF_ASSOC,
        "{hmac_sta_wait_join::Join AP channel=%d idx=%d, bandwidth=%d Beacon Period=%d SUCC.}",
        join_req->st_bss_dscr.st_channel.uc_chan_number,
        join_req->st_bss_dscr.st_channel.uc_chan_idx,
        hmac_sta->st_vap_base_info.st_channel.en_bandwidth,
        join_req->st_bss_dscr.us_beacon_period);

    return OAL_SUCC;
}

/*
 * 函 数 名  : hmac_sta_wait_join_timeout
 * 功能描述  : 在WAIT_JOIN状态下处理超时事件
 * 1.日    期  : 2013年7月4日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_sta_wait_join_timeout(hmac_vap_stru *hmac_sta, void *msg)
{
    hmac_join_rsp_stru jion_rsp = { 0 };

    if (oal_any_null_ptr2(hmac_sta, msg)) {
        oam_error_log0(0, OAM_SF_CONN, "{hmac_sta_wait_join_timeout::hmac_sta or msg is null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    oam_warning_log0(hmac_sta->st_vap_base_info.uc_vap_id, OAM_SF_CONN,
        "{hmac_sta_wait_join_timeout::join timeout.}");

    /* 进入timeout处理函数表示join没有成功，仍继续关联 */
    jion_rsp.en_result_code = HMAC_MGMT_SUCCESS;

    /* 发送超时消息给SME, hmac_handle_join_rsp_sta */
    hmac_send_rsp_to_sme_sta(hmac_sta, HMAC_SME_JOIN_RSP, (uint8_t *)&jion_rsp);

    return OAL_SUCC;
}

/*
 * 函 数 名  : hmac_sta_wait_join_misc
 * 功能描述  : 在join_complete 状态下处理TBTT中断及其它异常事件
 */
uint32_t hmac_sta_wait_join_misc(hmac_vap_stru *hmac_sta, void *msg)
{
    hmac_join_rsp_stru jion_rsp;
    hmac_misc_input_stru *misc_input = (hmac_misc_input_stru *)msg;

    if (oal_any_null_ptr2(hmac_sta, msg)) {
        oam_error_log0(0, OAM_SF_CONN,
            "{hmac_sta_wait_join_misc::hmac_sta or msg is null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    oam_info_log0(hmac_sta->st_vap_base_info.uc_vap_id, OAM_SF_CONN,
        "{hmac_sta_wait_join_misc::enter func.}");
    switch (misc_input->en_type) {
        /* 处理TBTT中断  */
        case HMAC_MISC_TBTT: {
            /* 接收到TBTT中断，意味着JOIN成功了，所以取消JOIN开始时设置的定时器,发消息通知SME  */
            frw_timer_immediate_destroy_timer_m(&hmac_sta->st_mgmt_timer);

            jion_rsp.en_result_code = HMAC_MGMT_SUCCESS;

            oam_info_log0(hmac_sta->st_vap_base_info.uc_vap_id, OAM_SF_CONN,
                "{hmac_sta_wait_join_misc::join succ.}");
            /* 切换STA状态到JOIN_COMP */
            hmac_fsm_change_state(hmac_sta, MAC_VAP_STATE_STA_JOIN_COMP);

            /* 发送JOIN成功消息给SME hmac_handle_join_rsp_sta */
            hmac_send_rsp_to_sme_sta(hmac_sta, HMAC_SME_JOIN_RSP, (uint8_t *)&jion_rsp);
            break;
        }

        default: {
            /* Do Nothing */
            break;
        }
    }
    return OAL_SUCC;
}

/*
 * 功能描述  : 组seq = 1 的认证请求帧
 * 1.日    期  : 2020年5月18日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_sta_assemble_auth_seq1(hmac_vap_stru *hmac_sta, hmac_auth_req_stru *auth_req, oal_netbuf_stru *auth_frame)
{
    hmac_user_stru *hmac_user_ap = NULL;
    mac_tx_ctl_stru *tx_ctl = NULL;
    uint16_t auth_len;
    uint32_t ret;

    /* 组seq = 1 的认证请求帧 */
    auth_len = hmac_mgmt_encap_auth_req(hmac_sta,
        (uint8_t *)(oal_netbuf_header(auth_frame)), hmac_sta->st_vap_base_info.auc_bssid);

    oal_netbuf_put(auth_frame, auth_len);
    hmac_user_ap = mac_res_get_hmac_user(hmac_sta->st_vap_base_info.us_assoc_vap_id);
    if (hmac_user_ap == NULL) {
        oal_netbuf_free(auth_frame);
        oam_error_log1(hmac_sta->st_vap_base_info.uc_vap_id, OAM_SF_AUTH,
            "{hmac_sta_assemble_auth_frame::pst_hmac_user[%d] null.}", hmac_sta->st_vap_base_info.us_assoc_vap_id);
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* 为填写发送描述符准备参数 */
    tx_ctl = (mac_tx_ctl_stru *)oal_netbuf_cb(auth_frame); /* 获取cb结构体 */
    mac_get_cb_mpdu_len(tx_ctl) = auth_len;                 /* dmac发送需要的mpdu长度 */
    /* 发送完成需要获取user结构体 */
    mac_get_cb_tx_user_idx(tx_ctl) = hmac_user_ap->st_user_base_info.us_assoc_id;

    /* 如果是WEP，需要将ap的mac地址写入lut */
    ret = hmac_init_security(&(hmac_sta->st_vap_base_info), hmac_user_ap->st_user_base_info.auc_user_mac_addr,
        sizeof(hmac_user_ap->st_user_base_info.auc_user_mac_addr));
    if (ret != OAL_SUCC) {
        oam_error_log1(hmac_sta->st_vap_base_info.uc_vap_id, OAM_SF_ASSOC,
                       "{hmac_sta_assemble_auth_frame::hmac_init_security failed[%d].}", ret);
    }

    /* 抛事件让dmac将该帧发送 */
    ret = hmac_tx_mgmt_send_event(&hmac_sta->st_vap_base_info, auth_frame, auth_len);
    if (ret != OAL_SUCC) {
        oal_netbuf_free(auth_frame);
        oam_warning_log1(hmac_sta->st_vap_base_info.uc_vap_id, OAM_SF_AUTH,
                         "{hmac_sta_assemble_auth_frame::hmac_tx_mgmt_send_event failed[%d].}", ret);
        return ret;
    }

    /* 更改状态 */
    hmac_fsm_change_state(hmac_sta, MAC_VAP_STATE_STA_WAIT_AUTH_SEQ2);

    /* 启动认证超时定时器 */
    hmac_sta->st_mgmt_timetout_param.en_state = MAC_VAP_STATE_STA_WAIT_AUTH_SEQ2;
    hmac_sta->st_mgmt_timetout_param.us_user_index = hmac_user_ap->st_user_base_info.us_assoc_id;
    hmac_sta->st_mgmt_timetout_param.uc_vap_id = hmac_sta->st_vap_base_info.uc_vap_id;
    frw_timer_create_timer_m(&hmac_sta->st_mgmt_timer, hmac_mgmt_timeout_sta, auth_req->us_timeout,
        &hmac_sta->st_mgmt_timetout_param, OAL_FALSE, OAM_MODULE_ID_HMAC, hmac_sta->st_vap_base_info.core_id);

    return OAL_SUCC;
}

/*
 * 功能描述  : 处理sme发来的auth req请求。将状态置为WAIT_AUTH_SEQ2 抛事件到dmac发送
 * 1.日    期  : 2013年6月25日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_sta_wait_auth(hmac_vap_stru *hmac_sta, void *msg)
{
    hmac_auth_req_stru *auth_req = NULL;
    oal_netbuf_stru *auth_frame = NULL;
    uint32_t ret;

    if (oal_any_null_ptr2(hmac_sta, msg)) {
        oam_error_log0(0, OAM_SF_AUTH, "{hmac_sta_wait_auth::hmac_sta or msg is null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    auth_req = (hmac_auth_req_stru *)msg;

#ifdef _PRE_WLAN_FEATURE_SAE
    if ((mac_mib_get_AuthenticationMode(&(hmac_sta->st_vap_base_info)) == WLAN_WITP_AUTH_SAE ||
        mac_mib_get_AuthenticationMode(&(hmac_sta->st_vap_base_info)) == WLAN_WITP_AUTH_TBPEKE)
        && (hmac_sta->bit_sae_connect_with_pmkid == OAL_FALSE)) {
        ret = hmac_sta_sae_connect_info_wpas(hmac_sta, auth_req);
        return ret;
    }
#endif

    /* 申请认证帧空间 */
    auth_frame = oal_mem_netbuf_alloc(OAL_NORMAL_NETBUF, WLAN_MEM_NETBUF_SIZE2, OAL_NETBUF_PRIORITY_MID);
    if (auth_frame == NULL) {
        oam_error_log0(hmac_sta->st_vap_base_info.uc_vap_id, OAM_SF_AUTH, "{hmac_wait_auth_sta::puc_auth_frame null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    oal_mem_netbuf_trace(auth_frame, OAL_TRUE);

    memset_s(oal_netbuf_cb(auth_frame), oal_netbuf_cb_size(), 0, oal_netbuf_cb_size());

    memset_s((uint8_t *)oal_netbuf_header(auth_frame), MAC_80211_FRAME_LEN, 0, MAC_80211_FRAME_LEN);

    /* 组seq = 1 的认证请求帧 */
    ret = hmac_sta_assemble_auth_seq1(hmac_sta, auth_req, auth_frame);
    if (ret != OAL_SUCC) {
        return ret;
    }

    return OAL_SUCC;
}

#ifdef _PRE_WLAN_WAKEUP_SRC_PARSE
void wlan_pm_wkup_src_debug(hmac_vap_stru *pst_sta, uint8_t *puc_mac_hdr)
{
    if (OAL_TRUE == wlan_pm_wkup_src_debug_get()) {
        wlan_pm_wkup_src_debug_set(OAL_FALSE);
        oam_warning_log1(pst_sta->st_vap_base_info.uc_vap_id, OAM_SF_RX,
                         "{wifi_wake_src:hmac_sta_wait_auth_seq2_rx::wakeup mgmt type[0x%x]}",
                         mac_get_frame_type_and_subtype(puc_mac_hdr));
    }
}
#endif

void hmac_auth_alg_check(hmac_vap_stru *pst_sta, uint16_t us_auth_alg)
{
    if ((mac_mib_get_AuthenticationMode(&pst_sta->st_vap_base_info) != us_auth_alg)
        && (WLAN_WITP_AUTH_AUTOMATIC != mac_mib_get_AuthenticationMode(&pst_sta->st_vap_base_info))) {
        oam_warning_log2(pst_sta->st_vap_base_info.uc_vap_id, OAM_SF_AUTH,
                         "{hmac_sta_wait_auth_seq2_rx::rcv unexpected auth alg[%d/%d].}",
                         us_auth_alg, mac_mib_get_AuthenticationMode(&pst_sta->st_vap_base_info));
        /*  接收到auth 后，继续往下执行，避免vap 状态一直为WAIT_AUTH_SEQ2 */
    }
}

void hmac_auth_rsp_status_code_successful_handle(hmac_vap_stru *pst_sta, hmac_auth_rsp_stru* st_auth_rsp)
{
    oam_warning_log1(pst_sta->st_vap_base_info.uc_vap_id, OAM_SF_AUTH,
        "{hmac_sta_wait_auth_seq2_rx::AP refuse STA auth reason[%d]!}", st_auth_rsp->us_status_code);

    /*  收到seq = 2 的认证帧，并且正常处理，取消定时器 */
    frw_timer_immediate_destroy_timer_m(&pst_sta->st_mgmt_timer);

    /* 上报给SME认证结果 */
    hmac_send_rsp_to_sme_sta(pst_sta, HMAC_SME_AUTH_RSP, (uint8_t *)st_auth_rsp);

    if (st_auth_rsp->us_status_code != MAC_AP_FULL) {
        chr_exception(chr_wifi_drv(CHR_WIFI_DRV_EVENT_CONNECT, CHR_WIFI_DRV_ERROR_AUTH_REJECTED));
    }
}

uint32_t hmac_sta_send_auth_seq2(hmac_vap_stru *pst_sta, hmac_auth_rsp_stru *st_auth_rsp)
{
    /*  收到seq = 2 的认证帧，并且正常处理，取消定时器 */
    frw_timer_immediate_destroy_timer_m(&pst_sta->st_mgmt_timer);

    /* 将状态更改为AUTH_COMP */
    hmac_fsm_change_state(pst_sta, MAC_VAP_STATE_STA_AUTH_COMP);
    st_auth_rsp->us_status_code = HMAC_MGMT_SUCCESS;

    /* 上报给SME认证成功 */
    hmac_send_rsp_to_sme_sta(pst_sta, HMAC_SME_AUTH_RSP, (uint8_t *)st_auth_rsp);
    return OAL_SUCC;
}

/*
 * 函 数 名  : hmac_sta_wait_auth_seq2_rx
 * 功能描述  : 处理接收到seq num 等于2 的认证帧
 * 1.日    期  : 2013年6月27日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_sta_wait_auth_seq2_rx(hmac_vap_stru *pst_sta, void *pst_msg)
{
    dmac_wlan_crx_event_stru *pst_crx_event = NULL;
    mac_rx_ctl_stru *rx_ctl = NULL; /* 每一个MPDU的控制信息 */
    uint8_t *puc_mac_hdr = NULL;
    uint8_t *payload = NULL;
    uint16_t payload_len;
    uint16_t us_auth_alg;
    hmac_auth_rsp_stru st_auth_rsp = { { 0 }, };

    if (oal_any_null_ptr2(pst_sta, pst_msg)) {
        oam_error_log0(0, OAM_SF_AUTH, "{hmac_sta_wait_auth_seq2_rx::sta or msg is null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    pst_crx_event = (dmac_wlan_crx_event_stru *)pst_msg;
    rx_ctl = (mac_rx_ctl_stru *)oal_netbuf_cb(pst_crx_event->pst_netbuf); /* 每一个MPDU的控制信息 */
    if (rx_ctl == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }
    puc_mac_hdr = (uint8_t *)mac_get_rx_cb_mac_header_addr(rx_ctl);
    payload = mac_get_rx_payload(pst_crx_event->pst_netbuf, &payload_len);
    if (payload == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }
#ifdef _PRE_WLAN_WAKEUP_SRC_PARSE
    wlan_pm_wkup_src_debug(pst_sta, puc_mac_hdr);
#endif

    if ((WLAN_FC0_SUBTYPE_AUTH | WLAN_FC0_TYPE_MGT) != mac_get_frame_type_and_subtype(puc_mac_hdr)) {
        return OAL_SUCC;
    }

    us_auth_alg = mac_get_auth_alg(payload, payload_len);
#ifdef _PRE_WLAN_FEATURE_SAE
    /* 注意:mib 值中填写的auth_alg 值来自内核，和ieee定义的auth_alg取值不同 */
    if ((us_auth_alg == WLAN_MIB_AUTH_ALG_SAE || us_auth_alg == WLAN_MIB_AUTH_ALG_TBPEKE) &&
        (pst_sta->bit_sae_connect_with_pmkid == OAL_FALSE)) {
        return hmac_sta_process_sae_commit(pst_sta, pst_crx_event->pst_netbuf);
    }
#endif

    if (mac_get_auth_seq_num(payload, payload_len) != WLAN_AUTH_TRASACTION_NUM_TWO) {
        return OAL_SUCC;
    }

#if defined(_PRE_WLAN_FEATURE_SNIFFER) && defined(CONFIG_HW_SNIFFER)
    proc_sniffer_write_file(NULL, 0, puc_mac_hdr, rx_ctl->us_frame_len, 0);
#endif
    /* AUTH alg CHECK */
    hmac_auth_alg_check(pst_sta, us_auth_alg);
    st_auth_rsp.us_status_code = mac_get_auth_status(payload, payload_len);
    if (st_auth_rsp.us_status_code != MAC_SUCCESSFUL_STATUSCODE) {
        hmac_auth_rsp_status_code_successful_handle(pst_sta, &st_auth_rsp);
        return OAL_SUCC;
    }

    /* auth response status_code 处理 */
    if (us_auth_alg == WLAN_WITP_AUTH_SHARED_KEY) {
        return hmac_sta_send_auth_seq3(pst_sta, puc_mac_hdr, rx_ctl);
    }
    return hmac_sta_send_auth_seq2(pst_sta, &st_auth_rsp);
}

/*
 * 函 数 名  : hmac_sta_wait_auth_seq4_rx
 * 功能描述  : 处理收到seq = 4 的认证帧
 * 1.日    期  : 2013年6月28日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_sta_wait_auth_seq4_rx(hmac_vap_stru *pst_sta, void *p_msg)
{
    dmac_wlan_crx_event_stru *pst_crx_event = NULL;
    mac_rx_ctl_stru *rx_ctl = NULL; /* 每一个MPDU的控制信息 */
    uint8_t *mac_hdr = NULL;
    uint8_t *payload = NULL;
    uint16_t payload_len;
    hmac_auth_rsp_stru st_auth_rsp = { { 0 }, };

    if (oal_any_null_ptr2(pst_sta, p_msg)) {
        oam_error_log0(0, OAM_SF_AUTH, "{hmac_sta_wait_auth_seq4_rx::sta or msg is null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    pst_crx_event = (dmac_wlan_crx_event_stru *)p_msg;
    rx_ctl = (mac_rx_ctl_stru *)oal_netbuf_cb(pst_crx_event->pst_netbuf); /* 每一个MPDU的控制信息 */
    if (rx_ctl == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }
    payload = mac_get_rx_payload(pst_crx_event->pst_netbuf, &payload_len);
    if (payload == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }
    mac_hdr = (uint8_t *)mac_get_rx_cb_mac_header_addr(rx_ctl);

#ifdef _PRE_WLAN_WAKEUP_SRC_PARSE
    if (OAL_TRUE == wlan_pm_wkup_src_debug_get()) {
        wlan_pm_wkup_src_debug_set(OAL_FALSE);
        oam_warning_log1(pst_sta->st_vap_base_info.uc_vap_id, OAM_SF_RX,
            "wifi_wake_src:hmac_sta_wait_auth_seq4_rx:wakeup mgmt type 0x%x", mac_get_frame_type_and_subtype(mac_hdr));
    }
#endif

    if ((WLAN_FC0_SUBTYPE_AUTH | WLAN_FC0_TYPE_MGT) != mac_get_frame_type_and_subtype(mac_hdr)) {
        return OAL_SUCC;
    }

#ifdef _PRE_WLAN_FEATURE_SAE
    /* 注意:mib 值中填写的auth_alg 值来自内核，和ieee定义的auth_alg取值不同 */
    if (((mac_get_auth_alg(payload, payload_len) == WLAN_MIB_AUTH_ALG_SAE) ||
        (mac_get_auth_alg(payload, payload_len) == WLAN_MIB_AUTH_ALG_TBPEKE)) &&
        (pst_sta->bit_sae_connect_with_pmkid == OAL_FALSE)) {
        return hmac_sta_process_sae_confirm(pst_sta, pst_crx_event->pst_netbuf);
    }
#endif

#ifdef _PRE_WLAN_FEATURE_SNIFFER
#ifdef CONFIG_HW_SNIFFER
        proc_sniffer_write_file(NULL, 0, mac_hdr, rx_ctl->us_frame_len, 0);
#endif
#endif
    if ((mac_get_auth_seq_num(payload, payload_len) == WLAN_AUTH_TRASACTION_NUM_FOUR) &&
        (mac_get_auth_status(payload, payload_len) == MAC_SUCCESSFUL_STATUSCODE)) {
        /* 接收到seq = 4 且状态位为succ 取消定时器 */
        frw_timer_immediate_destroy_timer_m(&pst_sta->st_mgmt_timer);
        st_auth_rsp.us_status_code = HMAC_MGMT_SUCCESS;
        /* 更改sta状态为MAC_VAP_STATE_STA_AUTH_COMP */
        hmac_fsm_change_state(pst_sta, MAC_VAP_STATE_STA_AUTH_COMP);
        /* 将认证结果上报SME */
        hmac_send_rsp_to_sme_sta(pst_sta, HMAC_SME_AUTH_RSP, (uint8_t *)&st_auth_rsp);
    } else {
        oam_warning_log1(pst_sta->st_vap_base_info.uc_vap_id, OAM_SF_AUTH,
            "{hmac_sta_wait_auth_seq4_rx::transaction num.status[%d]}", mac_get_auth_status(payload, payload_len));
        /* 等待定时器超时 */
    }
    return OAL_SUCC;
}

uint32_t hmac_sta_wait_asoc_check_frame_len(hmac_vap_stru *sta, uint32_t asoc_frame_len,
    oal_netbuf_stru *asoc_req_frame)
{
    if (oal_unlikely(asoc_frame_len < OAL_ASSOC_REQ_IE_OFFSET)) {
        oam_error_log1(sta->st_vap_base_info.uc_vap_id, OAM_SF_ASSOC,
                       "{hmac_sta_wait_asoc::invalid asoc_req_ie_len[%u].}",
                       asoc_frame_len);
        oam_report_dft_params(BROADCAST_MACADDR, (uint8_t *)oal_netbuf_header(asoc_req_frame),
            (uint16_t)asoc_frame_len, OAM_OTA_TYPE_80211_FRAME);
        return OAL_FAIL;
    }
    return OAL_SUCC;
}

uint32_t hmac_sta_wait_asoc_process_ie(hmac_vap_stru *sta, hmac_user_stru *hmac_user_ap, uint32_t asoc_frame_len,
    oal_netbuf_stru *asoc_req_frame)
{
    uint32_t ret;
    hmac_user_free_asoc_req_ie(sta->st_vap_base_info.us_assoc_vap_id);
    ret = hmac_user_set_asoc_req_ie(hmac_user_ap,
                                    oal_netbuf_header(asoc_req_frame) + OAL_ASSOC_REQ_IE_OFFSET,
                                    asoc_frame_len - OAL_ASSOC_REQ_IE_OFFSET,
                                    (uint8_t)(sta->bit_reassoc_flag));
    if (ret != OAL_SUCC) {
        oam_error_log0(sta->st_vap_base_info.uc_vap_id, OAM_SF_ASSOC, "{hmac_sta_wait_asoc::hmac__asoc_req_ie failed}");
    }
    return ret;
}

uint32_t hmac_sta_wait_asoc_process_send_event(hmac_vap_stru *sta, oal_netbuf_stru *asoc_req_frame,
    uint32_t asoc_frame_len)
{
    uint32_t ret;
    ret = hmac_tx_mgmt_send_event(&(sta->st_vap_base_info), asoc_req_frame, (uint16_t)asoc_frame_len);
    if (ret != OAL_SUCC) {
        hmac_user_free_asoc_req_ie(sta->st_vap_base_info.us_assoc_vap_id);
        oam_warning_log1(sta->st_vap_base_info.uc_vap_id, OAM_SF_ASSOC,
                         "{hmac_sta_wait_asoc::hmac_tx_mgmt_send_event failed[%d].}", ret);
    }
    return ret;
}

void hmac_sta_wait_asoc_set_tx_ctl(oal_netbuf_stru *asoc_req_frame, uint32_t asoc_frame_len,
    hmac_user_stru *hmac_user_ap)
{
    mac_tx_ctl_stru *tx_ctl = NULL;
    tx_ctl = (mac_tx_ctl_stru *)oal_netbuf_cb(asoc_req_frame);

    mac_get_cb_mpdu_len(tx_ctl) = (uint16_t)asoc_frame_len;
    mac_get_cb_tx_user_idx(tx_ctl) = hmac_user_ap->st_user_base_info.us_assoc_id;
}

void hmac_sta_wait_asoc_timeout_timer_handle(hmac_vap_stru *sta, hmac_user_stru *hmac_user_ap,
    hmac_asoc_req_stru *hmac_asoc_req)
{
    /* 启动关联超时定时器, 为对端ap分配一个定时器，如果超时ap没回asoc rsp则启动超时处理 */
    sta->st_mgmt_timetout_param.en_state = MAC_VAP_STATE_STA_WAIT_ASOC;
    sta->st_mgmt_timetout_param.us_user_index = hmac_user_ap->st_user_base_info.us_assoc_id;
    sta->st_mgmt_timetout_param.uc_vap_id = sta->st_vap_base_info.uc_vap_id;
    sta->st_mgmt_timetout_param.en_status_code = MAC_ASOC_RSP_TIMEOUT;

    frw_timer_create_timer_m(&(sta->st_mgmt_timer), hmac_mgmt_timeout_sta, hmac_asoc_req->us_assoc_timeout,
        &(sta->st_mgmt_timetout_param), OAL_FALSE, OAM_MODULE_ID_HMAC, sta->st_vap_base_info.core_id);
}

/*
 * 函 数 名  : hmac_sta_wait_asoc
 * 功能描述  : 在AUTH_COMP状态接收到SME发过来的ASOC_REQ请求，将STA状态设置为WAIT_ASOC,
 * 1.日    期  : 2013年6月27日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_sta_wait_asoc(hmac_vap_stru *sta, void *msg)
{
    hmac_asoc_req_stru *hmac_asoc_req = (hmac_asoc_req_stru *)msg;
    oal_netbuf_stru *asoc_req_frame = NULL;
    hmac_user_stru *hmac_user_ap = NULL;
    uint32_t asoc_frame_len, ret;
    uint8_t *curr_bssid = NULL;

    if (oal_any_null_ptr2(sta, msg)) {
        oam_error_log0(0, OAM_SF_ASSOC, "{hmac_sta_wait_asoc::sta or msg is null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    hmac_user_ap = (hmac_user_stru *)mac_res_get_hmac_user(sta->st_vap_base_info.us_assoc_vap_id);
    if (hmac_user_ap == NULL) {
        oam_error_log0(sta->st_vap_base_info.uc_vap_id, OAM_SF_ASSOC, "{hmac_sta_wait_asoc::hmac_user_ap null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    asoc_req_frame = oal_mem_netbuf_alloc(OAL_NORMAL_NETBUF, WLAN_MEM_NETBUF_SIZE2, OAL_NETBUF_PRIORITY_MID);
    if (asoc_req_frame == NULL) {
        oam_error_log0(sta->st_vap_base_info.uc_vap_id, OAM_SF_ASSOC, "{hmac_sta_wait_asoc::asoc_req_frame null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }
    oal_mem_netbuf_trace(asoc_req_frame, OAL_TRUE);
    memset_s(oal_netbuf_cb(asoc_req_frame), oal_netbuf_cb_size(), 0, oal_netbuf_cb_size());
    /* 将mac header清零 */
    memset_s((uint8_t *)oal_netbuf_header(asoc_req_frame), MAC_80211_FRAME_LEN, 0, MAC_80211_FRAME_LEN);

    /* 组帧 (Re)Assoc_req_Frame */
    curr_bssid = (sta->bit_reassoc_flag) ? sta->st_vap_base_info.auc_bssid : NULL;
    asoc_frame_len = hmac_mgmt_encap_asoc_req_sta(sta, (uint8_t *)(oal_netbuf_header(asoc_req_frame)),
        curr_bssid, sta->st_vap_base_info.auc_bssid);
    if (asoc_frame_len == 0) {
        oam_warning_log0(sta->st_vap_base_info.uc_vap_id, OAM_SF_ASSOC, "{hmac_sta_wait_asoc::encap_asoc_req null}");
        oal_netbuf_free(asoc_req_frame);
        return OAL_FAIL;
    }
    oal_netbuf_put(asoc_req_frame, asoc_frame_len);

    if (hmac_sta_wait_asoc_check_frame_len(sta, asoc_frame_len, asoc_req_frame) != OAL_SUCC) {
        oal_netbuf_free(asoc_req_frame);
        return OAL_FAIL;
    }

    if (hmac_sta_wait_asoc_process_ie(sta, hmac_user_ap, asoc_frame_len, asoc_req_frame) != OAL_SUCC) {
        oal_netbuf_free(asoc_req_frame);
        return OAL_FAIL;
    }

    hmac_sta_wait_asoc_set_tx_ctl(asoc_req_frame, asoc_frame_len, hmac_user_ap);

    /* 抛事件让DMAC将该帧发送 */
    ret = hmac_sta_wait_asoc_process_send_event(sta, asoc_req_frame, asoc_frame_len);
    if (ret != OAL_SUCC) {
        oal_netbuf_free(asoc_req_frame);
        return ret;
    }

    /* 更改状态 */
    hmac_fsm_change_state(sta, MAC_VAP_STATE_STA_WAIT_ASOC);

    /* 启动关联超时定时器, 为对端ap分配一个定时器，如果超时ap没回asoc rsp则启动超时处理 */
    hmac_sta_wait_asoc_timeout_timer_handle(sta, hmac_user_ap, hmac_asoc_req);

    return OAL_SUCC;
}


/*
 * 函 数 名  : hmac_p2p_listen_comp_cb
 * 功能描述  : P2P 监听超时处理函数
 * 1.日    期  : 2015年5月29日
  *   修改内容  : 新生成函数
 */
void hmac_p2p_listen_comp_cb(void *p_arg)
{
    hmac_vap_stru *pst_hmac_vap = NULL;
    mac_device_stru *pst_mac_device = NULL;
    hmac_scan_record_stru *pst_scan_record;

    pst_scan_record = (hmac_scan_record_stru *)p_arg;

    /* 判断listen完成时的状态 */
    if ((pst_scan_record->en_scan_rsp_status != MAC_SCAN_SUCCESS) &&
        (!hmac_get_feature_switch(HMAC_MIRACAST_REDUCE_LOG_SWITCH))) {
        oam_warning_log1(0, OAM_SF_P2P, "{hmac_p2p_listen_comp_cb::listen failed, listen rsp status: %d.}",
                         pst_scan_record->en_scan_rsp_status);
    }

    pst_hmac_vap = mac_res_get_hmac_vap(pst_scan_record->uc_vap_id);
    if (pst_hmac_vap == NULL) {
        oam_error_log1(0, OAM_SF_P2P, "{hmac_p2p_listen_comp_cb::pst_hmac_vap is null:vap_id %d.}",
                       pst_scan_record->uc_vap_id);
        return;
    }

    pst_mac_device = mac_res_get_dev(pst_scan_record->uc_device_id);
    if (pst_mac_device == NULL) {
        oam_error_log1(0, OAM_SF_P2P, "{hmac_p2p_listen_comp_cb::pst_mac_device is null:vap_id %d.}",
                       pst_scan_record->uc_device_id);
        return;
    }
    /* ull_last_roc_id在P2P listen命令下发时就已经+1了,所以判断是否为同一个p2p listen扫描要ull_cookie + 1 */
    if ((pst_scan_record->ull_cookie + 1) == pst_mac_device->st_p2p_info.ull_last_roc_id) {
        /* 状态机调用: hmac_p2p_listen_timeout */
        if (hmac_fsm_call_func_sta(pst_hmac_vap, HMAC_FSM_INPUT_LISTEN_TIMEOUT, &(pst_hmac_vap->st_vap_base_info)) !=
            OAL_SUCC) {
            oam_warning_log0(0, OAM_SF_P2P, "{hmac_p2p_listen_comp_cb::hmac_fsm_call_func_sta fail.}");
        }
    } else {
        oam_warning_log3(pst_hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_P2P,
            "{hmac_p2p_listen_comp_cb::ignore listen complete.scan_report_cookie[%x], \
            current_listen_cookie[%x], ull_last_roc_id[%x].}",
            pst_scan_record->ull_cookie,
            pst_mac_device->st_scan_params.ull_cookie,
            pst_mac_device->st_p2p_info.ull_last_roc_id);
    }

    return;
}
/*
 * 函 数 名  : hmac_mgmt_tx_roc_comp_cb
 * 功能描述  : P2P 监听超时处理函数
 * 1.日    期  : 2017年07月19日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void hmac_mgmt_tx_roc_comp_cb(void *p_arg)
{
    hmac_vap_stru *pst_hmac_vap = NULL;
    mac_device_stru *pst_mac_device = NULL;
    hmac_scan_record_stru *pst_scan_record;

    pst_scan_record = (hmac_scan_record_stru *)p_arg;

    /* 判断listen完成时的状态 */
    if (pst_scan_record->en_scan_rsp_status != MAC_SCAN_SUCCESS) {
        oam_warning_log1(0, OAM_SF_P2P, "{hmac_mgmt_tx_roc_comp_cb::listen failed, listen rsp status: %d.}",
                         pst_scan_record->en_scan_rsp_status);
    }

    pst_hmac_vap = mac_res_get_hmac_vap(pst_scan_record->uc_vap_id);
    if (pst_hmac_vap == NULL) {
        oam_error_log1(0, OAM_SF_P2P, "{hmac_mgmt_tx_roc_comp_cb::pst_hmac_vap is null:vap_id %d.}",
                       pst_scan_record->uc_vap_id);
        return;
    }

    pst_mac_device = mac_res_get_dev(pst_scan_record->uc_device_id);
    if (pst_mac_device == NULL) {
        oam_error_log1(pst_hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_P2P,
                       "{hmac_mgmt_tx_roc_comp_cb::pst_mac_device is null:vap_id %d.}",
                       pst_scan_record->uc_device_id);
        return;
    }

    /* 由于P2P0 和P2P_CL 共用vap 结构体，监听超时，返回监听前保存的状态 */
    /*  p2p listen同步vap状态与背景扫描冲突，不同步到dmac */
    /* ,已经提前入网状态，不能打断，防止出现后续扫描和入网异常 */
    /*  wlan0 也可能进入监听模式 */
    if (pst_hmac_vap->st_vap_base_info.en_vap_state >= MAC_VAP_STATE_STA_JOIN_COMP &&
        pst_hmac_vap->st_vap_base_info.en_vap_state <= MAC_VAP_STATE_STA_WAIT_ASOC) {
        oam_warning_log0(pst_hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_P2P,
                         "{hmac_mgmt_tx_roc_comp_cb::vap is connecting, can not change vap state.}");
    } else if (pst_hmac_vap->st_vap_base_info.en_vap_state == MAC_VAP_STATE_STA_FAKE_UP) {
        oam_warning_log0(pst_hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_P2P,
                         "{hmac_mgmt_tx_roc_comp_cb::vap is fake up, can not change vap state.}");
    } else if (pst_hmac_vap->st_vap_base_info.en_p2p_mode != WLAN_LEGACY_VAP_MODE) {
        mac_vap_state_change(&pst_hmac_vap->st_vap_base_info, pst_mac_device->st_p2p_info.en_last_vap_state);
    } else {
        mac_vap_state_change(&pst_hmac_vap->st_vap_base_info, pst_hmac_vap->st_vap_base_info.en_last_vap_state);
    }
    oam_warning_log0(pst_hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_P2P, "{hmac_mgmt_tx_roc_comp_cb}");
}

/*
 * 函 数 名  : hmac_cfg80211_prepare_listen_req_param
 * 功能描述  : 准备p2p监听请求的对应参数
 * 1.日    期  : 2015年5月29日
  *   修改内容  : 新生成函数
 */
OAL_STATIC void hmac_cfg80211_prepare_listen_req_param(mac_scan_req_stru *pst_scan_params,
    hmac_remain_on_channel_param_stru *pst_remain_on_channel)
{
    mac_channel_stru *pst_channel_tmp = NULL;
    uint16_t channel_center_freq;

    channel_center_freq = pst_remain_on_channel->st_listen_channel.center_freq;

    /* 设置监听信道信息到扫描参数中 */
    if (channel_center_freq >= 5925 && channel_center_freq <= 7115) { // [5925, 7115]: 中心频点是否在6G频段
        pst_scan_params->ast_channel_list[0].ext6g_band = OAL_TRUE;
    } else {
        pst_scan_params->ast_channel_list[0].ext6g_band = OAL_FALSE;
    }
    pst_scan_params->ast_channel_list[0].en_band = pst_remain_on_channel->en_band;
    pst_scan_params->ast_channel_list[0].en_bandwidth = pst_remain_on_channel->en_listen_channel_type;
    pst_scan_params->ast_channel_list[0].uc_chan_number = pst_remain_on_channel->uc_listen_channel;
    pst_scan_params->ast_channel_list[0].uc_chan_idx = 0;
    pst_channel_tmp = &(pst_scan_params->ast_channel_list[0]);
    if (mac_get_channel_idx_from_num(pst_channel_tmp->en_band, pst_channel_tmp->uc_chan_number,
        pst_channel_tmp->ext6g_band, &(pst_channel_tmp->uc_chan_idx)) != OAL_SUCC) {
        oam_warning_log2(0, OAM_SF_P2P,
            "{hmac_cfg80211_prepare_listen_req_param::mac_get_channel_idx_from_num fail.band[%u] channel[%u]}",
            pst_channel_tmp->en_band, pst_channel_tmp->uc_chan_number);
    }

    /* 设置其它监听参数 */
    pst_scan_params->uc_max_scan_count_per_channel = 1;
    pst_scan_params->uc_channel_nums = 1;
    pst_scan_params->uc_scan_func = MAC_SCAN_FUNC_P2P_LISTEN;
    pst_scan_params->us_scan_time = (uint16_t)pst_remain_on_channel->listen_duration;
    if ((pst_remain_on_channel->en_roc_type == IEEE80211_ROC_TYPE_MGMT_TX) ||
        (pst_remain_on_channel->en_roc_type == IEEE80211_ROC_TYPE_HIGH_PRIO_MGMT_TX)) {
        pst_scan_params->p_fn_cb = hmac_mgmt_tx_roc_comp_cb;
        pst_scan_params->bit_is_special_roc_type = OAL_TRUE;
    } else if (pst_remain_on_channel->en_roc_type == IEEE80211_ROC_TYPE_HIGH_PRIO_MGMT_RX) {
        pst_scan_params->p_fn_cb = hmac_p2p_listen_comp_cb;
        pst_scan_params->bit_is_special_roc_type = OAL_TRUE;
    } else {
        pst_scan_params->p_fn_cb = hmac_p2p_listen_comp_cb;
        pst_scan_params->bit_is_special_roc_type = OAL_FALSE;
    }

    pst_scan_params->en_scan_mode = WLAN_SCAN_MODE_MGMT_TX;
    pst_scan_params->ull_cookie = pst_remain_on_channel->ull_cookie;
    pst_scan_params->bit_is_p2p0_scan = OAL_TRUE;
    pst_scan_params->uc_p2p0_listen_channel = pst_remain_on_channel->uc_listen_channel;

    return;
}

/*
 * 函 数 名  : hmac_p2p_listen_timeout
 * 功能描述  : P2P_DEVICE 监听超时
 * 1.日    期  : 2014年11月24日
  *   修改内容  : 新生成函数
 */
uint32_t hmac_p2p_listen_timeout(hmac_vap_stru *pst_hmac_vap_sta, void *p_param)
{
    mac_device_stru *pst_mac_device = NULL;
    hmac_vap_stru *pst_hmac_vap;
    mac_vap_stru *pst_mac_vap;
    hmac_device_stru *pst_hmac_device = NULL;
    hmac_scan_record_stru *pst_scan_record = NULL;

    pst_mac_vap = (mac_vap_stru *)p_param;
    pst_hmac_vap = mac_res_get_hmac_vap(pst_mac_vap->uc_vap_id);
    if (pst_hmac_vap == NULL) {
        oam_error_log1(0, OAM_SF_P2P, "{hmac_p2p_listen_timeout::mac_res_get_hmac_vap fail.vap_id[%u]!}",
                       pst_mac_vap->uc_vap_id);
        return OAL_ERR_CODE_PTR_NULL;
    }
    pst_mac_device = mac_res_get_dev(pst_mac_vap->uc_device_id);
    if (pst_mac_device == NULL) {
        oam_warning_log1(0, OAM_SF_P2P, "{hmac_p2p_listen_timeout::mac_res_get_dev fail.device_id[%u]!}",
                         pst_mac_vap->uc_device_id);
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* 获取hmac device */
    pst_hmac_device = hmac_res_get_mac_dev(pst_mac_device->uc_device_id);
    if (oal_unlikely(pst_hmac_device == NULL)) {
        oam_error_log0(0, OAM_SF_P2P, "{hmac_p2p_listen_timeout::pst_hmac_device null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* 由于P2P0 和P2P_CL 共用vap 结构体，监听超时，返回监听前保存的状态 */
    /*  p2p listen同步vap状态与背景扫描冲突，不同步到dmac */
    if (pst_hmac_vap->st_vap_base_info.en_p2p_mode != WLAN_LEGACY_VAP_MODE) {
        mac_vap_state_change(&pst_hmac_vap->st_vap_base_info, pst_mac_device->st_p2p_info.en_last_vap_state);
    } else {
        mac_vap_state_change(&pst_hmac_vap->st_vap_base_info, pst_hmac_vap->st_vap_base_info.en_last_vap_state);
    }

    pst_scan_record = &(pst_hmac_device->st_scan_mgmt.st_scan_record_mgmt);
    /* ull_last_roc_id在P2P listen命令下发时就已经+1了,所以判断是否为同一个p2p listen扫描要ull_cookie + 1 */
    if ((pst_scan_record->ull_cookie + 1) == pst_mac_device->st_p2p_info.ull_last_roc_id) {
        /* 3.1 抛事件到WAL ，上报监听结束 */
        hmac_p2p_send_listen_expired_to_host(pst_hmac_vap);
    }

    /* 3.2 抛事件到DMAC ，返回监听信道 */
    hmac_p2p_send_listen_expired_to_device(pst_hmac_vap);

    return OAL_SUCC;
}

/*
 * 函 数 名  : hmac_p2p_remain_on_channel
 * 功能描述  : 设置device 到指定信道监听，并设置监听超时定时器
 * 1.日    期  : 2014年11月24日
  *   修改内容  : 新生成函数
 */
uint32_t hmac_p2p_remain_on_channel(hmac_vap_stru *pst_hmac_vap_sta, void *p_param)
{
    mac_device_stru *pst_mac_device = NULL;
    mac_vap_stru *pst_mac_vap;
    hmac_remain_on_channel_param_stru *pst_remain_on_channel;
    mac_scan_req_h2d_stru st_scan_h2d_params;
    uint32_t ret;

    pst_remain_on_channel = (hmac_remain_on_channel_param_stru *)p_param;

    pst_mac_vap = mac_res_get_mac_vap(pst_hmac_vap_sta->st_vap_base_info.uc_vap_id);
    if (pst_mac_vap == NULL) {
        oam_error_log1(0, OAM_SF_P2P, "{hmac_p2p_remain_on_channel::mac_res_get_mac_vap fail.vap_id[%u]!}",
                       pst_hmac_vap_sta->st_vap_base_info.uc_vap_id);
        return OAL_ERR_CODE_PTR_NULL;
    }
    pst_mac_device = mac_res_get_dev(pst_mac_vap->uc_device_id);
    if (oal_unlikely(pst_mac_device == NULL)) {
        oam_error_log1(0, OAM_SF_ANY,
            "{hmac_p2p_listen_timeout::pst_mac_device[%d](%d) null!}", pst_mac_vap->uc_device_id);
        return OAL_ERR_CODE_PTR_NULL;
    }

    /*  设置P2P 监听超时定时器,
        P2P处于Listen状态下无法下发监听命令，导致Listen状态下不能重新出发监听，无法与商用设备关联 */
    if (pst_hmac_vap_sta->st_vap_base_info.en_vap_state == MAC_VAP_STATE_STA_LISTEN) {
        hmac_p2p_send_listen_expired_to_host(pst_hmac_vap_sta);
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_P2P,
            "{hmac_p2p_remain_on_channel::listen nested, send remain on channel expired to host!curr_state[%d]}",
            pst_hmac_vap_sta->st_vap_base_info.en_vap_state);
    }

    /* 修改P2P_DEVICE 状态为监听状态 */
    /*
     *  P2P监听状态与背景扫描时DMAC的pause状态冲突，
     * P2P_LISTEN状态不同步到DMAC去，DMAC不再使用P2P_LISTEN状态
     */
    mac_vap_state_change((mac_vap_stru *)&pst_hmac_vap_sta->st_vap_base_info, MAC_VAP_STATE_STA_LISTEN);
    oam_info_log4(pst_mac_vap->uc_vap_id, OAM_SF_P2P,
        "{hmac_p2p_remain_on_channel: get in listen state!last_state %d, channel %d, duration %d, curr_state %d}",
        pst_mac_device->st_p2p_info.en_last_vap_state,
        pst_remain_on_channel->uc_listen_channel,
        pst_remain_on_channel->listen_duration,
        pst_hmac_vap_sta->st_vap_base_info.en_vap_state);

    /* 准备监听参数 */
    memset_s(&st_scan_h2d_params, sizeof(mac_scan_req_h2d_stru), 0, sizeof(mac_scan_req_h2d_stru));
    hmac_cfg80211_prepare_listen_req_param(&(st_scan_h2d_params.st_scan_params), pst_remain_on_channel);

    /* 调用扫描入口，准备进行监听动作，不管监听动作执行成功或失败，都返回监听成功 */
    /* 状态机调用: hmac_scan_proc_scan_req_event */
    ret = hmac_fsm_call_func_sta(pst_hmac_vap_sta, HMAC_FSM_INPUT_SCAN_REQ, (void *)(&st_scan_h2d_params));
    if (ret != OAL_SUCC) {
        oam_warning_log1(0, OAM_SF_SCAN,
            "{hmac_p2p_remain_on_channel::hmac_fsm_call_func_sta fail[%d].}", ret);
        if (hmac_get_feature_switch(HMAC_MIRACAST_SINK_SWITCH)) {
            /* 大屏需要持续侦听，在下发侦听失败后，需通知wpas恢复P2P状态为IDLE，以便后续能再次进入侦听流程  */
            return ret;
        }
    }

    return OAL_SUCC;
}
