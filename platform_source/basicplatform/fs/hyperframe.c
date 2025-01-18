/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2022. All rights reserved.
 * Description: hyperframe management
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * Create: 2022-06-16
 *
 */
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/file.h>
#include <linux/task_work.h>
#include <linux/fs_struct.h>
#include <linux/namei.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <linux/f2fs_fs.h>
#include <linux/syscalls.h>
#include <linux/falloc.h>
#include <linux/fscrypt_common.h>
#include <linux/sysctl.h>
#include <linux/fsnotify.h>
#include <linux/fdtable.h>
#include <linux/kmemleak.h>
#include <linux/mount.h>
#include <linux/dma-buf.h>
#include <linux/scatterlist.h>
#include <linux/uaccess.h>
#include <linux/nospec.h>
#include <linux/sizes.h>
#include <linux/namei.h>
#include <linux/fsnotify.h>
#include <linux/fadvise.h>
#include <linux/io_uring.h>
#include <uapi/linux/io_uring.h>
#include <linux/kthread.h>
#include <uapi/linux/sched/types.h>
#include <platform_include/basicplatform/linux/fs/hyperframe_inf.h>
#include <platform_include/basicplatform/linux/hck/fs/hck_hyperframe.h>
#ifdef CONFIG_DMABUF_MM
#include <platform_include/basicplatform/linux/dmabuf/mm_dma_heap.h>
#endif

#ifdef CONFIG_DFX_DEBUG_FS
#define CREATE_TRACE_POINTS
#include <platform_include/trace/events/hyperframe.h>
#endif

#include "hw_f2fs/f2fs.h"
#include "hw_f2fs/segment.h"
#include "io_uring_types.h"
#include "../../../fs/internal.h"

#define HF_SPACE_NO_LIMIT (-1)
#define HF_HEALTH_ENABLE 1
#define PRE_EOL_INFO_OVER_VAL 2
#define LIFE_TIME_EST_OVER_ALL 8
#define HYPERFRAME_MAX_USAGE (5UL * 1024UL * 1024UL) /* 5G */
#define get_ksize(size) ((size) >> 10)
#define roundup_pagesize(size) (((size) + PAGE_SIZE - 1) / PAGE_SIZE)

void hf_io_req_complete(struct io_kiocb *, long);

#ifdef CONFIG_DFX_DEBUG_FS
int proc_dointvec(struct ctl_table *, int, void *, size_t *, loff_t *);
int proc_douintvec(struct ctl_table *, int, void *, size_t *, loff_t *);
#endif

static atomic_t hf_ctx_alloc;
static atomic_t hf_req_alloc;

static struct hyperframe_cfg hf_cfg = {
	.hf_size = 0,
	.hf_health = HF_HEALTH_ENABLE,
	.hf_max_usage = HF_SPACE_NO_LIMIT,
	.hf_ctx_alloc = 0,
	.hf_req_alloc = 0,
};

#ifdef CONFIG_HYPERFRAME_SPACE_MANAGE
static int hyperframe_get_bdev(const char *dir_name, struct block_device **bdev)
{
	int ret = 0;
	struct file *file = NULL;
	struct super_block *sb = NULL;

	file = filp_open(dir_name, O_RDONLY, S_IRWXU);
	if (IS_ERR_OR_NULL(file)) {
		pr_err("%s, [HF] open file %s error %ld", __func__,
			 dir_name, PTR_ERR(file));
		return -EINVAL;
	}

	sb = file->f_path.mnt->mnt_sb;
	if (!sb || sb->s_magic != F2FS_SUPER_MAGIC) {
		ret = -ENOENT;
		pr_err("%s, [HF] mount info error!\n", __func__);
		goto out;
	}

	*bdev = sb->s_bdev;
out:
	filp_close(file, NULL);
	return ret;
}

static void hyperframe_ufs_lifetime_check(void)
{
	int ret = 0;
	struct block_device *bdev = NULL;
	u8 pre_eol_info = PRE_EOL_INFO_OVER_VAL;
	u8 life_time_est_a = LIFE_TIME_EST_OVER_ALL;
	u8 life_time_est_b = LIFE_TIME_EST_OVER_ALL;
	hf_cfg.hf_health = 0;

	ret = hyperframe_get_bdev("/data/vendor", &bdev);
	if (unlikely(ret)) {
		pr_err("%s, [HF] hyperframe get block_device failed\n", __func__);
		return;
	}

	ret = blk_dev_health_query(bdev, &pre_eol_info, &life_time_est_a, &life_time_est_b);
	if (ret) {
		pr_err("%s, [HF] get health query err:%d\n", __func__, ret);
		return;
	}

	if ((pre_eol_info >= PRE_EOL_INFO_OVER_VAL) ||
		(life_time_est_a >= LIFE_TIME_EST_OVER_ALL) ||
		(life_time_est_b >= LIFE_TIME_EST_OVER_ALL)) {
		pr_err("%s, [HF] over life time used:%d %d %d\n", __func__,
			pre_eol_info, life_time_est_a, life_time_est_b);
		return;
	}

	hf_cfg.hf_health = HF_HEALTH_ENABLE;
}
#endif

static void hyperframe_req_complete(struct io_kiocb *req, int res)
{
	req->result = res;
	if (hyperframe_rw(req->opcode) && res > 0)
		req->rw.len -= res;
	hf_io_req_complete(req, res);
}

