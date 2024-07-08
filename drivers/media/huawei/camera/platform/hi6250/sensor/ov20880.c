


#include <linux/module.h>
#include <linux/printk.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/platform_device.h>
#include <linux/rpmsg.h>

#include "hwsensor.h"
#include "sensor_commom.h"
#include "hw_csi.h"

#define I2S(i) container_of(i, sensor_t, intf)

//lint -save -e846 -e514 -e866 -e30 -e84 -e785 -e64
//lint -save -e826 -e838 -e715 -e747 -e778 -e774 -e732
//lint -save -e650 -e31 -e731 -e528 -e753 -e737

static bool s_ov20880_power_on = false;
extern struct hw_csi_pad hw_csi_pad;
static hwsensor_vtbl_t s_ov20880_vtbl;

int ov20880_config(hwsensor_intf_t* si, void  *argp);

struct sensor_power_setting hw_ov20880_power_up_setting[] = {
    //disable main camera reset
    {
        .seq_type = SENSOR_SUSPEND,
        .config_val = SENSOR_GPIO_LOW,
        .sensor_index = SENSOR_INDEX_INVALID,
        .delay = 1,
    },

    //MCAM1 AVDD 2.80V
    {
        .seq_type = SENSOR_AVDD2,
        .data = (void*)"main-sensor-avdd",
        .config_val = LDO_VOLTAGE_V2P8V,
        .sensor_index = SENSOR_INDEX_INVALID,
        .delay = 0,
    },

    //MCAM1 DVDD 1.2V
    {
        .seq_type = SENSOR_DVDD2,
        .config_val = LDO_VOLTAGE_1P2V,
        .sensor_index = SENSOR_INDEX_INVALID,
        .delay = 0,
    },

    //SCAM AVDD 2.85V
    {
        .seq_type = SENSOR_AVDD,
        .data = (void*)"slave-sensor-avdd",
        .config_val = LDO_VOLTAGE_V2P85V,
        .sensor_index = SENSOR_INDEX_INVALID,
        .delay = 0,
    },

    //SCAM DVDD 1.05V
    {
        .seq_type = SENSOR_DVDD,
        .config_val = LDO_VOLTAGE_1P05V,
        .sensor_index = SENSOR_INDEX_INVALID,
        .delay = 1,
    },

    //MCAM1 IOVDD 1.80V
    {
        .seq_type = SENSOR_IOVDD,
        .data = (void*)"main-sensor-iovdd",
        .config_val = LDO_VOLTAGE_1P8V,
        .sensor_index = SENSOR_INDEX_INVALID,
        .delay = 1,
    },

    {
        .seq_type = SENSOR_MCLK,
        .sensor_index = SENSOR_INDEX_INVALID,
        .delay = 1,
    },

    //SCAM RST
    {
        .seq_type = SENSOR_RST,
        .config_val = SENSOR_GPIO_HIGH,
        .sensor_index = SENSOR_INDEX_INVALID,
        .delay = 1,
    },
};
struct sensor_power_setting hw_ov20880_power_down_setting[] = {
    //SCAM RST
    {
        .seq_type = SENSOR_RST,
        .config_val = SENSOR_GPIO_LOW,
        .sensor_index = SENSOR_INDEX_INVALID,
        .delay = 1,
    },
    {
        .seq_type = SENSOR_MCLK,
        .sensor_index = SENSOR_INDEX_INVALID,
        .delay = 1,
    },
    //MCAM1 IOVDD 1.80V
    {
        .seq_type = SENSOR_IOVDD,
        .data = (void*)"main-sensor-iovdd",
        .config_val = LDO_VOLTAGE_1P8V,
        .sensor_index = SENSOR_INDEX_INVALID,
        .delay = 1,
    },
    //SCAM DVDD 1.05V
    {
        .seq_type = SENSOR_DVDD,
        .config_val = LDO_VOLTAGE_1P05V,
        .sensor_index = SENSOR_INDEX_INVALID,
        .delay = 1,
    },
    //SCAM AVDD 2.85V
    {
        .seq_type = SENSOR_AVDD,
        .data = (void*)"slave-sensor-avdd",
        .config_val = LDO_VOLTAGE_V2P85V,
        .sensor_index = SENSOR_INDEX_INVALID,
        .delay = 0,
    },
    //MCAM1 DVDD 1.2V
    {
        .seq_type = SENSOR_DVDD2,
        .config_val = LDO_VOLTAGE_1P2V,
        .sensor_index = SENSOR_INDEX_INVALID,
        .delay = 0,
    },
    //MCAM1 AVDD 2.80V
    {
        .seq_type = SENSOR_AVDD2,
        .data = (void*)"main-sensor-avdd",
        .config_val = LDO_VOLTAGE_V2P8V,
        .sensor_index = SENSOR_INDEX_INVALID,
        .delay = 0,
    },
    //disable main camera reset
    {
        .seq_type = SENSOR_SUSPEND,
        .config_val = SENSOR_GPIO_LOW,
        .sensor_index = SENSOR_INDEX_INVALID,
        .delay = 1,
    },
};

