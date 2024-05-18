/*
 * Copyright (c) Honor Device Co., Ltd. 2022-2022. All rights reserved.
 * Description:micro dump testcases
 * Author: Lu Laicheng
 * Create: 2022-03-22
 */

#include <linux/sched/signal.h>
#include <linux/sched/rt.h>
#include <linux/sched/debug.h>
#include <linux/sched/task.h>
#include <linux/sched.h>
#include <linux/ctype.h>
#include <linux/interrupt.h>
#include <linux/mm.h>
#include <linux/fs.h>
#include <linux/mount.h>
#include <linux/kdev_t.h>
#include <linux/major.h>
#include <linux/reboot.h>
#include <linux/sysrq.h>
#include <linux/kbd_kern.h>
#include <linux/proc_fs.h>
#include <linux/nmi.h>
#include <linux/quotaops.h>
#include <linux/perf_event.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/suspend.h>
#include <linux/writeback.h>
#include <linux/swap.h>
#include <linux/spinlock.h>
#include <linux/vt_kern.h>
#include <linux/workqueue.h>
#include <linux/hrtimer.h>
#include <linux/delay.h>
#include <linux/oom.h>
#include <linux/slab.h>
#include <linux/input.h>
#include <linux/uaccess.h>
#include <linux/moduleparam.h>
#include <linux/jiffies.h>
#include <linux/syscalls.h>
#include <linux/of.h>
#include <linux/rcupdate.h>
#include <linux/mutex.h>
#include <asm-generic/bug.h>
#include <asm/ptrace.h>
#include <asm/irq_regs.h>
#include "../micro_dump.h"

struct mutex g_mutex;
DEFINE_SPINLOCK(g_micro_spinlock);

static void asm_get_regs(struct pt_regs *regs)
{
	struct pt_regs *p;

	if (!regs)
		return;
	p = regs;
	MD_PRINT("asm_get_regs start 0x%lx \n", p);

	asm volatile(
	"stp	x0, x1, [%0, #16 * 0]\n"
	"stp	x2, x3, [%0, #16 * 1]\n"
	"stp	x4, x5, [%0, #16 * 2]\n"
	"stp	x6, x7, [%0, #16 * 3]\n"
	"stp	x8, x9, [%0, #16 * 4]\n"
	"stp	x10, x11, [%0, #16 * 5]\n"
	"stp	x12, x13, [%0, #16 * 6]\n"
	"stp	x14, x15, [%0, #16 * 7]\n"
	"stp	x16, x17, [%0, #16 * 8]\n"
	"stp	x18, x19, [%0, #16 * 9]\n"
	"stp	x20, x21, [%0, #16 * 10]\n"
	"stp	x22, x23, [%0, #16 * 11]\n"
	"stp	x24, x25, [%0, #16 * 12]\n"
	"stp	x26, x27, [%0, #16 * 13]\n"
	"stp	x28, x29, [%0, #16 * 14]\n"
	"stp	x30, x29, [%0, #16 * 15]\n"
	"stp	x30, x30, [%0, #16 * 16]\n"
	::"r"(p):"memory");

	MD_PRINT("asm_get_regs end 0x%lx \n", p);
}

typedef int (*test_func) (int i);

static noinline int test_hung(void *dummy)
{
	unsigned long hung_last_checked = 0;
	MD_PRINT("%s: in\n", __func__);

	mutex_lock(&g_mutex);
	hung_last_checked++;
	mutex_unlock(&g_mutex);

	return 0;
}

static noinline int test_hung_task_init(void)
{
	MD_PRINT("%s: in\n", __func__);
	mutex_lock(&g_mutex);
	kthread_run(test_hung, NULL, "test_hung");
	return 0;
}

static noinline int test_bitflip_dabt(void)
{
	unsigned long test_data = 777;
	unsigned long test_addr_value = ((uintptr_t)(&test_data)) & 0xfdffffffffffffff;
	MD_PRINT("test_bitflip_dabt: test_addr_value=%lx\n", *(unsigned long *)(uintptr_t)test_addr_value);
	return 0;
}

static noinline int test_bitflip_undef(void)
{
	MD_PRINT("test_bitflip_undef start.\n");
	asm volatile(".short 0xde00\n");
	return 0;
}

