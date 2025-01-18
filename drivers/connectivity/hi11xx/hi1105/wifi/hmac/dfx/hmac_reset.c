/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * 功能说明 : hmac复位处理文件
 * 作    者 : wifi
 * 创建日期 : 2014年11月26日
 */

#include "mac_device.h"
#include "mac_resource.h"
#include "hmac_vap.h"
#include "oal_cfg80211.h" // 不能删，删了ut编不过
#include "wlan_chip_i.h"
#include "hmac_config.h"
#include "hmac_chan_mgmt.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_RESET_C

/*
 * 函 数 名  : hmac_reset_sys_event
 * 功能描述  : device进行复位时，同步host事件处理
 * 日    期  : 2014年11月26日
 * 修改内容  : 新生成函数
 */
uint32_t hmac_reset_sys_event(mac_vap_stru *mac_vap, uint8_t len, uint8_t *param)
{
    mac_device_stru *mac_dev = NULL;
    mac_reset_sys_stru *reset_sys = NULL;

    reset_sys = (mac_reset_sys_stru *)param;

    mac_dev = mac_res_get_dev(mac_vap->uc_device_id);
    if (mac_dev == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "{hmac_reset_sys_event::mac_dev null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    switch (reset_sys->en_reset_sys_type) {
        case MAC_RESET_STATUS_SYS_TYPE:
            if ((mac_dev->uc_device_reset_in_progress == OAL_TRUE) &&
                (reset_sys->uc_value == OAL_FALSE)) {
                mac_dev->us_device_reset_num++;
            }

            hmac_config_set_reset_state(mac_vap, len, param);

            break;
        case MAC_RESET_SWITCH_SYS_TYPE:
            mac_dev->en_reset_switch = reset_sys->uc_value;

            break;
        default:
            break;
    }

    return OAL_SUCC;
}

/*
 * 功能描述  : 处理上报内核的速率标记
 * 日    期  : 2020.2.12
 * 作    者  : wifi
 * 修改内容  : 新生成函数
 */
OAL_STATIC void hmac_proc_query_response_flag(hmac_vap_stru *hmac_vap,
    dmac_query_station_info_response_event *query_sta_event)
{
    uint8_t flag = 0;

    flag |= ((query_sta_event->rate_info.txrx_rate.tx_rate.flags & MAC_RATE_INFO_FLAGS_MCS) ?
        RATE_INFO_FLAGS_MCS : 0);

    flag |= ((query_sta_event->rate_info.txrx_rate.tx_rate.flags & MAC_RATE_INFO_FLAGS_VHT_MCS) ?
        RATE_INFO_FLAGS_VHT_MCS : 0);

    flag |= ((query_sta_event->rate_info.txrx_rate.tx_rate.flags & MAC_RATE_INFO_FLAGS_SHORT_GI) ?
        RATE_INFO_FLAGS_SHORT_GI : 0);

    flag |= ((query_sta_event->rate_info.txrx_rate.tx_rate.flags & MAC_RATE_INFO_FLAGS_HE_MCS) ?
        MAC_RATE_INFO_FLAGS_HE_MCS : 0);

    hmac_vap->station_info.txrate.bw =
        query_sta_event->rate_info.txrx_rate.tx_rate.flags & MAC_RATE_INFO_FLAGS_40_MHZ_WIDTH ? RATE_INFO_BW_40 :
        (query_sta_event->rate_info.txrx_rate.tx_rate.flags & MAC_RATE_INFO_FLAGS_80_MHZ_WIDTH ? RATE_INFO_BW_80 :
        (query_sta_event->rate_info.txrx_rate.tx_rate.flags & MAC_RATE_INFO_FLAGS_160_MHZ_WIDTH ?
        RATE_INFO_BW_160 : RATE_INFO_BW_20));

    hmac_vap->station_info.txrate.flags = flag;
}

