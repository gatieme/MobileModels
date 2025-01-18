/*
 * cloud_network_device.c
 *
 * cloud network kernel module implementation
 *
 * Copyright (c) 2023-2023 Huawei Technologies Co., Ltd.
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

#include "cloud_network_device.h"
#include <linux/module.h>
#include <linux/init.h>
#include <linux/netdevice.h>
#include <linux/etherdevice.h>
#include <linux/platform_device.h>
#include <linux/inetdevice.h>
#include <linux/mm.h>
#include <linux/device.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/skbuff.h>
#include <linux/netlink.h>
#include <linux/moduleparam.h>
#include <net/sock.h>
#include <linux/delay.h>
#include <linux/mutex.h>
#include <linux/spinlock.h>
#include <linux/notifier.h>
#include <linux/reboot.h>
#include <linux/signal.h>
#include <linux/interrupt.h>
#include <securec.h>
#include <linux/sort.h>
#include <linux/version.h>
#include <linux/io.h>
#include <linux/types.h>
#include <linux/timer.h>
#include <linux/gfp.h>
#include <net/xfrm.h>
#include <linux/jhash.h>
#include <linux/rtnetlink.h>
#include <net/netfilter/nf_conntrack.h>
#include <net/netfilter/nf_conntrack_core.h>
#include <net/netfilter/nf_conntrack_helper.h>
#include <net/netfilter/nf_conntrack_seqadj.h>
#include <net/netfilter/nf_conntrack_zones.h>
#include <net/netfilter/nf_nat.h>
#include <net/netfilter/nf_nat_helper.h>
#include <uapi/linux/netfilter/nf_nat.h>

#include "cloud_network.h"
#include "cloud_network_utils.h"
#include "cloud_network_param.h"
#include "cloud_network_option.h"
#include "cloud_network_detect.h"
#include "cloud_network_tx.h"
#include "cloud_network_rx.h"

#define TRIGGER_RX_MONITOR_TIMER_MS 250

struct hlist_head *dev_htable __read_mostly;
unsigned int dev_htable_size __read_mostly;
__cacheline_aligned_in_smp rwlock_t dev_htable_locks[DEV_HTABLE_LOCK_NUM];
atomic_t dev_htable_count;
/* available link paths : bit0 WiFi,bit1 primary modem,bit2 secondary modem */
static unsigned int available_paths = 0;
static unsigned int available_paths_last = 0;
static u64 last_traffic[ROLLE_MAX] = {0};
static DEFINE_SPINLOCK(available_paths_lock);

static atomic_t tx_rx_state;
/* less-device tx more-device rx tx_rx_state: 1 need trigger rx, 0 not need */
static atomic_t trigger_rx;
struct hrtimer trigger_rx_monitor_timer;
atomic_t device_rx_pkt[ROLLE_MAX];
struct cloud_network_device_tun device_tun;

struct net_device_stat net_devices[ROLLE_MAX] __read_mostly;
struct net_device_match dev_match[ROLLE_MAX] __read_mostly;
static const char modem_name[ROLLE_MAX][IFNAMSIZ] = {"wlan0", "rmnet0", "rmnet3"};
static struct net_dev_traffic_stat traffic_stat[ROLLE_MAX];

static int cloud_network_device_event(struct notifier_block *this,
	unsigned long event, void *ptr);
static int cloud_network_inet_event(struct notifier_block *this,
	unsigned long event, void *ptr);

static struct notifier_block cloud_network_dev_notifier = {
	.notifier_call = cloud_network_device_event,
};

static struct notifier_block cloud_network_inet_notifier = {
	.notifier_call = cloud_network_inet_event,
};

__be32 cloud_network_get_tun_ip(void)
{
	__be32 ip = 0;
	if ((atomic_read(&(device_tun.ip_enable)) != 1) || (atomic_read(&(device_tun.dev_enable)) != 1))
		return 0;
	spin_lock_bh(&device_tun.lock);
	ip = device_tun.ip;
	spin_unlock_bh(&device_tun.lock);
	return ip;
}

struct net_device *cloud_network_get_tun(void)
{
	struct net_device *dev = NULL;
	if ((atomic_read(&(device_tun.ip_enable)) != 1) || (atomic_read(&(device_tun.dev_enable)) != 1))
		return dev;
	spin_lock_bh(&device_tun.lock);
	dev = device_tun.dev;
	spin_unlock_bh(&device_tun.lock);
	return dev;
}

bool tun_dev_match_by_name(struct net_device *dev)
{
	if (unlikely(dev == NULL))
		return false;

	/* tun0/vnic-tun device name match */
	if ((dev->name[NUM_0] == 't' && dev->name[NUM_1] == 'u' && dev->name[NUM_2] == 'n' && dev->name[NUM_3] == '0') ||
		(dev->name[NUM_0] == 'v' && dev->name[NUM_1] == 'n' && dev->name[NUM_2] == 'i' && dev->name[NUM_3] == 'c'))
		return true;

	return false;
}

bool cloud_network_tun_device_skb_match(struct sk_buff *skb)
{
	struct iphdr *iph = NULL;
	bool ret = false;

	if (unlikely(skb == NULL))
		return false;

	if ((atomic_read(&(device_tun.ip_enable)) != 1) || (atomic_read(&(device_tun.dev_enable)) != 1))
		return false;

	if (!tun_dev_match_by_name(skb->dev))
		return false;

	iph = (struct iphdr *)skb->data;
	if (iph->protocol == IPPROTO_UDP)
		return true;

	spin_lock_bh(&device_tun.lock);
	if (iph->saddr == device_tun.ip)
		ret = true;
	spin_unlock_bh(&device_tun.lock);
	return ret;
}

static void set_cloud_network_tun_ip_up(struct net_device *dev, const struct in_ifaddr *ifa)
{
	if (unlikely(dev == NULL || ifa == NULL))
		return;

	if (!tun_dev_match_by_name(dev))
		return;

	dev->wanted_features &= ~(NETIF_F_GSO | NETIF_F_TSO);
	netdev_update_features(dev);

	spin_lock_bh(&device_tun.lock);
	device_tun.dev = dev;
	device_tun.ip = ifa->ifa_address;
	spin_unlock_bh(&device_tun.lock);
	atomic_set(&(device_tun.ip_enable), 1);
	log_info("ip up ifindex %d name %s", dev->ifindex, dev->name);
	return;
}

static void set_cloud_network_tun_ip_down(struct net_device *dev)
{
	if (unlikely(dev == NULL))
		return;

	if (!tun_dev_match_by_name(dev))
		return;

	atomic_set(&(device_tun.ip_enable), 0);
	spin_lock_bh(&device_tun.lock);
	device_tun.dev = NULL;
	device_tun.ip = 0;
	spin_unlock_bh(&device_tun.lock);
	log_info("ip down ifindex %d name %s", dev->ifindex, dev->name);
	return;
}

