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
#include <linux/atomic.h>
#include <linux/clk.h>
#include <linux/pm_runtime.h>
#include <linux/of_irq.h>
#include <linux/of_gpio.h>
#include <linux/interrupt.h>
#include <linux/delay.h>
#include <linux/pinctrl/qcom-pinctrl.h>

#include <linux/sort.h>
#include "honor_thp.h"

#ifdef CONFIG_ARCH_QTI_VM
void *g_msgq_reg;
#endif

#ifdef CONFIG_HONOR_TRUSTED_TOUCH
extern int touch_driver_send_reset_cmd(struct thp_device *tdev);
extern int touch_driver_send_test_cmd(struct thp_device *tdev);

static void thp_trusted_touch_abort_handler(struct thp_core_data *cd,
						int error);

static struct gh_acl_desc *thp_vm_get_acl(enum gh_vm_names vm_name)
{
	struct gh_acl_desc *acl_desc;
	gh_vmid_t vmid;

	gh_rm_get_vmid(vm_name, &vmid);

	acl_desc = kzalloc(offsetof(struct gh_acl_desc, acl_entries[1]),
			GFP_KERNEL);
	if (!acl_desc)
		return ERR_PTR(ENOMEM);

	acl_desc->n_acl_entries = 1;
	acl_desc->acl_entries[0].vmid = vmid;
	acl_desc->acl_entries[0].perms = GH_RM_ACL_R | GH_RM_ACL_W;

	return acl_desc;
}

static struct gh_sgl_desc *thp_vm_get_sgl(struct thp_core_data *cd,
				struct trusted_touch_vm_info *vm_info)
{
	struct gh_sgl_desc *sgl_desc;
	int i;

	sgl_desc = kzalloc(offsetof(struct gh_sgl_desc,
			sgl_entries[vm_info->iomem_list_size]), GFP_KERNEL);
	if (!sgl_desc)
		return ERR_PTR(ENOMEM);

	sgl_desc->n_sgl_entries = vm_info->iomem_list_size;

	for (i = 0; i < vm_info->iomem_list_size; i++) {
		sgl_desc->sgl_entries[i].ipa_base = vm_info->iomem_bases[i];
		sgl_desc->sgl_entries[i].size = vm_info->iomem_sizes[i];
		thp_vm_log_info(cd, "%s sgl entry %d: 0x%lx, 0x%lx\n", __func__, i,
			sgl_desc->sgl_entries[i].ipa_base, sgl_desc->sgl_entries[i].size);
	}

	return sgl_desc;
}

static int thp_populate_vm_info_iomem(struct thp_core_data *cd)
{
	int i, gpio, rc = 0;
	int num_regs, num_sizes, num_gpios, list_size;
	struct resource res;
	struct device_node *np = cd->thp_node;
	struct trusted_touch_vm_info *vm_info = cd->vm_info;

	num_regs = of_property_count_u32_elems(np, "trusted-touch-io-bases");
	if (num_regs < 0) {
		thp_vm_log_err(cd, "Invalid number of IO regions specified\n");
		return -EINVAL;
	}

	num_sizes = of_property_count_u32_elems(np, "trusted-touch-io-sizes");
	if (num_sizes < 0) {
		thp_vm_log_err(cd, "Invalid number of IO regions specified\n");
		return -EINVAL;
	}

	if (num_regs != num_sizes) {
		thp_vm_log_err(cd, "IO bases and sizes array lengths mismatch\n");
		return -EINVAL;
	}

	num_gpios = of_gpio_named_count(np, "trusted-touch-vm-gpio-list");
	if (num_gpios < 0) {
		thp_vm_log_info(cd, "Ignoring invalid trusted gpio list: %d\n", num_gpios);
		num_gpios = 0;
	}

	list_size = num_regs + num_gpios;
	vm_info->iomem_list_size = list_size;
	vm_info->iomem_bases = devm_kcalloc(cd->dev, list_size, sizeof(*vm_info->iomem_bases),
			GFP_KERNEL);
	if (!vm_info->iomem_bases)
		return -ENOMEM;

	vm_info->iomem_sizes = devm_kcalloc(cd->dev, list_size, sizeof(*vm_info->iomem_sizes),
			GFP_KERNEL);
	if (!vm_info->iomem_sizes)
		return -ENOMEM;

	for (i = 0; i < num_gpios; ++i) {
		gpio = of_get_named_gpio(np, "trusted-touch-vm-gpio-list", i);
		if (gpio < 0 || !gpio_is_valid(gpio)) {
			thp_vm_log_err(cd, "Invalid gpio %d at position %d\n", gpio, i);
			return gpio;
		}

		if (!msm_gpio_get_pin_address(gpio, &res)) {
			thp_vm_log_err(cd, "Failed to retrieve gpio-%d resource\n", gpio);
			return -ENODATA;
		}

		vm_info->iomem_bases[i] = res.start;
		vm_info->iomem_sizes[i] = resource_size(&res);
	}

	rc = of_property_read_u32_array(np, "trusted-touch-io-bases",
			&vm_info->iomem_bases[i], list_size - i);
	if (rc) {
		thp_vm_log_err(cd, "Failed to read trusted touch io bases:%d\n", rc);
		return rc;
	}

	rc = of_property_read_u32_array(np, "trusted-touch-io-sizes",
			&vm_info->iomem_sizes[i], list_size - i);
	if (rc) {
		thp_vm_log_err(cd, "Failed to read trusted touch io sizes:%d\n", rc);
		return rc;
	}

	return 0;
}

