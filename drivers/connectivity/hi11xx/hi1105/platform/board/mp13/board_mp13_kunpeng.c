/**
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 *
 * Description: Declaration Driver Entry Function
 * Author: @CompanyNameTag
 */

/* 头文件包含 */
#define MPXX_LOG_MODULE_NAME     "[MP13_BOARD]"
#define MPXX_LOG_MODULE_NAME_VAR mp13_board_loglevel
#include "board_mp13_kunpeng.h"

#ifdef _PRE_CONFIG_USE_DTS
#include <linux/of.h>
#include <linux/of_gpio.h>
#endif

#include <linux/clk.h>
#include <linux/interrupt.h>
#include <linux/platform_device.h>
#include <linux/timer.h>
#include <linux/delay.h>
#ifdef CONFIG_PINCTRL
#include <linux/pinctrl/consumer.h>
#endif

#include "plat_debug.h"
#include "bfgx_dev.h"
#include "plat_pm.h"
#include "oal_hcc_host_if.h"
#include "plat_uart.h"
#include "plat_firmware.h"
#include "plat_firmware_download.h"
#include "chr_user.h"
#include "oam_dsm.h"

#ifdef BFGX_UART_DOWNLOAD_SUPPORT
#include "bfgx_data_parse.h"
#include "plat_firmware_uart.h"
#endif

#ifdef PLATFORM_DEBUG_ENABLE
int32_t g_device_monitor_enable = 0;
#endif

STATIC int32_t g_ft_fail_powerdown_bypass = 0;

/*
 * 函 数 名  : mp13_board_flowctrl_gpio_init
 * 功能描述  : 注册gpio流控中断
 */
STATIC int32_t mp13_board_flowctrl_gpio_init(void)
{
    int32_t ret;
    int32_t physical_gpio = 0;

    /* 根据设备树DTS文件获取流控GPIO在host侧对应的管脚，保存在physical_gpio中 */
    ret = get_board_gpio(DTS_NODE_MPXX_WIFI, DTS_PROP_GPIO_WLAN_FLOWCTRL, &physical_gpio);
    if (ret != BOARD_SUCC) {
        ps_print_err("get dts prop %s failed\n", DTS_PROP_GPIO_WLAN_FLOWCTRL);
        return BOARD_SUCC;
    }

    g_st_board_info.flowctrl_gpio = physical_gpio;

    /* 向内核申请使用该管脚 */
#ifdef GPIOF_IN
    ret = gpio_request_one(physical_gpio, GPIOF_IN, PROC_NAME_GPIO_WLAN_FLOWCTRL);
    if (ret) {
        ps_print_err("%s gpio_request failed\n", PROC_NAME_GPIO_WLAN_FLOWCTRL);
        return BOARD_FAIL;
    }
#else
    ret = gpio_request(physical_gpio, PROC_NAME_GPIO_WLAN_FLOWCTRL);
    if (ret) {
        ps_print_err("%s gpio_request failed\n", PROC_NAME_GPIO_WLAN_FLOWCTRL);
        return BOARD_FAIL;
    } else {
        ps_print_err("%s gpio_request succ\n", PROC_NAME_GPIO_WLAN_FLOWCTRL);
        gpio_direction_input(physical_gpio);
    }
#endif

    return BOARD_SUCC;
}

STATIC void mp13_free_board_flowctrl_gpio(void)
{
    oal_gpio_free(g_st_board_info.flowctrl_gpio);
}


STATIC int32_t mp13_board_power_on(uint32_t ul_subsystem)
{
    int32_t ret = SUCC;

    if (ul_subsystem == W_SYS) {
        if (bfgx_is_shutdown()) {
            ps_print_info("wifi pull up power_on_enable gpio!\n");
            board_chip_power_on();
            if (board_sys_enable(W_SYS)) {
                ret = WIFI_POWER_BFGX_OFF_PULL_WLEN_FAIL;
            }
            board_sys_enable(B_SYS);
        } else {
            if (board_sys_enable(W_SYS)) {
                ret = WIFI_POWER_BFGX_ON_PULL_WLEN_FAIL;
            }
        }
    } else if (ul_subsystem == B_SYS) {
#ifndef BFGX_UART_DOWNLOAD_SUPPORT
        if (wlan_is_shutdown()) {
            ps_print_info("bfgx pull up power_on_enable gpio!\n");
            board_chip_power_on();
            ret = board_sys_enable(W_SYS);
        }
#else
        board_chip_power_on();
#endif
        board_sys_enable(B_SYS);
    } else {
        ps_print_err("power input system:%d error\n", ul_subsystem);
    }

    return ret;
}

STATIC int32_t mp13_board_power_off(uint32_t ul_subsystem)
{
    if (ul_subsystem == W_SYS) {
        board_sys_disable(W_SYS);
        if (bfgx_is_shutdown()) {
            ps_print_info("wifi pull down power_on_enable!\n");
            board_sys_disable(B_SYS);
            board_chip_power_off();
        }
    } else if (ul_subsystem == B_SYS) {
        board_sys_disable(B_SYS);
#ifndef BFGX_UART_DOWNLOAD_SUPPORT
        if (wlan_is_shutdown()) {
            ps_print_info("bfgx pull down power_on_enable!\n");
            board_sys_disable(W_SYS);
            board_chip_power_off();
        }
#else
        board_chip_power_off();
#endif
    } else {
        ps_print_err("power input system:%d error\n", ul_subsystem);
        return -EFAIL;
    }

    return SUCC;
}

STATIC int32_t mp13_board_power_reset(uint32_t ul_subsystem)
{
#ifndef BFGX_UART_DOWNLOAD_SUPPORT
    int32_t ret;
#endif
    board_sys_disable(B_SYS);
#ifndef BFGX_UART_DOWNLOAD_SUPPORT
    board_sys_disable(W_SYS);
#endif
    board_chip_power_off();
    board_chip_power_on();
#ifndef BFGX_UART_DOWNLOAD_SUPPORT
    ret = board_sys_enable(W_SYS);
#endif
    board_sys_enable(B_SYS);
    return ret;
}

