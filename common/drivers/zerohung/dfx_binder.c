/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2022. All rights reserved.
 * Description: Support Binder Maintenance and Test info for DFX.
 * Author: Zhang Kuangqi <zhangkuangqi1@huawei.com>
 * Create: 2022-12-13
 */
#include <linux/module.h>
#include <linux/ratelimit_types.h>
#include <linux/sched.h>

#include "binder_alloc.h"

#define PRINT_TIMEOUT 60

static char *g_binder_comm;
module_param_named(debug_comm, g_binder_comm, charp, 0644);

static pid_t g_noticed_tgid;
module_param_named(debug_tgid, g_noticed_tgid, uint, 0644);

pid_t get_noticed_tgid(void)
{
	return g_noticed_tgid;
}

static int set_binder_flush(const char *val, const struct kernel_param *kp)
{
	int ret;
	struct task_struct *p = NULL;

	ret = param_set_int(val, kp);

	if (g_binder_comm == NULL)
		return ret;

	g_noticed_tgid = -ESRCH;
	rcu_read_lock();
	for_each_process(p) {
		if (strstr(p->comm, g_binder_comm)) {
			g_noticed_tgid = p->tgid;
			break;
		}
	}
	rcu_read_unlock();

	return ret;
}

static int g_binder_flush;
module_param_call(debug_flush, set_binder_flush, param_get_int, &g_binder_flush, 0644);

bool task_need_noticed(struct task_struct *p)
{
	if (p == NULL)
		return false;

	return (strstr(p->comm, "litet") || strstr(p->comm, "tencent.mm"));
}

void binder_print_related_task(pid_t pid)
{
	struct task_struct *p = NULL;

	rcu_read_lock();
	for_each_process(p) {
		if (p->binder_pid == pid)
			pr_err("binder_proc_check: %s %d state: %d hold %d's binder_proc\n",
				p->comm, p->pid, p->state, pid);
	}
	rcu_read_unlock();

	return;
}

bool check_buffer_print_task(void)
{
	return (strstr(current->group_leader->comm, "system_server") ||
		(g_binder_comm && strstr(current->group_leader->comm, g_binder_comm)));
}

void print_binder_allocated_buffer(struct binder_alloc *alloc, bool is_async)
{
	size_t buffer_size;
	struct rb_node *n = NULL;
	struct binder_buffer *buffer = NULL;

	static DEFINE_RATELIMIT_STATE(buffer_print_rs, PRINT_TIMEOUT * HZ, 1);

	if (!__ratelimit(&buffer_print_rs))
		return;

	if (!alloc->buffer_print_noticed)
		return;

	for (n = rb_first(&alloc->allocated_buffers); n != NULL; n = rb_next(n)) {
		buffer = rb_entry(n, struct binder_buffer, rb_node);
		buffer_size = get_buffer_size(alloc, buffer);
		if (!is_async)
			pr_err("binder_buffer: pid:%d buffer_size:%zd\n", buffer->pid, buffer_size);
		else if (buffer->async_transaction & is_async)
			pr_err("binder_buffer: pid:%d async buffer_size:%zd\n", buffer->pid, buffer_size);
	}
}
