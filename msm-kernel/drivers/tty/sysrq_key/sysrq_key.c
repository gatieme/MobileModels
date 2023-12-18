#ifdef CONFIG_HANDSET_SYSRQ_RESET

#include "sysrq_key.h"

#include <linux/input.h>
#include <linux/printk.h>
#include <linux/sched/debug.h>
#include <linux/sysrq.h>
#include <linux/bitops.h>
#include <linux/input.h>
#include <platform/trace/events/rainbow.h>
#include <platform/linux/rainbow.h>

#ifdef CONFIG_FASTBOOT_DUMP
#include <linux/fastboot_dump_reason_api.h>
#endif
#ifdef CONFIG_RAINBOW_RESET_DETECT
#include <linux/rainbow_reset_detect_api.h>
#endif

bool sysrq_down = false;
int sysrq_alt_use = 0;
int sysrq_alt = 0;

void sysrq_key_init(void)
{
	sysrq_down = false;
	sysrq_alt = 0;
}

bool sysrq_handle_keypress(struct sysrq_state *sysrq, unsigned int code, int value)
{
	char attach_info_buffer[RB_SREASON_STR_MAX] = {0};
	switch (code) {
	/* use volumedown + volumeup + power for sysrq function */
	case KEY_VOLUMEDOWN:
		/* identify volumedown pressed down or not */
		if (value) {
			sysrq_alt = code;
		}
		/* when volumedown lifted up clear the state of syrq_down and syrq_alt */
		else {
			if (sysrq_down && code == sysrq_alt_use)
				sysrq_down = false;
			sysrq_alt = 0;
		}
		break;

	case KEY_VOLUMEUP:
		/* identify volumeup pressed down or not */
		if (value == 1 && sysrq_alt) {
			sysrq_down = true;
			sysrq_alt_use = sysrq_alt;
		}
		else {
			sysrq_down = false;
			sysrq_alt_use = 0;
		}
		break;

	case KEY_POWER:
		/* identify power pressed down or not */
		if (sysrq_down && value && value != 2) {
			pr_info("trigger system crash by sysrq.\n");
#ifdef CONFIG_FASTBOOT_DUMP
			fastboot_dump_m_reason_set(FD_M_NORMALBOOT);
			fastboot_dump_s_reason_set(FD_S_NORMALBOOT_COMBIN_KEY);
			fastboot_dump_s_reason_str_set("Combin_Key");
#endif
#ifdef CONFIG_RAINBOW_RESET_DETECT
			rainbow_reset_detect_m_reason_set(FD_M_NORMAL);
			rainbow_reset_detect_s_reason_set(FD_S_COMBIN_KEY);
			rainbow_reset_detect_s_reason_str_set("Combin_Key");
#endif
			memcpy(attach_info_buffer, "combin_key", RB_SREASON_STR_MAX);
			rb_sreason_set(attach_info_buffer);
			show_state_filter(TASK_UNINTERRUPTIBLE);
			__handle_sysrq('c', true);
		}
		else {
			sysrq_down = false;
			sysrq_alt_use = 0;
		}
		break;

	default:
		break;
	}

	return sysrq_down;
}

#endif
