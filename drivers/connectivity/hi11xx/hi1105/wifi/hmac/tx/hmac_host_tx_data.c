/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * 功能说明 : Host发送(Ring模式)模块
 * 作    者 : wifi
 * 创建日期 : 2020年4月23日
 */

#include "hmac_host_tx_data.h"
#include "hmac_tx_msdu_dscr.h"
#include "hmac_tx_ring_alloc.h"
#include "hmac_tid_sche.h"
#include "hmac_tid_update.h"
#include "hmac_tx_data.h"
#include "mac_data.h"
#ifdef _PRE_WLAN_FEATURE_TCP_ACK_BUFFER
#include "hmac_tcp_ack_buf.h"
#endif
#include "hmac_stat.h"
#include "hmac_wapi.h"
#include "hmac_tid_ring_switch.h"
#include "host_hal_ext_if.h"
#ifdef _PRE_WLAN_FEATURE_MCAST_AMPDU
#include "hmac_mcast_ampdu.h"
#endif
#ifdef _PRE_WLAN_CHBA_MGMT
#include "hmac_chba_ps.h"
#endif
#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_HOST_TX_DATA_C

#define MAC_DATA_DOUBLE_VLAN_MIN_LEN           22   /* 双vlan最小报文长度 */
#define MAC_DATA_DOUBLE_VLAN_ETHER_TYPE_OFFSET (ETHER_ADDR_LEN * 2 + sizeof(mac_vlan_tag_stru) * 2)

/*
 * 功能描述 : 通过ring发送数据帧
 * 1.日    期 : 2020年2月17日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
uint32_t hmac_host_ring_tx(hmac_vap_stru *hmac_vap, hmac_user_stru *hmac_user, oal_netbuf_stru *netbuf)
{
    uint8_t tid_no = mac_get_cb_wme_tid_type((mac_tx_ctl_stru *)oal_netbuf_cb(netbuf));
    hmac_tid_info_stru *tid_info = &hmac_user->tx_tid_info[tid_no];
    hmac_msdu_info_ring_stru *tx_ring = &tid_info->tx_ring;
    oal_netbuf_stru *next_buf = NULL;
    hal_pm_try_wakeup_forbid_sleep();
    if (hal_pm_try_wakeup_dev_lock() != OAL_SUCC) {
        hal_pm_try_wakeup_allow_sleep();
        return OAL_FAIL;
    }

    mutex_lock(&tx_ring->tx_lock);

    if (oal_atomic_read(&tid_info->ring_tx_mode) != HOST_RING_TX_MODE) {
        mutex_unlock(&tx_ring->tx_lock);
        hal_pm_try_wakeup_allow_sleep();
        oam_warning_log2(0, 0, "{hmac_host_ring_tx::usr[%d] tid[%d] mode err}", tid_info->user_index, tid_info->tid_no);
        return OAL_FAIL;
    }

    if (!hmac_tx_ring_alloced(tx_ring) && hmac_alloc_tx_ring_after_inited(tid_info, tx_ring) != OAL_SUCC) {
        mutex_unlock(&tx_ring->tx_lock);
        hal_pm_try_wakeup_allow_sleep();
        hmac_tid_info_deinit(tid_info);
        return OAL_FAIL;
    }

    if (hmac_tx_ring_switch_enabled() == OAL_TRUE) {
        hmac_tid_ring_switch_list_enqueue(tid_info);
    }

    while (netbuf != NULL) {
        next_buf = oal_netbuf_next(netbuf);
        if (hmac_tx_ring_push_msdu(&hmac_vap->st_vap_base_info, tx_ring, netbuf) != OAL_SUCC) {
            /*
             * 1. 流量高时一次性处理大量netbuf, 可能会使tx ring table写指针更新不及时, 导致MAC无帧可发但软件ring满的情况
             * 此时需要强制更新一次写指针, 加速MAC消耗ring中数据帧, 提升发送效率, 降低入ring失败带来的无效MIPS开销
             * 2. 此处返回fail一定是netbuf未进行dma map或已unmap的情况, 可直接释放
             *
             */
            hmac_tx_reg_write_ring_info(tid_info, TID_CMDID_ENQUE);
            oam_warning_log0(0, OAM_SF_TX, "{hmac_host_ring_tx::tx ring push fail}");
            hmac_free_netbuf_list(netbuf);
            break;
        }

        netbuf = next_buf;
    }

    hmac_host_ring_tx_suspend(hmac_vap, hmac_user, tid_info);

    mutex_unlock(&tx_ring->tx_lock);
    hal_pm_try_wakeup_allow_sleep();
    return OAL_SUCC;
}

