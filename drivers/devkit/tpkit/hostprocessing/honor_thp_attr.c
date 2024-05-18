/*
 * Honor Touchscreen Driver
 *
 * Copyright (c) 2017-2021 Honor Technologies Co., Ltd.
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

#include "honor_thp.h"
#include <linux/kernel.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <linux/delay.h>
#include <asm/byteorder.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/spi/spi.h>
#include <linux/ctype.h>
#if ((defined CONFIG_FB) && (!(IS_ENABLED(CONFIG_HONOR_THP_QCOM) || \
	IS_ENABLED(CONFIG_HONOR_THP_MTK))))
#include "honor_fb.h"
#endif
#ifdef CONFIG_HONOR_SENSORS_2_0
#include "sensor_scp.h"
#endif

#define SYSFS_PROPERTY_PATH "afe_properties"
#define SYSFS_TOUCH_PATH "touchscreen"
#define THP_CHARGER_BUF_LEN 32
#define THP_BASE_DECIMAL 10
#define NEED_SCREEN_OFF 1
#define STYLUS3_CONNECT 2

u8 g_thp_log_cfg;
EXPORT_SYMBOL(g_thp_log_cfg);
#if IS_ENABLED(CONFIG_HONOR_TRUSTED_TOUCH)
struct kset *g_qts_kset;
#endif

static ssize_t thp_tui_wake_up_enable_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	int ret;
	struct thp_core_data *cd = dev_get_drvdata(dev);

	ret = strncmp(buf, "open", sizeof("open"));
	if (ret == 0) {
		cd->thp_ta_waitq_flag = WAITQ_WAKEUP;
		wake_up_interruptible(&(cd->thp_ta_waitq));
		thp_log_err(cd, "%s wake up thp_ta_flag\n", __func__);
	}
	return count;
}

static ssize_t thp_tui_wake_up_enable_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	return 0;
}

static ssize_t thp_hostprocessing_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	return snprintf(buf, PAGE_SIZE, "hostprocessing\n");
}

static ssize_t thp_status_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct thp_core_data *cd = dev_get_drvdata(dev);

	return snprintf(buf, PAGE_SIZE - 1, "status=0x%x\n",
		thp_get_status_all(cd));
}

/* If not config ic_name in dts, it will be "unknown" */
static ssize_t thp_chip_info_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct thp_core_data *cd = dev_get_drvdata(dev);

	if (cd->hide_product_info_en && (!thp_is_factory()))
		return snprintf(buf, PAGE_SIZE, "%s\n", cd->project_id);

	return snprintf(buf, PAGE_SIZE, "%s-%s-%s\n",
		cd->thp_dev->ic_name,
		cd->project_id,
		cd->vendor_name ? cd->vendor_name : "unknown");
}

static ssize_t thp_loglevel_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	u8 new_level = g_thp_log_cfg ? 0 : 1;

	int len = snprintf(buf, PAGE_SIZE, "%d -> %d\n",
		g_thp_log_cfg, new_level);

	g_thp_log_cfg = new_level;

	return len;
}

#if defined(THP_CHARGER_FB)
static ssize_t thp_host_charger_state_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct thp_core_data *cd = dev_get_drvdata(dev);

	thp_log_debug(cd, "%s called\n", __func__);

	return snprintf(buf, THP_CHARGER_BUF_LEN, "%d\n",
			thp_get_status(cd, THP_STATUS_CHARGER));
}

static ssize_t thp_host_charger_state_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	struct thp_core_data *cd = dev_get_drvdata(dev);
	/*
	 * get value of charger status from first byte of buf
	 */
	unsigned int value = buf[0] - '0';

	thp_log_info(cd, "%s: input value is %d\n", __func__, value);

	thp_set_status(cd, THP_STATUS_CHARGER, value);

	return count;
}
#endif

static ssize_t thp_roi_data_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct thp_core_data *cd = dev_get_drvdata(dev);
	short *roi_data = cd->roi_data;

	memcpy(buf, roi_data, ROI_DATA_LENGTH * sizeof(short));

	return ROI_DATA_LENGTH * sizeof(short);
}

static const char *move_to_next_number(const char *str_in)
{
	const char *str = str_in;
	const char *next_num = NULL;

	str = skip_spaces(str);
	next_num = strchr(str, ' ');
	if (next_num)
		return next_num;

	return str_in;
}

static ssize_t thp_roi_data_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	int i = 0;
	int num;
	struct thp_core_data *cd = dev_get_drvdata(dev);
	short *roi_data = cd->roi_data;
	const char *str = buf;

	while (i < ROI_DATA_LENGTH && *str) {
		if (sscanf(str, "%7d", &num) < 0)
			break;

		str = move_to_next_number(str);
		roi_data[i++] = (short)num;
	}
	if (cd->need_notify_to_roi_algo)
		sysfs_notify(&dev->kobj, NULL, "roi_data");
	return count;
}

static ssize_t thp_roi_data_debug_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	int count = 0;
	int i;
	int ret;
	struct thp_core_data *cd = dev_get_drvdata(dev);
	short *roi_data = cd->roi_data;

	for (i = 0; i < ROI_DATA_LENGTH; ++i) {
		ret = snprintf(buf + count, PAGE_SIZE - count, "%4d ",
			roi_data[i]);
		if (ret > 0)
			count += ret;
		/* every 7 data is a row */
		if (!((i + 1) % 7)) {
			ret = snprintf(buf + count, PAGE_SIZE - count, "\n");
			if (ret > 0)
				count += ret;
		}
	}

	return count;
}

static ssize_t thp_roi_enable_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	long status = 0;
	int ret;
	struct thp_core_data *cd = dev_get_drvdata(dev);

	ret = kstrtoul(buf, THP_BASE_DECIMAL, &status);
	if (ret) {
		thp_log_err(cd, "%s: illegal input\n", __func__);
		return ret;
	}

	thp_set_status(cd, THP_STATUS_ROI, !!status);
	thp_log_info(cd, "%s: set roi enable status to %d\n", __func__, !!status);

	return count;
}

static ssize_t thp_roi_enable_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct thp_core_data *cd = dev_get_drvdata(dev);

	return snprintf(buf, PAGE_SIZE - 1, "%d\n",
		thp_get_status(cd, THP_STATUS_ROI));
}

static ssize_t thp_holster_enable_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	long status = 0;
	int ret;
	struct thp_core_data *cd = dev_get_drvdata(dev);
	if (cd->holster_support == 0) {
		thp_log_err(cd, "%s: holster not support\n", __func__);
		return count;
	}
	ret = kstrtoul(buf, THP_BASE_DECIMAL, &status);
	if (ret) {
		thp_log_err(cd, "%s: illegal input\n", __func__);
		return ret;
	}
	thp_set_status(cd, THP_STATUS_HOLSTER, !!status);
	thp_log_info(cd, "%s: set holster status to %d\n", __func__, !!status);
	return count;
}

static ssize_t thp_holster_enable_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct thp_core_data *cd = dev_get_drvdata(dev);

	return snprintf(buf, PAGE_SIZE - 1, "%d\n",
				thp_get_status(cd, THP_STATUS_HOLSTER));
}

static ssize_t thp_glove_enable_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	long status = 0;
	int ret;
	struct thp_core_data *cd = dev_get_drvdata(dev);

	ret = kstrtoul(buf, THP_BASE_DECIMAL, &status);
	if (ret) {
		thp_log_err(cd, "%s: illegal input\n", __func__);
		return ret;
	}

	thp_set_status(cd, THP_STATUS_GLOVE, !!status);
	thp_log_info(cd, "%s: set glove status to %d\n", __func__, !!status);

	return count;
}

