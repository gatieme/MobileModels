#include "cold_start_utils.h"
#include <linux/etherdevice.h>
#include <linux/module.h>
#include <linux/init.h>
#ifdef CONFIG_COMPAT
#include <linux/compat.h>
#endif
#include <linux/platform_device.h>
#include <linux/mm.h>
#include <linux/device.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/skbuff.h>
#include <linux/netlink.h>
#include <linux/moduleparam.h>
#include <linux/miscdevice.h>
#include <net/sock.h>
#include <linux/delay.h>
#include <linux/mutex.h>
#include <linux/spinlock.h>
#include <linux/notifier.h>
#include <linux/reboot.h>
#include <linux/netlink.h>
#include <linux/signal.h>
#include <linux/interrupt.h>
#include <linux/uaccess.h>
#include <linux/syscalls.h>
#include <securec.h>
#include <linux/ioctl.h>
#include <linux/version.h>
#include <linux/errno.h>
#include <linux/fs.h>
#include <linux/semaphore.h>
#include <linux/file.h>


static long wireless_dev_ioctl(struct file *file, unsigned int cmd, unsigned long arg);
static long wireless_bt_compat_ioctl(struct file *filp, unsigned int cmd, unsigned long arg);
int bt_set_mac_addr(uint8_t *data_to_write, bool uwb_rcu);
int bt_read_mac_addr(uint8_t *data_from_flash, bool uwb_rcu);

#define COLD_START_MODULE "cold_start_module"
#define WIRELESS_DEVICE "wireless_dev"
#define DATA_LENGTH 26
#define MAC_STRLEN 18
#define MAC_NUMLEN 6
#define MAC_INDEX 10
#define BT_MAC_BAK_OFFSET 512
#ifdef CONFIG_CONNECTIVITY_HI110X
#define FILTER_DATA_OFFSET (0x400000 - 0x400)
#define FLASH_PATH "/dev/block/by-name/reserved2"
#else
#define FLASH_PATH "/dev/block/by-name/stbcdat"
#define UWB_FILTER_DATA_OFFSET 128
#endif
#define BIT_SHIFT_SPACE 3
#define BIT_SHIFT_CNT 4
static ssize_t wireless_device_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count);
DEVICE_ATTR(wireless_dev, 0660, NULL, wireless_device_store);

static struct platform_device *wireless_platform_device = NULL;
static wait_queue_head_t g_read_queue;
static atomic_t g_read_condition;
uint8_t g_uwb_mac[MAC_NUMLEN] = {0};
uint8_t g_bt_mac[MAC_NUMLEN] = {0};

static struct attribute *wireless_dev_attributes[] = {
	&dev_attr_wireless_dev.attr,
	NULL
};

static const struct attribute_group wireless_dev_group = {
	.attrs = wireless_dev_attributes,
};

#define BT_CTRL_MSG 'z'

enum {
	BT_CMD_WRITE_FLASH_DATA = 0,
	BT_CMD_READ_FLASH_DATA,
	UWB_CMD_WRITE_FLASH_DATA,
	UWB_CMD_READ_FLASH_DATA
};

typedef struct _bt_ioctl_data_req_stru {
	uint8_t flash_data[DATA_LENGTH];
} bt_ioctl_data_req_stru;

typedef struct _bt_ioctl_data_rsp_stru {
	int ret; /* success 0,  faield  -1 */
	uint8_t flash_data[DATA_LENGTH];
} bt_ioctl_data_rsp_stru;

typedef struct _bt_ioctl_data_stru {
	bt_ioctl_data_req_stru req;
	bt_ioctl_data_rsp_stru rsp;
} bt_ioctl_data_stru;

typedef struct _bt_ioctl_msg {
	unsigned int cmd;
	bt_ioctl_data_stru msg_data;
} bt_ioctl_msg;

