/*
 * Copyright (C) 2020-2023 HONOR, Inc.
 * Smart Cache Manager helper
 * Author:
 * 		lizhiwei<lizhiwei3@hihonor.com>,
 * 		wangxin<wangxin23@honor.com>,
 * 		qiyichuan<qiyichuan@hihonor.com>,
 * 		yangxuzhe<yangxuzhe@hihonor.com>,
 * 		zhangzhongshi<zhangzhongshi@hihonor.com>
 *
 *  This file is for API, structure defination.
 *
 */
#include "scm_internal.h"

struct _scm_task_counts {
	int vip_task;
	int qos_task;
	int normal_task;
	int imst_hit;
	int imst_miss;
};

static struct _scm_task_counts g_scm_task_counts;
static struct _scm_task_counts *scm_task_counts = &g_scm_task_counts;

// ================== oomadj ==================
#define MIN_APPLICATION_UID 10000 /* min uid to conrtrol */
#define OOM_ADJ_FOREGROUND 0
#define OOM_ADJ_SYSTEM_SERVER -900
#define OOM_ADJ_PERCEPTIBLE 200
#define OOM_ADJ_KTHREAD -2000
#define OOM_ADJ_CUSTOM_IMPORTANT -990

// ================== task vip/rt ==================

#ifdef CONFIG_HN_VIP_THREAD_BUILDIN
#include <trace/hooks/binder.h>
enum DYNAMIC_VIP_TYPE {
	DYNAMIC_VIP_BINDER = 0,
	DYNAMIC_VIP_RWSEM,
	DYNAMIC_VIP_MUTEX,
	DYNAMIC_VIP_SEM,
	DYNAMIC_VIP_FUTEX,
	DYNAMIC_VIP_QOS,
	DYNAMIC_VIP_MAX,
};

static inline bool __test_task_vip(struct task_struct *task)
{
	bool is_vip = false;
	trace_android_rvh_honor_test_task_vip(current, &is_vip);
	return is_vip;
}

static inline bool _scm_test_task_vip(struct task_struct *task)
{
	// static and dynamic vip.
	return task->prio < _SCM_SYS_RT_PRIO || __test_task_vip(task);
}
#else
static inline bool _scm_test_task_vip(struct task_struct *task)
{
	return task->prio <= _SCM_SYS_RT_PRIO;
}
#endif

// ================== task priority ==================
#define PRIO_RT_VIP_OR_RTG (-80)
#define PRIO_QOS_THREAD (DEFAULT_PRIO - 19) // for CONFIG_HN_QOS_THREAD
#define PRIO_BACKGROUND_APP (DEFAULT_PRIO + 3)
#define PRIO_TO_SCM_PRIO(x) ((x)-DEFAULT_PRIO)

#define SCM_TASK_PRIO_VIP PRIO_TO_SCM_PRIO(101)
#define SCM_TASK_PRIO_DEFAULT PRIO_TO_SCM_PRIO(DEFAULT_PRIO)
#define SCM_TASK_PRIO_GC PRIO_TO_SCM_PRIO(124)

int __scm_task_prio(struct task_struct *task)
{
	if (_scm_test_task_vip(task)) {
		scm_task_counts->vip_task++;
		return PRIO_RT_VIP_OR_RTG;
	}
	scm_task_counts->normal_task++;
	return PRIO_TO_SCM_PRIO(task->prio);
};

// ================== task cgroup ==================
enum SCM_CGP_TYPE {
	SCM_CGP_TYPE_UNKNOWN = 0,

	SCM_CGP_TYPE_VIP,
	SCM_CGP_TYPE_BOOST,
	SCM_CGP_TYPE_GAME,
	SCM_CGP_TYPE_TOP_APP,
	SCM_CGP_TYPE_GRAPHICS,
	SCM_CGP_TYPE_KEY_FG,

	SCM_CGP_TYPE_FOREGROUND,
	SCM_CGP_TYPE_ROOT_OR_OTHER, // in root or other cgroup.
	SCM_CGP_TYPE_CAMERA_DAEMON,
	SCM_CGP_TYPE_SYSTEM_BACKGROUND,

	SCM_CGP_TYPE_KEY_BACKGROUND,
	SCM_CGP_TYPE_RESTRICTED, // when screen off.
	SCM_CGP_TYPE_BACKGROUND,

	_SCM_CGP_TYPE_VIP_START = SCM_CGP_TYPE_VIP,
	_SCM_CGP_TYPE_VIP_END = SCM_CGP_TYPE_KEY_FG,

	_SCM_CGP_TYPE_FOREGROUND_START = SCM_CGP_TYPE_FOREGROUND,
	_SCM_CGP_TYPE_FOREGROUND_END = SCM_CGP_TYPE_SYSTEM_BACKGROUND,

