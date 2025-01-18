/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: als para table sensortek stk31862 source file
 * Author: linjianpeng <linjianpeng1@huawei.com>
 * Create: 2020-05-25
 */

#include "als_para_table_sensortek_stk31862.h"

#include <linux/err.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/of_gpio.h>
#include <linux/slab.h>
#include <linux/types.h>

#include <securec.h>

#include "als_tp_color.h"
#include "contexthub_boot.h"
#include "contexthub_route.h"

stk31862_als_para_table stk31862_als_para[] = {
	{ BTKR, V3, DEFAULT_TPLCD, BLACK,
	  { 1000, 1000, 1000, 10000, 30, 8500, 30, 4700, 30, 33, 630, 5000,
	    10, 1800, 5000, 200}
	},
};

stk31862_als_para_table *als_get_stk31862_table_by_id(uint32_t id)
{
	if (id >= ARRAY_SIZE(stk31862_als_para))
		return NULL;
	return &(stk31862_als_para[id]);
}

stk31862_als_para_table *als_get_stk31862_first_table(void)
{
	return &(stk31862_als_para[0]);
}

uint32_t als_get_stk31862_table_count(void)
{
	return ARRAY_SIZE(stk31862_als_para);
}
