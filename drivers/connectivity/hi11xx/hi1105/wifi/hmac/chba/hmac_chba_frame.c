/*
* Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
* 功能说明   : CHBA基本功能
* 作者       : wifi
* 创建日期   : 2021年3月18日
*/

#ifdef _PRE_WLAN_CHBA_MGMT
/* 1 头文件包含 */
#include "securec.h"
#include "securectype.h"
#include "oal_cfg80211.h"
#include "hmac_chba_frame.h"
#include "hmac_chba_interface.h"
#include "hmac_chba_function.h"
#include "hmac_chba_sync.h"
#include "hmac_chba_ps.h"
#include "hmac_chba_user.h"
#include "hmac_chba_chan_switch.h"
#include "hmac_chba_coex.h"
#include "hmac_chba_mgmt.h"
#include "wlan_types.h"
#include "mac_device.h"
#include "mac_ie.h"
#include "hmac_encap_frame_sta.h"
#include "hmac_encap_frame_ap.h"
#include "hmac_chan_mgmt.h"
#include "hmac_scan.h"
#include "hmac_config.h"
#include "hmac_mgmt_ap.h"
#include "hmac_mgmt_sta.h"
#include "hmac_sme_sta.h"
#include "hmac_mgmt_sta_up.h"
#include "hmac_chba_fsm.h"
#include "mac_frame_inl.h"
#include "mac_function.h"
#include "oam_event_wifi.h"
#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_CHBA_FRAME_C

static oal_bool_enum_uint8 hmac_chba_is_chba_action(uint8_t *payload, uint32_t payload_len)
{
    /*
     *                       CHBA Action
     * | category |  chba oui  | oui type | CHBA Attributes |
     * |     1    |     3      |     1    |     variable    |
     * |    127   |   00-E0-FC |   0x88   |                 |
     */
    uint8_t chba_oui[MAC_OUI_LEN] = { 0x00, 0xE0, 0xFC };

    if (payload_len < MAC_CHBA_ACTION_HDR_LEN) {
        return OAL_FALSE;
    }

    if (((payload[0] != MAC_ACTION_CATEGORY_VENDOR) && (payload[0] != MAC_ACTION_CATEGORY_VENDOR_SPECIFIC_PROTECTED)) ||
        oal_memcmp(payload + 1, chba_oui, MAC_OUI_LEN) != 0  ||
        payload[MAC_CHBA_ACTION_OUI_TYPE_LEN] != MAC_OUI_TYPE_CHBA) {
        return OAL_FALSE;
    }

    return OAL_TRUE;
}

/* 功能描述: 判断是否是chba negotiation action, 此action由上层组帧, hisi只负责透传 */
oal_bool_enum_uint8 hmac_is_chba_negotiation_action(uint8_t *action_buf, uint16_t action_len)
{
    if (action_len < MAC_CHBA_NEGOTIATION_ACTION_HDR_LEN) {
        return OAL_FALSE;
    }

    /* | category | action code |  chba oui  | oui type |  length  | CHBA Action Subtype | CHBA Attributes |
     * |     1    |      1      |      3     |     1    |    2     |          1          |   variable      |
     * |    0x4   |     0x9     |   00-E0-FC |   0x88   |          |         0xa         |                 | */
    if ((action_buf[BYTE_OFFSET_0] == MAC_ACTION_CATEGORY_PUBLIC) &&
        (action_buf[BYTE_OFFSET_1] == MAC_PUB_VENDOR_SPECIFIC)) {
        if ((action_buf[BYTE_OFFSET_2] == 0x00) && (action_buf[BYTE_OFFSET_3] == 0xE0) &&
            (action_buf[BYTE_OFFSET_4] == 0xFC) && (action_buf[BYTE_OFFSET_5] == MAC_OUI_TYPE_CHBA)) {
            return (action_buf[BYTE_OFFSET_8] == MAC_CHBA_NEGOTIATION);
        }
    }

    return OAL_FALSE;
}
/*
 * 功能描述  : 发送Sync Request Action帧
 * 日    期  : 2021年03月10日
 * 作    者  : wifi
 */
uint32_t hmac_send_chba_sync_request_action(mac_vap_stru *mac_vap, void *chba_vap,
    uint8_t *peer_addr, uint8_t *payload, uint16_t payload_len)
{
    hmac_chba_vap_stru *chba_vap_info = NULL;
    oal_netbuf_stru *sync_frame = NULL;
    uint8_t *frame_buf = NULL;
    uint32_t frame_len = 0;
    uint32_t ret;
    int32_t err;

    if (oal_any_null_ptr4(mac_vap, chba_vap, peer_addr, payload)) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    chba_vap_info = (hmac_chba_vap_stru *)chba_vap;
    sync_frame = oal_mem_netbuf_alloc(OAL_NORMAL_NETBUF, WLAN_MEM_NETBUF_SIZE2, OAL_NETBUF_PRIORITY_MID);
    if (sync_frame == NULL) {
        oam_warning_log0(mac_vap->uc_vap_id, OAM_SF_CHBA,
            "hmac_send_chba_sync_request_action::sync_req_frame null.");
        return OAL_ERR_CODE_PTR_NULL;
    }
    oal_mem_netbuf_trace(sync_frame, OAL_TRUE);
    memset_s(oal_netbuf_cb(sync_frame), oal_netbuf_cb_size(), 0, oal_netbuf_cb_size());

    /* 将mac header清零 */
    memset_s((uint8_t *)oal_netbuf_header(sync_frame), MAC_80211_FRAME_LEN, 0, MAC_80211_FRAME_LEN);

    /* 封装Sync Request Action */
    frame_buf = (uint8_t *)oal_netbuf_header(sync_frame);
    /* 填写mac头信息 */
    mac_hdr_set_frame_control(frame_buf, WLAN_PROTOCOL_VERSION | WLAN_FC0_TYPE_MGT | WLAN_FC0_SUBTYPE_ACTION);
    oal_set_mac_addr(frame_buf + WLAN_HDR_ADDR1_OFFSET, peer_addr);
    oal_set_mac_addr(frame_buf + WLAN_HDR_ADDR2_OFFSET, mac_mib_get_StationID(mac_vap));
    mac_set_domain_bssid(frame_buf + WLAN_HDR_ADDR3_OFFSET, mac_vap, chba_vap_info);
    frame_len += MAC_80211_FRAME_LEN;

    err = memcpy_s(frame_buf + frame_len, payload_len, payload, payload_len);
    if (err != EOK) {
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_send_chba_sync_request_action:: memcpy failed.");
        oal_netbuf_free(sync_frame);
        return OAL_FAIL;
    }
    frame_len += payload_len;

    oal_netbuf_put(sync_frame, frame_len);
    hmac_chba_mgmt_cb_partial_init(mac_vap, peer_addr, sync_frame, frame_len, OAL_FALSE);

    /* 发送Sync Request Action帧 */
    ret = hmac_tx_mgmt_send_event(mac_vap, sync_frame, frame_len);
    if (ret != OAL_SUCC) {
        oal_netbuf_free(sync_frame);
        oam_warning_log1(mac_vap->uc_vap_id, OAM_SF_CHBA,
            "hmac_send_chba_sync_request_action::hmac_tx_mgmt_send_event failed[%d].", ret);
        return ret;
    }

    return OAL_SUCC;
}

/*
 * 功能描述  : 封装Coex Info Attribute
 * 日    期  : 2021年02月04日
 * 作    者  : wifi
 */
static void mac_set_chba_coex_info_attr(uint8_t *attr_buf, uint16_t *attr_len,
    hmac_chba_vap_stru *chba_vap_info)
{
    uint8_t offset;
    uint8_t chan_idx;
    /***************************************************************************
                 --------------------------------------------------------
                 |AttributeID | Length | Channels cnt|Coex Channels list |
                 --------------------------------------------------------
     Octets:     |1           | 1      | 1           |      variable     |
                 --------------------------------------------------------
     ***************************************************************************/
    /* Attribute ID */
    attr_buf[0] = MAC_CHBA_ATTR_COEX_STATUS;
    offset = MAC_CHBA_ATTR_HDR_LEN;
    /* chan cnt */
    attr_buf[offset++] = chba_vap_info->self_coex_chan_cnt;
    /* 复制共存信道列表 */
    for (chan_idx = 0; chan_idx < chba_vap_info->self_coex_chan_cnt; chan_idx++) {
        attr_buf[offset++] = chba_vap_info->self_coex_channels_list[chan_idx];
    }
    /* 设置Attr Length字段 */
    attr_buf[MAC_CHBA_ATTR_ID_LEN] = offset - MAC_CHBA_ATTR_HDR_LEN;
    *attr_len = offset;
}

/*
 * 功能描述  : Sync Beacon帧封装
 * 日    期  : 2021年02月01日
 * 作    者  : wifi
 */
