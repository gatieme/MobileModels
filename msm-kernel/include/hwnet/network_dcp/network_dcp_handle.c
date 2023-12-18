/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2022.
 * Description: This file implements weixin proxy function
 * Author: c00454187
 * Create: 2022-9-16
 */

#include "network_dcp_handle.h"
#include <linux/init.h>
#include <linux/module.h>
#include <linux/errno.h>
#include <linux/mutex.h>
#include <linux/semaphore.h>
#include <linux/time.h>
#include <net/sock.h>
#include <net/netlink.h>
#include <linux/skbuff.h>
#include <huawei_platform/log/hw_log.h>
#include <linux/types.h>
#include <uapi/linux/netlink.h>
#include <uapi/linux/netfilter.h>
#include <uapi/linux/netfilter_ipv4.h>
#include <securec.h>

#undef HWLOG_TAG
#define HWLOG_TAG network_dcp
HWLOG_REGIST();
MODULE_LICENSE("GPL");
DEFINE_MUTEX(dcp_receive_sem);

static unsigned int g_user_space_pid;
static int g_push_timer_count = 1;
static u32 g_session_id = 10000;

static char g_token_info[LEN_OF_TOKEN];
static spinlock_t g_dcp_send_lock;
static spinlock_t g_proxy_state_lock;

static struct sock *g_dcp_nlfd;
static struct semaphore g_dcp_netlink_sema;
static struct timer_list g_dcp_push_check_timer;
static struct timer_list g_dcp_proxy_check_timer;
static struct push_process_ctx g_push_process_ctx[NUM_OF_WEIXIN_APP];

const char g_push_keywords1[] = {0x16, 0xf1, 0x04, 0x00};
const char g_push_keywords2[] = {0x17, 0xf1, 0x04, 0x01};

u32 get_transport_hdr_len(const struct sk_buff *skb, u8 proto)
{
	if (proto == IPPROTO_UDP)
		return sizeof(struct udphdr);

	return tcp_hdrlen(skb);
}

bool is_zero_lineare_room(const struct sk_buff *skb, u8 proto)
{
	if (skb_is_nonlinear(skb) &&
		(skb_headlen(skb) == skb_transport_offset(skb)
			+ get_transport_hdr_len(skb, proto)))
		return true;

	return false;
}

u32 dcp_get_parse_len(const struct sk_buff *skb, u8 proto)
{
	u32 parse_len = 0;
	u32 hdr_len = get_transport_hdr_len(skb, proto);
	if (skb->len > skb_transport_offset(skb) + hdr_len)
		parse_len = skb->len - skb_transport_offset(skb) - hdr_len;
	return parse_len;
}

u8 *dcp_get_payload_addr(const struct sk_buff *skb,
	u8 proto, u8 **vaddr, u32 *parse_len)
{
	const skb_frag_t *frag = NULL;
	struct page *page = NULL;
	u8 *payload = NULL;
	if (skb == NULL || vaddr == NULL || parse_len == NULL)
		return payload;

	if (is_zero_lineare_room(skb, proto)) {
		frag = &skb_shinfo(skb)->frags[0];
		page = skb_frag_page(frag);
		*vaddr = kmap_atomic(page);
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 4, 0)
		payload = *vaddr + frag->page_offset;
#else
		payload = *vaddr + skb_frag_off(frag);
#endif
		*parse_len = skb_frag_size(frag);
	} else {
		payload = skb_transport_header(skb) + get_transport_hdr_len(skb, proto);
		*parse_len = dcp_get_parse_len(skb, proto);
	}
	return payload;
}

void dcp_unmap_vaddr(u8 *vaddr)
{
	if (vaddr)
		kunmap_atomic(vaddr);
}

bool is_ipv6_packet(struct sock *sk)
{
	return ((sk->sk_family == AF_INET6 &&
		!((u32)ipv6_addr_type(&sk->sk_v6_rcv_saddr) &
		IPV6_ADDR_MAPPED)) ? true : false);
}

bool is_port_in_proxy_range(u16 port)
{
	if (port >= LOW_PORT && port <= HIGH_PORT)
		return true;
	return false;
}

uid_t dcp_get_uid_from_sock(struct sock *sk)
{
	if (sk == NULL)
		return 0;
	return sk->sk_uid.val;
}

int get_weixin_uid_index(u32 uid)
{
	int index = -1;
	if (uid == g_push_process_ctx[0].uid)
		index = 0;
	if (uid == g_push_process_ctx[1].uid)
		index = 1;

	return index;
}

int get_weixin_pid_index(u32 pid)
{
	int index = -1;
	if (pid == g_push_process_ctx[0].pids)
		index = 0;
	if (pid == g_push_process_ctx[1].pids)
		index = 1;
	return index;
}

u8 get_proxy_state(int index)
{
	u8 result;
	if (index < 0 || index > 1)
		return DCP_INIT_STATE;
	spin_lock_bh(&g_proxy_state_lock);
	result = g_push_process_ctx[index].proxy_state;
	spin_unlock_bh(&g_proxy_state_lock);
	return result;
}

u8 get_proxy_state_by_uid(u32 uid)
{
	int index = get_weixin_uid_index(uid);
	return get_proxy_state(index);
}

