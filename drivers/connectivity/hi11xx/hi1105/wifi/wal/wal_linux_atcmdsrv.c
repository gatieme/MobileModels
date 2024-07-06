/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * 功能说明 : 装备测试配置命令
 * 作    者 :
 * 创建日期 : 2015年10月10日
 */

#include "oal_ext_if.h"

#include "oam_ext_if.h"
#include "frw_ext_if.h"

#include "wlan_spec.h"
#include "wlan_types.h"

#include "mac_vap.h"
#include "mac_resource.h"
#include "mac_ie.h"
#include "hmac_resource.h"
#include "hmac_scan.h"

#include "hmac_ext_if.h"
#include "hmac_chan_mgmt.h"

#include "wal_main.h"
#include "wal_config.h"
#include "wal_regdb.h"
#include "wal_linux_scan.h"
#include "wal_linux_atcmdsrv.h"
#include "wal_linux_bridge.h"
#include "wal_linux_flowctl.h"
#include "wal_linux_event.h"
#include "wal_cfg_ioctl.h"

#include "plat_cali.h"
#include "oal_hcc_host_if.h"
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
#include <linux/of.h>
#include <linux/of_gpio.h>
#ifdef CONFIG_PINCTRL
#include <linux/pinctrl/consumer.h>
#endif
#include "board.h"
#endif
#include "securec.h"
#include "hmac_config.h"
#include "hmac_auto_adjust_freq.h"
#include "hmac_auto_cpufreq.h"
#include "hmac_cali_mgmt_debug.h"
#include "../chip/mp13/hisi_customize_wifi_mp13.h"
#include "../chip/hisi_conn_nve_interface_gf61.h"
#include "ssi_common.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_WAL_LINUX_ATCMDSRV_C
#ifdef PLATFORM_DEBUG_ENABLE
typedef enum {
    CHECK_LTE_GPIO_INIT = 0,      /* 初始化 */
    CHECK_LTE_GPIO_LOW = 1,       /* 设置为低电平 */
    CHECK_LTE_GPIO_HIGH = 2,      /* 设置为高电平 */
    CHECK_LTE_GPIO_RESUME = 3,    /* 恢复寄存器设置 */
    CHECK_LTE_GPIO_DEV_LEVEL = 4, /* 读取device GPIO管脚电平值 */
    CHECK_LTE_GPIO_BUTT
} check_lte_gpio_step;

typedef struct {
    uint32_t ssi_addr;
    uint32_t ssi_value;
} wal_atcmdsrv_ssi_stru;

typedef struct {
    uint8_t uc_mode; /* 模式 */
    uint8_t uc_band; /* 频段 */
} wal_atcmdsrv_mode_stru;

typedef struct {
    uint32_t datarate; /* at命令配置的速率值 */
    int8_t *puc_datarate; /* 速率字符串 */
} wal_atcmdsrv_datarate_stru;
typedef int32_t (*wal_atcmd_ioctl_set_func)(oal_net_device_stru *pst_net_dev,
                                            wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd);
typedef struct {
    int32_t l_cmd_id;
    wal_atcmd_ioctl_set_func p_func;
    int32_t l_copy_flag;
} wal_atcmd_ioctl_set_stru;

const wal_atcmdsrv_mode_stru g_ast_atcmdsrv_mode_table[] = {
    { WLAN_LEGACY_11A_MODE,    WLAN_BAND_5G },    /* 11a, 5G, OFDM */
    { WLAN_LEGACY_11B_MODE,    WLAN_BAND_2G },    /* 11b, 2.4G */
    { WLAN_LEGACY_11G_MODE,    WLAN_BAND_2G },    /* 旧的11g only已废弃, 2.4G, OFDM */
    { WLAN_MIXED_ONE_11G_MODE, WLAN_BAND_2G }, /* 11bg, 2.4G */
    { WLAN_MIXED_TWO_11G_MODE, WLAN_BAND_2G }, /* 11g only, 2.4G */
    { WLAN_HT_MODE,            WLAN_BAND_5G },            /* 11n(11bgn或者11an，根据频段判断) */
    { WLAN_VHT_MODE,           WLAN_BAND_5G },           /* 11ac */
    { WLAN_HT_ONLY_MODE,       WLAN_BAND_5G },       /* 11n only 5Gmode,只有带HT的设备才可以接入 */
    { WLAN_VHT_ONLY_MODE,      WLAN_BAND_5G },      /* 11ac only mode 只有带VHT的设备才可以接入 */
    { WLAN_HT_11G_MODE,        WLAN_BAND_2G },        /* 11ng,不包括11b */
    { WLAN_HT_ONLY_MODE_2G,    WLAN_BAND_2G },    /* 11nonlg 2Gmode */
    { WLAN_VHT_ONLY_MODE_2G,   WLAN_BAND_2G },   /* 11ac 2g mode 只有带VHT的设备才可以接入 */
    { WLAN_HE_MODE_5G,         WLAN_BAND_5G },
    { WLAN_HE_MODE_2G,         WLAN_BAND_2G },

    { WLAN_PROTOCOL_BUTT, WLAN_BAND_2G },
};

OAL_STATIC const wal_atcmdsrv_datarate_stru g_past_atcmdsrv_non_ht_rate_table[] = {
    { 0,  " 0 " }, /* mcs0, 装备下发65 */
    { 1,  " 1 " },
    { 2,  " 2 " },
    { 5,  " 5.5 " },
    { 6,  " 6 " },
    { 7,  " 7 " },
    { 8,  " 8 " },
    { 9,  " 9 " },
    { 10, " 10 " },
    { 11, " 11 " },
    { 12, " 12 " },
    { 13, " 13 " },
    { 18, " 18 " },
    { 24, " 24 " },
    { 36, " 36 " },
    { 48, " 48 " },
    { 54, " 54 " },
};
uint64_t g_chipcheck_total_time;
uint16_t g_us_efuse_buffer[WAL_ATCMDSRV_EFUSE_BUFF_LEN];
int32_t g_us_tsensor_val;
uint32_t g_us_config_word;
uint8_t g_us_bsn[WAL_ATCMDSRV_BOARD_SN_LENGTH];
int8_t g_us_flash_check_result;
int32_t g_write_pow_flag;
int32_t g_write_xo_flag;
int32_t g_us_spmi_check_result;
int32_t g_us_ssi_check_result;

wal_efuse_bits *g_efuse_bits = NULL;
int32_t g_l_bandwidth;
int32_t g_l_mode;

#define WAL_ATCMDSRV_WIFI_CHAN_NUM       2
#define WAL_ATCMDSRV_DYN_INTVAL_LEN      19
#define WAL_ATCMDSRV_DYN_INTVAL_LOCATION (WAL_ATCMDSRV_DYN_INTVAL_LEN - 2)
#define WAL_ATCMDSRV_MAC_DBB_NUM_MP15 0x0508031d
#define WAL_ATCMDSRV_MAC_DBB_NUM_MP13 0x036c0907
#define WAL_ATCMDSRB_DBB_NUM_TIME_MS ((WAL_ATCMDSRB_DBB_NUM_TIME * HMAC_S_TO_MS) / OAL_TIME_HZ)
#endif

/*
 * 函 数 名  : wal_get_fem_pa_status
 * 功能描述  : 获取fem和pa是否烧毁
 * 1.日    期  : 2015年7月12日
 *   修改内容  : 新生成函数
 */
OAL_STATIC void wal_get_fem_pa_status(oal_net_device_stru *pst_net_dev, int32_t *pl_fem_pa_status)
{
    mp13_cali_param_stru            *pst_cali_data_c0;
    mp13_cali_param_stru            *pst_cali_data_c1 = NULL;

    pst_cali_data_c0 = (mp13_cali_param_stru *)get_cali_data_buf_addr();
    if (pst_cali_data_c0 == NULL) {
        oam_error_log0(0, 0, "wal_get_fem_pa_status::null ptr happened");
        return;
    }
    pst_cali_data_c1 = pst_cali_data_c0 + 1;
    if (pst_cali_data_c1 == NULL) {
        oam_error_log0(0, 0, "wal_get_fem_pa_status::null ptr happened");
        return;
    }

    *pl_fem_pa_status = (int32_t)((pst_cali_data_c0->check_hw_status) |
        (pst_cali_data_c1->check_hw_status << BIT_OFFSET_4));
    if (*pl_fem_pa_status != 0) {
        chr_exception_report(CHR_PLATFORM_EXCEPTION_EVENTID, CHR_SYSTEM_WIFI, CHR_LAYER_DEV,
                             CHR_WIFI_DEV_EVENT_CHIP, CHR_WIFI_DEV_ERROR_FEM_FAIL);
        oam_error_log1(0, OAM_SF_ANY,
            "{wal_get_fem_pa_status::FEM pa status[%x].Bit:[0-1]2gc0,[2-3]5gc0,[4-5]2gc1,[6-7]5gc1}",
            *pl_fem_pa_status);
#if defined(CONFIG_HUAWEI_OHOS_DSM) || defined(CONFIG_HUAWEI_DSM)
        hw_mpxx_dsm_client_notify(SYSTEM_TYPE_WIFI, DSM_WIFI_FEMERROR, "%s: fem error",  __FUNCTION__);
#endif
    }
}

/*
 * 函 数 名  : wal_get_fem_pa_status
 * 功能描述  : 获取fem和pa是否烧毁
 * 1.日    期  : 2015年7月12日
 *   修改内容  : 新生成函数
 */
OAL_STATIC void wal_get_mp15_fem_pa_status(oal_net_device_stru *pst_net_dev, int32_t *pl_fem_pa_status)
{
    mp15_cali_param_stru            *pst_cali_data_c0 = NULL;
    mp15_cali_param_stru            *pst_cali_data_c1 = NULL;

    pst_cali_data_c0 = (mp15_cali_param_stru *)get_cali_data_buf_addr();
    if (pst_cali_data_c0 == NULL) {
        oam_error_log0(0, 0, "wal_get_fem_pa_status::null ptr happened");
        return;
    }

    pst_cali_data_c1 = pst_cali_data_c0 + 1;
    if (pst_cali_data_c1 == NULL) {
        oam_error_log0(0, 0, "wal_get_fem_pa_status::null ptr happened");
        return;
    }

    *pl_fem_pa_status = (int32_t)((pst_cali_data_c0->check_hw_status) |
        (pst_cali_data_c1->check_hw_status << BIT_OFFSET_4));
    if (*pl_fem_pa_status != 0) {
        chr_exception_report(CHR_PLATFORM_EXCEPTION_EVENTID, CHR_SYSTEM_WIFI, CHR_LAYER_DEV,
                             CHR_WIFI_DEV_EVENT_CHIP, CHR_WIFI_DEV_ERROR_FEM_FAIL);
        oam_error_log1(0, OAM_SF_ANY,
            "{wal_get_fem_pa_status::FEM pa status[%x].Bit:[0-1]2gc0,[2-3]5gc0,[4-5]2gc1,[6-7]5gc1}",
            *pl_fem_pa_status);
#if defined(CONFIG_HUAWEI_OHOS_DSM) || defined(CONFIG_HUAWEI_DSM)
        hw_mpxx_dsm_client_notify(SYSTEM_TYPE_WIFI, DSM_WIFI_FEMERROR, "%s: fem error",  __FUNCTION__);
#endif
    }
}

/*
 * 函 数 名  : wal_get_mp16_fem_pa_status
 * 功能描述  : 获取fem和pa是否烧毁
 * 1.日    期  : 2015年7月12日
 *   修改内容  : 新生成函数
 */
OAL_STATIC void wal_get_mp16_fem_pa_status(oal_net_device_stru *pst_net_dev, int32_t *pl_fem_pa_status)
{
    wlan_cali_data_para_stru *cali_data;
    uint32_t *check_hw_status = NULL;
    uint8_t rf_id;

    cali_data = (wlan_cali_data_para_stru *)get_cali_data_buf_addr();
    if (cali_data == NULL) {
        return;
    }
    check_hw_status = cali_data->common_cali_data.cali_ctl_data.check_hw_status;

    for (rf_id = 0; rf_id < HD_EVENT_RF_NUM; rf_id++) {
        *pl_fem_pa_status |= (int32_t)((check_hw_status[rf_id] & WLAN_FEM_PA_STATUS_MASK) << (BIT_OFFSET_4 * rf_id));
        check_hw_status[rf_id] &= ~WLAN_FEM_PA_STATUS_MASK;
    }
    if (*pl_fem_pa_status != 0) {
        chr_exception_report(CHR_PLATFORM_EXCEPTION_EVENTID, CHR_SYSTEM_WIFI, CHR_LAYER_DEV,
                             CHR_WIFI_DEV_EVENT_CHIP, CHR_WIFI_DEV_ERROR_FEM_FAIL);
        oam_error_log2(0, OAM_SF_ANY,
            "{wal_get_fem_pa_status::fem_status[0x%x].Bit:[0-3]c0,[4-7]c1,[8-11]c2,[12-15]c3,6g/5g/2g,error_band [%x]}",
            *pl_fem_pa_status, cali_data->common_cali_data.cali_ctl_data.fem_error_band);
        oam_error_log3(0, OAM_SF_CALIBRATE, "wal_get_mp16_fem_pa_status::pll1_err_flag[%d],bt_on[%d],gle_on[%d]",
            cali_data->common_cali_data.cali_ctl_data.pll1_err_flag,
            cali_data->common_cali_data.cali_ctl_data.curr_bt_on_flag,
            cali_data->common_cali_data.cali_ctl_data.curr_gle_on_flag);
        hmac_dump_cali_result_mp16();
        cali_data->common_cali_data.cali_ctl_data.curr_bt_on_flag = 0;
        cali_data->common_cali_data.cali_ctl_data.curr_gle_on_flag = 0;
#if defined(CONFIG_HUAWEI_OHOS_DSM) || defined(CONFIG_HUAWEI_DSM)
        hw_mpxx_dsm_client_notify(SYSTEM_TYPE_WIFI, DSM_WIFI_FEMERROR, "%s: fem error",  __FUNCTION__);
#endif
    }
    cali_data->common_cali_data.cali_ctl_data.fem_error_band = 0;
    return;
}

OAL_STATIC void wal_get_mp16_lna_gain_status(oal_net_device_stru *net_dev, int32_t *lna_gain_status)
{
    wlan_cali_data_para_stru *cali_data;
    uint32_t *check_hw_status = NULL;
    uint8_t rf_id;

    cali_data = (wlan_cali_data_para_stru *)get_cali_data_buf_addr();
    if (cali_data == NULL) {
        return;
    }
    check_hw_status = cali_data->common_cali_data.cali_ctl_data.check_hw_status;

    for (rf_id = 0; rf_id < HD_EVENT_RF_NUM; rf_id++) {
        *lna_gain_status |=
            (int32_t)(((check_hw_status[rf_id] & WLAN_LNA_GAIN_STATUS_MASK) >> BIT_OFFSET_4) << (BIT_OFFSET_4 * rf_id));
        check_hw_status[rf_id] &= ~WLAN_LNA_GAIN_STATUS_MASK;
    }
    if (*lna_gain_status != 0) {
        oam_error_log1(0, OAM_SF_ANY,
            "{wal_get_mp16_lna_gain_status::LNA gain status[%x].Bit:[0-3]c0,[4-7]c1,[8-11]c2,[12-15]c3,6g/5g/2g}",
            *lna_gain_status);
        /* CHR上报和DMD上报待申请新的ID,暂时先复用FEM PA */
        chr_exception_report(CHR_PLATFORM_EXCEPTION_EVENTID, CHR_SYSTEM_WIFI, CHR_LAYER_DEV,
            CHR_WIFI_DEV_EVENT_CHIP, CHR_WIFI_DEV_ERROR_FEM_FAIL);
#if defined(CONFIG_HUAWEI_OHOS_DSM) || defined(CONFIG_HUAWEI_DSM)
        hw_mpxx_dsm_client_notify(SYSTEM_TYPE_WIFI, DSM_WIFI_LNAERROR, "%s: lna gain error",  __FUNCTION__);
#endif
    }
    return;
}

/*
 * 函 数 名  : wal_atcmsrv_ioctl_get_fem_pa_status
 * 功能描述  : 获取fem和pa是否烧毁
 * 1.日    期  : 2015年7月12日
 *   修改内容  : 新生成函数
 */
void wal_atcmsrv_ioctl_get_fem_pa_status(oal_net_device_stru *pst_net_dev, int32_t *pl_fem_pa_status)
{
    int32_t l_chip_type;

    l_chip_type = get_mpxx_subchip_type();
    if (l_chip_type >= BOARD_VERSION_MP16) {
        wal_get_mp16_fem_pa_status(pst_net_dev, pl_fem_pa_status);
    } else if (l_chip_type == BOARD_VERSION_MP15) {
        wal_get_mp15_fem_pa_status(pst_net_dev, pl_fem_pa_status);
    } else {
        wal_get_fem_pa_status(pst_net_dev, pl_fem_pa_status);
    }
}

void wal_atcmsrv_ioctl_get_lna_gain_status(oal_net_device_stru *net_dev, int32_t *lna_gain_status)
{
    int32_t l_chip_type;

    l_chip_type = get_mpxx_subchip_type();
    if (l_chip_type >= BOARD_VERSION_MP16) {
        wal_get_mp16_lna_gain_status(net_dev, lna_gain_status);
    }
}
#ifdef PLATFORM_DEBUG_ENABLE
static int32_t wal_atcmsrv_ioctl_wait_rx_fcs_info_event(
    mac_vap_stru *mac_vap, hmac_vap_stru *hmac_vap, int32_t *rx_pckg_succ_num)
{
    int32_t leftime;

    /* 阻塞等待dmac上报 */
    leftime = oal_wait_event_interruptible_timeout_m(hmac_vap->query_wait_q,
        (uint32_t)(hmac_vap->st_atcmdsrv_get_status.uc_get_rx_pkct_flag == OAL_TRUE), WAL_ATCMDSRB_GET_RX_PCKT);
    if (leftime == 0) {
        /* 超时还没有上报扫描结束 */
        oam_warning_log1(mac_vap->uc_vap_id, 0, "{wal_atcmsrv_ioctl_get_rx_pckg::dbb_num wait for %ld ms timeout!}",
                         ((WAL_ATCMDSRB_DBB_NUM_TIME * HMAC_S_TO_MS) / OAL_TIME_HZ));
        return -OAL_EINVAL;
    } else if (leftime < 0) {
        /* 定时器内部错误 */
        oam_warning_log1(mac_vap->uc_vap_id, 0, "{wal_atcmsrv_ioctl_get_rx_pckg::dbb_num wait for %ld ms error!}",
                         ((WAL_ATCMDSRB_DBB_NUM_TIME * HMAC_S_TO_MS) / OAL_TIME_HZ));
        return -OAL_EINVAL;
    } else {
        /* 正常结束  */
        oam_info_log1(mac_vap->uc_vap_id, 0, "{wal_atcmsrv_ioctl_get_rx_pckg::dbb_num wait for %ld ms error!}",
                      ((WAL_ATCMDSRB_DBB_NUM_TIME * HMAC_S_TO_MS) / OAL_TIME_HZ));
        *rx_pckg_succ_num = (int32_t)hmac_vap->st_atcmdsrv_get_status.rx_pkct_succ_num;
        return OAL_SUCC;
    }
}

/*
 * 函 数 名  : wal_atcmsrv_ioctl_get_rx_pckg_old
 * 功能描述  : 统计收包数
 * 日    期  : 2019年7月29日
 */
int32_t wal_atcmsrv_ioctl_get_rx_pckg_old(oal_net_device_stru *pst_net_dev, int32_t *rx_pckg_succ_num)
{
    int32_t l_ret;
    mac_cfg_rx_fcs_info_stru *pst_rx_fcs_info = NULL;
    wal_msg_write_stru st_write_msg = {0};
    mac_vap_stru *mac_vap = NULL;
    hmac_vap_stru *hmac_vap = NULL;

    mac_vap = oal_net_dev_priv(pst_net_dev);
    if (mac_vap == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "{wal_atcmsrv_ioctl_get_rx_pckg::OAL_NET_DEV_PRIV, return null!}");
        return -OAL_EINVAL;
    }

    hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(mac_vap->uc_vap_id);
    if (hmac_vap == NULL) {
        oam_error_log0(mac_vap->uc_vap_id, OAM_SF_ANY, "{wal_atcmsrv_ioctl_get_rx_pckg::get_hmac_vap failed!}");
        return -OAL_EINVAL;
    }

    /***************************************************************************
                                抛事件到wal层处理
    ***************************************************************************/
    hmac_vap->st_atcmdsrv_get_status.uc_get_rx_pkct_flag = OAL_FALSE;
    wal_write_msg_hdr_init(&st_write_msg, WLAN_CFGID_RX_FCS_INFO, sizeof(mac_cfg_rx_fcs_info_stru));

    /* 设置配置命令参数 */
    pst_rx_fcs_info = (mac_cfg_rx_fcs_info_stru *)(st_write_msg.auc_value);
    /* 这两个参数在02已经没有意义 */
    pst_rx_fcs_info->data_op = 1;
    pst_rx_fcs_info->print_info = 0;

    l_ret = wal_send_cfg_event(pst_net_dev, WAL_MSG_TYPE_WRITE,
                               WAL_MSG_WRITE_MSG_HDR_LENGTH + sizeof(mac_cfg_rx_fcs_info_stru),
                               (uint8_t *)&st_write_msg, OAL_FALSE, NULL);
    if (oal_unlikely(l_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_ANY, "{wal_atcmsrv_ioctl_get_rx_pckg::return err code %d!}\r\n", l_ret);
        return l_ret;
    }

    return wal_atcmsrv_ioctl_wait_rx_fcs_info_event(mac_vap, hmac_vap, rx_pckg_succ_num);
}
/*
 * 函 数 名  : wal_atcmsrv_ioctl_get_rx_pckg
 * 功能描述  : 统计收包数
 * 日    期  : 2019年7月29日
 */
