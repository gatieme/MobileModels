/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * 功能说明 : hmac_dbac.c
 * 作    者 : wifi
 * 创建日期 : 2019年12月25日
 */

#include "hmac_dbac.h"
#include "mac_ie.h"
#include "mac_device.h"
#include "wlan_types.h"
#include "hmac_chan_mgmt.h"
#ifdef _PRE_WLAN_CHBA_MGMT
#include "hmac_chba_channel_sequence.h"
#include "hmac_chba_coex.h"
#include "hmac_chba_chan_switch.h"
#endif

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_DBAC_C

#define DBAC_RUNING_HANDLE_TIMEOUT 30000 /* 30秒 */
#define HMAC_DBAC_GO_CSA_COUNT 5

hmac_dbac_handle_stru g_st_hmac_dbac_handle_info;

static oal_bool_enum_uint8 hmac_vap_get_enable_ap_follow_channel_flag(mac_vap_stru *mac_vap);

/*
 * 函 数 名  : hmac_dbac_ap_csa_handle
 * 功能描述  : go/ap切到sta 同信道，带宽保持原go带宽不变
 * 1.日    期  : 2019年12月27日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC void hmac_dbac_ap_csa_handle(mac_vap_stru *csa_vap, mac_channel_stru *csa_channel)
{
    wlan_bw_cap_enum_uint8 en_bw_cap;
    wlan_channel_bandwidth_enum_uint8 en_go_new_bw;

    if (csa_channel->en_band != csa_vap->st_channel.en_band) {
        oam_warning_log2(0, OAM_SF_DBAC, "{hmac_dbac_ap_csa_handle::\
            legacy_band=[%d], go_band=[%d], not handle}", csa_channel->en_band,
            csa_vap->st_channel.en_band);
        return;
    }

    if (csa_channel->uc_chan_number == csa_vap->st_channel.uc_chan_number) {
        oam_warning_log2(0, OAM_SF_DBAC,
            "{hmac_dbac_ap_csa_handle::legacy_channel=[%d], go_channel=[%d], not handle}",
            csa_channel->uc_chan_number,
            csa_vap->st_channel.uc_chan_number);
        return;
    }

    /* sta+go DBAC,禁止sta工作在雷达信道，go跟随到雷达信道
     * go如果跟随sta信道，需要wpa_s支持P2P工作在雷达信道，oh wpa_s不支持p2p工作在雷达信道
     */
    if (mac_is_dfs_channel(csa_channel->en_band, csa_channel->uc_chan_number) == OAL_TRUE) {
        oam_warning_log1(0, OAM_SF_DBAC, "{hmac_dbac_ap_csa_handle::[%d] is dfs channel, not handle}",
            csa_channel->uc_chan_number);
        return;
    }

    en_bw_cap = mac_vap_bw_mode_to_bw(csa_vap->st_channel.en_bandwidth);
    en_go_new_bw = mac_regdomain_get_bw_by_channel_bw_cap(csa_channel->uc_chan_number, en_bw_cap);

    oam_warning_log4(0, OAM_SF_DBAC,
        "{hmac_dbac_ap_csa_handle::go channel from [%d][%d] to [%d][%d]}",
        csa_vap->st_channel.uc_chan_number,
        csa_vap->st_channel.en_bandwidth,
        csa_channel->uc_chan_number, en_go_new_bw);

    csa_vap->st_ch_switch_info.uc_ch_switch_cnt = HMAC_DBAC_GO_CSA_COUNT;
    csa_vap->st_ch_switch_info.en_csa_mode      = WLAN_CSA_MODE_TX_ENABLE;
    hmac_chan_initiate_switch_to_new_channel(csa_vap, csa_channel->uc_chan_number, en_go_new_bw);
}

