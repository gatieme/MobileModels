#include <linux/shmec/shmec.h>
#include <linux/printk.h>
#include <linux/slab.h>
#include <linux/mm.h>
#include <asm/compiler.h>

#include <stdarg.h>

#include "rbuffer.h"

#define SHMEC_BUFFER_SIZE (PAGE_SIZE * 4)
#define SHMEC_MIN_SEND_BUFFER_SIZE	8
#define SHMEC_RECV_TIMES	2
#define SHMEC_MIN_IRQ	32U
#define SHMEC_MAX_IRQ	1020U
#define SHMEC_UNUSED_ARG	0U
#define SHMEC_EC_CALL_ARG	8U

#define SHMEC_DETACH_OR_DELETE_ARG_NUM	2U
#define SHMEC_SENT_ARG_NUM		4U
#define SHMEC_CREATE_ARG_NUM	5U
#define SHMEC_ATTACH_ARG_NUM	6U

#ifndef __asmeq
#define __asmeq(x, y)  ".ifnc " x "," y " ; .err ; .endif\n\t"
#endif

struct shmec_ep {
    int ep_idx;
    phys_addr_t shmec_buf_paddr;
    void *shmec_buf;
    struct rbuffer_s shmec_rb;
};

static inline unsigned long ec_call(unsigned long num, ...)
{
	unsigned long arg[SHMEC_EC_CALL_ARG];
	va_list valist;
	if (num < 1 || num > 8) {
		pr_err("shmec ec call invalid num, %lu\n", num);
		return -EINVAL;
	}

	va_start(valist, num);
	for (unsigned long i = 0; i < SHMEC_EC_CALL_ARG; ++i) {
		if (i < num) {
			arg[i] = va_arg(valist, unsigned long);
		} else {
			arg[i] = SHMEC_UNUSED_ARG;
		}
	}
	va_end(valist);

	register unsigned long arg0 asm("x0") = arg[0];
	register unsigned long arg1 asm("x1") = arg[1];
	register unsigned long arg2 asm("x2") = arg[2];
	register unsigned long arg3 asm("x3") = arg[3];
	register unsigned long arg4 asm("x4") = arg[4];
	register unsigned long arg5 asm("x5") = arg[5];
	register unsigned long arg6 asm("x6") = arg[6];
	register unsigned long arg7 asm("x7") = arg[7];
	asm volatile(
		__asmeq("%0", "x0")
		__asmeq("%1", "x1")
		__asmeq("%2", "x2")
		__asmeq("%3", "x3")
		__asmeq("%4", "x4")
		__asmeq("%5", "x5")
		__asmeq("%6", "x6")
		__asmeq("%7", "x7")
		"hvc #0\n"
		: "+r" (arg0)
		: "r" (arg1), "r" (arg2), "r" (arg3), "r" (arg4),
		  "r" (arg5), "r" (arg6), "r" (arg7));

	return arg0;
}

int shmec_attach(const struct shmec_ep *endpoint, const char *chn, size_t size, int flag, mode_t mode)
{
	if (endpoint == NULL || chn == NULL || size == 0) {
		pr_err("shmec attach: parameters are invalid, endpoint=%lx, chn=%s, size=%lu", endpoint, chn, size);
		return -EINVAL;
	}

	long ret = ec_call(SHMEC_ATTACH_ARG_NUM, EC_VM_CMD_CONNECT, endpoint->ep_idx,
                      (unsigned long)virt_to_phys(chn), size, flag, mode);
	if (ret < 0) {
		pr_err("failed to attach event channel, chn=%s, ep_idx=%d, ret=%ld\n", chn, endpoint->ep_idx, ret);
		return -EFAULT;
	}
	return 0;
}

int shmec_detach(const struct shmec_ep *endpoint)
{
	if (endpoint == NULL) {
		pr_err("shmec detach parameter is invalid, endpoint is NULL\n");
		return -EINVAL;
	}

	long ret = ec_call(SHMEC_DETACH_OR_DELETE_ARG_NUM, EC_VM_CMD_DISCONNECT, endpoint->ep_idx);
	if (ret < 0) {
		pr_err("failed to detach event channel, ep_idx=%d, ret=%ld\n", endpoint->ep_idx, ret);
	}
	return 0;
}

