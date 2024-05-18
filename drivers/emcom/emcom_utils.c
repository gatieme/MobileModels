/*
 * Copyright (c) Honor Device Co., Ltd. 2017-2020. All rights reserved.
 * Description: utils of xengine module
 * Author: lianghenghui lianghenghui.
 * Create: 2017-07-24
 */

#include "emcom_utils.h"
#include <linux/module.h>
#include <linux/types.h>

#undef HWLOG_TAG
#define HWLOG_TAG emcom_utils
HILOG_REGIST();
MODULE_LICENSE("GPL");

EMCOM_SUPPORT_ENUM g_modem_emcom_support = MODEM_NOT_SUPPORT_EMCOM;

void Emcom_Ind_Modem_Support(uint8_t enSupport)
{
	EMCOM_LOGD("g_modem_emcom_support:%d\n", g_modem_emcom_support);
	g_modem_emcom_support = (EMCOM_SUPPORT_ENUM)enSupport;
}

bool emcom_is_modem_support( void )
{
	if(g_modem_emcom_support == MODEM_NOT_SUPPORT_EMCOM)
		return false;
	else
		return true;
}
