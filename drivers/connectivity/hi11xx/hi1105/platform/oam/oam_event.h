/**
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 *
 * Description:oam_event.c header file
 * Author: @CompanyNameTag
 */

#ifndef OAM_EVENT_H
#define OAM_EVENT_H

/* 其他头文件包含 */
#include "oal_ext_if.h"
#include "oam_ext_if.h"

/* 宏定义 */
#define OAM_OTA_DATA_TO_STD_MAX_LEN  300
#define OAM_OTA_FRAME_TO_SDT_MAX_LEN 1200
#define OAM_SKB_CB_LEN               oal_netbuf_cb_size()

/* 函数声明 */
extern uint32_t oam_event_init(void);
extern void oam_set_ota_board_type(oam_ota_stru *ota_data);

#endif /* end of oam_event.h */