static void set_cloud_network_tun_dev_up(struct net_device *dev)
{
	if (unlikely(dev == NULL))
		return;

	if (!tun_dev_match_by_name(dev))
		return;

	atomic_set(&(device_tun.dev_enable), 1);
	log_info("dev up ifindex %d name %s", dev->ifindex, dev->name);
	return;
}

static void set_cloud_network_tun_dev_down(struct net_device *dev)
{
	if (unlikely(dev == NULL))
		return;

	if (!tun_dev_match_by_name(dev))
		return;

	atomic_set(&(device_tun.dev_enable), 0);
	spin_lock_bh(&device_tun.lock);
	device_tun.dev = NULL;
	device_tun.ip = 0;
	spin_unlock_bh(&device_tun.lock);
	log_info("dev down ifindex %d name %s", dev->ifindex, dev->name);
	return;
}

static void cloud_network_tun_init(void)
{
	spin_lock_init(&device_tun.lock);
	atomic_set(&(device_tun.ip_enable), 0);
	atomic_set(&(device_tun.dev_enable), 0);
	device_tun.ip = 0;
	device_tun.dev = NULL;
	return;
}

void set_trigger_rx(int val)
{
	atomic_set(&trigger_rx, val);
}

int get_trigger_rx(void)
{
	return atomic_read(&trigger_rx);
}

static void start_trigger_rx_monitor_timer(void)
{
	if (!hrtimer_active(&trigger_rx_monitor_timer))
		hrtimer_start(&trigger_rx_monitor_timer,
			ms_to_ktime(TRIGGER_RX_MONITOR_TIMER_MS),
			HRTIMER_MODE_REL_PINNED);
	return;
}

static void stop_trigger_rx_monitor_timer(void)
{
	if (hrtimer_active(&trigger_rx_monitor_timer))
		hrtimer_cancel(&trigger_rx_monitor_timer);
	return;
}

/* data packets, not include only option packet */
void device_rx_pkt_statistic(int device_id)
{
	struct link_info link_info_data;

	if (unlikely(device_id < 0 || device_id >= ROLLE_MAX)) {
		log_err("device id is invalid, error");
		return;
	}

	atomic_inc(&(device_rx_pkt[device_id]));

	if (get_link_info(&link_info_data) != SUCCESS)
		return;

	if ((link_info_data.scene == SCENE_MOEM_MODEM &&
		device_id == ROLLE_SECONDARY_MODEM) ||
		(link_info_data.scene == SCENE_WIFI_MODEM &&
		device_id == ROLLE_PRIMARY_MODEM))
		set_trigger_rx(0);
	return;
}

static void device_rx_pkt_statistic_reset(void)
{
	log_info("device rx pkt statistic reset");
	for (int i = 0; i < ROLLE_MAX; i++)
		atomic_set(&(device_rx_pkt[i]), 0);

	return;
}

static enum hrtimer_restart trigger_rx_monitor_timer_handle(struct hrtimer *timer)
{
	struct link_info link_info_data;
	int device_id_check = 0;
	int device_id_cmp = 0;

	log_info("trigger rx monitor handle");
	if (!is_cloud_network_enable())
		return HRTIMER_NORESTART;
	if (get_link_info(&link_info_data) != SUCCESS)
		return HRTIMER_NORESTART;

	log_info("scene %d", link_info_data.scene);
	if (link_info_data.scene == SCENE_MOEM_MODEM) {
		device_id_check = ROLLE_SECONDARY_MODEM;
		device_id_cmp = ROLLE_PRIMARY_MODEM;
	} else if (link_info_data.scene == SCENE_WIFI_MODEM) {
		device_id_check = ROLLE_PRIMARY_MODEM;
		device_id_cmp = ROLLE_PRIMARY_WIFI;
	} else {
		return HRTIMER_NORESTART;
	}

	if (atomic_read(&(device_rx_pkt[device_id_cmp])) > 0 &&
		atomic_read(&(device_rx_pkt[device_id_check])) == 0)
		set_trigger_rx(1);

	if (atomic_read(&tx_rx_state) == TX_RX_STATE_1T2R)
		hrtimer_start(&trigger_rx_monitor_timer,
			ms_to_ktime(TRIGGER_RX_MONITOR_TIMER_MS), HRTIMER_MODE_REL_PINNED);

	device_rx_pkt_statistic_reset();

	return HRTIMER_NORESTART;
}

static void trigger_rx_monitor_timer_init(void)
{
	hrtimer_init(&trigger_rx_monitor_timer, CLOCK_MONOTONIC,
		HRTIMER_MODE_REL);
	trigger_rx_monitor_timer.function = trigger_rx_monitor_timer_handle;
	device_rx_pkt_statistic_reset();
	return;
}

void set_tx_rx_state(int val)
{
	if (unlikely(val < 0 || val >= TX_RX_STATE_MAX)) {
		log_err("input param tx_rx_state is invalid, error");
		return;
	}

	if (val == TX_RX_STATE_1T2R) {
		set_trigger_rx(1);
		start_trigger_rx_monitor_timer();
	} else {
		set_trigger_rx(0);
		stop_trigger_rx_monitor_timer();
	}
	atomic_set(&tx_rx_state, val);

	if (val != TX_RX_STATE_2T2R) {
		link_dynamic_schedule_clear();
		set_rtt_quality(LINK_DYNAMIC_SLOW);
	}
	return;
}

int get_tx_rx_state(void)
{
	return atomic_read(&tx_rx_state);
}

static struct net_device_stat *get_dev_htable_by_ifindex(struct hlist_head *htable,
	const int ifindex)
{
	struct net_device_stat *net_dev_stat = NULL;
	struct net_device_stat *nds = NULL;
	unsigned int bucket_hash;

	if (unlikely(htable == NULL))
		return NULL;

	rcu_read_lock();
	bucket_hash = reciprocal_scale(ifindex, dev_htable_size);
	hlist_for_each_entry_rcu(nds, &(htable[bucket_hash]), dev_hash) {
		if ((nds->dev != NULL) && (nds->dev->ifindex == ifindex)) {
			net_dev_stat = nds;
			break;
		}
	}
	rcu_read_unlock();
	return net_dev_stat;
}

static struct net_device_stat *get_default_dev_htable(void)
{
	struct rtable *rt = NULL;
	struct net_device_stat *ret = NULL;
	/* 0x72727272: ip sample */
	rt = ip_route_output(&init_net, 0x72727272, 0, RT_TOS(0), 0);
	if ((IS_ERR(rt)) || !rt || rt->rt_gw4 == 0 || (!rt->dst.dev)) {
		log_err("default rt find failed, error");
		return NULL;
	}
	ret = get_dev_htable_by_ifindex(dev_htable, rt->dst.dev->ifindex);
	ip_rt_put(rt);
	return ret;
}

static struct net_device *get_default_dev(void)
{
	struct net_device_stat *net_dev_stat = get_default_dev_htable();
	if (unlikely(net_dev_stat == NULL)) {
		log_err("net_dev_stat find failed, error");
		return NULL;
	}

	return net_dev_stat->dev;
}

