/*
* sy3132cs.c
*
* code for sy3132cs rgb sensor
*
*  Copyright (c) 2022 Huawei Technologies Co., Ltd.
*
* Description: code for sy3132cs color sensor
* Author: hufan
* Create: 2021-10-18
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

#include <linux/kernel.h>
#include <linux/i2c.h>
#include <linux/input.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/errno.h>
#include <linux/delay.h>
#include <linux/string.h>
#include <linux/mutex.h>
#include <linux/unistd.h>
#include <linux/interrupt.h>
#include <linux/platform_device.h>
#include <linux/input.h>
#include <linux/slab.h>
#include <linux/pm.h>
#include <linux/string.h>
#include <linux/uaccess.h>
#include <linux/kthread.h>
#include <linux/freezer.h>
#include <linux/timer.h>
#include <linux/version.h>
#include <securec.h>
#include <huawei_platform/log/hw_log.h>
#include <../apsensor_channel/ap_sensor.h>
#include <../apsensor_channel/ap_sensor_route.h>

#include "sy3132cs.h"

#ifdef CONFIG_HUAWEI_DSM
#include <dsm/dsm_pub.h>
#endif

#ifdef HWLOG_TAG
#undef HWLOG_TAG
#endif
#define HWLOG_TAG color_sensor
HWLOG_REGIST();

#define CH_MAX(a, b) ((a) > (b) ? (a) : (b))

static bool fd_timer_stopped = true;
static bool first_fifo_full = false;
static uint32_t algo_support;
static uint16_t ring_count = 0;
static uint8_t print_log_count = 0;
static struct color_chip *p_chip;
static enum sy3132cs_sensor_id_t sensor_type;

extern UINT32 flicker_support;
extern int (*color_default_enable)(bool enable);
extern int color_report_val[MAX_REPORT_LEN];

static sy3132cs_algo_t sy3132cs_algo;
static const int32_t nature_log_coef = -130; // expand 10000 -0.013
static const int32_t nature_log_offset = 11112; // expand 10000  1.1112
static struct mutex read_fifo_lock;
static uint16_t gain_ch_data[SY3132CS_CHANNEL_NUMBER][GAIN_CALI_NUM] = { 0 };
static uint16_t  gain_ch_ration[SY3132CS_CHANNEL_NUMBER][GAIN_CALI_NUM - 1] = { 0 };
static bool light12_flag = false;
static uint8_t light12_time_count = 0;
static bool gain_cali_flag = false;
static bool cali_flag = false;
static bool monochro_flag = false;
bool  light12_first = true;
int counter_9302 = 0;
bool als_valid_flag = false;

const SY3132CS_IC_FUNC_T sy3132cs_ic_func = {
	// ADC1_EN
	{ SY3132CS_REG_ALS_CON1, 3, 1 },
	// ADC2_EN
	{ SY3132CS_REG_ALS_CON1, 4, 1 },
	// ADC3_EN
	{ SY3132CS_REG_ALS_CON1, 5, 1 },
	// ADC4_EN
	{ SY3132CS_REG_ALS_CON1, 6, 1 },
	// ADC5_EN
	{ SY3132CS_REG_ALS_CON1, 7, 1 },
	// ALS_IT
	{ SY3132CS_REG_ALS_CON2, 4, 4 },
	// ALS_GAIN
	{ SY3132CS_REG_ALS_CON2, 0, 4 },
	// ALS_MODE
	{ SY3132CS_REG_ALS_CON3, 6, 2 },
	// MODE1_IT
	{ SY3132CS_REG_ALS_CON3, 5, 1 },
	// MODE1_CYC
	{ SY3132CS_REG_ALS_CON3, 0, 4 },
	// MODE2_CYC
	{ SY3132CS_REG_ALS_CON4, 0, 5 },
	// FILTER_EN
	{ SY3132CS_REG_ALS_CON5, 7, 1 },
	// FILTER_n
	{ SY3132CS_REG_ALS_CON5, 4, 2 },
	// FILTER_m1
	{ SY3132CS_REG_ALS_CON5, 2, 2 },
	// FILTER_m2
	{ SY3132CS_REG_ALS_CON5, 0, 2 },
	// FLK_EN
	{ SY3132CS_REG_ALS_CON6, 7, 1 },
	// FLK_IT
	{ SY3132CS_REG_ALS_CON6, 4, 3 },
	// FLK_GAIN
	{ SY3132CS_REG_ALS_CON6, 0, 3 },
	// AINT_EN
	{ SY3132CS_REG_AINT_CON, 7, 1 },
	// AINT_SOURCE
	{ SY3132CS_REG_AINT_CON, 2, 4 },
	// AINT_PRST
	{ SY3132CS_REG_AINT_CON, 0, 2 },
	// FLV_EN
	{ SY3132CS_REG_FINT_CON, 7, 1 },
	// FLK_OVERWR_EN
	{ SY3132CS_REG_FINT_CON, 6, 1 },
	// FIFO_CAL_EN
	{ SY3132CS_REG_FINT_CON, 4, 1 },
	// FLK_INT_EN
	{ SY3132CS_REG_FINT_CON, 3, 1 },
	// FLK_TYPE
	{ SY3132CS_REG_FINT_CON, 2, 1 },
	// FLK_PRST
	{ SY3132CS_REG_FINT_CON, 0, 2 },
	// SYNC_MODE
	{ SY3132CS_REG_SYN_CON, 6, 2 },
	// SYNC_DELAY
	{ SY3132CS_REG_SYN_CON, 1, 5 },
	// DRV_EN
	{ SY3132CS_REG_DRV_CON1, 7, 1 },
	// DRV_CUR
	{ SY3132CS_REG_DRV_CON1, 0, 7 }
};

static sy3132_gcl_t sy3132_gcl[MAX_GCL_NUM] = {
	{ 2048, 20000 }, // it expand 100
	{ 2048, 10000 },
	{ 2048, 5000 },
	{ 2048, 2500 },
	{ 2048, 1250},
	{ 64, 20000 },
	{ 64, 10000 },
	{ 64, 5000 },
	{ 64, 2500 },
	{ 64, 1250 },
};

pxs_kalman_algo_t pxs_kalman_algo[10] = {
	{ 1, 200, 1, 100, 1, 0, 0, 0, 0, 100, 1, 3, 1000, 0, 0 },
	{ 1, 200, 1, 100, 1, 0, 0, 0, 0, 100, 1, 3, 1000, 0, 0 },
	{ 1, 200, 1, 100, 1, 0, 0, 0, 0, 100, 1, 3, 1000, 0, 0 },
	{ 1, 200, 1, 100, 1, 0, 0, 0, 0, 100, 1, 3, 1000, 0, 0 },
	{ 1, 200, 1, 100, 1, 0, 0, 0, 0, 100, 1, 3, 1000, 0, 0 },
	{ 1, 200, 1, 100, 1, 0, 0, 0, 0, 100, 1, 3, 1000, 0, 0 },
	{ 1, 200, 1, 100, 1, 0, 0, 0, 0, 100, 1, 3, 1000, 0, 0 },
	{ 1, 200, 1, 100, 1, 0, 0, 0, 0, 100, 1, 3, 1000, 0, 0 },
	{ 1, 200, 1, 100, 1, 0, 0, 0, 0, 100, 1, 3, 1000, 0, 0 },
	{ 1, 200, 1, 100, 1, 0, 0, 0, 0, 100, 1, 3, 1000, 0, 0 }
};

int sy3132cs_set_ic_func(const struct i2c_client *i2c, IC_FUNC_INFO func, uint8_t data)
{
	uint8_t buf[1] = { 0 };
	uint8_t clear_data = 1;
	int i;
	int ret;

	ret = color_sensor_get_byte(i2c, func.reg, buf);
	if (ret < 0)
		return ret;

	if (func.bit_len == 0)
		return -1;

	for (i = 0; i < func.bit_len - 1; i++) {
		clear_data <<= 1;
		clear_data++;
	}
	data &= clear_data;
	clear_data <<= func.offset;
	clear_data ^= 0xFF;
	buf[0] &= clear_data;
	buf[0] |= (data << func.offset);
	ret = color_sensor_set_byte(i2c, func.reg, buf[0]);

	return ret;
}

int sy3132cs_get_ic_func(const struct i2c_client *i2c, IC_FUNC_INFO func)
{
	uint8_t buf[1] = { 0 };
	uint8_t clear_data = 1;
	int i;
	int ret;

	ret = color_sensor_get_byte(i2c, func.reg, buf);
	if (ret < 0)
		return ret;

	if (func.bit_len == 0)
		return -1;

	for (i = 0; i < func.bit_len - 1; i++) {
		clear_data <<= 1;
		clear_data++;
	}
	return ((buf[0] >> func.offset) & clear_data);
}

static uint16_t trans_gain_value_to_index(uint16_t gain)
{
	uint16_t temp;
	uint16_t i;

	if (gain == 0)
		return 0;

	temp = GAIN_MAX / gain;
	for (i = 0; temp > 1; i++)
		temp /= GAIN_DEFAULT_RATION;

	return i;
}

static uint16_t trans_gain_index_to_value(uint16_t index)
{
	uint16_t temp = 1;
	uint16_t i;

	for (i = 0; i < index; i++)
		temp *= GAIN_DEFAULT_RATION;

	return GAIN_MAX / temp;
}

// it expand 100
static uint16_t trans_it_value_to_index(uint16_t it)
{
	if (it <= IT_TIME_INDEX0_VALUE)
		return IT_INDEX_ZERO;
	else if (it <= IT_TIME_INDEX1_VALUE)
		return IT_INDEX_ONE;
	else if (it <= IT_TIME_INDEX2_VALUE)
		return IT_INDEX_TWO;
	else if (it <= IT_TIME_INDEX3_VALUE)
		return IT_INDEX_THREE;
	else if (it <= IT_TIME_INDEX4_VALUE)
		return IT_INDEX_FOUR;
	else if (it <= IT_TIME_INDEX5_VALUE)
		return IT_INDEX_FIVE;
	else if (it <= IT_TIME_INDEX6_VALUE)
		return IT_INDEX_SIX;
	else if (it <= IT_TIME_INDEX7_VALUE)
		return IT_INDEX_SEVEN;
	else
		return IT_INDEX_EIGHT;
}

// it expand 100
static uint16_t trans_it_index_to_value(uint16_t index)
{
	uint16_t temp = 1;
	uint16_t i;

	if (index < IT_INDEX_TWO) {
		if (index == 0)
			return IT_TIME_INDEX0_VALUE;
		else
			return IT_TIME_INDEX1_VALUE;
	}
	for (i = IT_INDEX_TWO; i < index; i++)
		temp *= IT_TIME_DEFAULT_RATION;

	temp *= IT_TIME_INDEX2_VALUE;

	return temp;
}

static uint16_t trans_flk_gain_value_to_index(uint16_t gain)
{
	uint16_t temp;
	uint16_t i;

	if (gain == 0)
		return 0;

	temp = FLK_GAIN_MAX / gain;

	for (i = 0; temp > 1; i++)
		temp /= FLK_GAIN_DEFAULT_RATION;

	return i;
}

static uint16_t trans_flk_gain_index_to_value(uint16_t index)
{
	uint16_t temp = 1;
	uint16_t i;

	for (i = 0; i < index; i++)
		temp *= FLK_GAIN_DEFAULT_RATION;

	return FLK_GAIN_MAX / temp;
}

// flk_it expand 100
static uint16_t trans_flk_it_value_to_index(uint16_t it)
{
	uint16_t it_index = 0;

	if (it <= FLK_IT_TIME_INDEX0_VALUE)
		it_index = FLK_IT_INDEX_ZERO;
	else if (it <= FLK_IT_TIME_INDEX1_VALUE)
		it_index = FLK_IT_INDEX_ONE;
	else if (it <= FLK_IT_TIME_INDEX2_VALUE)
		it_index = FLK_IT_INDEX_TWO;
	else if (it <= FLK_IT_TIME_INDEX3_VALUE)
		it_index = FLK_IT_INDEX_THREE;
	else if (it <= FLK_IT_TIME_INDEX4_VALUE)
		it_index = FLK_IT_INDEX_FOUR;
	else if (it <= FLK_IT_TIME_INDEX5_VALUE)
		it_index = FLK_IT_INDEX_FIVE;
	else if (it <= FLK_IT_TIME_INDEX6_VALUE)
		it_index = FLK_IT_INDEX_SIX;

	return it_index;
}

// flk_it expand 100
static uint16_t trans_flk_it_index_to_value(uint16_t index)
{
	uint16_t temp = 1;
	uint16_t i;

	for (i = 0; i < index; i++)
		temp *= FLK_IT_RATION;

	temp *= FLK_IT_MIN;

	return temp;
}

static void sy3132cs_get_als_gain(const struct sy3132cs_ctx *ctx, uint16_t *als_gain)
{
	int index;

	index = sy3132cs_get_ic_func(ctx->handle, sy3132cs_ic_func.ALS_GAIN);
	if (index < 0)
		return;

	sy3132cs_algo.als_gain_index = index;
	*als_gain = trans_gain_index_to_value(sy3132cs_algo.als_gain_index);
}

static void sy3132cs_set_als_gain(const struct sy3132cs_ctx *ctx, uint16_t als_gain)
{
	sy3132cs_algo.als_gain_index = trans_gain_value_to_index(als_gain);
	sy3132cs_set_ic_func(ctx->handle, sy3132cs_ic_func.ALS_GAIN, sy3132cs_algo.als_gain_index);
}

static void sy3132cs_ic_time_div(const struct sy3132cs_ctx *ctx, uint8_t div)
{
	uint8_t data;
	const uint8_t bits = 4;

	color_sensor_set_byte(ctx->handle, SY3133CS_REG_TEST_KEY, TEST_KEY_VALUE);

	if (div == FREQ_DIV2)
		sy3132cs_algo.ic_time_div = FREQ_DIV2_REG_VALUE;
	else if (div == FREQ_DIV4)
		sy3132cs_algo.ic_time_div = FREQ_DIV4_REG_VALUE;
	else if (div == FREQ_DIV8)
		sy3132cs_algo.ic_time_div = FREQ_DIV8_REG_VALUE;
	else
		sy3132cs_algo.ic_time_div = FREQ_DIV1_REG_VALUE;

	data = (sy3132cs_algo.ic_time_div << bits) | CONFIG_NO_DUMMY_VALUE;
	color_sensor_set_byte(ctx->handle, SY3133CS_REG_TEST_F2, data);
}

static void sy3132cs_set_flk_gain(const struct sy3132cs_ctx *ctx, uint16_t flk_gain)
{
	sy3132cs_algo.flk_gain_index = trans_flk_gain_value_to_index(flk_gain);
	sy3132cs_set_ic_func(ctx->handle, sy3132cs_ic_func.FLK_GAIN, sy3132cs_algo.flk_gain_index);
}

static void sy3132cs_get_flk_gain(const struct sy3132cs_ctx *ctx, uint16_t *flk_gain)
{
	int index;

	index = sy3132cs_get_ic_func(ctx->handle, sy3132cs_ic_func.FLK_GAIN);
	if (index < 0)
		return;

	sy3132cs_algo.flk_gain_index = index;
	*flk_gain = trans_flk_gain_index_to_value(sy3132cs_algo.flk_gain_index);
}

static void sy3132cs_get_flk_it(const struct sy3132cs_ctx *ctx, uint16_t *flk_it)
{
	int index;

	index = sy3132cs_get_ic_func(ctx->handle, sy3132cs_ic_func.FLK_IT);
	if (index < 0)
		return;
	sy3132cs_algo.flk_it_index = index;

	index += sy3132cs_algo.ic_time_div;
	if (index > FLK_IT_INDEX_SIX)
		index = FLK_IT_INDEX_SIX;

	*flk_it = trans_flk_it_index_to_value(index);
}

static void sy3132cs_set_flk_it(const struct sy3132cs_ctx *ctx, uint16_t flk_it)
{
	uint8_t index;

	index = trans_flk_it_value_to_index(flk_it);
	index -= sy3132cs_algo.ic_time_div;
	if (index >= 0) {
		sy3132cs_set_ic_func(ctx->handle, sy3132cs_ic_func.FLK_IT, index);
		sy3132cs_algo.flk_it_index = index;
	}
}

static void sy3132cs_get_als_it(const struct sy3132cs_ctx *ctx, uint16_t *als_it)
{
	int index;

	index = sy3132cs_get_ic_func(ctx->handle, sy3132cs_ic_func.ALS_IT);
	if (index < 0)
		return;

	sy3132cs_algo.als_it_index = index;
	index += sy3132cs_algo.ic_time_div;
	if (index > IT_INDEX_EIGHT)
		index = IT_INDEX_EIGHT;

	*als_it = trans_it_index_to_value(index);
}

static int sy3132cs_get_gainlist(void)
{
	return sy3132cs_algo.gcl_index;
}

static void sy3132cs_set_als_it(const struct sy3132cs_ctx *ctx, uint16_t als_it)
{
	int index;

	index = trans_it_value_to_index(als_it);

	sy3132cs_get_flk_it(ctx, &sy3132cs_algo.flk_it);

	if (sy3132cs_get_gainlist() > 1) {
		if (sy3132cs_algo.ic_time_div > 0) {
			sy3132cs_ic_time_div(ctx, FREQ_DIV1);
			sy3132cs_set_flk_it(ctx, sy3132cs_algo.flk_it);
		}
	} else {
		if (sy3132cs_algo.ic_time_div == 0) {
			sy3132cs_ic_time_div(ctx, FREQ_DIV4);
			sy3132cs_set_flk_it(ctx, sy3132cs_algo.flk_it);
		}
	}

	index -= sy3132cs_algo.ic_time_div;
	if (index > 0) {
		sy3132cs_set_ic_func(ctx->handle, sy3132cs_ic_func.ALS_IT, index);
		sy3132cs_algo.als_it_index = index;
	}
	color_sensor_set_byte(ctx->handle, SY3133CS_COMMAND_REST_ADC, 0x00);
	color_sensor_set_byte(ctx->handle, SY3133CS_COMMAND_REST_ADC, 0x00);
}

static int sy3132cs_rgb_report_type(void)
{
	return AWB_SENSOR_RAW_SEQ_TYPE_SY3121CS;
}

static int sy3132cs_report_data(const int value[])
{
	struct custom_sensor_data_t rgb_data;

	rgb_data.sensor_data_head.sensor_type = SENSOR_TYPE_RGB;
	rgb_data.sensor_data_head.action = STD_SENSOR_DATA_REPORT;
	memcpy_s(&rgb_data.sensor_data[0], RGB_REPORT_DATA_LEN * sizeof(int),
		value, RGB_REPORT_DATA_LEN * sizeof(int));
	return ap_sensor_route_write((char*)&rgb_data,
		sizeof(struct custom_sensor_data_t));
}

static enum sy3132cs_sensor_id_t sy3132cs_get_chipid(const struct i2c_client *handle)
{
	UINT8 chipid = 0;

	if (!handle) {
		hwlog_err("%s: Pointer is NULL\n", __func__);
		return UNKNOWN_DEVICE;
	}
	color_sensor_get_byte(handle, SY3132CS_REG_CHIP_ID, &chipid);

	if (chipid == SY3132CS_CHIP_VALUE) {
		hwlog_info("%s: Chip is sy3132cs, id = 0x%x\n", __func__, chipid);
		sensor_type = SY3132CS_REV0;
	} else {
		hwlog_info("%s: Chip is unkonwn\n", __func__);
		return UNKNOWN_DEVICE;
	}

	return sensor_type;
}

static INT32 sy3132cs_als_get_gain(const void *ctx)
{
	INT32 gain;
	uint16_t temp_gain;

	if (!ctx) {
		hwlog_err("%s: Pointer is NULL\n", __func__);
		return -EFAULT;
	}
	sy3132cs_get_als_gain(ctx, &temp_gain);
	gain = (INT32)temp_gain;

	hwlog_info("now the gain val = %d\n", gain);
	return gain;
}

static INT32 sy3132cs_als_set_gain(void *ctx, int gain_id)
{
	struct sy3132cs_ctx *ctx_t = NULL;

	if (!ctx) {
		hwlog_err("%s: Pointer is NULL\n", __func__);
		return -1;
	}
	if (gain_id > SY3231CS_GAIN_FACTOR) {
		hwlog_err("%s: gain_id out of range: %u\n", __func__, gain_id);
		return -1;
	}
	ctx_t = (struct sy3132cs_ctx *)ctx;
	sy3132cs_set_ic_func(ctx_t->handle, sy3132cs_ic_func.ALS_GAIN, (uint8_t)gain_id);
	hwlog_info("%s gain = %d, gain_id = %u\n",
		__func__, sy3132cs_algo.als_gain, gain_id);

	return 0;
}

void sy3132cs_buff_input_new_data(uint16_t *data_buff, uint16_t new_data, int data_num)
{
	int i;

	for (i = data_num - 1; i > 0; i--)
		data_buff[i] = data_buff[i - 1];

	data_buff[0] = new_data;
}

uint32_t sy3132cs_calcu_data_avg(uint16_t *data_buff, int avg_num)
{
	uint32_t temp = 0;
	int i;

	for (i = 0; i < avg_num; i++)
		temp += data_buff[i];

	return temp / avg_num;
}

void sy3132cs_buff_reset(uint16_t *data_buff, uint16_t new_data, int avg_num)
{
	int i;

	for (i = 0; i < avg_num; i++)
		data_buff[i] = new_data;
}

void sy3132cs_check_buff_reset(uint16_t *data_buff, uint16_t new_data, int avg_num)
{
	uint16_t gap = abs((int)new_data - data_buff[0]);
	uint8_t coef = SY3132CS_ALGO_AVG_REST_PERCENT;
	uint8_t offset = SY3132CS_ALGO_AVG_REST_COUNT;
	int i;
	int avg_data = sy3132cs_calcu_data_avg(data_buff, avg_num);

	if (new_data < CHECK_BUFF_RESET_LOW_VALUE) {
		if (avg_data > CHECK_BUFF_RESET_LOW_VALUE) {
			for (i = 0; i < avg_num; i++)
				data_buff[i] = new_data;
		} else {
			return;
		}
	} else if ((new_data < CHECK_BUFF_RESET_MIDDLE_VALUE) &&
			(data_buff[0] < CHECK_BUFF_RESET_MIDDLE_VALUE)) {
		coef = 10; // updata
		offset = 10; // update
	}
	if (gap > (data_buff[0] / DATA_EXPAND_100 * coef + offset)) {
		for (i = 0; i < avg_num; i++)
			data_buff[i] = new_data;
	}
}

static bool sy3132cs_flk_auto_gain(uint16_t *gain, uint16_t *it)
{
	uint16_t data_low_limit; // low_limit
	uint16_t current_gain = sy3132cs_algo.flk_gain;
	uint16_t data_high_limit;
	uint32_t temp_flk = sy3132cs_algo.avg_flk_data;
	uint16_t half = 2;
	bool check = false;

	if (sy3132cs_algo.ic_time_div != 0) {
		data_low_limit = FLK_MIX_DATA;
		data_high_limit = FLK_AUTO_GAIN_DATA * sy3132cs_algo.flk_it / DATA_EXPAND_100;
	} else {
		data_low_limit = FLK_MAX_DATA;
		data_high_limit = 4 * FLK_AUTO_GAIN_DATA * sy3132cs_algo.flk_it / DATA_EXPAND_100;
	}

	if (data_high_limit > FLK_AUTO_GAIN_HIGH_LIMIT_DATA)
		data_high_limit = FLK_AUTO_GAIN_HIGH_LIMIT_DATA;

	if (sy3132cs_algo.avg_flk_data > data_high_limit) {
		while (temp_flk > data_low_limit * half) {
			if (current_gain > FLK_GAIN_1) {
				*gain = current_gain / FLK_GAIN_RATION1;
				current_gain = current_gain / FLK_GAIN_RATION1;
				temp_flk /= half;
				*it = FLK_IT_TIME_INDEX2_VALUE;
				check = true;
			} else {
				return false;
			}
		}
	}
	if (sy3132cs_algo.avg_flk_data < data_low_limit) {
		while (temp_flk < data_high_limit / half) {
			if (current_gain < FLK_GAIN_64) {
				*gain = current_gain * FLK_GAIN_RATION1;
				current_gain = current_gain * FLK_GAIN_RATION1;
				*it = FLK_IT_TIME_INDEX2_VALUE;
				temp_flk *= half;
				check = true;
			} else {
				return false;
			}
		}
	}
	*it = FLK_IT_TIME_INDEX2_VALUE;
	return check;
}

int pow_cal(int x, int y) // x to the power of y
{
	int result = 1;
	int i;

	for (i = 0; i < y; i++)
		result *= x;

	return result;
}

int talor_log(int x, int precision)
{
	int count = 1;
	int total_value = 0;
	int even = 2;
	int i;

	for (i = 0; x > even; i++)
		x = x / DATA_EXPAND_10;

	while (count <= precision) {
		total_value += pow_cal((-1), (count + 1)) *
			(pow_cal((x - 1), count) / count);
		count++;
	}
	total_value += i * LN10 / DATA_EXPAND_10000;
	return total_value;
}

static int32_t sy3132cs_ln_fix_proc(int32_t data)
{
	int64_t temp_log;
	int64_t factor;
	int32_t temp_data;

	if (data > 0) {
		temp_log = talor_log(data, TALOR_JI_SHU);
		factor = temp_log * nature_log_coef +
			nature_log_offset;
		temp_data = data * factor / DATA_EXPAND_10000;
	} else {
		temp_data = 0;
	}
	return temp_data;
}

static void sy3132cs_read_fifo_data_30_bytes(const struct sy3132cs_ctx *ctx,
				uint8_t *data_buff, uint8_t len)
{
	int ret;
	uint8_t test_byte;
	int j;

	ret = color_sensor_read_fifo(ctx->handle, SY3132CS_REG_FIFO_R_CNT_CLR, data_buff, len);
	if (ret < 0) {
		hwlog_info("%s: i2c--2 failed\n", __func__);
		return;
	}
	color_sensor_get_byte(ctx->handle, SY3132CS_REG_FIFO_DATAH, &test_byte);

	for (j = 1; j < len; j++)
		data_buff[j - 1] = data_buff[j];

	data_buff[j - 1] = test_byte;
}

static void sy3132cs_calcu_flk_fifo_data(const struct sy3132cs_ctx *ctx)
{
	uint8_t raw_data[SY3132_FIFO_RAW_DATA_NUM] = { 0 };
	uint8_t fifo_level = 0;
	int i, k;
	int ret;
	const int double_byte = 2;
	uint8_t count;
	uint8_t data_buff[I2C_MAX_BUFF] = { 0 };
	uint32_t ration;

	sy3132cs_get_flk_gain(ctx, &sy3132cs_algo.flk_gain);
	sy3132cs_get_flk_it(ctx, &sy3132cs_algo.flk_it);
	ration = SY3132CS_FLK_GAIN_ST / sy3132cs_algo.flk_gain * SY3132CS_FLK_IT_ST *
			DATA_EXPAND_100 / sy3132cs_algo.flk_it;

	ret = color_sensor_get_byte(ctx->handle, SY3132CS_REG_FIFO_LV_CNT, &fifo_level);
	if (ret < 0) {
		hwlog_err("%s: i2c transfer failed\n", __func__);
		return;
	}
	if (fifo_level != 0) {
		count = (fifo_level * double_byte) % I2C_MAX_BUFF;
		hwlog_info("%s: start fifo_level = %d, fifo_count = %d\n",
			__func__, fifo_level, sy3132cs_algo.fifo_counter);

		for (i = 0; i < (fifo_level * double_byte / I2C_MAX_BUFF); i++) {
			sy3132cs_read_fifo_data_30_bytes(ctx, data_buff, I2C_MAX_BUFF);

			for (k = 0; k < I2C_MAX_BUFF; k++)
				raw_data[k + i * I2C_MAX_BUFF] = data_buff[k];
			memset_s(data_buff, I2C_MAX_BUFF, 0, I2C_MAX_BUFF);
		}
		if (count != 0) {
			sy3132cs_read_fifo_data_30_bytes(ctx, data_buff, count);
			for (k = 0; k < count; k++)
				raw_data[k + i * I2C_MAX_BUFF] = data_buff[k];
		}
		if (!first_fifo_full) {
			if ((sy3132cs_algo.fifo_counter +
				fifo_level * double_byte) <=
				SY3132_FIFO_RAW_DATA_NUM) {
				for (i = 0; i < fifo_level; i++) {
					sy3132cs_algo.flk_fifo_data[sy3132cs_algo.fifo_counter / double_byte + i] =
						((uint16_t)raw_data[i * double_byte + 1] << BITS8) +
						raw_data[i * double_byte];
					sy3132cs_algo.nor_flk_fifo_data[sy3132cs_algo.fifo_counter / double_byte + i] =
						sy3132cs_algo.flk_fifo_data[sy3132cs_algo.fifo_counter / double_byte + i] * ration;
				}

				sy3132cs_algo.fifo_counter += fifo_level * double_byte;
			} else {
				ring_count = sy3132cs_algo.fifo_counter +
					fifo_level * double_byte -
					SY3132_FIFO_RAW_DATA_NUM;

				for (i = 0; i < (SY3132_FIFO_BYTE_DATA_NUM - (ring_count / double_byte)); i++) {
					sy3132cs_algo.flk_fifo_data[i] =
						sy3132cs_algo.flk_fifo_data[ring_count / double_byte + i];
					sy3132cs_algo.nor_flk_fifo_data[i] =
						sy3132cs_algo.nor_flk_fifo_data[ring_count / double_byte + i];
				}

				for (i = 0; i < (ring_count / double_byte); i++) {
					sy3132cs_algo.flk_fifo_data[SY3132_FIFO_BYTE_DATA_NUM -
						(ring_count / double_byte) + i] =
						((uint16_t)raw_data[i * double_byte + 1] << BITS8) +
						raw_data[i * double_byte];
					sy3132cs_algo.nor_flk_fifo_data[SY3132_FIFO_BYTE_DATA_NUM -
						(ring_count / double_byte) + i] =
						sy3132cs_algo.flk_fifo_data[SY3132_FIFO_BYTE_DATA_NUM -
						(ring_count / double_byte) + i] *ration;
				}

				first_fifo_full = true;
				sy3132cs_algo.fifo_counter = SY3132_FIFO_RAW_DATA_NUM;
			}
		} else {
			for (i = 0; i < SY3132_FIFO_BYTE_DATA_NUM - fifo_level; i++) {
				sy3132cs_algo.flk_fifo_data[i] =
					sy3132cs_algo.flk_fifo_data[fifo_level + i];
				sy3132cs_algo.nor_flk_fifo_data[i] =
					sy3132cs_algo.nor_flk_fifo_data[fifo_level + i];
			}

			for (i = 0; i < fifo_level; i++) {
				sy3132cs_algo.flk_fifo_data[SY3132_FIFO_BYTE_DATA_NUM - fifo_level + i] =
					((uint16_t)raw_data[i * double_byte + 1] << BITS8) +
					raw_data[i * double_byte];
				sy3132cs_algo.nor_flk_fifo_data[SY3132_FIFO_BYTE_DATA_NUM - fifo_level + i] =
						sy3132cs_algo.flk_fifo_data[SY3132_FIFO_BYTE_DATA_NUM - fifo_level + i] *ration;
			}

			sy3132cs_algo.fifo_counter = SY3132_FIFO_RAW_DATA_NUM;
			hwlog_info("%s: update fifo_level = %d, fifocount = %d\n", __func__,
				fifo_level, sy3132cs_algo.fifo_counter);
		}
	}
}

static int sy3132cs_flk_data_check(struct sy3132cs_ctx *ctx)
{
	uint16_t flk_gain;
	uint16_t flk_it;
	int i;
	uint16_t len;
	uint16_t counter;
	int start_index;
	uint32_t data_temp = 0;
	const int double_byte = 2;
	uint16_t data0_count;

	sy3132cs_get_flk_gain(ctx, &sy3132cs_algo.flk_gain);
	sy3132cs_get_flk_it(ctx, &sy3132cs_algo.flk_it);

	if (sy3132cs_algo.flk_delay_counter) {
		sy3132cs_algo.flk_delay_counter--;
	} else {
		if (fd_timer_stopped)
			sy3132cs_calcu_flk_fifo_data(ctx);

		sy3132cs_algo.avg_flk_data = 0;
		counter = sy3132cs_algo.als_it / sy3132cs_algo.flk_it;
		if (counter > SY3132_FIFO_BYTE_DATA_NUM)
			counter = SY3132_FIFO_BYTE_DATA_NUM;

		len = sy3132cs_algo.fifo_counter / double_byte;
		if (len < counter) {
			data0_count = 0;
			for (i = 0; i < len; i++) {
				data_temp += sy3132cs_algo.flk_fifo_data[i];

				if (sy3132cs_algo.startup_count_flag) {
					if (sy3132cs_algo.flk_fifo_data[i] == 0)
						data0_count++;
				}
			}
			if ((len - data0_count) != 0) {
				data_temp = data_temp / (len - data0_count);
				sy3132cs_algo.avg_flk_data = data_temp;
			}
		} else {
			if (sy3132cs_algo.fifo_counter % double_byte == 0) {
				start_index = len - counter;
				data0_count = 0;
				for (i = 0; i < counter; i++) {
					data_temp += sy3132cs_algo.flk_fifo_data[start_index + i];
					if (sy3132cs_algo.startup_count_flag) {
						if (sy3132cs_algo.flk_fifo_data[start_index + i] == 0)
							data0_count++;
					}
				}
				if ((counter - data0_count) != 0) {
					data_temp = data_temp / (counter - data0_count);
					sy3132cs_algo.avg_flk_data = data_temp;
				}
			}
		}

		sy3132cs_algo.clear_by_fifo = sy3132cs_algo.avg_flk_data *
			SY3132CS_ALS_IT_ST / sy3132cs_algo.flk_gain;

		if (als_valid_flag) {
			if (sy3132cs_flk_auto_gain(&flk_gain, &flk_it) == true) {
				sy3132cs_algo.flk_delay_counter = 0;
				sy3132cs_set_flk_gain(ctx, flk_gain);
				sy3132cs_set_flk_it(ctx, flk_it);
				sy3132cs_algo.flk_gain = flk_gain;
				sy3132cs_algo.flk_it = flk_it;
				return 1;
			}
		}
	}
	return 1;
}

static int auto_gain_check(const uint16_t *data, uint16_t *gain, uint16_t *it)
{
	int i;
	int check = 0;
	uint16_t max_data = data[0];
	uint16_t min_data = data[0];
	uint8_t temp_index = sy3132cs_algo.gcl_index;
	const uint8_t half = 2;

	if (sy3132cs_algo.gain_delay_counter)
		sy3132cs_algo.gain_delay_counter--;

	if (sy3132cs_algo.gain_delay_counter)
		return 0;

	if (sy3132cs_algo.auto_gain_enable == false)
		return 0;

	for (i = 0; i < (SY3132CS_CHANNEL_NUMBER - 1); i++) {
		if (data[i] > max_data)
			max_data = data[i];
		if (data[i] < min_data)
			min_data = data[i];
		if (data[i] > SY3132CS_ALGO_DE_HIGH_LIMIT)
			check++;
	}
	if (check > 0) {
		while ((sy3132cs_algo.gcl_index < (MAX_GCL_NUM - 1)) &&
			((min_data / half) > (SY3132CS_ALGO_DE_LOW_LIMIT * half))) {
			min_data /= half;
			sy3132cs_algo.gcl_index++;
			*gain = sy3132_gcl[sy3132cs_algo.gcl_index].gain;
			*it = sy3132_gcl[sy3132cs_algo.gcl_index].it;
			hwlog_info("%s: --1--gain = %d, %d, %d,%d\n", __func__,
				*gain, *it, sy3132cs_algo.gcl_index, sy3132cs_algo.gain_delay_counter);
		}
		if (temp_index != sy3132cs_algo.gcl_index) {
			sy3132cs_algo.gain_delay_counter = *it / ALS_POLLING_TIME / DATA_EXPAND_100 + 1;
			hwlog_info("%s: --2--gain = %d, %d, %d,%d\n", __func__,
				*gain, *it, sy3132cs_algo.gcl_index, sy3132cs_algo.gain_delay_counter);
			return 1;
		} else {
			if (sy3132cs_algo.gcl_index < (MAX_GCL_NUM - 1)) {
				sy3132cs_algo.gcl_index++;
				*gain = sy3132_gcl[sy3132cs_algo.gcl_index].gain;
				*it = sy3132_gcl[sy3132cs_algo.gcl_index].it;
				sy3132cs_algo.gain_delay_counter = *it / ALS_POLLING_TIME / DATA_EXPAND_100 + 1;
				hwlog_info("%s: --3--gain = %d, %d, %d,%d\n", __func__,
				*gain, *it, sy3132cs_algo.gcl_index, sy3132cs_algo.gain_delay_counter);
				return 1;
			} else {
				return 0;
			}
		}
	}
	// check low
	check = 0;
	max_data = data[0];
	min_data = data[0];
	for (i = 0; i < (SY3132CS_CHANNEL_NUMBER - 1); i++) {
		if (data[i] > max_data)
			max_data = data[i];
		if (data[i] < min_data)
			min_data = data[i];
		if (data[i] < SY3132CS_ALGO_DE_LOW_LIMIT)
			check++;
	}
	if (check > 0) {
		while ((sy3132cs_algo.gcl_index > 0) &&
			((max_data * half) < SY3132CS_ALGO_DE_HIGH_LIMIT)) {
			max_data *= half;
			sy3132cs_algo.gcl_index--;
			*gain = sy3132_gcl[sy3132cs_algo.gcl_index].gain;
			*it = sy3132_gcl[sy3132cs_algo.gcl_index].it;
			hwlog_info("%s: --4--gain = %d, %d, %d,%d\n", __func__,
				*gain, *it, sy3132cs_algo.gcl_index, sy3132cs_algo.gain_delay_counter);
		}
		if (temp_index != sy3132cs_algo.gcl_index) {
			sy3132cs_algo.gain_delay_counter = *it / ALS_POLLING_TIME / DATA_EXPAND_100 + 1;
			hwlog_info("%s: --5--gain = %d, %d, %d,%d\n", __func__,
				*gain, *it, sy3132cs_algo.gcl_index, sy3132cs_algo.gain_delay_counter);
			return 1;
		} else {
			return 0;
		}
	}
	return 0;
}

uint16_t  sy3132cs_calcu_low_lux_data(uint16_t *data_buff, uint16_t new_data)
{
	const uint8_t half = 2;
	int gap = abs((int)new_data - data_buff[0]);
	if ((gap % LOW_LUX_REG_VALUE == 0) && (gap < CHECK_BUFF_RESET_LOW_VALUE) && (gap != 0))
		return (data_buff[1] + data_buff[0]) / half;
	else
		return new_data;
}

void sy3132cs_set_dummy_config(const struct sy3132cs_ctx *ctx)
{
	uint8_t data;

	color_sensor_set_byte(ctx->handle, SY3133CS_REG_TEST_KEY, TEST_KEY_VALUE);
	color_sensor_get_byte(ctx->handle, SY3133CS_REG_TEST_F2, &data);

	data &= 0x3f;
	data |= 0x40; // ic default no reduce dummy
	color_sensor_set_byte(ctx->handle, SY3133CS_REG_TEST_F2, data);
}

void sy3132cs_init_reg_config(const struct sy3132cs_ctx *ctx)
{
	uint8_t data = 0;

	color_sensor_set_byte(ctx->handle, SY3133CS_REG_TEST_KEY, TEST_KEY_VALUE);
	color_sensor_get_byte(ctx->handle, SY3133CS_REG_TEST_F3, &data);
	data &= 0xf3;
	data |= 0x04; // ic vref power
	color_sensor_set_byte(ctx->handle, SY3133CS_REG_TEST_F3, data);

	/* set filter en */
	sy3132cs_set_ic_func(ctx->handle, sy3132cs_ic_func.FILTER_EN, ENABLE_FILTER_EN);
	/* set FILTER_n 2 */
	sy3132cs_set_ic_func(ctx->handle, sy3132cs_ic_func.FILTER_n, ALS_FILTER_N);
	/* set FILTER_m1 0 */
	sy3132cs_set_ic_func(ctx->handle, sy3132cs_ic_func.FILTER_m1, ALS_FILTER_M1);
	/* set FILTER_m2 3 */
	sy3132cs_set_ic_func(ctx->handle, sy3132cs_ic_func.FILTER_m2, ALS_FILTER_M2);
	/* set flk it */
	sy3132cs_algo.flk_it = SY3132CS_FLK_IT_ST * DATA_EXPAND_100; // it expand 100
	sy3132cs_set_flk_it(ctx, sy3132cs_algo.flk_it);
	/* set flk gain */
	sy3132cs_algo.flk_gain = SY3132CS_FLK_GAIN_ST;
	sy3132cs_set_flk_gain(ctx, sy3132cs_algo.flk_gain);
	/* set als it */
	sy3132cs_algo.als_it = ENABLE_ALS_IT_VALUE * DATA_EXPAND_100; // it expand 100
	sy3132cs_algo.als_gain = SY3132CS_ALS_GAIN_ST;
	sy3132cs_algo.gcl_index = INI_GCL_INDEX;
	/* set als gain */
	sy3132cs_set_als_it(ctx, sy3132cs_algo.als_it);
	sy3132cs_set_als_gain(ctx, sy3132cs_algo.als_gain);

	sy3132cs_set_ic_func(ctx->handle, sy3132cs_ic_func.FLK_OVERWR_EN, 0);
	sy3132cs_set_ic_func(ctx->handle, sy3132cs_ic_func.MODE1_IT, 0);
	sy3132cs_set_ic_func(ctx->handle, sy3132cs_ic_func.ADC1_EN, 1);
	sy3132cs_set_dummy_config(ctx);

	sy3132cs_set_ic_func(ctx->handle, sy3132cs_ic_func.MODE1_CYC, 0);
	sy3132cs_set_ic_func(ctx->handle, sy3132cs_ic_func.MODE2_CYC, 0);
}