static noinline void micro_handle_sysrq(char key, bool check_mask)
{
#ifndef CONFIG_HN_MICRODUMP_GKI
	char stackp [10];
#endif
	void * page;
	int *  ptr;
	char * charp;
	int tmp = 0;
	unsigned long flag;
	test_func func;
	struct pt_regs regs = {0};

	MD_PRINT("micro_handle_sysrq \n");
	switch (key) {
	case 't':
		asm_get_regs(&regs);
		for (tmp = 0; tmp < 30; tmp++) {
			MD_PRINT("micro_handle_sysrq asm_get_regs x-%2d = 0x%lx \n", tmp, regs.regs[tmp]);
		}
		break;
	case 'n':
		ptr = NULL;
		ptr++;
		*ptr = 0;
		break;
	case 's':
		while (1) {
			charp = kmalloc(16, GFP_KERNEL);
			memset(charp, 0xF, 2046);
			kfree(charp);
		}
		break;
	case 'b':
		BUG_ON(1);
		break;
	case 'g':
		BUG();
		break;
	case 'i': // undef instr
		func = (test_func)0x8088;
		tmp = func(tmp);
		break;
#ifndef CONFIG_HN_MICRODUMP_GKI
	case 'k': {
		char buff[2] = {0};
		tmp = 128000;
		MD_PRINT("stack corrupt in\n");
		strcpy(buff, "hello world!!!");
		memset(stackp, 0x4, tmp);
		break;
	}
#endif
	case 'h': // hung irq close
		mutex_init(&g_mutex);
		mutex_lock(&g_mutex);
		while (1) {
			tmp++;
		}
		mutex_unlock(&g_mutex);
		break;
	case 'u':
		mutex_init(&g_mutex);
		mutex_lock(&g_mutex);
		test_hung_task_init();
		if (tmp)
			mutex_unlock(&g_mutex);
		break;
	case 'v': // vmalloc page access
		charp = (char *)vmalloc(PAGE_SIZE - 1024);
		memset(charp, 0xF, PAGE_SIZE*2);
		break;
	case 'w': // write read only page
		spin_lock_irqsave(&g_micro_spinlock, flag);
		spin_lock_irqsave(&g_micro_spinlock, flag);
		while (1) {
			tmp++;
		}
		spin_unlock_irqrestore(&g_micro_spinlock, flag);
		break;
	case 'r': // random point of slub
		while (1) {
			charp = kmalloc(1024, GFP_KERNEL);
			kfree(charp);
			cond_resched();
			memset(charp, 0xF, 1024);
		}
		break;
	case 'l': // linear mapping page access
		page = alloc_page(GFP_KERNEL);
		charp = (char *)page;
		memset(charp, 0xF, PAGE_SIZE*2);
		break;
	case 'p':
		panic("panic test");
		break;
	case 'd':
		test_bitflip_dabt();
		break;
	case 'c':
		test_bitflip_undef();
		break;
	default:
		MD_PRINT("micro__handle_sysrq do nothing\n");
		break;
	}
}

static ssize_t write_micro_trigger(struct file *file, const char __user *buf,
						size_t count, loff_t *ppos)
{
	if (count) {
		char c;

		if (get_user(c, buf))
			return -EFAULT;
		micro_handle_sysrq(c, false);
	}

	return count;
}
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0)
static const struct file_operations proc_operations = {
	.write  = write_micro_trigger,
};
#else
static const struct proc_ops proc_operations = {
	.proc_write = write_micro_trigger,
	.proc_lseek = noop_llseek,
};
#endif
static int __init micro_test_proc_init(void)
{
	if (!proc_create("microdump", S_IWOTH|S_IWGRP|S_IWUSR|S_IROTH|S_IRGRP|S_IRUSR,
		NULL, &proc_operations))
		MD_PRINT("Failed to register proc interface\n");

	MD_PRINT("micro_test module init\n");
	return 0;
}

#ifdef CONFIG_HN_MICRODUMP_GKI
module_init(micro_test_proc_init);
#else
late_initcall(micro_test_proc_init);
#endif
MODULE_DESCRIPTION("kernel micro dump test for honor");
MODULE_LICENSE("GPL v2");