static void hck_hyperframe_close_prep(struct io_kiocb *req,
		const struct io_uring_sqe *sqe)
{
	struct hyperframe_req *hf_req = req->buf;
	if (hf_req && req->opcode == IORING_OP_HYPERFRAME_CLOSE)
		hf_req->cancel = READ_ONCE(sqe->user_data);
}

static void hyperframe_close_unlink(struct io_kiocb *req,
		struct path *path, int *ret, unsigned long long size)
{
	mm_segment_t old_fs;
	char *file_path = NULL;
	char *buf = NULL;
	struct hyperframe_req *hf_req = req->buf;

	if (!hf_req->cancel)
		return;

	buf = __getname();
	if (!buf) {
		pr_err("%s, [HF] getname buf failed\n", __func__);
		*ret = -ENOMEM;
		return;
	}

	file_path = d_path((const struct path *)path, buf, PATH_MAX);

	old_fs = get_fs();
	set_fs(KERNEL_DS);
	if (!ksys_access(file_path, 0)) {
		*ret = ksys_unlink(file_path);
		if (*ret)
			pr_err("%s, [HF] %s unlink fail ret = %d", __func__, file_path, *ret);
	}
	set_fs(old_fs);
	__putname(buf);

	if (hf_cfg.hf_size >= get_ksize(size)) {
		hf_cfg.hf_size -= get_ksize(size);
	} else {
		pr_err("%s, [HF] set size fail hf_size = %u ksize = %llu\n", __func__,
			hf_cfg.hf_size, get_ksize(size));
		hf_cfg.hf_size = 0;
	}
}

static int hyperframe_io_close(struct io_kiocb *req)
{
	struct files_struct *files = current->files;
	struct io_close *close = &req->close;
	struct fdtable *fdt;
	struct file *file;
	struct path path;
	unsigned long long size;
	int ret;

	file = NULL;
	ret = -EBADF;
	spin_lock(&files->file_lock);
	fdt = files_fdtable(files);
	if (close->fd >= fdt->max_fds) {
		spin_unlock(&files->file_lock);
		goto err;
	}
	file = fdt->fd[close->fd];
	if (!file) {
		spin_unlock(&files->file_lock);
		goto err;
	}

	ret = __close_fd_get_file(close->fd, &file);
	spin_unlock(&files->file_lock);
	if (ret < 0) {
		if (ret == -ENOENT)
			ret = -EBADF;
		goto err;
	}

	/* No ->flush() or already async, safely close from here */
	ret = filp_close(file, current->files);
err:
	if (ret < 0 &&
		(req->flags & (REQ_F_LINK | REQ_F_HARDLINK)) == REQ_F_LINK)
		req->flags |= REQ_F_FAIL_LINK;
	if (file) {
		path = file->f_path;
		size = (unsigned long long)i_size_read(file_inode(file));
		fput(file);
		hyperframe_close_unlink(req, &path, &ret, size);
	}
	hyperframe_req_complete(req, ret);
	return 0;
}

static void hck_hyperframe_openat_prep(struct io_kiocb *req,
		const struct io_uring_sqe *sqe)
{
	struct hyperframe_req *hf_req = req->buf;
	if (hf_req && req->opcode == IORING_OP_HYPERFRAME_OPEN) {
		hf_req->open_size = READ_ONCE(sqe->off);
		hf_req->size_addr = u64_to_user_ptr(READ_ONCE(sqe->__pad2[1]));
	}
}

static void hyperframe_openat_alloc(struct io_kiocb *req,
		struct file *file, int *ret)
{
	int ret2 = 0;
	unsigned long long size;
	struct hyperframe_req *hf_req = req->buf;
	struct path path;
	struct hyperframe_info finfo = {0};

	if (!hf_req)
		return;

	if ((req->open.how.flags & O_ACCMODE) == O_RDONLY) {
		finfo.fsize = (u64)i_size_read(file_inode(file));
		if (hf_req->size_addr) {
			copy_to_user(hf_req->size_addr, &finfo, sizeof(struct hyperframe_info));
			hf_req->size_addr = NULL;
		}
		return;
	}

	size = hf_req->open_size;
	if (i_size_read(file_inode(file)) >= size)
		return;

	hf_cfg.hf_size += get_ksize(size);
#ifdef CONFIG_HYPERFRAME_SPACE_MANAGE
	if ((hf_cfg.hf_max_usage != HF_SPACE_NO_LIMIT) &&
	    (hf_cfg.hf_size > (unsigned int)hf_cfg.hf_max_usage)) {
		pr_err("%s, [HF] out of space usage:%u - %u!\n",
			__func__, get_ksize(size), hf_cfg.hf_size);
		*ret = -ENOSPC;
		goto out;
	}
#endif

	if (!file->f_op || !file->f_op->fallocate) {
		pr_err("%s, [HF] file op error!\n", __func__);
		*ret = -EINVAL;
		goto out;
	}

	ret2 = file->f_op->fallocate(file, 0, 0, size);
	if (!ret2)
		return;

	*ret = ret2;
out:
	hf_req->cancel = 1;
	path = file->f_path;
	hyperframe_close_unlink(req, &path, &ret2, size);
}