void hmac_chba_encap_sync_beacon_frame(mac_vap_stru *mac_vap, uint8_t *beacon_buf, uint16_t *beacon_len,
    uint8_t *domain_bssid, uint8_t *payload, uint16_t payload_len)
{
    hmac_chba_system_params *system_params = hmac_get_chba_system_params();
    uint16_t total_len, attr_len, vendor_ie_len;
    hmac_vap_stru *hmac_vap = NULL;
    hmac_chba_vap_stru *chba_vap_info = NULL;
    uint16_t *beacon_interval = NULL;
    uint32_t bcn_int;
    uint8_t *vendor_ie_len_pos = NULL;
    int32_t err;

    if (oal_any_null_ptr5(mac_vap, beacon_buf, beacon_len, domain_bssid, payload)) {
        return;
    }
    hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(mac_vap->uc_vap_id);
    if (hmac_vap == NULL) {
        return;
    }
    chba_vap_info = hmac_vap->hmac_chba_vap_info;
    if (chba_vap_info == NULL) {
        return;
    }

    total_len = 0;
    /* 填写mac头信息 */
    mac_hdr_set_frame_control(beacon_buf, WLAN_PROTOCOL_VERSION | WLAN_FC0_TYPE_MGT | WLAN_FC0_SUBTYPE_BEACON);
    oal_set_mac_addr(beacon_buf + WLAN_HDR_ADDR1_OFFSET, BROADCAST_MACADDR); /* 设置广播发送地址 */
    oal_set_mac_addr(beacon_buf + WLAN_HDR_ADDR2_OFFSET, mac_mib_get_StationID(mac_vap)); /* 设置sa */
    oal_set_mac_addr(beacon_buf + WLAN_HDR_ADDR3_OFFSET, domain_bssid); /* 设置BSSID */

    /* beacon帧没有sequence number */
    mac_hdr_set_fragment_number(beacon_buf, 0);
    total_len += MAC_80211_FRAME_LEN;

    /* Timestamp由硬件填写 */
    memset_s(beacon_buf + total_len, MAC_TIME_STAMP_LEN, 0, MAC_TIME_STAMP_LEN);
    total_len += MAC_TIME_STAMP_LEN;
    /* 填写beacon period字段为512 */
    bcn_int = system_params->schedule_time_ms;
    beacon_interval = (uint16_t *)(beacon_buf + total_len);
    *beacon_interval = (uint16_t)oal_byteorder_to_le32(bcn_int);
    total_len += MAC_BEACON_INTERVAL_LEN;
    /* 填写capinfo字段 */
    mac_set_cap_info_ap(mac_vap, beacon_buf + total_len);
    total_len += MAC_CAP_INFO_LEN;

    vendor_ie_len_pos = beacon_buf + total_len + 1;

    /* 将payload复制到netbuf中 */
    err = memcpy_s(beacon_buf + total_len, payload_len, payload, payload_len);
    if (err != EOK) {
        oam_warning_log0(0, 0, "hmac_chba_encap_sync_beacon_frame::memcpy failed.");
        return;
    }
    total_len += payload_len;
    /* 获取当前的vendor IE Len */
    vendor_ie_len = payload[MAC_CHBA_ATTR_ID_LEN];

    /* 封装coex info属性(必选) */
    mac_set_chba_coex_info_attr(beacon_buf + total_len, &attr_len, chba_vap_info);
    total_len += attr_len;
    vendor_ie_len += attr_len;

    *vendor_ie_len_pos = vendor_ie_len;
    *beacon_len = total_len;
}

/*
 * 功能描述  : PNF帧封装
 * 日    期  : 2021年02月04日
 * 作    者  : wifi
 */
void hmac_chba_encap_pnf_action_frame(mac_vap_stru *mac_vap, uint8_t *pnf_buf, uint16_t *pnf_len)
{
    uint16_t total_len, attr_len;
    hmac_vap_stru *hmac_vap = NULL;
    hmac_chba_vap_stru *chba_vap_info = NULL;
    int32_t err;

    if (oal_any_null_ptr3(mac_vap, pnf_buf, pnf_len)) {
        return;
    }

    *pnf_len = 0;

    hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(mac_vap->uc_vap_id);
    if (hmac_vap == NULL) {
        return;
    }
    chba_vap_info = (hmac_chba_vap_stru *)hmac_vap->hmac_chba_vap_info;
    if (chba_vap_info == NULL) {
        return;
    }

    total_len = 0;
    /* 填写mac头信息 */
    mac_hdr_set_frame_control(pnf_buf, WLAN_PROTOCOL_VERSION | WLAN_FC0_TYPE_MGT | WLAN_FC0_SUBTYPE_ACTION);
    oal_set_mac_addr(pnf_buf + WLAN_HDR_ADDR1_OFFSET, BROADCAST_MACADDR); /* 设置广播发送地址 */
    oal_set_mac_addr(pnf_buf + WLAN_HDR_ADDR2_OFFSET, mac_mib_get_StationID(mac_vap)); /* 设置sa */
    mac_set_domain_bssid(pnf_buf + WLAN_HDR_ADDR3_OFFSET, mac_vap, chba_vap_info); /* 设置BSSID */
    total_len += MAC_80211_FRAME_LEN;

    /* 将保存的payload复制到netbuf中 */
    if (chba_vap_info->pnf_buf_len == 0) {
        oam_warning_log0(0, 0, "hmac_chba_encap_pnf_action_frame::invalid saved pnf, can not encap pnf frame, return.");
        return;
    }
    err = memcpy_s(pnf_buf + total_len, chba_vap_info->pnf_buf_len, chba_vap_info->pnf_buf,
        chba_vap_info->pnf_buf_len);
    if (err != EOK) {
        oam_warning_log0(0, 0, "hmac_chba_encap_pnf_action_frame::hmac_chba_encap_pnf_action_frame::memcpy failed.");
        return;
    }
    total_len += chba_vap_info->pnf_buf_len;

    /* 封装coex info属性(必选) */
    mac_set_chba_coex_info_attr(pnf_buf + total_len, &attr_len, chba_vap_info);
    total_len += attr_len;

    *pnf_len = total_len;
}

static oal_bool_enum_uint8 mac_chba_action_protected(mac_chba_action_category_enum action_type)
{
    return (action_type > MAC_CHBA_PNF && action_type < MAC_CHBA_SYNC_BEACON);
}
void hmac_chba_assoc_set_ssid(hmac_vap_stru *hmac_vap, uint8_t *req_frame, uint8_t *ie_len, uint8_t *dest_addr)
{
    uint8_t *ssid = NULL;
    uint8_t ssid_len;
    hmac_user_stru *hmac_user = NULL;
    hmac_user = mac_vap_get_hmac_user_by_addr(&hmac_vap->st_vap_base_info, dest_addr, WLAN_MAC_ADDR_LEN);
    if (hmac_user == NULL) {
        return;
    }
    *req_frame = MAC_EID_SSID;
    ssid = hmac_user->chba_user.ssid;
    ssid_len = (uint8_t)OAL_STRLEN((int8_t *)ssid);   /* 不包含'\0' */
    *(req_frame + 1) = ssid_len;
    if (memcpy_s(req_frame + MAC_IE_HDR_LEN, ssid_len, ssid, ssid_len) != EOK) {
        oam_error_log0(0, OAM_SF_ANY, "hmac_chba_assoc_set_ssid::memcpy fail!");
    }

    *ie_len = ssid_len + MAC_IE_HDR_LEN;
}
void hmac_chba_set_assoc_scan_bss(hmac_vap_stru *hmac_sta, hmac_scanned_bss_info *scaned_bss)
{
    scaned_bss->st_bss_dscr_info.en_ht_capable = OAL_TRUE;
    scaned_bss->st_bss_dscr_info.en_vht_capable = OAL_TRUE;
    scaned_bss->st_bss_dscr_info.en_support_1024qam = OAL_TRUE;
    scaned_bss->st_bss_dscr_info.uc_num_sounding_dim = 1; /* user的bfer能力 */
    scaned_bss->st_bss_dscr_info.en_ht_ldpc = OAL_TRUE;
    scaned_bss->st_bss_dscr_info.en_ht_stbc = OAL_TRUE;
}
/*
 * 功能描述  : CHBA Action Header填写
 * 日    期  : 2021年02月06日
 * 作    者  : wifi
 */
void mac_set_chba_action_hdr(uint8_t *action_buf, uint8_t action_type)
{
    oal_bool_enum_uint8 protected;
    if (oal_any_null_ptr1(action_buf)) {
        return;
    }

    protected = mac_chba_action_protected(action_type);
    if (protected == OAL_TRUE) {
        action_buf[0] = MAC_ACTION_CATEGORY_VENDOR_SPECIFIC_PROTECTED; /* vendor-specific protected action */
    } else {
        action_buf[0] = MAC_ACTION_CATEGORY_VENDOR; /* vendor-specific action */
    }
    action_buf[BYTE_OFFSET_1] = 0x00; /* 1: oui[0] */
    action_buf[BYTE_OFFSET_2] = 0xE0; /* 2: oui[1] */
    action_buf[BYTE_OFFSET_3] = 0xFC; /* 3: oui[2] */
    action_buf[BYTE_OFFSET_4] = MAC_OUI_TYPE_CHBA;
    action_buf[BYTE_OFFSET_5] = action_type;
}

/*
 * 功能描述  : 填写domain_bssid字段
 * 日    期  : 2021年02月09日
 * 作    者  : wifi
 */
void mac_set_domain_bssid(uint8_t *domain_bssid, mac_vap_stru *mac_vap, hmac_chba_vap_stru *chba_vap_info)
{
    if (oal_any_null_ptr3(domain_bssid, mac_vap, chba_vap_info)) {
        return;
    }

    if (hmac_chba_get_sync_state() == CHBA_NON_SYNC) {
        /* 根据自己的mac地址，生成域BSSID */
        hmac_generate_chba_domain_bssid(domain_bssid, WLAN_MAC_ADDR_LEN,
            mac_mib_get_StationID(mac_vap), WLAN_MAC_ADDR_LEN);
    } else {
        /* 获取域BSSID */
        oal_set_mac_addr(domain_bssid, mac_vap->auc_bssid);
    }
}

/*
 * 功能描述  : 查找帧payload中的属性字段
 * 日    期  : 2021年02月24日
 */
