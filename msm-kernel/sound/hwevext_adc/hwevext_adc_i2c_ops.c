/*
 * hwevext_adc_i2c_ops.c
 *
 * extern adc i2c driver
 *
 * Copyright (c) 2022 Huawei Technologies Co., Ltd.
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
#include <linux/delay.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <linux/regmap.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <huawei_platform/log/hw_log.h>
#include <dsm/dsm_pub.h>
#include <sound/hwevext_adc/hwevext_adc.h>
#if IS_ENABLED(CONFIG_HUAWEI_DSM_AUDIO)
#include <dsm_audio/dsm_audio.h>
#endif
#include <securec.h>

#define HWLOG_TAG hwevext_adc
HWLOG_REGIST();

#if IS_ENABLED(CONFIG_HUAWEI_DSM_AUDIO)
#define DSM_BUF_SIZE DSM_SMARTPA_BUF_SIZE
#endif

#define RETRY_TIMES                3
#define EXT_ADC_I2C_READ           0
#define EXT_ADC_I2C_WRITE          1
#define REG_PRINT_NUM              100

#define I2C_STATUS_B64 64
#define MIC_REGULATOR_VOLTAGE 1800000
#define MIC_REGULATOR_CURRENT 10000

enum hwevext_adc_enumrate_state {
	ADC_ENUMRATE_SUCCED = 0,
	ADC_ALREADY_ENUMRATED_NEED_SKIP,
};

enum {
	MICB_DISABLE,
	MICB_ENABLE,
};

/* 0 i2c device not init completed, 1 init completed */
static bool hwevext_adc_i2c_probe_skip[HWEVEXT_ADC_ID_MAX] =
	{ 0, 0, 0, 0, 0, 0, 0, 0 };

static int hwevext_adc_check_i2c_regmap_cfg(
	struct hwevext_adc_i2c_priv *i2c_priv)
{
	if ((i2c_priv == NULL) || (i2c_priv->regmap_cfg == NULL) ||
		(i2c_priv->regmap_cfg->regmap == NULL))
		return -EINVAL;
	return 0;
}

static int hwevext_adc_regmap_read(struct regmap *regmap,
	unsigned int reg_addr, unsigned int *value)
{
	int ret;
	int i;

	for (i = 0; i < RETRY_TIMES; i++) {
		ret = regmap_read(regmap, reg_addr, value);
		if (ret == 0)
			break;

		mdelay(1);
	}
	return ret;
}

static int hwevext_adc_regmap_write(struct regmap *regmap,
	unsigned int reg_addr, unsigned int value)
{
	int ret;
	int i;

	for (i = 0; i < RETRY_TIMES; i++) {
		ret = regmap_write(regmap, reg_addr, value);
		if (ret == 0)
			break;

		mdelay(1);
	}
	return ret;
}

static int hwevext_adc_regmap_update_bits(struct regmap *regmap,
	unsigned int reg_addr, unsigned int mask, unsigned int value)
{
	int ret;
	int i;

	for (i = 0; i < RETRY_TIMES; i++) {
		ret = regmap_update_bits(regmap, reg_addr, mask, value);
		if (ret == 0)
			break;

		mdelay(1);
	}
	return ret;
}

static int hwevext_adc_regmap_xorw(struct regmap *regmap,
	unsigned int reg_addr, unsigned int mask, unsigned int read_addr)
{
	int ret;
	unsigned int value = 0;

	ret = hwevext_adc_regmap_read(regmap, read_addr, &value);
	if (ret < 0) {
		hwlog_info("%s: read reg 0x%x failed, ret = %d\n",
			__func__, read_addr, ret);
		return ret;
	}

#ifndef CONFIG_FINAL_RELEASE
	hwlog_debug("%s: read reg 0x%x = 0x%x\n", __func__, read_addr, value);
#endif

	value ^= mask;
#ifndef CONFIG_FINAL_RELEASE
	hwlog_debug("%s: after xor 0x%x, write reg 0x%x = 0x%x\n", __func__,
		mask, reg_addr, value);
#endif

	ret += hwevext_adc_regmap_write(regmap, reg_addr, value);
	return ret;
}

static int hwevext_adc_regmap_complex_write(struct hwevext_adc_regmap_cfg *cfg,
	unsigned int reg_addr, unsigned int mask, unsigned int value)
{
	int ret;

	if (cfg == NULL)
		return -EINVAL;

	if ((mask ^ cfg->value_mask) == 0)
		ret = hwevext_adc_regmap_write(cfg->regmap, reg_addr, value);
	else
		ret = hwevext_adc_regmap_update_bits(cfg->regmap, reg_addr,
			mask, value);

	return ret;
}

static void hwevext_adc_delay(unsigned int delay, int index, int num)
{
	if (delay == 0)
		return;
	if ((index < 0) || (num < 0))
		return;

	if (index == num)
		msleep(delay);
	else
		mdelay(delay);
}

#if IS_ENABLED(CONFIG_HUAWEI_DSM_AUDIO)
static void hwevext_adc_append_dsm_report(char *dst, char *fmt, ...)
{
	va_list args;
	unsigned int buf_len;
	char tmp_str[DSM_BUF_SIZE] = {0};

	if ((dst == NULL) || (fmt == NULL)) {
		hwlog_err("%s, dst or src is NULL\n", __func__);
		return;
	}

	va_start(args, fmt);
	vscnprintf(tmp_str, (unsigned long)DSM_BUF_SIZE, (const char *)fmt,
		args);
	va_end(args);

	buf_len = DSM_BUF_SIZE - strlen(dst) - 1;
	if (strlen(dst) < DSM_BUF_SIZE - 1) {
		if (strncat_s(dst, buf_len, tmp_str, strlen(tmp_str)) != EOK)
			hwlog_err("%s: strncat_s is failed\n", __func__);
	}
}
#endif

static void hwevext_adc_dsm_report_by_i2c_error(const char *model, int id,
	int flag, int errno, struct i2c_err_info *info)
{
	char *report = NULL;

	unused(report);
	if (errno == 0)
		return;

#if IS_ENABLED(CONFIG_HUAWEI_DSM_AUDIO)
	report = kzalloc(sizeof(char) * DSM_BUF_SIZE, GFP_KERNEL);
	if (report == NULL)
		return;

	hwevext_adc_append_dsm_report(report, "%s_%d i2c ", model, id);

	if (flag == EXT_ADC_I2C_READ) /* read i2c error */
		hwevext_adc_append_dsm_report(report, "read ");
	else /* flag write i2c error == 1 */
		hwevext_adc_append_dsm_report(report, "write ");

	hwevext_adc_append_dsm_report(report, "errno %d", errno);

	if (info != NULL)
		hwevext_adc_append_dsm_report(report,
			" %u fail times of %u all times, err_details is 0x%lx",
			info->err_count, info->regs_num, info->err_details);

	audio_dsm_report_info(AUDIO_CODEC, DSM_CODEC_SSI_READ_ONCE, "%s", report);
	hwlog_info("%s: dsm report, %s\n", __func__, report);
	kfree(report);
#endif
}

static void hwevext_adc_i2c_dsm_report(struct hwevext_adc_i2c_priv *i2c_priv,
	int flag, int errno, struct i2c_err_info *info)
{
	if (i2c_priv->probe_completed == 0)
		return;
	hwevext_adc_dsm_report_by_i2c_error(i2c_priv->chip_model,
		(int)i2c_priv->chip_id, flag, errno, info);
}

