/*
 * Copyright (c) Honor Device Co., Ltd. 2022-2022. All rights reserved.
 * Description:micro dump output print function
 * Author: Lu Laicheng
 * Create: 2022-03-22
 */

#include <micro_dump.h>

/* dump a block of kernel memory from around the given address */
static void show_data(unsigned long addr, unsigned long nbytes, const struct microdump_page_info *info)
{
	int i, no_zero;
	int nlines;
	unsigned long *ptr, *p;

	if (addr > (unsigned long)ABOVE_MEM_VALID) {
		MD_PRINT("show_data: addr is invalid, addr:%016llx ABOVE_MEM_VALID:%016llx", addr,
			ABOVE_MEM_VALID);
		return;
	}

	ptr = (unsigned long *)(uintptr_t)addr;
	nbytes += (addr & (sizeof(u32) - 1));
	nlines = (nbytes + LINE_SIZE - 1) / LINE_SIZE;
	MD_PRINT("dump %016llx, total bytes:%u ", addr, nlines * LINE_SIZE);
	for (i = 0; i < nlines; i++) {
		p = ptr;
		no_zero = 0;
		do {
			if (*p != 0) {
				no_zero = 1;
				break;
			}
		} while (++p < (ptr + sizeof(unsigned long)));
		if (no_zero) {
			MD_PRINT("%04lx  %016llx %016llx %016llx %016llx %016llx %016llx %016llx %016llx",
				((unsigned long)(uintptr_t)ptr) & 0xffff, *(unsigned long *)(ptr), *(unsigned long *)(ptr + 1),
				*(unsigned long *)(ptr + 2), *(unsigned long *)(ptr + 3), *(unsigned long *)(ptr + 4),
				*(unsigned long *)(ptr + 5), *(unsigned long *)(ptr + 6), *(unsigned long *)(ptr + 7));
		}
		ptr += sizeof(unsigned long);
	}
}

void minidump_section_mark(unsigned long addr, unsigned long size, struct microdump_page_info *info)
{
	MD_PRINT("addr: %016llx, size: %016llx, info: %016llx");
}

int print_to_minidump(unsigned long addr, unsigned long size, struct microdump_page_info *info)
{
	if (addr == 0)
		return -1;

	minidump_section_mark(addr, size, info);
	return 0;
}

int print_to_console(unsigned long addr, unsigned long size, struct microdump_page_info *info)
{
	if (addr == 0)
		return -1;

	show_data(addr, size, info);
	return 0;
}
