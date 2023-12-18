/*
 * proc_ufs.c
 *
 * ufs proc configuration
 *
 * Copyright (c) Huawei Technologies Co., Ltd. 2021. All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <linux/bootdevice.h>
#include "proc_ufs.h"
#ifdef CONFIG_HUAWEI_STORAGE_ROFA
#include <chipset_common/storage_rofa/storage_rofa.h>
#endif
#include "ufs.h"
#include "ufshcd.h"

int ufshcd_read_geometry_desc(struct ufs_hba *hba, u8 *buf, u32 size)
{
	if (hba == NULL || buf == NULL)
		return -1;
	return ufshcd_read_desc_param(hba, QUERY_DESC_IDN_GEOMETRY, 0, 0, buf, size);
}

void ufs_get_geometry_info(struct ufs_hba *hba)
{
	int err;
	uint8_t desc_buf[QUERY_DESC_GEOMETRY_MAX_SIZE];
	u64 total_raw_device_capacity;
	if (hba == NULL)
		return;
	err =
		ufshcd_read_geometry_desc(hba, desc_buf, QUERY_DESC_GEOMETRY_MAX_SIZE);
	if (err) {
		dev_err(hba->dev, "%s: Failed getting geometry info\n", __func__);
		goto out;
	}
	total_raw_device_capacity =
		(u64)desc_buf[GEOMETRY_DESC_PARAM_DEV_CAP + 0] << 56 |
		(u64)desc_buf[GEOMETRY_DESC_PARAM_DEV_CAP + 1] << 48 |
		(u64)desc_buf[GEOMETRY_DESC_PARAM_DEV_CAP + 2] << 40 |
		(u64)desc_buf[GEOMETRY_DESC_PARAM_DEV_CAP + 3] << 32 |
		(u64)desc_buf[GEOMETRY_DESC_PARAM_DEV_CAP + 4] << 24 |
		(u64)desc_buf[GEOMETRY_DESC_PARAM_DEV_CAP + 5] << 16 |
		(u64)desc_buf[GEOMETRY_DESC_PARAM_DEV_CAP + 6] << 8 |
		desc_buf[GEOMETRY_DESC_PARAM_DEV_CAP + 7] << 0;
	set_bootdevice_size(BOOT_DEVICE_UFS, total_raw_device_capacity);

out:
	return;
}

static void set_sunm_for_samsung(uint8_t *snum_buf, uint8_t *str_desc_buf)
{
	int i, idx;
	/* Samsung V4 UFS need 24 Bytes for serial number, transfer unicode to 12 bytes
	 * the magic number 12 here was following original below HYNIX/TOSHIBA decoding method
	 */
	for (i = 0; i < NUM_12; i++) {
		idx = QUERY_DESC_HDR_SIZE + i * NUM_2 + NUM_1;
		snum_buf[i] = str_desc_buf[idx];
	}
}

static void set_sunm_for_skhynix(uint8_t *snum_buf, uint8_t *str_desc_buf)
{
	int i;
	/* hynix only have 6Byte, add a 0x00 before every byte */
	for (i = 0; i < NUM_6; i++) {
		/*lint -save  -e679 */
		snum_buf[i * NUM_2] = 0x0;
		snum_buf[i * NUM_2 + NUM_1] = str_desc_buf[QUERY_DESC_HDR_SIZE + i];
		/*lint -restore*/
	}
}

static void set_sunm_for_toshiba(uint8_t *snum_buf, uint8_t *str_desc_buf)
{
	int i;
	/*
	 * toshiba: 20Byte, every two byte has a prefix of 0x00, skip
	 * and add two 0x00 to the end
	 */
	for (i = 0; i < NUM_10; i++)
		snum_buf[i] = str_desc_buf[QUERY_DESC_HDR_SIZE + i * NUM_2 + NUM_1]; /*lint !e679*/
}

static void set_sunm_for_sandisk(uint8_t *snum_buf, uint8_t *str_desc_buf)
{
	int i, idx;
	for (i = 0; i < NUM_12; i++) {
		idx = QUERY_DESC_HDR_SIZE + i * NUM_2 + NUM_1;
		snum_buf[i] = str_desc_buf[idx];
	}
}