static int hyperframe_io_open(struct io_kiocb *req)
{
	int ret;
	struct open_flags op;
	struct file *file = NULL;

	ret = build_open_flags(&req->open.how, &op);
	if (ret)
		goto err;

	ret = __get_unused_fd_flags(req->open.how.flags, req->open.nofile);
	if (ret < 0)
		goto err;

	file = do_filp_open(req->open.dfd, req->open.filename, &op);
	if (IS_ERR(file)) {
		put_unused_fd(ret);
		ret = PTR_ERR(file);
	} else {
		fsnotify_open(file);
		fd_install(ret, file);
		hyperframe_openat_alloc(req, file, &ret);
	}
err:
	putname(req->open.filename);
	req->flags &= ~REQ_F_NEED_CLEANUP;
	if (ret < 0 &&
		(req->flags & (REQ_F_LINK | REQ_F_HARDLINK)) == REQ_F_LINK)
		req->flags |= REQ_F_FAIL_LINK;
	hyperframe_req_complete(req, ret);
	return 0;
}

static void hck_hyperframe_init_req(struct io_kiocb *req,
		const struct io_uring_sqe *sqe, int *ret)
{
	struct hyperframe_req *hf_req = NULL;
	req->buf = NULL;
	if (*ret || !hyperframe_opcode(req->opcode))
		return;

	req->buf = kzalloc(sizeof(struct hyperframe_req), GFP_KERNEL);
	if (req->buf == NULL) {
		*ret = -ENOMEM;
		pr_err("%s, [HF] hyperframe_req alloc failed\n", __func__);
		return;
	}

	atomic_inc(&hf_req_alloc);
	hf_req = req->buf;
	hf_req->req = req;
	hf_req->kiocb = NULL;
	hf_req->hf_ctx = NULL;
	hf_req->dma_buf = NULL;
	hf_req->attach = NULL;
	hf_req->sgt = NULL;
	hf_req->size_addr = NULL;
	INIT_LIST_HEAD(&hf_req->req_list);
	atomic_set(&hf_req->in_list, 0);
	hf_req->open_size = 0;
	hf_req->rw_size = 0;
	hf_req->cancel = 0;
	hf_req->ion_fd = 0;
	hf_req->file_fd = 0;
	hf_req->ret = 0;
	hf_req->addr = 0;

#ifdef CONFIG_DFX_DEBUG_FS
	trace_hyperframe_req_init(req->ctx, req->ctx->buf,
		 req->opcode, req->user_data, READ_ONCE(sqe->fd));
#endif
}

static void hck_hyperframe_free_req(struct io_kiocb *req)
{
	struct hyperframe_req *hf_req = req->buf;

	if (!hyperframe_opcode(req->opcode))
		return;

	if (hf_req == NULL) {
		pr_err("%s, [HF] hyperframe_req free err\n", __func__);
		return;
	}

#ifdef CONFIG_DFX_DEBUG_FS
	trace_hyperframe_req_completed(req->opcode, req->user_data,
		req->result, refcount_read(&req->refs), hf_req->file_fd);
#endif

	kfree(hf_req);
	atomic_dec(&hf_req_alloc);
}

static void hyperframe_put_pages(struct page **pages, int len)
{
	int i;
	for (i = 0; i < len; i++)
		put_page(pages[i]);
}

static ssize_t hyperframe_prepare_bvec_buf(struct hyperframe_req *hf_req,
	int rw, struct bio_vec **bvec, struct iov_iter *iter)
{
	unsigned int i;
	struct page *pg = NULL;
	unsigned int len = roundup_pagesize(hf_req->rw_size);

	*bvec = kvmalloc_array(len, sizeof(struct bio_vec), GFP_KERNEL);
	if (*bvec == NULL) {
		pr_err("%s, [HF] bvec alloc failed\n", __func__);
		return -ENOMEM;
	}

	for (i = 0; i < len; i++) {
		pg = hf_req->pages[i];
		(*bvec)[i].bv_page = pg;
		(*bvec)[i].bv_len = PAGE_SIZE;
		(*bvec)[i].bv_offset = 0;
	}

	iov_iter_bvec(iter, rw, (const struct bio_vec *)(*bvec), len, hf_req->rw_size);
	return 0;
}

static void hyperframe_fill_iov_iter(struct iov_iter *iter,
	struct scatterlist *sgl, unsigned int nents, struct bio_vec **bvec, int rw)
{
	unsigned int i;
	ssize_t size;
	ssize_t total = 0;
	struct page *pg = NULL;
	struct scatterlist *s = NULL;

	for_each_sg(sgl, s, nents, i) {
		pg = sg_page(s);
		size = s->length;
		(*bvec)[i].bv_page = pg;
		(*bvec)[i].bv_len = size;
		(*bvec)[i].bv_offset = 0;
		total += size;
	}

	iov_iter_bvec(iter, rw, (const struct bio_vec *)(*bvec), nents, total);
}

static ssize_t hyperframe_prepare_bvec_ion(struct hyperframe_req *hf_req,
	int rw, struct bio_vec **bvec, struct iov_iter *iter)
{
	unsigned int nents;
	struct scatterlist *sgl = NULL;
	struct sg_table *sgt = NULL;
	struct dma_buf_attachment *attach = NULL;
	struct device *dev = NULL;
	struct dma_buf *buffer = hf_req->dma_buf;
#ifndef CONFIG_DMABUF_MM
	struct device dummy_dev = { 0 };
	dev = &dummy_dev;
#else
	dev = dmabuf_heap_device_get(buffer);
	if(!dev) {
		pr_err("%s, [HF] failed to get dev\n", __func__);
		return -EFAULT;
	}
#endif
	attach = dma_buf_attach(buffer, dev);
	if (IS_ERR(attach)) {
		pr_err("%s, [HF] failed to attach the dmabuf\n", __func__);
		return -EFAULT;
	}

	sgt = dma_buf_map_attachment(attach, DMA_TO_DEVICE);
	if (IS_ERR(sgt)) {
		pr_err("%s, [HF] failed to map dma buf to get sgt\n", __func__);
		dma_buf_detach(buffer, attach);
		return -EFAULT;
	}

	sgl = sgt->sgl;
	nents = sg_nents(sgl);
	*bvec = kvmalloc_array(nents, sizeof(struct bio_vec), GFP_KERNEL);
	if (*bvec == NULL) {
		pr_err("%s, [HF] bvec alloc failed\n", __func__);
		dma_buf_unmap_attachment(attach, sgt, DMA_FROM_DEVICE);
		dma_buf_detach(buffer, attach);
		return -ENOMEM;
	}

	hf_req->attach = attach;
	hf_req->sgt = sgt;
	hyperframe_fill_iov_iter(iter, sgl, nents, bvec, rw);
	return 0;
}

