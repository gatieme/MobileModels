/**
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 *
 * Description:MPxx & 118x pcie pm interface file, used to unload the chip
 * Author: @CompanyNameTag
 */

#ifdef _PRE_PLAT_FEATURE_GF6X_PCIE
#define MPXX_LOG_MODULE_NAME     "[PCIEL]"
#define MPXX_LOG_MODULE_NAME_VAR pciel_loglevel
#define HISI_LOG_TAG               "[PCIEL]"

#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
#include <linux/delay.h>
#include <linux/device.h>
#include <linux/err.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/module.h>
#include <linux/pci.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <linux/types.h>
#include <linux/workqueue.h>
#include "board.h"
#include "plat_pm.h"

#endif
#include "ete_host.h"
#include "external/lpcpu_feature.h"
#include "hisi_ini.h"
#include "oal_ext_if.h"
#include "oal_hcc_host_if.h"
#include "oal_net.h"
#include "oal_util.h"
#include "oam_ext_if.h"
#include "pcie_firmware.h"
#include "oal_pcie_interface.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_OAL_PCIE_LINUX_C

#define WIFI_POWERUP_DONE_TIMEOUT 2000
#define HOST_WAIT_DEV_DELAY_TIMEOUT 5000

int32_t g_rc_idx = 0;
oal_debug_module_param(g_rc_idx, int, S_IRUGO | S_IWUSR);
#ifdef _PRE_PLAT_FEATURE_HI110X_DUAL_PCIE
int32_t g_rc_idx_dual = 1;
oal_debug_module_param(g_rc_idx_dual, int, S_IRUGO | S_IWUSR);
#endif
int32_t g_pcie_print_once = 0;
oal_debug_module_param(g_pcie_print_once, int, S_IRUGO | S_IWUSR);

int32_t g_pcie_aspm_enable = 1;
oal_debug_module_param(g_pcie_aspm_enable, int, S_IRUGO | S_IWUSR);

int32_t g_pcie_performance_mode = 0;
oal_debug_module_param(g_pcie_performance_mode, int, S_IRUGO | S_IWUSR);
/* WCPU芯片唤醒阶段是否自动关闭L1降低单包延迟 */
int32_t g_pcie_auto_disable_aspm = 0;
oal_debug_module_param(g_pcie_auto_disable_aspm, int, S_IRUGO | S_IWUSR);

int32_t oal_pcie_set_loglevel(int32_t loglevel)
{
    int32_t ret = g_hipcie_loglevel;
    g_hipcie_loglevel = loglevel;
    return ret;
}

int32_t oal_pcie_set_mpxx_loglevel(int32_t loglevel)
{
    int32_t ret = MPXX_LOG_MODULE_NAME_VAR;
    MPXX_LOG_MODULE_NAME_VAR = loglevel;
    return ret;
}

void oal_pcie_rx_netbuf_hdr_init(oal_pci_dev_stru *hwdev, oal_netbuf_stru *pst_netbuf)
{
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    if (g_pcie_dma_data_rx_hdr_init != 0) {
        memset_s((void *)oal_netbuf_data(pst_netbuf), oal_netbuf_len(pst_netbuf), 0xff, oal_netbuf_len(pst_netbuf));
    }
    /* 申请rx_buf时：利用cpu，赋初值 */
    *(volatile uint32_t *)oal_netbuf_data(pst_netbuf) = PCIE_RX_TRANS_FLAG;

#endif
}

OAL_STATIC int32_t oal_pcie_enable_single_device(oal_pci_dev_stru *pst_pcie_dev, struct pci_saved_state **default_state)
{
    u16 old_cmd = 0;
    int32_t ret;

    if (oal_warn_on(*default_state == NULL)) {
        oal_io_print("pcie had't any saved state!\n");
        return -OAL_ENODEV;
    }

    /*
     * Updated with pci_load_and_free_saved_state to compatible
     * with kernel 3.14 or higher
     */
    pci_load_and_free_saved_state(pst_pcie_dev, default_state);

    /* Update default state */
    *default_state = pci_store_saved_state(pst_pcie_dev);

    pci_restore_state(pst_pcie_dev);

    ret = oal_pci_enable_device(pst_pcie_dev);
    if (ret) {
        oal_io_print("enable device failed!ret=%d\n", ret);
        pci_disable_device(pst_pcie_dev);
    } else {
        pci_set_master(pst_pcie_dev);
    }

    pci_read_config_word(pst_pcie_dev, PCI_COMMAND, &old_cmd);
    oal_io_print("PCI_COMMAND:0x%x\n", old_cmd);

    return ret;
}

OAL_STATIC int32_t oal_pcie_save_resource(oal_pci_dev_stru *pst_pcie_dev, struct pci_saved_state **default_state)
{
    int32_t ret = OAL_SUCC;

    pci_save_state(pst_pcie_dev);
    oal_io_print("save resource\n");

    if (*default_state != NULL) {
        /* There is already exist pcie state */
        struct pci_saved_state *pst_state = *default_state;
        *default_state = NULL;
        kfree(pst_state);
        oal_io_print("default state already exist, free first\n");
    }

    *default_state = pci_store_saved_state(pst_pcie_dev);
    if (oal_unlikely(*default_state == NULL)) {
        oal_pci_disable_device(pst_pcie_dev);
        return -OAL_ENOMEM;
    }
    return ret;
}

OAL_STATIC int32_t oal_pcie_enable_device(oal_pcie_linux_res *pst_pci_lres)
{
    if (oal_warn_on(pst_pci_lres == NULL)) {
        return -OAL_ENOMEM;
    }

    if (oal_warn_on(pst_pci_lres->comm_res->pcie_dev == NULL)) {
        return -OAL_ENODEV;
    }
    return oal_pcie_enable_single_device(pst_pci_lres->comm_res->pcie_dev, &pst_pci_lres->comm_res->default_state);
}

int32_t oal_pcie_save_default_resource(oal_pcie_linux_res *pst_pci_lres)
{
    if (oal_warn_on(pst_pci_lres == NULL)) {
        return -OAL_EINVAL;
    }

    if (oal_warn_on(pst_pci_lres->comm_res->pcie_dev == NULL)) {
        return -OAL_ENODEV;
    }

    return oal_pcie_save_resource(pst_pci_lres->comm_res->pcie_dev, &pst_pci_lres->comm_res->default_state);
}

