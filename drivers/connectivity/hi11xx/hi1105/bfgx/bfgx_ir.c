/**
 * Copyright (c) @CompanyNameMagicTag 2022-2023. All rights reserved.
 *
 * Description: Create an IR system file node and register the driver
 * Author: @CompanyNameTag
 */
#include <linux/platform_device.h>
#include <linux/miscdevice.h>
#include <linux/reboot.h>
#include <linux/fs.h>

#include "plat_pm.h"
#include "bfgx_dev.h"
#include "bfgx_core.h"
#include "bfgx_data_parse.h"
#include "plat_exception_rst.h"
#include "hw_bfg_ps.h"
#include "plat_debug.h"

enum board_irled_ctrl_type {
    IR_GPIO_CTRL = 0x0,
    IR_LDO_CTRL = 0x1,
};

#ifdef HAVE_HISI_IR
static bool g_have_ir_ctrl = OAL_FALSE;
static int32_t g_irled_power_type = IR_GPIO_CTRL;
static struct regulator *g_ir_ctrl_ldo = NULL;

/*
 * Prototype    : ir_ctrl_gpio_init
 * Description  : 由于IR_CTRL GPIO归入conn_gpio模块统一管理, 这里仅判断是否可以获取到
 */
static int32_t ir_ctrl_gpio_init(void)
{
    int32_t ir_ctrl_gpio = conn_get_gpio_number_by_type(IR_CTRL);
    if (ir_ctrl_gpio < 0) {
        ps_print_err("%s gpio not inited\n", PROC_NAME_GPIO_BFGX_IR_CTRL);
        return -OAL_FAIL;
    } else {
        ps_print_info("%s gpio is %d\n", PROC_NAME_GPIO_BFGX_IR_CTRL, ir_ctrl_gpio);
        return OAL_SUCC;
    }
}

/*
 * Prototype    : ir_ctrl_pmic_init
 * Description  : 红外控制的PMU LDO初始化和电压设置
 */
static int32_t ir_ctrl_pmic_init(struct platform_device *pdev)
{
#ifdef _PRE_CONFIG_USE_DTS
    int32_t ret = -OAL_FAIL;
    struct device_node *np = NULL;
    int32_t irled_voltage = 0;
    if (pdev == NULL) {
        ps_print_err("board pmu pdev is NULL!\n");
        return ret;
    }

    ret = get_board_dts_node(&np, DTS_NODE_HISI_MPXX);
    if (ret != OAL_SUCC) {
        ps_print_err("DTS read node %s fail!!!\n", DTS_NODE_HISI_MPXX);
        return ret;
    }

    g_ir_ctrl_ldo = regulator_get(&pdev->dev, DTS_PROP_MPXX_IRLED_LDO_POWER);
    if (IS_ERR(g_ir_ctrl_ldo)) {
        ps_print_err("board_ir_ctrl_pmic_init get ird ldo failed\n");
        return ret;
    }

    ret = of_property_read_u32(np, DTS_PROP_MPXX_IRLED_VOLTAGE, &irled_voltage);
    if (ret == OAL_SUCC) {
        ps_print_info("set irled voltage %d\n", irled_voltage); /* 电压以uv为单位<2850000> */
        ret = regulator_set_voltage(g_ir_ctrl_ldo, (int)irled_voltage, (int)irled_voltage);
        if (ret) {
            ps_print_err("board_ir_ctrl_pmic_init set voltage ldo failed\n");
            return ret;
        }
    } else {
        ps_print_info("get irled voltage failed ,use default\n");
    }

    ret = regulator_set_mode(g_ir_ctrl_ldo, REGULATOR_MODE_NORMAL);
    if (ret) {
        ps_print_err("board_ir_ctrl_pmic_init set ldo mode failed\n");
        return ret;
    }
    ps_print_info("board_ir_ctrl_pmic_init success\n");
    return OAL_SUCC;
#else
    return OAL_SUCC;
#endif
}
#endif

/*
 * Prototype    : hw_ir_ctrl_init
 * Description  : 红外控制的初始化接口, 读取DTS配置中以下内容：
 *                （1）是否有SOC侧的红外灯控制 -- have_ir_ctrl
 *                （2）红外灯的控制类型 -- GPIO控制外置LDO或者是直接控制SOC PMU_LDO
 */
