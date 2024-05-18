/*
 * Copyright (c) Honor Device Co., Ltd. 2021-2021. All rights reserved.
 * Description: define platform-dependent bootfail interfaces
 * Author: yuanshuai
 * Create: 2021-2-3
 */

#ifndef BOOTFAIL_SPRD_H
#define BOOTFAIL_SPRD_H

#include <linux/vmalloc.h>
#include <linux/types.h>
#include <linux/semaphore.h>

/* ---- c++ support ---- */
#ifdef __cplusplus
extern "C" {
#endif

/* ---- export macroes ---- */

/*---- export function prototypes ----*/
void bootfail_pwk_press(void);
void bootfail_pwk_release(void);

/* ---- c++ support ---- */
#ifdef __cplusplus
}
#endif
#endif
