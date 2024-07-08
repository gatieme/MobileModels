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
#include "hisi_hisee_chip_test.h"
#include "hisi_hisee_upgrade.h"

static int check_sw_version_null(const cosimage_version_info *info)
{
	if (!info->magic && !info->img_version_num &&
		!info->img_timestamp.timestamp.year && !info->img_timestamp.timestamp.month
		&& !info->img_timestamp.timestamp.day && !info->img_timestamp.timestamp.hour
		&& !info->img_timestamp.timestamp.minute && !info->img_timestamp.timestamp.second)
		return 1;
	else
		return 0;
}

static int check_timestamp_valid(const cosimage_version_info *info)
{
	if (info->img_timestamp.timestamp.year < 2016)
		return 0;

	/*the year of deadline is 2050? I Don't konw! */
	if (info->img_timestamp.timestamp.year >= 2050)
		return 0;

	if (info->img_timestamp.timestamp.month > 12)
		return 0;

	/*the judge is not accurate, because not all month has 31 day,
	  depend on the value of year and month*/
	if (info->img_timestamp.timestamp.day > 31)
		return 0;

	if (info->img_timestamp.timestamp.hour >= 24)
		return 0;

	if (info->img_timestamp.timestamp.minute >= 60)
		return 0;

	if (info->img_timestamp.timestamp.second >= 60)
		return 0;

	return 1;
}

static void parse_timestamp(const char *timestamp_str, cosimage_version_info *info)
{
	unsigned short value_short;
	unsigned char  value_char;

	info->img_timestamp.value = 0x0;

	value_short = (timestamp_str[0] - 0x30) * 1000 + (timestamp_str[1] - 0x30) * 100
			+ (timestamp_str[2] - 0x30) * 10 + (timestamp_str[3] - 0x30); /*lint !e734*/
	info->img_timestamp.timestamp.year = value_short;

	value_char = (timestamp_str[5] - 0x30) * 10 + (timestamp_str[6] - 0x30); /*lint !e734*/
	info->img_timestamp.timestamp.month = value_char;

	value_char = (timestamp_str[8] - 0x30) * 10 + (timestamp_str[9] - 0x30); /*lint !e734*/
	info->img_timestamp.timestamp.day = value_char;

	value_char = (timestamp_str[11] - 0x30) * 10 + (timestamp_str[12] - 0x30); /*lint !e734*/
	info->img_timestamp.timestamp.hour = value_char;

	value_char = (timestamp_str[14] - 0x30) * 10 + (timestamp_str[15] - 0x30); /*lint !e734*/
	info->img_timestamp.timestamp.minute = value_char;

	value_char = (timestamp_str[17] - 0x30) * 10 + (timestamp_str[18] - 0x30); /*lint !e734*/
	info->img_timestamp.timestamp.second = value_char;

	return;
}

static int exist_newest_cosimage(const cosimage_version_info *curr_ptr, const cosimage_version_info *previous_ptr)
{
	if (!check_timestamp_valid(curr_ptr))
		return 0;
	if (!check_timestamp_valid(previous_ptr))
		return 0;

	if (HISEE_SW_VERSION_MAGIC_VALUE != curr_ptr->magic
		|| HISEE_SW_VERSION_MAGIC_VALUE != previous_ptr->magic)
		return 0;

	if (curr_ptr->img_version_num > previous_ptr->img_version_num)
		return 1;
	else if (curr_ptr->img_version_num < previous_ptr->img_version_num)
		return 0;
	else {
		if (curr_ptr->img_timestamp.value > previous_ptr->img_timestamp.value)
			return 1;
		else if (curr_ptr->img_timestamp.value <= previous_ptr->img_timestamp.value)
			return 0;
	}
	return 0;
}

static void check_misc_version(void)
{
	cosimage_version_info cos_version, misc_version;
	unsigned char v_first_info[] = {0x5a, 0x5a, 0xa5, 0xa5, 0x00, 0x00, 0x00, 0x00,
						 0x1c, 0x38, 0x15, 0x0c, 0x09, 0x00, 0xe0 ,0x07};

	/* get current misc version from record area */
	access_hisee_image_partition((char *)&misc_version, MISC_VERSION_READ_TYPE);
	pr_err("%s(): magic=%x,version=%x\n", __func__, misc_version.magic, misc_version.img_version_num);

	if (HISEE_SW_VERSION_MAGIC_VALUE == misc_version.magic) {
		/* compare misc version */
		if (g_misc_version <= misc_version.img_version_num) {
			pr_err("%s(): magic is valid,misc version is old\n", __func__);
			g_hisee_data.hisee_img_head.misc_image_cnt = 0;
		}
	} else {
		/* get current cos version from record area */
		access_hisee_image_partition((char *)&cos_version, SW_VERSION_READ_TYPE);
		if (0 == memcmp((char *)&cos_version, (char *)v_first_info, sizeof(cosimage_version_info))) {
			if (HISEE_MISC_VERSION0 == g_misc_version) {
				pr_err("%s(): magic is invalid,misc version is old\n", __func__);
				g_hisee_data.hisee_img_head.misc_image_cnt = 0;
				/* write current misc version into record area */
				misc_version.magic = HISEE_SW_VERSION_MAGIC_VALUE;
				misc_version.img_version_num = g_misc_version;
				access_hisee_image_partition((char *)&misc_version, MISC_VERSION_WRITE_TYPE);
			}
		}
	}
}

