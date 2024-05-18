/*
 * Copyright (c) Honor Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: I/O performence measure
 * Author:  lipeng
 * Create:  2021-06-10
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/workqueue.h>
#include <linux/proc_fs.h>
#include <linux/blkdev.h>
#include <linux/blk_types.h>
#include <linux/timekeeping.h>
#include <linux/tracepoint.h>
#include <linux/err.h>
#include <linux/types.h>
#include <linux/swap.h>
#include <linux/slab.h>
#include <linux/version.h>
#include <log/log_usertype.h>
#include <trace/events/block.h>
#include <trace/events/scsi.h>
#include <trace/events/android_fs.h>
#include <linux/iomt_host/iomeasure.h>

#define USER_IOM_DIR		"iomeasure"
#define USER_IOM_ENABLE		"enable"
#define USER_IOM_RESET		"reset"
#define USER_IOM_BLK_ENTRY	"io_blk_scatter"
#define USER_IOM_BLK_SCHED	"io_blk_sched_scatter"
#define USER_IOM_FS_ENTRY	"io_fs_scatter"
#define USER_IOM_PG_ENTRY	"io_pagecache"
#define USER_IOM_SCSI_ENTRY	"io_scsi_scatter"
#define USER_IOM_SCSI_SCHED	"io_scsi_sched_scatter"

#define IOM_INIT_STAGE1			0
#define IOM_INIT_STAGE2			1
#define IOM_INIT_STAGE_END		2
#define IOM_INIT_DELAY_TIME		(10*HZ)
#define IOM_RUN_DELAY_TIME		(60*HZ)

#define IOM_USER_INVAILD		0
#define IOM_USER_NOT_COMMERCIAL	1
#define IOM_USER_COMMERCIAL		2

#define IOM_NS_TO_US(t)			((t) / 1000)
#define IOM_US_TO_MS(t)			((t) / 1000)
#define IOM_NS_TO_MS(t)			((t) / 1000000)
#define IOM_TIME_IDX_TO_MS(idx)	(1 << (idx))
#define IOM_LATENCY_THRESHOLD	(500000) //us
#define IOM_BLK_LTCY_THRESHOLD	(500000000) //ns
#define IOM_SCSI_LTCY_THRESHOLD	(500000000) //ns

#define IOM_BYTE_TO_KB(byte)	((byte) >> 10)
#define IOM_BYTE_TO_PAGE(byte)	((byte) >> 12)
#define IOM_PAGE_TO_KB(byte)	((byte) << 2)

#define IOM_LATENCY_LOG_TAG_LEN	16
#define IOM_PROC_BUF_LEN		(10 * TIME_DIV_NUM * IO_TP_NUM * 20)
#define IOM_LOG_BUF_LEN			(100 + TIME_DIV_NUM * IO_TP_NUM * 20)

#define iom_pr_info(fmt, arg...) pr_info("[io_measure] %s,"fmt, __func__, ##arg)

enum iom_type {
	IO_TP_READ,
	IO_TP_WRITE,
	IO_TP_OTHER,
	IO_TP_NUM,
	IO_TP_INVAILD = IO_TP_NUM
};

enum iom_time_range {
	TIME_1 = 0,	/*<1ms*/
	TIME_2,		/*<2ms*/
	TIME_4,		/*<4ms*/
	TIME_8,		/*<8ms*/
	TIME_16,	/*<16ms*/
	TIME_32,	/*<32ms*/
	TIME_64,	/*<64ms*/
	TIME_128,	/*<128ms*/
	TIME_256,	/*<256ms*/
	TIME_512,	/*<512ms*/
	TIME_1024,	/*<1024ms*/
	TIME_OVERSIZE,	/*>1024ms*/
	MAX_LATENCY,	/*max_io_latency,2023-06-19*/
	TIME_DIV_NUM
};

enum iom_chunk_size {
	IO_CHUNK_4K,
	IO_CHUNK_8K,
	IO_CHUNK_16K,
	IO_CHUNK_32K,
	IO_CHUNK_128K,
	IO_CHUNK_512K,
	IO_CHUNK_NUM,
	IO_CHUNK_INVAILD = IO_CHUNK_NUM
};

static const uint iom_chunksize_array[IO_CHUNK_NUM] = {
	4096,	/*4KB*/
	8192,	/*8KB*/
	16384,  /*16KB*/
	32768,	/*32KB*/
	131072,	/*128KB*/
	524288	/*512KB*/
};

typedef u32 (*ioml_get_chunk_idx_func)(u32 size);
typedef void (*ioml_add_func)(void *iom_latency, u32 chunksz_idx,
	u32 time_us, u32 io_type);
typedef void (*ioml_get_func)(void *iom_latency, char *buf, u32 buf_len);

struct io_measure_latency_avg {
	u64 latency_total;
	u64 count;
};

struct io_measure_latency {
	struct io_measure_latency_avg latency_avg[IO_CHUNK_NUM][IO_TP_NUM];
	u64		latency_stat[IO_CHUNK_NUM][TIME_DIV_NUM][IO_TP_NUM];
	u32		log_threshold_us;
	char	log_tag[IOM_LATENCY_LOG_TAG_LEN];

	ioml_get_chunk_idx_func	iom_get_chunksize_idx;
	ioml_add_func	iom_latency_add;
	ioml_get_func	iom_latency_get;
};

struct io_measure_blk {
	struct io_measure_latency iom_latency;
	u64 latency_all[TIME_DIV_NUM][IO_TP_NUM];
	u64 latency_last[TIME_DIV_NUM][IO_TP_NUM];
	u64 latency_total_time[IO_TP_NUM];
};

#define IO_INO_HASH_MASK	0x7F
#define IO_OFS_HASH_MASK	0x7F
#define IO_INO_HSIZE		(IO_INO_HASH_MASK + 1)
#define IO_OFS_HSIZE		(IO_OFS_HASH_MASK + 1)

struct io_measure_fs_item {
	u32 flag;
	u32 ino;
	u32 offset_page;
	u32 start_time_us;
};

struct io_measure_fs {
	struct io_measure_latency iom_latency;
	struct io_measure_fs_item iom_item_inf[IO_INO_HSIZE][IO_OFS_HSIZE];
};

struct io_measure_pgcache {
	atomic64_t cache_stat[IOM_CACHE_TYPE_NR];
	u64 cache_size;
	u32 cache_count;
};

struct io_measure_scsi {
	struct io_measure_latency iom_latency;
	u64 latency_all[TIME_DIV_NUM][IO_TP_NUM];
	u64 latency_last[TIME_DIV_NUM][IO_TP_NUM];
	u64 latency_total_time[IO_TP_NUM];
};

struct io_measure_ctrl {
	bool iom_enable;
	bool enable_node_exist;
	uint iom_init_stage;
	struct delayed_work		iom_work;
	struct workqueue_struct		*iom_workqueue;
	struct proc_dir_entry		*iom_proc_root;
	struct io_measure_blk		*iom_blk;
	struct io_measure_fs		*iom_fs;
	struct io_measure_pgcache	*iom_pgcache;
	struct io_measure_scsi		*iom_scsi;
};

static struct io_measure_ctrl *iom_ctrl = NULL;
static DEFINE_MUTEX(iom_enable_lock);

static inline u32 io_measure_latency_time_index(u64 time_ms)
{
	u32 index = TIME_OVERSIZE;
	u32 i;

	if (likely(time_ms < IOM_TIME_IDX_TO_MS(TIME_1))) {
		index = TIME_1;
	} else if (time_ms < IOM_TIME_IDX_TO_MS(TIME_2)) {
		index = TIME_2;
	} else if (unlikely(time_ms >= IOM_TIME_IDX_TO_MS(TIME_1024))) {
		index = TIME_OVERSIZE;
	} else {
		for (i = TIME_512; i != TIME_1; i--) {
			if (time_ms & IOM_TIME_IDX_TO_MS(i)) {
				index = i + 1;
				break;
			}
		}
	}
	return index;
}

static u32 io_measure_latency_get_chunk_idx(u32 size)
{
	int i;

	for (i = 0; i < IO_CHUNK_NUM; i++) {
		if (size == iom_chunksize_array[i])
			break;
	}
	return i;
}

