#include <linux/net.h>

#ifndef __PERF_BUFFERED_LOG_SENDER_H__
#define __PERF_BUFFERED_LOG_SENDER_H__

#define S_TO_MS 1000
#define NS_TO_MS 1000000
// limit perf buffered log entry to 50KB
#define MAX_PERF_LOG_LENGTH 51200

struct perf_buffered_log_entry {
	int length;
	int magic;
	int count;
	long long time;
	unsigned char data[0];
};

int send_perf_buffered_log_entry(const struct perf_buffered_log_entry *entry);
struct perf_buffered_log_entry *perf_create_log_entry(int size, int magic, int count);
void free_perf_buffered_log_entry(struct perf_buffered_log_entry *entry);
void perf_buffered_log_release(void);
int cal_log_entry_len(size_t head, size_t info, int count);

#endif // __PERF_BUFFERED_LOG_SENDER_H__