	_SCM_CGP_TYPE_BACKGROUND_START = SCM_CGP_TYPE_KEY_BACKGROUND,
	_SCM_CGP_TYPE_BACKGROUND_END = SCM_CGP_TYPE_BACKGROUND,

	SCM_CGP_TYPE_MAX = _SCM_CGP_TYPE_BACKGROUND_END + 1,
};
static const char *g_cpuset_type_names[] = {
	"unknown",

	"/vip",
	"/boost",
	"/game",
	"/top-app",
	"/graphics",
	"/key-fg",

	"/foreground",
	"/",
	"/camera-daemon",
	"/system-background",

	"/key-background",
	"/restricted",
	"/background",
};

static inline uint64_t _scm_task_cpuset_id(struct task_struct *task)
{
	// 0 for root or other.
	if (unlikely(!task->cgroups)) {
		return 0;
	}
	return cgroup_id(task_css(task, cpuset_cgrp_id)->cgroup);
}

#define SCM_CGP_CPUSET_ID_MAX 1024
static uint8_t g_cpuset_id_types[SCM_CGP_CPUSET_ID_MAX];

#define SCM_MEM_CGROUP_NAME_MAX_LEN 100
static uint8_t _scm_cgroup_update_cpuset_type(struct cgroup_subsys_state *css)
{
	uint8_t type;
	uint64_t _cgroup_id;
	char name[SCM_MEM_CGROUP_NAME_MAX_LEN];
	if (css == NULL || cgroup_path(css->cgroup, name, sizeof(name)) < 0) {
		return SCM_CGP_TYPE_ROOT_OR_OTHER;
	}
	_cgroup_id = cgroup_id(css->cgroup);
	if (_cgroup_id >= SCM_CGP_CPUSET_ID_MAX) {
		pr_err("[ERROR]: scm: cpuset_update: id=%lld, name=%s. index overflow.\n",
		       _cgroup_id, name);
		return SCM_CGP_TYPE_ROOT_OR_OTHER;
	}
	for (type = SCM_CGP_TYPE_VIP; type < SCM_CGP_TYPE_MAX; type++) {
		if (!strncmp(g_cpuset_type_names[type], name, sizeof(name))) {
			g_cpuset_id_types[_cgroup_id] = type;
#ifdef CONFIG_HONOR_SCM_DEBUG
			pr_info("scm: cpuset_update: id=%lld, name=%s, type=%d\n",
				_cgroup_id, name, type);
#endif
			return type;
		}
	}
	g_cpuset_id_types[_cgroup_id] = SCM_CGP_TYPE_ROOT_OR_OTHER;
	return SCM_CGP_TYPE_ROOT_OR_OTHER;
}

static inline uint8_t _scm_cpuset_type(struct task_struct *task)
{
	uint8_t type_id;
	uint64_t cpuset_id = _scm_task_cpuset_id(task);
	if (unlikely(cpuset_id >= SCM_CGP_CPUSET_ID_MAX)) {
		pr_err("scm: cpuset_type: id=%lld is unknown\n", cpuset_id);
		return SCM_CGP_TYPE_ROOT_OR_OTHER;
	}
	type_id = g_cpuset_id_types[cpuset_id];
	if (unlikely(type_id == SCM_CGP_TYPE_UNKNOWN)) {
		return _scm_cgroup_update_cpuset_type(
			task_css(task, cpuset_cgrp_id));
	}
	return type_id;
}

static inline bool _scm_cpuset_is_vip(uint8_t type)
{
	// uint8_t type = _scm_cpuset_type(task);
	return (type >= _SCM_CGP_TYPE_VIP_START &&
		type <= _SCM_CGP_TYPE_VIP_END);
}

static inline bool _scm_cpuset_is_fg(uint8_t type)
{
	return (type >= _SCM_CGP_TYPE_FOREGROUND_START &&
		type <= _SCM_CGP_TYPE_FOREGROUND_END);
}

static inline bool _scm_cpuset_is_bg(uint8_t type)
{
	return (type >= _SCM_CGP_TYPE_BACKGROUND_START &&
		type <= _SCM_CGP_TYPE_BACKGROUND_END);
}

static inline short _scm_task_get_oom_adj(struct task_struct *task)
{
	if (unlikely(_scm_is_kernel_thread(task))) {
		// kernel thread's oom adj is 0
		return OOM_ADJ_KTHREAD;
	}
	return task->signal->oom_score_adj;
}

