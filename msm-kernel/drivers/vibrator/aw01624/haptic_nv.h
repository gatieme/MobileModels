/*
 * z haptic_nv.h
 *
 * code for vibrator
 *
 * Copyright (c) 2021 Huawei Technologies Co., Ltd.
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

#ifndef _HAPTIC_NV_H_
#define _HAPTIC_NV_H_

#include <linux/regmap.h>
#include <linux/timer.h>
#include <linux/workqueue.h>
#include <linux/hrtimer.h>
#include <linux/mutex.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/syscalls.h>

/*********************************************************
 *
 * kernel marco
 *
 ********************************************************/
#if LINUX_VERSION_CODE <= KERNEL_VERSION(4, 4, 1)
#define TIMED_OUTPUT
#endif

#ifdef TIMED_OUTPUT
#include <../../../drivers/staging/android/timed_output.h>
typedef struct timed_output_dev cdev_t;
#else
typedef struct led_classdev cdev_t;
#endif

/*********************************************************
 *
 * normal marco
 *
 ********************************************************/
#define HAPTIC_NV_I2C_NAME		("haptic_nv")
#define HAPTIC_NV_AWRW_SIZE		(220)
#define HAPTIC_NV_CHIPID_RETRIES	(5)
#define HAPTIC_NV_I2C_RETRIES		(2)
#define HAPTIC_NV_REG_ID		(0x00)
#define AW8624_CHIP_ID			(0x24)
#define AW8622X_CHIP_ID			(0x00)
#define AW86214_CHIP_ID			(0x01)
#define AW862XX_REG_EFRD9		(0x64)
#define REG_NONE_ACCESS			(0)
#define REG_RD_ACCESS			(1 << 0)
#define REG_WR_ACCESS			(1 << 1)
#define AW_REG_MAX			(0xFF)
#define AW_RAMDATA_RD_BUFFER_SIZE	(1024)
#define AW_RAMDATA_WR_BUFFER_SIZE	(2048)
#define AW_GUN_TYPE_DEF_VAL		(0xFF)
#define AW_BULLET_NR_DEF_VAL		(0)
#define AW_I2C_READ_MSG_NUM		(2)
#define AW_I2C_BYTE_ONE			(1)
#define AW_I2C_BYTE_TWO			(2)
#define AW_I2C_BYTE_THREE		(3)
#define AW_I2C_BYTE_FOUR		(4)
#define AW_I2C_BYTE_FIVE		(5)
#define AW_I2C_BYTE_SIX			(6)
#define AW_I2C_BYTE_SEVEN		(7)
#define AW_I2C_BYTE_EIGHT		(8)
#define AWRW_CMD_UNIT			(5)
#define AW_SET_RAMADDR_H(addr)		((addr) >> 8)
#define AW_SET_RAMADDR_L(addr)		((addr) & 0x00FF)
#define AW_SET_BASEADDR_H(addr)		((addr) >> 8)
#define AW_SET_BASEADDR_L(addr)		((addr) & 0x00FF)
/*********************************************************
 *
 * macro control
 *
 ********************************************************/
#define AW_CHECK_RAM_DATA
#define AW_READ_BIN_FLEXBALLY
#define AW_ENABLE_RTP_PRINT_LOG
/* #define AW8624_MUL_GET_F0 */

