/*
 * lcd_kit_drm_panel.h
 *
 * lcdkit display function head file for lcd driver
 *
 * Copyright (c) 2018-2019 Honor Device Co., Ltd.
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

#ifndef __LCD_KIT_DRM_PANEL_H_
#define __LCD_KIT_DRM_PANEL_H_
#include <linux/backlight.h>
#include <linux/miscdevice.h>
#include <linux/of_reserved_mem.h>
#include <linux/dma-mapping.h>
#include <linux/memory.h>
#include <drm/drmP.h>
#include <drm/drm_mipi_dsi.h>
#include <drm/drm_panel.h>
#include <linux/gpio/consumer.h>
#include <linux/regulator/consumer.h>
#include <video/mipi_display.h>
#include <video/of_videomode.h>
#include <video/videomode.h>
#include <linux/module.h>
#include <linux/of_platform.h>
#include <linux/platform_device.h>
#include "lcd_kit_common.h"
#include "lcd_kit_parse.h"
#include "lcd_kit_adapt.h"
#include "lcd_kit_core.h"
#include "bias_bl_utils.h"
#include "lcd_kit_panel.h"
#include "lcd_kit_sysfs.h"
#if defined CONFIG_HONOR_DSM
#include <dsm/dsm_pub.h>
#endif

/* macro */
#define DTS_COMP_LCD_KIT_PANEL_TYPE     "honor,lcd_panel_type"
// elvdd detect type
#define ELVDD_MIPI_CHECK_MODE   1
#define ELVDD_GPIO_CHECK_MODE   2
/* default panel */
#define LCD_KIT_DEFAULT_PANEL  "auo_otm1901a_5p2_1080p_video_default"

/* lcd fps scence */
#define LCD_KIT_FPS_SCENCE_IDLE        BIT(0)
#define LCD_KIT_FPS_SCENCE_VIDEO       BIT(1)
#define LCD_KIT_FPS_SCENCE_GAME        BIT(2)
#define LCD_KIT_FPS_SCENCE_WEB         BIT(3)
#define LCD_KIT_FPS_SCENCE_EBOOK       BIT(4)
#define LCD_KIT_FPS_SCENCE_FORCE_30FPS          BIT(5)
#define LCD_KIT_FPS_SCENCE_FUNC_DEFAULT_ENABLE  BIT(6)
#define LCD_KIT_FPS_SCENCE_FUNC_DEFAULT_DISABLE BIT(7)
/* lcd fps value */
#define LCD_KIT_FPS_30 30
#define LCD_KIT_FPS_55 55
#define LCD_KIT_FPS_60 60
#define LCD_KIT_FPS_90 90
#define LCD_KIT_FPS_120 120
#define MAX_BUF        60
#define LCD_REG_LENGTH_MAX 200
#define LCD_DDIC_INFO_LEN      64
/* 2d barcode */
#define BARCODE_LENGTH 46

/* project id */
#define PROJECTID_LEN 10
#define SN_CODE_LENGTH_MAX 54
#define MTK_MODE_STATE_OK 0
#define MTK_MODE_STATE_FAIL 1

/* ddic low voltage detect */
#define DETECT_NUM     4
#define DETECT_LOOPS   6
#define ERR_THRESHOLD  4
#define DET_START      1
#define VAL_NUM        2
#define VAL_0          0
#define VAL_1          1
#define DET1_INDEX     0
#define DET2_INDEX     1
#define DET3_INDEX     2
#define DET4_INDEX     3
#define DMD_DET_ERR_LEN      300
#define ENABLE	        1
#define DISABLE	        0
#define INVALID_INDEX  0xFF

/* pcd errflag detect */
#define PCD_ERRFLAG_SUCCESS       0
#define PCD_FAIL                  1
#define ERRFLAG_FAIL              2
#define LCD_KIT_PCD_SIZE          3
#define LCD_KIT_ERRFLAG_SIZE      8
#define DMD_ERR_INFO_LEN         50
#define LCD_KIT_PCD_DETECT_OPEN   1
#define LCD_KIT_PCD_DETECT_CLOSE  0

