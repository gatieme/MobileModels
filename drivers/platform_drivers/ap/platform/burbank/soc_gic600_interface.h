#ifndef __SOC_GIC600_INTERFACE_H__
#define __SOC_GIC600_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_GIC600_GICD_CTLR_ADDR(base) ((base) + (0x0000UL))
#define SOC_GIC600_GICD_TYPER_ADDR(base) ((base) + (0x0004UL))
#define SOC_GIC600_GICD_IIDR_ADDR(base) ((base) + (0x0008UL))
#define SOC_GIC600_GICD_SAC_ADDR(base) ((base) + (0x0024UL))
#define SOC_GIC600_GICD_SETSPI_NSR_ADDR(base) ((base) + (0x0040UL))
#define SOC_GIC600_GICD_CLRSPI_NSR_ADDR(base) ((base) + (0x0048UL))
#define SOC_GIC600_GICD_SETSPI_SR_ADDR(base) ((base) + (0x0050UL))
#define SOC_GIC600_GICD_CLRSPI_SR_ADDR(base) ((base) + (0x0058UL))
#define SOC_GIC600_GICD_IGROUPRn_ADDR(base,N) ((base) + (0x0080+(4*(N))))
#define SOC_GIC600_GICD_ISENABLERn_ADDR(base,N) ((base) + (0x0100+(4*(N))))
#define SOC_GIC600_GICD_ICENABLERn_ADDR(base,N) ((base) + (0x0180+(4*(N))))
#define SOC_GIC600_GICD_ISPENDRn_ADDR(base,N) ((base) + (0x0200+(4*(N))))
#define SOC_GIC600_GICD_ICPENDRn_ADDR(base,N) ((base) + (0x0280+(4*(N))))
#define SOC_GIC600_GICD_ISACTIVERn_ADDR(base,N) ((base) + (0x0300+(4*(N))))
#define SOC_GIC600_GICD_ICACTIVERn_ADDR(base,N) ((base) + (0x0380+(4*(N))))
#define SOC_GIC600_GICD_IPRIORITYRn_ADDR(base,N) ((base) + (0x0400+(4*(N))))
#define SOC_GIC600_GICD_ITARGETSRn_ADDR(base,N) ((base) + (0x0800+(4*(N))))
#define SOC_GIC600_GICD_ICFGRn_ADDR(base,N) ((base) + (0x0C00+(4*(N))))
#define SOC_GIC600_GICD_IGRPMODRn_ADDR(base,N) ((base) + (0x0D00+(4*(N))))
#define SOC_GIC600_GICD_NSACRn_ADDR(base,N) ((base) + (0x0E00+(4*(N))))
#define SOC_GIC600_GICD_SGIR_ADDR(base) ((base) + (0x0F00UL))
#define SOC_GIC600_GICD_CPENDSGIN_ADDR(base,N) ((base) + (0x0F10+(4*(N))))
#define SOC_GIC600_GICD_SPENDSGIRN_ADDR(base,N) ((base) + (0x0F20+(4*(N))))
#define SOC_GIC600_GICD_IROUTERN_ADDR(base,N) ((base) + (0x6000+(8*(N))))
#define SOC_GIC600_GICD_CHIPSR_ADDR(base) ((base) + (0xC000UL))
#define SOC_GIC600_GICD_DCHIPR_ADDR(base) ((base) + (0xC004UL))
#define SOC_GIC600_GICD_CHIPR0_ADDR(base) ((base) + (0xC008UL))
#define SOC_GIC600_GICD_CHIPR1_ADDR(base) ((base) + (0xC010UL))
#define SOC_GIC600_GICD_IERRR_ADDR(base,N) ((base) + (0xE100+(4*(N))))
#define SOC_GIC600_GICR0_CTLR_ADDR(base) ((base) + (0x00040000UL))
#define SOC_GIC600_GICR0_IIDR_ADDR(base) ((base) + (0x00040004UL))
#define SOC_GIC600_GICR0_WAKER_ADDR(base) ((base) + (0x00040014UL))
#define SOC_GIC600_GICR0_PWRR_ADDR(base) ((base) + (0x00040024UL))
#define SOC_GIC600_GICR0_IGROUPR0_ADDR(base) ((base) + (0x00050080UL))
#define SOC_GIC600_GICR0_ISENABLER0_ADDR(base) ((base) + (0x00050100UL))
#define SOC_GIC600_GICR0_ICENABLER0_ADDR(base) ((base) + (0x00050180UL))
#define SOC_GIC600_GICR_ISPENDR0_ADDR(base) ((base) + (0x00050200UL))
#define SOC_GIC600_GICR_ICPENDR0_ADDR(base) ((base) + (0x00050280UL))
#define SOC_GIC600_GICR0_ISACTIVER0_ADDR(base) ((base) + (0x00050300UL))
#define SOC_GIC600_GICR0_ICACTIVER0_ADDR(base) ((base) + (0x00050380UL))
#define SOC_GIC600_GICR0_IPRIORITYRn_ADDR(base) ((base) + (0x00050400UL))
#define SOC_GIC600_GICR0_ICFGR0_ADDR(base) ((base) + (0x00050C00UL))
#define SOC_GIC600_GICR0_ICFGR1_ADDR(base) ((base) + (0x00050C04UL))
#define SOC_GIC600_GICR0_IGRPMODR0_ADDR(base) ((base) + (0x00050D00UL))
#define SOC_GIC600_GICR0_NSACR_ADDR(base) ((base) + (0x00050E00UL))
#define SOC_GIC600_GICR0_MISCSTATUSR_ADDR(base) ((base) + (0x0005C000UL))
#define SOC_GIC600_GICR1_CTLR_ADDR(base) ((base) + (0x00060000UL))
#define SOC_GIC600_GICR1_IIDR_ADDR(base) ((base) + (0x00060004UL))
#define SOC_GIC600_GICR1_WAKER_ADDR(base) ((base) + (0x00060014UL))
#define SOC_GIC600_GICR1_PWRR_ADDR(base) ((base) + (0x00060024UL))
#define SOC_GIC600_GICR1_IGROUPR0_ADDR(base) ((base) + (0x00070080UL))
#define SOC_GIC600_GICR1_ISENABLER0_ADDR(base) ((base) + (0x00070100UL))
#define SOC_GIC600_GICR1_ICENABLER0_ADDR(base) ((base) + (0x00070180UL))
#define SOC_GIC600_GICR1_ISPENDR0_ADDR(base) ((base) + (0x00070200UL))
#define SOC_GIC600_GICR1_ICPENDR0_ADDR(base) ((base) + (0x00070280UL))
#define SOC_GIC600_GICR1_ISACTIVER0_ADDR(base) ((base) + (0x00070300UL))
#define SOC_GIC600_GICR1_ICACTIVER0_ADDR(base) ((base) + (0x00070380UL))
#define SOC_GIC600_GICR1_IPRIORITYRn_ADDR(base) ((base) + (0x00070400UL))
#define SOC_GIC600_GICR1_ICFGR0_ADDR(base) ((base) + (0x00070C00UL))
#define SOC_GIC600_GICR1_ICFGR1_ADDR(base) ((base) + (0x00070C04UL))
#define SOC_GIC600_GICR1_IGRPMODR0_ADDR(base) ((base) + (0x00070D00UL))
#define SOC_GIC600_GICR1_NSACR_ADDR(base) ((base) + (0x00070E00UL))
#define SOC_GIC600_GICR1_MISCSTATUSR_ADDR(base) ((base) + (0x0007C000UL))
#define SOC_GIC600_GICR2_CTLR_ADDR(base) ((base) + (0x00080000UL))
#define SOC_GIC600_GICR2_IIDR_ADDR(base) ((base) + (0x00080004UL))
#define SOC_GIC600_GICR2_WAKER_ADDR(base) ((base) + (0x00080014UL))
#define SOC_GIC600_GICR2_PWRR_ADDR(base) ((base) + (0x00080024UL))
#define SOC_GIC600_GICR2_IGROUPR0_ADDR(base) ((base) + (0x00090080UL))
#define SOC_GIC600_GICR2_ISENABLER0_ADDR(base) ((base) + (0x00090100UL))
#define SOC_GIC600_GICR2_ICENABLER0_ADDR(base) ((base) + (0x00090180UL))
#define SOC_GIC600_GICR2_ISPENDR0_ADDR(base) ((base) + (0x00090200UL))
#define SOC_GIC600_GICR2_ICPENDR0_ADDR(base) ((base) + (0x00090280UL))
#define SOC_GIC600_GICR_ISACTIVER0_ADDR(base) ((base) + (0x00090300UL))
#define SOC_GIC600_GICR2_ICACTIVER0_ADDR(base) ((base) + (0x00090380UL))
#define SOC_GIC600_GICR2_IPRIORITYRn_ADDR(base) ((base) + (0x00090400UL))
#define SOC_GIC600_GICR2_ICFGR0_ADDR(base) ((base) + (0x00090C00UL))
#define SOC_GIC600_GICR2_ICFGR1_ADDR(base) ((base) + (0x00090C04UL))
#define SOC_GIC600_GICR2_IGRPMODR0_ADDR(base) ((base) + (0x00090D00UL))
#define SOC_GIC600_GICR2_NSACR_ADDR(base) ((base) + (0x00090E00UL))
#define SOC_GIC600_GICR2_MISCSTATUSR_ADDR(base) ((base) + (0x0009C000UL))
#define SOC_GIC600_GICR3_CTLR_ADDR(base) ((base) + (0x000A0000UL))
#define SOC_GIC600_GICR3_IIDR_ADDR(base) ((base) + (0x000A0004UL))
#define SOC_GIC600_GICR3_WAKER_ADDR(base) ((base) + (0x000A0014UL))
#define SOC_GIC600_GICR3_PWRR_ADDR(base) ((base) + (0x000A0024UL))
#define SOC_GIC600_GICR3_IGROUPR0_ADDR(base) ((base) + (0x000B0080UL))
#define SOC_GIC600_GICR3_ISENABLER0_ADDR(base) ((base) + (0x000B0100UL))
#define SOC_GIC600_GICR3_ICENABLER0_ADDR(base) ((base) + (0x000B0180UL))
#define SOC_GIC600_GICR3_ISPENDR0_ADDR(base) ((base) + (0x000B0200UL))
#define SOC_GIC600_GICR3_ICPENDR0_ADDR(base) ((base) + (0x000B0280UL))
#define SOC_GIC600_GICR3_ISACTIVER0_ADDR(base) ((base) + (0x000B0300UL))
#define SOC_GIC600_GICR3_ICACTIVER0_ADDR(base) ((base) + (0x000B0380UL))
#define SOC_GIC600_GICR3_IPRIORITYRn_ADDR(base) ((base) + (0x000B0400UL))
#define SOC_GIC600_GICR3_ICFGR0_ADDR(base) ((base) + (0x000B0C00UL))
#define SOC_GIC600_GICR3_ICFGR1_ADDR(base) ((base) + (0x000B0C04UL))
#define SOC_GIC600_GICR3_IGRPMODR0_ADDR(base) ((base) + (0x000B0D00UL))
#define SOC_GIC600_GICR3_NSACR_ADDR(base) ((base) + (0x000B0E00UL))
#define SOC_GIC600_GICR3_MISCSTATUSR_ADDR(base) ((base) + (0x000BC000UL))
#define SOC_GIC600_GICR4_CTLR_ADDR(base) ((base) + (0x000C0000UL))
#define SOC_GIC600_GICR4_IIDR_ADDR(base) ((base) + (0x000C0004UL))
#define SOC_GIC600_GICR4_WAKER_ADDR(base) ((base) + (0x000C0014UL))
#define SOC_GIC600_GICR4_PWRR_ADDR(base) ((base) + (0x000C0024UL))
#define SOC_GIC600_GICR4_IGROUPR0_ADDR(base) ((base) + (0x000D0080UL))
#define SOC_GIC600_GICR4_ISENABLER0_ADDR(base) ((base) + (0x000D0100UL))
#define SOC_GIC600_GICR4_ICENABLER0_ADDR(base) ((base) + (0x000D0180UL))
#define SOC_GIC600_GICR4_ISPENDR0_ADDR(base) ((base) + (0x000D0200UL))
#define SOC_GIC600_GICR4_ICPENDR0_ADDR(base) ((base) + (0x000D0280UL))
#define SOC_GIC600_GICR4_ISACTIVER0_ADDR(base) ((base) + (0x000D0300UL))
#define SOC_GIC600_GICR4_ICACTIVER0_ADDR(base) ((base) + (0x000D0380UL))
#define SOC_GIC600_GICR4_IPRIORITYRn_ADDR(base) ((base) + (0x000D0400UL))
#define SOC_GIC600_GICR4_ICFGR0_ADDR(base) ((base) + (0x000D0C00UL))
#define SOC_GIC600_GICR4_ICFGR1_ADDR(base) ((base) + (0x000D0C04UL))
#define SOC_GIC600_GICR4_IGRPMODR0_ADDR(base) ((base) + (0x000D0D00UL))
#define SOC_GIC600_GICR4_NSACR_ADDR(base) ((base) + (0x000D0E00UL))
#define SOC_GIC600_GICR4_MISCSTATUSR_ADDR(base) ((base) + (0x000DC000UL))
#define SOC_GIC600_GICR5_CTLR_ADDR(base) ((base) + (0x000E0000UL))
#define SOC_GIC600_GICR5_IIDR_ADDR(base) ((base) + (0x000E0004UL))
#define SOC_GIC600_GICR5_WAKER_ADDR(base) ((base) + (0x000E0014UL))
#define SOC_GIC600_GICR5_PWRR_ADDR(base) ((base) + (0x000E0024UL))
#define SOC_GIC600_GICR5_IGROUPR0_ADDR(base) ((base) + (0x000F0080UL))
#define SOC_GIC600_GICR5_ISENABLER0_ADDR(base) ((base) + (0x000F0100UL))
#define SOC_GIC600_GICR5_ICENABLER0_ADDR(base) ((base) + (0x000F0180UL))
#define SOC_GIC600_GICR5_ISPENDR0_ADDR(base) ((base) + (0x000F0200UL))
#define SOC_GIC600_GICR5_ICPENDR0_ADDR(base) ((base) + (0x000F0280UL))
#define SOC_GIC600_GICR5_ISACTIVER0_ADDR(base) ((base) + (0x000F0300UL))
#define SOC_GIC600_GICR5_ICACTIVER0_ADDR(base) ((base) + (0x000F0380UL))
#define SOC_GIC600_GICR5_IPRIORITYRn_ADDR(base) ((base) + (0x000F0400UL))
#define SOC_GIC600_GICR5_ICFGR0_ADDR(base) ((base) + (0x000F0C00UL))
#define SOC_GIC600_GICR5_ICFGR1_ADDR(base) ((base) + (0x000F0C04UL))
#define SOC_GIC600_GICR5_IGRPMODR0_ADDR(base) ((base) + (0x000F0D00UL))
#define SOC_GIC600_GICR5_NSACR_ADDR(base) ((base) + (0x000F0E00UL))
#define SOC_GIC600_GICR5_MISCSTATUSR_ADDR(base) ((base) + (0x000FC000UL))
#define SOC_GIC600_GICR6_CTLR_ADDR(base) ((base) + (0x00100000UL))
#define SOC_GIC600_GICR6_IIDR_ADDR(base) ((base) + (0x00100004UL))
#define SOC_GIC600_GICR6_WAKER_ADDR(base) ((base) + (0x00100014UL))
#define SOC_GIC600_GICR6_PWRR_ADDR(base) ((base) + (0x00100024UL))
#define SOC_GIC600_GICR6_IGROUPR0_ADDR(base) ((base) + (0x00110080UL))
#define SOC_GIC600_GICR6_ISENABLER0_ADDR(base) ((base) + (0x00110100UL))
#define SOC_GIC600_GICR6_ICENABLER0_ADDR(base) ((base) + (0x00110180UL))
#define SOC_GIC600_GICR6_ISPENDR0_ADDR(base) ((base) + (0x00110200UL))
#define SOC_GIC600_GICR6_ICPENDR0_ADDR(base) ((base) + (0x00110280UL))
#define SOC_GIC600_GICR6_ISACTIVER0_ADDR(base) ((base) + (0x00110300UL))
#define SOC_GIC600_GICR6_ICACTIVER0_ADDR(base) ((base) + (0x00110380UL))
#define SOC_GIC600_GICR6_IPRIORITYRn_ADDR(base) ((base) + (0x00110400UL))
#define SOC_GIC600_GICR6_ICFGR0_ADDR(base) ((base) + (0x00110C00UL))
#define SOC_GIC600_GICR6_ICFGR1_ADDR(base) ((base) + (0x00110C04UL))
#define SOC_GIC600_GICR6_IGRPMODR0_ADDR(base) ((base) + (0x00110D00UL))
#define SOC_GIC600_GICR6_NSACR_ADDR(base) ((base) + (0x00110E00UL))
#define SOC_GIC600_GICR6_MISCSTATUSR_ADDR(base) ((base) + (0x0011C000UL))
#define SOC_GIC600_GICR7_CTLR_ADDR(base) ((base) + (0x00120000UL))
#define SOC_GIC600_GICR7_IIDR_ADDR(base) ((base) + (0x00120004UL))
#define SOC_GIC600_GICR7_WAKER_ADDR(base) ((base) + (0x00120014UL))
#define SOC_GIC600_GICR7_PWRR_ADDR(base) ((base) + (0x00120024UL))
#define SOC_GIC600_GICR7_IGROUPR0_ADDR(base) ((base) + (0x00130080UL))
#define SOC_GIC600_GICR7_ISENABLER0_ADDR(base) ((base) + (0x00130100UL))
#define SOC_GIC600_GICR7_ICENABLER0_ADDR(base) ((base) + (0x00130180UL))
#define SOC_GIC600_GICR7_ISPENDR0_ADDR(base) ((base) + (0x00130200UL))
#define SOC_GIC600_GICR7_ICPENDR0_ADDR(base) ((base) + (0x00130280UL))
#define SOC_GIC600_GICR7_ISACTIVER0_ADDR(base) ((base) + (0x00130300UL))
#define SOC_GIC600_GICR7_ICACTIVER0_ADDR(base) ((base) + (0x00130380UL))
#define SOC_GIC600_GICR7_IPRIORITYRn_ADDR(base) ((base) + (0x00130400UL))
#define SOC_GIC600_GICR7_ICFGR0_ADDR(base) ((base) + (0x00130C00UL))
#define SOC_GIC600_GICR7_ICFGR1_ADDR(base) ((base) + (0x00130C04UL))
#define SOC_GIC600_GICR7_IGRPMODR0_ADDR(base) ((base) + (0x00130D00UL))
#define SOC_GIC600_GICR7_NSACR_ADDR(base) ((base) + (0x00130E00UL))
#define SOC_GIC600_GICR7_MISCSTATUSR_ADDR(base) ((base) + (0x0013C000UL))
#else
#define SOC_GIC600_GICD_CTLR_ADDR(base) ((base) + (0x0000))
#define SOC_GIC600_GICD_TYPER_ADDR(base) ((base) + (0x0004))
#define SOC_GIC600_GICD_IIDR_ADDR(base) ((base) + (0x0008))
#define SOC_GIC600_GICD_SAC_ADDR(base) ((base) + (0x0024))
#define SOC_GIC600_GICD_SETSPI_NSR_ADDR(base) ((base) + (0x0040))
#define SOC_GIC600_GICD_CLRSPI_NSR_ADDR(base) ((base) + (0x0048))
#define SOC_GIC600_GICD_SETSPI_SR_ADDR(base) ((base) + (0x0050))
#define SOC_GIC600_GICD_CLRSPI_SR_ADDR(base) ((base) + (0x0058))
#define SOC_GIC600_GICD_IGROUPRn_ADDR(base,N) ((base) + (0x0080+(4*(N))))
#define SOC_GIC600_GICD_ISENABLERn_ADDR(base,N) ((base) + (0x0100+(4*(N))))
#define SOC_GIC600_GICD_ICENABLERn_ADDR(base,N) ((base) + (0x0180+(4*(N))))
#define SOC_GIC600_GICD_ISPENDRn_ADDR(base,N) ((base) + (0x0200+(4*(N))))
#define SOC_GIC600_GICD_ICPENDRn_ADDR(base,N) ((base) + (0x0280+(4*(N))))
#define SOC_GIC600_GICD_ISACTIVERn_ADDR(base,N) ((base) + (0x0300+(4*(N))))
#define SOC_GIC600_GICD_ICACTIVERn_ADDR(base,N) ((base) + (0x0380+(4*(N))))
#define SOC_GIC600_GICD_IPRIORITYRn_ADDR(base,N) ((base) + (0x0400+(4*(N))))
#define SOC_GIC600_GICD_ITARGETSRn_ADDR(base,N) ((base) + (0x0800+(4*(N))))
#define SOC_GIC600_GICD_ICFGRn_ADDR(base,N) ((base) + (0x0C00+(4*(N))))
#define SOC_GIC600_GICD_IGRPMODRn_ADDR(base,N) ((base) + (0x0D00+(4*(N))))
#define SOC_GIC600_GICD_NSACRn_ADDR(base,N) ((base) + (0x0E00+(4*(N))))
#define SOC_GIC600_GICD_SGIR_ADDR(base) ((base) + (0x0F00))
#define SOC_GIC600_GICD_CPENDSGIN_ADDR(base,N) ((base) + (0x0F10+(4*(N))))
#define SOC_GIC600_GICD_SPENDSGIRN_ADDR(base,N) ((base) + (0x0F20+(4*(N))))
#define SOC_GIC600_GICD_IROUTERN_ADDR(base,N) ((base) + (0x6000+(8*(N))))
#define SOC_GIC600_GICD_CHIPSR_ADDR(base) ((base) + (0xC000))
#define SOC_GIC600_GICD_DCHIPR_ADDR(base) ((base) + (0xC004))
#define SOC_GIC600_GICD_CHIPR0_ADDR(base) ((base) + (0xC008))
#define SOC_GIC600_GICD_CHIPR1_ADDR(base) ((base) + (0xC010))
#define SOC_GIC600_GICD_IERRR_ADDR(base,N) ((base) + (0xE100+(4*(N))))
#define SOC_GIC600_GICR0_CTLR_ADDR(base) ((base) + (0x00040000))
#define SOC_GIC600_GICR0_IIDR_ADDR(base) ((base) + (0x00040004))
#define SOC_GIC600_GICR0_WAKER_ADDR(base) ((base) + (0x00040014))
#define SOC_GIC600_GICR0_PWRR_ADDR(base) ((base) + (0x00040024))
#define SOC_GIC600_GICR0_IGROUPR0_ADDR(base) ((base) + (0x00050080))
#define SOC_GIC600_GICR0_ISENABLER0_ADDR(base) ((base) + (0x00050100))
#define SOC_GIC600_GICR0_ICENABLER0_ADDR(base) ((base) + (0x00050180))
#define SOC_GIC600_GICR_ISPENDR0_ADDR(base) ((base) + (0x00050200))
#define SOC_GIC600_GICR_ICPENDR0_ADDR(base) ((base) + (0x00050280))
#define SOC_GIC600_GICR0_ISACTIVER0_ADDR(base) ((base) + (0x00050300))
#define SOC_GIC600_GICR0_ICACTIVER0_ADDR(base) ((base) + (0x00050380))
#define SOC_GIC600_GICR0_IPRIORITYRn_ADDR(base) ((base) + (0x00050400))
#define SOC_GIC600_GICR0_ICFGR0_ADDR(base) ((base) + (0x00050C00))
#define SOC_GIC600_GICR0_ICFGR1_ADDR(base) ((base) + (0x00050C04))
#define SOC_GIC600_GICR0_IGRPMODR0_ADDR(base) ((base) + (0x00050D00))
#define SOC_GIC600_GICR0_NSACR_ADDR(base) ((base) + (0x00050E00))
#define SOC_GIC600_GICR0_MISCSTATUSR_ADDR(base) ((base) + (0x0005C000))
#define SOC_GIC600_GICR1_CTLR_ADDR(base) ((base) + (0x00060000))
#define SOC_GIC600_GICR1_IIDR_ADDR(base) ((base) + (0x00060004))
#define SOC_GIC600_GICR1_WAKER_ADDR(base) ((base) + (0x00060014))
#define SOC_GIC600_GICR1_PWRR_ADDR(base) ((base) + (0x00060024))
#define SOC_GIC600_GICR1_IGROUPR0_ADDR(base) ((base) + (0x00070080))
#define SOC_GIC600_GICR1_ISENABLER0_ADDR(base) ((base) + (0x00070100))
#define SOC_GIC600_GICR1_ICENABLER0_ADDR(base) ((base) + (0x00070180))
#define SOC_GIC600_GICR1_ISPENDR0_ADDR(base) ((base) + (0x00070200))
#define SOC_GIC600_GICR1_ICPENDR0_ADDR(base) ((base) + (0x00070280))
#define SOC_GIC600_GICR1_ISACTIVER0_ADDR(base) ((base) + (0x00070300))
#define SOC_GIC600_GICR1_ICACTIVER0_ADDR(base) ((base) + (0x00070380))
#define SOC_GIC600_GICR1_IPRIORITYRn_ADDR(base) ((base) + (0x00070400))
#define SOC_GIC600_GICR1_ICFGR0_ADDR(base) ((base) + (0x00070C00))
#define SOC_GIC600_GICR1_ICFGR1_ADDR(base) ((base) + (0x00070C04))
#define SOC_GIC600_GICR1_IGRPMODR0_ADDR(base) ((base) + (0x00070D00))
#define SOC_GIC600_GICR1_NSACR_ADDR(base) ((base) + (0x00070E00))
#define SOC_GIC600_GICR1_MISCSTATUSR_ADDR(base) ((base) + (0x0007C000))
#define SOC_GIC600_GICR2_CTLR_ADDR(base) ((base) + (0x00080000))
#define SOC_GIC600_GICR2_IIDR_ADDR(base) ((base) + (0x00080004))
#define SOC_GIC600_GICR2_WAKER_ADDR(base) ((base) + (0x00080014))
#define SOC_GIC600_GICR2_PWRR_ADDR(base) ((base) + (0x00080024))
#define SOC_GIC600_GICR2_IGROUPR0_ADDR(base) ((base) + (0x00090080))
#define SOC_GIC600_GICR2_ISENABLER0_ADDR(base) ((base) + (0x00090100))
#define SOC_GIC600_GICR2_ICENABLER0_ADDR(base) ((base) + (0x00090180))
#define SOC_GIC600_GICR2_ISPENDR0_ADDR(base) ((base) + (0x00090200))
#define SOC_GIC600_GICR2_ICPENDR0_ADDR(base) ((base) + (0x00090280))
#define SOC_GIC600_GICR_ISACTIVER0_ADDR(base) ((base) + (0x00090300))
#define SOC_GIC600_GICR2_ICACTIVER0_ADDR(base) ((base) + (0x00090380))
#define SOC_GIC600_GICR2_IPRIORITYRn_ADDR(base) ((base) + (0x00090400))
#define SOC_GIC600_GICR2_ICFGR0_ADDR(base) ((base) + (0x00090C00))
#define SOC_GIC600_GICR2_ICFGR1_ADDR(base) ((base) + (0x00090C04))
#define SOC_GIC600_GICR2_IGRPMODR0_ADDR(base) ((base) + (0x00090D00))
#define SOC_GIC600_GICR2_NSACR_ADDR(base) ((base) + (0x00090E00))
#define SOC_GIC600_GICR2_MISCSTATUSR_ADDR(base) ((base) + (0x0009C000))
#define SOC_GIC600_GICR3_CTLR_ADDR(base) ((base) + (0x000A0000))
#define SOC_GIC600_GICR3_IIDR_ADDR(base) ((base) + (0x000A0004))
#define SOC_GIC600_GICR3_WAKER_ADDR(base) ((base) + (0x000A0014))
#define SOC_GIC600_GICR3_PWRR_ADDR(base) ((base) + (0x000A0024))
#define SOC_GIC600_GICR3_IGROUPR0_ADDR(base) ((base) + (0x000B0080))
#define SOC_GIC600_GICR3_ISENABLER0_ADDR(base) ((base) + (0x000B0100))
#define SOC_GIC600_GICR3_ICENABLER0_ADDR(base) ((base) + (0x000B0180))
#define SOC_GIC600_GICR3_ISPENDR0_ADDR(base) ((base) + (0x000B0200))
#define SOC_GIC600_GICR3_ICPENDR0_ADDR(base) ((base) + (0x000B0280))
#define SOC_GIC600_GICR3_ISACTIVER0_ADDR(base) ((base) + (0x000B0300))
#define SOC_GIC600_GICR3_ICACTIVER0_ADDR(base) ((base) + (0x000B0380))
#define SOC_GIC600_GICR3_IPRIORITYRn_ADDR(base) ((base) + (0x000B0400))
#define SOC_GIC600_GICR3_ICFGR0_ADDR(base) ((base) + (0x000B0C00))
#define SOC_GIC600_GICR3_ICFGR1_ADDR(base) ((base) + (0x000B0C04))
#define SOC_GIC600_GICR3_IGRPMODR0_ADDR(base) ((base) + (0x000B0D00))
#define SOC_GIC600_GICR3_NSACR_ADDR(base) ((base) + (0x000B0E00))
#define SOC_GIC600_GICR3_MISCSTATUSR_ADDR(base) ((base) + (0x000BC000))
#define SOC_GIC600_GICR4_CTLR_ADDR(base) ((base) + (0x000C0000))
#define SOC_GIC600_GICR4_IIDR_ADDR(base) ((base) + (0x000C0004))
#define SOC_GIC600_GICR4_WAKER_ADDR(base) ((base) + (0x000C0014))
#define SOC_GIC600_GICR4_PWRR_ADDR(base) ((base) + (0x000C0024))
#define SOC_GIC600_GICR4_IGROUPR0_ADDR(base) ((base) + (0x000D0080))
#define SOC_GIC600_GICR4_ISENABLER0_ADDR(base) ((base) + (0x000D0100))
#define SOC_GIC600_GICR4_ICENABLER0_ADDR(base) ((base) + (0x000D0180))
#define SOC_GIC600_GICR4_ISPENDR0_ADDR(base) ((base) + (0x000D0200))
#define SOC_GIC600_GICR4_ICPENDR0_ADDR(base) ((base) + (0x000D0280))
#define SOC_GIC600_GICR4_ISACTIVER0_ADDR(base) ((base) + (0x000D0300))
#define SOC_GIC600_GICR4_ICACTIVER0_ADDR(base) ((base) + (0x000D0380))
#define SOC_GIC600_GICR4_IPRIORITYRn_ADDR(base) ((base) + (0x000D0400))
#define SOC_GIC600_GICR4_ICFGR0_ADDR(base) ((base) + (0x000D0C00))
#define SOC_GIC600_GICR4_ICFGR1_ADDR(base) ((base) + (0x000D0C04))
#define SOC_GIC600_GICR4_IGRPMODR0_ADDR(base) ((base) + (0x000D0D00))
#define SOC_GIC600_GICR4_NSACR_ADDR(base) ((base) + (0x000D0E00))
#define SOC_GIC600_GICR4_MISCSTATUSR_ADDR(base) ((base) + (0x000DC000))
#define SOC_GIC600_GICR5_CTLR_ADDR(base) ((base) + (0x000E0000))
#define SOC_GIC600_GICR5_IIDR_ADDR(base) ((base) + (0x000E0004))
#define SOC_GIC600_GICR5_WAKER_ADDR(base) ((base) + (0x000E0014))
#define SOC_GIC600_GICR5_PWRR_ADDR(base) ((base) + (0x000E0024))
#define SOC_GIC600_GICR5_IGROUPR0_ADDR(base) ((base) + (0x000F0080))
#define SOC_GIC600_GICR5_ISENABLER0_ADDR(base) ((base) + (0x000F0100))
#define SOC_GIC600_GICR5_ICENABLER0_ADDR(base) ((base) + (0x000F0180))
#define SOC_GIC600_GICR5_ISPENDR0_ADDR(base) ((base) + (0x000F0200))
#define SOC_GIC600_GICR5_ICPENDR0_ADDR(base) ((base) + (0x000F0280))
#define SOC_GIC600_GICR5_ISACTIVER0_ADDR(base) ((base) + (0x000F0300))
#define SOC_GIC600_GICR5_ICACTIVER0_ADDR(base) ((base) + (0x000F0380))
#define SOC_GIC600_GICR5_IPRIORITYRn_ADDR(base) ((base) + (0x000F0400))
#define SOC_GIC600_GICR5_ICFGR0_ADDR(base) ((base) + (0x000F0C00))
#define SOC_GIC600_GICR5_ICFGR1_ADDR(base) ((base) + (0x000F0C04))
#define SOC_GIC600_GICR5_IGRPMODR0_ADDR(base) ((base) + (0x000F0D00))
#define SOC_GIC600_GICR5_NSACR_ADDR(base) ((base) + (0x000F0E00))
#define SOC_GIC600_GICR5_MISCSTATUSR_ADDR(base) ((base) + (0x000FC000))
#define SOC_GIC600_GICR6_CTLR_ADDR(base) ((base) + (0x00100000))
#define SOC_GIC600_GICR6_IIDR_ADDR(base) ((base) + (0x00100004))
#define SOC_GIC600_GICR6_WAKER_ADDR(base) ((base) + (0x00100014))
#define SOC_GIC600_GICR6_PWRR_ADDR(base) ((base) + (0x00100024))
#define SOC_GIC600_GICR6_IGROUPR0_ADDR(base) ((base) + (0x00110080))
#define SOC_GIC600_GICR6_ISENABLER0_ADDR(base) ((base) + (0x00110100))
#define SOC_GIC600_GICR6_ICENABLER0_ADDR(base) ((base) + (0x00110180))
#define SOC_GIC600_GICR6_ISPENDR0_ADDR(base) ((base) + (0x00110200))
#define SOC_GIC600_GICR6_ICPENDR0_ADDR(base) ((base) + (0x00110280))
#define SOC_GIC600_GICR6_ISACTIVER0_ADDR(base) ((base) + (0x00110300))
#define SOC_GIC600_GICR6_ICACTIVER0_ADDR(base) ((base) + (0x00110380))
#define SOC_GIC600_GICR6_IPRIORITYRn_ADDR(base) ((base) + (0x00110400))
#define SOC_GIC600_GICR6_ICFGR0_ADDR(base) ((base) + (0x00110C00))
#define SOC_GIC600_GICR6_ICFGR1_ADDR(base) ((base) + (0x00110C04))
#define SOC_GIC600_GICR6_IGRPMODR0_ADDR(base) ((base) + (0x00110D00))
#define SOC_GIC600_GICR6_NSACR_ADDR(base) ((base) + (0x00110E00))
#define SOC_GIC600_GICR6_MISCSTATUSR_ADDR(base) ((base) + (0x0011C000))
#define SOC_GIC600_GICR7_CTLR_ADDR(base) ((base) + (0x00120000))
#define SOC_GIC600_GICR7_IIDR_ADDR(base) ((base) + (0x00120004))
#define SOC_GIC600_GICR7_WAKER_ADDR(base) ((base) + (0x00120014))
#define SOC_GIC600_GICR7_PWRR_ADDR(base) ((base) + (0x00120024))
#define SOC_GIC600_GICR7_IGROUPR0_ADDR(base) ((base) + (0x00130080))
#define SOC_GIC600_GICR7_ISENABLER0_ADDR(base) ((base) + (0x00130100))
#define SOC_GIC600_GICR7_ICENABLER0_ADDR(base) ((base) + (0x00130180))
#define SOC_GIC600_GICR7_ISPENDR0_ADDR(base) ((base) + (0x00130200))
#define SOC_GIC600_GICR7_ICPENDR0_ADDR(base) ((base) + (0x00130280))
#define SOC_GIC600_GICR7_ISACTIVER0_ADDR(base) ((base) + (0x00130300))
#define SOC_GIC600_GICR7_ICACTIVER0_ADDR(base) ((base) + (0x00130380))
#define SOC_GIC600_GICR7_IPRIORITYRn_ADDR(base) ((base) + (0x00130400))
#define SOC_GIC600_GICR7_ICFGR0_ADDR(base) ((base) + (0x00130C00))
#define SOC_GIC600_GICR7_ICFGR1_ADDR(base) ((base) + (0x00130C04))
#define SOC_GIC600_GICR7_IGRPMODR0_ADDR(base) ((base) + (0x00130D00))
#define SOC_GIC600_GICR7_NSACR_ADDR(base) ((base) + (0x00130E00))
#define SOC_GIC600_GICR7_MISCSTATUSR_ADDR(base) ((base) + (0x0013C000))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int EnableGrp0 : 1;
        unsigned int EnableGrp1NS : 1;
        unsigned int EnableGrp1S : 1;
        unsigned int reserved_0 : 1;
        unsigned int ARE_S : 1;
        unsigned int ARE_NS : 1;
        unsigned int DS : 1;
        unsigned int E1NWF : 1;
        unsigned int reserved_1 : 23;
        unsigned int RWP : 1;
    } reg;
} SOC_GIC600_GICD_CTLR_UNION;
#endif
#define SOC_GIC600_GICD_CTLR_EnableGrp0_START (0)
#define SOC_GIC600_GICD_CTLR_EnableGrp0_END (0)
#define SOC_GIC600_GICD_CTLR_EnableGrp1NS_START (1)
#define SOC_GIC600_GICD_CTLR_EnableGrp1NS_END (1)
#define SOC_GIC600_GICD_CTLR_EnableGrp1S_START (2)
#define SOC_GIC600_GICD_CTLR_EnableGrp1S_END (2)
#define SOC_GIC600_GICD_CTLR_ARE_S_START (4)
#define SOC_GIC600_GICD_CTLR_ARE_S_END (4)
#define SOC_GIC600_GICD_CTLR_ARE_NS_START (5)
#define SOC_GIC600_GICD_CTLR_ARE_NS_END (5)
#define SOC_GIC600_GICD_CTLR_DS_START (6)
#define SOC_GIC600_GICD_CTLR_DS_END (6)
#define SOC_GIC600_GICD_CTLR_E1NWF_START (7)
#define SOC_GIC600_GICD_CTLR_E1NWF_END (7)
#define SOC_GIC600_GICD_CTLR_RWP_START (31)
#define SOC_GIC600_GICD_CTLR_RWP_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ITLinesNumber : 5;
        unsigned int CPUNumber : 3;
        unsigned int reserved_0 : 2;
        unsigned int SecurityExtn : 1;
        unsigned int reserved_1 : 5;
        unsigned int MBIS : 1;
        unsigned int LPIS : 1;
        unsigned int DVIS : 1;
        unsigned int Idbits : 5;
        unsigned int A3V : 1;
        unsigned int No1N : 1;
        unsigned int reserved_2 : 6;
    } reg;
} SOC_GIC600_GICD_TYPER_UNION;
#endif
#define SOC_GIC600_GICD_TYPER_ITLinesNumber_START (0)
#define SOC_GIC600_GICD_TYPER_ITLinesNumber_END (4)
#define SOC_GIC600_GICD_TYPER_CPUNumber_START (5)
#define SOC_GIC600_GICD_TYPER_CPUNumber_END (7)
#define SOC_GIC600_GICD_TYPER_SecurityExtn_START (10)
#define SOC_GIC600_GICD_TYPER_SecurityExtn_END (10)
#define SOC_GIC600_GICD_TYPER_MBIS_START (16)
#define SOC_GIC600_GICD_TYPER_MBIS_END (16)
#define SOC_GIC600_GICD_TYPER_LPIS_START (17)
#define SOC_GIC600_GICD_TYPER_LPIS_END (17)
#define SOC_GIC600_GICD_TYPER_DVIS_START (18)
#define SOC_GIC600_GICD_TYPER_DVIS_END (18)
#define SOC_GIC600_GICD_TYPER_Idbits_START (19)
#define SOC_GIC600_GICD_TYPER_Idbits_END (23)
#define SOC_GIC600_GICD_TYPER_A3V_START (24)
#define SOC_GIC600_GICD_TYPER_A3V_END (24)
#define SOC_GIC600_GICD_TYPER_No1N_START (25)
#define SOC_GIC600_GICD_TYPER_No1N_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Implementer : 12;
        unsigned int Revision : 4;
        unsigned int Variant : 4;
        unsigned int reserved : 4;
        unsigned int ProductID : 8;
    } reg;
} SOC_GIC600_GICD_IIDR_UNION;
#endif
#define SOC_GIC600_GICD_IIDR_Implementer_START (0)
#define SOC_GIC600_GICD_IIDR_Implementer_END (11)
#define SOC_GIC600_GICD_IIDR_Revision_START (12)
#define SOC_GIC600_GICD_IIDR_Revision_END (15)
#define SOC_GIC600_GICD_IIDR_Variant_START (16)
#define SOC_GIC600_GICD_IIDR_Variant_END (19)
#define SOC_GIC600_GICD_IIDR_ProductID_START (24)
#define SOC_GIC600_GICD_IIDR_ProductID_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DSL : 1;
        unsigned int GICTNS : 1;
        unsigned int GICPNS : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_GIC600_GICD_SAC_UNION;