static void io_measure_latency_add(void *iom_latency,
	u32 chunksz_idx, u32 time_us, u32 io_type)
{
	struct io_measure_latency *iom_ltcy = (struct io_measure_latency *)iom_latency;
	u32 time_idx;

	if ((chunksz_idx >= IO_CHUNK_NUM) || (io_type >= IO_TP_NUM))
		return;

	//io latency stat
	time_idx = io_measure_latency_time_index((u64)IOM_US_TO_MS(time_us));
	iom_ltcy->latency_stat[chunksz_idx][time_idx][io_type]++;

	//max io latency
	if (unlikely((u64)time_us > iom_ltcy->latency_stat[chunksz_idx][MAX_LATENCY][io_type]))
		iom_ltcy->latency_stat[chunksz_idx][MAX_LATENCY][io_type] = (u64)time_us;

	//io average latency stat
	iom_ltcy->latency_avg[chunksz_idx][io_type].count++;
	iom_ltcy->latency_avg[chunksz_idx][io_type].latency_total += (u64)time_us;

	//io latency print
	if (unlikely(time_us > iom_ltcy->log_threshold_us)) {
		pr_info("[io_measure]%s,type:%u,len:%u,latency:%uus.\n",
		(char *)iom_ltcy->log_tag, io_type,
		iom_chunksize_array[chunksz_idx], time_us);
	}
}

static void io_measure_latency_get(void *iom_latency,
	char *buf, u32 buf_len)
{
	struct io_measure_latency *iom_ltcy = (struct io_measure_latency *)iom_latency;
	int i, j, k;
	int offset = 0;

	if ((buf == NULL) || (buf_len == 0))
		return;

	//Latency title
	offset = scnprintf(buf, buf_len, "Latency[%s]:\t", (char *)iom_ltcy->log_tag);
	for (i = 0; i < TIME_DIV_NUM - 2; i++) {
		offset += scnprintf(buf + offset, buf_len - offset,
				"%lu\t", IOM_TIME_IDX_TO_MS(i));
	}
	offset += scnprintf(buf + offset, buf_len - offset, "Oversize\tMax(us)\tAvg(us)");

	//Latency stat
	for (i = 0; i < IO_CHUNK_NUM; i++) {
		offset += scnprintf(buf + offset, buf_len - offset,
			"\nIO[%lu]:\t", IOM_BYTE_TO_KB(iom_chunksize_array[i]));
		for (j = 0; j < TIME_DIV_NUM; j++)
			for (k = 0; k < IO_TP_NUM; k++)
				offset += scnprintf(buf + offset, buf_len - offset,
				(k + 1 == IO_TP_NUM) ? "%lu\t" : "%lu/",
				iom_ltcy->latency_stat[i][j][k]);

		for (k = 0; k < IO_TP_NUM; k++)
			offset += scnprintf(buf + offset, buf_len - offset,
			(k + 1 == IO_TP_NUM) ? "%lu" : "%lu/",
			(iom_ltcy->latency_avg[i][k].count == 0) ? 0 :
				iom_ltcy->latency_avg[i][k].latency_total /
				iom_ltcy->latency_avg[i][k].count);
	}
}

/*
 * @brief: iom_latency for block and fs io latency stat.
 * iom_latency_add: add one io latency time.
 * iom_latency_get: get all latency stat info.
 */
static void io_measure_latency_init(
	struct io_measure_latency *iom_latency, char *tag)
{
	iom_latency->log_threshold_us		= IOM_LATENCY_THRESHOLD;
	iom_latency->iom_get_chunksize_idx	= io_measure_latency_get_chunk_idx;
	iom_latency->iom_latency_add		= io_measure_latency_add;
	iom_latency->iom_latency_get		= io_measure_latency_get;

	if (tag == NULL) {
		iom_latency->log_tag[0] = 0;
	} else {
		strncpy(iom_latency->log_tag, tag, IOM_LATENCY_LOG_TAG_LEN - 1);
		iom_latency->log_tag[IOM_LATENCY_LOG_TAG_LEN - 1] = 0;
	}
}

void io_measure_blk_sched_log(void)
{
	struct io_measure_blk *iom_blk = NULL;
	u64 latency_cur[TIME_DIV_NUM][IO_TP_NUM];
	char *buf = NULL;
	u32 buf_len = IOM_LOG_BUF_LEN;
	int offset;
	int i, j;

	if ((iom_ctrl == NULL) || (iom_ctrl->iom_blk == NULL) ||
		(iom_ctrl->iom_enable == false))
		return;

	iom_blk = iom_ctrl->iom_blk;
	buf = kmalloc(buf_len, GFP_KERNEL);
	if (!buf)
		return;
	memset(buf, 0, buf_len);

	memcpy(latency_cur, iom_blk->latency_all, sizeof(latency_cur));
	offset = scnprintf(buf, buf_len, "[BLK_LATENCY_SCATTER] ");
	//ignore max latency info print
	for (i = 0; i < TIME_DIV_NUM - 1; i++) {
		if (i != (TIME_DIV_NUM - 2))
			offset += scnprintf(buf + offset, buf_len - offset,
					"%u:[", IOM_TIME_IDX_TO_MS(i));
		else
			offset += scnprintf(buf + offset, buf_len - offset,
					"GE%u:[", IOM_TIME_IDX_TO_MS(i - 1));

		for (j = 0; j < IO_TP_NUM; j++)
			offset += scnprintf(buf + offset, buf_len - offset,
			(j + 1 == IO_TP_NUM) ? "%lu] " : "%lu/",
			latency_cur[i][j] - iom_blk->latency_last[i][j]);
	}

	memcpy(iom_blk->latency_last, latency_cur, sizeof(latency_cur));
	pr_info("%s\n", buf);
	kfree(buf);
}

static inline u32 io_measure_blk_optype_get(unsigned int op, unsigned int flag)
{
	u32 rw_type = IO_TP_INVAILD;

	switch (op) {
	case REQ_OP_READ:
		rw_type = IO_TP_READ;
		break;
	case REQ_OP_WRITE:
	case REQ_OP_WRITE_SAME:
#if IS_ENABLED(CONFIG_HYPERHOLD)
		if (flag & (REQ_SYNC | REQ_FUA | REQ_PREFLUSH | REQ_META | REQ_FG))
#else
		if (flag & (REQ_SYNC | REQ_FUA | REQ_PREFLUSH | REQ_META))
#endif
			rw_type = IO_TP_WRITE;
		break;
	case REQ_OP_FLUSH:
	case REQ_OP_DISCARD:
	case REQ_OP_SECURE_ERASE:
	default:
		rw_type = IO_TP_OTHER;
		break;
	}
	return rw_type;
}

static int io_measure_blk_sched_proc_show(struct seq_file *m, void *v)
{
	struct io_measure_blk *iom_blk = (struct io_measure_blk *)m->private;
	char *buf = NULL;
	u32 buf_len = IOM_PROC_BUF_LEN;
	int offset;
	int i, j;
	u64 io_cnt[IO_TP_NUM] = { 0 };

	if (iom_blk == NULL)
		return -EINVAL;

	buf = kmalloc(buf_len, GFP_KERNEL);
	if (!buf)
		return -ENOMEM;
	memset(buf, 0, buf_len);

	//Latency title
	offset = scnprintf(buf, buf_len, "Latency[scheduler]:\t");
	for (i = 0; i < TIME_DIV_NUM - 2; i++) {
		offset += scnprintf(buf + offset, buf_len - offset,
				"%lu\t", IOM_TIME_IDX_TO_MS(i));
	}
	offset += scnprintf(buf + offset, buf_len - offset, "oversize\tMax(us)\tAvg(us)\nIO:\t");

	//Latency stat
	for (i = 0; i < TIME_DIV_NUM; i++) {
		for (j = 0; j < IO_TP_NUM; j++) {
			offset += scnprintf(buf + offset, buf_len - offset,
			(j + 1 == IO_TP_NUM) ? "%lu\t" : "%lu/",
			iom_blk->latency_all[i][j]);
			io_cnt[j] += iom_blk->latency_all[i][j];
		}
	}
	for (j = 0; j < IO_TP_NUM; j++)
		offset += scnprintf(buf + offset, buf_len - offset,
		(j + 1 == IO_TP_NUM) ? "%lu" : "%lu/",
		IOM_NS_TO_US((io_cnt[j] == 0) ? 0 :
		iom_blk->latency_total_time[j] / io_cnt[j]));

	seq_printf(m, "%s\n", buf);
	kfree(buf);
	return 0;
}

