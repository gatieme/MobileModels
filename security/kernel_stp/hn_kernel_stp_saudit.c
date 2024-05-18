/*
 * Copyright (c) Honor Device Co., Ltd. 2021-2021. All rights reserved.
 * Description: the hn_kernel_stp_saudit.c for kernel stp
 * Author: jiayunlong <jiayunlong@hihonor.com>
 * Create: 2021-08-30
 */
#include "hn_kernel_stp_saudit.h"

void saudit_log_end(struct saudit_buffer *sab)
{
	struct saudit_upload_work *work_node = NULL;

	if (!sab)
		return;

	if (kernel_stp_upload(sab->item, sab->info) < 0)
		pr_err("stp upload fail, %s\n", sab->item.name);
	if (sab->delay)
		mdelay(sab->delay);

	if (sab->flags & SAUDIT_ASYNC) {
		work_node = container_of(sab, struct saudit_upload_work, sab);
		kfree(work_node);
	} else {
		kfree(sab);
	}
}

static void saudit_log_end_work(struct work_struct *work)
{
	struct saudit_upload_work *work_node = NULL;

	work_node = container_of(work, struct saudit_upload_work, worker);
	saudit_log_end(&work_node->sab);
}

void saudit_log_stack(struct saudit_buffer *sab)
{
	unsigned long entries[SAUDIT_STACK_DEPTH] = {0};
	unsigned int trace_nr_entries = 0;
	unsigned int generated = 0;
	unsigned int i = 0;
	unsigned int size = 0;
	char * buf = NULL;
#if LINUX_VERSION_CODE <= KERNEL_VERSION(5, 4 , 0)
	struct stack_trace trace = {
		.nr_entries = 0,
		.entries = entries,
		.max_entries = SAUDIT_STACK_DEPTH,
		.skip = SAUDIT_SELF_DEPTH,
	};
#endif
	if (!sab)
		return;

	if (sab->offset >= SAUDIT_BUFSIZ - 1)
		return;
#if LINUX_VERSION_CODE <= KERNEL_VERSION(5, 4 , 0)
	save_stack_trace(&trace);
	sab->offset += snprint_stack_trace(sab->info + sab->offset,
		SAUDIT_BUFSIZ - sab->offset - 1, &trace, 0);
#else
    trace_nr_entries = stack_trace_save(entries, SAUDIT_STACK_DEPTH, SAUDIT_SELF_DEPTH-1);
	buf = sab->info + sab->offset;
	size = SAUDIT_BUFSIZ - sab->offset - 1;
	for (i = 0; i < trace_nr_entries && size; i++) {
 		generated = snprintf(buf, size, "%*c%pS\n", 1, ' ',
 				     (void *)entries[i]);

 		sab->offset += generated;
 		if (generated >= size) {
 			buf += size;
 			size = 0;
 		} else {
 			buf += generated;
 			size -= generated;
 		}
 	}
#endif
	if (sab->offset >= SAUDIT_BUFSIZ)
		sab->offset = SAUDIT_BUFSIZ - 1;

	sab->info[sab->offset] = '\0';
}

static void saudit_log_vformat(struct saudit_buffer *sab, const char *fmt,
	va_list args)
{
	if (!sab)
		return;

	if (sab->offset >= SAUDIT_BUFSIZ - 1)
		return;
	sab->offset += vsnprintf(sab->info + sab->offset,
		SAUDIT_BUFSIZ - sab->offset - 1, fmt, args);
	if (sab->offset >= SAUDIT_BUFSIZ)
		sab->offset = SAUDIT_BUFSIZ - 1;
	sab->info[sab->offset] = '\0';
}

void saudit_log_format(struct saudit_buffer *sab, const char *fmt, ...)
{
	va_list args;

	if (!sab || !fmt)
		return;

	va_start(args, fmt);
	saudit_log_vformat(sab, fmt, args);
	va_end(args);
}

static void saudit_log_config(struct saudit_buffer *sab, int idx, int status,
	unsigned int flags)
{
	const struct stp_item_info *attr = NULL;

	if (!sab)
		return;

	sab->flags = flags;
	attr = get_item_info_by_idx(idx);
	if (!attr) {
		pr_err("get item attr %d fail\n", idx);
		return;
	}
	sab->item.id = attr->id;
	sab->item.status = status;
	sab->item.credible = (sab->flags & SAUDIT_REF) ?
		STP_REFERENCE : STP_CREDIBLE;
	(void)strncpy(sab->item.name, attr->name, STP_ITEM_NAME_LEN - 1);
	sab->item.name[STP_ITEM_NAME_LEN - 1] = '\0';

	switch (idx) {
	case KEY_FILES:
		sab->item.version = 1;
		break;
	case USERCOPY:
	case CFI:
		sab->flags |= SAUDIT_TRACE;
		sab->delay = 1000; /* 1s */
		break;
	case DOUBLE_FREE:
		sab->flags |= SAUDIT_TRACE;
		break;
	default:
		break;
	}
}

struct saudit_buffer *saudit_log_start(unsigned int flags)
{
	struct saudit_upload_work *work_node = NULL;
	struct saudit_buffer *sab = NULL;

	if (flags & SAUDIT_ASYNC) {
		work_node = kzalloc(sizeof(*work_node), GFP_ATOMIC);
		if (work_node)
			sab = &work_node->sab;
	} else {
		sab = kzalloc(sizeof(*sab), GFP_ATOMIC);
	}
	return sab;
}

void saudit_log(int idx, int status, unsigned int flags, const char *fmt, ...)
{
	va_list args;
#if LINUX_VERSION_CODE <= KERNEL_VERSION(5, 4 , 0)
	struct timeval tv = {0};
#else
	struct timespec64 ts = {0};
#endif
	struct saudit_buffer *sab = NULL;
	struct saudit_upload_work *work_node = NULL;

	if (flags & SAUDIT_ATOMIC) {
		if (in_irq() || in_softirq() || irqs_disabled())
			return;
	}

	sab = saudit_log_start(flags);
	if (!sab) {
		pr_err("out of memory in saudit_log_start\n");
		return;
	}
    memset(sab, 0, sizeof(*sab));
	saudit_log_config(sab, idx, status, flags);

#if LINUX_VERSION_CODE <= KERNEL_VERSION(5, 4 , 0)
	do_gettimeofday(&tv);
	saudit_log_format(sab,
		"time=%ull,pid=%d,pcomm=%.20s,gid=%d,gcomm=%.20s,",
		(unsigned long long)tv.tv_sec, current->pid, current->comm,
		current->tgid, current->group_leader->comm);
#else
	ktime_get_boottime_ts64(&ts);
	saudit_log_format(sab,
		"time=%ull,pid=%d,pcomm=%.20s,gid=%d,gcomm=%.20s,",
		(unsigned long long)ts.tv_sec, current->pid, current->comm,
		current->tgid, current->group_leader->comm);
#endif
	if (fmt) {
		va_start(args, fmt);
		saudit_log_vformat(sab, fmt, args);
		va_end(args);
	}

	if (sab->flags & SAUDIT_TRACE) {
		saudit_log_format(sab, ",stack=");
		saudit_log_stack(sab);
	}
	if (sab->flags & SAUDIT_ASYNC) {
		work_node = container_of(sab, struct saudit_upload_work, sab);
		INIT_WORK(&work_node->worker, saudit_log_end_work);
		queue_work(system_long_wq, &work_node->worker);
	} else {
		saudit_log_end(sab);
	}
}
EXPORT_SYMBOL(saudit_log);