int32_t oal_pcie_device_wakeup_handler(const void *data)
{
    oal_reference(data);
    board_host_wakeup_dev_set(1);
    pci_print_log(PCI_LOG_INFO, "pcie wakeup device control, pull up gpio");
    return 0;
}

uint32_t oal_pcie_is_master_ip(oal_pci_dev_stru *pst_pci_dev)
{
#ifdef _PRE_PLAT_FEATURE_HI110X_DUAL_PCIE
    oal_pcie_linux_res *pst_pci_lres = oal_get_default_pcie_handler();
    return ((pst_pci_dev == pst_pci_lres->comm_res->pcie_dev) ? OAL_TRUE : OAL_FALSE);
#else
    return OAL_TRUE;
#endif
}

int32_t oal_pcie_get_pcie_rc_idx(oal_pci_dev_stru *pst_pci_dev)
{
#ifdef _PRE_PLAT_FEATURE_HI110X_DUAL_PCIE
    return (oal_pcie_is_master_ip(pst_pci_dev) == OAL_TRUE ? g_rc_idx : g_rc_idx_dual);
#else
    return g_rc_idx;
#endif
}
int32_t oal_pcie_sr_para_check(oal_pcie_linux_res *pst_pci_lres, hcc_bus **pst_bus, struct hcc_handler **pst_hcc)
{
    if (pst_pci_lres == NULL) {
        oal_io_print("lres is null\n");
        return -OAL_ENODEV;
    }

    *pst_bus = pst_pci_lres->pst_bus;
    if (*pst_bus == NULL) {
        oal_io_print("sr pst_bus is null\n");
        return -OAL_EFAIL;
    }

    if (hbus_to_dev(*pst_bus) == NULL) {
        oal_io_print("sr,pcie is not work...\n");
        return -OAL_ENODEV;
    }

    *pst_hcc = hbus_to_hcc(*pst_bus);
    if (*pst_hcc == NULL) {
        pci_print_log(PCI_LOG_WARN, "pcie dev's hcc handler is null!");
        return -OAL_ENODEV;
    }

    if (*pst_bus != hdev_to_hbus(hbus_to_dev(*pst_bus))) {
        /* pcie非当前接口 */
        oal_print_mpxx_log(MPXX_LOG_INFO, "pcie is not current bus, return");
        return -OAL_ENODEV;
    }

    if (oal_atomic_read(&(*pst_hcc)->state) != HCC_ON) {
        pci_print_log(PCI_LOG_INFO, "wifi is closed");
        return -OAL_ENODEV;
    }

    return OAL_SUCC;
}

// 判断pcie suspend之前是否持锁
int32_t oal_pcie_wakelock_active(hcc_bus *pst_bus)
{
    struct wlan_pm_s *pst_wlan_pm = wlan_pm_get_drv();
    if (pst_wlan_pm != NULL) {
        if (oal_wakelock_active(&pst_wlan_pm->st_pm_wakelock)) {
            pci_print_log(PCI_LOG_INFO, "st_pm_wakelock active");
            return OAL_TRUE;
        }
    }

    if (hcc_bus_wakelock_active(pst_bus)) {
        pci_print_log(PCI_LOG_INFO, "st_bus_wakelock active");
        return OAL_TRUE;
    }

    return OAL_FALSE;
}

int32_t oal_pcie_get_state(hcc_bus *pst_bus, uint32_t mask)
{
    oal_pcie_linux_res *pst_pci_lres;

    pst_pci_lres = (oal_pcie_linux_res *)pst_bus->data;
    oal_reference(pst_pci_lres);

    return OAL_TRUE;
}

void oal_enable_pcie_state(hcc_bus *pst_bus, uint32_t mask)
{
    oal_pcie_linux_res *pst_pci_lres;

    pst_pci_lres = (oal_pcie_linux_res *)pst_bus->data;
    oal_reference(pst_pci_lres);
}

void oal_disable_pcie_state(hcc_bus *pst_bus, uint32_t mask)
{
    oal_pcie_linux_res *pst_pci_lres;

    pst_pci_lres = (oal_pcie_linux_res *)pst_bus->data;
    oal_reference(pst_pci_lres);
}

int32_t oal_pcie_rx_netbuf(hcc_bus *pst_bus, oal_netbuf_head_stru *pst_head)
{
    oal_pcie_linux_res *pst_pci_lres;

    pst_pci_lres = (oal_pcie_linux_res *)pst_bus->data;
    oal_reference(pst_pci_lres);
    return OAL_SUCC;
}

int32_t oal_pcie_check_tx_param(hcc_bus *pst_bus, oal_netbuf_head_stru *pst_head, hcc_netbuf_queue_type qtype)
{
    oal_pcie_linux_res *pst_pci_lres = NULL;
    struct hcc_handler *pst_hcc = NULL;

    pst_pci_lres = (oal_pcie_linux_res *)pst_bus->data;
    if (oal_warn_on(pst_pci_lres == NULL)) {
        oal_io_print("pcie tx netbuf failed, lres is null\n");
        hcc_tx_netbuf_list_free(pst_head, hbus_to_hcc(pst_bus));
        return -OAL_ENODEV;
    }
    pst_hcc = hbus_to_hcc(pst_bus);
    if (pst_hcc == NULL) {
        pci_print_log(PCI_LOG_WARN, "pcie dev's hcc handler is null!");
        hcc_tx_netbuf_list_free(pst_head, pst_hcc);
        return -OAL_ENODEV;
    }

    if (oal_unlikely(oal_atomic_read(&pst_hcc->state) != HCC_ON)) {
        /* drop netbuf list, wlan close or exception */
        oal_print_mpxx_log(MPXX_LOG_INFO, "drop pcie netbuflist %u", oal_netbuf_list_len(pst_head));
        hcc_tx_netbuf_list_free(pst_head, pst_hcc);
        return -OAL_EFAIL;
    }

    return OAL_SUCC;
}

OAL_STATIC int32_t oal_pcie_send_message2dev(oal_pcie_linux_res *pst_pci_lres, uint32_t message)
{
    hcc_bus *pst_bus;
    int32_t ret;
    pst_bus = pst_pci_lres->pst_bus;

    if (oal_warn_on(pst_bus == NULL)) {
        return -OAL_ENODEV;
    }

    pci_print_log(PCI_LOG_DBG, "send msg to device [0x%8x]\n", (uint32_t)message);

    hcc_bus_wake_lock(pst_bus);
    ret = oal_pcie_send_message_to_dev(pst_pci_lres, message);
    hcc_bus_wake_unlock(pst_bus);

    return ret;
}

