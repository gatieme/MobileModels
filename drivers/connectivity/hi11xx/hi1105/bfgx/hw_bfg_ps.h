/**
 * Copyright (c) @CompanyNameMagicTag 2022-2023. All rights reserved.
 *
 * Description: bfg_ps functional module
 * Author: @CompanyNameTag
 */

#ifndef HW_BFG_PS_H
#define HW_BFG_PS_H

/* 其他头文件包含 */
#include <linux/kernel.h>
#include <linux/types.h>
#include "oal_net.h"
#include "oal_schedule.h"
#include "oal_workqueue.h"
#include "plat_type.h"

/* 宏定义 */
#define BT_TX_MAX_FRAME   3000  /* tx bt data max lenth */
#define GNSS_TX_MAX_FRAME 30000 /* gnss send buf max lenth */
#define FM_TX_MAX_FRAME   512   /* fm cmd data max lenth */
#define NFC_TX_MAX_FRAME  512   /* nfc cmd data max lenth */
#define IR_TX_MAX_FRAME   5120  /* ir cmd data max lenth */
#define DBG_TX_MAX_FRAME  10000 /* dbg cmd data max lenth */
#define SLE_TX_MAX_FRAME  3000  /* tx sle data max lenth */

#define BT_RX_MAX_FRAME                1500  /* RX bt data max lenth */
#define FM_RX_MAX_FRAME                512   /* fm recv buf max lenth */
#define NFC_RX_MAX_FRAME               512   /* nfc recv buf max lenth */
#define IR_RX_MAX_FRAME                5120  /* ir recv buf max lenth */
#define DBG_RX_MAX_FRAME               10000 /* dbg recv buf max lenth */
#define GNSS_RX_MAX_FRAME              30000 /* gnss recv buf max lenth */
#define SLE_RX_MAX_FRAME               1500  /* RX sle data max lenth */

#define OML_FRAME_MAX 2048 // 空间足够保存一包完整的log + OMLSENDMAX，OTA当前为1200字节

/* skb has skb_shared_info, and SKB_DATA_ALIGN */
#define GNSS_RX_SEPERATE_FRAME_MAX_LEN (4 * 1024 - SKB_DATA_ALIGN(sizeof(struct skb_shared_info)) - SKB_DATA_ALIGN(1))

#define PS_TX_PACKET_LIMIT   200

#define HISI_UART_DEV_NAME_LEN 32
#define PS_TX_WORK_NAME_LEN 32

/* define for tx and rx packet queue */
#define TX_URGENT_QUEUE 0
#define TX_HIGH_QUEUE   1
#define TX_LOW_QUEUE    2
#define RX_GNSS_QUEUE   3
#define RX_FM_QUEUE     4
#define RX_BT_QUEUE     5
#define RX_DBG_QUEUE    6
#define RX_NFC_QUEUE    7
#define RX_IR_QUEUE     8
#define RX_SLE_QUEUE    9

/* max number for tx and rx packet queue */
#define TX_HIGH_QUE_MAX_NUM 50
#define TX_LOW_QUE_MAX_NUM  250
#define RX_GNSS_QUE_MAX_NUM 50
#define RX_FM_QUE_MAX_NUM   50
#define RX_BT_QUE_MAX_NUM   50
#define RX_DBG_QUE_MAX_NUM  50
#define RX_NFC_QUE_MAX_NUM  50
#define RX_IR_QUE_MAX_NUM   50
#define RX_SLE_QUE_MAX_NUM  50

/* timeout when after download patch */
#define WAIT_BFGX_BOOTOK_TIME  1000
#define WAIT_BFGX_CLOSEOK_TIME 2000
#define WAIT_BT_OPEN_TIME      3000
#define WAIT_BT_CLOSE_TIME     3000
#define WAIT_FM_OPEN_TIME      3000
#define WAIT_FM_CLOSE_TIME     3000
#define WAIT_GNSS_OPEN_TIME    3000
#define WAIT_GNSS_CLOSE_TIME   3000
#define WAIT_IR_OPEN_TIME      3000
#define WAIT_IR_CLOSE_TIME     3000
#define WAIT_NFC_OPEN_TIME     1000
#define WAIT_NFC_CLOSE_TIME    2000
#define WAIT_SLE_OPEN_TIME     3000
#define WAIT_SLE_CLOSE_TIME    3000
#define BFGX_CLOSE_DELAY       1000

#define BFG_POWER_GPIO_DOWN 0
#define BFG_POWER_GPIO_UP   1