int shmec_send_event(const struct shmec_ep *endpoint, const void *buf, size_t size)
{
	if (endpoint == NULL || buf == NULL || size < SHMEC_MIN_SEND_BUFFER_SIZE) {
		pr_err("send event parameters is invalid: endpoint=%lx, buf=%lx, size=%llu\n",
                endpoint, buf, (unsigned long long)size);
		return -EINVAL;
	}
	long ret = ec_call(SHMEC_SENT_ARG_NUM, EC_VM_CMD_SEND_EVENT, endpoint->ep_idx, virt_to_phys(buf), size);
	if (ret < 0) {
		pr_err("failed to send event, ep_idx=%d, ret=%ld\n", endpoint->ep_idx, ret);
		return -EFAULT;
	}

	return 0;
}

int shmec_recv_event(struct shmec_ep *endpoint, void *buf, size_t size)
{
	int ret = 0;
	if (endpoint == NULL || buf == NULL || size == 0) {
		pr_err("shmec receive event parameters are invalid, endpoint=%lx, buf=%lx, size=%llu\n",
				endpoint, buf, (unsigned long long)size);
		return -EINVAL;
	}

	for (int i = 0; i < SHMEC_RECV_TIMES; i++) {
		ret = rb_try_read_entry(&endpoint->shmec_rb, buf, size, NULL);
		if (ret > 0) {
			break;
		}
	}

	if (ret == 0) {
		pr_err("failed to read shmec receive event, ep_idx=%d\n", endpoint->ep_idx);
		return -EFAULT;
	}

	return ret;
}

static int shmec_init_buffer(struct shmec_ep *endpoint)
{
	void *buf = kmalloc(SHMEC_BUFFER_SIZE, GFP_KERNEL);
	if (buf == NULL) {
		pr_err("failed to malloc shmec buffer\n");
		return -EFAULT;
	}

	memset_s(buf, SHMEC_BUFFER_SIZE , 0x78, SHMEC_BUFFER_SIZE);
	endpoint->shmec_buf = buf;
	endpoint->shmec_buf_paddr = virt_to_phys(buf);
	int ret = rb_init(&endpoint->shmec_rb, buf, SHMEC_BUFFER_SIZE, 2, RB_RDONLY);
	if (ret < 0) {
		kfree(buf);
		pr_err("failed to init shmec ring buffer, ret=%d\n", ret);
		return ret;
	}

	return 0;
}

struct shmec_ep *shmec_create_endpoint(uint64_t flags, int irq)
{
	long ret;

	if ((flags & (EC_EP_SRC | EC_EP_DST)) == 0 || irq < SHMEC_MIN_IRQ || irq > SHMEC_MAX_IRQ) {
		pr_err("shmec create endpoint invalid flags:%lu, irq:%d\n", flags, irq);
		return NULL;
	}

	struct shmec_ep *endpoint = kmalloc(sizeof(struct shmec_ep), GFP_KERNEL);
	if (endpoint == NULL) {
		pr_err("failed to create shmec endpoiont\n");
		return NULL;
	}
	memset_s(endpoint, sizeof(struct shmec_ep), 0, sizeof(struct shmec_ep));

	if (flags & EC_EP_DST) {
		ret = shmec_init_buffer(endpoint);
		if (ret < 0) {
			kfree(endpoint);
			return NULL;
		}
	}

	ret = ec_call(SHMEC_CREATE_ARG_NUM, EC_VM_CMD_CREATE, flags, irq, endpoint->shmec_buf_paddr, SHMEC_BUFFER_SIZE);
	if (ret < 0) {
		pr_err("failed to create event channel,ret=%ld\n", ret);
		kfree(endpoint);
		return NULL;
	}
	endpoint->ep_idx = ret;
	pr_info("create shmec endpoint success, ep_idx=%d\n", endpoint->ep_idx);
	return endpoint;
}

int shmec_delete_endpoint(struct shmec_ep *endpoint)
{
	if (endpoint == NULL) {
		pr_err("endpoint is NULL\n");
		return -EINVAL;
	}

	long ret = ec_call(SHMEC_DETACH_OR_DELETE_ARG_NUM, EC_VM_CMD_DESTROY, endpoint->ep_idx);
	if (ret < 0) {
		pr_err("failed to delete endpoint, ep_idx=%d, ret=%ld\n", endpoint->ep_idx, ret);
		return -EFAULT;
	}
	pr_info("shmec delete endpoint success, ep_idx=%d\n", endpoint->ep_idx);
	if (endpoint->shmec_buf != NULL) {
		kfree(endpoint->shmec_buf);
	}
	kfree(endpoint);
	return 0;
}
