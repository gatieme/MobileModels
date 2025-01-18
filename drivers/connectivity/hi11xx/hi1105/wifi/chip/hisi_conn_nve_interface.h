/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * 功能说明   : mp16产测pow\rssi\dpd校准NV接口声明
 * 作者       : wifi
 * 创建日期   : 2020年12月8日
 */
#ifndef HISI_CONN_NVE_INTERFACE_H
#define HISI_CONN_NVE_INTERFACE_H
#ifdef HISI_CONN_NVE_SUPPORT

/* 其他头文件包含 */
#include "hisi_conn_nve.h"
#include "wlan_cali.h"
#include "wlan_types.h"
#include "oam_wdk.h"
#include "wlan_oneimage_define.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HISI_CONN_NVE_INTERFACE_H

/* conn_nve分区相关定义 */
#define CONN_NVE_IMG_NUM            2
#define CONN_NVE_IMG_MASK           0x1
#define CONN_NVE_WIFIDATA_LEN       (sizeof(conn_nve_particion_stru) * CONN_NVE_IMG_NUM)
#define RSSI_CAL_2G_GAIN_LVL        7
#define RSSI_CAL_5G_GAIN_LVL        8
#define RSSI_CAL_2G_FEM_LVL         2
#define RSSI_CAL_5G_FEM_LVL         2
#define RSSI_CAL_2G_BAND_NUM        3
#define RSSI_CAL_5G_BAND_NUM        7
#define RSSI_CAL_6G_BAND_NUM        15
#define RSSI_ONE_STREAM_SIZE_2G     (sizeof(int) * RSSI_CAL_2G_BAND_NUM * RSSI_CAL_2G_GAIN_LVL * RSSI_CAL_2G_FEM_LVL)
#define RSSI_ONE_STREAM_SIZE_5G     (sizeof(int) * RSSI_CAL_5G_BAND_NUM * RSSI_CAL_5G_GAIN_LVL * RSSI_CAL_5G_FEM_LVL)
#define RSSI_ONE_STREAM_SIZE_6G     (sizeof(int) * RSSI_CAL_6G_BAND_NUM * RSSI_CAL_5G_GAIN_LVL * RSSI_CAL_5G_FEM_LVL)
#define WICAL_STREAM_NUM            4
#define WICAL_2G_RF_BAND_NUM        13
#define WICAL_POW_CAL_LVL_NUM       2
#define WICAL_POW_CAL_2G_VAR_NUM    3
#define WICAL_POW_CAL_5G_VAR_NUM    4
#define WICAL_5G_RF_BAND_NUM        7
#define WICAL_5G_RF_160M_BAND_NUM   2
#define WICAL_6G_RF_BAND_NUM        15
#define WICAL_6G_RF_160M_BAND_NUM   7
#define WICAL_DPD_LVL_NUM           WLAN_DPD_TPC_LEVEL_NUM
#define WICAL_2G_DPD_BAND_NUM       WLAN_2G_CALI_BAND_NUM
#define WICAL_5G_DPD_BAND_NUM       WLAN_5G_CALI_SUB_BAND_NUM
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
#define WICAL_6G_DPD_BAND_NUM       WLAN_6G_CALI_SUB_BAND_NUM
#endif
#define WICAL_DPD_BW_NUM            4
#define dpd_size(n)                (sizeof(wlan_cali_dpd_para_stru) * (n))
#define CONN_NVE_PREFIX            g_conn_nve_struct.conn_nve_ramdisk
#define DPD_DATA_PREFIX             g_conn_nve_struct.conn_nve_ramdisk->dpd_cal_data
#define POW_DATA_PREFIX             g_conn_nve_struct.conn_nve_ramdisk->pow_cal_data
    // DPD数据单元
#define conn_nve_dpd_unit(pre, array) \
        (&(((nv_dpd_stru)(pre)->dpd_cal_data).array[info->stream][info->band_idx].dpd_cali_para[info->dpd_lvl]))
#define conn_nve_start_addr(id) (size_t)(((unsigned int)(id) & CONN_NVE_IMG_MASK) * sizeof(conn_nve_particion_stru))
#define CONN_NVE_CLEAR_MASK 0x1F
#define CONN_NVE_CLEAR_2G_MASK 0x20
#define CONN_NVE_CLEAR_5G_MASK 0x40
#define CONN_NVE_CLEAR_6G_MASK 0x80
// fb_gain nv项信息
#define CONN_NVE_FBGAIN_NUM 363
#define CONN_NVE_FBGAIN_NAME "FBGAIN"
/* 返回值定义 */
typedef enum {
    CONN_NVE_ERROR_CRC = CONN_NVE_ERROR_BUT + 1,
    CONN_NVE_ERROR_CLEAR_ALL,
    CONN_NVE_ERROR_DO_CLEAR,
} hisi_conn_wifidata_ret_enum;

