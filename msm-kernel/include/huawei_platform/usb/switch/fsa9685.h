/*
 * fsa9685.h
 *
 * head file for fsa9685 driver
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

#ifndef _FSA9685_H_
#define _FSA9685_H_

#include <linux/power/huawei_charger.h>
#include <huawei_platform/usb/hw_pd_dev.h>

/* fsa9688 serial */
#define FSA9683_VERSION_ID                               0x1
#define FSA9688_VERSION_ID                               0x2
#define FSA9688C_VERSION_ID                              0x3
#define FSA9685_VENDOR_ID                                0x0

/* ID validity detection */
#define ID_VALID                                         1
#define ID_INVALID                                       0
#define MAX_DETECTION_TIMES                              3

struct fsa9685_device_info {
	struct device *dev;
	struct i2c_client *client;
	int device_id;

	struct mutex accp_detect_lock;
	struct mutex accp_adaptor_reg_lock;
	struct wakeup_source usb_switch_lock;

	struct work_struct intb_work;
	struct delayed_work detach_delayed_work;

	u32 fcp_support;
	u32 scp_support;
	u32 two_switch_flag; /* disable for two switch */
	u32 pd_support;
	u32 dcd_timeout_force_enable;
	u32 power_by_5v;
	struct delayed_work chg_det_work;
	struct delayed_work update_type_work;

	bool attach;
	struct power_supply *usb_psy;
	struct power_supply *ac_psy;
	unsigned int chg_type;
	atomic_t chg_type_det;
};

struct fsa9685_device_info *fsa9685_get_dev_info(void);
int fsa9685_get_gpio(void);
int fsa9685_is_support_fcp(struct fsa9685_device_info *di);

#endif /* _FSA9685_H_ */
