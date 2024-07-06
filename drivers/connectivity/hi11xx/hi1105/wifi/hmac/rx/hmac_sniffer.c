/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * 功能说明 : hmac_sniffer.c文件
 * 作    者 : wifi
 * 创建日期 : 2020年09月17日
 */

/* 1 头文件包含 */
#include "mac_frame_inl.h"
#include "host_hal_ext_if.h"
#include "hmac_sniffer.h"
#include "hmac_mgmt_classifier.h"
#include "hmac_rx_data.h"
#ifdef _PRE_WLAN_FEATURE_SNIFFER
#ifdef CONFIG_HW_SNIFFER
#include <hwnet/ipv4/sysctl_sniffer.h>
#endif
#endif
#include "oam_event_wifi.h"
#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_SNIFFER_C
#ifdef _PRE_WLAN_FEATURE_SNIFFER
/*
 * 命令格式:
 * CMD_QUERY_SNIFFER TA MAC(6b) sniffer enable(1b) cap_channel(1b) cap_protocol_mode(32b)
 */
#define WAL_SNIFFER_CAP_PROTOCOL_MODE_LEN 32
#define WAL_SNIFFER_CAP_CHAN_STR_LEN 5
#define WAL_SNIFFER_MODE_LEN 2
#define WAL_SNIFFER_TA_MAC_STR_LEN 18
#define WAL_SNIFFER_CMD_STR_LEN 32

void hmac_monitor_init(hmac_device_stru *hmac_device)
{
    oal_spin_lock_init(&hmac_device->d2h_sniffer_info);
    hmac_device->en_monitor_mode = OAL_FALSE;
    hmac_device->sniffer_mode = 0;
    hmac_device->rssi0 = 0;
    hmac_device->rssi1 = 0;
    hmac_device->mgmt_frames_cnt = 0;
    hmac_device->control_frames_cnt = 0;
    hmac_device->data_frames_cnt = 0;
    hmac_device->others_frames_cnt = 0;
    hmac_device->addr_filter_on = OAL_FALSE;
    memset_s(hmac_device->monitor_mac_addr, WLAN_MAC_ADDR_LEN, 0xff, WLAN_MAC_ADDR_LEN);
}

/*
 * 功能描述  : 根据sniffer使能情况，对al_rx、pm、monitor进行切换
 */
OAL_STATIC uint32_t wal_vendor_sniffer_set_switch(oal_net_device_stru *p_net_dev, mac_vap_stru *mac_vap,
    uint8_t sniffer_mode)
{
    uint32_t ret, pm_switch_on;
    uint8_t  cmd_is_on[BYTE_OFFSET_2] = {0};

    cmd_is_on[0] = sniffer_mode;

    ret = wal_ioctl_set_al_rx(p_net_dev, (int8_t *)cmd_is_on);
    if (ret != OAL_SUCC) {
        return ret;
    }
    pm_switch_on = (cmd_is_on[0] - '0') ? 0 : 1;
    ret = wal_ioctl_set_pm_switch(mac_vap, &pm_switch_on);
    if (ret != OAL_SUCC) {
        return ret;
    }
    ret = wal_ioctl_set_monitor_mode(p_net_dev, (int8_t *)cmd_is_on);
    if (ret != OAL_SUCC) {
        return ret;
    }
    return OAL_SUCC;
}

