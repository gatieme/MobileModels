/*
 * Copyright (c) Honor Device Co., Ltd. 2022-2022. All rights reserved.
 * Description:define micro dump function
 * Author: Lu Laicheng
 * Create: 2022-03-22
 */

#ifndef __MICRO_DUMP_H__
#define __MICRO_DUMP_H__

#include <linux/mm.h>
#include <linux/slab.h>
#include "../../mm/slab.h"
#include <linux/uaccess.h>
#include <linux/init.h>
#include <linux/memblock.h>
#include <linux/notifier.h>
#include <linux/elf.h>
#include <linux/kdebug.h>
#include <linux/module.h>
#include <linux/vmalloc.h>
#include <linux/bug.h>
#include <linux/compiler.h>
#include <linux/printk.h>
#include <linux/sizes.h>
#include <linux/spinlock.h>
#include <linux/stacktrace.h>
#include <linux/highmem.h>
#include <linux/kasan.h>
#include <linux/version.h>
#include <sched/sched.h>

#include <asm/stacktrace.h>
#include <asm/pgtable.h>
#include <asm-generic/percpu.h>
#include <asm-generic/sections.h>
#include <asm/page.h>
#include <asm/irq.h>
#include <asm/kexec.h>
#include <asm/memory.h>
#include <asm/traps.h>
#include <asm/sysreg.h>

#include <policy.h>
#include "securec.h"

#ifdef CONFIG_MTK_AEE_IPANIC
#include <linux/arm-smccc.h>
#include <mt-plat/mrdump.h>
#include <mrdump_private.h>
#endif
#define MICRO_DUMP "[MICRO_DUMP]"
#define MD_PRINT(fmt, ...) printk(KERN_ERR MICRO_DUMP fmt, ##__VA_ARGS__)

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 15, 0))
#include <linux/panic_notifier.h>
#endif

extern struct memblock memblock;

#define DIE_TYPE_UNKNOWN			(0x0)

#define DIE_TYPE_DABT				(0x1000)
#define SUB_TYPE_UNKNOWN_ADDR		(DIE_TYPE_DABT + 1)
#define SUB_TYPE_RW_ONLY			(DIE_TYPE_DABT + 2)
#define SUB_TYPE_UNREADABLE			(DIE_TYPE_DABT + 3)
#define SUB_TYPE_UNEXCUTE			(DIE_TYPE_DABT + 4)
#define SUB_TYPE_NULL_POINT			(DIE_TYPE_DABT + 5)
#define SUB_TYPE_PAGE_REQ			(DIE_TYPE_DABT + 6)
#define SUB_TYPE_SP_PC				(DIE_TYPE_DABT + 7)
#define SUB_TYPE_UNHANDLE			(DIE_TYPE_DABT + 8)

#define DIE_TYPE_HUNG				(0x10000)
#define SUB_TYPE_HUNG_TASK			(DIE_TYPE_HUNG + 1)
#define SUB_TYPE_HANG_DETECT		(DIE_TYPE_HUNG + 2)
#define SUB_TYPE_WDT				(DIE_TYPE_HUNG + 3)

#define DIE_TYPE_BUS				(0x100000)
#define SUB_TYPE_SEA				(DIE_TYPE_BUS + 1)

#define DIE_TYPE_ASSERT				(0x1000000)
#define SUB_TYPE_BUG_ON				(DIE_TYPE_ASSERT + 1)
#define SUB_TYPE_BUG				(DIE_TYPE_ASSERT + 2)
#define SUB_TYPE_TRIGGER			(DIE_TYPE_ASSERT + 3)
#define SUB_TYPE_MANUAL_TRIGGER		(DIE_TYPE_ASSERT + 4)
#define SUB_TYPE_OTHER_PANIC		(DIE_TYPE_ASSERT + 5)
#define SUB_TYPE_OTHER_DIE			(DIE_TYPE_ASSERT + 6)

#define DIE_TYPE_UNDEFINE_INSTR		(0x10000000)
#define SUB_TYPE_UNDEFINE_INSTR		(DIE_TYPE_UNDEFINE_INSTR + 1)

#define DIE_TYPE_OOM				(0x100000000)
#define SUB_TYPE_OOM				(DIE_TYPE_OOM + 1)
#define SUB_TYPE_DEADLOCK_MEM		(DIE_TYPE_OOM + 2)

#define DIE_TYPE_SUBSYS				(0x1000000000)
#ifdef CONFIG_ARCH_QCOM
#define SUB_TYPE_BASE				(DIE_TYPE_SUBSYS + 0x0)
#define SUB_TYPE_ADSP				(SUB_TYPE_BASE + 1)
#define SUB_TYPE_MODEM				(SUB_TYPE_BASE + 2)
#define SUB_TYPE_RPM				(SUB_TYPE_BASE + 3)
#define SUB_TYPE_TZ					(SUB_TYPE_BASE + 4)
#endif
#ifdef CONFIG_ARCH_MTK
#define SUB_TYPE_BASE				(DIE_TYPE_SUBSYS + 0x10)
#define SUB_TYPE_SCP				(SUB_TYPE_BASE + 1)
#define SUB_TYPE_MODEM				(SUB_TYPE_BASE + 2)
#define SUB_TYPE_SSPM				(SUB_TYPE_BASE + 3)
#define SUB_TYPE_TZ					(SUB_TYPE_BASE + 4)
#define SUB_TYPE_ADSP				(SUB_TYPE_BASE + 5)
#endif

