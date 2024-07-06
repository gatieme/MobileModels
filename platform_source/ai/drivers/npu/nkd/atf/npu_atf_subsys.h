/*
 * npu_atf_subsys.c
 *
 * about npu atf subsys
 *
 * Copyright (c) 2012-2019 Huawei Technologies Co., Ltd.
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
#ifndef _NPU_ATF_H_
#define _NPU_ATF_H_

#include <linux/types.h>

#define NPU_SVC_NOT_SUPPORT                        0x0F0F0F0F

int atfd_service_npu_smc(u64 _service_id, u64 _cmd, u64 _arg1, u64 _arg2);
#endif
