#ifndef __PERF_IOCTL_H__
#define __PERF_IOCTL_H__

#include <linux/ioctl.h>

#define IOC_GET_THREAD_STATUS _IOW(IOC_THREAD_STATUS, 1, int)
#define IOC_GET_PROCESS_CPUTIME _IO(IOC_PROCESS_CPUTIME, 1)
#define IOC_SET_CPU_DIMPS _IOW(IOC_PROCESS_CPUTIME, 1, struct ioctl_message)

#define IOCRL_MAX_NUM 20

enum perf_ioctl_type_t {
	IOC_THREAD_STATUS = 0,
	IOC_PROCESS_CPUTIME = 1,
};

struct ioctl_message {
	int count;
	int data[IOCRL_MAX_NUM];
};

#endif // __PERF_IOCTL_H__