/*
 * 功能描述 : 设置VLAN以太帧的data type、snap cb字段
 * 1.日    期 : 2020年4月23日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
OAL_STATIC OAL_INLINE oal_bool_enum_uint8 hmac_ether_with_double_vlan_tag(oal_netbuf_stru *netbuf, uint16_t ether_type)
{
    return (oal_netbuf_len(netbuf) >= MAC_DATA_DOUBLE_VLAN_MIN_LEN &&
           (ether_type == oal_host2net_short(ETHER_TYPE_VLAN_88A8) ||
           ether_type == oal_host2net_short(ETHER_TYPE_VLAN_9100) ||
           ether_type == oal_host2net_short(ETHER_TYPE_VLAN))) ? OAL_TRUE : OAL_FALSE;
}

/*
 * 功能描述 : 双vlan以太网报文的情况下, 返回第二个vlan的ether type
 * 1.日    期 : 2020年4月23日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
OAL_STATIC OAL_INLINE uint16_t hmac_ether_get_second_vlan_type(uint8_t *vlan_ether_hdr)
{
    return *(uint16_t *)(vlan_ether_hdr + MAC_DATA_DOUBLE_VLAN_ETHER_TYPE_OFFSET);
}

/*
 * 功能描述 : 设置VLAN以太帧的data type、snap cb字段
 * 1.日    期 : 2020年4月23日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
OAL_STATIC void hmac_ether_set_vlan_data_type(mac_tx_ctl_stru *tx_ctl, oal_netbuf_stru *netbuf)
{
    oal_vlan_ethhdr_stru *vlan_ether_hdr = (oal_vlan_ethhdr_stru *)oal_netbuf_data(netbuf);
    uint16_t ether_type = vlan_ether_hdr->h_vlan_encapsulated_proto;

    /* 单vlan以太网类型报文 */
    mac_get_cb_data_type(tx_ctl) = DATA_TYPE_1_VLAN_ETH;

    if (hmac_ether_with_double_vlan_tag(netbuf, ether_type) == OAL_TRUE) {
        /* 双vlan以太网报文 */
        mac_get_cb_data_type(tx_ctl) = DATA_TYPE_2_VLAN_ETH;

        /* 取第2个vlan后面的2字节用于802.3报文判断, DA|SA|VLAN|VLAN|TYPE(LEN)|DATA */
        ether_type = hmac_ether_get_second_vlan_type((uint8_t *)vlan_ether_hdr);
    }

    /* 判断是否是802.3报文 */
    mac_get_cb_is_802_3_snap(tx_ctl) = MAC_DATA_TYPE_INVALID_MIN_VALUE >= oal_net2host_short(ether_type);
}

/*
 * 功能描述 : 设置其他以太帧的data type、snap cb字段
 * 1.日    期 : 2020年4月23日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
OAL_STATIC OAL_INLINE void hmac_ether_set_other_data_type(mac_tx_ctl_stru *tx_ctl, oal_netbuf_stru *netbuf)
{
    uint16_t ether_type = mac_get_cb_ether_type(tx_ctl);

    mac_get_cb_is_802_3_snap(tx_ctl) = MAC_DATA_TYPE_INVALID_MIN_VALUE >= oal_net2host_short(ether_type);
}

/*
 * 功能描述 : vlan、其他报文类型检查与设置
 * 1.日    期 : 2020年4月23日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
OAL_STATIC void hmac_ether_set_data_type(mac_tx_ctl_stru *tx_ctl, oal_netbuf_stru *netbuf)
{
    /* 默认设置 */
    mac_get_cb_data_type(tx_ctl) = DATA_TYPE_ETH;

    switch (mac_get_cb_frame_subtype(tx_ctl)) {
        case MAC_DATA_VLAN:
            hmac_ether_set_vlan_data_type(tx_ctl, netbuf);
            break;
        case MAC_DATA_BUTT:
            hmac_ether_set_other_data_type(tx_ctl, netbuf);
            break;
        default:
            break;
    }

    /* 802.3格式 */
    if (mac_get_cb_is_802_3_snap(tx_ctl)) {
        mac_get_cb_data_type(tx_ctl) |= DATA_TYPE_802_3_SNAP;
    }
}