static void sy3132cs_print_reg(const struct sy3132cs_ctx *ctx)
{
	uint8_t reg_value[SY3132_CONFIG_REG_NUM] = { 0 };
	uint8_t reg_map[] = {
		SY3132CS_REG_CHIP_ID,
		SY3132CS_REG_ALS_CON1,
		SY3132CS_REG_ALS_CON2,
		SY3132CS_REG_ALS_CON3,
		SY3132CS_REG_ALS_CON4,
		SY3132CS_REG_ALS_CON5,
		SY3132CS_REG_ALS_CON6,
		SY3132CS_REG_AINT_CON,
		SY3132CS_REG_FINT_CON,
		SY3132CS_REG_SYN_CON,
		SY3132CS_REG_DRV_CON1,
		SY3132CS_REG_ALS_LTL,
		SY3132CS_REG_ALS_LTH,
		SY3132CS_REG_ALS_HTL,
		SY3132CS_REG_ALS_HTH,
		SY3132CS_REG_ALS_FIFO_TH
	};
	uint8_t i;
	uint16_t n = sizeof(reg_map) / sizeof(reg_map[0]);
	for (i = 0; i < n; i++) {
		color_sensor_get_byte(ctx->handle, reg_map[i], &reg_value[i]);
		hwlog_info("%s: reg[0x%X] = 0x%X\n", __func__, i, reg_value[i]);
	}
}

