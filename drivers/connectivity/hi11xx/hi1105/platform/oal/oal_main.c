/**
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 *
 * Description:Initializing the OAL module
 * Author: @CompanyNameTag
 */

/* 头文件包含 */
#include "oal_main.h"
#include "oal_workqueue.h"
#include "oal_schedule.h"
#include "oal_net.h"
#include "oal_hcc_host_if.h"
#include "oal_kernel_file.h"
#include "securec.h"
#ifdef _PRE_OAL_FEATURE_KEY_PROCESS_TRACE
#include "oal_dft.h"
#endif
#ifdef _PRE_CONFIG_HISI_CONN_SOFTWDFT
#include "oal_softwdt.h"
#endif
#ifdef HISI_CONN_NVE_SUPPORT
#include "hisi_conn_nve.h"
#endif

#define OAL_MAX_TRACE_ENTRY 64

typedef struct {
    oal_spin_lock_stru st_lock;
    unsigned long aul_trace_entries[OAL_MAX_TRACE_ENTRY];
} oal_stacktrace_stru;

/* 全局变量定义 */
/* 动态/静态DBDC，其中一个默认使能 */
uint8_t g_wlan_service_device_per_chip[WLAN_SERVICE_DEVICE_MAX_NUM_PER_CHIP] = { WLAN_INIT_DEVICE_RADIO_CAP };

/* 有些内核版本可能没开启CONFIG_STACKTRACE, 增加CONFIG_STACKTRACE的宏 */
#define oal_dump_stack_str_init()
int32_t oal_dump_stack_str(uint8_t *puc_str, uint32_t ul_max_size)
{
    return 0;
}

/*
 * 函 数 名  : oal_main_init
 * 功能描述  : OAL模块初始化总入口，包含OAL模块内部所有特性的初始化。
 * 返 回 值  : 初始化返回值，成功或失败原因
 */
int32_t ATTR_OAL_NO_FUNC_TRACE oal_main_init(void)
{
    uint32_t ul_rslt;

#ifdef _PRE_CONFIG_CONN_HISI_SYSFS_SUPPORT
    if (oal_conn_sysfs_root_obj_init() == NULL) {
        oal_io_print("hisi root sysfs init failed\n");
    }
#endif

/* 为了解各模块的启动时间，增加时间戳打印 */
#if !defined(CONFIG_HI110X_KERNEL_MODULES_BUILD_SUPPORT) && defined(_PRE_CONFIG_CONN_HISI_SYSFS_SUPPORT)
    /* 110X 驱动build in，内存池初始化上移到内核完成，保证大片内存申请成功 */
#else
    /* 内存池初始化 */
    ul_rslt = oal_mem_init_pool();
    if (ul_rslt != OAL_SUCC) {
        oal_io_print("oal_main_init: oal_mem_init_pool return error code: %d", ul_rslt);
        return -OAL_EFAIL;
    }
#ifdef HISI_CONN_NVE_SUPPORT // 存储NV内容的RAM内存申请
    if (oal_unlikely(hisi_conn_nve_alloc_ramdisk() != OAL_SUCC)) {
        return -OAL_EFAIL;
    }
#endif
#endif

    /* 初始化: 总线上的chip数量增加1 */
    oal_bus_init_chip_num();
    ul_rslt = oal_bus_inc_chip_num();
    if (ul_rslt != OAL_SUCC) {
        oal_io_print("oal_pci_probe: oal_bus_inc_chip_num failed!\n");
        return -OAL_EIO;
    }

    /* 启动成功 */
#if (_PRE_OS_VERSION_WIN32 == _PRE_OS_VERSION)
    memset_s(g_past_net_device, WLAN_NET_DEVICE_MAX_NUM * sizeof(oal_net_device_stru *),
             0, WLAN_NET_DEVICE_MAX_NUM * sizeof(oal_net_device_stru *));
#endif

#ifndef BFGX_UART_DOWNLOAD_SUPPORT
    /* HCC初始化 */
    if (oal_unlikely(hcc_dev_init() != OAL_SUCC)) {
        oal_io_print("[ERROR]hcc_module_init return err null\n");
        return -OAL_EFAIL;
    }

#ifdef _PRE_CONFIG_HISI_CONN_SOFTWDFT
    if (oal_unlikely(oal_softwdt_init() != OAL_SUCC)) {
        oal_io_print("oal_softwdt_init init failed!\n");
        goto oal_softwdt_init_fail;
    }
#endif

#ifdef _PRE_OAL_FEATURE_KEY_PROCESS_TRACE
    if (oal_unlikely(oal_dft_init() != OAL_SUCC)) {
        oal_io_print("oal_dft_init init failed!\n");
        goto oal_dft_init_fail;
    }
#endif
#else
    oal_io_print("gnss only version not support wifi hcc\\n");
#endif

    oal_dump_stack_str_init();

    oal_workqueue_init();
    return OAL_SUCC;

#ifndef BFGX_UART_DOWNLOAD_SUPPORT
#ifdef _PRE_OAL_FEATURE_KEY_PROCESS_TRACE
oal_dft_init_fail:
    oal_softwdt_exit();
#endif

#ifdef _PRE_CONFIG_HISI_CONN_SOFTWDFT
oal_softwdt_init_fail:
    hcc_dev_exit();
#endif
#endif

    return -OAL_EFAIL;
}

