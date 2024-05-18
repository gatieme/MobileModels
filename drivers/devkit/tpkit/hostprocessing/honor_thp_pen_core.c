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

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/spi/spi.h>
#include <linux/gpio.h>
#include <linux/delay.h>
#include <linux/notifier.h>
#include <linux/fb.h>
#include <linux/list.h>
#include <linux/interrupt.h>
#include <linux/platform_device.h>
#include <linux/delay.h>
#include <linux/uaccess.h>
#include <linux/of_gpio.h>
#include <linux/of.h>
#include <linux/of_irq.h>
#include <linux/regulator/consumer.h>
#include <linux/hwspinlock.h>
#include <linux/kthread.h>
#include "honor_thp.h"

#include "honor_thp_mt_wrapper.h"
#include "honor_thp_attr.h"
#include "hwspinlock_internal.h"

#ifdef CONFIG_INPUTHUB_20
#include "contexthub_recovery.h"
#endif

#ifdef CONFIG_HONOR_PS_SENSOR
#include "ps_sensor.h"
#endif

#ifdef CONFIG_HONOR_SENSORS_2_0
#include "sensor_scp.h"
#endif

#if (!(IS_ENABLED(CONFIG_HONOR_THP_QCOM) || IS_ENABLED(CONFIG_HONOR_THP_MTK)))
#include <honor_platform/sensor/hw_comm_pmic.h>
#endif

#ifdef CONFIG_HONOR_HW_DEV_DCT
#if (IS_ENABLED(CONFIG_HONOR_THP_QCOM) || IS_ENABLED(CONFIG_HONOR_THP_MTK))
#include <hwmanufac/dev_detect/dev_detect.h>
#else
#include <honor_platform/devdetect/hw_dev_dec.h>
#endif
#endif

#if IS_ENABLED(CONFIG_DSM)
#include <dsm/dsm_pub.h>
#endif

#ifndef CONFIG_ARCH_QTI_VM
#include "../include/hwpower/power_event_ne.h"
#endif
#define trace_touch(x...)

extern int  himax_pen_driver_module_init(struct thp_core_data *cd);
extern bool need_work_in_suspend_switch(struct thp_core_data *cd);
static void thp_wakeup_screenon_waitq(struct thp_core_data *cd);
static int thp_pen_put_one_cmd(struct thp_core_data *cd, struct thp_cmd_node *cmd, int timeout);
static void thp_pen_set_irq_status(struct thp_core_data *cd, int status);

struct thp_core_data *g_thp_pen_core;
struct thp_core_data *g_thp_pen_core_sub;
struct dsm_client *dsm_thp_pen_dclient;

#if IS_ENABLED(CONFIG_DSM)
#define THP_CHIP_DMD_REPORT_SIZE 1024
#define THP_DSM_BUFF_SIZE 4096
static struct dsm_dev dsm_thp = {
	.name = "dsm_tphostprocessing",
	.device_name = "TPHOSTPROCESSING",
	.ic_name = "syn",
	.module_name = "NNN",
	.fops = NULL,
	.buff_size = THP_DSM_BUFF_SIZE,
};
#endif

#define PRINTF_ERROR_CODE "printf error\n"
#define THP_PEN_DEVICE_NAME	"honor_thp_pen"
#define THP_PEN_MISC_DEVICE_NAME "thp_pen"
#define RECOVERY_ENTER "1"
static bool recovery_mode = false;

#if defined(CONFIG_LCD_KIT_DRIVER)
static int thp_pen_power_control_notify(struct thp_core_data *cd, enum lcd_kit_ts_pm_type pm_type, int timeout);
static struct thp_core_data *thp_pen_get_core_data(void)
{
	return g_thp_pen_core;
}
#endif
int thp_pen_spi_sync(struct spi_device *spi, struct spi_message *message)
{
	int ret;

	trace_touch(TOUCH_TRACE_SPI, TOUCH_TRACE_FUNC_IN, "thp");
	ret = spi_sync(spi, message);
	trace_touch(TOUCH_TRACE_SPI, TOUCH_TRACE_FUNC_OUT, "thp");

	return ret;
}

static struct thp_core_data *misc_dev_get_core_data(struct miscdevice *dev)
{
	struct thp_core_data *cd = NULL;

	if (dev == NULL) {
		thp_log_err(cd, "%s: miscdevice is NULL\n", __func__);
		return NULL;
	}

	if (g_thp_pen_core && g_thp_pen_core->thp_misc_device) {
		if (dev->name == g_thp_pen_core->thp_misc_device->name)
			return g_thp_pen_core;
	}
	if (g_thp_pen_core_sub && g_thp_pen_core_sub->thp_misc_device) {
		if (dev->name == g_thp_pen_core_sub->thp_misc_device->name)
			return g_thp_pen_core_sub;
	}
	return NULL;
}

static void thp_pen_wake_up_frame_waitq(struct thp_core_data *cd)
{
	cd->frame_waitq_flag = WAITQ_WAKEUP;
	wake_up_interruptible(&(cd->frame_waitq));
}
static int thp_pen_pinctrl_get_init(struct thp_device *tdev);
static int thp_pen_pinctrl_select_normal(struct thp_device *tdev);
#ifndef CONFIG_ARCH_QTI_VM
static int thp_pinctrl_select_lowpower(struct thp_device *tdev);
#endif

#define GET_HWLOCK_FAIL 0
static int thp_pen_bus_lock(struct thp_core_data *cd)
{
	int ret = 0;
	unsigned long time;
	unsigned long timeout;
	struct hwspinlock *hwlock = cd->hwspin_lock;

	mutex_lock(&cd->spi_mutex);
	if (!cd->use_hwlock)
		return 0;

	timeout = jiffies + msecs_to_jiffies(THP_GET_HARDWARE_TIMEOUT);

	do {
		ret = hwlock->bank->ops->trylock(hwlock);
		if (ret == GET_HWLOCK_FAIL) {
			time = jiffies;
			if (time_after(time, timeout)) {
				thp_log_err(cd, "%s:get hardware_mutex timeout\n",
					__func__);
				mutex_unlock(&cd->spi_mutex);
				return -ETIME;
			}
		}
	} while (ret == GET_HWLOCK_FAIL);
	return 0;
}

static void thp_pen_bus_unlock(struct thp_core_data *cd)
{
	struct hwspinlock *hwlock = cd->hwspin_lock;

	mutex_unlock(&cd->spi_mutex);
	if (cd->use_hwlock)
		hwlock->bank->ops->unlock(hwlock);
}

#define QUEUE_IS_FULL 1
#define QUEUE_IS_NOT_FULL 0
static struct thp_queue *thp_pen_queue_init(struct thp_core_data *cd)
{
	int i;
	struct thp_queue *queue = NULL;

	thp_log_info(cd, "%s start\n", __func__);
	if (cd->thp_queue_buf_len > THP_MAX_FRAME_SIZE) {
		thp_log_err(cd, "%s thp queue node len is invalid\n", __func__);
		return NULL;
	}
	thp_log_info(cd, "%s:thp queue node len is %u\n",
		__func__, cd->thp_queue_buf_len);
	queue = kzalloc(sizeof(*queue), GFP_KERNEL);
	if (queue == NULL) {
		thp_log_err(cd, "%s queue malloc failed\n", __func__);
		return NULL;
	}
	cd->queue_data_buf = vzalloc(cd->thp_queue_buf_len * THP_PEN_LIST_MAX_FRAMES);
	if (!cd->queue_data_buf) {
		thp_log_err(cd, "%s queue_data_buf vzalloc failed\n", __func__);
		kfree(queue);
		queue = NULL;
		return NULL;
	}

	for (i = 0; i < THP_PEN_LIST_MAX_FRAMES; i++)
		queue->frame_data[i].buf = cd->queue_data_buf +
			(i * cd->thp_queue_buf_len);

	queue->front = 0;
	queue->tail = 0;
	queue->size = THP_PEN_LIST_MAX_FRAMES;
	queue->flag = QUEUE_IS_NOT_FULL;
	return queue;
}

static bool thp_pen_queue_is_empty(struct thp_core_data *cd, struct thp_queue *queue)
{
	if (queue == NULL) {
		thp_log_err(cd, "%s queue is NULL\n", __func__);
		return false;
	}
	if ((queue->flag == QUEUE_IS_NOT_FULL) &&
		(queue->front == queue->tail))
		return true;
	else
		return false;
}

static bool thp_pen_queue_is_full(struct thp_core_data *cd, struct thp_queue *queue)
{
	if (queue == NULL) {
		thp_log_err(cd, "%s queue is NULL\n", __func__);
		return false;
	}
	if (queue->flag == QUEUE_IS_FULL)
		return true;
	else
		return false;
}

static bool thp_pen_queue_dequeue(struct thp_core_data *cd, struct thp_queue *queue)
{
	if (queue == NULL) {
		thp_log_err(cd, "%s queue is NULL\n", __func__);
		return false;
	}
	thp_log_debug(cd, "%s in\n", __func__);

	if (thp_pen_queue_is_empty(cd, queue)) {
		thp_log_err(cd, "%s queue is empty\n", __func__);
		return false;
	}
	memset(queue->frame_data[queue->front].buf, 0, cd->thp_queue_buf_len);
	memset(&queue->frame_data[queue->front].tv, 0,
		sizeof(queue->frame_data[queue->front].tv));
	queue->front = ((queue->front + 1) < queue->size) ?
		(queue->front + 1) : 0;
	queue->flag = QUEUE_IS_NOT_FULL;
	return true;
}

static bool thp_pen_queue_enqueue(struct thp_core_data *cd, struct thp_queue *queue,
	u8 *read_buf, unsigned int len)
{
	if ((read_buf == NULL) || (queue == NULL)) {
		thp_log_err(cd, "%s read_buf is NULL\n", __func__);
		return false;
	}
	thp_log_debug(cd, "%s in\n", __func__);

	if (thp_pen_queue_is_full(cd, queue)) {
		if (!thp_pen_queue_dequeue(cd, queue)) {
			thp_log_err(cd, "%s dequeue failed\n", __func__);
			return false;
		}
	}
	if (len > cd->thp_queue_buf_len) {
		thp_log_debug(cd, "%s len is too big\n", __func__);
		len = cd->thp_queue_buf_len;
	}
	memcpy(queue->frame_data[queue->tail].buf, read_buf, len);
	get_timestamp(&queue->frame_data[queue->tail].tv);
	queue->tail = ((queue->tail + 1) < queue->size) ? (queue->tail + 1) : 0;
	if (queue->tail == queue->front)
		queue->flag = QUEUE_IS_FULL;
	return true;
}

static struct thp_queue_node *thp_queue_get_head(struct thp_core_data *cd,
	struct thp_queue *queue)
{
	if (queue == NULL) {
		thp_log_err(cd, "%s queue is NULL\n", __func__);
		return NULL;
	}
	if (thp_pen_queue_is_empty(cd, queue)) {
		thp_log_err(cd, "%s queue is empty\n", __func__);
		return NULL;
	}
	return &queue->frame_data[queue->front];
}

static void thp_pen_queue_clear_all(struct thp_core_data *cd, struct thp_queue *queue)
{
	int i;

	if (queue == NULL) {
		thp_log_err(cd, "%s queue is NULL\n", __func__);
		return;
	}

	for (i = 0; i < THP_PEN_LIST_MAX_FRAMES; i++) {
		memset(queue->frame_data[i].buf, 0, cd->thp_queue_buf_len);
		memset(&queue->frame_data[i].tv, 0,
			sizeof(queue->frame_data[i].tv));
	}

	queue->front = 0;
	queue->tail = 0;
	queue->size = THP_PEN_LIST_MAX_FRAMES;
	queue->flag = QUEUE_IS_NOT_FULL;
}

static void thp_pen_queue_free(struct thp_core_data *cd, struct thp_queue *queue)
{
	if (queue == NULL) {
		thp_log_err(cd, "%s queue is NULL\n", __func__);
		return;
	}
	vfree(cd->queue_data_buf);
	cd->queue_data_buf = NULL;
	kfree(queue);
	queue = NULL;
}

static int thp_pen_setup_spi(struct thp_core_data *cd);
static int thp_pen_set_spi3_max_speed(struct thp_core_data *cd, unsigned int speed)
{
	int rc;

	cd->sdev->max_speed_hz = speed;

	thp_log_info(cd, "%s:set max_speed_hz %d\n", __func__, speed);
	rc = thp_pen_bus_lock(cd);
	if (rc) {
		thp_log_err(cd, "%s: get lock failed\n", __func__);
		return rc;
	}
	if (thp_pen_setup_spi(cd)) {
		thp_log_err(cd, "%s: set spi speed fail\n", __func__);
		rc = -EIO;
	}
	thp_pen_bus_unlock(cd);
	return rc;
}

static int thp_wait_frame_waitq(struct thp_core_data *cd)
{
	int t;

	cd->frame_waitq_flag = WAITQ_WAIT;

	/* if not use timeout */
	if (!cd->timeout) {
		t = wait_event_interruptible(cd->frame_waitq,
				(cd->frame_waitq_flag == WAITQ_WAKEUP));
		return 0;
	}

	/* if use timeout */
	t = wait_event_interruptible_timeout(cd->frame_waitq,
			(cd->frame_waitq_flag == WAITQ_WAKEUP),
			msecs_to_jiffies(cd->timeout));
	if (!is_tmo(t))
		return 0;

#if IS_ENABLED(CONFIG_DSM)
	thp_log_err(cd, "%s: wait frame timed out, dmd code:%d\n",
			__func__, DSM_TPHOSTPROCESSING_DEV_STATUS_ERROR_NO);
	if (!cd->suspend_resume_control)
		thp_dmd_report(cd, DSM_TPHOSTPROCESSING_DEV_STATUS_ERROR_NO,
			"%s, wait frame timed out\n", __func__);
#endif

	return -ETIMEDOUT;
}

static void thp_pen_clear_frame_buffer(struct thp_core_data *cd)
{
	struct thp_frame *temp = NULL;
	struct list_head *pos = NULL;
	struct list_head *n = NULL;

	if (cd->use_thp_queue) {
		thp_pen_queue_clear_all(cd, cd->thp_queue);
	} else {
		if (list_empty(&cd->frame_list.list))
			return;
		list_for_each_safe(pos, n, &cd->frame_list.list) {
			temp = list_entry(pos, struct thp_frame, list);
			list_del(pos);
			kfree(temp);
			temp = NULL;
		}
	}
	cd->frame_count = 0;
}

