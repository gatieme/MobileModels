#include <linux/sched.h>
#include <linux/kthread.h>
#include <linux/nmi.h>
#include <linux/stacktrace.h>
#include <linux/kern_levels.h>
#include <linux/lockdep.h>
#include <linux/signal.h>
#include <linux/delay.h>
#include <linux/sched/debug.h>
#include <securec.h>

/* local macroes */
#define MAX_NAME_LEN 128
#define MAX_WRITE_BUFFER_SIZE 32
#define MAX_READ_BUFFER_SIZE 32
#define VALUE_START_INDEX 2
#define OCT 10

/* local static varibles */
static unsigned int first_threshold = 5000; // 5 seconds
static unsigned int second_threshold = 10000; // 10 seconds
static unsigned int third_threshold = 15000; // 15 seconds
static unsigned int lock_detector_enabled = 1;
static unsigned int one_cycle =  5000;
static const lock_detector_banching = 1024;

static int split_string(const char *str)
{
	int res = -1;
	for (int i = 0; i < strlen(str); i++) {
		char p = *(str + i);
		if (p == ' ')
			res = (res == -1) ? i : -1;
	}
	return res;
}

static ssize_t lock_detector_store(struct kobject *kobj, struct kobj_attribute *attr,
				const char *buf, size_t count)
{
	if (!buf)
		return -EINVAL;

	char buffer[MAX_WRITE_BUFFER_SIZE];
	char value[MAX_WRITE_BUFFER_SIZE];
	int new_val;
	int ret;
	size_t size = min(count, MAX_WRITE_BUFFER_SIZE - 1);
	memset_s(buffer, MAX_WRITE_BUFFER_SIZE, 0, MAX_WRITE_BUFFER_SIZE);
	if (strncpy_s(buffer, MAX_WRITE_BUFFER_SIZE - 1, buf, count) != EOK) {
		pr_err("copy input from userspace failed!\n");
		return 0;
	}
	buffer[size + 1] = '\0';
	int index = -1;
	index = split_string(buffer);
	if (index != 1) {
		pr_err("%s", "input is invalid");
		return -EFAULT;
	}

	int change = buf[0] - '0';
	ret = strncpy_s(value, MAX_WRITE_BUFFER_SIZE - 1, &buf[VALUE_START_INDEX], count - VALUE_START_INDEX);
	if (!ret)
		pr_err("parse input value failed\n");
	ret = kstrtouint(value, OCT, &new_val);
	if (ret)
		return ret;
	switch (change) {
	case 1:
		first_threshold = new_val;
		break;
	case 2:
		second_threshold = new_val;
		break;
	case 3:
		third_threshold = new_val;
		break;
	case 4:
		one_cycle = new_val;
		break;
	case 5:
		lock_detector_enabled = new_val;
		break;
	default:
		break;
	}
	return count;
}

static ssize_t lock_detector_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
	char buffer[MAX_READ_BUFFER_SIZE];
	int len = 0;
	char *begin = buf;
	len = snprintf_s(buffer, MAX_READ_BUFFER_SIZE - 1, MAX_READ_BUFFER_SIZE, "1.first_threshold %ums\n2."
				"second_threshold %ums\n3.third_threshold %ums\n4.one_cycle %ums\n5.lock_detector_enabled %u, "
				"1 : enabled; 0 : disabled\nif you wanna change a value, please enter its order and then its new"
				"value, eg: 1 4500\n", first_threshold, second_threshold, third_threshold, one_cycle,
				lock_detector_enabled);
	if (len <= 0) {
		pr_err("failed to print formation need to show to buffer\n");
		return len;
	}
	len = snprintf_s(buf, MAX_READ_BUFFER_SIZE - 1, MAX_READ_BUFFER_SIZE - 1, "%s\n", buffer);
	if (len <= 0) {
		pr_err("failed to print information to user space buffer\n");
		return len;
	}
	return len;
}

static struct kobj_attribute lock_detector_attribute = {
	.attr = {
		.name = "lock_detector",
		.mode = 0640,
	},
	.show = lock_detector_show,
	.store = lock_detector_store,
};

