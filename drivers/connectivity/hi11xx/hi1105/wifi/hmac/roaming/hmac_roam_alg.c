/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * 功能说明 : 漫游模块算法实现
 * 作    者 :
 * 创建日期 : 2015年3月18日
 */

#include "oam_ext_if.h"
#include "mac_ie.h"
#include "mac_device.h"
#include "mac_resource.h"

#include "hmac_dfx.h"
#include "hmac_fsm.h"
#include "hmac_sme_sta.h"
#include "hmac_resource.h"
#include "hmac_device.h"
#include "hmac_scan.h"
#include "hmac_roam_main.h"
#include "hmac_roam_connect.h"
#include "hmac_roam_alg.h"
#include "hmac_mgmt_sta.h"
#include "hmac_blacklist.h"
#include "mac_mib.h"
#include "hmac_chan_mgmt.h"
#ifdef _PRE_WLAN_FEATURE_FTM
#include "mac_ftm.h"
#endif
#ifdef _PRE_WLAN_CHBA_MGMT
#include "hmac_chba_coex.h"
#endif
#ifdef _PRE_WLAN_FEATURE_PWL
#include "hmac_roam_pwl.h"
#endif

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_ROAM_ALG_C

hmac_roam_rssi_capacity_stru g_st_rssi_table_11a_ofdm[ROAM_RSSI_LEVEL] = {
    { -75, 29300 },
    { -82, 17300 },
    { -90, 5400 }
};
hmac_roam_rssi_capacity_stru g_st_rssi_table_11b[ROAM_RSSI_LEVEL] = {
    { -88, 8100 },
    { -92, 4900 },
    { -94, 900 }

};
hmac_roam_rssi_capacity_stru g_st_rssi_table_11g_ofdm[ROAM_RSSI_LEVEL] = {
    { -75, 29300 },
    { -82, 17300 },
    { -90, 5400 }
};
hmac_roam_rssi_capacity_stru g_st_rssi_table_ht20_ofdm[ROAM_RSSI_LEVEL] = {
    { -72, 58800 },
    { -80, 35300 },
    { -90, 5800 }
};
hmac_roam_rssi_capacity_stru g_st_rssi_table_ht40_ofdm[ROAM_RSSI_LEVEL] = {
    { -75, 128100 },
    { -77, 70500 },
    { -87, 11600 }
};
hmac_roam_rssi_capacity_stru g_st_rssi_table_vht80_ofdm[ROAM_RSSI_LEVEL] = {
    { -72, 256200 },
    { -74, 141000 },
    { -84, 23200 }
};

void hmac_roam_alg_init(hmac_roam_info_stru *roam_info, int8_t c_current_rssi)
{
    hmac_roam_alg_stru *roam_alg = NULL;

    if (roam_info == NULL) {
        oam_error_log0(0, OAM_SF_ROAM, "{hmac_roam_alg_init::param null.}");
        return;
    }
    oam_warning_log1(0, OAM_SF_ROAM, "{hmac_roam_alg_init c_current_rssi = %d.}", c_current_rssi);
    roam_alg = &(roam_info->st_alg);
    if (c_current_rssi == ROAM_RSSI_LINKLOSS_TYPE) {
        roam_info->st_static.trigger_linkloss_cnt++;
    } else {
        roam_info->st_static.trigger_rssi_cnt++;
    }

    roam_alg->max_capacity = 0;
    roam_alg->pst_max_capacity_bss = NULL;
    roam_alg->c_current_rssi = c_current_rssi;
    roam_alg->c_max_rssi = 0;
    roam_alg->uc_another_bss_scaned = 0;
    /* 首次关联时初始化 roam_alg->uc_invalid_scan_cnt   = 0x0; */
    roam_alg->pst_max_rssi_bss = NULL;
#ifdef _PRE_WLAN_FEATURE_FTM
    if (g_wlan_spec_cfg->feature_ftm_is_open) {
        if (mac_is_ftm_enable(&roam_info->pst_hmac_vap->st_vap_base_info)) {
            roam_info->st_config.uc_scan_orthogonal = ROAM_SCAN_CHANNEL_ORG_1;
        }
    }
#endif

    return;
}

/*
 * 功能描述  : 为了解决圈复杂度，初始化hmac_roam_alg_init
 * 1.日    期  : 2019年8月15日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void hmac_roam_alg_init_rssi(hmac_vap_stru *hmac_vap, hmac_roam_info_stru *roam_info)
{
    int8_t trigger_rssi = 0;
    if (oal_unlikely(hmac_vap == NULL)) {
        return;
    }

    if (oal_unlikely(roam_info == NULL)) {
        return;
    }

#ifdef _PRE_WLAN_FEATURE_11V_ENABLE
    if (roam_info->en_roam_trigger == ROAM_TRIGGER_11V) {
        trigger_rssi = roam_info->st_bsst_rsp_info.c_rssi;
    } else
#endif
#ifdef _PRE_WLAN_FEATURE_11K
    /* 11k扫描失败重新触发漫游，以上一次触发的rssi为准，避免rssi增益计算错误导致选网错误 */
    if (roam_info->en_roam_trigger == ROAM_TRIGGER_11K_FAIL_RESTART) {
        trigger_rssi = roam_info->st_alg.c_current_rssi;
    } else
#endif
    if (roam_info->en_roam_trigger == ROAM_TRIGGER_HOME_NETWORK) {
        trigger_rssi = hmac_vap->station_info.signal;
    } else {
        trigger_rssi = ROAM_RSSI_CMD_TYPE;
    }
    hmac_roam_alg_init(roam_info, trigger_rssi);
    return;
}

/*
 * 功能描述  : 调整5G AP rssi权重
 * 1.日    期  : 2018年9月22日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC int8_t hmac_roam_alg_adjust_5g_rssi_weight(int8_t orginal_rssi)
{
    int8_t current_rssi = orginal_rssi;

    if (current_rssi >= ROAM_RSSI_NE65_DB) {
        current_rssi += ROAM_RSSI_DIFF_20_DB;
    } else if (current_rssi < ROAM_RSSI_NE65_DB && current_rssi >= ROAM_RSSI_NE72_DB) {
        current_rssi += ROAM_RSSI_DIFF_10_DB;
    } else {
        current_rssi += ROAM_RSSI_DIFF_4_DB;
    }

    return current_rssi;
}

/*
 * 功能描述  : 调整支持wifi6 AP rssi权重
 * 1.日    期  : 2020年6月8日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC int8_t hmac_roam_alg_adjust_ax_rssi_weight(int8_t orginal_rssi)
{
    int8_t current_rssi = orginal_rssi;

    if (current_rssi >= ROAM_RSSI_NE65_DB) {
        current_rssi += ROAM_RSSI_DIFF_6_DB;
    } else if (current_rssi < ROAM_RSSI_NE65_DB && current_rssi > ROAM_RSSI_NE75_DB) {
        current_rssi += ROAM_RSSI_DIFF_2_DB;
    }

    return current_rssi;
}

OAL_STATIC int8_t hmac_roam_alg_adjust_sap_rssi_weight(int8_t orginal_rssi)
{
    int8_t current_rssi = orginal_rssi;

    if (current_rssi >= ROAM_RSSI_NE65_DB) {
        current_rssi += ROAM_RSSI_DIFF_8_DB;
    } else if (current_rssi < ROAM_RSSI_NE65_DB && current_rssi >= ROAM_RSSI_NE72_DB) {
        current_rssi += ROAM_RSSI_DIFF_4_DB;
    }

    return current_rssi;
}

/*
 * 功能描述  : 非漫游冲突场景下，清除统计量
 */