void set_proxy_state(int index, u8 state)
{
	if (index < 0 || index > 1)
		return;
	spin_lock_bh(&g_proxy_state_lock);
	g_push_process_ctx[index].proxy_state = state;
	spin_unlock_bh(&g_proxy_state_lock);
}

u32 is_push_skb(struct sk_buff *skb, struct tcphdr *tcph, struct iphdr *iph)
{
	char *tcp_payload = NULL;
	u8 *vaddr = NULL;
	u32 dlen;
	if (tcph->ack != 1 || tcph->psh != 1)
		return 0;

	tcp_payload = (char *)dcp_get_payload_addr(skb, IPPROTO_TCP, &vaddr, &dlen);
	if (dlen == 0 || tcp_payload == NULL) {
		dcp_unmap_vaddr(vaddr);
		return 0;
	}

	if (dlen > KEY_WORDS_LENGTH &&
		strncmp(tcp_payload, g_push_keywords1, KEY_WORDS_LENGTH - 1) == 0) {
		hwlog_info("%s, s_port: %u, d_port: %u, first key pkt.\n", __func__,
			htons(tcph->source), htons(tcph->dest));
		dcp_unmap_vaddr(vaddr);
		return FIRST_KEY_PKT;
	}

	if (dlen > KEY_WORDS_LENGTH &&
		strncmp(tcp_payload, g_push_keywords2, KEY_WORDS_LENGTH -1) == 0) {
		hwlog_info("%s, s_port: %u, d_port: %u, second key pkt.\n", __func__,
			htons(tcph->source), htons(tcph->dest));
		dcp_unmap_vaddr(vaddr);
		return SECOND_KEY_PKT;
	}

	dcp_unmap_vaddr(vaddr);
	return 0;
}

void clear_push_process_ctx(int index)
{
	if (index < 0 || index > 1)
		return;

	g_push_process_ctx[index].bind_port_num = 0;
	(void)memset_s(g_push_process_ctx[index].dst_info_list,
		sizeof(g_push_process_ctx[index].dst_info_list), 0,
		sizeof(g_push_process_ctx[index].dst_info_list));
	(void)memset_s(g_push_process_ctx[index].before_proxy_stream_list,
		sizeof(g_push_process_ctx[index].before_proxy_stream_list), 0,
		sizeof(g_push_process_ctx[index].before_proxy_stream_list));
	(void)memset_s(g_push_process_ctx[index].after_proxy_stream_list,
		sizeof(g_push_process_ctx[index].after_proxy_stream_list), 0,
		sizeof(g_push_process_ctx[index].after_proxy_stream_list));
}

u16 calc_checksum(struct sig_forward_req_new *msg, int len)
{
	u16 *p_16bit_hdr = (u16 *)msg;
	u16 us_sum = 0;
	u32 ul_sum = 0;
	while (len > 1) {
		ul_sum += *p_16bit_hdr;
		p_16bit_hdr++;
		len -= 2; // step 2 for each loop
	}
	if (len == 1)
		ul_sum += *((u8 *)p_16bit_hdr);

	while (ul_sum >> 16) // shift 16 bit
		ul_sum = (ul_sum & 0xFFFF) + (ul_sum >> 16); // shift 16 bit
	us_sum = (u16)~ul_sum;
	return us_sum;
}

struct proxy_socket_dst_info *find_target_stream(u32 uid, u16 port)
{
	int i;
	int index;
	struct proxy_socket_dst_info *dst_info = NULL;
	index = get_weixin_uid_index(uid);
	if (index < 0)
		return NULL;

	dst_info = g_push_process_ctx[index].dst_info_list;
	for (i = 0; i < NUM_OF_BIND_PORT; i++) {
		if (dst_info->src_port == port) {
			hwlog_info("%s success, uid: %lu, port: %lu.\n", __func__, uid, port);
			return dst_info;
		}
		dst_info++;
	}
	hwlog_info("%s fail, uid: %lu, port: %lu.\n", __func__, uid, port);
	return NULL;
}

struct sig_forward_req_new *construct_data_packet(u32 uid, u16 src_port)
{
	u32 ret;
	struct proxy_socket_dst_info *dst_info = NULL;
	struct sig_forward_req_new *msg = NULL;
	dst_info = find_target_stream(uid, src_port);
	if (dst_info == NULL) {
		hwlog_err("%s dst_info is NULL.!\n", __func__);
		return NULL;
	}

	msg = kmalloc(sizeof(struct sig_forward_req_new), GFP_KERNEL);
	if (msg == NULL) {
		hwlog_err("%s kmalloc error!\n", __func__);
		return NULL;
	}

	msg->head.length = sizeof(struct sig_forward_req_new);
	msg->head.name = 1;
	ret = memcpy_s(msg->head.token, LEN_OF_TOKEN, g_token_info, LEN_OF_TOKEN);
	if (ret < 0) {
		kfree(msg);
		return NULL;
	}
	g_session_id++;
	msg->session_id = g_session_id;
	msg->orig_dst_address.sin_family = dst_info->dst_info.sin_family;
	msg->orig_dst_address.sin_port = dst_info->dst_info.sin_port;
	msg->orig_dst_address.v4.sin_addr.s_addr = dst_info->dst_info.v4.sin_addr.s_addr;
	msg->head.check_sum = calc_checksum(msg, sizeof(struct sig_forward_req_new));
	return msg;
}

