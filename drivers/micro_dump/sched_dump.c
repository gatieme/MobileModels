/*
 * Copyright (c) Honor Device Co., Ltd. 2022-2022. All rights reserved.
 * Description:micro dump function
 * Author: Lu Laicheng
 * Create: 2022-03-22
 */

#include <micro_dump.h>
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 4, 0)
#include <linux/sched.h>
#include <linux/delay.h>
#define TRYLOCK_NUM 10
#define NSEC_PER_MSEC 1000000L
#define PROCESS_RUN_TIME 30000

static long long msec_high(unsigned long long t)
{
	if ((long long)t < 0) {
		t = -t;
		do_div(t, NSEC_PER_MSEC);
		return -t;
	}
	do_div(t, NSEC_PER_MSEC);

	return t;
}

static unsigned long msec_low(unsigned long long t)
{
	if ((long long)t < 0)
		t = -t;

	return do_div(t, NSEC_PER_MSEC);
}

#define SPLIT_NS(x) msec_high(x), msec_low(x)

static char g_group_path[PATH_MAX];
static char *task_group_path(struct task_group *tg)
{
	if (autogroup_path(tg, g_group_path, PATH_MAX))
		return g_group_path;

	cgroup_path(tg->css.cgroup, g_group_path, PATH_MAX);

	return g_group_path;
}

void print_task(const struct rq *rq, struct task_struct *p)
{
	MD_PRINT("%c %15s %5d %9lld %3d %9lld.%06ld %9lld.%06ld %9lld.%06ld"
		" %9lld.%06ld %9lld.%06ld %9lld.%06ld %9lld.%06ld %9lld.%06ld\n",
		task_state_to_char(p),
		p->comm,
		task_pid_nr(p),
		(long long)(p->nvcsw + p->nivcsw),
		p->prio,
		SPLIT_NS(p->sched_info.last_arrival),
		SPLIT_NS(p->sched_info.last_queued),
		SPLIT_NS(p->sched_info.run_delay),
		SPLIT_NS(p->last_enqueued_ts),
		SPLIT_NS(p->last_sleep_ts),
		SPLIT_NS((p->last_sleep_ts - p->last_enqueued_ts)),
		SPLIT_NS(p->se.sum_exec_runtime),
		SPLIT_NS(p->se.statistics.wait_sum));
}

