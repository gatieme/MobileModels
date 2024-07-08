#include <asm/compiler.h>
#include <linux/compiler.h>
#include <linux/fd.h>
#include <linux/tty.h>
#include <linux/fs.h>
#include <linux/fcntl.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <linux/syscalls.h>
#include <linux/device.h>
#include <linux/dma-mapping.h>
#include <linux/semaphore.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/types.h>
#include <linux/io.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_reserved_mem.h>
#include <linux/of_device.h>
#include <linux/of_platform.h>
#include <linux/delay.h>
#include <linux/timer.h>
#include <linux/atomic.h>
#include <linux/notifier.h>
#include <linux/printk.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/interrupt.h>
#include <linux/hisi/ipc_msg.h>
#include <linux/hisi/hisi_rproc.h>
#include <linux/hisi/kirin_partition.h>
#include <linux/clk.h>
#include <linux/mm.h>
#include "soc_acpu_baseaddr_interface.h"
#include "soc_sctrl_interface.h"
#include "hisi_hisee.h"
#include "hisi_hisee_fs.h"
#include "hisi_hisee_power.h"

hisee_powerctrl_status powerctrl_status;

static bool g_daemon_created = false;
static int g_unhandled_timer_cnt = 0;
static struct semaphore g_hisee_poweroff_sem;
static struct mutex g_poweron_timeout_mutex;
static struct list_head g_unhandled_timer_list;

void hisee_power_ctrl_init(void) {
	powerctrl_status = HISEE_POWER_NONE;
	mutex_init(&g_poweron_timeout_mutex);
	g_unhandled_timer_cnt = 0;
	INIT_LIST_HEAD(&g_unhandled_timer_list);
}

static int set_hisee_state(hisee_state state)
{
	int ret = HISEE_OK;
	if (state >= HISEE_STATE_MAX) {
		pr_err("%s() state=%d invalid\n", __func__, (int)state);
		set_errno_and_return(HISEE_INVALID_PARAMS);
	}
	ret = atfd_hisee_smc((u64)HISEE_FN_MAIN_SERVICE_CMD, (u64)CMD_SET_STATE, (u64)state, (u64)0);
	return ret;
}

static int hisee_powerctrl_func(hisee_power_operation op_type)
{
	int retry;
	int ret = HISEE_OK;
	rproc_id_t rproc_id = HISI_RPROC_LPM3_MBX27;
	rproc_msg_t tx_buffer[2] = {0};
	rproc_msg_t ack_buffer[2] = {0};

	if ((op_type != HISEE_POWER_OFF) && (op_type != HISEE_POWER_ON_BOOTING) &&\
		(op_type != HISEE_POWER_ON_UPGRADE) && (op_type != HISEE_POWER_ON_BOOTING_MISC) &&\
		(op_type != HISEE_POWER_ON_UPGRADE_SM)) {
		set_errno_and_return(HISEE_INVALID_PARAMS);
	}
	if ((HISEE_POWER_ON_BOOTING == op_type) || (HISEE_POWER_ON_UPGRADE == op_type) ||\
		(HISEE_POWER_ON_BOOTING_MISC == op_type) ||(HISEE_POWER_ON_UPGRADE_SM == op_type) )
		ret = set_hisee_state(HISEE_STATE_POWER_UP);
	else
		ret = set_hisee_state(HISEE_STATE_POWER_DOWN);
	if (HISEE_OK != ret) {
		pr_err("%s(): set_hisee_state faile,ret=%d.\n",  __func__, ret);
		set_errno_and_return(HISEE_SET_HISEE_STATE_ERROR);
	}

	tx_buffer[0] = IPC_CMD(OBJ_AP, OBJ_LPM3, CMD_NOTIFY, 0);
	tx_buffer[1] = op_type;
	retry = 3;

	do {
		ret = RPROC_SYNC_SEND(rproc_id, tx_buffer, 2, ack_buffer, 2);
		if ((0 == ret) && (HISEE_LPM3_CMD == ack_buffer[0]) && (HISEE_LPM3_ACK_MAGIC == ack_buffer[1])) {
			/* the send is reponsed by the remote process, break out */
			ret = HISEE_OK;
			break;
		}
		else if (-ETIMEOUT == ret) {
			/*the timeout will print out, below message to tell it's normal*/
		    retry--;
			ret = HISEE_POWERCTRL_TIMEOUT_ERROR;
			pr_err("%s(): the ack of sending ipc is timeout.\n",  __func__);
			continue;
		} else {
			pr_err("%s(): send ipc failed\n", __func__);
			ret = HISEE_POWERCTRL_NOTIFY_ERROR;
			retry = 0;
			break;
		}
	} while (retry);
	if (0 == retry) {
		pr_err("%s(): send ipc with retry still failed\n", __func__);
		ret = HISEE_POWERCTRL_RETRY_FAILURE_ERROR;
	}
	set_errno_and_return(ret);
}