OAL_STATIC uint32_t wal_vendor_sniffer_set_sniffer_mode(oal_net_device_stru *p_net_dev,
    uint8_t *sniffer_ta_mac, uint8_t sniffer_mode)
{
    uint8_t set_sniffer_cmd_str[WAL_SNIFFER_CMD_STR_LEN] = {0}; // 拼接set_sniffer命令
    int32_t sec_fun_ret;
    uint32_t ret;

    set_sniffer_cmd_str[BYTE_OFFSET_0] = sniffer_mode;
    set_sniffer_cmd_str[BYTE_OFFSET_1] = ' ';
    sec_fun_ret = memcpy_s(set_sniffer_cmd_str + BYTE_OFFSET_2,
        WAL_SNIFFER_CMD_STR_LEN - BYTE_OFFSET_2, sniffer_ta_mac, WAL_SNIFFER_TA_MAC_STR_LEN - 1);
    if (sec_fun_ret != EOK) {
        oam_warning_log1(0, OAM_SF_CFG, "{wal_vendor_sniffer_set_sniffer_mode::memcpy_s err[%d]}", sec_fun_ret);
        return OAL_FAIL;
    }
    ret = wal_ioctl_set_sniffer(p_net_dev, (int8_t *)set_sniffer_cmd_str);
    if (ret != OAL_SUCC) {
        return ret;
    }
    return OAL_SUCC;
}

OAL_STATIC uint32_t wal_vendor_enable_sniffer(oal_net_device_stru *p_net_dev,
    uint8_t *sniffer_ta_mac, uint8_t sniffer_mode, uint8_t *cap_channel, uint8_t *cap_protocol_mode)
{
    uint32_t ret;
    mac_vap_stru *mac_vap = oal_net_dev_priv(p_net_dev);
    if (mac_vap == NULL) {
        return OAL_FAIL;
    }

    ret = wal_ioctl_set_mode(p_net_dev, cap_protocol_mode);
    if (ret != OAL_SUCC) {
        oam_warning_log1(0, OAM_SF_CFG, "{wal_vendor_enable_sniffer::set_mode err[%d]}", ret);
        return ret;
    }
    ret = wal_ioctl_set_freq(p_net_dev, cap_channel);
    if (ret != OAL_SUCC) {
        oam_warning_log1(0, OAM_SF_CFG, "{wal_vendor_enable_sniffer::set_freq err[%d]}", ret);
        return ret;
    }
    ret = wal_vendor_sniffer_set_sniffer_mode(p_net_dev, sniffer_ta_mac, sniffer_mode);
    if (ret != OAL_SUCC) {
        oam_warning_log1(0, OAM_SF_CFG, "{wal_vendor_enable_sniffer::set_sniffer err[%d]}", ret);
        return ret;
    }
    ret = wal_vendor_sniffer_set_switch(p_net_dev, mac_vap, sniffer_mode);
    if (ret != OAL_SUCC) {
        return ret;
    }
    return OAL_SUCC;
}
// disable sniffer将关闭指令放在最后
OAL_STATIC uint32_t wal_vendor_disable_sniffer(oal_net_device_stru *p_net_dev,
    uint8_t *sniffer_ta_mac, uint8_t sniffer_mode, uint8_t *cap_channel, uint8_t *cap_protocol_mode)
{
    uint32_t ret;
    mac_vap_stru *mac_vap = oal_net_dev_priv(p_net_dev);
    if (mac_vap == NULL) {
        return OAL_FAIL;
    }

    ret = wal_ioctl_set_mode(p_net_dev, cap_protocol_mode);
    if (ret != OAL_SUCC) {
        oam_warning_log1(0, OAM_SF_CFG, "{wal_vendor_disable_sniffer::set_mode err[%d]}", ret);
        return ret;
    }
    ret = wal_ioctl_set_freq(p_net_dev, cap_channel);
    if (ret != OAL_SUCC) {
        oam_warning_log1(0, OAM_SF_CFG, "{wal_vendor_disable_sniffer::set_freq err[%d]}", ret);
        return ret;
    }
    ret = wal_vendor_sniffer_set_switch(p_net_dev, mac_vap, sniffer_mode);
    if (ret != OAL_SUCC) {
        return ret;
    }
    ret = wal_vendor_sniffer_set_sniffer_mode(p_net_dev, sniffer_ta_mac, sniffer_mode);
    if (ret != OAL_SUCC) {
        oam_warning_log1(0, OAM_SF_CFG, "{wal_vendor_disable_sniffer::set_sniffer err[%d]}", ret);
        return ret;
    }
    return OAL_SUCC;
}

