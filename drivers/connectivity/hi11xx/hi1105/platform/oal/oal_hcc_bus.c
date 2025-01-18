/**
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 *
 * Description:hcc bus, adaptation SDIO/PCIE/USB etc
 * Author: @CompanyNameTag
 */

#define HISI_LOG_TAG               "[HCC_BUS]"
#define MPXX_LOG_MODULE_NAME     "[HCC_BUS]"
#define MPXX_LOG_MODULE_NAME_VAR hcc_bus_loglevel
#define HI_BUS_EXCPLOCK_TIMEOUT (60 * 1000)
/* 头文件包含 */
#include "oal_hcc_bus.h"
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
#include "board.h"
#include "oal_hcc_bus_exception.h"
#endif
#include "oal_dft.h"
#include "oal_sdio_host_if.h"
#include "oal_usb_host_if.h"
#include "pcie_linux.h"
#include "oal_hcc_host_if.h"
#include "oam_ext_if.h"
#include "plat_pm_wlan.h"
#include "plat_firmware.h"
#include "plat_parse_changid.h"
#include "securec.h"
#if (defined(CONFIG_LOG_EXCEPTION) || defined(CONFIG_LOG_USERTYPE)) && \
    !defined(CONFIG_HI110X_KERNEL_MODULES_BUILD_SUPPORT)
#include <log/log_usertype.h>
#endif
#include "securec.h"
#ifndef WIN32
#include "plat_pm.h"
#include "plat_exception_rst.h"
#endif
#include "external/lpcpu_feature.h"
#ifdef _PRE_PLAT_FEATURE_MULTI_HCC
#ifdef CONFIG_PCI
#include "pcie_host.h"
#endif
#endif

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_OAL_HCC_BUS_C

/* 全局变量定义 */
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
static int32_t hcc_bus_pm_state_switch_event(struct notifier_block *unused,
                                             unsigned long wifi_state, void *ptr);
OAL_STATIC oal_dlist_create_head(g_hcc_bus_res_hdr);
OAL_STATIC oal_define_spinlock(g_hcc_bus_res_lock);
OAL_STATIC oal_dlist_create_head(g_hcc_bus_switch_hdr);

static struct notifier_block g_hcc_bus_pm_notifier = {
    .notifier_call = hcc_bus_pm_state_switch_event,
};

/*
 * Set Format, split with ",", like below
 * "sdio,pcie,switchon" -- board support sdio & pcie, enable dynamic switch
 * "sdio,pcie,switchoff"
 * "pcie,sdio"          -- board support pcie & sdio, default we use pcie
 * "sdio"               -- only support sdio
 * "pcie"               -- only support pcie
 */
OAL_STATIC char *g_hisi_wifi_bus_select = "";
uint32_t g_hcc_exception_enable = 1;
oal_debug_module_param(g_hcc_exception_enable, uint, S_IRUGO | S_IWUSR);
OAL_STATIC uint32_t g_hcc_bus_auto_bindcpu = 0;
OAL_STATIC uint32_t g_hcc_bus_manual_bindcpu = 1;

/* pps 按照大包计算 */
OAL_STATIC uint32_t g_hcc_bus_auto_bindcpu_limit = OAL_BUS_BINDCPU_LIMIT;
OAL_STATIC uint32_t g_hcc_bus_current_pps = 0x0;
OAL_STATIC uint32_t g_hcc_bus_wakelock_debug = 0x0;
OAL_STATIC char g_str_ini_hcc_bus_switch[OAL_BUS_INI_STR_LEN] = {0};
#else
oal_dlist_head_stru g_hcc_bus_res_hdr;
oal_spin_lock_stru g_hcc_bus_res_lock;
oal_dlist_head_stru g_hcc_bus_switch_hdr;
char *g_hisi_wifi_bus_select = "";
uint32_t g_hcc_exception_enable = 1;
char g_str_ini_hcc_bus_switch[OAL_BUS_INI_STR_LEN];
uint32_t g_hcc_bus_auto_bindcpu = 0;
uint32_t g_hcc_bus_manual_bindcpu = 1;
uint32_t g_hcc_bus_current_pps = 0x0;
uint32_t g_hcc_bus_wakelock_debug = 0x0;
#endif

uint32_t g_hcc_tx_err_cnt = 0;

/* 函数声明 */
OAL_STATIC int32_t oal_register_gpio_intr(hcc_bus_dev *pst_bus_dev);
OAL_STATIC void oal_unregister_gpio_intr(hcc_bus_dev *pst_bus_dev);
OAL_STATIC void hcc_bus_sched_gpio_task(hcc_bus *pst_bus, int32_t irq);
OAL_STATIC void hcc_dev_pps_count_timeout(oal_timeout_func_para_t arg);
OAL_STATIC int32_t hcc_bus_auto_bindcpu_is_support(uint32_t dev_id);
OAL_STATIC int32_t hcc_bus_auto_sched_is_support(uint32_t dev_id);
OAL_STATIC int32_t hcc_bus_resource_alloc(hcc_bus *pst_bus);
OAL_STATIC void hcc_bus_resource_free(hcc_bus *pst_bus);
OAL_STATIC int32_t hcc_set_pcie_switch_flag(int32_t flag);

OAL_STATIC hcc_bus_dev_res g_bus_devs;

#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
/* 根据以下结构体来枚举 IP设备 */
OAL_STATIC hcc_bus_dev g_bus_dev_res[] = {
    {
        .dev_id = HCC_EP_WIFI_DEV,
        .init_bus_type = HCC_BUS_SDIO,
        .is_wakeup_gpio_support = 1,
#if defined(_PRE_PLAT_FEATURE_HI110X_PCIE)
        .bus_cap = (HCC_BUS_SDIO_CAP) | (HCC_BUS_PCIE_CAP),
#else
        .bus_cap = (HCC_BUS_SDIO_CAP),
#endif
        .name = "hi110x_dev",
        .en_flowctrl_gpio_registered = OAL_FALSE,
    },
};
#else
OAL_STATIC hcc_bus_dev g_bus_dev_res[OAL_BUS_DEV_RES_SIZE];
#endif

OAL_STATIC uint32_t g_hcc_bus_shutdown_flag = OAL_FALSE;
OAL_STATIC uint32_t g_bus_dump_mem_flag = 0;
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
oal_atomic g_wakeup_dev_wait_ack;
oal_atomic g_bus_powerup_dev_wait_ack; /* ip 上电握手标记 */
#endif

/* -1 means did't bind cpus */
OAL_STATIC int32_t g_cpu_id = -1;

#ifdef WIN32
char *g_hcc_bus_type_str[HCC_BUS_BUTT] = {
    "sdio",
    "pcie",
#ifdef _PRE_PLAT_FEATURE_USB
    "usb"
#endif
};
#else
OAL_STATIC char *g_hcc_bus_type_str[HCC_BUS_BUTT] = {
    [HCC_BUS_SDIO] = "sdio",
    [HCC_BUS_PCIE] = "pcie",
#ifdef _PRE_PLAT_FEATURE_USB
    [HCC_BUS_USB] = "usb"
#endif
};
#endif

int32_t hcc_bus_get_shutdown_flag(void)
{
    return g_hcc_bus_shutdown_flag;
}

void hcc_bus_set_shutdown_flag(uint32_t flag)
{
    g_hcc_bus_shutdown_flag = flag;
}

OAL_STATIC char *hcc_bus_get_bus_type_str(uint32_t bus_type)
{
    if (oal_unlikely(bus_type >= HCC_BUS_BUTT)) {
        return "unkown";
    }

    return g_hcc_bus_type_str[bus_type] ? g_hcc_bus_type_str[bus_type] : "uninit";
}

OAL_STATIC void hcc_bus_stop_auto_pps_task(hcc_bus_dev *pst_bus_dev)
{
    /* cancel the timer */
    oal_timer_delete_sync(&pst_bus_dev->bus_pps_timer);
    pst_bus_dev->hcc->hcc_transer_info.tx_assem_info.pkt_cnt = 0;
    pst_bus_dev->hcc->hcc_transer_info.rx_assem_info.pkt_cnt = 0;
    hcc_dev_bindcpu(pst_bus_dev->dev_id, 0);
}

OAL_STATIC void hcc_bus_start_auto_pps_task(hcc_bus_dev *pst_bus_dev)
{
    /* start the timer */
    pst_bus_dev->bus_pps_start_time = OAL_TIME_JIFFY;
    oal_timer_start(&pst_bus_dev->bus_pps_timer, HCC_BUS_PPS_COUNT_TIMEOUT);
}

#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
OAL_STATIC int32_t hcc_bus_pm_state_switch_event(struct notifier_block *unused, unsigned long wifi_state, void *ptr)
{
    hcc_bus *pst_bus = (hcc_bus*)ptr;
    hcc_bus_dev *pst_bus_dev = NULL;

    pst_bus_dev = pst_bus == NULL ? NULL : pst_bus->bus_dev;
    if (pst_bus_dev == NULL) {
        oal_print_mpxx_log(MPXX_LOG_WARN, "mpxx dev is null");
        return -OAL_ENODEV;
    }
    if (!hcc_bus_auto_sched_is_support(pst_bus_dev->dev_id)) {
        return OAL_SUCC;
    }
    if (wifi_state == WIFI_PM_WAKEUP_EVENT) {
        oal_print_mpxx_log(MPXX_LOG_INFO, "mpxx dev wakeup");
        hcc_bus_start_auto_pps_task(pst_bus_dev);
    } else if (wifi_state == WIFI_PM_SLEEP_EVENT) {
        oal_print_mpxx_log(MPXX_LOG_INFO, "mpxx dev sleep");
        hcc_bus_stop_auto_pps_task(pst_bus_dev);
    } else if (wifi_state == WIFI_PM_POWERDOWN_EVENT) {
        oal_print_mpxx_log(MPXX_LOG_INFO, "mpxx dev powerdown");
        hcc_bus_stop_auto_pps_task(pst_bus_dev);
    } else if (wifi_state == WIFI_PM_POWERUP_EVENT) {
        oal_print_mpxx_log(MPXX_LOG_INFO, "mpxx dev powerup");
        hcc_bus_start_auto_pps_task(pst_bus_dev);
    }
    return 0;
}
#endif

int32_t hcc_switch_action_register(hcc_switch_action *action, void *data)
{
    if (oal_unlikely(action == NULL)) {
        oal_warn_on(1);
        return OAL_FAIL;
    }
    action->data = data;
    oal_dlist_add_tail(&action->list, &g_hcc_bus_switch_hdr);

    return OAL_SUCC;
}

void hcc_switch_action_unregister(hcc_switch_action *action)
{
    if (oal_unlikely(action == NULL)) {
        oal_warn_on(1);
        return;
    }
    oal_dlist_delete_entry(&action->list);
}

OAL_STATIC int32_t bus_chan_init_string_cmp(const char *start, int len, const char *pc_para)
{
    if ((len == OAL_STRLEN(pc_para)) && (!oal_memcmp(start, pc_para, len))) {
        return OAL_SUCC;
    }
    return OAL_FAIL;
}

OAL_STATIC uint32_t hcc_bus_chan_set(hcc_bus_dev *pst_bus_dev, const char *start, uint32_t len)
{
    if (len == 0) {
        return HCC_BUS_BUTT;
    }

    if (bus_chan_init_string_cmp(start, len, "sdio") == OAL_SUCC) {
        pst_bus_dev->bus_cap |= HCC_BUS_SDIO_CAP;
        oal_print_mpxx_log(MPXX_LOG_INFO, "hisi wifi support sdio");
        return HCC_BUS_SDIO;
    }

    if (bus_chan_init_string_cmp(start, len, "pcie") == OAL_SUCC) {
        pst_bus_dev->bus_cap |= HCC_BUS_PCIE_CAP;
        oal_print_mpxx_log(MPXX_LOG_INFO, "hisi wifi support pcie");
        return HCC_BUS_PCIE;
    }

#ifdef _PRE_PLAT_FEATURE_USB
    if (bus_chan_init_string_cmp(start, len, "usb") == OAL_SUCC) {
        pst_bus_dev->bus_cap |= HCC_BUS_USB_CAP;
        oal_print_mpxx_log(MPXX_LOG_INFO, "hisi wifi support usb");
        return HCC_BUS_USB;
    }
#endif
    /* wlan channel support pcie switch to sdio, used to pice hardwhare bugfix */
    /* current only used for vogue */
    if (bus_chan_init_string_cmp(start, len, "pcie_switch_enable") == OAL_SUCC) {
        if (pst_bus_dev->bus_cap & HCC_BUS_PCIE_CAP) {
            pst_bus_dev->bus_cap |= HCC_BUS_SDIO_CAP;
            hcc_set_pcie_switch_flag(1);
            oal_print_mpxx_log(MPXX_LOG_INFO, "hisi wifi bus support pcie switch");
        }
        return HCC_BUS_BUTT;
    }

    if (bus_chan_init_string_cmp(start, len, "auto_bindcpu") == OAL_SUCC) {
        pst_bus_dev->bus_auto_bindcpu = 1;
        oal_print_mpxx_log(MPXX_LOG_INFO, "hisi hcc bus auto bindcpu enable");
        return HCC_BUS_BUTT;
    }

    return HCC_BUS_BUTT;
}

OAL_STATIC void hcc_bus_chan_init_from_string(hcc_bus_dev *pst_bus_dev, const char *bus_select)
{
    int len;
    const char *start = NULL;
    const char *end = NULL;

    uint32_t init_bus_type = HCC_BUS_BUTT;
    uint32_t tmp_bus_type;

    if (OAL_STRLEN(g_str_ini_hcc_bus_switch) != 0) {
        start = g_str_ini_hcc_bus_switch;
        oal_print_mpxx_log(MPXX_LOG_INFO, "get ini string from module para [%s]", g_str_ini_hcc_bus_switch);
    } else {
        start = bus_select;
    }

    pst_bus_dev->bus_cap = 0;
    for (end = start;;) {
        // search to separative sign
        if ((*end != ',') && (*end != '\0')) {
            end++;
            continue;
        }

        len = end - start;

        tmp_bus_type = hcc_bus_chan_set(pst_bus_dev, start, len);
        // select the first found bus type
        if ((tmp_bus_type != HCC_BUS_BUTT) && (init_bus_type == HCC_BUS_BUTT)) {
            init_bus_type = tmp_bus_type;
            pst_bus_dev->init_bus_type = init_bus_type;
            oal_print_mpxx_log(MPXX_LOG_INFO, "hisi wifi hcc bus type set to %s",
                               (init_bus_type == HCC_BUS_SDIO) ? "sdio" : "pcie");
        }

        if (*end == '\0') {
            break;
        }

        start = end + 1;
        end++;
    }
}

