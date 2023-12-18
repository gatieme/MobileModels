/*
 * ulog_trace.c
 *
 * trace adsp log
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

#include <linux/slab.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/uaccess.h>
#include <linux/completion.h>
#include <linux/workqueue.h>
#include <linux/debugfs.h>
#include <linux/timex.h>
#include <linux/device.h>
#include <linux/miscdevice.h>
#include <linux/of.h>
#include <linux/syscalls.h>
#include <log/log_usertype.h>
#include <linux/platform_device.h>
#include <linux/soc/qcom/pmic_glink.h>
#include <huawei_platform/log/hw_log.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <chipset_common/hwpower/common_module/power_cmdline.h>
#include <chipset_common/hwpower/charger/charger_common_interface.h>
#include "ulog_file.h"

#if IS_ENABLED(HWLOG_TAG)
#undef HWLOG_TAG
#endif
#define HWLOG_TAG ulog_trace
HWLOG_REGIST();

#define UTRACE_GLINK_OWNER          32785
#define UTRACE_TYPE_REQ_RESP        1
#define UTRACE_GET_ULOG_REQ         0x0018
#define UTRACE_SET_LOGGING_PROP_REQ 0x0019
#define UTRACE_WAIT_TIME_MS         1000
#define UTRACE_MAX_GET_LOG_SIZE     8192
#define UTRACE_DEF_PERIOD           10
#define USB_AND_CHARGE_CATEGORIES   0xFFFFFFFF

#define UTRACE_BETA_FILE_PATH_1     "/hw_product/region_comm/china/log_collect_service_beta.xml"
#define UTRACE_BETA_FILE_PATH_2     "/system/etc/log_collect_service_beta.xml"

enum {
	TRACE_ONCE = 0,
	TRACE_PERIOD,
};

enum {
	TRACE_STOP = 0,
	TRACE_START,
};

static struct utrace_device *g_utrace_dev;

struct utrace_device {
	struct device *dev;
	u32 run;
	u32 mode;
	u32 level;
	u32 period;
	u64 categories;
	u32 set_prop_result;
	struct dentry *root;
	struct pmic_glink_client *client;
	struct completion wait_rsp;
	struct mutex lock;
	struct delayed_work trace_work;
	u32 ulog_size;
	char ulog_buffer[UTRACE_MAX_GET_LOG_SIZE + 1];
	struct ulog_file ufile;
	struct notifier_block event_nb;
	bool charger_online;
};

struct utrace_ulog_prop_req_msg {
	struct pmic_glink_hdr hdr;
	u64 categories;
	u32 level;
};

struct utrace_ulog_prop_rsp_msg {
	struct pmic_glink_hdr hdr;
	u32 result;
};

struct utrace_ulog_req_msg {
	struct pmic_glink_hdr hdr;
	u32 max_log_size;
};

struct utrace_ulog_rsp_msg {
	struct pmic_glink_hdr hdr;
	char read_buffer[UTRACE_MAX_GET_LOG_SIZE];
};

static int utrace_glink_sync_write(struct utrace_device *di, void *data, size_t len)
{
	int rc;

	mutex_lock(&di->lock);
	reinit_completion(&di->wait_rsp);
	rc = pmic_glink_write(di->client, data, len);
	if (!rc) {
		rc = wait_for_completion_timeout(&di->wait_rsp,
			msecs_to_jiffies(UTRACE_WAIT_TIME_MS));
		if (!rc) {
			hwlog_err("error, timed out sending message\n");
			mutex_unlock(&di->lock);
			return -ETIMEDOUT;
		}

		rc = 0;
	}
	mutex_unlock(&di->lock);

	return rc;
}

static int utrace_set_ulog_prop(struct utrace_device *di)
{
	int rc;
	struct utrace_ulog_prop_req_msg msg = { 0 };

	msg.hdr.owner = UTRACE_GLINK_OWNER;
	msg.hdr.type = UTRACE_TYPE_REQ_RESP;
	msg.hdr.opcode = UTRACE_SET_LOGGING_PROP_REQ;
	msg.categories = di->categories;
	msg.level = di->level;

	rc = utrace_glink_sync_write(di, &msg, sizeof(msg));
	if (!rc)
		rc = di->set_prop_result;

	return rc;
}

static void utrace_proc_ulog_prop_rsp(struct utrace_device *di,
	struct utrace_ulog_prop_rsp_msg *msg, size_t len)
{
	if (len != sizeof(*msg)) {
		hwlog_err("expected data length: %zu, received: %zu\n",
			sizeof(*msg), len);
		return;
	}

	hwlog_info("set ulog prop result=%u\n", msg->result);
	di->set_prop_result = msg->result;
	complete(&di->wait_rsp);
}

static int utrace_req_ulog(struct utrace_device *di)
{
	struct utrace_ulog_req_msg msg = { 0 };

	msg.hdr.owner = UTRACE_GLINK_OWNER;
	msg.hdr.type = UTRACE_TYPE_REQ_RESP;
	msg.hdr.opcode = UTRACE_GET_ULOG_REQ;
	msg.max_log_size = UTRACE_MAX_GET_LOG_SIZE;

	return utrace_glink_sync_write(di, &msg, sizeof(msg));
}

static void utrace_proc_req_ulog_rsp(struct utrace_device *di,
	struct utrace_ulog_rsp_msg *msg, size_t len)
{
	if (len != sizeof(*msg)) {
		hwlog_err("expected data length: %zu, received: %zu\n",
			sizeof(*msg), len);
		return;
	}

	memcpy(di->ulog_buffer, msg->read_buffer, sizeof(msg->read_buffer));
	di->ulog_size = strlen(di->ulog_buffer);
	hwlog_debug("get ulog success size =%u\n", di->ulog_size);
	complete(&di->wait_rsp);
}

static int utrace_glink_callback(void *priv, void *data, size_t len)
{
	struct pmic_glink_hdr *hdr = data;
	struct utrace_device *di = priv;

	hwlog_debug("owner: %u type: %u opcode: %#x len: %zu\n", hdr->owner,
		hdr->type, hdr->opcode, len);

	switch (hdr->opcode) {
	case UTRACE_GET_ULOG_REQ:
		utrace_proc_req_ulog_rsp(di, data, len);
		break;
	case UTRACE_SET_LOGGING_PROP_REQ:
		utrace_proc_ulog_prop_rsp(di, data, len);
		break;
	default:
		hwlog_err("unknown opcode %u\n", hdr->opcode);
		break;
	}

	return 0;
}

static int utrace_mode_set(void *data, u64 val)
{
	struct utrace_device *di = data;

	hwlog_info("%s: set trace mode to %llu\n", __func__, val);
	if (di->mode == val)
		return 0;

	di->mode = val;
	if (di->mode == TRACE_PERIOD)
		queue_delayed_work(system_power_efficient_wq, &di->trace_work, 0);
	else
		cancel_delayed_work(&di->trace_work);

	return 0;
}

static int utrace_mode_get(void *data, u64 *val)
{
	struct utrace_device *di = data;

	*val = di->mode;
	return 0;
}

DEFINE_DEBUGFS_ATTRIBUTE(utrace_mode_fops,
	utrace_mode_get, utrace_mode_set, "%llu\n");

static int utrace_period_set(void *data, u64 val)
{
	struct utrace_device *di = data;

	hwlog_info("%s: set trace period to %llu\n", __func__, val);
	di->period = val;
	return 0;
}

static int utrace_period_get(void *data, u64 *val)
{
	struct utrace_device *di = data;

	*val = di->period;
	return 0;
}

DEFINE_DEBUGFS_ATTRIBUTE(utrace_period_fops,
	utrace_period_get, utrace_period_set, "%llu\n");

static int utrace_categories_set(void *data, u64 val)
{
	struct utrace_device *di = data;

	hwlog_info("%s: set trace categories to %llu\n", __func__, val);
	if (di->categories == val)
		return 0;

	di->categories = val;
	utrace_set_ulog_prop(di);
	return 0;
}

static int utrace_categories_get(void *data, u64 *val)
{
	struct utrace_device *di = data;

	*val = di->categories;
	return 0;
}

DEFINE_DEBUGFS_ATTRIBUTE(utrace_categories_fops,
	utrace_categories_get, utrace_categories_set, "%llu\n");

static int utrace_level_set(void *data, u64 val)
{
	struct utrace_device *di = data;

	if (val > 5) /* 5: all logs */
		return -EINVAL;

	hwlog_info("%s: set trace level to %llu\n", __func__, val);
	if (di->level == val)
		return 0;

	di->level = val;
	utrace_set_ulog_prop(di);
	return 0;
}

