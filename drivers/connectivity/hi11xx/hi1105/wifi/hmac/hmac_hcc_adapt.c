/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * 功能说明 : HMAC模块HCC层适配
 * 作    者 :
 * 创建日期 : 2014年10月8日
 */

#include "hmac_hcc_adapt.h"
#include "mac_resource.h"
#include "oal_hcc_host_if.h"
#include "frw_event_main.h"
#include "hmac_vap.h"
#include "wlan_chip_i.h"
#include "host_hal_device.h"
#include "host_hal_ext_if.h"
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
#include "plat_pm_wlan.h"
#endif
#include "hmac_wifi_delay.h"
#include "securec.h"
#include "securectype.h"
#include "oam_event_wifi.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_HCC_ADAPT_C

OAL_STATIC uint8_t g_hcc_sched_stat[FRW_EVENT_TYPE_BUTT];
OAL_STATIC uint8_t g_hcc_flowctrl_stat[FRW_EVENT_TYPE_BUTT];
OAL_STATIC uint32_t g_hcc_sched_event_pkts[FRW_EVENT_TYPE_BUTT] = { 0 };
OAL_STATIC uint8_t g_wlan_queue_to_dmac_queue[WLAN_NET_QUEUE_BUTT];

extern uint32_t hmac_hcc_tx_netbuf(frw_event_mem_stru *pst_hcc_event_mem,
                                   oal_netbuf_stru *pst_netbuf, uint32_t hdr_len,
                                   uint32_t fc_type,
                                   uint32_t queue_id);
uint32_t hmac_hcc_tx_netbuf_auto(frw_event_mem_stru *pst_hcc_event_mem,
                                 oal_netbuf_stru *pst_netbuf, uint32_t hdr_len);
extern uint32_t hmac_hcc_tx_data(frw_event_mem_stru *pst_hcc_event_mem, oal_netbuf_stru *pst_netbuf);

/* 3 函数实现 */
void hmac_tx_net_queue_map_init(void)
{
    memset_s(g_wlan_queue_to_dmac_queue, sizeof(g_wlan_queue_to_dmac_queue),
             DATA_LO_QUEUE, sizeof(g_wlan_queue_to_dmac_queue));
    g_wlan_queue_to_dmac_queue[WLAN_HI_QUEUE] = DATA_HI_QUEUE;
    g_wlan_queue_to_dmac_queue[WLAN_NORMAL_QUEUE] = DATA_LO_QUEUE;
    g_wlan_queue_to_dmac_queue[WLAN_TCP_DATA_QUEUE] = DATA_TCP_DATA_QUEUE;
    g_wlan_queue_to_dmac_queue[WLAN_TCP_ACK_QUEUE] = DATA_TCP_ACK_QUEUE;
    g_wlan_queue_to_dmac_queue[WLAN_UDP_BK_QUEUE] = DATA_UDP_BK_QUEUE;
    g_wlan_queue_to_dmac_queue[WLAN_UDP_BE_QUEUE] = DATA_UDP_BE_QUEUE;
    g_wlan_queue_to_dmac_queue[WLAN_UDP_VI_QUEUE] = DATA_UDP_VI_QUEUE;
    g_wlan_queue_to_dmac_queue[WLAN_UDP_VO_QUEUE] = DATA_UDP_VO_QUEUE;

    hcc_tx_wlan_queue_map_set(hcc_get_handler(HCC_EP_WIFI_DEV), DATA_HI_QUEUE, WLAN_HI_QUEUE);
    hcc_tx_wlan_queue_map_set(hcc_get_handler(HCC_EP_WIFI_DEV), DATA_LO_QUEUE, WLAN_NORMAL_QUEUE);
    hcc_tx_wlan_queue_map_set(hcc_get_handler(HCC_EP_WIFI_DEV), DATA_TCP_DATA_QUEUE, WLAN_TCP_DATA_QUEUE);
    hcc_tx_wlan_queue_map_set(hcc_get_handler(HCC_EP_WIFI_DEV), DATA_TCP_ACK_QUEUE, WLAN_TCP_ACK_QUEUE);
    hcc_tx_wlan_queue_map_set(hcc_get_handler(HCC_EP_WIFI_DEV), DATA_UDP_BK_QUEUE, WLAN_UDP_BK_QUEUE);
    hcc_tx_wlan_queue_map_set(hcc_get_handler(HCC_EP_WIFI_DEV), DATA_UDP_BE_QUEUE, WLAN_UDP_BE_QUEUE);
    hcc_tx_wlan_queue_map_set(hcc_get_handler(HCC_EP_WIFI_DEV), DATA_UDP_VI_QUEUE, WLAN_UDP_VI_QUEUE);
    hcc_tx_wlan_queue_map_set(hcc_get_handler(HCC_EP_WIFI_DEV), DATA_UDP_VO_QUEUE, WLAN_UDP_VO_QUEUE);
}

#ifdef _PRE_CONFIG_CONN_HISI_SYSFS_SUPPORT
int32_t hmac_tx_event_pkts_info_print(void *data, char *buf, int32_t buf_len)
{
    int i;
    int32_t ret = 0;
    uint64_t total = 0;
    struct hcc_handler *hcc = hcc_get_handler(HCC_EP_WIFI_DEV);
    if (hcc == NULL) {
        return ret;
    }
    ret += snprintf_s(buf + ret, buf_len - ret, (buf_len - ret) - 1, "tx_event_pkts_info_show\n");
    for (i = 0; i < FRW_EVENT_TYPE_BUTT; i++) {
        if (g_hcc_sched_event_pkts[i]) {
            ret += snprintf_s(buf + ret, buf_len - ret, buf_len - ret - 1,
                              "event:%d, pkts:%10u\n", i, g_hcc_sched_event_pkts[i]);
        }
        total += g_hcc_sched_event_pkts[i];
    }

    if (total) {
        ret += snprintf_s(buf + ret, buf_len - ret, (buf_len - ret) - 1, "total:%llu\n", total);
    }

    return ret;
}
#endif

#ifdef _PRE_CONFIG_HISI_PANIC_DUMP_SUPPORT
OAL_STATIC declare_wifi_panic_stru(hmac_panic_hcc_adapt, hmac_tx_event_pkts_info_print);
#endif

void hmac_tx_sched_info_init(void)
{
    memset_s(g_hcc_sched_stat, sizeof(g_hcc_sched_stat),
             DATA_LO_QUEUE, sizeof(g_hcc_sched_stat));

    /* set the event sched PRI */
    g_hcc_sched_stat[FRW_EVENT_TYPE_HIGH_PRIO] = DATA_HI_QUEUE;
    g_hcc_sched_stat[FRW_EVENT_TYPE_HOST_CRX] = DATA_HI_QUEUE;
    g_hcc_sched_stat[FRW_EVENT_TYPE_HOST_DRX] = DATA_LO_QUEUE;
    g_hcc_sched_stat[FRW_EVENT_TYPE_HOST_CTX] = DATA_HI_QUEUE;
    g_hcc_sched_stat[FRW_EVENT_TYPE_HOST_SDT_REG] = DATA_HI_QUEUE;
    g_hcc_sched_stat[FRW_EVENT_TYPE_WLAN_CRX] = DATA_HI_QUEUE;
    g_hcc_sched_stat[FRW_EVENT_TYPE_WLAN_DRX] = DATA_LO_QUEUE;
    g_hcc_sched_stat[FRW_EVENT_TYPE_WLAN_CTX] = DATA_HI_QUEUE;
    g_hcc_sched_stat[FRW_EVENT_TYPE_WLAN_TX_COMP] = DATA_HI_QUEUE;
    g_hcc_sched_stat[FRW_EVENT_TYPE_TBTT] = DATA_HI_QUEUE;
    g_hcc_sched_stat[FRW_EVENT_TYPE_TIMEOUT] = DATA_HI_QUEUE;
    g_hcc_sched_stat[FRW_EVENT_TYPE_DMAC_MISC] = DATA_HI_QUEUE;

    memset_s(g_hcc_flowctrl_stat, sizeof(g_hcc_flowctrl_stat),
             HCC_FC_NONE, sizeof(g_hcc_flowctrl_stat));
    /* 来自HOST的事件，如果从Kernel Net过来选择网络层流控+丢包的方式，
    如果是Wlan To Wlan 的方式，直接丢包! */
    g_hcc_flowctrl_stat[FRW_EVENT_TYPE_HOST_DRX] = HCC_FC_DROP | HCC_FC_NET;
}

OAL_STATIC OAL_INLINE void hmac_hcc_adapt_extend_hdr_init(frw_event_hdr_stru *pst_event_hdr,
                                                          oal_netbuf_stru *pst_netbuf)
{
    struct frw_hcc_extend_hdr *pst_hdr;

    pst_hdr = (struct frw_hcc_extend_hdr *)oal_netbuf_data(pst_netbuf);
    pst_hdr->en_nest_type = pst_event_hdr->en_type;
    pst_hdr->uc_nest_sub_type = pst_event_hdr->uc_sub_type;
    pst_hdr->device_id = pst_event_hdr->uc_device_id;
    pst_hdr->chip_id = pst_event_hdr->uc_chip_id;
    pst_hdr->vap_id = pst_event_hdr->uc_vap_id;
}

/*
 * 函 数 名  : check_headroom_add_length
 * 1.日    期  : 2015年1月12日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t check_headroom_add_length(mac_tx_ctl_stru *pst_tx_ctl,
                                   uint8_t en_nest_type,
                                   uint8_t uc_nest_sub_type, uint8_t uc_cb_length)
{
    uint32_t headroom_add;

    if (mac_get_cb_80211_mac_head_type(pst_tx_ctl) == 1) {
        /* case 1: data from net, mac head is maintence in netbuff */
        headroom_add = uc_cb_length + MAC_80211_QOS_HTC_4ADDR_FRAME_LEN;  // 结构体肯定大于4
    } else if ((en_nest_type == FRW_EVENT_TYPE_WLAN_CTX) && (uc_nest_sub_type == DMAC_WLAN_CTX_EVENT_SUB_TYPE_MGMT)) {
        /* case 2: mgmt frame, mac header is maintence in payload part */
        headroom_add = uc_cb_length + (MAX_MAC_HEAD_LEN - MAC_80211_FRAME_LEN);
    } else {
        /* case 3: data from net, mac head not maintence in netbuff */
        /* case 4: netbuff alloced in adapt layer */
        headroom_add = uc_cb_length + MAX_MAC_HEAD_LEN;
    }

    return headroom_add;
}