int32_t hcc_bus_cap_init(uint32_t dev_id, const char *bus_select)
{
    hcc_bus_dev *pst_bus_dev;

    pst_bus_dev = hcc_get_bus_dev(dev_id);
    if (pst_bus_dev == NULL) {
        return -OAL_ENODEV;
    }

    if (g_hisi_wifi_bus_select != NULL && OAL_STRLEN(g_hisi_wifi_bus_select) != 0) {
        hcc_bus_chan_init_from_string(pst_bus_dev, g_hisi_wifi_bus_select);
        return OAL_SUCC;
    }

    if (bus_select != NULL && OAL_STRLEN(bus_select) != 0) {
        hcc_bus_chan_init_from_string(pst_bus_dev, bus_select);
        return OAL_SUCC;
    }

#ifdef _PRE_PRODUCT_HI1620S_KUNPENG
    /* default use pcie */
    hcc_bus_chan_init_from_string(pst_bus_dev, "pcie");
#else
    /* default use sdio */
    hcc_bus_chan_init_from_string(pst_bus_dev, "sdio");
#endif

    return OAL_SUCC;
}

/* This interface is not good, remove later */
hcc_bus *hcc_get_current_mpxx_bus(void)
{
#ifdef _PRE_PLAT_FEATURE_MULTI_HCC
    hcc_bus_dev *pst_bus_dev = hcc_get_get_one_alive_bus_dev();
#else
    hcc_bus_dev *pst_bus_dev = hcc_get_bus_dev(HCC_EP_WIFI_DEV);
#endif
    if (pst_bus_dev == NULL) {
        return NULL;
    }

    return pst_bus_dev->cur_bus;
}

hcc_bus *hcc_get_bus(uint32_t bus_dev)
{
    hcc_bus_dev *pst_bus_dev = hcc_get_bus_dev(bus_dev);

    if (pst_bus_dev == NULL) {
        return NULL;
    }

    return pst_bus_dev->cur_bus;
}

#ifndef _PRE_PLAT_FEATURE_MULTI_HCC
OAL_STATIC int32_t hcc_bus_check_dev_id(uint32_t dev_id)
{
    if (oal_warn_on(dev_id == 0xFFFFFFFF)) {
        return -OAL_ENODEV;
    }

    if (oal_warn_on(dev_id >= (uint32_t)oal_array_size(g_bus_dev_res))) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "invalid dev id :%d", dev_id);
        return -OAL_EINVAL;
    }

    return OAL_SUCC;
}
#endif
OAL_STATIC int32_t hcc_bus_is_match(hcc_bus *pst_new, hcc_bus *pst_old)
{
    if (pst_new->bus_type != pst_old->bus_type) {
        return OAL_FALSE;
    }

    if (pst_new->bus_id != pst_old->bus_id) {
        return OAL_FALSE;
    }

    return OAL_TRUE;
}

#ifdef _PRE_PLAT_FEATURE_MULTI_HCC
hcc_bus_dev *hcc_get_bus_dev(uint32_t dev_id)
{
    int32_t i;
    hcc_bus_dev *pst_bus_dev = NULL;

    if (oal_warn_on(dev_id >= HCC_CHIP_MAX_DEV)) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "invalid dev id :%d", dev_id);
        return NULL;
    }

    for (i = 0; i < g_bus_devs.dev_num; i++) {
        pst_bus_dev = &g_bus_devs.dev_list[i];
        if (dev_id == pst_bus_dev->dev_id) {
            return pst_bus_dev;
        }
    }
    return NULL;
}

hcc_bus_dev *hcc_get_get_one_alive_bus_dev(void)
{
    hcc_bus_dev *main_bus_dev = hcc_get_bus_dev(hcc_get_main_dev());
#ifdef CONFIG_PCI
    if (main_bus_dev->bus_cap == HCC_BUS_PCIE_CAP) {
        return oal_pcie_get_one_alive_bus_dev();
    }
#endif
    return main_bus_dev;
}
#else
hcc_bus_dev *hcc_get_bus_dev(uint32_t dev_id)
{
    int32_t i;
    hcc_bus_dev *pst_bus_dev = NULL;

    if (hcc_bus_check_dev_id(dev_id) != OAL_SUCC) {
        return NULL;
    }

    for (i = 0; i < (int32_t)oal_array_size(g_bus_dev_res); i++) {
        pst_bus_dev = &g_bus_dev_res[i];
        if (dev_id == pst_bus_dev->dev_id) {
            return pst_bus_dev;
        }
    }
    return NULL;
}
#endif

int32_t hcc_get_main_dev(void)
{
    return g_bus_devs.main_dev;
}

OAL_STATIC int32_t hcc_foreach_switch_actions(uint32_t dev_id, hcc_bus *old_bus, hcc_bus *new_bus)
{
    int32_t ret = OAL_SUCC;
    oal_dlist_head_stru *pst_entry = NULL;
    hcc_switch_action *pst_action = NULL;

    oal_dlist_search_for_each(pst_entry, &g_hcc_bus_switch_hdr)
    {
        pst_action = oal_dlist_get_entry(pst_entry, hcc_switch_action, list);
        if (pst_action->switch_notify != NULL) {
            ret = pst_action->switch_notify(dev_id, old_bus, new_bus, pst_action->data);
            if (ret != OAL_SUCC) {
                oal_print_mpxx_log(MPXX_LOG_ERR, "hcc switch action probe failed,name:%s, ret=%d,func:%p",
                                   pst_action->name ? pst_action->name : "unkown", ret, pst_action->switch_notify);
                return ret;
            }
        }
    }

    return ret;
}

hcc_bus *hcc_find_bus_by_devid(uint32_t dev_id, uint32_t bus_type)
{
    oal_uint irqsave;
    oal_dlist_head_stru *pst_entry = NULL;
    hcc_bus *pst_bus_tmp = NULL;

    hcc_bus_dev *pst_bus_dev = hcc_get_bus_dev(dev_id);
    if (pst_bus_dev == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dev_id %u invalid", dev_id);
        return NULL;
    }

    oal_spin_lock_irq_save(&g_hcc_bus_res_lock, &irqsave);
    oal_dlist_search_for_each(pst_entry, &g_hcc_bus_res_hdr)
    {
        pst_bus_tmp = oal_dlist_get_entry(pst_entry, hcc_bus, list);
        /* found the bus */
        if (pst_bus_tmp->bus_type == bus_type) {
            oal_spin_unlock_irq_restore(&g_hcc_bus_res_lock, &irqsave);
            return pst_bus_tmp;
        }
    }
    oal_spin_unlock_irq_restore(&g_hcc_bus_res_lock, &irqsave);

    return NULL;
}

OAL_STATIC int32_t hcc_select_bus(uint32_t dev_id, uint32_t bus_type)
{
    oal_uint irqsave;
    oal_dlist_head_stru *pst_entry = NULL;
    hcc_bus *pst_bus_tmp = NULL;

    hcc_bus_dev *pst_bus_dev = hcc_get_bus_dev(dev_id);
    if (pst_bus_dev == NULL) {
        return -OAL_EINVAL;
    }

    oal_spin_lock_irq_save(&g_hcc_bus_res_lock, &irqsave);
    oal_dlist_search_for_each(pst_entry, &g_hcc_bus_res_hdr)
    {
        pst_bus_tmp = oal_dlist_get_entry(pst_entry, hcc_bus, list);
        if (pst_bus_tmp->bus_dev == pst_bus_dev) {
            if (pst_bus_tmp->bus_type == bus_type) {
                /* match */
                pst_bus_dev->cur_bus = pst_bus_tmp;
                oal_spin_unlock_irq_restore(&g_hcc_bus_res_lock, &irqsave);
                return OAL_SUCC;
            }
        }
    }
    oal_spin_unlock_irq_restore(&g_hcc_bus_res_lock, &irqsave);

    return -OAL_ENODEV;
}

/* switch bus from sdio to pcie or pcie to sdio */
int32_t hcc_switch_bus(uint32_t dev_id, uint32_t bus_type)
{
    int32_t ret;
    hcc_bus *old_bus = NULL;
    hcc_bus_dev *pst_bus_dev = hcc_get_bus_dev(dev_id);
    /* 暂时只允许在关机状态切换 */
    if (oal_warn_on(dev_id != HCC_EP_WIFI_DEV)) {
        return -OAL_EINVAL;
    }

    if (pst_bus_dev == NULL) {
        return -OAL_EINVAL;
    }

    if (oal_warn_on(pst_bus_dev->cur_bus == NULL)) {
        return -OAL_ENODEV;
    }

    oal_wake_lock(&pst_bus_dev->st_switch_wakelock);

    old_bus = pst_bus_dev->cur_bus;

    ret = hcc_select_bus(dev_id, bus_type);
    if (ret == OAL_SUCC) {
        /* call switch bus actions after bus changed */
        ret = hcc_foreach_switch_actions(dev_id, old_bus, pst_bus_dev->cur_bus);
    }

    oal_wake_unlock(&pst_bus_dev->st_switch_wakelock);
    hcc_sched_transfer(pst_bus_dev->hcc);
    return ret;
}

int32_t hcc_bus_isvalid(hcc_bus *pst_bus)
{
    if (pst_bus == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "bus is null");
        return -OAL_EINVAL;
    }

    if (pst_bus->bus_dev == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "bus %d 's bus dev is null", pst_bus->bus_id);
        return -OAL_ENODEV;
    }

    return OAL_SUCC;
}

/* enable to clear xfer_pending_sig, enable L1
 * disable to set xfer_pending_sig, disable L1 */
OAL_STATIC int32_t hcc_bus_ip_pm_ctrl(hcc_bus *pst_bus, uint32_t enable)
{
    int32_t ret;
    int32_t cmd_len;
    oal_netbuf_stru *pst_netbuf = NULL;
    struct hcc_transfer_param st_hcc_transfer_param = { 0 };
    struct hcc_handler *hcc = NULL;

    if (pst_bus->bus_dev == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "hcc_bus_ip_pm_ctrl bus_dev is null");
        return -OAL_ENODEV;
    }

    hcc = pst_bus->bus_dev->hcc;
    if (hcc == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "hcc_bus_ip_pm_ctrl hcc is null");
        return -OAL_ENODEV;
    }

    cmd_len = (int32_t)sizeof(enable);

    pst_netbuf = hcc_netbuf_alloc(cmd_len);
    if (pst_netbuf == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "hcc_bus_ip_pm_ctrl alloc skb fail, cmd_len=%d", cmd_len);
        return -OAL_ENOMEM;
    }

    oal_netbuf_put(pst_netbuf, cmd_len);

    ret = memcpy_s((void *)oal_netbuf_data(pst_netbuf), cmd_len, &enable, sizeof(enable));
    if (ret != EOK) {
        oal_netbuf_free(pst_netbuf);
        oal_print_mpxx_log(MPXX_LOG_ERR, "memcpy_s error, destlen=%d, srclen=%u\n ",
            cmd_len, (uint32_t)sizeof(enable));
        return -OAL_EFAIL;
    }

    /* 高优先级发送 */
    hcc_hdr_param_init(&st_hcc_transfer_param, HCC_ACTION_TYPE_BUS,
                       HCC_SUB_BUS_IP_PM, 0, HCC_FC_NONE, DATA_HI_QUEUE);  // DATA_HI_QUEUE

    ret = hcc_tx(hcc, pst_netbuf, &st_hcc_transfer_param);
    if (ret != OAL_SUCC) {
        oal_netbuf_free(pst_netbuf);
        oal_print_mpxx_log(MPXX_LOG_ERR, "hcc_bus_ip_pm_ctrl send failed, ret=%d", ret);
    } else {
        oal_print_mpxx_log(MPXX_LOG_INFO, "hcc_bus_ip_pm_ctrl enable =%u", enable);
    }

    return ret;
}

int32_t mpxx_hcc_ip_pm_ctrl(uint32_t enable, uint8_t dev_id)
{
    hcc_bus *pst_bus = hcc_get_bus(dev_id);
    if (pst_bus == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "current bus is null");
        return -OAL_ENODEV;
    }
    return hcc_bus_ip_pm_ctrl(pst_bus, enable);
}
oal_module_symbol(mpxx_hcc_ip_pm_ctrl);

OAL_STATIC int32_t hcc_bus_auto_bindcpu_is_support(uint32_t dev_id)
{
    hcc_bus_dev *pst_bus_dev = hcc_get_bus_dev(dev_id);
    if (oal_unlikely(pst_bus_dev == NULL)) {
        return 0;
    }

    if (g_hcc_bus_auto_bindcpu) {
        return 1;
    }

    return pst_bus_dev->bus_auto_bindcpu;
}

int32_t hcc_is_sdio(void)
{
#if defined(_PRE_PLAT_FEATURE_HI110X_PCIE) || defined(_PRE_PLAT_FEATURE_MULTI_HCC)
    hcc_bus *pst_bus = hcc_get_bus(HCC_EP_WIFI_DEV);
    if ((pst_bus != NULL) && (pst_bus->bus_type == HCC_BUS_SDIO)) {
        return OAL_TRUE;
    }
#endif
    return OAL_FALSE;
}
EXPORT_SYMBOL_GPL(hcc_is_sdio);

int32_t hcc_is_pcie(void)
{
#if defined(_PRE_PLAT_FEATURE_HI110X_PCIE) || defined(_PRE_PLAT_FEATURE_MULTI_HCC)
    hcc_bus *pst_bus = hcc_get_bus(HCC_EP_WIFI_DEV);
    if ((pst_bus != NULL) && (pst_bus->bus_type == HCC_BUS_PCIE)) {
        return OAL_TRUE;
    }
#endif
    return OAL_FALSE;
}
EXPORT_SYMBOL_GPL(hcc_is_pcie);

