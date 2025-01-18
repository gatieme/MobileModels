/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * 功能说明 : hmac_hd2d.c
 * 作    者 : wifi
 * 创建日期 : 2020年04月10日
 */

#ifdef _PRE_WLAN_FEATURE_HID2D
/* 1 头文件包含 */
#include "mac_ie.h"
#include "mac_vap.h"
#include "mac_device.h"
#include "wlan_types.h"
#include "hmac_chan_mgmt.h"
#include "mac_device.h"
#include "hmac_hid2d.h"
#include "hmac_scan.h"
#include "oal_cfg80211.h"
#include "hmac_config.h"
#ifdef _PRE_WLAN_CHBA_MGMT
#include "hmac_chba_function.h"
#endif
#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_HID2D_C

#define DECIMAL_TO_INTEGER 100 /* 用于将小数转换成整数，便于计算 */
/* 2 全局变量定义 */
/* 全局待选信道覆盖所有信道，实际运行中可选择的待选信道根据GO与GC所支持的信道列表求交集所得，
   用全局待选信道的序号表示 */
/* 2.4G全频段待选信道 */
hmac_hid2d_chan_stru g_aus_channel_candidate_list_2g[HMAC_HID2D_CHANNEL_NUM_2G] = {
    // idx  chan_idx  chan_num   bandwidth
    {0,     0,      1,    WLAN_BAND_WIDTH_20M},
    {1,     1,      2,    WLAN_BAND_WIDTH_20M},
    {2,     2,      3,    WLAN_BAND_WIDTH_20M},
    {3,     3,      4,    WLAN_BAND_WIDTH_20M},
    {4,     4,      5,    WLAN_BAND_WIDTH_20M},
    {5,     5,      6,    WLAN_BAND_WIDTH_20M},
    {6,     6,      7,    WLAN_BAND_WIDTH_20M},
    {7,     7,      8,    WLAN_BAND_WIDTH_20M},
    {8,     8,      9,    WLAN_BAND_WIDTH_20M},
    {9,     9,      10,   WLAN_BAND_WIDTH_20M},
    {10,    10,     11,   WLAN_BAND_WIDTH_20M},
    {11,    11,     12,   WLAN_BAND_WIDTH_20M},
    {12,    12,     13,   WLAN_BAND_WIDTH_20M},
    {13,    13,     14,   WLAN_BAND_WIDTH_20M},
    {14,    0,      1,    WLAN_BAND_WIDTH_40PLUS},
    {15,    4,      5,    WLAN_BAND_WIDTH_40PLUS},
    {16,    6,      7,    WLAN_BAND_WIDTH_40PLUS},
    {17,    8,      9,    WLAN_BAND_WIDTH_40PLUS},
    {18,    1,      2,    WLAN_BAND_WIDTH_40PLUS},
    {19,    5,      6,    WLAN_BAND_WIDTH_40PLUS},
    {20,    7,      8,    WLAN_BAND_WIDTH_40PLUS},
    {21,    12,     13,   WLAN_BAND_WIDTH_40MINUS},
    {22,    4,      5,    WLAN_BAND_WIDTH_40MINUS},
    {23,    6,      7,    WLAN_BAND_WIDTH_40MINUS},
    {24,    10,     11,   WLAN_BAND_WIDTH_40MINUS},
    {25,    11,     12,   WLAN_BAND_WIDTH_40MINUS},
    {26,    9,      10,   WLAN_BAND_WIDTH_40MINUS},
    {27,    2,      3,    WLAN_BAND_WIDTH_40PLUS},
    {28,    3,      4,    WLAN_BAND_WIDTH_40PLUS},
    {29,    5,      6,    WLAN_BAND_WIDTH_40MINUS},
    {30,    7,      8,    WLAN_BAND_WIDTH_40MINUS},
    {31,    8,      9,    WLAN_BAND_WIDTH_40MINUS},
};
/* 5G全频段待选信道 */
hmac_hid2d_chan_stru g_aus_channel_candidate_list_5g[HMAC_HID2D_CHANNEL_NUM_5G] = {
    // idx  chan_idx  chan_num   bandwidth
    {0,     0,      36,    WLAN_BAND_WIDTH_20M},
    {1,     1,      40,    WLAN_BAND_WIDTH_20M},
    {2,     2,      44,    WLAN_BAND_WIDTH_20M},
    {3,     3,      48,    WLAN_BAND_WIDTH_20M},
    {4,     0,      36,    WLAN_BAND_WIDTH_40PLUS},
    {5,     1,      40,    WLAN_BAND_WIDTH_40MINUS},
    {6,     2,      44,    WLAN_BAND_WIDTH_40PLUS},
    {7,     3,      48,    WLAN_BAND_WIDTH_40MINUS},
    {8,     0,      36,    WLAN_BAND_WIDTH_80PLUSPLUS},
    {9,     1,      40,    WLAN_BAND_WIDTH_80MINUSPLUS},
    {10,    2,      44,    WLAN_BAND_WIDTH_80PLUSMINUS},
    {11,    3,      48,    WLAN_BAND_WIDTH_80MINUSMINUS},
    {12,    4,      52,    WLAN_BAND_WIDTH_20M},
    {13,    5,      56,    WLAN_BAND_WIDTH_20M},
    {14,    6,      60,    WLAN_BAND_WIDTH_20M},
    {15,    7,      64,    WLAN_BAND_WIDTH_20M},
    {16,    4,      52,    WLAN_BAND_WIDTH_40PLUS},
    {17,    5,      56,    WLAN_BAND_WIDTH_40MINUS},
    {18,    6,      60,    WLAN_BAND_WIDTH_40PLUS},
    {19,    7,      64,    WLAN_BAND_WIDTH_40MINUS},
    {20,    4,      52,    WLAN_BAND_WIDTH_80PLUSPLUS},
    {21,    5,      56,    WLAN_BAND_WIDTH_80MINUSPLUS},
    {22,    6,      60,    WLAN_BAND_WIDTH_80PLUSMINUS},
    {23,    7,      64,    WLAN_BAND_WIDTH_80MINUSMINUS},
    {24,    8,      100,   WLAN_BAND_WIDTH_20M},
    {25,    9,      104,   WLAN_BAND_WIDTH_20M},
    {26,    10,     108,   WLAN_BAND_WIDTH_20M},
    {27,    11,     112,   WLAN_BAND_WIDTH_20M},
    {28,    8,      100,   WLAN_BAND_WIDTH_40PLUS},
    {29,    9,      104,   WLAN_BAND_WIDTH_40MINUS},
    {30,    10,     108,   WLAN_BAND_WIDTH_40PLUS},
    {31,    11,     112,   WLAN_BAND_WIDTH_40MINUS},
    {32,    8,      100,   WLAN_BAND_WIDTH_80PLUSPLUS},
    {33,    9,      104,   WLAN_BAND_WIDTH_80MINUSPLUS},
    {34,    10,     108,   WLAN_BAND_WIDTH_80PLUSMINUS},
    {35,    11,     112,   WLAN_BAND_WIDTH_80MINUSMINUS},
    {36,    12,     116,   WLAN_BAND_WIDTH_20M},
    {37,    13,     120,   WLAN_BAND_WIDTH_20M},
    {38,    14,     124,   WLAN_BAND_WIDTH_20M},
    {39,    15,     128,   WLAN_BAND_WIDTH_20M},
    {40,    12,     116,   WLAN_BAND_WIDTH_40PLUS},
    {41,    13,     120,   WLAN_BAND_WIDTH_40MINUS},
    {42,    14,     124,   WLAN_BAND_WIDTH_40PLUS},
    {43,    15,     128,   WLAN_BAND_WIDTH_40MINUS},
    {44,    12,     116,   WLAN_BAND_WIDTH_80PLUSPLUS},
    {45,    13,     120,   WLAN_BAND_WIDTH_80MINUSPLUS},
    {46,    14,     124,   WLAN_BAND_WIDTH_80PLUSMINUS},
    {47,    15,     128,   WLAN_BAND_WIDTH_80MINUSMINUS},
    {48,    16,     132,   WLAN_BAND_WIDTH_20M},
    {49,    17,     136,   WLAN_BAND_WIDTH_20M},
    {50,    18,     140,   WLAN_BAND_WIDTH_20M},
    {51,    19,     144,   WLAN_BAND_WIDTH_20M},
    {52,    16,     132,   WLAN_BAND_WIDTH_40PLUS},
    {53,    17,     136,   WLAN_BAND_WIDTH_40MINUS},
    {54,    18,     140,   WLAN_BAND_WIDTH_40PLUS},
    {55,    19,     144,   WLAN_BAND_WIDTH_40MINUS},
    {56,    16,     132,   WLAN_BAND_WIDTH_80PLUSPLUS},
    {57,    17,     136,   WLAN_BAND_WIDTH_80MINUSPLUS},
    {58,    18,     140,   WLAN_BAND_WIDTH_80PLUSMINUS},
    {59,    19,     144,   WLAN_BAND_WIDTH_80MINUSMINUS},
    {60,    20,     149,   WLAN_BAND_WIDTH_20M},
    {61,    21,     153,   WLAN_BAND_WIDTH_20M},
    {62,    22,     157,   WLAN_BAND_WIDTH_20M},
    {63,    23,     161,   WLAN_BAND_WIDTH_20M},
    {64,    20,     149,   WLAN_BAND_WIDTH_40PLUS},
    {65,    21,     153,   WLAN_BAND_WIDTH_40MINUS},
    {66,    22,     157,   WLAN_BAND_WIDTH_40PLUS},
    {67,    23,     161,   WLAN_BAND_WIDTH_40MINUS},
    {68,    20,     149,   WLAN_BAND_WIDTH_80PLUSPLUS},
    {69,    21,     153,   WLAN_BAND_WIDTH_80MINUSPLUS},
    {70,    22,     157,   WLAN_BAND_WIDTH_80PLUSMINUS},
    {71,    23,     161,   WLAN_BAND_WIDTH_80MINUSMINUS},
    {72,    24,     165,   WLAN_BAND_WIDTH_20M}
};
/* 扫描顺序数组: 初始化为发布会场景的扫描顺序，正常业务场景需要在开始扫描时根据实际待选信道列表确定并赋值 */
uint8_t g_scan_chan_list[HMAC_HID2D_MAX_SCAN_CHAN_NUM] = { 8, 20, 32, 44, 56, 68 };
/* 一轮扫描的数组值，确定g_scan_chan_list的边界，初始化值为发布会场景 */
uint8_t g_scan_chan_num_max = HMAC_HID2D_SCAN_CHAN_NUM_FOR_APK;
/* 实际可支持的信道列表数组 */
uint8_t g_supp_chan_list[HMAC_HID2D_CHANNEL_NUM_5G] = { 0 };
/* 实际可支持的信道个数，确定g_supp_chan_list的边界 */
uint8_t g_supp_chan_num_max = 0;
/* 扫描信息 */
hmac_hid2d_auto_channel_switch_stru g_st_hmac_hid2d_acs_info = {
    .uc_acs_mode = OAL_FALSE,
};