#define BT_IOCTL_CMD_WRITE_FLASH_DATA _IOWR(BT_CTRL_MSG, BT_CMD_WRITE_FLASH_DATA, bt_ioctl_data_stru)
#define BT_IOCTL_CMD_READ_FLASH_DATA _IOR(BT_CTRL_MSG, BT_CMD_READ_FLASH_DATA, bt_ioctl_data_stru)
#define UWB_IOCTL_CMD_WRITE_FLASH_DATA _IOWR(BT_CTRL_MSG, UWB_CMD_WRITE_FLASH_DATA, bt_ioctl_data_stru)
#define UWB_IOCTL_CMD_READ_FLASH_DATA _IOR(BT_CTRL_MSG, UWB_CMD_READ_FLASH_DATA, bt_ioctl_data_stru)

struct list_queue bt_receive_queue;
struct work_struct bt_receive_handle_work;

static int wireless_dev_open(struct inode *inode, struct file *file);
static const struct file_operations wireless_dev_fops = {
	.owner = THIS_MODULE,
	.open = wireless_dev_open,
#ifdef CONFIG_COMPAT
	.compat_ioctl = wireless_bt_compat_ioctl,
#endif
	.unlocked_ioctl = wireless_dev_ioctl,
};

static struct miscdevice wireless_dev = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "wireless_dev",
	.fops = &wireless_dev_fops,
};

static long full_rw_file(struct file *fp, char *buf,
			size_t buf_size, bool read, loff_t pos)
{
	mm_segment_t old_fs;
	long bytes_total_to_rw = (long)buf_size;
	long bytes_total_rw = 0L;
	long bytes_this_time = 0L;
	char *ptemp = buf;

	while (bytes_total_to_rw > 0) {
		bytes_this_time = read ?
			vfs_read(fp, ptemp, bytes_total_to_rw, &pos) :
			vfs_write(fp, ptemp, bytes_total_to_rw, &pos);
		if (read ? (bytes_this_time <= 0) : (bytes_this_time < 0)) {
			cold_start_log_err("bf_sys_read or bf_sys_write failed!\n");
			break;
		}
		ptemp += bytes_this_time;
		bytes_total_to_rw -= bytes_this_time;
		bytes_total_rw += bytes_this_time;
	}
	return bytes_total_rw;
}

static int rw_part(const char *dev_path, unsigned long long offset,
		char *buf, unsigned long long buf_size, bool read)
{
	struct file *fp = NULL;
	int ret = -1;
	long bytes_total;
	loff_t seek_result;
	mm_segment_t fs;
	int err = 0;

	if (dev_path == NULL || buf == NULL)
		return -1;

	fs = get_fs();
	set_fs(KERNEL_DS);
	fp = filp_open(dev_path, read ? O_RDONLY : O_WRONLY, 0);
	if (IS_ERR(fp)) {
		err = PTR_ERR(fp);
		cold_start_log_err("Open file [%s] failed, errno is %d!\n", dev_path, err);
		if (!IS_ERR(fp))
			filp_close(fp, NULL);
		set_fs(fs);
		return ret;
	}

	bytes_total = full_rw_file(fp, buf, buf_size, read, offset);
	if ((long long)buf_size != bytes_total) {
		cold_start_log_err("rw [%s] failed!, result: %ld, it should be: %lld\n",
			dev_path, bytes_total, (long long)buf_size);
		if (!IS_ERR(fp))
			filp_close(fp, NULL);
		set_fs(fs);
		return ret;
	} else {
		ret = 0;
	}
	if (!IS_ERR(fp))
		filp_close(fp, NULL);
	set_fs(fs);
	return ret;
}

static void bt_msg_receive_dispatch(bt_ioctl_msg *msg_rev)
{
	if (msg_rev == NULL) {
		cold_start_log_err("msg_rev is NULL, error");
		return;
	}

	cold_start_log_info("dispatch msg from ioctl:%d", msg_rev->cmd);
	switch (msg_rev->cmd) {
	case BT_IOCTL_CMD_READ_FLASH_DATA:
		if (msg_rev->msg_data.rsp.flash_data == NULL) {
			cold_start_log_err("flash_data ia NULL");
			msg_rev->msg_data.rsp.ret = ERROR;
		} else {
			msg_rev->msg_data.rsp.ret = bt_read_mac_addr(msg_rev->msg_data.rsp.flash_data, false);
		}
		break;
	case BT_IOCTL_CMD_WRITE_FLASH_DATA:
		msg_rev->msg_data.rsp.ret = bt_set_mac_addr(msg_rev->msg_data.req.flash_data, false);
		break;
	case UWB_IOCTL_CMD_WRITE_FLASH_DATA:
		msg_rev->msg_data.rsp.ret = bt_set_mac_addr(msg_rev->msg_data.req.flash_data, true);
		break;
	case UWB_IOCTL_CMD_READ_FLASH_DATA:
		if (msg_rev->msg_data.rsp.flash_data == NULL) {
			cold_start_log_err("flash_data ia NULL");
			msg_rev->msg_data.rsp.ret = ERROR;
		} else {
			msg_rev->msg_data.rsp.ret = bt_read_mac_addr(msg_rev->msg_data.rsp.flash_data, true);
		}
		break;
	default:
		msg_rev->msg_data.rsp.ret = ERROR;
		break;
	}
	return;
}