static int thp_populate_vm_info(struct thp_core_data *cd)
{
	int rc;
	struct trusted_touch_vm_info *vm_info;
	struct device_node *np = cd->thp_node;

	vm_info = devm_kzalloc(cd->dev, sizeof(struct trusted_touch_vm_info), GFP_KERNEL);
	if (!vm_info)
		return -ENOMEM;

	cd->vm_info = vm_info;
	vm_info->vm_name = GH_TRUSTED_VM;
	rc = of_property_read_u32(np, "trusted-touch-spi-irq", &vm_info->hw_irq);
	if (rc) {
		thp_vm_log_err(cd, "Failed to read trusted touch SPI irq:%d\n", rc);
		return rc;
	}

	rc = thp_populate_vm_info_iomem(cd);
	if (rc) {
		thp_vm_log_err(cd, "Failed to read trusted touch mmio ranges:%d\n", rc);
		return rc;
	}

	rc = of_property_read_string(np, "trusted-touch-type",
						&vm_info->trusted_touch_type);
	if (rc) {
		thp_vm_log_info(cd, "%s: No trusted touch type selection made\n", __func__);
		vm_info->mem_tag = GH_MEM_NOTIFIER_TAG_TOUCH_PRIMARY;
		vm_info->irq_label = GH_IRQ_LABEL_TRUSTED_TOUCH_PRIMARY;
		rc = 0;
	} else if (!strcmp(vm_info->trusted_touch_type, "primary")) {
		vm_info->mem_tag = GH_MEM_NOTIFIER_TAG_TOUCH_PRIMARY;
		vm_info->irq_label = GH_IRQ_LABEL_TRUSTED_TOUCH_PRIMARY;
	} else if (!strcmp(vm_info->trusted_touch_type, "secondary")) {
		vm_info->mem_tag = GH_MEM_NOTIFIER_TAG_TOUCH_SECONDARY;
		vm_info->irq_label = GH_IRQ_LABEL_TRUSTED_TOUCH_SECONDARY;
	}

	return 0;
}

static void thp_destroy_vm_info(struct thp_core_data *cd)
{
	kfree(cd->vm_info->iomem_sizes);
	kfree(cd->vm_info->iomem_bases);
	kfree(cd->vm_info);
}

void thp_vm_deinit(struct thp_core_data *cd)
{
	if (cd->vm_info->mem_cookie)
		gh_mem_notifier_unregister(cd->vm_info->mem_cookie);
	thp_destroy_vm_info(cd);
}

static int thp_trusted_touch_get_vm_state(struct thp_core_data *cd)
{
	return atomic_read(&cd->vm_info->vm_state);
}

static void thp_trusted_touch_set_vm_state(struct thp_core_data *cd,
							int state)
{
	atomic_set(&cd->vm_info->vm_state, state);
}

#define TOUCH_CS_GPIO_BASE 0xF113000
#define TOUCH_CS_GPIO_SIZE 0x1000
#define TOUCH_CS_GPIO_OFFSET 0x4

#define TOUCH_INTR_GPIO_BASE 0xF115000
#define TOUCH_INTR_GPIO_SIZE 0x1000
#define TOUCH_INTR_GPIO_OFFSET 0x8


void thp_ts_trusted_dump_touch_gpio(struct thp_core_data *cd)
{
	void __iomem *base;
	int enable = 0;
	u32 val;

	thp_vm_log_info(cd, "%s called: irq %d\n", __func__, cd->irq);
	base = ioremap(TOUCH_INTR_GPIO_BASE, TOUCH_INTR_GPIO_SIZE);
	thp_vm_log_info(cd, "irq gpio reg -- cfg 0x%08x\n", readl_relaxed(base));
	thp_vm_log_info(cd, "irq gpio reg -- in/out 0x%08x\n", readl_relaxed(base+4));
	thp_vm_log_info(cd, "irq gpio reg -- intr-cfg 0x%08x\n", readl_relaxed(base+8));
	thp_vm_log_info(cd, "irq gpio reg -- intr-status 0x%08x\n", readl_relaxed(base+12));
	thp_vm_log_info(cd, "irq gpio reg -- id-status 0x%08x\n", readl_relaxed(base+16));
	thp_vm_log_info(cd, "irq gpio reg -- lp-cfg 0x%08x\n", readl_relaxed(base+20));

	val = readl_relaxed(base + TOUCH_INTR_GPIO_OFFSET);
	if (enable) {
		val |= BIT(0);
		writel_relaxed(val, base + TOUCH_INTR_GPIO_OFFSET);
		/* wait until toggle to finish*/
		wmb();
	} else {
		val &= ~BIT(0);
		writel_relaxed(val, base + TOUCH_INTR_GPIO_OFFSET);
		/* wait until toggle to finish*/
		wmb();
	}

	thp_vm_log_info(cd, "irq gpio reg -- cfg 0x%08x\n", readl_relaxed(base));
	thp_vm_log_info(cd, "irq gpio reg -- in/out 0x%08x\n", readl_relaxed(base+4));
	thp_vm_log_info(cd, "irq gpio reg -- intr-cfg 0x%08x\n", readl_relaxed(base+8));
	thp_vm_log_info(cd, "irq gpio reg -- intr-status 0x%08x\n", readl_relaxed(base+12));
	thp_vm_log_info(cd, "irq gpio reg -- id-status 0x%08x\n", readl_relaxed(base+16));
	thp_vm_log_info(cd, "irq gpio reg -- lp-cfg 0x%08x\n", readl_relaxed(base+20));

	iounmap(base);
}


#ifdef CONFIG_ARCH_QTI_VM
static int thp_vm_mem_release(struct thp_core_data *cd);
static void thp_trusted_touch_tvm_vm_mode_disable(struct thp_core_data *cd);
static void thp_trusted_touch_abort_tvm(struct thp_core_data *cd);
static void thp_trusted_touch_event_notify(struct thp_core_data *cd, int event);

static int thp_sgl_cmp(const void *a, const void *b)
{
	struct gh_sgl_entry *left = (struct gh_sgl_entry *)a;
	struct gh_sgl_entry *right = (struct gh_sgl_entry *)b;

	return (left->ipa_base - right->ipa_base);
}

static int thp_vm_compare_sgl_desc(struct thp_core_data *cd, struct gh_sgl_desc *expected,
		struct gh_sgl_desc *received)
{
	int idx;

	if (expected->n_sgl_entries != received->n_sgl_entries)
		return -E2BIG;
	sort(received->sgl_entries, received->n_sgl_entries,
			sizeof(received->sgl_entries[0]), thp_sgl_cmp, NULL);
	sort(expected->sgl_entries, expected->n_sgl_entries,
			sizeof(expected->sgl_entries[0]), thp_sgl_cmp, NULL);

	for (idx = 0; idx < expected->n_sgl_entries; idx++) {
		struct gh_sgl_entry *left = &expected->sgl_entries[idx];
		struct gh_sgl_entry *right = &received->sgl_entries[idx];

		if ((left->ipa_base != right->ipa_base) ||
				(left->size != right->size)) {
			thp_vm_log_err(cd, "sgl mismatch: left_base:%d right base:%d left size:%d right size:%d\n",
					left->ipa_base, right->ipa_base,
					left->size, right->size);
			return -EINVAL;
		}
	}
	return 0;
}

