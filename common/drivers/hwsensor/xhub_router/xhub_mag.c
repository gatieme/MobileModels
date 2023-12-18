/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2019. All rights reserved.
 * Team:    Huawei DIVS
 * Date:    2021.07.20
 * Description: xhub pm module
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

#include "xhub_mag.h"
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/semaphore.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/sched.h>
#include <asm/uaccess.h>
#include <asm/io.h>
#include <linux/sysfs.h>
#include <securec.h>
#include <linux/fb.h>
#include <../apsensor_channel/ap_sensor_route.h>
#include <../apsensor_channel/ap_sensor.h>
#include <linux/hrtimer.h>
#include <linux/backlight.h>
#include <linux/completion.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <chipset_common/hwpower/common_module/power_dts.h>
#include <huawei_platform/hwpower/common_module/power_platform.h>
#include <securec.h>

static atomic_t enabled = ATOMIC_INIT(0);
int (*send_func)(int) = NULL;
static int charge_status;
static int charge_offset_x;
static int charge_offset_y;
static int charge_offset_z;
static int coef_x = COEF_VALUE;
static int coef_y = COEF_VALUE;
static int coef_z = COEF_VALUE;

static void get_current_work_func(struct work_struct *work);
DECLARE_DELAYED_WORK(read_current_work, get_current_work_func);

static int mag_charge_dts_read_str2int(const struct device_node *np,
	const char *prop, int *data)
{
	const char *tmp_string = NULL;

	if (!np || !prop || !data) {
		pr_err("np or prop or data is null\n");
		return -1;
	}

	if (of_property_read_string(np, prop, &tmp_string)) {
		pr_err("prop %s read fail\n", prop);
		return -1;
	}
	if (kstrtoint(tmp_string, 0, data)) {
		pr_err("prop %s kstrtoint fail\n", prop);
		return -1;
	}

	return 0;
}

static void mag_charge_get_info_from_dts(void)
{
	int ret = 0;
	int data = 0;
	struct device_node *mag_node = NULL;

	mag_node = of_find_compatible_node(NULL, NULL, "huawei,xhub_mag");
	if (mag_node == NULL) {
		pr_err("Cannot find mag mode from dts\n");
		return;
	}

	ret = of_property_read_u32(mag_node, "charge_enable", &data);
	if (!ret) {
		pr_info("%s, charge_enable is :%d\n", __func__, data);
		charge_status = data;
	} else {
		charge_status = 0;
		pr_err("%s, Cannot find charge_enable\n", __func__);
	}

	ret = mag_charge_dts_read_str2int(mag_node, "mag_offset_x", &data);
	if (!ret) {
		pr_info("%s, mag_offset_x is :%d\n", __func__, data);
		charge_offset_x = data;
	} else {
		charge_offset_x = 0;
		pr_err("%s, Cannot find mag_offset_x\n", __func__);
	}
	ret = mag_charge_dts_read_str2int(mag_node, "mag_offset_y", &data);
	if (!ret) {
		pr_info("%s, mag_offset_y is :%d\n", __func__, data);
		charge_offset_y = data;
	} else {
		charge_offset_y = 0;
		pr_err("%s, Cannot find mag_offset_y\n", __func__);
	}

	ret = mag_charge_dts_read_str2int(mag_node, "mag_offset_z", &data);
	if (!ret) {
		pr_info("%s, mag_offset_z is :%d\n", __func__, data);
		charge_offset_z = data;
	} else {
		charge_offset_z = 0;
		pr_err("%s, Cannot find mag_offset_z\n", __func__);
	}

	coef_x = (charge_offset_x >= 0 ? COEF_VALUE : -COEF_VALUE);
	coef_y = (charge_offset_y >= 0 ? COEF_VALUE : -COEF_VALUE);
	coef_z = (charge_offset_z >= 0 ? COEF_VALUE : -COEF_VALUE);
	pr_info("%s, %d %d %d\n", __func__, coef_x, coef_y, coef_z);
}

static void get_current_work_func(struct work_struct *work)
{
	int value = 0;

	value = power_platform_get_battery_current();
	/* send current to iom3 */
	if (send_func)
		(*send_func)(value);

	if (atomic_read(&enabled))
		queue_delayed_work(system_power_efficient_wq, &read_current_work,
			msecs_to_jiffies(READ_CURRENT_INTERVAL));
}

