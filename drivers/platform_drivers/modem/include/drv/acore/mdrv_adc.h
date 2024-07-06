/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may
 * *    be used to endorse or promote products derived from this software
 * *    without specific prior written permission.
 *
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/**
 * @brief   adc模块在acore上的对外头文件
 * @file    mdrv_adc.h
 * @version v1.0
 * @date    2019.08.20
 * @note    修改记录(版本号|修订日期|说明)
 * <ul><li>v1.0|xxx.xx.xx|创建文件</li></ul>
 * @since
 */
#ifndef __MDRV_ADC_H__
#define __MDRV_ADC_H__

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
     *                           Attention                           *
* Description : Driver for adc
* Core        : Acore、Ccore、ll1c、mcore
* Header File : the following head files need to be modified at the same time
*             : /acore/mdrv_adc.h
*             : /ccore/mdrv_adc.h
              : /ll1c/mdrv_adc.h
              : /mcore/mdrv_adc.h
              : /dsp/mdrv_adc.h
******************************************************************************/
/**
 * @brief 共享区域数据边界魔幻数
 */
#define ADC_MAGIC_DATA (0x5A5A5A5A)

/**
 * @brief ADC错误码枚举
 *
 */
typedef enum adc_err_code {
    ADC_TRY_LOCK_ERR = -100,
} adc_err_code_e;

/**
 * @brief 支持的物理通道号列表
 */
typedef enum adc_channel_id {
    ADC_CHANNEL_MIN = 0, /**< 0 acore */
    /* HKADC */
    HKADC_CHANNEL_MIN = ADC_CHANNEL_MIN, /**< 0 acore */
    HKADC_CHANNEL_0 = HKADC_CHANNEL_MIN, /**< 0 acore */
    HKADC_CHANNEL_1,                     /**< 1 acore */
    HKADC_CHANNEL_2,                     /**< 2 acore */
    HKADC_CHANNEL_3,                     /**< 3 acore */
    HKADC_CHANNEL_4,                     /**< 4 acore */
    HKADC_CHANNEL_5,                     /**< 5 acore */
    HKADC_CHANNEL_6,                     /**< 6 acore */
    HKADC_CHANNEL_7,                     /**< 7 acore */
    HKADC_CHANNEL_8,                     /**< 8 acore */
    HKADC_CHANNEL_9,                     /**< 9 acore */
    HKADC_CHANNEL_10,                    /**< 10 acore */
    HKADC_CHANNEL_11,                    /**< 11 acore */
    HKADC_CHANNEL_12,                    /**< 12 acore */
    HKADC_CHANNEL_13,                    /**< 13 acore */
    HKADC_CHANNEL_14,                    /**< 14 acore */
    HKADC_CHANNEL_MAX,                   /**< 15 acore */
    /* HKADC END */
    /* XOADC */
    XOADC_CHANNEL_MIN = HKADC_CHANNEL_MAX, /**< 15 acore */
    XOADC_CHANNEL_0 = XOADC_CHANNEL_MIN,   /**< 15 acore */
    XOADC_CHANNEL_MAX,                     /**< 16 acore */
    /* XOADC END */
    ADC_CHANNEL_MAX = XOADC_CHANNEL_MAX, /**< 16 acore */
    ADC_CHANNEL_NUM = ADC_CHANNEL_MAX,   /**< 16 acore */
} adc_channel_id_e;
/**
 * @brief adc信息结构体
 */
typedef struct adc_data {
    unsigned short code;      /**< adc转换的码值 */
    unsigned short code_r;    /**< adc转换的码值按位取反 */
    unsigned short voltage;   /**< adc转换的电压值 */
    unsigned short voltage_r; /**< adc转换的电压值按位取反 */
} adc_data_s;

/**
 * @brief 共享区域数据排布结构体
 */
typedef struct adc_data_shm {
    unsigned int magic_start;              /**< 其值为ADC_MAGIC_DATA */
    struct adc_data data[ADC_CHANNEL_NUM]; /**< 各通道的adc信息 */
    unsigned int magic_end;                /**< 其值为ADC_MAGIC_DATA */
} adc_data_shm_s;

/**
 * @brief 支持的逻辑通道号列表
 */
typedef enum adc_logic_channel {
    ADC_LOGIC_CHANNEL_MIN = 0,         /* ADC逻辑通道最小值 */
    ADC_LOGIC_CHANNEL_BATTERY = 0,     /* 电池温度检测 */
    ADC_LOGIC_CHANNEL_PA0 = 1,         /* PA0温度检测 */
    ADC_LOGIC_CHANNEL_PA1 = 2,         /* PA1温度检测 */
    ADC_LOGIC_CHANNEL_XO = 3,          /* XO温度检测 */
    ADC_LOGIC_CHANNEL_PA2 = 4,         /* PA2温度检测 */
    ADC_LOGIC_CHANNEL_PA3 = 5,         /* PA3温度检测 */
    ADC_LOGIC_CHANNEL_SIM_CARD = 6,    /* SIM卡温度检测 */
    ADC_LOGIC_CHANNEL_FLASH = 7,       /* FLASH温度检测 */
    ADC_LOGIC_CHANNEL_USB = 8,         /* USB温度检测 */
    ADC_LOGIC_CHANNEL_SURFACE = 9,     /* USB温度检测 */
    ADC_LOGIC_CHANNEL_BAT_ID = 10,     /* 电池厂家ID检测 */
    ADC_LOGIC_CHANNEL_CRADLE_ID = 11,  /* 充电座ID检测 */
    ADC_LOGIC_CHANNEL_BAT_ET = 12,     /* 电池电压检测 */
    ADC_LOGIC_CHANNEL_WIFI = 13,       /* 2.4GWIFI温度检测 */
    ADC_LOGIC_CHANNEL_AC_WIFI = 14,    /* 5G WIFI温度检测 */
    ADC_LOGIC_CHANNEL_BASE_MAX = 19,   /* MODEM基线结尾 */
    ADC_LOGIC_CHANNEL_CUST_BEGIN = 20, /* 产品定制开头 */
    ADC_LOGIC_CHANNEL_MAX = 32 /* 逻辑通道最大值,该枚举值用于判断逻辑通道是否符合要求 */
} adc_logic_channel_e;

