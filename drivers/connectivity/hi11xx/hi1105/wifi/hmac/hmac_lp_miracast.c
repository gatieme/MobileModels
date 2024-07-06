/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * 功能说明 : WIFI 投屏低功耗
 * 创建日期 : 2023年4月6日
 */

#include "wlan_chip.h"
#include "wlan_chip_i.h"
#include "oal_main.h"
#include "hmac_ext_if.h"
#include "hmac_cali_mgmt.h"
#include "wal_linux_ioctl.h"
#include "hmac_config.h"
#include "hmac_stat.h"

#include "hisi_customize_wifi.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID      OAM_FILE_ID_HMAC_LP_MIRACAST_C
#ifdef _PRE_WLAN_FEATURE_LP_MIRACAST

#define MBPS_10M 10
#define MBPS_30M 30
#define HMAC_SCREEN_CNT 3
#define HMAC_PROTOCOL_CNT 3
#define LP_MIRACAST_TIMEOUT 120000 /* 120秒 */

static uint8_t hmac_get_custom_cap_5g_chain(void)
{
    uint8_t radio_cap = wlan_chip_get_chn_radio_cap();
    return radio_cap >> WLAN_CHAIN_BAND_INDICATOR;
}

static uint8_t hmac_get_custom_cap_5g_nss(void)
{
    uint8_t chain_5g = hmac_get_custom_cap_5g_chain();
    uint8_t chain_num_5g = oal_bit_get_num_one_byte(chain_5g);
    oam_warning_log2(0, OAM_SF_DBDC,
        "hmac_get_custom_cap_5g_nss:chain_2g[%d], chain_num_2g[%d]", chain_5g, chain_num_5g);
    if (chain_num_5g == 0) {
        return 0;
    }
    return chain_num_5g - 1;
}

mac_vap_stru *hmac_get_single_gc_mac_vap(void)
{
    uint8_t vap_id;
    mac_vap_stru *mac_vap = NULL;

    for (vap_id = 0; vap_id < WLAN_VAP_SUPPORT_MAX_NUM_LIMIT; vap_id++) {
        mac_vap = (mac_vap_stru *)mac_res_get_mac_vap(vap_id);
        if (mac_vap == NULL) {
            oam_error_log1(0, OAM_SF_ANY, "{hmac_update_pk_mode_info::mac_vap(%d) is null.}", vap_id);
            continue;
        }
        if (!is_p2p_cl(mac_vap)) {
            continue;
        }
        return mac_vap;
    }
    return NULL;
}

/* 根据是否投屏低功耗下发对应的切换C1还是MIMO的命令 */
void hmac_config_control_lp_miracast(mac_vap_stru *mac_vap, uint8_t is_siso)
{
    hmac_lp_miracast_stat_stru *hmac_lp_miracast_stats = hmac_stat_get_lp_miracast_stats();

    mac_m2s_mgr_stru m2s_mgr = {0};
    int32_t chip_type = get_mpxx_subchip_type();
    if (chip_type >= BOARD_VERSION_MP16) {
        if (is_siso == OAL_TRUE) {
            m2s_mgr.pri_data.test_mode.uc_m2s_state =
                wal_hipriv_m2s_switch_get_mcm_chain((uint16_t)oal_atoi("0010"));
        } else {
            m2s_mgr.pri_data.test_mode.uc_m2s_state =
                wal_hipriv_m2s_switch_get_mcm_chain((uint16_t)oal_atoi("0011"));
        }
    } else {
        if (is_siso == OAL_TRUE) {
            m2s_mgr.pri_data.test_mode.uc_m2s_state = (uint8_t)oal_atoi("1");
        } else {
            m2s_mgr.pri_data.test_mode.uc_m2s_state = (uint8_t)oal_atoi("2");
        }
    }

    hmac_lp_miracast_stats->is_siso = is_siso;
    m2s_mgr.en_cfg_m2s_mode = MAC_M2S_MODE_SW_TEST;

    m2s_mgr.pri_data.test_mode.uc_master_id = HAL_DEVICE_ID_MASTER;

    /* true: 硬切换测试模式采用默认软切换配置 */
    /* false: 业务切换，软切换测试模式采用默认软切换配置 */
    m2s_mgr.pri_data.test_mode.en_m2s_type =  MAC_M2S_MODE_LP_MIRACAST;

    /* 标识业务类型 */
    m2s_mgr.pri_data.test_mode.uc_trigger_mode = WLAN_M2S_TRIGGER_MODE_TEST;

    oam_warning_log1(mac_vap->uc_vap_id, OAM_SF_M2S, "{hmac_config_control_lp_miracast::is_siso[%d].}", is_siso);
    hmac_config_set_m2s_switch(mac_vap, sizeof(mac_m2s_mgr_stru), (uint8_t *)&m2s_mgr);
}