static void set_sunm_for_xhfz(uint8_t *snum_buf, uint8_t *str_desc_buf)
{
	int i, idx;
	for (i = 0; i < NUM_4; i++) {
		idx = QUERY_DESC_SNUM_XHFZ + i * NUM_2 + NUM_1;
		snum_buf[i] = str_desc_buf[idx];
	}
	for (i = NUM_4; i < NUM_12; i++) {
		idx = QUERY_DESC_SNUM_XHFZ_SEC + i * NUM_2 + NUM_1;
		snum_buf[i] = str_desc_buf[idx];
	}
}

static void set_sunm_for_ymtc(uint8_t *snum_buf, uint8_t *str_desc_buf)
{
	int i, idx;
	for (i = 0; i < NUM_5; i++) {
		idx = QUERY_DESC_SNUM_YMTC + i * NUM_4;
		snum_buf[i] = ((str_desc_buf[idx] & 0xF) << NUM_4) | (str_desc_buf[idx + NUM_2] & 0xF);
	}
	for (i = NUM_5; i < NUM_8; i++) {
		idx = QUERY_DESC_SNUM_YMTC_SEC + i * NUM_2;
		snum_buf[i] = str_desc_buf[idx] & 0xFF;
	}
	for (i = NUM_8; i < NUM_12; i++) {
		idx = QUERY_DESC_SNUM_YMTC_THR + i * NUM_4;
		snum_buf[i] = ((str_desc_buf[idx] & 0xF) << NUM_4) | (str_desc_buf[idx + NUM_2] & 0xF);
	}
}

static void ufs_set_sunm_buf(struct ufs_hba *hba, uint8_t *snum_buf, uint8_t *str_desc_buf)
{
	int i;
	switch (hba->manufacturer_id) {
	case UFS_VENDOR_SAMSUNG:
		set_sunm_for_samsung(snum_buf, str_desc_buf);
		break;
	case UFS_VENDOR_SKHYNIX:
		set_sunm_for_skhynix(snum_buf, str_desc_buf);
		break;
	case UFS_VENDOR_TOSHIBA:
		set_sunm_for_toshiba(snum_buf, str_desc_buf);
		break;
	case UFS_VENDOR_HI1861:
		memcpy(snum_buf, str_desc_buf + QUERY_DESC_HDR_SIZE, NUM_12);
		break;
	case UFS_VENDOR_MICRON:
		memcpy(snum_buf, str_desc_buf + QUERY_DESC_HDR_SIZE, NUM_4);
		for (i = NUM_4; i < NUM_12; i++)
			snum_buf[i] = 0;
		break;
	case UFS_VENDOR_SANDISK:
		set_sunm_for_sandisk(snum_buf, str_desc_buf);
		break;
	case UFS_VENDOR_XHFZ:
		set_sunm_for_xhfz(snum_buf, str_desc_buf);
		break;
	case UFS_VENDOR_YMTC:
		set_sunm_for_ymtc(snum_buf, str_desc_buf);
		break;
	default:
		dev_err(hba->dev, "unknown ufs manufacturer id\n");
		break;
	}
}

void ufs_set_sec_unique_number(struct ufs_hba *hba,
					uint8_t *str_desc_buf,
					char *product_name)
{
	int i;
	u32 cid[UFS_CID_SIZE];
	uint8_t snum_buf[SERIAL_NUM_SIZE + 1];
	struct ufs_unique_number unique_number = {0};
	if (hba == NULL || str_desc_buf == NULL || product_name == NULL)
		return;
	memset(snum_buf, 0, sizeof(snum_buf));

	ufs_set_sunm_buf(hba, snum_buf, str_desc_buf);

	unique_number.manufacturer_id = hba->manufacturer_id;
	unique_number.manufacturer_date = hba->manufacturer_date;
	memcpy(unique_number.serial_number, snum_buf, SERIAL_NUM_SIZE);
	memcpy(cid, (u32 *)&unique_number, sizeof(cid));
	for (i = 0; i < UFS_CID_SIZE - 1; i++)
		cid[i] = be32_to_cpu(cid[i]);
	cid[UFS_CID_SIZE - 1] =
		((cid[UFS_CID_SIZE - 1] & 0xffff) << NUM_16) |
		((cid[UFS_CID_SIZE - 1] >> NUM_16) & 0xffff);
	set_bootdevice_cid(BOOT_DEVICE_UFS, (u32 *)cid);
#ifdef CONFIG_HUAWEI_KERNEL_DEBUG
	pr_notice("ufs_debug manufacturer_id:%d\n", unique_number.manufacturer_id);
	pr_notice("ufs_debug manufacturer_date:%d\n", unique_number.manufacturer_date);
#endif
}