void hmac_roam_alg_clear_repeat_roam_stat(hmac_roam_info_stru *roam_info)
{
    roam_info->roam_conflict_info.pre_roam_trigger_type = ROAM_TRIGGER_BUTT;
    roam_info->roam_conflict_info.repeat_11v_roam_cnt = 0;
    memset_s(roam_info->roam_conflict_info.reject_bssid, OAL_MAC_ADDR_LEN, 0, OAL_MAC_ADDR_LEN);
    memset_s(roam_info->roam_conflict_info.pre_llv_roam_2g_bssid, OAL_MAC_ADDR_LEN, 0, OAL_MAC_ADDR_LEN);
}

/*
 * 功能描述  : 比较rssi增益
 * 1.日    期  : 2015年7月8日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC int16_t hmac_roam_alg_compare_rssi_increase(hmac_roam_info_stru *roam_info,
    mac_bss_dscr_stru *bss_dscr, int8_t c_target_weight_rssi)
{
    hmac_vap_stru *hmac_vap = NULL;
    mac_vap_stru *mac_vap = NULL;
    int16_t s_current_rssi, s_target_rssi;
    uint8_t delta_rssi;

    hmac_vap = roam_info->pst_hmac_vap;
    mac_vap = &(hmac_vap->st_vap_base_info);
    s_target_rssi = bss_dscr->c_rssi;

    delta_rssi = (bss_dscr->st_channel.en_band == WLAN_BAND_5G) ? roam_info->st_config.uc_delta_rssi_5g :
        roam_info->st_config.uc_delta_rssi_2g;

    /* current AP is 2G, target AP is 5G */
    if ((bss_dscr->st_channel.en_band == WLAN_BAND_5G) && (mac_vap->st_channel.en_band == WLAN_BAND_2G)) {
        s_target_rssi = c_target_weight_rssi;
    }

    s_current_rssi = roam_info->st_alg.c_current_rssi;
    oam_warning_log3(0, OAM_SF_ROAM, "{hmac_roam_alg_compare_rssi_increase::cur_rssi[%d], target[%d], delta[%d]!}",
        s_current_rssi, s_target_rssi, delta_rssi);
    /* current AP is 5G, target AP is 2G */
    if ((mac_vap->st_channel.en_band == WLAN_BAND_5G) && (bss_dscr->st_channel.en_band == WLAN_BAND_2G)) {
        s_current_rssi = (int16_t)hmac_roam_alg_adjust_5g_rssi_weight((int8_t)s_current_rssi);
        oam_warning_log1(0, OAM_SF_ROAM, "{roam_alg_rssi_incr::cur 5g target 2g, adjust cur_rssi:%d}", s_current_rssi);
    }

#ifdef _PRE_WLAN_FEATURE_11V_ENABLE
    if (roam_info->en_roam_trigger == ROAM_TRIGGER_11V &&
        (bss_dscr->c_rssi >= ROAM_RSSI_NE70_DB)) {
        return 1;
    }
#endif

    if (roam_info->en_roam_trigger == ROAM_TRIGGER_BSSID) {
        return 1;
    }

    if (delta_rssi < ROAM_RSSI_DIFF_4_DB) {
        delta_rssi = ROAM_RSSI_DIFF_4_DB;
    }

    if (s_current_rssi >= ROAM_RSSI_NE70_DB) {
        return (s_target_rssi - s_current_rssi - (int16_t)delta_rssi);
    }

    if (delta_rssi >= ROAM_RSSI_DIFF_6_DB) {
        /* 步进2DB至4DB */
        delta_rssi -= 2;
    }

    if (s_current_rssi >= ROAM_RSSI_NE75_DB) {
        return (s_target_rssi - s_current_rssi - (int16_t)delta_rssi);
    }

    if (delta_rssi >= ROAM_RSSI_DIFF_6_DB) {
        /* 步进2DB至4DB */
        delta_rssi -= 2;
    }

    if (s_current_rssi >= ROAM_RSSI_NE80_DB) {
        return (s_target_rssi - s_current_rssi - (int16_t)delta_rssi);
    }

    return (s_target_rssi - s_current_rssi - ROAM_RSSI_DIFF_4_DB);
}

/*
 * 功能描述  : 将bssid添加到列表中
 * 1.日    期  : 2015年7月8日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC uint32_t hmac_roam_alg_add_bsslist(hmac_roam_bss_list_stru *roam_bss_list,
                                              uint8_t *puc_bssid, roam_blacklist_type_enum list_type)
{
    hmac_roam_bss_info_stru *cur_bss = NULL;
    hmac_roam_bss_info_stru *oldest_bss = NULL;
    hmac_roam_bss_info_stru *zero_bss = NULL;
    uint8_t auc_mac_zero[WLAN_MAC_ADDR_LEN] = { 0 };
    uint32_t current_index, now, timeout;

    now = (uint32_t)oal_time_get_stamp_ms();

    for (current_index = 0; current_index < ROAM_LIST_MAX; current_index++) {
        cur_bss = &roam_bss_list->ast_bss[current_index];
        timeout = (uint32_t)cur_bss->timeout;
        if (oal_compare_mac_addr(cur_bss->auc_bssid, puc_bssid) == 0) {
            /* 优先查找已存在的记录，如果名单超时更新时间戳，否则更新count */
            if (oal_time_get_runtime(cur_bss->time_stamp, now) > timeout) {
                cur_bss->time_stamp = now;
                cur_bss->us_count = 1;
                return OAL_SUCC;
            }
            cur_bss->us_count++;
            if (cur_bss->us_count == cur_bss->us_count_limit) {
                cur_bss->time_stamp = now;
            }
            return OAL_SUCC;
        }

        /* 记录第一个空记录 */
        if (zero_bss != NULL) {
            continue;
        }

        if (oal_compare_mac_addr(cur_bss->auc_bssid, auc_mac_zero) == 0) {
            zero_bss = cur_bss;
            continue;
        }

        /* 记录一个非空最老记录 */
        if (oldest_bss == NULL) {
            oldest_bss = cur_bss;
        } else if (oal_time_get_runtime(cur_bss->time_stamp, now) >
            oal_time_get_runtime(oldest_bss->time_stamp, now)) {
            oldest_bss = cur_bss;
        }
    }

    if (zero_bss == NULL) {
        zero_bss = oldest_bss;
    }

    if (zero_bss != NULL) {
        oal_set_mac_addr(zero_bss->auc_bssid, puc_bssid);
        zero_bss->time_stamp = now;
        zero_bss->us_count = 1;
        return OAL_SUCC;
    }
    return OAL_FAIL;
}

/*
 * 功能描述  : 检查列表中是否存在该bssid
 * 1.日    期  : 2015年7月8日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC oal_bool_enum_uint8 hmac_roam_alg_find_in_bsslist(hmac_roam_bss_list_stru *roam_bss_list,
                                                             uint8_t *puc_bssid)
{
    hmac_roam_bss_info_stru *cur_bss = NULL;
    uint32_t current_index;
    uint32_t now;
    uint32_t timeout;
    uint32_t delta_time;
    uint16_t us_count_limit;

    now = (uint32_t)oal_time_get_stamp_ms();

    for (current_index = 0; current_index < ROAM_LIST_MAX; current_index++) {
        cur_bss = &roam_bss_list->ast_bss[current_index];
        timeout = cur_bss->timeout;
        us_count_limit = cur_bss->us_count_limit;

        if (oal_compare_mac_addr(cur_bss->auc_bssid, puc_bssid) == 0) {
            /* 如果在超时时间内出现count_limit次以上记录 */
            delta_time = oal_time_get_runtime(cur_bss->time_stamp, now);
            if ((delta_time <= timeout) &&
                (cur_bss->us_count >= us_count_limit)) {
                return OAL_TRUE;
            }
            return OAL_FALSE;
        }
    }

    return OAL_FALSE;
}

