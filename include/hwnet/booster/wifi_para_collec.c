/*
 * Copyright (c) Honor Device Co., Ltd. 2020-2020. All rights reserved.
 * Description: This module is to collect wifi chip parameters
 * Author: tongxilin.
 * Create: 2020-03-30.
 */

#include "wifi_para_collec.h"

#include <../net/wireless/rdev-ops.h>
#include <../net/wireless/nl80211.h>
#include <net/neighbour.h>
#include "ip_para_collec_ex.h"
#include <linux/version.h>
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4,19,0)
#include <net/cfg80211.h>
#endif
static struct wifi_ctx *g_wifi_ctx;
static u32 g_gateway[MAX_WIFI_NUM];
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4,19,0)
struct wifi_dev g_wifi_dev[MAX_WIFI_IFACE_NUM];
#endif

static u32 turn_over(u32 cur, u32 past)
{
	if (cur < past)
		return MAX_U32 - past + cur + 1;
	else
		return cur - past;
}
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4,19,0)
void set_wifi_state_connect(const char *name,
				   struct cfg80211_registered_device *rdev,
				   struct net_device *dev, u8 *mac_addr)
{
	if (strstr(name, "wlan0")) {
		g_wifi_dev[0].wifi_state_flag = 1;
		g_wifi_dev[0].rdev = rdev;
		g_wifi_dev[0].dev = dev;
		memcpy(g_wifi_dev[0].mac_addr, mac_addr,
		       MAC_ADDR_SIZE * sizeof(u8));
	}
	if (strstr(name, "wlan1")) {
		g_wifi_dev[1].wifi_state_flag = 1;
		g_wifi_dev[1].rdev = rdev;
		g_wifi_dev[1].dev = dev;
		memcpy(g_wifi_dev[1].mac_addr, mac_addr,
		       MAC_ADDR_SIZE * sizeof(u8));
	}
}

EXPORT_SYMBOL(set_wifi_state_connect);

static bool hn_wifi_connect_mode;

bool hn_timestamps_get_wifi_connect_status(void)
{
	return hn_wifi_connect_mode;
}
EXPORT_SYMBOL(hn_timestamps_get_wifi_connect_status);

void hn_timestamps_set_wifi_connect_status(bool connect)
{
	hn_wifi_connect_mode = connect;
	printk(KERN_ERR "%s: hn_wifi_connect_mode(%d)\n",
		__FUNCTION__, hn_wifi_connect_mode);
}
EXPORT_SYMBOL(hn_timestamps_set_wifi_connect_status);

void clean_wifi_iface_rdev(void)
{
        int i;
        for (i = 0; i < MAX_WIFI_IFACE_NUM; i++) {
                g_wifi_dev[i].wifi_state_flag = 0;
                g_wifi_dev[i].rdev = NULL;
                g_wifi_dev[i].dev = NULL;
                memset(g_wifi_dev[i].mac_addr, 0, MAC_ADDR_SIZE * sizeof(u8));
        }
}

EXPORT_SYMBOL(clean_wifi_iface_rdev);

void set_wifi_state_disconnect(const char *name)
{
	if (strstr(name, "wlan0")) {
		g_wifi_dev[0].wifi_state_flag = 0;
		g_wifi_dev[0].rdev = NULL;
		g_wifi_dev[0].dev = NULL;
		memset(g_wifi_dev[0].mac_addr, 0, MAC_ADDR_SIZE * sizeof(u8));
	}
	if (strstr(name, "wlan1")) {
		g_wifi_dev[1].wifi_state_flag = 0;
		g_wifi_dev[1].rdev = NULL;
		g_wifi_dev[1].dev = NULL;
		memset(g_wifi_dev[1].mac_addr, 0, MAC_ADDR_SIZE * sizeof(u8));
	}
}

