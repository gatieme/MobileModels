/**
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 *
 * Description: Update and load independent calibration data
 * Author: @CompanyNameTag
 */

/* 头文件包含 */
#include "plat_cali.h"
#include "plat_debug.h"
#include "bfgx_dev.h"
#include "plat_pm.h"
#include "bfgx_data_parse.h"
#include "pcie_linux.h"
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 35))
#ifndef _PRE_NO_HISI_NVRAM
#define HISI_NVRAM_SUPPORT
#endif
#endif

/* 保存校准数据的buf */
STATIC uint8_t *g_cali_data_buf = NULL; /* wifi校准数据(仅SDIO使用) */
STATIC uint8_t *g_cali_data_buf_dma = NULL; /* wifi校准数据(仅PCIE使用) */
STATIC uint64_t g_cali_data_buf_phy_addr = 0; /* 06 wifi校准数据DMA物理地址 */
uint8_t g_netdev_is_open = OAL_FALSE;
uint32_t g_cali_update_channel_info = 0;

/* add for MP13 bfgx */
STATIC struct completion g_cali_recv_done;
STATIC uint8_t *g_bfgx_cali_data_buf = NULL;

int32_t g_cali_buffer_debug = 0;
oal_debug_module_param(g_cali_buffer_debug, int, S_IRUGO | S_IWUSR);

/* 定义不能超过BFGX_BT_CUST_INI_SIZE/4 (128) 最后使用 { NULL, 0 } 结尾 */
STATIC bfgx_ini_cmd g_bfgx_ini_config_cmd_mp13[BFGX_BT_CUST_INI_SIZE / 4] = {
    { "bt_maxpower",                       0 },
    { "bt_edrpow_offset",                  0 },
    { "bt_blepow_offset",                  0 },
    { "bt_cali_txpwr_pa_ref_num",          0 },
    { "bt_cali_txpwr_pa_ref_band1",        0 },
    { "bt_cali_txpwr_pa_ref_band2",        0 },
    { "bt_cali_txpwr_pa_ref_band3",        0 },
    { "bt_cali_txpwr_pa_ref_band4",        0 },
    { "bt_cali_txpwr_pa_ref_band5",        0 },
    { "bt_cali_txpwr_pa_ref_band6",        0 },
    { "bt_cali_txpwr_pa_ref_band7",        0 },
    { "bt_cali_txpwr_pa_ref_band8",        0 },
    { "bt_cali_txpwr_pa_fre1",             0 },
    { "bt_cali_txpwr_pa_fre2",             0 },
    { "bt_cali_txpwr_pa_fre3",             0 },
    { "bt_cali_txpwr_pa_fre4",             0 },
    { "bt_cali_txpwr_pa_fre5",             0 },
    { "bt_cali_txpwr_pa_fre6",             0 },
    { "bt_cali_txpwr_pa_fre7",             0 },
    { "bt_cali_txpwr_pa_fre8",             0 },
    { "bt_cali_bt_tone_amp_grade",         0 },
    { "bt_rxdc_band",                      0 },
    { "bt_dbb_scaling_saturation",         0 },
    { "bt_productline_upccode_search_max", 0 },
    { "bt_productline_upccode_search_min", 0 },
    { "bt_dynamicsarctrl_bt",              0 },
    { "bt_powoffsbt",                      0 },
    { "bt_elna_2g_bt",                     0 },
    { "bt_rxisobtelnabyp",                 0 },
    { "bt_rxgainbtelna",                   0 },
    { "bt_rxbtextloss",                    0 },
    { "bt_elna_on2off_time_ns",            0 },
    { "bt_elna_off2on_time_ns",            0 },
    { "bt_hipower_mode",                   0 },
    { "bt_fem_control",                    0 },
    { "bt_feature_32k_clock",              0 },
    { "bt_feature_log",                    0 },
    { "bt_cali_swtich_all",                0 },
    { "bt_ant_num_bt",                     0 },
    { "bt_power_level_control",            0 },
    { "bt_country_code",                   0 },
    { "bt_reserved1",                      0 },
    { "bt_reserved2",                      0 },
    { "bt_reserved3",                      0 },
    { "bt_dedicated_antenna",              0 },
    { "bt_reserved5",                      0 },
    { "bt_reserved6",                      0 },
    { "bt_reserved7",                      0 },
    { "bt_reserved8",                      0 },
    { "bt_reserved9",                      0 },
    { "bt_reserved10",                     0 },

    { NULL, 0 }
};

