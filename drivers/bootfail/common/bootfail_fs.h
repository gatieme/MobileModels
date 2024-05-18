/*
 * Copyright (c) Honor Device Co., Ltd. 2019-2019. All rights reserved.
 * Description: implement the chipsets's common interface of HONOR
 * Author: qidechun
 * Create: 2019-03-05
 */

/* ---- includes ---- */
#include <linux/device.h>
#include <linux/errno.h>
#include <linux/kprobes.h>
#include <linux/miscdevice.h>
#include <linux/platform_device.h>
#include <linux/fs.h>
#include <linux/ioport.h>
#include <linux/io.h>
#include <linux/uaccess.h>
#include <linux/syscalls.h>
#include <linux/sched/xacct.h>
//#include <linux/kdev_t.h>
#include <linux/kthread.h>
#include <linux/vmalloc.h>
#include <linux/delay.h>
#include <linux/semaphore.h>
#include <linux/statfs.h>
#include <linux/version.h>
#include <bootfail/chipsets/common/bootfail_common.h>
#include <bootfail/chipsets/common/bootfail_timer.h>
#include <bootfail/chipsets/common/bootfail_chipsets.h>
#include <bootfail/core/boot_detector.h>
#ifdef CONFIG_HONOR_DYNAMIC_BRD
#include <chipset_common/storage_rofa/dynbrd_public.h>
#endif
#ifdef CONFIG_HONOR_STORAGE_ROFA
#include <chipset_common/storage_rofa/storage_rofa.h>
#endif


#ifdef CONFIG_BOOT_DETECTOR_GKI

void bf_ksys_ops_init(void);

#endif /* CONFIG_BOOT_DETECTOR_GKI */

long bf_sys_read(unsigned int fd, char __user *buf, size_t count);

long bf_sys_write(unsigned int fd, char __user *buf, size_t count);

long bf_sys_open(const char __user *filename, int flags, umode_t mode);

long bf_sys_lseek(unsigned int fd, off_t offset, unsigned int whence);

long bf_sys_sync(void);

long bf_sys_close(unsigned int fd);

long bf_sys_fsync(unsigned int fd);

long bf_sys_statfs(const char __user * path, struct statfs __user *buf);

long bf_sys_lstat64(const char __user *filename, struct stat64 __user *statbuf);

long bf_sys_newlstat(const char __user *filename, struct stat __user *statbuf);

long bf_lstat(const char __user *filename, void __user *statbuf);