void sy3132cs_set_als_mode(const struct sy3132cs_ctx *ctx, uint8_t mode)
{
	uint8_t reg_value[REG_VALUE_LEN] = { 0 }; // 0x01-0x0F
	int ret;

	ret = color_sensor_read_fifo(ctx->handle,
		SY3132CS_REG_ALS_CON1, reg_value, REG_VALUE_LEN);
	if (ret < 0)
		return;

	ret = color_sensor_set_byte(ctx->handle,
		SY3133CS_REG_TEST_KEY, TEST_KEY_VALUE);
	if (ret < 0)
		return;

	ret = color_sensor_set_byte(ctx->handle,
		SY3133CS_COMMAND_REST_ADC, TEST_KEY_VALUE);
	if (ret < 0)
		return;

	ret = color_sensor_write_fifo(ctx->handle,
		SY3132CS_REG_ALS_CON1, reg_value, REG_VALUE_LEN);
	if (ret < 0)
		return;

	sy3132cs_set_ic_func(ctx->handle, sy3132cs_ic_func.ALS_MODE, mode);
}

static UINT8 get_rgb_enable_status(const struct i2c_client *handle)
{
	UINT8 enable_sta = 0;

	if (!handle) {
		hwlog_err("%s: Pointer is NULL\n", __func__);
		return -EFAULT;
	}
	color_sensor_get_byte(handle, SY3132CS_REG_ALS_CON1, &enable_sta);
	return enable_sta;
}

