#include <asm/compiler.h>
#include <linux/compiler.h>
#include <linux/fd.h>
#include <linux/tty.h>
#include <linux/fs.h>
#include <linux/fcntl.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <linux/syscalls.h>
#include <linux/device.h>
#include <linux/dma-mapping.h>
#include <linux/semaphore.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/types.h>
#include <linux/io.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_reserved_mem.h>
#include <linux/of_device.h>
#include <linux/of_platform.h>
#include <linux/delay.h>
#include <linux/timer.h>
#include <linux/atomic.h>
#include <linux/notifier.h>
#include <linux/printk.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/interrupt.h>
#include <linux/hisi/ipc_msg.h>
#include <linux/hisi/hisi_rproc.h>
#include <linux/hisi/kirin_partition.h>
#include <linux/clk.h>
#include <linux/mm.h>
#include "soc_acpu_baseaddr_interface.h"
#include "soc_sctrl_interface.h"
#include "hisi_hisee.h"
#include "hisi_hisee_fs.h"
#include "hisi_hisee_power.h"
#include "hisi_hisee_upgrade.h"
#include "hisi_hisee_chip_test.h"

/*
 * this module implements: manufacture function; slt test functions; channel test function
 */

/* part 1: manufacture function */
extern void release_hisee_semphore(void);

static int otp_image_upgrade_func(void *buf, int para)
{
	int ret;
	ret = write_hisee_otp_value(OTP_IMG_TYPE);
	check_and_print_result();
	set_errno_and_return(ret);
}/*lint !e715*/

static int write_rpmb_key_func (void *buf, int para)
{
	char *buff_virt = NULL;
	phys_addr_t buff_phy = 0;
	atf_message_header *p_message_header;
	int ret = HISEE_OK;
	int image_size = 0;

	buff_virt = (void *)dma_alloc_coherent(g_hisee_data.cma_device, SIZE_1K * 4,
											&buff_phy, GFP_KERNEL);
	if (buff_virt == NULL) {
		pr_err("%s(): dma_alloc_coherent failed\n", __func__);
		set_errno_and_return(HISEE_NO_RESOURCES);
	}
	memset(buff_virt, 0, SIZE_1K * 4);
	p_message_header = (atf_message_header *)buff_virt;
	set_message_header(p_message_header, CMD_WRITE_RPMB_KEY);
	image_size = HISEE_ATF_MESSAGE_HEADER_LEN;
	ret = send_smc_process(p_message_header, buff_phy, image_size,
							HISEE_ATF_WRITE_RPMBKEY_TIMEOUT, CMD_WRITE_RPMB_KEY);
	dma_free_coherent(g_hisee_data.cma_device, (unsigned long)(SIZE_1K * 4), buff_virt, buff_phy);
	check_and_print_result();
	set_errno_and_return(ret);
}/*lint !e715*/

static int set_sm_lcs_func(void *buf, int para)
{
	char *buff_virt = NULL;
	phys_addr_t buff_phy = 0;
	atf_message_header *p_message_header;
	int ret = HISEE_OK;
	int image_size;
	unsigned int result_offset;

	buff_virt = (void *)dma_alloc_coherent(g_hisee_data.cma_device, SIZE_1K * 4,
											&buff_phy, GFP_KERNEL);
	if (buff_virt == NULL) {
		pr_err("%s(): dma_alloc_coherent failed\n", __func__);
		set_errno_and_return(HISEE_NO_RESOURCES);
	}
	memset(buff_virt, 0, SIZE_1K * 4);
	p_message_header = (atf_message_header *)buff_virt;
	set_message_header(p_message_header, CMD_SET_LCS_SM);

	image_size = HISEE_ATF_MESSAGE_HEADER_LEN;
	result_offset = HISEE_ATF_MESSAGE_HEADER_LEN;
	p_message_header->test_result_phy = (unsigned int)buff_phy + result_offset;
	p_message_header->test_result_size = SIZE_1K * 4 - result_offset;
	ret = send_smc_process(p_message_header, buff_phy, (unsigned int)image_size,
							HISEE_ATF_GENERAL_TIMEOUT, CMD_SET_LCS_SM);
	if (HISEE_OK != ret) {
		pr_err("%s(): hisee reported fail code=%d\n", __func__, *((int *)(void *)(buff_virt + result_offset)));
	}

	dma_free_coherent(g_hisee_data.cma_device, (unsigned long)(SIZE_1K * 4), buff_virt, buff_phy);
	check_and_print_result();
	set_errno_and_return(ret);
}/*lint !e715*/

