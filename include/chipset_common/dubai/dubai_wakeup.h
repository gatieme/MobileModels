#ifndef DUBAI_WAKEUP_H
#define DUBAI_WAKEUP_H

#include <linux/types.h>

#define DUBAI_WAKEUP_NUM_MAX					10
#define DUBAI_WAKEUP_TAG_LENGTH					48
#define DUBAI_WAKEUP_MSG_LENGTH					128
#define SUBSYSTEM_POWER_STATS_MAX_CLK_LEVELS    16
#define MAX_NAME_LENGTH                         16
#define SUBSYSTEM_STATS_NUM                     10
#define SOC_STATS_NUM                           3
#define MAX_CLK_NAME_LENGTH 					64

enum dubai_wakeup_type {
	DUBAI_WAKEUP_TYPE_INVALID = 0,
	DUBAI_WAKEUP_TYPE_RTC,
	DUBAI_WAKEUP_TYPE_GPIO,
	DUBAI_WAKEUP_TYPE_OTHERS,
};

struct dubai_wakeup_info {
	enum dubai_wakeup_type type;
	char tag[DUBAI_WAKEUP_TAG_LENGTH];
	char msg[DUBAI_WAKEUP_MSG_LENGTH];
};

struct dubai_sysmon_freq_time {
	int64_t freq;
	int64_t time;
} __packed;

struct dubai_sysmon_time_in_state {
	char tag[DUBAI_WAKEUP_TAG_LENGTH];
	int64_t pc_time;
	int64_t  lpi_time;
	struct dubai_sysmon_freq_time freq_time[SUBSYSTEM_POWER_STATS_MAX_CLK_LEVELS];
} __packed;

struct dubai_sysmon_stats {
	struct dubai_sysmon_time_in_state sysmon_stats[3];
} __packed;

struct honor_sleep_stats {
	char name[MAX_NAME_LENGTH];
	u32 stat_type;
	u32 count;
	u64 last_entered_at;
	u64 last_exited_at;
	u64 accumulated;
} __packed;

struct dubai_sleep_stats {
	struct honor_sleep_stats rpmh_stats[SUBSYSTEM_STATS_NUM];
	struct honor_sleep_stats soc_stats[SOC_STATS_NUM];
} __packed;

struct dubai_clock_name {
	char name[MAX_CLK_NAME_LENGTH];
} __packed;

struct dubai_clock_transmit {
	unsigned long long timestamp;
	int count;
	char value[0];
} __packed;

typedef int (*dubai_suspend_notify_fn_t)(unsigned long mode);
typedef int (*dubai_wakeup_stats_fn_t)(struct dubai_wakeup_info *data, size_t num);
typedef int (*dubai_get_sysmon_stats_fn_t)(struct dubai_sysmon_stats *data);
typedef int (*dubai_get_subsystem_sleep_stats_fn_t)(struct honor_sleep_stats *rpmh_data, struct honor_sleep_stats *soc_data);
typedef int (*dubai_get_clock_num_fn_t)(void);
typedef int (*dubai_get_clock_stats_fn_t)(struct dubai_clock_transmit *transmit);

struct dubai_wakeup_stats_ops {
	dubai_suspend_notify_fn_t suspend_notify;
	dubai_wakeup_stats_fn_t get_stats;
	dubai_get_sysmon_stats_fn_t get_sysmon_stats;
	dubai_get_subsystem_sleep_stats_fn_t get_subsystem_sleep_stats;
	dubai_get_clock_num_fn_t get_clock_num;
	dubai_get_clock_stats_fn_t get_clock_stats;
};

extern void dubai_wakeup_notify(const char *source);

#endif // DUBAI_WAKEUP_H