/* 定义不能超过BFGX_BT_CUST_INI_SIZE/4 (128) 最后使用 { NULL, 0 } 结尾 */
STATIC bfgx_ini_cmd g_bfgx_ini_config_cmd_mp15[BFGX_BT_CUST_INI_SIZE / 4] = {
    { "bt_maxpower",                       0 },
    { "bt_edrpow_offset",                  0 },
    { "bt_blepow_offset",                  0 },
    { "bt_cali_txpwr_pa_ref_num",          0 },
    { "bt_cali_txpwr_pa_ref_band1",        0 },
    { "bt_cali_txpwr_pa_ref_band2",        0 },
    { "bt_cali_txpwr_pa_ref_band3",        0 },
    { "bt_cali_txpwr_pa_ref_band4",        0 },
    { "bt_cali_txpwr_pa_ref_band5",        0 },
    { "bt_cali_txpwr_pa_ref_band6",        0 },
    { "bt_cali_txpwr_pa_ref_band7",        0 },
    { "bt_cali_txpwr_pa_ref_band8",        0 },
    { "bt_cali_txpwr_pa_fre1",             0 },
    { "bt_cali_txpwr_pa_fre2",             0 },
    { "bt_cali_txpwr_pa_fre3",             0 },
    { "bt_cali_txpwr_pa_fre4",             0 },
    { "bt_cali_txpwr_pa_fre5",             0 },
    { "bt_cali_txpwr_pa_fre6",             0 },
    { "bt_cali_txpwr_pa_fre7",             0 },
    { "bt_cali_txpwr_pa_fre8",             0 },
    { "bt_cali_bt_tone_amp_grade",         0 },
    { "bt_rxdc_band",                      0 },
    { "bt_dbb_scaling_saturation",         0 },
    { "bt_productline_upccode_search_max", 0 },
    { "bt_productline_upccode_search_min", 0 },
    { "bt_dynamicsarctrl_bt",              0 },
    { "bt_powoffsbt",                      0 },
    { "bt_elna_2g_bt",                     0 },
    { "bt_rxisobtelnabyp",                 0 },
    { "bt_rxgainbtelna",                   0 },
    { "bt_rxbtextloss",                    0 },
    { "bt_elna_on2off_time_ns",            0 },
    { "bt_elna_off2on_time_ns",            0 },
    { "bt_hipower_mode",                   0 },
    { "bt_fem_control",                    0 },
    { "bt_feature_32k_clock",              0 },
    { "bt_feature_log",                    0 },
    { "bt_cali_switch_all",                0 },
    { "bt_ant_num_bt",                     0 },
    { "bt_power_level_control",            0 },
    { "bt_country_code",                   0 },
    { "bt_power_idle_voltage",             0 },
    { "bt_power_tx_voltage",               0 },
    { "bt_power_rx_voltage",               0 },
    { "bt_power_sleep_voltage",            0 },
    { "bt_power_idle_current",             0 },
    { "bt_power_tx_current",               0 },
    { "bt_power_rx_current",               0 },
    { "bt_power_sleep_current",            0 },
    { "bt_20dbm_txpwr_cali_num",           0 },
    { "bt_20dbm_txpwr_cali_freq_ref1",     0 },
    { "bt_20dbm_txpwr_cali_freq_ref2",     0 },
    { "bt_20dbm_txpwr_cali_freq_ref3",     0 },
    { "bt_20dbm_txpwr_cali_freq_ref4",     0 },
    { "bt_20dbm_txpwr_cali_freq_ref5",     0 },
    { "bt_20dbm_txpwr_cali_freq_ref6",     0 },
    { "bt_20dbm_txpwr_cali_freq_ref7",     0 },
    { "bt_20dbm_txpwr_cali_freq_ref8",     0 },
    { "bt_20dbm_txpwr_cali_freq_ref9",     0 },
    { "bt_20dbm_txpwr_cali_freq_ref10",    0 },
    { "bt_20dbm_txpwr_cali_freq_ref11",    0 },
    { "bt_20dbm_txpwr_cali_freq_ref12",    0 },
    { "bt_20dbm_txpwr_cali_freq_ref13",    0 },
    { "bt_reserved1",                      0 },
    { "bt_20dbm_txpwr_adjust",             0 },
    { "bt_feature_config",                 0 },
    { "bt_dedicated_antenna",              0 },
    { "bt_reserved5",                      0 },
    { "bt_reserved6",                      0 },
    { "bt_reserved7",                      0 },
    { "bt_reserved8",                      0 },
    { "bt_reserved9",                      0 },
    { "bt_reserved10",                     0 },

    { NULL, 0 }
};

/* 定义不能超过BFGX_BT_CUST_INI_SIZE/4 (128) 最后使用 { NULL, 0 } 结尾 */
STATIC bfgx_ini_cmd g_bfgx_ini_config_cmd_mp16[BFGX_BT_CUST_INI_SIZE / 4] = {
    { "bt_maxpower",                0 },
    { "bt_edrpow_offset",           0 },
    { "bt_blepow_offset",           0 },
    { "bt_power_level_control",     0 },
    { "rf_trx_features",            0 },
    { "bt_dedicated_antenna",       0 },
    { "bt_elna_2g_bt",              0 },
    { "bt_feature_config",          0 },
    { "bt_power_idle_voltage",      0 },
    { "bt_power_tx_voltage",        0 },
    { "bt_power_rx_voltage",        0 },
    { "bt_power_sleep_voltage",     0 },
    { "bt_power_idle_current",      0 },
    { "bt_power_tx_current",        0 },
    { "bt_power_rx_current",        0 },
    { "bt_power_sleep_current",     0 },
    { "bt_priv_config",             0 },
    { "bt_ce_adaptive",             0 },
    { "bt_cali_switch_all",         0 },
    { "bt_powermgmt",               0 },
    { "bt_reserved1",               0 },
    { "bt_reserved2",               0 },
    { "bt_reserved3",               0 },

    { NULL, 0 }
};

