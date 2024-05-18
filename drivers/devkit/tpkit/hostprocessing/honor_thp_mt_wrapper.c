/*
 * Honor Touchscreen Driver
 *
 * Copyright (c) 2012-2021 Honor Technologies Co., Ltd.
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

#include "honor_thp_mt_wrapper.h"
#include "honor_thp.h"
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/input.h>
#include <linux/input/mt.h>
#include <linux/miscdevice.h>
#include <linux/uaccess.h>
#if (!(IS_ENABLED(CONFIG_HONOR_THP_QCOM) || IS_ENABLED(CONFIG_HONOR_THP_MTK)))
#include <honor_platform/log/hw_log.h>
#endif
#include <linux/slab.h>
#include <linux/poll.h>
#include <linux/delay.h>
#if defined(CONFIG_FB)
#include <linux/notifier.h>
#include <linux/fb.h>
#endif

#ifdef CONFIG_INPUTHUB_20
#include "contexthub_recovery.h"
#endif

#ifdef CONFIG_HONOR_PS_SENSOR
#include "ps_sensor.h"
#endif

#ifdef CONFIG_HONOR_SENSORS_2_0
#include "sensor_scp.h"
#endif
#define trace_touch(x...)

#define DEVICE_NAME "input_mt_wrapper"
#define SECOND 1000000
#define NO_DELAY 0
#define DELAY_LIMIT_FRAME_COUNT 5
#define SUPPORT_PEN_PROTOCOL_CLASS 2
#define SUPPORT_PEN_PROTOCOL_CODE 4

extern struct thp_core_data *g_thp_core;
extern struct thp_core_data *g_thp_core_sub;

struct thp_vendor_name {
	const char *vendor_id;
	const char *compatible_name;
};

/*
 * use 2 bits vendor_id in project_id to distinguish LCD IC.
 * 09: SDC, 13: BOE
 */
static struct thp_vendor_name thp_input_compatible_table[] = {
	{ "09", "honor,thp_input_09" },
	{ "13", "honor,thp_input_13" },
};

static struct thp_core_data *misc_dev_get_core_data(struct miscdevice *dev)
{
	struct thp_core_data *cd = NULL;

	if (dev == NULL) {
		thp_log_err(cd, "%s: miscdevice is NULL\n", __func__);
		return NULL;
	}
	if (g_thp_core && g_thp_core->thp_mt_wrapper_misc_device) {
		if (dev->name == g_thp_core->thp_mt_wrapper_misc_device->name)
			return g_thp_core;
	}
	if (g_thp_core_sub && g_thp_core_sub->thp_mt_wrapper_misc_device) {
		if (dev->name == g_thp_core_sub->thp_mt_wrapper_misc_device->name)
			return g_thp_core_sub;
	}

	return NULL;
}

void thp_inputkey_report(struct thp_core_data *cd, unsigned int gesture_wakeup_value)
{
	input_report_key(cd->thp_mt_wrapper->input_dev, gesture_wakeup_value, 1);
	input_sync(cd->thp_mt_wrapper->input_dev);
	input_report_key(cd->thp_mt_wrapper->input_dev, gesture_wakeup_value, 0);
	input_sync(cd->thp_mt_wrapper->input_dev);
	thp_log_info(cd, "%s ->done\n", __func__);
}

#if (IS_ENABLED(CONFIG_HONOR_THP_QCOM) || IS_ENABLED(CONFIG_HONOR_THP_MTK))
void thp_aod_click_report(struct thp_core_data *cd, struct thp_udfp_data udfp_data)
{
	unsigned int x;
	unsigned int y;
	struct input_dev *input_dev = cd->thp_mt_wrapper->input_dev;

	if (input_dev == NULL) {
		thp_log_err(cd, "%s: have null ptr\n", __func__);
		return;
	}
	x = udfp_data.tpud_data.tp_x;
	y = udfp_data.tpud_data.tp_y;
	input_report_abs(input_dev, ABS_MT_POSITION_X, x);
	input_report_abs(input_dev, ABS_MT_POSITION_Y, y);
	if (!cd->support_b_protocol)
		input_mt_sync(input_dev);

	input_report_key(input_dev, TS_SINGLE_CLICK, THP_KEY_DOWN);
	input_sync(input_dev);
	input_report_key(input_dev, TS_SINGLE_CLICK, THP_KEY_UP);
	input_sync(input_dev);
	thp_log_info(cd, "%s ->done, (%u, %u)\n", __func__, x, y);
}

void thp_udfp_event_to_aod(struct thp_core_data *cd, struct thp_udfp_data udfp_data)
{
	struct input_dev *input_dev = cd->thp_mt_wrapper->input_dev;

	if (input_dev == NULL) {
		thp_log_err(cd, "%s: have null ptr\n", __func__);
		return;
	}
	if (udfp_data.tpud_data.udfp_event == TP_EVENT_FINGER_DOWN) {
		thp_log_info(cd, "%s FINGER_DOWN\n", __func__);
		input_report_key(input_dev, KEY_FINGER_DOWN, THP_KEY_DOWN);
		input_sync(input_dev);
		input_report_key(input_dev, KEY_FINGER_DOWN, THP_KEY_UP);
		input_sync(input_dev);
	}
	if (udfp_data.tpud_data.udfp_event == TP_EVENT_FINGER_UP) {
		thp_log_info(cd, "%s FINGER_UP\n", __func__);
		input_report_key(input_dev, KEY_FINGER_UP, THP_KEY_DOWN);
		input_sync(input_dev);
		input_report_key(input_dev, KEY_FINGER_UP, THP_KEY_UP);
		input_sync(input_dev);
	}
}

void thp_tui_report_to_input(struct thp_core_data *cd, struct thp_udfp_data udfp_data)
{
	unsigned int x;
	unsigned int y;
	int value = 0;
	struct input_dev *input_dev = cd->thp_mt_wrapper->input_dev;

	if (input_dev == NULL) {
		thp_log_err(cd, "%s: have null ptr\n", __func__);
		return;
	}

	if (udfp_data.tpud_data.udfp_event == TP_EVENT_FINGER_DOWN) {
		value = 0;
	} else if (udfp_data.tpud_data.udfp_event == TP_EVENT_FINGER_UP) {
		value = -1;
	} else {
		thp_log_info(cd, "%s: ignore the move event here\n", __func__);
		return;
	}
	input_report_abs(input_dev, ABS_MT_TRACKING_ID, value);

	x = udfp_data.tpud_data.tp_x;
	y = udfp_data.tpud_data.tp_y;
	input_report_abs(input_dev, ABS_MT_POSITION_X, x);
	input_report_abs(input_dev, ABS_MT_POSITION_Y, y);
	input_mt_sync(input_dev);

	if (udfp_data.tpud_data.udfp_event == TP_EVENT_FINGER_DOWN) {
		input_report_key(input_dev, BTN_TOUCH, 1);
		input_sync(input_dev);
	} else if (udfp_data.tpud_data.udfp_event == TP_EVENT_FINGER_UP) {
		input_report_key(input_dev, BTN_TOUCH, 0);
		input_sync(input_dev);
	}

	thp_log_info(cd, "%s ->done, %s, (%u, %u)\n", __func__, input_dev->name, x, y, udfp_data.tpud_data.udfp_event);
}
#endif

void thp_input_pen_report(struct thp_core_data *cd, unsigned int pen_event_value)
{
	input_report_key(cd->thp_mt_wrapper->pen_dev, pen_event_value, 1);
	input_sync(cd->thp_mt_wrapper->pen_dev);
	input_report_key(cd->thp_mt_wrapper->pen_dev, pen_event_value, 0);
	input_sync(cd->thp_mt_wrapper->pen_dev);
	thp_log_info(cd, "%s:done\n", __func__);
}

int thp_mt_wrapper_ioctl_get_events(struct thp_core_data *cd, unsigned long event)
{
	int t;
	int __user *events = (int *)(uintptr_t)event;

	if ((!cd) || (!events)) {
		thp_log_info(cd, "%s: input null\n", __func__);
		return -ENODEV;
	}

	thp_log_info(cd, "%d: cd->event_flag\n", cd->event_flag);
	if (cd->event_flag) {
		if (copy_to_user(events, &cd->event, sizeof(cd->event))) {
			thp_log_err(cd, "%s:copy events failed\n", __func__);
			return -EFAULT;
		}

		cd->event_flag = false;
	} else {
		cd->thp_event_waitq_flag = WAITQ_WAIT;
		t = wait_event_interruptible(cd->thp_event_waitq,
			(cd->thp_event_waitq_flag == WAITQ_WAKEUP));
		thp_log_info(cd, "%s: set wait finish :%d\n", __func__, t);
	}

	return 0;
}

static void thp_adjustment_coordinate(struct thp_core_data *cd)
{
	unsigned int delta_time;
	unsigned int delay_time;
	unsigned int time_interval;

	if (!cd->frame_count)
		time_interval = cd->time_interval;
	else if (cd->frame_count < DELAY_LIMIT_FRAME_COUNT)
		time_interval = cd->time_min_interval;
	else
		time_interval = NO_DELAY;
	get_timestamp(&cd->report_cur_time);
	delta_time = ((cd->report_cur_time.tv_sec -
		cd->report_pre_time.tv_sec) * SECOND) +
		cd->report_cur_time.tv_usec - cd->report_pre_time.tv_usec;

	if (delta_time < time_interval) {
		delay_time = time_interval - delta_time;
		udelay(delay_time);
		get_timestamp(&cd->report_cur_time);
	}
	cd->report_pre_time = cd->report_cur_time;
}

