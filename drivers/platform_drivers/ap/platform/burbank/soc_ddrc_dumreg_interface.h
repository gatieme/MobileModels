#ifndef __SOC_DDRC_DUMREG_INTERFACE_H__
#define __SOC_DDRC_DUMREG_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_DDRC_DUMREG_DDR_IOTEST_CTRL0_ADDR(base) ((base) + (0xf00UL))
#define SOC_DDRC_DUMREG_DDR_IOTEST_CTRL1_ADDR(base) ((base) + (0xf04UL))
#define SOC_DDRC_DUMREG_DDR_IETEST_CTRL0_ADDR(base) ((base) + (0xf08UL))
#define SOC_DDRC_DUMREG_DDR_IETEST_CTRL1_ADDR(base) ((base) + (0xf0CUL))
#define SOC_DDRC_DUMREG_DDR_OUT_CTRL0_ADDR(base) ((base) + (0xf10UL))
#define SOC_DDRC_DUMREG_DDR_OUT_CTRL1_ADDR(base) ((base) + (0xf14UL))
#define SOC_DDRC_DUMREG_DDR_OE_CTRL0_ADDR(base) ((base) + (0xf18UL))
#define SOC_DDRC_DUMREG_DDR_OE_CTRL1_ADDR(base) ((base) + (0xf1CUL))
#define SOC_DDRC_DUMREG_DDR_IE_CTRL0_ADDR(base) ((base) + (0xf20UL))
#define SOC_DDRC_DUMREG_DDR_IE_CTRL1_ADDR(base) ((base) + (0xf24UL))
#define SOC_DDRC_DUMREG_DDR_NE_CTRL0_ADDR(base) ((base) + (0xf28UL))
#define SOC_DDRC_DUMREG_DDR_NE_CTRL1_ADDR(base) ((base) + (0xf2CUL))
#define SOC_DDRC_DUMREG_DDR_ODTTEST_CTRL0_ADDR(base) ((base) + (0xf30UL))
#define SOC_DDRC_DUMREG_DDR_ODTTEST_CTRL1_ADDR(base) ((base) + (0xf34UL))
#define SOC_DDRC_DUMREG_DDR_ODTEN_CTRL0_ADDR(base) ((base) + (0xf38UL))
#define SOC_DDRC_DUMREG_DDR_ODTEN_CTRL1_ADDR(base) ((base) + (0xf3CUL))
#define SOC_DDRC_DUMREG_DDR_IOTST_I_STAT0_ADDR(base) ((base) + (0xf40UL))
#define SOC_DDRC_DUMREG_DDR_IOTST_I_STAT1_ADDR(base) ((base) + (0xf44UL))
#define SOC_DDRC_DUMREG_DUM_REG_CTRL_ADDR(base) ((base) + (0xf4cUL))
#define SOC_DDRC_DUMREG_PASENSOR_CTRL0_ADDR(base) ((base) + (0xf50UL))
#define SOC_DDRC_DUMREG_PASENSOR_CTRL1_ADDR(base) ((base) + (0xf54UL))
#define SOC_DDRC_DUMREG_PASENSOR_STAT0_ADDR(base) ((base) + (0xf58UL))
#define SOC_DDRC_DUMREG_PASENSOR_STAT1_ADDR(base) ((base) + (0xf5CUL))
#define SOC_DDRC_DUMREG_PASENSOR_STAT2_ADDR(base) ((base) + (0xf60UL))
#define SOC_DDRC_DUMREG_DFX_STATUS0_ADDR(base) ((base) + (0xf64UL))
#define SOC_DDRC_DUMREG_DFX_STATUS1_ADDR(base) ((base) + (0xf68UL))
#define SOC_DDRC_DUMREG_DUMMY_RW0_ADDR(base) ((base) + (0xf6CUL))
#define SOC_DDRC_DUMREG_DUMMY_RW1_ADDR(base) ((base) + (0xf70UL))
#define SOC_DDRC_DUMREG_DDR_HPMX_CTRL_AND_STATUS_ADDR(base) ((base) + (0xfa0UL))
#define SOC_DDRC_DUMREG_DMC_SEC_LOCK_ADDR(base) ((base) + (0xfa8UL))
#define SOC_DDRC_DUMREG_DDRC_LP_WAITCFG_ADDR(base) ((base) + (0xfacUL))
#define SOC_DDRC_DUMREG_DMC_HIDDRPHY_REG_SLVERR_ADDR(base) ((base) + (0xfb0UL))
#define SOC_DDRC_DUMREG_DDR_HPM_CTRL_AND_STATUS_ADDR(base) ((base) + (0xfb4UL))
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL6_ADDR(base) ((base) + (0xfb8UL))
#define SOC_DDRC_DUMREG_DDRC_INBAND_ECC_CTRL_ADDR(base) ((base) + (0xfc0UL))
#define SOC_DDRC_DUMREG_DDRC_INBAND_ECC_INTMSK_ADDR(base) ((base) + (0xfc4UL))
#define SOC_DDRC_DUMREG_DDRC_INBAND_ECC_RINT_ADDR(base) ((base) + (0xfc8UL))
#define SOC_DDRC_DUMREG_DDRC_INBAND_ECC_INTSTS_ADDR(base) ((base) + (0xfccUL))
#define SOC_DDRC_DUMREG_DDRC_INBAND_ECC_INFO_INDEX_ADDR(base) ((base) + (0xfd0UL))
#define SOC_DDRC_DUMREG_DDRC_INBAND_ECC_INFO_ADDR(base) ((base) + (0xfd4UL))
#define SOC_DDRC_DUMREG_DBG_MODE_SEL_ADDR(base) ((base) + (0xfd8UL))
#define SOC_DDRC_DUMREG_DBG_MODE_OUT_UCE_TEST_POINT_ADDR(base) ((base) + (0xfdcUL))
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA0_ADDR(base) ((base) + (0xfe0UL))
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA1_ADDR(base) ((base) + (0xfe4UL))
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL5_ADDR(base) ((base) + (0xfe8UL))
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL4_ADDR(base) ((base) + (0xfecUL))
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL0_ADDR(base) ((base) + (0xff0UL))
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL1_ADDR(base) ((base) + (0xff4UL))
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL2_ADDR(base) ((base) + (0xff8UL))
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL3_ADDR(base) ((base) + (0xffcUL))
#else
#define SOC_DDRC_DUMREG_DDR_IOTEST_CTRL0_ADDR(base) ((base) + (0xf00))
#define SOC_DDRC_DUMREG_DDR_IOTEST_CTRL1_ADDR(base) ((base) + (0xf04))
#define SOC_DDRC_DUMREG_DDR_IETEST_CTRL0_ADDR(base) ((base) + (0xf08))
#define SOC_DDRC_DUMREG_DDR_IETEST_CTRL1_ADDR(base) ((base) + (0xf0C))
#define SOC_DDRC_DUMREG_DDR_OUT_CTRL0_ADDR(base) ((base) + (0xf10))
#define SOC_DDRC_DUMREG_DDR_OUT_CTRL1_ADDR(base) ((base) + (0xf14))
#define SOC_DDRC_DUMREG_DDR_OE_CTRL0_ADDR(base) ((base) + (0xf18))
#define SOC_DDRC_DUMREG_DDR_OE_CTRL1_ADDR(base) ((base) + (0xf1C))
#define SOC_DDRC_DUMREG_DDR_IE_CTRL0_ADDR(base) ((base) + (0xf20))
#define SOC_DDRC_DUMREG_DDR_IE_CTRL1_ADDR(base) ((base) + (0xf24))
#define SOC_DDRC_DUMREG_DDR_NE_CTRL0_ADDR(base) ((base) + (0xf28))
#define SOC_DDRC_DUMREG_DDR_NE_CTRL1_ADDR(base) ((base) + (0xf2C))
#define SOC_DDRC_DUMREG_DDR_ODTTEST_CTRL0_ADDR(base) ((base) + (0xf30))
#define SOC_DDRC_DUMREG_DDR_ODTTEST_CTRL1_ADDR(base) ((base) + (0xf34))
#define SOC_DDRC_DUMREG_DDR_ODTEN_CTRL0_ADDR(base) ((base) + (0xf38))
#define SOC_DDRC_DUMREG_DDR_ODTEN_CTRL1_ADDR(base) ((base) + (0xf3C))
#define SOC_DDRC_DUMREG_DDR_IOTST_I_STAT0_ADDR(base) ((base) + (0xf40))
#define SOC_DDRC_DUMREG_DDR_IOTST_I_STAT1_ADDR(base) ((base) + (0xf44))
#define SOC_DDRC_DUMREG_DUM_REG_CTRL_ADDR(base) ((base) + (0xf4c))
#define SOC_DDRC_DUMREG_PASENSOR_CTRL0_ADDR(base) ((base) + (0xf50))
#define SOC_DDRC_DUMREG_PASENSOR_CTRL1_ADDR(base) ((base) + (0xf54))
#define SOC_DDRC_DUMREG_PASENSOR_STAT0_ADDR(base) ((base) + (0xf58))
#define SOC_DDRC_DUMREG_PASENSOR_STAT1_ADDR(base) ((base) + (0xf5C))
#define SOC_DDRC_DUMREG_PASENSOR_STAT2_ADDR(base) ((base) + (0xf60))
#define SOC_DDRC_DUMREG_DFX_STATUS0_ADDR(base) ((base) + (0xf64))
#define SOC_DDRC_DUMREG_DFX_STATUS1_ADDR(base) ((base) + (0xf68))
#define SOC_DDRC_DUMREG_DUMMY_RW0_ADDR(base) ((base) + (0xf6C))
#define SOC_DDRC_DUMREG_DUMMY_RW1_ADDR(base) ((base) + (0xf70))
#define SOC_DDRC_DUMREG_DDR_HPMX_CTRL_AND_STATUS_ADDR(base) ((base) + (0xfa0))
#define SOC_DDRC_DUMREG_DMC_SEC_LOCK_ADDR(base) ((base) + (0xfa8))
#define SOC_DDRC_DUMREG_DDRC_LP_WAITCFG_ADDR(base) ((base) + (0xfac))
#define SOC_DDRC_DUMREG_DMC_HIDDRPHY_REG_SLVERR_ADDR(base) ((base) + (0xfb0))
#define SOC_DDRC_DUMREG_DDR_HPM_CTRL_AND_STATUS_ADDR(base) ((base) + (0xfb4))
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL6_ADDR(base) ((base) + (0xfb8))
#define SOC_DDRC_DUMREG_DDRC_INBAND_ECC_CTRL_ADDR(base) ((base) + (0xfc0))
#define SOC_DDRC_DUMREG_DDRC_INBAND_ECC_INTMSK_ADDR(base) ((base) + (0xfc4))
#define SOC_DDRC_DUMREG_DDRC_INBAND_ECC_RINT_ADDR(base) ((base) + (0xfc8))
#define SOC_DDRC_DUMREG_DDRC_INBAND_ECC_INTSTS_ADDR(base) ((base) + (0xfcc))
#define SOC_DDRC_DUMREG_DDRC_INBAND_ECC_INFO_INDEX_ADDR(base) ((base) + (0xfd0))
#define SOC_DDRC_DUMREG_DDRC_INBAND_ECC_INFO_ADDR(base) ((base) + (0xfd4))
#define SOC_DDRC_DUMREG_DBG_MODE_SEL_ADDR(base) ((base) + (0xfd8))
#define SOC_DDRC_DUMREG_DBG_MODE_OUT_UCE_TEST_POINT_ADDR(base) ((base) + (0xfdc))
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA0_ADDR(base) ((base) + (0xfe0))
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA1_ADDR(base) ((base) + (0xfe4))
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL5_ADDR(base) ((base) + (0xfe8))
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL4_ADDR(base) ((base) + (0xfec))
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL0_ADDR(base) ((base) + (0xff0))
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL1_ADDR(base) ((base) + (0xff4))
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL2_ADDR(base) ((base) + (0xff8))
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL3_ADDR(base) ((base) + (0xffc))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddrc_iotest_ctrl0 : 32;
    } reg;
} SOC_DDRC_DUMREG_DDR_IOTEST_CTRL0_UNION;
#endif
#define SOC_DDRC_DUMREG_DDR_IOTEST_CTRL0_ddrc_iotest_ctrl0_START (0)
#define SOC_DDRC_DUMREG_DDR_IOTEST_CTRL0_ddrc_iotest_ctrl0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddrc_iotest_ctrl1 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDRC_DUMREG_DDR_IOTEST_CTRL1_UNION;
#endif
#define SOC_DDRC_DUMREG_DDR_IOTEST_CTRL1_ddrc_iotest_ctrl1_START (0)
#define SOC_DDRC_DUMREG_DDR_IOTEST_CTRL1_ddrc_iotest_ctrl1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddrc_ietest_ctrl0 : 32;
    } reg;
} SOC_DDRC_DUMREG_DDR_IETEST_CTRL0_UNION;
#endif
#define SOC_DDRC_DUMREG_DDR_IETEST_CTRL0_ddrc_ietest_ctrl0_START (0)
#define SOC_DDRC_DUMREG_DDR_IETEST_CTRL0_ddrc_ietest_ctrl0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddrc_ietest_ctrl1 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDRC_DUMREG_DDR_IETEST_CTRL1_UNION;
#endif
#define SOC_DDRC_DUMREG_DDR_IETEST_CTRL1_ddrc_ietest_ctrl1_START (0)
#define SOC_DDRC_DUMREG_DDR_IETEST_CTRL1_ddrc_ietest_ctrl1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddrc_o_ctrl0 : 32;
    } reg;
} SOC_DDRC_DUMREG_DDR_OUT_CTRL0_UNION;
#endif
#define SOC_DDRC_DUMREG_DDR_OUT_CTRL0_ddrc_o_ctrl0_START (0)
#define SOC_DDRC_DUMREG_DDR_OUT_CTRL0_ddrc_o_ctrl0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddrc_o_ctrl1 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDRC_DUMREG_DDR_OUT_CTRL1_UNION;
#endif
#define SOC_DDRC_DUMREG_DDR_OUT_CTRL1_ddrc_o_ctrl1_START (0)
#define SOC_DDRC_DUMREG_DDR_OUT_CTRL1_ddrc_o_ctrl1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddrc_oe_ctrl0 : 32;
    } reg;
} SOC_DDRC_DUMREG_DDR_OE_CTRL0_UNION;
#endif
#define SOC_DDRC_DUMREG_DDR_OE_CTRL0_ddrc_oe_ctrl0_START (0)
#define SOC_DDRC_DUMREG_DDR_OE_CTRL0_ddrc_oe_ctrl0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddrc_oe_ctrl1 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDRC_DUMREG_DDR_OE_CTRL1_UNION;
#endif
#define SOC_DDRC_DUMREG_DDR_OE_CTRL1_ddrc_oe_ctrl1_START (0)
#define SOC_DDRC_DUMREG_DDR_OE_CTRL1_ddrc_oe_ctrl1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddrc_ie_ctrl0 : 32;
    } reg;
} SOC_DDRC_DUMREG_DDR_IE_CTRL0_UNION;
#endif
#define SOC_DDRC_DUMREG_DDR_IE_CTRL0_ddrc_ie_ctrl0_START (0)
#define SOC_DDRC_DUMREG_DDR_IE_CTRL0_ddrc_ie_ctrl0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddrc_ie_ctrl1 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDRC_DUMREG_DDR_IE_CTRL1_UNION;
#endif
#define SOC_DDRC_DUMREG_DDR_IE_CTRL1_ddrc_ie_ctrl1_START (0)
#define SOC_DDRC_DUMREG_DDR_IE_CTRL1_ddrc_ie_ctrl1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddrc_ne_ctrl0 : 32;
    } reg;
} SOC_DDRC_DUMREG_DDR_NE_CTRL0_UNION;
#endif
#define SOC_DDRC_DUMREG_DDR_NE_CTRL0_ddrc_ne_ctrl0_START (0)
#define SOC_DDRC_DUMREG_DDR_NE_CTRL0_ddrc_ne_ctrl0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddrc_ne_ctrl1 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDRC_DUMREG_DDR_NE_CTRL1_UNION;
#endif
#define SOC_DDRC_DUMREG_DDR_NE_CTRL1_ddrc_ne_ctrl1_START (0)
#define SOC_DDRC_DUMREG_DDR_NE_CTRL1_ddrc_ne_ctrl1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddrc_odttest_ctrl0 : 32;
    } reg;
} SOC_DDRC_DUMREG_DDR_ODTTEST_CTRL0_UNION;
#endif
#define SOC_DDRC_DUMREG_DDR_ODTTEST_CTRL0_ddrc_odttest_ctrl0_START (0)
#define SOC_DDRC_DUMREG_DDR_ODTTEST_CTRL0_ddrc_odttest_ctrl0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddrc_odttest_ctrl1 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDRC_DUMREG_DDR_ODTTEST_CTRL1_UNION;
#endif
#define SOC_DDRC_DUMREG_DDR_ODTTEST_CTRL1_ddrc_odttest_ctrl1_START (0)
#define SOC_DDRC_DUMREG_DDR_ODTTEST_CTRL1_ddrc_odttest_ctrl1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddrc_odten_ctrl0 : 32;
    } reg;
} SOC_DDRC_DUMREG_DDR_ODTEN_CTRL0_UNION;
#endif
#define SOC_DDRC_DUMREG_DDR_ODTEN_CTRL0_ddrc_odten_ctrl0_START (0)
#define SOC_DDRC_DUMREG_DDR_ODTEN_CTRL0_ddrc_odten_ctrl0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddrc_odten_ctrl1 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDRC_DUMREG_DDR_ODTEN_CTRL1_UNION;
#endif
#define SOC_DDRC_DUMREG_DDR_ODTEN_CTRL1_ddrc_odten_ctrl1_START (0)
#define SOC_DDRC_DUMREG_DDR_ODTEN_CTRL1_ddrc_odten_ctrl1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddrc_iotst_i_stat0 : 32;
    } reg;
} SOC_DDRC_DUMREG_DDR_IOTST_I_STAT0_UNION;
#endif
#define SOC_DDRC_DUMREG_DDR_IOTST_I_STAT0_ddrc_iotst_i_stat0_START (0)
#define SOC_DDRC_DUMREG_DDR_IOTST_I_STAT0_ddrc_iotst_i_stat0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddrc_iotst_i_stat1 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDRC_DUMREG_DDR_IOTST_I_STAT1_UNION;
#endif
#define SOC_DDRC_DUMREG_DDR_IOTST_I_STAT1_ddrc_iotst_i_stat1_START (0)
#define SOC_DDRC_DUMREG_DDR_IOTST_I_STAT1_ddrc_iotst_i_stat1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int auto_pclken_bypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDRC_DUMREG_DUM_REG_CTRL_UNION;
#endif
#define SOC_DDRC_DUMREG_DUM_REG_CTRL_auto_pclken_bypass_START (0)
#define SOC_DDRC_DUMREG_DUM_REG_CTRL_auto_pclken_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pasensor_cfg_vaid : 1;
        unsigned int pasensor_cmd : 2;
        unsigned int pasensor_en : 1;
        unsigned int pasensor_ctrl : 6;
        unsigned int reserved : 22;
    } reg;
} SOC_DDRC_DUMREG_PASENSOR_CTRL0_UNION;
#endif
#define SOC_DDRC_DUMREG_PASENSOR_CTRL0_pasensor_cfg_vaid_START (0)
#define SOC_DDRC_DUMREG_PASENSOR_CTRL0_pasensor_cfg_vaid_END (0)
#define SOC_DDRC_DUMREG_PASENSOR_CTRL0_pasensor_cmd_START (1)
#define SOC_DDRC_DUMREG_PASENSOR_CTRL0_pasensor_cmd_END (2)
#define SOC_DDRC_DUMREG_PASENSOR_CTRL0_pasensor_en_START (3)
#define SOC_DDRC_DUMREG_PASENSOR_CTRL0_pasensor_en_END (3)
#define SOC_DDRC_DUMREG_PASENSOR_CTRL0_pasensor_ctrl_START (4)
#define SOC_DDRC_DUMREG_PASENSOR_CTRL0_pasensor_ctrl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pasensor_msg : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDRC_DUMREG_PASENSOR_CTRL1_UNION;
#endif
#define SOC_DDRC_DUMREG_PASENSOR_CTRL1_pasensor_msg_START (0)
#define SOC_DDRC_DUMREG_PASENSOR_CTRL1_pasensor_msg_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pasensor_vaid : 1;
        unsigned int pasensor_cfg_ready : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DDRC_DUMREG_PASENSOR_STAT0_UNION;
