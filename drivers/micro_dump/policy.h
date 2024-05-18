/*
 * Copyright (c) Honor Device Co., Ltd. 2022-2022. All rights reserved.
 * Description:define micro dump policy function
 * Author: Lu Laicheng
 * Create: 2022-03-22
 */

#ifndef __MICRO_DUMP_POLICY_H__
#define __MICRO_DUMP_POLICY_H__

#define POLICY_NAME_LEN 16

typedef int (*policy_func) (unsigned long type);

struct struct_policy {
	policy_func func;
	char name[POLICY_NAME_LEN];
};

extern int dabt_policy(unsigned long type);
extern int hung_policy(unsigned long type);
extern int undefinstr_policy(unsigned long type);
extern int subsys_policy(unsigned long type);
extern int assert_policy(unsigned long type);
extern int outmem_policy(unsigned long type);
extern int bus_policy(unsigned long type);
extern int unknow_policy(unsigned long type);
extern policy_func microdump_get_policy (unsigned long error_type);

#endif // __MICRO_DUMP_POLICY_H__