static ssize_t thp_glove_enable_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct thp_core_data *cd = dev_get_drvdata(dev);

	return snprintf(buf, PAGE_SIZE - 1, "%d\n",
			thp_get_status(cd, THP_STATUS_GLOVE));
}


static ssize_t thp_holster_window_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	struct thp_core_data *cd = dev_get_drvdata(dev);
	int ret;
	int window_enable;
	int x0 = 0;
	int y0 = 0;
	int x1 = 0;
	int y1 = 0;
	if (cd->holster_support == 0) {
		thp_log_err(cd, "%s: holster not support\n", __func__);
		return count;
	}
	ret = sscanf(buf, "%4d %4d %4d %4d %4d",
		&window_enable, &x0, &y0, &x1, &y1);
	if (ret <= 0) {
		thp_log_err(cd, "%s: illegal input\n", __func__);
		return -EBUSY;
	}
	cd->window.x0 = x0;
	cd->window.y0 = y0;
	cd->window.x1 = x1;
	cd->window.y1 = y1;

	thp_set_status(cd, THP_STATUS_HOLSTER, !!window_enable);
	thp_set_status(cd, THP_STATUS_WINDOW_UPDATE,
		!thp_get_status(cd, THP_STATUS_WINDOW_UPDATE));
	thp_log_info(cd, "%s: update window %d %d %d %d %d\n",
		__func__, window_enable, x0, y0, x1, y1);

	return count;
}

static ssize_t thp_holster_window_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct thp_core_data *cd = dev_get_drvdata(dev);
	struct thp_window_info *window = &cd->window;

	return snprintf(buf, PAGE_SIZE - 1, "%d %d %d %d %d\n",
			thp_get_status(cd, THP_STATUS_HOLSTER),
			window->x0, window->y0, window->x1, window->y1);
}

static ssize_t thp_touch_switch_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	struct thp_core_data *cd = dev_get_drvdata(dev);
	int ret;
	int type = 0;
	int status = 0;
	int parameter = 0;

	ret = sscanf(buf, "%4d,%4d,%4d", &type, &status, &parameter);
	if (ret <= 0) {
		thp_log_err(cd, "%s: illegal input\n", __func__);
		return -EBUSY;
	}
	cd->scene_info.type = type;
	cd->scene_info.status = status;
	cd->scene_info.parameter = parameter;
	if (cd->support_interval_adjustment) {
		/* type:5 status:3 paramerter:0 means game mode on */
		if ((type == GAME_MODE_TYPE) &&
			(status == GAME_MODE_STATUS_ON) &&
			(parameter == GAME_MODE_PARAM))
			cd->time_adjustment_switch = true;
		/* type:5 status:4 paramerter:0 means game mode off */
		else if ((type == GAME_MODE_TYPE) &&
			(status == GAME_MODE_STATUS_OFF) &&
			(parameter == GAME_MODE_PARAM))
			cd->time_adjustment_switch = false;
		thp_log_info(cd, "%s: time_adjustment_switch = %d\n", __func__,
			cd->time_adjustment_switch);
	}

	thp_set_status(cd, THP_STATUS_TOUCH_SCENE,
		!thp_get_status(cd, THP_STATUS_TOUCH_SCENE));
	thp_log_info(cd, "%s:touch scene update %d %d %d\n",
		__func__, type, status, parameter);

	return count;
}

static ssize_t thp_touch_switch_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	unsigned int value = 0;
	struct thp_core_data *cd = dev_get_drvdata(dev);

	thp_log_info(cd, "%s:value = %d\n", __func__, value);

	/*
	 * Inherit from tskit
	 * which will be use for ApsService to decide doze is support or not
	 * This feature is not supported by default in THP
	 */
	return snprintf(buf, PAGE_SIZE - 1, "%d\n", value);
}

static ssize_t thp_udfp_enable_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct thp_core_data *cd = dev_get_drvdata(dev);

	return snprintf(buf, PAGE_SIZE - 1, "udfp status : %d\n",
		thp_get_status(cd, THP_STATUS_UDFP));
}

static ssize_t thp_udfp_enable_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	unsigned int value = 0;
	int ret;
	struct thp_core_data *cd = dev_get_drvdata(dev);

	ret = sscanf(buf, "%d", &value);
	if (ret <= 0) {
		thp_log_err(cd, "%s: illegal input\n", __func__);
		return -EINVAL;
	}

	thp_set_status(cd, THP_STATUS_UDFP, value);
	thp_log_info(cd, "%s: ud fp status: %d\n", __func__, !!value);
#ifdef CONFIG_HONOR_SENSORS_2_0
	/* Use in-screen fingerprints on the mtk-53rd and 73rd platforms */
	send_sensor_scp_udfp(value);
#endif

	return count;
}

static ssize_t stylus_wakeup_ctrl_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct thp_core_data *cd = dev_get_drvdata(dev);
	int stylus_mode = STYLUS_WAKEUP_DISABLE;

	if ((dev == NULL) || (attr == NULL) || (buf == NULL) ||
		(cd == NULL)) {
		thp_log_err(cd, "%s:input null ptr\n", __func__);
		return -EINVAL;
	}
	if (cd->pen_supported == 0) {
		thp_log_err(cd, "%s not support\n", __func__);
		return -EINVAL;
	}
	return snprintf(buf, PAGE_SIZE - 1, "%d\n", stylus_mode);
}

static ssize_t stylus_wakeup_ctrl_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	int parameter = 0;
	int ret;
	unsigned int cur_status;
	struct thp_core_data *cd = dev_get_drvdata(dev);

	if ((dev == NULL) || (attr == NULL) || (buf == NULL) ||
		(cd == NULL)) {
		thp_log_err(cd, "%s:input null ptr\n", __func__);
		return -EINVAL;
	}
	if (cd->send_bt_status_to_fw) {
		cur_status = atomic_read(&cd->last_stylus3_status);
		thp_log_info(cd, "%s:cur_status:%d\n", __func__, cur_status);
	}
	if (cd->pen_supported == 0) {
		thp_log_err(cd, "%s not support\n", __func__);
		return -EINVAL;
	}
	ret = sscanf(buf, "%1d", &parameter);
	if (ret <= 0)
		thp_log_err(cd, "%s:read node error\n", __func__);
	thp_log_info(cd, "%s:parameter:%d\n", __func__, parameter);
	switch (parameter) {
	case STYLUS_WAKEUP_TESTMODE_IN:
		thp_log_info(cd, "%s:enter test mode\n", __func__);
		if (cd->send_bt_status_to_fw) {
			cd->enter_stylus3_mmi_test = true;
			if ((cur_status & STYLUS3_CONNECT) != STYLUS3_CONNECT) {
				thp_log_info(cd, "ready set stylus3 connect\n");
				atomic_set(&cd->last_stylus3_status, STYLUS3_CONNECT);
				if (cd->thp_dev->ops->bt_handler)
					if (cd->thp_dev->ops->bt_handler(cd->thp_dev, false))
						thp_log_err(cd, "ioctl mmi in send bt status fail\n");
				atomic_set(&cd->last_stylus3_status, cur_status);
			}
		}
		cd->stylus_status = thp_get_status(cd, THP_STATUS_STYLUS);
		cd->stylus3_status = thp_get_status(cd, THP_STATUS_STYLUS3);
		/* set bit 1 to turn on the pen switch */
		thp_set_status(cd, THP_STATUS_STYLUS, 1);
		thp_set_status(cd, THP_STATUS_STYLUS3, 1);
		break;
	case STYLUS_WAKEUP_TESTMODE_OUT:
		thp_log_info(cd, "%s:exit test mode, recover last status\n",
			__func__);
		if (cd->send_bt_status_to_fw) {
			cd->enter_stylus3_mmi_test = false;
			if ((cur_status & STYLUS3_CONNECT) != STYLUS3_CONNECT) {
				thp_log_info(cd, "ready set stylus3 disconnect\n");
				atomic_set(&cd->last_stylus3_status, 0);
				if (cd->thp_dev->ops->bt_handler)
					if (cd->thp_dev->ops->bt_handler(cd->thp_dev, false))
						thp_log_err(cd, "ioctl mmi out send bt status fail\n");
				atomic_set(&cd->last_stylus3_status, cur_status);
			}
		}
		thp_set_status(cd, THP_STATUS_STYLUS, cd->stylus_status);
		thp_set_status(cd, THP_STATUS_STYLUS3, cd->stylus3_status);
		break;
	case STYLUS_WAKEUP_DISABLE:
		/* set bit 0 to turn off the pen switch */
		thp_set_status(cd, THP_STATUS_STYLUS, 0);
		cd->stylus_status = parameter;
		break;
	case STYLUS_WAKEUP_NORMAL_STATUS:
	case STYLUS_WAKEUP_LOW_FREQENCY:
		/* set bit 1 to turn on the pen switch */
		thp_set_status(cd, THP_STATUS_STYLUS, 1);
		cd->stylus_status = parameter;
		break;
	case STYLUS_GESTURE_WAKEUP_ENABLE:
		if (cd->support_pen_wakeup_gesture) {
			thp_log_info(cd, "%s:stylus gesture setting enable\n", __func__);
			cd->stylus_gesture_status = 1;
			if (cd->thp_dev->ops->bt_handler)
				if (cd->thp_dev->ops->bt_handler(cd->thp_dev, false))
					thp_log_err(cd, "send bt status to fw fail\n");
		}
		break;
	case STYLUS_GESTURE_WAKEUP_DISABLE:
		if (cd->support_pen_wakeup_gesture) {
			thp_log_info(cd, "%s:stylus gesture setting disable\n", __func__);
			cd->stylus_gesture_status = 0;
			if (cd->thp_dev->ops->bt_handler)
				if (cd->thp_dev->ops->bt_handler(cd->thp_dev, false))
					thp_log_err(cd, "send bt status to fw fail\n");
		}
		break;
	default:
		thp_log_info(cd, "%s:invalid  input\n", __func__);
		break;
	}
	return count;
}