int32_t wal_atcmsrv_ioctl_get_rx_pckg(oal_net_device_stru *pst_net_dev, wal_atcmdsrv_wifi_priv_cmd_stru *priv_cmd)
{
    return wal_atcmsrv_ioctl_get_rx_pckg_old(pst_net_dev, &priv_cmd->pri_data.l_rx_pkcg);
}

/*
 * 功能描述  : 设置接收mac地址
 * 1.日    期  : 2015年10月10日
  *   修改内容  : 新生成函数
 */
int32_t wal_atcmsrv_ioctl_set_hw_addr(oal_net_device_stru *pst_net_dev,
                                      wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    int32_t l_ret;
    mac_cfg_staion_id_param_stru *pst_mac_cfg_para = NULL;
    wal_msg_write_stru st_write_msg;
    uint8_t *pc_hw_addr = pst_priv_cmd->pri_data.auc_mac_addr;

    /***************************************************************************
                                抛事件到wal层处理
    ***************************************************************************/
    wal_write_msg_hdr_init(&st_write_msg, WLAN_CFGID_STATION_ID, sizeof(mac_cfg_staion_id_param_stru));

    /* 设置配置命令参数 */
    pst_mac_cfg_para = (mac_cfg_staion_id_param_stru *)(st_write_msg.auc_value);
    /* 这两个参数在02已经没有意义 */
    pst_mac_cfg_para->en_p2p_mode = WLAN_LEGACY_VAP_MODE;
    oal_set_mac_addr(pst_mac_cfg_para->auc_station_id, pc_hw_addr);

    l_ret = wal_send_cfg_event(pst_net_dev, WAL_MSG_TYPE_WRITE,
                               WAL_MSG_WRITE_MSG_HDR_LENGTH + sizeof(mac_cfg_staion_id_param_stru),
                               (uint8_t *)&st_write_msg, OAL_FALSE, NULL);
    if (oal_unlikely(l_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_ANY, "{wal_atcmsrv_ioctl_set_hw_addr::return err code %d!}\r\n", l_ret);
        return l_ret;
    }
    return OAL_SUCC;
}

/*
 * 函 数 名  : wal_atcmsrv_ioctl_set_freq
 * 功能描述  : 设置频点/信道
 * 1.日    期  : 2015年7月12日
  *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmsrv_ioctl_set_freq(oal_net_device_stru *pst_net_dev,
                                              wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    wal_msg_write_stru st_write_msg;
    int32_t l_freq = pst_priv_cmd->pri_data.l_freq;
    int32_t l_ret;

    oam_warning_log1(0, OAM_SF_ANY, "wal_atcmsrv_ioctl_set_freq:l_freq[%d]", l_freq);
    /***************************************************************************
        抛事件到wal层处理
    ***************************************************************************/
    /* 填写消息 */
    wal_write_msg_hdr_init(&st_write_msg, WLAN_CFGID_CURRENT_CHANEL, sizeof(int32_t));
    *((int32_t *)(st_write_msg.auc_value)) = l_freq;

    /* 发送消息 */
    l_ret = wal_send_cfg_event(pst_net_dev,
                               WAL_MSG_TYPE_WRITE,
                               WAL_MSG_WRITE_MSG_HDR_LENGTH + sizeof(int32_t),
                               (uint8_t *)&st_write_msg,
                               OAL_FALSE,
                               NULL);
    if (oal_unlikely(l_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_ANY, "{wal_atcmsrv_ioctl_set_freq::return err code %d!}", l_ret);
        return l_ret;
    }

    return OAL_SUCC;
}

/*
 * 函 数 名  : wal_atcmsrv_ioctl_set_country
 * 功能描述  : 设置国家码
 * 1.日    期  : 2016年10月08日
 *   作    者  : 修改内容
 *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmsrv_ioctl_set_country(oal_net_device_stru *pst_net_dev,
    wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
#ifdef _PRE_WLAN_FEATURE_11D
    int32_t l_ret;
    int8_t *puc_countrycode = pst_priv_cmd->pri_data.auc_country_code;

    l_ret = wal_regdomain_update_for_dfs(pst_net_dev, puc_countrycode);
    if (l_ret != OAL_SUCC) {
        oam_warning_log1(0, OAM_SF_ANY,
            "{wal_atcmsrv_ioctl_set_country::regdomain_update_for_dfs return err code %d!}\r\n",
            l_ret);
        return l_ret;
    }

    l_ret = wal_regdomain_update(pst_net_dev, puc_countrycode);
    if (l_ret != OAL_SUCC) {
        oam_warning_log1(0, OAM_SF_ANY,
            "{wal_atcmsrv_ioctl_set_country::regdomain_update return err code %d!}\r\n",
            l_ret);
        return l_ret;
    }
#endif
    return OAL_SUCC;
}

/*
 * 函 数 名  : wal_atcmsrv_ioctl_set_txpower
 * 功能描述  : 设置频点/信道
 * 1.日    期  : 2015年7月12日
  *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmsrv_ioctl_set_txpower(oal_net_device_stru *pst_net_dev,
                                                 wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    wal_msg_write_stru st_write_msg;
    int32_t l_txpower = pst_priv_cmd->pri_data.l_pow;
    int32_t l_ret;

    oam_warning_log1(0, OAM_SF_ANY, "wal_atcmsrv_ioctl_set_txpower:l_txpower[%d]", l_txpower);

    /***************************************************************************
        抛事件到wal层处理
    ***************************************************************************/
    /* 填写消息 */
    wal_write_msg_hdr_init(&st_write_msg, WLAN_CFGID_TX_POWER, sizeof(int32_t));
    *((int32_t *)(st_write_msg.auc_value)) = (int32_t)(l_txpower);

    /* 发送消息 */
    l_ret = wal_send_cfg_event(pst_net_dev, WAL_MSG_TYPE_WRITE,
                               WAL_MSG_WRITE_MSG_HDR_LENGTH + sizeof(int32_t),
                               (uint8_t *)&st_write_msg, OAL_FALSE, NULL);
    if (oal_unlikely(l_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_ANY, "{wal_atcmsrv_ioctl_set_txpower::return err code %d!}", l_ret);
        return l_ret;
    }

    return OAL_SUCC;
}
/*
 * 函 数 名  : wal_atcmsrv_adapt_mode
 * 功能描述  : 模式转换
 * 1.日    期  : 2019年10月15日
  *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmsrv_adapt_mode(oal_net_device_stru *pst_net_dev,
    mac_cfg_mode_param_stru *pst_mode_param, int32_t l_mode)
{
    int8_t  *mcast_data = "cc 1";
    uint32_t ret;

    switch (l_mode) {
        case WLAN_HT_ONLY_MODE_2G:
            pst_mode_param->en_protocol = WLAN_HT_ONLY_MODE;
            break;
        case WLAN_VHT_ONLY_MODE_2G:
            pst_mode_param->en_protocol = WLAN_VHT_MODE;
            break;
        case WLAN_HE_MODE_5G:
        case WLAN_HE_MODE_2G:
            pst_mode_param->en_protocol = WLAN_HE_MODE;
            ret = wal_hipriv_set_mcast_data_dscr_param(pst_net_dev, mcast_data);
            if (ret != OAL_SUCC) {
                oam_error_log0(0, 0, "wal_hipriv_set_mcast_data_dscr_param set failed\n");
                return -OAL_EINVAL;
            }
            break;

        default:
            pst_mode_param->en_protocol = (uint8_t)l_mode;
            break;
    }

    return OAL_SUCC;
}

/*
 * 函 数 名  : wal_atcmsrv_ioctl_set_mode
 * 功能描述  : 设置模式
 * 1.日    期  : 2015年7月12日
  *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmsrv_ioctl_set_mode(oal_net_device_stru *pst_net_dev,
                                              wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    wal_msg_write_stru st_write_msg;
    mac_cfg_mode_param_stru *pst_mode_param = NULL;
    uint8_t uc_prot_idx;
    mac_vap_stru *pst_mac_vap = NULL;
    int32_t l_mode = pst_priv_cmd->pri_data.l_mode;
    uint8_t uc_arr_num = oal_array_size(g_ast_atcmdsrv_mode_table);
    int32_t l_ret;

    pst_mac_vap = oal_net_dev_priv(pst_net_dev);
    if (pst_mac_vap == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "{wal_atcmsrv_ioctl_set_mode::OAL_NET_DEV_PRIV, return null!}");
        return -OAL_EINVAL;
    }

    /* 获取模式对应的band */
    for (uc_prot_idx = 0; uc_prot_idx < uc_arr_num; uc_prot_idx++) {
        if (g_ast_atcmdsrv_mode_table[uc_prot_idx].uc_mode == (uint8_t)l_mode) {
            break;
        }
    }
    if (uc_prot_idx >= uc_arr_num) {
        oam_error_log1(0, OAM_SF_ANY, "{wal_atcmsrv_ioctl_set_mode:err code[%u]}", uc_prot_idx);
        return -OAL_EINVAL;
    }

    /***************************************************************************
        抛事件到wal层处理
    ***************************************************************************/
    /* 填写消息 */
    wal_write_msg_hdr_init(&st_write_msg, WLAN_CFGID_MODE, sizeof(mac_cfg_mode_param_stru));

    /* 设置模式，在配置模式的时候将带宽默认成20M */
    pst_mode_param = (mac_cfg_mode_param_stru *)(st_write_msg.auc_value);
    l_ret = wal_atcmsrv_adapt_mode(pst_net_dev, pst_mode_param, l_mode);
    if (l_ret != OAL_SUCC)
        return -OAL_EINVAL;

    pst_mode_param->en_band = (wlan_channel_band_enum_uint8)g_ast_atcmdsrv_mode_table[uc_prot_idx].uc_band;
    pst_mode_param->en_bandwidth = WLAN_BAND_WIDTH_20M;
    /* 未测使用，后续将删除 */
    oam_warning_log3(pst_mac_vap->uc_vap_id, OAM_SF_CFG,
                     "{wal_atcmsrv_ioctl_set_mode::protocol[%d],band[%d],bandwidth[%d]!}\r\n",
                     pst_mode_param->en_protocol, pst_mode_param->en_band, pst_mode_param->en_bandwidth);

    /* 发送消息 */
    l_ret = wal_send_cfg_event(pst_net_dev, WAL_MSG_TYPE_WRITE,
                               WAL_MSG_WRITE_MSG_HDR_LENGTH + sizeof(mac_cfg_mode_param_stru),
                               (uint8_t *)&st_write_msg, OAL_FALSE, NULL);
    if (oal_unlikely(l_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_ANY, "{wal_atcmsrv_ioctl_set_mode::return err code %d!}\r\n", l_ret);
        return l_ret;
    }
    g_l_mode = pst_mode_param->en_protocol;

    return OAL_SUCC;
}
/*
 * 函 数 名  : wal_atcmsrv_ioctl_set_datarate
 * 功能描述  : 设置发送速率
 * 1.日    期  : 2015年7月12日
  *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmsrv_set_bw(uint8_t *pen_bw)
{
    int8_t ac_bw_str[5] = { 0 };    /* 5表示带宽字符串长度 */
    const int8_t *c_bw20 = "20";
    const int8_t *c_bw40 = "40";
    const int8_t *c_bw80 = "80";
    const int8_t *c_bw160 = "160";
    errno_t err;
    if ((WLAN_BAND_WIDTH_160PLUSPLUSPLUS <= g_l_bandwidth) && (g_l_bandwidth <= WLAN_BAND_WIDTH_160MINUSMINUSMINUS)) {
        err = strncpy_s(ac_bw_str, sizeof(ac_bw_str), c_bw160, oal_min(oal_array_size(ac_bw_str), OAL_STRLEN(c_bw160)));
    } else if ((WLAN_BAND_WIDTH_80PLUSPLUS <= g_l_bandwidth) && (g_l_bandwidth <= WLAN_BAND_WIDTH_80MINUSMINUS)) {
        err = strncpy_s(ac_bw_str, sizeof(ac_bw_str), c_bw80, oal_min(oal_array_size(ac_bw_str), OAL_STRLEN(c_bw80)));
    } else if ((WLAN_BAND_WIDTH_40PLUS <= g_l_bandwidth) && (g_l_bandwidth <= WLAN_BAND_WIDTH_40MINUS)) {
        err = strncpy_s(ac_bw_str, sizeof(ac_bw_str), c_bw40, oal_min(oal_array_size(ac_bw_str), OAL_STRLEN(c_bw40)));
    } else {
        err = strncpy_s(ac_bw_str, sizeof(ac_bw_str), c_bw20, oal_min(oal_array_size(ac_bw_str), OAL_STRLEN(c_bw20)));
    }
    if (err != EOK) {
        return (err);
    }
    for (*pen_bw = 0; *pen_bw < WLAN_BANDWITH_CAP_BUTT; (*pen_bw)++) {
        if (!oal_strcmp(g_pauc_bw_tbl[*pen_bw], ac_bw_str)) {
            break;
        }
    }

    /* 检查命令是否打错 */
    if (*pen_bw >= WLAN_BANDWITH_CAP_BUTT) {
        oam_warning_log0(0, OAM_SF_ANY, "{wal_hipriv_set_bw::not support this bandwidth!}\r\n");
        return OAL_ERR_CODE_INVALID_CONFIG;
    }
    return OAL_SUCC;
}

/*
 * 函 数 名  : wal_hipriv_protocol_set_mcs
 * 功能描述  : 根据协议模式设置发送速率
 * 1.日    期  : 2019.10.25
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_hipriv_protocol_set_mcs(oal_net_device_stru *pst_net_dev, uint8_t uc_prot_idx)
{
    uint32_t ret = 0;

    if (g_l_mode == WLAN_HT_ONLY_MODE) { /* 当速率设置为7时表示MCS7 */
        ret = wal_hipriv_set_mcs(pst_net_dev,
                                 (int8_t *)g_past_atcmdsrv_non_ht_rate_table[uc_prot_idx].puc_datarate);
    } else if (g_l_mode == WLAN_VHT_MODE) {
        ret = wal_hipriv_set_mcsac(pst_net_dev,
                                   (int8_t *)g_past_atcmdsrv_non_ht_rate_table[uc_prot_idx].puc_datarate);
    } else if (g_l_mode == WLAN_HE_MODE) {
#ifdef _PRE_WLAN_FEATURE_11AX
        if (g_wlan_spec_cfg->feature_11ax_is_open) {
            ret = wal_hipriv_set_mcsax(pst_net_dev,
                                       (int8_t *)g_past_atcmdsrv_non_ht_rate_table[uc_prot_idx].puc_datarate);
        }
#endif
    } else {
        ret = wal_hipriv_set_rate(pst_net_dev,
                                  (int8_t *)g_past_atcmdsrv_non_ht_rate_table[uc_prot_idx].puc_datarate);
    }

    return ret;
}

/*
 * 函 数 名  : wal_atcmsrv_ioctl_set_datarate
 * 功能描述  : 设置发送速率
 * 1.日    期  : 2015年7月12日
  *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmsrv_ioctl_set_datarate(oal_net_device_stru *pst_net_dev,
    wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    uint8_t uc_prot_idx;
    mac_vap_stru *pst_mac_vap = NULL;
    uint8_t en_bw_index = 0;
    mac_cfg_tx_comp_stru *pst_set_bw_param = NULL;
    wal_msg_write_stru st_write_msg;
    int32_t l_datarate = pst_priv_cmd->pri_data.l_datarate;
    int32_t l_ret;
    uint8_t uc_arr_num = oal_array_size(g_past_atcmdsrv_non_ht_rate_table);

    pst_mac_vap = oal_net_dev_priv(pst_net_dev);
    if (pst_mac_vap == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "{wal_atcmsrv_ioctl_set_datarate::OAL_NET_DEV_PRIV, return null!}");
        return -OAL_EINVAL;
    }
    oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_ANY, "wal_atcmsrv_ioctl_set_datarate:l_datarate[%d]", l_datarate);

    /* 获取速率对应的字符，方便调用设置速率的相应接口 */
    for (uc_prot_idx = 0; uc_prot_idx < uc_arr_num; uc_prot_idx++) {
        if (g_past_atcmdsrv_non_ht_rate_table[uc_prot_idx].datarate == (uint32_t)l_datarate) {
            break;
        }
    }
    if (uc_prot_idx >= uc_arr_num) {
        oam_error_log0(0, OAM_SF_ANY, "uc_prot_idx Overrunning!");
        return -OAL_EINVAL;
    }

    if (wal_hipriv_protocol_set_mcs(pst_net_dev, uc_prot_idx) != OAL_SUCC) {
        return -OAL_EFAIL;
    }
    /* 设置长发描述符带宽 */
    /***************************************************************************
                                抛事件到wal层处理
    ***************************************************************************/
    wal_write_msg_hdr_init(&st_write_msg, WLAN_CFGID_SET_BW, sizeof(mac_cfg_tx_comp_stru));

    /* 解析并设置配置命令参数 */
    pst_set_bw_param = (mac_cfg_tx_comp_stru *)(st_write_msg.auc_value);

    l_ret = wal_atcmsrv_set_bw(&en_bw_index);
    if (l_ret != OAL_SUCC) {
        return -OAL_EFAIL;
    }
    pst_set_bw_param->uc_param = (uint8_t)(en_bw_index);

    l_ret = wal_send_cfg_event(pst_net_dev, WAL_MSG_TYPE_WRITE,
                               WAL_MSG_WRITE_MSG_HDR_LENGTH + sizeof(mac_cfg_tx_comp_stru),
                               (uint8_t *)&st_write_msg, OAL_FALSE, NULL);
    if (oal_unlikely(l_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_ANY, "{wal_hipriv_set_bw::return err code [%d]!}\r\n", l_ret);
        return l_ret;
    }
    return OAL_SUCC;
}

/*
 * 函 数 名  : wal_atcmsrv_ioctl_set_bandwidth
 * 功能描述  : 设置带宽
 * 1.日    期  : 2015年7月12日
  *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmsrv_ioctl_set_bandwidth(oal_net_device_stru *pst_net_dev,
                                                   wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    wal_msg_write_stru st_write_msg;
    mac_cfg_mode_param_stru *pst_mode_param = NULL;
    int32_t l_bandwidth = pst_priv_cmd->pri_data.l_bandwidth;
    int32_t l_ret;

    oam_warning_log1(0, OAM_SF_ANY, "wal_atcmsrv_ioctl_set_bandwidth:l_bandwidth[%d]", l_bandwidth);
    g_l_bandwidth = l_bandwidth;

    /***************************************************************************
        抛事件到wal层处理
    ***************************************************************************/
    /* 填写消息 */
    wal_write_msg_hdr_init(&st_write_msg, WLAN_CFGID_BANDWIDTH, sizeof(int32_t));

    /* 设置带宽时，模式不做修改，还是按照之前的值配置 */
    pst_mode_param = (mac_cfg_mode_param_stru *)(st_write_msg.auc_value);

    pst_mode_param->en_bandwidth = (uint8_t)l_bandwidth;

    /* 发送消息 */
    l_ret = wal_send_cfg_event(pst_net_dev, WAL_MSG_TYPE_WRITE,
                               WAL_MSG_WRITE_MSG_HDR_LENGTH + sizeof(mac_cfg_mode_param_stru),
                               (uint8_t *)&st_write_msg, OAL_FALSE, NULL);
    if (oal_unlikely(l_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_ANY, "{wal_atcmsrv_ioctl_set_mode::return err code %d!}\r\n", l_ret);
        return l_ret;
    }

    return OAL_SUCC;
}
#ifdef PLATFORM_DEBUG_ENABLE
/*
 * 函 数 名  : wal_atcmsrv_ioctl_set_always_tx
 * 功能描述  : 设置长发模式
 * 1.日    期  : 2015年7月12日
  *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmsrv_ioctl_set_always_tx(oal_net_device_stru *pst_net_dev,
                                                   wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    wal_msg_write_stru st_write_msg;
    int32_t ret;
    mac_cfg_tx_comp_stru *pst_set_bcast_param = NULL;
    uint8_t auc_param[] = { "all" };
    uint16_t us_len;
    int32_t always_tx = pst_priv_cmd->pri_data.l_awalys_tx;
    uint32_t value, cmd_id;
    uint32_t offset = 0;

    oam_warning_log1(0, OAM_SF_ANY, "wal_atcmsrv_ioctl_set_always_tx:always_tx[%d]", always_tx);
    /* 关闭常发时不需要重复配置num */
    if (always_tx != 0) {
        ret = wal_get_cmd_id("al_tx_num", &cmd_id, &offset);
        if (ret != OAL_SUCC) {
            oam_error_log0(0, OAM_SF_ANY, "wal_atcmsrv_ioctl_set_always_tx:find al_tx_num cmd is fail");
            return -OAL_EINVAL;
        }
        value = 0xffffffe; /* 0xffffffff用于温度补偿 */
        wal_process_cmd_params(pst_net_dev, cmd_id, &value);
    }

    /***************************************************************************
                                抛事件到wal层处理
    ***************************************************************************/
    wal_write_msg_hdr_init(&st_write_msg, WLAN_CFGID_SET_ALWAYS_TX, sizeof(mac_cfg_tx_comp_stru));

    /* 解析并设置配置命令参数 */
    pst_set_bcast_param = (mac_cfg_tx_comp_stru *)(st_write_msg.auc_value);

    /* 装备测试的情况下直接将长发参数设置好 */
    pst_set_bcast_param->en_payload_flag = RF_PAYLOAD_RAND;
    pst_set_bcast_param->payload_len = WAL_ATCMDSRB_IOCTL_AL_TX_LEN;
    pst_set_bcast_param->uc_param = (uint8_t)always_tx;

    ret = wal_send_cfg_event(pst_net_dev, WAL_MSG_TYPE_WRITE,
                             WAL_MSG_WRITE_MSG_HDR_LENGTH + sizeof(mac_cfg_tx_comp_stru),
                             (uint8_t *)&st_write_msg, OAL_FALSE, NULL);
    if (oal_unlikely(ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_ANY, "{wal_atcmsrv_ioctl_set_always_tx::return err code [%d]!}", ret);
        return -OAL_EFAIL;
    }

    /* 打印维测信息 */
    if (always_tx && (get_mpxx_subchip_type() <= BOARD_VERSION_MP15)) {
        /* 打印所有寄存器 */
        /***************************************************************************
                                    抛事件到wal层处理
        ***************************************************************************/
        if (memcpy_s(st_write_msg.auc_value, sizeof(st_write_msg.auc_value),
            auc_param, OAL_STRLEN((int8_t *)auc_param)) != EOK) {
            oam_error_log0(0, OAM_SF_ANY, "wal_atcmsrv_ioctl_set_always_tx:memcpy_s fail !");
            return -OAL_EFAIL;
        }

        st_write_msg.auc_value[OAL_STRLEN((int8_t *)auc_param)] = '\0';
        us_len = (uint16_t)(OAL_STRLEN((int8_t *)auc_param) + 1);

        wal_write_msg_hdr_init(&st_write_msg, WLAN_CFGID_REG_INFO, us_len);

        ret = wal_send_cfg_event(pst_net_dev, WAL_MSG_TYPE_WRITE, WAL_MSG_WRITE_MSG_HDR_LENGTH + us_len,
                                 (uint8_t *)&st_write_msg, OAL_FALSE, NULL);
        if (oal_unlikely(ret != OAL_SUCC)) {
            oam_warning_log1(0, OAM_SF_ANY, "{wal_atcmsrv_ioctl_set_always_tx::return err code [%d]!}\r\n", ret);
        }
    }
    return OAL_SUCC;
}
#endif
/*
 * 功能描述  : 转换dbb版本号
 * 1.日    期  : 2015年7月12日
  *   修改内容  : 新生成函数
 */
