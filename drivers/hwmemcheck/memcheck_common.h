#ifndef _MEMCHECK_COMMON_H
#define _MEMCHECK_COMMON_H

#include <linux/types.h>
#include <chipset_common/hwmemcheck/memcheck.h>

#define TEST_BIT(v, i) ((v) & (1 << (i)))
#define	memcheck_err(format, ...)	\
	pr_err("MemLeak[%s %d] " format, __func__, __LINE__, ##__VA_ARGS__)
#define	memcheck_info(format, ...)	\
	pr_info("MemLeak[%s %d] " format, __func__, __LINE__, ##__VA_ARGS__)

struct mm_slub_detail_info {
	char name[MEMCHECK_MEM_NAME_MAX];
	unsigned long active_objs;
	unsigned long num_objs;
	unsigned long active_slabs;
	unsigned long num_slabs;
	unsigned long size; /* total size */
	unsigned int objects_per_slab;
	unsigned int objsize;
};

struct mm_ion_detail_info {
	pid_t pid;
	size_t size;
};

struct mm_vmalloc_detail_info {
	int type;
	size_t size;
};

struct memstat_all;
struct memstat_kernel;
struct track_cmd;
struct detail_info;
struct stack_info;
struct lmk_oom_read;
struct lmk_oom_write;
struct task_type_read;

unsigned short memcheck_get_memstat(const void *buf, struct memstat_all *p);
int memcheck_do_command(const struct track_cmd *cmd);
void memcheck_save_top_slub(const char *name);
int memcheck_detail_read(void *buf, struct detail_info *info);
int memcheck_stack_read(void *buf, struct stack_info *info);
int memcheck_stack_write(const void *buf, const struct stack_info *info);
int memcheck_stack_clear(void);
int memcheck_lmk_oom_read(void *buf, struct lmk_oom_read *rec);
int memcheck_lmk_oom_write(const struct lmk_oom_write *write);
int memcheck_get_task_type(void *buf, struct task_type_read *read);
int memcheck_wait_stack_ready(u16 type);
size_t get_ion_by_pid(pid_t pid);
static inline size_t get_mem_total(int type)
{
	return 0;
}
static inline int buddy_track_unmap(void)
{
	return 0;
}
static inline size_t get_mem_detail(int type, void *buf, size_t len)
{
	return 0;
}
#endif /* _MEMCHECK_COMMON_H */