static void thp_coordinate_report(struct thp_core_data *cd, struct thp_mt_wrapper_ioctl_touch_data data)
{
	struct input_dev *input_dev = cd->thp_mt_wrapper->input_dev;
	unsigned int i;

	for (i = 0; i < INPUT_MT_WRAPPER_MAX_FINGERS; i++) {
		if (cd->support_b_protocol) {
			input_mt_slot(input_dev, i);
			input_mt_report_slot_state(input_dev,
				data.touch[i].tool_type,
				data.touch[i].valid != 0);
		}
		if (data.touch[i].valid != 0) {
			input_report_abs(input_dev, ABS_MT_POSITION_X,
						data.touch[i].x);
			input_report_abs(input_dev, ABS_MT_POSITION_Y,
						data.touch[i].y);
			input_report_abs(input_dev, ABS_MT_PRESSURE,
						data.touch[i].pressure);
			input_report_abs(input_dev, ABS_MT_TRACKING_ID,
						data.touch[i].tracking_id);
			input_report_abs(input_dev, ABS_MT_TOUCH_MAJOR,
						data.touch[i].major);
			input_report_abs(input_dev, ABS_MT_TOUCH_MINOR,
						data.touch[i].minor);
			input_report_abs(input_dev, ABS_MT_ORIENTATION,
						data.touch[i].orientation);
			input_report_abs(input_dev, ABS_MT_TOOL_TYPE,
						data.touch[i].tool_type);
			input_report_abs(input_dev, ABS_MT_BLOB_ID,
						data.touch[i].hand_side);
			if (!cd->support_b_protocol)
				input_mt_sync(input_dev);
		}
	}
	/* BTN_TOUCH DOWN */
	if (data.t_num > 0)
		input_report_key(input_dev, BTN_TOUCH, 1);
	/* BTN_TOUCH UP */
	if (data.t_num == 0) {
		if (!cd->support_b_protocol)
			input_mt_sync(input_dev);
		input_report_key(input_dev, BTN_TOUCH, 0);
	}
	input_sync(input_dev);
}

static long thp_mt_wrapper_ioctl_set_coordinate(struct thp_core_data *cd, unsigned long arg)
{
	void __user *argp = (void __user *)(uintptr_t)arg;
	struct thp_mt_wrapper_ioctl_touch_data data;

	trace_touch(TOUCH_TRACE_ALGO_SET_EVENT, TOUCH_TRACE_FUNC_IN, "thp");
	if (arg == 0) {
		thp_log_err(cd, "%s:arg is null\n", __func__);
		return -EINVAL;
	}

	if (copy_from_user(&data, argp, sizeof(data))) {
		thp_log_err(cd, "Failed to copy_from_user()\n");
		return -EFAULT;
	}
	trace_touch(TOUCH_TRACE_ALGO_SET_EVENT, TOUCH_TRACE_FUNC_OUT, "thp");

	trace_touch(TOUCH_TRACE_INPUT, TOUCH_TRACE_FUNC_IN, "thp");

	if ((cd->support_interval_adjustment) && (cd->time_adjustment_switch))
		thp_adjustment_coordinate(cd);

	thp_coordinate_report(cd, data);
	trace_touch(TOUCH_TRACE_INPUT, TOUCH_TRACE_FUNC_OUT, "thp");
	return 0;
}

void thp_clean_fingers(struct thp_core_data *cd)
{
	struct input_dev *input_dev = cd->thp_mt_wrapper->input_dev;
	struct thp_mt_wrapper_ioctl_touch_data data;
	int i;

	memset(&data, 0, sizeof(data));

	if (cd->support_b_protocol) {
		for (i = 0; i < INPUT_MT_WRAPPER_MAX_FINGERS; i++) {
			input_mt_slot(input_dev, i);
			input_mt_report_slot_state(input_dev, 0, 0);
		}
	} else {
		input_mt_sync(input_dev);
	}
	if (!cd->support_b_protocol)
		input_sync(input_dev);

	input_report_key(input_dev, BTN_TOUCH, 0);
	input_sync(input_dev);
}

static int thp_mt_wrapper_open(struct inode *inode, struct file *filp)
{
	struct thp_core_data *cd = misc_dev_get_core_data(filp->private_data);

	thp_log_info(cd, "%s:called\n", __func__);
	return 0;
}

static int thp_mt_wrapper_release(struct inode *inode, struct file *filp)
{
	return 0;
}

static int thp_mt_wrapper_ioctl_read_status(struct thp_core_data *cd, unsigned long arg)
{
	int __user *status = (int *)(uintptr_t)arg;
	u32 thp_status = thp_get_status_all(cd);

	thp_log_info(cd, "%s:status=%d\n", __func__, thp_status);

	if (!status) {
		thp_log_err(cd, "%s:input null\n", __func__);
		return -EINVAL;
	}

	if (copy_to_user(status, &thp_status, sizeof(u32))) {
		thp_log_err(cd, "%s:copy status failed\n", __func__);
		return -EFAULT;
	}

	if (atomic_read(&cd->thp_mt_wrapper->status_updated) != 0)
		atomic_dec(&cd->thp_mt_wrapper->status_updated);

	return 0;
}

static int thp_mt_ioctl_read_input_config(struct thp_core_data *cd, unsigned long arg)
{
	struct thp_input_dev_config __user *config =
		(struct thp_input_dev_config *)(uintptr_t)arg;
	struct thp_input_dev_config *input_config =
			&cd->thp_mt_wrapper->input_dev_config;

	if (!config) {
		thp_log_err(cd, "%s:input null\n", __func__);
		return -EINVAL;
	}

	if (copy_to_user(config, input_config,
			sizeof(struct thp_input_dev_config))) {
		thp_log_err(cd, "%s:copy input config failed\n", __func__);
		return -EFAULT;
	}

	return 0;
}

static int thp_mt_wrapper_ioctl_read_scene_info(struct thp_core_data *cd, unsigned long arg)
{
	struct thp_scene_info __user *config =
		(struct thp_scene_info *)(uintptr_t)arg;
	struct thp_scene_info *scene_info = NULL;

	if (!cd) {
		thp_log_err(cd, "%s:thp_core_data is NULL\n", __func__);
		return -EINVAL;
	}
	scene_info = &(cd->scene_info);

	thp_log_info(cd, "%s:%d,%d,%d\n", __func__,
		scene_info->type, scene_info->status, scene_info->parameter);

	if (copy_to_user(config, scene_info, sizeof(struct thp_scene_info))) {
		thp_log_err(cd, "%s:copy scene_info failed\n", __func__);
		return -EFAULT;
	}

	return 0;
}

static int thp_mt_wrapper_ioctl_get_window_info(struct thp_core_data *cd, unsigned long arg)
{
	struct thp_window_info __user *window_info =
		(struct thp_window_info *)(uintptr_t)arg;

	if ((!cd) || (!window_info)) {
		thp_log_err(cd, "%s:args error\n", __func__);
		return -EINVAL;
	}

	thp_log_info(cd, "%s:x0=%d,y0=%d,x1=%d,y1=%d\n", __func__,
		cd->window.x0, cd->window.y0, cd->window.x1, cd->window.y1);

	if (copy_to_user(window_info, &cd->window,
		sizeof(struct thp_window_info))) {
		thp_log_err(cd, "%s:copy window_info failed\n", __func__);
		return -EFAULT;
	}

	return 0;
}

static int thp_mt_wrapper_ioctl_get_projectid(struct thp_core_data *cd, unsigned long arg)
{
	char __user *project_id = (char __user *)(uintptr_t)arg;

	if ((!cd) || (!project_id)) {
		thp_log_err(cd, "%s:args error\n", __func__);
		return -EINVAL;
	}

	thp_log_info(cd, "%s:project id:%s\n", __func__, cd->project_id);

	if (copy_to_user(project_id, cd->project_id, sizeof(cd->project_id))) {
		thp_log_err(cd, "%s:copy project_id failed\n", __func__);
		return -EFAULT;
	}

	return 0;
}

static int thp_mt_wrapper_ioctl_get_res_scale(struct thp_core_data *cd, unsigned long arg)
{
	u32 __user *res_scale = (u32 __user *)(uintptr_t)arg;

	if ((!cd) || (!res_scale)) {
		thp_log_err(cd, "%s:args error\n", __func__);
		return -EINVAL;
	}

	thp_log_info(cd, "%s:res_scale:%u\n", __func__, cd->res_scale);
	if (copy_to_user(res_scale, &cd->res_scale, sizeof(cd->res_scale))) {
		thp_log_err(cd, "%s:copy res_scale failed\n", __func__);
		return -EFAULT;
	}

	return 0;
}

static int thp_mt_wrapper_ioctl_get_res_scale_pen(struct thp_core_data *cd, unsigned long arg)
{
	u32 __user *res_scale_pen = (u32 __user *)(uintptr_t)arg;

	if ((!cd) || (!res_scale_pen)) {
		thp_log_err(cd, "%s:args error\n", __func__);
		return -EINVAL;
	}

	thp_log_info(cd, "%s:res_scale_pen:%u\n", __func__, cd->res_scale_pen);
	if (copy_to_user(res_scale_pen, &cd->res_scale_pen, sizeof(cd->res_scale_pen))) {
		thp_log_err(cd, "%s:copy res_scale_pen failed\n", __func__);
		return -EFAULT;
	}

	return 0;
}

static int thp_mt_wrapper_ioctl_get_screen_status(struct thp_core_data *cd, unsigned long arg)
{
	u32 __user *fold_status = (u32 __user *)(uintptr_t)arg;

	if ((!cd) || (!fold_status)) {
		thp_log_err(cd, "%s:args error\n", __func__);
		return -EINVAL;
	}

	thp_log_info(cd, "%s:fold_status:%d\n", __func__, cd->fold_status);
	if (copy_to_user(fold_status, &cd->fold_status, sizeof(cd->fold_status))) {
		thp_log_err(cd, "%s:copy screen_status failed\n", __func__);
		return -EFAULT;
	}

	return 0;
}

static int thp_mt_wrapper_ioctl_enable_pen(struct thp_core_data *cd, unsigned long arg)
{
	u32 __user *status = (u32 __user *)(uintptr_t)arg;

	if ((!cd) || (!status)) {
		thp_log_err(cd, "%s:args error\n", __func__);
		return -EINVAL;
	}

	if (cd->suspended && thp_get_status(cd, THP_STATUS_STYLUS3) &&
		cd->stylus_gesture_status) {
		if (cd->thp_dev && cd->thp_dev->ops && cd->thp_dev->ops->suspend_connect_pen) {
			cd->thp_dev->ops->suspend_connect_pen(cd->thp_dev);
			thp_log_info(cd, "suspend connect pen\n");
		}
	}

	return 0;
}