/* 帧头帧体连续hcc格式所需的headroom检查 */
uint32_t check_headroom_length(mac_tx_ctl_stru *tx_ctl,
    uint8_t en_nest_type, uint8_t nest_sub_type, uint8_t cb_len)
{
    uint32_t headroom_need;

    if (mac_get_cb_80211_mac_head_type(tx_ctl) == 1) {
        /* case 1: data from net, mac head is maintence in netbuff */
        headroom_need = cb_len + MAC_80211_QOS_HTC_4ADDR_FRAME_LEN + mac_get_cb_frame_header_length(tx_ctl);
    } else if ((en_nest_type == FRW_EVENT_TYPE_WLAN_CTX) && (nest_sub_type == DMAC_WLAN_CTX_EVENT_SUB_TYPE_MGMT)) {
        /* case 2: mgmt frame, mac header is maintence in payload part */
        headroom_need = cb_len + (MAX_MAC_HEAD_LEN);
    } else {
        /* case 3: data from net, mac head not maintence in netbuff */
        /* case 4: netbuff alloced in adapt layer */
        headroom_need = cb_len + MAX_MAC_HEAD_LEN + mac_get_cb_frame_header_length(tx_ctl);
    }

    return headroom_need;
}

/*
 * 函 数 名  : hmac_adjust_netbuf_data
 * 1.日    期  : 2015年1月12日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void hmac_adjust_netbuf_data(oal_netbuf_stru *pst_netbuf, mac_tx_ctl_stru *pst_tx_ctrl,
    uint8_t en_nest_type, uint8_t uc_nest_sub_type)
{
    uint8_t *puc_data_hdr;
    uint8_t uc_cb_length;
    int32_t l_ret = EOK;

    /* 在进入HCC之前，将CB字段和Mac头连续存放至payload之前 */
    puc_data_hdr = oal_netbuf_data(pst_netbuf);

    uc_cb_length = sizeof(mac_tx_ctl_stru) - sizeof(mac_tx_expand_cb_stru);

    if ((en_nest_type == FRW_EVENT_TYPE_WLAN_CTX) && (uc_nest_sub_type == DMAC_WLAN_CTX_EVENT_SUB_TYPE_MGMT)) {
        /* case 1: mgmt frame, mac header is maintence in payload part */
        l_ret += memcpy_s(puc_data_hdr, uc_cb_length, (uint8_t *)pst_tx_ctrl, uc_cb_length);
        /* copy mac hdr */
        l_ret += memmove_s(puc_data_hdr + uc_cb_length, MAC_80211_FRAME_LEN,
                           puc_data_hdr + uc_cb_length + (MAX_MAC_HEAD_LEN - MAC_80211_FRAME_LEN),
                           MAC_80211_FRAME_LEN);
    } else if (mac_get_cb_frame_header_addr(pst_tx_ctrl) != NULL) {
        /* case 2: data from net, mac head not maintence in netbuff */
        /* case 3: netbuff alloced in adapt layer */
        l_ret += memcpy_s(puc_data_hdr, uc_cb_length, (uint8_t *)pst_tx_ctrl, uc_cb_length);
        /* 帧头和帧体不连续，帧头重新申请了事件内存，此处需要释放 */
        if (mac_get_cb_80211_mac_head_type(pst_tx_ctrl) == 0) {
            l_ret += memmove_s(puc_data_hdr + uc_cb_length, mac_get_cb_frame_header_length(pst_tx_ctrl),
                               (uint8_t *)mac_get_cb_frame_header_addr(pst_tx_ctrl),
                               mac_get_cb_frame_header_length(pst_tx_ctrl));
            oal_mem_free_m((uint8_t *)mac_get_cb_frame_header_addr(pst_tx_ctrl), OAL_TRUE);
        }
    }
    if (l_ret != EOK) {
        oam_error_log0(0, OAM_SF_ANY, "hmac_adjust_netbuf_data::memcpy or memmove fail!");
        return;
    }
}

/* 格式化hcc头部数据格式，用于帧体帧头连续格式 */
void hmac_format_netbuf_header(oal_netbuf_stru *netbuf, mac_tx_ctl_stru *tx_ctrl,
    uint8_t nest_type, uint8_t nest_sub_type)
{
    uint8_t *data_hdr = NULL;
    uint8_t cb_len = sizeof(mac_tx_ctl_stru) - sizeof(mac_tx_expand_cb_stru);
    int32_t l_ret = EOK;

    /* 在进入HCC之前，将CB字段和Mac头连续存放至payload之前 */
    data_hdr = oal_netbuf_data(netbuf);

    if ((nest_type == FRW_EVENT_TYPE_WLAN_CTX) && (nest_sub_type == DMAC_WLAN_CTX_EVENT_SUB_TYPE_MGMT)) {
        /* case 1: mgmt frame, mac header is maintence in payload part */
        l_ret += memcpy_s(data_hdr, cb_len, (uint8_t *)tx_ctrl, cb_len);
    } else if (mac_get_cb_frame_header_addr(tx_ctrl) != NULL) {
        /* case 2: data from net, mac head not maintence in netbuff */
        /* case 3: netbuff alloced in adapt layer */
        l_ret += memcpy_s(data_hdr, cb_len, (uint8_t *)tx_ctrl, cb_len);
        l_ret += memmove_s(data_hdr + cb_len + MAX_MAC_HEAD_LEN, mac_get_cb_frame_header_length(tx_ctrl),
            (uint8_t *)mac_get_cb_frame_header_addr(tx_ctrl), mac_get_cb_frame_header_length(tx_ctrl));
        /* 帧头和帧体不连续，帧头重新申请了事件内存，此处需要释放 */
        if (mac_get_cb_80211_mac_head_type(tx_ctrl) == 0) {
            oal_mem_free_m((uint8_t *)mac_get_cb_frame_header_addr(tx_ctrl), OAL_TRUE);
        }
    }
    if (l_ret != EOK) {
        oam_error_log0(0, OAM_SF_ANY, "hmac_format_netbuf_header::memcpy or memmove fail!");
        return;
    }
}

/*
 * 函 数 名  : hmac_hcc_tx_netbuf_auto
 * 1.日    期  : 2016年6月18日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_hcc_tx_netbuf_auto(frw_event_mem_stru *pst_hcc_event_mem,
                                 oal_netbuf_stru *pst_netbuf, uint32_t hdr_len)
{
    uint32_t fc_type, queue_id;
    frw_event_hdr_stru *pst_event_hdr;
    uint8_t en_type;
    pst_event_hdr = frw_get_event_hdr(pst_hcc_event_mem);
    en_type = pst_event_hdr->en_type;

    if (oal_warn_on(en_type >= FRW_EVENT_TYPE_BUTT)) {
        oal_netbuf_free(pst_netbuf);
        oam_warning_log1(0, OAM_SF_ANY, "{hmac_hcc_tx_netbuf_auto::FRW_EVENT_TYPE[%d] over limit!}", en_type);
        return OAL_FAIL;
    }

    queue_id = g_hcc_sched_stat[en_type];
    fc_type = g_hcc_flowctrl_stat[en_type];

    /* 对于从以太网报文获取其队列号 */
    if (en_type == FRW_EVENT_TYPE_HOST_DRX) {
        queue_id = oal_skb_get_queue_mapping(pst_netbuf);
        if (oal_warn_on(queue_id >= WLAN_NET_QUEUE_BUTT)) {
            queue_id = DATA_LO_QUEUE;
        } else {
            queue_id = g_wlan_queue_to_dmac_queue[queue_id];
        }
    }

    return hmac_hcc_tx_netbuf(pst_hcc_event_mem, pst_netbuf, hdr_len, fc_type, queue_id);
}

uint32_t hmac_hcc_tx_update_netbuf_addr(oal_netbuf_stru *netbuf, uint32_t hdr_len)
{
    uint32_t netbuf_old_addr, netbuf_new_addr, addr_offset, head_room;
    int32_t ret;

    netbuf_old_addr = (uint32_t)(uintptr_t)(oal_netbuf_data(netbuf) + hdr_len);
    netbuf_new_addr = OAL_ROUND_DOWN(netbuf_old_addr, 4); // 4是4字节对齐
    addr_offset = netbuf_old_addr - netbuf_new_addr;

    /* 未对齐时在host侧做数据搬移，此处牺牲host，解放device */
    if (addr_offset) {
        head_room = (uint32_t)oal_netbuf_headroom(netbuf);
        if (addr_offset > head_room) {
            ret = oal_netbuf_expand_head(netbuf, addr_offset - head_room, 0, GFP_ATOMIC);
            if (oal_warn_on(ret != OAL_SUCC)) {
                oam_error_log0(0, OAM_SF_ANY, "{hmac_hcc_tx_data:: alloc head room failed.}");
                return OAL_ERR_CODE_ALLOC_MEM_FAIL;
            }
        }

        if (EOK != memmove_s((uint8_t *)oal_netbuf_data(netbuf) - addr_offset, oal_netbuf_len(netbuf),
            (uint8_t *)oal_netbuf_data(netbuf), oal_netbuf_len(netbuf))) {
            oam_error_log0(0, OAM_SF_ANY, "hmac_hcc_tx_data::memmove fail!");
        }
        oal_netbuf_push(netbuf, addr_offset);
        oal_netbuf_trim(netbuf, addr_offset);
    }
    return OAL_SUCC;
}

uint32_t hmac_hcc_tx_get_head_pad(oal_netbuf_stru *netbuf, uint32_t hcc_head_len)
{
    uint32_t hcc_head_pad;

    /* 一次性扩展HCC适配层9字节 */
    if (oal_netbuf_headroom(netbuf) > 0) {
        /* 保证cb 4bytes对齐 */
        oal_netbuf_push(netbuf, 1);

        hcc_head_pad = hcc_head_len;
    } else {
        hcc_head_pad = hcc_head_len + 1;
    }
    return hcc_head_pad;
}

#if (_PRE_TEST_MODE != _PRE_TEST_MODE_UT)
uint32_t hmac_hcc_tx_event_handle(frw_event_hdr_stru *event_hdr, oal_netbuf_stru *netbuf,
    struct hcc_transfer_param *hcc_transfer_param)
{
    uint32_t ret;

