/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * 功能说明 : hmac_user.c 的头文件
 * 作    者 :
 * 创建日期 : 2012年10月19日
 */

#ifndef HMAC_USER_H
#define HMAC_USER_H

#include "mac_user.h"
#include "mac_resource.h"
#include "mac_common.h"
#include "hmac_ext_if.h"
#include "hmac_btcoex.h"
#include "hmac_tid.h"
#include "hmac_stat_stru.h"
#ifdef _PRE_WLAN_CHBA_MGMT
#include "mac_chba_common.h"
#endif
#include "wlan_oneimage_define.h"
#ifdef _PRE_WLAN_FEATURE_PWL
#include "hd_pwl_common.h"
#endif
#if (defined(_PRE_WLAN_FEATURE_WAPI) || defined(_PRE_WLAN_FEATURE_PWL))
#include "hmac_wpi.h"
#endif
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_USER_H

#define HMAC_ADDBA_EXCHANGE_ATTEMPTS 10 /* 试图建立ADDBA会话的最大允许次数 */

#define MAX_JUDGE_CACHE_LENGTH 20 /* 业务识别-用户待识别队列长度 */
#define MAX_CONFIRMED_FLOW_NUM 2  /* 业务识别-用户已识别业务总数 */
#define MAX_CLEAR_JUDGE_TH     2  /* 业务识别-用户未识别业务导致清空重新识别的次数门限 */
#define CHBA_THROUGHPUT_WINDOW_LEN 5 /* CHBA流量窗口大小，保存最近5次的trx总流量数据 */
#define HMAC_USER_STATS_PKT_INCR(_member, _cnt) ((_member) += (_cnt))

#ifdef _PRE_WLAN_FEATURE_HIEX
#define HMAC_HIEX_MAX_SII_SIZE             8
#define HMAC_HIEX_SII_AGING_INTERVAL_MS    5000
#define HMAC_HIEX_SII_AGING_MS             60000
#endif

typedef enum {
    WLAN_TX_TCP_DATA = 0, /* 发送TCP data */
    WLAN_RX_TCP_DATA = 1, /* 接收TCP data */
    WLAN_TX_UDP_DATA = 2, /* 发送UDP data */
    WLAN_RX_UDP_DATA = 3, /* 接收UDP data */

    WLAN_TXRX_DATA_BUTT = 4,
} wlan_txrx_data_type_enum;

typedef struct {
    void *pst_ba;
    uint8_t uc_tid;
    mac_delba_initiator_enum_uint8 en_direction;
    uint16_t us_mac_user_idx;
    uint8_t uc_vap_id;
    uint16_t us_timeout_times;
    uint8_t uc_resv[1];
} dmac_ba_alarm_stru;

#ifdef _PRE_WLAN_FEATURE_HIEX
/* stream info item */
typedef struct {
    uint32_t  server_ip;    /* all net endian */
    uint32_t  client_ip;
    uint16_t  server_port;
    uint16_t  client_port;
    uint32_t  mark;         /* used for game/voice... */
    uint32_t  last_active;
} hmac_hiex_sii_stru;

/* stream info table */
typedef struct {
    oal_spin_lock_stru  lock;
    uint32_t          count;
    hmac_hiex_sii_stru  item[HMAC_HIEX_MAX_SII_SIZE];
    frw_timeout_stru    aging_timer;
} hmac_hiex_sit_stru;
#endif

/* TID对应的发送BA会话的状态 */
typedef struct {
    frw_timeout_stru st_addba_timer;
    dmac_ba_alarm_stru st_alarm_data;

    dmac_ba_conn_status_enum_uint8 en_ba_status; /* 该TID对应的BA会话的状态 */
    uint8_t uc_addba_attemps;                  /* 启动建立BA会话的次数 */
    uint8_t uc_dialog_token;                   /* 随机标记数 */
    oal_bool_enum_uint8 uc_ba_policy;            /* Immediate=1 Delayed=0 */
    oal_spin_lock_stru st_ba_status_lock;        /* 该TID对应的BA会话的状态锁 */
} hmac_ba_tx_stru;

typedef struct {
    oal_bool_enum_uint8 in_use;          /* 缓存BUF是否被使用 */
    uint8_t uc_num_buf;                /* MPDU占用的netbuf(接收描述符)个数 */
    uint16_t us_seq_num;               /* MPDU对应的序列号 */
    oal_netbuf_head_stru st_netbuf_head; /* MPDU对应的描述符首地址 */
    uint32_t rx_time;               /* 报文被缓存的时间戳 */
} hmac_rx_buf_stru;

typedef struct {
    void *pst_ba;
    uint8_t uc_tid;
    mac_delba_initiator_enum_uint8 en_direction;
    uint8_t uc_resv[1];
    uint8_t uc_vap_id;
    uint16_t us_mac_user_idx;
    uint16_t us_timeout_times;
} hmac_ba_alarm_stru;

