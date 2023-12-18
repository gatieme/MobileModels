/* SPDX-License-Identifier: GPL-2.0 */
#undef TRACE_SYSTEM
#define TRACE_SYSTEM sched

#if !defined(_TRACE_SCHED_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_SCHED_H

#include <linux/sched/numa_balancing.h>
#include <linux/tracepoint.h>
#include <linux/binfmts.h>
#include <linux/kallsyms.h>
#include <linux/module.h>

#ifdef CONFIG_HW_QOS_THREAD
#include <chipset_common/hwqos/hwqos_common.h>
#endif

/*
 * Tracepoint for calling kthread_stop, performed to end a kthread:
 */
TRACE_EVENT(sched_kthread_stop,

	TP_PROTO(struct task_struct *t),

	TP_ARGS(t),

	TP_STRUCT__entry(
		__array(	char,	comm,	TASK_COMM_LEN	)
		__field(	pid_t,	pid			)
	),

	TP_fast_assign(
		memcpy(__entry->comm, t->comm, TASK_COMM_LEN);
		__entry->pid	= t->pid;
	),

	TP_printk("comm=%s pid=%d", __entry->comm, __entry->pid)
);

/*
 * Tracepoint for the return value of the kthread stopping:
 */
TRACE_EVENT(sched_kthread_stop_ret,

	TP_PROTO(int ret),

	TP_ARGS(ret),

	TP_STRUCT__entry(
		__field(	int,	ret	)
	),

	TP_fast_assign(
		__entry->ret	= ret;
	),

	TP_printk("ret=%d", __entry->ret)
);

/*
 * Tracepoint for waking up a task:
 */
DECLARE_EVENT_CLASS(sched_wakeup_template,

	TP_PROTO(struct task_struct *p),

	TP_ARGS(__perf_task(p)),

	TP_STRUCT__entry(
		__array(	char,	comm,	TASK_COMM_LEN	)
		__field(	pid_t,	pid			)
		__field(	int,	prio			)
		__field(	int,	success			)
		__field(	int,	target_cpu		)
		__field(	unsigned long, cpus_mask)
		__field(	int, min_util)
		__field(	unsigned int, vip_prio)
		__field(	int, static_vip)
		__field(	u64, dynamic_vip)
		__field(	int, tg_latency_offset)
		__field(	int, latency_prio)
	),

	TP_fast_assign(
		memcpy(__entry->comm, p->comm, TASK_COMM_LEN);
		__entry->pid		= p->pid;
		__entry->prio		= p->prio; /* XXX SCHED_DEADLINE */
		__entry->success	= 1; /* rudiment, kill when possible */
		__entry->target_cpu	= task_cpu(p);
		__entry->cpus_mask = cpumask_bits(&p->cpus_mask)[0];
#ifdef CONFIG_UCLAMP_TASK
		__entry->min_util = p->uclamp[UCLAMP_MIN].value;
#else
		__entry->min_util = 0;
#endif
#ifdef CONFIG_HUAWEI_SCHED_VIP
		__entry->vip_prio = p->vip_prio;
#else
		__entry->vip_prio = 0;
#endif
#ifdef CONFIG_HW_VIP_THREAD
		__entry->static_vip = p->static_vip;
		__entry->dynamic_vip = atomic64_read(&p->dynamic_vip);
#else
		__entry->static_vip = 0;
		__entry->dynamic_vip = 0;
#endif
#ifdef CONFIG_SCHED_LATENCY_NICE
		__entry->tg_latency_offset = tg_latency_offset(p);
		__entry->latency_prio = p->latency_prio;
#else
		__entry->tg_latency_offset = 0;
		__entry->latency_prio = 20;
#endif
	),

	TP_printk("comm=%s pid=%d prio=%d target_cpu=%03d affinity=%#lx uclamp_min=%d vip_prio=%u static_vip=%d dynamic_vip=%lu latency_prio=%d/%d",
		  __entry->comm, __entry->pid, __entry->prio, __entry->target_cpu,
		  __entry->cpus_mask, __entry->min_util, __entry->vip_prio,
		  __entry->static_vip, __entry->dynamic_vip, __entry->latency_prio,
		  __entry->tg_latency_offset)
);

/*
 * Tracepoint called when waking a task; this tracepoint is guaranteed to be
 * called from the waking context.
 */
DEFINE_EVENT(sched_wakeup_template, sched_waking,
	     TP_PROTO(struct task_struct *p),
	     TP_ARGS(p));

/*
 * Tracepoint called when the task is actually woken; p->state == TASK_RUNNNG.
 * It is not always called from the waking context.
 */
DEFINE_EVENT(sched_wakeup_template, sched_wakeup,
	     TP_PROTO(struct task_struct *p),
	     TP_ARGS(p));

/*
 * Tracepoint for waking up a new task:
 */
DEFINE_EVENT(sched_wakeup_template, sched_wakeup_new,
	     TP_PROTO(struct task_struct *p),
	     TP_ARGS(p));

