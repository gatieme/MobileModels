/*
 * Copyright (c) Honor Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: Logger test suit
 * Author:  yuliang
 * Create:  2021-09-10
 */

#include <log/hiview_hievent.h>

#include <linux/delay.h>
#include <linux/vmalloc.h>
#include <linux/moduleparam.h>
#include <linux/module.h>
#include <linux/kthread.h>
#include <linux/types.h>
#include <linux/version.h>
#include <securec.h>

#define LOG_TAG "logger_test:"
#define log_err(fmt, ...) pr_err(LOG_TAG fmt, ##__VA_ARGS__)
#define log_info(fmt, ...) pr_info(LOG_TAG fmt, ##__VA_ARGS__)
#define KTHREAD_MAX 64
struct task_test {
	struct task_struct *ptask;
	u64 latency_max;
	struct list_head list;
};

static LIST_HEAD(task_list);
static u32 interval = 10;      // ms
static u32 kthread_count = 8;    // default 1
static u32 pack_maxsize  = 4096; // single package max content size
static u64 total_test = 0;
static u64 total_over_200ms = 0;
static u64 total_over_10ms = 0;

module_param(interval, int, 0644);
module_param(kthread_count, int, 0644);
module_param(pack_maxsize, int, 0644);

static u64 get_time_us()
{
	u64 tick_ms;
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 4, 0)
	struct timespec64 now;
	ktime_get_coarse_real_ts64(&now);
#else
	struct timespec now = current_kernel_time();
#endif
	tick_ms = (u64)now.tv_sec * 1000 * 1000;
	tick_ms += (u64)now.tv_nsec / 1000;
	return tick_ms;
}

// len : test content size
static bool test_hievent(u32 len)
{
	int ret;
	char *msg, *tmp;
	struct hiview_hievent *hievent;
	errno_t ret;

	msg = vmalloc(len);
	if (msg == NULL) {
		log_err("vmalloc fail\n");
		return false;
	}

	hievent = hiview_hievent_create(0x00);
	if (!hievent) {
		log_err("create hievent fail\n");
		return false;
	}

	ret = memset_s(msg, len, (int)'A', len - 1);
	if (ret != EOK) {
		log_err("memset_s fail\n");
		return false;
	}
	tmp = msg + len - 1;
	*tmp = '\0';

	ret = hiview_hievent_put_string(hievent, "CONTENT", msg);
	if (ret < 0) {
		pr_err("hievent put string failed\n");
		goto out;
	}

	ret = hiview_hievent_report(hievent);
	if (ret < 0) {
		pr_err("report hievent failed\n");
		goto out;
	}

out:
	hiview_hievent_destroy(hievent);
	vfree(msg);
	if (total_test < (u64)-1)
		total_test++;
	return true;
}

#define LATENCY_LIMIT_10MS  (10 * 1000)
#define LATENCY_LIMIT_200MS (200 * 1000)

static u64 latency_detect(u64 start)
{
	u64 end, latency;
	end = get_time_us();
	if (end < start) {
		log_info("time reversal");
		return 0;
	}
	latency = end - start;
	if (latency > LATENCY_LIMIT_200MS) {
		log_err("LOGGER_FAILED: spend %lu (ms)\n", latency);
		if (total_over_200ms < (u64)-1)
			total_over_200ms++;
	}

	if (latency > LATENCY_LIMIT_10MS) {
		log_err("LOGGER_FAILED: spend %lu (ms)\n", latency);
		if (total_over_10ms < (u64)-1)
			total_over_10ms++;
	}
	return latency;
}

static void logger_sleep(u64 ms)
{
	long jffn = ms * HZ / 1000;
	while (jffn > 0) {
		set_current_state(TASK_INTERRUPTIBLE);
		jffn = schedule_timeout(jffn);
	}
}

static u32 get_random_size(void)
{
	u32 size = get_random_int() % pack_maxsize;
	size = max_t(u32, size, 4); // 4: min
	return  size;
}

static int logger_func(void *data)
{
	u32 latency;
	struct task_test *tsk_tester = (struct task_test *)data;
	while(!kthread_should_stop()) {
		u64 start = get_time_us();
		test_hievent(get_random_size());

		latency = latency_detect(start);
		if (latency > tsk_tester->latency_max)
			tsk_tester->latency_max = latency;
		log_info("%s sleep begin\n", __func__);
		logger_sleep(interval);
		log_info("%s sleep end\n", __func__);
	}

	if (tsk_tester && tsk_tester->ptask) {
		tsk_tester->ptask = NULL;
		log_info("%s exit\n", __func__);
	}
	return 0;
}

static void launch_logger_test_task(void)
{
	int i;
	char name[64];
	struct task_struct *tsk;
	struct task_test *tsk_tester;
	errno_t ret;
	kthread_count = min_t(u32, kthread_count, KTHREAD_MAX);
	for (i = 0; i < kthread_count; i++) {
		ret = memset_s(name, sizeof(name), 0, sizeof(name));
		if (ret != EOK) {
			log_err("memset_s fail\n");
			return false;
		}

		tsk_tester = vmalloc(sizeof(struct task_test));
		if (!tsk_tester)
			break;
		ret = memset_s(tsk_tester, sizeof(struct task_test), 0, sizeof(struct task_test));
		if (ret != EOK) {
			log_err("memset_s fail\n");
			return false;
		}

		INIT_LIST_HEAD(&tsk_tester->list);
		list_add_tail(&tsk_tester->list, &task_list);

		tsk = kthread_create(logger_func, tsk_tester, "logger_test%d", i);
		if (IS_ERR(tsk)) {
			log_err("kthread create failed %d\n", i);
			break;
		}
		tsk_tester->ptask = tsk;
		wake_up_process(tsk);
	}
	log_info("[kthread_count] %d\n", i);
	log_info("[interval] %d\n", interval);
	log_info("[pack_maxsize] %d\n", pack_maxsize);
}

// hwlog_exception ringbuffer size 128KB
// test command: insmod logger_test.ko kthread_count=8 interval=100 pack_maxsize=8192
static int __init logger_test_init(void)
{
	u64 start;
	start = get_time_us();
	if (!test_hievent(4096)) { // size > 2K, unpack
		log_err("LOGGER_FAILED: for 4k content test\n");
	}
	log_info("test for content size:4k");

	start = get_time_us();
	if (!test_hievent(64 * 1024)) { // size > 64K,drop the part over 64kB
		log_err("LOGGER_FAILED: for 4k content test\n");
	}
	log_info("test for content over size 65KB");
	latency_detect(start);
	launch_logger_test_task();
	return 0;
}

static void __exit logger_test_exit(void)
{
	struct task_test *tsk_tester;
	struct task_test *tsk_tester_next;

	list_for_each_entry_safe(tsk_tester, tsk_tester_next, &task_list, list) {

		if (!tsk_tester)
			continue;

		log_info("%s latency_max:%lu(us)\n", tsk_tester->ptask->comm,
			tsk_tester->latency_max);
		if (tsk_tester->ptask) {
			log_info("stop %s \n", tsk_tester->ptask->comm);
			kthread_stop(tsk_tester->ptask);
			tsk_tester->ptask = NULL;
		}
		list_del(&tsk_tester->list);
		vfree(tsk_tester);
		tsk_tester = NULL;
	}
	log_info("total:%lu, over 200ms:%lu, over 10ms:%lu",
		total_test, total_over_200ms, total_over_10ms);
}

module_init(logger_test_init);
module_exit(logger_test_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Logger for exception, jank, dubai");
MODULE_AUTHOR("yuliang");