void sy3132cs_als_timer_wrk(struct timer_list *data)
{
	struct color_chip *chip = from_timer(chip, data, work_timer);

	if (!chip) {
		hwlog_err("%s: Pointer is NULL\n", __func__);
		return;
	}
	queue_work(system_power_efficient_wq, &chip->als_work);
}

void sy3132cs_flc_timer_wrk(struct timer_list *data)
{
	struct color_chip *chip = from_timer(chip, data, fd_timer);

	if (!chip) {
		hwlog_err("%s: Pointer is NULL\n", __func__);
		return;
	}
	queue_work(system_power_efficient_wq, &chip->fd_work);
}

/***********kalman filter algo  start************/
void kalman_para_reset(int32_t pxs_data, uint8_t index)
{
	pxs_kalman_algo[index].para_q = 1; // 0.01
	pxs_kalman_algo[index].para_r = 100; // 100
	pxs_kalman_algo[index].para_a = 1;
	pxs_kalman_algo[index].para_x_k = pxs_data;
	pxs_kalman_algo[index].para_p_k = 0; // 100
	pxs_kalman_algo[index].para_kg = 0; // 100
	pxs_kalman_algo[index].para_z_k = 0;
	pxs_kalman_algo[index].para_p = 100; // 1
	pxs_kalman_algo[index].para_x = pxs_data;
}