void mp13_bfgx_subsys_reset(void)
{
    // 维测, 判断之前的gpio状态
    ps_print_info("bfgx wkup host gpio val %d\n", conn_get_gpio_level(BFGX_WKUP_HOST));

    board_sys_disable(B_SYS);
    mdelay(BFGX_SUBSYS_RST_DELAY);
    board_sys_enable(B_SYS);
}

int32_t mp13_wifi_subsys_reset(void)
{
    int32_t ret;
    board_sys_disable(W_SYS);
    mdelay(WIFI_SUBSYS_RST_DELAY);
    ret = board_sys_enable(W_SYS);
    return ret;
}


STATIC void judge_ir_only_mode(struct ps_core_s *ps_core_d)
{
    if (get_mpxx_subchip_type() == BOARD_VERSION_MP16) {
        return;
    }
    /* wifi & bfgx both shutdown */
    if ((wlan_is_shutdown() == true) && (bfgx_is_shutdown() == true)) {
        /* chip type is asic */
        if (mpxx_is_asic()) {
            oal_atomic_set(&ps_core_d->ir_only, 1);
        }
    }
}

#ifndef BFGX_UART_DOWNLOAD_SUPPORT
int32_t mp13_bfgx_run_bcpu(void)
{
    int32_t ret;
    int32_t error = BFGX_POWER_SUCCESS;
    struct pm_top* pm_top_data = pm_get_top();

    if (wlan_is_shutdown()) {
        ret = firmware_download_function(BFGX_CFG, hcc_get_bus(HCC_EP_WIFI_DEV));
        if (ret != BFGX_POWER_SUCCESS) {
            hcc_bus_disable_state(pm_top_data->wlan_pm_info->pst_bus, OAL_BUS_STATE_ALL);
            ps_print_err("bfgx download firmware fail!\n");
            error = (ret == -OAL_EINTR) ? BFGX_POWER_DOWNLOAD_FIRMWARE_INTERRUPT : BFGX_POWER_DOWNLOAD_FIRMWARE_FAIL;
            return error;
        }
        hcc_bus_disable_state(pm_top_data->wlan_pm_info->pst_bus, OAL_BUS_STATE_ALL);

        /* eng support monitor */
#ifdef PLATFORM_DEBUG_ENABLE
        if (!g_device_monitor_enable) {
#endif
            board_sys_disable(W_SYS);
#ifdef PLATFORM_DEBUG_ENABLE
        }
#endif
    } else {
        /* 此时BFGX 需要解复位BCPU */
        ps_print_info("wifi dereset bcpu\n");
        if (wlan_pm_open_bcpu() != BFGX_POWER_SUCCESS) {
            ps_print_err("wifi dereset bcpu fail!\n");
            error = BFGX_POWER_WIFI_DERESET_BCPU_FAIL;
            chr_exception_report(CHR_PLATFORM_EXCEPTION_EVENTID, CHR_SYSTEM_PLAT, CHR_LAYER_DRV,
                                 CHR_PLT_DRV_EVENT_OPEN, CHR_PLAT_DRV_ERROR_BFGX_PWRON_BY_WIFI);

            return error;
        }
    }
    return error;
}

STATIC int32_t mp13_bfgx_dev_power_on(struct ps_core_s *ps_core_d, uint32_t sys, uint32_t subsys)
{
    int32_t ret;
    int32_t error = BFGX_POWER_SUCCESS;
    struct pm_drv_data *pm_data = NULL;

    if ((ps_core_d == NULL) || (ps_core_d->pm_data == NULL)) {
        return BFGX_POWER_FAILED;
    }

    pm_data = ps_core_d->pm_data;

    bfgx_gpio_intr_enable(pm_data, OAL_TRUE);

    /* judge ir only mode */
    if (subsys == BFGX_IR) {
        judge_ir_only_mode(ps_core_d);
    }

    ret = mp13_board_power_on(sys);
    if (ret) {
        ps_print_err("mp13_board_power_on bfg failed, ret=%d\n", ret);
        error = BFGX_POWER_PULL_POWER_GPIO_FAIL;
        goto bfgx_power_on_fail;
    }

    if (open_tty_drv(ps_core_d) != BFGX_POWER_SUCCESS) {
        ps_print_err("open tty fail!\n");
        error = BFGX_POWER_TTY_OPEN_FAIL;
        goto bfgx_power_on_fail;
    }

    error = mp13_bfgx_run_bcpu();
    if (error != BFGX_POWER_SUCCESS) {
        goto bfgx_power_on_fail;
    }

    return BFGX_POWER_SUCCESS;

bfgx_power_on_fail:
#if defined(CONFIG_HUAWEI_OHOS_DSM) || defined(CONFIG_HUAWEI_DSM)
    if (error != BFGX_POWER_DOWNLOAD_FIRMWARE_INTERRUPT) {
        hw_mpxx_dsm_client_notify(SYSTEM_TYPE_PLATFORM, DSM_MPXX_DOWNLOAD_FIRMWARE,
                                  "bcpu download firmware failed,wifi %s,ret=%d,process:%s\n",
                                  wlan_is_shutdown() ? "off" : "on", error, current->comm);
    }
#endif
    (void)mp13_board_power_off(sys);
    return error;
}
#else
STATIC int32_t mp13_bfgx_dev_power_on(struct ps_core_s *ps_core_d, uint32_t sys, uint32_t subsys)
{
    int32_t ret;
    int32_t error = BFGX_POWER_SUCCESS;
    struct pm_drv_data *pm_data = NULL;

    if ((ps_core_d == NULL) || (ps_core_d->pm_data == NULL)) {
        return BFGX_POWER_FAILED;
    }

    pm_data = ps_core_d->pm_data;

    /* judge ir only mode */
    if (subsys == BFGX_IR) {
        judge_ir_only_mode(ps_core_d);
    }

    bfgx_gpio_intr_enable(pm_data, OAL_TRUE);

    ps_print_info("bfgx pull up power_on_enable gpio!\n");
    ret = mp13_board_power_on(sys);
    if (ret) {
        ps_print_err("mp13_board_power_on bfg failed ret=%d\n", ret);
        return BFGX_POWER_FAILED;
    }

    if (open_tty_drv(ps_core_d) != BFGX_POWER_SUCCESS) {
        ps_print_err("open tty fail!\n");
        error = BFGX_POWER_TTY_OPEN_FAIL;
        goto bfgx_power_on_fail;
    }

    st_tty_recv = ps_recv_patch;
    error = ps_core_d->pm_data->download_patch(ps_core_d);
    if (error) { /* if download patch err,and close uart */
        error = release_tty_drv(ps_core_d);
        ps_print_err(" download_patch is failed!\n");
        goto bfgx_power_on_fail;
    }

    ps_print_suc(" download_patch is successfully!\n");

    return BFGX_POWER_SUCCESS;

bfgx_power_on_fail:
    chr_exception_report(CHR_PLATFORM_EXCEPTION_EVENTID, CHR_SYSTEM_PLAT, CHR_LAYER_DRV,
                         CHR_PLT_DRV_EVENT_OPEN, CHR_PLAT_DRV_ERROR_POWER_UP_BFGX);
    (void)mp13_board_power_off(sys);
    return error;
}
#endif

