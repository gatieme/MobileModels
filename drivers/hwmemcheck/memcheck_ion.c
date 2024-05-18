#include <linux/fdtable.h>
#include <linux/version.h>
#include <linux/sched/task.h>
#include  <linux/dma-buf.h>

#if defined(CONFIG_ION) || defined(CONFIG_MTK_ION)
	extern bool is_ion_dma_buf(struct dma_buf *dmabuf);
#endif

// To decouple with mem_track, copy some ion function from mm_ion_dump.c
static struct dma_buf * file_to_dma_buf(struct file *file)
{
	return file->private_data;
}

/* this func must be in ion.c */
static inline void *get_ion_buf(struct dma_buf *dbuf)
{
	return dbuf->priv;
}

static size_t mm_ion_detail_cb(const void *data,
	struct file *f, unsigned int fd)
{
	struct dma_buf *dbuf = NULL;
	void *ibuf = NULL;

	if (!is_dma_buf_file(f))
		return 0;

	dbuf = file_to_dma_buf(f);
	if (!dbuf)
		return 0;

#if defined(CONFIG_ION) || defined(CONFIG_MTK_ION)
	if (!is_ion_dma_buf(dbuf))
		return 0;
#endif

	ibuf = get_ion_buf(dbuf);
	if (!ibuf)
		return 0;

	return dbuf->size;
}

static size_t ion_iterate_fd(struct files_struct *files, unsigned int n,
	size_t (*f)(const void *, struct file *, unsigned int), const void *p)
{
	struct fdtable *fdt = NULL;
	size_t res = 0;
	struct file *file = NULL;

	if (!files)
		return 0;
	spin_lock(&files->file_lock);
	for (fdt = files_fdtable(files); n < fdt->max_fds; n++) {
		file = rcu_dereference_check_fdtable(files, fdt->fd[n]);
		if (!file)
			continue;
		res += f(p, file, n);
	}
	spin_unlock(&files->file_lock);
	return res;
}

size_t get_ion_by_pid(pid_t pid)
{
	size_t size;
	struct task_struct *tsk = NULL;

	rcu_read_lock();
	tsk = find_task_by_vpid(pid);
	if (!tsk) {
		rcu_read_unlock();
		return 0;
	}
	if (tsk->flags & PF_KTHREAD) {
		rcu_read_unlock();
		return 0;
	}
	task_lock(tsk);
	size = ion_iterate_fd(tsk->files, 0,
		mm_ion_detail_cb, (void *)tsk);
	task_unlock(tsk);

	rcu_read_unlock();
	return size;
}
EXPORT_SYMBOL(get_ion_by_pid);

