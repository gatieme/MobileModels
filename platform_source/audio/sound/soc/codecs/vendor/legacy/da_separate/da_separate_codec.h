/*
 * da_separate_codec.h -- codec driver
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

#ifndef __DA_SEPARATE_CODEC_H__
#define __DA_SEPARATE_CODEC_H__
#include "da_separate_type.h"

void da_separate_codec_driver_init(const struct codec_ops *ops);

#endif

