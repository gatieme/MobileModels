#ifndef __SOC_GPU_INTERFACE_H__
#define __SOC_GPU_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_GPU_ID_ADDR(base) ((base) + (0x0000UL))
#define SOC_GPU_L2_FEATURES_ADDR(base) ((base) + (0x0004UL))
#define SOC_GPU_TILER_FEATURES_ADDR(base) ((base) + (0x000CUL))
#define SOC_GPU_MEM_FEATURES_ADDR(base) ((base) + (0x0010UL))
#define SOC_GPU_MMU_FEATURES_ADDR(base) ((base) + (0x0014UL))
#define SOC_GPU_AS_PRESENT_ADDR(base) ((base) + (0x0018UL))
#define SOC_GPU_JS_PRESENT_ADDR(base) ((base) + (0x001CUL))
#define SOC_GPU_IRQ_RAWSTAT_ADDR(base) ((base) + (0x0020UL))
#define SOC_GPU_IRQ_CLEAR_ADDR(base) ((base) + (0x0024UL))
#define SOC_GPU_IRQ_MASK_ADDR(base) ((base) + (0x0028UL))
#define SOC_GPU_IRQ_STATUS_ADDR(base) ((base) + (0x002CUL))
#define SOC_GPU_COMMAND_ADDR(base) ((base) + (0x0030UL))
#define SOC_GPU_STATUS_ADDR(base) ((base) + (0x0034UL))
#define SOC_GPU_LATEST_FLUSH_ADDR(base) ((base) + (0x0038UL))
#define SOC_GPU_FAULTSTATUS_ADDR(base) ((base) + (0x003CUL))
#define SOC_GPU_FAULTADDRESS_LO_ADDR(base) ((base) + (0x0040UL))
#define SOC_GPU_FAULTADDRESS_HI_ADDR(base) ((base) + (0x0044UL))
#define SOC_GPU_PWR_KEY_ADDR(base) ((base) + (0x0050UL))
#define SOC_GPU_PWR_KEYOVERRIDE0_ADDR(base) ((base) + (0x0054UL))
#define SOC_GPU_PWR_KEYOVERRIDE1_ADDR(base) ((base) + (0x0058UL))
#define SOC_GPU_PRFCNT_BASE_LO_ADDR(base) ((base) + (0x0060UL))
#define SOC_GPU_PRFCNT_BASE_HI_ADDR(base) ((base) + (0x0064UL))
#define SOC_GPU_PRFCNT_CONFIG_ADDR(base) ((base) + (0x0068UL))
#define SOC_GPU_PRFCNT_JM_EN_ADDR(base) ((base) + (0x006CUL))
#define SOC_GPU_PRFCNT_SHADER_EN_ADDR(base) ((base) + (0x0070UL))
#define SOC_GPU_PRFCNT_TILER_EN_ADDR(base) ((base) + (0x0074UL))
#define SOC_GPU_PRFCNT_MMU_L2_EN_ADDR(base) ((base) + (0x007CUL))
#define SOC_GPU_CYCLE_COUNT_LO_ADDR(base) ((base) + (0x0090UL))
#define SOC_GPU_CYCLE_COUNT_HI_ADDR(base) ((base) + (0x0094UL))
#define SOC_GPU_TIMESTAMP_LO_ADDR(base) ((base) + (0x0098UL))
#define SOC_GPU_TIMESTAMP_HI_ADDR(base) ((base) + (0x009CUL))
#define SOC_GPU_THREAD_MAX_THREADS_ADDR(base) ((base) + (0x00A0UL))
#define SOC_GPU_THREAD_MAX_WORKGROUP_ADDR(base) ((base) + (0x00A4UL))
#define SOC_GPU_THREAD_MAX_BARRIER_SIZE_ADDR(base) ((base) + (0x00A8UL))
#define SOC_GPU_THREAD_FEATURES_ADDR(base) ((base) + (0x00ACUL))
#define SOC_GPU_TEXTURE_FEATURES_0_ADDR(base) ((base) + (0x00B0UL))
#define SOC_GPU_TEXTURE_FEATURES_1_ADDR(base) ((base) + (0x00B4UL))
#define SOC_GPU_TEXTURE_FEATURES_2_ADDR(base) ((base) + (0x00B8UL))
#define SOC_GPU_JS0_FEATURES_ADDR(base) ((base) + (0x00C0UL))
#define SOC_GPU_JS1_FEATURES_ADDR(base) ((base) + (0x00C4UL))
#define SOC_GPU_JS2_FEATURES_ADDR(base) ((base) + (0x00C8UL))
#define SOC_GPU_SHADER_PRESENT_LO_ADDR(base) ((base) + (0x0100UL))
#define SOC_GPU_SHADER_PRESENT_HI_ADDR(base) ((base) + (0x0104UL))
#define SOC_GPU_TILER_PRESENT_LO_ADDR(base) ((base) + (0x0110UL))
#define SOC_GPU_TILER_PRESENT_HI_ADDR(base) ((base) + (0x0114UL))
#define SOC_GPU_L2_PRESENT_LO_ADDR(base) ((base) + (0x0120UL))
#define SOC_GPU_L2_PRESENT_HI_ADDR(base) ((base) + (0x0124UL))
#define SOC_GPU_SHADER_READY_LO_ADDR(base) ((base) + (0x0140UL))
#define SOC_GPU_SHADER_READY_HI_ADDR(base) ((base) + (0x0144UL))
#define SOC_GPU_TILER_READY_LO_ADDR(base) ((base) + (0x0150UL))
#define SOC_GPU_TILER_READY_HI_ADDR(base) ((base) + (0x0154UL))
#define SOC_GPU_L2_READY_LO_ADDR(base) ((base) + (0x0160UL))
#define SOC_GPU_L2_READY_HI_ADDR(base) ((base) + (0x0164UL))
#define SOC_GPU_SHADER_PWRON_LO_ADDR(base) ((base) + (0x0180UL))
#define SOC_GPU_SHADER_PWRON_HI_ADDR(base) ((base) + (0x0184UL))
#define SOC_GPU_TILER_PWRON_LO_ADDR(base) ((base) + (0x0190UL))
#define SOC_GPU_TILER_PWRON_HI_ADDR(base) ((base) + (0x0194UL))
#define SOC_GPU_L2_PWRON_LO_ADDR(base) ((base) + (0x01A0UL))
#define SOC_GPU_L2_PWRON_HI_ADDR(base) ((base) + (0x01A4UL))
#define SOC_GPU_SHADER_PWROFF_LO_ADDR(base) ((base) + (0x01C0UL))
#define SOC_GPU_SHADER_PWROFF_HI_ADDR(base) ((base) + (0x01C4UL))
#define SOC_GPU_TILER_PWROFF_LO_ADDR(base) ((base) + (0x01D0UL))
#define SOC_GPU_TILER_PWROFF_HI_ADDR(base) ((base) + (0x01D4UL))
#define SOC_GPU_L2_PWROFF_LO_ADDR(base) ((base) + (0x01E0UL))
#define SOC_GPU_L2_PWROFF_HI_ADDR(base) ((base) + (0x01E4UL))
#define SOC_GPU_SHADER_PWRTRANS_LO_ADDR(base) ((base) + (0x0200UL))
#define SOC_GPU_SHADER_PWRTRANS_HI_ADDR(base) ((base) + (0x0204UL))
#define SOC_GPU_TILER_PWRTRANS_LO_ADDR(base) ((base) + (0x0210UL))
#define SOC_GPU_TILER_PWRTRANS_HI_ADDR(base) ((base) + (0x0214UL))
#define SOC_GPU_L2_PWRTRANS_LO_ADDR(base) ((base) + (0x0220UL))
#define SOC_GPU_L2_PWRTRANS_HI_ADDR(base) ((base) + (0x0224UL))
#define SOC_GPU_SHADER_PWRACTIVE_LO_ADDR(base) ((base) + (0x0240UL))
#define SOC_GPU_SHADER_PWRACTIVE_HI_ADDR(base) ((base) + (0x0244UL))
#define SOC_GPU_TILER_PWRACTIVE_LO_ADDR(base) ((base) + (0x0250UL))
#define SOC_GPU_TILER_PWRACTIVE_HI_ADDR(base) ((base) + (0x0254UL))
#define SOC_GPU_L2_PWRACTIVE_LO_ADDR(base) ((base) + (0x0260UL))
#define SOC_GPU_L2_PWRACTIVE_HI_ADDR(base) ((base) + (0x0264UL))
#define SOC_GPU_COHERENCY_FEATURES_ADDR(base) ((base) + (0x0300UL))
#define SOC_GPU_COHERENCY_ENABLE_ADDR(base) ((base) + (0x0304UL))
#define SOC_GPU_JM_CONFIG_ADDR(base) ((base) + (0x0F00UL))
#define SOC_GPU_SHADER_CONFIG_ADDR(base) ((base) + (0x0F04UL))
#define SOC_GPU_TILER_CONFIG_ADDR(base) ((base) + (0x0F08UL))
#define SOC_GPU_L2_MMU_CONFIG_ADDR(base) ((base) + (0x0F0CUL))
#define SOC_GPU_JOB_IRQ_RAWSTAT_ADDR(base) ((base) + (0x1000UL))
#define SOC_GPU_JOB_IRQ_CLEAR_ADDR(base) ((base) + (0x1004UL))
#define SOC_GPU_JOB_IRQ_MASK_ADDR(base) ((base) + (0x1008UL))
#define SOC_GPU_JOB_IRQ_STATUS_ADDR(base) ((base) + (0x100CUL))
#define SOC_GPU_JOB_IRQ_JS_STATE_ADDR(base) ((base) + (0x1010UL))
#define SOC_GPU_JOB_IRQ_THROTTLE_ADDR(base) ((base) + (0x1014UL))
#define SOC_GPU_EVENT_IRQ_RAWSTAT_ADDR(base) ((base) + (0x1020UL))
#define SOC_GPU_EVENT_IRQ_CLEAR_ADDR(base) ((base) + (0x1024UL))
#define SOC_GPU_EVENT_IRQ_MASK_ADDR(base) ((base) + (0x1028UL))
#define SOC_GPU_EVENT_IRQ_STATUS_ADDR(base) ((base) + (0x102CUL))
#define SOC_GPU_JS0_HEAD_LO_ADDR(base) ((base) + (0x1800UL))
#define SOC_GPU_JS0_HEAD_HI_ADDR(base) ((base) + (0x1804UL))
#define SOC_GPU_JS0_TAIL_LO_ADDR(base) ((base) + (0x1808UL))
#define SOC_GPU_JS0_TAIL_HI_ADDR(base) ((base) + (0x180CUL))
#define SOC_GPU_JS0_AFFINITY_LO_ADDR(base) ((base) + (0x1810UL))
#define SOC_GPU_JS0_AFFINITY_HI_ADDR(base) ((base) + (0x1814UL))
#define SOC_GPU_JS0_CONFIG_ADDR(base) ((base) + (0x1818UL))
#define SOC_GPU_JS0_XAFFINITY_ADDR(base) ((base) + (0x181CUL))
#define SOC_GPU_JS0_COMMAND_ADDR(base) ((base) + (0x1820UL))
#define SOC_GPU_JS0_STATUS_ADDR(base) ((base) + (0x1824UL))
#define SOC_GPU_JS0_FLUSH_ID_ADDR(base) ((base) + (0x1830UL))
#define SOC_GPU_JS0_EVENT_0_ADDR(base) ((base) + (0x1834UL))
#define SOC_GPU_JS0_EVENT_1_ADDR(base) ((base) + (0x1838UL))
#define SOC_GPU_JS0_EVENT_MASK_ADDR(base) ((base) + (0x183CUL))
#define SOC_GPU_JS0_HEAD_NEXT_LO_ADDR(base) ((base) + (0x1840UL))
#define SOC_GPU_JS0_HEAD_NEXT_HI_ADDR(base) ((base) + (0x1844UL))
#define SOC_GPU_JS0_AFFINITY_NEXT_LO_ADDR(base) ((base) + (0x1850UL))
#define SOC_GPU_JS0_AFFINITY_NEXT_HI_ADDR(base) ((base) + (0x1854UL))
#define SOC_GPU_JS0_CONFIG_NEXT_ADDR(base) ((base) + (0x1858UL))
#define SOC_GPU_JS0_XAFFINITY_NEXT_ADDR(base) ((base) + (0x185cUL))
#define SOC_GPU_JS0_COMMAND_NEXT_ADDR(base) ((base) + (0x1860UL))
#define SOC_GPU_MMU_IRQ_RAWSTAT_ADDR(base) ((base) + (0x2000UL))
#define SOC_GPU_MMU_IRQ_CLEAR_ADDR(base) ((base) + (0x2004UL))
#define SOC_GPU_MMU_IRQ_MASK_ADDR(base) ((base) + (0x2008UL))
#define SOC_GPU_MMU_IRQ_STATUS_ADDR(base) ((base) + (0x200CUL))
#define SOC_GPU_AS0_TRANSTAB_LO_ADDR(base) ((base) + (0x2400UL))
#define SOC_GPU_AS0_TRANSTAB_HI_ADDR(base) ((base) + (0x2404UL))
#define SOC_GPU_AS0_MEMATTR_LO_ADDR(base) ((base) + (0x2408UL))
#define SOC_GPU_AS0_MEMATTR_HI_ADDR(base) ((base) + (0x240CUL))
#define SOC_GPU_AS0_LOCKADDR_LO_ADDR(base) ((base) + (0x2410UL))
#define SOC_GPU_AS0_LOCKADDR_HI_ADDR(base) ((base) + (0x2414UL))
#define SOC_GPU_AS0_COMMAND_ADDR(base) ((base) + (0x2418UL))
#define SOC_GPU_AS0_FAULTSTATUS_ADDR(base) ((base) + (0x241CUL))
#define SOC_GPU_AS0_FAULTADDRESS_LO_ADDR(base) ((base) + (0x2420UL))
#define SOC_GPU_AS0_FAULTADDRESS_HI_ADDR(base) ((base) + (0x2424UL))
#define SOC_GPU_AS0_STATUS_ADDR(base) ((base) + (0x2428UL))
#define SOC_GPU_AS0_TRANSCFG_LO_ADDR(base) ((base) + (0x2430UL))
#define SOC_GPU_AS0_TRANSCFG_HI_ADDR(base) ((base) + (0x2434UL))
#define SOC_GPU_AS0_FAULTEXTRA_LO_ADDR(base) ((base) + (0x2438UL))
#define SOC_GPU_AS0_FAULTEXTRA_HI_ADDR(base) ((base) + (0x243CUL))
#define SOC_GPU_AS1_TRANSTAB_LO_ADDR(base) ((base) + (0x2440UL))
#define SOC_GPU_AS1_TRANSTAB_HI_ADDR(base) ((base) + (0x2444UL))
#define SOC_GPU_AS1_MEMATTR_LO_ADDR(base) ((base) + (0x2448UL))
#define SOC_GPU_AS1_MEMATTR_HI_ADDR(base) ((base) + (0x244CUL))
#define SOC_GPU_AS1_LOCKADDR_LO_ADDR(base) ((base) + (0x2450UL))
#define SOC_GPU_AS1_LOCKADDR_HI_ADDR(base) ((base) + (0x2454UL))
#define SOC_GPU_AS1_COMMAND_ADDR(base) ((base) + (0x2458UL))
#define SOC_GPU_AS1_FAULTSTATUS_ADDR(base) ((base) + (0x245CUL))
#define SOC_GPU_AS1_FAULTADDRESS_LO_ADDR(base) ((base) + (0x2460UL))
#define SOC_GPU_AS1_FAULTADDRESS_HI_ADDR(base) ((base) + (0x2464UL))
#define SOC_GPU_AS1_STATUS_ADDR(base) ((base) + (0x2468UL))
#define SOC_GPU_AS1_TRANSCFG_LO_ADDR(base) ((base) + (0x2470UL))
#define SOC_GPU_AS1_TRANSCFG_HI_ADDR(base) ((base) + (0x2474UL))
#define SOC_GPU_AS1_FAULTEXTRA_LO_ADDR(base) ((base) + (0x2478UL))
#define SOC_GPU_AS1_FAULTEXTRA_HI_ADDR(base) ((base) + (0x247CUL))
#define SOC_GPU_AS2_TRANSTAB_LO_ADDR(base) ((base) + (0x2480UL))
#define SOC_GPU_AS2_TRANSTAB_HI_ADDR(base) ((base) + (0x2484UL))
#define SOC_GPU_AS2_MEMATTR_LO_ADDR(base) ((base) + (0x2488UL))
#define SOC_GPU_AS2_MEMATTR_HI_ADDR(base) ((base) + (0x248CUL))
#define SOC_GPU_AS2_LOCKADDR_LO_ADDR(base) ((base) + (0x2490UL))
#define SOC_GPU_AS2_LOCKADDR_HI_ADDR(base) ((base) + (0x2494UL))
#define SOC_GPU_AS2_COMMAND_ADDR(base) ((base) + (0x2498UL))
#define SOC_GPU_AS2_FAULTSTATUS_ADDR(base) ((base) + (0x249CUL))
#define SOC_GPU_AS2_FAULTADDRESS_LO_ADDR(base) ((base) + (0x24A0UL))
#define SOC_GPU_AS2_FAULTADDRESS_HI_ADDR(base) ((base) + (0x24A4UL))
#define SOC_GPU_AS2_STATUS_ADDR(base) ((base) + (0x24A8UL))
#define SOC_GPU_AS2_TRANSCFG_LO_ADDR(base) ((base) + (0x24B0UL))
#define SOC_GPU_AS2_TRANSCFG_HI_ADDR(base) ((base) + (0x24B4UL))
#define SOC_GPU_AS2_FAULTEXTRA_LO_ADDR(base) ((base) + (0x24B8UL))
#define SOC_GPU_AS2_FAULTEXTRA_HI_ADDR(base) ((base) + (0x24BCUL))
#define SOC_GPU_AS3_TRANSTAB_LO_ADDR(base) ((base) + (0x24C0UL))
#define SOC_GPU_AS3_TRANSTAB_HI_ADDR(base) ((base) + (0x24C4UL))
#define SOC_GPU_AS3_MEMATTR_LO_ADDR(base) ((base) + (0x24C8UL))
#define SOC_GPU_AS3_MEMATTR_HI_ADDR(base) ((base) + (0x24CCUL))
#define SOC_GPU_AS3_LOCKADDR_LO_ADDR(base) ((base) + (0x24D0UL))
#define SOC_GPU_AS3_LOCKADDR_HI_ADDR(base) ((base) + (0x24D4UL))
#define SOC_GPU_AS3_COMMAND_ADDR(base) ((base) + (0x24D8UL))
#define SOC_GPU_AS3_FAULTSTATUS_ADDR(base) ((base) + (0x24DCUL))
#define SOC_GPU_AS3_FAULTADDRESS_LO_ADDR(base) ((base) + (0x24E0UL))
#define SOC_GPU_AS3_FAULTADDRESS_HI_ADDR(base) ((base) + (0x24E4UL))
#define SOC_GPU_AS3_STATUS_ADDR(base) ((base) + (0x24E8UL))
#define SOC_GPU_AS3_TRANSCFG_LO_ADDR(base) ((base) + (0x24F0UL))
#define SOC_GPU_AS3_TRANSCFG_HI_ADDR(base) ((base) + (0x24F4UL))
#define SOC_GPU_AS3_FAULTEXTRA_LO_ADDR(base) ((base) + (0x24F8UL))
#define SOC_GPU_AS3_FAULTEXTRA_HI_ADDR(base) ((base) + (0x24FCUL))
#else
#define SOC_GPU_ID_ADDR(base) ((base) + (0x0000))
#define SOC_GPU_L2_FEATURES_ADDR(base) ((base) + (0x0004))
#define SOC_GPU_TILER_FEATURES_ADDR(base) ((base) + (0x000C))
#define SOC_GPU_MEM_FEATURES_ADDR(base) ((base) + (0x0010))
#define SOC_GPU_MMU_FEATURES_ADDR(base) ((base) + (0x0014))
#define SOC_GPU_AS_PRESENT_ADDR(base) ((base) + (0x0018))
#define SOC_GPU_JS_PRESENT_ADDR(base) ((base) + (0x001C))
#define SOC_GPU_IRQ_RAWSTAT_ADDR(base) ((base) + (0x0020))
#define SOC_GPU_IRQ_CLEAR_ADDR(base) ((base) + (0x0024))
#define SOC_GPU_IRQ_MASK_ADDR(base) ((base) + (0x0028))
#define SOC_GPU_IRQ_STATUS_ADDR(base) ((base) + (0x002C))
#define SOC_GPU_COMMAND_ADDR(base) ((base) + (0x0030))
#define SOC_GPU_STATUS_ADDR(base) ((base) + (0x0034))
#define SOC_GPU_LATEST_FLUSH_ADDR(base) ((base) + (0x0038))
#define SOC_GPU_FAULTSTATUS_ADDR(base) ((base) + (0x003C))
#define SOC_GPU_FAULTADDRESS_LO_ADDR(base) ((base) + (0x0040))
#define SOC_GPU_FAULTADDRESS_HI_ADDR(base) ((base) + (0x0044))
#define SOC_GPU_PWR_KEY_ADDR(base) ((base) + (0x0050))
#define SOC_GPU_PWR_KEYOVERRIDE0_ADDR(base) ((base) + (0x0054))
#define SOC_GPU_PWR_KEYOVERRIDE1_ADDR(base) ((base) + (0x0058))
#define SOC_GPU_PRFCNT_BASE_LO_ADDR(base) ((base) + (0x0060))
#define SOC_GPU_PRFCNT_BASE_HI_ADDR(base) ((base) + (0x0064))
#define SOC_GPU_PRFCNT_CONFIG_ADDR(base) ((base) + (0x0068))
#define SOC_GPU_PRFCNT_JM_EN_ADDR(base) ((base) + (0x006C))
#define SOC_GPU_PRFCNT_SHADER_EN_ADDR(base) ((base) + (0x0070))
#define SOC_GPU_PRFCNT_TILER_EN_ADDR(base) ((base) + (0x0074))
#define SOC_GPU_PRFCNT_MMU_L2_EN_ADDR(base) ((base) + (0x007C))
#define SOC_GPU_CYCLE_COUNT_LO_ADDR(base) ((base) + (0x0090))
#define SOC_GPU_CYCLE_COUNT_HI_ADDR(base) ((base) + (0x0094))
#define SOC_GPU_TIMESTAMP_LO_ADDR(base) ((base) + (0x0098))
#define SOC_GPU_TIMESTAMP_HI_ADDR(base) ((base) + (0x009C))
#define SOC_GPU_THREAD_MAX_THREADS_ADDR(base) ((base) + (0x00A0))
#define SOC_GPU_THREAD_MAX_WORKGROUP_ADDR(base) ((base) + (0x00A4))
#define SOC_GPU_THREAD_MAX_BARRIER_SIZE_ADDR(base) ((base) + (0x00A8))
#define SOC_GPU_THREAD_FEATURES_ADDR(base) ((base) + (0x00AC))
#define SOC_GPU_TEXTURE_FEATURES_0_ADDR(base) ((base) + (0x00B0))
#define SOC_GPU_TEXTURE_FEATURES_1_ADDR(base) ((base) + (0x00B4))
#define SOC_GPU_TEXTURE_FEATURES_2_ADDR(base) ((base) + (0x00B8))
#define SOC_GPU_JS0_FEATURES_ADDR(base) ((base) + (0x00C0))
#define SOC_GPU_JS1_FEATURES_ADDR(base) ((base) + (0x00C4))
#define SOC_GPU_JS2_FEATURES_ADDR(base) ((base) + (0x00C8))
#define SOC_GPU_SHADER_PRESENT_LO_ADDR(base) ((base) + (0x0100))
#define SOC_GPU_SHADER_PRESENT_HI_ADDR(base) ((base) + (0x0104))
#define SOC_GPU_TILER_PRESENT_LO_ADDR(base) ((base) + (0x0110))
#define SOC_GPU_TILER_PRESENT_HI_ADDR(base) ((base) + (0x0114))
#define SOC_GPU_L2_PRESENT_LO_ADDR(base) ((base) + (0x0120))
#define SOC_GPU_L2_PRESENT_HI_ADDR(base) ((base) + (0x0124))
#define SOC_GPU_SHADER_READY_LO_ADDR(base) ((base) + (0x0140))
#define SOC_GPU_SHADER_READY_HI_ADDR(base) ((base) + (0x0144))
#define SOC_GPU_TILER_READY_LO_ADDR(base) ((base) + (0x0150))
#define SOC_GPU_TILER_READY_HI_ADDR(base) ((base) + (0x0154))
#define SOC_GPU_L2_READY_LO_ADDR(base) ((base) + (0x0160))
#define SOC_GPU_L2_READY_HI_ADDR(base) ((base) + (0x0164))
#define SOC_GPU_SHADER_PWRON_LO_ADDR(base) ((base) + (0x0180))
#define SOC_GPU_SHADER_PWRON_HI_ADDR(base) ((base) + (0x0184))
#define SOC_GPU_TILER_PWRON_LO_ADDR(base) ((base) + (0x0190))
#define SOC_GPU_TILER_PWRON_HI_ADDR(base) ((base) + (0x0194))
#define SOC_GPU_L2_PWRON_LO_ADDR(base) ((base) + (0x01A0))
#define SOC_GPU_L2_PWRON_HI_ADDR(base) ((base) + (0x01A4))
#define SOC_GPU_SHADER_PWROFF_LO_ADDR(base) ((base) + (0x01C0))
#define SOC_GPU_SHADER_PWROFF_HI_ADDR(base) ((base) + (0x01C4))
#define SOC_GPU_TILER_PWROFF_LO_ADDR(base) ((base) + (0x01D0))
#define SOC_GPU_TILER_PWROFF_HI_ADDR(base) ((base) + (0x01D4))
#define SOC_GPU_L2_PWROFF_LO_ADDR(base) ((base) + (0x01E0))
#define SOC_GPU_L2_PWROFF_HI_ADDR(base) ((base) + (0x01E4))
#define SOC_GPU_SHADER_PWRTRANS_LO_ADDR(base) ((base) + (0x0200))
#define SOC_GPU_SHADER_PWRTRANS_HI_ADDR(base) ((base) + (0x0204))
#define SOC_GPU_TILER_PWRTRANS_LO_ADDR(base) ((base) + (0x0210))
#define SOC_GPU_TILER_PWRTRANS_HI_ADDR(base) ((base) + (0x0214))
#define SOC_GPU_L2_PWRTRANS_LO_ADDR(base) ((base) + (0x0220))
#define SOC_GPU_L2_PWRTRANS_HI_ADDR(base) ((base) + (0x0224))
#define SOC_GPU_SHADER_PWRACTIVE_LO_ADDR(base) ((base) + (0x0240))
#define SOC_GPU_SHADER_PWRACTIVE_HI_ADDR(base) ((base) + (0x0244))
#define SOC_GPU_TILER_PWRACTIVE_LO_ADDR(base) ((base) + (0x0250))
#define SOC_GPU_TILER_PWRACTIVE_HI_ADDR(base) ((base) + (0x0254))
#define SOC_GPU_L2_PWRACTIVE_LO_ADDR(base) ((base) + (0x0260))
#define SOC_GPU_L2_PWRACTIVE_HI_ADDR(base) ((base) + (0x0264))
#define SOC_GPU_COHERENCY_FEATURES_ADDR(base) ((base) + (0x0300))
#define SOC_GPU_COHERENCY_ENABLE_ADDR(base) ((base) + (0x0304))
#define SOC_GPU_JM_CONFIG_ADDR(base) ((base) + (0x0F00))
#define SOC_GPU_SHADER_CONFIG_ADDR(base) ((base) + (0x0F04))
#define SOC_GPU_TILER_CONFIG_ADDR(base) ((base) + (0x0F08))
#define SOC_GPU_L2_MMU_CONFIG_ADDR(base) ((base) + (0x0F0C))
#define SOC_GPU_JOB_IRQ_RAWSTAT_ADDR(base) ((base) + (0x1000))
#define SOC_GPU_JOB_IRQ_CLEAR_ADDR(base) ((base) + (0x1004))
#define SOC_GPU_JOB_IRQ_MASK_ADDR(base) ((base) + (0x1008))
#define SOC_GPU_JOB_IRQ_STATUS_ADDR(base) ((base) + (0x100C))
#define SOC_GPU_JOB_IRQ_JS_STATE_ADDR(base) ((base) + (0x1010))
#define SOC_GPU_JOB_IRQ_THROTTLE_ADDR(base) ((base) + (0x1014))
#define SOC_GPU_EVENT_IRQ_RAWSTAT_ADDR(base) ((base) + (0x1020))
#define SOC_GPU_EVENT_IRQ_CLEAR_ADDR(base) ((base) + (0x1024))
#define SOC_GPU_EVENT_IRQ_CLEAR_ADDR(base) ((base) + (0x1028))
#define SOC_GPU_EVENT_IRQ_STATUS_ADDR(base) ((base) + (0x102C))
#define SOC_GPU_JS0_HEAD_LO_ADDR(base) ((base) + (0x1800))
#define SOC_GPU_JS0_HEAD_HI_ADDR(base) ((base) + (0x1804))
#define SOC_GPU_JS0_TAIL_LO_ADDR(base) ((base) + (0x1808))
#define SOC_GPU_JS0_TAIL_HI_ADDR(base) ((base) + (0x180C))
#define SOC_GPU_JS0_AFFINITY_LO_ADDR(base) ((base) + (0x1810))
#define SOC_GPU_JS0_AFFINITY_HI_ADDR(base) ((base) + (0x1814))
#define SOC_GPU_JS0_CONFIG_ADDR(base) ((base) + (0x1818))
#define SOC_GPU_JS0_XAFFINITY_ADDR(base) ((base) + (0x181C))
#define SOC_GPU_JS0_COMMAND_ADDR(base) ((base) + (0x1820))
#define SOC_GPU_JS0_STATUS_ADDR(base) ((base) + (0x1824))
#define SOC_GPU_JS0_FLUSH_ID_ADDR(base) ((base) + (0x1830))
#define SOC_GPU_JS0_EVENT_0_ADDR(base) ((base) + (0x1834))
#define SOC_GPU_JS0_EVENT_1_ADDR(base) ((base) + (0x1838))
#define SOC_GPU_JS0_EVENT_MASK_ADDR(base) ((base) + (0x183C))
#define SOC_GPU_JS0_HEAD_NEXT_LO_ADDR(base) ((base) + (0x1840))
#define SOC_GPU_JS0_HEAD_NEXT_HI_ADDR(base) ((base) + (0x1844))
#define SOC_GPU_JS0_AFFINITY_NEXT_LO_ADDR(base) ((base) + (0x1850))
#define SOC_GPU_JS0_AFFINITY_NEXT_HI_ADDR(base) ((base) + (0x1854))
#define SOC_GPU_JS0_CONFIG_NEXT_ADDR(base) ((base) + (0x1858))
#define SOC_GPU_JS0_XAFFINITY_NEXT_ADDR(base) ((base) + (0x185c))
#define SOC_GPU_JS0_COMMAND_NEXT_ADDR(base) ((base) + (0x1860))
#define SOC_GPU_MMU_IRQ_RAWSTAT_ADDR(base) ((base) + (0x2000))
#define SOC_GPU_MMU_IRQ_CLEAR_ADDR(base) ((base) + (0x2004))
#define SOC_GPU_MMU_IRQ_MASK_ADDR(base) ((base) + (0x2008))
#define SOC_GPU_MMU_IRQ_STATUS_ADDR(base) ((base) + (0x200C))
#define SOC_GPU_AS0_TRANSTAB_LO_ADDR(base) ((base) + (0x2400))
#define SOC_GPU_AS0_TRANSTAB_HI_ADDR(base) ((base) + (0x2404))
#define SOC_GPU_AS0_MEMATTR_LO_ADDR(base) ((base) + (0x2408))
#define SOC_GPU_AS0_MEMATTR_HI_ADDR(base) ((base) + (0x240C))
#define SOC_GPU_AS0_LOCKADDR_LO_ADDR(base) ((base) + (0x2410))
#define SOC_GPU_AS0_LOCKADDR_HI_ADDR(base) ((base) + (0x2414))
#define SOC_GPU_AS0_COMMAND_ADDR(base) ((base) + (0x2418))
#define SOC_GPU_AS0_FAULTSTATUS_ADDR(base) ((base) + (0x241C))
#define SOC_GPU_AS0_FAULTADDRESS_LO_ADDR(base) ((base) + (0x2420))
#define SOC_GPU_AS0_FAULTADDRESS_HI_ADDR(base) ((base) + (0x2424))
#define SOC_GPU_AS0_STATUS_ADDR(base) ((base) + (0x2428))
#define SOC_GPU_AS0_TRANSCFG_LO_ADDR(base) ((base) + (0x2430))
#define SOC_GPU_AS0_TRANSCFG_HI_ADDR(base) ((base) + (0x2434))
#define SOC_GPU_AS0_FAULTEXTRA_LO_ADDR(base) ((base) + (0x2438))
#define SOC_GPU_AS0_FAULTEXTRA_HI_ADDR(base) ((base) + (0x243C))
#define SOC_GPU_AS1_TRANSTAB_LO_ADDR(base) ((base) + (0x2440))
#define SOC_GPU_AS1_TRANSTAB_HI_ADDR(base) ((base) + (0x2444))
#define SOC_GPU_AS1_MEMATTR_LO_ADDR(base) ((base) + (0x2448))
#define SOC_GPU_AS1_MEMATTR_HI_ADDR(base) ((base) + (0x244C))
#define SOC_GPU_AS1_LOCKADDR_LO_ADDR(base) ((base) + (0x2450))
#define SOC_GPU_AS1_LOCKADDR_HI_ADDR(base) ((base) + (0x2454))
#define SOC_GPU_AS1_COMMAND_ADDR(base) ((base) + (0x2458))
#define SOC_GPU_AS1_FAULTSTATUS_ADDR(base) ((base) + (0x245C))
#define SOC_GPU_AS1_FAULTADDRESS_LO_ADDR(base) ((base) + (0x2460))
#define SOC_GPU_AS1_FAULTADDRESS_HI_ADDR(base) ((base) + (0x2464))
#define SOC_GPU_AS1_STATUS_ADDR(base) ((base) + (0x2468))
#define SOC_GPU_AS1_TRANSCFG_LO_ADDR(base) ((base) + (0x2470))
#define SOC_GPU_AS1_TRANSCFG_HI_ADDR(base) ((base) + (0x2474))
#define SOC_GPU_AS1_FAULTEXTRA_LO_ADDR(base) ((base) + (0x2478))
#define SOC_GPU_AS1_FAULTEXTRA_HI_ADDR(base) ((base) + (0x247C))
#define SOC_GPU_AS2_TRANSTAB_LO_ADDR(base) ((base) + (0x2480))
#define SOC_GPU_AS2_TRANSTAB_HI_ADDR(base) ((base) + (0x2484))
#define SOC_GPU_AS2_MEMATTR_LO_ADDR(base) ((base) + (0x2488))
#define SOC_GPU_AS2_MEMATTR_HI_ADDR(base) ((base) + (0x248C))
#define SOC_GPU_AS2_LOCKADDR_LO_ADDR(base) ((base) + (0x2490))
#define SOC_GPU_AS2_LOCKADDR_HI_ADDR(base) ((base) + (0x2494))
#define SOC_GPU_AS2_COMMAND_ADDR(base) ((base) + (0x2498))
#define SOC_GPU_AS2_FAULTSTATUS_ADDR(base) ((base) + (0x249C))
#define SOC_GPU_AS2_FAULTADDRESS_LO_ADDR(base) ((base) + (0x24A0))
#define SOC_GPU_AS2_FAULTADDRESS_HI_ADDR(base) ((base) + (0x24A4))
#define SOC_GPU_AS2_STATUS_ADDR(base) ((base) + (0x24A8))
#define SOC_GPU_AS2_TRANSCFG_LO_ADDR(base) ((base) + (0x24B0))
#define SOC_GPU_AS2_TRANSCFG_HI_ADDR(base) ((base) + (0x24B4))
#define SOC_GPU_AS2_FAULTEXTRA_LO_ADDR(base) ((base) + (0x24B8))
#define SOC_GPU_AS2_FAULTEXTRA_HI_ADDR(base) ((base) + (0x24BC))
#define SOC_GPU_AS3_TRANSTAB_LO_ADDR(base) ((base) + (0x24C0))
#define SOC_GPU_AS3_TRANSTAB_HI_ADDR(base) ((base) + (0x24C4))
#define SOC_GPU_AS3_MEMATTR_LO_ADDR(base) ((base) + (0x24C8))
#define SOC_GPU_AS3_MEMATTR_HI_ADDR(base) ((base) + (0x24CC))
#define SOC_GPU_AS3_LOCKADDR_LO_ADDR(base) ((base) + (0x24D0))
#define SOC_GPU_AS3_LOCKADDR_HI_ADDR(base) ((base) + (0x24D4))
#define SOC_GPU_AS3_COMMAND_ADDR(base) ((base) + (0x24D8))
#define SOC_GPU_AS3_FAULTSTATUS_ADDR(base) ((base) + (0x24DC))
#define SOC_GPU_AS3_FAULTADDRESS_LO_ADDR(base) ((base) + (0x24E0))
#define SOC_GPU_AS3_FAULTADDRESS_HI_ADDR(base) ((base) + (0x24E4))
#define SOC_GPU_AS3_STATUS_ADDR(base) ((base) + (0x24E8))
#define SOC_GPU_AS3_TRANSCFG_LO_ADDR(base) ((base) + (0x24F0))
#define SOC_GPU_AS3_TRANSCFG_HI_ADDR(base) ((base) + (0x24F4))
#define SOC_GPU_AS3_FAULTEXTRA_LO_ADDR(base) ((base) + (0x24F8))
#define SOC_GPU_AS3_FAULTEXTRA_HI_ADDR(base) ((base) + (0x24FC))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int version_status : 4;
        unsigned int version_minor : 8;
        unsigned int version_major : 4;
        unsigned int product_id : 16;
    } reg;
} SOC_GPU_ID_UNION;
#endif
#define SOC_GPU_ID_version_status_START (0)
#define SOC_GPU_ID_version_status_END (3)
#define SOC_GPU_ID_version_minor_START (4)
#define SOC_GPU_ID_version_minor_END (11)
#define SOC_GPU_ID_version_major_START (12)
#define SOC_GPU_ID_version_major_END (15)
#define SOC_GPU_ID_product_id_START (16)
#define SOC_GPU_ID_product_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int line_size : 8;
        unsigned int associativity : 8;
        unsigned int cache_size : 8;
        unsigned int external_bus_width : 8;
    } reg;
} SOC_GPU_L2_FEATURES_UNION;
#endif
#define SOC_GPU_L2_FEATURES_line_size_START (0)
#define SOC_GPU_L2_FEATURES_line_size_END (7)
#define SOC_GPU_L2_FEATURES_associativity_START (8)
#define SOC_GPU_L2_FEATURES_associativity_END (15)
#define SOC_GPU_L2_FEATURES_cache_size_START (16)
#define SOC_GPU_L2_FEATURES_cache_size_END (23)
#define SOC_GPU_L2_FEATURES_external_bus_width_START (24)
#define SOC_GPU_L2_FEATURES_external_bus_width_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bin_size : 6;
        unsigned int reserved_0 : 2;
        unsigned int max_active_levels : 4;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_GPU_TILER_FEATURES_UNION;