EXPORT_SYMBOL(set_wifi_state_disconnect);
static u32 wifi_calculate_bitrate_ht(struct rate_info *rate)
{
	int modulation, streams, bitrate;

	/* the formula below does only work for MCS values smaller than 32 */
	if (WARN_ON_ONCE(rate->mcs >= 32))
		return 0;

	modulation = rate->mcs & 7;
	streams = (rate->mcs >> 3) + 1;

	bitrate = (rate->bw == RATE_INFO_BW_40) ? 13500000 : 6500000;

	if (modulation < 4)
		bitrate *= (modulation + 1);
	else if (modulation == 4)
		bitrate *= (modulation + 2);
	else
		bitrate *= (modulation + 3);

	bitrate *= streams;

	if (rate->flags & RATE_INFO_FLAGS_SHORT_GI)
		bitrate = (bitrate / 9) * 10;

	/* do NOT round down here */
	return (bitrate + 50000) / 100000;
}

static u32 wifi_calculate_bitrate_dmg(struct rate_info *rate)
{
	static const u32 __mcs2bitrate[] = {
		/* control PHY */
		[0] =   275,
		/* SC PHY */
		[1] =  3850,
		[2] =  7700,
		[3] =  9625,
		[4] = 11550,
		[5] = 12512, /* 1251.25 mbps */
		[6] = 15400,
		[7] = 19250,
		[8] = 23100,
		[9] = 25025,
		[10] = 30800,
		[11] = 38500,
		[12] = 46200,
		/* OFDM PHY */
		[13] =  6930,
		[14] =  8662, /* 866.25 mbps */
		[15] = 13860,
		[16] = 17325,
		[17] = 20790,
		[18] = 27720,
		[19] = 34650,
		[20] = 41580,
		[21] = 45045,
		[22] = 51975,
		[23] = 62370,
		[24] = 67568, /* 6756.75 mbps */
		/* LP-SC PHY */
		[25] =  6260,
		[26] =  8340,
		[27] = 11120,
		[28] = 12510,
		[29] = 16680,
		[30] = 22240,
		[31] = 25030,
	};

	if (WARN_ON_ONCE(rate->mcs >= ARRAY_SIZE(__mcs2bitrate)))
		return 0;

	return __mcs2bitrate[rate->mcs];
}

static u32 wifi_calculate_bitrate_edmg(struct rate_info *rate)
{
	static const u32 __mcs2bitrate[] = {
		/* control PHY */
		[0] =   275,
		/* SC PHY */
		[1] =  3850,
		[2] =  7700,
		[3] =  9625,
		[4] = 11550,
		[5] = 12512, /* 1251.25 mbps */
		[6] = 13475,
		[7] = 15400,
		[8] = 19250,
		[9] = 23100,
		[10] = 25025,
		[11] = 26950,
		[12] = 30800,
		[13] = 38500,
		[14] = 46200,
		[15] = 50050,
		[16] = 53900,
		[17] = 57750,
		[18] = 69300,
		[19] = 75075,
		[20] = 80850,
	};

	if (WARN_ON_ONCE(rate->mcs >= ARRAY_SIZE(__mcs2bitrate)))
		return 0;

	return __mcs2bitrate[rate->mcs] * rate->n_bonded_ch;
}

