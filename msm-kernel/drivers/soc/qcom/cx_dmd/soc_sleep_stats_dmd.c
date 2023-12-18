/*
 * soc_sleep_stats_dmd.c
 *
 * cx none idle dmd upload
 *
 * Copyright (C) 2017-2021 Huawei Technologies Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#include <securec.h>
#include <asm/arch_timer.h>
#include <log/hiview_hievent.h>
#include <log/log_usertype.h>

#define CXSD_NOT_IDLE_DMD 925004501
#define SPI_NOT_IDLE_DMD  925004510

#define REPORT_NONEIDLE_DMD_TIME (60 * 60 * 1000) /* 60min */
#define APSS_CRYSTAL_FREQ 19200000
#define APSS_REPORT_NONEIDLE_DMD_TIME (60 * 60) /* 60min */

static __le64 cx_last_acc_dur;
static s64 cx_last_time;
static bool flag_cx_none_idle, flag_cx_none_idle_short;

#define REPORT_SPI_UNSUSPEND_DMD_TIME (60 * 60 * 1000) /* 60min */
#define REPORT_SPI_UNSUSPEND_DMD_LIMIT_TIME (24 * 60 * 60 * 1000) /* 24hour */
#define REPORT_SPI_UNSUSPEND_CNT 40
#define SPI_CHECK_QUE_SIZE (REPORT_SPI_UNSUSPEND_CNT + 2)

#define RESET_SPI_IDLE_CHECK    0

static void soc_sleep_stats_dmd_report(int domain, const char* context)
{
	int dmd_code, ret;
	struct hiview_hievent *hi_event = NULL;

	dmd_code = domain;

	hi_event = hiview_hievent_create(dmd_code);
	if (!hi_event) {
		pr_err("create hievent fail\n");
		return;
	}

	ret = hiview_hievent_put_string(hi_event, "CONTENT", context);
	if (ret < 0)
		pr_err("hievent put string failed\n");

	ret = hiview_hievent_report(hi_event);
	if (ret < 0)
		pr_err("report hievent failed\n");

	hiview_hievent_destroy(hi_event);
}

void cx_dmd_check_apss_state(const uint64_t acc_dur, const uint64_t last_enter, const uint64_t last_exit)
{
	static bool apss_first = true;
	static uint64_t last_apss_sleep_acc_dur;
	uint64_t cur_apss_sleep_dur;
	uint64_t accumulated_duration = acc_dur;

	/*
	* If a master is in sleep when reading the sleep stats from SMEM
	* adjust the accumulated sleep duration to show actual sleep time.
	* This ensures that the displayed stats are real when used for
	* the purpose of computing battery utilization.
	*/
	if (last_enter > last_exit)
		accumulated_duration +=
			(__arch_counter_get_cntvct()
			- last_enter);

	if (apss_first) {
		last_apss_sleep_acc_dur = accumulated_duration;
		apss_first = false;
		return;
	}

	if (accumulated_duration < last_apss_sleep_acc_dur) {
		last_apss_sleep_acc_dur = accumulated_duration;
		cx_last_time = ktime_to_ms(ktime_get_real());
		return;
	}

	if (flag_cx_none_idle_short || flag_cx_none_idle) {
		if (flag_cx_none_idle) {
			cur_apss_sleep_dur = accumulated_duration - last_apss_sleep_acc_dur;
			cur_apss_sleep_dur = cur_apss_sleep_dur / APSS_CRYSTAL_FREQ; // to second

			if (cur_apss_sleep_dur >= APSS_REPORT_NONEIDLE_DMD_TIME) {
				soc_sleep_stats_dmd_report(CXSD_NOT_IDLE_DMD, "cx none idle");

				flag_cx_none_idle = false;
				flag_cx_none_idle_short = false;
				cx_last_time = ktime_to_ms(ktime_get_real());
				last_apss_sleep_acc_dur = accumulated_duration;
			}
		}
	} else {
		last_apss_sleep_acc_dur = accumulated_duration;
	}
}