static int hwevext_adc_i2c_dump_regs_read(struct hwevext_adc_i2c_priv *i2c_priv,
	struct hwevext_adc_reg_ctl *reg)
{
	struct regmap *regmap = NULL;
	unsigned int reg_addr;
	unsigned int value = 0;
	int ret = 0;
	int ret_once;
	int j;

	regmap = i2c_priv->regmap_cfg->regmap;
	reg_addr = reg->addr;

	/* reg->mask  is dump regs num */
	for (j = 0; j < (int)reg->mask; j++) {
		ret_once = hwevext_adc_regmap_read(regmap, reg_addr, &value);
		hwevext_adc_i2c_dsm_report(i2c_priv, EXT_ADC_I2C_READ, ret_once,
			NULL);

		if (ret_once < 0)
			ret += ret_once;

		hwlog_info("%s: adc %u, r reg 0x%x = 0x%x\n", __func__,
			i2c_priv->chip_id, reg_addr, value);

		reg_addr++;
	}
	return ret;
}

static int hwevext_adc_i2c_dump_reg_ops(struct hwevext_adc_i2c_priv *i2c_priv,
	struct hwevext_adc_reg_ctl_sequence *sequence)
{
	unsigned int reg_addr;
	unsigned int ctl_value;
	unsigned int ctl_type;
	int ret = 0;
	int ret_once;
	int i;
	struct regmap *regmap = NULL;

	if (hwevext_adc_check_i2c_regmap_cfg(i2c_priv) < 0) {
		hwlog_err("%s: invalid argument\n", __func__);
		return -EINVAL;
	}

	if ((sequence == NULL) || (sequence->num == 0) ||
		(sequence->regs == NULL))
		return 0;

	regmap = i2c_priv->regmap_cfg->regmap;

	for (i = 0; i < (int)sequence->num; i++) {
		reg_addr = sequence->regs[i].addr;
		ctl_value = sequence->regs[i].value;
		ctl_type = sequence->regs[i].ctl_type;

		if (ctl_type == HWEVEXT_DAC_REG_CTL_TYPE_W) {
			ret_once = hwevext_adc_regmap_write(regmap, reg_addr,
				ctl_value);
			hwevext_adc_i2c_dsm_report(i2c_priv, EXT_ADC_I2C_WRITE,
				ret_once, NULL);

			ret += ret_once;
#ifndef CONFIG_FINAL_RELEASE
			hwlog_info("%s: adc %u, w reg 0x%x 0x%x\n", __func__,
				i2c_priv->chip_id, reg_addr, ctl_value);
#endif
		} else if (ctl_type == HWEVEXT_DAC_REG_CTL_TYPE_DELAY) {
			if (ctl_value > 0) /* delay time units: msecs */
				msleep(ctl_value);
		} else if (ctl_type == HWEVEXT_DAC_REG_CTL_TYPE_DUMP) {
			ret += hwevext_adc_i2c_dump_regs_read(i2c_priv,
					&sequence->regs[i]);
		} else { /* HWEVEXT_DAC_REG_CTL_TYPE_R or other types */
			continue;
		}
	}

	return ret;
}

static int hwevext_adc_i2c_dump_regs(struct hwevext_adc_i2c_priv *i2c_priv)
{
	if (i2c_priv == NULL) {
		hwlog_err("%s: i2c_priv NULL\n", __func__);
		return -EINVAL;
	}

	hwlog_info("%s: adc %u, dump regs\n", __func__, i2c_priv->chip_id);
	return hwevext_adc_i2c_dump_reg_ops(i2c_priv,
		i2c_priv->dump_regs_sequence);
}

static int hwevext_adc_i2c_ctrl_read_reg(struct hwevext_adc_i2c_priv *i2c_priv,
	struct hwevext_adc_reg_ctl *reg)
{
	int ret;

	if (hwevext_adc_check_i2c_regmap_cfg(i2c_priv) < 0) {
		hwlog_err("%s: invalid argument\n", __func__);
		return -EINVAL;
	}

	ret = hwevext_adc_regmap_read(i2c_priv->regmap_cfg->regmap, reg->addr,
		&reg->value);
	hwevext_adc_i2c_dsm_report(i2c_priv, EXT_ADC_I2C_READ, ret, NULL);
	if (ret < 0)
		hwlog_debug("%s: regmap_read failed ret = %d\n", __func__, ret);

	return ret;
}

static bool hwevext_adc_is_need_write_regs(struct hwevext_adc_i2c_priv *i2c_priv,
	struct hwevext_adc_reg_ctl_sequence *seq)
{
	struct hwevext_adc_reg_ctl_sequence *old = NULL;
	unsigned int regs_size;

	if (i2c_priv == NULL)
		return false;

	if (i2c_priv->record_wirten_seq == NULL)
		return true;

	old = i2c_priv->record_wirten_seq;
	regs_size = sizeof(struct hwevext_adc_reg_ctl) * seq->num;

	if ((old->num == seq->num) &&
		(memcmp(old->regs, seq->regs, regs_size) == 0))
		return false;

	return true;
}

static int hwevext_adc_i2c_reg_node_ops(struct hwevext_adc_regmap_cfg *cfg,
	struct hwevext_adc_reg_ctl *reg, int index, unsigned int reg_num)
{
	int ret = 0;
	int value;

	switch (reg->ctl_type) {
	case HWEVEXT_DAC_REG_CTL_TYPE_DELAY:
		if (reg->delay > 0)
			msleep(reg->delay);
		break;
	case HWEVEXT_DAC_PARAM_NODE_TYPE_SKIP:
	case HWEVEXT_DAC_REG_CTL_TYPE_DUMP:
		break;
	case HWEVEXT_DAC_PARAM_NODE_TYPE_REG_RXORW:
		hwlog_info("%s: rworw node %d/%u\n", __func__, index, reg_num);
		ret = hwevext_adc_regmap_xorw(cfg->regmap, reg->addr,
			reg->mask, reg->value);
		break;
	case HWEVEXT_DAC_REG_CTL_TYPE_R:
		ret = hwevext_adc_regmap_read(cfg->regmap, reg->addr, &value);
#ifndef CONFIG_FINAL_RELEASE
		hwlog_info("%s: read node %d/%u, reg[0x%x]:0x%x, ret:%d\n",
			__func__, index, reg_num, reg->addr, value, ret);
#endif
		break;
	case HWEVEXT_DAC_REG_CTL_TYPE_W:
		hwevext_adc_delay(reg->delay, index, (int)reg_num - 1);
		ret = hwevext_adc_regmap_complex_write(cfg, reg->addr,
			reg->mask, reg->value);
#ifndef CONFIG_FINAL_RELEASE
		hwlog_info("%s: w node %d/%u,reg[0x%x]:0x%x,"
			"mask:0x%x,ret:%d,delay:%d\n",
			__func__, index, reg_num, reg->addr, reg->value,
			reg->mask, ret, reg->delay);
#endif
		break;
	default:
		hwlog_err("%s: invalid argument\n", __func__);
		break;
	}
	return ret;
}

static void hwevext_adc_i2c_get_i2c_err_info(struct i2c_err_info *info,
	unsigned int index)
{
	if (index < I2C_STATUS_B64)
		info->err_details |= ((unsigned long int)1 << index);

	info->err_count++;
}

static int get_adc_node(struct i2c_client *i2c,
	struct hwevext_adc_i2c_priv *i2c_priv, struct device_node **node)
{
	char name[HWEVEXT_ADC_NAME_MAX] = {0};

