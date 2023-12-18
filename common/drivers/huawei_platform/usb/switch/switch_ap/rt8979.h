/*
 * rt8979.h
 *
 * head file for rt8979 driver
 *
 * Copyright (c) 2021-2021 Huawei Technologies Co., Ltd.
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

#ifndef _RT8979_H_
#define _RT8979_H_

#include <linux/power/huawei_charger.h>
#include <huawei_platform/usb/hw_pd_dev.h>

/* rt8979 serial */
#define RT8979_1_VERSION_ID                              0x1
#define RT8979_2_VERSION_ID                              0x2
#define RT8979_VENDOR_ID                                 0x1

#define RT8979_ACCP_DM_TRANSFER_CHECK_WAIT_TIME          40
#define RT8979_ADJ_OSC_MAX_COUNT                         10

enum {
	RT8979_SUCCESS = 0,
	RT8979_FAIL,
	RT8979_RETRY,
};

enum rt8979_usb_status {
	RT8979_USB_STATUS_NOVBUS,
	RT8979_USB_STATUS_UNDER_GOING,
	RT8979_USB_STATUS_SDP,
	RT8979_USB_STATUS_SDP_NSTD,
	RT8979_USB_STATUS_DCP,
	RT8979_USB_STATUS_CDP,
};

struct rt8979_device_info {
	struct device *dev;
	struct i2c_client *client;
	int device_id;

	struct mutex accp_detect_lock;
	struct mutex accp_adaptor_reg_lock;

	u32 fcp_support;
	u32 scp_support;
	u32 two_switch_flag; /* disable for two switch */
	u32 pd_support;
	u32 dcd_timeout_force_enable;
	u32 power_by_5v;

	struct rt8979_desc *desc;
	u32 intr_gpio;
	int irq;
	u8 irq_mask;
	bool attach;
	int hidden_mode_cnt;
	struct mutex io_lock;
	struct mutex hidden_mode_lock;
	struct mutex bc12_lock;
	struct mutex bc12_en_lock;
	struct delayed_work psy_dwork;
	struct power_supply *usb_psy;
	struct power_supply *ac_psy;
	unsigned int chg_type;
	enum rt8979_usb_status us;
	struct wakeup_source *bc12_en_ws;
	struct task_struct *bc12_en_kthread;
	int bc12_en_buf[2];
	int bc12_en_buf_idx;
	bool nstd_retrying;
	u8 sdp_retried;
	atomic_t chg_type_det;
	atomic_t bc12_en_req_cnt;
	wait_queue_head_t bc12_en_req;
	bool resume_completed;
	bool irq_waiting;
	struct mutex irq_lock;
};

struct rt8979_device_info *rt8979_get_dev_info(void);
int rt8979_is_support_fcp(struct rt8979_device_info *di);

#endif /* _RT8979_H_ */