uint8_t *hmac_find_chba_attr(uint8_t attr_id, uint8_t *payload, int32_t len)
{
    if (payload == NULL) {
        return NULL;
    }

    if (len > MAC_CHBA_MGMT_MAX_PAYLOAD_BYTES) {
        return NULL;
    }

    while (len > MAC_CHBA_ATTR_HDR_LEN && payload[0] != attr_id) {
        len -= (int32_t)(payload[1] + MAC_CHBA_ATTR_HDR_LEN);
        payload += payload[1] + MAC_CHBA_ATTR_HDR_LEN;
    }

    if ((len < MAC_CHBA_ATTR_HDR_LEN) || (len < (MAC_CHBA_ATTR_HDR_LEN + payload[1])) ||
        ((len == MAC_CHBA_ATTR_HDR_LEN) && (payload[0] != attr_id))) {
        return NULL;
    }

    return payload;
}

/*
 * 功能描述  : 保存用户态下发的PNF帧或Beacon帧
 * 日    期  : 2021年03月20日
 * 作    者  : wifi
 */
void hmac_chba_save_mgmt_frame(hmac_chba_vap_stru *chba_vap_info, uint8_t *payload,
    uint16_t payload_len, uint8_t mgmt_type)
{
    int32_t err;
    uint8_t *master_attr = NULL;
    uint8_t *attr_payload = NULL;
    uint16_t attr_payload_len;

    if (oal_any_null_ptr2(chba_vap_info, payload)) {
        return;
    }

    if (payload_len == 0) {
        return;
    }

    /* 更新主设备选举字段 */
    attr_payload = payload + MAC_CHBA_ACTION_HDR_LEN;
    attr_payload_len = payload_len - MAC_CHBA_ACTION_HDR_LEN;
    master_attr = hmac_find_chba_attr(MAC_CHBA_ATTR_MASTER_ELECTION, attr_payload, attr_payload_len);
    if (master_attr == NULL) {
        oam_warning_log0(0, OAM_SF_CHBA,
            "hmac_chba_save_mgmt_frame::can't find master election attr in beacon/pnf frame.");
        return;
    }

    if (MAC_CHBA_ATTR_HDR_LEN + master_attr[MAC_CHBA_ATTR_ID_LEN] < MAC_CHBA_MASTER_ELECTION_ATTR_LEN) {
        oam_error_log1(0, OAM_SF_CHBA, "hmac_chba_save_mgmt_frame::master election attr len[%d] invalid.",
            master_attr[MAC_CHBA_ATTR_ID_LEN]);
        return;
    }
    oam_warning_log4(0, OAM_SF_CHBA,
        "hmac_chba_save_mgmt_frame::save mgmt frame, declare sync state %d, master addr is %02X:XX:XX:XX:%02X:%02X.",
        master_attr[MAC_CHBA_ATTR_HDR_LEN],
        master_attr[MAC_CHBA_MASTER_ADDR_POS + MAC_ADDR_0],
        master_attr[MAC_CHBA_MASTER_ADDR_POS + MAC_ADDR_4],
        master_attr[MAC_CHBA_MASTER_ADDR_POS + MAC_ADDR_5]);

    if (mgmt_type == MAC_CHBA_PNF) {
        err = memcpy_s(chba_vap_info->pnf_buf, MAC_CHBA_MGMT_MID_PAYLOAD_BYTES, payload, payload_len);
        if (err == EOK) {
            chba_vap_info->pnf_buf_len = payload_len;
            return;
        }
    } else if (mgmt_type == MAC_CHBA_SYNC_BEACON) {
        err = memcpy_s(chba_vap_info->beacon_buf, MAC_CHBA_MGMT_MAX_PAYLOAD_BYTES, payload, payload_len);
        if (err == EOK) {
            chba_vap_info->beacon_buf_len = payload_len;
            return;
        }
    }

    return;
}

/*
 * 功能描述  : 封装Master Election Attribute
 * 日    期  : 2021年02月04日
 * 作    者  : wifi
 */
uint32_t hmac_chba_set_master_election_attr(uint8_t *attr_buf)
{
    hmac_chba_device_para_stru *device_info = hmac_chba_get_device_info();
    hmac_chba_sync_info *sync_info = hmac_chba_get_sync_info();
    uint16_t schedule_period;
    uint8_t index;
    uint8_t sync_state;
    int32_t err;

    if (attr_buf == NULL) {
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_chba_set_master_election_attr: input pointer is null.");
        return 0;
    }

    /* Attribute ID */
    attr_buf[0] = MAC_CHBA_ATTR_MASTER_ELECTION;
    index = MAC_CHBA_ATTR_HDR_LEN;

    /* Attribute Content */
    hmac_chba_fill_sync_state_field(&sync_state);
    attr_buf[index++] = sync_state;
    attr_buf[index++] = 0; // beacon loss cnt：device 发送pnf时填写
    /* 填写period */
    schedule_period = device_info->config_para.schdule_period * device_info->config_para.slot_duration;
    attr_buf[index++] = (uint8_t)(schedule_period & 0x00FF);
    attr_buf[index++] = (uint8_t)((schedule_period & 0xFF00) >> BIT_OFFSET_8);
    /* 填写sync slot */
    attr_buf[index++] = (uint8_t)(device_info->config_para.discovery_slot & 0xFF);
    attr_buf[index++] = 0;

    /* 填写RP字段 */
    err = memcpy_s(attr_buf + index, sizeof(ranking_priority), &sync_info->own_rp_info, sizeof(ranking_priority));
    index += sizeof(ranking_priority);
    err += memcpy_s(attr_buf + index, sizeof(ranking_priority),
        &sync_info->cur_master_info.master_rp, sizeof(ranking_priority));
    index += sizeof(ranking_priority);
    /* 填写master域bssid */
    err += memcpy_s(attr_buf + index, OAL_MAC_ADDR_LEN, &sync_info->cur_master_info.master_addr, OAL_MAC_ADDR_LEN);
    index += OAL_MAC_ADDR_LEN;
    if (err != EOK) {
        oam_warning_log1(0, OAM_SF_CHBA, "hmac_chba_set_master_election_attr: memcpy failed, err[%d].", err);
        return 0;
    }

    /* 设置Attr Length字段 */
    attr_buf[MAC_CHBA_ATTR_ID_LEN] = index - MAC_CHBA_ATTR_HDR_LEN;
    return index;
}

/*
 * 功能描述  : 封装Link Info Attribute
 * 日    期  : 2021年02月04日
 * 作    者  : wifi
 */
static void hmac_chba_set_link_info_attr(hmac_chba_vap_stru *chba_vap_info, uint8_t *attr_buf, uint16_t *attr_len)
{
    uint8_t index;
    uint8_t link_cnt_pos;
    hmac_vap_stru *hmac_vap = NULL;
    oal_dlist_head_stru *entry = NULL;
    oal_dlist_head_stru *dlist_tmp = NULL;
    mac_user_stru *mac_user = NULL;

    if (oal_any_null_ptr3(chba_vap_info, attr_buf, attr_len)) {
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_chba_set_link_info_attr: input pointer is null.");
        return;
    }

    hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(chba_vap_info->mac_vap_id);
    if (hmac_vap == NULL) {
        oam_error_log0(0, OAM_SF_CHBA, "{hmac_chba_set_link_info_attr:hmac_vap is NULL!}");
        return;
    }

    /* Attribute ID */
    attr_buf[0] = MAC_CHBA_ATTR_LINK_INFO;
    index = MAC_CHBA_ATTR_HDR_LEN;

    /* Attribute Content */
    attr_buf[index++] = chba_vap_info->work_channel.uc_chan_number;
    attr_buf[index++] = chba_vap_info->work_channel.en_bandwidth;

    /* 空一格字段，用于填写Recv RSSI */
    index++;

    /* 清空link cnt字段 */
    link_cnt_pos = index++;
    attr_buf[link_cnt_pos] = 0;
    /* 分别填写每个link的地址 */
    oal_dlist_search_for_each_safe(entry, dlist_tmp, &(hmac_vap->st_vap_base_info.st_mac_user_list_head))
    {
        mac_user = oal_dlist_get_entry(entry, mac_user_stru, st_user_dlist);
        if (mac_user == NULL) {
            continue;
        }
        /* 建链未完成的设备, 不加入link info */
        if (mac_user->en_user_asoc_state != MAC_USER_STATE_ASSOC) {
            continue;
        }
        oal_set_mac_addr(attr_buf + index, mac_user->auc_user_mac_addr);
        attr_buf[link_cnt_pos]++; /* link cnt + 1 */
        index += OAL_MAC_ADDR_LEN;
    }

    /* 设置Attr Length字段 */
    attr_buf[MAC_CHBA_ATTR_ID_LEN] = index - MAC_CHBA_ATTR_HDR_LEN;
    *attr_len = index;
}

/*
 * 功能描述  : 封装Device Capability Attribute
 * 日    期  : 2022年06月29日
 * 作    者  : wifi7
 */