static int hyperframe_io_rw_buf(struct hyperframe_req *hf_req, int rw)
{
	ssize_t ret = 0;
	struct bio_vec *bvec = NULL;
	struct iov_iter __iter, *iter = &__iter;
	struct kiocb *kiocb = hf_req->kiocb;

	if (hf_req->ion_fd)
		ret = hyperframe_prepare_bvec_ion(hf_req, rw, &bvec, iter);
	else
		ret = hyperframe_prepare_bvec_buf(hf_req, rw, &bvec, iter);
	if (ret)
		return ret;

#ifdef CONFIG_SCSI_UFS_ENHANCED_INLINE_CRYPTO_V3
	ret = rw_begin(hf_req->req->file);
	if (ret) {
		pr_err("%s, [HF] rw_begin failed, rw:%d, ret:%d\n",
			__func__, rw, ret);
		if (bvec)
			kvfree(bvec);
		return ret;
	}
#endif

	if (rw == WRITE) {
		sb_start_write(file_inode(hf_req->req->file)->i_sb);
		__sb_writers_release(file_inode(hf_req->req->file)->i_sb,
					SB_FREEZE_WRITE);
		kiocb->ki_flags |= IOCB_WRITE;
	}

	if (rw == WRITE)
		ret = call_write_iter(hf_req->req->file, kiocb, iter);
	else
		ret = call_read_iter(hf_req->req->file, kiocb, iter);

#ifdef CONFIG_DFX_DEBUG_FS
	trace_hyperframe_req_dispatch(hf_req->req->opcode, ret, hf_req->file_fd);
#endif

	if (ret == -EIOCBQUEUED)
		ret = 0;

#ifdef CONFIG_SCSI_UFS_ENHANCED_INLINE_CRYPTO_V3
	rw_finish(READ, hf_req->req->file);
#endif
	if (bvec)
		kvfree(bvec);
	return ret;
}

static int hyperframe_prepare_buf(struct hyperframe_req *hf_req, int rw)
{
	int ret = 0;
	size_t start = 0;
	void __user *user_buf;
	struct dma_buf *dma_buf = NULL;
	struct iov_iter __iter, *iter = &__iter;
	struct iovec inline_vecs[UIO_FASTIOV], *iovec = inline_vecs;

	if (hf_req->ion_fd) {
		dma_buf = dma_buf_get(hf_req->ion_fd);
		if (IS_ERR(dma_buf) || !dma_buf) {
			pr_err("%s, [HF] get dma_buf error by fd:%d\n", __func__, hf_req->ion_fd);
			ret = -EFAULT;
			hyperframe_req_complete(hf_req->req, ret);
			return ret;
		}
		hf_req->dma_buf = dma_buf;
		hf_req->kiocb->ki_pos = 0;
	} else {
		user_buf = u64_to_user_ptr(hf_req->addr);
		ret = import_single_range(rw, user_buf, hf_req->rw_size, iovec, iter);
		if (ret) {
			pr_err("%s, [HF] import user buffer error ret:%d\n", __func__, ret);
			hyperframe_req_complete(hf_req->req, ret);
			return ret;
		}

		hf_req->pages = kvmalloc(roundup_pagesize(hf_req->rw_size) *
				sizeof(struct page *), GFP_KERNEL);
		if (hf_req->pages == NULL) {
			pr_err("%s, [HF] pages alloc failed\n", __func__);
			ret = -ENOMEM;
			hyperframe_req_complete(hf_req->req, ret);
			return ret;
		}

		ret = iov_iter_get_pages(iter, hf_req->pages, LONG_MAX, UINT_MAX, &start);
		if (ret < 0) {
			pr_err("%s, [HF] iter get pages error ret:%d\n", __func__, ret);
			kvfree(hf_req->pages);
			hyperframe_req_complete(hf_req->req, ret);
			return ret;
		}
	}

	return 0;
}