/*
 * 函 数 名  : hmac_lp_miracast_calc_m2s_state
 * 功能描述  : host判定协议模式，流量大小，device是否允许，计算是否进入siso
 * 1.日    期  : 2023年3月28日
 *   修改内容  : 新生成函数
 */
uint8_t hmac_lp_miracast_calc_m2s_state(hmac_user_stru *hmac_user,
    hmac_lp_miracast_stat_stru *hmac_lp_miracast_stats, uint32_t throughput_mbps)
{
    wlan_protocol_enum_uint8 protocol_mode = hmac_user->st_user_base_info.en_protocol_mode;
    if ((protocol_mode <= WLAN_HT_MODE) || (protocol_mode == WLAN_HT_ONLY_MODE) ||
        (protocol_mode == WLAN_HT_11G_MODE) || (protocol_mode == WLAN_HT_ONLY_MODE_2G)) {
        hmac_lp_miracast_stats->protocol_allow_siso = OAL_FALSE;
    } else {
        hmac_lp_miracast_stats->protocol_allow_siso = OAL_TRUE;
    }

    hmac_lp_miracast_stats->throughput_cnt = (throughput_mbps < MBPS_10M) ?
        hmac_lp_miracast_stats->throughput_cnt + 1 : hmac_lp_miracast_stats->throughput_cnt;

    hmac_lp_miracast_stats->throughput_cnt = (throughput_mbps > MBPS_30M) ?
        0 : hmac_lp_miracast_stats->throughput_cnt;

    hmac_lp_miracast_stats->throughput_cnt = oal_min(hmac_lp_miracast_stats->throughput_cnt, HMAC_SCREEN_CNT);

    hmac_lp_miracast_stats->host_allow_m2s_siso = (hmac_lp_miracast_stats->throughput_cnt >= HMAC_SCREEN_CNT
        && hmac_lp_miracast_stats->protocol_allow_siso == OAL_TRUE) ?
        OAL_TRUE : OAL_FALSE;

    if (hmac_lp_miracast_stats->debug_on == OAL_TRUE) {
        oam_warning_log4(0, OAM_SF_M2S, "protocol_mode[%d],throughput[%d],protocol_allow_siso[%d], throughput_cnt[%d]",
            protocol_mode, throughput_mbps, hmac_lp_miracast_stats->protocol_allow_siso,
            hmac_lp_miracast_stats->throughput_cnt);

        oam_warning_log3(0, OAM_SF_M2S,
            "host_allow[%d],device_allow[%d], is_siso[%d]", hmac_lp_miracast_stats->host_allow_m2s_siso,
            hmac_lp_miracast_stats->device_allow_m2s_siso, hmac_lp_miracast_stats->is_siso);
    }

    return (hmac_lp_miracast_stats->host_allow_m2s_siso == OAL_TRUE &&
        hmac_lp_miracast_stats->device_allow_m2s_siso == OAL_TRUE);
}

/*
 * 函 数 名  : hmac_config_lp_miracast_stat_mbps
 * 功能描述  : host统计流量，计算是否进入siso
 * 1.日    期  : 2023年3月28日
 *   修改内容  : 新生成函数
 */
