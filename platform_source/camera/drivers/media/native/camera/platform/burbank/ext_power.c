/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: parse ext power setting of device, provide common power management
 *
 * This file is released under the GPLv2.
 */
#include <linux/delay.h>
#include <linux/printk.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/platform_device.h>

#include "sensor_commom.h"
#include "hw_pmic.h"
#include "../../clt/kernel_clt_flag.h"
#include <i2c_switch_gpio.h>

#include <ext_power.h>

static int hw_vcm_power_up(sensor_t *s_ctrl)
{
	struct sensor_power_setting_array *power_setting_array = NULL;
	struct sensor_power_setting *power_setting = NULL;
	int index = 0;
	int rc = 0;
	struct kernel_pmic_ctrl_t *pmic_ctrl = NULL;

	cam_info("%s enter", __func__);

	if ((s_ctrl->vcm_power_up_setting_array.power_setting == NULL) || (s_ctrl->vcm_power_up_setting_array.size == 0)) {
		cam_err("%s invalid power on setting", __func__);
		return rc;
	}

	power_setting_array = &s_ctrl->vcm_power_up_setting_array;
	if (power_setting_array == NULL) {
		cam_err("%s vcm_power_up_setting_array is null.\n", __func__);
		return -1;
	}

	if (s_ctrl->board_info->i2c_use_gpio_group >= 0) {
		rc = i2c_switch_gpio_pinctrl_set(s_ctrl->board_info->i2c_id[0], s_ctrl->board_info->i2c_use_gpio_group, true);
		if (rc) {
			rc = 0;
			cam_err("%s hw_sensor_pinctrl_set set error", __func__);
		}
	}

	pmic_ctrl = kernel_get_pmic_ctrl();
	if (pmic_ctrl != NULL) {
		cam_info("pmic power on!");
		pmic_ctrl->func_tbl->pmic_on(pmic_ctrl, 0);
	} else {
		cam_info("%s pimc ctrl is null", __func__);
	}

	for (index = 0; index < power_setting_array->size; index++) {
		power_setting = &power_setting_array->power_setting[index];
		rc = kernel_sensor_power_config(s_ctrl, power_setting, POWER_ON);
		if (rc) {
			cam_err("%s power up procedure error", __func__);
			break;
		}
	}
	return rc;
}

static int hw_vcm_power_down(sensor_t *s_ctrl)
{
	struct sensor_power_setting_array *power_setting_array = NULL;
	struct sensor_power_setting *power_setting = NULL;
	unsigned int index = 0;
	int rc = 0;
	struct kernel_pmic_ctrl_t *pmic_ctrl = NULL;

	cam_info("%s enter", __func__);

	if ((s_ctrl->vcm_power_down_setting_array.power_setting == NULL) || (s_ctrl->vcm_power_down_setting_array.size == 0)) {
		cam_err("%s invalid power down setting", __func__);
		return rc;
	}

	power_setting_array = &s_ctrl->vcm_power_down_setting_array;
	if (power_setting_array == NULL) {
		cam_err("%s power_setting_array is null", __func__);
		return -1;
	}

	for (index = 0; index < power_setting_array->size; index++) {
		power_setting = &power_setting_array->power_setting[index];
		rc = kernel_sensor_power_config(s_ctrl, power_setting, POWER_OFF);
	}

	pmic_ctrl = kernel_get_pmic_ctrl();
	if (pmic_ctrl != NULL)
		pmic_ctrl->func_tbl->pmic_off(pmic_ctrl);

	if (s_ctrl->board_info->i2c_use_gpio_group >= 0) {
		rc = i2c_switch_gpio_pinctrl_set(s_ctrl->board_info->i2c_id[0], s_ctrl->board_info->i2c_use_gpio_group, false);
		if (rc) {
			rc = 0;
			cam_err("%s hw_sensor_pinctrl_set set error", __func__);
		}
	}
	return rc;
}

int ext_hw_vcm_power_on_off(sensor_t *s_ctrl, int on_off)
{
	int rc = 0;
	cam_info("%s enter", __func__);

	if (s_ctrl == NULL) {
		cam_err("%s s_ctrl is null.\n", __func__);
		return -1;
	}

	if (kernel_is_clt_flag() || hw_is_fpga_board()) {
		cam_info("%s just return", __func__);
		return 0;
	}

	if (on_off) {
		rc = hw_vcm_power_up(s_ctrl);
		if (rc)
			cam_err("%s [%d]: vcm power up fail", __func__, __LINE__);
	} else {
		rc = hw_vcm_power_down(s_ctrl);
		if (rc)
			cam_err("%s [%d]: vcm power down fail", __func__, __LINE__);
	}

	return rc;
}