int32_t oal_pcie_send_msg(hcc_bus *pst_bus, uint32_t val)
{
    oal_pcie_linux_res *pst_pci_lres;

    pst_pci_lres = (oal_pcie_linux_res *)pst_bus->data;

    if (oal_warn_on(pst_pci_lres == NULL)) {
        return -OAL_ENODEV;
    }

    if (val >= H2D_MSG_COUNT) {
        oal_io_print("[Error]invaild param[%u]!\n", val);
        return -OAL_EINVAL;
    }

    return oal_pcie_send_message2dev(pst_pci_lres, (uint32_t)val);
}

/*
 * 功能描述  : 根据吞吐量与PPS门限自动指定CPU绑定
 * 1.日    期  : 2020年07月02日
 */
OAL_STATIC void oal_pcie_bindcpu_autoctl(oal_pcie_linux_res *pci_lres, oal_pci_dev_stru *pci_dev, int32_t is_bind)
{
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
#ifdef _PRE_HISI_BINDCPU
    oal_pcie_bindcpu_cfg *bindcpu_cfg = (oal_pcie_bindcpu_cfg *)&is_bind;
    struct cpumask all_cpus, fast_cpus;
    cpumask_setall(&all_cpus);
    external_get_fast_cpus(&fast_cpus);

    /* 线程允许绑核, 判定PCIE补内存线程绑核 */
    if (bindcpu_cfg->thread_cmd && pci_lres->ep_res.pst_rx_hi_task != NULL) {
        if (bindcpu_cfg->is_bind) {
            /* 中断所在核会影响线程迁移 */
            oal_cpumask_clear_cpu(cpumask_first(&fast_cpus), &fast_cpus);
            set_cpus_allowed_ptr(pci_lres->ep_res.pst_rx_hi_task, &fast_cpus);
        } else {
            oal_cpumask_clear_cpu(cpumask_first(&all_cpus), &all_cpus);
            set_cpus_allowed_ptr(pci_lres->ep_res.pst_rx_hi_task, &all_cpus);
        }
        oal_print_mpxx_log(MPXX_LOG_INFO, "pcie rx task thread to 0x%lx",
                           (bindcpu_cfg->is_bind ? cpumask_bits(&fast_cpus)[0] : cpumask_bits(&all_cpus)[0]));
    }
#endif
#endif
}

/*
 * 功能描述  : 根据用户命令指定CPU绑定
 * 1.日    期  : 2020年07月02日
 *   修改内容  : 新生成函数
 */
OAL_STATIC void oal_pcie_bindcpu_userctl(oal_pcie_linux_res *pci_lres, oal_pci_dev_stru *pci_dev, uint8_t irq_cpu,
                                         uint8_t thread_cmd)
{
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
#ifdef _PRE_HISI_BINDCPU
    struct cpumask thread_cpu_mask;
#endif

#if defined(CONFIG_NR_CPUS) && defined(_PRE_HISI_BINDCPU)
    oal_print_mpxx_log(MPXX_LOG_DBG, "pcie bindcpu irq =%u, bind to cpu %d", pci_dev->irq, irq_cpu);
    irq_set_affinity_hint(pci_dev->irq, cpumask_of(irq_cpu));
#endif

#ifdef _PRE_HISI_BINDCPU
    if (pci_lres->ep_res.pst_rx_hi_task) {
        thread_cpu_mask = *((struct cpumask *)&thread_cmd);
        if (irq_cpu >= OAL_BUS_HPCPU_NUM) {
            /* 中断所在核会影响线程迁移 */
            oal_cpumask_clear_cpu(irq_cpu, &thread_cpu_mask);
        }
        oal_print_mpxx_log(MPXX_LOG_DBG, "pst_rx_hi_task bind to cpu[0x%x]", thread_cmd);
        set_cpus_allowed_ptr(pci_lres->ep_res.pst_rx_hi_task, &thread_cpu_mask);
    }
#endif
#endif
}

int32_t oal_pcie_bindcpu(hcc_bus *pst_bus, uint32_t chan, int32_t is_bind)
{
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    oal_pcie_bindcpu_cfg bindcpu_cfd = *(oal_pcie_bindcpu_cfg *)&is_bind;
    oal_pcie_linux_res *pst_pci_lres = NULL;
    oal_pci_dev_stru *pst_pci_dev = NULL;

    pst_pci_lres = (oal_pcie_linux_res *)pst_bus->data;
    if (pst_pci_lres == NULL) {
        return OAL_SUCC;
    }

    pst_pci_dev = pst_pci_lres->comm_res->pcie_dev;
    if (pst_pci_dev == NULL) {
        return OAL_SUCC;
    }

    if (bindcpu_cfd.is_userctl == OAL_TRUE) {
        /* 根据用户命令绑定CPU */
        oal_pcie_bindcpu_userctl(pst_pci_lres, pst_pci_dev, bindcpu_cfd.irq_cpu, bindcpu_cfd.thread_cmd);
    } else {
        /* 根据吞吐量与PPS门限自动绑定CPU */
        oal_pcie_bindcpu_autoctl(pst_pci_lres, pst_pci_dev, is_bind);
    }
#endif
    return OAL_SUCC;
}

int32_t oal_pcie_get_trans_count(hcc_bus *hi_bus, uint64_t *tx, uint64_t *rx)
{
    oal_pcie_linux_res *pst_pci_lres = (oal_pcie_linux_res *)hi_bus->data;
    return oal_pcie_get_host_trans_count(pst_pci_lres, tx, rx);
}

int32_t oal_pcie_deinit(hcc_bus *pst_bus)
{
    return OAL_SUCC;
}

/* mp16 cs2 to be deleted: disable group2 cputrace */
#define DIAG_CTL_GROUP2_SAMPLE_ENABLE_REG 0x40124C80
OAL_STATIC int32_t oal_pcie_disable_cputrace(oal_pcie_linux_res *pst_pci_lres)
{
    int32_t ret;
    pci_addr_map addr_map;
    uint32_t cpu_address = DIAG_CTL_GROUP2_SAMPLE_ENABLE_REG;
    uint32_t value = 0x0;
    oal_pci_dev_stru *pst_pci_dev = pst_pci_lres->comm_res->pcie_dev;
    if ((pst_pci_dev->device != PCIE_HISI_DEVICE_ID_MP16) &&
        (pst_pci_dev->device != PCIE_HISI_DEVICE_ID_MP16FPGA)) {
        return OAL_SUCC;
    }

    ret = oal_pcie_inbound_ca_to_va(pst_pci_lres, cpu_address, &addr_map);
    if (oal_unlikely(ret != OAL_SUCC)) {
        oal_io_print("oal_pcie_disable_cputrace 0x%8x unmap, write failed!\n", cpu_address);
        return -OAL_EFAIL;
    }

    oal_writel(value, (void *)addr_map.va);
    oal_io_print("oal_pcie_disable_cputrace 0x%x = %x, write success!\n", cpu_address, value);
    return ret;
}

