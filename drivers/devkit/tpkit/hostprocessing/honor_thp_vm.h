/*
 * Honor Touchscreen Driver
 *
 * Copyright (c) 2012-2021 Honor Device Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */
#ifndef _HONOR_THP_VM_H_
#define _HONOR_THP_VM_H_

#include "linux/gunyah/gh_mem_notifier.h"
#include "linux/gunyah/gh_irq_lend.h"
#include "linux/gunyah/gh_msgq.h"
#include "linux/gunyah/gh_rm_drv.h"

#define TRUSTED_TOUCH_MEM_LABEL 0x7
#define TRUSTED_TP_SUB_MSGQ_LABEL 0x30
#define TRUSTED_TP_MAIN_MSGQ_LABEL 0x31

#define TRUSTED_TOUCH_EVENT_LEND_FAILURE -1
#define TRUSTED_TOUCH_EVENT_LEND_NOTIFICATION_FAILURE -2
#define TRUSTED_TOUCH_EVENT_ACCEPT_FAILURE -3
#define	TRUSTED_TOUCH_EVENT_FUNCTIONAL_FAILURE -4
#define	TRUSTED_TOUCH_EVENT_RELEASE_FAILURE -5
#define	TRUSTED_TOUCH_EVENT_RECLAIM_FAILURE -6
#define	TRUSTED_TOUCH_EVENT_I2C_FAILURE -7
#define	TRUSTED_TOUCH_EVENT_NOTIFICATIONS_PENDING 5
#define TUI_ENABLE 1
#define TUI_DISABLE 0

enum trusted_touch_mode_config {
	TRUSTED_TOUCH_VM_MODE,
	TRUSTED_TOUCH_MODE_NONE
};

enum trusted_touch_pvm_states {
	TRUSTED_TOUCH_PVM_INIT,
	PVM_I2C_RESOURCE_ACQUIRED,
	PVM_INTERRUPT_DISABLED,
	PVM_IOMEM_LENT,
	PVM_IOMEM_LENT_NOTIFIED,
	PVM_IRQ_LENT,
	PVM_IRQ_LENT_NOTIFIED,
	PVM_IOMEM_RELEASE_NOTIFIED,
	PVM_IRQ_RELEASE_NOTIFIED,
	PVM_ALL_RESOURCES_RELEASE_NOTIFIED,
	PVM_IRQ_RECLAIMED,
	PVM_IOMEM_RECLAIMED,
	PVM_INTERRUPT_ENABLED,
	PVM_I2C_RESOURCE_RELEASED,
	TRUSTED_TOUCH_PVM_STATE_MAX
};

enum trusted_touch_tvm_states {
	TRUSTED_TOUCH_TVM_INIT,
	TVM_IOMEM_LENT_NOTIFIED,
	TVM_IRQ_LENT_NOTIFIED,
	TVM_ALL_RESOURCES_LENT_NOTIFIED,
	TVM_IOMEM_ACCEPTED,
	TVM_CLIENT_SESSION_ACQUIRED,
	TVM_IRQ_ACCEPTED,
	TVM_INTERRUPT_ENABLED,
	TVM_INTERRUPT_DISABLED,
	TVM_IRQ_RELEASED,
	TVM_CLIENT_SESSION_RELEASED,
	TVM_IOMEM_RELEASED,
	TRUSTED_TOUCH_TVM_STATE_MAX
};

struct trusted_touch_vm_info {
	enum gh_irq_label irq_label;
	enum gh_mem_notifier_tag mem_tag;
	enum gh_vm_names vm_name;
	const char *trusted_touch_type;
	u32 hw_irq;
	gh_memparcel_handle_t vm_mem_handle;
	u32 *iomem_bases;
	u32 *iomem_sizes;
	u32 iomem_list_size;
	void *mem_cookie;
	void *input_msgq;
	void *tp_sub_msgq;
	void *tp_main_msgq;
	atomic_t vm_state;
};

#define thp_vm_log_err(cd, msg, ...) \
	do { \
		if (cd) {\
			if (cd->multi_panel_index == SUB_TOUCH_PANEL) { \
				printk(KERN_ERR "[E/THP1_VM] " msg, ## __VA_ARGS__); \
			} else { \
				printk(KERN_ERR "[E/THP0_VM] " msg, ## __VA_ARGS__); \
			} \
		} else {\
			printk(KERN_ERR "[E/THP_VM] " msg, ## __VA_ARGS__); \
		} \
	} while (0)
#define thp_vm_log_info(cd, msg, ...) \
	do { \
		if (cd) {\
			if (cd->multi_panel_index == SUB_TOUCH_PANEL) { \
				printk(KERN_INFO "[I/THP1_VM] " msg, ## __VA_ARGS__); \
			} else { \
				printk(KERN_INFO "[I/THP0_VM] " msg, ## __VA_ARGS__); \
			} \
		} else {\
			printk(KERN_INFO "[I/THP_VM] " msg, ## __VA_ARGS__); \
		} \
	} while (0)
#define thp_vm_log_debug(cd, msg, ...) \
	do { \
		if (g_thp_log_cfg) { \
			if (cd) {\
				if (cd->multi_panel_index == SUB_TOUCH_PANEL) { \
					printk(KERN_INFO "[D/THP1_VM] " msg, ## __VA_ARGS__); \
				} else { \
					printk(KERN_INFO "[D/THP0_VM] " msg, ## __VA_ARGS__); \
				} \
			} else {\
				printk(KERN_INFO "[D/THP_VM] " msg, ## __VA_ARGS__); \
			} \
		} \
	} while (0)

#endif