	if (i2c_priv->adc_num_by_same_i2c_addr == 1) {
		*node = i2c->dev.of_node;
		return 0;
	}

	if (snprintf_s(name, HWEVEXT_ADC_NAME_MAX,  HWEVEXT_ADC_NAME_MAX - 1,
		"adc%d", i2c_priv->adc_iter) < 0) {
		hwlog_err("%s: snprintf_s is failed\n",	__func__);
		return -EINVAL;
	}

	*node = of_get_child_by_name(i2c->dev.of_node, name);
	if (!(*node)) {
		hwlog_err("%s: get node %s fail\n", __func__, name);
		return -EINVAL;
	}

	return 0;
}

static void hwevext_adc_i2c_free_reg_ctl(
	struct hwevext_adc_reg_ctl_sequence **reg_ctl)
{
	if (reg_ctl == NULL || *reg_ctl == NULL)
		return;

	hwevext_adc_kfree_ops((*reg_ctl)->regs);
	kfree(*reg_ctl);
	*reg_ctl = NULL;
}

static void hwevext_adc_i2c_set_record_regs(
	struct hwevext_adc_i2c_priv *i2c_priv,
	struct hwevext_adc_reg_ctl_sequence *seq)
{
	unsigned int size;

	if (i2c_priv == NULL) {
		hwlog_err("%s: i2c_priv invalid argument\n", __func__);
		return;
	}

	if (i2c_priv->record_wirten_seq != NULL)
		hwevext_adc_i2c_free_reg_ctl(&i2c_priv->record_wirten_seq);

	size = sizeof(struct hwevext_adc_reg_ctl_sequence);
	i2c_priv->record_wirten_seq = kzalloc(size, GFP_KERNEL);
	if (i2c_priv->record_wirten_seq == NULL)
		return;

	size = sizeof(struct hwevext_adc_reg_ctl) * seq->num;

	i2c_priv->record_wirten_seq->regs = kzalloc(size, GFP_KERNEL);
	if (i2c_priv->record_wirten_seq->regs == NULL) {
		hwevext_adc_kfree_ops(i2c_priv->record_wirten_seq);
		return;
	}
	i2c_priv->record_wirten_seq->num = seq->num;
	if (memcpy_s(i2c_priv->record_wirten_seq->regs,
		size, seq->regs, size) != EOK)
		hwlog_err("%s: memcpy_s is failed\n", __func__);
}

static int hwevext_adc_mic_regulator_enable(
	struct hwevext_adc_i2c_priv *i2c_priv)
{
	int ret;

	ret = regulator_set_voltage(i2c_priv->regulator->mic_supply,
		i2c_priv->regulator->mic_voltage,
		i2c_priv->regulator->mic_voltage);
	if (ret) {
		hwlog_err("%s: set voltage err:%d\n", __func__, ret);
		return ret;
	}

	ret = regulator_set_load(i2c_priv->regulator->mic_supply,
		i2c_priv->regulator->mic_current);
	if (ret) {
		hwlog_err("%s: set current err:%d\n", __func__, ret);
		return ret;
	}

	ret = regulator_enable(i2c_priv->regulator->mic_supply);
	if (ret) {
		hwlog_err("%s: regulator enable err:%d\n",
			__func__, ret);
		return ret;
	}
	hwlog_info("%s: micbias enbale\n", __func__);

	return 0;
}

static int hwevext_adc_mic_regulator_disable(
	struct hwevext_adc_i2c_priv *i2c_priv)
{
	int ret;

	ret = regulator_disable(i2c_priv->regulator->mic_supply);
	if (ret) {
		hwlog_err("%s: regulator disable err:%d\n",
			__func__, ret);
		return ret;
	}
	ret = regulator_set_voltage(i2c_priv->regulator->mic_supply, 0,
		i2c_priv->regulator->mic_voltage);
	if (ret) {
		hwlog_err("%s: set voltage err:%d\n", __func__, ret);
		return ret;
	}

	ret = regulator_set_load(i2c_priv->regulator->mic_supply, 0);
	if (ret) {
		hwlog_err("%s: set current err:%d\n", __func__, ret);
		return ret;
	}
	hwlog_info("%s: micbias disbale\n", __func__);

	return 0;
}

static int hwevext_adc_mic_regulator_control(
	struct hwevext_adc_i2c_priv *i2c_priv,
	int req, unsigned int delay)
{
	int ret;

	if (i2c_priv->regulator == NULL ||
		i2c_priv->regulator->mic_supply == NULL) {
		hwlog_err("%s: mic_supply regulator invalid\n", __func__);
		return -EINVAL;
	}

	hwlog_info("%s: req:%d, mic_use_count:%d\n", __func__,
		req, i2c_priv->regulator->mic_use_count);
	if (req == MICB_ENABLE) {
		if (i2c_priv->regulator->mic_use_count > 0)
			return 0;

		ret = hwevext_adc_mic_regulator_enable(i2c_priv);
		if (ret)
			return ret;

		i2c_priv->regulator->mic_use_count++;
	} else {
		i2c_priv->regulator->mic_use_count--;
		if (i2c_priv->regulator->mic_use_count > 0)
			return 0;

		if (i2c_priv->regulator->mic_use_count < 0) {
			i2c_priv->regulator->mic_use_count = 0;
			return 0;
		}

		ret = hwevext_adc_mic_regulator_disable(i2c_priv);
		if (ret)
			return ret;
	}

	if (delay > 0)
		msleep(delay);

	return 0;
}

static int hwevext_adc_i2c_wirte_ctl_seq_regs(
	struct hwevext_adc_i2c_priv *i2c_priv,
	struct hwevext_adc_reg_ctl_sequence *seq,
	struct i2c_err_info *info)
{
	int i;
	int ret;
	int errno = 0;
	struct hwevext_adc_regmap_cfg *cfg = i2c_priv->regmap_cfg;

	for (i = 0; i < (int)(seq->num); i++) {
		if (seq->regs[i].ctl_type == HWEVEXT_DAC_PARAM_NODE_TYPE_GPIO) {
			ret = hwevext_adc_gpio_node_ctl(i2c_priv->priv_data,
				&(seq->regs[i]));
			if (ret == 0)
				continue;
			hwlog_err("%s: node %d, set gpio index%u %u err\n",
				__func__, i, seq->regs[i].addr,
				seq->regs[i].value);
			return ret;
		}

		if (seq->regs[i].ctl_type == HWEVEXT_DAC_PARAM_REGULATOR_TYPE) {
			ret = hwevext_adc_mic_regulator_control(i2c_priv,
				seq->regs[i].value, seq->regs[i].delay);
			if (ret == 0)
				continue;
			hwlog_err("%s: node %d, set regulator status:%u err\n",
				__func__, i, seq->regs[i].value);
			return ret;
		}

		/* regmap node */
		ret = hwevext_adc_i2c_reg_node_ops(cfg,
			&(seq->regs[i]), i, seq->num);
		if (ret < 0) {
			hwlog_err("%s: ctl %d, reg 0x%x w/r 0x%x err, ret %d\n",
				__func__, i, seq->regs[i].addr,
				seq->regs[i].value, ret);
			hwevext_adc_i2c_get_i2c_err_info(info, (unsigned int)i);
			errno = ret;
		}
	}
	info->regs_num = seq->num;
	hwevext_adc_i2c_dsm_report(i2c_priv, EXT_ADC_I2C_WRITE, errno, info);
	hwevext_adc_i2c_set_record_regs(i2c_priv, seq);