#endif
#define SOC_GIC600_GICD_SAC_DSL_START (0)
#define SOC_GIC600_GICD_SAC_DSL_END (0)
#define SOC_GIC600_GICD_SAC_GICTNS_START (1)
#define SOC_GIC600_GICD_SAC_GICTNS_END (1)
#define SOC_GIC600_GICD_SAC_GICPNS_START (2)
#define SOC_GIC600_GICD_SAC_GICPNS_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int INTID : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_GIC600_GICD_SETSPI_NSR_UNION;
#endif
#define SOC_GIC600_GICD_SETSPI_NSR_INTID_START (0)
#define SOC_GIC600_GICD_SETSPI_NSR_INTID_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int INTID : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_GIC600_GICD_CLRSPI_NSR_UNION;
#endif
#define SOC_GIC600_GICD_CLRSPI_NSR_INTID_START (0)
#define SOC_GIC600_GICD_CLRSPI_NSR_INTID_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int INTID : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_GIC600_GICD_SETSPI_SR_UNION;
#endif
#define SOC_GIC600_GICD_SETSPI_SR_INTID_START (0)
#define SOC_GIC600_GICD_SETSPI_SR_INTID_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int INTID : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_GIC600_GICD_CLRSPI_SR_UNION;
#endif
#define SOC_GIC600_GICD_CLRSPI_SR_INTID_START (0)
#define SOC_GIC600_GICD_CLRSPI_SR_INTID_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int groupstatus : 32;
    } reg;
} SOC_GIC600_GICD_IGROUPRn_UNION;
#endif
#define SOC_GIC600_GICD_IGROUPRn_groupstatus_START (0)
#define SOC_GIC600_GICD_IGROUPRn_groupstatus_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int setenable : 32;
    } reg;
} SOC_GIC600_GICD_ISENABLERn_UNION;
#endif
#define SOC_GIC600_GICD_ISENABLERn_setenable_START (0)
#define SOC_GIC600_GICD_ISENABLERn_setenable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clrenable : 32;
    } reg;
} SOC_GIC600_GICD_ICENABLERn_UNION;
#endif
#define SOC_GIC600_GICD_ICENABLERn_clrenable_START (0)
#define SOC_GIC600_GICD_ICENABLERn_clrenable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SetPending : 32;
    } reg;
} SOC_GIC600_GICD_ISPENDRn_UNION;
#endif
#define SOC_GIC600_GICD_ISPENDRn_SetPending_START (0)
#define SOC_GIC600_GICD_ISPENDRn_SetPending_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ClearPending : 32;
    } reg;
} SOC_GIC600_GICD_ICPENDRn_UNION;
#endif
#define SOC_GIC600_GICD_ICPENDRn_ClearPending_START (0)
#define SOC_GIC600_GICD_ICPENDRn_ClearPending_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SetActive : 32;
    } reg;
} SOC_GIC600_GICD_ISACTIVERn_UNION;
#endif
#define SOC_GIC600_GICD_ISACTIVERn_SetActive_START (0)
#define SOC_GIC600_GICD_ISACTIVERn_SetActive_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ClearActive : 32;
    } reg;
} SOC_GIC600_GICD_ICACTIVERn_UNION;
#endif
#define SOC_GIC600_GICD_ICACTIVERn_ClearActive_START (0)
#define SOC_GIC600_GICD_ICACTIVERn_ClearActive_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Priority_offset_0B : 8;
        unsigned int Priority_offset_1B : 8;
        unsigned int Priority_offset_2B : 8;
        unsigned int Priority_offset_3B : 8;
    } reg;
} SOC_GIC600_GICD_IPRIORITYRn_UNION;
#endif
#define SOC_GIC600_GICD_IPRIORITYRn_Priority_offset_0B_START (0)
#define SOC_GIC600_GICD_IPRIORITYRn_Priority_offset_0B_END (7)
#define SOC_GIC600_GICD_IPRIORITYRn_Priority_offset_1B_START (8)
#define SOC_GIC600_GICD_IPRIORITYRn_Priority_offset_1B_END (15)
#define SOC_GIC600_GICD_IPRIORITYRn_Priority_offset_2B_START (16)
#define SOC_GIC600_GICD_IPRIORITYRn_Priority_offset_2B_END (23)
#define SOC_GIC600_GICD_IPRIORITYRn_Priority_offset_3B_START (24)
#define SOC_GIC600_GICD_IPRIORITYRn_Priority_offset_3B_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int CPUtargets_offset_0B : 8;
        unsigned int CPUtargets_offset_1B : 8;
        unsigned int CPUtargets_offset_2B : 8;
        unsigned int CPUtargets_offset_3B : 8;
    } reg;
} SOC_GIC600_GICD_ITARGETSRn_UNION;
#endif
#define SOC_GIC600_GICD_ITARGETSRn_CPUtargets_offset_0B_START (0)
#define SOC_GIC600_GICD_ITARGETSRn_CPUtargets_offset_0B_END (7)
#define SOC_GIC600_GICD_ITARGETSRn_CPUtargets_offset_1B_START (8)
#define SOC_GIC600_GICD_ITARGETSRn_CPUtargets_offset_1B_END (15)
#define SOC_GIC600_GICD_ITARGETSRn_CPUtargets_offset_2B_START (16)
#define SOC_GIC600_GICD_ITARGETSRn_CPUtargets_offset_2B_END (23)
#define SOC_GIC600_GICD_ITARGETSRn_CPUtargets_offset_3B_START (24)
#define SOC_GIC600_GICD_ITARGETSRn_CPUtargets_offset_3B_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int IntConfig : 32;
    } reg;
} SOC_GIC600_GICD_ICFGRn_UNION;
#endif
#define SOC_GIC600_GICD_ICFGRn_IntConfig_START (0)
#define SOC_GIC600_GICD_ICFGRn_IntConfig_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Group_modifier_bit : 32;
    } reg;
} SOC_GIC600_GICD_IGRPMODRn_UNION;
#endif
#define SOC_GIC600_GICD_IGRPMODRn_Group_modifier_bit_START (0)
#define SOC_GIC600_GICD_IGRPMODRn_Group_modifier_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ns_access : 32;
    } reg;
} SOC_GIC600_GICD_NSACRn_UNION;
#endif
#define SOC_GIC600_GICD_NSACRn_ns_access_START (0)
#define SOC_GIC600_GICD_NSACRn_ns_access_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intid : 4;
        unsigned int reserved_0 : 11;
        unsigned int nsatt : 1;
        unsigned int cputargetlist : 8;
        unsigned int targetlistfilter : 2;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_GIC600_GICD_SGIR_UNION;
