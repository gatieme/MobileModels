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
#include <linux/fdtable.h>
#ifndef CONFIG_BOOT_DETECTOR_GKI
#include <linux/file.h>
#endif
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

#ifndef CONFIG_BOOT_DETECTOR_GKI

static int do_statfs_native(struct kstatfs *st, struct statfs __user *p)
{
	struct statfs buf;

	if (sizeof(buf) == sizeof(*st))
		memcpy(&buf, st, sizeof(*st));
	else {
		if (sizeof buf.f_blocks == 4) {
			if ((st->f_blocks | st->f_bfree | st->f_bavail |
			     st->f_bsize | st->f_frsize) &
			    0xffffffff00000000ULL)
				return -EOVERFLOW;
			/*
			 * f_files and f_ffree may be -1; it's okay to stuff
			 * that into 32 bits
			 */
			if (st->f_files != -1 &&
			    (st->f_files & 0xffffffff00000000ULL))
				return -EOVERFLOW;
			if (st->f_ffree != -1 &&
			    (st->f_ffree & 0xffffffff00000000ULL))
				return -EOVERFLOW;
		}

		buf.f_type = st->f_type;
		buf.f_bsize = st->f_bsize;
		buf.f_blocks = st->f_blocks;
		buf.f_bfree = st->f_bfree;
		buf.f_bavail = st->f_bavail;
		buf.f_files = st->f_files;
		buf.f_ffree = st->f_ffree;
		buf.f_fsid = st->f_fsid;
		buf.f_namelen = st->f_namelen;
		buf.f_frsize = st->f_frsize;
		buf.f_flags = st->f_flags;
		memset(buf.f_spare, 0, sizeof(buf.f_spare));
	}
	if (copy_to_user(p, &buf, sizeof(buf)))
		return -EFAULT;
	return 0;
}

#if BITS_PER_LONG == 32
#  define choose_32_64(a,b) a
#else
#  define choose_32_64(a,b) b
#endif

#define valid_dev(x)  choose_32_64(old_valid_dev(x),true)
#define encode_dev(x) choose_32_64(old_encode_dev,new_encode_dev)(x)
#ifndef INIT_STRUCT_STAT_PADDING
#  define INIT_STRUCT_STAT_PADDING(st) memset(&st, 0, sizeof(st))
#endif

static int cp_new_stat(struct kstat *stat, struct stat __user *statbuf)
{
	struct stat tmp;

	if (!valid_dev(stat->dev) || !valid_dev(stat->rdev))
		return -EOVERFLOW;
#if BITS_PER_LONG == 32
	if (stat->size > MAX_NON_LFS)
		return -EOVERFLOW;
#endif

	INIT_STRUCT_STAT_PADDING(tmp);
	tmp.st_dev = encode_dev(stat->dev);
	tmp.st_ino = stat->ino;
	if (sizeof(tmp.st_ino) < sizeof(stat->ino) && tmp.st_ino != stat->ino)
		return -EOVERFLOW;
	tmp.st_mode = stat->mode;
	tmp.st_nlink = stat->nlink;
	if (tmp.st_nlink != stat->nlink)
		return -EOVERFLOW;
	SET_UID(tmp.st_uid, from_kuid_munged(current_user_ns(), stat->uid));
	SET_GID(tmp.st_gid, from_kgid_munged(current_user_ns(), stat->gid));
	tmp.st_rdev = encode_dev(stat->rdev);
	tmp.st_size = stat->size;
	tmp.st_atime = stat->atime.tv_sec;
	tmp.st_mtime = stat->mtime.tv_sec;
	tmp.st_ctime = stat->ctime.tv_sec;
#ifdef STAT_HAVE_NSEC
	tmp.st_atime_nsec = stat->atime.tv_nsec;
	tmp.st_mtime_nsec = stat->mtime.tv_nsec;
	tmp.st_ctime_nsec = stat->ctime.tv_nsec;
#endif
	tmp.st_blocks = stat->blocks;
	tmp.st_blksize = stat->blksize;
	return copy_to_user(statbuf,&tmp,sizeof(tmp)) ? -EFAULT : 0;
}

#ifndef INIT_STRUCT_STAT64_PADDING
#  define INIT_STRUCT_STAT64_PADDING(st) memset(&st, 0, sizeof(st))
#endif