	return 0;
}

static int hwevext_adc_i2c_ctrl_write_regs(struct hwevext_adc_i2c_priv *i2c_priv,
	struct hwevext_adc_reg_ctl_sequence *seq)
{
	struct i2c_err_info info = {
		.regs_num    = 0,
		.err_count   = 0,
		.err_details = 0,
	};

	if (hwevext_adc_check_i2c_regmap_cfg(i2c_priv) < 0) {
		hwlog_err("%s: invalid argument\n", __func__);
		return -EINVAL;
	}

	if ((seq == NULL) || (seq->num == 0)) {
		hwlog_err("%s: reg node is invalid\n", __func__);
		return -EINVAL;
	}

#ifndef CONFIG_FINAL_RELEASE
	hwlog_info("%s: chip model %s, chip_id %u, node num %u\n",
		__func__, i2c_priv->chip_model, i2c_priv->chip_id, seq->num);
#endif

	if (!hwevext_adc_is_need_write_regs(i2c_priv, seq)) {
		hwlog_info("%s: adc%d not need re-write the same regs\n",
			__func__, i2c_priv->chip_id);
		return 0;
	}

	return hwevext_adc_i2c_wirte_ctl_seq_regs(i2c_priv, seq, &info);
}

static int hwevext_adc_init_regs_seq(struct hwevext_adc_i2c_priv *i2c_priv)
{
	if (hwevext_adc_check_i2c_regmap_cfg(i2c_priv) < 0) {
		hwlog_err("%s: invalid argument\n", __func__);
		return -EINVAL;
	}

	if (i2c_priv->init_regs_seq != NULL)
		return hwevext_adc_i2c_ctrl_write_regs(i2c_priv,
			i2c_priv->init_regs_seq);

	return 0;
}

static int hwevext_adc_poweron(struct hwevext_adc_i2c_priv *i2c_priv)
{
	if (hwevext_adc_check_i2c_regmap_cfg(i2c_priv) < 0) {
		hwlog_err("%s: invalid argument\n", __func__);
		return -EINVAL;
	}

	if (i2c_priv->poweron_regs_seq != NULL)
		return hwevext_adc_i2c_ctrl_write_regs(i2c_priv,
			i2c_priv->poweron_regs_seq);

	return 0;
}

static int hwevext_adc_poweroff(struct hwevext_adc_i2c_priv *i2c_priv)
{
	if (hwevext_adc_check_i2c_regmap_cfg(i2c_priv) < 0) {
		hwlog_err("%s: invalid argument\n", __func__);
		return -EINVAL;
	}

	if (i2c_priv->poweroff_regs_seq != NULL)
		return hwevext_adc_i2c_ctrl_write_regs(i2c_priv,
			i2c_priv->poweroff_regs_seq);

	return 0;
}

struct hwevext_adc_i2c_ctl_ops adc_i2c_ops = {
	.dump_regs  = hwevext_adc_i2c_dump_regs,
	.power_on  = hwevext_adc_poweron,
	.power_off = hwevext_adc_poweroff,
	.write_regs = hwevext_adc_i2c_ctrl_write_regs,
	.read_reg = hwevext_adc_i2c_ctrl_read_reg,
};

static bool hwevext_adc_i2c_is_reg_in_special_range(unsigned int reg_addr,
	int num, unsigned int *reg)
{
	int i;

	if ((num <= 0) || (reg == NULL)) {
		hwlog_err("%s: invalid arg\n", __func__);
		return false;
	}

	for (i = 0; i < num; i++) {
		if (reg[i] == reg_addr)
			return true;
	}
	return false;
}

static struct hwevext_adc_regmap_cfg *hwevext_adc_i2c_get_regmap_cfg(
	struct device *dev)
{
	struct hwevext_adc_i2c_priv *i2c_priv = NULL;

	if (dev == NULL) {
		hwlog_err("%s: invalid argument\n", __func__);
		return NULL;
	}
	i2c_priv = dev_get_drvdata(dev);
	if ((i2c_priv == NULL) || (i2c_priv->regmap_cfg == NULL)) {
		hwlog_err("%s: regmap_cfg invalid argument\n", __func__);
		return NULL;
	}
	return i2c_priv->regmap_cfg;
}

static bool hwevext_adc_i2c_writeable_reg(struct device *dev, unsigned int reg)
{
	struct hwevext_adc_regmap_cfg *cfg = NULL;

	cfg = hwevext_adc_i2c_get_regmap_cfg(dev);
	if (cfg == NULL)
		return false;
	/* config writable or unwritable, can not config in dts at same time */
	if (cfg->num_writeable > 0)
		return hwevext_adc_i2c_is_reg_in_special_range(reg,
			cfg->num_writeable, cfg->reg_writeable);
	if (cfg->num_unwriteable > 0)
		return !hwevext_adc_i2c_is_reg_in_special_range(reg,
			cfg->num_unwriteable, cfg->reg_unwriteable);

	return true;
}

static bool hwevext_adc_i2c_readable_reg(struct device *dev, unsigned int reg)
{
	struct hwevext_adc_regmap_cfg *cfg = NULL;

	cfg = hwevext_adc_i2c_get_regmap_cfg(dev);
	if (cfg == NULL)
		return false;
	/* config readable or unreadable, can not config in dts at same time */
	if (cfg->num_readable > 0)
		return hwevext_adc_i2c_is_reg_in_special_range(reg,
			cfg->num_readable, cfg->reg_readable);
	if (cfg->num_unreadable > 0)
		return !hwevext_adc_i2c_is_reg_in_special_range(reg,
			cfg->num_unreadable, cfg->reg_unreadable);

	return true;
}

static bool hwevext_adc_i2c_volatile_reg(struct device *dev, unsigned int reg)
{
	struct hwevext_adc_regmap_cfg *cfg = NULL;

	cfg = hwevext_adc_i2c_get_regmap_cfg(dev);
	if (cfg == NULL)
		return false;
	/* config volatile or unvolatile, can not config in dts at same time */
	if (cfg->num_volatile > 0)
		return hwevext_adc_i2c_is_reg_in_special_range(reg,
			cfg->num_volatile, cfg->reg_volatile);
	if (cfg->num_unvolatile > 0)
		return !hwevext_adc_i2c_is_reg_in_special_range(reg,
			cfg->num_unvolatile, cfg->reg_unvolatile);

	return true;
}

static void hwevext_adc_print_regs_info(const char *seq_str,
	struct hwevext_adc_reg_ctl_sequence *reg_ctl)
{
	unsigned int print_node_num;
	unsigned int i;
	struct hwevext_adc_reg_ctl *reg = NULL;

	if (reg_ctl == NULL)
		return;

	print_node_num =
		(reg_ctl->num < REG_PRINT_NUM) ? reg_ctl->num : REG_PRINT_NUM;

	/* only print two registers */
	for (i = 0; i < print_node_num; i++) {
		reg = &(reg_ctl->regs[i]);
		hwlog_info("%s: %s reg_%d=0x%x, 0x%x, 0x%x, 0x%x, 0x%x\n",
			__func__, seq_str, i, reg->addr, reg->mask, reg->value,
			reg->delay, reg->ctl_type);
	}
}