static int io_measure_blk_sched_proc_open(struct inode *inode, struct file *file)
{
	return single_open(file, io_measure_blk_sched_proc_show, PDE_DATA(inode));
}

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
static const struct proc_ops iom_blk_sched_proc_fops = {
	.proc_open = io_measure_blk_sched_proc_open,
	.proc_read = seq_read,
	.proc_lseek = seq_lseek,
	.proc_release = single_release,
};
#else
static const struct file_operations iom_blk_sched_proc_fops = {
	.open = io_measure_blk_sched_proc_open,
	.read = seq_read,
	.llseek = seq_lseek,
	.release = single_release,
};
#endif

static int io_measure_blk_proc_show(struct seq_file *m, void *v)
{
	struct io_measure_blk *iom_blk = (struct io_measure_blk *)m->private;
	struct io_measure_latency *iom_ltcy = NULL;
	char *buf = NULL;

	if (iom_blk == NULL)
		return -EINVAL;

	buf = kmalloc(IOM_PROC_BUF_LEN, GFP_KERNEL);
	if (!buf)
		return -ENOMEM;
	memset(buf, 0, IOM_PROC_BUF_LEN);

	iom_ltcy = &iom_blk->iom_latency;
	iom_ltcy->iom_latency_get(iom_ltcy, buf, IOM_PROC_BUF_LEN);
	seq_printf(m, "%s\n", buf);

	kfree(buf);
	return 0;
}

static int io_measure_blk_proc_open(struct inode *inode, struct file *file)
{
	return single_open(file, io_measure_blk_proc_show, PDE_DATA(inode));
}

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
static const struct proc_ops iom_blk_proc_fops = {
	.proc_open = io_measure_blk_proc_open,
	.proc_read = seq_read,
	.proc_lseek = seq_lseek,
	.proc_release = single_release,
};
#else
static const struct file_operations iom_blk_proc_fops = {
	.open = io_measure_blk_proc_open,
	.read = seq_read,
	.llseek = seq_lseek,
	.release = single_release,
};
#endif

static void io_measure_blk_proc_remove(void)
{
	if (iom_ctrl && iom_ctrl->iom_proc_root) {
		remove_proc_entry(USER_IOM_BLK_ENTRY, iom_ctrl->iom_proc_root);
		remove_proc_entry(USER_IOM_BLK_SCHED, iom_ctrl->iom_proc_root);
	}
}

static int io_measure_blk_proc_creat(struct io_measure_blk *iom_blk)
{
	struct proc_dir_entry *proc_root = iom_ctrl->iom_proc_root;
	struct proc_dir_entry *proc_entry = NULL;

	proc_entry = proc_create_data(USER_IOM_BLK_ENTRY, 0444, proc_root,
		&iom_blk_proc_fops, iom_blk);
	if (proc_entry == NULL) {
		iom_pr_info("Create /proc/%s/%s fail.\n", USER_IOM_DIR, USER_IOM_BLK_ENTRY);
		return -ENODEV;
	}

	proc_entry = proc_create_data(USER_IOM_BLK_SCHED, 0444, proc_root,
		&iom_blk_sched_proc_fops, iom_blk);
	if (proc_entry == NULL) {
		iom_pr_info("Create /proc/%s/%s fail.\n", USER_IOM_DIR, USER_IOM_BLK_SCHED);
		return -ENODEV;
	}
	return 0;
}

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 15, 0))
static void io_measure_blk_rq_insert(void *ignore, struct request *rq)
#else
static void io_measure_blk_rq_insert(void *ignore,
	struct request_queue *q, struct request *rq)
#endif
{
	rq->rq_start_time_ns = ktime_get_ns();
}

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 15, 0))
static void io_measure_blk_rq_issue(void *ignore, struct request *rq)
#else
static void io_measure_blk_rq_issue(void *ignore,
	struct request_queue *q, struct request *rq)
#endif
{
	struct io_measure_blk *iom_blk = NULL;
	u32 io_type;
	u64 now_ns;
	u64 delta;
	u64 time_us;
	u32 time_idx;

	if ((iom_ctrl == NULL) || (iom_ctrl->iom_blk == NULL) ||
		(iom_ctrl->iom_enable == false))
		return;

	iom_blk = iom_ctrl->iom_blk;
	if (rq->rq_start_time_ns == 0)
		return;

	//1.get io type
	io_type = io_measure_blk_optype_get(req_op(rq), rq->cmd_flags);
	if (io_type == IO_TP_INVAILD)
		return;

	//2.get delay time
	now_ns = ktime_get_ns();
	if (now_ns <= rq->rq_start_time_ns)
		return;
	delta = now_ns - rq->rq_start_time_ns;
	time_idx = io_measure_latency_time_index(IOM_NS_TO_MS(delta));

	//max io latency
	time_us = IOM_NS_TO_US(delta);
	if (unlikely(time_us > iom_blk->latency_all[MAX_LATENCY][io_type]))
		iom_blk->latency_all[MAX_LATENCY][io_type] = time_us;

	iom_blk->latency_all[time_idx][io_type]++;
	iom_blk->latency_total_time[io_type] += delta;
	if (unlikely(delta > IOM_BLK_LTCY_THRESHOLD)) {
		pr_info("[io_measure]rq_insert_to_issue:rq_flag:0x%x,latency:%uns.\n",
		rq->cmd_flags, delta);
	}
}

static void io_measure_blk_rq_complete(void *ignore, struct request *rq,
			int error, unsigned int nr_bytes)
{
	struct io_measure_blk *iom_blk = NULL;
	struct io_measure_latency *iom_ltcy = NULL;
	u64 rq_start_ns;
	u32 chunksz_idx;
	u32 io_type;
	u64 now_ns;
	u64 delta;

	if (rq->rq_start_time_ns == 0)
		return;
	rq_start_ns = rq->rq_start_time_ns;
	rq->rq_start_time_ns = 0;

	if ((iom_ctrl == NULL) || (iom_ctrl->iom_blk == NULL) ||
		(iom_ctrl->iom_enable == false))
		return;

	iom_blk = iom_ctrl->iom_blk;
	iom_ltcy = &iom_blk->iom_latency;

	//1.get chunksize index
	chunksz_idx = iom_ltcy->iom_get_chunksize_idx((u32)blk_rq_bytes(rq));
	if (chunksz_idx == IO_CHUNK_INVAILD)
		return;

	//2.get io type
	io_type = io_measure_blk_optype_get(req_op(rq), rq->cmd_flags);
	if (io_type == IO_TP_INVAILD)
		return;

	//3.get delay time
	now_ns = ktime_get_ns();
	if (now_ns <= rq_start_ns)
		return;
	delta = now_ns - rq_start_ns;

	iom_ltcy->iom_latency_add(iom_ltcy, chunksz_idx,
		(u32)IOM_NS_TO_US(delta), io_type);
}

static void io_measure_blk_unregister_tracepoints(void)
{
	unregister_trace_block_rq_insert(io_measure_blk_rq_insert, NULL);
	unregister_trace_block_rq_issue(io_measure_blk_rq_issue, NULL);
	unregister_trace_block_rq_complete(io_measure_blk_rq_complete, NULL);
	tracepoint_synchronize_unregister();
}

static void io_measure_blk_register_tracepoints(void)
{
	int ret = 0;

	ret |= register_trace_block_rq_insert(io_measure_blk_rq_insert, NULL);
	ret |= register_trace_block_rq_issue(io_measure_blk_rq_issue, NULL);
	ret |= register_trace_block_rq_complete(io_measure_blk_rq_complete, NULL);

	if (ret)
		iom_pr_info("register tracepoint failed.");
}

static void io_measure_block_exit(void)
{
	if (iom_ctrl && iom_ctrl->iom_blk) {
		io_measure_blk_proc_remove();
		io_measure_blk_unregister_tracepoints();

		kfree(iom_ctrl->iom_blk);
		iom_ctrl->iom_blk = NULL;
	}
}

/*
 * @brief: init block resource for io measure, it is block root struct.
 * @return: 0:init success; others: fail.
 */
static int io_measure_block_init(void)
{
	int ret = 0;
	struct io_measure_blk *iom_blk = NULL;

	iom_blk = kmalloc(sizeof(struct io_measure_blk), GFP_KERNEL);
	if (iom_blk == NULL)
		return -ENOMEM;

	iom_ctrl->iom_blk = iom_blk;
	memset(iom_blk, 0, sizeof(struct io_measure_blk));
	io_measure_latency_init(&iom_blk->iom_latency, "block");

	io_measure_blk_register_tracepoints();

	ret = io_measure_blk_proc_creat(iom_blk);

	return ret;
}