static u32 wifi_calculate_bitrate_vht(struct rate_info *rate)
{
	static const u32 base[4][10] = {
		{   6500000,
		   13000000,
		   19500000,
		   26000000,
		   39000000,
		   52000000,
		   58500000,
		   65000000,
		   78000000,
		/* not in the spec, but some devices use this: */
		   86500000,
		},
		{  13500000,
		   27000000,
		   40500000,
		   54000000,
		   81000000,
		  108000000,
		  121500000,
		  135000000,
		  162000000,
		  180000000,
		},
		{  29300000,
		   58500000,
		   87800000,
		  117000000,
		  175500000,
		  234000000,
		  263300000,
		  292500000,
		  351000000,
		  390000000,
		},
		{  58500000,
		  117000000,
		  175500000,
		  234000000,
		  351000000,
		  468000000,
		  526500000,
		  585000000,
		  702000000,
		  780000000,
		},
	};
	u32 bitrate;
	int idx;

	if (rate->mcs > 9)
		goto warn;

	switch (rate->bw) {
	case RATE_INFO_BW_160:
		idx = 3;
		break;
	case RATE_INFO_BW_80:
		idx = 2;
		break;
	case RATE_INFO_BW_40:
		idx = 1;
		break;
	case RATE_INFO_BW_5:
	case RATE_INFO_BW_10:
	default:
		goto warn;
	case RATE_INFO_BW_20:
		idx = 0;
	}

	bitrate = base[idx][rate->mcs];
	bitrate *= rate->nss;

	if (rate->flags & RATE_INFO_FLAGS_SHORT_GI)
		bitrate = (bitrate / 9) * 10;

	/* do NOT round down here */
	return (bitrate + 50000) / 100000;
 warn:
	WARN_ONCE(1, "invalid rate bw=%d, mcs=%d, nss=%d\n",
		  rate->bw, rate->mcs, rate->nss);
	return 0;
}

static u32 wifi_calculate_bitrate_he(struct rate_info *rate)
{
#define SCALE 6144
	u32 mcs_divisors[14] = {
		102399, /* 16.666666... */
		 51201, /*  8.333333... */
		 34134, /*  5.555555... */
		 25599, /*  4.166666... */
		 17067, /*  2.777777... */
		 12801, /*  2.083333... */
		 11769, /*  1.851851... */
		 10239, /*  1.666666... */
		  8532, /*  1.388888... */
		  7680, /*  1.250000... */
		  6828, /*  1.111111... */
		  6144, /*  1.000000... */
		  5690, /*  0.926106... */
		  5120, /*  0.833333... */
	};
	u32 rates_160M[3] = { 960777777, 907400000, 816666666 };
	u32 rates_969[3] =  { 480388888, 453700000, 408333333 };
	u32 rates_484[3] =  { 229411111, 216666666, 195000000 };
	u32 rates_242[3] =  { 114711111, 108333333,  97500000 };
	u32 rates_106[3] =  {  40000000,  37777777,  34000000 };
	u32 rates_52[3]  =  {  18820000,  17777777,  16000000 };
	u32 rates_26[3]  =  {   9411111,   8888888,   8000000 };
	u64 tmp;
	u32 result;

	if (WARN_ON_ONCE(rate->mcs > 13))
		return 0;

	if (WARN_ON_ONCE(rate->he_gi > NL80211_RATE_INFO_HE_GI_3_2))
		return 0;
	if (WARN_ON_ONCE(rate->he_ru_alloc >
			 NL80211_RATE_INFO_HE_RU_ALLOC_2x996))
		return 0;
	if (WARN_ON_ONCE(rate->nss < 1 || rate->nss > 8))
		return 0;

	if (rate->bw == RATE_INFO_BW_160)
		result = rates_160M[rate->he_gi];
	else if (rate->bw == RATE_INFO_BW_80 ||
		 (rate->bw == RATE_INFO_BW_HE_RU &&
		  rate->he_ru_alloc == NL80211_RATE_INFO_HE_RU_ALLOC_996))
		result = rates_969[rate->he_gi];
	else if (rate->bw == RATE_INFO_BW_40 ||
		 (rate->bw == RATE_INFO_BW_HE_RU &&
		  rate->he_ru_alloc == NL80211_RATE_INFO_HE_RU_ALLOC_484))
		result = rates_484[rate->he_gi];
	else if (rate->bw == RATE_INFO_BW_20 ||
		 (rate->bw == RATE_INFO_BW_HE_RU &&
		  rate->he_ru_alloc == NL80211_RATE_INFO_HE_RU_ALLOC_242))
		result = rates_242[rate->he_gi];
	else if (rate->bw == RATE_INFO_BW_HE_RU &&
		 rate->he_ru_alloc == NL80211_RATE_INFO_HE_RU_ALLOC_106)
		result = rates_106[rate->he_gi];
	else if (rate->bw == RATE_INFO_BW_HE_RU &&
		 rate->he_ru_alloc == NL80211_RATE_INFO_HE_RU_ALLOC_52)
		result = rates_52[rate->he_gi];
	else if (rate->bw == RATE_INFO_BW_HE_RU &&
		 rate->he_ru_alloc == NL80211_RATE_INFO_HE_RU_ALLOC_26)
		result = rates_26[rate->he_gi];
	else {
		WARN(1, "invalid HE MCS: bw:%d, ru:%d\n",
		     rate->bw, rate->he_ru_alloc);
		return 0;
	}

	/* now scale to the appropriate MCS */
	tmp = result;
	tmp *= SCALE;
	do_div(tmp, mcs_divisors[rate->mcs]);
	result = tmp;

	/* and take NSS, DCM into account */
	result = (result * rate->nss) / 8;
	if (rate->he_dcm)
		result /= 2;

	return result / 10000;
}