STATIC int32_t mp13_bfgx_dev_power_off(struct ps_core_s *ps_core_d, uint32_t sys, uint32_t subsys)
{
    int32_t error = BFGX_POWER_SUCCESS;
    struct pm_drv_data *pm_data = NULL;

    ps_print_info("%s sys[%d] subsys[%d]\n", __func__, sys, subsys);
    if ((ps_core_d == NULL) || (ps_core_d->pm_data == NULL)) {
        ps_print_err("ps_core_d is err\n");
        return BFGX_POWER_FAILED;
    }

    pm_data = ps_core_d->pm_data;

    bfgx_gpio_intr_enable(pm_data, OAL_FALSE);

    if (release_tty_drv(ps_core_d) != SUCCESS) {
        /* 代码执行到此处，说明六合一所有业务都已经关闭，无论tty是否关闭成功，device都要下电 */
        ps_print_err("wifi off, close tty is err!");
    }

    if (!wlan_is_shutdown()) {
        ps_print_info("wifi shutdown bcpu\n");
        if (wlan_pm_shutdown_bcpu_cmd() != SUCCESS) {
            ps_print_err("wifi shutdown bcpu fail\n");
            chr_exception_report(CHR_PLATFORM_EXCEPTION_EVENTID, CHR_SYSTEM_PLAT, CHR_LAYER_DRV,
                                 CHR_PLT_DRV_EVENT_CLOSE, CHR_PLAT_DRV_ERROR_WIFI_CLOSE_BCPU);
            error = BFGX_POWER_FAILED;
        }
    }

    pm_data->bfgx_dev_state = BFGX_SLEEP;
    pm_data->uart_state = UART_NOT_READY;

    (void)mp13_board_power_off(sys);

    if (subsys == BFGX_IR) {
        oal_atomic_set(&ps_core_d->ir_only, 0);
    }

    return error;
}

STATIC int32_t mp13_wlan_power_off(void)
{
    struct wlan_pm_s *wlan_pm_info = wlan_pm_get_drv();

    /* 先关闭SDIO TX通道 */
    hcc_bus_disable_state(hcc_get_bus(HCC_EP_WIFI_DEV), OAL_BUS_STATE_TX);

    /* wakeup dev,send poweroff cmd to wifi */
    if (wlan_pm_poweroff_cmd() != OAL_SUCC) {
        /* wifi self close 失败了也继续往下执行，uart关闭WCPU，异常恢复推迟到wifi下次open的时候执行 */
        declare_dft_trace_key_info("wlan_poweroff_cmd_fail", OAL_DFT_TRACE_FAIL);
        chr_exception_report(CHR_PLATFORM_EXCEPTION_EVENTID, CHR_SYSTEM_PLAT, CHR_LAYER_DRV,
                             CHR_PLT_DRV_EVENT_CLOSE, CHR_PLAT_DRV_ERROR_CLOSE_WCPU);
    }
    hcc_bus_disable_state(hcc_get_bus(HCC_EP_WIFI_DEV), OAL_BUS_STATE_ALL);

    (void)mp13_board_power_off(W_SYS);

    if (wlan_pm_info != NULL) {
        wlan_pm_info->wlan_power_state = POWER_STATE_SHUTDOWN;
    }
    return SUCCESS;
}

static int32_t mp13_firmware_download_syserr_to_selferr(int32_t error)
{
    int32_t ret = SUCCESS;

    if (error != WIFI_POWER_SUCCESS) {
        ps_print_err("firmware download fail\n");
        if (error == -OAL_EINTR) {
            ret = WIFI_POWER_ON_FIRMWARE_DOWNLOAD_INTERRUPT;
        } else if (error == -OAL_ENOPERMI) {
            ret = WIFI_POWER_ON_FIRMWARE_FILE_OPEN_FAIL;
        } else {
            ret = WIFI_POWER_BFGX_OFF_FIRMWARE_DOWNLOAD_FAIL;
        }
    }
    return ret;
}

