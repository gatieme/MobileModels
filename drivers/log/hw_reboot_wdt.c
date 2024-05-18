/*
 * hw_reboot_wdt.c
 *
 * watch reboot/shutdown and notify logcat/xlogcat by sending signal SIGUSR2
 *
 * Copyright (c) 2012-2018 Honor Device Co., Ltd.
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

#include <asm/siginfo.h>
#include <linux/debugfs.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/notifier.h>
#include <linux/proc_fs.h>
#include <linux/rcupdate.h>
#include <linux/reboot.h>
#include <linux/version.h>
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(4, 14, 0))
#include <linux/sched/signal.h>
#endif
#include <linux/uaccess.h>

#include <securec.h>
#include <log/hw_log.h>

#undef HWLOG_TAG
#define HWLOG_TAG	reboot_wdt
HILOG_REGIST_LEVEL(HILOG_ERR | HILOG_WARNING | HILOG_INFO);

#define SIG_TEST	12	/* 12 for SIGUSR2 */
#define SIG_VAL		1234

#define SVC_NAME_APP	"applogcat"
#define SVC_NAME_KMSG	"kmsglogcat"

enum log_svc_index {
	SVC_IDX_APP = 0,
	SVC_IDX_KMSG,
	LIST_MAX = 10,
};

struct log_svc_order_t {
	int svc_idx;
	const char *svc_name;
};

static struct log_svc_order_t gs_preset_log_svc_list[] = {
	{ SVC_IDX_APP, SVC_NAME_APP },
	{ SVC_IDX_KMSG, SVC_NAME_KMSG },
};

#if IS_ENABLED(CONFIG_BOOT_DETECTOR)
extern int register_long_press_notifier(struct notifier_block *nb);
extern int unregister_long_press_notifier(struct notifier_block *nb);
#endif

struct proc_dir_entry *proc_file;
static struct gs_pid_list_t {
	int pid;
	char name[NAME_MAX];
} gs_pid_list[LIST_MAX];

static void clear_pid_list(void)
{
	int i;

	for (i = 0; i < LIST_MAX; i++) {
		gs_pid_list[i].pid = 0;
		memset(gs_pid_list[i].name, 0, NAME_MAX);
	}
}

static void init_preset_log_svc_list(void)
{
	int i;
	for (i = 0; i < ARRAY_SIZE(gs_preset_log_svc_list); i++) {
		memcpy(gs_pid_list[gs_preset_log_svc_list[i].svc_idx].name,
		       gs_preset_log_svc_list[i].svc_name,
		       strlen(gs_preset_log_svc_list[i].svc_name));
	}
}

static void insert_pid_list(int pid)
{
	int i;
	struct task_struct *t = NULL;

	rcu_read_lock();
	/* find the task_struct associated with this pid */
	t = find_task_by_vpid(pid);
	if (!t) {
		hilog_debug("%s no such pid\n", __func__);
		rcu_read_unlock();
		return;
	}
	rcu_read_unlock();

	for (i = 0; i < LIST_MAX; i++) {
		if (strncmp(t->comm, gs_pid_list[i].name, NAME_MAX) == 0) {
			if (gs_pid_list[i].pid == pid)
				gs_pid_list[i].pid = 0;
			else
				gs_pid_list[i].pid = pid;

			hilog_debug("%s update (%d)pid:%d, %s\n",
				    __func__, i, pid, t->comm);
			return;
		}
	}
	/* there was no same task name, so store a new one */
	for (i = 0; i < LIST_MAX; i++) {
		if (gs_pid_list[i].pid == 0 && gs_pid_list[i].name[0] == '\0') {
			gs_pid_list[i].pid = pid;
			memcpy_s(gs_pid_list[i].name, NAME_MAX, t->comm, strlen(t->comm));
			hilog_debug("%s add new (%d)pid:%d, %s\n",
				    __func__, i, pid, t->comm);
			return;
		}
	}
	hilog_debug("gs_pid_list was full\n");
}

