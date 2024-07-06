/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * 功能说明 : hmac_cali_mgmt.c 的头文件
 * 作    者 :
 * 创建日期 : 2012年11月20日
 */

#ifndef HMAC_CALI_MGMT_H
#define HMAC_CALI_MGMT_H

/* 1 其他头文件包含 */
#include "frw_ext_if.h"

#include "hmac_vap.h"
#include "plat_cali.h"
#include "wlan_spec.h"
#include "wlan_cali.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif
/* 2 宏定义 */
#define DPD_CORRAM_DATA_NUM                512
#define DPD_CORRAM_DATA_LEN                1024
#define MP13_DPD_OFFLINE_CALI_BW_NUM     2
#define MP13_2G_DPD_CALI_CHANNEL_NUM_20M 4
#define MP13_2G_DPD_CALI_CHANNEL_NUM_40M 3
#define MP13_2G_DPD_CALI_CHANNEL_NUM     (MP13_2G_DPD_CALI_CHANNEL_NUM_20M + MP13_2G_DPD_CALI_CHANNEL_NUM_40M)

#define MP13_DPD_CALI_TPC_LEVEL_NUM 2
#define MP13_DPD_CALI_LUT_LENGTH    31

#define MP13_DPD_OFFLINE_CALI_LUT_NUM (MP13_2G_DPD_CALI_CHANNEL_NUM * MP13_DPD_CALI_TPC_LEVEL_NUM)

#define MP13_CALI_SISO_TXDC_GAIN_LVL_NUM      8 /* SISO tx dc补偿值档位数目 */
#define MP13_CALI_MIMO_TXDC_GAIN_LVL_NUM      8 /* MIMO tx dc补偿值档位数目 */
#define MP13_CALI_TXDC_GAIN_LVL_NUM           (MP13_CALI_SISO_TXDC_GAIN_LVL_NUM +  \
                                                 MP13_CALI_MIMO_TXDC_GAIN_LVL_NUM)
#define MP13_CALI_IQ_TONE_NUM                 16
#define MP13_CALI_RXDC_GAIN_LVL_NUM           8 /* rx dc补偿值档位数目 */
#define MP13_CALI_ADC_CH_NUM                  4 /* 4路ADC */
#define MP13_CALI_2G_OTHER_CHANNEL_NUM        1
#define MP13_2G_CHANNEL_NUM                   3
#define MP13_5G_20M_CHANNEL_NUM               7
#define MP13_5G_80M_CHANNEL_NUM               7
#define MP13_5G_160M_CHANNEL_NUM              2
#define MP13_5G_CHANNEL_NUM                   (MP13_5G_20M_CHANNEL_NUM +  \
                                                 MP13_5G_80M_CHANNEL_NUM +  \
                                                 MP13_5G_160M_CHANNEL_NUM)
#define MP13_CALI_RXIQ_LS_FILTER_TAP_NUM_160M 17
#define MP13_CALI_TXIQ_LS_FILTER_TAP_NUM      15
#define MP13_CALI_RXIQ_LS_FILTER_TAP_NUM_320M (MP13_CALI_RXIQ_LS_FILTER_TAP_NUM_160M)

#define MP13_CALI_RXIQ_LS_FILTER_TAP_NUM_80M 15

#define MP13_RXIQ_LSFIR_FEQ_NUM_320M 128
#define MP13_CALI_RXIQ_LS_FILTER_FEQ_NUM_160M 64
#define MP13_CALI_RXIQ_LS_FILTER_FEQ_NUM_80M  32

#define MP13_CALI_TXIQ_LS_FILTER_FEQ_NUM_640M 256
#define MP13_CALI_TXIQ_LS_FILTER_FEQ_NUM_320M 128
#define MP13_CALI_TXIQ_LS_FILTER_FEQ_NUM_160M 64

#define NUM_80M_SNGL_TONE_1_4_CIRCLE  16 /* DAC 80M时1/4周期1.25M单音点采样点个数 */
#define NUM_160M_SNGL_TONE_1_4_CIRCLE 16 /* DAC 80M时1/4周期2.5M单音点采样点个数 */
#define NUM_320M_SNGL_TONE_1_4_CIRCLE 32 /* DAC 160M时1/4周期2.5M单音点采样点个数 */
#define NUM_640M_SNGL_TONE_1_4_CIRCLE 64 /* DAC 320M时1/4周期2.5M单音点采样点个数 */