static void hmac_chba_set_device_capability(uint8_t *attr_buf, uint16_t *attr_len)
{
    uint8_t index;

    if (oal_any_null_ptr2(attr_buf, attr_len)) {
        oam_error_log0(0, OAM_SF_CHBA, "hmac_chba_set_device_capability: ptr is NULL!");
        return;
    }

    /***************************************** CHBA device capability *****************************************/
    /* ------------------------------------------------------------------------------------------------------ */
    /* |    ATTR ID    |     LENGTH      | Max Channel Switch Time | Social channel Support |     resv     |  */
    /* ------------------------------------------------------------------------------------------------------ */
    /* |       1       |        1        |            1            |            1           |      8       |  */
    /* ------------------------------------------------------------------------------------------------------ */

    /* Attribute ID */
    attr_buf[0] = MAC_CHBA_ATTR_DEVICE_CAPABILITY;
    index = MAC_CHBA_ATTR_HDR_LEN;

    /* Attribute Max Channel Switch Time 初始化为0, 其能力由device决定 */
    attr_buf[index++] = CHBA_INVALID_MAX_CHANNEL_SWITCH_TIME;

    /* Attribute Social channel Support */
    attr_buf[index++] = g_chba_social_chan_cap;

    /* 预留字段 */
    index += MAC_CHBA_DEVICE_CAPABILITY_RES_LEN;

    /* 设置Attr Length字段 */
    attr_buf[MAC_CHBA_ATTR_ID_LEN] = index - MAC_CHBA_ATTR_HDR_LEN;
    *attr_len = index;
}

/*
 * 功能描述  : 设置bitmap属性
 * 日    期  : 2021年02月24日
 * 作    者  : wifi
 */
static void hmac_chba_set_bitmap_attr(uint8_t *attr_buf, uint16_t *attr_len,
    uint8_t req_rsp_flag, uint32_t bitmap)
{
    uint8_t index;

    if (attr_buf == NULL || attr_len == NULL) {
        return;
    }
    attr_buf[0] = MAC_CHBA_ATTR_POWER_SAVE_BITMAP;
    index = MAC_CHBA_ATTR_HDR_LEN;
    attr_buf[index++] = req_rsp_flag;
    if (memcpy_s(attr_buf + index, sizeof(bitmap), (void*)&bitmap, sizeof(bitmap)) != EOK) {
        return;
    }

    index += sizeof(bitmap);
    attr_buf[MAC_CHBA_ATTR_ID_LEN] = index - MAC_CHBA_ATTR_HDR_LEN;
    *attr_len = index;
}
/*
 * 功能描述  : 封装Island Owner Attribute
 * 日    期  : 2021年09月07日
 */
void hmac_chba_set_island_owner_attr(uint8_t *attr_buf, uint16_t *attr_len)
{
    int32_t ret;
    hmac_chba_mgmt_info_stru *chba_mgmt_info = hmac_chba_get_mgmt_info();
    *attr_len = 0;

    if (chba_mgmt_info->island_owner_attr_len == 0) {
        oam_warning_log0(0, 0, "CHBA: hmac_chba_set_island_owner_attr: buf len 0.");
        return;
    }

    ret = memcpy_s(attr_buf, chba_mgmt_info->island_owner_attr_len,
        chba_mgmt_info->island_owner_attr_buf, chba_mgmt_info->island_owner_attr_len);
    if (ret != 0) {
        oam_warning_log0(0, 0, "CBHA: hmac_chba_set_island_owner_attr: memcpy_s fail");
        return;
    }
    *attr_len = chba_mgmt_info->island_owner_attr_len;
}

static void hmac_chba_set_channel_seq_member(mac_channel_stru *channel,
    struct chba_channel_sequence_member *channel_seq_meber)
{
    channel_seq_meber->channel_number = channel->uc_chan_number;
    channel_seq_meber->bandwidth = channel->en_bandwidth;
}

/* 封装CHBA信道序列参数 */
uint32_t hmac_chba_encap_channel_sequence(hmac_chba_vap_stru *chba_vap_info, uint8_t *buffer)
{
    #define MAX_CHBA_SLOT 32
    uint32_t index;
    uint32_t channel_seq_bitmap = chba_vap_info->channel_sequence_bitmap;
    struct chba_channel_sequence_member *channel_seq_meber = NULL;

    buffer[BYTE_OFFSET_0] = MAC_CHBA_ATTR_CHANNEL_SEQ;
    buffer[BYTE_OFFSET_1] = MAX_CHBA_SLOT * sizeof(struct chba_channel_sequence_member); /* 信道序列参数长度 */

    channel_seq_meber = (struct chba_channel_sequence_member *)(&buffer[BYTE_OFFSET_2]);
    for (index = 0; index < MAX_CHBA_SLOT; index++) {
        if (index < MAC_CHBA_SYNC_SLOT_CNT) {
            /* 同步时隙，填CHBA social 信道 */
            hmac_chba_set_channel_seq_member(&(chba_vap_info->social_channel), channel_seq_meber);
        } else if (channel_seq_bitmap & BIT(index)) {
            /* CHBA工作时隙，填CHBA工作信道 */
            hmac_chba_set_channel_seq_member(&(chba_vap_info->work_channel), channel_seq_meber);
        } else {
            /* 非CHBA工作时隙，填STA工作信道 */
            hmac_chba_set_channel_seq_member(&(chba_vap_info->second_work_channel), channel_seq_meber);
        }
        channel_seq_meber++;
    }
    return MAC_CHBA_ATTR_HDR_LEN + MAX_CHBA_SLOT * sizeof(struct chba_channel_sequence_member);
}

/*
 * 功能描述  : Sync Beacon帧封装(从vendor IE开始)
 * 日    期  : 2021年02月01日
 * 作    者  : wifi
 */
void hmac_chba_encap_sync_beacon(hmac_chba_vap_stru *chba_vap_info, uint8_t *beacon_buf, uint16_t *beacon_len,
    attr_ctrl_info *attr_ctrl)
{
    uint16_t total_len = 0;
    uint16_t attr_len = 0;
    uint16_t vendor_ie_len;
    uint32_t vap_bitmap;
    uint8_t *vendor_ie_len_pos = NULL;

    if (oal_any_null_ptr3(chba_vap_info, beacon_buf, beacon_len)) {
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_chba_encap_sync_beacon: input pointer is null.");
        return;
    }

    /* 填写CHBA Vendor IE Header */
    hmac_chba_set_vendor_ie_hdr(beacon_buf);
    vendor_ie_len_pos = beacon_buf + 1;
    vendor_ie_len = MAC_CHBA_ACTION_HDR_LEN - MAC_CHBA_ATTR_HDR_LEN;
    total_len += MAC_CHBA_ACTION_HDR_LEN;

    /* 封装Master Election属性(必选) */
    hmac_chba_set_master_election_attr(beacon_buf + total_len);
    total_len += MAC_CHBA_MASTER_ELECTION_ATTR_LEN;
    vendor_ie_len += MAC_CHBA_MASTER_ELECTION_ATTR_LEN;

    /* 封装Link Info属性(必选) */
    hmac_chba_set_link_info_attr(chba_vap_info, beacon_buf + total_len, &attr_len);
    total_len += attr_len;
    vendor_ie_len += attr_len;

    /* 封装Device Capability属性(必选) */
    hmac_chba_set_device_capability(beacon_buf + total_len, &attr_len);
    total_len += attr_len;
    vendor_ie_len += attr_len;

    /*  beacon帧封装vap_bitmap字段所需, 允许通过低功耗等级获取其bitmap配置, 后续该vap_bitmap字段将被删除 */
    vap_bitmap = chba_level_to_bitmap(chba_vap_info->vap_bitmap_level);
    /* 封装bitmap属性(必选) */
    hmac_chba_set_bitmap_attr(beacon_buf + total_len, &attr_len, MAC_CHBA_BITMAP_TYPE_BUTT, vap_bitmap);
    total_len += attr_len;
    vendor_ie_len += attr_len;

    /* coex info属性在Driver封装 */
    /* 岛主属性 */
    if (attr_ctrl->island_owner == TRUE) {
        hmac_chba_set_island_owner_attr(beacon_buf + total_len, &attr_len);
        total_len += attr_len;
        vendor_ie_len += attr_len;
    }

    /* 封装信道序列属性(必选) */
    attr_len = hmac_chba_encap_channel_sequence(chba_vap_info, beacon_buf + total_len);
    total_len += attr_len;
    vendor_ie_len += attr_len;

    *vendor_ie_len_pos = vendor_ie_len;
    *beacon_len = total_len;
}

/*
 * 功能描述  : PNF帧封装
 * 日    期  : 2021年02月04日
 * 作    者  : wifi
 */
void hmac_chba_encap_pnf_action(hmac_chba_vap_stru *chba_vap_info, uint8_t *pnf_buf, uint16_t *pnf_len)
{
    uint32_t vap_bitmap;
    uint16_t total_len = 0;
    uint16_t attr_len = 0;

    if (oal_any_null_ptr3(chba_vap_info, pnf_buf, pnf_len)) {
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_chba_encap_pnf_action: input pointer is null.");
        return;
    }

    /* 填写Action 头 */
    mac_set_chba_action_hdr(pnf_buf + total_len, MAC_CHBA_PNF);
    total_len += MAC_CHBA_ACTION_HDR_LEN;

    /* 封装Master Election属性(必选) */
    hmac_chba_set_master_election_attr(pnf_buf + total_len);
    total_len += MAC_CHBA_MASTER_ELECTION_ATTR_LEN;

    /* 封装Link Info属性(必选) */
    hmac_chba_set_link_info_attr(chba_vap_info, pnf_buf + total_len, &attr_len);
    total_len += attr_len;

    /* 封装Device Capability属性(必选) */
    hmac_chba_set_device_capability(pnf_buf + total_len, &attr_len);
    total_len += attr_len;

    /*  PNF帧封装vap_bitmap字段所需, 允许通过低功耗等级获取其bitmap配置, 后续该vap_bitmap字段将被删除 */
    vap_bitmap = chba_level_to_bitmap(chba_vap_info->vap_bitmap_level);
    /* 封装bitmap属性(必选) */
    hmac_chba_set_bitmap_attr(pnf_buf + total_len, &attr_len, MAC_CHBA_BITMAP_TYPE_BUTT, vap_bitmap);
    total_len += attr_len;

    /* 封装信道序列属性(必选) */
    attr_len = hmac_chba_encap_channel_sequence(chba_vap_info, pnf_buf + total_len);
    total_len += attr_len;

    /* coex info属性在Driver封装 */
    *pnf_len = total_len;
}