static int upgrade_one_file_func(char *filename, se_smc_cmd cmd)
{
	char *buff_virt;
	phys_addr_t buff_phy = 0;
	atf_message_header *p_message_header;
	int ret = HISEE_OK;
	int image_size = 0;

	buff_virt = (void *)dma_alloc_coherent(g_hisee_data.cma_device, HISEE_SHARE_BUFF_SIZE,
											&buff_phy, GFP_KERNEL);
	if (buff_virt == NULL) {
		pr_err("%s(): dma_alloc_coherent failed\n", __func__);
		set_errno_and_return(HISEE_NO_RESOURCES);
	}
	memset(buff_virt, 0, HISEE_SHARE_BUFF_SIZE);
	p_message_header = (atf_message_header *)buff_virt; /*lint !e826*/
	set_message_header(p_message_header, cmd);

	ret = hisee_read_file((const char *)filename, (buff_virt + HISEE_ATF_MESSAGE_HEADER_LEN), 0, 0);
	if (ret < HISEE_OK) {
		pr_err("%s(): hisee_read_file failed, filename=%s, ret=%d\n", __func__, filename, ret);
		dma_free_coherent(g_hisee_data.cma_device, (unsigned long)HISEE_SHARE_BUFF_SIZE, buff_virt, buff_phy);
		set_errno_and_return(ret);
	}
	image_size = (ret + HISEE_ATF_MESSAGE_HEADER_LEN);
	ret = send_smc_process(p_message_header, buff_phy, (unsigned int)image_size,
							HISEE_ATF_GENERAL_TIMEOUT, cmd);
	dma_free_coherent(g_hisee_data.cma_device, (unsigned long)HISEE_SHARE_BUFF_SIZE, buff_virt, buff_phy);
	check_and_print_result();
	set_errno_and_return(ret);
}

static int factory_apdu_test_func(void *buf, int para)
{
	int ret = HISEE_OK;
	ret = upgrade_one_file_func("/hisee_fs/test.apdu.bin", CMD_FACTORY_APDU_TEST);
	check_and_print_result();
	set_errno_and_return(ret);
}

int verify_key(void)
{
	char *buff_virt;
	phys_addr_t buff_phy = 0;
	atf_message_header *p_message_header;
	int ret = HISEE_OK;
	unsigned int image_size;

	buff_virt = (void *)dma_alloc_coherent(g_hisee_data.cma_device, (unsigned long)SIZE_1K * 4,
											&buff_phy, GFP_KERNEL);
	if (buff_virt == NULL) {
		pr_err("%s(): dma_alloc_coherent failed\n", __func__);
		set_errno_and_return(HISEE_NO_RESOURCES);
	}
	memset(buff_virt, 0, (unsigned long)SIZE_1K * 4);
	p_message_header = (atf_message_header *)buff_virt;  /*lint !e826*/
	set_message_header(p_message_header, CMD_HISEE_VERIFY_KEY);
	image_size = HISEE_ATF_MESSAGE_HEADER_LEN;
	ret = send_smc_process(p_message_header, buff_phy, image_size,
							HISEE_ATF_GENERAL_TIMEOUT, CMD_HISEE_VERIFY_KEY);
	dma_free_coherent(g_hisee_data.cma_device, (unsigned long)(SIZE_1K * 4), buff_virt, buff_phy);
	check_and_print_result();
	set_errno_and_return(ret);
}

static int g_hisee_debug_flag = 0;
void hisee_debug(void)
{
}