STATIC int32_t mp13_wlan_power_on(void)
{
    int32_t ret;
    int32_t error = WIFI_POWER_SUCCESS;
    struct wlan_pm_s *wlan_pm_info = wlan_pm_get_drv();
    if (wlan_pm_info == NULL) {
        ps_print_err("wlan_pm_info is NULL!\n");
        return -FAILURE;
    }

    ret = mp13_board_power_on(W_SYS);
    if (ret) {
        ps_print_err("mp13_board_power_on wlan failed ret=%d\n", ret);
        return -FAILURE;
    }

    hcc_bus_power_action(hcc_get_bus(HCC_EP_WIFI_DEV), HCC_BUS_POWER_PATCH_LOAD_PREPARE);

    if (bfgx_is_shutdown()) {
        error = firmware_download_function(BFGX_AND_WIFI_CFG, hcc_get_bus(HCC_EP_WIFI_DEV));
        board_sys_disable(B_SYS);
    } else {
        error = firmware_download_function(WIFI_CFG, hcc_get_bus(HCC_EP_WIFI_DEV));
    }

    if (error != WIFI_POWER_SUCCESS) {
        error = mp13_firmware_download_syserr_to_selferr(error);
    } else {
        wlan_pm_info->wlan_power_state = POWER_STATE_OPEN;
    }

    ret = hcc_bus_power_action(hcc_get_bus(HCC_EP_WIFI_DEV), HCC_BUS_POWER_PATCH_LAUCH);
    if (ret != 0) {
        declare_dft_trace_key_info("wlan_poweron HCC_BUS_POWER_PATCH_LAUCH by gpio_fail", OAL_DFT_TRACE_FAIL);
        ps_print_err("wlan_poweron HCC_BUS_POWER_PATCH_LAUCH by gpio fail ret=%d", ret);
        error = WIFI_POWER_BFGX_OFF_BOOT_UP_FAIL;
        chr_exception_report(CHR_PLATFORM_EXCEPTION_EVENTID, CHR_SYSTEM_PLAT, CHR_LAYER_DRV,
                             CHR_PLT_DRV_EVENT_OPEN, CHR_PLAT_DRV_ERROR_WCPU_BOOTUP);
        goto wifi_power_fail;
    }

    return WIFI_POWER_SUCCESS;
wifi_power_fail:
#if defined(CONFIG_HUAWEI_OHOS_DSM) || defined(CONFIG_HUAWEI_DSM)
    if (error != WIFI_POWER_ON_FIRMWARE_DOWNLOAD_INTERRUPT && error != WIFI_POWER_ON_FIRMWARE_FILE_OPEN_FAIL) {
        hw_mpxx_dsm_client_notify(SYSTEM_TYPE_PLATFORM, DSM_MPXX_DOWNLOAD_FIRMWARE,
                                  "%s: failed to download firmware, bfgx %s, error=%d\n",
                                  __FUNCTION__, bfgx_is_shutdown() ? "off" : "on", error);
    }
#endif
    return error;
}

STATIC int32_t mp13_get_board_pmu_clk32k(void)
{
    g_st_board_info.clk_32k_name = "clk_pmu32kb";
    ps_print_info("mpxx 32k clk name is %s\n", g_st_board_info.clk_32k_name);

    return BOARD_SUCC;
}

STATIC int32_t mp13_get_board_uart_port(void)
{
    g_st_board_info.uart_port[BUART] = "/dev/ttySC_SPI0";
    g_st_board_info.uart_pclk = UART_PCLK_NORMAL;
    ps_print_info("g_st_board_info.uart_port=%s\n", g_st_board_info.uart_port[BUART]);
    return BOARD_SUCC;
}

STATIC int32_t mp13_check_evb_or_fpga(void)
{
    ps_print_info("mp13 ASIC VERSION\n");
    g_st_board_info.is_asic = VERSION_ASIC;
    return BOARD_SUCC;
}

STATIC int32_t mp13_check_mpxx_subsystem_support(void)
{
    g_st_board_info.is_wifi_disable = 0;
    g_st_board_info.is_bfgx_disable = 0;
    g_st_board_info.is_gt_disable = 1;
    ps_print_info("wifi %s, bfgx %s\n",
                  (g_st_board_info.is_wifi_disable == 0) ? "enabled" : "disabled",
                  (g_st_board_info.is_bfgx_disable == 0) ? "enabled" : "disabled");
    return BOARD_SUCC;
}

STATIC int32_t mp13_check_pmu_clk_share(void)
{
    g_st_board_info.pmu_clk_share_enable = PMU_CLK_REQ_DISABLE;
    ps_print_info("mpxx PMU clk request is %s\n", (g_st_board_info.pmu_clk_share_enable ? "enable" : "disable"));
    return BOARD_SUCC;
}

STATIC int32_t mp13_board_get_power_pinctrl(void)
{
    ps_print_info("no need prepare before board power on\n");
    g_st_board_info.need_power_prepare = NO_NEED_POWER_PREPARE;
    return BOARD_SUCC;
}

STATIC int32_t mp13_gpio_kungpeng_init(struct platform_device *pdev)
{
    int32_t ret;

    ret = mp13_board_flowctrl_gpio_init();
    if (ret != BOARD_SUCC) {
        ps_print_err("get wifi tas prop failed\n");
        chr_exception_report(CHR_PLATFORM_EXCEPTION_EVENTID, CHR_SYSTEM_PLAT, CHR_LAYER_DRV,
                             CHR_PLT_DRV_EVENT_INIT, CHR_PLAT_DRV_ERROR_BOARD_GPIO_INIT);
        return BOARD_FAIL;
    }

    return BOARD_SUCC;
}

STATIC void mp13_gpio_kunpeng_free(struct platform_device *pdev)
{
    mp13_free_board_flowctrl_gpio();
}

STATIC int32_t mp13_sys_attr_kunpeng_init(struct platform_device *pdev)
{
    int32_t ret;
    ret = mp13_check_mpxx_subsystem_support();
    if (ret != BOARD_SUCC) {
        ps_print_err("mpxx_check_mpxx_subsystem_support failed\n");
        goto sys_cfg_fail;
    }

    ret = mp13_check_evb_or_fpga();
    if (ret != BOARD_SUCC) {
        ps_print_err("mpxx_check_evb_or_fpga failed\n");
        goto sys_cfg_fail;
    }

    ret = mp13_check_pmu_clk_share();
    if (ret != BOARD_SUCC) {
        ps_print_err("mpxx_check_pmu_clk_share failed\n");
        goto sys_cfg_fail;
    }

    ret = mp13_get_board_pmu_clk32k();
    if (ret != BOARD_SUCC) {
        ps_print_err("mpxx_check_pmu_clk_share failed\n");
        goto sys_cfg_fail;
    }

    ret = mp13_get_board_uart_port();
    if (ret != BOARD_SUCC) {
        ps_print_err("get uart port failed\n");
        goto sys_cfg_fail;
    }

    ret = mp13_board_get_power_pinctrl();
    if (ret != BOARD_SUCC) {
        ps_print_err("mpxx_board_get_power_pinctrl failed\n");
        goto sys_cfg_fail;
    }

    return BOARD_SUCC;

sys_cfg_fail:
    return  BOARD_FAIL;
}

