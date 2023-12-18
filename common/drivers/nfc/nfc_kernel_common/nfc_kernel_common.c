/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2022. All rights reserved.
 * Description: Create NFC file system nodes and register the NFC driver.
 * Create: January 10, 2022
 */

#include <huawei_platform/log/hw_log.h>

#include "securec.h"
#include "nfc_kernel_common.h"

#ifdef CONFIG_HUAWEI_HW_DEV_DCT
#include <hwmanufac/dev_detect/dev_detect.h>
#endif

#ifdef CONFIG_HUAWEI_DSM
#include <dsm/dsm_pub.h>
#include <linux/errno.h>
#endif

enum NFC_ESE_TYPE {
	NFC_WITHOUT_ESE = 0,
	NFC_ESE_P61,
	NFC_ESE_HISEE,
};

#define NFC_CLK_SRC_CPU 0
#define MAX_CONFIG_NAME_SIZE 64
#define MAX_NFC_CHIP_TYPE_SIZE 32
#define UICC_SUPPORT_CARD_EMULATION (1<<0)
#define MAX_ATTRIBUTE_BUFFER_SIZE 128
#define NFC_DMD_NUMBER_MIN 923002000
#define NFC_DMD_NUMBER_MAX 923002016
#define CHAR_0 48
#define MAX_DETECT_SE_SIZE 32

#define MAX_CHIP_LENGTH 8 /* The supported NFC chip types are listed as follows: */
#define NFC_CHIP_ST "st21nfc"
#define NFC_CHIP_THN31 "thn31"
#define NFC_CHIP_ST54K "st54k"
#define NFC_CHIP_PN553 "pn553"
#define NFC_CHIP_PN80T "pn80t"
#define NFC_CHIP_SN110U "sn110u"
#define NFC_CHIP_SZ "nfc_sz"
#define NFC_CHIP_BJ "nfc_bj"

typedef struct {
	const char* type_str;
	int type_value;
} chip_type_mask;

static char nfc_config_name[MAX_CONFIG_NAME_SIZE];
static char nfc_brcm_config_name[MAX_CONFIG_NAME_SIZE];
static char nfc_chip_type[MAX_NFC_CHIP_TYPE_SIZE];
static char nfc_spec_rf_conf[MAX_CONFIG_NAME_SIZE];

/* 0 -- cpu(default); 1 -- pmu; 4 -- XTAL */
static int g_nfc_clk_src = NFC_CLK_SRC_CPU;
static int g_wait_event_interruptible_ret = 0;
static int g_ese_svdd_pwr_req = 0;
static int g_chip_type = NFCTYPE_INVALID;
static bool g_is_uid = false;
static int g_firmware_update = 0;
static int g_nfc_single_channel;
static int g_nfc_at_result;
static int g_nfc_switch_state;
static int g_nfc_activated_se_info; /* record activated se info when nfc enable process */
static int g_nfc_hal_dmd_no = 0; /* record last hal dmd no */
static int g_nfc_ese_type = NFC_WITHOUT_ESE; /* record ese type wired to nfcc by dts */
static int g_ese_spi_bus = 0;

int g_nfc_qcom_activated = 0;

static attr_show_wrapper nfc_sim_status_show_p = NULL;
static attr_show_wrapper nfc_sim_switch_show_p = NULL;
static attr_store_wrapper nfc_sim_switch_store_p = NULL;
static attr_show_wrapper rd_nfc_sim_status_show_p = NULL;
static attr_show_wrapper nfc_enable_status_show_p = NULL;
static attr_store_wrapper nfc_enable_status_store_p = NULL;
static attr_show_wrapper nfc_recovery_close_nfc_show_p = NULL;
static attr_store_wrapper nfc_recovery_close_nfc_store_p = NULL;

#ifdef CONFIG_HUAWEI_DSM
struct dsm_client *nfc_dclient = NULL;
#endif

int *get_g_nfc_qcom_activated(void)
{
	return &g_nfc_qcom_activated;
}

static int nfc_get_dts_config_string(const char *node_name,
	const char *prop_name,
	char *out_string,
	int out_string_len)
{
	struct device_node *np = NULL;
	const char *out_value = NULL;
	int ret = -1;

	for_each_node_with_property(np, node_name) {
		ret = of_property_read_string(np, prop_name, (const char **)&out_value);
		if (ret != 0) {
			pr_err("can not get prop values with prop_name: %s\n", prop_name);
		} else {
			if (out_value == NULL) {
				pr_err("error out_value = NULL\n");
				ret = -1;
			} else if (strlen(out_value) >= out_string_len) {
				pr_err("error out_value len :%d >= out_string_len:%d\n",
							 (int)strlen(out_value), (int)out_string_len);
				ret = -1;
			} else {
				errno_t rc = strcpy_s(out_string, out_string_len, out_value);
				if (rc != EOK) {
					pr_err("memcpy_s failed, err = %d\n", rc);
					return -1;
				}
				pr_info(": =%s\n", out_string);
			}
		}
	}
	return ret;
}

