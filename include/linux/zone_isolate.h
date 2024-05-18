/*
 * Copyright (c) Honor Device Co., Ltd. 2016-2022. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * Provide external call interfaces of Process reclaim information.
 */

#ifndef __ZONE_ISOLATE_H__
#define __ZONE_ISOLATE_H__

#ifdef CONFIG_HONOR_ZONE_ISOLATE_DEBUG
extern const struct proc_ops zone_isolate_info_fops;
extern void record_zi_index(unsigned int zi_index, unsigned int order, int migratetype);
#endif

extern void add_page_to_list(struct page *page, struct zone *zone, unsigned int order, int mt);
extern int page_to_zi_index(struct page *page);
extern void setup_zone_isolate(struct zone *zone);
extern unsigned int get_zi_index(unsigned int current_zi_index, unsigned int order, int migratetype);

#endif //__ZONE_ISOLATE_H__
