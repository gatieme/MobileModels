/**
 * Copyright (c) @CompanyNameMagicTag 2022-2023. All rights reserved.
 *
 * Description: bfgx_dev.c header file
 * Author: @CompanyNameTag
 */

#ifndef BFGX_DEV_H
#define BFGX_DEV_H

/* 其他头文件包含 */
#include "exception_common.h"
#include "hw_bfg_ps.h"

/* 宏定义 */
#define BT_TYPE_DATA_LEN       1

#define SUBSYS_NAME_SIZE       12

/* timeout for gnss read */
#define GNSS_READ_DEFAULT_TIME 1000
#define GNSS_MAX_READ_TIME     10000


/* timeout for fm read */
#define FM_READ_DEFAULT_TIME 1000
#define FM_MAX_READ_TIME     10000

/* timeout for dbg read */
#define DBG_READ_DEFAULT_TIME 5000

#define UART_LOOP_RESUME_DEVICE_DATA_HANDLER 0
#define UART_LOOP_SET_DEVICE_DATA_HANDLER    1

#define UART_LOOP_MAX_PKT_LEN 2048 /* device buf len is 2400 */

/* 结构体定义 */
struct bt_data_combination {
    uint8_t len;
    uint8_t type;
    uint16_t resverd;
    oal_mutex_stru comb_mutex;
};

typedef struct uart_loop_user_cfg {
    uint32_t loop_count;
    uint16_t pkt_len;
    uint16_t cpu_fre;
    uint32_t uart_loop_enable;
    uint32_t uart_loop_tx_random_enable;
} uart_loop_cfg;

typedef struct uart_loop_test {
    uart_loop_cfg *test_cfg;
    uint8_t *tx_buf;
    uint8_t *rx_buf;
    uint16_t rx_pkt_len;
    uint16_t result;
    struct completion set_done;
    struct completion loop_test_done;
} uart_loop_test_struct;

/* 全局变量声明 */
extern uint32_t g_gnss_me_thread_status;
extern uint32_t g_gnss_lppe_thread_status;

extern uart_loop_cfg g_uart_loop_test_cfg;
extern uart_loop_test_struct *g_uart_loop_test_info;

/* 函数声明 */
void service_attribute_load(void);
uint8_t service_get_bus_id(uint8_t service);
uint8_t service_bus_to_sys_en(uint8_t bus_id);
uint8_t* service_get_name(uint8_t service);
int32_t uart_loop_test(struct ps_core_s *ps_core_d);
int32_t uart_loop_test_recv_pkt(struct ps_core_s *ps_core_d, const uint8_t *buf_ptr, uint16_t pkt_len);
struct ps_core_s *ps_get_core_reference(uint32_t uart_index);
int32_t ps_get_plat_reference(struct ps_plat_s **plat_data);
struct sk_buff *ps_alloc_skb(uint16_t len);
void ps_kfree_skb(struct ps_core_s *ps_core_d, uint8_t type);
int32_t alloc_seperted_rx_buf(struct ps_core_s *ps_core_d, uint8_t subsys, uint32_t len, uint8_t alloctype);
void free_seperted_rx_buf(struct ps_core_s *ps_core_d, uint8_t subsys, uint8_t alloctype);
bool ps_chk_tx_queue_empty(struct ps_core_s *ps_core_d);
int32_t plat_bfgx_dump_rotate_cmd_read(struct ps_core_s *ps_core_d, unsigned long arg);
bool ps_bfg_subsys_active(struct ps_core_s *ps_core_d, uint32_t subsys);
void ps_set_device_log_status(bool status);
bool ps_is_device_log_enable(void);
int32_t prepare_to_visit_node(struct ps_core_s *ps_core_d, int32_t *prepare_result);
void post_to_visit_node(struct ps_core_s *ps_core_d, int32_t prepare_result);
int32_t bfgx_open_cmd_send(struct ps_core_s *ps_core_d, uint32_t subsys);
int32_t bfgx_close_cmd_send(struct ps_core_s *ps_core_d, uint32_t subsys);
int32_t uart_bfgx_close_cmd(struct ps_core_s *ps_core_d);
int32_t hw_ir_only_open_other_subsys(void);
int32_t ps_restore_skbqueue(struct ps_core_s *ps_core_d, struct sk_buff *skb, uint8_t type);
int32_t hw_bfgx_open(struct ps_core_s *ps_core_d, uint32_t subsys);
int32_t hw_bfgx_close(struct ps_core_s *ps_core_d, uint32_t subsys);
void hw_bfgx_close_for_excp(struct pm_drv_data *pm_data, uint32_t flag);
int32_t hw_plat_open(uint8_t uart);
int32_t hw_plat_close(uint8_t uart);
int32_t hw_bfgx_write_check(const char __user *buf, struct ps_core_s *ps_core_d,
                            uint32_t subsys);
#ifdef _PRE_CONFIG_HISI_S3S4_POWER_STATE
extern long hw_bt_ioctl(struct file *file, uint32_t cmd, unsigned long arg);
#endif
#endif /* __BFGX_DEV_H__ */