static u32 wifi_calculate_bitrate(struct rate_info *rate)
{
	if (rate->flags & RATE_INFO_FLAGS_MCS)
		return wifi_calculate_bitrate_ht(rate);
	if (rate->flags & RATE_INFO_FLAGS_DMG)
		return wifi_calculate_bitrate_dmg(rate);
	if (rate->flags & RATE_INFO_FLAGS_EDMG)
		return wifi_calculate_bitrate_edmg(rate);
	if (rate->flags & RATE_INFO_FLAGS_VHT_MCS)
		return wifi_calculate_bitrate_vht(rate);
	if (rate->flags & RATE_INFO_FLAGS_HE_MCS)
		return wifi_calculate_bitrate_he(rate);

	return rate->legacy;
}

static int get_wifi_para_for_booster(struct wifi_info *w_info, int w_info_len)
{
	int ret = -1;
	int i;

	for (i = 0; i < w_info_len; i++) {
		struct cfg80211_registered_device *tmp_rdev =
			g_wifi_dev[i].rdev;

		struct net_device *tmp_dev = g_wifi_dev[i].dev;
		u8 *tmp_mac_addr = g_wifi_dev[i].mac_addr;

		if (g_wifi_dev[i].wifi_state_flag == 1 &&
		    tmp_rdev != NULL &&
		    tmp_dev != NULL &&
		    tmp_mac_addr != NULL) {
			struct station_info s_info;

			memset(&s_info, 0, sizeof(s_info));
			if(tmp_rdev->ops->get_station) {
				ret = tmp_rdev->ops->get_station(&tmp_rdev->wiphy,
						tmp_dev, tmp_mac_addr, &s_info);
			}
			if (ret)
				return ret;
			memcpy(w_info[i].name, tmp_dev->name,
				sizeof(tmp_dev->name));
			w_info[i].flag = 1;
			if (s_info.filled & (BIT(NL80211_STA_INFO_RX_BYTES) |
				BIT(NL80211_STA_INFO_RX_BYTES64)))
				w_info[i].rx_bytes = (u32)s_info.rx_bytes;
			if (s_info.filled & (BIT(NL80211_STA_INFO_TX_BYTES) |
				BIT(NL80211_STA_INFO_TX_BYTES64)))
				w_info[i].tx_bytes = (u32)s_info.tx_bytes;
			if (s_info.filled & BIT(NL80211_STA_INFO_SIGNAL))
				w_info[i].rssi = s_info.signal;
			if (s_info.filled & BIT(NL80211_STA_INFO_TX_BITRATE))
				w_info[i].txrate =
				wifi_calculate_bitrate(&s_info.txrate);
			if (s_info.filled & BIT(NL80211_STA_INFO_RX_BITRATE))
				w_info[i].rxrate =
				wifi_calculate_bitrate(&s_info.rxrate);
			if (s_info.filled & BIT(NL80211_STA_INFO_RX_PACKETS))
				w_info[i].rx_packets = s_info.rx_packets;
			if (s_info.filled & BIT(NL80211_STA_INFO_TX_PACKETS))
				w_info[i].tx_packets = s_info.tx_packets;
			if (s_info.filled & BIT(NL80211_STA_INFO_TX_FAILED))
				w_info[i].tx_failed = s_info.tx_failed;
			if (s_info.filled & BIT(NL80211_STA_INFO_NOISE))
				w_info[i].noise = s_info.noise;
			if (s_info.filled & BIT(NL80211_STA_INFO_SNR))
				w_info[i].snr = s_info.snr;
			if (s_info.filled & BIT(NL80211_STA_INFO_CNAHLOAD))
				w_info[i].chload = s_info.chload;
			if (s_info.filled & BIT(NL80211_STA_INFO_UL_DELAY))
				w_info[i].ul_delay = s_info.ul_delay;
		}
	}
	if (g_wifi_dev[0].wifi_state_flag == 1 ||
		g_wifi_dev[1].wifi_state_flag == 1)
		return 0;
	else
		return -1;
}
#endif
static void get_wifi_para(struct wifi_stat *cur, int cnt)
{
	int i;
	struct wifi_info w_info[MAX_WIFI_NUM];

	memset(&w_info[0], 0, MAX_WIFI_NUM * sizeof(struct wifi_info));

	get_wifi_para_for_booster(&w_info[0], MAX_WIFI_NUM);

	for (i = 0; i < cnt; i++) {
		if (strstr(w_info[i].name, "wlan0") == NULL &&
			strstr(w_info[i].name, "wlan1") == NULL)
			continue;
		cur[i].dev_id = i + DEV_INDEX_OFFSET;
		cur[i].flag = w_info[i].flag;
		cur[i].info.rx_bytes = w_info[i].rx_bytes;
		cur[i].info.tx_bytes = w_info[i].tx_bytes;
		cur[i].info.phy_tx_rate = w_info[i].txrate;
		cur[i].info.phy_rx_rate = w_info[i].rxrate;
		cur[i].info.rx_packets = w_info[i].rx_packets;
		cur[i].info.tx_packets = w_info[i].tx_packets;
		cur[i].info.tx_failed = w_info[i].tx_failed;
		cur[i].info.rssi = w_info[i].rssi;

		cur[i].info.noise = w_info[i].noise;
		cur[i].info.snr = w_info[i].snr;
		cur[i].info.chload = w_info[i].chload;
		cur[i].info.ul_delay = w_info[i].ul_delay;

		cur[i].info.arp_state =
			get_wifi_arp_state(w_info[i].name, IFNAMSIZ, g_gateway[i]);
	}
}

