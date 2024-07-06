/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: display engine channel source file
 * Author: zouzhiting <zouzhiting@huawei.com>
 * Create: 2023-05-18
 */

#include "display_engine_channel.h"

#include <linux/err.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/io.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/slab.h>
#include <linux/types.h>
#include <linux/uaccess.h>

#include "contexthub_boot.h"
#include "contexthub_ext_log.h"
#include "contexthub_recovery.h"
#include "sensor_info.h"
#include <securec.h>

#include <platform_include/smart/linux/base/ap/protocol.h>

enum de_data_head_index {
	DATA_IDX_SIZE = 0,
	DATA_IDX_CMD_TYPE,
	DATA_IDX_PANEL_ID,
	DATA_IDX_MAX,
};

enum de_panel_id {
	PANEL_INVALID = -1,
	PANEL_INNER,
	PANEL_OUTER,
	PANEL_COUNT,
};

static struct display_engine_common_data* g_immutable_data[PANEL_COUNT];
static struct display_engine_common_data* g_mutable_data[PANEL_COUNT];
static struct display_engine_common_data* g_status_data = NULL;

static void display_engine_init_data_table(void)
{
	int i;

	for (i = 0; i < PANEL_COUNT; i++) {
		g_immutable_data[i] = NULL;
		g_mutable_data[i] = NULL;
	}
}

static int display_engine_send_cmd_to_sensorhub(struct write_info *wr,
	struct read_info *rd, bool is_lock)
{
	return write_customize_cmd(wr, rd, is_lock);
}

static int display_effect_send_to_sensorhub(int cmd, const void *buf, uint32_t length)
{
	int ret = 0;
	struct write_info pkg_ap;

	ret = memset_s(&pkg_ap, sizeof(pkg_ap), 0, sizeof(pkg_ap));
	if (ret != EOK) {
		hwlog_err("memset_s failed, ret = %d\n", ret);
		return ret;
	}
	pkg_ap.tag = TAG_DISPLAY_ENGINE;
	pkg_ap.cmd = cmd;
	pkg_ap.wr_buf = buf;
	pkg_ap.wr_len = length;
	ret = display_engine_send_cmd_to_sensorhub(&pkg_ap, NULL, true);
	if (ret)
		hwlog_err("%s fail,ret=%d\n", __func__, ret);
	return ret;
}

static int display_engine_copy_immutable_data(uint32_t *head, const void __user *argp)
{
	uint32_t panel_id = head[DATA_IDX_PANEL_ID];
	uint32_t length = head[DATA_IDX_SIZE];

	if (!g_immutable_data[panel_id])
		g_immutable_data[panel_id] = kzalloc(length, GFP_KERNEL);

	if (!g_immutable_data[panel_id]) {
		hwlog_err("kzalloc failed\n");
		return -EINVAL;
	}

	if (copy_from_user(g_immutable_data[panel_id], argp, length)) {
		hwlog_err("copy_from_user failed\n");
		return -EINVAL;
	}

	return EOK;
}

static int display_engine_set_immutable_param(uint32_t *head, const void __user *argp)
{
	int ret = 0;
	hwlog_info("%s IOCFG_TYPE_IMMUTABLE_PARAM\n", __func__);
	ret = display_engine_copy_immutable_data(head, argp);
	if (ret)
		return -EINVAL;
	ret = display_effect_send_to_sensorhub(CMD_CMN_CONFIG_REQ,
		g_immutable_data[head[DATA_IDX_PANEL_ID]],
		g_immutable_data[head[DATA_IDX_PANEL_ID]]->size);
	return ret;
}

static int display_engine_copy_mutable_data(uint32_t *head, const void __user *argp)
{
	uint32_t panel_id = head[DATA_IDX_PANEL_ID];
	uint32_t length = head[DATA_IDX_SIZE];

	if (!g_mutable_data[panel_id])
		g_mutable_data[panel_id] = kzalloc(length, GFP_KERNEL);

	if (!g_mutable_data[panel_id]) {
		hwlog_err("kzalloc failed\n");
		return -EINVAL;
	}

	if (copy_from_user(g_mutable_data[panel_id], argp, length)) {
		hwlog_err("copy_from_user failed\n");
		return -EINVAL;
	}

	return EOK;
}

static int display_engine_set_mutable_param(uint32_t *head, const void __user *argp)
{
	int ret = 0;
	hwlog_info("%s IOCFG_TYPE_MUTABLE_PARAM\n", __func__);
	ret = display_engine_copy_mutable_data(head, argp);
	if (ret)
		return -EINVAL;
	ret = display_effect_send_to_sensorhub(CMD_CMN_CONFIG_REQ,
		g_mutable_data[head[DATA_IDX_PANEL_ID]],
		g_mutable_data[head[DATA_IDX_PANEL_ID]]->size);
	return ret;
}

