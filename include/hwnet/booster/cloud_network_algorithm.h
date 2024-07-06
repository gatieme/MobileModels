/**
 * cloud_cellular_algorithm.h
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
*/
#ifndef CLOUD_CELLULAR_ALGORITHM_H
#define CLOUD_CELLULAR_ALGORITHM_H
#include <linux/types.h>
#include <linux/version.h>
#include <linux/spinlock.h>
#include "cloud_network.h"

typedef void (*status_change_callback) (algorithm_path status);
void cellular_algorithm_start(algorithm_path paths_in_use, status_change_callback status_change);
void cellular_algorithm_stop(void);
int cellular_usage_notification(algorithm_path paths_in_use);
algorithm_path cellular_expect_status(void);
#endif /* CLOUD_CELLULAR_ALGORITHM_H */