#ifdef CONFIG_HW_QOS_THREAD
/*
 *  * Tracepoint for sched qos
 *   */
DECLARE_EVENT_CLASS(sched_qos_template,

		TP_PROTO(struct task_struct *p, struct transact_qos *tq, int type),

		TP_ARGS(__perf_task(p), tq, type),

		TP_STRUCT__entry(
			__array(char,   comm,   TASK_COMM_LEN)
			__field(pid_t,  pid)
			__field(int,    prio)
			__field(int,    success)
			__field(int,    target_cpu)
			__field(int,    dynamic_qos)
			__field(int,    vip_prio)
			__field(int,    min_util)
			__field(int,    trans_qos)
			__field(pid_t,  trans_from)
			__field(int,    trans_type)
			__field(int,    trans_flags)
			__field(int,    type)
			),

		TP_fast_assign(
				memcpy(__entry->comm, p->comm, TASK_COMM_LEN);
				__entry->pid         = p->pid;
				__entry->prio        = p->prio;
				__entry->success     = 1; /* rudiment, kill when possible */
				__entry->target_cpu  = task_cpu(p);
				__entry->dynamic_qos = get_task_set_qos(p);
#ifdef CONFIG_HUAWEI_SCHED_VIP
				__entry->vip_prio = p->vip_prio;
#else
				__entry->vip_prio = -1;
#endif
#ifdef CONFIG_SCHED_HISI_UTIL_CLAMP
				__entry->min_util = p->uclamp.min_util;
#else
				__entry->min_util = -1;
#endif
				__entry->trans_qos   = get_task_trans_qos(tq);
				__entry->trans_from  = (tq == NULL) ? 0 : tq->trans_pid;
				__entry->trans_type  = (tq == NULL) ? 0 : tq->trans_type;
				__entry->trans_flags = atomic_read(&p->trans_flags);
		__entry->type        = type;
		),
		TP_printk("comm=%s pid=%d prio=%d target_cpu=%03d dynamic_qos=%d trans_qos=%d vip_prio=%d min_util=%d trans_from=%d trans_type=%d trans_flags=%d type=%d",
				__entry->comm, __entry->pid, __entry->prio,
				__entry->target_cpu, __entry->dynamic_qos,
				__entry->trans_qos, __entry->vip_prio,
				__entry->min_util,
				__entry->trans_from, __entry->trans_type,
				__entry->trans_flags, __entry->type)
		);

		DEFINE_EVENT(sched_qos_template, sched_qos,
				TP_PROTO(struct task_struct *p, struct transact_qos *tq, int type),
				TP_ARGS(p, tq, type));
#endif

#ifdef CONFIG_HW_VIP_THREAD
/*
 * Tracepoint for sched vip
 */
DECLARE_EVENT_CLASS(sched_vip_template,

	TP_PROTO(struct task_struct *p, char *msg),

	TP_ARGS(__perf_task(p), msg),

	TP_STRUCT__entry(
		__array(	char,	comm,	TASK_COMM_LEN	)
		__field(	pid_t,	pid			)
		__field(	int,	prio			)
		__array(	char,	msg, 	VIP_MSG_LEN	)
		__field(	int,	target_cpu		)
		__field(    u64,    dynamic_vip)
		__field(    int,    vip_depth)
	),

	TP_fast_assign(
		memcpy(__entry->comm, p->comm, TASK_COMM_LEN);
		__entry->pid		= p->pid;
		__entry->prio		= p->prio;
		memcpy(__entry->msg, msg, min((size_t)VIP_MSG_LEN, strlen(msg)+1));
		__entry->target_cpu	= task_cpu(p);
		__entry->dynamic_vip   = atomic64_read(&p->dynamic_vip);
		__entry->vip_depth     = p->vip_depth;
	),

	TP_printk("comm=%s pid=%d prio=%d msg=%s target_cpu=%03d dynamic_vip:%llx vip_depth:%d",
		  __entry->comm, __entry->pid, __entry->prio,
		  __entry->msg, __entry->target_cpu, __entry->dynamic_vip, __entry->vip_depth)
);

DEFINE_EVENT(sched_vip_template, sched_vip_queue_op,
         TP_PROTO(struct task_struct *p, char *msg),
	     TP_ARGS(p, msg));

DEFINE_EVENT(sched_vip_template, sched_vip_sched,
         TP_PROTO(struct task_struct *p, char *msg),
	     TP_ARGS(p, msg));
#endif

