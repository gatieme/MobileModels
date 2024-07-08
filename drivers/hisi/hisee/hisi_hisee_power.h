#ifndef __HISI_HISEE_POWER_H__
#define __HISI_HISEE_POWER_H__

#define HISEE_POWERCTRL_TIMEOUT_ERROR    (-4000)
#define HISEE_POWERCTRL_NOTIFY_ERROR     (-4001)
#define HISEE_POWERCTRL_RETRY_FAILURE_ERROR     (-4002)
#define HISEE_POWERCTRL_FLOW_ERROR       (-4003)

/* Lpm3 communication id */
#define HISEE_LPM3_CMD        IPC_CMD(OBJ_AP, OBJ_LPM3, CMD_NOTIFY, 0)
#define HISEE_LPM3_ACK_MAGIC  0xaaccbbdd

#define HISEE_PWROFF_LOCK	(1)
#define HISEE_PWROFF_NOLOCK	(0)

#define HISEE_COS_UPGRADE_RUNNING_FLG (0x87654321u)

/* timeout of thread exit when waiting semaphore, 30s */
#define HISEE_THREAD_WAIT_TIMEOUT (msecs_to_jiffies(30000))

typedef enum _HISEE_POWER_OPERATION {
	HISEE_POWER_OFF = 0x01000100,
	HISEE_POWER_ON_BOOTING = 0x01000101,
	HISEE_POWER_ON_UPGRADE = 0x01000102,
	HISEE_POWER_ON_UPGRADE_SM = 0x01000103,
	HISEE_POWER_ON_BOOTING_MISC = 0x01000104,
} hisee_power_operation;

typedef enum {
	HISEE_POWER_NONE = 0,
	HISEE_POWER_ON_BOOTING_SUCCESS,
	HISEE_POWER_ON_BOOTING_FAILURE,
	HISEE_POWER_ON_UPGRADE_SUCCESS,
	HISEE_POWER_ON_UPGRADE_FAILURE,
	HISEE_POWER_OFF_SUCCESS,
	HISEE_POWER_OFF_FAILURE,
} hisee_powerctrl_status;

typedef struct _TIMER_ENTRY_LIST {
	struct list_head list;
	struct timer_list timer;
	atomic_t handled;
} timer_entry_list;

extern hisee_powerctrl_status powerctrl_status;

int hisee_suspend(struct platform_device *pdev, struct pm_message state);
void hisee_power_ctrl_init(void);
ssize_t hisee_check_ready_show(struct device *dev, struct device_attribute *attr, char *buf);
void wait_hisee_ready(hisee_state ready_state, unsigned int timeout_ms);
int wait_cos_ready(unsigned int timeout_ms);

int hisee_poweron_booting_func(void *buf, int para);
int hisee_poweron_upgrade_func(void *buf, int para);
int hisee_poweroff_func(void *buf, int para);
int hisee_poweron_timeout_func(void *buf, int para);

#endif