#define SCM_IMST_CACHE_TIME_SHIFT 10
#define SCM_IMST_CACHE_STATUS_MASK ((1ull << (SCM_IMST_CACHE_TIME_SHIFT)) - 1)
#define SCM_IMST_CACHE_TIME_MASK (~(uint64_t)(SCM_IMST_CACHE_STATUS_MASK))
#define SCM_IMST_CACHE_TIME(imst) \
	((uint64_t)(imst) >> SCM_IMST_CACHE_TIME_SHIFT)
#define SCM_IMST_CACHE_TIME_BITS(imst) \
	((uint64_t)(imst)&SCM_IMST_CACHE_TIME_MASK)
#define SCM_IMST_CACHE_STATUS(imst) ((imst)&SCM_IMST_CACHE_STATUS_MASK)

static inline bool __scm_task_at_cached_time(uint64_t imst)
{
	return (get_jiffies_64() << SCM_IMST_CACHE_TIME_SHIFT) ==
	       SCM_IMST_CACHE_TIME_BITS(imst);
}

static inline uint64_t __scm_task_make_cache(uint64_t imst)
{
	return SCM_IMST_CACHE_STATUS(imst) |
	       (get_jiffies_64() << SCM_IMST_CACHE_TIME_SHIFT);
}

#ifdef _CONFIG_SCM_TASK_STATUS_HAS_CACHE
#define MAX_CACHED_PIDS 32768

static uint64_t *g_imst_cache = NULL;
static bool __init _scm_task_status_alloc_cache(void)
{
	g_imst_cache = vmalloc(sizeof(uint64_t) * MAX_CACHED_PIDS);
	if (g_imst_cache == NULL) {
		pr_warn("scm: task_cache: can't get mem.\n");
		return false;
	}
	memset(g_imst_cache, 0, sizeof(uint64_t) * MAX_CACHED_PIDS);
	return true;
}

static inline uint32_t _scm_task_status_cached(struct task_struct *task)
{
	uint64_t imst_cached;
	if (unlikely(task->pid >= MAX_CACHED_PIDS || g_imst_cache == NULL)) {
		scm_task_counts->imst_miss++;
		return SCM_IMST_INVALID;
	}
	imst_cached = g_imst_cache[task->pid];
	if (likely(__scm_task_at_cached_time(imst_cached))) {
		scm_task_counts->imst_hit++;
		return SCM_IMST_CACHE_STATUS(imst_cached);
	}
	scm_task_counts->imst_miss++;
	return SCM_IMST_INVALID;
}

static inline void _scm_task_status_update_cache(pid_t pid, uint64_t imst)
{
	if (unlikely(pid >= MAX_CACHED_PIDS || g_imst_cache == NULL)) {
		return;
	}
	g_imst_cache[pid] = __scm_task_make_cache(imst);
}
#else
#define _scm_task_status_alloc_cache()
#define _scm_task_status_cached(task) SCM_IMST_INVALID
#define _scm_task_status_update_cache(pid, imst)
#endif

#define MIN_APPLICATION_UID 10000

static inline int __scm_task_get_uid(struct task_struct *task)
{
	return task->cred ? task->cred->euid.val : -1;
}

static inline bool __scm_task_is_app(struct task_struct *task)
{
	return __scm_task_get_uid(task) >= MIN_APPLICATION_UID;
}


static inline uint32_t __scm_task_get_important_status(struct task_struct *task)
{
	uint32_t ret = 0;
	uint8_t cpuset_type = _scm_cpuset_type(task);
	short oom_adj = _scm_task_get_oom_adj(task);
	int scm_prio = __scm_task_prio(task);
	if (_scm_cpuset_is_vip(cpuset_type) ||
	    (oom_adj == OOM_ADJ_SYSTEM_SERVER)) {
		ret |= SCM_IMST_PROC_FOREGROUND;
	} else if (_scm_cpuset_is_fg(cpuset_type)) {
		if (__scm_task_is_app(task)) {
			ret |= SCM_IMST_PROC_BACKGROUND;
		} else {
			ret |= SCM_IMST_PROC_FOREGROUND_RELATED;
		}
	} else if (_scm_cpuset_is_bg(cpuset_type)) {
		ret |= SCM_IMST_PROC_BACKGROUND;
	} else {
		ret |= SCM_IMST_PROC_UNKNOWN;
	}

	if (scm_prio <= SCM_TASK_PRIO_VIP) {
		ret |= SCM_IMST_PRIO_VIP;
	} else if (scm_prio < SCM_TASK_PRIO_DEFAULT) {
		ret |= SCM_IMST_PRIO_HIGH;
	} else if (scm_prio > SCM_TASK_PRIO_DEFAULT) {
		ret |= (scm_prio == SCM_TASK_PRIO_GC) ? SCM_IMST_PRIO_GC :
							SCM_IMST_PRIO_LOW;
	}
	if (task->active_mm && mmap_lock_is_contended(task->active_mm)) {
		ret |= SCM_IMST_MM_MMAPLOCKED;
	}
	return ret;
}