uint32_t wal_vendor_sniffer_handle(oal_net_device_stru *p_net_dev,
    uint8_t *pc_cmd, uint32_t cmd_len)
{
    /* 跳过开头直接获取命令后续携带参数 */
    uint8_t *sniffer_cmd_str = pc_cmd + CMD_QUERY_SNIFFER_LEN + 1; // 1代表空格长度1个字节
    uint8_t  sniffer_ta_mac[WAL_SNIFFER_TA_MAC_STR_LEN];
    uint8_t  sniffer_mode[WAL_SNIFFER_MODE_LEN] = {0};
    uint8_t  cap_channel[WAL_SNIFFER_CAP_CHAN_STR_LEN] = {0};
    uint8_t  cap_protocol_mode[WAL_SNIFFER_CAP_PROTOCOL_MODE_LEN] = {0};
    uint32_t ret, cmd_offset;

    /* 获取ta mac地址 */
    ret = wal_get_cmd_one_arg(sniffer_cmd_str, sniffer_ta_mac, WAL_SNIFFER_TA_MAC_STR_LEN, &cmd_offset);
    if (ret != OAL_SUCC) {
        oam_warning_log1(0, OAM_SF_CFG, "{wal_vendor_sniffer_handle::get ta mac fail, err_code[%d]}", ret);
        return ret;
    }
    sniffer_cmd_str += cmd_offset;
    /* 获取sniffer mode */
    ret = wal_get_cmd_one_arg(sniffer_cmd_str, sniffer_mode, WAL_SNIFFER_MODE_LEN, &cmd_offset);
    if (ret != OAL_SUCC) {
        oam_warning_log1(0, OAM_SF_CFG, "{wal_vendor_sniffer_handle::get sniffer mode fail, err_code[%d]}", ret);
        return ret;
    }
    sniffer_cmd_str += cmd_offset;
    if ((sniffer_mode[0] != '0') && (sniffer_mode[0] != '1')) {
        oam_warning_log0(0, OAM_SF_CFG, "{wal_vendor_sniffer_handle::sniffer_mode > 1}");
        return OAL_FAIL;
    }
    /* 获取cap_channel */
    ret = wal_get_cmd_one_arg(sniffer_cmd_str, cap_channel, WAL_SNIFFER_CAP_CHAN_STR_LEN, &cmd_offset);
    if (ret != OAL_SUCC) {
        oam_warning_log1(0, OAM_SF_CFG, "{wal_vendor_sniffer_handle::get cap_channel fail, err_code[%d]}", ret);
        return ret;
    }
    sniffer_cmd_str += cmd_offset;

    /* 获取cap_protocol_mode */
    ret = wal_get_cmd_one_arg(sniffer_cmd_str, cap_protocol_mode, WAL_SNIFFER_CAP_PROTOCOL_MODE_LEN, &cmd_offset);
    if (ret != OAL_SUCC) {
        oam_warning_log1(0, OAM_SF_CFG, "{wal_vendor_sniffer_handle::get cap_proto_mode fail, err_code[%d]}", ret);
        return ret;
    }
    if (sniffer_mode[0] == '1') { // sniffer使能
        ret = wal_vendor_enable_sniffer(p_net_dev, sniffer_ta_mac, sniffer_mode[0], cap_channel, cap_protocol_mode);
    } else {
        ret = wal_vendor_disable_sniffer(p_net_dev, sniffer_ta_mac, sniffer_mode[0], cap_channel, cap_protocol_mode);
    }
    if (ret != OAL_SUCC) {
        oam_warning_log1(0, OAM_SF_CFG, "{wal_vendor_sniffer_handle::set_mode err[%d]}", ret);
        return ret;
    }

    return OAL_SUCC;
}
OAL_STATIC int32_t hmac_sniffer_get_pkt_len_phy_addr(hmac_device_stru *hmac_device,
    mac_rx_ctl_stru *rx_ctrl, uint8_t **mac_payload_addr)
{
    int32_t pkt_len;

    if (hmac_device == NULL) {
        return 0;
    }
    if (hmac_device->sniffer_mode == WLAN_SINFFER_ON) {
        pkt_len = (int32_t)rx_ctrl->us_frame_len - (int32_t)SNIFFER_RX_INFO_SIZE;
        *mac_payload_addr += (rx_ctrl->us_frame_len - SNIFFER_RX_INFO_SIZE); // 偏移到payload尾部phy信息起始位置
    } else {
        pkt_len = (int32_t)rx_ctrl->us_frame_len;
        *mac_payload_addr += rx_ctrl->uc_mac_header_len;
    }

    return pkt_len;
}

