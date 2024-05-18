/*
 * Copyright (c) Honor Device Co., Ltd. 2023-2023. All rights reserved.
 * Description:micro dump function GKI Support
 * Author: Li Chenqing
 * Create: 2023-02-28
 */

#include <micro_dump.h>

#ifdef CONFIG_HN_MICRODUMP_GKI
extern void micro_symbol_init(void);
extern void micro_show_stack(struct task_struct *, unsigned long *, const char *);
extern void *micro_fixup_red_left(struct kmem_cache *s, void *p);
extern bool micro_on_accessible_stack(const struct task_struct *tsk,
				       unsigned long sp, unsigned long size,
				       struct stack_info *info);
extern unsigned long micro_symbol_lookup_name(const char *name);
#endif

/* linker symbol */
unsigned long _text_addr;
unsigned long _etext_addr;
unsigned long __bss_start_addr;
unsigned long __bss_stop_addr;
unsigned long _sdata_addr;
unsigned long _edata_addr;
unsigned long __init_begin_addr;
unsigned long __init_end_addr;
unsigned long __start_rodata_addr;

/* kernel variable */
unsigned long high_memory_addr = 0;
struct memblock *micro_memblock = NULL;
unsigned long module_alloc_base_addr = 0;
unsigned long *micro_irq_stack_ptr = NULL;

/* function pointer */
void (*micro_put_task_stack)(struct task_struct *tsk);

void common_symbol_init(void)
{
#ifdef CONFIG_HN_MICRODUMP_GKI
	micro_symbol_init();
#else
	/* linker symbol initialization */
	_text_addr = (unsigned long)_text;
	_etext_addr = (unsigned long)_etext;
	__bss_start_addr = (unsigned long)__bss_start;
	__bss_stop_addr = (unsigned long)__bss_stop;
	_sdata_addr = (unsigned long)_sdata;
	_edata_addr = (unsigned long)_edata;
	__init_begin_addr = (unsigned long)__init_begin;
	__init_end_addr = (unsigned long)__init_end;

	high_memory_addr = (unsigned long)high_memory;
	module_alloc_base_addr = module_alloc_base;
	micro_memblock = &memblock;
	micro_irq_stack_ptr = irq_stack_ptr;

	micro_put_task_stack = NULL;
#endif
	MD_PRINT("debug_symbol_init successful\n");
	return;
}

void common_show_stack(struct task_struct *tsk, unsigned long *sp, const char *loglvl)
{
#ifdef CONFIG_HN_MICRODUMP_GKI
	micro_show_stack(tsk, sp, loglvl);
#else
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0)
	show_stack(tsk, sp);
#else
	show_stack(tsk, sp, loglvl);
#endif
#endif
	return;
}

/* common_fixup_red_left for build in and ko */
void *common_fixup_red_left(struct kmem_cache *s, void *p)
{
#ifdef CONFIG_HN_MICRODUMP_GKI
	return micro_fixup_red_left(s, p);
#else
	return fixup_red_left(s, p);
#endif
}

/* common_symbol_lookup_name for build in and ko */
unsigned long common_symbol_lookup_name(const char *name)
{
#ifdef CONFIG_HN_MICRODUMP_GKI
	return micro_symbol_lookup_name(name);
#else
	return kallsyms_lookup_name(name);
#endif
}

bool common_on_accessible_stack(const struct task_struct *tsk,
				       unsigned long sp, unsigned long size,
				       struct stack_info *info)
{
#ifdef CONFIG_HN_MICRODUMP_GKI
	return micro_on_accessible_stack(tsk, sp, size, info);
#else
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 15, 0)
	return on_accessible_stack(tsk, sp, size, info);
#else
	return on_accessible_stack(tsk, sp, info);
#endif
#endif
}

int notrace common_unwind_frame(struct task_struct *tsk, struct stackframe *frame)
{
#ifdef CONFIG_HN_MICRODUMP_GKI
	unsigned long fp = frame->fp;
	struct stack_info info;

	if (fp & 0xf)
		return -EINVAL;

	if (!tsk)
		tsk = current;

	if (!micro_on_accessible_stack(tsk, fp, 16, &info))
		return -EINVAL;

	if (test_bit(info.type, frame->stacks_done))
		return -EINVAL;
	if (info.type == frame->prev_type) {
		if (fp <= frame->prev_fp)
			return -EINVAL;
	} else {
		set_bit(frame->prev_type, frame->stacks_done);
	}
	frame->fp = READ_ONCE_NOCHECK(*(unsigned long *)(uintptr_t)(fp));
	frame->pc = READ_ONCE_NOCHECK(*(unsigned long *)(uintptr_t)(fp + 8));
	frame->prev_fp = fp;
	frame->prev_type = info.type;

	if (!frame->fp && !frame->pc)
		return -EINVAL;

	return 0;
#else
	return unwind_frame(tsk, frame);
#endif
}