static int thp_pen_spi3_transfer(struct thp_core_data *cd,
	char *tx_buf, char *rx_buf, unsigned int len, unsigned int lock_status)
{
	int rc;
	struct spi_message msg;
	struct spi_device *sdev = cd->sdev;
	struct spi_transfer xfer = {
		.tx_buf = tx_buf,
		.rx_buf = rx_buf,
		.len = len,
#if (!IS_ENABLED(CONFIG_TP_QCOM_8550))
		.delay_usecs = cd->thp_dev->timing_config.spi_transfer_delay_us,
#endif
	};

	if (cd->suspended && (!cd->need_work_in_suspend)) {
		thp_log_err(cd, "%s - suspended\n", __func__);
		return 0;
	}

	spi_message_init(&msg);
	spi_message_add_tail(&xfer, &msg);
	if (lock_status == NEED_LOCK) {
		rc = thp_pen_bus_lock(cd);
		if (rc < 0) {
			thp_log_err(cd, "%s:get lock failed:%d\n", __func__, rc);
			return rc;
		}
	}
	thp_spi_cs_set(cd, GPIO_HIGH);
	rc = thp_pen_spi_sync(sdev, &msg);
	if (lock_status == NEED_LOCK)
		thp_pen_bus_unlock(cd);

	return rc;
}

/*
 * If irq is disabled/enabled, can not disable/enable again
 * disable - status 0; enable - status not 0
 */
static void thp_pen_set_irq_status(struct thp_core_data *cd, int status)
{
	if (!cd) {
		thp_log_err(cd, "%s: cd is nullptr\n", __func__);
		return;
	}
	mutex_lock(&cd->irq_mutex);
	if (cd->irq_enabled != (!!status)) {
		status ? enable_irq(cd->irq) : disable_irq(cd->irq);
		cd->irq_enabled = !!status;
		thp_log_info(cd, "%s: %s irq\n", __func__,
			status ? "enable" : "disable");
	}
	mutex_unlock(&cd->irq_mutex);
};

#ifndef CONFIG_ARCH_QTI_VM
static int thp_suspend(struct thp_core_data *cd)
{
	if (!cd || !(cd->thp_dev)) {
		thp_log_err(cd, "%s: cd or thp_dev is nullptr\n", __func__);
		return 0;
	}
	if (cd->suspended) {
		thp_log_info(cd, "%s: already suspended, return\n", __func__);
		return 0;
	}
	cd->afe_download_status = false;
	cd->invalid_irq_num = 0; /* clear invalid irq count */
	mutex_lock(&cd->suspend_flag_mutex);
	cd->suspended = true;
	mutex_unlock(&cd->suspend_flag_mutex);
	if (need_work_in_suspend_switch(cd)) {
		enable_irq_wake(cd->irq);
		thp_pen_set_irq_status(cd, THP_IRQ_DISABLE);
		cd->thp_dev->ops->suspend(cd->thp_dev);
		thp_pen_set_irq_status(cd, THP_IRQ_ENABLE);
	} else {
		thp_pinctrl_select_lowpower(cd->thp_dev);
		if (cd->open_count)
			thp_pen_set_irq_status(cd, THP_IRQ_DISABLE);
		cd->thp_dev->ops->suspend(cd->thp_dev);
	}
	cd->work_status = SUSPEND_DONE;
	return 0;
}

static int thp_resume(struct thp_core_data *cd)
{
	if (!cd || !(cd->thp_dev)) {
		thp_log_err(cd, "%s: cd or thp_dev is nullptr\n", __func__);
		return 0;
	}
	if (!cd->suspended) {
		thp_log_info(cd, "%s: already resumed, return\n", __func__);
		return 0;
	}

	if (need_work_in_suspend_switch(cd))
		disable_irq_wake(cd->irq);

	cd->work_status = BEFORE_RESUME;

	thp_log_info(cd, "%s: pen\n", __func__);
	cd->thp_dev->ops->resume(cd->thp_dev);

	/* clear rawdata frame buffer list */
	mutex_lock(&cd->mutex_frame);
	thp_pen_clear_frame_buffer(cd);
	mutex_unlock(&cd->mutex_frame);
	thp_pen_pinctrl_select_normal(cd->thp_dev);

	cd->suspended = false;
	cd->work_status = RESUME_DONE;
	return 0;
}
#endif

/*
 * Add some delay before screenoff to avoid quick resume-suspend TP-firmware
 * does not download success but thp have notified afe screenoff.
 * Use 'wait_event_interruptible_timeout' wait THP_AFE_STATUS_SCREEN_ON
 * notify and set enough timeout make sure of TP-firmware download success.
 * This solution will cause suspend be more slowly.
 */
 #if defined(CONFIG_LCD_KIT_DRIVER)
static void thp_delay_before_screenoff(struct thp_core_data *cd)
{
	int rc;
	u32 suspend_delay_ms;

	if (!cd || !(cd->thp_dev)) {
		thp_log_err(cd, "%s: cd is null\n", __func__);
		return;
	}

	suspend_delay_ms = cd->thp_dev->timing_config.early_suspend_delay_ms;
	if ((atomic_read(&(cd->afe_screen_on_waitq_flag)) == WAITQ_WAKEUP) ||
		!suspend_delay_ms) {
		thp_log_info(cd, "%s, do not need wait\n", __func__);
		return;
	}

	thp_log_info(cd, "%s:wait afe screen on complete\n", __func__);
	rc = wait_event_interruptible_timeout(cd->afe_screen_on_waitq,
		(atomic_read(&(cd->afe_screen_on_waitq_flag)) == WAITQ_WAKEUP),
		msecs_to_jiffies(suspend_delay_ms));
	if (rc)
		return;
	/* if timeout and condition not true, rc is 0 need report DMD */
	atomic_set(&(cd->afe_screen_on_waitq_flag), WAITQ_WAKEUP);
#if IS_ENABLED(CONFIG_DSM)
	thp_dmd_report(cd, DSM_TPHOSTPROCESSING_DEV_GESTURE_EXP2,
		"%s, screen on %u ms, but fw not ready\n",
		__func__, suspend_delay_ms);
#endif
	thp_log_info(cd, "%s, screen on %u ms, but fw not ready\n",
		__func__, suspend_delay_ms);
}

static void thp_early_suspend(struct thp_core_data *cd)
{
	thp_log_info(cd, "%s:pen early suspend,%d\n", __func__,
		cd->suspend_resume_waitq_flag);
	/*
	 * to avoid easy_wakeup_info.sleep_mode being changed during suspend,
	 * assign cd->sleep_mode to easy_wakeup_info.sleep_mode once
	 */
	cd->easy_wakeup_info.sleep_mode = cd->sleep_mode;
	/*
	 * TDDI need make sure of firmware download complete,
	 * then lcd send 2810 to screen off,
	 * otherwise gesture mode will enter failed.
	 */
	if (cd->wait_afe_screen_on_support)
		thp_delay_before_screenoff(cd);

	thp_log_info(cd, "%s:pen early suspend\n", __func__);
}

static void thp_after_resume(struct thp_core_data *cd)
{
	thp_log_info(cd, "%s:pen after resume\n", __func__);
}
#endif

#if defined(CONFIG_LCD_KIT_DRIVER)

static int pm_type_switch(struct thp_core_data *cd,
	enum lcd_kit_ts_pm_type pm_type)
{
	switch (pm_type) {
	case TS_EARLY_SUSPEND:
		thp_early_suspend(cd);
		break;

	case TS_SUSPEND_DEVICE:
		thp_log_info(cd, "%s:pen suspend\n", __func__);
		// thp_clean_fingers(cd);
		break;

	case TS_BEFORE_SUSPEND:
		thp_log_info(cd, "%s:pen before suspend\n", __func__);
		thp_suspend(cd);
		break;

	case TS_RESUME_DEVICE:
		thp_log_info(cd, "%s:pen resume\n", __func__);
		thp_resume(cd);
		break;

	case TS_AFTER_RESUME:
		thp_after_resume(cd);
		break;
	case TS_2ND_POWER_OFF:
		if (cd->thp_dev && cd->thp_dev->ops &&
			cd->thp_dev->ops->second_poweroff)
			cd->thp_dev->ops->second_poweroff();
		break;
	default:
		break;
	}

	return 0;
}

int thp_pen_single_power_control_notify(enum lcd_kit_ts_pm_type pm_type, int timeout)
{
	struct thp_core_data *cd = thp_pen_get_core_data();

	return thp_pen_power_control_notify(cd, pm_type, timeout);
}

static int thp_pen_power_control_notify(struct thp_core_data *cd, enum lcd_kit_ts_pm_type pm_type, int timeout)
{
	if (!cd) {
		thp_log_err(cd, "%s: tp is not registered\n", __func__);
		return -ENODEV;
	}
	thp_log_debug(cd, "%s: called by lcdkit, pm_type=%d\n", __func__, pm_type);
	return pm_type_switch(cd, pm_type);
}
#endif

static int thp_pen_open(struct inode *inode, struct file *filp)
{
	int ret;
	struct thp_core_data *cd = misc_dev_get_core_data(filp->private_data);

	thp_log_info(cd, "%s: called\n", __func__);

	if (cd == NULL) {
		thp_log_err(cd, "%s: misc_dev_get_core_data is NULL\n", __func__);
		return -EINVAL;
	}

	mutex_lock(&cd->thp_mutex);
	if (cd->open_count) {
		thp_log_err(cd, "%s: dev have be opened\n", __func__);
		mutex_unlock(&cd->thp_mutex);
		return -EBUSY;
	}

	cd->open_count++;
	mutex_unlock(&cd->thp_mutex);
	cd->reset_flag = 0; /* current isn't in reset status */
	cd->get_frame_block_flag = THP_GET_FRAME_BLOCK;

	cd->frame_size = THP_MAX_FRAME_SIZE;
#ifdef THP_NOVA_ONLY
	cd->frame_size = NT_MAX_FRAME_SIZE;
#endif
	cd->timeout = THP_DEFATULT_TIMEOUT_MS;

	/*
	 * Daemon default is 0
	 * setting to 1 will trigger daemon to init or restore the status
	 */
	__set_bit(THP_STATUS_WINDOW_UPDATE, (unsigned long *)&cd->status);
	__set_bit(THP_STATUS_TOUCH_SCENE, (unsigned long *)&cd->status);

	thp_log_info(cd, "%s: cd->status = 0x%x\n", __func__, cd->status);
	mutex_lock(&cd->mutex_frame);
	thp_pen_clear_frame_buffer(cd);
	mutex_unlock(&cd->mutex_frame);
	/* restore spi config */
	ret = thp_pen_set_spi3_max_speed(cd, cd->spi_config.max_speed_hz);
	if (ret)
		thp_log_err(cd, "%s: thp_pen_set_spi3_max_speed error\n", __func__);

	return 0;
}

static int thp_pen_release(struct inode *inode, struct file *filp)
{
	struct thp_core_data *cd = misc_dev_get_core_data(filp->private_data);

	thp_log_info(cd, "%s: called\n", __func__);

	if (cd == NULL) {
		thp_log_err(cd, "%s: misc_dev_get_core_data is NULL\n", __func__);
		return -EINVAL;
	}

	mutex_lock(&cd->thp_mutex);
	cd->open_count--;
	if (cd->open_count < 0) {
		thp_log_err(cd, "%s: abnormal release\n", __func__);
		cd->open_count = 0;
	}
	mutex_unlock(&cd->thp_mutex);

	thp_pen_wake_up_frame_waitq(cd);
	thp_pen_set_irq_status(cd, THP_IRQ_DISABLE);

	if (cd->locked_by_daemon) {
		thp_log_info(cd, "%s: need unlock here\n", __func__);
		thp_pen_bus_unlock(cd);
		cd->locked_by_daemon = false;
	}

	return 0;
}

static int thp_spi_sync_alloc_mem(struct thp_core_data *cd)
{
	if (cd->spi_sync_rx_buf || cd->spi_sync_tx_buf) {
		thp_log_debug(cd, "%s: has requested memory\n", __func__);
		return 0;
	}

	cd->spi_sync_rx_buf = kzalloc(THP_SYNC_DATA_MAX, GFP_KERNEL);
	if (!cd->spi_sync_rx_buf) {
		thp_log_err(cd, "%s:spi_sync_rx_buf request memory fail\n",
			__func__);
		goto exit;
	}
	cd->spi_sync_tx_buf = kzalloc(THP_SYNC_DATA_MAX, GFP_KERNEL);
	if (!cd->spi_sync_tx_buf) {
		thp_log_err(cd, "%s:spi_sync_tx_buf request memory fail\n",
			__func__);
		kfree(cd->spi_sync_rx_buf);
		cd->spi_sync_rx_buf = NULL;
		goto exit;
	}
	return 0;

exit:
	return -ENOMEM;
}

static unsigned int thp_get_spi_msg_lens(struct thp_core_data *cd,
	struct thp_ioctl_spi_xfer_data *spi_data, unsigned int xfer_num)
{
	int length = 0;
	int i;

	if (!spi_data || !xfer_num || (xfer_num > MAX_SPI_XFER_DATA_NUM)) {
		thp_log_err(cd, "%s:invalid input\n", __func__);
		return 0;
	}
	for (i = 0; i < xfer_num ; i++) {
		if ((spi_data[i].len == 0) ||
			(spi_data[i].len > THP_MAX_FRAME_SIZE)) {
			thp_log_err(cd, "%s:spi_data[i].len invalid\n", __func__);
			return 0;
		}
		length += spi_data[i].len;
		thp_log_debug(cd, "%s: spi_data[i].len = %d\n",
			__func__, spi_data[i].len);
	}
	return length;
}

