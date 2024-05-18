
#ifndef __HONOR_RTC_TIME_DAEMON_H__
#define __HONOR_RTC_TIME_DAEMON_H__

#include <linux/platform_device.h>
#include <linux/rtc.h>

int honor_rtc_time_daemon_init(struct device *dev);
const struct rtc_class_ops* get_honor_rtc_time_daemon_rw_ops(
                const struct rtc_class_ops *qpnp_rtc_rw_ops_ptr);
#endif
