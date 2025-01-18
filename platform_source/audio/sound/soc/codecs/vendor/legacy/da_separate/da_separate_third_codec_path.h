/*
 * da_separate_third_codec_path.h -- codec driver
 *
 * Copyright (c) 2019 Huawei Technologies Co., Ltd.
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

#ifndef __DA_SEPARATE_THIRD_CODEC_PATH_H__
#define __DA_SEPARATE_THIRD_CODEC_PATH_H__

#include <sound/soc.h>
#include "da_separate_reg.h"

int add_third_codec(struct snd_soc_component *codec);

#endif