static int utrace_level_get(void *data, u64 *val)
{
	struct utrace_device *di = data;

	*val = di->level;
	return 0;
}

DEFINE_DEBUGFS_ATTRIBUTE(utrace_level_fops,
	utrace_level_get, utrace_level_set, "%llu\n");

static int utrace_log_open(struct inode *inode, struct file *file)
{
	int ret = 0;
	struct utrace_device *di = inode->i_private;

	memset(di->ulog_buffer, 0, sizeof(di->ulog_buffer));
	di->ulog_size = 0;
	ret = utrace_req_ulog(di);
	if (ret) {
		hwlog_err("%s ret=%d\n", __func__, ret);
		return ret;
	}

	get_device(di->dev);
	file->private_data = di;

	hwlog_info("%s\n", __func__);
	return ret;
}

static int utrace_log_close(struct inode *inode, struct file *file)
{
	struct utrace_device *di = file->private_data;

	memset(di->ulog_buffer, 0, sizeof(di->ulog_buffer));
	di->ulog_size = 0;
	put_device(di->dev);
	hwlog_info("%s\n", __func__);
	return 0;
}

static ssize_t utrace_log_read(struct file *file, char __user *buf,
	size_t n, loff_t *ppos)
{
	loff_t pos = *ppos;
	size_t ret;
	struct utrace_device *di = file->private_data;

	if (pos < 0)
		return -EINVAL;
	if ((di->ulog_size == 0) || (pos >= di->ulog_size) || !n)
		return 0;

	if (n > (di->ulog_size - pos))
		n = di->ulog_size - pos;

	ret = copy_to_user(buf, di->ulog_buffer, n);
	if (ret == n)
		return -EFAULT;

	n -= ret;
	*ppos = pos + n;
	return n;
}