static int thp_mt_wrapper_ioctl_set_roi_data(struct thp_core_data *cd, unsigned long arg)
{
	short __user *roi_data = (short __user *)(uintptr_t)arg;

	if ((!cd) || (!roi_data)) {
		thp_log_err(cd, "%s:args error\n", __func__);
		return -EINVAL;
	}

	if (copy_from_user(cd->roi_data, roi_data, sizeof(cd->roi_data))) {
		thp_log_err(cd, "%s:copy roi data failed\n", __func__);
		return -EFAULT;
	}

	return 0;
}

static long thp_mt_wrapper_ioctl_set_events(struct thp_core_data *cd, unsigned long arg)
{
	void __user *argp = (void __user *)(uintptr_t)arg;
	int val;

	if (arg == 0) {
		thp_log_err(cd, "%s:arg is null\n", __func__);
		return -EINVAL;
	}
	if (copy_from_user(&val, argp,
			sizeof(int))) {
		thp_log_err(cd, "Failed to copy_from_user()\n");
		return -EFAULT;
	}
	thp_log_info(cd, "thp_send, write: %d\n", val);
	cd->event_flag = true;
	cd->event = val;
	if (cd->event_flag) {
		cd->thp_event_waitq_flag = WAITQ_WAKEUP;
		wake_up_interruptible(&cd->thp_event_waitq);
		thp_log_info(cd, "%d: wake_up\n", cd->event);
	}

	return 0;
}

static int thp_mt_ioctl_report_keyevent(struct thp_core_data *cd, unsigned long arg)
{
	int report_value[PROX_VALUE_LEN] = {0};
	struct input_dev *input_dev = cd->thp_mt_wrapper->input_dev;
	void __user *argp = (void __user *)(uintptr_t)arg;
	enum input_mt_wrapper_keyevent keyevent;

	if (arg == 0) {
		thp_log_err(cd, "%s:arg is null\n", __func__);
		return -EINVAL;
	}
	if (copy_from_user(&keyevent, argp,
			sizeof(enum input_mt_wrapper_keyevent))) {
		thp_log_err(cd, "Failed to copy_from_user()\n");
		return -EFAULT;
	}

	if (keyevent == INPUT_MT_WRAPPER_KEYEVENT_ESD) {
		input_report_key(input_dev, KEY_F26, 1);
		input_sync(input_dev);
		input_report_key(input_dev, KEY_F26, 0);
		input_sync(input_dev);
	} else if (keyevent == INPUT_MT_WRAPPER_KEYEVENT_APPROACH) {
		thp_log_info(cd, "[Proximity_feature] %s: report [near] event!\n",
			__func__);
		report_value[0] = APPROCH_EVENT_VALUE;
#if ((defined CONFIG_INPUTHUB_20) || (defined CONFIG_HONOR_PS_SENSOR) || \
	(defined CONFIG_HONOR_SENSORS_2_0))
		thp_prox_event_report(report_value, PROX_EVENT_LEN);
#endif
	} else if (keyevent == INPUT_MT_WRAPPER_KEYEVENT_AWAY) {
		thp_log_info(cd, "[Proximity_feature] %s: report [far] event!\n",
			__func__);
		report_value[0] = AWAY_EVENT_VALUE;
#if ((defined CONFIG_INPUTHUB_20) || (defined CONFIG_HONOR_PS_SENSOR) || \
	(defined CONFIG_HONOR_SENSORS_2_0))
		thp_prox_event_report(report_value, PROX_EVENT_LEN);
#endif
	}

	return 0;
}

static long thp_mt_wrapper_ioctl_get_platform_type(struct thp_core_data *cd, unsigned long arg)
{
	int __user *platform_type = (int __user *)(uintptr_t)arg;

	if ((!cd) || (!platform_type)) {
		thp_log_info(cd, "%s: input null\n", __func__);
		return -ENODEV;
	}

	thp_log_info(cd, "%s: cd->platform_type %d\n", __func__, cd->platform_type);

	if (copy_to_user(platform_type, &cd->platform_type,
					sizeof(cd->platform_type))) {
		thp_log_err(cd, "%s:copy platform_type failed\n", __func__);
		return -EFAULT;
	}

	return 0;
}

static int thp_report_system_event(struct thp_core_data *cd, struct thp_key_info *key_info)
{
	struct input_dev *input_dev = NULL;

	if ((cd == NULL) || (!cd->support_extra_key_event_input) ||
		(cd->thp_mt_wrapper->extra_key_dev == NULL)) {
		thp_log_err(cd, "%s:input is invalid\n", __func__);
		return -EINVAL;
	}
	input_dev = cd->thp_mt_wrapper->extra_key_dev;
	thp_log_info(cd, "%s Ring-Vibrate : key: %d, value: %d\n",
		__func__, key_info->key, key_info->action);
	if ((key_info->key != KEY_VOLUME_UP) &&
		(key_info->key != KEY_VOLUME_DOWN) &&
		(key_info->key != KEY_POWER) &&
		(key_info->key != KEY_VOLUME_MUTE) &&
		(key_info->key != KEY_VOLUME_TRIG)) {
		thp_log_err(cd, "%s:key is invalid\n", __func__);
		return -EINVAL;
	}
	if ((key_info->action != THP_KEY_UP) &&
		(key_info->action != THP_KEY_DOWN)) {
		thp_log_err(cd, "%s:action is invalid\n", __func__);
		return -EINVAL;
	}

	input_report_key(input_dev, key_info->key,
		key_info->action);
	input_sync(input_dev);
	return 0;
}

static int thp_mt_ioctl_report_system_keyevent(struct thp_core_data *cd, unsigned long arg)
{
	void __user *argp = (void __user *)(uintptr_t)arg;
	struct thp_key_info key_info;

	if (arg == 0) {
		thp_log_err(cd, "%s:arg is null\n", __func__);
		return -EINVAL;
	}
	memset(&key_info, 0, sizeof(key_info));
	if (copy_from_user(&key_info, argp, sizeof(key_info))) {
		thp_log_err(cd, "Failed to copy_from_user()\n");
		return -EFAULT;
	}
	return thp_report_system_event(cd, &key_info);
}

#if (IS_ENABLED(CONFIG_HONOR_THP_QCOM) || IS_ENABLED(CONFIG_HONOR_THP_MTK))
static int thp_notify_fp_event(struct thp_core_data *cd, struct thp_shb_info info)
{
	int ret = 0;

#ifdef CONFIG_ARCH_QTI_VM
	(void)info;
#else
	struct ud_fp_ops *fp_ops = NULL;

	thp_log_info(cd, "%s: cmd_type = %d\n", __func__, info.cmd_type);
	if (!cd || !cd->use_ap_gesture) {
		thp_log_info(cd, "%s: not support ap handle udfp\n", __func__);
		return -EINVAL;
	}
	if ((info.cmd_type != THP_FINGER_PRINT_EVENT) && (info.cmd_type != THP_AUXILIARY_DATA)) {
		thp_log_info(cd, "%s: only handle fp event or auxiliary data, return\n", __func__);
		return NO_ERR;
	}
	thp_log_info(cd, "%s: called\n", __func__);
	fp_ops = fp_get_ops();
	if (!fp_ops || !fp_ops->fp_irq_notify) {
		thp_log_err(cd, "%s: point is NULL!\n", __func__);
		return -EINVAL;
	}
	if (info.cmd_type == THP_FINGER_PRINT_EVENT)
		ret = fp_ops->fp_irq_notify((struct tp_to_udfp_data *)info.cmd_addr);
	else if ((info.cmd_type == THP_AUXILIARY_DATA) && cd->support_25D_anti_fake)
		ret = fp_ops->fp_anti_fake_data_notify((struct fp_data_head_t *)info.cmd_addr);
	else
		thp_log_info(cd, "%s: invalid cmd_type\n", __func__);

	if (ret)
		thp_log_err(cd, "%s: fp_irq_notify fail, ret %d\n", __func__, ret);
#endif

	return ret;
}
#endif

#ifdef CONFIG_HONOR_SHB_THP
int thp_send_volumn_to_drv(const char *head)
{
	struct thp_volumn_info *rx = (struct thp_volumn_info *)head;
	struct thp_key_info key_info;
	struct thp_core_data *cd = thp_get_core_data();

	if ((rx == NULL) || (cd == NULL)) {
		thp_log_err(cd, "%s:rx or cd is null\n", __func__);
		return -EINVAL;
	}
	if (!atomic_read(&cd->register_flag)) {
		thp_log_err(cd, "%s: thp have not be registered\n", __func__);
		return -ENODEV;
	}
	thp_log_info(cd, "%s:key:%ud, action:%ud\n", __func__,
		rx->data[0], rx->data[1]);
	key_info.key = rx->data[0];
	key_info.action = rx->data[1];
	return thp_report_system_event(&key_info);
}

static int thp_event_info_dispatch(struct thp_shb_info info)
{
	int ret;
	unsigned int cmd_type = info.cmd_type;
	uint8_t cmd;

	switch (cmd_type) {
	case THP_FINGER_PRINT_EVENT:
		cmd = ST_CMD_TYPE_FINGERPRINT_EVENT;
		ret = send_thp_ap_event(info.cmd_len, info.cmd_addr, cmd);
		break;
	case THP_RING_EVENT:
		cmd = ST_CMD_TYPE_RING_EVENT;
		ret = send_thp_ap_event(info.cmd_len, info.cmd_addr, cmd);
		break;
	case THP_ALGO_SCREEN_OFF_INFO:
		ret = send_thp_algo_sync_event(info.cmd_len, info.cmd_addr);
		break;
	case THP_AUXILIARY_DATA:
		ret = send_thp_auxiliary_data(info.cmd_len, info.cmd_addr);
		break;
	default:
		thp_log_err(cd, "%s: thp_shb_info is null\n", __func__);
		ret = -EFAULT;
	}
	return ret;
}
#endif
#if ((defined CONFIG_HONOR_SHB_THP) || (IS_ENABLED(CONFIG_HONOR_THP_QCOM) || \
	IS_ENABLED(CONFIG_HONOR_THP_MTK)))