#define NONEED_SET_FLAG 0
#define NEED_SET_FLAG   1

#define DEV_THREAD_EXIT 0
#define DEV_THREAD_INIT 1

#define SYS_INF_HEARTBEAT_CMD_BASE 128

enum BFGN_DATA_MSG_TYPE_ENUM {
    SYS_MSG = 0x00,         /* 系统串口消息 */
    BT_MSG = 0x01,          /* BT串口消息 */
    GNSS_FIRST_MSG = 0x02,  /* GNSS串口消息，第一个分段消息 */
    GNSS_COMMON_MSG = 0x03, /* GNSS串口消息，中间分段消息 */
    GNSS_LAST_MSG = 0x04,   /* GNSS串口消息，最后一个分段消息 */
    FM_FIRST_MSG = 0x05,    /* FM串口消息，第一个分段消息 */
    FM_COMMON_MSG = 0x06,   /* FM串口消息，中间分段消息 */
    FM_LAST_MSG = 0x07,     /* FM串口消息，最后一个分段消息 */
    IR_FIRST_MSG = 0x08,    /* 红外串口消息，第一个分段消息 */
    IR_COMMON_MSG = 0x09,   /* 红外串口消息，中间分段消息 */
    IR_LAST_MSG = 0x0A,     /* 红外串口消息，最后一个分段消息 */
    NFC_FIRST_MSG = 0x0B,   /* NFC串口消息，第一个分段消息 */
    NFC_COMMON_MSG = 0x0C,  /* NFC串口消息，中间分段消息 */
    NFC_LAST_MSG = 0x0D,    /* NFC串口消息，最后一个分段消息 */
    OML_MSG = 0x0E,         /* 可维可测消息 */
    MEM_DUMP_SIZE = 0x0f,   /* bfgx异常时，要dump的mem长度消息 */
    MEM_DUMP = 0x10,        /* bfgx异常时，内存dump消息 */
    WIFI_MEM_DUMP = 0x11,   /* UART READ WIFI MEM，内存dump消息 */
    BFGX_CALI_MSG = 0x12,   /* BFGX 校准数据上报 */

    /* GF_CPU消息 */
    GF_SYS_MSG = 0x13,      /* GF系统串口消息 */
    GF_OML_MSG = 0x14,      /* GF可维可测消息 */

    SLE_MSG = 0x15,         /* SLE串口消息 */

    MSG_BUTT,
};

/* below is tx sys content define */
enum platform_event_enum {
    SYS_CFG_OPEN_BT = 0,
    SYS_CFG_CLOSE_BT = 1,
    SYS_CFG_OPEN_GNSS = 2,
    SYS_CFG_CLOSE_GNSS = 3,
    SYS_CFG_OPEN_FM = 4,
    SYS_CFG_CLOSE_FM = 5,
    SYS_CFG_OPEN_NFC = 6,
    SYS_CFG_CLOSE_NFC = 7,
    SYS_CFG_OPEN_IR = 8,
    SYS_CFG_CLOSE_IR = 9,
    SYS_CFG_OPEN_WIFI = 0xa,        /* host通过uart打开WCPU */
    SYS_CFG_CLOSE_WIFI = 0xb,       /* host通过uart关闭WCPU */
    SYS_CFG_READ_STACK = 0xc,       /* host通过uart读栈 */
    SYS_CFG_QUERY_RF_TEMP = 0xd,    /* host通过uart查询rf温度 */
    SYS_CFG_ALLOWDEV_SLP = 0xe,     /* host allow device sleep */
    SYS_CFG_DISALLOW_SLP = 0xf,     /* host disallow device sleep */
    SYS_CFG_SHUTDOWN_SLP = 0x10,    /* shutdown bcpu */
    SYS_CFG_PL_ENABLE_PM = 0x11,    /* enable plat dev lowpower feature */
    SYS_CFG_PL_DISABLE_PM = 0x12,   /* disable plat dev lowpower feature */
    SYS_CFG_BT_ENABLE_PM = 0x13,    /* enable BT dev lowpower feature */
    SYS_CFG_BT_DISABLE_PM = 0x14,   /* disable BT dev lowpower feature */
    SYS_CFG_GNSS_ENABLE_PM = 0x15,  /* enable GNSS dev lowpower feature */
    SYS_CFG_GNSS_DISABLE_PM = 0x16, /* disable GNSS dev lowpower feature */
    SYS_CFG_NFC_ENABLE_PM = 0x17,   /* enable NFC dev lowpower feature */
    SYS_CFG_NFC_DISABLE_PM = 0x18,  /* disable NFC dev lowpower feature */