/* Hmac侧接收侧BA会话句柄 */
typedef struct {
    uint16_t us_baw_start;       /* 第一个未收到的MPDU的序列号 */
    uint16_t us_baw_end;         /* 最后一个可以接收的MPDU的序列号 */
    uint16_t us_baw_tail;        /* 目前Re-Order队列中，最大的序列号 */
    uint16_t us_baw_size;        /* Block_Ack会话的buffer size大小 */
    uint16_t us_last_relseq;     /* 目前Re-Order队列中，上一次release seqnum */
    oal_atomic ref_cnt;
    oal_spin_lock_stru st_ba_lock; /* 用于hcc线程和事件线程并发 */

    oal_bool_enum_uint8 en_timer_triggered;      /* 上一次上报是否为定时器上报 */
    oal_bool_enum_uint8 en_is_ba;                /* Session Valid Flag */
    dmac_ba_conn_status_enum_uint8 en_ba_status; /* 该TID对应的BA会话的状态 */
    uint16_t uc_mpdu_cnt;                      /* 当前Re-Order队列中，MPDU的数目 td */

    hmac_ba_alarm_stru st_alarm_data;
    /* 以下action帧相关 */
    mac_back_variant_enum_uint8 en_back_var; /* BA会话的变体 */
    uint8_t uc_dialog_token;               /* ADDBA交互帧的dialog token */
    uint8_t uc_ba_policy;                  /* Immediate=1 Delayed=0 */
    uint8_t uc_lut_index;                  /* 接收端Session H/w LUT Index */
    uint16_t us_status_code;               /* 返回状态码 */
    uint16_t us_ba_timeout;                /* BA会话交互超时时间 */
    uint8_t *puc_transmit_addr;            /* BA会话发送端地址 */
    oal_bool_enum_uint8 en_amsdu_supp;       /* BLOCK ACK支持AMSDU的标识 */
    uint8_t auc_resv1[1];
    uint16_t us_baw_head;                  /* bitmap的起始序列号 */
    uint32_t aul_rx_buf_bitmap[2];         /* rx buffer bitmap 2:共64位 */
    /* Re-Order队列 */
    hmac_rx_buf_stru ast_re_order_list[WLAN_AMPDU_RX_HE_BUFFER_SIZE];
} hmac_ba_rx_stru;

static inline hmac_rx_buf_stru *hmac_get_ba_rx_dhl(hmac_ba_rx_stru *ba_rx_hdl, uint16_t idx)
{
    return &(((hmac_ba_rx_stru *)(ba_rx_hdl))->ast_re_order_list[idx]);
}
/* user结构中，TID对应的BA信息的保存结构 */
typedef struct {
    uint8_t uc_tid_no;
    oal_bool_enum_uint8 en_ampdu_start; /* 标识该tid下的AMPDU是否已经被设置 */
    uint16_t us_hmac_user_idx;
    hmac_ba_tx_stru st_ba_tx_info;
    hmac_ba_rx_stru *pst_ba_rx_info;            /* 由于部分处理上移，这部分内存到LocalMem中申请 */
    frw_timeout_stru st_ba_timer;               /* 接收重排序缓冲超时 */
    oal_spin_lock_stru st_ba_timer_lock;        /* 用于hcc线程和事件线程并发 */
    oal_bool_enum_uint8 en_ba_handle_tx_enable; /* 该tid下发送方向是否允许建BA，配置命令需求 */
    oal_bool_enum_uint8 en_ba_handle_rx_enable; /* 该tid下接送方向是否允许建BA，配置命令需求 */
    uint8_t auc_resv[NUM_2_BYTES];
} hmac_tid_stru;
typedef struct {
    uint32_t bit_short_preamble : 1,          /* 是否支持802.11b短前导码 0=不支持， 1=支持 */
               bit_erp : 1,                     /* AP保存STA能力使用,指示user是否有ERP能力， 0=不支持，1=支持 */
               bit_short_slot_time : 1,         /* 短时隙: 0=不支持, 1=支持 */
               bit_11ac2g : 1,
               bit_owe : 1,
               bit_resv : 27;
} hmac_user_cap_info_stru;
typedef struct {
    uint8_t uc_rs_nrates;                           /* 个数 */
    uint8_t auc_rs_rates[WLAN_USER_MAX_SUPP_RATES]; /* 速率 */
} hmac_rate_stru;

#ifdef _PRE_WLAN_FEATURE_WAPI
#define WAPI_KEY_LEN        16
#define WAPI_PN_LEN         16
#define HMAC_WAPI_MAX_KEYID 2

