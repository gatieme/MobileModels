/*
 * da_separate_smpa_path.h -- codec driver
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

#ifndef __DA_SEPARATE_SMPA_PATH_H__
#define __DA_SEPARATE_SMPA_PATH_H__

#include <sound/soc.h>
#include "da_separate_reg.h"

int add_smpa(struct snd_soc_component *codec);

void smpa_asp_soc_reg_init(struct snd_soc_component *codec);

#endif