/* 定义不能超过BFGX_BT_CUST_INI_SIZE/4 (128) 最后使用 { NULL, 0 } 结尾 */
STATIC bfgx_ini_cmd g_bfgx_ini_config_cmd_mp16c[BFGX_BT_CUST_INI_SIZE / 4] = {
    { "bt_maxpower",                    0 },
    { "bt_edrpow_offset",               0 },
    { "bt_blepow_offset",               0 },
    { "bt_power_level_control",         0 },
    { "rf_trx_features",                0 },
    { "bt_dedicated_antenna",           0 },
    { "bt_elna_2g_bt",                  0 },
    { "bt_feature_config",              0 },
    { "bt_power_idle_voltage",          0 },
    { "bt_power_tx_voltage",            0 },
    { "bt_power_rx_voltage",            0 },
    { "bt_power_sleep_voltage",         0 },
    { "bt_power_idle_current",          0 },
    { "bt_power_tx_current",            0 },
    { "bt_power_rx_current",            0 },
    { "bt_power_sleep_current",         0 },
    { "bt_priv_config",                 0 },
    { "bt_ce_adaptive",                 0 },
    { "bt_cali_switch_all",             0 },
    { "bt_fem_mod_config",              0 },

    { "bt_tx_pwr_c_offset_high_0",      0 },
    { "bt_tx_pwr_c_offset_high_1",      0 },
    { "bt_tx_pwr_c_offset_high_2",      0 },
    { "bt_tx_pwr_c_offset_high_3",      0 },
    { "bt_tx_pwr_c_offset_high_4",      0 },
    { "bt_tx_pwr_c_offset_high_5",      0 },
    { "bt_tx_pwr_c_offset_high_6",      0 },
    { "bt_tx_pwr_c_offset_high_7",      0 },

    { "bt_tx_pwr_c_offset_norm_ad_0",   0 },
    { "bt_tx_pwr_c_offset_norm_ad_1",   0 },
    { "bt_tx_pwr_c_offset_norm_ad_2",   0 },
    { "bt_tx_pwr_c_offset_norm_ad_3",   0 },
    { "bt_tx_pwr_c_offset_norm_ad_4",   0 },
    { "bt_tx_pwr_c_offset_norm_ad_5",   0 },
    { "bt_tx_pwr_c_offset_norm_ad_6",   0 },
    { "bt_tx_pwr_c_offset_norm_ad_7",   0 },

    { "bt_tx_pwr_c_offset_norm_a0_0",   0 },
    { "bt_tx_pwr_c_offset_norm_a0_1",   0 },
    { "bt_tx_pwr_c_offset_norm_a0_2",   0 },
    { "bt_tx_pwr_c_offset_norm_a0_3",   0 },
    { "bt_tx_pwr_c_offset_norm_a0_4",   0 },
    { "bt_tx_pwr_c_offset_norm_a0_5",   0 },
    { "bt_tx_pwr_c_offset_norm_a0_6",   0 },
    { "bt_tx_pwr_c_offset_norm_a0_7",   0 },

    { "gle_tx_pwr_c_offset_0",          0 },
    { "gle_tx_pwr_c_offset_1",          0 },
    { "gle_tx_pwr_c_offset_2",          0 },
    { "gle_tx_pwr_c_offset_3",          0 },
    { "gle_tx_pwr_c_offset_4",          0 },
    { "gle_tx_pwr_c_offset_5",          0 },
    { "gle_tx_pwr_c_offset_6",          0 },
    { "gle_tx_pwr_c_offset_7",          0 },

    { "bt_spxt_ctrl_config",            0 },

    { "bt_powermgmt",                   0 },

    { "bt_sar_pwrctrl_en",              0 },

    { "bt_20dbm_mixbuf_code",           0 },
    { "bt_glepow_offset",               0 },
    { "gle_dpsk_pwr",                   0 },

    { "bt_wlcoex_wlan_siso",            0 },
    { "bt_reserved2",                   0 },
    { "bt_reserved3",                   0 },

    { NULL, 0 }
};

/* 定义不能超过BFGX_BT_CUST_INI_SIZE/4 (128) */
STATIC int32_t g_bfgx_cust_ini_data[BFGX_BT_CUST_INI_SIZE / 4] = {0};

/*
 * 函 数 名  : get_cali_count
 * 功能描述  : 返回校准的次数，首次开机校准时为0，以后递增
 * 输入参数  : uint32 *count:调用函数保存校准次数的地址
 * 输出参数  : count:自开机以来，已经校准的次数
 * 返 回 值  : 0表示成功，-1表示失败
 */
int32_t get_cali_count(uint32_t *count)
{
    if (count == NULL) {
        ps_print_err("count is NULL\n");
        return -EFAIL;
    }

    *count = g_cali_update_channel_info;

    ps_print_warning("cali update info is [%d]\r\n", g_cali_update_channel_info);

    return SUCC;
}

#ifdef HISI_NVRAM_SUPPORT
/*
 * 函 数 名  : bfgx_get_nv_data_buf
 * 功能描述  : 返回保存bfgx nv数据的内存地址
 * 输出参数  : nv buf的长度
 * 返 回 值  : bfgx nv数据buf的地址，也可能是NULL
 */
STATIC void *bfgx_get_nv_data_buf(uint32_t *pul_len)
{
    bfgx_cali_data_stru *pst_bfgx_cali_data_buf = NULL;

    if (g_bfgx_cali_data_buf == NULL) {
        return NULL;
    }

    pst_bfgx_cali_data_buf = (bfgx_cali_data_stru *)g_bfgx_cali_data_buf;

    *pul_len = (uint32_t)sizeof(pst_bfgx_cali_data_buf->auc_nv_data);

    ps_print_info("bfgx nv buf size is %d\n", *pul_len);

    return pst_bfgx_cali_data_buf->auc_nv_data;
}

/*
 * 函 数 名  : bfgx_nv_data_init
 * 功能描述  : bt 校准NV读取
 */
STATIC int32_t bfgx_nv_data_init(void)
{
#ifdef _PRE_WINDOWS_SUPPORT
    return INI_SUCC;
#else
    int32_t l_ret;
    char *pst_buf;
    uint32_t len;

    uint8_t bt_cal_nvram_tmp[OAL_BT_NVRAM_DATA_LENGTH];

    l_ret = read_conf_from_nvram(bt_cal_nvram_tmp, OAL_BT_NVRAM_DATA_LENGTH, OAL_BT_NVRAM_NUMBER, OAL_BT_NVRAM_NAME);
    if (l_ret != INI_SUCC) {
        ps_print_err("bfgx_nv_data_init::BT read NV error!");
        // last byte of NV ram is used to mark if NV ram is failed to read.
        bt_cal_nvram_tmp[OAL_BT_NVRAM_DATA_LENGTH - 1] = OAL_TRUE;
    } else {
        // last byte of NV ram is used to mark if NV ram is failed to read.
        bt_cal_nvram_tmp[OAL_BT_NVRAM_DATA_LENGTH - 1] = OAL_FALSE;
    }

    pst_buf = bfgx_get_nv_data_buf(&len);
    if (pst_buf == NULL) {
        ps_print_err("get bfgx nv buf fail!");
        return INI_FAILED;
    }
    if (len < OAL_BT_NVRAM_DATA_LENGTH) {
        ps_print_err("get bfgx nv buf size %d, NV data size is %d!", len, OAL_BT_NVRAM_DATA_LENGTH);
        return INI_FAILED;
    }

    l_ret = memcpy_s(pst_buf, len, bt_cal_nvram_tmp, OAL_BT_NVRAM_DATA_LENGTH);
    if (l_ret != EOK) {
        ps_print_err("bfgx_nv_data_init FAILED!");
        return INI_FAILED;
    }
    ps_print_info("bfgx_nv_data_init SUCCESS");
    return INI_SUCC;
#endif
}
#endif