    ret = (uint32_t)hcc_tx(hcc_get_handler(HCC_EP_WIFI_DEV), netbuf, hcc_transfer_param);
    if (oal_unlikely(ret != OAL_SUCC)) {
        /* hcc 关闭时下发了命令,报警需要清理 */
        if (oal_unlikely(ret == -OAL_EBUSY)) {
            if (oal_print_rate_limit(30 * PRINT_RATE_SECOND)) { // 30代表30s
                oal_warn_on(1);
            }
            oal_io_print("[E]hmac_tx event[%u:%u] drop!\n", event_hdr->en_type, event_hdr->uc_sub_type);
            declare_dft_trace_key_info("hcc_is_busy", OAL_DFT_TRACE_OTHER);
        }
    } else if (oal_likely(event_hdr->en_type < FRW_EVENT_TYPE_BUTT)) {
        g_hcc_sched_event_pkts[event_hdr->en_type]++;
    }
    return ret;
}
#endif

/*
 * 函 数 名  : hmac_hcc_tx_netbuf
 * 功能描述  : 发送普通netbuf,将netbuf->data开始的长度为ul_hdr_len的空间放入TCM
 * 1.日    期  : 2015/4/10
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_hcc_tx_netbuf(frw_event_mem_stru *pst_hcc_event_mem,
                            oal_netbuf_stru *pst_netbuf, uint32_t hdr_len,
                            uint32_t fc_type,
                            uint32_t queue_id)
{
    frw_event_hdr_stru *pst_event_hdr = NULL;
    uint32_t ret = OAL_SUCC; // 不初始化ut用例fail
    uint32_t hcc_head_len = HCC_HDR_LEN + sizeof(struct frw_hcc_extend_hdr);
    uint32_t hcc_head_pad;
    uint32_t head_room;

    declare_hcc_tx_param_initializer(st_hcc_transfer_param, HCC_ACTION_TYPE_WIFI, 0,
        hdr_len + sizeof(struct frw_hcc_extend_hdr), fc_type, queue_id);

    if (oal_unlikely(pst_netbuf == NULL)) {
        oam_error_log0(0, OAM_SF_ANY, "{hmac_hcc_tx_data:: pst_netbuf is null}");
        return -OAL_EINVAL;
    }

    hcc_head_pad = hmac_hcc_tx_get_head_pad(pst_netbuf, hcc_head_len);

    head_room = oal_netbuf_headroom(pst_netbuf);
    if (hcc_head_pad > head_room) {
        ret = (uint32_t)oal_netbuf_expand_head(pst_netbuf, (int32_t)(hcc_head_pad - head_room), 0, GFP_ATOMIC);
        if (oal_warn_on(ret != OAL_SUCC)) {
            oam_error_log0(0, OAM_SF_ANY, "{hmac_hcc_tx_data:: alloc head room failed.}");
            oal_netbuf_free(pst_netbuf);
            return OAL_ERR_CODE_ALLOC_MEM_FAIL;
        }
    }
    if (hcc_head_pad == hcc_head_len) {
        /* 恢复至CB首地址 */
        oal_netbuf_pull(pst_netbuf, 1);
    }

    ret = hmac_hcc_tx_update_netbuf_addr(pst_netbuf, hdr_len);
    if (oal_unlikely(ret != OAL_SUCC)) {
        oal_netbuf_free(pst_netbuf);
        return ret;
    }

    /* add frw hcc extend area */
    oal_netbuf_push(pst_netbuf, sizeof(struct frw_hcc_extend_hdr));

    pst_event_hdr = frw_get_event_hdr(pst_hcc_event_mem);
    hmac_hcc_adapt_extend_hdr_init(pst_event_hdr, pst_netbuf);

    // expand 14B后性能下降40%,待确认!
#if (_PRE_TEST_MODE != _PRE_TEST_MODE_UT)
    ret = hmac_hcc_tx_event_handle(pst_event_hdr, pst_netbuf, &st_hcc_transfer_param);
    if (oal_unlikely(ret != OAL_SUCC)) {
        if (ret == -OAL_EBUSY || ret == -OAL_EIO) {
            ret = OAL_SUCC;
        }
        oal_netbuf_free(pst_netbuf);
    }
#else
    /* UT Failed! Should remove this macro when DMT! */
    oal_netbuf_free(pst_netbuf);
#endif
    return ret;
}

/*
 * 功能描述  : hcc流程上报帧体
 * 作    者  : wifi
 */