/**
 * @brief ADC数据获取方式
 */
typedef enum adc_get_mode {
    ADC_GET_ICC = 0, /**< icc通信方式,实时获取 */
    ADC_GET_SYNC = 0, /**< 实时获取,后续会收编ADC_GET_ICC */
    ADC_GET_SHM,     /**< 共享区域方式,延时获取 */
    ADC_GET_ASYNC = ADC_GET_SHM, /**< 延时获取,后续会收编ADC_GET_SHM */
} adc_get_mode_e;

/**
 * @brief ADC转换结构
 */
typedef struct adc_cvt {
    unsigned short code;    /**< adc转换的码值 */
    unsigned short voltage; /**< adc转换的电压值 */
    int temperature;        /**< adc转换的温度值 */
} adc_cvt_s;

typedef enum tsensor_module_id {
    TSENSOR_ID = 0x0, /**< 温度获取,tsensor id枚举值 */
    HKADC_ID,         /**< 温度获取,hkadc   id枚举值 */
    MODULE_ID_MAX,
} tsensor_module_id_e;

typedef struct tsensor_param {
    unsigned int channel;
    unsigned int mode;
} tsensor_param_s;

/**
 * @brief 获取平台温度接口（包括tsensor和adc）
 *
 * @par 描述:
 * 获取平台温度接口（包括tsensor和adc）
 *
 * @attention
 * <ul><li>tsensor时电压码值和反码值为0。</li></ul>
 *
 * @param[in]  module_id   类型枚举变量，其取值范围参见tsensor_module_id_e，
 * @param[in]  channel_id  物理通道号。
 * @param[in]  cvt         类型枚举变量，对应通道的电压码值、电压反码值、温度值
 *
 * @retval 0，表示函数执行成功。
 * @retval ！=0，表示函数执行失败。

 * @par 依赖:
 * <ul><li>mdrv_adc.h：该接口声明所在的头文件。</li></ul>
 *
 * @see tsensor_module_id_e adc_cvt_s
 */
int mdrv_get_temperature_info(tsensor_module_id_e module_id, int channel_id, adc_cvt_s *cvt);

/**
 * @brief 将逻辑通道号转换为物理通道号。
 *
 * @par 描述:
 * 将逻辑通道号转换为物理通道号。
 *
 * @param[in]  logic_channel_id   类型枚举变量，逻辑通道号其取值范围参见adc_logic_channel_e，
 * 取值区间[ADC_LOGIC_CHANNEL_XO, ADC_LOGIC_CHANNEL_MAX)，终端可根据具体
 * 需求自行增加所支持的逻辑通道号。
 *
 * @retval <0，表示函数执行失败。
 * @retval >=0，表示函数执行成功，其值表示逻辑通道号所对应的物理通道号。
 *
 * @attention
 * <ul><li>当调用该函数失败时请打印该函数返回值，便于问题定位。</li></ul>
 *
 * @par 依赖:
 * <ul><li>mdrv_adc.h：该接口声明所在的头文件。</li></ul>
 *
 * @see adc_logic_channel_e
 */
int mdrv_adc_logic2phy(adc_logic_channel_e logic_channel_id);

/**
 * @brief 获取物理通道号为phy_channel_id的ADC转换码值、电压值、温度值
 *
 * @par 描述:
 * 获取物理通道号为phy_channel_id的ADC转换码值、电压值、温度值
 *
 * @param[in]  phy_channel_id    物理通道号，取值范围参考adc_channel_id_e
 * @param[in]  mode              指定获取ADC转换码值、电压值、温度值的方式，其取值参见
 * 枚举变量adc_get_mode_e。
 * @param[out] cvt               获取的ADC转换码值、电压值、温度值等结构体信息。
 *
 * @retval 0，表示函数执行成功。
 * @retval ！=0，表示函数执行失败，其中ADC_TRY_LOCK_ERR（在adc_err_code_e定义），表示尝试获取锁失败，该错误码使用者只能使用定义的枚举，不能使用数字。
 *
 * @attention
 * <ul><li>当调用该函数失败时请打印该函数返回值，便于问题定位。</li></ul>
 * <ul><li>错误码只能使用adc_err_code_e中定义的枚举，不能使用数字。</li></ul>
 *
 * @par 依赖:
 * <ul><li>mdrv_adc.h：该接口声明所在的头文件。</li></ul>
 *
 * @see adc_channel_id_e adc_get_mode_e adc_cvt_s adc_err_code_e
 */
int mdrv_adc_get(int phy_channel_id, adc_get_mode_e mode, adc_cvt_s *cvt);
/*****************************************************************************
      *                        Attention   END                        *
 *****************************************************************************/
#ifdef __cplusplus
}
#endif

#endif
