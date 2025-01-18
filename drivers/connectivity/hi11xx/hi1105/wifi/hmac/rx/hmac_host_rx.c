/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * 功能说明 : hmac_host_rx.c文件
 * 创建日期 : 2020年09月22日
 */

/* 1 头文件包含 */
#include "hmac_host_rx.h"
#include "mac_data.h"
#include "hmac_frag.h"
#include "hmac_11i.h"
#include "hmac_blockack.h"
#include "host_hal_ext_if.h"
#include "hmac_stat.h"
#include "hmac_wapi.h"
#include "hmac_ht_self_cure.h"
#include "hmac_vsp_if.h"
#include "hmac_config.h"
#ifdef _PRE_WLAN_FEATURE_SNIFFER
#include "hmac_sniffer.h"
#endif
#ifdef _PRE_WLAN_FEATURE_MCAST_AMPDU
#include "hmac_mcast_ampdu.h"
#endif
#include "hmac_mintp_log.h"
#ifdef _PRE_WLAN_CHBA_MGMT
#include "hmac_chba_ps.h"
#endif
#include "oam_event_wifi.h"
#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_HOST_RX_C
/*
 * 功能描述  : 802.11转换以太网格式
 * 1.日    期  : 2020年1月6日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC uint32_t hmac_rx_proc_80211_to_eth(oal_netbuf_stru *netbuf,
    mac_rx_ctl_stru *rx_ctrl, mac_ieee80211_frame_stru *frame_hdr)
{
    dmac_msdu_stru rx_msdu;
    uint8_t *frame_addr = NULL;

    memset_s(&rx_msdu, sizeof(dmac_msdu_stru), 0, sizeof(dmac_msdu_stru));
    mac_get_transmit_addr(frame_hdr, &frame_addr);
    oal_set_mac_addr(rx_msdu.auc_ta, frame_addr);

    /* 对当前的msdu进行赋值 */
    rx_msdu.pst_netbuf = netbuf;
    /* 802.11帧头结构 */
    /* 非聚合首帧：24字节的802.11mac_header + 2字节的QoS_control字段 */
    /* 聚合首帧：  24字节的802.11mac_header + 2字节的QoS_control字段 + 14字节的sub_amsdu头 */
    /* 聚合非首帧：14字节的sub_amsdu头 */
    if (mac_get_rx_cb_is_first_sub_msdu(rx_ctrl)) {
        /* 聚合首帧处理，获取源地址和目的地址 */
        mac_rx_get_sa(frame_hdr, &frame_addr);
        oal_set_mac_addr(rx_msdu.auc_sa, frame_addr);
        mac_rx_get_da(frame_hdr, &frame_addr);
        oal_set_mac_addr(rx_msdu.auc_da, frame_addr);
        /* 将netbuf的data指针指向mac frame的payload处 */
        oal_netbuf_pull(netbuf, rx_ctrl->uc_mac_header_len + (mac_rxcb_is_amsdu(rx_ctrl) ?
            MAC_SUBMSDU_HEADER_LEN : 0));
    } else {
        /* 聚合非首帧处理 */
        oal_set_mac_addr(rx_msdu.auc_da, (uint8_t *)oal_netbuf_data(netbuf));
        oal_set_mac_addr(rx_msdu.auc_sa, (uint8_t *)(oal_netbuf_data(netbuf) + OAL_MAC_ADDRESS_LEN));
        /* 将netbuf的data指针指向mac frame的payload处 */
        oal_netbuf_pull(netbuf, MAC_SUBMSDU_HEADER_LEN);
    }
    return hmac_rx_frame_80211_to_eth(netbuf, rx_msdu.auc_da, rx_msdu.auc_sa);
}

/*
 * 功能描述  : 接收相关维测统计
 * 1.日    期  : 2020年03月6日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC void hmac_rx_statistics(hmac_vap_stru *hmac_vap, hmac_user_stru *hmac_user, oal_netbuf_stru *netbuf)
{
    hmac_stat_vap_rx_netbuf(hmac_vap, netbuf);
    hmac_stat_device_rx_msdu(oal_netbuf_len(netbuf));
#ifdef _PRE_WLAN_CHBA_MGMT
    hmac_chba_stat_user_rx_netbuf(netbuf); /* chba低功耗相关接收统计 */
#endif
    return;
}
/*
 * 函 数 名   : hmac_rx_qos_data_need_drop
 * 功能描述   : 在未建ba场景下，软件检查qos data是否重复帧，此时硬件无法识别，sn 重复过滤，不重复更新sn
 * 1.日    期   : 2020-05-11
 *   作    者   : wifi
 */
OAL_STATIC oal_bool_enum_uint8 hmac_rx_qos_data_need_drop(hmac_host_rx_context_stru *rx_context)
{
    mac_rx_ctl_stru     *rx_ctl = rx_context->cb;
    hmac_user_stru      *hmac_user = rx_context->hmac_user;
    hmac_ba_rx_stru     *ba_rx_hdl = NULL;
    uint16_t             seq_frag_num;
    uint8_t              rx_tid;

    if (!hmac_rx_is_qos_data_frame(rx_ctl)) {
        return OAL_FALSE;
    }
    rx_tid = mac_get_rx_cb_tid(rx_ctl);
    if (!mac_tid_is_valid(rx_tid)) {
        oam_warning_log1(0, OAM_SF_RX, "{hmac_rx_qos_data_need_drop:: tid invalid[%d]}", rx_tid);
        return OAL_TRUE;
    }

    /* qos 已建ba返回 */
    ba_rx_hdl = hmac_user->ast_tid_info[rx_tid].pst_ba_rx_info;
    if (ba_rx_hdl != NULL && (ba_rx_hdl->en_ba_status == DMAC_BA_COMPLETE)) {
        return OAL_FALSE;
    }

    if (rx_ctl->bit_is_fragmented) {
        seq_frag_num = ((uint16_t)(rx_ctl->us_seq_num) << 4) | rx_ctl->bit_fragment_num; /* 合并sn放高4位 */
    } else {
        seq_frag_num = rx_ctl->us_seq_num;
    }

    /* no ba qos data，retry 且seq num相同则过滤，否则更新 */
    if (((mac_header_frame_control_stru *)&rx_ctl->us_frame_control)->bit_retry == OAL_TRUE &&
        (seq_frag_num == hmac_user->qos_last_seq_frag_num[rx_tid])) {
        oam_warning_log2(hmac_user->st_user_base_info.uc_vap_id, OAM_SF_RX,
            "{hmac_rx_qos_data_need_drop::tid is[%d],qos duplicate frame[%d].}", rx_tid, seq_frag_num);
        return OAL_TRUE;
    }

    hmac_user->qos_last_seq_frag_num[rx_tid] = seq_frag_num;
    return OAL_FALSE;
}
/* 功能描述 : 检查上报帧的vap是否有效 */
static uint32_t hmac_is_hal_vap_valid(hal_host_device_stru *hal_device, mac_rx_ctl_stru *rx_ctl)
{
    uint8_t   hal_vap_id;

    if (mac_rxcb_is_amsdu_sub_msdu(rx_ctl)) {
        return OAL_SUCC;
    }

    hal_vap_id = mac_get_rx_cb_hal_vap_id(rx_ctl);
    if (oal_unlikely(hal_vap_id >= HAL_MAX_VAP_NUM) && (hal_vap_id != g_wlan_spec_cfg->other_bss_id)) {
        oam_error_log1(0, OAM_SF_RX, "{hmac_is_hal_vap_valid::invalid hal vap id[%d].}", hal_vap_id);
        return OAL_FAIL;
    }

    if ((hal_vap_id < HAL_MAX_VAP_NUM) && (!hal_device->hal_vap_sts_info[hal_vap_id].hal_vap_valid)) {
        oam_warning_log2(0, OAM_SF_RX, "{hmac_is_hal_vap_valid::haldev[%d] invalid hal vap[%d]. }",
            hal_device->device_id, hal_vap_id);
        return OAL_FAIL;
    }

    return OAL_SUCC;
}
/* 功能描述 : 检查上报帧的tid是否有效 */
OAL_STATIC uint32_t hmac_is_tid_valid(hal_host_device_stru *hal_device, mac_rx_ctl_stru *rx_ctl)
{
    uint8_t frame_type;

    if (mac_rxcb_is_amsdu_sub_msdu(rx_ctl)) {
        return OAL_SUCC;
    }

    /* 判断该帧是不是qos帧 */
    frame_type = mac_get_frame_type_and_subtype((uint8_t *)&rx_ctl->us_frame_control);
    if (frame_type != (WLAN_FC0_SUBTYPE_QOS | WLAN_FC0_TYPE_DATA)) {
        return OAL_SUCC;
    }

    if (!mac_tid_is_valid(mac_get_rx_cb_tid(rx_ctl))) {
        oam_error_log1(0, OAM_SF_RX, "{hmac_is_tid_valid::invalid tid[%d].}", mac_get_rx_cb_tid(rx_ctl));
        return OAL_FAIL;
    }
    return OAL_SUCC;
}
static void hmac_alrx_process(hal_host_device_stru *hal_device, mac_rx_ctl_stru *rx_ctl)
{
    if (rx_ctl->rx_status != HAL_RX_SUCCESS) {
        hal_device->st_alrx.rx_ppdu_fail_num++;
    } else if (rx_ctl->bit_is_ampdu == OAL_TRUE) {
        hal_device->st_alrx.rx_ampdu_succ_num++;
    } else {
        hal_device->st_alrx.rx_normal_mdpu_succ_num++;
    }
    return;
}
uint8_t hmac_rx_da_is_in_same_bss(oal_netbuf_stru *netbuf, mac_rx_ctl_stru *rx_ctl,
    hmac_vap_stru *hmac_vap)
{
    hmac_user_stru *hmac_da_user = NULL;
    uint16_t user_dix = 0;
    uint8_t *puc_da = hmac_rx_get_eth_da(netbuf);

    if (mac_vap_find_user_by_macaddr(&hmac_vap->st_vap_base_info, puc_da, &user_dix) != OAL_SUCC) {
        oam_info_log0(0, 0, "{hmac_rx_da_is_in_same_bss::find da fail}");
        return OAL_FALSE;
    }

    hmac_da_user = (hmac_user_stru *)mac_res_get_hmac_user(user_dix);
    if (hmac_da_user == NULL) {
        oam_error_log1(0, 0, "{hmac_rx_da_is_in_same_bss::find da fail usr idx:%d}", user_dix);
        return OAL_FALSE;
    }

    if (hmac_da_user->st_user_base_info.en_user_asoc_state != MAC_USER_STATE_ASSOC) {
        hmac_mgmt_send_deauth_frame(&hmac_vap->st_vap_base_info,
            hmac_da_user->st_user_base_info.auc_user_mac_addr, MAC_NOT_AUTHED, OAL_FALSE);
        return OAL_FALSE;
    }

    mac_get_rx_cb_da_user_idx(rx_ctl) = hmac_da_user->st_user_base_info.us_assoc_id;
    return OAL_TRUE;
}