/*
 * 函 数 名  : save_get_bfgx_cali_data
 * 功能描述  : 返回保存bfgx校准数据的内存首地址以及长度
 * 输入参数  : uint8  *buf:调用函数保存bfgx校准数据的首地址
 *            uint32_t buf_len:buf的长度
 * 返 回 值  : 0表示成功，-1表示失败
 */
STATIC int32_t save_get_bfgx_cali_data(uint8_t *buf, uint32_t buf_len)
{
    uint32_t bfgx_cali_data_len;

    ps_print_info("%s\n", __func__);

#ifdef HISI_NVRAM_SUPPORT
    if (bfgx_nv_data_init() != OAL_SUCC) {
        ps_print_err("bfgx nv data init fail!\n");
    }
#endif

    bfgx_cali_data_len = (uint32_t)sizeof(bfgx_cali_data_stru);
    if (buf_len < bfgx_cali_data_len) {
        ps_print_err("bfgx cali buf len[%d] is smaller than struct size[%d]\n", buf_len, bfgx_cali_data_len);
        return -EFAIL;
    }

    if (memcpy_s(buf, buf_len, g_bfgx_cali_data_buf, bfgx_cali_data_len) != EOK) {
        ps_print_err("bfgx cali data copy fail, buf len = [%d], bfgx_cali_data_len = [%d]\n",
                     buf_len, bfgx_cali_data_len);
        return -EFAIL;
    }

    return SUCC;
}

STATIC void plat_bfgx_cali_data_test(void)
{
    bfgx_cali_data_stru *pst_cali_data = NULL;
    uint32_t *p_test = NULL;
    uint32_t count, i;

    pst_cali_data = (bfgx_cali_data_stru *)g_bfgx_cali_data_buf;
    p_test = (uint32_t *)(pst_cali_data->auc_bfgx_data);
    count = (uint32_t)(sizeof(pst_cali_data->auc_bfgx_data) / sizeof(uint32_t));

    for (i = 0; i < count; i++) {
        p_test[i] = i;
    }
}

STATIC int32_t get_board_specify(uint32_t fw_addr, uint8_t *index)
{
    int32_t subchip_type = get_mpxx_subchip_type();
    if (subchip_type < BOARD_VERSION_MP13 || subchip_type > BOARD_VERSION_GF61) {
        ps_print_err("subchip type invalid! subchip=%d\n", subchip_type);
        return -EFAIL;
    }

    if (subchip_type == BOARD_VERSION_MP16C) {
        if (fw_addr == 0x4472F800) {
            *index = BUART;
        } else if (fw_addr == 0x444D7800) { // G核蓝牙校准地址
            *index = GUART;
        } else {
            ps_print_err("cali address[0x%x] not adapter, pleas check cfg", fw_addr);
            return -EFAIL;
        }
        return SUCC;
    }

    *index = BUART;
    return SUCC;
}

/*
 * 函 数 名  : mpxx_get_bfgx_cali_data
 * 功能描述  : 返回保存bfgx校准数据的内存首地址以及长度
 * 输入参数  : uint8  *buf:调用函数保存bfgx校准数据的首地址
 *            uint32_t buf_len:buf的长度
 *            uint32_t fw_addr 固件加载的地址
 * 返 回 值  : 0表示成功，-1表示失败
 */
STATIC int32_t mpxx_get_bfgx_cali_data(uint8_t *buf, uint32_t buf_len, uint8_t uart_index)
{
    int32_t ret;
    struct ps_core_s *ps_core_d = NULL;
    struct st_bfgx_data *bfgx_data = NULL;
    bfgx_cali_data_stru *bfgx_cali_data_buf = NULL;

    ps_core_d = ps_get_core_reference(uart_index);
    if (ps_core_d == NULL) {
        ps_print_err("ps_core is null\n");
        return -EFAIL;
    }

    bfgx_data = &ps_core_d->bfgx_info[BFGX_BT];
    if (bfgx_data->cali_buf == NULL) {
        return -ENOMEM;
    }

    if (g_cali_buffer_debug != 0) {
        plat_bfgx_cali_data_test();
    } else {
        bfgx_cali_data_buf = (bfgx_cali_data_stru *)g_bfgx_cali_data_buf;
        if (memcpy_s(bfgx_cali_data_buf->auc_bfgx_data, BFGX_BT_CALI_DATA_SIZE,
                     bfgx_data->cali_buf, BFGX_BT_CALI_DATA_SIZE) != EOK) {
            ps_print_err("mp16c copy buffer len[%d], fail\n", BFGX_BT_CALI_DATA_SIZE);
            return -EFAIL;
        }
    }

    ret = save_get_bfgx_cali_data(buf, buf_len);
    if (ret < 0) {
        ps_print_err("save cali fail\n");
        return ret;
    }
    return SUCC;
}

/*
 * 函 数 名  : get_bfgx_cali_data
 * 功能描述  : 返回保存bfgx校准数据的内存首地址以及长度
 * 输入参数  : uint8  *buf:调用函数保存bfgx校准数据的首地址
 *            uint32_t buf_len:buf的长度
 *            uint32_t fw_addr 固件加载的地址
 * 返 回 值  : 0表示成功，-1表示失败
 */
int32_t get_bfgx_cali_data(uint8_t *buf, uint32_t buf_len, uint32_t fw_addr)
{
    int32_t ret;
    uint8_t uart_index;

    if (unlikely(g_bfgx_cali_data_buf == NULL)) {
        ps_print_err("g_bfgx_cali_data_buf is NULL\n");
        return -EFAIL;
    }

    ret = get_board_specify(fw_addr, &uart_index);
    if (ret < 0) {
        ps_print_err("get board cali fail\n");
        return ret;
    }

    ret = mpxx_get_bfgx_cali_data(buf, buf_len, uart_index);
    if (ret < 0) {
        ps_print_err("get cali data_fail\n");
        return ret;
    }

    return SUCC;
}