static int hwevext_adc_i2c_parse_reg_ctl(
	struct hwevext_adc_reg_ctl_sequence **reg_ctl, struct device_node *node,
	const char *ctl_str)
{
	struct hwevext_adc_reg_ctl_sequence *ctl = NULL;
	int count = 0;
	int val_num;
	int ret;

	if ((node == NULL) || (ctl_str == NULL)) {
		hwlog_err("%s: invalid argument\n", __func__);
		return -EINVAL;
	}

	ctl = kzalloc(sizeof(struct hwevext_adc_reg_ctl_sequence), GFP_KERNEL);
	if (ctl == NULL)
		return -ENOMEM;

	ret = hwevext_adc_get_prop_of_u32_array(node, ctl_str,
		(u32 **)&ctl->regs, &count);
	if ((count <= 0) || (ret < 0)) {
		hwlog_err("%s: get %s failed or count is 0\n",
			__func__, ctl_str);
		ret = -EFAULT;
		goto parse_reg_ctl_err_out;
	}

	val_num = sizeof(struct hwevext_adc_reg_ctl) / sizeof(unsigned int);
	if ((count % val_num) != 0) {
		hwlog_err("%s: count %d %% val_num %d != 0\n",
			__func__, count, val_num);
		ret = -EFAULT;
		goto parse_reg_ctl_err_out;
	}

	ctl->num = (unsigned int)(count / val_num);
	*reg_ctl = ctl;
	return 0;

parse_reg_ctl_err_out:
	hwevext_adc_i2c_free_reg_ctl(&ctl);
	return ret;
}

static int hwevext_adc_i2c_parse_dt_reg_ctl(struct i2c_client *i2c,
	struct device_node *node,
	struct hwevext_adc_reg_ctl_sequence **reg_ctl,
	const char *seq_str)
{
	int ret;

	if (!of_property_read_bool(node, seq_str)) {
		hwlog_debug("%s: %s not existed, skip\n", seq_str, __func__);
		return 0;
	}
	ret = hwevext_adc_i2c_parse_reg_ctl(reg_ctl,
		node, seq_str);
	if (ret < 0) {
		hwlog_err("%s: parse %s failed\n", __func__, seq_str);
		goto parse_dt_reg_ctl_err_out;
	}

	hwevext_adc_print_regs_info(seq_str, *reg_ctl);

parse_dt_reg_ctl_err_out:
	return ret;
}

static int hwevext_adc_parse_dts_sequence(struct i2c_client *i2c,
	struct device_node *node,
	struct hwevext_adc_i2c_priv *i2c_priv)
{
	int ret;

	ret = hwevext_adc_i2c_parse_dt_reg_ctl(i2c, node,
		&i2c_priv->version_regs_seq, "version_regs");
	ret += hwevext_adc_i2c_parse_dt_reg_ctl(i2c, node,
		&i2c_priv->dump_regs_sequence, "dump_regs");
	ret += hwevext_adc_i2c_parse_dt_reg_ctl(i2c, node,
		&i2c_priv->poweron_regs_seq, "poweron_regs");
	ret += hwevext_adc_i2c_parse_dt_reg_ctl(i2c, node,
		&i2c_priv->init_regs_seq, "init_regs");
	ret += hwevext_adc_i2c_parse_dt_reg_ctl(i2c, node,
		&i2c_priv->poweroff_regs_seq, "poweroff_regs");
	ret += hwevext_adc_i2c_parse_dt_reg_ctl(i2c, node,
		&i2c_priv->pga_volume_seq, "pga_volume_regs");
	ret += hwevext_adc_i2c_parse_dt_reg_ctl(i2c, node,
		&(i2c_priv->kctl_seqs[HWEVEXT_DAC_KCTL_TDM_MODE]),
		"tdm_mode_regs");
	ret += hwevext_adc_i2c_parse_dt_reg_ctl(i2c, node,
		&(i2c_priv->kctl_seqs[HWEVEXT_DAC_KCTL_DATA_SEL]),
		"data_sel_regs");
	ret += hwevext_adc_i2c_parse_dt_reg_ctl(i2c, node,
		&(i2c_priv->kctl_seqs[HWEVEXT_DAC_KCTL_MUTE_CTL]),
		"mute_ctl_regs");

	return ret;
}

static unsigned int hwevext_adc_i2c_get_reg_value_mask(int val_bits)
{
	unsigned int mask;

	if (val_bits == HWEVEXT_ADC_REG_VALUE_B16)
		mask = HWEVEXT_ADC_REG_VALUE_M16;
	else if (val_bits == HWEVEXT_ADC_REG_VALUE_B24)
		mask = HWEVEXT_ADC_REG_VALUE_M24;
	else if (val_bits == HWEVEXT_ADC_REG_VALUE_B32)
		mask = HWEVEXT_ADC_REG_VALUE_M32;
	else /* SMARTPAKIT_REG_VALUE_B8 or other */
		mask = HWEVEXT_ADC_REG_VALUE_M8;

	return mask;
}

static void hwevext_adc_i2c_free_regmap_cfg(struct hwevext_adc_regmap_cfg **cfg)
{
	if (*cfg == NULL)
		return;

	hwevext_adc_kfree_ops((*cfg)->reg_writeable);
	hwevext_adc_kfree_ops((*cfg)->reg_unwriteable);
	hwevext_adc_kfree_ops((*cfg)->reg_readable);
	hwevext_adc_kfree_ops((*cfg)->reg_unreadable);
	hwevext_adc_kfree_ops((*cfg)->reg_volatile);
	hwevext_adc_kfree_ops((*cfg)->reg_unvolatile);
	hwevext_adc_kfree_ops((*cfg)->reg_defaults);

	kfree((*cfg));
	(*cfg) = NULL;
}

static int hwevext_adc_i2c_parse_reg_defaults(struct device_node *node,
	struct hwevext_adc_regmap_cfg *cfg_info)
{
	const char *reg_defaults_str = "reg_defaults";

	return hwevext_adc_get_prop_of_u32_array(node, reg_defaults_str,
		(u32 **)&cfg_info->reg_defaults, &cfg_info->num_defaults);
}

static int hwevext_adc_i2c_parse_special_regs_range(struct device_node *node,
	struct hwevext_adc_regmap_cfg *cfg_info)
{
	const char *reg_writeable_str   = "reg_writeable";
	const char *reg_unwriteable_str = "reg_unwriteable";
	const char *reg_readable_str    = "reg_readable";
	const char *reg_unreadable_str  = "reg_unreadable";
	const char *reg_volatile_str    = "reg_volatile";
	const char *reg_unvolatile_str  = "reg_unvolatile";
	int ret;

	cfg_info->num_writeable   = 0;
	cfg_info->num_unwriteable = 0;
	cfg_info->num_readable    = 0;
	cfg_info->num_unreadable  = 0;
	cfg_info->num_volatile    = 0;
	cfg_info->num_unvolatile  = 0;
	cfg_info->num_defaults    = 0;

	ret = hwevext_adc_get_prop_of_u32_array(node, reg_writeable_str,
		&cfg_info->reg_writeable, &cfg_info->num_writeable);
	ret += hwevext_adc_get_prop_of_u32_array(node, reg_unwriteable_str,
		&cfg_info->reg_unwriteable, &cfg_info->num_unwriteable);
	ret += hwevext_adc_get_prop_of_u32_array(node, reg_readable_str,
		&cfg_info->reg_readable, &cfg_info->num_readable);
	ret += hwevext_adc_get_prop_of_u32_array(node, reg_unreadable_str,
		&cfg_info->reg_unreadable, &cfg_info->num_unreadable);
	ret += hwevext_adc_get_prop_of_u32_array(node, reg_volatile_str,
		&cfg_info->reg_volatile, &cfg_info->num_volatile);
	ret += hwevext_adc_get_prop_of_u32_array(node, reg_unvolatile_str,
		&cfg_info->reg_unvolatile, &cfg_info->num_unvolatile);
	ret += hwevext_adc_i2c_parse_reg_defaults(node, cfg_info);
	return ret;
}

