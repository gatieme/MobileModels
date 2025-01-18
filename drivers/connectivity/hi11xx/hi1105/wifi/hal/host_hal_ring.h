/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * 功能说明   : Free/Complete ring基本操作
 * 作者       : wifi
 * 创建日期   : 2018年4月26日
 */

#ifndef HOST_HAL_RING_H
#define HOST_HAL_RING_H


#include "oal_types.h"
#include "host_hal_device.h"

/* 判断ring是否为满，如果满，返回TRUE;反之，返回FALSE */
static inline bool hal_ring_is_full(hal_host_ring_ctl_stru *ring_ctl)
{
    return (((ring_ctl)->un_write_ptr.st_write_ptr.bit_write_ptr == \
        (ring_ctl)->un_read_ptr.st_read_ptr.bit_read_ptr) && \
        ((ring_ctl)->un_write_ptr.st_write_ptr.bit_wrap_flag != (ring_ctl)->un_read_ptr.st_read_ptr.bit_wrap_flag));
}

/* 判断ring是否为空，如果空，返回TRUE;反之，返回FALSE */
static inline bool hal_ring_is_empty(hal_host_ring_ctl_stru *ring_ctl)
{
    return ((ring_ctl)->un_write_ptr.write_ptr == (ring_ctl)->un_read_ptr.read_ptr);
}

/* 判断ring是否翻转，如果翻转，返回TRUE;反之，返回FALSE */
static inline bool hal_ring_wrap_around(hal_host_ring_ctl_stru *ring_ctl)
{
    return ((ring_ctl)->un_read_ptr.st_read_ptr.bit_wrap_flag != (ring_ctl)->un_write_ptr.st_write_ptr.bit_wrap_flag);
}

static inline oal_bool_enum_uint8 hmac_tid_is_host_ring_tx(hmac_tid_info_stru *tid_info)
{
    uint8_t ring_tx_mode = (uint8_t)oal_atomic_read(&tid_info->ring_tx_mode);

    return ring_tx_mode == HOST_RING_TX_MODE || ring_tx_mode == H2D_SWITCHING_MODE;
}


typedef enum {
    HAL_RING_TYPE_INVALID,
    /* Free ring: 软件操作write ptr, HW操作read ptr */
    HAL_RING_TYPE_FREE_RING,
    /* Complete ring: 软件操作read ptr, HW操作write ptr */
    HAL_RING_TYPE_COMPLETE_RING,

    HAL_RING_TYPE_BUTT
} hal_ring_type_enum;

uint32_t hal_ring_init(hal_host_ring_ctl_stru *ring_ctl);
void hal_ring_get_hw2sw(hal_host_ring_ctl_stru *ring_ctl);
uint32_t hal_ring_set_sw2hw(hal_host_ring_ctl_stru *ring_ctl);
uint32_t hal_ring_get_entry_count(hal_host_device_stru *hal_dev, hal_host_ring_ctl_stru *ring_ctl, uint16_t *p_count);
uint32_t hal_comp_ring_wait_valid(hal_host_device_stru *hal_dev, hal_host_ring_ctl_stru *ring_ctl);
uint32_t hal_ring_get_entries(hal_host_ring_ctl_stru *ring_ctl, uint8_t *entries, uint16_t count);
uint32_t hal_ring_set_entries(hal_host_ring_ctl_stru *ring_ctl, uint64_t entry);
void hmac_update_free_ring_wptr(hal_host_ring_ctl_stru *ring_ctl, uint16_t count);
void hal_host_ring_tx_deinit(hal_host_device_stru *hal_device);

#endif /* HAL_RING_H */