#endif
#define SOC_GPU_TILER_FEATURES_bin_size_START (0)
#define SOC_GPU_TILER_FEATURES_bin_size_END (5)
#define SOC_GPU_TILER_FEATURES_max_active_levels_START (8)
#define SOC_GPU_TILER_FEATURES_max_active_levels_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int COHERENT_CORE_GROUP : 1;
        unsigned int COHERENT_SUPERGROUP : 1;
        unsigned int reserved_0 : 6;
        unsigned int l2_slices : 4;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_GPU_MEM_FEATURES_UNION;
#endif
#define SOC_GPU_MEM_FEATURES_COHERENT_CORE_GROUP_START (0)
#define SOC_GPU_MEM_FEATURES_COHERENT_CORE_GROUP_END (0)
#define SOC_GPU_MEM_FEATURES_COHERENT_SUPERGROUP_START (1)
#define SOC_GPU_MEM_FEATURES_COHERENT_SUPERGROUP_END (1)
#define SOC_GPU_MEM_FEATURES_l2_slices_START (8)
#define SOC_GPU_MEM_FEATURES_l2_slices_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int va_bits : 8;
        unsigned int pa_bits : 8;
        unsigned int mmu_features : 16;
    } reg;
} SOC_GPU_MMU_FEATURES_UNION;
#endif
#define SOC_GPU_MMU_FEATURES_va_bits_START (0)
#define SOC_GPU_MMU_FEATURES_va_bits_END (7)
#define SOC_GPU_MMU_FEATURES_pa_bits_START (8)
#define SOC_GPU_MMU_FEATURES_pa_bits_END (15)
#define SOC_GPU_MMU_FEATURES_mmu_features_START (16)
#define SOC_GPU_MMU_FEATURES_mmu_features_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int as_present_low : 8;
        unsigned int as_present : 24;
    } reg;
} SOC_GPU_AS_PRESENT_UNION;
#endif
#define SOC_GPU_AS_PRESENT_as_present_low_START (0)
#define SOC_GPU_AS_PRESENT_as_present_low_END (7)
#define SOC_GPU_AS_PRESENT_as_present_START (8)
#define SOC_GPU_AS_PRESENT_as_present_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int js_present_low : 4;
        unsigned int js_present : 28;
    } reg;
} SOC_GPU_JS_PRESENT_UNION;
#endif
#define SOC_GPU_JS_PRESENT_js_present_low_START (0)
#define SOC_GPU_JS_PRESENT_js_present_low_END (3)
#define SOC_GPU_JS_PRESENT_js_present_START (4)
#define SOC_GPU_JS_PRESENT_js_present_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gpu_fault : 1;
        unsigned int reserved_0 : 6;
        unsigned int multi_gpu_fault : 1;
        unsigned int reset_completed : 1;
        unsigned int power_change_single : 1;
        unsigned int power_change_all : 1;
        unsigned int reserved_1 : 5;
        unsigned int prfcnt_sample_complete : 1;
        unsigned int clean_cache_completed : 1;
        unsigned int reserved_2 : 14;
    } reg;
} SOC_GPU_IRQ_RAWSTAT_UNION;
#endif
#define SOC_GPU_IRQ_RAWSTAT_gpu_fault_START (0)
#define SOC_GPU_IRQ_RAWSTAT_gpu_fault_END (0)
#define SOC_GPU_IRQ_RAWSTAT_multi_gpu_fault_START (7)
#define SOC_GPU_IRQ_RAWSTAT_multi_gpu_fault_END (7)
#define SOC_GPU_IRQ_RAWSTAT_reset_completed_START (8)
#define SOC_GPU_IRQ_RAWSTAT_reset_completed_END (8)
#define SOC_GPU_IRQ_RAWSTAT_power_change_single_START (9)
#define SOC_GPU_IRQ_RAWSTAT_power_change_single_END (9)
#define SOC_GPU_IRQ_RAWSTAT_power_change_all_START (10)
#define SOC_GPU_IRQ_RAWSTAT_power_change_all_END (10)
#define SOC_GPU_IRQ_RAWSTAT_prfcnt_sample_complete_START (16)
#define SOC_GPU_IRQ_RAWSTAT_prfcnt_sample_complete_END (16)
#define SOC_GPU_IRQ_RAWSTAT_clean_cache_completed_START (17)
#define SOC_GPU_IRQ_RAWSTAT_clean_cache_completed_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gpu_fault : 1;
        unsigned int reserved_0 : 6;
        unsigned int multi_gpu_fault : 1;
        unsigned int reset_completed : 1;
        unsigned int power_change_single : 1;
        unsigned int power_change_all : 1;
        unsigned int reserved_1 : 5;
        unsigned int prfcnt_sample_complete : 1;
        unsigned int clean_cache_completed : 1;
        unsigned int reserved_2 : 14;
    } reg;
} SOC_GPU_IRQ_CLEAR_UNION;
#endif
#define SOC_GPU_IRQ_CLEAR_gpu_fault_START (0)
#define SOC_GPU_IRQ_CLEAR_gpu_fault_END (0)
#define SOC_GPU_IRQ_CLEAR_multi_gpu_fault_START (7)
#define SOC_GPU_IRQ_CLEAR_multi_gpu_fault_END (7)
#define SOC_GPU_IRQ_CLEAR_reset_completed_START (8)
#define SOC_GPU_IRQ_CLEAR_reset_completed_END (8)
#define SOC_GPU_IRQ_CLEAR_power_change_single_START (9)
#define SOC_GPU_IRQ_CLEAR_power_change_single_END (9)
#define SOC_GPU_IRQ_CLEAR_power_change_all_START (10)
#define SOC_GPU_IRQ_CLEAR_power_change_all_END (10)
#define SOC_GPU_IRQ_CLEAR_prfcnt_sample_complete_START (16)
#define SOC_GPU_IRQ_CLEAR_prfcnt_sample_complete_END (16)
#define SOC_GPU_IRQ_CLEAR_clean_cache_completed_START (17)
#define SOC_GPU_IRQ_CLEAR_clean_cache_completed_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gpu_fault : 1;
        unsigned int reserved_0 : 6;
        unsigned int multi_gpu_fault : 1;
        unsigned int reset_completed : 1;
        unsigned int power_change_single : 1;
        unsigned int power_change_all : 1;
        unsigned int reserved_1 : 5;
        unsigned int prfcnt_sample_complete : 1;
        unsigned int clean_cache_completed : 1;
        unsigned int reserved_2 : 14;
    } reg;
} SOC_GPU_IRQ_MASK_UNION;
#endif
#define SOC_GPU_IRQ_MASK_gpu_fault_START (0)
#define SOC_GPU_IRQ_MASK_gpu_fault_END (0)
#define SOC_GPU_IRQ_MASK_multi_gpu_fault_START (7)
#define SOC_GPU_IRQ_MASK_multi_gpu_fault_END (7)
#define SOC_GPU_IRQ_MASK_reset_completed_START (8)
#define SOC_GPU_IRQ_MASK_reset_completed_END (8)
#define SOC_GPU_IRQ_MASK_power_change_single_START (9)
#define SOC_GPU_IRQ_MASK_power_change_single_END (9)
#define SOC_GPU_IRQ_MASK_power_change_all_START (10)
#define SOC_GPU_IRQ_MASK_power_change_all_END (10)
#define SOC_GPU_IRQ_MASK_prfcnt_sample_complete_START (16)
#define SOC_GPU_IRQ_MASK_prfcnt_sample_complete_END (16)
#define SOC_GPU_IRQ_MASK_clean_cache_completed_START (17)
#define SOC_GPU_IRQ_MASK_clean_cache_completed_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gpu_fault : 1;
        unsigned int reserved_0 : 6;
        unsigned int multi_gpu_fault : 1;
        unsigned int reset_completed : 1;
        unsigned int power_change_single : 1;
        unsigned int power_change_all : 1;
        unsigned int reserved_1 : 5;
        unsigned int prfcnt_sample_complete : 1;
        unsigned int clean_cache_completed : 1;
        unsigned int reserved_2 : 14;
    } reg;
} SOC_GPU_IRQ_STATUS_UNION;
#endif
#define SOC_GPU_IRQ_STATUS_gpu_fault_START (0)
#define SOC_GPU_IRQ_STATUS_gpu_fault_END (0)
#define SOC_GPU_IRQ_STATUS_multi_gpu_fault_START (7)
#define SOC_GPU_IRQ_STATUS_multi_gpu_fault_END (7)
#define SOC_GPU_IRQ_STATUS_reset_completed_START (8)
#define SOC_GPU_IRQ_STATUS_reset_completed_END (8)
#define SOC_GPU_IRQ_STATUS_power_change_single_START (9)
#define SOC_GPU_IRQ_STATUS_power_change_single_END (9)
#define SOC_GPU_IRQ_STATUS_power_change_all_START (10)
#define SOC_GPU_IRQ_STATUS_power_change_all_END (10)
#define SOC_GPU_IRQ_STATUS_prfcnt_sample_complete_START (16)
#define SOC_GPU_IRQ_STATUS_prfcnt_sample_complete_END (16)
#define SOC_GPU_IRQ_STATUS_clean_cache_completed_START (17)
#define SOC_GPU_IRQ_STATUS_clean_cache_completed_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gpu_command : 32;
    } reg;
} SOC_GPU_COMMAND_UNION;
#endif
#define SOC_GPU_COMMAND_gpu_command_START (0)
#define SOC_GPU_COMMAND_gpu_command_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gpu_active : 1;
        unsigned int pwr_active : 1;
        unsigned int prfcnt_active : 1;
        unsigned int job_active : 1;
        unsigned int page_fault : 1;
        unsigned int irq_active : 1;
        unsigned int cycle_count_active : 1;
        unsigned int protected_mode_active : 1;
        unsigned int debug_enable : 1;
        unsigned int gpu_status : 23;
    } reg;
} SOC_GPU_STATUS_UNION;
#endif
#define SOC_GPU_STATUS_gpu_active_START (0)
#define SOC_GPU_STATUS_gpu_active_END (0)
#define SOC_GPU_STATUS_pwr_active_START (1)
#define SOC_GPU_STATUS_pwr_active_END (1)
#define SOC_GPU_STATUS_prfcnt_active_START (2)
#define SOC_GPU_STATUS_prfcnt_active_END (2)
#define SOC_GPU_STATUS_job_active_START (3)
#define SOC_GPU_STATUS_job_active_END (3)
#define SOC_GPU_STATUS_page_fault_START (4)
#define SOC_GPU_STATUS_page_fault_END (4)
#define SOC_GPU_STATUS_irq_active_START (5)
#define SOC_GPU_STATUS_irq_active_END (5)
#define SOC_GPU_STATUS_cycle_count_active_START (6)
#define SOC_GPU_STATUS_cycle_count_active_END (6)
#define SOC_GPU_STATUS_protected_mode_active_START (7)
#define SOC_GPU_STATUS_protected_mode_active_END (7)
#define SOC_GPU_STATUS_debug_enable_START (8)
#define SOC_GPU_STATUS_debug_enable_END (8)
#define SOC_GPU_STATUS_gpu_status_START (9)
#define SOC_GPU_STATUS_gpu_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int latest_flush : 32;
    } reg;
} SOC_GPU_LATEST_FLUSH_UNION;
#endif
#define SOC_GPU_LATEST_FLUSH_latest_flush_START (0)
#define SOC_GPU_LATEST_FLUSH_latest_flush_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int exception_type : 8;
        unsigned int access_type : 2;
        unsigned int gpu_faultstatus : 22;
    } reg;
} SOC_GPU_FAULTSTATUS_UNION;
#endif
#define SOC_GPU_FAULTSTATUS_exception_type_START (0)
#define SOC_GPU_FAULTSTATUS_exception_type_END (7)
#define SOC_GPU_FAULTSTATUS_access_type_START (8)
#define SOC_GPU_FAULTSTATUS_access_type_END (9)
#define SOC_GPU_FAULTSTATUS_gpu_faultstatus_START (10)
#define SOC_GPU_FAULTSTATUS_gpu_faultstatus_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gpu_faultaddress_lo : 32;
    } reg;
} SOC_GPU_FAULTADDRESS_LO_UNION;
#endif
#define SOC_GPU_FAULTADDRESS_LO_gpu_faultaddress_lo_START (0)
#define SOC_GPU_FAULTADDRESS_LO_gpu_faultaddress_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gpu_faultaddress_hi : 32;
    } reg;
} SOC_GPU_FAULTADDRESS_HI_UNION;
#endif
#define SOC_GPU_FAULTADDRESS_HI_gpu_faultaddress_hi_START (0)
#define SOC_GPU_FAULTADDRESS_HI_gpu_faultaddress_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pwr_key : 32;
    } reg;
} SOC_GPU_PWR_KEY_UNION;
#endif
#define SOC_GPU_PWR_KEY_pwr_key_START (0)
#define SOC_GPU_PWR_KEY_pwr_key_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pwrup_override : 2;
        unsigned int isolate_override : 2;
        unsigned int reset_override : 2;
        unsigned int reserved_0 : 2;
        unsigned int pwrup_ack_override : 2;
        unsigned int isolate_ack_override : 2;
        unsigned int func_iso_override : 2;
        unsigned int func_iso_ack_override : 2;
        unsigned int pwrtrans_limt : 6;
        unsigned int reserved_1 : 1;
        unsigned int throttle_enable : 1;
        unsigned int throttle_limit : 6;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_GPU_PWR_KEYOVERRIDE0_UNION;