OAL_STATIC oal_bool_enum_uint8 hmac_sniffer_data_is_invalid(hmac_device_stru *hmac_device,
    int32_t pkt_len, mac_rx_ctl_stru *rx_ctrl)
{
    uint16_t payload_len = rx_ctrl->us_frame_len - rx_ctrl->uc_mac_header_len;
    if (hmac_device == NULL) {
        return OAL_FALSE;
    }
    return (pkt_len < 0 ||
            ((hmac_device->sniffer_mode == WLAN_SINFFER_ON) && (payload_len < SNIFFER_RX_INFO_SIZE)) ||
            ((hmac_device->sniffer_mode == WLAN_SNIFFER_TRAVEL_CAP_ON) &&
            (payload_len < SNIFFER_RX_INFO_SIZE + sizeof(uint16_t)))) ? OAL_TRUE : OAL_FALSE;
}

/*
 * 函 数 名  : hmac_sniffer_save_data
 * 功能描述  : 手机抓包写到文件中
 * 1.日    期  : 2019年6月5日
 *   修改内容  : 新生成函数
 */
void hmac_sniffer_save_data(hmac_device_stru *hmac_device,
    oal_netbuf_stru *netbuf, uint16_t netbuf_num)
{
    oal_netbuf_stru *temp_netbuf = NULL;
    mac_rx_ctl_stru *rx_ctrl = NULL; /* 指向MPDU控制块信息的指针 */
    uint8_t *payload = NULL;
    hal_sniffer_rx_status_stru *rx_status = NULL;
    hal_sniffer_rx_statistic_stru *rx_statistic = NULL;
    ieee80211_radiotap_stru radiotap;
    hal_statistic_stru *per_rate = NULL;
    uint32_t *rate_kbps = NULL;
    int32_t pkt_len;
    /******************************************************************************************************************/
    /*                   netbuf                                                                                  */
    /* -------------------------------------------------------------------------------------------------------------- */
    /* |frame body |rx status |rx statistic | rate_kbps |  rate info   | original frame len(travel mode only) |       */
    /* -------------------------------------------------------------------------------------------------------------- */
    /* |variable   |   6      |     8       | 4         |      4       |                    2                 |       */
    /* -------------------------------------------------------------------------------------------------------------- */
    /*                                                                                                                */
    /******************************************************************************************************************/
    while (netbuf_num != 0) {
        temp_netbuf = netbuf;
        if (temp_netbuf == NULL) {
            break;
        }

        netbuf = oal_netbuf_next(temp_netbuf);

        /* 获取该MPDU的控制信息 */
        rx_ctrl = (mac_rx_ctl_stru *)oal_netbuf_cb(temp_netbuf);
        payload = oal_netbuf_payload(temp_netbuf);
        pkt_len = hmac_sniffer_get_pkt_len_phy_addr(hmac_device, rx_ctrl, &payload);
        if (hmac_sniffer_data_is_invalid(hmac_device, pkt_len, rx_ctrl) == OAL_TRUE) {
            oam_warning_log1(0, OAM_SF_RX, "iPacketLength(%d) < 0", pkt_len);
            continue;
        }

        rx_status = (hal_sniffer_rx_status_stru *)payload;
        rx_statistic = (hal_sniffer_rx_statistic_stru *)(rx_status + 1);
        rate_kbps = (uint32_t *)(rx_statistic + 1);
        per_rate = (hal_statistic_stru *)(rate_kbps + 1);

#ifdef _PRE_WLAN_FEATURE_SNIFFER_DEBUG
        oam_warning_log4(0, OAM_SF_RX, "{hmac_sniffer_save_data::chn[%d], frame len[%d], rate_kbps[%d], bandwidth[%d]}",
            rx_ctrl->uc_channel_number, rx_ctrl->us_frame_len, (*rate_kbps), per_rate->uc_bandwidth);

        oam_warning_log4(0, OAM_SF_RX, "{hmac_sniffer_save_data::rssi[%d], snr_ant0[%d], snr_ant1[%d], ant0_rssi[%d]}",
            rx_statistic->c_rssi_dbm, rx_statistic->c_snr_ant0, rx_statistic->c_snr_ant1, rx_statistic->c_ant0_rssi);

        oam_warning_log4(0, OAM_SF_RX,
            "{hmac_sniffer_save_data::status[%d],freq_bandwidth_mode[%d], ext_spatial_streams[%d], protocol_mode[%d].}",
            rx_status->bit_dscr_status, rx_status->bit_freq_bandwidth_mode,
            rx_status->bit_ext_spatial_streams, rx_status->un_nss_rate.st_rate.bit_protocol_mode);
#endif
        hmac_sniffer_fill_radiotap(&radiotap, rx_ctrl, rx_status, rx_statistic, payload, rate_kbps, per_rate);
#ifdef _PRE_WLAN_FEATURE_SNIFFER
#ifdef CONFIG_HW_SNIFFER
        /* 调用终端提供的接口写入到文件 */
        proc_sniffer_write_file((uint8_t *)&radiotap, sizeof(ieee80211_radiotap_stru),
                                (uint8_t *)oal_netbuf_payload(temp_netbuf), pkt_len, DIRECTION_MONITOR_MODE);
#endif
#endif
        netbuf_num--;
    }

    return;
}
uint32_t hmac_monitor_report_frame_to_sdt(mac_rx_ctl_stru *pst_cb_ctrl, oal_netbuf_stru *pst_curr_netbuf)
{
    uint8_t *puc_payload = NULL;
    mac_ieee80211_frame_stru *pst_frame_hdr = NULL;
    uint32_t rslt;
    if (oam_ota_get_switch(OAM_OTA_SWITCH_RX_80211_FRAME) != OAL_SWITCH_ON) {
        return OAL_SUCC;
    }
    puc_payload = mac_get_rx_payload_addr(pst_cb_ctrl, pst_curr_netbuf);
    pst_frame_hdr = (mac_ieee80211_frame_stru *)mac_get_rx_cb_mac_hdr(pst_cb_ctrl);

    rslt = oam_report_80211_frame(BROADCAST_MACADDR, (uint8_t *)(pst_frame_hdr),
        mac_get_rx_cb_mac_header_len(pst_cb_ctrl), puc_payload,
        pst_cb_ctrl->us_frame_len, OAM_OTA_FRAME_DIRECTION_TYPE_RX);
    return rslt;
}
uint32_t hmac_rx_process_data_event_monitor_handle(hmac_device_stru *pst_hmac_device,
    oal_netbuf_stru *pst_netbuf, uint16_t us_netbuf_num)
{
    mac_rx_ctl_stru *pst_rx_ctrl = NULL;

    pst_hmac_device->data_frames_cnt += us_netbuf_num;
    pst_rx_ctrl = (mac_rx_ctl_stru *)oal_netbuf_cb(pst_netbuf);
    if (oal_value_eq_any2(pst_hmac_device->pst_device_base_info->uc_monitor_ota_mode,
        WLAN_MONITOR_OTA_HOST_RPT, WLAN_MONITOR_OTA_ALL_RPT)) {
        hmac_monitor_report_frame_to_sdt(pst_rx_ctrl, pst_netbuf);
    }
    hmac_sniffer_save_data(pst_hmac_device, pst_netbuf, us_netbuf_num);
    hmac_rx_free_netbuf(pst_netbuf, us_netbuf_num);
    return OAL_SUCC;
}