#ifdef _PRE_PLAT_FEATURE_GF6X_PCIE
static uint8_t *gf6x_alloc_dma_buff(uint32_t buffer_len)
{
    oal_pcie_linux_res *res = NULL;
    res = oal_get_default_pcie_handler();
    if ((res != NULL) && (res->comm_res != NULL) && (res->comm_res->pcie_dev != NULL)) {
        return dma_alloc_coherent(&(res->comm_res->pcie_dev->dev), buffer_len,
            (dma_addr_t *)&g_cali_data_buf_phy_addr, GFP_KERNEL);
    }
    ps_print_err("gf61_alloc_dma_buff:: get_pcie_dev fail\n");
    return NULL;
}
#endif

/*
 * 函 数 名  : get_cali_data_buf_addr
 * 功能描述  : 返回保存校准数据的内存地址
 */
void *get_cali_data_buf_addr(void)
{
    int32_t type = get_mpxx_subchip_type();
    uint8_t *buffer = NULL;
    uint32_t ul_buffer_len = (uint32_t)MP16_MIMO_CALI_DATA_STRU_LEN;

    /* 仅针对MP16、MP16C、GF61 PCIE */
    if ((hcc_is_pcie() == OAL_FALSE) ||
        (type != BOARD_VERSION_MP16 && type != BOARD_VERSION_MP16C && type != BOARD_VERSION_GF61)) {
        return g_cali_data_buf;
    }

    /* 已申请直接返回 */
    if (g_cali_data_buf_dma != NULL) {
        return g_cali_data_buf_dma;
    }

#ifdef _PRE_PLAT_FEATURE_HI110X_PCIE
    buffer = dma_alloc_coherent(&oal_get_wifi_pcie_dev()->dev, ul_buffer_len,
        &g_cali_data_buf_phy_addr, GFP_KERNEL);
#elif (defined _PRE_PLAT_FEATURE_GF6X_PCIE)
    buffer = gf6x_alloc_dma_buff(ul_buffer_len);
#endif
    if (buffer == NULL) {
        ps_print_err("get_cali_data_buf_addr:: malloc for g_cali_data_buf_dma fail\n");
        return NULL;
    }

    g_cali_data_buf_dma = buffer;
    memset_s(g_cali_data_buf_dma, ul_buffer_len, 0, ul_buffer_len);
    ps_print_info("get_cali_data_buf_addr:: buf(%p) size %d alloc succ", g_cali_data_buf_dma, ul_buffer_len);
    return g_cali_data_buf_dma;
}

/*
 * 函 数 名  : get_cali_data_buf_phy_addr
 * 功能描述  : 返回保存校准数据的DMA物理内存地址
 */
uint64_t get_cali_data_buf_phy_addr(void)
{
    return g_cali_data_buf_phy_addr;
}

EXPORT_SYMBOL(get_cali_data_buf_phy_addr);
EXPORT_SYMBOL(get_cali_data_buf_addr);
EXPORT_SYMBOL(g_netdev_is_open);
EXPORT_SYMBOL(g_cali_update_channel_info);

/*
 * 函 数 名  : wifi_get_bfgx_rc_data_buf_addr
 * 功能描述  : 返回保存wifi rc code校准数据的内存地址
 */
void *wifi_get_bfgx_rc_data_buf_addr(uint32_t *pul_len)
{
    bfgx_cali_data_stru *pst_bfgx_cali_buf = NULL;

    if (oal_any_null_ptr2(g_bfgx_cali_data_buf, pul_len)) {
        return NULL;
    }

    pst_bfgx_cali_buf = (bfgx_cali_data_stru *)g_bfgx_cali_data_buf;
    *pul_len = (uint32_t)sizeof(pst_bfgx_cali_buf->auc_wifi_rc_code_data);

    ps_print_info("wifi cali size is %d\n", *pul_len);

    return pst_bfgx_cali_buf->auc_wifi_rc_code_data;
}

EXPORT_SYMBOL(wifi_get_bfgx_rc_data_buf_addr);

/*
 * 函 数 名  : wifi_get_bt_cali_data_buf
 * 功能描述  : 返回保存wifi cali data for bt数据的内存地址
 * 输出参数  : wifi cali data for bt数据buf的长度
 * 返 回 值  : wifi cali data for bt数据buf的地址，也可能是NULL
 */
void *wifi_get_bt_cali_data_buf(uint32_t *pul_len)
{
    bfgx_cali_data_stru *pst_bfgx_cali_data_buf = NULL;

    if (oal_any_null_ptr2(g_bfgx_cali_data_buf, pul_len)) {
        return NULL;
    }

    pst_bfgx_cali_data_buf = (bfgx_cali_data_stru *)g_bfgx_cali_data_buf;

    *pul_len = (uint32_t)sizeof(pst_bfgx_cali_data_buf->auc_wifi_cali_for_bt_data);

    ps_print_info("bfgx wifi cali data for bt buf size is %d\n", *pul_len);

    return pst_bfgx_cali_data_buf->auc_wifi_cali_for_bt_data;
}

EXPORT_SYMBOL(wifi_get_bt_cali_data_buf);

/*
 * 函 数 名  : bfgx_get_cust_ini_data_buf
 * 功能描述  : 返回保存bfgx ini定制化数据的内存地址
 * 输出参数  : bfgx ini定制化数据buf的长度
 * 返 回 值  : bfgx ini数据buf的地址，也可能是NULL
 */
