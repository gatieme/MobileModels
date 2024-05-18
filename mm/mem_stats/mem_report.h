/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __MEM_REPORT_H__
#define __MEM_REPORT_H__

#ifdef CONFIG_MEM_STATS
extern unsigned long free_page_min;
extern unsigned long used_page_max;
extern unsigned long isolated_threshold;
void mem_alloc_report(const char *device_type, const char *device_name, size_t len,
				const char *reason, u64 wait_ms);
void mem_anomal_report(const char *anomal_name, unsigned long len, unsigned long threshold, unsigned int *nr);
void buddyinfo_report(void);
void isolated_detect(int file, unsigned long inactive, unsigned long isolated);
void page_detect(void);
#else
static inline void mem_alloc_report(const char *device_type, const char *device_name, size_t len,
				const char *reason, u64 wait_ms) {}
static inline void mem_anomal_report(const char *anomal_name, unsigned long len,
				unsigned long threshold, unsigned int *nr) {}
static inline void buddyinfo_report(void) {}
static inline void isolated_detect(int file, unsigned long inactive, unsigned long isolated) {}
static inline void page_detect(void) {}
#endif

#endif /* __MEM_REPORT_H__ */