int hisee_poweron_booting_func(void *buf, int para)
{
	int ret = HISEE_OK;
	hisee_state state;

	mutex_lock(&g_hisee_data.hisee_mutex);
	if (HISEE_POWER_ON_UPGRADE_SUCCESS == powerctrl_status) {
		ret = hisee_poweroff_func(NULL, HISEE_PWROFF_NOLOCK);
		if (HISEE_OK != ret) {
			pr_err("%s() hisee_poweroff_func failed ret=%d\n", __func__, ret);
			goto end;
		}
	}

	state = (hisee_state)atfd_hisee_smc((u64)HISEE_FN_MAIN_SERVICE_CMD, (u64)CMD_GET_STATE, (u64)0, (u64)0);
	/*case1: 灭屏下hisee处于下电，直接通过NFC刷卡，hisee低功耗流程生效，lpm3给hisee上电。此时要by pass该上电操作
	 *case2: 灭屏下hisee处于下电，亮屏后通过NFC刷卡，hisee低功耗流程不生效，此时不要by pass该上电操作
	 */
	if (state == HISEE_STATE_POWER_UP || state == HISEE_STATE_COS_READY ||
		state == HISEE_STATE_MISC_READY || state == HISEE_STATE_POWER_UP_DOING) {
		g_hisee_data.power_on_count++;
		powerctrl_status = HISEE_POWER_ON_BOOTING_SUCCESS;
		goto end; /*bypass power_on*/
	} else {
		g_hisee_data.power_on_count = 0;
		powerctrl_status = HISEE_POWER_OFF_SUCCESS;
	}

	if (0 == g_hisee_data.power_on_count) {
		ret = clk_prepare_enable(g_hisee_data.hisee_clk);
		if (ret < 0) {
			pr_err("%s() clk_prepare_enable failed ret=%d.\n", __func__, ret);
			ret = HISEE_BULK_CLK_ENABLE_ERROR;
			goto end;
		}

		if (HISEE_POWER_ON_BOOTING_MISC == para)
			ret = hisee_powerctrl_func(HISEE_POWER_ON_BOOTING_MISC);
		else
			ret = hisee_powerctrl_func(HISEE_POWER_ON_BOOTING);
		if (ret == HISEE_OK) {
			powerctrl_status = HISEE_POWER_ON_BOOTING_SUCCESS;
		} else {
			powerctrl_status = HISEE_POWER_ON_BOOTING_FAILURE;
		}
	}
	g_hisee_data.power_on_count++;
end:
	mutex_unlock(&g_hisee_data.hisee_mutex);
	check_and_print_result();
	set_errno_and_return(ret);
}/*lint !e715*/