static mac_dbac_vap_mode_enum hmac_parse_vap_mode_for_dbac(mac_vap_stru *mac_vap)
{
    /* 解析的顺序chba > P2P > 传统 */
    if (mac_is_chba_mode(mac_vap) == OAL_TRUE) {
        return CHBA_VAP_MODE;
    } else if (mac_vap->en_p2p_mode == WLAN_P2P_GO_MODE) {
        return P2P_GO_MODE;
    } else if (mac_vap->en_p2p_mode == WLAN_P2P_CL_MODE) {
        return P2P_GC_MODE;
    } else if (mac_vap->en_vap_mode == WLAN_VAP_MODE_BSS_STA) {
        return LEGACY_STA_MODE;
    } else if (mac_vap->en_vap_mode == WLAN_VAP_MODE_BSS_AP) {
        return LEGACY_AP_MODE;
    } else {
        return VAP_MODE_BUTT;
    }
}

/* 功能描述: 获取两vap dbac配置 */
static oal_bool_enum_uint8 hmac_dbac_vap_mode_is_support_chan_follow(mac_vap_stru *keep_chan_vap,
    mac_vap_stru *follow_chan_vap)
{
    /* 现不支持双p2p dbac场景, 不存在gc+go dbac之类的场景, 因此双p2p dbac场景配置为OAL_FALSE
       只有5种场景支持跟随: chba+go / chba+ap / gc+ap / sta+go / sta+ap，其他场景均不发起跟随 */
    oal_bool_enum_uint8 dbac_support_channel_follow[VAP_MODE_BUTT][VAP_MODE_BUTT] = {
        [CHBA_VAP_MODE] = /* chba+chba, chba+go, chba+gc, chba+sta, chba+ap */
            { OAL_FALSE, OAL_TRUE, OAL_FALSE, OAL_FALSE, OAL_TRUE },
        [P2P_GO_MODE] = /* go+chba, go+go, go+gc, go+sta, go+ap */
            { OAL_FALSE, OAL_FALSE, OAL_FALSE, OAL_FALSE, OAL_FALSE },
        [P2P_GC_MODE] = /* gc+chba, gc+go, gc+gc, gc+sta, gc+ap */
            { OAL_FALSE, OAL_FALSE, OAL_FALSE, OAL_FALSE, OAL_TRUE },
        [LEGACY_STA_MODE] = /* sta+chba, sta+go, sta+gc, sta+sta, sta+ap */
            { OAL_FALSE, OAL_TRUE, OAL_FALSE, OAL_FALSE, OAL_TRUE },
        [LEGACY_AP_MODE]  = /* ap+chba, ap+go, ap+gc, ap+sta, ap+ap */
            { OAL_FALSE, OAL_FALSE, OAL_FALSE, OAL_FALSE, OAL_FALSE },
    };
    mac_dbac_vap_mode_enum keep_chan_vap_mode = hmac_parse_vap_mode_for_dbac(keep_chan_vap);
    mac_dbac_vap_mode_enum follow_chan_vap_mode = hmac_parse_vap_mode_for_dbac(follow_chan_vap);
    if (keep_chan_vap_mode >= VAP_MODE_BUTT || follow_chan_vap_mode >= VAP_MODE_BUTT) {
        oam_error_log2(0, OAM_SF_DBAC,
            "{hmac_dbac_vap_mode_is_support_chan_follow:[%d]/[%d](0:chba 1:go 2:gc 3:sta 4:ap), invalid vap mode!}",
            hmac_parse_vap_mode_for_dbac(keep_chan_vap), hmac_parse_vap_mode_for_dbac(follow_chan_vap));
        return OAL_FALSE;
    }

    return dbac_support_channel_follow[keep_chan_vap_mode][follow_chan_vap_mode];
}