#define NUM_80M_SNGL_TONE_1_CIRCLE 2 /* DAC 80M时1/4周期1.25M单音点采样周期，1/4周期为一个单位 */
#define NUM_BW_SNGL_TONE_1_CIRCLE 4 /* DAC 不同带宽单音点采样一个周期，1/4周期为一个单位 */

#define MP13_CALI_MATRIX_DATA_NUMS  23
#define MP16_CALI_MATRIX_DATA_NUMS  1

#define HMAC_NETBUF_OFFSET  104
/* 指示定制化bit0-bit3表示2G通道能力 */
#define WLAN_CHAIN_BAND_INDICATOR 4

typedef void (*update_chn_cali_data)(mac_vap_stru *old_up_vap, cali_data_req_stru *cali_data_req_info);

/* 3 枚举定义 */
/* 4 全局变量声明 */
/* 5 消息头定义 */
/* 6 消息定义 */
/* 7 STRUCT定义 */
typedef enum {
    MP13_CALI_SISO,
    MP13_CALI_MIMO,

    MP13_CALI_CHAIN_NUM_BUTT,
} mp13_rf_cali_chain_num_enum;

typedef struct {
    uint8_t uc_rx_gain_cmp_code; /* 仅pilot RF使用，C校准补偿值 */

    /* LODIV 暂时和rx gain复用结构 */
    uint8_t uc_rx_mimo_cmp;
    uint8_t uc_dpd_siso_cmp;
    uint8_t uc_dpd_mimo_cmp;
} mp13_rx_gain_comp_val_stru;

typedef struct {
    uint16_t aus_analog_rxdc_siso_cmp[MP13_CALI_RXDC_GAIN_LVL_NUM];
    uint16_t aus_analog_rxdc_mimo_extlna_cmp[MP13_CALI_RXDC_GAIN_LVL_NUM];
    uint16_t aus_analog_rxdc_mimo_intlna_cmp[MP13_CALI_RXDC_GAIN_LVL_NUM];
    uint16_t us_digital_rxdc_cmp_i;
    uint16_t us_digital_rxdc_cmp_q;
    int16_t s_cali_temperature;
    int16_t s_mimo_cali_temperature;
} mp13_rx_dc_comp_val_stru;

typedef struct {
    uint8_t uc_ppa_cmp;
    uint8_t uc_atx_pwr_cmp;
    uint8_t uc_dtx_pwr_cmp;
    int8_t c_dp_init;
    int16_t s_2g_tx_ppa_dc;
    int16_t s_2g_tx_power_dc;
} mp13_2g_tx_power_comp_val_stru;

typedef struct {
    uint8_t uc_ppa_cmp;
    uint8_t uc_mx_cmp;
    uint8_t uc_atx_pwr_cmp;
    uint8_t uc_dtx_pwr_cmp;
    int16_t s_5g_tx_power_dc;
    uint8_t auc_reserve[2]; // 2代表2个保留字节，需要4字节对齐
} mp13_5g_tx_power_comp_val_stru;

typedef struct {
    uint8_t uc_ssb_cmp;
    uint8_t uc_buf0_cmp;
    uint8_t uc_buf1_cmp;
    uint8_t uc_resv;
} mp13_logen_comp_val_stru;

typedef struct {
    uint8_t uc_classa_cmp;
    uint8_t uc_classb_cmp;
    uint8_t auc_reserve[2]; // 2代表2个保留字节，需要4字节对齐
} mp13_pa_ical_val_stru;

typedef struct {
    uint16_t us_txdc_cmp_i;
    uint16_t us_txdc_cmp_q;
} mp13_txdc_comp_val_stru;

typedef struct {
    uint8_t uc_ppf_val;
    uint8_t auc_reserve[3]; // 3代表3个保留字节，需要4字节对齐
} mp13_ppf_comp_val_stru;

typedef struct {
    uint16_t us_txiq_cmp_p;
    uint16_t us_txiq_cmp_e;
} mp13_txiq_comp_val_stru;