/*
 * 功能描述  : 将bssid添加到黑名单列表中
 * 1.日    期  : 2015年7月8日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_roam_alg_add_blacklist(hmac_roam_info_stru *roam_info,
                                     uint8_t *puc_bssid,
                                     roam_blacklist_type_enum list_type)
{
    uint32_t ret;
    if (oal_any_null_ptr2(roam_info, puc_bssid)) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    ret = hmac_roam_alg_add_bsslist(&roam_info->st_alg.st_blacklist, puc_bssid, list_type);
    if (ret != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_ROAM,
                       "{hmac_roam_alg_add_blacklist::hmac_roam_alg_add_list failed[%d].}",
                       ret);
        return ret;
    }

    return OAL_SUCC;
}

/*
 * 功能描述  : 检查黑名单列表中是否存在该bssid
 * 1.日    期  : 2015年7月8日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
oal_bool_enum_uint8 hmac_roam_alg_find_in_blacklist(hmac_roam_info_stru *roam_info, uint8_t *puc_bssid)
{
    if (oal_any_null_ptr2(roam_info, puc_bssid)) {
        return OAL_FALSE;
    }

    return hmac_roam_alg_find_in_bsslist(&roam_info->st_alg.st_blacklist, puc_bssid);
}

/*
 * 功能描述  : 将bssid添加到历史优选AP列表中
 * 1.日    期  : 2015年7月8日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_roam_alg_add_history(hmac_roam_info_stru *roam_info, uint8_t *puc_bssid)
{
    uint32_t ret;

    if (oal_any_null_ptr2(roam_info, puc_bssid)) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    ret = hmac_roam_alg_add_bsslist(&roam_info->st_alg.st_history,
                                    puc_bssid, ROAM_BLACKLIST_TYPE_NORMAL_AP);
    if (ret != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_ROAM,
                       "{hmac_roam_alg_add_history::hmac_roam_alg_add_list failed[%d].}", ret);
        return ret;
    }

    return OAL_SUCC;
}

/*
 * 功能描述  : 检查历史优选列表中是否存在该bssid
 * 1.日    期  : 2015年7月8日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
oal_bool_enum_uint8 hmac_roam_alg_find_in_history(hmac_roam_info_stru *roam_info, uint8_t *puc_bssid)
{
    if (oal_any_null_ptr2(roam_info, puc_bssid)) {
        return OAL_FALSE;
    }

    return hmac_roam_alg_find_in_bsslist(&roam_info->st_alg.st_history, puc_bssid);
}

#if defined(_PRE_WLAN_FEATURE_11V_ENABLE)
/*
 * 功能描述  : neighbor report取交集信道
 * 1.日    期  : 2019年5月18日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 * 2.日    期  : 2020年12月26日
 *   作    者  : wifi
 *   修改内容  : 将新加入的信道插入有序表中
 */
void hmac_roam_neighbor_report_add_chan(mac_scan_req_stru *scan_params,
    uint8_t channum, wlan_channel_band_enum_uint8 en_band, uint8_t channel_idx)
{
    uint8_t   loop;
    int ret = 0;
    if (scan_params == NULL) {
        oam_warning_log0(0, OAM_SF_ROAM, "{hmac_roam_neighbor_report_add_chan::scan_params is NULL}");
        return;
    }

    if (scan_params->uc_channel_nums >= ROAM_NEIGHBOR_RPT_LIST_CHN_MAX_NUM) {
        oam_warning_log0(0, OAM_SF_ROAM, "{hmac_roam_neighbor_report_add_chan::exceed max neighbor list}");
        return;
    }

    /* 找到第一个比channum大的scan_params->ast_channel_list索引 */
    for (loop = 0; loop < scan_params->uc_channel_nums; loop++) {
        if (scan_params->ast_channel_list[loop].uc_chan_number == channum) {
            return;
        } else if (scan_params->ast_channel_list[loop].uc_chan_number > channum) {
            ret = memmove_s(&(scan_params->ast_channel_list[loop + 1]),
                sizeof(mac_channel_stru) * (scan_params->uc_channel_nums - loop),
                &(scan_params->ast_channel_list[loop]),
                sizeof(mac_channel_stru) * (scan_params->uc_channel_nums - loop));
            if (ret != EOK) {
                oam_error_log1(0, OAM_SF_ROAM, "{hmac_roam_neighbor_report_add_chan::memmove_s fail[%d]}", ret);
            }
            break;
        }
    }

    scan_params->ast_channel_list[loop].uc_chan_number  = channum;
    scan_params->ast_channel_list[loop].en_band         = en_band;
    scan_params->ast_channel_list[loop].uc_chan_idx     = channel_idx;
    scan_params->uc_channel_nums++;
}

/*
 * 功能描述  : neighbor report 增加目标AP
 * 1.日    期  : 2019年4月3日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void hmac_roam_neighbor_report_add_bssid(hmac_roam_info_stru *roam_info, uint8_t *puc_bssid)
{
    uint8_t *puc_idex = NULL;

    if (roam_info == NULL || puc_bssid == NULL) {
        oam_warning_log0(0, OAM_SF_ROAM, "{hmac_roam_neighbor_report_add_bssid::NULL pointer}");
        return;
    }

    puc_idex = &roam_info->uc_neighbor_rpt_bssid_num;
    if (*puc_idex >= ROAM_NEIGHBOR_RPT_LIST_BSSID_MAX_NUM) {
        return;
    }

    if (memcpy_s(roam_info->auc_neighbor_rpt_bssid[*puc_idex], WLAN_MAC_ADDR_LEN,
                 puc_bssid, WLAN_MAC_ADDR_LEN) != EOK) {
        oam_error_log0(0, OAM_SF_ANY, "hmac_roam_neighbor_report_add_bssid:memcopy fail!");
        return;
    }
    (*puc_idex)++;
    return;
}
#endif

/*
 * 功能描述  : 记录家庭网络的BSS info
 * 1.日    期   : 2019年7月11日
 *   作    者   : wifi
 *   修改内容   : 新生成函数
 */
OAL_STATIC void hmac_roam_alg_record_bss_info(hmac_roam_record_stru *roam_record,
                                              mac_bss_dscr_stru *bss_dscr)
{
    mac_channel_stru *channel = NULL;

    if (oal_any_null_ptr2(roam_record, bss_dscr)) {
        oam_error_log0(0, OAM_SF_ROAM, "{hmac_roam_alg_record_bss_info::param null.}");
        return;
    }

    if (roam_record->uc_bssid_num >= MAX_RECORD_BSSID_NUM) {
        return;
    }

    /* update channel info if bssid is already recorded */
    if (roam_record->uc_bssid_num == 1 &&
        oal_memcmp(roam_record->auc_bssid[0], bss_dscr->auc_bssid, WLAN_MAC_ADDR_LEN) == 0) {
        if (bss_dscr->st_channel.uc_chan_number != roam_record->st_channel[0].uc_chan_number) {
            roam_record->st_channel[0] = bss_dscr->st_channel;
        }
        return;
    }

    memcpy_s(roam_record->auc_bssid[roam_record->uc_bssid_num], WLAN_MAC_ADDR_LEN,
             bss_dscr->auc_bssid, WLAN_MAC_ADDR_LEN);

    channel = &(roam_record->st_channel[roam_record->uc_bssid_num]);
    memcpy_s(channel, sizeof(mac_channel_stru), &(bss_dscr->st_channel), sizeof(mac_channel_stru));

    roam_record->uc_bssid_num++;

    return;
}