void get_nfc_wired_ese_type(void)
{
	char nfc_on_str[MAX_DETECT_SE_SIZE] = {0};
	int ret;

	if (memset_s(nfc_on_str, sizeof(nfc_on_str), 0, MAX_DETECT_SE_SIZE) != EOK)
		pr_err("memset_s failed, func = %d\n", __func__);
	ret = nfc_get_dts_config_string("nfc_ese_type", "nfc_ese_type",
		nfc_on_str, sizeof(nfc_on_str));
	if (ret != 0) {
		if (memset_s(nfc_on_str, sizeof(nfc_on_str), 0, MAX_DETECT_SE_SIZE) != EOK)
			pr_err("memset_s failed, func = %d\n", __func__);
		g_nfc_ese_type = NFC_WITHOUT_ESE;
		pr_err("%s: can't find nfc_ese_type node\n", __func__);
		return;
	} else {
		if (!strncasecmp(nfc_on_str, "hisee", strlen("hisee"))) {
			g_nfc_ese_type = NFC_ESE_HISEE;
		} else if (!strncasecmp(nfc_on_str, "p61", strlen("p61"))) {
			g_nfc_ese_type = NFC_ESE_P61;
		} else if (!strncasecmp(nfc_on_str, "thd89", strlen("thd89"))) {
			g_nfc_ese_type = NFC_ESE_P61;
		} else {
			g_nfc_ese_type = NFC_WITHOUT_ESE;
		}
	}
	pr_info("%s: nfc_ese_type:%d\n", __func__, g_nfc_ese_type);
	return;
}

void get_nfc_chip_type(void)
{
	char nfc_on_str[MAX_DETECT_SE_SIZE] = {0};
	int ret, cnt;
	chip_type_mask chip_type[MAX_CHIP_LENGTH] = {
		{NFC_CHIP_ST, NFCTYPE_ST21NFC},
		{NFC_CHIP_THN31, NFCTYPE_THN31},
		{NFC_CHIP_ST54K, NFCTYPE_ST54K},
		{NFC_CHIP_PN553, NFCTYPE_PN553},
		{NFC_CHIP_PN80T, NFCTYPE_NXP},
		{NFC_CHIP_SN110U, NFCTYPE_SN110},
		{NFC_CHIP_SZ, NFCTYPE_SN110},
		{NFC_CHIP_BJ, NFCTYPE_THN31},
	};
	if (memset_s(nfc_on_str, sizeof(nfc_on_str), 0, MAX_DETECT_SE_SIZE) != EOK)
		pr_err("memset_s failed, func = %d\n", __func__);

	ret = nfc_get_dts_config_string("nfc_chip_type", "nfc_chip_type",
		nfc_on_str, sizeof(nfc_on_str));
	if (ret != 0) {
		if (memset_s(nfc_on_str, sizeof(nfc_on_str), 0, MAX_DETECT_SE_SIZE) != EOK)
			pr_err("memset_s failed, func = %d\n", __func__);
		pr_err("%s: can't find nfc_chip_type node\n", __func__);
		return;
	}
	for (cnt = 0; cnt < MAX_CHIP_LENGTH; cnt++) {
		if (chip_type[cnt].type_str == NULL) {
			continue;
		}
		if (!strncasecmp(nfc_on_str, chip_type[cnt].type_str, MAX_DETECT_SE_SIZE)) {
			g_chip_type = chip_type[cnt].type_value;
			break;
		}
	}
	pr_info("%s: nfc_chip_type:%d\n", __func__, g_chip_type);
	return;
}

/* FUNCTION: get_nfc_config_name
 * DESCRIPTION: get nfc configure files' name from device tree system, save result in global variable
 * Parameters
 * none
 * RETURN VALUE
 * none
 */