#define CRC32C_REV_SEED             0
/* 数据大小相关定义 */
#define CONN_NVE_PARTICION_SIZE     (sizeof(conn_nve_particion_stru) - 4)

typedef struct {
    int32_t delta_gain[WICAL_POW_CAL_LVL_NUM];
} wlan_cali_pow_para_stru;

typedef struct {
    wlan_cali_pow_para_stru delta_gain_2g_11b[WICAL_STREAM_NUM][WICAL_2G_RF_BAND_NUM];
    wlan_cali_pow_para_stru delta_gain_2g_ofdm_20[WICAL_STREAM_NUM][WICAL_2G_RF_BAND_NUM];
    wlan_cali_pow_para_stru delta_gain_2g_ofdm_40[WICAL_STREAM_NUM][WICAL_2G_RF_BAND_NUM];
    wlan_cali_pow_para_stru delta_gain_5g_20[WICAL_STREAM_NUM][WICAL_5G_RF_BAND_NUM];
    wlan_cali_pow_para_stru delta_gain_5g_40[WICAL_STREAM_NUM][WICAL_5G_RF_BAND_NUM];
    wlan_cali_pow_para_stru delta_gain_5g_80[WICAL_STREAM_NUM][WICAL_5G_RF_BAND_NUM];
    wlan_cali_pow_para_stru delta_gain_5g_160[WICAL_STREAM_NUM][WICAL_5G_RF_BAND_NUM];
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
    wlan_cali_pow_para_stru delta_gain_6g_20[WICAL_STREAM_NUM][WICAL_6G_RF_BAND_NUM];
    wlan_cali_pow_para_stru delta_gain_6g_40[WICAL_STREAM_NUM][WICAL_6G_RF_BAND_NUM];
    wlan_cali_pow_para_stru delta_gain_6g_80[WICAL_STREAM_NUM][WICAL_6G_RF_BAND_NUM];
    wlan_cali_pow_para_stru delta_gain_6g_160[WICAL_STREAM_NUM][WICAL_6G_RF_BAND_NUM];
#endif
} nv_pow_stru;

typedef struct {
    int32_t delta_gain_2g[WICAL_STREAM_NUM][RSSI_CAL_2G_BAND_NUM][RSSI_CAL_2G_GAIN_LVL][RSSI_CAL_2G_FEM_LVL];
    int32_t delta_gain_5g[WICAL_STREAM_NUM][RSSI_CAL_5G_BAND_NUM][RSSI_CAL_5G_GAIN_LVL][RSSI_CAL_5G_FEM_LVL];
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
    int32_t delta_gain_6g[WICAL_STREAM_NUM][RSSI_CAL_6G_BAND_NUM][RSSI_CAL_5G_GAIN_LVL][RSSI_CAL_5G_FEM_LVL];
#endif
} nv_rssi_stru;

typedef struct {
    // 2G校准数据
    wlan_cali_dpd_para_stru cali_data_2g[WICAL_STREAM_NUM][WLAN_2G_CALI_BAND_NUM];
    // 5G校准数据
    wlan_cali_dpd_para_stru cali_data_5g_20[WICAL_STREAM_NUM][WLAN_5G_20M_CALI_BAND_NUM];
    wlan_cali_dpd_para_stru cali_data_5g_80[WICAL_STREAM_NUM][WLAN_5G_20M_CALI_BAND_NUM];
    wlan_cali_dpd_para_stru cali_data_5g_160[WICAL_STREAM_NUM][WLAN_5G_160M_CALI_BAND_NUM];
    // 6G校准数据
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
    wlan_cali_dpd_para_stru cali_data_6g_20[WICAL_STREAM_NUM][WLAN_6G_20M_CALI_BAND_NUM];
    wlan_cali_dpd_para_stru cali_data_6g_80[WICAL_STREAM_NUM][WLAN_6G_20M_CALI_BAND_NUM];
    wlan_cali_dpd_para_stru cali_data_6g_160[WICAL_STREAM_NUM][WLAN_6G_160M_CALI_BAND_NUM];
#endif
} nv_dpd_stru;

typedef struct {
    int16_t fb_gain[WLAN_CALI_BAND_BUTT];
    uint32_t crc;
} nv_fbgain_stru;

typedef struct {
    nv_pow_stru pow_cal_data;
    nv_rssi_stru rssi_cal_data;
    nv_dpd_stru dpd_cal_data;
    uint32_t data_status;
    uint32_t age;
    uint32_t crc;
} conn_nve_particion_stru;
typedef struct {
    uint32_t current_id;
    conn_nve_particion_stru *conn_nve_ramdisk;
} conn_nve_ramdisk_stru;

