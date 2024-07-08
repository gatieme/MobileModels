#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/bio.h>
#include <linux/blkdev.h>
#include <linux/gfp.h>
#include "blk.h"
#include <linux/fs.h>
#include <linux/file.h>
#include <linux/uaccess.h>
#include <linux/syscalls.h>
#include <linux/suspend.h>
#include <linux/hisi/rdr_hisi_platform.h>

extern void hisi_mntn_test_enable(int enable);
extern int hisi_wdt_tst_lock(int type);
extern void rdr_syserr_process_for_ap(u32 modid, u64 arg1, u64 arg2);
extern void rdr_system_error(u32 modid, u32 arg1, u32 arg2);

static unsigned int blk_apd_test_modid_case_2_6_map(int case_id)
{
	unsigned int modid = MODID_AP_S_PANIC;
	switch(case_id){
		case 2:
			printk(KERN_EMERG "MQ-APD:MODID_AP_S_NOC \r\n");
			modid = MODID_AP_S_NOC;
			break;
		case 3:
			printk(KERN_EMERG "MQ-APD:MODID_AP_S_PMU \r\n");
			modid = MODID_AP_S_PMU;
			break;
		case 4:
			printk(KERN_EMERG "MQ-APD:MODID_AP_S_DDRC_SEC \r\n");
			modid = MODID_AP_S_DDRC_SEC;
			break;
		case 5:
			printk(KERN_EMERG "MQ-APD:MODID_AP_S_COMBINATIONKEY \r\n");
			modid = MODID_AP_S_COMBINATIONKEY;
			break;
		case 6:
			printk(KERN_EMERG "MQ-APD:MODID_AP_S_F2FS \r\n");
			modid = MODID_AP_S_F2FS;
			break;
		default:
			printk(KERN_EMERG "MQ-APD:WRONG CASE ID \r\n");
			break;
	}
	return modid;
}

static unsigned int blk_apd_test_modid_case_7_11_map(int case_id)
{
	unsigned int modid = MODID_AP_S_PANIC;
	switch(case_id){
		case 7:
			printk(KERN_EMERG "MQ-APD:MODID_AP_S_BL31_PANIC \r\n");
			modid = MODID_AP_S_BL31_PANIC;
			break;
		case 8:
			printk(KERN_EMERG "MQ-APD:MODID_AP_S_RESUME_SLOWY \r\n");
			modid = MODID_AP_S_RESUME_SLOWY;
			break;
		case 9:
			printk(KERN_EMERG "MQ-APD:RDR_MODEM_NOC_MOD_ID \r\n");
			modid = RDR_MODEM_NOC_MOD_ID;
			break;
		case 10:
			printk(KERN_EMERG "MQ-APD:RDR_MODEM_DMSS_MOD_ID \r\n");
			modid = RDR_MODEM_DMSS_MOD_ID;
			break;
		case 11:
			printk(KERN_EMERG "MQ-APD:RDR_AUDIO_NOC_MODID \r\n");
			modid = RDR_AUDIO_NOC_MODID;
			break;
		default:
			printk(KERN_EMERG "MQ-APD:WRONG CASE ID \r\n");
			break;
	}
	return modid;
}


static unsigned int blk_apd_test_modid_case_map(int case_id)
{
	unsigned int modid = MODID_AP_S_PANIC;
	if(case_id < 7)
		modid = blk_apd_test_modid_case_2_6_map(case_id);
	else
		modid = blk_apd_test_modid_case_7_11_map(case_id);
	return modid;
}

int blk_apd_test(int case_id,int mode,int type)
{
	unsigned long irqflags = 0;
	unsigned char disable_intr_ctx = 0;
	unsigned char disable_preempt_ctx = 0;
	unsigned int modid;
	switch(mode){
		case 1:{
			printk(KERN_EMERG "MQ-APD:Disable interrupt \r\n");
			disable_intr_ctx = 1;
			break;
		}
		case 2:{
			printk(KERN_EMERG "MQ-APD:Disable preempt \r\n");
			disable_preempt_ctx = 1;
			break;
		}
		default:
			break;
	}
	if(disable_intr_ctx)
		local_irq_save(irqflags);/*lint !e730 !e550*/
	if(disable_preempt_ctx)
		preempt_disable();
	switch(case_id){
		case 0:
			blk_power_off_flush(0);
			goto out;
		case 1:
			printk(KERN_EMERG "MQ-APD:MODID_AP_S_PANIC \r\n");
			BUG_ON(1);/*lint !e730 */
			goto out;
		case 12:
			printk(KERN_EMERG "MQ-APD:WDT timeout simulate \r\n");
			hisi_mntn_test_enable(1);
			hisi_wdt_tst_lock(0);
			goto out;
		default:
			modid = blk_apd_test_modid_case_map(case_id);
	}
	if(type == 0)
		rdr_syserr_process_for_ap(modid, 0UL, 0UL);
	else if(type == 1)
		rdr_system_error(modid, 0U, 0U);
out:
	if(disable_intr_ctx)
		local_irq_restore(irqflags);/*lint !e730 !e550*/
	if(disable_preempt_ctx)
		preempt_enable();/*lint !e730 */
	return 0;
}

int blk_mq_apd_test(int case_id,int mode,int type)
{
	printk(KERN_EMERG "blk_mq_apd_test case_id = %d mode = %d type = %d\r\n",case_id,mode,type);
	if(case_id==13)
		case_id=1;
	blk_apd_test(case_id,mode,type);
	return 1;
}