static int io_measure_fs_proc_show(struct seq_file *m, void *v)
{
	struct io_measure_fs *iom_fs = (struct io_measure_fs *)m->private;
	struct io_measure_latency *iom_ltcy = NULL;
	char *buf = NULL;

	if (iom_fs == NULL)
		return -EINVAL;

	buf = kmalloc(IOM_PROC_BUF_LEN, GFP_KERNEL);
	if (buf == NULL)
		return -ENOMEM;
	memset(buf, 0, IOM_PROC_BUF_LEN);

	iom_ltcy = &iom_fs->iom_latency;
	iom_ltcy->iom_latency_get(iom_ltcy, buf, IOM_PROC_BUF_LEN);
	seq_printf(m, "%s\n", buf);

	kfree(buf);
	return 0;
}

static int io_measure_fs_proc_open(struct inode *inode, struct file *file)
{
	return single_open(file, io_measure_fs_proc_show, PDE_DATA(inode));
}

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
static const struct proc_ops iom_fs_proc_fops = {
	.proc_open = io_measure_fs_proc_open,
	.proc_read = seq_read,
	.proc_lseek = seq_lseek,
	.proc_release = single_release,
};
#else
static const struct file_operations iom_fs_proc_fops = {
	.open = io_measure_fs_proc_open,
	.read = seq_read,
	.llseek = seq_lseek,
	.release = single_release,
};
#endif

static void io_measure_fs_proc_remove(void)
{
	if (iom_ctrl && iom_ctrl->iom_proc_root)
		remove_proc_entry(USER_IOM_FS_ENTRY, iom_ctrl->iom_proc_root);
}

static int io_measure_fs_proc_creat(struct io_measure_fs *iom_fs)
{
	struct proc_dir_entry *proc_root = iom_ctrl->iom_proc_root;
	struct proc_dir_entry *proc_entry = NULL;

	proc_entry = proc_create_data(USER_IOM_FS_ENTRY, 0444, proc_root,
		&iom_fs_proc_fops, iom_fs);
	if (proc_entry == NULL) {
		iom_pr_info("Create /proc/%s/%s fail.\n", USER_IOM_DIR, USER_IOM_FS_ENTRY);
		return -ENODEV;
	}
	return 0;
}

void io_measure_scsi_sched_log(void)
{
	struct io_measure_scsi *iom_scsi = NULL;
	u64 latency_cur[TIME_DIV_NUM][IO_TP_NUM];
	char *buf = NULL;
	u32 buf_len = IOM_LOG_BUF_LEN;
	int offset;
	int i, j;

	if ((iom_ctrl == NULL) || (iom_ctrl->iom_scsi == NULL) ||
		(iom_ctrl->iom_enable == false))
		return;

	iom_scsi = iom_ctrl->iom_scsi;
	buf = kmalloc(buf_len, GFP_KERNEL);
	if (!buf)
		return;
	memset(buf, 0, buf_len);

	memcpy(latency_cur, iom_scsi->latency_all, sizeof(latency_cur));
	offset = scnprintf(buf, buf_len, "[SCSI_LATENCY_SCATTER] ");
	//ignore max latency info  print
	for (i = 0; i < TIME_DIV_NUM - 1; i++) {
		if (i != (TIME_DIV_NUM - 2))
			offset += scnprintf(buf + offset, buf_len - offset,
					"%u:[", IOM_TIME_IDX_TO_MS(i));
		else
			offset += scnprintf(buf + offset, buf_len - offset,
					"GE%u:[", IOM_TIME_IDX_TO_MS(i - 1));

		for (j = 0; j < IO_TP_NUM; j++)
			offset += scnprintf(buf + offset, buf_len - offset,
			(j + 1 == IO_TP_NUM) ? "%lu] " : "%lu/",
			latency_cur[i][j] - iom_scsi->latency_last[i][j]);
	}

	memcpy(iom_scsi->latency_last, latency_cur, sizeof(latency_cur));
	pr_info("%s\n", buf);
	kfree(buf);
}

static int io_measure_scsi_sched_proc_show(struct seq_file *m, void *v)
{
	struct io_measure_scsi *iom_scsi = (struct io_measure_scsi *)m->private;
	char *buf = NULL;
	u32 buf_len = IOM_PROC_BUF_LEN;
	int offset;
	int i, j;
	u64 io_cnt[IO_TP_NUM] = { 0 };

	if (iom_scsi == NULL)
		return -EINVAL;

	buf = kmalloc(buf_len, GFP_KERNEL);
	if (!buf)
		return -ENOMEM;
	memset(buf, 0, buf_len);

	//Latency title
	offset = scnprintf(buf, buf_len, "Latency[scheduler]:\t");
	for (i = 0; i < TIME_DIV_NUM - 2; i++) {
		offset += scnprintf(buf + offset, buf_len - offset,
				"%lu\t", IOM_TIME_IDX_TO_MS(i));
	}
	offset += scnprintf(buf + offset, buf_len - offset, "oversize\tMax(us)\tAvg(us)\nIO:\t");

	//Latency stat
	for (i = 0; i < TIME_DIV_NUM; i++) {
		for (j = 0; j < IO_TP_NUM; j++) {
			offset += scnprintf(buf + offset, buf_len - offset,
			(j + 1 == IO_TP_NUM) ? "%lu\t" : "%lu/",
			iom_scsi->latency_all[i][j]);
			io_cnt[j] += iom_scsi->latency_all[i][j];
		}
	}
	for (j = 0; j < IO_TP_NUM; j++) {
		offset += scnprintf(buf + offset, buf_len - offset,
		(j + 1 == IO_TP_NUM) ? "%lu" : "%lu/",
		IOM_NS_TO_US((io_cnt[j] == 0) ? 0 :
		iom_scsi->latency_total_time[j] / io_cnt[j]));
	}

	seq_printf(m, "%s\n", buf);
	kfree(buf);
	return 0;
}

static int io_measure_scsi_sched_proc_open(struct inode *inode, struct file *file)
{
	return single_open(file, io_measure_scsi_sched_proc_show, PDE_DATA(inode));
}

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
static const struct proc_ops iom_scsi_sched_proc_fops = {
	.proc_open = io_measure_scsi_sched_proc_open,
	.proc_read = seq_read,
	.proc_lseek = seq_lseek,
	.proc_release = single_release,
};
#else
static const struct file_operations iom_scsi_sched_proc_fops = {
	.open = io_measure_scsi_sched_proc_open,
	.read = seq_read,
	.llseek = seq_lseek,
	.release = single_release,
};
#endif

static int io_measure_scsi_proc_show(struct seq_file *m, void *v)
{
	struct io_measure_scsi *iom_scsi = (struct io_measure_scsi *)m->private;
	struct io_measure_latency *iom_ltcy = NULL;
	char *buf = NULL;

	if (iom_scsi == NULL)
		return -EINVAL;

	buf = kmalloc(IOM_PROC_BUF_LEN, GFP_KERNEL);
	if (!buf)
		return -ENOMEM;
	memset(buf, 0, IOM_PROC_BUF_LEN);

	iom_ltcy = &iom_scsi->iom_latency;
	iom_ltcy->iom_latency_get(iom_ltcy, buf, IOM_PROC_BUF_LEN);
	seq_printf(m, "%s\n", buf);

	kfree(buf);
	return 0;
}

static int io_measure_scsi_proc_open(struct inode *inode, struct file *file)
{
	return single_open(file, io_measure_scsi_proc_show, PDE_DATA(inode));
}

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
static const struct proc_ops iom_scsi_proc_fops = {
	.proc_open = io_measure_scsi_proc_open,
	.proc_read = seq_read,
	.proc_lseek = seq_lseek,
	.proc_release = single_release,
};
#else
static const struct file_operations iom_scsi_proc_fops = {
	.open = io_measure_scsi_proc_open,
	.read = seq_read,
	.llseek = seq_lseek,
	.release = single_release,
};
#endif

static void io_measure_scsi_proc_remove(void)
{
	if (iom_ctrl && iom_ctrl->iom_proc_root) {
		remove_proc_entry(USER_IOM_SCSI_ENTRY, iom_ctrl->iom_proc_root);
		remove_proc_entry(USER_IOM_SCSI_SCHED, iom_ctrl->iom_proc_root);
	}
}

