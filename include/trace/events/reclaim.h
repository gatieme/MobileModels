/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: add trace points for memory reclaim thread kswapd
 * Author: Mi Sasa <misasa@huawei.com>
 * Create: 2022-06-20
 */
#undef TRACE_SYSTEM
#define TRACE_SYSTEM vmscan

#if !defined(_TRACE_RECLAIM_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_RECLAIM_H

#include <linux/tracepoint.h>

DECLARE_EVENT_CLASS(mm_reclaim_general_template,

	TP_PROTO(unsigned long freed),

	TP_ARGS(freed),

	TP_STRUCT__entry(
		__field(unsigned long, freed)
	),

	TP_fast_assign(
		__entry->freed = freed;
	),

	TP_printk("freed=%lu", __entry->freed)
);

DEFINE_EVENT(mm_reclaim_general_template, kswapd_start,

	TP_PROTO(unsigned long freed),

	TP_ARGS(freed)
);

DEFINE_EVENT(mm_reclaim_general_template, kswapd_end,

	TP_PROTO(unsigned long freed),

	TP_ARGS(freed)
);

DEFINE_EVENT(mm_reclaim_general_template, shrinklists_start,

	TP_PROTO(unsigned long freed),

	TP_ARGS(freed)
);

DEFINE_EVENT(mm_reclaim_general_template, shrinklists_end,

	TP_PROTO(unsigned long freed),

	TP_ARGS(freed)
);

DEFINE_EVENT(mm_reclaim_general_template, shrinkslabs_start,

	TP_PROTO(unsigned long freed),

	TP_ARGS(freed)
);

DEFINE_EVENT(mm_reclaim_general_template, shrinkslabs_pages,

	TP_PROTO(unsigned long freed),

	TP_ARGS(freed)
);

DEFINE_EVENT(mm_reclaim_general_template, shrinkslabs_end,

	TP_PROTO(unsigned long freed),

	TP_ARGS(freed)
);

#ifdef CONFIG_PROTECT_LRU_ENHANCED
TRACE_EVENT(mm_filemap_refault_distance,
		TP_PROTO(unsigned long distance),

		TP_ARGS(distance),

		TP_STRUCT__entry(
			__field(unsigned long, distance)
		),

		TP_fast_assign(
			__entry->distance = distance;
		),

		TP_printk("distance=%lu", __entry->distance)
);
#endif

#endif /* _TRACE_RECLAIM_H */
