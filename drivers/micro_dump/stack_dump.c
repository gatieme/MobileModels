/*
 * Copyright (c) Honor Device Co., Ltd. 2022-2022. All rights reserved.
 * Description:get stack information
 * Author: Lu Laicheng
 * Create: 2022-03-22
 */

#include <micro_dump.h>

void microdump_print_scs_x18(unsigned long x18)
{
	if (!microdump_check_addr_valid((unsigned long)x18))
		return;

	MD_PRINT("%s x18=0x%lx\n", __func__, x18);
	microdump_page_dump_checked(x18, ONE_PAGE, NULL);
}

void microdump_print_scs_task(struct task_struct *task)
{
	if (!task)
		return;

	if (!microdump_check_addr_valid((unsigned long)(uintptr_t)task))
		return;

	MD_PRINT("%s task=0x%lx\n", __func__, task);
#ifdef CONFIG_THREAD_INFO_IN_TASK
	if (!microdump_check_addr_valid((unsigned long)(&(task->thread_info))))
		return;

#ifdef CONFIG_SHADOW_CALL_STACK
	if (task->thread_info.scs_sp != NULL) {
		unsigned long addr = (unsigned long)task->thread_info.scs_sp;
		microdump_page_dump_checked(addr, 1, NULL);
	}
#endif
#endif
}

void microdump_stack_adjust_by_task(struct task_struct* task)
{
	struct microdump_page_info info = {0};
	int i;
	if (!task)
		return;

	for (i = 0; i < TASK_MULTIPLE_PAGE_SIZE; i++) {
		if (microdump_check_addr_valid((unsigned long)task->stack + i * PAGE_SIZE)) {
			info.type = TYPE_STACK;
			info.start_vir_addr = (unsigned long)task->stack;
			MD_PRINT("%s task=0x%lx , stack=0x%lx, sp=0x%lx ,fp=0x%lx ,pc=0x%lx\n", __func__, task,
				(unsigned long)task->stack, thread_saved_sp(task), thread_saved_fp(task), thread_saved_pc(task));
			microdump_page_dump_checked((unsigned long)task->stack + i * PAGE_SIZE,
				TASK_MULTIPLE_PAGE_SIZE - i, &info);
			break;
		}
	}
}

void microdump_stack_adjust_by_sp(unsigned long sp, struct task_struct* task, unsigned long fp)
{
	struct microdump_page_info info = {0};
	unsigned long print_len;
	bool same_stack = false;

	if (sp > (unsigned long)task->stack && sp < (((unsigned long)task->stack)
		+ TASK_MULTIPLE_PAGE_SIZE * PAGE_SIZE))
		same_stack = true;

	if (!same_stack) {
		microdump_stack_adjust_by_task(task);
		if (microdump_check_addr_valid(sp)) {
			microdump_addr_page_info(sp, &info);
			info.type = TYPE_STACK;
			info.start_vir_addr = sp & PAGE_ALIGN_MASK;
			microdump_page_dump(sp, ONE_PAGE, &info);
			MD_PRINT("%s not same stack end, sp:0x%lx, fp:0x%lx task->stack:0x%lx\n", __func__, sp, fp,
				(unsigned long)task->stack);
		}
	} else {
		print_len = (unsigned long)task->stack + TASK_MULTIPLE_PAGE_SIZE * PAGE_SIZE - sp;
		if (print_len >= (TASK_MULTIPLE_PAGE_SIZE * PAGE_SIZE)) {
			MD_PRINT("%s: invalid sp:0x%lx or task->stack:0x%lx, print_len:%d \n", __func__, sp, task->stack, print_len);
			return;
		}
		MD_PRINT("%s: sp:0x%lx, fp:0x%lx, task->stack:0x%lx, print_len:%d\n", __func__, sp, fp, task->stack, print_len);
		if (microdump_check_addr_valid(sp)) {
			microdump_addr_page_info(sp, &info);
			info.type = TYPE_STACK;
			info.start_vir_addr = (unsigned long)task->stack;
			microdump_byte_dump_checked(sp, 0, print_len, &info);
			MD_PRINT("%s end, sp:0x%lx \n", __func__, sp);
		} else {
			// register sp invalid, dump sp use current
			MD_PRINT("%s end, sp:0x%lx is invalid \n", __func__, sp);
		}
	}
}

