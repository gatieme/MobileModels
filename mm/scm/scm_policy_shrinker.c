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
 *  This file is for shrinker optimize policies.
 *
 */
#include "scm_internal.h"

extern unsigned long shrink_slab(gfp_t gfp_mask, int nid,
				 struct mem_cgroup *memcg, int priority);

enum scm_shrinker_type {
	SCM_TYPE_INVALID = 0,
	SCM_TYPE_UNKNOWN,
	SCM_TYPE_DMABUF,
	SCM_TYPE_GPU,
	SCM_TYPE_F2FS,
	SCM_TYPE_EROFS,
	SCM_TYPE_BINDER,
	SCM_TYPE_VFS,
	SCM_TYPE_ZRAM,
	SCM_TYPE_MAX
};

#define SCM_SHRINKER_TYPE_BITS 4 // bits in scm_shrinker.type;
STATIC_ASSERT(SCM_TYPE_MAX <= (1 << (SCM_SHRINKER_TYPE_BITS)));

#define SHRINKER_FLAG_SCM_SHIFT 8
#define SHRINKER_FLAG_SCM_MASK (0xFF << (SHRINKER_FLAG_SCM_SHIFT))

/*
* shrinker policy
*/

typedef struct _scm_type_info {
	const char *name;
	long nr_min_cache; // when mempressure is cirtical, keep freeable in nr_min_cache.
} scm_type_info;

#ifdef CONFIG_HONOR_SCM_DEBUG
typedef struct _scm_type_info_count {
	atomic64_t org_count_count;
	atomic64_t org_scan_count;
	atomic64_t scm_scan_count;
} scm_type_info_count;

typedef struct _scm_shrinker_count {
	scm_type_info_count info_count[SCM_TYPE_MAX];
	// global counter
	atomic64_t org_count_count;
	atomic64_t org_scan_count;
	atomic64_t scm_scan_count;
} scm_shrinker_count;

#endif // CONFIG_HONOR_SCM_DEBUG

static scm_type_info _shrinker_min_cache_list[] = {
	{ "INVALID", KB2PAGE(0) }, { "UNKNOWN", KB2PAGE(200) },
	{ "DMABUF", MB2PAGE(16) },  { "GPU", MB2PAGE(4) },
	{ "F2FS", KB2PAGE(0) },  { "EROFS", KB2PAGE(0) },
	{ "BINDER", MB2PAGE(2) },  { "VFS", KB2PAGE(256) },
	{ "ZRAM", MB2PAGE(8) },	   { "TOTAL_RESERVED", 0 },
};

#define startswith(buf, prefix) \
	(strncmp(buf, prefix, strlen(prefix)) == 0 ? 1 : 0)
static uint16_t _scm_get_type_by_scan_fn(struct shrinker *shrinker)
{
	uint16_t type;
	char fn_name[64] = { 0 };
	if (shrinker == NULL || shrinker->count_objects == NULL) {
		pr_warn("scm: invalid shrinker.\n");
		return SCM_TYPE_INVALID;
	}
	snprintf(fn_name, sizeof(fn_name), "%pS", shrinker->scan_objects);
	if (strlen(fn_name) == 0) {
		pr_warn("scm: count find symbol name of shrinker->scan_objects.\n");
		return SCM_TYPE_INVALID;
	}

	if (startswith(fn_name, "super_cache_scan")) {
		type = SCM_TYPE_VFS;
	} else if (startswith(fn_name, "kgsl_pool_shrink_scan_objects")) {
		type = SCM_TYPE_GPU;
	} else if (startswith(fn_name, "kbase_mem_pool_reclaim_scan_objects")) {
		type = SCM_TYPE_GPU;
	} else if (startswith(fn_name, "kbase_mem_evictable_reclaim_scan_objects")) {
		type = SCM_TYPE_GPU;
	} else if (startswith(fn_name, "f2fs_shrink_scan")) {
		type = SCM_TYPE_F2FS;
	} else if (startswith(fn_name, "erofs_shrink_scan")) {
		type = SCM_TYPE_EROFS;
	} else if (startswith(fn_name, "binder_shrink_scan")) {
		type = SCM_TYPE_BINDER;
	} else if (startswith(fn_name, "dmabuf_page_pool_shrink_scan")) {
		type = SCM_TYPE_DMABUF;
	} else if (startswith(fn_name, "dynamic_page_pool_shrink_scan")) {
		// [qcom_dma_heaps]
		type = SCM_TYPE_DMABUF;
	} else if (startswith(fn_name, "ion_heap_shrink_scan")) {
		type = SCM_TYPE_DMABUF;
	} else if (startswith(fn_name, "zs_shrinker_scan")) {
		type = SCM_TYPE_ZRAM;
	} else {
		type = SCM_TYPE_UNKNOWN;
	}
	return type;
}
static inline void _scm_shrinker_set_type(struct shrinker *shrinker,
					  enum scm_shrinker_type type)
{
	unsigned int flags = ((unsigned int)type << (SHRINKER_FLAG_SCM_SHIFT));
	shrinker->flags = (shrinker->flags & (~SHRINKER_FLAG_SCM_MASK)) | flags;
}

static scm_type_info *_scm_get_type_info(enum scm_shrinker_type type)
{
	if (type >= SCM_TYPE_MAX) {
		type = SCM_TYPE_INVALID;
	}
	return &_shrinker_min_cache_list[type];
}

