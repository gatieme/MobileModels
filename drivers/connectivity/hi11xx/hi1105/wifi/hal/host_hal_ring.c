/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * 功能说明   : Free/Complete ring基本操作
 * 作者       : wifi
 * 创建日期   : 2018年4月26日
 */

#include "oal_util.h"
#include "oal_net.h"
#include "oal_ext_if.h"
#include "oam_ext_if.h"
#include "host_hal_ext_if.h"
#include "host_hal_ring.h"
#include "securec.h"
#include "host_hal_device.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID     OAM_FILE_ID_HAL_RING_C
#define HAL_WORD_TO_BYTE 4

/*
 * 功能描述   : 初始化ring，设置寄存器的值
 * 1.日    期   : 2018年4月26日
 *   作    者   : wifi
 *   修改内容   : 新生成函数
 */
uint32_t hal_ring_init(hal_host_ring_ctl_stru *ring_ctl)
{
    return OAL_SUCC;
}

/*
 * 功能描述   : 1) free ring,从寄存器中读取read寄存器，并更新SW的read ptr
                2) complete ring,从寄存器中读取write寄存器，并更新SW的write ptr
 * 1.日    期   : 2018年4月26日
 *   作    者   : wifi
 *   修改内容   : 新生成函数
 */
void hal_ring_get_hw2sw(hal_host_ring_ctl_stru *ring_ctl)
{
    uint32_t reginfo;

    /* 入参判断 */
    if (oal_unlikely(ring_ctl == NULL)) {
        oam_error_log0(0, OAM_SF_RX, "{hal_ring_get_hw2sw::ring_ctl NULL}");
        return;
    }

    if (ring_ctl->ring_type == HAL_RING_TYPE_FREE_RING) {
        reginfo = hal_host_readl(ring_ctl->read_ptr_reg);
        if (reginfo != HAL_HOST_READL_INVALID_VAL) {
            ring_ctl->un_read_ptr.read_ptr = (uint16_t)reginfo;
        }
    } else if (ring_ctl->ring_type == HAL_RING_TYPE_COMPLETE_RING) {
        reginfo = hal_host_readl(ring_ctl->write_ptr_reg);
        if (reginfo != HAL_HOST_READL_INVALID_VAL) {
            ring_ctl->un_write_ptr.write_ptr = (uint16_t)reginfo;
        }
    } else {
        return;
    }

    return;
}

/*
 * 功能描述   : 1) free ring,更新SW的write ptr到write寄存器
                2) complete ring,更新SW的read ptr到read寄存器
 * 1.日    期   : 2018年4月26日
 *   作    者   : wifi
 *   修改内容   : 新生成函数
 */
uint32_t hal_ring_set_sw2hw(hal_host_ring_ctl_stru *ring_ctl)
{
    if (ring_ctl == NULL) {
        return OAL_FAIL;
    }

    if (ring_ctl->ring_type == HAL_RING_TYPE_FREE_RING) {
        hal_host_writel(ring_ctl->un_write_ptr.write_ptr, ring_ctl->write_ptr_reg);
    } else if (ring_ctl->ring_type == HAL_RING_TYPE_COMPLETE_RING) {
        hal_host_writel(ring_ctl->un_read_ptr.read_ptr, ring_ctl->read_ptr_reg);
    } else {
        oam_error_log1(0, OAM_SF_RX, "{hal_ring_set_sw2hw::ring_type[%d] err.}", ring_ctl->ring_type);
    }

    return OAL_SUCC;
}

/*
 * 功能描述   : 获取(free)ring上待补充内存的元素个数
 * 1.日    期   : 2018年4月26日
 *   作    者   : wifi
 *   修改内容   : 新生成函数
 */
