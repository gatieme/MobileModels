#ifndef __SOC_NPU_ETZPC_INTERFACE_H__
#define __SOC_NPU_ETZPC_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_ETZPC_etpzcdec0stat_ADDR(base) ((base) + (0x800UL))
#define SOC_NPU_ETZPC_etpzcdec0set_ADDR(base) ((base) + (0x804UL))
#define SOC_NPU_ETZPC_etpzcdec0clr_ADDR(base) ((base) + (0x808UL))
#define SOC_NPU_ETZPC_etpzcdec1stat_ADDR(base) ((base) + (0x80CUL))
#define SOC_NPU_ETZPC_etpzcdec1set_ADDR(base) ((base) + (0x810UL))
#define SOC_NPU_ETZPC_etpzcdec1clr_ADDR(base) ((base) + (0x814UL))
#else
#define SOC_NPU_ETZPC_etpzcdec0stat_ADDR(base) ((base) + (0x800))
#define SOC_NPU_ETZPC_etpzcdec0set_ADDR(base) ((base) + (0x804))
#define SOC_NPU_ETZPC_etpzcdec0clr_ADDR(base) ((base) + (0x808))
#define SOC_NPU_ETZPC_etpzcdec1stat_ADDR(base) ((base) + (0x80C))
#define SOC_NPU_ETZPC_etpzcdec1set_ADDR(base) ((base) + (0x810))
#define SOC_NPU_ETZPC_etpzcdec1clr_ADDR(base) ((base) + (0x814))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enhance_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_ETZPC_etpzcdec0stat_UNION;
#endif
#define SOC_NPU_ETZPC_etpzcdec0stat_enhance_en_START (0)
#define SOC_NPU_ETZPC_etpzcdec0stat_enhance_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enhance_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_ETZPC_etpzcdec0set_UNION;
#endif
#define SOC_NPU_ETZPC_etpzcdec0set_enhance_en_START (0)
#define SOC_NPU_ETZPC_etpzcdec0set_enhance_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enhance_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_ETZPC_etpzcdec0clr_UNION;
#endif
#define SOC_NPU_ETZPC_etpzcdec0clr_enhance_en_START (0)
#define SOC_NPU_ETZPC_etpzcdec0clr_enhance_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int irpt_s_smmu_aicore_mask : 1;
        unsigned int irpt_s_smmu_sysdma_mask : 1;
        unsigned int wdog_res_ai_mask : 1;
        unsigned int wdog_res_ts_mask : 1;
        unsigned int intr_uart_npu_mask : 1;
        unsigned int gic_ts_sram_int_mask : 1;
        unsigned int npu_trace_int_mask : 1;
        unsigned int gic_wake_request0_mask : 1;
        unsigned int gic_wake_request1_mask : 1;
        unsigned int tcu_iprt_s_mask : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_NPU_ETZPC_etpzcdec1stat_UNION;
#endif
#define SOC_NPU_ETZPC_etpzcdec1stat_irpt_s_smmu_aicore_mask_START (0)
#define SOC_NPU_ETZPC_etpzcdec1stat_irpt_s_smmu_aicore_mask_END (0)
#define SOC_NPU_ETZPC_etpzcdec1stat_irpt_s_smmu_sysdma_mask_START (1)
#define SOC_NPU_ETZPC_etpzcdec1stat_irpt_s_smmu_sysdma_mask_END (1)
#define SOC_NPU_ETZPC_etpzcdec1stat_wdog_res_ai_mask_START (2)
#define SOC_NPU_ETZPC_etpzcdec1stat_wdog_res_ai_mask_END (2)
#define SOC_NPU_ETZPC_etpzcdec1stat_wdog_res_ts_mask_START (3)
#define SOC_NPU_ETZPC_etpzcdec1stat_wdog_res_ts_mask_END (3)
#define SOC_NPU_ETZPC_etpzcdec1stat_intr_uart_npu_mask_START (4)
#define SOC_NPU_ETZPC_etpzcdec1stat_intr_uart_npu_mask_END (4)
#define SOC_NPU_ETZPC_etpzcdec1stat_gic_ts_sram_int_mask_START (5)
#define SOC_NPU_ETZPC_etpzcdec1stat_gic_ts_sram_int_mask_END (5)
#define SOC_NPU_ETZPC_etpzcdec1stat_npu_trace_int_mask_START (6)
#define SOC_NPU_ETZPC_etpzcdec1stat_npu_trace_int_mask_END (6)
#define SOC_NPU_ETZPC_etpzcdec1stat_gic_wake_request0_mask_START (7)
#define SOC_NPU_ETZPC_etpzcdec1stat_gic_wake_request0_mask_END (7)
#define SOC_NPU_ETZPC_etpzcdec1stat_gic_wake_request1_mask_START (8)
#define SOC_NPU_ETZPC_etpzcdec1stat_gic_wake_request1_mask_END (8)
#define SOC_NPU_ETZPC_etpzcdec1stat_tcu_iprt_s_mask_START (9)
#define SOC_NPU_ETZPC_etpzcdec1stat_tcu_iprt_s_mask_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int irpt_s_smmu_aicore_mask : 1;
        unsigned int irpt_s_smmu_sysdma_mask : 1;
        unsigned int wdog_res_ai_mask : 1;
        unsigned int wdog_res_ts_mask : 1;
        unsigned int intr_uart_npu_mask : 1;
        unsigned int gic_ts_sram_int_mask : 1;
        unsigned int npu_trace_int_mask : 1;
        unsigned int gic_wake_request0_mask : 1;
        unsigned int gic_wake_request1_mask : 1;
        unsigned int tcu_iprt_s_mask : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_NPU_ETZPC_etpzcdec1set_UNION;
