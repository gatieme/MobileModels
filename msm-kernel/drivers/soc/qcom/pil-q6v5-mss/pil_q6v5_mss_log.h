/*
 * Copyright (C) 2013 Huawei Device Co.Ltd
 * License terms: GNU General Public License (GPL) version 2
 *
 */

#ifndef PIL_Q6V5_MSS_LOG
#define PIL_Q6V5_MSS_LOG
#include <linux/types.h>
#include <linux/soc/qcom/smem.h>
#define SMEM_NUM_SMD_STREAM_CHANNELS 64

void save_modem_reset_log(char reason[], int reasonLength);
void wpss_reset_save_log(char reason[], int reasonLength);
void save_modem_err_log(char *modem_log, size_t size,int type);

int create_modem_log_queue(void);
void destroy_modem_log_queue(void);

#endif