static int get_default_role_id(void)
{
	struct link_info link_info_data;

	struct net_device_stat *net_dev_stat = get_default_dev_htable();
	if (unlikely(net_dev_stat == NULL)) {
		log_err("net_dev_stat find failed, error");
		if (get_link_info(&link_info_data) != SUCCESS)
			return ERROR;
		if (link_info_data.scene == SCENE_MOEM_MODEM) {
			if (available_paths & 0X02) {
				log_err("modem + modem, default role id is PRIMARY MODEM");
				return ROLLE_PRIMARY_MODEM;
			} else if (available_paths & 0X04) {
				log_err("modem + modem, default role id is SECONDARY MODEM");
				return ROLLE_SECONDARY_MODEM;
			} else {
				return ERROR;
			}
		} else if (link_info_data.scene == SCENE_WIFI_MODEM) {
			log_err("wifi + modem, default role id is wifi");
			return ROLLE_PRIMARY_WIFI;
		} else {
			return ERROR;
		}
	}
	return net_dev_stat->role;
}

int get_default_fid(void)
{
	return get_fid(get_default_role_id());
}

/* Called with rcu_read_lock() or hash_table_locks[] held */
static struct net_device_stat *dev_htable_find(struct hlist_head *htable,
	const struct net_device *dev)
{
	struct net_device_stat *net_dev_stat = NULL;
	struct net_device_stat *nds = NULL;
	unsigned int bucket_hash;

	if (unlikely(htable == NULL || dev == NULL))
		return NULL;

	rcu_read_lock();
	bucket_hash = reciprocal_scale(dev->ifindex, dev_htable_size);
	hlist_for_each_entry_rcu(nds, &(htable[bucket_hash]), dev_hash) {
		if ((nds->dev != NULL) && (nds->dev->ifindex == dev->ifindex)) {
			net_dev_stat = nds;
			break;
		}
	}
	rcu_read_unlock();
	return net_dev_stat;
}

static void dev_htable_delete(struct net_device_stat *net_dev_stat)
{
	unsigned int bucket_hash;
	rwlock_t *lock = NULL;

	if (unlikely(net_dev_stat == NULL))
		return;

	atomic_set(&(net_dev_stat->dev_enable), 0);
	atomic_set(&(net_dev_stat->ip_enable), 0);

	write_lock_bh(&(net_dev_stat->lock));

	if (net_dev_stat->dev == NULL) {
		write_unlock_bh(&(net_dev_stat->lock));
		return;
	}

	log_info("net_device ifindex %d name %s", net_dev_stat->dev->ifindex,
		net_dev_stat->dev->name);

	bucket_hash = reciprocal_scale(net_dev_stat->dev->ifindex,
		dev_htable_size);
	lock = &(dev_htable_locks[bucket_hash]);
	write_lock_bh(lock);
	if (hash_hashed(&(net_dev_stat->dev_hash)))
		hlist_del_rcu(&(net_dev_stat->dev_hash));
	atomic_dec(&dev_htable_count);
	write_unlock_bh(lock);

	INIT_HLIST_NODE(&(net_dev_stat->dev_hash));
	net_dev_stat->role = ROLLE_MAX;
	net_dev_stat->dev = NULL;
	(void)memset_s(&(net_dev_stat->addr), sizeof(net_dev_stat->addr), 0x00,
		sizeof(net_dev_stat->addr));
	(void)memset_s(net_dev_stat->dest_eth_addr, ETH_ALEN, 0x00, ETH_ALEN);

	write_unlock_bh(&(net_dev_stat->lock));
	return;
}

static void dev_htable_insert(struct net_device *dev, int role_id)
{
	unsigned int bucket_hash;
	rwlock_t *lock;

	if (unlikely(dev == NULL || role_id < 0 || role_id >= ROLLE_MAX))
		return;

	write_lock_bh(&(net_devices[role_id].lock));

	if (net_devices[role_id].dev != NULL ||
		atomic_read(&net_devices[role_id].dev_enable) != 0 ||
		atomic_read(&net_devices[role_id].ip_enable) != 0) {
		write_unlock_bh(&(net_devices[role_id].lock));
		log_err("this net_device not delete, ERROR");
		return;
	}

	log_info("ifindex %d name %s role_id %d", dev->ifindex, dev->name,
		role_id);

	bucket_hash = reciprocal_scale(dev->ifindex, dev_htable_size);
	lock = &(dev_htable_locks[bucket_hash]);
	write_lock_bh(lock);
	hlist_add_head_rcu(&net_devices[role_id].dev_hash,
			   &(dev_htable[bucket_hash]));
	atomic_inc(&dev_htable_count);
	write_unlock_bh(lock);

	net_devices[role_id].role = role_id;
	net_devices[role_id].dev = dev;

	write_unlock_bh(&(net_devices[role_id].lock));
	return;
}

static bool match_net_device_by_name(struct net_device *dev, struct dev_name_match *match)
{
	if (unlikely(dev == NULL || match == NULL || match->end >= IFNAMSIZ ||
		match->start >= IFNAMSIZ))
		return false;

	log_info("dev ifindex %d name %s match name %s", dev->ifindex,
		dev->name, match->name);
	for (int i = match->start; i <= match->end; i++) {
		if (match->name[i] != dev->name[i])
			return false;
	}
	return true;
}

static bool match_net_device(struct net_device *dev, struct net_device_match *match)
{
	if (unlikely(dev == NULL || match == NULL))
		return false;

	if ((match->match_mode & DEVICE_NAME_MATCH) == DEVICE_NAME_MATCH) {
		if (match_net_device_by_name(dev, &match->dev_name_rule))
			return true;
	}
	return false;
}

static void net_device_register_event(struct net_device *dev)
{
	struct net_device_stat *net_dev_stat = NULL;
	int role_id;

	if (unlikely(dev == NULL))
		return;

	log_info("device register ifindex %d name %s", dev->ifindex, dev->name);

	role_id = get_role_id(dev);
	if (role_id < 0 || role_id >= ROLLE_MAX) {
		log_info("ignore the device");
		return;
	}

	net_dev_stat = dev_htable_find(dev_htable, dev);
	if (net_dev_stat != NULL) {
		log_err("this net_device not unregister, ERROR");
		dev_htable_delete(net_dev_stat);
	}

	dev_htable_insert(dev, role_id);
	return;
}

static void net_device_up_event(struct net_device *dev)
{
	struct net_device_stat *net_dev_stat = NULL;

	if (unlikely(dev == NULL))
		return;

	log_info("device up ifindex %d name %s", dev->ifindex, dev->name);

	set_cloud_network_tun_dev_up(dev);

	net_dev_stat = dev_htable_find(dev_htable, dev);
	if (net_dev_stat == NULL) {
		log_info("ignore the device");
		return;
	}

	smp_mb__before_atomic();
	atomic_set(&(net_dev_stat->dev_enable), 1);
	return;
}