/*
 * 功能描述 : host发送MPDU报文,netbuf内容调整
 * 1.日    期 : 2020.5.16
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
OAL_STATIC void hmac_host_tx_mpdu_netbuf_move(oal_netbuf_stru *netbuf)
{
    mac_tx_ctl_stru *tx_ctl = NULL;
    uint32_t mac_hdr_len;
    int32_t ret;

    while (netbuf != NULL) {
        tx_ctl = (mac_tx_ctl_stru *)oal_netbuf_cb(netbuf);
        mac_hdr_len = mac_get_cb_frame_header_length(tx_ctl);
        mac_get_cb_data_type(tx_ctl) = DATA_TYPE_80211;
        /* MAC header和snap头部分存在空洞，需要调整mac header内容位置 */
        ret = memmove_s(oal_netbuf_data(netbuf) - mac_hdr_len, mac_hdr_len,
            mac_get_cb_frame_header_addr(tx_ctl), mac_hdr_len);
        if (oal_unlikely(ret != EOK)) {
            oam_error_log0(0, 0, "hmac_host_tx_mpdu_netbuf_adjust:memmove fail");
        }
        oal_netbuf_push(netbuf, mac_hdr_len);
        /* 记录新的MAC头的位置 */
        mac_get_cb_frame_header_addr(tx_ctl) = (mac_ieee80211_frame_stru *)oal_netbuf_data(netbuf);
        /* 分片场景存在多个netbuf */
        netbuf = oal_netbuf_next(netbuf);
    }
}

OAL_STATIC oal_bool_enum_uint8 hmac_host_tx_need_transfer_to_80211(hmac_vap_stru *hmac_vap,
    hmac_user_stru *hmac_user, oal_netbuf_stru *netbuf, mac_tx_ctl_stru *tx_ctl)
{
    /* host_tx需要封装为802.11格式条件：
     * 1. 分片报文
     * 2. 芯片不支持WAPI硬件加解密 && WAPI关联场景
     * host tx模式下分片/WAPI 时需要软件封装802.11帧头, 其余情况硬件会进行封装
     * 也可通过设置msdu info中的data type = 3进行软件封装, 详见Host描述符文档
     */
    if ((hmac_tx_need_frag(hmac_vap, hmac_user, netbuf, tx_ctl) != 0)
#ifdef _PRE_WLAN_FEATURE_WAPI
        || ((wlan_chip_is_support_hw_wapi() == OAL_FALSE) && (wapi_port_flag(&hmac_user->st_wapi) == OAL_TRUE))
#endif
        ) {
        return OAL_TRUE;
    }

    return OAL_FALSE;
}

static inline void hmac_ring_tx_update_tid(mac_tx_ctl_stru *tx_ctl)
{
    if (mac_get_cb_wme_tid_type(tx_ctl) == WLAN_TIDNO_BCAST) {
        mac_get_cb_wme_tid_type(tx_ctl) = WLAN_TIDNO_VOICE;
        mac_get_cb_wme_ac_type(tx_ctl) = WLAN_WME_TID_TO_AC(WLAN_TIDNO_VOICE);
    }
}