OAL_STATIC const wal_hid2d_cmd_entry_stru g_hid2d_vendor_cmd[] = {
#ifdef _PRE_WLAN_FEATURE_HID2D_PRESENTATION
    { WAL_HID2D_INIT_CMD,          wal_hipriv_hid2d_presentation_init },
    { WAL_HID2D_CHAN_SWITCH_CMD,   wal_hipriv_hid2d_swchan },
#endif
    { WAL_HID2D_ACS_CMD,           wal_ioctl_set_hid2d_acs_mode },
    { WAL_HID2D_ACS_STATE_CMD,     wal_ioctl_update_acs_state },
    { WAL_HID2D_LINK_MEAS_CMD,     wal_ioctl_hid2d_link_meas },
};

/* 3 函数声明 */
uint32_t hmac_hid2d_h2d_link_meas_cmd(mac_vap_stru *pst_mac_vap, uint8_t chan_index, uint8_t scan_mode);
uint8_t hmac_hid2d_get_best_chan(mac_channel_stru *pst_scan_chan);
OAL_STATIC uint32_t hmac_hid2d_acs_scan_handler(hmac_vap_stru *hmac_vap, wlan_scan_chan_stats_stru *chan_result,
    hmac_hid2d_auto_channel_switch_stru *hmac_hid2d_acs_info);
OAL_STATIC uint32_t hmac_hid2d_acs_once_scan_handler(hmac_vap_stru *hmac_vap, wlan_scan_chan_stats_stru *chan_result,
    hmac_hid2d_auto_channel_switch_stru *hmac_hid2d_acs_info);
uint32_t hmac_hid2d_acs_timeout_handle(void *arg);
uint32_t hmac_hid2d_chan_stat_report_timeout_handle(void *arg);
uint32_t hmac_hid2d_acs_get_best_chan(hmac_hid2d_auto_channel_switch_stru *hmac_hid2d_acs_info,
    hmac_hid2d_chan_info_stru *chan_info, hmac_hid2d_chan_stru *candidate_chan_list);

/* 4 函数实现 */
/*
 * 函 数 名  : wal_hid2d_sleep_mode
 * 功能描述  : 配置wifi休眠模式
 * 1.日    期  : 2020年4月22日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
int32_t wal_hid2d_sleep_mode(oal_net_device_stru *net_dev, uint8_t ctrl)
{
    char *cmd = CMD_SET_STA_PM_ON;
    char cmd_buf[BUFF_SIZE] = { 0 };

    oam_warning_log1(0, OAM_SF_ANY, "wal_hid2d_sleep_mode::ctrl = %d", ctrl);
    if (snprintf_s(cmd_buf, BUFF_SIZE, BUFF_SIZE - 1, "%s %u", cmd, ctrl) > 0) {
        return wal_ioctl_set_sta_pm_on(net_dev, cmd_buf, BUFF_SIZE);
    }
    return -OAL_EFAUL;
}

/*
 * 函 数 名  : wal_hid2d_napi_mode
 * 功能描述  : 配置napi模式
 * 1.日    期  : 2020年4月22日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
int32_t wal_hid2d_napi_mode(oal_net_device_stru *pst_net_dev, uint8_t uc_ctrl)
{
    oal_netdev_priv_stru *pst_netdev_priv = (oal_netdev_priv_stru *)oal_net_dev_wireless_priv(pst_net_dev);

    if (pst_netdev_priv == NULL) {
        oam_warning_log0(0, OAM_SF_ANY, "{wal_hid2d_napi_mode::pst_netdev_priv is null!}");
        return -OAL_EFAUL;
    }

    oam_warning_log1(0, OAM_SF_ANY, "wal_hid2d_napi_mode::ctrl = %d", uc_ctrl);
    pst_netdev_priv->uc_napi_enable = uc_ctrl;
    pst_netdev_priv->uc_gro_enable = uc_ctrl;
    return OAL_SUCC;
}

uint32_t wal_hipriv_start_chan_meas(oal_net_device_stru *net_dev, int8_t *pc_param)
{
    return wal_ioctl_hid2d_link_meas(net_dev, pc_param);
}

/*
 * 函 数 名  : wal_hid2d_gso_mode
 * 功能描述  : 配置gso模式
 * 1.日    期  : 2020年4月22日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
int32_t wal_hid2d_gso_mode(oal_net_device_stru *pst_net_dev, uint8_t uc_ctrl)
{
#ifdef _PRE_WLAN_FEATURE_GSO
    oam_warning_log1(0, OAM_SF_ANY, "wal_hid2d_gso_mode::uc_ctrl = %d", uc_ctrl);
    if (uc_ctrl == DISABLE) {
        pst_net_dev->features &= ~NETIF_F_SG;
        pst_net_dev->hw_features &= ~NETIF_F_SG;
    } else if (uc_ctrl == ENABLE) {
        pst_net_dev->features |= NETIF_F_SG;
        pst_net_dev->hw_features |= NETIF_F_SG;
    }
#endif
    return OAL_SUCC;
}

/*
 * 函 数 名  : wal_hid2d_freq_boost
 * 功能描述  : 配置wifi芯片调频模式
 * 1.日    期  : 2020年4月22日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
int32_t wal_hid2d_freq_boost(oal_net_device_stru *pst_net_dev, uint8_t uc_ctrl)
{
    uint32_t l_ret = 0;
    char freq_cmd1[] = {"auto_freq 0 0"};
    char freq_cmd2[] = {"auto_freq 1 30"};
    char freq_cmd3[] = {"auto_freq 0 1"};

    oam_warning_log1(0, OAM_SF_ANY, "wal_hid2d_freq_boost::uc_ctrl = %d", uc_ctrl);
    if (uc_ctrl == ENABLE) {
        l_ret = wal_hipriv_set_tlv_cmd(pst_net_dev, (uint8_t*) freq_cmd1);
        l_ret = wal_hipriv_set_tlv_cmd(pst_net_dev, (uint8_t*) freq_cmd2);
    } else if (uc_ctrl == DISABLE) {
        l_ret = wal_hipriv_set_tlv_cmd(pst_net_dev, (uint8_t*) freq_cmd3);
    }
    return l_ret;
}

/*
 * 函 数 名  : hmac_hid2d_find_p2p_vap
 * 功能描述  : 根据mac device找到p2p dmac vap，如果找不到返回空指针
 * 1.日    期  : 2020年04月12日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_hid2d_find_p2p_vap(mac_device_stru *pst_mac_device, mac_vap_stru **ppst_mac_vap)
{
    uint8_t uc_vap_index;
    uint8_t uc_no_p2p_vap_flag = OAL_TRUE;
    mac_vap_stru *pst_p2p_mac_vap = NULL;

    /* 找到挂接在该device上的p2p vap */
    for (uc_vap_index = 0; uc_vap_index < pst_mac_device->uc_vap_num; uc_vap_index++) {
        pst_p2p_mac_vap = mac_res_get_mac_vap(pst_mac_device->auc_vap_id[uc_vap_index]);
        if (pst_p2p_mac_vap == NULL) {
            continue;
        }
        if (pst_p2p_mac_vap->en_p2p_mode != WLAN_LEGACY_VAP_MODE) {
            uc_no_p2p_vap_flag = OAL_FALSE;
            break;
        }
    }
    if (uc_no_p2p_vap_flag == OAL_TRUE) {
        oam_error_log0(0, OAM_SF_ANTI_INTF, "{hmac_hid2d_find_p2p_vap_ext::no p2p vap error!}");
        return OAL_FAIL;
    }
    *ppst_mac_vap = pst_p2p_mac_vap;
    return OAL_SUCC;
}
uint32_t hmac_hid2d_find_up_p2p_vap(mac_device_stru *pst_mac_device, mac_vap_stru **ppst_mac_vap)
{
    uint8_t uc_vap_index;
    uint8_t uc_no_p2p_vap_flag = OAL_TRUE;
    mac_vap_stru *pst_p2p_mac_vap = NULL;
    mac_vap_stru *mac_vap = NULL;

    /* 找到挂接在该device上的p2p vap */
    for (uc_vap_index = 0; uc_vap_index < pst_mac_device->uc_vap_num; uc_vap_index++) {
        pst_p2p_mac_vap = mac_res_get_mac_vap(pst_mac_device->auc_vap_id[uc_vap_index]);
        if (pst_p2p_mac_vap == NULL) {
            continue;
        }
        mac_vap = pst_p2p_mac_vap;
        if (pst_p2p_mac_vap->en_p2p_mode == WLAN_P2P_GO_MODE || pst_p2p_mac_vap->en_p2p_mode == WLAN_P2P_CL_MODE) {
            uc_no_p2p_vap_flag = OAL_FALSE;
            break;
        }
    }
    if (uc_no_p2p_vap_flag == OAL_TRUE) {
        oam_error_log0(0, 0, "{hmac_hid2d_find_p2p_vap::no up p2p vap error!}");
        *ppst_mac_vap = mac_vap; /* pst_mac_vap是非p2p GO/CL vap，用于p2p断链后的方案善后处理 */
        return OAL_FAIL;
    }
    *ppst_mac_vap = pst_p2p_mac_vap;
    return OAL_SUCC;
}

