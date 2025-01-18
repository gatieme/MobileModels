/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: efuse source file to provide drivers
 * Create: 2023/01/30
 */

#include <linux/arm-smccc.h>       /* arm_smccc_smc */
#include <platform_include/see/efuse_driver.h>
#include "efuse_plat.h"
#include "efuse_call.h"

/*
 * adapt local smc function
 */
uint32_t efuse_smc(struct efuse_call_args *arg)
{
	struct arm_smccc_res res;

	if (!arg) {
		efuse_err("error, arg is null\n");
		return EFUSE_INVALID_PARAM_ERR;
	}

	arm_smccc_smc(arg->arg0, arg->arg1, arg->arg2, arg->arg3,
		      arg->arg4, 0, 0, 0, &res);
	arg->arg1 = res.a1;
	arg->arg2 = res.a2;
	arg->arg3 = res.a3;
	return (uint32_t)res.a0;
}
