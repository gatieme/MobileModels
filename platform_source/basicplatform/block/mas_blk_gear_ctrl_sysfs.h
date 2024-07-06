#ifndef __MAS_BLK_GEAR_CTRL_SYSFS_H__
#define __MAS_BLK_GEAR_CTRL_SYSFS_H__

#include <linux/kernel.h>
#include <linux/types.h>
#include "blk.h"

ssize_t mas_gear_ctrl_store(struct request_queue *q, const char *page, size_t count);
ssize_t mas_gear_ctrl_show(struct request_queue *q, char *page);
ssize_t mas_gear_auto_enable_store(struct request_queue *q, const char *page, size_t count);
ssize_t mas_gear_auto_enable_show(struct request_queue *q, char *page);
ssize_t mas_gear_ufs_rate_store(struct request_queue *q, const char *page, size_t count);
ssize_t mas_gear_ufs_rate_show(struct request_queue *q, char *page);
ssize_t mas_gear_fg_num_store(struct request_queue *q, const char *page, size_t count);
ssize_t mas_gear_fg_num_show(struct request_queue *q, char *page);
ssize_t mas_gear_flow_wndsz_store(struct request_queue *q, const char *page, size_t count);
ssize_t mas_gear_flow_wndsz_show(struct request_queue *q, char *page);
ssize_t mas_gear_flow_threshold_size_store(struct request_queue *q, const char *page, size_t count);
ssize_t mas_gear_flow_threshold_size_show(struct request_queue *q, char *page);
ssize_t mas_gear_flow_threshold_cnt_store(struct request_queue *q, const char *page, size_t count);
ssize_t mas_gear_flow_threshold_cnt_show(struct request_queue *q, char *page);
ssize_t mas_gear_sync_num_store(struct request_queue *q, const char *page, size_t count);
ssize_t mas_gear_sync_num_show(struct request_queue *q, char *page);
ssize_t mas_min_gear_stay_time_store(struct request_queue *q, const char *page, size_t count);
ssize_t mas_min_gear_stay_time_show(struct request_queue *q, char *page);
ssize_t mas_gear_io_back_store(struct request_queue *q, const char *page, size_t count);
ssize_t mas_gear_io_back_show(struct request_queue *q, char *page);

#endif
