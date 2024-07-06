/*
 * lcd_kit_display.h
 *
 * lcdkit function for lcdkit head file
 *
 * Copyright (c) 2022-2024 Huawei Technologies Co., Ltd.
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

#ifndef __LCD_KIT_DISPLAY__
#define __LCD_KIT_DISPLAY__

#include "lcd_kit_common.h"
#include "lcd_kit_utils.h"
#include "lcd_kit_power.h"
#include "lcd_kit_ext_power.h"
#include <linux/semaphore.h>
#include <linux/mtd/nve_ap_kernel_interface.h>

#define DTS_COMP_LCD_KIT_PANEL_TYPE     "huawei,lcd_panel_type"
#define POWERKEY_RESTART_TYPE_PROP      "ro.boot.powerkey_restart_type"
#define LCD_KIT_PANEL_COMP_LENGTH       128
#define SN_CODE_LENGTH_MAX 54
/* lcd panel version */
#define VERSION_VALUE_NUM_MAX 30
#define VERSION_NUM_MAX       20
#define LCD_PANEL_VERSION_SIZE 32
#define DISPLAY_PANEL_NAME_MAX_LEN 64
#define LCD_DDIC_INFO_LEN 64
#define PROJECTID_LEN 32
#define MAX_READ_SIZE 162
#define READ_REG_H_OFFSET 152
#define READ_REG_L_OFFSET 153
#define REG_EFFECT_H_OFFSET 158
#define REG_EFFECT_L_OFFSET 159
#define REG_OFFSET 12
#define BYTE_OFFSET 8

int lcd_kit_get_active_panel_id(void);

struct lcd_kit_disp_info *lcd_kit_get_disp_info(int panel_id);
#define disp_info lcd_kit_get_disp_info(panel_id)

struct lcd_kit_public_info *lcd_kit_get_public_info(void);
#define PUBLIC_INFO lcd_kit_get_public_info()

struct lcd_kit_disp_lock *lcd_kit_get_disp_lock(int panel_id);
#define DISP_LOCK lcd_kit_get_disp_lock(panel_id)

struct dpu_panel_info *lcd_kit_get_dpu_pinfo(int panel_id);
#define DPU_PINFO lcd_kit_get_dpu_pinfo(panel_id)

enum lcd_kit_support_panel_id {
	PRIMARY_PANEL,
	SECONDARY_PANEL,
	MAX_PANEL,
};

enum lcd_kit_product_type {
	NORMAL_TYPE,
	DUAL_PANEL,
	LCD_DUAL_PANEL_SIM_DISPLAY_TYPE,
};

/* power sequece */
enum lcd_kit_power_sequece {
	LCD_KIT_POWER_NONE,
	LCD_KIT_POWER_ON_SEQ,
	LCD_KIT_POWER_ON_LP_SEQ,
	LCD_KIT_POWER_ON_HS_SEQ,
	LCD_KIT_POWER_ON,
	LCD_KIT_POWER_OFF_HS_SEQ,
	LCD_KIT_POWER_OFF_LP_SEQ,
	LCD_KIT_POWER_OFF_SEQ,
	LCD_KIT_POWER_OFF,
	LCD_KIT_POWER_DBL_ON_SEQ,
	LCD_KIT_POWER_DBL_ON_LP_SEQ,
	LCD_KIT_POWER_DBL_ON_HS_SEQ,
};

/* lcd fps scence */
enum {
	LCD_FPS_SCENCE_60 = 0,
	LCD_FPS_SCENCE_90 = 1,
	LCD_FPS_SCENCE_120 = 2,
	LCD_FPS_SCENCE_144 = 3,
	LCD_FPS_SCENCE_MAX = 4,
};

/* fps dsi mipi parameter index */
enum {
	FPS_HSA = 0,
	FPS_HBP = 1,
	FPS_HSIZE = 2,
	FPS_HLINE = 3,
	FPS_VSA = 4,
	FPS_VBP = 5,
	FPS_VFP = 6,
	FPS_DSI_CLK = 7,
	FPS_DSI_TIMMING_NUM = 8,
};

enum powerkey_restart_type {
	PRESS_POWER_ONLY,
	PRESS_POWER_VOL_DOWN,
	PRESS_POWER_VOL_UP,
};

struct lcd_kit_disp_lock {
	/* lcd kit semaphore */
	struct semaphore lcd_kit_sem;
	/* thp proximity semaphore */
	struct semaphore thp_second_poweroff_sem;
};