static int thp_vm_handle_vm_hardware(struct thp_core_data *cd)
{
	int rc = 0;

	if (atomic_read(&cd->delayed_vm_probe_pending)) {
		rc = thp_probe_delayed(cd);
		if (rc) {
			thp_vm_log_err(cd, " Delayed probe failure on VM!\n");
			return rc;
		}
		atomic_set(&cd->delayed_vm_probe_pending, 0);
	}

	enable_irq(cd->irq);
	thp_trusted_touch_set_vm_state(cd, TVM_INTERRUPT_ENABLED);

	return rc;
}

static void thp_trusted_touch_tvm_vm_mode_enable(struct thp_core_data *cd)
{
	struct gh_sgl_desc *sgl_desc, *expected_sgl_desc;
	struct gh_acl_desc *acl_desc;
	struct irq_data *irq_data;
	int rc = 0;
	int irq = 0;

	atomic_set(&cd->trusted_touch_transition, 1);
	if (thp_trusted_touch_get_vm_state(cd) != TVM_ALL_RESOURCES_LENT_NOTIFIED) {
		thp_vm_log_err(cd, "All lend notifications not received\n");
		thp_trusted_touch_event_notify(cd,
				TRUSTED_TOUCH_EVENT_NOTIFICATIONS_PENDING);
		return;
	}

	acl_desc = thp_vm_get_acl(GH_TRUSTED_VM);
	if (IS_ERR(acl_desc)) {
		thp_vm_log_err(cd, "failed to populated acl data:rc=%d\n",
				PTR_ERR(acl_desc));
		goto accept_fail;
	}

	sgl_desc = gh_rm_mem_accept(cd->vm_info->vm_mem_handle,
			GH_RM_MEM_TYPE_IO,
			GH_RM_TRANS_TYPE_LEND,
			GH_RM_MEM_ACCEPT_VALIDATE_ACL_ATTRS |
			GH_RM_MEM_ACCEPT_VALIDATE_LABEL |
			GH_RM_MEM_ACCEPT_DONE,  TRUSTED_TOUCH_MEM_LABEL,
			acl_desc, NULL, NULL, 0);
	if (IS_ERR_OR_NULL(sgl_desc)) {
		thp_vm_log_err(cd, "failed to do mem accept :rc=%d\n",
				PTR_ERR(sgl_desc));
		goto acl_fail;
	}
	thp_trusted_touch_set_vm_state(cd, TVM_IOMEM_ACCEPTED);

	/* Initiate session on tvm */
	rc = pm_runtime_get_sync(cd->sdev->master->dev.parent);

	if (rc < 0) {
		thp_vm_log_err(cd, "failed to get sync rc:%d\n", rc);
		goto acl_fail;
	}
	thp_trusted_touch_set_vm_state(cd, TVM_CLIENT_SESSION_ACQUIRED);

	expected_sgl_desc = thp_vm_get_sgl(cd, cd->vm_info);
	if (thp_vm_compare_sgl_desc(cd, expected_sgl_desc, sgl_desc)) {
		thp_vm_log_err(cd, "IO sg list does not match\n");
		goto sgl_cmp_fail;
	}

	kfree(expected_sgl_desc);
	kfree(acl_desc);

	irq = gh_irq_accept(cd->vm_info->irq_label, -1, IRQ_TYPE_EDGE_RISING);

	if (irq < 0) {
		thp_vm_log_err(cd, "failed to accept irq\n");
		goto accept_fail;
	}
	thp_trusted_touch_set_vm_state(cd, TVM_IRQ_ACCEPTED);

	irq_data = irq_get_irq_data(irq);
	if (!irq_data) {
		thp_vm_log_err(cd, "Invalid irq data for trusted touch\n");
		goto accept_fail;
	}
	if (!irq_data->hwirq) {
		thp_vm_log_err(cd, "Invalid irq in irq data\n");
		goto accept_fail;
	}

	if (irq_data->hwirq != cd->vm_info->hw_irq) {
		thp_vm_log_err(cd, "Invalid irq lent\n");
		goto accept_fail;
	}

	thp_vm_log_info(cd, "irq:returned from accept:%d hwirq %d\n", irq, irq_data->hwirq);
	cd->irq = irq;

	rc = thp_vm_handle_vm_hardware(cd);
	if (rc) {
		thp_vm_log_err(cd, " Delayed probe failure on VM!\n");
		goto accept_fail;
	}
	atomic_set(&cd->trusted_touch_transition, 0);
	atomic_set(&cd->trusted_touch_enabled, 1);
	thp_vm_log_info(cd, "trusted touch enabled\n");

	return;
sgl_cmp_fail:
	kfree(expected_sgl_desc);
acl_fail:
	kfree(acl_desc);
accept_fail:
	thp_trusted_touch_abort_handler(cd,
			TRUSTED_TOUCH_EVENT_ACCEPT_FAILURE);
}
static void thp_vm_irq_on_lend_callback(void *data,
					unsigned long notif_type,
					enum gh_irq_label label)
{
	struct thp_core_data *cd = data;

	thp_vm_log_info(cd, "received irq lend request for label:%d\n", label);
	if (thp_trusted_touch_get_vm_state(cd) == TVM_IOMEM_LENT_NOTIFIED)
		thp_trusted_touch_set_vm_state(cd, TVM_ALL_RESOURCES_LENT_NOTIFIED);
	else
		thp_trusted_touch_set_vm_state(cd, TVM_IRQ_LENT_NOTIFIED);
}

static void thp_vm_mem_on_lend_handler(enum gh_mem_notifier_tag tag,
		unsigned long notif_type, void *entry_data, void *notif_msg)
{
	struct gh_rm_notif_mem_shared_payload *payload;
	struct trusted_touch_vm_info *vm_info;
	struct thp_core_data *cd;

	cd = (struct thp_core_data *)entry_data;
	vm_info = cd->vm_info;
	if (!vm_info) {
		thp_vm_log_err(cd, "Invalid vm_info\n");
		return;
	}

	if (notif_type != GH_RM_NOTIF_MEM_SHARED ||
			tag != vm_info->mem_tag) {
		thp_vm_log_err(cd, "Invalid command passed from rm\n");
		return;
	}

	if (!entry_data || !notif_msg) {
		thp_vm_log_err(cd, "Invalid entry data passed from rm\n");
		return;
	}


	payload = (struct gh_rm_notif_mem_shared_payload  *)notif_msg;
	if (payload->trans_type != GH_RM_TRANS_TYPE_LEND ||
			payload->label != TRUSTED_TOUCH_MEM_LABEL) {
		thp_vm_log_err(cd, "Invalid label or transaction type\n");
		return;
	}

	vm_info->vm_mem_handle = payload->mem_handle;
	thp_vm_log_info(cd, "received mem lend request with handle:%d\n",
		vm_info->vm_mem_handle);
	if (thp_trusted_touch_get_vm_state(cd) == TVM_IRQ_LENT_NOTIFIED)
		thp_trusted_touch_set_vm_state(cd, TVM_ALL_RESOURCES_LENT_NOTIFIED);
	else
		thp_trusted_touch_set_vm_state(cd, TVM_IOMEM_LENT_NOTIFIED);
}

