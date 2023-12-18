/*
 * dp_aux_switch.h
 *
 * dp switch driver
 *
 * Copyright (c) 2021-2022 Huawei Technologies Co., Ltd.
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

#ifndef __DP_AUX_SWITCH_H__
#define __DP_AUX_SWITCH_H__

#include <linux/kernel.h>

#if IS_ENABLED(CONFIG_HUAWEI_DP_AUX)
void dp_aux_switch_enable(bool enable);
void dp_switch_orient_cc1(void);
void dp_switch_orient_cc2(void);
#else
static inline void dp_aux_switch_enable(bool enable) {}
static inline void dp_switch_orient_cc1(void) {}
static inline void dp_switch_orient_cc2(void) {}
#endif /* !CONFIG_DP_AUX_SWITCH */

#endif /* __DP_AUX_SWITCH_H__ */