OAL_STATIC void hmac_proc_query_set_state_info(hmac_vap_stru *hmac_vap,
    dmac_query_station_info_response_event *reponse_event)
{
    /* 如果漫游结束时从dmac查询到rssi=-1，则用hmac_vap下保存的roam_rssi上报 */
    hmac_vap->station_info.signal = reponse_event->c_signal == -1 ? hmac_vap->roam_rssi : reponse_event->c_signal;

#ifdef CONFIG_HW_GET_EXT_SIG
    hmac_vap->station_info.noise = reponse_event->s_free_power;
    hmac_vap->station_info.chload = reponse_event->s_chload;
#endif
#ifdef CONFIG_HW_GET_EXT_SIG_ULDELAY
    hmac_vap->station_info.ul_delay = reponse_event->uplink_dealy;
#endif
    hmac_vap->station_info.rxrate.legacy = reponse_event->rate_info.txrx_rate.rx_rate_legacy;
    hmac_vap->station_info.txrate.mcs = reponse_event->rate_info.txrx_rate.tx_rate.mcs;
    hmac_vap->station_info.txrate.legacy = reponse_event->rate_info.txrx_rate.tx_rate.legacy;
    hmac_vap->station_info.txrate.nss = reponse_event->rate_info.txrx_rate.tx_rate.nss;
}

/*
 * 功能描述  : hmac接收dmac抛回来的查询应答事件
 * 日    期  : 2014年11月26日
 * 修改内容  : 新生成函数
 */