#endif
#define SOC_DDRC_DUMREG_PASENSOR_STAT0_pasensor_vaid_START (0)
#define SOC_DDRC_DUMREG_PASENSOR_STAT0_pasensor_vaid_END (0)
#define SOC_DDRC_DUMREG_PASENSOR_STAT0_pasensor_cfg_ready_START (1)
#define SOC_DDRC_DUMREG_PASENSOR_STAT0_pasensor_cfg_ready_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pasensor_nbti_a_data : 9;
        unsigned int reserved_0 : 7;
        unsigned int pasensor_nbti_o_data : 9;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_DDRC_DUMREG_PASENSOR_STAT1_UNION;
#endif
#define SOC_DDRC_DUMREG_PASENSOR_STAT1_pasensor_nbti_a_data_START (0)
#define SOC_DDRC_DUMREG_PASENSOR_STAT1_pasensor_nbti_a_data_END (8)
#define SOC_DDRC_DUMREG_PASENSOR_STAT1_pasensor_nbti_o_data_START (16)
#define SOC_DDRC_DUMREG_PASENSOR_STAT1_pasensor_nbti_o_data_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pasensor_hci_a_data : 9;
        unsigned int reserved_0 : 7;
        unsigned int pasensor_hci_o_data : 9;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_DDRC_DUMREG_PASENSOR_STAT2_UNION;