static int check_new_cosimage(int *is_new_cosimage)
{
	hisee_img_header *p_img_header;
	cosimage_version_info curr = {0};
	cosimage_version_info previous = {0};
	int ret;

	if (NULL == is_new_cosimage) {
		pr_err("%s buf paramters is null\n", __func__);
		set_errno_and_return(HISEE_INVALID_PARAMS);
	}

	if (!g_hisee_data.img_header_is_parse) {
		ret = hisee_parse_img_header((char *)&(g_hisee_data.hisee_img_head));
		if (HISEE_OK != ret) {
			pr_err("%s():hisee_parse_img_header failed, ret=%d\n", __func__, ret);
			set_errno_and_return(ret);
		}
		check_misc_version();
		g_hisee_data.img_header_is_parse = 1;
	}
	p_img_header = &(g_hisee_data.hisee_img_head);
	parse_timestamp(p_img_header->time_stamp, &curr);
	curr.img_version_num = p_img_header->sw_version_cnt;
	curr.magic = HISEE_SW_VERSION_MAGIC_VALUE;

	ret = access_hisee_image_partition((char *)&previous, SW_VERSION_READ_TYPE);
	if (HISEE_OK != ret) {
		pr_err("%s access_hisee_image_partition fail,ret=%d\n", __func__, ret);
		return ret;
	}
	if (check_sw_version_null(&previous))
		*is_new_cosimage = 1;
	else
		*is_new_cosimage = exist_newest_cosimage(&curr, &previous);
	return HISEE_OK;
}

int misc_image_upgrade_func(void *buf, int para)
{
	char *buff_virt;
	phys_addr_t buff_phy = 0;
	atf_message_header *p_message_header;
	int ret = HISEE_OK;
	int image_size;
	hisee_img_file_type type = MISC0_IMG_TYPE;
	unsigned int misc_image_cnt = 1;
	unsigned int result_offset;

	buff_virt = (void *)dma_alloc_coherent(g_hisee_data.cma_device, HISEE_SHARE_BUFF_SIZE,
											&buff_phy, GFP_KERNEL);
	if (buff_virt == NULL) {
		pr_err("%s(): dma_alloc_coherent failed\n", __func__);
		set_errno_and_return(HISEE_NO_RESOURCES);
	}

do_loop:
	memset(buff_virt, 0, HISEE_SHARE_BUFF_SIZE);
	p_message_header = (atf_message_header *)buff_virt;
	set_message_header(p_message_header, CMD_UPGRADE_MISC);
	ret = filesys_hisee_read_image(type, (buff_virt + HISEE_ATF_MESSAGE_HEADER_LEN));
	if (ret < HISEE_OK) {
		pr_err("%s(): filesys_hisee_read_image failed, ret=%d\n", __func__, ret);
		dma_free_coherent(g_hisee_data.cma_device, (unsigned long)HISEE_SHARE_BUFF_SIZE, buff_virt, buff_phy);
		set_errno_and_return(ret);
	}

	image_size = (ret + HISEE_ATF_MESSAGE_HEADER_LEN);
	result_offset = (u32)(image_size + SMC_TEST_RESULT_SIZE - 1) & (~(u32)(SMC_TEST_RESULT_SIZE -1));
	if (result_offset + SMC_TEST_RESULT_SIZE <= HISEE_SHARE_BUFF_SIZE) {
		p_message_header->test_result_phy = (unsigned int)buff_phy + result_offset;
		p_message_header->test_result_size = (unsigned int)SMC_TEST_RESULT_SIZE;
	}
	ret = send_smc_process(p_message_header, buff_phy, image_size,
							HISEE_ATF_MISC_TIMEOUT, CMD_UPGRADE_MISC);
	if (HISEE_OK != ret) {
		pr_err("%s(): send_smc_process failed, ret=%d\n", __func__, ret);
		if (result_offset + SMC_TEST_RESULT_SIZE <= HISEE_SHARE_BUFF_SIZE) {
			pr_err("%s(): hisee reported fail code=%d\n", __func__, *((int *)(void *)(buff_virt + result_offset)));
		}
		dma_free_coherent(g_hisee_data.cma_device, (unsigned long)HISEE_SHARE_BUFF_SIZE, buff_virt, buff_phy);
		set_errno_and_return(ret);
	}
	if (type == MISC0_IMG_TYPE)
		misc_image_cnt = g_hisee_data.hisee_img_head.misc_image_cnt;
	if ((--misc_image_cnt) > 0) {
		type++;
		goto do_loop;
	}

	dma_free_coherent(g_hisee_data.cma_device, (unsigned long)HISEE_SHARE_BUFF_SIZE, buff_virt, buff_phy);
	check_and_print_result();
	set_errno_and_return(ret);
}/*lint !e715*/

