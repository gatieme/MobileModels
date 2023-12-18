/*
 * sy3132cs.c
 *
 * code for sy3132cs rgb sensor
 *
 * Copyright (c) 2022 Huawei Technologies Co., Ltd.
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
#ifndef __SY3132CS_H__
#define __SY3132CS_H__
#include "color_sensor.h"

#define SY3132CS_SLAVE_ADDR                   0x46
#define SY3132CS_CHIP_VALUE                   0x32

/* sy3132cs registers address */
#define SY3132CS_REG_CHIP_ID                  0X00
#define SY3132CS_REG_ALS_CON1                 0x01
#define SY3132CS_REG_ALS_CON2                 0x02
#define SY3132CS_REG_ALS_CON3                 0x03
#define SY3132CS_REG_ALS_CON4                 0x04
#define SY3132CS_REG_ALS_CON5                 0x05
#define SY3132CS_REG_ALS_CON6                 0x06
#define SY3132CS_REG_AINT_CON                 0x07
#define SY3132CS_REG_FINT_CON                 0x08
#define SY3132CS_REG_SYN_CON                  0x09
#define SY3132CS_REG_DRV_CON1                 0x0A
#define SY3132CS_REG_ALS_LTL                  0x0B
#define SY3132CS_REG_ALS_LTH                  0x0C
#define SY3132CS_REG_ALS_HTL                  0x0D
#define SY3132CS_REG_ALS_HTH                  0x0E
#define SY3132CS_REG_ALS_FIFO_TH              0x0F
#define SY3132CS_REG_CH1_DATAL                0x10
#define SY3132CS_REG_CH1_DATAH                0x11
#define SY3132CS_REG_CH2_DATAL                0x12
#define SY3132CS_REG_CH2_DATAH                0x13
#define SY3132CS_REG_CH3_DATAL                0x14
#define SY3132CS_REG_CH3_DATAH                0x15
#define SY3132CS_REG_CH4_DATAL                0x16
#define SY3132CS_REG_CH4_DATAH                0x17
#define SY3132CS_REG_CH5_DATAL                0x18
#define SY3132CS_REG_CH5_DATAH                0x19
#define SY3132CS_REG_CH6_DATAL                0x1A
#define SY3132CS_REG_CH6_DATAH                0x1B
#define SY3132CS_REG_CH7_DATAL                0x1C
#define SY3132CS_REG_CH7_DATAH                0x1D
#define SY3132CS_REG_CH8_DATAL                0x1E
#define SY3132CS_REG_CH8_DATAH                0x1F
#define SY3132CS_REG_CLR_DATAL                0x20
#define SY3132CS_REG_CLR_DATAH                0x21
#define SY3132CS_REG_NIR_DATAL                0x22
#define SY3132CS_REG_NIR_DATAH                0x23
#define SY3132CS_REG_F1_DATAL                 0x24
#define SY3132CS_REG_F1_DATAH                 0x25
#define SY3132CS_REG_F2_DATAL                 0x26
#define SY3132CS_REG_F2_DATAH                 0x27
#define SY3132CS_REG_DummyA_DATAL             0x28
#define SY3132CS_REG_DummyA_DATAH             0x29
#define SY3132CS_REG_DummyC_DATAL             0x2A
#define SY3132CS_REG_DummyC_DATAH             0x2B
#define SY3132CS_REG_FLK_DATAL                0x2C
#define SY3132CS_REG_FLK_DATAH                0x2D
#define SY3132CS_REG_INT_BUF                  0x2E
#define SY3132CS_REG_INT_FLAG                 0x2F

#define SY3132CS_REG_FIFO_LV_CNT              0x30
#define SY3132CS_REG_FIFO_FLAG                0x31
#define SY3132CS_REG_FIFO_R_CNT_CLR           0x33
#define SY3132CS_REG_FIFO_DATAL               0x34
#define SY3132CS_REG_FIFO_DATAH               0x35
#define SY3132CS_REG_FIFO_R_CNT               0x36

