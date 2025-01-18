/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * Description: CHBA 2.0 sync header file
 * Author: wifi
 * Create: 2021-02-06
 */

#ifndef HMAC_CHBA_SYNC_H
#define HMAC_CHBA_SYNC_H

#include "hmac_chba_common_function.h"
#include "hmac_chba_mgmt.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_CHBA_SYNC_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _PRE_WLAN_CHBA_MGMT
/* 1 宏定义 */
#define MAC_CHBA_OUT_OF_SYNC_CNT 6
#define MAC_CHBA_MAX_LOSE_PNF_CNT 3
#define MAC_CHBA_BROADCAST_BEACON_CNT 4 /* 连续N个slot在当前信道发送beacon帧 */

#define WIFI_MAC_CHBA_SYNC_WAITING_TIMEOUT 256 /* 一次主动同步的等待时间: 256ms */
#define MAC_MERGE_REQ_MAX_CNT 4 /* 强制域合并时，发送merge req的最大次数 */
#define MAC_MERGE_REQ_MAX_SLOT_CNT 3 /* 发送域合并帧时的超时slot个数，16ms*3 */

/* 2 枚举定义 */
/* Master选举状态枚举 */
typedef enum {
    MASTER_ALIVE = 1,
    MASTER_LOST = 2,
} chba_master_election_enum;

/* 3 结构体定义 */
/* 同步相关的flag */
typedef struct {
    uint8_t sync_request_flag; /* 启动主动同步流程后将该flag置为1 */
    uint8_t master_update_flag; /* master更新开始时设置为1，master更新结束时设置为0 */
    uint8_t sync_with_new_master_flag; /* 请求同步或者master更新后，是否与新master同步上的标记 */
} sync_info_flags;

/* 请求同步的List */
typedef struct {
    uint8_t next_request_idx; /* 指向下一个未询问的设备idx */
    uint8_t end_idx; /* 指向List中保存的最后一个设备idx */
    uint8_t island_peer_flag; /* 如果添加的是岛内节点，则该标志位置1，且填写下面的islandMacAddr */
    uint8_t sync_save_flag; /* 同步失败时补救标记, false表示未做过补救, true表示已经做过补救 */
    uint8_t island_master_addr[OAL_MAC_ADDR_LEN];
    sync_peer_info request_list[MAC_CHBA_REQUEST_LIST_NUM];
} sync_request;

/* 域合并处理结构体 */
typedef struct {
    uint8_t domain_merge_flag; /* 域合并开始时设置为1，域合并结束时设置为0 */
    uint8_t domain_merge_sync_flag; /* domain merge，是否与新master同步上的标记 */
    uint8_t his_role;
    uint8_t ask_for_sync_mgmt_type; /* 请求同步管理帧帧类型, sync request帧或domain merge response帧 */
    uint8_t ask_for_sync_cnt; /* 域合并流程请求同步发送的次数 */
    uint8_t domain_merge_notify_mgmt_type; /* 通知自身岛内其他设备域合并管理帧类型, beacon帧或domain merge requset帧 */
    uint8_t domain_merge_notify_cnt; /* 通知自身岛内其他设备域合并管理帧帧发送次数 */
    uint8_t peer_addr[OAL_MAC_ADDR_LEN]; /* 发现的其他域设备地址 */
    uint8_t his_bssid[OAL_MAC_ADDR_LEN]; /* 历史域bssid */
} hmac_chba_domain_merge_info;

/* 同步请求信息结构体 */
typedef struct {
    uint8_t request_cnt; /* 用户态下发的每个请求，发送三次sync request action帧 */
    uint8_t peer_addr[WLAN_MAC_ADDR_LEN];
    uint8_t sync_req_buf[MAC_CHBA_MGMT_SHORT_PAYLOAD_BYTES]; /* 保存sync req帧 */
    uint16_t sync_req_buf_len;
} request_sync_info_stru;

/* 同步信息结构体 */
typedef struct {
    uint8_t sync_state; /* 同步状态(chba_vap_state_enum) */

    uint8_t domain_bssid[OAL_MAC_ADDR_LEN]; /* 当前的域BSSID */
    uint8_t try_bssid[OAL_MAC_ADDR_LEN]; /* 失同步时，试图尝试同步的域BSSID */

    sync_info_flags sync_flags;
    sync_request sync_req_ctrl;
    request_sync_info_stru request_sync_info;
    hmac_chba_domain_merge_info domain_merge_info; /* 管理域合并 */

    ranking_priority own_rp_info; /* 本设备的RP值 */
    master_info cur_master_info; /* 当前Master相关信息 */
    master_info his_master_info; /* Master变更时，前一个Master的信息 */
    master_info max_rp_device; /* 主设备选举过程中，保存当前RP值最大的设备信息 */

    frw_timeout_stru sync_waiting_timer; /* 请求同步，等待超时的定时器 */
    frw_timeout_stru sync_request_timer; /* 发送一次sync request帧后等待回复的定时器 */
    frw_timeout_stru domain_merge_sync_waiting_timer; /* 域合并，请求与新域时钟同步后等待同步完成的定时器 */
    uint32_t start_sync_tsf;
} hmac_chba_sync_info;