static long thp_pen_ioctl_multiple_spi_xfer_sync(struct thp_core_data *cd,
	const void __user *data, unsigned int lock_status)
{
	struct thp_ioctl_spi_msg_package ioctl_spi_msg;
	struct thp_ioctl_spi_xfer_data *ioctl_spi_xfer = NULL;
	struct spi_message msg;
	struct spi_transfer *xfer = NULL;
	int rc;
	int i;
	unsigned int current_speed = 0;
	u8 *tx_buf = NULL;
	u8 *rx_buf = NULL;
	unsigned int msg_len;

	memset(&ioctl_spi_msg, 0, sizeof(ioctl_spi_msg));
	if (cd->suspended || (!data)) {
		thp_log_info(cd, "%s:suspended or invalid data,return\n", __func__);
		return -EIO;
	}

	if (copy_from_user(&ioctl_spi_msg, data, sizeof(ioctl_spi_msg))) {
		thp_log_err(cd, "%s:Failed to copy spi data\n", __func__);
		return -EFAULT;
	}
	if ((ioctl_spi_msg.xfer_num > MAX_SPI_XFER_DATA_NUM) ||
		!ioctl_spi_msg.xfer_num) {
		thp_log_err(cd, "xfer_num:%d\n", ioctl_spi_msg.xfer_num);
		return -EINVAL;
	}

	ioctl_spi_xfer = kcalloc(ioctl_spi_msg.xfer_num,
			sizeof(*ioctl_spi_xfer), GFP_KERNEL);
	if (!ioctl_spi_xfer) {
		thp_log_err(cd, "%s:failed alloc memory for spi_xfer_data\n",
			__func__);
		return -EFAULT;
	}
	if (ioctl_spi_msg.xfer_data) {
		if (copy_from_user(ioctl_spi_xfer, ioctl_spi_msg.xfer_data,
			sizeof(*ioctl_spi_xfer) * ioctl_spi_msg.xfer_num)) {
			thp_log_err(cd, "%s:failed copy xfer_data\n", __func__);
			rc = -EINVAL;
			goto exit;
		}
	}
	msg_len = thp_get_spi_msg_lens(cd, ioctl_spi_xfer, ioctl_spi_msg.xfer_num);
	if (msg_len > THP_MAX_FRAME_SIZE || !msg_len) {
		thp_log_err(cd, "%s:invalid msg len :%d\n", __func__, msg_len);
		rc = -EINVAL;
		goto exit;
	}

	xfer = kcalloc(ioctl_spi_msg.xfer_num, sizeof(*xfer), GFP_KERNEL);
	rx_buf = kzalloc(msg_len, GFP_KERNEL);
	tx_buf = kzalloc(msg_len, GFP_KERNEL);
	if (!rx_buf || !tx_buf || !xfer) {
		thp_log_err(cd, "%s:failed alloc buffer\n", __func__);
		rc = -EINVAL;
		goto exit;
	}

	spi_message_init(&msg);
	for (i = 0, msg_len = 0; i < ioctl_spi_msg.xfer_num; i++) {
		if (ioctl_spi_xfer[i].tx) {
			rc = copy_from_user(tx_buf + msg_len,
					ioctl_spi_xfer[i].tx,
					ioctl_spi_xfer[i].len);
			if (rc) {
				thp_log_err(cd, "%s:failed copy tx_buf:%d\n",
					__func__, rc);
				goto exit;
			}
		}
		xfer[i].tx_buf = tx_buf + msg_len;
		xfer[i].rx_buf = rx_buf + msg_len;
		xfer[i].len = ioctl_spi_xfer[i].len;
		xfer[i].cs_change = !!ioctl_spi_xfer[i].cs_change;
#if (!IS_ENABLED(CONFIG_TP_QCOM_8550))
		xfer[i].delay_usecs = ioctl_spi_xfer[i].delay_usecs;
#endif
		thp_log_debug(cd,
			"%s:%d, cs_change=%d,len =%d,delay_usecs=%d\n",
			__func__, i, ioctl_spi_xfer[i].cs_change,
			ioctl_spi_xfer[i].len, ioctl_spi_xfer[i].delay_usecs);
		spi_message_add_tail(&xfer[i], &msg);
		msg_len += ioctl_spi_xfer[i].len;
	}
	if (lock_status == NEED_LOCK) {
		rc = thp_pen_bus_lock(cd);
		if (rc) {
			thp_log_info(cd, "%s:failed get lock:%d", __func__, rc);
			goto exit;
		}
	}

	if (ioctl_spi_msg.speed_hz != 0) {
		thp_log_debug(cd, "%s change to 3.5k-> speed =%d\n",
			__func__, ioctl_spi_msg.speed_hz);
		current_speed = cd->sdev->max_speed_hz;
		cd->sdev->max_speed_hz = ioctl_spi_msg.speed_hz;
		rc = thp_pen_setup_spi(cd);
		if (rc) {
			thp_log_err(cd, "%s:set max speed failed rc:%d",
				__func__, rc);
			if (lock_status == NEED_LOCK)
				thp_pen_bus_unlock(cd);
			goto exit;
		}
	}

	rc = thp_pen_spi_sync(cd->sdev, &msg);
	if (rc) {
		thp_log_err(cd, "%s:failed sync msg:%d", __func__, rc);
		if (lock_status == NEED_LOCK)
			thp_pen_bus_unlock(cd);
		goto exit;
	}
	if (ioctl_spi_msg.speed_hz != 0) {
		thp_log_debug(cd, "%s current_speed-> %d\n",
			__func__, current_speed);
		cd->sdev->max_speed_hz = current_speed;
		rc = thp_pen_setup_spi(cd);
		if (rc) {
			thp_log_err(cd, "%s:set max speed failed rc:%d",
				__func__, rc);
			if (lock_status == NEED_LOCK)
				thp_pen_bus_unlock(cd);
			goto exit;
		}
	}
	if (lock_status == NEED_LOCK)
		thp_pen_bus_unlock(cd);

	for (i = 0, msg_len = 0; i < ioctl_spi_msg.xfer_num; i++) {
		if (ioctl_spi_xfer[i].rx) {
			rc = copy_to_user(ioctl_spi_xfer[i].rx,
					rx_buf + msg_len,
					ioctl_spi_xfer[i].len);
			if (rc) {
				thp_log_err(cd, "%s:copy to rx buff fail:%d",
					__func__, rc);
				goto exit;
			}
		}
		msg_len += ioctl_spi_xfer[i].len;
	}
exit:
	kfree(ioctl_spi_xfer);
	kfree(xfer);
	kfree(rx_buf);
	kfree(tx_buf);
	return rc;
}

static long thp_pen_ioctl_spi_sync(struct thp_core_data *cd, const void __user *data,
	unsigned int lock_status)
{
	struct thp_ioctl_spi_sync_data sync_data;
	struct thp_ioctl_spi_sync_data_compat sync_data_compat;
	int rc = 0;
	u8 *tx_buf = NULL;
	u8 *rx_buf = NULL;

	thp_log_debug(cd, "%s: called\n", __func__);
	memset(&sync_data, 0, sizeof(sync_data));
	memset(&sync_data_compat, 0, sizeof(sync_data_compat));

	if (cd->suspended && (!cd->need_work_in_suspend)) {
		thp_log_info(cd, "%s suspended return!\n", __func__);
		return 0;
	}

	if (!data) {
		thp_log_err(cd, "%s: input parameter null\n", __func__);
		return -EINVAL;
	}

	if (cd->compat_flag == true) {
		if (copy_from_user(&sync_data_compat, data,
			sizeof(sync_data_compat))) {
			thp_log_err(cd, "Failed to copy_from_user\n");
			return -EFAULT;
		}
		sync_data.rx = compat_ptr(sync_data_compat.rx);
		sync_data.tx = compat_ptr(sync_data_compat.tx);
		sync_data.size = sync_data_compat.size;
	} else {
		if (copy_from_user(&sync_data, data,
			sizeof(sync_data))) {
			thp_log_err(cd, "Failed to copy_from_user\n");
			return -EFAULT;
		}
	}

	if (sync_data.size > THP_SYNC_DATA_MAX) {
		thp_log_err(cd, "sync_data.size out of range\n");
		return -EINVAL;
	}

	if (cd->need_huge_memory_in_spi) {
		rc = thp_spi_sync_alloc_mem(cd);
		if (!rc) {
			rx_buf = cd->spi_sync_rx_buf;
			tx_buf = cd->spi_sync_tx_buf;
		} else {
			thp_log_err(cd, "%s:buf request memory fail\n", __func__);
			goto exit;
		}
	} else {
		rx_buf = kzalloc(sync_data.size, GFP_KERNEL);
		tx_buf = kzalloc(sync_data.size, GFP_KERNEL);
		if (!rx_buf || !tx_buf) {
			thp_log_err(cd,
				"%s:buf request memory fail,sync_data.size = %d\n",
				__func__, sync_data.size);
			goto exit;
		}
	}
	rc = copy_from_user(tx_buf, sync_data.tx, sync_data.size);
	if (rc) {
		thp_log_err(cd, "%s:copy in buff fail\n", __func__);
		goto exit;
	}
	if (lock_status == NEED_LOCK) {
		if (cd->thp_dev->ops->spi_transfer)
			rc = cd->thp_dev->ops->spi_transfer(tx_buf,
				rx_buf, sync_data.size);
		else
			rc = thp_pen_spi3_transfer(cd, tx_buf, rx_buf,
				sync_data.size, lock_status);
	} else {
		rc = thp_pen_spi3_transfer(cd, tx_buf, rx_buf,
			sync_data.size, lock_status);
	}
	if (rc) {
		thp_log_err(cd, "%s: transfer error, ret = %d\n", __func__, rc);
		goto exit;
	}

	if (sync_data.rx) {
		rc = copy_to_user(sync_data.rx, rx_buf, sync_data.size);
		if (rc) {
			thp_log_err(cd, "%s:copy out buff fail\n", __func__);
			goto exit;
		}
	}

exit:
	if (!cd->need_huge_memory_in_spi) {
		kfree(rx_buf);
		rx_buf = NULL;

		kfree(tx_buf);
		tx_buf = NULL;
	}
	return rc;
}

static long thp_pen_ioctl_finish_notify(struct thp_core_data *cd, unsigned long arg)
{
	unsigned long event_type = arg;
	int rc;
	struct thp_device_ops *ops = cd->thp_dev->ops;

	thp_log_info(cd, "%s: called\n", __func__);
	switch (event_type) {
	case THP_AFE_NOTIFY_FW_UPDATE:
		rc = ops->afe_notify ?
			ops->afe_notify(cd->thp_dev, event_type) : 0;
		break;
	default:
		thp_log_err(cd, "%s: illegal event type\n", __func__);
		rc = -EINVAL;
	}
	return rc;
}

static long thp_pen_ioctl_get_frame_count(struct thp_core_data *cd, unsigned long arg)
{
	u32 __user *frame_cnt = (u32 *)arg;

	if (cd->frame_count)
		thp_log_info(cd, "%s:frame_cnt=%d\n", __func__, cd->frame_count);

	if (frame_cnt == NULL) {
		thp_log_err(cd, "%s: input parameter null\n", __func__);
		return -EINVAL;
	}

	if (copy_to_user(frame_cnt, &cd->frame_count, sizeof(u32))) {
		thp_log_err(cd, "%s:copy frame_cnt failed\n", __func__);
		return -EFAULT;
	}

	return 0;
}

static long thp_pen_ioctl_clear_frame_buffer(struct thp_core_data *cd)
{
	if (cd->frame_count == 0)
		return 0;

	mutex_lock(&cd->mutex_frame);
	thp_pen_clear_frame_buffer(cd);
	mutex_unlock(&cd->mutex_frame);
	return 0;
}

static long thp_pen_get_frame_from_thp_queue(struct thp_core_data *cd,
	struct thp_ioctl_get_frame_data *data)
{
	struct thp_queue_node *temp_frame = NULL;
	long rc = 0;

	if (data->size > cd->thp_queue_buf_len) {
		thp_log_debug(cd, "%s data size too big, set to %u\n",
			__func__, cd->thp_queue_buf_len);
		data->size = cd->thp_queue_buf_len;
	}
	cd->frame_size = data->size;
	mutex_lock(&cd->suspend_flag_mutex);
	if (cd->suspended && (!cd->need_work_in_suspend)) {
		thp_log_info(cd, "%s: drv suspended\n", __func__);
		mutex_unlock(&cd->suspend_flag_mutex);
		return -EINVAL;
	}
	thp_pen_set_irq_status(cd, THP_IRQ_ENABLE);
	mutex_unlock(&cd->suspend_flag_mutex);
	if (thp_pen_queue_is_empty(cd, cd->thp_queue) &&
		cd->get_frame_block_flag) {
		if (thp_wait_frame_waitq(cd))
			rc = -ETIMEDOUT;
	}
	mutex_lock(&cd->mutex_frame);
	if (thp_pen_queue_is_empty(cd, cd->thp_queue) == false) {
		temp_frame = thp_queue_get_head(cd, cd->thp_queue);
		if (temp_frame == NULL) {
			thp_log_err(cd, "Failed to temp_frame is NULL\n");
			rc = -EFAULT;
			goto out;
		}
		if (data->buf == NULL) {
			thp_log_err(cd, "Failed to data buf is NULL\n");
			rc = -EFAULT;
			goto out;
		}
		if (copy_to_user(data->buf, temp_frame->buf,
			cd->frame_size)) {
			thp_log_err(cd, "Failed to copy_to_user\n");
			rc = -EFAULT;
			goto out;
		}
		if (data->tv == NULL) {
			thp_log_err(cd, "Failed to data tv is NULL\n");
			rc = -EFAULT;
			goto out;
		}
		if (copy_to_user(data->tv, &(temp_frame->tv),
			sizeof(temp_frame->tv))) {
			thp_log_err(cd, "Failed to copy_to_user tv\n");
			rc = -EFAULT;
			goto out;
		}
		if (!thp_pen_queue_dequeue(cd, cd->thp_queue))
			thp_log_err(cd, "%s queue remove failed\n", __func__);
		temp_frame = NULL;
		cd->frame_count--;
		rc = 0;
	} else {
		thp_log_err(cd, "%s:no frame\n", __func__);
		/*
		 * When wait timeout, try to get data.
		 * If timeout and no data, return -ETIMEDOUT
		 */
		if (rc != -ETIMEDOUT)
			rc = -ENODATA;
	}
out:
	mutex_unlock(&cd->mutex_frame);
	trace_touch(TOUCH_TRACE_GET_FRAME, TOUCH_TRACE_FUNC_OUT,
		rc ? "no frame" : "with frame");
	return rc;
}

