/*
 * Huawei ntc tm table header
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
#ifndef HW_NTC_TM_TABLE_H
#define HW_NTC_TM_TABLE_H

#include <linux/err.h>
#include <linux/types.h>
#include <linux/interrupt.h>
#include <linux/delay.h>
#include <linux/kthread.h>
#include <linux/input.h>
#include <linux/time.h>
#include <linux/device.h>
#include <linux/pm_wakeup.h>
#include <linux/syscalls.h>
#include <linux/mutex.h>
#include <linux/io.h>
#include <linux/hw/hw_adc.h>
#include "hw_peripheral_tm.h"

#ifdef CONFIG_HW_HKADC_MODEM
#include "modem_hkadc_temp.h"
#endif

/* in order to resolve divisor less than zero */
#define PRORATE_OF_INIT		1000
#define NCP_GENERAL1_NUM	34
#define ROOM_DEFAULT_TEMP	25000

enum ntc_tm_table_list {
	THERMAL_ADC2TEMP_FLAG = 0,
	THERMAL_PA_VOLT2TEMP_FLAG = 1,
	THERMAL_SOC_VOLT2TEMP_FLAG = 2
};

#endif