static int hyperframe_io_rw(struct io_kiocb *req, int rw)
{
	int ret;
	unsigned long flags = 0;
	loff_t ki_pos = 0;
	struct hyperframe_ctx *hf_ctx = NULL;
	struct hyperframe_req *hf_req = req->buf;

	if (!hf_req || !hf_req->rw_size) {
		pr_err("%s, [HF] hyperframe_req alloc error\n", __func__);
		hyperframe_req_complete(req, -ENOMEM);
		return 0;
	}

	if (req->rw.len > (unsigned long)i_size_read(file_inode(req->file))) {
		pr_err("%s, [HF] rw buf size:%d is larger than i_size:%d\n",
			__func__, req->rw.len,
			i_size_read(file_inode(req->file)));
		hyperframe_req_complete(req, -EINVAL);
		return 0;
	}

	ret = rw_verify_area(rw, req->file, &ki_pos, req->rw.len);
	if (unlikely(ret)) {
		pr_err("%s, [HF] verify failed, rw:%d ret:%d\n", __func__, rw, ret);
		hyperframe_req_complete(req, ret);
		return 0;
	}

	if (atomic_read(&hf_req->in_list)) {
		pr_err("%s, [HF] req is reused, rw:%d\n", __func__, rw);
		hyperframe_req_complete(req, -EEXIST);
		return 0;
	}

	atomic_inc(&hf_req->in_list);
	ret = hyperframe_prepare_buf(hf_req, rw);
	if (unlikely(ret))
		return 0;

	hf_ctx = hf_req->hf_ctx;
#ifdef CONFIG_DFX_DEBUG_FS
	trace_hyperframe_add_list(hf_ctx, req->opcode,
		 hf_req->ion_fd ? 1 : 0, hf_req->file_fd);
#endif

	if (rw == READ) {
		spin_lock_irqsave(&hf_ctx->lock_read, flags);
		list_add_tail(&hf_req->req_list, &hf_ctx->list_read);
		atomic_inc(&hf_ctx->read_cnt);
		spin_unlock_irqrestore(&hf_ctx->lock_read, flags);
		kthread_queue_delayed_work(&hf_cfg.async_kwq_read, &hf_ctx->kwork_read, 0);
	} else {
		spin_lock_irqsave(&hf_ctx->lock_write, flags);
		list_add_tail(&hf_req->req_list, &hf_ctx->list_write);
		atomic_inc(&hf_ctx->write_cnt);
		spin_unlock_irqrestore(&hf_ctx->lock_write, flags);
		kthread_queue_delayed_work(&hf_cfg.async_kwq_write, &hf_ctx->kwork_write, 0);
	}

	return 0;
}

static void hyperframe_add_cq_list(struct hyperframe_req *hf_req, long res)
{
	unsigned long flags = 0;
	struct hyperframe_ctx *hf_ctx = hf_req->hf_ctx;

	hf_req->ret = res;
	spin_lock_irqsave(&hf_ctx->lock_cq, flags);
	list_add_tail(&hf_req->req_list, &hf_ctx->list_cq);
	atomic_inc(&hf_ctx->cq_comp_cnt);
	spin_unlock_irqrestore(&hf_ctx->lock_cq, flags);
#ifdef CONFIG_DFX_DEBUG_FS
	trace_hyperframe_irq_complete(hf_ctx, hf_req->req->opcode,
		 atomic_read(&hf_ctx->cq_comp_cnt), hf_req->file_fd);
#endif
	kthread_queue_delayed_work(&hf_cfg.async_kwq_cq, &hf_ctx->kwork_cq, 0);
}

static void hyperframe_write_work(struct kthread_work *work)
{
	int ret;
	unsigned long flags = 0;
	struct hyperframe_req *hf_req = NULL;
	struct hyperframe_ctx *hf_ctx =
		container_of(work, struct hyperframe_ctx, kwork_write.work);

again:
	spin_lock_irqsave(&hf_ctx->lock_write, flags);
	if (list_empty_careful(&hf_ctx->list_write)) {
		if (atomic_read(&hf_ctx->write_cnt))
			pr_err("%s, [HF] write IO count err:%d\n",
				__func__, atomic_read(&hf_ctx->write_cnt));
		spin_unlock_irqrestore(&hf_ctx->lock_write, flags);
		return;
	}
	hf_req = list_first_entry(&hf_ctx->list_write, struct hyperframe_req, req_list);
	list_del_init(&hf_req->req_list);
	spin_unlock_irqrestore(&hf_ctx->lock_write, flags);

#ifdef CONFIG_DFX_DEBUG_FS
	trace_hyperframe_work_start(hf_ctx, hf_req->req->opcode,
		 atomic_read(&hf_ctx->write_cnt), hf_req->file_fd);
#endif
	atomic_inc(&hf_ctx->cq_cnt);
	ret = hyperframe_io_rw_buf(hf_req, WRITE);
	if (ret == -EAGAIN) {
		atomic_dec(&hf_ctx->cq_cnt);
		spin_lock_irqsave(&hf_ctx->lock_write, flags);
		list_add(&hf_req->req_list, &hf_ctx->list_write);
		spin_unlock_irqrestore(&hf_ctx->lock_write, flags);
		goto again;
	} else if (ret) {
		atomic_dec(&hf_ctx->cq_cnt);
		__sb_writers_acquired(file_inode(hf_req->req->file)->i_sb, SB_FREEZE_WRITE);
		file_end_write(hf_req->req->file);

#ifdef CONFIG_DFX_DEBUG_FS
		trace_hyperframe_fill_cqe(hf_ctx, hf_req->req->opcode, atomic_read(&hf_ctx->cq_cnt),
			 atomic_read(&hf_ctx->cq_comp_cnt), hf_req->file_fd);
#endif
		if (hf_req->ion_fd) {
			dma_buf_unmap_attachment(hf_req->attach, hf_req->sgt, DMA_FROM_DEVICE);
			dma_buf_detach(hf_req->dma_buf, hf_req->attach);
			dma_buf_put(hf_req->dma_buf);
		} else {
			hyperframe_put_pages(hf_req->pages, roundup_pagesize(hf_req->rw_size));
			kvfree(hf_req->pages);
		}
		hyperframe_req_complete(hf_req->req, ret);
	}

	if (!atomic_dec_and_test(&hf_ctx->write_cnt))
		goto again;
}