// HBM
#define BACKLIGHT_HIGH_LEVEL 1
#define BACKLIGHT_LOW_LEVEL  2
// UD PrintFinger HBM
#define LCD_KIT_FP_HBM_ENTER 1
#define LCD_KIT_FP_HBM_EXIT  2
#define LCD_KIT_ENABLE_ELVSSDIM  0
#define LCD_KIT_DISABLE_ELVSSDIM 1
#define LCD_KIT_ELVSSDIM_NO_WAIT 0
#define REC_DMD_NO_LIMIT      (-1)
#define DMD_RECORD_BUF_LEN    100
#define RECOVERY_TIMES          1

enum LCM_DRM_DSI_MODE {
	DSI_CMD_MODE = 0,
	DSI_BURST_VDO_MODE = 1,
	DSI_SYNC_PULSE_VDO_MODE = 2,
	DSI_SYNC_EVENT_VDO_MODE = 3
};

enum LCM_DSI_PIXEL_FORMAT {
	PIXEL_24BIT_RGB888 = 0,
	LOOSELY_PIXEL_18BIT_RGB666 = 1,
	PACKED_PIXEL_18BIT_RGB666 = 2,
	PIXEL_16BIT_RGB565 = 3,
	PIXEL_SPRD_DSC = 4
};

/* lcd fps set from app */
enum {
	LCD_FPS_APP_SET_60 = 3,
	LCD_FPS_APP_SET_90,
	LCD_FPS_APP_SET_120
};

/* pcd detect */
enum pcd_check_status {
	PCD_CHECK_WAIT,
	PCD_CHECK_ON,
	PCD_CHECK_OFF,
};

/* pcd errflag detect */
enum {
	PCD_COMPARE_MODE_EQUAL = 0,
	PCD_COMPARE_MODE_BIGGER = 1,
	PCD_COMPARE_MODE_MASK = 2
};

/* lcd fps scence */
enum {
	LCD_FPS_SCENCE_60 = 0,
	LCD_FPS_SCENCE_H60 = 1,
	LCD_FPS_SCENCE_90 = 2,
	LCD_FPS_SCENCE_120 = 3,
	LCD_FPS_SCENCE_MAX = 4
};

/* lcd fps index */
enum {
	LCD_FPS_60_INDEX = 0,
	LCD_FPS_90_INDEX = 1,
	LCD_FPS_120_INDEX = 2
};

/* fps dsi mipi parameter index */
enum {
	FPS_HFP_INDEX = 0,
	FPS_HBP_INDEX = 1,
	FPS_HS_INDEX = 2,
	FPS_VFP_INDEX = 3,
	FPS_VBP_INDEX = 4,
	FPS_VS_INDEX = 5,
	FPS_VRE_INDEX = 6,
	FPS_RATE_INDEX = 7,
	FPS_LOWER_INDEX = 8,
	FPS_DA_HS_EXIT = 9,
	FPS_DSI_TIMMING_PARA_NUM = 10
};

/* enum */
enum {
	RGBW_SET1_MODE = 1,
	RGBW_SET2_MODE = 2,
	RGBW_SET3_MODE = 3,
	RGBW_SET4_MODE = 4
};

enum {
	LCD_OFFLINE = 0,
	LCD_ONLINE = 1
};

enum alpm_mode {
	ALPM_DISPLAY_OFF,
	ALPM_ON_HIGH_LIGHT,
	ALPM_EXIT,
	ALPM_ON_LOW_LIGHT,
	ALPM_SINGLE_CLOCK,
	ALPM_DOUBLE_CLOCK,
	ALPM_ON_MIDDLE_LIGHT,
};

enum alpm_state {
	ALPM_OUT,
	ALPM_START,
	ALPM_IN,
};

enum HBM_CFG_TYPE {
	HBM_FOR_FP = 0,
	HBM_FOR_MMI = 1,
	HBM_FOR_LIGHT = 2
};

enum bl_type {
	DSI_BACKLIGHT_PWM = 0,
	DSI_BACKLIGHT_DCS,
    DSI_BACKLIGHT_I2C_IC,
	DSI_BACKLIGHT_DCS_I2C_IC,
	DSI_BACKLIGHT_MAX
};

enum backlight_ctrl_mode {
  	BL_I2C_ONLY_MODE = 0,
    BL_PWM_ONLY_MODE = 1,
    BL_MUL_RAMP_MODE = 2,
    BL_RAMP_MUL_MODE = 3,
    BL_PWM_I2C_MODE = 4,
    BL_MIPI_IC_PWM_MODE = 5
};