    SYS_CFG_DEV_PANIC = 0x19,       /* cause device into exception */
    SYS_CFG_DUMP_RESET_WCPU = 0x1a, /* host通过uart不掉电复位WCPU */

    SYS_CFG_HALT_WCPU = 0x1b,          /* halt WCPU */
    SYS_CFG_READ_WLAN_PUB_REG = 0x1c,  /* 读取wcpu的公共寄存器 */
    SYS_CFG_READ_WLAN_PRIV_REG = 0x1d, /* 读取wcpu的私有寄存器 */
    SYS_CFG_READ_WLAN_MEM = 0x1e,      /* 读取wcpu的mem */
    SYS_CFG_EXCEP_RESET_WCPU = 0x1f,   /* wifi DFR WCPU复位 */

    SYS_CFG_SET_UART_LOOP_HANDLER = 0x20, /* 设置device侧uart环回处理函数 */
    SYS_CFG_SET_UART_LOOP_FINISH = 0x21,  /* UART环回test ok，恢复gnss消息处理函数 */

    PL_PM_DEBUG = 0x22,                 /* 低功耗维测开关 */
    PL_FAKE_CLOSE_BT_EVT = 0x23,          /* BT假关机 */
    PL_RSV1 = 0x24,

    SYS_CFG_NOTIFY_WIFI_OPEN = 0x25,  /* wifi open  通知 */
    SYS_CFG_NOTIFY_WIFI_CLOSE = 0x26, /* wifi close 通知 */
#ifdef _PRE_H2D_GPIO_WKUP
    SYS_CFG_ENABLE_GPIO_WKUP_BFG = 0x27, /* enable gpio wakeup bfg */
#endif
    SYS_CFG_OPEN_SLE  = 0x28,             /* host通过uart打开SLE */
    SYS_CFG_CLOSE_SLE = 0x29,             /* host通过uart打开SLE */

    PL_EVT_BUTT
};

/* below is rx sys content define from device */
enum SYS_INF_MSG_VALUE_ENUM {
    SYS_INF_PF_INIT = 0x00,                /* 平台软件初始化完成 */
    SYS_INF_BT_INIT = 0x01,                /* BT软件初始化完成 */
    SYS_INF_GNSS_INIT = 0x02,              /* GNSS软件初始化完成 */
    SYS_INF_FM_INIT = 0x03,                /* FM软件初始化完成 */
    SYS_INF_BT_DISABLE = 0x04,             /* BT禁能 */
    SYS_INF_GNSS_DISABLE = 0x05,           /* GNSS禁能 */
    SYS_INF_FM_DISABLE = 0x06,             /* FM禁能 */
    SYS_INF_BT_EXIT = 0x07,                /* BT退出 */
    SYS_INF_GNSS_EXIT = 0x08,              /* GNSS退出 */
    SYS_INF_FM_EXIT = 0x09,                /* FM退出 */
    SYS_INF_GNSS_WAIT_DOWNLOAD = 0x0A,     /* 等待GNSS代码下载 */
    SYS_INF_GNSS_DOWNLOAD_COMPLETE = 0x0B, /* GNSS代码下载完毕 */
    SYS_INF_BFG_HEART_BEAT = 0x0C,         /* 心跳信号 */
    SYS_INF_DEV_AGREE_HOST_SLP = 0x0D,     /* device回复host可睡 */
    SYS_INF_DEV_NOAGREE_HOST_SLP = 0x0E,   /* device回复host不可睡 */
    SYS_INF_WIFI_OPEN = 0x0F,              /* WCPU上电完成 */
    SYS_INF_IR_INIT = 0x10,                /* IR软件初始化完成 */
    SYS_INF_IR_EXIT = 0x11,                /* IR退出 */
    SYS_INF_NFC_INIT      =  0x12,         /* NFC软件初始化完成 */
    SYS_INF_NFC_EXIT      =  0x13,         /* NFC退出 */
    SYS_INF_WIFI_CLOSE = 0x14,             /* WCPU下电完成 */
    SYS_INF_RF_TEMP_NORMAL = 0x15,         /* RF温度正常 */
    SYS_INF_RF_TEMP_OVERHEAT = 0x16,       /* RF温度过热 */
    SYS_INF_MEM_DUMP_COMPLETE = 0x17,      /* bfgx异常时，MEM DUMP已完成 */
    SYS_INF_WIFI_MEM_DUMP_COMPLETE = 0X18, /* bfgx异常时，MEM DUMP已完成 */
    SYS_INF_UART_HALT_WCPU = 0x19,         /* uart halt wcpu ok */
    SYS_INF_UART_LOOP_SET_DONE = 0x1a,     /* device 设置uart环回ok */
    SYS_INF_CHR_ERRNO_REPORT = 0x1b,       /* device向host上报CHR异常码 */