typedef struct {
    uint32_t ulrx_mic_calc_fail;   /* 由于参数错误导致mic计算错误 */
    uint32_t ultx_ucast_drop;      /* 由于协议没有完成，将帧drop掉 */
    uint32_t ultx_wai;
    uint32_t ultx_port_valid;      /* 协商完成的情况下，发送的帧个数 */
    uint32_t ulrx_port_valid;      /* 协商完成的情况下，接收的帧个数 */
    uint32_t ulrx_idx_err;         /* 接收idx错误错误 */
    uint32_t ulrx_netbuff_len_err; /* 接收netbuff长度错误 */
    uint32_t ulrx_idx_update_err;  /* 密钥更新错误 */
    uint32_t ulrx_key_en_err;      /* 密钥没有使能 */
    uint32_t ulrx_pn_odd_err;      /* PN奇偶校验出错 */
    uint32_t ulrx_pn_replay_err;   /* PN重放 */
    uint32_t ulrx_memalloc_err;    /* rx内存申请失败 */
    uint32_t ulrx_decrypt_ok;      /* 解密成功的次数 */

    uint32_t ultx_memalloc_err;    /* 内存分配失败 */
    uint32_t ultx_mic_calc_fail;   /* 由于参数错误导致mic计算错误 */
    // uint32_t ultx_drop_wai;     /* wai帧drop的次数 */
    uint32_t ultx_encrypt_ok;      /* 加密成功的次数 */
    uint8_t aucrx_pn[WAPI_PN_LEN]; /* 问题发生时，记录接收方向帧的PN,此pn会随时被刷新 */
} hmac_wapi_debug;

typedef struct {
    uint8_t auc_wpi_ek[WAPI_KEY_LEN];
    uint8_t auc_wpi_ck[WAPI_KEY_LEN];
    uint8_t auc_pn_rx[WAPI_PN_LEN];
    uint8_t auc_pn_tx[WAPI_PN_LEN];
    uint8_t uc_key_en;
    uint8_t auc_rsv[NUM_3_BYTES];
} hmac_wapi_key_stru;

typedef struct tag_hmac_wapi_stru {
    uint8_t uc_port_valid;    /* wapi控制端口 */
    uint8_t uc_keyidx;
    uint8_t uc_keyupdate_flg; /* key更新标志 */
    uint8_t uc_pn_inc;        /* pn步进值 */

    hmac_wapi_key_stru ast_wapi_key[HMAC_WAPI_MAX_KEYID]; /* keyed: 0~1 */

#ifdef _PRE_WAPI_DEBUG
    hmac_wapi_debug st_debug; /* 维侧 */
#endif

    uint8_t (*wapi_filter_frame)(struct tag_hmac_wapi_stru *pst_wapi, oal_netbuf_stru *pst_netbuff);
    uint32_t (*wapi_decrypt)(struct tag_hmac_wapi_stru *pst_wapi, oal_netbuf_stru *pst_netbuff);
    uint32_t (*wapi_encrypt)(struct tag_hmac_wapi_stru *pst_wapi, oal_netbuf_stru *pst_netbuf);
    oal_netbuf_stru *(*wapi_netbuff_txhandle)(struct tag_hmac_wapi_stru *pst_wapi, oal_netbuf_stru *pst_netbuf);
    oal_netbuf_stru *(*wapi_netbuff_rxhandle)(struct tag_hmac_wapi_stru *pst_wapi, oal_netbuf_stru *pst_netbuf);
} hmac_wapi_stru;

#endif

/* 业务识别-五元组结构体: 用于唯一地标识业务流 */
typedef struct {
    uint32_t sip; /* ip */
    uint32_t dip;

    uint16_t us_sport; /* 端口 */
    uint16_t us_dport;

    uint32_t proto; /* 协议 */
} hmac_tx_flow_info_stru;

/* 业务识别-待识别队列结构体: */
typedef struct {
    hmac_tx_flow_info_stru st_flow_info;

    uint32_t len;          /* 来包长度 */
    uint8_t uc_flag;          /* 有效位，用于计数 */

    uint8_t uc_udp_flag;      /* udp flag为1即为UDP帧 */
    uint8_t uc_tcp_flag;      /* tcp flag为1即为TCP帧 */

    uint8_t uc_rtpver;        /* RTP version */
    uint32_t rtpssrc;      /* RTP SSRC */
    uint32_t payload_type; /* RTP:标记1bit不计入，仅记录有效载荷类型(PT)7bit */
} hmac_tx_judge_info_stru;

/* 业务识别-待识别队列主要业务结构体: */
typedef struct {
    hmac_tx_flow_info_stru st_flow_info;

    uint32_t average_len;  /* 业务来包平均长度 */
    uint8_t uc_flag;          /* 有效位 */

    uint8_t uc_udp_flag;      /* udp flag为1即为UDP帧 */
    uint8_t uc_tcp_flag;      /* tcp flag为1即为TCP帧 */

    uint8_t uc_rtpver;        /* RTP version */
    uint32_t rtpssrc;      /* RTP SSRC */
    uint32_t payload_type; /* 标记1bit不计入，仅记录有效载荷类型(PT)7bit */

    uint32_t wait_check_num; /* 待检测列表中此业务包个数 */
} hmac_tx_major_flow_stru;

