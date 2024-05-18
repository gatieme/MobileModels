/*
 * Copyright (C) 2020-2023 HONOR, Inc.
 * Smart Cache Manager internal define
 * Author:
 * 		lizhiwei<lizhiwei3@hihonor.com>,
 * 		wangxin<wangxin23@honor.com>,
 * 		qiyichuan<qiyichuan@hihonor.com>,
 * 		yangxuzhe<yangxuzhe@hihonor.com>,
 * 		zhangzhongshi<zhangzhongshi@hihonor.com>
 */

#ifndef _SCM_INTERNAL_DEF_H_
#define _SCM_INTERNAL_DEF_H_

#define POLICY_RECLAIM_TYPE 0x01 // for file lru, anon lru and shrinke_slab
#define POLICY_RESERVE_MIN_CACHE 0x02 // for shrinker's min cache.
#define POLICY_RESERVE_AVAILABLE 0x04 // reserve for available memory.
#define POLICY_QOS_POOL_STEP0 0x08 // for qos pool step0
#define POLICY_FAULT_AROUND 0x10 // for dynamic fault around size.
#define POLICY_SHRINK_SLABD 0x20 // for shrink_slabd.

#define POLICY_QOS_PCP 0x80 // qos pcp bypass.
#define POLICY_QOS_POOL_STEP1 0x100 // for qos pool step1
#define POLICY_SCM_ALLOC_HARDER 0x200 // for qos alloc harder.

#define POLICY_DMABUF_QOS_ALLOC 0x800 // for dmabuf qos alloc

#define POLICY_HAS_SCHED_QOS_THREAD 0x1000 // for rw_sem opt.
#define POLICY_QOS_BACKGROUND_SLOWPATH 0x2000 // for background slowpath.

#define POLICY_ALL 0xFFFFFFFFFFFF
#define POLICY_DEFAULT 0x0303

#endif /*_SCM_INTERNAL_DEF_H_*/