/*
 * 函 数 名  : hmac_hid2d_h2d_link_meas_cmd
 * 功能描述  : 设置扫描参数，并开启一次扫描
 * 1.日    期  : 2020年3月18日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_hid2d_h2d_link_meas_cmd(mac_vap_stru *pst_mac_vap, uint8_t chan_index, uint8_t scan_mode)
{
    hmac_hid2d_auto_channel_switch_stru *pst_hmac_hid2d_acs_info = NULL;
    hmac_hid2d_chan_stru *pst_candidate_list = NULL;
    mac_channel_stru scan_channel = {0};
    mac_chan_meas_h2d_info_stru chan_meas_h2d_info = {};
    hmac_vap_stru *pst_hmac_vap = NULL;
    uint32_t ret;

    pst_hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(pst_mac_vap->uc_vap_id);
    if (pst_hmac_vap == NULL) {
        oam_error_log0(pst_mac_vap->uc_vap_id, 0, "{hmac_hid2d_h2d_link_meas_cmd::pst_hmac_vap null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    if (hmac_vap_is_connecting(pst_mac_vap)) {
        oam_warning_log0(pst_mac_vap->uc_vap_id, 0, "{hmac_hid2d_h2d_link_meas_cmd::has user connecting, stop scan!}");
        return OAL_FAIL;
    }
    ret = hmac_scan_check_can_enter_scan_state(pst_mac_vap, OAL_FALSE);
    if (ret != OAL_SUCC) {
        oam_warning_log1(pst_mac_vap->uc_vap_id, 0,
            "{hmac_hid2d_h2d_link_meas_cmd::Because of err_code[%d], can't enter into meas state!}", ret);
        return ret;
    }
    pst_hmac_hid2d_acs_info = &g_st_hmac_hid2d_acs_info;

    if (scan_mode == HMAC_HID2D_ACS_SCAN) {
        scan_channel.en_band = pst_hmac_hid2d_acs_info->uc_cur_band;
        pst_candidate_list = (scan_channel.en_band == WLAN_BAND_5G) ? g_aus_channel_candidate_list_5g :
            g_aus_channel_candidate_list_2g;
    } else {
        scan_channel.en_band = pst_hmac_hid2d_acs_info->scan_band;
        pst_candidate_list = (scan_channel.en_band == WLAN_BAND_5G) ? g_aus_channel_candidate_list_5g :
            g_aus_channel_candidate_list_2g;
    }
    scan_channel.uc_chan_number = pst_candidate_list[chan_index].uc_chan_number;
    scan_channel.en_bandwidth = pst_candidate_list[chan_index].en_bandwidth;
    scan_channel.uc_chan_idx = pst_candidate_list[chan_index].uc_chan_idx;

    /* 配置下发参数 */
    chan_meas_h2d_info.scan_time = pst_hmac_hid2d_acs_info->scan_time;
    chan_meas_h2d_info.scan_channel = scan_channel;

    oam_warning_log0(pst_mac_vap->uc_vap_id, OAM_SF_ANY, "{hmac_hid2d_h2d_link_meas_cmd:send to start chan meas!");
    ret = hmac_config_send_event(pst_mac_vap, WLAN_CFGID_CHAN_MEAS_EVENT, sizeof(mac_chan_meas_h2d_info_stru),
        (uint8_t *)&chan_meas_h2d_info);
    if (ret != OAL_SUCC) {
        oam_error_log0(pst_mac_vap->uc_vap_id, OAM_SF_ANY, "{hmac_hid2d_h2d_link_meas_cmd:fail to send event to dmac}");
    }
    return ret;
}
/*
 * 函 数 名  : hmac_hid2d_get_best_chan
 * 功能描述  : 获取最空闲的信道
 * 1.日    期  : 2020年3月18日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint8_t hmac_hid2d_get_best_chan(mac_channel_stru *pst_scan_chan)
{
    hmac_hid2d_chan_info_stru *pst_chan_info = NULL;
    hmac_hid2d_auto_channel_switch_stru *pst_hmac_hid2d_acs_info = NULL;
    uint8_t uc_index;
    uint8_t uc_chan_idx;
    int16_t highest_chan_load = 0;
    int16_t lowest_noise_rssi = 0;
    uint8_t best_chan_of_chan_load = 0;
    uint8_t best_chan_of_noise_rssi = 0;

    pst_hmac_hid2d_acs_info = &g_st_hmac_hid2d_acs_info;
    pst_chan_info = pst_hmac_hid2d_acs_info->chan_info_5g;

    for (uc_index = 0; uc_index < g_scan_chan_num_max; uc_index++) {
        uc_chan_idx = g_scan_chan_list[uc_index];
        oam_warning_log3(0, OAM_SF_SCAN, "{HiD2D results: channel[%d], avg chan_load is %d, avg noise rssi is %d}",
            g_aus_channel_candidate_list_5g[uc_chan_idx].uc_chan_number,
            pst_chan_info[uc_chan_idx].chan_load, pst_chan_info[uc_chan_idx].chan_noise_rssi);
        if (pst_chan_info[uc_chan_idx].chan_load > highest_chan_load) {
            highest_chan_load = pst_chan_info[uc_chan_idx].chan_load;
            best_chan_of_chan_load = uc_chan_idx;
        }
        if (pst_chan_info[uc_chan_idx].chan_noise_rssi < lowest_noise_rssi) {
            lowest_noise_rssi = pst_chan_info[uc_chan_idx].chan_noise_rssi;
            best_chan_of_noise_rssi = uc_chan_idx;
        }
    }
    /* 分别按照占空比最高和底噪最小选择了信道A和信道B */
    /* 如果信道A和信道B是一个信道，则就report该信道，否则优先选择占空比最高的信道A，除非信道B的占空比略小于A，
        但底噪比A低5dB以上 */
    if (best_chan_of_chan_load == best_chan_of_noise_rssi) {
        uc_chan_idx = best_chan_of_chan_load;
    } else if ((highest_chan_load - pst_chan_info[best_chan_of_noise_rssi].chan_load < HMAC_HID2D_CHAN_LOAD_DIFF)
        && (pst_chan_info[best_chan_of_chan_load].chan_noise_rssi - lowest_noise_rssi > HMAC_HID2D_NOISE_DIFF)) {
        uc_chan_idx = best_chan_of_noise_rssi;
    } else {
        uc_chan_idx = best_chan_of_chan_load;
    }
    pst_scan_chan->en_band = WLAN_BAND_5G;
    pst_scan_chan->uc_chan_number = g_aus_channel_candidate_list_5g[uc_chan_idx].uc_chan_number;
    pst_scan_chan->en_bandwidth = g_aus_channel_candidate_list_5g[uc_chan_idx].en_bandwidth;
    pst_scan_chan->uc_chan_idx = g_aus_channel_candidate_list_5g[uc_chan_idx].uc_chan_idx;
    oam_warning_log2(0, OAM_SF_SCAN, "{HiD2D results: best channel num is %d, bw is %d}",
        pst_scan_chan->uc_chan_number, pst_scan_chan->en_bandwidth);

    return OAL_SUCC;
}

/*
 * 函 数 名  : hmac_hid2d_scan_complete_handler
 * 功能描述  : 信道测量结果上报到hmac后的处理函数
 * 1.日    期  : 2020年3月18日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_hid2d_scan_complete_handler(hmac_vap_stru *hmac_vap, wlan_scan_chan_stats_stru *chan_result)
{
    hmac_hid2d_auto_channel_switch_stru *pst_hmac_hid2d_acs_info = NULL;
    uint32_t ret = OAL_SUCC;

    if ((hmac_vap == NULL) || (chan_result == NULL)) {
        return OAL_ERR_CODE_PTR_NULL;
    }
    pst_hmac_hid2d_acs_info = &g_st_hmac_hid2d_acs_info;
    if (pst_hmac_hid2d_acs_info->uc_acs_mode) {
        oam_warning_log0(0, OAM_SF_SCAN, "hmac_hid2d_scan_complete_handler: acs enabled");
        ret = hmac_hid2d_acs_scan_handler(hmac_vap, chan_result, pst_hmac_hid2d_acs_info);
    } else if (pst_hmac_hid2d_acs_info->scan_mode == HMAC_HID2D_ONCE_SCAN) {
        ret = hmac_hid2d_acs_once_scan_handler(hmac_vap, chan_result, pst_hmac_hid2d_acs_info);
    }

    return ret;
}

/*
 * 功能描述  : 根据信道号、带宽得到其在全局待选信道中的序号
 * 修改历史
 * 1.日    期  : 2020年4月22日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint16_t hmac_hid2d_get_idx_from_chan_num(uint8_t band, uint8_t channel_num, uint8_t bw)
{
    uint8_t channel_idx = 0;
    uint8_t idx;
    hmac_hid2d_chan_stru *candidate_list = NULL;
    uint8_t total_num;

    if (band == WLAN_BAND_2G) {
        candidate_list = g_aus_channel_candidate_list_2g;
        total_num = HMAC_HID2D_CHANNEL_NUM_2G;
    } else {
        candidate_list = g_aus_channel_candidate_list_5g;
        total_num = HMAC_HID2D_CHANNEL_NUM_5G;
    }

    for (idx = 0; idx < total_num; idx++) {
        if (candidate_list[idx].uc_chan_number == channel_num &&
            candidate_list[idx].en_bandwidth == bw) {
            channel_idx = idx;
        }
    }

    return channel_idx;
}

/*
 * 功能描述  : 根据信道号、带宽(802.11)得到其在带宽模式
 * 日    期  : 2021年4月22日
 * 作    者  : wifi
 */
uint8_t hmac_hid2d_bw_mode_convert(uint8_t band, uint8_t channel_num, uint8_t bw)
{
    uint8_t idx, bandwidth;
    hmac_hid2d_chan_stru *candidate_list = NULL;
    uint8_t total_num;

    if (band == WLAN_BAND_2G) {
        candidate_list = g_aus_channel_candidate_list_2g;
        total_num = HMAC_HID2D_CHANNEL_NUM_2G;
    } else {
        candidate_list = g_aus_channel_candidate_list_5g;
        total_num = HMAC_HID2D_CHANNEL_NUM_5G;
    }

    bandwidth = WLAN_BAND_WIDTH_20M;
    for (idx = 0; idx < total_num; idx++) {
        if (candidate_list[idx].uc_chan_number == channel_num) {
            bandwidth = candidate_list[idx].en_bandwidth;
            if (bw == (oal_nl80211_chan_width)wlan_bandwidth_to_ieee_chan_width(bandwidth, OAL_TRUE)) {
                break;
            }
        }
    }

    return bandwidth;
}

