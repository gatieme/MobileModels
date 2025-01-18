/*
 * Copyright (C) 2004-2020 Jens Axboe <axboe@suse.de> SUSE Labs
 *
 * Discription: blk_scsi_kern.c - block layer implementation of the sg v4 interface
 *  This file is subject to the terms and conditions of the GNU General Public
 *  License version 2.  See the file "COPYING" in the main directory of this
 *  archive for more details.
 *
 */
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/file.h>
#include <linux/blkdev.h>
#include <linux/poll.h>
#include <linux/cdev.h>
#include <linux/jiffies.h>
#include <linux/percpu.h>
#include <linux/uio.h>
#include <linux/idr.h>
#include <linux/bsg.h>
#include <linux/slab.h>

#include <scsi/scsi.h>
#include <scsi/scsi_ioctl.h>
#include <scsi/scsi_cmnd.h>
#include <scsi/scsi_device.h>
#include <scsi/scsi_driver.h>
#include <scsi/sg.h>
#include <scsi/scsi_request.h>
#include <linux/types.h>
#include <linux/version.h>
#if defined(CONFIG_MAS_ORDER_PRESERVE) || defined(CONFIG_MAS_UNISTORE_PRESERVE)
#include "mas_blk.h"
#endif
#include <securec.h>

#define TIME_RECORD_COUNT 3
#define IO_RECORD_COUNT 3

struct rpmb_time_blk_record {
	u64 req_get_done[IO_RECORD_COUNT];
	u64 req_exec_start[IO_RECORD_COUNT];
	u64 req_exec_end[IO_RECORD_COUNT];
};

static struct rpmb_time_blk_record rpmb_time_blk_point[TIME_RECORD_COUNT];

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
void blk_scsi_kern_time_stamp_dump(void)
{
	int i, j;

	for (i = 0; i < TIME_RECORD_COUNT; i++)
		for (j = 0; j < IO_RECORD_COUNT; j++)
			pr_err("source %d, req_get %llu, start %llu, end %llu\n", i,
					rpmb_time_blk_point[i].req_get_done[j],
					rpmb_time_blk_point[i].req_exec_start[j],
					rpmb_time_blk_point[i].req_exec_end[j]);
}
#endif
enum time_record_type {
	REQ_GET_DONE,
	REQ_EXEC_START,
	REQ_EXEC_END,
};

static void blk_scsi_kern_time_record(enum time_record_type type,
				      unsigned int source_id,
				      unsigned int io_cnt)
{
	if (source_id >= TIME_RECORD_COUNT || io_cnt >= IO_RECORD_COUNT) {
		pr_err("%s: out of bound\n", __func__);
		return;
	}
	switch(type) {
	case REQ_GET_DONE:
		rpmb_time_blk_point[source_id].req_get_done[io_cnt] =
			dfx_getcurtime();
		break;
	case REQ_EXEC_START:
		rpmb_time_blk_point[source_id].req_exec_start[io_cnt] =
			dfx_getcurtime();
		break;
	case REQ_EXEC_END:
		rpmb_time_blk_point[source_id].req_exec_end[io_cnt] =
			dfx_getcurtime();
		break;
	}
}

static int blk_kern_fill_sgv4_hdr_rq(struct request_queue *q,
					  struct request *rq,
					  struct sg_io_v4 *hdr)
{
	struct scsi_request *req = scsi_req(rq);

	if (hdr->request_len > BLK_MAX_CDB) {
		req->cmd = kzalloc((size_t)hdr->request_len, GFP_KERNEL);
		if (!req->cmd)
			return -ENOMEM;
	}

	memcpy((void *)req->cmd, /* unsafe_function_ignore: memcpy */
	       (void *)(uintptr_t)hdr->request,
	       (unsigned long)hdr->request_len);

	/*
	 * fill in request structure
	 */
	req->cmd_len = (unsigned short)hdr->request_len;