OAL_STATIC void wal_atcmdsrv_ioctl_convert_dbb_num(uint32_t dbb_num, uint8_t *pc_dbb_num)
{
    uint8_t uc_temp;

    /* MAC H/w version register format                  */
    /* ------------------------------------------------ */
    /* | 31 - 24 | 23 - 16 | 15 - 12 | 11 - 0 | */
    /* ------------------------------------------------ */
    /* | BN      | Y1      | Y2      |   Y3   | */
    /* ------------------------------------------------ */
    /* Format the version as BN.Y1.Y2.Y3 with all values in hex i.e. the  */
    /* version string would be XX.XX.X.XXX.                                 */
    /* For e.g. 0225020A saved in the version register would translate to */
    /* the configuration interface version number 02.25.0.20A             */
    uc_temp = (dbb_num & 0xF0000000) >> BIT_OFFSET_28;
    pc_dbb_num[0] = wal_atcmdsrv_get_hex_char(uc_temp);
    uc_temp = (dbb_num & 0x0F000000) >> BIT_OFFSET_24;
    pc_dbb_num[1] = wal_atcmdsrv_get_hex_char(uc_temp);

    pc_dbb_num[BYTE_OFFSET_2] = '.';

    uc_temp = (dbb_num & 0x00F00000) >> BIT_OFFSET_20;
    pc_dbb_num[BYTE_OFFSET_3] = wal_atcmdsrv_get_hex_char(uc_temp);
    uc_temp = (dbb_num & 0x000F0000) >> BIT_OFFSET_16;
    pc_dbb_num[BYTE_OFFSET_4] = wal_atcmdsrv_get_hex_char(uc_temp);
    pc_dbb_num[BYTE_OFFSET_5] = '.';

    uc_temp = (dbb_num & 0x0000F000) >> BIT_OFFSET_12;
    pc_dbb_num[BYTE_OFFSET_6] = wal_atcmdsrv_get_hex_char(uc_temp);
    pc_dbb_num[BYTE_OFFSET_7] = '.';

    uc_temp = (dbb_num & 0x00000F00) >> BIT_OFFSET_8;
    pc_dbb_num[BYTE_OFFSET_8] = wal_atcmdsrv_get_hex_char(uc_temp);
    uc_temp = (dbb_num & 0x000000F0) >> BIT_OFFSET_4;
    pc_dbb_num[BYTE_OFFSET_9] = wal_atcmdsrv_get_hex_char(uc_temp);
    uc_temp = (dbb_num & 0x0000000F) >> 0;
    pc_dbb_num[BYTE_OFFSET_10] = wal_atcmdsrv_get_hex_char(uc_temp);

    return;
}
OAL_STATIC int32_t wal_atcmsrv_ioctl_wait_for_dbb_num(hmac_vap_stru *hmac_vap, int8_t *dbb_num)
{
    uint8_t vap_id = hmac_vap->st_vap_base_info.uc_vap_id;
    int32_t leftime;
    uint32_t mac_dbb_num = WAL_ATCMDSRV_MAC_DBB_NUM_MP13;

    if (get_mpxx_subchip_type() == BOARD_VERSION_MP15) {
        mac_dbb_num = WAL_ATCMDSRV_MAC_DBB_NUM_MP15;
    }

    /* 阻塞等待dmac上报 */
    leftime = oal_wait_event_interruptible_timeout_m(hmac_vap->query_wait_q,
        (uint32_t)(hmac_vap->st_atcmdsrv_get_status.uc_get_dbb_completed_flag == OAL_TRUE),
        WAL_ATCMDSRB_DBB_NUM_TIME);
    if (leftime == 0) {
        /* 超时还没有上报扫描结束 */
        oam_warning_log1(vap_id, OAM_SF_ANY,
                         "{wal_atcmsrv_ioctl_get_dbb_num::wait for %ld ms timeout!}", WAL_ATCMDSRB_DBB_NUM_TIME_MS);
        return -OAL_EINVAL;
    } else if (leftime < 0) {
        /* 定时器内部错误 */
        oam_warning_log1(vap_id, OAM_SF_ANY,
                         "{wal_atcmsrv_ioctl_get_dbb_num::wait for %ld ms error!}", WAL_ATCMDSRB_DBB_NUM_TIME_MS);
        return -OAL_EINVAL;
    } else {
        /* 正常结束  */
        oam_info_log2(vap_id, OAM_SF_ANY,
                      "{wal_atcmsrv_ioctl_get_dbb_num::dbb_num wait for %ld ms!, dbb_num[0x%x].}",
                      WAL_ATCMDSRB_DBB_NUM_TIME_MS, hmac_vap->st_atcmdsrv_get_status.dbb_num);

        if (hmac_vap->st_atcmdsrv_get_status.dbb_num != mac_dbb_num) {
            oam_error_log2(0, OAM_SF_ANY,
                           "wal_atcmsrv_ioctl_get_dbb_num:ul_dbb_num[0x%x],not match %u", mac_dbb_num,
                           hmac_vap->st_atcmdsrv_get_status.dbb_num);
            return -OAL_EINVAL;
        }

        wal_atcmdsrv_ioctl_convert_dbb_num(hmac_vap->st_atcmdsrv_get_status.dbb_num, (uint8_t *)dbb_num);
        return OAL_SUCC;
    }
}
/*
 * 函 数 名  : wal_atcmsrv_ioctl_get_dbb_num
 * 功能描述  : 获取dbb版本号
 * 1.日    期  : 2015年7月12日
  *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmsrv_ioctl_get_dbb_num(oal_net_device_stru *pst_net_dev,
                                                 wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    wal_msg_write_stru st_write_msg;
    int32_t l_ret;
    int8_t *pc_dbb_num = pst_priv_cmd->pri_data.auc_dbb;
    mac_vap_stru *pst_mac_vap = NULL;
    hmac_vap_stru *pst_hmac_vap = NULL;

    pst_mac_vap = oal_net_dev_priv(pst_net_dev);
    if (pst_mac_vap == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "{wal_atcmsrv_ioctl_get_dbb_num::OAL_NET_DEV_PRIV, return null!}");
        return -OAL_EINVAL;
    }

    pst_hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(pst_mac_vap->uc_vap_id);
    if (pst_hmac_vap == NULL) {
        oam_error_log0(pst_mac_vap->uc_vap_id, OAM_SF_ANY,
                       "{wal_atcmsrv_ioctl_get_dbb_num::mac_res_get_hmac_vap failed!}");
        return -OAL_EINVAL;
    }

    /***************************************************************************
                              抛事件到wal层处理
    ***************************************************************************/
    pst_hmac_vap->st_atcmdsrv_get_status.uc_get_dbb_completed_flag = OAL_FALSE;
    wal_write_msg_hdr_init(&st_write_msg, WLAN_CFGID_GET_VERSION, 0);

    l_ret = wal_send_cfg_event(pst_net_dev, WAL_MSG_TYPE_WRITE, WAL_MSG_WRITE_MSG_HDR_LENGTH,
                               (uint8_t *)&st_write_msg, OAL_FALSE, NULL);
    if (oal_unlikely(l_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_ANY,
                         "{wal_atcmsrv_ioctl_get_dbb_num::wal_send_cfg_event return err_code [%d]!}", l_ret);
        return l_ret;
    }

    return wal_atcmsrv_ioctl_wait_for_dbb_num(pst_hmac_vap, pc_dbb_num);
}

/*
 * 函 数 名  : wal_atcmsrv_ioctl_lte_gpio_mode
 * 功能描述  : LTE共存引脚虚焊检测模式设置
 * 1.日    期  : 2015年7月12日
  *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmsrv_ioctl_lte_gpio_mode(oal_net_device_stru *pst_net_dev, int32_t l_check_lte_gpio_step)
{
    wal_msg_write_stru st_write_msg;
    int32_t l_ret;
    int32_t i_leftime;
    mac_vap_stru *pst_mac_vap = NULL;
    hmac_vap_stru *pst_hmac_vap = NULL;

    pst_mac_vap = oal_net_dev_priv(pst_net_dev);
    if (pst_mac_vap == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "{wal_atcmsrv_ioctl_lte_gpio_mode::OAL_NET_DEV_PRIV, return null!}");
        return -OAL_EINVAL;
    }

    pst_hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(pst_mac_vap->uc_vap_id);
    if (pst_hmac_vap == NULL) {
        oam_error_log0(pst_mac_vap->uc_vap_id, OAM_SF_ANY,
                       "{wal_atcmsrv_ioctl_lte_gpio_mode::mac_res_get_hmac_vap failed!}");
        return -OAL_EINVAL;
    }

    pst_hmac_vap->st_atcmdsrv_get_status.uc_lte_gpio_check_flag = OAL_FALSE;

    /***************************************************************************
         抛事件到wal层处理
     ***************************************************************************/
    /* 填写消息 */
    wal_write_msg_hdr_init(&st_write_msg, WLAN_CFGID_CHECK_LTE_GPIO, sizeof(int32_t));

    /* 设置LTE虚焊检测的模式 */
    *(int32_t *)(st_write_msg.auc_value) = l_check_lte_gpio_step;

    /* 发送消息 */
    l_ret = wal_send_cfg_event(pst_net_dev, WAL_MSG_TYPE_WRITE, WAL_MSG_WRITE_MSG_HDR_LENGTH + sizeof(int32_t),
                               (uint8_t *)&st_write_msg, OAL_FALSE, NULL);
    if (oal_unlikely(l_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_ANY, "{wal_atcmsrv_ioctl_lte_gpio_mode::return err code %d!}\r\n", l_ret);
        return l_ret;
    }
    /* 阻塞等待dmac上报 */
    i_leftime = oal_wait_event_interruptible_timeout_m(pst_hmac_vap->query_wait_q,
        (uint32_t)(OAL_TRUE == pst_hmac_vap->st_atcmdsrv_get_status.uc_lte_gpio_check_flag),
        WAL_ATCMDSRB_DBB_NUM_TIME);
    if (i_leftime == 0) {
        /* 超时还没有上报扫描结束 */
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_ANY,
                         "{wal_atcmsrv_ioctl_lte_gpio_mode:: wait for %ld ms timeout!}",
                         ((WAL_ATCMDSRB_DBB_NUM_TIME * HMAC_S_TO_MS) / OAL_TIME_HZ));
        return -OAL_EINVAL;
    } else if (i_leftime < 0) {
        /* 定时器内部错误 */
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_ANY,
                         "{wal_atcmsrv_ioctl_lte_gpio_mode:: wait for %ld ms error!}",
                         ((WAL_ATCMDSRB_DBB_NUM_TIME * HMAC_S_TO_MS) / OAL_TIME_HZ));
        return -OAL_EINVAL;
    } else {
        return OAL_SUCC;
    }
}
OAL_STATIC int32_t wal_gpio_direction_output(uint32_t gpio_num, int32_t l_gpio_level)
{
    int32_t l_ret;
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    if (gpio_num == 0) {
        oam_warning_log1(0, 0, "wal_gpio_direction_output::no need to check gpio %d", gpio_num);
        return OAL_SUCC;
    }

    oam_warning_log2(0, 0, "wal_gpio_direction_output::gpio %d output set to %d", gpio_num, l_gpio_level);
    l_ret = gpio_direction_output(gpio_num, l_gpio_level);
    if (l_ret != OAL_SUCC) {
        oam_warning_log0(0, 0, "wal_atcmsrv_ioctl_lte_gpio_level_set:SET ISM PRIORITY FAIL!");
        return l_ret;
    }
#endif
    return l_ret;
}
/*
 * 函 数 名  : wal_atcmsrv_ioctl_lte_gpio_level_set
 * 功能描述  : LTE共存引脚虚焊检测
 * 1.日    期  : 2015年7月12日
  *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmsrv_ioctl_lte_gpio_level_set(int32_t gpio_level)
{
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    int32_t ret = wal_gpio_direction_output(g_wlan_cust.ism_priority, gpio_level);
    if (ret != OAL_SUCC) {
        oam_warning_log0(0, 0, "wal_atcmsrv_ioctl_lte_gpio_level_set:SET ISM PRIORITY FAIL!");
        return ret;
    }

    ret = wal_gpio_direction_output(g_wlan_cust.lte_rx, gpio_level);
    if (ret != OAL_SUCC) {
        oam_warning_log0(0, 0, "wal_atcmsrv_ioctl_lte_gpio_level_set:SET LTE RX FAIL!");
        return ret;
    }

    ret = wal_gpio_direction_output(g_wlan_cust.lte_tx, gpio_level);
    if (ret != OAL_SUCC) {
        oam_warning_log0(0, 0, "wal_atcmsrv_ioctl_lte_gpio_level_set:SET LTE TX FAIL!");
        return ret;
    }

    ret = wal_gpio_direction_output(g_wlan_cust.lte_inact, gpio_level);
    if (ret != OAL_SUCC) {
        oam_warning_log0(0, 0, "wal_atcmsrv_ioctl_lte_gpio_level_set:SET LTE INACT FAIL!");
        return ret;
    }

    ret = wal_gpio_direction_output(g_wlan_cust.ism_rx_act, gpio_level);
    if (ret != OAL_SUCC) {
        oam_warning_log0(0, 0, "wal_atcmsrv_ioctl_lte_gpio_level_set:SET ISM RX ACT FAIL!");
        return ret;
    }

    ret = wal_gpio_direction_output(g_wlan_cust.bant_pri, gpio_level);
    if (ret != OAL_SUCC) {
        oam_warning_log0(0, 0, "wal_atcmsrv_ioctl_lte_gpio_level_set:SET BANT PRI FAIL!");
        return ret;
    }

    ret = wal_gpio_direction_output(g_wlan_cust.bant_status, gpio_level);
    if (ret != OAL_SUCC) {
        oam_warning_log0(0, 0, "wal_atcmsrv_ioctl_lte_gpio_level_set:SET BANT STATUS FAIL!");
        return ret;
    }

    ret = wal_gpio_direction_output(g_wlan_cust.want_pri, gpio_level);
    if (ret != OAL_SUCC) {
        oam_warning_log0(0, 0, "wal_atcmsrv_ioctl_lte_gpio_level_set:SET WANT PRI FAIL!");
        return ret;
    }

    ret = wal_gpio_direction_output(g_wlan_cust.want_status, gpio_level);
    if (ret != OAL_SUCC) {
        oam_warning_log0(0, 0, "wal_atcmsrv_ioctl_lte_gpio_level_set:SET WANT STATUS FAIL!");
        return ret;
    }
#endif

    return OAL_SUCC;
}

/*
 * 函 数 名  : wal_atcmsrv_ioctl_lte_gpio_level_check
 * 功能描述  : LTE共存引脚虚焊检测
 * 1.日    期  : 2015年7月12日
  *   修改内容  : 新生成函数
 */
uint8_t g_uc_dev_lte_gpio_level = 0x0;
OAL_STATIC int32_t wal_atcmsrv_ioctl_lte_gpio_level_check(oal_net_device_stru *pst_net_dev, int32_t l_gpio_level)
{
    int32_t l_ret;

    l_ret = wal_atcmsrv_ioctl_lte_gpio_mode(pst_net_dev, CHECK_LTE_GPIO_DEV_LEVEL);
    if (l_ret < 0) {
        oam_error_log0(0, OAM_SF_ANY, "{wal_atcmsrv_ioctl_lte_gpio_level_check::GET DEV LTE GPIO LEVEL FAIL!}");
        return -OAL_EINVAL;
    }

    l_ret = -OAL_EINVAL;

    if (l_gpio_level == 0) {
        if (g_uc_dev_lte_gpio_level == 0x0) {
            oam_error_log0(0, OAM_SF_ANY, "{wal_atcmsrv_ioctl_lte_gpio_level_check::check gpio low mode SUCC!}");
            l_ret = OAL_SUCC;
        }
    } else if (l_gpio_level == 1) {
        /* CHECK BIT_3 BIT_4 */
        if (g_uc_dev_lte_gpio_level == 0x18) {
            oam_error_log0(0, OAM_SF_ANY, "{wal_atcmsrv_ioctl_lte_gpio_level_check::check gpio high mode SUCC!}");
            l_ret = OAL_SUCC;
        }
    } else {
        oam_error_log1(0, OAM_SF_ANY,
                       "{wal_atcmsrv_ioctl_lte_gpio_level_check::unknown param l_gpio_level %d!}",
                       l_gpio_level);
    }

    return l_ret;
}
/*
 * 函 数 名  : wal_gpio_request_one
 * 功能描述  : host申请gpio通道
 * 1.日    期  : 2015年7月12日
  *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_gpio_request_one(uint32_t gpio_num, const int8_t *name)
{
    int32_t l_ret = OAL_SUCC;
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    if (name == NULL) {
        oam_error_log1(0, 0, "wal_gpio_request_one::invalid input gpio %d", gpio_num);
        return OAL_EFAIL;
    }

    if (gpio_num == 0) {
        oam_warning_log1(0, 0, "wal_gpio_request_one::no need to check gpio %d", gpio_num);
        return OAL_SUCC;
    }

    oam_warning_log1(0, 0, "wal_gpio_request_one::request gpio_num is %d", gpio_num);
    l_ret = gpio_request_one(gpio_num, GPIOF_OUT_INIT_LOW, name);
    if (l_ret) {
        oam_warning_log0(0, 0, "wal_atcmsrv_ioctl_lte_gpio_set:set LTE_ISM_PRIORITY mode gpio fail");
        return -OAL_EFAIL;
    }
#endif
    return l_ret;
}

/*
 * 函 数 名  : wal_atcmsrv_ioctl_lte_gpio_set
 * 功能描述  : LTE共存引脚虚焊检测
 * 1.日    期  : 2015年7月12日
  *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmsrv_ioctl_lte_gpio_set(void)
{
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    int32_t l_ret;

    l_ret = wal_gpio_request_one(g_wlan_cust.ism_priority, WAL_ATCMDSRV_ISM_PRIORITY_NAME);
    if (l_ret) {
        oam_warning_log0(0, 0, "wal_atcmsrv_ioctl_lte_gpio_set:set LTE_ISM_PRIORITY mode gpio fail");
        return -OAL_EFAIL;
    }

    l_ret = wal_gpio_request_one(g_wlan_cust.lte_rx, WAL_ATCMDSRV_LTE_RX_NAME);
    if (l_ret) {
        oam_warning_log0(0, 0, "wal_atcmsrv_ioctl_lte_gpio_set:set LTE_RX_ACT mode gpio fail");
        return -OAL_EFAIL;
    }

    l_ret = wal_gpio_request_one(g_wlan_cust.lte_tx, WAL_ATCMDSRV_LTE_TX_NAME);
    if (l_ret) {
        oam_warning_log0(0, 0, "wal_atcmsrv_ioctl_lte_gpio_set:set LTE_TX_ACT mode gpio fail");
        return -OAL_EFAIL;
    }

    l_ret = wal_gpio_request_one(g_wlan_cust.lte_inact, WAL_ATCMDSRV_LTE_INACT_NAME);
    if (l_ret) {
        oam_warning_log0(0, 0, "wal_atcmsrv_ioctl_lte_gpio_set:set LTE_TX_ACT mode gpio fail");
        return -OAL_EFAIL;
    }

    l_ret = wal_gpio_request_one(g_wlan_cust.ism_rx_act, WAL_ATCMDSRV_ISM_RX_ACT_NAME);
    if (l_ret) {
        oam_warning_log0(0, 0, "wal_atcmsrv_ioctl_lte_gpio_set:set LTE_TX_ACT mode gpio fail");
        return -OAL_EFAIL;
    }

    l_ret = wal_gpio_request_one(g_wlan_cust.bant_pri, WAL_ATCMDSRV_BANT_PRI_NAME);
    if (l_ret) {
        oam_warning_log0(0, 0, "wal_atcmsrv_ioctl_lte_gpio_set:set LTE_TX_ACT mode gpio fail");
        return -OAL_EFAIL;
    }

    l_ret = wal_gpio_request_one(g_wlan_cust.bant_status, WAL_ATCMDSRV_BANT_STATUS_NAME);
    if (l_ret) {
        oam_warning_log0(0, 0, "wal_atcmsrv_ioctl_lte_gpio_set:set LTE_TX_ACT mode gpio fail");
        return -OAL_EFAIL;
    }

    l_ret = wal_gpio_request_one(g_wlan_cust.want_pri, WAL_ATCMDSRV_WANT_PRI_NAME);
    if (l_ret) {
        oam_warning_log0(0, 0, "wal_atcmsrv_ioctl_lte_gpio_set:set LTE_TX_ACT mode gpio fail");
        return -OAL_EFAIL;
    }

    if (wal_gpio_request_one(g_wlan_cust.want_status, WAL_ATCMDSRV_WANT_STATUS_NAME) != OAL_SUCC) {
        oam_warning_log0(0, 0, "wal_atcmsrv_ioctl_lte_gpio_set:set LTE_TX_ACT mode gpio fail");
        return -OAL_EFAIL;
    }
#endif
    return OAL_SUCC;
}
OAL_STATIC void wal_gpio_free(uint32_t gpio_num)
{
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    if (gpio_num == 0) {
        return;
    } else {
        oam_info_log1(0, 0, "wal_gpio_free:: free gpio %d", gpio_num);
        oal_gpio_free(gpio_num);
    }
#endif
}
/*
 * 函 数 名  : wal_atcmsrv_ioctl_lte_gpio_free
 * 功能描述  : LTE共存引脚虚焊检测
 * 1.日    期  : 2015年7月12日
  *   修改内容  : 新生成函数
 */