/*
 * 功能描述 : host tx预处理, 包括帧过滤、业务识别、BA会话建立、分片报文802.11头封装等
 * 1.日    期 : 2020年4月23日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
OAL_STATIC uint32_t hmac_host_tx_preprocess(
    hmac_vap_stru *hmac_vap, hmac_user_stru *hmac_user, oal_netbuf_stru **origin_netbuf)
{
    oal_netbuf_stru *netbuf = *origin_netbuf;
    mac_tx_ctl_stru *tx_ctl = (mac_tx_ctl_stru *)oal_netbuf_cb(netbuf);

    if (hmac_tx_filter_security(hmac_vap, netbuf, hmac_user) != OAL_SUCC) {
        return HMAC_TX_DROP_SECURITY_FILTER;
    }

    hmac_ring_tx_update_tid(tx_ctl);

    if (!hmac_tid_info_inited(&hmac_user->tx_tid_info[mac_get_cb_wme_tid_type(tx_ctl)])) {
        return HMAC_TX_DROP_USER_NULL;
    }

    if (hmac_tid_need_ba_session(hmac_vap, hmac_user, mac_get_cb_wme_tid_type(tx_ctl), netbuf) == OAL_TRUE) {
        hmac_tx_ba_setup(hmac_vap, hmac_user, mac_get_cb_wme_tid_type(tx_ctl));
    }

#ifdef _PRE_WLAN_CHBA_MGMT
    hmac_chba_sync_user_bitmap_level_by_data_type(hmac_vap, hmac_user, tx_ctl);
#endif

    if (hmac_host_tx_need_transfer_to_80211(hmac_vap, hmac_user, netbuf, tx_ctl) == OAL_FALSE) {
#ifdef _PRE_WLAN_FEATURE_TCP_ACK_BUFFER
        if (hmac_tx_tcp_ack_buf_process(hmac_vap, hmac_user, netbuf) == HMAC_TX_BUFF) {
            return HMAC_TX_BUFF;
        }
#endif
        return HMAC_TX_PASS;
    }

#ifndef _PRE_WINDOWS_SUPPORT
    /* MAC层分片与CSUM硬化功能不共存，此场景由驱动计算CSUM值 */
    if (netbuf->ip_summed == CHECKSUM_PARTIAL) {
        oal_skb_checksum_help(netbuf);
        netbuf->ip_summed = CHECKSUM_COMPLETE;
    }
#endif

    /* 分片报文由软件组MAC头 */
    if (hmac_tx_encap_ieee80211_header(hmac_vap, hmac_user, netbuf) != OAL_SUCC) {
        oam_warning_log0(0, OAM_SF_TX, "{hmac_host_tx_preprocess_sta::hmac_tx_encap_ieee80211_header failed}");
        return HMAC_TX_DROP_80211_ENCAP_FAIL;
    }

    hmac_host_tx_mpdu_netbuf_move(netbuf);

    /* WAPI host_tx 加密处理 */
#ifdef _PRE_WLAN_FEATURE_WAPI
    {
        *origin_netbuf = hmac_wapi_netbuf_tx_encrypt_mp16(hmac_vap, hmac_user, netbuf);
        if (*origin_netbuf == NULL) {
            /* WAPI加密失败，netbuf在此处释放并返回TX_DONE, 不需要外部释放 */
            hmac_free_netbuf_list(netbuf);
            oam_warning_log0(0, 0, "{hmac_host_tx_preprocess_sta::hmac_wapi_netbuff_tx_handle_sta failed}");
            return HMAC_TX_DONE;
        }

        /* 如果*origin_netbuf和netbuf指针不相同则说明做过加密, 释放掉旧的netbuf */
        if (*origin_netbuf != netbuf) {
            hmac_free_netbuf_list(netbuf);
        }
    }
#endif /* _PRE_WLAN_FEATURE_WAPI */

    return HMAC_TX_PASS;
}

