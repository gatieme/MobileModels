/*
 * Huawei ipa sensor header
 *
 * Copyright (c) 2022-2022 Huawei Technologies Co., Ltd.
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
#ifndef HW_IPA_SENSOR_H
#define HW_IPA_SENSOR_H

#include <linux/thermal.h>
#include <securec.h>

#include "../../../drivers/misc/mediatek/base/power/include/mtk_upower.h"
#include "../../../drivers/misc/mediatek/base/power/include/mtk_common_static_power.h"

#define DYNAMIC_TABLE2REAL_PERCENTAGE 58

enum hw_peripheral_temp_chanel {
	DETECT_SYSTEM_H_CHANEL = 0,
};

enum hw_ipa_tsens {
	IPA_CLUSTER_0 = 0,
	IPA_CLUSTER_1,
	IPA_GPU,
};


#endif