OAL_STATIC void wal_atcmsrv_ioctl_lte_gpio_free(oal_net_device_stru *pst_net_dev)
{
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    wal_msg_write_stru st_write_msg;
    int32_t l_ret;

    wal_gpio_free(g_wlan_cust.ism_priority);
    wal_gpio_free(g_wlan_cust.lte_rx);
    wal_gpio_free(g_wlan_cust.lte_tx);
    wal_gpio_free(g_wlan_cust.lte_inact);
    wal_gpio_free(g_wlan_cust.ism_rx_act);
    wal_gpio_free(g_wlan_cust.bant_pri);
    wal_gpio_free(g_wlan_cust.bant_status);
    wal_gpio_free(g_wlan_cust.want_pri);
    wal_gpio_free(g_wlan_cust.want_status);

    /***************************************************************************
         抛事件到wal层处理
     ***************************************************************************/
    /* 填写消息 */
    wal_write_msg_hdr_init(&st_write_msg, WLAN_CFGID_CHECK_LTE_GPIO, sizeof(int32_t));

    /* 设置LTE虚焊检测的模式 */
    *(int32_t *)(st_write_msg.auc_value) = CHECK_LTE_GPIO_RESUME;

    /* 发送消息 */
    l_ret = wal_send_cfg_event(pst_net_dev, WAL_MSG_TYPE_WRITE,
                               WAL_MSG_WRITE_MSG_HDR_LENGTH + sizeof(int32_t),
                               (uint8_t *)&st_write_msg, OAL_FALSE, NULL);
    if (oal_unlikely(l_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_ANY, "{wal_atcmsrv_ioctl_lte_gpio_mode::return err code %d!}\r\n", l_ret);
    }
#endif
}
/*
 * 函 数 名  : wal_atcmsrv_ioctl_lte_gpio_check
 * 功能描述  : LTE共存引脚虚焊检测
 * 1.日    期  : 2015年7月12日
  *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmsrv_ioctl_lte_gpio_check(oal_net_device_stru *pst_net_dev)
{
    int32_t l_ret;

    /* step1 设置管脚为gpio模式 */
    oam_warning_log0(0, 0, "wal_atcmsrv_ioctl_lte_gpio_check:enter lte gpio check!");
    /* 初始化host管脚 */
    l_ret = wal_atcmsrv_ioctl_lte_gpio_set();
    if (l_ret != OAL_SUCC) {
        return l_ret;
    }

    /* 初始化device lte共存引脚检测 */
    l_ret = wal_atcmsrv_ioctl_lte_gpio_mode(pst_net_dev, CHECK_LTE_GPIO_INIT);
    if (l_ret != OAL_SUCC) {
        oam_warning_log0(0, 0, "wal_atcmsrv_ioctl_lte_gpio_check:CHECK_LTE_GPIO_INIT FAIL!");
        wal_atcmsrv_ioctl_lte_gpio_free(pst_net_dev);
        return l_ret;
    }

    /* step2 设置host管脚为低，读取device结果 */
    /* 将gpio全部设置为低 */
    l_ret = wal_atcmsrv_ioctl_lte_gpio_level_set(0);
    if (l_ret != OAL_SUCC) {
        oam_warning_log0(0, 0, "wal_atcmsrv_ioctl_lte_gpio_check:SET LTE GPIO LOW FAIL!");
        wal_atcmsrv_ioctl_lte_gpio_free(pst_net_dev);
        return l_ret;
    }

    /* 读取device GPIO管脚电平 */
    l_ret = wal_atcmsrv_ioctl_lte_gpio_level_check(pst_net_dev, 0);
    if (l_ret != OAL_SUCC) {
        oam_warning_log1(0, 0,
                         "wal_atcmsrv_ioctl_lte_gpio_check:check gpio low mode FAIL[%x]!",
                         g_uc_dev_lte_gpio_level);
        wal_atcmsrv_ioctl_lte_gpio_free(pst_net_dev);
        return l_ret;
    }

    /* step3 设置host管脚为高，读取device结果 */
    /* 将gpio全部设置为高 */
    l_ret = wal_atcmsrv_ioctl_lte_gpio_level_set(1);
    if (l_ret != OAL_SUCC) {
        oam_warning_log0(0, 0, "wal_atcmsrv_ioctl_lte_gpio_check:SET LTE GPIO HIGH FAIL!");
        wal_atcmsrv_ioctl_lte_gpio_free(pst_net_dev);
        return l_ret;
    }

    /* 读取device GPIO管脚电平 */
    l_ret = wal_atcmsrv_ioctl_lte_gpio_level_check(pst_net_dev, 1);
    if (l_ret != 0) {
        oam_warning_log1(0, 0,
                         "wal_atcmsrv_ioctl_lte_gpio_check:check gpio high mode FAIL[%x]!",
                         g_uc_dev_lte_gpio_level);
        wal_atcmsrv_ioctl_lte_gpio_free(pst_net_dev);
        return l_ret;
    }

    wal_atcmsrv_ioctl_lte_gpio_free(pst_net_dev);

    return OAL_SUCC;
}
/*
 * 函 数 名  : wal_atcmsrv_ioctl_wipin_test
 * 功能描述  : wifi 管脚检测
 * 1.日    期  : 2016年10月08日
 *   作    者  : 修改内容
 *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmsrv_ioctl_wipin_test(oal_net_device_stru *pst_net_dev,
                                                wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    int32_t l_lte_status = 0;
    int32_t *pl_pin_status = &(pst_priv_cmd->pri_data.l_pin_status);
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    int32_t l_ret;
    oam_warning_log1(0, OAM_SF_ANY,
                     "{wal_atcmsrv_ioctl_wipin_test::ul_lte_gpio_check_switch is %d",
                     g_wlan_cust.lte_gpio_check_switch);
    /* 定制化是否检测lte共存管脚 */
    if (g_wlan_cust.lte_gpio_check_switch == 1) {
        /* 获取lte共存管脚结果 */
        l_ret = wal_atcmsrv_ioctl_lte_gpio_check(pst_net_dev);
        if (l_ret != OAL_SUCC) {
            l_lte_status = 1;
        }
    }
#endif
    *pl_pin_status = l_lte_status;

    if (*pl_pin_status != 0) {
        oam_error_log1(0, OAM_SF_ANY, "{wal_atcmsrv_ioctl_wipin_test::coe_lte_pin status is %d", *pl_pin_status);
        return -OAL_EINVAL;
    }

    return OAL_SUCC;
}

/*
 * 函 数 名  : wal_get_hw_status
 * 功能描述  : 获取硬件检测结果，包括fem、pa、host wakeup device引脚、lte共存管脚
 * 1.日    期  : 2015年7月12日
  *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_get_hw_status(oal_net_device_stru *pst_net_dev,
    wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    int32_t l_ret;
    uint32_t lte_status = 0;
    mp13_cali_param_stru *pst_cali_data_c0 = NULL;
    mp13_cali_param_stru *pst_cali_data_c1 = NULL;
    int32_t *pl_fem_pa_status = &(pst_priv_cmd->pri_data.l_fem_pa_status);

    if (g_wlan_cust.lte_gpio_check_switch == 1) {
        /* 获取lte共存管脚结果 */
        l_ret = wal_atcmsrv_ioctl_lte_gpio_check(pst_net_dev);
        if (l_ret != OAL_SUCC) {
            lte_status = 1;
        }
    }

    pst_cali_data_c0 = (mp13_cali_param_stru *)get_cali_data_buf_addr();
    if (pst_cali_data_c0 == NULL) {
        oam_error_log0(0, 0, "wal_get_hw_status::null ptr happened");
        return -OAL_EINVAL;
    }
    pst_cali_data_c1 = pst_cali_data_c0 + 1;
    if (pst_cali_data_c1 == NULL) {
        oam_error_log0(0, 0, "wal_get_hw_status::null ptr happened");
        return -OAL_EINVAL;
    }

    *pl_fem_pa_status = (int32_t)((pst_cali_data_c0->check_hw_status) |
                        (pst_cali_data_c1->check_hw_status << BIT_OFFSET_4) |
                        (lte_status << BIT_OFFSET_8));
    if (*pl_fem_pa_status != 0) {
        oam_error_log1(0, OAM_SF_ANY,
            "{wal_get_hw_status::FEM pa[%x].Bit:[0-1]2gc0,[2-3]5gc0,[4-5]2gc1,[6-7]5gc1,[8]lte_gpio}",
            *pl_fem_pa_status);
        return -OAL_EINVAL;
    }

    return OAL_SUCC;
}

/*
 * 函 数 名  : wal_get_mp15_hw_status
 * 功能描述  : 获取硬件检测结果，包括fem、pa、host wakeup device引脚、lte共存管脚
 * 1.日    期  : 2015年7月12日
 *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_get_mp15_hw_status(oal_net_device_stru *pst_net_dev,
    wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    int32_t                       l_ret;
    uint32_t                      lte_status = 0;
    mp15_cali_param_stru          *pst_cali_data_c0 = NULL;
    mp15_cali_param_stru          *pst_cali_data_c1 = NULL;
    int32_t                       *pl_fem_pa_status = &(pst_priv_cmd->pri_data.l_fem_pa_status);

    if (g_wlan_cust.lte_gpio_check_switch == 1) {
        /* 获取lte共存管脚结果 */
        l_ret = wal_atcmsrv_ioctl_lte_gpio_check(pst_net_dev);
        if (l_ret != OAL_SUCC) {
            lte_status = 1;
        }
    }

    pst_cali_data_c0 = (mp15_cali_param_stru *)get_cali_data_buf_addr();
    if (pst_cali_data_c0 == NULL) {
        oam_error_log0(0, 0, "wal_get_hw_status::null ptr happened");
        return -OAL_EINVAL;
    }
    pst_cali_data_c1 = pst_cali_data_c0 + 1;

    *pl_fem_pa_status = (int32_t)((pst_cali_data_c0->check_hw_status) |
                        (pst_cali_data_c1->check_hw_status << BIT_OFFSET_4) |
                        (lte_status << BIT_OFFSET_8));
    if (*pl_fem_pa_status != 0) {
        oam_error_log1(0, OAM_SF_ANY,
            "{wal_get_hw_status::FEM pa status[%x].Bit:[0-1]2gc0,[2-3]5gc0,[4-5]2gc1,[6-7]5gc1,[8]lte_gpio}",
            *pl_fem_pa_status);
        return -OAL_EINVAL;
    }

    return OAL_SUCC;
}

/*
 * 函 数 名  : wal_atcmsrv_ioctl_get_hw_status
 * 功能描述  : 获取硬件检测结果，包括fem、pa、host wakeup device引脚、lte共存管脚
 * 1.日    期  : 2015年7月12日
 *   修改内容  : 新生成函数
 */
int32_t wal_atcmsrv_ioctl_get_hw_status(oal_net_device_stru *pst_net_dev,
    wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    int32_t l_chip_type = get_mpxx_subchip_type();
    int32_t l_ret = 0;

    if (l_chip_type >= BOARD_VERSION_MP16) {
        wal_get_mp16_fem_pa_status(pst_net_dev, &(pst_priv_cmd->pri_data.l_fem_pa_status));
    } else if (l_chip_type == BOARD_VERSION_MP15) {
        l_ret = wal_get_mp15_hw_status(pst_net_dev, pst_priv_cmd);
    } else {
        l_ret = wal_get_hw_status(pst_net_dev, pst_priv_cmd);
    }
    return l_ret;
}

#ifdef PLATFORM_DEBUG_ENABLE
/*
 * 函 数 名  : wal_atcmsrv_ioctl_set_always_rx
 * 功能描述  : 打开长收功能
 * 1.日    期  : 2015年10月10日
  *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmsrv_ioctl_set_always_rx(oal_net_device_stru *pst_net_dev,
                                                   wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    wal_msg_write_stru st_write_msg;
    int32_t l_ret;
    uint8_t auc_param[] = { "all" };
    uint16_t us_len;
    int32_t l_always_rx = pst_priv_cmd->pri_data.l_awalys_rx;

    /* 将状态赋值 */
    *(uint8_t *)(st_write_msg.auc_value) = (uint8_t)l_always_rx;

    /***************************************************************************
                                抛事件到wal层处理
    ***************************************************************************/
    wal_write_msg_hdr_init(&st_write_msg, WLAN_CFGID_SET_ALWAYS_RX, sizeof(uint8_t));

    l_ret = wal_send_cfg_event(pst_net_dev, WAL_MSG_TYPE_WRITE,
                               WAL_MSG_WRITE_MSG_HDR_LENGTH + sizeof(uint8_t),
                               (uint8_t *)&st_write_msg, OAL_FALSE, NULL);
    if (oal_unlikely(l_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_ANY, "{wal_hipriv_always_rx::return err code [%d]!}\r\n", l_ret);
        return l_ret;
    }

    if (l_always_rx) {
        /* 打印所有寄存器 */
        /***************************************************************************
                                    抛事件到wal层处理
        ***************************************************************************/
        if (memcpy_s(st_write_msg.auc_value, sizeof(st_write_msg.auc_value),
            auc_param, OAL_STRLEN((int8_t *)auc_param)) != EOK) {
            oam_error_log0(0, OAM_SF_ANY, "{wal_hipriv_always_rx::memcpy_s fail !}\r\n");
            return OAL_FAIL;
        }

        st_write_msg.auc_value[OAL_STRLEN((int8_t *)auc_param)] = '\0';
        us_len = (uint16_t)(OAL_STRLEN((int8_t *)auc_param) + 1);

        wal_write_msg_hdr_init(&st_write_msg, WLAN_CFGID_REG_INFO, us_len);

        l_ret = wal_send_cfg_event(pst_net_dev, WAL_MSG_TYPE_WRITE,
                                   WAL_MSG_WRITE_MSG_HDR_LENGTH + us_len, (uint8_t *)&st_write_msg,
                                   OAL_FALSE, NULL);
        if (oal_unlikely(l_ret != OAL_SUCC)) {
            oam_warning_log1(0, OAM_SF_ANY, "{wal_atcmsrv_ioctl_set_always_rx::return err code [%d]!}\r\n", l_ret);
        }
    }
    return OAL_SUCC;
}
#endif
/*
 * 函 数 名  : wal_atcmsrv_ioctl_set_pm_switch
 * 1.日    期  : 2015年7月12日
  *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmsrv_ioctl_set_pm_switch(oal_net_device_stru *pst_net_dev,
                                                   wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    uint32_t ret;
    int32_t pm_switch = pst_priv_cmd->pri_data.l_pm_switch;
    uint32_t cmd_id;
    uint32_t offset = 0;

    oam_warning_log1(0, OAM_SF_ANY, "wal_atcmsrv_ioctl_set_pm_switch:l_pm_switch[%d]", pm_switch);

    ret = wal_get_cmd_id("pm_switch", &cmd_id, &offset);
    if (ret != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_ANY, "wal_atcmsrv_ioctl_set_pm_switch:find pm_switch cmd is fail");
        return -OAL_EINVAL;
    }
    ret = wal_process_cmd_params(pst_net_dev, cmd_id, &pm_switch);
    if (oal_unlikely(ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_ANY,
                         "{wal_atcmsrv_ioctl_set_pm_switch::wal_process_cmd_params return err code [%d]!}\r\n",
                         ret);
        return -OAL_EINVAL;
    }
    ret = wal_hipriv_sta_pm_on(pst_net_dev, " 0 ");
    if (oal_unlikely(ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_ANY,
                         "{wal_atcmsrv_ioctl_set_pm_switch::CMD_SET_STA_PM_ON return err code [%d]!}\r\n",
                         ret);
        return -OAL_EFAIL;
    }

    return OAL_SUCC;
}

/*
 * 函 数 名  : wal_atcmsrv_ioctl_get_rx_rssi
 * 功能描述  : 查询接收RSSI值
 * 1.日    期  : 2015年10月10日
  *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmsrv_ioctl_get_rx_rssi(oal_net_device_stru *pst_net_dev,
                                                 wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    int32_t l_ret;
    mac_cfg_rx_fcs_info_stru *pst_rx_fcs_info = NULL;
    wal_msg_write_stru st_write_msg;
    mac_vap_stru *pst_mac_vap = NULL;
    hmac_vap_stru *pst_hmac_vap = NULL;
    int32_t i_leftime;
    int32_t *pl_rx_rssi = &(pst_priv_cmd->pri_data.l_rx_rssi);

    pst_mac_vap = oal_net_dev_priv(pst_net_dev);
    if (pst_mac_vap == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "{wal_atcmsrv_ioctl_get_rx_rssi::OAL_NET_DEV_PRIV, return null!}");
        return -OAL_EINVAL;
    }

    pst_hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(pst_mac_vap->uc_vap_id);
    if (pst_hmac_vap == NULL) {
        oam_error_log0(pst_mac_vap->uc_vap_id, OAM_SF_ANY,
                       "{wal_atcmsrv_ioctl_get_rx_rssi::mac_res_get_hmac_vap failed!}");
        return -OAL_EINVAL;
    }

    /***************************************************************************
                                抛事件到wal层处理
    ***************************************************************************/
    pst_hmac_vap->st_atcmdsrv_get_status.uc_get_rx_pkct_flag = OAL_FALSE;
    wal_write_msg_hdr_init(&st_write_msg, WLAN_CFGID_RX_FCS_INFO, sizeof(mac_cfg_rx_fcs_info_stru));

    /* 设置配置命令参数 */
    pst_rx_fcs_info = (mac_cfg_rx_fcs_info_stru *)(st_write_msg.auc_value);
    /* 这两个参数在02已经没有意义 */
    pst_rx_fcs_info->data_op = 0;
    pst_rx_fcs_info->print_info = 0;

    l_ret = wal_send_cfg_event(pst_net_dev, WAL_MSG_TYPE_WRITE,
        WAL_MSG_WRITE_MSG_HDR_LENGTH + sizeof(mac_cfg_rx_fcs_info_stru), (uint8_t *)&st_write_msg, OAL_FALSE, NULL);
    if (oal_unlikely(l_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_ANY, "{wal_atcmsrv_ioctl_get_rx_rssi::return err code %d!}\r\n", l_ret);
        return l_ret;
    }

    /* 阻塞等待dmac上报 */
    i_leftime = oal_wait_event_interruptible_timeout_m(pst_hmac_vap->query_wait_q,
        (uint32_t)(pst_hmac_vap->st_atcmdsrv_get_status.uc_get_rx_pkct_flag == OAL_TRUE),
        WAL_ATCMDSRB_GET_RX_PCKT);
    if (i_leftime == 0) {
        /* 超时还没有上报扫描结束 */
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_ANY,
                         "{wal_atcmsrv_ioctl_get_rx_rssi::get_rssi wait for %ld ms timeout!}",
                         ((WAL_ATCMDSRB_DBB_NUM_TIME * HMAC_S_TO_MS) / OAL_TIME_HZ));
        return -OAL_EINVAL;
    } else if (i_leftime < 0) {
        /* 定时器内部错误 */
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_ANY,
                         "{wal_atcmsrv_ioctl_get_rx_rssi::get_rssi wait for %ld ms error!}",
                         ((WAL_ATCMDSRB_DBB_NUM_TIME * HMAC_S_TO_MS) / OAL_TIME_HZ));
        return -OAL_EINVAL;
    } else {
        /* 正常结束  */
        *pl_rx_rssi = pst_hmac_vap->st_atcmdsrv_get_status.s_rx_rssi;
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_ANY, "{wal_atcmsrv_ioctl_get_rx_rssi::get rssi [%d]!}",
                         *pl_rx_rssi);
        return OAL_SUCC;
    }
}