static int thp_vm_mem_release(struct thp_core_data *cd)
{
	int rc = 0;

	if (!cd->vm_info->vm_mem_handle) {
		thp_vm_log_err(cd, "Invalid memory handle\n");
		return -EINVAL;
	}

	rc = gh_rm_mem_release(cd->vm_info->vm_mem_handle, 0);
	if (rc)
		thp_vm_log_err(cd, "VM mem release failed: rc=%d\n", rc);

	rc = gh_rm_mem_notify(cd->vm_info->vm_mem_handle,
				GH_RM_MEM_NOTIFY_OWNER_RELEASED,
				cd->vm_info->mem_tag, 0);
	if (rc)
		thp_vm_log_err(cd, "Failed to notify mem release to PVM: rc=%d\n");
	thp_vm_log_info(cd, "vm mem release succeded\n");

	cd->vm_info->vm_mem_handle = 0;
	return rc;
}

static void thp_trusted_touch_tvm_vm_mode_disable(struct thp_core_data *cd)
{
	int rc = 0;

	atomic_set(&cd->trusted_touch_transition, 1);
	if (atomic_read(&cd->trusted_touch_abort_status)) {
		thp_trusted_touch_abort_tvm(cd);
		return;
	}

	disable_irq(cd->irq);

	thp_trusted_touch_set_vm_state(cd, TVM_INTERRUPT_DISABLED);

	rc = gh_irq_release(cd->vm_info->irq_label);
	if (rc) {
		thp_vm_log_err(cd, "Failed to release irq rc:%d\n", rc);
		goto error;
	} else {
		thp_trusted_touch_set_vm_state(cd, TVM_IRQ_RELEASED);
	}
	rc = gh_irq_release_notify(cd->vm_info->irq_label);
	if (rc)
		thp_vm_log_err(cd, "Failed to notify release irq rc:%d\n", rc);

	thp_vm_log_info(cd, "vm irq release succeded\n");

	pm_runtime_put_sync(cd->sdev->master->dev.parent);

	thp_trusted_touch_set_vm_state(cd, TVM_CLIENT_SESSION_RELEASED);
	rc = thp_vm_mem_release(cd);
	if (rc) {
		thp_vm_log_err(cd, "Failed to release mem rc:%d\n", rc);
		goto error;
	} else {
		thp_trusted_touch_set_vm_state(cd, TVM_IOMEM_RELEASED);
	}
	thp_trusted_touch_set_vm_state(cd, TRUSTED_TOUCH_TVM_INIT);

	atomic_set(&cd->trusted_touch_enabled, 0);
	atomic_set(&cd->trusted_touch_transition, 0);
	thp_vm_log_info(cd, "trusted touch disabled\n");
	return;
error:
	thp_trusted_touch_abort_handler(cd,
			TRUSTED_TOUCH_EVENT_RELEASE_FAILURE);
}

int thp_handle_trusted_touch_tvm(struct thp_core_data *cd, int value)
{
	int err = 0;

	thp_vm_log_info(cd, "%s called, value = %d", __func__, value);

	switch (value) {
	case 0:
		if ((atomic_read(&cd->trusted_touch_enabled) == 0) &&
			(atomic_read(&cd->trusted_touch_abort_status) == 0)) {
			thp_vm_log_err(cd, "Trusted touch is already disabled\n");
			break;
		}
		if (atomic_read(&cd->trusted_touch_mode) ==
				TRUSTED_TOUCH_VM_MODE) {
			thp_trusted_touch_tvm_vm_mode_disable(cd);
		} else {
			thp_vm_log_err(cd, "Unsupported trusted touch mode\n");
		}
		break;

	case 1:
		if (atomic_read(&cd->trusted_touch_enabled)) {
			thp_vm_log_err(cd, "Trusted touch usecase underway\n");
			err = -EBUSY;
			break;
		}
		if (atomic_read(&cd->trusted_touch_mode) ==
				TRUSTED_TOUCH_VM_MODE) {
			thp_trusted_touch_tvm_vm_mode_enable(cd);
		} else {
			thp_vm_log_err(cd, "Unsupported trusted touch mode\n");
		}
		break;

	default:
		thp_vm_log_err(cd, "unsupported value: %lu\n", value);
		err = -EINVAL;
		break;
	}

	return err;
}

static void thp_trusted_touch_abort_tvm(struct thp_core_data *cd)
{
	int rc = 0;
	int vm_state = thp_trusted_touch_get_vm_state(cd);

	if (vm_state >= TRUSTED_TOUCH_TVM_STATE_MAX) {
		thp_vm_log_err(cd, "invalid tvm driver state: %d\n", vm_state);
		return;
	}

	switch (vm_state) {
	case TVM_INTERRUPT_ENABLED:
		thp_set_irq_status(cd, THP_IRQ_DISABLE);
	case TVM_IRQ_ACCEPTED:
	case TVM_INTERRUPT_DISABLED:
		rc = gh_irq_release(cd->vm_info->irq_label);
		if (rc)
			thp_vm_log_err(cd, "Failed to release irq rc:%d\n", rc);
		rc = gh_irq_release_notify(cd->vm_info->irq_label);
		if (rc)
			thp_vm_log_err(cd, "Failed to notify irq release rc:%d\n", rc);
	case TVM_CLIENT_SESSION_ACQUIRED:
	case TVM_IOMEM_ACCEPTED:
	case TVM_IRQ_RELEASED:
		pm_runtime_put_sync(cd->sdev->master->dev.parent);
	case TVM_CLIENT_SESSION_RELEASED:
		rc = thp_vm_mem_release(cd);
		if (rc)
			thp_vm_log_err(cd, "Failed to release mem rc:%d\n", rc);
	case TVM_IOMEM_RELEASED:
	case TVM_ALL_RESOURCES_LENT_NOTIFIED:
	case TRUSTED_TOUCH_TVM_INIT:
	case TVM_IRQ_LENT_NOTIFIED:
	case TVM_IOMEM_LENT_NOTIFIED:
		atomic_set(&cd->trusted_touch_enabled, 0);
	}

	atomic_set(&cd->trusted_touch_abort_status, 0);
	thp_trusted_touch_set_vm_state(cd, TRUSTED_TOUCH_TVM_INIT);
}