void kalman_filter_algo(int32_t pxs_data, uint8_t index)
{
	int32_t temp = (pxs_data * pxs_kalman_algo[index].switch_para_persent +
		pxs_kalman_algo[index].switch_para_offset) / DATA_EXPAND_100;

	if (abs((int)pxs_kalman_algo[index].ex_data - (int)pxs_data) > temp)
		kalman_para_reset(pxs_data, index);

	pxs_kalman_algo[index].ex_data = pxs_data;
	pxs_kalman_algo[index].para_x_k = pxs_kalman_algo[index].para_a * pxs_kalman_algo[index].para_x;

	pxs_kalman_algo[index].para_z_k = pxs_data;
	pxs_kalman_algo[index].para_p_k = (pxs_kalman_algo[index].para_a * pxs_kalman_algo[index].para_p *
		pxs_kalman_algo[index].para_a + pxs_kalman_algo[index].para_q) * DATA_EXPAND_100 / DATA_EXPAND_100;

	pxs_kalman_algo[index].para_kg = pxs_kalman_algo[index].para_p_k * DATA_EXPAND_100 /
		(pxs_kalman_algo[index].para_p_k + pxs_kalman_algo[index].para_r * DATA_EXPAND_100);
	pxs_kalman_algo[index].para_p = (DATA_EXPAND_100 - pxs_kalman_algo[index].para_kg) *
		pxs_kalman_algo[index].para_p_k * DATA_EXPAND_100 / DATA_EXPAND_100 / DATA_EXPAND_100;

	pxs_kalman_algo[index].para_x = pxs_kalman_algo[index].para_x_k + pxs_kalman_algo[index].para_kg *
		(pxs_kalman_algo[index].para_z_k - (1 * pxs_kalman_algo[index].para_x_k)) / DATA_EXPAND_100;

	pxs_kalman_algo[index].cal_data = pxs_kalman_algo[index].para_x;
}

uint16_t kalman_filter_get_cal_data(uint8_t index)
{
	return pxs_kalman_algo[index].cal_data;
}

void kalman_filter_set_swtich_para(int32_t percent, int32_t offset, uint8_t index)
{
	pxs_kalman_algo[index].switch_para_persent = percent; // expand 100
	pxs_kalman_algo[index].switch_para_offset = offset;
}

void kalman_filter_set_para(int32_t steady_para, int32_t follow_para, uint8_t index)
{
	pxs_kalman_algo[index].para_steady_q = steady_para; // expand 100
	pxs_kalman_algo[index].para_flow_q = follow_para;
}

void sy3132cs_signal_fix_ratio_proc(void)
{
	int i;

	for (i = 0; i < SY3132CS_CHANNEL_NUMBER; i++) {
		if (sy3132cs_algo.kalman_filter_enable[i] == true) {
			if (sy3132cs_algo.avg_data[i] < KALMAN_JUDGE_DATA_LEVEL1)
				// 0.5, 0 expand 100
				kalman_filter_set_swtich_para(KAL_PARA_RATION1, 0, i);
			else if (sy3132cs_algo.avg_data[i] < KALMAN_JUDGE_DATA_LEVEL2)
				// 0.3, 0 expand 100
				kalman_filter_set_swtich_para(KAL_PARA_RATION2, 0, i);
			else if (sy3132cs_algo.avg_data[i] < KALMAN_JUDGE_DATA_LEVEL3)
				// 0.1, 0 expand 100
				kalman_filter_set_swtich_para(KAL_PARA_RATION3, 0, i);
			else if (sy3132cs_algo.avg_data[i] < KALMAN_JUDGE_DATA_LEVEL4)
				// 0.05, 10  expand 100
				kalman_filter_set_swtich_para(KAL_PARA_RATION4, KAL_PARA_RATION7, i);
			else if (sy3132cs_algo.avg_data[i] < KALMAN_JUDGE_DATA_LEVEL5)
				// 0.02, 10  expand 100
				kalman_filter_set_swtich_para(KAL_PARA_RATION5, KAL_PARA_RATION7, i);
			else
				// 0.01, 10 expand 100
				kalman_filter_set_swtich_para(KAL_PARA_RATION6, KAL_PARA_RATION7, i);

			kalman_filter_algo(sy3132cs_algo.avg_data[i], i);
			sy3132cs_algo.avg_data[i] = pxs_kalman_algo[i].cal_data;
		}
	}
}

void sy3132cs_data_normalize_proc(void)
{
	int i;

	for (i = 0; i < (SY3132CS_CHANNEL_NUMBER + 1); i++)
		sy3132cs_algo.normalize_data[i] =
			sy3132cs_algo.avg_data[i] *
			sy3132cs_algo.als_trans_gain *
			sy3132cs_algo.als_trans_it / DATA_EXPAND_100;
}

/*********** kalman filter algo  end ***********/
static void sy3132cs_get_fifo_data(struct color_chip *chip, char *flk_data)
{
	int i;

	if (!chip || !flk_data) {
		hwlog_err("%s: Pointer is NULL\n", __func__);
		return;
	}
	memcpy_s(flk_data, sizeof(sy3132cs_algo.nor_flk_fifo_data),
		sy3132cs_algo.nor_flk_fifo_data,
		sizeof(sy3132cs_algo.nor_flk_fifo_data));
	for (i = 0; i < SY3132_FIFO_BYTE_DATA_NUM; i++)
		hwlog_info("%s:  %d,  %d \n", __func__, i,
			sy3132cs_algo.nor_flk_fifo_data[i]);
}

static void sy3132cs_read_fifo_data(struct color_chip *chip)
{
	if (!chip) {
		hwlog_err("%s: Pointer is NULL\n", __func__);
		return;
	}
	if (fd_timer_stopped == false) {
		mod_timer(&chip->fd_timer,
			jiffies + msecs_to_jiffies(FLK_POLLING_TIME));
	} else {
		hwlog_info("fd has been disabled, del fd work timer\n");
		return;
	}
	mutex_lock(&read_fifo_lock);
	sy3132cs_calcu_flk_fifo_data((struct sy3132cs_ctx *)chip->device_ctx);
	mutex_unlock(&read_fifo_lock);
}

void sy3132cs_startup_data_calcu(uint16_t *data, int dummya_data, int dummyc_data)
{
	const int fix_ratio[SY3132CS_CHANNEL_NUMBER] = { 100, 50, 50, 25, 25, 25, 25, 0 };
	int i, temp;
	uint8_t index = SY3132CS_CHANNEL_NUMBER - 1;

	for (i = 0; i < index; i++) {
		temp = dummya_data * fix_ratio[i] / DATA_EXPAND_100;
		if (data[i] > temp)
			data[i] -= temp;
	}
	temp = dummyc_data * fix_ratio[index] / DATA_EXPAND_100;
	if (data[index] > temp)
		data[index] -= temp;
}

/*----------------normal operation start--------------------------------------------*/
void sy3132cs_normal_low_lux_fix_proc(uint16_t *raw_data, const int len)
{
	int i;
	uint16_t temp_data;

	if (len <= 0)
		return;

	for (i = 0; i < SY3132CS_CHANNEL_NUMBER; i++) {
		temp_data = sy3132cs_algo.ch_raw_data[i];
		if (temp_data < RAW_DATA_LOW_LIMIT)
			raw_data[i] =
				sy3132cs_calcu_low_lux_data(&sy3132cs_algo.raw_data_buff[i][0],
				temp_data);
		else
			raw_data[i] = temp_data;

		sy3132cs_buff_input_new_data(&sy3132cs_algo.raw_data_buff[i][0],
			temp_data, RAW_DB_NUM);
	}
}

void sy3132cs_algo_normal_operation(struct sy3132cs_ctx *ctx)
{
	int i;
	uint16_t raw_data[ALL_CHANNEL_NUM] = { 0 };

	sy3132cs_normal_low_lux_fix_proc(raw_data, ALL_CHANNEL_NUM);
	sy3132cs_flk_data_check(ctx);

	raw_data[CH8_VALUE] = sy3132cs_algo.ch_raw_data[CH8_VALUE]; // nir
	raw_data[CH9_VALUE] = sy3132cs_algo.avg_flk_data; // clear
	for (i = 0; i < ALL_CHANNEL_NUM; i++) {
		sy3132cs_check_buff_reset(&sy3132cs_algo.data_buff[i][0],
			raw_data[i], ACTIVE_DB_NUM);
		sy3132cs_buff_input_new_data(&sy3132cs_algo.data_buff[i][0],
			raw_data[i], ACTIVE_DB_NUM);
		sy3132cs_algo.avg_data[i] =
			sy3132cs_calcu_data_avg(&sy3132cs_algo.data_buff[i][0],
			ACTIVE_DB_NUM);
	}
}

/*----------------normal operation end--------------------------------------------*/
void sy3132cs_startup_low_lux_fix_proc(uint16_t *raw_data, const int len)
{
	const uint8_t dummya_index = 10;
	const uint8_t dummyc_index = 11;
	uint16_t *raw_da = &raw_data[dummya_index];
	uint16_t *raw_dc = &raw_data[dummyc_index];
	uint32_t temp_data;
	int i;
	uint32_t normal_ratio = 1;

	if (len <= 0)
		return;

	// low_lux_fix
	for (i = 0; i < SY3132CS_CHANNEL_NUMBER; i++) {
		temp_data = sy3132cs_algo.ch_raw_data[i];
		if (temp_data < RAW_DATA_LOW_LIMIT)
			raw_data[i] = sy3132cs_calcu_low_lux_data(&sy3132cs_algo.raw_data_buff[i][0], temp_data);
		else
			raw_data[i] = temp_data;

		sy3132cs_buff_input_new_data(&sy3132cs_algo.raw_data_buff[i][0], temp_data, RAW_DB_NUM);
	}
	temp_data = sy3132cs_algo.raw_dummya_data;
	if (temp_data < RAW_DATA_LOW_LIMIT)
		*raw_da = sy3132cs_calcu_low_lux_data(&sy3132cs_algo.raw_dummy_buff[0][0], temp_data);
	else
		*raw_da = temp_data;

	sy3132cs_buff_input_new_data(&sy3132cs_algo.raw_dummy_buff[0][0], temp_data, RAW_DB_NUM);
	sy3132cs_check_buff_reset(&sy3132cs_algo.dummy_buff[0][0], *raw_da * normal_ratio, DUMMY_DB_NUM);
	sy3132cs_buff_input_new_data(&sy3132cs_algo.dummy_buff[0][0], *raw_da * normal_ratio, DUMMY_DB_NUM);

	temp_data = sy3132cs_algo.raw_dummyc_data;
	if (temp_data < RAW_DATA_LOW_LIMIT)
		*raw_dc = sy3132cs_calcu_low_lux_data(&sy3132cs_algo.raw_dummy_buff[1][0], temp_data);
	else
		*raw_dc = temp_data;

	sy3132cs_buff_input_new_data(&sy3132cs_algo.raw_dummy_buff[1][0], temp_data, RAW_DB_NUM);
	sy3132cs_check_buff_reset(&sy3132cs_algo.dummy_buff[1][0], *raw_dc * normal_ratio, DUMMY_DB_NUM);
	sy3132cs_buff_input_new_data(&sy3132cs_algo.dummy_buff[1][0], *raw_dc * normal_ratio, DUMMY_DB_NUM);
}

void sy3132cs_set_als_mode2(const struct sy3132cs_ctx *ctx)
{
	sy3132cs_set_als_mode(ctx, ALS_MODE2_ON);
	sy3132cs_algo.algo_main_status = ALGO_STATUS_NORMAL;
}