void send_data_packet(struct sock *sk, u16 src_port)
{
	u32 uid;
	struct kvec vec;
	struct msghdr msg1;
	struct sig_forward_req_new *msg = NULL;
	uid = dcp_get_uid_from_sock(sk);
	msg = construct_data_packet(uid, src_port);
	if (msg == NULL) {
		hwlog_err("%s: fail, msg is NULL.\n", __func__);
		return;
	}

	vec.iov_base = msg;
	vec.iov_len = sizeof(struct sig_forward_req_new);
	(void)memset_s(&msg1, sizeof(msg1), 0, sizeof(msg1));
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 4, 0))
	iov_iter_kvec(&msg1.msg_iter, WRITE | ITER_KVEC,
		&vec, 1, sizeof(struct sig_forward_req_new));
#else
	iov_iter_kvec(&msg1.msg_iter, WRITE,
		&vec, 1, sizeof(struct sig_forward_req_new));
#endif
	(void)tcp_sendmsg_locked(sk, &msg1, sizeof(struct sig_forward_req_new));
	kfree(msg);
	hwlog_info("%s: success.\n", __func__);
}

void find_idle_port(u16 *low, u16 *high)
{
	*low = LOW_PORT;
	*high = HIGH_PORT;
}

void notify_proxy_result(u32 uid, int result)
{
	int ret;
	struct sk_buff *skb = NULL;
	struct nlmsghdr *nlh = NULL;
	struct dcp_unsol_proxy_result *packet = NULL;

	spin_lock_bh(&g_dcp_send_lock);
	if (!g_user_space_pid || !g_dcp_nlfd) {
		hwlog_err("%s: cannot unsol port msg.\n", __func__);
		ret = -1;
		goto end;
	}

	skb = nlmsg_new(sizeof(struct dcp_unsol_proxy_result), GFP_ATOMIC);
	if (skb == NULL) {
		hwlog_err("%s: alloc skb fail.\n", __func__);
		ret = -1;
		goto end;
	}

	nlh = nlmsg_put(skb, 0, 0, 1, sizeof(struct dcp_unsol_proxy_result), 0);
	if (nlh == NULL) {
		kfree_skb(skb);
		skb = NULL;
		ret = -1;
		goto end;
	}

	if (result == 1)
		nlh->nlmsg_type = DCP_PROXY_SUCC;
	else
		nlh->nlmsg_type = DCP_PROXY_FAIL;
	packet = nlmsg_data(nlh);
	(void)memset_s(packet, sizeof(struct dcp_unsol_proxy_result),
		0, sizeof(struct dcp_unsol_proxy_result));
	packet->uid = uid,
	packet->result = result;
	// skb will be free in netlink_unicast
	ret = netlink_unicast(g_dcp_nlfd, skb, g_user_space_pid, MSG_DONTWAIT);
	hwlog_info("%s: netlink_unicast result %d.\n", __func__, ret);
	goto end;

end:
	spin_unlock_bh(&g_dcp_send_lock);
}

int notify_proxy_port(u32 uid, u16 low, u16 high)
{
	int ret;
	struct sk_buff *skb = NULL;
	struct nlmsghdr *nlh = NULL;
	struct dcp_port_range *packet = NULL;
	spin_lock_bh(&g_dcp_send_lock);
	if (!g_user_space_pid || !g_dcp_nlfd) {
		hwlog_err("%s: cannot unsol port msg.\n", __func__);
		ret = -1;
		goto end;
	}

	skb = nlmsg_new(sizeof(struct dcp_port_range), GFP_ATOMIC);
	if (skb == NULL) {
		hwlog_err("%s: alloc skb fail.\n", __func__);
		ret = -1;
		goto end;
	}

	nlh = nlmsg_put(skb, 0, 0, 1, sizeof(struct dcp_port_range), 0);
	if (nlh == NULL) {
		kfree_skb(skb);
		skb = NULL;
		ret = -1;
		goto end;
	}

	nlh->nlmsg_type = DCP_PORT_RANGE;
	packet = nlmsg_data(nlh);
	(void)memset_s(packet, sizeof(struct dcp_port_range), 0, sizeof(struct dcp_port_range));
	packet->uid = uid;
	packet->low = low;
	packet->high = high;
	// skb will be free in netlink_unicast
	ret = netlink_unicast(g_dcp_nlfd, skb, g_user_space_pid, MSG_DONTWAIT);
	hwlog_info("%s: netlink_unicast result %d.\n", __func__, ret);
	goto end;

end:
	spin_unlock_bh(&g_dcp_send_lock);
	return ret;
}