#else

static void thp_bus_put(struct thp_core_data *cd);

static void thp_trusted_touch_abort_pvm(struct thp_core_data *cd)
{
	int rc = 0;
	int vm_state = thp_trusted_touch_get_vm_state(cd);

	if (vm_state >= TRUSTED_TOUCH_PVM_STATE_MAX) {
		thp_vm_log_err(cd, "Invalid driver state: %d\n", vm_state);
		return;
	}

	switch (vm_state) {
	case PVM_IRQ_RELEASE_NOTIFIED:
	case PVM_ALL_RESOURCES_RELEASE_NOTIFIED:
	case PVM_IRQ_LENT:
	case PVM_IRQ_LENT_NOTIFIED:
		rc = gh_irq_reclaim(cd->vm_info->irq_label);
		if (rc)
			thp_vm_log_err(cd, "failed to reclaim irq on pvm rc:%d\n", rc);
	case PVM_IRQ_RECLAIMED:
	case PVM_IOMEM_LENT:
	case PVM_IOMEM_LENT_NOTIFIED:
	case PVM_IOMEM_RELEASE_NOTIFIED:
		rc = gh_rm_mem_reclaim(cd->vm_info->vm_mem_handle, 0);
		if (rc)
			thp_vm_log_err(cd, "failed to reclaim iomem on pvm rc:%d\n", rc);
		cd->vm_info->vm_mem_handle = 0;
	case PVM_IOMEM_RECLAIMED:
	case PVM_INTERRUPT_DISABLED:
		thp_set_irq_status(cd, THP_IRQ_ENABLE);
	case PVM_I2C_RESOURCE_ACQUIRED:
	case PVM_INTERRUPT_ENABLED:
		thp_bus_put(cd);
	case TRUSTED_TOUCH_PVM_INIT:
	case PVM_I2C_RESOURCE_RELEASED:
		atomic_set(&cd->trusted_touch_enabled, 0);
		atomic_set(&cd->trusted_touch_transition, 0);
	}

	atomic_set(&cd->trusted_touch_abort_status, 0);

	thp_trusted_touch_set_vm_state(cd, TRUSTED_TOUCH_PVM_INIT);
}

static int thp_clk_prepare_enable(struct thp_core_data *cd)
{
	int ret;

	ret = clk_prepare_enable(cd->iface_clk);
	if (ret) {
		thp_vm_log_err(cd, "error on clk_prepare_enable(iface_clk):%d\n", ret);
		return ret;
	}

	ret = clk_prepare_enable(cd->core_clk);
	if (ret) {
		clk_disable_unprepare(cd->iface_clk);
		thp_vm_log_err(cd, "error clk_prepare_enable(core_clk):%d\n", ret);
	}
	return ret;
}

static void thp_clk_disable_unprepare(struct thp_core_data *cd)
{
	clk_disable_unprepare(cd->core_clk);
	clk_disable_unprepare(cd->iface_clk);
}

static int thp_bus_get(struct thp_core_data *cd)
{
	int rc = 0;
	struct device *dev = NULL;

	reinit_completion(&cd->trusted_touch_powerdown);
	dev = cd->sdev->master->dev.parent;

	mutex_lock(&cd->fts_clk_io_ctrl_mutex);
	rc = pm_runtime_get_sync(dev);
	if (rc >= 0 &&  cd->core_clk != NULL &&
				cd->iface_clk != NULL) {
		rc = thp_clk_prepare_enable(cd);
		if (rc)
			pm_runtime_put_sync(dev);
	}
	mutex_unlock(&cd->fts_clk_io_ctrl_mutex);

	return rc;
}

static void thp_bus_put(struct thp_core_data *cd)
{
	struct device *dev = NULL;

	dev = cd->sdev->master->dev.parent;

	mutex_lock(&cd->fts_clk_io_ctrl_mutex);
	if (cd->core_clk != NULL && cd->iface_clk != NULL)
		thp_clk_disable_unprepare(cd);
	pm_runtime_put_sync(dev);
	mutex_unlock(&cd->fts_clk_io_ctrl_mutex);
	complete(&cd->trusted_touch_powerdown);
}

static struct gh_notify_vmid_desc *thp_vm_get_vmid(gh_vmid_t vmid)
{
	struct gh_notify_vmid_desc *vmid_desc;

	vmid_desc = kzalloc(offsetof(struct gh_notify_vmid_desc,
				vmid_entries[1]), GFP_KERNEL);
	if (!vmid_desc)
		return ERR_PTR(ENOMEM);

	vmid_desc->n_vmid_entries = 1;
	vmid_desc->vmid_entries[0].vmid = vmid;
	return vmid_desc;
}