void sy3132cs_ic_startup_process(struct sy3132cs_ctx *ctx)
{
	uint16_t raw_data[RAW_DB_LEN] = { 0 };
	int i;
	int j;

	if (sy3132cs_algo.first_time_get_data == true) {
		for (i = 0; i < SY3132CS_CHANNEL_NUMBER; i++) {
			for (j = 0; j < ACTIVE_DB_NUM; j++)
				sy3132cs_algo.data_buff[i][j] = sy3132cs_algo.ch_raw_data[i];
		}

		for (i = 0; i < DUMMY_DB_NUM; i++)
			sy3132cs_algo.dummy_buff[0][i] = sy3132cs_algo.raw_dummya_data;

		for (i = 0; i < DUMMY_DB_NUM; i++)
			sy3132cs_algo.dummy_buff[1][i] = sy3132cs_algo.raw_dummyc_data;

		for (i = 0; i < SY3132CS_CHANNEL_NUMBER; i++) {
			for (j = 0; j < RAW_DB_NUM; j++)
				sy3132cs_algo.raw_data_buff[i][j] = sy3132cs_algo.ch_raw_data[i];
		}

		for (i = 0; i < RAW_DB_NUM; i++)
			sy3132cs_algo.raw_dummy_buff[0][i] = sy3132cs_algo.raw_dummya_data;

		for (i = 0; i < RAW_DB_NUM; i++)
			sy3132cs_algo.raw_dummy_buff[1][i] = sy3132cs_algo.raw_dummyc_data;

		sy3132cs_algo.dummy_max = sy3132cs_algo.raw_dummya_data; // dummpya
	}
	sy3132cs_startup_low_lux_fix_proc(raw_data, RAW_DB_LEN);
	sy3132cs_algo.dummya_avg =
		sy3132cs_calcu_data_avg(&sy3132cs_algo.dummy_buff[0][0],
		DUMMY_DB_NUM);
	sy3132cs_algo.dummyc_avg =
		sy3132cs_calcu_data_avg(&sy3132cs_algo.dummy_buff[1][0],
		DUMMY_DB_NUM);
	sy3132cs_startup_data_calcu(raw_data, sy3132cs_algo.dummya_avg, sy3132cs_algo.dummyc_avg);

	if (sy3132cs_algo.startup_count_flag)
		sy3132cs_algo.startup_count_timer++;

	sy3132cs_flk_data_check(ctx);
	if (sy3132cs_algo.first_time_get_data == true) {
		sy3132cs_algo.first_time_get_data = false;
		for (j = 0; j < ACTIVE_DB_NUM; j++) {
			sy3132cs_algo.data_buff[CH8_VALUE][j] = sy3132cs_algo.ch_raw_data[CH8_VALUE]; // nir
			sy3132cs_algo.data_buff[CH9_VALUE][j] = sy3132cs_algo.avg_flk_data; // clear
		}
	}
	raw_data[CH8_VALUE] = sy3132cs_algo.ch_raw_data[CH8_VALUE]; // nir
	raw_data[CH9_VALUE] = sy3132cs_algo.avg_flk_data; // clear

	for (i = 0; i < ALL_CHANNEL_NUM; i++) {
		sy3132cs_check_buff_reset(&sy3132cs_algo.data_buff[i][0],
			raw_data[i], ACTIVE_DB_NUM);
		sy3132cs_buff_input_new_data(&sy3132cs_algo.data_buff[i][0],
			raw_data[i], ACTIVE_DB_NUM);
		sy3132cs_algo.avg_data[i] =
			sy3132cs_calcu_data_avg(&sy3132cs_algo.data_buff[i][0],
			ACTIVE_DB_NUM);
	}
	if ((sy3132cs_algo.dummya_avg < DUMMYA_AVG_DATA_LIMIT && sy3132cs_algo.dummyc_avg > 0) ||
		sy3132cs_algo.startup_count_timer > MODE3_SWITCH_MODE2_TIME) { // 50 * 100 ms = 5s
		if (sy3132cs_algo.startup_count_flag) {
			hwlog_info("%s: set mode2, a_avg = %d, c_avg = %d\n", __func__,
				sy3132cs_algo.dummya_avg, sy3132cs_algo.dummyc_avg);
			sy3132cs_algo.startup_count_flag = false;
			sy3132cs_set_als_mode2(ctx);
		}
		return;
	}
}
/*---------------startup process end---------------------------------------------*/

void sy3132cs_read_channel_raw_data(const struct sy3132cs_ctx *ctx)
{
	uint8_t raw_data[RAW_DB_LEN] = { 0 };
	uint8_t i;
	uint8_t double_byte = 2;
	const uint8_t dummy_len = 4;

	// read ch1-ch7 data
	color_sensor_read_fifo(ctx->handle, SY3132CS_REG_CH1_DATAL, raw_data, RAW_DB_LEN);
	for (i = 0; i < (SY3132CS_CHANNEL_NUMBER - 1); i++) {
		sy3132cs_algo.ch_raw_data[i] =
			((uint16_t)raw_data[double_byte * i + 1] << BITS8) +
			raw_data[double_byte * i];
	}
	// read ch8
	sy3132cs_algo.ch_raw_data[CH7_VALUE] = ((uint16_t)raw_data[17] << BITS8) + raw_data[16];
	// read clear
	sy3132cs_algo.ch_raw_data[CH9_VALUE] = ((uint16_t)raw_data[15] << BITS8) + raw_data[14];
	// read nir
	sy3132cs_algo.ch_raw_data[CH8_VALUE] = ((uint16_t)raw_data[19] << BITS8) + raw_data[18];
	// read dummpy data
	color_sensor_read_fifo(ctx->handle, SY3132CS_REG_DummyA_DATAL, raw_data, dummy_len);
	sy3132cs_algo.raw_dummya_data = ((uint16_t)raw_data[1] << BITS8) + raw_data[0];
	sy3132cs_algo.raw_dummyc_data = ((uint16_t)raw_data[3] << BITS8) + raw_data[2];
}

int sy3132cs_get_gain_offset(void)
{
	uint8_t i;
	uint8_t j;

	for (j = 0; j < (GAIN_CALI_NUM - 1); j++) {
		for (i = 0; i < SY3132CS_CHANNEL_NUMBER; i++) {
			if (gain_ch_data[i][j] == 0)
				return -1;

			if ((j == 0) && (gain_ch_data[i][j + 1] == 0))
				return -1;

			hwlog_info("%s gain_ch_data : %d, %d ", __func__,
					gain_ch_data[i][j], gain_ch_data[i][j + 1]);
		}
	}
	// c1/c8
	gain_ch_ration[0][0] = gain_ch_data[0][0] * DATA_EXPAND_100 / gain_ch_data[0][1];
	gain_ch_ration[7][0] = gain_ch_data[7][0] * DATA_EXPAND_100 / gain_ch_data[7][1];
	hwlog_info("%s c1/c8 2048/64 gain cali result : %d, %d ", __func__,
				gain_ch_ration[0][0], gain_ch_ration[7][0]);

	// c2/c3
	gain_ch_data[1][0] = CH_MAX((gain_ch_data[1][0]), (gain_ch_data[2][0]));
	gain_ch_data[1][1] = CH_MAX((gain_ch_data[1][1]), (gain_ch_data[2][1]));
	gain_ch_ration[1][0] = gain_ch_data[1][0] * DATA_EXPAND_100 / gain_ch_data[1][1];
	gain_ch_ration[2][0] = gain_ch_ration[1][0];
	hwlog_info("%s c2/c3 2048/64 gain cali result : %d", __func__, gain_ch_ration[1][0]);
	// c4/c7
	gain_ch_data[3][0] = CH_MAX((gain_ch_data[3][0]), (gain_ch_data[6][0]));
	gain_ch_data[3][1] = CH_MAX((gain_ch_data[3][1]), (gain_ch_data[6][1]));
	gain_ch_ration[3][0] = gain_ch_data[3][0] * DATA_EXPAND_100 / gain_ch_data[3][1];
	gain_ch_ration[6][0] = gain_ch_ration[3][0];
	hwlog_info("%s c4/c7 2048/64 gain cali result : %d", __func__, gain_ch_ration[3][0]);
	// c6/c5
	gain_ch_data[4][0] = CH_MAX((gain_ch_data[4][0]), (gain_ch_data[5][0]));
	gain_ch_data[4][1] = CH_MAX((gain_ch_data[4][1]), (gain_ch_data[5][1]));
	gain_ch_ration[4][0] = gain_ch_data[4][0] * DATA_EXPAND_100 / gain_ch_data[4][1];
	gain_ch_ration[5][0] = gain_ch_ration[4][0];
	hwlog_info("%s c6/c5 2048/64 gain cali result : %d", __func__, gain_ch_ration[4][0]);

	return 0;
}

void get_switch_gain_data(struct sy3132cs_ctx *ctx, uint8_t count,
				uint16_t gain, uint16_t als_it, uint8_t index)
{
	int i;

	for (i = 0; i < SY3132CS_CHANNEL_NUMBER; i++)
		gain_ch_data[i][count] = sy3132cs_algo.ch_raw_data[i];

	sy3132cs_algo.als_gain = gain;
	sy3132cs_algo.gcl_index = als_it;
	sy3132cs_algo.gcl_index = index;
	sy3132cs_set_als_gain(ctx, sy3132cs_algo.als_gain);
	sy3132cs_set_als_it(ctx, sy3132cs_algo.als_it);
}

void switch_gain_by_light12_data(struct sy3132cs_ctx *ctx)
{
	int j;

	if (light12_flag)
		light12_time_count++;

	if (light12_time_count == 2) {
		get_switch_gain_data(ctx, 0, MONOCHRO_GAIN_VALUE, CALI_IT_VALUE, CALI_GCL_INDEX_MAX);
	} else if (light12_time_count == 6) {
		get_switch_gain_data(ctx, 1, CALI_GAIN_VALUE, CALI_IT_VALUE, CALI_GCL_INDEX);
		sy3132cs_get_gain_offset();
	} else if (light12_time_count > 6) {
		for (j = 0; j < SY3132CS_CHANNEL_NUMBER; j++)
			color_report_val[j + 1] = color_report_val[j + 1] + (gain_ch_ration[j][0] << SY3132_CONFIG_REG_NUM);
	}
	hwlog_info("%s light12_time_count, %d", __func__, light12_time_count);
}

void judge_is_light12(struct sy3132cs_ctx *ctx)
{
	int temp_ch2 = sy3132cs_algo.ch_raw_data[1] * DATA_EXPAND_100;

	if (light12_first) {
		// ch2/ch7
		if (sy3132cs_algo.ch_raw_data[1] >= LIGHT12_CH2_VALUE &&
			(temp_ch2 / sy3132cs_algo.ch_raw_data[CH6_VALUE]) < LIGHT12_RATION_MAX &&
			(temp_ch2 / sy3132cs_algo.ch_raw_data[CH6_VALUE]) > LIGHT12_RATION_MIN) {
				light12_flag = true;
				light12_first = false;
		}
	}
	if (light12_flag)
		switch_gain_by_light12_data(ctx);

	hwlog_info("%s ch2, %d, ch7, %d, flag, %d", __func__, sy3132cs_algo.ch_raw_data[1],
		sy3132cs_algo.ch_raw_data[CH6_VALUE], light12_flag);
}

void sy3132cs_cali_mode(struct sy3132cs_ctx *ctx)
{
	int i;

	counter_9302++;
	if (counter_9302 > FACTOR_9302_TEST_COUNT) {
		for (i = 0; i < (ALL_CHANNEL_NUM - 1); i++)
			color_report_val[i + 1] = sy3132cs_algo.avg_data[i] * sy3132cs_algo.als_trans_gain *
				sy3132cs_algo.als_trans_it / DATA_EXPAND_100;

		color_report_val[CH10_VALUE] = sy3132cs_algo.clear_by_fifo; // clear

		hwlog_info("%s before report data, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", __func__,
			color_report_val[0], color_report_val[1], color_report_val[2], color_report_val[3],
			color_report_val[4], color_report_val[5], color_report_val[6], color_report_val[7],
			color_report_val[8], color_report_val[9], color_report_val[10]);

		if (gain_cali_flag)
			judge_is_light12(ctx);
	} else {
		color_report_val[0] = RGB_REPORT_DATA_LEN;
		for (i = 0; i < ALL_CHANNEL_NUM; i++)
			color_report_val[i + 1] = -1;
	}
}

