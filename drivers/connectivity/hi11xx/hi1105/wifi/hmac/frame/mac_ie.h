/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * 功能说明 : mac_ie.c 的头文件
 * 作    者 :
 * 创建日期 : 2013年1月8日
 */

#ifndef MAC_IE_H
#define MAC_IE_H

#include "oal_ext_if.h"
#include "mac_frame.h"
#include "wlan_mib.h"
#include "wlan_types.h"
#include "mac_user.h"
#include "mac_vap.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_MAC_IE_H

static inline oal_bool_enum_uint8 mac_ie_reamin_len_is_enough(const uint8_t *src_ie, const uint8_t *curr_ie,
    uint8_t ie_len, uint32_t remain_len)
{
    return (oal_bool_enum_uint8)((((curr_ie - src_ie) + remain_len) <= ie_len) ? OAL_TRUE : OAL_FALSE);
}

/* 信道偏移定义 */
#define CHAN_OFFSET_PLUS_2   2
#define CHAN_OFFSET_PLUS_6   6
#define CHAN_OFFSET_PLUS_8   8
#define CHAN_OFFSET_PLUS_10  10
#define CHAN_OFFSET_PLUS_14  14
#define CHAN_OFFSET_MINUS_2   (-2)
#define CHAN_OFFSET_MINUS_6   (-6)
#define CHAN_OFFSET_MINUS_8   (-8)
#define CHAN_OFFSET_MINUS_10  (-10)
#define CHAN_OFFSET_MINUS_14  (-14)


typedef struct {
    int8_t auc_non_transmitted_ssid[WLAN_SSID_MAX_LEN];
    uint8_t uc_non_transmitted_ssid_len;
    uint16_t us_non_tramsmitted_bssid_cap;

    uint8_t auc_transmitted_bssid[WLAN_MAC_ADDR_LEN];     /* transmitted bssid */
    uint8_t auc_non_transmitted_bssid[WLAN_MAC_ADDR_LEN]; /* transmitted bssid */

    uint8_t uc_maxbssid_indicator;
    uint8_t uc_bssid_index;
    uint8_t uc_dtim_period;
    uint8_t uc_dtim_count;

    uint8_t bit_is_non_transimitted_bss : 1,
            bit_rsv : 7;
    uint8_t auc_rcv[NUM_3_BITS];
} mac_multi_bssid_frame_info_stru;

/*
 * 功能描述  : 根据"次信道偏移量"获取对应的带宽模式
 * 1.日    期  : 2014年3月12日
  *   修改内容  : 新生成函数
 */
OAL_STATIC OAL_INLINE wlan_channel_bandwidth_enum_uint8 mac_get_bandwidth_from_sco(
    mac_sec_ch_off_enum_uint8 en_sec_chan_offset)
{
    switch (en_sec_chan_offset) {
        case MAC_SCA: /* Secondary Channel Above */
            return WLAN_BAND_WIDTH_40PLUS;

        case MAC_SCB: /* Secondary Channel Below */
            return WLAN_BAND_WIDTH_40MINUS;

        default: /* No Secondary Channel    */
            return WLAN_BAND_WIDTH_20M;
    }
}

/*
 * 功能描述  : 根据"带宽模式"获取对应的"次信道偏移量"
 * 1.日    期  : 2014年2月26日
  *   修改内容  : 新生成函数
 */
OAL_STATIC OAL_INLINE mac_sec_ch_off_enum_uint8 mac_get_sco_from_bandwidth(
    wlan_channel_bandwidth_enum_uint8 en_bandwidth)
{
    switch (en_bandwidth) {
        case WLAN_BAND_WIDTH_40PLUS:
        case WLAN_BAND_WIDTH_80PLUSPLUS:
        case WLAN_BAND_WIDTH_80PLUSMINUS:
            return MAC_SCA;

        case WLAN_BAND_WIDTH_40MINUS:
        case WLAN_BAND_WIDTH_80MINUSPLUS:
        case WLAN_BAND_WIDTH_80MINUSMINUS:
            return MAC_SCB;

        default:
            return MAC_SCN;
    }
}

wlan_mib_mimo_power_save_enum mac_ie_proc_sm_power_save_field(
    mac_user_stru *mac_user, uint8_t smps);

oal_bool_enum_uint8 mac_ie_proc_ht_green_field(mac_user_stru *mac_user_sta,
                                               mac_vap_stru *mac_vap,
                                               uint8_t ht_green_field,
                                               oal_bool_enum prev_asoc_ht);

oal_bool_enum_uint8 mac_ie_proc_ht_supported_channel_width(mac_user_stru *mac_user_sta,
                                                           mac_vap_stru *mac_vap,
                                                           uint8_t supported_channel_width,
                                                           oal_bool_enum prev_asoc_ht);

oal_bool_enum_uint8 mac_ie_proc_lsig_txop_protection_support(mac_user_stru *mac_user_sta,
                                                             mac_vap_stru *mac_vap,
                                                             uint8_t lsig_txop_protection_support,
                                                             oal_bool_enum prev_asoc_ht);
uint32_t mac_ie_proc_ext_cap_ie(mac_user_stru *mac_user, uint8_t *payload);
uint8_t mac_ie_get_chan_num(uint8_t *frame_body, uint16_t frame_len, uint16_t offset, dmac_rx_ctl_stru *rx_ctrl);
uint32_t mac_ie_proc_chwidth_field(mac_vap_stru *mac_vap, mac_user_stru *mac_user, uint8_t chwidth);