static int io_measure_scsi_proc_creat(struct io_measure_scsi *iom_scsi)
{
	struct proc_dir_entry *proc_root = iom_ctrl->iom_proc_root;
	struct proc_dir_entry *proc_entry = NULL;

	proc_entry = proc_create_data(USER_IOM_SCSI_ENTRY, 0444, proc_root,
		&iom_scsi_proc_fops, iom_scsi);
	if (proc_entry == NULL) {
		iom_pr_info("Create /proc/%s/%s fail.\n", USER_IOM_DIR, USER_IOM_SCSI_ENTRY);
		return -ENODEV;
	}

	proc_entry = proc_create_data(USER_IOM_SCSI_SCHED, 0444, proc_root,
		&iom_scsi_sched_proc_fops, iom_scsi);
	if (proc_entry == NULL) {
		iom_pr_info("Create /proc/%s/%s fail.\n", USER_IOM_DIR, USER_IOM_SCSI_SCHED);
		return -ENODEV;
	}
	return 0;
}

#ifdef CONFIG_HONOR_RWLOG
void io_measure_scsi_dispatch_cmd_start_lifetime(void *ignore, struct scsi_cmnd *cmd,
		unsigned long long secd, unsigned long long nrsecd)
#else
void io_measure_scsi_dispatch_cmd_start(void *ignore, struct scsi_cmnd *cmd)
#endif
{
	cmd->iomt_start_time.ticks = jiffies;
	cmd->iomt_start_time.ktime = ktime_get_ns();
}

unsigned char io_measure_scsi_optype_get(struct scsi_cmnd *cmd)
{
	if (cmd->sc_data_direction == DMA_FROM_DEVICE)
		return IO_TP_READ;
	else if (cmd->sc_data_direction == DMA_TO_DEVICE)
		return IO_TP_WRITE;
	else
		return IO_TP_OTHER;
}

static void io_measure_scsi_dispatch_cmd_done(void *ignore,
	struct scsi_cmnd *cmd)
{
	struct io_measure_scsi *iom_scsi = NULL;
	struct io_measure_latency *iom_ltcy = NULL;
	struct request *rq = cmd->request;
	u64 now_ns;
	u64 delta;
	u64 time_us;
	u32 time_idx;
	u32 io_type;
	u32 chunksz_idx;
	u32 bytes;

	if ((iom_ctrl == NULL) || (iom_ctrl->iom_scsi == NULL) ||
		(iom_ctrl->iom_enable == false))
		return;

	iom_scsi = iom_ctrl->iom_scsi;
	iom_ltcy = &iom_scsi->iom_latency;

	if (cmd->iomt_start_time.ktime == 0)
		return;
	//1.get chunksize index
	bytes = (u32)blk_rq_bytes(rq);
	chunksz_idx = iom_ltcy->iom_get_chunksize_idx((u32)bytes);
	if (chunksz_idx == IO_CHUNK_INVAILD)
		return;
	//2.get scsi io type
	io_type = io_measure_scsi_optype_get(cmd);
	//3.get delay time
	now_ns = ktime_get_ns();
	if (now_ns <= cmd->iomt_start_time.ktime)
		return;
	delta = now_ns - cmd->iomt_start_time.ktime;
	time_idx = io_measure_latency_time_index(IOM_NS_TO_MS(delta));

	//max io latency
	time_us = IOM_NS_TO_US(delta);
	if (unlikely(time_us > iom_scsi->latency_all[MAX_LATENCY][io_type]))
		iom_scsi->latency_all[MAX_LATENCY][io_type] = time_us;

	iom_scsi->latency_all[time_idx][io_type]++;
	iom_scsi->latency_total_time[io_type] += delta;
	if (unlikely(delta > IOM_SCSI_LTCY_THRESHOLD)) {
		pr_info("[io_measure]scsi_scsi_cmd_done:io_type:%d,latency:%uns.\n",
		io_type, delta);
	}
	iom_ltcy->iom_latency_add(iom_ltcy, chunksz_idx,
	(u32)IOM_NS_TO_US(delta), io_type);
}

static void io_measure_scsi_unregister_tracepoints(void)
{
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(4, 19, 0))
#ifdef CONFIG_HONOR_RWLOG
	unregister_trace_scsi_dispatch_cmd_start_lifetime(io_measure_scsi_dispatch_cmd_start_lifetime, NULL);
#else
	unregister_trace_scsi_dispatch_cmd_start(io_measure_scsi_dispatch_cmd_start, NULL);
#endif
	unregister_trace_scsi_dispatch_cmd_done(io_measure_scsi_dispatch_cmd_done, NULL);
	tracepoint_synchronize_unregister();
#endif
}

static void io_measure_scsi_register_tracepoints(void)
{
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(4, 19, 0))
	int ret = 0;

#ifdef CONFIG_HONOR_RWLOG
	ret |= register_trace_scsi_dispatch_cmd_start_lifetime(io_measure_scsi_dispatch_cmd_start_lifetime, NULL);
#else
	ret |= register_trace_scsi_dispatch_cmd_start(io_measure_scsi_dispatch_cmd_start, NULL);
#endif
	ret |= register_trace_scsi_dispatch_cmd_done(io_measure_scsi_dispatch_cmd_done, NULL);

	if (ret)
		iom_pr_info("register tracepoint failed.");
#endif
}

static void io_measure_scsi_exit(void)
{
	if (iom_ctrl && iom_ctrl->iom_scsi) {
		io_measure_scsi_proc_remove();
		io_measure_scsi_unregister_tracepoints();

		kfree(iom_ctrl->iom_scsi);
		iom_ctrl->iom_scsi = NULL;
	}
}
/*
 * @brief: init scsi resource for io measure, it is scsi root struct.
 * @return: 0:init success; others: fail.
 */
static int io_measure_scsi_init(void)
{
	int ret = 0;
	struct io_measure_scsi *iom_scsi = NULL;

	iom_scsi = kmalloc(sizeof(struct io_measure_scsi), GFP_KERNEL);
	if (iom_scsi == NULL)
		return -ENOMEM;

	iom_ctrl->iom_scsi = iom_scsi;
	memset(iom_scsi, 0, sizeof(struct io_measure_scsi));
	io_measure_latency_init(&iom_scsi->iom_latency, "scsi");

	io_measure_scsi_register_tracepoints();

	ret = io_measure_scsi_proc_creat(iom_scsi);

	return ret;
}

/*
 * @brief: save information when start IO request.
 * Some IO items will be overwritten, but the current sampling statistics,
 * you can ignore this problem, just get the correct sampling value.
 */
static inline void io_measure_fs_item_set(struct io_measure_fs *iom_fs,
	struct inode *inode, loff_t offset, u32 rw_flag)
{
	struct io_measure_fs_item *iom_item = NULL;
	u32 inode_idx;
	u32 offset_idx;

	inode_idx = (u32)inode->i_ino & IO_INO_HASH_MASK;
	offset_idx = (u32)offset & IO_OFS_HASH_MASK;
	iom_item = &iom_fs->iom_item_inf[inode_idx][offset_idx];
	iom_item->flag = rw_flag;
	iom_item->ino = (u32)inode->i_ino;
	iom_item->offset_page = (u32)IOM_BYTE_TO_PAGE(offset);
	iom_item->start_time_us = (u32)IOM_NS_TO_US(ktime_get_ns());
}

static inline struct io_measure_fs_item *io_measure_fs_item_get(
	struct io_measure_fs *iom_fs, struct inode *inode,
	loff_t offset, u32 rw_flag)
{
	struct io_measure_fs_item *iom_item = NULL;
	u32 inode_idx;
	u32 offset_idx;

	inode_idx = (u32)inode->i_ino & IO_INO_HASH_MASK;
	offset_idx = (u32)offset & IO_OFS_HASH_MASK;
	iom_item = &iom_fs->iom_item_inf[inode_idx][offset_idx];
	if ((iom_item->flag != rw_flag) ||
		(iom_item->ino != (u32)inode->i_ino) ||
		(iom_item->offset_page != (u32)IOM_BYTE_TO_PAGE(offset))) {
		return NULL;
	}
	return iom_item;
}