bool is_stack_ptr(unsigned long sp, unsigned long addr)
{
	unsigned long distance;
	if (sp > addr) {
		distance = sp - addr;
	} else {
		distance = addr - sp;
	}

	return (distance < PAGE_SIZE * TASK_MULTIPLE_PAGE_SIZE);
}

static void micro_dump_get_stack_frame(unsigned long sp, unsigned long *stack,
	unsigned long *size, u32 nr)
{
	unsigned long fp;
	uintptr_t p;
	unsigned long stack_bottom;

	if (!stack)
		return;

	stack_bottom = ((unsigned long)(uintptr_t)stack) + (PAGE_SIZE * TASK_MULTIPLE_PAGE_SIZE);
	MD_PRINT("%s in, sp:0x%lx, stack:0x%lx, nr:0x%lx bottom:0x%lx sp aglin:0x%lx\n",
		__func__, sp, stack, nr, stack_bottom,
		!IS_ALIGNED(sp, sizeof(unsigned long)));

	if (!IS_ALIGNED(sp, sizeof(unsigned long)))
		return;
	if (sp < (unsigned long)(uintptr_t)stack || sp > stack_bottom)
		return;

	MD_PRINT("%s in, sp:0x%lx, stack:0x%lx, nr:0x%lx\n", __func__, sp, stack, nr);

	fp = sp;
	p = (uintptr_t)fp;

	while (nr-- > 0 && (unsigned long)p >= sp && (unsigned long)p < stack_bottom) {
		if (microdump_check_addr_valid((unsigned long)p)) {
			fp = (unsigned long)p;
			p = (uintptr_t) *((unsigned long *)p);
		} else {
			break;
		}
	}
	*size = fp - sp;
}

void microdump_stack_local_var(unsigned long sp, unsigned long *stack, u32 nr_frame)
{
	unsigned long addrs;
	unsigned long size = 0;
	unsigned long *p;
	int def_nr_frame = MAX_STACK_FRAME;
	int i;
	struct microdump_page_info info = {0};

	if (!IS_ALIGNED(sp, sizeof(unsigned long)))
		return;

	if (sp < (unsigned long)(uintptr_t)stack ||
		sp > ((unsigned long)(uintptr_t)stack + TASK_MULTIPLE_PAGE_SIZE * PAGE_SIZE))
		return;

	if (nr_frame > 0) {
		def_nr_frame = (nr_frame > MAX_STACK_FRAME) ? MAX_STACK_FRAME : nr_frame;
	}
	micro_dump_get_stack_frame(sp, stack, &size, def_nr_frame);
	MD_PRINT("%s size:0x%lx\n", __func__, size);
	if (size <= 0 || size >= (TASK_MULTIPLE_PAGE_SIZE * PAGE_SIZE)) {
		MD_PRINT("%s size:0x%lx is invalid\n", __func__, size);
		return;
	}

	addrs = sp;
	for (i = 0; i < size / sizeof(unsigned long); i++) {
		addrs = sp + i * sizeof(unsigned long);

		p = (unsigned long *)(uintptr_t)addrs;
		if (microdump_check_addr_valid(*p)) {
			if (is_stack_ptr(*p, (unsigned long)(uintptr_t)stack) || *p < PAGE_OFFSET)
				continue;
			microdump_addr_page_info(*p, &info);
			microdump_byte_dump_checked(*p, 0, 0, &info);
		}
	}
}

void microdump_stack_local_irq(unsigned long irq_sp)
{
	unsigned long *p;
	unsigned long addr = irq_sp;
	unsigned long page_bottom = (irq_sp & PAGE_ALIGN_MASK) + PAGE_SIZE - sizeof(unsigned long);
	struct microdump_page_info info = {0};

	if (!IS_ALIGNED(addr, sizeof(unsigned long)) || (addr > page_bottom))
		return;

	while (addr <= page_bottom) {
		addr += sizeof(unsigned long);
		if (!is_kernel_addr(addr))
			continue;
		if (is_stack_ptr(irq_sp, addr))
			continue;

		p = (unsigned long *)(uintptr_t)addr;
		if (microdump_check_addr_valid(*p)) {
			microdump_byte_dump_checked(*p, 0, 0, &info);
		}
	}
}

void microdump_stack_by_sp(unsigned long sp, struct task_struct *task, unsigned long fp)
{
	microdump_stack_adjust_by_sp(sp, task, fp);
}

void microdump_stack_by_task(struct task_struct *task)
{
	microdump_stack_adjust_by_task(task);
}

