/*
 * Copyright (c) Honor Device Co., Ltd. 2022-2022. All rights reserved.
 * Description:dump valid memory for register
 * Author: Lu Laicheng
 * Create: 2022-03-22
 */

#include <micro_dump.h>

static const char *TYPE_NAME[] = {
	"TYPE_NONE",
	"TYPE_KIMAGE",
	"TYPE_VMALLOC",
	"TYPE_BSS",
	"TYPE_DATA",
	"TYPE_INIT",
	"TYPE_RODATA",
	"TYPE_TEXT",
	"TYPE_FIXED",
	"TYPE_PCI_IO",
	"TYPE_SLAB",
	"TYPE_VMEM",
	"TYPE_PAGE",
	"TYPE_MODULE",
	"TYPE_STACK"
};

#ifndef MICRO_REGS_NUM
#define MICRO_REGS_NUM 31
#endif

static void dump_valid_memory_for_register(struct pt_regs *regs)
{
	int i;
	struct microdump_page_info info;

	for (i = 0; i < MICRO_REGS_NUM; i++) {
		if (microdump_check_addr_valid(regs->regs[i])) {
			memset_s(&info, sizeof(info), 0, sizeof(info));
			microdump_addr_page_info(regs->regs[i], &info);

			// print phy_addr and type here
			MD_PRINT("X%d register:0x%016llx PHY_ADDR:%016llx PAGE_TYPE:%s \n",
				i, (void*)regs->regs[i], info.phy_addr, TYPE_NAME[info.type]);

			if (info.type == TYPE_NONE || is_stack_ptr(regs->sp, regs->regs[i]))
				continue;

			switch (info.type) {
			case TYPE_VMALLOC:
			case TYPE_SLAB:
			case TYPE_PAGE:
				microdump_page_dump_checked(regs->regs[i], ONE_PAGE, &info);
				break;
			case TYPE_BSS:
			case TYPE_DATA:
			case TYPE_RODATA:
			case TYPE_VMEM:
				microdump_byte_dump_checked(regs->regs[i], 0, PAGE_SIZE >> 5, &info);
				break;
			case TYPE_MODULE:
#ifdef CONFIG_MODULES
				(void)microdump_ko_load_address(regs->regs[i]);
#endif
				break;
			default:
				break;
			}
		} else {
			MD_PRINT("X%d register:%px memory invalid.\n", i, (void *)regs->regs[i]);
		}
	}

	if (microdump_check_addr_valid(regs->pc)) {
		memset_s(&info, sizeof(info), 0, sizeof(info));
		microdump_addr_page_info(regs->pc, &info);
		MD_PRINT("PC register:0x%016llx PHY_ADDR:%016llx PAGE_TYPE:%s \n",
			(void *)regs->pc, info.phy_addr, TYPE_NAME[info.type]);
		// 4: print 1/16 pagesize, 5: print 1/32 pagesize
		microdump_byte_dump_checked(regs->pc, PAGE_SIZE >> 5, PAGE_SIZE >> 4, &info);
	} else {
		MD_PRINT("PC register:%px memory invalid.\n", (void *)regs->pc);
	}
}

void microdump_register_dump(void)
{
	dump_valid_memory_for_register(&g_exp_ctrl.regs);
}