void hmac_config_lp_miracast_stat_mbps(uint32_t tx_throughput_mbps, uint32_t rx_throughput_mbps)
{
    hmac_lp_miracast_stat_stru *hmac_lp_miracast_stats = hmac_stat_get_lp_miracast_stats();
    mac_vap_stru *mac_vap = NULL;
    hmac_vap_stru *hmac_vap = NULL;
    hmac_user_stru *hmac_user = NULL;
    mac_device_stru *mac_device = NULL;
    uint32_t throughput = tx_throughput_mbps + rx_throughput_mbps;
    uint8_t is_siso = OAL_FALSE;
    uint32_t cur_timestamp;

    if (hmac_lp_miracast_stats->lp_miracast_enable == OAL_FALSE) {
        return;
    }

    mac_device = mac_res_get_dev(0);
    /* 如果非单GC,则不用开启统计 */
    if (mac_device_calc_up_vap_num(mac_device) != 1) {
        return;
    }

    mac_vap = hmac_get_single_gc_mac_vap();
    if (mac_vap == NULL) {
        return;
    }

    hmac_vap = mac_res_get_hmac_vap(mac_vap->uc_vap_id);
    if (hmac_vap == NULL) {
        return;
    }
    hmac_user = mac_res_get_hmac_user(hmac_vap->st_vap_base_info.us_assoc_vap_id);
    if (hmac_user == NULL) {
        oam_error_log0(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_M2S,
            "wlan_chip_lp_miracast_stat_mbps: hmac_user is null ptr.");
        return;
    }

    is_siso = hmac_lp_miracast_calc_m2s_state(hmac_user, hmac_lp_miracast_stats, throughput);
    cur_timestamp = oal_time_get_stamp_ms();
    if (hmac_lp_miracast_stats->is_siso != is_siso && ((is_siso == OAL_FALSE) || ((is_siso == OAL_TRUE) &&
        oal_time_after32(cur_timestamp, (hmac_lp_miracast_stats->last_time + LP_MIRACAST_TIMEOUT))))) {
        hmac_config_control_lp_miracast(mac_vap, is_siso);
        hmac_lp_miracast_stats->last_time = cur_timestamp;
    }
}
/*
 * 函 数 名  : hmac_m2s_lp_miracast_report_state
 * 功能描述  : host获取device是否允许进入低功耗的上报参数
 * 1.日    期  : 2023年3月28日
 *   修改内容  : 新生成函数
 */
uint32_t hmac_m2s_lp_miracast_report_state(mac_vap_stru *mac_vap, uint8_t uc_len, uint8_t *param)
{
    hmac_lp_miracast_stat_stru *hmac_lp_miracast_stats = hmac_stat_get_lp_miracast_stats();
    dmac_miracast_report_stru *dmac_miracast_report = NULL;
    dmac_miracast_report = (dmac_miracast_report_stru *)param;
    if (dmac_miracast_report->abort_switch == OAL_TRUE) {
        hmac_lp_miracast_stats->is_siso = !hmac_lp_miracast_stats->is_siso;
    }
    hmac_lp_miracast_stats->device_allow_m2s_siso = dmac_miracast_report->device_allow_m2s_siso;

    oam_warning_log2(0, OAM_SF_PWR, "{hmac_m2s_lp_miracast_report_state::device_allow_m2s_siso[%d], is_siso[%d]}",
        hmac_lp_miracast_stats->device_allow_m2s_siso, hmac_lp_miracast_stats->is_siso);
    return OAL_SUCC;
}

/*
 * 函 数 名  : hmac_config_notify_lp_miracast
 * 功能描述  : 通知底层投屏低功耗开关
 * 1.日    期  : 2023年3月16日
 *   修改内容  : 新生成函数
 */