struct delayed_work bg_io_test_work;
int bg_io_test_io_case_id;
char* bg_io_test_buf = NULL;
#define BG_IO_TEST_BUF_LEN (1024UL*1024UL)
atomic_t bg_io_test_work_state;
unsigned char first_run = 0;
int emergency_flush_test_case_id;
int emergency_flush_test_mode;
int emergency_flush_test_type;

static void blk_run_sr_test_work(struct work_struct *work)
{
	unsigned long interval_for_next_test = 0;
	long fd;
	long ret = 0;
	mm_segment_t oldfs = get_fs();
	if(work == NULL || atomic_read(&bg_io_test_work_state) ==0)/*lint !e529 !e438 */
		return;
	switch(bg_io_test_io_case_id){
		case 1:{
			set_fs(get_ds());/*lint !e501 */
			fd = sys_open("/data/blk_sr_test_file", (O_RDWR | O_CREAT | O_DIRECT),(S_IRWXU | S_IRWXG | S_IRWXO));/*lint !e712 */
			if (fd < 0){
				printk(KERN_EMERG "<%s> sys_open fail!! fd=%ld \r\n", __func__,fd);
				goto restore_fs;
			}
			ret = sys_write((unsigned int)fd, bg_io_test_buf, BG_IO_TEST_BUF_LEN);
			if (ret == -1){
				printk(KERN_EMERG "<%s> sys_write fail!! \r\n", __func__);
				goto close_file;
			}
			ret = sys_fsync((unsigned int)fd);
			if (ret < 0) {
				printk(KERN_EMERG "<%s> sys_fsync fail!! \r\n", __func__);
				goto close_file;
			}
			printk(KERN_EMERG "<%s> success!! \r\n", __func__);
		close_file:
			sys_close((unsigned int)fd);
		restore_fs:
			set_fs(oldfs);
			interval_for_next_test = 2UL;
			break;
		}
		case 2:{
			blk_apd_test(emergency_flush_test_case_id,emergency_flush_test_mode,emergency_flush_test_type);
			interval_for_next_test = 10UL;
			break;
		}
		default:
			printk(KERN_EMERG "MQ-APD:WRONG CASE ID \r\n");
			break;
	}
	if(atomic_read(&bg_io_test_work_state) ==0)/*lint !e529 !e438 */
		return;
	kblockd_schedule_delayed_work(&bg_io_test_work, interval_for_next_test);
}

static int blk_sr_tst_start(void)
{
	if(atomic_read(&bg_io_test_work_state)==0){/*lint !e529 !e438 */
		if(bg_io_test_io_case_id == 1){
			unsigned long i;
			char j=0;
			for(i=0;i<BG_IO_TEST_BUF_LEN;i++,j++)
				bg_io_test_buf[i] = j;
		}
		kblockd_schedule_delayed_work(&bg_io_test_work, 0UL);
		atomic_set(&bg_io_test_work_state, 1);
		printk(KERN_EMERG "<%s> success!! \r\n", __func__);
	}
	return 1;
}

static int  blk_sr_tst_end(void)
{
	atomic_set(&bg_io_test_work_state, 0);
	cancel_delayed_work_sync(&bg_io_test_work);
	printk(KERN_EMERG "<%s> success!! \r\n", __func__);
	return 1;
}

static int blk_sr_tst_suspend_notifier(struct notifier_block *nb,	unsigned long event,void *dummy)
{
	switch (event) {
	case PM_SUSPEND_PREPARE:
		printk(KERN_EMERG "<%s> PM_SUSPEND_PREPARE \r\n", __func__);
		blk_sr_tst_start();
		break;
	case PM_POST_SUSPEND:
		printk(KERN_EMERG "<%s> PM_POST_SUSPEND \r\n", __func__);
		blk_sr_tst_end();
		break;
	default:
		break;
	}
	if(nb == NULL || dummy)
		printk(KERN_EMERG "<%s> nb is empty or dummy not empty \r\n", __func__);
	return 0;
}

static struct notifier_block blk_bg_io_notif_block;

static void blk_sr_tst_config(void)
{
	if(first_run == 0){
		first_run = 1;
		INIT_DELAYED_WORK(&bg_io_test_work, blk_run_sr_test_work);/*lint !e747 */
		blk_bg_io_notif_block.notifier_call = blk_sr_tst_suspend_notifier;
	}
	atomic_set(&bg_io_test_work_state, 0);
	register_pm_notifier(&blk_bg_io_notif_block);
}

int blk_sr_bg_io_test_start(void)
{
	bg_io_test_io_case_id = 1;
	bg_io_test_buf = vmalloc(BG_IO_TEST_BUF_LEN);
	blk_sr_tst_config();
	return 1;
}

int blk_sr_flush_test_start(int case_id,int mode,int type)
{
	bg_io_test_io_case_id = 2;
	emergency_flush_test_case_id = case_id;
	emergency_flush_test_mode = mode;
	emergency_flush_test_type = type;
	blk_sr_tst_config();
	return 1;
}

int blk_sr_tst_stop(void)
{
	unregister_pm_notifier(&blk_bg_io_notif_block);
	if(bg_io_test_io_case_id==1)
		vfree(bg_io_test_buf);
	bg_io_test_io_case_id = 0;
	return 1;
}
