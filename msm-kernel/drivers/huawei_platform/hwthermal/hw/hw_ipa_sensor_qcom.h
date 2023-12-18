/*
 * Huawei ipa sensor qcom header
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
#ifndef HW_IPA_SENSOR_QCOM_H
#define HW_IPA_SENSOR_QCOM_H

#include <linux/thermal.h>
#include <securec.h>
#include <linux/energy_model.h>

#define DEFAULT_SHELL_TEMPERATURE 25000
#define DEFAULT_SOC_TEMPERATURE 85000

enum hw_peripheral_temp_chanel {
	DETECT_SYSTEM_H_CHANEL = 0,
};

enum hw_ipa_tsens {
	IPA_CLUSTER_0 = 0,
	IPA_CLUSTER_1,
	IPA_CLUSTER_2,
	IPA_GPU,
};

#endif
