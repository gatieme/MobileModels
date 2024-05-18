#include "../rasbase/rasbase.h"
#include "rasproc.h"

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
int proc_init(char *name, const struct proc_ops *proc_ops, void *data)
#else
int proc_init(char *name, const struct file_operations *proc_ops, void *data)
#endif
{
	struct proc_dir_entry *pde = 0;

	if (name == 0)
		ras_retn(-ENOMEM);
	pde = proc_create_data(name, S_IFREG | 0666, 0, proc_ops, data);
	if (unlikely(0 == pde))
		ras_retn(-ENOMEM);
	return 0;
}

void proc_exit(const char *name)
{
	remove_proc_entry(name, 0);
}
