/*
 * da_separate_fpga.h is used to work by da_separate_fpga
 *
 * Copyright (c) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#ifndef __DA_SEPARATE_FPGA_H__
#define __DA_SEPARATE_FPGA_H__

#include <sound/soc.h>

void au0_io_init(struct snd_soc_component *codec);
bool is_pmu_version_valid(struct snd_soc_component *codec);
#endif