static void io_measure_fs_dataread_start(void *ignore,
	struct inode *inode, loff_t offset, int bytes, pid_t pid,
	char *pathname, char *command)
{
	struct io_measure_fs *iom_fs = NULL;
	u32 chunksz_idx;

	if ((iom_ctrl == NULL) || (iom_ctrl->iom_fs == NULL) ||
		(iom_ctrl->iom_enable == false))
		return;

	iom_fs = iom_ctrl->iom_fs;
	chunksz_idx = iom_fs->iom_latency.iom_get_chunksize_idx((u32)bytes);
	if (chunksz_idx == IO_CHUNK_INVAILD)
		return;

	io_measure_fs_item_set(iom_fs, inode, offset, IO_TP_READ);
}

static void io_measure_fs_dataread_end(void *ignore,
	struct inode *inode, loff_t offset, int bytes)
{
	struct io_measure_fs *iom_fs = NULL;
	struct io_measure_latency *iom_ltcy = NULL;
	struct io_measure_fs_item *iom_item = NULL;
	u32	chunksz_idx;
	u32	now_us;
	u32	delta;

	if ((iom_ctrl == NULL) || (iom_ctrl->iom_fs == NULL) ||
		(iom_ctrl->iom_enable == false))
		return;

	iom_fs = iom_ctrl->iom_fs;
	iom_ltcy = &iom_fs->iom_latency;
	chunksz_idx = iom_ltcy->iom_get_chunksize_idx((u32)bytes);
	if (chunksz_idx == IO_CHUNK_INVAILD)
		return;

	iom_item = io_measure_fs_item_get(iom_fs, inode, offset, IO_TP_READ);
	if (iom_item == NULL)
		return;

	now_us = (u32)IOM_NS_TO_US(ktime_get_ns());
	if (now_us <= iom_item->start_time_us)
		return;
	delta = now_us - iom_item->start_time_us;

	iom_ltcy->iom_latency_add(iom_ltcy, chunksz_idx, delta, IO_TP_READ);
}

static void io_measure_fs_datawrite_start(void *ignore,
	struct inode *inode, loff_t offset, int bytes, pid_t pid,
	char *pathname, char *command)
{
	struct io_measure_fs *iom_fs = NULL;
	u32 chunksz_idx;

	if ((iom_ctrl == NULL) || (iom_ctrl->iom_fs == NULL) ||
		(iom_ctrl->iom_enable == false))
		return;

	iom_fs = iom_ctrl->iom_fs;
	chunksz_idx = iom_fs->iom_latency.iom_get_chunksize_idx((u32)bytes);
	if (chunksz_idx == IO_CHUNK_INVAILD)
		return;

	io_measure_fs_item_set(iom_fs, inode, offset, IO_TP_WRITE);
}

static void io_measure_fs_datawrite_end(void *ignore,
	struct inode *inode, loff_t offset, int bytes)
{
	struct io_measure_fs *iom_fs = NULL;
	struct io_measure_latency *iom_ltcy = NULL;
	struct io_measure_fs_item *iom_item = NULL;
	u32	chunksz_idx;
	u32	now_us;
	u32	delta;

	if ((iom_ctrl == NULL) || (iom_ctrl->iom_fs == NULL) ||
		(iom_ctrl->iom_enable == false))
		return;

	iom_fs = iom_ctrl->iom_fs;
	iom_ltcy = &iom_fs->iom_latency;
	chunksz_idx = iom_ltcy->iom_get_chunksize_idx((u32)bytes);
	if (chunksz_idx == IO_CHUNK_INVAILD)
		return;

	iom_item = io_measure_fs_item_get(iom_fs, inode, offset, IO_TP_WRITE);
	if (iom_item == NULL)
		return;

	now_us = (u32)IOM_NS_TO_US(ktime_get_ns());
	if (now_us <= iom_item->start_time_us)
		return;
	delta = now_us - iom_item->start_time_us;

	iom_ltcy->iom_latency_add(iom_ltcy, chunksz_idx, delta, IO_TP_WRITE);
}

static void io_measure_fs_unregister_tracepoints(void)
{
	unregister_trace_android_fs_dataread_start(io_measure_fs_dataread_start, NULL);
	unregister_trace_android_fs_dataread_end(io_measure_fs_dataread_end, NULL);
	unregister_trace_android_fs_datawrite_start(io_measure_fs_datawrite_start, NULL);
	unregister_trace_android_fs_datawrite_end(io_measure_fs_datawrite_end, NULL);
	tracepoint_synchronize_unregister();
}

static void io_measure_fs_register_tracepoints(void)
{
	int ret = 0;

	ret |= register_trace_android_fs_dataread_start(io_measure_fs_dataread_start, NULL);
	ret |= register_trace_android_fs_dataread_end(io_measure_fs_dataread_end, NULL);
	ret |= register_trace_android_fs_datawrite_start(io_measure_fs_datawrite_start, NULL);
	ret |= register_trace_android_fs_datawrite_end(io_measure_fs_datawrite_end, NULL);

	if (ret)
		iom_pr_info("register tracepoint failed.");
}

static void io_measure_fs_exit(void)
{
	if (iom_ctrl && iom_ctrl->iom_fs) {
		io_measure_fs_proc_remove();
		io_measure_fs_unregister_tracepoints();

		kfree(iom_ctrl->iom_fs);
		iom_ctrl->iom_fs = NULL;
	}
}

/*
 * @brief: init fs resource for io measure, it is fs root struct.
 * @return: 0:init success; others: fail.
 */
static int io_measure_fs_init(void)
{
	int ret = 0;
	struct io_measure_fs *iom_fs = NULL;

	iom_fs = kmalloc(sizeof(struct io_measure_fs), GFP_KERNEL);
	if (iom_fs == NULL)
		return -ENOMEM;

	iom_ctrl->iom_fs = iom_fs;
	memset(iom_fs, 0, sizeof(struct io_measure_fs));
	io_measure_latency_init(&iom_fs->iom_latency, "fs");

	io_measure_fs_register_tracepoints();

	ret = io_measure_fs_proc_creat(iom_fs);

	return ret;
}

void io_measure_pgcache_stat_inc(enum iom_pgcache_type type)
{
	mutex_lock(&iom_enable_lock);
	if ((iom_ctrl == NULL) || (iom_ctrl->iom_enable == false)) {
		mutex_unlock(&iom_enable_lock);
		return;
	}
	atomic64_inc(&iom_ctrl->iom_pgcache->cache_stat[type]);
	mutex_unlock(&iom_enable_lock);
}
EXPORT_SYMBOL(io_measure_pgcache_stat_inc);

static int io_measure_pgcache_proc_show(struct seq_file *m, void *v)
{
	struct io_measure_pgcache *iom_pgcache = NULL;

	iom_pgcache = (struct io_measure_pgcache *)m->private;
	if (iom_pgcache == NULL)
		return -EINVAL;

	seq_printf(m,
		"pgcache_access_hit:       %llu\n"
		"pgcache_access_miss:      %llu\n"
		"pgcache_add:              %llu\n"
		"pgcache_readahead_amount: %llu\n"
		"pgcache_readahead_hit:    %llu\n"
		"pgcache_average_size:     %llu\n",
		atomic64_read(&iom_pgcache->cache_stat[IOM_CACHE_ACCESS]) -
		atomic64_read(&iom_pgcache->cache_stat[IOM_CACHE_MISS]),
		atomic64_read(&iom_pgcache->cache_stat[IOM_CACHE_MISS]),
		atomic64_read(&iom_pgcache->cache_stat[IOM_CACHE_ADD]),
		atomic64_read(&iom_pgcache->cache_stat[IOM_CACHE_RA_ADD]),
		atomic64_read(&iom_pgcache->cache_stat[IOM_CACHE_RA_HIT]),
		IOM_PAGE_TO_KB(iom_pgcache->cache_size / (u64)iom_pgcache->cache_count));

	return 0;
}

static int io_measure_pgcache_proc_open(struct inode *inode, struct file *file)
{
	return single_open(file, io_measure_pgcache_proc_show, PDE_DATA(inode));
}

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
static const struct proc_ops iom_pgcache_proc_fops = {
	.proc_open = io_measure_pgcache_proc_open,
	.proc_read = seq_read,
	.proc_lseek = seq_lseek,
	.proc_release = single_release,
};
#else
static const struct file_operations iom_pgcache_proc_fops = {
	.open = io_measure_pgcache_proc_open,
	.read = seq_read,
	.llseek = seq_lseek,
	.release = single_release,
};
#endif