/* 业务识别-用户已识别结构体: */
typedef struct {
    hmac_tx_flow_info_stru st_cfm_flow_info; /* 已识别业务的五元组信息 */

    unsigned long last_jiffies;               /* 记录已识别业务的最新来包时间 */
    uint16_t us_cfm_tid;                   /* 已识别业务tid */

    uint16_t us_cfm_flag;                  /* 有效位 */
} hmac_tx_cfm_flow_stru;

/* 业务识别-用户待识别业务队列: */
typedef struct {
    unsigned long jiffies_st;                                         /* 记录待识别业务队列的起始时间与最新来包时间 */
    unsigned long jiffies_end;
    uint32_t to_judge_num;                                      /* 用户待识别业务队列长度 */
    hmac_tx_judge_info_stru ast_judge_cache[MAX_JUDGE_CACHE_LENGTH]; /* 待识别流队列 */
} hmac_tx_judge_list_stru;

#ifdef _PRE_WLAN_FEATURE_11V_ENABLE
/* 超过3个信道，只扫描一次，否则指定信道扫描两次+全信道一次 */
#define MAC_11V_ROAM_SCAN_ONE_TIME_CHANNEL_NUM  3
#define MAC_11V_ROAM_SCAN_ONE_CHANNEL_LIMIT  2
#define MAC_11V_ROAM_SCAN_FULL_CHANNEL_LIMIT (MAC_11V_ROAM_SCAN_ONE_CHANNEL_LIMIT + 1)

typedef uint32_t (*mac_user_callback_func_11v)(void *, void *, void *);
/* 11v 控制信息结构体 */
typedef struct {
    uint8_t uc_user_bsst_token;                   /* 用户发送bss transition 帧的信令 */
    uint8_t uc_user_status;                       /* 用户11V状态 */
    uint8_t uc_11v_roam_scan_times;               /* 单信道11v漫游扫描次数  */
    oal_bool_enum_uint8 en_only_scan_one_time;      /* 只扫描一次标志位 */
    frw_timeout_stru st_status_wait_timer;          /* 等待用户回应帧的计时器 */
    mac_scan_req_h2d_stru st_scan_h2d_params;       /* 解析邻居列表获取扫描信道列表 */
    mac_user_callback_func_11v mac_11v_callback_fn; /* 回调函数指针 */
} hmac_user_11v_ctrl_stru;
#endif

/* user结构中，本地pn号对应的保存结构 */
typedef struct {
    uint16_t ucast_qos_last_msb_pn[WLAN_TID_MAX_NUM];
    uint32_t ucast_qos_last_lsb_pn[WLAN_TID_MAX_NUM];
    uint8_t  resv[NUM_2_BYTES];
    uint16_t mcast_qos_last_msb_pn[WLAN_TID_MAX_NUM];
    uint32_t mcast_qos_last_lsb_pn[WLAN_TID_MAX_NUM];
    uint8_t  resv1[NUM_2_BYTES];
    uint16_t mcast_nonqos_last_msb_pn;
    uint32_t mcast_nonqos_last_lsb_pn;
    uint8_t  resv2[NUM_2_BYTES];
    uint16_t ucast_nonqos_last_msb_pn;
    uint32_t ucast_nonqos_last_lsb_pn;
} hmac_last_pn_stru;

/* 供AP查看STA是否被统计到对应项 */
typedef struct {
    /* 指示user是否被统计到no short slot num中, 0表示未被统计， 1表示已被统计 */
    uint8_t bit_no_short_slot_stats_flag : 1;
    uint8_t bit_no_short_preamble_stats_flag : 1; /* 指示user是否被统计到no short preamble num中 */
    uint8_t bit_no_erp_stats_flag : 1;            /* 指示user是否被统计到no erp num中 */
    uint8_t bit_no_ht_stats_flag : 1;             /* 指示user是否被统计到no ht num中 */
    uint8_t bit_no_gf_stats_flag : 1;             /* 指示user是否被统计到no gf num中 */
    uint8_t bit_20m_only_stats_flag : 1;          /* 指示user是否被统计到no 20M only num中 */
    uint8_t bit_no_40dsss_stats_flag : 1;         /* 指示user是否被统计到no 40dsss num中 */
    uint8_t bit_no_lsig_txop_stats_flag : 1;      /* 指示user是否被统计到no lsig txop num中 */

    uint8_t auc_resv0[NUM_3_BYTES];
} hmac_user_stats_flag_stru;