enum bias_control_mode {
	MT_AP_MODE = 0,
	PMIC_ONLY_MODE = 1,
	GPIO_ONLY_MODE,
	GPIO_THEN_I2C_MODE,
};

struct hbm_type_cfg {
	int source;
	void *dsi;
	void *cb;
	void *handle;
};

struct display_engine_ddic_rgbw_param {
	int ddic_panel_id;
	int ddic_rgbw_mode;
	int ddic_rgbw_backlight;
	int pixel_gain_limit;
};

struct display_engine_panel_info_param {
	int width;
	int height;
	int maxluminance;
	int minluminance;
	int maxbacklight;
	int minbacklight;
};

struct display_engine {
	u8 ddic_cabc_support;
	u8 ddic_rgbw_support;
};

struct display_engine_ddic_hbm_param {
	int type;      // 0:fp   1:MMI   2:light
	int level;
	bool dimming;  // 0:no dimming  1:dimming
};

struct lcd_kit_gamma {
	u32 support;
	u32 addr;
	u32 length;
	struct lcd_kit_dsi_panel_cmds cmds;
};

struct lcd_kit_color_coordinate {
	u32 support;
	/* color consistency support */
	struct lcd_kit_dsi_panel_cmds cmds;
};

struct lcd_kit_2d_barcode {
	u32 support;
	int number_offset;
	struct lcd_kit_dsi_panel_cmds cmds;
};

struct lcd_kit_oem_info {
	u32 support;
	/* 2d barcode */
	struct lcd_kit_2d_barcode barcode_2d;
	/* color coordinate */
	struct lcd_kit_color_coordinate col_coordinate;
};

struct lcd_kit_brightness_color_oeminfo {
	u32 support;
	struct lcd_kit_oem_info oem_info;
};

struct lcd_kit_project_id {
	u32 support;
	char id[LCD_DDIC_INFO_LEN];
	char *default_project_id;
	struct lcd_kit_dsi_panel_cmds cmds;
};

struct lcd_kit_pcd_errflag {
	u32 pcd_support;
	u32 errflag_support;
	u32 pcd_value_compare_mode;
	u32 pcd_errflag_check_support;
	u32 gpio_pcd;
	u32 gpio_errflag;
	u32 exp_pcd_mask;
	u32 pcd_det_num;
	struct lcd_kit_dsi_panel_cmds start_pcd_check_cmds;
	struct lcd_kit_dsi_panel_cmds switch_page_cmds;
	struct lcd_kit_dsi_panel_cmds read_pcd_cmds;
	struct lcd_kit_array_data pcd_value;
	struct lcd_kit_dsi_panel_cmds read_errflag_cmds;
};

struct lcd_kit_fps {
	u32 support;
	u32 fps_switch_support;
	unsigned int default_fps;
	unsigned int current_fps;
	unsigned int hop_support;
	struct lcd_kit_dsi_panel_cmds dfr_enable_cmds;
	struct lcd_kit_dsi_panel_cmds dfr_disable_cmds;
	struct lcd_kit_dsi_panel_cmds fps_to_30_cmds;
	struct lcd_kit_dsi_panel_cmds fps_to_60_cmds;
	struct lcd_kit_array_data low_frame_porch;
	struct lcd_kit_array_data normal_frame_porch;
	struct lcd_kit_array_data panel_support_fps_list;
	struct lcd_kit_dsi_panel_cmds fps_to_cmds[LCD_FPS_SCENCE_MAX];
	struct lcd_kit_array_data fps_dsi_timming[LCD_FPS_SCENCE_MAX];
	struct lcd_kit_array_data hop_info[LCD_FPS_SCENCE_MAX];
};

struct lcd_kit_rgbw {
	u32 support;
	u32 rgbw_bl_max;
	struct lcd_kit_dsi_panel_cmds mode1_cmds;
	struct lcd_kit_dsi_panel_cmds mode2_cmds;
	struct lcd_kit_dsi_panel_cmds mode3_cmds;
	struct lcd_kit_dsi_panel_cmds mode4_cmds;
	struct lcd_kit_dsi_panel_cmds backlight_cmds;
	struct lcd_kit_dsi_panel_cmds saturation_ctrl_cmds;
	struct lcd_kit_dsi_panel_cmds frame_gain_limit_cmds;
	struct lcd_kit_dsi_panel_cmds frame_gain_speed_cmds;
	struct lcd_kit_dsi_panel_cmds color_distor_allowance_cmds;
	struct lcd_kit_dsi_panel_cmds pixel_gain_limit_cmds;
	struct lcd_kit_dsi_panel_cmds pixel_gain_speed_cmds;
	struct lcd_kit_dsi_panel_cmds pwm_gain_cmds;
};