atomic_t volatile ov20880_powered = ATOMIC_INIT(0);
sensor_t s_ov20880 =
{
    .intf = { .vtbl = &s_ov20880_vtbl, },
    .power_setting_array = {
            .size = ARRAY_SIZE(hw_ov20880_power_up_setting),
            .power_setting = hw_ov20880_power_up_setting,
     },
    .power_down_setting_array = {
            .size = ARRAY_SIZE(hw_ov20880_power_down_setting),
            .power_setting = hw_ov20880_power_down_setting,
    },

     .p_atpowercnt = &ov20880_powered,
};

const struct of_device_id
s_ov20880_dt_match[] =
{
    {
        .compatible = "huawei,ov20880",
        .data = &s_ov20880.intf,
    },
    {
    },
};

MODULE_DEVICE_TABLE(of, s_ov20880_dt_match);

struct platform_driver
s_ov20880_driver =
{
    .driver =
    {
        .name = "huawei,ov20880",
        .owner = THIS_MODULE,
        .of_match_table = s_ov20880_dt_match,
    },
};

char const* ov20880_get_name(hwsensor_intf_t* si)
{
    sensor_t* sensor = NULL;

    if (NULL == si) {
        cam_err("%s. si is NULL.", __func__);
        return NULL;
    }

    sensor = I2S(si);
    return sensor->board_info->name;
}

int ov20880_power_up(hwsensor_intf_t* si)
{
    int ret = 0;
    sensor_t* sensor = NULL;

    if (NULL == si) {
        cam_err("%s. si is NULL.", __func__);
        return -EINVAL;
    }

    sensor = I2S(si);
    cam_info("enter %s. index = %d name = %s", __func__, sensor->board_info->sensor_index, sensor->board_info->name);
    ret = hw_sensor_power_up_config(s_ov20880.dev, sensor->board_info);
    if (0 == ret ){
        cam_info("%s. power up config success.", __func__);
    }else{
        cam_err("%s. power up config fail.", __func__);
        return ret;
    }
    if (hw_is_fpga_board()) {
        ret = do_sensor_power_on(sensor->board_info->sensor_index, sensor->board_info->name);
    } else {
        ret = hw_sensor_power_up(sensor);
    }
    if (0 == ret )
    {
        cam_info("%s. power up sensor success.", __func__);
    }
    else
    {
        cam_err("%s. power up sensor fail.", __func__);
    }
    return ret;
}

int ov20880_power_down(hwsensor_intf_t* si)
{
    int ret = 0;
    sensor_t* sensor = NULL;

    if (NULL == si) {
        cam_err("%s. si is NULL.", __func__);
        return -EINVAL;
    }

    sensor = I2S(si);
    cam_info("enter %s. index = %d name = %s", __func__, sensor->board_info->sensor_index, sensor->board_info->name);
    if (hw_is_fpga_board()) {
        ret = do_sensor_power_off(sensor->board_info->sensor_index, sensor->board_info->name);
    } else {
        ret = hw_sensor_power_down(sensor);
    }
    if (0 == ret )
    {
        cam_info("%s. power down sensor success.", __func__);
    }
    else
    {
        cam_err("%s. power down sensor fail.", __func__);
    }
    hw_sensor_power_down_config(sensor->board_info);
    return ret;
}

int ov20880_csi_enable(hwsensor_intf_t* si)
{
    return 0;
}

int ov20880_csi_disable(hwsensor_intf_t* si)
{
    return 0;
}

