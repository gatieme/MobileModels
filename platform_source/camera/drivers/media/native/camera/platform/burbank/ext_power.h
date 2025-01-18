/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: parse ext power setting of device, provide common power management
 *
 * This file is released under the GPLv2.
 */
#ifndef SENSOR_POWER_H
#define SENSOR_POWER_H
#include "sensor_commom.h"

typedef struct __power_seq_type_tab {
	const char* seq_name;
	enum sensor_power_seq_type_t seq_type;
} power_seq_type_tab;

typedef struct __vcm_power_seq_dt_vals {
	const char *seq_name;
	uint32_t *seq_vals;
	uint32_t *cfg_vals;
	uint32_t *sensor_indexs;
	uint32_t *seq_delays;
	const char *seq_type_name;
	int seq_size;
} vcm_power_seq_dt_vals;

int ext_hw_vcm_power_on_off(sensor_t *sensor, int on_off);
extern int kernel_sensor_power_config(sensor_t *s_ctrl, struct sensor_power_setting *power_setting, int on_off);
int hw_vcm_get_dt_power_setting_data(struct platform_device *pdev, sensor_t *sensor);
extern int hw_get_power_seq_type_tab(power_seq_type_tab** tab);

#endif /* end of include guard: SENSOR_POWER_H */