uint32_t hmac_proc_query_response_event(mac_vap_stru *mac_vap, uint8_t len, uint8_t *param)
{
    hmac_vap_stru *hmac_vap = NULL;
    dmac_query_station_info_response_event *reponse_event = NULL;
    uint8_t band;

    hmac_vap = mac_res_get_hmac_vap(mac_vap->uc_vap_id);
    if (hmac_vap == NULL) {
        oam_error_log0(mac_vap->uc_vap_id, OAM_SF_ANY, "{hmac_query_response::hmac_vap null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    reponse_event = (dmac_query_station_info_response_event *)(param);
    if (reponse_event->query_event == OAL_QUERY_STATION_INFO_EVENT) {
        wlan_chip_proc_query_station_packets(hmac_vap, reponse_event);

        hmac_proc_query_set_state_info(hmac_vap, reponse_event);

        hmac_proc_query_response_flag(hmac_vap, reponse_event);

        band = hmac_get_80211_band_type(&mac_vap->st_channel);
        /*  */
        hmac_vap->center_freq = oal_ieee80211_channel_to_frequency(mac_vap->st_channel.uc_chan_number, band);

        hmac_vap->s_free_power = reponse_event->s_free_power;
        hmac_vap->st_station_info_extend.uc_distance = reponse_event->st_station_info_extend.uc_distance;
        hmac_vap->st_station_info_extend.uc_cca_intr = reponse_event->st_station_info_extend.uc_cca_intr;
        hmac_vap->st_station_info_extend.c_snr_ant0 = reponse_event->st_station_info_extend.c_snr_ant0;
        hmac_vap->st_station_info_extend.c_snr_ant1 = reponse_event->st_station_info_extend.c_snr_ant1;
        hmac_vap->beacon_rssi = reponse_event->rate_info.tx_rate.beacon_rssi;
        hmac_vap->st_station_info_extend.bcn_cnt = reponse_event->st_station_info_extend.bcn_cnt;
        hmac_vap->st_station_info_extend.bcn_tout_cnt = reponse_event->st_station_info_extend.bcn_tout_cnt;
    }

    /* 唤醒wal_sdt_recv_reg_cmd等待的进程 */
    hmac_vap->station_info_query_completed_flag = OAL_TRUE;
    oal_wait_queue_wake_up_interrupt(&(hmac_vap->query_wait_q));

    return OAL_SUCC;
}
uint32_t hmac_proc_query_additional_response_event(mac_vap_stru *mac_vap, uint8_t len, uint8_t *param)
{
    hmac_vap_stru *hmac_vap = NULL;
    dmac_query_station_info_additional_response_event *reponse_event = NULL;

    hmac_vap = mac_res_get_hmac_vap(mac_vap->uc_vap_id);
    if (hmac_vap == NULL) {
        oam_error_log0(mac_vap->uc_vap_id, OAM_SF_ANY, "{hmac_proc_query_additional_response_event::hmac_vap null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    reponse_event = (dmac_query_station_info_additional_response_event *)(param);
    memcpy_s(&hmac_vap->station_info_extend2, sizeof(hmac_vap->station_info_extend2),
        &reponse_event->station_info_extend2, sizeof(reponse_event->station_info_extend2));

    return OAL_SUCC;
}

/*
 * 功能描述  : 配置命令下发
 * 日    期  : 2014年11月26日
 * 修改内容  : 新生成函数
 */
uint32_t hmac_config_reset_operate(mac_vap_stru *mac_vap, uint16_t len, uint8_t *param)
{
    mac_device_stru *mac_dev = NULL;
    mac_reset_sys_stru reset_sys;
    uint32_t ret;
    int8_t *token = NULL;
    int8_t *end = NULL;
    int8_t *ctx = NULL;
    int8_t *sep = " ";

    mac_dev = mac_res_get_dev(mac_vap->uc_device_id);
    if (mac_dev == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "{hmac_config_reset_operate::mac_dev null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* 获取复位信息 */
    token = oal_strtok((int8_t *)param, sep, &ctx);
    if (token == NULL) {
        oam_error_log0(mac_vap->uc_vap_id, OAM_SF_CFG, "{hmac_config_reset_operate::token null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }
    memset_s(&reset_sys, sizeof(mac_reset_sys_stru), 0, sizeof(mac_reset_sys_stru));
    reset_sys.en_reset_sys_type = (mac_reset_sys_type_enum_uint8)oal_strtol(token, &end, NUM_16_BITS);

    if (reset_sys.en_reset_sys_type == MAC_RESET_SWITCH_SET_TYPE) {
        /* 获取Channel List */
        token = oal_strtok(NULL, sep, &ctx);
        if (token == NULL) {
            oam_error_log0(mac_vap->uc_vap_id, OAM_SF_CFG, "{hmac_config_reset_operate::token null.}");
            return OAL_ERR_CODE_PTR_NULL;
        }

        reset_sys.uc_value = (uint8_t)oal_strtol(token, &end, 16); //  16进制
        mac_dev->en_reset_switch = reset_sys.uc_value;
        ret = hmac_config_send_event(mac_vap, WLAN_CFGID_RESET_HW_OPERATE, len, (uint8_t *)&reset_sys);
        if (oal_unlikely(ret != OAL_SUCC)) {
            oam_warning_log1(mac_vap->uc_vap_id, OAM_SF_CFG,
                             "{hmac_config_reset_operate::hmac_config_send_event failed[%d].}", ret);
        }

        return ret;
    } else if (reset_sys.en_reset_sys_type == MAC_RESET_SWITCH_GET_TYPE) {
        oam_warning_log1(mac_vap->uc_vap_id, OAM_SF_CFG,
                         "{hmac_config_reset_operate::the reset switch is %d.}",
                         mac_dev->en_reset_switch);
    } else if (reset_sys.en_reset_sys_type == MAC_RESET_STATUS_GET_TYPE) {
        oam_warning_log2(mac_vap->uc_vap_id, OAM_SF_CFG,
                         "{hmac_config_reset_operate::the reset status is %d, the reset num is %d.}",
                         mac_dev->uc_device_reset_in_progress, mac_dev->us_device_reset_num);
    } else {
        oam_warning_log1(mac_vap->uc_vap_id, OAM_SF_CFG,
                         "{hmac_config_reset_operate::the reset tpye is %d, out of limit.}",
                         reset_sys.en_reset_sys_type);
    }

    return OAL_SUCC;
}