#define aw_dev_err(format, ...) \
			pr_err("[haptic_nv]" format, ##__VA_ARGS__)

#define aw_dev_info(format, ...) \
			pr_info("[haptic_nv]" format, ##__VA_ARGS__)

#define aw_dev_dbg(format, ...) \
			pr_debug("[haptic_nv]" format, ##__VA_ARGS__)

/*********************************************************
 *
 * customization
 *
 *********************************************************/
#define AW_HAPTIC_NAME                 "haptics"

#define RTP_WORK_HZ_12K                         2
#define EFFECT_ID_MAX                           100
#define EFFECT_MAX_SHORT_VIB_ID                 10
#define EFFECT_SHORT_VIB_AVAIABLE               3
#define EFFECT_MAX_LONG_VIB_ID                  20
#define LONG_VIB_EFFECT_ID                      4
#define LONG_HAPTIC_RTP_MAX_ID                  4999
#define LONG_HAPTIC_RTP_MIN_ID                  1010

#define SHORT_HAPTIC_RAM_MAX_ID                 309
#define SHORT_HAPTIC_RTP_MAX_ID                 9999

#define SHORT_HAPTIC_RAM_MIN_IDX                1
#define SHORT_HAPTIC_RAM_MAX_IDX                30
#define SHORT_HAPTIC_RTP_MAX_IDX                9999

#define SHORT_HAPTIC_AMP_DIV_COFF               10
#define LONG_TIME_AMP_DIV_COFF                  100
#define BASE_INDEX                              31

#define AW_RTP_NAME_MAX				(64)

#define AW_LONG_HAPTIC_RUNNING              4253
#define AW_LONG_MAX_AMP_CFG            9
#define AW_SHORT_MAX_AMP_CFG           6

#define AW_HAPTIC_IOCTL_MAGIC             'h'
#define AW_HAPTIC_SET_QUE_SEQ \
	_IOWR(AW_HAPTIC_IOCTL_MAGIC, 1, struct aw_que_seq*)
#define AW_HAPTIC_SET_SEQ_LOOP \
	_IOWR(AW_HAPTIC_IOCTL_MAGIC, 2, struct aw_seq_loop*)
#define AW_HAPTIC_PLAY_QUE_SEQ \
	_IOWR(AW_HAPTIC_IOCTL_MAGIC, 3, unsigned int)
#define AW_HAPTIC_SET_BST_VOL \
	_IOWR(AW_HAPTIC_IOCTL_MAGIC, 4, unsigned int)
#define AW_HAPTIC_SET_BST_PEAK_CUR \
	_IOWR(AW_HAPTIC_IOCTL_MAGIC, 5, unsigned int)
#define AW_HAPTIC_SET_GAIN \
	_IOWR(AW_HAPTIC_IOCTL_MAGIC, 6, unsigned int)
#define AW_HAPTIC_PLAY_REPEAT_SEQ \
	_IOWR(AW_HAPTIC_IOCTL_MAGIC, 7, unsigned int)

#define MAX_WRITE_BUF_LEN           16

enum aw_haptic_awrw_flag {
	AW_SEQ_WRITE = 0,
	AW_SEQ_READ = 1,
};

enum z_vib_mode_type {
	SHORT_VIB_RAM_MODE = 0,
	LONG_VIB_RAM_MODE = 1,
	RTP_VIB_MODE = 2,
	VIB_MODE_MAX,
};

enum aw_haptic_read_write {
	AW_HAPTIC_CMD_READ_REG = 0,
	AW_HAPTIC_CMD_WRITE_REG = 1,
};

struct fileops {
	unsigned char cmd;
	unsigned char reg;
	unsigned char ram_addrh;
	unsigned char ram_addrl;
};
enum aw_haptic_activate_mode {
	AW_HAPTIC_ACTIVATE_RAM_MODE = 0,
	AW_HAPTIC_ACTIVATE_CONT_MODE = 1,
};

/*********************************************************
 *
 * enum
 *
 ********************************************************/
enum haptic_nv_chip_name {
	AW_CHIP_NULL = 0,
	AW86223 = 1,
	AW86224_5 = 2,
	AW86214 = 3,
	AW8624 = 4,
};

enum haptic_nv_read_chip_type {
	HAPTIC_NV_FIRST_TRY = 0,
	HAPTIC_NV_LAST_TRY = 1,
};

enum aw862xx_ef_id {
	AW86223_EF_ID = 0x01,
	AW86224_5_EF_ID = 0x00,
	AW86214_EF_ID = 0x41,
};
/*********************************************************
 *
 * struct
 *
 ********************************************************/
struct awinic {
	bool IsUsedIRQ;
	unsigned char name;

	unsigned int aw862xx_i2c_addr;
	struct mutex lock;
	struct fileops fileops;
	int boost_en;
	int boost_fw;
	int reset_gpio;
	int irq_gpio;
	int reset_gpio_ret;
	int irq_gpio_ret;

	struct i2c_client *i2c;
	struct device *dev;
	struct aw8624 *aw8624;
	struct aw8622x *aw8622x;
	struct aw86214 *aw86214;
};

struct ram {
	unsigned int len;
	unsigned int check_sum;
	unsigned int base_addr;
	unsigned char version;
	unsigned char ram_shift;
	unsigned char baseaddr_shift;
	unsigned char ram_num;
};

struct haptic_ctr {
	unsigned char cnt;
	unsigned char cmd;
	unsigned char play;
	unsigned char wavseq;
	unsigned char loop;
	unsigned char gain;
	struct list_head list;
};

struct haptic_audio {
	struct mutex lock;
	struct hrtimer timer;
	struct work_struct work;
	int delay_val;
	int timer_val;
	struct haptic_ctr ctr;
	struct list_head ctr_list;
};

struct aw_i2c_package {
	unsigned char flag;
	unsigned char reg_num;
	unsigned char first_addr;
	unsigned char reg_data[HAPTIC_NV_AWRW_SIZE];
};
#endif
