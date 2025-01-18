#ifndef __I2C_SWITCH_GPIO_H
#define __I2C_SWITCH_GPIO_H

#define I2C_GPIO_GROUP_NUM 2
#define I2C_INDEX_MAX 3

typedef struct _tag_i2c_switch_gpio_board_info {
	/* i2c  */
	struct pinctrl *pctrl;
	struct pinctrl_state *pinctrl_def_i2c_group[I2C_INDEX_MAX][I2C_GPIO_GROUP_NUM];
	struct pinctrl_state *pinctrl_idle_i2c[I2C_INDEX_MAX];

	struct device *dev;
} i2c_switch_gpio_board_info_t;

int32_t i2c_switch_gpio_pinctrl_set(int32_t i2c_index, int32_t gpio_group_index, bool on_off);

#endif