#define SY3133CS_REG_TEST_KEY                 0x50
#define SY3133CS_REG_TEST_F1                  0x51
#define SY3133CS_REG_TEST_F2                  0x52
#define SY3133CS_REG_TEST_F3                  0x53

#define SY3133CS_COMMAND_CLEAR_FIFO           0x70
#define SY3133CS_COMMAND_CLEAR_INTER          0X74
#define SY3133CS_COMMAND_REST_ADC             0x7A
#define SY3133CS_COMMAND_SET_REG_DEFAULT      0x7D

#define ALS_IT_1560_US                        0x00
#define ALS_IT_3120_US                        0x01
#define ALS_IT_6250_US                        0x02
#define ALS_IT_12500_US                       0x03
#define ALS_IT_25_MS                          0x04
#define ALS_IT_50_MS                          0x05
#define ALS_IT_100_MS                         0x06
#define ALS_IT_200_MS                         0x07
#define ALS_IT_400_MS                         0x08

#define ALS_GAIN_2048                         0x00
#define ALS_GAIN_1024                         0x01
#define ALS_GAIN_512                          0x02
#define ALS_GAIN_256                          0x03
#define ALS_GAIN_128                          0x04
#define ALS_GAIN_64                           0x05
#define ALS_GAIN_32                           0x06
#define ALS_GAIN_16                           0x07
#define ALS_GAIN_8                            0x08
#define ALS_GAIN_4                            0x09
#define ALS_GAIN_2                            0xA0
#define ALS_GAIN_1                            0xB0

/* MODE1:integrates Dummy_A, Dummy_C, F1, F2 MODE2:integrates CH1~CH8, Clear */
#define ALS_MODE1_MODE2_OFF                   0x00
#define ALS_MODE1_ON                          0x01
#define ALS_MODE2_ON                          0x02
#define ALS_MODE1_AND_MODE2                   0x03

#define FLK_GAIN_64_INDEX                     0x00
#define FLK_GAIN_32_INDEX                     0x01
#define FLK_GAIN_16_INDEX                     0x02
#define FLK_GAIN_8_INDEX                      0x03
#define FLK_GAIN_4_INDEX                      0x04
#define FLK_GAIN_2_INDEX                      0x05
#define FLK_GAIN_1_INDEX                      0x07

#define FLK_GAIN_64                             64
#define FLK_GAIN_32                             32
#define FLK_GAIN_16                             16
#define FLK_GAIN_8                               8
#define FLK_GAIN_4                               4
#define FLK_GAIN_2                               2
#define FLK_GAIN_1                               1

#define SY3132CS_ALGO_DE_LOW_LIMIT             200
#define SY3132CS_ALGO_DE_HIGH_LIMIT          50000
#define SY3132CS_ALS_INT_LIMIT                 200
#define SY3132CS_ALS_GAIN_LIMIT               2048

#define SY3132CS_ALS_GAIN_ST                  2048
#define SY3132CS_ALS_IT_ST                      50
#define SY3132CS_FLK_GAIN_ST                    64
#define SY3132CS_FLK_IT_ST                       1

#define SY3132CS_CHANNEL_NUMBER                  8
#define SY3231CS_GAIN_FACTOR                    12
#define SY3132CS_ALGO_AVG_NUM_DEFAULT           10
#define SY3132CS_ALGO_AVG_REST_PERCENT           3
#define SY3132CS_ALGO_AVG_REST_COUNT             8

#define MAX_GCL_NUM                             10
#define INI_GCL_INDEX                            3

#define SY3132_FIFO_RAW_DATA_NUM               512
#define SY3132_FIFO_BYTE_DATA_NUM              256

#define FIFO_BUFF_NUM                            5

#define DATA_EXPAND_10                          10
#define DATA_EXPAND_100                        100
#define DATA_EXPAND_1000                      1000
#define DATA_EXPAND_10000                    10000