int notify_proxy_ready(u32 uid)
{
	int ret;
	struct sk_buff *skb = NULL;
	struct nlmsghdr *nlh = NULL;
	struct dcp_unsol_proxy_result *packet = NULL;
	spin_lock_bh(&g_dcp_send_lock);
	if (!g_user_space_pid || !g_dcp_nlfd) {
		hwlog_err("%s: cannot unsol port msg.\n", __func__);
		ret = -1;
		goto end;
	}

	skb = nlmsg_new(sizeof(struct dcp_unsol_proxy_result), GFP_ATOMIC);
	if (skb == NULL) {
		hwlog_err("%s: alloc skb fail.\n", __func__);
		ret = -1;
		goto end;
	}

	nlh = nlmsg_put(skb, 0, 0, 1, sizeof(struct dcp_unsol_proxy_result), 0);
	if (nlh == NULL) {
		kfree_skb(skb);
		skb = NULL;
		ret = -1;
		goto end;
	}

	nlh->nlmsg_type = DCP_PUSH_FOUND;
	packet = nlmsg_data(nlh);
	(void)memset_s(packet, sizeof(struct dcp_unsol_proxy_result),
		0, sizeof(struct dcp_unsol_proxy_result));
	packet->uid = uid;
	packet->result = 3; // 3 means push socket found
	// skb will be free in netlink_unicast
	ret = netlink_unicast(g_dcp_nlfd, skb, g_user_space_pid, MSG_DONTWAIT);
	hwlog_info("%s: netlink_unicast result %d, uid: %lu.\n",
		__func__, ret, uid);
	goto end;

end:
	spin_unlock_bh(&g_dcp_send_lock);
	return ret;
}

bool is_push_socket(struct sock *sk, u32 uid)
{
	int i;
	int index;
	u16 src_port;
	struct inet_sock *inet = NULL;
	struct push_stream_info *head = NULL;
	inet = inet_sk(sk);
	if (inet == NULL)
		return false;

	index = get_weixin_uid_index(uid);
	if (index < 0)
		return false;

	head = g_push_process_ctx[index].before_proxy_stream_list;
	src_port = htons(inet->inet_sport);
	for (i = 0; i < NUM_OF_RECORD_PORT; i++) {
		if (head[i].src_port != src_port)
			continue;
		if (head[i].key_words1_num > 2 || head[i].key_words2_num > 2)
			return true;
	}

	return false;
}

bool is_proxy_push_socket(u32 uid, u16 port)
{
	int i;
	int index;
	struct push_stream_info *head = NULL;
	index = get_weixin_uid_index(uid);
	if (index < 0)
		return false;

	head = g_push_process_ctx[index].after_proxy_stream_list;
	for (i = 0; i < NUM_OF_BIND_PORT; i++) {
		if (head[i].src_port != port)
			continue;
		if (head[i].key_words1_num > 1 && head[i].key_words2_num > 1)
			return true;
	}
	return false;
}

bool is_proxy_socket(struct sock *sk)
{
	u16 src_port;
	struct inet_sock *inet = NULL;
	inet = inet_sk(sk);
	if (inet == NULL)
		return false;

	src_port = htons(inet->inet_sport);
	if (is_port_in_proxy_range(src_port))
		return true;
	return false;
}

void destroy_push_socket(struct sock *sk, u32 state, u32 uid)
{
	if (state == DCP_NORMAL_STATE) {
		if (!is_push_socket(sk, uid))
			return;
	}

	if (state == DCP_PROXY_STATE) {
		if (!is_proxy_socket(sk))
			return;
	}

	if (sk->sk_state == TCP_ESTABLISHED || sk->sk_state == TCP_SYN_SENT) {
		local_bh_disable();
		bh_lock_sock(sk);
		if (!sock_flag(sk, SOCK_DEAD)) {
			sk->sk_err = ECONNABORTED;
			smp_wmb();
			sk->sk_error_report(sk);
			if (tcp_need_reset(sk->sk_state)) {
				hwlog_info("%s: success.\n", __func__);
				tcp_send_active_reset(sk, sk->sk_allocation);
			}
		}
		bh_unlock_sock(sk);
		local_bh_enable();
	}
}

void destroy_all_push_socket(u32 uid, u32 pids)
{
	u32 bucket;
	u8 state;
	struct sock *sk = NULL;
	struct hlist_nulls_node *node = NULL;
	spinlock_t *lock = NULL;
	state = get_proxy_state_by_uid(uid);
	if (state < DCP_NORMAL_STATE)
		return;

	for (bucket = 0; bucket <= tcp_hashinfo.ehash_mask; ++bucket) {
		if (hlist_nulls_empty(&tcp_hashinfo.ehash[bucket].chain))
			continue;
		lock = inet_ehash_lockp(&tcp_hashinfo, bucket);
		spin_lock_bh(lock);
		sk_nulls_for_each(sk, node, &tcp_hashinfo.ehash[bucket].chain) {
			if (!sk_fullsock(sk))
				continue;
			if (uid != dcp_get_uid_from_sock(sk))
				continue;
#ifdef CONFIG_HUAWEI_KSTATE
			if (pids != (u32)sk->sk_pid)
				continue;
#endif
			destroy_push_socket(sk, state, uid);
		}
		spin_unlock_bh(lock);
	}
}

void record_proxy_sock_port(struct sock *sk,
	struct tcphdr *tcph, u32 uid, u32 key)
{
	u32 i;
	int index;
	u16 src_port;
	u16 dst_port;
	struct push_stream_info *head = NULL;
	src_port = htons(tcph->source);
	dst_port = htons(tcph->dest);
	index = get_weixin_uid_index(uid);
	if (index < 0)
		return;

	head = g_push_process_ctx[index].after_proxy_stream_list;
	for (i = 0; i < NUM_OF_BIND_PORT; i++) {
		if (src_port != head[i].src_port ||
			dst_port != head[i].dst_port)
			continue;
		if (key == FIRST_KEY_PKT)
			head[i].key_words1_num++;
		if (key == SECOND_KEY_PKT)
			head[i].key_words2_num++;
		return;
	}