int ufshcd_read_health_desc(struct ufs_hba *hba, u8 *buf, u32 size)
{
	return ufshcd_read_desc_param(hba, QUERY_DESC_IDN_HEALTH, 0, 0, buf, size);
}
EXPORT_SYMBOL(ufshcd_read_health_desc);

void ufs_set_health_desc(struct ufs_hba *hba)
{
	int err;
	int buff_len = QUERY_DESC_HEALTH_DEF_SIZE;
	uint8_t desc_buf[QUERY_DESC_HEALTH_DEF_SIZE] = {0};
	if (hba == NULL)
		return;

	err = ufshcd_read_health_desc(hba, desc_buf, buff_len);
	if (err) {
		dev_info(hba->dev, "%s: Failed reading PRL. err = %d\n",
				__func__, err);
		return;
	}
	set_bootdevice_pre_eol_info(BOOT_DEVICE_UFS, (u8)desc_buf[2]);
	set_bootdevice_life_time_est_typ_a(BOOT_DEVICE_UFS, (u8)desc_buf[3]);
	set_bootdevice_life_time_est_typ_b(BOOT_DEVICE_UFS, (u8)desc_buf[4]);
}

int ufs_proc_set_device(struct ufs_hba *hba, u8 model_index, u8 *desc_buf, size_t buff_len)
{
	int err;
	u8 serial_num_index;
	u8 prl_index;
	char prl[MAX_PRL_LEN + 1] = {0};
	u8 *dev_buf = NULL;
	struct ufs_dev_info *dev_info = &hba->dev_info;
	if (hba == NULL)
		return -1;
	hba->manufacturer_id = hba->dev_info.wmanufacturerid;
	hba->manufacturer_date = desc_buf[DEVICE_DESC_PARAM_MANF_DATE] << 8 |
				     desc_buf[DEVICE_DESC_PARAM_MANF_DATE + 1];
	serial_num_index = desc_buf[DEVICE_DESC_PARAM_SN];
	prl_index = desc_buf[DEVICE_DESC_PARAM_PRDCT_REV];

	err = ufshcd_read_string_desc(hba, model_index, &dev_buf, true /* ASCII */);
	if (err < 0) {
		dev_err(hba->dev, "%s: Failed reading Product Name. err = %d\n",
			__func__, err);
		return err;
	}

	strlcpy(dev_info->model_name, dev_buf,
		min_t(u8, dev_buf[QUERY_DESC_LENGTH_OFFSET],
		      sizeof(dev_info->model_name)));
	kfree(dev_buf);

	/* Get serial number */
	err = ufshcd_read_string_desc(hba, serial_num_index, &dev_buf, false);
	if (err < 0) {
		dev_info(hba->dev, "%s: Failed reading Serial Number. err = %d\n",
			__func__, err);
		return err;
	}

	ufs_set_sec_unique_number(hba, dev_buf, dev_info->model_name);
	set_bootdevice_product_name(BOOT_DEVICE_UFS, dev_info->model_name);
	set_bootdevice_manfid(BOOT_DEVICE_UFS, hba->manufacturer_id);
#ifdef CONFIG_HUAWEI_STORAGE_ROFA
	storage_rochk_record_bootdevice_type(1); /* set ufs type */
	storage_rochk_record_bootdevice_manfid(hba->manufacturer_id);
	storage_rochk_record_bootdevice_model(dev_info->model_name);
#endif
	kfree(dev_buf);

	err = ufshcd_read_string_desc(hba, prl_index, &dev_buf, true);
	if (err < 0) {
		dev_info(hba->dev, "%s: Failed reading PRL. err = %d\n",
				__func__, err);
		return err;
	}

	strlcpy(prl, dev_buf,
		min_t(u8, dev_buf[QUERY_DESC_LENGTH_OFFSET],
			MAX_PRL_LEN));
	kfree(dev_buf);

	set_bootdevice_fw_version(BOOT_DEVICE_UFS, prl);
	return 0;
}