static void hyperframe_read_work(struct kthread_work *work)
{
	int ret;
	unsigned long flags = 0;
	struct hyperframe_req *hf_req = NULL;
	struct hyperframe_ctx *hf_ctx =
		container_of(work, struct hyperframe_ctx, kwork_read.work);

again:
	spin_lock_irqsave(&hf_ctx->lock_read, flags);
	if (list_empty_careful(&hf_ctx->list_read)) {
		if (atomic_read(&hf_ctx->read_cnt))
			pr_err("%s, [HF] read IO count err:%d\n",
				__func__, atomic_read(&hf_ctx->read_cnt));
		spin_unlock_irqrestore(&hf_ctx->lock_read, flags);
		return;
	}
	hf_req = list_first_entry(&hf_ctx->list_read, struct hyperframe_req, req_list);
	list_del_init(&hf_req->req_list);
	spin_unlock_irqrestore(&hf_ctx->lock_read, flags);

#ifdef CONFIG_DFX_DEBUG_FS
	trace_hyperframe_work_start(hf_ctx, hf_req->req->opcode,
		 atomic_read(&hf_ctx->read_cnt), hf_req->file_fd);
#endif
	atomic_inc(&hf_ctx->cq_cnt);
	ret = hyperframe_io_rw_buf(hf_req, READ);
	if (ret == -EAGAIN) {
		atomic_dec(&hf_ctx->cq_cnt);
		spin_lock_irqsave(&hf_ctx->lock_read, flags);
		list_add(&hf_req->req_list, &hf_ctx->list_read);
		spin_unlock_irqrestore(&hf_ctx->lock_read, flags);
		goto again;
	} else if (ret) {
		atomic_dec(&hf_ctx->cq_cnt);

#ifdef CONFIG_DFX_DEBUG_FS
		trace_hyperframe_fill_cqe(hf_ctx, hf_req->req->opcode, atomic_read(&hf_ctx->cq_cnt),
			 atomic_read(&hf_ctx->cq_comp_cnt), hf_req->file_fd);
#endif
		if (hf_req->ion_fd) {
			dma_buf_unmap_attachment(hf_req->attach, hf_req->sgt, DMA_FROM_DEVICE);
			dma_buf_detach(hf_req->dma_buf, hf_req->attach);
			dma_buf_put(hf_req->dma_buf);
		} else {
			hyperframe_put_pages(hf_req->pages, roundup_pagesize(hf_req->rw_size));
			kvfree(hf_req->pages);
		}
		hyperframe_req_complete(hf_req->req, ret);
	}

	if (!atomic_dec_and_test(&hf_ctx->read_cnt))
		goto again;
}

static void hyperframe_fill_cq_work(struct kthread_work *work)
{
	unsigned long flags = 0;
	struct hyperframe_req *hf_req = NULL;
	struct hyperframe_ctx *hf_ctx =
		container_of(work, struct hyperframe_ctx, kwork_cq.work);

again:
	spin_lock_irqsave(&hf_ctx->lock_cq, flags);
	if (list_empty_careful(&hf_ctx->list_cq)) {
		if (atomic_read(&hf_ctx->cq_comp_cnt))
			pr_err("%s, [HF] cqe complete count err:%d\n",
				__func__, atomic_read(&hf_ctx->cq_comp_cnt));
		spin_unlock_irqrestore(&hf_ctx->lock_cq, flags);
		return;
	}
	hf_req = list_first_entry(&hf_ctx->list_cq, struct hyperframe_req, req_list);
	list_del_init(&hf_req->req_list);
	spin_unlock_irqrestore(&hf_ctx->lock_cq, flags);

	atomic_dec(&hf_ctx->cq_cnt);
	atomic_dec(&hf_ctx->cq_comp_cnt);

#ifdef CONFIG_DFX_DEBUG_FS
	trace_hyperframe_fill_cqe(hf_ctx, hf_req->req->opcode, atomic_read(&hf_ctx->cq_cnt),
		 atomic_read(&hf_ctx->cq_comp_cnt), hf_req->file_fd);
#endif

	if (hf_req->req->opcode == IORING_OP_HYPERFRAME_WRITE) {
		__sb_writers_acquired(file_inode(hf_req->req->file)->i_sb, SB_FREEZE_WRITE);
		file_end_write(hf_req->req->file);
	}

	if (hf_req->ion_fd) {
		dma_buf_unmap_attachment(hf_req->attach, hf_req->sgt, DMA_FROM_DEVICE);
		dma_buf_detach(hf_req->dma_buf, hf_req->attach);
		dma_buf_put(hf_req->dma_buf);
	} else {
		hyperframe_put_pages(hf_req->pages, roundup_pagesize(hf_req->rw_size));
		kvfree(hf_req->pages);
	}

	hyperframe_req_complete(hf_req->req, hf_req->ret);

	if (atomic_read(&hf_ctx->cq_comp_cnt))
		goto again;
}

static void hyperframe_fill_cq(struct kiocb *kiocb, long res, long res2)
{
	struct io_kiocb *req = container_of(kiocb, struct io_kiocb, rw.kiocb);
	struct hyperframe_req *hf_req = req->buf;
	hyperframe_add_cq_list(hf_req, res);
}