	for (i = 0; i < NUM_OF_BIND_PORT; i++) {
		if (head[i].src_port == 0) {
			head[i].src_port = src_port;
			head[i].dst_port = dst_port;
			if (key == FIRST_KEY_PKT)
				head[i].key_words1_num++;
			if (key == SECOND_KEY_PKT)
				head[i].key_words2_num++;
			break;
		}
	}
}

void record_pre_proxy_sock_port(struct tcphdr *tcph, u32 uid, u32 key, u32 flags)
{
	int i;
	int index;
	u16 src_port;
	u16 dst_port;
	struct push_stream_info *head = NULL;
	index = get_weixin_uid_index(uid);
	if (index < 0)
		return;

	head = g_push_process_ctx[index].before_proxy_stream_list;
	if (flags == 1) {
		src_port = htons(tcph->source);
		dst_port = htons(tcph->dest);
	} else {
		dst_port = htons(tcph->source);
		src_port = htons(tcph->dest);
	}
	for (i = 0; i < NUM_OF_RECORD_PORT; i++) {
		if (head[i].src_port == 0) {
			head[i].src_port = src_port;
			head[i].dst_port = dst_port;
			break;
		} else if (head[i].src_port == src_port) {
			break;
		} else {
			continue;
		}
	}

	if (i == NUM_OF_RECORD_PORT)
		return;

	if (key == FIRST_KEY_PKT)
		head[i].key_words1_num++;
	if (key == SECOND_KEY_PKT)
		head[i].key_words2_num++;
}

void record_proxy_sock_addrinfo(struct sock *sk,
	struct tcphdr *tcph, u32 uid)
{
	int i;
	int index;
	u16 src_port;
	u16 dst_port;
	bool is_ipv6_pkt = false;
	struct inet_sock *inet = NULL;
	struct proxy_socket_dst_info *dst_info = NULL;
	index = get_weixin_uid_index(uid);
	if (index < 0)
		return;

	is_ipv6_pkt = is_ipv6_packet(sk);
	if (is_ipv6_pkt)
		return;

	inet = inet_sk(sk);
	if (inet == NULL)
		return;

	dst_info = g_push_process_ctx[index].dst_info_list;
	src_port = htons(tcph->source);
	dst_port = htons(tcph->dest);
	for (i = 0; i < NUM_OF_BIND_PORT; i++) {
		if (dst_info[i].src_port == 0) {
			dst_info[i].src_port = src_port;
			dst_info[i].dst_info.sin_family = AF_INET;
			dst_info[i].dst_info.sin_port = dst_port;
			dst_info[i].dst_info.v4.sin_addr.s_addr = inet->inet_daddr;
			break;
		}
	}
}

void abnormal_process(u16 port, u32 uid, struct tcphdr *tcph)
{
	if (tcph->rst == 1 || tcph->fin == 1) {
		hwlog_info("%s port = %lu.\n", __func__, port);
		if (is_proxy_push_socket(uid, port)) {
			hwlog_err("%s port = %lu, it's push socket, rst = %lu, fin = %lu.\n",
				__func__, port, tcph->rst, tcph->fin);
			notify_proxy_result(uid, 0);
		}
	}
}

void process_hook_in(struct sock *sk, struct sk_buff *skb, struct tcphdr *tcph, struct iphdr *iph)
{
	u8 state;
	u16 dst_port;
	u32 uid;
	u32 key;
	uid = dcp_get_uid_from_sock(sk);
	if (get_weixin_uid_index(uid) < 0)
		return;

#ifdef CONFIG_HUAWEI_KSTATE
	if (get_weixin_pid_index((u32)sk->sk_pid) < 0)
		return;
#endif

	state = get_proxy_state_by_uid(uid);
	if (state == DCP_NORMAL_STATE) {
		key = is_push_skb(skb, tcph, iph);
		if (key > 0)
			record_pre_proxy_sock_port(tcph, uid, key, 0);
	} else {
		dst_port = htons(tcph->dest);
		if (!is_port_in_proxy_range(dst_port))
			return;
		abnormal_process(dst_port, uid, tcph);
	}
}

void process_hook_out(struct sock *sk, struct sk_buff *skb,
	struct tcphdr *tcph, struct iphdr *iph)
{
	u8 state;
	u16 src_port;
	u32 key;
	u32 uid;
	uid = dcp_get_uid_from_sock(sk);
	if (get_weixin_uid_index(uid) < 0)
		return;

#ifdef CONFIG_HUAWEI_KSTATE
	if (get_weixin_pid_index((u32)sk->sk_pid) < 0)
		return;
#endif

	state = get_proxy_state_by_uid(uid);
	if (state == DCP_PROXY_STATE) {
		src_port = htons(tcph->source);
		if (!is_port_in_proxy_range(src_port))
			return;

		if (tcph->syn == 1) {
			record_proxy_sock_addrinfo(sk, tcph, uid);
			return;
		}

		key = is_push_skb(skb, tcph, iph);
		if (key > 0)
			record_proxy_sock_port(sk, tcph, uid, key);
		abnormal_process(src_port, uid, tcph);
	}

