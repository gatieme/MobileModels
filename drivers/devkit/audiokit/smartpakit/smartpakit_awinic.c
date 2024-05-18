/*
 * smartpakit_awinic.c
 *
 * smartpakit_awinic driver
 *
 * Copyright (c) 2022-2022 Honor Device Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#include <log/hw_log.h>
#include "smartpakit.h"

#define HWLOG_TAG smartpakit
HILOG_REGIST();
#define RETRY_TIMES                (3)

#define AW_CORRECT_COEFF           (1 << 13)
#define AW_TRIM_VALUE_MASK         (0x03ff)
#define AW_TRIM_VALUE_BASE         (1000)
#define aw_fill_short_type_sign(a) ((((a) & 0x200) == 0) ? (a) : ((a) | 0xfc00))

#define AW_BIT_WIDE_MAX      (16)
#define AW_DBGCTRL_REG       (0x14)
#define AW_VSNTM1_REG        (0x50)
#define AW_EFRH4_REG         (0x78)
#define AW_EFRH3_REG         (0x79)
#define AW_EFRL4_REG         (0x7C)
#define AW_EFRL3_REG         (0x7D)
#define AW_CALB_BASE_VALUE   (10000)
#define AW_EF_DBMD_MASK      (0xfff7)
#define AW_AND_VALUE         (0x0000)
#define AW_OR_VALUE          (0x0008)

enum {
	AW_EF_AND_CHECK = 0,
	AW_EF_OR_CHECK,
};

struct aw_vcalb_desc {
	unsigned int icalk_reg;
	unsigned int icalk_reg_mask;
	unsigned int icalk_shift;
	unsigned int icalkl_reg;
	unsigned int icalkl_reg_mask;
	unsigned int icalkl_shift;
	unsigned int icalk_sign_mask;
	unsigned int icalk_neg_mask;
	int icalk_value_factor;

	unsigned int vcalk_reg;
	unsigned int vcalk_reg_mask;
	unsigned int vcalk_shift;
	unsigned int vcalkl_reg;
	unsigned int vcalkl_reg_mask;
	unsigned int vcalkl_shift;
	unsigned int vcalk_sign_mask;
	unsigned int vcalk_neg_mask;
	int vcalk_value_factor;

	unsigned int vcalb_reg;
	int calb_base_value;
	int vcal_factor;
};

static inline int aw_smartpakit_regmap_read(struct regmap *regmap,
	unsigned int reg_addr, unsigned int *value)
{
	int ret = 0;
	int i;

	for (i = 0; i < RETRY_TIMES; i++) {
		ret = regmap_read(regmap, reg_addr, value);
		if (ret == 0)
			break;

		mdelay(1);
	}
	return ret;
}

static inline int aw_smartpakit_regmap_write(struct regmap *regmap,
	unsigned int reg_addr, unsigned int value)
{
	int ret = 0;
	int i;

	for (i = 0; i < RETRY_TIMES; i++) {
		ret = regmap_write(regmap, reg_addr, value);
		if (ret == 0)
			break;

		mdelay(1);
	}
	return ret;
}

static int aw_smartpa_get_trim_value(struct regmap *regmap,
	unsigned int reg_addr, int *trim)
{
	int ret;
	unsigned int reg_val = 0;
	unsigned short val;

	ret = aw_smartpakit_regmap_read(regmap, reg_addr, &reg_val);
	if (ret < 0) {
		hilog_err("%s: read reg 0x%x failed\n", __func__, reg_addr);
		return ret;
	}

	hilog_debug("%s: read reg 0x%x = 0x%x\n", __func__, reg_addr, reg_val);

	/* calk value is ten bits, the highest bit is sign */
	val = (unsigned short)reg_val & AW_TRIM_VALUE_MASK;
	val = aw_fill_short_type_sign(val);

	*trim = AW_TRIM_VALUE_BASE + (short)val;
	return ret;
}

int aw_smartpa_set_correction_v1(struct regmap *regmap,
	unsigned int reg_addr, unsigned int isn_addr, unsigned int vsn_addr)
{
	int ret;
	int i_trim = 0;
	int v_trim = 0;
	int reg_val;

	ret = aw_smartpa_get_trim_value(regmap, isn_addr, &i_trim);
	ret += aw_smartpa_get_trim_value(regmap, vsn_addr, &v_trim);
	if (ret < 0)
		return ret;

	hilog_info("%s: i_trim 0x%x, v_trim 0x%x\n", __func__, i_trim, v_trim);

	/* get vcal from i_trim&v_trim */
	reg_val = AW_CORRECT_COEFF * i_trim / v_trim;

	hilog_info("%s: write reg 0x%x value 0x%x\n", __func__, reg_addr,
		reg_val);

	ret = aw_smartpakit_regmap_write(regmap, reg_addr, (unsigned int)reg_val);
	if (ret < 0)
		hilog_err("%s: write reg 0x%x failed\n", __func__, reg_addr);

	return ret;
}