static ssize_t thp_supported_func_indicater_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct thp_core_data *cd = dev_get_drvdata(dev);

	return snprintf(buf, PAGE_SIZE - 1, "%d\n",
		cd->supported_func_indicater);
}

static ssize_t thp_easy_wakeup_gesture_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct thp_core_data *cd = dev_get_drvdata(dev);
	struct thp_easy_wakeup_info *info = &cd->easy_wakeup_info;
	ssize_t ret;

	if (!cd->support_gesture_mode) {
		thp_log_err(cd, "%s not support\n", __func__);
		return -EINVAL;
	}
	thp_log_info(cd, "%s\n", __func__);

	if (!dev) {
		thp_log_err(cd, "dev is null\n");
		return -EINVAL;
	}

	ret = snprintf(buf, MAX_STR_LEN, "0x%04X\n",
		info->easy_wakeup_gesture);

	return ret;
}

static ssize_t thp_easy_wakeup_gesture_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t size)
{
	struct thp_core_data *cd = dev_get_drvdata(dev);
	struct thp_easy_wakeup_info *info = NULL;
	unsigned int value = 0;
	int ret;

	if (!cd->support_gesture_mode) {
		thp_log_err(cd, "%s not support\n", __func__);
		return -EINVAL;
	}
	thp_log_info(cd, "%s: called\n", __func__);

	if (!dev) {
		thp_log_err(cd, "dev is null\n");
		return -EINVAL;
	}
	ret = sscanf(buf, "%5u", &value);
	if ((ret <= 0) || (value > TS_GESTURE_INVALID_COMMAND)) {
		thp_log_err(cd, "invalid parm\n");
		return -EBUSY;
	}
	info = &cd->easy_wakeup_info;
	info->easy_wakeup_gesture = value;
	cd->double_click_switch = (is_app_enable_gesture(GESTURE_DOUBLE_CLICK) &
		info->easy_wakeup_gesture) ? DOUBLE_CLICK_ON : DOUBLE_CLICK_OFF;
	cd->single_click_switch = (is_app_enable_gesture(GESTURE_SINGLE_CLICK) &
		info->easy_wakeup_gesture) ? SINGLE_CLICK_ON : SINGLE_CLICK_OFF;
	thp_log_info(cd, "easy_wakeup_gesture=0x%x\n", info->easy_wakeup_gesture);
	thp_log_info(cd, "double_click_switch:%u, single_click_switch %u\n",
		cd->double_click_switch, cd->single_click_switch);
	if (info->easy_wakeup_gesture == false) {
		cd->sleep_mode = TS_POWER_OFF_MODE;
		thp_log_info(cd, "poweroff mode\n");
	} else {
		cd->sleep_mode = TS_GESTURE_MODE;
		thp_log_info(cd, "gesture mode\n");
	}

	if ((cd->support_pen_wakeup_gesture) && (cd->thp_dev->ops->bt_handler))
		if (cd->thp_dev->ops->bt_handler(cd->thp_dev, false))
			thp_log_err(cd, "send bt status to fw fail\n");
	thp_log_info(cd, "ts gesture wakeup done\n");
	return size;
}

static ssize_t thp_wakeup_gesture_enable_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	unsigned long tmp = 0;
	struct thp_core_data *cd = dev_get_drvdata(dev);
	int error;

	if (!cd->support_gesture_mode) {
		thp_log_err(cd, "%s not support\n", __func__);
		return -EINVAL;
	}
	thp_log_info(cd, "%s called\n", __func__);

	error = sscanf(buf, "%4lu", &tmp);
	if (error <= 0) {
		thp_log_err(cd, "sscanf return invaild :%d\n", error);
		return -EINVAL;
	}
	thp_log_info(cd, "%s:%lu\n", __func__, tmp);
	return count;
}

static ssize_t thp_wakeup_gesture_enable_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct thp_core_data *cd = dev_get_drvdata(dev);

	if (!cd->support_gesture_mode) {
		thp_log_err(cd, "%s not support\n", __func__);
		return -EINVAL;
	}
	thp_log_info(cd, "%s called\n", __func__);
	return 0;
}

static ssize_t thp_easy_wakeup_control_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t size)
{
	struct thp_core_data *cd = dev_get_drvdata(dev);

	unsigned long value = 0;
	int ret;
	int error;

	if (!cd->support_gesture_mode) {
		thp_log_err(cd, "%s not support\n", __func__);
		return -EINVAL;
	}
	thp_log_info(cd, "%s called\n", __func__);

	ret = sscanf(buf, "%4lu", &value);
	if (ret <= 0 || value > TS_GESTURE_INVALID_CONTROL_NO) {
		thp_log_info(cd, "%s->invalid parm\n", __func__);
		return -EINVAL;
	}

	value = (u8) value & TS_GESTURE_COMMAND;
	if (value == 1) {
		if (cd->thp_dev->ops->chip_wrong_touch) {
			error = cd->thp_dev->ops->chip_wrong_touch(cd->thp_dev);
			if (error < 0)
				thp_log_info(cd, "chip_wrong_touch error\n");
		} else {
			thp_log_info(cd, "chip_wrong_touch not init\n");
		}
	}
	thp_log_info(cd, "%s done\n", __func__);
	return size;
}

static ssize_t thp_easy_wakeup_position_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct thp_core_data *cd = dev_get_drvdata(dev);

	if (!cd->support_gesture_mode) {
		thp_log_err(cd, "%s not support\n", __func__);
		return -EINVAL;
	}
	return 0;
}