/*
 * 功能描述  : 获取可支持的信道列表
 * 修改历史
 * 1.日    期  : 2020年4月20日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_hid2d_get_valid_2g_channel_list(void)
{
    uint8_t *scan_chan_list = g_scan_chan_list;
    uint8_t *supp_chan_list = g_supp_chan_list;
    uint8_t max_scan_chan_num = 0;
    uint8_t max_supp_chan_num = 0;
    uint8_t idx;
    uint8_t chan_idx;
    uint8_t valid_flag1 = 0;
    uint8_t valid_flag2;

    for (idx = 0; idx < 14; idx++) { /* 2.4G上20M信道个数为14个 */
        chan_idx = g_aus_channel_candidate_list_2g[idx].uc_chan_idx;
        if (g_aus_channel_candidate_list_2g[idx].en_bandwidth == WLAN_BAND_WIDTH_20M) {
            valid_flag1 = (mac_is_channel_idx_valid(WLAN_BAND_2G, chan_idx, OAL_FALSE) == OAL_SUCC) ? 1 : 0;
        }
        if (valid_flag1) {
            supp_chan_list[max_supp_chan_num] = idx;
            max_supp_chan_num++;
        }
    }
    for (idx = 14; idx < HMAC_HID2D_CHANNEL_NUM_2G; idx++) { /* 2.4G上20M信道个数为14个 */
        chan_idx = g_aus_channel_candidate_list_2g[idx].uc_chan_idx;
        if (g_aus_channel_candidate_list_2g[idx].en_bandwidth == WLAN_BAND_WIDTH_40PLUS) {
            valid_flag1 = (mac_is_channel_idx_valid(WLAN_BAND_2G, chan_idx, OAL_FALSE) == OAL_SUCC) ? 1 : 0;
            valid_flag2 = (mac_is_channel_idx_valid(WLAN_BAND_2G,
                chan_idx + 4, OAL_FALSE) == OAL_SUCC) ? 1 : 0; /* idx+4信道号 */
        } else {
            valid_flag1 = (mac_is_channel_idx_valid(WLAN_BAND_2G, chan_idx, OAL_FALSE) == OAL_SUCC) ? 1 : 0;
            valid_flag2 = (mac_is_channel_idx_valid(WLAN_BAND_2G,
                chan_idx - 4, OAL_FALSE) == OAL_SUCC) ? 1 : 0; /* idx-4信道号 */
        }
        if (valid_flag1 && valid_flag2) {
            supp_chan_list[max_supp_chan_num] = idx;
            max_supp_chan_num++;
            scan_chan_list[max_scan_chan_num] = idx;
            max_scan_chan_num++;
        }
    }
    g_supp_chan_num_max = max_supp_chan_num;
    g_scan_chan_num_max = max_scan_chan_num;
    return OAL_SUCC;
}

/*
 * 功能描述  : 判断是否是待选信道
 * 修改历史
 * 1.日    期  : 2020年4月20日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint8_t hmac_hid2d_is_valid_5g_channel(uint8_t idx)
{
    uint8_t chan_idx;
    uint8_t valid, dfs;
    uint8_t valid_flag;

    if (idx >= HMAC_HID2D_CHANNEL_NUM_5G) {
        oam_warning_log1(0, 0, "hmac_hid2d_is_valid_5g_channel:: idx[%d] is invalid.", idx);
        return OAL_FALSE;
    }
    chan_idx = g_aus_channel_candidate_list_5g[idx].uc_chan_idx;
    valid = (uint8_t)mac_is_channel_idx_valid(WLAN_BAND_5G, chan_idx, OAL_FALSE);
    dfs = mac_is_dfs_channel(WLAN_BAND_5G, g_aus_channel_candidate_list_5g[idx].uc_chan_number);
    valid_flag = (valid == OAL_SUCC && dfs == OAL_FALSE) ? 1 : 0;
    return valid_flag;
}

/*
 * 功能描述  : 获取可支持的信道列表
 * 1.日    期  : 2020年4月20日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_hid2d_get_valid_5g_channel_list(void)
{
    uint8_t *scan_chan_list = g_scan_chan_list;
    uint8_t *supp_chan_list = g_supp_chan_list;
    uint8_t max_scan_chan_num = 0;
    uint8_t max_supp_chan_num = 0;
    uint8_t idx, k;
    uint8_t valid_flag[HMAC_HID2D_MAX_CHANNELS];
    uint8_t cnt;

    idx = 0;
    while (idx < HMAC_HID2D_CHANNEL_NUM_5G - 1) {
        for (k = 0; k < HMAC_HID2D_MAX_CHANNELS; k++) {
            valid_flag[k] = hmac_hid2d_is_valid_5g_channel(idx + k);
            if (valid_flag[k] == OAL_TRUE) {
                supp_chan_list[max_supp_chan_num++] = idx + k;
            }
        }
        idx = idx + HMAC_HID2D_MAX_CHANNELS;
        if (valid_flag[0] && valid_flag[1]) {
            supp_chan_list[max_supp_chan_num++] = idx++;
            supp_chan_list[max_supp_chan_num++] = idx++;
        }
        if (valid_flag[2] && valid_flag[3]) { /* 查看80M信道中后40M信道(序号2、3)是否可用 */
            supp_chan_list[max_supp_chan_num++] = idx++;
            supp_chan_list[max_supp_chan_num++] = idx++;
        }
        if (valid_flag[0] && valid_flag[1] && valid_flag[2] && valid_flag[3]) { /* 查看各20M信道(0, 1, 2, 3)是否可用 */
            scan_chan_list[max_scan_chan_num++] = idx;
            supp_chan_list[max_supp_chan_num++] = idx++;
            supp_chan_list[max_supp_chan_num++] = idx++;
            supp_chan_list[max_supp_chan_num++] = idx++;
            supp_chan_list[max_supp_chan_num++] = idx++;
        }
    }
    cnt = max_scan_chan_num;
    for (k = 0; k < cnt; k++) {
        scan_chan_list[cnt + k] = scan_chan_list[k] + 1; /* 添加次20M为主信道的80M信道 */
        scan_chan_list[cnt * 2 + k] = scan_chan_list[k] + 2; /* 添加以第3个20M(序号2)为主信道的80M信道 */
        scan_chan_list[cnt * 3 + k] = scan_chan_list[k] + 3; /* 添加以第4个20M(序号3)为主信道的80M信道 */
        max_scan_chan_num = max_scan_chan_num + 3; /* 本轮添加了3个扫描信道 */
    }
    /* 对于165信道的特殊处理 */
    valid_flag[0] = hmac_hid2d_is_valid_5g_channel(idx);
    if (valid_flag[0] == OAL_TRUE) {
        supp_chan_list[max_supp_chan_num++] = idx;
        scan_chan_list[max_scan_chan_num++] = idx;
    }
    g_supp_chan_num_max = max_supp_chan_num;
    g_scan_chan_num_max = max_scan_chan_num;
    return OAL_SUCC;
}

/*
 * 功能描述  : 判断设备是否处于单P2P或者DBDC状态
 * 修改历史
 * 1.日    期  : 2020年4月20日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
hmac_hid2d_net_mode_enum hmac_hid2d_check_vap_state(mac_vap_stru *mac_vap, mac_device_stru *mac_device)
{
    hmac_hid2d_net_mode_enum state;
    uint8_t is_dbdc;
    uint8_t is_only_p2p;
    mac_vap_stru *another_vap = NULL;

    /* 判断当前vap是否是GO，如果不是则直接退出 */
    if (mac_vap->en_p2p_mode != WLAN_P2P_GO_MODE) {
        return HMAC_HID2D_NET_MODE_BUTT;
    }

    /* 判断是否存在另一个up的vap */
    another_vap = mac_vap_find_another_up_vap_by_mac_vap(mac_vap);
    /* 如果能找到除了p2p vap之外的up的vap，说明不是单p2p */
    is_only_p2p = (another_vap == NULL) ? OAL_TRUE : OAL_FALSE;
    is_dbdc = mac_is_dbdc_running(mac_device);
    if (is_only_p2p) {
        state = HMAC_HID2D_P2P_ONLY;
    } else if (is_dbdc) {
        state = HMAC_HID2D_DBDC;
    } else {
        state = HMAC_HID2D_SAME_BAND;
    }
    return state;
}

/*
 * 功能描述  : 获取当前需要扫描的信道
 * 1.日    期  : 2020年4月22日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint8_t hmac_hid2d_get_next_scan_channel(hmac_hid2d_auto_channel_switch_stru *hmac_hid2d_acs_info)
{
    uint8_t next_chan_idx;

    /* 第一次触发扫描，直接返回0 */
    if (hmac_hid2d_acs_info->uc_cur_scan_chan_idx == g_scan_chan_num_max) {
        hmac_hid2d_acs_info->uc_cur_scan_chan_idx = 0;
        return 0;
    }
    /* 先获取上次扫描的信道在g_scan_chan_list中的idx，然后加1获取本次应该扫描的信道idx */
    next_chan_idx = (hmac_hid2d_acs_info->uc_cur_scan_chan_idx + 1) % g_scan_chan_num_max;
    /* 判断是否是当前信道，如果是当前信道则直接跳过 */
    /* 当前先判断当前信道是否与扫描信道严格一致
       如果当前信道为20M/40M，芯片上报的40M/80M信息有效将判断条件改为扫描信道是否包含当前信道 */
    if (hmac_hid2d_acs_info->uc_cur_chan_idx == g_scan_chan_list[next_chan_idx]) {
        next_chan_idx = (next_chan_idx + 1) % g_scan_chan_num_max;
    }
    hmac_hid2d_acs_info->uc_cur_scan_chan_idx = next_chan_idx;
    return next_chan_idx;
}