void get_nfc_config_name(const struct device *dev)
{
	int ret;
	struct device_node *np = dev->of_node;
	const char *out_value = NULL;

	if (memset_s(nfc_config_name, sizeof(nfc_config_name), 0, sizeof(nfc_config_name)) != EOK)
		pr_err("memset_s nfc_config_name failed, func = %d\n", __func__);
	if (memset_s(nfc_brcm_config_name, sizeof(nfc_brcm_config_name), 0, sizeof(nfc_brcm_config_name)) != EOK)
		pr_err("memset_s nfc_brcm_config_name failed, func = %d\n", __func__);
	if (memset_s(nfc_spec_rf_conf, sizeof(nfc_spec_rf_conf), 0, sizeof(nfc_spec_rf_conf)) != EOK)
		pr_err("memset_s nfc_spec_rf_conf failed, func = %d\n", __func__);

	/* get nfc_nxp_conf_name */
	ret = of_property_read_string(np, "nfc_nxp_conf_name", &out_value);
	if (strncpy_s(nfc_config_name, sizeof(nfc_config_name), out_value, MAX_CONFIG_NAME_SIZE - 1) != EOK)
		pr_err("strncpy_s nfc_config_name failed, func = %d\n", __func__);

	if (ret != 0) {
		if (memset_s(nfc_config_name, sizeof(nfc_config_name), 0, MAX_CONFIG_NAME_SIZE) != EOK)
			pr_err("memset_s nfc_config_name failed, func = %d\n", __func__);
		pr_err("%s: can't get nfc nxp config name\n", __func__);
	}

	/* get nfc_brcm_conf_name */
	ret = of_property_read_string(np, "nfc_brcm_conf_name", &out_value);
	if (strncpy_s(nfc_brcm_config_name, sizeof(nfc_brcm_config_name), out_value, MAX_CONFIG_NAME_SIZE - 1) != EOK)
		pr_err("strncpy_s nfc_brcm_config_name failed, func = %d\n", __func__);
	if (ret != 0) {
		if (memset_s(nfc_brcm_config_name, sizeof(nfc_brcm_config_name), 0, sizeof(nfc_brcm_config_name)) != EOK)
			pr_err("memset_s nfc_brcm_config_name failed, func = %d\n", __func__);
		pr_err("%s: can't get nfc brcm config name\n", __func__);
	}
	/* get nfc_spec_rf_conf_name */
	ret = of_property_read_string(np, "nfc_spec_rf_conf_name", &out_value);
	if (ret == 0) {
		if (strncpy_s(nfc_spec_rf_conf, sizeof(nfc_spec_rf_conf), out_value, MAX_CONFIG_NAME_SIZE - 1) != EOK)
			pr_err("strncpy_s nfc_spec_rf_conf failed, func = %d\n", __func__);
		pr_info("%s: get nfc spec rf conf name\n", __func__);
	}

	return ;
}

/* FUNCTION: nfc_fwupdate_store
 * DESCRIPTION: store nfc firmware update result.
 * Parameters
 * struct device *dev:device structure
 * struct device_attribute *attr:device attribute
 * const char *buf:user buffer
 * size_t count:data count
 * RETURN VALUE
 * ssize_t: result
 */
static ssize_t nfc_fwupdate_store(struct device *dev, struct device_attribute *attr,
	const char *buf, size_t count)
{
	/* if success, store firmware update result into variate firmware_update */
	if (buf[0] == '1') {
		g_firmware_update = 1;
		pr_err("%s:firmware update success\n", __func__);
	}

	return (ssize_t)count;
}

/* FUNCTION: nfc_fwupdate_show
 * DESCRIPTION: show nfc firmware update result.
 * Parameters
 * struct device *dev:device structure
 * struct device_attribute *attr:device attribute
 * const char *buf:user buffer
 * RETURN VALUE
 * ssize_t:  result
 */
static ssize_t nfc_fwupdate_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	/* get firmware update result from variate firmware_update */
	return (ssize_t)(snprintf_s(buf, sizeof(g_firmware_update) + 1, sizeof(g_firmware_update), "%d", g_firmware_update));
}

/* FUNCTION: nxp_config_name_store
 * DESCRIPTION: store nxp_config_name, infact do nothing now.
 * Parameters
 * struct device *dev:device structure
 * struct device_attribute *attr:device attribute
 * const char *buf:user buffer
 * size_t count:data count
 * RETURN VALUE
 * ssize_t:  result
 */
static ssize_t nxp_config_name_store(struct device *dev, struct device_attribute *attr,
	const char *buf, size_t count)
{
	/* no need store config name, do nothing now */
	return (ssize_t)count;
}

/* FUNCTION: nxp_config_name_show
 * DESCRIPTION: get nxp_config_name from variate nfc_config_name.
 * Parameters
 * struct device *dev:device structure
 * struct device_attribute *attr:device attribute
 * const char *buf:user buffer
 * RETURN VALUE
 * ssize_t:  result
 */
static ssize_t nxp_config_name_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return (ssize_t)(snprintf_s(buf, strlen(nfc_config_name) + 1, strlen(nfc_config_name), "%s", nfc_config_name));
}

/* FUNCTION: nfc_spec_rf_conf_name_store
 * DESCRIPTION: store nfc_spec_rf_conf_name, do nothing now.
 * Parameters
 *  struct device *dev:device structure
 *  struct device_attribute *attr:device attribute
 *  const char *buf:user buffer
 *  size_t count:data count
 * RETURN VALUE
 *  ssize_t:  result
 */
static ssize_t nfc_spec_rf_conf_name_store(struct device *dev, struct device_attribute *attr,
			 const char *buf, size_t count)
{
	/* no need store config name, do nothing now */
	return (ssize_t)count;
}

