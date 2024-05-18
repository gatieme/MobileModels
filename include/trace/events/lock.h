/* SPDX-License-Identifier: GPL-2.0 */
#undef TRACE_SYSTEM
#define TRACE_SYSTEM lock

#if !defined(_TRACE_LOCK_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_LOCK_H

#include <linux/lockdep.h>
#include <linux/tracepoint.h>

#ifdef CONFIG_HN_RW_SEM_DEBUG
#include <linux/rwsem.h>
#endif

#ifdef CONFIG_LOCKDEP

TRACE_EVENT(lock_acquire,

	TP_PROTO(struct lockdep_map *lock, unsigned int subclass,
		int trylock, int read, int check,
		struct lockdep_map *next_lock, unsigned long ip),

	TP_ARGS(lock, subclass, trylock, read, check, next_lock, ip),

	TP_STRUCT__entry(
		__field(unsigned int, flags)
		__string(name, lock->name)
		__field(void *, lockdep_addr)
	),

	TP_fast_assign(
		__entry->flags = (trylock ? 1 : 0) | (read ? 2 : 0);
		__assign_str(name, lock->name);
		__entry->lockdep_addr = lock;
	),

	TP_printk("%p %s%s%s", __entry->lockdep_addr,
		  (__entry->flags & 1) ? "try " : "",
		  (__entry->flags & 2) ? "read " : "",
		  __get_str(name))
);

DECLARE_EVENT_CLASS(lock,

	TP_PROTO(struct lockdep_map *lock, unsigned long ip),

	TP_ARGS(lock, ip),

	TP_STRUCT__entry(
		__string(	name, 	lock->name	)
		__field(	void *, lockdep_addr	)
	),

	TP_fast_assign(
		__assign_str(name, lock->name);
		__entry->lockdep_addr = lock;
	),

	TP_printk("%p %s",  __entry->lockdep_addr, __get_str(name))
);

DEFINE_EVENT(lock, lock_release,

	TP_PROTO(struct lockdep_map *lock, unsigned long ip),

	TP_ARGS(lock, ip)
);

#ifdef CONFIG_LOCK_STAT

DEFINE_EVENT(lock, lock_contended,

	TP_PROTO(struct lockdep_map *lock, unsigned long ip),

	TP_ARGS(lock, ip)
);

DEFINE_EVENT(lock, lock_acquired,

	TP_PROTO(struct lockdep_map *lock, unsigned long ip),

	TP_ARGS(lock, ip)
);

#endif
#endif

#ifdef CONFIG_HN_RW_SEM_DEBUG
TRACE_EVENT(rw_sem_debug,

	TP_PROTO(struct rwsem_waiter *waiter, char *func,
		unsigned long caller_addr0, unsigned long caller_addr1, unsigned long caller_addr2,
		unsigned long caller_addr3, unsigned long caller_addr4, unsigned long caller_addr5),

	TP_ARGS(waiter, func, caller_addr0, caller_addr1, caller_addr2, caller_addr3, caller_addr4, caller_addr5),

	TP_STRUCT__entry(
		__string(function, func)
		__field(unsigned long, addr0)
		__field(unsigned long, addr1)
		__field(unsigned long, addr2)
		__field(unsigned long, addr3)
		__field(unsigned long, addr4)
		__field(unsigned long, addr5)
	),

	TP_fast_assign(
		__assign_str(function, func);
		__entry->addr0 = caller_addr0;
		__entry->addr1 = caller_addr1;
		__entry->addr2 = caller_addr2;
		__entry->addr3 = caller_addr3;
		__entry->addr4 = caller_addr4;
		__entry->addr5 = caller_addr5;
	),

	TP_printk("func: %s, caller (%pS<-%pS<-%pS<-%pS<-%pS<-%pS)",
			__get_str(function),
			__entry->addr0, __entry->addr1,
			__entry->addr2, __entry->addr3,
			__entry->addr4, __entry->addr5)
);
#endif

#endif /* _TRACE_LOCK_H */

/* This part must be outside protection */
#include <trace/define_trace.h>