uint8_t hmac_sniffer_filter_frame(hmac_device_stru *hmac_device, mac_rx_ctl_stru *rxctl)
{
    oal_bool_enum_uint8 is_filter_frame = OAL_TRUE;
    uint8_t mac_address[WLAN_MAC_ADDR_LEN];
    mac_ieee80211_frame_stru *frame_hdr = NULL;

    if (hmac_device == NULL) {
        return OAL_FALSE;
    }
    if (hmac_device->addr_filter_on == OAL_FALSE) {
        return OAL_FALSE;
    }

    frame_hdr = (mac_ieee80211_frame_stru *)mac_get_rx_cb_mac_hdr(rxctl);

    mac_get_addr1((uint8_t *)frame_hdr, mac_address, WLAN_MAC_ADDR_LEN);
    if (oal_compare_mac_addr(mac_address, hmac_device->monitor_mac_addr) == 0) {
        is_filter_frame = OAL_FALSE;
    }

    mac_get_address2((uint8_t *)frame_hdr, mac_address, WLAN_MAC_ADDR_LEN);
    if (oal_compare_mac_addr(mac_address, hmac_device->monitor_mac_addr) == 0) {
        is_filter_frame = OAL_FALSE;
    }

    mac_get_address3((uint8_t *)frame_hdr, mac_address, WLAN_MAC_ADDR_LEN);
    if (oal_compare_mac_addr(mac_address, hmac_device->monitor_mac_addr) == 0) {
        is_filter_frame = OAL_FALSE;
    }

    return is_filter_frame;
}