void sy3132cs_normal_mode(struct sy3132cs_ctx *ctx)
{
	int i;

	switch (sy3132cs_algo.algo_main_status) {
	case ALGO_STATUS_STRATUP:
		sy3132cs_ic_startup_process(ctx);
		break;
	case ALGO_STATUS_NORMAL:
		sy3132cs_algo_normal_operation(ctx);
		break;
	default:
		break;
	}
	sy3132cs_algo.avg_data[CH9_VALUE] = sy3132cs_algo.avg_data[CH9_VALUE] *
				SY3132CS_ALS_IT_ST / sy3132cs_algo.avg_flk_gain * GAIN_CALI_NUM; // clear
	if (cali_flag || monochro_flag) {
		sy3132cs_algo.avg_data[CH8_VALUE] = sy3132cs_algo.ch_raw_data[CH8_VALUE]; // nir
		sy3132cs_cali_mode(ctx);
	} else {
		sy3132cs_signal_fix_ratio_proc();
		sy3132cs_data_normalize_proc();
		if (als_valid_flag) {
			for (i = 0; i < SY3132CS_CHANNEL_NUMBER + 1; i++)
				color_report_val[i + 1] = sy3132cs_ln_fix_proc(sy3132cs_algo.normalize_data[i]);

			color_report_val[CH10_VALUE] = sy3132cs_ln_fix_proc(sy3132cs_algo.avg_data[CH9_VALUE]);
			if (sy3132cs_algo.als_gain == ALS_GAIN_MAX) {
				if ((color_report_val[CH9_VALUE] % 2) == 0)
					color_report_val[CH9_VALUE] += 1;
			} else {
				if ((color_report_val[CH9_VALUE] % 2) != 0)
					color_report_val[CH9_VALUE] += 1;
			}
		}
	}
}

void sy3132cs_data_algo_process(struct sy3132cs_ctx *ctx)
{
	int ret;
	uint8_t temp1 = 0;
	uint8_t temp2 = 0;

	color_sensor_get_byte(ctx->handle, SY3132CS_REG_INT_FLAG, &temp1);
	color_sensor_get_byte(ctx->handle, SY3132CS_REG_INT_FLAG, &temp2);
	if ((temp1 & CONFIG_NO_DUMMY_VALUE) == CONFIG_NO_DUMMY_VALUE ||
		(temp2 & CONFIG_NO_DUMMY_VALUE) == CONFIG_NO_DUMMY_VALUE)
		als_valid_flag = true;
	else
		als_valid_flag = false;

	sy3132cs_get_als_gain(ctx, &sy3132cs_algo.als_gain);
	sy3132cs_get_als_it(ctx, &sy3132cs_algo.als_it);
	sy3132cs_algo.als_trans_gain = SY3132CS_ALS_GAIN_ST  / sy3132cs_algo.als_gain;
	sy3132cs_algo.als_trans_it = SY3132CS_ALS_IT_ST *
		DATA_EXPAND_100 * DATA_EXPAND_100 / sy3132cs_algo.als_it;
	sy3132cs_algo.avg_flk_gain = sy3132cs_algo.flk_gain;

	sy3132cs_read_channel_raw_data(ctx);
	sy3132cs_normal_mode(ctx);
	color_report_val[0] = RGB_REPORT_DATA_LEN;
	sy3132cs_report_data(color_report_val + 1);

	hwlog_info("%s als_gain_index : %d, it_index : %d, cali_flag : %d,\
		monochro_flag : %d, gcl_index, %d, count, %d",
		__func__, sy3132cs_algo.als_gain_index,
		sy3132cs_algo.als_it_index, cali_flag, monochro_flag,
		sy3132cs_algo.gcl_index, sy3132cs_algo.gain_delay_counter);
	hwlog_info("%s, raw_data, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", __func__,
		als_valid_flag, sy3132cs_algo.als_gain, sy3132cs_algo.als_it, sy3132cs_algo.ic_time_div,
		sy3132cs_algo.ch_raw_data[0], sy3132cs_algo.ch_raw_data[1],
		sy3132cs_algo.ch_raw_data[2], sy3132cs_algo.ch_raw_data[3],
		sy3132cs_algo.ch_raw_data[4], sy3132cs_algo.ch_raw_data[5],
		sy3132cs_algo.ch_raw_data[6], sy3132cs_algo.ch_raw_data[7],
		sy3132cs_algo.ch_raw_data[8], sy3132cs_algo.avg_flk_data,
		sy3132cs_algo.raw_dummya_data, sy3132cs_algo.raw_dummyc_data);

	hwlog_info("%s flk_gain : %d, flk_gain_index : %d, flk_it : %d, flk_it_index : %d,\
		fd_timer_stopped : %d", __func__,
		sy3132cs_algo.flk_gain, sy3132cs_algo.flk_gain_index, sy3132cs_algo.flk_it,
		sy3132cs_algo.flk_it_index, fd_timer_stopped);
	hwlog_info("%s report data, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", __func__,
		color_report_val[0], color_report_val[1], color_report_val[2], color_report_val[3],
		color_report_val[4], color_report_val[5], color_report_val[6], color_report_val[7],
		color_report_val[8], color_report_val[9], color_report_val[10]);

	if (!cali_flag && !monochro_flag) {
		ret = auto_gain_check(sy3132cs_algo.ch_raw_data,
			&sy3132cs_algo.als_gain, &sy3132cs_algo.als_it);
		if (ret) {
			sy3132cs_set_als_gain(ctx, sy3132cs_algo.als_gain);
			sy3132cs_set_als_it(ctx, sy3132cs_algo.als_it);
		}
	}
}

static void sy3132cs_set_als_power_status(struct color_chip *chip, int en)
{
	if (sy3132cs_algo.als_en && (en == 1)) {
		hwlog_warn("%s, rgb already enabled, return\n", __func__);
		return;
	}
	if (!sy3132cs_algo.als_en && (en == 0)) {
		hwlog_warn("%s, rgb already disabled, no open, return\n", __func__);
		return;
	}
	sy3132cs_algo.als_en = en;
	if (en) {
		sy3132cs_set_ic_func(chip->client, sy3132cs_ic_func.ADC1_EN, 1);
		sy3132cs_set_ic_func(chip->client, sy3132cs_ic_func.ADC2_EN, 1);
		sy3132cs_set_ic_func(chip->client, sy3132cs_ic_func.ADC3_EN, 1);
		sy3132cs_set_ic_func(chip->client, sy3132cs_ic_func.ADC4_EN, 1);
		sy3132cs_set_ic_func(chip->client, sy3132cs_ic_func.ADC5_EN, 1);
		sy3132cs_set_ic_func(chip->client, sy3132cs_ic_func.FLK_EN, 1);
		sy3132cs_algo.als_gain = SY3132CS_ALS_GAIN_ST;
		sy3132cs_algo.als_it = ENABLE_ALS_IT_VALUE * DATA_EXPAND_100;
		sy3132cs_algo.gcl_index = INI_GCL_INDEX;
		cali_flag = 0;
		sy3132cs_set_als_gain((struct sy3132cs_ctx *)chip->device_ctx, sy3132cs_algo.als_gain);
		sy3132cs_set_als_it((struct sy3132cs_ctx *)chip->device_ctx, sy3132cs_algo.als_it);
		mod_timer(&chip->work_timer, jiffies + msecs_to_jiffies(ALS_POLLING_TIME));
		print_log_count = 0;
	} else {
		cali_flag = 0;
		sy3132cs_set_ic_func(chip->client, sy3132cs_ic_func.ADC2_EN, 0);
		sy3132cs_set_ic_func(chip->client, sy3132cs_ic_func.ADC3_EN, 0);
		sy3132cs_set_ic_func(chip->client, sy3132cs_ic_func.ADC4_EN, 0);
		sy3132cs_set_ic_func(chip->client, sy3132cs_ic_func.ADC5_EN, 0);
	}
}

int sy3132cs_enable_rgb(bool enable)
{
	struct color_chip *chip = p_chip;

	hwlog_info("%s: enter enable = %d\n", __func__, enable);

	if (!chip) {
		hwlog_err("%s: chip Pointer is NULL\n", __func__);
		return 0;
	}
	sy3132cs_set_als_power_status(chip, enable);
	return 1;
}
EXPORT_SYMBOL_GPL(sy3132cs_enable_rgb);

void sy3132cs_show_enable(struct color_chip *chip, int *state)
{
	UINT8 rgb_enable_status;

	if (!chip || !state) {
		hwlog_err("%s: Pointer is NULL\n", __func__);
		return;
	}
	rgb_enable_status = get_rgb_enable_status(chip->client);
	hwlog_info("%s: rgb_enable_status = %d\n", __func__, rgb_enable_status);
	if (rgb_enable_status & 0xF0) // ADC1_EN OPEN
		*state = 1;
	else
		*state = 0;
}

static void sy3132cs_cali_enable(struct color_chip *chip, int en)
{
	int i;
	int j;

	if (en == 1) {
		cali_flag = true; // cali_mode
		monochro_flag = false;
		sy3132cs_algo.als_gain = CALI_GAIN_VALUE;
		sy3132cs_algo.als_it = CALI_IT_VALUE;
		sy3132cs_algo.gcl_index = CALI_GCL_INDEX;
		sy3132cs_set_als_gain((struct sy3132cs_ctx *)chip->device_ctx, sy3132cs_algo.als_gain);
		sy3132cs_set_als_it((struct sy3132cs_ctx *)chip->device_ctx, sy3132cs_algo.als_it);
		if (!sy3132cs_algo.als_en && !monochro_flag) {
			sy3132cs_set_ic_func(chip->client, sy3132cs_ic_func.ADC1_EN, 1);
			sy3132cs_set_ic_func(chip->client, sy3132cs_ic_func.ADC2_EN, 1);
			sy3132cs_set_ic_func(chip->client, sy3132cs_ic_func.ADC3_EN, 1);
			sy3132cs_set_ic_func(chip->client, sy3132cs_ic_func.ADC4_EN, 1);
			sy3132cs_set_ic_func(chip->client, sy3132cs_ic_func.ADC5_EN, 1);
			sy3132cs_set_ic_func(chip->client, sy3132cs_ic_func.FLK_EN, 1);
			mod_timer(&chip->work_timer, jiffies + msecs_to_jiffies(ALS_POLLING_TIME + TIME_OFFSET));
			print_log_count = 0;
		}
		if (counter_9302 == 0) {
			color_report_val[0] = RGB_REPORT_DATA_LEN;
			for (i = 0; i < ALL_CHANNEL_NUM; i++)
				color_report_val[i + 1] = -1;
		}
	} else if (en == 2) {
		cali_flag = false;
		monochro_flag = true;
		sy3132cs_algo.als_gain = MONOCHRO_GAIN_VALUE;
		sy3132cs_algo.als_it = MONOCHRO_IT_VALUE;
		sy3132cs_algo.gcl_index = MONOCHRO_GCL_INDEX;
		sy3132cs_set_als_gain((struct sy3132cs_ctx *)chip->device_ctx, sy3132cs_algo.als_gain);
		sy3132cs_set_als_it((struct sy3132cs_ctx *)chip->device_ctx, sy3132cs_algo.als_it);
		if (!sy3132cs_algo.als_en && !cali_flag) {
			sy3132cs_set_ic_func(chip->client, sy3132cs_ic_func.ADC1_EN, 1);
			sy3132cs_set_ic_func(chip->client, sy3132cs_ic_func.ADC2_EN, 1);
			sy3132cs_set_ic_func(chip->client, sy3132cs_ic_func.ADC3_EN, 1);
			sy3132cs_set_ic_func(chip->client, sy3132cs_ic_func.ADC4_EN, 1);
			sy3132cs_set_ic_func(chip->client, sy3132cs_ic_func.ADC5_EN, 1);
			sy3132cs_set_ic_func(chip->client, sy3132cs_ic_func.FLK_EN, 1);
			mod_timer(&chip->work_timer, jiffies + msecs_to_jiffies(ALS_POLLING_TIME + TIME_OFFSET));
			print_log_count = 0;
		}
	} else {
		counter_9302 = 0;
		light12_time_count = 0;
		monochro_flag = false;
		light12_flag = false;
		light12_first = true;
		for (j = 0; j < GAIN_CALI_NUM; j++) {
			for (i = 0; i < SY3132CS_CHANNEL_NUMBER; i++) {
				gain_ch_data[i][j] = 0;
				if (j == 0)
					gain_ch_ration[i][j] = 0;
			}
		}
	}
}