OAL_STATIC uint32_t hmac_ota_report_frame_hcc_tx_data(mac_tx_ctl_stru *tx_ctrl, oal_netbuf_stru *netbuf)
{
    if (oal_unlikely(oal_any_null_ptr2(tx_ctrl, netbuf))) {
        oam_error_log0(0, OAM_SF_ANY, "{hmac_ota_report_frame_hcc_tx_data::input params null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    return oam_report_80211_frame(BROADCAST_MACADDR,
                                  (uint8_t *)oal_netbuf_header(netbuf),
                                  mac_get_cb_frame_header_length(tx_ctrl),
                                  (uint8_t *)oal_netbuf_data(netbuf) + mac_get_cb_frame_header_length(tx_ctrl),
                                  (mac_get_cb_mpdu_len(tx_ctrl) + mac_get_cb_frame_header_length(tx_ctrl)),
                                  OAM_OTA_FRAME_DIRECTION_TYPE_TX);
}

/*
 * 功能描述  : hcc流程netbuf扩展headroom空间
 * 作    者  : wifi
 */
OAL_STATIC int32_t hmac_hcc_expand_hdr_inside_payload(mac_tx_ctl_stru *tx_ctrl, oal_netbuf_stru *netbuf,
    uint32_t headroom_add)
{
    int32_t ret;
    mac_ieee80211_qos_htc_frame_addr4_stru mac_hdr;

    ret = memcpy_s((uint8_t *)(&mac_hdr), mac_get_cb_frame_header_length(tx_ctrl),
        (uint8_t *)mac_get_cb_frame_header_addr(tx_ctrl), mac_get_cb_frame_header_length(tx_ctrl));
    if (ret != EOK) {
        return ret;
    }
    ret = oal_netbuf_expand_head(netbuf, (int32_t)headroom_add - (int32_t)oal_netbuf_headroom(netbuf),
                                 0, GFP_ATOMIC);
    if (oal_warn_on(ret != OAL_SUCC)) {
        return ret;
    }
    mac_get_cb_frame_header_addr(tx_ctrl) =
        (mac_ieee80211_frame_stru *)(oal_netbuf_header(netbuf) - MAC_80211_QOS_HTC_4ADDR_FRAME_LEN);

    return memcpy_s((uint8_t *)mac_get_cb_frame_header_addr(tx_ctrl), mac_get_cb_frame_header_length(tx_ctrl),
                    (uint8_t *)(&mac_hdr), mac_get_cb_frame_header_length(tx_ctrl));
}

/*
 * 功能描述  : hcc流程netbuf扩展headroom空间
 * 作    者  : wifi
 */
OAL_STATIC int32_t hmac_hcc_tx_data_expand_hdr(mac_tx_ctl_stru *tx_ctrl, oal_netbuf_stru *netbuf,
    uint32_t headroom_add)
{
    /* 若cb中挂载mac头的地址不指向skb_buff的headroom中，则调用oal_netbuf_expand_head之后不会释放对应地址的内容 */
    if (mac_get_cb_frame_header_addr(tx_ctrl) == NULL || mac_get_cb_80211_mac_head_type(tx_ctrl) == 0) {
        return oal_netbuf_expand_head(netbuf, (int32_t)headroom_add - (int32_t)oal_netbuf_headroom(netbuf),
                                     0, GFP_ATOMIC);
    } else {
        return hmac_hcc_expand_hdr_inside_payload(tx_ctrl, netbuf, headroom_add);
    }
}

/*
 * 功能描述  : 核间通信传输802.11帧，device tx网络层过来的数据包
 * 作    者  : wifi
 */
uint32_t hmac_hcc_tx_data(frw_event_mem_stru *pst_hcc_event_mem, oal_netbuf_stru *pst_netbuf)
{
    frw_event_hdr_stru *pst_event_hdr = frw_get_event_hdr(pst_hcc_event_mem);
    uint8_t en_type = pst_event_hdr->en_type;
    uint8_t uc_sub_type = pst_event_hdr->uc_sub_type;
    mac_tx_ctl_stru *pst_tx_ctrl = NULL;
    uint32_t headroom_add;
    uint8_t uc_cb_length;

    if (oal_unlikely(pst_netbuf == NULL)) {
        oam_error_log0(0, OAM_SF_ANY, "{hmac_hcc_tx_data:: pst_netbuf is null}");
        return OAL_FAIL;
    }

    pst_tx_ctrl = (mac_tx_ctl_stru *)oal_netbuf_cb(pst_netbuf);
    if (oal_warn_on(mac_get_cb_is_4address(pst_tx_ctrl))) {
        oam_error_log0(0, OAM_SF_ANY, "{hmac_hcc_tx_data:: use 4 address.}");
        return OAL_FAIL;
    }

    uc_cb_length = sizeof(mac_tx_ctl_stru) - sizeof(mac_tx_expand_cb_stru);

    headroom_add = wlan_chip_check_headroom_len(pst_tx_ctrl, en_type, uc_sub_type, uc_cb_length);
    if (headroom_add > oal_netbuf_headroom(pst_netbuf)) {
        oam_warning_log0(0, OAM_SF_ANY, "hmac_hcc_tx_data::need expand headroom.");
        if (hmac_hcc_tx_data_expand_hdr(pst_tx_ctrl, pst_netbuf, headroom_add) != OAL_SUCC) {
            hmac_ota_report_frame_hcc_tx_data(pst_tx_ctrl, pst_netbuf);
            oam_error_log0(0, OAM_SF_ANY, "{hmac_hcc_tx_data:: alloc head room failed.}");
            return OAL_ERR_CODE_ALLOC_MEM_FAIL;
        }
    }
    /* 修改netbuff的data指针和len */
    oal_netbuf_push(pst_netbuf, headroom_add);
    wlan_chip_adjust_netbuf_data(pst_netbuf, pst_tx_ctrl, en_type, uc_sub_type);

#ifdef _PRE_DELAY_DEBUG
    /* device tx数据通道 */
    if (g_wifi_delay_debug & HMAC_DELAY_TX) {
        hmac_wifi_delay_tx_hcc_device_tx(pst_netbuf, pst_event_hdr);
    }
#endif
    /* netbuf不管成功与否都由发送函数释放! */
    hmac_hcc_tx_netbuf_auto(pst_hcc_event_mem, pst_netbuf, uc_cb_length + MAX_MAC_HEAD_LEN);
    return OAL_SUCC;
}

/*
 * 功能描述  : 核间通信传输事件内存统一规范接口
 */
uint32_t hmac_hcc_tx_event_buf_to_netbuf(frw_event_mem_stru *pst_event_mem,
                                         uint8_t *pst_buf,
                                         uint32_t payload_size)
{
    oal_netbuf_stru *pst_netbuf;
    /* 申请netbuf存放事件payload */
    pst_netbuf = hcc_netbuf_alloc(payload_size);
    if (oal_warn_on(pst_netbuf == NULL)) {
        oal_io_print("hmac_hcc_tx_event_buf_to_netbuf alloc netbuf failed!\n");
        return OAL_ERR_CODE_ALLOC_MEM_FAIL;
    }

    /* 将结构体拷贝到netbuff数据区 */
    oal_netbuf_put(pst_netbuf, payload_size);
    if (EOK != memcpy_s((uint8_t *)(oal_netbuf_data(pst_netbuf)),
        payload_size, (uint8_t *)pst_buf, payload_size)) {
        oam_error_log0(0, OAM_SF_ANY, "hmac_hcc_tx_event_buf_to_netbuf::memcpy fail!");
        oal_netbuf_free(pst_netbuf);
        return OAL_FAIL;
    }

    return hmac_hcc_tx_netbuf_auto(pst_event_mem, pst_netbuf, 0);
}

/*
 * 功能描述  : 事件内存核间通信 func1：传递payload&len
 */
uint32_t hmac_hcc_tx_event_payload_to_netbuf(frw_event_mem_stru *pst_event_mem,
                                             uint32_t payload_size)
{
    uint8_t *pst_event_payload = NULL;

    if (oal_warn_on(pst_event_mem == NULL)) {
        oam_error_log0(0, OAM_SF_ANY, "hmac_hcc_tx_event_payload_to_netbuf:pst_event_mem null!");
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* 取业务事件信息 */
    pst_event_payload = frw_get_event_payload(pst_event_mem);
    return hmac_hcc_tx_event_buf_to_netbuf(pst_event_mem, pst_event_payload, payload_size);
}

/*
 * 函 数 名  : hmac_hcc_rx_event_comm_adapt
 * 功能描述  : Hmac rx 业务事件适配函数，主要用于wlan数据适配
 * 1.日    期  : 2015年4月13日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_hcc_rx_event_comm_adapt(frw_event_mem_stru *pst_hcc_event_mem)
{
    uint8_t bit_mac_header_len;
    frw_event_hdr_stru *pst_event_hdr;
    hcc_event_stru *pst_hcc_event_payload;

    mac_rx_ctl_stru *pst_rx_ctrl = NULL;
    uint8_t *puc_hcc_extend_hdr = NULL;
    int32_t l_ret;

    /* step1 提取嵌套的业务事件类型 */
    pst_event_hdr = frw_get_event_hdr(pst_hcc_event_mem);
    pst_hcc_event_payload = (hcc_event_stru *)frw_get_event_payload(pst_hcc_event_mem);
    /*
     * 完成从51Mac rx ctl 到02 Mac rx ctl的拷贝,
     * 传到此处,pad_payload已经是0
     */
    /* hcc protocol header
    |-------hcc total(64B)-----|-----------package mem--------------|
    |hcc hdr|pad hdr|hcc extend|pad_payload|--------payload---------| */
    if (oal_warn_on(pst_hcc_event_payload->pst_netbuf == NULL)) {
        oam_error_log0(0, OAM_SF_ANY, "hmac_hcc_rx_event_comm_adapt:did't found netbuf!");
        return OAL_FAIL;
    }

    puc_hcc_extend_hdr = oal_netbuf_data((oal_netbuf_stru *)pst_hcc_event_payload->pst_netbuf);
    bit_mac_header_len = ((mac_rx_ctl_stru *)puc_hcc_extend_hdr)->uc_mac_header_len;
    if (bit_mac_header_len) {
        if (bit_mac_header_len > MAX_MAC_HEAD_LEN) {
            oam_error_log3(pst_event_hdr->uc_vap_id, OAM_SF_ANY, "invaild mac header len:%d,main:%d,sub:%d",
                           bit_mac_header_len, pst_event_hdr->en_type, pst_event_hdr->uc_sub_type);
            oal_print_hex_dump(puc_hcc_extend_hdr,
                               (int32_t)oal_netbuf_len((oal_netbuf_stru *)pst_hcc_event_payload->pst_netbuf),
                               32, "invaild mac header len"); // 32代表长度
            return OAL_FAIL;
        }

        pst_rx_ctrl = (mac_rx_ctl_stru *)oal_netbuf_cb((oal_netbuf_stru *)pst_hcc_event_payload->pst_netbuf);
        l_ret = memcpy_s(pst_rx_ctrl, sizeof(mac_rx_ctl_stru), puc_hcc_extend_hdr, sizeof(mac_rx_ctl_stru));

        /* 需要修改pst_rx_ctrl中所有指针 */
        mac_get_rx_cb_mac_header_addr(pst_rx_ctrl) = (uint32_t *)(puc_hcc_extend_hdr + OAL_MAX_CB_LEN +
                                                                    MAX_MAC_HEAD_LEN - pst_rx_ctrl->uc_mac_header_len);

        /* 将mac header的内容向高地址偏移8个字节拷贝，使得mac header和payload的内容连续 */
        l_ret += memmove_s((uint8_t *)mac_get_rx_cb_mac_header_addr(pst_rx_ctrl), pst_rx_ctrl->uc_mac_header_len,
                           (uint8_t *)((uint8_t *)mac_get_rx_cb_mac_header_addr(pst_rx_ctrl) -
                            (MAX_MAC_HEAD_LEN - pst_rx_ctrl->uc_mac_header_len)), pst_rx_ctrl->uc_mac_header_len);
        if (l_ret != EOK) {
            oam_error_log0(0, OAM_SF_ANY, "hmac_hcc_rx_event_comm_adapt::memcpy or memmove fail!");
        }

        /* 将netbuff data指针移到payload位置 */
        oal_netbuf_pull(pst_hcc_event_payload->pst_netbuf,
                        OAL_MAX_CB_LEN + (MAX_MAC_HEAD_LEN - pst_rx_ctrl->uc_mac_header_len));
    } else {
        pst_rx_ctrl = (mac_rx_ctl_stru *)oal_netbuf_cb((oal_netbuf_stru *)pst_hcc_event_payload->pst_netbuf);
        if (memcpy_s(pst_rx_ctrl, sizeof(mac_rx_ctl_stru), puc_hcc_extend_hdr, sizeof(mac_rx_ctl_stru)) != EOK) {
            oam_error_log0(0, OAM_SF_ANY, "hmac_hcc_rx_event_comm_adapt::memcpy fail!");
        }
        oal_netbuf_pull(pst_hcc_event_payload->pst_netbuf, (OAL_MAX_CB_LEN + MAX_MAC_HEAD_LEN));
    }

    return OAL_SUCC;
}

/*
 * 函 数 名  : hmac_hcc_expand_rx_adpat_event
 * 功能描述  : hmac event 扩展函数，复制一个rx event事件,事件申请失败则释放原事件中的netbuf!
 * 1.日    期  : 2015年4月13日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
frw_event_mem_stru *hmac_hcc_expand_rx_adpat_event(frw_event_mem_stru *pst_hcc_event_mem, uint32_t event_size)
{
    frw_event_hdr_stru *pst_hcc_event_hdr;
    hcc_event_stru *pst_hcc_event_payload;
    oal_netbuf_stru *pst_hcc_netbuf;
    uint8_t en_type;
    uint8_t uc_sub_type;
    uint8_t uc_chip_id;
    uint8_t uc_device_id;
    uint8_t uc_vap_id;
    frw_event_mem_stru *pst_event_mem = NULL; /* 业务事件相关信息 */

    /* 提取HCC事件信息 */
    pst_hcc_event_hdr = frw_get_event_hdr(pst_hcc_event_mem);
    pst_hcc_event_payload = (hcc_event_stru *)frw_get_event_payload(pst_hcc_event_mem);
    pst_hcc_netbuf = pst_hcc_event_payload->pst_netbuf;
    en_type = pst_hcc_event_hdr->en_type;
    uc_sub_type = pst_hcc_event_hdr->uc_sub_type;
    uc_chip_id = pst_hcc_event_hdr->uc_chip_id;
    uc_device_id = pst_hcc_event_hdr->uc_device_id;
    uc_vap_id = pst_hcc_event_hdr->uc_vap_id;

    /* 强制转换为uint16前先做判断 */
    if (oal_unlikely(event_size > 0xffff)) {
        oam_warning_log1(0, OAM_SF_ANY,
                         "hmac_hcc_rx_netbuf_convert_to_event::invalid event len:%d", event_size);
        /* 释放hcc事件中申请的netbuf内存 */
        oal_netbuf_free(pst_hcc_netbuf);
        return NULL;
    }

    /* 申请业务事件 */
    pst_event_mem = frw_event_alloc_m((uint16_t)event_size);
    if (oal_warn_on(pst_event_mem == NULL)) {
        oam_warning_log1(0, OAM_SF_ANY,
                         "hmac_hcc_rx_netbuf_convert_to_event  alloc event failed,event len:%d", event_size);
        /* 释放hcc事件中申请的netbuf内存 */
        oal_netbuf_free(pst_hcc_netbuf);
        return NULL;
    }

    /* 填业务事件头 */
    frw_event_hdr_init(frw_get_event_hdr(pst_event_mem),
                       en_type,
                       uc_sub_type,
                       (uint16_t)event_size,
                       FRW_EVENT_PIPELINE_STAGE_1,
                       uc_chip_id,
                       uc_device_id,
                       uc_vap_id);

    return pst_event_mem;
}

