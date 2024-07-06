

#ifndef _DCP_HANDLER_H
#define _DCP_HANDLER_H

#include <linux/ip.h>
#include <linux/ipv6.h>
#include <linux/list.h>
#include <linux/module.h>
#include <linux/net.h>
#include <linux/netfilter.h>
#include <linux/netlink.h>
#include <linux/types.h>
#include <net/tcp.h>
#include <net/sock.h>

#define LEN_OF_TOKEN 44
#define LEN_OF_AUTH_KEY_INFO 45
#define LEN_OF_SIGN_KEY_INFO 44
#define LEN_SHA256_HMAC 32
#define DCP_PROXY_CHECK (30 * HZ)
#define DCP_PUSH_CHECK (30 * HZ)
#define KEY_WORDS_LENGTH 4
#define FIRST_KEY_PKT 1
#define SECOND_KEY_PKT 2
#define MAX_DEST_ADDR_COUNT 30
#define MAX_SYN_FAIL_NUM 6
#define SYSTEM_UID 1000

enum dcp_cmd_type {
	NL_DCP_MSG_REG,
	NL_DCP_MSG_UNREG,
	NL_DCP_MSG_ENABLE_PXY,
	NL_DCP_MSG_DISABLE_PXY,
	NL_DCP_MSG_SET_APP_INFO,
	NL_DCP_MSG_SET_TOKEN,
	NL_DCP_MSG_PROCESS_DIED,
	NL_DCP_MSG_SET_IP_CONFIG,
	NL_DCP_MSG_REQ_BUTT
};

enum dcp_state {
	DCP_INIT_STATE,
	DCP_NORMAL_STATE,
	DCP_PROXY_STATE
};

enum dcp_notify_event {
	DCP_PROXY_SUCC,
	DCP_PROXY_FAIL,
	DCP_PROXY_BYPASS,
	DCP_CLOUD_ENABLE,
	DCP_CLOUD_DISABLE
};

enum dcp_push_socket_state {
	NOT_FOUND,
	FOUND_ESTABLISHED,
	FOUND_CLOSED
};

// Ŀ�ĵ�ַ�ṹ�嶨��
typedef union sockaddr_un_t {
	struct sockaddr_in6 v6;
	struct sockaddr_in v4;
	struct {
		u16 sin_family;
		u16 sin_port;
	};
} sockaddr_un;

// �µ��װ����ݽṹ�嶨��
struct sig_head_info {
	u16 version;
	u16 cmd_type;
	u32 time_stamp_high;
	u32 time_stamp_low;
	u32 length;
};

// �µ��װ����ݽṹ�嶨��
struct session_info {
	char auth_token[LEN_OF_AUTH_KEY_INFO];
	char resv[3];
	char token[LEN_OF_TOKEN];
	u32 session_id;
};

// �µ��װ����ݽṹ�嶨��
struct sig_forward_req_msg {
	struct sig_head_info head;
	struct session_info info;
	sockaddr_un orig_dst_address;
	u8 sha256[LEN_SHA256_HMAC];
};

// ��¼��ʼ����ǰ��socket��Ϣ
struct push_stream_info {
	u16 src_port;
	u16 dst_port;
	u32 key_words1_num;
	u32 key_words2_num;
	bool is_tcp_established;
	struct list_head push_stream_info_list;
};

// ��¼��ʼ�������Ŀ����Ϣ���Լ�Դ�˿�
struct proxy_socket_dst_info {
	u16 src_port; // Դ�˿�
	u16 dcp_index;
	sockaddr_un dst_info; // Ŀ�Ķ˿ڼ���ַ��Ϣ
	struct list_head proxy_socket_dst_info_list;
};

// ��¼ÿ���������е���Ϣ
struct proxy_app_info {
	u32 uid;
	u32 pids;
	u8 proxy_state; // ��ǰӦ��״̬
	u16 push_port;
	u8 push_socket_state;
	u8 fail_num;
	u8 proxy_socket_num;
	bool is_proxy_enable; // �Ƿ�������
	u16 dst_info_num;
	spinlock_t dst_info_list_lock;
	spinlock_t before_stream_lock;
	spinlock_t after_stream_lock;
	struct list_head app_info_list;
	struct list_head dst_info_list;
	struct list_head before_proxy_stream_list;
	struct list_head after_proxy_stream_list;
};

// �����ϱ��������
struct dcp_unsol_proxy_result {
	u32 uid;
	int result;
};

// ����netd�·����̵�uid, pid���Լ�����token��Ϣ
struct dcp_app_info {
	struct nlmsghdr hdr;
	u32 pids;
	u32 uid;
	char token[LEN_OF_TOKEN];
};

// ����netd�·��Ĵ��������IP��ַ��Ϣ
struct dcp_sockaddr_info {
	struct nlmsghdr hdr;
	u32 uid;
	sockaddr_un addr;
};

// ����ͷ����
void dcp_send_data_packet(struct sock *);
void dcp_tcp_state_change(struct sock *, int);
void dcp_tcp_v6_change_soackaddr(struct sock *, struct sockaddr_in6 *);
void dcp_tcp_v4_change_soackaddr(struct sock *, struct sockaddr_in *);
void process_auth_token_update(char *, int);
void process_sign_token_update(char *, int);
void dcp_close_proxy(bool);

#endif