/* Parameter Notes:
 *                                                     *
 *  1.xml_mask: icalk&vcalk's valid bits               *
 *      for example: 0x03ff (0000 0011 1111 1111)      *
 *                                                     *
 *  2.mask: for calculation                            *
 *      for example: 0xfc00 (1111 1100 0000 0000)      *
 *                                                     *
 *  3.shift: first position of valid bits              *
 *      for example: 0x0                               *
 *                                                     *
 *  4.sign_mask: icalk&vcalk's sign bit                *
 *      for example: 0xfdff (1111 1101 1111 1111)      *
 *                                                     *
 *  5.neg_mask: icalk&vcalk's negative bit             *
 *      for example: 0x03ff (0000 0011 1111 1111)      *
 *                                                     */
static int aw_smartpa_get_param_from_mask(unsigned short mask, unsigned int *shift,
	unsigned int *sign_mask, unsigned int *neg_mask)
{
	unsigned int i;

	/* get shift */
	for (i = 0; i < AW_BIT_WIDE_MAX; i++) {
		if (((mask >> i) % 2) == 0)
			break;
	}

	if (i == AW_BIT_WIDE_MAX) {
		hilog_err("%s: get shift failed\n", __func__);
		return -EINVAL;
	}

	*shift = i;

	/* get sign_mask neg_mask */
	for (i = *shift; i < AW_BIT_WIDE_MAX; i++) {
		if (((mask >> i) % 2) == 1)
			break;
	}

	*sign_mask = ~(0x0001 << (i - 1));

	*neg_mask = 0xFFFF ^ (mask >> (*shift));

	return 0;
}

static int aw_smartpa_get_efuse_check(struct regmap *regmap, int *efuse_check)
{
	int ret;
	unsigned int efcheck_val;
	unsigned int reg_val = 0;

	ret = aw_smartpakit_regmap_read(regmap, AW_DBGCTRL_REG, &reg_val);
	if (ret < 0) {
		hilog_err("%s: read reg 0x%x failed\n", __func__, AW_DBGCTRL_REG);
		return ret;
	}
	efcheck_val = reg_val & (~AW_EF_DBMD_MASK);
	if (efcheck_val == AW_OR_VALUE)
		*efuse_check = AW_EF_OR_CHECK;
	else
		*efuse_check = AW_EF_AND_CHECK;

	hilog_info("%s: efuse_check is %d\n", __func__, *efuse_check);
	return ret;
}

static int aw_smartpa_get_icalk(struct regmap *regmap, struct aw_vcalb_desc *desc,
	int efuse_check, short *icalk)
{
	int ret;
	unsigned short reg_icalk;
	unsigned short reg_icalkl;
	unsigned int reg_val = 0;

	ret = aw_smartpakit_regmap_read(regmap, desc->icalk_reg, &reg_val);
	if (ret < 0) {
		hilog_err("%s: read reg 0x%x failed\n", __func__, desc->icalk_reg);
		return ret;
	}
	reg_icalk = (unsigned short)reg_val & (~desc->icalk_reg_mask);

	ret = aw_smartpakit_regmap_read(regmap, desc->icalkl_reg, &reg_val);
	if (ret < 0) {
		hilog_err("%s: read reg 0x%x failed\n", __func__, desc->icalkl_reg);
		return ret;
	}
	reg_icalkl = (unsigned short)reg_val & (~desc->icalkl_reg_mask);

	if (efuse_check == AW_EF_OR_CHECK)
		reg_icalk = (reg_icalk >> desc->icalk_shift) | (reg_icalkl >> desc->icalkl_shift);
	else
		reg_icalk = (reg_icalk >> desc->icalk_shift) & (reg_icalkl >> desc->icalkl_shift);

	/* if icalk is a negative number, extend the sign bit */
	if (reg_icalk & (~desc->icalk_sign_mask))
		reg_icalk = reg_icalk | (~desc->icalk_neg_mask);

	*icalk = (short)reg_icalk;

	return ret;
}

