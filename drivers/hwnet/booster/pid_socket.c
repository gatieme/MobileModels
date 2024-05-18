/*copyright (c) Honor Technologies Co., Ltd. 1998-2014. All rights reserved.
 *
 * File name: pid_socket.c
 * Description: This file use to record pid and socket
 * Author: xishiying@honor.com
 * Version: 0.1
 * Date:  2014/11/27
 */

#include <linux/rcupdate.h>
#include <linux/sched.h>
#include <linux/version.h>
#include <net/sock.h>
#include <net/tcp.h>
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 14,0 )
#include <linux/sched/task.h>
#endif

#include <../../../include/log/log_usertype.h>
#include "pid_socket.h"
#include <linux/pid_namespace.h>	/* For task_active_pid_ns.  */

void print_process_pid_name(struct inet_sock *inet)
{
	int pid = 0;
	int uid = 0;
	unsigned short source_port = 0;
	struct task_struct *task = NULL;
	struct pid_namespace *ns = NULL;
#ifdef CONFIG_LOG_EXCEPTION
	unsigned int user_type = get_logusertype_flag();

	if (user_type != BETA_USER && user_type != OVERSEA_USER)
		return;
#endif

#if defined(CONFIG_KSTATE_COMMON) || defined(CONFIG_MPTCP)
	if (NULL == inet || NULL == inet->sk.sk_socket) {
		return;
	}

	pid = inet->sk.sk_socket->pid;
#else
	if (NULL == inet) {
		return;
	}

	pid = task_tgid_nr(current);
#endif

#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 1, 10)
	uid = sock_i_uid(&inet->sk).val;
#else
	uid = sock_i_uid(&inet->sk);
#endif
	source_port = inet->inet_sport;
	source_port = htons(source_port);

	if (pid <= 0) {
		printk("pid=0,%s:uid:%d,pid:%d,port:%d\n", __func__, uid, pid, source_port);
		return;
	}

	rcu_read_lock();
	ns = task_active_pid_ns(current);
	if (ns == NULL) {
		rcu_read_unlock();
		printk("ns=NULL,%s:uid:%d,pid:%d,port:%d\n", __func__, uid, pid, source_port);
		return;
	}

	// warning: do not use find_task_by_vpid(pid) here, it may cause crash after kernel 5.4
	task = find_task_by_pid_ns(pid, ns);
	if (task == NULL) {
		rcu_read_unlock();
		printk("task=NULL,%s:uid:%d,pid:%d,port:%d\n", __func__, uid, pid, source_port);
		return;
	}
	get_task_struct(task);
	rcu_read_unlock();

	printk("%s: uid:%d,pid:(%d),name:(%s),port:(%d)\n", __func__, uid, pid, task->comm, source_port);
	put_task_struct(task);
}