uint32_t hmac_config_notify_lp_miracast(mac_vap_stru *mac_vap, uint16_t len, uint8_t *param)
{
    uint32_t ret;

    /***************************************************************************
        抛事件到DMAC层, 同步DMAC数据
    ***************************************************************************/
    ret = hmac_config_send_event(mac_vap, WLAN_CFGID_SET_LP_MIRACAST, len, param);
    if (oal_unlikely(ret != OAL_SUCC)) {
        oam_warning_log1(mac_vap->uc_vap_id, OAM_SF_M2S,
            "{hmac_config_notify_lp_miracast::hmac_config_send_event failed[%d].}", ret);
    }

    return ret;
}
/*
 * 函 数 名  : hmac_config_set_lp_miracast
 * 功能描述  : 通知底层投屏低功耗命令下发及解析
 * 1.日    期  : 2023年3月16日
 *   修改内容  : 新生成函数
 */
uint32_t hmac_config_set_lp_miracast(mac_vap_stru *mac_vap, uint16_t len, uint8_t *param)
{
    mac_device_stru *mac_device = NULL;
    hmac_lp_miracast_stat_stru *hmac_lp_miracast_stats = hmac_stat_get_lp_miracast_stats();
    uint8_t nss_num = hmac_get_custom_cap_5g_nss();
    mac_lp_miracast_cmd_enum lp_miracast_cmd = (mac_lp_miracast_cmd_enum)*param;

    if (nss_num == WLAN_SINGLE_NSS) {
        oam_warning_log0(0, OAM_SF_ANY, "{hmac_config_set_lp_miracast:: single nss not support slpr}");
        return OAL_FAIL;
    }

    mac_device = mac_res_get_dev(0);
    /* 如果非单GC,则不用开启统计 */
    if (mac_device_calc_up_vap_num(mac_device) != 1) {
        oam_warning_log0(0, OAM_SF_ANY, "{hmac_config_set_lp_miracast::vap_num is not 1.}");
        return OAL_FAIL;
    }

    if (!is_p2p_cl(mac_vap)) {
        return OAL_FAIL;
    }

    switch (lp_miracast_cmd) {
        case MAC_LP_MIRACAST_ENABLE:
            hmac_lp_miracast_stats->lp_miracast_enable = OAL_TRUE;
            break;
        case MAC_LP_MIRACAST_DISABLE:
            hmac_lp_miracast_stats->lp_miracast_enable = OAL_FALSE;
            hmac_config_control_lp_miracast(mac_vap, OAL_FALSE);
            break;
        case MAC_LP_MIRACAST_DEBUG_ON:
            hmac_lp_miracast_stats->debug_on = OAL_TRUE;
            break;
        case MAC_LP_MIRACAST_DEBUG_OFF:
            hmac_lp_miracast_stats->debug_on = OAL_FALSE;
            break;
        default:
            break;
    }

    return hmac_config_notify_lp_miracast(mac_vap, len, param);
}

void hmac_config_start_vap_close_lp_miracast(mac_vap_stru *mac_vap)
{
    hmac_lp_miracast_stat_stru *hmac_lp_miracast_stats = hmac_stat_get_lp_miracast_stats();

    if (hmac_lp_miracast_stats->lp_miracast_enable == OAL_TRUE) {
        hmac_config_control_lp_miracast(mac_vap, OAL_FALSE);
    }
}
void hmac_config_down_vap_close_lp_miracast(mac_vap_stru *mac_vap)
{
    hmac_lp_miracast_stat_stru *hmac_lp_miracast_stats = hmac_stat_get_lp_miracast_stats();
    uint8_t param = OAL_FALSE;

    if (hmac_lp_miracast_stats->lp_miracast_enable == OAL_TRUE && is_p2p_cl(mac_vap)) {
        hmac_lp_miracast_stats->lp_miracast_enable = OAL_FALSE;
        hmac_config_control_lp_miracast(mac_vap, OAL_FALSE);
        hmac_config_notify_lp_miracast(mac_vap, sizeof(uint8_t), &param);
    }
}

#endif