static int aw_smartpa_get_vcalk(struct regmap *regmap, struct aw_vcalb_desc *desc,
	int efuse_check, short *vcalk)
{
	int ret;
	unsigned short reg_vcalk;
	unsigned short reg_vcalkl;
	unsigned int reg_val = 0;

	ret = aw_smartpakit_regmap_read(regmap, desc->vcalk_reg, &reg_val);
	if (ret < 0) {
		hilog_err("%s: read reg 0x%x failed\n", __func__, desc->vcalk_reg);
		return ret;
	}
	reg_vcalk = (unsigned short)reg_val & (~desc->vcalk_reg_mask);

	ret = aw_smartpakit_regmap_read(regmap, desc->vcalkl_reg, &reg_val);
	if (ret < 0) {
		hilog_err("%s: read reg 0x%x failed\n", __func__, desc->vcalkl_reg);
		return ret;
	}
	reg_vcalkl = (unsigned short)reg_val & (~desc->vcalkl_reg_mask);

	if (efuse_check == AW_EF_OR_CHECK)
		reg_vcalk = (reg_vcalk >> desc->vcalk_shift) | (reg_vcalkl >> desc->vcalkl_shift);
	else
		reg_vcalk = (reg_vcalk >> desc->vcalk_shift) & (reg_vcalkl >> desc->vcalkl_shift);

	/* if vcalk is a negative number, extend the sign bit */
	if (reg_vcalk & (~desc->vcalk_sign_mask))
		reg_vcalk = reg_vcalk | (~desc->vcalk_neg_mask);

	*vcalk = (short)reg_vcalk;

	return ret;
}

static int aw_smartpa_param_init(struct aw_vcalb_desc *desc, unsigned int value_factor,
	unsigned int xml_mask, unsigned int vcal_factor)
{
	int ret;
	unsigned int shift = 0;
	unsigned int sign_mask = 0;
	unsigned int neg_mask = 0;
	unsigned short mask = ~((unsigned short)xml_mask);

	ret = aw_smartpa_get_param_from_mask(mask, &shift, &sign_mask, &neg_mask);
	if (ret < 0) {
		hilog_err("%s: get param failed\n", __func__);
		return ret;
	}

	memset(desc, 0, sizeof(struct aw_vcalb_desc));
	desc->vcalb_reg = AW_VSNTM1_REG;
	desc->vcal_factor = vcal_factor;
	desc->calb_base_value = AW_CALB_BASE_VALUE;

	desc->icalk_reg = AW_EFRH4_REG;
	desc->icalk_reg_mask = mask;
	desc->icalk_shift = shift;
	desc->icalkl_reg = AW_EFRL4_REG;
	desc->icalkl_reg_mask = mask;
	desc->icalkl_shift = shift;
	desc->icalk_sign_mask = sign_mask;
	desc->icalk_neg_mask = neg_mask;
	desc->icalk_value_factor = value_factor;

	desc->vcalk_reg = AW_EFRH3_REG;
	desc->vcalk_reg_mask = mask;
	desc->vcalk_shift = shift;
	desc->vcalkl_reg = AW_EFRL3_REG;
	desc->vcalkl_reg_mask = mask;
	desc->vcalkl_shift = shift;
	desc->vcalk_sign_mask = sign_mask;
	desc->vcalk_neg_mask = neg_mask;
	desc->vcalk_value_factor = value_factor;

	return ret;
}

int aw_smartpa_set_correction_v2(struct regmap *regmap, unsigned int value_factor,
	unsigned int xml_mask, unsigned int vcal_factor)
{
	int ret;
	int vcalb;
	int icalk;
	int vcalk;
	unsigned int reg_val;
	short icalk_val = 0;
	short vcalk_val = 0;
	int efuse_check = 0;
	struct aw_vcalb_desc desc;

	if (aw_smartpa_param_init(&desc, value_factor, xml_mask, vcal_factor) < 0)
		return -EINVAL;
	if (aw_smartpa_get_efuse_check(regmap, &efuse_check) < 0)
		return -EINVAL;
	if (aw_smartpa_get_icalk(regmap, &desc, efuse_check, &icalk_val) < 0)
		return -EINVAL;
	if (aw_smartpa_get_vcalk(regmap, &desc, efuse_check, &vcalk_val) < 0)
		return -EINVAL;

	/* base value&factor value is expanded 1000 times for calculation */
	icalk = desc.calb_base_value + desc.icalk_value_factor * icalk_val;
	vcalk = desc.calb_base_value + desc.vcalk_value_factor * vcalk_val;
	if (!vcalk) {
		hilog_err("%s: vcalk(0) is error", __func__);
		return -EINVAL;
	}
	vcalb = desc.vcal_factor * icalk / vcalk;
	reg_val = (unsigned int)vcalb;
	hilog_info("%s: icalk=%d, vcalk=%d, vcalb=%d, reg_val=0x%04x",
			__func__, icalk, vcalk, vcalb, reg_val);

	ret = aw_smartpakit_regmap_write(regmap, desc.vcalb_reg, reg_val);
	if (ret < 0) {
		hilog_err("%s: write reg 0x%x failed\n", __func__, desc.vcalb_reg);
		return ret;
	}

	hilog_info("%s: write reg 0x%x(0x%04x) success\n", __func__, desc.vcalb_reg, reg_val);
	return ret;
}