OAL_STATIC int32_t hcc_bus_auto_sched_is_support(uint32_t dev_id)
{
    if (!hcc_bus_auto_bindcpu_is_support(dev_id)) {
        return 0;
    }

    return 1;
}

int32_t hcc_bind_thread(uint8_t is_bind, uint8_t thread_bind, uint8_t irq_bind, uint32_t dev_id)
{
    hcc_bus *pst_bus = NULL;
    hcc_bus_dev *pst_bus_dev = hcc_get_bus_dev(dev_id);
    oal_pcie_bindcpu_cfg bindcpu_cfg;

    if (oal_unlikely(pst_bus_dev == NULL)) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "non-support switch dev id:%u", dev_id);
        return -OAL_EINVAL;
    }

    if (hcc_bus_auto_bindcpu_is_support(dev_id) != 0) {
        /* 自动绑核打开直接返回 */
        return OAL_SUCC;
    }

    if (g_hcc_bus_manual_bindcpu == 0) {
        /* forbid manual control */
        return OAL_SUCC;
    }

    pst_bus = pst_bus_dev->cur_bus;

    bindcpu_cfg.is_bind = is_bind;
    bindcpu_cfg.irq_cpu = irq_bind;
    bindcpu_cfg.thread_cmd = thread_bind;
    bindcpu_cfg.is_userctl = 0;

    return hcc_bus_bindcpu(pst_bus, HCC_DIR_COUNT, *(int32_t *)&bindcpu_cfg);
}
EXPORT_SYMBOL_GPL(hcc_bind_thread);

int32_t mpxx_bind_hcc_thread(uint8_t is_bind, uint8_t thread_bind, uint8_t irq_bind)
{
    return hcc_bind_thread(is_bind, thread_bind, irq_bind, HCC_EP_WIFI_DEV);
}
EXPORT_SYMBOL_GPL(mpxx_bind_hcc_thread);

int32_t hcc_dev_bindcpu(uint32_t dev_id, int32_t is_bind)
{
    hcc_bus *pst_bus = NULL;
    hcc_bus_dev *pst_bus_dev = hcc_get_bus_dev(dev_id);

    if (oal_unlikely(pst_bus_dev == NULL)) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "non-support switch dev id:%u", dev_id);
        return -OAL_EINVAL;
    }

    pst_bus = pst_bus_dev->cur_bus;
    if (hcc_bus_auto_bindcpu_is_support(dev_id)) {
        return hcc_bus_bindcpu(pst_bus, HCC_DIR_COUNT, is_bind);
    }
    return -OAL_EIO;
}
EXPORT_SYMBOL_GPL(hcc_dev_bindcpu);

/* bus性能调度 */
void hcc_bus_performance_core_schedule(uint32_t dev_id)
{
    uint32_t run_time;
    unsigned long current_time, pkt_pps_rx, pkt_pps_tx, pkt_pps_total;
    unsigned long tx_cnt, rx_cnt, total_cnt;
    hcc_bus_dev *pst_bus_dev = hcc_get_bus_dev(dev_id);

    if (oal_unlikely(pst_bus_dev == NULL)) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "non-support switch dev id:%u", dev_id);
        return;
    }

    if (!hcc_bus_auto_sched_is_support(dev_id)) {
        oal_print_mpxx_log(MPXX_LOG_VERBOSE, "hcc bus auto sched disabled");
        return;
    }

    current_time = OAL_TIME_JIFFY;

    if (oal_time_after(current_time, (pst_bus_dev->bus_pps_start_time + 1 * HZ))) {
        /* time is up, calc pps */
        tx_cnt = pst_bus_dev->hcc->hcc_transer_info.tx_assem_info.pkt_cnt;
        rx_cnt = pst_bus_dev->hcc->hcc_transer_info.rx_assem_info.pkt_cnt;
        total_cnt = tx_cnt + rx_cnt;

        run_time = oal_jiffies_to_msecs(current_time)
                   - oal_jiffies_to_msecs(pst_bus_dev->bus_pps_start_time);
        if (run_time == 0) {
            run_time = 1; /* 1 msec at least */
        }

        /* 计算发送pps,1000ms */
        pkt_pps_tx = (tx_cnt * 1000) / (unsigned long)run_time;
        /* 计算接收pps,1000ms */
        pkt_pps_rx = (rx_cnt * 1000) / (unsigned long)run_time;

        pkt_pps_total = pkt_pps_tx + pkt_pps_rx;

        g_hcc_bus_current_pps = pkt_pps_total;

        if (hcc_bus_auto_bindcpu_is_support(dev_id)) {
            hcc_bus *pst_bus = pst_bus_dev->cur_bus;
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
            if (pkt_pps_total >= g_hcc_bus_auto_bindcpu_limit) {
                hcc_bus_bindcpu(pst_bus, HCC_DIR_COUNT, 1);
            } else if (pkt_pps_total <= g_hcc_bus_auto_bindcpu_limit / 2) { /* limit除以2为不绑定的切换门限 */
                hcc_bus_bindcpu(pst_bus, HCC_DIR_COUNT, 0);
            }
#endif
        }

        oal_print_mpxx_log(MPXX_LOG_DBG, "tx: %lu, rx: %lu, runtime:%u", pkt_pps_tx, pkt_pps_rx, run_time);

        pst_bus_dev->hcc->hcc_transer_info.tx_assem_info.pkt_cnt = 0;
        pst_bus_dev->hcc->hcc_transer_info.rx_assem_info.pkt_cnt = 0;
        pst_bus_dev->bus_pps_start_time = current_time;
    }

    return;
}
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
OAL_STATIC void hcc_bus_performance_core_init(uint32_t dev_id)
{
    hcc_bus_dev *pst_bus_dev = hcc_get_bus_dev(dev_id);

    if (oal_unlikely(pst_bus_dev == NULL)) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "non-support switch dev id:%u", dev_id);
        return;
    }

    pst_bus_dev->bus_pps_start_time = OAL_TIME_JIFFY;
    pst_bus_dev->hcc->hcc_transer_info.tx_assem_info.pkt_cnt = 0;
    pst_bus_dev->hcc->hcc_transer_info.rx_assem_info.pkt_cnt = 0;
    oal_timer_init(&pst_bus_dev->bus_pps_timer, HCC_BUS_PPS_COUNT_TIMEOUT,
                   hcc_dev_pps_count_timeout, (uintptr_t)pst_bus_dev);

    return;
}
#endif
OAL_STATIC void hcc_bus_performance_core_exit(uint32_t dev_id)
{
    hcc_bus_dev *pst_bus_dev = hcc_get_bus_dev(dev_id);

    if (oal_unlikely(pst_bus_dev == NULL)) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "non-support switch dev id:%u", dev_id);
        return;
    }

    oal_timer_delete_sync(&pst_bus_dev->bus_pps_timer);
    return;
}

/* after all bus inited */
OAL_STATIC int32_t hcc_probe_bus(hcc_bus *pst_bus)
{
    hcc_bus_dev *pst_bus_dev = NULL;

    if (oal_warn_on(pst_bus->bus_dev != NULL)) {
        oal_print_mpxx_log(MPXX_LOG_INFO, "%s had probed", pst_bus->name);
        return OAL_SUCC;
    }

    pst_bus_dev = hcc_get_bus_dev(pst_bus->dev_id);
    if (pst_bus_dev == NULL) {
        return -OAL_EINVAL;
    }

    oal_print_mpxx_log(MPXX_LOG_INFO, "bus_type:%s, cap:%u, dev_name:%s",
                       hcc_bus_get_bus_type_str(pst_bus->bus_type), pst_bus_dev->bus_cap, pst_bus_dev->name);

    if ((1 << pst_bus->bus_type) & pst_bus_dev->bus_cap) {
        pst_bus->bus_dev = pst_bus_dev;
        pst_bus_dev->bus_num++;
        return OAL_SUCC;
    }

    return -OAL_ENODEV;
}

/*
 * Prototype    : hcc_message_register
 * Description  : used for sdio messsage callback, 1 bit to 1 msg event
 * Input        : struct hcc_handler *hcc
 */
int32_t hcc_message_register(struct hcc_handler *hcc, uint8_t msg, hcc_msg_rx cb, void *data)
{
    int32_t flag = 0;
    int32_t ret = OAL_SUCC;
    oal_uint irqsave;
    oal_dlist_head_stru *pst_entry = NULL;
    hcc_bus *pst_bus_tmp = NULL;

    if (oal_unlikely(hcc == NULL)) {
        oal_warn_on(1);
        return OAL_FAIL;
    }

    oal_spin_lock_irq_save(&g_hcc_bus_res_lock, &irqsave);
    oal_dlist_search_for_each(pst_entry, &g_hcc_bus_res_hdr)
    {
        pst_bus_tmp = oal_dlist_get_entry(pst_entry, hcc_bus, list);
        if (pst_bus_tmp->bus_dev == hcc->bus_dev) {
            /* 注册在当前设备上的所有BUS 都需要注册 */
            ret = hcc_bus_message_register(pst_bus_tmp, msg, cb, data);
            if (ret != OAL_SUCC) {
                oal_spin_unlock_irq_restore(&g_hcc_bus_res_lock, &irqsave);
                oal_print_mpxx_log(MPXX_LOG_ERR, "register bus %d failed, ret=%d", pst_bus_tmp->bus_id, ret);
                return ret;
            }
            flag++;
        }
    }
    oal_spin_unlock_irq_restore(&g_hcc_bus_res_lock, &irqsave);

    if (flag) {
        return OAL_SUCC;
    }
    return -OAL_ENODEV;
}

void hcc_message_unregister(struct hcc_handler *hcc, uint8_t msg)
{
    oal_uint irqsave;
    oal_dlist_head_stru *pst_entry = NULL;
    hcc_bus *pst_bus_tmp = NULL;

    if (oal_unlikely(hcc == NULL)) {
        oal_warn_on(1);
        return;
    }

    oal_spin_lock_irq_save(&g_hcc_bus_res_lock, &irqsave);
    oal_dlist_search_for_each(pst_entry, &g_hcc_bus_res_hdr)
    {
        pst_bus_tmp = oal_dlist_get_entry(pst_entry, hcc_bus, list);
        if (pst_bus_tmp->bus_dev == hcc->bus_dev) {
            /* 注册在当前设备上的所有BUS 都需要注册 */
            hcc_bus_message_unregister(pst_bus_tmp, msg);
        }
    }
    oal_spin_unlock_irq_restore(&g_hcc_bus_res_lock, &irqsave);
}

hcc_bus *hcc_alloc_bus(void)
{
    hcc_bus *pst_bus = NULL;

    pst_bus = oal_memalloc(sizeof(hcc_bus));
    if (pst_bus == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "alloc hcc bus failed, size:%u", (uint32_t)sizeof(hcc_bus));
        return NULL;
    }

    memset_s((void *)pst_bus, sizeof(hcc_bus), 0, sizeof(hcc_bus));

    pst_bus->dev_id = 0xFFFFFFFF;

    /* 设置4字节对齐 */
    pst_bus->cap.align_size[HCC_TX] = (uint32_t)sizeof(uint32_t);
    pst_bus->cap.align_size[HCC_RX] = (uint32_t)sizeof(uint32_t);

    pst_bus->cap.is_full_duplex = 0;

    pst_bus->cap.max_trans_size = 0x7fffffff;
    return pst_bus;
}

void hcc_free_bus(hcc_bus *pst_bus)
{
    if (oal_likely(pst_bus != NULL)) {
        oal_free(pst_bus);
    }
}

int32_t hcc_send_message(struct hcc_handler *hcc, uint32_t val)
{
    int32_t ret = OAL_SUCC;
    hcc_bus *hi_bus = NULL;

    if (oal_unlikely(hcc == NULL)) {
        return -OAL_ENODEV;
    }

    hi_bus = hcc_to_bus(hcc);

    hcc_tx_transfer_lock(hcc);
    if (hcc_bus_pm_wakeup_device(hi_bus) == OAL_SUCC) {
        ret = hcc_bus_send_message(hi_bus, val);
    } else {
        hcc_tx_transfer_unlock(hcc);
        return -OAL_EFAIL;
    }
    hcc_tx_transfer_unlock(hcc);

    return ret;
}

OAL_STATIC void hcc_dev_res_exit_by_id(int32_t dev_max)
{
    int32_t i;
    hcc_bus_dev *pst_bus_dev = NULL;
    dev_max = oal_min(dev_max, (int32_t)oal_array_size(g_bus_dev_res));
    for (i = 0; i < dev_max; i++) {
        pst_bus_dev = &g_bus_dev_res[i];
        oal_wake_lock_exit(&pst_bus_dev->st_switch_wakelock);
        if (pst_bus_dev->is_wakeup_gpio_support) {
            oal_unregister_gpio_intr(pst_bus_dev);
        }

        /* HCC支持GPIO流控 */
        if (pst_bus_dev->en_flowctrl_gpio_registered) {
            /* 注销GPIO流控 */
            oal_unregister_gpio_flowctrl_intr(pst_bus_dev);
        }
    }
}

#ifdef _PRE_PLAT_FEATURE_MULTI_HCC
OAL_STATIC void hcc_dev_res_exit(void)
{
    hcc_dev_res_exit_by_id(g_bus_devs.dev_num);
}
#else
OAL_STATIC void hcc_dev_res_exit(void)
{
    hcc_dev_res_exit_by_id((int32_t)oal_array_size(g_bus_dev_res));
}
#endif