typedef struct {
    int32_t l_txiq_cmp_alpha_p;
    int32_t l_txiq_cmp_beta_p;
    int32_t l_txiq_cmp_alpha_n;
    int32_t l_txiq_cmp_beta_n;
} mp13_new_txiq_comp_val_stru;

typedef struct {
    int32_t l_txiq_cmp_alpha;
    int32_t l_txiq_cmp_beta;
    int16_t as_txiq_comp_ls_filt[MP13_CALI_TXIQ_LS_FILTER_TAP_NUM];
    uint8_t auc_resev[2]; // 2代表2个保留字节，需要4字节对齐
} mp13_new_txiq_time_comp_val_stru;

typedef struct {
    int32_t l_rxiq_cmp_alpha;
    int32_t l_rxiq_cmp_beta;
    int16_t as_rxiq_comp_ls_filt[MP13_CALI_RXIQ_LS_FILTER_TAP_NUM_160M];
    int16_t as_rxiq_bw80m_siso_comp_ls_filt[MP13_CALI_RXIQ_LS_FILTER_TAP_NUM_160M];
} mp13_new_rxiq_comp_val_stru;

typedef struct {
    /* 乘2为IQ两路数据 */
    uint8_t uc_cmp_cali[MP13_CALI_ADC_CH_NUM << BIT_OFFSET_1];
    uint32_t cap_cali_w1[MP13_CALI_ADC_CH_NUM << BIT_OFFSET_1];
    uint32_t cap_cali_w2[MP13_CALI_ADC_CH_NUM << BIT_OFFSET_1];
    uint32_t cap_cali_w3[MP13_CALI_ADC_CH_NUM << BIT_OFFSET_1];
    uint32_t cap_cali_w4[MP13_CALI_ADC_CH_NUM << BIT_OFFSET_1];
    uint32_t cap_cali_w5[MP13_CALI_ADC_CH_NUM << BIT_OFFSET_1];
    int32_t l_moec[MP13_CALI_ADC_CH_NUM << BIT_OFFSET_1];
    uint16_t us_mgec[MP13_CALI_ADC_CH_NUM << BIT_OFFSET_1];
} mp13_adc_cali_param_stru;

typedef struct {
    mp13_rx_dc_comp_val_stru st_cali_rx_dc_cmp[MP13_CALI_2G_OTHER_CHANNEL_NUM];
    mp13_rx_gain_comp_val_stru st_cali_rx_gain_cmp[MP13_CALI_2G_OTHER_CHANNEL_NUM];
    mp13_logen_comp_val_stru st_cali_logen_cmp[MP13_2G_CHANNEL_NUM];
    mp13_2g_tx_power_comp_val_stru st_cali_tx_power_cmp_2g[MP13_2G_CHANNEL_NUM];
    mp13_txdc_comp_val_stru ast_txdc_cmp_val[MP13_2G_CHANNEL_NUM][MP13_CALI_TXDC_GAIN_LVL_NUM];
#ifdef _PRE_WLAN_NEW_IQ
    mp13_new_txiq_time_comp_val_stru ast_new_txiq_time_cmp_val[MP13_2G_CHANNEL_NUM];
    mp13_new_rxiq_comp_val_stru ast_new_rxiq_cmp_val[MP13_2G_CHANNEL_NUM];
#endif
} mp13_2gcali_param_stru;

typedef struct {
    mp13_rx_dc_comp_val_stru st_cali_rx_dc_cmp[MP13_CALI_2G_OTHER_CHANNEL_NUM];
    mp13_txdc_comp_val_stru ast_txdc_cmp_val[MP13_2G_CHANNEL_NUM][MP13_CALI_TXDC_GAIN_LVL_NUM];
#ifdef _PRE_WLAN_NEW_IQ
    mp13_new_txiq_time_comp_val_stru ast_new_txiq_time_cmp_val[MP13_2G_CHANNEL_NUM];
    mp13_new_rxiq_comp_val_stru ast_new_rxiq_cmp_val[MP13_2G_CHANNEL_NUM];
#endif
} mp13_2g_dbdc_cali_param_stru;