static int thp_mt_ioctl_cmd_shb_event(struct thp_core_data *cd, unsigned long arg)
{
	void __user *argp = (void __user *)(uintptr_t)arg;
	int ret;
	struct thp_shb_info data;
	char *cmd_data = NULL;

	if (arg == 0) {
		thp_log_err(cd, "%s:arg is null.\n", __func__);
		return -EINVAL;
	}
	if (copy_from_user(&data, argp, sizeof(struct thp_shb_info))) {
		thp_log_err(cd, "%s:copy info failed\n", __func__);
		return -EFAULT;
	}
	if ((data.cmd_len > MAX_THP_CMD_INFO_LEN) || (data.cmd_len == 0)) {
		thp_log_err(cd, "%s:cmd_len:%u is illegal\n", __func__,
			data.cmd_len);
		return 0;
	}
	cmd_data = kzalloc(data.cmd_len, GFP_KERNEL);
	if (cmd_data == NULL) {
		thp_log_err(cd, "%s:cmd buffer kzalloc failed\n", __func__);
		return -EFAULT;
	}
	if (copy_from_user(cmd_data, data.cmd_addr, data.cmd_len)) {
		thp_log_err(cd, "%s:copy cmd data failed\n", __func__);
		kfree(cmd_data);
		return -EFAULT;
	}
	data.cmd_addr = cmd_data;
#ifdef CONFIG_HONOR_SHB_THP
	if (cd->tsa_event_to_udfp) {
		ret = send_tp_ap_event(data.cmd_len, data.cmd_addr,
			ST_CMD_TYPE_FINGERPRINT_EVENT);
		if (ret < 0)
			thp_log_err(cd, "%s:tsa_event notify fp err %d\n",
				__func__, ret);
		kfree(cmd_data);
		return 0;
	}
	ret = thp_event_info_dispatch(data);
	if (ret < 0)
		thp_log_err(cd, "%s:thp event info dispatch failed\n", __func__);
#endif
#if (IS_ENABLED(CONFIG_HONOR_THP_QCOM) || IS_ENABLED(CONFIG_HONOR_THP_MTK))
	ret = thp_notify_fp_event(cd, data);
	if (ret < 0)
		thp_log_err(cd, "%s:tpud event notify fp err %d\n", __func__, ret);
#endif
	kfree(cmd_data);
	return 0;
}
#endif

static long thp_ioctl_get_volume_side(struct thp_core_data *cd, unsigned long arg)
{
	void __user *status = (void __user *)(uintptr_t)arg;

	if (cd == NULL) {
		thp_log_err(cd, "%s: thp cord data null\n", __func__);
		return -EINVAL;
	}
	if (status == NULL) {
		thp_log_err(cd, "%s: input parameter null\n", __func__);
		return -EINVAL;
	}

	if (copy_to_user(status, (void *)&cd->volume_side_status,
		sizeof(cd->volume_side_status))) {
		thp_log_err(cd, "%s: get volume side failed\n", __func__);
		return -EFAULT;
	}

	return 0;
}

static long thp_ioctl_get_power_switch(struct thp_core_data *cd, unsigned long arg)
{
	void __user *status = (void __user *)(uintptr_t)arg;

	if ((cd == NULL) || (status == NULL)) {
		thp_log_err(cd, "%s: thp cord data null\n", __func__);
		return -EINVAL;
	}

	if (copy_to_user(status, (void *)&cd->power_switch,
		sizeof(cd->power_switch))) {
		thp_log_err(cd, "%s: get power_switch failed\n", __func__);
		return -EFAULT;
	}
	return 0;
}

static void thp_report_pen_event(struct thp_core_data *cd, struct input_dev *input,
	struct thp_tool tool, int pressure, int tool_type, int tool_value)
{
	if (input == NULL) {
		thp_log_err(cd, "%s: input null ptr\n", __func__);
		return;
	}

	thp_log_debug(cd, "%s:tool.tip_status:%d, tool_type:%d, tool_value:%d\n",
		__func__, tool.tip_status, tool_type, tool_value);
	input_report_abs(input, ABS_X, tool.x);
	input_report_abs(input, ABS_Y, tool.y);
	input_report_abs(input, ABS_PRESSURE, pressure);
	input_report_abs(input, ABS_TILT_X, tool.tilt_x);
	input_report_abs(input, ABS_TILT_Y, tool.tilt_y);
	input_report_key(input, BTN_TOUCH, tool.tip_status);
	input_report_key(input, tool_type, tool_value);
	input_sync(input);
}

static int thp_mt_wrapper_ioctl_report_pen(struct thp_core_data *cd, unsigned long arg)
{
	struct thp_mt_wrapper_ioctl_pen_data pens;
	struct input_dev *input = cd->thp_mt_wrapper->pen_dev;
	int i;
	int key_value;
	void __user *argp = (void __user *)(uintptr_t)arg;

	if ((arg == 0) || (input == NULL) || (cd == NULL)) {
		thp_log_err(cd, "%s:have null ptr\n", __func__);
		return -EINVAL;
	}
	if (cd->pen_supported == 0) {
		thp_log_info(cd, "%s:not support pen\n", __func__);
		return 0;
	}
	memset(&pens, 0, sizeof(pens));
	if (copy_from_user(&pens, argp, sizeof(pens))) {
		thp_log_err(cd, "Failed to copy_from_user\n");
		return -EFAULT;
	}

	/* report pen basic single button */
	for (i = 0; i < TS_MAX_PEN_BUTTON; i++) {
		if (pens.buttons[i].status == 0)
			continue;
		else if (pens.buttons[i].status == TS_PEN_BUTTON_PRESS)
			key_value = 1; /* key down */
		else
			key_value = 0; /* key up */
		if (pens.buttons[i].key != 0) {
			thp_log_err(cd, "pen index is %d\n", i);
			input_report_key(input, pens.buttons[i].key,
				key_value);
		}
	}

	/* pen or rubber report point */
	thp_report_pen_event(cd, input, pens.tool, pens.tool.pressure,
		pens.tool.tool_type, pens.tool.pen_inrange_status);
	return 0;
}

static long thp_ioctl_get_stylus3_connect_status(struct thp_core_data *cd, unsigned long arg)
{
	void __user *argp = NULL;
	int ret;

	if (arg == 0) {
		thp_log_err(cd, "arg == 0\n");
		return -EINVAL;
	}
	argp = (void __user *)(uintptr_t)arg;
	ret = wait_for_completion_interruptible(&cd->stylus3_status_flag);
	if (ret) {
		thp_log_err(cd, " Failed to get_connect_status\n");
		return ret;
	}
	if (copy_to_user(argp, &cd->last_stylus3_status,
		sizeof(cd->last_stylus3_status))) {
		thp_log_err(cd, "%s: Failed to copy_to_user()\n",
			__func__);
		return -EFAULT;
	}
	return NO_ERR;
}

static int set_stylus3_change_protocol(struct thp_core_data *cd, unsigned long arg)
{
	unsigned int stylus_status;
	void __user *argp = (void __user *)(uintptr_t)arg;

	if (arg == 0) {
		thp_log_err(cd, "arg == 0\n");
		return -EINVAL;
	}
	if (copy_from_user(&stylus_status, argp, sizeof(stylus_status))) {
		thp_log_err(cd, "%s Failed to copy_from_user\n", __func__);
		return -EFAULT;
	}
	/* bt close,do not need handle */
	if (stylus_status == 0) {
		thp_log_info(cd, "do not change pen protocol\n");
		return NO_ERR;
	}
	/* change pen protocol to 2.2 */
	cd->stylus3_callback_event.event_class = SUPPORT_PEN_PROTOCOL_CLASS;
	cd->stylus3_callback_event.event_code = SUPPORT_PEN_PROTOCOL_CODE;
	thp_log_info(cd, "%s: to pen\n", __func__);
	atomic_set(&cd->callback_event_flag, true);
	complete(&cd->stylus3_callback_flag);
	return NO_ERR;
}

static int thp_ioctl_set_stylus3_connect_status(struct thp_core_data *cd, unsigned long arg)
{
	void __user *argp = NULL;
	unsigned int stylus3_status;

	if (arg == 0) {
		thp_log_err(cd, "arg == 0\n");
		return -EINVAL;
	}
	argp = (void __user *)(uintptr_t)arg;
	if (copy_from_user(&stylus3_status, argp, sizeof(unsigned int))) {
		thp_log_err(cd, "%s Failed to copy_from_user\n", __func__);
		return -EFAULT;
	}
	thp_log_info(cd, "%s:stylus3_status = %d\n", __func__, stylus3_status);
	thp_set_status(cd, THP_STATUS_STYLUS3,
		(stylus3_status & STYLUS3_CONNECTED_MASK));
	atomic_set(&cd->last_stylus3_status, stylus3_status);
	complete(&cd->stylus3_status_flag);
	if ((cd->send_bt_status_to_fw) && (cd->support_dual_chip_arch))
		if (cd->thp_dev->ops->bt_handler(cd->thp_dev, false))
			thp_log_err(cd, "send bt status to fw fail\n");
	if (cd->use_dual_spi_for_pen == 1)
		if (cd->thp_dev->ops->bt_handler(cd->thp_dev, false))
			thp_log_err(cd, "use dual spi bt_handler fail\n");
	return 0;
}

static long thp_ioctl_get_current_grip_data(unsigned long arg)
{
	void __user *argp = (void __user *)(uintptr_t)arg;
	struct thp_core_data *cd = thp_get_core_data();

	if (!cd) {
		thp_log_err(cd, "%s:have null ptr\n", __func__);
		return -EINVAL;
	}
	if (!cd->support_grip_recognition) {
		thp_log_err(cd ,"%s: Not support grip recognition\n", __func__);
		return -EINVAL;
	}
	if (arg == 0) {
		thp_log_err(cd ,"arg == 0\n");
		return -EINVAL;
	}

	mutex_lock(&cd->grip_event_mutex);
	if (copy_to_user(argp, &cd->grip_data, sizeof(cd->grip_data))) {
		thp_log_err(cd ,"%s: Failed to copy_to_user\n", __func__);
		return -EFAULT;
	}
	thp_log_info(cd, "Get current grip data done!\n");
	mutex_unlock(&cd->grip_event_mutex);

	return NO_ERR;
}