/*
 * 功能描述  : AP转发逻辑，仅处理单个netbuf
 * 1.日    期  : 2020年03月6日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void hmac_rx_ap_w2w_proc(hmac_host_rx_context_stru *rx_context,
    oal_netbuf_head_stru *release_list, oal_netbuf_head_stru *w2w_list)
{
    oal_netbuf_stru          *netbuf = NULL;
    mac_rx_ctl_stru          *rx_ctl = NULL;
    mac_ieee80211_frame_stru *copy_frame_hdr = NULL;
    oal_netbuf_stru          *netbuf_copy = NULL;
    hmac_vap_stru            *hmac_vap = rx_context->hmac_vap;
    oal_netbuf_stru          *next_netbuf = NULL;
    uint8_t                  *frame_ctl = NULL;

    oal_netbuf_search_for_each_safe(netbuf, next_netbuf, release_list) {
        rx_ctl = (mac_rx_ctl_stru *)oal_netbuf_cb(netbuf);
        frame_ctl = (uint8_t *)&rx_ctl->us_frame_control;
        /* 四地址amsdu不进行转发，上报协议栈解析后再转发 */
        if ((mac_is_4addr(frame_ctl) == OAL_TRUE) && rx_ctl->bit_amsdu_enable) {
            continue;
        }
        if (ether_is_multicast(hmac_rx_get_eth_da(netbuf)) == OAL_TRUE) {
            /* copy_frame_hdr复用mp13接口，mp16不用 */
            if (hmac_rx_copy_netbuff(&netbuf_copy, netbuf, rx_ctl->uc_mac_vap_id, &copy_frame_hdr) != OAL_SUCC) {
                continue;
            }
            hmac_rx_prepare_to_wlan(w2w_list, netbuf_copy);
        } else if (hmac_rx_da_is_in_same_bss(netbuf, rx_ctl, hmac_vap) == OAL_TRUE) {
            /* 目的用户已在AP的用户表中，进行WLAN_TO_WLAN转发 */
            oal_netbuf_delete(netbuf, release_list);
            hmac_rx_prepare_to_wlan(w2w_list, netbuf);
        } else {
            /* 该帧呆在链表里面 等待to lan */
            oam_info_log1(0, OAM_SF_RX, "{hmac_rx_host_ring_ap_proc::dst_is_valid[%d]}", rx_ctl->bit_dst_is_valid);
            oam_info_log4(0, OAM_SF_RX, "{hmac_rx_host_ring_ap_proc::band[%d] dst[%d] vap[%d]dst[%d]}",
                rx_ctl->bit_band_id, rx_ctl->bit_dst_band_id, rx_ctl->bit_vap_id, rx_ctl->dst_hal_vap_id);
        }
    }
}
/*
 * 功能描述   : 对收到的mpdu做重排序处理
 * 1.日    期   : 2018-04-11
 *   作    者   : wifi
 *   修改内容   : 新增函数
 */
uint32_t hmac_rx_data_wnd_proc(hmac_host_rx_context_stru *rx_context,
    hmac_ba_rx_stru *ba_rx_hdl, oal_netbuf_head_stru *rpt_list, uint8_t *buff_is_valid)
{
    uint32_t ret = OAL_SUCC;
    mac_rx_ctl_stru *rx_ctl = rx_context->cb;

    switch (rx_ctl->bit_process_flag) {
        case HAL_RX_PROC_FLAGS_RELEASE:
            ret = hmac_ba_rx_data_release(rx_context, ba_rx_hdl, rpt_list, buff_is_valid);
            break;
        case HAL_RX_PROC_FLAGS_BUFFER:
            ret = hmac_ba_rx_data_buffer(rx_context, ba_rx_hdl, rpt_list, buff_is_valid);
            break;
        case HAL_RX_PROC_FLAGS_OUT_OF_WIND_DROP:
        case HAL_RX_PROC_FLAGS_DUPLICATE_DROP:
        default:
            return OAL_FAIL;
    }

    if (oal_unlikely(ret != OAL_SUCC)) {
        /* 缓存或者直接上报处理失败时会进入此处，这里需要check失败的包上报 */
        hmac_rx_mpdu_to_netbuf_list(rpt_list, rx_context->netbuf);
        oam_info_log1(0, OAM_SF_RX, "{hmac_rx_data_wnd_proc:: process flag[%d].}", rx_ctl->bit_process_flag);
    }

    return OAL_SUCC;
}
/*
 * 功能描述  : 重排序逻辑
 * 1.日    期  : 2020.7.20
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_rx_proc_reorder(hmac_host_rx_context_stru *rx_context,
    oal_netbuf_head_stru *rpt_list, uint8_t *buff_is_valid)
{
    hmac_vap_stru   *hmac_vap = rx_context->hmac_vap;
    hmac_user_stru  *hmac_user = rx_context->hmac_user;
    mac_rx_ctl_stru *rx_ctl = rx_context->cb;
    uint32_t         ret;
    hmac_ba_rx_stru *ba_rx_hdl = NULL;

    if ((hmac_user == NULL) || (buff_is_valid == OAL_FALSE)) {
        return OAL_SUCC;
    }
    if (hmac_ba_check_rx_aggrate(hmac_vap, rx_ctl) != OAL_SUCC) {
        return OAL_SUCC;
    }
    ba_rx_hdl = hmac_user->ast_tid_info[mac_get_rx_cb_tid(rx_ctl)].pst_ba_rx_info;
    if (ba_rx_hdl == NULL) {
        return OAL_SUCC;
    }
    hmac_ba_rx_hdl_hold(ba_rx_hdl);
    if (ba_rx_hdl->en_ba_status != DMAC_BA_COMPLETE) {
        hmac_ba_rx_hdl_put(ba_rx_hdl);
        return OAL_SUCC;
    }
    ret = hmac_rx_data_wnd_proc(rx_context, ba_rx_hdl, rpt_list, buff_is_valid);
    if (ret != OAL_SUCC) {
        hmac_ba_rx_hdl_put(ba_rx_hdl);
        return ret;
    }
    hmac_ba_rx_hdl_put(ba_rx_hdl);
    return OAL_SUCC;
}

/*
 * 功能描述  : 当前vap已经up,找不到user,收到的是eapol帧时继续上报
 * 1.日    期  : 2020年06月28日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
oal_bool_enum_uint8 hmac_rx_eapol_while_sta_just_up(hmac_vap_stru *hmac_vap, oal_netbuf_stru *netbuf)
{
    mac_ether_header_stru *ether_hdr = (mac_ether_header_stru *)oal_netbuf_data(netbuf);

    if (hmac_vap->st_vap_base_info.en_vap_mode != WLAN_VAP_MODE_BSS_STA) {
        return OAL_FALSE;
    }

    if (hmac_vap->st_vap_base_info.en_vap_state != MAC_VAP_STATE_UP &&
        hmac_vap->st_vap_base_info.en_vap_state != MAC_VAP_STATE_STA_WAIT_ASOC) {
        oam_warning_log0(0, OAM_SF_RX, "{hmac_rx_ring_entry_proc:hmac_vap is not up}");
        return OAL_FALSE;
    }

    if (oal_byteorder_host_to_net_uint16(ETHER_TYPE_PAE) != ether_hdr->us_ether_type)  {
        return OAL_FALSE;
    }

    return OAL_TRUE;
}

/*
 * 功能描述   : rx获取数据帧报文类型,填充cb供后续业务流程使用
 * 1.日    期   : 2021.2.22
 *   作    者   : wifi
 *   修改内容   : 更新cb中data和以太网帧子类型，供后续业务流程使用
 */