/*
 * 函 数 名  : hmac_hcc_rx_netbuf_convert_to_event
 * 功能描述  : Dmac模块将netbuf中的事件内容还原到事件内存中
 * 1.日    期  : 2015年2月3日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
frw_event_mem_stru *hmac_hcc_rx_netbuf_convert_to_event(frw_event_mem_stru *pst_hcc_event_mem,
                                                        uint32_t revert_size)
{
    hcc_event_stru *pst_hcc_event_payload = NULL;
    oal_netbuf_stru *pst_hcc_netbuf = NULL;
    frw_event_mem_stru *pst_event_mem = NULL; /* 业务事件相关信息 */

    if (oal_warn_on(pst_hcc_event_mem == NULL)) {
        return NULL;
    }

    /* filter the extend buf */
    if (hmac_hcc_rx_event_comm_adapt(pst_hcc_event_mem) == OAL_FAIL) {
        return NULL;
    }

    pst_hcc_event_payload = (hcc_event_stru *)frw_get_event_payload(pst_hcc_event_mem);
    pst_hcc_netbuf = pst_hcc_event_payload->pst_netbuf;

    if (oal_warn_on(pst_hcc_netbuf == NULL)) {
        oam_error_log0(0, OAM_SF_ANY, "Fatal Error,payload did't contain any netbuf!");
        return NULL;
    }

    if (revert_size > oal_netbuf_len(pst_hcc_netbuf)) {
        revert_size = oal_netbuf_len(pst_hcc_netbuf);
    }

    pst_event_mem = hmac_hcc_expand_rx_adpat_event(pst_hcc_event_mem, revert_size);
    if (pst_event_mem == NULL) {
        return NULL;
    }

    if (revert_size) {
        if (EOK != memcpy_s((uint8_t *)frw_get_event_payload(pst_event_mem), revert_size,
            (uint8_t *)oal_netbuf_data(pst_hcc_netbuf), revert_size)) {
            oam_error_log0(0, OAM_SF_ANY, "hmac_hcc_rx_netbuf_convert_to_event::memcpy fail!");
            oal_netbuf_free(pst_hcc_netbuf);
            frw_event_free_m(pst_event_mem);
            return NULL;
        }
    }
    /* 释放hcc事件中申请的netbuf内存 */
    oal_netbuf_free(pst_hcc_netbuf);

    return pst_event_mem;
}

/*
 * 函 数 名  : hmac_hcc_rx_convert_netbuf_to_event_default
 * 功能描述  : Dmac模块将netbuf中的事件内容还原到事件内存中,
 * 1.日    期  : 2015年2月3日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
frw_event_mem_stru *hmac_hcc_rx_convert_netbuf_to_event_default(frw_event_mem_stru *pst_hcc_event_mem)
{
    hcc_event_stru *pst_hcc_event_payload = NULL;

    if (oal_warn_on(pst_hcc_event_mem == NULL)) {
        return NULL;
    }

    pst_hcc_event_payload = (hcc_event_stru *)frw_get_event_payload(pst_hcc_event_mem);
    return hmac_hcc_rx_netbuf_convert_to_event(pst_hcc_event_mem, pst_hcc_event_payload->buf_len);
}

/*
 * 函 数 名  : hmac_common_rx_adapt
 * 功能描述  : hmac处理不懈怠payload事件的公共接收适配接口
 * 1.日    期  : 2014年10月18日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
frw_event_mem_stru *hmac_hcc_test_rx_adapt(frw_event_mem_stru *pst_hcc_event_mem)
{
    hcc_event_stru *pst_hcc_event_payload;

    frw_event_mem_stru *pst_event_mem = NULL;
    hcc_event_stru *pst_hcc_rx_event = NULL;

    pst_hcc_event_payload = (hcc_event_stru *)frw_get_event_payload(pst_hcc_event_mem);

    /* filter the extend buf */
    if (hmac_hcc_rx_event_comm_adapt(pst_hcc_event_mem) == OAL_FAIL) {
        return NULL;
    }

    pst_event_mem = hmac_hcc_expand_rx_adpat_event(pst_hcc_event_mem, sizeof(hcc_event_stru));
    if (pst_event_mem == NULL) {
        return NULL;
    }

    /* 填业务事件信息 */
    pst_hcc_rx_event = (hcc_event_stru *)frw_get_event_payload(pst_event_mem);
    pst_hcc_rx_event->pst_netbuf = pst_hcc_event_payload->pst_netbuf;
    pst_hcc_rx_event->buf_len = (uint32_t)oal_netbuf_len((oal_netbuf_stru *)pst_hcc_event_payload->pst_netbuf);

    return pst_event_mem;
}

frw_event_mem_stru *hmac_rx_convert_netbuf_to_netbuf_default(frw_event_mem_stru *pst_hcc_event_mem)
{
    hcc_event_stru *pst_hcc_event_payload;

    frw_event_mem_stru *pst_event_mem = NULL;

    dmac_tx_event_stru *pst_ctx_event = NULL;

    pst_hcc_event_payload = (hcc_event_stru *)frw_get_event_payload(pst_hcc_event_mem);

    /* filter the extend buf */
    if (hmac_hcc_rx_event_comm_adapt(pst_hcc_event_mem) == OAL_FAIL) {
        return NULL;
    }

    pst_event_mem = hmac_hcc_expand_rx_adpat_event(pst_hcc_event_mem, sizeof(dmac_tx_event_stru));
    if (pst_event_mem == NULL) {
        return NULL;
    }

    pst_ctx_event = (dmac_tx_event_stru *)frw_get_event_payload(pst_event_mem);

    pst_ctx_event->pst_netbuf = pst_hcc_event_payload->pst_netbuf;
    pst_ctx_event->us_frame_len = (uint16_t)oal_netbuf_len((oal_netbuf_stru *)pst_hcc_event_payload->pst_netbuf);

    oam_info_log1(0, OAM_SF_ANY, "{hmac_rx_convert_netbuf_to_netbuf_default::frame len = %d.}",
                  pst_ctx_event->us_frame_len);

    return pst_event_mem;
}

frw_event_mem_stru *hmac_rx_convert_netbuf_to_netbuf_ring(frw_event_mem_stru *phcc_event_mem)
{
    hcc_event_stru *hcc_event_payload;

    frw_event_mem_stru *pevent_mem = NULL;

    dmac_tx_event_stru *pctx_event = NULL;

    hcc_event_payload = (hcc_event_stru *)frw_get_event_payload(phcc_event_mem);

    /* filter the extend buf */
    if (hmac_hcc_rx_event_wow_comm_adapt(phcc_event_mem) != OAL_SUCC) {
        return NULL;
    }

    pevent_mem = hmac_hcc_expand_rx_adpat_event(phcc_event_mem, sizeof(dmac_tx_event_stru));
    if (pevent_mem == NULL) {
        return NULL;
    }

    pctx_event = (dmac_tx_event_stru *)frw_get_event_payload(pevent_mem);

    pctx_event->pst_netbuf = hcc_event_payload->pst_netbuf;
    pctx_event->us_frame_len = (uint16_t)oal_netbuf_len((oal_netbuf_stru *)hcc_event_payload->pst_netbuf);

    oam_info_log1(0, OAM_SF_ANY, "{hmac_rx_convert_netbuf_to_netbuf_wow::frame len = %d.}",
                  pctx_event->us_frame_len);

    return pevent_mem;
}

/*
 * 函 数 名  : hmac_rx_process_data_rx_adapt
 * 功能描述  : rx_process_data_sta接收适配
 * 1.日    期  : 2014年10月7日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
frw_event_mem_stru *hmac_rx_process_data_rx_adapt(frw_event_mem_stru *pst_hcc_event_mem)
{
    hcc_event_stru *pst_hcc_event_payload = NULL;

    frw_event_mem_stru *pst_event_mem = NULL;
    dmac_wlan_drx_event_stru *pst_wlan_rx_event = NULL;

    pst_hcc_event_payload = (hcc_event_stru *)frw_get_event_payload(pst_hcc_event_mem);

    /* filter the extend buf */
    if (hmac_hcc_rx_event_comm_adapt(pst_hcc_event_mem) == OAL_FAIL) {
        return NULL;
    }

    pst_event_mem = hmac_hcc_expand_rx_adpat_event(pst_hcc_event_mem, sizeof(dmac_wlan_drx_event_stru));
    if (pst_event_mem == NULL) {
        return NULL;
    }

    /* 填业务事件信息 */
    pst_wlan_rx_event = (dmac_wlan_drx_event_stru *)frw_get_event_payload(pst_event_mem);
    pst_wlan_rx_event->pst_netbuf = pst_hcc_event_payload->pst_netbuf;
    pst_wlan_rx_event->us_netbuf_num = 1;  // 目前不支持通过SDIO后组链，默认都是单帧

    return pst_event_mem;
}

frw_event_mem_stru *hmac_hcc_expand_rx_adpat_crx_event(frw_event_mem_stru *pst_hcc_event_mem)
{
    hcc_event_stru *pst_hcc_event_payload = NULL;
    frw_event_mem_stru *pst_event_mem = NULL;
    dmac_wlan_crx_event_stru *pst_crx_event = NULL;

    pst_event_mem = hmac_hcc_expand_rx_adpat_event(pst_hcc_event_mem, sizeof(dmac_wlan_crx_event_stru));
    if (pst_event_mem == NULL) {
        return NULL;
    }

    /* 取HCC事件信息 */
    pst_hcc_event_payload = (hcc_event_stru *)frw_get_event_payload(pst_hcc_event_mem);

    /* 填业务事件信息 */
    pst_crx_event = (dmac_wlan_crx_event_stru *)frw_get_event_payload(pst_event_mem);
    pst_crx_event->pst_netbuf = pst_hcc_event_payload->pst_netbuf;

    return pst_event_mem;
}

frw_event_mem_stru *hmac_rx_process_mgmt_event_rx_adapt(frw_event_mem_stru *pst_hcc_event_mem)
{
    frw_event_mem_stru *pst_event_mem = NULL;

    /* filter the extend buf */
    if (hmac_hcc_rx_event_comm_adapt(pst_hcc_event_mem) == OAL_FAIL) {
        return NULL;
    }

    pst_event_mem = hmac_hcc_expand_rx_adpat_crx_event(pst_hcc_event_mem);
    if (pst_event_mem == NULL) {
        return NULL;
    }

    return pst_event_mem;
}

