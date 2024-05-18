/*
  * boot time implementation
  *
  * Copyright (c) 2021-2021 Honor Technologies Co., Ltd.
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

#include <linux/device.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/platform_device.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>
#include <linux/sched/clock.h>
#include <linux/seq_file.h>
#include <linux/types.h>
#include <linux/uaccess.h>
#include <linux/wait.h>

#define BOOT_STR_SIZE 128
#define BOOT_LOG_NUM 256
#define BOOT_50_MS 50000
unsigned int sbl1_time = 0;
unsigned int lk_time = 0;
unsigned int uefi_time = 0; //ms

#define BOOTUP_DONE "[INFOR]_wm_boot_animation_done"
struct boot_log_struct
{
	u32 Second;
	u32 mSecond;
	char event[BOOT_STR_SIZE];
} boottime[BOOT_LOG_NUM];

int boot_log_count = 0;
static DEFINE_MUTEX(boottime_lock);
static int boottime_enabled = 1;

void log_boot(char *str);

int __init_or_module do_boottime_initcall(initcall_t fn)
{
	int ret;
	unsigned long long duration;
	ktime_t calltime, delta, rettime;
	char log_info[BOOT_STR_SIZE] = {0};

	calltime = ktime_get();
	ret = fn();
	rettime = ktime_get();
	delta = ktime_sub(rettime, calltime);
	duration = (unsigned long long) ktime_to_ns(delta) >> 10;
	if(duration > BOOT_50_MS) {
		printk(KERN_DEBUG "initcall %pS returned %d after %lld usecs\n",
				fn, ret, duration);
		snprintf(log_info, sizeof(log_info), "[WARNING] %pS %lld usecs", fn, duration);
		log_boot(log_info);
	}
	return ret;
}

EXPORT_SYMBOL(do_boottime_initcall);

static long long Second(unsigned long long nsec, unsigned long divs)
{
	if ((long long)nsec < 0) {
		nsec = -nsec;/*lint !e501 */
		do_div(nsec, divs);
		return -nsec;/*lint !e501 */
	}
	do_div(nsec, divs);
	return nsec;
}

static unsigned long mSecond(unsigned long long nsec, unsigned long divs)
{
	if ((long long)nsec < 0)
		nsec = -nsec;
	return do_div(nsec, divs);
}

void get_uefi_time(unsigned int time_from_power)
{
	unsigned long long int ts = 0;
	unsigned long long tmp;
	unsigned int ms_cur;

	ts = sched_clock();

	tmp = ts;
	if ((long long)tmp < 0) {
		tmp = -tmp;
	}
	do_div(tmp, 1000000);
	ms_cur = tmp;

	uefi_time = time_from_power - ms_cur;
}
EXPORT_SYMBOL(get_uefi_time);

void log_boot(char *str)
{
	unsigned long long ts, tmp;
	if (!str) {
		return;
	}
	if (!boottime_enabled) {
        return;
	}
	ts = sched_clock();
	if (ts == 0) {
		printk("[boottime] invalid boottime point\n");
		return;
	}
	if (boot_log_count >= BOOT_LOG_NUM) {
		printk("[boottime] no enough boottime buffer\n");
		return;
	}
	if (strncmp(BOOTUP_DONE, str, strlen(BOOTUP_DONE)) == 0) {
		printk("BOOTUP_DONE:%s,str:%s\n",str,BOOTUP_DONE);
		boottime_enabled = 0;//zygote start
	}
	mutex_lock(&boottime_lock);
	tmp = ts;
	boottime[boot_log_count].Second = Second(tmp, 1000000000);
	tmp = ts;
	boottime[boot_log_count].mSecond = mSecond(tmp, 1000000000);
	strncpy((char*)&boottime[boot_log_count].event, str, BOOT_STR_SIZE);
	printk("boottime %d.%d : %s\n", boottime[boot_log_count].Second,
			boottime[boot_log_count].mSecond, boottime[boot_log_count].event);
	boot_log_count++;
	mutex_unlock(&boottime_lock);
}
EXPORT_SYMBOL(log_boot);

static int boottime_show(struct seq_file *m, void *v)
{
	int i;
	seq_printf(m, "----------- BOOT TIME (sec) -----------\n");
	seq_printf(m, "%d.%-9u s : %s\n", uefi_time / 1000, uefi_time % 1000, "[INFOR] uefi boot time");
	for (i = 0; i < boot_log_count; i++) {
		seq_printf(m, "%d.%09u s : %s\n", boottime[i].Second, boottime[i].mSecond, boottime[i].event);
	}
	seq_printf(m, "%s\n", boottime_enabled ? "starting..." : "start done");
	return 0;
}

static int boottime_open(struct inode *inode, struct file *file)
{
	return single_open(file, boottime_show, inode->i_private);
}

static int __init get_sbl1_time(char *str)
{
	int tmp;
	if (get_option(&str, &tmp)) {
		sbl1_time = tmp;
		return 0;
	}
	return -EINVAL;
}
early_param("sbl1_boottime", get_sbl1_time);

static int __init get_lk_time(char *str)
{
	int tmp;
	if (get_option(&str, &tmp)) {
		lk_time = tmp;
		return 0;
	}
	return -EINVAL;
}
early_param("lk_boottime", get_lk_time);

static ssize_t boottime_write(struct file *filp, const char *ubuf,size_t cnt, loff_t *data)
{
	char buf[BOOT_STR_SIZE] = {0};
	size_t copy_size = cnt;
	if (cnt >= sizeof(buf))
		copy_size = BOOT_STR_SIZE - 1;
	if (copy_from_user(&buf, ubuf, copy_size))
		return -EFAULT;
	if (cnt == 1) {
		if (buf[0] == '0')
			boottime_enabled = 0;  // boot up complete
		else if(buf[0] == '1')
			boottime_enabled = 1;
	}
	buf[copy_size] = 0;
	log_boot(buf);
	return cnt;
}

static const struct proc_ops boottime_fops = {
	.proc_open		= boottime_open,
	.proc_write		= boottime_write,
	.proc_read		= seq_read,
	.proc_lseek 	= seq_lseek,
	.proc_release	= single_release,
};

static int boot_time_init(void)
{
	struct proc_dir_entry *pe;

	printk("uefi boottime is %d.%-9u", uefi_time / 1000, uefi_time % 1000);

	pe = proc_create("boottime", 0664, NULL, &boottime_fops);
	if (!pe) {
		printk("boottime: failed to create '/proc/boottime'\n");
		return -ENOMEM;
	}
	return 0;
}

static void __exit boot_time_exit(void)
{
	remove_proc_entry("bootime", NULL);
}

MODULE_AUTHOR("Honor");
MODULE_DESCRIPTION("Boot Time Recoder");
MODULE_LICENSE("GPL");

module_init(boot_time_init);
module_exit(boot_time_exit);