void hmac_rx_netbuf_update_rxctl_data_type(oal_netbuf_stru *netbuf, mac_rx_ctl_stru *rx_ctl)
{
    mac_data_type_enum_uint8 datatype = MAC_DATA_NUM;
    uint16_t frame_format = rx_ctl->bit_frame_format;
    uint32_t frame_len = rx_ctl->us_frame_len;
    uint8_t *frame_hdr = NULL;
    mac_netbuff_payload_type eth_type = MAC_NETBUFF_PAYLOAD_BUTT;

    if (frame_format == MAC_FRAME_TYPE_80211) {
        datatype = mac_get_data_type_from_80211(netbuf, mac_get_rx_cb_mac_header_len(rx_ctl),
            mac_get_rx_cb_frame_len(rx_ctl) - mac_get_rx_cb_mac_header_len(rx_ctl));
    } else if (frame_format == MAC_FRAME_TYPE_RTH) {
        frame_hdr = oal_netbuf_data(netbuf);
        eth_type = mac_get_eth_data_subtype(netbuf, frame_len);
        if (eth_type == MAC_NETBUFF_PAYLOAD_SNAP) {
            /* 跳过DA/SA/length 14字节 */
            frame_hdr += ETHER_HDR_LEN;
            datatype = mac_get_data_type_from_8023(netbuf, frame_hdr, MAC_NETBUFF_PAYLOAD_SNAP,
                frame_len - ETHER_HDR_LEN, OAM_OTA_FRAME_DIRECTION_TYPE_RX);
        } else {
            datatype = mac_get_data_type_from_8023(netbuf, frame_hdr, MAC_NETBUFF_PAYLOAD_ETH, frame_len,
                OAM_OTA_FRAME_DIRECTION_TYPE_RX);
        }
    } else {
        oam_warning_log1(0, OAM_SF_RX, "hmac_rx_netbuf_update_rxctl_data_type:frame format[%d]", frame_format);
    }

    rx_ctl->bit_data_type  = datatype;
    rx_ctl->bit_eth_flag = eth_type;
}

void hmac_rx_netbuf_update_rxctl_data_type_mp16(oal_netbuf_stru *netbuf, mac_rx_ctl_stru *rx_ctl)
{
    mac_data_type_enum_uint8 datatype = MAC_DATA_NUM;
    uint16_t frame_format = rx_ctl->bit_frame_format;
    uint32_t frame_len = rx_ctl->us_frame_len;
    uint8_t *frame_hdr = NULL;
    mac_netbuff_payload_type eth_type = MAC_NETBUFF_PAYLOAD_BUTT;

    if (frame_format == MAC_FRAME_TYPE_80211) {
        datatype = mac_get_data_type_from_80211(netbuf, mac_get_rx_cb_mac_header_len(rx_ctl),
            mac_get_rx_cb_frame_len(rx_ctl) - mac_get_rx_cb_mac_header_len(rx_ctl));
    } else if (frame_format == MAC_FRAME_TYPE_RTH) {
        frame_hdr = oal_netbuf_data(netbuf);
        eth_type = mac_get_eth_data_subtype(netbuf, frame_len);
        if (eth_type == MAC_NETBUFF_PAYLOAD_SNAP) {
            /* 跳过DA/SA/length 14字节 */
            frame_hdr += ETHER_HDR_LEN;
            datatype = mac_get_data_type_from_8023(netbuf, frame_hdr, MAC_NETBUFF_PAYLOAD_SNAP,
                frame_len - ETHER_HDR_LEN, OAM_OTA_FRAME_DIRECTION_TYPE_RX);
        } else {
            datatype = mac_get_data_type_from_8023(netbuf, frame_hdr, MAC_NETBUFF_PAYLOAD_ETH, frame_len,
                OAM_OTA_FRAME_DIRECTION_TYPE_RX);
        }
    } else {
        oam_warning_log1(0, OAM_SF_RX, "hmac_rx_netbuf_update_rxctl_data_type:frame format[%d]", frame_format);
    }

    rx_ctl->bit_data_type  = datatype;
    rx_ctl->bit_eth_flag = eth_type;
}

/* Rxcb中amsdu非首帧的信息填充 */
void hmac_rx_update_submsdu_rxctl(mac_rx_ctl_stru *dst_rxcb, mac_rx_ctl_stru *src_rxcb, oal_netbuf_stru *netbuf)
{
    mac_get_rx_cb_tid(dst_rxcb) = mac_get_rx_cb_tid(src_rxcb);
    mac_get_rx_cb_hal_vap_id(dst_rxcb) = mac_get_rx_cb_hal_vap_id(src_rxcb);
    mac_rxcb_is_amsdu(dst_rxcb) = mac_rxcb_is_amsdu(src_rxcb);
    mac_get_rx_cb_is_first_sub_msdu(dst_rxcb) = OAL_FALSE;
    mac_get_rx_cb_ta_user_id(dst_rxcb) = mac_get_rx_cb_ta_user_id(src_rxcb);
    mac_get_rx_cb_ta_user_id(dst_rxcb) = mac_get_rx_cb_ta_user_id(src_rxcb);

    mac_get_rx_cb_mac_vap_id(dst_rxcb) = mac_get_rx_cb_mac_vap_id(src_rxcb);
    mac_get_rx_cb_seq_num(dst_rxcb) = mac_get_rx_cb_seq_num(src_rxcb);
    dst_rxcb->us_frame_control = src_rxcb->us_frame_control;
    dst_rxcb->us_rx_msb_pn = src_rxcb->us_rx_msb_pn;
    dst_rxcb->rx_lsb_pn = src_rxcb->rx_lsb_pn;

    /* frame len刷新 当芯片上报802.11格式的AMSDU帧时，且非首个msdu不包含802.11头 */
    if (dst_rxcb->bit_frame_format == MAC_FRAME_TYPE_80211 && mac_rxcb_is_amsdu_sub_msdu(dst_rxcb)) {
        dst_rxcb->us_frame_len += dst_rxcb->uc_mac_header_len;
    }
    dst_rxcb->last_msdu_in_amsdu = (netbuf->next == NULL);
}
uint32_t hmac_rx_netbuf_check_status(mac_rx_ctl_stru *cb, oal_netbuf_stru *netbuf)
{
    hmac_vap_stru *hmac_vap = NULL;
    hmac_vap_stat_stru  *hmac_vap_stat = NULL;
    uint8_t  rx_status = cb->rx_status;
    if (rx_status == HAL_RX_SUCCESS) {
        return OAL_SUCC;
    }
    hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(cb->uc_mac_vap_id);
    if (hmac_vap == NULL) {
        return OAL_FAIL;
    }
    hmac_vap_stat = hmac_stat_get_vap_stat(hmac_vap);
    if (rx_status == HAL_RX_NEW) {
        oam_error_log1(0, OAM_SF_RX, "hmac_rx_netbuf_check_status::rx_status:[%d]", rx_status);
        oam_report_dscr(BROADCAST_MACADDR, (uint8_t *)oal_netbuf_data(netbuf), HAL_RX_DSCR_LEN,
            OAM_OTA_TYPE_RX_MSDU_DSCR);
    }
    HMAC_VAP_DFT_STATS_PKT_INCR(hmac_vap_stat->rx_dropped_misc, 1);
    return OAL_FAIL;
}