struct lcd_kit_panel_params {
	unsigned int  product_id;
	unsigned int  pin_id;
	char panel_name[DISPLAY_PANEL_NAME_MAX_LEN];
};

struct lcd_kit_public_info {
	int product_type;
	unsigned int active_panel_id;
	unsigned int dvdd_avs_volt;
	char *dvdd_avs_dmd;
	unsigned int primary_panel_version;
	unsigned int secondary_panel_version;
};

struct lcd_kit_panel_version {
	u32 support;
	u32 read_at_uefi;
	u32 value_number;
	u32 version_number;
	u32 secend_value_number;
	unsigned char read_value[VERSION_VALUE_NUM_MAX];
	unsigned char lcd_version_name[VERSION_NUM_MAX][LCD_PANEL_VERSION_SIZE];
	struct lcd_kit_arrays_data value;
	char lcd_panel_version[LCD_PANEL_VERSION_SIZE];
	struct lcd_kit_dsi_panel_cmds cmds;
	struct lcd_kit_dsi_panel_cmds enter_cmds;
	struct lcd_kit_dsi_panel_cmds exit_cmds;
	struct lcd_kit_dsi_panel_cmds secend_cmds;
	struct lcd_kit_dsi_panel_cmds secend_enter_cmds;
	struct lcd_kit_dsi_panel_cmds secend_exit_cmds;
};

struct lcd_kit_project_id {
	unsigned int support;
	char *default_project_id;
	char id[PROJECTID_LEN + 1];
	struct lcd_kit_dsi_panel_cmds cmds;
};

struct lcd_kit_pcd_errflag {
	u32 pcd_support;
	u32 errflag_support;
	u32 gpio_pcd;
	u32 gpio_errflag;
	u32 exp_pcd_mask;
	u32 pcd_det_num;
	u32 power_on_support;
	u32 pcd_value_compare_mode;
	u32 pcd_errflag_check_support;
	struct lcd_kit_dsi_panel_cmds start_pcd_check_cmds;
	struct lcd_kit_dsi_panel_cmds switch_page_cmds;
	struct lcd_kit_dsi_panel_cmds read_pcd_cmds;
	struct lcd_kit_array_data pcd_value;
	struct lcd_kit_dsi_panel_cmds read_errflag_cmds;
};

struct elvdd_detect {
	u32 support;
	u32 detect_type;
	u32 detect_gpio;
	u32 detect_gpio_type;
	u32 exp_value;
	u32 exp_value_mask;
	u32 delay;
	bool is_start_delay_timer;
	struct lcd_kit_dsi_panel_cmds cmds;
};

struct lcd_kit_fps {
	u32 support;
	u32 fps_switch_support;
	char *fps_60_cmd;
	char *fps_90_cmd;
	char *fps_120_cmd;
	char *fps_144_cmd;
	char *fps_45_cmd;
	char *fps_40_cmd;
	char *fps_30_cmd;
	char *fps_24_cmd;
	char *fps_20_cmd;
	char *fps_18_cmd;
	char *fps_15_cmd;
	char *fps_10_cmd;
	char *fps_1_cmd;
	unsigned int default_fps;
	unsigned int current_fps;
	unsigned int hop_support;
	unsigned int bl_to_1_hz;
	unsigned int aod_bl_to_1_hz;
	struct lcd_kit_array_data normal_frame_porch;
	struct lcd_kit_array_data panel_support_fps_list;
	struct lcd_kit_dsi_panel_cmds dfr_enable_cmds;
	struct lcd_kit_dsi_panel_cmds dfr_disable_cmds;
	struct lcd_kit_dsi_panel_cmds fps_to_1_cmds;
	struct lcd_kit_dsi_panel_cmds fps_to_10_cmds;
	struct lcd_kit_dsi_panel_cmds fps_to_15_cmds;
	struct lcd_kit_dsi_panel_cmds fps_to_18_cmds;
	struct lcd_kit_dsi_panel_cmds fps_to_20_cmds;
	struct lcd_kit_dsi_panel_cmds fps_to_24_cmds;
	struct lcd_kit_dsi_panel_cmds fps_to_30_cmds;
	struct lcd_kit_dsi_panel_cmds fps_to_40_cmds;
	struct lcd_kit_dsi_panel_cmds fps_to_45_cmds;
	struct lcd_kit_dsi_panel_cmds fps_to_60_cmds;
	struct lcd_kit_dsi_panel_cmds fps_to_90_cmds;
	struct lcd_kit_dsi_panel_cmds fps_to_120_cmds;
	struct lcd_kit_dsi_panel_cmds fps_to_144_cmds;
	struct lcd_kit_dsi_panel_cmds refresh_cmds;
	struct lcd_kit_array_data low_frame_porch;
	struct lcd_kit_array_data fps_dsi_timming[LCD_FPS_SCENCE_MAX];
};

