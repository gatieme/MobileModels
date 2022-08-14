/*
 * camkit_check_cable.h
 *
 * Check the camera btb cable status.
 *
 * Copyright (c) 2021-2021 Honor Technologies Co., Ltd.
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
#ifndef _CAMKIT_CHECK_CABLE_H_
#define _CAMKIT_CHECK_CABLE_H_
#include "cam_sensor_dev.h"

void check_camera_btb_gpio_info(struct cam_sensor_ctrl_t *s_ctrl);

#endif