#define ALGO_STATUS_IDLE                         0
#define ALGO_STATUS_INIT                         1
#define ALGO_STATUS_STRATUP                      2
#define ALGO_STATUS_NORMAL                       3
#define ALGO_STATUS_AGC_GETTING                  4
#define ALGO_STATUS_DELAY                        5
#define ALGO_STATUS_DISABLE                      6

#define STANDARD_GAIN_INDEX                      1

#define RAW_DB_NUM                               3
#define RAW_DB_LEN                              20
#define ACTIVE_DB_NUM                           10
#define DUMMY_DB_NUM                             5
#define CAL_DB_NUM                              10

#define RGB_REPORT_DATA_LEN                     10
#define HIGH_TIMER_OFFSET                        5

#define TALOR_JI_SHU                            10
#define I2C_MAX_BUFF                            30
#define UNSUPPORT_ALGO                           0

#define ALS_POLLING_TIME                        49
#define FLK_POLLING_TIME                        50
#define TIME_OFFSET                              1

// it expand 100
#define IT_TIME_INDEX0_VALUE                   156
#define IT_TIME_INDEX1_VALUE                   312
#define IT_TIME_INDEX2_VALUE                   625
#define IT_TIME_INDEX3_VALUE                  1250
#define IT_TIME_INDEX4_VALUE                  2500
#define IT_TIME_INDEX5_VALUE                  5000
#define IT_TIME_INDEX6_VALUE                 10000
#define IT_TIME_INDEX7_VALUE                 20000
#define IT_TIME_INDEX8_VALUE                 40000
// it expand 100
#define FLK_IT_TIME_INDEX0_VALUE                25
#define FLK_IT_TIME_INDEX1_VALUE                50
#define FLK_IT_TIME_INDEX2_VALUE               100
#define FLK_IT_TIME_INDEX3_VALUE               200
#define FLK_IT_TIME_INDEX4_VALUE               400
#define FLK_IT_TIME_INDEX5_VALUE               800
#define FLK_IT_TIME_INDEX6_VALUE              1600

#define GAIN_MAX                              2048
#define GAIN_DEFAULT_RATION                      2
#define IT_TIME_DEFAULT_RATION                   2
#define FLK_GAIN_MAX                            64
#define FLK_GAIN_DEFAULT_RATION                  2
#define FLK_IT_MIN                              25
#define FLK_IT_RATION                            2

#define TEST_KEY_VALUE                        0x29
#define CONFIG_NO_DUMMY_VALUE                 0x40

#define FREQ_DIV1                                1
#define FREQ_DIV2                                2
#define FREQ_DIV4                                4
#define FREQ_DIV8                                8

#define CHECK_BUFF_RESET_LOW_VALUE             100
#define CHECK_BUFF_RESET_MIDDLE_VALUE          300

#define FLK_AUTO_GAIN_HIGH_LIMIT_DATA        50000
#define BITS8                                    8

#define FLK_AVG_DATA_LEN                        50
#define LOW_LUX_REG_VALUE                       16

#define ENABLE_FILTER_EN                         1
#define ALS_FILTER_N                             2
#define ALS_FILTER_M1                            0
#define ALS_FILTER_M2                            3
#define ALS_GAIN_MAX                            64

#define SY3132_CONFIG_REG_NUM                   16
#define ALL_CHANNEL_NUM                         10

#define KALMAN_JUDGE_DATA_LEVEL1                30
#define KALMAN_JUDGE_DATA_LEVEL2                50
#define KALMAN_JUDGE_DATA_LEVEL3               200
#define KALMAN_JUDGE_DATA_LEVEL4               500
#define KALMAN_JUDGE_DATA_LEVEL5              1000

// expend 100
#define KAL_PARA_RATION1                        50
#define KAL_PARA_RATION2                        30
#define KAL_PARA_RATION3                        10
#define KAL_PARA_RATION4                         5
#define KAL_PARA_RATION5                         2
#define KAL_PARA_RATION6                         1
#define KAL_PARA_RATION7                      1000