#endif
#define SOC_GPU_PWR_KEYOVERRIDE0_pwrup_override_START (0)
#define SOC_GPU_PWR_KEYOVERRIDE0_pwrup_override_END (1)
#define SOC_GPU_PWR_KEYOVERRIDE0_isolate_override_START (2)
#define SOC_GPU_PWR_KEYOVERRIDE0_isolate_override_END (3)
#define SOC_GPU_PWR_KEYOVERRIDE0_reset_override_START (4)
#define SOC_GPU_PWR_KEYOVERRIDE0_reset_override_END (5)
#define SOC_GPU_PWR_KEYOVERRIDE0_pwrup_ack_override_START (8)
#define SOC_GPU_PWR_KEYOVERRIDE0_pwrup_ack_override_END (9)
#define SOC_GPU_PWR_KEYOVERRIDE0_isolate_ack_override_START (10)
#define SOC_GPU_PWR_KEYOVERRIDE0_isolate_ack_override_END (11)
#define SOC_GPU_PWR_KEYOVERRIDE0_func_iso_override_START (12)
#define SOC_GPU_PWR_KEYOVERRIDE0_func_iso_override_END (13)
#define SOC_GPU_PWR_KEYOVERRIDE0_func_iso_ack_override_START (14)
#define SOC_GPU_PWR_KEYOVERRIDE0_func_iso_ack_override_END (15)
#define SOC_GPU_PWR_KEYOVERRIDE0_pwrtrans_limt_START (16)
#define SOC_GPU_PWR_KEYOVERRIDE0_pwrtrans_limt_END (21)
#define SOC_GPU_PWR_KEYOVERRIDE0_throttle_enable_START (23)
#define SOC_GPU_PWR_KEYOVERRIDE0_throttle_enable_END (23)
#define SOC_GPU_PWR_KEYOVERRIDE0_throttle_limit_START (24)
#define SOC_GPU_PWR_KEYOVERRIDE0_throttle_limit_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_GPU_PWR_KEYOVERRIDE1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 8;
        unsigned int prfcnt_base : 24;
    } reg;
} SOC_GPU_PRFCNT_BASE_LO_UNION;
#endif
#define SOC_GPU_PRFCNT_BASE_LO_prfcnt_base_START (8)
#define SOC_GPU_PRFCNT_BASE_LO_prfcnt_base_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int prfcnt_base : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_GPU_PRFCNT_BASE_HI_UNION;
#endif
#define SOC_GPU_PRFCNT_BASE_HI_prfcnt_base_START (0)
#define SOC_GPU_PRFCNT_BASE_HI_prfcnt_base_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mode : 4;
        unsigned int address_space : 4;
        unsigned int set_select : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_GPU_PRFCNT_CONFIG_UNION;