typedef struct {
    mp13_rx_dc_comp_val_stru st_cali_rx_dc_cmp;
    mp13_rx_gain_comp_val_stru st_cali_rx_gain_cmp;
    mp13_logen_comp_val_stru st_cali_logen_cmp;
    mp13_5g_tx_power_comp_val_stru st_cali_tx_power_cmp_5g;
    mp13_ppf_comp_val_stru st_ppf_cmp_val;
    mp13_txdc_comp_val_stru ast_txdc_cmp_val[MP13_CALI_TXDC_GAIN_LVL_NUM];
#ifdef _PRE_WLAN_NEW_IQ
    mp13_new_txiq_time_comp_val_stru ast_new_txiq_time_cmp_val[MP13_CALI_CHAIN_NUM_BUTT];
    mp13_new_rxiq_comp_val_stru st_new_rxiq_cmp_val;
#endif
} mp13_5gcali_param_stru;

typedef struct {
    mp13_2gcali_param_stru st_2gcali_param[MP13_2G_CHANNEL_NUM];
    mp13_5gcali_param_stru st_5gcali_param[MP13_5G_CHANNEL_NUM];
} mp13_wifi_cali_param_stru;

typedef struct {
    uint16_t cali_time;
    uint16_t bit_temperature : 3,
               uc_5g_chan_idx1 : 5,
               uc_5g_chan_idx2 : 5,
               bit_rev : 3;
} mp13_update_cali_channel_stru;

typedef struct {
    uint8_t uc_rc_cmp_code;
    uint8_t uc_r_cmp_code;
    /* 重要: MPW2和PILOT RF公用, mpw2代表c校准值; pilot代表800M rejection补偿code，根据C code计算得到 */
    uint8_t uc_c_cmp_code;
    uint8_t uc_20m_rc_cmp_code;
} mp13_rc_r_c_cali_param_stru;

#ifdef _PRE_WLAN_ONLINE_DPD
typedef struct {
    uint32_t aul_dpd_even_lut[MP13_DPD_OFFLINE_CALI_LUT_NUM][MP13_DPD_CALI_LUT_LENGTH];
    uint32_t aul_dpd_odd_lut[MP13_DPD_OFFLINE_CALI_LUT_NUM][MP13_DPD_CALI_LUT_LENGTH];
} mp13_dpd_cali_lut_stru;
#endif

typedef struct {
    uint32_t dog_tag;
    mp13_2gcali_param_stru ast_2gcali_param;
    mp13_5gcali_param_stru ast_5gcali_param[MP13_5G_CHANNEL_NUM];
#ifdef _PRE_WLAN_ONLINE_DPD
    mp13_dpd_cali_lut_stru st_dpd_cali_data;
#endif
    mp13_ppf_comp_val_stru st_165chan_ppf_comp;
    mp13_update_cali_channel_stru st_cali_update_info;
    uint32_t check_hw_status;
    mp13_pa_ical_val_stru st_pa_ical_cmp;
    mp13_rc_r_c_cali_param_stru st_rc_r_c_cali_data;
    mp13_2g_dbdc_cali_param_stru ast_2g_dbdc_cali_param;
    int16_t s_2g_idet_gm;
    oal_bool_enum_uint8 en_use_lpf_10m_for_2grx_20m;
    oal_bool_enum_uint8 en_save_all;
    uint8_t uc_last_cali_fail_status;
    oal_bool_enum_uint8 en_need_close_fem_cali;
    uint8_t auc_resv[2]; // 2代表2个保留字节，需要4字节对齐
    mp13_adc_cali_param_stru st_adc_cali_data;
} mp13_cali_param_stru;

typedef struct {
    uint8_t uc_atx_pwr_cmp;
    uint8_t uc_dtx_pwr_cmp;
    int16_t s_2g_tx_power_dc;
} mp13_bt20dbm_txpwr_cal_stru;
typedef struct {
    int32_t l_txiq_cmp_alpha;
    int32_t l_txiq_cmp_beta;
    mp13_bt20dbm_txpwr_cal_stru st_20dbmtxpwr;
    mp13_txdc_comp_val_stru ast_txdc_cmp_val[8];  // 8代表8个档位，wifi siso tx档位
} mp13_bt20dbm_txcal_val_stru;
typedef struct {
    mp13_bt20dbm_txcal_val_stru st_bt20dbm_txcali_param[MP13_2G_CHANNEL_NUM];
} mp13_bt20dbm_txcal_param_stru;