/* reinit pcie ep control */
int32_t oal_pcie_reinit(hcc_bus *pst_bus)
{
    int32_t ret;
    uint32_t version = 0x0;
    oal_pcie_linux_res *pst_pci_lres = (oal_pcie_linux_res *)pst_bus->data;
    declare_time_cost_stru(reinit);

    oal_get_time_cost_start(reinit);

    oal_print_mpxx_log(MPXX_LOG_INFO, "wake_sema_count=%d, dev_id %d", pst_bus->sr_wake_sema.count,
                       pst_bus->dev_id);
    sema_init(&pst_bus->sr_wake_sema, 1); /* S/R信号量 */

    hcc_bus_disable_state(pst_bus, OAL_BUS_STATE_ALL);
    ret = oal_pcie_enable_device(pst_pci_lres);
    if (ret == OAL_SUCC) {
#ifdef _PRE_COMMENT_CODE_
        /* 需要在初始化完成后打开 */
        hcc_bus_enable_state(pst_bus, OAL_BUS_STATE_ALL);
#endif
    }

    /* check link status */
    if (pst_pci_lres->comm_res->pcie_dev != NULL) {
        ret = oal_pci_read_config_dword(pst_pci_lres->comm_res->pcie_dev, 0x0, &version);
        if (ret) {
            pci_print_log(PCI_LOG_ERR, "read pci version failed, enable device failed, ret=%d, version=0x%x", ret,
                          version);
            declare_dft_trace_key_info("pcie_enable_device_reinit_fail", OAL_DFT_TRACE_FAIL);
            return -OAL_ENODEV;
        }

        if (version != pst_pci_lres->comm_res->version) {
            pci_print_log(PCI_LOG_WARN, "version:0x%x is not match with:0x%x", version,
                          pst_pci_lres->comm_res->version);
        } else {
            pci_print_log(PCI_LOG_INFO, "pcie enable device check succ");
        }
    }

    /* 初始化PCIE资源 */
    ret = oal_pcie_enable_regions(pst_pci_lres);
    if (ret) {
        oal_io_print("enable regions failed, ret=%d\n", ret);
        return ret;
    }

    ret = oal_pcie_iatu_init(pst_pci_lres);
    if (ret) {
        oal_io_print("iatu init failed, ret=%d\n", ret);
        return ret;
    }

    oal_get_time_cost_end(reinit);
    oal_calc_time_cost_sub(reinit);
    pci_print_log(PCI_LOG_INFO, "pcie reinit cost %llu us", time_cost_var_sub(reinit));

    /* mp16 cs2 to be deleted: disable group2 cputrace */
    ret = oal_pcie_disable_cputrace(pst_pci_lres);

    return ret;
}

int32_t oal_pcie_host_lock(hcc_bus *pst_bus)
{
    oal_pcie_linux_res *pst_pci_lres;
    pst_pci_lres = (oal_pcie_linux_res *)pst_bus->data;
    return OAL_SUCC;
}

int32_t oal_pcie_host_unlock(hcc_bus *pst_bus)
{
    oal_pcie_linux_res *pst_pci_lres;
    pst_pci_lres = (oal_pcie_linux_res *)pst_bus->data;
    return OAL_SUCC;
}

/* MP13 PCIE 通过 host_wakeup_dev gpio 来唤醒和通知WCPU睡眠 */
int32_t oal_pcie_sleep_request(hcc_bus *pst_bus)
{
    int32_t ret;
    oal_pcie_linux_res *pst_pci_lres;
    pst_pci_lres = (oal_pcie_linux_res *)pst_bus->data;

    oal_disable_pcie_irq(pst_pci_lres);

    if (g_pcie_auto_disable_aspm != 0) {
        /* enable L1 after wakeup */
        oal_pcie_set_device_aspm_dync_disable(pst_pci_lres, OAL_FALSE);
        oal_pcie_device_xfer_pending_sig_clr(pst_pci_lres, OAL_TRUE);
    }

    /* 拉低GPIO，PCIE只有在system suspend的时候才会下电 GPIO 拉低之后 DEV 随时可能进深睡，不允许再通过PCIE 访问 */
    mutex_lock(&pst_pci_lres->ep_res.st_rx_mem_lock);
    oal_pcie_change_link_state(pst_pci_lres, PCI_WLAN_LINK_UP);
    mutex_unlock(&pst_pci_lres->ep_res.st_rx_mem_lock);

    pci_clear_master(pst_pci_lres->comm_res->pcie_dev);

    ret = board_host_wakeup_dev_set(0);
    oal_usleep(WLAN_WAKEUP_DEV_EVENT_DELAY_US);
    return ret;
}

int32_t oal_pcie_get_sleep_state(hcc_bus *pst_bus)
{
    oal_pcie_linux_res *pst_pci_lres;
    enum gpio_type type;

    pst_pci_lres = (oal_pcie_linux_res *)pst_bus->data;
    if (oal_warn_on(pst_pci_lres == NULL)) {
        oal_io_print("pst_pci_lres is null\n");
        return -OAL_EINVAL;
    }
    if (pst_bus->dev_id == HCC_EP_GT_DEV) {
        type = HOST_WKUP_GT;
    } else {
        type = HOST_WKUP_W;
    }

    return (conn_get_gpio_level(type) == GPIO_LEVEL_HIGH) ?
               DISALLOW_TO_SLEEP_VALUE : ALLOW_TO_SLEEP_VALUE;
}

int32_t oal_pcie_rx_int_mask(hcc_bus *pst_bus, int32_t is_mask)
{
    oal_pcie_linux_res *pst_pci_lres;
    pst_pci_lres = (oal_pcie_linux_res *)pst_bus->data;

    if (oal_warn_on(pst_pci_lres == NULL)) {
        oal_io_print("pst_pci_lres is null\n");
        return -OAL_EINVAL;
    }
    return OAL_SUCC;
}