static long thp_pen_ioctl_get_frame(struct thp_core_data *cd, unsigned long arg, unsigned int f_flag)
{
	struct thp_ioctl_get_frame_data data;
	struct thp_ioctl_get_frame_data_compat data_compat;
	void __user *argp = (void __user *)arg;
	long rc = 0;

	memset(&data, 0, sizeof(data));
	memset(&data_compat, 0, sizeof(data_compat));
	trace_touch(TOUCH_TRACE_GET_FRAME, TOUCH_TRACE_FUNC_IN, "thp");

	if (!arg) {
		thp_log_err(cd, "%s: input parameter null\n", __func__);
		return -EINVAL;
	}
	if (cd->suspended && (!cd->need_work_in_suspend)) {
		thp_log_debug(cd, "%s: drv suspended\n", __func__);
		return -ETIMEDOUT;
	}

	if (cd->compat_flag == true) {
		if (copy_from_user(&data_compat, argp,
			sizeof(data_compat))) {
			thp_log_err(cd, "Failed to copy_from_user\n");
			return -EFAULT;
		}
		data.buf = compat_ptr(data_compat.buf);
		data.tv = compat_ptr(data_compat.tv);
		data.size = data_compat.size;
	} else {
		if (copy_from_user(&data, argp,
			sizeof(data))) {
			thp_log_err(cd, "Failed to copy_from_user\n");
			return -EFAULT;
		}
	}

	if (data.buf == 0 || data.size == 0 ||
		data.size > THP_MAX_FRAME_SIZE || data.tv == 0) {
		thp_log_err(cd, "%s:input buf invalid\n", __func__);
		return -EINVAL;
	}
	if (cd->use_thp_queue)
		return thp_pen_get_frame_from_thp_queue(cd, &data);

	cd->frame_size = data.size;
	mutex_lock(&cd->suspend_flag_mutex);
	if (cd->suspended && (!cd->need_work_in_suspend)) {
		thp_log_info(cd, "%s: drv suspended\n", __func__);
		mutex_unlock(&cd->suspend_flag_mutex);
		return -EINVAL;
	}
	thp_pen_set_irq_status(cd, THP_IRQ_ENABLE);
	mutex_unlock(&cd->suspend_flag_mutex);
	if (list_empty(&cd->frame_list.list) && cd->get_frame_block_flag) {
		if (thp_wait_frame_waitq(cd))
			rc = -ETIMEDOUT;
	}

	mutex_lock(&cd->mutex_frame);
	if (!list_empty(&cd->frame_list.list)) {
		struct thp_frame *temp;

		temp = list_first_entry(&cd->frame_list.list,
				struct thp_frame, list);
		if (data.buf == NULL) {
			thp_log_err(cd, "Failed to copy_to_user()\n");
			rc = -EFAULT;
			goto out;
		}
		if (copy_to_user(data.buf, temp->frame, cd->frame_size)) {
			thp_log_err(cd, "Failed to copy_to_user()\n");
			rc = -EFAULT;
			goto out;
		}

		if (data.tv == NULL) {
			thp_log_err(cd, "Failed to copy_to_user()\n");
			rc = -EFAULT;
			goto out;
		}
		if (copy_to_user(data.tv, &(temp->tv),
					sizeof(struct timeval))) {
			thp_log_err(cd, "Failed to copy_to_user()\n");
			rc = -EFAULT;
			goto out;
		}

		list_del(&temp->list);
		kfree(temp);
		cd->frame_count--;
		rc = 0;
	} else {
		thp_log_err(cd, "%s:no frame\n", __func__);
		/*
		 * When wait timeout, try to get data.
		 * If timeout and no data, return -ETIMEDOUT
		 */
		if (rc != -ETIMEDOUT)
			rc = -ENODATA;
	}
out:
	mutex_unlock(&cd->mutex_frame);
	trace_touch(TOUCH_TRACE_GET_FRAME, TOUCH_TRACE_FUNC_OUT,
		rc ? "no frame" : "with frame");
	return rc;
}

static long thp_ioctl_reset(struct thp_core_data *cd, unsigned long reset)
{
	thp_log_info(cd, "%s:set reset status %lu\n", __func__, reset);

	gpio_set_value(cd->gpios.rst_gpio, !!reset);

	if ((!!reset) && (cd->send_bt_status_to_fw) &&
		(cd->support_dual_chip_arch) &&
		(!cd->enter_stylus3_mmi_test)) {
		if (cd->thp_dev->ops->bt_handler(cd->thp_dev, true))
			thp_log_err(cd, "ioctl reset send bt status fail\n");
	}
	cd->frame_waitq_flag = WAITQ_WAIT;
	cd->reset_flag = !reset;

	return 0;
}


static long thp_ioctl_hw_lock_status(struct thp_core_data *cd, unsigned long arg)
{
	thp_log_info(cd, "%s: set hw lock status %lu\n", __func__, arg);
	if (arg) {
		if (thp_pen_bus_lock(cd)) {
			thp_log_err(cd, "%s: get lock failed\n", __func__);
			return -ETIME;
		}
		cd->locked_by_daemon = true;
	} else {
		thp_pen_bus_unlock(cd);
		cd->locked_by_daemon = false;
	}
	return 0;
}

static long thp_pen_ioctl_set_timeout(struct thp_core_data *cd, unsigned long arg)
{
	unsigned int timeout_ms = min_t(unsigned int, arg, THP_WAIT_MAX_TIME);


	thp_log_info(cd, "set wait time %d ms.(current %dms)\n",
		timeout_ms, cd->timeout);

	if (timeout_ms != cd->timeout) {
		cd->timeout = timeout_ms;
		thp_pen_wake_up_frame_waitq(cd);
	}

	return 0;
}

static long thp_pen_ioctl_set_block(struct thp_core_data *cd, unsigned long arg)
{
	unsigned int block_flag = arg;

	if (block_flag)
		cd->get_frame_block_flag = THP_GET_FRAME_BLOCK;
	else
		cd->get_frame_block_flag = THP_GET_FRAME_NONBLOCK;

	thp_log_info(cd, "%s:set block %d\n", __func__, block_flag);

	thp_pen_wake_up_frame_waitq(cd);
	return 0;
}


static long thp_pen_ioctl_set_irq(struct thp_core_data *cd, unsigned long arg)
{
	unsigned int irq_en = (unsigned int)arg;

	mutex_lock(&cd->suspend_flag_mutex);
	if (cd->suspended && (!cd->need_work_in_suspend)) {
		thp_log_info(cd, "%s: drv suspended\n", __func__);
		mutex_unlock(&cd->suspend_flag_mutex);
		return -EINVAL;
	}
	thp_pen_set_irq_status(cd, irq_en);
	mutex_unlock(&cd->suspend_flag_mutex);
	return 0;
}

static long thp_ioctl_get_irq_gpio_value(struct thp_core_data *cd, unsigned long arg)
{
	u32 __user *out_value = (u32 *)arg;
	u32 value;

	value = gpio_get_value(cd->gpios.irq_gpio);
	if (copy_to_user(out_value, &value, sizeof(u32))) {
		thp_log_err(cd, "%s:copy value fail\n", __func__);
		return -EFAULT;
	}
	return 0;
}

static long thp_ioctl_set_spi_speed(struct thp_core_data *cd, unsigned long arg)
{
	unsigned long max_speed_hz = arg;
	int rc;

	if (max_speed_hz == cd->sdev->max_speed_hz)
		return 0;
	rc = thp_pen_set_spi3_max_speed(cd, max_speed_hz);
	if (rc)
		thp_log_err(cd, "%s: failed to set spi speed\n", __func__);
	return rc;
}

static long thp_ioctl_spi_sync_ssl_bl(struct thp_core_data *cd, const void __user *data)
{
	struct thp_ioctl_spi_sync_data sync_data;
	int rc = 0;
	u8 *tx_buf = NULL;
	u8 *rx_buf = NULL;

	memset(&sync_data, 0, sizeof(sync_data));
	thp_log_debug(cd, "%s: called\n", __func__);

	if (!data) {
		thp_log_err(cd, "%s: data null\n", __func__);
		return -EINVAL;
	}
	if (cd == NULL) {
		thp_log_err(cd, "%s: thp get core data err\n", __func__);
		return -EINVAL;
	}
	if (cd->suspended)
		return 0;

	if (copy_from_user(&sync_data, data,
				sizeof(struct thp_ioctl_spi_sync_data))) {
		thp_log_err(cd, "Failed to copy_from_user()\n");
		return -EFAULT;
	}

	if (sync_data.size > THP_SYNC_DATA_MAX || 0 == sync_data.size) {
		thp_log_err(cd, "sync_data.size out of range\n");
		return -EINVAL;
	}

	rx_buf = kzalloc(sync_data.size, GFP_KERNEL);
	tx_buf = kzalloc(sync_data.size, GFP_KERNEL);
	if (!rx_buf || !tx_buf) {
		thp_log_err(cd, "%s:buf request memory fail,sync_data.size = %d\n",
			__func__, sync_data.size);
		goto exit;
	}

	if (sync_data.tx) {
		rc = copy_from_user(tx_buf, sync_data.tx, sync_data.size);
		if (rc) {
			thp_log_err(cd, "%s:copy in buff fail\n", __func__);
			goto exit;
		}
	}

	if (cd) {
		if (cd->thp_dev->ops->spi_transfer_one_byte_bootloader)
			rc = cd->thp_dev->ops->spi_transfer_one_byte_bootloader(
				cd->thp_dev, tx_buf, rx_buf, sync_data.size);
		else
			rc = -EINVAL;
		if (rc) {
			thp_log_err(cd, "%s: transfer error, ret = %d\n",
				__func__, rc);
			goto exit;
		}
	}

	if (sync_data.rx) {
		rc = copy_to_user(sync_data.rx, rx_buf, sync_data.size);
		if (rc) {
			thp_log_err(cd, "%s:copy out buff fail\n", __func__);
			goto exit;
		}
	}

exit:

	kfree(rx_buf);
	kfree(tx_buf);

	return rc;
}

static void thp_wakeup_screenon_waitq(struct thp_core_data *cd)
{
	if (!cd) {
		thp_log_err(cd, "%s: cd is null\n", __func__);
		return;
	}

	if (atomic_read(&(cd->afe_screen_on_waitq_flag)) != WAITQ_WAKEUP) {
		atomic_set(&(cd->afe_screen_on_waitq_flag), WAITQ_WAKEUP);
		wake_up_interruptible(&(cd->afe_screen_on_waitq));
	} else {
		thp_log_info(cd, "afe set status screen on have done\n");
	}
}

static long thp_ioctl_set_afe_status(struct thp_core_data *cd, const void __user *data)
{
	int rc = 0;
	struct thp_ioctl_set_afe_status set_afe_status;

	thp_log_info(cd, "%s: called\n", __func__);
	if (!data) {
		thp_log_err(cd, "%s: data null\n", __func__);
		return -EINVAL;
	}
	if (copy_from_user(&set_afe_status, data,
				sizeof(struct thp_ioctl_set_afe_status))) {
		thp_log_err(cd, "Failed to copy_from_user()\n");
		return -EFAULT;
	}
	thp_log_info(cd, "%s ->%d,%d,%d\n", __func__, set_afe_status.type,
		set_afe_status.status, set_afe_status.parameter);

	switch (set_afe_status.type) {
	case THP_AFE_STATUS_FW_UPDATE:
		if (cd->thp_dev->ops->set_fw_update_mode != NULL)
			rc = cd->thp_dev->ops->set_fw_update_mode(cd->thp_dev,
				set_afe_status);
		else
			rc = -EINVAL;
		if (!rc) {
			if (set_afe_status.parameter == NORMAL_WORK_MODE) {
				cd->is_fw_update = 0;
			} else if (set_afe_status.parameter ==
						FW_UPDATE_MODE) {
				cd->is_fw_update = 1;
			} else {
				thp_log_err(cd, "%s->error mode\n",
					__func__);
				rc = -EINVAL;
			}
			thp_log_info(cd, "%s call is_fw_updating=%d\n",
				__func__, cd->is_fw_update);
		}
		break;
	case THP_AFE_STATUS_SCREEN_ON:
		if (cd->wait_afe_screen_on_support)
			thp_wakeup_screenon_waitq(cd);
		if (cd->lcd_need_get_afe_status &&
			(set_afe_status.status == 1)) {
			get_timestamp(&cd->afe_status_record_tv);
			cd->afe_download_status = true;
		}
		break;
	default:
		thp_log_err(cd, "%s: illegal type\n", __func__);
		rc = -EINVAL;
		break;
	}
	return rc;
}

static long thp_ioctl_get_work_status(struct thp_core_data *cd, unsigned long arg)
{
	u32 __user *work_status = (u32 *)(uintptr_t)arg;
	u32 status;

	if (cd == NULL) {
		thp_log_err(cd, "%s: thp cord data null\n", __func__);
		return -EINVAL;
	}
	if (work_status == NULL) {
		thp_log_err(cd, "%s: input parameter null\n", __func__);
		return -EINVAL;
	}
	if (cd->suspended == true)
		status = THP_WORK_STATUS_SUSPENDED;
	else
		status = THP_WORK_STATUS_RESUMED;

	if (copy_to_user(work_status, &status, sizeof(u32))) {
		thp_log_err(cd, "%s:get wort_status failed\n", __func__);
		return -EFAULT;
	}

	return 0;
}

static long thp_ioctl_set_resume_status(struct thp_core_data *cd, unsigned long arg)
{
	unsigned long status = arg;

	thp_log_info(cd, "%s:set resume status %lu\n", __func__, status);
	switch (status) {
	case THP_AFE_NOTIFY_RESUME_FINISH:
		if (cd->wait_afe_screen_on_support) {
			thp_log_info(cd, "%s: afe notify resume status\n", __func__);
			thp_wakeup_screenon_waitq(cd);
		}
		break;
	default:
		thp_log_err(cd, "%s: illegal type\n", __func__);
		break;
	}
	return 0;
}