static long thp_ioctl_get_grip_data(unsigned long arg)
{
	void __user *argp = (void __user *)(uintptr_t)arg;
	struct thp_core_data *cd = thp_get_core_data();
	int ret;

	if (!cd) {
		thp_log_err(cd ,"%s:have null ptr\n", __func__);
		return -EINVAL;
	}
	if (!cd->support_grip_recognition) {
		thp_log_err(cd ,"%s: Not support grip recognition\n", __func__);
		return -EINVAL;
	}
	if (arg == 0) {
		thp_log_err(cd ,"arg == 0\n");
		return -EINVAL;
	}
	ret = wait_for_completion_interruptible(&cd->grip_data_setting_flag);
	if (ret) {
		thp_log_info(cd, " Failed to get grip_data_setting_flag\n");
	} else {
		mutex_lock(&cd->grip_event_mutex);
		if (copy_to_user(argp, &cd->grip_data, sizeof(cd->grip_data))) {
			thp_log_err(cd, "%s: Failed to copy_to_user\n", __func__);
			return -EFAULT;
		}
		thp_log_info(cd, "%s, screen_rotate=%d, grip_type=%d, grip_num=%d\n",
			__func__, (cd->grip_data.screen_rotate * 90),
			cd->grip_data.grip_type, cd->grip_data.grip_num);
		mutex_unlock(&cd->grip_event_mutex);
	}
	return NO_ERR;
}

static int thp_ioctl_set_grip_data(unsigned long arg)
{
	void __user *argp = (void __user *)(uintptr_t)arg;
	struct thp_core_data *cd = thp_get_core_data();

	if (!cd) {
		thp_log_err(cd ,"%s:have null ptr\n", __func__);
		return -EINVAL;
	}
	if (!cd->support_grip_recognition) {
		thp_log_err(cd ,"%s: Not support grip recognition\n", __func__);
		return -EINVAL;
	}
	if (arg == 0) {
		thp_log_err(cd ,"arg == 0\n");
		return -EINVAL;
	}
	mutex_lock(&cd->grip_event_mutex);
	if (copy_from_user(&cd->grip_data, argp, sizeof(cd->grip_data))) {
		thp_log_err(cd ,"%s Failed to copy_from_user\n", __func__);
		return -EFAULT;
	}
	thp_log_info(cd, "%s, screen_rotate=%d, grip_type=%d, grip_num=%d\n",
		__func__, (cd->grip_data.screen_rotate * 90), cd->grip_data.grip_type,
		cd->grip_data.grip_num);
	if (!completion_done(&cd->grip_data_setting_flag))
		complete(&cd->grip_data_setting_flag);

	mutex_unlock(&cd->grip_event_mutex);

	return NO_ERR;
}

static long thp_ioctl_get_callback_events(struct thp_core_data *cd, unsigned long arg)
{
	void __user *argp = (void __user *)(uintptr_t)arg;
	int ret;

	if (!(cd->pen_supported) || !(cd->pen_mt_enable_flag)) {
		thp_log_err(cd, "%s: Not support stylus3\n", __func__);
		return -EINVAL;
	}
	if (arg == 0) {
		thp_log_err(cd, "arg == 0\n");
		return -EINVAL;
	}
	ret = wait_for_completion_interruptible(&cd->stylus3_callback_flag);
	if (ret) {
		thp_log_info(cd, " Failed to get stylus3_callback_flag\n");
	} else {
		if (copy_to_user(argp, &cd->stylus3_callback_event,
			sizeof(cd->stylus3_callback_event))) {
			thp_log_err(cd, "%s: Failed to copy_to_user()\n", __func__);
			return -EFAULT;
		}
		thp_log_info(cd, "%s, eventClass=%d, eventCode=%d, extraInfo=%s\n",
			__func__, cd->stylus3_callback_event.event_class,
			cd->stylus3_callback_event.event_code,
			cd->stylus3_callback_event.extra_info);
	}
	atomic_set(&cd->callback_event_flag, false);
	return NO_ERR;
}

static int thp_ioctl_set_callback_events(struct thp_core_data *cd, unsigned long arg)
{
	void __user *argp = (void __user *)(uintptr_t)arg;

	if (!(cd->pen_supported) || !(cd->pen_mt_enable_flag)) {
		thp_log_err(cd, "%s: Not support stylus3\n", __func__);
		return -EINVAL;
	}
	if (arg == 0) {
		thp_log_err(cd, "arg == 0\n");
		return -EINVAL;
	}
	if (atomic_read(&cd->callback_event_flag) != false) {
		thp_log_err(cd, "%s,callback event not handle, need retry\n",
			__func__);
		return -EBUSY;
	}
	if (copy_from_user(&cd->stylus3_callback_event,
		argp, sizeof(cd->stylus3_callback_event))) {
		thp_log_err(cd, "%s Failed to copy_from_user\n", __func__);
		return -EFAULT;
	}
	thp_log_info(cd, "%s, eventClass=%d, eventCode=%d, extraInfo=%s\n",
		__func__,
		cd->stylus3_callback_event.event_class,
		cd->stylus3_callback_event.event_code,
		cd->stylus3_callback_event.extra_info);
	atomic_set(&cd->callback_event_flag, true);
	complete(&cd->stylus3_callback_flag);
	return NO_ERR;
}

static int daemon_init_protect(struct thp_core_data *cd, unsigned long arg)
{
	void __user *argp = (void __user *)(uintptr_t)arg;
	u32 daemon_flag;

	if (!cd->support_daemon_init_protect) {
		thp_log_err(cd, "%s: not support daemon init protect\n", __func__);
		return 0;
	}

	if (copy_from_user(&daemon_flag, argp, sizeof(daemon_flag))) {
		thp_log_err(cd, "%s Failed to copy_from_user\n", __func__);
		return -EFAULT;
	}

	thp_log_info(cd, "%s called,daemon_flag = %u\n", __func__, daemon_flag);
	if (daemon_flag) {
		atomic_set(&(cd->fw_update_protect), 1);
	} else {
		atomic_set(&(cd->fw_update_protect), 0);
		if (atomic_read(&(cd->resend_suspend_after_fw_update)) == 1) {
			thp_log_info(cd, "%s: fw update complete, need resend suspend cmd\n",
				__func__);
			atomic_set(&(cd->resend_suspend_after_fw_update), 0);
			thp_set_status(cd, THP_STATUS_POWER, THP_SUSPEND);
			mdelay(5); /* delay 5ms to wait for daemon reading status */
		}
	}
	return 0;
}

static int thp_daemon_power_reset(struct thp_core_data *cd, unsigned long arg)
{
	void __user *argp = (void __user *)(uintptr_t)arg;
	u32 daemon_flag;


	if (cd->multi_panel_index == SINGLE_TOUCH_PANEL) {
		thp_log_err(cd, "%s: not support daemon power reset\n", __func__);
		return 0;
	}

	if (copy_from_user(&daemon_flag, argp, sizeof(daemon_flag))) {
		thp_log_err(cd, "%s Failed to copy_from_user\n", __func__);
		return -EFAULT;
	}

	thp_log_info(cd, "%s called,daemon_flag = %u\n", __func__, daemon_flag);
	if ((daemon_flag != MAIN_TOUCH_PANEL) &&
		(daemon_flag != SUB_TOUCH_PANEL)) {
		thp_log_err(cd, "%s invalid arg\n", __func__);
		return -EINVAL;
	}
	return 0;
}

static long thp_mt_wrapper_ioctl(struct file *filp, unsigned int cmd,
	unsigned long arg)
{
	long ret = 0;
	struct thp_core_data *cd = misc_dev_get_core_data(filp->private_data);

	if (!cd) {
		thp_log_err(cd, "%s:misc_dev_get_core_data null\n", __func__);
		return -EINVAL;
	}

	switch (cmd) {
	case INPUT_MT_WRAPPER_IOCTL_CMD_SET_COORDINATES:
		ret = thp_mt_wrapper_ioctl_set_coordinate(cd, arg);
		break;
	case INPUT_MT_WRAPPER_IOCTL_CMD_REPORT_PEN:
		ret = thp_mt_wrapper_ioctl_report_pen(cd, arg);
		break;
	case INPUT_MT_WRAPPER_IOCTL_READ_STATUS:
		ret = thp_mt_wrapper_ioctl_read_status(cd, arg);
		break;
	case INPUT_MT_WRAPPER_IOCTL_READ_INPUT_CONFIG:
		ret = thp_mt_ioctl_read_input_config(cd, arg);
		break;
	case INPUT_MT_WRAPPER_IOCTL_READ_SCENE_INFO:
		ret = thp_mt_wrapper_ioctl_read_scene_info(cd, arg);
		break;
	case INPUT_MT_WRAPPER_IOCTL_GET_WINDOW_INFO:
		ret = thp_mt_wrapper_ioctl_get_window_info(cd, arg);
		break;
	case INPUT_MT_WRAPPER_IOCTL_GET_PROJECT_ID:
		ret = thp_mt_wrapper_ioctl_get_projectid(cd, arg);
		break;
	case INPUT_MT_WRAPPER_IOCTL_GET_RES_SCALE:
		ret = thp_mt_wrapper_ioctl_get_res_scale(cd, arg);
		break;
	case INPUT_MT_WRAPPER_IOCTL_CMD_SET_EVENTS:
		ret = thp_mt_wrapper_ioctl_set_events(cd, arg);
		break;
	case INPUT_MT_WRAPPER_IOCTL_CMD_GET_EVENTS:
		ret = thp_mt_wrapper_ioctl_get_events(cd, arg);
		break;
	case INPUT_MT_WRAPPER_IOCTL_SET_ROI_DATA:
		ret = thp_mt_wrapper_ioctl_set_roi_data(cd, arg);
		break;
	case INPUT_MT_WRAPPER_IOCTL_CMD_REPORT_KEYEVENT:
		ret = thp_mt_ioctl_report_keyevent(cd, arg);
		break;
	case INPUT_MT_WRAPPER_IOCTL_REPORT_SYSTEM_KEYEVENT:
		ret = thp_mt_ioctl_report_system_keyevent(cd, arg);
		break;
	case INPUT_MT_WRAPPER_IOCTL_GET_PLATFORM_TYPE:
		ret = thp_mt_wrapper_ioctl_get_platform_type(cd, arg);
		break;
#if ((defined CONFIG_HONOR_SHB_THP) || (IS_ENABLED(CONFIG_HONOR_THP_QCOM) || \
	(IS_ENABLED(CONFIG_HONOR_THP_MTK))))
	case INPUT_MT_WRAPPER_IOCTL_CMD_SHB_EVENT:
		ret = thp_mt_ioctl_cmd_shb_event(cd, arg);
		break;
