/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: als para table sip1225 source file
 * Author: lisheng
 * Create: 2024-01-19
 */

#include "als_para_table_sip1225.h"

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

static als_para_normal_table sip1225_als_para_diff_tp_color_table[] = {
	{ PSD, V3, VISI_TPLCD, SIP1225_PARA_SIZE,
	  {400, 550, 1000, 2000, 3978, 4326, 4363, 4114, 11000, 5900, 4000, 250, 0, 0, 0, 0}
	},
	{ PSD, V3, BOE_TPLCD_B12, SIP1225_PARA_SIZE,
	  {420, 550, 1000, 2000, 6025, 6503, 6571, 6247, 7988, 4159, 4000, 250, 0, 0, 0, 0}
	},
	{ PSD, V3, CSOT_TPLCD, SIP1225_PARA_SIZE,
	  {410, 620, 1000, 2000, 2200, 2403, 2422, 2296, 18390, 9712, 4000, 250, 0, 0, 0, 0}
	},
	{ PSD, V3, TS_PANEL_UNKNOWN, SIP1225_PARA_SIZE,
	  {420, 550, 1000, 2000, 6330, 7008, 7054, 6712, 7988, 4159, 4000, 250, 0, 0, 0, 0}
	},
};

als_para_normal_table *als_get_sip1225_table_by_id(uint32_t id)
{
	if (id >= ARRAY_SIZE(sip1225_als_para_diff_tp_color_table))
		return NULL;
	return &(sip1225_als_para_diff_tp_color_table[id]);
}

als_para_normal_table *als_get_sip1225_first_table(void)
{
	return &(sip1225_als_para_diff_tp_color_table[0]);
}

uint32_t als_get_sip1225_table_count(void)
{
	return ARRAY_SIZE(sip1225_als_para_diff_tp_color_table);
}