#endif
#define SOC_GPU_PRFCNT_CONFIG_mode_START (0)
#define SOC_GPU_PRFCNT_CONFIG_mode_END (3)
#define SOC_GPU_PRFCNT_CONFIG_address_space_START (4)
#define SOC_GPU_PRFCNT_CONFIG_address_space_END (7)
#define SOC_GPU_PRFCNT_CONFIG_set_select_START (8)
#define SOC_GPU_PRFCNT_CONFIG_set_select_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pfrcnt_jm_en : 32;
    } reg;
} SOC_GPU_PRFCNT_JM_EN_UNION;
#endif
#define SOC_GPU_PRFCNT_JM_EN_pfrcnt_jm_en_START (0)
#define SOC_GPU_PRFCNT_JM_EN_pfrcnt_jm_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pfrcnt_shader_en : 32;
    } reg;
} SOC_GPU_PRFCNT_SHADER_EN_UNION;
#endif
#define SOC_GPU_PRFCNT_SHADER_EN_pfrcnt_shader_en_START (0)
#define SOC_GPU_PRFCNT_SHADER_EN_pfrcnt_shader_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pfrcnt_tiler_en : 32;
    } reg;
} SOC_GPU_PRFCNT_TILER_EN_UNION;
#endif
#define SOC_GPU_PRFCNT_TILER_EN_pfrcnt_tiler_en_START (0)
#define SOC_GPU_PRFCNT_TILER_EN_pfrcnt_tiler_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pfrcnt_mmu_en : 32;
    } reg;
} SOC_GPU_PRFCNT_MMU_L2_EN_UNION;
#endif
#define SOC_GPU_PRFCNT_MMU_L2_EN_pfrcnt_mmu_en_START (0)
#define SOC_GPU_PRFCNT_MMU_L2_EN_pfrcnt_mmu_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cycle_count_lo : 32;
    } reg;
} SOC_GPU_CYCLE_COUNT_LO_UNION;
#endif
#define SOC_GPU_CYCLE_COUNT_LO_cycle_count_lo_START (0)
#define SOC_GPU_CYCLE_COUNT_LO_cycle_count_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cycle_count_hi : 32;
    } reg;
} SOC_GPU_CYCLE_COUNT_HI_UNION;
#endif
#define SOC_GPU_CYCLE_COUNT_HI_cycle_count_hi_START (0)
#define SOC_GPU_CYCLE_COUNT_HI_cycle_count_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int timestamp_lo : 32;
    } reg;
} SOC_GPU_TIMESTAMP_LO_UNION;
#endif
#define SOC_GPU_TIMESTAMP_LO_timestamp_lo_START (0)
#define SOC_GPU_TIMESTAMP_LO_timestamp_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int timestamp_hi : 32;
    } reg;
} SOC_GPU_TIMESTAMP_HI_UNION;
#endif
#define SOC_GPU_TIMESTAMP_HI_timestamp_hi_START (0)
#define SOC_GPU_TIMESTAMP_HI_timestamp_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int thread_max_thread : 32;
    } reg;
} SOC_GPU_THREAD_MAX_THREADS_UNION;
#endif
#define SOC_GPU_THREAD_MAX_THREADS_thread_max_thread_START (0)
#define SOC_GPU_THREAD_MAX_THREADS_thread_max_thread_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int thread_max_workgroup : 32;
    } reg;
} SOC_GPU_THREAD_MAX_WORKGROUP_UNION;
#endif
#define SOC_GPU_THREAD_MAX_WORKGROUP_thread_max_workgroup_START (0)
#define SOC_GPU_THREAD_MAX_WORKGROUP_thread_max_workgroup_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int thread_max_barrier_size : 32;
    } reg;
} SOC_GPU_THREAD_MAX_BARRIER_SIZE_UNION;
#endif
#define SOC_GPU_THREAD_MAX_BARRIER_SIZE_thread_max_barrier_size_START (0)
#define SOC_GPU_THREAD_MAX_BARRIER_SIZE_thread_max_barrier_size_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int max_registers : 16;
        unsigned int max_task_queue : 8;
        unsigned int max_thread_group_split : 6;
        unsigned int implementattion_technology : 2;
    } reg;
} SOC_GPU_THREAD_FEATURES_UNION;
#endif
#define SOC_GPU_THREAD_FEATURES_max_registers_START (0)
#define SOC_GPU_THREAD_FEATURES_max_registers_END (15)
#define SOC_GPU_THREAD_FEATURES_max_task_queue_START (16)
#define SOC_GPU_THREAD_FEATURES_max_task_queue_END (23)
#define SOC_GPU_THREAD_FEATURES_max_thread_group_split_START (24)
#define SOC_GPU_THREAD_FEATURES_max_thread_group_split_END (29)
#define SOC_GPU_THREAD_FEATURES_implementattion_technology_START (30)
#define SOC_GPU_THREAD_FEATURES_implementattion_technology_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int texture_features_0 : 32;
    } reg;
} SOC_GPU_TEXTURE_FEATURES_0_UNION;
#endif
#define SOC_GPU_TEXTURE_FEATURES_0_texture_features_0_START (0)
#define SOC_GPU_TEXTURE_FEATURES_0_texture_features_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int texture_features_1 : 32;
    } reg;
} SOC_GPU_TEXTURE_FEATURES_1_UNION;
#endif
#define SOC_GPU_TEXTURE_FEATURES_1_texture_features_1_START (0)
#define SOC_GPU_TEXTURE_FEATURES_1_texture_features_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int texture_features_2 : 32;
    } reg;
} SOC_GPU_TEXTURE_FEATURES_2_UNION;
#endif
#define SOC_GPU_TEXTURE_FEATURES_2_texture_features_2_START (0)
#define SOC_GPU_TEXTURE_FEATURES_2_texture_features_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int js0_features : 32;
    } reg;
} SOC_GPU_JS0_FEATURES_UNION;
#endif
#define SOC_GPU_JS0_FEATURES_js0_features_START (0)
#define SOC_GPU_JS0_FEATURES_js0_features_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int js1_features : 32;
    } reg;
} SOC_GPU_JS1_FEATURES_UNION;
#endif
#define SOC_GPU_JS1_FEATURES_js1_features_START (0)
#define SOC_GPU_JS1_FEATURES_js1_features_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int js2_features : 32;
    } reg;
} SOC_GPU_JS2_FEATURES_UNION;
#endif
#define SOC_GPU_JS2_FEATURES_js2_features_START (0)
#define SOC_GPU_JS2_FEATURES_js2_features_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int shader_present_lo : 32;
    } reg;
} SOC_GPU_SHADER_PRESENT_LO_UNION;
#endif
#define SOC_GPU_SHADER_PRESENT_LO_shader_present_lo_START (0)
#define SOC_GPU_SHADER_PRESENT_LO_shader_present_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int shader_present_hi : 32;
    } reg;
} SOC_GPU_SHADER_PRESENT_HI_UNION;
#endif
#define SOC_GPU_SHADER_PRESENT_HI_shader_present_hi_START (0)
#define SOC_GPU_SHADER_PRESENT_HI_shader_present_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tiler_present_lo : 32;
    } reg;
} SOC_GPU_TILER_PRESENT_LO_UNION;
#endif
#define SOC_GPU_TILER_PRESENT_LO_tiler_present_lo_START (0)
#define SOC_GPU_TILER_PRESENT_LO_tiler_present_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tiler_present_hi : 32;
    } reg;
} SOC_GPU_TILER_PRESENT_HI_UNION;
#endif
#define SOC_GPU_TILER_PRESENT_HI_tiler_present_hi_START (0)
#define SOC_GPU_TILER_PRESENT_HI_tiler_present_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_present_lo : 32;
    } reg;
} SOC_GPU_L2_PRESENT_LO_UNION;
#endif
#define SOC_GPU_L2_PRESENT_LO_l2_present_lo_START (0)
#define SOC_GPU_L2_PRESENT_LO_l2_present_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_present_hi : 32;
    } reg;
} SOC_GPU_L2_PRESENT_HI_UNION;
#endif
#define SOC_GPU_L2_PRESENT_HI_l2_present_hi_START (0)
#define SOC_GPU_L2_PRESENT_HI_l2_present_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int shader_ready_lo : 32;
    } reg;
} SOC_GPU_SHADER_READY_LO_UNION;
#endif
#define SOC_GPU_SHADER_READY_LO_shader_ready_lo_START (0)
#define SOC_GPU_SHADER_READY_LO_shader_ready_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int shader_ready_hi : 32;
    } reg;
} SOC_GPU_SHADER_READY_HI_UNION;
#endif
#define SOC_GPU_SHADER_READY_HI_shader_ready_hi_START (0)
#define SOC_GPU_SHADER_READY_HI_shader_ready_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tiler_ready_lo : 32;
    } reg;
} SOC_GPU_TILER_READY_LO_UNION;
#endif
#define SOC_GPU_TILER_READY_LO_tiler_ready_lo_START (0)
#define SOC_GPU_TILER_READY_LO_tiler_ready_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tiler_ready_hi : 32;
    } reg;
} SOC_GPU_TILER_READY_HI_UNION;
#endif
#define SOC_GPU_TILER_READY_HI_tiler_ready_hi_START (0)
#define SOC_GPU_TILER_READY_HI_tiler_ready_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_ready_lo : 32;
    } reg;
} SOC_GPU_L2_READY_LO_UNION;
#endif
#define SOC_GPU_L2_READY_LO_l2_ready_lo_START (0)
#define SOC_GPU_L2_READY_LO_l2_ready_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_ready_hi : 32;
    } reg;
} SOC_GPU_L2_READY_HI_UNION;
#endif
#define SOC_GPU_L2_READY_HI_l2_ready_hi_START (0)
#define SOC_GPU_L2_READY_HI_l2_ready_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int shader_pwron_lo : 32;
    } reg;
} SOC_GPU_SHADER_PWRON_LO_UNION;
#endif
#define SOC_GPU_SHADER_PWRON_LO_shader_pwron_lo_START (0)
#define SOC_GPU_SHADER_PWRON_LO_shader_pwron_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int shader_pwron_hi : 32;
    } reg;
} SOC_GPU_SHADER_PWRON_HI_UNION;
#endif
#define SOC_GPU_SHADER_PWRON_HI_shader_pwron_hi_START (0)
#define SOC_GPU_SHADER_PWRON_HI_shader_pwron_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tiler_pwron_lo : 32;
    } reg;
} SOC_GPU_TILER_PWRON_LO_UNION;
#endif
#define SOC_GPU_TILER_PWRON_LO_tiler_pwron_lo_START (0)
#define SOC_GPU_TILER_PWRON_LO_tiler_pwron_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tiler_pwron_hi : 32;
    } reg;
} SOC_GPU_TILER_PWRON_HI_UNION;
#endif
#define SOC_GPU_TILER_PWRON_HI_tiler_pwron_hi_START (0)
#define SOC_GPU_TILER_PWRON_HI_tiler_pwron_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_pwron_lo : 32;
    } reg;
} SOC_GPU_L2_PWRON_LO_UNION;
#endif
#define SOC_GPU_L2_PWRON_LO_l2_pwron_lo_START (0)
#define SOC_GPU_L2_PWRON_LO_l2_pwron_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_pwron_hi : 32;
    } reg;
} SOC_GPU_L2_PWRON_HI_UNION;
#endif
#define SOC_GPU_L2_PWRON_HI_l2_pwron_hi_START (0)
#define SOC_GPU_L2_PWRON_HI_l2_pwron_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int shader_pwroff_lo : 32;
    } reg;
} SOC_GPU_SHADER_PWROFF_LO_UNION;
#endif
#define SOC_GPU_SHADER_PWROFF_LO_shader_pwroff_lo_START (0)
#define SOC_GPU_SHADER_PWROFF_LO_shader_pwroff_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int shader_pwroff_hi : 32;
    } reg;
} SOC_GPU_SHADER_PWROFF_HI_UNION;
#endif
#define SOC_GPU_SHADER_PWROFF_HI_shader_pwroff_hi_START (0)
#define SOC_GPU_SHADER_PWROFF_HI_shader_pwroff_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tiler_pwroff_lo : 32;
    } reg;
} SOC_GPU_TILER_PWROFF_LO_UNION;
#endif
#define SOC_GPU_TILER_PWROFF_LO_tiler_pwroff_lo_START (0)
#define SOC_GPU_TILER_PWROFF_LO_tiler_pwroff_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tiler_pwroff_hi : 32;
    } reg;
} SOC_GPU_TILER_PWROFF_HI_UNION;
#endif
#define SOC_GPU_TILER_PWROFF_HI_tiler_pwroff_hi_START (0)
#define SOC_GPU_TILER_PWROFF_HI_tiler_pwroff_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_pwroff_lo : 32;
    } reg;
} SOC_GPU_L2_PWROFF_LO_UNION;
#endif
#define SOC_GPU_L2_PWROFF_LO_l2_pwroff_lo_START (0)
#define SOC_GPU_L2_PWROFF_LO_l2_pwroff_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_pwroff_hi : 32;
    } reg;
} SOC_GPU_L2_PWROFF_HI_UNION;
#endif
#define SOC_GPU_L2_PWROFF_HI_l2_pwroff_hi_START (0)
#define SOC_GPU_L2_PWROFF_HI_l2_pwroff_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int shader_pwrtrans_lo : 32;
    } reg;
} SOC_GPU_SHADER_PWRTRANS_LO_UNION;
#endif
#define SOC_GPU_SHADER_PWRTRANS_LO_shader_pwrtrans_lo_START (0)
#define SOC_GPU_SHADER_PWRTRANS_LO_shader_pwrtrans_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int shader_pwrtrans_hi : 32;
    } reg;
} SOC_GPU_SHADER_PWRTRANS_HI_UNION;
#endif
#define SOC_GPU_SHADER_PWRTRANS_HI_shader_pwrtrans_hi_START (0)
#define SOC_GPU_SHADER_PWRTRANS_HI_shader_pwrtrans_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tiler_pwrtrans_lo : 32;
    } reg;
} SOC_GPU_TILER_PWRTRANS_LO_UNION;
#endif
#define SOC_GPU_TILER_PWRTRANS_LO_tiler_pwrtrans_lo_START (0)
#define SOC_GPU_TILER_PWRTRANS_LO_tiler_pwrtrans_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tiler_pwrtrans_hi : 32;
    } reg;
} SOC_GPU_TILER_PWRTRANS_HI_UNION;
#endif
#define SOC_GPU_TILER_PWRTRANS_HI_tiler_pwrtrans_hi_START (0)
#define SOC_GPU_TILER_PWRTRANS_HI_tiler_pwrtrans_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_pwrtrans_lo : 32;
    } reg;
} SOC_GPU_L2_PWRTRANS_LO_UNION;
#endif
#define SOC_GPU_L2_PWRTRANS_LO_l2_pwrtrans_lo_START (0)
#define SOC_GPU_L2_PWRTRANS_LO_l2_pwrtrans_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_pwrtrans_hi : 32;
    } reg;
} SOC_GPU_L2_PWRTRANS_HI_UNION;
#endif
#define SOC_GPU_L2_PWRTRANS_HI_l2_pwrtrans_hi_START (0)
#define SOC_GPU_L2_PWRTRANS_HI_l2_pwrtrans_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int shader_pwractive_lo : 32;
    } reg;
} SOC_GPU_SHADER_PWRACTIVE_LO_UNION;
#endif
#define SOC_GPU_SHADER_PWRACTIVE_LO_shader_pwractive_lo_START (0)
#define SOC_GPU_SHADER_PWRACTIVE_LO_shader_pwractive_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int shader_pwractive_hi : 32;
    } reg;
} SOC_GPU_SHADER_PWRACTIVE_HI_UNION;
#endif
#define SOC_GPU_SHADER_PWRACTIVE_HI_shader_pwractive_hi_START (0)
#define SOC_GPU_SHADER_PWRACTIVE_HI_shader_pwractive_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tiler_pwractive_lo : 32;
    } reg;
} SOC_GPU_TILER_PWRACTIVE_LO_UNION;
#endif
#define SOC_GPU_TILER_PWRACTIVE_LO_tiler_pwractive_lo_START (0)
#define SOC_GPU_TILER_PWRACTIVE_LO_tiler_pwractive_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tiler_pwractive_hi : 32;
    } reg;
} SOC_GPU_TILER_PWRACTIVE_HI_UNION;
#endif
#define SOC_GPU_TILER_PWRACTIVE_HI_tiler_pwractive_hi_START (0)
#define SOC_GPU_TILER_PWRACTIVE_HI_tiler_pwractive_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_pwractive_lo : 32;
    } reg;
} SOC_GPU_L2_PWRACTIVE_LO_UNION;
#endif
#define SOC_GPU_L2_PWRACTIVE_LO_l2_pwractive_lo_START (0)
#define SOC_GPU_L2_PWRACTIVE_LO_l2_pwractive_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_pwractive_hi : 32;
    } reg;
} SOC_GPU_L2_PWRACTIVE_HI_UNION;
#endif
#define SOC_GPU_L2_PWRACTIVE_HI_l2_pwractive_hi_START (0)
#define SOC_GPU_L2_PWRACTIVE_HI_l2_pwractive_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ace_lite : 1;
        unsigned int ace : 1;
        unsigned int reserved : 29;
        unsigned int no_coherency : 1;
    } reg;
} SOC_GPU_COHERENCY_FEATURES_UNION;
#endif
#define SOC_GPU_COHERENCY_FEATURES_ace_lite_START (0)
#define SOC_GPU_COHERENCY_FEATURES_ace_lite_END (0)
#define SOC_GPU_COHERENCY_FEATURES_ace_START (1)
#define SOC_GPU_COHERENCY_FEATURES_ace_END (1)
#define SOC_GPU_COHERENCY_FEATURES_no_coherency_START (31)
#define SOC_GPU_COHERENCY_FEATURES_no_coherency_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_cache_protocol_select : 5;
        unsigned int l2_cache_protocol : 27;
    } reg;
} SOC_GPU_COHERENCY_ENABLE_UNION;
#endif
#define SOC_GPU_COHERENCY_ENABLE_l2_cache_protocol_select_START (0)
#define SOC_GPU_COHERENCY_ENABLE_l2_cache_protocol_select_END (4)
#define SOC_GPU_COHERENCY_ENABLE_l2_cache_protocol_START (5)
#define SOC_GPU_COHERENCY_ENABLE_l2_cache_protocol_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int jm_config : 32;
    } reg;
} SOC_GPU_JM_CONFIG_UNION;
#endif
#define SOC_GPU_JM_CONFIG_jm_config_START (0)
#define SOC_GPU_JM_CONFIG_jm_config_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int shader_config : 32;
    } reg;
} SOC_GPU_SHADER_CONFIG_UNION;
#endif
#define SOC_GPU_SHADER_CONFIG_shader_config_START (0)
#define SOC_GPU_SHADER_CONFIG_shader_config_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tiler_config : 32;
    } reg;
} SOC_GPU_TILER_CONFIG_UNION;
#endif
#define SOC_GPU_TILER_CONFIG_tiler_config_START (0)
#define SOC_GPU_TILER_CONFIG_tiler_config_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_mmu_config : 32;
    } reg;
} SOC_GPU_L2_MMU_CONFIG_UNION;
#endif
#define SOC_GPU_L2_MMU_CONFIG_l2_mmu_config_START (0)
#define SOC_GPU_L2_MMU_CONFIG_l2_mmu_config_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int job_done : 3;
        unsigned int reserved_0: 13;
        unsigned int job_fail : 3;
        unsigned int reserved_1: 13;
    } reg;
} SOC_GPU_JOB_IRQ_RAWSTAT_UNION;
#endif
#define SOC_GPU_JOB_IRQ_RAWSTAT_job_done_START (0)
#define SOC_GPU_JOB_IRQ_RAWSTAT_job_done_END (2)
#define SOC_GPU_JOB_IRQ_RAWSTAT_job_fail_START (16)
#define SOC_GPU_JOB_IRQ_RAWSTAT_job_fail_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int job_done : 3;
        unsigned int reserved : 13;
        unsigned int job_fail : 3;
        unsigned int job_irq_clear : 13;
    } reg;
} SOC_GPU_JOB_IRQ_CLEAR_UNION;
#endif
#define SOC_GPU_JOB_IRQ_CLEAR_job_done_START (0)
#define SOC_GPU_JOB_IRQ_CLEAR_job_done_END (2)
#define SOC_GPU_JOB_IRQ_CLEAR_job_fail_START (16)
#define SOC_GPU_JOB_IRQ_CLEAR_job_fail_END (18)
#define SOC_GPU_JOB_IRQ_CLEAR_job_irq_clear_START (19)
#define SOC_GPU_JOB_IRQ_CLEAR_job_irq_clear_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int job_done : 3;
        unsigned int reserved_0: 13;
        unsigned int job_fail : 3;
        unsigned int reserved_1: 13;
    } reg;
} SOC_GPU_JOB_IRQ_MASK_UNION;
#endif
#define SOC_GPU_JOB_IRQ_MASK_job_done_START (0)
#define SOC_GPU_JOB_IRQ_MASK_job_done_END (2)
#define SOC_GPU_JOB_IRQ_MASK_job_fail_START (16)
#define SOC_GPU_JOB_IRQ_MASK_job_fail_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int job_done : 3;
        unsigned int reserved_0: 13;
        unsigned int job_fail : 3;
        unsigned int reserved_1: 13;
    } reg;
} SOC_GPU_JOB_IRQ_STATUS_UNION;
#endif
#define SOC_GPU_JOB_IRQ_STATUS_job_done_START (0)
#define SOC_GPU_JOB_IRQ_STATUS_job_done_END (2)
#define SOC_GPU_JOB_IRQ_STATUS_job_fail_START (16)
#define SOC_GPU_JOB_IRQ_STATUS_job_fail_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int job_active_n : 16;
        unsigned int job_next_active_n : 16;
    } reg;
} SOC_GPU_JOB_IRQ_JS_STATE_UNION;
#endif
#define SOC_GPU_JOB_IRQ_JS_STATE_job_active_n_START (0)
#define SOC_GPU_JOB_IRQ_JS_STATE_job_active_n_END (15)
#define SOC_GPU_JOB_IRQ_JS_STATE_job_next_active_n_START (16)
#define SOC_GPU_JOB_IRQ_JS_STATE_job_next_active_n_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int job_irq_throttle : 32;
    } reg;
} SOC_GPU_JOB_IRQ_THROTTLE_UNION;
#endif
#define SOC_GPU_JOB_IRQ_THROTTLE_job_irq_throttle_START (0)
#define SOC_GPU_JOB_IRQ_THROTTLE_job_irq_throttle_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int evnent_done : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_GPU_EVENT_IRQ_RAWSTAT_UNION;
#endif
#define SOC_GPU_EVENT_IRQ_RAWSTAT_evnent_done_START (0)
#define SOC_GPU_EVENT_IRQ_RAWSTAT_evnent_done_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int evnent_done : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_GPU_EVENT_IRQ_CLEAR_UNION;
#endif
#define SOC_GPU_EVENT_IRQ_CLEAR_evnent_done_START (0)
#define SOC_GPU_EVENT_IRQ_CLEAR_evnent_done_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int evnent_done : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_GPU_EVENT_IRQ_MASK_UNION;
#endif
#define SOC_GPU_EVENT_IRQ_MASK_evnent_done_START (0)
#define SOC_GPU_EVENT_IRQ_MASK_evnent_done_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int evnent_done : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_GPU_EVENT_IRQ_STATUS_UNION;
#endif
#define SOC_GPU_EVENT_IRQ_STATUS_evnent_done_START (0)
#define SOC_GPU_EVENT_IRQ_STATUS_evnent_done_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 6;
        unsigned int js0_head_lo : 26;
    } reg;
} SOC_GPU_JS0_HEAD_LO_UNION;
#endif
#define SOC_GPU_JS0_HEAD_LO_js0_head_lo_START (6)
#define SOC_GPU_JS0_HEAD_LO_js0_head_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int js0_head_hi : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_GPU_JS0_HEAD_HI_UNION;
#endif
#define SOC_GPU_JS0_HEAD_HI_js0_head_hi_START (0)
#define SOC_GPU_JS0_HEAD_HI_js0_head_hi_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 6;
        unsigned int js0_tail_lo : 26;
    } reg;
} SOC_GPU_JS0_TAIL_LO_UNION;
#endif
#define SOC_GPU_JS0_TAIL_LO_js0_tail_lo_START (6)
#define SOC_GPU_JS0_TAIL_LO_js0_tail_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int js0_tail_hi : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_GPU_JS0_TAIL_HI_UNION;
#endif
#define SOC_GPU_JS0_TAIL_HI_js0_tail_hi_START (0)
#define SOC_GPU_JS0_TAIL_HI_js0_tail_hi_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int js0_affinity_lo : 32;
    } reg;
} SOC_GPU_JS0_AFFINITY_LO_UNION;
#endif
#define SOC_GPU_JS0_AFFINITY_LO_js0_affinity_lo_START (0)
#define SOC_GPU_JS0_AFFINITY_LO_js0_affinity_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int js0_affinity_hi : 32;
    } reg;
} SOC_GPU_JS0_AFFINITY_HI_UNION;
#endif
#define SOC_GPU_JS0_AFFINITY_HI_js0_affinity_hi_START (0)
#define SOC_GPU_JS0_AFFINITY_HI_js0_affinity_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int address_space : 4;
        unsigned int reserved_0 : 4;
        unsigned int start_flush : 2;
        unsigned int start_mmu : 1;
        unsigned int job_chain_flag : 1;
        unsigned int end_flush : 2;
        unsigned int enable_flush_reduction : 1;
        unsigned int disable_descriptor : 1;
        unsigned int thread_priority : 4;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_GPU_JS0_CONFIG_UNION;