OAL_STATIC void hmac_roam_record_chan_info(hmac_roam_record_chan_stru *chan_info, mac_bss_dscr_stru *bss_dscr)
{
    int8_t chan_idx;
    int8_t chan_next;
    uint8_t stored = 0;

    for (chan_idx = 0; chan_idx < MAX_RECORD_CHAN_NUM; chan_idx++) {
        if (bss_dscr->st_channel.uc_chan_number == chan_info->channel[chan_idx].uc_chan_number) {
            stored = 1;
            break;
        } else if (bss_dscr->st_channel.uc_chan_number < chan_info->channel[chan_idx].uc_chan_number) {
            for (chan_next = MAX_RECORD_CHAN_NUM - 2; chan_next >= chan_idx; chan_next--) { /* 扫描信道信息减2 */
                chan_info->channel[chan_next + 1] = chan_info->channel[chan_next]; // 从小到大排序，插入排序
            }
            memset_s(&(chan_info->channel[chan_idx]), sizeof(mac_channel_stru), 0, sizeof(mac_channel_stru));
        }

        if (chan_info->channel[chan_idx].uc_chan_number == 0) {
            chan_info->channel[chan_idx] = bss_dscr->st_channel;
            oam_warning_log4(0, OAM_SF_ROAM, "{hmac_roam_record_chan_info::idx=%d, ChanNum=%d mac:%02x::%02x}",
                chan_info->chan_num, chan_info->channel[chan_idx].uc_chan_number,
                bss_dscr->auc_bssid[BYTE_OFFSET_4], bss_dscr->auc_bssid[BYTE_OFFSET_5]);
            chan_info->chan_num++;
            stored = 1;
            break;
        }
    }

    if (stored == 0 && chan_info->chan_num == MAX_RECORD_CHAN_NUM) {
        chan_info->chan_num++; // 标记超过3 个信道
    }
}

OAL_STATIC void hmac_roam_alg_record_bss(hmac_roam_info_stru *roam_info, mac_bss_dscr_stru *bss_dscr)
{
    hmac_roam_alg_stru *roam_alg = &(roam_info->st_alg);

    if (bss_dscr->st_channel.en_band == WLAN_BAND_5G) {
        hmac_roam_record_chan_info(&(roam_info->scan_info.chan_5g), bss_dscr);
        hmac_roam_alg_record_bss_info(&(roam_alg->st_home_network.st_5g_bssid), bss_dscr);
    } else if (bss_dscr->st_channel.en_band == WLAN_BAND_2G) {
        hmac_roam_record_chan_info(&(roam_info->scan_info.chan_2g), bss_dscr);
        hmac_roam_alg_record_bss_info(&(roam_alg->st_home_network.st_2g_bssid), bss_dscr);
    } else {
        oam_error_log1(0, OAM_SF_ROAM, "{hmac_roam_alg_bss_in_ess::en_band[%d].}", bss_dscr->st_channel.en_band);
    }
}