static void hck_hyperframe_ctx_alloc(struct io_ring_ctx *ctx, int *ret)
{
	struct hyperframe_ctx *hf_ctx = NULL;

	ctx->buf = kzalloc(sizeof(struct hyperframe_ctx), GFP_KERNEL);
	if (ctx->buf == NULL) {
		pr_err("%s, [HF] hyperframe_ctx alloc failed!\n", __func__);
		*ret = -ENOMEM;
		return;
	}

#ifdef CONFIG_HYPERFRAME_SPACE_MANAGE
	hyperframe_ufs_lifetime_check();
	if (hf_cfg.hf_health == 0) {
		pr_err("%s, [HF] ufs lifetime not available!\n", __func__);
		kfree(ctx->buf);
		ctx->buf = NULL;
		*ret = -ENOSPC;
		return;
	}
#endif

	atomic_inc(&hf_ctx_alloc);
	hf_ctx = ctx->buf;
	hf_ctx->hf_enable = false;
	kthread_init_delayed_work(&hf_ctx->kwork_read, hyperframe_read_work);
	kthread_init_delayed_work(&hf_ctx->kwork_write, hyperframe_write_work);
	kthread_init_delayed_work(&hf_ctx->kwork_cq, hyperframe_fill_cq_work);
	INIT_LIST_HEAD(&hf_ctx->list_read);
	INIT_LIST_HEAD(&hf_ctx->list_write);
	INIT_LIST_HEAD(&hf_ctx->list_cq);
	spin_lock_init(&hf_ctx->lock_read);
	spin_lock_init(&hf_ctx->lock_write);
	spin_lock_init(&hf_ctx->lock_cq);
	atomic_set(&hf_ctx->read_cnt, 0);
	atomic_set(&hf_ctx->write_cnt, 0);
	atomic_set(&hf_ctx->cq_cnt, 0);
	atomic_set(&hf_ctx->cq_comp_cnt, 0);
	hf_ctx->hf_enable = true;
}

static void hck_hyperframe_ctx_free(struct io_ring_ctx *ctx)
{
	struct hyperframe_ctx *hf_ctx = ctx->buf;
	if (!hf_ctx)
		return;

	kfree(hf_ctx);
	atomic_dec(&hf_ctx_alloc);
}

static void hck_hyperframe_set_opf(struct bio *bio, struct kiocb *iocb)
{
	if (!iocb || (iocb->ki_complete != hyperframe_fill_cq))
		return;

	bio->bi_opf |= REQ_SYNC;
	if (op_is_write(bio_op(bio)) || !(iocb->ki_flags & RWF_HF_HIPRI))
		return;

	bio->bi_opf |= REQ_FG;
}

static void hck_hyperframe_rw_prep(struct io_kiocb *req,
		const struct io_uring_sqe *sqe, long *ret)
{
	struct kiocb *kiocb = NULL;
	struct hyperframe_req *hf_req = req->buf;
	struct hyperframe_ctx *hf_ctx = req->ctx->buf;

	if (!hyperframe_rw(req->opcode))
		return;

	if (!hf_ctx || !hf_ctx->hf_enable) {
		pr_err("%s, [HF] hyperframe_ctx is not ready:%pK\n", __func__, req->ctx->buf);
		*ret = EPERM;
		return;
	}

	if (!hf_req) {
		*ret = -ENOMEM;
		pr_err("%s, [HF] hyperframe_req is NULL\n", __func__);
		return;
	}

	kiocb = &req->rw.kiocb;
	kiocb->ki_complete = hyperframe_fill_cq;
	hf_req->addr = req->rw.addr;
	hf_req->kiocb = kiocb;
	hf_req->hf_ctx = req->ctx->buf;
	hf_req->rw_size = req->rw.len;
	hf_req->ion_fd = kiocb->ki_pos;
	hf_req->file_fd = READ_ONCE(sqe->fd);
}

static void hck_hyperframe_issue_sqe(struct io_kiocb *req, int *ret)
{
	switch (req->opcode) {
	case IORING_OP_HYPERFRAME_OPEN:
		*ret = hyperframe_io_open(req);
		return;
	case IORING_OP_HYPERFRAME_WRITE:
		*ret = hyperframe_io_rw(req, WRITE);
		return;
	case IORING_OP_HYPERFRAME_READ:
		*ret = hyperframe_io_rw(req, READ);
		return;
	case IORING_OP_HYPERFRAME_CLOSE:
		*ret = hyperframe_io_close(req);
		return;
	}
}

static void hck_hyperframe_complete_sqe(u8 opcode, int *ret)
{
	if (!hyperframe_opcode(opcode))
		return;
	*ret = 1;
}

static void hck_hyperframe_err_record(const char *func, int ret, int resv1, int resv2, int resv3)
{
	pr_err("[HF], %s, %d, %d, %d, %d\n", func, ret, resv1, resv2, resv3);
}

#ifdef CONFIG_DFX_DEBUG_FS
static int hyperframe_get_health(struct ctl_table *table, int write,
		   void *buffer, size_t *lenp, loff_t *ppos)
{
#ifdef CONFIG_HYPERFRAME_SPACE_MANAGE
	hyperframe_ufs_lifetime_check();
#endif
	return proc_douintvec(table, write, buffer, lenp, ppos);
}

static int hyperframe_set_max_usage(struct ctl_table *table, int write,
		   void *buffer, size_t *lenp, loff_t *ppos)
{
	int ret = proc_dointvec(table, write, buffer, lenp, ppos);
	int *max_usage = (int *)table->data;
	if (write && (*max_usage > HYPERFRAME_MAX_USAGE)) {
		pr_err("%s, [HF] set usage exceeds default max:%u\n", __func__, *max_usage);
		*max_usage = HYPERFRAME_MAX_USAGE;
	}
	return ret;
}