static inline enum scm_shrinker_type
_scm_shrinker_get_type(struct shrinker *shrinker)
{
	return (shrinker->flags & SHRINKER_FLAG_SCM_MASK) >>
	       SHRINKER_FLAG_SCM_SHIFT;
}

static inline enum scm_shrinker_type
_scm_shrinker_try_get_type(struct shrinker *shrinker)
{
	enum scm_shrinker_type type_id = _scm_shrinker_get_type(shrinker);
	if (type_id == SCM_TYPE_INVALID && current_is_kswapd()) {
		type_id = _scm_get_type_by_scan_fn(shrinker);
		_scm_shrinker_set_type(shrinker, type_id);
	}
	return type_id;
}

#ifdef CONFIG_HONOR_SCM_DEBUG
#define SHRINKER_ARRAY_COUNT(arr) (sizeof(arr) / sizeof(arr[0]))
#define SHRINKER_BUF (buf + strlen(buf))
#define SHRINKER_LEN ((len > strlen(buf)) ? (len - strlen(buf)) : 0)

static scm_shrinker_count g_scm_shrinker;
static scm_shrinker_count *scm_shrinker = &g_scm_shrinker;

static void scm_shrinker_update_counter(enum scm_shrinker_type type_id,
					long freeable, long new_freeable)
{
	atomic64_inc(&scm_shrinker->org_count_count);
	atomic64_inc(&scm_shrinker->info_count[type_id].org_count_count);
	if (freeable > 0) {
		atomic64_inc(&scm_shrinker->org_scan_count);
		atomic64_inc(&scm_shrinker->info_count[type_id].org_scan_count);
	}
	if (new_freeable > 0) {
		atomic64_inc(&scm_shrinker->scm_scan_count);
		atomic64_inc(&scm_shrinker->info_count[type_id].scm_scan_count);
	}
}

void _scm_shrinker_show(char *buf, int len)
{
	snprintf(
		SHRINKER_BUF, SHRINKER_LEN,
		"all_shrinker_called: [org_count = %lld, org_scan = %lld, scm_scan = %lld\n",
		atomic64_read(&scm_shrinker->org_count_count),
		atomic64_read(&scm_shrinker->org_scan_count),
		atomic64_read(&scm_shrinker->scm_scan_count));
}

void _scm_type_info_show(char *buf, int len)
{
	int type_id;
	for (type_id = SCM_TYPE_INVALID;
	     type_id < SHRINKER_ARRAY_COUNT(scm_shrinker->info_count);
	     type_id++) {
		scm_type_info *info = _scm_get_type_info(type_id);
		scm_type_info_count *count = scm_shrinker->info_count;
		snprintf(
			SHRINKER_BUF, SHRINKER_LEN,
			"shrinker_type(id = %d, name = %s): min_cache = %ld kB, count = %lld, scan = %lld, scan_smart = %lld\n",
			type_id, info->name ? info->name : "invalid",
			PAGE2KB(info->nr_min_cache),
			atomic64_read(&count[type_id].org_count_count),
			atomic64_read(&count[type_id].org_scan_count),
			atomic64_read(&count[type_id].scm_scan_count));
	}
}
#else
#define scm_shrinker_update_counter(type_id, freeable, new_freeable)
#endif // CONFIG_HONOR_SCM_DEBUG

#define STR_EQ(buf, taget) !strncmp(buf, taget, strlen(taget))
// size in kb
void scm_shrinker_set_typed_wm(const char *buf)
{
	int i;
	int64_t value = -1;
	scm_type_info *info;
	for (i = 0; i < SCM_TYPE_MAX; i++) {
		info = _scm_get_type_info(i);
		if (!STR_EQ(buf, info->name)) {
			continue;
		}
		if (strlen(buf) < strlen(info->name) + 2) {
			break;
		}
		// skip "=" in buf.
		if (kstrtos64(buf + strlen(info->name) + 1, 0, &value)) {
			value = -1; // kstrtos64() return != 0, reset value to invalid.
		}
		break;
	}
	if (i >= SCM_TYPE_MAX || value < 0 || value > 8 * 1024 * 1024) {
		pr_err("scm: invalid typed size: [%s] kB\n", buf);
		return;
	}
	info->nr_min_cache = KB2PAGE(value);
}

void scm_shrinker_show(char *buf, int len)
{
#ifdef CONFIG_HONOR_SCM_DEBUG
	_scm_shrinker_show(BUF, LEN);
	_scm_type_info_show(BUF, LEN);
#endif
}

long scm_shrinker_do_shrink_slab(struct shrinker *shrinker, long org_freeable)
{
	long new_freeable;
	long min_cache;
	enum scm_shrinker_type type_id = _scm_shrinker_try_get_type(shrinker);
	scm_type_info *info = _scm_get_type_info(type_id);

	if (!_scm_enabled(POLICY_RESERVE_MIN_CACHE)) {
		scm_shrinker_update_counter(type_id, org_freeable, 0);
		return org_freeable;
	}

	if (type_id == SCM_TYPE_INVALID) {
		scm_shrinker_update_counter(type_id, org_freeable, 0);
		return org_freeable;
	}
	min_cache = info->nr_min_cache;
	if (!current_is_kswapd() || org_freeable <= min_cache) {
		new_freeable = 0;
	} else {
		new_freeable = org_freeable - min_cache;
	}
	scm_shrinker_update_counter(type_id, org_freeable, new_freeable);
	return new_freeable;
}

void __init scm_shrinker_init(void)
{
	return;
}