int32_t oal_pcie_power_ctrl(hcc_bus *hi_bus, hcc_bus_power_ctrl_type ctrl, int (*func)(void *data), void *data)
{
    int32_t ret = OAL_SUCC;
    oal_pcie_linux_res *pst_pci_lres = NULL;

    if (hi_bus == NULL) {
        return -OAL_EFAIL;
    }
    pst_pci_lres = (oal_pcie_linux_res *)hi_bus->data;

    if (ctrl == HCC_BUS_CTRL_POWER_UP) {
        ret = oal_pcie_power_notifiy_register(g_rc_idx, func, NULL, data);
    }

    if (ctrl == HCC_BUS_CTRL_POWER_DOWN) {
        ret = oal_pcie_power_notifiy_register(g_rc_idx, NULL, func, data);
    }
    return ret;
}

int32_t oal_pcie_enable_device_func(oal_pcie_linux_res *pst_pci_lres)
{
    int32_t i;
    int32_t ret;
    unsigned int timeout = hi110x_get_emu_timeout(HOST_WAIT_BOTTOM_INIT_TIMEOUT);
    const int32_t retry = 2;
    hcc_bus *pst_bus = pst_pci_lres->pst_bus;
    char *dname = NULL;

    if (pst_bus == NULL) {
        return -OAL_ENODEV;
    }

    for (i = 0; i < retry; i++) {
        oal_init_completion(&pst_pci_lres->ep_res.st_pcie_ready);

        ret = oal_pcie_send_message2dev(pst_pci_lres, PCIE_H2D_MESSAGE_HOST_READY);
        if (ret != OAL_SUCC) {
            oal_io_print("oal_pcie_send_message2dev failed, ret=%d\n", ret);
            continue;
        }

        /* 第一个中断有可能在中断使能之前上报，强制调度一次RX Thread */
        up(&pst_bus->rx_sema);

        if (oal_wait_for_completion_timeout(&pst_pci_lres->ep_res.st_pcie_ready,
                                            (uint32_t)oal_msecs_to_jiffies(timeout)) == 0) {
            oal_io_print("wait pcie ready timeout... %u ms \n", timeout);
            up(&pst_bus->rx_sema);
            if (oal_wait_for_completion_timeout(&pst_pci_lres->ep_res.st_pcie_ready,
                                                (uint32_t)oal_msecs_to_jiffies(HOST_WAIT_DEV_DELAY_TIMEOUT)) == 0) {
                oal_io_print("pcie retry 5 second hold, still timeout");
                dname = (i == 0 ? "wait pcie ready when power on, retry" :
                    "wait pcie ready when power on, retry still failed");
                declare_dft_trace_key_info(dname, OAL_DFT_TRACE_FAIL);
                ret = -OAL_ETIMEDOUT;
                continue;
            } else {
                /* 强制调度成功，说明有可能是GPIO中断未响应 */
                oal_io_print("[E]retry succ, maybe gpio interrupt issue");
                declare_dft_trace_key_info("pcie gpio int issue", OAL_DFT_TRACE_FAIL);
                break;
            }
        } else {
            break;
        }
    }

    if (i >= retry) {
        return ret;
    }

    return OAL_SUCC;
}

int32_t oal_enable_pcie_irq(oal_pcie_linux_res *pst_pci_lres)
{
    oal_uint flag;
    if (oal_warn_on(pst_pci_lres == NULL)) {
        return -OAL_ENODEV;
    }

    oal_spin_lock_irq_save(&pst_pci_lres->comm_res->st_lock, &flag);
    if (pst_pci_lres->comm_res->irq_stat == 1) {
        pci_print_log(PCI_LOG_DBG, "enable_pcie_irq");
        enable_irq(pst_pci_lres->comm_res->pcie_dev->irq);

        pst_pci_lres->comm_res->irq_stat = 0;
    }
    oal_spin_unlock_irq_restore(&pst_pci_lres->comm_res->st_lock, &flag);

    return OAL_SUCC;
}

int32_t oal_disable_pcie_irq(oal_pcie_linux_res *pst_pci_lres)
{
    oal_uint flag;
    oal_uint nosync;

    if (oal_warn_on(pst_pci_lres == NULL)) {
        return -OAL_ENODEV;
    }
    if (oal_atomic_read(&pst_pci_lres->comm_res->refcnt) > 1) {
        oal_print_mpxx_log(MPXX_LOG_INFO, "other cpu use pcie ctrl, not disable pcie irq, devid %d, refcnt 0x%x",
            pst_pci_lres->dev_id, oal_atomic_read(&pst_pci_lres->comm_res->refcnt));
        return OAL_SUCC;
    }

    nosync = in_atomic() || in_softirq() || in_interrupt() || irqs_disabled();
    oal_spin_lock_irq_save(&pst_pci_lres->comm_res->st_lock, &flag);
    if (pst_pci_lres->comm_res->irq_stat == 0) {
        pst_pci_lres->comm_res->irq_stat = 1;
        /* intx */
        pci_print_log(PCI_LOG_DBG, "disable_pcie_irq");
        if (nosync) {
            disable_irq_nosync(pst_pci_lres->comm_res->pcie_dev->irq);
        } else {
            /* process context */
            disable_irq_nosync(pst_pci_lres->comm_res->pcie_dev->irq);
            oal_spin_unlock_irq_restore(&pst_pci_lres->comm_res->st_lock, &flag);
            synchronize_irq(pst_pci_lres->comm_res->pcie_dev->irq);
            oal_spin_lock_irq_save(&pst_pci_lres->comm_res->st_lock, &flag);
        }
    }
    oal_spin_unlock_irq_restore(&pst_pci_lres->comm_res->st_lock, &flag);

    return OAL_SUCC;
}

OAL_STATIC void oal_pcie_host_ip_edma_init(oal_pcie_linux_res *pst_pci_lres)
{
    if (pst_pci_lres->ep_res.chip_info.edma_support != OAL_TRUE) {
        return;
    }
    oal_pcie_set_device_soft_fifo_enable(pst_pci_lres);
    oal_pcie_set_device_ringbuf_bugfix_enable(pst_pci_lres);
    oal_pcie_set_device_dma_check_enable(pst_pci_lres);
}

