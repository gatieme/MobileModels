#ifndef __SOC_FCM_GIC_HW_SPI_CTRL_INTERFACE_H__
#define __SOC_FCM_GIC_HW_SPI_CTRL_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_FCM_GIC_HW_SPI_CTRL_HW_SPI_SET_REG_ADDR(base) ((base) + (0x000UL))
#define SOC_FCM_GIC_HW_SPI_CTRL_HW_SPI_CLR_REG_ADDR(base) ((base) + (0x004UL))
#define SOC_FCM_GIC_HW_SPI_CTRL_HW_SPI_STAT_REG_ADDR(base) ((base) + (0x008UL))
#define SOC_FCM_GIC_HW_SPI_CTRL_HW_SPI_PULSE_REG_ADDR(base) ((base) + (0x00CUL))
#define SOC_FCM_GIC_HW_SPI_CTRL_HW_SPI_CFG_REG_ADDR(base) ((base) + (0x100UL))
#else
#define SOC_FCM_GIC_HW_SPI_CTRL_HW_SPI_SET_REG_ADDR(base) ((base) + (0x000))
#define SOC_FCM_GIC_HW_SPI_CTRL_HW_SPI_CLR_REG_ADDR(base) ((base) + (0x004))
#define SOC_FCM_GIC_HW_SPI_CTRL_HW_SPI_STAT_REG_ADDR(base) ((base) + (0x008))
#define SOC_FCM_GIC_HW_SPI_CTRL_HW_SPI_PULSE_REG_ADDR(base) ((base) + (0x00C))
#define SOC_FCM_GIC_HW_SPI_CTRL_HW_SPI_CFG_REG_ADDR(base) ((base) + (0x100))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int spi_set : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_FCM_GIC_HW_SPI_CTRL_HW_SPI_SET_REG_UNION;
#endif
#define SOC_FCM_GIC_HW_SPI_CTRL_HW_SPI_SET_REG_spi_set_START (0)
#define SOC_FCM_GIC_HW_SPI_CTRL_HW_SPI_SET_REG_spi_set_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int spi_clr : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_FCM_GIC_HW_SPI_CTRL_HW_SPI_CLR_REG_UNION;
#endif
#define SOC_FCM_GIC_HW_SPI_CTRL_HW_SPI_CLR_REG_spi_clr_START (0)
#define SOC_FCM_GIC_HW_SPI_CTRL_HW_SPI_CLR_REG_spi_clr_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int spi_stat : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_FCM_GIC_HW_SPI_CTRL_HW_SPI_STAT_REG_UNION;
#endif
#define SOC_FCM_GIC_HW_SPI_CTRL_HW_SPI_STAT_REG_spi_stat_START (0)
#define SOC_FCM_GIC_HW_SPI_CTRL_HW_SPI_STAT_REG_spi_stat_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int spi_pulse : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_FCM_GIC_HW_SPI_CTRL_HW_SPI_PULSE_REG_UNION;
#endif
#define SOC_FCM_GIC_HW_SPI_CTRL_HW_SPI_PULSE_REG_spi_pulse_START (0)
#define SOC_FCM_GIC_HW_SPI_CTRL_HW_SPI_PULSE_REG_spi_pulse_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int spi_cfg : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_FCM_GIC_HW_SPI_CTRL_HW_SPI_CFG_REG_UNION;
#endif
#define SOC_FCM_GIC_HW_SPI_CTRL_HW_SPI_CFG_REG_spi_cfg_START (0)
#define SOC_FCM_GIC_HW_SPI_CTRL_HW_SPI_CFG_REG_spi_cfg_END (3)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