void board_info_init_kunpeng(void)
{
    g_st_board_info.bd_ops.board_gpio_init = mp13_gpio_kungpeng_init;
    g_st_board_info.bd_ops.board_gpio_free = mp13_gpio_kunpeng_free;
    g_st_board_info.bd_ops.board_sys_attr_init = mp13_sys_attr_kunpeng_init;

    g_st_board_info.bd_ops.bfgx_dev_power_on = mp13_bfgx_dev_power_on;
    g_st_board_info.bd_ops.bfgx_dev_power_off = mp13_bfgx_dev_power_off;
    g_st_board_info.bd_ops.wlan_power_off = mp13_wlan_power_off;
    g_st_board_info.bd_ops.wlan_power_on = mp13_wlan_power_on;
    g_st_board_info.bd_ops.board_power_on = mp13_board_power_on;
    g_st_board_info.bd_ops.board_power_off = mp13_board_power_off;
    g_st_board_info.bd_ops.board_power_reset = mp13_board_power_reset;
}

/* factory test, wifi power on, do some test under bootloader mode */
void mp13_dump_gpio_regs(void)
{
    uint16_t value;
    int32_t ret;
    value = 0;
    ret = read_device_reg16(GPIO_BASE_ADDR + GPIO_INOUT_CONFIG_REGADDR, &value);
    if (ret) {
        return;
    }

    oal_print_mpxx_log(MPXX_LOG_INFO, "gpio reg 0x%x = 0x%x", GPIO_BASE_ADDR + GPIO_INOUT_CONFIG_REGADDR, value);

    value = 0;
    ret = read_device_reg16(GPIO_BASE_ADDR + GPIO_LEVEL_GET_REGADDR, &value);
    if (ret) {
        return;
    }

    oal_print_mpxx_log(MPXX_LOG_INFO, "gpio reg 0x%x = 0x%x", GPIO_BASE_ADDR + GPIO_LEVEL_GET_REGADDR, value);
}

int32_t mp13_check_device_ready(void)
{
    uint16_t value;
    int32_t ret;

    value = 0;
    ret = read_device_reg16(CHECK_DEVICE_RDY_ADDR, &value);
    if (ret) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "read 0x%x reg failed, ret=%d", CHECK_DEVICE_RDY_ADDR, ret);
        return -OAL_EFAIL;
    }

    /* 读到0x101表示成功 */
    if (value != 0x101) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "device sysctrl reg error, value=0x%x", value);
        return -OAL_EFAIL;
    }

    return OAL_SUCC;
}

int32_t mp13_check_wlan_wakeup_host_config(void)
{
    uint16_t value;
    int32_t ret;

    value = 0;
    ret = read_device_reg16(GPIO_BASE_ADDR + GPIO_INOUT_CONFIG_REGADDR, &value);
    if (ret) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "read 0x%x reg failed, ret=%d",
                           (GPIO_BASE_ADDR + GPIO_INOUT_CONFIG_REGADDR), ret);
        return -1;
    }

    /* * 输出 */
    value |= (WLAN_DEV2HOST_GPIO);

    ret = write_device_reg16(GPIO_BASE_ADDR + GPIO_INOUT_CONFIG_REGADDR, value);
    if (ret) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "write 0x%x reg failed,value=0x%x, ret=%d",
                           (GPIO_BASE_ADDR + GPIO_INOUT_CONFIG_REGADDR), value, ret);
        return -1;
    }
    return OAL_SUCC;
}

int32_t mp13_check_wlan_wakeup_host(void)
{
    int32_t i;
    int32_t ret;
    const uint32_t test_times = 2;

    if (conn_gpio_valid(W_WKUP_HOST) == OAL_FALSE) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "wlan_wakeup_host gpio is invalid!");
        return -OAL_EIO;
    }

    ret = mp13_check_wlan_wakeup_host_config();
    if (ret) {
        return ret;
    }

    for (i = 0; i < test_times; i++) {
        ret = write_device_reg16(GPIO_BASE_ADDR + GPIO_LEVEL_CONFIG_REGADDR, WLAN_DEV2HOST_GPIO);
        if (ret) {
            oal_print_mpxx_log(MPXX_LOG_ERR, "write 0x%x reg failed,value=0x%x, ret=%d",
                               (GPIO_BASE_ADDR + GPIO_LEVEL_CONFIG_REGADDR), WLAN_DEV2HOST_GPIO, ret);
            return -1;
        }

        oal_msleep(1);

        if (conn_get_gpio_level(W_WKUP_HOST) == 0) {
            oal_print_mpxx_log(MPXX_LOG_ERR, "pull gpio high failed!");
            mp13_dump_gpio_regs();
            return -OAL_EFAIL;
        }

        ret = write_device_reg16(GPIO_BASE_ADDR + GPIO_LEVEL_CONFIG_REGADDR, 0x0);
        if (ret) {
            oal_print_mpxx_log(MPXX_LOG_ERR, "write 0x%x reg failed,value=0x%x, ret=%d",
                               (GPIO_BASE_ADDR + GPIO_LEVEL_CONFIG_REGADDR), WLAN_DEV2HOST_GPIO, ret);
            return -1;
        }

        oal_msleep(1);

        if (conn_get_gpio_level(W_WKUP_HOST) != 0) {
            oal_print_mpxx_log(MPXX_LOG_ERR, "pull gpio low failed!");
            mp13_dump_gpio_regs();
            return -OAL_EFAIL;
        }

        oal_print_mpxx_log(MPXX_LOG_INFO, "check d2h wakeup io %d times ok", i + 1);
    }

    oal_print_mpxx_log(MPXX_LOG_INFO, "check d2h wakeup io done");
    return OAL_SUCC;
}

int32_t mp13_check_host_wakeup_wlan_direction(void)
{
    uint16_t value;
    int32_t ret;

    value = 0;
    ret = read_device_reg16(GPIO_BASE_ADDR + GPIO_INOUT_CONFIG_REGADDR, &value);
    if (ret) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "read 0x%x reg failed, ret=%d",
                           (GPIO_BASE_ADDR + GPIO_INOUT_CONFIG_REGADDR), ret);
        return -1;
    }

    /* * 输入 */
    value &= (~WLAN_HOST2DEV_GPIO);

    ret = write_device_reg16(GPIO_BASE_ADDR + GPIO_INOUT_CONFIG_REGADDR, value);
    if (ret) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "write 0x%x reg failed,value=0x%x, ret=%d",
                           (GPIO_BASE_ADDR + GPIO_INOUT_CONFIG_REGADDR), value, ret);
        return -1;
    }
    return ret;
}