static long thp_pen_ioctl(struct file *filp, unsigned int cmd,
	unsigned long arg)
{
	long ret;
	struct thp_core_data *cd = misc_dev_get_core_data(filp->private_data);

	if (cd == NULL) {
		thp_log_err(cd, "%s: misc_dev_get_core_data is NULL\n", __func__);
		return -EINVAL;
	}
	switch (cmd) {
	case THP_IOCTL_CMD_GET_FRAME_COMPAT:
	case THP_IOCTL_CMD_GET_FRAME:
		ret = thp_pen_ioctl_get_frame(cd, arg, filp->f_flags);
		break;

	case THP_IOCTL_CMD_RESET:
		ret = thp_ioctl_reset(cd, arg);
		break;

	case THP_IOCTL_CMD_SET_TIMEOUT:
		ret = thp_pen_ioctl_set_timeout(cd, arg);
		break;

	case THP_IOCTL_CMD_SPI_SYNC_COMPAT:
	case THP_IOCTL_CMD_SPI_SYNC:
		ret = thp_pen_ioctl_spi_sync(cd, (void __user *)arg, NEED_LOCK);
		break;

	case THP_IOCTL_CMD_FINISH_NOTIFY:
		ret = thp_pen_ioctl_finish_notify(cd, arg);
		break;
	case THP_IOCTL_CMD_SET_BLOCK:
		ret = thp_pen_ioctl_set_block(cd, arg);
		break;

	case THP_IOCTL_CMD_SET_IRQ:
		ret = thp_pen_ioctl_set_irq(cd, arg);
		break;

	case THP_IOCTL_CMD_GET_FRAME_COUNT:
		ret = thp_pen_ioctl_get_frame_count(cd, arg);
		break;
	case THP_IOCTL_CMD_CLEAR_FRAME_BUFFER:
		ret = thp_pen_ioctl_clear_frame_buffer(cd);
		break;

	case THP_IOCTL_CMD_GET_IRQ_GPIO_VALUE:
		ret = thp_ioctl_get_irq_gpio_value(cd, arg);
		break;

	case THP_IOCTL_CMD_SET_SPI_SPEED:
		ret = thp_ioctl_set_spi_speed(cd, arg);
		break;
	case THP_IOCTL_CMD_SPI_SYNC_SSL_BL:
		ret = thp_ioctl_spi_sync_ssl_bl(cd, (void __user *) arg);
		break;
	case THP_IOCTL_CMD_SET_AFE_STATUS:
		ret = thp_ioctl_set_afe_status(cd, (void __user *)arg);
		break;
	case THP_IOCTL_CMD_SET_RESUME_STATUS:
		ret = thp_ioctl_set_resume_status(cd, arg);
		break;
	case THP_IOCTL_CMD_MUILTIPLE_SPI_XFRE_SYNC:
		ret = thp_pen_ioctl_multiple_spi_xfer_sync(cd, (void __user *)arg,
			NEED_LOCK);
		break;
	case THP_IOCTL_CMD_HW_LOCK:
		ret = thp_ioctl_hw_lock_status(cd, arg);
		break;
	case THP_IOCTL_CMD_SPI_SYNC_NO_LOCK:
		ret = thp_pen_ioctl_spi_sync(cd, (void __user *)arg, DONOT_NEED_LOCK);
		break;
	case THP_IOCTL_CMD_MUILTIPLE_SPI_XFRE_SYNC_NO_LOCK:
		ret = thp_pen_ioctl_multiple_spi_xfer_sync(cd, (void __user *)arg,
			DONOT_NEED_LOCK);
		break;
	case THP_IOCTL_CMD_GET_WORK_STATUS:
		ret = thp_ioctl_get_work_status(cd, arg);
		break;
	default:
		thp_log_err(cd, "%s: pen cmd unknown, cmd = 0x%x\n", __func__, cmd);
		ret = 0;
	}

	return ret;
}

static long thp_pen_compat_ioctl(struct file *filp, unsigned int cmd,
	unsigned long arg)
{
	long ret;
	struct thp_core_data *cd = misc_dev_get_core_data(filp->private_data);

	if (cd == NULL) {
		thp_log_err(cd, "%s: misc_dev_get_core_data is NULL\n", __func__);
		return -EINVAL;
	}

	cd->compat_flag = true;
	ret = thp_pen_ioctl(filp, cmd, arg);
	if (ret)
		thp_log_err(cd, "%s: ioctl err %ld\n", __func__, ret);

	return ret;
}


static const struct file_operations g_thp_pen_fops = {
	.owner = THIS_MODULE,
	.open = thp_pen_open,
	.release = thp_pen_release,
	.unlocked_ioctl = thp_pen_ioctl,
	.compat_ioctl = thp_pen_compat_ioctl,
};

static void thp_pen_copy_frame_to_thp_queue(struct thp_core_data *cd)
{
	static int pre_frame_count = -1;

	mutex_lock(&(cd->mutex_frame));
	/* check for max limit */
	if (cd->frame_count >= THP_PEN_LIST_MAX_FRAMES) {
		if (!thp_pen_queue_dequeue(cd, cd->thp_queue))
			thp_log_err(cd, "%s queue remove failed\n", __func__);
		pre_frame_count = cd->frame_count;
		cd->frame_count--;
	} else if (pre_frame_count >= THP_PEN_LIST_MAX_FRAMES) {
		pre_frame_count = cd->frame_count;
	}

	if (!thp_pen_queue_enqueue(cd, cd->thp_queue, cd->frame_read_buf,
		cd->frame_size))
		thp_log_err(cd, "%s queue insert failed\n", __func__);
	cd->frame_count++;
	mutex_unlock(&(cd->mutex_frame));
}

static void thp_pen_copy_frame(struct thp_core_data *cd)
{
	struct thp_frame *temp = NULL;
	static int pre_frame_count = -1;
	unsigned long len;

	mutex_lock(&(cd->mutex_frame));

	/* check for max limit */
	if (cd->frame_count >= THP_PEN_LIST_MAX_FRAMES) {
		if (cd->frame_count != pre_frame_count)
			thp_log_err(cd, "pen frame buf full start,frame_count:%d\n",
				cd->frame_count);

		temp = list_first_entry(&cd->frame_list.list,
				struct thp_frame, list);
		list_del(&temp->list);
		kfree(temp);
		pre_frame_count = cd->frame_count;
		cd->frame_count--;
	} else if (pre_frame_count >= THP_PEN_LIST_MAX_FRAMES) {
		thp_log_err(cd,
			"%s:frame buf full exception restored,frame_count:%d\n",
			__func__, cd->frame_count);
		pre_frame_count = cd->frame_count;
	}

	temp = kzalloc(sizeof(struct thp_frame), GFP_KERNEL);
	if (!temp) {
		thp_log_err(cd, "%s:memory out\n", __func__);
		mutex_unlock(&(cd->mutex_frame));
		return;
	}

	if (cd->frame_size > sizeof(temp->frame)) {
		thp_log_err(cd, "%s: frame size is too large: %u\n",
			__func__, cd->frame_size);
		len = sizeof(temp->frame);
	} else {
		len = cd->frame_size;
	}
	memcpy(temp->frame, cd->frame_read_buf, len);
	get_timestamp(&(temp->tv));
	list_add_tail(&(temp->list), &(cd->frame_list.list));
	cd->frame_count++;
	mutex_unlock(&(cd->mutex_frame));
}

/*
 * disable the interrupt if the interrupt is enabled,
 * which is only used in irq handler
 */
static void thp_disable_irq_in_irq_process(struct thp_core_data *cd)
{
	int ret;

	/*
	 * Use mutex_trylock to avoid the irq process requesting lock failure,
	 * thus solving the problem that other process calls disable_irq
	 * process is blocked.
	 */
	ret = mutex_trylock(&cd->irq_mutex);
	if (ret) {
		if (cd->irq_enabled) {
			disable_irq_nosync(cd->irq);
			cd->irq_enabled = 0;
			thp_log_info(cd, "%s:disable irq to protect irq storm\n",
				__func__);
		}
		mutex_unlock(&cd->irq_mutex);
		return;
	}
	thp_log_info(cd, "%s:failed to try lock, only need ignore it\n", __func__);
}

static void protect_for_irq_storm(struct thp_core_data *cd)
{
	struct timeval end_time;
	static struct timeval irq_storm_start_time;
	long delta_time;

	/*
	 * We should not try to disable irq when we
	 * need to handle the irq in screen off state
	 */
	if (!cd->support_irq_storm_protect) {
		if (need_work_in_suspend_switch(cd)) {
			thp_log_err(cd, "%s:ignore the irq\n", __func__);
			return;
		}
	}
	if (cd->invalid_irq_num == 0) {
		get_timestamp(&irq_storm_start_time);
		return;
	}
	if (cd->invalid_irq_num == MAX_INVALID_IRQ_NUM) {
		memset(&end_time, 0, sizeof(end_time));
		cd->invalid_irq_num = 0;
		get_timestamp(&end_time);
		/* multiply 1000000 to transfor second to us */
		delta_time = ((end_time.tv_sec - irq_storm_start_time.tv_sec) *
			1000000) + end_time.tv_usec -
			irq_storm_start_time.tv_usec;
		/* divide 1000 to transfor sec to us to ms */
		delta_time /= 1000;
		thp_log_info(cd, "%s:delta_time = %ld ms\n", __func__, delta_time);
		if (delta_time <= (MAX_INVALID_IRQ_NUM / THP_IRQ_STORM_FREQ)) {
			if (cd->support_irq_storm_protect)
				cd->irq_storm_flag = true;
			thp_disable_irq_in_irq_process(cd);
		}
	}
}

static void thp_pen_irq_thread_suspend_process(struct thp_core_data *cd)
{
	int rc;
	unsigned int gesture_wakeup_value = 0;
	/*
	 * whole process interruption storm protection
	 * when open support_irq_storm_protect
	 */
	if (cd->support_irq_storm_protect) {
		if (!cd->irq_storm_flag) {
			protect_for_irq_storm(cd);
			cd->invalid_irq_num++;
		}
	}
	if (need_work_in_suspend_switch(cd) &&
		(cd->work_status != RESUME_DONE)) {
		thp_log_info(cd, "%s:ts gesture mode irq\n", __func__);
		if (cd->thp_dev->ops->chip_gesture_report) {
			rc = cd->thp_dev->ops->chip_gesture_report(cd->thp_dev,
				&gesture_wakeup_value);
			if (rc) {
				thp_log_err(cd,
					"%s:gesture report failed this irq,rc = %d\n",
					__func__, rc);
				goto exit;
			}
		} else {
			thp_log_err(cd, "%s:gesture not support\n", __func__);
			goto exit;
		}
		thp_inputkey_report(cd, gesture_wakeup_value);
		goto exit;
	}

	return;
exit:
	trace_touch(TOUCH_TRACE_IRQ_BOTTOM, TOUCH_TRACE_FUNC_OUT, "thp");
}

static irqreturn_t thp_pen_irq_thread(int irq, void *dev_id)
{
	struct thp_core_data *cd = dev_id;
	u8 *read_buf = (u8 *)cd->frame_read_buf;
	int rc;

	trace_touch(TOUCH_TRACE_IRQ_BOTTOM, TOUCH_TRACE_FUNC_IN, "thp");
	if (cd->reset_flag) {
		thp_log_err(cd, "%s:reset state, ignore this irq\n", __func__);
		return IRQ_HANDLED;
	}

	if (cd->suspended && (!cd->need_work_in_suspend)) {
		thp_pen_irq_thread_suspend_process(cd);
		return IRQ_HANDLED;
	}

	disable_irq_nosync(cd->irq);

	/* get frame */
	rc = cd->thp_dev->ops->get_frame(cd->thp_dev, read_buf, cd->frame_size);
	if (rc) {
		thp_log_err(cd, "%s: failed to read frame %d\n", __func__, rc);
		goto exit;
	}

	trace_touch(TOUCH_TRACE_DATA2ALGO, TOUCH_TRACE_FUNC_IN, "thp");
	if (cd->use_thp_queue)
		thp_pen_copy_frame_to_thp_queue(cd);
	else
		thp_pen_copy_frame(cd);
	thp_pen_wake_up_frame_waitq(cd);
	trace_touch(TOUCH_TRACE_DATA2ALGO, TOUCH_TRACE_FUNC_OUT, "thp");

exit:
	enable_irq(cd->irq);
	trace_touch(TOUCH_TRACE_IRQ_BOTTOM, TOUCH_TRACE_FUNC_OUT, "thp");
	return IRQ_HANDLED;
}

#define THP_PROJECTID_LEN 9
#define THP_PROJECTID_PRODUCT_NAME_LEN 4
#define THP_PROJECTID_IC_NAME_LEN 2
#define THP_PROJECTID_VENDOR_NAME_LEN 3
#if (IS_ENABLED(CONFIG_HONOR_THP_MTK))
static int thp_pen_mtk_pinctrl_get_init(struct thp_device *tdev)
{
	int ret = 0;
	struct thp_core_data *cd = tdev->thp_core;

	cd->mtk_pinctrl.cs_high =
		pinctrl_lookup_state(cd->pctrl, PINCTRL_STATE_CS_HIGH);
	if (IS_ERR_OR_NULL(cd->mtk_pinctrl.cs_high)) {
		thp_log_err(cd, "Can not lookup %s pinstate\n",
			PINCTRL_STATE_CS_HIGH);
		ret = -EINVAL;
		return ret;
	}

	cd->mtk_pinctrl.cs_low =
		pinctrl_lookup_state(cd->pctrl, PINCTRL_STATE_CS_LOW);
	if (IS_ERR_OR_NULL(cd->mtk_pinctrl.cs_low)) {
		thp_log_err(cd, "Can not lookup %s pinstate\n",
			PINCTRL_STATE_CS_LOW);
		ret = -EINVAL;
		return ret;
	}

	cd->mtk_pinctrl.spi_status = pinctrl_lookup_state(cd->pctrl,
			PINCTRL_STATE_SPI_STATUS);
	if (IS_ERR_OR_NULL(cd->mtk_pinctrl.spi_status)) {
		thp_log_err(cd, "Can not lookup %s pinstate\n",
			PINCTRL_STATE_SPI_STATUS);
		ret = -EINVAL;
		return ret;
	}
	ret = pinctrl_select_state(cd->pctrl,
		cd->mtk_pinctrl.spi_status);
	if (ret < 0)
		thp_log_err(cd, "change spi driving force failed\n");

	return ret;
}
#endif