static int open_send_current(int (*send)(int))
{
	if (!atomic_cmpxchg(&enabled, 0, 1)) {
		queue_delayed_work(system_power_efficient_wq, &read_current_work,
			msecs_to_jiffies(READ_CURRENT_INTERVAL));
		send_func = send;
	} else {
		pr_info("%s allready opend\n", __func__);
	}
	return 0;
}

static int close_send_current(void)
{
	if (atomic_cmpxchg(&enabled, 1, 0))
		cancel_delayed_work_sync(&read_current_work);

	return 0;
}

static int send_current_to_mcu_mag(int current_value_now)
{
	mag_buf_to_hal_t charge_current_data;
	if (memset_s(&charge_current_data, sizeof(charge_current_data),
		0, sizeof(charge_current_data)) != EOK)
		return 0;

	current_value_now = -current_value_now;
	if (current_value_now < CURRENT_MIN_VALUE ||
		current_value_now > CURRENT_MAX_VALUE)
		return 0;

	charge_current_data.sensor_type = SENSOR_TYPE_MAG;
	charge_current_data.cmd = 1;
	charge_current_data.current_value = current_value_now;

	charge_current_data.current_offset_x = (charge_offset_x *
		current_value_now + coef_x * MAG_ROUND_FAC) / MAG_CURRENT_FAC_RAIO;
	charge_current_data.current_offset_y = (charge_offset_y *
		current_value_now + coef_y * MAG_ROUND_FAC) / MAG_CURRENT_FAC_RAIO;
	charge_current_data.current_offset_z = (charge_offset_z *
		current_value_now + coef_z * MAG_ROUND_FAC) / MAG_CURRENT_FAC_RAIO;
	pr_info("%s %d %d %d %d %d\n", __func__, charge_current_data.cmd, charge_current_data.current_offset_x,
		charge_current_data.current_offset_y, charge_current_data.current_offset_z, current_value_now);
	ap_sensor_route_write((char *)&charge_current_data,
		(sizeof(charge_current_data.current_offset_x) + MAG_IOCTL_PKG_HEADER));
	return 0;
}

static void mag_charge_notify_close(void)
{
	mag_buf_to_hal_t charge_current_data;
	close_send_current();
	if (memset_s(&charge_current_data, sizeof(charge_current_data),
		0, sizeof(charge_current_data)) != EOK)
		return;

	charge_current_data.sensor_type = SENSOR_TYPE_MAG;
	charge_current_data.cmd = 0;
	ap_sensor_route_write((char *)&charge_current_data,
		(sizeof(charge_current_data.current_offset_x) + MAG_IOCTL_PKG_HEADER));
}

static void mag_charge_notify_open(void)
{
	open_send_current(send_current_to_mcu_mag);
}

static int xhub_mag_notifier_call(struct notifier_block *nb,
	unsigned long event, void *data)
{
	if (charge_status == 0)
		return NOTIFY_DONE;

	switch (event) {
	case POWER_NE_USB_DISCONNECT:
	case POWER_NE_WIRELESS_DISCONNECT:
		pr_info("%s, close event = %d\n", __func__, event);
		mag_charge_notify_close();
		break;
	case POWER_NE_USB_CONNECT:
	case POWER_NE_WIRELESS_CONNECT:
		pr_info("%s, open event = %d\n", __func__, event);
		mag_charge_notify_open();
		break;
	default:
		return NOTIFY_DONE;
	}
	return NOTIFY_DONE;
}

static struct notifier_block xhub_mag_notify = {
	.notifier_call = xhub_mag_notifier_call,
};

static int xhub_mag_register(void)
{
	mag_charge_get_info_from_dts();
	(void)power_event_bnc_register(0, &xhub_mag_notify);
	return 0;
}

static void xhub_mag_exit(void)
{
	pr_info("xhub_mag_exit\n");
	return;
}

late_initcall_sync(xhub_mag_register);
module_exit(xhub_mag_exit);

MODULE_LICENSE("GPL");
