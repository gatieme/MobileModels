/*
 * hall_ak8987 driver
 *
 * Copyright (c) 2023-2023 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#include <linux/device.h>
#include <linux/time64.h>
#include <securec.h>
#include "hall_report.h"
#include "log/hw_log.h"

#ifdef HWLOG_TAG
#undef HWLOG_TAG
#endif

#define HWLOG_TAG ap_hall
HWLOG_REGIST();

#ifdef CONFIG_HUAWEI_DSM
#define HALL_IRQ_CODE_MAX (100)
#define HALL_FREP_IRQ_COURT_THRESHOLD (60)
#define HALL_IRQ_REPORT_HOUR_MAX (25)
#define SECS_PER_8_HOUR (60 * 60 * 8)
#define E_OK (0)

#define DSM_BUFF_MAX_INFO_LEN   256

static unsigned int g_code_count_arr[HALL_IRQ_CODE_MAX] = { 0 };
static unsigned int g_irq_time_arr[HALL_IRQ_REPORT_HOUR_MAX] = { 0 };

static void hall_record_code_count(struct tm *ptm, unsigned int code)
{
	if (ptm == NULL) {
		hwlog_err("%s:ptm is null,return", __func__);
		return;
	}

	if (ptm->tm_hour >= 0 && ptm->tm_hour < HALL_IRQ_REPORT_HOUR_MAX)
		g_irq_time_arr[ptm->tm_hour]++;

	if (code >= HALL_IRQ_CODE_MAX) {
		hwlog_err("%s:code[%u] is big than [%d],return", __func__, code, HALL_IRQ_CODE_MAX);
		return;
	}

	g_code_count_arr[code]++;
}

static void get_local_time(struct tm *ptm)
{
	struct timespec64 tv;

	(void)memset_s(&tv, sizeof(tv), 0, sizeof(tv));
	ktime_get_real_ts64(&tv);
	time64_to_tm(tv.tv_sec, SECS_PER_8_HOUR, ptm);
}

static void hall_report_irq_dsm(struct dsm_client *dclient, struct tm ptm)
{
	static struct tm pre_ptm;
	bool is_need_report = false;
	int i;

	if (pre_ptm.tm_mday == 0 || pre_ptm.tm_mday == ptm.tm_mday) {
		pre_ptm = ptm;
		return;
	}
	pre_ptm = ptm;
	for (i = 0; i < HALL_IRQ_REPORT_HOUR_MAX; i++) {
		if (g_irq_time_arr[i] > HALL_FREP_IRQ_COURT_THRESHOLD) {
			is_need_report = true;
			break;
		}
	}
	if (is_need_report)
		hall_report_dsm_info(dclient, false);
	(void)memset_s(&g_code_count_arr, sizeof(g_code_count_arr), 0, sizeof(g_code_count_arr));
	(void)memset_s(&g_irq_time_arr, sizeof(g_irq_time_arr), 0, sizeof(g_irq_time_arr));
}

static void hall_irq_code_count_to_str(char *ret_content, int len)
{
	int i, ret;

	if (ret_content == NULL) {
		hwlog_err("%s:ret_content is null, return", __func__);
		return;
	}
	for (i = 0; i < HALL_IRQ_CODE_MAX; i++) {
		if (g_code_count_arr[i] == 0)
			continue;
		ret = snprintf_s(ret_content, len, len - 1, "%s %d:%u ", ret_content, i, g_code_count_arr[i]);
		if (ret < 0)
			hwlog_err("%s:snprintf_s error %d", __func__, ret);
	}
}

static void hall_arr_to_str(char *ret_content, int len, unsigned int *arr_value, int arr_len)
{
	int i, ret;

	if (ret_content == NULL) {
		hwlog_err("%s:ret_content is null, return", __func__);
		return;
	}
	for (i = 0; i < arr_len; i++) {
		ret = snprintf_s(ret_content, len, len - 1, "%s%u_", ret_content, arr_value[i]);
		if (ret < 0)
			hwlog_err("%s:snprintf_s error %d", __func__, ret);
	}
}

static void hall_get_report_dsm_buffer(char *dsm_buf, int len)
{
	struct tm ptm;
	char str_irq_time[DSM_BUFF_MAX_INFO_LEN] = {0};
	char str_pdata_count[DSM_BUFF_MAX_INFO_LEN] = {0};
	int ret;

	if (dsm_buf == NULL) {
		hwlog_err("%s:dsm_buf is null, return", __func__);
		return;
	}
	get_local_time(&ptm);
	hall_arr_to_str(str_irq_time, DSM_BUFF_MAX_INFO_LEN, g_irq_time_arr, HALL_IRQ_REPORT_HOUR_MAX);
	hall_irq_code_count_to_str(str_pdata_count, DSM_BUFF_MAX_INFO_LEN);
	ret = snprintf_s(dsm_buf, len, len - 1, "%s 24 hour irq:%s,hall value count:%s report_time:%d-%d-%d %d:%d:%d,",
		dsm_buf, str_irq_time, str_pdata_count, ptm.tm_year + 1900, ptm.tm_mon + 1, ptm.tm_mday, ptm.tm_hour,
		ptm.tm_min, ptm.tm_sec);
	if (ret < 0)
		hwlog_err("%s:snprintf_s error %d", __func__, ret);
	hwlog_info("%s,len:%d dsm_buf:%s\n", __func__, strlen(dsm_buf), dsm_buf);
}

void hall_report_dsm_info(struct dsm_client *dclient, bool istrigger)
{
	int ret;
	char dmd_error_buffer[DSM_BUFF_MAX_INFO_LEN] = {"timer:"};

	if (dclient == NULL) {
		hwlog_err("%s:ak8789_dsm_client is null, return", __func__);
		return;
	}

	if (istrigger) {
		ret = strcpy_s(dmd_error_buffer, sizeof(dmd_error_buffer), "trigger:");
		if (ret != E_OK)
			hwlog_err("%s:strcpy_s error %d", __func__, ret);
	}

	hall_get_report_dsm_buffer(dmd_error_buffer, DSM_BUFF_MAX_INFO_LEN);

	if (!dsm_client_ocuppy(dclient)) {
		dsm_client_record(dclient, dmd_error_buffer);
		dsm_client_notify(dclient, DSM_HALL_ERROR_NO);
	}
}

void hall_set_irq_info(struct dsm_client *dclient, unsigned int pdata)
{
	struct tm ptm;

	if (dclient == NULL) {
		hwlog_err("%s:ak8789_dsm_client is null, return", __func__);
		return;
	}
	get_local_time(&ptm);
	hall_record_code_count(&ptm, pdata);
	hall_report_irq_dsm(dclient, ptm);
}
EXPORT_SYMBOL(hall_set_irq_info);
#endif

MODULE_LICENSE("GPL");