/*
 * 函 数 名  : wal_atcmsrv_ioctl_set_chipcheck
 * 功能描述  : 进行芯片自检，获取自检结果
 * 1.日    期  : 2015年10月10日
  *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmsrv_ioctl_set_chipcheck(oal_net_device_stru *pst_net_dev,
                                                   wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    int32_t ret;
    int32_t l_runing_test_mode = pst_priv_cmd->pri_data.l_runingtest_mode;

    ret = wlan_device_mem_check(l_runing_test_mode);

    return ret;
}

/*
 * 函 数 名  : wal_atcmsrv_ioctl_get_chipcheck_result
 * 功能描述  : 进行芯片自检，获取自检结果
 * 1.日    期  : 2015年10月10日
  *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmsrv_ioctl_get_chipcheck_result(oal_net_device_stru *pst_net_dev,
                                                          wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    int32_t *l_chipcheck_result = &(pst_priv_cmd->pri_data.l_chipcheck_result);
    *l_chipcheck_result = wlan_device_mem_check_result(&g_chipcheck_total_time);

    oam_warning_log1(0, OAM_SF_ANY, "wal_atcmsrv_ioctl_get_chipcheck_result:result[%d]", *l_chipcheck_result);
    return OAL_SUCC;
}

/*
 * 函 数 名  : wal_atcmsrv_ioctl_get_chipcheck_time
 * 功能描述  : 查询chipcheck所用时间
 * 1.日    期  : 2015年10月10日
  *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmsrv_ioctl_get_chipcheck_time(oal_net_device_stru *pst_net_dev,
                                                        wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    uint64_t *ull_chipcheck_time = &(pst_priv_cmd->pri_data.ull_chipcheck_time);
    *ull_chipcheck_time = g_chipcheck_total_time;

    oam_warning_log1(0, OAM_SF_ANY, "wal_atcmsrv_ioctl_get_chipcheck_time:[%d]", g_chipcheck_total_time);
    return OAL_SUCC;
}

/*
 * 函 数 名  : wal_atcmsrv_ioctl_set_uart_loop
 * 功能描述  : uart环回测试
 * 1.日    期  : 2015年10月10日
  *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmsrv_ioctl_set_uart_loop(oal_net_device_stru *pst_net_dev,
                                                   wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    int32_t *l_uart_loop_set = &(pst_priv_cmd->pri_data.l_uart_loop_set);
    return conn_test_uart_loop((int8_t *)&l_uart_loop_set);
}

/*
 * 函 数 名  : wal_atcmsrv_ioctl_set_wifi_chan_loop
 * 功能描述  : 查询chipcheck所用时间
 * 1.日    期  : 2015年10月10日
  *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmsrv_ioctl_set_wifi_chan_loop(oal_net_device_stru *pst_net_dev,
                                                        wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    int32_t ret;
    int32_t *l_wifi_chan_loop_set = &(pst_priv_cmd->pri_data.l_wifi_chan_loop_set);
    mpxx_bind_hcc_thread(1, 1, 1);
    /* Test High freq interface, lock host cpufreq */
    hmac_set_cpu_freq(WLAN_CPU_FREQ_SUPER);
    ret = conn_test_wifi_chan_loop((int8_t *)&l_wifi_chan_loop_set);
    hmac_set_cpu_freq(WLAN_CPU_FREQ_IDLE);
    mpxx_bind_hcc_thread(0, 0, 0);
    return ret;
}
#ifdef PLATFORM_DEBUG_ENABLE
/*
 * 函 数 名  : wal_atcmdsrv_efuse_regs_read
 * 1.日    期  : 2015年12月9日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmdsrv_efuse_regs_read(oal_net_device_stru *pst_net_dev)
{
    int32_t l_ret;
    wal_msg_write_stru st_write_msg;
    hmac_vap_stru *pst_hmac_vap = NULL;
    int32_t i_leftime;
    uint8_t auc_param[] = { "efuse" };
    uint16_t us_len;
    mac_vap_stru *pst_mac_vap = oal_net_dev_priv(pst_net_dev);
    if (pst_mac_vap == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "{wal_atcmdsrv_efuse_regs_read::OAL_NET_DEV_PRIV, return null!}");
        return -OAL_EINVAL;
    }

    pst_hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(pst_mac_vap->uc_vap_id);
    if (pst_hmac_vap == NULL) {
        oam_error_log0(pst_mac_vap->uc_vap_id, OAM_SF_ANY,
                       "{wal_atcmdsrv_efuse_regs_read::mac_res_get_hmac_vap failed!}");
        return -OAL_EINVAL;
    }

    pst_hmac_vap->st_atcmdsrv_get_status.uc_report_efuse_reg_flag = OAL_FALSE;

    /* 打印所有寄存器 */
    /***************************************************************************
                                抛事件到wal层处理
    ***************************************************************************/
    if (memcpy_s(st_write_msg.auc_value, sizeof(st_write_msg.auc_value),
        auc_param, OAL_STRLEN((int8_t *)auc_param)) != EOK) {
        oam_error_log0(pst_mac_vap->uc_vap_id, OAM_SF_ANY, "{wal_atcmdsrv_efuse_regs_read::memcpy_s failed!}");
        return -OAL_EINVAL;
    }
    st_write_msg.auc_value[OAL_STRLEN((int8_t *)auc_param)] = '\0';

    us_len = (uint16_t)(OAL_STRLEN((int8_t *)auc_param) + 1);

    wal_write_msg_hdr_init(&st_write_msg, WLAN_CFGID_REG_INFO, us_len);

    l_ret = wal_send_cfg_event(pst_net_dev, WAL_MSG_TYPE_WRITE, WAL_MSG_WRITE_MSG_HDR_LENGTH + us_len,
                               (uint8_t *)&st_write_msg, OAL_FALSE, NULL);
    if (oal_unlikely(l_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_ANY, "{wal_atcmdsrv_efuse_regs_read::return err code [%d]!}\r\n", l_ret);
        return -OAL_EINVAL;
    }

    /* 阻塞等待dmac上报 */
    i_leftime = oal_wait_event_interruptible_timeout_m(pst_hmac_vap->query_wait_q,
        (uint32_t)(pst_hmac_vap->st_atcmdsrv_get_status.uc_report_efuse_reg_flag == OAL_TRUE),
        WAL_ATCMDSRB_DBB_NUM_TIME);
    if (i_leftime == 0) {
        /* 超时还没有上报扫描结束 */
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_ANY,
                         "{wal_atcmdsrv_efuse_regs_read::efuse_regs wait for %ld ms timeout!}",
                         ((WAL_ATCMDSRB_DBB_NUM_TIME * HMAC_S_TO_MS) / OAL_TIME_HZ));
        return -OAL_EINVAL;
    } else if (i_leftime < 0) {
        /* 定时器内部错误 */
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_ANY,
                         "{wal_atcmdsrv_efuse_regs_read::efuse_regs wait for %ld ms error!}",
                         ((WAL_ATCMDSRB_DBB_NUM_TIME * HMAC_S_TO_MS) / OAL_TIME_HZ));
        return -OAL_EINVAL;
    }
    return OAL_SUCC;
}

/*
 * 函 数 名  : wal_atcmdsrv_efuse_info_print
 * 1.日    期  : 2015年12月9日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC void wal_atcmdsrv_efuse_info_print(void)
{
    uint32_t loop;
    uint32_t high_bit = WAL_ATCMDSRV_EFUSE_REG_WIDTH - 1;
    uint32_t low_bit = 0;
    for (loop = 0; loop < WAL_ATCMDSRV_EFUSE_BUFF_LEN; loop++) {
        oam_warning_log3(0, 0,
                         "DIE_ID: ATE bits:[%d:%d] value[0x%x]",
                         high_bit, low_bit, g_us_efuse_buffer[loop]);
        high_bit += WAL_ATCMDSRV_EFUSE_REG_WIDTH;
        low_bit += WAL_ATCMDSRV_EFUSE_REG_WIDTH;
    }
}
/*
 * 函 数 名  : wal_atcmdsrv_ioctl_efuse_bits_check
 * 1.日    期  : 2015年12月9日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmdsrv_ioctl_efuse_bits_check(void)
{
    int32_t result = OAL_SUCC;
    int32_t        l_chip_type = get_mpxx_subchip_type();

    g_efuse_bits = (wal_efuse_bits *)g_us_efuse_buffer;

    /* 打印所有efuse字段 */
    wal_atcmdsrv_efuse_info_print();

    /*******************************************
      efuse rd_data10映射位域为
        IR 15:15
        GNSS 14:14
        FM 13:13
        BT 12:12
        WIIF 11:11
        CHIP_VER 10:8
        CHID_ID 7:0
    *******************************************/
    if (l_chip_type == BOARD_VERSION_MP15) {
        if (g_efuse_bits->efuse_rd_10_11.chip_id != WAL_ATCMDSRV_EFUSE_CHIP_ID_MP15) {
            oam_error_log1(0, 0,
                           "wal_atcmdsrv_ioctl_efuse_bits_check::chip ver expect value[0x5] error value[0x%x]\n",
                           g_efuse_bits->efuse_rd_10_11.chip_id);
            result = -OAL_EINVAL;
        }
    } else {
        if (g_efuse_bits->efuse_rd_10_11.chip_id != WAL_ATCMDSRV_EFUSE_CHIP_ID_MP13) {
            oam_error_log1(0, 0,
                           "wal_atcmdsrv_ioctl_efuse_bits_check::chip ver expect value[0x3] error value[0x%x]\n",
                           g_efuse_bits->efuse_rd_10_11.chip_id);
            result = -OAL_EINVAL;
        }
    }

    return result;
}

/*
 * 函 数 名  : wal_atcmsrv_ioctl_dieid_inform
 * 功能描述  : 上报die_id
 * 1.日    期  : 2016年1月15日
  *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmsrv_ioctl_dieid_inform(oal_net_device_stru *pst_net_dev,
                                                  wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    int32_t l_ret;
    uint16_t loop = 0;
    uint16_t efuse_len = WAL_ATCMDSRV_EFUSE_BUFF_LEN / 2;
    uint16_t *pl_die_id = pst_priv_cmd->pri_data.die_id;

    /* 获取efuse字段 */
    l_ret = wal_atcmdsrv_efuse_regs_read(pst_net_dev);
    if (l_ret != OAL_SUCC) {
        oam_warning_log0(0, 0, "wal_atcmsrv_ioctl_efuse_check:get efuse reg fail");
        return l_ret;
    }
    /* 上报efuse字段, efuse字段大小为16 * 2byte */
    for (loop = 0; loop < efuse_len; loop++) {
        pl_die_id[loop] = g_us_efuse_buffer[loop];
    }
    return OAL_SUCC;
}

/*
 * 函 数 名  : wal_atcmsrv_ioctl_efuse_check
 * 功能描述  : 设置接收mac地址
 * 1.日    期  : 2016年1月15日
  *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmsrv_ioctl_efuse_check(oal_net_device_stru *pst_net_dev,
                                                 wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    int32_t l_ret;
    int32_t *pl_efuse_check_result = &(pst_priv_cmd->pri_data.l_efuse_check_result);

    /* 获取efuse字段 */
    l_ret = wal_atcmdsrv_efuse_regs_read(pst_net_dev);
    if (l_ret != OAL_SUCC) {
        oam_warning_log0(0, 0, "wal_atcmsrv_ioctl_efuse_check:get efuse reg fail");
        *pl_efuse_check_result = 1;
        return l_ret;
    }
    /* 检测efuse字段 */
    l_ret = wal_atcmdsrv_ioctl_efuse_bits_check();
    if (l_ret != OAL_SUCC) {
        oam_warning_log0(0, 0, "wal_atcmsrv_ioctl_efuse_check:check efuse reg fail");
        *pl_efuse_check_result = 1;
    }

    return l_ret;
}
#endif
#ifdef _PRE_WLAN_FEATURE_M2S
/*
 * 函 数 名  : wal_atcmsrv_ioctl_set_mimo_ch
 * 功能描述  : 设置双通道模式下通道
 *             1:ch0    2:ch1
 * 1.日    期  : 2017年4月13日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmsrv_ioctl_set_mimo_ch(oal_net_device_stru *pst_net_dev,
                                                 wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    int32_t l_ret;
    int8_t pc_param[NUM_6_BYTES] = "3 0 0";
    // 06使用二进制形式标识通道，如C2 SISO表示为：0100
    int8_t pc_param_mp16[][NUM_9_BYTES] = { "3 0001 0", "3 0010 0", "3 0100 0", "3 1000 0", "3 1111 0" };
    int32_t l_mimo_channel = pst_priv_cmd->pri_data.l_mimo_channel;

    oam_warning_log1(0, OAM_SF_ANY, "wal_atcmsrv_ioctl_set_mimo_ch::mimo_channel[%d]", l_mimo_channel--);

    if (get_mpxx_subchip_type() <= BOARD_VERSION_MP15) {
        pc_param[BYTE_OFFSET_2] += l_mimo_channel;
        /* "3 0/1/2 0" for mimo/siso switch */
        l_ret = (int32_t)wal_hipriv_set_m2s_switch(pst_net_dev, pc_param);
    } else {
        l_ret = (int32_t)wal_hipriv_set_m2s_switch(pst_net_dev, pc_param_mp16[l_mimo_channel]);
    }

    return l_ret;
}
#endif

/*
 * 函 数 名  : wal_atcmsrv_ioctl_get_dp_init
 * 功能描述  : 查询驱动侧的dp_init
 * 1.日    期  : 2017年12月28日
 *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmsrv_ioctl_get_dp_init(oal_net_device_stru *pst_net_dev,
                                                 wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    uint8_t uc_i;
    int8_t *c_dp_init = pst_priv_cmd->pri_data.ac_dp_init;

    /* 1.读取NV中dp_init是否空的标志位 */
    c_dp_init[0] = (int8_t)g_en_nv_dp_init_is_null;
    oam_warning_log1(0, OAM_SF_ANY, "wal_atcmsrv_ioctl_get_dp_init::dp_init_status[%d]", c_dp_init[0]);

    /* 2.若为空，将device计算结果上报,AT部分写入NV */
    if (c_dp_init[0] == OAL_TRUE) {
        /* 维测 */
        hmac_dump_cali_result();

        if (get_cali_data_buf_addr() == NULL) {
            oam_warning_log0(0, 0, "{wal_atcmsrv_ioctl_get_dp_init::null ptr!}");
            return -OAL_EINVAL;
        }

        for (uc_i = 0; uc_i < DP_INIT_EACH_CORE_NUM; uc_i++) {
            /* 现在功率校准由13个信道修改为3个信道，但是上层接口还是13个，且暂时不用dpinit，全部复制为0，接口预留 */
            // pst_cali_data_c0->ast_2Gcali_param.st_cali_tx_power_cmp_2G[uc_i].c_dp_init;      // core 0 的dp_init
            c_dp_init[uc_i + DP_INIT_FLAG_NUM] = 0;
            // pst_cali_data_c1->ast_2Gcali_param.st_cali_tx_power_cmp_2G[uc_i].c_dp_init;// core 1的dp_init
            c_dp_init[uc_i + DP_INIT_FLAG_NUM + DP_INIT_EACH_CORE_NUM] = 0;
        }
    }

    return OAL_SUCC;
}

/*
 * 函 数 名  : wal_atcmsrv_ioctl_get_pd_tran_param
 * 功能描述  : 查询驱动侧的初始校准参数
 * 1.日    期  : 2017年12月28日
 *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmsrv_ioctl_get_pd_tran_param(oal_net_device_stru *pst_net_dev,
                                                       wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    int8_t *c_pd_param = pst_priv_cmd->pri_data.ac_pd_tran_param;
    uint32_t param_num = (uint32_t)c_pd_param[WAL_ATCMDSRV_NV_WINVRAM_LENGTH - 1];
    int8_t *pc_pd_info = NULL;

    oam_warning_log1(0, 0,
                     "wal_atcmsrv_ioctl_get_pd_tran_param::s_pd_param end element is %d",
                     c_pd_param[WAL_ATCMDSRV_NV_WINVRAM_LENGTH - 1]);

    if (param_num >= WLAN_CFG_DTS_NVRAM_END) {
        oam_error_log1(0, 0, "wal_atcmsrv_ioctl_get_pd_tran_param::num[%d] larger than array_row", param_num);
        return -OAL_EINVAL;
    }

    pc_pd_info = (int8_t *)hwifi_get_nvram_param(param_num);
    if (pc_pd_info == NULL) {
        oam_warning_log0(0, 0, "wal_atcmsrv_ioctl_get_pd_tran_param::null ptr!");
        return -OAL_EINVAL;
    }

    if (EOK != memcpy_s(c_pd_param, sizeof(pst_priv_cmd->pri_data.ac_pd_tran_param),
                        pc_pd_info, oal_min(WAL_ATCMDSRV_NV_WINVRAM_LENGTH, CUS_PARAMS_LEN_MAX))) {
        oam_error_log0(0, 0, "wal_atcmsrv_ioctl_get_pd_tran_param::memcpy fail!");
        return -OAL_EINVAL;
    }

    oal_io_print("wal_atcmsrv_ioctl_get_pd_tran_param::pd_param is %s", c_pd_param);
    return OAL_SUCC;
}

/*
 * 函 数 名  : wal_atcmsrv_ioctl_io_test
 * 功能描述  : 唤醒io产线测试接口
 * 1.日    期  : 2017年12月28日
 *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmsrv_ioctl_io_test(oal_net_device_stru *pst_net_dev,
                                             wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    int32_t l_ret;
    int16_t *s_wkup_io_status = &(pst_priv_cmd->pri_data.s_wkup_io_status);

    oam_warning_log0(0, 0, "{wal_atcmsrv_ioctl_io_test::func entered}");
    l_ret = hi1103_dev_io_test();
    if (l_ret != OAL_SUCC) {
        oam_warning_log1(0, 0, "{wal_atcmsrv_ioctl_io_test::io test ret is %d}", l_ret);
        *s_wkup_io_status = 1;
    }

    return l_ret;
}

/*
 * 函 数 名  : wal_atcmdsrv_ioctl_pcie_ip_test
 * 功能描述  : pcie ip产线测试
 * 1.日    期  : 2017年12月28日
 *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmdsrv_ioctl_pcie_ip_test(oal_net_device_stru *pst_net_dev,
                                                   wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
#ifdef _PRE_PLAT_FEATURE_HI110X_PCIE
    int32_t l_ret;
    int32_t l_test_count = 1;
    int16_t *s_pcie_status = &(pst_priv_cmd->pri_data.s_pcie_status);

    oam_warning_log0(0, 0, "{wal_atcmdsrv_ioctl_pcie_ip_test::func entered}");

    l_ret = hi1103_pcie_ip_test(l_test_count);
    if (l_ret != OAL_SUCC) {
        oam_warning_log1(0, 0, "{wal_atcmdsrv_ioctl_pcie_ip_test::pcie_ip test ret is %d}", l_ret);
        *s_pcie_status = 1;
    }

    return l_ret;
#else
    return OAL_SUCC;
#endif
}

/*
 * 函 数 名  : wal_atcmdsrv_ioctl_dyn_intervel_set
 * 功能描述  : pcie ip产线测试
 * 1.日    期  : 2017年12月28日
 *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmdsrv_ioctl_dyn_intervel_set(oal_net_device_stru *pst_net_dev,
                                                       wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    int32_t l_ret;
    int8_t c_dyn_cmd[WAL_ATCMDSRV_WIFI_CHAN_NUM][WAL_ATCMDSRV_DYN_INTVAL_LEN] = {
        "2g_dscr_interval  ", "5g_dscr_interval  "
    };
    int8_t c_i;
    int8_t *c_dyn_intv = pst_priv_cmd->pri_data.c_dyn_interval;

    for (c_i = 0; c_i < WAL_ATCMDSRV_WIFI_CHAN_NUM; c_i++) {
        c_dyn_cmd[c_i][WAL_ATCMDSRV_DYN_INTVAL_LOCATION] = c_dyn_intv[c_i];
        l_ret = (int32_t)wal_hipriv_dyn_cali_cfg(pst_net_dev, &c_dyn_cmd[c_i][0]);
        if (l_ret != OAL_SUCC) {
            oam_warning_log1(0, 0, "{wal_atcmdsrv_ioctl_dyn_intervel_set::ret is %d}", l_ret);
        }
    }
    return OAL_SUCC;
}

/*
 * 函 数 名  : wal_atcmdsrv_ioctl_selfcali_intervel_set
 * 功能描述  : 产线测试时，设置wifi为每次开关进行自校准
 * 1.日    期  : 2017年12月28日
 *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmdsrv_ioctl_selfcali_intervel_set(oal_net_device_stru *pst_net_dev,
                                                            wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    int32_t l_selfcali_en = pst_priv_cmd->pri_data.l_selfcali_interval_set;
    /* selcali_en: 1 for sel_cali every time, 0 for never sel_cal */
    if (!l_selfcali_en) {
        g_wlan_cal_disable_switch = OAL_TRUE;
    }
    if (l_selfcali_en) {
        g_wlan_cal_intvl_enable = OAL_FALSE; /* 使能每次上下电自校准 */
        g_wlan_cal_disable_switch = OAL_FALSE;
    }

    oam_warning_log1(0, 0, "wal_atcmdsrv_ioctl_selfcali_intervel_set::set selfcali_interval to [%d]!", l_selfcali_en);
    return OAL_SUCC;
}
/*
 * 函 数 名  : wal_atcmdsrv_ioctl_set_ru_test
 * 功能描述  : 设置11ax ru模式
 * 日    期  : 2019年7月29日
 * 修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmdsrv_ioctl_set_ru_test(oal_net_device_stru *pst_net_dev,
    wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    wal_msg_write_stru st_write_msg;
    st_wal_atcmdsrv_wifi_rumode_info *pst_ru_param = NULL;
    int32_t l_ret;
    st_wal_atcmdsrv_wifi_rumode_info st_ru_info = pst_priv_cmd->pri_data.st_ru_info;

    oam_warning_log2(0, 0,
        "wal_atcmdsrv_ioctl_selfcali_intervel_set::ru_dir[%d], aid[0x%x]!",
        st_ru_info.us_rudir, st_ru_info.us_aid);

    /***************************************************************************
           抛事件到wal层处理
       ***************************************************************************/
    /* 填写消息 */
    wal_write_msg_hdr_init(&st_write_msg, WLAN_CFGID_SET_RU_TEST, sizeof(st_wal_atcmdsrv_wifi_rumode_info));

    /* 设置模式，在配置模式的时候将带宽默认成20M */
    pst_ru_param = (st_wal_atcmdsrv_wifi_rumode_info *)(st_write_msg.auc_value);
    pst_ru_param->us_aid = st_ru_info.us_aid;
    pst_ru_param->us_rudir = st_ru_info.us_rudir;

    /* 发送消息 */
    l_ret = wal_send_cfg_event(pst_net_dev, WAL_MSG_TYPE_WRITE,
        WAL_MSG_WRITE_MSG_HDR_LENGTH + sizeof(mac_cfg_mode_param_stru),
        (uint8_t *)&st_write_msg, OAL_FALSE, NULL);
    if (oal_unlikely(l_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_ANY, "{wal_atcmsrv_ioctl_set_mode::return err code %d!}\r\n", l_ret);
    }

    return l_ret;
}