/*
 * 函 数 名  : hmac_hcc_rx_event_wow_comm_adapt
 * 功能描述  : Hmac rx 业务事件适配函数，主要用于wlan数据适配
 * 1.日    期  : 2019年12月30日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_hcc_rx_event_wow_comm_adapt(frw_event_mem_stru *pst_hcc_event_mem)
{
    frw_event_hdr_stru *pst_event_hdr = frw_get_event_hdr(pst_hcc_event_mem);
    hcc_event_stru *pst_hcc_event_payload = (hcc_event_stru *)frw_get_event_payload(pst_hcc_event_mem);
    mac_rx_ctl_stru *pst_rx_ctrl = NULL;
    uint8_t *cb = NULL;
    uint8_t bit_mac_header_len;
    oal_netbuf_stru *netbuf = (oal_netbuf_stru *)pst_hcc_event_payload->pst_netbuf;
    int32_t l_ret;

    /* hcc protocol header
    |-------hcc total(64B)-----|-----------package mem--------------|
    |hcc hdr|pad hdr|hcc extend|pad_payload|--------payload---------| */
    if (oal_warn_on(netbuf == NULL)) {
        oam_error_log0(0, OAM_SF_ANY, "hmac_hcc_rx_event_comm_adapt:did't found netbuf!");
        return OAL_FAIL;
    }

    cb = oal_netbuf_data(netbuf);
    bit_mac_header_len = ((mac_rx_ctl_stru *)cb)->uc_mac_header_len;
    if (bit_mac_header_len) {
        if (bit_mac_header_len > MAX_MAC_HEAD_LEN) {
            oam_error_log3(pst_event_hdr->uc_vap_id, OAM_SF_ANY, "invaild mac header len:%d,main:%d,sub:%d",
                bit_mac_header_len, pst_event_hdr->en_type, pst_event_hdr->uc_sub_type);
            oal_print_hex_dump(cb, (int32_t)oal_netbuf_len(netbuf), 32, "invaild mac header len"); // 32代表长度
            return OAL_FAIL;
        }

        pst_rx_ctrl = (mac_rx_ctl_stru *)oal_netbuf_cb(netbuf);
        l_ret = memcpy_s(pst_rx_ctrl, sizeof(mac_rx_ctl_stru), cb, sizeof(mac_rx_ctl_stru));
        if (l_ret != EOK) {
            oam_error_log0(0, OAM_SF_ANY, "hmac_hcc_rx_event_comm_adapt::memcpy fail!");
        }

        /* 需要修改pst_rx_ctrl中所有指针 */
        mac_get_rx_cb_mac_header_addr(pst_rx_ctrl) = (uint32_t *)(cb + OAL_MAX_CB_LEN + MAX_MAC_HEAD_LEN);
    }

    /* 将netbuff data指针移到mac hdr位置 */
    oal_netbuf_pull(netbuf, (OAL_MAX_CB_LEN + MAX_MAC_HEAD_LEN));
    return OAL_SUCC;
}

frw_event_mem_stru *hmac_rx_process_wow_mgmt_event_rx_adapt(frw_event_mem_stru *pst_hcc_event_mem)
{
    frw_event_mem_stru *pst_event_mem = NULL;

    /* filter the extend buf */
    if (hmac_hcc_rx_event_wow_comm_adapt(pst_hcc_event_mem) == OAL_FAIL) {
        return NULL;
    }

    pst_event_mem = hmac_hcc_expand_rx_adpat_crx_event(pst_hcc_event_mem);
    if (pst_event_mem == NULL) {
        return NULL;
    }

    return pst_event_mem;
}

/*
 * 函 数 名  : hmac_rx_process_wow_data_rx_adapt
 * 功能描述  : mac hdr和帧体连续，hcc传输层适配
 * 1.日    期  : 2014年10月7日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
frw_event_mem_stru *hmac_rx_process_wow_data_rx_adapt(frw_event_mem_stru *pst_hcc_event_mem)
{
    hcc_event_stru *pst_hcc_event_payload = (hcc_event_stru *)frw_get_event_payload(pst_hcc_event_mem);
    frw_event_mem_stru *pst_event_mem = NULL;
    dmac_wlan_drx_event_stru *pst_wlan_rx_event = NULL;

    /* filter the extend buf */
    if (hmac_hcc_rx_event_wow_comm_adapt(pst_hcc_event_mem) == OAL_FAIL) {
        return NULL;
    }

    pst_event_mem = hmac_hcc_expand_rx_adpat_event(pst_hcc_event_mem, sizeof(dmac_wlan_drx_event_stru));
    if (pst_event_mem == NULL) {
        return NULL;
    }

    /* 填业务事件信息 */
    pst_wlan_rx_event = (dmac_wlan_drx_event_stru *)frw_get_event_payload(pst_event_mem);
    pst_wlan_rx_event->pst_netbuf = pst_hcc_event_payload->pst_netbuf;
    pst_wlan_rx_event->us_netbuf_num = 1;  // 目前不支持通过SDIO后组链，默认都是单帧

#ifdef _PRE_DELAY_DEBUG
    if (g_wifi_delay_debug & HMAC_DELAY_RX) {
        /* device rx数据通道 */
        hmac_wifi_delay_rx_hcc_device_rx(pst_wlan_rx_event->pst_netbuf, frw_get_event_hdr(pst_hcc_event_mem));
    }
#endif
    return pst_event_mem;
}

/*
 * 函 数 名  : hmac_rx_process_data_sta_rx_adapt
 * 功能描述  : rx_process_data_sta接收适配
 * 1.日    期  : 2014年10月7日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
frw_event_mem_stru *hmac_cali2hmac_event_rx_adapt(frw_event_mem_stru *pst_hcc_event_mem)
{
    hcc_event_stru *pst_hcc_event_payload = NULL;
    frw_event_mem_stru *pst_event_mem = NULL;
    hal_cali_hal2hmac_event_stru *pst_cali_save_event = NULL;

    pst_hcc_event_payload = (hcc_event_stru *)frw_get_event_payload(pst_hcc_event_mem);

    if (hmac_hcc_rx_event_comm_adapt(pst_hcc_event_mem) == OAL_FAIL) {
        return NULL;
    }

    pst_event_mem = hmac_hcc_expand_rx_adpat_event(pst_hcc_event_mem, sizeof(hal_cali_hal2hmac_event_stru));
    if (pst_event_mem == NULL) {
        oal_io_print("cali_hmac_rx_adapt_fail\r\n");
        return NULL;
    }

    /* 填业务事件信息 */
    pst_cali_save_event = (hal_cali_hal2hmac_event_stru *)frw_get_event_payload(pst_event_mem);
    pst_cali_save_event->pst_netbuf = pst_hcc_event_payload->pst_netbuf;
    pst_cali_save_event->us_netbuf_num = 1;  // 目前不支持通过SDIO后组链，默认都是单帧

    return pst_event_mem;
}

#ifdef _PRE_WLAN_FEATURE_APF
/*
 * 函 数 名  : hmac_apf_program_report_rx_adapt
 * 功能描述  : hmac_apf_program_report_event接收适配
 * 1.日    期  : 2018年3月17日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
frw_event_mem_stru *hmac_apf_program_report_rx_adapt(frw_event_mem_stru *pst_hcc_event_mem)
{
    hcc_event_stru *pst_hcc_event_payload;
    frw_event_mem_stru *pst_event_mem = NULL;
    dmac_apf_report_event_stru *pst_report_event = NULL;

    pst_hcc_event_payload = (hcc_event_stru *)frw_get_event_payload(pst_hcc_event_mem);

    /* filter the extend buf */
    if (hmac_hcc_rx_event_comm_adapt(pst_hcc_event_mem) == OAL_FAIL) {
        return NULL;
    }

    pst_event_mem = hmac_hcc_expand_rx_adpat_event(pst_hcc_event_mem, sizeof(dmac_apf_report_event_stru));
    if (pst_event_mem == NULL) {
        return NULL;
    }

    /* 填业务事件信息 */
    pst_report_event = (dmac_apf_report_event_stru *)frw_get_event_payload(pst_event_mem);
    pst_report_event->p_program = pst_hcc_event_payload->pst_netbuf;

    return pst_event_mem;
}
#endif
/*
 * 函 数 名  : hmac_proc_add_user_tx_adapt
 * 功能描述  : add_user模块发送适配
 * 1.日    期  : 2014年10月7日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_proc_add_user_tx_adapt(frw_event_mem_stru *pst_event_mem)
{
    return hmac_hcc_tx_event_payload_to_netbuf(pst_event_mem, sizeof(dmac_ctx_add_user_stru));
}

/*
 * 函 数 名  : hmac_proc_del_user_tx_adapt
 * 功能描述  : del_user模块发送适配
 * 1.日    期  : 2014年10月7日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_proc_del_user_tx_adapt(frw_event_mem_stru *pst_event_mem)
{
    return hmac_hcc_tx_event_payload_to_netbuf(pst_event_mem, sizeof(dmac_ctx_del_user_stru));
}

/*
 * 函 数 名  : hmac_proc_config_syn_tx_adapt
 * 功能描述  : config_syn模块发送适配
 * 1.日    期  : 2015/4/9
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_proc_config_syn_tx_adapt(frw_event_mem_stru *pst_event_mem)
{
    hmac_to_dmac_cfg_msg_stru *pst_syn_cfg_payload;
    pst_syn_cfg_payload = (hmac_to_dmac_cfg_msg_stru *)frw_get_event_payload(pst_event_mem);

    return hmac_hcc_tx_event_payload_to_netbuf(pst_event_mem,
        (pst_syn_cfg_payload->us_len + (uint32_t)OAL_OFFSET_OF(hmac_to_dmac_cfg_msg_stru, auc_msg_body)));
}

/*
 * 函 数 名  : hmac_proc_config_syn_alg_tx_adapt
 * 功能描述  : config_alg_syn模块发送适配
 * 1.日    期  : 2015年1月26日
 *   修改内容  : 新生成函数
 */
uint32_t hmac_proc_config_syn_alg_tx_adapt(frw_event_mem_stru *pst_event_mem)
{
    hmac_to_dmac_cfg_msg_stru *pst_syn_cfg_payload;
    pst_syn_cfg_payload = (hmac_to_dmac_cfg_msg_stru *)frw_get_event_payload(pst_event_mem);

    return hmac_hcc_tx_event_payload_to_netbuf(pst_event_mem,
        (pst_syn_cfg_payload->us_len + (uint32_t)OAL_OFFSET_OF(hmac_to_dmac_cfg_msg_stru, auc_msg_body)));
}

