/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2016-2020. All rights reserved.
 * Description: this file is used for huawei events reporting
 * Author: l00368743
 * Create: 2016-10-24
 */

#ifndef __HW_EVENT_H__
#define __HW_EVENT_H__

#include <linux/etherdevice.h>

#ifdef CONFIG_HW_ABS
void cfg80211_drv_ant_grab(struct net_device *dev, gfp_t gfp);
#endif

#endif /* __HW_EVENT_H__ */