static ssize_t thp_oem_info_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	int error = NO_ERR;
	struct thp_core_data *cd = dev_get_drvdata(dev);

	thp_log_info(cd, "%s: called\n", __func__);

	if ((dev == NULL) || (cd == NULL)) {
		thp_log_err(cd, "%s: dev is null\n", __func__);
		return -EINVAL;
	}
	if (cd->support_oem_info == THP_OEM_INFO_LCD_EFFECT_TYPE) {
		error = snprintf(buf, OEM_INFO_DATA_LENGTH, "%s",
			cd->oem_info_data);
		if (error < 0) {
			thp_log_info(cd, "%s:oem info data:%s\n",
				__func__, cd->oem_info_data);
			return error;
		}
		thp_log_info(cd, "%s: oem info :%s\n", __func__, buf);
	}

	thp_log_debug(cd, "%s done\n", __func__);
	return error;
}


static ssize_t thp_fingerprint_switch_ctrl_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	struct thp_core_data *cd = dev_get_drvdata(dev);
	unsigned int udfp_enable = 0;
	unsigned int udfp_switch = 0;
	int ret;

	if (!cd->support_fingerprint_switch) {
		thp_log_debug(cd, "%s:no need to report fingerprint switch\n",
			__func__);
		return count;
	}
	/*
	 * 0,0:the fingerprint doesn't be enrolled
	 * 1,1:begin enroll or authenticate
	 * 1,0:end enroll or authenticate
	 */
	ret = sscanf(buf, "%4u,%4u", &udfp_enable, &udfp_switch);
	if (ret <= 0) {
		thp_log_err(cd, "%s: illegal input\n", __func__);
		return -EINVAL;
	}

	cd->udfp_status.udfp_enable = udfp_enable;
	cd->udfp_status.udfp_switch = udfp_switch;

	thp_set_status(cd, THP_STATUS_UDFP_SWITCH, !!udfp_switch);
	thp_log_info(cd, "%s: update udfp_status:%u %u\n",
		__func__, udfp_enable, udfp_switch);

	return count;
}

static ssize_t thp_fingerprint_switch_ctrl_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct thp_core_data *cd = dev_get_drvdata(dev);

	return snprintf(buf, PAGE_SIZE - 1, "%u,%u\n",
		cd->udfp_status.udfp_enable, cd->udfp_status.udfp_switch);
}

static ssize_t thp_ring_switch_ctrl_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	struct thp_core_data *cd = dev_get_drvdata(dev);
	unsigned int ring_status = 0;
	int ret;

	if ((dev == NULL) || (cd == NULL)) {
		thp_log_err(cd, "%s: dev or cd is null\n", __func__);
		return -EINVAL;
	}

	ret = sscanf(buf, "%4u", &ring_status);
	if (ret <= 0) {
		thp_log_err(cd, "%s: illegal input\n", __func__);
		return -EINVAL;
	}
	thp_log_info(cd, "%s:ring_status:%u\n", __func__, ring_status);
	if (!cd->support_ring_feature) {
		thp_log_err(cd, "%s: not support ring\n", __func__);
		return -EINVAL;
	}
	cd->ring_switch = RING_SWITCH_OFF;
	cd->phone_status = PNONE_STATUS_OFF;
	/*
	 * ring_status = 0:disbale report ring event
	 * ring_status = 1:enable report ring event
	 * ring_status = 2:on the phone
	 */
	switch (ring_status) {
	case RING_STAUS_ENABLE:
		cd->ring_switch = RING_SWITCH_ON;
		break;
	case RING_PHONE_STATUS:
		cd->ring_switch = RING_SWITCH_ON;
		cd->phone_status = PNONE_STATUS_ON;
		break;
	default:
		break;
	}

#ifdef CONFIG_HONOR_SHB_THP
	if ((cd->suspended || cd->support_ring_feature) &&
		(ring_status <= RING_PHONE_STATUS)) {
		ret = send_thp_driver_status_cmd(ring_status,
			0, ST_CMD_TYPE_SET_AUDIO_STATUS);
		thp_log_info(cd, "%s: %d\n", __func__, ret);
	}
#endif
	return count;
}

static ssize_t thp_ring_switch_ctrl_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct thp_core_data *cd = dev_get_drvdata(dev);

	if ((dev == NULL) || (cd == NULL)) {
		thp_log_err(cd, "%s: dev or cd is null\n", __func__);
		return -EINVAL;
	}
	return snprintf(buf, PAGE_SIZE - 1, "%u\n", cd->ring_switch);
}

static ssize_t thp_power_switch_ctrl_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	struct thp_core_data *cd = dev_get_drvdata(dev);
	unsigned int power_status = 0;
	int ret;

	if ((dev == NULL) || (cd == NULL)) {
		thp_log_err(cd, "%s: dev or cd is null\n", __func__);
		return -EINVAL;
	}

	ret = sscanf(buf, "%u", &power_status);
	if (ret <= 0) {
		thp_log_err(cd, "%s: illegal input\n", __func__);
		return -EINVAL;
	}
	thp_log_info(cd, "%s:power_status:0x%x\n", __func__, power_status);
	switch (power_status) {
	case WAKE_REASON_POWER_BUTTON:
		cd->power_switch = POWER_KEY_ON_CTRL;
		break;
	case WAKE_REASON_FINGER_PRINT:
	case WAKE_REASON_PICKUP:
		cd->power_switch = FINGERPRINT_ON_CTRL;
		break;
	case WAKE_REASON_PROXIMITY:
		cd->power_switch = PROXIMITY_ON_CTRL;
		break;
	case WAKE_REASON_UNKNOWN:
	case WAKE_REASON_APPLICATION:
	case WAKE_REASON_PLUGGED_IN:
	case WAKE_REASON_GESTURE:
	case WAKE_REASON_CAMERA_LAUNCH:
	case WAKE_REASON_WAKE_KEY:
	case WAKE_REASON_WAKE_MOTION:
	case WAKE_REASON_HDMI:
	case WAKE_REASON_LID:
		cd->power_switch = AUTO_OR_OTHER_ON_CTRL;
		break;
	case GO_TO_SLEEP_REASON_POWER_BUTTON:
		cd->power_switch = POWER_KEY_OFF_CTRL;
		break;
	case GO_TO_SLEEP_REASON_PROX_SENSOR:
		cd->power_switch = PROXIMITY_OFF_CTRL;
		break;
	case GO_TO_SLEEP_REASON_TIMEOUT:
		cd->power_switch = POWERON_TIMEOUT_OFF_CTRL;
		break;
	case GO_TO_SLEEP_REASON_APPLICATION:
	case GO_TO_SLEEP_REASON_DEVICE_ADMIN:
	case GO_TO_SLEEP_REASON_LID_SWITCH:
	case GO_TO_SLEEP_REASON_HDMI:
	case GO_TO_SLEEP_REASON_ACCESSIBILITY:
	case GO_TO_SLEEP_REASON_FORCE_SUSPEND:
	case GO_TO_SLEEP_REASON_WAIT_BRIGHTNESS_TIMEOUT:
	case GO_TO_SLEEP_REASON_PHONE_CALL:
		cd->power_switch = AUTO_OR_OTHER_OFF_CTRL;
		break;
	default:
		cd->power_switch = POWER_STATUS_NULL;
		return -EINVAL;
	}
	thp_log_info(cd, "%s :power_switch = %u\n", __func__, cd->power_switch);
	thp_set_status(cd, THP_STATUS_POWER_SWITCH_CTRL,
		!thp_get_status(cd, THP_STATUS_POWER_SWITCH_CTRL));
	return count;
}