struct lcd_kit_alpm {
	u32 support;
	u32 state;
	u32 doze_delay;
	u32 need_reset;
	struct lcd_kit_dsi_panel_cmds exit_cmds;
	struct lcd_kit_dsi_panel_cmds off_cmds;
	struct lcd_kit_dsi_panel_cmds low_light_cmds;
	struct lcd_kit_dsi_panel_cmds middle_light_cmds;
	struct lcd_kit_dsi_panel_cmds high_light_cmds;
	struct lcd_kit_dsi_panel_cmds double_clock_cmds;
	struct lcd_kit_dsi_panel_cmds single_clock_cmds;
};

struct lcd_kit_snd_disp {
	u32 support;
	struct lcd_kit_dsi_panel_cmds on_cmds;
	struct lcd_kit_dsi_panel_cmds off_cmds;
};

struct lcd_kit_quickly_sleep_out {
	u32 support;
	u32 interval;
	u32 panel_on_tag;
	struct timeval panel_on_record_tv;
};

struct elvdd_detect {
	u32 support;
	u32 detect_type;
	u32 detect_gpio;
	u32 exp_value;
	u32 exp_value_mask;
	u32 delay;
	bool is_start_delay_timer;
	struct lcd_kit_dsi_panel_cmds cmds;
};

struct poweric_detect_delay {
	struct work_struct wq;
	struct timer_list timer;
};

struct lcd_kit_disp_info {
	/* effect */
	/* gamma calibration */
	struct lcd_kit_gamma gamma_cal;
	/* oem information */
	struct lcd_kit_oem_info oeminfo;
	/* rgbw function */
	struct lcd_kit_rgbw rgbw;
	/* end */
	/* normal */
	/* lcd type */
	u32 lcd_type;
	/* panel information */
	char *compatible;
	/* regulator name */
	char *vci_regulator_name;
	char *iovcc_regulator_name;
	char *vdd_regulator_name;
	/* product id */
	u32 product_id;
	/* vr support */
	u32 vr_support;
	/* lcd kit blank semaphore */
	struct semaphore blank_sem;
	/* lcd kit semaphore */
	struct semaphore lcd_kit_sem;
	/* lcd kit mipi mutex lock */
	struct mutex mipi_lock;
	/* alpm -aod */
	struct lcd_kit_alpm alpm;
	u8 alpm_state;
	ktime_t alpm_start_time;
	struct mutex drm_hw_lock;
	/* pre power off */
	u32 pre_power_off;
	/* quickly sleep out */
	struct lcd_kit_quickly_sleep_out quickly_sleep_out;
	/* fps ctrl */
	struct lcd_kit_fps fps;
	/* project id */
	struct lcd_kit_project_id project_id;
	/* thp_second_poweroff_sem */
	struct semaphore thp_second_poweroff_sem;
	struct display_engine_ddic_rgbw_param ddic_rgbw_param;
	/* elvdd detect */
	struct elvdd_detect elvdd_detect;
	/* end */
	/* normal */
	bool bl_is_shield_backlight;
	u8 bl_is_start_timer;
	/* hbm set */
	u32 hbm_entry_delay;
	ktime_t hbm_blcode_ts;
	u32 te_interval_us;
	u32 hbm_en_times;
	u32 hbm_dis_times;
	/* skip poweron esd check */
	u8 lcd_kit_skip_poweron_esd_check;
	u8 lcd_kit_skip_esd_check_cnt;
	u32 lcd_kit_again_esd_check_delay;
	u32 lcd_kit_esd_check_delay;
	/* pcd errflag */
	struct lcd_kit_pcd_errflag pcd_errflag;
	/* display idle mode support */
	u32 lcd_kit_idle_mode_support;
};

