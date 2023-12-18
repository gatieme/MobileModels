/*
 * hw_klinkaware.c
 *
 * This file use to aware link and report it
 *
 * Copyright (c) 2022-2022 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#include <securec.h>
#include <net/sock.h>
#include <linux/err.h>
#include <linux/kernel.h>
#include <linux/skbuff.h>
#include <linux/inet.h>

#include <huawei_platform/power/hw_kstate.h>
#include <huawei_platform/power/hw_kcollect.h>
#include <huawei_platform/power/hw_klinkaware.h>

typedef enum {
	MESSAGE_UNKNOW = -1,
	MESSAGE_CALL = 1,
	MESSAGE_CHAR
}message_type;

#define BASE			10
#define KEY_UID_MAX		2
#define KEY_WORD_MAX		4
#define DEFAULT_KEY_DATA_LEN	50 // call message feature data len>100,first four bytes like key word below
#define MC_ADD          1
#define MC_DEL          0

static char pg_mc_proxy_addr[IPV4_MAX_LEN];
static int key_uids[KEY_UID_MAX];
static unsigned int key_data_len = DEFAULT_KEY_DATA_LEN;
static uint8_t key_word[KEY_WORD_MAX] = {0x17, 0xf1, 0x04, 0x00};

static void process_dl_data(struct sock *sk, uint8_t *user_data, unsigned int len);
static int process_dl_proxy_data(struct sock *sk);

void pg_hook_dl_stub(struct sock *sk, struct sk_buff *skb, unsigned int len)
{
	uint8_t *user_data;

	if (IS_ERR_OR_NULL(sk)) {
		pr_err("invalid parameter");
		return;
	}

	if (IS_ERR_OR_NULL(skb)) {
		pr_err("invalid parameter");
		return;
	}

	if (process_dl_proxy_data(sk) == 0)
		return;

	if (skb->len < len + KEY_WORD_MAX)
		return;

	user_data = skb->data + len;
	process_dl_data(sk, user_data, skb->len - len);
}

int set_key_uid(const char *info)
{
	int i;
	int uid;

	if (IS_ERR_OR_NULL(info)) {
		pr_err("invalid parameter");
		return -1;
	}

	uid = simple_strtol(info, NULL, BASE);
	if (uid < 0) {
		memset_s(&key_uids[0], sizeof(key_uids), 0, sizeof(key_uids));
		return 0;
	}

	for (i = 0; i < KEY_UID_MAX; i++) {
		if (key_uids[i] == 0) {
			key_uids[i] = uid;
			break;
		}
	}

	return 0;
}

static bool is_match_key_uid(uid_t uid)
{
	int i;
	bool match = false;

	for (i = 0; i < KEY_UID_MAX; i++) {
		if (uid == key_uids[i]) {
			match = true;
			break;
		}
	}

	return match;
}

static bool is_match_mc_addr(__be32 addr)
{
	pr_info("proxy mc addr = %s, is corrent = %d", pg_mc_proxy_addr, addr == in_aton(pg_mc_proxy_addr));
	if (pg_mc_proxy_addr == NULL || strlen(pg_mc_proxy_addr) == 0)
		return false;
	return addr == in_aton(pg_mc_proxy_addr);
}

static void process_dl_data(struct sock *sk, uint8_t *user_data, unsigned int len)
{
	bool is_care = false;
	int type;
	int i;
	uid_t uid;

	uid = sock_i_uid(sk).val;
	if (!is_match_key_uid(uid))
		return;

	if (len < key_data_len)
		return;

	if (memcmp(&key_word[0], user_data, KEY_WORD_MAX) == 0) {
		type = MESSAGE_CALL;
		report_link_info(type, uid);
	}
}

static int process_dl_proxy_data(struct sock *sk)
{
	uid_t uid;

	uid = sock_i_uid(sk).val;
	if (!is_match_key_uid(uid))
		return -1 ;

	return hw_packet_cb(uid, -1);
}

void pg_hook_mc_add(struct sock *sk, __be32 addr)
{
	if (!is_match_mc_addr(addr))
		return;
	uid_t uid;
	uid = sock_i_uid(sk).val;
	pr_info("pg hook mc add, uid = %d", uid);
	report_igmp_info(MC_ADD, uid);
}

void pg_hook_mc_del(struct sock *sk, __be32 addr)
{
	if (!is_match_mc_addr(addr))
		return;
	uid_t uid;
	uid = sock_i_uid(sk).val;
	pr_info("pg hook mc del, uid = %d", uid);
	report_igmp_info(MC_DEL, uid);
}

int set_proxy_addr(const char *info)
{
	if (memcpy_s(pg_mc_proxy_addr, IPV4_MAX_LEN, info, IPV4_MAX_LEN) != EOK) {
		pr_err("global mc proxy addr set failed\n");
		return -1;
	}
	return 0;
}


char *pg_get_proxy_addr(void)
{
	return pg_mc_proxy_addr;
}