	if (state == DCP_NORMAL_STATE) {
		key = is_push_skb(skb, tcph, iph);
		if (key > 0)
			record_pre_proxy_sock_port(tcph, uid, key, 1);
	}
}

unsigned int hook_v4(void *ops,
	struct sk_buff *skb, const struct nf_hook_state *state)
{
	struct sock *sk = NULL;
	struct iphdr *iph = NULL;
	struct tcphdr *tcph = NULL;
	if (state == NULL || skb == NULL)
		return NF_ACCEPT;

	sk = skb_to_full_sk(skb);
	if (sk == NULL)
		sk = state->sk;
	if (sk == NULL)
		return NF_ACCEPT;

	iph = ip_hdr(skb);
	if (iph == NULL || iph->protocol != IPPROTO_TCP)
		return NF_ACCEPT;

	tcph = tcp_hdr(skb);
	if (tcph == NULL)
		return NF_ACCEPT;

	process_hook_out(sk, skb, tcph, iph);
	return NF_ACCEPT;
}

unsigned int hook_v6(void *ops,
	struct sk_buff *skb, const struct nf_hook_state *state)
{
	(void)ops;
	(void)skb;
	(void)state;
	return NF_ACCEPT;
}

void proxy_check(u32 uid)
{
	int num = 0;
	u32 bucket;
	struct sock *sk = NULL;
	struct hlist_nulls_node *node = NULL;
	spinlock_t *lock = NULL;
	for (bucket = 0; bucket <= tcp_hashinfo.ehash_mask; bucket++) {
		if (hlist_nulls_empty(&tcp_hashinfo.ehash[bucket].chain))
			continue;
		lock = inet_ehash_lockp(&tcp_hashinfo, bucket);
		spin_lock_bh(lock);
		sk_nulls_for_each(sk, node, &tcp_hashinfo.ehash[bucket].chain) {
			if (!sk_fullsock(sk))
				continue;
			if (uid != dcp_get_uid_from_sock(sk))
				continue;
			if (!is_proxy_socket(sk))
				continue;
			if (sk->sk_state == TCP_ESTABLISHED || sk->sk_state == TCP_SYN_SENT)
				num++;
		}
		spin_unlock_bh(lock);
	}

	if (num > 0)
		notify_proxy_result(uid, 1);
	else
		notify_proxy_result(uid, 0);
}

void dcp_proxy_check_timer(struct timer_list *data)
{
	int i;
	u32 uid;
	for (i = 0; i < NUM_OF_WEIXIN_APP; i++) {
		uid = g_push_process_ctx[i].uid;
		if (uid == 0)
			continue;
		if (get_proxy_state(i) != DCP_PROXY_STATE)
			continue;
		if (g_push_process_ctx[i].is_notify_result)
			continue;
		proxy_check(uid);
		g_push_process_ctx[i].is_notify_result = 1;
	}
}

void dcp_push_check_timer(struct timer_list *data)
{
	int i;
	int j;
	u32 uid;
	struct push_stream_info *head = NULL;
	for (i = 0; i < NUM_OF_WEIXIN_APP; i++) {
		uid = g_push_process_ctx[i].uid;
		if (get_proxy_state(i) != DCP_NORMAL_STATE)
			continue;
		if (g_push_process_ctx[i].is_push_socket_finded)
			continue;
		hwlog_info("%s: uid: %lu.\n", __func__, uid);
		head = g_push_process_ctx[i].before_proxy_stream_list;
		for (j = 0; j < NUM_OF_RECORD_PORT; j++) {
			if (head[j].src_port == 0 || head[j].dst_port == 0)
				continue;
			if (head[j].key_words1_num > 2 || head[j].key_words2_num > 2) {
				notify_proxy_ready(uid);
				g_push_process_ctx[i].is_push_socket_finded = 1;
				break;
			}
		}
	}

	if ((g_push_process_ctx[0].proxy_state == DCP_NORMAL_STATE &&
		!g_push_process_ctx[0].is_push_socket_finded) ||
		(g_push_process_ctx[1].proxy_state == DCP_NORMAL_STATE &&
		!g_push_process_ctx[1].is_push_socket_finded)) {
		g_dcp_push_check_timer.expires = jiffies + g_push_timer_count * DCP_PUSH_CHECK;
		add_timer(&g_dcp_push_check_timer);
		g_push_timer_count++;
	}
}

void process_proxy_enable(u32 uid)
{
	int index;
	u16 low;
	u16 high;
	index = get_weixin_uid_index(uid);
	if (index < 0)
		return;

	if (get_proxy_state(index) != DCP_NORMAL_STATE) {
		hwlog_err("%s, it's in proxy state.\n", __func__);
		return;
	}

	find_idle_port(&low, &high);
	(void)notify_proxy_port(uid, low, high);
	destroy_all_push_socket(uid, g_push_process_ctx[index].pids);
	set_proxy_state(index, DCP_PROXY_STATE);
	if (timer_pending(&g_dcp_proxy_check_timer))
		del_timer(&g_dcp_proxy_check_timer);
	g_dcp_proxy_check_timer.expires = jiffies + DCP_PROXY_CHECK;
	add_timer(&g_dcp_proxy_check_timer);
}

