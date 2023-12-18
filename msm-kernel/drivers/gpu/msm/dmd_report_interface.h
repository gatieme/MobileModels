/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: add GPU FAULT DMD upload to GPU driver
 * Author: Yiping Long 00525429
 * Create: 2021-07-13
 * version 2.0: 2022-0705
 * file: dmd_report_interface.h
 */

enum {
    GPU_OTHER_FAULT = 0,
    GPU_PAGE_FAULT,
    GPU_SOFT_FAULT,
    GPU_HARD_FAULT,
    PON_FAULT_EVENT,
};

void report_dmd_inirq(int event, const char* context);