/* FUNCTION: nfc_spec_rf_conf_name_show
 * DESCRIPTION: get nfc spec rf config name from variate g_nfc_spec_rf_conf.
 * Parameters
 *  struct device *dev:device structure
 *  struct device_attribute *attr:device attribute
 *  const char *buf:user buffer
 * RETURN VALUE
 *  ssize_t:  result
 */
static ssize_t nfc_spec_rf_conf_name_show(struct device *dev, struct device_attribute *attr,
			 char *buf)
{
	return (ssize_t)(snprintf_s(buf, strlen(nfc_spec_rf_conf) + 1, strlen(nfc_spec_rf_conf), "%s", nfc_spec_rf_conf));
}

/* FUNCTION: nfc_brcm_conf_name_store
 * DESCRIPTION: store nfc_brcm_conf_name, infact do nothing now.
 * Parameters
 * struct device *dev:device structure
 * struct device_attribute *attr:device attribute
 * const char *buf:user buffer
 * size_t count:data count
 * RETURN VALUE
 * ssize_t:  result
 */
static ssize_t nfc_brcm_conf_name_store(struct device *dev, struct device_attribute *attr,
	const char *buf, size_t count)
{
	/* no need store config name, do nothing now */
	return (ssize_t)count;
}

/* FUNCTION: nfc_brcm_conf_name_show
 * DESCRIPTION: get nfc_brcm_conf_name from variate nfc_brcm_config_name.
 * Parameters
 *	struct device *dev:device structure
 *	struct device_attribute *attr:device attribute
 *	const char *buf:user buffer
 * RETURN VALUE
 *	ssize_t:  result
 */
static ssize_t nfc_brcm_conf_name_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return (ssize_t)(snprintf_s(buf, strlen(nfc_brcm_config_name) + 1,
		strlen(nfc_brcm_config_name), "%s", nfc_brcm_config_name));
}

/* FUNCTION: nfc_card_num_show
 * DESCRIPTION: show supported nfc_card_num, which config in device tree system.
 * Parameters
 * struct device *dev:device structure
 * struct device_attribute *attr:device attribute
 * const char *buf:user buffer
 * RETURN VALUE
 * ssize_t:  result
 */
static ssize_t nfc_card_num_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	int temp = 0;
	int ret;
	struct device_node *np = dev->of_node;

	/* read supported nfc_card_num from device tree system. */
	ret = of_property_read_u32(np, "nfc_card_num", &temp);
	if (ret) {
		temp = UICC_SUPPORT_CARD_EMULATION;
		pr_err("%s: can't get nfc card num config!\n", __func__);
	}
	return (ssize_t)(snprintf_s(buf,  MAX_ATTRIBUTE_BUFFER_SIZE,
		MAX_ATTRIBUTE_BUFFER_SIZE - 1, "%d\n", temp));
}

/* FUNCTION: nfc_chip_type_show
 * DESCRIPTION: show nfc_chip_type, which config in device tree system.
 * Parameters
 * struct device *dev:device structure
 * struct device_attribute *attr:device attribute
 * const char *buf:user buffer
 * RETURN VALUE
 * ssize_t:  result
 */
static ssize_t nfc_chip_type_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	int ret;
	struct device_node *np = dev->of_node;
	const char *out_value = NULL;

	if (memset_s(nfc_chip_type, sizeof(nfc_chip_type), 0, MAX_NFC_CHIP_TYPE_SIZE) != EOK)
		pr_err("memset_s nfc_chip_type failed, func = %d\n", __func__);
	/* read nfc_chip_type from device tree system. */
	ret = of_property_read_string(np, "nfc_chip_type", &out_value);
	if (strncpy_s(nfc_chip_type, sizeof(nfc_chip_type), out_value, MAX_NFC_CHIP_TYPE_SIZE - 1) != EOK)
		pr_err("strncpy_s nfc_chip_type failed, func = %d\n", __func__);

	if (ret != 0) {
		pr_err("%s: can't get nfc nfc_chip_type, default pn547\n", __func__);
		if (strncpy_s(nfc_chip_type, sizeof(nfc_chip_type), "pn547", MAX_NFC_CHIP_TYPE_SIZE - 1) != EOK)
			pr_err("strncpy_s nfc_chip_type failed, func = %d\n", __func__);
	}

	if (!strncasecmp(nfc_chip_type, "nfc_sz", strlen("nfc_sz"))) {
		if (memset_s(nfc_chip_type, sizeof(nfc_chip_type), 0, MAX_NFC_CHIP_TYPE_SIZE) != EOK)
			pr_err("memset_s nfc_chip_type failed, func = %d\n", __func__);
		if (strncpy_s(nfc_chip_type, sizeof(nfc_chip_type), "sn110u", strlen("sn110u")) != EOK)
			pr_err("strncpy_s nfc_chip_type failed, func = %d\n", __func__);
	}

	if (!strncasecmp(nfc_chip_type, "nfc_dg", strlen("nfc_dg"))) {
		if (memset_s(nfc_chip_type, sizeof(nfc_chip_type), 0, MAX_NFC_CHIP_TYPE_SIZE) != EOK)
			pr_err("memset_s nfc_chip_type failed, func = %d\n", __func__);
		if (strncpy_s(nfc_chip_type, sizeof(nfc_chip_type), "pn80t", strlen("pn80t")) != EOK)
			pr_err("strncpy_s nfc_chip_type failed, func = %d\n", __func__);
	}

	if (!strncasecmp(nfc_chip_type, "nfc_bj", strlen("nfc_bj"))) {
		if (memset_s(nfc_chip_type, sizeof(nfc_chip_type), 0, MAX_NFC_CHIP_TYPE_SIZE) != EOK)
			pr_err("memset_s nfc_chip_type failed, func = %d\n", __func__);
		if (strncpy_s(nfc_chip_type, sizeof(nfc_chip_type), "thn31", strlen("thn31")) != EOK)
			pr_err("strncpy_s nfc_chip_type failed, func = %d\n", __func__);
	}

	return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE, MAX_ATTRIBUTE_BUFFER_SIZE - 1, "%s", nfc_chip_type));
}