static ssize_t thp_power_switch_ctrl_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct thp_core_data *cd = dev_get_drvdata(dev);

	if ((dev == NULL) || (cd == NULL)) {
		thp_log_err(cd, "%s: dev or cd is null\n", __func__);
		return -EINVAL;
	}
	return snprintf(buf, PAGE_SIZE - 1, "%u\n", cd->power_switch);
}

static void get_spi_hw_info(struct thp_core_data *cd)
{
	if (cd == NULL) {
		thp_log_err(cd, "%s:cd is null\n", __func__);
		return;
	}

#if (!(IS_ENABLED(CONFIG_HONOR_THP_QCOM) || IS_ENABLED(CONFIG_HONOR_THP_MTK)))
	if (cd->get_spi_hw_info_enable) {
		spi_show_err_info(cd->sdev);
		thp_log_info(cd, "%s: get spi hw info out\n", __func__);
	}
#endif
}

static ssize_t thp_factory_extra_cmd_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	int ret;
	unsigned int type = 0;
	int data = 0;
	struct thp_core_data *cd = dev_get_drvdata(dev);
#if ((defined CONFIG_FB) && (!(IS_ENABLED(CONFIG_HONOR_THP_QCOM) || \
	IS_ENABLED (CONFIG_HONOR_THP_MTK))))
	struct honor_fb_data_type *honorfd = honorfd_list[PRIMARY_PANEL_IDX];
#endif

	if ((dev == NULL) || (cd == NULL)) {
		thp_log_err(cd, "%s: dev is null\n", __func__);
		return -EINVAL;
	}
	if ((cd->support_factory_mode_extra_cmd == 0) || (cd->suspended)) {
		thp_log_err(cd, "%s: not support or suspended\n", __func__);
		return -EINVAL;
	}
	ret = sscanf(buf, "%3u,%4d", &type, &data);
	if (ret <= 0) {
		thp_log_info(cd, "%s: illegal input\n", __func__);
		return -EINVAL;
	}
	thp_log_info(cd, "%s: type:%u, data:%d\n",
		__func__, type, data);
	switch (type) {
	case SUSPEND_NEED_CAP_TEST:
		if (thp_is_factory()) {
			thp_log_info(cd, "%s in factory mode\n", __func__);
#if ((defined CONFIG_FB) && (!(IS_ENABLED(CONFIG_HONOR_THP_QCOM) || \
	IS_ENABLED(CONFIG_HONOR_THP_MTK))))
			if (data == NEED_SCREEN_OFF) {
				cd->always_poweron_in_screenoff = data;
				cd->factory_mode_current_backlight =
					honorfd->bl_level;
				thp_log_info(cd, "%s lcd power off current_bl = %d\n",
					__func__,
					cd->factory_mode_current_backlight);
				honor_fb_blank_sub(FB_BLANK_POWERDOWN,
					honorfd->fbi);
			} else {
				honor_fb_blank_sub(FB_BLANK_UNBLANK,
					honorfd->fbi);
				/* triggers refresh and brightness setting */
				honor_fb_frame_refresh(honorfd, "esd");
				msleep(100);
				honorfb_set_backlight(honorfd,
					cd->factory_mode_current_backlight,
					false);
				thp_log_info(cd, "%s lcd power on current_bl = %d\n",
					__func__,
					cd->factory_mode_current_backlight);
				cd->always_poweron_in_screenoff = data;
			}
#endif
		}
		break;
	default:
		return -EINVAL;
	}
	return count;
}


static ssize_t thp_dfx_info_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	int ret;
	unsigned int type = 0;
	int data = 0;
	struct thp_core_data *cd = dev_get_drvdata(dev);

	if (dev == NULL) {
		thp_log_err(cd, "%s: dev is null\n", __func__);
		return -EINVAL;
	}
	ret = sscanf(buf, "%3u,%4d", &type, &data);
	if (ret <= 0) {
		thp_log_err(cd, "%s: illegal input\n", __func__);
		return -EINVAL;
	}
	thp_log_info(cd, "%s: type:%u, data:%d\n",
		__func__, type, data);
	switch (type) {
	case SPI_HW_INFO:
		get_spi_hw_info(cd);
		break;
	default:
		return -EINVAL;
	}
	return count;
}

static ssize_t aod_touch_switch_ctrl_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	struct thp_core_data *cd = dev_get_drvdata(dev);
	struct thp_core_data *cd_main = thp_get_core_data();
	unsigned int aod_touch_enable;
	struct thp_cmd_node cmd;
	int ret;

	if ((dev == NULL) || (cd == NULL)) {
		thp_log_err(cd, "%s: dev or cd is null\n", __func__);
		return -EINVAL;
	}

	if (cd_main == NULL) {
		thp_log_err(cd, "%s: cd_main is null\n", __func__);
		return -EINVAL;
	}

	if (!cd->aod_display_support) {
		thp_log_err(cd, "%s not support\n", __func__);
		return -EINVAL;
	}

	ret = sscanf(buf, "%4u", &aod_touch_enable);
	if (ret <= 0) {
		thp_log_err(cd, "%s: illegal input, ret = %d\n", __func__, ret);
		return -EINVAL;
	}

	thp_log_info(cd, "%s: aod_touch_enable recv: %u\n", __func__,
		aod_touch_enable);
	memset(&cmd, 0, sizeof(cmd));
	cmd.command = AOD_TOUCH_STATUS_SWITCH;
	cmd.cmd_param.prv_params = cd;
	cmd.cmd_param.pub_params.aod_touch_status_switch = aod_touch_enable;
	ret = thp_put_one_cmd(cd_main, &cmd, NO_SYNC_TIMEOUT);
	if (ret)
		thp_log_err(cd, "%s: put cmd error :%d\n", __func__, ret);

	return count;
}

static ssize_t aod_touch_switch_ctrl_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct thp_core_data *cd = dev_get_drvdata(dev);

	if ((dev == NULL) || (cd == NULL)) {
		thp_log_err(cd, "%s: dev or cd is null\n", __func__);
		return -EINVAL;
	}

	if (!cd->aod_display_support) {
		thp_log_err(cd, "%s not support\n", __func__);
		return -EINVAL;
	}
	return snprintf(buf, PAGE_SIZE - 1, "%u\n", cd->aod_touch_status);
}

static ssize_t thp_ring_setting_config_ctrl_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	struct thp_core_data *cd = dev_get_drvdata(dev);
	int ret;
	unsigned int type = 0;
	unsigned int data = 0;
	unsigned int volume_side;

	if (!dev || !cd) {
		thp_log_err(cd, "%s: dev is null\n", __func__);
		return -EINVAL;
	}

	if (cd->support_ring_feature == 0) {
		thp_log_err(cd, "%s: not support\n", __func__);
		return -EINVAL;
	}
	volume_side = cd->volume_side_status;
	ret = sscanf(buf, "%u,%u", &type, &data);
	if (ret <= 0) {
		thp_log_err(cd, "%s: illegal input\n", __func__);
		return -EINVAL;
	}
	thp_log_info(cd, "%s: type:%u, data:%u\n",
		__func__, type, data);
	switch (type) {
	case RING_FEATURE_MODE:
		cd->volume_side_status = data & VOLUME_SIDE_STATUS_BOTH;
		if (cd->support_ring_setting_switch)
			cd->ring_setting_switch = !!data;
		if (cd->volume_side_status != volume_side)
			thp_set_status(cd, THP_STATUS_VOLUME_SIDE,
				!thp_get_status(cd, THP_STATUS_VOLUME_SIDE));
		break;
	default:
		return -EINVAL;
	}
	return count;
}