#endif
#define SOC_GPU_JS0_CONFIG_address_space_START (0)
#define SOC_GPU_JS0_CONFIG_address_space_END (3)
#define SOC_GPU_JS0_CONFIG_start_flush_START (8)
#define SOC_GPU_JS0_CONFIG_start_flush_END (9)
#define SOC_GPU_JS0_CONFIG_start_mmu_START (10)
#define SOC_GPU_JS0_CONFIG_start_mmu_END (10)
#define SOC_GPU_JS0_CONFIG_job_chain_flag_START (11)
#define SOC_GPU_JS0_CONFIG_job_chain_flag_END (11)
#define SOC_GPU_JS0_CONFIG_end_flush_START (12)
#define SOC_GPU_JS0_CONFIG_end_flush_END (13)
#define SOC_GPU_JS0_CONFIG_enable_flush_reduction_START (14)
#define SOC_GPU_JS0_CONFIG_enable_flush_reduction_END (14)
#define SOC_GPU_JS0_CONFIG_disable_descriptor_START (15)
#define SOC_GPU_JS0_CONFIG_disable_descriptor_END (15)
#define SOC_GPU_JS0_CONFIG_thread_priority_START (16)
#define SOC_GPU_JS0_CONFIG_thread_priority_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int xaffinity_enable : 1;
        unsigned int reserved_0 : 7;
        unsigned int tiler_enable : 1;
        unsigned int reserved_1 : 7;
        unsigned int cache_enable : 1;
        unsigned int reserved_2 : 15;
    } reg;
} SOC_GPU_JS0_XAFFINITY_UNION;
#endif
#define SOC_GPU_JS0_XAFFINITY_xaffinity_enable_START (0)
#define SOC_GPU_JS0_XAFFINITY_xaffinity_enable_END (0)
#define SOC_GPU_JS0_XAFFINITY_tiler_enable_START (8)
#define SOC_GPU_JS0_XAFFINITY_tiler_enable_END (8)
#define SOC_GPU_JS0_XAFFINITY_cache_enable_START (16)
#define SOC_GPU_JS0_XAFFINITY_cache_enable_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int js0_command : 32;
    } reg;
} SOC_GPU_JS0_COMMAND_UNION;
#endif
#define SOC_GPU_JS0_COMMAND_js0_command_START (0)
#define SOC_GPU_JS0_COMMAND_js0_command_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int exception_type : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_GPU_JS0_STATUS_UNION;
#endif
#define SOC_GPU_JS0_STATUS_exception_type_START (0)
#define SOC_GPU_JS0_STATUS_exception_type_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int flush_id : 32;
    } reg;
} SOC_GPU_JS0_FLUSH_ID_UNION;
#endif
#define SOC_GPU_JS0_FLUSH_ID_flush_id_START (0)
#define SOC_GPU_JS0_FLUSH_ID_flush_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int js0_event_0 : 32;
    } reg;
} SOC_GPU_JS0_EVENT_0_UNION;
#endif
#define SOC_GPU_JS0_EVENT_0_js0_event_0_START (0)
#define SOC_GPU_JS0_EVENT_0_js0_event_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int js0_event_1 : 32;
    } reg;
} SOC_GPU_JS0_EVENT_1_UNION;
#endif
#define SOC_GPU_JS0_EVENT_1_js0_event_1_START (0)
#define SOC_GPU_JS0_EVENT_1_js0_event_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int js0_event_mask : 32;
    } reg;
} SOC_GPU_JS0_EVENT_MASK_UNION;
#endif
#define SOC_GPU_JS0_EVENT_MASK_js0_event_mask_START (0)
#define SOC_GPU_JS0_EVENT_MASK_js0_event_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int js0_head_next_lo : 32;
    } reg;
} SOC_GPU_JS0_HEAD_NEXT_LO_UNION;
#endif
#define SOC_GPU_JS0_HEAD_NEXT_LO_js0_head_next_lo_START (0)
#define SOC_GPU_JS0_HEAD_NEXT_LO_js0_head_next_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int js0_head_next_hi : 32;
    } reg;
} SOC_GPU_JS0_HEAD_NEXT_HI_UNION;
#endif
#define SOC_GPU_JS0_HEAD_NEXT_HI_js0_head_next_hi_START (0)
#define SOC_GPU_JS0_HEAD_NEXT_HI_js0_head_next_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int js0_affinity_next_lO : 32;
    } reg;
} SOC_GPU_JS0_AFFINITY_NEXT_LO_UNION;
#endif
#define SOC_GPU_JS0_AFFINITY_NEXT_LO_js0_affinity_next_lO_START (0)
#define SOC_GPU_JS0_AFFINITY_NEXT_LO_js0_affinity_next_lO_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int js0_affinity_next_hi : 32;
    } reg;
} SOC_GPU_JS0_AFFINITY_NEXT_HI_UNION;
#endif
#define SOC_GPU_JS0_AFFINITY_NEXT_HI_js0_affinity_next_hi_START (0)
#define SOC_GPU_JS0_AFFINITY_NEXT_HI_js0_affinity_next_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int js0_config_next : 32;
    } reg;
} SOC_GPU_JS0_CONFIG_NEXT_UNION;
#endif
#define SOC_GPU_JS0_CONFIG_NEXT_js0_config_next_START (0)
#define SOC_GPU_JS0_CONFIG_NEXT_js0_config_next_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int js0_xaffinity_next : 32;
    } reg;
} SOC_GPU_JS0_XAFFINITY_NEXT_UNION;
#endif
#define SOC_GPU_JS0_XAFFINITY_NEXT_js0_xaffinity_next_START (0)
#define SOC_GPU_JS0_XAFFINITY_NEXT_js0_xaffinity_next_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int js0_command_next : 32;
    } reg;
} SOC_GPU_JS0_COMMAND_NEXT_UNION;
#endif
#define SOC_GPU_JS0_COMMAND_NEXT_js0_command_next_START (0)
#define SOC_GPU_JS0_COMMAND_NEXT_js0_command_next_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int page_fault : 8;
        unsigned int reserved_0 : 8;
        unsigned int bus_error : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_GPU_MMU_IRQ_RAWSTAT_UNION;