	rq->timeout = (unsigned int)msecs_to_jiffies(hdr->timeout);
	if (!rq->timeout)
		rq->timeout = q->sg_timeout;
	if (!rq->timeout)
		rq->timeout = BLK_DEFAULT_SG_TIMEOUT;
	if (rq->timeout < BLK_MIN_SG_TIMEOUT)
		rq->timeout = BLK_MIN_SG_TIMEOUT;

	return 0;
}

/*
 * Check if sg_io_v4 from kernel is allowed and valid
 */
static int blk_kern_validate_sgv4_hdr(struct sg_io_v4 *hdr,
					   int *op)
{
	int ret = 0;

	if (hdr->guard != 'Q')
		return -EINVAL;

	switch (hdr->protocol) {
	case BSG_PROTOCOL_SCSI:
		switch (hdr->subprotocol) {
		case BSG_SUB_PROTOCOL_SCSI_CMD:
		case BSG_SUB_PROTOCOL_SCSI_TRANSPORT:
			break;
		default:
			ret = -EINVAL;
		}
		break;
	default:
		ret = -EINVAL;
	}

	*op = hdr->dout_xfer_len ? REQ_OP_SCSI_OUT : REQ_OP_SCSI_IN;
	return ret;
}

static struct request *blk_kern_map_hdr_queue(struct request_queue *q,
					struct sg_io_v4 *hdr,
					unsigned int source_id, unsigned int io_cnt)
{
	struct request *rq = NULL;
	int ret, op;
	unsigned int dxfer_len;
	void *dxferp = NULL;

	ret = blk_kern_validate_sgv4_hdr(hdr, &op);
	if (ret)
		return ERR_PTR(ret);

	/*
	 * map scatter-gather elements separately and string them to request
	 */
	rq = blk_get_request(q, op, 0);
	if (IS_ERR(rq))
		return rq;

	blk_scsi_kern_time_record(REQ_GET_DONE, source_id, io_cnt);
	ret = blk_kern_fill_sgv4_hdr_rq(q, rq, hdr);
	if (ret)
		goto out;

	if (hdr->dout_xfer_len) {
		dxfer_len = hdr->dout_xfer_len;
		dxferp = (void *)(uintptr_t)hdr->dout_xferp;
	} else if (hdr->din_xfer_len) {
		dxfer_len = hdr->din_xfer_len;
		dxferp = (void *)(uintptr_t)hdr->din_xferp;
	} else {
		dxfer_len = 0;
	}

	if (dxfer_len) {
		ret = blk_rq_map_kern(q, rq, dxferp, dxfer_len, GFP_KERNEL);
		if (ret)
			goto out;
	}

	return rq;
out:
	scsi_req_free_cmd(scsi_req(rq));
	blk_put_request(rq);
	return ERR_PTR(ret);
}

/*
 * map sg_io_v4 to a request.
 */
static struct request *blk_kern_map_hdr(struct bsg_device *bd,
					struct sg_io_v4 *hdr,
					unsigned int source_id, unsigned int io_cnt)
{
	struct request_queue *q = bd->queue;
	struct bsg_class_device *bcd = &q->bsg_dev;

	/* if the LLD has been removed then the bsg_unregister_queue will
	 * eventually be called and the class_dev was freed, so we can no
	 * longer use this request_queue. Return no such address.
	 */
	if (!bcd->class_dev)
		return ERR_PTR(-ENXIO);

	return blk_kern_map_hdr_queue(q, hdr, source_id, io_cnt);
}