uint32_t hmac_roam_alg_bss_in_ess(hmac_roam_info_stru *roam_info, mac_bss_dscr_stru *bss_dscr)
{
    hmac_vap_stru *hmac_vap = NULL;
    mac_vap_stru *mac_vap = NULL;
    hmac_roam_alg_stru *roam_alg = NULL;
    mac_cfg_ssid_param_stru cfg_ssid;
    uint8_t stru_len;
    uint32_t roam_timeout;

    if (oal_any_null_ptr2(roam_info, bss_dscr)) {
        oam_error_log0(0, OAM_SF_ROAM, "{hmac_roam_alg_bss_in_ess::param null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    hmac_vap = roam_info->pst_hmac_vap;
    if (hmac_vap == NULL) {
        return OAL_ERR_CODE_ROAM_INVALID_VAP;
    }

    mac_vap = &(hmac_vap->st_vap_base_info);
    mac_mib_get_ssid (mac_vap, &stru_len, (uint8_t *)(&cfg_ssid));

    if ((OAL_STRLEN(bss_dscr->ac_ssid) != cfg_ssid.uc_ssid_len) ||
        (oal_memcmp(cfg_ssid.ac_ssid, bss_dscr->ac_ssid, cfg_ssid.uc_ssid_len) != 0)) {
        return OAL_SUCC;
    }

    /* 挑选HMAC_SCAN_MAX_VALID_SCANNED_BSS_EXPIRE时间以内的有效bss */
    //  use oal_time_after32
    roam_timeout = ((g_pd_bss_expire_time * HMAC_S_TO_MS) < HMAC_SCAN_MAX_VALID_SCANNED_BSS_EXPIRE) ?
        HMAC_SCAN_MAX_VALID_SCANNED_BSS_EXPIRE : (g_pd_bss_expire_time * HMAC_S_TO_MS);
    if (oal_time_after32(oal_time_get_stamp_ms(),
                         (bss_dscr->timestamp + roam_timeout))) {
        return OAL_SUCC;
    }

    roam_alg = &(roam_info->st_alg);
    /* 是否扫描到了当前关联的 bss, 仅置位，不过滤 */
    if (oal_compare_mac_addr(mac_vap->auc_bssid, bss_dscr->auc_bssid) != 0) {
        roam_alg->uc_another_bss_scaned = 1;

        /* Roaming Scenario Recognition
         * dense AP standard: RSSI>=-60dB, candidate num>=5;
         *                    RSSI<-60dB && RSSI >=-75dB, candidate num>=10;
         */
        roam_alg->uc_candidate_bss_num++;
        if (bss_dscr->c_rssi >= roam_info->st_config.c_candidate_good_rssi) {
            roam_alg->uc_candidate_good_rssi_num++;
        } else if ((bss_dscr->c_rssi < roam_info->st_config.c_candidate_good_rssi) &&
                   bss_dscr->c_rssi >= ROAM_RSSI_NE75_DB) {
            roam_alg->uc_candidate_weak_rssi_num++;
        }

        if (bss_dscr->c_rssi > roam_alg->c_max_rssi) {
            roam_alg->c_max_rssi = bss_dscr->c_rssi;
        }
    } else {
        roam_alg->c_current_rssi = bss_dscr->c_rssi;
        roam_alg->current_bss_scaned = OAL_TRUE;
    }

    hmac_roam_alg_record_bss(roam_info, bss_dscr);

    return OAL_SUCC;
}

uint32_t hmac_roam_check_akm(mac_vap_stru *mac_vap, mac_bss_dscr_stru *bss_dscr)
{
    mac_crypto_settings_stru crypto;
    uint32_t match_suite;
    uint32_t rsn_akm_suites[WLAN_PAIRWISE_CIPHER_SUITES] = { 0 };

    mac_ie_get_rsn_cipher(bss_dscr->puc_rsn_ie, &crypto);
    match_suite = mac_mib_rsn_akm_match_suites_s(mac_vap, crypto.aul_akm_suite, sizeof(crypto.aul_akm_suite));
    if (match_suite != 0) {
        return OAL_SUCC;
    }
    mac_mib_get_rsn_akm_suites_s(mac_vap, rsn_akm_suites, sizeof(rsn_akm_suites));

    /* 不支持TBPEKE与其他任何非TBPEKE认证方式的漫游 */
    if (is_only_support_tbpeke(rsn_akm_suites, WLAN_AUTHENTICATION_SUITES) ||
        is_only_support_tbpeke(crypto.aul_akm_suite, WLAN_AUTHENTICATION_SUITES)) {
        oam_warning_log0(mac_vap->uc_vap_id, OAM_SF_ROAM,
            "hmac_roam_check_akm::forbid roam between TBPEKE and others");
        return OAL_ERR_CODE_ROAM_NO_VALID_BSS;
    }
    return OAL_SUCC;
}

#ifdef _PRE_WLAN_FEATURE_11R
uint32_t hmac_roam_check_11r_limit(mac_vap_stru *mac_vap, hmac_roam_info_stru *roam_info, mac_bss_dscr_stru *bss_dscr)
{
    wlan_auth_alg_mode_enum_uint8 auth_mode;
    uint8_t *ie = NULL;

    if (!(roam_info->pst_hmac_vap->bit_11r_enable)) {
        return OAL_SUCC;
    }
#ifdef _PRE_WLAN_FEATURE_PWL
    /* pwl检查自定义信息元素 */
    if ((mac_vap->pwl_enable == OAL_TRUE) && (hmac_pwl_check_bss_11r_cap(bss_dscr) == OAL_TRUE)) {
        return OAL_SUCC;
    }
#endif
    auth_mode = mac_mib_get_AuthenticationMode(mac_vap);
    ie = mac_find_ie(MAC_EID_MOBILITY_DOMAIN,
                     bss_dscr->auc_mgmt_buff + MAC_80211_FRAME_LEN + MAC_SSID_OFFSET,
                     bss_dscr->mgmt_len - MAC_80211_FRAME_LEN - MAC_SSID_OFFSET);
    /* SAE不支持11R漫游 */
    if ((roam_info->pst_hmac_vap->en_sae_connect == OAL_TRUE) && (ie != NULL)) {
        oam_warning_log0(mac_vap->uc_vap_id, OAM_SF_ROAM, "hmac_roam_check_11r_limit::SAE do not support 11r roam");
        return OAL_ERR_CODE_ROAM_NO_VALID_BSS;
    }
    /* 不支持ft到非ft */
    if ((auth_mode == WLAN_WITP_AUTH_FT) && (ie == NULL)) {
        oam_warning_log0(mac_vap->uc_vap_id, OAM_SF_ROAM,
            "hmac_roam_check_11r_limit::not support roam from FT to Non_FT");
        return OAL_ERR_CODE_ROAM_NO_VALID_BSS;
    }
    return OAL_SUCC;
}
#endif

/*
 * 功能描述  : 检测目标BSS加密套件是否支持漫游
 * 1.日    期  : 2019.5.11
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
static uint32_t hmac_roam_check_cipher_limit(hmac_roam_info_stru *roam_info, mac_bss_dscr_stru *bss_dscr)
{
    mac_vap_stru *mac_vap = NULL;
    mac_cap_info_stru *cap_info = NULL;
    uint32_t ret;

    mac_vap = &roam_info->pst_hmac_vap->st_vap_base_info;
    cap_info = (mac_cap_info_stru *)&bss_dscr->us_cap_info;
#ifdef _PRE_WLAN_FEATURE_PWL
    if (mac_vap->pwl_enable == OAL_TRUE) {
        return OAL_SUCC;
    }
#endif
    /*  wapi/wep的bss直接过滤掉 */
    if ((bss_dscr->puc_rsn_ie == NULL) &&
        (bss_dscr->puc_wpa_ie == NULL) &&
        (cap_info->bit_privacy != 0)) {
        return OAL_ERR_CODE_ROAM_NO_VALID_BSS;
    }

    /*  open加密方式到wpa/wpa2直接过滤掉 */
    if ((cap_info->bit_privacy == 0) != (OAL_TRUE != mac_mib_get_privacyinvoked(mac_vap))) {
        return OAL_ERR_CODE_ROAM_NO_VALID_BSS;
    }

    ret = hmac_roam_check_akm(mac_vap, bss_dscr);
    if (ret != OAL_SUCC) {
        return ret;
    }

#ifdef _PRE_WLAN_FEATURE_11R
    ret = hmac_roam_check_11r_limit(mac_vap, roam_info, bss_dscr);
    if (ret != OAL_SUCC) {
        return ret;
    }
#endif

    return OAL_SUCC;
}

#ifdef _PRE_WLAN_FEATURE_11V_ENABLE
/*
 * 功能描述  : 检查输入的扫描结果是否在11v的邻居AP列表
 * 1.日    期  : 2020年05月11日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
oal_bool_enum_uint8 hmac_roam_alg_check_bsst_bssid_in_scan_list(hmac_roam_info_stru *roam_info,
                                                                uint8_t *puc_mac_addr)
{
    uint8_t bss_list_idx = 0;
    oal_bool_enum_uint8 bssid_find = OAL_FALSE;
    uint8_t *puc_dst_mac_addr = NULL;

    if (roam_info == NULL || puc_mac_addr == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "{hmac_roam_alg_check_bsst_bssid_in_scan_list:: NULL pointer}");
        return OAL_FALSE;
    }

    if (roam_info->en_roam_trigger == ROAM_TRIGGER_11V) {
        uint8_t neighbor_bssid_num = roam_info->uc_neighbor_rpt_bssid_num;
        for (bss_list_idx = 0; bss_list_idx < neighbor_bssid_num; bss_list_idx++) {
            puc_dst_mac_addr = roam_info->auc_neighbor_rpt_bssid[bss_list_idx];
            if (!oal_memcmp(roam_info->auc_neighbor_rpt_bssid[bss_list_idx],
                            puc_mac_addr, WLAN_MAC_ADDR_LEN)) {
                bssid_find = OAL_TRUE;
                break;
            }
        }
    }
    return bssid_find;
}
#endif /* _PRE_WLAN_FEATURE_11V_ENABLE */

/*
 * 功能描述  : 检测目标BSSID是否在限制列表中
 * 1.日    期  : 2019.5.18
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_roam_alg_check_bssid_limit(hmac_roam_info_stru *roam_info, uint8_t *puc_mac_addr)
{
    uint32_t ret;

#ifdef _PRE_WLAN_FEATURE_11V_ENABLE
    if (roam_info->en_roam_trigger == ROAM_TRIGGER_11V) {
        ret = hmac_roam_alg_check_bsst_bssid_in_scan_list(roam_info, puc_mac_addr);
        if (ret != OAL_TRUE) {
            return OAL_ERR_CODE_ROAM_NO_VALID_BSS;
        }
        oam_warning_log3(0, OAM_SF_ROAM,
                         "{hmac_roam_alg_check_bssid_limit :: [%02X:XX:XX:XX:%02X:%02X] is in scan list}",
                         puc_mac_addr[MAC_ADDR_0], puc_mac_addr[MAC_ADDR_4], puc_mac_addr[MAC_ADDR_5]);
    }
#endif /* _PRE_WLAN_FEATURE_11V_ENABLE */

    /* 检查黑名单 */
    ret = hmac_roam_alg_find_in_blacklist(roam_info, puc_mac_addr);
    if (ret == OAL_TRUE) {
        oam_warning_log3(0, OAM_SF_ROAM,
                         "{hmac_roam_alg_check_bssid_limit:: [%02X:XX:XX:XX:%02X:%02X] in blacklist!}",
                         puc_mac_addr[MAC_ADDR_0], puc_mac_addr[MAC_ADDR_4], puc_mac_addr[MAC_ADDR_5]);
        return OAL_ERR_CODE_ROAM_NO_VALID_BSS;
    }

    return OAL_SUCC;
}

