#include "perf_thread_status_stats.h"

#include <linux/ioctl.h>
#include <linux/init.h>
#include <linux/mm.h>
#include <linux/net.h>
#include <linux/profile.h>
#include <linux/slab.h>
#include <linux/version.h>
#include <linux/sched/stat.h>
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(4, 14, 0))
#include <linux/sched.h>
#include <linux/sched/cputime.h>
#include <linux/sched/signal.h>
#endif

#include "perf_ioctl.h"
#include "utils/perf_buffered_log_sender.h"
#include "securec.h"

#define MAX_COUNT_THREAD_STATUS 1

struct perf_thread_status_info {
	unsigned int pid;
	unsigned int running_duration;
	unsigned int runnable_duration;
	unsigned int sleeping_duration;
	unsigned int uninterruptible_sleep_duration;
};

static int get_perf_thread_status_stats(struct perf_buffered_log_entry *entry, int key_task_id)
{
	int max_count;
	struct perf_thread_status_info info;
	struct task_struct *task;
	int ret;
	unsigned char *data = entry->data;

	max_count = entry->count;
	entry->count = 0;

	rcu_read_lock();
	task = &init_task;
	for_each_process(task) {
		if (entry->count >= max_count)
			break;
		if (task->pid != key_task_id)
			continue;
		info.pid = (unsigned int)task->pid;
		info.running_duration = task->se.sum_exec_runtime / NS_TO_MS;
		info.runnable_duration = task->se.statistics.wait_sum / NS_TO_MS;
		info.sleeping_duration = 0;
		info.uninterruptible_sleep_duration = 0;
		ret = memcpy_s(data, sizeof(struct perf_thread_status_info), &info, sizeof(struct perf_thread_status_info));
		if (ret != EOK) {
			pr_err("PerfD %s: memcpy_s failed\n", __func__);
			return ret;
		}
		data += sizeof(struct perf_thread_status_info);
		entry->count++;
	}
	rcu_read_unlock();

	return 0;
}

static int perf_thread_status_fetch(void __user *argp)
{
	int ret;
	int entry_size;
	int key_task_id;
	struct perf_buffered_log_entry *entry = NULL;

	// accept key pid from hiview
	if (copy_from_user(&key_task_id, (void*)argp, sizeof(int))) {
		pr_err("PerfD %s: failed to copy_from_user\n", __func__);
		return -EFAULT;
	}

	entry_size = cal_log_entry_len(sizeof(struct perf_buffered_log_entry),
		sizeof(struct perf_thread_status_info), MAX_COUNT_THREAD_STATUS);
	entry = perf_create_log_entry(entry_size, IOC_THREAD_STATUS, MAX_COUNT_THREAD_STATUS);

	if (entry == NULL) {
		pr_err("PerfD %s: failed to create log entry\n", __func__);
		goto error;
	}

	if (get_perf_thread_status_stats(entry, key_task_id)) {
		pr_err("PerfD %s: failed to get thread status\n", __func__);
		goto error;
	}

	ret = send_perf_buffered_log_entry(entry);
	if (ret < 0) {
		pr_err("PerfD %s: failed to send log entry\n", __func__);
		goto error;
	}

	free_perf_buffered_log_entry(entry);

	return 0;

error:
	free_perf_buffered_log_entry(entry);
	return -EINVAL;
}

long perf_ioctl_thread_status(unsigned int cmd, void __user *argp)
{
	int ret = 0;

	switch (cmd) {
	case  IOC_GET_THREAD_STATUS:
		ret = perf_thread_status_fetch(argp);
		break;
	default:
		ret = -EINVAL;
		break;
	}

	return ret;
}