void set_nfc_single_channel(const struct device *dev)
{
	int ret;
	struct device_node *np = dev->of_node;
	const char *out_value = NULL;

	pr_err("%s: nfc single channel begin:%d\n", __func__, g_nfc_single_channel);
	ret = of_property_read_string(np, "nfc_single_channel", &out_value);
	if (ret != 0) {
		pr_err("%s: can't get nfc single channel dts config\n", __func__);
		g_nfc_single_channel = 0;
		return;
	}
	pr_err("%s: get nfc single channel dts config %s\n", __func__, out_value);
	if (!strcasecmp(out_value, "true")) {
		g_nfc_single_channel = 1;
	}
	pr_err("%s: nfc single channel:%d\n", __func__, g_nfc_single_channel);
	return;
}

static ssize_t nfc_single_channel_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE,
		MAX_ATTRIBUTE_BUFFER_SIZE - 1, "%d", g_nfc_single_channel));
}

int nfc_record_dmd_info(long dmd_no, const char *dmd_info)
{
#ifdef CONFIG_HUAWEI_DSM
	if (dmd_no < NFC_DMD_NUMBER_MIN || dmd_no > NFC_DMD_NUMBER_MAX
		|| dmd_info == NULL || NULL == nfc_dclient) {
		pr_info("%s: para error: %ld\n", __func__, dmd_no);
		return -1;
	}

	pr_info("%s: dmd no: %ld - %s", __func__, dmd_no, dmd_info);
	if (!dsm_client_ocuppy(nfc_dclient)) {
		dsm_client_record(nfc_dclient, "DMD info:%s", dmd_info);
		dsm_client_notify(nfc_dclient, dmd_no);
	}
#endif
	return 0;
}

static ssize_t nfc_hal_dmd_info_store(struct device *dev, struct device_attribute *attr,
	const char *buf, size_t count)
{
	int val = 0;
	char dmd_info_from_hal[64] = {'\0'};
	/* The length of DMD error number is 9 */
	if (sscanf_s(buf, "%9d", &val) == 1) {
		if (val < NFC_DMD_NUMBER_MIN || val > NFC_DMD_NUMBER_MAX)
			return (ssize_t)count;
		g_nfc_hal_dmd_no = val;
		/* The max length of content for current dmd description set as 63.
		   Example for DMD Buf: '923002014 CoreReset:600006A000D1A72000'.
		   A space as a separator is between dmd error no and description. */
		if (sscanf_s(buf, "%*s%63s", dmd_info_from_hal) == 1) {
			nfc_record_dmd_info(val, dmd_info_from_hal);
		}
	} else {
		pr_err("%s: get dmd number error\n", __func__);
	}
	return (ssize_t)count;
}

static ssize_t nfc_hal_dmd_info_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE, MAX_ATTRIBUTE_BUFFER_SIZE - 1, "%d", g_nfc_hal_dmd_no));
}
static ssize_t nfc_at_result_store(struct device *dev, struct device_attribute *attr,
	const char *buf, size_t count)
{
	if (buf != NULL)
		g_nfc_at_result = buf[0] - CHAR_0; /* file storage str */
	return (ssize_t)count;
}

static ssize_t nfc_at_result_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return (ssize_t)(snprintf_s(buf, sizeof(g_nfc_at_result) + 1, sizeof(g_nfc_at_result), "%d", g_nfc_at_result));
}

static ssize_t nfc_clk_src_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE, MAX_ATTRIBUTE_BUFFER_SIZE - 1, "%d", g_nfc_clk_src));
}

static ssize_t nfc_switch_state_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return (ssize_t)(snprintf_s(buf, sizeof(g_nfc_switch_state) + 1,
		sizeof(g_nfc_switch_state), "%d", g_nfc_switch_state));
}

