/**
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 *
 * Description: plat_cali.c header file
 * Author: @CompanyNameTag
 */

#ifndef PLAT_CALI_H
#define PLAT_CALI_H

/* 头文件包含 */
#include "plat_type.h"
#include "oal_types.h"
#include "oal_util.h"
#include "wlan_cali.h"
#include "hw_bfg_ps.h"

/* 宏定义 */
#define OAL_2G_CHANNEL_NUM            3
#define OAL_5G_20M_CHANNEL_NUM        7
#define OAL_5G_80M_CHANNEL_NUM        7
#define OAL_5G_160M_CHANNEL_NUM       2
#define OAL_5G_CHANNEL_NUM            (OAL_5G_20M_CHANNEL_NUM + OAL_5G_80M_CHANNEL_NUM + OAL_5G_160M_CHANNEL_NUM)
#define OAL_5G_DEVICE_CHANNEL_NUM     7
#define OAL_CALI_HCC_BUF_NUM          3
#define OAL_CALI_HCC_BUF_SIZE         1500
#define OAL_CALI_IQ_TONE_NUM          16
#define OAL_CALI_TXDC_GAIN_LVL_NUM    16 /* tx dc补偿值档位数目 */
#define OAL_BT_RF_FEQ_NUM             79 /* total Rf frequency number */
#define OAL_BT_CHANNEL_NUM            8  /* total Rf frequency number */
#define OAL_BT_POWER_CALI_CHANNEL_NUM 3
#define OAL_BT_NVRAM_DATA_LENGTH      104
#define OAL_BT_NVRAM_NAME             "BTCALNV"
#define OAL_BT_NVRAM_NUMBER           352

#define WIFI_2_4G_ONLY              0x2424
#define SYS_EXCEP_REBOOT            0xC7C7
#define OAL_CALI_PARAM_ADDITION_LEN 8
#define OAL_5G_IQ_CALI_TONE_NUM     8

#define BT_TXBF_CALI_STREAMS 2 /* BT TXBF仅使用C0、C1通道 */

#define CHECK_5G_ENABLE "radio_cap_0"

/* wifi校准buf长度 */
#define RF_CALI_DATA_BUF_LEN             0x4bb0
#define RF_SINGLE_CHAN_CALI_DATA_BUF_LEN (RF_CALI_DATA_BUF_LEN >> 1)
/* 校准结构体大小 */
#define OAL_SINGLE_CALI_DATA_STRU_LEN (RF_CALI_DATA_BUF_LEN + 4)
#define OAL_DOUBLE_CALI_DATA_STRU_LEN (OAL_SINGLE_CALI_DATA_STRU_LEN)

/* MP15 wifi校准buf长度 */
#define MP15_CALI_DATA_BUF_LEN             0xb380
#define MP15_SINGLE_CHAN_CALI_DATA_BUF_LEN (MP15_CALI_DATA_BUF_LEN >> 1)

/* MP15校准结构体大小 */
#define OAL_SOLO_CALI_DATA_STRU_LEN (MP15_CALI_DATA_BUF_LEN + 4)
#define OAL_MIMO_CALI_DATA_STRU_LEN (OAL_SOLO_CALI_DATA_STRU_LEN)

/* MP16 wifi校准buf长度 */
#define MP16_MIMO_CALI_DATA_STRU_LEN (sizeof(wlan_cali_data_para_stru))

/* 全局变量定义 */
extern uint32_t g_cali_update_channel_info;
extern uint8_t g_netdev_is_open;

/* STRUCT 定义 */
typedef struct {
    uint16_t us_analog_rxdc_cmp;
    uint16_t us_digital_rxdc_cmp_i;
    uint16_t us_digital_rxdc_cmp_q;
    uint8_t auc_reserve[2]; // 2字节保留对齐
} oal_rx_dc_comp_val_stru;

typedef struct {
    uint16_t us_txdc_cmp_i;
    uint16_t us_txdc_cmp_q;
} oal_txdc_comp_val_stru;

typedef struct {
    uint8_t uc_ppf_val;
    uint8_t auc_reserve[3]; // 3字节保留对齐
} oal_ppf_comp_val_stru;

typedef struct {
    uint16_t us_txiq_cmp_p;
    uint16_t us_txiq_cmp_e;
} oal_txiq_comp_val_stru;