#endif
#define SOC_DDRC_DUMREG_PASENSOR_STAT2_pasensor_hci_a_data_START (0)
#define SOC_DDRC_DUMREG_PASENSOR_STAT2_pasensor_hci_a_data_END (8)
#define SOC_DDRC_DUMREG_PASENSOR_STAT2_pasensor_hci_o_data_START (16)
#define SOC_DDRC_DUMREG_PASENSOR_STAT2_pasensor_hci_o_data_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_status_inecc : 9;
        unsigned int reserved_0 : 3;
        unsigned int dfx_status_abrg_mst : 8;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_DDRC_DUMREG_DFX_STATUS0_UNION;
#endif
#define SOC_DDRC_DUMREG_DFX_STATUS0_dfx_status_inecc_START (0)
#define SOC_DDRC_DUMREG_DFX_STATUS0_dfx_status_inecc_END (8)
#define SOC_DDRC_DUMREG_DFX_STATUS0_dfx_status_abrg_mst_START (12)
#define SOC_DDRC_DUMREG_DFX_STATUS0_dfx_status_abrg_mst_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_status_dmc_wrap : 25;
        unsigned int reserved : 7;
    } reg;
} SOC_DDRC_DUMREG_DFX_STATUS1_UNION;
#endif
#define SOC_DDRC_DUMREG_DFX_STATUS1_dfx_status_dmc_wrap_START (0)
#define SOC_DDRC_DUMREG_DFX_STATUS1_dfx_status_dmc_wrap_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dummy_rw0 : 32;
    } reg;
} SOC_DDRC_DUMREG_DUMMY_RW0_UNION;
#endif
#define SOC_DDRC_DUMREG_DUMMY_RW0_dummy_rw0_START (0)
#define SOC_DDRC_DUMREG_DUMMY_RW0_dummy_rw0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dummy_rw1 : 32;
    } reg;
} SOC_DDRC_DUMREG_DUMMY_RW1_UNION;
#endif
#define SOC_DDRC_DUMREG_DUMMY_RW1_dummy_rw1_START (0)
#define SOC_DDRC_DUMREG_DUMMY_RW1_dummy_rw1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hpmx_en : 1;
        unsigned int reserved_0 : 15;
        unsigned int hpmx_opc_vld : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpmx_opc : 10;
        unsigned int dummy_rw1 : 2;
    } reg;
} SOC_DDRC_DUMREG_DDR_HPMX_CTRL_AND_STATUS_UNION;
#endif
#define SOC_DDRC_DUMREG_DDR_HPMX_CTRL_AND_STATUS_hpmx_en_START (0)
#define SOC_DDRC_DUMREG_DDR_HPMX_CTRL_AND_STATUS_hpmx_en_END (0)
#define SOC_DDRC_DUMREG_DDR_HPMX_CTRL_AND_STATUS_hpmx_opc_vld_START (16)
#define SOC_DDRC_DUMREG_DDR_HPMX_CTRL_AND_STATUS_hpmx_opc_vld_END (16)
#define SOC_DDRC_DUMREG_DDR_HPMX_CTRL_AND_STATUS_hpmx_opc_START (20)
#define SOC_DDRC_DUMREG_DDR_HPMX_CTRL_AND_STATUS_hpmx_opc_END (29)
#define SOC_DDRC_DUMREG_DDR_HPMX_CTRL_AND_STATUS_dummy_rw1_START (30)
#define SOC_DDRC_DUMREG_DDR_HPMX_CTRL_AND_STATUS_dummy_rw1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dmc_sec_lock : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDRC_DUMREG_DMC_SEC_LOCK_UNION;
#endif
#define SOC_DDRC_DUMREG_DMC_SEC_LOCK_dmc_sec_lock_START (0)
#define SOC_DDRC_DUMREG_DMC_SEC_LOCK_dmc_sec_lock_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddrc_lp_waitcfg_in : 10;
        unsigned int ddrc_lp_waitcfg_out : 10;
        unsigned int reserved : 12;
    } reg;
} SOC_DDRC_DUMREG_DDRC_LP_WAITCFG_UNION;
#endif
#define SOC_DDRC_DUMREG_DDRC_LP_WAITCFG_ddrc_lp_waitcfg_in_START (0)
#define SOC_DDRC_DUMREG_DDRC_LP_WAITCFG_ddrc_lp_waitcfg_in_END (9)
#define SOC_DDRC_DUMREG_DDRC_LP_WAITCFG_ddrc_lp_waitcfg_out_START (10)
#define SOC_DDRC_DUMREG_DDRC_LP_WAITCFG_ddrc_lp_waitcfg_out_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dmc_hiddrphy_reg_slverr : 1;
        unsigned int dmc_reg_eps_slverr : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DDRC_DUMREG_DMC_HIDDRPHY_REG_SLVERR_UNION;