int hisee_misc_process(void)
{
	cosimage_version_info misc_version;
	int ret = HISEE_OK;

	if (0 == g_hisee_data.hisee_img_head.misc_image_cnt) {
		return ret;
	}
	/* check misc version */

	ret = hisee_poweroff_func(NULL, HISEE_PWROFF_LOCK);
	if (HISEE_OK != ret) {
		pr_err("%s()  hisee poweroff failed,ret=%d\n", __func__, ret);
		return ret;
	}
	hisee_mdelay(DELAY_BETWEEN_STEPS); /*lint !e744 !e747 !e748*/
	ret = hisee_poweron_booting_func(NULL, HISEE_POWER_ON_BOOTING_MISC);
	if (HISEE_OK != ret) {
		pr_err("%s()  hisee poweron booting failed,ret=%d\n", __func__, ret);
		return ret;
	}

	wait_hisee_ready(HISEE_STATE_MISC_READY, 30000);

	ret = misc_image_upgrade_func(NULL, 0);
	if (HISEE_OK != ret) {
		pr_err("%s() misc_image_upgrade_func failed,ret=%d\n", __func__, ret);
		return ret;
	}

	wait_hisee_ready(HISEE_STATE_COS_READY, 3000);

	/* verify key */
	ret = verify_key();
	if (HISEE_OK != ret) {
		pr_err("%s() verify_key failed,ret=%d\n", __func__, ret);
		return ret;
	}

	/* write current misc version into record area */
	if (g_misc_version) {
		misc_version.magic = HISEE_SW_VERSION_MAGIC_VALUE;
		misc_version.img_version_num = g_misc_version;
		access_hisee_image_partition((char *)&misc_version, MISC_VERSION_WRITE_TYPE);
	}

	return ret;
}