STATIC void *bfgx_get_cust_ini_data_buf(uint32_t *pul_len)
{
    bfgx_cali_data_stru *pst_bfgx_cali_data_buf = NULL;

    if (g_bfgx_cali_data_buf == NULL) {
        return NULL;
    }

    pst_bfgx_cali_data_buf = (bfgx_cali_data_stru *)g_bfgx_cali_data_buf;

    *pul_len = (uint32_t)sizeof(pst_bfgx_cali_data_buf->auc_bt_cust_ini_data);

    ps_print_info("bfgx cust ini buf size is %d\n", *pul_len);

    return pst_bfgx_cali_data_buf->auc_bt_cust_ini_data;
}

#ifndef BFGX_UART_DOWNLOAD_SUPPORT
STATIC int32_t wifi_cali_buf_malloc(void)
{
    uint8_t *buffer = NULL;
    uint32_t ul_buffer_len;
    int32_t type = get_mpxx_subchip_type();
    if ((type == BOARD_VERSION_MP16) ||
        (type == BOARD_VERSION_MP16C) ||
        (type == BOARD_VERSION_GF61)) {
        ul_buffer_len = (uint32_t)MP16_MIMO_CALI_DATA_STRU_LEN;
    } else if (type == BOARD_VERSION_MP15) {
        ul_buffer_len = OAL_MIMO_CALI_DATA_STRU_LEN;
    } else {
        ul_buffer_len = OAL_DOUBLE_CALI_DATA_STRU_LEN;
    }

    if (g_cali_data_buf == NULL) {
        buffer = (uint8_t *)os_kzalloc_gfp(ul_buffer_len);
        if (buffer == NULL) {
            ps_print_err("malloc for g_cali_data_buf fail\n");
            return -ENOMEM;
        }
        g_cali_data_buf = buffer;
        memset_s(g_cali_data_buf, ul_buffer_len, 0, ul_buffer_len);
        ps_print_info("g_cali_data_buf(%p) size %d alloc in sysfs init", g_cali_data_buf, ul_buffer_len);
    } else {
        ps_print_info("g_cali_data_buf size %d alloc in sysfs init\n", ul_buffer_len);
    }

    return SUCC;
}
#endif

STATIC int32_t bfgx_cali_buf_malloc(void)
{
    uint8_t *buffer = NULL;

    if (g_bfgx_cali_data_buf == NULL) {
        buffer = (uint8_t *)os_kzalloc_gfp(BFGX_CALI_DATA_BUF_LEN);
        if (buffer == NULL) {
            os_mem_kfree(g_cali_data_buf);
            g_cali_data_buf = NULL;
            ps_print_err("malloc for g_bfgx_cali_data_buf fail\n");
            return -ENOMEM;
        }
        g_bfgx_cali_data_buf = buffer;
    } else {
        ps_print_info("g_bfgx_cali_data_buf alloc in sysfs init\n");
    }

    return SUCC;
}

/*
 * 函 数 名  : cali_data_buf_malloc
 * 功能描述  : 分配保存校准数据的内存
 * 返 回 值  : 0表示分配成功，-1表示分配失败
 */
int32_t cali_data_buf_malloc(void)
{
#ifndef BFGX_UART_DOWNLOAD_SUPPORT
    if (wifi_cali_buf_malloc() < 0) {
        return -ENOMEM;
    }
#endif

    if (bfgx_cali_buf_malloc() < 0) {
        return -ENOMEM;
    }

    return SUCC;
}

/*
 * 函 数 名  : cali_data_buf_free
 * 功能描述  : 释放保存校准数据的内存
 */
void cali_data_buf_free(void)
{
    if (g_cali_data_buf != NULL) {
        os_mem_kfree(g_cali_data_buf);
        g_cali_data_buf = NULL;
    }

    if (g_cali_data_buf_dma != NULL) {
#ifdef _PRE_PLAT_FEATURE_HI110X_PCIE
        dma_free_coherent(&oal_get_wifi_pcie_dev()->dev,
            MP16_MIMO_CALI_DATA_STRU_LEN, g_cali_data_buf_dma, g_cali_data_buf_phy_addr);
#elif (defined _PRE_PLAT_FEATURE_GF6X_PCIE)
        dma_free_coherent(&(oal_get_default_pcie_handler())->comm_res->pcie_dev->dev,
            MP16_MIMO_CALI_DATA_STRU_LEN, g_cali_data_buf_dma, g_cali_data_buf_phy_addr);
#endif
        g_cali_data_buf_dma = NULL;
    }

    g_cali_data_buf_phy_addr = 0;
    if (g_bfgx_cali_data_buf != NULL) {
        os_mem_kfree(g_bfgx_cali_data_buf);
        g_bfgx_cali_data_buf = NULL;
    }
}

/*
 * 函 数 名  : wait_bfgx_cali_data
 * 功能描述  : 等待接受device发送的校准数据
 * 返 回 值  : 0表示成功，-1表示失败
 */
STATIC int32_t wait_bfgx_cali_data(void)
{
#define WAIT_BFGX_CALI_DATA_TIME 2000
    unsigned long timeleft;

    timeleft = wait_for_completion_timeout(&g_cali_recv_done, msecs_to_jiffies(WAIT_BFGX_CALI_DATA_TIME));
    if (!timeleft) {
        ps_print_err("wait bfgx cali data timeout\n");
        return -ETIMEDOUT;
    }

    return 0;
}

STATIC bfgx_ini_cmd *bfgx_cust_get_ini(void)
{
    int32_t l_subchip_type = get_mpxx_subchip_type();
    bfgx_ini_cmd *p_bfgx_ini_cmd = NULL;

    switch (l_subchip_type) {
        case BOARD_VERSION_MP13:
            p_bfgx_ini_cmd = (bfgx_ini_cmd *)&g_bfgx_ini_config_cmd_mp13;
            ps_print_dbg("bfgx load ini MP13");
            break;
        case BOARD_VERSION_MP15:
            p_bfgx_ini_cmd = (bfgx_ini_cmd *)&g_bfgx_ini_config_cmd_mp15;
            ps_print_dbg("bfgx load ini MP15");
            break;
        case BOARD_VERSION_MP16:
            p_bfgx_ini_cmd = (bfgx_ini_cmd *)&g_bfgx_ini_config_cmd_mp16;
            ps_print_dbg("bfgx load ini MP16");
            break;
        case BOARD_VERSION_MP16C:
        case BOARD_VERSION_GF61:
            p_bfgx_ini_cmd = (bfgx_ini_cmd *)&g_bfgx_ini_config_cmd_mp16c;
            ps_print_dbg("bfgx load ini GF61&MP16C");
            break;
        default:
            ps_print_err("bfgx load ini error: No corresponding chip was found, chiptype %d", l_subchip_type);
            break;
    }
    return p_bfgx_ini_cmd;
}