struct mipi_panel_info {
	u32 h_back_porch;
	u32 h_front_porch;
	u32 h_pulse_width;
	u32 v_back_porch;
	u32 v_front_porch;
	u32 v_pulse_width;
	u8 lane_nums;
	u8 non_continue_en;
	u8 use_dcs;
	u32 dsi_color_format;

	u8 color_mode;
	u32 dsi_bit_clk;
	u32 burst_mode;
	u32 phy_mode;  /* 0: DPHY, 1:CPHY */
};

struct sprd_panel_info {
	struct device_node *np;
	struct mipi_dsi_device *slave;
	struct backlight_device *bldev;
	u32 panel_state;
	u32 panel_density;
	u32 panel_interface;
	u32 panel_dsi_mode;
	u32 type;
	u32 xres;
	u32 yres;
	u32 width; /* mm */
	u32 height;
	u32 surface_width;
	u32 surface_height;
	u32 vrefresh;
	u32 fps;
	u32 fps_updt;
	u32 orientation;
	u32 bl_set_type;
	u32 bl_min;
	u32 bl_max;
	u32 bl_current;
	u32 bl_ic_ctrl_mode;
	u32 gpio_offset;

	u8 esd_enable;
	u8 esd_skip_mipi_check;
	u8 esd_recover_step;
	u8 esd_expect_value_type;
	u8 dirty_region_updt_support;
	u8 snd_cmd_before_frame_support;
	u8 dsi_bit_clk_upt_support;
	u8 mipiclk_updt_support_new;
	u8 fps_updt_support;
	u8 fps_updt_panel_only;
	u8 fps_updt_force_update;
	u8 fps_scence;
	
	u8 gmp_support;
	u8 colormode_support;
	u8 gamma_support;
	u8 rgbw_support;
	u8 hbm_support;

	u8 hiace_support;
	u8 dither_support;
	struct mipi_panel_info mipi;
	int maxluminance;
	int minluminance;
	/* sn code */
	uint32_t sn_code_length;
	unsigned char sn_code[SN_CODE_LENGTH_MAX];
};

/* function declare */
struct lcd_kit_disp_info *lcd_kit_get_disp_info(void);
#define disp_info	lcd_kit_get_disp_info()
unsigned int lcm_get_panel_state(void);
int lcd_kit_read_project_id(void);
int lcd_kit_utils_init(struct device_node *np, struct sprd_panel_info *pinfo);
bool lcd_kit_support(void);
void lcd_kit_disp_on_record_time(void);
int lcd_kit_get_bl_max_nit_from_dts(void);
void lcd_kit_disp_on_check_delay(void);
void lcd_kit_set_bl_cmd(uint32_t level);
int lcd_kit_mipi_set_backlight(struct hbm_type_cfg hbm_source, uint32_t level);
void lcd_esd_enable(int enable);
void lcd_kit_recovery_display(void);
void lcd_kit_ddic_lv_detect_dmd_report(
	u8 reg_val[DETECT_LOOPS][DETECT_NUM][VAL_NUM]);
int lcd_kit_check_pcd_errflag_check_fac(void);
int lcd_kit_gpio_pcd_errflag_check(void);
int lcd_kit_start_pcd_check(void *hld);
int lcd_kit_check_pcd_errflag_check(void *hld);
struct sprd_panel_info *lcm_get_panel_info(void);
int lcd_kit_init(void);
int lcm_rgbw_mode_set_param(struct drm_device *dev, void *data,
	struct drm_file *file_priv);
int lcm_rgbw_mode_get_param(struct drm_device *dev, void *data,
	struct drm_file *file_priv);
int lcm_display_engine_get_panel_info(struct drm_device *dev, void *data,
	struct drm_file *file_priv);
int lcm_display_engine_init(struct drm_device *dev, void *data,
	struct drm_file *file_priv);
int panel_drm_hbm_set(struct drm_device *dev, void *data,
	struct drm_file *file_priv);
int lcd_kit_rgbw_set_handle(void);
unsigned int lcm_get_panel_backlight_max_level(void);
int lcd_kit_sysfs_init(void);
int lcd_kit_get_cur_backlight_level(void);
int lcd_kit_get_max_backlight_level(void);
int lcd_kit_cabc_backlight_update(int level);
struct mutex *lcm_get_panel_lock(void);
#if defined CONFIG_HONOR_DSM
struct dsm_client *lcd_kit_get_lcd_dsm_client(void);
#endif
#endif