static int vcm_malloc_dt_string_vals(vcm_power_seq_dt_vals *dt_vals, int count)
{
	dt_vals->seq_vals = kzalloc(sizeof(uint32_t) * count, GFP_KERNEL);
	if (!dt_vals->seq_vals) {
		cam_err("%s:%d failed\n", __func__, __LINE__);
		return -ENOMEM;
	}

	dt_vals->cfg_vals = kzalloc(sizeof(uint32_t) * count, GFP_KERNEL);
	if (!dt_vals->cfg_vals) {
		cam_err("%s:%d failed\n", __func__, __LINE__);
		return -ENOMEM;
	}

	dt_vals->sensor_indexs = kzalloc(sizeof(uint32_t) * count, GFP_KERNEL);
	if (!dt_vals->sensor_indexs) {
		cam_err("%s failed %d", __func__, __LINE__);
		return -ENOMEM;
	}

	dt_vals->seq_delays = kzalloc(sizeof(uint32_t) * count, GFP_KERNEL);
	if (!dt_vals->seq_delays) {
		cam_err("%s failed %d", __func__, __LINE__);
		return -ENOMEM;
	}

	return 0;
}

static void vcm_free_dt_string_vals(vcm_power_seq_dt_vals *dt_vals)
{
	if (dt_vals->seq_vals != NULL) {
		kfree(dt_vals->seq_vals);
		dt_vals->seq_vals = NULL;
	}
	if (dt_vals->cfg_vals != NULL) {
		kfree(dt_vals->cfg_vals);
		dt_vals->cfg_vals = NULL;
	}
	if (dt_vals->sensor_indexs != NULL) {
		kfree(dt_vals->sensor_indexs);
		dt_vals->sensor_indexs = NULL;
	}
	if (dt_vals->seq_delays != NULL) {
		kfree(dt_vals->seq_delays);
		dt_vals->seq_delays = NULL;
	}
}

static int hw_vcm_get_dt_power_string_vals(struct device_node *dev_node,
	vcm_power_seq_dt_vals *dt_vals, int is_power_on, int* count)
{
	int rc = 0;
	const char *seq_val_name = NULL;
	const char *seq_cfg_name = NULL;
	const char *seq_sensor_index_name = NULL;
	const char *seq_delay_name = NULL;

	dt_vals->seq_type_name = (is_power_on ? "vendor,vcm-power-seq-type" : "vendor,vcm-power-down-seq-type");
	*count = of_property_count_strings(dev_node, dt_vals->seq_type_name);
	if (*count <= 0) {
		cam_err("%s:%d seq_type_name:%s count:%d vcm power not config", __func__, __LINE__, dt_vals->seq_type_name, *count);
		return -EINVAL;
	}

	rc = vcm_malloc_dt_string_vals(dt_vals, *count);
	if (rc) {
		cam_err("%s:%d maclloc fail", __func__, __LINE__);
		return rc;
	}

	seq_val_name = (is_power_on ? "vendor,vcm-power-seq-val" : "vendor,vcm-power-down-seq-val");
	rc = of_property_read_u32_array(dev_node, seq_val_name, dt_vals->seq_vals, *count);
	if (rc < 0)
		cam_err("%s:%d seq val not to config", __func__, __LINE__);

	seq_cfg_name = (is_power_on ? "vendor,vcm-power-seq-cfg-val" : "vendor,vcm-power-down-seq-cfg-val");
	rc = of_property_read_u32_array(dev_node, seq_cfg_name, dt_vals->cfg_vals, *count);
	if (rc < 0)
		cam_err("%s:%d seq val not to config", __func__, __LINE__);

	seq_sensor_index_name = (is_power_on ? "vendor,vcm-power-seq-sensor-index" : "vendor,vcm-power-down-seq-sensor-index");
	rc = of_property_read_u32_array(dev_node, seq_sensor_index_name, dt_vals->sensor_indexs, *count);
	if (rc < 0)
		cam_err("%s:%d sensor index not to config", __func__, __LINE__);

	seq_delay_name = (is_power_on ? "vendor,vcm-power-seq-delay" : "vendor,vcm-power-down-seq-delay");
	rc = of_property_read_u32_array(dev_node, seq_delay_name, dt_vals->seq_delays, *count);
	if (rc < 0)
		cam_err("%s:%d seq delay not to config", __func__, __LINE__);

	return 0;
}

