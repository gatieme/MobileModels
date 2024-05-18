/*
 * Copyright (c) Honor Device Co., Ltd. 2017-2020. All rights reserved.
 * Description: utils of xengine module
 * Author: lianghenghui lianghenghui.
 * Create: 2017-07-24
 */

#ifndef _EMCOM_UTILS_H
#define _EMCOM_UTILS_H
#include <log/hw_log.h>
#include <linux/types.h>

#undef HWLOG_TAG
#define HWLOG_TAG EMCOMK

HILOG_REGIST();

#define EMCOM_DEBUG    1
#define EMCOM_INFO     1

/* network type */
typedef enum {
	NETWORK_TYPE_UNKNOWN = 0,
	NETWORK_TYPE_2G,
	NETWORK_TYPE_3G,
	NETWORK_TYPE_4G,
	NETWORK_TYPE_WIFI,
} NETWORK_TYPE;

typedef enum
{
	MODEM_NOT_SUPPORT_EMCOM,
	MODEM_SUPPORT_EMCOM
} EMCOM_SUPPORT_ENUM;

#define EMCOM_LOGD(fmt, ...) \
	do { \
		if (EMCOM_DEBUG) { \
			hilog_info("%s "fmt"\n", __func__, ##__VA_ARGS__); \
		} \
	} while (0)

#define EMCOM_LOGI(fmt, ...) \
	do { \
		if (EMCOM_INFO) { \
			hilog_info("%s "fmt"\n", __func__, ##__VA_ARGS__); \
		} \
	} while (0)

#define EMCOM_LOGE(fmt, ...) \
	do \
		hilog_err("%s "fmt"\n", __func__, ##__VA_ARGS__); \
	while (0)

bool emcom_is_modem_support(void);

#endif  /* _EMCOM_UTILS_H */