int32_t hw_ir_ctrl_init(struct platform_device *pdev)
{
#if (defined HAVE_HISI_IR) && (defined _PRE_CONFIG_USE_DTS)
    int ret;
    struct device_node *np = NULL;

    ret = get_board_dts_node(&np, DTS_NODE_HISI_MPXX);
    if (ret != OAL_SUCC) {
        ps_print_err("DTS read node %s fail!!!\n", DTS_NODE_HISI_MPXX);
        return OAL_SUCC;
    }
    g_have_ir_ctrl = of_property_read_bool(np, "have_ir_ctrl");
    if (g_have_ir_ctrl == OAL_FALSE) {
        ps_print_info("board has no Ir");
    } else {
        ret = of_property_read_u32(np, DTS_PROP_MPXX_IR_LDO_TYPE, &g_irled_power_type);
        ps_print_info("read property ret is %d, g_irled_power_type is %d\n", ret, g_irled_power_type);
        if (ret != OAL_SUCC) {
            ps_print_err("get dts prop %s failed\n", DTS_PROP_MPXX_IR_LDO_TYPE);
            return -OAL_FAIL;
        }

        if (g_irled_power_type == IR_GPIO_CTRL) {
            ret = ir_ctrl_gpio_init();
            if (ret != OAL_SUCC) {
                ps_print_err("ir_ctrl_gpio init failed\n");
                return -OAL_FAIL;
            }
        } else if (g_irled_power_type == IR_LDO_CTRL) {
            ret = ir_ctrl_pmic_init(pdev);
            if (ret != OAL_SUCC) {
                ps_print_err("ir_ctrl_pmic init failed\n");
                return -OAL_FAIL;
            }
        } else {
            ps_print_err("get ir_ldo_type failed!err num is %d\n", g_irled_power_type);
            return -OAL_FAIL;
        }
    }
    return OAL_SUCC;
#else
    return OAL_SUCC;
#endif
}

/*
 * Prototype    : hw_ir_ctrl_show
 * Description  : /sys/hi110x_ps/ir_ctrl节点显示当前状态
 */
int32_t hw_ir_ctrl_show(char *buf)
{
#ifdef HAVE_HISI_IR
    if (g_have_ir_ctrl == OAL_FALSE) {
        ps_print_info("board have no ir ctrl");
        return -OAL_FAIL;
    }

    if (g_irled_power_type == IR_GPIO_CTRL) {
        return snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%d\n", conn_get_gpio_level(IR_CTRL));
    } else if (g_irled_power_type == IR_LDO_CTRL) {
        return snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%d\n",
                          (regulator_is_enabled(g_ir_ctrl_ldo)) > 0 ? 1 : 0);
    }

    return -OAL_FAIL;
#else
    return OAL_SUCC;
#endif
}

/*
 * Prototype    : hw_ir_ctrl_set
 * Description  : 设置红外灯电源开启或关闭
 *                power_on: 1 = 开启; 0 = 关闭
 */
int32_t hw_ir_ctrl_set(int32_t power_on)
{
#ifdef HAVE_HISI_IR
    int ret = OAL_SUCC;

    if (g_have_ir_ctrl == OAL_FALSE) {
        ps_print_info("board have no ir ctrl");
        return OAL_SUCC;
    }

    ps_print_info("set ir ctrl mode as %d!\n", power_on);
    if ((power_on != OAL_TRUE) && (power_on != OAL_FALSE)) {
        ps_print_err("ctrl param should be 0 or 1, cur value is [%d]\n", power_on);
        return -OAL_FAIL;
    }
    if (g_irled_power_type == IR_GPIO_CTRL) {
        enum gpio_level level = (power_on == OAL_TRUE) ? GPIO_LEVEL_HIGH : GPIO_LEVEL_LOW;
        conn_set_gpio_level(IR_CTRL, level);
    } else if (g_irled_power_type == IR_LDO_CTRL) {
        if (IS_ERR(g_ir_ctrl_ldo)) {
            ps_print_err("ir_ctrl get ird ldo failed\n");
            return -OAL_FAIL;
        }

        if (power_on == OAL_FALSE) {
            ret = regulator_disable(g_ir_ctrl_ldo);
        } else {
            ret = regulator_enable(g_ir_ctrl_ldo);
        }

        if (ret != OAL_SUCC) {
            ps_print_err("ir_ctrl %s ldo failed\n", (power_on == OAL_FALSE) ? "disable" : "enable");
        }
    } else {
        ps_print_err("get ir_ldo_type error! ir_ldo_type is %d!\n", g_irled_power_type);
        return -OAL_FAIL;
    }
#endif
    return OAL_SUCC;
}

/*
 * Prototype    : hw_ir_open
 * Description  : open ir device
 */
static int32_t hw_ir_open(struct inode *inode, struct file *filp)
{
    int32_t ret;
    struct pm_top* pm_top_data = pm_get_top();
    struct ps_core_s *ps_core_d = NULL;

    if (unlikely(inode == NULL)) {
        ps_print_err("%s param is error", __func__);
        return -EINVAL;
    }

    ps_core_d = get_ps_core_from_miscdev(filp->private_data);
    if (ps_core_d == NULL) {
        ps_print_err("%s ps core is null", __func__);
        return -EINVAL;
    }

    mutex_lock(&(pm_top_data->host_mutex));
    ret = hw_bfgx_open(ps_core_d, BFGX_IR);
    mutex_unlock(&(pm_top_data->host_mutex));

    /* 上电成功后，再打开红外灯 */
    if (ret == OAL_SUCC) {
        ret = hw_ir_ctrl_set(OAL_TRUE);
    }

    return ret;
}

