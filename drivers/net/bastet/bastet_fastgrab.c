
#include <net/bastet/bastet_fastgrab.h>

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/spinlock.h>
#include <linux/file.h>
#include <linux/list.h>
#include <linux/types.h>
#include <linux/err.h>
#include <linux/fs.h>
#include <linux/fdtable.h>
#include <linux/tcp.h>
#include <linux/version.h>
#include <net/sock.h>
#include <net/ip.h>
#include <linux/string.h>
#include <net/inet_sock.h>
#include <securec.h>

#include "hwnet/booster/hw_booster_common.h"

#include <net/bastet/bastet_utils.h>
#if (KERNEL_VERSION(4, 14, 0) <= LINUX_VERSION_CODE)
#endif

spinlock_t g_bast_fg_custom_lock;
struct bst_fg_custom_stru g_st_bastet_fg_custom;

#define VIP_APP_MARK 0x80000000
#define QCOM_DSCP_MARK 0xB8
#define DNS_PORT_NUM 53

static bool detect_sock_state(struct sock *pst_sock)
{
	if ((!sk_fullsock(pst_sock)) || sock_flag(pst_sock, SOCK_DEAD) ||
		(pst_sock->sk_state == TCP_TIME_WAIT)) {
		bastet_logd("fail,wrong sk_state");
		return false;
	}
	return true;
}

static void bst_fg_print_matched_info(uid_t l_sock_uid, __u16 src_port,
	uint8_t uc_protocol_bitmap, uint8_t uc_app_type)
{
	bastet_logd("BST_FG_CUSTOM:Find sock UID is %d", l_sock_uid);
	bastet_logd("Source Port is %d", src_port);
	bastet_logd("AppType is %d", uc_app_type);
	bastet_logd("ProtocolBitMap is %d", uc_protocol_bitmap);
}

bool bst_fg_is_socket_set(struct sock *sock, struct bst_fg_custom_info *custom_info)
{
	uint8_t idx;

	if (custom_info->socket_num == 0) {
		return true;
	}

	for (idx = 0; idx < custom_info->socket_num; idx++) {
		if (sock == custom_info->socket_info[idx].sock_ptr) {
			if (sock_i_ino(sock) == custom_info->socket_info[idx].ino) {
				return true;
			}
			bastet_loge("socket compare fail, pointer and ino is not corresponding");
		}
	}

	return false;
}

#ifdef CONFIG_HONOR_BASTET_QCOM
bool bst_is_dns_port(struct sk_buff *skb, struct flowi4 *fl4)
{
	struct udphdr *uh;

	if (fl4 != NULL) {
		uh = udp_hdr(skb);
		uh->dest = fl4->fl4_dport;
		// if support bastet all DNS will set vip flag
		if (htons(uh->dest) == DNS_PORT_NUM) {
			return true;
		}
	}
	return false;
}

/*
 * bst_fg_custom_process() - Application Customization
 *
 * @*pstSock: the object of socket
 * @*msg: struct msghdr, the struct of message that was sent.
 * @ucTcpOrUdpBitMa: bitmap of TCP or UDP.
 *
 * start to process the custom request.
 */
void bst_fg_custom_process(struct sock *pst_sock, uint8_t uc_protocol_bitmap,
    struct sk_buff *skb, struct flowi4 *fl4)
{
	uid_t l_sock_uid;
	uint8_t idx;
	uint8_t uc_app_num;
	struct dst_entry *dst = NULL;
	struct net_device *out = NULL;
	struct bst_fg_custom_info *past_custom_info = NULL;

	if (pst_sock == NULL || skb == NULL) {
		return;
	}

	dst = skb_dst(skb);
	if (likely(dst))
		out = dst->dev;

	if (!is_ds_rnic(out))
		return;

	if (!detect_sock_state(pst_sock)) {
		return;
	}

	if (bst_is_dns_port(skb, fl4))
		bst_set_high_prio_mark(skb);

#ifdef CONFIG_HN_DPIMARK_MODULE
	bst_fg_init_app_type(pst_sock);
#endif

	l_sock_uid = sock_i_uid(pst_sock).val;
	if (!bst_fg_is_uid_valid(l_sock_uid))
		return;

	uc_app_num = bst_min(g_st_bastet_fg_custom.uc_app_num, BST_FG_MAX_CUSTOM_APP);
	for (idx = 0; idx < uc_app_num; idx++) {
		if (l_sock_uid == g_st_bastet_fg_custom.ast_custom_info[idx].uid) {
			past_custom_info = &(g_st_bastet_fg_custom.ast_custom_info[idx]);
			break;
		}
	}

	if (past_custom_info == NULL) {
		return;
	}

	if (!bst_fg_is_socket_set(pst_sock, past_custom_info)) {
		return;
	}