static int hwevext_adc_i2c_parse_remap_cfg(struct device_node *node,
	struct hwevext_adc_regmap_cfg **cfg)
{
	struct hwevext_adc_regmap_cfg *cfg_info = NULL;
	const char *reg_bits_str     = "reg_bits";
	const char *val_bits_str     = "val_bits";
	const char *cache_type_str   = "cache_type";
	const char *max_register_str = "max_register";
	int ret;

	cfg_info = kzalloc(sizeof(struct hwevext_adc_regmap_cfg), GFP_KERNEL);
	if (cfg_info == NULL)
		return -ENOMEM;

	ret = of_property_read_u32(node, reg_bits_str,
		(u32 *)&cfg_info->cfg.reg_bits);
	if (ret < 0) {
		hwlog_err("%s: get reg_bits failed\n", __func__);
		ret = -EFAULT;
		goto hwevext_adc_parse_remap_err_out;
	}

	ret = of_property_read_u32(node, val_bits_str,
		(u32 *)&cfg_info->cfg.val_bits);
	if (ret < 0) {
		hwlog_err("%s: get val_bits failed\n", __func__);
		ret = -EFAULT;
		goto hwevext_adc_parse_remap_err_out;
	}
	cfg_info->value_mask = hwevext_adc_i2c_get_reg_value_mask(
		cfg_info->cfg.val_bits);

	ret = of_property_read_u32(node, cache_type_str,
		(u32 *)&cfg_info->cfg.cache_type);
	if ((ret < 0) || (cfg_info->cfg.cache_type > REGCACHE_FLAT)) {
		hwlog_err("%s: get cache_type failed\n", __func__);
		ret = -EFAULT;
		goto hwevext_adc_parse_remap_err_out;
	}

	ret = of_property_read_u32(node, max_register_str,
		&cfg_info->cfg.max_register);
	if (ret < 0) {
		hwlog_err("%s: get max_register failed\n", __func__);
		ret = -EFAULT;
		goto hwevext_adc_parse_remap_err_out;
	}

	ret = hwevext_adc_i2c_parse_special_regs_range(node, cfg_info);
	if (ret < 0)
		goto hwevext_adc_parse_remap_err_out;

	*cfg = cfg_info;
	return 0;

hwevext_adc_parse_remap_err_out:
	hwevext_adc_i2c_free_regmap_cfg(&cfg_info);
	return ret;
}

static int hwevext_adc_i2c_regmap_init(struct i2c_client *i2c,
	struct device_node *adc_node,
	struct hwevext_adc_i2c_priv *i2c_priv)
{
	const char *regmap_cfg_str = "regmap_cfg";
	struct hwevext_adc_regmap_cfg *cfg = NULL;
	struct device_node *node = NULL;
	int ret;
	int val_num;

	node = of_get_child_by_name(adc_node, regmap_cfg_str);
	if (node == NULL) {
		hwlog_debug("%s: regmap_cfg not existed, skip\n", __func__);
		return 0;
	}

	ret = hwevext_adc_i2c_parse_remap_cfg(node, &i2c_priv->regmap_cfg);
	if (ret < 0)
		return ret;

	cfg = i2c_priv->regmap_cfg;
	val_num = sizeof(struct reg_default) / sizeof(unsigned int);
	if (cfg->num_defaults > 0) {
		if ((cfg->num_defaults % val_num) != 0) {
			hwlog_err("%s: reg_defaults %d%%%d != 0\n",
				__func__, cfg->num_defaults, val_num);
			ret = -EFAULT;
			goto regmap_init_err_out;
		}
	}

#ifndef CONFIG_FINAL_RELEASE
	hwlog_info("%s: regmap_cfg get w%d,%d,r%d,%d,v%d,%d,default%d\n",
		__func__, cfg->num_writeable, cfg->num_unwriteable,
		cfg->num_readable, cfg->num_unreadable, cfg->num_volatile,
		cfg->num_unvolatile, cfg->num_defaults / val_num);
#endif

	/* set num_reg_defaults */
	if (cfg->num_defaults > 0) {
		cfg->num_defaults /= val_num;
		cfg->cfg.reg_defaults = cfg->reg_defaults;
		cfg->cfg.num_reg_defaults = (unsigned int)cfg->num_defaults;
	}

	cfg->cfg.writeable_reg = hwevext_adc_i2c_writeable_reg;
	cfg->cfg.readable_reg  = hwevext_adc_i2c_readable_reg;
	cfg->cfg.volatile_reg  = hwevext_adc_i2c_volatile_reg;

	cfg->regmap = regmap_init_i2c(i2c, &cfg->cfg);
	if (IS_ERR(cfg->regmap)) {
		hwlog_err("%s: regmap_init_i2c regmap failed\n", __func__);
		ret = -EFAULT;
		goto regmap_init_err_out;
	}
	return 0;
regmap_init_err_out:
	hwevext_adc_i2c_free_regmap_cfg(&i2c_priv->regmap_cfg);
	return ret;
}

static int hwevext_adc_i2c_regmap_deinit(struct hwevext_adc_i2c_priv *i2c_priv)
{
	struct hwevext_adc_regmap_cfg *cfg = NULL;

	if ((i2c_priv == NULL) || (i2c_priv->regmap_cfg == NULL)) {
		hwlog_err("%s: invalid argument\n", __func__);
		return -EINVAL;
	}
	cfg = i2c_priv->regmap_cfg;

	regmap_exit(cfg->regmap);
	cfg->regmap = NULL;
	hwevext_adc_i2c_free_regmap_cfg(&cfg);
	return 0;
}

static int hwevext_adc_check_chip_info_valid(
	struct hwevext_adc_i2c_priv *i2c_priv)
{
	if (i2c_priv == NULL) {
		hwlog_err("%s: invalid argument\n", __func__);
		return -EINVAL;
	}

	if (i2c_priv->chip_id >= HWEVEXT_ADC_ID_MAX) {
		hwlog_err("%s: invalid chip_id %u\n", __func__,
			i2c_priv->chip_id);
		return -EFAULT;
	}

	return 0;
}

static int hwevext_adc_i2c_parse_dt_chip(struct i2c_client *i2c,
	struct hwevext_adc_i2c_priv *i2c_priv)
{
	const char *chip_id_str      = "chip_id";
	const char *chip_model_str   = "chip_model";
	struct device_node *adc_node = NULL;
	int ret;

	ret = get_adc_node(i2c, i2c_priv, &adc_node);
	if (ret < 0)
		return ret;

	ret = hwevext_adc_get_prop_of_u32_type(adc_node, chip_id_str,
		&i2c_priv->chip_id, true);
	ret += hwevext_adc_get_prop_of_str_type(adc_node, chip_model_str,
		&i2c_priv->chip_model);
	if (ret < 0)
		goto parse_dt_err_out;

	ret = hwevext_adc_check_chip_info_valid(i2c_priv);
	if (ret < 0)
		goto parse_dt_err_out;

	return 0;

parse_dt_err_out:
	return ret;
}