#endif
#define SOC_GPU_MMU_IRQ_RAWSTAT_page_fault_START (0)
#define SOC_GPU_MMU_IRQ_RAWSTAT_page_fault_END (7)
#define SOC_GPU_MMU_IRQ_RAWSTAT_bus_error_START (16)
#define SOC_GPU_MMU_IRQ_RAWSTAT_bus_error_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int page_fault : 8;
        unsigned int reserved_0 : 8;
        unsigned int bus_error : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_GPU_MMU_IRQ_CLEAR_UNION;
#endif
#define SOC_GPU_MMU_IRQ_CLEAR_page_fault_START (0)
#define SOC_GPU_MMU_IRQ_CLEAR_page_fault_END (7)
#define SOC_GPU_MMU_IRQ_CLEAR_bus_error_START (16)
#define SOC_GPU_MMU_IRQ_CLEAR_bus_error_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int page_fault : 8;
        unsigned int reserved : 8;
        unsigned int bus_error : 8;
        unsigned int interruptmaskregister : 8;
    } reg;
} SOC_GPU_MMU_IRQ_MASK_UNION;
#endif
#define SOC_GPU_MMU_IRQ_MASK_page_fault_START (0)
#define SOC_GPU_MMU_IRQ_MASK_page_fault_END (7)
#define SOC_GPU_MMU_IRQ_MASK_bus_error_START (16)
#define SOC_GPU_MMU_IRQ_MASK_bus_error_END (23)
#define SOC_GPU_MMU_IRQ_MASK_interruptmaskregister_START (24)
#define SOC_GPU_MMU_IRQ_MASK_interruptmaskregister_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int page_fault : 8;
        unsigned int reserved : 8;
        unsigned int bus_error : 8;
        unsigned int mmu_irq_status : 8;
    } reg;
} SOC_GPU_MMU_IRQ_STATUS_UNION;
#endif
#define SOC_GPU_MMU_IRQ_STATUS_page_fault_START (0)
#define SOC_GPU_MMU_IRQ_STATUS_page_fault_END (7)
#define SOC_GPU_MMU_IRQ_STATUS_bus_error_START (16)
#define SOC_GPU_MMU_IRQ_STATUS_bus_error_END (23)
#define SOC_GPU_MMU_IRQ_STATUS_mmu_irq_status_START (24)
#define SOC_GPU_MMU_IRQ_STATUS_mmu_irq_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int transtab_adrmode : 2;
        unsigned int transtab_read_inner : 1;
        unsigned int reserved_0 : 1;
        unsigned int share_out : 1;
        unsigned int reserved_1 : 7;
        unsigned int as0_transtab_lo : 20;
    } reg;
} SOC_GPU_AS0_TRANSTAB_LO_UNION;
#endif
#define SOC_GPU_AS0_TRANSTAB_LO_transtab_adrmode_START (0)
#define SOC_GPU_AS0_TRANSTAB_LO_transtab_adrmode_END (1)
#define SOC_GPU_AS0_TRANSTAB_LO_transtab_read_inner_START (2)
#define SOC_GPU_AS0_TRANSTAB_LO_transtab_read_inner_END (2)
#define SOC_GPU_AS0_TRANSTAB_LO_share_out_START (4)
#define SOC_GPU_AS0_TRANSTAB_LO_share_out_END (4)
#define SOC_GPU_AS0_TRANSTAB_LO_as0_transtab_lo_START (12)
#define SOC_GPU_AS0_TRANSTAB_LO_as0_transtab_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int as0_transtab_hi : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_GPU_AS0_TRANSTAB_HI_UNION;
#endif
#define SOC_GPU_AS0_TRANSTAB_HI_as0_transtab_hi_START (0)
#define SOC_GPU_AS0_TRANSTAB_HI_as0_transtab_hi_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int as0_memattr_l3 : 8;
        unsigned int as0_memattr_l2 : 8;
        unsigned int as0_memattr_l1 : 8;
        unsigned int as0_memattr_l0 : 8;
    } reg;
} SOC_GPU_AS0_MEMATTR_LO_UNION;
#endif
#define SOC_GPU_AS0_MEMATTR_LO_as0_memattr_l3_START (0)
#define SOC_GPU_AS0_MEMATTR_LO_as0_memattr_l3_END (7)
#define SOC_GPU_AS0_MEMATTR_LO_as0_memattr_l2_START (8)
#define SOC_GPU_AS0_MEMATTR_LO_as0_memattr_l2_END (15)
#define SOC_GPU_AS0_MEMATTR_LO_as0_memattr_l1_START (16)
#define SOC_GPU_AS0_MEMATTR_LO_as0_memattr_l1_END (23)
#define SOC_GPU_AS0_MEMATTR_LO_as0_memattr_l0_START (24)
#define SOC_GPU_AS0_MEMATTR_LO_as0_memattr_l0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int as0_memattr_h3 : 8;
        unsigned int as0_memattr_h2 : 8;
        unsigned int as0_memattr_h1 : 8;
        unsigned int as0_memattr_h0 : 8;
    } reg;
} SOC_GPU_AS0_MEMATTR_HI_UNION;
#endif
#define SOC_GPU_AS0_MEMATTR_HI_as0_memattr_h3_START (0)
#define SOC_GPU_AS0_MEMATTR_HI_as0_memattr_h3_END (7)
#define SOC_GPU_AS0_MEMATTR_HI_as0_memattr_h2_START (8)
#define SOC_GPU_AS0_MEMATTR_HI_as0_memattr_h2_END (15)
#define SOC_GPU_AS0_MEMATTR_HI_as0_memattr_h1_START (16)
#define SOC_GPU_AS0_MEMATTR_HI_as0_memattr_h1_END (23)
#define SOC_GPU_AS0_MEMATTR_HI_as0_memattr_h0_START (24)
#define SOC_GPU_AS0_MEMATTR_HI_as0_memattr_h0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lockaddr_size : 6;
        unsigned int reserved : 6;
        unsigned int as0_lockaddr_l0 : 20;
    } reg;
} SOC_GPU_AS0_LOCKADDR_LO_UNION;
#endif
#define SOC_GPU_AS0_LOCKADDR_LO_lockaddr_size_START (0)
#define SOC_GPU_AS0_LOCKADDR_LO_lockaddr_size_END (5)
#define SOC_GPU_AS0_LOCKADDR_LO_as0_lockaddr_l0_START (12)
#define SOC_GPU_AS0_LOCKADDR_LO_as0_lockaddr_l0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int as0_lockaddr_hi : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_GPU_AS0_LOCKADDR_HI_UNION;
#endif
#define SOC_GPU_AS0_LOCKADDR_HI_as0_lockaddr_hi_START (0)
#define SOC_GPU_AS0_LOCKADDR_HI_as0_lockaddr_hi_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_GPU_AS0_COMMAND_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int exception_type : 8;
        unsigned int access_type : 2;
        unsigned int reserved : 6;
        unsigned int source_id : 16;
    } reg;
} SOC_GPU_AS0_FAULTSTATUS_UNION;
#endif
#define SOC_GPU_AS0_FAULTSTATUS_exception_type_START (0)
#define SOC_GPU_AS0_FAULTSTATUS_exception_type_END (7)
#define SOC_GPU_AS0_FAULTSTATUS_access_type_START (8)
#define SOC_GPU_AS0_FAULTSTATUS_access_type_END (9)
#define SOC_GPU_AS0_FAULTSTATUS_source_id_START (16)
#define SOC_GPU_AS0_FAULTSTATUS_source_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int as0_faultaddress_lo : 32;
    } reg;
} SOC_GPU_AS0_FAULTADDRESS_LO_UNION;
#endif
#define SOC_GPU_AS0_FAULTADDRESS_LO_as0_faultaddress_lo_START (0)
#define SOC_GPU_AS0_FAULTADDRESS_LO_as0_faultaddress_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int as0_faultaddress_hi : 32;
    } reg;
} SOC_GPU_AS0_FAULTADDRESS_HI_UNION;
#endif
#define SOC_GPU_AS0_FAULTADDRESS_HI_as0_faultaddress_hi_START (0)
#define SOC_GPU_AS0_FAULTADDRESS_HI_as0_faultaddress_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mmu_flush_active : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_GPU_AS0_STATUS_UNION;
#endif
#define SOC_GPU_AS0_STATUS_mmu_flush_active_START (0)
#define SOC_GPU_AS0_STATUS_mmu_flush_active_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int MODE : 4;
        unsigned int reserved_0 : 2;
        unsigned int INA_BITS : 5;
        unsigned int reserved_1 : 3;
        unsigned int OUTA_BITS : 5;
        unsigned int reserved_2 : 3;
        unsigned int SL_CONCAT_EN : 1;
        unsigned int reserved_3 : 1;
        unsigned int PTW_MEMATTR : 2;
        unsigned int reserved_4 : 2;
        unsigned int PTW_SH : 2;
        unsigned int R_ALLOCATE : 1;
        unsigned int reserved_5 : 1;
    } reg;
} SOC_GPU_AS0_TRANSCFG_LO_UNION;
#endif
#define SOC_GPU_AS0_TRANSCFG_LO_MODE_START (0)
#define SOC_GPU_AS0_TRANSCFG_LO_MODE_END (3)
#define SOC_GPU_AS0_TRANSCFG_LO_INA_BITS_START (6)
#define SOC_GPU_AS0_TRANSCFG_LO_INA_BITS_END (10)
#define SOC_GPU_AS0_TRANSCFG_LO_OUTA_BITS_START (14)
#define SOC_GPU_AS0_TRANSCFG_LO_OUTA_BITS_END (18)
#define SOC_GPU_AS0_TRANSCFG_LO_SL_CONCAT_EN_START (22)
#define SOC_GPU_AS0_TRANSCFG_LO_SL_CONCAT_EN_END (22)
#define SOC_GPU_AS0_TRANSCFG_LO_PTW_MEMATTR_START (24)
#define SOC_GPU_AS0_TRANSCFG_LO_PTW_MEMATTR_END (25)
#define SOC_GPU_AS0_TRANSCFG_LO_PTW_SH_START (28)
#define SOC_GPU_AS0_TRANSCFG_LO_PTW_SH_END (29)
#define SOC_GPU_AS0_TRANSCFG_LO_R_ALLOCATE_START (30)
#define SOC_GPU_AS0_TRANSCFG_LO_R_ALLOCATE_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int DISABLE_HIER_AP : 1;
        unsigned int DISABLE_AF_FAULT : 1;
        unsigned int WXN : 1;
        unsigned int XREADABLE : 1;
        unsigned int reserved_1 : 27;
    } reg;
} SOC_GPU_AS0_TRANSCFG_HI_UNION;
#endif
#define SOC_GPU_AS0_TRANSCFG_HI_DISABLE_HIER_AP_START (1)
#define SOC_GPU_AS0_TRANSCFG_HI_DISABLE_HIER_AP_END (1)
#define SOC_GPU_AS0_TRANSCFG_HI_DISABLE_AF_FAULT_START (2)
#define SOC_GPU_AS0_TRANSCFG_HI_DISABLE_AF_FAULT_END (2)
#define SOC_GPU_AS0_TRANSCFG_HI_WXN_START (3)
#define SOC_GPU_AS0_TRANSCFG_HI_WXN_END (3)
#define SOC_GPU_AS0_TRANSCFG_HI_XREADABLE_START (4)
#define SOC_GPU_AS0_TRANSCFG_HI_XREADABLE_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int FAULT_ADDRESS : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_GPU_AS0_FAULTEXTRA_LO_UNION;
#endif
#define SOC_GPU_AS0_FAULTEXTRA_LO_FAULT_ADDRESS_START (0)
#define SOC_GPU_AS0_FAULTEXTRA_LO_FAULT_ADDRESS_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_GPU_AS0_FAULTEXTRA_HI_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int transtab_adrmode : 2;
        unsigned int transtab_read_inner : 1;
        unsigned int reserved_0 : 1;
        unsigned int share_out : 1;
        unsigned int reserved_1 : 7;
        unsigned int as1_transtab_lo : 20;
    } reg;
} SOC_GPU_AS1_TRANSTAB_LO_UNION;
#endif
#define SOC_GPU_AS1_TRANSTAB_LO_transtab_adrmode_START (0)
#define SOC_GPU_AS1_TRANSTAB_LO_transtab_adrmode_END (1)
#define SOC_GPU_AS1_TRANSTAB_LO_transtab_read_inner_START (2)
#define SOC_GPU_AS1_TRANSTAB_LO_transtab_read_inner_END (2)
#define SOC_GPU_AS1_TRANSTAB_LO_share_out_START (4)
#define SOC_GPU_AS1_TRANSTAB_LO_share_out_END (4)
#define SOC_GPU_AS1_TRANSTAB_LO_as1_transtab_lo_START (12)
#define SOC_GPU_AS1_TRANSTAB_LO_as1_transtab_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int as1_transtab_hi : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_GPU_AS1_TRANSTAB_HI_UNION;
#endif
#define SOC_GPU_AS1_TRANSTAB_HI_as1_transtab_hi_START (0)
#define SOC_GPU_AS1_TRANSTAB_HI_as1_transtab_hi_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int as1_memattr_l3 : 8;
        unsigned int as1_memattr_l2 : 8;
        unsigned int as1_memattr_l1 : 8;
        unsigned int as1_memattr_l0 : 8;
    } reg;
} SOC_GPU_AS1_MEMATTR_LO_UNION;
#endif
#define SOC_GPU_AS1_MEMATTR_LO_as1_memattr_l3_START (0)
#define SOC_GPU_AS1_MEMATTR_LO_as1_memattr_l3_END (7)
#define SOC_GPU_AS1_MEMATTR_LO_as1_memattr_l2_START (8)
#define SOC_GPU_AS1_MEMATTR_LO_as1_memattr_l2_END (15)
#define SOC_GPU_AS1_MEMATTR_LO_as1_memattr_l1_START (16)
#define SOC_GPU_AS1_MEMATTR_LO_as1_memattr_l1_END (23)
#define SOC_GPU_AS1_MEMATTR_LO_as1_memattr_l0_START (24)
#define SOC_GPU_AS1_MEMATTR_LO_as1_memattr_l0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int as1_memattr_h3 : 8;
        unsigned int as1_memattr_h2 : 8;
        unsigned int as1_memattr_h1 : 8;
        unsigned int as1_memattr_h0 : 8;
    } reg;
} SOC_GPU_AS1_MEMATTR_HI_UNION;
#endif
#define SOC_GPU_AS1_MEMATTR_HI_as1_memattr_h3_START (0)
#define SOC_GPU_AS1_MEMATTR_HI_as1_memattr_h3_END (7)
#define SOC_GPU_AS1_MEMATTR_HI_as1_memattr_h2_START (8)
#define SOC_GPU_AS1_MEMATTR_HI_as1_memattr_h2_END (15)
#define SOC_GPU_AS1_MEMATTR_HI_as1_memattr_h1_START (16)
#define SOC_GPU_AS1_MEMATTR_HI_as1_memattr_h1_END (23)
#define SOC_GPU_AS1_MEMATTR_HI_as1_memattr_h0_START (24)
#define SOC_GPU_AS1_MEMATTR_HI_as1_memattr_h0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lockaddr_size : 6;
        unsigned int reserved : 6;
        unsigned int as1_lockaddr_l0 : 20;
    } reg;
} SOC_GPU_AS1_LOCKADDR_LO_UNION;
#endif
#define SOC_GPU_AS1_LOCKADDR_LO_lockaddr_size_START (0)
#define SOC_GPU_AS1_LOCKADDR_LO_lockaddr_size_END (5)
#define SOC_GPU_AS1_LOCKADDR_LO_as1_lockaddr_l0_START (12)
#define SOC_GPU_AS1_LOCKADDR_LO_as1_lockaddr_l0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int as1_lockaddr_hi : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_GPU_AS1_LOCKADDR_HI_UNION;
#endif
#define SOC_GPU_AS1_LOCKADDR_HI_as1_lockaddr_hi_START (0)
#define SOC_GPU_AS1_LOCKADDR_HI_as1_lockaddr_hi_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nop : 1;
        unsigned int update : 1;
        unsigned int lock : 1;
        unsigned int unlock : 1;
        unsigned int flush_pt : 1;
        unsigned int flush_mem : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_GPU_AS1_COMMAND_UNION;