OAL_STATIC void hmac_rx_netbug_check_cb_valid_ota_report(mac_rx_ctl_stru *rx_ctl, oal_netbuf_stru *netbuf)
{
    oam_report_netbuf_cb(BROADCAST_MACADDR,
                         (uint8_t *)oal_netbuf_cb(netbuf),
                         sizeof(mac_rx_ctl_stru),
                         OAM_OTA_FRAME_DIRECTION_TYPE_RX);
    if (rx_ctl->bit_frame_format == MAC_FRAME_TYPE_RTH) {
        oam_report_eth_frame(BROADCAST_MACADDR,
                             (uint8_t *)oal_netbuf_data(netbuf),
                             rx_ctl->us_frame_len,
                             OAM_OTA_FRAME_DIRECTION_TYPE_RX);
    } else if (rx_ctl->bit_frame_format == MAC_FRAME_TYPE_80211) {
        oam_report_80211_frame(BROADCAST_MACADDR,
                               (uint8_t *)mac_get_rx_cb_mac_header_addr(rx_ctl),
                               rx_ctl->uc_mac_header_len,
                               mac_get_rx_payload_addr(rx_ctl, netbuf),
                               rx_ctl->us_frame_len,
                               OAM_OTA_FRAME_DIRECTION_TYPE_RX);
    }
}
/* 功能描述  : 检查cb部分字段取值范围是否有效，若无效，上报对应cb和msdu */
OAL_STATIC uint32_t hmac_rx_netbuf_chack_cb_is_valid(mac_rx_ctl_stru *rx_ctl, oal_netbuf_stru *netbuf)
{
    if (mac_get_rx_cb_tid(rx_ctl) < WLAN_TID_MAX_NUM) {
        return OAL_SUCC;
    }
    oam_error_log1(0, OAM_SF_RX, "{hmac_rx_netbuf_chack_cb_is_valid::invalid cb, tid[%d].}",
                   mac_get_rx_cb_tid(rx_ctl));
    hmac_rx_netbug_check_cb_valid_ota_report(rx_ctl, netbuf);
    return OAL_FAIL;
}
/*
 * 功能描述  : MPDU级别(msdu或者amsdu)的netbuf成链并生成cb
 * 1.日    期  : 2020.7.20
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_host_rx_mpdu_build_cb(hal_host_device_stru *hal_dev, oal_netbuf_stru *netbuf)
{
    mac_rx_ctl_stru *rxctl = NULL;
    uint8_t          first_msdu = OAL_TRUE;
    mac_rx_ctl_stru  first_rx_ctl;
    oal_netbuf_stru *next = NULL;

    memset_s(&first_rx_ctl, sizeof(mac_rx_ctl_stru), 0, sizeof(mac_rx_ctl_stru));
    while (netbuf != NULL) {
        next = oal_netbuf_next(netbuf);
        rxctl = (mac_rx_ctl_stru *)oal_netbuf_cb(netbuf);
        if (hal_host_rx_get_msdu_info_dscr(hal_dev, netbuf, rxctl, first_msdu) != OAL_SUCC) {
            return OAL_FAIL;
        }
        /*  fcs错误帧提前过滤, 防止帧长错误时候取报文类型读越界 */
        if (first_msdu && (hmac_rx_netbuf_check_status(rxctl, netbuf) != OAL_SUCC)) {
            hmac_rx_exception_free_stat(hal_dev);
            return OAL_FAIL;
        }
        if (hmac_rx_netbuf_chack_cb_is_valid(rxctl, netbuf) != OAL_SUCC) {
            return OAL_FAIL;
        }
        /* AMSDU专有处理流程 */
        if (mac_rxcb_is_first_msdu(rxctl) == OAL_TRUE) {
            memcpy_s(&first_rx_ctl, sizeof(mac_rx_ctl_stru), rxctl, sizeof(mac_rx_ctl_stru));
            first_msdu = OAL_FALSE;
        } else if (first_msdu == OAL_FALSE) {
            hmac_rx_update_submsdu_rxctl(rxctl, &first_rx_ctl, netbuf);
        }

        wlan_chip_update_rxctl_data_type(netbuf, rxctl);
        netbuf = next;
    }
    return OAL_SUCC;
}

/*
 * 功能描述  : host rx接收方向去分片流程封装
 * 1.日    期  : 2020.5.21
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
oal_netbuf_stru *hmac_rx_defrag(hmac_host_rx_context_stru *rx_context)
{
    hmac_user_stru *hmac_user = rx_context->hmac_user;
    oal_netbuf_stru *netbuf = rx_context->netbuf;
    mac_rx_ctl_stru *rx_ctl = rx_context->cb;

    if ((rx_ctl->bit_amsdu_enable == OAL_TRUE) ||
        (rx_ctl->bit_frame_format != MAC_FRAME_TYPE_80211) ||
        rx_context->hmac_user == NULL) {
        return netbuf;
    }
    return hmac_defrag_process(hmac_user, netbuf, rx_ctl->uc_mac_header_len);
}

/*
 * 功能描述  : 用户加密，接收到的数据帧不加密，则过滤
 * 1.日    期  : 2020.12.28
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
static hmac_rx_frame_ctrl_enum hmac_host_rx_filter_encrypt(hmac_vap_stru *hmac_vap, hmac_user_stru *hmac_user,
    mac_rx_ctl_stru *rx_ctl)
{
    mac_header_frame_control_stru *frame_ctl = NULL;
    wlan_ciper_protocol_type_enum_uint8 user_cipher_type;
    if (hmac_user == NULL) {
        return HMAC_RX_FRAME_CTRL_GOON;
    }

    frame_ctl = (mac_header_frame_control_stru *)(&rx_ctl->us_frame_control);
    user_cipher_type = hmac_user->st_user_base_info.st_key_info.en_cipher_type;
    if (user_cipher_type == WLAN_80211_CIPHER_SUITE_WAPI && wlan_chip_is_support_hw_wapi() == OAL_FALSE) {
        /* 软件WAPI 加解密，rx_ctrl加密类型未填写，不过滤 */
        return HMAC_RX_FRAME_CTRL_GOON;
    }
    /* 加密场景接收到非加密的数据帧，则过滤；null帧、QOS null帧、eapol帧、WAI帧无需过滤 */
    if ((user_cipher_type != WLAN_80211_CIPHER_SUITE_NO_ENCRYP) &&
        (rx_ctl->bit_cipher_type == WLAN_80211_CIPHER_SUITE_NO_ENCRYP) &&
        (frame_ctl->bit_type == WLAN_DATA_BASICTYPE)) {
        uint8_t uc_data_type = rx_ctl->bit_data_type;
        if ((frame_ctl->bit_sub_type != WLAN_NULL_FRAME) &&
            (frame_ctl->bit_sub_type != WLAN_QOS_NULL_FRAME) &&
            (uc_data_type != MAC_DATA_EAPOL) &&
            (uc_data_type != MAC_DATA_WAPI)) {
            oam_warning_log1(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_RX,
                "{hmac_host_rx_filter_encrypt::plaintext drop! data type[%d]}",
                uc_data_type);
            return HMAC_RX_FRAME_CTRL_DROP;
        }
    }
    return HMAC_RX_FRAME_CTRL_GOON;
}

/* 过滤A-MSDU首帧DA为AA-AA-03-00-00-00 的异常A-MSDU 帧 */
OAL_STATIC hmac_rx_frame_ctrl_enum hmac_host_rx_filter_abnormal_amsdu(hmac_vap_stru *hmac_vap,
    oal_netbuf_stru *netbuf, mac_rx_ctl_stru *rx_cb_ctrl)
{
    uint8_t *dst_addr = NULL;
    uint8_t frame_format;
    uint8_t mac_addr_snap_header[WLAN_MAC_ADDR_LEN] = {0xAA, 0xAA, 0x03, 0x00, 0x00, 0x00};

    if (!rx_cb_ctrl->bit_amsdu_enable || !rx_cb_ctrl->bit_is_first_buffer) {
        return HMAC_RX_FRAME_CTRL_GOON;
    }
    frame_format = rx_cb_ctrl->bit_frame_format;
    if (frame_format == MAC_FRAME_TYPE_80211) {
        uint8_t *ieee80211_hdr = oal_netbuf_data(netbuf);
        /* 80211 格式A-MSDU DA在80211 帧头后 */
        dst_addr = (ieee80211_hdr + rx_cb_ctrl->uc_mac_header_len + MAC_SUBMSDU_DA_OFFSET);
    } else if (frame_format == MAC_FRAME_TYPE_RTH) {
        mac_ether_header_stru *eth_hdr = (mac_ether_header_stru *)oal_netbuf_data(netbuf);
        dst_addr = eth_hdr->auc_ether_dhost;
    } else {
        return HMAC_RX_FRAME_CTRL_GOON;
    }

    if (oal_memcmp(dst_addr, mac_addr_snap_header, WLAN_MAC_ADDR_LEN) == 0) {
        return HMAC_RX_FRAME_CTRL_DROP;
    }

    return HMAC_RX_FRAME_CTRL_GOON;
}