#endif
#define SOC_GIC600_GICD_SGIR_intid_START (0)
#define SOC_GIC600_GICD_SGIR_intid_END (3)
#define SOC_GIC600_GICD_SGIR_nsatt_START (15)
#define SOC_GIC600_GICD_SGIR_nsatt_END (15)
#define SOC_GIC600_GICD_SGIR_cputargetlist_START (16)
#define SOC_GIC600_GICD_SGIR_cputargetlist_END (23)
#define SOC_GIC600_GICD_SGIR_targetlistfilter_START (24)
#define SOC_GIC600_GICD_SGIR_targetlistfilter_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sgi_clear_pending_bits : 32;
    } reg;
} SOC_GIC600_GICD_CPENDSGIN_UNION;
#endif
#define SOC_GIC600_GICD_CPENDSGIN_sgi_clear_pending_bits_START (0)
#define SOC_GIC600_GICD_CPENDSGIN_sgi_clear_pending_bits_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sgi_set_pending_bits : 32;
    } reg;
} SOC_GIC600_GICD_SPENDSGIRN_UNION;
#endif
#define SOC_GIC600_GICD_SPENDSGIRN_sgi_set_pending_bits_START (0)
#define SOC_GIC600_GICD_SPENDSGIRN_sgi_set_pending_bits_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long aff0 : 8;
        unsigned long long aff1 : 8;
        unsigned long long aff2 : 8;
        unsigned long long reserved_0: 7;
        unsigned long long irm : 1;
        unsigned long long aff3 : 8;
        unsigned long long reserved_1: 24;
    } reg;
} SOC_GIC600_GICD_IROUTERN_UNION;
#endif
#define SOC_GIC600_GICD_IROUTERN_aff0_START (0)
#define SOC_GIC600_GICD_IROUTERN_aff0_END (7)
#define SOC_GIC600_GICD_IROUTERN_aff1_START (8)
#define SOC_GIC600_GICD_IROUTERN_aff1_END (15)
#define SOC_GIC600_GICD_IROUTERN_aff2_START (16)
#define SOC_GIC600_GICD_IROUTERN_aff2_END (23)
#define SOC_GIC600_GICD_IROUTERN_irm_START (31)
#define SOC_GIC600_GICD_IROUTERN_irm_END (31)
#define SOC_GIC600_GICD_IROUTERN_aff3_START (32)
#define SOC_GIC600_GICD_IROUTERN_aff3_END (39)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GTR : 1;
        unsigned int GTS : 1;
        unsigned int GTO : 1;
        unsigned int reserved_0: 1;
        unsigned int RTS : 2;
        unsigned int reserved_1: 26;
    } reg;
} SOC_GIC600_GICD_CHIPSR_UNION;
#endif
#define SOC_GIC600_GICD_CHIPSR_GTR_START (0)
#define SOC_GIC600_GICD_CHIPSR_GTR_END (0)
#define SOC_GIC600_GICD_CHIPSR_GTS_START (1)
#define SOC_GIC600_GICD_CHIPSR_GTS_END (1)
#define SOC_GIC600_GICD_CHIPSR_GTO_START (2)
#define SOC_GIC600_GICD_CHIPSR_GTO_END (2)
#define SOC_GIC600_GICD_CHIPSR_RTS_START (4)
#define SOC_GIC600_GICD_CHIPSR_RTS_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PUP : 1;
        unsigned int reserved_0: 3;
        unsigned int rt_owner : 4;
        unsigned int reserved_1: 24;
    } reg;
} SOC_GIC600_GICD_DCHIPR_UNION;
#endif
#define SOC_GIC600_GICD_DCHIPR_PUP_START (0)
#define SOC_GIC600_GICD_DCHIPR_PUP_END (0)
#define SOC_GIC600_GICD_DCHIPR_rt_owner_START (4)
#define SOC_GIC600_GICD_DCHIPR_rt_owner_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long SocketState : 1;
        unsigned long long PUP : 1;
        unsigned long long reserved_0 : 3;
        unsigned long long SPI_BLOCKS : 5;
        unsigned long long SPI_BLOCK_MIN : 6;
        unsigned long long ADDR : 32;
        unsigned long long reserved_1 : 16;
    } reg;
} SOC_GIC600_GICD_CHIPR0_UNION;
#endif
#define SOC_GIC600_GICD_CHIPR0_SocketState_START (0)
#define SOC_GIC600_GICD_CHIPR0_SocketState_END (0)
#define SOC_GIC600_GICD_CHIPR0_PUP_START (1)
#define SOC_GIC600_GICD_CHIPR0_PUP_END (1)
#define SOC_GIC600_GICD_CHIPR0_SPI_BLOCKS_START (5)
#define SOC_GIC600_GICD_CHIPR0_SPI_BLOCKS_END (9)
#define SOC_GIC600_GICD_CHIPR0_SPI_BLOCK_MIN_START (10)
#define SOC_GIC600_GICD_CHIPR0_SPI_BLOCK_MIN_END (15)
#define SOC_GIC600_GICD_CHIPR0_ADDR_START (16)
#define SOC_GIC600_GICD_CHIPR0_ADDR_END (47)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long SocketState : 1;
        unsigned long long PUP : 1;
        unsigned long long reserved_0 : 3;
        unsigned long long SPI_BLOCKS : 5;
        unsigned long long SPI_BLOCK_MIN : 6;
        unsigned long long ADDR : 32;
        unsigned long long reserved_1 : 16;
    } reg;
} SOC_GIC600_GICD_CHIPR1_UNION;
#endif
#define SOC_GIC600_GICD_CHIPR1_SocketState_START (0)
#define SOC_GIC600_GICD_CHIPR1_SocketState_END (0)
#define SOC_GIC600_GICD_CHIPR1_PUP_START (1)
#define SOC_GIC600_GICD_CHIPR1_PUP_END (1)
#define SOC_GIC600_GICD_CHIPR1_SPI_BLOCKS_START (5)
#define SOC_GIC600_GICD_CHIPR1_SPI_BLOCKS_END (9)
#define SOC_GIC600_GICD_CHIPR1_SPI_BLOCK_MIN_START (10)
#define SOC_GIC600_GICD_CHIPR1_SPI_BLOCK_MIN_END (15)
#define SOC_GIC600_GICD_CHIPR1_ADDR_START (16)
#define SOC_GIC600_GICD_CHIPR1_ADDR_END (47)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Status : 32;
    } reg;
} SOC_GIC600_GICD_IERRR_UNION;
#endif
#define SOC_GIC600_GICD_IERRR_Status_START (0)
#define SOC_GIC600_GICD_IERRR_Status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Enable_LPIs : 1;
        unsigned int reserved_0 : 2;
        unsigned int RWP : 1;
        unsigned int reserved_1 : 20;
        unsigned int DPG0 : 1;
        unsigned int DPG1NS : 1;
        unsigned int DPG1S : 1;
        unsigned int reserved_2 : 4;
        unsigned int UWP : 1;
    } reg;
} SOC_GIC600_GICR0_CTLR_UNION;
#endif
#define SOC_GIC600_GICR0_CTLR_Enable_LPIs_START (0)
#define SOC_GIC600_GICR0_CTLR_Enable_LPIs_END (0)
#define SOC_GIC600_GICR0_CTLR_RWP_START (3)
#define SOC_GIC600_GICR0_CTLR_RWP_END (3)
#define SOC_GIC600_GICR0_CTLR_DPG0_START (24)
#define SOC_GIC600_GICR0_CTLR_DPG0_END (24)
#define SOC_GIC600_GICR0_CTLR_DPG1NS_START (25)
#define SOC_GIC600_GICR0_CTLR_DPG1NS_END (25)
#define SOC_GIC600_GICR0_CTLR_DPG1S_START (26)
#define SOC_GIC600_GICR0_CTLR_DPG1S_END (26)
#define SOC_GIC600_GICR0_CTLR_UWP_START (31)
#define SOC_GIC600_GICR0_CTLR_UWP_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Implementer : 12;
        unsigned int Revision : 4;
        unsigned int Variant : 4;
        unsigned int reserved : 4;
        unsigned int ProductID : 8;
    } reg;
} SOC_GIC600_GICR0_IIDR_UNION;
#endif
#define SOC_GIC600_GICR0_IIDR_Implementer_START (0)
#define SOC_GIC600_GICR0_IIDR_Implementer_END (11)
#define SOC_GIC600_GICR0_IIDR_Revision_START (12)
#define SOC_GIC600_GICR0_IIDR_Revision_END (15)
#define SOC_GIC600_GICR0_IIDR_Variant_START (16)
#define SOC_GIC600_GICR0_IIDR_Variant_END (19)
#define SOC_GIC600_GICR0_IIDR_ProductID_START (24)
#define SOC_GIC600_GICR0_IIDR_ProductID_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Sleep : 1;
        unsigned int ProcessorSleep : 1;
        unsigned int ChildrenAsleep : 1;
        unsigned int reserved : 28;
        unsigned int Quiescent : 1;
    } reg;
} SOC_GIC600_GICR0_WAKER_UNION;
#endif
#define SOC_GIC600_GICR0_WAKER_Sleep_START (0)
#define SOC_GIC600_GICR0_WAKER_Sleep_END (0)
#define SOC_GIC600_GICR0_WAKER_ProcessorSleep_START (1)
#define SOC_GIC600_GICR0_WAKER_ProcessorSleep_END (1)
#define SOC_GIC600_GICR0_WAKER_ChildrenAsleep_START (2)
#define SOC_GIC600_GICR0_WAKER_ChildrenAsleep_END (2)
#define SOC_GIC600_GICR0_WAKER_Quiescent_START (31)
#define SOC_GIC600_GICR0_WAKER_Quiescent_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int RDPD : 1;
        unsigned int RDAG : 1;
        unsigned int RDGPD : 1;
        unsigned int RDGPO : 1;
        unsigned int reserved_0: 4;
        unsigned int RDGO : 8;
        unsigned int RDG : 8;
        unsigned int reserved_1: 8;
    } reg;
} SOC_GIC600_GICR0_PWRR_UNION;
#endif
#define SOC_GIC600_GICR0_PWRR_RDPD_START (0)
#define SOC_GIC600_GICR0_PWRR_RDPD_END (0)
#define SOC_GIC600_GICR0_PWRR_RDAG_START (1)
#define SOC_GIC600_GICR0_PWRR_RDAG_END (1)
#define SOC_GIC600_GICR0_PWRR_RDGPD_START (2)
#define SOC_GIC600_GICR0_PWRR_RDGPD_END (2)
#define SOC_GIC600_GICR0_PWRR_RDGPO_START (3)
#define SOC_GIC600_GICR0_PWRR_RDGPO_END (3)
#define SOC_GIC600_GICR0_PWRR_RDGO_START (8)
#define SOC_GIC600_GICR0_PWRR_RDGO_END (15)
#define SOC_GIC600_GICR0_PWRR_RDG_START (16)
#define SOC_GIC600_GICR0_PWRR_RDG_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Redistributor_group_status_bit : 32;
    } reg;
} SOC_GIC600_GICR0_IGROUPR0_UNION;
#endif
#define SOC_GIC600_GICR0_IGROUPR0_Redistributor_group_status_bit_START (0)
#define SOC_GIC600_GICR0_IGROUPR0_Redistributor_group_status_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Set_enable_bit : 32;
    } reg;
} SOC_GIC600_GICR0_ISENABLER0_UNION;
#endif
#define SOC_GIC600_GICR0_ISENABLER0_Set_enable_bit_START (0)
#define SOC_GIC600_GICR0_ISENABLER0_Set_enable_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Clear_enable_bit : 32;
    } reg;
} SOC_GIC600_GICR0_ICENABLER0_UNION;
#endif
#define SOC_GIC600_GICR0_ICENABLER0_Clear_enable_bit_START (0)
#define SOC_GIC600_GICR0_ICENABLER0_Clear_enable_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Set_pending_bit : 32;
    } reg;
} SOC_GIC600_GICR_ISPENDR0_UNION;
#endif
#define SOC_GIC600_GICR_ISPENDR0_Set_pending_bit_START (0)
#define SOC_GIC600_GICR_ISPENDR0_Set_pending_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Clear_pending_bit : 32;
    } reg;
} SOC_GIC600_GICR_ICPENDR0_UNION;
#endif
#define SOC_GIC600_GICR_ICPENDR0_Clear_pending_bit_START (0)
#define SOC_GIC600_GICR_ICPENDR0_Clear_pending_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Set_active_bit : 32;
    } reg;
} SOC_GIC600_GICR0_ISACTIVER0_UNION;
#endif
#define SOC_GIC600_GICR0_ISACTIVER0_Set_active_bit_START (0)
#define SOC_GIC600_GICR0_ISACTIVER0_Set_active_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Clear_active_bit : 32;
    } reg;
} SOC_GIC600_GICR0_ICACTIVER0_UNION;
#endif
#define SOC_GIC600_GICR0_ICACTIVER0_Clear_active_bit_START (0)
#define SOC_GIC600_GICR0_ICACTIVER0_Clear_active_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Priority_offset_0B : 8;
        unsigned int Priority_offset_1B : 8;
        unsigned int Priority_offset_2B : 8;
        unsigned int Priority_offset_3B : 8;
    } reg;
} SOC_GIC600_GICR0_IPRIORITYRn_UNION;
#endif
#define SOC_GIC600_GICR0_IPRIORITYRn_Priority_offset_0B_START (0)
#define SOC_GIC600_GICR0_IPRIORITYRn_Priority_offset_0B_END (7)
#define SOC_GIC600_GICR0_IPRIORITYRn_Priority_offset_1B_START (8)
#define SOC_GIC600_GICR0_IPRIORITYRn_Priority_offset_1B_END (15)
#define SOC_GIC600_GICR0_IPRIORITYRn_Priority_offset_2B_START (16)
#define SOC_GIC600_GICR0_IPRIORITYRn_Priority_offset_2B_END (23)
#define SOC_GIC600_GICR0_IPRIORITYRn_Priority_offset_3B_START (24)
#define SOC_GIC600_GICR0_IPRIORITYRn_Priority_offset_3B_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Int_config : 32;
    } reg;
} SOC_GIC600_GICR0_ICFGR0_UNION;
#endif
#define SOC_GIC600_GICR0_ICFGR0_Int_config_START (0)
#define SOC_GIC600_GICR0_ICFGR0_Int_config_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Int_config : 32;
    } reg;
} SOC_GIC600_GICR0_ICFGR1_UNION;
#endif
#define SOC_GIC600_GICR0_ICFGR1_Int_config_START (0)
#define SOC_GIC600_GICR0_ICFGR1_Int_config_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Group_modifier_bit : 32;
    } reg;
} SOC_GIC600_GICR0_IGRPMODR0_UNION;
#endif
#define SOC_GIC600_GICR0_IGRPMODR0_Group_modifier_bit_START (0)
#define SOC_GIC600_GICR0_IGRPMODR0_Group_modifier_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int NS_access : 32;
    } reg;
} SOC_GIC600_GICR0_NSACR_UNION;
#endif
#define SOC_GIC600_GICR0_NSACR_NS_access_START (0)
#define SOC_GIC600_GICR0_NSACR_NS_access_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int EnableGrp0 : 1;
        unsigned int EnableGrp1NSecure : 1;
        unsigned int EnableGrp1Secure : 1;
        unsigned int reserved_0 : 1;
        unsigned int AccessType : 1;
        unsigned int reserved_1 : 25;
        unsigned int wake_request : 1;
        unsigned int cpu_active : 1;
    } reg;
} SOC_GIC600_GICR0_MISCSTATUSR_UNION;
#endif
#define SOC_GIC600_GICR0_MISCSTATUSR_EnableGrp0_START (0)
#define SOC_GIC600_GICR0_MISCSTATUSR_EnableGrp0_END (0)
#define SOC_GIC600_GICR0_MISCSTATUSR_EnableGrp1NSecure_START (1)
#define SOC_GIC600_GICR0_MISCSTATUSR_EnableGrp1NSecure_END (1)
#define SOC_GIC600_GICR0_MISCSTATUSR_EnableGrp1Secure_START (2)
#define SOC_GIC600_GICR0_MISCSTATUSR_EnableGrp1Secure_END (2)
#define SOC_GIC600_GICR0_MISCSTATUSR_AccessType_START (4)
#define SOC_GIC600_GICR0_MISCSTATUSR_AccessType_END (4)
#define SOC_GIC600_GICR0_MISCSTATUSR_wake_request_START (30)
#define SOC_GIC600_GICR0_MISCSTATUSR_wake_request_END (30)
#define SOC_GIC600_GICR0_MISCSTATUSR_cpu_active_START (31)
#define SOC_GIC600_GICR0_MISCSTATUSR_cpu_active_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Enable_LPIs : 1;
        unsigned int reserved_0 : 2;
        unsigned int RWP : 1;
        unsigned int reserved_1 : 20;
        unsigned int DPG0 : 1;
        unsigned int DPG1NS : 1;
        unsigned int DPG1S : 1;
        unsigned int reserved_2 : 4;
        unsigned int uwp : 1;
    } reg;
} SOC_GIC600_GICR1_CTLR_UNION;
#endif
#define SOC_GIC600_GICR1_CTLR_Enable_LPIs_START (0)
#define SOC_GIC600_GICR1_CTLR_Enable_LPIs_END (0)
#define SOC_GIC600_GICR1_CTLR_RWP_START (3)
#define SOC_GIC600_GICR1_CTLR_RWP_END (3)
#define SOC_GIC600_GICR1_CTLR_DPG0_START (24)
#define SOC_GIC600_GICR1_CTLR_DPG0_END (24)
#define SOC_GIC600_GICR1_CTLR_DPG1NS_START (25)
#define SOC_GIC600_GICR1_CTLR_DPG1NS_END (25)
#define SOC_GIC600_GICR1_CTLR_DPG1S_START (26)
#define SOC_GIC600_GICR1_CTLR_DPG1S_END (26)
#define SOC_GIC600_GICR1_CTLR_uwp_START (31)
#define SOC_GIC600_GICR1_CTLR_uwp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Implementer : 12;
        unsigned int Revision : 4;
        unsigned int Variant : 4;
        unsigned int reserved : 4;
        unsigned int ProductID : 8;
    } reg;
} SOC_GIC600_GICR1_IIDR_UNION;
#endif
#define SOC_GIC600_GICR1_IIDR_Implementer_START (0)
#define SOC_GIC600_GICR1_IIDR_Implementer_END (11)
#define SOC_GIC600_GICR1_IIDR_Revision_START (12)
#define SOC_GIC600_GICR1_IIDR_Revision_END (15)
#define SOC_GIC600_GICR1_IIDR_Variant_START (16)
#define SOC_GIC600_GICR1_IIDR_Variant_END (19)
#define SOC_GIC600_GICR1_IIDR_ProductID_START (24)
#define SOC_GIC600_GICR1_IIDR_ProductID_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Sleep : 1;
        unsigned int ProcessorSleep : 1;
        unsigned int ChildrenAsleep : 1;
        unsigned int reserved : 28;
        unsigned int Quiescent : 1;
    } reg;
} SOC_GIC600_GICR1_WAKER_UNION;
#endif
#define SOC_GIC600_GICR1_WAKER_Sleep_START (0)
#define SOC_GIC600_GICR1_WAKER_Sleep_END (0)
#define SOC_GIC600_GICR1_WAKER_ProcessorSleep_START (1)
#define SOC_GIC600_GICR1_WAKER_ProcessorSleep_END (1)
#define SOC_GIC600_GICR1_WAKER_ChildrenAsleep_START (2)
#define SOC_GIC600_GICR1_WAKER_ChildrenAsleep_END (2)
#define SOC_GIC600_GICR1_WAKER_Quiescent_START (31)
#define SOC_GIC600_GICR1_WAKER_Quiescent_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int RDPD : 1;
        unsigned int RDAG : 1;
        unsigned int RDGPD : 1;
        unsigned int RDGPO : 1;
        unsigned int reserved_0: 4;
        unsigned int RDGO : 8;
        unsigned int RDG : 8;
        unsigned int reserved_1: 8;
    } reg;
} SOC_GIC600_GICR1_PWRR_UNION;
#endif
#define SOC_GIC600_GICR1_PWRR_RDPD_START (0)
#define SOC_GIC600_GICR1_PWRR_RDPD_END (0)
#define SOC_GIC600_GICR1_PWRR_RDAG_START (1)
#define SOC_GIC600_GICR1_PWRR_RDAG_END (1)
#define SOC_GIC600_GICR1_PWRR_RDGPD_START (2)
#define SOC_GIC600_GICR1_PWRR_RDGPD_END (2)
#define SOC_GIC600_GICR1_PWRR_RDGPO_START (3)
#define SOC_GIC600_GICR1_PWRR_RDGPO_END (3)
#define SOC_GIC600_GICR1_PWRR_RDGO_START (8)
#define SOC_GIC600_GICR1_PWRR_RDGO_END (15)
#define SOC_GIC600_GICR1_PWRR_RDG_START (16)
#define SOC_GIC600_GICR1_PWRR_RDG_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Redistributor_group_status_bit : 32;
    } reg;
} SOC_GIC600_GICR1_IGROUPR0_UNION;
#endif
#define SOC_GIC600_GICR1_IGROUPR0_Redistributor_group_status_bit_START (0)
#define SOC_GIC600_GICR1_IGROUPR0_Redistributor_group_status_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Set_enable_bit : 32;
    } reg;
} SOC_GIC600_GICR1_ISENABLER0_UNION;
#endif
#define SOC_GIC600_GICR1_ISENABLER0_Set_enable_bit_START (0)
#define SOC_GIC600_GICR1_ISENABLER0_Set_enable_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Clear_enable_bit : 32;
    } reg;
} SOC_GIC600_GICR1_ICENABLER0_UNION;
#endif
#define SOC_GIC600_GICR1_ICENABLER0_Clear_enable_bit_START (0)
#define SOC_GIC600_GICR1_ICENABLER0_Clear_enable_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Set_pending_bit : 32;
    } reg;
} SOC_GIC600_GICR1_ISPENDR0_UNION;
#endif
#define SOC_GIC600_GICR1_ISPENDR0_Set_pending_bit_START (0)
#define SOC_GIC600_GICR1_ISPENDR0_Set_pending_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Clear_pending_bit : 32;
    } reg;
} SOC_GIC600_GICR1_ICPENDR0_UNION;
#endif
#define SOC_GIC600_GICR1_ICPENDR0_Clear_pending_bit_START (0)
#define SOC_GIC600_GICR1_ICPENDR0_Clear_pending_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Set_active_bit : 32;
    } reg;
} SOC_GIC600_GICR1_ISACTIVER0_UNION;
#endif
#define SOC_GIC600_GICR1_ISACTIVER0_Set_active_bit_START (0)
#define SOC_GIC600_GICR1_ISACTIVER0_Set_active_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Clear_active_bit : 32;
    } reg;
} SOC_GIC600_GICR1_ICACTIVER0_UNION;
#endif
#define SOC_GIC600_GICR1_ICACTIVER0_Clear_active_bit_START (0)
#define SOC_GIC600_GICR1_ICACTIVER0_Clear_active_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Priority_offset_0B : 8;
        unsigned int Priority_offset_1B : 8;
        unsigned int Priority_offset_2B : 8;
        unsigned int Priority_offset_3B : 8;
    } reg;
} SOC_GIC600_GICR1_IPRIORITYRn_UNION;
#endif
#define SOC_GIC600_GICR1_IPRIORITYRn_Priority_offset_0B_START (0)
#define SOC_GIC600_GICR1_IPRIORITYRn_Priority_offset_0B_END (7)
#define SOC_GIC600_GICR1_IPRIORITYRn_Priority_offset_1B_START (8)
#define SOC_GIC600_GICR1_IPRIORITYRn_Priority_offset_1B_END (15)
#define SOC_GIC600_GICR1_IPRIORITYRn_Priority_offset_2B_START (16)
#define SOC_GIC600_GICR1_IPRIORITYRn_Priority_offset_2B_END (23)
#define SOC_GIC600_GICR1_IPRIORITYRn_Priority_offset_3B_START (24)
#define SOC_GIC600_GICR1_IPRIORITYRn_Priority_offset_3B_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Int_config : 32;
    } reg;
} SOC_GIC600_GICR1_ICFGR0_UNION;
#endif
#define SOC_GIC600_GICR1_ICFGR0_Int_config_START (0)
#define SOC_GIC600_GICR1_ICFGR0_Int_config_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Int_config : 32;
    } reg;
} SOC_GIC600_GICR1_ICFGR1_UNION;
#endif
#define SOC_GIC600_GICR1_ICFGR1_Int_config_START (0)
#define SOC_GIC600_GICR1_ICFGR1_Int_config_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Group_modifier_bit : 32;
    } reg;
} SOC_GIC600_GICR1_IGRPMODR0_UNION;
#endif
#define SOC_GIC600_GICR1_IGRPMODR0_Group_modifier_bit_START (0)
#define SOC_GIC600_GICR1_IGRPMODR0_Group_modifier_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int NS_access : 32;
    } reg;
} SOC_GIC600_GICR1_NSACR_UNION;
#endif
#define SOC_GIC600_GICR1_NSACR_NS_access_START (0)
#define SOC_GIC600_GICR1_NSACR_NS_access_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int EnableGrp0 : 1;
        unsigned int EnableGrp1NSecure : 1;
        unsigned int EnableGrp1Secure : 1;
        unsigned int reserved_0 : 1;
        unsigned int AccessType : 1;
        unsigned int reserved_1 : 25;
        unsigned int wake_request : 1;
        unsigned int cpu_active : 1;
    } reg;
} SOC_GIC600_GICR1_MISCSTATUSR_UNION;
#endif
#define SOC_GIC600_GICR1_MISCSTATUSR_EnableGrp0_START (0)
#define SOC_GIC600_GICR1_MISCSTATUSR_EnableGrp0_END (0)
#define SOC_GIC600_GICR1_MISCSTATUSR_EnableGrp1NSecure_START (1)
#define SOC_GIC600_GICR1_MISCSTATUSR_EnableGrp1NSecure_END (1)
#define SOC_GIC600_GICR1_MISCSTATUSR_EnableGrp1Secure_START (2)
#define SOC_GIC600_GICR1_MISCSTATUSR_EnableGrp1Secure_END (2)
#define SOC_GIC600_GICR1_MISCSTATUSR_AccessType_START (4)
#define SOC_GIC600_GICR1_MISCSTATUSR_AccessType_END (4)
#define SOC_GIC600_GICR1_MISCSTATUSR_wake_request_START (30)
#define SOC_GIC600_GICR1_MISCSTATUSR_wake_request_END (30)
#define SOC_GIC600_GICR1_MISCSTATUSR_cpu_active_START (31)
#define SOC_GIC600_GICR1_MISCSTATUSR_cpu_active_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Enable_LPIs : 1;
        unsigned int reserved_0 : 2;
        unsigned int RWP : 1;
        unsigned int reserved_1 : 20;
        unsigned int DPG0 : 1;
        unsigned int DPG1NS : 1;
        unsigned int DPG1S : 1;
        unsigned int reserved_2 : 4;
        unsigned int uwp : 1;
    } reg;
} SOC_GIC600_GICR2_CTLR_UNION;
#endif
#define SOC_GIC600_GICR2_CTLR_Enable_LPIs_START (0)
#define SOC_GIC600_GICR2_CTLR_Enable_LPIs_END (0)
#define SOC_GIC600_GICR2_CTLR_RWP_START (3)
#define SOC_GIC600_GICR2_CTLR_RWP_END (3)
#define SOC_GIC600_GICR2_CTLR_DPG0_START (24)
#define SOC_GIC600_GICR2_CTLR_DPG0_END (24)
#define SOC_GIC600_GICR2_CTLR_DPG1NS_START (25)
#define SOC_GIC600_GICR2_CTLR_DPG1NS_END (25)
#define SOC_GIC600_GICR2_CTLR_DPG1S_START (26)
#define SOC_GIC600_GICR2_CTLR_DPG1S_END (26)
#define SOC_GIC600_GICR2_CTLR_uwp_START (31)
#define SOC_GIC600_GICR2_CTLR_uwp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Implementer : 12;
        unsigned int Revision : 4;
        unsigned int Variant : 4;
        unsigned int reserved : 4;
        unsigned int ProductID : 8;
    } reg;
} SOC_GIC600_GICR2_IIDR_UNION;
#endif
#define SOC_GIC600_GICR2_IIDR_Implementer_START (0)
#define SOC_GIC600_GICR2_IIDR_Implementer_END (11)
#define SOC_GIC600_GICR2_IIDR_Revision_START (12)
#define SOC_GIC600_GICR2_IIDR_Revision_END (15)
#define SOC_GIC600_GICR2_IIDR_Variant_START (16)
#define SOC_GIC600_GICR2_IIDR_Variant_END (19)
#define SOC_GIC600_GICR2_IIDR_ProductID_START (24)
#define SOC_GIC600_GICR2_IIDR_ProductID_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Sleep : 1;
        unsigned int ProcessorSleep : 1;
        unsigned int ChildrenAsleep : 1;
        unsigned int reserved : 28;
        unsigned int Quiescent : 1;
    } reg;
} SOC_GIC600_GICR2_WAKER_UNION;
#endif
#define SOC_GIC600_GICR2_WAKER_Sleep_START (0)
#define SOC_GIC600_GICR2_WAKER_Sleep_END (0)
#define SOC_GIC600_GICR2_WAKER_ProcessorSleep_START (1)
#define SOC_GIC600_GICR2_WAKER_ProcessorSleep_END (1)
#define SOC_GIC600_GICR2_WAKER_ChildrenAsleep_START (2)
#define SOC_GIC600_GICR2_WAKER_ChildrenAsleep_END (2)
#define SOC_GIC600_GICR2_WAKER_Quiescent_START (31)
#define SOC_GIC600_GICR2_WAKER_Quiescent_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int RDPD : 1;
        unsigned int RDAG : 1;
        unsigned int RDGPD : 1;
        unsigned int RDGPO : 1;
        unsigned int reserved_0: 4;
        unsigned int RDGO : 8;
        unsigned int RDG : 8;
        unsigned int reserved_1: 8;
    } reg;
} SOC_GIC600_GICR2_PWRR_UNION;
#endif
#define SOC_GIC600_GICR2_PWRR_RDPD_START (0)
#define SOC_GIC600_GICR2_PWRR_RDPD_END (0)
#define SOC_GIC600_GICR2_PWRR_RDAG_START (1)
#define SOC_GIC600_GICR2_PWRR_RDAG_END (1)
#define SOC_GIC600_GICR2_PWRR_RDGPD_START (2)
#define SOC_GIC600_GICR2_PWRR_RDGPD_END (2)
#define SOC_GIC600_GICR2_PWRR_RDGPO_START (3)
#define SOC_GIC600_GICR2_PWRR_RDGPO_END (3)
#define SOC_GIC600_GICR2_PWRR_RDGO_START (8)
#define SOC_GIC600_GICR2_PWRR_RDGO_END (15)
#define SOC_GIC600_GICR2_PWRR_RDG_START (16)
#define SOC_GIC600_GICR2_PWRR_RDG_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Redistributor_group_status_bit : 32;
    } reg;
} SOC_GIC600_GICR2_IGROUPR0_UNION;
#endif
#define SOC_GIC600_GICR2_IGROUPR0_Redistributor_group_status_bit_START (0)
#define SOC_GIC600_GICR2_IGROUPR0_Redistributor_group_status_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Set_enable_bit : 32;
    } reg;
} SOC_GIC600_GICR2_ISENABLER0_UNION;
#endif
#define SOC_GIC600_GICR2_ISENABLER0_Set_enable_bit_START (0)
#define SOC_GIC600_GICR2_ISENABLER0_Set_enable_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Clear_enable_bit : 32;
    } reg;
} SOC_GIC600_GICR2_ICENABLER0_UNION;
#endif
#define SOC_GIC600_GICR2_ICENABLER0_Clear_enable_bit_START (0)
#define SOC_GIC600_GICR2_ICENABLER0_Clear_enable_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Set_pending_bit : 32;
    } reg;
} SOC_GIC600_GICR2_ISPENDR0_UNION;
#endif
#define SOC_GIC600_GICR2_ISPENDR0_Set_pending_bit_START (0)
#define SOC_GIC600_GICR2_ISPENDR0_Set_pending_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Clear_pending_bit : 32;
    } reg;
} SOC_GIC600_GICR2_ICPENDR0_UNION;
#endif
#define SOC_GIC600_GICR2_ICPENDR0_Clear_pending_bit_START (0)
#define SOC_GIC600_GICR2_ICPENDR0_Clear_pending_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Set_active_bit : 32;
    } reg;
} SOC_GIC600_GICR_ISACTIVER0_UNION;
#endif
#define SOC_GIC600_GICR_ISACTIVER0_Set_active_bit_START (0)
#define SOC_GIC600_GICR_ISACTIVER0_Set_active_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Clear_active_bit : 32;
    } reg;
} SOC_GIC600_GICR2_ICACTIVER0_UNION;
#endif
#define SOC_GIC600_GICR2_ICACTIVER0_Clear_active_bit_START (0)
#define SOC_GIC600_GICR2_ICACTIVER0_Clear_active_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Priority_offset_0B : 8;
        unsigned int Priority_offset_1B : 8;
        unsigned int Priority_offset_2B : 8;
        unsigned int Priority_offset_3B : 8;
    } reg;
} SOC_GIC600_GICR2_IPRIORITYRn_UNION;
#endif
#define SOC_GIC600_GICR2_IPRIORITYRn_Priority_offset_0B_START (0)
#define SOC_GIC600_GICR2_IPRIORITYRn_Priority_offset_0B_END (7)
#define SOC_GIC600_GICR2_IPRIORITYRn_Priority_offset_1B_START (8)
#define SOC_GIC600_GICR2_IPRIORITYRn_Priority_offset_1B_END (15)
#define SOC_GIC600_GICR2_IPRIORITYRn_Priority_offset_2B_START (16)
#define SOC_GIC600_GICR2_IPRIORITYRn_Priority_offset_2B_END (23)
#define SOC_GIC600_GICR2_IPRIORITYRn_Priority_offset_3B_START (24)
#define SOC_GIC600_GICR2_IPRIORITYRn_Priority_offset_3B_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Int_config : 32;
    } reg;
} SOC_GIC600_GICR2_ICFGR0_UNION;
#endif
#define SOC_GIC600_GICR2_ICFGR0_Int_config_START (0)
#define SOC_GIC600_GICR2_ICFGR0_Int_config_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Int_config : 32;
    } reg;
} SOC_GIC600_GICR2_ICFGR1_UNION;
#endif
#define SOC_GIC600_GICR2_ICFGR1_Int_config_START (0)
#define SOC_GIC600_GICR2_ICFGR1_Int_config_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Group_modifier_bit : 32;
    } reg;
} SOC_GIC600_GICR2_IGRPMODR0_UNION;
#endif
#define SOC_GIC600_GICR2_IGRPMODR0_Group_modifier_bit_START (0)
#define SOC_GIC600_GICR2_IGRPMODR0_Group_modifier_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int NS_access : 32;
    } reg;
} SOC_GIC600_GICR2_NSACR_UNION;
#endif
#define SOC_GIC600_GICR2_NSACR_NS_access_START (0)
#define SOC_GIC600_GICR2_NSACR_NS_access_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int EnableGrp0 : 1;
        unsigned int EnableGrp1NSecure : 1;
        unsigned int EnableGrp1Secure : 1;
        unsigned int reserved_0 : 1;
        unsigned int AccessType : 1;
        unsigned int reserved_1 : 25;
        unsigned int wake_request : 1;
        unsigned int cpu_active : 1;
    } reg;
} SOC_GIC600_GICR2_MISCSTATUSR_UNION;
#endif
#define SOC_GIC600_GICR2_MISCSTATUSR_EnableGrp0_START (0)
#define SOC_GIC600_GICR2_MISCSTATUSR_EnableGrp0_END (0)
#define SOC_GIC600_GICR2_MISCSTATUSR_EnableGrp1NSecure_START (1)
#define SOC_GIC600_GICR2_MISCSTATUSR_EnableGrp1NSecure_END (1)
#define SOC_GIC600_GICR2_MISCSTATUSR_EnableGrp1Secure_START (2)
#define SOC_GIC600_GICR2_MISCSTATUSR_EnableGrp1Secure_END (2)
#define SOC_GIC600_GICR2_MISCSTATUSR_AccessType_START (4)
#define SOC_GIC600_GICR2_MISCSTATUSR_AccessType_END (4)
#define SOC_GIC600_GICR2_MISCSTATUSR_wake_request_START (30)
#define SOC_GIC600_GICR2_MISCSTATUSR_wake_request_END (30)
#define SOC_GIC600_GICR2_MISCSTATUSR_cpu_active_START (31)
#define SOC_GIC600_GICR2_MISCSTATUSR_cpu_active_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Enable_LPIs : 1;
        unsigned int reserved_0 : 2;
        unsigned int RWP : 1;
        unsigned int reserved_1 : 20;
        unsigned int DPG0 : 1;
        unsigned int DPG1NS : 1;
        unsigned int DPG1S : 1;
        unsigned int reserved_2 : 4;
        unsigned int uwp : 1;
    } reg;
} SOC_GIC600_GICR3_CTLR_UNION;
#endif
#define SOC_GIC600_GICR3_CTLR_Enable_LPIs_START (0)
#define SOC_GIC600_GICR3_CTLR_Enable_LPIs_END (0)
#define SOC_GIC600_GICR3_CTLR_RWP_START (3)
#define SOC_GIC600_GICR3_CTLR_RWP_END (3)
#define SOC_GIC600_GICR3_CTLR_DPG0_START (24)
#define SOC_GIC600_GICR3_CTLR_DPG0_END (24)
#define SOC_GIC600_GICR3_CTLR_DPG1NS_START (25)
#define SOC_GIC600_GICR3_CTLR_DPG1NS_END (25)
#define SOC_GIC600_GICR3_CTLR_DPG1S_START (26)
#define SOC_GIC600_GICR3_CTLR_DPG1S_END (26)
#define SOC_GIC600_GICR3_CTLR_uwp_START (31)
#define SOC_GIC600_GICR3_CTLR_uwp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Implementer : 12;
        unsigned int Revision : 4;
        unsigned int Variant : 4;
        unsigned int reserved : 4;
        unsigned int ProductID : 8;
    } reg;
} SOC_GIC600_GICR3_IIDR_UNION;
#endif
#define SOC_GIC600_GICR3_IIDR_Implementer_START (0)
#define SOC_GIC600_GICR3_IIDR_Implementer_END (11)
#define SOC_GIC600_GICR3_IIDR_Revision_START (12)
#define SOC_GIC600_GICR3_IIDR_Revision_END (15)
#define SOC_GIC600_GICR3_IIDR_Variant_START (16)
#define SOC_GIC600_GICR3_IIDR_Variant_END (19)
#define SOC_GIC600_GICR3_IIDR_ProductID_START (24)
#define SOC_GIC600_GICR3_IIDR_ProductID_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Sleep : 1;
        unsigned int ProcessorSleep : 1;
        unsigned int ChildrenAsleep : 1;
        unsigned int reserved : 28;
        unsigned int Quiescent : 1;
    } reg;
} SOC_GIC600_GICR3_WAKER_UNION;
#endif
#define SOC_GIC600_GICR3_WAKER_Sleep_START (0)
#define SOC_GIC600_GICR3_WAKER_Sleep_END (0)
#define SOC_GIC600_GICR3_WAKER_ProcessorSleep_START (1)
#define SOC_GIC600_GICR3_WAKER_ProcessorSleep_END (1)
#define SOC_GIC600_GICR3_WAKER_ChildrenAsleep_START (2)
#define SOC_GIC600_GICR3_WAKER_ChildrenAsleep_END (2)
#define SOC_GIC600_GICR3_WAKER_Quiescent_START (31)
#define SOC_GIC600_GICR3_WAKER_Quiescent_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int RDPD : 1;
        unsigned int RDAG : 1;
        unsigned int RDGPD : 1;
        unsigned int RDGPO : 1;
        unsigned int reserved_0: 4;
        unsigned int RDGO : 8;
        unsigned int RDG : 8;
        unsigned int reserved_1: 8;
    } reg;
} SOC_GIC600_GICR3_PWRR_UNION;
#endif
#define SOC_GIC600_GICR3_PWRR_RDPD_START (0)
#define SOC_GIC600_GICR3_PWRR_RDPD_END (0)
#define SOC_GIC600_GICR3_PWRR_RDAG_START (1)
#define SOC_GIC600_GICR3_PWRR_RDAG_END (1)
#define SOC_GIC600_GICR3_PWRR_RDGPD_START (2)
#define SOC_GIC600_GICR3_PWRR_RDGPD_END (2)
#define SOC_GIC600_GICR3_PWRR_RDGPO_START (3)
#define SOC_GIC600_GICR3_PWRR_RDGPO_END (3)
#define SOC_GIC600_GICR3_PWRR_RDGO_START (8)
#define SOC_GIC600_GICR3_PWRR_RDGO_END (15)
#define SOC_GIC600_GICR3_PWRR_RDG_START (16)
#define SOC_GIC600_GICR3_PWRR_RDG_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Redistributor_group_status_bit : 32;
    } reg;
} SOC_GIC600_GICR3_IGROUPR0_UNION;
#endif
#define SOC_GIC600_GICR3_IGROUPR0_Redistributor_group_status_bit_START (0)
#define SOC_GIC600_GICR3_IGROUPR0_Redistributor_group_status_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Set_enable_bit : 32;
    } reg;
} SOC_GIC600_GICR3_ISENABLER0_UNION;
#endif
#define SOC_GIC600_GICR3_ISENABLER0_Set_enable_bit_START (0)
#define SOC_GIC600_GICR3_ISENABLER0_Set_enable_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Clear_enable_bit : 32;
    } reg;
} SOC_GIC600_GICR3_ICENABLER0_UNION;
#endif
#define SOC_GIC600_GICR3_ICENABLER0_Clear_enable_bit_START (0)
#define SOC_GIC600_GICR3_ICENABLER0_Clear_enable_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Set_pending_bit : 32;
    } reg;
} SOC_GIC600_GICR3_ISPENDR0_UNION;
#endif
#define SOC_GIC600_GICR3_ISPENDR0_Set_pending_bit_START (0)
#define SOC_GIC600_GICR3_ISPENDR0_Set_pending_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Clear_pending_bit : 32;
    } reg;
} SOC_GIC600_GICR3_ICPENDR0_UNION;
#endif
#define SOC_GIC600_GICR3_ICPENDR0_Clear_pending_bit_START (0)
#define SOC_GIC600_GICR3_ICPENDR0_Clear_pending_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Set_active_bit : 32;
    } reg;
} SOC_GIC600_GICR3_ISACTIVER0_UNION;
#endif
#define SOC_GIC600_GICR3_ISACTIVER0_Set_active_bit_START (0)
#define SOC_GIC600_GICR3_ISACTIVER0_Set_active_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Clear_active_bit : 32;
    } reg;
} SOC_GIC600_GICR3_ICACTIVER0_UNION;
#endif
#define SOC_GIC600_GICR3_ICACTIVER0_Clear_active_bit_START (0)
#define SOC_GIC600_GICR3_ICACTIVER0_Clear_active_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Priority_offset_0B : 8;
        unsigned int Priority_offset_1B : 8;
        unsigned int Priority_offset_2B : 8;
        unsigned int Priority_offset_3B : 8;
    } reg;
} SOC_GIC600_GICR3_IPRIORITYRn_UNION;
#endif
#define SOC_GIC600_GICR3_IPRIORITYRn_Priority_offset_0B_START (0)
#define SOC_GIC600_GICR3_IPRIORITYRn_Priority_offset_0B_END (7)
#define SOC_GIC600_GICR3_IPRIORITYRn_Priority_offset_1B_START (8)
#define SOC_GIC600_GICR3_IPRIORITYRn_Priority_offset_1B_END (15)
#define SOC_GIC600_GICR3_IPRIORITYRn_Priority_offset_2B_START (16)
#define SOC_GIC600_GICR3_IPRIORITYRn_Priority_offset_2B_END (23)
#define SOC_GIC600_GICR3_IPRIORITYRn_Priority_offset_3B_START (24)
#define SOC_GIC600_GICR3_IPRIORITYRn_Priority_offset_3B_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Int_config : 32;
    } reg;
} SOC_GIC600_GICR3_ICFGR0_UNION;
#endif
#define SOC_GIC600_GICR3_ICFGR0_Int_config_START (0)
#define SOC_GIC600_GICR3_ICFGR0_Int_config_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Int_config : 32;
    } reg;
} SOC_GIC600_GICR3_ICFGR1_UNION;
#endif
#define SOC_GIC600_GICR3_ICFGR1_Int_config_START (0)
#define SOC_GIC600_GICR3_ICFGR1_Int_config_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Group_modifier_bit : 32;
    } reg;
} SOC_GIC600_GICR3_IGRPMODR0_UNION;
#endif
#define SOC_GIC600_GICR3_IGRPMODR0_Group_modifier_bit_START (0)
#define SOC_GIC600_GICR3_IGRPMODR0_Group_modifier_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int NS_access : 32;
    } reg;
} SOC_GIC600_GICR3_NSACR_UNION;
#endif
#define SOC_GIC600_GICR3_NSACR_NS_access_START (0)
#define SOC_GIC600_GICR3_NSACR_NS_access_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int EnableGrp0 : 1;
        unsigned int EnableGrp1NSecure : 1;
        unsigned int EnableGrp1Secure : 1;
        unsigned int reserved_0 : 1;
        unsigned int AccessType : 1;
        unsigned int reserved_1 : 25;
        unsigned int wake_request : 1;
        unsigned int cpu_active : 1;
    } reg;
} SOC_GIC600_GICR3_MISCSTATUSR_UNION;
#endif
#define SOC_GIC600_GICR3_MISCSTATUSR_EnableGrp0_START (0)
#define SOC_GIC600_GICR3_MISCSTATUSR_EnableGrp0_END (0)
#define SOC_GIC600_GICR3_MISCSTATUSR_EnableGrp1NSecure_START (1)
#define SOC_GIC600_GICR3_MISCSTATUSR_EnableGrp1NSecure_END (1)
#define SOC_GIC600_GICR3_MISCSTATUSR_EnableGrp1Secure_START (2)
#define SOC_GIC600_GICR3_MISCSTATUSR_EnableGrp1Secure_END (2)
#define SOC_GIC600_GICR3_MISCSTATUSR_AccessType_START (4)
#define SOC_GIC600_GICR3_MISCSTATUSR_AccessType_END (4)
#define SOC_GIC600_GICR3_MISCSTATUSR_wake_request_START (30)
#define SOC_GIC600_GICR3_MISCSTATUSR_wake_request_END (30)
#define SOC_GIC600_GICR3_MISCSTATUSR_cpu_active_START (31)
#define SOC_GIC600_GICR3_MISCSTATUSR_cpu_active_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Enable_LPIs : 1;
        unsigned int reserved_0 : 2;
        unsigned int RWP : 1;
        unsigned int reserved_1 : 20;
        unsigned int DPG0 : 1;
        unsigned int DPG1NS : 1;
        unsigned int DPG1S : 1;
        unsigned int reserved_2 : 4;
        unsigned int uwp : 1;
    } reg;
} SOC_GIC600_GICR4_CTLR_UNION;
#endif
#define SOC_GIC600_GICR4_CTLR_Enable_LPIs_START (0)
#define SOC_GIC600_GICR4_CTLR_Enable_LPIs_END (0)
#define SOC_GIC600_GICR4_CTLR_RWP_START (3)
#define SOC_GIC600_GICR4_CTLR_RWP_END (3)
#define SOC_GIC600_GICR4_CTLR_DPG0_START (24)
#define SOC_GIC600_GICR4_CTLR_DPG0_END (24)
#define SOC_GIC600_GICR4_CTLR_DPG1NS_START (25)
#define SOC_GIC600_GICR4_CTLR_DPG1NS_END (25)
#define SOC_GIC600_GICR4_CTLR_DPG1S_START (26)
#define SOC_GIC600_GICR4_CTLR_DPG1S_END (26)
#define SOC_GIC600_GICR4_CTLR_uwp_START (31)
#define SOC_GIC600_GICR4_CTLR_uwp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Implementer : 12;
        unsigned int Revision : 4;
        unsigned int Variant : 4;
        unsigned int reserved : 4;
        unsigned int ProductID : 8;
    } reg;
} SOC_GIC600_GICR4_IIDR_UNION;
#endif
#define SOC_GIC600_GICR4_IIDR_Implementer_START (0)
#define SOC_GIC600_GICR4_IIDR_Implementer_END (11)
#define SOC_GIC600_GICR4_IIDR_Revision_START (12)
#define SOC_GIC600_GICR4_IIDR_Revision_END (15)
#define SOC_GIC600_GICR4_IIDR_Variant_START (16)
#define SOC_GIC600_GICR4_IIDR_Variant_END (19)
#define SOC_GIC600_GICR4_IIDR_ProductID_START (24)
#define SOC_GIC600_GICR4_IIDR_ProductID_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Sleep : 1;
        unsigned int ProcessorSleep : 1;
        unsigned int ChildrenAsleep : 1;
        unsigned int reserved : 28;
        unsigned int Quiescent : 1;
    } reg;
} SOC_GIC600_GICR4_WAKER_UNION;
#endif
#define SOC_GIC600_GICR4_WAKER_Sleep_START (0)
#define SOC_GIC600_GICR4_WAKER_Sleep_END (0)
#define SOC_GIC600_GICR4_WAKER_ProcessorSleep_START (1)
#define SOC_GIC600_GICR4_WAKER_ProcessorSleep_END (1)
#define SOC_GIC600_GICR4_WAKER_ChildrenAsleep_START (2)
#define SOC_GIC600_GICR4_WAKER_ChildrenAsleep_END (2)
#define SOC_GIC600_GICR4_WAKER_Quiescent_START (31)
#define SOC_GIC600_GICR4_WAKER_Quiescent_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int RDPD : 1;
        unsigned int RDAG : 1;
        unsigned int RDGPD : 1;
        unsigned int RDGPO : 1;
        unsigned int reserved_0: 4;
        unsigned int RDGO : 8;
        unsigned int RDG : 8;
        unsigned int reserved_1: 8;
    } reg;
} SOC_GIC600_GICR4_PWRR_UNION;
#endif
#define SOC_GIC600_GICR4_PWRR_RDPD_START (0)
#define SOC_GIC600_GICR4_PWRR_RDPD_END (0)
#define SOC_GIC600_GICR4_PWRR_RDAG_START (1)
#define SOC_GIC600_GICR4_PWRR_RDAG_END (1)
#define SOC_GIC600_GICR4_PWRR_RDGPD_START (2)
#define SOC_GIC600_GICR4_PWRR_RDGPD_END (2)
#define SOC_GIC600_GICR4_PWRR_RDGPO_START (3)
#define SOC_GIC600_GICR4_PWRR_RDGPO_END (3)
#define SOC_GIC600_GICR4_PWRR_RDGO_START (8)
#define SOC_GIC600_GICR4_PWRR_RDGO_END (15)
#define SOC_GIC600_GICR4_PWRR_RDG_START (16)
#define SOC_GIC600_GICR4_PWRR_RDG_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Redistributor_group_status_bit : 32;
    } reg;
} SOC_GIC600_GICR4_IGROUPR0_UNION;
#endif
#define SOC_GIC600_GICR4_IGROUPR0_Redistributor_group_status_bit_START (0)
#define SOC_GIC600_GICR4_IGROUPR0_Redistributor_group_status_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Set_enable_bit : 32;
    } reg;
} SOC_GIC600_GICR4_ISENABLER0_UNION;
#endif
#define SOC_GIC600_GICR4_ISENABLER0_Set_enable_bit_START (0)
#define SOC_GIC600_GICR4_ISENABLER0_Set_enable_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Clear_enable_bit : 32;
    } reg;
} SOC_GIC600_GICR4_ICENABLER0_UNION;
#endif
#define SOC_GIC600_GICR4_ICENABLER0_Clear_enable_bit_START (0)
#define SOC_GIC600_GICR4_ICENABLER0_Clear_enable_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Set_pending_bit : 32;
    } reg;
} SOC_GIC600_GICR4_ISPENDR0_UNION;
#endif
#define SOC_GIC600_GICR4_ISPENDR0_Set_pending_bit_START (0)
#define SOC_GIC600_GICR4_ISPENDR0_Set_pending_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Clear_pending_bit : 32;
    } reg;
} SOC_GIC600_GICR4_ICPENDR0_UNION;
#endif
#define SOC_GIC600_GICR4_ICPENDR0_Clear_pending_bit_START (0)
#define SOC_GIC600_GICR4_ICPENDR0_Clear_pending_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Set_active_bit : 32;
    } reg;
} SOC_GIC600_GICR4_ISACTIVER0_UNION;
#endif
#define SOC_GIC600_GICR4_ISACTIVER0_Set_active_bit_START (0)
#define SOC_GIC600_GICR4_ISACTIVER0_Set_active_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Clear_active_bit : 32;
    } reg;
} SOC_GIC600_GICR4_ICACTIVER0_UNION;
#endif
#define SOC_GIC600_GICR4_ICACTIVER0_Clear_active_bit_START (0)
#define SOC_GIC600_GICR4_ICACTIVER0_Clear_active_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Priority_offset_0B : 8;
        unsigned int Priority_offset_1B : 8;
        unsigned int Priority_offset_2B : 8;
        unsigned int Priority_offset_3B : 8;
    } reg;
} SOC_GIC600_GICR4_IPRIORITYRn_UNION;
#endif
#define SOC_GIC600_GICR4_IPRIORITYRn_Priority_offset_0B_START (0)
#define SOC_GIC600_GICR4_IPRIORITYRn_Priority_offset_0B_END (7)
#define SOC_GIC600_GICR4_IPRIORITYRn_Priority_offset_1B_START (8)
#define SOC_GIC600_GICR4_IPRIORITYRn_Priority_offset_1B_END (15)
#define SOC_GIC600_GICR4_IPRIORITYRn_Priority_offset_2B_START (16)
#define SOC_GIC600_GICR4_IPRIORITYRn_Priority_offset_2B_END (23)
#define SOC_GIC600_GICR4_IPRIORITYRn_Priority_offset_3B_START (24)
#define SOC_GIC600_GICR4_IPRIORITYRn_Priority_offset_3B_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Int_config : 32;
    } reg;
} SOC_GIC600_GICR4_ICFGR0_UNION;
#endif
#define SOC_GIC600_GICR4_ICFGR0_Int_config_START (0)
#define SOC_GIC600_GICR4_ICFGR0_Int_config_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Int_config : 32;
    } reg;
} SOC_GIC600_GICR4_ICFGR1_UNION;
#endif
#define SOC_GIC600_GICR4_ICFGR1_Int_config_START (0)
#define SOC_GIC600_GICR4_ICFGR1_Int_config_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Group_modifier_bit : 32;
    } reg;
} SOC_GIC600_GICR4_IGRPMODR0_UNION;
#endif
#define SOC_GIC600_GICR4_IGRPMODR0_Group_modifier_bit_START (0)
#define SOC_GIC600_GICR4_IGRPMODR0_Group_modifier_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int NS_access : 32;
    } reg;
} SOC_GIC600_GICR4_NSACR_UNION;
#endif
#define SOC_GIC600_GICR4_NSACR_NS_access_START (0)
#define SOC_GIC600_GICR4_NSACR_NS_access_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int EnableGrp0 : 1;
        unsigned int EnableGrp1NSecure : 1;
        unsigned int EnableGrp1Secure : 1;
        unsigned int reserved_0 : 1;
        unsigned int AccessType : 1;
        unsigned int reserved_1 : 25;
        unsigned int wake_request : 1;
        unsigned int cpu_active : 1;
    } reg;
} SOC_GIC600_GICR4_MISCSTATUSR_UNION;
#endif
#define SOC_GIC600_GICR4_MISCSTATUSR_EnableGrp0_START (0)
#define SOC_GIC600_GICR4_MISCSTATUSR_EnableGrp0_END (0)
#define SOC_GIC600_GICR4_MISCSTATUSR_EnableGrp1NSecure_START (1)
#define SOC_GIC600_GICR4_MISCSTATUSR_EnableGrp1NSecure_END (1)
#define SOC_GIC600_GICR4_MISCSTATUSR_EnableGrp1Secure_START (2)
#define SOC_GIC600_GICR4_MISCSTATUSR_EnableGrp1Secure_END (2)
#define SOC_GIC600_GICR4_MISCSTATUSR_AccessType_START (4)
#define SOC_GIC600_GICR4_MISCSTATUSR_AccessType_END (4)
#define SOC_GIC600_GICR4_MISCSTATUSR_wake_request_START (30)
#define SOC_GIC600_GICR4_MISCSTATUSR_wake_request_END (30)
#define SOC_GIC600_GICR4_MISCSTATUSR_cpu_active_START (31)
#define SOC_GIC600_GICR4_MISCSTATUSR_cpu_active_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Enable_LPIs : 1;
        unsigned int reserved_0 : 2;
        unsigned int RWP : 1;
        unsigned int reserved_1 : 20;
        unsigned int DPG0 : 1;
        unsigned int DPG1NS : 1;
        unsigned int DPG1S : 1;
        unsigned int reserved_2 : 4;
        unsigned int uwp : 1;
    } reg;
} SOC_GIC600_GICR5_CTLR_UNION;
#endif
#define SOC_GIC600_GICR5_CTLR_Enable_LPIs_START (0)
#define SOC_GIC600_GICR5_CTLR_Enable_LPIs_END (0)
#define SOC_GIC600_GICR5_CTLR_RWP_START (3)
#define SOC_GIC600_GICR5_CTLR_RWP_END (3)
#define SOC_GIC600_GICR5_CTLR_DPG0_START (24)
#define SOC_GIC600_GICR5_CTLR_DPG0_END (24)
#define SOC_GIC600_GICR5_CTLR_DPG1NS_START (25)
#define SOC_GIC600_GICR5_CTLR_DPG1NS_END (25)
#define SOC_GIC600_GICR5_CTLR_DPG1S_START (26)
#define SOC_GIC600_GICR5_CTLR_DPG1S_END (26)
#define SOC_GIC600_GICR5_CTLR_uwp_START (31)
#define SOC_GIC600_GICR5_CTLR_uwp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Implementer : 12;
        unsigned int Revision : 4;
        unsigned int Variant : 4;
        unsigned int reserved : 4;
        unsigned int ProductID : 8;
    } reg;
} SOC_GIC600_GICR5_IIDR_UNION;
#endif
#define SOC_GIC600_GICR5_IIDR_Implementer_START (0)
#define SOC_GIC600_GICR5_IIDR_Implementer_END (11)
#define SOC_GIC600_GICR5_IIDR_Revision_START (12)
#define SOC_GIC600_GICR5_IIDR_Revision_END (15)
#define SOC_GIC600_GICR5_IIDR_Variant_START (16)
#define SOC_GIC600_GICR5_IIDR_Variant_END (19)
#define SOC_GIC600_GICR5_IIDR_ProductID_START (24)
#define SOC_GIC600_GICR5_IIDR_ProductID_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Sleep : 1;
        unsigned int ProcessorSleep : 1;
        unsigned int ChildrenAsleep : 1;
        unsigned int reserved : 28;
        unsigned int Quiescent : 1;
    } reg;
} SOC_GIC600_GICR5_WAKER_UNION;
#endif
#define SOC_GIC600_GICR5_WAKER_Sleep_START (0)
#define SOC_GIC600_GICR5_WAKER_Sleep_END (0)
#define SOC_GIC600_GICR5_WAKER_ProcessorSleep_START (1)
#define SOC_GIC600_GICR5_WAKER_ProcessorSleep_END (1)
#define SOC_GIC600_GICR5_WAKER_ChildrenAsleep_START (2)
#define SOC_GIC600_GICR5_WAKER_ChildrenAsleep_END (2)
#define SOC_GIC600_GICR5_WAKER_Quiescent_START (31)
#define SOC_GIC600_GICR5_WAKER_Quiescent_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int RDPD : 1;
        unsigned int RDAG : 1;
        unsigned int RDGPD : 1;
        unsigned int RDGPO : 1;
        unsigned int reserved_0: 4;
        unsigned int RDGO : 8;
        unsigned int RDG : 8;
        unsigned int reserved_1: 8;
    } reg;
} SOC_GIC600_GICR5_PWRR_UNION;
#endif
#define SOC_GIC600_GICR5_PWRR_RDPD_START (0)
#define SOC_GIC600_GICR5_PWRR_RDPD_END (0)
#define SOC_GIC600_GICR5_PWRR_RDAG_START (1)
#define SOC_GIC600_GICR5_PWRR_RDAG_END (1)
#define SOC_GIC600_GICR5_PWRR_RDGPD_START (2)
#define SOC_GIC600_GICR5_PWRR_RDGPD_END (2)
#define SOC_GIC600_GICR5_PWRR_RDGPO_START (3)
#define SOC_GIC600_GICR5_PWRR_RDGPO_END (3)
#define SOC_GIC600_GICR5_PWRR_RDGO_START (8)
#define SOC_GIC600_GICR5_PWRR_RDGO_END (15)
#define SOC_GIC600_GICR5_PWRR_RDG_START (16)
#define SOC_GIC600_GICR5_PWRR_RDG_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Redistributor_group_status_bit : 32;
    } reg;
} SOC_GIC600_GICR5_IGROUPR0_UNION;
#endif
#define SOC_GIC600_GICR5_IGROUPR0_Redistributor_group_status_bit_START (0)
#define SOC_GIC600_GICR5_IGROUPR0_Redistributor_group_status_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Set_enable_bit : 32;
    } reg;
} SOC_GIC600_GICR5_ISENABLER0_UNION;
#endif
#define SOC_GIC600_GICR5_ISENABLER0_Set_enable_bit_START (0)
#define SOC_GIC600_GICR5_ISENABLER0_Set_enable_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Clear_enable_bit : 32;
    } reg;
} SOC_GIC600_GICR5_ICENABLER0_UNION;
#endif
#define SOC_GIC600_GICR5_ICENABLER0_Clear_enable_bit_START (0)
#define SOC_GIC600_GICR5_ICENABLER0_Clear_enable_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Set_pending_bit : 32;
    } reg;
} SOC_GIC600_GICR5_ISPENDR0_UNION;
#endif
#define SOC_GIC600_GICR5_ISPENDR0_Set_pending_bit_START (0)
#define SOC_GIC600_GICR5_ISPENDR0_Set_pending_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Clear_pending_bit : 32;
    } reg;
} SOC_GIC600_GICR5_ICPENDR0_UNION;
#endif
#define SOC_GIC600_GICR5_ICPENDR0_Clear_pending_bit_START (0)
#define SOC_GIC600_GICR5_ICPENDR0_Clear_pending_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Set_active_bit : 32;
    } reg;
} SOC_GIC600_GICR5_ISACTIVER0_UNION;
#endif
#define SOC_GIC600_GICR5_ISACTIVER0_Set_active_bit_START (0)
#define SOC_GIC600_GICR5_ISACTIVER0_Set_active_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Clear_active_bit : 32;
    } reg;
} SOC_GIC600_GICR5_ICACTIVER0_UNION;
#endif
#define SOC_GIC600_GICR5_ICACTIVER0_Clear_active_bit_START (0)
#define SOC_GIC600_GICR5_ICACTIVER0_Clear_active_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Priority_offset_0B : 8;
        unsigned int Priority_offset_1B : 8;
        unsigned int Priority_offset_2B : 8;
        unsigned int Priority_offset_3B : 8;
    } reg;
} SOC_GIC600_GICR5_IPRIORITYRn_UNION;
#endif
#define SOC_GIC600_GICR5_IPRIORITYRn_Priority_offset_0B_START (0)
#define SOC_GIC600_GICR5_IPRIORITYRn_Priority_offset_0B_END (7)
#define SOC_GIC600_GICR5_IPRIORITYRn_Priority_offset_1B_START (8)
#define SOC_GIC600_GICR5_IPRIORITYRn_Priority_offset_1B_END (15)
#define SOC_GIC600_GICR5_IPRIORITYRn_Priority_offset_2B_START (16)
#define SOC_GIC600_GICR5_IPRIORITYRn_Priority_offset_2B_END (23)
#define SOC_GIC600_GICR5_IPRIORITYRn_Priority_offset_3B_START (24)
#define SOC_GIC600_GICR5_IPRIORITYRn_Priority_offset_3B_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Int_config : 32;
    } reg;
} SOC_GIC600_GICR5_ICFGR0_UNION;
#endif
#define SOC_GIC600_GICR5_ICFGR0_Int_config_START (0)
#define SOC_GIC600_GICR5_ICFGR0_Int_config_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Int_config : 32;
    } reg;
} SOC_GIC600_GICR5_ICFGR1_UNION;
#endif
#define SOC_GIC600_GICR5_ICFGR1_Int_config_START (0)
#define SOC_GIC600_GICR5_ICFGR1_Int_config_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Group_modifier_bit : 32;
    } reg;
} SOC_GIC600_GICR5_IGRPMODR0_UNION;
#endif
#define SOC_GIC600_GICR5_IGRPMODR0_Group_modifier_bit_START (0)
#define SOC_GIC600_GICR5_IGRPMODR0_Group_modifier_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int NS_access : 32;
    } reg;
} SOC_GIC600_GICR5_NSACR_UNION;
#endif
#define SOC_GIC600_GICR5_NSACR_NS_access_START (0)
#define SOC_GIC600_GICR5_NSACR_NS_access_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int EnableGrp0 : 1;
        unsigned int EnableGrp1NSecure : 1;
        unsigned int EnableGrp1Secure : 1;
        unsigned int reserved_0 : 1;
        unsigned int AccessType : 1;
        unsigned int reserved_1 : 25;
        unsigned int wake_request : 1;
        unsigned int cpu_active : 1;
    } reg;
} SOC_GIC600_GICR5_MISCSTATUSR_UNION;
#endif
#define SOC_GIC600_GICR5_MISCSTATUSR_EnableGrp0_START (0)
#define SOC_GIC600_GICR5_MISCSTATUSR_EnableGrp0_END (0)
#define SOC_GIC600_GICR5_MISCSTATUSR_EnableGrp1NSecure_START (1)
#define SOC_GIC600_GICR5_MISCSTATUSR_EnableGrp1NSecure_END (1)
#define SOC_GIC600_GICR5_MISCSTATUSR_EnableGrp1Secure_START (2)
#define SOC_GIC600_GICR5_MISCSTATUSR_EnableGrp1Secure_END (2)
#define SOC_GIC600_GICR5_MISCSTATUSR_AccessType_START (4)
#define SOC_GIC600_GICR5_MISCSTATUSR_AccessType_END (4)
#define SOC_GIC600_GICR5_MISCSTATUSR_wake_request_START (30)
#define SOC_GIC600_GICR5_MISCSTATUSR_wake_request_END (30)
#define SOC_GIC600_GICR5_MISCSTATUSR_cpu_active_START (31)
#define SOC_GIC600_GICR5_MISCSTATUSR_cpu_active_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Enable_LPIs : 1;
        unsigned int reserved_0 : 2;
        unsigned int RWP : 1;
        unsigned int reserved_1 : 20;
        unsigned int DPG0 : 1;
        unsigned int DPG1NS : 1;
        unsigned int DPG1S : 1;
        unsigned int reserved_2 : 4;
        unsigned int uwp : 1;
    } reg;
} SOC_GIC600_GICR6_CTLR_UNION;
#endif
#define SOC_GIC600_GICR6_CTLR_Enable_LPIs_START (0)
#define SOC_GIC600_GICR6_CTLR_Enable_LPIs_END (0)
#define SOC_GIC600_GICR6_CTLR_RWP_START (3)
#define SOC_GIC600_GICR6_CTLR_RWP_END (3)
#define SOC_GIC600_GICR6_CTLR_DPG0_START (24)
#define SOC_GIC600_GICR6_CTLR_DPG0_END (24)
#define SOC_GIC600_GICR6_CTLR_DPG1NS_START (25)
#define SOC_GIC600_GICR6_CTLR_DPG1NS_END (25)
#define SOC_GIC600_GICR6_CTLR_DPG1S_START (26)
#define SOC_GIC600_GICR6_CTLR_DPG1S_END (26)
#define SOC_GIC600_GICR6_CTLR_uwp_START (31)
#define SOC_GIC600_GICR6_CTLR_uwp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Implementer : 12;
        unsigned int Revision : 4;
        unsigned int Variant : 4;
        unsigned int reserved : 4;
        unsigned int ProductID : 8;
    } reg;
} SOC_GIC600_GICR6_IIDR_UNION;
#endif
#define SOC_GIC600_GICR6_IIDR_Implementer_START (0)
#define SOC_GIC600_GICR6_IIDR_Implementer_END (11)
#define SOC_GIC600_GICR6_IIDR_Revision_START (12)
#define SOC_GIC600_GICR6_IIDR_Revision_END (15)
#define SOC_GIC600_GICR6_IIDR_Variant_START (16)
#define SOC_GIC600_GICR6_IIDR_Variant_END (19)
#define SOC_GIC600_GICR6_IIDR_ProductID_START (24)
#define SOC_GIC600_GICR6_IIDR_ProductID_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Sleep : 1;
        unsigned int ProcessorSleep : 1;
        unsigned int ChildrenAsleep : 1;
        unsigned int reserved : 28;
        unsigned int Quiescent : 1;
    } reg;
} SOC_GIC600_GICR6_WAKER_UNION;
#endif
#define SOC_GIC600_GICR6_WAKER_Sleep_START (0)
#define SOC_GIC600_GICR6_WAKER_Sleep_END (0)
#define SOC_GIC600_GICR6_WAKER_ProcessorSleep_START (1)
#define SOC_GIC600_GICR6_WAKER_ProcessorSleep_END (1)
#define SOC_GIC600_GICR6_WAKER_ChildrenAsleep_START (2)
#define SOC_GIC600_GICR6_WAKER_ChildrenAsleep_END (2)
#define SOC_GIC600_GICR6_WAKER_Quiescent_START (31)
#define SOC_GIC600_GICR6_WAKER_Quiescent_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int RDPD : 1;
        unsigned int RDAG : 1;
        unsigned int RDGPD : 1;
        unsigned int RDGPO : 1;
        unsigned int reserved_0: 4;
        unsigned int RDGO : 8;
        unsigned int RDG : 8;
        unsigned int reserved_1: 8;
    } reg;
} SOC_GIC600_GICR6_PWRR_UNION;
#endif
#define SOC_GIC600_GICR6_PWRR_RDPD_START (0)
#define SOC_GIC600_GICR6_PWRR_RDPD_END (0)
#define SOC_GIC600_GICR6_PWRR_RDAG_START (1)
#define SOC_GIC600_GICR6_PWRR_RDAG_END (1)
#define SOC_GIC600_GICR6_PWRR_RDGPD_START (2)
#define SOC_GIC600_GICR6_PWRR_RDGPD_END (2)
#define SOC_GIC600_GICR6_PWRR_RDGPO_START (3)
#define SOC_GIC600_GICR6_PWRR_RDGPO_END (3)
#define SOC_GIC600_GICR6_PWRR_RDGO_START (8)
#define SOC_GIC600_GICR6_PWRR_RDGO_END (15)
#define SOC_GIC600_GICR6_PWRR_RDG_START (16)
#define SOC_GIC600_GICR6_PWRR_RDG_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Redistributor_group_status_bit : 32;
    } reg;
} SOC_GIC600_GICR6_IGROUPR0_UNION;
#endif
#define SOC_GIC600_GICR6_IGROUPR0_Redistributor_group_status_bit_START (0)
#define SOC_GIC600_GICR6_IGROUPR0_Redistributor_group_status_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Set_enable_bit : 32;
    } reg;
} SOC_GIC600_GICR6_ISENABLER0_UNION;
#endif
#define SOC_GIC600_GICR6_ISENABLER0_Set_enable_bit_START (0)
#define SOC_GIC600_GICR6_ISENABLER0_Set_enable_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Clear_enable_bit : 32;
    } reg;
} SOC_GIC600_GICR6_ICENABLER0_UNION;
#endif
#define SOC_GIC600_GICR6_ICENABLER0_Clear_enable_bit_START (0)
#define SOC_GIC600_GICR6_ICENABLER0_Clear_enable_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Set_pending_bit : 32;
    } reg;
} SOC_GIC600_GICR6_ISPENDR0_UNION;
#endif
#define SOC_GIC600_GICR6_ISPENDR0_Set_pending_bit_START (0)
#define SOC_GIC600_GICR6_ISPENDR0_Set_pending_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Clear_pending_bit : 32;
    } reg;
} SOC_GIC600_GICR6_ICPENDR0_UNION;
#endif
#define SOC_GIC600_GICR6_ICPENDR0_Clear_pending_bit_START (0)
#define SOC_GIC600_GICR6_ICPENDR0_Clear_pending_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Set_active_bit : 32;
    } reg;
} SOC_GIC600_GICR6_ISACTIVER0_UNION;
#endif
#define SOC_GIC600_GICR6_ISACTIVER0_Set_active_bit_START (0)
#define SOC_GIC600_GICR6_ISACTIVER0_Set_active_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Clear_active_bit : 32;
    } reg;
} SOC_GIC600_GICR6_ICACTIVER0_UNION;
#endif
#define SOC_GIC600_GICR6_ICACTIVER0_Clear_active_bit_START (0)
#define SOC_GIC600_GICR6_ICACTIVER0_Clear_active_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Priority_offset_0B : 8;
        unsigned int Priority_offset_1B : 8;
        unsigned int Priority_offset_2B : 8;
        unsigned int Priority_offset_3B : 8;
    } reg;
} SOC_GIC600_GICR6_IPRIORITYRn_UNION;
#endif
#define SOC_GIC600_GICR6_IPRIORITYRn_Priority_offset_0B_START (0)
#define SOC_GIC600_GICR6_IPRIORITYRn_Priority_offset_0B_END (7)
#define SOC_GIC600_GICR6_IPRIORITYRn_Priority_offset_1B_START (8)
#define SOC_GIC600_GICR6_IPRIORITYRn_Priority_offset_1B_END (15)
#define SOC_GIC600_GICR6_IPRIORITYRn_Priority_offset_2B_START (16)
#define SOC_GIC600_GICR6_IPRIORITYRn_Priority_offset_2B_END (23)
#define SOC_GIC600_GICR6_IPRIORITYRn_Priority_offset_3B_START (24)
#define SOC_GIC600_GICR6_IPRIORITYRn_Priority_offset_3B_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Int_config : 32;
    } reg;
} SOC_GIC600_GICR6_ICFGR0_UNION;
#endif
#define SOC_GIC600_GICR6_ICFGR0_Int_config_START (0)
#define SOC_GIC600_GICR6_ICFGR0_Int_config_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Int_config : 32;
    } reg;
} SOC_GIC600_GICR6_ICFGR1_UNION;
#endif
#define SOC_GIC600_GICR6_ICFGR1_Int_config_START (0)
#define SOC_GIC600_GICR6_ICFGR1_Int_config_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Group_modifier_bit : 32;
    } reg;
} SOC_GIC600_GICR6_IGRPMODR0_UNION;
#endif
#define SOC_GIC600_GICR6_IGRPMODR0_Group_modifier_bit_START (0)
#define SOC_GIC600_GICR6_IGRPMODR0_Group_modifier_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int NS_access : 32;
    } reg;
} SOC_GIC600_GICR6_NSACR_UNION;
#endif
#define SOC_GIC600_GICR6_NSACR_NS_access_START (0)
#define SOC_GIC600_GICR6_NSACR_NS_access_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int EnableGrp0 : 1;
        unsigned int EnableGrp1NSecure : 1;
        unsigned int EnableGrp1Secure : 1;
        unsigned int reserved_0 : 1;
        unsigned int AccessType : 1;
        unsigned int reserved_1 : 25;
        unsigned int wake_request : 1;
        unsigned int cpu_active : 1;
    } reg;
} SOC_GIC600_GICR6_MISCSTATUSR_UNION;
#endif
#define SOC_GIC600_GICR6_MISCSTATUSR_EnableGrp0_START (0)
#define SOC_GIC600_GICR6_MISCSTATUSR_EnableGrp0_END (0)
#define SOC_GIC600_GICR6_MISCSTATUSR_EnableGrp1NSecure_START (1)
#define SOC_GIC600_GICR6_MISCSTATUSR_EnableGrp1NSecure_END (1)
#define SOC_GIC600_GICR6_MISCSTATUSR_EnableGrp1Secure_START (2)
#define SOC_GIC600_GICR6_MISCSTATUSR_EnableGrp1Secure_END (2)
#define SOC_GIC600_GICR6_MISCSTATUSR_AccessType_START (4)
#define SOC_GIC600_GICR6_MISCSTATUSR_AccessType_END (4)
#define SOC_GIC600_GICR6_MISCSTATUSR_wake_request_START (30)
#define SOC_GIC600_GICR6_MISCSTATUSR_wake_request_END (30)
#define SOC_GIC600_GICR6_MISCSTATUSR_cpu_active_START (31)
#define SOC_GIC600_GICR6_MISCSTATUSR_cpu_active_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Enable_LPIs : 1;
        unsigned int reserved_0 : 2;
        unsigned int RWP : 1;
        unsigned int reserved_1 : 20;
        unsigned int DPG0 : 1;
        unsigned int DPG1NS : 1;
        unsigned int DPG1S : 1;
        unsigned int reserved_2 : 4;
        unsigned int uwp : 1;
    } reg;
} SOC_GIC600_GICR7_CTLR_UNION;
#endif
#define SOC_GIC600_GICR7_CTLR_Enable_LPIs_START (0)
#define SOC_GIC600_GICR7_CTLR_Enable_LPIs_END (0)
#define SOC_GIC600_GICR7_CTLR_RWP_START (3)
#define SOC_GIC600_GICR7_CTLR_RWP_END (3)
#define SOC_GIC600_GICR7_CTLR_DPG0_START (24)
#define SOC_GIC600_GICR7_CTLR_DPG0_END (24)
#define SOC_GIC600_GICR7_CTLR_DPG1NS_START (25)
#define SOC_GIC600_GICR7_CTLR_DPG1NS_END (25)
#define SOC_GIC600_GICR7_CTLR_DPG1S_START (26)
#define SOC_GIC600_GICR7_CTLR_DPG1S_END (26)
#define SOC_GIC600_GICR7_CTLR_uwp_START (31)
#define SOC_GIC600_GICR7_CTLR_uwp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Implementer : 12;
        unsigned int Revision : 4;
        unsigned int Variant : 4;
        unsigned int reserved : 4;
        unsigned int ProductID : 8;
    } reg;
} SOC_GIC600_GICR7_IIDR_UNION;
#endif
#define SOC_GIC600_GICR7_IIDR_Implementer_START (0)
#define SOC_GIC600_GICR7_IIDR_Implementer_END (11)
#define SOC_GIC600_GICR7_IIDR_Revision_START (12)
#define SOC_GIC600_GICR7_IIDR_Revision_END (15)
#define SOC_GIC600_GICR7_IIDR_Variant_START (16)
#define SOC_GIC600_GICR7_IIDR_Variant_END (19)
#define SOC_GIC600_GICR7_IIDR_ProductID_START (24)
#define SOC_GIC600_GICR7_IIDR_ProductID_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Sleep : 1;
        unsigned int ProcessorSleep : 1;
        unsigned int ChildrenAsleep : 1;
        unsigned int reserved : 28;
        unsigned int Quiescent : 1;
    } reg;
} SOC_GIC600_GICR7_WAKER_UNION;
#endif
#define SOC_GIC600_GICR7_WAKER_Sleep_START (0)
#define SOC_GIC600_GICR7_WAKER_Sleep_END (0)
#define SOC_GIC600_GICR7_WAKER_ProcessorSleep_START (1)
#define SOC_GIC600_GICR7_WAKER_ProcessorSleep_END (1)
#define SOC_GIC600_GICR7_WAKER_ChildrenAsleep_START (2)
#define SOC_GIC600_GICR7_WAKER_ChildrenAsleep_END (2)
#define SOC_GIC600_GICR7_WAKER_Quiescent_START (31)
#define SOC_GIC600_GICR7_WAKER_Quiescent_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int RDPD : 1;
        unsigned int RDAG : 1;
        unsigned int RDGPD : 1;
        unsigned int RDGPO : 1;
        unsigned int reserved_0: 4;
        unsigned int RDGO : 8;
        unsigned int RDG : 8;
        unsigned int reserved_1: 8;
    } reg;
} SOC_GIC600_GICR7_PWRR_UNION;
#endif
#define SOC_GIC600_GICR7_PWRR_RDPD_START (0)
#define SOC_GIC600_GICR7_PWRR_RDPD_END (0)
#define SOC_GIC600_GICR7_PWRR_RDAG_START (1)
#define SOC_GIC600_GICR7_PWRR_RDAG_END (1)
#define SOC_GIC600_GICR7_PWRR_RDGPD_START (2)
#define SOC_GIC600_GICR7_PWRR_RDGPD_END (2)
#define SOC_GIC600_GICR7_PWRR_RDGPO_START (3)
#define SOC_GIC600_GICR7_PWRR_RDGPO_END (3)
#define SOC_GIC600_GICR7_PWRR_RDGO_START (8)
#define SOC_GIC600_GICR7_PWRR_RDGO_END (15)
#define SOC_GIC600_GICR7_PWRR_RDG_START (16)
#define SOC_GIC600_GICR7_PWRR_RDG_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Redistributor_group_status_bit : 32;
    } reg;
} SOC_GIC600_GICR7_IGROUPR0_UNION;
#endif
#define SOC_GIC600_GICR7_IGROUPR0_Redistributor_group_status_bit_START (0)
#define SOC_GIC600_GICR7_IGROUPR0_Redistributor_group_status_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Set_enable_bit : 32;
    } reg;
} SOC_GIC600_GICR7_ISENABLER0_UNION;
#endif
#define SOC_GIC600_GICR7_ISENABLER0_Set_enable_bit_START (0)
#define SOC_GIC600_GICR7_ISENABLER0_Set_enable_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Clear_enable_bit : 32;
    } reg;
} SOC_GIC600_GICR7_ICENABLER0_UNION;
#endif
#define SOC_GIC600_GICR7_ICENABLER0_Clear_enable_bit_START (0)
#define SOC_GIC600_GICR7_ICENABLER0_Clear_enable_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Set_pending_bit : 32;
    } reg;
} SOC_GIC600_GICR7_ISPENDR0_UNION;
#endif
#define SOC_GIC600_GICR7_ISPENDR0_Set_pending_bit_START (0)
#define SOC_GIC600_GICR7_ISPENDR0_Set_pending_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Clear_pending_bit : 32;
    } reg;
} SOC_GIC600_GICR7_ICPENDR0_UNION;
#endif
#define SOC_GIC600_GICR7_ICPENDR0_Clear_pending_bit_START (0)
#define SOC_GIC600_GICR7_ICPENDR0_Clear_pending_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Set_active_bit : 32;
    } reg;
} SOC_GIC600_GICR7_ISACTIVER0_UNION;
#endif
#define SOC_GIC600_GICR7_ISACTIVER0_Set_active_bit_START (0)
#define SOC_GIC600_GICR7_ISACTIVER0_Set_active_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Clear_active_bit : 32;
    } reg;
} SOC_GIC600_GICR7_ICACTIVER0_UNION;
#endif
#define SOC_GIC600_GICR7_ICACTIVER0_Clear_active_bit_START (0)
#define SOC_GIC600_GICR7_ICACTIVER0_Clear_active_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Priority_offset_0B : 8;
        unsigned int Priority_offset_1B : 8;
        unsigned int Priority_offset_2B : 8;
        unsigned int Priority_offset_3B : 8;
    } reg;
} SOC_GIC600_GICR7_IPRIORITYRn_UNION;
#endif
#define SOC_GIC600_GICR7_IPRIORITYRn_Priority_offset_0B_START (0)
#define SOC_GIC600_GICR7_IPRIORITYRn_Priority_offset_0B_END (7)
#define SOC_GIC600_GICR7_IPRIORITYRn_Priority_offset_1B_START (8)
#define SOC_GIC600_GICR7_IPRIORITYRn_Priority_offset_1B_END (15)
#define SOC_GIC600_GICR7_IPRIORITYRn_Priority_offset_2B_START (16)
#define SOC_GIC600_GICR7_IPRIORITYRn_Priority_offset_2B_END (23)
#define SOC_GIC600_GICR7_IPRIORITYRn_Priority_offset_3B_START (24)
#define SOC_GIC600_GICR7_IPRIORITYRn_Priority_offset_3B_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Int_config : 32;
    } reg;
} SOC_GIC600_GICR7_ICFGR0_UNION;
#endif
#define SOC_GIC600_GICR7_ICFGR0_Int_config_START (0)
#define SOC_GIC600_GICR7_ICFGR0_Int_config_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Int_config : 32;
    } reg;
} SOC_GIC600_GICR7_ICFGR1_UNION;
#endif
#define SOC_GIC600_GICR7_ICFGR1_Int_config_START (0)
#define SOC_GIC600_GICR7_ICFGR1_Int_config_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Group_modifier_bit : 32;
    } reg;
} SOC_GIC600_GICR7_IGRPMODR0_UNION;
#endif
#define SOC_GIC600_GICR7_IGRPMODR0_Group_modifier_bit_START (0)
#define SOC_GIC600_GICR7_IGRPMODR0_Group_modifier_bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int NS_access : 32;
    } reg;
} SOC_GIC600_GICR7_NSACR_UNION;
#endif
#define SOC_GIC600_GICR7_NSACR_NS_access_START (0)
#define SOC_GIC600_GICR7_NSACR_NS_access_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int EnableGrp0 : 1;
        unsigned int EnableGrp1NSecure : 1;
        unsigned int EnableGrp1Secure : 1;
        unsigned int reserved_0 : 1;
        unsigned int AccessType : 1;
        unsigned int reserved_1 : 25;
        unsigned int wake_request : 1;
        unsigned int cpu_active : 1;
    } reg;
} SOC_GIC600_GICR7_MISCSTATUSR_UNION;
#endif
#define SOC_GIC600_GICR7_MISCSTATUSR_EnableGrp0_START (0)
#define SOC_GIC600_GICR7_MISCSTATUSR_EnableGrp0_END (0)
#define SOC_GIC600_GICR7_MISCSTATUSR_EnableGrp1NSecure_START (1)
#define SOC_GIC600_GICR7_MISCSTATUSR_EnableGrp1NSecure_END (1)
#define SOC_GIC600_GICR7_MISCSTATUSR_EnableGrp1Secure_START (2)
#define SOC_GIC600_GICR7_MISCSTATUSR_EnableGrp1Secure_END (2)
#define SOC_GIC600_GICR7_MISCSTATUSR_AccessType_START (4)
#define SOC_GIC600_GICR7_MISCSTATUSR_AccessType_END (4)
#define SOC_GIC600_GICR7_MISCSTATUSR_wake_request_START (30)
#define SOC_GIC600_GICR7_MISCSTATUSR_wake_request_END (30)
#define SOC_GIC600_GICR7_MISCSTATUSR_cpu_active_START (31)
#define SOC_GIC600_GICR7_MISCSTATUSR_cpu_active_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
