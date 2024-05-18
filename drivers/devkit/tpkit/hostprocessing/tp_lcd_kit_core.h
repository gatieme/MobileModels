/*
 * lcd_kit_core.h
 *
 * lcdkit core function for lcdkit head file
 *
 * Copyright (c) 2020-2020 Honor Device Co., Ltd.
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

#ifndef _LCD_TP_KIT_CORE_H_
#define _LCD_TP_KIT_CORE_H_
#include <linux/types.h>
#include <linux/kobject.h>

#define TP_FP_VALID_EVENT_NUM 5

enum tp_fp_event {
	TP_EVENT_FINGER_DOWN = 0,
	TP_EVENT_FINGER_UP = 1,
	TP_EVENT_HOVER_DOWN = 2,
	TP_EVENT_HOVER_UP = 3,
	TP_EVENT_FINGER_UP_QDB = 10,
	TP_FP_EVENT_MAX = 255,
};

struct fp_data_head_t {
	uint8_t version;
	uint8_t num_row;
	uint8_t num_col;
	uint8_t linedata_flag;
	uint8_t valid_frames;
	uint8_t motion_complete_flag; /* 1: complete */
	uint8_t screen_status; /* 1: SCREEN_ON 0: SCREEN_OFF */
	uint8_t freq;
	uint32_t data_size; /* head_len + data_len */
	char project_id[16]; /* 16: length of project_id */
	uint8_t reserve[6]; /* 6: reserve bytes */
};

struct tp_to_udfp_data {
	unsigned int version;
	enum tp_fp_event udfp_event;
	unsigned int mis_touch_count_area;
	unsigned int touch_to_fingerdown_time;
	unsigned int pressure;
	unsigned int mis_touch_count_pressure;
	unsigned int tp_coverage;
	unsigned int tp_fingersize;
	unsigned int tp_x;
	unsigned int tp_y;
	unsigned int tp_major;
	unsigned int tp_minor;
	char tp_ori;
};

struct ud_fp_ops {
	int (*fp_irq_notify)(struct tp_to_udfp_data *tp_data);
	int (*fp_anti_fake_data_notify)(struct fp_data_head_t *tp_data);
};

void fp_ops_register(struct ud_fp_ops *ops);
void fp_ops_unregister(struct ud_fp_ops *ops);
struct ud_fp_ops *fp_get_ops(void);

/* lcd kit ops, provide to lcd kit module register */

#endif