OAL_STATIC int32_t hcc_dev_res_init(hcc_bus_dev *dev_res, int32_t dev_num)
{
    int32_t i, ret;
    hcc_bus_dev *pst_bus_dev = NULL;
    for (i = 0; i < dev_num; i++) {
        pst_bus_dev = &dev_res[i];
        oal_wake_lock_init(&pst_bus_dev->st_switch_wakelock, "bus_dev_wakelock");
        if (pst_bus_dev->is_wakeup_gpio_support) {
            ret = oal_register_gpio_intr(pst_bus_dev);
            if (ret) {
                goto failed_reg_gpio_int;
            }
        }
    }

    return OAL_SUCC;
failed_reg_gpio_int:
    hcc_dev_res_exit_by_id(i);
    return ret;
}
#ifdef _PRE_PLAT_FEATURE_MULTI_HCC
OAL_STATIC int32_t hcc_dev_res_init_gfxx(void)
{
    return hcc_dev_res_init(g_bus_devs.dev_list, g_bus_devs.dev_num);
}
#else
OAL_STATIC int32_t hcc_dev_res_init_mpxx(void)
{
    return hcc_dev_res_init(g_bus_dev_res, oal_array_size(g_bus_dev_res));
}
#endif
int32_t hcc_add_bus(hcc_bus *pst_bus, const char *bus_name)
{
    int32_t ret;
    int32_t init_flag = 0;
    oal_uint irqsave;
    oal_dlist_head_stru *pst_entry = NULL;
    hcc_bus *pst_bus_tmp = NULL;
    if (oal_warn_on(pst_bus == NULL)) {
        return -OAL_EINVAL;
    }

    /* Check duplicate bus */
    oal_spin_lock_irq_save(&g_hcc_bus_res_lock, &irqsave);
    oal_dlist_search_for_each(pst_entry, &g_hcc_bus_res_hdr)
    {
        pst_bus_tmp = oal_dlist_get_entry(pst_entry, hcc_bus, list);
        if (oal_warn_on(hcc_bus_is_match(pst_bus_tmp, pst_bus) == OAL_TRUE)) {
            oal_print_mpxx_log(MPXX_LOG_ERR, "bus[%p] is duplicate, type:%s, id:%d",
                               pst_bus, hcc_bus_get_bus_type_str(pst_bus->bus_type), pst_bus->bus_id);
            oal_spin_unlock_irq_restore(&g_hcc_bus_res_lock, &irqsave);
            return -OAL_EBUSY;
        }
    }

    oal_spin_unlock_irq_restore(&g_hcc_bus_res_lock, &irqsave);

    ret = hcc_bus_resource_alloc(pst_bus);
    if (ret != OAL_SUCC) {
        return ret;
    }

    ret = snprintf_s(pst_bus->name, sizeof(pst_bus->name), sizeof(pst_bus->name) - 1,
                     "%s:%u", bus_name, pst_bus->bus_id);
    if (ret < 0) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "bus name format err\n");
        return ret;
    }

    oal_spin_lock_irq_save(&g_hcc_bus_res_lock, &irqsave);
    /* If empty init dev res */
    if (oal_dlist_is_empty(&g_hcc_bus_res_hdr) == OAL_TRUE) {
        oal_spin_unlock_irq_restore(&g_hcc_bus_res_lock, &irqsave);
#ifdef _PRE_PLAT_FEATURE_MULTI_HCC
        ret = hcc_dev_res_init_gfxx();
#else
        ret = hcc_dev_res_init_mpxx();
#endif
        oal_spin_lock_irq_save(&g_hcc_bus_res_lock, &irqsave);
        if (ret) {
            goto failed_dev_res_init;
        }
        init_flag = 1;
    }

    oal_dlist_add_tail(&pst_bus->list, &g_hcc_bus_res_hdr);
    ret = hcc_probe_bus(pst_bus);
    if (ret != OAL_SUCC) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "hcc bus %s probed failed!", pst_bus->name);
        goto failed_probe_bus;
    }
    oal_spin_unlock_irq_restore(&g_hcc_bus_res_lock, &irqsave);

    return OAL_SUCC;
failed_probe_bus:
    oal_dlist_delete_entry(&pst_bus->list);
    if (init_flag) {
        oal_spin_unlock_irq_restore(&g_hcc_bus_res_lock, &irqsave);
        hcc_dev_res_exit();
        oal_spin_lock_irq_save(&g_hcc_bus_res_lock, &irqsave);
    }
failed_dev_res_init:
    oal_spin_unlock_irq_restore(&g_hcc_bus_res_lock, &irqsave);
    hcc_bus_resource_free(pst_bus);
    return ret;
}

int32_t hcc_remove_bus(hcc_bus *pst_bus)
{
    oal_uint irqsave;
    oal_dlist_head_stru *pst_entry = NULL;
    hcc_bus *pst_bus_tmp = NULL;

    if (oal_warn_on(pst_bus == NULL)) {
        return OAL_SUCC;
    }

    /* delete bus and remove from dev resource */
    oal_spin_lock_irq_save(&g_hcc_bus_res_lock, &irqsave);

    oal_dlist_search_for_each(pst_entry, &g_hcc_bus_res_hdr)
    {
        pst_bus_tmp = oal_dlist_get_entry(pst_entry, hcc_bus, list);
        if (pst_bus_tmp->bus_dev == pst_bus->bus_dev) {
            if (pst_bus_tmp->bus_type == pst_bus->bus_type) {
                pst_bus->bus_dev->cur_bus = NULL;
            }
        }
    }

    oal_dlist_delete_entry(&pst_bus->list);

    oal_spin_unlock_irq_restore(&g_hcc_bus_res_lock, &irqsave);
    hcc_bus_resource_free(pst_bus);
    oal_spin_lock_irq_save(&g_hcc_bus_res_lock, &irqsave);

    if (oal_dlist_is_empty(&g_hcc_bus_res_hdr) == OAL_TRUE) {
        oal_spin_unlock_irq_restore(&g_hcc_bus_res_lock, &irqsave);
        hcc_dev_res_exit();
        oal_spin_lock_irq_save(&g_hcc_bus_res_lock, &irqsave);
    }

    oal_spin_unlock_irq_restore(&g_hcc_bus_res_lock, &irqsave);
    return OAL_SUCC;
}

#ifdef _PRE_HISI_BINDCPU
/* Debug */
int32_t hcc_bus_printbindcpu(void)
{
    hcc_bus *hi_bus = NULL;
    struct hcc_handler *hcc = NULL;
    struct cpumask slow_cpus, fast_cpus;

    external_get_slow_cpus(&slow_cpus);
    external_get_fast_cpus(&fast_cpus);

    hi_bus = hcc_get_bus(HCC_EP_WIFI_DEV);
    if (hi_bus == NULL) {
        return -OAL_EFAIL;
    }

    hcc = hbus_to_hcc(hi_bus);
    if (hcc == NULL) {
        return -OAL_EFAIL;
    }
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 4, 0))
    oal_print_mpxx_log(MPXX_LOG_INFO, "hcc cpu mask:0x%lx",
                       cpumask_bits(hcc->hcc_transer_info.hcc_transfer_thread->cpus_ptr)[0]);
#else
    oal_print_mpxx_log(MPXX_LOG_INFO, "hcc cpu mask:0x%lx",
                       cpumask_bits(&(hcc->hcc_transer_info.hcc_transfer_thread->cpus_allowed))[0]);
#endif
    oal_print_mpxx_log(MPXX_LOG_INFO, "hcc cpu fast_cpus:0x%lx", cpumask_bits(&fast_cpus)[0]);
    oal_print_mpxx_log(MPXX_LOG_INFO, "hcc cpu slow_cpus:0x%lx", cpumask_bits(&slow_cpus)[0]);

    return OAL_SUCC;
}
#endif

/*
 * 功能描述  : 绑定hcc_transfer_thread线程所在CPU核
 * 1.日    期  : 2020年07月14日
 *   修改内容  : 新生成函数
 */
#ifdef _PRE_HISI_BINDCPU
OAL_STATIC void hcc_bus_hcctransfer_bindcpu(struct hcc_handler *hcc, oal_pcie_bindcpu_cfg *bindcpu_cfg)
{
    struct cpumask fast_cpus, all_cpus;
    external_get_fast_cpus(&fast_cpus);
    cpumask_setall(&all_cpus);

    if (bindcpu_cfg->is_bind) {
        /*  6 7核麒麟有特殊处理可能迁移不过去导致fastboot问题 */
        /*  irq核占用率容易到100%,故只绑567核保证160M性能 */
        oal_cpumask_clear_cpu(cpumask_first(&fast_cpus), &fast_cpus);
        set_cpus_allowed_ptr(hcc->hcc_transer_info.hcc_transfer_thread, &fast_cpus);
    } else {
        /* CPU0中断多负载大, 线程部署在非CPU0上 */
        oal_cpumask_clear_cpu(cpumask_first(&all_cpus), &all_cpus);
        set_cpus_allowed_ptr(hcc->hcc_transer_info.hcc_transfer_thread, &all_cpus);
    }
    oal_print_mpxx_log(MPXX_LOG_INFO, "hisi_hcc bind to cpu 0x%lx",
        bindcpu_cfg->is_bind ? cpumask_bits(&fast_cpus)[0] : cpumask_bits(&all_cpus)[0]);
}

int __weak find_lowest_load_cpu(struct cpumask *mask)
{
    int cpu;
    int lowest_load_cpu = -1;

    if (!mask || cpumask_empty(mask)) {
        return -1;
    }

    for_each_cpu(cpu, mask) {
        if (!cpu_online(cpu)) {
            continue;
        }

        lowest_load_cpu = cpu;
    }

    return lowest_load_cpu;
}

void hcc_get_cpus(cpu_cap_mask *cpu_mask, uint8_t is_lowest_load)
{
    if (is_lowest_load == 1) {
        struct cpumask tmp;
        int32_t cpu;
        external_get_fast_cpus(&tmp);
        external_get_slow_cpus(&cpu_mask->slow_cpus);
        oal_cpumask_clear_cpu(OAL_BUS_HPCPU_NUM, &tmp);
        cpu = find_lowest_load_cpu(&tmp);
        if (cpu < 0) {
            oal_print_mpxx_log(MPXX_LOG_INFO, "find lowest load cpu failed!");
            return;
        }
        cpu_mask->fast_cpus = *(struct cpumask *)cpumask_of(cpu);
    } else {
        external_get_fast_cpus(&cpu_mask->fast_cpus);
        external_get_slow_cpus(&cpu_mask->slow_cpus);
    }
}
#endif
int32_t hcc_bus_bindcpu(hcc_bus *hi_bus, uint32_t chan, int32_t is_bind)
{
    oal_pcie_bindcpu_cfg bindcpu_cfg = *(oal_pcie_bindcpu_cfg *)&is_bind;
#ifdef _PRE_HISI_BINDCPU
    struct hcc_handler *hcc = NULL;
#endif

    if (oal_warn_on(hi_bus == NULL)) {
        return -OAL_ENODEV;
    }

    if (oal_unlikely(hi_bus->opt_ops->bindcpu == NULL)) {
        return -OAL_EIO;
    }

    if (hi_bus->is_bind == bindcpu_cfg.is_bind) {
        return OAL_SUCC;
    }

    oal_print_mpxx_log(MPXX_LOG_INFO, "hcc %s cpu, thread[%d]irq[%d]",
        (bindcpu_cfg.is_bind ? "bind" : "unbind"), bindcpu_cfg.thread_cmd, bindcpu_cfg.irq_cpu);
    hi_bus->is_bind = bindcpu_cfg.is_bind;

    /* 绑定线程hisi_hcc */
#ifdef _PRE_HISI_BINDCPU
    hcc = hbus_to_hcc(hi_bus);
    if (hcc != NULL) {
        if (bindcpu_cfg.thread_cmd && hcc->hcc_transer_info.hcc_transfer_thread != NULL) {
            hcc_bus_hcctransfer_bindcpu(hcc, &bindcpu_cfg);
        }
    }
#endif
    if (hi_bus->opt_ops->bindcpu == NULL) {
        oal_print_mpxx_log(MPXX_LOG_INFO, "bindcpu NULL!");
    }

    return hi_bus->opt_ops->bindcpu(hi_bus, chan, is_bind);
}

EXPORT_SYMBOL_GPL(hcc_bus_bindcpu);

/* PM */
int32_t hcc_bus_pm_wakeup_device(hcc_bus *hi_bus)
{
    uint32_t uret;
    if (oal_warn_on(hi_bus == NULL)) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "hi_bus is null");
        return -OAL_EIO;
    }
    if (oal_unlikely(hi_bus->pst_pm_callback == NULL)) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "pst_pm_callback is null");
        return -OAL_EIO;
    }
    if (oal_unlikely(hi_bus->pst_pm_callback->pm_wakeup_dev == NULL)) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "pm_wakeup_dev is null");
        return -OAL_EIO;
    }
    uret = hi_bus->pst_pm_callback->pm_wakeup_dev();
    if (oal_unlikely(uret != OAL_SUCC)) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "pm_wakeup_dev failed ret=%u, bus_type=%u", uret, hi_bus->bus_type);
        wlan_pm_dump_host_info();
        return -OAL_EBUSY;
    }
    return OAL_SUCC;
}
EXPORT_SYMBOL_GPL(hcc_bus_pm_wakeup_device);

#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
void hcc_bus_exception_submit(hcc_bus *hi_bus, int32_t excep_type)
{
    unsigned long flags;
    oal_workqueue_stru *pst_excp_workqueue = NULL;

    declare_dft_trace_key_info("wifi_trans_exception", OAL_DFT_TRACE_EXCEP);
    if (oal_unlikely(hi_bus == NULL)) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "[E]%s, hi_bus is null", __FUNCTION__);
        return;
    }

    pst_excp_workqueue = wifi_get_exception_workqueue();
    if (oal_unlikely(pst_excp_workqueue == NULL)) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "[E]%s, pst_excp_workqueue is null", __FUNCTION__);
        return;
    }

    /* disable bus */
    hcc_bus_disable_state(hi_bus, OAL_BUS_STATE_RX);

    oal_spin_lock_irq_save(&hi_bus->bus_excp_lock, &flags);

    if (oal_work_is_busy(&hi_bus->bus_excp_worker)) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "excep %d, exception %d is working", excep_type, hi_bus->bus_excp_type);
        oal_spin_unlock_irq_restore(&hi_bus->bus_excp_lock, &flags);
        return;
    }

    hcc_change_state_exception(hbus_to_hcc(hi_bus));
    hi_bus->bus_excp_type = excep_type;

    if (excep_type != HCC_BUS_PANIC) {
        oal_spin_unlock_irq_restore(&hi_bus->bus_excp_lock, &flags);
        if (hi_bus->bus_type == HCC_BUS_SDIO) {
            (void)ssi_dump_err_regs(SSI_ERR_HCC_EXCP_SDIO);
        }
        if (hi_bus->bus_type == HCC_BUS_PCIE) {
            (void)ssi_dump_err_regs(SSI_ERR_HCC_EXCP_PCIE);
        }
        oal_spin_lock_irq_save(&hi_bus->bus_excp_lock, &flags);
    }

    oal_dft_print_error_key_info();

    if (g_hcc_exception_enable) {
        oal_wake_lock_timeout(&hi_bus->bus_excp_wlock, HI_BUS_EXCPLOCK_TIMEOUT);
        queue_work(pst_excp_workqueue, &hi_bus->bus_excp_worker);
    } else {
        oal_print_mpxx_log(MPXX_LOG_INFO, "wifi exception memdump function disabled");
    }
    oal_spin_unlock_irq_restore(&hi_bus->bus_excp_lock, &flags);
}

