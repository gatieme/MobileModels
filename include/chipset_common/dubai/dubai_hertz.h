#ifndef DUBAI_HERTZ_H
#define DUBAI_HERTZ_H

#include <linux/types.h>

struct dubai_hertz_info {
  uint32_t enter_worke_mode_number;
  uint32_t enter_sleep_mode_number;
  uint32_t run_time_in_worke_mode;
  uint32_t event_number_in_worke_mode;
} __packed;

typedef int32_t (*dubai_get_hertz_info_fn_t)(struct dubai_hertz_info *hertz_info);

struct dubai_hertz_stats_ops {
	dubai_get_hertz_info_fn_t get_hertz_info;
};

#endif // DUBAI_HERTZ_H