static ssize_t thp_ring_setting_config_ctrl_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct thp_core_data *cd = dev_get_drvdata(dev);

	if (!dev || !cd) {
		thp_log_err(cd, "%s: dev or cd is null\n", __func__);
		return -EINVAL;
	}

	return snprintf(buf, PAGE_SIZE - 1, "%u\n",
		cd->volume_side_status);
}

static ssize_t thp_screen_status_switch_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	struct thp_core_data *cd = dev_get_drvdata(dev);
	u32 screen_status = SCREEN_UNFOLD;
	int ret;
	struct thp_cmd_node cmd;

	if (!dev || !cd) {
		thp_log_err(cd, "%s: dev or cd is null\n", __func__);
		return -EINVAL;
	}

	if (!cd->support_screen_switch) {
		thp_log_err(cd, "%s: not support screen switch\n", __func__);
		return -EINVAL;
	}

	ret = sscanf(buf, "%u", &screen_status);
	if (ret <= 0) {
		thp_log_err(cd, "%s: illegal input\n", __func__);
		return -EINVAL;
	}
	thp_log_info(cd, "%s:screen_status:0x%x\n", __func__, screen_status);

	memset(&cmd, 0, sizeof(cmd));
	if (screen_status == SCREEN_FOLDED) {
		cmd.command = TS_SCREEN_FOLD;
		cd->fold_status = TS_SCREEN_FOLD;
	} else if (screen_status == SCREEN_UNFOLD) {
		cmd.command = TS_SCREEN_UNFOLD;
		cd->fold_status = TS_SCREEN_UNFOLD;
	} else {
		cmd.command = TS_INVAILD_CMD;
	}

	cmd.cmd_param.pub_params.dev = cd->thp_dev;
	ret = thp_put_one_cmd(cd, &cmd, 0);
	if (ret)
		thp_log_err(cd, "%s: put cmd error :%d\n", __func__, ret);

	return count;
}

static ssize_t aod_notify_tp_talk_mode_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	struct thp_core_data *cd = dev_get_drvdata(dev);
	unsigned int talk_mode;
	int ret;

	if ((dev == NULL) || (cd == NULL)) {
		thp_log_err(cd, "%s: dev or cd is null\n", __func__);
		return -EINVAL;
	}

	if (!cd->talk_mode_support) {
		thp_log_info(cd, "%s not support\n", __func__);
		return -EINVAL;
	}

	ret = sscanf(buf, "%u", &talk_mode);
	if (ret <= 0) {
		thp_log_err(cd, "%s: illegal input, ret = %d\n", __func__, ret);
		return -EINVAL;
	}

	cd->talk_mode_flag = talk_mode;
	thp_log_info(cd, "%s: update talk mode: %u\n", __func__,
		talk_mode);
	return count;
}
#if (IS_ENABLED(CONFIG_HONOR_THP_QCOM) || IS_ENABLED(CONFIG_HONOR_THP_MTK))
static ssize_t aod_event_report_ctrl_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	struct thp_core_data *cd = dev_get_drvdata(dev);
	struct thp_aod_window window;
	unsigned int status = 0;
	int ret;

	if (!dev || !buf || !cd) {
		thp_log_err(cd, "%s: pointer is null\n", __func__);
		return -EINVAL;
	}
	if (!cd->use_ap_gesture) {
		thp_log_err(cd, "%s not support\n", __func__);
		return -EINVAL;
	}
	ret = sscanf(buf, "%4u %4u %4u %4u %4u", &status, &window.x0,
		&window.y0, &window.x1, &window.y1);
	if (ret <= 0) {
		thp_log_err(cd, "%s: illegal input, ret = %d\n", __func__, ret);
		return -EINVAL;
	}
	cd->aod_event_report_status = status;
	thp_log_info(cd, "%s: update status: %u\n", __func__, status);
	if (!cd->thp_dev->ops->tp_aod_event_ctrl) {
		thp_log_err(cd, "%s: ops is NULL\n", __func__);
		return -EINVAL;
	}
	ret = cd->thp_dev->ops->tp_aod_event_ctrl(cd->thp_dev, status, window);
	if (ret < 0) {
		thp_log_err(cd, "%s: aod event ctrl error, %d\n", __func__, ret);
		return -EINVAL;
	}
	return count;
}

static ssize_t tp_ud_lowpower_ctrl_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	struct thp_core_data *cd = dev_get_drvdata(dev);
	unsigned int status = 0;
	int ret;

	if (!dev || !buf || !cd) {
		thp_log_err(cd, "%s: pointer is null\n", __func__);
		return -EINVAL;
	}
	if (!cd->use_ap_gesture) {
		thp_log_err(cd, "%s not support\n", __func__);
		return -EINVAL;
	}
	if (!cd->lowpower_support) {
		thp_log_err(cd, "%s lowpower not support\n", __func__);
		return -EINVAL;
	}

	ret = sscanf(buf, "%1u", &status);
	if (ret <= 0) {
		thp_log_err(cd, "%s: illegal input, ret = %d\n", __func__, ret);
		return -EINVAL;
	}
	cd->tp_ud_lowpower_status = status;
	thp_log_info(cd, "%s: update lowpower_status: %u\n", __func__, status);
	if (!cd->thp_dev->ops->tp_lowpower_ctrl) {
		thp_log_err(cd, "%s: ops is NULL\n", __func__);
		return -EINVAL;
	}
	ret = cd->thp_dev->ops->tp_lowpower_ctrl(cd->thp_dev, status);
	if (ret < 0) {
		thp_log_err(cd, "%s: lowpower ctrl error, %d\n", __func__, ret);
		return -EINVAL;
	}
	return count;
}

static ssize_t aod_notify_tp_power_status_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	struct thp_core_data *cd = dev_get_drvdata(dev);
	unsigned int status;
	int ret;
	int panel_index = -1;
	struct thp_cmd_node cmd;

	if ((dev == NULL) || (cd == NULL)) {
		thp_log_err(cd, "%s: dev or cd is null\n", __func__);
		return -EINVAL;
	}
	if (!cd->use_aod_power_ctrl_notify) {
		thp_log_err(cd, "%s not support\n", __func__);
		return -EINVAL;
	}
	memset(&cmd, 0, sizeof(cmd));
	mutex_lock(&cd->aod_power_ctrl_mutex);
	if (cd->is_fold_device)
		ret = sscanf(buf, "%4u,%4u", &panel_index, &status);
	else
		ret = sscanf(buf, "%1u", &status);
	if (ret <= 0) {
		thp_log_err(cd, "%s: illegal input, ret = %d\n", __func__, ret);
		return -EINVAL;
	}
	thp_log_info(cd, "%s: update aod_notify_tp_power_status: %u\n", __func__,
		status);
	if (cd->is_fold_device) {
		thp_log_info(cd, "%s: panel_index = %d, fold_status = %d\n", __func__, panel_index, cd->fold_status);
		if (panel_index == POWER_NOTIFY_AOD) {
			if (cd->fold_status == TS_SCREEN_FOLD)
				panel_index = SUB_TOUCH_PANEL;
			if (cd->fold_status == TS_SCREEN_UNFOLD)
				panel_index = MAIN_TOUCH_PANEL;
		}
		if (panel_index == MAIN_TOUCH_PANEL) {
			cd->aod_notify_tp_power_status = status;
			aod_status_notifier(cd, status);
		} else if (panel_index == SUB_TOUCH_PANEL) {
			cd->aod_notify_subpanel_power_status = status;
			cmd.command = AOD_NOTIFY_SUBPANEL_POWER_CTRL;
			cmd.cmd_param.pub_params.power_ctrl = status;
			thp_put_one_cmd(cd, &cmd, NO_SYNC_TIMEOUT);
		} else {
			thp_log_err(cd, "panel index is invaild\n");
		}
	} else {
		cd->aod_notify_tp_power_status = status;
		aod_status_notifier(cd, status);
	}
	mutex_unlock(&cd->aod_power_ctrl_mutex);
	return count;
}