static ssize_t recv_pid(struct file *file, const char __user *buf,
			size_t count, loff_t *ppos)
{
	char mybuf[LIST_MAX];
	unsigned int pid = 0;
	/* read the value from user space */
	if (count >= LIST_MAX)
		return -EINVAL;

	if (copy_from_user(mybuf, buf, count)) {
		hilog_debug("%s copy failed\n", __func__);
	} else {
		mybuf[count] = '\0';
		if (kstrtoint(mybuf, 0, &pid) == 0)
			insert_pid_list(pid);
	}

	return count;
}

static int reboot_callback(struct notifier_block *self, unsigned long event,
			   void *data)
{
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 4, 0)
	struct kernel_siginfo info;
#else
	struct siginfo info;
#endif
	struct task_struct *t = NULL;
	int i;
	int ret;

	hilog_debug("Shutdown... Event code: %li\n", event);

	/* send the signal */
	memset_s(&info, sizeof(struct siginfo), 0, sizeof(info));
	info.si_signo = SIG_TEST;
	info.si_code = SI_QUEUE;
	/*
	 * this is bit of a trickery: SI_QUEUE is normally used by sigqueue from
	 * user space, and kernel space should use SI_KERNEL. But if SI_KERNEL
	 * is used the real_time data is not delivered to the user space signals
	 * handler function.
	 */
	/* real time signals may have 32 bits of data */
	info.si_int = SIG_VAL;

	for (i = 0; i < LIST_MAX; i++) {
		if (gs_pid_list[i].pid != 0) {
			rcu_read_lock();
			/* find the task_struct associated with this pid */
			t = find_task_by_vpid(gs_pid_list[i].pid);
			if (!t) {
				hilog_debug("%s no such pid\n", __func__);
				rcu_read_unlock();
				continue;
			}
			rcu_read_unlock();
			ret = send_sig_info(SIG_TEST, &info, t);
			hilog_info("%s will notify pid(%d):%d, %s\n", __func__,
				    i, gs_pid_list[i].pid, t->comm);
			if (ret < 0)
				hilog_err("%s error sending signal\n", __func__);
		}
		hilog_debug("%s each (%d)pid:%d\n", __func__, i, gs_pid_list[i].pid);
	}
	return NOTIFY_OK;
}

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0)
static const struct proc_ops config_node_fops = {
	.proc_write = recv_pid,
};
#else
static const struct file_operations config_node_fops = {
	.write = recv_pid,
};
#endif

static struct notifier_block reboot_wdt_notifier = {
	.notifier_call = reboot_callback,
};

#if IS_ENABLED(CONFIG_BOOT_DETECTOR)
static struct notifier_block long_press_notifier = {
	.notifier_call = reboot_callback,
};
#endif

int reboot_wdt_module_init(void)
{
	int ret;
	clear_pid_list();
	init_preset_log_svc_list();
	/*
	 * we need to know the pid of the user space process
	 * -> we use debugfs for this. As soon as a pid is written to
	 * this file, a signal is sent to that pid
	 */
	/* only root can write to this file (no read) */
	proc_file = proc_create("reboot_watchdog", 0200, NULL,
				&config_node_fops);
	ret = register_reboot_notifier(&reboot_wdt_notifier);
	hilog_debug("%s:register_reboot_notifier ret=%d\n", __func__, ret);
#if IS_ENABLED(CONFIG_BOOT_DETECTOR)
	ret = register_long_press_notifier(&long_press_notifier);
	hilog_debug("%s:register_long_press_notifier ret=%d\n", __func__, ret);
#endif
	return 0;
}

void reboot_wdt_module_exit(void)
{
	hilog_debug("%s\n", __func__);
	remove_proc_entry("reboot_watchdog", NULL);
	unregister_reboot_notifier(&reboot_wdt_notifier);
#if IS_ENABLED(CONFIG_BOOT_DETECTOR)
	unregister_long_press_notifier(&long_press_notifier);
#endif
}