static long cp_new_stat64(struct kstat *stat, struct stat64 __user *statbuf)
{
	struct stat64 tmp;

	INIT_STRUCT_STAT64_PADDING(tmp);
#ifdef CONFIG_MIPS
	/* mips has weird padding, so we don't get 64 bits there */
	tmp.st_dev = new_encode_dev(stat->dev);
	tmp.st_rdev = new_encode_dev(stat->rdev);
#else
	tmp.st_dev = huge_encode_dev(stat->dev);
	tmp.st_rdev = huge_encode_dev(stat->rdev);
#endif
	tmp.st_ino = stat->ino;
	if (sizeof(tmp.st_ino) < sizeof(stat->ino) && tmp.st_ino != stat->ino)
		return -EOVERFLOW;
#ifdef STAT64_HAS_BROKEN_ST_INO
	tmp.__st_ino = stat->ino;
#endif
	tmp.st_mode = stat->mode;
	tmp.st_nlink = stat->nlink;
	tmp.st_uid = from_kuid_munged(current_user_ns(), stat->uid);
	tmp.st_gid = from_kgid_munged(current_user_ns(), stat->gid);
	tmp.st_atime = stat->atime.tv_sec;
	tmp.st_atime_nsec = stat->atime.tv_nsec;
	tmp.st_mtime = stat->mtime.tv_sec;
	tmp.st_mtime_nsec = stat->mtime.tv_nsec;
	tmp.st_ctime = stat->ctime.tv_sec;
	tmp.st_ctime_nsec = stat->ctime.tv_nsec;
	tmp.st_size = stat->size;
	tmp.st_blocks = stat->blocks;
	tmp.st_blksize = stat->blksize;
	return copy_to_user(statbuf,&tmp,sizeof(tmp)) ? -EFAULT : 0;
}

#if (LINUX_VERSION_CODE != KERNEL_VERSION(5, 4, 190))
static off_t ksys_lseek(unsigned int fd, off_t offset, unsigned int whence)
{
	off_t retval;
	struct fd f = fdget_pos(fd);
	if (!f.file)
		return -EBADF;

	retval = -EINVAL;
	if (whence <= SEEK_MAX) {
		loff_t res = vfs_llseek(f.file, offset, whence);
		retval = res;
		if (res != (loff_t)retval)
			retval = -EOVERFLOW;	/* LFS: should only happen on 32 bit platforms */
	}
	fdput_pos(f);
	return retval;
}
#endif

static int do_fsync(unsigned int fd, int datasync)
{
	struct fd f = fdget(fd);
	int ret = -EBADF;

	if (f.file) {
		ret = vfs_fsync(f.file, datasync);
		fdput(f);
		inc_syscfs(current);
	}
	return ret;
}

long ksys_fsync(unsigned int fd)
{
	return (long)do_fsync(fd, 0);
}

long ksys_statfs(const char __user * path, struct statfs __user *buf)
{
	struct kstatfs st;
	int error = user_statfs(path, &st);
	if (!error)
		error = do_statfs_native(&st, buf);
	return (long)error;
}

long ksys_newlstat(const char __user *filename, struct stat __user *statbuf)
{
	struct kstat stat;
	int error;

	error = vfs_lstat(filename, &stat);
	if (error)
		return error;

	return cp_new_stat(&stat, statbuf);
}

long ksys_lstat64(const char __user *filename, struct stat64 __user *statbuf)
{
	struct kstat stat;
	int error = vfs_lstat(filename, &stat);

	if (!error)
		error = cp_new_stat64(&stat, statbuf);

	return error;
}

#if (LINUX_VERSION_CODE != KERNEL_VERSION(5, 4, 190))
static inline long ksys_open(const char __user *filename, int flags,
			     umode_t mode)
{
	if (force_o_largefile())
		flags |= O_LARGEFILE;
	return do_sys_open(AT_FDCWD, filename, flags, mode);
}
#endif

#endif /* CONFIG_BOOT_DETECTOR_GKI */

long bf_sys_read(unsigned int fd, char __user *buf, size_t count)
{
#if LINUX_VERSION_CODE < KERNEL_VERSION(4,19,0)
	return sys_read(fd, buf, count);
#else
#ifndef CONFIG_ARCH_HAS_SYSCALL_WRAPPER
	return sys_read(fd, buf, count);
#else
#ifdef CONFIG_BOOT_DETECTOR_GKI
	return 0;
#else
	return ksys_read(fd, buf, count);
#endif /* CONFIG_BOOT_DETECTOR_GKI */
#endif
#endif
}

long bf_sys_write(unsigned int fd, char __user *buf, size_t count)
{
#if LINUX_VERSION_CODE < KERNEL_VERSION(4,19,0)
	return sys_write(fd, buf, count);
#else
#ifndef CONFIG_ARCH_HAS_SYSCALL_WRAPPER
	return sys_write(fd, buf, count);
#else
#ifdef CONFIG_BOOT_DETECTOR_GKI
	return 0;
#else
	return ksys_write(fd, buf, count);
#endif /* CONFIG_BOOT_DETECTOR_GKI */
#endif
#endif
}