static oal_bool_enum_uint8 hmac_is_roam_homenetwork_2gto5g_condition(hmac_vap_stru *hmac_vap,
    hmac_roam_info_stru *roam_info, mac_bss_dscr_stru *bss_dscr)
{
    return ((roam_info->st_alg.st_home_network.uc_is_homenetwork == OAL_TRUE) &&
        (hmac_vap->st_vap_base_info.st_channel.en_band == WLAN_BAND_2G) &&
        (bss_dscr->st_channel.en_band == WLAN_BAND_5G) &&
        (bss_dscr->c_rssi > roam_info->st_alg.st_home_network.c_5g_rssi_th));
}

static oal_bool_enum_uint8 hmac_is_roam_weak_rssi_condition(int8_t rssi, mac_bss_dscr_stru *bss_dscr)
{
    return (((rssi < ROAM_RSSI_NE80_DB) && (bss_dscr->st_channel.en_band == WLAN_BAND_2G)) ||
        ((rssi < ROAM_RSSI_NE78_DB) && (bss_dscr->st_channel.en_band == WLAN_BAND_5G)));
}

OAL_STATIC uint32_t hmac_roam_alg_check_aging_time(hmac_roam_info_stru *roam_info,
                                                   mac_bss_dscr_stru *bss_dscr)
{
    hmac_vap_stru *hmac_vap;
    uint32_t roam_timeout;

    hmac_vap = roam_info->pst_hmac_vap;
    if (hmac_vap == NULL) {
        return OAL_ERR_CODE_ROAM_INVALID_VAP;
    }

    roam_timeout = ((g_pd_bss_expire_time * HMAC_S_TO_MS) < HMAC_SCAN_MAX_VALID_SCANNED_BSS_EXPIRE) ?
        HMAC_SCAN_MAX_VALID_SCANNED_BSS_EXPIRE : (g_pd_bss_expire_time * HMAC_S_TO_MS);

    /* 上层触发指定bssid漫游，选网老化时间和扫描老化时间一致 */
    if (roam_info->en_roam_trigger == ROAM_TRIGGER_BSSID) {
        roam_timeout = HMAC_SCAN_MAX_SCANNED_BSS_EXPIRE;
    }

    if (roam_info->en_current_bss_ignore == OAL_TRUE) {
        /* 非voe认证, 挑选HMAC_SCAN_MAX_VALID_SCANNED_BSS_EXPIRE时间以内的有效bss */
#if defined(_PRE_WLAN_FEATURE_11K) || defined(_PRE_WLAN_FEATURE_11R)
        if (hmac_vap->bit_voe_11r_auth != 0) {
            return OAL_SUCC;
        }
#endif
        //  use oal_time_after32
        if (oal_time_after32(oal_time_get_stamp_ms(), (bss_dscr->timestamp + roam_timeout))) {
            return OAL_ERR_CODE_ROAM_NO_VALID_BSS;
        }
    }

    return OAL_SUCC;
}

/* 如果p2p是低时延场景。不支持漫游到dbac。 */
OAL_STATIC uint32_t hmac_roam_check_p2p_dbac(mac_vap_stru *up_mac_vap[], mac_vap_stru *mac_vap,
    mac_bss_dscr_stru *bss_dscr, uint32_t up_vap_num, mac_mvap_state_trans_enum state_trans)
{
    uint32_t i;
    if (state_trans == MAC_MVAP_STATE_TRANS_DCHN_TO_DBAC ||
        state_trans == MAC_MVAP_STATE_TRANS_DBDC_TO_DBAC ||
        state_trans == MAC_MVAP_STATE_TRANS_DBAC_TO_DBAC ||
        state_trans == MAC_MVAP_STATE_TRANS_DBDC_TO_DBDC_AC ||
        state_trans == MAC_MVAP_STATE_TRANS_DBDC_AC_TO_DBDC_AC) {
        for (i = 0; i < up_vap_num; i++) {
            if (up_mac_vap[i]->uc_vap_id == mac_vap->uc_vap_id) {
                continue;
            }

            if (hmac_roam_check_dbac_channel(up_mac_vap[i], bss_dscr->st_channel.uc_chan_number) == OAL_TRUE) {
                return OAL_ERR_CODE_ROAM_NO_VALID_BSS;
            }
        }
    }

    return OAL_SUCC;
}
/*
 * 功能描述  : 检查信道和频段是否匹配
 * 1.日    期  : 2020年6月1日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC uint32_t hmac_roam_alg_check_channel(mac_vap_stru *mac_vap, hmac_roam_info_stru *roam_info,
                                                mac_bss_dscr_stru *bss_dscr)
{
    hmac_roam_alg_stru *roam_alg = &(roam_info->st_alg);
    mac_device_stru *mac_device = NULL;
    mac_vap_stru *up_mac_vap[WLAN_SERVICE_VAP_MAX_NUM_PER_DEVICE] = {NULL};
    uint32_t up_vap_num;
    mac_mvap_state_trans_enum state_trans;

    mac_device = mac_res_get_dev(mac_vap->uc_device_id);
    if (mac_device == NULL) {
        return OAL_ERR_CODE_ROAM_NO_VALID_BSS;
    }

    up_vap_num = mac_device_find_up_vaps(mac_device, up_mac_vap, WLAN_SERVICE_VAP_MAX_NUM_PER_DEVICE);
    if (up_vap_num == 0) {
        oam_warning_log0(0, OAM_SF_ANY, "{hmac_roam_alg_check_channel::mac_device_find_up_vaps fail.}");
        return OAL_ERR_CODE_ROAM_NO_VALID_BSS;
    }

    /* 目标场景不支持不漫游 */
    state_trans = hmac_chan_switch_get_state_trans(up_mac_vap, mac_vap, &(bss_dscr->st_channel), up_vap_num,
        MAC_MVAP_CHAN_SWITCH_STA_ROAM);
    if (state_trans == MAC_MVAP_STATE_TRANS_UNSUPPORTED) {
        return OAL_ERR_CODE_ROAM_NO_VALID_BSS;
    }

    /* p2p低时延场景，不去dbac */
    if (hmac_roam_check_p2p_dbac(up_mac_vap, mac_vap, bss_dscr, up_vap_num, state_trans) != OAL_SUCC) {
        return OAL_ERR_CODE_ROAM_NO_VALID_BSS;
    }

    /* 非双sta模式，不做判断 */
    if (!mac_is_dual_sta_mode()) {
        return OAL_SUCC;
    }

    if (mac_is_primary_legacy_vap(mac_vap) == OAL_TRUE) {
        /* wlan0已经找到了同频段可漫游的bss, 待处理bss是异频，不处理该bss。否则需要继续处理 */
        if (roam_alg->pst_max_rssi_bss &&
            roam_alg->pst_max_rssi_bss->st_channel.en_band == mac_vap->st_channel.en_band &&
            bss_dscr->st_channel.en_band != mac_vap->st_channel.en_band) {
            return OAL_ERR_CODE_ROAM_NO_VALID_BSS;
        }
    } else {
        /* wlan1漫游不考虑异频的bss */
        if (bss_dscr->st_channel.en_band != mac_vap->st_channel.en_band) {
            return OAL_ERR_CODE_ROAM_NO_VALID_BSS;
        }
    }
    return OAL_SUCC;
}