void process_proxy_disable(u32 uid)
{
	int index;
	index = get_weixin_uid_index(uid);
	if (index < 0)
		return;

	if (get_proxy_state(index) != DCP_PROXY_STATE) {
		hwlog_err("%s, it's not in proxy state.\n", __func__);
		return;
	}

	g_push_process_ctx[index].is_push_socket_finded = 0;
	g_push_process_ctx[index].is_notify_result = 0;
	destroy_all_push_socket(uid, g_push_process_ctx[index].pids);
	clear_push_process_ctx(index);
	set_proxy_state(index, DCP_NORMAL_STATE);
	g_push_timer_count = 1;
	if (timer_pending(&g_dcp_push_check_timer))
		del_timer(&g_dcp_push_check_timer);
	g_dcp_push_check_timer.expires = jiffies + DCP_PUSH_CHECK;
	add_timer(&g_dcp_push_check_timer);
	hwlog_info("%s: uid: %lu.\n", __func__, uid);
}

void process_app_update(u32 uid, u32 pid)
{
	int i;
	if (uid <= MIN_APP_UID)
		return;
	if (get_weixin_uid_index(uid) >= 0)
		return;

	for (i = 0; i < NUM_OF_WEIXIN_APP; i++) {
		if (g_push_process_ctx[i].uid > 0)
			continue;
		g_push_process_ctx[i].uid = uid;
		g_push_process_ctx[i].pids = pid;
		set_proxy_state(i, DCP_NORMAL_STATE);
		hwlog_info("%s: success. uid: %lu, pid: %lu.\n", __func__, uid, pid);
		break;
	}

	if (i == NUM_OF_WEIXIN_APP) {
		hwlog_info("%s: failed. uid: %lu, pid: %lu.\n", __func__, uid, pid);
		return;
	}

	g_push_timer_count = 1;
	if (timer_pending(&g_dcp_push_check_timer))
		del_timer(&g_dcp_push_check_timer);
	g_dcp_push_check_timer.expires = jiffies + DCP_PUSH_CHECK;
	add_timer(&g_dcp_push_check_timer);
}

void process_app_crash(u32 uid)
{
	int index;
	index = get_weixin_uid_index(uid);
	if (index < 0)
		return;

	destroy_all_push_socket(uid, g_push_process_ctx[index].pids);
	g_push_process_ctx[index].uid = 0;
	g_push_process_ctx[index].pids = 0;
	g_push_process_ctx[index].is_push_socket_finded = 0;
	g_push_process_ctx[index].is_notify_result = 0;
	clear_push_process_ctx(index);
	set_proxy_state(index, DCP_INIT_STATE);
	hwlog_info("%s: %lu rollback to init state.\n", __func__, uid);
}

void process_token_update(char *token)
{
	u32 ret;
	if (token == NULL || strlen(token) < LEN_OF_TOKEN) {
		hwlog_err("%s error.\n", __func__);
		return;
	}

	ret = memcpy_s(g_token_info, LEN_OF_TOKEN, token, LEN_OF_TOKEN);
	if (ret != 0)
		hwlog_err("%s: memcpy_s token fail.\n", __func__);
}

void dcp_netlink_receive(struct sk_buff *__skb)
{
	struct nlmsghdr *nlh = NULL;
	struct sk_buff *skb = NULL;
	struct dcp_app_info *hmsg = NULL;
	if (__skb == NULL)
		return;

	skb = skb_get(__skb);
	if (skb == NULL)
		return;

	mutex_lock(&dcp_receive_sem);
	if (skb->len < NLMSG_HDRLEN)
		goto skb_free;

	nlh = nlmsg_hdr(skb);
	if (nlh == NULL)
		goto skb_free;

	if ((nlh->nlmsg_len < sizeof(struct nlmsghdr)) ||
		(skb->len < nlh->nlmsg_len))
		goto skb_free;

	hmsg = (struct dcp_app_info *)nlh;
	hwlog_err("%s: type = %d.\n", __func__, nlh->nlmsg_type);
	switch (nlh->nlmsg_type) {
	case NL_DCP_MSG_REG:
		g_user_space_pid = nlh->nlmsg_pid;
		break;
	case NL_DCP_MSG_UNREG:
		g_user_space_pid = 0;
		break;
	case NL_DCP_MSG_ENABLE_PXY:
		process_proxy_enable(hmsg->uid);
		break;
	case NL_DCP_MSG_DISABLE_PXY:
		process_proxy_disable(hmsg->uid);
		break;
	case NL_DCP_MSG_SET_APP_INFO:
		process_app_update(hmsg->uid, hmsg->pids);
		break;
	case NL_DCP_MSG_SET_TOKEN:
		process_token_update(hmsg->token);
		break;
	case NL_DCP_MSG_PROCESS_DIED:
		process_app_crash(hmsg->uid);
		break;
	default:
		break;
	}

skb_free:
	kfree_skb(skb);
	mutex_unlock(&dcp_receive_sem);
}

void dcp_hook_dl_stub(struct sock *sk, struct sk_buff *skb)
{
	struct iphdr *iph = NULL;
	struct tcphdr *tcph = NULL;
	if (sk == NULL || skb == NULL)
		return;

	iph = ip_hdr(skb);
	if (iph == NULL || iph->protocol != IPPROTO_TCP)
		return;

	tcph = tcp_hdr(skb);
	if (tcph == NULL)
		return;

	if (is_ipv6_packet(sk))
		return;

	process_hook_in(sk, skb, tcph, iph);
}