    SYS_INF_FAKE_CLOSE_BT =  0x1c,         /* FAKE CLOSE BT的ACK */
    SYS_INF_RSV1 = 0x1d,                   /* rsv */
    SYS_INF_RSV2 = 0x1e,                   /* rsv */

    SYS_INF_GNSS_LPPE_INIT = 0x1F,         /* MP13 GNSS 新增的线程初始化完成 */
    SYS_INF_GNSS_LPPE_EXIT = 0x20,         /* MP13 GNSS 新增的线程退出 */
    SYS_INF_GNSS_TRICKLE_SLEEP = 0x21,     /* MP13 GNSS_TRICKLE_SLEEP */
#ifdef _PRE_H2D_GPIO_WKUP
    SYS_INF_ENABLE_GPIO_WKUP_BFG_RSP = 0x22, /* 配置uart or gpio唤醒 */
#else
    SYS_INF_RSV3 = 0x22,                    /* rsv */
#endif
    SYS_INF_BOOT_UP_ACK = 0x23,             /* device启动时通过消息回复ack的场景（通常是通过GPIO回复ack） */
    SYS_INF_WAKE_UP_ACK = 0x24,             /* device被唤醒时通过消息回复ack的场景（通常是通过GPIO回复ack） */
    SYS_INF_SLE_INIT = 0x25,                /* SLE软件初始化完成 */
    SYS_INF_SLE_EXIT = 0x26,                /* SLE退出 */

    SYS_INF_BUTT /* 枚举定义最大不能超过127，因为128~255被用来当做心跳的时间戳 */
};

typedef enum {
    BFGX_BT = 0x00,
    BFGX_FM = 0x01,
    BFGX_GNSS = 0x02,
    BFGX_IR = 0x03,
    BFGX_NFC = 0x04,
    BFGX_SLE = 0x05,
    BFGX_BUTT
} bfgx_subsys_type_enum;

#define WIFI_SUBSYS        BFGX_BUTT           /* wifi和BFG子系统统一编号 */
#define PLAT_SUBSYS        (WIFI_SUBSYS + 1)

#define MPXX_BT_SUB_MASK    (1 << BFGX_BT)
#define MPXX_FM_SUB_MASK    (1 << BFGX_FM)
#define MPXX_GNSS_SUB_MASK  (1 << BFGX_GNSS)
#define MPXX_IR_SUB_MASK    (1 << BFGX_IR)
#define MPXX_NFC_SUB_MASK   (1 << BFGX_NFC)
#define MPXX_SLE_SUB_MASK   (1 << BFGX_SLE)
#define MPXX_WIFI_SUB_MASK  (1 << WIFI_SUBSYS)
#define MPXX_PLAT_SUB_MASK  (1 << PLAT_SUBSYS)


typedef enum {
    BUART = 0,
    GUART = 1,

    UART_BUTT,
} uart_enum;

typedef enum {
    POWER_STATE_SHUTDOWN = 0,
    POWER_STATE_OPEN = 1,
    POWER_STATE_BUTT = 2,
} power_state_enum;

typedef enum {
    RX_SEQ_NULL = 0,
    RX_SEQ_START = 1,
    RX_SEQ_INT = 2,
    RX_SEQ_LAST = 3,

    RX_SEQ_BUTT,
} bfgx_rx_sepreted_pkt_type;

typedef enum {
    KZALLOC = 0,
    VMALLOC = 1,

    ALLOC_BUFF,
} alloc_type;

typedef enum {
    GNSS_SEPER_TAG_INIT,
    GNSS_SEPER_TAG_LAST,
} gnss_seperate_tag;

struct bfgx_sepreted_rx_st {
    oal_spin_lock_stru sepreted_rx_lock;
    uint8_t *rx_buf_ptr;
    uint8_t *rx_buf_org_ptr;
    uint16_t rx_pkt_len;
    uint16_t rx_buf_all_len;
    uint8_t rx_prev_seq;
};