#endif
#define SOC_DDRC_DUMREG_DMC_HIDDRPHY_REG_SLVERR_dmc_hiddrphy_reg_slverr_START (0)
#define SOC_DDRC_DUMREG_DMC_HIDDRPHY_REG_SLVERR_dmc_hiddrphy_reg_slverr_END (0)
#define SOC_DDRC_DUMREG_DMC_HIDDRPHY_REG_SLVERR_dmc_reg_eps_slverr_START (1)
#define SOC_DDRC_DUMREG_DMC_HIDDRPHY_REG_SLVERR_dmc_reg_eps_slverr_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hpm_en : 1;
        unsigned int reserved_0 : 3;
        unsigned int hpm_clk_div : 6;
        unsigned int reserved_1 : 2;
        unsigned int reserved_2 : 4;
        unsigned int hpm_opc_vld : 1;
        unsigned int reserved_3 : 3;
        unsigned int hpm_opc : 10;
        unsigned int reserved_4 : 2;
    } reg;
} SOC_DDRC_DUMREG_DDR_HPM_CTRL_AND_STATUS_UNION;
#endif
#define SOC_DDRC_DUMREG_DDR_HPM_CTRL_AND_STATUS_hpm_en_START (0)
#define SOC_DDRC_DUMREG_DDR_HPM_CTRL_AND_STATUS_hpm_en_END (0)
#define SOC_DDRC_DUMREG_DDR_HPM_CTRL_AND_STATUS_hpm_clk_div_START (4)
#define SOC_DDRC_DUMREG_DDR_HPM_CTRL_AND_STATUS_hpm_clk_div_END (9)
#define SOC_DDRC_DUMREG_DDR_HPM_CTRL_AND_STATUS_hpm_opc_vld_START (16)
#define SOC_DDRC_DUMREG_DDR_HPM_CTRL_AND_STATUS_hpm_opc_vld_END (16)
#define SOC_DDRC_DUMREG_DDR_HPM_CTRL_AND_STATUS_hpm_opc_START (20)
#define SOC_DDRC_DUMREG_DDR_HPM_CTRL_AND_STATUS_hpm_opc_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_ddrphy_ref_b_dmc_cfg : 1;
        unsigned int gt_clk_dmc_hpm_out : 1;
        unsigned int gt_clk_dmc_pasensor : 1;
        unsigned int gt_clk_dfi_pasensor : 1;
        unsigned int div_clk_ddrphy_ref_b_inuse : 1;
        unsigned int sel_dfi_pasensor_mux : 1;
        unsigned int ip_rst_dmc_pasendor : 1;
        unsigned int ip_rst_dmc_hpm : 1;
        unsigned int dmc_autogt_cnt_cfg : 6;
        unsigned int reserved : 2;
        unsigned int clk_wr_en : 16;
    } reg;
} SOC_DDRC_DUMREG_DDRC_COMMON_CTRL6_UNION;
#endif
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL6_gt_clk_ddrphy_ref_b_dmc_cfg_START (0)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL6_gt_clk_ddrphy_ref_b_dmc_cfg_END (0)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL6_gt_clk_dmc_hpm_out_START (1)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL6_gt_clk_dmc_hpm_out_END (1)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL6_gt_clk_dmc_pasensor_START (2)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL6_gt_clk_dmc_pasensor_END (2)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL6_gt_clk_dfi_pasensor_START (3)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL6_gt_clk_dfi_pasensor_END (3)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL6_div_clk_ddrphy_ref_b_inuse_START (4)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL6_div_clk_ddrphy_ref_b_inuse_END (4)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL6_sel_dfi_pasensor_mux_START (5)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL6_sel_dfi_pasensor_mux_END (5)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL6_ip_rst_dmc_pasendor_START (6)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL6_ip_rst_dmc_pasendor_END (6)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL6_ip_rst_dmc_hpm_START (7)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL6_ip_rst_dmc_hpm_END (7)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL6_dmc_autogt_cnt_cfg_START (8)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL6_dmc_autogt_cnt_cfg_END (13)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL6_clk_wr_en_START (16)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL6_clk_wr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int inband_ecc_en : 1;
        unsigned int inband_ecc_mode : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DDRC_DUMREG_DDRC_INBAND_ECC_CTRL_UNION;
