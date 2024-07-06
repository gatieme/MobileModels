/*
 * direct_charge_test.h
 *
 * direct charge test driver
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

#ifndef _DIRECT_CHARGE_TEST_H_
#define _DIRECT_CHARGE_TEST_H_

#ifdef CONFIG_DIRECT_CHARGER
void dc_test_set_adapter_test_result(int mode, int result);
#else
static inline void dc_test_set_adapter_test_result(int mode, int result)
{
}

#endif /* CONFIG_DIRECT_CHARGER */

#endif /* _DIRECT_CHARGE_TEST_H_ */