static void check_wifi_para(struct wifi_stat *cur, int cnt)
{
	int i;

	if (cur == NULL)
		return;
	for (i = 0; i < cnt; i++) {
		if (cur[i].flag == 0)
			continue;
		if (cur[i].info.rssi < MIN_RSSI ||
			cur[i].info.rssi > MAX_RSSI)
			cur[i].info.rssi = MAX_RSSI;
		if (cur[i].info.noise < MIN_NOISE ||
			cur[i].info.noise > MAX_NOISE)
			cur[i].info.noise = MIN_NOISE;
		if (cur[i].info.snr < MIN_SNR ||
			cur[i].info.snr > MAX_SNR)
			cur[i].info.snr = MAX_SNR;
		if (cur[i].info.chload < MIN_CHLOAD ||
			cur[i].info.chload > MAX_CHLOAD)
			cur[i].info.chload = MIN_CHLOAD;
		if (cur[i].info.ul_delay < MIN_UL_DELAY ||
			cur[i].info.ul_delay > MAX_UL_DELAY)
			cur[i].info.ul_delay = MIN_UL_DELAY;
	}
}

static void update_wifi_res(struct wifi_stat *past,
	struct wifi_stat *cur, struct wifi_stat *res, int cnt)
{
	int i;

	if (past == NULL || res == NULL || cur == NULL)
		return;
	if (cur[WLAN0_IDX].flag == 0 && cur[WLAN1_IDX].flag == 0)
		return;
	for (i = 0; i < cnt; i++) {
		if (past[i].flag == 0 || cur[i].flag == 0) {
			res[i].flag = 0;
			continue;
		}
		res[i].flag = cur[i].flag;
		res[i].dev_id = cur[i].dev_id;
		res[i].info.rx_bytes =
			turn_over(cur[i].info.rx_bytes,
				past[i].info.rx_bytes);
		res[i].info.tx_bytes =
			turn_over(cur[i].info.tx_bytes,
				past[i].info.tx_bytes);
		res[i].info.rssi = cur[i].info.rssi;
		res[i].info.phy_tx_rate
			= cur[i].info.phy_tx_rate;
		res[i].info.phy_rx_rate
			= cur[i].info.phy_rx_rate;
		res[i].info.rx_packets =
			turn_over(cur[i].info.rx_packets,
				past[i].info.rx_packets);
		res[i].info.tx_packets =
			turn_over(cur[i].info.tx_packets,
				past[i].info.tx_packets);
		res[i].info.tx_failed =
			turn_over(cur[i].info.tx_failed,
				past[i].info.tx_failed);
		res[i].info.noise = cur[i].info.noise;
		res[i].info.snr = cur[i].info.snr;
		res[i].info.chload = cur[i].info.chload;
		res[i].info.ul_delay = cur[i].info.ul_delay;
		res[i].info.arp_state = cur[i].info.arp_state;
	}
}

