/* Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved. */

#ifndef __DDR_PERF_CTRL_COMMON_H__
#define __DDR_PERF_CTRL_COMMON_H__

#if defined(CONFIG_DDR_CRATER)
#define PERF_CTRL_DDR_MAX_CH    8
#elif defined(CONFIG_DDR_PISCES)
#define PERF_CTRL_DDR_MAX_CH    2
#else
#define PERF_CTRL_DDR_MAX_CH    4
#endif

#endif /* __DDR_PERF_CTRL_COMMON_H__ */
