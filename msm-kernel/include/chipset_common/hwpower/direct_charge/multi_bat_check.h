/* SPDX-License-Identifier: GPL-2.0 */
/*
 * multi_bat_check.h
 *
 * multi battery check interface for power module
 *
 * Copyright (c) 2023-2023 Huawei Technologies Co., Ltd.
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

#ifndef _MULTI_BAT_CHECK_H_
#define _MULTI_BAT_CHECK_H_

int multi_bat_ck_get_support_mode(int cur_mode, bool cur_flag);

#endif /* _MULTI_BAT_CHECK_H_ */