static void update_wifi_para(struct wifi_stat *past,
	struct wifi_stat *cur, int cnt)
{
	if (past == NULL || cur == NULL)
		return;
	if (cur[WLAN0_IDX].flag == 0 && cur[WLAN1_IDX].flag == 0)
		return;
	memcpy(past, cur, cnt * sizeof(struct wifi_stat));
}

static void wifi_para_report()
{
	struct wifi_res_msg *res = NULL;
	struct wifi_stat cur[MAX_WIFI_NUM];
	u16 len;

	if (g_wifi_ctx == NULL)
		return;
	len = sizeof(struct wifi_res_msg) +
		MAX_WIFI_NUM * sizeof(struct wifi_stat);
	res = kmalloc(len, GFP_ATOMIC);
	if (res == NULL)
		return;
	memset(res, 0, len);
	memset(&cur[0], 0, MAX_WIFI_NUM * sizeof(struct wifi_stat));


	get_wifi_para(&cur[0], MAX_WIFI_NUM); // wlan0->cur[0], wlan1->cur[1],
	check_wifi_para(&cur[0], MAX_WIFI_NUM); // flag = 0,invalid
	update_wifi_res(g_wifi_ctx->past, &cur[0], res->wifi_res, MAX_WIFI_NUM);
	update_wifi_para(g_wifi_ctx->past, &cur[0], MAX_WIFI_NUM);

	res->type = WIFI_PARA_RPT;
	res->len = len;
	if (g_wifi_ctx->fn)
		g_wifi_ctx->fn((struct res_msg_head *)res);
	kfree(res);
}

#if LINUX_VERSION_CODE < KERNEL_VERSION(4,19,0)
static void wifi_para_report_timer(unsigned long sync)
#else
static void wifi_para_report_timer(struct timer_list *t)
#endif
{
	struct timer_msg msg;
	char *p = NULL;

	memset(&msg, 0, sizeof(struct timer_msg));
	p = (char *)&msg;
#if LINUX_VERSION_CODE < KERNEL_VERSION(4,19,0)
	g_wifi_ctx->timer.data = sync + 1; // number of reports
#else
	g_wifi_ctx->report_cnt++;
#endif
	g_wifi_ctx->timer.function = wifi_para_report_timer;
	mod_timer(&g_wifi_ctx->timer, jiffies + g_wifi_ctx->expires);

	msg.len = sizeof(struct timer_msg);
	msg.type = WIFI_RPT_TIMER;
#if LINUX_VERSION_CODE < KERNEL_VERSION(4,19,0)
	msg.sync = (u32)sync;
#else
	msg.sync = (u32)g_wifi_ctx->report_cnt;
#endif

	if (g_wifi_ctx->fn)
		g_wifi_ctx->fn((struct res_msg_head *)p);
}

