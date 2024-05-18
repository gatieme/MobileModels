/*
 * Copyright (c) Honor Device Co., Ltd. 2023-2023. All rights reserved.
 * Description:micro dump function GKI Support
 * Author: Li Chenqing
 * Create: 2023-02-28
 */

#include <micro_dump.h>
#include <asm/module.h>
#include "../../drivers/soc/qcom/debug_symbol.h"

#define md_symbol_init(item, type, origin) \
	item = (type)debug_symbol_get_addr(#origin);

#define md_symbol_get_ptr_value(item, type, origin) do { \
	if (debug_symbol_get_addr(#origin)) { \
		item = *(type)debug_symbol_get_addr(#origin); \
	} else { \
		item = 0; \
		MD_PRINT("cannont find symbol: %s", #origin); \
	} \
} while(0)

static unsigned long debug_symbol_get_addr(const char *symbol)
{
	if (symbol == NULL)
		return 0;
	return (unsigned long)debug_symbol_lookup_name(symbol);
}

void micro_symbol_init(void)
{
	int ret  = 0;
	ret = debug_symbol_available();
	if (ret != 0) {
		MD_PRINT("debug_symbol_init failed: not avaliable\n");
		return;
	}

	/* linker symbol initialization */
	md_symbol_init(_text_addr, unsigned long, _text);
	md_symbol_init(_etext_addr, unsigned long, _etext);
	md_symbol_init(__bss_start_addr, unsigned long, __bss_start);
	md_symbol_init(__bss_stop_addr, unsigned long, __bss_stop);
	md_symbol_init(_sdata_addr, unsigned long, _sdata);
	md_symbol_init(_edata_addr, unsigned long, _edata);
	md_symbol_init(__init_begin_addr, unsigned long, __init_begin);
	md_symbol_init(__init_end_addr, unsigned long, __init_end);
	md_symbol_init(__start_rodata_addr, unsigned long, __start_rodata);

	/* kernel variable initialization */
	md_symbol_init(micro_memblock, struct memblock *, memblock);
	md_symbol_init(micro_irq_stack_ptr, unsigned long *, irq_stack_ptr);
	md_symbol_get_ptr_value(high_memory_addr, unsigned long *, high_memory);
	md_symbol_get_ptr_value(module_alloc_base_addr, const unsigned long *, module_alloc_base);

	/* function pointer */
	micro_put_task_stack = (void(*)(struct task_struct *))debug_symbol_lookup_name("put_task_stack");
	return;
}

/* export qualcomm debug_symbol_lookup_name for kallsyms_lookup_name */
unsigned long micro_symbol_lookup_name(const char *name)
{
	if (debug_symbol_available()) {
		MD_PRINT("debug_symbol_init failed: not avaliable\n");
		return 0;
	}
	return debug_symbol_lookup_name(name);
}

/* replace show_stack to micro_show_stack */
extern void dump_backtrace(struct pt_regs *regs, struct task_struct *tsk, const char *loglvl);

void micro_show_stack(struct task_struct *tsk, unsigned long *sp, const char *loglvl)
{
	dump_backtrace(NULL, tsk, loglvl);
	barrier();
}

/* replace fixup_red_left to micro_fixup_red_left */
#ifdef CONFIG_SLUB_DEBUG
#ifdef CONFIG_SLUB_DEBUG_ON
static bool micro_slub_debug_enabled = true;
#else
static bool micro_slub_debug_enabled = false;
#endif

static inline bool __slub_debug_enabled_micro(void)
{
	return micro_slub_debug_enabled;
}
#else
static inline bool __slub_debug_enabled_micro(void)
{
	return false;
}
#endif

static bool micro_kmem_cache_debug_flags(struct kmem_cache *s, slab_flags_t flags)
{
	if (IS_ENABLED(CONFIG_SLUB_DEBUG))
		VM_WARN_ON_ONCE(!(flags & SLAB_DEBUG_FLAGS));
	if (__slub_debug_enabled_micro())
		return s->flags & flags;
	return false;
}

void *micro_fixup_red_left(struct kmem_cache *s, void *p)
{
	if (micro_kmem_cache_debug_flags(s, SLAB_RED_ZONE))
		p += s->red_left_pad;
	return p;
}

/* replace stacktrace.h */
static bool micro_on_irq_stack(unsigned long sp, unsigned long size, struct stack_info *info)
{
	unsigned long low, high;
	if (!micro_irq_stack_ptr) {
		MD_PRINT("irq_stack_ptr not avaliable\n");
		return false;
	}
	low = (unsigned long)raw_cpu_read(micro_irq_stack_ptr);
	high = low + IRQ_STACK_SIZE;

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 15, 0)
	return on_stack(sp, size, low, high, STACK_TYPE_IRQ, info);
#else
	return on_stack(sp, low, high, STACK_TYPE_IRQ, info);
#endif
}

static bool micro_on_overflow_stack(unsigned long sp, unsigned long size, struct stack_info *info)
{
	unsigned long low, high;
	unsigned long *micro_overflow_stack = (unsigned long *)debug_symbol_lookup_name("overflow_stack");
	if (!micro_overflow_stack) {
		MD_PRINT("micro_overflow_stack not avaliable\n");
		return false;
	}
	low = (unsigned long)raw_cpu_ptr(micro_overflow_stack);
	high = low + OVERFLOW_STACK_SIZE;

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 15, 0)
	return on_stack(sp, size, low, high, STACK_TYPE_OVERFLOW, info);
#else
	return on_stack(sp, low, high, STACK_TYPE_OVERFLOW, info);
#endif
}

bool micro_on_accessible_stack(const struct task_struct *tsk,
				       unsigned long sp, unsigned long size,
				       struct stack_info *info)
{
	if (info)
		info->type = STACK_TYPE_UNKNOWN;

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 15, 0)
	if (on_task_stack(tsk, sp, size, info))
		return true;
	if (tsk != current || preemptible())
		return false;
	if (micro_on_irq_stack(sp, size, info))
		return true;
	if (micro_on_overflow_stack(sp, size, info))
		return true;
	if (on_sdei_stack(sp, size, info))
		return true;
#else
	if (on_task_stack(tsk, sp, info))
		return true;
	if (tsk != current || preemptible())
		return false;
	if (micro_on_irq_stack(sp, size, info))
		return true;
	if (micro_on_overflow_stack(sp, size, info))
		return true;
	if (on_sdei_stack(sp, info))
		return true;
#endif
	return false;
}
