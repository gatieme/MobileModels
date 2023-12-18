/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2022.
 * Description: This file implements communication between kernel
 *              and user space.
 * Author: c00454187
 * Create: 2022-9-16
 */

#ifndef _DCP_HANDLER_H
#define _DCP_HANDLER_H

#include <linux/netlink.h>
#include <linux/net.h>
#include <net/sock.h>
#include <linux/ip.h>
#include <linux/ipv6.h>
#include <net/tcp.h>
#include <linux/netfilter.h>

#define LEN_OF_TOKEN 44
#define NUM_OF_WEIXIN_APP 2
#define NUM_OF_BIND_PORT 3
#define NUM_OF_RECORD_PORT 8
#define DCP_PROXY_CHECK (15 * HZ)
#define DCP_PUSH_CHECK (30 * HZ)
#define MIN_APP_UID 10000
#define LOW_PORT 64000
#define HIGH_PORT 65000
#define KEY_WORDS_LENGTH 4
#define FIRST_KEY_PKT 1
#define SECOND_KEY_PKT 2

enum dcp_cmd_type {
	NL_DCP_MSG_REG,
	NL_DCP_MSG_UNREG,
	NL_DCP_MSG_ENABLE_PXY,
	NL_DCP_MSG_DISABLE_PXY,
	NL_DCP_MSG_SET_APP_INFO,
	NL_DCP_MSG_SET_TOKEN,
	NL_DCP_MSG_PROCESS_DIED,
	NL_DCP_MSG_REQ_BUTT
};

enum dcp_state {
	DCP_INIT_STATE,
	DCP_NORMAL_STATE,
	DCP_PROXY_STATE,
	DCP_BUTT_STATE
};

enum dcp_notify_event {
	DCP_PROXY_SUCC,
	DCP_PROXY_FAIL,
	DCP_PORT_RANGE,
	DCP_PUSH_FOUND
};

// 目的地址结构体定义
typedef union sockaddr_un_t {
	struct sockaddr_in6 v6;
	struct sockaddr_in v4;
	struct {
		u16 sin_family;
		u16 sin_port;
	};
} sockaddr_un;

// 首包数据结构体定义
struct sig_head {
	u8 length;
	u8 name;
	u16 check_sum;
	char token[LEN_OF_TOKEN];
};

// 首包数据结构体定义
struct sig_forward_req_new {
	struct sig_head head;
	u32 session_id;
	sockaddr_un orig_dst_address;
};

// 记录开始导流前的socket信息
struct push_stream_info {
	u16 src_port;
	u16 dst_port;
	u32 key_words1_num;
	u32 key_words2_num;
	u32 socket_life_cycle;
};

// 记录开始导流后的目的信息，以及源端口
struct proxy_socket_dst_info {
	u16 src_port; // 源端口
	sockaddr_un dst_info; // 目的信息
};

// 记录每个push进程所有的流信息
struct push_process_ctx {
	u32 uid;
	u32 pids;
	u8 proxy_state;
	u8 bind_port_num;
	u8 is_push_socket_finded;
	u8 is_notify_result;
	struct proxy_socket_dst_info dst_info_list[NUM_OF_BIND_PORT];
	struct push_stream_info before_proxy_stream_list[NUM_OF_RECORD_PORT];
	struct push_stream_info after_proxy_stream_list[NUM_OF_BIND_PORT];
};

// kernel上报代理结果
struct dcp_unsol_proxy_result {
	u32 uid;
	int result;
};

// kernel主动上报端口号
struct dcp_port_range {
	u32 uid;
	u16 low;
	u16 high;
};

// netd下发信息结构体类型
struct dcp_app_info {
	struct nlmsghdr hdr;
	u32 pids;
	u32 uid;
	char token[LEN_OF_TOKEN];
};

// 函数头定义
void dcp_bind_port_range(struct sock *, u32 *, u32 *);
void dcp_send_data_packet(struct sock *);
void dcp_hook_dl_stub(struct sock *, struct sk_buff *);

#endif
