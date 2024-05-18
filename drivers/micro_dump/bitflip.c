/*
 * Copyright (c) Honor Device Co., Ltd. 2022-2022. All rights reserved.
 * Description: bitflip detect
 * Author: yangyusheng
 * Create: 2022-11-10
 */

#include <micro_dump.h>
#include <asm/traps.h>
#ifdef CONFIG_RAINBOW_REASON
#include <linux/rainbow_reason.h>
#endif

#define MAX_BITFLIP_BIT_COUNT	3
#define HIGH_ADDR_MASK		(UL(0xffffffffffffffff) - \
 	(UL(1) << CONFIG_ARM64_VA_BITS) + 1)

enum bitflip_type {
	TYPE_UNKNOWN = 0,
	TYPE_BITFLIP,
	TYPE_CACHE_BITFLIP,
	TYPE_DDR_BITFLIP,
};

struct bitflip_type_info {
	int  type;
	char *type_notes;
};

const struct bitflip_type_info g_bitflip_type_list[] = {
	{TYPE_UNKNOWN,		"unknown"},
	{TYPE_BITFLIP,		"bitflip"},
	{TYPE_CACHE_BITFLIP,	"cache bitflip"},
	{TYPE_DDR_BITFLIP,	"ddr bitflip"},
};

static int high_addr_flip_count(unsigned long addr)
{
	int flip_count = 0;
	unsigned long high_addr = addr >> CONFIG_ARM64_VA_BITS;

	while (high_addr) {
		if (!(high_addr & 1))
			flip_count++;
		high_addr >>= 1;
	}
	return flip_count;
}

void bitflip_sub_type_dabt(void)
{
	unsigned long dabt_addr = g_exp_ctrl.addr;
	int flip_count = high_addr_flip_count(dabt_addr);

	if (flip_count == 0) {
		MD_PRINT("unable to determine bitflip.\n");
		return;
	}

	if (flip_count < MAX_BITFLIP_BIT_COUNT) {
		if (microdump_check_addr_valid(dabt_addr | HIGH_ADDR_MASK)) {
			MD_PRINT("is probable %s.\n", g_bitflip_type_list[TYPE_BITFLIP].type_notes);
#ifdef CONFIG_RAINBOW_REASON
			rb_sreason_set("probable_bitflip");
#endif
		}
	}

	if (flip_count >= MAX_BITFLIP_BIT_COUNT)
		MD_PRINT("unable to determine bitflip.\n");
}