#define MAX_STACK_FRAME				8
#define ABOVE_MEM_VALID				(-256UL)
#define PAGE_ALIGN_MASK				(~(unsigned long)((1 << PAGE_SHIFT) - 1))
#define LINE_SHIFT					6
#define LINE_ALIGN_MASK				(~(unsigned long)((1 << LINE_SHIFT) - 1))
#define LINE_SIZE					64
#define TASK_MULTIPLE_PAGE_SIZE		4
#define ONE_PAGE					PAGE_SIZE >> PAGE_SHIFT
#define SCS_REGISTER				18
#define FP_REGISTER					29
#define MICRO_CPU_NR				(nr_cpu_ids)

enum microdump_page_type {
	TYPE_NONE = 0,
	TYPE_KIMAGE,
	TYPE_VMALLOC,
	TYPE_BSS,
	TYPE_DATA,
	TYPE_INIT,
	TYPE_RODATA,
	TYPE_TEXT,
	TYPE_FIXED,
	TYPE_PCI_IO,
	TYPE_SLAB,
	TYPE_VMEM,
	TYPE_PAGE,
	TYPE_MODULE,
	TYPE_STACK,
};

struct microdump_page_info {
	unsigned long start_vir_addr;
	unsigned long phy_addr;
	int order;
	enum microdump_page_type type;
	struct page *page;
};

typedef int (*out_print) (unsigned long addr, unsigned long size, struct microdump_page_info *info);

#define MAX_DUMP_ADDR_NUM 32

struct global_exp_ctrl {
	unsigned long addr;
	unsigned long error_type;
	int die_cpu;
	int panic_cpu;
	int die_in_irq;
	out_print print_func;
	struct task_struct *task;
	struct pt_regs regs;
	unsigned long dump_addr[MAX_DUMP_ADDR_NUM];
	u32 dump_size[MAX_DUMP_ADDR_NUM];
};

extern struct global_exp_ctrl g_exp_ctrl;

int reverse_policy(unsigned long type);
int print_to_minidump(unsigned long addr, unsigned long size, struct microdump_page_info *info);
int print_to_console(unsigned long addr, unsigned long size, struct microdump_page_info *info);
void microdump_addr_page_info(unsigned long addr, struct microdump_page_info *info);
bool is_kernel_addr(unsigned long addr);
bool microdump_check_addr_valid(unsigned long addr);
void microdump_page_dump_checked(unsigned long ptr, int nr_page, struct microdump_page_info *info);
void microdump_page_dump(unsigned long ptr, int nr_page, struct microdump_page_info *info);
void microdump_byte_dump_checked(unsigned long ptr, int before_byte, int nr_byte,
	struct microdump_page_info *info);
void microdump_on_core_process_dump(void);
void microdump_D_state_process_dump(void);
void microdump_crucial_process_dump(void);
int microdump_ko_load_address(unsigned long addr);
void microdump_relation_process_dump(void);
void microdump_task_struct_dump(struct task_struct *task);
void microdump_register_dump(void);
bool is_stack_ptr(unsigned long sp, unsigned long addr);
void microdump_stack_local_var(unsigned long sp, unsigned long *stack, u32 nr_frame);
void microdump_stack_by_sp(unsigned long sp, struct task_struct *task, unsigned long fp);
void microdump_stack_by_task(struct task_struct *task);
void microdump_stack_local_irq(unsigned long irq_sp);
void microdump_print_scs_x18(unsigned long x18);
void microdump_print_scs_task(struct task_struct *task);
void microdump_cpu_irqstack(int cpu);
void microdump_irq_dump(void);
void microdump_hungtask_lock_dump(void);
void microdump_sched_dump(void);

void bitflip_sub_type_dabt(void);
void microdump_hungtask_stack(void);
void microdump_corereg_pstate(unsigned long pstate);

/* compatible for [Qualcomm & MTK] [builtin & ko] */
/* linker symbol */
extern unsigned long _text_addr;
extern unsigned long _etext_addr;
extern unsigned long __bss_start_addr;
extern unsigned long __bss_stop_addr;
extern unsigned long _sdata_addr;
extern unsigned long _edata_addr;
extern unsigned long __init_begin_addr;
extern unsigned long __init_end_addr;
extern unsigned long __start_rodata_addr;

/* kernel variable */
extern unsigned long high_memory_addr;
extern struct memblock *micro_memblock;
extern unsigned long module_alloc_base_addr;
extern unsigned long *micro_irq_stack_ptr;

/* function pointer */
extern void (*micro_put_task_stack)(struct task_struct *tsk);

void common_symbol_init(void);
void common_show_stack(struct task_struct *tsk, unsigned long *sp, const char *loglvl);
void *common_fixup_red_left(struct kmem_cache *s, void *p);
unsigned long common_symbol_lookup_name(const char *name);
bool common_on_accessible_stack(const struct task_struct *tsk,
				       unsigned long sp, unsigned long size,
				       struct stack_info *info);
int notrace common_unwind_frame(struct task_struct *tsk, struct stackframe *frame);
#endif /* __MICRO_DUMP_H__ */