/*
 * 功能描述  : host rx预先过滤流程，主要涉及device rx部分已经设置的过滤
 * 1.日    期  : 2020.7.20
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
hmac_rx_frame_ctrl_enum hmac_host_rx_pre_abnormal_filter(hmac_host_rx_context_stru *rx_context)
{
    hal_host_device_stru    *hal_dev = rx_context->hal_dev;
    oal_netbuf_stru         *netbuf = rx_context->netbuf;
    mac_rx_ctl_stru         *rx_ctl = rx_context->cb;
    hmac_vap_stru           *hmac_vap = rx_context->hmac_vap;
    hmac_vap_stat_stru      *hmac_vap_stat = NULL;

    if (hmac_vap == NULL) {
        return HMAC_RX_FRAME_CTRL_DROP;
    }

    hmac_vap_stat = hmac_stat_get_vap_stat(hmac_vap);

    if (hal_dev->st_alrx.en_al_rx_flag != 0) {
        hmac_alrx_process(hal_dev, rx_ctl);
        HMAC_VAP_DFT_STATS_PKT_INCR(hmac_vap_stat->rx_dropped_misc, 1);
        return HMAC_RX_FRAME_CTRL_DROP;
    }
#ifdef _PRE_WLAN_FEATURE_SNIFFER
    if (hmac_host_rx_sniffer_is_on(hal_dev) == OAL_TRUE) {
        hmac_host_rx_sniffer_filter_check(hal_dev, netbuf, rx_ctl);
        return HMAC_RX_FRAME_CTRL_DROP;
    }
#endif
    if ((hmac_is_hal_vap_valid(hal_dev, rx_ctl) != OAL_SUCC) ||
        (hmac_is_tid_valid(hal_dev, rx_ctl)) != OAL_SUCC) {
        HMAC_VAP_DFT_STATS_PKT_INCR(hmac_vap_stat->rx_dropped_misc, 1);
        return HMAC_RX_FRAME_CTRL_DROP;
    }
    /* 加密收到非加密的数据帧需要过滤处理,只处理首帧 */
    if (hmac_host_rx_filter_encrypt(hmac_vap, rx_context->hmac_user, rx_ctl) == HMAC_RX_FRAME_CTRL_DROP) {
        return HMAC_RX_FRAME_CTRL_DROP;
    }

    /* 异常AMSDU 帧过滤 */
    if (hmac_host_rx_filter_abnormal_amsdu(hmac_vap, netbuf, rx_ctl) == HMAC_RX_FRAME_CTRL_DROP) {
        oam_warning_log0(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_RX,
            "hmac_host_rx_pre_abnormal_filter::msdu da is snap llc header!");
        return HMAC_RX_FRAME_CTRL_DROP;
    }

    return HMAC_RX_FRAME_CTRL_GOON;
}

/*
 * 功能描述  : aput场景下，lut idx无效，重新查找mac addr,查找失败则对帧丢弃处理
 * 1.日    期  : 2020年06月28日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC hmac_user_stru *hmac_ap_rx_recheck_user_idx(hmac_vap_stru *hmac_vap,
    oal_netbuf_stru *netbuf, mac_rx_ctl_stru *rx_ctl)
{
    mac_ieee80211_frame_stru *frmhdr = NULL;
    uint8_t *transmit_addr = NULL;
    hmac_user_stru *hmac_user = NULL;
    uint8_t usr_lut = rx_ctl->bit_ta_user_idx;
    uint16_t user_idx;

    /* lut为无效值且为80211帧时，才进行查找,此为异常保护流程 */
    if ((usr_lut < g_wlan_spec_cfg->invalid_user_id) ||
        (rx_ctl->bit_frame_format != MAC_FRAME_TYPE_80211)) {
        return NULL;
    }
    frmhdr = (mac_ieee80211_frame_stru *)oal_netbuf_header(netbuf);
    transmit_addr = frmhdr->auc_address2;
    if (mac_vap_find_user_by_macaddr(&(hmac_vap->st_vap_base_info), transmit_addr, &user_idx) == OAL_SUCC) {
        hmac_user = (hmac_user_stru *)mac_res_get_hmac_user(user_idx);
    }
    return hmac_user;
}

/*
 * 功能描述  : 根据lut idx获取user
 * 1.日    期  : 2020.7.20
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_INLINE hmac_user_stru *hmac_host_rx_lut_get_user(hmac_vap_stru *hmac_vap, oal_netbuf_stru *netbuf,
                                                     hal_host_device_stru *hal_dev, mac_rx_ctl_stru *cb)
{
    hmac_user_stru *hmac_user = NULL;
    uint8_t usr_lut = cb->bit_ta_user_idx;

    if ((usr_lut < HAL_MAX_LUT) && (hal_dev->user_sts_info[usr_lut].user_valid)) {
        hmac_user = (hmac_user_stru *)mac_res_get_hmac_user(hal_dev->user_sts_info[usr_lut].user_id);
    }
    if (oal_unlikely(hmac_user == NULL) &&
       !mac_rx_dscr_need_drop(cb->rx_status) && (hal_dev->st_alrx.en_al_rx_flag == HAL_ALWAYS_RX_DISABLE)) {
        oam_warning_log1(hal_dev->device_id, OAM_SF_ANY,
                         "hmac_host_rx_lut_get_user:get user fail, lut idx[%d]", usr_lut);
        /* 漫游过程中接收到数据帧信息输出 */
        if (hmac_vap->st_vap_base_info.en_vap_state == MAC_VAP_STATE_ROAMING) {
            hmac_rx_report_eth_frame(&hmac_vap->st_vap_base_info, netbuf);
        }
    }
    return hmac_user;
}

/*
 * 功能描述  : 将cb中的user id统一更新为mac user id
 * 1.日    期  : 2020.7.20
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_INLINE void hmac_host_rx_update_cb_user_idx(hmac_user_stru *hmac_user, oal_netbuf_stru *netbuf)
{
    mac_rx_ctl_stru *rx_ctl = NULL;
    uint16_t user_idx;

    if (hmac_user == NULL) {
        return;
    }

    user_idx = hmac_user->st_user_base_info.us_assoc_id;

    for (; netbuf; netbuf = oal_netbuf_next(netbuf)) {
        rx_ctl = (mac_rx_ctl_stru *)oal_netbuf_cb(netbuf);
        rx_ctl->bit_ta_user_idx = user_idx;
    }
}

/*
 * 功能描述  : 构建host rx上下文
 * 1.日    期  : 2020.7.20
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_host_build_rx_context(hal_host_device_stru *hal_dev, oal_netbuf_stru *netbuf,
    hmac_host_rx_context_stru *rx_context)
{
    mac_rx_ctl_stru *cb = (mac_rx_ctl_stru *)oal_netbuf_cb(netbuf);
    hmac_vap_stru *hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(cb->uc_mac_vap_id);
    hmac_user_stru *hmac_user = NULL;
    if (hmac_vap == NULL) {
        oam_error_log0(cb->uc_mac_vap_id, OAM_SF_ANY, "hmac_host_build_rx_context:hmac_vap null");
        return OAL_FAIL;
    }
    rx_context->hal_dev = hal_dev;
    rx_context->hmac_vap = hmac_vap;
    hmac_user = hmac_host_rx_lut_get_user(hmac_vap, netbuf, hal_dev, cb);
    if ((hmac_user == NULL) && (hmac_vap->st_vap_base_info.en_vap_mode == WLAN_VAP_MODE_BSS_AP)) {
        hmac_user = hmac_ap_rx_recheck_user_idx(hmac_vap, netbuf, cb);
    }
    hmac_host_rx_update_cb_user_idx(hmac_user, netbuf);
    rx_context->hmac_user = hmac_user;
    rx_context->netbuf = netbuf;
    rx_context->cb = cb;
    return OAL_SUCC;
}

/*
 * 功能描述  : host rx预处理，统计逻辑
 * 1.日    期  : 2020.7.20
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void hmac_host_rx_pre_static_proc(hmac_host_rx_context_stru *rx_context)
{
}

/*
 * 功能描述  : host rx预处理，业务逻辑
 * 1.日    期  : 2020.7.20
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_host_rx_pre_proc_feature(hmac_host_rx_context_stru *rx_context)
{
    return OAL_SUCC;
}

void hmac_host_ring_rx_static_proc(hmac_host_rx_context_stru *rx_context)
{
    oal_netbuf_stru *netbuf = rx_context->netbuf;
    hmac_device_stat_stru *hmac_device_stats = hmac_stat_get_device_stats();
    for (; netbuf != NULL; netbuf = oal_netbuf_next(netbuf)) {
        oal_atomic_add(&(hmac_device_stats->host_ring_rx_packets), 1);
    }
}
/*
 * 功能描述  : host rx流程预处理函数，主要包括AMSDU成链，cb生成，device部分过滤操作
 * 1.日    期  : 2020.7.20
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_host_rx_proc_dev_routine(hal_host_device_stru *hal_dev,
    oal_netbuf_stru *netbuf, hmac_host_rx_context_stru *rx_context)
{
    hal_host_rx_amsdu_list_build(hal_dev, netbuf);
    if (hal_host_rx_proc_msdu_dscr(hal_dev, netbuf) != OAL_SUCC) {
        hmac_rx_netbuf_list_free(netbuf);
        return OAL_FAIL;
    }
    if (hmac_host_rx_mpdu_build_cb(hal_dev, netbuf) != OAL_SUCC) {
        hmac_rx_netbuf_list_free(netbuf);
        return OAL_FAIL;
    }
    if (hmac_host_build_rx_context(hal_dev, netbuf, rx_context) != OAL_SUCC) {
        hmac_rx_netbuf_list_free(netbuf);
        return OAL_FAIL;
    }
    if (hmac_host_rx_pre_abnormal_filter(rx_context) != HMAC_RX_FRAME_CTRL_GOON) {
        hmac_rx_exception_free_stat(hal_dev);
        hmac_rx_netbuf_list_free(netbuf);
        return OAL_FAIL;
    }
    hmac_host_rx_pre_static_proc(rx_context);
    if (hmac_host_rx_pre_proc_feature(rx_context) != OAL_SUCC) {
        hmac_rx_netbuf_list_free(netbuf);
        return OAL_FAIL;
    }
    hmac_host_ring_rx_static_proc(rx_context);
    return OAL_SUCC;
}

/*
 * 功能描述  : 通用统计处理流程
 * 1.日    期  : 2020.7.20
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void hmac_host_rx_static_proc(hmac_host_rx_context_stru *rx_context)
{
    hmac_vap_stru *hmac_vap = rx_context->hmac_vap;
    oal_netbuf_stru *netbuf = rx_context->netbuf;
    mac_rx_ctl_stru *rx_ctl = rx_context->cb;

    for (;netbuf != NULL; netbuf = oal_netbuf_next(netbuf)) {
        /* 此统计位置需要调整 */
        hmac_rx_statistics(hmac_vap, rx_context->hmac_user, netbuf);
    }

    if (rx_ctl->bit_mcast_bcast == OAL_FALSE) {
        oal_atomic_inc(&(hmac_vap->st_hmac_arp_probe.rx_unicast_pkt_to_lan));
    }
}