static void hwevext_adc_i2c_free(struct hwevext_adc_i2c_priv *i2c_priv)
{
	int i;

	if (i2c_priv == NULL) {
		hwlog_err("%s: i2c_priv invalid argument\n", __func__);
		return;
	}

	if (i2c_priv->regmap_cfg != NULL) {
		hwevext_adc_i2c_regmap_deinit(i2c_priv);
		i2c_priv->regmap_cfg = NULL;
	}

	if (i2c_priv->regulator != NULL) {
		if (i2c_priv->regulator->mic_supply != NULL)
			devm_regulator_put(i2c_priv->regulator->mic_supply);

		hwevext_adc_kfree_ops(i2c_priv->regulator);
		i2c_priv->regulator = NULL;
		i2c_priv->regulator->mic_use_count = 0;
	}

	hwevext_adc_i2c_free_reg_ctl(&i2c_priv->init_regs_seq);
	hwevext_adc_i2c_free_reg_ctl(&i2c_priv->poweron_regs_seq);
	hwevext_adc_i2c_free_reg_ctl(&i2c_priv->poweroff_regs_seq);
	hwevext_adc_i2c_free_reg_ctl(&i2c_priv->dump_regs_sequence);
	hwevext_adc_i2c_free_reg_ctl(&i2c_priv->version_regs_seq);
	hwevext_adc_i2c_free_reg_ctl(&i2c_priv->record_wirten_seq);
	hwevext_adc_i2c_free_reg_ctl(&i2c_priv->pga_volume_seq);

	for (i = 0; i < HWEVEXT_DAC_KCTL_MAX; i++)
		hwevext_adc_i2c_free_reg_ctl(&(i2c_priv->kctl_seqs[i]));
}

static void hwevext_adc_i2c_reset_priv_data(
	struct hwevext_adc_i2c_priv *i2c_priv)
{
	if (i2c_priv == NULL)
		return;

	i2c_priv->probe_completed = 0;
	hwevext_adc_i2c_free(i2c_priv);
}

static int hwevext_adc_i2c_read_chip_version(
	struct hwevext_adc_i2c_priv *i2c_priv)
{
	struct regmap *regmap = NULL;
	struct hwevext_adc_reg_ctl_sequence *seq = NULL;
	struct hwevext_adc_reg_ctl *regs = NULL;
	unsigned int reg_addr;
	unsigned int value = 0;
	int ret;
	int i;
	unsigned int num;

	if (hwevext_adc_check_i2c_regmap_cfg(i2c_priv) < 0) {
		hwlog_err("%s: invalid argument\n", __func__);
		return -EINVAL;
	}

	if (i2c_priv->version_regs_seq == NULL)
		return 0;

	seq = i2c_priv->version_regs_seq;
	num = seq->num;
	regmap = i2c_priv->regmap_cfg->regmap;

#ifndef CONFIG_FINAL_RELEASE
	hwlog_info("%s: adc %u, seq num %u read version\n",
		__func__, i2c_priv->chip_id, seq->num);
#endif
	for (i = 0; i < (int)num; i++) {
		regs = &(seq->regs[i]);
		reg_addr = regs->addr;
		hwlog_info("%s: adc %u, seq num %u  read version reg:0x%x\n",
			__func__, i2c_priv->chip_id, seq->num, reg_addr);
		ret = hwevext_adc_regmap_read(regmap, reg_addr, &value);
		hwevext_adc_i2c_dsm_report(i2c_priv, EXT_ADC_I2C_READ, ret,
			NULL);
		if (ret < 0) {
			hwlog_err("%s: %s read version regs:0x%x failed, %d\n",
				__func__, i2c_priv->chip_model, reg_addr, ret);
			return ret;
		}
		hwlog_info("%s: adc %u, r reg 0x%x = 0x%x\n", __func__,
			i2c_priv->chip_id, reg_addr, value);

		if ((value & regs->mask) != regs->chip_version) {
			hwlog_err("%s: adc %u, r reg 0x%x = 0x%x,"
				"mask:0x%x, chip_version:0x%x\n",
				__func__, i2c_priv->chip_id, reg_addr,
				value, regs->mask, regs->chip_version);
			return -EINVAL;
		}
	}
	return ret;
}

static int hwevext_adc_parse_mic_regulator(struct i2c_client *i2c,
	struct device_node *node, struct hwevext_adc_i2c_priv *i2c_priv)
{
	struct hwevext_adc_regulator *regulator = NULL;
	int ret;
	const char *mic_supply_str = "vdd_mic-supply";
	const char *mic_supply_str1 = "vdd_mic";
	const char *mic_voltage_str = "vdd_mic-voltage";
	const char *mic_current_str = "vdd_mic-current";

	if (!of_property_read_bool(node, mic_supply_str))
		return 0;

	regulator = kzalloc(sizeof(struct hwevext_adc_regulator), GFP_KERNEL);
	if (regulator == NULL)
		return -ENOMEM;

	regulator->mic_supply = devm_regulator_get(&i2c->dev,
		mic_supply_str1);
	if (IS_ERR_OR_NULL(regulator->mic_supply)) {
		hwlog_err("%s: failed to get micbias supply\n", __func__);
		ret = -ENODEV;
		goto parse_err_out;
	}

	ret = of_property_read_u32(node, mic_voltage_str,
		&regulator->mic_voltage);
	if (ret) {
		hwlog_warn("%s: failed to get micbias voltage\n", __func__);
		regulator->mic_voltage = MIC_REGULATOR_VOLTAGE;
	}

	ret = of_property_read_u32(node, mic_current_str,
		&regulator->mic_current);
	if (ret) {
		hwlog_warn("%s:failed to get micbias current\n", __func__);
		regulator->mic_current = MIC_REGULATOR_CURRENT;
	}

	i2c_priv->regulator = regulator;
	return 0;

parse_err_out:
	kfree(regulator);
	return ret;
}

static int hwevext_adc_i2c_check_status(struct i2c_client *i2c,
	const struct i2c_device_id *id)
{
	if (hwevext_adc_get_misc_init_flag() == 0) {
		hwlog_info("%s: this driver need probe_defer\n", __func__);
		return -EPROBE_DEFER;
	}

	if (i2c == NULL) {
		hwlog_err("%s: invalid argument\n", __func__);
		return -EINVAL;
	}

	hwlog_info("%s: device %s, addr=0x%x, flags=0x%x\n", __func__,
		id->name, i2c->addr, i2c->flags);
	if (!i2c_check_functionality(i2c->adapter, I2C_FUNC_I2C)) {
		hwlog_err("%s: i2c check functionality error\n", __func__);
		return -ENODEV;
	}

	return 0;
}

static int hwevext_adc_i2c_resource_init(struct i2c_client *i2c,
	struct hwevext_adc_i2c_priv *i2c_priv)
{
	int ret;
	struct device_node *adc_node = NULL;

	ret = get_adc_node(i2c, i2c_priv, &adc_node);
	if (ret < 0)
		return ret;

	ret = hwevext_adc_parse_dts_sequence(i2c, adc_node, i2c_priv);
	if (ret < 0)
		return ret;

	/* int regmap */
	ret = hwevext_adc_i2c_regmap_init(i2c, adc_node, i2c_priv);
	if (ret < 0)
		return ret;

	ret = hwevext_adc_i2c_read_chip_version(i2c_priv);
	if (ret < 0)
		return ret;

