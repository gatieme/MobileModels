/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2016-2021.
 * Description: wlan extersion feature
 * Author: y00265214
 * Create: 2017-03-03
 */
#ifndef HW_WLAN_H
#define HW_WLAN_H
#include <linux/types.h> /* for size_t */

#ifndef DSM_WIFI_ICMP_WAKEUP_ERROR
#define DSM_WIFI_ICMP_WAKEUP_ERROR (909030002)
#endif
#ifndef DSM_WIFI_MODULE_INIT_ERROR
#define DSM_WIFI_MODULE_INIT_ERROR (909030001)
#endif
#ifndef DSM_WIFI_FIRMWARE_DL_ERROR
#define DSM_WIFI_FIRMWARE_DL_ERROR (909030007)
#endif
#ifndef DSM_WIFI_SET_KEY_MGMT_ERROR
#define DSM_WIFI_SET_KEY_MGMT_ERROR (909030017)
#endif
#ifndef DSM_WIFI_OPEN_ERROR
#define DSM_WIFI_OPEN_ERROR (909030019)
#endif
#ifndef DSM_WIFI_FIRMWARE_RESET_ERROR
#define DSM_WIFI_FIRMWARE_RESET_ERROR (909030041)
#endif
#ifndef DSM_PCIE_LINKFAIL_ERROR
#define DSM_PCIE_LINKFAIL_ERROR (909030032)
#endif

#ifndef DSM_PCIE_SWITCH_SDIO_FAIL
#define DSM_PCIE_SWITCH_SDIO_FAIL (909030043)
#endif
#ifndef DSM_PCIE_SWITCH_SDIO_SUCC
#define DSM_PCIE_SWITCH_SDIO_SUCC (909030044)
#endif

void hw_wlan_dsm_register_client(void);
void hw_wlan_dsm_unregister_client(void);
void hw_wlan_dsm_client_notify(int dsm_id, const char *fmt, ...);
int hw_wlan_get_cust_ini_path(char *ini_path, size_t len);
bool hw_wlan_is_driver_match(const char *driver_module_name);
const void *hw_wlan_get_board_name(void);

#ifdef CONFIG_CONNECTIVITY_HI110X
#ifdef CONFIG_ARCH_QCOM
extern int hi11xx_wifi_plat_complete(void);
extern int set_slave_wlan_mac_address(const u8 *mac_list, const uint32_t len);
#endif
#endif

#endif //HW_WLAN_H