OAL_STATIC void oal_pcie_host_ip_ete_init(oal_pcie_linux_res *pst_pci_lres)
{
    if (pst_pci_lres->ep_res.chip_info.ete_support != OAL_TRUE) {
        return;
    }
    oal_print_mpxx_log(MPXX_LOG_INFO, "oal_pcie_host_ip_ete_init");
    (void)oal_ete_ip_init(pst_pci_lres);
}

int32_t oal_pcie_host_ip_init(oal_pcie_linux_res *pst_pci_lres)
{
    oal_pcie_mps_init(pst_pci_lres);
    oal_pcie_host_aspm_init(pst_pci_lres);
    oal_pcie_host_ip_edma_init(pst_pci_lres);
    oal_pcie_host_ip_ete_init(pst_pci_lres);
    return OAL_SUCC;
}

void oal_pcie_print_chip_info(oal_pcie_linux_res *pst_pci_lres, uint32_t is_full_log)
{
    /* L1 recovery count */
    uint32_t l1_err_cnt = oal_readl(pst_pci_lres->ep_res.pst_pci_ctrl_base + PCIE_STAT_CNT_LTSSM_ENTER_RCVRY_OFF);
    uint32_t l1_recvy_cnt = oal_readl(pst_pci_lres->ep_res.pst_pci_ctrl_base + PCIE_STAT_CNT_L1_ENTER_RCVRY_OFF);
    const uint32_t l1_max_err_cnt = 3;

    if (pst_pci_lres->ep_res.l1_err_cnt == 0) {
        pst_pci_lres->ep_res.l1_err_cnt = l1_err_cnt;
    }

    if (is_full_log) {
        if (l1_err_cnt > l1_max_err_cnt - 1) {
            oal_print_mpxx_log(MPXX_LOG_ERR, "not l1 recovry error count %u, link_state unstable", l1_err_cnt);
        } else {
            /* 建链过程中会进入2次 */
            oal_print_mpxx_log(MPXX_LOG_INFO, "link_state stable, l1 excp count:%u", l1_err_cnt);
        }

        if (l1_recvy_cnt) {
            oal_print_mpxx_log(MPXX_LOG_INFO, "l1 enter count is %u", l1_recvy_cnt);
        } else {
            oal_print_mpxx_log(MPXX_LOG_INFO, "l1 maybe not enable");
        }
    } else {
        if (l1_err_cnt > l1_max_err_cnt - 1) {
            if ((pst_pci_lres->ep_res.l1_err_cnt == 0) || (l1_err_cnt > pst_pci_lres->ep_res.l1_err_cnt)) {
                /* link state error */
                oal_print_mpxx_log(MPXX_LOG_ERR, "not l1 recovry error count %u, link_state unstable", l1_err_cnt);
                declare_dft_trace_key_info("pcie_link_state_unstable", OAL_DFT_TRACE_FAIL);
            } else {
                oal_print_mpxx_log(MPXX_LOG_DBG, "link_state stable, l1 excp count:%u", l1_err_cnt);
            }
        }
    }

    pst_pci_lres->ep_res.l1_err_cnt = l1_err_cnt;
}

void oal_pcie_chip_info(hcc_bus *pst_bus, uint32_t is_need_wakeup, uint32_t is_full_log)
{
    oal_pcie_linux_res *pst_pci_lres;
    pst_pci_lres = (oal_pcie_linux_res *)pst_bus->data;
    if (oal_warn_on(pst_pci_lres == NULL)) {
        return;
    }

    if (oal_unlikely(pst_pci_lres->ep_res.link_state <= PCI_WLAN_LINK_DOWN)) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "link_state:%s",
                           oal_pcie_get_link_state_str(pst_pci_lres->ep_res.link_state));
        return;
    }

    if (is_need_wakeup == OAL_TRUE) {
        if (pst_bus->bus_dev == NULL) {
            return;
        }
    }

    if (is_need_wakeup == OAL_TRUE) {
        hcc_tx_transfer_lock(pst_bus->bus_dev->hcc);
        if (oal_unlikely(hcc_bus_pm_wakeup_device(pst_pci_lres->pst_bus) != OAL_SUCC)) {
            oal_print_mpxx_log(MPXX_LOG_ERR, "wakeup device failed");
            hcc_tx_transfer_unlock(pst_bus->bus_dev->hcc);
            return;
        }
    }

    oal_pcie_print_chip_info(pst_pci_lres, is_full_log);

    if (is_need_wakeup == OAL_TRUE) {
        hcc_tx_transfer_unlock(pst_bus->bus_dev->hcc);
    }
}

int32_t oal_pcie_ip_init(hcc_bus *pst_bus)
{
    int32_t ret;
    oal_pcie_linux_res *pst_pci_lres = NULL;
    if (pst_bus == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "pst_bus is null");
        return -OAL_ENODEV;
    }

    pst_pci_lres = (oal_pcie_linux_res *)pst_bus->data;
    if (oal_warn_on(pst_pci_lres == NULL)) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "pst_pci_lres is null");
        return -OAL_ENODEV;
    }

    ret = oal_pcie_device_auxclk_init(pst_pci_lres);
    if (ret) {
        return ret;
    }

    ret = oal_pcie_device_aspm_init(pst_pci_lres);
    if (ret) {
        return ret;
    }

    /* 使能低功耗 */
    ret = oal_pcie_host_aspm_init(pst_pci_lres);
    if (ret) {
        return ret;
    }

    return OAL_SUCC;
}

int32_t oal_pcie_ip_voltage_bias_init(hcc_bus *pst_bus)
{
    oal_pcie_linux_res *pst_pci_lres;
    pst_pci_lres = (oal_pcie_linux_res *)pst_bus->data;
    if (oal_warn_on(pst_pci_lres == NULL)) {
        return -OAL_ENODEV;
    }
    return oal_pcie_voltage_bias_init(pst_pci_lres);
}