int cos_image_upgrade_func(void *buf, int para)
{
	char *buff_virt;
	phys_addr_t buff_phy = 0;
	atf_message_header *p_message_header;
	cosimage_version_info curr = {0};
	int ret;
	int image_size;
	int new_cos_exist = 0;
	unsigned int upgrade_run_flg;
	int retry = 2; /* retry 2 more times if failed */
	int ret_tmp;
	/*unsigned int hisee_lcs_mode = 0;*/

	/* hisee factory test(include slt test) don't check there is new cos image */
	if ((int)HISEE_FACTORY_TEST_VERSION != para) {
		ret = check_new_cosimage(&new_cos_exist);
		if (HISEE_OK == ret) {
			if (!new_cos_exist) {
				pr_err("%s(): there is no new cosimage\n", __func__);
				goto upgrade_bypass;
			}
		} else {
			pr_err("%s(): check_new_cosimage failed,ret=%d\n", __func__, ret);
			ret = HISEE_OLD_COS_IMAGE_ERROR;
			goto upgrade_bypass;
		}
	}

	upgrade_run_flg = HISEE_COS_UPGRADE_RUNNING_FLG;
	access_hisee_image_partition((char *)&upgrade_run_flg, COS_UPGRADE_RUN_WRITE_TYPE);

upgrade_retry:
	buff_virt = (void *)dma_alloc_coherent(g_hisee_data.cma_device, HISEE_SHARE_BUFF_SIZE,
											&buff_phy, GFP_KERNEL);
	if (buff_virt == NULL) {
		pr_err("%s(): dma_alloc_coherent failed\n", __func__);
		ret = HISEE_NO_RESOURCES;
		goto upgrade_exit;
	}

	memset(buff_virt, 0, HISEE_SHARE_BUFF_SIZE);
	p_message_header = (atf_message_header *)buff_virt;
	set_message_header(p_message_header, CMD_UPGRADE_COS);
	ret = filesys_hisee_read_image(COS_IMG_TYPE, (buff_virt + HISEE_ATF_MESSAGE_HEADER_LEN));
	if (ret < HISEE_OK) {
		pr_err("%s(): filesys_hisee_read_image failed, ret=%d\n", __func__, ret);
		dma_free_coherent(g_hisee_data.cma_device, (unsigned long)HISEE_SHARE_BUFF_SIZE, buff_virt, buff_phy);
		goto upgrade_exit;
	}
	image_size = (ret + HISEE_ATF_MESSAGE_HEADER_LEN);
	ret = send_smc_process(p_message_header, buff_phy, image_size,
							HISEE_ATF_COS_TIMEOUT, CMD_UPGRADE_COS);

	dma_free_coherent(g_hisee_data.cma_device, (unsigned long)HISEE_SHARE_BUFF_SIZE, buff_virt, buff_phy);
	if (HISEE_OK == ret) {
		parse_timestamp(g_hisee_data.hisee_img_head.time_stamp, &curr);
		if (!check_timestamp_valid(&curr)) {
			ret = HISEE_INVALID_PARAMS;
			pr_err("%s(): check_timestamp_valid failed\n", __func__);
			goto upgrade_exit;
		}

		/* add misc upgrade for normal case */
		if ((int)HISEE_FACTORY_TEST_VERSION != para) {
			check_misc_version();
			ret = hisee_misc_process();
		}
	} else {
		g_hisee_data.hisee_img_head.sw_version_cnt = 0;
		/*get_hisee_lcs_mode(&hisee_lcs_mode);
		if ((int)HISEE_FACTORY_TEST_VERSION != para && (unsigned int)HISEE_SM_MODE_MAGIC == hisee_lcs_mode) { 
			hisee_erase_hisee_img_head();
		}*/
	}

upgrade_exit:
	if (HISEE_OK == ret) {
		curr.img_version_num = g_hisee_data.hisee_img_head.sw_version_cnt;
		curr.magic = HISEE_SW_VERSION_MAGIC_VALUE;
		access_hisee_image_partition((char *)&curr, SW_VERSION_WRITE_TYPE);
		upgrade_run_flg = 0;
		access_hisee_image_partition((char *)&upgrade_run_flg, COS_UPGRADE_RUN_WRITE_TYPE);
	} else {
		while (retry > 0) {
			int ret1, ret2;
			pr_err("%s() failed and retry. retcode=%d\n", __func__, ret);
			retry--;
			ret1 = hisee_poweroff_func(NULL, HISEE_PWROFF_LOCK);
			hisee_mdelay(200);
			ret2 = hisee_poweron_upgrade_func(NULL, 0);
			hisee_mdelay(200);
			if (HISEE_OK != ret1 || HISEE_OK != ret2)
				continue;
			goto upgrade_retry;
		}
	}
upgrade_bypass:
	/* clear parse flag */
	g_hisee_data.img_header_is_parse = 0;
	ret_tmp = hisee_poweroff_func(NULL, HISEE_PWROFF_LOCK);
	if (HISEE_OK != ret_tmp) {
		pr_err("%s() poweroff failed. retcode=%d\n", __func__, ret_tmp);
		if (HISEE_OK == ret) ret = ret_tmp;
	}
	check_and_print_result();
	set_errno_and_return(ret);
}/*lint !e715*/

ssize_t hisee_has_new_cos_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	int new_cos_exist = 0;
	int ret;

	if (NULL == buf) {
		pr_err("%s buf paramters is null\n", __func__);
		set_errno_and_return(HISEE_INVALID_PARAMS);
	}

	ret = check_new_cosimage(&new_cos_exist);
	if (HISEE_OK == ret) {
		if (1 == new_cos_exist) {/*lint !e774*/
			snprintf(buf, (u64)3, "%d,", 0);
			strncat(buf, "exsited new cosimage", (unsigned long)strlen("exsited new cosimage"));
		} else {
			snprintf(buf, (u64)3, "%d,", 1);
			strncat(buf, "no exsited new cosimage", (unsigned long)strlen("no exsited new cosimage"));
		}
	} else {
		snprintf(buf, (u64)4, "%d,", -1);
		strncat(buf, "failed", (unsigned long)strlen("failed"));
	}
	pr_err("%s(): %s\n", __func__, buf);
	return (ssize_t)strlen(buf);
}/*lint !e715*/

ssize_t hisee_check_upgrade_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	unsigned int upgrade_run_flg = 0;
	int ret;

	if (NULL == buf) {
		pr_err("%s buf paramters is null\n", __func__);
		set_errno_and_return(HISEE_INVALID_PARAMS);
	}

	access_hisee_image_partition((char *)&upgrade_run_flg, COS_UPGRADE_RUN_READ_TYPE);
	if (0 == upgrade_run_flg) {
		snprintf(buf, (size_t)HISEE_BUF_SHOW_LEN, "0,cos upgrade success");
	} else if (HISEE_COS_UPGRADE_RUNNING_FLG == upgrade_run_flg) {
		snprintf(buf, (size_t)HISEE_BUF_SHOW_LEN, "1,cos upgrade failed last time");
	} else {
		snprintf(buf, (size_t)HISEE_BUF_SHOW_LEN, "-1,failed");
	}

	pr_err("%s(): %s\n", __func__, buf);
	return (ssize_t)strlen(buf);
}/*lint !e715*/
