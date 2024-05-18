/*
 * Copyright (c) Honor Device Co., Ltd. 2016-2018. All rights reserved.
 * Description: the rproc.h for root processes list checking
 * Author: Yongzheng Wu <Wu.Yongzheng.>
 *         likun <quentin.lee.>
 *         likan <likan82.>
 * Create: 2016-06-18
 */

#ifndef _RPROC_H_
#define _RPROC_H_

void rprocs_strip_whitelist(char *rprocs, ssize_t rprocs_len);
int get_root_procs(char *out, size_t outlen);
bool init_rprocs_whitelist(const char *whitelist);

void rproc_init(void);
void rproc_deinit(void);

#endif