#endif
	case INPUT_MT_WRAPPER_IOCTL_GET_VOMLUME_SIDE:
		ret = thp_ioctl_get_volume_side(cd, arg);
		break;
	case INPUT_MT_WRAPPER_IOCTL_GET_POWER_SWITCH:
		ret = thp_ioctl_get_power_switch(cd, arg);
		break;
	case INPUT_MT_IOCTL_CMD_GET_STYLUS3_CONNECT_STATUS:
		if ((cd->pen_supported) && (cd->pen_mt_enable_flag))
			ret = thp_ioctl_get_stylus3_connect_status(cd, arg);
		break;
	case INPUT_MT_IOCTRL_CMD_SET_STYLUS3_CONNECT_STATUS:
		if (cd->pen_change_protocol) {
			ret = set_stylus3_change_protocol(cd, arg);
			return ret;
		}
		if ((cd->pen_supported) && (cd->pen_mt_enable_flag))
			ret = thp_ioctl_set_stylus3_connect_status(cd, arg);
		break;
	case INPUT_MT_IOCTL_CMD_GET_CALLBACK_EVENTS:
		ret = thp_ioctl_get_callback_events(cd, arg);
		break;
	case INPUT_MT_IOCTL_CMD_SET_CALLBACK_EVENTS:
		ret = thp_ioctl_set_callback_events(cd, arg);
		break;
	case INPUT_MT_WRAPPER_IOCTL_CMD_GET_GRIP_DATA:
		ret = thp_ioctl_get_grip_data(arg);
		break;
	case INPUT_MT_WRAPPER_IOCTL_CMD_SET_GRIP_DATA:
		ret = thp_ioctl_set_grip_data(arg);
		break;
	case INPUT_MT_WRAPPER_IOCTL_CMD_GET_CURRENT_GRIP_DATA:
		ret = thp_ioctl_get_current_grip_data(arg);
		break;
	case INPUT_MT_IOCTL_CMD_SET_DAEMON_INIT_PROTECT:
		ret = daemon_init_protect(cd, arg);
		break;
	case INPUT_MT_IOCTL_CMD_SET_DAEMON_POWER_RESET:
		ret = thp_daemon_power_reset(cd, arg);
		break;
	case INPUT_MT_WRAPPER_IOCTL_GET_RES_SCALE_PEN:
		ret = thp_mt_wrapper_ioctl_get_res_scale_pen(cd, arg);
		break;
	case INPUT_MT_WRAPPER_IOCTL_GET_SCREEN_FOLDED:
		ret = thp_mt_wrapper_ioctl_get_screen_status(cd, arg);
		break;
	case INPUT_MT_WRAPPER_IOCTL_DAE_ENABLE_PEN:
		ret = thp_mt_wrapper_ioctl_enable_pen(cd, arg);
		break;
	default:
		thp_log_err(cd, "%s: cmd unknown, cmd = 0x%x\n", __func__, cmd);
		ret = -EINVAL;
	}

	return ret;
}

int thp_mt_wrapper_wakeup_poll(struct thp_core_data *cd)
{
	if (!cd->thp_mt_wrapper) {
		thp_log_err(cd, "%s: wrapper not init\n", __func__);
		return -ENODEV;
	}
	atomic_inc(&cd->thp_mt_wrapper->status_updated);
	wake_up_interruptible(&cd->thp_mt_wrapper->wait);
	return 0;
}

static unsigned int thp_mt_wrapper_poll(struct file *file, poll_table *wait)
{
	unsigned int mask = 0;
	struct thp_core_data *cd = misc_dev_get_core_data(file->private_data);

	if (!cd) {
		thp_log_err(cd, "%s:misc_dev_get_core_data null\n", __func__);
		return 0;
	}

	thp_log_debug(cd, "%s:poll call in\n", __func__);
	poll_wait(file, &cd->thp_mt_wrapper->wait, wait);
	if (atomic_read(&cd->thp_mt_wrapper->status_updated) > 0)
		mask |= POLLIN | POLLRDNORM;

	thp_log_debug(cd, "%s:poll call out, mask = 0x%x\n", __func__, mask);
	return mask;
}

static const struct file_operations g_thp_mt_wrapper_fops = {
	.owner = THIS_MODULE,
	.open = thp_mt_wrapper_open,
	.release = thp_mt_wrapper_release,
	.unlocked_ioctl = thp_mt_wrapper_ioctl,
	.compat_ioctl = thp_mt_wrapper_ioctl,
	.poll = thp_mt_wrapper_poll,
};

static void set_default_input_config(struct thp_input_dev_config *input_config)
{
	input_config->abs_max_x = THP_MT_WRAPPER_MAX_X;
	input_config->abs_max_y = THP_MT_WRAPPER_MAX_Y;
	input_config->abs_max_z = THP_MT_WRAPPER_MAX_Z;
	input_config->major_max = THP_MT_WRAPPER_MAX_MAJOR;
	input_config->minor_max = THP_MT_WRAPPER_MAX_MINOR;
	input_config->tool_type_max = THP_MT_WRAPPER_TOOL_TYPE_MAX;
	input_config->tracking_id_max = THP_MT_WRAPPER_MAX_FINGERS;
	input_config->orientation_min = THP_MT_WRAPPER_MIN_ORIENTATION;
	input_config->orientation_max = THP_MT_WRAPPER_MAX_ORIENTATION;
}

static int thp_projectid_to_vender_id(struct thp_core_data *cd, const char *project_id,
	unsigned int project_id_len, char *temp_buf, unsigned int len)
{
	if ((!project_id) || (!temp_buf)) {
		thp_log_err(cd, "%s: project id or temp buffer null\n", __func__);
		return -EINVAL;
	}
	if ((strlen(project_id) > project_id_len) ||
		(len < THP_PROJECTID_VENDOR_ID_LEN)) {
		thp_log_err(cd, "%s:project_id or temp_buf has a wrong length\n", __func__);
		return -EINVAL;
	}
	strncpy(temp_buf, project_id + THP_PROJECTID_PRODUCT_NAME_LEN +
		THP_PROJECTID_IC_NAME_LEN, THP_PROJECTID_VENDOR_ID_LEN);

	return 0;
}
static int thp_parse_input_config(struct thp_core_data *cd, struct thp_input_dev_config *config)
{
	int rc;
	unsigned int i;
	int ret;
	char temp_buf[THP_PROJECTID_VENDOR_ID_LEN + 1] = {0};
	struct device_node *thp_dev_node = NULL;

	if (cd->support_diff_resolution) {
		thp_log_info(cd, "%s: use different resolution\n", __func__);
		ret = thp_projectid_to_vender_id(cd, cd->project_id,
			THP_PROJECT_ID_LEN + 1, temp_buf, sizeof(temp_buf));
		if (ret < 0) {
			thp_log_err(cd, "%s: get vendor id failed\n", __func__);
			goto use_default;
		}
		for (i = 0; i < ARRAY_SIZE(thp_input_compatible_table); i++) {
			if (!strncmp(thp_input_compatible_table[i].vendor_id,
				(const char *)temp_buf,
				strlen(thp_input_compatible_table[i].vendor_id))) {
				thp_dev_node = of_find_compatible_node(NULL, NULL,
					thp_input_compatible_table[i].compatible_name);
				break;
			}
		}
		/* if no compatible id-name pair in table, use default */
		if (i == ARRAY_SIZE(thp_input_compatible_table)) {
			thp_log_err(cd, "%s:vendor id:%s not in id_table\n", __func__, temp_buf);
			thp_dev_node = of_find_compatible_node(NULL, NULL,
				THP_INPUT_DEV_COMPATIBLE);
		}
	} else {
		thp_dev_node = of_find_compatible_node(cd->thp_node, NULL,
			THP_INPUT_DEV_COMPATIBLE);
	}
	if (!thp_dev_node) {
		thp_log_info(cd, "%s:not found node, use defatle config\n",
					__func__);
		goto use_default;
	}

	rc = of_property_read_u32(thp_dev_node, "abs_max_x",
						&config->abs_max_x);
	if (rc) {
		thp_log_err(cd, "%s:abs_max_x not config, use deault\n", __func__);
		config->abs_max_x = THP_MT_WRAPPER_MAX_X;
	}

	rc = of_property_read_u32(thp_dev_node, "abs_max_y",
						&config->abs_max_y);
	if (rc) {
		thp_log_err(cd, "%s:abs_max_y not config, use deault\n", __func__);
		config->abs_max_y = THP_MT_WRAPPER_MAX_Y;
	}

	rc = of_property_read_u32(thp_dev_node, "abs_max_z",
						&config->abs_max_z);
	if (rc) {
		thp_log_err(cd, "%s:abs_max_z not config, use deault\n", __func__);
		config->abs_max_z = THP_MT_WRAPPER_MAX_Z;
	}

	rc = of_property_read_u32(thp_dev_node, "tracking_id_max",
						&config->tracking_id_max);
	if (rc) {
		thp_log_err(cd, "%s:tracking_id_max not config, use deault\n",
				__func__);
		config->tracking_id_max = THP_MT_WRAPPER_MAX_FINGERS;
	}

	rc = of_property_read_u32(thp_dev_node, "major_max",
						&config->major_max);
	if (rc) {
		thp_log_err(cd, "%s:major_max not config, use deault\n", __func__);
		config->major_max = THP_MT_WRAPPER_MAX_MAJOR;
	}

	rc = of_property_read_u32(thp_dev_node, "minor_max",
						&config->minor_max);
	if (rc) {
		thp_log_err(cd, "%s:minor_max not config, use deault\n", __func__);
		config->minor_max = THP_MT_WRAPPER_MAX_MINOR;
	}

	rc = of_property_read_u32(thp_dev_node, "orientation_min",
						&config->orientation_min);
	if (rc) {
		thp_log_err(cd, "%s:orientation_min not config, use deault\n",
				__func__);
		config->orientation_min = THP_MT_WRAPPER_MIN_ORIENTATION;
	}

	rc = of_property_read_u32(thp_dev_node, "orientation_max",
					&config->orientation_max);
	if (rc) {
		thp_log_err(cd, "%s:orientation_max not config, use deault\n",
				__func__);
		config->orientation_max = THP_MT_WRAPPER_MAX_ORIENTATION;
	}

	rc = of_property_read_u32(thp_dev_node, "tool_type_max",
					&config->tool_type_max);
	if (rc) {
		thp_log_err(cd, "%s:tool_type_max not config, use deault\n",
				__func__);
		config->tool_type_max = THP_MT_WRAPPER_TOOL_TYPE_MAX;
	}

	return 0;

use_default:
	set_default_input_config(config);
	return 0;
}

