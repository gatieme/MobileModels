#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/bio.h>
#include <linux/blkdev.h>
#include <linux/gfp.h>
#include <linux/blk-mq.h>

#include "blk.h"
#include "blk-mq.h"

#include "hisi-blk-mq.h"
#include "hisi-blk-mq-dispatch-strategy.h"
#include "hisi-blk-mq-debug.h"

#define HISI_BLK_ASYNC_FLUSH_DELAY_MS	0U

static LIST_HEAD(all_flush_q_list);
static DEFINE_MUTEX(all_flush_q_mutex);/*lint !e651 !e708 !e64 !e785 !e570 */
void blk_flush_reduced_queue_register(struct request_queue *q)
{
	mutex_lock(&all_flush_q_mutex);
	list_add(&q->flush_queue_node, &all_flush_q_list);
	mutex_unlock(&all_flush_q_mutex);
}

void blk_flush_reduced_queue_unregister(struct request_queue *q)
{
	mutex_lock(&all_flush_q_mutex);
	list_del(&q->flush_queue_node);
	mutex_unlock(&all_flush_q_mutex);
}

static unsigned char blk_power_off_flush_executing = 0;
void blk_power_off_flush(int emergency)
{
	struct request_queue *q;
	if(blk_power_off_flush_executing)
		return;
	printk(KERN_EMERG "<%s> emergency = %d \r\n", __func__, emergency);
	blk_power_off_flush_executing = 1;
	list_for_each_entry(q, &all_flush_q_list, flush_queue_node){ /*lint !e64 !e826 */
		if(q && q->direct_flush && q->blk_part_tbl_exist){
			if(q->request_queue_disk)
				printk(KERN_EMERG "<%s> emergency flush on %s \r\n", __func__, q->request_queue_disk->disk_name);
			q->direct_flush(q,0);
		}
	}
	blk_power_off_flush_executing = 0;
}
EXPORT_SYMBOL_GPL(blk_power_off_flush);

static void blk_flush_work_fn(struct work_struct* work)
{
	struct request_queue *q = container_of(work, struct request_queue, flush_work.work);/*lint !e826*/
	struct block_device *bdev = bdget_disk(q->request_queue_disk, 0);
	if(bdev){
		int ret = blkdev_get(bdev, FMODE_WRITE, NULL);
		if(ret){
			printk(KERN_EMERG "<%s> blkdev_get fail! \r\n", __func__);
			goto exit;
		}
		ret = blkdev_issue_flush(bdev, GFP_KERNEL, NULL);
		if(ret)
			printk(KERN_EMERG "<%s> blkdev_issue_flush fail! \r\n", __func__);
		blkdev_put(bdev, FMODE_WRITE);
	}
exit:
	atomic_set(&q->flush_work_trigger, 0);
}

bool flush_sync_dispatch(struct request_queue *q, struct bio *bio)
{
	if((bio->bi_rw & REQ_FLUSH)&&(bio->bi_iter.bi_size == 0)){
		if(bio->bi_async_flush == 1 && q->blk_flush_reduce){
			if(atomic_read(&q->flush_work_trigger) == 0){/*lint !e529 !e438 */
				atomic_set(&q->flush_work_trigger, 1);
				kblockd_schedule_delayed_work(&q->flush_work,msecs_to_jiffies(HISI_BLK_ASYNC_FLUSH_DELAY_MS));
			}
			else if(kblockd_schedule_delayed_work_cancel(&q->flush_work)){
				kblockd_schedule_delayed_work(&q->flush_work,msecs_to_jiffies(HISI_BLK_ASYNC_FLUSH_DELAY_MS));
			}
			return false;
		}
	}
	return true;
}

void blk_queue_async_flush_init(struct request_queue *q)
{
	q->blk_flush_reduce = 0;
	q->direct_flush = NULL;
	INIT_DELAYED_WORK(&q->flush_work, blk_flush_work_fn);/*lint !e747 */
	atomic_set(&q->flush_work_trigger, 0);
}