static void net_device_down_event(struct net_device *dev)
{
	struct net_device_stat *net_dev_stat = NULL;

	if (unlikely(dev == NULL))
		return;

	log_info("device down ifindex %d name %s", dev->ifindex, dev->name);

	set_cloud_network_tun_dev_down(dev);

	net_dev_stat = dev_htable_find(dev_htable, dev);
	if (net_dev_stat == NULL) {
		log_info("ignore the device");
		return;
	}

	smp_mb__before_atomic();
	atomic_set(&(net_dev_stat->dev_enable), 0);
	return;
}

static void net_device_unregister_event(struct net_device *dev)
{
	struct net_device_stat *net_dev_stat = NULL;

	if (unlikely(dev == NULL))
		return;

	log_info("device unregister ifindex %d name %s", dev->ifindex, dev->name);

	net_dev_stat = dev_htable_find(dev_htable, dev);
	if (net_dev_stat == NULL) {
		log_info("ignore the device");
		return;
	}

	dev_htable_delete(net_dev_stat);
	return;
}

static int cloud_network_device_event(struct notifier_block *this,
	unsigned long event, void *ptr)
{
	struct net_device *dev = NULL;

	if (unlikely(ptr == NULL))
		return NOTIFY_DONE;

	dev = netdev_notifier_info_to_dev(ptr);

	ASSERT_RTNL();

	log_info("event %lu ifindex %d name %s", event, dev->ifindex, dev->name);

	switch (event) {
	case NETDEV_REGISTER:
		net_device_register_event(dev);
		break;
	case NETDEV_UP:
		net_device_up_event(dev);
		break;
	case NETDEV_DOWN:
		net_device_down_event(dev);
		break;
	case NETDEV_UNREGISTER:
		net_device_unregister_event(dev);
		break;
	}
	return NOTIFY_DONE;
}

static int ip_confilct_report(void)
{
	struct netlink_head *msg_rsp = NULL;
	struct netlink_msg_head *msg_header = NULL;
	struct rept_ip_conflict *msg_rept = NULL;

	msg_rsp = (struct netlink_head *)kmalloc(sizeof(struct netlink_head) +
		sizeof(struct netlink_msg_head) +
		sizeof(struct rept_ip_conflict), GFP_ATOMIC);
	if (unlikely(msg_rsp == NULL)) {
		log_err("kmalloc failed");
		return ERROR;
	}

	msg_rsp->type = CLOUD_NETWORK_REPORT;
	msg_rsp->msg_len = sizeof(struct netlink_head) +
		sizeof(struct netlink_msg_head) +
		sizeof(struct rept_ip_conflict);

	msg_header = (struct netlink_msg_head *)(msg_rsp->data);
	msg_header->type = TUN_IP_CONFILCT;
	msg_header->data_len = sizeof(struct netlink_msg_head) +
		sizeof(struct rept_ip_conflict);

	msg_rept = (struct rept_ip_conflict *)(msg_header->data);
	msg_rept->status = 0;
	msg_rept->conflict_type = 4;
	log_info("event report tun interface ip conflict");
	netlink_report(msg_rsp, WORK_EXEC);
	kfree(msg_rsp);
	return SUCCESS;
}

static int ip_conflict_check(const struct net_device *dev, const struct in_ifaddr *ifa)
{
	struct net_device *tun_dev = NULL;

	if (unlikely(dev == NULL || ifa == NULL))
		return 0;
	if (!is_cloud_network_enable())
		return 0;

	/* tun0 match by **n0 */
	if ((dev->name)[2] == 'n' && (dev->name)[3] == '0') {
		log_info("ignore tun dev");
		return 0;
	}

	tun_dev = dev_get_by_name(&init_net, TUN_NAME);
	if (tun_dev == NULL) {
		log_info("tun dev is NULL");
		return 0;
	}
	if (tun_dev == dev) {
		log_info("ignore tun dev");
		dev_put(tun_dev);
		return 0;
	}
	if (unlikely(tun_dev->ip_ptr == NULL)) {
		dev_put(tun_dev);
		return 0;
	}

	struct in_ifaddr *ifa_list = tun_dev->ip_ptr->ifa_list;
	while (ifa_list != NULL) {
		if (ifa_list->ifa_address == 0 || ifa->ifa_address == 0) {
			ifa_list = ifa_list->ifa_next;
			continue;
		}
		if (ifa_list->ifa_address == ifa->ifa_address) {
			log_info("ip conflict tun %s dev %s", tun_dev->name, dev->name);
			ip_confilct_report();
			dev_put(tun_dev);
			return 1;
		}
		ifa_list = ifa_list->ifa_next;
	}
	dev_put(tun_dev);
	return 0;
}

static int primary_network_report(const char *name, u8 length)
{
	struct netlink_head *msg_rsp = NULL;
	struct netlink_msg_head *msg_header = NULL;
	struct rept_primary_network *msg_rept = NULL;

	if (!is_cloud_network_enable())
		return ERROR;
	if (unlikely(name == NULL))
		return ERROR;

	msg_rsp = (struct netlink_head *)kmalloc(sizeof(struct netlink_head) +
		sizeof(struct netlink_msg_head) +
		sizeof(struct rept_primary_network), GFP_ATOMIC);
	if (unlikely(msg_rsp == NULL)) {
		log_err("kmalloc failed");
		return ERROR;
	}

	(void)memset_s(msg_rsp, sizeof(struct netlink_head) +
		sizeof(struct netlink_msg_head) +
		sizeof(struct rept_primary_network), 0x00,
		sizeof(struct netlink_head) +
		sizeof(struct netlink_msg_head) +
		sizeof(struct rept_primary_network));
	msg_rsp->type = CLOUD_NETWORK_REPORT;
	msg_rsp->msg_len = sizeof(struct netlink_head) +
		sizeof(struct netlink_msg_head) +
		sizeof(struct rept_primary_network);

	msg_header = (struct netlink_msg_head *)(msg_rsp->data);
	msg_header->type = PRIMARY_NETWORK_REPORT;
	msg_header->data_len = sizeof(struct netlink_msg_head) +
		sizeof(struct rept_primary_network);

	msg_rept = (struct rept_primary_network *)(msg_header->data);
	msg_rept->length = length;
	if (snprintf_s(msg_rept->primary_name, IFNAMSIZ, IFNAMSIZ - 1, "%s",
		name) < 0) {
		log_err("snprintf_s failed");
		kfree(msg_rsp);
		return ERROR;
	}
	log_info("event report primary network %s", msg_rept->primary_name);
	netlink_report(msg_rsp, WORK_EXEC);
	kfree(msg_rsp);
	return SUCCESS;
}