static int utrace_open(struct inode *inode, struct file *file)
{
	if (!g_utrace_dev) {
		hwlog_info("%s:NULL pointerr", __func__);
		return -EFAULT;
	}

	memset(g_utrace_dev->ulog_buffer, 0, sizeof(g_utrace_dev->ulog_buffer));
	g_utrace_dev->ulog_size = 0;
	if (utrace_req_ulog(g_utrace_dev))
		return -EFAULT;

	get_device(g_utrace_dev->dev);

	return 0;
}

static int utrace_write(unsigned int cmd, unsigned long arg)
{
	int ret = 0;

	switch (cmd & IOCTL_ULOGTRACE_PARA) {
	case IOCTL_ULOGTRACE_MODE:
		g_utrace_dev->mode = arg;
		if (g_utrace_dev->mode == TRACE_PERIOD)
			queue_delayed_work(system_power_efficient_wq,
				&g_utrace_dev->trace_work, 0);
		else
			cancel_delayed_work(&g_utrace_dev->trace_work);
		break;
	case IOCTL_ULOGTRACE_LEVEL:
		g_utrace_dev->level = arg;
		utrace_set_ulog_prop(g_utrace_dev);
		break;
	case IOCTL_ULOGTRACE_PERIOD:
		g_utrace_dev->period = arg;
		break;
	case IOCTL_ULOGTRACE_CATEGORIES:
		g_utrace_dev->categories = arg;
		utrace_set_ulog_prop(g_utrace_dev);
		break;
	default:
		ret = -1;
		hwlog_err("%s:utrace para not support", __func__);
		break;
	}
	return ret;
}

static int utrace_read(unsigned int cmd, unsigned long arg)
{
	u64 value;

	switch (cmd & IOCTL_ULOGTRACE_PARA) {
	case IOCTL_ULOGTRACE_LEVEL:
		value = g_utrace_dev->level;
		break;
	case IOCTL_ULOGTRACE_MODE:
		value = g_utrace_dev->mode;
		break;
	case IOCTL_ULOGTRACE_PERIOD:
		value = g_utrace_dev->period;
		break;
	case IOCTL_ULOGTRACE_CATEGORIES:
		value = g_utrace_dev->categories;
		break;
	default:
		hwlog_err("%s:utrace para not support", __func__);
		break;
	}
	copy_to_user((u64 *)(uintptr_t)arg, &value, sizeof(value));
	return 0;
}

static long utrace_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	if (!g_utrace_dev) {
		hwlog_info("%s: g_utrace_dev is NULL", __func__);
		return -EFAULT;
	}

	if ((cmd & IOCTL_ULOGTRACE_CMD) == IOCTL_ULOGTRACE_WRITE) {
		if (utrace_write(cmd, arg) != 0) {
			hwlog_info("%s: utrace write failed", __func__);
			return -EFAULT;
		}
	}

	if ((cmd & IOCTL_ULOGTRACE_CMD) == IOCTL_ULOGTRACE_READ) {
		if (utrace_read(cmd, arg) != 0) {
			hwlog_info("%s: utrace read failed", __func__);
			return -EFAULT;
		}
	}
	return 0;
}

