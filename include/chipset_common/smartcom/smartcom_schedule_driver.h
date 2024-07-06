/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2022. All rights reserved.
 */
#ifndef __SMARTCOM_SCHEDULE_DRIVER_H__
#define __SMARTCOM_SCHEDULE_DRIVER_H__

#include <linux/version.h>
#include <net/sock.h>
#include <linux/socket.h>
#include <linux/in.h>
#include <linux/in6.h>
#include <linux/spinlock.h>

#define UID_APP 200000
#define UID_INVALID_APP 0
#define INDEX_INVALID (-1)
#define SMARTCOM_TRUE_VALUE  1
#define SMARTCOM_SCHEDULE_DRIVER_DEFAULT_NET_ID 0
#define SMARTCOM_SCHEDULE_DRIVER_NET_ID_MASK 0xff
#define SMARTCOM_MAX_HOST_LEN  60
#define SMARTCOM_MIN_HTTP_LEN  100
#define SMARTCOM_PORT_80 80
#define SMARTCOM_PORT_443 443
#define COMMON_HOST_PREFIX  "*."
#define COMMON_HOST_PREFIX_LEN  2
#define HTTP_REQUEST_GET_HOST_STR "Host: "
#define HTTP_REQUEST_ENTER_STR "\r\n"
#define IPV6_ADDR_STR_SEP  ":"
#define IPV4_ADDR_STR_SEP  "."
#define MAX_IPV4_ADDR_STR_LEN 15
#define MIN_IPV4_ADDR_STR_LEN 7
#define IPV4_ADDR_STR_SEG_NUM 3
#define IPV6_ADDR32_SEG_NUM 4
#define INVALID_IFACE_NAME  "none"
#define SMARTCOM_MAX_ACC_APP 5
#define SMARTCOM_UID_ACC_AGE_MAX 1000
#define SMARTCOM_SPEED_CTRL_BASE_WIN_SIZE 10000
#define FAST_SYN_COUNT 5
#define MIN_JIFFIE 1

#define SMARTCOM_WLAN0_IFNAME smartcom_schedule_driver_get_network_iface_name(SMARTCOM_SCHEDULE_DRIVER_NET_WLAN0)
#define SMARTCOM_CELL0_IFNAME smartcom_schedule_driver_get_network_iface_name(SMARTCOM_SCHEDULE_DRIVER_NET_CELL0)
#define SMARTCOM_WLAN1_IFNAME smartcom_schedule_driver_get_network_iface_name(SMARTCOM_SCHEDULE_DRIVER_NET_WLAN1)
#define SMARTCOM_CELL1_IFNAME smartcom_schedule_driver_get_network_iface_name(SMARTCOM_SCHEDULE_DRIVER_NET_CELL1)
#define SMARTCOM_WLAN2_IFNAME smartcom_schedule_driver_get_network_iface_name(SMARTCOM_SCHEDULE_DRIVER_NET_WLAN2)

#define IFNAMSIZ 16

#define IP_DEBUG 0

#define ip6_addr_block1(ip6_addr) (ntohs((ip6_addr).s6_addr16[0]) & 0xffff)
#define ip6_addr_block2(ip6_addr) (ntohs((ip6_addr).s6_addr16[1]) & 0xffff)
#define ip6_addr_block3(ip6_addr) (ntohs((ip6_addr).s6_addr16[2]) & 0xffff)
#define ip6_addr_block4(ip6_addr) (ntohs((ip6_addr).s6_addr16[3]) & 0xffff)
#define ip6_addr_block5(ip6_addr) (ntohs((ip6_addr).s6_addr16[4]) & 0xffff)
#define ip6_addr_block6(ip6_addr) (ntohs((ip6_addr).s6_addr16[5]) & 0xffff)
#define ip6_addr_block7(ip6_addr) (ntohs((ip6_addr).s6_addr16[6]) & 0xffff)
#define ip6_addr_block8(ip6_addr) (ntohs((ip6_addr).s6_addr16[7]) & 0xffff)