/*
 * 功能描述  : 获取netbuf对应以太帧类型,兼容80211及8023
 * 1.日    期  : 2020.7.20
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
#define ETHER_HEADER_ETH_TYPE_OFFSET 12
#define SNAP_HEADER_ETH_TYPE_OFFSET 6
OAL_INLINE uint16_t hmac_rx_netbuf_get_ether_type(oal_netbuf_stru *netbuf,
    mac_rx_ctl_stru *mac_rx_ctl)
{
    uint16_t frame_formate;
    uint8_t *header = NULL;
    uint16_t ether_type = 0;

    frame_formate = mac_rx_ctl->bit_frame_format;
    header = oal_netbuf_data(netbuf);
    if (frame_formate == MAC_FRAME_TYPE_80211) {
        ether_type = *(uint16_t *)(header + SNAP_HEADER_ETH_TYPE_OFFSET);
    } else if (frame_formate == MAC_FRAME_TYPE_RTH) {
        ether_type = *(uint16_t *)(header + ETHER_HEADER_ETH_TYPE_OFFSET);
    }
    return ether_type;
}

/*
 * 功能描述  : 通用业务过滤流程
 * 1.日    期  : 2020.7.20
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_INLINE hmac_rx_frame_ctrl_enum hmac_host_rx_feature_filter(hmac_host_rx_context_stru *rx_context)
{
    hmac_vap_stru *hmac_vap = rx_context->hmac_vap;
    hmac_user_stru *hmac_user = rx_context->hmac_user;
    oal_netbuf_stru *netbuf = rx_context->netbuf;
    mac_rx_ctl_stru *mac_rx_ctl = NULL;
    uint16_t ether_type;

    mac_rx_ctl = (mac_rx_ctl_stru *)oal_netbuf_cb(netbuf);
    if (hmac_user == NULL) {
        oam_warning_log1(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_RX,
                         "{hmac_host_rx_feature_filter::user[%d] null!}",
                         mac_get_rx_cb_ta_user_id(mac_rx_ctl));
        return HMAC_RX_FRAME_CTRL_DROP;
    }

    if (hmac_rx_qos_data_need_drop(rx_context) == OAL_TRUE) {
        return HMAC_RX_FRAME_CTRL_DROP;
    }

    ether_type = hmac_rx_netbuf_get_ether_type(netbuf, mac_rx_ctl);
    if (hmac_11i_ether_type_filter(hmac_vap, hmac_user, ether_type) != OAL_SUCC) {
        return HMAC_RX_FRAME_CTRL_DROP;
    }
#ifdef _PRE_WLAN_FEATURE_MCAST_AMPDU
    if (hmac_mcast_ampdu_rx_proc(rx_context) == HMAC_RX_FRAME_CTRL_DROP) {
        return HMAC_RX_FRAME_CTRL_DROP;
    }
#endif
    return HMAC_RX_FRAME_CTRL_GOON;
}

/*
 * 功能描述  : 将netbuf链加入netbuf_head结构
 * 1.日    期  : 2020.7.20
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_INLINE void hmac_rx_netbuf_join_to_list(oal_netbuf_stru *netbuf, oal_netbuf_head_stru *list)
{
    oal_netbuf_stru *next = NULL;

    while (netbuf != NULL) {
        next = oal_netbuf_next(netbuf);
        oal_netbuf_add_to_list_tail(netbuf, list);
        netbuf = next;
    }
}

/*
 * 功能描述  : 将接收上下文中的netbuf链加入链表尾部
 * 1.日    期  : 2020.7.20
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_INLINE void hmac_rx_context_netbuf_add_to_list(hmac_host_rx_context_stru *rx_context,
    oal_netbuf_head_stru *list, uint8_t buff_is_valid)
{
    oal_netbuf_stru *netbuf = rx_context->netbuf;

    if (buff_is_valid) {
        hmac_rx_netbuf_join_to_list(netbuf, list);
    }
    rx_context->netbuf = NULL;
}

static uint8_t hmac_rx_vip_info_proc_data_eapol(mac_ether_header_stru *ether_hdr, mac_rx_ctl_stru *rx_ctrl,
    mac_vap_stru *vap, uint32_t len)
{
    mac_eapol_type_enum_uint8 eapol_type;
    /* netbuf 长度判断 */
    if (len < sizeof(mac_ether_header_stru) + sizeof(mac_eapol_header_stru)) {
        oam_error_log1(0, OAM_SF_RX, "hmac_rx_vip_info_proc::len[%d]", len);
        return MAC_EAPOL_PTK_BUTT;
    }
    eapol_type = mac_get_eapol_key_type((uint8_t *)(ether_hdr + 1));
    oam_warning_log3(vap->uc_vap_id, OAM_SF_RX, "{hmac_rx_vip_info_proc::EAPOL type=%u, len==%u, \
        user[%d].}[1:1/4 2:2/4 3:3/4 4:4/4]", eapol_type, len, mac_get_rx_cb_ta_user_id(rx_ctrl));
    return eapol_type;
}

