/*
 * 版权所有 (c) 华为技术有限公司 2014-2019
 * 功能说明 : APUT发送性能优化模块
 * 作    者 : g00428180
 * 创建日期 : 2019年7月22日
 */

#ifndef __HMAC_TX_OPT_H__
#define __HMAC_TX_OPT_H__

/* 1 头文件包含 */
#include "oal_ext_if.h"
#include "mac_vap.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_TX_OPT_H

/* 2 宏定义 */
#define MAX_TX_OPT_SWITCH_CNT 3
#define MAX_TX_OPT_SWITCH_CNT_TCP_ACK 3

/* 3 枚举定义 */
/* 4 全局变量声明 */
/* 5 消息头定义 */
/* 6 消息定义 */
/* 7 STRUCT定义 */
/* 8 UNION定义 */
/* 9 OTHERS定义 */
/* 10 函数声明 */
extern oal_void hmac_tx_opt_switch(oal_uint32 ul_tx_large_pps);
extern oal_void hmac_tx_opt_switch_tcp_ack(oal_uint32 ul_rx_large_pps);
extern oal_void hmac_set_tx_opt_switch_cnt(oal_uint8 uc_opt_switch_cnt);
extern oal_void hmac_set_tx_opt_switch_cnt_tcp_ack(oal_uint8 uc_opt_switch_cnt);
extern oal_void hmac_tx_opt_set_ip_addr(mac_vap_stru *pst_mac_vap, oal_void *pst_ip_addr);
extern oal_void hmac_tx_opt_del_ip_addr(mac_vap_stru *pst_mac_vap, oal_void *pst_ip_addr);
extern oal_bool_enum_uint8 hmac_get_tx_opt_tcp_ack(oal_void);

#endif