#ifdef CONFIG_HW_GRADED_SCHED
DECLARE_EVENT_CLASS(sched_graded_template,

	TP_PROTO(struct task_struct* t, int increase),

	TP_ARGS(t, increase),

	TP_STRUCT__entry(
		__field(	int,	pid)
		__field(	int,	tgid)
		__field(	int,	prio)
		__field(	int,	static_prio)
		__field(	int,	graded_prio)
		__field(	int,	increase)
		__array(	char,	comm,	TASK_COMM_LEN)
	),

	TP_fast_assign(
		__entry->pid = t->pid;
		__entry->tgid = t->tgid;
		__entry->prio = t->prio;
		__entry->static_prio = t->static_prio;
		__entry->graded_prio = t->graded_prio;
		__entry->increase = increase;
		memcpy(__entry->comm, t->comm, TASK_COMM_LEN);
	),

	TP_printk("comm=%s, pid=%d, tgid=%d, prio=%d, static_prio=%d, graded_prio=%d, increase=%d",
		__entry->comm,
		__entry->pid,
		__entry->tgid,
		__entry->prio,
		__entry->static_prio,
		__entry->graded_prio,
		__entry->increase)
);

DEFINE_EVENT(sched_graded_template, sched_update_graded_nice,
		TP_PROTO(struct task_struct *p, int increase),
		TP_ARGS(p, increase));

DEFINE_EVENT(sched_graded_template, sched_init_graded_nice,
		TP_PROTO(struct task_struct *p, int increase),
		TP_ARGS(p, increase));
#endif

#ifdef CREATE_TRACE_POINTS
static inline long __trace_sched_switch_state(bool preempt, struct task_struct *p)
{
	unsigned int state;

#ifdef CONFIG_SCHED_DEBUG
	BUG_ON(p != current);
#endif /* CONFIG_SCHED_DEBUG */

	/*
	 * Preemption ignores task state, therefore preempted tasks are always
	 * RUNNING (we will not have dequeued if state != RUNNING).
	 */
	if (preempt)
		return TASK_REPORT_MAX;

	/*
	 * task_state_index() uses fls() and returns a value from 0-8 range.
	 * Decrement it by 1 (except TASK_RUNNING state i.e 0) before using
	 * it for left shift operation to get the correct task->state
	 * mapping.
	 */
	state = task_state_index(p);

	return state ? (1 << (state - 1)) : state;
}
#endif /* CREATE_TRACE_POINTS */

/*
 * Tracepoint for task switches, performed by the scheduler:
 */
TRACE_EVENT(sched_switch,

	TP_PROTO(bool preempt,
		 struct task_struct *prev,
		 struct task_struct *next),

	TP_ARGS(preempt, prev, next),

	TP_STRUCT__entry(
		__array(	char,	prev_comm,	TASK_COMM_LEN	)
		__field(	pid_t,	prev_pid			)
		__field(	int,	prev_prio			)
		__field(	long,	prev_state			)
		__array(	char,	next_comm,	TASK_COMM_LEN	)
		__field(	pid_t,	next_pid			)
		__field(	int,	next_prio			)
	),

	TP_fast_assign(
		memcpy(__entry->next_comm, next->comm, TASK_COMM_LEN);
		__entry->prev_pid	= prev->pid;
		__entry->prev_prio	= prev->prio;
		__entry->prev_state	= __trace_sched_switch_state(preempt, prev);
		memcpy(__entry->prev_comm, prev->comm, TASK_COMM_LEN);
		__entry->next_pid	= next->pid;
		__entry->next_prio	= next->prio;
		/* XXX SCHED_DEADLINE */
	),

	TP_printk("prev_comm=%s prev_pid=%d prev_prio=%d prev_state=%s%s ==> next_comm=%s next_pid=%d next_prio=%d",
		__entry->prev_comm, __entry->prev_pid, __entry->prev_prio,

		(__entry->prev_state & (TASK_REPORT_MAX - 1)) ?
		  __print_flags(__entry->prev_state & (TASK_REPORT_MAX - 1), "|",
				{ TASK_INTERRUPTIBLE, "S" },
				{ TASK_UNINTERRUPTIBLE, "D" },
				{ __TASK_STOPPED, "T" },
				{ __TASK_TRACED, "t" },
				{ EXIT_DEAD, "X" },
				{ EXIT_ZOMBIE, "Z" },
				{ TASK_PARKED, "P" },
				{ TASK_DEAD, "I" }) :
		  "R",

		__entry->prev_state & TASK_REPORT_MAX ? "+" : "",
		__entry->next_comm, __entry->next_pid, __entry->next_prio)
);

/*
 * Tracepoint for a task being migrated:
 */
TRACE_EVENT(sched_migrate_task,

	TP_PROTO(struct task_struct *p, int dest_cpu),

	TP_ARGS(p, dest_cpu),

	TP_STRUCT__entry(
		__array(	char,	comm,	TASK_COMM_LEN	)
		__field(	pid_t,	pid			)
		__field(	int,	prio			)
		__field(	int,	orig_cpu		)
		__field(	int,	dest_cpu		)
		__field(	int,	running			)
	),

	TP_fast_assign(
		memcpy(__entry->comm, p->comm, TASK_COMM_LEN);
		__entry->pid		= p->pid;
		__entry->prio		= p->prio; /* XXX SCHED_DEADLINE */
		__entry->orig_cpu	= task_cpu(p);
		__entry->dest_cpu	= dest_cpu;
		__entry->running	= (p->state == TASK_RUNNING);
	),

	TP_printk("comm=%s pid=%d prio=%d orig_cpu=%d dest_cpu=%d running=%d",
		  __entry->comm, __entry->pid, __entry->prio,
		  __entry->orig_cpu, __entry->dest_cpu,
		  __entry->running)
);