oal_module_symbol(hcc_bus_exception_submit);

int32_t hcc_bus_exception_is_busy(hcc_bus *hi_bus)
{
    if (oal_unlikely(hi_bus == NULL)) {
        return OAL_FALSE;
    }

    if (oal_work_is_busy(&hi_bus->bus_excp_worker)) {
        /* mem dump is processing,
          can't power off or submit repeat */
        return OAL_TRUE;
    }

    return OAL_FALSE;
}

oal_module_symbol(hcc_bus_exception_is_busy);

int32_t oal_trigger_bus_exception(hcc_bus *hi_bus, int32_t is_sync)
{
    unsigned long timeout_jiffies;
    if (oal_unlikely(hi_bus == NULL)) {
        return OAL_FALSE;
    }

    if (hcc_bus_exception_is_busy(hi_bus) == OAL_TRUE) {
        return OAL_TRUE;
    }

    if (oal_is_chip_error_block() == OAL_TRUE) {
        oal_print_mpxx_log(MPXX_LOG_INFO, "bypass bus exception");
        return OAL_TRUE;
    }

    /* trigger device panic */
    if (hcc_bus_send_message(hi_bus, H2D_MSG_TEST)) {
        oal_print_mpxx_log(MPXX_LOG_WARN, "send device panic message failed!");
        return OAL_FALSE;
    }

    if (is_sync != OAL_TRUE) {
        oal_print_mpxx_log(MPXX_LOG_INFO, "wifi exception is doing...");
        return OAL_TRUE;
    }

    timeout_jiffies = OAL_TIME_JIFFY + oal_msecs_to_jiffies(2000); /* 2000ms for wait */
    forever_loop() {
        if (hcc_bus_exception_is_busy(hi_bus) == OAL_TRUE) {
            break;
        }

        if (time_after(OAL_TIME_JIFFY, timeout_jiffies)) {
            oal_print_mpxx_log(MPXX_LOG_WARN, "wait panic message timeout!");
            return OAL_FALSE;
        }

        oal_msleep(oal_jiffies_to_msecs(1));
        up(&hi_bus->rx_sema);
    }

    oal_print_mpxx_log(MPXX_LOG_INFO, "trigger wifi exception manually sucuess");
    return OAL_TRUE;
}

oal_module_symbol(oal_trigger_bus_exception);

void hcc_bus_exception_submit_test(void)
{
    hcc_bus_exception_submit(hcc_get_bus(HCC_EP_WIFI_DEV), HCC_BUS_TRANS_FAIL);
}

OAL_STATIC int32_t hcc_bus_device_panic_callback(void *data)
{
    hcc_bus *hi_bus = (hcc_bus *)data;
    hcc_bus_disable_state(hi_bus, OAL_BUS_STATE_ALL);
    hcc_bus_exception_submit(hi_bus, HCC_BUS_PANIC);

    oal_print_mpxx_log(MPXX_LOG_INFO, "receive dev panic msg");
    chr_exception_report(CHR_PLATFORM_EXCEPTION_EVENTID, CHR_SYSTEM_PLAT, CHR_LAYER_DRV,
                         CHR_PLT_DRV_EVENT_DEV, CHR_PLAT_DRV_ERROR_WIFI_DEV_PANIC);

    return OAL_SUCC;
}

OAL_STATIC int32_t hcc_bus_device_init_ready(void *data)
{
    hcc_bus *hi_bus = (hcc_bus *)data;
    oal_print_mpxx_log(MPXX_LOG_INFO, "device ready, bus:%s", hcc_bus_get_bus_type_str(hi_bus->bus_type));
    oal_complete(&hi_bus->st_device_ready);
    return OAL_SUCC;
}

int32_t hcc_bus_poweroff_pre(hcc_bus *hi_bus)
{
    int32_t ret = -OAL_EFAIL;

    if (oal_warn_on(hi_bus == NULL)) {
        return -OAL_EINVAL;
    }

    if (oal_likely(hi_bus->opt_ops->poweroff_pre)) {
        ret = hi_bus->opt_ops->poweroff_pre(hi_bus);
    }

    return ret;
}

int32_t hcc_bus_poweroff_complete(hcc_bus *hi_bus)
{
    int32_t ret = -OAL_EFAIL;

    if (oal_warn_on(hi_bus == NULL)) {
        return -OAL_EINVAL;
    }

    if (oal_likely(hi_bus->opt_ops->poweroff_complete)) {
        ret = hi_bus->opt_ops->poweroff_complete(hi_bus);
    }

    return ret;
}

OAL_STATIC int32_t wait_wlan_wkup_gpio_level(int32_t gpio_level, unsigned long timeout)
{
    int32_t gpio_value;
    gpio_level = (gpio_level == GPIO_LOWLEVEL) ? GPIO_LOWLEVEL : GPIO_HIGHLEVEL;
    forever_loop() {
        gpio_value = conn_get_gpio_level(W_WKUP_HOST);
        gpio_value = (gpio_value == GPIO_LOWLEVEL) ? GPIO_LOWLEVEL : GPIO_HIGHLEVEL;
        if (gpio_value == gpio_level) {
            return SUCCESS;
        }

        if (time_after(OAL_TIME_JIFFY, timeout)) {
            return -FAILURE;
        } else {
            if (wlan_is_shutdown()) {
                oal_io_print("[E]hold_time_check:wifi is shutdown!\n");
                return (gpio_level == GPIO_LOWLEVEL) ? SUCCESS : -FAILURE;
            }
            oal_usleep_range(10, 20); /* 10~20us 让出cpu */
            cpu_relax();
        }
    }
}

/* 检查DEVICE WAKEUP HOST gpio 是否拉高。 */
OAL_STATIC int32_t oal_dev2host_gpio_hold_time_check(uint32_t switch_timeout, uint32_t hold_time)
{
    unsigned long timeout;
    declare_time_cost_stru(cost);
    const uint32_t ul_default_timeout = 200;

    if (!switch_timeout) {
        switch_timeout = ul_default_timeout;
    }

    timeout = OAL_TIME_JIFFY + oal_msecs_to_jiffies(switch_timeout);
    oal_get_time_cost_start(cost);

    // wait gpio high
    if (wait_wlan_wkup_gpio_level(GPIO_HIGHLEVEL, timeout) != SUCCESS) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "[E]wait wakeup gpio to high timeout [%u] ms", switch_timeout);
        return OAL_FALSE;
    }
    oal_get_time_cost_end(cost);
    oal_calc_time_cost_sub(cost);
    oal_print_mpxx_log(MPXX_LOG_INFO, "device reset  ip cost %llu us", time_cost_var_sub(cost));

    // high level hold time
    timeout = OAL_TIME_JIFFY + oal_msecs_to_jiffies(hold_time);
    // wait high level hold time
    if (wait_wlan_wkup_gpio_level(GPIO_LOWLEVEL, timeout) == SUCCESS) {
        oal_print_mpxx_log(MPXX_LOG_INFO, "[E]gpio pull down again!");
        return OAL_FALSE;
    }

    // gpio high and hold enough time.
    return OAL_TRUE;
}

OAL_STATIC void hcc_bus_panic_get_checktime(uint32_t *timeout, uint32_t *hold_time)
{
    *hold_time = 100; // 100 ms for gpio high level
    if (mpxx_is_asic()) {
        *timeout = 5000; // 5000 ms
    } else {
        *timeout = 60000; // 60000 ms, 60 seconds for cpu wdt timeout
    }
    oal_print_mpxx_log(MPXX_LOG_INFO, "timeout=%u ms, hold_time=%u ms", *timeout, *hold_time);
}

/* check whether device had panic */
OAL_STATIC int32_t hcc_bus_panic_status_check(hcc_bus *hi_bus)
{
    int32_t ret = OAL_FALSE;
    uint32_t timeout, hold_time;

    if (hi_bus->bus_excp_type == HCC_BUS_PANIC) {
        ret = OAL_TRUE;
    }

    /* 如果GPIO没有分配, 则不检查GPIO状态来确定是否device panic，保持原异常类型 */
    if (conn_gpio_valid(W_WKUP_HOST) == OAL_FALSE) {
        ret = OAL_FALSE;
    } else {
        hcc_bus_panic_get_checktime(&timeout, &hold_time);

        /* gpio mode,两参数均代表设置的超时 */
        if (oal_dev2host_gpio_hold_time_check(timeout, hold_time) == OAL_TRUE) {
            ret = OAL_TRUE;
        } else {
            ret = OAL_FALSE;
        }
    }

    return ret;
}

OAL_STATIC uint32_t hcc_bus_get_exception_mem_info_gf61(hcc_bus *hi_bus)
{
    uint32_t size;
    struct st_wifi_dump_mem_info *mem_info = NULL;
    uint32_t is_gt = (hi_bus->dev_id == HCC_EP_GT_DEV) ? OAL_TRUE : OAL_FALSE;

    oal_print_mpxx_log(MPXX_LOG_INFO, "gf61 %s memdump ", is_gt ? "gt" : "wifi");

    if (is_gt) {
        mem_info = g_gf61_pilot_gt_meminfo;
        size = (uint32_t)(sizeof(g_gf61_pilot_gt_meminfo) / sizeof(struct st_wifi_dump_mem_info));
    } else {
        mem_info = g_gf61_pilot_wifi_meminfo;
        size = (uint32_t)(sizeof(g_gf61_pilot_wifi_meminfo) / sizeof(struct st_wifi_dump_mem_info));
    }
    hi_bus->mem_info = mem_info;
    hi_bus->mem_size = size;
    return OAL_SUCC;
}

int32_t hcc_bus_get_exception_mem_info(hcc_bus *hi_bus)
{
    uint32_t size;
    struct st_wifi_dump_mem_info *mem_info = NULL;

    if (get_mpxx_subchip_type() == BOARD_VERSION_MP15) {
        oal_print_mpxx_log(MPXX_LOG_INFO, "mp15 %s memdump ", mpxx_is_asic() ? "asic" : "fpga");
        if (mpxx_is_asic()) {
            /* mp15 Asic */
            mem_info = g_mp15_pilot_asic_meminfo;
            size = (uint32_t)(sizeof(g_mp15_pilot_asic_meminfo) / sizeof(struct st_wifi_dump_mem_info));
        } else {
            /* mp15 Fpga */
            mem_info = g_mp15_pilot_fpga_meminfo;
            size = (uint32_t)(sizeof(g_mp15_pilot_fpga_meminfo) / sizeof(struct st_wifi_dump_mem_info));
        }
    } else if (get_mpxx_subchip_type() == BOARD_VERSION_MP16) {
        oal_print_mpxx_log(MPXX_LOG_INFO, "mp16 %s memdump ", mpxx_is_asic() ? "asic" : "fpga");
        if (mpxx_is_asic()) {
            /* mp16 Asic */
            mem_info = g_mp16_pilot_asic_meminfo;
            size = (uint32_t)(sizeof(g_mp16_pilot_asic_meminfo) / sizeof(struct st_wifi_dump_mem_info));
        } else {
            /* mp16 Fpga */
            mem_info = g_mp16_pilot_fpga_meminfo;
            size = (uint32_t)(sizeof(g_mp16_pilot_fpga_meminfo) / sizeof(struct st_wifi_dump_mem_info));
        }
    } else if (get_mpxx_subchip_type() == BOARD_VERSION_MP16C) {
        oal_print_mpxx_log(MPXX_LOG_INFO, "mp16c memdump");

        /* mp16c Memdump */
        mem_info = g_mp16c_meminfo;
        size = (uint32_t)(sizeof(g_mp16c_meminfo) / sizeof(struct st_wifi_dump_mem_info));
    } else if (get_mpxx_subchip_type() == BOARD_VERSION_GF61) {
        return hcc_bus_get_exception_mem_info_gf61(hi_bus);
    } else if (get_mpxx_subchip_type() == BOARD_VERSION_MP13) {
        mem_info = g_mp13_pilot_meminfo;
        size = (uint32_t)(sizeof(g_mp13_pilot_meminfo) / sizeof(struct st_wifi_dump_mem_info));
    } else {
        oal_print_mpxx_log(MPXX_LOG_ERR, "chip[%d] no memdump info", get_mpxx_subchip_type());
        return -OAL_EFAIL;
    }

    hi_bus->mem_info = mem_info;
    hi_bus->mem_size = size;

    return OAL_SUCC;
}

OAL_STATIC void hcc_bus_exception_handler(oal_work_stru *work)
{
    hcc_bus *hi_bus = oal_container_of(work, hcc_bus, bus_excp_worker);

    if (hi_bus == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "hi_bus is null");
        return;
    }

    if (hcc_bus_get_exception_mem_info(hi_bus) != OAL_SUCC) {
        return;
    }

    hcc_bus_wake_lock(hi_bus);
    if (hi_bus->bus_excp_type == HCC_BUS_PANIC) {
        declare_dft_trace_key_info("wifi_device_panic", OAL_DFT_TRACE_EXCEP);
        oam_error_log0(0, OAM_SF_ANY, "[E]WiFi Device Panic");
    }

    if (hi_bus->bus_excp_type == HCC_BUS_TRANS_FAIL) {
        declare_dft_trace_key_info("wifi_trans_fail", OAL_DFT_TRACE_EXCEP);
        oam_error_log0(0, OAM_SF_ANY, "[E]wifi_trans_fail");
    }

    hcc_bus_disable_state(hi_bus, OAL_BUS_STATE_ALL);

    oal_dft_print_all_key_info();
    plat_changid_print();