/* user结构体，对SA Query流程信息的保存结构 */
typedef struct {
    uint32_t sa_query_count;        /* number of pending SA Query requests, 0 = no SA Query in progress */
    uint32_t sa_query_start_time;   /* sa_query 流程开始时间,单位ms */
    uint16_t us_sa_query_trans_id;     /* trans id */
    oal_bool_enum_uint8 en_is_protected; /* 加密标志 */
    uint8_t rx_sa_req;
    uint32_t peer_sta_keep_silent_time;
    frw_timeout_stru st_sa_query_interval_timer; /* SA Query 间隔定时器，相关dot11AssociationSAQueryRetryTimeout */
} hmac_sa_query_stru;

#ifdef _PRE_WLAN_CHBA_MGMT
typedef struct {
    uint8_t connect_role; /* 建链角色(chba_connect_role_enum),关联完成配置为CHBA_CONN_ROLE_BUTT */
    uint8_t auth_cnt; /* 记录auth的次数 */
    uint8_t assoc_cnt; /* 记录assoc的次数 */
    uint8_t max_assoc_cnt; /* assoc次数超过该门限，则上报建链失败 */
    mac_status_code_enum_uint16 status_code; /* 反馈给上层的建链结果码 */
    oal_bool_enum_uint8 is_fast_conn_initiate; /* 标记是否是快速连接发起方 */
    uint32_t assoc_waiting_time; /* 该时间内未接收到assoc response则try again，单位ms */
    mac_channel_stru assoc_channel; /* 建链信道 */
    frw_timeout_stru assoc_waiting_timer;
} chba_connect_status_stru;

typedef struct {
    uint64_t last_tx_bytes;
    uint64_t last_rx_bytes;
    uint64_t rx_bytes_windows[CHBA_THROUGHPUT_WINDOW_LEN];
    uint64_t tx_bytes_windows[CHBA_THROUGHPUT_WINDOW_LEN];
    uint8_t peer_cnt;
    uint8_t trx_windows_cnt; /* 流量窗口中保存的有吞吐的周期计数 */
    uint8_t high_trx_windows_cnt; /* 流量窗口中保存的有高吞吐的周期计数 */
    uint8_t resv;
} hmac_chba_user_throughput_stru; /* 低功耗模块: 用户吞吐统计信息 */

typedef struct {
    uint16_t power_down_count;
    uint16_t power_up_count;
    uint8_t chba_link_state; /* CHBA用户关联状态(chba_user_state_enum) */
    uint8_t user_bitmap_level; /* 该链路对应的bitmap(chba_bitmap_level_enum) */
    chba_connect_status_stru connect_info; /* 用于该链路协商创建 */
    mac_channel_stru link_channel; /* 记录该链路的工作信道 */
    uint8_t scene_type;
    uint8_t ssid[WLAN_SSID_MAX_LEN]; /* CHBA关联ssid信息 */
    uint8_t ssid_len;
    chba_req_sync_after_assoc_stru req_sync; /* 用于建链后发起的同步请求 */
    hmac_chba_user_throughput_stru throughput_info; /* 用户吞吐统计 */
    uint32_t add_user_tsf;
} hmac_chba_user_stru;
#endif

typedef struct {
    uint32_t pmf_rx_deauth_cnt;
    uint32_t pmf_rx_asoc_cnt;
    uint32_t pmf_rx_disasoc_cnt;
    uint32_t ap_rx_auth_start_tsf;
    uint16_t ap_rx_auth_type;
    uint16_t ap_rx_auth_seq;
    uint32_t ap_rx_auth_cnt;
} hmac_user_attack_mgmt_stru;

typedef struct {
    uint32_t ap_reject_auth_start_tsf; /* 记录本轮检测周期开始的时间 */
    uint32_t ap_reject_auth_cnt;       /* 记录本轮检测周期reject auth发送的个数 */
    uint32_t ap_pre_reject_auth_tsf;    /* 记录上一次发送reject auth的时间 */
} hmac_non_assoc_user_attack_mgmt_stru;

#define SUPPORTED_CHANNEL_NUM_MAX_CNT 8
typedef struct {
    uint8_t num;
    struct supported_channel supported_channels[SUPPORTED_CHANNEL_NUM_MAX_CNT];
} supproted_channel_stru;