static int display_engine_copy_status_data(const void __user *argp, uint32_t length)
{
	if (length <= sizeof(struct display_engine_common_data)) {
		hwlog_err("input length %u invalid, expected at least size %u\n", length,
			(sizeof(uint32_t) * DATA_IDX_MAX));
		return -EINVAL;
	}
	if (!g_status_data)
		g_status_data = kzalloc(length, GFP_KERNEL);

	if (copy_from_user(g_status_data, argp, length)) {
		hwlog_err("copy_from_user failed\n");
		return -EINVAL;
	}

	return EOK;
}

static int display_engine_set_status_param(unsigned int cmd, const void __user *argp)
{
	int ret = 0;
	uint32_t length = 0;

	hwlog_info("%s IOCFG_TYPE_STATUS_PARAM\n", __func__);
	if (!argp) {
		hwlog_err("%s argp NULL Pointer!\n", __func__);
		return -EINVAL;
	}
	if (copy_from_user(&length, argp, sizeof(uint32_t))) {
		hwlog_warn("display_engine:%s copy_from_user failed\n", __func__);
		return -EFAULT;
	}

	ret = display_engine_copy_status_data(argp, length);
	if (ret)
		return -EINVAL;
	ret = display_effect_send_to_sensorhub(CMD_CMN_CONFIG_REQ, g_status_data, length);
	return ret;
}

static int display_engine_data_check(uint32_t *head, const void __user *argp)
{
	uint32_t length = 0;
	int32_t panel_id = -1;
	int32_t cmd_type = -1;

	hwlog_info("%s +\n", __func__);
	if (!argp) {
		hwlog_err("%s argp NULL Pointer!\n", __func__);
		return -EINVAL;
	}
	if (!head) {
		hwlog_err("%s head NULL Pointer!\n", __func__);
		return -EINVAL;
	}
	if (copy_from_user(head, argp, sizeof(uint32_t) * DATA_IDX_MAX)) {
		hwlog_warn("%s copy head data failed\n", __func__);
		return -EFAULT;
	}

	length = head[DATA_IDX_SIZE];
	if (length <= (sizeof(uint32_t) * DATA_IDX_MAX)) {
		hwlog_err("%s invalid length %u, expect length at least %u size\n", __func__,
			length, sizeof(uint32_t) * (DATA_IDX_MAX + 1));
		return -EINVAL;
	}

	cmd_type = head[DATA_IDX_CMD_TYPE];
	if (cmd_type <= IOCFG_TYPE_INVALID || cmd_type >= IOCFG_TYPE_MAX) {
		hwlog_err("%s cmd_type invalid\n", __func__);
		return -EINVAL;
	}

	panel_id = head[DATA_IDX_PANEL_ID];
	if (panel_id <= PANEL_INVALID || panel_id >= PANEL_COUNT) {
		hwlog_err("%s panel_id invalid\n", __func__);
		return -EINVAL;
	}
	hwlog_info("%s length:%u, cmd_type:%d, panel id:%d\n", __func__, length, cmd_type,
		panel_id);
	return EOK;
}

static int display_engine_set_effect_param(unsigned int cmd, const void __user *argp)
{
	int ret = 0;
	uint32_t head[DATA_IDX_MAX] = {0, -1, -1};

	hwlog_info("%s +\n", __func__);
	if (display_engine_data_check(head, argp))
		return -EINVAL;

	switch (head[DATA_IDX_CMD_TYPE]) {
	case IOCFG_TYPE_IMMUTABLE_PARAM:
		ret = display_engine_set_immutable_param(head, argp);
		break;
	case IOCFG_TYPE_MUTABLE_PARAM:
		ret = display_engine_set_mutable_param(head, argp);
		break;
	default:
		hwlog_err("%s invalid cmd_type %u\n", __func__, head[DATA_IDX_CMD_TYPE]);
		break;
	}
	hwlog_info("%s -\n", __func__);
	return ret;
}

/*
 * Description:    read /dev/xxx
 * Return:         length of read data
 */
static ssize_t display_engine_read(struct file *file, char __user *buf,
	size_t count, loff_t *pos)
{
	hwlog_info("display_engine: enter %s\n", __func__);
	return 0;
}

/*
 * Description:    write to /dev/xxx, do nothing now
 * Return:         length of write data
 */
static ssize_t display_engine_write(struct file *file, const char __user *data,
	size_t len, loff_t *ppos)
{
	hwlog_info("display_engine: enter %s\n", __func__);
	return len;
}

/*
 * Description:    open to /dev/xxx
 * Return:         result 0 successed
 */
static int display_engine_open(struct inode *inode, struct file *file)
{
	hwlog_info("display_engine: enter %s\n", __func__);
	return 0;
}

/*
 * Description:    ioctrl function to /dev/xxx, do open,
 *                 close ca, or set interval and attribute to xxx
 * Return:         result of ioctrl command, 0 successed, -ENOTTY failed
 */
