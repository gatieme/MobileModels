/*
 * Copyright (c) Honor Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: I/O performence measure
 * Author:  lipeng
 * Create:  2021-06-10
 */

#ifndef _IO_MEASURE_H
#define _IO_MEASURE_H

enum iom_pgcache_type {
	IOM_CACHE_ACCESS,
	IOM_CACHE_MISS,
	IOM_CACHE_ADD,
	IOM_CACHE_RA_ADD,
	IOM_CACHE_RA_HIT,
	IOM_CACHE_TYPE_NR
};

void io_measure_pgcache_stat_inc(enum iom_pgcache_type type);
void io_measure_blk_sched_log(void);
void io_measure_scsi_sched_log(void);

#endif