/*
 * 功能描述  : 销毁定时器
 * 修改历史
 * 1.日    期  : 2020年4月26日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void hmac_hid2d_acs_destroy_timer(hmac_hid2d_auto_channel_switch_stru *hmac_hid2d_acs_info)
{
    if (hmac_hid2d_acs_info->st_chan_stat_report_timer.en_is_registerd == OAL_TRUE) {
        frw_timer_immediate_destroy_timer_m(&(hmac_hid2d_acs_info->st_chan_stat_report_timer));
    }
    if (hmac_hid2d_acs_info->st_scan_chan_timer.en_is_registerd == OAL_TRUE) {
        frw_timer_immediate_destroy_timer_m(&(hmac_hid2d_acs_info->st_scan_chan_timer));
    }
}

/*
 * 功能描述  : ACS方案初始化参数设置
 * 修改历史
 * 1.日    期  : 2020年4月26日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void hmac_hid2d_acs_init_params(hmac_hid2d_auto_channel_switch_stru *hmac_hid2d_acs_info, mac_vap_stru *p2p_vap)
{
    hmac_hid2d_acs_destroy_timer(hmac_hid2d_acs_info);
    memset_s(hmac_hid2d_acs_info, sizeof(hmac_hid2d_auto_channel_switch_stru),
        0, sizeof(hmac_hid2d_auto_channel_switch_stru));
    hmac_hid2d_acs_info->uc_acs_mode = OAL_TRUE;
    hmac_hid2d_acs_info->uc_vap_id = p2p_vap->uc_vap_id;
    hmac_hid2d_acs_info->uc_cur_band = p2p_vap->st_channel.en_band;
    if (hmac_hid2d_acs_info->uc_cur_band == WLAN_BAND_2G) {
        hmac_hid2d_acs_info->candidate_list = g_aus_channel_candidate_list_2g;
        hmac_hid2d_get_valid_2g_channel_list();
    } else {
        hmac_hid2d_acs_info->candidate_list = g_aus_channel_candidate_list_5g;
        hmac_hid2d_get_valid_5g_channel_list();
    }
    hmac_hid2d_acs_info->uc_cur_chan_idx = hmac_hid2d_get_idx_from_chan_num(p2p_vap->st_channel.en_band,
        p2p_vap->st_channel.uc_chan_number, p2p_vap->st_channel.en_bandwidth);
    hmac_hid2d_acs_info->uc_cur_scan_chan_idx = g_scan_chan_num_max;
    hmac_hid2d_acs_info->scan_chan_idx = HMAC_HID2D_CHANNEL_NUM_5G;
    hmac_hid2d_acs_info->scan_time = HMAC_HID2D_SCAN_TIME_PER_CHAN_ACS;
}

/*
 * 功能描述  : ACS方案退出前处理:销毁定时器，上报CHR，同步状态给dmac
 * 修改历史
 * 1.日    期  : 2020年4月26日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void hmac_hid2d_acs_exit(hmac_hid2d_auto_channel_switch_stru *hmac_hid2d_acs_info, mac_vap_stru *p2p_vap,
    uint8_t exit_type)
{
    uint32_t ret;
    uint8_t acs_mode;
    hmac_vap_stru *hmac_vap = NULL;
    hmac_hid2d_acs_init_report_stru acs_init_report;
    hmac_hid2d_acs_exit_report_stru acs_exit_report;

    hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(p2p_vap->uc_vap_id);
    if (hmac_vap == NULL) {
        return;
    }
    if (exit_type == HMAC_HID2D_NON_GO) {
        acs_init_report.acs_info_type = HMAC_HID2D_INIT_REPORT;
        acs_init_report.acs_exit_type = HMAC_HID2D_NON_GO;
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
        oal_cfg80211_hid2d_acs_report(hmac_vap->pst_net_device, GFP_KERNEL, (uint8_t *)(&acs_init_report),
            sizeof(acs_init_report));
#endif
        return;
    } else if (exit_type != HMAC_HID2D_FWK_DISABLE) {
        /* 上报内核方案退出的原因 */
        acs_exit_report.acs_info_type = HMAC_HID2D_EXTI_REPORT;
        acs_exit_report.acs_exit_type = exit_type;
        oam_warning_log1(0, OAM_SF_ANY, "HiD2D ACS: exit and report to hal, exit type[%d].", exit_type);
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
        oal_cfg80211_hid2d_acs_report(hmac_vap->pst_net_device, GFP_KERNEL,
            (uint8_t *)(&acs_exit_report), sizeof(acs_exit_report));
#endif
    }

    /* 注销定时器 */
    hmac_hid2d_acs_destroy_timer(hmac_hid2d_acs_info);
    /* 将状态同步给dmac */
    acs_mode = OAL_FALSE;
    hmac_hid2d_acs_info->uc_acs_mode = acs_mode;
    hmac_hid2d_acs_info->acs_state = HMAC_HID2D_ACS_DISABLE;
    ret = hmac_config_send_event(p2p_vap, WLAN_CFGID_HID2D_ACS_MODE, sizeof(uint8_t), &acs_mode);
    if (oal_unlikely(ret != OAL_SUCC)) {
        return;
    }
}

/*
 * 函 数 名  : hmac_hid2d_init_report
 * 功能描述  : 上报初始化参数
 * 修改历史
 * 1.日    期  : 2020年10月20日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void hmac_hid2d_init_report(hmac_hid2d_auto_channel_switch_stru *hmac_hid2d_acs_info, mac_vap_stru *p2p_vap,
    mac_device_stru *mac_device)
{
    hmac_hid2d_acs_init_report_stru acs_init_report;
    hmac_vap_stru *hmac_vap = NULL;
    int32_t ret;

    hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(p2p_vap->uc_vap_id);
    if (hmac_vap == NULL) {
        return;
    }
    acs_init_report.acs_info_type = HMAC_HID2D_INIT_REPORT;
    acs_init_report.cur_band = hmac_hid2d_acs_info->uc_cur_band;
    acs_init_report.chan_number = p2p_vap->st_channel.uc_chan_number;
    acs_init_report.bandwidth = p2p_vap->st_channel.en_bandwidth;
    acs_init_report.go_mode = hmac_hid2d_check_vap_state(p2p_vap, mac_device);
    ret = memcpy_s(acs_init_report.supp_chan_list, sizeof(uint8_t) * HMAC_HID2D_CHANNEL_NUM_5G,
        g_supp_chan_list, sizeof(uint8_t) * g_supp_chan_num_max);
    acs_init_report.supp_chan_num_max = g_supp_chan_num_max;
    ret += memcpy_s(acs_init_report.scan_chan_list, sizeof(uint8_t) * HMAC_HID2D_CHANNEL_NUM_5G,
        g_supp_chan_list, sizeof(uint8_t) * g_scan_chan_num_max);
    if (ret != EOK) {
        oam_warning_log1(0, 0, "{hmac_hid2d_init_report::memcpy fail, ret[%d].}", ret);
    }
    acs_init_report.scan_chan_num_max = g_scan_chan_num_max;

#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    /* 上报内核 */
    oal_cfg80211_hid2d_acs_report(hmac_vap->pst_net_device, GFP_KERNEL,
        (uint8_t *)(&acs_init_report), sizeof(acs_init_report));
#endif
}

/*
 * 函 数 名  : hmac_hid2d_set_acs_mode
 * 功能描述  : HiD2D场景下开启或者关闭自动信道切换
 * 修改历史
 * 1.日    期  : 2020年10月20日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_hid2d_set_acs_mode(mac_vap_stru *mac_vap, uint8_t acs_mode)
{
    hmac_hid2d_auto_channel_switch_stru *hmac_hid2d_acs_info = &g_st_hmac_hid2d_acs_info;
    mac_device_stru *mac_device = NULL;
    mac_vap_stru *p2p_vap = NULL;
    uint32_t ret;

    oam_warning_log1(0, 0, "{hmac_hid2d_set_acs_mode: %d", acs_mode);

    /* 找到对应的P2P vap并判断是否是GO，不是则直接返回 */
    mac_device = mac_res_get_dev(mac_vap->uc_device_id);
    if (mac_device == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }
    ret = hmac_hid2d_find_up_p2p_vap(mac_device, (mac_vap_stru **)&p2p_vap);
    if (ret != OAL_SUCC) {
        hmac_hid2d_acs_exit(hmac_hid2d_acs_info, p2p_vap, HMAC_HID2D_P2P_LOST);
        return ret;
    }
    if (!is_p2p_go(p2p_vap)) {
        hmac_hid2d_acs_exit(hmac_hid2d_acs_info, p2p_vap, HMAC_HID2D_NON_GO);
        return OAL_SUCC;
    }

    if (acs_mode == OAL_FALSE) {
        hmac_hid2d_acs_exit(hmac_hid2d_acs_info, p2p_vap, HMAC_HID2D_FWK_DISABLE);
        return OAL_SUCC;
    }

    /* 初始化 */
    hmac_hid2d_acs_init_params(hmac_hid2d_acs_info, p2p_vap);
    /* 上传信息到hal层 */
    hmac_hid2d_init_report(hmac_hid2d_acs_info, p2p_vap, mac_device);

    /* 同步该状态到dmac层 */
    ret = hmac_config_send_event(p2p_vap, WLAN_CFGID_HID2D_ACS_MODE, sizeof(uint8_t), &acs_mode);
    if (oal_unlikely(ret != OAL_SUCC)) {
        oam_warning_log1(p2p_vap->uc_vap_id, 0, "HiD2D ACS: send hid2d acs mode to dmac failed[%d].", ret);
        return ret;
    }
    /* 开启dmac上报超时定时器(60s) */
    frw_timer_create_timer_m(&hmac_hid2d_acs_info->st_chan_stat_report_timer,
        hmac_hid2d_chan_stat_report_timeout_handle, HMAC_HID2D_REPORT_TIMEOUT_MS,
        mac_device, OAL_FALSE, OAM_MODULE_ID_HMAC, mac_device->core_id);

    return OAL_SUCC;
}

uint32_t hmac_hid2d_update_acs_state(mac_vap_stru *mac_vap, uint16_t len, uint8_t *param)
{
    hmac_hid2d_auto_channel_switch_stru *hmac_hid2d_acs_info = NULL;

    oam_warning_log1(0, OAM_SF_ANY, "HiD2D ACS: acs state updated to [%d].", *param);
    hmac_hid2d_acs_info = &g_st_hmac_hid2d_acs_info;
    hmac_hid2d_acs_info->acs_state = *param;
    return OAL_SUCC;
}

