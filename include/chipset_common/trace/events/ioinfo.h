/* SPDX-License-Identifier: GPL-2.0 */
#undef TRACE_SYSTEM
#define TRACE_SYSTEM ioinfo

#ifdef CONFIG_HONOR_IO_INFO_DEBUG
struct pgcache_stats;
#endif

#if !defined(_TRACE_IOINFO_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_IOINFO_H

#include <linux/tracepoint.h>

#ifdef CONFIG_HONOR_IO_INFO_DEBUG
TRACE_EVENT(io_info_debug,

		TP_PROTO(unsigned long r_kb, unsigned long w_kb,
		struct pgcache_stats *pgcache_stat),

		TP_ARGS(r_kb, w_kb, pgcache_stat),

		TP_STRUCT__entry(
			__field(unsigned long, read_kb)
			__field(unsigned long, write_kb)
			__field(unsigned long, pgfile)
			__field(unsigned long, free)
			__field(unsigned long, slab)
			__field(unsigned long, refault)
		),

		TP_fast_assign(
			__entry->read_kb = r_kb;
			__entry->write_kb = w_kb;
			__entry->pgfile = pgcache_stat->pgfile;
			__entry->free = pgcache_stat->free;
			__entry->slab = pgcache_stat->slab;
			__entry->refault = pgcache_stat->refault;
		),

		TP_printk("rw=%lu/%lu pgfile=%lu free=%lu slab=%lu refault=%lu",
			__entry->read_kb, __entry->write_kb, __entry->pgfile,
			__entry->free, __entry->slab, __entry->refault)
);
#endif

#endif /* _TRACE_IOINFO_H */

/* This part must be outside protection */
#include <trace/define_trace.h>