#ifdef CONFIG_PRINTK
    hwifi_panic_log_dump(KERN_INFO);
    hcc_bus_print_trans_info(hi_bus, 0);
#endif

    if (hi_bus->pst_pm_callback->pm_disable) {
        hi_bus->pst_pm_callback->pm_disable(OAL_FALSE);
    }

    if (hcc_bus_panic_status_check(hi_bus) == OAL_TRUE) {
        oam_error_log0(0, OAM_SF_ANY, "[E]check wakeup gpio ok, wcpu had panic");
        if (hi_bus->bus_excp_type != HCC_BUS_PANIC) {
            oam_error_log1(0, OAM_SF_ANY, "[E]change sdio excp type from %d to device panic ", hi_bus->bus_excp_type);
        }
        hi_bus->bus_excp_type = HCC_BUS_PANIC;
        oal_msleep(10); /* wait 10ms for device panic */
    } else {
        /* device is't panic, reset sdio ip from host */
        oam_error_log0(0, OAM_SF_ANY, "[E]check wakeup gpio fail, wcpu crash");
        hi_bus->bus_excp_type = HCC_BUS_TRANS_FAIL;
    }

    if (wlan_is_shutdown()) {
        hcc_bus_wake_unlock(hi_bus);
        oal_io_print("[E]dfr ignored, wifi shutdown, wakelock cnt %lu\n", hi_bus->st_bus_wakelock.lock_count);
        oam_error_log0(0, OAM_SF_ANY, "wifi is shutdown, dfr submit ignored");
        return;
    }

    dfr_notifier_chain_call(hi_bus->bus_excp_type);

    wifi_exception_work_submit(hi_bus, hi_bus->bus_excp_type);

    hcc_bus_wake_unlock(hi_bus);
}

#undef COFNIG_TEST_SDIO_INT_LOSS
/*
 * Prototype    : oal_gpio_rxdata_thread
 * Description  : gpio rx data function
 * Input        : adapter   oal_sdio handler
 * Return Value : succ or fail
 */
OAL_STATIC int32_t hcc_bus_rxdata_thread(void *data)
{
#ifdef COFNIG_TEST_SDIO_INT_LOSS
    int i = 0;
    const int l_loop_times = 5;
#endif
    hcc_bus *hi_bus;

#ifdef _PRE_LINUX_TEST
    struct oal_sched_param_stru param;
#else
    struct sched_param param;
#endif

    hi_bus = (hcc_bus *)data;

    oal_print_mpxx_log(MPXX_LOG_INFO, "hisi wifi sched ctrl rx thread high speed");
    param.sched_priority = OAL_BUS_RXDATA_THREAD_PRIORITY;
    oal_set_thread_property(current, OAL_BUS_RX_THREAD_POLICY, &param, MIN_NICE);

    allow_signal(SIGTERM);
    while (oal_likely(!down_interruptible(&hi_bus->rx_sema))) {
        if (oal_unlikely(kthread_should_stop())) {
            oal_print_mpxx_log(MPXX_LOG_INFO, "exit gpio rx thread");
            break;
        }
#ifdef COFNIG_TEST_SDIO_INT_LOSS
        for (i = 0; i < l_loop_times; i++) {
#endif
            /* start to read GPIO interrupt */
            hcc_bus_rx_transfer_lock(hi_bus);
            if (hi_bus->opt_ops->wlan_gpio_rxdata_proc) {
                hi_bus->opt_ops->wlan_gpio_rxdata_proc(hi_bus);
            }
            hcc_bus_rx_transfer_unlock(hi_bus);
#ifdef COFNIG_TEST_SDIO_INT_LOSS
        }
#endif
    }

    oal_print_mpxx_log(MPXX_LOG_INFO, "gpio rx data is terminated");
    return OAL_SUCC;
}

// 此函数无人使用
uint64_t oal_get_gpio_int_count_para(void)
{
    hcc_bus *hi_bus;

    hi_bus = hcc_get_bus(HCC_EP_WIFI_DEV);
    if (hi_bus == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "hi_bus is null");
        return 0;
    }

    return hi_bus->gpio_int_count;
}

oal_module_symbol(oal_get_gpio_int_count_para);

OAL_STATIC void hcc_bus_sched_gpio_task(hcc_bus *pst_bus, int32_t irq)
{
    if (oal_likely(pst_bus->opt_ops->wlan_gpio_handler)) {
        pst_bus->opt_ops->wlan_gpio_handler(pst_bus, irq);
    } else {
        oal_print_mpxx_log(MPXX_LOG_ERR, "wlan_gpio_handler is NULL, irq:%d, bus type:%s, disable gpio interrupt!",
                           irq, hcc_bus_get_bus_type_str(pst_bus->bus_type));
    }
}

/*
 * Prototype    : hcc_bus_wlan_gpio_irq
 * Description  : wlan irq process function
 * Return Value : OAL_STATIC irqreturn_t
 */
#if defined(_PRE_S4_FEATURE)
irqreturn_t hcc_bus_wlan_gpio_irq(int32_t irq, void *dev_id)
#else
OAL_STATIC irqreturn_t hcc_bus_wlan_gpio_irq(int32_t irq, void *dev_id)
#endif
{
    hcc_bus *pst_bus = NULL;
    hcc_bus_dev *pst_bus_dev = NULL;

    pst_bus_dev = (hcc_bus_dev *)dev_id;
    if (oal_unlikely(pst_bus_dev == NULL)) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dev id  is NULL, irq:%d", irq);
        return IRQ_HANDLED;
    }

    pst_bus = hdev_to_hbus(pst_bus_dev);
    if (oal_unlikely(pst_bus == NULL)) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "curr bus is NULL, irq:%d, bus_dev id:%u", irq, pst_bus_dev->dev_id);
        return IRQ_HANDLED;
    }

    if (oal_likely(pst_bus->opt_ops->wlan_gpio_handler)) {
        hcc_bus_sched_gpio_task(pst_bus, irq);
    } else {
        oal_print_mpxx_log(MPXX_LOG_ERR,
                           "wlan_gpio_handler is NULL, irq:%d, bus_dev id:%u, disable gpio interrupt!",
                           irq, pst_bus_dev->dev_id);
        oal_wlan_gpio_intr_enable(pst_bus_dev, OAL_FALSE);
    }

    return IRQ_HANDLED;
}

/*
 * Prototype    : oal_register_gpio_intr
 * Description  : initialize sdio pm interface
 */
OAL_STATIC int32_t oal_register_gpio_intr(hcc_bus_dev *pst_bus_dev)
{
    int32_t ret;
    int32_t type;

    if (pst_bus_dev->dev_id == HCC_EP_GT_DEV) {
        type = GT_WKUP_HOST;
    } else {
        type = W_WKUP_HOST;
    }

    ret = conn_irq_register(type, hcc_bus_wlan_gpio_irq, pst_bus_dev);
    if (ret < 0) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "failed to request wlan irq");
        return ret;
    }

    oal_print_mpxx_log(MPXX_LOG_INFO, "success to register sdio gpio intr");
    return OAL_SUCC;
}

/*
 * Prototype    : oal_unregister_gpio_intr
 * Description  : initialize sdio pm interface
 */
OAL_STATIC void oal_unregister_gpio_intr(hcc_bus_dev *pst_bus_dev)
{
    int32_t type;

    if (oal_unlikely(pst_bus_dev == NULL)) {
        oal_warn_on(1);
        return;
    }
    if (pst_bus_dev->dev_id == HCC_EP_GT_DEV) {
        type = GT_WKUP_HOST;
    } else {
        type = W_WKUP_HOST;
    }

    /* disable wlan irq */
    conn_gpio_intr_enable(type, OAL_FALSE);
    /* free irq when sdio driver deinit */
    conn_irq_unregister(type, pst_bus_dev);
}

/*
 * 函 数 名  : oal_wlan_gpio_intr_enable
 * 功能描述  : 使能/关闭 WLAN GPIO 中断
 * 输入参数  : 1:enable; 0:disenable
 * 返 回 值  : 成功或失败原因
 */
void oal_wlan_gpio_intr_enable(hcc_bus_dev *pst_bus_dev, uint32_t ul_en)
{
    int32_t type;

    if (oal_unlikely(pst_bus_dev == NULL)) {
        oal_warn_on(1);
        return;
    }
    if (pst_bus_dev->dev_id == HCC_EP_GT_DEV) {
        type = GT_WKUP_HOST;
    } else {
        type = W_WKUP_HOST;
    }

    conn_gpio_intr_enable(type, ul_en);
}

/*
 * 函 数 名  : oal_flowctrl_gpio_intr_enable
 * 功能描述  : 使能/关闭GPIO流控中断
 * 输入参数  : 1: enabled; 0: disabled
 */
OAL_STATIC void oal_flowctrl_gpio_intr_enable(hcc_bus_dev *pst_bus_dev, oal_bool_enum_uint8 en_enable)
{
    if (en_enable) {
        /* 当前流控状态为关闭 */
        if (!pst_bus_dev->en_flowctrl_irq_stat) {
            /* 使能GPIO流控中断 */
            enable_irq(pst_bus_dev->l_flowctrl_irq);
            oal_print_mpxx_log(MPXX_LOG_WARN, "gpio flowctrl irq: %d enable", pst_bus_dev->l_flowctrl_irq);
            /* 同步当前流控状态为使能 */
            pst_bus_dev->en_flowctrl_irq_stat = OAL_TRUE;
        }
    } else {
        /* 当前流控状态为使能 */
        if (pst_bus_dev->en_flowctrl_irq_stat) {
            /* 关闭GPIO流控中断 */
            disable_irq_nosync(pst_bus_dev->l_flowctrl_irq);
            oal_print_mpxx_log(MPXX_LOG_WARN, "gpio flowctrl irq: %d disable nosync", pst_bus_dev->l_flowctrl_irq);
            /* 同步当前流控状态为关闭 */
            pst_bus_dev->en_flowctrl_irq_stat = OAL_FALSE;
        }
    }
}

/*
 * 函 数 名  : hcc_bus_flowctrl_gpio_irq
 * 功能描述  : GPIO流控中断回调函数
 */
OAL_STATIC irqreturn_t hcc_bus_flowctrl_gpio_irq(int32_t l_irq, void *p_dev_id)
{
    hcc_bus *pst_bus = NULL;
    hcc_bus_dev *pst_bus_dev = NULL;

    pst_bus_dev = (hcc_bus_dev *)p_dev_id;
    if (oal_unlikely(pst_bus_dev == NULL)) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dev id  is NULL, irq:%d", l_irq);
        return IRQ_HANDLED;
    }

    pst_bus = hdev_to_hbus(pst_bus_dev);
    if (oal_unlikely(pst_bus == NULL)) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "curr bus is NULL, irq:%d, bus_dev id:%u", l_irq, pst_bus_dev->dev_id);
        return IRQ_HANDLED;
    }

    if (oal_likely(pst_bus->opt_ops->flowctrl_gpio_handler)) {
        /* 执行GPIO流控逻辑(oal_sdio_gpio_flowctrl_irq) */
        pst_bus->opt_ops->flowctrl_gpio_handler(pst_bus, l_irq);
    } else {
        /* flowctrl_gpio_handler不存在, 关闭GPIO流控功能 */
        oal_print_mpxx_log(MPXX_LOG_ERR,
                           "flowctrl_gpio_handler is NULL, irq:%d, bus_dev id:%u, disable gpio interrupt!",
                           l_irq, pst_bus_dev->dev_id);
        oal_flowctrl_gpio_intr_enable(pst_bus_dev, OAL_FALSE);
    }

    return IRQ_HANDLED;
}

/*
 * 函 数 名  : oal_register_gpio_flowctrl_intr
 * 功能描述  : 注册GPIO流控中断
 */
OAL_STATIC int32_t oal_register_gpio_flowctrl_intr(hcc_bus_dev *pst_bus_dev)
{
    int32_t ret;
    mpxx_board_info *pst_board = get_hi110x_board_info();
    uint32_t flowctrl_irq = 0;

    /*  获取管脚对应中断号 */
    board_flowctrl_irq_init();

    flowctrl_irq = (uint32_t)pst_board->flowctrl_irq;
    if (!flowctrl_irq) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "[BUS][ERROR]flowctrl irq should't be 0");
        return OAL_FAIL;
    }

    pst_bus_dev->l_flowctrl_irq = pst_board->flowctrl_irq;

    /* 调用内核接口注册GPIO流控中断, 中断触发时回调hcc_bus_flowctrl_gpio_irq */
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3, 10, 44))
    ret = request_irq(flowctrl_irq, hcc_bus_flowctrl_gpio_irq,
                      IRQF_NO_SUSPEND | IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING | IRQF_DISABLED,
                      "wifi_gpio_flowctrl_intr", pst_bus_dev);
#else
    /* 低版本内核没有IRQF_NO_SUSPEND标记 */
    ret = request_irq(flowctrl_irq, hcc_bus_flowctrl_gpio_irq,
                      IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING | IRQF_DISABLED,
                      "wifi_gpio_flowctrl_intr", pst_bus_dev);
#endif
    if (ret < 0) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "failed to request flowctrl irq, ret code = %d", ret);
        return OAL_FAIL;
    }

    /* 中断状态标记初始化(使能) */
    pst_bus_dev->en_flowctrl_irq_stat = OAL_FALSE;

    /* 初始化GPIO流控中断为使能状态 */
    /* : 内核规定enable_irq调用次数必须小于等于disable_irq, 否侧kmesg会报warning  */
    oal_flowctrl_gpio_intr_enable(pst_bus_dev, OAL_FALSE);
    oal_flowctrl_gpio_intr_enable(pst_bus_dev, OAL_TRUE);

    pst_bus_dev->en_flowctrl_gpio_registered = OAL_TRUE;

    return OAL_SUCC;
}

/*
 * 函 数 名  : oal_unregister_gpio_flowctrl_intr
 * 功能描述  : 注销GPIO流控中断
 */