#endif
#define SOC_NPU_ETZPC_etpzcdec1set_irpt_s_smmu_aicore_mask_START (0)
#define SOC_NPU_ETZPC_etpzcdec1set_irpt_s_smmu_aicore_mask_END (0)
#define SOC_NPU_ETZPC_etpzcdec1set_irpt_s_smmu_sysdma_mask_START (1)
#define SOC_NPU_ETZPC_etpzcdec1set_irpt_s_smmu_sysdma_mask_END (1)
#define SOC_NPU_ETZPC_etpzcdec1set_wdog_res_ai_mask_START (2)
#define SOC_NPU_ETZPC_etpzcdec1set_wdog_res_ai_mask_END (2)
#define SOC_NPU_ETZPC_etpzcdec1set_wdog_res_ts_mask_START (3)
#define SOC_NPU_ETZPC_etpzcdec1set_wdog_res_ts_mask_END (3)
#define SOC_NPU_ETZPC_etpzcdec1set_intr_uart_npu_mask_START (4)
#define SOC_NPU_ETZPC_etpzcdec1set_intr_uart_npu_mask_END (4)
#define SOC_NPU_ETZPC_etpzcdec1set_gic_ts_sram_int_mask_START (5)
#define SOC_NPU_ETZPC_etpzcdec1set_gic_ts_sram_int_mask_END (5)
#define SOC_NPU_ETZPC_etpzcdec1set_npu_trace_int_mask_START (6)
#define SOC_NPU_ETZPC_etpzcdec1set_npu_trace_int_mask_END (6)
#define SOC_NPU_ETZPC_etpzcdec1set_gic_wake_request0_mask_START (7)
#define SOC_NPU_ETZPC_etpzcdec1set_gic_wake_request0_mask_END (7)
#define SOC_NPU_ETZPC_etpzcdec1set_gic_wake_request1_mask_START (8)
#define SOC_NPU_ETZPC_etpzcdec1set_gic_wake_request1_mask_END (8)
#define SOC_NPU_ETZPC_etpzcdec1set_tcu_iprt_s_mask_START (9)
#define SOC_NPU_ETZPC_etpzcdec1set_tcu_iprt_s_mask_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int irpt_s_smmu_aicore_mask : 1;
        unsigned int irpt_s_smmu_sysdma_mask : 1;
        unsigned int wdog_res_ai_mask : 1;
        unsigned int wdog_res_ts_mask : 1;
        unsigned int intr_uart_npu_mask : 1;
        unsigned int gic_ts_sram_int_mask : 1;
        unsigned int npu_trace_int_mask : 1;
        unsigned int gic_wake_request0_mask : 1;
        unsigned int gic_wake_request1_mask : 1;
        unsigned int tcu_iprt_s_mask : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_NPU_ETZPC_etpzcdec1clr_UNION;
#endif
#define SOC_NPU_ETZPC_etpzcdec1clr_irpt_s_smmu_aicore_mask_START (0)
#define SOC_NPU_ETZPC_etpzcdec1clr_irpt_s_smmu_aicore_mask_END (0)
#define SOC_NPU_ETZPC_etpzcdec1clr_irpt_s_smmu_sysdma_mask_START (1)
#define SOC_NPU_ETZPC_etpzcdec1clr_irpt_s_smmu_sysdma_mask_END (1)
#define SOC_NPU_ETZPC_etpzcdec1clr_wdog_res_ai_mask_START (2)
#define SOC_NPU_ETZPC_etpzcdec1clr_wdog_res_ai_mask_END (2)
#define SOC_NPU_ETZPC_etpzcdec1clr_wdog_res_ts_mask_START (3)
#define SOC_NPU_ETZPC_etpzcdec1clr_wdog_res_ts_mask_END (3)
#define SOC_NPU_ETZPC_etpzcdec1clr_intr_uart_npu_mask_START (4)
#define SOC_NPU_ETZPC_etpzcdec1clr_intr_uart_npu_mask_END (4)
#define SOC_NPU_ETZPC_etpzcdec1clr_gic_ts_sram_int_mask_START (5)
#define SOC_NPU_ETZPC_etpzcdec1clr_gic_ts_sram_int_mask_END (5)
#define SOC_NPU_ETZPC_etpzcdec1clr_npu_trace_int_mask_START (6)
#define SOC_NPU_ETZPC_etpzcdec1clr_npu_trace_int_mask_END (6)
#define SOC_NPU_ETZPC_etpzcdec1clr_gic_wake_request0_mask_START (7)
#define SOC_NPU_ETZPC_etpzcdec1clr_gic_wake_request0_mask_END (7)
#define SOC_NPU_ETZPC_etpzcdec1clr_gic_wake_request1_mask_START (8)
#define SOC_NPU_ETZPC_etpzcdec1clr_gic_wake_request1_mask_END (8)
#define SOC_NPU_ETZPC_etpzcdec1clr_tcu_iprt_s_mask_START (9)
#define SOC_NPU_ETZPC_etpzcdec1clr_tcu_iprt_s_mask_END (9)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