/*
 * 函 数 名  : wal_atcmdsrv_ioctl_dyn_intervel_set
 * 功能描述  : pcie ip产线测试
 * 1.日    期  : 2017年12月28日
 *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmdsrv_ioctl_pt_set(oal_net_device_stru *pst_net_dev,
                                             wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    int32_t l_pt_set = pst_priv_cmd->pri_data.l_pt_set;

    if (l_pt_set) {
        oam_warning_log0(0, 0, "pt_test pull up power_on_enable gpio!\n");
        board_chip_power_on();
    } else {
        oam_warning_log0(0, 0, "pt_test pull down power_on_enable gpio!\n");
        board_chip_power_off();
    }

    return OAL_SUCC;
}

/*
 * 函 数 名  : wal_atcmdsrv_ioctl_tas_ant_set
 * 功能描述  : tas产线测试
 * 1.日    期  : 2017年12月28日
 *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmdsrv_ioctl_tas_ant_set(oal_net_device_stru *pst_net_dev,
                                                  wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    int32_t l_tas_ant_set = pst_priv_cmd->pri_data.l_tas_ant_set;

    board_wifi_tas_set(l_tas_ant_set);

    return OAL_SUCC;
}

/*
 * 函 数 名  : wal_atcmsrv_ioctl_set_bss_expire_age
 * 功能描述  : 设置芯片扫描结果老化时间
 * 1.日    期  : 2018年5月31日
 *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmsrv_ioctl_set_bss_expire_age(oal_net_device_stru *pst_net_dev,
                                                        wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    uint32_t expire_age = pst_priv_cmd->pri_data.bss_expire_age;
    g_pd_bss_expire_time = (expire_age < WAL_ATCMSRV_MIN_BSS_EXPIRATION_AGE) ?
        WAL_ATCMSRV_MIN_BSS_EXPIRATION_AGE : expire_age;
    g_pd_bss_expire_time = (g_pd_bss_expire_time > WAL_ATCMSRV_MAX_BSS_EXPIRATION_AGE) ?
        WAL_ATCMSRV_MAX_BSS_EXPIRATION_AGE : g_pd_bss_expire_time;

    oam_warning_log2(0, OAM_SF_CFG, "wal_atcmsrv_ioctl_set_bss_expire_age::pd_bss_expire_time %d, input expire time %d",
                     g_pd_bss_expire_time, expire_age);

    return OAL_SUCC;
}

OAL_STATIC int32_t wal_get_up_vap_connect_info(mac_vap_stru *mac_vap,
    struct wal_atcmdsrv_wifi_connect_info *connect_info)
{
    hmac_vap_stru *hmac_vap = NULL;
    hmac_bss_mgmt_stru *bss_mgmt = NULL; /* 管理扫描的bss结果的结构体 */
    hmac_device_stru *hmac_device = NULL;
    hmac_scanned_bss_info *scanned_bss_info = NULL;

    hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(mac_vap->uc_vap_id);
    if (hmac_vap == NULL) {
        oam_error_log1(0, OAM_SF_ANY,
            "{wal_atcmsrv_ioctl_get_wifi_connect_info::mac_res_get_hmac_vap fail.vap_id[%u]}", mac_vap->uc_vap_id);
        return -OAL_EINVAL;
    }

    /* 获取hmac device 结构 */
    hmac_device = hmac_res_get_mac_dev(mac_vap->uc_device_id);
    if (hmac_device == NULL) {
        oam_warning_log0(0, OAM_SF_SCAN, "{wal_atcmsrv_ioctl_get_wifi_connect_info::hmac_device is null.}");
        return -OAL_EINVAL;
    }

    connect_info->en_status = ATCMDSRV_WIFI_CONNECTED;
    connect_info->c_rssi = hmac_vap->station_info.signal;
    memcpy_s(connect_info->auc_bssid, WLAN_MAC_ADDR_LEN, mac_vap->auc_bssid, WLAN_MAC_ADDR_LEN);

    /* 获取管理扫描的bss结果的结构体 */
    bss_mgmt = &(hmac_device->st_scan_mgmt.st_scan_record_mgmt.st_bss_mgmt);
    /* 对链表删操作前加锁 */
    oal_spin_lock(&(bss_mgmt->st_lock));
    scanned_bss_info = hmac_scan_find_scanned_bss_by_bssid(bss_mgmt, connect_info->auc_bssid, WLAN_MAC_ADDR_LEN);
    if (scanned_bss_info == NULL) {
        oam_warning_log4(mac_vap->uc_vap_id, OAM_SF_CFG,
            "{wal_atcmsrv_ioctl_get_wifi_connect_info::find the bss failed by bssid:%02X:XX:XX:%02X:%02X:%02X}",
            connect_info->auc_bssid[MAC_ADDR_0],
            connect_info->auc_bssid[MAC_ADDR_3],
            connect_info->auc_bssid[MAC_ADDR_4],
            connect_info->auc_bssid[MAC_ADDR_5]);

        /* 解锁 */
        oal_spin_unlock(&(bss_mgmt->st_lock));
        return -OAL_EINVAL;
    }
    /* 解锁 */
    oal_spin_unlock(&(bss_mgmt->st_lock));

    if (EOK != memcpy_s(connect_info->auc_ssid, WLAN_SSID_MAX_LEN,
                        scanned_bss_info->st_bss_dscr_info.ac_ssid, WLAN_SSID_MAX_LEN)) {
        oam_error_log0(0, OAM_SF_CFG, "wal_atcmsrv_ioctl_get_wifi_connect_info::memcpy fail!");
        return -OAL_EINVAL;
    }
    return OAL_SUCC;
}

/*
 * 函 数 名  : wal_atcmsrv_ioctl_get_wifi_connect_info
 * 功能描述  : 获取wifi连接信息
 * 1.日    期  : 2018年5月31日
 *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmsrv_ioctl_get_wifi_connect_info(oal_net_device_stru *pst_net_dev,
                                                           wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    mac_vap_stru *pst_mac_vap = NULL;
    struct wal_atcmdsrv_wifi_connect_info *pst_connect_info = &(pst_priv_cmd->pri_data.st_connect_info);

    pst_mac_vap = oal_net_dev_priv(pst_net_dev);
    if (pst_mac_vap == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "{wal_atcmsrv_ioctl_get_wifi_connect_info::vap is null.}");
        return -OAL_EINVAL;
    }

    if (pst_mac_vap->en_vap_mode != WLAN_VAP_MODE_BSS_STA) {
        oam_error_log1(0, OAM_SF_ANY,
                       "{wal_atcmsrv_ioctl_get_wifi_connect_info::invalid vap mode.vap_mode [%d]}",
                       pst_mac_vap->en_vap_mode);
        return -OAL_EINVAL;
    }
    /* 清空数据 */
    memset_s(pst_connect_info, sizeof(struct wal_atcmdsrv_wifi_connect_info),
        0, sizeof(struct wal_atcmdsrv_wifi_connect_info));

    if (pst_mac_vap->en_vap_state == MAC_VAP_STATE_UP) {
        if (wal_get_up_vap_connect_info(pst_mac_vap, pst_connect_info) != OAL_SUCC) {
            return -OAL_EINVAL;
        }
    } else {
        pst_connect_info->en_status = ATCMDSRV_WIFI_DISCONNECT;
    }

    oam_warning_log4(0, OAM_SF_CFG,
                     "wal_atcmsrv_ioctl_get_wifi_connect_info::state %d, rssi %d, BSSID[XX:XX:XX:XX:%02X:%02X]",
                     pst_connect_info->en_status, pst_connect_info->c_rssi,
                     pst_connect_info->auc_bssid[MAC_ADDR_4], pst_connect_info->auc_bssid[MAC_ADDR_5]);

    return OAL_SUCC;
}

/*
 * 函 数 名  : wal_atcmsrv_ioctl_io_test
 * 功能描述  : 唤醒io产线测试接口
 * 1.日    期  : 2017年12月28日
 *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmsrv_ioctl_pcie_sdio_set(oal_net_device_stru *pst_net_dev,
                                                   wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    int32_t ret;
    uint8_t input_1[200] = "sdio";       /* io测试接口1,输入数组大小200字节 */
    uint8_t input_2[200] = "pcie";       /* io测试接口2,输入数组大小200字节 */
    int16_t s_pcie_sdio_set = pst_priv_cmd->pri_data.s_pcie_sdio_set;

    if (s_pcie_sdio_set == 1) {          /* io测试接口1 */
        ret = conn_test_hcc_chann_switch(input_1);
        if (ret != OAL_SUCC) {
            return -OAL_EINVAL;
        }
    } else if (s_pcie_sdio_set == 2) {   /* io测试接口2 */
        ret = conn_test_hcc_chann_switch(input_2);
        if (ret != OAL_SUCC) {
            return -OAL_EINVAL;
        }
    } else {
        return -OAL_EINVAL;
    }
    return OAL_SUCC;
}
#ifdef HISI_CONN_NVE_SUPPORT
uint32_t hwifi_config_set_cali_chan(uint32_t);
uint32_t hwifi_config_get_cali_chan(uint32_t, uint32_t);
/*
 * 函 数 名  : wal_atcmdsrv_ioctl_dpd_cali
 * 功能描述  : 私有接口函数
 * 1.日    期  : 2021年06月30日
 *   作    者  : wifi
 *   修改内容  : 新增函数
 */
OAL_STATIC int32_t wal_atcmdsrv_ioctl_dpd_cali(oal_net_device_stru *pst_net_dev,
    wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    wal_msg_write_stru st_write_msg;
    int32_t l_ret;
    int32_t i_leftime;
    mac_vap_stru *pst_mac_vap = oal_net_dev_priv(pst_net_dev);
    hmac_vap_stru *pst_hmac_vap = NULL;

    /* 检查是否设置校准通道 */
    if (pst_priv_cmd->pri_data.dpd_cali_info.cali_step == 0x3 ||
        pst_priv_cmd->pri_data.dpd_cali_info.cali_step == 0x2) {
        pst_priv_cmd->pri_data.dpd_cali_info.cali_chn = conn_nve_get_data_status(CONN_STATUS_DPD);
        return OAL_SUCC;
    } else if (pst_priv_cmd->pri_data.dpd_cali_info.cali_step == 0) {
        hwifi_config_set_cali_chan(pst_priv_cmd->pri_data.dpd_cali_info.cali_chn);
        return OAL_SUCC;
    } else if (pst_priv_cmd->pri_data.dpd_cali_info.cali_step == 0x4) {
        conn_nve_clear_by_cmd(pst_priv_cmd->pri_data.dpd_cali_info.cali_chn);
        return OAL_SUCC;
    }
    if (pst_mac_vap == NULL) {
        return -OAL_EINVAL;
    }

    pst_hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(pst_mac_vap->uc_vap_id);
    if (pst_hmac_vap == NULL) {
        return -OAL_EINVAL;
    }
    /***************************************************************************
                              抛事件到wal层处理
    ***************************************************************************/
    pst_hmac_vap->st_atcmdsrv_get_status.uc_get_dbb_completed_flag = OAL_FALSE;
    wal_write_msg_hdr_init(&st_write_msg, WLAN_CFGID_SAVE_DPD_DATA, 0);

    l_ret = wal_send_cfg_event(pst_net_dev, WAL_MSG_TYPE_WRITE, WAL_MSG_WRITE_MSG_HDR_LENGTH,
                               (uint8_t *)&st_write_msg, OAL_FALSE, NULL);
    if (oal_unlikely(l_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_ANY, "{wal_send_cfg_event return err_code [%d]!}", l_ret);
        return l_ret;
    }
    /* 阻塞等待dmac上报 */
    i_leftime = oal_wait_event_interruptible_timeout_m(pst_hmac_vap->query_wait_q,
        (uint32_t)(pst_hmac_vap->st_atcmdsrv_get_status.uc_get_dbb_completed_flag == OAL_TRUE), WAL_ATCMDSRB_DPD_TIME);
    if (oal_unlikely(i_leftime <= 0)) {
        /* 超时还没有上报扫描结束 */
        oam_warning_log1(0, OAM_SF_ANY, "{wal_atcmdsrv_ioctl_dpd_cali::timeout, timeleft[%d]!}", i_leftime);
        return -OAL_EINVAL;
    } else {
        /* 正常结束  */
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_ANY, "{wal_atcmdsrv_ioctl_dpd_cali::wait for %ld ms!}",
            WAL_ATCMDSRB_DPD_TIME - i_leftime);
        if (pst_hmac_vap->st_atcmdsrv_get_status.dbb_num != 0) {
            return -OAL_EINVAL;
        }
        conn_nve_set_data_status(CONN_STATUS_DPD, pst_priv_cmd->pri_data.dpd_cali_info.cali_chn);
        return OAL_SUCC;
    }
}
/*
 * 函 数 名  : wal_atcmdsrv_ioctl_pow_cali
 * 功能描述  : 私有接口函数
 * 1.日    期  : 2021年06月30日
 *   作    者  : wifi
 *   修改内容  : 新增函数
 */
OAL_STATIC int32_t wal_atcmdsrv_ioctl_pow_cali(oal_net_device_stru *pst_net_dev,
    wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    mac_vap_stru *pst_mac_vap = NULL;

    pst_mac_vap = oal_net_dev_priv(pst_net_dev);
    if (pst_mac_vap == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "{wal_atcmdsrv_ioctl_pow_cali::OAL_NET_DEV_PRIV, return null!}");
        return -OAL_EINVAL;
    }

    /* 保存功率校准数据到NV */
    return conn_nve_write_powcal_data_pro((nv_pow_user_info_stru*)(&pst_priv_cmd->pri_data.pow_cal_info));
}

/*
 * 函 数 名  : wal_atcmdsrv_ioctl_pow_cali
 * 功能描述  : 私有接口函数
 * 1.日    期  : 2021年06月30日
 *   作    者  : wifi
 *   修改内容  : 新增函数
 */
OAL_STATIC int32_t wal_atcmdsrv_ioctl_pow_cali_gf61(oal_net_device_stru *pst_net_dev,
    wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    mac_vap_stru *pst_mac_vap = NULL;

    pst_mac_vap = oal_net_dev_priv(pst_net_dev);
    if (pst_mac_vap == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "{wal_atcmdsrv_ioctl_pow_cali::OAL_NET_DEV_PRIV, return null!}");
        return -OAL_EINVAL;
    }

    /* 保存功率校准数据到全局变量 */
    return conn_nve_write_powcal_data_pro_gf61((nv_pow_user_info_stru*)(&pst_priv_cmd->pri_data.pow_cal_info));
}

/*
 * 函 数 名  : wal_atcmdsrv_ioctl_get_pwr_diff
 * 功能描述  : 私有接口函数
 * 1.日    期  : 2023年03月
  *   修改内容  : 新增函数
 */
OAL_STATIC int32_t wal_atcmdsrv_ioctl_get_pwr_diff(oal_net_device_stru *pst_net_dev,
    wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    int32_t l_ret, leftime;
    hmac_vap_stru *hmac_vap;
    mac_vap_stru *pst_mac_vap = NULL;
    wal_msg_write_stru st_write_msg;

    pst_mac_vap = oal_net_dev_priv(pst_net_dev);
    if (pst_mac_vap == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "{wal_atcmdsrv_ioctl_get_pwr_diff::OAL_NET_DEV_PRIV, return null!}");
        return -OAL_EINVAL;
    }
    hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(pst_mac_vap->uc_vap_id);
    if (hmac_vap == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "wal_atcmdsrv_efuse_regs_read:mac_res_get_hmac_vap failed");
        return -OAL_EINVAL;
    }
    hmac_vap->uc_write_pow_flag = OAL_FALSE;

    /* 校准完毕将校准数据下发到device */
    wal_write_msg_hdr_init(&st_write_msg, WLAN_CFGID_TX_POW_H2D, sizeof(nv_pow_stru_gf61));

    if (EOK != memcpy_s(st_write_msg.auc_value, sizeof(nv_pow_stru_gf61),
                        &g_pow_cail, sizeof(nv_pow_stru_gf61))) {
        oam_error_log0(0, OAM_SF_CFG, "wal_atcmdsrv_ioctl_get_pwr_diff::memcpy fail!");
        return OAL_FAIL;
    }
    l_ret = wal_send_cfg_event(pst_net_dev, WAL_MSG_TYPE_WRITE,
                               WAL_MSG_WRITE_MSG_HDR_LENGTH + sizeof(nv_pow_stru_gf61),
                               (uint8_t *)&st_write_msg, OAL_FALSE, NULL);
    if (oal_unlikely(l_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_ANY, "{wal_atcmdsrv_ioctl_get_pwr_diff::return err code %d!}\r\n", l_ret);
        return l_ret;
    }
    /* 阻塞等待dmac上报 */
    leftime = oal_wait_event_interruptible_timeout_m(hmac_vap->query_wait_q,
                                                     (int32_t)(hmac_vap->uc_write_pow_flag ==
                                                     OAL_TRUE), WAL_ATCMDSRB_WRITEF_TIME);
    if (leftime == 0) {
        /* 超时还没有上报扫描结束 */
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_ANY,
                         "{wal_atcmdsrv_ioctl_set_pwr_diff_to_nv::efuse_regs wait for %ld ms!}",
                         ((WAL_ATCMDSRB_WRITEF_TIME * 1000) / OAL_TIME_HZ)); /* 1s等于1000ms */
        return -OAL_EINVAL;
    } else if (leftime < 0) {
        /* 定时器内部错误 */
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_ANY,
                         "{wal_atcmdsrv_ioctl_set_pwr_diff_to_nv::efuse_regs wait for %ld ms!}",
                         ((WAL_ATCMDSRB_WRITEF_TIME * 1000) / OAL_TIME_HZ)); /* 1s等于1000ms */
        return -OAL_EINVAL;
    }
    return g_write_pow_flag;
}
/*
 * 函 数 名  : wal_atcmdsrv_ioctl_get_xo_pwr_diff
 * 功能描述  : 私有接口函数
 * 1.日    期  : 2023年03月
  *   修改内容  : 新增函数
 */
OAL_STATIC int32_t wal_atcmdsrv_ioctl_get_xo_pwr_diff(oal_net_device_stru *pst_net_dev,
    wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    int32_t l_ret, leftime;
    hmac_vap_stru *hmac_vap;
    mac_vap_stru *pst_mac_vap = NULL;
    wal_msg_write_stru st_write_msg;

    pst_mac_vap = oal_net_dev_priv(pst_net_dev);
    if (pst_mac_vap == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "{wal_atcmdsrv_ioctl_get_xo_pwr_diff::OAL_NET_DEV_PRIV, return null!}");
        return -OAL_EINVAL;
    }
    hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(pst_mac_vap->uc_vap_id);
    if (hmac_vap == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "wal_atcmdsrv_efuse_regs_read:mac_res_get_hmac_vap failed");
        return -OAL_EINVAL;
    }
    hmac_vap->uc_write_xo_flag = OAL_FALSE;

    /* 下发命令将校准数据写入flash */
    wal_write_msg_hdr_init(&st_write_msg, WLAN_CFGID_XO_DIFF_H2D, 0);

    l_ret = wal_send_cfg_event(pst_net_dev, WAL_MSG_TYPE_WRITE,
                               WAL_MSG_WRITE_MSG_HDR_LENGTH,
                               (uint8_t *)&st_write_msg, OAL_FALSE, NULL);
    if (oal_unlikely(l_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_ANY, "{wal_atcmdsrv_ioctl_get_xo_pwr_diff::return err code %d!}\r\n", l_ret);
        return l_ret;
    }
    /* 阻塞等待dmac上报 */
    leftime = oal_wait_event_interruptible_timeout_m(hmac_vap->query_wait_q,
                                                     (int32_t)(hmac_vap->uc_write_xo_flag ==
                                                     OAL_TRUE), WAL_ATCMDSRB_WRITEF_TIME);
    if (leftime == 0) {
        /* 超时还没有上报扫描结束 */
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_ANY,
                         "{wal_atcmdsrv_ioctl_set_pwr_diff_to_nv::efuse_regs wait for %ld ms!}",
                         ((WAL_ATCMDSRB_WRITEF_TIME * 1000) / OAL_TIME_HZ)); /* 1s等于1000ms */
        return -OAL_EINVAL;
    } else if (leftime < 0) {
        /* 定时器内部错误 */
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_ANY,
                         "{wal_atcmdsrv_ioctl_set_pwr_diff_to_nv::efuse_regs wait for %ld ms!}",
                         ((WAL_ATCMDSRB_WRITEF_TIME * 1000) / OAL_TIME_HZ)); /* 1s等于1000ms */
        return -OAL_EINVAL;
    }
    return g_write_xo_flag;
}

