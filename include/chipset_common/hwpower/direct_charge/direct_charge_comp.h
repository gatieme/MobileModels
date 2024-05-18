/*
 * direct_charge_comp.h
 *
 * compensation parameter interface for direct charge
 *
 * Copyright (c) 2020-2020 Honor Device Co., Ltd.
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

#ifndef _DIRECT_CHARGE_COMP_H_
#define _DIRECT_CHARGE_COMP_H_

#include <hwpower/direct_charge/direct_charge_ic_manager.h>

#define DC_VBAT_COMP_PARA_MAX       12
#define DC_IC_NAME_LEN_MAX          32

enum dc_vbat_comp_info {
	DC_IC_ID,
	DC_IC_MODE,
	DC_VBAT_COMP_VALUE,
	DC_VBAT_COMP_TOTAL,
};

struct dc_vbat_comp_para {
	int ic_id;
	int ic_mode;
	int vbat_comp;
};

struct dc_comp_para {
	struct dc_vbat_comp_para vbat_comp_para[DC_VBAT_COMP_PARA_MAX];
	int vbat_comp_group_size;
	int vbat_comp[CHARGE_IC_MAX_NUM];
};

void dc_get_vbat_comp_para(int main_ic_id,
	int aux_ic_id, int ic_mode, struct dc_comp_para *info);
void dc_comp_parse_dts(struct device_node *np, struct dc_comp_para *info);

#endif /* _DIRECT_CHARGE_COMP_H_ */