/* 根据输入dbac 状态vap0，vap1，判断是否可信道跟随。若可信道跟随，则输出需要跟随的vap和目标信道 */
oal_bool_enum_uint8 hmac_dbac_get_channel_flow_info(mac_vap_stru *mac_vap0, mac_vap_stru *mac_vap1,
    mac_vap_stru **csa_vap, mac_channel_stru *csa_channel)
{
    if (hmac_dbac_vap_mode_is_support_chan_follow(mac_vap0, mac_vap1) == OAL_TRUE) {
        *csa_vap = mac_vap1;
        *csa_channel = mac_vap0->st_channel;
        return OAL_TRUE;
    } else if (hmac_dbac_vap_mode_is_support_chan_follow(mac_vap1, mac_vap0) == OAL_TRUE) {
        *csa_vap = mac_vap0;
        *csa_channel = mac_vap1->st_channel;
        return OAL_TRUE;
    }
    oam_warning_log2(0, OAM_SF_DBAC,
        "{hmac_dbac_get_channel_flow_info:[%d]/[%d](0:chba 1:go 2:gc 3:sta 4:ap), not support chan_flow}",
        hmac_parse_vap_mode_for_dbac(mac_vap0), hmac_parse_vap_mode_for_dbac(mac_vap1));
    return OAL_FALSE;
}

/*
 * 函 数 名  : hmac_change_sta_channel
 * 功能描述  : 30秒超时处理函数
               go 不存在时切换信道
 * 1.日    期  : 2019年12月27日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_dbac_ap_flow_other_vap_channel_handle(mac_device_stru *mac_device)
{
    mac_vap_stru *vap[WLAN_SERVICE_VAP_MAX_NUM_PER_DEVICE] = {NULL};
    mac_vap_stru *csa_vap = NULL;
    mac_channel_stru csa_channel = {0};

    if (!mac_is_dbac_running(mac_device)) {
        return OAL_SUCC;
    }
#ifdef _PRE_WLAN_CHBA_MGMT
    /* 如果当前存在3个vap，则不切换 */
    if ((g_optimized_feature_switch_bitmap & BIT(CUSTOM_OPTIMIZE_CHBA)) &&
        mac_device_calc_up_vap_num(mac_device) > TWO_UP_VAP_NUMS) {
            oam_warning_log1(0, OAM_SF_DBAC,
                "{hmac_dbac_ap_flow_other_vap_channel_handle:: find [%d]up vap > 2,return}",
                mac_device_calc_up_vap_num(mac_device));
            return OAL_SUCC;
        }
#endif
    if (mac_device_find_2up_vap(mac_device, &vap[0], &vap[1]) != OAL_SUCC) {
        oam_warning_log0(0, OAM_SF_DBAC, "{hmac_dbac_ap_flow_other_vap_channel_handle::not find 2up vap,return}");
        return OAL_SUCC;
    }

    if (vap[0] == NULL || vap[1] == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    if (hmac_dbac_get_channel_flow_info(vap[0], vap[1], &csa_vap, &csa_channel) == OAL_TRUE &&
        hmac_vap_get_enable_ap_follow_channel_flag(csa_vap) == OAL_TRUE) {
        hmac_dbac_ap_csa_handle(csa_vap, &csa_channel);
    } else {
        oam_warning_log1(0, OAM_SF_DBAC,
            "{hmac_dbac_ap_flow_other_vap_channel_handle::vap %d not channel follow.}",
            (csa_vap != NULL) ? csa_vap->uc_vap_id : 0);
    }

    return OAL_SUCC;
}