static void io_measure_pgcache_proc_remove(void)
{
	if (iom_ctrl && iom_ctrl->iom_proc_root)
		remove_proc_entry(USER_IOM_PG_ENTRY, iom_ctrl->iom_proc_root);
}

static int io_measure_pgcache_proc_creat(struct io_measure_pgcache *iom_pgcache)
{
	struct proc_dir_entry *proc_root = iom_ctrl->iom_proc_root;
	struct proc_dir_entry *proc_entry = NULL;

	proc_entry = proc_create_data(USER_IOM_PG_ENTRY, 0444, proc_root,
		&iom_pgcache_proc_fops, iom_pgcache);
	if (proc_entry == NULL) {
		iom_pr_info("Create /proc/%s/%s fail.\n", USER_IOM_DIR, USER_IOM_PG_ENTRY);
		return -ENODEV;
	}
	return 0;
}

static void io_measure_pagecache_exit(void)
{
	if (iom_ctrl && iom_ctrl->iom_pgcache) {
		io_measure_pgcache_proc_remove();
		kfree(iom_ctrl->iom_pgcache);
		iom_ctrl->iom_pgcache = NULL;
	}
}

/*
 * @brief: init pagecache resource for io measure, it is pagecache root struct.
 * @return: 0:init success; others: fail.
 */
static int io_measure_pagecache_init(void)
{
	int ret = 0;
	struct io_measure_pgcache *iom_pgcache = NULL;

	iom_pgcache = kmalloc(sizeof(struct io_measure_pgcache), GFP_KERNEL);
	if (iom_pgcache == NULL)
		return -ENOMEM;

	iom_ctrl->iom_pgcache = iom_pgcache;
	memset(iom_pgcache, 0, sizeof(struct io_measure_pgcache));
	ret = io_measure_pgcache_proc_creat(iom_pgcache);

	return ret;
}

static void io_measure_reset(void)
{
	struct io_measure_blk *iom_blk = NULL;
	struct io_measure_fs  *iom_fs = NULL;
	struct io_measure_pgcache *iom_pg = NULL;
	struct io_measure_scsi *iom_scsi = NULL;

	if ((iom_ctrl == NULL) || (iom_ctrl->iom_pgcache == NULL) ||
		(iom_ctrl->iom_blk == NULL) || (iom_ctrl->iom_fs == NULL) ||
		(iom_ctrl->iom_scsi == NULL))
		return;

	iom_ctrl->iom_enable = false;

	// pagecache measure reset
	iom_pg = iom_ctrl->iom_pgcache;
	memset(iom_pg, 0, sizeof(struct io_measure_pgcache));

	// fs measure reset
	iom_fs = iom_ctrl->iom_fs;
	memset(iom_fs->iom_latency.latency_avg, 0, sizeof(iom_fs->iom_latency.latency_avg));
	memset(iom_fs->iom_latency.latency_stat, 0, sizeof(iom_fs->iom_latency.latency_stat));

	// block measure reset
	iom_blk = iom_ctrl->iom_blk;
	memset(iom_blk->latency_total_time, 0, sizeof(iom_blk->latency_total_time));
	memset(iom_blk->latency_all, 0, sizeof(iom_blk->latency_all));
	memset(iom_blk->latency_last, 0, sizeof(iom_blk->latency_last));
	memset(iom_blk->iom_latency.latency_avg, 0, sizeof(iom_blk->iom_latency.latency_avg));
	memset(iom_blk->iom_latency.latency_stat, 0, sizeof(iom_blk->iom_latency.latency_stat));

	// scsi measure reset
	iom_scsi = iom_ctrl->iom_scsi;
	memset(iom_scsi->latency_total_time, 0, sizeof(iom_scsi->latency_total_time));
	memset(iom_scsi->latency_all, 0, sizeof(iom_scsi->latency_all));
	memset(iom_scsi->latency_last, 0, sizeof(iom_scsi->latency_last));
	memset(iom_scsi->iom_latency.latency_avg, 0, sizeof(iom_scsi->iom_latency.latency_avg));
	memset(iom_scsi->iom_latency.latency_stat, 0, sizeof(iom_scsi->iom_latency.latency_stat));

	iom_ctrl->iom_enable = true;
}

static int io_measure_reset_proc_show(struct seq_file *m, void *v)
{
	int val = 0;

	seq_printf(m, "%d\n", val);
	return 0;
}

static int io_measure_reset_proc_open(struct inode *inode, struct file *file)
{
	return single_open(file, io_measure_reset_proc_show, NULL);
}

static ssize_t io_measure_reset_proc_write(struct file *file,
	const char __user *buffer, size_t count, loff_t *ppos)
{
	bool reset;
	int rc;

	rc = kstrtobool_from_user(buffer, count, &reset);
	if (rc)
		return rc;

	if ((iom_ctrl == NULL) || (iom_ctrl->iom_enable == false) ||
		(iom_ctrl->iom_fs == NULL) || (iom_ctrl->iom_blk == NULL) ||
		(iom_ctrl->iom_scsi == NULL))
		return -EINVAL;

	if (reset) {
		io_measure_reset();
		iom_pr_info("reset success.\n");
	}

	return count;
}

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
static const struct proc_ops iom_reset_proc_fops = {
	.proc_open = io_measure_reset_proc_open,
	.proc_write = io_measure_reset_proc_write,
	.proc_read = seq_read,
	.proc_lseek = seq_lseek,
	.proc_release = single_release,
};
#else
static const struct file_operations iom_reset_proc_fops = {
	.open = io_measure_reset_proc_open,
	.write = io_measure_reset_proc_write,
	.read = seq_read,
	.llseek = seq_lseek,
	.release = single_release,
};
#endif

static void io_measure_reset_exit(void)
{
	if (iom_ctrl && iom_ctrl->iom_proc_root && iom_ctrl->iom_enable)
		remove_proc_entry(USER_IOM_RESET, iom_ctrl->iom_proc_root);
}

static int io_measure_reset_init(void)
{
	struct proc_dir_entry *proc_root = iom_ctrl->iom_proc_root;
	struct proc_dir_entry *proc_entry = NULL;

	proc_entry = proc_create(USER_IOM_RESET, 0644, proc_root,
		&iom_reset_proc_fops);
	if (proc_entry == NULL) {
		iom_pr_info("Create /proc/%s/%s fail.\n", USER_IOM_DIR, USER_IOM_RESET);
		return -ENODEV;
	}
	return 0;
}

static void io_measure_work_run(void)
{
	struct io_measure_pgcache *iom_pgcache = NULL;
	unsigned long cached;

	if ((iom_ctrl == NULL) || (iom_ctrl->iom_pgcache == NULL))
		return;

	iom_pgcache = iom_ctrl->iom_pgcache;
	cached = global_node_page_state(NR_FILE_PAGES) -
				global_node_page_state(NR_SHMEM) -
				total_swapcache_pages();
	iom_pgcache->cache_size += cached;
	iom_pgcache->cache_count++;
}

static unsigned int io_measure_is_commercial_user(void)
{
	unsigned int logusertype;
	unsigned int iom_usertype;

	logusertype = get_logusertype_flag();
	iom_pr_info("logusertype = %d\n", logusertype);

	if (logusertype == 0)
		logusertype = BETA_USER;

	if (logusertype == 0)
		iom_usertype = IOM_USER_INVAILD;
	else if ((logusertype == COMMERCIAL_USER) ||
			(logusertype == OVERSEA_COMMERCIAL_USER))
		iom_usertype = IOM_USER_COMMERCIAL;
	else
		iom_usertype = IOM_USER_NOT_COMMERCIAL;

	return iom_usertype;
}

static void io_measure_storage_exit(void)
{
	io_measure_pagecache_exit();
	io_measure_fs_exit();
	io_measure_block_exit();
	io_measure_scsi_exit();
	io_measure_reset_exit();
}

/*
 * @brief: Includes three modules: block, fs, pagecache.
 */
