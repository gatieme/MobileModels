/*
 * adaptor_test.h
 *
 * adaptor test driver
 *
 * Copyright (c) 2022-2022 Honor Device Co., Ltd.
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

#include <linux/version.h>
#include <hwpower/direct_charge/direct_charge_ic_manager.h>

#ifndef _ADAPTOR_TEST_
#define _ADAPTOR_TEST_

/* adaptor test macro */
#define TMEP_BUF_LENTH              10
#define POSTFIX_LEN                 3
#define INVALID_RET_VAL             (-1)
#define ADAPTOR_TEST_START          1
#define MIN_ADAPTOR_TEST_INS_NUM    0
#define MAX_ADAPTOR_TEST_INS_NUM    5
#define WEAKSOURCE_CNT              10
#define ADAPTOR_STR_LEN             10
#define PWR_INFO_MAX_LEN            128

/*adaptor protocol test*/
enum adaptor_name {
	TYPE_SCP,
	TYPE_FCP,
	TYPE_PD,
	TYPE_SC,
	TYPE_HSC,
	TYPE_OTHER,
};

enum test_state {
	DETECT_FAIL = 0,
	DETECT_SUCC = 1,
	PROTOCOL_FINISH_SUCC = 2,
};

struct adaptor_test_attr{
	enum adaptor_name charger_type;
	char adaptor_str_name[10];
	enum test_state result;
	unsigned int local_mode;
};

void chg_set_adaptor_test_result(enum adaptor_name charger_type,
	enum test_state result, unsigned int local_mode);
int chg_get_adaptor_test_result(char *buf);
void clear_adaptor_test_result(void);
#endif /* _ADAPTOR_TEST_ */