static int hisee_total_manafacture_func(void *buf, int para)
{
	int ret1, ret = HISEE_OK;
	unsigned int hisee_lcs_mode = 0;
	int write_rpmbkey_try = 5;
	cosimage_version_info misc_version;
	/*unsigned char apdu_key_cmd0[21] = {	0xF0, 0x10, 0x00, 0x00, \
								0x10, 0x01, 0x23, 0x45, \
								0x67, 0x89, 0xab, 0xcd, \
								0xef, 0xfe, 0xdc, 0xba, \
								0x98, 0x76, 0x54, 0x32, \
								0x10};
	unsigned char apdu_key_cmd1[5] = {0xF0,0xd8, 0x00,0x00,0x00};
	unsigned char apdu_key_cmd2[5] = {0x00, 0xa4, 0x04, 0x00, 0x00};
	unsigned char apdu_key_cmd3[12] = {0x80, 0xe4, 0x00, 0x80,0x07, \
									  0x4f, 0x05, 0x12, 0x34, 0x56, \
									  0x78, 0x90};*/

	ret = get_hisee_lcs_mode(&hisee_lcs_mode);
	if (HISEE_OK != ret) {
		pr_err("%s() get_hisee_lcs_mode failed,ret=%d\n", __func__, ret);
		set_errno_and_return(ret);
	}
write_rpmbkey_retry_process:
	ret = hisee_poweroff_func(NULL, HISEE_PWROFF_LOCK);
	if (HISEE_OK != ret) {
		pr_err("%s() hisee_poweroff_func 1 failed,ret=%d\n", __func__, ret);
		set_errno_and_return(ret);
	}
	if (HISEE_DM_MODE_MAGIC == hisee_lcs_mode) {
		ret = hisee_poweron_upgrade_func(NULL, 0);
	} else {
		ret = hisee_poweron_upgrade_func(NULL, HISEE_POWER_ON_UPGRADE_SM);
	}
	if (HISEE_OK != ret) {
		pr_err("%s() poweron upgrade failed,ret=%d\n", __func__, ret);
		set_errno_and_return(ret);
	}

	hisee_mdelay(200); /*lint !e744 !e747 !e748*/
	if (HISEE_DM_MODE_MAGIC == hisee_lcs_mode) {
		ret = write_rpmb_key_func(NULL, 0);
		if (HISEE_OK != ret) {
			write_rpmbkey_try--;
			if (0 == write_rpmbkey_try) {
				pr_err("%s() write_rpmb_key_func failed,ret=%d\n", __func__, ret);
				goto err_process;
			}
			goto write_rpmbkey_retry_process;
		}
	}

	hisee_mdelay(DELAY_BETWEEN_STEPS); /*lint !e744 !e747 !e748*/
	ret = cos_image_upgrade_func(NULL, HISEE_FACTORY_TEST_VERSION);
	if (HISEE_OK != ret) {
		pr_err("%s() cos_image_upgrade_func failed,ret=%d\n", __func__, ret);
		goto err_process;
	}

	if (HISEE_DM_MODE_MAGIC == hisee_lcs_mode) {
		hisee_mdelay(DELAY_BETWEEN_STEPS); /*lint !e744 !e747 !e748*/
		ret = hisee_poweron_booting_func(NULL, 0);
		if (HISEE_OK != ret) {
			pr_err("%s() poweron booting failed,ret=%d\n", __func__, ret);
			set_errno_and_return(ret);
		}
		wait_hisee_ready(HISEE_STATE_MISC_READY, 30000);

		ret = otp_image_upgrade_func(NULL, 0);
		if (HISEE_OK != ret) {
			pr_err("%s() otp_image_upgrade_func failed,ret=%d\n", __func__, ret);
			goto err_process;
		}

		hisee_mdelay(DELAY_BETWEEN_STEPS); /*lint !e744 !e747 !e748*/

		ret = misc_image_upgrade_func(NULL, 0);
		if (HISEE_OK != ret) {
			pr_err("%s() misc_image_upgrade_func failed,ret=%d\n", __func__, ret);
			return ret;
		}

		wait_hisee_ready(HISEE_STATE_COS_READY, 30000);

		/* verify key */
		ret = verify_key();
		if (HISEE_OK != ret) {
			pr_err("%s() verify_key failed,ret=%d\n", __func__, ret);
			goto err_process;
		}

		 /* write current misc version into record area */
		if (g_misc_version) {
			misc_version.magic = HISEE_SW_VERSION_MAGIC_VALUE;
			misc_version.img_version_num = g_misc_version;
			access_hisee_image_partition((char *)&misc_version, MISC_VERSION_WRITE_TYPE);
		}
	}else {
		ret = hisee_misc_process();
		if (HISEE_OK != ret) {
			pr_err("%s() hisee_misc_process failed,ret=%d\n", __func__, ret);
			goto err_process;
		}
	}
	/* cos should be ready now */

	ret = factory_apdu_test_func(NULL, 0);
	if (HISEE_OK != ret) {
		pr_err("%s() factory_apdu_test_func failed,ret=%d\n", __func__, ret);
		goto err_process;
	}

	/* send command to delete test applet */
	ret = send_apdu_cmd(HISEE_DEL_TEST_APPLET);
	if (HISEE_OK != ret) {
		pr_err("%s() send_apdu_cmd failed,ret=%d\n", __func__, ret);
		goto err_process;
	}

	if (HISEE_DM_MODE_MAGIC == hisee_lcs_mode) {
		if (g_hisee_debug_flag == 0) {

			ret = set_sm_lcs_func(NULL, 0);
			if (HISEE_OK != ret) {
				pr_err("%s() set_sm_lcs_func failed,ret=%d\n", __func__, ret);
				goto err_process;
			}

			hisee_mdelay(DELAY_BETWEEN_STEPS); /*lint !e744 !e747 !e748*/
			ret = set_hisee_lcs_sm_flg();
			if (HISEE_OK != ret) {
				pr_err("%s() set_hisee_lcs_sm_flg failed,ret=%d\n", __func__, ret);
				set_errno_and_return(ret);
				BUG_ON(1);
			}
		}
	}
	pr_err("%s() success!\n", __func__);
	ret = HISEE_OK;

err_process:
	ret1 = hisee_poweroff_func(NULL, HISEE_PWROFF_LOCK);
	if (HISEE_OK != ret1) {
		pr_err("%s() hisee poweroff entry failed,ret=%d\n", __func__, ret1);
		ret = ret1;
	}
	hisee_mdelay(DELAY_BETWEEN_STEPS);
	if (HISEE_OK == ret)
		release_hisee_semphore();

	set_errno_and_return(ret);
}