static void stop_wifi_collect(void)
{
	if (!timer_pending(&g_wifi_ctx->timer))
		return;
	del_timer(&g_wifi_ctx->timer);
}

static void start_wifi_collect(struct wifi_req_msg *msg)
{
	u32 expires;

	if (g_wifi_ctx == NULL)
		return;
	expires = msg->report_expires;
	g_gateway[0] = msg->wifi_gateway[0];
	g_gateway[1] = msg->wifi_gateway[1];
	pr_info("[WIFI_PARA]%s,expires=%u", __func__, expires);
	memset(g_wifi_ctx->past, 0, sizeof(struct wifi_stat) * MAX_WIFI_NUM);
	wifi_para_report();
#if LINUX_VERSION_CODE < KERNEL_VERSION(4,19,0)
	g_wifi_ctx->timer.data = 0;
#else
	g_wifi_ctx->report_cnt = 0;
#endif
	g_wifi_ctx->timer.function = wifi_para_report_timer;
	g_wifi_ctx->expires = expires / JIFFIES_MS;
	mod_timer(&g_wifi_ctx->timer, jiffies + g_wifi_ctx->expires);
}

static void update_wifi_collect(struct wifi_req_msg *msg)
{
	g_gateway[0] = msg->wifi_gateway[0];
	g_gateway[1] = msg->wifi_gateway[1];
}

static void cmd_process(struct req_msg_head *msg)
{
	pr_info("[WIFI_PARA]%s,len=%u, type=%u", __func__, msg->len, msg->type);
	if (msg->len > MAX_REQ_DATA_LEN)
		return;
	if (msg->len < sizeof(struct req_msg_head))
		return;
	if (msg->type == WIFI_PARA_COLLECT_START)
		start_wifi_collect((struct wifi_req_msg *)msg);
	else if (msg->type == WIFI_PARA_COLLECT_STOP)
		stop_wifi_collect();
	else if (msg->type == WIFI_RPT_TIMER)
		wifi_para_report();
	else if (msg->type == WIFI_PARA_COLLECT_UPDATE)
		update_wifi_collect((struct wifi_req_msg *)msg);
}

/*
 * Initialize internal variables and external interfaces
 */
msg_process *wifi_para_collec_init(notify_event *fn)
{
	if (fn == NULL)
		return NULL;
	g_wifi_ctx = kmalloc(sizeof(struct wifi_ctx), GFP_KERNEL);
	if (g_wifi_ctx == NULL)
		return NULL;

	memset(g_wifi_ctx, 0, sizeof(struct wifi_ctx));
	g_wifi_ctx->fn = fn;
	g_wifi_ctx->past = kmalloc(sizeof(struct wifi_stat) * MAX_WIFI_NUM,
		GFP_KERNEL);
	if (g_wifi_ctx->past == NULL)
		goto init_error;
	memset(g_wifi_ctx->past, 0, sizeof(struct wifi_stat) * MAX_WIFI_NUM);

#if LINUX_VERSION_CODE < KERNEL_VERSION(4,19,0)
	init_timer(&g_wifi_ctx->timer);
#else
	timer_setup(&g_wifi_ctx->timer, NULL, 0);
#endif
	return cmd_process;

init_error:
	if (g_wifi_ctx != NULL)
		kfree(g_wifi_ctx);
	g_wifi_ctx = NULL;
	return NULL;
}

void wifi_para_collec_exit(void)
{
	if (g_wifi_ctx->past != NULL)
		kfree(g_wifi_ctx->past);
	if (g_wifi_ctx != NULL)
		kfree(g_wifi_ctx);
	g_wifi_ctx = NULL;
}