static void print_heldlock_name(struct held_lock *hlock, char *name)
{
	int res;
#ifdef CONFIG_DEBUG_LOCK_ALLOC
	res = snprintf_s(name, MAX_NAME_LEN, MAX_NAME_LEN, "%s", hlock->instance->name);
#else
	res = snprintf_s(name, MAX_NAME_LEN, MAX_NAME_LEN, "%pS", hlock);
#endif
	if (res <= 0)
		pr_err("print_held_lock_name failed!\n");
}

static void dump_task_trace(struct task_struct *curr)
{
	show_stack(curr, NULL, KERN_DEFAULT);
}

static bool rcu_lock_break(struct task_struct *g, struct task_struct *t)
{
	bool can_cont = false;

	get_task_struct(g);
	get_task_struct(t);
	rcu_read_unlock();
	cond_resched();
	rcu_read_lock();
	can_cont = pid_alive(g) && pid_alive(t);
	put_task_struct(t);
	put_task_struct(g);
	return can_cont;
}

static void check_timestamp(struct task_struct *p, struct held_lock *hold_lock)
{
	unsigned long acquired_time = hold_lock->timestamp;
	char name[MAX_NAME_LEN];
	print_heldlock_name(hold_lock, name);
	barrier();
	if (time_after(jiffies, acquired_time + msecs_to_jiffies(first_threshold))) {
		pr_info("lock %s is held by [%s]%d on CPU%d\n",
				name, p->comm, p->pid, task_cpu(p));
		if ((hold_lock->timestamp == 0) || (hold_lock->timestamp != acquired_time))
			return;
		if (time_after(jiffies, acquired_time + msecs_to_jiffies(second_threshold))) {
			pr_err("=============start dump backtrace==============\n");
			dump_task_trace(p);
			pr_err("==============end dump backtrace===============\n");
			if ((hold_lock->timestamp == 0) || (hold_lock->timestamp != acquired_time))
				return;
			if (time_after(jiffies, acquired_time + msecs_to_jiffies(third_threshold)))
				debug_show_held_locks(p);
		}
	}
}

static void check_all_held_locks(struct task_struct *p)
{
	struct held_lock *hold_lock;
	int i;

	for (i = 0; i < p->lockdep_depth; i++) {
		hold_lock = p->held_locks + i;
		if (hold_lock)
			check_timestamp(p, hold_lock);
	}
}

static void held_lock_check()
{
	struct task_struct *g, *p;
	int batch_count = lock_detector_banching;
	rcu_read_lock();
	for_each_process_thread(g, p) {
		if (!p->lockdep_depth)
			continue;
		if (!--batch_count) {
			batch_count = lock_detector_banching;
			if (!rcu_lock_break(g, p))
				goto unlock;
		}
		check_all_held_locks(p);
		touch_nmi_watchdog();
		touch_all_softlockup_watchdogs();
	}
unlock:
	rcu_read_unlock();
}

static int lock_detect(void *data)
{
	while (lock_detector_enabled) {
		held_lock_check();
		msleep(one_cycle);
	}
	return 1;
}

static void create_ksysfs_node(void)
{
	int ret = 0;

	while (!kernel_kobj)
	msleep(1000);

	struct kobject *lock_detector = kobject_create_and_add("lock_detector", kernel_kobj);
	if (!lock_detector) {
		pr_err("create sysfs node failed!\n");
		return;
}

	ret = sysfs_create_file(lock_detector, &lock_detector_attribute.attr);
	if (ret) {
		pr_err("link sysfs node operations to node failed\n");
		return;
	}
}

unsigned int is_lock_detector_enabled(void)
{
	return lock_detector_enabled;
}

#ifndef CONFIG_DFX_HUNGTASK
static int __init lock_detector_start(void)
{
	create_ksysfs_node();
	kthread_run(lock_detect, NULL, "lock_detector");
	return 0;
}
__initcall(lock_detector_start);
#else
void lock_detector_start(void)
{
	create_ksysfs_node();
	kthread_run(lock_detect, NULL, "lock_detector");
}
EXPORT_SYMBOL_GPL(lock_detector_start);
#endif
