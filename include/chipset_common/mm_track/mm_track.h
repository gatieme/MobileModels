/*
 * mm_track.h
 *
 * Copyright(C) 2022 Honor Device Co., Ltd. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef _MM_TRACK_H
#define _MM_TRACK_H

#include <linux/types.h>
#include <linux/mm.h>
#include <linux/page-flags.h>

#define MM_TRACK_STACK_DEPTH 8

enum {
	START_TRACK,
	ION_TRACK = START_TRACK,
	SLUB_TRACK,
	LSLUB_TRACK,
	VMALLOC_TRACK,
	CMA_TRACK,
	ZSPAGE_TRACK,
	BUDDY_TRACK,
	SKB_TRACK,
	NR_TRACK,
};

enum {
	SLUB_ALLOC,
	SLUB_FREE,
	NR_SLUB_ID,
};

struct stack_track {
	unsigned long caller;
#ifdef CONFIG_STACKTRACE
	unsigned long addrs[MM_TRACK_STACK_DEPTH];
	unsigned int stack_len;
#endif
	unsigned int stack_hash;
};

struct mm_stack_info {
	struct stack_track stack_entry;
	atomic_t ref;
};

#ifdef CONFIG_HN_MM_TRACK
int mm_track_on(int type, const char *name);
int mm_track_off(int type, const char *name);
size_t mm_track_read(int type,
struct mm_stack_info *info, size_t len, int subtype);
int mm_track_clean(int type);
#else
static inline int mm_track_on(int type, const char *name)
{
	return 0;
}

static inline int mm_track_off(int type, const char *name)
{
	return 0;
}

static inline size_t mm_track_read(int type,
	struct mm_stack_info *info, size_t len, int subtype)
{
	return 0;
}

static inline int mm_track_clean(int type)
{
	return 0;
}
#endif
#endif