uint32_t mac_set_second_channel_offset_ie(wlan_channel_bandwidth_enum_uint8 en_bw,
                                          uint8_t *buffer, uint8_t *output_len);
uint32_t mac_set_11ac_wideband_ie(uint8_t channel, wlan_channel_bandwidth_enum_uint8 en_bw,
                                  uint8_t *buffer, uint8_t *output_len);
oal_bool_enum_uint8 mac_ie_check_p2p_action(uint8_t *payload, uint16_t payload_len);
uint32_t mac_ie_proc_ht_sta(mac_vap_stru *mac_sta, uint8_t *payload, uint16_t offset,
                            mac_user_stru *mac_user_ap, uint16_t *amsdu_maxsize);
uint32_t mac_ie_proc_obss_scan_ie(mac_vap_stru *mac_vap, uint8_t *payload);
uint8_t mac_ie_from_vht_cap_get_tx_nss(mac_vht_hdl_stru *mac_vht_hdl);
#ifdef _PRE_WLAN_FEATURE_11AX
uint32_t mac_ie_proc_he_opern_ie(mac_vap_stru *mac_vap, uint8_t *payload, mac_user_stru *mac_user);
uint32_t mac_ie_parse_he_cap(uint8_t *he_cap_ie, mac_frame_he_cap_ie_stru *he_cap_value);
uint8_t mac_ie_from_he_cap_get_tx_nss(mac_he_hdl_stru *mac_he_hdl);
uint32_t mac_ie_from_he_cap_get_nss(mac_he_hdl_stru *mac_he_hdl, wlan_nss_enum_uint8 *nss);
uint32_t mac_ie_parse_he_oper(uint8_t *he_oper_ie, mac_frame_he_oper_ie_stru *he_oper_ie_value);
oal_bool_enum_uint8 mac_proc_he_uora_parameter_set_ie(mac_vap_stru *mac_vap, uint8_t *payload, uint16_t msg_len);
uint32_t mac_ie_parse_mu_edca_parameter(uint8_t *he_edca_ie,
                                        mac_frame_he_mu_edca_parameter_ie_stru *he_mu_edca_value);
uint32_t mac_ie_parse_spatial_reuse_parameter(uint8_t *he_cap_ie,
    mac_frame_he_spatial_reuse_parameter_set_ie_stru *he_srp_value);
uint32_t mac_ie_parse_he_bss_color_change_announcement_ie(uint8_t *payload,
    mac_frame_bss_color_change_annoncement_ie_stru *bss_color);
uint32_t mac_ie_parse_he_ndp_feedback_report_ie(uint8_t *he_ndp_ie, uint8_t *nfrp_buff_threshold_exp);
uint32_t mac_ie_parse_multi_bssid_opt_subie(uint8_t *frame_data, uint16_t data_len,
                                            mac_multi_bssid_frame_info_stru *mbssid_info,
                                            uint8_t *mbssid_body_ie_len);
#endif
uint32_t mac_proc_ht_opern_ie(mac_vap_stru *mac_vap, uint8_t *payload, mac_user_stru *mac_user);
uint32_t mac_ie_proc_vht_opern_ie(mac_vap_stru *mac_vap, uint8_t *payload, mac_user_stru *mac_user);

#ifdef _PRE_WLAN_FEATURE_OPMODE_NOTIFY
uint32_t  mac_ie_proc_opmode_field(mac_vap_stru *mac_vap,
    mac_user_stru *pst_mac_user, mac_opmode_notify_stru *opmode_notify,
    oal_bool_enum_uint8 from_beacon);
#endif
uint32_t mac_ie_get_wpa_cipher(uint8_t *ie, mac_crypto_settings_stru *crypto);
uint32_t mac_ie_get_rsn_cipher(uint8_t *ie, mac_crypto_settings_stru *crypto);
uint8_t *mac_ie_find_vendor_vht_ie(uint8_t *frame, uint16_t frame_len);
uint16_t mac_ie_get_max_mpdu_len_by_vht_cap(uint8_t vht_cap_max_mpdu_len_bit);
wlan_channel_bandwidth_enum_uint8 mac_get_bandwith_from_center_freq_seg0_seg1(
    uint8_t chan_width, uint8_t channel, uint8_t chan_center_freq0, uint8_t chan_center_freq1);
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
uint32_t mac_ie_proc_he_6ghz_opern_info(uint8_t *he_oper_ie,
    mac_frame_he_6ghz_oper_info_stru *he_6ghz_oper_info, mac_frame_he_oper_ie_stru *he_oper_ie_value);
uint32_t mac_ie_parse_he_6ghz_band_cap(uint8_t *payload, mac_he_6ghz_band_cap_info_stru *he_6ghz_band_cap_ie_value);
wlan_channel_bandwidth_enum_uint8 mac_get_6ghz_bandwith_from_center_freq_seg0_seg1(
    uint8_t chan_width, uint8_t channel, uint8_t chan_center_freq0, uint8_t chan_center_freq1);
#endif
wlan_channel_bandwidth_enum_uint8 mac_get_80mbandwith_from_offset_channel(int8_t offset_channel);
#endif /* end of mac_ie.h */
