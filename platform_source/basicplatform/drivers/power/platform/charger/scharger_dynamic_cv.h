#ifndef __SCHARGER_DYNAMIC_CV_H__
#define __SCHARGER_DYNAMIC_CV_H__

#include <linux/printk.h>
#include <linux/notifier.h>
#include <linux/workqueue.h>
#include <linux/power_supply.h>
#include <securec.h>
#include <linux/delay.h>
#include <linux/platform_device.h>
#include <linux/platform_drivers/usb/chip_usb.h>
#include <platform_include/basicplatform/linux/power/platform/coul/coul_drv.h>
#include <platform_include/basicplatform/linux/power/platform/bci_battery.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_device.h>
#include <linux/sort.h>
#ifdef CONFIG_HUAWEI_DSM
#include <chipset_common/hwpower/common_module/power_dsm.h>
#endif

#define scharger_cv_err(fmt, args...) pr_err("[scharger_cv]" fmt, ## args)
#define scharger_cv_evt(fmt, args...) pr_warn("[scharger_cv]" fmt, ## args)
#define scharger_cv_inf(fmt, args...) pr_info("[scharger_cv]" fmt, ## args)
#define scharger_cv_dbg(fmt, args...) pr_debug("[scharger_cv]" fmt, ## args)

#define SAMPLE_CYCLE_MS              3000
#define CALCU_CYCLE_MS               1000
#define JUDGE_TRIM_COMPLETE_CYCLE_MS 1000

#define CV_IBAT_MIN_DEFAULT          10
#define COUL_PRECISION_TEMP_HIGH     35
#define COUL_PRECISION_TEMP_LOW      15

#define DATA_COUNT                   10

#define RETRY_COUNT                  30

#define BATT_CAP_97                  97

#define PERMILLAGE                   1000
#define CV_PROTECT_MARGIN            2
#define CV_PROTECT_CNT               5

enum scharger_cv_state {
	CV_IDLE = 0,
	CV_WORKING,
	CV_ABNORMAL,
};

struct scharger_cv_device_info {
	struct device *dev;
	struct notifier_block chg_nb;
	struct delayed_work get_data_work;
	struct delayed_work calcu_trim_val_work;
	struct delayed_work safety_protect_work;
	int cv_sample_count;
	int cv_ori;
	int cv_ori_new;
	int cv_new_set;
	int batt_vol[DATA_COUNT];
	int first_sample_flag;
	int vbat_average;
	int vbat_max;
	int ibat_thre;
	int vbat_max_margin;
	int delta_cv_max;
	enum scharger_cv_state working_flag;
	int protect_cnt;
	int cv_ibat_min_thre;
};

struct scharger_cv_ops {
	int (*get_charge_done_state)(void);
	int (*get_chg_mode)(void);
	int (*get_chg_enable)(void);
	int (*get_vterm)(void);
	int (*set_vterm)(int cv_ori, int cv_new_set);
	void (*clear_cv_trim_flag)(void);
	void (*reset_cv_value)(void);
};

struct cv_info {
	int cv_ori_val;
	int cv_new_set_val;
	int cv_trim_flag;
};

int scharger_cv_ops_register(struct scharger_cv_ops *ops);
#endif