/*
 * 函 数 名  : hmac_dbac_timeout_handle
 * 功能描述  : 30秒超时处理函数
               go 不存在时直接退出
 * 1.日    期  : 2019年12月27日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC uint32_t hmac_dbac_timeout_handle(void *p_arg)
{
    mac_device_stru *pst_mac_device = NULL;

    pst_mac_device = (mac_device_stru *)p_arg;
    if (pst_mac_device == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }
    return hmac_dbac_ap_flow_other_vap_channel_handle(pst_mac_device);
}

/*
 * 函 数 名  : hmac_dbac_handle
 * 功能描述  : dbac 运行时启动30秒定时器，处理事项避免尽量切走避免dbac
 * 1.日    期  : 2019年12月27日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC void hmac_dbac_handle(mac_device_stru *pst_mac_device)
{
    hmac_dbac_handle_stru *pst_hmac_dbac_info;

    pst_hmac_dbac_info = &g_st_hmac_dbac_handle_info;

    if (!mac_is_dbac_running(pst_mac_device)) {
        return;
    }

    if (pst_hmac_dbac_info->st_dbac_timer.en_is_registerd == OAL_TRUE) {
        return;
    }

    frw_timer_create_timer_m(&pst_hmac_dbac_info->st_dbac_timer,
                             hmac_dbac_timeout_handle,
                             DBAC_RUNING_HANDLE_TIMEOUT,
                             pst_mac_device,
                             OAL_FALSE,
                             OAM_MODULE_ID_HMAC,
                             pst_mac_device->core_id);
}

/*
 * 函 数 名  : hmac_dbac_status_notify
 * 功能描述  : 处理dbac status event
 * 1.日    期  : 2014年5月8日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_dbac_status_notify(frw_event_mem_stru *pst_event_mem)
{
    frw_event_stru *pst_event = NULL;
    mac_device_stru *pst_mac_device = NULL;
    dmac_dbac_notify_to_hmac_stru *dbac_notify_data = NULL;

    if (oal_unlikely(pst_event_mem == NULL)) {
        oam_error_log0(0, OAM_SF_DBAC, "{hmac_dbac_status_notify::pst_event_mem null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    pst_event = frw_get_event_stru(pst_event_mem);
    dbac_notify_data = (dmac_dbac_notify_to_hmac_stru *)pst_event->auc_event_data;
    oam_warning_log4(pst_event->st_event_hdr.uc_vap_id, OAM_SF_DBAC,
        "hmac_dbac_status_notify::dbac switch to enable=%d, dbac_type %d, led_vap_id %d, flw_vap_id %d",
        dbac_notify_data->dbac_enabled,
        dbac_notify_data->dbac_type,
        dbac_notify_data->led_vap_id,
        dbac_notify_data->flw_vap_id);

    pst_mac_device = mac_res_get_dev(pst_event->st_event_hdr.uc_device_id);
    if (oal_unlikely(pst_mac_device == NULL)) {
        oam_error_log0(pst_event->st_event_hdr.uc_vap_id, OAM_SF_DBAC,
                       "{hmac_dbac_status_notify::pst_mac_device null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    pst_mac_device->en_dbac_running = dbac_notify_data->dbac_enabled;
    hmac_dbac_handle(pst_mac_device);

#ifdef _PRE_WLAN_CHBA_MGMT
    hmac_chba_update_channel_seq_when_dbac_notify(dbac_notify_data);
    hmac_chba_dbac_vap_set_rx_reorder_timeout(pst_mac_device->en_dbac_running);
#endif /* _PRE_WLAN_CHBA_MGMT */
    return OAL_SUCC;
}

static oal_bool_enum_uint8 hmac_vap_get_enable_ap_follow_channel_flag(mac_vap_stru *mac_vap)
{
    return mac_vap->dbac_enable_ap_follow_channel;
}

/* 功能描述  : 配置vap 是否使能信道跟随
 * 函数入参: true表示允许信道跟随; false表示禁止进行信道跟随
 */
static void hmac_vap_set_enable_ap_follow_channel_flag(mac_vap_stru *mac_vap, oal_bool_enum_uint8 flag)
{
    mac_vap->dbac_enable_ap_follow_channel = flag;
}

uint32_t hmac_dbac_enable_follow_channel(mac_vap_stru *mac_vap, uint32_t *params)
{
    hmac_vap_set_enable_ap_follow_channel_flag(mac_vap, (uint8_t)params[0]);
    oam_warning_log1(mac_vap->uc_vap_id, OAM_SF_DBAC,
        "{hmac_dbac_enable_follow_channel:flag[%d]}",
        hmac_vap_get_enable_ap_follow_channel_flag(mac_vap));
    return OAL_SUCC;
}