uint32_t hal_ring_get_entry_count(hal_host_device_stru *hal_dev, hal_host_ring_ctl_stru *ring_ctl, uint16_t *p_count)
{
    uint16_t count = 0;
    uint16_t read_idx;
    uint16_t write_idx;

    if (oal_unlikely(oal_any_null_ptr2(ring_ctl, p_count))) {
        oam_error_log0(0, OAM_SF_RX, "{hal_ring_get_entry_count::input para null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    hal_ring_get_hw2sw(ring_ctl);
    if (ring_ctl->ring_type == HAL_RING_TYPE_FREE_RING) {
        if (hal_ring_is_full(ring_ctl)) {
            *p_count = 0;
            return OAL_SUCC;
        }
        write_idx = ring_ctl->un_write_ptr.st_write_ptr.bit_write_ptr;
        read_idx = ring_ctl->un_read_ptr.st_read_ptr.bit_read_ptr;

        if (hal_ring_wrap_around(ring_ctl)) {
            count = read_idx - write_idx;
        } else {
            count = ring_ctl->entries - write_idx;
            count += read_idx;
        }
    } else if (ring_ctl->ring_type == HAL_RING_TYPE_COMPLETE_RING) {
        if (hal_ring_is_empty(ring_ctl)) {
            *p_count = 0;
            return OAL_SUCC;
        }
        write_idx = ring_ctl->un_write_ptr.st_write_ptr.bit_write_ptr;
        read_idx = ring_ctl->un_read_ptr.st_read_ptr.bit_read_ptr;
        if (!hal_ring_wrap_around(ring_ctl)) {
            count = write_idx - read_idx;
        } else {
            count = ring_ctl->entries - read_idx;
            count += write_idx;
        }
    }

    if (count > ring_ctl->entries) {
        oam_warning_log3(hal_dev->device_id, OAM_SF_RX,
            "{hal_ring_get_entry_count::get error! count[%d]ring_type[%d].entries[%d]}",
            count, ring_ctl->ring_type, ring_ctl->entries);
        oam_warning_log2(hal_dev->device_id, OAM_SF_RX,
            "{hal_ring_get_entry_count::write_ptr[%d]read_ptr[%d].}",
            ring_ctl->un_write_ptr.write_ptr, ring_ctl->un_read_ptr.read_ptr);
        return OAL_FAIL;
    }
    *p_count = count;
    return OAL_SUCC;
}

/*
 * 功能描述   : 按word获取ring内容
 * 1.日    期   : 2019年7月30日
 *   作    者   : wifi
 *   修改内容   : 新生成函数
 */
OAL_STATIC void hal_ring_get_ring(uint8_t *entries, uint8_t *src_addr, uint32_t size)
{
    volatile uint32_t *src_addr_volatile = NULL;
    uint32_t i;

    if ((size % HAL_WORD_TO_BYTE) != 0) {
        oam_error_log1(0, OAM_SF_RX, "{hal_ring_get_ring::size = [%d].}", size);
        return;
    }

    src_addr_volatile = (volatile uint32_t *)src_addr;
    for (i = 0; i < size / HAL_WORD_TO_BYTE; i++) {
        *(uint32_t *)(entries + HAL_WORD_TO_BYTE * i) = *(src_addr_volatile + i);
    }
}

/*
 * 函 数 名   : hal_comp_ring_wait_valid
 * 功能描述   : wait rx complete ring addr valid
 * 1.日    期   : 2021年4月17日
 *   作    者   : wifi
 *   修改内容   : 新生成函数
 */
uint32_t hal_comp_ring_wait_valid(hal_host_device_stru *hal_dev, hal_host_ring_ctl_stru *ring_ctl)
{
#define COMPLETE_RING_WAIT_CNT 1000
    uint16_t rd_idx;
    uint32_t wait_cnt = 0;
    uint8_t *entries = (uint8_t *)(ring_ctl->p_entries);

    rd_idx = ring_ctl->un_read_ptr.st_read_ptr.bit_read_ptr;
    while (oal_unlikely(*(uintptr_t *)(entries + ring_ctl->entry_size * rd_idx)) == 0) {
#ifdef _PRE_EMU
        oal_udelay(300);  /* 延迟 300 微秒  */
#endif
        wait_cnt++;
        if (wait_cnt > COMPLETE_RING_WAIT_CNT) {
            oam_warning_log1(hal_dev->device_id, OAM_SF_RX, "hal_comp_ring_wait_valid:wait_cnt:%d exceeded.", wait_cnt);
            return OAL_FAIL;
        }
    }

    return OAL_SUCC;
}


/*
 * 函 数 名   : hal_ring_entries_get
 * 功能描述   : 获取(complete)ring上待处理的"us_count"个元素，
                把元素的内容copy到"entries"中。
                注:该函数会更新ring_ctl中的read_ptr
 * 1.日    期   : 2018年4月26日
 *   作    者   : wifi
 *   修改内容   : 新生成函数
 */
uint32_t hal_ring_get_entries(hal_host_ring_ctl_stru *ring_ctl,
    uint8_t *entries, uint16_t count)
{
    uint16_t entry_size;
    uint16_t remains;
    uint16_t read_idx;
    uint8_t *src_addr = NULL;
    /* 入参判断 */
    if (oal_unlikely(oal_any_null_ptr2(ring_ctl, entries))) {
        oam_error_log0(0, OAM_SF_RX, "{hal_ring_get_entries::input para null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    if (ring_ctl->ring_type != HAL_RING_TYPE_COMPLETE_RING) {
        oam_error_log0(0, OAM_SF_RX, "{hal_ring_get_entries::not complete ring!.}");
        return OAL_FAIL;
    }

    if (hal_ring_is_empty(ring_ctl)) {
        oam_error_log0(0, OAM_SF_RX, "{hal_ring_get_entries::HAL_RING_IS_EMPTY!}");
        return OAL_FAIL;
    }

    entry_size = ring_ctl->entry_size;

    read_idx = ring_ctl->un_read_ptr.st_read_ptr.bit_read_ptr;
    src_addr = (uint8_t *)(ring_ctl->p_entries) + entry_size * read_idx;
    if (count + read_idx >= ring_ctl->entries) {
        remains = (count + read_idx) % ring_ctl->entries;
        hal_ring_get_ring(entries, src_addr, entry_size * (ring_ctl->entries - read_idx));

        /* 内容读出后，清0 */
        memset_s(src_addr, entry_size * (ring_ctl->entries - read_idx),
            0, entry_size * (ring_ctl->entries - read_idx));
        if (remains != 0) {
            hal_ring_get_ring(entries + entry_size * (ring_ctl->entries - read_idx),
                (uint8_t *)(ring_ctl->p_entries), entry_size * remains);
            /* 内容读出后，清0 */
            memset_s(ring_ctl->p_entries, entry_size * remains, 0, entry_size * remains);
        }
        ring_ctl->un_read_ptr.st_read_ptr.bit_read_ptr = remains;
        ring_ctl->un_read_ptr.st_read_ptr.bit_wrap_flag =
            !ring_ctl->un_read_ptr.st_read_ptr.bit_wrap_flag;
    } else {
        hal_ring_get_ring(entries, src_addr, entry_size * count);
        /* 内容读出后，清0 */
        memset_s(src_addr, entry_size * count, 0, entry_size * count);
        ring_ctl->un_read_ptr.st_read_ptr.bit_read_ptr += count;
    }
    return OAL_SUCC;
}

/*
 * 功能描述   : 设置/补充(free)ring上的元素，
                把entry放在write_ptr指向的位置，然后更新write_ptr(++)。
                注:该函数会更新ring_ctl中的write_ptr
                如果该函数返回失败，调用者负责释放entry内存
 * 1.日    期   : 2018年4月26日
 *   作    者   : wifi
 *   修改内容   : 新生成函数
 */
uint32_t hal_ring_set_entries(hal_host_ring_ctl_stru *ring_ctl, uint64_t entry)
{
    uint16_t write_idx;

    if (oal_any_null_ptr1(ring_ctl) || (!entry)) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    if (ring_ctl->ring_type != HAL_RING_TYPE_FREE_RING) {
        return OAL_FAIL;
    }

    if (hal_ring_is_full(ring_ctl)) {
        return OAL_FAIL;
    }
    write_idx = ring_ctl->un_write_ptr.st_write_ptr.bit_write_ptr;

    *(uintptr_t *)((uint8_t *)(ring_ctl->p_entries) + ring_ctl->entry_size * write_idx) = entry;
    write_idx++;
    if (write_idx >= ring_ctl->entries) {
        /* 已到达ring的最后一个元素，index从0开始计数，并设置flag标志(flag翻转) */
        ring_ctl->un_write_ptr.st_write_ptr.bit_write_ptr = 0;
        ring_ctl->un_write_ptr.st_write_ptr.bit_wrap_flag = !ring_ctl->un_write_ptr.st_write_ptr.bit_wrap_flag;
    } else {
        /* 未到达ring的最后一个元素，index递增，flag标志保存不变 */
        ring_ctl->un_write_ptr.st_write_ptr.bit_write_ptr = write_idx;
    }

    return OAL_SUCC;
}

/*
 * 功能描述   : 更新host free ring 的写指针
 * 1.日    期   : 2019年4月12日
 *   作    者   : wifi
 *   修改内容   : 新生成函数
 */
void hal_update_free_ring_wptr(hal_host_ring_ctl_stru *ring_ctl, uint16_t count)
{
    uint16_t remains;
    uint16_t write_idx;

    if (hal_ring_is_full(ring_ctl)) {
        return;
    }

    write_idx = ring_ctl->un_write_ptr.st_write_ptr.bit_write_ptr;
    if (count + write_idx >= ring_ctl->entries) {
        remains = (count + write_idx) % ring_ctl->entries;
        ring_ctl->un_write_ptr.st_write_ptr.bit_write_ptr = remains;
        ring_ctl->un_write_ptr.st_write_ptr.bit_wrap_flag =
            !ring_ctl->un_write_ptr.st_write_ptr.bit_wrap_flag;
    } else {
        ring_ctl->un_write_ptr.st_write_ptr.bit_write_ptr += count;
    }
    return;
}

void hal_host_ring_tx_deinit(hal_host_device_stru *hal_device)
{
    oal_atomic_set(&hal_device->ba_ring_type, INIT_BA_INFO_RING);
    hal_device->host_ba_info_ring.un_read_ptr.read_ptr = 0;
    hal_device->host_ba_info_ring.un_write_ptr.write_ptr = 0;
}
