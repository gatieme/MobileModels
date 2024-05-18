/*
 * Copyright (c) Honor Device Co., Ltd. 2022-2022. All rights reserved.
 * Description:dump hungtask lock
 * Author: mahulin
 * Create: 2022-10-26
 */

#include <micro_dump.h>
#include <linux/kmsg_dump.h>

#define MUTEX_FLAG_MASK 0x07
#define MAX_CHECK_DEEP 5
#define HUNG_PANIC_LOG "120s is causing panic"

enum lock_type {
	RW_SEM = 0,
	SEM,
	MUTEX,
	UNKNOWN,
};

struct lock_info {
	enum lock_type type;
	char *lock_symbol;
};

const struct lock_info g_lock_list[] = {
	{RW_SEM,	"down_read"},
	{RW_SEM,	"down_write"},
	{SEM,		"down"},
	{MUTEX,		"mutex_lock"},
};

static pid_t get_hung_pid(void)
{
	pid_t pid;
	char *ptr;
	static char line[1024];
	unsigned long len;

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 15, 0))
	struct kmsg_dump_iter dumper;
	kmsg_dump_rewind(&dumper);
	while (kmsg_dump_get_line(&dumper, true, line, sizeof(line), &len)) {
#else
	struct kmsg_dumper dumper;
	kmsg_dump_rewind_nolock(&dumper);
	dumper.active = true;
	while (kmsg_dump_get_line_nolock(&dumper, true, line, sizeof(line), &len)) {
#endif
		line[len] = '\0';
		ptr = strstr(line, HUNG_PANIC_LOG);
		if (ptr)
			break;
	}

	if (!ptr) {
		MD_PRINT("Unable to locate string:120s is causing panic\n");
		return -1;
	}

	/* find pid from such info "Thread-31:3315 blocked for 120s is causing panic" */
	ptr = strrchr(line, ':');
	pid = (pid_t)simple_strtoul(++ptr, NULL, 10);
	if (!pid) {
		MD_PRINT("Unable to convert out correct pid, maybe no pid info\n");
		return -1;
	}

	return pid;
}

static struct task_struct *get_hung_task(pid_t pid)
{
	struct task_struct *g, *p;

	for_each_process_thread(g, p)
		if (p->pid == pid)
			return p;

	return NULL;
}

void microdump_hungtask_stack(void)
{
	pid_t pid;
	struct task_struct *task;

	pid = get_hung_pid();
	if (pid < 0) {
		MD_PRINT("get hung pid failed\n");
		return;
	}

	task = get_hung_task(pid);
	if (!task) {
		MD_PRINT("get hung task struct failed\n");
		return;
	}

	MD_PRINT("hungtask pid:%d, name:%s\n", pid, task->comm);
	common_show_stack(task, NULL, KERN_INFO);
}

/*
 * 0xFFFFFF8018D69BC0:FFFFFFA2DF7A1000 FFFFFFC25E4B2110 <-lock:sem/mutex
 * 0xFFFFFF8018D69BD0:FFFFFF8018D69BE0 FFFFFFA2DDB2E630 <-func:down_read/mutex_lock/...
 *     |                 |                |
 *    \|/               \|/              \|/
 *  last_fp           frame.fp         frame.pc
 * so we can get :sem/mutex = *(last_fp - 8), if the value invalid, will try
 * another way:sem/mutex = *(frame.fp - 8).
 */
static unsigned long get_lock_addr(struct task_struct *task)
{
	struct stackframe frame;
	unsigned long lock_addr;
	unsigned long last_fp;
	char buf[64] = {0};
	int i;

	frame.fp = thread_saved_fp(task);
	frame.pc = thread_saved_pc(task);
	last_fp = frame.fp;
	do {
		sprintf_s(buf, sizeof(buf) - 1, "%ps", (void *)(uintptr_t)frame.pc);
		for (i = 0; i < ARRAY_SIZE(g_lock_list); i++) {
			if (!strcmp(buf, g_lock_list[i].lock_symbol))
				break;
		}

		if (i != ARRAY_SIZE(g_lock_list)) {
			lock_addr = *(unsigned long *)(last_fp - 8);
			if (microdump_check_addr_valid((unsigned long)lock_addr)) {
				MD_PRINT("task %s is doing %s lock:0x%016lx",
					 task->comm, g_lock_list[i].lock_symbol, lock_addr);
				return lock_addr;
			}

			MD_PRINT("lock addr:0x%016lx is invalid, try another way\n", lock_addr);
			lock_addr = *(unsigned long *)(frame.fp - 8);
			if (microdump_check_addr_valid((unsigned long)lock_addr)) {
				MD_PRINT("task %s is doing %s lock:0x%016lx",
					 task->comm, g_lock_list[i].lock_symbol, lock_addr);
				return lock_addr;
			}
		}
		last_fp = frame.fp;
	} while (!common_unwind_frame(task, &frame));

	return 0;
}