static void thp_trusted_touch_pvm_vm_mode_disable(struct thp_core_data *cd)
{
	int rc = 0;

	atomic_set(&cd->trusted_touch_transition, 1);

	if (atomic_read(&cd->trusted_touch_abort_status)) {
		thp_trusted_touch_abort_pvm(cd);
		return;
	}

	if (thp_trusted_touch_get_vm_state(cd) != PVM_ALL_RESOURCES_RELEASE_NOTIFIED) {
		thp_vm_log_err(cd, "all release notifications are not received yet\n");
		if (!wait_for_completion_timeout(&cd->tvm_release_finished, msecs_to_jiffies(200)))
			thp_vm_log_err(cd, "tvm resources release delay 200 ms\n");
		else
			thp_vm_log_info(cd, "tvm resources release finished\n");
	}

	rc = gh_rm_mem_reclaim(cd->vm_info->vm_mem_handle, 0);
	if (rc) {
		thp_vm_log_err(cd, "Trusted touch VM mem reclaim failed rc:%d\n", rc);
		goto error;
	}
	thp_trusted_touch_set_vm_state(cd, PVM_IOMEM_RECLAIMED);
	cd->vm_info->vm_mem_handle = 0;
	thp_vm_log_info(cd, "vm mem reclaim succeded!\n");

	rc = gh_irq_reclaim(cd->vm_info->irq_label);
	if (rc) {
		thp_vm_log_err(cd, "failed to reclaim irq on pvm rc:%d\n", rc);
		goto error;
	}
	thp_trusted_touch_set_vm_state(cd, PVM_IRQ_RECLAIMED);
	thp_vm_log_info(cd, "vm irq reclaim succeded!\n");

	thp_trusted_touch_set_vm_state(cd, PVM_INTERRUPT_ENABLED);
	thp_bus_put(cd);

	thp_trusted_touch_set_vm_state(cd, PVM_I2C_RESOURCE_RELEASED);
	thp_trusted_touch_set_vm_state(cd, TRUSTED_TOUCH_PVM_INIT);
	atomic_set(&cd->trusted_touch_enabled, 0);

	thp_vm_log_info(cd, "enable irq for exit tui here\n");
	enable_irq(cd->irq);
	atomic_set(&cd->tui_irq_disabled, 0);
	thp_set_status(cd, THP_STATUS_TUI, 0);

	if (cd->thp_dev && cd->thp_dev->ops && cd->thp_dev->ops->tui_enable_switch) {
		rc = cd->thp_dev->ops->tui_enable_switch(cd->thp_dev, TUI_DISABLE);
		if (rc) {
			thp_vm_log_err(cd, "%s: TUI disable failed\n", __func__);
			goto error;
		} else {
			atomic_set(&cd->tp_ic_tui_enabled, 0);
		}
	}

	if (!wait_for_completion_timeout(&cd->tp_ic_tui_exited,
			msecs_to_jiffies(2000))) {
		thp_vm_log_err(cd, "TP IC don't exit TUI mode in 2000 ms\n");
	}

	atomic_set(&cd->trusted_touch_transition, 0);

	thp_vm_log_info(cd, "trusted touch disabled\n");
	return;
error:
	thp_trusted_touch_abort_handler(cd,
			TRUSTED_TOUCH_EVENT_RECLAIM_FAILURE);
	atomic_set(&cd->trusted_touch_transition, 0);
}

static void thp_vm_irq_on_release_callback(void *data,
					unsigned long notif_type,
					enum gh_irq_label label)
{
	struct thp_core_data *cd = data;

	if (notif_type != GH_RM_NOTIF_VM_IRQ_RELEASED) {
		thp_vm_log_err(cd, "invalid notification type\n");
		return;
	}

	if (thp_trusted_touch_get_vm_state(cd) == PVM_IOMEM_RELEASE_NOTIFIED) {
		thp_trusted_touch_set_vm_state(cd, PVM_ALL_RESOURCES_RELEASE_NOTIFIED);
		complete_all(&cd->tvm_release_finished);
	}
	else
		thp_trusted_touch_set_vm_state(cd, PVM_IRQ_RELEASE_NOTIFIED);
}

static void thp_vm_mem_on_release_handler(enum gh_mem_notifier_tag tag,
		unsigned long notif_type, void *entry_data, void *notif_msg)
{
	struct gh_rm_notif_mem_released_payload *release_payload;
	struct trusted_touch_vm_info *vm_info;
	struct thp_core_data *cd;

	cd = (struct thp_core_data *)entry_data;
	vm_info = cd->vm_info;
	if (!vm_info) {
		thp_vm_log_err(cd, " Invalid vm_info\n");
		return;
	}

	if (notif_type != GH_RM_NOTIF_MEM_RELEASED) {
		thp_vm_log_err(cd, " Invalid notification type\n");
		return;
	}

	if (tag != vm_info->mem_tag) {
		thp_vm_log_err(cd, " Invalid tag\n");
		return;
	}

	if (!entry_data || !notif_msg) {
		thp_vm_log_err(cd, " Invalid data or notification message\n");
		return;
	}

	release_payload = (struct gh_rm_notif_mem_released_payload  *)notif_msg;
	if (release_payload->mem_handle != vm_info->vm_mem_handle) {
		thp_vm_log_err(cd, "Invalid mem handle detected\n");
		return;
	}

	if (thp_trusted_touch_get_vm_state(cd) == PVM_IRQ_RELEASE_NOTIFIED) {
		thp_trusted_touch_set_vm_state(cd, PVM_ALL_RESOURCES_RELEASE_NOTIFIED);
		complete_all(&cd->tvm_release_finished);
	}
	else
		thp_trusted_touch_set_vm_state(cd, PVM_IOMEM_RELEASE_NOTIFIED);
}

static int thp_vm_mem_lend(struct thp_core_data *cd)
{
	struct gh_acl_desc *acl_desc;
	struct gh_sgl_desc *sgl_desc;
	struct gh_notify_vmid_desc *vmid_desc;
	gh_memparcel_handle_t mem_handle;
	gh_vmid_t trusted_vmid;
	int rc = 0;

	acl_desc = thp_vm_get_acl(GH_TRUSTED_VM);
	if (IS_ERR(acl_desc)) {
		thp_vm_log_err(cd, "Failed to get acl of IO memories for Trusted touch\n");
		return PTR_ERR(acl_desc);
	}

	sgl_desc = thp_vm_get_sgl(cd, cd->vm_info);
	if (IS_ERR(sgl_desc)) {
		thp_vm_log_err(cd, "Failed to get sgl of IO memories for Trusted touch\n");
		rc = PTR_ERR(sgl_desc);
		goto sgl_error;
	}

	rc = gh_rm_mem_lend(GH_RM_MEM_TYPE_IO, 0, TRUSTED_TOUCH_MEM_LABEL,
			acl_desc, sgl_desc, NULL, &mem_handle);
	if (rc) {
		thp_vm_log_err(cd, "Failed to lend IO memories for Trusted touch rc:%d\n",
							rc);
		goto error;
	}

	thp_vm_log_info(cd, "vm mem lend succeded\n");

	thp_trusted_touch_set_vm_state(cd, PVM_IOMEM_LENT);

	gh_rm_get_vmid(GH_TRUSTED_VM, &trusted_vmid);

	vmid_desc = thp_vm_get_vmid(trusted_vmid);

	rc = gh_rm_mem_notify(mem_handle, GH_RM_MEM_NOTIFY_RECIPIENT_SHARED,
			cd->vm_info->mem_tag, vmid_desc);
	if (rc) {
		thp_vm_log_err(cd, "Failed to notify mem lend to hypervisor rc:%d\n", rc);
		goto vmid_error;
	}

	thp_trusted_touch_set_vm_state(cd, PVM_IOMEM_LENT_NOTIFIED);

	cd->vm_info->vm_mem_handle = mem_handle;
vmid_error:
	kfree(vmid_desc);
error:
	kfree(sgl_desc);
sgl_error:
	kfree(acl_desc);

	return rc;
}