uint32_t hmac_hid2d_link_meas(mac_vap_stru *mac_vap, uint16_t len, uint8_t *param)
{
    mac_device_stru *mac_device = NULL;
    mac_hid2d_link_meas_stru *hid2d_meas_cmd = NULL;
    hmac_hid2d_auto_channel_switch_stru *hmac_hid2d_acs_info = NULL;

    mac_device = mac_res_get_dev(mac_vap->uc_device_id);
    if (mac_device == NULL) {
        return OAL_SUCC;
    }
    hmac_hid2d_acs_info = &g_st_hmac_hid2d_acs_info;
    hid2d_meas_cmd = (mac_hid2d_link_meas_stru *)param;

    if (hid2d_meas_cmd->link_meas_cmd_type == HMAC_HID2D_LINK_MEAS_START_BY_CHAN_LIST) {
        hmac_hid2d_acs_info->scan_mode = HMAC_HID2D_ACS_SCAN;
        hmac_hid2d_acs_info->scan_time = hid2d_meas_cmd->meas_time;
        hmac_hid2d_acs_info->scan_interval = hid2d_meas_cmd->scan_interval;
        oam_warning_log2(0, OAM_SF_ANY, "HiD2D ACS: start link measurement by default scan list, scan time[%u]ms, \
            scan interval[%u]s.", hmac_hid2d_acs_info->scan_time, hmac_hid2d_acs_info->scan_interval);
        frw_timer_create_timer_m(&hmac_hid2d_acs_info->st_scan_chan_timer,
            hmac_hid2d_acs_timeout_handle,
            HMAC_HID2D_SCAN_TIMER_CYCLE_MS * hmac_hid2d_acs_info->scan_interval,
            mac_device, OAL_FALSE, OAM_MODULE_ID_HMAC, mac_device->core_id);
    } else if (hid2d_meas_cmd->link_meas_cmd_type == HMAC_HID2D_LINK_MEAS_UPDATE_SCAN_INTERVAL) {
        hmac_hid2d_acs_info->scan_mode = HMAC_HID2D_ACS_SCAN;
        hmac_hid2d_acs_info->scan_interval = hid2d_meas_cmd->scan_interval;
        oam_warning_log1(0, OAM_SF_ANY, "HiD2D ACS: update scan interval[%u]s.", hmac_hid2d_acs_info->scan_interval);
        if (hmac_hid2d_acs_info->st_scan_chan_timer.en_is_registerd == OAL_TRUE) {
            frw_timer_immediate_destroy_timer_m(&(hmac_hid2d_acs_info->st_scan_chan_timer));
        }
        frw_timer_create_timer_m(&hmac_hid2d_acs_info->st_scan_chan_timer, hmac_hid2d_acs_timeout_handle,
            HMAC_HID2D_SCAN_TIMER_CYCLE_MS * hmac_hid2d_acs_info->scan_interval,
            mac_device, OAL_FALSE, OAM_MODULE_ID_HMAC, mac_device->core_id);
    } else if (hid2d_meas_cmd->link_meas_cmd_type == HMAC_HID2D_LINK_MEAS_UPDATE_SCAN_TIME) {
        hmac_hid2d_acs_info->scan_mode = HMAC_HID2D_ACS_SCAN;
        hmac_hid2d_acs_info->scan_time = hid2d_meas_cmd->meas_time;
        oam_warning_log1(0, OAM_SF_ANY, "HiD2D ACS: update scan time[%u]ms.", hmac_hid2d_acs_info->scan_time);
    } else if (hid2d_meas_cmd->link_meas_cmd_type == HMAC_HID2D_LINK_MEAS_START_BY_CHAN) {
        if (hmac_hid2d_acs_info->uc_acs_mode == OAL_TRUE) {
            oam_warning_log0(0, OAM_SF_ANY, "HiD2D ACS: acs enabled, not support link measurement.");
            return OAL_FAIL;
        }
        hmac_hid2d_acs_info->scan_mode = HMAC_HID2D_ONCE_SCAN;
        hmac_hid2d_acs_info->scan_chan_idx = hid2d_meas_cmd->scan_chan;
        hmac_hid2d_acs_info->scan_time = hid2d_meas_cmd->meas_time;
        hmac_hid2d_acs_info->scan_band = hid2d_meas_cmd->scan_band;
        oam_warning_log2(0, OAM_SF_ANY, "HiD2D ACS: scan channel idx[%d] once for [%u]ms.",
            hmac_hid2d_acs_info->scan_chan_idx, hmac_hid2d_acs_info->scan_time);
        hmac_hid2d_h2d_link_meas_cmd(mac_vap, hmac_hid2d_acs_info->scan_chan_idx, HMAC_HID2D_ONCE_SCAN);
    }

    return OAL_SUCC;
}

/*
 * 函 数 名  : hmac_hid2d_acs_timeout_handle
 * 功能描述  : 定时器到期处理函数，判断是否要发起下一次扫描
 * 修改历史
 * 1.日    期  : 2020年04月24日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_hid2d_acs_timeout_handle(void *arg)
{
    mac_device_stru *mac_device = (mac_device_stru *)arg;
    mac_vap_stru *p2p_vap = NULL;
    hmac_hid2d_auto_channel_switch_stru *hmac_hid2d_acs_info = &g_st_hmac_hid2d_acs_info;
    uint8_t next_chan_idx;
    uint8_t next_scan_chan;
    uint32_t ret;

    if (mac_device == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }
    ret = hmac_hid2d_find_up_p2p_vap(mac_device, (mac_vap_stru **)&p2p_vap);
    if (ret != OAL_SUCC) {
        /* P2P 断链, 退出方案 */
        hmac_hid2d_acs_exit(hmac_hid2d_acs_info, p2p_vap, HMAC_HID2D_P2P_LOST);
        return ret;
    }

    if (hmac_hid2d_acs_info->acs_state == HMAC_HID2D_ACS_DISABLE) {
        return OAL_SUCC;
    } else if (hmac_hid2d_acs_info->acs_state == HMAC_HID2D_ACS_WORK) {
        next_chan_idx = hmac_hid2d_get_next_scan_channel(hmac_hid2d_acs_info);
        next_scan_chan = g_scan_chan_list[next_chan_idx];
        hmac_hid2d_h2d_link_meas_cmd(p2p_vap, next_scan_chan, HMAC_HID2D_ACS_SCAN);
    }
    /* 开启下一次扫描的定时器 */
    frw_timer_create_timer_m(&hmac_hid2d_acs_info->st_scan_chan_timer,
        hmac_hid2d_acs_timeout_handle,
        HMAC_HID2D_SCAN_TIMER_CYCLE_MS * hmac_hid2d_acs_info->scan_interval,
        mac_device,
        OAL_FALSE,
        OAM_MODULE_ID_HMAC,
        mac_device->core_id);
    return OAL_SUCC;
}

static void hmac_hid2d_pack_chan_stat_report_info(wlan_scan_chan_stats_stru *chan_result,
    hmac_hid2d_chan_stat_report_stru *info, uint8_t scan_chan_sbs, uint8_t scan_chan_idx)
{
    info->acs_info_type = HMAC_HID2D_CHAN_STAT_REPORT;
    info->scan_chan_sbs = scan_chan_sbs;
    info->scan_chan_idx = scan_chan_idx;
    info->total_free_time_20m_us = chan_result->total_free_time_20m_us;
    info->total_free_time_40m_us = chan_result->total_free_time_40m_us;
    info->total_free_time_80m_us = chan_result->total_free_time_80m_us;
    info->total_send_time_us = chan_result->total_send_time_us;
    info->total_recv_time_us = chan_result->total_recv_time_us;
    info->total_stats_time_us = chan_result->total_stats_time_us;
    info->free_power_cnt = chan_result->uc_free_power_cnt;
    info->free_power_stats_20m = chan_result->free_power_stats_20m;
    info->free_power_stats_40m = chan_result->free_power_stats_40m;
    info->free_power_stats_80m = chan_result->free_power_stats_80m;
    info->free_power_stats_160m = chan_result->free_power_stats_160m;
}

/*
 * 函 数 名  : hmac_hid2d_acs_scan_handler
 * 功能描述  : HiD2D ACS算法对扫描上报结果的处理
 * 修改历史
 * 1.日    期  : 2020年4月22日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC uint32_t hmac_hid2d_acs_scan_handler(hmac_vap_stru *hmac_vap, wlan_scan_chan_stats_stru *chan_result,
    hmac_hid2d_auto_channel_switch_stru *hmac_hid2d_acs_info)
{
    hmac_hid2d_chan_stru *candidate_chan_list = NULL;
    hmac_hid2d_chan_stat_report_stru chan_stats_report;
    uint8_t channel_number;
    uint8_t channel_idx;

    /* 获取当前上报的信息信息 */
    channel_number = chan_result->uc_channel_number;
    candidate_chan_list = hmac_hid2d_acs_info->candidate_list;
    if (hmac_hid2d_acs_info->scan_chan_idx < HMAC_HID2D_CHANNEL_NUM_5G) {
        channel_idx = hmac_hid2d_acs_info->scan_chan_idx;
    } else {
        channel_idx = g_scan_chan_list[hmac_hid2d_acs_info->uc_cur_scan_chan_idx];
    }
    /* 判断上报的信道与下发扫描的信道是否一致 */
    if (channel_number != candidate_chan_list[channel_idx].uc_chan_number) {
        oam_warning_log2(0, 0, "HiD2D ACS: channel not match, scan chan is [%d], report chan is [%d]!",
            candidate_chan_list[channel_idx].uc_chan_number, channel_number);
        return OAL_FAIL;
    }
    /* 上报信息 */
    hmac_hid2d_pack_chan_stat_report_info(chan_result, &chan_stats_report,
        hmac_hid2d_acs_info->scan_chan_idx, channel_idx);
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    oal_cfg80211_hid2d_acs_report(hmac_vap->pst_net_device, GFP_KERNEL,
        (uint8_t *)(&chan_stats_report), sizeof(chan_stats_report));
#endif
    return OAL_SUCC;
}

OAL_STATIC uint32_t hmac_hid2d_acs_once_scan_handler(hmac_vap_stru *hmac_vap, wlan_scan_chan_stats_stru *chan_result,
    hmac_hid2d_auto_channel_switch_stru *hmac_hid2d_acs_info)
{
    hmac_hid2d_chan_stat_report_stru chan_stats_report;

    /* 上报信息 */
    hmac_hid2d_pack_chan_stat_report_info(chan_result, &chan_stats_report,
        hmac_hid2d_acs_info->scan_chan_idx, hmac_hid2d_acs_info->scan_chan_idx);
#ifdef _PRE_WLAN_CHBA_MGMT
    if (hmac_vap->st_vap_base_info.chba_mode != CHBA_MODE || (hmac_vap->st_vap_base_info.chba_mode == CHBA_MODE &&
        hmac_vap->hmac_chba_vap_info->chba_log_level == CHBA_DEBUG_ALL_LOG)) {
#endif
        oam_warning_log3(hmac_vap->st_vap_base_info.uc_vap_id, 0,
            "HiD2D ACS: report_chan_num=[%d], report_chan_idx=[%d], scan_chan_sbs=[%d]",
            chan_result->uc_channel_number, chan_stats_report.scan_chan_idx, chan_stats_report.scan_chan_sbs);

        oam_warning_log3(0, 0, "HiD2D ACS: free_time_20m_us=[%d], free_time_40m_us=[%d], \
            free_time_80m_us=[%d]", chan_stats_report.total_free_time_20m_us,
            chan_stats_report.total_free_time_40m_us, chan_stats_report.total_free_time_80m_us);

        oam_warning_log4(0, 0, "HiD2D ACS: send_time_us=%d, recv_time_us=[%d], stats_time_us=[%d], free_power_cnt=[%d]",
            chan_stats_report.total_send_time_us, chan_stats_report.total_recv_time_us,
            chan_stats_report.total_stats_time_us, chan_stats_report.free_power_cnt);

        oam_warning_log4(0, 0, "HiD2D ACS: free_power_stats_20m=[%d], free_power_stats_40m=[%d], \
            free_power_stats_80m=[%d], free_power_stats_160m=[%d]",
            chan_stats_report.free_power_stats_20m, chan_stats_report.free_power_stats_40m,
            chan_stats_report.free_power_stats_80m, chan_stats_report.free_power_stats_160m);
#ifdef _PRE_WLAN_CHBA_MGMT
    }
#endif
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    oal_cfg80211_hid2d_acs_report(hmac_vap->pst_net_device, GFP_KERNEL,
        (uint8_t *)(&chan_stats_report), sizeof(chan_stats_report));
#endif
    return OAL_SUCC;
}