static void bt_msg_receive_handle(struct work_struct *work)
{
	struct list_node *node = NULL;
	bt_ioctl_msg msg_rev;
	int sec_ret = 0;
	if (work == NULL) {
		cold_start_log_err("work is NULL, error");
		return;
	}

	while (tvcold_list_queue_is_empty(&(bt_receive_queue)) == 0) {
		node = tvcold_list_queue_dequeue(&(bt_receive_queue));
		if (node == NULL) {
			cold_start_log_err("dequeue a null node");
			break;
		}
		(void)memset_s(&msg_rev, sizeof(msg_rev), 0, sizeof(msg_rev));

		sec_ret = memcpy_s(&msg_rev, sizeof(msg_rev), node->data, node->len);
		tvcold_free_list_node(node);
		node = NULL;
		if (sec_ret != 0) {
			cold_start_log_err("memcpy node->data fail, error");
			break;
		}
		bt_msg_receive_dispatch(&msg_rev);
	}
}

static uint32_t string_to_hex(uint8_t ch, uint32_t *hex)
{
	if (ch <= '9' && ch >= '0') {
		*hex = ch - '0';
	} else if (ch <= 'f' && ch >= 'a') {
		*hex = ch - 'a' + 0x0A;
	} else if (ch <= 'F' && ch >= 'A') {
		*hex = ch - 'A' + 0x0A;
	} else {
		cold_start_log_err("string_to_hex para error");
		return ERROR;
	}

	return SUCCESS;
}

static int string_to_mac_addr(uint8_t *data_from_flash, bool uwb_rcu)
{
	int ret = SUCCESS;
	uint32_t high_data;
	uint32_t low_data;
	char flash_mac[MAC_STRLEN] = {0};

	for (int i = 0; i < MAC_NUMLEN; i++) {
 		ret = string_to_hex(data_from_flash[i * BIT_SHIFT_SPACE], &high_data);
 		if (ret != SUCCESS) {
 			cold_start_log_err("string_to_hex error");
 			return ERROR;
 		}
 		high_data = high_data << BIT_SHIFT_CNT;
 		ret = string_to_hex(data_from_flash[i * BIT_SHIFT_SPACE + 1], &low_data);
 		if (ret != SUCCESS) {
 			cold_start_log_err("string_to_hex error");
 			return ERROR;
 		}
 		flash_mac[i] = high_data + low_data;
 	}

	cold_start_log_err("read bt mac is %x:**:**:%x:%x", flash_mac[0], flash_mac[4], flash_mac[5]);
	if (uwb_rcu) {
		ret = memcpy_s(g_uwb_mac, MAC_NUMLEN, flash_mac, MAC_NUMLEN);
		if (ret != EOK) {
			cold_start_log_err("memcpy failed");
			return ERROR;
		}
	} else {
		ret = memcpy_s(g_bt_mac, MAC_NUMLEN, flash_mac, MAC_NUMLEN);
		if (ret != EOK) {
			cold_start_log_err("memcpy failed");
			return ERROR;
		}
	}

	return ret;
}

