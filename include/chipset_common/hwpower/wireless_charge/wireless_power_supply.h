/*
 * wireless_power_supply.h
 *
 * common interface, varibles, definition etc for wireless power supply
 *
 * Copyright (c) 2020-2020 Honor Device Co., Ltd.
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

#ifndef _WIRELESS_POWER_SUPPLY_H_
#define _WIRELESS_POWER_SUPPLY_H_

#define WLPS_ENABLE          1

#define WLPS_CTRL_ON         1
#define WLPS_CTRL_OFF        0
#define WLPS_TX_VSET_MAX     3

#define WIRELESS_CHANNEL_CUTOFF   0
#define WIRELESS_CHANNEL_RESTORE  1
#define WIRELESS_CHANNEL_FOREWORD 0
#define WIRELESS_CHANNEL_BACKWORD 1
#define WLC_RX_EXT_PWR_SW_VOTE_OBJECT     "wlc_rx_ext_pwr_sw"
#define WLC_RX_EXT_PWR_ENABLE      1
#define WLC_RX_EXT_PWR_DISABLE     0

enum wlps_ctrl_scene {
	WLPS_PROBE_PWR = 0,
	WLPS_SYSFS_EN_PWR,
	WLPS_PROC_OTP_PWR,
	WLPS_RECOVER_OTP_PWR,
	WLPS_RX_EXT_PWR,
	WLPS_TX_PWR_SW,
	WLPS_RX_SW,
	WLPS_RX_SW_AUX,
	WLPS_TX_SW,
	WLPS_SC_SW2,
	WLPS_TX_PMU_SW,
	WLPS_TX_VBUS_SW,
	WLPS_TX_9V_SW,
	WLPS_TX_SC_SW,
	WLPS_MAX,
};

enum wlps_chip_power_type {
	WLPS_CHIP_PWR_NULL = 0,
	WLPS_CHIP_PWR_RX,
	WLPS_CHIP_PWR_TX,
};

enum wlps_tx_chip_ctrl_src {
	WLPS_TX_CHIP_NA = 0,
	WLPS_TX_SRC_TX_CHIP,
	WLPS_TX_CHIP_MAX,
};

struct wlps_tx_ops {
	int (*tx_vset)(int);
};
struct wlps_rx_ops {
	void (*ext_pwr_prev_ctrl)(int);
	void (*ext_pwr_post_ctrl)(int);
};

struct wlps_wc_vout_ops {
	void *dev_data;
	int (*wc_vout_ctrl)(int, void *);
	int (*wc_vout_ctrl_mode)(int, void *);
	int (*wc_vout_reverse_ctrl)(int, void *);
};

struct wlps_dev_info {
	struct device *dev;
	int gpio_tx_sppwr_en;
	int gpio_tx_sppwr_en_valid_val;
	int gpio_txsw;
	int gpio_txsw_valid_val;
	int gpio_rxsw;
	int gpio_rxsw_valid_val;
	int gpio_rxsw_aux;
	int gpio_rxsw_aux_valid_val;
	int gpio_ext_pwr_sw;
	int gpio_ext_pwr_sw_valid_val;
	int gpio_sc_sw2;
	int gpio_sc_sw2_valid_val;
	int wlps_ready;
	enum wlps_chip_power_type sysfs_en_pwr;
	enum wlps_chip_power_type proc_otp_pwr;
	enum wlps_chip_power_type recover_otp_pwr;
};

#if IS_ENABLED(CONFIG_WIRELESS_CHARGER)
int wlps_tx_ops_register(struct wlps_tx_ops *ops);
int wlps_rx_ops_register(struct wlps_rx_ops *ops);
void wlps_control(enum wlps_ctrl_scene scene, int ctrl_flag);
int wlps_tx_mode_vset(int tx_vset);
void wlc_rx_ext_pwr_prev_ctrl(int flag);
void wlc_rx_ext_pwr_post_ctrl(int flag);
int wlps_wc_vout_ops_register(unsigned int type, struct wlps_wc_vout_ops *ops);
void wlps_wc_vout_ctrl(unsigned int type, int flag);
void wlps_wc_vout_ctrl_mode(unsigned int type, int mode);
int wlps_wc_vout_reverse_ctrl(unsigned int type, int mode);
void wlps_rx_dev_check(const char *rx_fac, int flag);
int wlc_rx_ext_pwr_sw_enable(bool enable, const char *client_name);
int wlps_ready_status(void);

#else
void wlc_rx_ext_pwr_prev_ctrl(int flag) { return;}
void wlc_rx_ext_pwr_post_ctrl(int flag) { return;}

static inline int wlps_tx_ops_register(struct wlps_tx_ops *ops)
{
	return 0;
}
static inline int wlps_rx_ops_register(struct wlps_rx_ops *ops)
{
	return 0;
}

static inline void wlps_control(enum wlps_ctrl_scene scene, int ctrl_flag)
{
}

static inline int wlps_tx_mode_vset(int tx_vset)
{
	return 0;
}

static inline int wlps_wc_vout_ops_register(unsigned int type, struct wlps_wc_vout_ops *ops)
{
	return 0;
}

static inline void wlps_wc_vout_ctrl(unsigned int type, int flag)
{
	return;
}

static inline void wlps_wc_vout_ctrl_mode(unsigned int type, int mode)
{
	return;
}

static inline int wlps_wc_vout_reverse_ctrl(unsigned int type, int mode)
{
	return 0;
}

static inline int wlc_rx_ext_pwr_sw_enable(bool enable, const char *client_name)
{
	return 0;
}

static inline int wlps_ready_status(void)
{
	return 0;
}
#endif /* CONFIG_WIRELESS_CHARGER */

#endif /* _WIRELESS_POWER_SUPPLY_H_ */
