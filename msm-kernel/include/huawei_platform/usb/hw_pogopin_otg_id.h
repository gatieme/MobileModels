/* SPDX-License-Identifier: GPL-2.0 */
/*
 * hw_pogopin_otg_id.h
 *
 * huawei pogopin driver
 *
 * Copyright (c) 2021-2021 Huawei Technologies Co., Ltd.
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

#ifndef _HW_POGOPIN_OTG_ID_H_
#define _HW_POGOPIN_OTG_ID_H_

#include <linux/iio/consumer.h>

#ifndef TRUE
#define TRUE                        1
#endif
#ifndef FALSE
#define FALSE                       0
#endif

#define EXTCON_USB_HOST_CONNECT     1
#define EXTCON_USB_HOST_DISCONNECT  0

#define SAMPLE_DOING                0
#define SAMPLE_DONE                 1

#define VBUS_IS_CONNECTED           0
#define DISABLE_USB_IRQ             0
#define FAIL                        (-1)
#define SAMPLING_OPTIMIZE_FLAG      1
#define SAMPLING_INTERVAL           10
#define SMAPLING_OPTIMIZE           5
#define VBATT_AVR_MAX_COUNT         10
#define ADC_VOLTAGE_LIMIT           150000
#define ADC_VOLTAGE_MAX             1250000
#define ADC_VOLTAGE_NEGATIVE        2000000
#define USB_CHARGER_INSERTED        1
#define USB_CHARGER_REMOVE          0
#define TIMEOUT_1000MS              1000
#define TIMEOUT_200MS               200
#define TIMEOUT_800MS               800
#define SLEEP_50MS                  50
#define OTG_DELAYED_5000MS          5000
#define OTG_INVALID_ADC             0
#define ADC_SAMPLING_SUM_DEFAULT    0
#define ADC_SAMPLING_RETRY_TIMES    30
#define ADC_SAMPLE_COUNT_DEFAULT    0
#define OCP_DELAY_2MS               2
#define GET_ADC_FAIL                (-1)

struct pogopin_otg_id_dev {
	struct platform_device *pdev;
	struct wakeup_source *wakelock;
	u32 otg_adc_channel;
	int gpio;
	int irq;
	int ocp_int_gpio;
	int ocp_irq;
	int ocp_en_gpio;
	int ocp_control_support;
	struct work_struct ocp_work;
	int pogo_otg_gpio_status;
	struct delayed_work otg_intb_work;
	bool otg_irq_enabled;
	bool is_iio_init;
	struct iio_channel *channel_raw;
	struct iio_channel *id_iio;
	struct notifier_block pogopin_otg_status_check_nb;
};
#endif /* _HW_POGOPIN_OTG_ID_H_ */