void dcp_bind_port_range(struct sock *sk, u32 *low, u32 *high)
{
	int index = -1;
	if (!sk)
		return;

#ifdef CONFIG_HUAWEI_KSTATE
	index = get_weixin_pid_index((u32)sk->sk_pid);
	if (index < 0)
		return;
#endif

	if (get_proxy_state(index) != DCP_PROXY_STATE)
		return;

	if (is_ipv6_packet(sk)) {
		hwlog_err("%s: sock is ipv6.\n", __func__);
		return;
	}

	if (g_push_process_ctx[index].bind_port_num >= NUM_OF_BIND_PORT)
		return;

	*low = LOW_PORT;
	*high = HIGH_PORT;
	g_push_process_ctx[index].bind_port_num++;
	hwlog_info("%s: bind port success.\n", __func__);
}

void dcp_send_data_packet(struct sock *sk)
{
	int index = -1;
	u16 src_port;
	struct inet_sock *inet = NULL;
	if (sk == NULL || sk->is_first_packet != 0)
		return;

	sk->is_first_packet = 1;
#ifdef CONFIG_HUAWEI_KSTATE
	index = get_weixin_pid_index((u32)sk->sk_pid);
	if (index < 0)
		return;
#endif

	if (get_proxy_state(index) != DCP_PROXY_STATE)
		return;

	if (is_ipv6_packet(sk))
		return;

	inet = inet_sk(sk);
	src_port = htons(inet->inet_sport);
	if (!is_port_in_proxy_range(src_port))
		return;

	hwlog_info("%s: src_port = %lu.\n", __func__, src_port);
	send_data_packet(sk, src_port);
}

void dcp_push_ctx_init(void)
{
	int i;
	for (i = 0; i < NUM_OF_WEIXIN_APP; i++) {
		g_push_process_ctx[i].uid = 0;
		g_push_process_ctx[i].pids = 0;
		set_proxy_state(i, DCP_INIT_STATE);
		clear_push_process_ctx(i);
	}
	(void)memset_s(g_token_info, LEN_OF_TOKEN, 0, LEN_OF_TOKEN);
	sema_init(&g_dcp_netlink_sema, 0);
	spin_lock_init(&g_dcp_send_lock);
	spin_lock_init(&g_proxy_state_lock);

	timer_setup(&g_dcp_push_check_timer, dcp_push_check_timer, 0);
	g_dcp_push_check_timer.expires = jiffies + DCP_PUSH_CHECK;
	timer_setup(&g_dcp_proxy_check_timer, dcp_proxy_check_timer, 0);
	g_dcp_proxy_check_timer.expires = jiffies + DCP_PROXY_CHECK;
}

void dcp_netlink_init(void)
{
	struct netlink_kernel_cfg dcp_nl_cfg = {
		.input = dcp_netlink_receive,
	};

	g_dcp_nlfd = netlink_kernel_create(&init_net,
		NETLINK_DCP_EVENT_NL, &dcp_nl_cfg);
	if (!g_dcp_nlfd) {
		hwlog_err("%s fail to create netlink fd.\n", __func__);
		return;
	}

	hwlog_info("%s success to create netlink fd.\n", __func__);
}

struct nf_hook_ops net_hooks[] = {
	{
		.hook = hook_v4,
#if (LINUX_VERSION_CODE < KERNEL_VERSION(4, 4, 0))
		.owner = THIS_MODULE,
#endif
		.pf = AF_INET,
		.hooknum = NF_INET_LOCAL_OUT,
		.priority = NF_IP_PRI_MANGLE + 1,
	},
	{
		.hook = hook_v6,
#if (LINUX_VERSION_CODE < KERNEL_VERSION(4, 4, 0))
		.owner = THIS_MODULE,
#endif
		.pf = AF_INET6,
		.hooknum = NF_INET_LOCAL_OUT,
		.priority = NF_IP_PRI_MANGLE + 1,
	}
};

int __init dcp_handle_module_init(void)
{
	u32 ret;
#if (LINUX_VERSION_CODE < KERNEL_VERSION(4, 14, 0))
	ret = nf_register_hooks(net_hooks, ARRAY_SIZE(net_hooks));
#else
	ret = nf_register_net_hooks(&init_net, net_hooks,
		ARRAY_SIZE(net_hooks));
#endif
	hwlog_info("network_dcp_handle nf_init_in ret=%d.", ret);
	dcp_netlink_init();
	dcp_push_ctx_init();
	return 0;
}

void __exit dcp_handle_module_exit(void)
{
	if (g_dcp_nlfd && g_dcp_nlfd->sk_socket) {
		sock_release(g_dcp_nlfd->sk_socket);
		g_dcp_nlfd = NULL;
	}
#if (LINUX_VERSION_CODE < KERNEL_VERSION(4, 14, 0))
	nf_unregister_hooks(net_hooks, ARRAY_SIZE(net_hooks));
#else
	nf_unregister_net_hooks(&init_net, net_hooks, ARRAY_SIZE(net_hooks));
#endif
}

module_init(dcp_handle_module_init);
module_exit(dcp_handle_module_exit);