OAL_STATIC uint8_t hmac_roam_alg_compare_bss(hmac_vap_stru *hmac_vap, hmac_roam_alg_stru *roam_alg,
                                             mac_bss_dscr_stru *bss_dscr, int8_t tmp_rssi)
{
    mac_vap_stru *mac_vap = &hmac_vap->st_vap_base_info;

    if (roam_alg->pst_max_rssi_bss == NULL) {
        return OAL_TRUE;
    }

    /* 双sta模式下，如果已找到的bss是异频的，当前处理的bss是同频。不比较rssi，优先同频。 */
    if ((mac_is_dual_sta_mode() == OAL_TRUE) &&
        roam_alg->pst_max_rssi_bss->st_channel.en_band != mac_vap->st_channel.en_band &&
        bss_dscr->st_channel.en_band == mac_vap->st_channel.en_band) {
        oam_warning_log1(0, OAM_SF_ROAM,
            "{hmac_roam_compare_bss::dual sta mode find first same band[%d] bss, replace the result!}",
            bss_dscr->st_channel.en_band);
        return OAL_TRUE;
    }

    return (tmp_rssi > roam_alg->c_max_rssi) ? OAL_TRUE : OAL_FALSE;
}

static uint32_t hmac_roam_alg_check_common_info(mac_vap_stru *mac_vap,
                                                hmac_roam_info_stru *roam_info,
                                                mac_bss_dscr_stru *bss_dscr)
{
    uint32_t ret;
#ifdef _PRE_WLAN_CHBA_MGMT
    mac_device_stru *mac_device = mac_res_get_dev(mac_vap->uc_device_id);
    if (mac_device == NULL) {
        return OAL_ERR_CODE_ROAM_NO_VALID_BSS;
    }
#endif

    /* 检查漫游到自己 */
    if ((roam_info->en_current_bss_ignore == OAL_FALSE) &&
        oal_memcmp(mac_vap->auc_bssid, bss_dscr->auc_bssid, OAL_MAC_ADDR_LEN)) {
        return OAL_ERR_CODE_ROAM_NO_VALID_BSS;
    }

    /* 检查特定BSSID的漫游 */
    if ((roam_info->en_roam_trigger == ROAM_TRIGGER_BSSID) &&
        oal_memcmp(roam_info->auc_target_bssid, bss_dscr->auc_bssid, OAL_MAC_ADDR_LEN)) {
        return OAL_ERR_CODE_ROAM_NO_VALID_BSS;
    }

    ret = hmac_roam_alg_check_channel(mac_vap, roam_info, bss_dscr);
    if (ret != OAL_SUCC) {
        hmac_chr_mvap_report(mac_vap, MAC_MVAP_ERROR_SCENE_ROAM);
        return OAL_ERR_CODE_ROAM_NO_VALID_BSS;
    }

    ret = hmac_roam_alg_check_aging_time(roam_info, bss_dscr);
    if (ret != OAL_SUCC) {
        return OAL_ERR_CODE_ROAM_NO_VALID_BSS;
    }

    ret = hmac_roam_alg_check_bssid_limit(roam_info, bss_dscr->auc_bssid);
    if (ret != OAL_SUCC) {
        return OAL_ERR_CODE_ROAM_NO_VALID_BSS;
    }

    /* check bssid blacklist from Framework setting */
    ret = hmac_blacklist_filter(mac_vap, bss_dscr->auc_bssid, WLAN_MAC_ADDR_LEN);
    if (ret == OAL_TRUE) {
        return OAL_ERR_CODE_ROAM_NO_VALID_BSS;
    }

    /* 检查漫游到其它BSSID */
    if (roam_info->en_current_bss_ignore == OAL_TRUE) {
        /* 排除当前bss的rssi值计算，本地已经保存了dmac上报的rssi */
        if (oal_compare_mac_addr(mac_vap->auc_bssid, bss_dscr->auc_bssid) == 0) {
            return OAL_ERR_CODE_ROAM_NO_VALID_BSS;
        }
    }

    if (hmac_roam_check_cipher_limit(roam_info, bss_dscr) != OAL_SUCC) {
        return OAL_ERR_CODE_ROAM_NO_VALID_BSS;
    }
    return OAL_SUCC;
}

int8_t hmac_roam_alg_check_rssi_weight(mac_bss_dscr_stru *bss_dscr)
{
    int8_t rssi;

    rssi = bss_dscr->c_rssi;

    /*  5G AP have more weight than 2.4G AP for higher priority */
    if (bss_dscr->st_channel.en_band == WLAN_BAND_5G) {
        rssi = hmac_roam_alg_adjust_5g_rssi_weight(rssi);
    }

    /* 支持ax 加分处理 */
    if (bss_dscr->en_he_capable == OAL_TRUE) {
        rssi = hmac_roam_alg_adjust_ax_rssi_weight(rssi);
    }

    if (bss_dscr->sap_mode == MAC_SAP_MASTER) {
        rssi = hmac_roam_alg_adjust_sap_rssi_weight(rssi);
    }
    return rssi;
}

OAL_STATIC uint8_t hmac_roam_alg_compare_conflict_bssid(hmac_roam_info_stru *roam_info, mac_bss_dscr_stru *bss_dscr)
{
    hmac_vap_stru *hmac_vap = NULL;
    mac_vap_stru *mac_vap = NULL;
    uint8_t ret = OAL_FALSE;

    hmac_vap = roam_info->pst_hmac_vap;
    mac_vap = &(hmac_vap->st_vap_base_info);

    /* 漫游冲突场景只针对11v从5G漫游到2G场景 */
    if ((roam_info->en_roam_trigger != ROAM_TRIGGER_11V) ||
        (mac_vap->st_channel.en_band != WLAN_BAND_5G) ||
        (bss_dscr->st_channel.en_band != WLAN_BAND_2G)) {
        return ret;
    }

#ifdef _PRE_WLAN_FEATURE_11V_ENABLE
        /* 如果是华为路由器，识别11v漫游和指定bssid漫游冲突场景后，拒绝后续11v指示的 5G->2G漫游 */
        if (hmac_vap->is_hwrouter == OAL_TRUE &&
            !oal_memcmp(bss_dscr->auc_bssid, roam_info->roam_conflict_info.reject_bssid, OAL_MAC_ADDR_LEN)) {
            oam_warning_log3(0, OAM_SF_ROAM,
                "{hmac_roam_alg_compare_rssi_increase::reject 11v_roam to [%2X:XX:XX:XX:%2X:%2X]for roam conflict!}",
                bss_dscr->auc_bssid[BYTE_OFFSET_0], bss_dscr->auc_bssid[BYTE_OFFSET_4],
                bss_dscr->auc_bssid[BYTE_OFFSET_5]);
            ret = OAL_TRUE;
        } else {
            hmac_roam_alg_clear_repeat_roam_stat(roam_info);
        }
#endif
    return ret;
}