/*
 * 函 数 名  : hmac_sdt_recv_reg_cmd_tx_adapt
 * 功能描述  : SDT read reg适配
 * 1.日    期  : 2016年6月24日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_sdt_recv_reg_cmd_tx_adapt(frw_event_mem_stru *pst_event_mem)
{
    return hmac_hcc_tx_event_payload_to_netbuf(pst_event_mem,
        (uint32_t)((frw_get_event_stru(pst_event_mem))->st_event_hdr.us_length));
}

#if defined(_PRE_WLAN_FEATURE_DATA_SAMPLE) || defined(_PRE_WLAN_FEATURE_PSD_ANALYSIS)
/*
 * 函 数 名  : hmac_sdt_recv_sample_cmd_tx_adapt
 * 功能描述  : sample模块发送适配
 * 1.日    期  : 2016年7月28日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_sdt_recv_sample_cmd_tx_adapt(frw_event_mem_stru *pst_event_mem)
{
    return hmac_hcc_tx_event_payload_to_netbuf(pst_event_mem,
        (uint32_t)((frw_get_event_stru(pst_event_mem))->st_event_hdr.us_length) - sizeof(frw_event_hdr_stru));
}
#endif

#ifdef _PRE_WLAN_FEATURE_HIEX
/*
 * 函 数 名  : hmac_hiex_h2d_msg_tx_adapt
 * 功能描述  : hiex h2d消息发送适配
 * 1.日    期  : 2019年12月2日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_hiex_h2d_msg_tx_adapt(frw_event_mem_stru *pst_event_mem)
{
    return hmac_hcc_tx_event_payload_to_netbuf(pst_event_mem,
        (uint32_t)((frw_get_event_stru(pst_event_mem))->st_event_hdr.us_length) - sizeof(frw_event_hdr_stru));
}
#endif

/*
 * 函 数 名  : hmac_proc_tx_host_tx_adapt
 * 功能描述  : tx_host_event发送适配
 * 1.日    期  : 2014年10月7日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_proc_tx_host_tx_adapt(frw_event_mem_stru *event)
{
    oal_netbuf_stru    *cur_netbuf = NULL;
    oal_netbuf_stru    *tmp_netbuf = NULL;
    dmac_tx_event_stru *event_payload = NULL;
    uint32_t            ret;

    event_payload = (dmac_tx_event_stru *)frw_get_event_payload(event);
    cur_netbuf = event_payload->pst_netbuf;

    while (cur_netbuf != NULL) {
        /* 必须在netbuf抛出之前指向下一个netbuf，防止dispatch_event 中重置 netbuf->next */
        tmp_netbuf = cur_netbuf;
        cur_netbuf = oal_netbuf_next(cur_netbuf);

        /* netbuf 失败由被调函数释放! */
        ret = hmac_hcc_tx_data(event, tmp_netbuf);
        if (ret != OAL_SUCC) {
            return ret;
        }
    }
    return OAL_SUCC;
}
/*
 * 功能描述  : 核间通信传输: ring tx统一规范接口
 * 作    者  :
 */
#define BAD_HEADROOM_TH 50
uint32_t g_bad_headroom_stat = 0;
uint32_t hmac_hcc_tx_device_ring_tx_adapt(frw_event_mem_stru *frw_event)
{
    uint32_t headroom = OAL_MAX_CB_LEN + HCC_RESERVED_LEN;
    uint32_t ret;
    dmac_tx_event_stru *dmac_tx_event = (dmac_tx_event_stru *)frw_get_event_payload(frw_event);
    oal_netbuf_stru *netbuf = dmac_tx_event->pst_netbuf;
    /*
     * ----------------------------------------------------------------------------------
     *    | hcc hdr = 9  |   cb len = 19   |  reserve len = 36  |  8023 hdr + payload
     * ----------------------------------------------------------------------------------
     *                   ↑                                     ↑
     *           netbuf->data target                  netbuf->data current
     *
     * 此时netbuf->data位于8023 hdr处, 需要调用oal_netbuf_push将netbuf->data偏移至cb处, 并拷贝cb
     * 【注】当前默认device ring tx流程h2d传输的都是8023帧
     */
    if (oal_netbuf_headroom(netbuf) < HCC_HDR_TOTAL_LEN) {
        g_bad_headroom_stat++;
        if (g_bad_headroom_stat >= BAD_HEADROOM_TH) {
            g_bad_headroom_stat = 0;
            oam_warning_log2(0, OAM_SF_ANY, "{device_ring_tx_adapt:: headroom %d skb len %d.}",
                oal_netbuf_headroom(netbuf), oal_netbuf_len(netbuf));
        }
        ret = oal_netbuf_expand_head(netbuf, (int32_t)(HCC_HDR_TOTAL_LEN - oal_netbuf_headroom(netbuf)), 0, GFP_ATOMIC);
        if (oal_warn_on(ret != OAL_SUCC)) {
            oam_error_log0(0, OAM_SF_ANY, "{device_ring_tx_adapt:: alloc head room failed.}");
            return OAL_FAIL;
        }
    }
    oal_netbuf_push(netbuf, headroom);
    if (EOK != memcpy_s(oal_netbuf_data(netbuf), OAL_MAX_CB_LEN, oal_netbuf_cb(netbuf), OAL_MAX_CB_LEN)) {
        oam_error_log0(0, OAM_SF_ANY, "{device_ring_tx_adapt, memcpy_s failed.}");
        oal_netbuf_free(netbuf);
        return OAL_FAIL;
    }
#ifdef _PRE_DELAY_DEBUG
    /* DEVICE ring通道 */
    if (g_wifi_delay_debug & HMAC_DELAY_TX) {
        hmac_wifi_delay_tx_hcc_device_tx(netbuf, frw_get_event_hdr(frw_event));
    }
#endif
    return hmac_hcc_tx_netbuf_auto(frw_event, netbuf, OAL_MAX_CB_LEN + HCC_RESERVED_LEN);
}

/*
 * 函 数 名  : hmac_proc_set_edca_param_tx_adapt
 * 功能描述  : set_edca_param发送适配
 * 1.日    期  : 2014年10月7日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_proc_set_edca_param_tx_adapt(frw_event_mem_stru *pst_event_mem)
{
    return hmac_hcc_tx_event_payload_to_netbuf(pst_event_mem, sizeof(dmac_ctx_sta_asoc_set_edca_reg_stru));
}

#ifdef _PRE_WLAN_FEATURE_11AX
/*
 * 函 数 名  : hmac_proc_set_mu_edca_param_tx_adapt
 * 功能描述  : set_edca_param发送适配
 * 1.日    期  : 2014年10月7日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_proc_set_mu_edca_param_tx_adapt(frw_event_mem_stru *pst_event_mem)
{
    return hmac_hcc_tx_event_payload_to_netbuf(pst_event_mem, sizeof(dmac_ctx_sta_asoc_set_edca_reg_stru));
}

/*
 * 函 数 名  : hmac_proc_set_spatial_reuse_param_tx_adapt
 * 功能描述  : sr发送适配
 * 1.日    期  : 2014年10月7日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_proc_set_spatial_reuse_param_tx_adapt(frw_event_mem_stru *pst_event_mem)
{
    return hmac_hcc_tx_event_payload_to_netbuf(pst_event_mem, sizeof(dmac_ctx_sta_asoc_set_sr_reg_stru));
}
#endif

/*
 * 功能描述  : 事件内存核间通信 func3：传递netbuf&len
 */