static int utrace_close(struct inode *inode, struct file *file)
{
	return 0;
}

static loff_t utrace_log_lseek(struct file *file, loff_t off, int whence)
{
	loff_t pos = -1;
	struct utrace_device *di = file->private_data;

	switch (whence) {
	case SEEK_SET:
		pos = off;
		break;
	case SEEK_CUR:
		pos = file->f_pos + off;
		break;
	case SEEK_END:
		pos = di->ulog_size - off;
		break;
	default:
		hwlog_err("unknown whence value=%d\n", whence);
		return -EINVAL;
	}

	if ((pos < 0) || (pos > di->ulog_size))
		return -EINVAL;

	file->f_pos = pos;
	return pos;
}

static const struct file_operations utrace_log_data_fops = {
	.open = utrace_log_open,
	.release = utrace_log_close,
	.read = utrace_log_read,
	.llseek = utrace_log_lseek,
};

static const struct file_operations utrace_log_fops = {
	.owner = THIS_MODULE,
	.open = utrace_open,
	.release = utrace_close,
	.unlocked_ioctl = utrace_ioctl,
};

static struct miscdevice utrace_misc_dev = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "ulog_trace",
	.fops = &utrace_log_fops,
};

static void utrace_create_debugfs(struct utrace_device *udi)
{
	udi->root = debugfs_create_dir("ulog_trace", NULL);
	if (!udi->root) {
		hwlog_err("%s: create debugfs root node fail\n", __func__);
		return;
	}

	debugfs_create_file("mode", 0600, udi->root, udi, &utrace_mode_fops);
	debugfs_create_file("period", 0600, udi->root, udi, &utrace_period_fops);
	debugfs_create_file("categories", 0600, udi->root, udi, &utrace_categories_fops);
	debugfs_create_file("level", 0600, udi->root, udi, &utrace_level_fops);
	debugfs_create_file("log", 0400, udi->root, udi, &utrace_log_data_fops);
}

static void utrace_work(struct work_struct *work)
{
	int ret = 0;
	int charge_done_status = charge_get_done_type();
	struct utrace_device *di = container_of(work, struct utrace_device,
		trace_work.work);

	while (1) {
		memset(di->ulog_buffer, 0, sizeof(di->ulog_buffer));
		di->ulog_size = 0;
		ret = utrace_req_ulog(di);
		if (ret || (di->ulog_size == 0)) {
			hwlog_debug("%s ret=%d\n", __func__, ret);
			break;
		} else {
			ret = ulog_write(&di->ufile, di->ulog_buffer, di->ulog_size);
			if (ret) {
				hwlog_err("%s ulog write fail\n", __func__);
				return;
			}
		}
	}

	if (!power_cmdline_is_factory_mode() && (!di->charger_online || (charge_done_status == CHARGE_DONE)) &&
		(di->mode != TRACE_PERIOD)) {
		hwlog_info("stop utrace work, online=%d, status=%d\n",
			di->charger_online, charge_done_status);
		return;
	}

	queue_delayed_work(system_power_efficient_wq, &di->trace_work,
		msecs_to_jiffies(MSEC_PER_SEC * di->period));
}

static bool utrace_check_log_version(void)
{
	int ret;

	ret = ksys_access(UTRACE_BETA_FILE_PATH_1, 0);
	if (!ret) {
		hwlog_info("hw_product path access ok\n");
		return true;
	}

	ret = ksys_access(UTRACE_BETA_FILE_PATH_2, 0);
	if (!ret) {
		hwlog_info("system path access ok\n");
		return true;
	}
	return false;
}

static bool utrace_normal_boot_mode(void)
{
	if (power_cmdline_is_powerdown_charging_mode() ||
		power_cmdline_is_recovery_mode() ||
		power_cmdline_is_erecovery_mode()) {
		hwlog_info("current mode not support ulog trace\n");
		return false;
	}

	return true;
}

static bool utrace_start_mode_support(void)
{
	if (power_cmdline_is_factory_mode()) {
		hwlog_info("factory version, open adsp log\n");
		return true;
	}

	if (!utrace_check_log_version()) {
		hwlog_info("no log version\n");
		return false;
	}

	if (!utrace_normal_boot_mode())
		return false;

	return true;
}