	bst_fg_print_matched_info(l_sock_uid, pst_sock->sk_num, uc_protocol_bitmap,
		past_custom_info->uc_app_type);
	if (!(uc_protocol_bitmap & past_custom_info->uc_protocol_bitmap)) {
		return;
	}
	bst_set_high_prio_mark(skb);

#ifdef CONFIG_HN_DPIMARK_MODULE
	bst_fg_set_app_type(pst_sock, past_custom_info->uc_app_type);
	bastet_logd("DPI_MARK is 0x%x", pst_sock->sk_hwdpi_mark);
#endif
}

void bst_set_high_prio_mark(struct sk_buff *skb)
{
	struct iphdr *iph, _iph;
	int noff;

	if (skb == NULL) {
		return;
	}

	noff = skb_network_offset(skb);
	iph = skb_header_pointer(skb, noff, sizeof(_iph), &_iph);
	if (!iph) {
		bastet_loge("iph is NULL");
		return;
	}

	iph->tos = QCOM_DSCP_MARK;
}
#endif

#ifdef CONFIG_HONOR_BASTET_MTK
void bst_set_vip_app_mark(struct sk_buff *skb)
{
	if (skb != NULL) {
		skb->mark = skb->mark | VIP_APP_MARK;
	} else {
		bastet_loge("bst_set_vip_app_mark fail, skb is NULL");
	}
}

/*
 * bst_fg_custom_process() - Application Customization
 *
 * @*pstSock: the object of socket
 * @*msg: struct msghdr, the struct of message that was sent.
 * @ucTcpOrUdpBitMa: bitmap of TCP or UDP.
 *
 * start to process the custom request.
 */
void bst_fg_custom_process(struct sock *pst_sock, struct msghdr *msg,
	uint8_t uc_protocol_bitmap, struct sk_buff *skb)
{
	uid_t l_sock_uid;
	uint8_t idx;
	uint8_t uc_app_num;
	struct bst_fg_custom_info *past_custom_info = NULL;

    // IPV6 only RST set will return for mtk
	if (pst_sock == NULL) {
		return;
	}

	if (!detect_sock_state(pst_sock))
		return;

	l_sock_uid = sock_i_uid(pst_sock).val;

#ifdef CONFIG_HN_DPIMARK_MODULE
	bst_fg_init_app_type(pst_sock);
#endif

	if (!bst_fg_is_uid_valid(l_sock_uid))
		return;

	uc_app_num = bst_min(g_st_bastet_fg_custom.uc_app_num, BST_FG_MAX_CUSTOM_APP);
	for (idx = 0; idx < uc_app_num; idx++) {
		if (l_sock_uid == g_st_bastet_fg_custom.ast_custom_info[idx].uid) {
			past_custom_info = &(g_st_bastet_fg_custom.ast_custom_info[idx]);
			break;
		}
	}

	if (past_custom_info == NULL)
		return;

	if (!bst_fg_is_socket_set(pst_sock, past_custom_info)) {
		return;
	}

	if (!(uc_protocol_bitmap & past_custom_info->uc_protocol_bitmap))
		return;

	bst_set_vip_app_mark(skb);

#ifdef CONFIG_HN_DPIMARK_MODULE
	bst_fg_set_app_type(pst_sock, past_custom_info->uc_app_type);
	bastet_logd("DPI_MARK is 0x%x", pst_sock->__sk_common.skc_hwdpi_mark);
#endif
	bst_fg_print_matched_info(l_sock_uid, pst_sock->sk_num, uc_protocol_bitmap,
		past_custom_info->uc_app_type);
}
#endif

static bool bastet_fastgrab_save_one_app_info(uint8_t info_idx,
	void **infos_ptr, uint16_t *infos_msg_len)
{
	uint8_t socket_idx;
	int32_t socket_fd;
	struct sock *sock_ptr;
	struct bst_fg_custom_info *save_info_ptr;

	if (*infos_msg_len < BST_FG_CUSTOM_INFO_FIX_LEN) {
		bastet_loge("check message length for info fail");
		return false;
	}

	save_info_ptr = &(g_st_bastet_fg_custom.ast_custom_info[info_idx]);
	memcpy_s(save_info_ptr, sizeof(struct bst_fg_custom_info), *infos_ptr,
		BST_FG_CUSTOM_INFO_FIX_LEN);

	*infos_ptr += BST_FG_CUSTOM_INFO_FIX_LEN;
	*infos_msg_len -= BST_FG_CUSTOM_INFO_FIX_LEN;

	if (save_info_ptr->socket_num > BST_FG_MAX_SOCKET) {
		bastet_loge("socket number exceed the limit");
		return false;
	}

	if (*infos_msg_len < save_info_ptr->socket_num * BST_FG_SOCKET_FD_LEN) {
		bastet_loge("check message length for socket fail");
		return false;
	}

	for (socket_idx = 0; socket_idx < save_info_ptr->socket_num; socket_idx++) {
		socket_fd = *((int *)(*infos_ptr));
		*infos_ptr += BST_FG_SOCKET_FD_LEN;
		*infos_msg_len -= BST_FG_SOCKET_FD_LEN;

		sock_ptr = get_sock_by_fd_pid(socket_fd, save_info_ptr->pid);
		save_info_ptr->socket_info[socket_idx].socket_fd = socket_fd;
		save_info_ptr->socket_info[socket_idx].sock_ptr = sock_ptr;
		if (sock_ptr != NULL) {
			save_info_ptr->socket_info[socket_idx].ino = sock_i_ino(sock_ptr);
			save_info_ptr->socket_info[socket_idx].src_port = sock_ptr->sk_num;
			sock_put(sock_ptr);
		} else {
			save_info_ptr->socket_info[socket_idx].ino = 0;
			save_info_ptr->socket_info[socket_idx].src_port = 0;
		}
	}

	return true;
}