typedef struct {
    uint16_t us_ppa_cmp;
    uint16_t us_atx_pwr_cmp;
    int16_t s_2g_tx_power_dc;
    uint8_t uc_dtx_pwr_cmp;
    uint8_t auc_rsv[1]; // 4字节对齐
} mp15_bt20dbm_txpwr_cal_stru;

typedef struct {
    int32_t l_txiq_cmp_alpha[MP15_CALI_TXIQ_GAIN_LVL_NUM];
    int32_t l_txiq_cmp_beta[MP15_CALI_TXIQ_GAIN_LVL_NUM];
    mp15_logen_comp_val_stru cali_logen_cmp;
    mp15_bt20dbm_txpwr_cal_stru st_20dbmtxpwr;
    mp15_txdc_comp_val_stru st_txdc_cmp_val;
} mp15_bt20dbm_txcal_chn_stru;

typedef struct {
    mp15_bt20dbm_txcal_chn_stru bt20dbm_txcali_chn_param[MP13_2G_CHANNEL_NUM];
    uint8_t rc_cmp_code; // 不区分频点
    uint8_t rsv[3]; // 3代表3个保留字节，需要4字节对齐
} mp15_bt20dbm_txcal_param_stru;
// end added of 20dbm cali

uint32_t hmac_save_cali_event(frw_event_mem_stru *pst_event_mem);
uint32_t hmac_send_cali_data(mac_vap_stru *mac_vap);
uint32_t hmac_send_cali_matrix_data(mac_vap_stru *mac_vap);
void hmac_get_cali_data_for_bt20dbm(void);
void hmac_get_mp15_cali_data_for_bt20dbm(void);
void hmac_set_close_fem_cali_status(oal_bool_enum_uint8 en_switch);
/* 校准区分芯片回调函数 */
uint32_t hmac_send_cali_matrix_data_mp13(mac_vap_stru *mac_vap);
uint32_t hmac_send_cali_matrix_data_mp15(mac_vap_stru *mac_vap);
uint32_t hmac_send_cali_matrix_data_mp16(mac_vap_stru *mac_vap);

uint32_t hmac_send_cali_matrix_data_mp16c(mac_vap_stru *mac_vap);
uint32_t hmac_send_cali_data_mp13(mac_vap_stru *mac_vap, wlan_h2d_cali_data_type_enum_uint8 en_type);
uint32_t hmac_send_cali_data_mp15(mac_vap_stru *mac_vap, wlan_h2d_cali_data_type_enum_uint8 en_type);

uint32_t hmac_send_cali_data_mp16(mac_vap_stru *mac_vap, h2d_cali_trans_stru *h2d_cali_trans);
uint32_t hmac_save_cali_event_mp13(frw_event_mem_stru *event_mem);
uint32_t hmac_save_cali_event_mp15(frw_event_mem_stru *event_mem);
uint32_t hmac_save_cali_event_mp16(frw_event_mem_stru *event_mem);
void hmac_set_scan_cali_data(mac_vap_stru *mac_vap);
void hmac_set_scan_dbdc_cali_data(void);
void hmac_update_cur_chn_cali_data_mp16(cali_data_req_stru *cali_data_req_info);
int32_t hmac_cali_ops_init(void);
int8_t hmac_get_wlan_first_power_on_cali_flag(void);
void hmac_set_wlan_first_powon_mark(oal_bool_enum_uint8 status);
oal_completion *hmac_get_wlan_cali_completed_addr(void);
void hmac_first_powon_cali_completed(void);
void hmac_cali_send_work_channel_cali_data(mac_vap_stru *mac_vap, mac_channel_stru *channel,
    uint8_t work_cali_data_sub_type);
wlan_bandwidth_type_enum_uint8 hmac_cali_get_wlan_bandwidth(mac_channel_stru *chn_para);
void hmac_dump_cali_result_mp16(void);
OAL_STATIC OAL_INLINE uint8_t hmac_get_rf_num(void)
{
    return g_wlan_spec_cfg->max_rf_num;
}

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* end of hmac_mgmt_classifier.h */