/*
 * 功能描述 : 判断是否允许进行host tx
 * 1.日    期 : 2020年4月23日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
OAL_STATIC OAL_INLINE uint32_t hmac_host_tx_netbuf_allowed(mac_vap_stru *mac_vap, hmac_vap_stru *hmac_vap)
{
    if (hmac_vap == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    if (mac_vap->en_vap_mode != WLAN_VAP_MODE_BSS_AP && mac_vap->en_vap_mode != WLAN_VAP_MODE_BSS_STA) {
        return OAL_ERR_CODE_CONFIG_UNSUPPORT;
    }

    if (mac_vap->us_user_nums == 0) {
        return OAL_FAIL;
    }

    return OAL_SUCC;
}

static uint32_t hmac_host_tx_tid_enqueue_nolock(hmac_tid_info_stru *tid_info, oal_netbuf_stru *netbuf)
{
    oal_netbuf_stru *next_buf = NULL;

    if (!hmac_tid_info_inited(tid_info)) {
        oam_warning_log1(0, 0, "{hmac_host_tx_tid_enqueue_nolock::tid[%d] not inited}", tid_info->tid_no);
        return OAL_FAIL;
    }

    while (netbuf != NULL) {
        next_buf = oal_netbuf_next(netbuf);
        hmac_tid_netbuf_enqueue(&tid_info->tid_queue, netbuf);
        netbuf = next_buf;
    }

    if ((hmac_tid_sche_allowed(tid_info) == OAL_TRUE) && oal_likely(!hmac_tx_ring_switching(tid_info))) {
        hmac_tid_schedule();
    }

    return OAL_SUCC;
}

/*
 * 功能描述 : netbuf入tid缓存队列, 并将对应的user tid结构体挂给tid调度管理结构体等待调度
 * 1.日    期 : 2020年7月29日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
uint32_t hmac_host_tx_tid_enqueue(hmac_tid_info_stru *tid_info, oal_netbuf_stru *netbuf)
{
    uint32_t ret;

    oal_spin_lock_bh(&tid_info->lock);
    ret = hmac_host_tx_tid_enqueue_nolock(tid_info, netbuf);
    oal_spin_unlock_bh(&tid_info->lock);

    return ret;
}

/*
 * 功能描述 : host tx主入口
 * 1.日    期 : 2020年4月13日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
uint32_t hmac_ring_tx(hmac_vap_stru *hmac_vap, oal_netbuf_stru **netbuf, mac_tx_ctl_stru *tx_ctl)
{
    hmac_user_stru *hmac_user = NULL;
    mac_vap_stru *mac_vap = &hmac_vap->st_vap_base_info;
    uint32_t ret = hmac_host_tx_netbuf_allowed(mac_vap, hmac_vap);
    if (ret != OAL_SUCC) {
        return ret;
    }

    /* 发包统计 */
    hmac_stat_device_tx_msdu(oal_netbuf_get_len(*netbuf));

    /* csum上层填写在skb cb里, 后续流程根据该字段填写 */
    hmac_ether_set_data_type(tx_ctl, *netbuf);

    hmac_user = mac_res_get_hmac_user(mac_get_cb_tx_user_idx(tx_ctl));
    if (oal_unlikely(hmac_user == NULL)) {
        oam_warning_log0(mac_vap->uc_vap_id, OAM_SF_TX, "{hmac_host_tx::hmac_user is null.}");
        return OAL_FAIL;
    }
    switch (hmac_host_tx_preprocess(hmac_vap, hmac_user, netbuf)) {
        case HMAC_TX_PASS:
            return hmac_host_tx_data(hmac_vap, hmac_user, *netbuf);
        case HMAC_TX_BUFF:
        case HMAC_TX_DONE:
            return OAL_SUCC;
        default:
            return OAL_FAIL;
    }
}

/*
 * host ring tx流控水线, ring中sk_buff数量:
 * 达到上水线(suspend)时, 停止mac_vap对应的netdev下发数据帧
 * 降低至下水线(resume)时, 恢复mac_vap对应的netdev下发数据帧
 */
static inline uint32_t hmac_ring_tx_suspend_th(hmac_tid_info_stru *tid_info)
{
    return (hal_host_tx_tid_ring_depth_get(tid_info->tx_ring.base_ring_info.size) * 7 / 8); // 7/8: 流控上水线(87.5%)
}

static inline uint32_t hmac_ring_tx_resume_th(hmac_tid_info_stru *tid_info)
{
    return (hal_host_tx_tid_ring_depth_get(tid_info->tx_ring.base_ring_info.size) * 1 / 2); // 1/2: 流控上水线(50%)
}

void hmac_host_ring_tx_suspend(hmac_vap_stru *hmac_vap, hmac_user_stru *hmac_user, hmac_tid_info_stru *tid_info)
{
    if (oal_atomic_read(&tid_info->tx_ring.msdu_cnt) < hmac_ring_tx_suspend_th(tid_info) ||
        oal_atomic_read(&hmac_user->netdev_tx_suspend)) {
        return;
    }

    if (oal_unlikely(hmac_vap->pst_net_device == NULL)) {
        return;
    }

    if (oal_atomic_read(&hmac_vap->tx_suspend_user_cnt) == 0) {
        oal_net_tx_stop_all_queues(hmac_vap->pst_net_device);
    }

    oal_atomic_inc(&hmac_vap->tx_suspend_user_cnt);
    oal_atomic_set(&hmac_user->netdev_tx_suspend, OAL_TRUE);
}