static int utrace_charge_control(struct utrace_device *di, u64 status)
{
	hwlog_info("%s: set trace run mode to %llu\n", __func__, status);
	if (di->run == status)
		return 0;

	di->run = status;
	di->categories = USB_AND_CHARGE_CATEGORIES;
	if (di->run == TRACE_START) {
		di->period = 1;
		queue_delayed_work(system_power_efficient_wq, &di->trace_work, 0);
	} else {
		cancel_delayed_work_sync(&di->trace_work);
	}

	utrace_set_ulog_prop(di);

	return 0;
}

static int utrace_charge_notifier_call(struct notifier_block *nb,
	unsigned long event, void *data)
{
	struct utrace_device *di = g_utrace_dev;

	if (!di || power_cmdline_is_factory_mode())
		return NOTIFY_OK;

	switch (event) {
	case POWER_NE_CHARGING_STOP:
		di->charger_online = false;
		utrace_charge_control(di, TRACE_STOP);
		break;
	case POWER_NE_CHARGING_START:
		di->charger_online = true;
		utrace_charge_control(di, TRACE_START);
		break;
	default:
		return NOTIFY_OK;
	}

	hwlog_info("%s: receive event=%lu\n", __func__, event);

	return NOTIFY_OK;
}

static void utrace_charge_mode_log(struct utrace_device *di)
{
	int ret;

	di->charger_online = false;

	di->event_nb.notifier_call = utrace_charge_notifier_call;
	ret = power_event_bnc_register(POWER_BNT_CHARGING, &di->event_nb);
	if (ret)
		hwlog_err("%s: charge notify register failed", __func__);
}

static int utrace_probe(struct platform_device *pdev)
{
	int rc;
	struct utrace_device *udi = NULL;
	struct pmic_glink_client_data client_data = { 0 };

	if (!utrace_start_mode_support())
		return 0;

	udi = devm_kzalloc(&pdev->dev, sizeof(*udi), GFP_KERNEL);
	if (!udi)
		return -ENOMEM;

	udi->dev = &pdev->dev;
	client_data.id = UTRACE_GLINK_OWNER;
	client_data.name = "ulog_trace";
	client_data.msg_cb = utrace_glink_callback;
	client_data.priv = udi;

	udi->client = pmic_glink_register_client(udi->dev, &client_data);
	if (IS_ERR(udi->client)) {
		rc = PTR_ERR(udi->client);
		if (rc != -EPROBE_DEFER)
			hwlog_err("error in registering with pmic_glink %d\n", rc);
		return rc;
	}

	udi->categories = 0xFFFFFFFF;
	udi->level = 3; /* info */
	udi->period = UTRACE_DEF_PERIOD;
	init_completion(&udi->wait_rsp);
	mutex_init(&udi->lock);
	INIT_DELAYED_WORK(&udi->trace_work, utrace_work);
	ulog_init(&udi->ufile);
	platform_set_drvdata(pdev, udi);
	utrace_charge_mode_log(udi);

	g_utrace_dev = udi;
	if (power_cmdline_is_factory_mode()) {
		udi->period = 2; /* unit seconds */
		utrace_set_ulog_prop(udi);
		queue_delayed_work(system_power_efficient_wq, &udi->trace_work, 0);
	}
#ifndef DBG_ULOG_TRACE
	return 0;
#endif /* DBG_ULOG_TRACE */

	utrace_create_debugfs(udi);
	if (misc_register(&utrace_misc_dev) != 0) {
		hwlog_err("%s: misc register failed", __func__);
		goto exit;
	}

	return 0;

exit:
	debugfs_remove_recursive(udi->root);
	pmic_glink_unregister_client(udi->client);
	udi->root = NULL;
	g_utrace_dev = NULL;

	return -ENODEV;
}

static int utrace_remove(struct platform_device *pdev)
{
	struct utrace_device *di = platform_get_drvdata(pdev);

	if (!di)
		return 0;

	debugfs_remove_recursive(di->root);
	pmic_glink_unregister_client(di->client);
	power_event_bnc_unregister(POWER_BNT_CHARGING, &di->event_nb);

	di->root = NULL;
	return 0;
}

static const struct of_device_id utrace_match_table[] = {
	{ .compatible = "huawei,ulog_glink_trace" },
	{},
};

static struct platform_driver utrace_driver = {
	.driver = {
		.name = "ulog_trace",
		.owner = THIS_MODULE,
		.of_match_table = utrace_match_table,
	},
	.probe = utrace_probe,
	.remove = utrace_remove,
};
module_platform_driver(utrace_driver);

MODULE_LICENSE("GPL v2");
MODULE_IMPORT_NS(VFS_internal_I_am_really_a_filesystem_and_am_NOT_a_driver);
MODULE_DESCRIPTION("huawei ulog trace driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