static ssize_t nfc_switch_state_store(struct device *dev, struct device_attribute *attr,
	const char *buf, size_t count)
{
	if (buf != NULL)
		g_nfc_switch_state = buf[0] - CHAR_0; /* file storage str */
	return (ssize_t)count;
}

int nfc_get_dts_config_u32(const char *node_name, const char *prop_name, u32 *pvalue)
{
	struct device_node *np = NULL;
	int ret = -1;

	for_each_node_with_property(np, node_name) {
		ret = of_property_read_u32(np, prop_name, pvalue);
		if (ret != 0) {
			pr_debug("%s: can not get prop values with prop_name: %s\n", __func__, prop_name);
		} else {
			pr_info("%s: %s=%d\n", __func__, prop_name, *pvalue);
		}
	}
	return ret;
}

int nfc_get_ese_spi_bus(void)
{
	int ret;
	ret = nfc_get_dts_config_u32("ese_config_spi_bus", "ese_config_spi_bus", &g_ese_spi_bus);
	if (ret != 0) {
		pr_err("can't get nfc spi_bus config node!\n");
		return -1;
	}
	pr_info("ese_spi_bus = %d\n", g_ese_spi_bus);
	return 0;
}

int nfc_get_ese_pwr_req_gpio(void)
{
	int ret;
	ret = nfc_get_dts_config_u32("gpio_svdd_pwr_req", "gpio_svdd_pwr_req", &g_ese_svdd_pwr_req);
	if (ret != 0) {
		pr_err("can't get nfc gpio_svdd_pwr_req config node!\n");
		return -1;
	}
	pr_info("g_ese_svdd_pwr_req = %d\n", g_ese_svdd_pwr_req);
	return 0;
}

static int get_dev_name_type(void)
{
	int type = 0;
	int ret;

	/* read supported nfc_card_num from device tree system. */
	ret = nfc_get_dts_config_u32("nfc_dev_name_type", "nfc_dev_name_type", &type);
	if (ret != 0) {
		pr_err("%s: can't get nfc_dev_name_type!\n", __func__);
	}
	pr_err("%s: get_dev_name_type = %d\n", __func__, type);
	return type;
}

static ssize_t nfc_dev_name_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	int temp = get_dev_name_type();
	return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE,
		MAX_ATTRIBUTE_BUFFER_SIZE - 1, "%d\n", temp));
}

static ssize_t nfc_activated_se_info_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE,
		MAX_ATTRIBUTE_BUFFER_SIZE - 1, "%d", g_nfc_activated_se_info));
}

static ssize_t nfc_activated_se_info_store(struct device *dev, struct device_attribute *attr,
	const char *buf, size_t count)
{
	int val = 0;
	if (sscanf_s(buf, "%1d", &val) == 1) {
		g_nfc_activated_se_info = val;
	} else {
		g_nfc_activated_se_info = 0;
	}
	return (ssize_t)count;
}

static ssize_t nfc_wired_ese_info_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE, MAX_ATTRIBUTE_BUFFER_SIZE - 1, "%d", g_nfc_ese_type));
}

static ssize_t nfc_wired_ese_info_store(struct device *dev, struct device_attribute *attr,
	const char *buf, size_t count)
{
	int val = 0;
	if (sscanf_s(buf, "%1d", &val) == 1) {
		g_nfc_ese_type = val;
	} else {
		pr_err("%s: set nfc_ese_type  error\n", __func__);
	}
	pr_info("%s: nfc_ese_type:%d\n", __func__, g_nfc_ese_type);
	return (ssize_t)count;
}

static ssize_t nfc_sim_status_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	int status = -1;
	if (nfc_sim_status_show_p != NULL)
		status = (*nfc_sim_status_show_p)(dev, attr, buf);

	pr_info("%s: status=%d\n", __func__, status);
	return (ssize_t)(snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE, MAX_ATTRIBUTE_BUFFER_SIZE - 1, "%d\n", status));
}

/* FUNCTION: nfc_sim_switch_store
 * DESCRIPTION: save user sim card select result.
 * Parameters
 * struct device *dev:device structure
 * struct device_attribute *attr:device attribute
 * const char *buf:user buffer
 * size_t count:data count
 * RETURN VALUE
 * ssize_t:result
 */
static ssize_t nfc_sim_switch_store(struct device *dev, struct device_attribute *attr,
	const char *buf, size_t count)
{
	if (nfc_sim_switch_store_p != NULL)
		return (*nfc_sim_switch_store_p)(dev, attr, buf, count);
	return -1;
}

/* FUNCTION: nfc_sim_switch_show
 * DESCRIPTION: get user sim card select result.
 * Parameters
 * struct device *dev:device structure
 * struct device_attribute *attr:device attribute
 * const char *buf:user buffer
 * RETURN VALUE
 * ssize_t:  result
 */