void oal_unregister_gpio_flowctrl_intr(hcc_bus_dev *pst_bus_dev)
{
    /* 关闭GPIO流控中断 */
    oal_flowctrl_gpio_intr_enable(pst_bus_dev, OAL_FALSE);

    /* 注销GPIO流控中断 */
    free_irq(pst_bus_dev->l_flowctrl_irq, pst_bus_dev);

    pst_bus_dev->en_flowctrl_gpio_registered = OAL_FALSE;
}

/*
 * 函 数 名  : hcc_bus_flowctrl_init
 * 功能描述  : 流控初始化接口, 流控类型来自私有定制化文件
 */
uint32_t hcc_bus_flowctrl_init(uint8_t uc_hcc_flowctrl_type)
{
    hcc_bus_dev *pst_bus_dev = hcc_get_bus_dev(0);
    if (pst_bus_dev == NULL) {
        oal_print_mpxx_log(MPXX_LOG_WARN, "flowctrl init get mpxx dev is null");
        return OAL_FAIL;
    }

    /* 流控类型: 0.SDIO 1.GPIO */
    if (uc_hcc_flowctrl_type == 0) {
        oal_print_mpxx_log(MPXX_LOG_WARN, "flowctrl type = SDIO, already init");
        return OAL_SUCC;
    }

    /* hcc已注册GPIO中断 */
    if (pst_bus_dev->en_flowctrl_gpio_registered) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "flowctrl type = GPIO, already init");
        return OAL_SUCC;
    }

    /* Step3: 使用中断号注册GPIO中断 */
    if (oal_register_gpio_flowctrl_intr(pst_bus_dev) != OAL_SUCC) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "request flowctrl gpio irq failed!");
        return OAL_FAIL;
    }

    return OAL_SUCC;
}

OAL_STATIC OAL_INLINE void hcc_bus_print_state(uint32_t old_state, uint32_t new_state)
{
    if (old_state != new_state) {
        oal_print_mpxx_log(MPXX_LOG_INFO, "bus state changed, tx[%s=>%s],rx[%s=>%s]",
                           (old_state & OAL_BUS_STATE_TX) ? "on " : "off",
                           (new_state & OAL_BUS_STATE_TX) ? "on " : "off",
                           (old_state & OAL_BUS_STATE_RX) ? "on " : "off",
                           (new_state & OAL_BUS_STATE_RX) ? "on " : "off");
    }
}

/*
 * 函 数 名  : hcc_bus_wakelocks_release_detect
 * 功能描述  : 强行释放wakelock锁
 * 返 回 值  : 成功或失败原因
 */
void hcc_bus_wakelocks_release_detect(hcc_bus *pst_bus)
{
    /* before call this function , please make sure the rx/tx queue is empty and no data transfer!! */
    if (oal_warn_on(!pst_bus)) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "[E]pst_bus is error can not release wake locks");
        return;
    };

    if (hcc_bus_wakelock_active(pst_bus)) {
#if ((KERNEL_VERSION(2, 6, 37) <= LINUX_VERSION_CODE) && (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION))
        oal_print_mpxx_log(MPXX_LOG_INFO, "[E]We still hold %s   %lu wake locks, Now release all",
                           pst_bus->st_bus_wakelock.st_wakelock.name,
                           pst_bus->st_bus_wakelock.lock_count);
#endif
        declare_dft_trace_key_info("wlan_wakelock_error_hold", OAL_DFT_TRACE_EXCEP);
        pst_bus->st_bus_wakelock.lock_count = 1;
        hcc_bus_wake_unlock(pst_bus);
    }
}

OAL_STATIC int32_t hcc_bus_resource_alloc(hcc_bus *pst_bus)
{
    int32_t ret;
    uint8_t name[WAKELOCK_NAME_LEN];

    if (oal_warn_on(pst_bus == NULL)) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "pst_bus is null,alloc fail ");
        return -OAL_EFAIL;
    };

    ret = snprintf_s(name, sizeof(name), sizeof(name) - 1, "wlan_bus_lock/%s:%u",
                     hcc_bus_get_bus_type_str(pst_bus->bus_type), pst_bus->dev_id);
    if (ret < 0) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "wakelock name formate err\n");
        return ret;
    }
    /* 接口内部会copy name */
    oal_wake_lock_init(&pst_bus->st_bus_wakelock, name);

    pst_bus->st_bus_wakelock.debug = g_hcc_bus_wakelock_debug;

    oal_init_completion(&pst_bus->st_device_ready);

    ret = snprintf_s(name, sizeof(name), sizeof(name) - 1, "wlan_bus_rx/%s:%u",
                     hcc_bus_get_bus_type_str(pst_bus->bus_type), pst_bus->dev_id);
    if (ret < 0) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "bus name formate err\n");
        oal_wake_lock_exit(&pst_bus->st_bus_wakelock);
        return ret;
    }

    /* create thread for gpio rx data in interrupt handler */
    pst_bus->pst_rx_tsk = oal_thread_create(hcc_bus_rxdata_thread, (hcc_bus *)pst_bus,
                                            &pst_bus->rx_sema, name, OAL_BUS_RX_THREAD_POLICY,
                                            OAL_BUS_RXDATA_THREAD_PRIORITY, g_cpu_id);
    if (pst_bus->pst_rx_tsk == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "[SDIO][ERROR]failed to create rx data thread");
        oal_wake_lock_exit(&pst_bus->st_bus_wakelock);
        return -OAL_EFAIL;
    }
    mutex_init(&pst_bus->rx_transfer_lock);

    oal_atomic_set(&g_wakeup_dev_wait_ack, 0);
    oal_atomic_set(&g_bus_powerup_dev_wait_ack, 0);

    sema_init(&pst_bus->sr_wake_sema, 1);

    /* init exception work */
    oal_spin_lock_init(&pst_bus->bus_excp_lock);
    oal_init_work(&pst_bus->bus_excp_worker, hcc_bus_exception_handler);
    oal_wake_lock_init(&pst_bus->bus_excp_wlock, hcc_bus_get_bus_type_str(pst_bus->bus_type));

    hcc_bus_message_register(pst_bus, D2H_MSG_DEVICE_PANIC, hcc_bus_device_panic_callback, pst_bus);

    hcc_bus_message_register(pst_bus, D2H_MSG_WLAN_READY, hcc_bus_device_init_ready, pst_bus);

    return OAL_SUCC;
}

OAL_STATIC void hcc_bus_resource_free(hcc_bus *pst_bus)
{
    char *name = NULL;

    if (oal_unlikely(pst_bus == NULL)) {
        oal_warn_on(1);
        return;
    }

    if (pst_bus->pst_rx_tsk != NULL) {
        oal_thread_stop(pst_bus->pst_rx_tsk, &pst_bus->rx_sema);
        pst_bus->pst_rx_tsk = NULL;
    }
    mutex_destroy(&pst_bus->rx_transfer_lock);
#if ((KERNEL_VERSION(2, 6, 37) <= LINUX_VERSION_CODE) && (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION))
    name = (char *)pst_bus->st_bus_wakelock.st_wakelock.name;
#endif
    oal_wake_lock_exit(&pst_bus->st_bus_wakelock);

    oal_wake_lock_exit(&pst_bus->bus_excp_wlock);
#if ((KERNEL_VERSION(2, 6, 37) <= LINUX_VERSION_CODE) && (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION))
    oal_free((void *)name);
#endif
}

OAL_STATIC void hcc_dev_pps_count_timeout(oal_timeout_func_para_t arg)
{
    hcc_bus_dev *pst_bus_dev = oal_get_timer_container(pst_bus_dev, arg, bus_pps_timer);

    if (oal_warn_on(pst_bus_dev == NULL)) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "bus dev is null");
        return;
    }

    if (!hcc_bus_auto_sched_is_support(pst_bus_dev->dev_id)) {
        return;
    }

    hcc_bus_performance_core_schedule(pst_bus_dev->dev_id);

    oal_timer_start(&pst_bus_dev->bus_pps_timer, HCC_BUS_PPS_COUNT_TIMEOUT);
}

#ifndef _PRE_PLAT_FEATURE_MULTI_HCC
OAL_STATIC int32_t hcc_get_pcie_switch_flag(void)
{
    hcc_bus_dev *pst_bus_dev;

    pst_bus_dev = hcc_get_bus_dev(HCC_EP_WIFI_DEV);
    if (pst_bus_dev == NULL) {
        return 0;
    }

    return pst_bus_dev->pcie_bugfix_enable;
}
#endif

OAL_STATIC int32_t hcc_set_pcie_switch_flag(int32_t flag)
{
    hcc_bus_dev *pst_bus_dev;

    pst_bus_dev = hcc_get_bus_dev(HCC_EP_WIFI_DEV);
    if (pst_bus_dev == NULL) {
        return -OAL_ENODEV;
    }

    pst_bus_dev->pcie_bugfix_enable = (flag == 0) ? 0 : 1;

    return 0;
}

void hcc_dev_exit(void)
{
    int32_t i;
    hcc_bus_dev *pst_bus_dev = NULL;

    for (i = 0; i < (int32_t)oal_array_size(g_bus_dev_res); i++) {
        pst_bus_dev = &g_bus_dev_res[i];

        hcc_bus_performance_core_exit(pst_bus_dev->dev_id);

        if (pst_bus_dev->hcc != NULL) {
            hcc_module_exit(pst_bus_dev->hcc);
            pst_bus_dev->hcc = NULL;
        }
    }

#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    wlan_pm_unregister_notifier(&g_hcc_bus_pm_notifier);
#endif
}

#define HCC_BUS_INI_BUFF_SIZE  100
OAL_STATIC void hcc_bus_config_init(void)
{
    char buff[HCC_BUS_INI_BUFF_SIZE]; /* 因编译原因，暂不支持用const变量定义数组大小 */

    memset_s(buff, sizeof(buff), 0, sizeof(buff));
    if (get_cust_conf_string(INI_MODU_PLAT, "g_hcc_exception_enable", buff, sizeof(buff) - 1) == INI_SUCC) {
        if (!oal_strncmp("enable", buff, OAL_STRLEN("enable"))) {
            g_hcc_exception_enable = 1;
        } else if (!strncmp("disable", buff, OAL_STRLEN("disable"))) {
            g_hcc_exception_enable = 0;
        } else {
            oal_print_mpxx_log(MPXX_LOG_WARN, "g_hcc_exception_enable:%s", buff);
        }

        oal_print_mpxx_log(MPXX_LOG_INFO, "hcc_exception_enable %s", g_hcc_exception_enable ? "enable" : "disable");
    }
}

int32_t hcc_dev_init(void)
{
    int32_t i;
    int32_t ret;
    hcc_bus_dev *pst_bus_dev = NULL;
#ifdef _PRE_PLAT_FEATURE_MULTI_HCC
    hcc_bus_dev *devs = g_bus_devs.dev_list;
    int32_t dev_num = g_bus_devs.dev_num;
#else
    hcc_bus_dev *devs = g_bus_dev_res;
    int32_t dev_num = (int32_t)oal_array_size(g_bus_dev_res);
#endif
    oal_print_mpxx_log(MPXX_LOG_INFO, "hcc_dev_init we had %d devs", dev_num);

#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    wlan_pm_register_notifier(&g_hcc_bus_pm_notifier);
#endif

    for (i = 0; i < dev_num; i++) {
        pst_bus_dev = &devs[i];
        ret = hcc_select_bus(pst_bus_dev->dev_id, pst_bus_dev->init_bus_type);
        if (ret != OAL_SUCC) {
            oal_print_mpxx_log(MPXX_LOG_ERR, "bus dev %s select bus failed, ret=%d", pst_bus_dev->name, ret);
            goto hcc_init_fail;
        }

        pst_bus_dev->hcc = hcc_module_init(pst_bus_dev);
        if (pst_bus_dev->hcc == NULL) {
            oal_print_mpxx_log(MPXX_LOG_ERR, "alloc hcc failed!");
            goto hcc_init_fail;
        }

        hcc_bus_performance_core_init(pst_bus_dev->dev_id);

        oal_print_mpxx_log(MPXX_LOG_INFO, "hcc init dev %d succ", pst_bus_dev->dev_id);
    }

    hcc_bus_config_init();

    return OAL_SUCC;

hcc_init_fail:
    hcc_dev_exit();
    return -OAL_EFAIL;
}

#ifdef _PRE_SUSPORT_OEMINFO
void resume_wlan_wakeup_host_gpio(void)
{
    int32_t ret;
    hcc_bus_dev *pst_bus_dev = NULL;
    uint32_t dev_id = HCC_EP_WIFI_DEV;
    int32_t phy_gpio;

    pst_bus_dev = hcc_get_bus_dev(dev_id);
    if (pst_bus_dev == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "pst_bus_dev get fail:\n");
        return;
    }

    conn_irq_unregister(W_WKUP_HOST, pst_bus_dev);
    phy_gpio = conn_get_gpio_number_by_type(W_WKUP_HOST);
    oal_gpio_free(phy_gpio);

    ret = gpio_request(phy_gpio, PROC_NAME_GPIO_WLAN_WAKEUP_HOST);
    if (ret != 0) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "req gpio fail wl_wakeup_h = %d\n",
            phy_gpio);
        return;
    }
    oal_print_mpxx_log(MPXX_LOG_INFO, "req gpio ok wl_wakeup_h = %d\n", phy_gpio);
    gpio_direction_input(phy_gpio);

    conn_irq_register(W_WKUP_HOST, hcc_bus_wlan_gpio_irq, pst_bus_dev);
}
#endif

#ifndef _PRE_PLAT_FEATURE_MULTI_HCC
OAL_STATIC int32_t oal_load_dev(void)
{
    int32_t load_sdio, load_pcie;

    load_sdio = oal_wifi_platform_load_sdio();
    if (load_sdio != OAL_SUCC) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "load sdio failed ret=%d", load_sdio);
        return load_sdio;
    }

    load_pcie = oal_wifi_platform_load_pcie();
    if (load_pcie != OAL_SUCC) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "load pcie failed ret=%d", load_pcie);
        oal_wifi_platform_unload_sdio();
        return load_pcie;
    }

    return OAL_SUCC;
}
#endif