int32_t mp13_check_host_wakeup_wlan_value(void)
{
    int32_t i, ret;
    uint16_t value;
    int32_t gpio_nr;
    const uint32_t test_times = 2;

    gpio_nr = conn_get_gpio_number_by_type(HOST_WKUP_W);
    for (i = 0; i < test_times; i++) {
        gpio_direction_output(gpio_nr, GPIO_HIGHLEVEL);
        oal_msleep(1);

        value = 0;
        ret = read_device_reg16(GPIO_BASE_ADDR + GPIO_LEVEL_GET_REGADDR, &value);
        if (ret) {
            oal_print_mpxx_log(MPXX_LOG_ERR, "read 0x%x reg failed, ret=%d",
                               (GPIO_BASE_ADDR + GPIO_LEVEL_GET_REGADDR), ret);
            return -1;
        }

        oal_print_mpxx_log(MPXX_LOG_DBG, "read 0x%x reg=0x%x", (GPIO_BASE_ADDR + GPIO_LEVEL_GET_REGADDR), value);

        value &= WLAN_HOST2DEV_GPIO;

        if (value == 0) {
            oal_print_mpxx_log(MPXX_LOG_ERR, "pull gpio high failed!");
            mp13_dump_gpio_regs();
            return -OAL_EFAIL;
        }

        gpio_direction_output(gpio_nr, GPIO_LOWLEVEL);
        oal_msleep(1);

        value = 0;
        ret = read_device_reg16(GPIO_BASE_ADDR + GPIO_LEVEL_GET_REGADDR, &value);
        if (ret) {
            oal_print_mpxx_log(MPXX_LOG_ERR, "read 0x%x reg failed, ret=%d",
                               (GPIO_BASE_ADDR + GPIO_LEVEL_GET_REGADDR), ret);
            return -1;
        }

        oal_print_mpxx_log(MPXX_LOG_DBG, "read 0x%x reg=0x%x", (GPIO_BASE_ADDR + GPIO_LEVEL_GET_REGADDR), value);

        value &= WLAN_HOST2DEV_GPIO;

        if (value != 0) {
            oal_print_mpxx_log(MPXX_LOG_ERR, "pull gpio low failed!");
            mp13_dump_gpio_regs();
            return -OAL_EFAIL;
        }

        oal_print_mpxx_log(MPXX_LOG_INFO, "check h2d wakeup io %d times ok", i + 1);
    }
    return 0;
}

int32_t mp13_check_host_wakeup_wlan(void)
{
    int32_t ret;

    if ((conn_gpio_valid(HOST_WKUP_W)== OAL_TRUE)) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "host_wakeup_wlan gpio is zero!");
        return -OAL_EIO;
    }

    ret = mp13_check_host_wakeup_wlan_direction();
    if (ret) {
        return ret;
    }

    ret = mp13_check_host_wakeup_wlan_value();
    if (ret) {
        return ret;
    }

    oal_print_mpxx_log(MPXX_LOG_INFO, "check h2d wakeup io done");
    return 0;
}

int32_t mp13_check_wlan_gpio(void)
{
    int32_t ret;
    struct wlan_pm_s *wlan_pm_info = wlan_pm_get_drv();

    /* power on wifi, need't download firmware */
    ret = mp13_board_power_on(W_SYS);
    if (ret) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "power on wlan failed=%d", ret);
        goto IO_CHECK_FAIL;
    }

    hcc_bus_power_action(hcc_get_bus(HCC_EP_WIFI_DEV), HCC_BUS_POWER_PATCH_LOAD_PREPARE);
    ret = hcc_bus_reinit(wlan_pm_info->pst_bus);
    if (ret != OAL_SUCC) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "reinit bus %d failed, ret=%d", wlan_pm_info->pst_bus->bus_type, ret);
        goto IO_CHECK_FAIL;
    }

    wlan_pm_init_dev();
    ret = mp13_check_device_ready();
    if (ret) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "check_device_ready failed, ret=%d", ret);
        goto IO_CHECK_FAIL;
    }

    /* check io */
    ret = mp13_check_host_wakeup_wlan();
    if (ret) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "check_host_wakeup_wlan failed, ret=%d", ret);
        goto IO_CHECK_FAIL;
    }

    (void)mp13_board_power_off(W_SYS);
    return OAL_SUCC;
IO_CHECK_FAIL:
    if (!g_ft_fail_powerdown_bypass) {
        mp13_board_power_off(W_SYS);
    }
    hcc_bus_and_wake_unlock(wlan_pm_info->pst_bus);
    return ret;
}

int32_t hi1103_dev_io_test(void)
{
    int32_t ret;
    declare_time_cost_stru(cost);

    struct wlan_pm_s *wlan_pm_info = wlan_pm_get_drv();
    if (wlan_pm_info == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "wlan_pm_info is NULL!");
        return -FAILURE;
    }

    if (!bfgx_is_shutdown()) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "bfgx is open, test abort!");
        bfgx_print_subsys_state(BUART);
        return -OAL_ENODEV;
    }

    if (!wlan_is_shutdown()) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "wlan is open, test abort!");
        return -OAL_ENODEV;
    }

    oal_get_time_cost_start(cost);

    hcc_bus_and_wake_lock(wlan_pm_info->pst_bus);

    /* check io */
    ret = mp13_check_wlan_gpio();
    if (ret) {
        return ret;
    }

    hcc_bus_and_wake_unlock(wlan_pm_info->pst_bus);

    oal_get_time_cost_end(cost);
    oal_calc_time_cost_sub(cost);
    oal_print_mpxx_log(MPXX_LOG_INFO, "mp13 device io test cost %llu us", time_cost_var_sub(cost));
    return OAL_SUCC;
}

#ifdef _PRE_PLAT_FEATURE_HI110X_PCIE
OAL_STATIC int32_t pcie_ip_test_pre(hcc_bus **old_bus)
{
    if (!bfgx_is_shutdown()) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "bfgx is open, test abort!");
        bfgx_print_subsys_state(BUART);
        return -OAL_ENODEV;
    }

    if (!wlan_is_shutdown()) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "wlan is open, test abort!");
        return -OAL_ENODEV;
    }

    *old_bus = hcc_get_bus(HCC_EP_WIFI_DEV);
    if (*old_bus == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "mpxx_bus is null, test abort!");
        return -OAL_ENODEV;
    }

    return OAL_SUCC;
}