static ssize_t nfc_sim_switch_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	if (nfc_sim_switch_show_p != NULL)
		return (*nfc_sim_switch_show_p)(dev, attr, buf);
	return -1;
}

/* FUNCTION: rd_nfc_sim_status_show
 * DESCRIPTION: get nfc-sim card support result from variate, no need to send check commands again.
 * Parameters
 * struct device *dev:device structure
 * struct device_attribute *attr:device attribute
 * const char *buf:user buffer
 * RETURN VALUE
 *		eSE 	UICC	value
 *		0		0		0	(not support)
 *		0		1		1	(swp1 support)
 *		1		0		2	(swp2 support)
 *		1		1		3	(all support)
 *		<0	:error
 */
static ssize_t rd_nfc_sim_status_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	if (rd_nfc_sim_status_show_p != NULL)
		return (*rd_nfc_sim_status_show_p)(dev, attr, buf);
	return -1;
}

/* FUNCTION: nfc_enable_status_store
 * DESCRIPTION: store nfc_enable_status for RD test.
 * Parameters
 * struct device *dev:device structure
 * struct device_attribute *attr:device attribute
 * const char *buf:user buffer
 * size_t count:data count
 * RETURN VALUE
 * ssize_t:  result
 */
static ssize_t nfc_enable_status_store(struct device *dev, struct device_attribute *attr,
	const char *buf, size_t count)
{
	if (nfc_enable_status_store_p != NULL)
		return (*nfc_enable_status_store_p)(dev, attr, buf, count);
	return -1;
}

/* FUNCTION: nfc_enable_status_show
 * DESCRIPTION: show nfc_enable_status for RD test.
 * Parameters
 * struct device *dev:device structure
 * struct device_attribute *attr:device attribute
 * const char *buf:user buffer
 * RETURN VALUE
 * ssize_t:  result
 */
static ssize_t nfc_enable_status_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	if (nfc_enable_status_show_p != NULL)
		return (*nfc_enable_status_show_p)(dev, attr, buf);
	return -1;
}

static ssize_t nfc_recovery_close_nfc_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	if (nfc_recovery_close_nfc_show_p != NULL)
		return (*nfc_recovery_close_nfc_show_p)(dev, attr, buf);
	return -1;
}

static ssize_t nfc_recovery_close_nfc_store(struct device *dev, struct device_attribute *attr,
	const char *buf, size_t count)
{
	if (nfc_recovery_close_nfc_store_p != NULL)
		return (*nfc_recovery_close_nfc_store_p)(dev, attr, buf, count);
	return -1;
}

static ssize_t nfc_qcom_activated_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	int ret = -1;
	ret = snprintf_s(buf,
		MAX_ATTRIBUTE_BUFFER_SIZE - 1,
		sizeof(g_nfc_qcom_activated) + 1,
		"%d\n",
		g_nfc_qcom_activated);
	if (ret < 0) {
		pr_err("%s:snprintf_s fail, ret=%d.\n", __func__, ret);
	}
	return ret;
}

/* register device node to communication with user space */
static struct device_attribute common_attr[] = {
	__ATTR(nfc_fwupdate, 0664, nfc_fwupdate_show, nfc_fwupdate_store),
	__ATTR(nxp_config_name, 0664, nxp_config_name_show, nxp_config_name_store),
	__ATTR(nfc_brcm_conf_name, 0664, nfc_brcm_conf_name_show, nfc_brcm_conf_name_store),
	__ATTR(nfc_card_num, 0444, nfc_card_num_show, NULL),
	__ATTR(nfc_chip_type, 0444, nfc_chip_type_show, NULL),
	__ATTR(nfc_qcom_activated, 0444, nfc_qcom_activated_show, NULL),
	__ATTR(nfc_single_channel, 0444, nfc_single_channel_show, NULL),
	__ATTR(nfc_wired_ese_type, 0664, nfc_wired_ese_info_show, nfc_wired_ese_info_store),
	__ATTR(nfc_activated_se_info, 0664, nfc_activated_se_info_show, nfc_activated_se_info_store),
	__ATTR(nfc_hal_dmd, 0664, nfc_hal_dmd_info_show, nfc_hal_dmd_info_store),
	__ATTR(nfc_clk_src, 0444, nfc_clk_src_show, NULL),
	__ATTR(nfc_switch_state, 0664, nfc_switch_state_show, nfc_switch_state_store),
	__ATTR(nfc_at_result, 0664, nfc_at_result_show, nfc_at_result_store),
	__ATTR(nfc_dev_name, 0444, nfc_dev_name_show, NULL),
	__ATTR(nfc_sim_switch, 0664, nfc_sim_switch_show, nfc_sim_switch_store),
	__ATTR(nfc_sim_status, 0444, nfc_sim_status_show, NULL),
	__ATTR(rd_nfc_sim_status, 0444, rd_nfc_sim_status_show, NULL),
	__ATTR(nfc_enable_status, 0664, nfc_enable_status_show, nfc_enable_status_store),
	__ATTR(nfc_recovery_close_nfc, 0664, nfc_recovery_close_nfc_show, nfc_recovery_close_nfc_store),
	__ATTR(nfc_spec_rf_conf_name, 0664, nfc_spec_rf_conf_name_show, nfc_spec_rf_conf_name_store),
};