static int thp_trusted_touch_pvm_vm_mode_enable(struct thp_core_data *cd)
{
	int rc = 0;
	struct trusted_touch_vm_info *vm_info = cd->vm_info;

	atomic_set(&cd->trusted_touch_transition, 1);
	mutex_lock(&cd->transition_lock);

	// if it is in suspend, just ignore this request.
	if (cd->suspended) {
		thp_vm_log_err(cd, "Invalid power state for operation\n");
		atomic_set(&cd->trusted_touch_transition, 0);
		rc =  -EPERM;
		goto perm_error;
	}

	// set tui mode to tp ic
	reinit_completion(&cd->tp_ic_tui_entered);
	reinit_completion(&cd->tp_ic_tui_exited);
	reinit_completion(&cd->tvm_release_finished);
	thp_set_status(cd, THP_STATUS_TUI, 1);
	if (!wait_for_completion_timeout(&cd->tp_ic_tui_entered,
				msecs_to_jiffies(2000))) {
		thp_vm_log_err(cd, "TP IC don't enter TUI mode in 2000 ms\n");
		rc = -EBUSY;
		goto error;
	}

	if (cd->thp_dev && cd->thp_dev->ops && cd->thp_dev->ops->tui_enable_switch) {
		rc = cd->thp_dev->ops->tui_enable_switch(cd->thp_dev, TUI_ENABLE);
		if (rc) {
			thp_vm_log_err(cd, "%s: TUI enable failed \n", __func__);
			goto error;
		} else {
			atomic_set(&cd->tp_ic_tui_enabled, 1);
		}
	}

	/* flush pending interurpts from FIFO */
	thp_vm_log_info(cd, "disable irq for tui here\n");
	disable_irq(cd->irq);
	atomic_set(&cd->tui_irq_disabled, 1);
	thp_trusted_touch_set_vm_state(cd, PVM_INTERRUPT_DISABLED);

	/* client session start and resource acquire */
	if (thp_bus_get(cd) < 0) {
		thp_vm_log_err(cd, "thp_bus_get failed\n");
		rc = -EIO;
		goto error;
	}
	thp_trusted_touch_set_vm_state(cd, PVM_I2C_RESOURCE_ACQUIRED);

	rc = thp_vm_mem_lend(cd);
	if (rc) {
		thp_vm_log_err(cd, "Failed to lend memory\n");
		goto abort_handler;
	}
	thp_vm_log_info(cd, "vm mem lend succeded\n");

	rc = gh_irq_lend_v2(vm_info->irq_label, vm_info->vm_name,
		cd->irq, &thp_vm_irq_on_release_callback, cd);
	if (rc) {
		thp_vm_log_err(cd, "Failed to lend irq\n");
		goto abort_handler;
	}

	thp_vm_log_info(cd, "vm irq lend succeded for irq:%d\n", cd->irq);
	thp_trusted_touch_set_vm_state(cd, PVM_IRQ_LENT);

	rc = gh_irq_lend_notify(vm_info->irq_label);
	if (rc) {
		thp_vm_log_err(cd, "Failed to notify irq\n");
		goto abort_handler;
	}
	thp_trusted_touch_set_vm_state(cd, PVM_IRQ_LENT_NOTIFIED);

	mutex_unlock(&cd->transition_lock);
	atomic_set(&cd->trusted_touch_transition, 0);
	atomic_set(&cd->trusted_touch_enabled, 1);
	thp_vm_log_info(cd, "trusted touch enabled\n");
	return rc;

abort_handler:
	thp_trusted_touch_abort_handler(cd, TRUSTED_TOUCH_EVENT_LEND_FAILURE);

error:
	thp_set_status(cd, THP_STATUS_TUI, 0);

perm_error:
	atomic_set(&cd->trusted_touch_transition, 0);
	mutex_unlock(&cd->transition_lock);
	return rc;
}

int thp_handle_trusted_touch_pvm(struct thp_core_data *cd, int value)
{
	int err = 0;

	thp_vm_log_info(cd, "%s called, value = %d", __func__, value);

	switch (value) {
	case 0:
		if (atomic_read(&cd->trusted_touch_enabled) == 0 &&
			(atomic_read(&cd->trusted_touch_abort_status) == 0)) {
			thp_vm_log_err(cd, "Trusted touch is already disabled\n");
			break;
		}
		if (atomic_read(&cd->trusted_touch_mode) ==
				TRUSTED_TOUCH_VM_MODE) {
			thp_trusted_touch_pvm_vm_mode_disable(cd);
		} else {
			thp_vm_log_err(cd, "Unsupported trusted touch mode\n");
		}
		break;

	case 1:
		if (atomic_read(&cd->trusted_touch_enabled)) {
			thp_vm_log_err(cd, "Trusted touch usecase underway\n");
			err = -EBUSY;
			break;
		}
		if (atomic_read(&cd->trusted_touch_mode) ==
				TRUSTED_TOUCH_VM_MODE) {
			err = thp_trusted_touch_pvm_vm_mode_enable(cd);
		} else {
			thp_vm_log_err(cd, "Unsupported trusted touch mode\n");
		}
		break;

	default:
		thp_vm_log_err(cd, "unsupported value: %lu\n", value);
		err = -EINVAL;
		break;
	}
	return err;
}

#endif

static void thp_trusted_touch_event_notify(struct thp_core_data *cd, int event)
{
	atomic_set(&cd->trusted_touch_event, event);
	sysfs_notify(&cd->dev->kobj, NULL, "trusted_touch_event");
}

static void thp_trusted_touch_abort_handler(struct thp_core_data *cd, int error)
{
	atomic_set(&cd->trusted_touch_abort_status, error);
	thp_vm_log_err(cd, "TUI session aborted with failure:%d\n", error);
	thp_trusted_touch_event_notify(cd, error);
}

