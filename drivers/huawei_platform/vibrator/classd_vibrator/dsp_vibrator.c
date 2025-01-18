/*
 * dsp_vibrator.c
 *
 * classd_vibrator driver
 *
 * Copyright (c) 2020-2020 Huawei Technologies Co., Ltd.
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
#include <linux/delay.h>
#include <linux/slab.h>
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/hrtimer.h>
#include <linux/io.h>
#include <securec.h>
#include "dsp_vibrator.h"
#include "huawei_platform/log/hw_log.h"

#ifdef HWLOG_TAG
#undef HWLOG_TAG
#endif
#define HWLOG_TAG hw_dsp_vibrator
HWLOG_REGIST();

#define INVALIDATE_NUM		(-1)
#define EVEN_NUM		2

#define MAX_TEMP_LEN                        100001
#define VIB_DEFAULT_FREQ                    235
#define XVIB_DEFAULT_FREQ                   170
#define VIB_MIN_FREQ                        230
#define VIB_MAX_FREQ                        240
#define DATA_SCALE                          1000
#define VIB_235_WAVE_T                      24
#define XFREQ_BASE                          65
#define TABLE_SIZE                          11
#define INDEX_BASE                          5
#define ZERO_MAX                            0x01000000
#define ZERO_MIN                            0xF0000000
#define MIN_SIZE                            1000

enum VIB_TR_DSP_STATUS
{
	VIB_TR_DSP_PLAY = 0x0,
	VIB_TR_DSP_STOP = 0x1,
};

struct hifi_msg {
	uint16_t msg_id;
	uint16_t module_id;
	uint8_t payload[0];
};

struct vibrator_open_cmd {
	unsigned short msg_id;
	unsigned short reverse;
	unsigned int value;
};

static int g_vib_played_count = 0;
static int g_vib_maxfb_count = 0;
static int g_vib_wav_offset = 0;
static int g_vib_wav_select = VIB_WAV_235HZ;	// enum VIB_WAVE_TYPE
static bool g_vib_should_stop;
static bool g_ignore_first_stop;

const int g_wav235hz[] = {
#include "wav235hz.txt"
};

const int g_wav_z1[] = {
#include "wav_z1.txt"
};

const int g_wav_z2[] = {
#include "wav_z2.txt"
};

const int g_wav_z3[] = {
#include "wav_z3.txt"
};

const int g_wav_z4[] = {
#include "wav_z4.txt"
};

const int g_wav_z5[] = {
#include "wav_z5.txt"
};

const int g_vsys_wav235hz[] = {
#include "vsys_wav235hz.txt"
};

const int g_wav_vsys_1[] = {
#include "wav_vsys_1.txt"
};

const int g_wav_vsys_2[] = {
#include "wav_vsys_2.txt"
};

const int g_wav_vsys_3[] = {
#include "wav_vsys_3.txt"
};

const int g_wav_vsys_4[] = {
#include "wav_vsys_4.txt"
};

const int g_wav_vsys_5[] = {
#include "wav_vsys_5.txt"
};

const int calibretion_0[] = {
#ifdef CLASSD_VIBRATOR_DEBUG
#include "calibration-230.txt"
#endif
};

const int calibretion_1[] = {
#ifdef CLASSD_VIBRATOR_DEBUG
#include "calibration-231.txt"
#endif
};

const int calibretion_2[] = {
#ifdef CLASSD_VIBRATOR_DEBUG
#include "calibration-232.txt"
#endif
};

const int calibretion_3[] = {
#ifdef CLASSD_VIBRATOR_DEBUG
#include "calibration-233.txt"
#endif
};

const int calibretion_4[] = {
#ifdef CLASSD_VIBRATOR_DEBUG
#include "calibration-234.txt"
#endif
};

const int calibretion_5[] = {
#ifdef CLASSD_VIBRATOR_DEBUG
#include "calibration-235.txt"
#endif
};

const int calibretion_6[] = {
#ifdef CLASSD_VIBRATOR_DEBUG
#include "calibration-236.txt"
#endif
};

const int calibretion_7[] = {
#ifdef CLASSD_VIBRATOR_DEBUG
#include "calibration-237.txt"
#endif
};

const int calibretion_8[] = {
#ifdef CLASSD_VIBRATOR_DEBUG
#include "calibration-238.txt"
#endif
};

const int calibretion_9[] = {
#ifdef CLASSD_VIBRATOR_DEBUG
#include "calibration-239.txt"
#endif
};

const int calibretion_10[] = {
#ifdef CLASSD_VIBRATOR_DEBUG
#include "calibration-240.txt"
#endif
};

const int vibrator_wave_5v[] = {
#include "vibrator_wave_5v.txt"
};

const int g_vsys_wav235hz_flat[] = {
#include "flat_vsys_wav.txt"
};

const int flat_vibrator_wav1[] = {
#include "flat_vibrator_wav1.txt"
};

const int flat_vibrator_wav2[] = {
#include "flat_vibrator_wav2.txt"
};

const int flat_vibrator_wav3[] = {
#include "flat_vibrator_wav3.txt"
};

const int flat_vibrator_wav4[] = {
#include "flat_vibrator_wav4.txt"
};

const int flat_vibrator_wav5[] = {
#include "flat_vibrator_wav5.txt"
};

const int g_vsys_wav235hz_line[] = {
#include "line_vsys_wav.txt"
};
// mengchong
const int mengchong_wav_1[] = {
#include "mengchong-1.txt"
};

const int mengchong_wav_2[] = {
#include "mengchong-2.txt"
};

const int mengchong_wav_3[] = {
#include "mengchong-3.txt"
};

const int mengchong_wav_4[] = {
#include "mengchong-4.txt"
};

const int mengchong_wav_5[] = {
#include "mengchong-5.txt"
};

const int mengchong_wav_6[] = {
#include "mengchong-6.txt"
};

const int mengchong_wav_7[] = {
#include "mengchong-7.txt"
};

const int mengchong_wav_8[] = {
#include "mengchong-8.txt"
};

const int mengchong_wav_9[] = {
#include "mengchong-9.txt"
};

const int mengchong_wav_10[] = {
#include "mengchong-10.txt"
};

const int mengchong_wav_11[] = {
#include "mengchong-11.txt"
};

const int mengchong_wav_12[] = {
#include "mengchong-12.txt"
};

const int mengchong_wav_13[] = {
#include "mengchong-13.txt"
};

const int mengchong_wav_14[] = {
#include "mengchong-14.txt"
};

const int mengchong_wav_15[] = {
#include "mengchong-15.txt"
};

const int mengchong_wav_16[] = {
#include "mengchong-16.txt"
};

#define MENGCHONG_COUNT 16
#define MENGCHONG_BASE 100

const int xcalibration_0[] = {
#include "xcalibration-165.txt"
};

const int xcalibration_1[] = {
#include "xcalibration-166.txt"
};

const int xcalibration_2[] = {
#include "xcalibration-167.txt"
};

const int xcalibration_3[] = {
#include "xcalibration-168.txt"
};

const int xcalibration_4[] = {
#include "xcalibration-169.txt"
};

const int xcalibration_5[] = {
#include "xcalibration-170.txt"
};

const int xcalibration_6[] = {
#include "xcalibration-171.txt"
};

const int xcalibration_7[] = {
#include "xcalibration-172.txt"
};

const int xcalibration_8[] = {
#include "xcalibration-173.txt"
};

const int xcalibration_9[] = {
#include "xcalibration-174.txt"
};

const int xcalibration_10[] = {
#include "xcalibration-175.txt"
};

const int xvib_vsys_wave[] = {
#include "xvib_vsys_wave.txt"
};

const int x_vibrator_wav_1[] = {
#include "x_vibrator_wav1.txt"
};
 
const int x_vibrator_wav_2[] = {
#include "x_vibrator_wav2.txt"
};
 
const int x_vibrator_wav_3[] = {
#include "x_vibrator_wav3.txt"
};
 
const int x_vibrator_wav_4[] = {
#include "x_vibrator_wav4.txt"
};
 
const int x_vibrator_wav_5[] = {
#include "x_vibrator_wav5.txt"
};

struct vibrator_pcm_data {
	void *wav_data;
	size_t wav_size;
};

struct vibrator_pcm_data mengchong_wave[MENGCHONG_COUNT] = {
	{ (void*)mengchong_wav_1, sizeof(mengchong_wav_1) },
	{ (void*)mengchong_wav_2, sizeof(mengchong_wav_2) },
	{ (void*)mengchong_wav_3, sizeof(mengchong_wav_3) },
	{ (void*)mengchong_wav_4, sizeof(mengchong_wav_4) },
	{ (void*)mengchong_wav_5, sizeof(mengchong_wav_5) },
	{ (void*)mengchong_wav_6, sizeof(mengchong_wav_6) },
	{ (void*)mengchong_wav_7, sizeof(mengchong_wav_7) },
	{ (void*)mengchong_wav_8, sizeof(mengchong_wav_8) },
	{ (void*)mengchong_wav_9, sizeof(mengchong_wav_9) },
	{ (void*)mengchong_wav_10, sizeof(mengchong_wav_10) },
	{ (void*)mengchong_wav_11, sizeof(mengchong_wav_11) },
	{ (void*)mengchong_wav_12, sizeof(mengchong_wav_12) },
	{ (void*)mengchong_wav_13, sizeof(mengchong_wav_13) },
	{ (void*)mengchong_wav_14, sizeof(mengchong_wav_14) },
	{ (void*)mengchong_wav_15, sizeof(mengchong_wav_15) },
	{ (void*)mengchong_wav_16, sizeof(mengchong_wav_16) }
};

struct vibrator_pcm_data vib_wave_data[VIB_WAV_COUNT] = {
	{ (void*)g_wav235hz, sizeof(g_wav235hz) },
	{ (void*)g_wav_z1, sizeof(g_wav_z1) },
	{ (void*)g_wav_z2, sizeof(g_wav_z2) },
	{ (void*)g_wav_z3, sizeof(g_wav_z3) },
	{ (void*)g_wav_z4, sizeof(g_wav_z4) },
	{ (void*)g_wav_z5, sizeof(g_wav_z5) },
	{ (void*)calibretion_0, sizeof(calibretion_0) },
	{ (void*)calibretion_1, sizeof(calibretion_1) },
	{ (void*)calibretion_2, sizeof(calibretion_2) },
	{ (void*)calibretion_3, sizeof(calibretion_3) },
	{ (void*)calibretion_4, sizeof(calibretion_4) },
	{ (void*)calibretion_5, sizeof(calibretion_5) },
	{ (void*)calibretion_6, sizeof(calibretion_6) },
	{ (void*)calibretion_7, sizeof(calibretion_7) },
	{ (void*)calibretion_8, sizeof(calibretion_8) },
	{ (void*)calibretion_9, sizeof(calibretion_9) },
	{ (void*)calibretion_10, sizeof(calibretion_10) },
};

struct vibrator_pcm_data vib_vsys_wave_data[VIB_WAV_COUNT] = {
	{ (void*)g_vsys_wav235hz, sizeof(g_vsys_wav235hz) },
	{ (void*)g_wav_vsys_1, sizeof(g_wav_vsys_1) },
	{ (void*)g_wav_vsys_2, sizeof(g_wav_vsys_2) },
	{ (void*)g_wav_vsys_3, sizeof(g_wav_vsys_3) },
	{ (void*)g_wav_vsys_4, sizeof(g_wav_vsys_4) },
	{ (void*)g_wav_vsys_5, sizeof(g_wav_vsys_5) },
};

struct vibrator_pcm_data vib_flat_vsys_wave_data[VIB_WAV_COUNT] = {
	{ (void*)g_vsys_wav235hz_flat, sizeof(g_vsys_wav235hz_flat) },
	{ (void*)flat_vibrator_wav1, sizeof(flat_vibrator_wav1) },
	{ (void*)flat_vibrator_wav2, sizeof(flat_vibrator_wav2) },
	{ (void*)flat_vibrator_wav3, sizeof(flat_vibrator_wav3) },
	{ (void*)flat_vibrator_wav4, sizeof(flat_vibrator_wav4) },
	{ (void*)flat_vibrator_wav5, sizeof(flat_vibrator_wav5) },
};

struct vibrator_pcm_data vib_line_vsys_wave_data[VIB_WAV_COUNT] = {
	{ (void*)g_vsys_wav235hz_line, sizeof(g_vsys_wav235hz_line) },
	{ (void*)g_wav_vsys_1, sizeof(g_wav_vsys_1) },
	{ (void*)g_wav_vsys_2, sizeof(g_wav_vsys_2) },
	{ (void*)g_wav_vsys_3, sizeof(g_wav_vsys_3) },
	{ (void*)g_wav_vsys_4, sizeof(g_wav_vsys_4) },
	{ (void*)g_wav_vsys_5, sizeof(g_wav_vsys_5) },
};

struct vibrator_pcm_data xvib_vsys_wave_data[VIB_WAV_COUNT] = {
	{ (void*)xvib_vsys_wave, sizeof(xvib_vsys_wave) },
	{ (void*)x_vibrator_wav_1, sizeof(x_vibrator_wav_1) },
	{ (void*)x_vibrator_wav_2, sizeof(x_vibrator_wav_2) },
	{ (void*)x_vibrator_wav_3, sizeof(x_vibrator_wav_3) },
	{ (void*)x_vibrator_wav_4, sizeof(x_vibrator_wav_4) },
	{ (void*)x_vibrator_wav_5, sizeof(x_vibrator_wav_5) },
	{ (void*)xcalibration_0, sizeof(xcalibration_0) },
	{ (void*)xcalibration_1, sizeof(xcalibration_1) },
	{ (void*)xcalibration_2, sizeof(xcalibration_2) },
	{ (void*)xcalibration_3, sizeof(xcalibration_3) },
	{ (void*)xcalibration_4, sizeof(xcalibration_4) },
	{ (void*)xcalibration_5, sizeof(xcalibration_5) },
	{ (void*)xcalibration_6, sizeof(xcalibration_6) },
	{ (void*)xcalibration_7, sizeof(xcalibration_7) },
	{ (void*)xcalibration_8, sizeof(xcalibration_8) },
	{ (void*)xcalibration_9, sizeof(xcalibration_9) },
	{ (void*)xcalibration_10, sizeof(xcalibration_10) },
};

struct vibrator_pcm_data vib_5v_wave_data[VIB_WAV_COUNT] = {
	{ (void*)vibrator_wave_5v, sizeof(vibrator_wave_5v) },
	{ (void*)g_wav_vsys_1, sizeof(g_wav_vsys_1) },
	{ (void*)g_wav_vsys_2, sizeof(g_wav_vsys_2) },
	{ (void*)g_wav_vsys_3, sizeof(g_wav_vsys_3) },
	{ (void*)g_wav_vsys_4, sizeof(g_wav_vsys_4) },
	{ (void*)g_wav_vsys_5, sizeof(g_wav_vsys_5) },
};

static int g_wave_temp[MAX_TEMP_LEN];
static size_t g_wave_temp_size;
static uint32_t target_freq = VIB_DEFAULT_FREQ;
static uint32_t default_freq = VIB_DEFAULT_FREQ;
static uint32_t freq_base = 0;
static struct vibrator_pcm_data vib_wave_use_data;
static bool g_is_long_effect;
static int freq_table[TABLE_SIZE] = { -3, -1 ,0, 0, 0 ,0, 0, 0, 0, 1, 3};

void set_long_effect(bool status)
{
	g_is_long_effect = status;
}

void dsp_vibrator_set_freq(uint32_t freq)
{
	int index = 0;
	if (freq < VIB_MIN_FREQ || freq > VIB_MAX_FREQ) {
		hwlog_err("%s: freq error", __func__);
		return;
	}

	target_freq = freq - freq_base;
	index = target_freq - default_freq + INDEX_BASE;
	if (freq_base == XFREQ_BASE && index >= 0 && index <= TABLE_SIZE) {
		target_freq += freq_table[index];
	}

	hwlog_info("%s: set cali freq = %u", __func__, target_freq);
}

void dsp_vibrator_get_freq(uint32_t *freq)
{
	(*freq) = target_freq;
}

void change_vibrator_mode(uint32_t mode)
{
	int i;

	if (mode >= MODE_COUNT) {
		hwlog_err("%s: invalid mode", __func__);
		return;
	}

	if (mode == MODE_LDO) {
		hwlog_info("%s: vibrator mode is LDO", __func__);
		return;
	}
	if (mode == MODE_VSYS) {
		for (i = 0; i <= VIB_WAV_Z5; i++) {
			vib_wave_data[i].wav_data = vib_vsys_wave_data[i].wav_data;
			vib_wave_data[i].wav_size = vib_vsys_wave_data[i].wav_size;
		}
		hwlog_info("%s: change mode to vsys success", __func__);
		return;
	}
	if (mode == MODE_VSYS_FLAT) {
		for (i = 0; i <= VIB_WAV_Z5; i++) {
			vib_wave_data[i].wav_data = vib_flat_vsys_wave_data[i].wav_data;
			vib_wave_data[i].wav_size = vib_flat_vsys_wave_data[i].wav_size;
		}
		hwlog_info("%s: change mode to vsys flat success", __func__);
		return;
	}
	if (mode == MODE_VSYS_LINE) {
		for (i = 0; i <= VIB_WAV_Z5; i++) {
			vib_wave_data[i].wav_data = vib_line_vsys_wave_data[i].wav_data;
			vib_wave_data[i].wav_size = vib_line_vsys_wave_data[i].wav_size;
		}
		hwlog_info("%s: change mode to vsys line success", __func__);
		return;
	}
	if (mode == MODE_VSYS_XVIB) {
		for (i = 0; i < VIB_WAV_COUNT; i++) {
			vib_wave_data[i].wav_data = xvib_vsys_wave_data[i].wav_data;
			vib_wave_data[i].wav_size = xvib_vsys_wave_data[i].wav_size;
		}
		default_freq = XVIB_DEFAULT_FREQ;
		freq_base = XFREQ_BASE;
		target_freq = default_freq;
		hwlog_info("%s: change mode to xvib success", __func__);
		return;
	}
	if (mode == MODE_5V) {
		for (i = 0; i <= VIB_WAV_Z5; i++) {
			vib_wave_data[i].wav_data = vib_5v_wave_data[i].wav_data;
			vib_wave_data[i].wav_size = vib_5v_wave_data[i].wav_size;
		}
		hwlog_info("%s: change mode to 5v success", __func__);
	}
}

static int cali_data_size(int old_len)
{
	int old_point;
	int new_t;
	int new_point;
	int new_len;

	old_point = old_len * DATA_SCALE / VIB_235_WAVE_T;
	new_t = VIB_235_WAVE_T * (int)target_freq / (int)default_freq;
	new_point = old_point * (int)default_freq / (int)target_freq;

	new_len = new_t * new_point / DATA_SCALE;
	hwlog_info("%s: old_len = %d, new_len = %d", __func__, old_len, new_len);
	return new_len;
}

static void cali_play_data(int select)
{
	int ration;
	int index;

	int i;
	int ret;
	int len;

	int temp;
	long long temp1;
	long long temp2;

	int *use_data = NULL;
	size_t new_size;

	if (select >= MENGCHONG_BASE && select < MENGCHONG_BASE + MENGCHONG_COUNT) {
		hwlog_info("%s: pet type: %d", __func__, select);
		vib_wave_use_data.wav_data = mengchong_wave[select - MENGCHONG_BASE].wav_data;
		vib_wave_use_data.wav_size = mengchong_wave[select - MENGCHONG_BASE].wav_size;
		return;
	}

	(void)memset_s(g_wave_temp, sizeof(g_wave_temp), 0, sizeof(g_wave_temp));
	g_wave_temp_size = vib_wave_data[select].wav_size;
	len = g_wave_temp_size / sizeof(int);

	if (len > MAX_TEMP_LEN) {
		hwlog_err("%s: len too big", __func__);
		vib_wave_use_data.wav_data = vib_wave_data[select].wav_data;
		vib_wave_use_data.wav_size = vib_wave_data[select].wav_size;
		return;
	}
	use_data = vib_wave_data[select].wav_data;

	if (target_freq == default_freq ||
		(select >= VIB_CALIBRATION_0 && select <= VIB_CALIBRATION_10)) {
		hwlog_info("%s: not use cali data, size: %d", __func__, vib_wave_data[select].wav_size);
		vib_wave_use_data.wav_data = vib_wave_data[select].wav_data;
		vib_wave_use_data.wav_size = vib_wave_data[select].wav_size;
		return;
	}

	for (i = 0; i < len; i++) {
		temp = i * (int)target_freq;
		index = temp / (int)default_freq;
		temp1 = (long long)temp * DATA_SCALE;
		ration = (int) (temp1 / (int)default_freq) - index * DATA_SCALE;

		if (index < len - 1) {
			temp2 = (long long)(use_data[index + 1] - use_data[index]) * ration;
			g_wave_temp[i] = use_data[index] + (int)(temp2 / DATA_SCALE);
		} else if (index == len - 1) {
			g_wave_temp[i] = use_data[index];
			g_wave_temp_size = (i + 1) * sizeof(int);
		} else {
			break;
		}

		if (i > 0 && (unsigned int)g_wave_temp[i - 1] > ZERO_MIN && (unsigned int)g_wave_temp[i] < ZERO_MAX) {
			new_size = i * sizeof(int);
			hwlog_info("new_size: %d wav %0x wav-1 %0x", new_size, g_wave_temp[i], g_wave_temp[i-1]);
		}
	}

	if (select == VIB_WAV_235HZ && default_freq == VIB_DEFAULT_FREQ) {
		new_size = (size_t)cali_data_size(len) * sizeof(int);
		if (new_size < g_wave_temp_size)
			g_wave_temp_size = new_size;
	}
	if (select == VIB_WAV_235HZ && default_freq == XVIB_DEFAULT_FREQ) {
		if (new_size < g_wave_temp_size && new_size > MIN_SIZE)
			g_wave_temp_size = new_size;
	}
	hwlog_info("g_wave_temp_size: %d, default_frep = %d", g_wave_temp_size, default_freq);
	vib_wave_use_data.wav_data = (void *)g_wave_temp;
	vib_wave_use_data.wav_size = g_wave_temp_size;
}
static void (*g_stop_notify)(void);

void dsp_vibrator_register_stop_handler(void (*call_back)(void))
{
	if (call_back != NULL)
		g_stop_notify = call_back;
}

static int hisi_pcm_mailbox_send_data(const void *pmsg_body, unsigned int msg_len,
	unsigned int msg_priority)
{
	unsigned int ret = 0;
	ret = DRV_MAILBOX_SENDMAIL(MAILBOX_MAILCODE_ACPU_TO_HIFI_AUDIO, pmsg_body, msg_len);
	return (int)ret;
}

static int hisi_pcm_notify_set_buf(unsigned short msg_id, unsigned short value)
{
	int ret;
	struct vibrator_open_cmd msg_body = {0};
	msg_body.msg_id = msg_id;
	msg_body.value = value;
	ret = hisi_pcm_mailbox_send_data(&msg_body, sizeof(msg_body), 0);
	return ret;
}

static int copy_vibrator_data(void *dest, int dest_size,
	const void *src, int src_size, int offset)
{
	int size = src_size;
	int total_size = dest_size;
	int cur_size;
	int filloffset = offset;
	void *dest_buffer = dest;

	if (filloffset >= size) {
		hwlog_err("%s: offset(%0x) > size(%0x)", __func__, filloffset, size);
		filloffset = 0;
	}

	while (total_size > 0) {
		cur_size = size - filloffset;
		if (total_size < cur_size)
			cur_size = total_size;

		if (memcpy_s((void *)dest_buffer, cur_size, (void *)&src[filloffset], cur_size) != EOK) {
			hwlog_err("%s: vib copybuffer fail", __func__);
			return 0;
		}
		dest_buffer += cur_size;
		total_size -= cur_size;
		if (src_size != 0)
			filloffset = (filloffset + cur_size) % src_size;
		else
			break;
		if ((g_vib_wav_select != VIB_WAV_235HZ) && filloffset == 0) {
			if (total_size > 0)
				memset_s(dest_buffer, total_size, 0, total_size);
			g_vib_should_stop = true;
			break;
		}
	}
	return filloffset;
}

static void play_vibrator_filldata(const void *user_hdl, struct mb_queue *mail_hdl, uint32_t mail_len)
{
	unsigned char *buffer = get_trans_buffer();
	size_t buf_size = (((unsigned long)HISI_AP_AUDIO_VIBRATOR_DATA_SIZE) >> 1);
	int select = g_vib_wav_select;
	(void)user_hdl;
	(void)mail_hdl;
	(void)mail_len;
	if (g_vib_should_stop && ((g_vib_wav_select <= VIB_WAV_Z5 && g_vib_wav_select >= VIB_WAV_Z1) ||
		(g_vib_wav_select < MENGCHONG_BASE + MENGCHONG_COUNT && g_vib_wav_select >= MENGCHONG_BASE))) {
		if (g_stop_notify == NULL) {
			hwlog_err("%s: stop function not init", __func__);
			return;
		}

		if (g_is_long_effect && g_ignore_first_stop) {
			g_ignore_first_stop = false;
			hwlog_info("first stop effect, ignored");
			return;
		}
		hwlog_info("stop effect");
		(*g_stop_notify)();
		return;
	}
	hwlog_info("%s: count:%#x, max_cn:%#x", __func__, g_vib_played_count, g_vib_maxfb_count);
	if (buffer == NULL || buf_size == 0) {
		hwlog_err("%s: param invalidate(buffer:%p, size:%x)!", __func__, buffer, buf_size);
		return;
	}
	++g_vib_played_count;
	if (g_vib_played_count > g_vib_maxfb_count) {
		if (g_stop_notify == NULL) {
			hwlog_err("%s: stop function not init", __func__);
			return;
		}
		(*g_stop_notify)();
		return;
	}
	if (g_vib_should_stop && g_vib_wav_select <= VIB_CALIBRATION_10 &&
		g_vib_wav_select >= VIB_CALIBRATION_0) {
		g_vib_maxfb_count = g_vib_played_count;
		return;
	}

	if (g_vib_played_count % EVEN_NUM == 0)
		buffer = &buffer[buf_size];

	g_vib_wav_offset = copy_vibrator_data((unsigned char *)buffer, buf_size,
		(void *)vib_wave_use_data.wav_data,
		vib_wave_use_data.wav_size, g_vib_wav_offset);
}

int play_vibrator_data(void *buffer, int buf_size, int count, int type, mb_msg_cb receive_func)
{
	int ret;
	if (buffer == NULL || buf_size == 0) {
		hwlog_err("%s: param invalidate(buffer:%p, size:%x)!", __func__, buffer, buf_size);
		return INVALIDATE_NUM;
	}
	hwlog_info("%s:buffer:%p,size:%x, count:%d, type:%d", __func__, buffer, buf_size, count, type);
	g_vib_played_count = 0;
	g_vib_maxfb_count = count;
	g_vib_wav_offset = 0;
	g_vib_wav_select = type;
	g_vib_should_stop = false;
	g_ignore_first_stop = true;

	cali_play_data(type);
	if (vib_wave_use_data.wav_size <= 0) {
		hwlog_err("%s play data err", __func__);
		return INVALIDATE_NUM;
	}

	hwlog_info("%s: pcmbuf:%p, pcmsize:%x", __func__, vib_wave_use_data.wav_data, vib_wave_use_data.wav_size);
	g_vib_wav_offset = copy_vibrator_data(buffer, buf_size,
		(void *)vib_wave_use_data.wav_data, vib_wave_use_data.wav_size, g_vib_wav_offset);
	ret = DRV_MAILBOX_REGISTERRECVFUNC(MAILBOX_MAILCODE_HIFI_TO_ACPU_VIBRATOR, receive_func, NULL);
	if (ret == 0)
		ret = hisi_pcm_notify_set_buf(ID_AP_CMD_VIBRATOR_TRIGGER, VIB_TR_DSP_PLAY);

	return ret;
}

bool is_play_vibrator(void)
{
	return g_vib_maxfb_count > 0;
}

bool is_type_valid(int type)
{
	if (type >= 0 && type < VIB_WAV_COUNT) {
		return true;
	}
	if (type >= MENGCHONG_BASE && type < MENGCHONG_COUNT + MENGCHONG_BASE) {
		return true;
	}
	return false;
}

int start_play_vibrator_data(int type, int count)
{
	int ret;
	unsigned char *buffer = get_trans_buffer();
	int buf_size = (int)HISI_AP_AUDIO_VIBRATOR_DATA_SIZE;
	hwlog_info("%s: buffer:%p, size:%0x", __func__, buffer, buf_size);

	if (buffer == NULL) {
		hwlog_err("%s: buffer empty!", __func__);
		return INVALIDATE_NUM;
	}

	stop_play_vibrator_data();
	(void)memset_s(buffer, buf_size, 0, buf_size);
	if (!is_type_valid(type)) {
		hwlog_err("%s: invalid type = %d", __func__, type);
		return INVALIDATE_NUM;
	}
	ret = play_vibrator_data((void *)buffer, buf_size, count, type, play_vibrator_filldata);
	return ret;
}

void stop_play_vibrator_data(void)
{
	int ret;

	if (!is_play_vibrator())
		return;
	hwlog_info("%s", __func__);
	ret = hisi_pcm_notify_set_buf(ID_AP_CMD_VIBRATOR_TRIGGER, VIB_TR_DSP_STOP);
	if (ret)
		hwlog_err("%s: notify dsp stop vibrator err!", __func__);
	g_vib_maxfb_count = 0;
	g_vib_played_count = 0;
}