static int tun_changed_report(u32 status, u32 ip_address)
{
	struct netlink_head *msg_rsp = NULL;
	struct netlink_msg_head *msg_header = NULL;
	struct rept_tun_cfg_info *msg_rept = NULL;

	if (!is_cloud_network_enable())
		return ERROR;

	msg_rsp = (struct netlink_head *)kmalloc(sizeof(struct netlink_head) +
		sizeof(struct netlink_msg_head) +
		sizeof(struct rept_tun_cfg_info), GFP_ATOMIC);
	if (unlikely(msg_rsp == NULL)) {
		log_err("kmalloc failed");
		return ERROR;
	}

	msg_rsp->type = CLOUD_NETWORK_REPORT;
	msg_rsp->msg_len = sizeof(struct netlink_head) +
		sizeof(struct netlink_msg_head) +
		sizeof(struct rept_tun_cfg_info);

	msg_header = (struct netlink_msg_head *)(msg_rsp->data);
	msg_header->type = TUN_CONFIG_INFO;
	msg_header->data_len = sizeof(struct netlink_msg_head) +
		sizeof(struct rept_tun_cfg_info);

	msg_rept = (struct rept_tun_cfg_info *)(msg_header->data);
	msg_rept->status = status;
	msg_rept->ip_address = ip_address;
	log_info("event report tun change status %u",
		msg_rept->status);
	netlink_report(msg_rsp, WORK_EXEC);
	kfree(msg_rsp);
	return SUCCESS;
}

int select_default_network_role_id(void)
{
	struct link_info link_info_data;
	int ret = ERROR;
	if (get_link_info(&link_info_data) != SUCCESS)
		return ret;
	spin_lock_bh(&available_paths_lock);
	/* wifi path available and scene is 0(WIFI + MODEM) */
	if ((available_paths & PATH_WIFI_1) &&
		(link_info_data.scene == SCENE_WIFI_MODEM))
		ret = ROLLE_PRIMARY_WIFI;
	else if (available_paths & PATH_MODEM_1) /* primary modem path check */
		ret = ROLLE_PRIMARY_MODEM;
	else if (available_paths & PATH_MODEM_2) /* secondary modem path check */
		ret = ROLLE_SECONDARY_MODEM;

	spin_unlock_bh(&available_paths_lock);
	return ret;
}

static void select_default_network_report(void)
{
	struct link_info link_info_data;
	if (get_link_info(&link_info_data) != SUCCESS)
		return;

	spin_lock_bh(&available_paths_lock);
	/* wifi path available and scene is 0(WIFI + MODEM) */
	if ((available_paths & PATH_WIFI_1) &&
		(link_info_data.scene == SCENE_WIFI_MODEM))
		primary_network_report(modem_name[ROLLE_PRIMARY_WIFI],
			strlen(modem_name[ROLLE_PRIMARY_WIFI]));
	else if (available_paths & PATH_MODEM_1) /* primary modem path check */
		primary_network_report(modem_name[ROLLE_PRIMARY_MODEM],
			strlen(modem_name[ROLLE_PRIMARY_MODEM]));
	else if (available_paths & PATH_MODEM_2) /* secondary modem path check */
		primary_network_report(modem_name[ROLLE_SECONDARY_MODEM],
			strlen(modem_name[ROLLE_SECONDARY_MODEM]));

	spin_unlock_bh(&available_paths_lock);

	return;
}

void traffic_tx_stat_save(struct net_dev_traffic_stat *dev_traffic_stat, int role_id, int bytes)
{
	if (unlikely(!dev_traffic_stat || role_id < 0 || role_id >= ROLLE_MAX))
		return;

	spin_lock_bh(&(dev_traffic_stat[role_id].txlock));
	dev_traffic_stat[role_id].tx_bytes += bytes;
	dev_traffic_stat[role_id].tx_packet++;
	spin_unlock_bh(&(dev_traffic_stat[role_id].txlock));
	return;
}

void traffic_tx_stat(int role_id, int bytes)
{
	traffic_tx_stat_save(traffic_stat, role_id, bytes);
}

void traffic_rx_stat_save(struct net_dev_traffic_stat *dev_traffic_stat,
							struct net_device *dev, int bytes)
{
	if (unlikely(!dev || !dev_traffic_stat))
		return;
	int role_id = get_role_id(dev);
	if (unlikely(role_id < 0 || role_id >= ROLLE_MAX))
		return;

	spin_lock_bh(&(dev_traffic_stat[role_id].rxlock));
	dev_traffic_stat[role_id].rx_bytes += bytes;
	dev_traffic_stat[role_id].rx_packet++;
	spin_unlock_bh(&(dev_traffic_stat[role_id].rxlock));
	return;
}

void traffic_rx_stat(struct net_device *dev, int bytes)
{
	traffic_rx_stat_save(traffic_stat, dev, bytes);
}

void traffic_stat_reset_by_role_id(struct net_dev_traffic_stat *dev_traffic_stat, int role_id)
{
	if (unlikely(!dev_traffic_stat || role_id < 0 || role_id >= ROLLE_MAX))
		return;

	spin_lock_bh(&(dev_traffic_stat[role_id].rxlock));
	dev_traffic_stat[role_id].rx_bytes = 0;
	dev_traffic_stat[role_id].rx_packet = 0;
	spin_unlock_bh(&(dev_traffic_stat[role_id].rxlock));

	spin_lock_bh(&(dev_traffic_stat[role_id].txlock));
	dev_traffic_stat[role_id].tx_bytes = 0;
	dev_traffic_stat[role_id].tx_packet = 0;
	spin_unlock_bh(&(dev_traffic_stat[role_id].txlock));

	return;
}

void traffic_stat_init_by_role_id(struct net_dev_traffic_stat *dev_traffic_stat, int role_id)
{
	if (unlikely(!dev_traffic_stat || role_id < 0 || role_id >= ROLLE_MAX))
		return;

	spin_lock_init(&(dev_traffic_stat[role_id].rxlock));
	spin_lock_init(&(dev_traffic_stat[role_id].txlock));
	traffic_stat_reset_by_role_id(dev_traffic_stat, role_id);
	return;
}

int traffic_stat_data_to_buffer(struct net_dev_traffic_stat *dev_traffic_stat, int role_id,
								char *buffer, int *len, int buffer_len)
{
	if (unlikely(!dev_traffic_stat || !buffer || !len))
		return ERROR;

	spin_lock_bh(&(dev_traffic_stat[role_id].rxlock));
	spin_lock_bh(&(dev_traffic_stat[role_id].txlock));
	int temp_len = snprintf_s(buffer + *len, buffer_len - *len, buffer_len - *len - 1,
		"%s %llu %llu %llu %llu\r\n", modem_name[role_id],
		dev_traffic_stat[role_id].tx_bytes, dev_traffic_stat[role_id].rx_bytes,
		dev_traffic_stat[role_id].tx_packet, dev_traffic_stat[role_id].rx_packet);
	spin_unlock_bh(&(dev_traffic_stat[role_id].txlock));
	spin_unlock_bh(&(dev_traffic_stat[role_id].rxlock));
	if (temp_len < 0) {
		log_err("snprintf_s failed %d", role_id);
		return ERROR;
	}
	*len += temp_len;
	return SUCCESS;
}