static int thp_parse_pen_input_config(struct thp_core_data *cd, struct thp_input_pen_dev_config *config)
{
	int rc = -EINVAL;
	struct device_node *thp_dev_node = NULL;

	if (config == NULL) {
		thp_log_err(cd, "%s: config is null\n", __func__);
		goto err;
	}
	thp_dev_node = of_find_compatible_node(cd->thp_node, NULL,
		THP_PEN_INPUT_DEV_COMPATIBLE);
	if (!thp_dev_node) {
		thp_log_info(cd, "%s:thp_dev_node not found\n", __func__);
		goto err;
	}

	rc = of_property_read_u32(thp_dev_node, "max_x",
		&config->max_x);
	if (rc) {
		thp_log_err(cd, "%s:max_x not config\n", __func__);
		goto err;
	}

	rc = of_property_read_u32(thp_dev_node, "max_y",
		&config->max_y);
	if (rc) {
		thp_log_err(cd, "%s:max_y not config\n", __func__);
		goto err;
	}

	rc = of_property_read_u32(thp_dev_node, "max_pressure",
		&config->pressure);
	if (rc) {
		thp_log_err(cd, "%s:pressure not config\n", __func__);
		config->pressure = THP_MT_WRAPPER_MAX_Z;
	}

	rc = of_property_read_u32(thp_dev_node, "max_tilt_x",
		&config->max_tilt_x);
	if (rc) {
		thp_log_err(cd, "%s:max_tilt_x not config\n", __func__);
		config->max_tilt_x = THP_PEN_WRAPPER_TILT_MAX_X;
	}

	rc = of_property_read_u32(thp_dev_node, "max_tilt_y",
		&config->max_tilt_y);
	if (rc) {
		thp_log_err(cd, "%s:max_tilt_y not config\n", __func__);
		config->max_tilt_y = THP_PEN_WRAPPER_TILT_MAX_X;
	}
err:
	return rc;
}

static int thp_set_pen_input_config(struct thp_core_data *cd, struct input_dev *pen_dev)
{
	if (pen_dev == NULL) {
		thp_log_err(cd, "%s:input null ptr\n", __func__);
		return -EINVAL;
	}

	pen_dev->evbit[0] |= BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
	__set_bit(ABS_X, pen_dev->absbit);
	__set_bit(ABS_Y, pen_dev->absbit);
	__set_bit(ABS_TILT_X, pen_dev->absbit);
	__set_bit(ABS_TILT_Y, pen_dev->absbit);
	__set_bit(BTN_STYLUS, pen_dev->keybit);
	__set_bit(BTN_TOUCH, pen_dev->keybit);
	__set_bit(BTN_TOOL_PEN, pen_dev->keybit);
	__set_bit(INPUT_PROP_DIRECT, pen_dev->propbit);
	if (cd->support_dynamic_resolution) {
		input_set_abs_params(pen_dev, ABS_X, 0,
			cd->thp_mt_wrapper->input_pen_dev_config.max_x * cd->res_scale_pen, 0, 0);
		input_set_abs_params(pen_dev, ABS_Y, 0,
			cd->thp_mt_wrapper->input_pen_dev_config.max_y * cd->res_scale_pen, 0, 0);
	} else {
		input_set_abs_params(pen_dev, ABS_X, 0,
			cd->thp_mt_wrapper->input_pen_dev_config.max_x, 0, 0);
		input_set_abs_params(pen_dev, ABS_Y, 0,
			cd->thp_mt_wrapper->input_pen_dev_config.max_y, 0, 0);
	}
	input_set_abs_params(pen_dev, ABS_PRESSURE, 0,
		cd->thp_mt_wrapper->input_pen_dev_config.pressure, 0, 0);
	input_set_abs_params(pen_dev, ABS_TILT_X,
		-1 * cd->thp_mt_wrapper->input_pen_dev_config.max_tilt_x,
		cd->thp_mt_wrapper->input_pen_dev_config.max_tilt_x, 0, 0);
	input_set_abs_params(pen_dev, ABS_TILT_Y,
		-1 * cd->thp_mt_wrapper->input_pen_dev_config.max_tilt_y,
		cd->thp_mt_wrapper->input_pen_dev_config.max_tilt_y, 0, 0);
	__set_bit(TS_STYLUS_WAKEUP_TO_MEMO, pen_dev->keybit);
	__set_bit(TS_STYLUS_WAKEUP_SCREEN_ON, pen_dev->keybit);
	return 0;
}

static int thp_set_extra_key_input_config(struct thp_core_data *cd,
	struct input_dev *extra_key_dev)
{
	if (extra_key_dev == NULL) {
		thp_log_err(cd, "%s:input null ptr\n", __func__);
		return -EINVAL;
	}
	__set_bit(EV_SYN, extra_key_dev->evbit);
	__set_bit(EV_KEY, extra_key_dev->evbit);
	__set_bit(KEY_VOLUME_UP, extra_key_dev->keybit);
	__set_bit(KEY_VOLUME_DOWN, extra_key_dev->keybit);
	__set_bit(KEY_POWER, extra_key_dev->keybit);
	__set_bit(KEY_VOLUME_MUTE, extra_key_dev->keybit);
	__set_bit(KEY_VOLUME_TRIG, extra_key_dev->keybit);

	return 0;
}

static int thp_input_pen_device_register(struct thp_core_data *cd)
{
	int rc;
	char *node = NULL;
	struct thp_input_pen_dev_config *pen_config = NULL;
	struct input_dev *pen_dev = input_allocate_device();

	if (pen_dev == NULL) {
		thp_log_err(cd, "%s:failed to allocate memory\n", __func__);
		rc = -ENOMEM;
		goto err_out;
	}

	pen_dev->name = TS_PEN_DEV_NAME;
	if (cd->sub_solution == THP_SOLUTION) {
		node = kzalloc(sizeof(char) * MULTI_PANEL_NODE_BUF_LEN, GFP_KERNEL);
		if (!node) {
			thp_log_err(cd, "%s:node is null\n", __func__);
			rc = -ENOMEM;
			goto err_free_dev;
		}
		rc = snprintf(node, MULTI_PANEL_NODE_BUF_LEN, "%s%d",
			TS_PEN_DEV_NAME, cd->multi_panel_index);
		if (rc < 0) {
			thp_log_err(cd, "%s: snprintf err\n", __func__);
			goto err_free_dev;
		}

		pen_dev->name = (const char *)node;
		thp_log_info(cd, "%s pen_dev->name is :%s\n", __func__,
			pen_dev->name);
	}
	cd->thp_mt_wrapper->pen_dev = pen_dev;
	pen_config = &cd->thp_mt_wrapper->input_pen_dev_config;
	rc = thp_parse_pen_input_config(cd, pen_config);
	if (rc)
		thp_log_err(cd, "%s: parse pen input config failed: %d\n",
			__func__, rc);

	rc = thp_set_pen_input_config(cd, pen_dev);
	if (rc) {
		thp_log_err(cd, "%s:set input config failed : %d\n",
			__func__, rc);
		goto err_free_dev;
	}
	rc = input_register_device(pen_dev);
	if (rc) {
		thp_log_err(cd, "%s:input dev register failed : %d\n",
			__func__, rc);
		goto err_free_dev;
	}
	return rc;
err_free_dev:
	if (node) {
		kfree(node);
		node = NULL;
	}
	input_free_device(pen_dev);
err_out:
	return rc;
}

static int thp_input_extra_key_register(struct thp_core_data *cd)
{
	int rc;
	struct input_dev *extra_key = input_allocate_device();

	if (extra_key == NULL) {
		thp_log_err(cd, "%s:failed to allocate memory\n", __func__);
		rc = -ENOMEM;
		goto err_out;
	}

	extra_key->name = TS_EXTRA_KEY_DEV_NAME;
	cd->thp_mt_wrapper->extra_key_dev = extra_key;

	rc = thp_set_extra_key_input_config(cd, extra_key);
	if (rc) {
		thp_log_err(cd, "%s:set input config failed : %d\n",
			__func__, rc);
		goto err_free_dev;
	}
	rc = input_register_device(extra_key);
	if (rc) {
		thp_log_err(cd, "%s:input dev register failed : %d\n",
			__func__, rc);
		goto err_free_dev;
	}
	return rc;
err_free_dev:
	input_free_device(extra_key);
err_out:
	return rc;
}