DECLARE_EVENT_CLASS(sched_process_template,

	TP_PROTO(struct task_struct *p),

	TP_ARGS(p),

	TP_STRUCT__entry(
		__array(	char,	comm,	TASK_COMM_LEN	)
		__field(	pid_t,	pid			)
		__field(	int,	prio			)
	),

	TP_fast_assign(
		memcpy(__entry->comm, p->comm, TASK_COMM_LEN);
		__entry->pid		= p->pid;
		__entry->prio		= p->prio; /* XXX SCHED_DEADLINE */
	),

	TP_printk("comm=%s pid=%d prio=%d",
		  __entry->comm, __entry->pid, __entry->prio)
);

/*
 * Tracepoint for freeing a task:
 */
DEFINE_EVENT(sched_process_template, sched_process_free,
	     TP_PROTO(struct task_struct *p),
	     TP_ARGS(p));

/*
 * Tracepoint for a task exiting:
 */
DEFINE_EVENT(sched_process_template, sched_process_exit,
	     TP_PROTO(struct task_struct *p),
	     TP_ARGS(p));

/*
 * Tracepoint for waiting on task to unschedule:
 */
DEFINE_EVENT(sched_process_template, sched_wait_task,
	TP_PROTO(struct task_struct *p),
	TP_ARGS(p));

/*
 * Tracepoint for a waiting task:
 */
TRACE_EVENT(sched_process_wait,

	TP_PROTO(struct pid *pid),

	TP_ARGS(pid),

	TP_STRUCT__entry(
		__array(	char,	comm,	TASK_COMM_LEN	)
		__field(	pid_t,	pid			)
		__field(	int,	prio			)
	),

	TP_fast_assign(
		memcpy(__entry->comm, current->comm, TASK_COMM_LEN);
		__entry->pid		= pid_nr(pid);
		__entry->prio		= current->prio; /* XXX SCHED_DEADLINE */
	),

	TP_printk("comm=%s pid=%d prio=%d",
		  __entry->comm, __entry->pid, __entry->prio)
);

/*
 * Tracepoint for do_fork:
 */
TRACE_EVENT(sched_process_fork,

	TP_PROTO(struct task_struct *parent, struct task_struct *child),

	TP_ARGS(parent, child),

	TP_STRUCT__entry(
		__array(	char,	parent_comm,	TASK_COMM_LEN	)
		__field(	pid_t,	parent_pid			)
		__array(	char,	child_comm,	TASK_COMM_LEN	)
		__field(	pid_t,	child_pid			)
	),

	TP_fast_assign(
		memcpy(__entry->parent_comm, parent->comm, TASK_COMM_LEN);
		__entry->parent_pid	= parent->pid;
		memcpy(__entry->child_comm, child->comm, TASK_COMM_LEN);
		__entry->child_pid	= child->pid;
	),

	TP_printk("comm=%s pid=%d child_comm=%s child_pid=%d",
		__entry->parent_comm, __entry->parent_pid,
		__entry->child_comm, __entry->child_pid)
);

/*
 * Tracepoint for exec:
 */
TRACE_EVENT(sched_process_exec,

	TP_PROTO(struct task_struct *p, pid_t old_pid,
		 struct linux_binprm *bprm),

	TP_ARGS(p, old_pid, bprm),

	TP_STRUCT__entry(
		__string(	filename,	bprm->filename	)
		__field(	pid_t,		pid		)
		__field(	pid_t,		old_pid		)
	),

	TP_fast_assign(
		__assign_str(filename, bprm->filename);
		__entry->pid		= p->pid;
		__entry->old_pid	= old_pid;
	),

	TP_printk("filename=%s pid=%d old_pid=%d", __get_str(filename),
		  __entry->pid, __entry->old_pid)
);


#ifdef CONFIG_SCHEDSTATS
#define DEFINE_EVENT_SCHEDSTAT DEFINE_EVENT
#define DECLARE_EVENT_CLASS_SCHEDSTAT DECLARE_EVENT_CLASS
#else
#define DEFINE_EVENT_SCHEDSTAT DEFINE_EVENT_NOP
#define DECLARE_EVENT_CLASS_SCHEDSTAT DECLARE_EVENT_CLASS_NOP
#endif

/*
 * XXX the below sched_stat tracepoints only apply to SCHED_OTHER/BATCH/IDLE
 *     adding sched_stat support to SCHED_FIFO/RR would be welcome.
 */
