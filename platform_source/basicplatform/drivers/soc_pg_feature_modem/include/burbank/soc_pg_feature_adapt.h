/*
 * parse soc pg feature adapt
 *
 * Copyright (c) Huawei Technologies Co., Ltd. 2023. All rights reserved.
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
#ifndef _SOC_PG_FEATURE_ADAPT_H_
#define _SOC_PG_FEATURE_ADAPT_H_

#include <linux/string.h>

#define EFUSE_SOC_ERROR "efuse_soc_error"


static inline unsigned int is_have_modem(const char *dts_str)
{
	if (strncmp(dts_str, "pad", strlen("pad")) == 0 || 
	    strncmp(dts_str, "sepc_info=1", strlen("sepc_info=1")) == 0)
		return 0;
	return 1;
}

#endif /* _SOC_PG_FEATURE_ADAPT_H_ */