typedef enum {
    CONN_NVE_LUT_TYPE_NORMAL = 0,
    CONN_NVE_LUT_TYPE_SIDE_PLUS = 1,
    CONN_NVE_LUT_TYPE_SIDE_MINUS = 2,
    CONN_NVE_LUT_TYPE_TB = 3,

    CONN_NVE_LUT_TYPE_BUTT,
} conn_nve_lut_type_enum;

typedef enum {
    CONN_NVE_CLEAR_POW_C0,
    CONN_NVE_CLEAR_POW_C1,
    CONN_NVE_CLEAR_POW_C2,
    CONN_NVE_CLEAR_POW_C3,
    CONN_NVE_CLEAR_POW_2G,
    CONN_NVE_CLEAR_POW_5G,
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
    CONN_NVE_CLEAR_POW_6G,
#endif
    CONN_NVE_CLEAR_POW_ALL,
    CONN_NVE_CLEAR_RSSI_C0,
    CONN_NVE_CLEAR_RSSI_C1,
    CONN_NVE_CLEAR_RSSI_C2,
    CONN_NVE_CLEAR_RSSI_C3,
    CONN_NVE_CLEAR_RSSI_2G,
    CONN_NVE_CLEAR_RSSI_5G,
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
    CONN_NVE_CLEAR_RSSI_6G,
#endif
    CONN_NVE_CLEAR_RSSI_ALL,
    CONN_NVE_CLEAR_DPD_C0,
    CONN_NVE_CLEAR_DPD_C1,
    CONN_NVE_CLEAR_DPD_C2,
    CONN_NVE_CLEAR_DPD_C3,
    CONN_NVE_CLEAR_DPD_2G,
    CONN_NVE_CLEAR_DPD_5G,
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
    CONN_NVE_CLEAR_DPD_6G,
#endif
    CONN_NVE_CLEAR_DPD_ALL,
    CONN_NVE_CLEAR_ALL,
    CONN_NVE_CLEAR_CMD_BUTT,
} conn_nve_clear_cmd_enum;

typedef enum {
    POW_CAL_BAND_2G_11B,
    POW_CAL_BAND_2G_OFDM_20,
    POW_CAL_BAND_2G_OFDM_40,
    POW_CAL_BAND_5G_20,
    POW_CAL_BAND_5G_40,
    POW_CAL_BAND_5G_80,
    POW_CAL_BAND_5G_160,
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
    POW_CAL_BAND_6G_20,
    POW_CAL_BAND_6G_40,
    POW_CAL_BAND_6G_80,
    POW_CAL_BAND_6G_160,
#endif
    POW_CAL_BAND_BUT,
} conn_nvee_pow_band_type;
typedef enum {
    CONN_STATUS_DPD,
    CONN_STATUS_POW,
    CONN_STATUS_RSSI,
    CONN_STATUS_BUTT,
} conn_nve_status_cali_type;

typedef enum {
    CONN_DATA_UNSAVED,
    CONN_DATA_SAVED,
} conn_nve_data_status_type;

typedef struct {
    uint8_t stream;
    uint8_t band_type;
    uint8_t band_idx;
    uint8_t gain_lvl;
    int32_t buf;
} nv_pow_user_info_stru;


typedef struct {
    uint8_t stream;
    uint8_t band_type;
    uint8_t band_idx;
    uint8_t gain_lvl;
    uint8_t fem_lvl;
    int32_t buf;
} nv_rssi_user_info_stru;

typedef struct {
    uint8_t stream;
    uint8_t band_type;
    uint8_t bw;
    uint8_t band_idx;
    uint8_t lut_type;
    uint8_t dpd_lvl;
    wlan_cali_dpd_lut_stru *buf;
} nv_dpd_user_info_stru;

/* 变量声明 */
/* 函数声明 */
/* conn_nve 分区函数接口 */
int32_t conn_nve_write_powcal_data(const nv_pow_stru *buf);
int32_t conn_nve_read_powcal_data(nv_pow_stru *buf);
int32_t conn_nve_write_powcal_data_pro(const nv_pow_user_info_stru *info);
int32_t conn_nve_write_dpd_data(const nv_dpd_user_info_stru *info);
int32_t conn_nve_read_dpd_data(const nv_dpd_user_info_stru *info);
int32_t conn_nve_write_rssi_data(const nv_rssi_user_info_stru *info);
int32_t conn_nve_read_rssi_data(nv_rssi_user_info_stru *info);
int32_t conn_nve_clear_by_cmd(uint8_t cmd);
int32_t conn_nve_init_wifi_nvdata(void);
int32_t conn_nve_fetch_wifi_nvdata(conn_nve_particion_stru *buf);
int32_t conn_nve_set_data_status(uint8_t type, uint32_t status);
uint32_t conn_nve_get_data_status(uint8_t type);
int32_t conn_nve_write_fbgain(int16_t *data);
int32_t conn_nve_read_fbgain(int16_t *data);
#endif
#endif
