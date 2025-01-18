/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: als para table sensortek sip1221lr source file
 * Author: huangxinlong <huangxinlong6@h-partners.com>
 * Create: 2024-06-26
 */

#include "als_para_table_sip1221lr.h"

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

sip1221lr_als_para_table sip1221lr_als_para[] = {
	{ BTKR, V3, DEFAULT_TPLCD, BLACK,
	  { 1000, 0, 0, 1000, 0, 0, 1000, 0, 0, 1000, 0, 0,
	    1000, 0, 0, 1000, 0, 0, 7329, 17312, 0, 1477, 0, 1104, 0,
		1008, 5100, 4300, 1000, 5000, 200}
	},
};

sip1221lr_als_para_table *als_get_sip1221lr_table_by_id(uint32_t id)
{
	if (id >= ARRAY_SIZE(sip1221lr_als_para))
		return NULL;
	return &(sip1221lr_als_para[id]);
}

sip1221lr_als_para_table *als_get_sip1221lr_first_table(void)
{
	return &(sip1221lr_als_para[0]);
}

uint32_t als_get_sip1221lr_table_count(void)
{
	return ARRAY_SIZE(sip1221lr_als_para);
}