/* 组关联帧中的CHBA IE */
uint32_t hmac_chba_encape_assoc_attribute(uint8_t *buffer, uint32_t buffer_len)
{
    uint32_t chba_assoc_ie_len;
    chba_assoc_ie_len = hmac_chba_set_vendor_ie_hdr(buffer);
    chba_assoc_ie_len += hmac_chba_set_master_election_attr(buffer + chba_assoc_ie_len);
    if (chba_assoc_ie_len < MAC_IE_HDR_LEN) {
        oam_error_log1(0, OAM_SF_CHBA, "hmac_chba_encape_assoc_attribute::chba ie len [%d] is too short",
            chba_assoc_ie_len);
        return 0;
    }
    buffer[1] = chba_assoc_ie_len - MAC_IE_HDR_LEN;
    return chba_assoc_ie_len;
}

/*
 * 功能描述  : CHBA收到beacon帧上报的处理
 * 日    期  : 2021年02月24日
 */
static void hmac_chba_rx_beacon_proc(hmac_vap_stru *hmac_vap, mac_ieee80211_frame_stru *mac_hdr, uint8_t *payload,
    uint16_t payload_len)
{
    sync_info_flags *sync_flags = hmac_chba_get_sync_flags();
    uint8_t sa_addr[WLAN_MAC_ADDR_LEN], domain_bssid[WLAN_MAC_ADDR_LEN];
    hmac_user_stru *hmac_user = NULL;
    uint8_t is_my_user = OAL_FALSE;
    uint8_t *chba_ie = NULL;
    uint16_t chba_ie_len;
    /* 获取该帧的发送地址 & 域Bssid */
    mac_get_address2((uint8_t *)mac_hdr, sa_addr, WLAN_MAC_ADDR_LEN);
    mac_get_address3((uint8_t *)mac_hdr, domain_bssid, WLAN_MAC_ADDR_LEN);
    // 跳过固定字段和私有IE头
    payload = payload + MAC_CHBA_BEACON_ELEMENT_OFFSET;
    payload_len = payload_len - MAC_CHBA_BEACON_ELEMENT_OFFSET;
    chba_ie = mac_find_vendor_ie(MAC_CHBA_VENDOR_IE, MAC_OUI_TYPE_CHBA, payload, payload_len);
    if (chba_ie == NULL) {
        oam_error_log0(0, OAM_SF_CHBA, "hmac_chba_rx_beacon_proc: can't find chba ie in beacon frame.");
        return;
    }
    chba_ie_len = ((uint16_t)(chba_ie[1]) + MAC_IE_HDR_LEN) - sizeof(mac_ieee80211_vendor_ie_stru);
    chba_ie = chba_ie + sizeof(mac_ieee80211_vendor_ie_stru);
    /* 标记发送方地址是否为自己的user，用于更新拓扑 */
    hmac_user = mac_vap_get_hmac_user_by_addr(&hmac_vap->st_vap_base_info, sa_addr, WLAN_MAC_ADDR_LEN);
    if (hmac_user != NULL) {
        is_my_user = OAL_TRUE;
    }
    /* 解析连接属性和设备选举属性，更新设备管理信息 */
    hmac_chba_beacon_update_device_mgmt_info(sa_addr, chba_ie, chba_ie_len, is_my_user);

    /* 解析岛主属性 */
    hmac_chba_rx_beacon_island_owner_attr_handler(sa_addr, chba_ie, chba_ie_len);

    /* 如果当前处于NON_SYNC状态，或者trySyncFlag，则进入同步处理流程；其他分别进入Discovery或Work处理流程 */
    if (hmac_chba_get_sync_state() == CHBA_NON_SYNC || hmac_chba_get_sync_request_flag(sync_flags) == TRUE) {
        hmac_chba_rx_bcn_non_sync_state_handler(hmac_vap, sa_addr, domain_bssid, chba_ie, chba_ie_len);
        return;
    }
    /* 同步相关处理 */
    hmac_chba_rx_bcn_sync_handler(hmac_vap, sa_addr, domain_bssid, chba_ie, chba_ie_len);
}

/*
 * 功能描述  : CHBA收到PNF帧上报的处理
 * 日    期  : 2021年02月24日
 */
static void hmac_chba_rx_pnf_proc(hmac_vap_stru *hmac_vap, uint8_t *sa_addr, uint8_t sa_len, uint8_t *domain_bssid,
    uint8_t *payload, uint16_t payload_len)
{
    sync_info_flags *sync_flags = hmac_chba_get_sync_flags();
    uint8_t device_id;
    uint32_t power_save_bitmap;
    int8_t rssi = 0;
    uint8_t linkcnt = 0;
    hmac_user_stru *hmac_user = NULL;
    uint8_t is_my_user = OAL_FALSE;
    hmac_chba_per_device_id_info_stru *device_id_info = hmac_chba_get_device_id_info();

    /* 标记发送方地址是否为自己的user，用于更新拓扑 */
    hmac_user = mac_vap_get_hmac_user_by_addr(&hmac_vap->st_vap_base_info, sa_addr, WLAN_MAC_ADDR_LEN);
    if (hmac_user != NULL) {
        is_my_user = OAL_TRUE;
    }
    /* 根据该帧payload更新设备管理信息 */
    device_id = hmac_chba_update_dev_mgmt_info_by_frame(payload, payload_len, sa_addr, &rssi, &linkcnt, is_my_user);

    /* 解析低功耗属性 */
    power_save_bitmap = hmac_chba_decap_power_save_attr(payload, payload_len);
    /* 保存PNF帧的接收RSSI和低功耗bitmap */
    if (device_id < MAC_CHBA_MAX_DEVICE_NUM) {
        device_id_info[device_id].pnf_rcv_flag = TRUE;
        device_id_info[device_id].pnf_rssi = rssi;
        device_id_info[device_id].ps_bitmap = power_save_bitmap;
    }

    /* 如果当前处于NON_SYNC状态，或者sync_request_flag为TRUE，无需处理PNF */
    if (hmac_chba_get_sync_state() == CHBA_NON_SYNC || hmac_chba_get_sync_request_flag(sync_flags) == TRUE) {
        return;
    }
}

/*
 * 功能描述  : CHBA收到Sync Request Action帧上报的处理
 * 日    期  : 2021年03月22日
 * 作    者  : wifi
 */
static void hmac_chba_rx_sync_request_proc(hmac_vap_stru *hmac_vap, uint8_t *sa_addr, uint8_t mac_addr_len,
    uint8_t *payload, uint16_t payload_len)
{
    sync_info_flags *sync_flags = hmac_chba_get_sync_flags();
    hmac_chba_domain_merge_info *domain_merge = hmac_chba_get_domain_merge_info();
    uint8_t request_type;

    if (payload_len < MAC_CHBA_SYNC_REQ_TYPE_POS) {
        oam_error_log1(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_CHBA,
            "hmac_chba_sync_request_report_proc::rx sync request action frame len[%d] invalid.", payload_len);
        return;
    }
    request_type = *payload;
    oam_warning_log1(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_CHBA,
        "hmac_chba_sync_request_report_proc::rx sync request action frame, subtype is %d.", request_type);

    /* 如果子类型为request，且自己已经同步，则发送beacon帧; 否则回复response帧 */
    if (request_type == MAC_CHBA_REQUEST_ACTION) {
        if (hmac_chba_get_sync_state() > CHBA_NON_SYNC && hmac_chba_get_sync_request_flag(sync_flags) == FALSE) {
            hmac_chba_send_sync_beacon(hmac_vap, hmac_chba_sync_get_domain_bssid(), OAL_MAC_ADDR_LEN);
        } else {
            /* 未同步状态下收到了sync req, 回复sync rsp拒绝对端同步请求并打印error */
            hmac_chba_send_sync_action(sa_addr, hmac_chba_sync_get_domain_bssid(),
                MAC_CHBA_SYNC_REQUEST, MAC_CHBA_RESPONSE_ACTION);
            oam_warning_log0(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_CHBA,
                "{hmac_chba_sync_request_report_proc:rx sync_req in non_sync type!}");
        }
    } else {
        /* 如果子类型为response，且当前处于域合并状态. 说明想要进行合并的对端设备处于未同步状态，则恢复状态，终止域合并 */
        if (hmac_chba_get_domain_merge_flag(domain_merge) == TRUE) {
            oam_error_log0(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_CHBA,
                "{hmac_chba_sync_request_report_proc::the domain try to merge is non-sync!merge need recovery!}");
            hmac_chba_domain_merge_recovery_handler();
        }
    }
}

/*
 * 功能描述  : domain merge action帧的帧格式检查
 * 日    期  : 2021年03月22日
 * 作    者  : wifi
 */