/*
 * 函 数 名  : oal_main_exit
 * 功能描述  : OAL模块卸载
 * 返 回 值  : 模块卸载返回值，成功或失败原因
 */
void ATTR_OAL_NO_FUNC_TRACE oal_main_exit(void)
{
#ifdef _PRE_OAL_FEATURE_KEY_PROCESS_TRACE
    oal_dft_exit();
#endif

#ifdef _PRE_CONFIG_HISI_CONN_SOFTWDFT
    oal_softwdt_exit();
#endif

    /* chip num初始化:0 */
    oal_bus_init_chip_num();

#if !defined(CONFIG_HI110X_KERNEL_MODULES_BUILD_SUPPORT) && \
    defined(_PRE_CONFIG_CONN_HISI_SYSFS_SUPPORT)
    /* 110X 驱动build in，内存池初始化上移到内核完成，保证大片内存申请成功 */
#else
    /* 内存池卸载 */
    oal_mem_exit();
#ifdef HISI_CONN_NVE_SUPPORT
    hisi_conn_nve_free_ramdisk();
#endif
#endif

#ifdef _PRE_CONFIG_CONN_HISI_SYSFS_SUPPORT
    oal_conn_sysfs_root_boot_obj_exit();
    oal_conn_sysfs_root_obj_exit();
#endif
    oal_workqueue_exit();
    return;
}

/*
 * 函 数 名  : oal_device_check_enable_num
 * 功能描述  : 检查单chip中mac device使能个数
 * 返 回 值  : 使能device个数
 */
OAL_STATIC uint8_t oal_device_check_enable_num(void)
{
    uint8_t uc_device_num = 0;
    uint8_t uc_device_id;

    for (uc_device_id = 0; uc_device_id < WLAN_SERVICE_DEVICE_MAX_NUM_PER_CHIP; uc_device_id++) {
        if (g_wlan_service_device_per_chip[uc_device_id]) {
            uc_device_num++;
        }
    }
    return uc_device_num;
}

/*
 * 函 数 名  : oal_chip_get_device_num
 * 功能描述  : 根据chip version获取device num
 * 输入参数  : chip version
 */
uint8_t oal_chip_get_device_num(uint32_t ul_chip_ver)
{
    return oal_device_check_enable_num();
}
/*
 * 函 数 名  : oal_board_get_service_vap_start_id
 * 功能描述  : 获取board上的业务vap其实idx
 */
uint8_t oal_board_get_service_vap_start_id(void)
{
    uint8_t uc_device_num_per_chip = oal_device_check_enable_num();

    /* 配置vap个数 = mac device个数,vap idx分配先配置vap,后业务vap */
    return (uint8_t)(WLAN_CHIP_MAX_NUM_PER_BOARD * uc_device_num_per_chip);
}

oal_module_symbol(oal_dump_stack_str);
oal_module_symbol(oal_chip_get_device_num);
oal_module_symbol(oal_board_get_service_vap_start_id);
oal_module_symbol(oal_main_init);
oal_module_symbol(oal_main_exit);
oal_module_symbol(g_wlan_service_device_per_chip);
oal_module_license("GPL");
