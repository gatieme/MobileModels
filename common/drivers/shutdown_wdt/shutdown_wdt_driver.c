/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2022. All rights reserved.
 * Description: Monitoring the Shutdown Process Using the Watchdog
 * Author: dongjunfeng
 * Create: 2022-07-03
 */

/* ---- includes ---- */
#include <linux/device.h>
#include <linux/errno.h>
#include <linux/miscdevice.h>
#include <linux/platform_device.h>
#include <linux/fs.h>
#include <linux/ioport.h>
#include <linux/io.h>
#include <linux/uaccess.h>
#include <linux/syscalls.h>
#include <linux/kthread.h>
#include <linux/vmalloc.h>
#include <linux/delay.h>
#include <linux/semaphore.h>
#include <linux/statfs.h>
#include <linux/version.h>
#include <trace/hooks/qcom_wdg.h>

/* ---- local macroes ---- */
#define HW_SHUTDOWN_WDT_DEV_NAME "hw_shutdown_watchdog"

#define HW_SHUTDOWN_WDT_IOCTL_BASE 'W'
#define HW_SHUTDOWN_WDT_ENABLE_IOCTRL _IOW(HW_SHUTDOWN_WDT_IOCTL_BASE, 1, int)

static int g_shutdown_wdt_enable = 0;

static long hw_shutdown_wdt_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	long ret = 0;

	switch (cmd) {
	case HW_SHUTDOWN_WDT_ENABLE_IOCTRL:
		if (g_shutdown_wdt_enable == 1) {
			printk(KERN_ERR "shutdown_wdt_ioctl shutdown_wdt has enabled! \n");
			return ret;
		}
		trace_android_vh_qwdt_pet_stop(NULL);
		printk(KERN_ERR "shutdown_wdt_ioctl qwdt_pet_stop OK \n");
		g_shutdown_wdt_enable = 1;
		break;

	default:
		printk(KERN_ERR "shutdown_wdt_ioctl Invalid CMD: 0x%x\n", cmd);
		ret = -EFAULT;
		break;
	}

	return ret;
}

static int hw_shutdown_wdt_open(struct inode *inode, struct file *file)
{
	return nonseekable_open(inode, file);
}

static ssize_t hw_shutdown_wdt_read(struct file *file,
	char __user *buf,
	size_t count,
	loff_t *pos)
{
	return count;
}


static ssize_t hw_shutdown_wdt_write(struct file *file,
	const char *data,
	size_t len,
	loff_t *ppos)
{
	return len;
}

static const struct file_operations hw_shutdown_wdt_fops = {
	.owner	 = THIS_MODULE,
	.unlocked_ioctl = hw_shutdown_wdt_ioctl,
#ifdef CONFIG_COMPAT
	.compat_ioctl = hw_shutdown_wdt_ioctl,
#endif
	.open = hw_shutdown_wdt_open,
	.read = hw_shutdown_wdt_read,
	.write = hw_shutdown_wdt_write,
};

static struct miscdevice hw_shutdown_wdt_miscdev = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = HW_SHUTDOWN_WDT_DEV_NAME,
	.fops = &hw_shutdown_wdt_fops,
};

int __init hw_shutdown_wdt_init(void)
{
	int ret;

	ret = misc_register(&hw_shutdown_wdt_miscdev);
	if (ret != 0) {
		printk(KERN_ERR "misc_register hw_shutdown_watchdog failed, ret: %d.\n", ret);
		return ret;
	}

	return 0;
}

static void __exit hw_shutdown_wdt_exit(void)
{
	printk(KERN_ERR "hw_shutdown_wdt_exit Enter.\n");
}


module_init(hw_shutdown_wdt_init);
module_exit(hw_shutdown_wdt_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("huawei");
MODULE_DESCRIPTION("enable shutdown watchdog monitor");