static enum lock_type get_lock_type(struct task_struct *task)
{
	struct stackframe frame;
	unsigned long last_fp;
	enum lock_type type = UNKNOWN;
	char buf[64] = {0};
	int i;

	frame.fp = thread_saved_fp(task);
	frame.pc = thread_saved_pc(task);
	do {
		sprintf_s(buf, sizeof(buf) - 1, "%ps", (void *)(uintptr_t)frame.pc);
		for (i = 0; i < ARRAY_SIZE(g_lock_list); i++) {
			if (!strcmp(buf, g_lock_list[i].lock_symbol))
				break;
		}
		if (i != ARRAY_SIZE(g_lock_list))
			type = g_lock_list[i].type;

		last_fp = frame.fp;
	} while (!common_unwind_frame(task, &frame));

	return type;
}

static unsigned long identify_lock_holder(unsigned long lock_addr, enum lock_type type)
{
	unsigned long holder;
	struct mutex *mutex;
	struct rw_semaphore *rw_sem;

	switch (type) {
	case RW_SEM:
		rw_sem = (struct rw_semaphore *)(uintptr_t)lock_addr;
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 4, 0)
		holder = (unsigned long)rw_sem->owner;
#else
		holder = atomic_long_read(&rw_sem->owner);
#endif
		break;
	case MUTEX:
		mutex = (struct mutex *)lock_addr;
		holder = atomic_long_read(&mutex->owner);
		holder = holder & ~MUTEX_FLAG_MASK;
		break;
	case SEM:
	default:
		holder = 0;
		break;
	}

	return holder;
}

static struct task_struct *get_lock_holder(struct task_struct *task)
{
	unsigned long lock_addr;
	struct task_struct *holder;
	enum lock_type type;

	lock_addr = get_lock_addr(task);
	if (!lock_addr)
		return NULL;

	type = get_lock_type(task);
	if (type == UNKNOWN) {
		MD_PRINT("lock type is not predefined\n");
		return NULL;
	}

	holder = (struct task_struct *)(uintptr_t)identify_lock_holder(lock_addr, type);
	if (!holder) {
		MD_PRINT("lock struct don't have owner or lock holder is NULL\n");
		return NULL;
	}

	if (!microdump_check_addr_valid((unsigned long)(uintptr_t)holder)) {
		MD_PRINT("holder is invalid\n");
		return NULL;
	}

	return holder;
}

static void traverse_lock_holders(struct task_struct *entry_task)
{
	int i;
	struct task_struct *task = entry_task;

	for (i = 0; i < MAX_CHECK_DEEP; i++) {
		task = get_lock_holder(task);
		if (!task)
			return;

#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 15, 0))
		MD_PRINT("lock:%d holder info task_addr:0x%016lx, name:%s, pid:%d, tgid:%d, state:%d\n",
			 i, task, task->comm, task->pid, task->tgid, task->state);
		switch (task->state) {
#else
		MD_PRINT("lock:%d holder info task_addr:0x%016lx, name:%s, pid:%d, tgid:%d, __state:%d\n",
			i, task, task->comm, task->pid, task->tgid, task->__state);
		switch (task->__state) {
#endif
		case TASK_UNINTERRUPTIBLE:
			common_show_stack(task, NULL, KERN_INFO);
			break;
		case TASK_DEAD:
		case TASK_KILLABLE:
			return;
		default:
			common_show_stack(task, NULL, KERN_INFO);
			return;
		}
	}
}

void microdump_hungtask_lock_dump(void)
{
	struct task_struct *hung_task;
	struct task_struct *g, *task;
	struct task_struct *holder;
	char task_state;
	pid_t pid;

	pid = get_hung_pid();
	if (pid < 0) {
		MD_PRINT("get hung pid failed\n");
		return;
	}

	hung_task = get_hung_task(pid);
	if (!hung_task) {
		MD_PRINT("get hung task struct failed\n");
		return;
	}
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 15, 0))
	MD_PRINT("hung task info name:%s, pid:%d, tgid:%d, state:%d\n",
		 hung_task->comm, hung_task->pid, hung_task->tgid, hung_task->state);
#else
	MD_PRINT("hung task info name:%s, pid:%d, tgid:%d, state:%d\n",
		hung_task->comm, hung_task->pid, hung_task->tgid, hung_task->__state);
#endif
	traverse_lock_holders(hung_task);

	MD_PRINT("now traverse all D-state task are waiting which lock\n");
	for_each_process_thread(g, task) {
		task_state = task_state_to_char(task);
		if (task_state == 'D') {
			holder = get_lock_holder(task);
			if (holder)
				pr_cont(" held by %s\n", holder->comm);
		}
	}
}