static int thp_pen_setup_irq(struct thp_core_data *cd)
{
	int rc;
	int irq;
	char *node = NULL;
	unsigned long irq_flag_type;
	u32 current_trigger_mode;

	if (!cd) {
		thp_log_err(cd, "%s: thp_core_data is null\n", __func__);
		return -EINVAL;
	}

#ifdef CONFIG_ARCH_QTI_VM
	if (atomic_read(&cd->vm_info->vm_state) == TVM_IRQ_ACCEPTED)  {
		irq = cd->irq;
	} else {
		thp_log_err(cd, "%s: irq is not lent successfully.\n", __func__);
		return -EINVAL;
	}
#else
	irq = gpio_to_irq(cd->gpios.irq_gpio);
#endif
	/*
	 * IRQF_TRIGGER_RISING 0x00000001
	 * IRQF_TRIGGER_FALLING 0x00000002
	 * IRQF_TRIGGER_HIGH 0x00000004
	 * IRQF_TRIGGER_LOW 0x00000008
	 * IRQF_NO_SUSPEND 0x00004000
	 */
	current_trigger_mode = cd->irq_flag;
	thp_log_info(cd, "%s:current_trigger_mode->0x%x\n",
		__func__, current_trigger_mode);

#ifdef CONFIG_ARCH_QTI_VM
	// here we have to use this trigger mode in qtvm, otherwise it will setup failed.
	irq_flag_type = IRQF_ONESHOT | IRQF_TRIGGER_RISING;
#else
	irq_flag_type = IRQF_ONESHOT | current_trigger_mode;
#endif
	if (cd->multi_panel_index != SINGLE_TOUCH_PANEL) {
		node = kzalloc(sizeof(char) * MULTI_PANEL_NODE_BUF_LEN, GFP_KERNEL);
		if (!node) {
			thp_log_err(cd, "%s:node is null\n", __func__);
			rc = -ENOMEM;
			kfree(node);
			node = NULL;
			return rc;
		}
		rc = snprintf(node, MULTI_PANEL_NODE_BUF_LEN, "%s%d",
			"thp", cd->multi_panel_index);
		if (rc < 0) {
			thp_log_err(cd, "%s: snprintf err\n", __func__);
			return rc;
		}
		rc = request_threaded_irq(irq, NULL,
				thp_pen_irq_thread, irq_flag_type,
				node, cd);
	} else {
		rc = request_threaded_irq(irq, NULL,
				thp_pen_irq_thread, irq_flag_type,
				"thp", cd);
	}

	if (rc) {
		thp_log_err(cd, "%s: request irq fail\n", __func__);
		kfree(node);
		node = NULL;
		return rc;
	}
	mutex_lock(&cd->irq_mutex);
	disable_irq(irq);
	cd->irq_enabled = false;
	mutex_unlock(&cd->irq_mutex);
	thp_log_info(cd, "%s: disable irq\n", __func__);
	cd->irq = irq;

	return 0;
}

static int thp_pen_setup_gpio(struct thp_core_data *cd)
{
	int rc;

#ifdef CONFIG_ARCH_QTI_VM
	thp_log_info(cd, "%s: called in QTVM, do nothing\n", __func__);
	return 0;
#else
	thp_log_info(cd, "%s: called\n", __func__);
#endif

	rc = gpio_request(cd->gpios.cs_gpio, "thp_cs");
	if (rc) {
		thp_log_err(cd, "%s:gpio_request %d failed\n", __func__,
				cd->gpios.cs_gpio);
		gpio_free(cd->gpios.rst_gpio);
		return rc;
	}
	gpio_direction_output(cd->gpios.cs_gpio, GPIO_HIGH);

	thp_log_info(cd, "%s:set cs gpio %d deault hi\n", __func__,
				cd->gpios.cs_gpio);

	rc = gpio_request(cd->gpios.irq_gpio, "thp_int");
	if (rc) {
		thp_log_err(cd, "%s: irq gpio %d request failed\n", __func__,
				cd->gpios.irq_gpio);
		gpio_free(cd->gpios.rst_gpio);
		gpio_free(cd->gpios.cs_gpio);
		return rc;
	}
	rc = gpio_direction_input(cd->gpios.irq_gpio);
	if (rc)
		thp_log_info(cd, "%s:gpio_direction_input failed\n", __func__);

	return 0;
}

static void thp_pen_free_gpio(struct thp_core_data *cd)
{
#ifdef CONFIG_ARCH_QTI_VM
	thp_log_info(cd, "%s: called in QTVM, do nothing\n", __func__);
	return;
#else
	thp_log_info(cd, "%s: called\n", __func__);
#endif

	gpio_free(cd->gpios.irq_gpio);
	gpio_free(cd->gpios.cs_gpio);
}

static int thp_pen_setup_spi(struct thp_core_data *cd)
{
	int rc;

#if (IS_ENABLED(CONFIG_HONOR_THP_MTK))
	cd->mtk_spi_config.cs_setuptime =
		cd->thp_dev->timing_config.spi_sync_cs_low_delay_ns;
#endif
	rc = spi_setup(cd->sdev);
	if (rc) {
		thp_log_err(cd, "%s: spi setup fail\n", __func__);
		return rc;
	}

	return 0;
}

static int thp_pen_pinctrl_get_init(struct thp_device *tdev)
{
	int ret = 0;

#ifdef CONFIG_ARCH_QTI_VM
	thp_log_info(tdev->thp_core, "%s: called in QTVM, do nothing\n", __func__);
	return ret;
#endif

	tdev->thp_core->pctrl = devm_pinctrl_get(&tdev->sdev->dev);
	if (IS_ERR(tdev->thp_core->pctrl)) {
		thp_log_err(tdev->thp_core, "failed to devm pinctrl get\n");
		ret = -EINVAL;
		return ret;
	}

	tdev->thp_core->pins_default =
		pinctrl_lookup_state(tdev->thp_core->pctrl, "default");
	if (IS_ERR(tdev->thp_core->pins_default)) {
		thp_log_err(tdev->thp_core, "failed to pinctrl lookup state default\n");
		ret = -EINVAL;
		goto err_pinctrl_put;
	}

	tdev->thp_core->pins_idle =
			pinctrl_lookup_state(tdev->thp_core->pctrl, "idle");
	if (IS_ERR(tdev->thp_core->pins_idle)) {
		thp_log_err(tdev->thp_core, "failed to pinctrl lookup state idle\n");
		ret = -EINVAL;
		goto err_pinctrl_put;
	}

#if (IS_ENABLED(CONFIG_HONOR_THP_MTK))
	ret = thp_pen_mtk_pinctrl_get_init(tdev);
	if (ret < 0) {
		thp_log_err(tdev->thp_core, "%s: mtk pinctrl init failed\n", __func__);
		goto err_pinctrl_put;
	}
#endif

	return 0;

err_pinctrl_put:
	devm_pinctrl_put(tdev->thp_core->pctrl);
	return ret;
}

static int thp_pen_pinctrl_select_normal(struct thp_device *tdev)
{
	int retval = 0;

#ifdef CONFIG_ARCH_QTI_VM
	thp_log_info(tdev->thp_core, "%s: called in QTVM, do nothing\n", __func__);
	return retval;
#endif

	retval = pinctrl_select_state(tdev->thp_core->pctrl,
		tdev->thp_core->pins_default);
	if (retval < 0)
		thp_log_err(tdev->thp_core, "set iomux normal error, %d\n", retval);
	return retval;
}
#ifndef CONFIG_ARCH_QTI_VM
static int thp_pinctrl_select_lowpower(struct thp_device *tdev)
{
	int retval;

	retval = pinctrl_select_state(tdev->thp_core->pctrl,
		tdev->thp_core->pins_idle);
	if (retval < 0)
		thp_log_err(tdev->thp_core, "set iomux lowpower error, %d\n", retval);
	return retval;
}
#endif


static int thp_pen_misc_init(struct thp_core_data *cd)
{
	int rc;
	struct miscdevice *misc_device = NULL;
	char *node = NULL;

	misc_device = kzalloc(sizeof(struct miscdevice), GFP_KERNEL);
	if (!misc_device) {
		thp_log_err(cd, "%s: misc_device out of memory\n", __func__);
		return -ENOMEM;
	}

	misc_device->name = THP_PEN_MISC_DEVICE_NAME;
	if (cd->sub_solution == THP_SOLUTION) {
		node = kzalloc(sizeof(char) * MULTI_PANEL_NODE_BUF_LEN, GFP_KERNEL);
		if (!node) {
			thp_log_err(cd, "%s:node is null\n", __func__);
			rc = -ENOMEM;
			goto err_register_misc;
		}
		rc = snprintf(node, MULTI_PANEL_NODE_BUF_LEN, "%s%d",
			THP_PEN_MISC_DEVICE_NAME, cd->multi_panel_index);
		if (rc < 0) {
			thp_log_err(cd, "%s: multi snprintf err\n", __func__);
			goto err_register_misc;
		}
		misc_device->name = (const char *)node;
	}

	misc_device->minor = MISC_DYNAMIC_MINOR;
	misc_device->fops = &g_thp_pen_fops;
	rc = misc_register(misc_device);
	if (rc) {
		thp_log_err(cd, "%s: failed to register misc device\n", __func__);
		goto err_register_misc;
	}
	cd->thp_misc_device = misc_device;

	return rc;

err_register_misc:
	if (node)
		kfree(node);
	if (misc_device)
		kfree(misc_device);
	return rc;
}

static int thp_pen_misc_exit(struct thp_core_data *cd)
{
	if (cd->thp_misc_device)
		misc_deregister(cd->thp_misc_device);
	if (cd->thp_misc_device->name)
		kfree(cd->thp_misc_device->name);
	if (cd->thp_misc_device)
		kfree(cd->thp_misc_device);
	return 0;
}

static int thp_pen_core_init(struct thp_core_data *cd)
{
	int rc;

	/* step 1 : init mutex */
	mutex_init(&cd->mutex_frame);
	mutex_init(&cd->irq_mutex);
	mutex_init(&cd->thp_mutex);
	mutex_init(&cd->status_mutex);
	mutex_init(&cd->suspend_flag_mutex);
#if (IS_ENABLED(CONFIG_HONOR_THP_QCOM) || IS_ENABLED(CONFIG_HONOR_THP_MTK))
	mutex_init(&cd->aod_power_ctrl_mutex);
#endif
	if (cd->support_gesture_mode)
		mutex_init(&cd->thp_wrong_touch_lock);
	dev_set_drvdata(&cd->sdev->dev, cd);
	cd->ic_name = cd->thp_dev->ic_name;
	cd->prox_cache_enable = false;
	cd->need_work_in_suspend = false;
	cd->thp_prox_enable = false;
	cd->onetime_poweroff_done = false;
	cd->work_status = RESUME_DONE;
	cd->event_anomaly_count = 0;

#if IS_ENABLED(CONFIG_DSM)
	if (cd->ic_name)
		dsm_thp.ic_name = cd->ic_name;
	if (strlen(cd->project_id))
		dsm_thp.module_name = cd->project_id;
	dsm_thp_pen_dclient = dsm_register_client(&dsm_thp);
#endif
	rc = thp_pen_misc_init(cd);
	if (rc) {
		thp_log_err(cd, "%s: failed to init misc device\n", __func__);
	}

	rc = thp_pen_setup_irq(cd);

	if (rc) {
		thp_log_err(cd, "%s: failed to set up irq\n", __func__);
	}

	atomic_set(&cd->register_flag, 1);

	mutex_destroy(&cd->mutex_frame);
	mutex_destroy(&cd->irq_mutex);
	mutex_destroy(&cd->thp_mutex);
#if (IS_ENABLED(CONFIG_HONOR_THP_QCOM) || IS_ENABLED(CONFIG_HONOR_THP_MTK))
	mutex_destroy(&cd->aod_power_ctrl_mutex);
#endif
	if (cd->support_gesture_mode)
		mutex_destroy(&cd->thp_wrong_touch_lock);
	return rc;
}

static int thp_pen_parse_test_config(struct thp_core_data *cd, struct device_node *test_node,
	struct thp_test_config *config)
{
	int rc;
	unsigned int value = 0;

	if (!test_node || !config) {
		thp_log_info(cd, "%s: input dev null\n", __func__);
		return -ENODEV;
	}

	rc = of_property_read_u32(test_node,
			"pt_station_test", &value);
	if (!rc) {
		config->pt_station_test = value;
		thp_log_info(cd, "%s:pt_test_flag %d\n",
			__func__, value);
	}

	return 0;
}

static struct device_node *thp_pen_get_dev_node(struct thp_core_data *cd,
	struct thp_device *dev)
{
	struct device_node *dev_node = of_get_child_by_name(cd->thp_node,
						dev->ic_name);

	if (!dev_node && dev->dev_node_name)
		return of_get_child_by_name(cd->thp_node, dev->dev_node_name);

	return dev_node;
}

static void thp_pen_chip_detect(struct thp_core_data *cd, struct thp_cmd_node *in_cmd)
{
	int ret;
	struct thp_device *dev = NULL;

	if (in_cmd == NULL) {
		thp_log_err(cd, "%s:input is NULL\n", __func__);
		return;
	}
	dev = in_cmd->cmd_param.pub_params.dev;
	ret = thp_pen_register_dev(cd, dev);
	if (ret)
		thp_log_err(cd, "%s,register failed\n", __func__);
}

void thp_pen_send_detect_cmd(struct thp_core_data *cd, struct thp_device *dev, int timeout)
{
	int error;
	struct thp_cmd_node cmd;

	thp_log_info(cd, "%s: called\n", __func__);
	if (dev == NULL) {
		thp_log_info(cd, "%s: input is invalid\n", __func__);
		return;
	}
	cd->thp_unregister_ic_num++;
	thp_log_info(cd, "%s:thp_unregister_ic_num:%d",
		__func__, cd->thp_unregister_ic_num);
	memset(&cmd, 0, sizeof(cmd));
	cmd.command = TS_CHIP_DETECT;
	cmd.cmd_param.pub_params.dev = dev;
	error = thp_pen_put_one_cmd(cd, &cmd, timeout);
	if (error)
		thp_log_err(cd, "%s: put cmd error :%d\n", __func__, error);
}