void hmac_sniffer_append_rx_info(hmac_device_stru *hmac_device, mac_rx_ctl_stru *rxctl, oal_netbuf_stru *netbuf,
    hal_sniffer_extend_info *sniffer_rx_info)
{
    hal_sniffer_rx_status_stru *sniffer_rx_status = &sniffer_rx_info->sniffer_rx_status;
    hal_sniffer_rx_statistic_stru *sniffer_rx_statistic = &sniffer_rx_info->sniffer_rx_statistic;
    hal_statistic_stru *per_rate = &sniffer_rx_info->per_rate;
    uint32_t *rate_kbps = &sniffer_rx_info->rate_kbps;
    uint8_t *payload_addr = get_netbuf_payload(netbuf) + rxctl->uc_mac_header_len;
    int32_t ret;
    uint16_t payload_len = (rxctl->us_frame_len - rxctl->uc_mac_header_len);
    if (hmac_device == NULL) {
        return;
    }
    /* 如果接收的帧长大于netbuf长度，修改为最大netbuf帧长减去SNIFFER_RX_INFO_SIZE，预留出填写rx info的区域 */
    if (rxctl->us_frame_len > (WLAN_LARGE_NETBUF_SIZE - (uint16_t)SNIFFER_RX_INFO_SIZE)) {
        rxctl->us_frame_len = (WLAN_LARGE_NETBUF_SIZE - (uint16_t)SNIFFER_RX_INFO_SIZE);
    }

    /* netbuf */
    /* ------------------------------------------------------------------------------------------------------------- */
    /* |frame body |rx status |rx statistic | rate_kbps |  rate info */
    /* ------------------------------------------------------------------------------------------------------------- */
    /* |variable   |   6      |     8       | 4         |      4 */
    /* ------------------------------------------------------------------------------------------------------------- */
    /* 正常抓包偏移到帧尾部添加phy信息 */
    if (hmac_device->sniffer_mode == WLAN_SINFFER_ON) {
        /* 正常抓包偏移到帧尾部添加phy信息 */
        payload_addr += payload_len;
    } else {
        /* 出行模式phy信息直接覆盖掉帧体内容上报 */
        memset_s(payload_addr, payload_len, 0, payload_len);
    }
    /* 添加rx status */
    ret = memcpy_s(payload_addr, sizeof(hal_sniffer_rx_status_stru), (uint8_t *)(sniffer_rx_status),
        sizeof(hal_sniffer_rx_status_stru));
    payload_addr += sizeof(hal_sniffer_rx_status_stru);

    /* 添加rx statistic */
    ret += memcpy_s(payload_addr, sizeof(hal_sniffer_rx_statistic_stru),
        (uint8_t *)(sniffer_rx_statistic), sizeof(hal_sniffer_rx_statistic_stru));
    payload_addr += sizeof(hal_sniffer_rx_statistic_stru);

    /* 添加rate_kbps */
    ret += memcpy_s(payload_addr, sizeof(uint32_t), (uint8_t *)(rate_kbps), sizeof(uint32_t));
    payload_addr += sizeof(uint32_t);

    /* 添加per_rate */
    ret += memcpy_s(payload_addr, sizeof(hal_statistic_stru), (uint8_t *)(per_rate), sizeof(hal_statistic_stru));

    if (hmac_device->sniffer_mode == WLAN_SNIFFER_TRAVEL_CAP_ON) {
        // 出行模式phy信息增加原始帧长字段
        payload_addr += sizeof(uint16_t);
        ret += memcpy_s(payload_addr, sizeof(uint16_t), (uint8_t *)(&rxctl->us_frame_len), sizeof(uint16_t));
    }

    if (ret != EOK) {
        oam_warning_log0(0, OAM_SF_RX, "{hmac_sniffer_append_rx_info::memcpy fail.}");
    }

    /* 更新frame len */
    if (hmac_device->sniffer_mode == WLAN_SINFFER_ON) {
        /* 更新长度加上上报phy信息长度 */
        rxctl->us_frame_len += SNIFFER_RX_INFO_SIZE;
    } else {
        rxctl->us_frame_len = rxctl->uc_mac_header_len + SNIFFER_RX_INFO_SIZE + sizeof(uint16_t);
    }
}