int hisee_poweron_upgrade_func(void *buf, int para)
{
	int ret;
	hisee_state state;
	unsigned int hisee_lcs_mode = 0;

	ret = get_hisee_lcs_mode(&hisee_lcs_mode);
	if (HISEE_OK != ret) {
		pr_err("%s() get_hisee_lcs_mode failed,ret=%d\n", __func__, ret);
		set_errno_and_return(ret);
	}
	if (HISEE_SM_MODE_MAGIC == hisee_lcs_mode)
	{
		para = HISEE_POWER_ON_UPGRADE_SM;
	}

	mutex_lock(&g_hisee_data.hisee_mutex);

	if (HISEE_POWER_ON_BOOTING_SUCCESS == powerctrl_status) {
		ret = hisee_poweroff_func(NULL, HISEE_PWROFF_NOLOCK);
		if (HISEE_OK != ret) {
			pr_err("%s() hisee_poweroff_func failed ret=%d\n", __func__, ret);
			goto end;
		}
	}

	state = (hisee_state)atfd_hisee_smc((u64)HISEE_FN_MAIN_SERVICE_CMD, (u64)CMD_GET_STATE, (u64)0, (u64)0);
	/*case1: 灭屏下hisee处于下电，直接通过NFC刷卡，hisee低功耗流程生效，lpm3给hisee上电。此时要by pass该上电操作
	 *case2: 灭屏下hisee处于下电，亮屏后通过NFC刷卡，hisee低功耗流程不生效，此时不要by pass该上电操作
	 */
	if (state == HISEE_STATE_POWER_UP || state == HISEE_STATE_COS_READY ||
		state == HISEE_STATE_MISC_READY || state == HISEE_STATE_POWER_UP_DOING) {
		g_hisee_data.power_on_count++;
		goto end; /*bypass power_on*/
	} else {
		g_hisee_data.power_on_count = 0;
		powerctrl_status = HISEE_POWER_OFF_SUCCESS;
	}

	if (0 == g_hisee_data.power_on_count) {
		ret = clk_prepare_enable(g_hisee_data.hisee_clk);
		if (ret < 0) {
			pr_err("%s() clk_prepare_enable failed ret=%d.\n", __func__, ret);
			ret = HISEE_BULK_CLK_ENABLE_ERROR;
			goto end;
		}

		if (HISEE_POWER_ON_UPGRADE_SM == para)
			ret = hisee_powerctrl_func(HISEE_POWER_ON_UPGRADE_SM);
		else
			ret = hisee_powerctrl_func(HISEE_POWER_ON_UPGRADE);
		if (ret == HISEE_OK) {
			powerctrl_status = HISEE_POWER_ON_UPGRADE_SUCCESS;
		} else {
			powerctrl_status = HISEE_POWER_ON_UPGRADE_FAILURE;
		}
	}
	g_hisee_data.power_on_count++;
end:
	mutex_unlock(&g_hisee_data.hisee_mutex);
	check_and_print_result();
	set_errno_and_return(ret);
}/*lint !e715*/

int hisee_poweroff_func(void *buf, int para)
{
	int ret = HISEE_OK;

	if (HISEE_PWROFF_NOLOCK != para) {
		mutex_lock(&g_hisee_data.hisee_mutex);
	}
	if (powerctrl_status == HISEE_POWER_NONE || powerctrl_status == HISEE_POWER_OFF_SUCCESS)
		goto end;

	if (g_hisee_data.power_on_count > 0)
		g_hisee_data.power_on_count--;
	if (0 == g_hisee_data.power_on_count) {
		ret = hisee_powerctrl_func(HISEE_POWER_OFF);
		clk_disable_unprepare(g_hisee_data.hisee_clk);

		if (ret == HISEE_OK) {
			powerctrl_status = HISEE_POWER_OFF_SUCCESS;
		} else {
			powerctrl_status = HISEE_POWER_OFF_FAILURE;
		}
	}
end:
	if (HISEE_PWROFF_NOLOCK != para) {
		mutex_unlock(&g_hisee_data.hisee_mutex);
	}
	check_and_print_result();
	set_errno_and_return(ret);
}

