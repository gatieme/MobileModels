/*
 * hw_thermal_ipa.h
 *
 * head file for hw ipa thermal
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
#ifndef __HW_THERMAL_IPA_H__
#define __HW_THERMAL_IPA_H__

#ifdef CONFIG_HW_IPA_THERMAL
unsigned int ipa_get_gpu_temp(const char **tz_name);
void hw_thermal_init(struct work_struct *work);
#else
unsigned int ipa_get_gpu_temp(const char **tz_name)
{
	return 0;
}
EXPORT_SYMBOL(ipa_get_gpu_temp);

void hw_thermal_init(struct work_struct *work)
{
}
EXPORT_SYMBOL(hw_thermal_init);
#endif

#endif /* __HW_THERMAL_IPA_H__ */