/* 4 全局变量声明 */
extern hmac_chba_sync_info g_chba_sync_info;

static inline hmac_chba_sync_info *hmac_chba_get_sync_info(void)
{
    return &g_chba_sync_info;
}
static inline uint8_t *hmac_chba_sync_get_domain_bssid(void)
{
    return g_chba_sync_info.domain_bssid;
}
static inline sync_info_flags *hmac_chba_get_sync_flags(void)
{
    return &g_chba_sync_info.sync_flags;
}
static inline sync_request *hmac_chba_get_sync_req_ctrl(void)
{
    return &g_chba_sync_info.sync_req_ctrl;
}
static inline sync_peer_info *hmac_chba_get_sync_req_list(void)
{
    return g_chba_sync_info.sync_req_ctrl.request_list;
}

static inline hmac_chba_domain_merge_info *hmac_chba_get_domain_merge_info(void)
{
    return &g_chba_sync_info.domain_merge_info;
}
static inline uint8_t *hmac_chba_get_master_mac_addr(void)
{
    return g_chba_sync_info.cur_master_info.master_addr;
}
static inline void hmac_chba_sync_set_rp_dev_type(uint8_t val)
{
    g_chba_sync_info.own_rp_info.device_level.dl.device_type = val;
}
static inline void hmac_chba_sync_set_rp_capability(uint8_t val)
{
    g_chba_sync_info.own_rp_info.device_level.dl.hardware_capability = val;
}
static inline void hmac_chba_sync_set_rp_power(uint8_t val)
{
    g_chba_sync_info.own_rp_info.device_level.dl.remain_power = val;
}
static inline void hmac_chba_sync_set_rp_version(uint8_t val)
{
    g_chba_sync_info.own_rp_info.chba_version = val;
}
static inline void hmac_chba_sync_set_rp_link_cnt(uint16_t val)
{
    g_chba_sync_info.own_rp_info.link_cnt = val;
}
static inline uint8_t hmac_chba_get_sync_state(void)
{
    return g_chba_sync_info.sync_state;
}
static inline void hmac_chba_set_sync_state(uint8_t val)
{
    g_chba_sync_info.sync_state = val;
}
static inline uint8_t hmac_chba_get_sync_save_flag(void)
{
    return g_chba_sync_info.sync_req_ctrl.sync_save_flag;
}
static inline void hmac_chba_set_sync_save_flag(uint8_t sync_save_flag)
{
    g_chba_sync_info.sync_req_ctrl.sync_save_flag = sync_save_flag;
}
/* 5 函数声明 */
void hmac_chba_sync_module_init(hmac_chba_device_para_stru *device_info);
void hmac_chba_sync_module_deinit(void);
void hmac_chba_vap_start_sync_proc(mac_chba_vap_start_rpt *info_report);
void hmac_chba_multiple_domain_detection_after_asoc(uint8_t *sa_addr, chba_req_sync_after_assoc_stru *req_sync);
void hmac_chba_domain_merge_start_handler(master_info *another_master, uint8_t *peer_addr, uint8_t mgmt_type);
void hmac_chba_domain_merge_recovery_handler(void);
void hmac_chba_rx_bcn_non_sync_state_handler(hmac_vap_stru *hmac_vap, uint8_t *sa_addr, uint8_t *domain_bssid,
    uint8_t *payload, uint16_t payload_len);
void hmac_chba_rx_bcn_sync_handler(hmac_vap_stru *hmac_vap, uint8_t *sa_addr, uint8_t *domain_bssid, uint8_t *payload,
    uint16_t payload_len);
void hmac_chba_update_island_sync_info(void);
void hmac_chba_clear_sync_info(hmac_chba_sync_info *sync_info);
uint8_t hmac_chba_sync_dev_rp_compare(master_info *device_rp1, master_info *device_rp2);
int32_t hmac_chba_sync_become_master_handler(hmac_chba_sync_info *sync_info, uint8_t rrm_list_flag);
void hmac_chba_non_sync_detect(hmac_vap_stru *hmac_vap);
uint32_t hmac_chba_sync_multiple_domain_info(mac_vap_stru *mac_vap, uint8_t len, uint8_t *param);
uint8_t hmac_chba_get_sync_request_flag(sync_info_flags *sync_flags);
void hmac_chba_set_sync_request_flag(sync_info_flags *sync_flags, uint8_t new_flag);
void hmac_chba_set_sync_domain_merge_flag(hmac_chba_domain_merge_info *domain_merge, uint8_t new_flag);
uint8_t hmac_chba_get_domain_merge_flag(hmac_chba_domain_merge_info *domain_merge);
void hmac_chba_sync_update_own_rp(hmac_vap_stru *hmac_vap);
void hmac_chba_sync_master_election_proc(hmac_vap_stru *hmac_vap, hmac_chba_sync_info *sync_info, uint8_t process_type);
int32_t hmac_chba_start_sync_request(hmac_chba_sync_info *sync_info);
uint32_t hmac_chba_domain_merge_send_notify_immediately(mac_vap_stru *mac_vap, uint8_t len, uint8_t *param);
#endif

#ifdef __cplusplus
}
#endif

#endif