void sy3132cs_store_enable(struct color_chip *chip, int state)
{
	hwlog_err("%s: enter, state : %d\n", __func__, state);

	if (!chip) {
		hwlog_err("%s: Pointer is NULL\n", __func__);
		return;
	}
	sy3132cs_cali_enable(chip, state);
}

static void sy3132cs_als_work(struct work_struct *work)
{
	struct color_chip *chip = NULL;
	struct sy3132cs_ctx *ctx = NULL;

	if (!work) {
		hwlog_err("%s: Pointer is NULL\n", __func__);
		return;
	}
	chip = container_of(work, struct color_chip, als_work);
	if (!chip || !chip->device_ctx) {
		hwlog_err("%s: Pointer chip is NULL\n", __func__);
		return;
	}
	ctx = (struct sy3132cs_ctx *)chip->device_ctx;

	if (sy3132cs_algo.als_en || cali_flag || monochro_flag) {
		sy3132cs_data_algo_process(ctx);
		mod_timer(&chip->work_timer, jiffies + msecs_to_jiffies(ALS_POLLING_TIME));
	} else {
		hwlog_warn("%s: rgb already disabled, no read data\n", __func__);
		return;
	}
}

static void sy3132cs_fd_work(struct work_struct *work)
{
	struct color_chip *chip = NULL;
	struct sy3132cs_ctx *ctx = NULL;

	if (!work) {
		hwlog_err("%s: Pointer work is NULL\n", __func__);
		return;
	}
	chip = container_of(work, struct color_chip, fd_work);
	if (!chip) {
		hwlog_err("%s: Pointer chip is NULL\n", __func__);
		return;
	}
	ctx = (struct sy3132cs_ctx *)chip->device_ctx;

	mutex_lock(&chip->lock);
	sy3132cs_read_fifo_data(chip);
	mutex_unlock(&chip->lock);
}

static void sy3132cs_algo_var_init()
{
	int i;

	sy3132cs_algo.auto_gain_enable = true;
	sy3132cs_algo.first_time_get_data = true;
	sy3132cs_algo.algo_main_status = ALGO_STATUS_STRATUP;
	for (i = 0; i < ALL_CHANNEL_NUM; i++)
		sy3132cs_algo.kalman_filter_enable[i] = true;

	sy3132cs_algo.startup_count_flag = true;
	sy3132cs_algo.startup_count_timer = 0;
	sy3132cs_algo.als_en = false;

	sy3132cs_algo.ic_time_div = 0;
	sy3132cs_algo.flk_delay_counter = 0;
	sy3132cs_algo.gain_delay_counter = 0;
	sy3132cs_algo.fifo_counter = 0;
	memset_s(sy3132cs_algo.flk_fifo_data,
		SY3132_FIFO_BYTE_DATA_NUM,
		0, SY3132_FIFO_BYTE_DATA_NUM);
	memset_s(sy3132cs_algo.nor_flk_fifo_data,
		SY3132_FIFO_BYTE_DATA_NUM,
		0, SY3132_FIFO_BYTE_DATA_NUM);
}

void sy3132cs_ic_algo_init(struct sy3132cs_ctx *ctx)
{
	sy3132cs_algo_var_init();
	// reg config
	sy3132cs_init_reg_config(ctx);
	// set als mode
	sy3132cs_set_als_mode(ctx, ALS_MODE1_AND_MODE2);

	sy3132cs_print_reg(ctx);
}

static char *sy3132cs_chip_name(void)
{
	if (sensor_type == SY3132CS_REV0)
		return "silergy_sy3132cs";
	else
		return "unknown device";
}

static char *sy3132cs_algo_type(void)
{
	if (sensor_type == SY3132CS_REV0)
		return "sy3132cs_nor";
	else
		return "unsupport";
}

void sy3132cs_flk_show_enable(struct color_chip *chip, int *state)
{
	UINT8 flk_enable_status;

	if (!chip || !state) {
		hwlog_err("%s: Pointer is NULL\n", __func__);
		return;
	}
	flk_enable_status = sy3132cs_get_ic_func(chip->client, sy3132cs_ic_func.FLK_EN);
	if (flk_enable_status < 0) {
		hwlog_err("%s: fail\n", __func__);
		return;
	}
	if (flk_enable_status == 1)
		*state = 1;
	else
		*state = 0;
}

void sy3132cs_flk_store_enable(struct color_chip *chip, int state)
{
	int flk_status;

	if (!chip) {
		hwlog_err("%s: Pointer is NULL\n", __func__);
		return;
	}
	if (state) {
		flk_status = sy3132cs_get_ic_func(chip->client,
			sy3132cs_ic_func.FLK_EN);
		if (flk_status < 0) {
			hwlog_err("%s: i2c fail\n", __func__);
			return;
		}

		mod_timer(&chip->fd_timer, jiffies + msecs_to_jiffies(FLK_POLLING_TIME));
		fd_timer_stopped = false;

		if (flk_status == 0) {
			hwlog_warn("%s, flk_enable not enabled\n", __func__);
			sy3132cs_set_ic_func(chip->client,
				sy3132cs_ic_func.FLK_EN, 1);
		} else {
			hwlog_warn("%s, flk_enable already enabled\n", __func__);
		}
	} else {
		fd_timer_stopped = true;
	}
	hwlog_info("%s enable = %d success\n", __func__, state);
}

static void configure_functions(struct color_chip *chip)
{
	chip->color_enable_show_state = sy3132cs_show_enable;
	chip->color_enable_store_state = sy3132cs_store_enable;
	chip->color_sensor_get_gain = sy3132cs_als_get_gain;
	chip->color_sensor_set_gain = sy3132cs_als_set_gain;
	chip->get_flicker_data = sy3132cs_get_fifo_data;
	chip->flicker_enable_show_state = sy3132cs_flk_show_enable;
	chip->flicker_enable_store_state = sy3132cs_flk_store_enable;
	chip->color_report_type = sy3132cs_rgb_report_type;
	chip->color_chip_name = sy3132cs_chip_name;
	chip->color_algo_type = sy3132cs_algo_type;

	color_default_enable = sy3132cs_enable_rgb;
}

static void sy3132cs_get_dts_parameter(const struct device *dev)
{
	int rc;

	rc = of_property_read_u32(dev->of_node,
		"flicker_support", &flicker_support);
	if (rc < 0) {
		hwlog_warn("%s, get flicker_support failed\n", __func__);
		flicker_support = 1; // default support flk
	}
	rc = of_property_read_u32(dev->of_node,
		"algo_support", &algo_support);
	if (rc < 0) {
		hwlog_warn("%s, get algo_support failed\n", __func__);
		algo_support = UNSUPPORT_ALGO; // default not support algo
	}
	hwlog_info("%s flicker_support = %u, algo_support = %u\n", __func__,
		flicker_support, algo_support);
}

static void init_library(struct color_chip *chip)
{
	int ret;

	timer_setup(&chip->work_timer, sy3132cs_als_timer_wrk, 0);
	INIT_WORK(&chip->als_work, sy3132cs_als_work);

	timer_setup(&chip->fd_timer, sy3132cs_flc_timer_wrk, 0);
	INIT_WORK(&chip->fd_work, sy3132cs_fd_work);

	configure_functions(chip);
	p_chip = chip;
	ret = color_register(chip);
	if (ret < 0)
		hwlog_err("%s color_register fail\n", __func__);

	hwlog_info("rgb sensor %s ok\n", __func__);
}

int sy3132cs_probe(struct i2c_client *client,
	const struct i2c_device_id *idp)
{
	int ret = -1;
	struct device *dev = NULL;
	static struct color_chip *chip = NULL;
	struct sy3132cs_ctx *ctx = NULL;

	hwlog_info("%s enter\n", __func__);

	if (!client)
		return -EFAULT;

	color_notify_support(); // declare support sy3132cs
	dev = &client->dev;
	if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
		goto init_failed;

	chip = kzalloc(sizeof(struct color_chip), GFP_KERNEL);
	if (!chip)
		goto malloc_failed;

	color_get_regulator(dev);

	mutex_init(&chip->lock);
	chip->client = client;
	chip->pdata = dev->platform_data;
	i2c_set_clientdata(chip->client, chip);
	chip->in_cal_mode = false;
	chip->cali_ctx.cal_state = 0;

	if (sy3132cs_get_chipid(chip->client) == UNKNOWN_DEVICE) {
		hwlog_info("%s failed: UNKNOWN_DEVICE\n", __func__);
		goto id_failed;
	}
	sy3132cs_get_dts_parameter(dev);
	chip->device_ctx = kzalloc(sizeof(struct sy3132cs_ctx), GFP_KERNEL);
	if (!chip->device_ctx)
		goto id_failed;

	ctx = chip->device_ctx;
	ctx->handle = chip->client;
	mutex_init(&read_fifo_lock);
	sy3132cs_ic_algo_init(ctx);
	init_library(chip);
	return 0;

id_failed:
	if (chip->device_ctx)
		kfree(chip->device_ctx);
	i2c_set_clientdata(client, NULL);
	hwlog_err("%s id_failed\n", __func__);
malloc_failed:
	if (chip)
		kfree(chip);
init_failed:
	hwlog_err("%s Probe failed\n", __func__);
	color_notify_absent();
	return ret;
}

int sy3132cs_suspend(struct device *dev)
{
	struct color_chip *chip = NULL;

	if (!dev) {
		hwlog_err("%s: Pointer is NULL\n", __func__);
		return -EFAULT;
	}
	chip = dev_get_drvdata(dev);
	if (!chip) {
		hwlog_err("%s: Pointer is NULL\n", __func__);
		return -EFAULT;
	}
	hwlog_info("%s\n", __func__);
	return 0;
}

int sy3132cs_resume(struct device *dev)
{
	struct color_chip *chip = NULL;

	if (!dev) {
		hwlog_err("%s: Pointer is NULL\n", __func__);
		return -EFAULT;
	}
	chip = dev_get_drvdata(dev);
	if (!chip) {
		hwlog_err("%s: Pointer is NULL\n", __func__);
		return -EFAULT;
	}
	hwlog_info("%s\n", __func__);
	return 0;
}

int sy3132cs_remove(struct i2c_client *client)
{
	struct color_chip *chip = NULL;

	if (!client) {
		hwlog_err("%s: Pointer is NULL\n", __func__);
		return -1;
	}
	chip = i2c_get_clientdata(client);
	if (!chip) {
		hwlog_err("%s: Pointer is NULL\n", __func__);
		return -1;
	}
	free_irq(client->irq, chip);
	i2c_set_clientdata(client, NULL);
	kfree(chip->device_ctx);
	kfree(chip);
	return 0;
}

static struct i2c_device_id sy3132cs_idtable[] = {
	{ "sy3132cs", 0 },
	{},
};
MODULE_DEVICE_TABLE(i2c, sy3132cs_idtable);

static const struct dev_pm_ops sy3132cs_pm_ops = {
	.suspend = sy3132cs_suspend,
	.resume = sy3132cs_resume,
};

static const struct of_device_id sy3132cs_driver_of_id_table[] = {
	{ .compatible = "silergy,sy3132cs" },
	{},
};

struct i2c_driver sy3132cs_driver = {
	.driver = {
		.name = "sy3132cs",
		.owner = THIS_MODULE,
		.of_match_table = sy3132cs_driver_of_id_table,
	},
	.id_table = sy3132cs_idtable,
	.probe = sy3132cs_probe,
	.remove = sy3132cs_remove,
};
EXPORT_SYMBOL(sy3132cs_driver);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("color_sensor driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