int thp_mt_wrapper_input_dev_register(struct thp_core_data *cd)
{
	struct input_dev *input_dev = NULL;
	struct thp_mt_wrapper_data *mt_wrapper;
	int rc;
	char *node = NULL;

	if (cd->thp_mt_wrapper) {
		thp_log_err(cd, "%s:thp_mt_wrapper have inited, exit\n", __func__);
		return 0;
	}

	mt_wrapper = kzalloc(sizeof(struct thp_mt_wrapper_data), GFP_KERNEL);
	if (!mt_wrapper) {
		thp_log_err(cd, "%s:out of memory\n", __func__);
		return -ENOMEM;
	}

	init_waitqueue_head(&mt_wrapper->wait);

	input_dev = input_allocate_device();
	if (!input_dev) {
		thp_log_err(cd, "%s:Unable to allocated input device\n", __func__);
		rc = -ENOMEM;
		goto input_dev_reg_err;
	}

	input_dev->name = THP_INPUT_DEVICE_NAME;
	input_dev->dev.parent = cd->dev;
	if (cd->sub_solution == THP_SOLUTION) {
		node = kzalloc(sizeof(char) * MULTI_PANEL_NODE_BUF_LEN, GFP_KERNEL);
		if (!node) {
			thp_log_err(cd, "%s:node is null\n", __func__);
			rc = -ENOMEM;
			goto input_dev_reg_err;
		}
		rc = snprintf(node, MULTI_PANEL_NODE_BUF_LEN, "%s%d",
			THP_INPUT_DEVICE_NAME, cd->multi_panel_index);
		if (rc < 0) {
			thp_log_err(cd, "%s: snprintf err\n", __func__);
			goto input_dev_reg_err;
		}

		input_dev->name = (const char *)node;
		thp_log_info(cd, "%s input_dev name is :%s\n", __func__,
			input_dev->name);
	}

	rc = thp_parse_input_config(cd, &mt_wrapper->input_dev_config);
	if (rc)
		thp_log_err(cd, "%s: parse config fail\n", __func__);

	__set_bit(EV_SYN, input_dev->evbit);
	__set_bit(EV_KEY, input_dev->evbit);
	__set_bit(EV_ABS, input_dev->evbit);
	__set_bit(BTN_TOUCH, input_dev->keybit);
	__set_bit(BTN_TOOL_FINGER, input_dev->keybit);
	__set_bit(INPUT_PROP_DIRECT, input_dev->propbit);
	__set_bit(KEY_F26, input_dev->keybit);
	__set_bit(TS_DOUBLE_CLICK, input_dev->keybit);
	__set_bit(KEY_FINGER_DOWN, input_dev->keybit);
	__set_bit(KEY_FINGER_UP, input_dev->keybit);
	__set_bit(TS_STYLUS_WAKEUP_TO_MEMO, input_dev->keybit);
	__set_bit(KEY_VOLUME_UP, input_dev->keybit);
	__set_bit(KEY_VOLUME_DOWN, input_dev->keybit);
	__set_bit(KEY_POWER, input_dev->keybit);
	__set_bit(TS_SINGLE_CLICK, input_dev->keybit);

	input_set_abs_params(input_dev, ABS_X, 0,
			mt_wrapper->input_dev_config.abs_max_x - 1, 0, 0);
	input_set_abs_params(input_dev, ABS_Y, 0,
			mt_wrapper->input_dev_config.abs_max_y - 1, 0, 0);
	input_set_abs_params(input_dev, ABS_PRESSURE,
			0, mt_wrapper->input_dev_config.abs_max_z, 0, 0);
	if (cd->support_dynamic_resolution) {
		input_set_abs_params(input_dev, ABS_MT_POSITION_X,
			0, mt_wrapper->input_dev_config.abs_max_x * cd->res_scale - 1, 0, 0);
		input_set_abs_params(input_dev, ABS_MT_POSITION_Y,
			0, mt_wrapper->input_dev_config.abs_max_y * cd->res_scale - 1, 0, 0);
	} else {
		input_set_abs_params(input_dev, ABS_MT_POSITION_X,
			0, mt_wrapper->input_dev_config.abs_max_x - 1, 0, 0);
		input_set_abs_params(input_dev, ABS_MT_POSITION_Y,
			0, mt_wrapper->input_dev_config.abs_max_y - 1, 0, 0);
	}
	input_set_abs_params(input_dev, ABS_MT_PRESSURE,
			0, mt_wrapper->input_dev_config.abs_max_z, 0, 0);
	input_set_abs_params(input_dev, ABS_MT_TRACKING_ID, 0,
			mt_wrapper->input_dev_config.tracking_id_max - 1, 0, 0);
	input_set_abs_params(input_dev, ABS_MT_TOUCH_MAJOR,
			0, mt_wrapper->input_dev_config.major_max, 0, 0);
	input_set_abs_params(input_dev, ABS_MT_TOUCH_MINOR,
			0, mt_wrapper->input_dev_config.minor_max, 0, 0);
	input_set_abs_params(input_dev, ABS_MT_ORIENTATION,
			mt_wrapper->input_dev_config.orientation_min,
			mt_wrapper->input_dev_config.orientation_max, 0, 0);
	input_set_abs_params(input_dev, ABS_MT_BLOB_ID, 0,
			INPUT_MT_WRAPPER_MAX_FINGERS, 0, 0);
	if (cd->support_b_protocol) {
		input_mt_init_slots(input_dev, THP_MT_WRAPPER_MAX_FINGERS, 0);
		thp_log_info(cd, "%s:type b protocol init\n", __func__);
	}

	rc = input_register_device(input_dev);
	if (rc) {
		thp_log_err(cd, "%s:failed to register input device\n", __func__);
		goto input_dev_reg_err;
	}

	mt_wrapper->input_dev = input_dev;
	cd->thp_mt_wrapper = mt_wrapper;
	return 0;

input_dev_reg_err:
	if (node) {
		kfree(node);
		node = NULL;
	}
	if (mt_wrapper) {
		kfree(mt_wrapper);
		mt_wrapper = NULL;
	}
	return rc;
}

int thp_mt_wrapper_input_dev_deregister(struct thp_core_data *cd)
{
	if (cd->thp_mt_wrapper) {
		input_unregister_device(cd->thp_mt_wrapper->input_dev);
		if (cd->pen_supported)
			input_unregister_device(cd->thp_mt_wrapper->pen_dev);
	}

	if ((cd->sub_solution == THP_SOLUTION) &&
		(cd->thp_mt_wrapper->input_dev->name)) {
		kfree(cd->thp_mt_wrapper->input_dev->name);
		cd->thp_mt_wrapper->input_dev->name = NULL;
	}

	if (cd->thp_mt_wrapper) {
		kfree(cd->thp_mt_wrapper);
		cd->thp_mt_wrapper = NULL;
	}
	return 0;
}

int thp_mt_wrapper_misc_dev_register(struct thp_core_data *cd)
{
	int rc;
	struct miscdevice *misc_device = NULL;
	char *node = NULL;

	misc_device = kzalloc(sizeof(struct miscdevice), GFP_KERNEL);
	if (!misc_device) {
		thp_log_err(cd, "%s: misc_device out of memory\n", __func__);
		return -ENOMEM;
	}

	misc_device->minor = MISC_DYNAMIC_MINOR;
	misc_device->fops = &g_thp_mt_wrapper_fops;
	misc_device->name = DEVICE_NAME;

	if (cd->multi_panel_index != SINGLE_TOUCH_PANEL) {
		node = kzalloc(sizeof(char) * MULTI_PANEL_NODE_BUF_LEN, GFP_KERNEL);
		if (!node) {
			thp_log_err(cd, "%s:node is null\n", __func__);
			rc = -ENOMEM;
			goto misc_dev_reg_err;
		}
		rc = snprintf(node, MULTI_PANEL_NODE_BUF_LEN, "%s%d",
			DEVICE_NAME, cd->multi_panel_index);
		if (rc < 0) {
			thp_log_err(cd, "%s: snprintf err\n", __func__);
			goto misc_dev_reg_err;
		}

		misc_device->name = (const char *)node;
		thp_log_info(cd, "%s misc name is :%s\n", __func__,
			misc_device->name);
	}
	rc = misc_register(misc_device);
	if (rc) {
		thp_log_err(cd, "%s:failed to register misc device\n", __func__);
		goto misc_dev_reg_err;
	}
	cd->thp_mt_wrapper_misc_device = misc_device;

	return 0;

misc_dev_reg_err:
	if (node) {
		kfree(node);
		node = NULL;
	}
	if (misc_device) {
		kfree(misc_device);
		misc_device = NULL;
	}
	return rc;
}

int thp_mt_wrapper_misc_dev_deregister(struct thp_core_data *cd)
{
	if (cd->thp_mt_wrapper_misc_device)
		misc_deregister(cd->thp_mt_wrapper_misc_device);

	if ((cd->multi_panel_index != SINGLE_TOUCH_PANEL) &&
		(cd->thp_mt_wrapper_misc_device->name)) {
		kfree(cd->thp_mt_wrapper_misc_device->name);
		cd->thp_mt_wrapper_misc_device->name = NULL;
	}

	if (cd->thp_mt_wrapper_misc_device) {
		kfree(cd->thp_mt_wrapper_misc_device);
		cd->thp_mt_wrapper_misc_device = NULL;
	}
	return 0;
}

int thp_mt_wrapper_init(struct thp_core_data *cd)
{
	int rc;

	rc = thp_mt_wrapper_input_dev_register(cd);
	if (rc) {
		thp_log_err(cd, "%s: failed to init input_dev\n", __func__);
		return rc;
	}

	rc = thp_mt_wrapper_misc_dev_register(cd);
	if (rc) {
		thp_log_err(cd, "%s: failed to init misc_dev\n", __func__);
		thp_mt_wrapper_input_dev_deregister(cd);
		return rc;
	}

	if (cd->pen_supported) {
		rc = thp_input_pen_device_register(cd);
		if (rc)
			thp_log_err(cd, "%s:pen register failed\n", __func__);
	}
	if (cd->support_extra_key_event_input) {
		rc = thp_input_extra_key_register(cd);
		if (rc)
			thp_log_err(cd, "%s:ring key register failed\n", __func__);
	}
	atomic_set(&cd->thp_mt_wrapper->status_updated, 0);
	if ((cd->pen_supported) && (cd->pen_mt_enable_flag)) {
		atomic_set(&cd->last_stylus3_status, 0);
		atomic_set(&cd->callback_event_flag, false);
		init_completion(&cd->stylus3_status_flag);
		init_completion(&cd->stylus3_callback_flag);
	}
	if (cd->support_grip_recognition)
		init_completion(&cd->grip_data_setting_flag);

	return 0;
}
EXPORT_SYMBOL(thp_mt_wrapper_init);

void thp_mt_wrapper_exit(struct thp_core_data *cd)
{
	thp_mt_wrapper_input_dev_deregister(cd);
	thp_mt_wrapper_misc_dev_deregister(cd);
}
EXPORT_SYMBOL(thp_mt_wrapper_exit);

