 /*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2022. All rights reserved.
 * Description: This Hiview detect probe dmd
 * Author: wangjingjin@huawei.com
 * Create: 2021-08-30
 */


#ifndef _HIVIEW_DETECT_FPC_DMD_H_
#define _HIVIEW_DETECT_FPC_DMD_H_

#include <linux/device.h>
#include "card_tray_gpio_detect.h"

int BtbFpcDetect(struct card_tray_info *di, struct device_node *card_tray_node);

#endif
