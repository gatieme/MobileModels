/*
 * lcd_factory.c
 *
 * lcd factory test function for lcd driver
 *
 * Copyright (c) 2021-2022 Honor Technologies Co., Ltd.
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
#ifndef LCD_FACTORY_H
#define LCD_FACTORY_H

#define LCD_CMD_NAME_MAX 100
#define MAX_REG_READ_COUNT 4

/* pcd errflag detect */
#define PCD_ERRFLAG_SUCCESS	0
#define PCD_FAIL		1
#define LCD_KIT_PCD_SIZE	3
#define DMD_ERR_INFO_LEN	50

#define HOR_LINE_TEST_TIMES	3
#define MILLISEC_TIME	1000
#define LCD_ESD_ENABLE	0
#define LCD_ESD_DISABLE	1
#define LCD_RST_DOWN_TIME	300

/* ddic low voltage detect test */
#define DET_START 1
#define DET1_INDEX 0
#define DETECT_NUM 4
#define DETECT_LOOPS 6
#define DMD_DET_ERR_LEN 300
#define ERR_THRESHOLD 0
#define INVALID_INDEX 0xFF
#define VAL_NUM 2
#define VAL_0 0
#define VAL_1 1
#define DET1_INDEX 0
#define DET2_INDEX 1
#define DET3_INDEX 2
#define DET4_INDEX 3

/* vertical line test picture index */
enum {
	PIC1_INDEX,
	PIC2_INDEX,
	PIC3_INDEX,
	PIC4_INDEX,
	PIC5_INDEX,
};

/* pcd errflag detect */
enum {
	LCD_KIT_CHECKSUM_END = 0,
	LCD_KIT_CHECKSUM_START = 1,
};
enum {
	TEST_PIC_0 = 0,
	TEST_PIC_1 = 1,
	TEST_PIC_2 = 2,
	TEST_PIC_MAX,
};
#define CHECKSUM_CHECKCOUNT 5
#define LCD_KIT_CHECKSUM_SIZE 8
#define CHECKSUM_VALUE_SIZE 8
#define INDEX_START 2
#define INVALID_INDEX 0xFF

/* pcd errflag detect */
enum {
	PCD_COMPARE_MODE_EQUAL = 0,
	PCD_COMPARE_MODE_BIGGER = 1,
	PCD_COMPARE_MODE_MASK = 2,
};

struct lcd_checkreg {
	bool enabled;
	int expect_count;
	uint8_t *expect_val;
};

struct lcd_pcd_errflag {
	int pcd_support;
	int pcd_value_compare_mode;
	int exp_pcd_mask;
	int pcd_det_num;
	int pcd_value;
};

struct horizontal_line_desc {
	int hor_support;
	int hor_duration;
	int hor_no_reset;
};

struct lcd_array_data {
	u32 *buf;
	u32 cnt;
};
struct lcd_checksum {
	bool support;
	u32 pic_index;
	u32 status;
	u32 check_count;
	struct lcd_array_data value;
};

struct vertical_line_desc {
	int vtc_support;
	int vtc_no_reset;
};

struct ddic_lv_detect_desc {
	u8 reg_val[DETECT_LOOPS][DETECT_NUM][VAL_NUM];
	int support;
	uint32_t pic_index;
	uint32_t err_flag[DETECT_NUM];
	uint32_t *lv_expect;
	uint32_t cnt;
};

struct lcd_fact_info {
	/* test config */
	char lcd_cmd_now[LCD_CMD_NAME_MAX];
	int pt_flag;
	int pt_reset_enable;
	struct lcd_checkreg checkreg;
	struct lcd_pcd_errflag pcd_errflag_check;
	struct vertical_line_desc vtc_line_test;
	struct horizontal_line_desc hor_line_test;
	struct ddic_lv_detect_desc ddic_lv_detect;
	struct lcd_checksum checksum;
};

#endif
