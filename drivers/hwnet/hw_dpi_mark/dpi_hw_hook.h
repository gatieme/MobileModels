

#ifndef _NF_HW_HOOK
#define _NF_HW_HOOK

#include <linux/module.h>

#define NETLINK_DOWNLOADEVENT_TO_USER 1000
#define DPI_RULE_MAX_SIZE 2

#define LOG_DEBUG 1
#define LOG_INFO 1

#define MPLINK_DEBUG(fmt, ...) \
	do { \
		if (LOG_DEBUG) { \
			printk(KERN_INFO "%s "fmt"\n", __func__, ##__VA_ARGS__); \
		} \
	} while (0)

#define MPLINK_INFO(fmt, ...) \
	do { \
		if (LOG_INFO) { \
			printk(KERN_INFO "%s "fmt"\n", __func__, ##__VA_ARGS__); \
		} \
	} while (0)

#define MPLINK_ERROR(fmt, ...) \
	do \
		printk(KERN_ERR "%s "fmt"\n", __func__, ##__VA_ARGS__); \
	while (0)


typedef enum {
	NETLINK_REG_TO_KERNEL = 0,
	NETLINK_UNREG_TO_KERNEL,
	NETLINK_CMM_TO_KERNEL,
	NETLINK_SET_RULE_TO_KERNEL,
	NETLINK_STOP_MARK,
	NETLINK_START_MARK,
	NETLINK_MPLK_BIND_NETWORK,
	NETLINK_MPLK_UNBIND_NETWORK,
	NETLINK_MPLK_RESET_SOCKET,
	NETLINK_MPLK_CLOSE_SOCKET,
	NETLINK_HID2D_TYPE,
} ntl_cmd_type_t;

typedef enum {
	DMR_MT_BEGIN = 0,
	DMR_MT_TP,
	DMR_MT_END,
} dmr_match_type_t;

typedef enum {
	/* init state, not recognized */
	MR_NORMAL = 0x0,
	/* reserve for acc_state, acc_state may delete future */
	MR_TMGP_1 = 0x1,
	/* gaming socket, mobile data use it for high priority bsr flag */
	MR_TMGP_2 = 0x2,
	/* marked no need to deal */
	MR_MARKED = 0x80,
	/*
	 * just use first byte, second byte used by bastet,
	 * thrid and forth byte is reserved
	 */
	MR_RESET = 0xFFFFFF00,
} mark_ret_t;

void mplk_try_nw_bind(struct sock *sk);
int mplk_sendmsg(struct sock *sk);
int mplk_recvmsg(struct sock *sk);
int get_mplk_somark(struct sock *sk, int mark);

#endif /* _NF_HW_HOOK */