#endif
#define SOC_GPU_AS1_COMMAND_nop_START (0)
#define SOC_GPU_AS1_COMMAND_nop_END (0)
#define SOC_GPU_AS1_COMMAND_update_START (1)
#define SOC_GPU_AS1_COMMAND_update_END (1)
#define SOC_GPU_AS1_COMMAND_lock_START (2)
#define SOC_GPU_AS1_COMMAND_lock_END (2)
#define SOC_GPU_AS1_COMMAND_unlock_START (3)
#define SOC_GPU_AS1_COMMAND_unlock_END (3)
#define SOC_GPU_AS1_COMMAND_flush_pt_START (4)
#define SOC_GPU_AS1_COMMAND_flush_pt_END (4)
#define SOC_GPU_AS1_COMMAND_flush_mem_START (5)
#define SOC_GPU_AS1_COMMAND_flush_mem_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int exception_type : 8;
        unsigned int access_type : 2;
        unsigned int reserved : 6;
        unsigned int source_id : 16;
    } reg;
} SOC_GPU_AS1_FAULTSTATUS_UNION;
#endif
#define SOC_GPU_AS1_FAULTSTATUS_exception_type_START (0)
#define SOC_GPU_AS1_FAULTSTATUS_exception_type_END (7)
#define SOC_GPU_AS1_FAULTSTATUS_access_type_START (8)
#define SOC_GPU_AS1_FAULTSTATUS_access_type_END (9)
#define SOC_GPU_AS1_FAULTSTATUS_source_id_START (16)
#define SOC_GPU_AS1_FAULTSTATUS_source_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int as1_faultaddress_lo : 32;
    } reg;
} SOC_GPU_AS1_FAULTADDRESS_LO_UNION;
#endif
#define SOC_GPU_AS1_FAULTADDRESS_LO_as1_faultaddress_lo_START (0)
#define SOC_GPU_AS1_FAULTADDRESS_LO_as1_faultaddress_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int as0_faultaddress_hi : 32;
    } reg;
} SOC_GPU_AS1_FAULTADDRESS_HI_UNION;
#endif
#define SOC_GPU_AS1_FAULTADDRESS_HI_as0_faultaddress_hi_START (0)
#define SOC_GPU_AS1_FAULTADDRESS_HI_as0_faultaddress_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mmu_flush_active : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_GPU_AS1_STATUS_UNION;
#endif
#define SOC_GPU_AS1_STATUS_mmu_flush_active_START (0)
#define SOC_GPU_AS1_STATUS_mmu_flush_active_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int MODE : 4;
        unsigned int reserved_0 : 2;
        unsigned int INA_BITS : 5;
        unsigned int reserved_1 : 3;
        unsigned int OUTA_BITS : 5;
        unsigned int reserved_2 : 3;
        unsigned int SL_CONCAT_EN : 1;
        unsigned int reserved_3 : 1;
        unsigned int PTW_MEMATTR : 2;
        unsigned int reserved_4 : 2;
        unsigned int PTW_SH : 2;
        unsigned int R_ALLOCATE : 1;
        unsigned int reserved_5 : 1;
    } reg;
} SOC_GPU_AS1_TRANSCFG_LO_UNION;
#endif
#define SOC_GPU_AS1_TRANSCFG_LO_MODE_START (0)
#define SOC_GPU_AS1_TRANSCFG_LO_MODE_END (3)
#define SOC_GPU_AS1_TRANSCFG_LO_INA_BITS_START (6)
#define SOC_GPU_AS1_TRANSCFG_LO_INA_BITS_END (10)
#define SOC_GPU_AS1_TRANSCFG_LO_OUTA_BITS_START (14)
#define SOC_GPU_AS1_TRANSCFG_LO_OUTA_BITS_END (18)
#define SOC_GPU_AS1_TRANSCFG_LO_SL_CONCAT_EN_START (22)
#define SOC_GPU_AS1_TRANSCFG_LO_SL_CONCAT_EN_END (22)
#define SOC_GPU_AS1_TRANSCFG_LO_PTW_MEMATTR_START (24)
#define SOC_GPU_AS1_TRANSCFG_LO_PTW_MEMATTR_END (25)
#define SOC_GPU_AS1_TRANSCFG_LO_PTW_SH_START (28)
#define SOC_GPU_AS1_TRANSCFG_LO_PTW_SH_END (29)
#define SOC_GPU_AS1_TRANSCFG_LO_R_ALLOCATE_START (30)
#define SOC_GPU_AS1_TRANSCFG_LO_R_ALLOCATE_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int DISABLE_HIER_AP : 1;
        unsigned int DISABLE_AF_FAULT : 1;
        unsigned int WXN : 1;
        unsigned int XREADABLE : 1;
        unsigned int reserved_1 : 27;
    } reg;
} SOC_GPU_AS1_TRANSCFG_HI_UNION;
#endif
#define SOC_GPU_AS1_TRANSCFG_HI_DISABLE_HIER_AP_START (1)
#define SOC_GPU_AS1_TRANSCFG_HI_DISABLE_HIER_AP_END (1)
#define SOC_GPU_AS1_TRANSCFG_HI_DISABLE_AF_FAULT_START (2)
#define SOC_GPU_AS1_TRANSCFG_HI_DISABLE_AF_FAULT_END (2)
#define SOC_GPU_AS1_TRANSCFG_HI_WXN_START (3)
#define SOC_GPU_AS1_TRANSCFG_HI_WXN_END (3)
#define SOC_GPU_AS1_TRANSCFG_HI_XREADABLE_START (4)
#define SOC_GPU_AS1_TRANSCFG_HI_XREADABLE_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int FAULT_ADDRESS : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_GPU_AS1_FAULTEXTRA_LO_UNION;
#endif
#define SOC_GPU_AS1_FAULTEXTRA_LO_FAULT_ADDRESS_START (0)
#define SOC_GPU_AS1_FAULTEXTRA_LO_FAULT_ADDRESS_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_GPU_AS1_FAULTEXTRA_HI_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int transtab_adrmode : 2;
        unsigned int transtab_read_inner : 1;
        unsigned int reserved_0 : 1;
        unsigned int share_out : 1;
        unsigned int reserved_1 : 7;
        unsigned int as2_transtab_lo : 20;
    } reg;
} SOC_GPU_AS2_TRANSTAB_LO_UNION;
#endif
#define SOC_GPU_AS2_TRANSTAB_LO_transtab_adrmode_START (0)
#define SOC_GPU_AS2_TRANSTAB_LO_transtab_adrmode_END (1)
#define SOC_GPU_AS2_TRANSTAB_LO_transtab_read_inner_START (2)
#define SOC_GPU_AS2_TRANSTAB_LO_transtab_read_inner_END (2)
#define SOC_GPU_AS2_TRANSTAB_LO_share_out_START (4)
#define SOC_GPU_AS2_TRANSTAB_LO_share_out_END (4)
#define SOC_GPU_AS2_TRANSTAB_LO_as2_transtab_lo_START (12)
#define SOC_GPU_AS2_TRANSTAB_LO_as2_transtab_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int as2_transtab_hi : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_GPU_AS2_TRANSTAB_HI_UNION;
#endif
#define SOC_GPU_AS2_TRANSTAB_HI_as2_transtab_hi_START (0)
#define SOC_GPU_AS2_TRANSTAB_HI_as2_transtab_hi_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int as2_memattr_l3 : 8;
        unsigned int as2_memattr_l2 : 8;
        unsigned int as2_memattr_l1 : 8;
        unsigned int as2_memattr_l0 : 8;
    } reg;
} SOC_GPU_AS2_MEMATTR_LO_UNION;
#endif
#define SOC_GPU_AS2_MEMATTR_LO_as2_memattr_l3_START (0)
#define SOC_GPU_AS2_MEMATTR_LO_as2_memattr_l3_END (7)
#define SOC_GPU_AS2_MEMATTR_LO_as2_memattr_l2_START (8)
#define SOC_GPU_AS2_MEMATTR_LO_as2_memattr_l2_END (15)
#define SOC_GPU_AS2_MEMATTR_LO_as2_memattr_l1_START (16)
#define SOC_GPU_AS2_MEMATTR_LO_as2_memattr_l1_END (23)
#define SOC_GPU_AS2_MEMATTR_LO_as2_memattr_l0_START (24)
#define SOC_GPU_AS2_MEMATTR_LO_as2_memattr_l0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int as2_memattr_h3 : 8;
        unsigned int as2_memattr_h2 : 8;
        unsigned int as2_memattr_h1 : 8;
        unsigned int as2_memattr_h0 : 8;
    } reg;
} SOC_GPU_AS2_MEMATTR_HI_UNION;
#endif
#define SOC_GPU_AS2_MEMATTR_HI_as2_memattr_h3_START (0)
#define SOC_GPU_AS2_MEMATTR_HI_as2_memattr_h3_END (7)
#define SOC_GPU_AS2_MEMATTR_HI_as2_memattr_h2_START (8)
#define SOC_GPU_AS2_MEMATTR_HI_as2_memattr_h2_END (15)
#define SOC_GPU_AS2_MEMATTR_HI_as2_memattr_h1_START (16)
#define SOC_GPU_AS2_MEMATTR_HI_as2_memattr_h1_END (23)
#define SOC_GPU_AS2_MEMATTR_HI_as2_memattr_h0_START (24)
#define SOC_GPU_AS2_MEMATTR_HI_as2_memattr_h0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lockaddr_size : 6;
        unsigned int reserved : 6;
        unsigned int as2_lockaddr_l0 : 20;
    } reg;
} SOC_GPU_AS2_LOCKADDR_LO_UNION;
#endif
#define SOC_GPU_AS2_LOCKADDR_LO_lockaddr_size_START (0)
#define SOC_GPU_AS2_LOCKADDR_LO_lockaddr_size_END (5)
#define SOC_GPU_AS2_LOCKADDR_LO_as2_lockaddr_l0_START (12)
#define SOC_GPU_AS2_LOCKADDR_LO_as2_lockaddr_l0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int as2_lockaddr_hi : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_GPU_AS2_LOCKADDR_HI_UNION;
#endif
#define SOC_GPU_AS2_LOCKADDR_HI_as2_lockaddr_hi_START (0)
#define SOC_GPU_AS2_LOCKADDR_HI_as2_lockaddr_hi_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nop : 1;
        unsigned int update : 1;
        unsigned int lock : 1;
        unsigned int unlock : 1;
        unsigned int flush_pt : 1;
        unsigned int flush_mem : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_GPU_AS2_COMMAND_UNION;
