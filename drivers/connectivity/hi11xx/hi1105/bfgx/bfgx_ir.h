/**
 * Copyright (c) @CompanyNameMagicTag 2022-2023. All rights reserved.
 *
 * Description: bfgx_ir.c header file
 * Author: @CompanyNameTag
 */

#ifndef BFGX_IR_H
#define BFGX_IR_H
#include "hw_bfg_ps.h"

struct bfgx_subsys_driver_desc *get_ir_default_drv_desc(void);
int32_t hw_ir_ctrl_init(struct platform_device *pdev);
int32_t hw_ir_ctrl_show(char *buf);
int32_t hw_ir_ctrl_set(int32_t power_on);
#endif
