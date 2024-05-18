#ifndef __LCD_NOTIFIER_H_
#define __LCD_NOTIFIER_H_


typedef  enum {
	PON_PRESS_KEY_DOWN = 0,
	PON_PRESS_KEY_UP,
	PON_PRESS_KEY_S1,
	PON_PRESS_KEY_MAX
}PON_POWERKEY_EVENT_T;

void lcd_register_power_key_notify(void);

#endif
