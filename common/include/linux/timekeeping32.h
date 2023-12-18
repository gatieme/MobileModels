#ifndef _LINUX_TIMEKEEPING32_H
#define _LINUX_TIMEKEEPING32_H
/*
 * These interfaces are all based on the old timespec type
 * and should get replaced with the timespec64 based versions
 * over time so we can remove the file here.
 */

static inline unsigned long get_seconds(void)
{
	return ktime_get_real_seconds();
}

static inline void getnstimeofday(struct timespec64 *ts)
{
        struct timespec64 ts64;
 
        ktime_get_real_ts64(&ts64);
        *ts = *(const struct timespec64 *)&ts64;
}

#endif