void print_rq(const struct rq *rq)
{
#define P(x) \
	do { \
		if (sizeof(rq->x) == 4) \
			MD_PRINT("  .%-30s: %ld\n", \
			#x, (long)(rq->x)); \
		else \
			MD_PRINT("  .%-30s: %lld\n", \
		#x, (long long)(rq->x)); \
	} while (0)

#define PN(x) \
	MD_PRINT("  .%-30s: %lu\n", #x, SPLIT_NS(rq->x))

	P(nr_running);
	MD_PRINT("  .%-30s: %lu\n", "load", rq->load.weight);
#ifdef DEBUG
	P(nr_switches);
#endif
	P(nr_load_updates);
	P(nr_uninterruptible);
	PN(next_balance);
	MD_PRINT("  .%-30s: %ld\n", "curr->pid", (long)(task_pid_nr(rq->curr)));
	PN(clock);
	MD_PRINT("  .%-30s: %ld %ld %ld %ld %ld\n", "cpu_load",
	(long)(rq->cpu_load[0]),
	(long)(rq->cpu_load[1]),
	(long)(rq->cpu_load[2]),
	(long)(rq->cpu_load[3]),
	(long)(rq->cpu_load[4]));

#undef P
#undef PN

#ifdef CONFIG_SMP
#define P64(n) MD_PRINT("  .%-30s: %lld\n", #n, rq->n)
	P64(avg_idle);
	P64(max_idle_balance_cost);
#undef P64
#endif

#define P(n) MD_PRINT("  .%-30s: %d\n", #n, schedstat_val(rq->n))
	if (schedstat_enabled()) {
		P(yld_count);
		P(sched_count);
		P(sched_goidle);
		P(ttwu_count);
		P(ttwu_local);
	}
#undef P
}

#if 1
#ifdef CONFIG_FAIR_GROUP_SCHED
static void microdump_print_cfs_group_stats(const int cpu, struct task_group *tg)
{
	struct sched_entity *se = tg->se[cpu];

#define P(F)		MD_PRINT("  .%-30s: %lld\n",	#F, (long long)F)
#define P_SCHEDSTAT(F)	MD_PRINT("  .%-30s: %lld\n",	#F, (long long)schedstat_val(F))
#define PN(F)		MD_PRINT("  .%-30s: %lu\n", #F, SPLIT_NS((long long)F))
#define PN_SCHEDSTAT(F)	MD_PRINT("  .%-30s: %lu\n", #F, SPLIT_NS((long long)schedstat_val(F)))

	if (!se)
		return;

	PN(se->exec_start);
	PN(se->vruntime);
	PN(se->sum_exec_runtime);
	if (schedstat_enabled()) {
		PN_SCHEDSTAT(se->statistics.wait_start);
		PN_SCHEDSTAT(se->statistics.sleep_start);
		PN_SCHEDSTAT(se->statistics.block_start);
		PN_SCHEDSTAT(se->statistics.sleep_max);
		PN_SCHEDSTAT(se->statistics.block_max);
		PN_SCHEDSTAT(se->statistics.exec_max);
		PN_SCHEDSTAT(se->statistics.slice_max);
		PN_SCHEDSTAT(se->statistics.wait_max);
		PN_SCHEDSTAT(se->statistics.wait_sum);
		P_SCHEDSTAT(se->statistics.wait_count);
	}
	P(se->load.weight);
	P(se->runnable_weight);
#ifdef CONFIG_SMP
	P(se->avg.load_avg);
	P(se->avg.util_avg);
	P(se->avg.runnable_load_avg);
#endif
#undef PN
#undef P
}
#endif

static void microdump_print_cfs_rq(const int cpu, struct cfs_rq *cfs_rq)
{
	s64 MIN_vruntime = -1, min_vruntime, max_vruntime = -1,
		spread, rq0_min_vruntime, spread0;
	struct sched_entity *last;

#ifdef CONFIG_FAIR_GROUP_SCHED
	MD_PRINT("\n");
	MD_PRINT("cfs_rq[%d]:%s\n", cpu, task_group_path(cfs_rq->tg));
#else
	MD_PRINT("\n");
	MD_PRINT("cfs_rq[%d]:\n", cpu);
#endif
	MD_PRINT("  .%-30s: %lu\n", "exec_clock",
			SPLIT_NS(cfs_rq->exec_clock));

	if (rb_first_cached(&cfs_rq->tasks_timeline))
		MIN_vruntime = (__pick_first_entity(cfs_rq))->vruntime;
	last = __pick_last_entity(cfs_rq);
	if (last)
		max_vruntime = last->vruntime;
	min_vruntime = cfs_rq->min_vruntime;
	rq0_min_vruntime = cpu_rq(0)->cfs.min_vruntime;

	MD_PRINT("  .%-30s: %lu\n", "MIN_vruntime",
			SPLIT_NS(MIN_vruntime));
	MD_PRINT("  .%-30s: %lu\n", "min_vruntime",
			SPLIT_NS(min_vruntime));
	MD_PRINT("  .%-30s: %lu\n", "max_vruntime",
			SPLIT_NS(max_vruntime));

	spread = max_vruntime - MIN_vruntime;
#ifdef DEBUG
	MD_PRINT("  .%-30s: %lu\n", "spread",
			SPLIT_NS(spread));
#endif
	spread0 = min_vruntime - rq0_min_vruntime;
#ifdef DEBUG
	MD_PRINT("  .%-30s: %lu\n", "spread0",
		SPLIT_NS(spread0));
	MD_PRINT("  .%-30s: %d\n", "nr_spread_over",
		cfs_rq->nr_spread_over);
#endif

	MD_PRINT("  .%-30s: %d\n",
			"nr_running", cfs_rq->nr_running);
	MD_PRINT("  .%-30s: %ld\n", "load", cfs_rq->load.weight);
#ifdef CONFIG_SMP
	MD_PRINT("  .%-30s: %ld\n", "runnable_weight", cfs_rq->runnable_weight);

	MD_PRINT("  .%-30s: %lu\n", "load_avg",
			cfs_rq->avg.load_avg);
	MD_PRINT("  .%-30s: %lu\n", "runnable_load_avg",
			cfs_rq->avg.runnable_load_avg);
	MD_PRINT("  .%-30s: %lu\n", "util_avg",
			cfs_rq->avg.util_avg);
	MD_PRINT("  .%-30s: %u\n", "util_est_enqueued",
			cfs_rq->avg.util_est.enqueued);
	MD_PRINT("  .%-30s: %ld\n", "removed.load_avg",
			cfs_rq->removed.load_avg);
	MD_PRINT("  .%-30s: %ld\n", "removed.util_avg",
			cfs_rq->removed.util_avg);
	MD_PRINT("  .%-30s: %ld\n", "removed.runnable_sum",
			cfs_rq->removed.runnable_sum);

#ifdef CONFIG_FAIR_GROUP_SCHED
	MD_PRINT("  .%-30s: %lu\n", "tg_load_avg_contrib",
			cfs_rq->tg_load_avg_contrib);
	MD_PRINT("  .%-30s: %ld\n", "tg_load_avg",
			atomic_long_read(&cfs_rq->tg->load_avg));
#endif
#endif
#ifdef CONFIG_CFS_BANDWIDTH
	MD_PRINT("  .%-30s: %d\n", "throttled",
			cfs_rq->throttled);
	MD_PRINT("  .%-30s: %d\n", "throttle_count",
			cfs_rq->throttle_count);
#endif

#ifdef CONFIG_FAIR_GROUP_SCHED
	microdump_print_cfs_group_stats(cpu, cfs_rq->tg);
#endif
}

#define for_each_leaf_cfs_rq(rq, cfs_rq) \
	list_for_each_entry_rcu(cfs_rq, &rq->leaf_cfs_rq_list, leaf_cfs_rq_list)

static void microdump_print_cfs_stats(int cpu)
{
	struct cfs_rq *cfs_rq;

	rcu_read_lock();
	cfs_rq = &cpu_rq(cpu)->cfs;
	/* sched: only output / cgroup schedule info */
	microdump_print_cfs_rq(cpu, cfs_rq);
	rcu_read_unlock();
}

static void microdump_print_rt_rq(int cpu, struct rt_rq *rt_rq)
{
#ifdef CONFIG_RT_GROUP_SCHED
	MD_PRINT("\n");
	MD_PRINT("rt_rq[%d]:%s\n", cpu, task_group_path(rt_rq->tg));

#else
	MD_PRINT("\n");
	MD_PRINT("rt_rq[%d]:\n", cpu);
#endif

#define P(x) \
	MD_PRINT("  .%-30s: %lld\n", #x, (long long)(rt_rq->x))
#define PU(x) \
	MD_PRINT("  .%-30s: %lu\n", #x, (unsigned long)(rt_rq->x))
#define PN(x) \
	MD_PRINT("  .%-30s: %lu\n", #x, SPLIT_NS(rt_rq->x))

	P(rt_nr_running);
#ifdef CONFIG_SMP
	PU(rt_nr_migratory);
#endif

	P(rt_throttled);
	PN(rt_time);
	PN(rt_runtime);

#undef PN
#undef PU
#undef P
}

static void microdump_print_rt_stats(int cpu)
{
	struct rt_rq *rt_rq;
	rt_rq = &cpu_rq(cpu)->rt;
	/* sched: only output / cgroup schedule info */
	microdump_print_rt_rq(cpu, rt_rq);
}
#endif

static void microdump_print_dl_rq(int cpu, struct dl_rq *dl_rq)
{
	struct dl_bw *dl_bw;

	MD_PRINT("\n");
	MD_PRINT("dl_rq[%d]:\n", cpu);
	MD_PRINT("  .%-30s: %ld\n", "dl_nr_running", dl_rq->dl_nr_running);

#define PU(x) \
	MD_PRINT("  .%-30s: %lu\n", #x, (unsigned long)(dl_rq->x))

	PU(dl_nr_running);
#ifdef CONFIG_SMP
	PU(dl_nr_migratory);
	dl_bw = &cpu_rq(cpu)->rd->dl_bw;
#else
	dl_bw = &dl_rq->dl_bw;
#endif
	MD_PRINT("  .%-30s: %lld\n", "dl_bw->bw", dl_bw->bw);
	MD_PRINT("  .%-30s: %lld\n", "dl_bw->total_bw", dl_bw->total_bw);
#undef PU
}

void microdump_sched_dump(void)
{
	int cpu;
	struct task_struct *g, *p;
	struct rq *rq;
	unsigned long timeout;

	for_each_possible_cpu(cpu) {
		MD_PRINT("cpu#%d: %s\n", cpu, cpu_is_offline(cpu) ? "Offline" : "Online");
		rq = cpu_rq(cpu);
		print_rq(rq);
		microdump_print_dl_rq(cpu, &cpu_rq(cpu)->dl);
		microdump_print_cfs_stats(cpu);
		microdump_print_rt_stats(cpu);
		MD_PRINT("state        name   pid  switches prio     exec_start       last_quened"
			"  total_wait_time    last_enqueued       last_sleep"
			"     last_runtime        sum_exec         wait-time");
		for_each_process_thread(g, p) {
			if (task_cpu(p) != cpu)
				continue;
			timeout = msecs_to_jiffies(msec_high(p->sched_info.last_arrival));
			timeout += msecs_to_jiffies(PROCESS_RUN_TIME) + INITIAL_JIFFIES;
			if (time_before(jiffies, timeout))
				print_task(rq, p);
		}
	}
}
#endif