static int io_measure_storage_init(void)
{
	int ret;

	//block measure init
	ret = io_measure_block_init();
	if (ret != 0) {
		iom_pr_info("ERR: block init failed, ret=%d.\n", ret);
		goto err;
	}

	//fs measure init
	ret = io_measure_fs_init();
	if (ret != 0) {
		iom_pr_info("ERR: fs init failed, ret=%d.\n", ret);
		goto err;
	}

	//pagecache measure init
	ret = io_measure_pagecache_init();
	if (ret != 0) {
		iom_pr_info("ERR: pagecache init failed, ret=%d.\n", ret);
		goto err;
	}

	//scsi measure init
	ret = io_measure_scsi_init();
	if (ret != 0) {
		iom_pr_info("ERR: scsi init failed, ret=%d.\n", ret);
		goto err;
	}

	// reset init
	ret = io_measure_reset_init();
	if (ret != 0) {
		iom_pr_info("ERR: reset init failed, ret=%d.\n", ret);
		goto err;
	}
	return ret;

err:
	io_measure_storage_exit();
	return ret;
}

static void io_measure_storage_disable(void)
{
	io_measure_fs_unregister_tracepoints();
	io_measure_blk_unregister_tracepoints();
	io_measure_scsi_unregister_tracepoints();
}

static void io_measure_storage_enable(void)
{
	io_measure_reset();
	io_measure_blk_register_tracepoints();
	io_measure_fs_register_tracepoints();
	io_measure_scsi_register_tracepoints();
}

static int io_measure_enable_proc_show(struct seq_file *m, void *v)
{
	if (iom_ctrl == NULL)
		return -EINVAL;
	seq_printf(m, "%d\n", iom_ctrl->iom_enable);
	return 0;
}

static int io_measure_enable_proc_open(struct inode *inode, struct file *file)
{
	return single_open(file, io_measure_enable_proc_show, NULL);
}

static ssize_t io_measure_enable_proc_write(struct file *file,
	const char __user *buffer, size_t count, loff_t *ppos)
{
	bool enable;
	int rc;

	rc = kstrtobool_from_user(buffer, count, &enable);
	if (rc)
		return rc;

	if (iom_ctrl == NULL)
		return -EINVAL;

	mutex_lock(&iom_enable_lock);
	if (iom_ctrl->iom_enable == true && enable == false) {
		if (iom_ctrl->iom_init_stage != IOM_INIT_STAGE_END) {
			iom_pr_info("disable failed!\n");
			mutex_unlock(&iom_enable_lock);
			return -EBUSY;
		}

		cancel_delayed_work_sync(&iom_ctrl->iom_work);
		io_measure_storage_disable();
		iom_ctrl->iom_enable = false;
		iom_pr_info("disable success.\n");
	}
	if (iom_ctrl->iom_enable == false && enable == true) {
		if (iom_ctrl->iom_init_stage == IOM_INIT_STAGE_END)
			io_measure_storage_enable();

		if (iom_ctrl->iom_init_stage == IOM_INIT_STAGE1) {
			if (io_measure_storage_init()) {
				iom_pr_info("enable failed.\n");
				io_measure_storage_exit();
				mutex_unlock(&iom_enable_lock);
				return -EBUSY;
			}
		}

		iom_ctrl->iom_init_stage = IOM_INIT_STAGE2;
		if (iom_ctrl->iom_workqueue)
			queue_delayed_work(iom_ctrl->iom_workqueue, &iom_ctrl->iom_work,
			IOM_INIT_DELAY_TIME);
		iom_pr_info("enable success.\n");
	}
	mutex_unlock(&iom_enable_lock);
	return count;
}

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
static const struct proc_ops iom_enable_proc_fops = {
	.proc_open = io_measure_enable_proc_open,
	.proc_write = io_measure_enable_proc_write,
	.proc_read = seq_read,
	.proc_lseek = seq_lseek,
	.proc_release = single_release,
};
#else
static const struct file_operations iom_enable_proc_fops = {
	.open = io_measure_enable_proc_open,
	.write = io_measure_enable_proc_write,
	.read = seq_read,
	.llseek = seq_lseek,
	.release = single_release,
};
#endif


/*
 * @brief: init resource by queuework stage.
 * STAGE1: init resource only not commercial version
 * STAGE2: in next delay work, enable iomeasure stat, init complete.
 * STAGE3: delay work for other measure, such as pagecache size sampling.
 */
static void io_measure_delay_work(struct work_struct *work)
{
	unsigned int iom_usertype;
	unsigned long delay = IOM_INIT_DELAY_TIME;
	struct proc_dir_entry *proc_entry = NULL;
	int ret;

	if (iom_ctrl == NULL)
		return;

	switch (iom_ctrl->iom_init_stage) {
	case IOM_INIT_STAGE1:
		iom_usertype = io_measure_is_commercial_user();
		if (iom_usertype == IOM_USER_COMMERCIAL) {
			proc_entry = proc_create(USER_IOM_ENABLE, 0644, iom_ctrl->iom_proc_root,
				&iom_enable_proc_fops);
			if (proc_entry == NULL) {
				iom_pr_info("Create /proc/%s/%s fail.\n", USER_IOM_DIR, USER_IOM_ENABLE);
				return;
			}
			iom_ctrl->enable_node_exist = true;
			return;
		} else if (iom_usertype == IOM_USER_NOT_COMMERCIAL) {
			ret = io_measure_storage_init();
			if (ret)
				return;
			iom_ctrl->iom_init_stage = IOM_INIT_STAGE2;
		}
		break;
	case IOM_INIT_STAGE2:
		iom_ctrl->iom_enable = true;
		if (iom_ctrl->enable_node_exist == false) {
			proc_entry = proc_create(USER_IOM_ENABLE, 0644, iom_ctrl->iom_proc_root,
				&iom_enable_proc_fops);
			if (proc_entry == NULL) {
				iom_pr_info("Create /proc/%s/%s fail.\n", USER_IOM_DIR, USER_IOM_ENABLE);
				return;
			}
			iom_ctrl->enable_node_exist = true;
		}
		iom_ctrl->iom_init_stage = IOM_INIT_STAGE_END;
		break;
	case IOM_INIT_STAGE_END:
		io_measure_work_run();
		delay = IOM_RUN_DELAY_TIME;
		break;
	default:
		return;
	}

	queue_delayed_work(iom_ctrl->iom_workqueue, &iom_ctrl->iom_work, delay);
}

/*
 * @brief: init globle resource for io measure, it is root struct.
 * @param: void
 * @return: 0:init success; others: fail.
 */
static int io_measure_resource_init(void)
{
	iom_ctrl = kmalloc(sizeof(struct io_measure_ctrl), GFP_KERNEL);
	if (iom_ctrl == NULL)
		return -ENOMEM;

	memset(iom_ctrl, 0, sizeof(struct io_measure_ctrl));
	iom_ctrl->iom_enable = false;
	iom_ctrl->enable_node_exist = false;
	iom_ctrl->iom_init_stage = IOM_INIT_STAGE1;
	iom_ctrl->iom_proc_root = proc_mkdir(USER_IOM_DIR, NULL);
	if (iom_ctrl->iom_proc_root == NULL) {
		iom_pr_info("iomt proc mkdir failed.\n");
		return -ENOMEM;
	}

	INIT_DELAYED_WORK(&iom_ctrl->iom_work, io_measure_delay_work);
	iom_ctrl->iom_workqueue = create_workqueue("io_measure");
	if (iom_ctrl->iom_workqueue)
		queue_delayed_work(iom_ctrl->iom_workqueue,
		&iom_ctrl->iom_work, IOM_INIT_DELAY_TIME);

	return 0;
}

static void io_measure_resource_exit(void)
{
	if (iom_ctrl == NULL)
		return;

	if (iom_ctrl->iom_workqueue) {
		destroy_workqueue(iom_ctrl->iom_workqueue);
		iom_ctrl->iom_workqueue = NULL;
	}
	if (iom_ctrl->iom_proc_root) {
		remove_proc_entry(USER_IOM_ENABLE, iom_ctrl->iom_proc_root);
		remove_proc_entry(USER_IOM_DIR, NULL);
		iom_ctrl->iom_proc_root = NULL;
	}
	kfree(iom_ctrl);
	iom_ctrl = NULL;
}

static int __init io_measure_init(void)
{
	int ret;

	ret = io_measure_resource_init();
	if (ret == 0)
		iom_pr_info("init success.\n");
	else
		iom_pr_info("ERR: init failed, ret=%d.\n", ret);

	return ret;
}

static void __exit io_measure_exit(void)
{
	io_measure_storage_exit();
	io_measure_resource_exit();
	iom_pr_info("exit.\n");
}

late_initcall(io_measure_init);
module_exit(io_measure_exit);
