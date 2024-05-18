/*
 * util_clamp_qc.c
 *
 * task util limit
 *
 * Copyright (c) 2012-2020 Honor Technologies Co., Ltd.
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

#include <linux/sched.h>
#include <uapi/linux/sched/types.h>
#include <trace/events/sched.h>

#ifdef CONFIG_SCHED_TASK_UTIL_CLAMP

int set_task_max_util(struct task_struct *p, unsigned int max_util)
{
	int ret;
	struct sched_attr attr = {
		.size = sizeof(attr),
		.sched_policy = -1,
		.sched_flags = SCHED_FLAG_UTIL_CLAMP_MAX | SCHED_FLAG_KEEP_PARAMS,
		.sched_util_min = min(max_util, (unsigned int)p->uclamp_req[UCLAMP_MIN].value),
		.sched_util_max = max_util,
	};

	if (!p) {
		pr_err("%s invalid arg\n", __func__);
		return -EINVAL;
	}

	if (max_util == SCHED_CAPACITY_SCALE) {
		p->uclamp_req[UCLAMP_MAX].user_defined = false;
		attr.sched_flags &= ~SCHED_FLAG_UTIL_CLAMP_MAX;
	}
	ret = sched_setattr_nocheck(p, &attr);

	trace_set_task_util(p->pid, UCLAMP_MAX, max_util, ret,
		p->uclamp_req[UCLAMP_MIN].user_defined, p->uclamp_req[UCLAMP_MIN].value,
		p->uclamp_req[UCLAMP_MAX].user_defined, p->uclamp_req[UCLAMP_MAX].value);

	if (ret) {
		pr_err("%s sched_setattr fail %d\n", __func__, ret);
		return -EINVAL;
	}
	return 0;
}

int set_task_min_util(struct task_struct *p, unsigned int min_util)
{
	int ret;
	struct sched_attr attr = {
		.size = sizeof(attr),
		.sched_policy = -1,
		.sched_flags = SCHED_FLAG_UTIL_CLAMP_MIN | SCHED_FLAG_KEEP_PARAMS,
		.sched_util_min = min_util,
		.sched_util_max = max(min_util, (unsigned int)p->uclamp_req[UCLAMP_MAX].value),
	};

	if (!p) {
		pr_err("%s invalid arg\n", __func__);
		return -EINVAL;
	}

	if (min_util == 0) {
		p->uclamp_req[UCLAMP_MIN].user_defined = false;
		attr.sched_flags &= ~SCHED_FLAG_UTIL_CLAMP_MIN;
	}
	ret = sched_setattr_nocheck(p, &attr);

	trace_set_task_util(p->pid, UCLAMP_MIN, min_util, ret,
		p->uclamp_req[UCLAMP_MIN].user_defined, p->uclamp_req[UCLAMP_MIN].value,
		p->uclamp_req[UCLAMP_MAX].user_defined, p->uclamp_req[UCLAMP_MAX].value);

	if (ret) {
		pr_err("%s sched_setattr fail %d\n", __func__, ret);
		return -EINVAL;
	}
	return 0;
}

#endif