static uint32_t hmac_rx_vip_info_proc_data_dhcp(mac_ether_header_stru *ether_hdr, uint8_t data_type,
    mac_vap_stru *vap, uint32_t payload_len)
{
    oal_ip_header_stru *ip_hdr = NULL;
    uint8_t sip[ETH_SENDER_IP_ADDR_LEN], dip[ETH_SENDER_IP_ADDR_LEN]; /* sender IP address */
    int32_t l_ret = EOK;
    uint8_t dhcp_type;

    if (payload_len < sizeof(mac_ether_header_stru) + sizeof(oal_ip_header_stru)) {
        oam_error_log2(0, OAM_SF_RX, "hmac_rx_vip_info_proc::DHCP buf_len[%d]data_type[%d]", payload_len, data_type);
        return -OAL_EFAIL;
    }

    ip_hdr = (oal_ip_header_stru *)(ether_hdr + 1);
    l_ret += memcpy_s((uint8_t *)sip, ETH_SENDER_IP_ADDR_LEN, (uint8_t *)&ip_hdr->saddr, sizeof(uint32_t));
    l_ret += memcpy_s((uint8_t *)dip, ETH_SENDER_IP_ADDR_LEN, (uint8_t *)&ip_hdr->daddr, sizeof(uint32_t));
    if (l_ret != EOK) {
        oam_error_log0(0, OAM_SF_RX, "hmac_rx_vip_info_proc::DHCP memcpy fail!");
        return l_ret;
    }

    /* ip tot len校验 */
    if (payload_len != sizeof(mac_ether_header_stru) + oal_net2host_short(ip_hdr->us_tot_len)) {
        oam_warning_log2(0, OAM_SF_RX, "hmac_rx_vip_info_proc::DHCP netbuf_len[%d] tot_len[%d]",
            payload_len, oal_net2host_short(ip_hdr->us_tot_len));
        return -OAL_EFAIL;
    }

    dhcp_type = mac_get_dhcp_frame_type(ip_hdr, payload_len - sizeof(mac_ether_header_stru));
    oam_warning_log2(vap->uc_vap_id, OAM_SF_RX, "{hmac_rx_vip_info_proc::DHCP type=%d len=%d.[1:discovery 2:offer \
        3:request 4:decline 5:ack 6:nack 7:release 8:inform.]", dhcp_type, payload_len);
    oam_warning_log4(vap->uc_vap_id, OAM_SF_RX, "{hmac_rx_vip_info_proc:: DHCP sip: %d.%d, dip: %d.%d.",
        sip[BYTE_OFFSET_2], sip[BYTE_OFFSET_3], dip[BYTE_OFFSET_2], dip[BYTE_OFFSET_3]);

    return l_ret;
}

static void hmac_rx_vip_info_proc_data_arp(mac_ether_header_stru *ether_hdr,
    mac_vap_stru *vap, uint32_t len, uint8_t data_type)
{
    oal_eth_arphdr_stru *arp_head = NULL;
    if (len < sizeof(mac_ether_header_stru) + sizeof(oal_eth_arphdr_stru)) {
        oam_error_log2(0, OAM_SF_RX, "hmac_rx_vip_info_proc::len[%d] data_type[%d]", len, data_type);
        return;
    }

    arp_head = (oal_eth_arphdr_stru *)(ether_hdr + 1);
    oam_warning_log1(vap->uc_vap_id, OAM_SF_RX, "{hmac_rx_vip_info_proc::ARP type=%d[2:arp rsp 3:arp req]", data_type);
    oam_warning_log4(vap->uc_vap_id, OAM_SF_RX, "{hmac_rx_vip_info_proc:: ARP sip: %d.%d, dip: %d.%d",
        arp_head->auc_ar_sip[BYTE_OFFSET_2], arp_head->auc_ar_sip[BYTE_OFFSET_3],
        arp_head->auc_ar_tip[BYTE_OFFSET_2], arp_head->auc_ar_tip[BYTE_OFFSET_3]);
}

static void hmac_rx_vip_data_notify_process(mac_vap_stru *mac_vap, uint8_t data_type)
{
    uint32_t ret;
    uint8_t rx_data_type = data_type;
    if (rx_data_type > MAC_DATA_ARP_RSP) {
        return;
    }

    ret = hmac_config_send_event(mac_vap, WLAN_CFGID_HOST_RX_VIP_DATA_EVENT, sizeof(uint8_t), &rx_data_type);
    if (oal_unlikely(ret != OAL_SUCC)) {
        oam_error_log2(mac_vap->uc_vap_id, OAM_SF_ANY, "{[RX]::failed[%d], data_type=%d .}", ret, data_type);
    }
}
static void hmac_rx_eapol_notify_process(mac_vap_stru *mac_vap, uint8_t is_rx_eapol_key_open)
{
    uint32_t ret;
    mac_vip_data_notify_stru st_mac_h2d_vip_info;
    st_mac_h2d_vip_info.is_rx_eapol_key_open = is_rx_eapol_key_open;

    ret = hmac_config_send_event(mac_vap, WLAN_CFGID_HOST_RX_EAPOL_DATA_EVENT,
        sizeof(mac_vip_data_notify_stru), (uint8_t *)&st_mac_h2d_vip_info);
    if (oal_unlikely(ret != OAL_SUCC)) {
        oam_error_log0(mac_vap->uc_vap_id, OAM_SF_ANY, "{hmac_rx_eapol_notify_process::failed}");
    }
}
/*
 * 函 数 名  : hmac_rx_vip_info_proc
 * 功能描述  : hmac 接收一个mpdu的关键帧识别维测
 * 1.日    期  : 2021年2月1日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
static void hmac_rx_vip_info_proc(mac_vap_stru *vap,
    uint8_t data_type, oal_netbuf_stru *netbuf, mac_rx_ctl_stru *rx_ctrl)
{
    mac_ether_header_stru *ether_hdr = NULL;
    uint32_t netbuf_len;
    uint8_t is_rx_eapol_key_open;
    uint8_t eapol_type;
    /* 收到skb为eth头 */
    ether_hdr = (mac_ether_header_stru *)oal_netbuf_data(netbuf);
    if (oal_unlikely(ether_hdr == NULL)) {
        return;
    }
    netbuf_len = oal_netbuf_len(netbuf);

    oam_warning_log3(vap->uc_vap_id, OAM_SF_RX, "{hmac_rx_vip_info_proc::send to wlan smac: %02X:XX:XX:XX:%02X:%02X]",
        ether_hdr->auc_ether_shost[MAC_ADDR_0],
        ether_hdr->auc_ether_shost[MAC_ADDR_4], ether_hdr->auc_ether_shost[MAC_ADDR_5]);
    oam_warning_log3(vap->uc_vap_id, OAM_SF_RX, "{hmac_rx_vip_info_proc::dmac:%02X:XX:XX:XX:%02X:%02X]",
        ether_hdr->auc_ether_dhost[MAC_ADDR_0],
        ether_hdr->auc_ether_dhost[MAC_ADDR_4], ether_hdr->auc_ether_dhost[MAC_ADDR_5]);

    if (data_type == MAC_DATA_EAPOL) {
        eapol_type = hmac_rx_vip_info_proc_data_eapol(ether_hdr, rx_ctrl, vap, netbuf_len);
        if ((is_sta(vap)) && (eapol_type != MAC_EAPOL_PTK_BUTT)) {
            is_rx_eapol_key_open = (rx_ctrl->bit_cipher_type == WLAN_80211_CIPHER_SUITE_NO_ENCRYP);
            oam_warning_log1(vap->uc_vap_id, OAM_SF_RX, "hmac_rx_vip_info_proc::is_rx_eapol_key_open=%d",
                is_rx_eapol_key_open);
            hmac_rx_eapol_notify_process(vap, is_rx_eapol_key_open);
        }
#ifdef _PRE_WLAN_FEATURE_PSM_ABN_PKTS_STAT
        hmac_rx_group_rekey_stat(vap, netbuf);
#endif
        /* H3C自愈 */
        if (!ether_is_broadcast(ether_hdr->auc_ether_dhost)) {
            hmac_ht_self_cure_event_set(vap, vap->auc_bssid, HAMC_HT_SELF_CURE_EVENT_RX_EAPOL);
        }
    } else if (data_type == MAC_DATA_DHCP) {
        if (hmac_rx_vip_info_proc_data_dhcp(ether_hdr, data_type, vap, netbuf_len) != EOK) {
            return;
        }

        /* H3C自愈 */
        hmac_ht_self_cure_event_set(vap, vap->auc_bssid, HMAC_HT_SELF_CURE_EVENT_RX_DHCP_FRAME);
    } else if (data_type == MAC_DATA_ARP_RSP || data_type == MAC_DATA_ARP_REQ) {
        hmac_rx_vip_info_proc_data_arp(ether_hdr, vap, netbuf_len, data_type);
    }
    hmac_rx_vip_data_notify_process(vap, data_type);
}