#ifndef _PRE_PLAT_FEATURE_MULTI_HCC
OAL_STATIC int32_t oal_load_dev_retry(void)
{
    int32_t load_sdio, load_pcie;
    hcc_bus_dev *pst_bus_dev;

    pst_bus_dev = hcc_get_bus_dev(HCC_EP_WIFI_DEV);
    if (pst_bus_dev == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "hcc_get_bus_dev fail!\n");
        return -OAL_ENODEV;
    }

    load_pcie = oal_wifi_platform_load_pcie();
    if (load_pcie == OAL_SUCC) {
        return OAL_SUCC;
    }

    /* pcie 枚举失败，尝试使用sdio */
    load_sdio = oal_wifi_platform_load_sdio();
    if (load_sdio == OAL_SUCC) {
        oal_print_mpxx_log(MPXX_LOG_INFO, "hisi wifi bus pcie fail, sdio succ");
        hcc_set_pcie_switch_flag(0);
        pst_bus_dev->init_bus_type = HCC_BUS_SDIO;
#if defined(CONFIG_HUAWEI_OHOS_DSM) || defined(CONFIG_HUAWEI_DSM)
        hw_mpxx_dsm_client_notify(SYSTEM_TYPE_PLATFORM, DSM_PCIE_SWITCH_SDIO_SUCC,
            "probe:pcie switch to sdio succ\n");
#endif
    } else {
        oal_print_mpxx_log(MPXX_LOG_ERR, "hisi wifi bus pcie and sdio all fail");
#if defined(CONFIG_HUAWEI_OHOS_DSM) || defined(CONFIG_HUAWEI_DSM)
        hw_mpxx_dsm_client_notify(SYSTEM_TYPE_PLATFORM, DSM_PCIE_SWITCH_SDIO_FAIL,
            "probe:pcie switch to sdio fail\n");
#endif
    }

    return load_sdio;
}
#endif

#ifdef _PRE_PLAT_FEATURE_MULTI_HCC
int32_t oal_wifi_platform_load_dev(void)
{
    int32_t ret, i, bus_cap;
    uint32_t usb_cap = OAL_FALSE;
    uint32_t pcie_cap = OAL_FALSE;

    ret = hcc_bus_param_init(&g_bus_devs);
    if (ret != OAL_SUCC) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "hisi bus param init fail");
        return ret;
    }
    for (i = 0; i < g_bus_devs.dev_num; i++) {
        bus_cap = g_bus_devs.dev_list[i].bus_cap;
        if (bus_cap & (1 << HCC_BUS_PCIE)) {
            pcie_cap = OAL_TRUE;
        }
#ifdef _PRE_PLAT_FEATURE_USB
        if (bus_cap & (1 << HCC_BUS_USB)) {
            usb_cap = OAL_TRUE;
        }
#endif
    }
    if (usb_cap == OAL_TRUE) {
        ret = oal_wifi_platform_load_usb();
        if (ret != OAL_SUCC) {
            oal_print_mpxx_log(MPXX_LOG_ERR, "load usb failed ret=%d", ret);
            return ret;
        }
    }
    if (pcie_cap == OAL_TRUE) {
        ret = oal_wifi_platform_load_pcie();
        if (ret != OAL_SUCC) {
            oal_print_mpxx_log(MPXX_LOG_ERR, "load pcie failed ret=%d", ret);
            return ret;
        }
    }
    return ret;
}
#else
/* 枚举接口设备 */
int32_t oal_wifi_platform_load_dev(void)
{
    if (hcc_get_pcie_switch_flag() != 1) {
        oal_print_mpxx_log(MPXX_LOG_INFO, "hisi wifi bus pcie switch disable");
        return oal_load_dev();
    }
    oal_print_mpxx_log(MPXX_LOG_INFO, "hisi wifi bus pcie switch enable");
    return oal_load_dev_retry();
}
#endif

/* 卸载接口设备 */
void oal_wifi_platform_unload_dev(void)
{
    oal_wifi_platform_unload_pcie();
    oal_wifi_platform_unload_sdio();
}

#else
int32_t hcc_get_pcie_switch_flag(void)
{
    return OAL_SUCC;
}

int32_t hcc_set_pcie_switch_flag(int32_t flag)
{
    return OAL_SUCC;
}
void hcc_dev_exit(void)
{
}

int32_t hcc_dev_init(void)
{
    /* UT/ST工程使用，正式版本不使用 */
#if (_PRE_TEST_MODE == _PRE_TEST_MODE_ST)
    hcc_bus_dev *pst_bus_dev = NULL;
#if (_PRE_PRODUCT_ID == _PRE_PRODUCT_ID_GF61_HOST)
    pst_bus_dev = hcc_get_get_one_alive_bus_dev();
    pst_bus_dev->cur_bus = NULL;
#else
    pst_bus_dev = &g_bus_dev_res[HCC_EP_WIFI_DEV];
#endif
    pst_bus_dev->hcc = hcc_module_init(pst_bus_dev);
#endif
    return OAL_SUCC;
}

int32_t hcc_bus_resource_alloc(hcc_bus *pst_bus)
{
    oal_reference(pst_bus);
    return OAL_SUCC;
}

void hcc_bus_resource_free(hcc_bus *pst_bus)
{
    oal_reference(pst_bus);
}

int32_t oal_register_gpio_flowctrl_intr(hcc_bus_dev *pst_bus_dev)
{
    oal_reference(pst_bus_dev);
    return OAL_SUCC;
}

int32_t oal_register_gpio_intr(hcc_bus_dev *pst_bus_dev)
{
    oal_reference(pst_bus_dev);
    return OAL_SUCC;
}

void oal_unregister_gpio_flowctrl_intr(hcc_bus_dev *pst_bus_dev)
{
    oal_reference(pst_bus_dev);
}

void oal_unregister_gpio_intr(hcc_bus_dev *pst_bus_dev)
{
    oal_reference(pst_bus_dev);
}

void hcc_bus_exception_handler(oal_work_stru *work)
{
    oal_reference(work);
}

int32_t oal_trigger_bus_exception(hcc_bus *hi_bus, int32_t is_sync)
{
    oal_reference(hi_bus);
    oal_reference(is_sync);
    return OAL_SUCC;
}

/* 枚举接口设备 */
int32_t oal_wifi_platform_load_dev(void)
{
    return OAL_SUCC;
}

/* 卸载接口设备 */
void oal_wifi_platform_unload_dev(void)
{
}
#endif

uint32_t hcc_bus_dump_mem_check(hcc_bus *hi_bus)
{
    oal_reference(hi_bus);
    return !!g_bus_dump_mem_flag;
}

oal_module_symbol(hcc_bus_dump_mem_check);

/*
 * Prototype    : hcc_bus_message_register
 * Description  : msg irq
 * Input        : struct oal_sdio *hi_sdio
 */
int32_t hcc_bus_message_register(hcc_bus* hi_bus, uint8_t msg, hcc_bus_msg_rx cb, void* data)
{
    if (hi_bus == NULL || msg >= D2H_MSG_COUNT) {
        return -OAL_EFAIL;
    }
    hi_bus->msg[msg].msg_rx = cb;
    hi_bus->msg[msg].data = data;
    return OAL_SUCC;
}

/*
 * Prototype    : oal_sdio_message_unregister
 * Description  : msg irq
 * Input        : struct oal_sdio *hi_sdio
 */
void hcc_bus_message_unregister(hcc_bus* hi_bus, uint8_t msg)
{
    if (hi_bus == NULL || msg >= D2H_MSG_COUNT) {
        return;
    }
    hi_bus->msg[msg].msg_rx = NULL;
    hi_bus->msg[msg].data = NULL;
}

int32_t hcc_bus_transfer_rx_register(hcc_bus *hi_bus, void *data, hcc_bus_data_rx rx)
{
    if (oal_warn_on(hi_bus == NULL)) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "bus is null, register rx bus fail\n");
        return OAL_FAIL;
    }
    hi_bus->bus_ops.rx = rx;
    hi_bus->bus_ops_data = data;
    return OAL_SUCC;
}

/*
 * Prototype    : oal_sdio_transfer_rx_unregister
 * Description  : msg irq
 * Input        : hisdio_rx rx
 */
void hcc_bus_transfer_rx_unregister(hcc_bus *hi_bus)
{
    if (oal_unlikely(hi_bus == NULL)) {
        oal_warn_on(1);
        return;
    }
    hi_bus->bus_ops.rx = NULL;
    hi_bus->bus_ops_data = NULL;
}

int32_t hcc_transfer_rx_register(struct hcc_handler *hcc, void *data, hcc_bus_data_rx rx)
{
    int32_t flag = 0;
    int32_t ret = OAL_SUCC;
    oal_uint irqsave;
    oal_dlist_head_stru *pst_entry = NULL;
    hcc_bus *pst_bus_tmp = NULL;
    if (oal_unlikely(hcc == NULL)) {
        oal_warn_on(1);
        return OAL_FAIL;
    }
    oal_spin_lock_irq_save(&g_hcc_bus_res_lock, &irqsave);
    oal_dlist_search_for_each(pst_entry, &g_hcc_bus_res_hdr)
    {
        pst_bus_tmp = oal_dlist_get_entry(pst_entry, hcc_bus, list);
        if (pst_bus_tmp->bus_dev == hcc->bus_dev) {
            /* 注册在当前设备上的所有BUS 都需要注册 */
            ret = hcc_bus_transfer_rx_register(pst_bus_tmp, data, rx);
            if (ret != OAL_SUCC) {
                oal_spin_unlock_irq_restore(&g_hcc_bus_res_lock, &irqsave);
                oal_print_mpxx_log(MPXX_LOG_ERR, "register rx bus %d failed, ret=%d", pst_bus_tmp->bus_id, ret);
                return ret;
            }
            flag++;
        }
    }
    oal_spin_unlock_irq_restore(&g_hcc_bus_res_lock, &irqsave);

    if (flag) {
        return OAL_SUCC;
    }
    return -OAL_ENODEV;
}

uint32_t hcc_get_max_trans_size(struct hcc_handler *hcc)
{
    if (oal_warn_on(hcc == NULL)) {
        return 0;
    }

    if (oal_warn_on(hcc->bus_dev == NULL)) {
        return 0;
    }

    return hcc_bus_get_max_trans_size(hcc->bus_dev->cur_bus);
}

/*
 * Prototype    :oal_thread_create
 * Description  : create thread
 */
struct task_struct* oal_thread_create(int (*threadfn)(void* data),
                                      void* data,
                                      struct semaphore* sema_sync,
                                      const char* namefmt,
                                      uint32_t policy,
                                      int32_t prio,
                                      int32_t cpuid)
{
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 9, 0)
    int ret;
    struct sched_param param;
#endif
    struct task_struct *tsk = NULL;

    /* create thread for gpio rx data in interrupt handler */
    if (sema_sync != NULL) {
        sema_init(sema_sync, 0);
    }

    tsk = kthread_create(threadfn, data, "%s", namefmt);
    if (oal_is_err_or_null(tsk)) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "failed to run thread:%s, tsk=%d", namefmt, PTR_ERR_OR_ZERO(tsk));
        return NULL;
    }
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 9, 0)
    /* set thread priority and schedule policy */
    param.sched_priority = prio;
    ret = sched_setscheduler(tsk, policy, &param);
    if (oal_unlikely(ret)) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "%s sched_setscheduler failed! ret =%d, prio=%d", namefmt, ret, prio);
    }
#else
    if (policy == SCHED_FIFO || policy == SCHED_RR) {
        if (prio <= 1) {
            sched_set_fifo_low(tsk);
        } else {
            sched_set_fifo(tsk);
        }
    }
#endif

    if (cpuid >= 0) {
        oal_kthread_bind(tsk, cpuid);
    } else {
        oal_print_mpxx_log(MPXX_LOG_INFO, "did not bind cpu...");
    }
    wake_up_process(tsk);
    return tsk;
#else
    return NULL;
#endif
}

oal_module_symbol(oal_thread_create);

/*
 * Prototype    : oal_thread_stop
 * Description  : create thread
 */
void oal_thread_stop(struct task_struct *tsk, struct semaphore *sema_sync)
{
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    /* sema_sync can be NULL */
    /* create thread for gpio rx data in interrupt handler */
    send_sig(SIGTERM, tsk, 1);
    kthread_stop(tsk);
#endif
}

oal_module_symbol(oal_thread_stop);

void oal_set_thread_property(struct task_struct *p, int policy,
#ifdef _PRE_LINUX_TEST
                             const struct oal_sched_param_stru *param,
#else
                             const struct sched_param *param,
#endif
                             long nice)
{
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    if (oal_warn_on(p == NULL) || (param == NULL)) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "param set thread scheduler policy fail, para is null");
        return;
    };

    oal_print_mpxx_log(MPXX_LOG_INFO, "set thread scheduler policy %d", policy);
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 9, 0)
    if (sched_setscheduler(p, policy, (struct sched_param *)param)) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "[Error]set scheduler failed! %d", policy);
    }
#else
    if (policy == SCHED_FIFO || policy == SCHED_RR) {
        if (param->sched_priority <= 1) {
            sched_set_fifo_low(p);
        } else {
            sched_set_fifo(p);
        }
    }
#endif
    if (policy != SCHED_FIFO && policy != SCHED_RR) {
        oal_print_mpxx_log(MPXX_LOG_INFO, "set thread scheduler nice %ld", nice);
        set_user_nice(p, nice);
    }
#endif
}

oal_module_symbol(oal_set_thread_property);

/* Try to dump device mem, controlled by flag sdio_dump_mem_flag */
void hcc_bus_try_to_dump_device_mem(hcc_bus *hi_bus, int32_t is_sync)
{
    if (oal_warn_on(hi_bus == NULL)) {
        return;
    }

    if (!hcc_bus_dump_mem_check(hi_bus)) {
        return;
    }

    oal_print_mpxx_log(MPXX_LOG_INFO, "Try to dump device mem!");
    if (oal_trigger_bus_exception(hi_bus, is_sync) != OAL_TRUE) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "hcc_bus_try_to_dump_device_mem fail\n");
    }
}

oal_module_symbol(hcc_bus_try_to_dump_device_mem);
oal_module_symbol(hcc_bus_transfer_rx_register);
oal_module_symbol(hcc_bus_flowctrl_init);
