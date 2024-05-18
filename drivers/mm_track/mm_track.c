/*
 * mm_track.c
 *
 * Copyright(C) 2022 Honor Device Co., Ltd. All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <linux/err.h>
#include <linux/mmzone.h>
#include <linux/printk.h>
#include <linux/kernel.h>
#include <linux/mm.h>
#include <linux/swap.h>
#include <linux/slab.h>
#include <linux/sizes.h>
#include "slub_track.h"
#ifdef CONFIG_CMA
#include <linux/cma.h>
#endif

#define pages_to_byte(pages) ((pages) << PAGE_SHIFT)

struct mm_stack_track_ops {
	int (*mm_stack_track_on)(const char *);
	int (*mm_stack_track_off)(const char *);
	size_t (*mm_stack_read)(struct mm_stack_info *, size_t, int);
	int (*mm_stack_clean)(void);
};

struct mm_track_entry {
	int type;
	struct mm_stack_track_ops *stack_track;
};

struct mm_stack_track_ops slub_mm_stack = {
	.mm_stack_track_on = slub_stack_track_on,
	.mm_stack_track_off = slub_stack_track_off,
	.mm_stack_read = slub_stack_read,
	.mm_stack_clean = slub_stack_clean,
};

struct mm_track_entry mm_track_table[] = {
	{ SLUB_TRACK,   &slub_mm_stack },
};

static const char * const track_text[] = {
	"SLUB_TRACK",
};

int mm_track_on(int type, const char *name)
{
	unsigned int i;

	if (!name)
		return -EINVAL;
	for (i = 0; i < ARRAY_SIZE(mm_track_table); i++) {
		if (type == mm_track_table[i].type && mm_track_table[i].stack_track) {
			return mm_track_table[i].stack_track->mm_stack_track_on(name);
		}
	}
	return -EINVAL;
}

int mm_track_off(int type, const char *name)
{
	unsigned int i;

	if (!name)
		return -EINVAL;
	for (i = 0; i < ARRAY_SIZE(mm_track_table); i++) {
		if (type == mm_track_table[i].type && mm_track_table[i].stack_track) {
			return mm_track_table[i].stack_track->mm_stack_track_off(name);
		}
	}

	return -EINVAL;
}

size_t mm_track_read(int type, struct mm_stack_info *info, size_t len, int subtype)
{
	unsigned int i;

	if (!info)
		return 0;
	for (i = 0; i < ARRAY_SIZE(mm_track_table); i++) {
		if (type == mm_track_table[i].type && mm_track_table[i].stack_track) {
			return mm_track_table[i].stack_track->mm_stack_read(info, len, subtype);
		}
	}

	return 0;
}

int mm_track_clean(int type)
{
	unsigned int i;

	for (i = 0; i < ARRAY_SIZE(mm_track_table); i++) {
	if (type == mm_track_table[i].type && mm_track_table[i].stack_track) {
			return mm_track_table[i].stack_track->mm_stack_clean();
		}
	}

	return 0;
}
