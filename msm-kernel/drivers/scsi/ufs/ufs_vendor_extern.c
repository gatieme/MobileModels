/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021. All rights reserved.
 * Description: ufs private driver interface
 * Author: zhangjinkai
 * Create: 2021-3-18
 */
#include "ufs_vendor_extern.h"
#include "ufs_vendor_cmd.h"
#include "ufs_vendor_mode.h"
#include "ufshcd.h"
#include <linux/version.h>
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
#include "ufshcd-add-info.h"
#endif

#ifdef CONFIG_HUAWEI_UFS_VENDOR_MODE
static bool send_queuecommand_directly(struct ufs_hba *hba, struct scsi_cmnd *cmd,
			struct ufshcd_lrb *lrbp, int tag)
{
	unsigned long flags;
	int err;

	WARN_ON(lrbp->cmd); /*lint !e146 !e665*/
	lrbp->cmd = cmd;
	lrbp->sense_bufflen = SCSI_SENSE_BUFFERSIZE;
	lrbp->sense_buffer = cmd->sense_buffer;
	lrbp->task_tag = tag;
	lrbp->lun = ufshcd_scsi_to_upiu_lun((unsigned int)cmd->device->lun);
	lrbp->intr_cmd = !ufshcd_is_intr_aggr_allowed(hba) ? true : false;
	lrbp->command_type = UTP_CMD_TYPE_SCSI;

	/* form UPIU before issuing the command */
	err = ufshcd_compose_upiu(hba, lrbp);
	if (err)
		return false;

	/* Black Magic, dont touch unless you want a BUG */
	lrbp->command_type = UTP_CMD_TYPE_DEV_MANAGE;
	err = ufshcd_map_sg(hba, lrbp);
	if (err)
		return false;

	/* Make sure descriptors are ready before ringing the doorbell */
	wmb();

#ifdef CONFIG_QCOM_SCSI_UFS_DUMP
	ufshcd_dump_scsi_command(hba, (unsigned int)tag);
#endif

#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
	spin_lock_irqsave(hba->host->host_lock, flags);
#endif
	/* issue command to the controller */
	ufshcd_send_command(hba, (unsigned int)tag);
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
	spin_unlock_irqrestore(hba->host->host_lock, flags);
#endif
	return true;
}

static int wait_command_complete(struct ufs_hba *hba,
			struct ufshcd_lrb *lrbp, unsigned int timeout)
{
	int err;
	unsigned long time_left;
	unsigned long flags;

	time_left = wait_for_completion_timeout(hba->dev_cmd.complete,
						msecs_to_jiffies(timeout));

	spin_lock_irqsave(hba->host->host_lock, flags);
	hba->dev_cmd.complete = NULL;
	spin_unlock_irqrestore(hba->host->host_lock, flags);

	if (likely(time_left)) {
		err = ufshcd_transfer_rsp_status(hba, lrbp);
	} else {
		err = -ETIMEDOUT;
		dev_err(hba->dev, "%s: scsi request timedout, tag %d\n",
			__func__, lrbp->task_tag);
		if (!ufshcd_clear_cmd(hba, lrbp->task_tag))
			err = -EAGAIN;
		ufshcd_outstanding_req_clear(hba, lrbp->task_tag);
	}
	return err;
}

/**
 * ufshcd_queuecommand_directly - API for sending scsi cmd directly, of course
 * skip error handler of scsi
 * @hba - UFS hba
 * @cmd - scsi_cmnd
 * @timeout - time in jiffies
 *
 * NOTE: We use device management tag and mutext lock, without this, we must
 * define a new wait, and complete it in scsi_done
 * Since there is only one available tag for device management commands,
 * it is expected you hold the hba->dev_cmd.lock mutex.
 * This function may sleep.
 */
int __ufshcd_queuecommand_directly(struct ufs_hba *hba,
					  struct scsi_cmnd *cmd,
					  unsigned int timeout)
{
	int err;
	int tag;
	unsigned long flags;
	struct ufshcd_lrb *lrbp = NULL;
	struct completion wait;

	init_completion(&wait);
	mutex_lock(&hba->dev_cmd.lock);
	hba->dev_cmd.complete = &wait;
	err = pm_runtime_get_sync(hba->dev);
	if (err < 0) {
		spin_lock_irqsave(hba->host->host_lock, flags);
		hba->dev_cmd.complete = NULL;
		spin_unlock_irqrestore(hba->host->host_lock,
				       flags);
		goto unlock;
	}
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
	wait_event(hba->dev_cmd.tag_wq,
		   ufshcd_get_dev_cmd_tag(hba, &tag));
#else
	tag = ufs_hba_add_info(hba)->reserved_slot;
	/* Protects use of ufs_hba_add_info(hba)->reserved_slot. */
	lockdep_assert_held(&hba->dev_cmd.lock);
#endif
	err = ufshcd_hold(hba, false);
	if (err) {
		err = SCSI_MLQUEUE_HOST_BUSY;
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
		clear_bit_unlock(tag, &hba->lrb_in_use);
#endif
		goto out;
	}

	lrbp = &hba->lrb[tag];
	if (!send_queuecommand_directly(hba, cmd, lrbp, tag))
		goto out;
	err = wait_command_complete(hba, lrbp, timeout);
out:
	lrbp->cmd = NULL;
	ufshcd_release(hba);
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
	ufshcd_put_dev_cmd_tag(hba, tag);
	wake_up(&hba->dev_cmd.tag_wq);
#endif
unlock:
	pm_runtime_put_sync(hba->dev);
	mutex_unlock(&hba->dev_cmd.lock);
	return err;
}

int ufshcd_queuecommand_directly(struct ufs_hba *hba, struct scsi_cmnd *cmd,
				 unsigned int timeout, bool eh_handle)
{
	int err = 1;
	int retry = 1;
	unsigned long flags;
	bool needs_flush = false;

start:
	spin_lock_irqsave(hba->host->host_lock, flags);
	if (hba->force_host_reset || hba->ufshcd_state == UFSHCD_STATE_RESET ||
	    hba->ufshcd_state == UFSHCD_STATE_EH_SCHEDULED_FATAL || hba->ufshcd_state == UFSHCD_STATE_EH_SCHEDULED_NON_FATAL)
		needs_flush = true;
	spin_unlock_irqrestore(hba->host->host_lock, flags);

	if (needs_flush)
		flush_work(&hba->eh_work);

	/* Assume flush work makes ufshcd works well, or return error */
	spin_lock_irqsave(hba->host->host_lock, flags);
	if (hba->ufshcd_state != UFSHCD_STATE_OPERATIONAL) {
		err = SCSI_MLQUEUE_HOST_BUSY;
		spin_unlock_irqrestore(hba->host->host_lock, flags);
		return err;
	}
	spin_unlock_irqrestore(hba->host->host_lock, flags);

	err = __ufshcd_queuecommand_directly(hba, cmd, timeout);
	if (err && eh_handle) {
		spin_lock_irqsave(hba->host->host_lock, flags);
		hba->force_host_reset = true;
		hba->ufshcd_state = UFSHCD_STATE_EH_SCHEDULED_FATAL;
		queue_work(hba->recovery_wq, &hba->eh_work);
		spin_unlock_irqrestore(hba->host->host_lock, flags);
		if (retry-- > 0)
			goto start;
	}

	return err;
}
#endif