OAL_STATIC void oal_pcie_power_down(hcc_bus *pst_bus)
{
    oal_pcie_linux_res *pst_pci_lres = (oal_pcie_linux_res *)pst_bus->data;
    int32_t ret;

    /* disable intx gpio... 等待中断处理完 */
    ret = oal_disable_pcie_irq(pst_pci_lres);
    if (ret != OAL_SUCC) {
        return;
    }

    pst_pci_lres->ep_res.power_status = PCIE_EP_IP_POWER_DOWN;
    pst_pci_lres->ep_res.l1_err_cnt = 0;
    mutex_lock(&pst_pci_lres->ep_res.st_rx_mem_lock);
    oal_pcie_change_link_state(pst_pci_lres, PCI_WLAN_LINK_DOWN);
    mutex_unlock(&pst_pci_lres->ep_res.st_rx_mem_lock);
    oal_pcie_disable_regions(pst_pci_lres);
    oal_pcie_transfer_res_exit(pst_pci_lres);

    if (oal_atomic_read(&pst_pci_lres->comm_res->refcnt) > 0) {
        oal_atomic_dec(&pst_pci_lres->comm_res->refcnt);
    }
    if (oal_atomic_read(&pst_pci_lres->comm_res->refcnt) > 0) {
        oal_print_mpxx_log(MPXX_LOG_INFO, "other cpu use pcie ctrl, not change pcie link, %d",
                           oal_atomic_read(&pst_pci_lres->comm_res->refcnt));
        return;
    }
    oal_pcie_deregister_event(pst_pci_lres);

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(4, 4, 0))
    ret = oal_pcie_pm_control(pst_pci_lres, g_rc_idx, PCIE_POWER_OFF_WITHOUT_L3MSG);
#else
    ret = oal_pcie_pm_control(pst_pci_lres, g_rc_idx, PCIE_POWER_OFF_WITH_L3MSG);
#endif
    if (pst_pci_lres->ep_res.power_status != PCIE_EP_IP_POWER_DOWN) {
        if (ret) {
            declare_dft_trace_key_info("pcie_power_down_fail", OAL_DFT_TRACE_EXCEP);
        }
    }
    oal_pcie_power_notifiy_register(g_rc_idx, NULL, NULL, NULL);
#ifdef _PRE_PLAT_FEATURE_HI110X_DUAL_PCIE
    oal_ete_dual_pci_power_down(pst_pci_lres);
#endif
}

void pcie_bus_power_down_action(hcc_bus *pst_bus)
{
    /* 关掉LINKDOWN注册回调函数 */
    hcc_disable(hbus_to_hcc(pst_bus), OAL_TRUE);
    oal_wlan_gpio_intr_enable(hbus_to_dev(pst_bus), OAL_FALSE);
    hcc_transfer_lock(hbus_to_hcc(pst_bus));
    oal_pcie_power_down(pst_bus);
    hcc_transfer_unlock(hbus_to_hcc(pst_bus));
    board_host_wakeup_dev_set(0);
}

int32_t oal_pcie_patch_read(hcc_bus *pst_bus, uint8_t *buff, int32_t len, uint32_t timeout)
{
    int32_t ret;
    oal_pcie_linux_res *pst_pci_lres;

    pst_pci_lres = (oal_pcie_linux_res *)pst_bus->data;
    if (oal_warn_on(pst_pci_lres == NULL)) {
        return -OAL_ENODEV;
    }

    mutex_lock(&pst_pci_lres->ep_res.st_rx_mem_lock);
    /* 检查链路状态 */
    if (oal_pcie_check_link_state(pst_pci_lres) != OAL_TRUE) {
        mutex_unlock(&pst_pci_lres->ep_res.st_rx_mem_lock);
        return -OAL_EFAUL;
    }
    ret = oal_pcie_firmware_read(pst_pci_lres, buff, len, timeout);
    /* 命令执行完成后再次检查，防止通道异常造成命令执行失败 */
    if (oal_pcie_check_link_state(pst_pci_lres) != OAL_TRUE) {
        mutex_unlock(&pst_pci_lres->ep_res.st_rx_mem_lock);
        return -OAL_EFAUL;
    }
    mutex_unlock(&pst_pci_lres->ep_res.st_rx_mem_lock);

    return ret;
}

int32_t oal_pcie_patch_write(hcc_bus *pst_bus, uint8_t *buff, int32_t len)
{
    int32_t ret;
    oal_pcie_linux_res *pst_pci_lres;

    pst_pci_lres = (oal_pcie_linux_res *)pst_bus->data;
    if (oal_warn_on(pst_pci_lres == NULL)) {
        oal_io_print("oal_pcie_patch_write failed, lres is null\n");
        return -OAL_ENODEV;
    }

    mutex_lock(&pst_pci_lres->ep_res.st_rx_mem_lock);
    /* 检查链路状态 */
    if (oal_pcie_check_link_state(pst_pci_lres) != OAL_TRUE) {
        mutex_unlock(&pst_pci_lres->ep_res.st_rx_mem_lock);
        return -OAL_EFAUL;
    }
    ret = oal_pcie_firmware_write(pst_pci_lres, buff, len);
    /* 命令执行完成后再次检查，防止通道异常造成命令执行失败 */
    if (oal_pcie_check_link_state(pst_pci_lres) != OAL_TRUE) {
        mutex_unlock(&pst_pci_lres->ep_res.st_rx_mem_lock);
        return -OAL_EFAUL;
    }
    mutex_unlock(&pst_pci_lres->ep_res.st_rx_mem_lock);

    return ret;
}

