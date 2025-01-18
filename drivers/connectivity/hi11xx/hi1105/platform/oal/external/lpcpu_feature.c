/**
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 *
 * Description:kirin 32k Low power interface
 * Author: @CompanyNameTag
 */

#include <linux/module.h> /* kernel module definitions */
#include <linux/kernel.h>
#include <linux/version.h>
#include <linux/platform_device.h>
#if defined(CONFIG_LPCPU_IDLE_SLEEP)
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 4, 0))
#include <linux/platform_drivers/lpcpu_idle_sleep.h>
#else
#include <linux/hisi/lpcpu_idle_sleep.h>
#endif
#elif defined(CONFIG_HISI_IDLE_SLEEP) // 兼容旧接口
#include <linux/hisi/hisi_idle_sleep.h>
#endif
#include "plat_pm_wlan.h"
#include "oal_types.h"
#include "oal_hcc_bus.h"
#include "plat_debug.h"
#include "lpcpu_feature.h"

int32_t bfgx_ilde_sleep_vote_nolock(uint32_t index, uint32_t val)
{
    static uint32_t bfgx_idle_flag = 0;
    uint32_t mask = (uint32_t)(1 << index);
    uint32_t vote;
    if (val == OAL_TRUE) {
        bfgx_idle_flag |= mask;
    } else  {
        bfgx_idle_flag &= ~mask;
    }
    vote = (bfgx_idle_flag != 0) ? OAL_TRUE : OAL_FALSE;
#if defined(CONFIG_LPCPU_IDLE_SLEEP)
    lpcpu_idle_sleep_vote(ID_GPS, vote);
    ps_print_info("lpcpu_idle_sleep_vote flag 0x%x, last vote %d\n", bfgx_idle_flag, vote);
#elif defined(CONFIG_HISI_IDLE_SLEEP)
    hisi_idle_sleep_vote(ID_GPS, vote);
    ps_print_info("lpcpu_idle_sleep_vote flag 0x%x, last vote %d\n", bfgx_idle_flag, vote);
#endif

    return OAL_SUCC;
}

/*
 * 函 数 名  : wlan_pm_idle_sleep_vote
 * 功能描述  : wlan投票是否允许kirin进入32k idle模式
 * 输入参数  : TRUE:允许，FALSE:不允许
 * 返 回 值  : 初始化返回值，成功或失败原因
 */
void wlan_pm_idle_sleep_vote(uint8_t uc_allow)
{
#if defined(CONFIG_HISI_IDLE_SLEEP)
    if (uc_allow == ALLOW_IDLESLEEP) {
        hisi_idle_sleep_vote(ID_WIFI, 0);
    } else {
        hisi_idle_sleep_vote(ID_WIFI, 1);
    }
#if defined(CONFIG_KIRIN_PCIE_L1SS_IDLE_SLEEP) || defined(CONFIG_PCIE_KPORT_IDLE)
    hcc_bus_wlan_pm_vote(hcc_get_bus(HCC_EP_WIFI_DEV), (uint8_t)uc_allow);
#endif
#elif defined(CONFIG_LPCPU_IDLE_SLEEP)
    if (uc_allow == ALLOW_IDLESLEEP) {
        lpcpu_idle_sleep_vote(ID_WIFI, 0);
    } else {
        lpcpu_idle_sleep_vote(ID_WIFI, 1);
    }
#if defined(CONFIG_KIRIN_PCIE_L1SS_IDLE_SLEEP) || defined(CONFIG_PCIE_KPORT_IDLE)
    hcc_bus_wlan_pm_vote(hcc_get_bus(HCC_EP_WIFI_DEV), (uint8_t)uc_allow);
#endif
#endif
}