struct lcd_kit_power_off_optimize_info {
	unsigned int support;
	unsigned int delay_time;
};

struct lcd_kit_check_mipi {
	unsigned int support;
	unsigned int max_number;
	struct lcd_kit_dsi_panel_cmds cmds;
	struct lcd_kit_array_data value;
	struct lcd_kit_array_data judge_type;
	struct lcd_kit_dsi_panel_cmds sub_cmds;
	struct lcd_kit_array_data sub_value;
};

struct lcd_kit_ddic_irc {
	uint32_t support;
	uint32_t enable;
	struct lcd_kit_dsi_panel_cmds on;
	struct lcd_kit_dsi_panel_cmds off;
};

struct lcd_kit_completion {
	struct completion tx_no_lock_done;
	bool is_in_tx_no_lock;
};

struct lcd_kit_power_key_info {
	unsigned int support;
	unsigned int power_off_flag;
	unsigned int esd_status;
	unsigned int long_press_flag;
	unsigned int timer_val;
	unsigned int rst_addr;
	unsigned int configtime1;
	unsigned int configtime2;
	unsigned int configtime3;
	unsigned int configtime4;
	struct notifier_block nb;
	struct delayed_work pf_work;
	struct lcd_kit_dsi_panel_cmds cmds;
};

struct lcd_kit_updt_fps_te {
	uint32_t support;
	uint32_t cmds_delay;
	struct lcd_kit_dsi_panel_cmds fps_60_cmds;
	struct lcd_kit_dsi_panel_cmds fps_120_cmds;
	struct lcd_kit_dsi_panel_cmds fps_144_cmds;
};

struct lcd_kit_effect_protect {
	uint32_t support;
	uint32_t ratio;
	uint32_t first_off_flag;
	struct lcd_kit_array_data expect_version;
	struct lcd_kit_dsi_panel_cmds read_cmds;
	struct lcd_kit_dsi_panel_cmds write_cmds;
};

struct lcd_kit_disp_info {
	/* lcd type */
	unsigned int lcd_type;
	/* panel information */
	char *compatible;
	/* board version */
	unsigned int board_version;
	/* product id */
	unsigned int product_id;
	unsigned int lcd_power_seq;
	/* oem information */
	struct lcd_kit_oem_info oeminfo;
	/* quickly sleep out */
	struct lcd_kit_quickly_sleep_out quickly_sleep_out;
	/* project id */
	struct lcd_kit_project_id project_id;
	/* sn code */
	unsigned int sn_code_length;
	unsigned char sn_code[SN_CODE_LENGTH_MAX];
	/* panel version */
	struct lcd_kit_panel_version panel_version;
	/* pcd errflag */
	struct lcd_kit_pcd_errflag pcd_errflag;
	/* elvdd detect */
	struct elvdd_detect elvdd_detect;
	/* fps ctrl */
	struct lcd_kit_fps fps;
	/* dieid info */
	struct lcd_kit_panel_dieid_info panel_dieid_info;
	/* camera prox */
	unsigned int camera_prox;
	/* power off optimize */
	struct lcd_kit_power_off_optimize_info pwr_off_optimize_info;
	/* jank last bl level */
	unsigned int jank_last_bl_level;
	/* mipi error */
	struct lcd_kit_check_mipi check_mipi;
	/* panel irc control */
	struct lcd_kit_ddic_irc panel_irc;
	/* esd enable */
	unsigned int esd_enable;
	/* lcd completion */
	struct lcd_kit_completion lcd_completion;
	/* lcd quick power off */
	struct lcd_kit_power_key_info pwrkey_press;
	/* nv info */
	struct opt_nve_info_user nv_info;
	/* lcd update fps te mode */
	struct lcd_kit_updt_fps_te updt_fps_te;
	struct lcd_kit_effect_protect effect_protect;
};

int lcd_kit_get_display_type(void);
#endif