long bf_sys_open(const char __user *filename, int flags, umode_t mode)
{
#if LINUX_VERSION_CODE < KERNEL_VERSION(4,19,0)
	return sys_open(filename, flags, mode);
#else
#ifndef CONFIG_ARCH_HAS_SYSCALL_WRAPPER
	return sys_open(filename, flags, mode);
#else
#ifdef CONFIG_BOOT_DETECTOR_GKI
	return 0;
#else
	return ksys_open(filename, flags, mode);
#endif /* CONFIG_BOOT_DETECTOR_GKI */
#endif
#endif
}

long bf_sys_lseek(unsigned int fd, off_t offset, unsigned int whence)
{
#if LINUX_VERSION_CODE < KERNEL_VERSION(4,19,0)
	return sys_lseek(fd, offset, whence);
#else
#ifndef CONFIG_ARCH_HAS_SYSCALL_WRAPPER
	return sys_lseek(fd, offset, whence);
#else
#ifdef CONFIG_BOOT_DETECTOR_GKI
	return 0;
#else
	return ksys_lseek(fd, offset, whence);
#endif /* CONFIG_BOOT_DETECTOR_GKI */
#endif
#endif
}

long bf_sys_sync(void)
{
#if LINUX_VERSION_CODE < KERNEL_VERSION(4,19,0)
	return sys_sync();
#else
#ifndef CONFIG_ARCH_HAS_SYSCALL_WRAPPER
	return sys_sync();
#else
#ifndef CONFIG_BOOT_DETECTOR_GKI
	ksys_sync();
#endif /* CONFIG_BOOT_DETECTOR_GKI */
	return 0;
#endif
#endif
}

long bf_sys_close(unsigned int fd)
{
#if LINUX_VERSION_CODE < KERNEL_VERSION(4,19,0)
	return sys_close(fd);
#else
#ifndef CONFIG_ARCH_HAS_SYSCALL_WRAPPER
	return sys_close(fd);
#else
#ifdef CONFIG_BOOT_DETECTOR_GKI
	return 0;
#else
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 15, 0))
	return close_fd(fd);
#else
	return ksys_close(fd);
#endif
#endif
#endif
#endif
}

long bf_sys_fsync(unsigned int fd)
{
#if LINUX_VERSION_CODE < KERNEL_VERSION(4,19,0)
	return sys_fsync(fd);
#else
#ifndef CONFIG_ARCH_HAS_SYSCALL_WRAPPER
	return sys_fsync(fd);
#else
#ifdef CONFIG_BOOT_DETECTOR_GKI
	return 0;
#else
	return ksys_fsync(fd);
#endif
#endif
#endif
}

long bf_sys_statfs(const char __user * path, struct statfs __user *buf)
{
#if LINUX_VERSION_CODE < KERNEL_VERSION(4,19,0)
	return sys_statfs(path, buf);
#else
#ifndef CONFIG_ARCH_HAS_SYSCALL_WRAPPER
	return sys_statfs(path, buf);
#else
#ifdef CONFIG_BOOT_DETECTOR_GKI
	return 0;
#else
	return ksys_statfs(path, buf);
#endif
#endif
#endif
}

long bf_sys_lstat64(const char __user *filename, struct stat64 __user *statbuf)
{
#if LINUX_VERSION_CODE < KERNEL_VERSION(4,19,0)
	return sys_lstat64(filename, statbuf);
#else
#ifndef CONFIG_ARCH_HAS_SYSCALL_WRAPPER
	return sys_lstat64(filename, statbuf);
#else
#ifdef CONFIG_BOOT_DETECTOR_GKI
	return 0;
#else
	return ksys_lstat64(filename, statbuf);
#endif
#endif
#endif
}

long bf_sys_newlstat(const char __user *filename, struct stat __user *statbuf)
{
#if LINUX_VERSION_CODE < KERNEL_VERSION(4,19,0)
	return sys_newlstat(filename, statbuf);
#else
#ifndef CONFIG_ARCH_HAS_SYSCALL_WRAPPER
	return sys_newlstat(filename, statbuf);
#else
#ifdef CONFIG_BOOT_DETECTOR_GKI
	return 0;
#else
	return ksys_newlstat(filename, statbuf);
#endif
#endif
#endif
}

long bf_lstat(const char __user *filename, void __user *statbuf)
{
#if BITS_PER_LONG == 32
	return bf_sys_lstat64(filename, (struct stat64 __user *)statbuf);
#else
	return bf_sys_newlstat(filename, (struct stat __user *)statbuf);
#endif
}

