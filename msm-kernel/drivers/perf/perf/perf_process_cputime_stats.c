#include "perf_process_cputime_stats.h"

#include <linux/cpufreq_times.h>
#include <linux/jiffies.h>
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

#define INIT_PID 1
#define KTHREADD_PID 2
#define DMIPS_NUM 16
#define MAX_COUNT_CPU_USAGE 1200

static int dmips_value_buffer[DMIPS_NUM];

struct perf_process_cputime_info {
	unsigned int pid;
	unsigned int cpu_usage_time;
	unsigned long cpu_load_time;
} __packed;

static unsigned long get_process_load_cputime(struct task_struct *task)
{
	unsigned long proc_cputime_total;

	if (task->tgid == INIT_PID || task->tgid == KTHREADD_PID)
		return 0;
	if (task->real_parent && task->real_parent->tgid == KTHREADD_PID && !strstr(task->comm, "swapd"))
		return 0;
	proc_cputime_total = get_proc_cpu_load(task, dmips_value_buffer, DMIPS_NUM);

	return proc_cputime_total;
}

static unsigned int get_process_usage_cputime(struct task_struct *task)
{
	u64 utime, stime, sum_time;
	unsigned int cputime;

	thread_group_cputime_adjusted(task, &utime, &stime);
	sum_time = utime + stime + task->signal->cutime + task->signal->cstime;
	cputime = (unsigned int)(sum_time / NS_TO_MS);

	return cputime;
}

static int get_perf_process_cputime_stats(struct perf_buffered_log_entry *entry)
{
	int max_count;
	struct task_struct *task;
	struct perf_process_cputime_info info;
	int ret;
	unsigned char *data = entry->data;

	max_count = entry->count;
	entry->count = 0;

	rcu_read_lock();
	task = &init_task;
	for_each_process(task) {
		if (entry->count >= max_count)
			break;
		if (task->pid != task->tgid)
			continue;
		info.pid = (unsigned int)task->pid;
		info.cpu_load_time = get_process_load_cputime(task);
		info.cpu_usage_time = get_process_usage_cputime(task);
		ret = memcpy_s(data, sizeof(struct perf_process_cputime_info), &info, sizeof(struct perf_process_cputime_info));
		if (ret != EOK) {
			pr_err("PerfD %s: memcpy_s failed\n", __func__);
			return ret;
		}
		data += sizeof(struct perf_process_cputime_info);
		entry->count++;
	}
	rcu_read_unlock();
	entry->length = cal_log_entry_len(sizeof(struct perf_buffered_log_entry),
		sizeof(struct perf_process_cputime_info), entry->count);

	return 0;
}

static int perf_process_cputime_fetch(void __user *argp)
{
	int ret;
	int entry_size;
	struct perf_buffered_log_entry *entry = NULL;

	entry_size = cal_log_entry_len(sizeof(struct perf_buffered_log_entry),
		sizeof(struct perf_process_cputime_info), MAX_COUNT_CPU_USAGE);
	entry = perf_create_log_entry(entry_size, IOC_PROCESS_CPUTIME, MAX_COUNT_CPU_USAGE);

	if (entry == NULL) {
		pr_err("PerfD %s: failed to create log entry\n", __func__);
		goto error;
	}

	if (get_perf_process_cputime_stats(entry)) {
		pr_err("PerfD %s: failed to get process cputime\n", __func__);
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

static int perf_init_cpu_load_dimps(void __user *argp)
{
	int ret;
	int i;
	struct ioctl_message message;
	ret = memset_s(dmips_value_buffer, sizeof(dmips_value_buffer), 0,
		sizeof(dmips_value_buffer));
	if (ret != EOK) {
		pr_err("PerfD %s: memset_s failed\n", __func__);
		return ret;
	}

	if (copy_from_user(&message, (void*)argp, sizeof(struct ioctl_message))) {
		pr_err("PerfD %s: copy_from_user failed\n", __func__);
		return -EFAULT;
	}

	if ((message.count < 0) || (message.count > DMIPS_NUM)) {
		pr_err("PerfD %s: invalid message count\n", __func__);
		return -EINVAL;
	}

	for (i = 0 ; i < message.count ; i++)
		dmips_value_buffer[i] = message.data[i];

	return 0;
}

long perf_ioctl_process_cputime(unsigned int cmd, void __user *argp)
{
	int ret = 0;

	switch (cmd) {
	case  IOC_GET_PROCESS_CPUTIME:
		ret = perf_process_cputime_fetch(argp);
		break;
	case IOC_SET_CPU_DIMPS:
		ret = perf_init_cpu_load_dimps(argp);
		break;
	default:
		ret = -EINVAL;
		break;
	}

	return ret;
}