void hmac_host_ring_tx_resume(hmac_vap_stru *hmac_vap, hmac_user_stru *hmac_user, hmac_tid_info_stru *tid_info)
{
    if (oal_atomic_read(&tid_info->tx_ring.msdu_cnt) > hmac_ring_tx_resume_th(tid_info) ||
        !oal_atomic_read(&hmac_user->netdev_tx_suspend)) {
        return;
    }

    if (oal_unlikely(hmac_vap->pst_net_device == NULL)) {
        return;
    }

    oal_atomic_dec(&hmac_vap->tx_suspend_user_cnt);
    if (oal_atomic_read(&hmac_vap->tx_suspend_user_cnt) == 0) {
        oal_net_tx_wake_all_queues(hmac_vap->pst_net_device);
    }

    oal_atomic_set(&hmac_user->netdev_tx_suspend, OAL_FALSE);
}

static uint8_t hmac_tid_ring_tx_allowed(mac_tx_ctl_stru *tx_ctl)
{
    hmac_user_stru *hmac_user = mac_res_get_hmac_user(mac_get_cb_tx_user_idx(tx_ctl));

    if (oal_unlikely(!hmac_user)) {
        oam_warning_log0(0, 0, "{hmac_tid_ring_tx_allowed::hmac_user NULL}");
        return OAL_FALSE;
    }

    return hmac_tid_info_inited(&hmac_user->tx_tid_info[mac_get_cb_wme_tid_type(tx_ctl)]);
}

/*
 * 功能描述 : netbuf是否采用ring tx模式
 * 1.日    期 : 2020年4月13日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
oal_bool_enum_uint8 hmac_is_ring_tx(mac_vap_stru *mac_vap, oal_netbuf_stru *netbuf, mac_tx_ctl_stru *tx_ctl)
{
    mac_ether_header_stru *eth_hdr = NULL;
    oal_bool_enum_uint8 need_ring_tx = OAL_TRUE;

    if (hmac_ring_tx_enabled() != OAL_TRUE) {
        return OAL_FALSE;
    }

    if (!hmac_tid_ring_tx_allowed(tx_ctl)) {
        return OAL_FALSE;
    }

    eth_hdr = (mac_ether_header_stru *)oal_netbuf_data(netbuf);
    if (mac_vap->en_vap_mode != WLAN_VAP_MODE_BSS_STA) {
        /* AP模式的单播帧支持ring tx, 组播帧不支持ring tx; STA模式没有组播帧 */
        need_ring_tx = !mac_get_cb_is_mcast(tx_ctl);
    }
#ifdef _PRE_WLAN_FEATURE_MCAST_AMPDU
    /* 如果组播聚合打开，则组播数据需要走ring tx流程，并走tid6 */
    if (mac_get_mcast_ampdu_switch() == OAL_TRUE) {
        hmac_mcast_ampdu_netbuf_process(mac_vap, netbuf, tx_ctl, eth_hdr, &need_ring_tx);
    }
#endif
    return (mac_get_cb_wme_tid_type(tx_ctl) != WLAN_TIDNO_BCAST) && need_ring_tx;
}

uint32_t hmac_host_tx_data(hmac_vap_stru *hmac_vap, hmac_user_stru *hmac_user, oal_netbuf_stru *netbuf)
{
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    uint8_t tid;
    uint32_t ret = OAL_FAIL;

    if (oal_likely(hmac_get_tid_schedule_list()->tid_schedule_thread)) {
        tid = mac_get_cb_wme_tid_type((mac_tx_ctl_stru *)oal_netbuf_cb(netbuf));
        ret = hmac_host_tx_tid_enqueue(&hmac_user->tx_tid_info[tid], netbuf);

        host_end_record_performance(1, TX_XMIT_PROC);
    }

    return ret;
#else
    return hmac_host_ring_tx(hmac_vap, hmac_user, netbuf);
#endif
}