static void bastet_fastgrab_save_info(uint16_t app_num, void *infos_ptr, uint16_t infos_msg_len)
{
	uint8_t idx;

	spin_lock_bh(&g_bast_fg_custom_lock);
	g_st_bastet_fg_custom.uc_app_num = app_num;
	for (idx = 0; idx < g_st_bastet_fg_custom.uc_app_num; idx++) {
		if (!bastet_fastgrab_save_one_app_info(idx, &infos_ptr, &infos_msg_len)) {
			g_st_bastet_fg_custom.uc_app_num = 0;
			break;
		}
	}
	spin_unlock_bh(&g_bast_fg_custom_lock);
}

static void bastet_fastgrab_print_info()
{
	uint8_t info_idx;
	uint8_t socket_idx;
	uint16_t len = 0;
	char socket_print_buffer[BST_FG_SOCKET_PRT_BUF_LEN];
	uint16_t available_buffer_size;
	char *print_buffer_ptr = NULL;

	bastet_logi("app num is %d", g_st_bastet_fg_custom.uc_app_num);
	for (info_idx = 0; info_idx < g_st_bastet_fg_custom.uc_app_num; info_idx++) {
		struct bst_fg_custom_info *custom_info = &g_st_bastet_fg_custom.ast_custom_info[info_idx];

		bastet_logi("uid is %d", custom_info->uid);
		bastet_logi("pid is %d", custom_info->pid);
		bastet_logi("discard_timer is %d", custom_info->uc_discard_timer);
		bastet_logi("app_type is %d,", custom_info->uc_app_type);
		bastet_logi("ProtocolBitMap is %d", custom_info->uc_protocol_bitmap);
		bastet_logi("RetranDiscardFlag is %d", custom_info->uc_tcp_retran_discard);

		if (custom_info->socket_num == 0) {
			continue;
		}

		available_buffer_size = BST_FG_SOCKET_PRT_BUF_LEN;
		print_buffer_ptr = socket_print_buffer;
		for (socket_idx = 0; socket_idx < custom_info->socket_num; socket_idx++) {
			len = snprintf_s(print_buffer_ptr, available_buffer_size, available_buffer_size - 1,
				"%d,%u;", custom_info->socket_info[socket_idx].socket_fd,
				custom_info->socket_info[socket_idx].src_port);
			if (len < 0) {
				bastet_loge("socket print buffer is full, len is %u, available_buffer_size is %u",
					len, available_buffer_size);
				break;
			}
			available_buffer_size -= len;
			print_buffer_ptr += len;
		}
		bastet_logi("[socket_fd,src_port]:%s", socket_print_buffer);
	}
}

static void bastet_fastgrab_do_command(struct req_msg_head *msg)
{
	uint8_t version;
	uint16_t app_num;
	char *version_ptr = NULL;
	char *app_num_ptr = NULL;
	struct bst_fg_custom_info *custom_infos_ptr = NULL;
	uint16_t custom_infos_msg_len = 0;

	if (!msg || (msg->len < sizeof(struct req_msg_head) + sizeof(uint8_t) + sizeof(uint16_t))) {
		bastet_loge("msg is null or msg length is too short");
		return;
	}

	version_ptr = (char *)msg + sizeof(struct req_msg_head);
	version = *((uint8_t *)version_ptr);

	if (version != BST_FG_VERSION_SUPPORT_SOCKET) {
		bastet_loge("version check fail");
		return;
	}

	app_num_ptr = version_ptr + sizeof(uint8_t);
	app_num = bst_min(*((uint16_t *)app_num_ptr), BST_FG_MAX_CUSTOM_APP);

	custom_infos_ptr = (struct bst_fg_custom_info *)(app_num_ptr + sizeof(uint16_t));
	custom_infos_msg_len = msg->len - sizeof(struct req_msg_head)
		- sizeof(uint8_t) - sizeof(uint16_t);

	bastet_fastgrab_save_info(app_num, custom_infos_ptr, custom_infos_msg_len);
	bastet_fastgrab_print_info();
}

msg_process *bastet_fastgrab_init(notify_event *fn)
{
	spin_lock_init(&g_bast_fg_custom_lock);
	memset_s(&g_st_bastet_fg_custom, sizeof(g_st_bastet_fg_custom), 0, sizeof(g_st_bastet_fg_custom));
	return bastet_fastgrab_do_command;
}

