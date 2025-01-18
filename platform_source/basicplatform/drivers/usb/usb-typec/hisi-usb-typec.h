/*
 * Copyright (C) 2018 Hisilicon
 * Author: Hisillicon <>
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef _LOCAL_HISI_USB_TYPEC_H_
#define _LOCAL_HISI_USB_TYPEC_H_

#define ADAPTER_CAP_MAX_NR 10

struct adapter_power_cap {
	uint8_t selected_cap_idx;
	uint8_t nr;
	uint8_t pdp;
	uint8_t pwr_limit[ADAPTER_CAP_MAX_NR];
	int32_t max_mv[ADAPTER_CAP_MAX_NR];
	int32_t min_mv[ADAPTER_CAP_MAX_NR];
	int32_t ma[ADAPTER_CAP_MAX_NR];
	int32_t maxwatt[ADAPTER_CAP_MAX_NR];
	int32_t minwatt[ADAPTER_CAP_MAX_NR];
	uint8_t type[ADAPTER_CAP_MAX_NR];
	int info[ADAPTER_CAP_MAX_NR];
};

enum adapter_cap_type {
	HISI_PD_APDO_START,
	HISI_PD_APDO_END,
	HISI_PD,
	HISI_PD_APDO,
	HISI_CAP_TYPE_UNKNOWN,
};

enum adapter_return_value {
	ADAPTER_OK = 0,
	ADAPTER_NOT_SUPPORT,
	ADAPTER_TIMEOUT,
	ADAPTER_REJECT,
	ADAPTER_ERROR,
	ADAPTER_ADJUST,
};

void hisi_usb_typec_set_vconn(int enable);
int hisi_usb_typec_register_pd_dpm(void);
void hisi_usb_typec_register_tcpc_device(struct tcpc_device *tcpc_dev);
void hisi_usb_typec_max_power(int max_power);
void hisi_usb_typec_reset_product(void);
void hisi_usb_typec_cc_status_change(uint8_t cc1, uint8_t cc2);
void hisi_usb_typec_cc_alert(uint8_t cc1, uint8_t cc2);
bool hisi_usb_typec_charger_type_pd(void);
void hisi_usb_pd_dp_state_change(struct tcp_ny_ama_dp_state *ama_dp_state);
void hisi_usb_pd_dp_hpd_state_change(
		struct tcp_ny_ama_dp_hpd_state *ama_dp_hpd_state);
void hisi_usb_pd_ufp_update_dock_svid(uint16_t svid);
void hisi_usb_typec_dfp_inform_id(uint32_t *payload, uint32_t size);
void hisi_pd_put_cc_detached_event(struct tcpc_device *tcpc_dev);
void hisi_usb_typec_cc_ovp_dmd_report(void);
int hisi_usb_typec_otg_pwr_src(void);
bool hisi_usb_typec_force_vconn(void);
bool hisi_usb_get_pd_neg_event(struct tcpc_device *tcpc_dev);
void hisi_usb_set_pd_neg_event(struct tcpc_device *tcpc_dev, bool flag);
bool hisi_usb_get_rev_sc_dev_flag(void);
void hisi_usb_set_rev_sc_dev_flag(bool flag);
void hisi_usb_set_rev_sc_switch_flag(int rever_flag);
void set_rchg_unattach_timer(struct tcpc_device *tcpc);
void hisi_usb_rpd_update_src_cap(void *client, struct otg_cap *allow_ext, int send);
int hisi_usb_rpd_get_src_extcap(void *client);
void hisi_usb_rpd_set_src_cap(struct tcpc_device *tcpc_dev, struct otg_cap *allow_ext, int send);
int hisi_usb_get_src_extcap(struct tcpc_device *tcpc_dev);
#ifdef CONFIG_DUAL_ROLE_USB_INTF
void tcpc_drive_path_prop(int val, struct tcpc_device *tcpc);
bool hisi_usb_first_attach_rscp(void);
int get_state_path(struct tcpc_device *tcpc);
bool timer_called_by_timeout(struct tcpc_device *tcpc);
bool rchg_check_cc_state(struct tcpc_device *tcpc);
bool get_first_attach(struct tcpc_device *tcpc);
void clear_rchg_rever_flag(struct tcpc_device *tcpc);
bool get_reverse_charge_enable(struct tcpc_device *tcpc);
bool get_pd_unattach_state(struct tcpc_device *tcpc);
bool hisi_usb_reverse_charge_unattach_state(void);
int hisi_usb_is_reverse_charge_enable(void);
#endif
#endif
