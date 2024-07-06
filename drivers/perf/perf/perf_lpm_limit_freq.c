
#include <linux/string.h>
#include <linux/kernel.h>
#include "securec.h"
#include "utils/perf_buffered_log_sender.h"
#include "perf_ioctl.h"
#include "perf_lpm_limit_freq.h"
#ifdef CONFIG_IPA_MNTN_INFO
#include "../platform_source/cee/drivers/thermal_platform/ipa_thermal.h"
#include "../drivers/platform_drivers/ap/platform/charlotte/thermal_common.h"
#endif

/* The data is aligned with HISI. The data content is four digits. */
#define LIMIT_FREQ_DATA_NUM 4

#ifdef CONFIG_IPA_MNTN_INFO
/* decimal notation */
#define DATA_CONVERT_BASE 10

static int perf_limit_freq_data_parse(char *buf, int *freq_data,
	const int data_num)
{
	char *token = NULL;
	int i = 0;
	int ret;

	if (!buf || !freq_data) {
		pr_err("PerfD %s: parse limit freq data failed, para err.\n",
			__func__);
		return -EINVAL;
	}

	/* Numbers are separated by ',' without spaces. */
	while ((token = strsep(&buf, ",")) && (i < data_num)) {
		ret = kstrtos32(token, DATA_CONVERT_BASE, freq_data + i);
		if (ret < 0) {
			pr_err("PerfD %s: convert to sint failed, ret: %d.\n",
				__func__, ret);
			return -EINVAL;
		}
		i++;
	}

	if (buf && buf[0] != '\0') {
		pr_err("PerfD %s: failed to parse data, the data is too long.\n",
			__func__);
		return -EINVAL;
	}
	if (i < data_num) {
		pr_err("PerfD %s: failed to parse data, the data is too short, "
			"data length: %d\n", __func__, i);
		return -EINVAL;
	}

	return 0;
}

static int perf_get_limit_freq_data(struct perf_buffered_log_entry *entry,
	int buf_len)
{
	int ret;
	char buf[MAX_IPA_MNTN_INF_LEN] = {0};
	int freq_data[LIMIT_FREQ_DATA_NUM] = {-1, -1, -1, -1};

	if (!entry) {
		pr_err("PerfD %s: get limit freq data failed, para err.\n", __func__);
		return -EINVAL;
	}

	ret = read_limit_freq(buf);
	if (ret <= 0) {
		pr_err("PerfD %s: failed to get limit freq info, ret: %d\n",
			__func__, ret);
		return -EINVAL;
	}

	ret = perf_limit_freq_data_parse(buf, freq_data, LIMIT_FREQ_DATA_NUM);
	if (ret < 0) {
		pr_err("PerfD %s: data parse failed, ret: %d\n", __func__, ret);
		return -EINVAL;
	}

	ret = memcpy_s(entry->data, buf_len, freq_data, sizeof(freq_data));
	if (ret != EOK) {
		pr_err("PerfD %s: data memcpy failed, ret: %d\n", __func__, ret);
		return -EINVAL;
	}

	return 0;
}
#endif

long perf_ioctl_lpm_limit_freq(unsigned int cmd, void __user *argp)
{
	int ret = -EINVAL;
	unsigned int entry_size;
	struct perf_buffered_log_entry *entry = NULL;
	int i;

	entry_size = sizeof(struct perf_buffered_log_entry) +
		LIMIT_FREQ_DATA_NUM * sizeof(int);

	entry = perf_create_log_entry(entry_size, IOC_LPM_LIMIT_FREQ,
		LIMIT_FREQ_DATA_NUM);
	if (entry == NULL) {
		pr_err("PerfD %s: failed to create log entry\n", __func__);
		return ret;
	}

	/*
	 * By default, the data is written as error data. When the upper layer
	 * detects incorrect data, it indicates that the function is faulty or
	 * the function macro is not enabled for the HISI.
	 */
	for (i = 0; i < LIMIT_FREQ_DATA_NUM; i++) {
		((int *)(entry->data))[i] = -1;
	}

#ifdef CONFIG_IPA_MNTN_INFO
	ret = perf_get_limit_freq_data(entry, LIMIT_FREQ_DATA_NUM * sizeof(int));
	if (ret < 0) {
		pr_err("PerfD %s: get freq data failed, ret: %d\n", __func__, ret);
		goto error;
	}
#endif

	ret = send_perf_buffered_log_entry(entry);
	if (ret < 0) {
		pr_err("PerfD %s: failed to send log entry ret %d\n", __func__, ret);
		goto error;
	}

error:
	free_perf_buffered_log_entry(entry);
	return ret;
}