#endif
#define SOC_DDRC_DUMREG_DDRC_INBAND_ECC_CTRL_inband_ecc_en_START (0)
#define SOC_DDRC_DUMREG_DDRC_INBAND_ECC_CTRL_inband_ecc_en_END (0)
#define SOC_DDRC_DUMREG_DDRC_INBAND_ECC_CTRL_inband_ecc_mode_START (1)
#define SOC_DDRC_DUMREG_DDRC_INBAND_ECC_CTRL_inband_ecc_mode_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int inband_ecc_err_intmask : 1;
        unsigned int hseldefault_err_intmask : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DDRC_DUMREG_DDRC_INBAND_ECC_INTMSK_UNION;
#endif
#define SOC_DDRC_DUMREG_DDRC_INBAND_ECC_INTMSK_inband_ecc_err_intmask_START (0)
#define SOC_DDRC_DUMREG_DDRC_INBAND_ECC_INTMSK_inband_ecc_err_intmask_END (0)
#define SOC_DDRC_DUMREG_DDRC_INBAND_ECC_INTMSK_hseldefault_err_intmask_START (1)
#define SOC_DDRC_DUMREG_DDRC_INBAND_ECC_INTMSK_hseldefault_err_intmask_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int inband_ecc_err_rint : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDRC_DUMREG_DDRC_INBAND_ECC_RINT_UNION;
#endif
#define SOC_DDRC_DUMREG_DDRC_INBAND_ECC_RINT_inband_ecc_err_rint_START (0)
#define SOC_DDRC_DUMREG_DDRC_INBAND_ECC_RINT_inband_ecc_err_rint_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int inband_ecc_err_intsts : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDRC_DUMREG_DDRC_INBAND_ECC_INTSTS_UNION;
#endif
#define SOC_DDRC_DUMREG_DDRC_INBAND_ECC_INTSTS_inband_ecc_err_intsts_START (0)
#define SOC_DDRC_DUMREG_DDRC_INBAND_ECC_INTSTS_inband_ecc_err_intsts_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int inband_ecc_info_index : 5;
        unsigned int inband_ecc_info_clr : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_DDRC_DUMREG_DDRC_INBAND_ECC_INFO_INDEX_UNION;