static int vcm_power_setting_init(struct device_node *dev_node, vcm_power_seq_dt_vals *dt_vals,
	struct sensor_power_setting *power_settings, int count)
{
	int rc = 0;
	int i = 0;
	int j = 0;
	int seq_size = 0;
	power_seq_type_tab* seq_type_tab = NULL;
	for (i = 0; i < count; i++) {
		rc = of_property_read_string_index(dev_node, dt_vals->seq_type_name, i, &dt_vals->seq_name);
		if (rc < 0) {
			cam_err("%s failed %d\n", __func__, __LINE__);
			return -EINVAL;
		}

		seq_size = hw_get_power_seq_type_tab(&seq_type_tab);
		for (j = 0; j < seq_size; j++) {
			if (!strcmp(dt_vals->seq_name, seq_type_tab[j].seq_name)) {
				power_settings[i].seq_type = seq_type_tab[j].seq_type;
				break;
			}
		}
		cam_err("%s seq_size %d\n", __func__, seq_size);
		if (j >= seq_size) {
			cam_warn("%s: unrecognized seq-type\n", __func__);
			return -EINVAL;
		}

		power_settings[i].seq_val = dt_vals->seq_vals[i];
		power_settings[i].config_val = dt_vals->cfg_vals[i];
		power_settings[i].sensor_index = ((dt_vals->sensor_indexs[i]>=0xFF) ? 0xFFFFFFFF : dt_vals->sensor_indexs[i]);
		power_settings[i].delay = dt_vals->seq_delays[i];
		cam_info("%s:%d index[%d] seq_name[%s] seq_type[%d] cfg_vals[%d] seq_delay[%d] sensor_index[0x%x]",
			__func__, __LINE__, i, dt_vals->seq_name, power_settings[i].seq_type, dt_vals->cfg_vals[i],
			dt_vals->seq_delays[i], dt_vals->sensor_indexs[i]);
		cam_info("%s:%d sensor_index = %d", __func__, __LINE__, power_settings[i].sensor_index);
	}
	return rc;
}

static int hw_vcm_get_dt_power_setting(struct device_node *dev_node,
	struct sensor_power_setting_array *vcm_power_setting_array, int is_power_on)
{
	int rc = 0;
	int count = 0;
	vcm_power_seq_dt_vals dt_vals = {0};
	struct sensor_power_setting *power_settings = NULL;

	cam_info("%s:%d is_power_on = %d", __func__, __LINE__, is_power_on);

	rc = hw_vcm_get_dt_power_string_vals(dev_node, &dt_vals, is_power_on, &count);
	if (rc) {
		cam_err("%s vcm get dt power string %d\n", __func__, __LINE__);
		goto out;
	}

	power_settings = kzalloc(sizeof(struct sensor_power_setting) * count, GFP_KERNEL);
	if (NULL == power_settings) {
		cam_err("%s failed %d\n", __func__, __LINE__);
		rc = -ENOMEM;
		goto out;
	}

	rc = vcm_power_setting_init(dev_node, &dt_vals, power_settings, count);
	if (rc) {
		rc = -EINVAL;
		goto out;
	}
	vcm_power_setting_array->power_setting = power_settings;
	vcm_power_setting_array->size = count;

out:
	vcm_free_dt_string_vals(&dt_vals);
	return rc;
}

int hw_vcm_get_dt_power_setting_data(struct platform_device *pdev, sensor_t *sensor)
{
	int rc = 0;
	struct device_node *dev_node = NULL;

	if (pdev == NULL|| pdev->dev.of_node == NULL|| sensor == NULL) {
		cam_err("%s dev_node is NULL", __func__);
		return -EINVAL;
	}

	dev_node = pdev->dev.of_node;
	rc = hw_vcm_get_dt_power_setting(dev_node, &sensor->vcm_power_up_setting_array, 1);
	if (rc < 0) {
		cam_warn("%s:%d get dt power on setting fail, it's not mandatory to config", __func__, __LINE__);
		return 0;
	}
	rc = hw_vcm_get_dt_power_setting(dev_node, &sensor->vcm_power_down_setting_array, 0); // 0 is power down
	if (rc < 0) {
		cam_warn("%s:%d get dt power down setting fail, it's not mandatory to config", __func__, __LINE__);
		return 0;
	}
	return 0;
}