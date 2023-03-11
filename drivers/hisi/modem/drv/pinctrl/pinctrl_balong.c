#include <product_config.h>
#include <mdrv_memory.h>
#include <osl_malloc.h>
#include <securec.h>
#include <linux/of.h>
#include <hi_pinctrl.h>
#include <bsp_shared_ddr.h>
#include <bsp_print.h>
#include "pinctrl_balong.h"

#undef THIS_MODU
#define THIS_MODU mod_pinctrl
#define ios_print_error(fmt, ...) (bsp_err("[balong pin]:<%s> "fmt, __FUNCTION__, ##__VA_ARGS__))
#define ios_print_debug(fmt, ...) (bsp_debug("[balong pin]:<%s> "fmt, __FUNCTION__, ##__VA_ARGS__))
void *g_pin_shmem_base  = NULL;

static int pinctrl_shared_memory_init(void)
{
    g_pin_shmem_base = (void *)SHM_BASE_ADDR + SHM_OFFSET_IOS;
    if (g_pin_shmem_base == NULL) {
        ios_print_error("error: share mem get fail\n");
        return -1;
    }
    return 0;
}
static void pinctrl_data_convert(struct pinctrl *pctl, const struct pinctrl_property *prop, unsigned int len)
{
    unsigned int i;

    for (i = 0; i < len; i++) {
        pctl[i].gpio = prop[i].gpio_grp * GPIO_MAX_NUMBER + prop[i].gpio_bit;

        pctl[i].iomg_off = prop[i].iomg_off;
        pctl[i].iomg_val = prop[i].iomg_val;
        pctl[i].iocg_off = prop[i].iocg_off;
        pctl[i].iocg_val = prop[i].iocg_val;
        pctl[i].gpio_dir = prop[i].gpio_dir;
        pctl[i].gpio_val = prop[i].gpio_val;
        pctl[i].reserve = 0;
    }
}

static int balong_pinctrl_set_sharemem(struct device_node *dev_node)
{
    struct modem_pinctrl_head *phead = (struct modem_pinctrl_head *)g_pin_shmem_base;
    void *dts_buf = NULL;
    char pinctrl_name[MODEM_PIN_BUTT][PIN_NAME_LEN] = {"pinctrl-0", "pinctrl-1", "pinctrl-2"};
    u32 offset_addr = 0;
    u32 pin_number[MODEM_PIN_BUTT] = {0};
    int i, ret;

    (void)memset_s((void *)phead, PINCTRL_SHMEM_SIZE, 0, PINCTRL_SHMEM_SIZE);
    ret = of_property_read_u32_array(dev_node, "pinctrl-num", pin_number, MODEM_PIN_BUTT);
    if (ret) {
        ios_print_error("get pin_number fail, ret :%d\n", ret);
        return ret;
    }

    dts_buf = kmalloc(PINCTRL_SHMEM_SIZE, GFP_KERNEL);
    if (dts_buf == NULL) {
        ios_print_error("malloc dts buf fail\n");
        return -1;
    }

    for (i = 0; i < MODEM_PIN_BUTT; i++) {
        phead->head[i].size = pin_number[i];
        offset_addr += (i == 0) ? sizeof(struct modem_pinctrl_head) : (phead->head[i - 1].size * sizeof(struct pinctrl));
        phead->head[i].offset = offset_addr;
        if (phead->head[i].size > MAX_GROUP_SIZE) {
            ios_print_error("head size is too much, mode %d size %u.\n", i, phead->head[i].size);
            goto error;
        }

        (void)memset_s((void *)dts_buf, PINCTRL_SHMEM_SIZE, 0, PINCTRL_SHMEM_SIZE);
        ret = of_property_read_u32_array(dev_node, pinctrl_name[i], dts_buf,\
                                         sizeof(struct pinctrl_property) * pin_number[i] / sizeof(u32));
        if (ret) {
            ios_print_error("Could not get property, ret=%d, node name:%s\n", ret, pinctrl_name[i]);
            goto error;
        }
        pinctrl_data_convert((struct pinctrl *)((void *)phead + offset_addr),\
                             (struct pinctrl_property *)dts_buf, \
                             phead->head[i].size);
    }
    kfree(dts_buf);
    dts_buf = NULL;
    return 0;

error:
    kfree(dts_buf);
    dts_buf = NULL;
    return -1;
}

void modem_pinctrl_debug(int mode)
{
    unsigned int i;
    unsigned int size;
    struct pinctrl *pctl = NULL;
    struct modem_pinctrl_head *phead = g_pin_shmem_base;

    if (mode >= MODEM_PIN_BUTT) {
        ios_print_error("modem pintrl mode is error, mode=%d.\n", mode);
        return;
    }

    size = phead->head[mode].size;
    pctl = (struct pinctrl *)((char *)phead + phead->head[mode].offset);

    ios_print_error("iocfg table size is %d\n", size);
    ios_print_error("  gpio  iomg  iocg  dir  value\n");

    for (i = 0; i < size; i++) {
        ios_print_error("%5d %5d %5d %5d %5d \n", pctl[i].gpio, pctl[i].iomg_val, pctl[i].iocg_val, pctl[i].gpio_dir,
            pctl[i].gpio_val);
    }
}

/* Modem pinctrl extract from the device tree. */
int bsp_modem_pinctrl_dts_parse(void)
{
    int ret;
    struct device_node *dev_node = NULL;

    ios_print_error("parse dts start!\n");

    if (pinctrl_shared_memory_init()) {
        return -1;
    }

    dev_node = of_find_compatible_node(NULL, NULL, "arm,modem_pinctrl");
    if (dev_node == NULL) {
        ios_print_error("Can't find balong pinctrl node.\n");
        return -1;
    }

    ret = balong_pinctrl_set_sharemem(dev_node);
    if (ret < 0) {
        ios_print_error("pinctrl set sharemem info fail, ret :%d\n", ret);
    }
    ios_print_error("parse dts end!\n");
    return ret;
}
#ifndef CONFIG_HISI_BALONG_MODEM_MODULE
module_init(bsp_modem_pinctrl_dts_parse);
#endif

EXPORT_SYMBOL_GPL(bsp_modem_pinctrl_dts_parse);