#endif
#define SOC_DDRC_DUMREG_DDRC_INBAND_ECC_INFO_INDEX_inband_ecc_info_index_START (0)
#define SOC_DDRC_DUMREG_DDRC_INBAND_ECC_INFO_INDEX_inband_ecc_info_index_END (4)
#define SOC_DDRC_DUMREG_DDRC_INBAND_ECC_INFO_INDEX_inband_ecc_info_clr_START (5)
#define SOC_DDRC_DUMREG_DDRC_INBAND_ECC_INFO_INDEX_inband_ecc_info_clr_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int inband_ecc_info : 32;
    } reg;
} SOC_DDRC_DUMREG_DDRC_INBAND_ECC_INFO_UNION;
#endif
#define SOC_DDRC_DUMREG_DDRC_INBAND_ECC_INFO_inband_ecc_info_START (0)
#define SOC_DDRC_DUMREG_DDRC_INBAND_ECC_INFO_inband_ecc_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_mode_sel : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_DDRC_DUMREG_DBG_MODE_SEL_UNION;
#endif
#define SOC_DDRC_DUMREG_DBG_MODE_SEL_dbg_mode_sel_START (0)
#define SOC_DDRC_DUMREG_DBG_MODE_SEL_dbg_mode_sel_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_mode_out : 16;
        unsigned int uce_test_point : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_DDRC_DUMREG_DBG_MODE_OUT_UCE_TEST_POINT_UNION;
#endif
#define SOC_DDRC_DUMREG_DBG_MODE_OUT_UCE_TEST_POINT_dbg_mode_out_START (0)
#define SOC_DDRC_DUMREG_DBG_MODE_OUT_UCE_TEST_POINT_dbg_mode_out_END (15)
#define SOC_DDRC_DUMREG_DBG_MODE_OUT_UCE_TEST_POINT_uce_test_point_START (16)
#define SOC_DDRC_DUMREG_DBG_MODE_OUT_UCE_TEST_POINT_uce_test_point_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int st_clk_p2p_m : 1;
        unsigned int reserved_0 : 1;
        unsigned int st_clk_pack_apb : 1;
        unsigned int st_clk_uce : 1;
        unsigned int st_clk_uce_bus : 1;
        unsigned int st_clk_dfi_pack : 1;
        unsigned int st_clk_dfi_dmc : 1;
        unsigned int st_clk_dmc_free : 1;
        unsigned int st_clk_uce_engine : 1;
        unsigned int reserved_1 : 4;
        unsigned int gt_clk_uce_subsys : 1;
        unsigned int swdone_clk_uce_subsys : 1;
        unsigned int st_clk_dfi_phy : 1;
        unsigned int reserved_2 : 1;
        unsigned int gt_auto_clk_ddrphy : 1;
        unsigned int st_clk_dfi_pack_on : 1;
        unsigned int st_clk_dfi_pasensor : 1;
        unsigned int reserved_3 : 5;
        unsigned int st_clk_dmc_pasensor : 1;
        unsigned int st_clk_dmc_hpm_out : 1;
        unsigned int reserved_4 : 5;
    } reg;
} SOC_DDRC_DUMREG_DDRC_COMMON_RDATA0_UNION;
#endif
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA0_st_clk_p2p_m_START (0)
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA0_st_clk_p2p_m_END (0)
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA0_st_clk_pack_apb_START (2)
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA0_st_clk_pack_apb_END (2)
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA0_st_clk_uce_START (3)
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA0_st_clk_uce_END (3)
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA0_st_clk_uce_bus_START (4)
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA0_st_clk_uce_bus_END (4)
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA0_st_clk_dfi_pack_START (5)
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA0_st_clk_dfi_pack_END (5)
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA0_st_clk_dfi_dmc_START (6)
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA0_st_clk_dfi_dmc_END (6)
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA0_st_clk_dmc_free_START (7)
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA0_st_clk_dmc_free_END (7)
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA0_st_clk_uce_engine_START (8)
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA0_st_clk_uce_engine_END (8)
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA0_gt_clk_uce_subsys_START (13)
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA0_gt_clk_uce_subsys_END (13)
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA0_swdone_clk_uce_subsys_START (14)
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA0_swdone_clk_uce_subsys_END (14)
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA0_st_clk_dfi_phy_START (15)
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA0_st_clk_dfi_phy_END (15)
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA0_gt_auto_clk_ddrphy_START (17)
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA0_gt_auto_clk_ddrphy_END (17)
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA0_st_clk_dfi_pack_on_START (18)
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA0_st_clk_dfi_pack_on_END (18)
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA0_st_clk_dfi_pasensor_START (19)
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA0_st_clk_dfi_pasensor_END (19)
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA0_st_clk_dmc_pasensor_START (25)
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA0_st_clk_dmc_pasensor_END (25)
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA0_st_clk_dmc_hpm_out_START (26)
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA0_st_clk_dmc_hpm_out_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int uce_m3_idle : 1;
        unsigned int uce_sys_idle : 1;
        unsigned int reserved_0 : 14;
        unsigned int reserved_1 : 4;
        unsigned int reserved_2 : 12;
    } reg;
} SOC_DDRC_DUMREG_DDRC_COMMON_RDATA1_UNION;
#endif
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA1_uce_m3_idle_START (0)
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA1_uce_m3_idle_END (0)
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA1_uce_sys_idle_START (1)
#define SOC_DDRC_DUMREG_DDRC_COMMON_RDATA1_uce_sys_idle_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tz_dmc_secure_n : 1;
        unsigned int tz_uce_secure_n : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DDRC_DUMREG_DDRC_COMMON_CTRL5_UNION;