static int hyperframe_get_alloc(struct ctl_table *table, int write,
		   void *buffer, size_t *lenp, loff_t *ppos)
{
	hf_cfg.hf_ctx_alloc = atomic_read(&hf_ctx_alloc);
	hf_cfg.hf_req_alloc = atomic_read(&hf_req_alloc);
	return proc_dointvec(table, write, buffer, lenp, ppos);
}

static struct ctl_table hf_table[] = {
	{
		.procname	= "hf_size",
		.data		= &(hf_cfg.hf_size),
		.maxlen		= sizeof(hf_cfg.hf_size),
		.mode		= 0440,
		.proc_handler	= proc_douintvec,
	},
	{
		.procname	= "hf_health",
		.data		= &(hf_cfg.hf_health),
		.maxlen		= sizeof(hf_cfg.hf_health),
		.mode		= 0440,
		.proc_handler	= hyperframe_get_health,
	},
	{
		.procname	= "hf_max_usage",
		.data		= &(hf_cfg.hf_max_usage),
		.maxlen		= sizeof(hf_cfg.hf_max_usage),
		.mode		= 0644,
		.proc_handler	= hyperframe_set_max_usage,
	},
	{
		.procname	= "hf_ctx_alloc",
		.data		= &(hf_cfg.hf_ctx_alloc),
		.maxlen		= sizeof(hf_cfg.hf_ctx_alloc),
		.mode		= 0440,
		.proc_handler	= hyperframe_get_alloc,
	},
	{
		.procname	= "hf_req_alloc",
		.data		= &(hf_cfg.hf_req_alloc),
		.maxlen		= sizeof(hf_cfg.hf_req_alloc),
		.mode		= 0440,
		.proc_handler	= hyperframe_get_alloc,
	},
	{ }
};

static struct ctl_table hf_sysctl_table[] = {
	{
		.procname	= "hyperframe",
		.mode		= 0550,
		.child		= hf_table,
	},
	{ }
};
#endif

static int __init hyperframe_init(void)
{
	static bool registered = false;
	struct task_struct* kworker_task = NULL;
#ifdef CONFIG_DFX_DEBUG_FS
	struct ctl_table_header *hdr;
	hdr = register_sysctl_table(hf_sysctl_table);
	kmemleak_not_leak(hdr);
#endif

	atomic_set(&hf_ctx_alloc, 0);
	atomic_set(&hf_req_alloc, 0);

	kthread_init_worker(&hf_cfg.async_kwq_read);
	kworker_task  = kthread_run(kthread_worker_fn, &hf_cfg.async_kwq_read, "hf_async_wq_read");
	if (IS_ERR((void *)kworker_task)) {
		pr_err("%s, [HF] async read wq create failed!\n", __func__);
		return -EINVAL;
	}
#ifdef CONFIG_SCHED_VIP
	set_vip_prio(kworker_task, 1);
#endif

	kthread_init_worker(&hf_cfg.async_kwq_write);
	kworker_task  = kthread_run(kthread_worker_fn, &hf_cfg.async_kwq_write, "hf_async_wq_write");
	if (IS_ERR((void *)kworker_task)) {
		pr_err("%s, [HF] async write wq create failed!\n", __func__);
		return -EINVAL;
	}
#ifdef CONFIG_SCHED_VIP
	set_vip_prio(kworker_task, 1);
#endif

	kthread_init_worker(&hf_cfg.async_kwq_cq);
	kworker_task  = kthread_run(kthread_worker_fn, &hf_cfg.async_kwq_cq, "hf_async_wq_cq");
	if (IS_ERR((void *)kworker_task)) {
		pr_err("%s, [HF] async cq wq create failed!\n", __func__);
		return -EINVAL;
	}
#ifdef CONFIG_SCHED_VIP
	set_vip_prio(kworker_task, 1);
#endif

	if (registered == false) {
		REGISTER_HCK_VH(hyperframe_err_record, hck_hyperframe_err_record);
		REGISTER_HCK_VH(hyperframe_set_opf, hck_hyperframe_set_opf);
		REGISTER_HCK_VH(hyperframe_ctx_alloc, hck_hyperframe_ctx_alloc);
		REGISTER_HCK_VH(hyperframe_ctx_free, hck_hyperframe_ctx_free);
		REGISTER_HCK_VH(hyperframe_openat_prep, hck_hyperframe_openat_prep);
		REGISTER_HCK_VH(hyperframe_close_prep, hck_hyperframe_close_prep);
		REGISTER_HCK_VH(hyperframe_rw_prep, hck_hyperframe_rw_prep);
		REGISTER_HCK_VH(hyperframe_init_req, hck_hyperframe_init_req);
		REGISTER_HCK_VH(hyperframe_free_req, hck_hyperframe_free_req);
		REGISTER_HCK_VH(hyperframe_issue_sqe, hck_hyperframe_issue_sqe);
		REGISTER_HCK_VH(hyperframe_complete_sqe, hck_hyperframe_complete_sqe);
		registered = true;
	}

	return 0;
}

static void __exit hyperframe_exit(void)
{
	kthread_destroy_worker(&hf_cfg.async_kwq_read);
	kthread_destroy_worker(&hf_cfg.async_kwq_write);
	kthread_destroy_worker(&hf_cfg.async_kwq_cq);
}

module_init(hyperframe_init)
module_exit(hyperframe_exit)
