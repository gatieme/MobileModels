/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: als para table sensortek sip1221lr source file
 * Author: huangxinlong <huangxinlong6@h-partners.com>
 * Create: 2024-06-26
 */

#ifndef __ALS_PARA_TABLE_SIP1221LR_H__
#define __ALS_PARA_TABLE_SIP1221LR_H__

#include "als_para_table.h"

sip1221lr_als_para_table *als_get_sip1221lr_table_by_id(uint32_t id);
sip1221lr_als_para_table *als_get_sip1221lr_first_table(void);
uint32_t als_get_sip1221lr_table_count(void);

#endif