int bt_read_mac_addr(uint8_t *data_from_flash, bool uwb_rcu)
{
	int fd = SUCCESS;
	int ret = SUCCESS;
	int offset = 0;
	char mac_str[MAC_STRLEN] = {0};
	mm_segment_t oldfs;

	if (data_from_flash == NULL) {
		cold_start_log_err("data_from_flash is NULL");
		return ERROR;
	}
#ifdef CONFIG_CONNECTIVITY_HI110X
	ret = rw_part(FLASH_PATH, FILTER_DATA_OFFSET, data_from_flash, DATA_LENGTH, true);
	cold_start_log_err("read bt mac is %x:**:**:%x:%x", data_from_flash[MAC_INDEX],
		data_from_flash[MAC_INDEX + 4], data_from_flash[MAC_INDEX + 5]);
#else
	if (uwb_rcu) {
		cold_start_log_info("bt_read_mac_addr is uwb rcu");
		offset = UWB_FILTER_DATA_OFFSET;
	}
	ret = rw_part(FLASH_PATH, offset, mac_str, MAC_STRLEN, true);

	ret = string_to_mac_addr(mac_str, uwb_rcu);
	if(ret != SUCCESS) {
		cold_start_log_err("string_to_mac_addr failed");
		atomic_set(&g_read_condition, QUEUE_WORK);
		wake_up(&g_read_queue);
		return ERROR;
	}
	atomic_set(&g_read_condition, QUEUE_WORK);
	wake_up(&g_read_queue);
#endif
	return ret;
}

int bt_set_mac_addr(uint8_t *data_to_write, bool uwb_rcu)
{
	int fd = SUCCESS;
	int ret = SUCCESS;
	int offset = 0;
	int bak_offset = BT_MAC_BAK_OFFSET;
	char mac[MAC_NUMLEN] = {0};
	char mac_str[MAC_STRLEN] = {0};
	mm_segment_t oldfs;

	if (data_to_write == NULL) {
		cold_start_log_err("data_to_write is NULL");
		return ERROR;
	}
	ret = memcpy_s(mac, MAC_NUMLEN, (char *)(data_to_write + MAC_INDEX), MAC_NUMLEN);
	if (ret != EOK) {
		cold_start_log_err("memcpy failed");
		return ERROR;
	}
	cold_start_log_err("write bt mac is %x:**:**:%x:%x", mac[0], mac[4], mac[5]);

#ifdef CONFIG_CONNECTIVITY_HI110X
	ret = rw_part(FLASH_PATH, FILTER_DATA_OFFSET, data_to_write, DATA_LENGTH, false);
#else
	sprintf_s(mac_str, MAC_STRLEN, "%02x:%02x:%02x:%02x:%02x:%02x",
		mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);

	if (uwb_rcu) {
		offset = UWB_FILTER_DATA_OFFSET;
		bak_offset = BT_MAC_BAK_OFFSET + UWB_FILTER_DATA_OFFSET;
	}
	cold_start_log_err("write bt mac is %x:**:**:%x:%x", mac[0], mac[4], mac[5]);
	ret = rw_part(FLASH_PATH, offset, mac_str, MAC_STRLEN, false);
	if (ret < 0)
		return ret;
	ret = rw_part(FLASH_PATH, bak_offset, mac_str, MAC_STRLEN, false);
#endif

	return ret;
}

static int wireless_dev_open(struct inode *inode, struct file *file)
{
	cold_start_log_err("dev open success");
	return SUCCESS;
}

static long read_rcu_bt_mac(unsigned int cmd, bt_ioctl_data_stru __user *argp)
{
	int ret = EOK;
	bt_ioctl_msg *msg_rsp = NULL;

	msg_rsp = (bt_ioctl_msg *)kmalloc(sizeof(bt_ioctl_msg), GFP_ATOMIC);
	if (msg_rsp == NULL) {
		cold_start_log_err("kmalloc bt_ioctl_msg failed");
		return ERROR;
	}

	wait_event_interruptible(g_read_queue, atomic_read(&g_read_condition));
	if (cmd == UWB_IOCTL_CMD_READ_FLASH_DATA) {
		ret = memcpy_s((uint8_t *)(msg_rsp->msg_data.rsp.flash_data + MAC_INDEX),
			(sizeof(msg_rsp->msg_data.rsp.flash_data) - MAC_INDEX), g_uwb_mac, MAC_NUMLEN);
	} else {
		ret = memcpy_s((uint8_t *)(msg_rsp->msg_data.rsp.flash_data + MAC_INDEX),
			(sizeof(msg_rsp->msg_data.rsp.flash_data) - MAC_INDEX), g_bt_mac, MAC_NUMLEN);
	}
	if (ret !=EOK) {
		kfree(msg_rsp);
		msg_rsp = NULL;
		cold_start_log_err("memcpy failed");
		return ERROR;
	}

	if (copy_to_user(argp, &(msg_rsp->msg_data), sizeof(msg_rsp->msg_data))) {
		kfree(msg_rsp);
		msg_rsp = NULL;
		cold_start_log_err("copy_to_user ERROR");
		return ERROR;
	}
	kfree(msg_rsp);
	msg_rsp = NULL;

	return ret;
}