int ov20880_match_id(hwsensor_intf_t* si, void * data)
{
    sensor_t* sensor = NULL;
    struct sensor_cfg_data *cdata = NULL;

    cam_info("%s enter.", __func__);

    if (NULL == si) {
        cam_err("%s. si is NULL.", __func__);
        return -EINVAL;
    }

    sensor = I2S(si);
    cdata  = (struct sensor_cfg_data *)data;
    cdata->data = sensor->board_info->sensor_index;

    cam_info("%s name:%s", __func__, sensor->board_info->name);
    return 0;

}

static hwsensor_vtbl_t
s_ov20880_vtbl =
{
    .get_name = ov20880_get_name,
    .config = ov20880_config,
    .power_up = ov20880_power_up,
    .power_down = ov20880_power_down,
    .match_id = ov20880_match_id,
    .csi_enable = ov20880_csi_enable,
    .csi_disable = ov20880_csi_disable,
};

int
ov20880_config(
        hwsensor_intf_t* si,
        void  *argp)
{
    struct sensor_cfg_data *data;
    int ret =0;

    if (NULL == si || NULL == argp){
        cam_err("%s : si or argp is null", __func__);
        return -EINVAL;
    }

    data = (struct sensor_cfg_data *)argp;
    cam_debug("ov20880 cfgtype = %d",data->cfgtype);
    switch(data->cfgtype){
        case SEN_CONFIG_POWER_ON:
        if (!s_ov20880_power_on)
        {
            ret = si->vtbl->power_up(si);
            s_ov20880_power_on = true;
        }
            break;
        case SEN_CONFIG_POWER_OFF:
        if (s_ov20880_power_on)
        {
            ret = si->vtbl->power_down(si);
            s_ov20880_power_on = false;
        }
            break;
        case SEN_CONFIG_WRITE_REG:
            break;
        case SEN_CONFIG_READ_REG:
            break;
        case SEN_CONFIG_WRITE_REG_SETTINGS:
            break;
        case SEN_CONFIG_READ_REG_SETTINGS:
            break;
        case SEN_CONFIG_ENABLE_CSI:
            break;
        case SEN_CONFIG_DISABLE_CSI:
            break;
        case SEN_CONFIG_MATCH_ID:
            ret = si->vtbl->match_id(si,argp);
            break;
        default:
            cam_err("%s cfgtype(%d) is error", __func__, data->cfgtype);
            break;
    }
    return ret;
}

int32_t
ov20880_platform_probe(
        struct platform_device* pdev)
{
    int rc = 0;
    cam_notice("enter %s",__func__);
    if (pdev->dev.of_node) {
        rc = hw_sensor_get_dt_data(pdev, &s_ov20880);
        if (rc < 0) {
            cam_err("%s failed line %d\n", __func__, __LINE__);
            goto ov20880_sensor_probe_fail;
        }
    } else {
        cam_err("%s ov20880 of_node is NULL.\n", __func__);
        goto ov20880_sensor_probe_fail;
    }

    s_ov20880.dev = &pdev->dev;

    rc = hwsensor_register(pdev, &s_ov20880.intf);
    if (rc < 0)
    {
        cam_err("%s hwsensor_register fail.\n", __func__);
        goto ov20880_sensor_probe_fail;
    }
    rc = rpmsg_sensor_register(pdev, (void*)&s_ov20880);
    if (rc < 0)
    {
        cam_err("%s rpmsg_sensor_register fail.\n", __func__);
    }

ov20880_sensor_probe_fail:
    return rc;
}

int __init
ov20880_init_module(void)
{
    cam_notice("enter %s",__func__);
    return platform_driver_probe(&s_ov20880_driver,
            ov20880_platform_probe);
}

void __exit
ov20880_exit_module(void)
{
    rpmsg_sensor_unregister((void*)&s_ov20880);
    hwsensor_unregister(&s_ov20880.intf);
    platform_driver_unregister(&s_ov20880_driver);
}
//lint -restore

/*lint -e528 -esym(528,*)*/
module_init(ov20880_init_module);
module_exit(ov20880_exit_module);
/*lint -e528 +esym(528,*)*/
/*lint -e753 -esym(753,*)*/
MODULE_DESCRIPTION("ov20880");
MODULE_LICENSE("GPL v2");
/*lint -e753 +esym(753,*)*/