/*
 * 函 数 名  : wal_atcmdsrv_ioctl_set_pwr_diff_to_nv
 * 功能描述  : 私有接口函数
 * 1.日    期  : 2023年03月
  *   修改内容  : 新增函数
 */
OAL_STATIC int32_t wal_atcmdsrv_ioctl_set_pwr_diff_to_nv(oal_net_device_stru *pst_net_dev,
    wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    int32_t l_ret;
    int32_t leftime;
    mac_vap_stru *pst_mac_vap = NULL;
    hmac_vap_stru *hmac_vap;
    wal_msg_write_stru st_write_msg;

    pst_mac_vap = oal_net_dev_priv(pst_net_dev);
    if (pst_mac_vap == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "{wal_atcmdsrv_ioctl_set_pwr_diff_to_nv::OAL_NET_DEV_PRIV, return null!}");
        return -OAL_EINVAL;
    }

    hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(pst_mac_vap->uc_vap_id);
    if (hmac_vap == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "wal_atcmdsrv_efuse_regs_read:mac_res_get_hmac_vap failed");
        return -OAL_EINVAL;
    }

    hmac_vap->uc_efuse_cali_flag = OAL_FALSE;

    /***************************************************************************
                              抛事件到wal层处理
    ***************************************************************************/

    wal_write_msg_hdr_init(&st_write_msg, WLAN_CFGID_GET_TX_POW, sizeof(nv_pow_stru_gf61));

    l_ret = wal_send_cfg_event(pst_net_dev, WAL_MSG_TYPE_WRITE,
                               WAL_MSG_WRITE_MSG_HDR_LENGTH,
                               (uint8_t *)&st_write_msg, OAL_FALSE, NULL);
    if (oal_unlikely(l_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_ANY, "{wal_atcmdsrv_ioctl_get_pwr_diff::return err code %d!}\r\n", l_ret);
        return l_ret;
    }

    /* 阻塞等待dmac上报 */
    leftime = oal_wait_event_interruptible_timeout_m(hmac_vap->query_wait_q,
                                                     (int32_t)(hmac_vap->uc_efuse_cali_flag ==
                                                     OAL_TRUE), WAL_ATCMDSRB_DBB_NUM_TIME);
    if (leftime == 0) {
        /* 超时还没有上报扫描结束 */
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_ANY,
                         "{wal_atcmdsrv_ioctl_set_pwr_diff_to_nv::efuse_regs wait for %ld ms!}",
                         ((WAL_ATCMDSRB_DBB_NUM_TIME * 1000) / OAL_TIME_HZ)); /* 1s等于1000ms */
        return -OAL_EINVAL;
    } else if (leftime < 0) {
        /* 定时器内部错误 */
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_ANY,
                         "{wal_atcmdsrv_ioctl_set_pwr_diff_to_nv::efuse_regs wait for %ld ms!}",
                         ((WAL_ATCMDSRB_DBB_NUM_TIME * 1000) / OAL_TIME_HZ)); /* 1s等于1000ms */
        return -OAL_EINVAL;
    } else {
        /* 将ram空间中的校准数据写入nv空间 */
        return write_cali_data_to_nv((uint8_t *)&g_pow_cail, sizeof(nv_pow_stru_gf61));
    }
}
/*
 * 函 数 名  : wal_atcmdsrv_ioctl_set_xo_pwr_diff_to_nv
 * 功能描述  : 私有接口函数
 * 1.日    期  : 2023年03月
  *   修改内容  : 新增函数
 */
OAL_STATIC int32_t wal_atcmdsrv_ioctl_set_xo_pwr_diff_to_nv(oal_net_device_stru *pst_net_dev,
    wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    int32_t l_ret;
    int32_t leftime;
    mac_vap_stru *pst_mac_vap = NULL;
    hmac_vap_stru *hmac_vap;
    wal_msg_write_stru st_write_msg;

    pst_mac_vap = oal_net_dev_priv(pst_net_dev);
    if (pst_mac_vap == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "{wal_atcmdsrv_ioctl_set_xo_pwr_diff_to_nv::OAL_NET_DEV_PRIV, return null!}");
        return -OAL_EINVAL;
    }

    hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(pst_mac_vap->uc_vap_id);
    if (hmac_vap == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "wal_atcmdsrv_ioctl_set_xo_pwr_diff_to_nv:mac_res_get_hmac_vap failed");
        return -OAL_EINVAL;
    }

    hmac_vap->uc_efuse_cali_flag = OAL_FALSE;

    /***************************************************************************
                              抛事件到wal层处理
    ***************************************************************************/

    wal_write_msg_hdr_init(&st_write_msg, WLAN_CFGID_GET_XO_DIFF, sizeof(int32_t));

    l_ret = wal_send_cfg_event(pst_net_dev, WAL_MSG_TYPE_WRITE,
                               WAL_MSG_WRITE_MSG_HDR_LENGTH,
                               (uint8_t *)&st_write_msg, OAL_FALSE, NULL);
    if (oal_unlikely(l_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_ANY, "{wal_atcmdsrv_ioctl_set_xo_pwr_diff_to_nv::return err code %d!}\r\n", l_ret);
        return l_ret;
    }

    /* 阻塞等待dmac上报 */
    leftime = oal_wait_event_interruptible_timeout_m(hmac_vap->query_wait_q,
                                                     (uint32_t)(hmac_vap->uc_efuse_cali_flag ==
                                                     OAL_TRUE), WAL_ATCMDSRB_DBB_NUM_TIME);
    if (leftime == 0) {
        /* 超时还没有上报扫描结束 */
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_ANY,
                         "{wal_atcmdsrv_ioctl_set_xo_pwr_diff_to_nv::efuse_regs wait for %ld ms!}",
                         ((WAL_ATCMDSRB_DBB_NUM_TIME * 1000) / OAL_TIME_HZ)); /* 1s等于1000ms */
        return -OAL_EINVAL;
    } else if (leftime < 0) {
        /* 定时器内部错误 */
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_ANY,
                         "{wal_atcmdsrv_ioctl_set_xo_pwr_diff_to_nv::efuse_regs wait for %ld ms!}",
                         ((WAL_ATCMDSRB_DBB_NUM_TIME * 1000) / OAL_TIME_HZ)); /* 1s等于1000ms */
        return -OAL_EINVAL;
    } else {
        /* 将全局变量校准数据写入nv空间 */
        return write_cali_data_to_nv((uint8_t *)&g_xo_pwr_diff, sizeof(g_xo_pwr_diff));
        }
}

#endif

/*
 * 函 数 名  : wal_atcmsrv_ioctl_get_pdet_val
 * 功能描述  : 老化查询pdet值
 * 1.日    期  : 2023年03月03日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC int32_t wal_atcmsrv_ioctl_get_pdet_val(oal_net_device_stru *pst_net_dev,
    wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    int32_t l_ret;
    wal_msg_write_stru st_write_msg;
    mac_vap_stru *pst_mac_vap = NULL;
    hmac_vap_stru *pst_hmac_vap = NULL;
    int32_t i_leftime;
    int32_t *pdet_val = &(pst_priv_cmd->pri_data.l_pow);

    pst_mac_vap = oal_net_dev_priv(pst_net_dev);
    if (pst_mac_vap == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "{wal_atcmsrv_ioctl_get_pdet_val::OAL_NET_DEV_PRIV, return null!}");
        return -OAL_EINVAL;
    }

    pst_hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(pst_mac_vap->uc_vap_id);
    if (pst_hmac_vap == NULL) {
        oam_error_log0(pst_mac_vap->uc_vap_id, OAM_SF_ANY,
                       "{wal_atcmsrv_ioctl_get_pdet_val::mac_res_get_hmac_vap failed!}");
        return -OAL_EINVAL;
    }

    /***************************************************************************
                                抛事件到wal层处理
    ***************************************************************************/
    pst_hmac_vap->st_atcmdsrv_get_status.uc_get_dbb_completed_flag = OAL_FALSE;
    wal_write_msg_hdr_init(&st_write_msg, WLAN_CFGID_TX_PDET_VAL, sizeof(int32_t));

    l_ret = wal_send_cfg_event(pst_net_dev, WAL_MSG_TYPE_WRITE,
        WAL_MSG_WRITE_MSG_HDR_LENGTH + sizeof(int32_t), (uint8_t *)&st_write_msg, OAL_FALSE, NULL);
    if (oal_unlikely(l_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_ANY, "{wal_atcmsrv_ioctl_get_pdet_val::return err code %d!}\r\n", l_ret);
        return l_ret;
    }

    /* 阻塞等待dmac上报 */
    i_leftime = oal_wait_event_interruptible_timeout_m(pst_hmac_vap->query_wait_q,
        (uint32_t)(pst_hmac_vap->st_atcmdsrv_get_status.uc_get_dbb_completed_flag == OAL_TRUE),
        WAL_ATCMDSRB_GET_RX_PCKT);
    if (i_leftime == 0) {
        /* 超时还没有上报扫描结束 */
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_ANY,
                         "{wal_atcmsrv_ioctl_get_pdet_val:: wait for %ld ms timeout!}",
                         ((WAL_ATCMDSRB_DBB_NUM_TIME * HMAC_S_TO_MS) / OAL_TIME_HZ));
        return -OAL_EINVAL;
    } else if (i_leftime < 0) {
        /* 定时器内部错误 */
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_ANY,
                         "{wal_atcmsrv_ioctl_get_pdet_val:: wait for %ld ms error!}",
                         ((WAL_ATCMDSRB_DBB_NUM_TIME * HMAC_S_TO_MS) / OAL_TIME_HZ));
        return -OAL_EINVAL;
    } else {
        /* 正常结束  */
        *pdet_val = pst_hmac_vap->st_atcmdsrv_get_status.dbb_num;
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_ANY, "{wal_atcmsrv_ioctl_get_pdet_val::get pdet [%d]!}",
                         *pdet_val);
        return OAL_SUCC;
    }
}

OAL_STATIC int32_t wal_atcmsrv_ioctl_get_tsensor_val(oal_net_device_stru *pst_net_dev,
                                                     wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    int32_t l_ret;
    wal_msg_write_stru st_write_msg;
    mac_vap_stru *pst_mac_vap = NULL;
    hmac_vap_stru *pst_hmac_vap = NULL;
    int32_t *pc_tsensor_val = &(pst_priv_cmd->pri_data.tsensor_val);
    int32_t leftime;

    pst_mac_vap = oal_net_dev_priv(pst_net_dev);
    if (pst_mac_vap == NULL) {
        oam_error_log0(0, OAM_SF_EQUIP_TEST,
                       "{wal_atcmsrv_ioctl_get_tsensor_val::OAL_NET_DEV_PRIV, return null!}");
        return -OAL_EINVAL;
    }

    pst_hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(pst_mac_vap->uc_vap_id);
    if (pst_hmac_vap == NULL) {
        oam_error_log0(pst_mac_vap->uc_vap_id, OAM_SF_EQUIP_TEST,
                       "{wal_atcmsrv_ioctl_get_tsensor_val::mac_res_get_hmac_vap failed!}");
        return -OAL_EINVAL;
    }

    g_us_tsensor_val = 0;
    pst_hmac_vap->st_atcmdsrv_get_status.uc_report_tsensor_val_flag = OAL_FALSE;
    /***************************************************************************
                                抛事件到wal层处理
    ***************************************************************************/
    /* 填写消息 */
    wal_write_msg_hdr_init(&st_write_msg, WLAN_CFGID_GET_TEMPERATURE, 0);
    /* 发送消息 */
    l_ret = wal_send_cfg_event(pst_net_dev, WAL_MSG_TYPE_WRITE, WAL_MSG_WRITE_MSG_HDR_LENGTH,
                               (uint8_t *)&st_write_msg, OAL_FALSE, NULL);
    if (oal_unlikely(l_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_EQUIP_TEST,
                         "{wal_atcmsrv_ioctl_get_tsensor_val:: return err_code [%d]!}", l_ret);
        return l_ret;
    }

    /* 阻塞等待dmac上报 */
    leftime = oal_wait_event_interruptible_timeout_m(pst_hmac_vap->query_wait_q,
        (uint32_t)(pst_hmac_vap->st_atcmdsrv_get_status.uc_report_tsensor_val_flag == OAL_TRUE),
        WAL_ATCMDSRB_NORM_TIME);
    if (leftime == 0) {
        /* 超时还没有上报扫描结束 */
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_EQUIP_TEST,
                         "{wal_atcmsrv_ioctl_get_tsensor_val::wait for %ld ms timeout!}",
                         ((WAL_ATCMDSRB_NORM_TIME * HMAC_S_TO_MS) / OAL_TIME_HZ));
        return -OAL_EINVAL;
    } else if (leftime < 0) {
        /* 定时器内部错误 */
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_EQUIP_TEST,
                         "{wal_atcmsrv_ioctl_get_tsensor_val::wait for %ld ms error!}",
                         ((WAL_ATCMDSRB_NORM_TIME * HMAC_S_TO_MS) / OAL_TIME_HZ));
        return -OAL_EINVAL;
    } else {
        /* 正常结束，上报芯片Tsensor结温  */
        *pc_tsensor_val = g_us_tsensor_val;
        return OAL_SUCC;
    }
}

OAL_STATIC int32_t wal_atcmsrv_ioctl_get_config_word(oal_net_device_stru *pst_net_dev,
                                                     wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    int32_t l_ret;
    wal_msg_write_stru st_write_msg;
    mac_vap_stru *pst_mac_vap = NULL;
    hmac_vap_stru *pst_hmac_vap = NULL;
    uint32_t *pc_config_word = &(pst_priv_cmd->pri_data.config_word);
    int32_t leftime;

    pst_mac_vap = oal_net_dev_priv(pst_net_dev);
    if (pst_mac_vap == NULL) {
        oam_error_log0(0, OAM_SF_EQUIP_TEST,
                       "{wal_atcmsrv_ioctl_get_config_word::OAL_NET_DEV_PRIV, return null!}");
        return -OAL_EINVAL;
    }

    pst_hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(pst_mac_vap->uc_vap_id);
    if (pst_hmac_vap == NULL) {
        oam_error_log0(pst_mac_vap->uc_vap_id, OAM_SF_EQUIP_TEST,
                       "{wal_atcmsrv_ioctl_get_config_word::mac_res_get_hmac_vap failed!}");
        return -OAL_EINVAL;
    }

    g_us_config_word = 0;
    /***************************************************************************
                                抛事件到wal层处理
    ***************************************************************************/
    pst_hmac_vap->st_atcmdsrv_get_status.uc_report_config_word_flag = OAL_FALSE;
    /* 填写消息 */
    wal_write_msg_hdr_init(&st_write_msg, WLAN_CFGID_GET_HW_WORD, 0);
    /* 发送消息 */
    l_ret = wal_send_cfg_event(pst_net_dev, WAL_MSG_TYPE_WRITE, WAL_MSG_WRITE_MSG_HDR_LENGTH,
                               (uint8_t *)&st_write_msg, OAL_FALSE, NULL);
    if (oal_unlikely(l_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_EQUIP_TEST,
                         "{wal_atcmsrv_ioctl_get_config_word:: return err_code [%d]!}", l_ret);
        return l_ret;
    }

    /* 阻塞等待dmac上报 */
    leftime = oal_wait_event_interruptible_timeout_m(pst_hmac_vap->query_wait_q,
        (uint32_t)(pst_hmac_vap->st_atcmdsrv_get_status.uc_report_config_word_flag == OAL_TRUE),
        WAL_ATCMDSRB_NORM_TIME);
    if (leftime == 0) {
        /* 超时还没有上报扫描结束 */
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_EQUIP_TEST,
                         "{wal_atcmsrv_ioctl_get_config_word::wait for %ld ms timeout!}",
                         ((WAL_ATCMDSRB_NORM_TIME * HMAC_S_TO_MS) / OAL_TIME_HZ));
        return -OAL_EINVAL;
    } else if (leftime < 0) {
        /* 定时器内部错误 */
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_EQUIP_TEST,
                         "{wal_atcmsrv_ioctl_get_config_word::wait for %ld ms error!}",
                         ((WAL_ATCMDSRB_NORM_TIME * HMAC_S_TO_MS) / OAL_TIME_HZ));
        return -OAL_EINVAL;
    } else {
        /* 正常结束，上报上电配置字 */
        *pc_config_word = g_us_config_word;
        return OAL_SUCC;
    }
}

OAL_STATIC int32_t wal_atcmsrv_ioctl_get_board_sn(oal_net_device_stru *pst_net_dev,
                                                  wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    int32_t l_ret;
    wal_msg_write_stru st_write_msg;
    mac_vap_stru *pst_mac_vap = NULL;
    hmac_vap_stru *pst_hmac_vap = NULL;
    uint8_t *pc_board_sn = pst_priv_cmd->pri_data.bsn;
    int32_t leftime;
    uint8_t i;

    pst_mac_vap = oal_net_dev_priv(pst_net_dev);
    if (pst_mac_vap == NULL) {
        oam_error_log0(0, OAM_SF_EQUIP_TEST,
                       "{wal_atcmsrv_ioctl_get_board_sn::OAL_NET_DEV_PRIV, return null!}");
        return -OAL_EINVAL;
    }

    pst_hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(pst_mac_vap->uc_vap_id);
    if (pst_hmac_vap == NULL) {
        oam_error_log0(pst_mac_vap->uc_vap_id, OAM_SF_EQUIP_TEST,
                       "{wal_atcmsrv_ioctl_get_board_sn::mac_res_get_hmac_vap failed!}");
        return -OAL_EINVAL;
    }

    pst_hmac_vap->st_atcmdsrv_get_status.uc_report_board_sn_flag = OAL_FALSE;
    /***************************************************************************
                                抛事件到wal层处理
    ***************************************************************************/
    /* 填写消息 */
    wal_write_msg_hdr_init(&st_write_msg, WLAN_CFGID_GET_BOARD_SN, 0);
    /* 发送消息 */
    l_ret = wal_send_cfg_event(pst_net_dev, WAL_MSG_TYPE_WRITE, WAL_MSG_WRITE_MSG_HDR_LENGTH,
                               (uint8_t *)&st_write_msg, OAL_FALSE, NULL);
    if (oal_unlikely(l_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_EQUIP_TEST,
                         "{wal_atcmsrv_ioctl_get_board_sn:: return err_code [%d]!}", l_ret);
        return l_ret;
    }

    /* 阻塞等待dmac上报 */
    leftime = oal_wait_event_interruptible_timeout_m(pst_hmac_vap->query_wait_q,
        (uint32_t)(pst_hmac_vap->st_atcmdsrv_get_status.uc_report_board_sn_flag == OAL_TRUE),
        WAL_ATCMDSRB_NORM_TIME);
    if (leftime == 0) {
        /* 超时还没有上报扫描结束 */
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_EQUIP_TEST,
                         "{wal_atcmsrv_ioctl_get_board_sn::wait for %ld ms timeout!}",
                         ((WAL_ATCMDSRB_NORM_TIME * HMAC_S_TO_MS) / OAL_TIME_HZ));
        return -OAL_EINVAL;
    } else if (leftime < 0) {
        /* 定时器内部错误 */
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_EQUIP_TEST,
                         "{wal_atcmsrv_ioctl_get_board_sn::wait for %ld ms error!}",
                         ((WAL_ATCMDSRB_NORM_TIME * HMAC_S_TO_MS) / OAL_TIME_HZ));
        return -OAL_EINVAL;
    } else {
        /* 正常结束，上报bsn */
        for (i = 0; i < WAL_ATCMDSRV_BOARD_SN_LENGTH; i++) {
            pc_board_sn[i] = g_us_bsn[i];
        }

        return OAL_SUCC;
    }
}

OAL_STATIC int32_t wal_atcmsrv_ioctl_set_board_sn(oal_net_device_stru *pst_net_dev,
                                                  wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    wal_msg_write_stru st_write_msg;
    uint8_t *pc_board_sn = pst_priv_cmd->pri_data.bsn;
    int32_t l_ret;
    uint16_t bsn_len = sizeof(uint8_t) * WAL_ATCMDSRV_BOARD_SN_LENGTH;
    uint8_t idx;

    /***************************************************************************
        抛事件到wal层处理
    ***************************************************************************/
    /* 填写消息 */
    wal_write_msg_hdr_init(&st_write_msg, WLAN_CFGID_SET_BOARD_SN, bsn_len);
    for (idx = 0; idx < WAL_ATCMDSRV_BOARD_SN_LENGTH; idx++) {
        st_write_msg.auc_value[idx] = pc_board_sn[idx];
    }

    /* 发送消息 */
    l_ret = wal_send_cfg_event(pst_net_dev, WAL_MSG_TYPE_WRITE,
                               WAL_MSG_WRITE_MSG_HDR_LENGTH + bsn_len,
                               (uint8_t *)&st_write_msg, OAL_FALSE, NULL);
    if (oal_unlikely(l_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_EQUIP_TEST,
                         "{wal_atcmsrv_ioctl_set_board_sn::return err code %d!}", l_ret);
        return l_ret;
    }

    return OAL_SUCC;
}

