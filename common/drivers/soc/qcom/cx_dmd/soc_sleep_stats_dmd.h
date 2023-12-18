/*
 * soc_sleep_stats_dmd.h
 *
 * cx none idle dmd upload
 *
 * Copyright (C) 2017-2021 Huawei Technologies Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */
#define RESET_SPI_IDLE_CHECK    0

void check_cx_idle_state(const __le64 cur_acc_duration, const s64 now);
void check_spi_idle_state(const s64 now);
void cx_dmd_check_apss_state(const uint64_t acc_dur, const uint64_t last_enter, const uint64_t last_exit);