static ssize_t aod_notify_tp_power_status_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct thp_core_data *cd = dev_get_drvdata(dev);

	if ((dev == NULL) || (cd == NULL)) {
		thp_log_err(cd, "%s: dev or cd is null\n", __func__);
		return -EINVAL;
	}
	if (!cd->use_aod_power_ctrl_notify) {
		thp_log_err(cd, "%s not support\n", __func__);
		return -EINVAL;
	}
	return snprintf(buf, PAGE_SIZE - 1, "%u\n",
		cd->aod_notify_tp_power_status);
}

#ifdef CONFIG_HONOR_TRUSTED_TOUCH
static ssize_t trusted_touch_type_show(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct thp_core_data *cd = dev_get_drvdata(dev);
	struct trusted_touch_vm_info *vm_info = cd->vm_info;

	if (vm_info->mem_tag == GH_MEM_NOTIFIER_TAG_TOUCH_PRIMARY) {
		thp_log_info(cd, "%s: primary\n", __func__);
		return snprintf(buf, PAGE_SIZE - 1, "primary");
	} else if (vm_info->mem_tag == GH_MEM_NOTIFIER_TAG_TOUCH_SECONDARY) {
		thp_log_info(cd, "%s: secondary\n", __func__);
		return snprintf(buf, PAGE_SIZE - 1, "secondary");
	} else {
		thp_log_info(cd, "%s: invalid tag for touch type %d\n", __func__, vm_info->mem_tag);
	}

	return 0;
}

static ssize_t thp_trusted_touch_enable_show(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct thp_core_data *cd = dev_get_drvdata(dev);
	if (!cd) {
		thp_log_err(cd, "info is null\n");
		return -EINVAL;
	}
	thp_log_info(cd, "%s: %u\n", __func__, cd->trusted_touch_enabled);

	return scnprintf(buf, PAGE_SIZE, "%d",
			atomic_read(&(cd->trusted_touch_enabled)));
}

static ssize_t thp_trusted_touch_enable_store(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t count)
{
	unsigned long value;
	int err = 0;
	struct thp_core_data *cd = dev_get_drvdata(dev);
	if (!cd) {
		thp_log_err(cd, "info is null\n");
		return -EINVAL;
	}

	thp_log_info(cd, "%s: %u\n", __func__, cd->trusted_touch_enabled);

	if (count > 2)
		return -EINVAL;
	err = kstrtoul(buf, 10, &value);
	if (err != 0)
		return err;

	if (!atomic_read(&(cd->trusted_touch_initialized)))
		return -EIO;

#ifdef CONFIG_ARCH_QTI_VM
	err = thp_handle_trusted_touch_tvm(cd, value);
	if (err) {
		thp_log_err(cd, "Failed to handle trusted touch in tvm\n");
		return -EINVAL;
	}
#else
	err = thp_handle_trusted_touch_pvm(cd, value);
	if (err) {
		thp_log_err(cd, "Failed to handle trusted touch in pvm\n");
		return -EINVAL;
	}
#endif
	err = count;
	return err;
}

#endif  // CONFIG_HONOR_TRUSTED_TOUCH

#endif

static DEVICE_ATTR(thp_status, 0444, thp_status_show, NULL);
static DEVICE_ATTR(touch_chip_info, 0640,
	thp_chip_info_show, NULL);
static DEVICE_ATTR(hostprocessing, 0444, thp_hostprocessing_show, NULL);
static DEVICE_ATTR(loglevel, 0444, thp_loglevel_show, NULL);
static DEVICE_ATTR(charger_state, 0660,
	thp_host_charger_state_show, thp_host_charger_state_store);
static DEVICE_ATTR(roi_data, 0660,
	thp_roi_data_show, thp_roi_data_store);
static DEVICE_ATTR(roi_data_internal, 0400, thp_roi_data_debug_show, NULL);
static DEVICE_ATTR(roi_enable, 0660,
	thp_roi_enable_show, thp_roi_enable_store);
static DEVICE_ATTR(touch_sensitivity, 0660,
	thp_holster_enable_show, thp_holster_enable_store);
static DEVICE_ATTR(touch_glove, 0660,
	thp_glove_enable_show, thp_glove_enable_store);
static DEVICE_ATTR(touch_window, 0660,
	thp_holster_window_show, thp_holster_window_store);
static DEVICE_ATTR(touch_switch, 0660,
	thp_touch_switch_show, thp_touch_switch_store);
static DEVICE_ATTR(udfp_enable, 0660,
	thp_udfp_enable_show, thp_udfp_enable_store);
static DEVICE_ATTR(stylus_wakeup_ctrl, 0660,
	stylus_wakeup_ctrl_show, stylus_wakeup_ctrl_store);
static DEVICE_ATTR(supported_func_indicater, 0400,
	thp_supported_func_indicater_show, NULL);
static DEVICE_ATTR(tui_wake_up_enable, 0660,
	thp_tui_wake_up_enable_show, thp_tui_wake_up_enable_store);
static DEVICE_ATTR(easy_wakeup_gesture, 0600,
	thp_easy_wakeup_gesture_show, thp_easy_wakeup_gesture_store);
static DEVICE_ATTR(wakeup_gesture_enable, 0600,
	thp_wakeup_gesture_enable_show, thp_wakeup_gesture_enable_store);
static DEVICE_ATTR(easy_wakeup_control, 0200, NULL,
	thp_easy_wakeup_control_store);
static DEVICE_ATTR(easy_wakeup_position, 0400, thp_easy_wakeup_position_show,
	NULL);
static DEVICE_ATTR(touch_oem_info, 0640,
	thp_oem_info_show, NULL);
static DEVICE_ATTR(fingerprint_switch_ctrl, 0660,
	thp_fingerprint_switch_ctrl_show, thp_fingerprint_switch_ctrl_store);
static DEVICE_ATTR(ring_switch_ctrl, 0660,
	thp_ring_switch_ctrl_show, thp_ring_switch_ctrl_store);
static DEVICE_ATTR(power_switch_ctrl, 0660,
	thp_power_switch_ctrl_show, thp_power_switch_ctrl_store);
static DEVICE_ATTR(tp_dfx_info, 0660, NULL, thp_dfx_info_store);
static DEVICE_ATTR(aod_touch_switch_ctrl, 0660,
	aod_touch_switch_ctrl_show, aod_touch_switch_ctrl_store);
static DEVICE_ATTR(ring_setting_config_ctrl, 0660,
	thp_ring_setting_config_ctrl_show, thp_ring_setting_config_ctrl_store);
static DEVICE_ATTR(factory_extra_cmd, 0660, NULL,
	thp_factory_extra_cmd_store);
static DEVICE_ATTR(screen_status_switch, 0660, NULL,
	thp_screen_status_switch_store);
#if (IS_ENABLED(CONFIG_HONOR_THP_QCOM) || IS_ENABLED(CONFIG_HONOR_THP_MTK))
static DEVICE_ATTR(aod_event_report_ctrl, 0660, NULL,
	aod_event_report_ctrl_store);
static DEVICE_ATTR(tp_ud_lowpower_ctrl, 0660, NULL, tp_ud_lowpower_ctrl_store);
static DEVICE_ATTR(aod_notify_tp_power_ctrl, 0660,
	aod_notify_tp_power_status_show, aod_notify_tp_power_status_store);

#ifdef CONFIG_HONOR_TRUSTED_TOUCH
static DEVICE_ATTR(trusted_touch_enable, 0660,
	thp_trusted_touch_enable_show, thp_trusted_touch_enable_store);