/*
 * 函 数 名  : hmac_hid2d_acs_switch_completed
 * 功能描述  : 信道切换成功事件处理
 * 修改历史
 * 1.日    期  : 2020年5月19日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void hmac_hid2d_acs_switch_completed(mac_vap_stru *mac_vap)
{
    hmac_hid2d_auto_channel_switch_stru *hmac_hid2d_acs_info = NULL;
    hmac_hid2d_switch_report_stru switch_info;
    hmac_vap_stru *hmac_vap = NULL;

    hmac_hid2d_acs_info = &g_st_hmac_hid2d_acs_info;

    if (mac_vap->en_p2p_mode != WLAN_P2P_GO_MODE || hmac_hid2d_acs_info->uc_acs_mode != OAL_TRUE) {
        return;
    }
    hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(mac_vap->uc_vap_id);
    if (hmac_vap == NULL) {
        return;
    }

    /* 将切换后的信道和带宽信息上报内核 */
    oam_warning_log0(0, OAM_SF_FRW, "HiD2D ACS: switch completed, report to hal.\n");
    switch_info.acs_info_type = HMAC_HID2D_SWITCH_SUCC_REPORT;
    switch_info.chan_number = mac_vap->st_channel.uc_chan_number;
    switch_info.bandwidth = mac_vap->st_channel.en_bandwidth;
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    oal_cfg80211_hid2d_acs_report(hmac_vap->pst_net_device, GFP_KERNEL,
        (uint8_t *)(&switch_info), sizeof(switch_info));
#endif

    return;
}

/*
 * 函 数 名  : hmac_hid2d_cur_chan_stat_handler
 * 功能描述  : dmac上报信息处理函数
 * 1.日    期  : 2020年04月24日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_hid2d_cur_chan_stat_handler(mac_vap_stru *mac_vap, uint8_t len, uint8_t *param)
{
    hmac_hid2d_chan_stat_stru *chan_stats = NULL;
    hmac_hid2d_auto_channel_switch_stru *hmac_hid2d_acs_info = NULL;

    mac_device_stru *mac_device = NULL;
    hmac_vap_stru *hmac_vap = NULL;
    hmac_hid2d_link_stat_report_stru link_stats;

    hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(mac_vap->uc_vap_id);
    if (hmac_vap == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }
    chan_stats = (hmac_hid2d_chan_stat_stru *)param;
    hmac_hid2d_acs_info = &g_st_hmac_hid2d_acs_info;

    mac_device = mac_res_get_dev(mac_vap->uc_device_id);
    if (mac_device == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }
    /* 先清除超时上报定时器 */
    if (hmac_hid2d_acs_info->st_chan_stat_report_timer.en_is_registerd == OAL_TRUE) {
        frw_timer_immediate_destroy_timer_m(&(hmac_hid2d_acs_info->st_chan_stat_report_timer));
    }

    /* 上报内核 */
    link_stats.acs_info_type = HMAC_HID2D_LINK_INFO_REPORT;
    link_stats.chan_number = mac_vap->st_channel.uc_chan_number;
    link_stats.bandwidth = mac_vap->st_channel.en_bandwidth;
    link_stats.go_mode = hmac_hid2d_check_vap_state(mac_vap, mac_device);
    if (link_stats.go_mode == HMAC_HID2D_NET_MODE_BUTT) {
        hmac_hid2d_acs_exit(hmac_hid2d_acs_info, mac_vap, HMAC_HID2D_P2P_LOST);
        return OAL_SUCC;
    }
    memcpy_s(&(link_stats.link_stat), sizeof(hmac_hid2d_chan_stat_stru),
        chan_stats, sizeof(hmac_hid2d_chan_stat_stru));
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    oal_cfg80211_hid2d_acs_report(hmac_vap->pst_net_device, GFP_KERNEL,
        (uint8_t *)(&link_stats), sizeof(link_stats));
#endif
    /* 开启dmac上报超时定时器 */
    frw_timer_create_timer_m(&hmac_hid2d_acs_info->st_chan_stat_report_timer,
        hmac_hid2d_chan_stat_report_timeout_handle, HMAC_HID2D_REPORT_TIMEOUT_MS,
        mac_device, OAL_FALSE, OAM_MODULE_ID_HMAC, mac_device->core_id);
    return OAL_SUCC;
}

/*
 * 函 数 名  : hmac_hid2d_chan_stat_report_timeout_handle
 * 功能描述  : dmac层上报超时处理，60s内没有下一次数据上报，认为dmac出现异常退出，关闭acs方案
 * 修改历史
 * 1.日    期  : 2020年04月25日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_hid2d_chan_stat_report_timeout_handle(void *arg)
{
    mac_device_stru *mac_device = (mac_device_stru *)arg;
    mac_vap_stru *p2p_vap = NULL;
    hmac_hid2d_auto_channel_switch_stru *hmac_hid2d_acs_info = &g_st_hmac_hid2d_acs_info;
    uint32_t ret;

    if (mac_device == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }
    ret = hmac_hid2d_find_up_p2p_vap(mac_device, (mac_vap_stru **)&p2p_vap);
    if (ret != OAL_SUCC) {
        /* P2P 断链, 退出方案 */
        hmac_hid2d_acs_exit(hmac_hid2d_acs_info, p2p_vap, HMAC_HID2D_P2P_LOST);
        return ret;
    }
    oam_warning_log0(p2p_vap->uc_vap_id, 0,
        "{HiD2D ACS: Too long to obtain the channel stats report from dmac. Disable ACS.");
    hmac_hid2d_acs_exit(hmac_hid2d_acs_info, p2p_vap, HMAC_HID2D_DMAC_REPORT_TIMEOUT);

    return OAL_SUCC;
}

#ifdef _PRE_WLAN_FEATURE_HID2D_PRESENTATION
OAL_STATIC uint32_t wal_hid2d_setcountry(oal_net_device_stru *net_dev, int8_t *param, uint8_t param_len)
{
    return wal_hipriv_setcountry(net_dev, param);
}
OAL_STATIC uint32_t wal_hid2d_set_val_cmd(oal_net_device_stru *net_dev, int8_t *param, uint8_t param_len)
{
    return wal_hipriv_set_val_cmd(net_dev, param);
}
/*
 * 函 数 名  : wal_hipriv_hid2d_presentation_init
 * 功能描述  : 适配FWK下发的命令
 * 1.日    期  : 2020年05月18日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t wal_hipriv_hid2d_presentation_init(oal_net_device_stru *net_dev, int8_t *cmd)
{
    oal_net_device_stru *hisilicon_net_dev = NULL;
    int8_t setcountry[] = {" 99"};
    int8_t fixcountry[WAL_HIPRIV_CMD_NAME_MAX_LEN] = {"hid2d_presentation"};
    uint32_t ret_type;
    int32_t ret;

    hisilicon_net_dev = wal_config_get_netdev("Hisilicon0", OAL_STRLEN("Hisilicon0"));
    if (hisilicon_net_dev == NULL) {
        oam_warning_log0(0, OAM_SF_ANY, "{HiD2D Presentation::wal_config_get_netdev return null ptr!}");
        return OAL_ERR_CODE_PTR_NULL;
    }
    /* 调用oal_dev_get_by_name后，必须调用oal_dev_put使net_dev的引用计数减一 */
    oal_dev_put(hisilicon_net_dev);
    /* 设置国家码需要使用"Hisilicon0"下命令 */
    ret_type = wal_hid2d_setcountry(hisilicon_net_dev, setcountry, sizeof(setcountry));
    if (ret_type != OAL_SUCC) {
        return ret_type;
    }
    ret = strcat_s(fixcountry, sizeof(fixcountry), cmd);
    if (ret != EOK) {
        return OAL_FAIL;
    }
    ret_type = wal_hid2d_set_val_cmd(net_dev, fixcountry, sizeof(fixcountry));
    if (ret_type != OAL_SUCC) {
        return ret_type;
    }
    return OAL_SUCC;
}

OAL_STATIC uint32_t wal_hid2d_switch_channel(oal_net_device_stru *net_dev, int8_t *param, uint8_t param_len)
{
    return wal_hipriv_hid2d_switch_channel(net_dev, param);
}
/*
 * 函 数 名  : wal_hipriv_hid2d_swchan
 * 功能描述  : 适配FWK下发的命令
 * 1.日    期  : 2020年05月18日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t wal_hipriv_hid2d_swchan(oal_net_device_stru *net_dev, int8_t *cmd)
{
    int8_t sw_cmd[WAL_HIPRIV_CMD_NAME_MAX_LEN] = {" "};
    int8_t value_cmd[WAL_HIPRIV_CMD_VALUE_MAX_LEN] = {0};
    uint32_t ret_type, value, offset;
    int32_t ret;
    uint16_t prim_chan, bw;

    /* 转化下信道与带宽然后下发命令 */
    ret_type = wal_get_cmd_one_arg(cmd, value_cmd, WAL_HIPRIV_CMD_VALUE_MAX_LEN, &offset);
    if (ret_type != OAL_SUCC) {
        return ret_type;
    }
    value = (uint32_t)oal_atoi(value_cmd);
    prim_chan = (uint16_t)(value >> 8); /* 前8位表示主信道号 */
    bw = (uint16_t)(value & 0xFF); /* 后8位表示带宽 */

    memset_s(value_cmd, sizeof(value_cmd), 0, sizeof(value_cmd));
    oal_itoa(prim_chan, value_cmd, sizeof(value_cmd));
    ret = strcat_s(sw_cmd, sizeof(sw_cmd), value_cmd);
    if (ret != EOK) {
        return OAL_FAIL;
    }
    ret = strcat_s(sw_cmd, sizeof(sw_cmd), " ");
    if (ret != EOK) {
        return OAL_FAIL;
    }
    memset_s(value_cmd, sizeof(value_cmd), 0, sizeof(value_cmd));
    oal_itoa(bw, value_cmd, sizeof(value_cmd));
    ret = strcat_s(sw_cmd, sizeof(sw_cmd), value_cmd);
    if (ret != EOK) {
        return OAL_FAIL;
    }
    ret_type = wal_hid2d_switch_channel(net_dev, sw_cmd, sizeof(sw_cmd));
    if (ret_type != OAL_SUCC) {
        return ret_type;
    }
    return OAL_SUCC;
}