static int32_t power_on_wifi_action(hcc_bus *pst_bus)
{
    int32_t ret;

    /* power on wifi, need't download firmware */
    ret = mp13_board_power_on(W_SYS);
    if (ret) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "power on wlan failed=%d", ret);
        hcc_bus_and_wake_unlock(pst_bus);
        return ret;
    }

    hcc_bus_power_action(pst_bus, HCC_BUS_POWER_PATCH_LOAD_PREPARE);
    return OAL_SUCC;
}

int32_t mp13_pcie_ip_test_core(int32_t test_count)
{
    int32_t ret;
    hcc_bus *pst_bus = NULL;
    pst_bus = hcc_get_bus(HCC_EP_WIFI_DEV);

    hcc_bus_and_wake_lock(pst_bus);
    ret = power_on_wifi_action(pst_bus);
    if (ret != OAL_SUCC) {
        return ret;
    }

    ret = hcc_bus_reinit(pst_bus);
    if (ret != OAL_SUCC) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "reinit bus %s failed, ret=%d", pst_bus->name, ret);
        ssi_dump_device_regs(SSI_MODULE_MASK_COMM | SSI_MODULE_MASK_PCIE_CFG);
        goto PCIE_IP_TEST_FAIL;
    }

    wlan_pm_init_dev();

    ret = mp13_check_device_ready();
    if (ret) {
        ssi_dump_device_regs(SSI_MODULE_MASK_COMM | SSI_MODULE_MASK_PCIE_CFG);
        oal_print_mpxx_log(MPXX_LOG_ERR, "check_device_ready failed, ret=%d", ret);
        goto PCIE_IP_TEST_FAIL;
    }

    ret = oal_pcie_ip_factory_test(pst_bus, test_count);
    if (ret) {
        ssi_dump_device_regs(SSI_MODULE_MASK_COMM | SSI_MODULE_MASK_PCIE_CFG);
        oal_print_mpxx_log(MPXX_LOG_ERR, "pcie_ip_factory_test failed, ret=%d", ret);
        goto PCIE_IP_TEST_FAIL;
    }

    (void)mp13_board_power_off(W_SYS);
    hcc_bus_and_wake_unlock(pst_bus);
    return OAL_SUCC;
PCIE_IP_TEST_FAIL:
    if (!g_ft_fail_powerdown_bypass) {
        mp13_board_power_off(W_SYS);
    }
    hcc_bus_and_wake_unlock(pst_bus);
    return ret;
}

static int32_t bus_switch_to_pice_test(hcc_bus *old_bus)
{
    int32_t ret;
    if (old_bus->bus_type != HCC_BUS_PCIE) {
        /* 尝试切换到PCIE */
        ret = hcc_switch_bus(HCC_EP_WIFI_DEV, HCC_BUS_PCIE);
        if (ret) {
            oal_print_mpxx_log(MPXX_LOG_ERR, "switch to PCIe failed, ret=%d", ret);
            return -OAL_ENODEV;
        }
        oal_print_mpxx_log(MPXX_LOG_INFO, "switch to PCIe ok.");
    } else {
        old_bus = NULL;
    }
    return OAL_SUCC;
}

int32_t hi1103_pcie_ip_test(int32_t test_count)
{
    int32_t ret;
    hcc_bus *old_bus = NULL;
    declare_time_cost_stru(cost);

    if (oal_pcie_mpxx_working_check() != OAL_TRUE) {
        /* 不支持PCIe,直接返回成功 */
        oal_print_mpxx_log(MPXX_LOG_WARN, "do not support PCIe!");
        return OAL_SUCC;
    }

    ret = pcie_ip_test_pre(&old_bus);
    if (ret != OAL_SUCC) {
        return -OAL_EFAIL;
    }

    ret = bus_switch_to_pice_test(old_bus);
    if (ret != OAL_SUCC) {
        return -OAL_ENODEV;
    }

    oal_get_time_cost_start(cost);

    ret = mp13_pcie_ip_test_core(test_count);
    if (ret) {
        return ret;
    }

    if (old_bus != NULL) {
        ret = hcc_switch_bus(HCC_EP_WIFI_DEV, old_bus->bus_type);
        if (ret) {
            oal_print_mpxx_log(MPXX_LOG_ERR, "restore to bus %s failed, ret=%d", old_bus->name, ret);
            return -OAL_ENODEV;
        }
        oal_print_mpxx_log(MPXX_LOG_INFO, "resotre to bus %s ok.", old_bus->name);
    }

    oal_get_time_cost_end(cost);
    oal_calc_time_cost_sub(cost);
    oal_print_mpxx_log(MPXX_LOG_INFO, "mp13 pcie ip test %llu us", time_cost_var_sub(cost));

    return OAL_SUCC;
}

EXPORT_SYMBOL(hi1103_pcie_ip_test);
EXPORT_SYMBOL(hi1103_dev_io_test);
OAL_STATIC uint32_t g_slt_pcie_status = 0;
OAL_STATIC hcc_bus *g_slt_old_bus = NULL;
/* for kirin slt test */
int32_t mp13_pcie_chip_poweron_core(void)
{
    int32_t ret;
    hcc_bus *pst_bus = NULL;
    pst_bus = hcc_get_bus(HCC_EP_WIFI_DEV);

    hcc_bus_and_wake_lock(pst_bus);
    ret = power_on_wifi_action(pst_bus);
    if (ret != OAL_SUCC) {
        return ret;
    }

    ret = hcc_bus_reinit(pst_bus);
    if (ret != OAL_SUCC) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "reinit bus %d failed, ret=%d", pst_bus->bus_type, ret);
        ssi_dump_device_regs(SSI_MODULE_MASK_COMM | SSI_MODULE_MASK_PCIE_CFG);
        goto PCIE_CHIP_POWERON_CORE_FAIL;
    }

    wlan_pm_init_dev();

    ret = mp13_check_device_ready();
    if (ret) {
        ssi_dump_device_regs(SSI_MODULE_MASK_COMM | SSI_MODULE_MASK_PCIE_CFG);
        oal_print_mpxx_log(MPXX_LOG_ERR, "check_device_ready failed, ret=%d", ret);
        goto PCIE_CHIP_POWERON_CORE_FAIL;
    }

    ret = oal_pcie_ip_init(pst_bus);
    if (ret) {
        ssi_dump_device_regs(SSI_MODULE_MASK_COMM | SSI_MODULE_MASK_PCIE_CFG);
        oal_print_mpxx_log(MPXX_LOG_ERR, "oal_pcie_ip_init failed, ret=%d", ret);
        goto PCIE_CHIP_POWERON_CORE_FAIL;
    }

    ret = oal_pcie_ip_voltage_bias_init(pst_bus);
    if (ret) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "voltage_bias_init failed, ret=%d", ret);
        goto PCIE_CHIP_POWERON_CORE_FAIL;
    }
    return OAL_SUCC;