struct st_bfgx_data {
    oal_spin_lock_stru rx_lock;
    oal_netbuf_head_stru rx_queue;
    oal_completion wait_opened;
    oal_completion wait_closed;
    struct bfgx_sepreted_rx_st sepreted_rx;   /* bfgx分包接收数据结构 */
    oal_wait_queue_head_stru rx_wait;         /* wait queue for rx packet */
    atomic_t subsys_state;
    const char *name;
    atomic_t read_delay;
    unsigned long rx_pkt_num;
    unsigned long tx_pkt_num;
    uint8_t *cali_buf;
};

#ifdef PLATFORM_DEBUG_ENABLE
struct uart_cache_buff {
    uint8_t  rx_pkt_err_flag;
    uint16_t rx_have_recv_cache_len;
    uint8_t  *rx_cache_buf_org_ptr;
    uint8_t  *rx_recv_cache_buf_ptr;
};
#endif

/*
 * struct ps_core_s - PS core internal structure
 * @tty: tty provided by the TTY core for line disciplines.
 * @txq: the list of skbs which needs to be sent onto the TTY.
 * @pm_data: reference to the parent encapsulating structure.
 *
 */
struct ps_core_s {
    void *ps_plat;
    struct pm_drv_data *pm_data;
    struct tty_struct *tty;
    struct st_bfgx_data bfgx_info[BFGX_BUTT];
    /* queue head define for all sk_buff */
    oal_netbuf_head_stru tx_high_seq;
    oal_netbuf_head_stru tx_low_seq;

    oal_netbuf_head_stru rx_dbg_seq;
    /* wait queue for rx packet */
    oal_wait_queue_head_stru rx_dbg_wait;
    /* force tx workqueue exit, release tty mutex */
    atomic_t force_tx_exit;
    atomic_t dbg_recv_dev_log;
    atomic_t dbg_read_delay;

    /* define for new workqueue */
    char tx_work_name[PS_TX_WORK_NAME_LEN];
    oal_workqueue_stru *ps_tx_workqueue;
    /* define new work struct */
    oal_work_stru tx_skb_work;
    uint16_t skb_retry_count; /* skb alloc retry times */

    oal_timer_list_stru tx_work_monitor_timer;
    uint16_t tx_work_wait_cnt;
    uint16_t tx_work_running;

    oal_spin_lock_stru rx_lock;

    /* mark user doing something on node */
    atomic_t node_visit_flag;

    /* define variable for decode rx data from uart */
    uint8_t rx_pkt_type;
    uint16_t rx_pkt_total_len;
    uint16_t rx_have_recv_pkt_len;
    uint16_t rx_have_del_public_len;
    uint8_t *rx_decode_tty_ptr;
    uint8_t *rx_public_buf_org_ptr;
    uint8_t *rx_decode_public_buf_ptr;

    uint8_t tty_have_open;
    int32_t uart_index;

    unsigned long rx_pkt_sys;
    unsigned long rx_pkt_oml;

    /* heartbeat timer */
    oal_timer_list_stru heartbeat_timer;
    atomic_t heartbeat_flag;
    uint32_t heartbeat_cnt;
    uint32_t heartbeat_dbg_flag;

    /* memdump */
    atomic_t is_memdump_runing;
    oal_completion wait_read_bfgx_stack;

    // 同一个UART可能接收多个CPU的log, 保存log非整包的残余数据
    uint8_t oml_frame_buf[2][OML_FRAME_MAX]; // 支持2种oml_type
    uint16_t oml_frame_len[2]; // 支持2种oml_type

    // ir only mode
    atomic_t ir_only;

    /* 统计tty数据的收发 */
    oal_mutex_stru tty_mutex;
    atomic_t tty_tx_cnt;
    atomic_t tty_rx_cnt;

#ifdef PLATFORM_DEBUG_ENABLE
    struct uart_cache_buff uart_packet_cache;
    uint16_t uart_cache_print_cnt;
#endif
};

/*
 * struct ps_plat_s - the PM internal data, embedded as the
 *  platform's drv data. One for each PS device in the system.
 * @core_data: PS core's data, which mainly is the tty's disc_data
 *
 */
struct ps_plat_s {
    struct ps_core_s *core_data;
    const uint8_t *uart_name;
    unsigned long baud_rate;
    struct list_head node;
    uint32_t uart_index;
    uint32_t flow_cntrl;
    uint32_t ldisc_num;
    int32_t host_wkup_io_type;
    uint32_t pm_switch;
};

#endif /* HW_BFG_PS_H */