/*
 * 函 数 名  : bfgx_cust_ini_init
 * 功能描述  : bt校准定制化项初始化
 * 返 回 值  : 0表示成功，-1表示失败
 */
STATIC int32_t bfgx_cust_ini_init(void)
{
    int32_t i;
    int32_t l_ret = INI_FAILED;
    int32_t l_cfg_value = 0;
    int32_t l_ori_val;
    char *pst_buf = NULL;
    uint32_t len;
    bfgx_ini_cmd *p_bfgx_ini_cmd = bfgx_cust_get_ini();
    if (p_bfgx_ini_cmd == NULL) {
        return INI_FAILED;
    }

    for (i = 0; i < (BFGX_BT_CUST_INI_SIZE / 4); i++) { /* 512/4转换为字节 */
        /* 定制化项目列表名称以 null 结尾 */
        if (p_bfgx_ini_cmd[i].name == NULL) {
            ps_print_info("bfgx ini load end count: %d", i);
            break;
        }

        l_ori_val = p_bfgx_ini_cmd[i].init_value;

        /* 获取ini的配置值 */
        l_ret = get_cust_conf_int32(INI_MODU_DEV_BT, p_bfgx_ini_cmd[i].name, &l_cfg_value);
        if (l_ret == INI_FAILED) {
            g_bfgx_cust_ini_data[i] = l_ori_val;
            ps_print_dbg("bfgx read ini file failed cfg_id[%d],default value[%d]!", i, l_ori_val);
            continue;
        }

        g_bfgx_cust_ini_data[i] = l_cfg_value;

        ps_print_info("bfgx ini init [id:%d] [%s] changed from [%d]to[%d]",
                      i, p_bfgx_ini_cmd[i].name, l_ori_val, l_cfg_value);
    }

    pst_buf = bfgx_get_cust_ini_data_buf(&len);
    if (pst_buf == NULL) {
        ps_print_err("get cust ini buf fail!");
        return INI_FAILED;
    }

    memcpy_s(pst_buf, len, g_bfgx_cust_ini_data, sizeof(g_bfgx_cust_ini_data));

    return INI_SUCC;
}

/*
 * 函 数 名  : bfgx_customize_init
 * 功能描述  : bfgx定制化项初始化，读取ini配置文件，读取nv配置项
 * 返 回 值  : 0表示成功，-1表示失败
 */
int32_t bfgx_customize_init(void)
{
    int32_t ret;

    /* 申请用于保存校准数据的buffer */
    ret = cali_data_buf_malloc();
    if (ret != OAL_SUCC) {
        ps_print_err("alloc cali data buf fail\n");
        return INI_FAILED;
    }

    init_completion(&g_cali_recv_done);

    ret = bfgx_cust_ini_init();
    if (ret != OAL_SUCC) {
        ps_print_err("bfgx ini init fail!\n");
        cali_data_buf_free();
        return INI_FAILED;
    }

#ifdef HISI_NVRAM_SUPPORT
    ret = bfgx_nv_data_init();
    if (ret != OAL_SUCC) {
        ps_print_err("bfgx nv data init fail!\n");
        cali_data_buf_free();
        return INI_FAILED;
    }
#endif

    return INI_SUCC;
}

int32_t ps_recv_bt_cali_data(struct ps_core_s *ps_core_d, uint8_t *buf_ptr)
{
    uint16_t rx_pkt_total_len;
    uint32_t copy_len;
    struct st_bfgx_data *pst_bfgx_data = NULL;

    if (ps_core_d == NULL || buf_ptr == NULL) {
        ps_print_err("ps_core_d or buf is NULL\n");
        return -EINVAL;
    }

    pst_bfgx_data = &ps_core_d->bfgx_info[BFGX_BT];
    if (pst_bfgx_data->cali_buf == NULL) {
        ps_print_err("bt cali buffer is null\n");
        return -EINVAL;
    }

    rx_pkt_total_len = ps_core_d->rx_pkt_total_len -
                       (uint16_t)(sizeof(struct ps_packet_head) + sizeof(struct ps_packet_end));
    copy_len = (rx_pkt_total_len > BFGX_BT_CALI_DATA_SIZE) ? BFGX_BT_CALI_DATA_SIZE : rx_pkt_total_len;

    ps_print_info("[%s]recv bfgx cali data, rx_len=%d,copy_len=%d\n",
                  index2name(ps_core_d->pm_data->index), rx_pkt_total_len, copy_len);
    if (unlikely(memcpy_s(pst_bfgx_data->cali_buf, BFGX_BT_CALI_DATA_SIZE, buf_ptr, copy_len) != EOK)) {
        ps_print_err("memcopy_s error, destlen=%d, srclen=%d\n ", BFGX_BT_CALI_DATA_SIZE, copy_len);
    }

    complete(&g_cali_recv_done);

    return 0;
}

/*
 * 函 数 名  : bt_cali_data_init
 * 功能描述  : 开机打开bt，进行bt校准
 * 返 回 值  : 0表示成功，-1表示失败
 */