uint32_t hmac_roam_alg_bss_check(hmac_roam_info_stru *roam_info, mac_bss_dscr_stru *bss_dscr)
{
    hmac_vap_stru *hmac_vap = NULL;
    mac_vap_stru *mac_vap = NULL;
    hmac_roam_alg_stru *roam_alg = NULL;
    mac_cfg_ssid_param_stru cfg_ssid = {0};

    uint8_t stru_len;
    int8_t c_tmp_rssi;

    hmac_vap = roam_info->pst_hmac_vap;
    if (hmac_vap == NULL) {
        return OAL_ERR_CODE_ROAM_INVALID_VAP;
    }

    mac_vap = &(hmac_vap->st_vap_base_info);
    mac_mib_get_ssid (mac_vap, &stru_len, (uint8_t *)(&cfg_ssid));
#ifdef _PRE_WLAN_FEATURE_PWL
    hmac_roam_pwl_update_ssid(hmac_vap, bss_dscr, &cfg_ssid);
#endif
    if ((OAL_STRLEN(bss_dscr->ac_ssid) != cfg_ssid.uc_ssid_len) ||
        (0 != oal_memcmp(cfg_ssid.ac_ssid, bss_dscr->ac_ssid, cfg_ssid.uc_ssid_len)) ||
        hmac_roam_alg_check_common_info(mac_vap, roam_info, bss_dscr) != OAL_SUCC) {
        return OAL_ERR_CODE_ROAM_NO_VALID_BSS;
    }
    roam_alg = &(roam_info->st_alg);

    if (hmac_is_roam_homenetwork_2gto5g_condition(hmac_vap, roam_info, bss_dscr)) {
        roam_alg->c_max_rssi = bss_dscr->c_rssi;
        roam_alg->pst_max_rssi_bss = bss_dscr;
        return OAL_SUCC;
    }

    //  candidate AP with weak signal ignored in case roaming time last too long
    // 终端评审: 2.4G候选AP小于-80dB不再漫游，5G候选AP小于-78dB不再漫游
    if (hmac_is_roam_weak_rssi_condition(bss_dscr->c_rssi, bss_dscr)) {
        oam_warning_log1(0, OAM_SF_ROAM, "{hmac_roam_alg_bss_check::bss rssi[%d] is weak!}", bss_dscr->c_rssi);
        return OAL_ERR_CODE_ROAM_NO_VALID_BSS;
    }

    c_tmp_rssi = hmac_roam_alg_check_rssi_weight(bss_dscr);
    /* c_current_rssi为0时，表示linkloss上报的触发，不需要考虑rssi增益 */
    if (hmac_roam_alg_compare_rssi_increase(roam_info, bss_dscr, c_tmp_rssi) <= 0) {
        return OAL_ERR_CODE_ROAM_NO_VALID_BSS;
    }

    /* 11v漫游和指定bssid关联场景下，拒绝11v漫游 */
    if (hmac_roam_alg_compare_conflict_bssid(roam_info, bss_dscr) == OAL_TRUE) {
        return OAL_ERR_CODE_ROAM_NO_VALID_BSS;
    }

    /* 对于已存在pmk缓存的bss进行加分处理 */
    if (hmac_vap_get_pmksa(hmac_vap, bss_dscr->auc_bssid) != NULL) {
        c_tmp_rssi += ROAM_RSSI_DIFF_4_DB;
    }

    if (hmac_roam_alg_compare_bss(hmac_vap, roam_alg, bss_dscr, c_tmp_rssi) == OAL_TRUE) {
        roam_alg->c_max_rssi = c_tmp_rssi;
        roam_alg->pst_max_rssi_bss = bss_dscr;
    }

    /* 当2G AP RSSI和5G AP加权RSSI相等时，优选5G低band AP */
    if ((c_tmp_rssi == roam_alg->c_max_rssi) &&
        (roam_alg->pst_max_rssi_bss->st_channel.en_band == WLAN_BAND_2G) &&
        (bss_dscr->st_channel.en_band == WLAN_BAND_5G)) {
        roam_alg->c_max_rssi = c_tmp_rssi;
        roam_alg->pst_max_rssi_bss = bss_dscr;
    }

    return OAL_SUCC;
}

oal_bool_enum_uint8 hmac_roam_alg_need_to_stop_roam_trigger(hmac_roam_info_stru *roam_info)
{
    hmac_vap_stru *hmac_vap = NULL;
    hmac_roam_alg_stru *roam_alg = NULL;

    if (roam_info == NULL) {
        return OAL_FALSE;
    }

    hmac_vap = roam_info->pst_hmac_vap;
    if (hmac_vap == NULL) {
        return OAL_FALSE;
    }

    roam_alg = &(roam_info->st_alg);

    if (roam_alg->uc_another_bss_scaned) {
        roam_alg->uc_invalid_scan_cnt = 0xff;
        return OAL_FALSE;
    }

    if (roam_alg->uc_invalid_scan_cnt == 0xff) {
        return OAL_FALSE;
    }

    if (roam_alg->uc_invalid_scan_cnt++ > 4) { /* 连续扫描到当前关联且首次关联的 bss 的次数大于4次 */
        roam_alg->uc_invalid_scan_cnt = 0xff;
        return OAL_TRUE;
    }

    return OAL_FALSE;
}

mac_bss_dscr_stru *hmac_roam_alg_select_bss(hmac_roam_info_stru *roam_info)
{
    hmac_vap_stru *hmac_vap = NULL;
    mac_vap_stru *mac_vap = NULL;
    mac_bss_dscr_stru *bss_dscr = NULL;
    hmac_roam_alg_stru *roam_alg = NULL;
    int16_t delta_rssi;

    if (oal_unlikely(roam_info == NULL || roam_info->pst_hmac_vap == NULL)) {
        return NULL;
    }

    hmac_vap = roam_info->pst_hmac_vap;
    mac_vap = &(hmac_vap->st_vap_base_info);
    roam_alg = &(roam_info->st_alg);

    /* 取得最大 rssi 的 bss */
    bss_dscr = roam_alg->pst_max_rssi_bss;

    if ((roam_alg->pst_max_capacity_bss != NULL) &&
        (roam_alg->max_capacity >= ROAM_THROUGHPUT_THRESHOLD)) {
        /* 取得最大 capacity 的 bss */
        bss_dscr = roam_alg->pst_max_capacity_bss;
    }

    if (bss_dscr == NULL) {
        /* should not be here */
        return NULL;
    }

    if (roam_info->st_alg.st_home_network.uc_is_homenetwork == OAL_TRUE &&
        roam_info->en_roam_trigger == ROAM_TRIGGER_HOME_NETWORK) {
        /* 5g优选，选中的5g bssid */
        if (bss_dscr->st_channel.en_band == WLAN_BAND_5G) {
            oam_warning_log4(0, OAM_SF_ROAM,
                "{hmac_roam_alg_select_bss::roam_to 5G home network AP, max_rssi=%d, [%02X:XX:XX:XX:%02X:%02X]}",
                roam_alg->c_max_rssi, bss_dscr->auc_bssid[BYTE_OFFSET_0],
                bss_dscr->auc_bssid[BYTE_OFFSET_4], bss_dscr->auc_bssid[BYTE_OFFSET_5]);
            return bss_dscr;
        }
    }

    /* rssi增益处理 */
    delta_rssi = hmac_roam_alg_compare_rssi_increase(roam_info, bss_dscr, roam_alg->c_max_rssi);
    if (delta_rssi <= 0) {
        return NULL;
    }

    if (bss_dscr->st_channel.en_band == WLAN_BAND_5G) {
        oam_warning_log4(0, OAM_SF_ROAM,
                         "{hmac_roam_alg_select_bss::roam_to 5G candidate AP, max_rssi=%d, [%02X:XX:XX:XX:%02X:%02X]}",
                         roam_alg->c_max_rssi, bss_dscr->auc_bssid[BYTE_OFFSET_0],
                         bss_dscr->auc_bssid[BYTE_OFFSET_4], bss_dscr->auc_bssid[BYTE_OFFSET_5]);
    } else {
        oam_warning_log4(0, OAM_SF_ROAM,
                         "{hmac_roam_alg_select_bss::roam_to candidate AP, max_rssi=%d, [%02X:XX:XX:XX:%02X:%02X]}",
                         roam_alg->c_max_rssi, bss_dscr->auc_bssid[BYTE_OFFSET_0],
                         bss_dscr->auc_bssid[BYTE_OFFSET_4], bss_dscr->auc_bssid[BYTE_OFFSET_5]);
    }

    return bss_dscr;
}