static int hisee_poweroff_daemon_body(void *arg)
{
	int ret;
	timer_entry_list *cursor = NULL, *next = NULL;

	for (;;) {
		if (down_timeout(&g_hisee_poweroff_sem, (long)HISEE_THREAD_WAIT_TIMEOUT)) {
			mutex_lock(&g_poweron_timeout_mutex);
			if (0 == g_unhandled_timer_cnt) {
				/* exit this thread if wait sema timeout and theres no timer to be handled */
				g_daemon_created = false;
				mutex_unlock(&g_poweron_timeout_mutex);
				return 0;
			} else {
				mutex_unlock(&g_poweron_timeout_mutex);
				continue;
			}
		}
		/* got the sema */
		mutex_lock(&g_poweron_timeout_mutex);
		if (g_unhandled_timer_cnt > 0) {
			g_unhandled_timer_cnt--;
			ret = hisee_poweroff_func(NULL, HISEE_PWROFF_LOCK);
			if (HISEE_OK != ret)
				pr_err("%s  hisee poweroff failed, ret=%d\n", __func__, ret);
		}
		/*lint -e{613,529,438,64,826}*/
		list_for_each_entry_safe(cursor, next, &g_unhandled_timer_list, list) {
			if (atomic_read(&(cursor->handled))) {
				list_del(&(cursor->list));
				kfree(cursor);
			}
		}
		mutex_unlock(&g_poweron_timeout_mutex);
	}
}/*lint !e715*/

static int create_hisee_poweroff_daemon(void)
{
	struct task_struct *hisee_poweroff_daemon;

	/* create semaphore for daemon to wait poweroff signal */
	sema_init(&g_hisee_poweroff_sem, 0);

	hisee_poweroff_daemon = kthread_run(hisee_poweroff_daemon_body, NULL, "hisee_poweroff_daemon");
	if (IS_ERR(hisee_poweroff_daemon)) {
		pr_err("hisee err create hisee_poweroff_daemon failed\n");
		return HISEE_THREAD_CREATE_ERROR;
	}

	g_daemon_created = true;

	return HISEE_OK;
}

static void poweroff_handle(unsigned long arg)
{
	timer_entry_list *p_timer_entry = (timer_entry_list *)arg;

	atomic_set(&(p_timer_entry->handled), 1);

	up(&g_hisee_poweroff_sem);

	return;
}

static unsigned int parse_arg_get_timeout(void *buf, int para)
{
	char *cmd = (char *)buf;
	char *p = cmd;
	unsigned int num = 0;
	/* interface for direct call */
	if (NULL == buf) {
		if (para <= 0) return 0;
		return (unsigned int)para;
	}
	/* called through powerctrl_cmd */
	while ('\0' != *p && ' ' != *p) p++;
	if ('\0' == *p) return 0;
	while (' ' == *p) p++;
	if (kstrtouint(p, 0, &num)) /*its ok that cmd end with new line*/
		return 0;
	return num;
}

/* poweron hisee and add a timer to poweroff hisee _msecs_ ms later */
int hisee_poweron_timeout_func(void *buf, int para)
{
	int ret;
	struct timer_list *p_timer;
	timer_entry_list *p_timer_entry;
	unsigned int msecs;
	msecs = parse_arg_get_timeout(buf, para);
	if (0 == msecs) {
		pr_err("%s()  invalid para, timeout not specified or not larger than 0\n", __func__);
		set_errno_and_return(HISEE_INVALID_PARAMS);
	}

	mutex_lock(&g_poweron_timeout_mutex);

	if (!g_daemon_created) {
		ret = create_hisee_poweroff_daemon();
		if (HISEE_OK != ret)
			goto end;
	}

	p_timer_entry = (timer_entry_list *)kmalloc(sizeof(timer_entry_list), GFP_KERNEL);
	if (NULL == p_timer_entry) {
		pr_err("%s()  timer kmalloc failed\n", __func__);
		ret = HISEE_NO_RESOURCES;
		goto end;
	}
	atomic_set(&(p_timer_entry->handled), 0);

	p_timer = &(p_timer_entry->timer);
	init_timer(p_timer);
	p_timer->function = poweroff_handle;
	p_timer->data     = (unsigned long)p_timer_entry;
	p_timer->expires  = jiffies + msecs_to_jiffies(msecs) + 1; /*+1 makes timeout >= msecs*/

	ret = hisee_poweron_booting_func(NULL, 0);
	if (HISEE_OK != ret) {
		int ret_tmp;
		ret_tmp = hisee_poweroff_func(NULL, HISEE_PWROFF_LOCK);
		kfree(p_timer_entry);
		pr_err("%s()  hisee poweron booting failed, ret=%d. abort poweron_timeout\n", __func__, ret);
		if (HISEE_OK != ret_tmp) pr_err("%s()  also poweroff failed, ret=%d\n", __func__, ret_tmp);
		goto end;
	}

	add_timer(p_timer);
	list_add(&(p_timer_entry->list), &g_unhandled_timer_list);
	g_unhandled_timer_cnt++;

end:
	mutex_unlock(&g_poweron_timeout_mutex);
	set_errno_and_return(ret);
}/*lint !e715*/