DECLARE_EVENT_CLASS_SCHEDSTAT(sched_stat_template,

	TP_PROTO(struct task_struct *tsk, u64 delay),

	TP_ARGS(__perf_task(tsk), __perf_count(delay)),

	TP_STRUCT__entry(
		__array( char,	comm,	TASK_COMM_LEN	)
		__field( pid_t,	pid			)
		__field( u64,	delay			)
	),

	TP_fast_assign(
		memcpy(__entry->comm, tsk->comm, TASK_COMM_LEN);
		__entry->pid	= tsk->pid;
		__entry->delay	= delay;
	),

	TP_printk("comm=%s pid=%d delay=%Lu [ns]",
			__entry->comm, __entry->pid,
			(unsigned long long)__entry->delay)
);

/*
 * Tracepoint for accounting wait time (time the task is runnable
 * but not actually running due to scheduler contention).
 */
DEFINE_EVENT_SCHEDSTAT(sched_stat_template, sched_stat_wait,
	     TP_PROTO(struct task_struct *tsk, u64 delay),
	     TP_ARGS(tsk, delay));

/*
 * Tracepoint for accounting sleep time (time the task is not runnable,
 * including iowait, see below).
 */
DEFINE_EVENT_SCHEDSTAT(sched_stat_template, sched_stat_sleep,
	     TP_PROTO(struct task_struct *tsk, u64 delay),
	     TP_ARGS(tsk, delay));

/*
 * Tracepoint for accounting iowait time (time the task is not runnable
 * due to waiting on IO to complete).
 */
DEFINE_EVENT_SCHEDSTAT(sched_stat_template, sched_stat_iowait,
	     TP_PROTO(struct task_struct *tsk, u64 delay),
	     TP_ARGS(tsk, delay));

/*
 * Tracepoint for accounting blocked time (time the task is in uninterruptible).
 */
DEFINE_EVENT_SCHEDSTAT(sched_stat_template, sched_stat_blocked,
	     TP_PROTO(struct task_struct *tsk, u64 delay),
	     TP_ARGS(tsk, delay));

/*
 * Tracepoint for recording the cause of uninterruptible sleep.
 */
#define TRACE_FUNNM_LEN_MAX 20
#define TRACE_MODNM_LEN_MAX 12

#ifdef CREATE_TRACE_POINTS
static inline void __trace_sched_blocked_detail(struct task_struct *tsk,
		unsigned long *caller, unsigned long *size,
		unsigned long *offset, char *fun, char *mod)
{
	char name[KSYM_NAME_LEN];
	char modname[MODULE_NAME_LEN];
	name[0] = '\0';
	name[KSYM_NAME_LEN - 1] = '\0';
	modname[0] = '\0';
	modname[MODULE_NAME_LEN - 1] = '\0';

	*caller = get_wchan(tsk);
	if (lookup_symbol_attrs(*caller, size, offset, modname, name)) {
		*offset = *caller;
		fun[0] = '\0';
		mod[0] = '\0';
		return;
	}

	memcpy(fun, name, TRACE_FUNNM_LEN_MAX);
	fun[TRACE_FUNNM_LEN_MAX - 1] = '\0';
	memcpy(mod, modname, TRACE_MODNM_LEN_MAX);
	mod[TRACE_MODNM_LEN_MAX - 1] = '\0';
}
#endif

TRACE_EVENT(sched_blocked_reason,

	TP_PROTO(struct task_struct *tsk),

	TP_ARGS(tsk),

	TP_STRUCT__entry(
		__field( pid_t,	pid	)
		__field( void*, caller	)
		__field( bool, io_wait	)
		__field( unsigned long, offset	)
		__field( unsigned long, size	)
		__array( char, funname, TRACE_FUNNM_LEN_MAX	)
		__array( char, modname, TRACE_MODNM_LEN_MAX	)
	),

	TP_fast_assign(
		__entry->pid	= tsk->pid;
		__entry->io_wait = tsk->in_iowait;
		__trace_sched_blocked_detail(tsk, (unsigned long*)&__entry->caller, &__entry->size, &__entry->offset,
		__entry->funname, __entry->modname);
	),

	TP_printk("pid=%d iowait=%d caller=%s+0x%lx/0x%lx [%s]", __entry->pid, __entry->io_wait, __entry->funname,
				__entry->offset,  __entry->size, __entry->modname)
);

/*
 * Tracepoint for accounting runtime (time the task is executing
 * on a CPU).
 */
DECLARE_EVENT_CLASS(sched_stat_runtime,

	TP_PROTO(struct task_struct *tsk, u64 runtime, u64 vruntime),

	TP_ARGS(tsk, __perf_count(runtime), vruntime),

	TP_STRUCT__entry(
		__array( char,	comm,	TASK_COMM_LEN	)
		__field( pid_t,	pid			)
		__field( u64,	runtime			)
		__field( u64,	vruntime			)
	),

	TP_fast_assign(
		memcpy(__entry->comm, tsk->comm, TASK_COMM_LEN);
		__entry->pid		= tsk->pid;
		__entry->runtime	= runtime;
		__entry->vruntime	= vruntime;
	),

	TP_printk("comm=%s pid=%d runtime=%Lu [ns] vruntime=%Lu [ns]",
			__entry->comm, __entry->pid,
			(unsigned long long)__entry->runtime,
			(unsigned long long)__entry->vruntime)
);

