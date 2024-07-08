/*
 * Generic driver head file for the cambricon ipu device.
 *
 * Copyright (C) 2016 Cambricon Limited
 *
 * Licensed under the GPL v2 or later.
 */
#ifndef _CAMBRICON_IPU_H
#define _CAMBRICON_IPU_H

#include <asm/io.h>
#define COMP_CAMBRICON_IPU_DRV_NAME "hisilicon,cambricon-ipu"
/* ipu base address */
#define IPU_NAME	"ipu"

/* configure registers info */
#define IPU_CONF_REG_BASE	(IPU_BASE_ADDRESS + 0x00000000)
#define IPU_CONF_REG_SIZE	0x00100000
/* instruction RAM info */
#define IPU_INST_RAM_BASE	(IPU_BASE_ADDRESS + 0x00100000)
#define IPU_INST_RAM_SIZE	0x00100000

/* ipu configure register offset */
#define IPU_START_REG 0x18	/* IPU start up reg */
#define IPU_STATUS_REG 0x20	/* IPU payload finish status reg */
#define IPU_BASE_ADDR_REG 0x28	/* IPU access external DDR address */
#define IPU_SRAM_CTRL_REG 0x30	/* IPU internal SRAM configure reg */

/* ipu status */
#undef SUCCESS
#undef FAILURE
#define SUCCESS 0
#define FAILURE -1

/* reserved DDR memory info */
#define DMA_BUFFER_START	0x20c00000
#define DMA_BUFFER_SIZE	(500 * 1024 * 1024)

/* Configuration Registers Operations: ioctl */
#define MAGIC_NUM	100
#define RDCONFIG_BYTE	_IOR(MAGIC_NUM, 1, unsigned int)
#define RDCONFIG_WORD	_IOR(MAGIC_NUM, 2, unsigned int)
#define RDCONFIG_DWORD	_IOR(MAGIC_NUM, 3, unsigned int)
#define WRCONFIG_BYTE	_IOW(MAGIC_NUM, 4, unsigned int*)
#define WRCONFIG_WORD	_IOW(MAGIC_NUM, 5, unsigned int*)
#define WRCONFIG_DWORD	_IOW(MAGIC_NUM, 6, unsigned int*)

#endif