int hisee_suspend(struct platform_device *pdev, struct pm_message state)
{
	timer_entry_list *cursor = NULL, *next = NULL;
	pr_err("hisi_hisee_suspend: +\n");
	mutex_lock(&g_poweron_timeout_mutex);

	/*lint -e{64,826,838} */
	list_for_each_entry_safe(cursor, next, &g_unhandled_timer_list, list) {
		list_del(&(cursor->list));
		del_timer_sync(&(cursor->timer));
		kfree(cursor);
	}

	sema_init(&g_hisee_poweroff_sem, 0);
	g_unhandled_timer_cnt = 0;

	mutex_unlock(&g_poweron_timeout_mutex);
	pr_err("hisi_hisee_suspend: -\n");
	return HISEE_OK;
}/*lint !e715*/

void wait_hisee_ready(hisee_state ready_state, unsigned int timeout_ms)
{
	hisee_state state = HISEE_STATE_MAX;
	unsigned int cnt = timeout_ms / 50;

	do {
		state = (hisee_state)atfd_hisee_smc((u64)HISEE_FN_MAIN_SERVICE_CMD, (u64)CMD_GET_STATE, (u64)0, (u64)0);
		if (ready_state == state)
			break;
		hisee_mdelay(50);
		cnt--;
	} while (cnt);
	if (cnt == 0)
		pr_err("%s() timeout!\n", __func__);
	return;
}

int wait_cos_ready(unsigned int timeout_ms)
{
	hisee_state state = HISEE_STATE_MAX;
	unsigned int cnt = timeout_ms / 20;

	do {
		state = (hisee_state)atfd_hisee_smc((u64)HISEE_FN_MAIN_SERVICE_CMD, (u64)CMD_GET_STATE, (u64)0, (u64)0);
		if (HISEE_STATE_COS_READY == state) {
			pr_err("%s %d ms\n", __func__, timeout_ms - cnt*20);
			return HISEE_OK;
		}
		hisee_mdelay(20);
		cnt--;
	} while (cnt);

	pr_err("%s() timeout!\n", __func__);
	return HISEE_WAIT_COS_READY_ERROR;
}

/** check whether the hisee is ready
 * @buf: output, return the hisee ready status
 */
ssize_t hisee_check_ready_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	hisee_state state;
	int ret;

	if (NULL == buf) {
		pr_err("%s buf paramters is null\n", __func__);
		set_errno_and_return(HISEE_INVALID_PARAMS);
	}
	state = (hisee_state)atfd_hisee_smc((u64)HISEE_FN_MAIN_SERVICE_CMD, (u64)CMD_GET_STATE, (u64)0, (u64)0);
	if (HISEE_STATE_COS_READY == state) {
		snprintf(buf, (u64)3, "%d,", 0);
		strncat(buf, "cos ready", (unsigned long)strlen("cos ready"));
	} else if (HISEE_STATE_POWER_DOWN == state
				|| HISEE_STATE_POWER_UP == state
				|| HISEE_STATE_MISC_READY == state
				|| HISEE_STATE_POWER_DOWN_DOING == state
				|| HISEE_STATE_POWER_UP_DOING == state) {
		snprintf(buf, (u64)3, "%d,", 1);
		strncat(buf, "cos unready", (unsigned long)strlen("cos unready"));
	} else {
		snprintf(buf, (u64)4, "%d,", -1);
		strncat(buf, "failed", (unsigned long)strlen("failed"));
	}

	pr_err("%s(): state=%d, %s\n", __func__, (int)state, buf);
	return (ssize_t)strlen(buf);
}/*lint !e715*/