#if IP_DEBUG
#define IPV4_FMT "%u.%u.%u.%u"
#define ipv4_info(addr) \
	((unsigned char *)&(addr))[0], \
	((unsigned char *)&(addr))[1], \
	((unsigned char *)&(addr))[2], \
	((unsigned char *)&(addr))[3]

#define IPV6_FMT "%x:%x:%x:%x:%x:%x:%x:%x"
#define ipv6_info(addr) \
	ip6_addr_block1(addr), \
	ip6_addr_block2(addr), \
	ip6_addr_block3(addr), \
	ip6_addr_block4(addr), \
	ip6_addr_block5(addr), \
	ip6_addr_block6(addr), \
	ip6_addr_block7(addr), \
	ip6_addr_block8(addr)

#else
#define IPV4_FMT "%u.%u.*.*"
#define ipv4_info(addr) \
	((unsigned char *)&(addr))[0], \
	((unsigned char *)&(addr))[1]

#define IPV6_FMT "%x:***:%x"
#define ipv6_info(addr) \
	ip6_addr_block1(addr), \
	ip6_addr_block8(addr)
#endif

#define SMARTCOM_SCHEDULE_DRIVER_ACC_HIGH 0x5A

typedef enum {
	SMARTCOM_SCHEDULE_DRIVER_NET_INVALID = -1,
	SMARTCOM_SCHEDULE_DRIVER_NET_WLAN0,
	SMARTCOM_SCHEDULE_DRIVER_NET_CELL0,
	SMARTCOM_SCHEDULE_DRIVER_NET_WLAN1,
	SMARTCOM_SCHEDULE_DRIVER_NET_CELL1,
	SMARTCOM_SCHEDULE_DRIVER_NET_WLAN2,
	SMARTCOM_SCHEDULE_DRIVER_NET_MAX_NUM,
	SMARTCOM_SCHEDULE_DRIVER_NET_DEFAULT = 15,
} smartcom_schedule_driver_net_no;

typedef enum {
	SMARTCOM_SCHEDULE_DRIVER_IP_TYPE_INVALID,
	SMARTCOM_SCHEDULE_DRIVER_IP_TYPE_V4,
	SMARTCOM_SCHEDULE_DRIVER_IP_TYPE_V6,
	SMARTCOM_SCHEDULE_DRIVER_IP_TYPE_V4V6
} smartcom_schedule_driver_ip_type;

struct smartcom_schedule_driver_acc_app_info {
	uid_t     uid; /* The uid of accelerate Application */
	uint16_t  age;
	uint16_t  reverse;
};

struct smartcom_schedule_driver_speed_ctrl_info {
	uid_t     uid; /* The uid of foreground Application */
	uint32_t  size; /* The grade of speed control */
	spinlock_t stlocker; /* The Guard Lock of this unit */
};

struct smartcom_schedule_driver_speed_ctrl_data {
	uid_t     uid; /* The uid of foreground Application */
	uint32_t  size; /* The grade of speed control */
};

struct smartcom_schedule_driver_network_info {
	int32_t net_type;
	int32_t net_id;
	int32_t is_validated;
	int32_t is_default;
	char iface_name[IFNAMSIZ];
};

void smartcom_schedule_driver_init(void);
int smartcom_schedule_driver_clear(void);
bool smartcom_schedule_driver_hook_ul_stub(struct sock *pstSock);
void smartcom_schedule_driver_set_acc_state(struct sock *pst_sock);
void smartcom_schedule_driver_speedctrl_winsize(struct sock *pstSock, uint32_t *win);
void smartcom_schedule_driver_fastsyn(struct sock *pstSock);
void smartcom_schedule_driver_evt_proc(int32_t event, const void *data, uint16_t len);
bool smartcom_schedule_driver_check_ip_addrss(struct sockaddr *addr);
bool smartcom_schedule_driver_check_ip_is_private(struct sockaddr *addr);
char *smartcom_schedule_driver_get_network_iface_name(int net_type);
void smartcom_schedule_driver_set_speedctrl(struct smartcom_schedule_driver_speed_ctrl_info *speedctrl_info,
	uid_t uid_value, uint32_t size);

#endif
