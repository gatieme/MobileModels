#ifndef _PINCTRL_BALONG_H_
#define _PINCTRL_BALONG_H_

#define GPIO_MAX_NUMBER 0x8
#define PINCONFIG_NF_VAL 0xffff
#define MAX_GROUP_SIZE 240
#define PINCTRL_SHMEM_SIZE 0x1800
#define PIN_NAME_LEN 10

enum {
    MODEM_PIN_INIT = 0,
    MODEM_PIN_NORMAL,
    MODEM_PIN_POWERDOWN,
    MODEM_PIN_BUTT,
};

struct pinctrl {
    unsigned int gpio;
    unsigned int iomg_off;
    unsigned int iomg_val;
    unsigned int iocg_off;
    unsigned int iocg_val;
    unsigned int gpio_dir;
    unsigned int gpio_val;
    unsigned int reserve;
};

struct pinctrl_property {
    unsigned int gpio_grp;
    unsigned int gpio_bit;
    unsigned int iomg_off;
    unsigned int iomg_val;
    unsigned int iocg_off;
    unsigned int iocg_val;
    unsigned int gpio_dir;
    unsigned int gpio_val;
};

struct pinctrl_head {
    unsigned int offset;
    unsigned int size;
};

struct modem_pinctrl_head {
    struct pinctrl_head head[MODEM_PIN_BUTT];
};

int modem_pintrl_dts_parse(void *fdt);

#endif