/* 声明该结构体变量后请一定要调用oal_memzero */
typedef struct hmac_user_tag {
    /* 当前VAP工作在AP或STA模式，以下字段为user是STA或AP时公共字段，新添加字段请注意!!! */
    uint8_t uc_is_wds;                              /* 是否是wds用户 */
    uint8_t uc_amsdu_supported;                     /* 每个位代表某个TID是否支持AMSDU */
    uint16_t amsdu_maxsize;                      /* amsdu最大长度 */
    hmac_amsdu_stru ast_hmac_amsdu[WLAN_TID_MAX_NUM]; /* asmdu数组 */
    hmac_tid_stru ast_tid_info[WLAN_TID_MAX_NUM];     /* 保存与TID相关的信息 */
    uint8_t auc_ch_text[WLAN_CHTXT_SIZE];           /* WEP用的挑战明文 */
    frw_timeout_stru st_mgmt_timer;                   /* 认证关联用定时器 */
    frw_timeout_stru st_defrag_timer;                 /* 去分片超时定时器 */
    oal_netbuf_stru *pst_defrag_netbuf;
    oal_netbuf_head_stru  device_rx_list[WLAN_TID_MAX_NUM];
#ifdef _PRE_WLAN_FEATURE_PMF
    hmac_sa_query_stru st_sa_query_info; /* sa query流程的控制信息 */
#endif
    /* user可选速率,记录对端assoc req或者assoc rsp帧中supported rates和assoc rsp宣称的速率 */
    hmac_rate_stru st_op_rates;
    hmac_user_cap_info_stru st_hmac_cap_info; /* hmac侧用户能力标志位 */
    uint32_t rssi_last_timestamp;        /* 获取user rssi所用时间戳, 1s最多更新一次rssi */
    oal_bool_enum_uint8 user_hisi;       /* 标识对端是否为hisi mp13/mp15芯片 */
    uint8_t resv[3];
    oal_atomic netdev_tx_suspend;

    /* 当前VAP工作在AP模式，以下字段为user是STA时独有字段，新添加字段请注意!!! */
    uint32_t assoc_req_ie_len;
    uint8_t *puc_assoc_req_ie_buff;
    oal_bool_enum_uint8 en_user_bw_limit; /* 该用是否有限速 */
    oal_bool_enum_uint8 en_wmm_switch;    /* 该用户是否开wmm */
    oal_bool_enum_uint8 en_user_vendor_vht_capable;
    oal_bool_enum_uint8 en_user_vendor_novht_capable;
    oal_bool_enum_uint8 en_report_kernel;
    wlan_tx_amsdu_enum_uint8 amsdu_level; /* 根据协议和max_mpdu_len 获取user amsdu level值 */
    uint8_t lut_index;
    uint16_t aus_tid_baw_size[WLAN_TID_MAX_NUM]; /* 保存与TID相关的信息 */

#ifdef _PRE_WLAN_FEATURE_EDCA_OPT_AP
    uint32_t aaul_txrx_data_stat[WLAN_WME_AC_BUTT][WLAN_TXRX_DATA_BUTT]; /* 发送/接收 tcp/udp be,bk,vi,vo报文 */
#endif

#ifdef _PRE_WLAN_FEATURE_WAPI
    hmac_wapi_stru st_wapi;
#endif
#ifdef _PRE_WLAN_FEATURE_PWL
    mac_user_pwl_stru pwl; /* PWL正式秘钥 */
    mac_user_pwl_stru pwl_pre; /* PWL预置秘钥 */
#endif
#if (defined(_PRE_WLAN_FEATURE_WAPI) || defined(_PRE_WLAN_FEATURE_PWL))
    hmac_wpi_cb wpi_cb; /* 数据帧加解密流程，提取pwl或wapi的钩子函数 */
    hmac_wpi_debug wpi_debug;
#endif

#ifdef _PRE_WLAN_FEATURE_HIEX
    hmac_hiex_sit_stru              st_hiex_sit;    // stream info table
    mac_hiex_ersru_ctrl_msg_stru    st_ersru;    /* extend range small resource unit */
#endif
#ifdef _PRE_WLAN_FEATURE_TCP_ACK_BUFFER
    void *tcp_ack_buf;
#endif
    uint8_t uc_cfm_num;                                            /* 用户已被识别业务个数 */
    oal_bool_enum_uint8 assoc_ap_up_tx_auth_req;                   // APUT下关联user是否在关联状态下回复过auth
    /* 未识别出RTP后清空重新识别的次数 在达到门限前可先快速预识别 加快识别过程 防止底层BE VI 调度可能导致的乱序 */
    uint16_t us_clear_judge_count;
    hmac_tx_cfm_flow_stru ast_cfm_flow_list[MAX_CONFIRMED_FLOW_NUM]; /* 已识别业务 */
    hmac_tx_judge_list_stru st_judge_list;                           /* 待识别流队列 */

    hmac_user_btcoex_stru st_hmac_user_btcoex;

    /* 当前VAP工作在STA模式，以下字段为user是AP时独有字段，新添加字段请注意!!! */
    hmac_user_stats_flag_stru st_user_stats_flag; /* 当user是sta时候，指示user是否被统计到对应项 */
    uint32_t rx_pkt_drop;                   /* 接收数据包host侧被drop的计数 */

    uint32_t first_add_time; /* 用户创建时的时间，用于统计用户在线时长 */

    /* dmac配置同步信息 */
    int8_t c_rssi;
    uint8_t uc_ps_st;
    int8_t c_free_power;
    uint8_t uc_rsvv;
#ifdef _PRE_WLAN_DFT_STAT
    uint8_t uc_cur_per;
    uint8_t uc_bestrate_per;
    uint8_t auc_resv4[NUM_2_BYTES];
#endif
    uint32_t tx_rate;
    uint32_t tx_rate_min;
    uint32_t tx_rate_max;
    uint32_t rx_rate;
    uint32_t rx_rate_min;
    uint32_t rx_rate_max;
    uint32_t aul_drop_num[WLAN_WME_AC_BUTT];
    uint32_t aul_tx_delay[3];              /* 共3个 0 1 2分别为最大发送延时,最小发送延时,平均发送延时 */
    mac_ap_type_enum_uint16 en_user_ap_type; /* 用户的AP类型，兼容性问题使用 */
    mac_sap_mode_enum_uint8 sap_mode;
    uint8_t reserved[NUM_1_BYTES];
    uint8_t auc_mimo_blacklist_mac[WLAN_MAC_ADDR_LEN];

#ifdef _PRE_WLAN_FEATURE_11V_ENABLE
    hmac_user_11v_ctrl_stru st_11v_ctrl_info; /* 11v控制信息结构体 */
#endif

#ifdef _PRE_WLAN_FEATURE_WMMAC
    mac_ts_stru st_ts_tmp_info[WLAN_WME_AC_BUTT]; /* 某个AC的TS已经建立成功，再次建立时临时参数保存 */
#endif

    hmac_tid_info_stru tx_tid_info[WLAN_TIDNO_BUTT];

    uint16_t    qos_last_seq_frag_num[WLAN_TID_MAX_NUM]; /* 保存本地最后收到的seq_num值 */

    uint8_t close_ht_flag;
    uint8_t assoc_err_code; /* 去关联 error code */

    hmac_last_pn_stru  last_pn_info; /* 保存本地最后收到的pn值 */

    hmac_user_stat_stru user_stats;
    void *vsp_hdl;

#ifdef _PRE_WLAN_CHBA_MGMT
    hmac_chba_user_stru chba_user;
#endif
    hmac_user_attack_mgmt_stru attack_mgmt;
    frw_timeout_stru kick_user_timer; /* 用户去关联定时器 */
    /* 用户支持信道列表，避免DBAC信道跟随时，切换到用户不支持信道列表，出现断联 */
    supproted_channel_stru supported_channel_param;

    /* 此项变量仅能处于HMAC USER结构体内的最后一项 */
    mac_user_stru st_user_base_info; /* hmac user与dmac user公共部分 */
} hmac_user_stru;

