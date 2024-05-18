/*
 * slub_track.h
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

#ifndef __SLUB_TRACK_H
#define __SLUB_TRACK_H
#include <linux/sizes.h>
#include <linux/types.h>
#include <chipset_common/mm_track/mm_track.h>

int slub_stack_track_on(const char *name);
int slub_stack_track_off(const char *name);
size_t slub_stack_read(struct mm_stack_info *buf, size_t len, int subtype);
int slub_stack_clean(void);

#endif