typedef struct {
    uint16_t ul_cali_time;
    uint16_t bit_temperature : 3,
               uc_5g_chan_idx1 : 5,
               uc_5g_chan_idx2 : 5,
               en_update_bt : 3;
} oal_update_cali_channel_stru;

typedef struct {
    uint32_t ul_wifi_2_4g_only;
    uint32_t ul_excep_reboot;
    uint32_t ul_reserve[OAL_CALI_PARAM_ADDITION_LEN];
} oal_cali_param_addition_stru;

// should synchronize with BT Device structure
typedef struct {
    uint16_t txdc_comp_i;
    uint16_t txdc_comp_q;
    wlan_cali_iq_coef_stru txiq_comp_siso;
} bt_txbf_cali_channel_stru;

typedef struct {
    wlan_cali_txpwr_para_stru txpwr_cali_data;
    uint16_t reserved[20];
} bt_txbf_cali_channel_extend_stru;

typedef struct {
    bt_txbf_cali_channel_stru channel_cali_data[WLAN_2G_CALI_BAND_NUM];
} bt_txbf_cali_stream_stru;

typedef struct {
    bt_txbf_cali_channel_extend_stru channel_cali_data_extend[WLAN_2G_CALI_BAND_NUM];
} bt_txbf_cali_stream_extend_stru;

typedef struct {
    wlan_cali_rc_r_c_para_stru rc_r_c_cali_data[BT_TXBF_CALI_STREAMS];
    wlan_cali_logen_para_stru logen_cali_data[BT_TXBF_CALI_STREAMS];
} bt_txbf_cali_common_stru;

typedef struct {
    bt_txbf_cali_stream_stru stream_cali_data[BT_TXBF_CALI_STREAMS];
    bt_txbf_cali_stream_extend_stru stream_cali_data_extend[BT_TXBF_CALI_STREAMS];
    bt_txbf_cali_common_stru common_cali_data;
} bt_txbf_cali_param_stru;

/* 函数声明 */
int32_t get_cali_count(uint32_t *count);
int32_t get_bfgx_cali_data(uint8_t *buf, uint32_t buf_len, uint32_t fw_addr);
void *get_cali_data_buf_addr(void);
uint64_t get_cali_data_buf_phy_addr(void);
int32_t cali_data_buf_malloc(void);
void cali_data_buf_free(void);

typedef struct {
    char *name;
    int32_t init_value;
} bfgx_ini_cmd;

/* 以下5个宏定义，如果要修改长度，需要同步修改device的宏定义 */
#define BFGX_BT_CALI_DATA_SIZE             492
#define WIFI_CALI_DATA_FOR_FM_RC_CODE_SIZE 20
#define BFGX_NV_DATA_SIZE                  128
#define BFGX_BT_CUST_INI_SIZE              512
#define WIFI_CALI_DATA_FOR_BT              896
/* 考虑结构体总体长度考虑SDIO下载长度512对齐特性，这里长度为2048 */
typedef struct {
    uint8_t auc_bfgx_data[BFGX_BT_CALI_DATA_SIZE];
    uint8_t auc_wifi_rc_code_data[WIFI_CALI_DATA_FOR_FM_RC_CODE_SIZE];
    uint8_t auc_nv_data[BFGX_NV_DATA_SIZE];
    uint8_t auc_bt_cust_ini_data[BFGX_BT_CUST_INI_SIZE];
    uint8_t auc_wifi_cali_for_bt_data[WIFI_CALI_DATA_FOR_BT];
} bfgx_cali_data_stru;

#define BFGX_CALI_DATA_BUF_LEN (sizeof(bfgx_cali_data_stru))

int32_t bfgx_customize_init(void);
void *bfgx_get_cali_data_buf(uint32_t *pul_len);
void *wifi_get_bfgx_rc_data_buf_addr(uint32_t *pul_len);
void *wifi_get_bt_cali_data_buf(uint32_t *pul_len);
int32_t bt_cali_data_init(struct ps_core_s *ps_core_d);
void bt_cali_data_exit(struct ps_core_s *ps_core_d);
void bt_txbf_get_wl_cali_data(void);
int32_t ps_recv_bt_cali_data(struct ps_core_s *ps_core_d, uint8_t *buf_ptr);
#endif /* end of plat_cali.h */