/*
 * 功能描述  : rx_context上下文中msdu转化成8023
 * 1.日    期  : 2021年1月4日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
static uint32_t hmac_rx_context_prepare_msdu_list_to_eth(hmac_host_rx_context_stru *rx_context)
{
    mac_rx_ctl_stru *rx_ctrl = NULL;
    oal_netbuf_stru *netbuf = rx_context->netbuf;
    oal_netbuf_stru *next_netbuf = NULL;
    oal_netbuf_head_stru netbuf_head;
    mac_ieee80211_frame_stru *frame_header = NULL;
    uint8_t data_type;

    frame_header = (mac_ieee80211_frame_stru *)oal_netbuf_data(netbuf);

    oal_netbuf_head_init(&netbuf_head);
    while (netbuf != NULL) {
        next_netbuf = netbuf->next;
        rx_ctrl = (mac_rx_ctl_stru *)oal_netbuf_cb(netbuf);
        if (rx_ctrl->bit_frame_format == MAC_FRAME_TYPE_80211) {
            /* 80211转换成8023 */
            if (hmac_rx_proc_80211_to_eth(netbuf, rx_ctrl, frame_header) != OAL_SUCC) {
                oal_netbuf_free(netbuf);
                netbuf = next_netbuf;
                continue;
            }
        }

        data_type = rx_ctrl->bit_data_type;
        if (data_type <= MAC_DATA_ARP_REQ) {
            hmac_rx_vip_info_proc(&(rx_context->hmac_vap->st_vap_base_info), data_type, netbuf, rx_ctrl);
        } else if (data_type == MAC_DATA_RTSP) {
            oam_warning_log0(0, OAM_SF_RX, "{hmac_rx_vip_info_proc::rtsp");
        }
        oal_netbuf_add_to_list_tail(netbuf, &netbuf_head);

        netbuf = next_netbuf;
    }

    if (oal_netbuf_list_empty(&netbuf_head)) {
        rx_context->netbuf = NULL;
        return OAL_FAIL;
    }

    /* 将最后一个NETBUF置空 */
    oal_set_netbuf_next((oal_netbuf_tail(&netbuf_head)), NULL);
    rx_context->netbuf = oal_netbuf_peek(&netbuf_head);

    return OAL_SUCC;
}

/*
 * 功能描述  : 通用业务处理流程
 * 1.日    期  : 2020.7.20
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_rx_proc_feature(hmac_host_rx_context_stru *rx_context,
    oal_netbuf_head_stru *rpt_list, oal_netbuf_head_stru *w2w_list)
{
    oal_netbuf_stru *netbuf = rx_context->netbuf;
    uint8_t buff_is_valid = OAL_TRUE;
    oal_netbuf_head_stru release_list;

    if (hmac_host_rx_feature_filter(rx_context) == HMAC_RX_FRAME_CTRL_DROP) {
        return OAL_FAIL;
    }

#ifdef _PRE_WLAN_FEATURE_WAPI
    if (hmac_wapi_netbuf_rx_decrypt_mp16(rx_context) != OAL_SUCC) {
        /* 解密失败，已经释放netbuf，此处返回成功，不需要释放netbuf */
        return OAL_SUCC;
    }
#endif /* _PRE_WLAN_FEATURE_WAPI */
    hal_host_rx_tcp_udp_checksum(rx_context->netbuf);
    netbuf = hmac_rx_defrag(rx_context);
    if (netbuf == NULL) {
        return OAL_SUCC;
    }
    /* defrag后更新参数 */
    rx_context->netbuf = netbuf;
    rx_context->cb = (mac_rx_ctl_stru *)oal_netbuf_cb(netbuf);

    /* 80211转换成8023 */
    if (hmac_rx_context_prepare_msdu_list_to_eth(rx_context) != OAL_SUCC) {
        return OAL_FAIL;
    }

    hmac_mintp_log((uint8_t *)rx_context->netbuf, MINTP_LOG_LVL_2, MINTP_LOG_DATATYPE_SKB_NEXT_LIST, MINTP_LOG_TYPE_RX);

    /* release list包括需要转发和上报的netbuf */
    oal_netbuf_head_init(&release_list);
    if (hmac_rx_proc_reorder(rx_context, &release_list, &buff_is_valid) != OAL_SUCC) {
        return OAL_FAIL;
    }

    /* 此函数执行后rx context中不包含netbuf,全部挂在release list中 */
    hmac_rx_context_netbuf_add_to_list(rx_context, &release_list, buff_is_valid);

    /* APUT转发链更新 */
    if (rx_context->hmac_vap->st_vap_base_info.en_vap_mode == WLAN_VAP_MODE_BSS_AP) {
        hmac_rx_ap_w2w_proc(rx_context, &release_list, w2w_list);
    }
    /* 剩下的报文全部上报协议栈 */
    oal_netbuf_queue_splice_tail_init(&release_list, rpt_list);
    return OAL_SUCC;
}

static void hmac_rx_enqueue_for_each(oal_netbuf_stru *netbuf)
{
    mac_rx_ctl_stru *cb = (mac_rx_ctl_stru *)oal_netbuf_cb(netbuf);
    hmac_vap_stru *hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(cb->uc_mac_vap_id);

    if (oal_unlikely(!hmac_vap)) {
        oam_error_log1(0, 0, "{hmac_rx_enqueue_for_each::hmac_vap NULL! vap id[%d]}", cb->uc_mac_vap_id);
        hmac_rx_enqueue_vap_abnormal_handle(netbuf, NULL);
        oal_netbuf_prev(netbuf) = NULL;
        oal_netbuf_next(netbuf) = NULL;
        oal_netbuf_free(netbuf);
        return;
    }

    hmac_rx_enqueue(netbuf, hmac_vap);
}

/*
 * 功能描述  : 报文上报协议栈
 * 1.日    期  : 2020.7.20
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void hmac_rx_rpt_netbuf(oal_netbuf_head_stru *list)
{
    oal_netbuf_stru *netbuf = NULL;
    uint8_t list_empty = oal_netbuf_list_empty(list);

    while (!oal_netbuf_list_empty(list)) {
        netbuf = oal_netbuf_delist_nolock(list);
        if (oal_likely(netbuf)) {
            hmac_rx_enqueue_for_each(netbuf);
        } else {
            oam_error_log0(0, 0, "{hmac_rx_rpt_netbuf::netbuf NULL?}");
        }
    }

    if (!list_empty && (hmac_get_rxthread_enable() == OAL_TRUE)) {
        g_hisi_softwdt_check.rxshed_rpt++;
        hmac_rxdata_sched();
    }
}

/*
 * 功能描述  : device/host rx通用处理流程
 * 1.日    期  : 2020.7.20
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void hmac_rx_common_proc(hmac_host_rx_context_stru *rx_context, oal_netbuf_head_stru *rpt_list)
{
    oal_netbuf_head_stru w2w_list;
    hmac_vap_stru *hmac_vap = rx_context->hmac_vap;

    oal_netbuf_list_head_init(&w2w_list);
    hmac_host_rx_static_proc(rx_context);
    if (hmac_rx_proc_feature(rx_context, rpt_list, &w2w_list) != OAL_SUCC) {
        hmac_rx_netbuf_list_free(rx_context->netbuf);
        return;
    }

    g_pm_wlan_pkt_statis.host_rx_pkt += oal_netbuf_list_len(rpt_list) + oal_netbuf_list_len(&w2w_list);
    hmac_rx_wlan_to_wlan_proc(hmac_vap, &w2w_list);
}

/*
 * 功能描述  : host rx ring数据处理接口
 * 1.日    期  : 2020年1月5日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_host_rx_ring_data_event(frw_event_mem_stru *event_mem)
{
    hal_host_device_stru        *hal_device = NULL;
    hal_host_rx_event           *wlan_rx_event = NULL;
    oal_netbuf_head_stru         list;
    oal_netbuf_stru             *netbuf = NULL;
    hmac_host_rx_context_stru    rx_context;
    oal_netbuf_head_stru rpt_list;

    host_cnt_init_record_performance(RX_RING_PROC);
    host_start_record_performance(RX_RING_PROC);

    if (oal_unlikely(event_mem == NULL)) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    wlan_rx_event = (hal_host_rx_event *)frw_get_event_stru(event_mem)->auc_event_data;
    hal_device    = wlan_rx_event->hal_dev;
    if (oal_unlikely(hal_device == NULL)) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    memset_s(&rx_context, sizeof(hmac_host_rx_context_stru), 0, sizeof(hmac_host_rx_context_stru));

    /* 处理乒乓链表 */
    oal_netbuf_list_head_init(&list);
    hal_host_rx_mpdu_que_pop(hal_device, &list);
    /* MPDU级别处理每个netbuf */
    netbuf = oal_netbuf_delist(&list);
    oal_netbuf_list_head_init(&rpt_list);
    for (; netbuf; netbuf = oal_netbuf_delist(&list)) {
        host_cnt_inc_record_performance(RX_RING_PROC);

        if (hmac_host_rx_proc_dev_routine(hal_device, netbuf, &rx_context) != OAL_SUCC) {
            continue;
        }
#ifdef _PRE_WLAN_FEATURE_VSP
        if (hmac_vsp_rx_proc(&rx_context, netbuf) == VSP_RX_ACCEPT) { /* vsp帧不采用上报协议栈方式，单独处理 */
            continue;
        }
#endif
        hmac_rx_route_print(hal_device, HOST_RX_REPORT, rx_context.cb);
        hmac_rx_common_proc(&rx_context, &rpt_list);
    }
    if (oal_netbuf_list_len(&rpt_list)) {
        hmac_rx_rpt_netbuf(&rpt_list);
    }

    host_end_record_performance(host_cnt_get_record_performance(RX_RING_PROC), RX_RING_PROC);
    return OAL_SUCC;
}