int32_t bt_cali_data_init(struct ps_core_s *ps_core_d)
{
    int32_t ret = 0;
    struct st_bfgx_data *pst_bfgx_data = NULL;
    struct pm_top* pm_top_data = pm_get_top();

    ps_print_info("%s\n", __func__);

    if (get_mpxx_subchip_type() == BOARD_VERSION_MP16 && ps_core_d->uart_index == GUART) {
        return SUCC;
    }

    mutex_lock(&(pm_top_data->host_mutex));
    pst_bfgx_data = &ps_core_d->bfgx_info[BFGX_BT];

    if (atomic_read(&pst_bfgx_data->subsys_state) == POWER_STATE_OPEN) {
        ps_print_warning("%s has opened! ignore bfgx cali!\n", service_get_name(BFGX_BT));
        goto open_fail;
    }
    if (pst_bfgx_data->cali_buf != NULL) {
        ps_print_err("%s already cali\n", service_get_name(BFGX_BT));
        goto open_fail;
    }

    pst_bfgx_data->cali_buf = (uint8_t *) os_kzalloc_gfp(BFGX_BT_CALI_DATA_SIZE);
    if (pst_bfgx_data->cali_buf == NULL) {
        ps_print_err("cali buf malloc fail\n");
        goto open_fail;
    }

    ret = hw_bfgx_open(ps_core_d, BFGX_BT);
    if (ret != SUCC) {
        ps_print_err("bfgx cali, open bt fail\n");
        goto open_fail;
    }

    ret = wait_bfgx_cali_data();
    if (ret != SUCC) {
        ps_print_err("wait bfgx cali fail\n");
    }

    ret = hw_bfgx_close(ps_core_d, BFGX_BT);
    if (ret != SUCC) {
        ps_print_err("bfgx cali, clsoe bt fail\n");
    }
    mutex_unlock(&(pm_top_data->host_mutex));

    return ret;

open_fail:
    mutex_unlock(&(pm_top_data->host_mutex));
    return ret;
}

void bt_cali_data_exit(struct ps_core_s *ps_core_d)
{
    struct st_bfgx_data *pst_bfgx_data = NULL;

    if (ps_core_d == NULL) {
        return;
    }

    pst_bfgx_data = &ps_core_d->bfgx_info[BFGX_BT];
    os_mem_kfree(pst_bfgx_data->cali_buf);
}

void bt_txbf_get_wl_cali_data(void)
{
    unsigned stream, channel, level;
    bt_txbf_cali_param_stru *bt_txbf_cali_data = NULL;
    bt_txbf_cali_common_stru *common_cali_data = NULL;
    uint32_t cali_data_size;
    wlan_cali_data_para_stru *wl_cali_data = (wlan_cali_data_para_stru *)get_cali_data_buf_addr();

    if (wl_cali_data == NULL || (get_mpxx_subchip_type() != BOARD_VERSION_MP16 &&
        get_mpxx_subchip_type() != BOARD_VERSION_MP16C && get_mpxx_subchip_type() != BOARD_VERSION_GF61)) {
        return;
    }

    bt_txbf_cali_data = (bt_txbf_cali_param_stru *)wifi_get_bt_cali_data_buf(&cali_data_size);
    if (bt_txbf_cali_data == NULL) {
        return;
    }
    ps_print_warning("[BT TxBF]get required Tx calibration result from WLAN.");

    common_cali_data = &bt_txbf_cali_data->common_cali_data;

    // C0
    memcpy_s(&common_cali_data->rc_r_c_cali_data[0], sizeof(wlan_cali_rc_r_c_para_stru),
             &wl_cali_data->common_cali_data.rc_r_c_cali_data[WLAN_CALI_BAND_2G][0],
             sizeof(wlan_cali_rc_r_c_para_stru));
    memcpy_s(&common_cali_data->logen_cali_data[0], sizeof(wlan_cali_logen_para_stru),
             &wl_cali_data->common_cali_data.logen_cali_data_2g[0][WLAN_CALI_BAND_2G],
             sizeof(wlan_cali_logen_para_stru));

    // C1
    memcpy_s(&common_cali_data->rc_r_c_cali_data[1], sizeof(wlan_cali_rc_r_c_para_stru),
             &wl_cali_data->common_cali_data.rc_r_c_cali_data[WLAN_CALI_BAND_2G][1],
             sizeof(wlan_cali_rc_r_c_para_stru));
    memcpy_s(&common_cali_data->logen_cali_data[1], sizeof(wlan_cali_logen_para_stru),
             &wl_cali_data->common_cali_data.logen_cali_data_2g[1][WLAN_CALI_BAND_2G],
             sizeof(wlan_cali_logen_para_stru));

    for (stream = 0; stream < BT_TXBF_CALI_STREAMS; stream++) {
        bt_txbf_cali_stream_stru *current_stream = &bt_txbf_cali_data->stream_cali_data[stream];
        bt_txbf_cali_stream_extend_stru *current_stream_extend = &bt_txbf_cali_data->stream_cali_data_extend[stream];
        wlan_cali_2g_20m_save_stru *wl_cali_2g = &wl_cali_data->rf_cali_data[stream].cali_data_2g_20m;

        for (channel = 0; channel < WLAN_2G_CALI_BAND_NUM; channel++) {
            bt_txbf_cali_channel_stru *current_channel = &current_stream->channel_cali_data[channel];
            bt_txbf_cali_channel_extend_stru *current_channel_extend =
                &current_stream_extend->channel_cali_data_extend[channel];
            wlan_cali_basic_para_stru *wl_cali_band = &wl_cali_2g->cali_data[channel];

            // use WL calibration result of level 0 to compensate
            level = 0;
            current_channel->txdc_comp_i = wl_cali_band->txdc_cali_data.txdc_cmp_i[level];
            current_channel->txdc_comp_q = wl_cali_band->txdc_cali_data.txdc_cmp_q[level];
            memcpy_s(&current_channel->txiq_comp_siso, sizeof(wlan_cali_iq_coef_stru),
                     &wl_cali_band->txiq_cali_data.qmc_data[level].qmc_siso, sizeof(wlan_cali_iq_coef_stru));
            memcpy_s(&current_channel_extend->txpwr_cali_data, sizeof(wlan_cali_txpwr_para_stru),
                     &wl_cali_band->txpwr_cali_data, sizeof(wlan_cali_txpwr_para_stru));
        }
    }
}