void check_cx_idle_state(const __le64 cur_acc_duration, const s64 now)
{
	static bool cx_first = true;
	s64 none_idle_time;

	if (cx_first) {
		cx_last_time = now;
		cx_last_acc_dur = cur_acc_duration;
		cx_first = false;
		return;
	}

	if (cur_acc_duration != cx_last_acc_dur) {
		cx_last_acc_dur = cur_acc_duration;
		cx_last_time = now;
		flag_cx_none_idle = false;
		flag_cx_none_idle_short = false;
	} else {
		none_idle_time = now - cx_last_time;
		if (none_idle_time >= REPORT_NONEIDLE_DMD_TIME) {
			flag_cx_none_idle = true;
			flag_cx_none_idle_short = false;
		} else {
			flag_cx_none_idle_short = true;
			flag_cx_none_idle = false;
		}
	}
}

typedef struct {
	s64 unsuspend_time[SPI_CHECK_QUE_SIZE];
	int size;
	int count;
	int head;
	int tail;
} spi_check_queue_t;

spi_check_queue_t g_spi_check_que;

static void spi_queue_init(spi_check_queue_t *que)
{
	(void)memset_s(que->unsuspend_time, sizeof(que->unsuspend_time), 0, sizeof(que->unsuspend_time));
	que->size = SPI_CHECK_QUE_SIZE - 1;
	que->count = 0;
	que->head = 0;
	que->tail = 0;
}

static bool spi_que_full(spi_check_queue_t *que)
{
	return (((que->tail + 1) % SPI_CHECK_QUE_SIZE) == que->head);
}

static bool spi_que_empty(spi_check_queue_t *que)
{
	return (que->head == que->tail);
}

static void spi_enqueue(spi_check_queue_t *que, s64 time)
{
	if (que == NULL || spi_que_full(que)) {
		pr_err("spi enqueue fail\n");
		return;
	}

	que->unsuspend_time[que->tail] = time;
	que->tail = (que->tail + 1) % SPI_CHECK_QUE_SIZE;
	que->count++;
}

static int spi_dequeue(spi_check_queue_t *que)
{
	if (que == NULL || spi_que_empty(que)) {
		pr_err("spi dequeue fail\n");
		return -1;
	}

	que->unsuspend_time[que->head] = 0;
	que->head = (que->head + 1) % SPI_CHECK_QUE_SIZE;
	que->count--;

	return 0;
}

static int spi_get_queue_count(spi_check_queue_t *que)
{
	if (que == NULL)
		return -1;

	if (spi_que_empty(que))
		return 0;

	return que->count;
}

static s64 spi_get_head_value(spi_check_queue_t *que)
{
	if (que == NULL || spi_que_empty(que))
		return -1;

	return que->unsuspend_time[que->head];
}

void check_spi_idle_state(const s64 now)
{
	static bool spi_report_dmd = false;
	int spi_unsuspend_cnt;
	static uint64_t last_spi_dmd_report_time;
	static bool que_need_init = true;
	spi_check_queue_t *spi_check_que = &g_spi_check_que;

	if (now == RESET_SPI_IDLE_CHECK) {
		que_need_init = true;
		return;
	}

	if (spi_report_dmd == true) {
		/* do not check when reported once within 24 hours */
		if ((now - last_spi_dmd_report_time) < REPORT_SPI_UNSUSPEND_DMD_LIMIT_TIME)
			return;
		que_need_init = true;
		spi_report_dmd = false;
	}

	if (!spi_que_empty(spi_check_que) && (now < spi_get_head_value(spi_check_que)))
		que_need_init = true;

	if (que_need_init == true) {
		spi_queue_init(spi_check_que);
		que_need_init = false;
	}

	while (!spi_que_empty(spi_check_que) &&
		((now - spi_get_head_value(spi_check_que)) > REPORT_SPI_UNSUSPEND_DMD_TIME)) {
		/* remove unsuspend time when exceeds 1 hour */
		if (spi_dequeue(spi_check_que) != 0)
			return;
	}

	spi_enqueue(spi_check_que, now);

	spi_unsuspend_cnt = spi_get_queue_count(spi_check_que);
	if (spi_unsuspend_cnt > REPORT_SPI_UNSUSPEND_CNT) {
		soc_sleep_stats_dmd_report(SPI_NOT_IDLE_DMD, "spi none idle");
		last_spi_dmd_report_time = now;
		spi_report_dmd = true;
	}
}
EXPORT_SYMBOL(check_spi_idle_state);
