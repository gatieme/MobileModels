/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2022. All rights reserved.
 */
#ifndef _NFC_KERNEL_COMMON_H_
#define _NFC_KERNEL_COMMON_H_

#include <linux/fs.h>
#include <linux/i2c.h>
#include <linux/platform_device.h>

typedef ssize_t (*attr_show_wrapper)(struct device *dev, struct device_attribute *attr, char *buf);
typedef ssize_t (*attr_store_wrapper)(struct device *dev, struct device_attribute *attr, const char *buf, size_t count);

enum NFC_CHIPTYPE {
	NFCTYPE_INVALID = 0,
	NFCTYPE_ST21NFC = 1, // st54h or st21
	NFCTYPE_NXP     = 2, // pn80t
	NFCTYPE_SN110   = 3,
	NFCTYPE_ST54K   = 4,
	NFCTYPE_THN31   = 5,
	NFCTYPE_PN553   = 6,
	MAX_CHIP_TYPE
};

int create_common_sysfs_interfaces(struct device *dev);
void remove_common_sysfs_interfaces(struct device *dev);
int nfc_get_dts_config_u32(const char *node_name, const char *prop_name, u32 *pvalue);
void get_nfc_wired_ese_type(void);
void get_nfc_chip_type(void);
int nfc_get_ese_spi_bus(void);
int nfc_get_ese_pwr_req_gpio(void);
void get_nfc_config_name(const struct device *dev);
void set_nfc_single_channel(const struct device *dev);
int nfc_record_dmd_info(long dmd_no, const char *dmd_info);
int get_chip_value(void);
int get_ese_spi_bus(void);
int get_ese_svdd_pwr_req(void);
void set_wait_event_interruptible_ret(int input);
bool get_is_uid(void);
void set_is_uid(bool input);
void set_nfc_clk_src(int input);
attr_show_wrapper get_nfc_sim_status_show_pointer(void);
attr_show_wrapper get_nfc_sim_switch_show_pointer(void);
attr_store_wrapper get_nfc_sim_switch_store_pointer(void);
attr_show_wrapper get_rd_nfc_sim_status_show_pointer(void);
attr_show_wrapper get_nfc_enable_status_show_pointer(void);
attr_store_wrapper get_nfc_enable_status_store_pointer(void);
attr_show_wrapper get_nfc_recovery_close_nfc_show_pointer(void);
attr_store_wrapper get_nfc_recovery_close_nfc_store_pointer(void);
void set_nfc_sim_status_show_pointer(attr_show_wrapper nfc_show_p);
void set_nfc_sim_switch_store_pointer(attr_store_wrapper nfc_store_p);
void set_nfc_sim_switch_show_pointer(attr_show_wrapper nfc_show_p);
void set_rd_nfc_sim_status_show_pointer(attr_show_wrapper nfc_show_p);
void set_nfc_enable_status_show_pointer(attr_show_wrapper nfc_show_p);
void set_nfc_enable_status_store_pointer(attr_store_wrapper nfc_store_p);
void set_nfc_recovery_close_nfc_show_pointer(attr_show_wrapper nfc_show_p);
void set_nfc_recovery_close_nfc_store_pointer(attr_store_wrapper nfc_store_p);

#ifdef CONFIG_HUAWEI_DSM
struct dsm_client* get_nfc_dclient(void);
void set_nfc_dclient(struct dsm_client *input);
#endif

int *get_g_nfc_qcom_activated(void);

#endif