	/* register i2c device to hwevext adc device */
	ret = hwevext_adc_register_i2c_device(i2c_priv);
	if (ret < 0)
		return ret;

	ret = hwevext_adc_init_regs_seq(i2c_priv);
	if (ret < 0)
		return ret;

	ret = hwevext_adc_parse_mic_regulator(i2c, adc_node, i2c_priv);
	if (ret < 0)
		return ret;

	return 0;
}

static int hwevext_adc_enumrate(struct i2c_client *i2c,
	struct hwevext_adc_i2c_priv *i2c_priv)
{
	int ret;
	unsigned int i;

	ret = of_property_read_u32(i2c->dev.of_node, "adc_num_by_same_i2c_addr",
		&i2c_priv->adc_num_by_same_i2c_addr);
	if (ret < 0)
		i2c_priv->adc_num_by_same_i2c_addr = 1;

	for (i = 0; i < i2c_priv->adc_num_by_same_i2c_addr; i++) {
		i2c_priv->adc_iter = i;
		hwevext_adc_i2c_reset_priv_data(i2c_priv);
		ret = hwevext_adc_i2c_parse_dt_chip(i2c, i2c_priv);
		if (ret < 0)
			continue;

		if (hwevext_adc_i2c_probe_skip[i2c_priv->chip_id]) {
			hwlog_info("%s: chip_id %u has probed success, skip\n",
				__func__, i2c_priv->chip_id);
			return ADC_ALREADY_ENUMRATED_NEED_SKIP;
		}

		ret = hwevext_adc_i2c_resource_init(i2c, i2c_priv);
		if (ret < 0)
			continue;

		return ADC_ENUMRATE_SUCCED;
	}

	return ret;
}

static int hwevext_adc_i2c_probe(struct i2c_client *i2c,
	const struct i2c_device_id *id)
{
	struct hwevext_adc_i2c_priv *i2c_priv = NULL;
	int ret;

	ret = hwevext_adc_i2c_check_status(i2c, id);
	if (ret < 0)
		return ret;

	i2c_priv = kzalloc(sizeof(struct hwevext_adc_i2c_priv), GFP_KERNEL);
	if (i2c_priv == NULL)
		return -ENOMEM;

	i2c_set_clientdata(i2c, i2c_priv);
	dev_set_drvdata(&i2c->dev, i2c_priv);

	ret = hwevext_adc_enumrate(i2c, i2c_priv);
	if (ret == ADC_ALREADY_ENUMRATED_NEED_SKIP) {
		ret = -EINVAL;
		goto skip_probe;
	} else if (ret < 0) {
		goto probe_err_out;
	}

	hwevext_adc_register_i2c_ctl_ops(&adc_i2c_ops);
	i2c_priv->probe_completed = 1;
	hwevext_adc_i2c_probe_skip[i2c_priv->chip_id] = true;
	hwlog_info("%s: end success\n", __func__);
	return 0;
probe_err_out:
	hwlog_err("%s: end failed\n", __func__);
skip_probe:
	hwevext_adc_i2c_free(i2c_priv);
	kfree(i2c_priv);
	return ret;
}

static int hwevext_adc_i2c_remove(struct i2c_client *i2c)
{
	struct hwevext_adc_i2c_priv *i2c_priv = NULL;

	hwlog_info("%s: remove\n", __func__);
	if (i2c == NULL) {
		pr_err("%s: invalid argument\n", __func__);
		return -EINVAL;
	}

	i2c_priv = i2c_get_clientdata(i2c);
	if (i2c_priv == NULL) {
		hwlog_err("%s: i2c_priv invalid\n", __func__);
		return -EINVAL;
	}

	i2c_set_clientdata(i2c, NULL);
	dev_set_drvdata(&i2c->dev, NULL);

	/* deregister i2c device */
	hwevext_adc_deregister_i2c_device(i2c_priv);
	hwevext_adc_deregister_i2c_ctl_ops();

	hwevext_adc_i2c_free(i2c_priv);
	kfree(i2c_priv);
	return 0;
}

static void hwevext_adc_i2c_shutdown(struct i2c_client *i2c)
{
}

#ifdef CONFIG_PM
static int hwevext_adc_i2c_suspend(struct device *dev)
{
	struct hwevext_adc_i2c_priv *i2c_priv = NULL;

	if (dev == NULL) {
		hwlog_err("%s: invalid argument\n", __func__);
		return -EINVAL;
	}

	i2c_priv = dev_get_drvdata(dev);
	if (i2c_priv == NULL)
		return 0;

	if ((i2c_priv->regmap_cfg != NULL) &&
		(i2c_priv->regmap_cfg->regmap != NULL) &&
		(i2c_priv->regmap_cfg->cfg.cache_type == REGCACHE_RBTREE))
		regcache_cache_only(i2c_priv->regmap_cfg->regmap, (bool)true);

	return 0;
}

static int hwevext_adc_i2c_resume(struct device *dev)
{
	struct hwevext_adc_i2c_priv *i2c_priv = NULL;

	if (dev == NULL) {
		hwlog_err("%s: invalid argument\n", __func__);
		return -EINVAL;
	}

	i2c_priv = dev_get_drvdata(dev);
	if (i2c_priv == NULL)
		return 0;

	if ((i2c_priv->regmap_cfg != NULL) &&
		(i2c_priv->regmap_cfg->regmap != NULL) &&
		(i2c_priv->regmap_cfg->cfg.cache_type == REGCACHE_RBTREE)) {
		regcache_cache_only(i2c_priv->regmap_cfg->regmap, (bool)false);
		regcache_sync(i2c_priv->regmap_cfg->regmap);
	}

	return 0;
}
#else
#define hwevext_adc_i2c_suspend NULL /* function pointer */
#define hwevext_adc_i2c_resume  NULL /* function pointer */
#endif /* CONFIG_PM */

static const struct dev_pm_ops hwevext_adc_i2c_pm_ops = {
	.suspend = hwevext_adc_i2c_suspend,
	.resume  = hwevext_adc_i2c_resume,
};

static const struct i2c_device_id hwevext_adc_i2c_id[] = {
	{ "hwevext_adc_i2c", 0 },
	{},
};
MODULE_DEVICE_TABLE(i2c, hwevext_adc_i2c_id);

static const struct of_device_id hwevext_adc_i2c_match[] = {
	{ .compatible = "huawei,hwevext_adc_i2c", },
	{},
};
MODULE_DEVICE_TABLE(of, hwevext_adc_i2c_match);

static struct i2c_driver hwevext_adc_i2c_driver = {
	.driver = {
		.name           = "hwevext_adc_i2c",
		.owner          = THIS_MODULE,
		.pm             = &hwevext_adc_i2c_pm_ops,
		.of_match_table = of_match_ptr(hwevext_adc_i2c_match),
	},
	.probe    = hwevext_adc_i2c_probe,
	.remove   = hwevext_adc_i2c_remove,
	.shutdown = hwevext_adc_i2c_shutdown,
	.id_table = hwevext_adc_i2c_id,
};

static int __init hwevext_adc_i2c_init(void)
{
	return i2c_add_driver(&hwevext_adc_i2c_driver);
}

static void __exit hwevext_adc_i2c_exit(void)
{
	i2c_del_driver(&hwevext_adc_i2c_driver);
}

fs_initcall(hwevext_adc_i2c_init);
module_exit(hwevext_adc_i2c_exit);

MODULE_DESCRIPTION("hwevext adc i2c driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
MODULE_LICENSE("GPL v2");