static long display_engine_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	int ret = 0;
	void __user *argp = (void __user *)(uintptr_t)arg;

	hwlog_info("display_engine: enter %s\n", __func__);
	switch (cmd) {
	case DEHB_IOCTL_DEHB_DEBUG_CMD:
		hwlog_info("display_engine:%s cmd: DEHB_IOCTL_DEHB_DEBUG_CMD\n", __func__);
		break;
	case DEHB_IOCTL_DEHB_CONFIG_CMD:
		hwlog_info("display_engine:%s cmd: DEHB_IOCTL_DEHB_CONFIG_CMD\n", __func__);
		ret = display_engine_set_effect_param(cmd, argp);
		break;
	case DEHB_IOCTL_DEHB_OPEN_CMD:
		hwlog_info("display_engine:%s set cmd : DEHB_IOCTL_DEHB_OPEN_CMD\n", __func__);
		break;
	case DEHB_IOCTL_DEHB_CLOSE_CMD:
		hwlog_info("display_engine:%s set cmd : DEHB_IOCTL_DEHB_CLOSE_CMD\n",
			__func__);
		break;
	case DEHB_IOCTL_DEHB_STATUS_CMD:
		hwlog_info("display_engine:%s set cmd : DEHB_IOCTL_DEHB_STATUS_CMD\n",
			__func__);
		ret = display_engine_set_status_param(cmd, argp);
		break;
	default:
		hwlog_err("display_engine:%s unknown cmd : %d\n", __func__, cmd);
		return -ENOTTY;
	}
	return ret;
}

static int resend_effect_when_recovery_iom3()
{
	int ret = 0;
	int i;

	hwlog_info("display_engine:%s\n", __func__);
	for (i = 0; i < PANEL_COUNT; i++) {
		if (!g_immutable_data[i])
			continue;
		ret = display_effect_send_to_sensorhub(
			CMD_CMN_CONFIG_REQ, g_immutable_data[i], g_immutable_data[i]->size);
		hwlog_info("display_engine:%s immutable data, panel_id:%d\n", __func__, i);
	}
	for (i = 0; i < PANEL_COUNT; i++) {
		if (!g_mutable_data[i])
			continue;
		ret = display_effect_send_to_sensorhub(
			CMD_CMN_CONFIG_REQ, g_mutable_data[i], g_mutable_data[i]->size);
		hwlog_info("display_engine:%s mutable data, panel_id:%d\n", __func__, i);
	}
	if (g_status_data)
		ret = display_effect_send_to_sensorhub(CMD_CMN_CONFIG_REQ, g_status_data,
			g_status_data->size);
	return ret;
}

static int display_engine_recovery_notifier(struct notifier_block *nb,
	unsigned long foo, void *bar)
{
	/* prevent access the emmc now: */
	hwlog_info("%s %lu enter\n", __func__, foo);
	switch (foo) {
	case IOM3_RECOVERY_IDLE:
	case IOM3_RECOVERY_START:
	case IOM3_RECOVERY_MINISYS:
	case IOM3_RECOVERY_3RD_DOING:
	case IOM3_RECOVERY_FAILED:
		break;
	case IOM3_RECOVERY_DOING:
		resend_effect_when_recovery_iom3();
		break;
	default:
		hwlog_err("%s -unknow state %ld\n", __func__, foo);
		break;
	}
	hwlog_info("%s out\n", __func__);
	return 0;
}

static struct notifier_block display_engine_recovery_notify = {
	.notifier_call = display_engine_recovery_notifier,
	.priority = -1,
};

/* file_operations to display_engine_hub */
static const struct file_operations display_engine_fops = {
	.owner             = THIS_MODULE,
	.read              = display_engine_read,
	.write             = display_engine_write,
	.unlocked_ioctl    = display_engine_ioctl,
#ifdef CONFIG_COMPAT
	.compat_ioctl      = display_engine_ioctl,
#endif
	.open              = display_engine_open,
};

/* miscdevice to display_engine_hub */
static struct miscdevice display_engine_hub_miscdev = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "display_engine_hub",
	.fops = &display_engine_fops,
};

/*
* Description:	apply kernel buffer, register display_engine_hub_miscdev
* Return: 		result of function, 0 successed, else false
*/
static int __init display_engine_hub_init(void)
{
	int ret;

	if (is_sensorhub_disabled())
		return -1;

	ret = inputhub_route_open(ROUTE_DE_PORT);
	if (ret != 0) {
		hwlog_err("display_engine: %s cannot open inputhub route err=%d\n",
			__func__, ret);
		return ret;
	}

	ret = misc_register(&display_engine_hub_miscdev);
	if (ret != 0) {
		hwlog_err("%s cannot register miscdev err=%d\n", __func__, ret);
		inputhub_route_close(ROUTE_DE_PORT);
		return ret;
	}
	display_engine_init_data_table();
	register_iom3_recovery_notifier(&display_engine_recovery_notify);
	hwlog_info("%s ok\n", __func__);

	return ret;
}

/* release kernel buffer, deregister display_engine_miscdev */
static void __exit display_engine_hub_exit(void)
{
	inputhub_route_close(ROUTE_DE_PORT);
	misc_deregister(&display_engine_hub_miscdev);
	hwlog_info("exit %s\n", __func__);
}

late_initcall_sync(display_engine_hub_init);
module_exit(display_engine_hub_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("DisplayEngine driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