int get_chip_value(void)
{
	return g_chip_type;
}

int get_ese_spi_bus(void)
{
	return g_ese_spi_bus;
}

int get_ese_svdd_pwr_req(void)
{
	return g_ese_svdd_pwr_req;
}

void set_wait_event_interruptible_ret(int input)
{
	g_wait_event_interruptible_ret = input;
	return;
}

bool get_is_uid(void)
{
	return g_is_uid;
}

void set_is_uid(bool input)
{
	g_is_uid = input;
	return;
}

void set_nfc_clk_src(int input)
{
	g_nfc_clk_src = input;
	return;
}

#ifdef CONFIG_HUAWEI_DSM
struct dsm_client* get_nfc_dclient(void)
{
	return nfc_dclient;
}

void set_nfc_dclient(struct dsm_client *input)
{
	nfc_dclient = input;
	return;
}
#endif

attr_show_wrapper get_nfc_sim_status_show_pointer(void)
{
	return nfc_sim_status_show_p;
}

attr_store_wrapper get_nfc_sim_switch_store_pointer(void)
{
	return nfc_sim_switch_store_p;
}
attr_show_wrapper get_nfc_sim_switch_show_pointer(void)
{
	return nfc_sim_switch_show_p;
}

attr_show_wrapper get_rd_nfc_sim_status_show_pointer(void)
{
	return rd_nfc_sim_status_show_p;
}

attr_show_wrapper get_nfc_enable_status_show_pointer(void)
{
	return nfc_enable_status_show_p;
}

attr_store_wrapper get_nfc_enable_status_store_pointer(void)
{
	return nfc_enable_status_store_p;
}

attr_show_wrapper get_nfc_recovery_close_nfc_show_pointer(void)
{
	return nfc_recovery_close_nfc_show_p;
}

attr_store_wrapper get_nfc_recovery_close_nfc_store_pointer(void)
{
	return nfc_recovery_close_nfc_store_p;
}

void set_nfc_sim_status_show_pointer(attr_show_wrapper nfc_show_p)
{
	nfc_sim_status_show_p = nfc_show_p;
	return;
}

void set_nfc_sim_switch_store_pointer(attr_store_wrapper nfc_store_p)
{
	nfc_sim_switch_store_p = nfc_store_p;
	return;
}
void set_nfc_sim_switch_show_pointer(attr_show_wrapper nfc_show_p)
{
	nfc_sim_switch_show_p = nfc_show_p;
	return;
}

void set_rd_nfc_sim_status_show_pointer(attr_show_wrapper nfc_show_p)
{
	rd_nfc_sim_status_show_p = nfc_show_p;
	return;
}

void set_nfc_enable_status_show_pointer(attr_show_wrapper nfc_show_p)
{
	nfc_enable_status_show_p = nfc_show_p;
	return;
}

void set_nfc_enable_status_store_pointer(attr_store_wrapper nfc_store_p)
{
	nfc_enable_status_store_p = nfc_store_p;
	return;
}

void set_nfc_recovery_close_nfc_show_pointer(attr_show_wrapper nfc_show_p)
{
	nfc_recovery_close_nfc_show_p = nfc_show_p;
	return;
}

void set_nfc_recovery_close_nfc_store_pointer(attr_store_wrapper nfc_store_p)
{
	nfc_recovery_close_nfc_store_p = nfc_store_p;
	return;
}

/* FUNCTION: create_common_sysfs_interfaces
 * DESCRIPTION: create_common_sysfs_interfaces.
 * Parameters
 * struct device *dev:device structure
 * RETURN VALUE
 * int:  result
 */
int create_common_sysfs_interfaces(struct device *dev)
{
	int i;
	for (i = 0; i < ARRAY_SIZE(common_attr); i++) {
		if (device_create_file(dev, common_attr + i)) {
			goto error;
		}
	}
	return 0;
error:
	for (; i >= 0; i--)
		device_remove_file(dev, common_attr + i);
	pr_err("%s:nfc unable to create sysfs interface.\n", __func__);
	return -1;
}

/* FUNCTION: remove_common_sysfs_interfaces
 * DESCRIPTION: remove_common_sysfs_interfaces.
 * Parameters
 * struct device *dev:device structure
 * RETURN VALUE
 * int:  result
 */
void remove_common_sysfs_interfaces(struct device *dev)
{
	int i;
	for (i = 0; i < ARRAY_SIZE(common_attr); i++)
		device_remove_file(dev, common_attr + i);
	return;
}