static u64 get_traffic_by_role_id(int role_id)
{
	u64 ret = 0;
	u64 trafiic[ROLLE_MAX] = {0};
	int i = 0;
	if (unlikely(role_id < 0 || role_id >= ROLLE_MAX))
		return ret;
	for (i = 0; i < ROLLE_MAX; i++) {
		spin_lock_bh(&(traffic_stat[i].rxlock));
		spin_lock_bh(&(traffic_stat[i].txlock));
		trafiic[i] = traffic_stat[i].tx_bytes + traffic_stat[i].rx_bytes;
		spin_unlock_bh(&(traffic_stat[i].txlock));
		spin_unlock_bh(&(traffic_stat[i].rxlock));
	}
	ret = trafiic[role_id] - last_traffic[role_id];
	for (i = 0; i < ROLLE_MAX; i++)
		last_traffic[i] = trafiic[i];
	return ret;
}

int get_traffic_stat_info_to_buffer(char *buffer, int buffer_len)
{
	int len = 0;
	if (!buffer || buffer_len < KBUFFER_SIZE)
		return ERROR;
	for (int i = 0; i < ROLLE_MAX; i++)
		if (traffic_stat_data_to_buffer(traffic_stat, i, buffer, &len, buffer_len) == ERROR)
			return ERROR;
	return len;
}

u64 get_secondary_traffic(void)
{
	struct link_info link_info_data;
	if (get_link_info(&link_info_data) != SUCCESS)
		return 0;

	if (link_info_data.scene == SCENE_MOEM_MODEM)
		return get_traffic_by_role_id(NUM_2);
	else if (link_info_data.scene == SCENE_WIFI_MODEM)
		return get_traffic_by_role_id(NUM_1);

	return 0;
}

void traffic_stat_reset_all(void)
{
	for (int i = 0; i < ROLLE_MAX; i++)
		traffic_stat_reset_by_role_id(traffic_stat, i);
	return;
}

static void traffic_stat_init(void)
{
	for (int i = 0; i < ROLLE_MAX; i++) {
		traffic_stat_init_by_role_id(traffic_stat, i);
		last_traffic[i] = 0;
	}
	return;
}

static void net_device_stat_set_up(struct net_device_stat *net_dev_stat,
	struct net_device *dev, const struct in_ifaddr *ifa)
{
	if (unlikely(net_dev_stat == NULL || dev == NULL || ifa == NULL))
		return;

	write_lock_bh(&(net_dev_stat->lock));
	(void)memset_s(net_dev_stat->dest_eth_addr, ETH_ALEN, 0x00, ETH_ALEN);
	(void)memset_s(&(net_dev_stat->addr), sizeof(net_dev_stat->addr), 0,
		sizeof(net_dev_stat->addr));
	net_dev_stat->addr.ip = ifa->ifa_address;
	write_unlock_bh(&(net_dev_stat->lock));
	return;
}

static void net_device_stat_set_down(struct net_device_stat *net_dev_stat,
	struct net_device *dev, const struct in_ifaddr *ifa)
{
	if (unlikely(net_dev_stat == NULL || dev == NULL || ifa == NULL))
		return;

	write_lock_bh(&(net_dev_stat->lock));
	(void)memset_s(net_dev_stat->dest_eth_addr, ETH_ALEN, 0x00, ETH_ALEN);
	(void)memset_s(&(net_dev_stat->addr), sizeof(net_dev_stat->addr), 0x00,
		sizeof(net_dev_stat->addr));
	write_unlock_bh(&(net_dev_stat->lock));
	return;
}

static void available_paths_change_check_modem(void)
{
	bool all_dev_down = false;
	bool first_dev_up = false;

	spin_lock_bh(&available_paths_lock);
	if ((available_paths & (PATH_MODEM_1 | PATH_MODEM_2)) == 0)
		all_dev_down = true;
	if (((available_paths & (PATH_MODEM_1 | PATH_MODEM_2)) != 0) &&
		((available_paths_last & (PATH_MODEM_1 | PATH_MODEM_2)) == 0))
		first_dev_up = true;
	spin_unlock_bh(&available_paths_lock);

	if (all_dev_down)
		stop_all_compass_detect();

	if (first_dev_up)
		start_compass_detect_on_demand();

	return;
}

static void available_paths_change_check(void)
{
	struct link_info link_info_data;

	if (get_link_info(&link_info_data) != SUCCESS)
		return ;

	if (link_info_data.scene == SCENE_MOEM_MODEM)
		available_paths_change_check_modem();

	spin_lock_bh(&available_paths_lock);
	available_paths_last = available_paths;
	spin_unlock_bh(&available_paths_lock);
	return;
}

static void available_paths_set_up(u32 role)
{
	spin_lock_bh(&available_paths_lock);
	if (role == ROLLE_PRIMARY_WIFI) {
		available_paths |= PATH_WIFI_1; /* set WiFi path */
	} else if (role == ROLLE_PRIMARY_MODEM) {
		available_paths |= PATH_MODEM_1; /* set primary modem path */
	} else if (role == ROLLE_SECONDARY_MODEM) {
		available_paths |= PATH_MODEM_2; /* set secondary modem path */
	}
	spin_unlock_bh(&available_paths_lock);
	return;
}

static void available_paths_set_down(u32 role)
{
	spin_lock_bh(&available_paths_lock);
	if (role == ROLLE_PRIMARY_WIFI) {
		available_paths &= (~PATH_WIFI_1); /* set WiFi path */
	} else if (role == ROLLE_PRIMARY_MODEM) {
		available_paths &= (~PATH_MODEM_1); /* set primary modem path */
	} else if (role == ROLLE_SECONDARY_MODEM) {
		available_paths &= (~PATH_MODEM_2); /* set secondary modem path */
	}
	spin_unlock_bh(&available_paths_lock);
	return;
}

static void inet_event_ip_up(struct net_device *dev, const struct in_ifaddr *ifa)
{
	struct net_device_stat *net_dev_stat = NULL;

	if (unlikely(dev == NULL || ifa == NULL))
		return;

	log_info("inet ip up ifindex %d name %s", dev->ifindex, dev->name);
	ip_conflict_check(dev, ifa);
	set_cloud_network_tun_ip_up(dev, ifa);
	/* tun0/vnic-tun device name match */
	if ((dev->name[NUM_0] == 't' && dev->name[NUM_1] == 'u' && dev->name[NUM_2] == 'n' && dev->name[NUM_3] == '0') ||
		(dev->name[NUM_0] == 'v' && dev->name[NUM_1] == 'n' && dev->name[NUM_2] == 'i' && dev->name[NUM_3] == 'c')) {
		log_info("tun0 device ip up");
		tun_changed_report(1, dev->ip_ptr->ifa_list->ifa_address);
		select_default_network_report();
		return;
	}

	net_dev_stat = dev_htable_find(dev_htable, dev);
	if (net_dev_stat == NULL) {
		log_info("ignore the device");
		return;
	}

	net_device_stat_set_up(net_dev_stat, dev, ifa);
	available_paths_set_up(net_dev_stat->role);
	log_info("available paths 0X%08X last paths 0X%08X", available_paths,
		available_paths_last);
	select_default_network_report();
	smp_mb__before_atomic();
	atomic_set(&(net_dev_stat->ip_enable), 1);
	available_paths_change_check();
	return;
}

