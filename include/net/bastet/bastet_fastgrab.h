

#ifndef _BST_FAST_GRAB_H
#define _BST_FAST_GRAB_H

#include <net/sock.h>
#ifdef CONFIG_CHR_NETLINK_MODULE
#include <hwnet/booster/netlink_handle.h>
#endif

#define BST_FG_MAX_CUSTOM_APP 4
#define BST_FG_MAX_SOCKET 10
#define BST_FG_UDP_BITMAP 0x02
#define BST_FG_TCP_BITMAP 0x01
#define BST_FG_SOCKET_FD_LEN sizeof(int)
#define BST_FG_SOCKET_PRT_BUF_LEN 150
#define BST_FG_VERSION_SUPPORT_SOCKET 1

#define bst_fg_is_uid_valid(uid) ((uid) > 0)

#define bst_min(x, y) ((x) < (y) ? (x) : (y))
#define bst_max(x, y) ((x) > (y) ? (x) : (y))

#ifdef CONFIG_HN_DPIMARK_MODULE
#define bst_fg_set_app_type(sk, value) \
	{ \
		sk->sk_hwdpi_mark |= (value << 8); \
	}

#define bst_fg_init_app_type(sk) \
	{ \
		sk->sk_hwdpi_mark &= (0xFFFF00FF); \
	}
#endif

/*
 * struct bst_fg_socket_info - bastet socket information.
 * @socket_fd: the fd of the socket, just for print.
 * @src_port: the source port of the socket, just for print.
 * @rsv[2]: reserve segment.
 * @sock_ptr: pointer to the struct sock area of the socket.
 * @ino: the inode number of the socket
 *
 * used to record the socket informations.
 */
struct bst_fg_socket_info {
	int32_t socket_fd;  /* just for print */
	uint16_t src_port;  /* just for print */
	uint8_t rsv[2];
	struct sock *sock_ptr;
	uint64_t ino;
};

/*
 * struct bst_fg_custom_info - bastet custom fg information.
 * @uid:The uid of Application.
 * @pid:The pid of Application.
 * @uc_protocol_bitmap:BIT0:tcp; BIT1:udp
 * @uc_tcp_retran_discard:Bit7 is switch flag, bit0~bit6 is value.
 * @uc_discard_timer:discard timer value.
 * @uc_app_type:app type
 * @socket_num: the number of sockets to filter.
 * @rsv[3]: reserve segment.
 * @socket_info: sockets to filter.
 *
 * used to record the tid bastet app common informations.
 */
struct bst_fg_custom_info {
	uid_t uid;
	pid_t pid;
	uint8_t uc_protocol_bitmap;
	uint8_t uc_tcp_retran_discard;
	uint8_t uc_discard_timer;
	uint8_t uc_app_type;
	uint8_t socket_num;  /* if socket_num is 0, then ignor socket informations */
	uint8_t rsv[3];
	struct bst_fg_socket_info socket_info[BST_FG_MAX_SOCKET];
};

#define BST_FG_CUSTOM_INFO_FIX_LEN offsetof(struct bst_fg_custom_info, rsv)

/*
 * struct bst_fg_custom_stru - bastet custom fg information.
 * @uc_app_num:app number.
 * @rsv[3]: reserve segment.
 * @ast_custom_info[BST_FG_MAX_CUSTOM_APP]:custom app infomations.
 *
 * used to record the several custom apps infomations
 */
struct bst_fg_custom_stru {
	uint8_t uc_app_num;
	uint8_t rsv[3];
	struct bst_fg_custom_info ast_custom_info[BST_FG_MAX_CUSTOM_APP];
};

void bst_fg_check_sock_uid(struct sock *pst_sock, int state);
bool bst_fg_hook_ul_stub(struct sock *pst_sock, struct msghdr *msg);
#ifdef CONFIG_HONOR_BASTET_MTK
void bst_fg_custom_process(struct sock *pst_sock, struct msghdr *msg,
	uint8_t uc_protocol_bitmap, struct sk_buff *skb);
void bst_set_vip_app_mark(struct sk_buff *skb);
#endif
#ifdef CONFIG_HONOR_BASTET_QCOM
bool bst_is_dns_port(struct sk_buff *skb, struct flowi4 *fl4);
void bst_fg_custom_process(struct sock *pst_sock, uint8_t uc_protocol_bitmap,
	struct sk_buff *skb, struct flowi4 *fl4);
void bst_set_high_prio_mark(struct sk_buff *skb);
#endif
#ifdef CONFIG_CHR_NETLINK_MODULE
void regist_msg_fun(notify_event *notify);
#endif

msg_process *bastet_fastgrab_init(notify_event *fn);

#endif

