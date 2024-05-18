/*
 * Copyright (c) Honor Device Co., Ltd. 2020-2020. All rights reserved.
 * Description: define adapter for MTK
 * Author: yuanshuai
 * Create: 2020-10-26
 */

#ifndef ADAPTER_MSTAR_H
#define ADAPTER_MSTAR_H

#include <bootfail/core/adapter.h>

#ifdef __cplusplus
extern "C" {
#endif

#define BFI_DEV_PATH "/dev/block/by-name/rrecord"

/* 12MB -128 KB */
#define BFI_PART_SIZE 0xFF0000

/* ----local macroes ---- */
#define BL_LOG_NAME "fastboot_log"
#define KERNEL_LOG_NAME "last_kmsg"
#define BL_LOG_MAX_LEN 0x3f000

#define BF_BOPD_RESERVE 32

int bf_rmem_init(void);
void *get_bf_mem_addr(void);
unsigned long get_bf_mem_size(void);
int mstar_adapter_init(struct adapter *padp);
void mstar_save_long_press_logs(void);

#ifdef __cplusplus
}
#endif
#endif