static int blk_kern_complete_hdr_rq(struct request *rq, struct sg_io_v4 *hdr)
{
	struct scsi_request *req = scsi_req(rq);
	int ret = 0;

	/*
	 * fill in all the output members
	 */
	hdr->device_status = (unsigned int)req->result & 0xff;
	hdr->transport_status = host_byte((unsigned int)(req->result));
	hdr->driver_status = driver_byte((unsigned int)(req->result));
	hdr->info = 0;
	if (hdr->device_status || hdr->transport_status || hdr->driver_status)
		hdr->info |= SG_INFO_CHECK;
	hdr->response_len = 0;

	if (req->sense_len && hdr->response) {
		unsigned int len = min_t(unsigned int, hdr->max_response_len,
				req->sense_len);

		memcpy((void *)(uintptr_t)hdr->response, /* unsafe_function_ignore: memcpy */
		       req->sense,
		       (unsigned long)len);
		hdr->response_len = len;
	}

	if (rq_data_dir(rq) == READ)
		hdr->din_resid = (__s32)req->resid_len;
	else
		hdr->dout_resid = (__s32)req->resid_len;

	/*
	 * If the request generated a negative error number, return it
	 * (providing we aren't already returning an error); if it's
	 * just a protocol response (i.e. non negative), that gets
	 * processed above.
	 */
	if (!ret && req->result < 0)
		ret = req->result;

	scsi_req_free_cmd(req);
	blk_put_request(rq);

	return ret;
}

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
long blk_scsi_kern_ioctl(unsigned int fd, unsigned long arg, bool need_order,
			 unsigned int source_id, unsigned int io_cnt)
{
	int *uarg = (int *)(uintptr_t)arg;
	int ret;
	struct request *rq = NULL;
	struct sg_io_v4 hdr;
	int at_head;
	struct bsg_device *bd = NULL;
	struct file *pfile = fget(fd);
	if (pfile == NULL)
		return -EFAULT;
	bd = (struct bsg_device *)pfile->private_data;
	memcpy(&hdr, uarg, sizeof(hdr)); /* unsafe_function_ignore: memcpy */
	rq = blk_kern_map_hdr(bd, &hdr, source_id, io_cnt);
	if (IS_ERR(rq))
		return PTR_ERR(rq);
#if defined(CONFIG_MAS_ORDER_PRESERVE) || defined(CONFIG_MAS_UNISTORE_PRESERVE)
	if (need_order)
		blk_req_set_make_req_nr(rq);
#endif
	at_head = (0 == (hdr.flags & BSG_FLAG_Q_AT_TAIL));
	blk_scsi_kern_time_record(REQ_EXEC_START, source_id, io_cnt);
	blk_execute_rq(bd->queue, NULL, rq, at_head);
	blk_scsi_kern_time_record(REQ_EXEC_END, source_id, io_cnt);
	ret = blk_kern_complete_hdr_rq(rq, &hdr);

	memcpy(uarg, &hdr, sizeof(hdr)); /* unsafe_function_ignore: memcpy */

	fput(pfile);
	return ret;
}

#ifdef CONFIG_UFS_RPMB_SUPPORT_FROM_TEEOS_IN_KERNEL
long blk_scsi_kern_ioctl_req_queue(struct request_queue *queue, unsigned long arg, bool need_order,
			 unsigned int source_id, unsigned int io_cnt)
{
	int *uarg = (int *)(uintptr_t)arg;
	int ret;
	struct request *rq = NULL;
	struct sg_io_v4 hdr;
	int at_head;

	pr_err("%s: in\n", __func__);

	(void)memcpy_s(&hdr, sizeof(hdr), uarg, sizeof(struct sg_io_v4));
	rq = blk_kern_map_hdr_queue(queue, &hdr, source_id, io_cnt);
	if (IS_ERR(rq))
		return PTR_ERR(rq);
#if defined(CONFIG_MAS_ORDER_PRESERVE) || defined(CONFIG_MAS_UNISTORE_PRESERVE)
	if (need_order)
		blk_req_set_make_req_nr(rq);
#endif
	at_head = (0 == (hdr.flags & BSG_FLAG_Q_AT_TAIL));
	blk_scsi_kern_time_record(REQ_EXEC_START, source_id, io_cnt);
	blk_execute_rq(queue, NULL, rq, at_head);
	blk_scsi_kern_time_record(REQ_EXEC_END, source_id, io_cnt);
	ret = blk_kern_complete_hdr_rq(rq, &hdr);

	(void)memcpy_s(uarg, sizeof(struct sg_io_v4), &hdr, sizeof(hdr));
	pr_err("%s: out, ret = %d\n", __func__, ret);
	return ret;
}
#endif
#endif