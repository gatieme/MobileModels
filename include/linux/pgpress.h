/*
 * Copyright (c) Honor Technologies Co., Ltd. 2022. All rights reserved.
 * Description: According to workingset refault, add pgpress for I/O performence.
 * Created by yangpanfei
 * Create:  2022-07-14
 */
#ifndef _PG_PGPRESS_H
#define _PG_PGPRESS_H

enum pg_fs_type {
	FS_TYPE_INVALID = 0,
	FS_TYPE_F2FS,
	FS_TYPE_EROFS,
	FS_TYPE_EXT4,
	FS_TYPE_OTHER,
};

struct pgcache_proc_node {
	const char * name;
	umode_t mode;
	// const struct file_operations *proc_fops;
	const struct proc_ops *proc_fops;
};

struct pgpress_stats {
	unsigned long start_time;
	unsigned long quota;
	unsigned long pgpress;
};
void refault_monitor(void);
void readahead_adaptive(struct file *file, struct vm_fault *vmf, bool buffer);
int swappniess_adaptive(int swappiness);
inline int get_pgpress(void);
#endif