static int factory_test_body(void *arg)
{
	int ret;

	if (g_hisee_data.factory_test_state != HISEE_FACTORY_TEST_RUNNING) {
		pr_err("%s BUG_ON\n", __func__);
		BUG_ON(1);
	}
	ret = hisee_total_manafacture_func(NULL, 0);
	if (HISEE_OK != ret)
		g_hisee_data.factory_test_state = HISEE_FACTORY_TEST_FAIL;
	else
		g_hisee_data.factory_test_state = HISEE_FACTORY_TEST_SUCCESS;

	check_and_print_result();
	set_errno_and_return(ret);
} /*lint !e715*/

int hisee_parallel_manafacture_func(void *buf, int para)
{
	int ret = HISEE_OK;
	struct task_struct *factory_test_task = NULL;

	if (HISEE_FACTORY_TEST_RUNNING != g_hisee_data.factory_test_state) {
		g_hisee_data.factory_test_state = HISEE_FACTORY_TEST_RUNNING;
		factory_test_task = kthread_run(factory_test_body, NULL, "factory_test_body");
		if (!factory_test_task) {
			ret = HISEE_THREAD_CREATE_ERROR;
			g_hisee_data.factory_test_state = HISEE_FACTORY_TEST_FAIL;
			pr_err("hisee err create factory_test_task failed\n");
		}
	}
	set_errno_and_return(ret);
}/*lint !e715*/


/* part 2: slt test functions */


/* part 3: channel test function */

int hisee_channel_test_func(void *buf, int para)
{
	int ret = HISEE_OK;
	check_and_print_result();
	set_errno_and_return(ret);
}/*lint !e715*/
