

#include <linux/version.h>
#include <linux/fdtable.h>
#include <linux/file.h>
#include <linux/net.h>
#include <net/sock.h>

static struct file *fget_by_pid(unsigned int fd, pid_t pid)
{
	struct file *file = NULL;
	struct task_struct *task = NULL;
	struct files_struct *files = NULL;

	rcu_read_lock();
	task = find_task_by_vpid(pid);
	if (!task) {
		rcu_read_unlock();
		return NULL;
	}
	get_task_struct(task);
	rcu_read_unlock();
	files = task->files;

	/* process is removed, task isn't null, but files is null */
	if (files == NULL) {
		put_task_struct(task);
		return NULL;
	}
	put_task_struct(task);
	rcu_read_lock();
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 15, 0)
		file = files_lookup_fd_locked(files, fd);
#else
		file = fcheck_files(files, fd);
#endif
	if (file) {
		/* File object ref couldn't be taken */
		if ((file->f_mode & FMODE_PATH) ||
			!atomic_long_inc_not_zero(&file->f_count))
			file = NULL;
	}
	rcu_read_unlock();

	return file;
}

struct socket *sockfd_lookup_by_fd_pid(int fd, pid_t pid, int *err)
{
	struct file *file = NULL;
	struct socket *sock = NULL;

	file = fget_by_pid(fd, pid);
	if (!file) {
		*err = -EBADF;
		return NULL;
	}

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 15, 0)
		sock = sock_from_file(file);
#else
		sock = sock_from_file(file, err);
#endif
	if (!sock)
		fput(file);

	return sock;
}

/*
 * get_sock_by_fd_pid() - get the sock.
 * @fd: file descriptor.
 * @pid: process id.
 *
 * invoke the sockfd_lookup_by_fd_pid() to get the sock.
 *
 * Return: sock, success.
 * NULL means fail.
 */
struct sock *get_sock_by_fd_pid(int fd, pid_t pid)
{
	int err = 0;
	struct socket *sock = NULL;
	struct sock *sk = NULL;

	sock = sockfd_lookup_by_fd_pid(fd, pid, &err);
	if (sock == NULL)
		return NULL;

	sk = sock->sk;
	if (sk != NULL)
		sock_hold(sk);

	if (sock->file != NULL)
		sockfd_put(sock);

	return sk;
}