void hmac_sniffer_report(hmac_device_stru *hmac_device, mac_rx_ctl_stru *rxctl, oal_netbuf_stru *netbuf)
{
    if (hmac_device == NULL || rxctl == NULL || netbuf == NULL) {
        return;
    }

    /* 写文件 */
    hmac_sniffer_save_data(hmac_device, netbuf, 1);
}

void hmac_sniffer_rx_process_handle(hal_host_device_stru *hal_device, oal_netbuf_stru *netbuf, mac_rx_ctl_stru *rx_ctl)
{
    oal_netbuf_stru *temp_netbuf = netbuf;
    mac_rx_ctl_stru *rxctl = NULL;
    hal_sniffer_extend_info sniffer_rx_info;
    hmac_device_stru *hmac_device = hmac_res_get_mac_dev(hal_device->mac_device_id);
    if (hmac_device == NULL) {
        return;
    }
    /* 优先补充netbuf资源,移动写指针 */
    hal_host_sniffer_add_rx_ppdu_dscr(hal_device);

    while (temp_netbuf != NULL) {
        rxctl = (mac_rx_ctl_stru *)oal_netbuf_cb(temp_netbuf);
        /* 根据mac地址过滤 */
        if (hmac_sniffer_filter_frame(hmac_device, rxctl) == OAL_TRUE) {
            /* do nothing */
        } else {
            /* 上报信息结构体初始化 */
            memset_s(&sniffer_rx_info, sizeof(hal_sniffer_extend_info), 0, sizeof(hal_sniffer_extend_info));
            /* 填充sniffer rx信息 */
            hal_host_sniffer_rx_info_fill(hal_device, temp_netbuf, &sniffer_rx_info, rx_ctl);

            if (oal_value_eq_any2(hmac_device->pst_device_base_info->uc_monitor_ota_mode,
                WLAN_MONITOR_OTA_HOST_RPT, WLAN_MONITOR_OTA_ALL_RPT)) {
                hmac_monitor_report_frame_to_sdt(rxctl, temp_netbuf);
            }
            /* 将信息填到帧体后面并更新 frame length */
            hmac_sniffer_append_rx_info(hmac_device, rxctl, temp_netbuf, &sniffer_rx_info);
            /* 写入系统文件 */
            hmac_sniffer_report(hmac_device, rxctl, temp_netbuf);
        }
        temp_netbuf = oal_netbuf_next(temp_netbuf);
    }
}