DEFINE_EVENT(sched_stat_runtime, sched_stat_runtime,
	     TP_PROTO(struct task_struct *tsk, u64 runtime, u64 vruntime),
	     TP_ARGS(tsk, runtime, vruntime));

/*
 * Tracepoint for showing priority inheritance modifying a tasks
 * priority.
 */
TRACE_EVENT(sched_pi_setprio,

	TP_PROTO(struct task_struct *tsk, struct task_struct *pi_task),

	TP_ARGS(tsk, pi_task),

	TP_STRUCT__entry(
		__array( char,	comm,	TASK_COMM_LEN	)
		__field( pid_t,	pid			)
		__field( int,	oldprio			)
		__field( int,	newprio			)
	),

	TP_fast_assign(
		memcpy(__entry->comm, tsk->comm, TASK_COMM_LEN);
		__entry->pid		= tsk->pid;
		__entry->oldprio	= tsk->prio;
		__entry->newprio	= pi_task ?
				min(tsk->normal_prio, pi_task->prio) :
				tsk->normal_prio;
		/* XXX SCHED_DEADLINE bits missing */
	),

	TP_printk("comm=%s pid=%d oldprio=%d newprio=%d",
			__entry->comm, __entry->pid,
			__entry->oldprio, __entry->newprio)
);

#ifdef CONFIG_HW_FUTEX_PI
#ifdef CONFIG_HW_QOS_THREAD
TRACE_EVENT(sched_pi_setqos,

	TP_PROTO(struct task_struct *tsk, int oldqos, int newqos),

	TP_ARGS(tsk, oldqos, newqos),

	TP_STRUCT__entry(
		__array(char, comm, TASK_COMM_LEN)
		__field(pid_t, pid)
		__field(int, oldqos)
		__field(int, newqos)
	),

	TP_fast_assign(
		memcpy(__entry->comm, tsk->comm, TASK_COMM_LEN);
		__entry->pid = tsk->pid;
		__entry->oldqos = oldqos;
		__entry->newqos	= newqos;
		/* XXX SCHED_DEADLINE bits missing */
	),

	TP_printk("comm=%s pid=%d oldqos=%d newqos=%d",
			__entry->comm, __entry->pid,
			__entry->oldqos, __entry->newqos)
);
#endif /* CONFIG_HW_QOS_THREAD */

#ifdef CONFIG_HW_VIP_THREAD
TRACE_EVENT(sched_pi_setvip,

	TP_PROTO(struct task_struct *tsk, int oldvip, int newvip),

	TP_ARGS(tsk, oldvip, newvip),

	TP_STRUCT__entry(
		__array( char,	comm,	TASK_COMM_LEN	)
		__field( pid_t,	pid			)
		__field( int,	oldvip			)
		__field( int,	newvip			)
	),

	TP_fast_assign(
		memcpy(__entry->comm, tsk->comm, TASK_COMM_LEN);
		__entry->pid		= tsk->pid;
		__entry->oldvip		= oldvip;
		__entry->newvip		= newvip;
		/* XXX SCHED_DEADLINE bits missing */
	),

	TP_printk("comm=%s pid=%d oldvip=%d newvip=%d",
			__entry->comm, __entry->pid,
			__entry->oldvip, __entry->newvip)
);
#endif /* CONFIG_HW_VIP_THREAD */

#ifdef CONFIG_HUAWEI_SCHED_VIP
TRACE_EVENT(sched_pi_setvipprio,

	TP_PROTO(struct task_struct *tsk, int oldvipprio, int newvipprio),

	TP_ARGS(tsk, oldvipprio, newvipprio),

	TP_STRUCT__entry(
		__array(char, comm, TASK_COMM_LEN)
		__field(pid_t, pid)
		__field(int, oldvipprio)
		__field(int, newvipprio)
	),

	TP_fast_assign(
		memcpy(__entry->comm, tsk->comm, TASK_COMM_LEN);
		__entry->pid = tsk->pid;
		__entry->oldvipprio = oldvipprio;
		__entry->newvipprio = newvipprio;
		/* XXX SCHED_DEADLINE bits missing */
	),

	TP_printk("comm=%s pid=%d oldvipprio=%d newvipprio=%d",
			__entry->comm, __entry->pid,
			__entry->oldvipprio, __entry->newvipprio)
);
#endif /* CONFIG_HUAWEI_SCHED_VIP */
#endif /* CONFIG_HW_FUTEX_PI */

#ifdef CONFIG_DETECT_HUNG_TASK
TRACE_EVENT(sched_process_hang,
	TP_PROTO(struct task_struct *tsk),
	TP_ARGS(tsk),

	TP_STRUCT__entry(
		__array( char,	comm,	TASK_COMM_LEN	)
		__field( pid_t,	pid			)
	),

	TP_fast_assign(
		memcpy(__entry->comm, tsk->comm, TASK_COMM_LEN);
		__entry->pid = tsk->pid;
	),

	TP_printk("comm=%s pid=%d", __entry->comm, __entry->pid)
);
#endif /* CONFIG_DETECT_HUNG_TASK */