static inline oal_bool_enum_uint8 hmac_user_is_amsdu_support(hmac_user_stru *user, uint8_t tidno)
{
    return (oal_bool_enum_uint8)((user->uc_amsdu_supported) & (0x01 << ((tidno)&0x07)));
}

static inline void hmac_user_set_amsdu_support(hmac_user_stru *user, uint8_t tidno)
{
    user->uc_amsdu_supported |= (0x01 << ((tidno)&0x07));
}

static inline void hmac_user_set_amsdu_not_support(hmac_user_stru *user, uint8_t tidno)
{
    user->uc_amsdu_supported &= (uint8_t)(~(0x01 << ((tidno)&0x07)));
}
// for CSEC cycle complexity
static inline oal_bool_enum_uint8 hmac_ap_is_bw_2g_double_nss(wlan_nss_enum_uint8 support_max_nss,
    mac_vap_stru *mac_vap)
{
    return (oal_bool_enum_uint8)(((support_max_nss) == WLAN_DOUBLE_NSS) && \
        ((mac_vap)->st_channel.en_band == WLAN_BAND_2G));
}
#ifdef _PRE_WLAN_FEATURE_HIEX
#define HMAC_HIEX_MAX_SII_SIZE             8
#define HMAC_HIEX_SII_AGING_INTERVAL_MS    5000
#define HMAC_HIEX_SII_AGING_MS             60000
static inline hmac_hiex_sit_stru *hmac_hiex_get_user_sit(hmac_user_stru *user)
{
    return &(user->st_hiex_sit);
}
#endif
/* 存储AP关联请求帧的ie信息，用于上报内核 */
typedef struct {
    uint32_t assoc_req_ie_len;
    uint8_t *puc_assoc_req_ie_buff;
    uint8_t auc_user_mac_addr[WLAN_MAC_ADDR_LEN];
} hmac_asoc_user_req_ie_stru;

/* 上报内核去关联结构体 */
typedef struct {
    uint16_t reason_code;
    uint8_t type; /* 取值为   WLAN_FC0_SUBTYPE_DISASSOC或WLAN_FC0_SUBTYPE_DEAUTH */
    uint8_t is_roam; /* 标识漫游流程发出的去关联用于windows回收OID */
} hmac_disconnect;

/*
 * 函 数 名  : hmac_user_ht_support
 * 功能描述  : 是否为HT用户
 * 1.日    期  : 2013年4月11日
 *   修改内容  : 新生成函数
 */
OAL_STATIC OAL_INLINE oal_bool_enum_uint8 hmac_user_ht_support(hmac_user_stru *pst_hmac_user)
{
    return pst_hmac_user->st_user_base_info.st_ht_hdl.en_ht_capable;
}