void hmac_host_rx_sniffer_filter_check(hal_host_device_stru *hal_device, oal_netbuf_stru *netbuf,
    mac_rx_ctl_stru *rx_ctl)
{
    hmac_device_stru  *hmac_device = NULL;

    hmac_device = hmac_res_get_mac_dev(hal_device->mac_device_id);
    if (hmac_device == NULL) {
        oam_error_log0(hal_device->mac_device_id, OAM_SF_RX,
            "{hmac_host_rx_sniffer_filter_check::hmac_res_get_mac_dev fail}");
        hmac_rx_netbuf_list_free(netbuf);
        return;
    }
    hmac_sniffer_rx_process_handle(hal_device, netbuf, rx_ctl);
}

bool hmac_host_rx_sniffer_is_on(hal_host_device_stru *hal_dev)
{
    hmac_device_stru *hmac_device;
    hmac_device = hmac_res_get_mac_dev(hal_dev->mac_device_id);
    if (hmac_device == NULL) {
        return OAL_FALSE;
    }

    if ((hmac_device->en_monitor_mode == OAL_TRUE) && (hmac_device->sniffer_mode == WLAN_SINFFER_ON)) {
        return OAL_TRUE;
    }

    return OAL_FALSE;
}

uint32_t hmac_sniffer_rx_info_event(frw_event_mem_stru *frw_mem)
{
    frw_event_stru *frw_event = NULL;
    dmac_to_hmac_sniffer_info_event_stru *sniffer_rx_info = NULL;
    hmac_device_stru *hmac_device = NULL;

    if (frw_mem == NULL) {
        return OAL_FAIL;
    }

    frw_event = frw_get_event_stru(frw_mem);
    sniffer_rx_info = (dmac_to_hmac_sniffer_info_event_stru *)frw_event->auc_event_data;

    /* 数据刷新到hmac device */
    hmac_device = hmac_res_get_mac_dev(frw_event->st_event_hdr.uc_device_id);
    if (hmac_device == NULL) {
        oam_error_log0(frw_event->st_event_hdr.uc_device_id, OAM_SF_RX,
            "{hmac_sniffer_rx_info_event::hmac_res_get_mac_dev fail.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    oal_spin_lock(&hmac_device->d2h_sniffer_info);
    hmac_device->rssi0 = sniffer_rx_info->rssi0;
    hmac_device->rssi1 = sniffer_rx_info->rssi1;
    oal_spin_unlock(&hmac_device->d2h_sniffer_info);

    return OAL_SUCC;
}
uint32_t hmac_sniffer_device_rx_proc(hmac_vap_stru *hmac_vap, oal_netbuf_stru *netbuf, mac_rx_ctl_stru *rx_ctl)
{
    hal_host_device_stru *hal_device = hal_get_host_device(hmac_vap->hal_dev_id);
    if (hmac_host_rx_sniffer_is_on(hal_device) == OAL_TRUE) {
        hmac_host_rx_sniffer_filter_check(hal_device, netbuf, rx_ctl);
        return OAL_RETURN;
    }
    return OAL_CONTINUE;
}
#endif