/*
 * Tracks migration of tasks from one runqueue to another. Can be used to
 * detect if automatic NUMA balancing is bouncing between nodes.
 */
TRACE_EVENT(sched_move_numa,

	TP_PROTO(struct task_struct *tsk, int src_cpu, int dst_cpu),

	TP_ARGS(tsk, src_cpu, dst_cpu),

	TP_STRUCT__entry(
		__field( pid_t,	pid			)
		__field( pid_t,	tgid			)
		__field( pid_t,	ngid			)
		__field( int,	src_cpu			)
		__field( int,	src_nid			)
		__field( int,	dst_cpu			)
		__field( int,	dst_nid			)
	),

	TP_fast_assign(
		__entry->pid		= task_pid_nr(tsk);
		__entry->tgid		= task_tgid_nr(tsk);
		__entry->ngid		= task_numa_group_id(tsk);
		__entry->src_cpu	= src_cpu;
		__entry->src_nid	= cpu_to_node(src_cpu);
		__entry->dst_cpu	= dst_cpu;
		__entry->dst_nid	= cpu_to_node(dst_cpu);
	),

	TP_printk("pid=%d tgid=%d ngid=%d src_cpu=%d src_nid=%d dst_cpu=%d dst_nid=%d",
			__entry->pid, __entry->tgid, __entry->ngid,
			__entry->src_cpu, __entry->src_nid,
			__entry->dst_cpu, __entry->dst_nid)
);

DECLARE_EVENT_CLASS(sched_numa_pair_template,

	TP_PROTO(struct task_struct *src_tsk, int src_cpu,
		 struct task_struct *dst_tsk, int dst_cpu),

	TP_ARGS(src_tsk, src_cpu, dst_tsk, dst_cpu),

	TP_STRUCT__entry(
		__field( pid_t,	src_pid			)
		__field( pid_t,	src_tgid		)
		__field( pid_t,	src_ngid		)
		__field( int,	src_cpu			)
		__field( int,	src_nid			)
		__field( pid_t,	dst_pid			)
		__field( pid_t,	dst_tgid		)
		__field( pid_t,	dst_ngid		)
		__field( int,	dst_cpu			)
		__field( int,	dst_nid			)
	),

	TP_fast_assign(
		__entry->src_pid	= task_pid_nr(src_tsk);
		__entry->src_tgid	= task_tgid_nr(src_tsk);
		__entry->src_ngid	= task_numa_group_id(src_tsk);
		__entry->src_cpu	= src_cpu;
		__entry->src_nid	= cpu_to_node(src_cpu);
		__entry->dst_pid	= dst_tsk ? task_pid_nr(dst_tsk) : 0;
		__entry->dst_tgid	= dst_tsk ? task_tgid_nr(dst_tsk) : 0;
		__entry->dst_ngid	= dst_tsk ? task_numa_group_id(dst_tsk) : 0;
		__entry->dst_cpu	= dst_cpu;
		__entry->dst_nid	= dst_cpu >= 0 ? cpu_to_node(dst_cpu) : -1;
	),

	TP_printk("src_pid=%d src_tgid=%d src_ngid=%d src_cpu=%d src_nid=%d dst_pid=%d dst_tgid=%d dst_ngid=%d dst_cpu=%d dst_nid=%d",
			__entry->src_pid, __entry->src_tgid, __entry->src_ngid,
			__entry->src_cpu, __entry->src_nid,
			__entry->dst_pid, __entry->dst_tgid, __entry->dst_ngid,
			__entry->dst_cpu, __entry->dst_nid)
);

DEFINE_EVENT(sched_numa_pair_template, sched_stick_numa,

	TP_PROTO(struct task_struct *src_tsk, int src_cpu,
		 struct task_struct *dst_tsk, int dst_cpu),

	TP_ARGS(src_tsk, src_cpu, dst_tsk, dst_cpu)
);

DEFINE_EVENT(sched_numa_pair_template, sched_swap_numa,

	TP_PROTO(struct task_struct *src_tsk, int src_cpu,
		 struct task_struct *dst_tsk, int dst_cpu),

	TP_ARGS(src_tsk, src_cpu, dst_tsk, dst_cpu)
);


/*
 * Tracepoint for waking a polling cpu without an IPI.
 */
TRACE_EVENT(sched_wake_idle_without_ipi,

	TP_PROTO(int cpu),

	TP_ARGS(cpu),

	TP_STRUCT__entry(
		__field(	int,	cpu	)
	),

	TP_fast_assign(
		__entry->cpu	= cpu;
	),

	TP_printk("cpu=%d", __entry->cpu)
);