int32_t oal_pcie_gpio_irq(hcc_bus *hi_bus, int32_t irq)
{
    oal_uint ul_state;
    oal_pcie_linux_res *pst_pci_lres = NULL;
    struct wlan_pm_s *pst_wlan_pm = wlan_pm_get_drv();

    if (oal_unlikely(hi_bus == NULL)) {
        oal_io_print("pcie bus is null, irq:%d\n", irq);
        return -OAL_EINVAL;
    }

    pst_pci_lres = (oal_pcie_linux_res *)hi_bus->data;

    if (!hi_bus->pst_pm_callback || !hi_bus->pst_pm_callback->pm_state_get) {
        oal_io_print("GPIO interrupt function param is NULL\r\n");
        return -OAL_EINVAL;
    }

    hi_bus->gpio_int_count++;

    if (oal_atomic_read(&g_wakeup_dev_wait_ack)) {
        pci_print_log(PCI_LOG_INFO, "pcie_gpio_irq wakeup dev ack");
        hi_bus->pst_pm_callback->pm_wakeup_dev_ack();
    }

    if (oal_atomic_read(&g_bus_powerup_dev_wait_ack)) {
        pci_print_log(PCI_LOG_INFO, "pcie_gpio_irq powerup dev ack");
        if (oal_likely(pst_wlan_pm != NULL)) {
            oal_complete(&pst_wlan_pm->st_wifi_powerup_done);
        } else {
            pci_print_log(PCI_LOG_INFO, "pst_wlan_pm is null");
        }
    }

    if (oal_unlikely(pst_pci_lres != NULL)) {
        pci_print_log(PCI_LOG_INFO, "pcie_gpio_irq dev ready ack");
        if (oal_likely(pst_wlan_pm != NULL)) {
            oal_complete(&pst_wlan_pm->st_wifi_powerup_done);
            up(&hi_bus->rx_sema);
        } else {
            pci_print_log(PCI_LOG_INFO, "pst_wlan_pm is null");
        }
    }

    ul_state = hi_bus->pst_pm_callback->pm_state_get();
    if (ul_state == 0) {
        /* 0==HOST_DISALLOW_TO_SLEEP表示不允许休眠 */
        hi_bus->data_int_count++;
        /* PCIE message use gpio interrupt */
        pci_print_log(PCI_LOG_DBG, "pcie message come..");
        up(&hi_bus->rx_sema);
    } else {
        /* 1==HOST_ALLOW_TO_SLEEP表示当前是休眠，唤醒host */
        if (oal_warn_on(!hi_bus->pst_pm_callback->pm_wakeup_host)) {
            pci_print_log(PCI_LOG_ERR, "%s error:hi_bus->pst_pm_callback->pm_wakeup_host is null", __FUNCTION__);
            return -OAL_FAIL;
        }

        hi_bus->wakeup_int_count++;
        pci_print_log(PCI_LOG_INFO, "trigger wakeup work...");
        hi_bus->pst_pm_callback->pm_wakeup_host();
    }
    return OAL_SUCC;
}

void oal_pcie_handle_d2h_message(hcc_bus *hi_bus, uint32_t message)
{
    oal_pcie_linux_res *pst_pci_lres = (oal_pcie_linux_res *)hi_bus->data;

    pci_print_log(PCI_LOG_DBG, "pci  message : %u", message);

    if (message < D2H_MSG_COUNT) {
        /* standard message */
        hi_bus->msg[message].count++;
        hi_bus->last_msg = message;
        hi_bus->msg[message].cpu_time = cpu_clock(UINT_MAX);
        if (hi_bus->msg[message].msg_rx) {
            hi_bus->msg[message].msg_rx(hi_bus->msg[message].data);
        } else {
            oal_io_print("pcie mssage :%u no callback functions\n", message);
        }
    } else {
        if (message == PCIE_D2H_MESSAGE_HOST_READY_ACK) {
            pci_print_log(PCI_LOG_INFO, "d2h host read ack");
            oal_complete(&pst_pci_lres->ep_res.st_pcie_ready);
        }
    }
}

int32_t oal_pcie_gpio_rx_data(hcc_bus *hi_bus)
{
    int32_t ret;
    uint32_t message;
    oal_pcie_linux_res *pst_pci_lres = (oal_pcie_linux_res *)hi_bus->data;
    if (oal_warn_on(pst_pci_lres == NULL)) {
        return -OAL_EINVAL;
    }

    /* read message from device, read until ringbuf empty */
    forever_loop()
    {
        if (!pst_pci_lres->comm_res->regions.inited) {
            oal_io_print("pcie rx data region is disabled!\n");
            return -OAL_ENODEV;
        }

        /* read one message */
        hcc_bus_wake_lock(hi_bus);
        mutex_lock(&pst_pci_lres->ep_res.st_rx_mem_lock);
        ret = oal_pcie_read_d2h_message(pst_pci_lres, &message);
        mutex_unlock(&pst_pci_lres->ep_res.st_rx_mem_lock);
        hcc_bus_wake_unlock(hi_bus);
        if (ret != OAL_SUCC) {
            break;
        }
        oal_pcie_handle_d2h_message(hi_bus, message);
    }

    return OAL_SUCC;
}

void oal_pcie_print_trans_info(hcc_bus *hi_bus, uint64_t print_flag)
{
    oal_pcie_linux_res *pst_pci_lres = (oal_pcie_linux_res *)hi_bus->data;
    if (oal_warn_on(pst_pci_lres == NULL)) {
        return;
    }

    oal_pcie_print_transfer_info(pst_pci_lres, print_flag);
}

void oal_pcie_reset_trans_info(hcc_bus *hi_bus)
{
    oal_pcie_linux_res *pst_pci_lres = (oal_pcie_linux_res *)hi_bus->data;
    if (oal_warn_on(pst_pci_lres == NULL)) {
        return;
    }

    oal_pcie_reset_transfer_info(pst_pci_lres);
}

int32_t oal_pcie_mpxx_working_check(void)
{
    hcc_bus_dev *pst_bus_dev = NULL;
    int32_t i;

    for (i = HCC_EP_WIFI_DEV; i < HCC_CHIP_MAX_DEV; i++) {
        pst_bus_dev = hcc_get_bus_dev(i);
        if (pst_bus_dev == NULL) {
            continue;
        }

        if (pst_bus_dev->bus_cap & HCC_BUS_PCIE_CAP) {
            return OAL_TRUE;
        }
    }
    return OAL_FALSE;
}

int32_t oal_wifi_platform_load_pcie(void)
{
    if (oal_pcie_mpxx_working_check() != OAL_TRUE) {
        /* pcie driver don't support */
        oal_io_print("pcie driver don't support\n");
        return OAL_SUCC;
    }

    return oal_pcie_mpxx_init();
}

void oal_wifi_platform_unload_pcie(void)
{
    if (oal_pcie_mpxx_working_check() != OAL_TRUE) {
        return;
    }

#ifdef _PRE_PLAT_FEATURE_HI110X_PCIE
    oal_pcie_mpxx_exit();
#endif
}

oal_pci_dev_stru *oal_get_wifi_pcie_dev(void)
{
    oal_pcie_linux_res *pcie_linux_res = oal_get_pcie_handler(HCC_EP_WIFI_DEV);
    if (pcie_linux_res == NULL || pcie_linux_res->comm_res == NULL) {
        return NULL;
    }
    return pcie_linux_res->comm_res->pcie_dev;
}
oal_module_symbol(oal_get_wifi_pcie_dev);

oal_pcie_linux_res *oal_get_pcie_linux_res(void)
{
    return NULL;
}
oal_module_symbol(oal_get_pcie_linux_res);

#else
#include "platform_oneimage_define.h"
int oal_wifi_platform_load_pcie(void)
{
    return 0;
}

void oal_wifi_platform_unload_pcie(void)
{
}
#endif