static uint32_t hmac_chba_check_domain_merge_frame(hmac_vap_stru *hmac_vap,
    uint8_t request_type, uint8_t *peer_addr, master_info *another_master)
{
    hmac_chba_domain_merge_info *domain_merge = hmac_chba_get_domain_merge_info();
    hmac_chba_sync_info *sync_info = hmac_chba_get_sync_info();

    if (request_type == MAC_CHBA_REQUEST_ACTION) {
        /* 如果接收到domain merge request, 但已经处于domain merge流程中，不响应该帧 */
        if (hmac_chba_get_domain_merge_flag(domain_merge) == OAL_TRUE) {
            /* 如果对端请求合并的新master与自身正在合并的master为同一设备, 则回复domain finish告知对端结束请求流程 */
            if (oal_compare_mac_addr(another_master->master_addr, sync_info->cur_master_info.master_addr) == 0) {
                hmac_chba_send_sync_action(peer_addr, hmac_chba_sync_get_domain_bssid(),
                    MAC_CHBA_DOMAIN_MERGE, MAC_CHBA_FINISH_ACTION);
            }
            oam_warning_log0(0, OAM_SF_CHBA,
                "hmac_chba_check_domain_merge_frame::already in domain merge processing, return.");
            return OAL_FAIL;
        }

        /* 如果接收到domain_merge_request时，自己已经与新master同步，回复finish */
        if (oal_compare_mac_addr(another_master->master_addr, sync_info->cur_master_info.master_addr) == 0) {
            oam_warning_log3(0, OAM_SF_CHBA,
                "hmac_chba_check_domain_merge_frame::send domain merge finish action, peer %02X:XX:XX:XX:%02X:%02X.",
                peer_addr[MAC_ADDR_0], peer_addr[MAC_ADDR_4], peer_addr[MAC_ADDR_5]);
            hmac_chba_send_sync_action(peer_addr, hmac_chba_sync_get_domain_bssid(),
                MAC_CHBA_DOMAIN_MERGE, MAC_CHBA_FINISH_ACTION);
            return OAL_FAIL;
        }

        /* 如果是OTHER_DEVICE角色接收到domain_merge_request，打印error */
        if (hmac_chba_get_role() == CHBA_OTHER_DEVICE) {
            oam_warning_log0(0, OAM_SF_CHBA,
                "hmac_chba_check_domain_merge_frame::it is not expected to receive domain merge request action.");
            return OAL_FAIL;
        }
    }

    if ((request_type == MAC_CHBA_RESPONSE_ACTION) || (request_type == MAC_CHBA_FINISH_ACTION)) {
        /* 如果接收到domain merge response, 但不处于domain merge流程中，发一个beacon，补救req没及时发出去的问题 */
        if (hmac_chba_get_domain_merge_flag(domain_merge) == FALSE) {
            if (request_type == MAC_CHBA_RESPONSE_ACTION) {
                hmac_chba_send_sync_beacon(hmac_vap, hmac_chba_sync_get_domain_bssid(), OAL_MAC_ADDR_LEN);
            }
            oam_warning_log1(0, OAM_SF_CHBA,
                "hmac_chba_check_domain_merge_frame::type[%d], not in domain merge processing, return.", request_type);
            return OAL_FAIL;
        }

        /* 如果是Master或者原来是master，且收到domain merge response，打印error */
        if ((hmac_chba_get_role() == CHBA_MASTER || domain_merge->his_role == CHBA_MASTER)) {
            oam_warning_log0(0, OAM_SF_CHBA,
                "hmac_chba_check_domain_merge_frame::it is not expected to receive domain merge response action.");
            return OAL_FAIL;
        }
    }

    return OAL_SUCC;
}

/*
 * 功能描述  : 接收到domain merge action帧的处理流程
 * 日    期  : 2021年03月22日
 * 作    者  : wifi
 */
static void hmac_chba_rx_domain_merge_proc(hmac_vap_stru *hmac_vap, uint8_t *sa_addr, uint32_t sa_addr_len,
    uint8_t *payload, uint16_t payload_len)
{
    hmac_chba_domain_merge_info *domain_merge = hmac_chba_get_domain_merge_info();
    master_info another_master = { 0 };
    uint8_t request_type;

    if (payload_len < 1 || (sa_addr_len != WLAN_MAC_ADDR_LEN)) {
        oam_error_log1(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_CHBA,
            "hmac_chba_rx_domain_merge_proc::receive domain merge action frame len[%d] invalid.", payload_len);
        return;
    }
    request_type = *payload;
    oam_warning_log1(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_CHBA,
        "hmac_chba_rx_domain_merge_proc::receive domain merge action frame, subtype is %d.", request_type);

    payload += 1;
    payload_len -= 1;
    hmac_chba_get_master_info_from_frame(payload, payload_len, sa_addr, &another_master);

    if (hmac_chba_check_domain_merge_frame(hmac_vap, request_type, sa_addr, &another_master) == OAL_FAIL) {
        return;
    }

    /* 如果原来是其他设备或者岛主接收到domain_merge_response，发送广播beacon帧，结束domain merge流程 */
    if (request_type == MAC_CHBA_RESPONSE_ACTION) {
        if (domain_merge->his_role == CHBA_OTHER_DEVICE || domain_merge->his_role == CHBA_ISLAND_OWNER) {
            hmac_chba_send_sync_beacon(hmac_vap, hmac_chba_sync_get_domain_bssid(), OAL_MAC_ADDR_LEN);
            hmac_chba_set_sync_domain_merge_flag(domain_merge, OAL_FALSE);
            oam_warning_log2(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_CHBA,
                "hmac_chba_rx_domain_merge_proc::domain merge end, hisRole[%d], curRole[%d].",
                domain_merge->his_role, hmac_chba_get_role());
        }
        return;
    }

    /* 如果是岛主或Master，接收到domain merge request，回复domain merge response，启动domain merge流程 */
    if (request_type == MAC_CHBA_REQUEST_ACTION) {
        hmac_chba_domain_merge_start_handler(&another_master, sa_addr, MAC_CHBA_DOMAIN_MERGE);
        return;
    }

    /* 如果收到domain merge finish，结束domain merge流程 */
    if (request_type == MAC_CHBA_FINISH_ACTION) {
        hmac_chba_set_sync_domain_merge_flag(domain_merge, OAL_FALSE);
        oam_warning_log2(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_CHBA,
            "hmac_chba_domain_merge_report_proc::rx finish action. domain merge end, hisRole[%d], curRole[%d].",
            domain_merge->his_role, hmac_chba_get_role());
        return;
    }
}
/* 处理CHBA action 帧 */
static uint32_t hmac_chba_process_chba_action(hmac_vap_stru *hmac_vap, oal_netbuf_stru *netbuf,
    mac_ieee80211_frame_stru *mac_hdr, uint8_t *payload, uint16_t payload_len)
{
    uint8_t sa_addr[WLAN_MAC_ADDR_LEN];
    uint8_t domain_bssid[WLAN_MAC_ADDR_LEN];

    mac_get_address2((uint8_t *)mac_hdr, sa_addr, WLAN_MAC_ADDR_LEN);
    mac_get_address3((uint8_t *)mac_hdr, domain_bssid, WLAN_MAC_ADDR_LEN);
    /* 打印非pnf帧 */
    if (payload[MAC_CHBA_ACTION_TYPE_LEN] != MAC_CHBA_PNF) {
        oam_warning_log4(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_CHBA,
            "{hmac_chba_process_action:action type[%x], peer addr: %02x:XX:XX:XX:%02x:%02x}",
            payload[MAC_CHBA_ACTION_TYPE_LEN], sa_addr[MAC_ADDR_0], sa_addr[MAC_ADDR_4], sa_addr[MAC_ADDR_5]);
    }
    switch (payload[MAC_CHBA_ACTION_TYPE_LEN]) {
        case MAC_CHBA_PNF:
            hmac_chba_rx_pnf_proc(hmac_vap, sa_addr, WLAN_MAC_ADDR_LEN, domain_bssid,
                payload + MAC_CHBA_ACTION_HDR_LEN, payload_len - MAC_CHBA_ACTION_HDR_LEN);
            break;
        case MAC_CHBA_CHANNEL_SWITCH_NOTIFICATION:
            hmac_chba_rx_chan_switch_notify_action(hmac_vap, sa_addr, WLAN_MAC_ADDR_LEN,
                payload + MAC_CHBA_ACTION_HDR_LEN, payload_len - MAC_CHBA_ACTION_HDR_LEN);
            break;
        case MAC_CHBA_SYNC_REQUEST:
            hmac_chba_rx_sync_request_proc(hmac_vap, sa_addr, WLAN_MAC_ADDR_LEN,
                payload + MAC_CHBA_ACTION_HDR_LEN, payload_len - MAC_CHBA_ACTION_HDR_LEN);
            break;
        case MAC_CHBA_DOMAIN_MERGE:
            hmac_chba_rx_domain_merge_proc(hmac_vap, sa_addr, WLAN_MAC_ADDR_LEN,
                payload + MAC_CHBA_ACTION_HDR_LEN, payload_len - MAC_CHBA_ACTION_HDR_LEN);
            break;
        default:
            break;
    }
    return OAL_SUCC;
}

/*
 * 功能描述  : 接收到Sync Beacon帧的处理
 * 日    期  : 2021年02月26日
 * 作    者  : wifi
 */
static uint32_t hmac_chba_rx_sync_beacon(hmac_vap_stru *hmac_vap, mac_ieee80211_frame_stru *mac_hdr,
    uint8_t *payload, uint16_t payload_len)
{
    hmac_chba_system_params *system_params = hmac_get_chba_system_params();
    uint16_t bcn_int;

    /* 判断是否是CHBA Beacon: 1) beacon interval为512; 2) chba vendor ie */
    /* beacon报到host长度已在device完成校验无需判断 */
    bcn_int = (payload[MAC_TIME_STAMP_LEN + 1] << BIT_OFFSET_8) | payload[MAC_TIME_STAMP_LEN];
    if (bcn_int != system_params->schedule_time_ms) {
        return OAL_FAIL;
    }
    hmac_chba_rx_beacon_proc(hmac_vap, mac_hdr, payload, payload_len);
    return OAL_SUCC;
}