int thp_pen_register_dev(struct thp_core_data *cd, struct thp_device *dev)
{
	int rc = -EINVAL;

	if ((dev == NULL) || (cd == NULL)) {
		thp_log_err(cd, "%s: input null\n", __func__);
		goto register_err;
	}
	thp_log_info(cd, "%s: called\n", __func__);
	/* check device configed ot not */
	if (!thp_pen_get_dev_node(cd, dev)) {
		thp_log_info(cd, "%s: not config in dts\n",
				__func__);
		goto register_err;
	}

	if (atomic_read(&cd->register_flag)) {
		thp_log_err(cd, "%s: thp have registerd\n", __func__);
		goto register_err;
	}

	dev->thp_core = cd;
	dev->gpios = &cd->gpios;
	dev->sdev = cd->sdev;
	cd->thp_dev = dev;
	cd->is_fw_update = 0;

	rc = thp_pen_parse_timing_config(cd, cd->thp_node, &dev->timing_config);
	if (rc) {
		thp_log_err(cd, "%s: timing config parse fail\n", __func__);
		goto register_err;
	}

	rc = thp_pen_parse_test_config(cd, cd->thp_node, &dev->test_config);
	if (rc) {
		thp_log_err(cd, "%s: special scene config parse fail\n", __func__);
		goto register_err;
	}

	rc = dev->ops->init(dev);
	if (rc) {
		thp_log_err(cd, "%s: dev init fail\n", __func__);
		goto dev_init_err;
	}

	rc = thp_pen_pinctrl_get_init(dev);
	if (rc) {
		thp_log_err(cd, "%s:pinctrl get init fail\n", __func__);
		goto dev_init_err;
	}

	rc = thp_pen_setup_gpio(cd);
	if (rc) {
		thp_log_err(cd, "%s: spi dev init fail\n", __func__);
		goto dev_init_err;
	}

	rc = thp_pen_setup_spi(cd);
	if (rc) {
		thp_log_err(cd, "%s: spi dev init fail\n", __func__);
		goto err;
	}

	rc = dev->ops->detect(dev);
	if (rc) {
		thp_log_err(cd, "%s: chip detect fail\n", __func__);
		goto err;
	}

	rc = thp_pen_pinctrl_select_normal(cd->thp_dev);
	if (rc) {
		thp_log_err(cd, "%s:thp_pen_pinctrl_select_normal fail\n", __func__);
		goto err;
	}

	rc = thp_pen_core_init(cd);
	if (rc) {
		thp_log_err(cd, "%s: core init\n", __func__);
		goto err;
	}

	cd->thp_unregister_ic_num--;
	thp_log_info(cd, "%s:thp_pen_unregister_ic_num :%d", __func__, cd->thp_unregister_ic_num);

	return 0;
err:
	thp_pen_free_gpio(cd);
dev_init_err:
	cd->thp_dev = 0;
register_err:
	if (cd && cd->fast_booting_solution) {
		cd->thp_unregister_ic_num--;
		thp_log_info(cd, "%s:thp_unregister_ic_num :%d",
			__func__, cd->thp_unregister_ic_num);
	}
	return rc;
}

int thp_pen_parse_spi3_config(struct device_node *spi_cfg_node,
	struct thp_core_data *cd)
{
	int rc;
	unsigned int value;
	struct thp_spi_config *spi_config = NULL;
	struct pl022_config_chip *pl022_spi_config = NULL;

	if (!spi_cfg_node || !cd) {
		thp_log_info(cd, "%s: input null\n", __func__);
		return -ENODEV;
	}
	spi_config = &cd->spi_config;
	pl022_spi_config = &cd->spi_config.pl022_spi_config;

	value = 0;
	rc = of_property_read_u32(spi_cfg_node, "spi-max-frequency", &value);
	if (!rc) {
		spi_config->max_speed_hz = value;
		thp_log_info(cd, "%s:spi-max-frequency configed %d\n",
				__func__, value);
	}
	value = 0;
	rc = of_property_read_u32(spi_cfg_node, "spi-bus-id", &value);
	if (!rc) {
		spi_config->bus_id = (u8)value;
		thp_log_info(cd, "%s:spi-bus-id configed %d\n", __func__, value);
	}
	value = 0;
	rc = of_property_read_u32(spi_cfg_node, "spi-mode", &value);
	if (!rc) {
		spi_config->mode = value;
		thp_log_info(cd, "%s:spi-mode configed %d\n", __func__, value);
	}
	value = 0;
	rc = of_property_read_u32(spi_cfg_node, "bits-per-word", &value);
	if (!rc) {
		spi_config->bits_per_word = value;
		thp_log_info(cd, "%s:bits-per-word configed %d\n", __func__, value);
	}

	if (!cd->spi_config.max_speed_hz)
		cd->spi_config.max_speed_hz = THP_SPI_SPEED_DEFAULT;
	if (!cd->spi_config.mode)
		cd->spi_config.mode = SPI_MODE_0;
	if (!cd->spi_config.bits_per_word)
	/* spi_config.bits_per_word default value is 8 */
		cd->spi_config.bits_per_word = 8;
#if (IS_ENABLED(CONFIG_HONOR_THP_MTK))
	/* control sample edge, 0-positive edge; 1-negative edge */
	cd->mtk_spi_config.sample_sel = 0;
	/* cs setup time, 0-default time */
	cd->mtk_spi_config.cs_setuptime = 0;
#endif
	cd->sdev->mode = spi_config->mode;
	cd->sdev->max_speed_hz = spi_config->max_speed_hz;
	cd->sdev->bits_per_word = spi_config->bits_per_word;
#if (IS_ENABLED(CONFIG_HONOR_THP_MTK))
	cd->sdev->controller_data = (void *)&(cd->mtk_spi_config);
#endif

	return 0;
}
EXPORT_SYMBOL(thp_pen_parse_spi3_config);

int thp_pen_parse_timing_config(struct thp_core_data *cd, struct device_node *timing_cfg_node,
	struct thp_timing_config *timing)
{
	int rc;
	unsigned int value;

	if (!timing_cfg_node || !timing) {
		thp_log_info(cd, "%s: input null\n", __func__);
		return -ENODEV;
	}

	rc = of_property_read_u32(timing_cfg_node,
					"boot_reset_hi_delay_ms", &value);
	if (!rc) {
		timing->boot_reset_hi_delay_ms = value;
		thp_log_info(cd, "%s:boot_reset_hi_delay_ms configed %d\n",
				__func__, value);
	}

	rc = of_property_read_u32(timing_cfg_node,
					"boot_reset_low_delay_ms", &value);
	if (!rc) {
		timing->boot_reset_low_delay_ms = value;
		thp_log_info(cd, "%s:boot_reset_low_delay_ms configed %d\n",
				__func__, value);
	}

	rc = of_property_read_u32(timing_cfg_node,
					"boot_reset_after_delay_ms", &value);
	if (!rc) {
		timing->boot_reset_after_delay_ms = value;
		thp_log_info(cd, "%s:boot_reset_after_delay_ms configed %d\n",
				__func__, value);
	}

	rc = of_property_read_u32(timing_cfg_node,
					"resume_reset_after_delay_ms", &value);
	if (!rc) {
		timing->resume_reset_after_delay_ms = value;
		thp_log_info(cd, "%s:resume_reset_after_delay_ms configed %d\n",
				__func__, value);
	}

	rc = of_property_read_u32(timing_cfg_node,
					"suspend_reset_after_delay_ms", &value);
	if (!rc) {
		timing->suspend_reset_after_delay_ms = value;
		thp_log_info(cd, "%s:suspend_reset_after_delay configed_ms %d\n",
				__func__, value);
	}

	rc = of_property_read_u32(timing_cfg_node,
					"spi_sync_cs_hi_delay_ns", &value);
	if (!rc) {
		timing->spi_sync_cs_hi_delay_ns = value;
		thp_log_info(cd, "%s:spi_sync_cs_hi_delay_ns configed_ms %d\n",
				__func__, value);
	}

	rc = of_property_read_u32(timing_cfg_node,
					"spi_sync_cs_low_delay_ns", &value);
	if (!rc) {
		timing->spi_sync_cs_low_delay_ns = value;
		thp_log_info(cd, "%s:spi_sync_cs_low_delay_ns configed_ms %d\n",
				__func__, value);
	}
	rc = of_property_read_u32(timing_cfg_node,
					"spi_sync_cs_low_delay_us", &value);
	if (!rc) {
		timing->spi_sync_cs_low_delay_us = value;
		thp_log_info(cd, "%s:spi_sync_cs_low_delay_us = %d\n",
				__func__, value);
	} else {
		timing->spi_sync_cs_low_delay_us = 0;
	}

	rc = of_property_read_u32(timing_cfg_node,
		"boot_vcc_on_after_delay_ms", &value);
	if (!rc) {
		timing->boot_vcc_on_after_delay_ms = value;
		thp_log_info(cd, "%s:boot_vcc_on_after_delay_ms configed_ms %d\n",
			__func__, value);
	}
	rc = of_property_read_u32(timing_cfg_node,
		"boot_vddio_on_after_delay_ms", &value);
	if (!rc) {
		timing->boot_vddio_on_after_delay_ms = value;
		thp_log_info(cd, "%s:boot_vddio_on_after_delay_ms configed_ms %d\n",
			__func__, value);
	}
	rc = of_property_read_u32(timing_cfg_node,
		"spi_transfer_delay_us", &value);
	if (!rc) {
		timing->spi_transfer_delay_us = value;
		thp_log_info(cd, "%s:spi_transfer_delay_us = %d\n",
			__func__, value);
	} else {
		timing->spi_transfer_delay_us = 0;
	}
	if (!of_property_read_u32(timing_cfg_node,
		"early_suspend_delay_ms", &value)) {
		timing->early_suspend_delay_ms = value;
		thp_log_info(cd, "%s:early_suspend_delay_ms configed_ms %u\n",
			__func__, value);
	}
	return 0;
}
EXPORT_SYMBOL(thp_pen_parse_timing_config);

static void  thp_pen_parse_extra_feature_config(
	struct device_node *thp_node, struct thp_core_data *cd)
{
	int rc;
	unsigned int value = 0;

	cd->support_reuse_ic_type = 0;
	rc = of_property_read_u32(thp_node, "use_thp_queue",
		&value);
	if (!rc) {
		cd->use_thp_queue = value;
		thp_log_info(cd, "%s: use_thp_queue %u\n",
			__func__, value);
	}
	cd->thp_queue_buf_len = THP_QUEUE_NODE_BUFF_MAX_LEN;
}

static int thp_pen_parse_feature_config(struct device_node *thp_node,
	struct thp_core_data *cd)
{
	// int rc;
	unsigned int value = 0;

	thp_log_debug(cd, "%s:Enter!\n", __func__);
	/*
	 * TDDI(TP powered by LCD) download fw in afe screen on,
	 * need wait interruptible to make sure of screen on done.
	 */
	if (!of_property_read_u32(thp_node, "wait_afe_screen_on_support",
		&value)) {
		cd->wait_afe_screen_on_support = value;
		thp_log_info(cd, "%s:wait_afe_screen_on_support configed %u\n",
			__func__, value);
	}
	cd->support_vendor_ic_type = 0;
	cd->edit_product_in_project_id = 0;
	cd->need_resume_reset = 0;
	cd->support_dual_chip_arch = 0;
	cd->gesture_retry_times = 20; /* defult gesture retry times:20 */

	cd->lcd_need_get_afe_status = 0;



	return 0;
}
//EXPORT_SYMBOL(thp_pen_parse_feature_config);

static int thp_pen_parse_config(struct thp_core_data *cd,
	struct device_node *thp_node)
{
	int rc;
	unsigned int value;

	if (!thp_node) {
		thp_log_err(cd, "%s:thp not config in dts, exit\n", __func__);
		return -ENODEV;
	}

	rc = thp_pen_parse_spi3_config(thp_node, cd);
	if (rc) {
		thp_log_err(cd, "%s: spi config parse fail\n", __func__);
		return rc;
	}

	cd->irq_flag = IRQF_TRIGGER_FALLING;
	rc = of_property_read_u32(thp_node, "irq_flag", &value);
	if (!rc) {
		cd->irq_flag = value;
		thp_log_info(cd, "%s:irq_flag parsed\n", __func__);
	}
	cd->fast_booting_solution = 0;
	rc = of_property_read_u32(thp_node, "fast_booting_solution", &value);
	if (!rc) {
		cd->fast_booting_solution = value;
		thp_log_info(cd, "%s:fast_booting_solution parsed:%d\n",
			__func__, cd->fast_booting_solution);
	}
	value = of_get_named_gpio(thp_node, "irq_gpio", 0);
	thp_log_info(cd, "irq gpio_ = %d\n", value);
	if (!gpio_is_valid(value)) {
		thp_log_err(cd, "%s: get irq_gpio failed\n", __func__);
		return rc;
	}
	cd->gpios.irq_gpio = value;

	value = of_get_named_gpio(thp_node, "cs_gpio", 0);
	thp_log_info(cd, "cs_gpio = %d\n", value);
	if (!gpio_is_valid(value)) {
		thp_log_err(cd, "%s: get cs_gpio failed\n", __func__);
		return rc;
	}
	cd->gpios.cs_gpio = value;
	thp_pen_parse_feature_config(thp_node, cd);
	thp_pen_parse_extra_feature_config(thp_node, cd);

	cd->thp_node = thp_node;
	return 0;
}

static int thp_pen_cmd_sync_allocate(struct thp_core_data *cd, struct thp_cmd_node *cmd, int timeout)
{
	struct thp_cmd_sync *sync = NULL;

	if (timeout == 0) {
		cmd->sync = NULL;
		return 0;
	}
	sync = kzalloc(sizeof(*sync), GFP_KERNEL);
	if (sync == NULL) {
		thp_log_err(cd, "failed to kzalloc completion\n");
		return -ENOMEM;
	}
	init_completion(&sync->done);
	atomic_set(&sync->timeout_flag, TS_NOT_TIMEOUT);
	cmd->sync = sync;
	return 0;
}

static int thp_pen_put_one_cmd(struct thp_core_data *cd, struct thp_cmd_node *cmd, int timeout)
{
	int error = -EIO;
	unsigned long flags;
	struct thp_cmd_queue *q = NULL;

	if ((cmd == NULL) || (cd == NULL)) {
		thp_log_err(cd, "%s:null pointer\n", __func__);
		goto out;
	}
	if ((!atomic_read(&cd->register_flag)) &&
		(cmd->command != TS_CHIP_DETECT)) {
		thp_log_err(cd, "%s: not initialize\n", __func__);
		goto out;
	}
	if (thp_pen_cmd_sync_allocate(cd, cmd, timeout)) {
		thp_log_debug(cd, "%s:allocate success\n", __func__);
		/*
		 * When the command execution timeout the memory occupied
		 * by sync will be released  in the command execution module,
		 * else the memory will be released after waiting for the
		 * command return normally.
		 */
		goto out;
	}
	q = &cd->queue;
	spin_lock_irqsave(&q->spin_lock, flags);
	smp_wmb(); /* Make sure queue has assigned correctly */
	if (q->cmd_count == q->queue_size) {
		spin_unlock_irqrestore(&q->spin_lock, flags);
		thp_log_err(cd, "%s:queue is full\n", __func__);
		WARN_ON(1);
		error = -EIO;
		goto free_sync;
	}
	memcpy(&q->ring_buff[q->wr_index], cmd, sizeof(*cmd));
	q->cmd_count++;
	q->wr_index++;
	q->wr_index %= q->queue_size;
	smp_mb(); /* Make sure queue is refreshed correctly */
	spin_unlock_irqrestore(&q->spin_lock, flags);
	thp_log_debug(cd, "%s:%d in ring buff\n", __func__, cmd->command);
	error = NO_ERR;
	wake_up_process(cd->thp_task); /* wakeup thp process */
	if (timeout && (cmd->sync != NULL) &&
		!(wait_for_completion_timeout(&cmd->sync->done,
			abs(timeout) * HZ))) {
		atomic_set(&cmd->sync->timeout_flag, TS_TIMEOUT);
		thp_log_err(cd, "%s:wait cmd respone timeout\n", __func__);
		error = -EBUSY;
		goto out;
	}
	smp_wmb(); /* Make sure code has been completed before function ends */
free_sync:
	kfree(cmd->sync);
	cmd->sync = NULL;
out:
	return error;
}