#endif
#define SOC_GPU_AS2_COMMAND_nop_START (0)
#define SOC_GPU_AS2_COMMAND_nop_END (0)
#define SOC_GPU_AS2_COMMAND_update_START (1)
#define SOC_GPU_AS2_COMMAND_update_END (1)
#define SOC_GPU_AS2_COMMAND_lock_START (2)
#define SOC_GPU_AS2_COMMAND_lock_END (2)
#define SOC_GPU_AS2_COMMAND_unlock_START (3)
#define SOC_GPU_AS2_COMMAND_unlock_END (3)
#define SOC_GPU_AS2_COMMAND_flush_pt_START (4)
#define SOC_GPU_AS2_COMMAND_flush_pt_END (4)
#define SOC_GPU_AS2_COMMAND_flush_mem_START (5)
#define SOC_GPU_AS2_COMMAND_flush_mem_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int exception_type : 8;
        unsigned int access_type : 2;
        unsigned int reserved : 6;
        unsigned int source_id : 16;
    } reg;
} SOC_GPU_AS2_FAULTSTATUS_UNION;
#endif
#define SOC_GPU_AS2_FAULTSTATUS_exception_type_START (0)
#define SOC_GPU_AS2_FAULTSTATUS_exception_type_END (7)
#define SOC_GPU_AS2_FAULTSTATUS_access_type_START (8)
#define SOC_GPU_AS2_FAULTSTATUS_access_type_END (9)
#define SOC_GPU_AS2_FAULTSTATUS_source_id_START (16)
#define SOC_GPU_AS2_FAULTSTATUS_source_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int as2_faultaddress_lo : 32;
    } reg;
} SOC_GPU_AS2_FAULTADDRESS_LO_UNION;
#endif
#define SOC_GPU_AS2_FAULTADDRESS_LO_as2_faultaddress_lo_START (0)
#define SOC_GPU_AS2_FAULTADDRESS_LO_as2_faultaddress_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int as2_faultaddress_hi : 32;
    } reg;
} SOC_GPU_AS2_FAULTADDRESS_HI_UNION;
#endif
#define SOC_GPU_AS2_FAULTADDRESS_HI_as2_faultaddress_hi_START (0)
#define SOC_GPU_AS2_FAULTADDRESS_HI_as2_faultaddress_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mmu_flush_active : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_GPU_AS2_STATUS_UNION;
#endif
#define SOC_GPU_AS2_STATUS_mmu_flush_active_START (0)
#define SOC_GPU_AS2_STATUS_mmu_flush_active_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int MODE : 4;
        unsigned int reserved_0 : 2;
        unsigned int INA_BITS : 5;
        unsigned int reserved_1 : 3;
        unsigned int OUTA_BITS : 5;
        unsigned int reserved_2 : 3;
        unsigned int SL_CONCAT_EN : 1;
        unsigned int reserved_3 : 1;
        unsigned int PTW_MEMATTR : 2;
        unsigned int reserved_4 : 2;
        unsigned int PTW_SH : 2;
        unsigned int R_ALLOCATE : 1;
        unsigned int reserved_5 : 1;
    } reg;
} SOC_GPU_AS2_TRANSCFG_LO_UNION;
#endif
#define SOC_GPU_AS2_TRANSCFG_LO_MODE_START (0)
#define SOC_GPU_AS2_TRANSCFG_LO_MODE_END (3)
#define SOC_GPU_AS2_TRANSCFG_LO_INA_BITS_START (6)
#define SOC_GPU_AS2_TRANSCFG_LO_INA_BITS_END (10)
#define SOC_GPU_AS2_TRANSCFG_LO_OUTA_BITS_START (14)
#define SOC_GPU_AS2_TRANSCFG_LO_OUTA_BITS_END (18)
#define SOC_GPU_AS2_TRANSCFG_LO_SL_CONCAT_EN_START (22)
#define SOC_GPU_AS2_TRANSCFG_LO_SL_CONCAT_EN_END (22)
#define SOC_GPU_AS2_TRANSCFG_LO_PTW_MEMATTR_START (24)
#define SOC_GPU_AS2_TRANSCFG_LO_PTW_MEMATTR_END (25)
#define SOC_GPU_AS2_TRANSCFG_LO_PTW_SH_START (28)
#define SOC_GPU_AS2_TRANSCFG_LO_PTW_SH_END (29)
#define SOC_GPU_AS2_TRANSCFG_LO_R_ALLOCATE_START (30)
#define SOC_GPU_AS2_TRANSCFG_LO_R_ALLOCATE_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int DISABLE_HIER_AP : 1;
        unsigned int DISABLE_AF_FAULT : 1;
        unsigned int WXN : 1;
        unsigned int XREADABLE : 1;
        unsigned int reserved_1 : 27;
    } reg;
} SOC_GPU_AS2_TRANSCFG_HI_UNION;
#endif
#define SOC_GPU_AS2_TRANSCFG_HI_DISABLE_HIER_AP_START (1)
#define SOC_GPU_AS2_TRANSCFG_HI_DISABLE_HIER_AP_END (1)
#define SOC_GPU_AS2_TRANSCFG_HI_DISABLE_AF_FAULT_START (2)
#define SOC_GPU_AS2_TRANSCFG_HI_DISABLE_AF_FAULT_END (2)
#define SOC_GPU_AS2_TRANSCFG_HI_WXN_START (3)
#define SOC_GPU_AS2_TRANSCFG_HI_WXN_END (3)
#define SOC_GPU_AS2_TRANSCFG_HI_XREADABLE_START (4)
#define SOC_GPU_AS2_TRANSCFG_HI_XREADABLE_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int FAULT_ADDRESS : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_GPU_AS2_FAULTEXTRA_LO_UNION;
#endif
#define SOC_GPU_AS2_FAULTEXTRA_LO_FAULT_ADDRESS_START (0)
#define SOC_GPU_AS2_FAULTEXTRA_LO_FAULT_ADDRESS_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_GPU_AS2_FAULTEXTRA_HI_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int transtab_adrmode : 2;
        unsigned int transtab_read_inner : 1;
        unsigned int reserved_0 : 1;
        unsigned int share_out : 1;
        unsigned int reserved_1 : 7;
        unsigned int as3_transtab_lo : 20;
    } reg;
} SOC_GPU_AS3_TRANSTAB_LO_UNION;
#endif
#define SOC_GPU_AS3_TRANSTAB_LO_transtab_adrmode_START (0)
#define SOC_GPU_AS3_TRANSTAB_LO_transtab_adrmode_END (1)
#define SOC_GPU_AS3_TRANSTAB_LO_transtab_read_inner_START (2)
#define SOC_GPU_AS3_TRANSTAB_LO_transtab_read_inner_END (2)
#define SOC_GPU_AS3_TRANSTAB_LO_share_out_START (4)
#define SOC_GPU_AS3_TRANSTAB_LO_share_out_END (4)
#define SOC_GPU_AS3_TRANSTAB_LO_as3_transtab_lo_START (12)
#define SOC_GPU_AS3_TRANSTAB_LO_as3_transtab_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int as3_transtab_hi : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_GPU_AS3_TRANSTAB_HI_UNION;
#endif
#define SOC_GPU_AS3_TRANSTAB_HI_as3_transtab_hi_START (0)
#define SOC_GPU_AS3_TRANSTAB_HI_as3_transtab_hi_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int as3_memattr_l3 : 8;
        unsigned int as3_memattr_l2 : 8;
        unsigned int as3_memattr_l1 : 8;
        unsigned int as3_memattr_l0 : 8;
    } reg;
} SOC_GPU_AS3_MEMATTR_LO_UNION;
#endif
#define SOC_GPU_AS3_MEMATTR_LO_as3_memattr_l3_START (0)
#define SOC_GPU_AS3_MEMATTR_LO_as3_memattr_l3_END (7)
#define SOC_GPU_AS3_MEMATTR_LO_as3_memattr_l2_START (8)
#define SOC_GPU_AS3_MEMATTR_LO_as3_memattr_l2_END (15)
#define SOC_GPU_AS3_MEMATTR_LO_as3_memattr_l1_START (16)
#define SOC_GPU_AS3_MEMATTR_LO_as3_memattr_l1_END (23)
#define SOC_GPU_AS3_MEMATTR_LO_as3_memattr_l0_START (24)
#define SOC_GPU_AS3_MEMATTR_LO_as3_memattr_l0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int as3_memattr_h3 : 8;
        unsigned int as3_memattr_h2 : 8;
        unsigned int as3_memattr_h1 : 8;
        unsigned int as3_memattr_h0 : 8;
    } reg;
} SOC_GPU_AS3_MEMATTR_HI_UNION;
#endif
#define SOC_GPU_AS3_MEMATTR_HI_as3_memattr_h3_START (0)
#define SOC_GPU_AS3_MEMATTR_HI_as3_memattr_h3_END (7)
#define SOC_GPU_AS3_MEMATTR_HI_as3_memattr_h2_START (8)
#define SOC_GPU_AS3_MEMATTR_HI_as3_memattr_h2_END (15)
#define SOC_GPU_AS3_MEMATTR_HI_as3_memattr_h1_START (16)
#define SOC_GPU_AS3_MEMATTR_HI_as3_memattr_h1_END (23)
#define SOC_GPU_AS3_MEMATTR_HI_as3_memattr_h0_START (24)
#define SOC_GPU_AS3_MEMATTR_HI_as3_memattr_h0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lockaddr_size : 6;
        unsigned int reserved : 6;
        unsigned int as3_lockaddr_l0 : 20;
    } reg;
} SOC_GPU_AS3_LOCKADDR_LO_UNION;
#endif
#define SOC_GPU_AS3_LOCKADDR_LO_lockaddr_size_START (0)
#define SOC_GPU_AS3_LOCKADDR_LO_lockaddr_size_END (5)
#define SOC_GPU_AS3_LOCKADDR_LO_as3_lockaddr_l0_START (12)
#define SOC_GPU_AS3_LOCKADDR_LO_as3_lockaddr_l0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int as3_lockaddr_hi : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_GPU_AS3_LOCKADDR_HI_UNION;
#endif
#define SOC_GPU_AS3_LOCKADDR_HI_as3_lockaddr_hi_START (0)
#define SOC_GPU_AS3_LOCKADDR_HI_as3_lockaddr_hi_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nop : 1;
        unsigned int update : 1;
        unsigned int lock : 1;
        unsigned int unlock : 1;
        unsigned int flush_pt : 1;
        unsigned int flush_mem : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_GPU_AS3_COMMAND_UNION;
#endif
#define SOC_GPU_AS3_COMMAND_nop_START (0)
#define SOC_GPU_AS3_COMMAND_nop_END (0)
#define SOC_GPU_AS3_COMMAND_update_START (1)
#define SOC_GPU_AS3_COMMAND_update_END (1)
#define SOC_GPU_AS3_COMMAND_lock_START (2)
#define SOC_GPU_AS3_COMMAND_lock_END (2)
#define SOC_GPU_AS3_COMMAND_unlock_START (3)
#define SOC_GPU_AS3_COMMAND_unlock_END (3)
#define SOC_GPU_AS3_COMMAND_flush_pt_START (4)
#define SOC_GPU_AS3_COMMAND_flush_pt_END (4)
#define SOC_GPU_AS3_COMMAND_flush_mem_START (5)
#define SOC_GPU_AS3_COMMAND_flush_mem_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int exception_type : 8;
        unsigned int access_type : 2;
        unsigned int reserved : 6;
        unsigned int source_id : 16;
    } reg;
} SOC_GPU_AS3_FAULTSTATUS_UNION;
#endif
#define SOC_GPU_AS3_FAULTSTATUS_exception_type_START (0)
#define SOC_GPU_AS3_FAULTSTATUS_exception_type_END (7)
#define SOC_GPU_AS3_FAULTSTATUS_access_type_START (8)
#define SOC_GPU_AS3_FAULTSTATUS_access_type_END (9)
#define SOC_GPU_AS3_FAULTSTATUS_source_id_START (16)
#define SOC_GPU_AS3_FAULTSTATUS_source_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int as3_faultaddress_lo : 32;
    } reg;
} SOC_GPU_AS3_FAULTADDRESS_LO_UNION;
#endif
#define SOC_GPU_AS3_FAULTADDRESS_LO_as3_faultaddress_lo_START (0)
#define SOC_GPU_AS3_FAULTADDRESS_LO_as3_faultaddress_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int as3_faultaddress_hi : 32;
    } reg;
} SOC_GPU_AS3_FAULTADDRESS_HI_UNION;
#endif
#define SOC_GPU_AS3_FAULTADDRESS_HI_as3_faultaddress_hi_START (0)
#define SOC_GPU_AS3_FAULTADDRESS_HI_as3_faultaddress_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mmu_flush_active : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_GPU_AS3_STATUS_UNION;
#endif
#define SOC_GPU_AS3_STATUS_mmu_flush_active_START (0)
#define SOC_GPU_AS3_STATUS_mmu_flush_active_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int MODE : 4;
        unsigned int reserved_0 : 2;
        unsigned int INA_BITS : 5;
        unsigned int reserved_1 : 3;
        unsigned int OUTA_BITS : 5;
        unsigned int reserved_2 : 3;
        unsigned int SL_CONCAT_EN : 1;
        unsigned int reserved_3 : 1;
        unsigned int PTW_MEMATTR : 2;
        unsigned int reserved_4 : 2;
        unsigned int PTW_SH : 2;
        unsigned int R_ALLOCATE : 1;
        unsigned int reserved_5 : 1;
    } reg;
} SOC_GPU_AS3_TRANSCFG_LO_UNION;
#endif
#define SOC_GPU_AS3_TRANSCFG_LO_MODE_START (0)
#define SOC_GPU_AS3_TRANSCFG_LO_MODE_END (3)
#define SOC_GPU_AS3_TRANSCFG_LO_INA_BITS_START (6)
#define SOC_GPU_AS3_TRANSCFG_LO_INA_BITS_END (10)
#define SOC_GPU_AS3_TRANSCFG_LO_OUTA_BITS_START (14)
#define SOC_GPU_AS3_TRANSCFG_LO_OUTA_BITS_END (18)
#define SOC_GPU_AS3_TRANSCFG_LO_SL_CONCAT_EN_START (22)
#define SOC_GPU_AS3_TRANSCFG_LO_SL_CONCAT_EN_END (22)
#define SOC_GPU_AS3_TRANSCFG_LO_PTW_MEMATTR_START (24)
#define SOC_GPU_AS3_TRANSCFG_LO_PTW_MEMATTR_END (25)
#define SOC_GPU_AS3_TRANSCFG_LO_PTW_SH_START (28)
#define SOC_GPU_AS3_TRANSCFG_LO_PTW_SH_END (29)
#define SOC_GPU_AS3_TRANSCFG_LO_R_ALLOCATE_START (30)
#define SOC_GPU_AS3_TRANSCFG_LO_R_ALLOCATE_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int DISABLE_HIER_AP : 1;
        unsigned int DISABLE_AF_FAULT : 1;
        unsigned int WXN : 1;
        unsigned int XREADABLE : 1;
        unsigned int reserved_1 : 27;
    } reg;
} SOC_GPU_AS3_TRANSCFG_HI_UNION;
#endif
#define SOC_GPU_AS3_TRANSCFG_HI_DISABLE_HIER_AP_START (1)
#define SOC_GPU_AS3_TRANSCFG_HI_DISABLE_HIER_AP_END (1)
#define SOC_GPU_AS3_TRANSCFG_HI_DISABLE_AF_FAULT_START (2)
#define SOC_GPU_AS3_TRANSCFG_HI_DISABLE_AF_FAULT_END (2)
#define SOC_GPU_AS3_TRANSCFG_HI_WXN_START (3)
#define SOC_GPU_AS3_TRANSCFG_HI_WXN_END (3)
#define SOC_GPU_AS3_TRANSCFG_HI_XREADABLE_START (4)
#define SOC_GPU_AS3_TRANSCFG_HI_XREADABLE_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int FAULT_ADDRESS : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_GPU_AS3_FAULTEXTRA_LO_UNION;
#endif
#define SOC_GPU_AS3_FAULTEXTRA_LO_FAULT_ADDRESS_START (0)
#define SOC_GPU_AS3_FAULTEXTRA_LO_FAULT_ADDRESS_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_GPU_AS3_FAULTEXTRA_HI_UNION;
#endif
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