static void inet_event_ip_down(struct net_device *dev, const struct in_ifaddr *ifa)
{
	struct net_device_stat *net_dev_stat = NULL;

	if (unlikely(dev == NULL))
		return;
	set_cloud_network_tun_ip_down(dev);
	/* tun0/vnic-tun device name match */
	if ((dev->name[NUM_0] == 't' && dev->name[NUM_1] == 'u' && dev->name[NUM_2] == 'n' && dev->name[NUM_3] == '0') ||
		(dev->name[NUM_0] == 'v' && dev->name[NUM_1] == 'n' && dev->name[NUM_2] == 'i' && dev->name[NUM_3] == 'c')) {
		log_info("tun0 ip down");
		tun_changed_report(0, 0);
		return;
	}

	log_info("inet ip down ifindex %d name %s", dev->ifindex, dev->name);

	net_dev_stat = dev_htable_find(dev_htable, dev);
	if (net_dev_stat == NULL) {
		log_info("ignore the device");
		return;
	}
	atomic_set(&(net_dev_stat->ip_enable), 0);
	net_device_stat_set_down(net_dev_stat, dev, ifa);
	available_paths_set_down(net_dev_stat->role);
	send_fid_control(net_dev_stat->role, 0, NULL, 0);
	select_default_network_report();
	log_info("available paths 0X%08X last paths 0X%08X", available_paths,
		available_paths_last);
	smp_mb__before_atomic();
	available_paths_change_check();
	return;
}

int get_device_id_by_path(int path)
{
	switch (path) {
	case PATH_WIFI_1:
		return ROLLE_PRIMARY_WIFI;
	case PATH_MODEM_1:
		return ROLLE_PRIMARY_MODEM;
	case PATH_MODEM_2:
		return ROLLE_SECONDARY_MODEM;
	default:
		return ERROR;
	}
}

char *get_net_device_mac(int path)
{
	int id = get_device_id_by_path(path);
	if (unlikely(id < 0 || id >= ROLLE_MAX)) {
		log_err("id is invalid, error");
		return NULL;
	}

	if (unlikely((atomic_read(&(net_devices[id].ip_enable)) == 0) ||
		(atomic_read(&(net_devices[id].dev_enable)) == 0)))
		return NULL;

	if (net_devices[id].dest_eth_addr[NUM_0] == 0 &&
		net_devices[id].dest_eth_addr[NUM_1] == 0 &&
		net_devices[id].dest_eth_addr[NUM_2] == 0 &&
		net_devices[id].dest_eth_addr[NUM_3] == 0 &&
		net_devices[id].dest_eth_addr[NUM_4] == 0 &&
		net_devices[id].dest_eth_addr[NUM_5] == 0)
		return NULL;

	return net_devices[id].dest_eth_addr;
}

void set_net_device_mac(int path, char *data)
{
	errno_t err;

	int id = get_device_id_by_path(path);
	if (unlikely(id < 0 || id >= ROLLE_MAX)) {
		log_err("id is invalid, error");
		return;
	}

	err = memcpy_s(net_devices[id].dest_eth_addr, ETH_ALEN, data, ETH_ALEN);
	if (err != EOK)
		log_err("memcpy_s failed");

	return;
}

static int get_link_path_modem(void)
{
	int ret = 0;
	int current_fid = DETECT_PATH_VAL_ERROR;
	spin_lock_bh(&available_paths_lock);
	if (atomic_read(&tx_rx_state) == TX_RX_STATE_1T1R &&
		(available_paths & 0X02) && (available_paths & 0X04))
		ret = 0X06;
	else if (atomic_read(&tx_rx_state) == TX_RX_STATE_1T1R &&
		(available_paths & 0X02))
		ret = 0X02;
	else if (atomic_read(&tx_rx_state) == TX_RX_STATE_1T1R &&
		(available_paths & 0X04))
		ret = 0X04;
	else if (atomic_read(&tx_rx_state) == TX_RX_STATE_2T2R)
		ret = (available_paths & 0X06);
	else if (atomic_read(&tx_rx_state) == TX_RX_STATE_1T2R &&
		(available_paths & 0X02))
		ret = 0X02;
	else if (atomic_read(&tx_rx_state) == TX_RX_STATE_1T2R &&
		(available_paths & 0X04))
		ret = 0X04;
	else
		ret = 0;
	spin_unlock_bh(&available_paths_lock);
	if ((atomic_read(&tx_rx_state) == TX_RX_STATE_2T2R) && !is_redundant_status() && (ret == 0x06)) {
		current_fid = get_default_fid();
		if (current_fid == DETECT_PATH_VAL_ERROR) {
			log_err("get default fid error");
			return ret;
		}
		if (current_fid == DETECT_PATH_VAL_MODEM_1)
			ret &= ~0x04;
		if (current_fid == DETECT_PATH_VAL_MODEM_2)
			ret &= ~0x02;
	}
	return ret;
}

static int get_link_path_wifi(void)
{
	int ret = 0;

	spin_lock_bh(&available_paths_lock);

	if (atomic_read(&tx_rx_state) == TX_RX_STATE_1T1R &&
		(available_paths & 0X01))
		ret = 0X01;
	else if (atomic_read(&tx_rx_state) == TX_RX_STATE_1T1R &&
		(available_paths & 0X02))
		ret = 0X02;
	else if (atomic_read(&tx_rx_state) == TX_RX_STATE_2T2R)
		ret = available_paths & 0X03;
	else if (atomic_read(&tx_rx_state) == TX_RX_STATE_1T2R &&
		(available_paths & 0X01))
		ret = 0X01;
	else if (atomic_read(&tx_rx_state) == TX_RX_STATE_1T2R &&
		(available_paths & 0X02))
		ret = 0X02;
	else
		ret = 0;
	spin_unlock_bh(&available_paths_lock);
	if (!is_redundant_status() && ret == 0x03)
		ret &= ~0x02;
	return ret;
}

u32 get_available_paths(void)
{
	int ret;
	spin_lock_bh(&available_paths_lock);
	ret = available_paths;
	spin_unlock_bh(&available_paths_lock);
	return ret;
}

u32 get_link_path(void)
{
	struct link_info link_info_data;

	if (atomic_read(&tx_rx_state) == TX_RX_STATE_ATAR)
		return available_paths;

	if (atomic_read(&tx_rx_state) == TX_RX_STATE_1T2R &&
		atomic_read(&trigger_rx) == 1)
		return available_paths;

	if (get_link_info(&link_info_data) != SUCCESS)
		return 0;

	if (link_info_data.scene == SCENE_MOEM_MODEM) {
		return get_link_path_modem();
	} else if (link_info_data.scene == SCENE_WIFI_MODEM) {
		return get_link_path_wifi();
	} else {
		return 0;
	}
}