/*
 * 函 数 名  : wal_hipriv_switch_channel
 * 功能描述  : HiD2D场景下GO 通过CSA 机制切换信道
 * 1.日    期  : 2020年03月10日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t wal_hipriv_hid2d_switch_channel(oal_net_device_stru *pst_net_dev, int8_t *pc_param)
{
    wal_msg_write_stru st_write_msg;
    uint32_t off_set;
    int8_t ac_name[WAL_HIPRIV_CMD_NAME_MAX_LEN] = {0};
    mac_csa_debug_stru st_csa_cfg;
    uint8_t uc_channel;
    wlan_channel_bandwidth_enum_uint8 en_bw_mode;
    int32_t l_ret;
    uint32_t ret;

    memset_s(&st_csa_cfg, sizeof(st_csa_cfg), 0, sizeof(st_csa_cfg));

    /* 获取要切换的主信道信道号 */
    ret = wal_get_cmd_one_arg(pc_param, ac_name, WAL_HIPRIV_CMD_NAME_MAX_LEN, &off_set);
    if (ret != OAL_SUCC) {
        oam_warning_log0(0, OAM_SF_ANY, "{HiD2D Presentation::get channel error, return.}");
        return ret;
    }
    pc_param += off_set;
    uc_channel = (oal_bool_enum_uint8)oal_atoi(ac_name);

    /* 获取信道带宽模式 */
    ret = wal_get_cmd_one_arg(pc_param, ac_name, WAL_HIPRIV_CMD_NAME_MAX_LEN, &off_set);
    if (ret != OAL_SUCC) {
        oam_warning_log0(0, OAM_SF_CFG, "{HiD2D Presentation::get bandwidth error, return.}");
        return ret;
    }
    ret = mac_regdomain_get_bw_mode_by_cmd(ac_name, uc_channel, &en_bw_mode);
    if (ret != OAL_SUCC) {
        return ret;
    }
    pc_param += off_set;
    st_csa_cfg.en_bandwidth = en_bw_mode;
    st_csa_cfg.uc_channel = uc_channel;

    oam_warning_log2(0, OAM_SF_CFG, "{HiD2D Presentation::switch to CH%d, BW is %d}", uc_channel, en_bw_mode);

    /* 抛事件到wal层处理 */
    wal_write_msg_hdr_init(&st_write_msg, WLAN_CFGID_HID2D_SWITCH_CHAN, sizeof(st_csa_cfg));

    /* 设置配置命令参数 */
    if (EOK != memcpy_s(st_write_msg.auc_value, sizeof(st_write_msg.auc_value),
        (const void *)&st_csa_cfg, sizeof(st_csa_cfg))) {
        oam_error_log0(0, OAM_SF_ANY, "HiD2D Presentation::memcpy fail!");
        return OAL_FAIL;
    }

    l_ret = wal_send_cfg_event(pst_net_dev,
        WAL_MSG_TYPE_WRITE,
        WAL_MSG_WRITE_MSG_HDR_LENGTH + sizeof(st_csa_cfg),
        (uint8_t *)&st_write_msg,
        OAL_FALSE,
        NULL);
    if (oal_unlikely(l_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_ANY, "{HiD2D Presentation::err[%d]!}", ret);
        return (uint32_t)l_ret;
    }
    return OAL_SUCC;
}
#endif

/*
 * 函 数 名  : wal_vendor_priv_cmd_hid2d_apk
 * 功能描述  : 私有命令拓展hid2d抗干扰相关接口
 * 1.日    期  : 2020年05月18日
 *   作    者  : wifi
 *   修改内容  : 新增函数
 */
uint32_t wal_vendor_priv_cmd_hid2d_apk(oal_net_device_stru *net_dev, oal_ifreq_stru *ifr, uint8_t *cmd)
{
    int8_t cmd_type_str[WAL_HIPRIV_CMD_VALUE_MAX_LEN] = {0};
    int32_t cmd_type;
    uint32_t ret, offset;
    uint8_t cmd_idx;

    /* 判断是不是HiD2D APK相关命令, 非HiD2D APK命令，直接返回 */
    if (oal_strncasecmp(cmd, CMD_HID2D_PARAMS, CMD_HID2D_PARAMS_LEN) != 0) {
        return OAL_SUCC;
    }
    /* 获取type值 */
    cmd += CMD_HID2D_PARAMS_LEN;
    ret = wal_get_cmd_one_arg(cmd, cmd_type_str, WAL_HIPRIV_CMD_VALUE_MAX_LEN, &offset);
    if (ret != OAL_SUCC) {
        oam_warning_log0(0, OAM_SF_ANY, "{wal_vendor_priv_cmd_hid2d_apk::invalid cmd}");
        return ret;
    }
    cmd_type = (int32_t)oal_atoi(cmd_type_str);
    cmd += offset;

    /* 解析Type值 */
    if (cmd_type == 256) { /* 256为返回最佳信道的cmd type */
        oam_warning_log1(0, OAM_SF_ANY, "{wal_vendor_priv_cmd_hid2d_apk::cmd[%d] NOT support!}", cmd_type);
        return OAL_SUCC;
    }
    if ((uint8_t)cmd_type >= WAL_HID2D_HIGH_BW_MCS_CMD && (uint8_t)cmd_type <= WAL_HID2D_CCA_CMD) {
        oam_warning_log1(0, OAM_SF_ANY, "{wal_vendor_priv_cmd_hid2d_apk::cmd[%d] NOT support!}", cmd_type);
        return OAL_SUCC;
    }
    for (cmd_idx = 0; cmd_idx < oal_array_size(g_hid2d_vendor_cmd); cmd_idx++) {
        if ((uint8_t)cmd_type == g_hid2d_vendor_cmd[cmd_idx].hid2d_cfg_type &&
            g_hid2d_vendor_cmd[cmd_idx].func != NULL) {
            return g_hid2d_vendor_cmd[cmd_idx].func(net_dev, cmd);
        }
    }

    oam_warning_log0(0, OAM_SF_ANY, "{wal_vendor_priv_cmd_hid2d::invalid cmd}");

    return OAL_FAIL;
}

/*
 * 功能描述  : 配置低时延。调整ip休眠模式，调整wifi休眠模式，调整napi模式，调整wifi芯片频率。1：enable 0：disable。
 */
int32_t wal_ioctl_config_low_latency(oal_net_device_stru *pst_net_dev, uint8_t uc_param)
{
    if (((uc_param & BIT0) >> 0) == OAL_FALSE) {
        g_freq_lock_control.hcc_aspm_close_bitmap |= BIT(ASPM_CALL_IOCTL_CONFIG_LOW_LATENCY);
    } else {
        g_freq_lock_control.hcc_aspm_close_bitmap &= ~BIT(ASPM_CALL_IOCTL_CONFIG_LOW_LATENCY);
    }
    mpxx_hcc_ip_pm_ctrl((uc_param & BIT0) >> 0, HCC_EP_WIFI_DEV); // BIT0 ip休眠模式
    wal_hid2d_sleep_mode(pst_net_dev, (uc_param & BIT1) >> 1); // BIT1 wifi休眠
    wal_hid2d_napi_mode(pst_net_dev, (uc_param & BIT2) >> 2); // BIT2 napi mode
    wal_hid2d_freq_boost(pst_net_dev,  (uc_param & BIT3) >> 3); // BIT3 wifi芯片频率提高

    oam_warning_log1(0, OAM_SF_ANY, "{wal_ioctl_config_low_latency::uc_param[0x%x].}", uc_param);
    return OAL_SUCC;
}
// cc仓现在调用的接口，先保留，等CC仓整改完后再删
int32_t wal_ioctl_config_low_latency_hi1105(oal_net_device_stru *net_dev, uint8_t param)
{
    return wal_ioctl_config_low_latency(net_dev, param);
}
uint32_t wlan_pm_disable_hi1105(void)
{
    return wlan_pm_disable();
}
uint32_t wlan_pm_enable_hi1105(void)
{
    return wlan_pm_enable();
}
// cc仓直接声明调用的新接口
int32_t wal_ioctl_config_low_latency_mintp_conn(oal_net_device_stru *net_dev, uint8_t param)
{
    wal_ioctl_config_low_latency(net_dev, param);
    // 该接口在cc仓mintp_conn.c中有对wlan pm操作，把wlan pm的操作处理下移，只暴露wal_ioctl_config_low_latency_mintp_conn接口
    if (param == WAL_LOW_LATENCY_ON) {
        wlan_pm_disable();
    } else if (param == WAL_LOW_LATENCY_OFF) {
        wlan_pm_enable();
    }
    return OAL_SUCC;
}

/*
 * 功能描述: dmac hid2d信道测量结果上报处理
 */
uint32_t hmac_scan_hid2d_chan_meas_result_event(frw_event_mem_stru *event_mem)
{
    frw_event_stru *event = NULL;
    frw_event_hdr_stru *event_hdr = NULL;
    hmac_vap_stru *hmac_vap = NULL;
    dmac_crx_chan_result_stru *chan_result_param = NULL;
    uint8_t scan_idx;

    /* 获取事件信息 */
    event = frw_get_event_stru(event_mem);
    event_hdr = &(event->st_event_hdr);
    chan_result_param = (dmac_crx_chan_result_stru *)(event->auc_event_data);
    scan_idx = chan_result_param->uc_scan_idx;

    /* 获取hmac_vap */
    hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(event_hdr->uc_vap_id);
    if (hmac_vap == NULL) {
        oam_error_log0(event_hdr->uc_vap_id, OAM_SF_SCAN,
            "{hmac_scan_hid2d_chan_meas_result_event:hmac_vap null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* 检查扫描次数是否合法 */
    if (scan_idx >= MAX_CHAN_MEAS_SCAN_NUMBERS) {
        /* dmac上报的扫描结果超出了要扫描的信道个数 */
        oam_warning_log1(0, OAM_SF_SCAN,
            "{hmac_scan_hid2d_chan_meas_result_event:result from dmac error! scan_idx[%d]}", scan_idx);
        return OAL_FAIL;
    }

    hmac_hid2d_scan_complete_handler(hmac_vap, &(chan_result_param->st_chan_result));
    oam_warning_log0(event_hdr->uc_vap_id, OAM_SF_SCAN,
        "{hmac_scan_hid2d_chan_meas_result_event:finish once chan meas!}");
    return OAL_SUCC;
}

#endif /* end of this file */