static long wireless_dev_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	int ret = SUCCESS;
	bt_ioctl_data_stru __user *argp = (bt_ioctl_data_stru __user *)arg;
	bt_ioctl_msg *msg_rev = NULL;
	struct list_node *node = NULL;

	if (!argp) {
		cold_start_log_err("argp is invalid");
		return ERROR;
	}

	msg_rev = (bt_ioctl_msg *)kmalloc(sizeof(bt_ioctl_msg), GFP_ATOMIC);
	if (msg_rev == NULL) {
		cold_start_log_err("kmalloc bt_ioctl_msg failed");
		return ERROR;
	}

	msg_rev->cmd = cmd;
	if (copy_from_user(&(msg_rev->msg_data), argp, sizeof(msg_rev->msg_data))) {
		kfree(msg_rev);
		msg_rev = NULL;
		cold_start_log_err("copy_from_user ERROR");
		return ERROR;
	}

	node = tvcold_alloc_list_node((void *)msg_rev, sizeof(*msg_rev));
	kfree(msg_rev);
	msg_rev = NULL;
	if (unlikely(node == NULL)) {
		cold_start_log_err("alloc node failed, error");
		return ERROR;
	}

	tvcold_list_queue_enqueue(&(bt_receive_queue), node);
	schedule_work(&(bt_receive_handle_work));

	if (cmd == UWB_IOCTL_CMD_READ_FLASH_DATA || cmd == BT_IOCTL_CMD_READ_FLASH_DATA) {
		ret = read_rcu_bt_mac(cmd, argp);
		if (ret != EOK) {
			cold_start_log_err("read_uwb_rcu_mac failed");
			return ERROR;
		}
	}

	return ret;
}

#ifdef CONFIG_COMPAT
static long wireless_bt_compat_ioctl(struct file *filp,
			unsigned int cmd, unsigned long arg)
{
	return wireless_dev_ioctl(filp, cmd, (unsigned long) compat_ptr(arg));
}
#endif

static ssize_t wireless_device_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	cold_start_log_err("device store success");
	return SUCCESS;
}

static int wireless_device_unregister(void)
{
	sysfs_remove_group(&wireless_platform_device->dev.kobj, &wireless_dev_group);
	platform_device_unregister(wireless_platform_device);
	(void)misc_deregister(&wireless_dev);
	wireless_platform_device = NULL;
	return SUCCESS;
}

static int __init cold_start_init(void)
{
	int ret;

	wireless_platform_device = platform_device_register_simple(WIRELESS_DEVICE, -1, NULL, 0);
	if (wireless_platform_device != NULL) {
		ret = sysfs_create_group(&wireless_platform_device->dev.kobj, &wireless_dev_group);
		if (ret != SUCCESS) {
			cold_start_log_err("create wireless_platform group failed");
			return ret;
		}
	} else {
		cold_start_log_err("cold_start_init: register wireless_platform faild");
	}

	if (misc_register(&wireless_dev) != SUCCESS) {
		cold_start_log_err("misc_register wireless_dev failed, ERROR");
	}

	tvcold_list_queue_init(&(bt_receive_queue));
	INIT_WORK(&(bt_receive_handle_work), bt_msg_receive_handle);
	init_waitqueue_head(&g_read_queue);
	atomic_set(&g_read_condition, QUEUE_SLEEP);
	return ret;
}

static void __exit cold_start_exit(void)
{
	(void)wireless_device_unregister();
}

module_init(cold_start_init);
module_exit(cold_start_exit);
MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION(COLD_START_MODULE);
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");