#ifdef CONFIG_HW_GRADED_SCHED_WAKEUP_NEW_TASK_FAST
DECLARE_EVENT_CLASS(sched_wakeup_new_task_fast_template,

	TP_PROTO(struct task_struct *p, unsigned int wakeup_fast),

	TP_ARGS(p, wakeup_fast),

	TP_STRUCT__entry(
		__field( int,		pid)
		__field( int,		tgid)
		__field( unsigned int,	wakeup_fast)
		__array( char,	comm,	TASK_COMM_LEN)
	),

	TP_fast_assign(
		__entry->wakeup_fast	= wakeup_fast;
		__entry->pid		= p->pid;
		__entry->tgid		= p->tgid;
		memcpy(__entry->comm, p->comm, TASK_COMM_LEN);
	),

	TP_printk("comm=%s pid=%d tgid=%d wakeup_fast=%u",
		__entry->comm,
		__entry->pid,
		__entry->tgid,
		__entry->wakeup_fast)
);

DEFINE_EVENT(sched_wakeup_new_task_fast_template, sched_wakeup_new_task_fast,
		TP_PROTO(struct task_struct *p, unsigned int wakeup_fast),
		TP_ARGS(p, wakeup_fast));
#endif

/*
 * Following tracepoints are not exported in tracefs and provide hooking
 * mechanisms only for testing and debugging purposes.
 *
 * Postfixed with _tp to make them easily identifiable in the code.
 */
DECLARE_TRACE(pelt_cfs_tp,
	TP_PROTO(struct cfs_rq *cfs_rq),
	TP_ARGS(cfs_rq));

DECLARE_TRACE(pelt_rt_tp,
	TP_PROTO(struct rq *rq),
	TP_ARGS(rq));

DECLARE_TRACE(pelt_dl_tp,
	TP_PROTO(struct rq *rq),
	TP_ARGS(rq));

DECLARE_TRACE(pelt_thermal_tp,
	TP_PROTO(struct rq *rq),
	TP_ARGS(rq));

DECLARE_TRACE(pelt_irq_tp,
	TP_PROTO(struct rq *rq),
	TP_ARGS(rq));

DECLARE_TRACE(pelt_se_tp,
	TP_PROTO(struct sched_entity *se),
	TP_ARGS(se));

DECLARE_TRACE(sched_cpu_capacity_tp,
	TP_PROTO(struct rq *rq),
	TP_ARGS(rq));

DECLARE_TRACE(sched_overutilized_tp,
	TP_PROTO(struct root_domain *rd, bool overutilized),
	TP_ARGS(rd, overutilized));

DECLARE_TRACE(sched_util_est_cfs_tp,
	TP_PROTO(struct cfs_rq *cfs_rq),
	TP_ARGS(cfs_rq));

DECLARE_TRACE(sched_util_est_se_tp,
	TP_PROTO(struct sched_entity *se),
	TP_ARGS(se));

DECLARE_TRACE(sched_update_nr_running_tp,
	TP_PROTO(struct rq *rq, int change),
	TP_ARGS(rq, change));

#ifdef CONFIG_SCHED_LATENCY_NICE
/*
 * Tracepoint for sched_setscheduler
 */
TRACE_EVENT(sched_setscheduler,

	TP_PROTO(struct task_struct *p, int oldpolicy, int oldprio,
		 int oldlatency, unsigned int sched_flags, bool user, bool pi),

	TP_ARGS(p, oldpolicy, oldprio, oldlatency, sched_flags, user, pi),

	TP_STRUCT__entry(
		__array(char,	comm,	TASK_COMM_LEN	)
		__field(pid_t,		pid		)
		__field(int,		oldpolicy	)
		__field(int,		newpolicy	)
		__field(int,		oldprio		)
		__field(int,		newprio		)
		__field(int,		oldlatency	)
		__field(int,		newlatency	)
		__field(unsigned int,	flags		)
		__field(bool,		user		)
		__field(bool,		pi		)
	),

	TP_fast_assign(
		__entry->pid = p->pid;
		memcpy(__entry->comm, p->comm, TASK_COMM_LEN);
		__entry->oldpolicy = oldpolicy;
		__entry->newpolicy = p->policy;
		__entry->oldprio = oldprio;
		__entry->newprio = p->prio;
		__entry->oldlatency = oldlatency;
		__entry->newlatency = p->latency_prio;
		__entry->flags = sched_flags;
		__entry->user = user;
		__entry->pi = pi;
	),

	TP_printk("comm=%s pid=%d prio %d=>%d policy %d=>%d "
		  "latency_prio %d=>%d flags=%u user=%u pi=%u",
		__entry->comm, __entry->pid,
		__entry->oldprio, __entry->newprio,
		__entry->oldpolicy, __entry->newpolicy,
		__entry->oldlatency, __entry->newlatency,
		__entry->flags, __entry->user, __entry->pi)
);
#endif

#endif /* _TRACE_SCHED_H */

/* This part must be outside protection */
#include <trace/define_trace.h>