PCIE_CHIP_POWERON_CORE_FAIL:
    if (!g_ft_fail_powerdown_bypass) {
        mp13_board_power_off(W_SYS);
    }
    hcc_bus_and_wake_unlock(pst_bus);
    return ret;
}

int32_t hi110x_pcie_chip_poweron(void *data)
{
    int32_t ret;
    hcc_bus *old_bus = NULL;

    if (oal_pcie_mpxx_working_check() != OAL_TRUE) {
        /* 不支持PCIe,直接返回成功 */
        oal_print_mpxx_log(MPXX_LOG_WARN, "do not support PCIe!");
        return -OAL_ENODEV;
    }

    ret = pcie_ip_test_pre(&old_bus);
    if (ret != OAL_SUCC) {
        return -OAL_EFAIL;
    }

    ret = bus_switch_to_pice_test(old_bus);
    if (ret != OAL_SUCC) {
        return -OAL_ENODEV;
    }

    g_slt_old_bus = old_bus;

    ret = mp13_pcie_chip_poweron_core();
    if (ret) {
        return ret;
    }

    g_slt_pcie_status = 1;

    return 0;
}

int32_t hi110x_pcie_chip_poweroff(void *data)
{
    int32_t ret;
    hcc_bus *pst_bus;

    pst_bus = hcc_get_bus(HCC_EP_WIFI_DEV);
    if (pst_bus == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "can't find any wifi bus");
        return -OAL_ENODEV;
    }

    if (pst_bus->bus_type != HCC_BUS_PCIE) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "current bus is %s , not PCIe", pst_bus->name);
        return -OAL_ENODEV;
    }

    if (g_slt_pcie_status != 1) {
        oal_print_mpxx_log(MPXX_LOG_WARN, "pcie slt is not power on");
        return -OAL_EBUSY;
    }

    g_slt_pcie_status = 0;

    /* SLT下电之前打印链路信息 */
    hcc_bus_chip_info(pst_bus, OAL_FALSE, OAL_TRUE);

    (void)mp13_board_power_off(W_SYS);

    hcc_bus_and_wake_unlock(pst_bus);

    if (g_slt_old_bus != NULL) {
        ret = hcc_switch_bus(HCC_EP_WIFI_DEV, g_slt_old_bus->bus_type);
        if (ret) {
            oal_print_mpxx_log(MPXX_LOG_ERR, "restore to bus %s failed, ret=%d", g_slt_old_bus->name, ret);
            return -OAL_ENODEV;
        }
        oal_print_mpxx_log(MPXX_LOG_INFO, "resotre to bus %s ok.", g_slt_old_bus->name);
    }

    return 0;
}

int32_t hi110x_pcie_chip_transfer(void *ddr_address, uint32_t data_size, uint32_t direction)
{
    hcc_bus *pst_bus;

    if (oal_unlikely(oal_any_null_ptr1(ddr_address))) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "ddr_address is null");
        return -OAL_ENODEV;
    }

    pst_bus = hcc_get_bus(HCC_EP_WIFI_DEV);
    if (pst_bus == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "can't find any wifi bus");
        return -OAL_ENODEV;
    }

    if (pst_bus->bus_type != HCC_BUS_PCIE) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "current bus is %s , not PCIe", pst_bus->name);
        return -OAL_ENODEV;
    }

    return oal_pcie_rc_slt_chip_transfer(pst_bus, ddr_address, data_size, (int32_t)direction);
}
EXPORT_SYMBOL(hi110x_pcie_chip_poweron);
EXPORT_SYMBOL(hi110x_pcie_chip_transfer);
EXPORT_SYMBOL(hi110x_pcie_chip_poweroff);
#endif

#if (defined(CONFIG_PCIE_KIRIN_SLT_HI110X)|| defined(CONFIG_PCIE_KPORT_SLT_DEVICE)) && defined(CONFIG_HISI_DEBUG_FS)
int pcie_slt_hook_register(u32 rc_id, u32 device_type, int (*init)(void *), int (*on)(void *),
    int (*off)(void *), int (*setup)(void *), int (*data_transfer)(void *, u32, u32));
int32_t mp13_pcie_chip_init(void *data)
{
    oal_print_mpxx_log(MPXX_LOG_INFO, "slt pcie init");
    return 0;
}

int32_t hi1103_pcie_chip_rc_slt_register(void)
{
#ifdef _PRE_PLAT_FEATURE_HI110X_PCIE
    return pcie_slt_hook_register(g_kirin_rc_idx, 0x2,
                                  mp13_pcie_chip_init, hi110x_pcie_chip_poweron,
                                  hi110x_pcie_chip_poweroff, mp13_pcie_chip_init,
                                  hi110x_pcie_chip_transfer);
#else
    return 0;
#endif
}

int32_t hi1103_pcie_chip_rc_slt_unregister(void)
{
#ifdef _PRE_PLAT_FEATURE_HI110X_PCIE
    return pcie_slt_hook_register(g_kirin_rc_idx, 0x2,
                                  NULL, NULL,
                                  NULL, NULL,
                                  NULL);
#else
    return 0;
#endif
}
EXPORT_SYMBOL(hi1103_pcie_chip_rc_slt_register);
EXPORT_SYMBOL(hi1103_pcie_chip_rc_slt_unregister);
#endif
