/*
 * hw_pmu.c
 *
 * Copyright (c) 2023 Huawei Technologies Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "hw_flash.h"
#include <linux/of_device.h>
#include "securec.h"
#include <platform_include/basicplatform/linux/mfd/pmic_platform.h>
#include <platform_include/basicplatform/linux/spmi_platform.h>

#define CURRENT_MAX 50
#define FLASH_ON 1
#define FLASH_OFF 0
#define MATCH_CUR_WIDE 5

enum hw_pmu_flash_pipe_flag {
	PIPE1_NORMAL = 0,
	PIPE2_NORMAL,
	ALL_PIPE_NORMAL,
};

struct hw_pmu_flash_private_data_t {
	unsigned int status;
	unsigned int pmu_flash_control_address;
	unsigned int dr1_iset_address;
	unsigned int dr2_iset_address;
	unsigned int iset_max_cur;
	unsigned int torch_mmi_cur;
};

static struct hw_pmu_flash_private_data_t g_pmu_flash_pdata;
static struct hw_flash_ctrl_t g_pmu_flash_ctrl;
static const char *g_pmu_flash_tag = "pmu_flash";
static unsigned int pmu_iset_list_num;
static int pmu_iset_list[CURRENT_MAX];
static int pmu_iset_level_list[CURRENT_MAX];
extern struct dsm_client *client_flash;

define_kernel_flash_mutex(pmu_flash);

static void match_current(int cur_flash, int dr[])
{
	int j = 0;
	int i = 0;
	int cur_sum = 0;
	int cur_gap = 2 * pmu_iset_list[pmu_iset_list_num - 1];

	if (cur_flash <= pmu_iset_list[0] * 2) {
		dr[0] = 0;
		dr[1] = 0;
		return;
	}
	if (cur_flash > pmu_iset_list[pmu_iset_list_num - 1] * 2) {
		dr[0] = pmu_iset_list_num - 1;
		dr[1] = pmu_iset_list_num - 1;
		cam_err("%s cur_flash exceeded maximum current", __func__);
		return;
	}
	for (i = 0; i < pmu_iset_list_num; i++) {
		if (pmu_iset_list[i] * 2 > cur_flash)
			break;
		for (j = i; j < pmu_iset_list_num && j < i + MATCH_CUR_WIDE; j++) {
			cur_sum = pmu_iset_list[i] + pmu_iset_list[j];
			if (cur_gap >= abs(cur_sum - cur_flash)) {
				dr[0] = i;
				dr[1] = j;
				cur_gap = abs(cur_sum - cur_flash);
			}
		}
	}

	return;
}

static int hw_pmu_find_match_current(struct hw_flash_ctrl_t *flash_ctrl,
	int cur_flash, int dr[], int pipe_flag)
{
	struct hw_pmu_flash_private_data_t *pdata = NULL;
	int i = 0;

	if (!flash_ctrl || !flash_ctrl->pdata) {
		cam_err("%s flash_ctrl is NULL", __func__);
		return -1;
	}

	if (cur_flash <= 0) {
		cam_err("%s current set is error", __func__);
		return -1;
	}

	pdata = (struct hw_pmu_flash_private_data_t *)flash_ctrl->pdata;

	if (pipe_flag == ALL_PIPE_NORMAL) {
		if (cur_flash > pdata->iset_max_cur * 2)
			cur_flash = pdata->iset_max_cur * 2;

		match_current(cur_flash, &dr[0]);
	} else {
		if (cur_flash > pdata->iset_max_cur)
			cur_flash = pdata->iset_max_cur;

		if (cur_flash <= pmu_iset_list[0]) {
			dr[pipe_flag] = 0;
			return 0;
		}
		for (i = 0; i < pmu_iset_list_num; i++) {
			if (cur_flash <= pmu_iset_list[i]) {
				if (pmu_iset_list[i] - cur_flash <= cur_flash - pmu_iset_list[i - 1]) {
					dr[pipe_flag] = i;
					break;
				} else {
					dr[pipe_flag] = i - 1;
					break;
				}
			}
		}
	}
	return 0;
}

static int hw_pmu_detection(struct hw_flash_ctrl_t *flash_ctrl)
{
	struct hw_pmu_flash_private_data_t *pdata = NULL;
	int dr1_iset_flag;
	int dr2_iset_flag;

	if (!flash_ctrl || !flash_ctrl->pdata) {
		cam_err("%s flash_ctrl is NULL", __func__);
		return -1;
	}

	pdata = (struct hw_pmu_flash_private_data_t *)flash_ctrl->pdata;
	pmic_write_reg(pdata->dr1_iset_address, pmu_iset_level_list[1]);
	pmic_write_reg(pdata->dr2_iset_address, pmu_iset_level_list[1]);
	dr1_iset_flag = pmic_read_reg(pdata->dr1_iset_address);
	dr2_iset_flag = pmic_read_reg(pdata->dr2_iset_address);
	cam_info("%s dr1_iset_flag = 0x%x", __func__, dr1_iset_flag);
	cam_info("%s dr2_iset_flag = 0x%x", __func__, dr2_iset_flag);

	if (!dr1_iset_flag && !dr2_iset_flag)
		return -1;
	else if (dr1_iset_flag && !dr2_iset_flag)
		return PIPE1_NORMAL;
	else if (!dr1_iset_flag && dr2_iset_flag)
		return PIPE2_NORMAL;

	return ALL_PIPE_NORMAL;
}

static int hw_pmu_flash_init(struct hw_flash_ctrl_t *flash_ctrl)
{
	return 0;
}

static int hw_pmu_flash_exit(struct hw_flash_ctrl_t *flash_ctrl)
{
	return 0;
}

static void report_dsm(void)
{
	if (!dsm_client_ocuppy(client_flash)) {
		dsm_client_record(client_flash, "LED open circuit\n");
		dsm_client_notify(client_flash, DSM_FLASH_OPEN_SHOTR_ERROR_NO);
		cam_warn("[I/DSM] %s dsm_client_notify",
			client_flash->client_name);
	}
}

static int hw_pmu_flash_on(struct hw_flash_ctrl_t *flash_ctrl, void *data)
{
	struct hw_flash_cfg_data *cdata = (struct hw_flash_cfg_data *)data;
	struct hw_pmu_flash_private_data_t *pdata = NULL;
	int dr[2] = {0};
	int rc = -1;
	int pipe_flag = -1;
	if (!flash_ctrl || !flash_ctrl->pdata || !cdata) {
		cam_err("%s flash_ctrl or cdata is NULL", __func__);
		return -1;
	}

	cam_info("%s mode=%d, level=%d\n", __func__, cdata->mode, cdata->data);

	mutex_lock(flash_ctrl->hw_flash_mutex);

	pdata = (struct hw_pmu_flash_private_data_t *)flash_ctrl->pdata;

	pipe_flag = hw_pmu_detection(flash_ctrl);
	if (pipe_flag != ALL_PIPE_NORMAL) {
		cam_err("%s pmic read or write fail!", __func__);
		report_dsm();
		if (pipe_flag < 0) {
			mutex_unlock(flash_ctrl->hw_flash_mutex);
			return -1;
		}
	}

	rc = hw_pmu_find_match_current(flash_ctrl, cdata->data, dr, pipe_flag);
	if (rc < 0) {
		cam_err("%s hw_pmu_find_match_current fail!", __func__);
		mutex_unlock(flash_ctrl->hw_flash_mutex);
		return -1;
	}

	if (pipe_flag == ALL_PIPE_NORMAL) {
		pmic_write_reg(pdata->dr1_iset_address, pmu_iset_level_list[dr[0]]);
		pmic_write_reg(pdata->dr2_iset_address, pmu_iset_level_list[dr[1]]);
	} else if (pipe_flag == PIPE1_NORMAL) {
		pmic_write_reg(pdata->dr1_iset_address, pmu_iset_level_list[dr[0]]);
	} else if (pipe_flag == PIPE2_NORMAL) {
		pmic_write_reg(pdata->dr2_iset_address, pmu_iset_level_list[dr[1]]);
	}
	pmic_write_reg(pdata->pmu_flash_control_address, FLASH_ON);
	cam_info("%s dr1_iset_current_value =  %d, level = %x\n",
			__func__, pmu_iset_list[dr[0]], pmu_iset_level_list[dr[0]]);
	cam_info("%s dr2_iset_current_value =  %d, level = %x\n",
			__func__, pmu_iset_list[dr[1]], pmu_iset_level_list[dr[1]]);

	flash_ctrl->state.mode = cdata->mode;
	flash_ctrl->state.data = cdata->data;
	mutex_unlock(flash_ctrl->hw_flash_mutex);
	return rc;
}

static int hw_pmu_flash_off(struct hw_flash_ctrl_t *flash_ctrl)
{
	struct hw_pmu_flash_private_data_t *pdata = NULL;

	if (!flash_ctrl || !flash_ctrl->pdata) {
		cam_err("%s flash_ctrl is NULL", __func__);
		return -1;
	}

	if (flash_ctrl->state.mode == STANDBY_MODE) {
		cam_notice("%s flash led has been powered off", __func__);
		return 0;
	}

	cam_info("%s enter\n", __func__);
	mutex_lock(flash_ctrl->hw_flash_mutex);
	pdata = (struct hw_pmu_flash_private_data_t *)flash_ctrl->pdata;
	flash_ctrl->state.mode = STANDBY_MODE;
	flash_ctrl->state.data = 0;

	pmic_write_reg(pdata->pmu_flash_control_address, FLASH_OFF);
	pmic_write_reg(pdata->dr1_iset_address, pmu_iset_level_list[0]);
	pmic_write_reg(pdata->dr2_iset_address, pmu_iset_level_list[0]);

	mutex_unlock(flash_ctrl->hw_flash_mutex);
	return 0;
}

static int hw_pmu_flash_match(struct hw_flash_ctrl_t *flash_ctrl)
{
	return 0;
}

static int hw_pmu_flash_get_dt_data(struct hw_flash_ctrl_t *flash_ctrl)
{
	struct hw_pmu_flash_private_data_t *pdata = NULL;
	struct device_node *of_node = NULL;
	int rc = -1;
	struct property *prop = NULL;
	int i;

	if (!flash_ctrl || !flash_ctrl->pdata) {
		cam_err("%s flash_ctrl is NULL", __func__);
		return -1;
	}

	pdata = (struct hw_pmu_flash_private_data_t *)flash_ctrl->pdata;
	of_node = flash_ctrl->dev->of_node;

	rc = of_property_read_u32(of_node, "vendor,flash_control_address",
		&pdata->pmu_flash_control_address);
	if (rc < 0) {
		cam_err("%s failed %d\n", __func__, __LINE__);
		return rc;
	}

	rc = of_property_read_u32(of_node, "vendor,dr1_iset_address",
		&pdata->dr1_iset_address);
	if (rc < 0) {
		cam_err("%s failed %d\n", __func__, __LINE__);
		return rc;
	}

	rc = of_property_read_u32(of_node, "vendor,dr2_iset_address",
		&pdata->dr2_iset_address);
	if (rc < 0) {
		cam_err("%s failed %d\n", __func__, __LINE__);
		return rc;
	}

	rc = of_property_read_u32(of_node, "vendor,iset_max_cur",
		&pdata->iset_max_cur);
	if (rc < 0) {
		cam_err("%s failed %d\n", __func__, __LINE__);
		return rc;
	}

	rc = of_property_read_u32(of_node, "vendor,flash-mmi-current",
		&pdata->torch_mmi_cur);
	if (rc < 0) {
		cam_err("%s failed %d\n", __func__, __LINE__);
		return rc;
	}

	prop = of_find_property(of_node, "pmu_iset_list", NULL);
	if (!prop) {
		cam_err("%s failed %d\n", __func__, __LINE__);
		return -1;
	}
	if (!prop->value) {
		cam_err("%s failed %d\n", __func__, __LINE__);
		return -1;
	}
	pmu_iset_list_num = ((unsigned int)prop->length) / sizeof(uint32_t);
	rc = of_property_read_u32_array(of_node, "pmu_iset_list", pmu_iset_list, pmu_iset_list_num);
	if (rc < 0) {
		cam_err("%s failed %d\n", __func__, __LINE__);
		return rc;
	}
	rc = of_property_read_u32_array(of_node, "pmu_iset_level_list", pmu_iset_level_list, pmu_iset_list_num);
	if (rc < 0) {
		cam_err("%s failed %d\n", __func__, __LINE__);
		return rc;
	}

	return rc;
}

static ssize_t hw_pmu_flash_lightness_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	int rc;
	rc = snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE,
		MAX_ATTRIBUTE_BUFFER_SIZE - 1,
		"mode=%d, data=%d.\n",
		g_pmu_flash_ctrl.state.mode, g_pmu_flash_ctrl.state.data);
	if (rc <= 0) {
		cam_err("%s, %d, ::snprintf_s return error %d",
			__func__, __LINE__, rc);
		return -EINVAL;
	}
	rc = strlen(buf) + 1;
	return rc;
}

static int hw_pmu_flash_param_check(char *buf, unsigned long *param,
	int num_of_par)
{
	char *token = NULL;
	int base;
	int cnt;
	token = strsep(&buf, " ");

	for (cnt = 0; cnt < num_of_par; cnt++) {
		if (token) {
			if ((token[1] == 'x') || (token[1] == 'X'))
				base = 16;
			else
				base = 10;
			if (kstrtoul(token, base, &param[cnt]) != 0)
				return -EINVAL;

			token = strsep(&buf, " ");
		} else {
			return -EINVAL;
		}
	}
	return 0;
}

static ssize_t hw_pmu_flash_lightness_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	struct hw_flash_cfg_data cdata = {0};
	unsigned long param[2] = {0};
	int rc = 0;
	int flash_id;
	rc = hw_pmu_flash_param_check((char *)buf, param, 2);
	if (rc < 0) {
		cam_err("%s failed to check param", __func__);
		return rc;
	}

	flash_id = (int)param[0];
	cdata.mode = (int)param[1];
	cam_info("%s flash_id = %d, cdata.mode = %d", __func__, flash_id, cdata.mode);

	if (cdata.mode == STANDBY_MODE) {
		rc = hw_pmu_flash_off(&g_pmu_flash_ctrl);
		if (rc < 0) {
			cam_err("%s pmu_flash flash off error", __func__);
			return rc;
		}
	} else if (cdata.mode == FLASH_MODE || cdata.mode == TORCH_MODE) {
		cdata.data = g_pmu_flash_pdata.torch_mmi_cur;
		rc = hw_pmu_flash_on(&g_pmu_flash_ctrl, &cdata);
		if (rc < 0) {
			cam_err("%s pmu_flash flash on error", __func__);
			return rc;
		}
	} else {
		cam_err("%s pmu_flash wrong mode = %d", __func__, cdata.mode);
		return -1;
	}
	return count;
}

static void hw_pmu_torch_brightness_set(struct led_classdev *cdev,
	enum led_brightness brightness)
{
	struct hw_flash_cfg_data cdata;
	int rc;
	unsigned int led_bright = brightness;

	cam_info("%s brightness= %d", __func__, brightness);
	if (led_bright == STANDBY_MODE) {
		rc = hw_pmu_flash_off(&g_pmu_flash_ctrl);
		if (rc < 0) {
			cam_err("%s pmu_flash off error", __func__);
			return;
		}
	} else {
		cdata.mode = TORCH_MODE;
		cdata.data = g_pmu_flash_pdata.torch_mmi_cur;
		rc = hw_pmu_flash_on(&g_pmu_flash_ctrl, &cdata);
		if (rc < 0) {
			cam_err("%s pmu_flash on error", __func__);
			return;
		}
	}
}

static struct device_attribute g_pmu_flash_lightness =
	__ATTR(flash_lightness, 0660, hw_pmu_flash_lightness_show,
	hw_pmu_flash_lightness_store);

extern int register_camerafs_attr(struct device_attribute *attr);

static int hw_pmu_flash_register_attribute(struct hw_flash_ctrl_t *flash_ctrl,
	struct device *dev)
{
	int rc;
	cam_info("%s enter\n", __func__);
	struct hw_pmu_flash_private_data_t *pdata = NULL;
	if (!flash_ctrl || !dev) {
		cam_err("%s flash_ctrl or dev is NULL", __func__);
		return -1;
	}

	pdata = (struct hw_pmu_flash_private_data_t *)(flash_ctrl->pdata);
	if (!pdata) {
		cam_err("%s pdata is NULL", __func__);
		return -1;
	}

	register_camerafs_attr(&g_pmu_flash_lightness);

	flash_ctrl->cdev_torch.name = "torch";
	flash_ctrl->cdev_torch.brightness_set = hw_pmu_torch_brightness_set;
	rc = led_classdev_register((struct device *)dev,
		&flash_ctrl->cdev_torch);
	if (rc < 0)
		cam_err("%s failed to register torch classdev", __func__);

	return rc;
}

static const struct of_device_id g_pmu_flash_dt_match[] = {
	{ .compatible = "pmu_flash", .data = &g_pmu_flash_ctrl },
	{}
};
MODULE_DEVICE_TABLE(of, pmu_flash_dt_match);

static struct platform_driver g_pmu_flash_platform_driver = {
	.driver = {
		.name = "pmu_flash",
		.owner = THIS_MODULE,
		.of_match_table = g_pmu_flash_dt_match,
	},
};

static int32_t hw_pmu_flash_platform_probe(struct platform_device *pdev)
{
	const struct of_device_id *match = NULL;
	match = of_match_device(g_pmu_flash_dt_match, &pdev->dev);
	if (!match) {
		cam_err("pmu led match device failed");
		return -1;
	}
	cam_debug("%s compatible=%s\n", __func__, match->compatible);
	return hw_flash_platform_probe(pdev, (void *)match->data);
}

static int __init hw_pmu_flash_module_init(void)
{
	int rc;
	cam_debug("%s:%d\n", __func__, __LINE__);

	rc = platform_driver_probe(&g_pmu_flash_platform_driver,
		hw_pmu_flash_platform_probe);
	if (rc < 0)
		cam_notice("%s platform_driver_probe error %d\n", __func__, rc);
	return rc;
}

static void __exit hw_pmu_flash_module_exit(void)
{
	g_pmu_flash_ctrl.func_tbl->flash_exit(&g_pmu_flash_ctrl);
	platform_driver_unregister(&g_pmu_flash_platform_driver);
}

static struct hw_flash_fn_t g_pmu_flash_func_tbl = {
	.flash_config = hw_flash_config,
	.flash_init = hw_pmu_flash_init,
	.flash_exit = hw_pmu_flash_exit,
	.flash_on = hw_pmu_flash_on,
	.flash_off = hw_pmu_flash_off,
	.flash_match = hw_pmu_flash_match,
	.flash_get_dt_data = hw_pmu_flash_get_dt_data,
	.flash_register_attribute = hw_pmu_flash_register_attribute,
};

static struct hw_flash_ctrl_t g_pmu_flash_ctrl = {
	.func_tbl = &g_pmu_flash_func_tbl,
	.hw_flash_mutex = &flash_mut_pmu_flash,
	.pdata = (void *)&g_pmu_flash_pdata,
	.flash_mask_enable = true,
	.state = {
		.mode = STANDBY_MODE,
	},
};

module_init(hw_pmu_flash_module_init);
module_exit(hw_pmu_flash_module_exit);
MODULE_DESCRIPTION("HW_PMU FLASH");
MODULE_LICENSE("GPL v2");