#ifdef CONFIG_ARCH_QTI_VM
DEFINE_MUTEX(g_msgq_create_mutex);
#endif
static int thp_vm_init(struct thp_core_data *cd)
{
	int rc = 0;
	struct trusted_touch_vm_info *vm_info;
	void *mem_cookie;

	thp_vm_log_info(cd, "%s called\n", __func__);

	rc = thp_populate_vm_info(cd);
	if (rc) {
		thp_vm_log_err(cd, "Cannot setup vm pipeline\n");
		rc = -EINVAL;
		goto fail;
	}

	vm_info = cd->vm_info;
#ifdef CONFIG_ARCH_QTI_VM
	mutex_lock(&g_msgq_create_mutex);
	if (!g_msgq_reg) {
		g_msgq_reg = gh_msgq_register(cd->trusted_touch_msgq);
		if (!g_msgq_reg) {
			thp_vm_log_err(cd, "Failed to register on lend mem notifier\n");
			rc = -EINVAL;
			mutex_unlock(&g_msgq_create_mutex);
			goto init_fail;
		}
		thp_vm_log_info(cd, "%s gh_msgq_register suc\n", __func__);
	} else {
		thp_vm_log_info(cd, "msgq already register\n");
	}
	mutex_unlock(&g_msgq_create_mutex);
	vm_info->input_msgq = g_msgq_reg;

	mem_cookie = gh_mem_notifier_register(vm_info->mem_tag,
			thp_vm_mem_on_lend_handler, cd);
	if (!mem_cookie) {
		thp_vm_log_err(cd, "Failed to register on lend mem notifier\n");
		rc = -EINVAL;
		goto init_fail;
	}
	vm_info->mem_cookie = mem_cookie;
	rc = gh_irq_wait_for_lend_v2(vm_info->irq_label, GH_PRIMARY_VM,
			&thp_vm_irq_on_lend_callback, cd);

	thp_trusted_touch_set_vm_state(cd, TRUSTED_TOUCH_TVM_INIT);
#else
	mem_cookie = gh_mem_notifier_register(vm_info->mem_tag,
			thp_vm_mem_on_release_handler, cd);
	if (!mem_cookie) {
		thp_vm_log_err(cd, "Failed to register on release mem notifier\n");
		rc = -EINVAL;
		goto init_fail;
	}
	vm_info->mem_cookie = mem_cookie;
	thp_trusted_touch_set_vm_state(cd, TRUSTED_TOUCH_PVM_INIT);
#endif
	return rc;
init_fail:
	thp_vm_deinit(cd);
fail:
	return rc;
}

static void thp_dt_parse_trusted_touch_info(struct thp_core_data *cd)
{
	struct device_node *np = cd->dev->of_node;
	int rc = 0;
	const char *selection;
	const char *environment;
	/*
	 * 0x24 default Trusted touch message queue,
	 * Can be modified later of dtsi.
	 */
	int trusted_touch_msgq = 0x24;

#ifdef CONFIG_ARCH_QTI_VM
	cd->touch_environment = "tvm";
#else
	cd->touch_environment = "pvm";
#endif

	rc = of_property_read_string(np, "trusted-touch-mode",
								&selection);
	if (rc) {
		thp_vm_log_err(cd, "%s: No trusted touch mode selection made\n", __func__);
		atomic_set(&cd->trusted_touch_mode,
						TRUSTED_TOUCH_MODE_NONE);
		return;
	}

	if (!strcmp(selection, "vm_mode")) {
		atomic_set(&cd->trusted_touch_mode,
						TRUSTED_TOUCH_VM_MODE);
		thp_vm_log_err(cd, "Selected trusted touch mode to VM mode\n");
	} else {
		atomic_set(&cd->trusted_touch_mode,
						TRUSTED_TOUCH_MODE_NONE);
		thp_vm_log_err(cd, "Invalid trusted_touch mode\n");
	}

	rc = of_property_read_string(np, "touch-environment",
						&environment);
	if (rc)
		thp_vm_log_err(cd, "%s: No trusted touch mode environment\n", __func__);
	cd->touch_environment = environment;
	thp_vm_log_info(cd, "Trusted touch environment:%s\n", cd->touch_environment);

	rc = of_property_read_u32(np, "trusted-touch-msgq",
						&trusted_touch_msgq);
	if (rc)
		thp_vm_log_err(cd, "%s: No Trusted touch message queue\n", __func__);
	cd->trusted_touch_msgq = trusted_touch_msgq;
}

// These event type and structure should be same with htee side.
#define TYPE_TOUCH 64
#define TYPE_RELEASE 32
struct event_node {
	int32_t status;
	int32_t x;
	int32_t y;
};
void thp_tui_report_to_htee(struct thp_core_data *cd, struct thp_udfp_data udfp_data)
{
	struct event_node event;
	int ret = 0;

	event.x = udfp_data.tpud_data.tp_x;
	event.y = udfp_data.tpud_data.tp_y;

	if (udfp_data.tpud_data.udfp_event == TP_EVENT_FINGER_DOWN)
		event.status = TYPE_TOUCH;
	else if (udfp_data.tpud_data.udfp_event == TP_EVENT_FINGER_UP)
		event.status = TYPE_RELEASE;
	else
		return;

	ret = gh_msgq_send(cd->vm_info->input_msgq, &event, sizeof(event), GH_MSGQ_TX_PUSH);
	if (ret < 0)
		thp_vm_log_err(cd, "%s failed to send input data: %d\n", __func__, ret);
	thp_vm_log_info(cd, "%s ->done,(%u, %u, %d)\n", __func__, event.x, event.y, event.status);
}

void thp_trusted_touch_init(struct thp_core_data *cd)
{
	int rc = 0;

	atomic_set(&cd->trusted_touch_initialized, 0);
	thp_dt_parse_trusted_touch_info(cd);

	if (atomic_read(&cd->trusted_touch_mode) == TRUSTED_TOUCH_MODE_NONE)
		return;

	init_completion(&cd->trusted_touch_powerdown);
	init_completion(&cd->tp_ic_tui_entered);
	init_completion(&cd->tp_ic_tui_exited);
	init_completion(&cd->tvm_release_finished);

	/* Get clocks */
	cd->core_clk = devm_clk_get(cd->dev->parent,
						"m-ahb");
	if (IS_ERR(cd->core_clk)) {
		cd->core_clk = NULL;
		thp_vm_log_err(cd, "%s: core_clk is not defined\n", __func__);
	}

	cd->iface_clk = devm_clk_get(cd->dev->parent,
						"se-clk");
	if (IS_ERR(cd->iface_clk)) {
		cd->iface_clk = NULL;
		thp_vm_log_err(cd, "%s: iface_clk is not defined\n", __func__);
	}

	if (atomic_read(&cd->trusted_touch_mode) ==
						TRUSTED_TOUCH_VM_MODE) {
		rc = thp_vm_init(cd);
		if (rc)
			thp_vm_log_err(cd, "Failed to init VM\n");
	}
	atomic_set(&cd->tp_ic_tui_enabled, 0);
	atomic_set(&cd->trusted_touch_initialized, 1);
}
#endif