static int cloud_network_inet_event(struct notifier_block *this,
	unsigned long event, void *ptr)
{
	const struct in_ifaddr *ifa = ptr;
	const struct in_device *idev = NULL;
	struct net_device *dev = NULL;

	idev = ifa->ifa_dev;
	if (idev->dead)
		return NOTIFY_DONE;

	dev = idev->dev;

	log_info("event %lu ifindex %d name %s", event, dev->ifindex, dev->name);

	switch (event) {
	case NETDEV_UP:
	case NETDEV_CHANGEADDR:
	case NETDEV_NOTIFY_PEERS:
		if (!inetdev_valid_mtu(dev->mtu))
			break;
		inet_event_ip_up(dev, ifa);
		break;
	case NETDEV_CHANGEMTU:
		if (inetdev_valid_mtu(dev->mtu))
			break;
		/* disable IP when MTU is invalid */
		fallthrough;
	case NETDEV_DOWN:
		inet_event_ip_down(dev, ifa);
		break;
	}
	return NOTIFY_DONE;
}

static void dev_match_rule_generate_primary_wifi(void)
{
	int sec_ret;

	sec_ret = snprintf_s(dev_match[ROLLE_PRIMARY_WIFI].dev_name_rule.name,
		sizeof(dev_match[ROLLE_PRIMARY_WIFI].dev_name_rule.name),
		sizeof(dev_match[ROLLE_PRIMARY_WIFI].dev_name_rule.name) - 1, "%s",
		modem_name[ROLLE_PRIMARY_WIFI]);
	if (sec_ret == -1) {
		log_err("generate primary WiFi match rule failed, error");
		return;
	}
	dev_match[ROLLE_PRIMARY_WIFI].dev_name_rule.start = 0;
	dev_match[ROLLE_PRIMARY_WIFI].dev_name_rule.end = strlen(modem_name[ROLLE_PRIMARY_WIFI]) - 1;
	dev_match[ROLLE_PRIMARY_WIFI].match_mode = DEVICE_NAME_MATCH;

	log_info("name %s start %u end %u", dev_match[ROLLE_PRIMARY_WIFI].dev_name_rule.name,
		dev_match[ROLLE_PRIMARY_WIFI].dev_name_rule.start,
		dev_match[ROLLE_PRIMARY_WIFI].dev_name_rule.end);
	return;
}

static void dev_match_rule_generate_primary_modem(void)
{
	for (int i = ROLLE_PRIMARY_MODEM; i < ROLLE_MAX; i++) {
		int sec_ret;

		sec_ret = snprintf_s(dev_match[i].dev_name_rule.name,
			sizeof(dev_match[i].dev_name_rule.name),
			sizeof(dev_match[i].dev_name_rule.name) - 1, "%s", modem_name[i]);
		if (sec_ret == -1) {
			log_err("generate primary WiFi match rule failed, error");
			return;
		}
		dev_match[i].dev_name_rule.start = 0;
		dev_match[i].dev_name_rule.end = strlen(modem_name[i]) - 1;
		dev_match[i].match_mode = DEVICE_NAME_MATCH;

		log_info("name %s start %u end %u", dev_match[i].dev_name_rule.name,
			dev_match[i].dev_name_rule.start,
			dev_match[i].dev_name_rule.end);
	}
	return;
}

static void dev_match_rule_generate(void)
{
	dev_match_rule_generate_primary_wifi();
	dev_match_rule_generate_primary_modem();
	return;
}

int get_role_id(struct net_device *dev)
{
	struct net_device_stat *net_dev_stat = NULL;
	int role_id = -1;

	if (unlikely(dev == NULL))
		return role_id;

	net_dev_stat = dev_htable_find(dev_htable, dev);
	if (net_dev_stat != NULL)
		return net_dev_stat->role;

	for (int i = 0; i < ROLLE_MAX; i++) {
		if (match_net_device(dev, &dev_match[i])) {
			role_id = i;
			break;
		}
	}
	return role_id;
}

__be32 cloud_network_inet_select_addr(int id)
{
	__be32 src;

	if (unlikely(id < 0 || id >= ROLLE_MAX))
		return 0;

	read_lock_bh(&(net_devices[id].lock));
	if (unlikely((atomic_read(&(net_devices[id].ip_enable)) == 0) ||
		(atomic_read(&(net_devices[id].dev_enable)) == 0))) {
		log_info("the net device is ip down");
		read_unlock_bh(&(net_devices[id].lock));
		return 0;
	}

	src = net_devices[id].addr.ip;
	read_unlock_bh(&(net_devices[id].lock));
	return src;
}

struct net_device *get_net_device(int id)
{
	if (unlikely(id < 0 || id >= ROLLE_MAX)) {
		log_info("trransmit unlikely(role_id < 0 || role_id >= ROLLE_MAX");
		return NULL;
	}

	if (unlikely((atomic_read(&(net_devices[id].ip_enable)) == 0) ||
		(atomic_read(&(net_devices[id].dev_enable)) == 0)))
		return NULL;
	return net_devices[id].dev;
}

int cloud_network_device_init(void)
{
	log_info("cloud network device init");
	atomic_set(&dev_htable_count, 0);
	dev_htable_size = DEV_HTABLE_LOCK_NUM;
	dev_htable = nf_ct_alloc_hashtable(&dev_htable_size, 0);
	dev_htable_size = DEV_HTABLE_LOCK_NUM;
	if (!dev_htable) {
		log_err("devices hash table alloc failed, error");
		return ERROR;
	}
	traffic_stat_init();
	for (int i = 0; i < DEV_HTABLE_LOCK_NUM; i++)
		rwlock_init(&dev_htable_locks[i]);

	for (int j = 0; j < ROLLE_MAX; j++) {
		(void)memset_s(&dev_match[j], sizeof(struct net_device_match), 0x00,
			sizeof(struct net_device_match));
		INIT_HLIST_NODE(&(net_devices[j].dev_hash));
		atomic_set(&(net_devices[j].dev_enable), 0);
		atomic_set(&(net_devices[j].ip_enable), 0);
		rwlock_init(&net_devices[j].lock);
		net_devices[j].role = ROLLE_MAX;
		net_devices[j].dev = NULL;
		memset_s(&(net_devices[j].addr), sizeof(net_devices[j].addr), 0,
			sizeof(net_devices[j].addr));
	}
	cloud_network_tun_init();
	dev_match_rule_generate();
	atomic_set(&tx_rx_state, TX_RX_STATE_2T2R);
	atomic_set(&trigger_rx, 1);
	trigger_rx_monitor_timer_init();
	/* Register for device stat reports */
	register_netdevice_notifier(&cloud_network_dev_notifier);
	/* Register IP address stat reports */
	register_inetaddr_notifier(&cloud_network_inet_notifier);
	return SUCCESS;
}

void cloud_network_device_exit(void)
{
	log_info("cloud network device exit");
	if (dev_htable)
		kvfree(dev_htable);
	return;
}