OAL_STATIC int32_t wal_atcmsrv_ioctl_flash_test(oal_net_device_stru *pst_net_dev,
                                                wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    int32_t l_ret;
    wal_msg_write_stru st_write_msg;
    mac_vap_stru *pst_mac_vap = NULL;
    hmac_vap_stru *pst_hmac_vap = NULL;
    int8_t *pc_flash_check_result = &(pst_priv_cmd->pri_data.flash_check_result);
    int32_t leftime;

    pst_mac_vap = oal_net_dev_priv(pst_net_dev);
    if (pst_mac_vap == NULL) {
        oam_error_log0(0, OAM_SF_EQUIP_TEST,
                       "{wal_atcmsrv_ioctl_flash_test::OAL_NET_DEV_PRIV, return null!}");
        return -OAL_EINVAL;
    }

    pst_hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(pst_mac_vap->uc_vap_id);
    if (pst_hmac_vap == NULL) {
        oam_error_log0(pst_mac_vap->uc_vap_id, OAM_SF_EQUIP_TEST,
                       "{wal_atcmsrv_ioctl_flash_test::mac_res_get_hmac_vap failed!}");
        return -OAL_EINVAL;
    }

    g_us_flash_check_result = 0;
    pst_hmac_vap->st_atcmdsrv_get_status.uc_check_flash_flag = OAL_FALSE;
    /***************************************************************************
                                抛事件到wal层处理
    ***************************************************************************/
    /* 填写消息 */
    wal_write_msg_hdr_init(&st_write_msg, WLAN_CFGID_FLASH_TEST, 0);
    /* 发送消息 */
    l_ret = wal_send_cfg_event(pst_net_dev, WAL_MSG_TYPE_WRITE, WAL_MSG_WRITE_MSG_HDR_LENGTH,
                               (uint8_t *)&st_write_msg, OAL_FALSE, NULL);
    if (oal_unlikely(l_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_EQUIP_TEST,
                         "{wal_atcmsrv_ioctl_flash_test:: return err_code [%d]!}", l_ret);
        return l_ret;
    }

    /* 阻塞等待dmac上报 */
    leftime = oal_wait_event_interruptible_timeout_m(pst_hmac_vap->query_wait_q,
        (uint32_t)(pst_hmac_vap->st_atcmdsrv_get_status.uc_check_flash_flag == OAL_TRUE),
        WAL_ATCMDSRB_FLASH_TIME);
    if (leftime == 0) {
        /* 超时还没有上报扫描结束 */
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_EQUIP_TEST,
                         "{wal_atcmsrv_ioctl_flash_test::wait for %ld ms timeout!}",
                         ((WAL_ATCMDSRB_FLASH_TIME * HMAC_S_TO_MS) / OAL_TIME_HZ));
        return -OAL_EINVAL;
    } else if (leftime < 0) {
        /* 定时器内部错误 */
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_EQUIP_TEST,
                         "{wal_atcmsrv_ioctl_flash_test::wait for %ld ms error!}",
                         ((WAL_ATCMDSRB_FLASH_TIME * HMAC_S_TO_MS) / OAL_TIME_HZ));
        return -OAL_EINVAL;
    } else {
        /* 正常结束  */
        *pc_flash_check_result = g_us_flash_check_result;
        return OAL_SUCC;
    }
}

OAL_STATIC int32_t wal_atcmsrv_ioctl_spmi_test(oal_net_device_stru *pst_net_dev,
                                               wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    int32_t l_ret;
    wal_msg_write_stru st_write_msg;
    mac_vap_stru *pst_mac_vap = NULL;
    hmac_vap_stru *pst_hmac_vap = NULL;
    int32_t leftime;

    pst_mac_vap = oal_net_dev_priv(pst_net_dev);
    if (pst_mac_vap == NULL) {
        oam_error_log0(0, OAM_SF_EQUIP_TEST,
                       "{wal_atcmsrv_ioctl_flash_test::OAL_NET_DEV_PRIV, return null!}");
        return -OAL_EINVAL;
    }

    pst_hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(pst_mac_vap->uc_vap_id);
    if (pst_hmac_vap == NULL) {
        oam_error_log0(pst_mac_vap->uc_vap_id, OAM_SF_EQUIP_TEST,
                       "{wal_atcmsrv_ioctl_flash_test::mac_res_get_hmac_vap failed!}");
        return -OAL_EINVAL;
    }

    g_us_spmi_check_result = 0;
    pst_hmac_vap->st_atcmdsrv_get_status.uc_check_spmi_flag = OAL_FALSE;
    /***************************************************************************
                                抛事件到wal层处理
    ***************************************************************************/
    /* 填写消息 */
    wal_write_msg_hdr_init(&st_write_msg, WLAN_CFGID_SPMI_TEST, 0);
    /* 发送消息 */
    l_ret = wal_send_cfg_event(pst_net_dev, WAL_MSG_TYPE_WRITE, WAL_MSG_WRITE_MSG_HDR_LENGTH,
                               (uint8_t *)&st_write_msg, OAL_FALSE, NULL);
    if (oal_unlikely(l_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_EQUIP_TEST,
                         "{wal_atcmsrv_ioctl_flash_test:: return err_code [%d]!}", l_ret);
        return l_ret;
    }

    /* 阻塞等待dmac上报 */
    leftime = oal_wait_event_interruptible_timeout_m(pst_hmac_vap->query_wait_q,
        (uint32_t)(pst_hmac_vap->st_atcmdsrv_get_status.uc_check_spmi_flag == OAL_TRUE),
        WAL_ATCMDSRB_SSI_TIME);
    if (leftime == 0) {
        /* 超时还没有上报扫描结束 */
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_EQUIP_TEST,
                         "{wal_atcmsrv_ioctl_flash_test::wait for %ld ms timeout!}",
                         ((WAL_ATCMDSRB_SSI_TIME * HMAC_S_TO_MS) / OAL_TIME_HZ));
        return -OAL_EINVAL;
    } else if (leftime < 0) {
        /* 定时器内部错误 */
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_EQUIP_TEST,
                         "{wal_atcmsrv_ioctl_flash_test::wait for %ld ms error!}",
                         ((WAL_ATCMDSRB_SSI_TIME * HMAC_S_TO_MS) / OAL_TIME_HZ));
        return -OAL_EINVAL;
    } else {
        return g_us_spmi_check_result;
    }
}

OAL_STATIC int32_t wal_atcmsrv_ioctl_ssi_test(oal_net_device_stru *pst_net_dev,
                                              wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    int32_t l_ret, leftime;
    mac_vap_stru *pst_mac_vap = NULL;
    hmac_vap_stru *pst_hmac_vap = NULL;
    wal_msg_write_stru st_write_msg;
    wal_atcmdsrv_ssi_stru st_ssi_stru;

    pst_mac_vap = oal_net_dev_priv(pst_net_dev);
    if (pst_mac_vap == NULL) {
        oam_error_log0(0, OAM_SF_ANY, "{wal_atcmsrv_ioctl_spmi_test::OAL_NET_DEV_PRIV, return null!}");
        return -OAL_EINVAL;
    }

    pst_hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(pst_mac_vap->uc_vap_id);
    if (pst_hmac_vap == NULL) {
        oam_error_log0(pst_mac_vap->uc_vap_id, OAM_SF_EQUIP_TEST,
                       "{wal_atcmsrv_ioctl_flash_test::mac_res_get_hmac_vap failed!}");
        return -OAL_EINVAL;
    }

    st_ssi_stru.ssi_addr = pst_priv_cmd->pri_data.st_ssi_reg_info.ssi_addr;
    st_ssi_stru.ssi_value = pst_priv_cmd->pri_data.st_ssi_reg_info.ssi_addr_value;

    g_us_ssi_check_result = -OAL_EINVAL;
    pst_hmac_vap->st_atcmdsrv_get_status.uc_check_ssi_flag = OAL_FALSE;
    /***************************************************************************
                                抛事件到wal层处理
    ***************************************************************************/
    if (EOK != memcpy_s(st_write_msg.auc_value, sizeof(wal_atcmdsrv_ssi_stru),
                        &st_ssi_stru, sizeof(wal_atcmdsrv_ssi_stru))) {
        oam_error_log0(0, OAM_SF_CFG, "wal_atcmsrv_ioctl_ssi_test::memcpy fail!");
        return -OAL_EINVAL;
    }

    wal_write_msg_hdr_init(&st_write_msg, WLAN_CFGID_SSI_TEST, sizeof(wal_atcmdsrv_ssi_stru));
    l_ret = wal_send_cfg_event(pst_net_dev, WAL_MSG_TYPE_WRITE,
                               WAL_MSG_WRITE_MSG_HDR_LENGTH + sizeof(wal_atcmdsrv_ssi_stru),
                               (uint8_t *)&st_write_msg, OAL_FALSE, NULL);
    if (oal_unlikely(l_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_ANY, "{wal_atcmsrv_ioctl_ssi_test::return err code %d!}\r\n", l_ret);
        return l_ret;
    }
    /* 阻塞等待dmac上报 */
    leftime = oal_wait_event_interruptible_timeout_m(pst_hmac_vap->query_wait_q,
        (uint32_t)(pst_hmac_vap->st_atcmdsrv_get_status.uc_check_ssi_flag == OAL_TRUE),
        WAL_ATCMDSRB_SSI_TIME);
    if (leftime == 0) {
        /* 超时还没有上报扫描结束 */
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_EQUIP_TEST,
                         "{wal_atcmsrv_ioctl_ssi_test::wait for %ld ms timeout!}",
                         ((WAL_ATCMDSRB_SSI_TIME * HMAC_S_TO_MS) / OAL_TIME_HZ));
        return -OAL_EINVAL;
    } else if (leftime < 0) {
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_EQUIP_TEST,
                         "{wal_atcmsrv_ioctl_ssi_test::wait for %ld ms error!}",
                         ((WAL_ATCMDSRB_SSI_TIME * HMAC_S_TO_MS) / OAL_TIME_HZ));
        return -OAL_EINVAL;
    }
    return g_us_ssi_check_result;
}

OAL_STATIC int32_t wal_atcmsrv_ioctl_set_lpmode(oal_net_device_stru *pst_net_dev,
    wal_atcmdsrv_wifi_priv_cmd_stru *pst_priv_cmd)
{
    uint8_t l_lpmode = pst_priv_cmd->pri_data.lp_mode;
    int32_t l_ret = OAL_SUCC;

    oam_warning_log1(0, OAM_SF_ANY, "wal_atcmsrv_ioctl_set_lpmode:lp_mode[%u]", l_lpmode);

    if (l_lpmode == 0) {
        l_ret = wal_hipriv_parse_cmd("wlan0 lp_rx_mode 0");
    } else if (l_lpmode == 0x2) {
        l_ret = wal_hipriv_parse_cmd("wlan0 lp_rx_mode 2");
    }

    if (oal_unlikely(l_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_ANY, "{wal_atcmsrv_ioctl_set_lpmode::return err code %d!}", l_ret);
        return l_ret;
    }

    return OAL_SUCC;
}

OAL_STATIC wal_atcmd_ioctl_set_stru g_ast_wal_atcmd_table[] = {
    { WAL_ATCMDSRV_IOCTL_CMD_WI_FREQ_SET,      wal_atcmsrv_ioctl_set_freq,             0 },
    { WAL_ATCMDSRV_IOCTL_CMD_WI_POWER_SET,     wal_atcmsrv_ioctl_set_txpower,          0 },
    { WAL_ATCMDSRV_IOCTL_CMD_MODE_SET,         wal_atcmsrv_ioctl_set_mode,             0 },
    { WAL_ATCMDSRV_IOCTL_CMD_DATARATE_SET,     wal_atcmsrv_ioctl_set_datarate,         0 },
    { WAL_ATCMDSRV_IOCTL_CMD_BAND_SET,         wal_atcmsrv_ioctl_set_bandwidth,        0 },
#ifdef PLATFORM_DEBUG_ENABLE
    { WAL_ATCMDSRV_IOCTL_CMD_ALWAYS_TX_SET,    wal_atcmsrv_ioctl_set_always_tx,        0 },
#endif
    { WAL_ATCMDSRV_IOCTL_CMD_DBB_GET,          wal_atcmsrv_ioctl_get_dbb_num,          1 },
    { WAL_ATCMDSRV_IOCTL_CMD_HW_STATUS_GET,    wal_atcmsrv_ioctl_get_hw_status,        1 },
#ifdef PLATFORM_DEBUG_ENABLE
    { WAL_ATCMDSRV_IOCTL_CMD_ALWAYS_RX_SET,    wal_atcmsrv_ioctl_set_always_rx,        0 },
#endif
    { WAL_ATCMDSRV_IOCTL_CMD_HW_ADDR_SET,      wal_atcmsrv_ioctl_set_hw_addr,          0 },
    { WAL_ATCMDSRV_IOCTL_CMD_RX_PCKG_GET,      wal_atcmsrv_ioctl_get_rx_pckg,          1 },
    { WAL_ATCMDSRV_IOCTL_CMD_PM_SWITCH,        wal_atcmsrv_ioctl_set_pm_switch,        0 },
    { WAL_ATCMDSRV_IOCTL_CMD_RX_RSSI,          wal_atcmsrv_ioctl_get_rx_rssi,          1 },
    { WAL_ATCMDSRV_IOCTL_CMD_CHIPCHECK_SET,    wal_atcmsrv_ioctl_set_chipcheck,        0 },
    { WAL_ATCMDSRV_IOCTL_CMD_CHIPCHECK_RESULT, wal_atcmsrv_ioctl_get_chipcheck_result, 1 },
    { WAL_ATCMDSRV_IOCTL_CMD_CHIPCHECK_TIME,   wal_atcmsrv_ioctl_get_chipcheck_time,   1 },
    { WAL_ATCMDSRV_IOCTL_CMD_UART_LOOP_SET,    wal_atcmsrv_ioctl_set_uart_loop,        0 },
    { WAL_ATCMDSRV_IOCTL_CMD_SDIO_LOOP_SET,    wal_atcmsrv_ioctl_set_wifi_chan_loop,   0 },
    { WAL_ATCMDSRV_IOCTL_CMD_RD_CALDATA,       NULL,                                   0 },
    { WAL_ATCMDSRV_IOCTL_CMD_SET_CALDATA,      NULL,                                   0 },
#ifdef PLATFORM_DEBUG_ENABLE
    { WAL_ATCMDSRV_IOCTL_CMD_EFUSE_CHECK,      wal_atcmsrv_ioctl_efuse_check,          1 },
#endif
    { WAL_ATCMDSRV_IOCTL_CMD_SET_ANT,          NULL,                                   0 },
#ifdef PLATFORM_DEBUG_ENABLE
    { WAL_ATCMDSRV_IOCTL_CMD_DIEID_INFORM,     wal_atcmsrv_ioctl_dieid_inform,         1 },
#endif
    { WAL_ATCMDSRV_IOCTL_CMD_SET_COUNTRY,      wal_atcmsrv_ioctl_set_country,          0 },
    { WAL_ATCMDSRV_IOCTL_CMD_GET_UPCCODE,      NULL,                                   0 },
    { WAL_ATCMDSRV_IOCTL_CMD_WIPIN_TEST, wal_atcmsrv_ioctl_wipin_test, 1 },
    { WAL_ATCMDSRV_IOCTL_CMD_PMU_CHECK, NULL, 0 },
#ifdef _PRE_WLAN_FEATURE_M2S
    { WAL_ATCMDSRV_IOCTL_CMD_SET_MIMO_CHANNEL, wal_atcmsrv_ioctl_set_mimo_ch, 0 },
#endif
    { WAL_ATCMDSRV_IOCTL_CMD_GET_DP_INIT,        wal_atcmsrv_ioctl_get_dp_init,            1 },
    { WAL_ATCMDSRV_IOCTL_CMD_GET_PDET_PARAM,     wal_atcmsrv_ioctl_get_pd_tran_param,      1 },
    { WAL_ATCMDSRV_IOCTL_CMD_IO_TEST,            wal_atcmsrv_ioctl_io_test,                1 },
    { WAL_ATCMDSRV_IOCTL_CMD_PCIE_TEST,          wal_atcmdsrv_ioctl_pcie_ip_test,          1 },
    { WAL_ATCMDSRV_IOCTL_CMD_PCIE_SDIO_SET,      wal_atcmsrv_ioctl_pcie_sdio_set,          0 },
    { WAL_ATCMDSRV_IOCTL_CMD_DYN_INTERVAL,       wal_atcmdsrv_ioctl_dyn_intervel_set,      0 },
    { WAL_ATCMDSRV_IOCTL_CMD_PT_STE,             wal_atcmdsrv_ioctl_pt_set,                0 },
    { WAL_ATCMDSRV_IOCTL_CMD_TAS_ANT_SET,        wal_atcmdsrv_ioctl_tas_ant_set,           0 },
    { WAL_ATCMDSRV_IOCTL_CMD_SELFCALI_INTERVAL,  wal_atcmdsrv_ioctl_selfcali_intervel_set, 0 },
    { WAL_ATCMDSRV_IOCTL_CMD_SET_BSS_EXPIRE_AGE, wal_atcmsrv_ioctl_set_bss_expire_age,     0 },
    { WAL_ATCMDSRV_IOCTL_CMD_GET_CONN_INFO,      wal_atcmsrv_ioctl_get_wifi_connect_info,  1 },
    { WAL_ATCMDSRV_IOCTL_CMD_SET_RUTEST,         wal_atcmdsrv_ioctl_set_ru_test,           0 },
#ifdef HISI_CONN_NVE_SUPPORT
    { WAL_ATCMDSRV_IOCTL_CMD_DPD_CALI,           wal_atcmdsrv_ioctl_dpd_cali,              1 },
    { WAL_ATCMDSRV_IOCTL_CMD_POW_CALI,           wal_atcmdsrv_ioctl_pow_cali,              0 },
    { WAL_ATCMDSRV_IOCTL_CMD_GETXOCAL,           wal_atcmdsrv_ioctl_get_xo_pwr_diff,       0 },
    { WAL_ATCMDSRV_IOCTL_CMD_SETXOCAL_NV,        wal_atcmdsrv_ioctl_set_xo_pwr_diff_to_nv, 0 },
    { WAL_ATCMDSRV_IOCTL_CMD_SETCAL,             wal_atcmdsrv_ioctl_pow_cali_gf61,         0 },
    { WAL_ATCMDSRV_IOCTL_CMD_GETCAL,             wal_atcmdsrv_ioctl_get_pwr_diff,          0 },
    { WAL_ATCMDSRV_IOCTL_CMD_SETCAL_NV,          wal_atcmdsrv_ioctl_set_pwr_diff_to_nv,    0 },
#endif
    { WAL_ATCMDSRV_IOCTL_CMD_GET_PDET_VAL,       wal_atcmsrv_ioctl_get_pdet_val,           1 },
#ifdef PLATFORM_DEBUG_ENABLE
    { WAL_ATCMDSRV_IOCTL_CMD_GET_TSENSOR_VAL,    wal_atcmsrv_ioctl_get_tsensor_val,        1 },
    { WAL_ATCMDSRV_IOCTL_CMD_GET_CONFIG_WORD,    wal_atcmsrv_ioctl_get_config_word,        1 },
    { WAL_ATCMDSRV_IOCTL_CMD_GET_BOARD_SN,       wal_atcmsrv_ioctl_get_board_sn,           1 },
    { WAL_ATCMDSRV_IOCTL_CMD_SET_BOARD_SN,       wal_atcmsrv_ioctl_set_board_sn,           0 },
    { WAL_ATCMDSRV_IOCTL_CMD_FLASH_TEST,         wal_atcmsrv_ioctl_flash_test,             1 },
    { WAL_ATCMDSRV_IOCTL_CMD_SPMI_TEST,          wal_atcmsrv_ioctl_spmi_test,              1 },
    { WAL_ATCMDSRV_IOCTL_CMD_SSI_TEST,           wal_atcmsrv_ioctl_ssi_test,               1 },
#endif
    { WAL_ATCMDSRV_IOCTL_CMD_SET_LPMODE,         wal_atcmsrv_ioctl_set_lpmode,             0 },
};

/*
 * 功能描述  : 装备测试私有接口函数
 */
int32_t wal_atcmdsrv_wifi_priv_cmd(oal_net_device_stru *pst_net_dev, oal_ifreq_stru *pst_ifr, int32_t cmd)
{
    wal_atcmdsrv_wifi_priv_cmd_stru st_priv_cmd;
    uint32_t arr_size = oal_array_size(g_ast_wal_atcmd_table);
    uint8_t uc_i;
    int32_t l_ret;

    if (oal_any_null_ptr2(pst_ifr->ifr_data, pst_net_dev)) {
        return -OAL_EINVAL;
    }

    /* 将用户态数据拷贝到内核态 */
    if (oal_copy_from_user(&st_priv_cmd, pst_ifr->ifr_data, sizeof(wal_atcmdsrv_wifi_priv_cmd_stru))) {
        return -OAL_EINVAL;
    }

    for (uc_i = 0; uc_i < arr_size; uc_i++) {
        if (g_ast_wal_atcmd_table[uc_i].l_cmd_id == st_priv_cmd.cmd) {
            break;
        }
    }
    if (uc_i >= arr_size) {
        oam_error_log1(0, 0, "wal_atcmdsrv_wifi_priv_cmd::err cmd[%d]", st_priv_cmd.cmd);
        return -OAL_EINVAL;
    }

    if (g_ast_wal_atcmd_table[uc_i].p_func != NULL) {
        l_ret = g_ast_wal_atcmd_table[uc_i].p_func(pst_net_dev, &st_priv_cmd);
        if (g_ast_wal_atcmd_table[uc_i].l_copy_flag) {
            oal_copy_to_user(pst_ifr->ifr_data, &st_priv_cmd, sizeof(wal_atcmdsrv_wifi_priv_cmd_stru));
        }
        return l_ret;
    }

    oam_error_log1(0, 0, "wal_atcmdsrv_wifi_priv_cmd::p_func not register, cmd_idx is %d", uc_i);
    return -OAL_EINVAL;
}
#endif
