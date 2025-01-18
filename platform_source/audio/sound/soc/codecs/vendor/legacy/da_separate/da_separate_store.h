/*
 * da_separate_store.h -- codec driver
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

#ifndef __DA_SEPARATE_STORE_H__
#define __DA_SEPARATE_STORE_H__

#include <sound/soc.h>

int da_separate_store_subscribe_path(struct snd_soc_component *codec, const char **name_list, unsigned int num);
#endif