static int get_one_cmd(struct thp_core_data *cd, struct thp_cmd_node *cmd)
{
	unsigned long flags;
	int error = -EIO;
	struct thp_cmd_queue *q = NULL;

	if (unlikely(!cmd)) {
		thp_log_err(cd, "%s:find null pointer\n", __func__);
		goto out;
	}

	q = &cd->queue;
	spin_lock_irqsave(&q->spin_lock, flags);
	smp_wmb(); /* Make sure queue has assigned correctly */
	if (!q->cmd_count) {
		thp_log_debug(cd, "%s: queue is empty\n", __func__);
		spin_unlock_irqrestore(&q->spin_lock, flags);
		goto out;
	}
	memcpy(cmd, &q->ring_buff[q->rd_index], sizeof(*cmd));
	q->cmd_count--;
	q->rd_index++;
	q->rd_index %= q->queue_size;
	smp_mb(); /* Make sure queue is refreshed correctly */
	spin_unlock_irqrestore(&q->spin_lock, flags);
	thp_log_debug(cd, "%s:%d from ring buff\n", __func__,
		cmd->command);
	error = NO_ERR;
out:
	return error;
}

static bool thp_pen_task_continue(struct thp_core_data *cd)
{
	bool task_continue = true;
	unsigned long flags;

	thp_log_debug(cd, "%s:prepare enter idle\n", __func__);
	while (task_continue) {
		if (unlikely(kthread_should_stop())) {
			task_continue = false;
			goto out;
		}
		spin_lock_irqsave(&cd->queue.spin_lock, flags);
		/*
		 * Make sure the memory and assignment are completed
		 * before updating the current process.
		 */
		smp_wmb();
		if (cd->queue.cmd_count) {
			set_current_state(TASK_RUNNING);
			thp_log_debug(cd, "%s:TASK_RUNNING\n", __func__);
			goto out_unlock;
		} else {
			set_current_state(TASK_INTERRUPTIBLE);
			thp_log_debug(cd, "%s:TASK_INTERRUPTIBLE\n", __func__);
			spin_unlock_irqrestore(&cd->queue.spin_lock, flags);
			schedule();
		}
	}

out_unlock:
	spin_unlock_irqrestore(&cd->queue.spin_lock, flags);
out:
	return task_continue;
}


static int thp_pen_proc_command(struct thp_core_data *cd, struct thp_cmd_node *cmd)
{
	int error = NO_ERR;
	struct thp_cmd_sync *sync = NULL;
	struct thp_cmd_node *proc_cmd = cmd;
	struct thp_cmd_node *out_cmd = &cd->pang_cmd_buff;

	if (!cmd) {
		thp_log_err(cd, "%s:invalid cmd\n", __func__);
		goto out;
	}
	sync = cmd->sync;
	/* discard timeout cmd */
	if (sync && (atomic_read(&sync->timeout_flag) == TS_TIMEOUT)) {
		kfree(sync);
		goto out;
	}
	while (true) {
		out_cmd->command = TS_INVAILD_CMD;
		switch (proc_cmd->command) {
		case TS_CHIP_DETECT:
			thp_pen_chip_detect(cd, proc_cmd);
			break;
#if defined CONFIG_LCD_KIT_DRIVER
		case THP_MUTIL_RESUME_THREAD:
			break;
		case THP_MUTIL_SUSPEND_THREAD:
			break;
		case TSKIT_MUTIL_RESUME_THREAD:
			break;
		case TSKIT_MUTIL_SUSPEND_THREAD:
			break;
		case TS_SCREEN_FOLD:
			break;
		case TS_SCREEN_UNFOLD:
			break;
		case AOD_NOTIFY_SUBPANEL_POWER_CTRL:
			break;
#endif
		default:
			break;
		}

		thp_log_debug(cd, "%s:command :%d process result:%d\n",
			__func__, proc_cmd->command, error);
		if (out_cmd->command != TS_INVAILD_CMD) {
			thp_log_debug(cd, "%s:related command :%d  need process\n",
				__func__, out_cmd->command);
			/* ping - pang */
			swap(proc_cmd, out_cmd);
		} else {
			break;
		}
	}
	/* notify wait threads by completion */
	if (sync) {
		smp_mb(); /* Make sure current timeout_flag is up to date */
		thp_log_debug(cd, "%s:wakeup threads in waitqueue\n", __func__);
		if (atomic_read(&sync->timeout_flag) == TS_TIMEOUT)
			kfree(sync);
		else
			complete(&sync->done);
	}

out:
	return error;
}

static int thp_pen_thread(void *thp_core)
{
	struct thp_core_data *cd = (struct thp_core_data *)thp_core;
	static const struct sched_param param = {
		/* The priority of thread scheduling is 99 */
		.sched_priority = 99,
	};
	/*
	 * Make sure buff is properly refreshed
	 * before the process is executed.
	 */
	smp_wmb();
	thp_log_info(cd, "%s: in\n", __func__);
	memset(&cd->ping_cmd_buff, 0, sizeof(cd->ping_cmd_buff));
	memset(&cd->pang_cmd_buff, 0, sizeof(cd->pang_cmd_buff));
	/*
	 * Make sure buff is properly refreshed
	 * before the process is executed.
	 */
	smp_mb();
	sched_setscheduler(current, SCHED_RR, &param);
	while (thp_pen_task_continue(cd)) {
		/* get one command */
		while (!get_one_cmd(cd, &cd->ping_cmd_buff)) {
			thp_pen_proc_command(cd, &cd->ping_cmd_buff);
			memset(&cd->ping_cmd_buff, 0, sizeof(cd->ping_cmd_buff));
			memset(&cd->pang_cmd_buff, 0, sizeof(cd->pang_cmd_buff));
		}
	}
	thp_log_err(cd, "%s: stop\n", __func__);
	return NO_ERR;
}

static int thp_pen_thread_init(struct thp_core_data *cd)
{
	if (cd->multi_panel_index == SINGLE_TOUCH_PANEL)
		cd->thp_task = kthread_create(thp_pen_thread, cd, "ts_thread:%d", 0);
	else
		cd->thp_task = kthread_create(thp_pen_thread, cd, "ts_thread:%d", cd->multi_panel_index);

	if (IS_ERR(cd->thp_task)) {
		kfree(cd->frame_read_buf);
		kfree(cd);
		g_thp_pen_core = NULL;
		thp_log_err(cd, "%s: creat thread failed\n", __func__);
		return -ENODEV;
	}
	cd->queue.rd_index = 0;
	cd->queue.wr_index = 0;
	cd->queue.cmd_count = 0;
	cd->queue.queue_size = THP_CMD_QUEUE_SIZE;
	spin_lock_init(&cd->queue.spin_lock);
	smp_mb(); /* Make sure queue is initialized before wake up the task */
	wake_up_process(cd->thp_task);
	return 0;
}

static int thp_pen_probe(struct spi_device *sdev)
{
	struct thp_core_data *thp_pen_core = NULL;
	u8 *frame_read_buf = NULL;
	int rc;

	thp_pen_core = kzalloc(sizeof(struct thp_core_data), GFP_KERNEL);
	if (!thp_pen_core) {
		thp_log_err(thp_pen_core, "%s: thp_pen_core out of memory\n", __func__);
		return -ENOMEM;
	}

	frame_read_buf = kzalloc(THP_MAX_FRAME_SIZE, GFP_KERNEL);
	if (!frame_read_buf) {
		thp_log_err(thp_pen_core, "%s: frame_read_buf out of memory\n", __func__);
		kfree(thp_pen_core);
		return -ENOMEM;
	}

	thp_pen_core->frame_read_buf = frame_read_buf;
	thp_pen_core->sdev = sdev;
	thp_pen_core->dev = &sdev->dev;
	rc = thp_pen_parse_config(thp_pen_core, sdev->dev.of_node);
	if (rc) {
		thp_log_err(thp_pen_core, "%s: parse dts fail\n", __func__);
		kfree(thp_pen_core->frame_read_buf);
		kfree(thp_pen_core);
		return -ENODEV;
	}

	thp_pen_core->thp_queue = thp_pen_queue_init(thp_pen_core);
	if (thp_pen_core->thp_queue == NULL) {
		thp_log_err(thp_pen_core, "%s: kzalloc frame fail\n", __func__);
		kfree(thp_pen_core->frame_read_buf);
		thp_pen_core->frame_read_buf = NULL;
		kfree(thp_pen_core);
		thp_pen_core = NULL;
		return -ENOMEM;
	}

	if (thp_pen_core->multi_panel_index == SUB_TOUCH_PANEL && recovery_mode == true) {
		thp_log_info(thp_pen_core, "%s: fold device in recovery\n", __func__);
		return 0;
	}

	mutex_init(&thp_pen_core->spi_mutex);
	atomic_set(&thp_pen_core->register_flag, 0);
	INIT_LIST_HEAD(&thp_pen_core->frame_list.list);
	init_waitqueue_head(&(thp_pen_core->frame_waitq));
	init_waitqueue_head(&(thp_pen_core->thp_ta_waitq));
	init_waitqueue_head(&(thp_pen_core->thp_event_waitq));
	init_waitqueue_head(&(thp_pen_core->suspend_resume_waitq));
	thp_pen_core->event_flag = false;
	thp_pen_core->suspend_resume_waitq_flag = WAITQ_WAKEUP;
	if (thp_pen_core->wait_afe_screen_on_support) {
		init_waitqueue_head(&(thp_pen_core->afe_screen_on_waitq));
		atomic_set(&(thp_pen_core->afe_screen_on_waitq_flag), WAITQ_WAKEUP);
		thp_log_info(thp_pen_core, "%s, init afe_screen_on_waitq done\n", __func__);
	}
	spi_set_drvdata(sdev, thp_pen_core);

	if (thp_pen_core->multi_panel_index == SUB_TOUCH_PANEL)
		g_thp_pen_core_sub = thp_pen_core;
	else
		g_thp_pen_core = thp_pen_core;

	thp_pen_core->thp_unregister_ic_num = 0;
	rc = thp_pen_thread_init(thp_pen_core);
	himax_pen_driver_module_init(thp_pen_core);
	thp_log_info(thp_pen_core, "%s:out\n", __func__);
	return 0;
}



static int thp_pen_remove(struct spi_device *sdev)
{
	struct thp_core_data *cd = spi_get_drvdata(sdev);
#if (IS_ENABLED(CONFIG_DRIVER_BRIGE) || defined(CONFIG_LCD_KIT_DRIVER))
	int rc;
#endif
	thp_log_info(cd, "%s: in\n", __func__);

	if (cd->use_thp_queue) {
		mutex_lock(&cd->mutex_frame);
		thp_pen_queue_free(cd, cd->thp_queue);
		mutex_unlock(&cd->mutex_frame);
	}
	if (atomic_read(&cd->register_flag)) {
		thp_sysfs_release(cd);
#ifndef CONFIG_ARCH_QTI_VM
#if ((defined THP_CHARGER_FB) && (!IS_ENABLED(CONFIG_HONOR_THP_QCOM)) && \
	(!IS_ENABLED (CONFIG_HONOR_THP_MTK)))
		if (cd->charger_detect_notify.notifier_call)
			honor_charger_type_notifier_unregister(
					&cd->charger_detect_notify);
#endif
#if ((defined THP_CHARGER_FB) && (IS_ENABLED(CONFIG_HONOR_THP_MTK)) || \
	(IS_ENABLED (CONFIG_HONOR_THP_QCOM)))
	if (cd->charger_detect_notify.notifier_call && cd->supported_charger) {
		rc = power_event_nc_unregister(POWER_NT_CONNECT,
				&cd->charger_detect_notify);
		if (rc)
			thp_log_err(cd, "%s:power_event_nc_unregister fail\n",
				__func__);
	}
#endif
#endif
		thp_pen_misc_exit(cd);
		mutex_destroy(&cd->mutex_frame);
		thp_mt_wrapper_exit(cd);
	}

	kfree(cd->frame_read_buf);
	kfree(cd->spi_sync_rx_buf);
	cd->spi_sync_rx_buf = NULL;

	kfree(cd->spi_sync_tx_buf);
	cd->spi_sync_tx_buf = NULL;

	kfree(cd);
	cd = NULL;

	return 0;
}

static const struct of_device_id g_thp_pen_match_table[] = {
	{ .compatible = "honor,thp_pen", },
	{ },
};

static const struct spi_device_id g_thp_pen_device_id[] = {
	{ THP_PEN_DEVICE_NAME, 0 },
	{ }
};
MODULE_DEVICE_TABLE(spi, g_thp_pen_device_id);

static struct spi_driver g_thp_pen_spi_driver = {
	.probe = thp_pen_probe,
	.remove = thp_pen_remove,
	.id_table = g_thp_pen_device_id,
	.driver = {
		.name = THP_PEN_DEVICE_NAME,
		.owner = THIS_MODULE,
		.bus = &spi_bus_type,
		.of_match_table = g_thp_pen_match_table,
	},
};

int g_thp_pen_spi_init(void)
{
	struct thp_core_data *cd = NULL;
	int ret = 0;

	thp_log_info(cd, "%s called\n", __func__);
	ret = spi_register_driver(&g_thp_pen_spi_driver);
	if (ret != 0)
		thp_log_err(cd, "spi3 register driver failed!");

	thp_log_info(cd, "%s end\n", __func__);
	return ret;
}
EXPORT_SYMBOL(g_thp_pen_spi_init);

void g_thp_pen_spi_exit(void)
{
	spi_unregister_driver(&g_thp_pen_spi_driver);
}
EXPORT_SYMBOL(g_thp_pen_spi_exit);