/*
 * 功能描述  : CHBA管理帧接收处理总入口(在该函数的调用处已经判断了chba状态大于INIT)
 * 日    期  : 2021年02月09日
 * 作    者  : wifi
 */
uint32_t hmac_rx_chba_mgmt(hmac_vap_stru *hmac_vap, dmac_wlan_crx_event_stru *rx_mgmt_event,
    oal_netbuf_stru *netbuf)
{
    dmac_rx_ctl_stru *rx_ctrl = NULL;
    mac_rx_ctl_stru *rx_info = NULL;
    mac_ieee80211_frame_stru *mac_hdr = NULL;
    uint8_t *payload = NULL;
    uint16_t mac_hdr_len, payload_len;
    hmac_user_stru *hmac_user = NULL;

    if (oal_any_null_ptr3(hmac_vap, rx_mgmt_event, netbuf)) {
        oam_error_log0(0, OAM_SF_CHBA, "{hmac_rx_chba_mgmt::null pointer.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    rx_ctrl = (dmac_rx_ctl_stru *)oal_netbuf_cb(netbuf);
    rx_info = (mac_rx_ctl_stru *)(&(rx_ctrl->st_rx_info));
    mac_hdr = (mac_ieee80211_frame_stru *)mac_get_rx_cb_mac_header_addr(rx_info);
    mac_hdr_len = rx_info->uc_mac_header_len; /* MAC头长度 */
    payload = (uint8_t *)mac_hdr + mac_hdr_len;
    payload_len = hmac_get_frame_body_len(netbuf);

    /* 判断是否是Beacon帧 */
    if (mac_hdr->st_frame_control.bit_sub_type == WLAN_BEACON) {
        return hmac_chba_rx_sync_beacon(hmac_vap, mac_hdr, payload, payload_len);
    }

    hmac_user = mac_vap_get_hmac_user_by_addr(&(hmac_vap->st_vap_base_info), mac_hdr->auc_address2, WLAN_MAC_ADDR_LEN);
    if (hmac_user != NULL && hmac_user->chba_user.connect_info.connect_role == CHBA_CONN_INITIATOR) {
        /* CHBA 建链发起者STA关联入网流程 */
        hmac_fsm_call_func_chba_conn_initiator(hmac_vap, hmac_user, HMAC_FSM_INPUT_RX_MGMT, (void *)netbuf);
        return OAL_SUCC;
    }

    /* chba negotiation action帧驱动只负责透传, 直接上抛给内核 */
    if (hmac_is_chba_negotiation_action(payload, payload_len) == OAL_TRUE) {
        oam_warning_log0(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_RX,
            "{hmac_chba_process_chba_action:send chba negotiation to host}");
        hmac_rx_mgmt_send_to_host(hmac_vap, netbuf);
        return OAL_SUCC;
    }

    if (hmac_chba_is_chba_action(payload, payload_len)) {
        hmac_chba_process_chba_action(hmac_vap, netbuf, mac_hdr, payload, payload_len);
    } else {
        if (hmac_fsm_call_func_ap(hmac_vap, HMAC_FSM_INPUT_RX_MGMT, (void *)rx_mgmt_event) != OAL_SUCC) {
            oam_warning_log0(hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_CHBA,
                "{hmac_rx_chba_mgmt::hmac_fsm_call_func_ap fail.}");
        }
    }

    return OAL_SUCC;
}
/* ----------------------------------------  以下为更新到Driver ---------------------------------------------- */
/*
 * 功能描述  : 发送更新后的PNF或Beacon帧到Driver，当发生以下变更时需要调用该函数
 *             1) 同步状态或角色发生改变; 2) OwnRp值发生变更; 3) Master信息发生变更; 4) lossCnt发生变更;
 *             5) 建链或删链; 6) 工作信道变更; 7) vap的bitmap发生变更; 8) RRMList发生变更
 * 日    期  : 2021年02月24日
 * 作    者  : wifi
 */
void hmac_chba_save_update_beacon_pnf(uint8_t *bssid)
{
    hmac_chba_sync_info *sync_info = hmac_chba_get_sync_info();
    mac_chba_send_mgmt_frame mgmt_frame_param = { 0 };
    uint8_t *mgmt_buf = NULL;
    uint16_t mgmt_len = 0;
    attr_ctrl_info attr_ctrl = { 0 };
    hmac_chba_vap_stru *chba_vap_info = NULL;
    hmac_vap_stru *hmac_vap = NULL;

    if (sync_info == NULL || bssid == NULL) {
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_chba_save_update_beacon_pnf: input pointer is null.");
        return;
    }
    chba_vap_info = hmac_get_up_chba_vap_info();
    if (chba_vap_info == NULL) {
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_chba_save_update_beacon_pnf::not chba vap or chba not up");
        return;
    }
    hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(chba_vap_info->mac_vap_id);
    if (hmac_vap == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "{hmac_chba_save_update_beacon_pnf:hmac_vap is NULL!}");
        return;
    }
    /* 如果CHBA Vap未启动，则直接返回 */
    if (hmac_chba_get_sync_state() <= CHBA_INIT) {
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_chba_save_update_beacon_pnf::chba Vap is not start, return.");
        return;
    }
    /* 更新最新的OwnRp值 */
    hmac_chba_sync_update_own_rp(hmac_vap);

    mgmt_frame_param.immediate_flag = FALSE;
    oal_set_mac_addr(mgmt_frame_param.bssid, bssid);
    mgmt_buf = mgmt_frame_param.buf;
    /* Master封装Beacon帧，非Master封装PNF帧 */
    if (hmac_chba_get_role() == CHBA_MASTER) {
        mgmt_frame_param.mgmt_frame_type = MAC_CHBA_SYNC_BEACON;
        attr_ctrl.island_owner = TRUE;
        hmac_chba_encap_sync_beacon(chba_vap_info, mgmt_buf, &mgmt_len, &attr_ctrl);
    } else {
        mgmt_frame_param.mgmt_frame_type = MAC_CHBA_PNF;
        hmac_chba_encap_pnf_action(chba_vap_info, mgmt_buf, &mgmt_len);
    }

    mgmt_frame_param.buf_size = mgmt_len;
    /* 保存beacon和PNF帧 */
    hmac_chba_save_mgmt_frame(chba_vap_info, mgmt_frame_param.buf, mgmt_frame_param.buf_size,
        mgmt_frame_param.mgmt_frame_type);
    hmac_chba_update_beacon_pnf(&hmac_vap->st_vap_base_info, mgmt_frame_param.bssid, mgmt_frame_param.mgmt_frame_type);
}
uint16_t hmac_chba_fill_sync_beacon_hdr(mac_vap_stru *mac_vap, uint8_t *frame_hdr, uint8_t *bssid)
{
    hmac_chba_system_params *system_params = hmac_get_chba_system_params();
    uint16_t *beacon_interval = NULL;
    uint16_t offset = 0;
    uint32_t bcn_int;

    mac_hdr_set_frame_control(frame_hdr, WLAN_PROTOCOL_VERSION | WLAN_FC0_TYPE_MGT | WLAN_FC0_SUBTYPE_BEACON);
    oal_set_mac_addr(frame_hdr + WLAN_HDR_ADDR1_OFFSET, BROADCAST_MACADDR); /* 设置广播发送地址 */
    oal_set_mac_addr(frame_hdr + WLAN_HDR_ADDR2_OFFSET, mac_mib_get_StationID(mac_vap)); /* 设置sa */
    oal_set_mac_addr(frame_hdr + WLAN_HDR_ADDR3_OFFSET, bssid); /* 设置BSSID */
    /* beacon帧没有sequence number */
    mac_hdr_set_fragment_number(frame_hdr, 0);
    offset += MAC_80211_FRAME_LEN;
    /* Timestamp由硬件填写 */
    memset_s(frame_hdr + offset, MAC_TIME_STAMP_LEN, 0, MAC_TIME_STAMP_LEN);
    offset += MAC_TIME_STAMP_LEN;
    /* 填写beacon period字段为512 */
    bcn_int = system_params->schedule_time_ms;
    beacon_interval = (uint16_t *)(frame_hdr + offset);
    *beacon_interval = (uint16_t)oal_byteorder_to_le32(bcn_int);
    offset += MAC_BEACON_INTERVAL_LEN;
    /* 填写capinfo字段 */
    mac_set_cap_info_ap(mac_vap, frame_hdr + offset);
    offset += MAC_CAP_INFO_LEN;

    return offset;
}

/*
 * 功能描述  : 发送Beacon帧(立即发送)
 * 日    期  : 2021年03月22日
 * 作    者  : wifi
 */
void hmac_chba_send_sync_beacon(hmac_vap_stru *hmac_vap, uint8_t *bssid, uint8_t addr_len)
{
    oal_netbuf_stru *beacon_frame = NULL;
    uint8_t *frame_hdr = NULL;
    uint8_t *payload = NULL;
    uint16_t total_len = 0;
    uint16_t payload_len = 0;
    uint16_t vendor_ie_len, attr_len;
    uint8_t *vendor_ie_len_pos = NULL;
    attr_ctrl_info attr_ctrl = { 0 };
    mac_vap_stru *mac_vap = &hmac_vap->st_vap_base_info;
    hmac_chba_vap_stru *chba_vap_info = hmac_vap->hmac_chba_vap_info;
    uint32_t ret;

    if (chba_vap_info == NULL) {
        return;
    }

    beacon_frame = oal_mem_netbuf_alloc(OAL_NORMAL_NETBUF, WLAN_MEM_NETBUF_SIZE2, OAL_NETBUF_PRIORITY_MID);
    if (beacon_frame == NULL) {
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_chba_send_sync_beacon::beacon_frame null.");
        return;
    }
    oal_mem_netbuf_trace(beacon_frame, OAL_TRUE);
    memset_s(oal_netbuf_cb(beacon_frame), oal_netbuf_cb_size(), 0, oal_netbuf_cb_size());
    /* 将mac header清零 */
    memset_s((uint8_t *)oal_netbuf_header(beacon_frame), MAC_80211_FRAME_LEN, 0, MAC_80211_FRAME_LEN);
    /* 封装Beacon帧 */
    frame_hdr = (uint8_t *)oal_netbuf_header(beacon_frame);
    /* 填写mac头信息 */
    total_len += hmac_chba_fill_sync_beacon_hdr(mac_vap, frame_hdr, bssid);
    payload = frame_hdr + total_len;
    vendor_ie_len_pos = frame_hdr + total_len + 1;

    hmac_chba_encap_sync_beacon(chba_vap_info, payload, &payload_len, &attr_ctrl);
    total_len += payload_len;
    /* 获取当前的vendor IE Len */
    vendor_ie_len = payload[MAC_CHBA_ATTR_ID_LEN];
    /* 封装coex info属性(必选) */
    mac_set_chba_coex_info_attr(frame_hdr + total_len, &attr_len, chba_vap_info);
    total_len += attr_len;
    vendor_ie_len += attr_len;
    *vendor_ie_len_pos = vendor_ie_len;
    oal_netbuf_put(beacon_frame, total_len);
    hmac_chba_mgmt_cb_partial_init(mac_vap, BROADCAST_MACADDR, beacon_frame, total_len, OAL_TRUE);

    /* 发送单播的beacon帧 */
    oam_warning_log3(0, OAM_SF_CHBA, "hmac_chba_send_sync_beacon::send sync beacon, bssid %02X:XX:XX:XX:%02X:%02X.",
        bssid[MAC_ADDR_0], bssid[MAC_ADDR_4], bssid[MAC_ADDR_5]);
    ret = hmac_tx_mgmt_send_event(mac_vap, beacon_frame, total_len);
    if (ret != OAL_SUCC) {
        oal_netbuf_free(beacon_frame);
        oam_warning_log1(0, OAM_SF_CHBA, "hmac_chba_send_sync_beacon::hmac_tx_mgmt_send_event failed[%d].", ret);
        return;
    }
}

/*
 * 功能描述  : 发送Sync Request帧(立即发送)
 * 日    期  : 2021年03月22日
 * 作    者  : wifi
 */
void hmac_chba_send_sync_action(uint8_t *sa_addr, uint8_t *bssid, uint8_t action_type, uint8_t request_type)
{
    oal_netbuf_stru *sync_action_frame = NULL;
    uint8_t *frame_hdr = NULL;
    uint8_t *payload = NULL;
    uint16_t mgmt_len = 0;
    uint16_t payload_len = 0;
    uint32_t ret;
    hmac_chba_vap_stru *chba_vap_info = hmac_get_chba_vap();
    hmac_vap_stru *hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(chba_vap_info->mac_vap_id);
    mac_vap_stru *mac_vap = NULL;

    if (sa_addr == NULL || hmac_vap == NULL) {
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_chba_send_sync_action: input pointer is null.");
        return;
    }
    mac_vap = &hmac_vap->st_vap_base_info;
    sync_action_frame = oal_mem_netbuf_alloc(OAL_NORMAL_NETBUF, WLAN_MEM_NETBUF_SIZE2, OAL_NETBUF_PRIORITY_MID);
    if (sync_action_frame == NULL) {
        oam_error_log0(mac_vap->uc_vap_id, OAM_SF_CHBA, "hmac_chba_send_sync_action::alloc fail.");
        return;
    }
    oal_mem_netbuf_trace(sync_action_frame, OAL_TRUE);
    memset_s(oal_netbuf_cb(sync_action_frame), oal_netbuf_cb_size(), 0, oal_netbuf_cb_size());
    /* 封装Sync Request Action */
    frame_hdr = (uint8_t *)oal_netbuf_header(sync_action_frame);
    /* 将mac header清零 */
    memset_s(frame_hdr, MAC_80211_FRAME_LEN, 0, MAC_80211_FRAME_LEN);
    /* 填写mac头信息 */
    mac_hdr_set_frame_control(frame_hdr, WLAN_PROTOCOL_VERSION | WLAN_FC0_TYPE_MGT | WLAN_FC0_SUBTYPE_ACTION);
    oal_set_mac_addr(frame_hdr + WLAN_HDR_ADDR1_OFFSET, sa_addr);
    oal_set_mac_addr(frame_hdr + WLAN_HDR_ADDR2_OFFSET, mac_mib_get_StationID(mac_vap));
    mac_set_domain_bssid(frame_hdr + WLAN_HDR_ADDR3_OFFSET, mac_vap, chba_vap_info);
    mgmt_len += MAC_80211_FRAME_LEN;
    payload = frame_hdr + mgmt_len;
    /* 填写Action 头 */
    mac_set_chba_action_hdr(payload, action_type);
    payload_len += MAC_CHBA_ACTION_HDR_LEN;
    /* 填写type */
    payload[payload_len] = request_type;
    payload_len++;
    /* 封装主设备选举字段 */
    hmac_chba_set_master_election_attr(payload + payload_len);
    payload_len += MAC_CHBA_MASTER_ELECTION_ATTR_LEN;

    mgmt_len += payload_len;
    oal_netbuf_put(sync_action_frame, mgmt_len);
    hmac_chba_mgmt_cb_partial_init(mac_vap, sa_addr, sync_action_frame, mgmt_len, OAL_FALSE);

    /* 发送Domain Merge Action帧 */
    ret = hmac_tx_mgmt_send_event(mac_vap, sync_action_frame, mgmt_len);
    if (ret != OAL_SUCC) {
        oal_netbuf_free(sync_action_frame);
        oam_warning_log1(mac_vap->uc_vap_id, OAM_SF_CHBA,
            "hmac_chba_send_sync_action::hmac_tx_mgmt_send_event failed[%d].", ret);
        return;
    }
}

/*
 * 功能描述  : 解析beacon/PNF帧的power save attr
 * 日    期  : 2021年02月24日
 */
uint32_t hmac_chba_decap_power_save_attr(uint8_t *payload, int32_t len)
{
    uint8_t *data = NULL;
    uint32_t *bitmap = NULL;
    uint32_t power_save_bitmap;
    if (payload == NULL) {
        return CHBA_PS_ALL_AWAKE_BITMAP;
    }

    /* 解析Power Save Attribute */
    /************************ Power Save Attribute *************************************/
    /* ------------------------------------------------------------------------------ */
    /* | CHBA ATTR ID | LEN | Flag | PS Bitmap |                                            */
    /* ------------------------------------------------------------------------------ */
    /* |        1      |  1  |   1  |     4     |                                            */
    /* ------------------------------------------------------------------------------ */
    data = hmac_find_chba_attr(MAC_CHBA_ATTR_POWER_SAVE_BITMAP, payload, len);
    if (data == NULL) {
        oam_warning_log0(0, OAM_SF_CHBA, "hmac_chba_decap_power_save_attr::can't find ps attr.");
        return CHBA_PS_ALL_AWAKE_BITMAP;
    }
    if (MAC_CHBA_ATTR_HDR_LEN + data[MAC_CHBA_ATTR_ID_LEN] < MAC_CHBA_POWER_SAVE_BITMAP_PS_BITMAP + sizeof(uint32_t)) {
        oam_error_log1(0, OAM_SF_CHBA, "hmac_chba_decap_power_save_attr::ps attr len[%d] invalid.",
            data[MAC_CHBA_ATTR_ID_LEN]);
        return CHBA_PS_ALL_AWAKE_BITMAP;
    }

    data += MAC_CHBA_ATTR_HDR_LEN;
    data++;
    bitmap = (uint32_t *)data;
    power_save_bitmap = *bitmap;

    return power_save_bitmap;
}

/* 功能描述: chba管理帧cb字段初始化 */
void hmac_chba_mgmt_cb_partial_init(mac_vap_stru *mac_vap, uint8_t *peer_addr, oal_netbuf_stru *mgmt_buf,
    uint16_t mgmt_len, oal_bool_enum_uint8 is_mcast)
{
    mac_tx_ctl_stru *tx_ctl = (mac_tx_ctl_stru *)oal_netbuf_cb(mgmt_buf);
    memset_s(tx_ctl, oal_netbuf_cb_size(), 0, oal_netbuf_cb_size());

    mac_get_cb_wlan_frame_type(tx_ctl) = WLAN_MANAGEMENT;
    mac_get_cb_wme_ac_type(tx_ctl) = WLAN_WME_AC_MGMT;
    mac_get_cb_mpdu_len(tx_ctl) = mgmt_len;
    mac_get_cb_mpdu_num(tx_ctl) = 1;
    mac_get_cb_tx_vap_index(tx_ctl) = mac_vap->uc_vap_id;
    mac_get_cb_is_mcast(tx_ctl) = is_mcast;
    if (is_mcast == OAL_TRUE) { /* 广播管理帧填写invalid user id */
        mac_get_cb_tx_user_idx(tx_ctl) = g_wlan_spec_cfg->invalid_user_id;
    } else {
        mac_vap_set_cb_tx_user_idx(mac_vap, tx_ctl, peer_addr);
    }
}
#endif /* end of this file */