/*
 * 函 数 名  : hmac_user_vht_support
 * 功能描述  : 是否为VHT用户
 * 1.日    期  : 2013年12月12日,星期四
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC OAL_INLINE oal_bool_enum_uint8 hmac_user_vht_support(hmac_user_stru *pst_hmac_user)
{
    return pst_hmac_user->st_user_base_info.st_vht_hdl.en_vht_capable;
}

/*
 * 函 数 名  : hmac_user_xht_support
 * 功能描述  : 是否支持ht/vht聚合
 * 1.日    期  : 2013年12月12日,星期四
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC OAL_INLINE oal_bool_enum_uint8 hmac_user_xht_support(hmac_user_stru *pst_hmac_user)
{
    return ((pst_hmac_user->st_user_base_info.en_cur_protocol_mode >= WLAN_HT_MODE) &&
            (pst_hmac_user->st_user_base_info.en_cur_protocol_mode < WLAN_PROTOCOL_BUTT));
}

uint32_t hmac_user_set_asoc_req_ie(hmac_user_stru *pst_hmac_user, uint8_t *puc_payload,
                                   uint32_t payload_len, uint8_t uc_reass_flag);
uint32_t hmac_user_free_asoc_req_ie(uint16_t us_idx);
uint32_t hmac_user_alloc(uint16_t *pus_user_idx);
uint32_t hmac_user_free(uint16_t us_idx);
uint32_t hmac_user_init(hmac_user_stru *pst_hmac_user);
uint32_t hmac_user_set_avail_num_space_stream(mac_user_stru *pst_mac_user, wlan_nss_enum_uint8 en_vap_nss);
void hmac_user_set_num_spatial_stream_160M(mac_user_stru *pst_mac_user);
void hmac_dbdc_need_kick_user(mac_vap_stru *pst_mac_vap, mac_device_stru *pst_mac_dev);
void hmac_user_clear_defrag_res(hmac_user_stru *hmac_user);
uint32_t hmac_user_del(mac_vap_stru *pst_mac_vap, hmac_user_stru *pst_hmac_user);
uint32_t hmac_user_add(mac_vap_stru *pst_mac_vap, uint8_t *puc_mac_addr, uint16_t *pus_user_index);
uint32_t hmac_alloc_user_lut_index(hmac_user_stru *hmac_user, mac_chip_stru *mac_chip,
    mac_ap_type_enum_uint16 ap_type);
uint32_t hmac_user_add_multi_user(mac_vap_stru *pst_mac_vap, uint16_t *us_user_index, uint8_t *multi_user_lut_idx);
uint32_t hmac_user_del_multi_user(mac_vap_stru *pst_mac_vap);
uint32_t hmac_user_add_notify_alg(mac_vap_stru *pst_mac_vap, uint16_t us_user_idx);
uint32_t hmac_update_user_last_active_time(mac_vap_stru *pst_mac_vap, uint8_t uc_len, uint8_t *puc_param);
void hmac_tid_clear(mac_vap_stru *pst_mac_vap, hmac_user_stru *pst_hmac_user);
hmac_user_stru *mac_res_get_hmac_user_alloc(uint16_t us_idx);
hmac_user_stru *mac_res_get_hmac_user(uint16_t us_idx);
hmac_user_stru *mac_vap_get_hmac_user_by_addr(mac_vap_stru *pst_mac_vap, uint8_t *puc_mac_addr, uint8_t mac_addr_len);
mac_ap_type_enum_uint16 hmac_identify_type_of_ap_with_compatibility_issues(mac_vap_stru *pst_mac_vap,
    uint8_t *puc_mac_addr);
void hmac_user_set_amsdu_level_by_max_mpdu_len(hmac_user_stru *pst_hmac_user, uint16_t us_max_mpdu_len);
void hmac_user_set_amsdu_level(hmac_user_stru *pst_hmac_user, wlan_tx_amsdu_enum_uint8 en_amsdu_level);
#ifdef _PRE_WLAN_FEATURE_WAPI
uint8_t hmac_user_is_wapi_connected(uint8_t uc_device_id);
#endif
void hmac_user_set_close_ht_flag(mac_vap_stru *p_mac_vap, hmac_user_stru *p_hmac_user);
void hmac_user_cap_update_by_hisi_cap_ie(hmac_user_stru *pst_hmac_user,
                                         uint8_t *puc_payload, uint32_t msg_len);
void hmac_init_user_lut_index_tbl(void);
hmac_user_stru *hmac_get_user_by_lut_index(uint8_t lut_idx);
#ifdef _PRE_WLAN_FEATURE_MCAST_AMPDU
void hmac_mcast_ampdu_rx_ba_init(hmac_user_stru *hmac_user, uint8_t tid);
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* end of hmac_user.h */