#endif
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL5_tz_dmc_secure_n_START (0)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL5_tz_dmc_secure_n_END (0)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL5_tz_uce_secure_n_START (1)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL5_tz_uce_secure_n_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clk_dmc_free_auto_bypass : 1;
        unsigned int clk_dmc_free_auto_bypass_ext : 1;
        unsigned int reset_pack_dfi_n : 1;
        unsigned int clk_ddrphy_neg_autofs_bypass : 1;
        unsigned int clk_bypass_auto_bypass_ext : 1;
        unsigned int cnt_wait_wake_cfg : 4;
        unsigned int reserved : 2;
        unsigned int reset_uce_h2hbrg_m : 1;
        unsigned int dfi_access_gt_vote_bypass : 4;
        unsigned int clk_wr_en : 16;
    } reg;
} SOC_DDRC_DUMREG_DDRC_COMMON_CTRL4_UNION;
#endif
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL4_clk_dmc_free_auto_bypass_START (0)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL4_clk_dmc_free_auto_bypass_END (0)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL4_clk_dmc_free_auto_bypass_ext_START (1)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL4_clk_dmc_free_auto_bypass_ext_END (1)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL4_reset_pack_dfi_n_START (2)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL4_reset_pack_dfi_n_END (2)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL4_clk_ddrphy_neg_autofs_bypass_START (3)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL4_clk_ddrphy_neg_autofs_bypass_END (3)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL4_clk_bypass_auto_bypass_ext_START (4)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL4_clk_bypass_auto_bypass_ext_END (4)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL4_cnt_wait_wake_cfg_START (5)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL4_cnt_wait_wake_cfg_END (8)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL4_reset_uce_h2hbrg_m_START (11)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL4_reset_uce_h2hbrg_m_END (11)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL4_dfi_access_gt_vote_bypass_START (12)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL4_dfi_access_gt_vote_bypass_END (15)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL4_clk_wr_en_START (16)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL4_clk_wr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int phyupd_reqen_byp : 1;
        unsigned int meta_dff_bypass : 1;
        unsigned int uce_clken_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int fast_wakeup_exd : 2;
        unsigned int dmc_apb_gt_en : 1;
        unsigned int byp_mode_sel : 1;
        unsigned int byp_mode_dum : 1;
        unsigned int pll_sw_sel_sel : 1;
        unsigned int pll_sw_sel_dum : 1;
        unsigned int gt_clk_ddrphy_neg_sel : 1;
        unsigned int gt_clk_ddrphy_neg_dum : 1;
        unsigned int gt_clk_stat : 1;
        unsigned int uc_h2h_m_gt_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int clk_wr_en : 16;
    } reg;
} SOC_DDRC_DUMREG_DDRC_COMMON_CTRL0_UNION;
#endif
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL0_phyupd_reqen_byp_START (0)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL0_phyupd_reqen_byp_END (0)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL0_meta_dff_bypass_START (1)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL0_meta_dff_bypass_END (1)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL0_uce_clken_bypass_START (2)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL0_uce_clken_bypass_END (2)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL0_fast_wakeup_exd_START (4)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL0_fast_wakeup_exd_END (5)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL0_dmc_apb_gt_en_START (6)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL0_dmc_apb_gt_en_END (6)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL0_byp_mode_sel_START (7)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL0_byp_mode_sel_END (7)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL0_byp_mode_dum_START (8)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL0_byp_mode_dum_END (8)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL0_pll_sw_sel_sel_START (9)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL0_pll_sw_sel_sel_END (9)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL0_pll_sw_sel_dum_START (10)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL0_pll_sw_sel_dum_END (10)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL0_gt_clk_ddrphy_neg_sel_START (11)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL0_gt_clk_ddrphy_neg_sel_END (11)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL0_gt_clk_ddrphy_neg_dum_START (12)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL0_gt_clk_ddrphy_neg_dum_END (12)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL0_gt_clk_stat_START (13)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL0_gt_clk_stat_END (13)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL0_uc_h2h_m_gt_en_START (14)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL0_uc_h2h_m_gt_en_END (14)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL0_clk_wr_en_START (16)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL0_clk_wr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clk_ddrphy_apb_ac : 1;
        unsigned int dfi_clk_ddrphy : 1;
        unsigned int dfi_clk_dlyline : 1;
        unsigned int rs_neg_rx_clock : 1;
        unsigned int rs1_rx_clock : 1;
        unsigned int rs2_rx_clock : 1;
        unsigned int rs0_tx_clock : 1;
        unsigned int rs1_tx_clock : 1;
        unsigned int rs_neg_tx_clock : 1;
        unsigned int reserved : 7;
        unsigned int clk_wr_en : 16;
    } reg;
} SOC_DDRC_DUMREG_DDRC_COMMON_CTRL1_UNION;
#endif
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL1_clk_ddrphy_apb_ac_START (0)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL1_clk_ddrphy_apb_ac_END (0)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL1_dfi_clk_ddrphy_START (1)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL1_dfi_clk_ddrphy_END (1)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL1_dfi_clk_dlyline_START (2)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL1_dfi_clk_dlyline_END (2)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL1_rs_neg_rx_clock_START (3)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL1_rs_neg_rx_clock_END (3)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL1_rs1_rx_clock_START (4)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL1_rs1_rx_clock_END (4)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL1_rs2_rx_clock_START (5)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL1_rs2_rx_clock_END (5)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL1_rs0_tx_clock_START (6)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL1_rs0_tx_clock_END (6)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL1_rs1_tx_clock_START (7)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL1_rs1_tx_clock_END (7)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL1_rs_neg_tx_clock_START (8)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL1_rs_neg_tx_clock_END (8)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL1_clk_wr_en_START (16)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL1_clk_wr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clk_pack_apb : 1;
        unsigned int clk_uce : 1;
        unsigned int clk_uce_bus : 1;
        unsigned int clk_dfi_pack : 1;
        unsigned int clk_dfi_dmc : 1;
        unsigned int clk_dmc_free : 1;
        unsigned int clk_uce_engine : 1;
        unsigned int clk_ddrphy_bypass : 1;
        unsigned int clk_ddrphy_ref : 1;
        unsigned int ddr_autoselfrefresh_ind_bypass : 1;
        unsigned int clk_pack_apb_auto_bypass_ext : 1;
        unsigned int clk_uce_auto_bypass_ext : 1;
        unsigned int clk_uce_bus_auto_bypass_ext : 1;
        unsigned int clk_dfi_pack_auto_bypass_ext : 1;
        unsigned int clk_uce_auto_bypass : 1;
        unsigned int clk_uce_bus_auto_bypass : 1;
        unsigned int clk_wr_en : 16;
    } reg;
} SOC_DDRC_DUMREG_DDRC_COMMON_CTRL2_UNION;
#endif
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL2_clk_pack_apb_START (0)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL2_clk_pack_apb_END (0)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL2_clk_uce_START (1)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL2_clk_uce_END (1)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL2_clk_uce_bus_START (2)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL2_clk_uce_bus_END (2)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL2_clk_dfi_pack_START (3)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL2_clk_dfi_pack_END (3)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL2_clk_dfi_dmc_START (4)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL2_clk_dfi_dmc_END (4)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL2_clk_dmc_free_START (5)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL2_clk_dmc_free_END (5)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL2_clk_uce_engine_START (6)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL2_clk_uce_engine_END (6)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL2_clk_ddrphy_bypass_START (7)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL2_clk_ddrphy_bypass_END (7)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL2_clk_ddrphy_ref_START (8)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL2_clk_ddrphy_ref_END (8)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL2_ddr_autoselfrefresh_ind_bypass_START (9)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL2_ddr_autoselfrefresh_ind_bypass_END (9)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL2_clk_pack_apb_auto_bypass_ext_START (10)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL2_clk_pack_apb_auto_bypass_ext_END (10)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL2_clk_uce_auto_bypass_ext_START (11)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL2_clk_uce_auto_bypass_ext_END (11)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL2_clk_uce_bus_auto_bypass_ext_START (12)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL2_clk_uce_bus_auto_bypass_ext_END (12)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL2_clk_dfi_pack_auto_bypass_ext_START (13)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL2_clk_dfi_pack_auto_bypass_ext_END (13)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL2_clk_uce_auto_bypass_START (14)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL2_clk_uce_auto_bypass_END (14)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL2_clk_uce_bus_auto_bypass_START (15)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL2_clk_uce_bus_auto_bypass_END (15)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL2_clk_wr_en_START (16)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL2_clk_wr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clk_dfi_pack_auto_bypass : 1;
        unsigned int clk_ddrphy_bypassref_auto_bypass : 1;
        unsigned int clk_ddrphy_bypass_ref_ind_auto_bypass : 1;
        unsigned int clk_ddrphy_bypassref_enable : 1;
        unsigned int ref_div : 1;
        unsigned int uc_div : 2;
        unsigned int reset_uce_n : 1;
        unsigned int reset_ucem3_n : 1;
        unsigned int reset_pack_n : 1;
        unsigned int reset_dmc_free_n : 1;
        unsigned int reset_uce_engine_n : 1;
        unsigned int dfi_access_gt_bypass : 1;
        unsigned int reset_s2p_n : 1;
        unsigned int reset_dmc_n : 1;
        unsigned int clk_pack_apb_auto_bypass : 1;
        unsigned int clk_wr_en : 16;
    } reg;
} SOC_DDRC_DUMREG_DDRC_COMMON_CTRL3_UNION;
#endif
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL3_clk_dfi_pack_auto_bypass_START (0)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL3_clk_dfi_pack_auto_bypass_END (0)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL3_clk_ddrphy_bypassref_auto_bypass_START (1)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL3_clk_ddrphy_bypassref_auto_bypass_END (1)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL3_clk_ddrphy_bypass_ref_ind_auto_bypass_START (2)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL3_clk_ddrphy_bypass_ref_ind_auto_bypass_END (2)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL3_clk_ddrphy_bypassref_enable_START (3)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL3_clk_ddrphy_bypassref_enable_END (3)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL3_ref_div_START (4)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL3_ref_div_END (4)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL3_uc_div_START (5)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL3_uc_div_END (6)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL3_reset_uce_n_START (7)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL3_reset_uce_n_END (7)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL3_reset_ucem3_n_START (8)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL3_reset_ucem3_n_END (8)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL3_reset_pack_n_START (9)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL3_reset_pack_n_END (9)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL3_reset_dmc_free_n_START (10)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL3_reset_dmc_free_n_END (10)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL3_reset_uce_engine_n_START (11)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL3_reset_uce_engine_n_END (11)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL3_dfi_access_gt_bypass_START (12)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL3_dfi_access_gt_bypass_END (12)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL3_reset_s2p_n_START (13)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL3_reset_s2p_n_END (13)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL3_reset_dmc_n_START (14)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL3_reset_dmc_n_END (14)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL3_clk_pack_apb_auto_bypass_START (15)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL3_clk_pack_apb_auto_bypass_END (15)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL3_clk_wr_en_START (16)
#define SOC_DDRC_DUMREG_DDRC_COMMON_CTRL3_clk_wr_en_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
