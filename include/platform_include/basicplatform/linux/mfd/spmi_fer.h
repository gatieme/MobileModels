/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 *
 * spmi_fer.h
 *
 * SPMI Debug fs support
 *
 * This software is licensed under the terms of the GNU General Public
 * either version 2 of that License or (at your option) any later version.
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef _SPMI_FER_H
#define _SPMI_FER_H

#ifdef CONFIG_SPMI_FER_PLATFORM
void spmi_fer_irq_ocp_mask(unsigned int fernum);
void spmi_fer_irq_ocp_unmask(unsigned int fernum);
#else
void spmi_fer_irq_ocp_mask(unsigned int fernum) { return; }
void spmi_fer_irq_ocp_unmask(unsigned int fernum) { return; }
#endif

#endif /* _SPMI_FER_H */