#define RAW_DATA_LOW_LIMIT                     500
// expend 100
#define DUMMYA_IT_TIME                        1250
#define MODE3_SWITCH_MODE2_TIME                100
#define DUMMYA_AVG_DATA_LIMIT                   20
#define PRINT_LOG_LIMIT                         10
#define LN10                                 23026

#define FLK_AUTO_GAIN_DATA                    1600
#define FLK_GAIN_RATION1                         2
#define FLK_GAIN_RATION2                         4

#define GAIN_CALI_NUM                            2
#define LIGHT12_RATION_MAX                     300 // 500
#define LIGHT12_RATION_MIN                     200 // 100
#define LIGHT12_CH2_VALUE                     7000

#define CALI_GAIN_VALUE                       2048
#define CALI_IT_VALUE                         5000  // 50ms，扩大100倍
#define CALI_GCL_INDEX                           2
#define CALI_GCL_INDEX_MAX                       7

#define MONOCHRO_GAIN_VALUE                     64
#define MONOCHRO_IT_VALUE                    10000 // 100ms，扩大100倍
#define MONOCHRO_GCL_INDEX                       6
#define STARTUP_DUMMYA_VALUE                  1300
#define FACTOR_9302_TEST_COUNT                   2
#define CH6_VALUE                                6
#define CH7_VALUE                                7
#define CH8_VALUE                                8
#define CH9_VALUE                                9
#define CH10_VALUE                              10
#define ENABLE_ALS_IT_VALUE                     25
#define FLK_MAX_DATA                           800
#define FLK_MIX_DATA                           200

#define REG_VALUE_LEN                            8

/* SY3132CS function define */
typedef struct ic_function_information {
	uint8_t reg;
	uint8_t offset;
	uint8_t bit_len;
} IC_FUNC_INFO;

typedef struct sy3132cs_ic_function {
	IC_FUNC_INFO ADC1_EN;
	IC_FUNC_INFO ADC2_EN;
	IC_FUNC_INFO ADC3_EN;
	IC_FUNC_INFO ADC4_EN;
	IC_FUNC_INFO ADC5_EN;
	IC_FUNC_INFO ALS_IT;
	IC_FUNC_INFO ALS_GAIN;
	IC_FUNC_INFO ALS_MODE;
	IC_FUNC_INFO MODE1_IT;
	IC_FUNC_INFO MODE1_CYC;
	IC_FUNC_INFO MODE2_CYC;
	IC_FUNC_INFO FILTER_EN;
	IC_FUNC_INFO FILTER_n;
	IC_FUNC_INFO FILTER_m1;
	IC_FUNC_INFO FILTER_m2;
	IC_FUNC_INFO FLK_EN;
	IC_FUNC_INFO FLK_IT;
	IC_FUNC_INFO FLK_GAIN;
	IC_FUNC_INFO AINT_EN;
	IC_FUNC_INFO AINT_SOURCE;
	IC_FUNC_INFO AINT_PRST;
	IC_FUNC_INFO FLV_EN;
	IC_FUNC_INFO FLK_OVERWR_EN;
	IC_FUNC_INFO FIFO_CAL_EN;
	IC_FUNC_INFO FLK_INT_EN;
	IC_FUNC_INFO FLK_TYPE;
	IC_FUNC_INFO FLK_PRST;
	IC_FUNC_INFO SYNC_MODE;
	IC_FUNC_INFO SYNC_DELAY;
	IC_FUNC_INFO DRV_EN;
	IC_FUNC_INFO DRV_CUR;
} SY3132CS_IC_FUNC_T;

typedef struct pxs_kalman_algo_t {
	int32_t para_steady_q;
	int32_t para_flow_q;
	int32_t para_q;
	int32_t para_r;
	int32_t para_a;
	int32_t para_x_k;
	int32_t para_p_k;
	int32_t para_kg;
	int32_t para_z_k;
	int32_t para_p;
	int32_t para_x;
	int32_t switch_para_persent;
	int32_t switch_para_offset;
	int32_t cal_data;
	int32_t ex_data;
} pxs_kalman_algo_t;

