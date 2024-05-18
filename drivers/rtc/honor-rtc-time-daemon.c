#include "honor-rtc-time-daemon.h"
#include <linux/fs.h>
#include <linux/ktime.h>
#include <linux/syscalls.h>
#include <linux/vmalloc.h>
#include <linux/soc/qcom/smem.h>

#include <log/log_usertype.h>

#define BSPINFO_RAW_PART_PATH "/dev/block/by-name/bsp_info"
#define RTC_MIN_VALUE_TO_RESET_OFFSET 60
#define OFFSET_TAG_SIZE 8
#define OFFSET_TAG "RTC"
#define MAX_TIME_VALUE 2524579200 // 2050-01-01 00:00:00

typedef struct {
	char off_tag[OFFSET_TAG_SIZE];
	uint64_t offset;
}Offset_Info;

static Offset_Info offset_info;
static const struct rtc_class_ops* qpnp_rtc_rw_ops;
static struct rtc_class_ops honor_rtc_rw_ops;

static struct timer_list check_rtc_timer;
#define CHECK_RTC_DELAY_TIME (120 * 1000) //s

static void check_rtc_timer_task(struct timer_list *t_list) {
	if (BETA_USER == get_logusertype_flag())
		panic("RTC bigger than MAX_TIME_VALUE");
	else
		del_timer(&check_rtc_timer);

	return;
}

static int honor_rtc_time_daemon_read_time(struct device *dev, struct rtc_time *tm){
	int ret = -1;
	uint64_t qpnp_rtc_secs, honor_rtc_secs = 0;
	struct rtc_time qpnp_rtc_time;

	if(!qpnp_rtc_rw_ops){
		dev_err(dev, "func %s: qpnp_rtc_rw_ops is NULL !\n",__func__);
		return -1;
	}
	if(!qpnp_rtc_rw_ops->read_time){
		dev_err(dev, "func %s: qpnp_rtc_rw_ops->read_time is NULL !\n",__func__);
		return -1;
	}
	ret = qpnp_rtc_rw_ops->read_time(dev, &qpnp_rtc_time);
	if(0 != ret){
		dev_err(dev, "func %s: read rtc time from qpnp_rtc failed !\n",__func__);
		return ret;
	}
	qpnp_rtc_secs = (unsigned long)rtc_tm_to_time64(&qpnp_rtc_time);

	honor_rtc_secs = qpnp_rtc_secs + offset_info.offset;
	if (honor_rtc_secs > MAX_TIME_VALUE) {
		dev_err(dev, "honor_rtc_secs:%llu is bigger than MAX_TIME_VALUE\n", honor_rtc_secs);
		honor_rtc_secs = MAX_TIME_VALUE;
	}
	rtc_time64_to_tm(honor_rtc_secs, tm);

	ret = rtc_valid_tm(tm);
	if (ret) {
		dev_err(dev, "Invalid time read from RTC\n");
		return ret;
	}
 	return ret;
}

const struct rtc_class_ops* get_honor_rtc_time_daemon_rw_ops(
                const struct rtc_class_ops *qpnp_rtc_rw_ops_ptr) {

        struct rtc_class_ops *honor_rtc_rw_ops_ptr;
        if(NULL == qpnp_rtc_rw_ops_ptr){
                pr_err("%s: the parameter qpnp_rtc_rw_ops_ptr is NULL\n", __func__);
                return NULL;
        }

        qpnp_rtc_rw_ops = qpnp_rtc_rw_ops_ptr;

        honor_rtc_rw_ops_ptr = &honor_rtc_rw_ops;
        memcpy(honor_rtc_rw_ops_ptr, qpnp_rtc_rw_ops_ptr, sizeof(struct rtc_class_ops));
        honor_rtc_rw_ops_ptr->read_time = honor_rtc_time_daemon_read_time;

        pr_info("%s: get rtc rw ops finished !\n", __func__);
        return honor_rtc_rw_ops_ptr;
}
EXPORT_SYMBOL(get_honor_rtc_time_daemon_rw_ops);


int honor_rtc_time_daemon_init(struct device *dev){
	int ret = -1;
	uint64_t qpnp_rtc_secs;
	struct rtc_time qpnp_rtc_time;
	struct smem_exten_honor_paramater *smem = NULL;
	size_t size = sizeof(*smem);

	if(NULL == dev){
 		pr_err("%s: Device pointer is null !\n", __func__);
 		return -1;
 	}

 	ret = qcom_smem_alloc(QCOM_SMEM_HOST_ANY, SMEM_ID_VENDOR1, size);
 	if (ret < 0 && ret != -EEXIST) {
 		pr_err("%s: qcom_smem_alloc failed, %d\n", __func__, ret);
 		return ret;
 	}
 	smem = qcom_smem_get(QCOM_SMEM_HOST_ANY, SMEM_ID_VENDOR1, &size);
 	if (NULL == smem)
 	{
 		pr_err("%s: SMEM Error, READING RTC OFFSET INFO \n", __func__);
 		return -1;
 	}

 	memcpy(&offset_info, smem->rtc_offset_info, sizeof(Offset_Info));

	/* if the qpnp rtc is abnormal power off, clear the offset */
	if(!qpnp_rtc_rw_ops){
		dev_err(dev, "func %s: qpnp_rtc_rw_ops is NULL !\n",__func__);
		return -1;
	}
	if(!qpnp_rtc_rw_ops->read_time){
		dev_err(dev, "func %s: qpnp_rtc_rw_ops->read_time is NULL !\n",__func__);
		return -1;
	}
 	ret = qpnp_rtc_rw_ops->read_time(dev, &qpnp_rtc_time);
 	if(0 != ret){
 		dev_err(dev, "func %s: read rtc time from qpnp_rtc failed !\n",__func__);
 		return ret;
 	}
 	qpnp_rtc_secs = (unsigned long)rtc_tm_to_time64(&qpnp_rtc_time);
 	pr_info("func %s: The qpnp rtc seconds is %lld \n", __func__, qpnp_rtc_secs);

 	pr_info("%s: the init rtc offset is %llu\n", __func__, offset_info.offset);

	if ((offset_info.offset + qpnp_rtc_secs) >= MAX_TIME_VALUE) {
		dev_err(dev, "rtc_secs is bigger than MAX_TIME_VALUE\n");
		check_rtc_timer.expires = jiffies + msecs_to_jiffies(CHECK_RTC_DELAY_TIME);
		timer_setup(&check_rtc_timer, check_rtc_timer_task, 0);
		add_timer(&check_rtc_timer);
	}

 	return 0;
}
EXPORT_SYMBOL(honor_rtc_time_daemon_init);