uint32_t hmac_send_event_netbuf_tx_adapt(frw_event_mem_stru *pst_event_mem)
{
    dmac_tx_event_stru *pst_dmac_tx_event = NULL;

    if (pst_event_mem == NULL) {
        oam_error_log0(0, OAM_SF_CALIBRATE, "{hmac_send_event_netbuf_tx_adapt::pst_event_mem null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    pst_dmac_tx_event = (dmac_tx_event_stru *)frw_get_event_payload(pst_event_mem);
    return hmac_hcc_tx_event_buf_to_netbuf(pst_event_mem,
        (uint8_t *)oal_netbuf_data(pst_dmac_tx_event->pst_netbuf), pst_dmac_tx_event->us_frame_len);
}

/*
 * 功能描述  : 事件内存核间通信 func2：传递addr&len
 */
uint32_t hmac_send_event_memaddr_tx_adapt(frw_event_mem_stru *pst_event_mem)
{
    dmac_tx_memaddr_stru *event_mem = NULL;

    if (oal_unlikely(pst_event_mem == NULL)) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    event_mem = (dmac_tx_memaddr_stru *)frw_get_event_payload(pst_event_mem);

    return hmac_hcc_tx_event_buf_to_netbuf(pst_event_mem, (uint8_t *)event_mem->memaddr, event_mem->us_mem_len);
}

/*
 * 函 数 名  : hmac_join_set_reg_event_tx_adapt
 * 功能描述  : 通过SDIO下发join配置前得适配函数
 * 1.日    期  : 2014年10月13日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_proc_join_set_reg_event_tx_adapt(frw_event_mem_stru *pst_event_mem)
{
    oam_info_log0(0, OAM_SF_ANY, "{hmac_proc_join_set_reg_event_tx_adapt::tx adapt.}");
    return hmac_hcc_tx_event_payload_to_netbuf(pst_event_mem, sizeof(dmac_ctx_join_req_set_reg_stru));
}

/*
 * 函 数 名  : hmac_join_set_dtim_reg_event_tx_adapt
 * 功能描述  : 通过SDIO下发配置dtim寄存器前的发送适配函数
 * 1.日    期  : 2014年10月20日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_proc_join_set_dtim_reg_event_tx_adapt(frw_event_mem_stru *pst_event_mem)
{
    oam_info_log0(0, OAM_SF_ANY, "{hmac_proc_join_set_dtim_reg_event_tx_adapt::tx adapt.}");
    return hmac_hcc_tx_event_payload_to_netbuf(pst_event_mem, sizeof(dmac_ctx_set_dtim_tsf_reg_stru));
}

/*
 * 函 数 名  : hmac_hcc_tx_convert_event_to_netbuf_uint32
 * 功能描述  : hmac 将event 转换为 netbuf,在dmac 将netbuf还原为event,event的payload长度为4B
 * 1.日    期  : 2014年10月20日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_hcc_tx_convert_event_to_netbuf_uint32(frw_event_mem_stru *pst_event_mem)
{
    return hmac_hcc_tx_event_payload_to_netbuf(pst_event_mem, sizeof(uint32_t));
}

/*
 * 函 数 名  : hmac_hcc_tx_convert_event_to_netbuf_uint16
 * 功能描述  : hmac 将event 转换为 netbuf,在dmac 将netbuf还原为event,event的payload长度为2B
 * 1.日    期  : 2016年1月23日
 *   作    者  : wifi
 *   修改内容  : 核间通信函数精简
 */
uint32_t hmac_hcc_tx_convert_event_to_netbuf_uint16(frw_event_mem_stru *pst_event_mem)
{
    return hmac_hcc_tx_event_payload_to_netbuf(pst_event_mem, sizeof(uint16_t));
}

/*
 * 函 数 名  : hmac_hcc_tx_convert_event_to_netbuf_uint8
 * 功能描述  : hmac 将event 转换为 netbuf,在dmac 将netbuf还原为event,event的payload长度为1B
 * 1.日    期  : 2016年1月23日
 *   作    者  : wifi
 *   修改内容  : 核间通信函数精简
 */
uint32_t hmac_hcc_tx_convert_event_to_netbuf_uint8(frw_event_mem_stru *pst_event_mem)
{
    return hmac_hcc_tx_event_payload_to_netbuf(pst_event_mem, sizeof(uint8_t));
}

/*
 * 函 数 名  : hmac_user_add_notify_alg_tx_adapt
 * 功能描述  : 通过SDIO下发数据，通知dmac挂算法钩子函数
 * 1.日    期  : 2014年10月13日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_user_add_notify_alg_tx_adapt(frw_event_mem_stru *pst_event_mem)
{
    oam_info_log0(0, OAM_SF_ANY, "{hmac_user_add_notify_alg_tx_adapt::tx adapt.}");
    return hmac_hcc_tx_event_payload_to_netbuf(pst_event_mem, sizeof(dmac_ctx_add_user_stru));
}

/*
 * 函 数 名  : hmac_proc_rx_process_sync_event_tx_adapt
 * 功能描述  : 输入参数  : 无
 * 1.日    期  : 2015年1月3日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_proc_rx_process_sync_event_tx_adapt(frw_event_mem_stru *pst_event_mem)
{
    return hmac_hcc_tx_event_payload_to_netbuf(pst_event_mem, sizeof(dmac_ctx_action_event_stru));
}

uint32_t hmac_chan_select_channel_mac_tx_adapt(frw_event_mem_stru *pst_event_mem)
{
    return hmac_hcc_tx_event_payload_to_netbuf(pst_event_mem, sizeof(dmac_set_chan_stru));
}

/*
 * 函 数 名  : hmac_chan_initiate_switch_to_new_channel_tx_adapt
 * 1.日    期  : 2015年1月16日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_chan_initiate_switch_to_new_channel_tx_adapt(frw_event_mem_stru *pst_event_mem)
{
    return hmac_hcc_tx_event_payload_to_netbuf(pst_event_mem, sizeof(dmac_set_ch_switch_info_stru));
}

#ifdef _PRE_WLAN_FEATURE_EDCA_OPT_AP
/*
 * 函 数 名  : hmac_edca_opt_stat_event_tx_adapt
 * 1.日    期  : 2015年4月20日
  *   修改内容  : 新生成函数
 */
uint32_t hmac_edca_opt_stat_event_tx_adapt(frw_event_mem_stru *pst_event_mem)
{
    return hmac_hcc_tx_event_payload_to_netbuf(pst_event_mem,
        sizeof(uint8_t) * (WLAN_WME_AC_BUTT * WLAN_TXRX_DATA_BUTT));
}

#endif

int32_t hmac_rx_extend_hdr_vaild_check(struct frw_hcc_extend_hdr *pst_extend_hdr)
{
    if (oal_unlikely(pst_extend_hdr->en_nest_type >= FRW_EVENT_TYPE_BUTT ||
        pst_extend_hdr->en_nest_type == FRW_EVENT_TYPE_HOST_DRX)) {
        return OAL_FALSE;
    }

    return OAL_TRUE;
}

int32_t hmac_rx_wifi_config_netbuf_filter(struct frw_hcc_extend_hdr *extend_hdr)
{
    hmac_vap_stru *hmac_vap = NULL;

    hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(extend_hdr->vap_id);
    if (oal_unlikely(hmac_vap == NULL)) {
        oam_warning_log1(0, OAM_SF_ANY, "hmac rx adapt ignored,pst vap is null, vap id:%u", extend_hdr->vap_id);
        return -OAL_EINVAL;
    }
    if (hmac_vap->st_vap_base_info.uc_init_flag == MAC_VAP_VAILD) {
        return OAL_SUCC;
    }
    if (extend_hdr->vap_id != 0) {
        oam_warning_log2(extend_hdr->vap_id, OAM_SF_ANY, "hmac rx adapt ignored,main:%u,sub:%u",
            extend_hdr->en_nest_type, extend_hdr->uc_nest_sub_type);
        return -OAL_ENOMEM;
    }
    return OAL_SUCC;
}

#ifdef _PRE_WLAN_WAKEUP_SRC_PARSE
void hmac_rx_wifi_pm_wkup(struct frw_hcc_extend_hdr *extend_hdr, oal_netbuf_stru *netbuf)
{
    if (OAL_TRUE != wlan_pm_wkup_src_debug_get()) {
        return;
    }

    oal_io_print("wifi_wake_src:event[%d],subtype[%d]!\n", extend_hdr->en_nest_type, extend_hdr->uc_nest_sub_type);
    if (extend_hdr->en_nest_type == FRW_EVENT_TYPE_WLAN_DRX) {
        return;
    }
    if ((extend_hdr->en_nest_type == FRW_EVENT_TYPE_HOST_SDT_REG) &&
        (extend_hdr->uc_nest_sub_type == DMAC_TO_HMAC_SYN_CFG)) {
        uint8_t netbuf_offset = sizeof(struct frw_hcc_extend_hdr) + OAL_MAX_CB_LEN + MAX_MAC_HEAD_LEN;
        dmac_to_hmac_cfg_msg_stru *syn_msg =
            (dmac_to_hmac_cfg_msg_stru *)(oal_netbuf_data(netbuf) + netbuf_offset);
        oal_io_print("wifi_wake_src:sys event id[%d]\n", syn_msg->en_syn_id);
    }

    /* 管理帧事件，开关在管理帧处理流程中打印具体的管理帧类型后关闭 */
    if (!((extend_hdr->en_nest_type == FRW_EVENT_TYPE_WLAN_CRX) &&
        (extend_hdr->uc_nest_sub_type == DMAC_WLAN_CRX_EVENT_SUB_TYPE_RX))) {
            wlan_pm_wkup_src_debug_set(OAL_FALSE);
    }
}
#endif

int32_t hmac_rx_wifi_event_handle(hcc_netbuf_stru *hcc_netbuf, frw_event_mem_stru *event_mem,
    struct frw_hcc_extend_hdr *extend_hdr)
{
    hcc_event_stru *event_payload = NULL;
    uint8_t *hcc_extend_hdr = NULL;
    frw_event_stru *event = NULL;

    mac_rx_ctl_stru *rx_ctl = NULL;
    int32_t ret;

    /* trim the frw hcc extend header */
    oal_netbuf_pull(hcc_netbuf->pst_netbuf, sizeof(struct frw_hcc_extend_hdr));

    /* event hdr point */
    event = frw_get_event_stru(event_mem);

    /* fill event hdr */
    frw_event_hdr_init(&(event->st_event_hdr),
                       extend_hdr->en_nest_type,
                       extend_hdr->uc_nest_sub_type,
                       sizeof(hcc_event_stru),
                       FRW_EVENT_PIPELINE_STAGE_1,
                       extend_hdr->chip_id, extend_hdr->device_id, extend_hdr->vap_id);

    event_payload = (hcc_event_stru *)frw_get_event_payload(event_mem);
    event_payload->pst_netbuf = hcc_netbuf->pst_netbuf;
    event_payload->buf_len = oal_netbuf_len(hcc_netbuf->pst_netbuf);

    hcc_extend_hdr = oal_netbuf_data((oal_netbuf_stru *)event_payload->pst_netbuf);
    rx_ctl = (mac_rx_ctl_stru *)hcc_extend_hdr;

    if (!(rx_ctl->bit_is_beacon)) {
        g_pm_wlan_pkt_statis.d2h_rx_pkt++;
    }

    frw_event_task_lock();
    ret = (int32_t)frw_event_dispatch_event(event_mem);
    frw_event_task_unlock();
    if (oal_warn_on(ret != OAL_SUCC)) {
        /* 如果事件入队失败，内存失败由该函数释放，直接调用的由rx adapt函数释放! */
        oal_io_print("[WARN]hcc rx post event failed!!!ret=%u,main:%d,sub:%d\n",
                     ret,
                     extend_hdr->en_nest_type,
                     extend_hdr->uc_nest_sub_type);
    }
    return ret;
}

int32_t hmac_rx_wifi_post_action_function(struct hcc_handler *hcc, uint8_t stype,
                                          hcc_netbuf_stru *pst_hcc_netbuf, uint8_t *pst_context)
{
    int32_t ret;
    hmac_vap_stru *pst_hmac_vap = NULL;
    struct frw_hcc_extend_hdr *pst_extend_hdr = NULL;
    frw_event_mem_stru *pst_event_mem = NULL; /* event mem */

    oal_reference(hcc);

    pst_extend_hdr = (struct frw_hcc_extend_hdr *)oal_netbuf_data(pst_hcc_netbuf->pst_netbuf);
    if (OAL_TRUE != hmac_rx_extend_hdr_vaild_check(pst_extend_hdr)) {
        oal_print_hex_dump(oal_netbuf_data(pst_hcc_netbuf->pst_netbuf),
                           (int32_t)oal_netbuf_len(pst_hcc_netbuf->pst_netbuf),
                           32, "invaild frw extend hdr: "); // 32代表长度
        oal_netbuf_free(pst_hcc_netbuf->pst_netbuf);
        return -OAL_EINVAL;
    }

    pst_hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(pst_extend_hdr->vap_id);

    frw_event_task_lock();
    ret = hmac_rx_wifi_config_netbuf_filter(pst_extend_hdr);
    frw_event_task_unlock();
    if (ret != OAL_SUCC) {
        oal_netbuf_free(pst_hcc_netbuf->pst_netbuf);
        return ret;
    }

#ifdef _PRE_WLAN_WAKEUP_SRC_PARSE
    hmac_rx_wifi_pm_wkup(pst_extend_hdr, pst_hcc_netbuf->pst_netbuf);
#endif
    pst_event_mem = frw_event_alloc_m(sizeof(hcc_event_stru));
    if (pst_event_mem == NULL) {
        oal_io_print("[WARN]event mem alloc failed\n");
        oal_netbuf_free(pst_hcc_netbuf->pst_netbuf);
        return -OAL_ENOMEM;
    }

    ret = hmac_rx_wifi_event_handle(pst_hcc_netbuf, pst_event_mem, pst_extend_hdr);
    frw_event_free_m(pst_event_mem);
    return ret;
}

int32_t hmac_hcc_adapt_init(void)
{
    hmac_tx_net_queue_map_init();
    hmac_tx_sched_info_init();
    hcc_rx_register(hcc_get_handler(HCC_EP_WIFI_DEV), HCC_ACTION_TYPE_WIFI,
                    hmac_rx_wifi_post_action_function, NULL);
#ifdef _PRE_CONFIG_HISI_PANIC_DUMP_SUPPORT
    hwifi_panic_log_register(&hmac_panic_hcc_adapt, NULL);
#endif
    return OAL_SUCC;
}