/*
 * Prototype    : hw_ir_read
 * Description  : read ir node data
 */
static ssize_t hw_ir_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
    uint16_t ret_count;
    struct sk_buff *skb = NULL;
    struct ps_core_s *ps_core_d = NULL;

    PS_PRINT_FUNCTION_NAME;
    if (unlikely(buf == NULL)) {
        ps_print_err("buf is NULL\n");
        return -EINVAL;
    }

    ps_core_d = get_ps_core_from_miscdev(filp->private_data);
    if (unlikely(ps_core_d == NULL)) {
        ps_print_err("ps_core_d is NULL\n");
        return -EINVAL;
    }

    if ((skb = ps_skb_dequeue(ps_core_d, RX_IR_QUEUE)) == NULL) {
        ps_print_dbg("ir read skb queue is null!\n");
        return 0;
    }

    ret_count = min_t(size_t, skb->len, count);
    if (copy_to_user(buf, skb->data, ret_count)) {
        ps_print_err("copy_to_user is err!\n");
        ps_restore_skbqueue(ps_core_d, skb, RX_IR_QUEUE);
        return -EFAULT;
    }

    skb_pull(skb, ret_count);

    if (skb->len == 0) {
        kfree_skb(skb);
    } else {
        ps_restore_skbqueue(ps_core_d, skb, RX_IR_QUEUE);
    }

    return ret_count;
}

/*
 * Prototype    : hw_ir_write
 * Description  : write data to ir node
 */
static ssize_t hw_ir_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos)
{
    struct ps_core_s *ps_core_d = NULL;
    int32_t ret = 0;
    int32_t prepare_result;

    PS_PRINT_FUNCTION_NAME;

    ps_core_d = get_ps_core_from_miscdev(filp->private_data);
    ret = hw_bfgx_write_check(buf, ps_core_d, BFGX_IR);
    if (ret < 0) {
        return ret;
    }

    if (count > IR_TX_MAX_FRAME) {
        ps_print_err("IR skb len is too large!\n");
        return -EINVAL;
    }

    if (oal_netbuf_list_len(&ps_core_d->tx_low_seq) > TX_LOW_QUE_MAX_NUM) {
        return 0;
    }

    ret = prepare_to_visit_node(ps_core_d, &prepare_result);
    if (ret < 0) {
        ps_print_err("prepare work fail, bring to reset work\n");
        plat_exception_handler(SUBSYS_BFGX, THREAD_IR, get_wakeup_excp_by_uart_idx(ps_core_d->pm_data->index));
        return ret;
    }

    if (oal_atomic_read(&ps_core_d->ir_only) == 0) {
        /* modify expire time of uart idle timer */
        mod_timer(&ps_core_d->pm_data->bfg_timer, jiffies + msecs_to_jiffies(BT_SLEEP_TIME));
        oal_atomic_inc(&ps_core_d->pm_data->bfg_timer_mod_cnt);
    }

    /* to divide up packet function and tx to tty work */
    if (ps_h2d_tx_data(ps_core_d, BFGX_IR, buf, count) < 0) {
        ps_print_err("hw_ir_write is err\n");
        post_to_visit_node(ps_core_d, prepare_result);
        return -EFAULT;
    }

    ps_core_d->bfgx_info[BFGX_IR].tx_pkt_num++;

    post_to_visit_node(ps_core_d, prepare_result);

    ps_print_info("no.[%d] send data %d Byte\n", (uint32_t)ps_core_d->bfgx_info[BFGX_IR].tx_pkt_num, (uint32_t)count);

    return count;
}

static int32_t hw_ir_release(struct inode *inode, struct file *filp)
{
    int32_t ret;
    struct ps_core_s *ps_core_d = NULL;
    struct pm_top* pm_top_data = pm_get_top();

    ps_core_d = get_ps_core_from_miscdev(filp->private_data);
    if (unlikely(ps_core_d == NULL)) {
        ps_print_err("ps_core_d is NULL\n");
        return -EINVAL;
    }

    /* 关红外前，先关闭红外灯电源 */
    hw_ir_ctrl_set(OAL_FALSE);

    mutex_lock(&(pm_top_data->host_mutex));
    ret = hw_bfgx_close(ps_core_d, BFGX_IR);
    mutex_unlock(&(pm_top_data->host_mutex));

    return ret;
}

static const struct file_operations g_default_ir_fops = {
    .owner = THIS_MODULE,
    .open = hw_ir_open,
    .write = hw_ir_write,
    .read = hw_ir_read,
    .release = hw_ir_release,
};

static struct bfgx_subsys_driver_desc g_default_ir_driver_desc = {
    .file_ops = &g_default_ir_fops
};

struct bfgx_subsys_driver_desc *get_ir_default_drv_desc(void)
{
    return &g_default_ir_driver_desc;
}

MODULE_DESCRIPTION("Public serial Driver for huawei ir chips");
MODULE_LICENSE("GPL");