static DEVICE_ATTR(trusted_touch_type, 0444, trusted_touch_type_show, NULL);
#endif

#endif
static DEVICE_ATTR(aod_notify_tp_talk_mode, 0660, NULL, aod_notify_tp_talk_mode_store);

static struct attribute *thp_ts_attributes[] = {
	&dev_attr_thp_status.attr,
	&dev_attr_touch_chip_info.attr,
	&dev_attr_hostprocessing.attr,
	&dev_attr_loglevel.attr,
#if defined(THP_CHARGER_FB)
	&dev_attr_charger_state.attr,
#endif
	&dev_attr_roi_data.attr,
	&dev_attr_roi_data_internal.attr,
	&dev_attr_roi_enable.attr,
	&dev_attr_touch_sensitivity.attr,
	&dev_attr_touch_glove.attr,
	&dev_attr_touch_window.attr,
	&dev_attr_touch_switch.attr,
	&dev_attr_udfp_enable.attr,
	&dev_attr_supported_func_indicater.attr,
	&dev_attr_tui_wake_up_enable.attr,
	&dev_attr_easy_wakeup_gesture.attr,
	&dev_attr_wakeup_gesture_enable.attr,
	&dev_attr_easy_wakeup_control.attr,
	&dev_attr_easy_wakeup_position.attr,
	&dev_attr_touch_oem_info.attr,
	&dev_attr_stylus_wakeup_ctrl.attr,
	&dev_attr_fingerprint_switch_ctrl.attr,
	&dev_attr_ring_switch_ctrl.attr,
	&dev_attr_power_switch_ctrl.attr,
	&dev_attr_tp_dfx_info.attr,
	&dev_attr_aod_touch_switch_ctrl.attr,
	&dev_attr_ring_setting_config_ctrl.attr,
	&dev_attr_factory_extra_cmd.attr,
	&dev_attr_screen_status_switch.attr,
#if (IS_ENABLED(CONFIG_HONOR_THP_QCOM) || IS_ENABLED(CONFIG_HONOR_THP_MTK))
	&dev_attr_aod_event_report_ctrl.attr,
	&dev_attr_tp_ud_lowpower_ctrl.attr,
	&dev_attr_aod_notify_tp_power_ctrl.attr,
#if IS_ENABLED(CONFIG_HONOR_TRUSTED_TOUCH)
	&dev_attr_trusted_touch_enable.attr,
	&dev_attr_trusted_touch_type.attr,
#endif
#endif
	&dev_attr_aod_notify_tp_talk_mode.attr,
	NULL,
};

static const struct attribute_group thp_ts_attr_group = {
	.attrs = thp_ts_attributes,
};

#if IS_ENABLED(CONFIG_HONOR_TRUSTED_TOUCH)
DEFINE_MUTEX(g_qts_create_mutex);
static int qts_create_sysfs(struct thp_core_data *cd)
{
	int ret = 0;

	thp_log_info(cd, "%s call\n", __func__);
	mutex_lock(&g_qts_create_mutex);
	if (g_qts_kset == NULL) {
		thp_log_info(cd, "%s qts kset create\n", __func__);
		g_qts_kset = kset_create_and_add("qts", NULL, kernel_kobj);
		if (!g_qts_kset) {
			thp_log_err(cd, "qts kset create failed\n");
			mutex_unlock(&g_qts_create_mutex);
			return -ENODEV;
		}
	}
	mutex_unlock(&g_qts_create_mutex);
	if ((cd->multi_panel_index == MAIN_TOUCH_PANEL) ||
			(cd->multi_panel_index == SINGLE_TOUCH_PANEL)) {
		ret = sysfs_create_link(&g_qts_kset->kobj, &cd->thp_platform_dev->dev.kobj,
			"primary");
		if (ret) {
			thp_log_err(cd, "%s: fail create primary link error = %d\n", __func__, ret);
			return -ENODEV;
		}
	} else if (cd->multi_panel_index == SUB_TOUCH_PANEL) {
		ret = sysfs_create_link(&g_qts_kset->kobj, &cd->thp_platform_dev->dev.kobj,
			"secondary");
		if (ret) {
			thp_log_err(cd, "%s: fail create secondary link error = %d\n", __func__, ret);
			return -ENODEV;
		}
	}
	thp_log_info(cd, "%s succeeded\n", __func__);
	return ret;
}
#endif

int thp_init_sysfs(struct thp_core_data *cd)
{
	int rc;
	char *node = NULL;

	if (!cd) {
		thp_log_err(cd, "%s: core data null\n", __func__);
		return -EINVAL;
	}

	if (cd->multi_panel_index == SUB_TOUCH_PANEL) {
		cd->thp_platform_dev = platform_device_alloc("honor_thp1", -1);
	} else {
		cd->thp_platform_dev = platform_device_alloc("honor_thp", -1);
	}
	if (!cd->thp_platform_dev) {
		thp_log_err(cd, "%s: regist platform_device failed\n", __func__);
		return -ENODEV;
	}

	rc = platform_device_add(cd->thp_platform_dev);
	if (rc) {
		thp_log_err(cd, "%s: add platform_device failed\n", __func__);
		platform_device_unregister(cd->thp_platform_dev);
		return -ENODEV;
	}

	rc = sysfs_create_group(&cd->thp_platform_dev->dev.kobj,
			&thp_ts_attr_group);
	if (rc) {
		thp_log_err(cd, "%s:can't create ts's sysfs\n", __func__);
		goto err_create_group;
	}

	if (cd->multi_panel_index != SINGLE_TOUCH_PANEL) {
		node = kzalloc(sizeof(char) * MULTI_PANEL_NODE_BUF_LEN, GFP_KERNEL);
		if (!node) {
			thp_log_err(cd, "%s:node is null\n", __func__);
			rc = -ENOMEM;
			goto err_create_group;
		}
		rc = snprintf(node, MULTI_PANEL_NODE_BUF_LEN, "%s%d",
			SYSFS_TOUCH_PATH, cd->multi_panel_index);
		if (rc < 0) {
			thp_log_err(cd, "%s: snprintf err\n", __func__);
			goto err_create_group;
		}
		rc = sysfs_create_link(NULL, &cd->thp_platform_dev->dev.kobj,
			node);
	} else {
		rc = sysfs_create_link(NULL, &cd->thp_platform_dev->dev.kobj,
			SYSFS_TOUCH_PATH);
	}
	if (rc) {
		thp_log_err(cd, "%s: fail create link error = %d\n", __func__, rc);
		goto err_create_link;
	}
	dev_set_drvdata(&cd->thp_platform_dev->dev, cd);

#if IS_ENABLED(CONFIG_HONOR_TRUSTED_TOUCH)
	rc = qts_create_sysfs(cd);
	if (rc) {
		thp_log_err(cd, "%s:qts_create_sysfs fail rc = %d\n", __func__, rc);
		goto err_create_link;
	}
#endif
	return 0;

err_create_link:
	sysfs_remove_group(&cd->thp_platform_dev->dev.kobj, &thp_ts_attr_group);
err_create_group:
	platform_device_put(cd->thp_platform_dev);
	platform_device_unregister(cd->thp_platform_dev);
	if (node) {
		kfree(node);
		node = NULL;
	}
	return rc;
}


void thp_sysfs_release(struct thp_core_data *cd)
{
	if (!cd) {
		thp_log_err(cd, "%s: core data null\n", __func__);
		return;
	}
	platform_device_put(cd->thp_platform_dev);
	platform_device_unregister(cd->thp_platform_dev);
	sysfs_remove_group(&cd->sdev->dev.kobj, &thp_ts_attr_group);
}
