/*
 * adapter_protocol_arbitration.h
 *
 * adapter_protocol_arbitration driver
 *
 * Copyright (c) 2022-2022 Honor Device Co., Ltd.
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

#ifndef _ADAPTER_PROTOCOL_ARBITRATION_H_
#define _ADAPTER_PROTOCOL_ARBITRATION_H_

#include <hwpower/adapter_protocol.h>

#define ADAPTER_PROTOCOL_USB_RETRY_MAX_CNT            3
#define ADAPTER_PROTOCOL_REMOVE_RETRY_MAX_CNT         3
#define ADAPTER_PROTOCOL_ONCE_GET_CHG_TYPE_MAX_CNT    10
#define ADAPTER_PROTOCOL_TOTAL_GET_CHG_TYPE_MAX_CNT   80
#define ADAPTER_PROTOCOL_TYPEC_RETRY_MAX_CNT          10

#define ADPATER_PROT_MW_TO_UW         1000
// adapter walt in mW
#define ADAPTER_PROT_WALT_2P5W        2500
#define ADAPTER_PROT_WALT_5W          5000
#define ADAPTER_PROT_WALT_6W          6000
#define ADAPTER_PROT_WALT_7P5W        7500
#define ADAPTER_PROT_WALT_10W         10000
#define ADAPTER_PROT_WALT_18W         18000
#define ADAPTER_PROT_WALT_30W         30000

#define ADAPTER_PROT_WORK_DELAY_TIME      10000  //ms
#define ADAPTER_PROT_ERR_THRESHOLD        8
#define ADAPTER_PROT_SCP_RETRY_THRESHOLD  8
#define ADAPTER_PROT_PPS_RETRY_THRESHOLD  8

#define PD_VOLTAGE_9000MV                 9000

struct adap_prot_err_info {
	int err_cnt;
	int err_cnt_threshold;
	bool valid;
};

struct adap_prot_bc12_retry_info {
	int usb_retry_cnt;
	int not_std_retry_cnt;
	int removed_retry_cnt;
	int total_get_chg_type_cnt;
};

struct adap_prot_adapter_retry_info {
	int retry_cnt;
	int retry_cnt_threshold;
};

struct adap_prot_adapter_info {
	int chg_type;
	int adapter_mode;
	int max_watt_in_mw;
	struct adap_prot_adapter_retry_info retry_info;
};

struct adapter_protocol_extcon_usb_ops {
	void (*extcon_usb_connect)(void);
	void (*extcon_usb_disconnect)(void);
	void (*usb_dpdm_hiz)(int val);
};

struct adapter_protocol_info {
	enum adapter_protocol_type protocol_type;
	int protocol_valid;

	struct adap_prot_err_info prot_err_info;
	struct adap_prot_adapter_info adapter_info;
	int (*get_adapter_info)(struct adap_prot_adapter_info *adapter_info);
};

struct adapter_prot_detect_adapter_info {
	int detect_retry;
	int detect_delay_time;
};

struct adapter_prot_detect_work_info {
	struct adap_prot_bc12_retry_info bc12_retry_info;
	struct adapter_prot_detect_adapter_info detect_adapter_info;
};

struct adapter_prot_arbitration_info {
	bool is_arbitration_done;
	struct mutex arbitration_lock;
	struct notifier_block event_nb;
	struct delayed_work usb_detect_work;
	struct delayed_work typec_detect_work;
	struct delayed_work adapter_detect_work;
	struct adapter_prot_detect_work_info detect_work_info;

	int adapter_plug;
	int allow_bc12;
	int usb_type;
	int typec_type;

	struct adapter_protocol_info protocol_info[ADAPTER_PROTOCOL_MAX_COUNT];
	struct adapter_protocol_extcon_usb_ops *extcon_ops;
};

int adapter_protocol_get_arbitration_result(int *prot, int *chg_type, int *adap_mode);
void adapter_protocol_arbitration(int adapter_plug, int allow_bc12);

int adapter_protocol_extcon_usb_register(struct adapter_protocol_extcon_usb_ops *ops);

int adapter_protocol_arbitration_probe(struct platform_device *pdev);
void adapter_protocol_arbitration_remove(struct platform_device *pdev);

#endif /* _ADAPTER_PROTOCOL_ARBITRATION_H_ */
