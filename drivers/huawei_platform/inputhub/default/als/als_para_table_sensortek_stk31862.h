/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: als para table sensortek stk31862 header file
 * Author: linjianpeng <linjianpeng1@huawei.com>
 * Create: 2020-05-25
 */

#ifndef __ALS_PARA_TABLE_SENSORTEK_STK31862_H__
#define __ALS_PARA_TABLE_SENSORTEK_STK31862_H__

#include "als_para_table.h"

stk31862_als_para_table *als_get_stk31862_table_by_id(uint32_t id);
stk31862_als_para_table *als_get_stk31862_first_table(void);
uint32_t als_get_stk31862_table_count(void);

#endif