typedef struct sy3132cs_algo_t {
	bool kalman_filter_enable[10];
	bool auto_gain_enable;
	bool cal_finish;

	uint64_t delay_time;
	uint64_t timer;
	uint32_t als_trans_it;
	uint32_t als_trans_gain;
	uint32_t avg_flk_data;
	uint32_t normalize_data[10];
	int32_t  gain_fixed_fator[12][10];
	int32_t  avg_data[ALL_CHANNEL_NUM];
	uint32_t flk_fifo_data[SY3132_FIFO_BYTE_DATA_NUM];
	uint16_t als_gain;
	uint16_t als_gain_index;
	uint16_t als_it;
	uint16_t als_it_index;
	uint16_t flk_gain;
	uint16_t flk_gain_index;
	uint16_t flk_it;
	uint16_t flk_it_index;
	uint16_t fifo_counter;
	uint16_t dummy_max;
	uint16_t dummyc_avg;
	uint16_t dummya_avg;
	uint16_t raw_dummyc_data;
	uint16_t raw_dummya_data;
	uint16_t startup_count_flag;
	uint16_t startup_count_timer;
	uint16_t ch_raw_data[10]; // ch1-ch8, clear, nir
	uint16_t dummy_buff[2][DUMMY_DB_NUM];
	uint16_t raw_dummy_buff[2][RAW_DB_NUM];
	uint16_t data_buff[ALL_CHANNEL_NUM][20];
	uint16_t raw_data_buff[SY3132CS_CHANNEL_NUMBER][RAW_DB_NUM];
	uint8_t ex_als_gain_index;
	uint8_t ex_als_it_index;
	uint8_t delay_count;
	uint8_t flk_delay_counter;
	uint8_t ic_time_div;
	uint8_t freq_divide;
	uint8_t algo_main_status;
	uint8_t algo_return_status;
	uint8_t gain_delay_counter;
	uint8_t agc_ex_config[8];
	int gcl_index;
	int cal_avg_data[10];
	int32_t clear_by_fifo;
	bool fifo_full;
	bool first_data;
	bool first_time_get_data;
	bool als_en;
	uint16_t raw_data_pro[SY3132CS_CHANNEL_NUMBER];
	uint16_t avg_flk_gain;
	uint32_t nor_flk_fifo_data[SY3132_FIFO_BYTE_DATA_NUM];
} sy3132cs_algo_t;

typedef struct sy3132_gain_change_list {
	uint16_t gain;
	uint16_t it; // 扩大100
} sy3132_gcl_t;

enum sy3132cs_sensor_id_t {
	UNKNOWN_DEVICE,
	SY3132CS_REV0
};

enum sy3132cs_it_index {
	IT_INDEX_ZERO = 0,
	IT_INDEX_ONE,
	IT_INDEX_TWO,
	IT_INDEX_THREE,
	IT_INDEX_FOUR,
	IT_INDEX_FIVE,
	IT_INDEX_SIX,
	IT_INDEX_SEVEN,
	IT_INDEX_EIGHT
};

enum sy3132cs_flk_it_index {
	FLK_IT_INDEX_ZERO = 0,
	FLK_IT_INDEX_ONE,
	FLK_IT_INDEX_TWO,
	FLK_IT_INDEX_THREE,
	FLK_IT_INDEX_FOUR,
	FLK_IT_INDEX_FIVE,
	FLK_IT_INDEX_SIX
};

enum sy3132cs_freq_div_value {
	FREQ_DIV1_REG_VALUE = 0,
	FREQ_DIV2_REG_VALUE,
	FREQ_DIV4_REG_VALUE,
	FREQ_DIV8_REG_VALUE
};

struct sy3132cs_ctx {
	enum sy3132cs_sensor_id_t device_id;
	struct i2c_client *handle;
};

void sy3132cs_agc_seting(const struct sy3132cs_ctx *ctx);
void sy3132cs_exit_agc(const struct sy3132cs_ctx *ctx);

#endif // __SY3132CS_AS7341_H__