#ifdef CONFIG_HONOR_SCM_DEBUG

#define SCM_IMST_COUNTER_MASK 0x01FF
static atomic64_t g_im_status_alloc[SCM_IMST_COUNTER_MASK + 1];
static inline void _scm_task_count_alloc_im_status(uint32_t im_status)
{
	atomic64_inc(&g_im_status_alloc[im_status & SCM_IMST_COUNTER_MASK]);
}
#else
#define _scm_task_count_alloc_im_status(st)
#endif // #ifdef CONFIG_HONOR_SCM_DEBUG

uint32_t scm_task_status_get(struct task_struct *task)
{
	uint32_t imst = _scm_task_status_cached(task);
	if (imst != SCM_IMST_INVALID) {
		return imst;
	}
	imst = __scm_task_get_important_status(task);
	_scm_task_status_update_cache(task->pid, imst);
	return imst;
}

uint32_t scm_task_status_get2(struct task_struct *task, gfp_t gfp_mask)
{
	uint32_t im_status;
	if (unlikely(task == NULL) ||
	    unlikely((gfp_mask & GFP_KERNEL) != GFP_KERNEL)) {
		_scm_task_count_alloc_im_status(SCM_IMST_INVALID);
		return SCM_IMST_INVALID;
	}
	im_status = scm_task_status_get(task);
	_scm_task_count_alloc_im_status(im_status);
	return im_status;
}

#ifdef CONFIG_HONOR_SCM_DEBUG
#define SCM_IMST_COUNT_COLUMN 9
static void _scm_task_show_alloc_line(char *buf, int len, int locked, int cate)
{
	int i, idx;
	uint64_t c[SCM_IMST_COUNT_COLUMN];
	for (i = 0; i < SCM_IMST_COUNT_COLUMN; i++) {
		idx = locked + cate + i;
		if (idx < 0 || idx >= SCM_IMST_COUNTER_MASK) {
			continue;
		}
		c[i] = atomic64_read(&g_im_status_alloc[idx]);
	}

	snprintf(BUF, LEN, "imst_%d_%x = ", locked, cate >> 4);
	for (i = 0; i < SCM_IMST_COUNT_COLUMN; i++) {
		snprintf(BUF, LEN, "%lld,", c[i]);
	}
	snprintf(BUF, LEN, "\n");
}
static void _scm_task_show_alloc_im_status(char *buf, int len)
{
	int i, locked;
	int cates[] = { SCM_IMST_INVALID, SCM_IMST_PROC_FOREGROUND,
			SCM_IMST_PROC_FOREGROUND_RELATED,
			SCM_IMST_PROC_BACKGROUND };

	// SCM_IMST_MM_MMAPLOCKED
	for (locked = 0; locked <= SCM_IMST_MM_MMAPLOCKED;
	     locked += SCM_IMST_MM_MMAPLOCKED) {
		for (i = 0; i < SCM_ARRAY_COUNT(cates); i++) {
			_scm_task_show_alloc_line(BUF, LEN, locked, cates[i]);
		}
	}
}

static const char *_scm_task_cpuset_name(uint8_t cpuset_type)
{
	if (unlikely(cpuset_type >= SCM_CGP_TYPE_MAX)) {
		return g_cpuset_type_names[SCM_CGP_TYPE_UNKNOWN];
	}
	return g_cpuset_type_names[cpuset_type];
}

static void _scm_cpuset_ids_show(char *buf, int len)
{
	uint8_t type;
	int id;
	for (id = 0; id < SCM_CGP_CPUSET_ID_MAX; id++) {
		type = g_cpuset_id_types[id];
		if (type == SCM_CGP_TYPE_UNKNOWN) {
			continue;
		}
		snprintf(BUF, LEN, "cpuset: %s = %d, type = %d\n",
			 _scm_task_cpuset_name(type), id, (int)type);
	}
}

#else
#define _scm_task_show_alloc_im_status(buf, len)
#define _scm_cpuset_ids_show(buf, len)
#endif // #ifdef CONFIG_HONOR_SCM_DEBUG

void scm_task_status_show(char *buf, int len)
{
	snprintf(BUF, LEN,
		 "task: vip= %d, qos = %d, normal = %d, hit = %d, miss = %d\n",
		 scm_task_counts->vip_task, scm_task_counts->qos_task,
		 scm_task_counts->normal_task, scm_task_counts->imst_hit,
		 scm_task_counts->imst_miss);
	_scm_cpuset_ids_show(BUF, LEN);
	_scm_task_show_alloc_im_status(BUF, LEN);
}

void __init scm_task_status_init(void)
{
	_scm_task_status_alloc_cache();
}