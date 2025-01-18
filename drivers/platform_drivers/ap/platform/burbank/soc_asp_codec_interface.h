#ifndef __SOC_ASP_CODEC_INTERFACE_H__
#define __SOC_ASP_CODEC_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_ASP_CODEC_VERSION_ADDR(base) ((base) + (0x0000UL))
#define SOC_ASP_CODEC_CODEC_CLK_EN0_ADDR(base) ((base) + (0x0004UL))
#define SOC_ASP_CODEC_CODEC_CLK_EN1_ADDR(base) ((base) + (0x0008UL))
#define SOC_ASP_CODEC_I2S1_CTRL_ADDR(base) ((base) + (0x000CUL))
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_ADDR(base) ((base) + (0x0010UL))
#define SOC_ASP_CODEC_I2S1_TDM_CTRL1_ADDR(base) ((base) + (0x0014UL))
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_ADDR(base) ((base) + (0x0018UL))
#define SOC_ASP_CODEC_PGA_THRE_CTRL0_ADDR(base) ((base) + (0x001CUL))
#define SOC_ASP_CODEC_PGA_THRE_CTRL1_ADDR(base) ((base) + (0x0020UL))
#define SOC_ASP_CODEC_PGA_THRE_CTRL2_ADDR(base) ((base) + (0x0024UL))
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL0_ADDR(base) ((base) + (0x0028UL))
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL1_ADDR(base) ((base) + (0x002CUL))
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL2_ADDR(base) ((base) + (0x0030UL))
#define SOC_ASP_CODEC_VOICE_L_DN_PGA_CTRL_ADDR(base) ((base) + (0x0034UL))
#define SOC_ASP_CODEC_AUDIO_L_DN_PGA_CTRL_ADDR(base) ((base) + (0x0038UL))
#define SOC_ASP_CODEC_AUDIO_R_DN_PGA_CTRL_ADDR(base) ((base) + (0x003CUL))
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_ADDR(base) ((base) + (0x0040UL))
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_ADDR(base) ((base) + (0x0044UL))
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_ADDR(base) ((base) + (0x0048UL))
#define SOC_ASP_CODEC_BT_L_RX_PGA_CTRL_ADDR(base) ((base) + (0x004CUL))
#define SOC_ASP_CODEC_BT_R_RX_PGA_CTRL_ADDR(base) ((base) + (0x0050UL))
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_ADDR(base) ((base) + (0x0054UL))
#define SOC_ASP_CODEC_SRCUP_CTRL_ADDR(base) ((base) + (0x0058UL))
#define SOC_ASP_CODEC_SRCDN_CTRL_ADDR(base) ((base) + (0x005CUL))
#define SOC_ASP_CODEC_DACL_MIXER4_CTRL0_ADDR(base) ((base) + (0x0060UL))
#define SOC_ASP_CODEC_DACL_MIXER4_CTRL1_ADDR(base) ((base) + (0x0064UL))
#define SOC_ASP_CODEC_DACR_MIXER4_CTRL0_ADDR(base) ((base) + (0x0068UL))
#define SOC_ASP_CODEC_DACR_MIXER4_CTRL1_ADDR(base) ((base) + (0x006CUL))
#define SOC_ASP_CODEC_BT_TX_MIXER2_CTRL_ADDR(base) ((base) + (0x0070UL))
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_ADDR(base) ((base) + (0x0074UL))
#define SOC_ASP_CODEC_ADC_FILTER_CTRL_ADDR(base) ((base) + (0x0078UL))
#define SOC_ASP_CODEC_AUDIO_DN_AFIFO_CTRL_ADDR(base) ((base) + (0x0080UL))
#define SOC_ASP_CODEC_AUDIO_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x0084UL))
#define SOC_ASP_CODEC_VOICE_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x0088UL))
#define SOC_ASP_CODEC_ECHO_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x008CUL))
#define SOC_ASP_CODEC_VOICE_DN_AFIFO_CTRL_ADDR(base) ((base) + (0x0090UL))
#define SOC_ASP_CODEC_MIC3_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x0094UL))
#define SOC_ASP_CODEC_MEM_CTRL_CFG_ADDR(base) ((base) + (0x0098UL))
#define SOC_ASP_CODEC_CODEC_STAT0_ADDR(base) ((base) + (0x009CUL))
#define SOC_ASP_CODEC_FS_CTRL0_ADDR(base) ((base) + (0x00A4UL))
#define SOC_ASP_CODEC_FS_CTRL1_ADDR(base) ((base) + (0x00A8UL))
#define SOC_ASP_CODEC_CODEC_DIN_MUX_ADDR(base) ((base) + (0x00ACUL))
#define SOC_ASP_CODEC_CODEC_DACL_DC_OFFSET_ADDR(base) ((base) + (0x00B4UL))
#define SOC_ASP_CODEC_CODEC_DACR_DC_OFFSET_ADDR(base) ((base) + (0x00B8UL))
#define SOC_ASP_CODEC_CODEC_ADCL_DC_OFFSET_ADDR(base) ((base) + (0x00BCUL))
#define SOC_ASP_CODEC_CODEC_ADCR_DC_OFFSET_ADDR(base) ((base) + (0x00C0UL))
#define SOC_ASP_CODEC_CODEC_ADC_MIC3_DC_OFFSET_ADDR(base) ((base) + (0x00C4UL))
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_ADDR(base) ((base) + (0x00C8UL))
#define SOC_ASP_CODEC_VOICE_R_DN_PGA_CTRL_ADDR(base) ((base) + (0x00CCUL))
#define SOC_ASP_CODEC_CODEC3_DN_AFIFO_CTRL_ADDR(base) ((base) + (0x00D0UL))
#define SOC_ASP_CODEC_FS_CTRL2_ADDR(base) ((base) + (0x00D4UL))
#define SOC_ASP_CODEC_CODEC_CLK_EN3_ADDR(base) ((base) + (0x00D8UL))
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL3_ADDR(base) ((base) + (0x00DCUL))
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ADDR(base) ((base) + (0x00E0UL))
#define SOC_ASP_CODEC_CODEC3_L_DN_PGA_CTRL_ADDR(base) ((base) + (0x00E4UL))
#define SOC_ASP_CODEC_CODEC3_R_DN_PGA_CTRL_ADDR(base) ((base) + (0x00E8UL))
#define SOC_ASP_CODEC_SRCDN_CTRL1_ADDR(base) ((base) + (0x00ECUL))
#define SOC_ASP_CODEC_ULTR_MIXER2_CTRL_ADDR(base) ((base) + (0x00F0UL))
#define SOC_ASP_CODEC_DACML_MIXER2_CTRL_ADDR(base) ((base) + (0x00F4UL))
#define SOC_ASP_CODEC_DACMR_MIXER2_CTRL_ADDR(base) ((base) + (0x00F8UL))
#define SOC_ASP_CODEC_DACML_FILTER_CTRL_ADDR(base) ((base) + (0x00FCUL))
#define SOC_ASP_CODEC_ADC_ULTR_FILTER_CTRL_ADDR(base) ((base) + (0x0100UL))
#define SOC_ASP_CODEC_DMIC_CTRL_ADDR(base) ((base) + (0x0104UL))
#define SOC_ASP_CODEC_DMIC_DIV_ADDR(base) ((base) + (0x0108UL))
#define SOC_ASP_CODEC_CODEC_DACML_DC_OFFSET_ADDR(base) ((base) + (0x010CUL))
#define SOC_ASP_CODEC_CODEC_ADC_ULTR_DC_OFFSET_ADDR(base) ((base) + (0x0120UL))
#define SOC_ASP_CODEC_SPA12_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x0124UL))
#define SOC_ASP_CODEC_SPA34_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x0128UL))
#define SOC_ASP_CODEC_ULTR_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x012CUL))
#define SOC_ASP_CODEC_ULTR_DN_AFIFO_CTRL_ADDR(base) ((base) + (0x0130UL))
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_ADDR(base) ((base) + (0x0134UL))
#define SOC_ASP_CODEC_FS_CTRL3_ADDR(base) ((base) + (0x0138UL))
#define SOC_ASP_CODEC_MEM_CTRL_S_CFG_ADDR(base) ((base) + (0x013CUL))
#define SOC_ASP_CODEC_I2S_FIFO_CLR_ADDR(base) ((base) + (0x0140UL))
#define SOC_ASP_CODEC_SPAIV_ADC_FILTER_ADDR(base) ((base) + (0x0144UL))
#define SOC_ASP_CODEC_CLASSH_CTRL1_ADDR(base) ((base) + (0x0148UL))
#define SOC_ASP_CODEC_CLASSH_CTRL2_ADDR(base) ((base) + (0x014CUL))
#define SOC_ASP_CODEC_LUT_REG0_3_ADDR(base) ((base) + (0x0150UL))
#define SOC_ASP_CODEC_LUT_REG4_7_ADDR(base) ((base) + (0x0154UL))
#define SOC_ASP_CODEC_LUT_REG8_11_ADDR(base) ((base) + (0x0158UL))
#define SOC_ASP_CODEC_LUT_REG12_15_ADDR(base) ((base) + (0x015CUL))
#define SOC_ASP_CODEC_LUT_REG16_19_ADDR(base) ((base) + (0x0160UL))
#define SOC_ASP_CODEC_LUT_REG20_23_ADDR(base) ((base) + (0x0164UL))
#define SOC_ASP_CODEC_LUT_REG24_27_ADDR(base) ((base) + (0x0168UL))
#define SOC_ASP_CODEC_LUT_REG28_31_ADDR(base) ((base) + (0x016CUL))
#define SOC_ASP_CODEC_LUT_REG32_35_ADDR(base) ((base) + (0x0170UL))
#define SOC_ASP_CODEC_LUT_REG36_39_ADDR(base) ((base) + (0x0174UL))
#define SOC_ASP_CODEC_LUT_REG40_43_ADDR(base) ((base) + (0x0178UL))
#define SOC_ASP_CODEC_LUT_REG44_47_ADDR(base) ((base) + (0x017CUL))
#define SOC_ASP_CODEC_LUT_REG48_51_ADDR(base) ((base) + (0x0180UL))
#define SOC_ASP_CODEC_LUT_REG52_55_ADDR(base) ((base) + (0x0184UL))
#define SOC_ASP_CODEC_LUT_REG56_59_ADDR(base) ((base) + (0x0188UL))
#define SOC_ASP_CODEC_LUT_REG60_63_ADDR(base) ((base) + (0x018CUL))
#define SOC_ASP_CODEC_LUT_REG64_67_ADDR(base) ((base) + (0x0190UL))
#define SOC_ASP_CODEC_CODEC_ADC_SPI_DC_OFFSET_ADDR(base) ((base) + (0x0194UL))
#define SOC_ASP_CODEC_CODEC_ADC_SPA_DC_OFFSET_ADDR(base) ((base) + (0x0198UL))
#define SOC_ASP_CODEC_CODEC_CLK_EN2_ADDR(base) ((base) + (0x019CUL))
#define SOC_ASP_CODEC_MIC4_SRCDN_CTRL1_ADDR(base) ((base) + (0x01A0UL))
#define SOC_ASP_CODEC_MIC4_PGA_ADDR(base) ((base) + (0x1A4UL))
#define SOC_ASP_CODEC_CODEC_DIN_MUX2_ADDR(base) ((base) + (0x01A8UL))
#define SOC_ASP_CODEC_FS_CTRL4_ADDR(base) ((base) + (0x01ACUL))
#define SOC_ASP_CODEC_SPA2_ADC_FILTER_ADDR(base) ((base) + (0x01B0UL))
#define SOC_ASP_CODEC_CODEC_ADC2_SPI_DC_OFFSET_ADDR(base) ((base) + (0x01B4UL))
#define SOC_ASP_CODEC_CODEC_ADC2_SPA_DC_OFFSET_ADDR(base) ((base) + (0x01B8UL))
#define SOC_ASP_CODEC_SPA3_ADC_FILTER_ADDR(base) ((base) + (0x01BCUL))
#define SOC_ASP_CODEC_CODEC_ADC3_SPI_DC_OFFSET_ADDR(base) ((base) + (0x01C0UL))
#define SOC_ASP_CODEC_CODEC_ADC3_SPA_DC_OFFSET_ADDR(base) ((base) + (0x01C4UL))
#define SOC_ASP_CODEC_SPA_SDM_CTRL_ADDR(base) ((base) + (0x01C8UL))
#define SOC_ASP_CODEC_CLASSH2_CTRL1_ADDR(base) ((base) + (0x01CCUL))
#define SOC_ASP_CODEC_CLASSH2_CTRL2_ADDR(base) ((base) + (0x01D0UL))
#define SOC_ASP_CODEC_CLASS2_LUT_REG0_3_ADDR(base) ((base) + (0x01D4UL))
#define SOC_ASP_CODEC_CLASS2_LUT_REG4_7_ADDR(base) ((base) + (0x01D8UL))
#define SOC_ASP_CODEC_CLASS2_LUT_REG8_11_ADDR(base) ((base) + (0x01DCUL))
#define SOC_ASP_CODEC_CLASS2_LUT_REG12_15_ADDR(base) ((base) + (0x01E0UL))
#define SOC_ASP_CODEC_CLASS2_LUT_REG16_19_ADDR(base) ((base) + (0x01E4UL))
#define SOC_ASP_CODEC_CLASS2_LUT_REG20_23_ADDR(base) ((base) + (0x01E8UL))
#define SOC_ASP_CODEC_CLASS2_LUT_REG24_27_ADDR(base) ((base) + (0x01ECUL))
#define SOC_ASP_CODEC_CLASS2_LUT_REG28_31_ADDR(base) ((base) + (0x01F0UL))
#define SOC_ASP_CODEC_CLASS2_LUT_REG32_35_ADDR(base) ((base) + (0x01F4UL))
#define SOC_ASP_CODEC_CLASS2_LUT_REG36_39_ADDR(base) ((base) + (0x01F8UL))
#define SOC_ASP_CODEC_CLASS2_LUT_REG40_43_ADDR(base) ((base) + (0x01FCUL))
#define SOC_ASP_CODEC_CLASS2_LUT_REG44_47_ADDR(base) ((base) + (0x0200UL))
#define SOC_ASP_CODEC_CLASS2_LUT_REG48_51_ADDR(base) ((base) + (0x0204UL))
#define SOC_ASP_CODEC_CLASS2_LUT_REG52_55_ADDR(base) ((base) + (0x0208UL))
#define SOC_ASP_CODEC_CLASS2_LUT_REG56_59_ADDR(base) ((base) + (0x020CUL))
#define SOC_ASP_CODEC_CLASS2_LUT_REG60_63_ADDR(base) ((base) + (0x0210UL))
#define SOC_ASP_CODEC_CLASS2_LUT_REG64_67_ADDR(base) ((base) + (0x021CUL))
#define SOC_ASP_CODEC_CLASSH3_CTRL1_ADDR(base) ((base) + (0x0220UL))
#define SOC_ASP_CODEC_CLASSH3_CTRL2_ADDR(base) ((base) + (0x0224UL))
#define SOC_ASP_CODEC_CLASSH3_LUT_REG0_3_ADDR(base) ((base) + (0x0228UL))
#define SOC_ASP_CODEC_CLASSH3_LUT_REG4_7_ADDR(base) ((base) + (0x022CUL))
#define SOC_ASP_CODEC_CLASSH3_LUT_REG8_11_ADDR(base) ((base) + (0x0230UL))
#define SOC_ASP_CODEC_CLASSH3_LUT_REG12_15_ADDR(base) ((base) + (0x0234UL))
#define SOC_ASP_CODEC_CLASSH3_LUT_REG16_19_ADDR(base) ((base) + (0x0238UL))
#define SOC_ASP_CODEC_CLASSH3_LUT_REG20_23_ADDR(base) ((base) + (0x023CUL))
#define SOC_ASP_CODEC_CLASSH3_LUT_REG24_27_ADDR(base) ((base) + (0x0240UL))
#define SOC_ASP_CODEC_CLASSH3_LUT_REG28_31_ADDR(base) ((base) + (0x0244UL))
#define SOC_ASP_CODEC_CLASSH3_LUT_REG32_35_ADDR(base) ((base) + (0x0248UL))
#define SOC_ASP_CODEC_CLASSH3_LUT_REG36_39_ADDR(base) ((base) + (0x024CUL))
#define SOC_ASP_CODEC_CLASSH3_LUT_REG40_43_ADDR(base) ((base) + (0x0250UL))
#define SOC_ASP_CODEC_CLASSH3_LUT_REG44_47_ADDR(base) ((base) + (0x0254UL))
#define SOC_ASP_CODEC_CLASSH3_LUT_REG48_51_ADDR(base) ((base) + (0x0258UL))
#define SOC_ASP_CODEC_CLASSH3_LUT_REG52_55_ADDR(base) ((base) + (0x025CUL))
#define SOC_ASP_CODEC_CLASSH3_LUT_REG56_59_ADDR(base) ((base) + (0x0260UL))
#define SOC_ASP_CODEC_CLASSH3_LUT_REG60_63_ADDR(base) ((base) + (0x0264UL))
#define SOC_ASP_CODEC_CLASSH3_LUT_REG64_67_ADDR(base) ((base) + (0x0268UL))
#define SOC_ASP_CODEC_MIC4_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x026CUL))
#define SOC_ASP_CODEC_ADC3_SPA_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x0270UL))
#define SOC_ASP_CODEC_ADC2_SPA_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x0274UL))
#define SOC_ASP_CODEC_MIC4_ADC_FILTER_ADDR(base) ((base) + (0x0278UL))
#define SOC_ASP_CODEC_CODEC_MIC4_DC_OFFSET_ADDR(base) ((base) + (0x027CUL))
#define SOC_ASP_CODEC_SPA1_SDM_DC_OFFSET_ADDR(base) ((base) + (0x0280UL))
#define SOC_ASP_CODEC_SPA2_SDM_DC_OFFSET_ADDR(base) ((base) + (0x0284UL))
#define SOC_ASP_CODEC_SPA3_SDM_DC_OFFSET_ADDR(base) ((base) + (0x0288UL))
#define SOC_ASP_CODEC_SIF2_3_CTRL_ADDR(base) ((base) + (0x028CUL))
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_ADDR(base) ((base) + (0x0290UL))
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL1_ADDR(base) ((base) + (0x0294UL))
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_ADDR(base) ((base) + (0x0298UL))
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL1_ADDR(base) ((base) + (0x029CUL))
#else
#define SOC_ASP_CODEC_VERSION_ADDR(base) ((base) + (0x0000))
#define SOC_ASP_CODEC_CODEC_CLK_EN0_ADDR(base) ((base) + (0x0004))
#define SOC_ASP_CODEC_CODEC_CLK_EN1_ADDR(base) ((base) + (0x0008))
#define SOC_ASP_CODEC_I2S1_CTRL_ADDR(base) ((base) + (0x000C))
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_ADDR(base) ((base) + (0x0010))
#define SOC_ASP_CODEC_I2S1_TDM_CTRL1_ADDR(base) ((base) + (0x0014))
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_ADDR(base) ((base) + (0x0018))
#define SOC_ASP_CODEC_PGA_THRE_CTRL0_ADDR(base) ((base) + (0x001C))
#define SOC_ASP_CODEC_PGA_THRE_CTRL1_ADDR(base) ((base) + (0x0020))
#define SOC_ASP_CODEC_PGA_THRE_CTRL2_ADDR(base) ((base) + (0x0024))
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL0_ADDR(base) ((base) + (0x0028))
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL1_ADDR(base) ((base) + (0x002C))
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL2_ADDR(base) ((base) + (0x0030))
#define SOC_ASP_CODEC_VOICE_L_DN_PGA_CTRL_ADDR(base) ((base) + (0x0034))
#define SOC_ASP_CODEC_AUDIO_L_DN_PGA_CTRL_ADDR(base) ((base) + (0x0038))
#define SOC_ASP_CODEC_AUDIO_R_DN_PGA_CTRL_ADDR(base) ((base) + (0x003C))
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_ADDR(base) ((base) + (0x0040))
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_ADDR(base) ((base) + (0x0044))
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_ADDR(base) ((base) + (0x0048))
#define SOC_ASP_CODEC_BT_L_RX_PGA_CTRL_ADDR(base) ((base) + (0x004C))
#define SOC_ASP_CODEC_BT_R_RX_PGA_CTRL_ADDR(base) ((base) + (0x0050))
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_ADDR(base) ((base) + (0x0054))
#define SOC_ASP_CODEC_SRCUP_CTRL_ADDR(base) ((base) + (0x0058))
#define SOC_ASP_CODEC_SRCDN_CTRL_ADDR(base) ((base) + (0x005C))
#define SOC_ASP_CODEC_DACL_MIXER4_CTRL0_ADDR(base) ((base) + (0x0060))
#define SOC_ASP_CODEC_DACL_MIXER4_CTRL1_ADDR(base) ((base) + (0x0064))
#define SOC_ASP_CODEC_DACR_MIXER4_CTRL0_ADDR(base) ((base) + (0x0068))
#define SOC_ASP_CODEC_DACR_MIXER4_CTRL1_ADDR(base) ((base) + (0x006C))
#define SOC_ASP_CODEC_BT_TX_MIXER2_CTRL_ADDR(base) ((base) + (0x0070))
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_ADDR(base) ((base) + (0x0074))
#define SOC_ASP_CODEC_ADC_FILTER_CTRL_ADDR(base) ((base) + (0x0078))
#define SOC_ASP_CODEC_AUDIO_DN_AFIFO_CTRL_ADDR(base) ((base) + (0x0080))
#define SOC_ASP_CODEC_AUDIO_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x0084))
#define SOC_ASP_CODEC_VOICE_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x0088))
#define SOC_ASP_CODEC_ECHO_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x008C))
#define SOC_ASP_CODEC_VOICE_DN_AFIFO_CTRL_ADDR(base) ((base) + (0x0090))
#define SOC_ASP_CODEC_MIC3_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x0094))
#define SOC_ASP_CODEC_MEM_CTRL_CFG_ADDR(base) ((base) + (0x0098))
#define SOC_ASP_CODEC_CODEC_STAT0_ADDR(base) ((base) + (0x009C))
#define SOC_ASP_CODEC_FS_CTRL0_ADDR(base) ((base) + (0x00A4))
#define SOC_ASP_CODEC_FS_CTRL1_ADDR(base) ((base) + (0x00A8))
#define SOC_ASP_CODEC_CODEC_DIN_MUX_ADDR(base) ((base) + (0x00AC))
#define SOC_ASP_CODEC_CODEC_DACL_DC_OFFSET_ADDR(base) ((base) + (0x00B4))
#define SOC_ASP_CODEC_CODEC_DACR_DC_OFFSET_ADDR(base) ((base) + (0x00B8))
#define SOC_ASP_CODEC_CODEC_ADCL_DC_OFFSET_ADDR(base) ((base) + (0x00BC))
#define SOC_ASP_CODEC_CODEC_ADCR_DC_OFFSET_ADDR(base) ((base) + (0x00C0))
#define SOC_ASP_CODEC_CODEC_ADC_MIC3_DC_OFFSET_ADDR(base) ((base) + (0x00C4))
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_ADDR(base) ((base) + (0x00C8))
#define SOC_ASP_CODEC_VOICE_R_DN_PGA_CTRL_ADDR(base) ((base) + (0x00CC))
#define SOC_ASP_CODEC_CODEC3_DN_AFIFO_CTRL_ADDR(base) ((base) + (0x00D0))
#define SOC_ASP_CODEC_FS_CTRL2_ADDR(base) ((base) + (0x00D4))
#define SOC_ASP_CODEC_CODEC_CLK_EN3_ADDR(base) ((base) + (0x00D8))
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL3_ADDR(base) ((base) + (0x00DC))
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ADDR(base) ((base) + (0x00E0))
#define SOC_ASP_CODEC_CODEC3_L_DN_PGA_CTRL_ADDR(base) ((base) + (0x00E4))
#define SOC_ASP_CODEC_CODEC3_R_DN_PGA_CTRL_ADDR(base) ((base) + (0x00E8))
#define SOC_ASP_CODEC_SRCDN_CTRL1_ADDR(base) ((base) + (0x00EC))
#define SOC_ASP_CODEC_ULTR_MIXER2_CTRL_ADDR(base) ((base) + (0x00F0))
#define SOC_ASP_CODEC_DACML_MIXER2_CTRL_ADDR(base) ((base) + (0x00F4))
#define SOC_ASP_CODEC_DACMR_MIXER2_CTRL_ADDR(base) ((base) + (0x00F8))
#define SOC_ASP_CODEC_DACML_FILTER_CTRL_ADDR(base) ((base) + (0x00FC))
#define SOC_ASP_CODEC_ADC_ULTR_FILTER_CTRL_ADDR(base) ((base) + (0x0100))
#define SOC_ASP_CODEC_DMIC_CTRL_ADDR(base) ((base) + (0x0104))
#define SOC_ASP_CODEC_DMIC_DIV_ADDR(base) ((base) + (0x0108))
#define SOC_ASP_CODEC_CODEC_DACML_DC_OFFSET_ADDR(base) ((base) + (0x010C))
#define SOC_ASP_CODEC_CODEC_ADC_ULTR_DC_OFFSET_ADDR(base) ((base) + (0x0120))
#define SOC_ASP_CODEC_SPA12_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x0124))
#define SOC_ASP_CODEC_SPA34_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x0128))
#define SOC_ASP_CODEC_ULTR_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x012C))
#define SOC_ASP_CODEC_ULTR_DN_AFIFO_CTRL_ADDR(base) ((base) + (0x0130))
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_ADDR(base) ((base) + (0x0134))
#define SOC_ASP_CODEC_FS_CTRL3_ADDR(base) ((base) + (0x0138))
#define SOC_ASP_CODEC_MEM_CTRL_S_CFG_ADDR(base) ((base) + (0x013C))
#define SOC_ASP_CODEC_I2S_FIFO_CLR_ADDR(base) ((base) + (0x0140))
#define SOC_ASP_CODEC_SPAIV_ADC_FILTER_ADDR(base) ((base) + (0x0144))
#define SOC_ASP_CODEC_CLASSH_CTRL1_ADDR(base) ((base) + (0x0148))
#define SOC_ASP_CODEC_CLASSH_CTRL2_ADDR(base) ((base) + (0x014C))
#define SOC_ASP_CODEC_LUT_REG0_3_ADDR(base) ((base) + (0x0150))
#define SOC_ASP_CODEC_LUT_REG4_7_ADDR(base) ((base) + (0x0154))
#define SOC_ASP_CODEC_LUT_REG8_11_ADDR(base) ((base) + (0x0158))
#define SOC_ASP_CODEC_LUT_REG12_15_ADDR(base) ((base) + (0x015C))
#define SOC_ASP_CODEC_LUT_REG16_19_ADDR(base) ((base) + (0x0160))
#define SOC_ASP_CODEC_LUT_REG20_23_ADDR(base) ((base) + (0x0164))
#define SOC_ASP_CODEC_LUT_REG24_27_ADDR(base) ((base) + (0x0168))
#define SOC_ASP_CODEC_LUT_REG28_31_ADDR(base) ((base) + (0x016C))
#define SOC_ASP_CODEC_LUT_REG32_35_ADDR(base) ((base) + (0x0170))
#define SOC_ASP_CODEC_LUT_REG36_39_ADDR(base) ((base) + (0x0174))
#define SOC_ASP_CODEC_LUT_REG40_43_ADDR(base) ((base) + (0x0178))
#define SOC_ASP_CODEC_LUT_REG44_47_ADDR(base) ((base) + (0x017C))
#define SOC_ASP_CODEC_LUT_REG48_51_ADDR(base) ((base) + (0x0180))
#define SOC_ASP_CODEC_LUT_REG52_55_ADDR(base) ((base) + (0x0184))
#define SOC_ASP_CODEC_LUT_REG56_59_ADDR(base) ((base) + (0x0188))
#define SOC_ASP_CODEC_LUT_REG60_63_ADDR(base) ((base) + (0x018C))
#define SOC_ASP_CODEC_LUT_REG64_67_ADDR(base) ((base) + (0x0190))
#define SOC_ASP_CODEC_CODEC_ADC_SPI_DC_OFFSET_ADDR(base) ((base) + (0x0194))
#define SOC_ASP_CODEC_CODEC_ADC_SPA_DC_OFFSET_ADDR(base) ((base) + (0x0198))
#define SOC_ASP_CODEC_CODEC_CLK_EN2_ADDR(base) ((base) + (0x019C))
#define SOC_ASP_CODEC_MIC4_SRCDN_CTRL1_ADDR(base) ((base) + (0x01A0))
#define SOC_ASP_CODEC_MIC4_PGA_ADDR(base) ((base) + (0x1A4))
#define SOC_ASP_CODEC_CODEC_DIN_MUX2_ADDR(base) ((base) + (0x01A8))
#define SOC_ASP_CODEC_FS_CTRL4_ADDR(base) ((base) + (0x01AC))
#define SOC_ASP_CODEC_SPA2_ADC_FILTER_ADDR(base) ((base) + (0x01B0))
#define SOC_ASP_CODEC_CODEC_ADC2_SPI_DC_OFFSET_ADDR(base) ((base) + (0x01B4))
#define SOC_ASP_CODEC_CODEC_ADC2_SPA_DC_OFFSET_ADDR(base) ((base) + (0x01B8))
#define SOC_ASP_CODEC_SPA3_ADC_FILTER_ADDR(base) ((base) + (0x01BC))
#define SOC_ASP_CODEC_CODEC_ADC3_SPI_DC_OFFSET_ADDR(base) ((base) + (0x01C0))
#define SOC_ASP_CODEC_CODEC_ADC3_SPA_DC_OFFSET_ADDR(base) ((base) + (0x01C4))
#define SOC_ASP_CODEC_SPA_SDM_CTRL_ADDR(base) ((base) + (0x01C8))
#define SOC_ASP_CODEC_CLASSH2_CTRL1_ADDR(base) ((base) + (0x01CC))
#define SOC_ASP_CODEC_CLASSH2_CTRL2_ADDR(base) ((base) + (0x01D0))
#define SOC_ASP_CODEC_CLASS2_LUT_REG0_3_ADDR(base) ((base) + (0x01D4))
#define SOC_ASP_CODEC_CLASS2_LUT_REG4_7_ADDR(base) ((base) + (0x01D8))
#define SOC_ASP_CODEC_CLASS2_LUT_REG8_11_ADDR(base) ((base) + (0x01DC))
#define SOC_ASP_CODEC_CLASS2_LUT_REG12_15_ADDR(base) ((base) + (0x01E0))
#define SOC_ASP_CODEC_CLASS2_LUT_REG16_19_ADDR(base) ((base) + (0x01E4))
#define SOC_ASP_CODEC_CLASS2_LUT_REG20_23_ADDR(base) ((base) + (0x01E8))
#define SOC_ASP_CODEC_CLASS2_LUT_REG24_27_ADDR(base) ((base) + (0x01EC))
#define SOC_ASP_CODEC_CLASS2_LUT_REG28_31_ADDR(base) ((base) + (0x01F0))
#define SOC_ASP_CODEC_CLASS2_LUT_REG32_35_ADDR(base) ((base) + (0x01F4))
#define SOC_ASP_CODEC_CLASS2_LUT_REG36_39_ADDR(base) ((base) + (0x01F8))
#define SOC_ASP_CODEC_CLASS2_LUT_REG40_43_ADDR(base) ((base) + (0x01FC))
#define SOC_ASP_CODEC_CLASS2_LUT_REG44_47_ADDR(base) ((base) + (0x0200))
#define SOC_ASP_CODEC_CLASS2_LUT_REG48_51_ADDR(base) ((base) + (0x0204))
#define SOC_ASP_CODEC_CLASS2_LUT_REG52_55_ADDR(base) ((base) + (0x0208))
#define SOC_ASP_CODEC_CLASS2_LUT_REG56_59_ADDR(base) ((base) + (0x020C))
#define SOC_ASP_CODEC_CLASS2_LUT_REG60_63_ADDR(base) ((base) + (0x0210))
#define SOC_ASP_CODEC_CLASS2_LUT_REG64_67_ADDR(base) ((base) + (0x021C))
#define SOC_ASP_CODEC_CLASSH3_CTRL1_ADDR(base) ((base) + (0x0220))
#define SOC_ASP_CODEC_CLASSH3_CTRL2_ADDR(base) ((base) + (0x0224))
#define SOC_ASP_CODEC_CLASSH3_LUT_REG0_3_ADDR(base) ((base) + (0x0228))
#define SOC_ASP_CODEC_CLASSH3_LUT_REG4_7_ADDR(base) ((base) + (0x022C))
#define SOC_ASP_CODEC_CLASSH3_LUT_REG8_11_ADDR(base) ((base) + (0x0230))
#define SOC_ASP_CODEC_CLASSH3_LUT_REG12_15_ADDR(base) ((base) + (0x0234))
#define SOC_ASP_CODEC_CLASSH3_LUT_REG16_19_ADDR(base) ((base) + (0x0238))
#define SOC_ASP_CODEC_CLASSH3_LUT_REG20_23_ADDR(base) ((base) + (0x023C))
#define SOC_ASP_CODEC_CLASSH3_LUT_REG24_27_ADDR(base) ((base) + (0x0240))
#define SOC_ASP_CODEC_CLASSH3_LUT_REG28_31_ADDR(base) ((base) + (0x0244))
#define SOC_ASP_CODEC_CLASSH3_LUT_REG32_35_ADDR(base) ((base) + (0x0248))
#define SOC_ASP_CODEC_CLASSH3_LUT_REG36_39_ADDR(base) ((base) + (0x024C))
#define SOC_ASP_CODEC_CLASSH3_LUT_REG40_43_ADDR(base) ((base) + (0x0250))
#define SOC_ASP_CODEC_CLASSH3_LUT_REG44_47_ADDR(base) ((base) + (0x0254))
#define SOC_ASP_CODEC_CLASSH3_LUT_REG48_51_ADDR(base) ((base) + (0x0258))
#define SOC_ASP_CODEC_CLASSH3_LUT_REG52_55_ADDR(base) ((base) + (0x025C))
#define SOC_ASP_CODEC_CLASSH3_LUT_REG56_59_ADDR(base) ((base) + (0x0260))
#define SOC_ASP_CODEC_CLASSH3_LUT_REG60_63_ADDR(base) ((base) + (0x0264))
#define SOC_ASP_CODEC_CLASSH3_LUT_REG64_67_ADDR(base) ((base) + (0x0268))
#define SOC_ASP_CODEC_MIC4_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x026C))
#define SOC_ASP_CODEC_ADC3_SPA_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x0270))
#define SOC_ASP_CODEC_ADC2_SPA_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x0274))
#define SOC_ASP_CODEC_MIC4_ADC_FILTER_ADDR(base) ((base) + (0x0278))
#define SOC_ASP_CODEC_CODEC_MIC4_DC_OFFSET_ADDR(base) ((base) + (0x027C))
#define SOC_ASP_CODEC_SPA1_SDM_DC_OFFSET_ADDR(base) ((base) + (0x0280))
#define SOC_ASP_CODEC_SPA2_SDM_DC_OFFSET_ADDR(base) ((base) + (0x0284))
#define SOC_ASP_CODEC_SPA3_SDM_DC_OFFSET_ADDR(base) ((base) + (0x0288))
#define SOC_ASP_CODEC_SIF2_3_CTRL_ADDR(base) ((base) + (0x028C))
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_ADDR(base) ((base) + (0x0290))
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL1_ADDR(base) ((base) + (0x0294))
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_ADDR(base) ((base) + (0x0298))
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL1_ADDR(base) ((base) + (0x029C))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int version : 32;
    } reg;
} SOC_ASP_CODEC_VERSION_UNION;
#endif
#define SOC_ASP_CODEC_VERSION_version_START (0)
#define SOC_ASP_CODEC_VERSION_version_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 2;
        unsigned int voice_l_dn_afifo_clken : 1;
        unsigned int audio_l_dn_afifo_clken : 1;
        unsigned int audio_r_dn_afifo_clken : 1;
        unsigned int audio_l_up_afifo_clken : 1;
        unsigned int audio_r_up_afifo_clken : 1;
        unsigned int voice_l_up_afifo_clken : 1;
        unsigned int voice_r_up_afifo_clken : 1;
        unsigned int mic3_up_afifo_clken : 1;
        unsigned int bt_l_rx_pga_clken : 1;
        unsigned int bt_r_rx_pga_clken : 1;
        unsigned int bt_l_rx_srcup_clken : 1;
        unsigned int bt_r_rx_srcup_clken : 1;
        unsigned int bt_l_rx_srcdn_clken : 1;
        unsigned int bt_r_rx_srcdn_clken : 1;
        unsigned int reserved_1 : 1;
        unsigned int bt_tx_mixer2_clken : 1;
        unsigned int voice_l_dn_pga_clken : 1;
        unsigned int audio_l_dn_pga_clken : 1;
        unsigned int audio_r_dn_pga_clken : 1;
        unsigned int voice_l_dn_srcup_clken : 1;
        unsigned int dacl_mixer4_clken : 1;
        unsigned int dacr_mixer4_clken : 1;
        unsigned int dacl_srcup_clken : 1;
        unsigned int dacr_srcup_clken : 1;
        unsigned int dacl_filter_clken : 1;
        unsigned int dacr_filter_clken : 1;
        unsigned int dacl_up16_clken : 1;
        unsigned int dacr_up16_clken : 1;
        unsigned int sdm_l_clken : 1;
        unsigned int sdm_r_clken : 1;
    } reg;
} SOC_ASP_CODEC_CODEC_CLK_EN0_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_CLK_EN0_voice_l_dn_afifo_clken_START (2)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_voice_l_dn_afifo_clken_END (2)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_audio_l_dn_afifo_clken_START (3)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_audio_l_dn_afifo_clken_END (3)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_audio_r_dn_afifo_clken_START (4)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_audio_r_dn_afifo_clken_END (4)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_audio_l_up_afifo_clken_START (5)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_audio_l_up_afifo_clken_END (5)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_audio_r_up_afifo_clken_START (6)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_audio_r_up_afifo_clken_END (6)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_voice_l_up_afifo_clken_START (7)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_voice_l_up_afifo_clken_END (7)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_voice_r_up_afifo_clken_START (8)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_voice_r_up_afifo_clken_END (8)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_mic3_up_afifo_clken_START (9)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_mic3_up_afifo_clken_END (9)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_bt_l_rx_pga_clken_START (10)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_bt_l_rx_pga_clken_END (10)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_bt_r_rx_pga_clken_START (11)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_bt_r_rx_pga_clken_END (11)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_bt_l_rx_srcup_clken_START (12)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_bt_l_rx_srcup_clken_END (12)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_bt_r_rx_srcup_clken_START (13)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_bt_r_rx_srcup_clken_END (13)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_bt_l_rx_srcdn_clken_START (14)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_bt_l_rx_srcdn_clken_END (14)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_bt_r_rx_srcdn_clken_START (15)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_bt_r_rx_srcdn_clken_END (15)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_bt_tx_mixer2_clken_START (17)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_bt_tx_mixer2_clken_END (17)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_voice_l_dn_pga_clken_START (18)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_voice_l_dn_pga_clken_END (18)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_audio_l_dn_pga_clken_START (19)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_audio_l_dn_pga_clken_END (19)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_audio_r_dn_pga_clken_START (20)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_audio_r_dn_pga_clken_END (20)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_voice_l_dn_srcup_clken_START (21)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_voice_l_dn_srcup_clken_END (21)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_dacl_mixer4_clken_START (22)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_dacl_mixer4_clken_END (22)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_dacr_mixer4_clken_START (23)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_dacr_mixer4_clken_END (23)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_dacl_srcup_clken_START (24)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_dacl_srcup_clken_END (24)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_dacr_srcup_clken_START (25)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_dacr_srcup_clken_END (25)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_dacl_filter_clken_START (26)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_dacl_filter_clken_END (26)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_dacr_filter_clken_START (27)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_dacr_filter_clken_END (27)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_dacl_up16_clken_START (28)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_dacl_up16_clken_END (28)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_dacr_up16_clken_START (29)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_dacr_up16_clken_END (29)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_sdm_l_clken_START (30)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_sdm_l_clken_END (30)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_sdm_r_clken_START (31)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_sdm_r_clken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int slv_mode_441 : 1;
        unsigned int rst_3mic_audio_irq : 1;
        unsigned int rst_3mic_voice_irq : 1;
        unsigned int sw_rst_n : 1;
        unsigned int voice_r_dn_afifo_clken : 1;
        unsigned int codec3_l_dn_afifo_clken : 1;
        unsigned int codec3_r_dn_afifo_clken : 1;
        unsigned int voice_r_dn_pga_clken : 1;
        unsigned int voice_r_dn_srcup_clken : 1;
        unsigned int i2s3_pcm_clken : 1;
        unsigned int reserved : 3;
        unsigned int echo_l_up_afifo_clken : 1;
        unsigned int echo_r_up_afifo_clken : 1;
        unsigned int echo_l_up_srcdn_clken : 1;
        unsigned int echo_r_up_srcdn_clken : 1;
        unsigned int sif_mst_clken : 1;
        unsigned int adcl_filter_clken : 1;
        unsigned int adcr_filter_clken : 1;
        unsigned int adc_mic3_filter_clken : 1;
        unsigned int sidetone_pga_clken : 1;
        unsigned int audio_l_up_pga_clken : 1;
        unsigned int audio_r_up_pga_clken : 1;
        unsigned int audio_l_up_srcup_clken : 1;
        unsigned int audio_r_up_srcup_clken : 1;
        unsigned int voice_l_up_srcdn_clken : 1;
        unsigned int voice_r_up_srcdn_clken : 1;
        unsigned int mic3_up_srcdn_clken : 1;
        unsigned int mic3_up_pga_clken : 1;
        unsigned int i2s1_tdm_clken : 1;
        unsigned int i2s2_pcm_clken : 1;
    } reg;
} SOC_ASP_CODEC_CODEC_CLK_EN1_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_CLK_EN1_slv_mode_441_START (0)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_slv_mode_441_END (0)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_rst_3mic_audio_irq_START (1)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_rst_3mic_audio_irq_END (1)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_rst_3mic_voice_irq_START (2)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_rst_3mic_voice_irq_END (2)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_sw_rst_n_START (3)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_sw_rst_n_END (3)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_voice_r_dn_afifo_clken_START (4)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_voice_r_dn_afifo_clken_END (4)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_codec3_l_dn_afifo_clken_START (5)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_codec3_l_dn_afifo_clken_END (5)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_codec3_r_dn_afifo_clken_START (6)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_codec3_r_dn_afifo_clken_END (6)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_voice_r_dn_pga_clken_START (7)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_voice_r_dn_pga_clken_END (7)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_voice_r_dn_srcup_clken_START (8)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_voice_r_dn_srcup_clken_END (8)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_i2s3_pcm_clken_START (9)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_i2s3_pcm_clken_END (9)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_echo_l_up_afifo_clken_START (13)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_echo_l_up_afifo_clken_END (13)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_echo_r_up_afifo_clken_START (14)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_echo_r_up_afifo_clken_END (14)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_echo_l_up_srcdn_clken_START (15)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_echo_l_up_srcdn_clken_END (15)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_echo_r_up_srcdn_clken_START (16)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_echo_r_up_srcdn_clken_END (16)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_sif_mst_clken_START (17)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_sif_mst_clken_END (17)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_adcl_filter_clken_START (18)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_adcl_filter_clken_END (18)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_adcr_filter_clken_START (19)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_adcr_filter_clken_END (19)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_adc_mic3_filter_clken_START (20)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_adc_mic3_filter_clken_END (20)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_sidetone_pga_clken_START (21)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_sidetone_pga_clken_END (21)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_audio_l_up_pga_clken_START (22)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_audio_l_up_pga_clken_END (22)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_audio_r_up_pga_clken_START (23)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_audio_r_up_pga_clken_END (23)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_audio_l_up_srcup_clken_START (24)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_audio_l_up_srcup_clken_END (24)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_audio_r_up_srcup_clken_START (25)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_audio_r_up_srcup_clken_END (25)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_voice_l_up_srcdn_clken_START (26)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_voice_l_up_srcdn_clken_END (26)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_voice_r_up_srcdn_clken_START (27)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_voice_r_up_srcdn_clken_END (27)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_mic3_up_srcdn_clken_START (28)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_mic3_up_srcdn_clken_END (28)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_mic3_up_pga_clken_START (29)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_mic3_up_pga_clken_END (29)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_i2s1_tdm_clken_START (30)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_i2s1_tdm_clken_END (30)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_i2s2_pcm_clken_START (31)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_i2s2_pcm_clken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 13;
        unsigned int fs_i2s1 : 3;
        unsigned int i2s1_if_tx_ena : 1;
        unsigned int i2s1_if_rx_ena : 1;
        unsigned int i2s1_mst_slv : 1;
        unsigned int i2s1_direct_loop : 2;
        unsigned int i2s1_func_mode : 3;
        unsigned int i2s1_frame_mode : 1;
        unsigned int i2s1_lrclk_mode : 1;
        unsigned int i2s1_chnnl_mode : 1;
        unsigned int i2s1_codec_data_format : 1;
        unsigned int i2s1_codec_io_wordlength : 2;
        unsigned int i2s1_tx_clk_sel : 1;
        unsigned int i2s1_rx_clk_sel : 1;
    } reg;
} SOC_ASP_CODEC_I2S1_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_I2S1_CTRL_fs_i2s1_START (13)
#define SOC_ASP_CODEC_I2S1_CTRL_fs_i2s1_END (15)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_if_tx_ena_START (16)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_if_tx_ena_END (16)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_if_rx_ena_START (17)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_if_rx_ena_END (17)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_mst_slv_START (18)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_mst_slv_END (18)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_direct_loop_START (19)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_direct_loop_END (20)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_func_mode_START (21)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_func_mode_END (23)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_frame_mode_START (24)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_frame_mode_END (24)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_lrclk_mode_START (25)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_lrclk_mode_END (25)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_chnnl_mode_START (26)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_chnnl_mode_END (26)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_codec_data_format_START (27)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_codec_data_format_END (27)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_codec_io_wordlength_START (28)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_codec_io_wordlength_END (29)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_tx_clk_sel_START (30)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_tx_clk_sel_END (30)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_rx_clk_sel_START (31)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_rx_clk_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int s1_fifo_clr : 1;
        unsigned int s1_mem_icg_bp_en : 1;
        unsigned int s1_tdm_frame_mode : 3;
        unsigned int s1_tdm_direct_loop : 2;
        unsigned int s1_tdm_if_en : 1;
        unsigned int s1_tdm_tx_ch3_sel : 2;
        unsigned int s1_tdm_tx_ch2_sel : 2;
        unsigned int s1_tdm_tx_ch1_sel : 2;
        unsigned int s1_tdm_tx_ch0_sel : 2;
        unsigned int s1_tdm_rx_slot_sel_v0 : 3;
        unsigned int s1_tdm_rx_slot_sel_i0 : 3;
        unsigned int s1_tdm_tx_clk_sel : 1;
        unsigned int s1_tdm_rx_clk_sel : 1;
        unsigned int s1_tdm_rx_slot_sel_v1 : 3;
        unsigned int s1_tdm_rx_slot_sel_i1 : 3;
        unsigned int reserved : 2;
    } reg;
} SOC_ASP_CODEC_I2S1_TDM_CTRL0_UNION;
#endif
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_fifo_clr_START (0)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_fifo_clr_END (0)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_mem_icg_bp_en_START (1)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_mem_icg_bp_en_END (1)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_frame_mode_START (2)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_frame_mode_END (4)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_direct_loop_START (5)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_direct_loop_END (6)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_if_en_START (7)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_if_en_END (7)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_tx_ch3_sel_START (8)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_tx_ch3_sel_END (9)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_tx_ch2_sel_START (10)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_tx_ch2_sel_END (11)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_tx_ch1_sel_START (12)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_tx_ch1_sel_END (13)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_tx_ch0_sel_START (14)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_tx_ch0_sel_END (15)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_rx_slot_sel_v0_START (16)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_rx_slot_sel_v0_END (18)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_rx_slot_sel_i0_START (19)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_rx_slot_sel_i0_END (21)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_tx_clk_sel_START (22)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_tx_clk_sel_END (22)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_rx_clk_sel_START (23)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_rx_clk_sel_END (23)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_rx_slot_sel_v1_START (24)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_rx_slot_sel_v1_END (26)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_rx_slot_sel_i1_START (27)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_rx_slot_sel_i1_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int s1_tdm_rx_slot_sel_v2 : 3;
        unsigned int s1_tdm_rx_slot_sel_i2 : 3;
        unsigned int reserved_0 : 2;
        unsigned int s1_tdm_rx_slot_sel_v3 : 3;
        unsigned int s1_tdm_rx_slot_sel_i3 : 3;
        unsigned int reserved_1 : 2;
        unsigned int s1_tdm_mst_slv : 1;
        unsigned int s1_i2s_tdm_mode : 1;
        unsigned int s1_tdm_err_stat : 2;
        unsigned int reserved_2 : 12;
    } reg;
} SOC_ASP_CODEC_I2S1_TDM_CTRL1_UNION;
#endif
#define SOC_ASP_CODEC_I2S1_TDM_CTRL1_s1_tdm_rx_slot_sel_v2_START (0)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL1_s1_tdm_rx_slot_sel_v2_END (2)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL1_s1_tdm_rx_slot_sel_i2_START (3)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL1_s1_tdm_rx_slot_sel_i2_END (5)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL1_s1_tdm_rx_slot_sel_v3_START (8)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL1_s1_tdm_rx_slot_sel_v3_END (10)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL1_s1_tdm_rx_slot_sel_i3_START (11)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL1_s1_tdm_rx_slot_sel_i3_END (13)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL1_s1_tdm_mst_slv_START (16)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL1_s1_tdm_mst_slv_END (16)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL1_s1_i2s_tdm_mode_START (17)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL1_s1_i2s_tdm_mode_END (17)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL1_s1_tdm_err_stat_START (18)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL1_s1_tdm_err_stat_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 13;
        unsigned int fs_i2s2 : 3;
        unsigned int i2s2_if_tx_ena : 1;
        unsigned int i2s2_if_rx_ena : 1;
        unsigned int i2s2_mst_slv : 1;
        unsigned int i2s2_direct_loop : 2;
        unsigned int i2s2_func_mode : 3;
        unsigned int i2s2_frame_mode : 1;
        unsigned int i2s2_lrclk_mode : 1;
        unsigned int i2s2_chnnl_mode : 1;
        unsigned int i2s2_codec_data_format : 1;
        unsigned int i2s2_codec_io_wordlength : 2;
        unsigned int i2s2_tx_clk_sel : 1;
        unsigned int i2s2_rx_clk_sel : 1;
    } reg;
} SOC_ASP_CODEC_I2S2_PCM_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_fs_i2s2_START (13)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_fs_i2s2_END (15)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_if_tx_ena_START (16)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_if_tx_ena_END (16)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_if_rx_ena_START (17)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_if_rx_ena_END (17)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_mst_slv_START (18)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_mst_slv_END (18)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_direct_loop_START (19)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_direct_loop_END (20)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_func_mode_START (21)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_func_mode_END (23)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_frame_mode_START (24)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_frame_mode_END (24)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_lrclk_mode_START (25)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_lrclk_mode_END (25)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_chnnl_mode_START (26)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_chnnl_mode_END (26)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_codec_data_format_START (27)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_codec_data_format_END (27)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_codec_io_wordlength_START (28)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_codec_io_wordlength_END (29)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_tx_clk_sel_START (30)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_tx_clk_sel_END (30)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_rx_clk_sel_START (31)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_rx_clk_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pga_mixer_thre_ctrl0 : 32;
    } reg;
} SOC_ASP_CODEC_PGA_THRE_CTRL0_UNION;
#endif
#define SOC_ASP_CODEC_PGA_THRE_CTRL0_pga_mixer_thre_ctrl0_START (0)
#define SOC_ASP_CODEC_PGA_THRE_CTRL0_pga_mixer_thre_ctrl0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pga_mixer_thre_ctrl1 : 32;
    } reg;
} SOC_ASP_CODEC_PGA_THRE_CTRL1_UNION;
#endif
#define SOC_ASP_CODEC_PGA_THRE_CTRL1_pga_mixer_thre_ctrl1_START (0)
#define SOC_ASP_CODEC_PGA_THRE_CTRL1_pga_mixer_thre_ctrl1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pga_mixer_thre_ctrl2 : 32;
    } reg;
} SOC_ASP_CODEC_PGA_THRE_CTRL2_UNION;
#endif
#define SOC_ASP_CODEC_PGA_THRE_CTRL2_pga_mixer_thre_ctrl2_START (0)
#define SOC_ASP_CODEC_PGA_THRE_CTRL2_pga_mixer_thre_ctrl2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sidetone_pga_gainoffset : 8;
        unsigned int audio_r_dn_pga_gainoffset : 8;
        unsigned int audio_l_dn_pga_gainoffset : 8;
        unsigned int voice_l_dn_pga_gainoffset : 8;
    } reg;
} SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL0_UNION;
#endif
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL0_sidetone_pga_gainoffset_START (0)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL0_sidetone_pga_gainoffset_END (7)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL0_audio_r_dn_pga_gainoffset_START (8)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL0_audio_r_dn_pga_gainoffset_END (15)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL0_audio_l_dn_pga_gainoffset_START (16)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL0_audio_l_dn_pga_gainoffset_END (23)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL0_voice_l_dn_pga_gainoffset_START (24)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL0_voice_l_dn_pga_gainoffset_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bt_r_rx_pga_gainoffset : 8;
        unsigned int bt_l_rx_pga_gainoffset : 8;
        unsigned int audio_r_up_pga_gainoffset : 8;
        unsigned int audio_l_up_pga_gainoffset : 8;
    } reg;
} SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL1_UNION;
#endif
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL1_bt_r_rx_pga_gainoffset_START (0)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL1_bt_r_rx_pga_gainoffset_END (7)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL1_bt_l_rx_pga_gainoffset_START (8)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL1_bt_l_rx_pga_gainoffset_END (15)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL1_audio_r_up_pga_gainoffset_START (16)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL1_audio_r_up_pga_gainoffset_END (23)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL1_audio_l_up_pga_gainoffset_START (24)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL1_audio_l_up_pga_gainoffset_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 16;
        unsigned int voice_r_dn_pga_gainoffset : 8;
        unsigned int mic3_up_pga_gainoffset : 8;
    } reg;
} SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL2_UNION;
#endif
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL2_voice_r_dn_pga_gainoffset_START (16)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL2_voice_r_dn_pga_gainoffset_END (23)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL2_mic3_up_pga_gainoffset_START (24)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL2_mic3_up_pga_gainoffset_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 1;
        unsigned int voice_l_dn_pga_linear_sel : 1;
        unsigned int voice_l_dn_pga_zero_num : 5;
        unsigned int voice_l_dn_pga_thre_id : 2;
        unsigned int voice_l_dn_pga_noise_en : 1;
        unsigned int voice_l_dn_pga_bypass : 1;
        unsigned int voice_l_dn_pga_fade_out : 5;
        unsigned int voice_l_dn_pga_fade_in : 5;
        unsigned int voice_l_dn_pga_cfg : 3;
        unsigned int voice_l_dn_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_VOICE_L_DN_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_VOICE_L_DN_PGA_CTRL_voice_l_dn_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_VOICE_L_DN_PGA_CTRL_voice_l_dn_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_VOICE_L_DN_PGA_CTRL_voice_l_dn_pga_zero_num_START (2)
#define SOC_ASP_CODEC_VOICE_L_DN_PGA_CTRL_voice_l_dn_pga_zero_num_END (6)
#define SOC_ASP_CODEC_VOICE_L_DN_PGA_CTRL_voice_l_dn_pga_thre_id_START (7)
#define SOC_ASP_CODEC_VOICE_L_DN_PGA_CTRL_voice_l_dn_pga_thre_id_END (8)
#define SOC_ASP_CODEC_VOICE_L_DN_PGA_CTRL_voice_l_dn_pga_noise_en_START (9)
#define SOC_ASP_CODEC_VOICE_L_DN_PGA_CTRL_voice_l_dn_pga_noise_en_END (9)
#define SOC_ASP_CODEC_VOICE_L_DN_PGA_CTRL_voice_l_dn_pga_bypass_START (10)
#define SOC_ASP_CODEC_VOICE_L_DN_PGA_CTRL_voice_l_dn_pga_bypass_END (10)
#define SOC_ASP_CODEC_VOICE_L_DN_PGA_CTRL_voice_l_dn_pga_fade_out_START (11)
#define SOC_ASP_CODEC_VOICE_L_DN_PGA_CTRL_voice_l_dn_pga_fade_out_END (15)
#define SOC_ASP_CODEC_VOICE_L_DN_PGA_CTRL_voice_l_dn_pga_fade_in_START (16)
#define SOC_ASP_CODEC_VOICE_L_DN_PGA_CTRL_voice_l_dn_pga_fade_in_END (20)
#define SOC_ASP_CODEC_VOICE_L_DN_PGA_CTRL_voice_l_dn_pga_cfg_START (21)
#define SOC_ASP_CODEC_VOICE_L_DN_PGA_CTRL_voice_l_dn_pga_cfg_END (23)
#define SOC_ASP_CODEC_VOICE_L_DN_PGA_CTRL_voice_l_dn_pga_gain_START (24)
#define SOC_ASP_CODEC_VOICE_L_DN_PGA_CTRL_voice_l_dn_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 1;
        unsigned int audio_l_dn_pga_linear_sel : 1;
        unsigned int audio_l_dn_pga_zero_num : 5;
        unsigned int audio_l_dn_pga_thre_id : 2;
        unsigned int audio_l_dn_pga_noise_en : 1;
        unsigned int audio_l_dn_pga_bypass : 1;
        unsigned int audio_l_dn_pga_fade_out : 5;
        unsigned int audio_l_dn_pga_fade_in : 5;
        unsigned int audio_l_dn_pga_cfg : 3;
        unsigned int audio_l_dn_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_AUDIO_L_DN_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_AUDIO_L_DN_PGA_CTRL_audio_l_dn_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_AUDIO_L_DN_PGA_CTRL_audio_l_dn_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_AUDIO_L_DN_PGA_CTRL_audio_l_dn_pga_zero_num_START (2)
#define SOC_ASP_CODEC_AUDIO_L_DN_PGA_CTRL_audio_l_dn_pga_zero_num_END (6)
#define SOC_ASP_CODEC_AUDIO_L_DN_PGA_CTRL_audio_l_dn_pga_thre_id_START (7)
#define SOC_ASP_CODEC_AUDIO_L_DN_PGA_CTRL_audio_l_dn_pga_thre_id_END (8)
#define SOC_ASP_CODEC_AUDIO_L_DN_PGA_CTRL_audio_l_dn_pga_noise_en_START (9)
#define SOC_ASP_CODEC_AUDIO_L_DN_PGA_CTRL_audio_l_dn_pga_noise_en_END (9)
#define SOC_ASP_CODEC_AUDIO_L_DN_PGA_CTRL_audio_l_dn_pga_bypass_START (10)
#define SOC_ASP_CODEC_AUDIO_L_DN_PGA_CTRL_audio_l_dn_pga_bypass_END (10)
#define SOC_ASP_CODEC_AUDIO_L_DN_PGA_CTRL_audio_l_dn_pga_fade_out_START (11)
#define SOC_ASP_CODEC_AUDIO_L_DN_PGA_CTRL_audio_l_dn_pga_fade_out_END (15)
#define SOC_ASP_CODEC_AUDIO_L_DN_PGA_CTRL_audio_l_dn_pga_fade_in_START (16)
#define SOC_ASP_CODEC_AUDIO_L_DN_PGA_CTRL_audio_l_dn_pga_fade_in_END (20)
#define SOC_ASP_CODEC_AUDIO_L_DN_PGA_CTRL_audio_l_dn_pga_cfg_START (21)
#define SOC_ASP_CODEC_AUDIO_L_DN_PGA_CTRL_audio_l_dn_pga_cfg_END (23)
#define SOC_ASP_CODEC_AUDIO_L_DN_PGA_CTRL_audio_l_dn_pga_gain_START (24)
#define SOC_ASP_CODEC_AUDIO_L_DN_PGA_CTRL_audio_l_dn_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 1;
        unsigned int audio_r_dn_pga_linear_sel : 1;
        unsigned int audio_r_dn_pga_zero_num : 5;
        unsigned int audio_r_dn_pga_thre_id : 2;
        unsigned int audio_r_dn_pga_noise_en : 1;
        unsigned int audio_r_dn_pga_bypass : 1;
        unsigned int audio_r_dn_pga_fade_out : 5;
        unsigned int audio_r_dn_pga_fade_in : 5;
        unsigned int audio_r_dn_pga_cfg : 3;
        unsigned int audio_r_dn_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_AUDIO_R_DN_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_AUDIO_R_DN_PGA_CTRL_audio_r_dn_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_AUDIO_R_DN_PGA_CTRL_audio_r_dn_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_AUDIO_R_DN_PGA_CTRL_audio_r_dn_pga_zero_num_START (2)
#define SOC_ASP_CODEC_AUDIO_R_DN_PGA_CTRL_audio_r_dn_pga_zero_num_END (6)
#define SOC_ASP_CODEC_AUDIO_R_DN_PGA_CTRL_audio_r_dn_pga_thre_id_START (7)
#define SOC_ASP_CODEC_AUDIO_R_DN_PGA_CTRL_audio_r_dn_pga_thre_id_END (8)
#define SOC_ASP_CODEC_AUDIO_R_DN_PGA_CTRL_audio_r_dn_pga_noise_en_START (9)
#define SOC_ASP_CODEC_AUDIO_R_DN_PGA_CTRL_audio_r_dn_pga_noise_en_END (9)
#define SOC_ASP_CODEC_AUDIO_R_DN_PGA_CTRL_audio_r_dn_pga_bypass_START (10)
#define SOC_ASP_CODEC_AUDIO_R_DN_PGA_CTRL_audio_r_dn_pga_bypass_END (10)
#define SOC_ASP_CODEC_AUDIO_R_DN_PGA_CTRL_audio_r_dn_pga_fade_out_START (11)
#define SOC_ASP_CODEC_AUDIO_R_DN_PGA_CTRL_audio_r_dn_pga_fade_out_END (15)
#define SOC_ASP_CODEC_AUDIO_R_DN_PGA_CTRL_audio_r_dn_pga_fade_in_START (16)
#define SOC_ASP_CODEC_AUDIO_R_DN_PGA_CTRL_audio_r_dn_pga_fade_in_END (20)
#define SOC_ASP_CODEC_AUDIO_R_DN_PGA_CTRL_audio_r_dn_pga_cfg_START (21)
#define SOC_ASP_CODEC_AUDIO_R_DN_PGA_CTRL_audio_r_dn_pga_cfg_END (23)
#define SOC_ASP_CODEC_AUDIO_R_DN_PGA_CTRL_audio_r_dn_pga_gain_START (24)
#define SOC_ASP_CODEC_AUDIO_R_DN_PGA_CTRL_audio_r_dn_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 1;
        unsigned int sidetone_pga_linear_sel : 1;
        unsigned int sidetone_pga_zero_num : 5;
        unsigned int sidetone_pga_thre_id : 2;
        unsigned int sidetone_pga_noise_en : 1;
        unsigned int sidetone_pga_bypass : 1;
        unsigned int sidetone_pga_fade_out : 5;
        unsigned int sidetone_pga_fade_in : 5;
        unsigned int sidetone_pga_cfg : 3;
        unsigned int sidetone_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_SIDETONE_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_sidetone_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_sidetone_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_sidetone_pga_zero_num_START (2)
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_sidetone_pga_zero_num_END (6)
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_sidetone_pga_thre_id_START (7)
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_sidetone_pga_thre_id_END (8)
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_sidetone_pga_noise_en_START (9)
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_sidetone_pga_noise_en_END (9)
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_sidetone_pga_bypass_START (10)
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_sidetone_pga_bypass_END (10)
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_sidetone_pga_fade_out_START (11)
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_sidetone_pga_fade_out_END (15)
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_sidetone_pga_fade_in_START (16)
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_sidetone_pga_fade_in_END (20)
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_sidetone_pga_cfg_START (21)
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_sidetone_pga_cfg_END (23)
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_sidetone_pga_gain_START (24)
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_sidetone_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 1;
        unsigned int audio_l_up_pga_linear_sel : 1;
        unsigned int audio_l_up_pga_zero_num : 5;
        unsigned int audio_l_up_pga_thre_id : 2;
        unsigned int audio_l_up_pga_noise_en : 1;
        unsigned int audio_l_up_pga_bypass : 1;
        unsigned int audio_l_up_pga_fade_out : 5;
        unsigned int audio_l_up_pga_fade_in : 5;
        unsigned int audio_l_up_pga_cfg : 3;
        unsigned int audio_l_up_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_audio_l_up_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_audio_l_up_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_audio_l_up_pga_zero_num_START (2)
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_audio_l_up_pga_zero_num_END (6)
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_audio_l_up_pga_thre_id_START (7)
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_audio_l_up_pga_thre_id_END (8)
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_audio_l_up_pga_noise_en_START (9)
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_audio_l_up_pga_noise_en_END (9)
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_audio_l_up_pga_bypass_START (10)
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_audio_l_up_pga_bypass_END (10)
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_audio_l_up_pga_fade_out_START (11)
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_audio_l_up_pga_fade_out_END (15)
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_audio_l_up_pga_fade_in_START (16)
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_audio_l_up_pga_fade_in_END (20)
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_audio_l_up_pga_cfg_START (21)
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_audio_l_up_pga_cfg_END (23)
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_audio_l_up_pga_gain_START (24)
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_audio_l_up_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 1;
        unsigned int audio_r_up_pga_linear_sel : 1;
        unsigned int audio_r_up_pga_zero_num : 5;
        unsigned int audio_r_up_pga_thre_id : 2;
        unsigned int audio_r_up_pga_noise_en : 1;
        unsigned int audio_r_up_pga_bypass : 1;
        unsigned int audio_r_up_pga_fade_out : 5;
        unsigned int audio_r_up_pga_fade_in : 5;
        unsigned int audio_r_up_pga_cfg : 3;
        unsigned int audio_r_up_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_audio_r_up_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_audio_r_up_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_audio_r_up_pga_zero_num_START (2)
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_audio_r_up_pga_zero_num_END (6)
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_audio_r_up_pga_thre_id_START (7)
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_audio_r_up_pga_thre_id_END (8)
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_audio_r_up_pga_noise_en_START (9)
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_audio_r_up_pga_noise_en_END (9)
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_audio_r_up_pga_bypass_START (10)
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_audio_r_up_pga_bypass_END (10)
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_audio_r_up_pga_fade_out_START (11)
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_audio_r_up_pga_fade_out_END (15)
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_audio_r_up_pga_fade_in_START (16)
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_audio_r_up_pga_fade_in_END (20)
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_audio_r_up_pga_cfg_START (21)
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_audio_r_up_pga_cfg_END (23)
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_audio_r_up_pga_gain_START (24)
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_audio_r_up_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 1;
        unsigned int bt_l_rx_pga_linear_sel : 1;
        unsigned int bt_l_rx_pga_zero_num : 5;
        unsigned int bt_l_rx_pga_thre_id : 2;
        unsigned int bt_l_rx_pga_noise_en : 1;
        unsigned int bt_l_rx_pga_bypass : 1;
        unsigned int bt_l_rx_pga_fade_out : 5;
        unsigned int bt_l_rx_pga_fade_in : 5;
        unsigned int bt_l_rx_pga_cfg : 3;
        unsigned int bt_l_rx_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_BT_L_RX_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_BT_L_RX_PGA_CTRL_bt_l_rx_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_BT_L_RX_PGA_CTRL_bt_l_rx_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_BT_L_RX_PGA_CTRL_bt_l_rx_pga_zero_num_START (2)
#define SOC_ASP_CODEC_BT_L_RX_PGA_CTRL_bt_l_rx_pga_zero_num_END (6)
#define SOC_ASP_CODEC_BT_L_RX_PGA_CTRL_bt_l_rx_pga_thre_id_START (7)
#define SOC_ASP_CODEC_BT_L_RX_PGA_CTRL_bt_l_rx_pga_thre_id_END (8)
#define SOC_ASP_CODEC_BT_L_RX_PGA_CTRL_bt_l_rx_pga_noise_en_START (9)
#define SOC_ASP_CODEC_BT_L_RX_PGA_CTRL_bt_l_rx_pga_noise_en_END (9)
#define SOC_ASP_CODEC_BT_L_RX_PGA_CTRL_bt_l_rx_pga_bypass_START (10)
#define SOC_ASP_CODEC_BT_L_RX_PGA_CTRL_bt_l_rx_pga_bypass_END (10)
#define SOC_ASP_CODEC_BT_L_RX_PGA_CTRL_bt_l_rx_pga_fade_out_START (11)
#define SOC_ASP_CODEC_BT_L_RX_PGA_CTRL_bt_l_rx_pga_fade_out_END (15)
#define SOC_ASP_CODEC_BT_L_RX_PGA_CTRL_bt_l_rx_pga_fade_in_START (16)
#define SOC_ASP_CODEC_BT_L_RX_PGA_CTRL_bt_l_rx_pga_fade_in_END (20)
#define SOC_ASP_CODEC_BT_L_RX_PGA_CTRL_bt_l_rx_pga_cfg_START (21)
#define SOC_ASP_CODEC_BT_L_RX_PGA_CTRL_bt_l_rx_pga_cfg_END (23)
#define SOC_ASP_CODEC_BT_L_RX_PGA_CTRL_bt_l_rx_pga_gain_START (24)
#define SOC_ASP_CODEC_BT_L_RX_PGA_CTRL_bt_l_rx_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 1;
        unsigned int bt_r_rx_pga_linear_sel : 1;
        unsigned int bt_r_rx_pga_zero_num : 5;
        unsigned int bt_r_rx_pga_thre_id : 2;
        unsigned int bt_r_rx_pga_noise_en : 1;
        unsigned int bt_r_rx_pga_bypass : 1;
        unsigned int bt_r_rx_pga_fade_out : 5;
        unsigned int bt_r_rx_pga_fade_in : 5;
        unsigned int bt_r_rx_pga_cfg : 3;
        unsigned int bt_r_rx_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_BT_R_RX_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_BT_R_RX_PGA_CTRL_bt_r_rx_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_BT_R_RX_PGA_CTRL_bt_r_rx_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_BT_R_RX_PGA_CTRL_bt_r_rx_pga_zero_num_START (2)
#define SOC_ASP_CODEC_BT_R_RX_PGA_CTRL_bt_r_rx_pga_zero_num_END (6)
#define SOC_ASP_CODEC_BT_R_RX_PGA_CTRL_bt_r_rx_pga_thre_id_START (7)
#define SOC_ASP_CODEC_BT_R_RX_PGA_CTRL_bt_r_rx_pga_thre_id_END (8)
#define SOC_ASP_CODEC_BT_R_RX_PGA_CTRL_bt_r_rx_pga_noise_en_START (9)
#define SOC_ASP_CODEC_BT_R_RX_PGA_CTRL_bt_r_rx_pga_noise_en_END (9)
#define SOC_ASP_CODEC_BT_R_RX_PGA_CTRL_bt_r_rx_pga_bypass_START (10)
#define SOC_ASP_CODEC_BT_R_RX_PGA_CTRL_bt_r_rx_pga_bypass_END (10)
#define SOC_ASP_CODEC_BT_R_RX_PGA_CTRL_bt_r_rx_pga_fade_out_START (11)
#define SOC_ASP_CODEC_BT_R_RX_PGA_CTRL_bt_r_rx_pga_fade_out_END (15)
#define SOC_ASP_CODEC_BT_R_RX_PGA_CTRL_bt_r_rx_pga_fade_in_START (16)
#define SOC_ASP_CODEC_BT_R_RX_PGA_CTRL_bt_r_rx_pga_fade_in_END (20)
#define SOC_ASP_CODEC_BT_R_RX_PGA_CTRL_bt_r_rx_pga_cfg_START (21)
#define SOC_ASP_CODEC_BT_R_RX_PGA_CTRL_bt_r_rx_pga_cfg_END (23)
#define SOC_ASP_CODEC_BT_R_RX_PGA_CTRL_bt_r_rx_pga_gain_START (24)
#define SOC_ASP_CODEC_BT_R_RX_PGA_CTRL_bt_r_rx_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 1;
        unsigned int mic3_up_pga_linear_sel : 1;
        unsigned int mic3_up_pga_zero_num : 5;
        unsigned int mic3_up_pga_thre_id : 2;
        unsigned int mic3_up_pga_noise_en : 1;
        unsigned int mic3_up_pga_bypass : 1;
        unsigned int mic3_up_pga_fade_out : 5;
        unsigned int mic3_up_pga_fade_in : 5;
        unsigned int mic3_up_pga_cfg : 3;
        unsigned int mic3_up_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_mic3_up_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_mic3_up_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_mic3_up_pga_zero_num_START (2)
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_mic3_up_pga_zero_num_END (6)
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_mic3_up_pga_thre_id_START (7)
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_mic3_up_pga_thre_id_END (8)
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_mic3_up_pga_noise_en_START (9)
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_mic3_up_pga_noise_en_END (9)
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_mic3_up_pga_bypass_START (10)
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_mic3_up_pga_bypass_END (10)
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_mic3_up_pga_fade_out_START (11)
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_mic3_up_pga_fade_out_END (15)
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_mic3_up_pga_fade_in_START (16)
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_mic3_up_pga_fade_in_END (20)
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_mic3_up_pga_cfg_START (21)
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_mic3_up_pga_cfg_END (23)
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_mic3_up_pga_gain_START (24)
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_mic3_up_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int voice_r_dn_srcup_src_mode : 3;
        unsigned int voice_r_dn_srcup_fifo_clr : 1;
        unsigned int bt_r_rx_srcup_src_mode : 3;
        unsigned int bt_r_rx_srcup_fifo_clr : 1;
        unsigned int bt_l_rx_srcup_src_mode : 3;
        unsigned int bt_l_rx_srcup_fifo_clr : 1;
        unsigned int audio_r_up_srcup_src_mode : 3;
        unsigned int audio_r_up_srcup_fifo_clr : 1;
        unsigned int audio_l_up_srcup_src_mode : 3;
        unsigned int audio_l_up_srcup_fifo_clr : 1;
        unsigned int dacr_srcup_src_mode : 3;
        unsigned int dacr_srcup_fifo_clr : 1;
        unsigned int dacl_srcup_src_mode : 3;
        unsigned int dacl_srcup_fifo_clr : 1;
        unsigned int voice_l_dn_srcup_src_mode : 3;
        unsigned int voice_l_dn_srcup_fifo_clr : 1;
    } reg;
} SOC_ASP_CODEC_SRCUP_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_SRCUP_CTRL_voice_r_dn_srcup_src_mode_START (0)
#define SOC_ASP_CODEC_SRCUP_CTRL_voice_r_dn_srcup_src_mode_END (2)
#define SOC_ASP_CODEC_SRCUP_CTRL_voice_r_dn_srcup_fifo_clr_START (3)
#define SOC_ASP_CODEC_SRCUP_CTRL_voice_r_dn_srcup_fifo_clr_END (3)
#define SOC_ASP_CODEC_SRCUP_CTRL_bt_r_rx_srcup_src_mode_START (4)
#define SOC_ASP_CODEC_SRCUP_CTRL_bt_r_rx_srcup_src_mode_END (6)
#define SOC_ASP_CODEC_SRCUP_CTRL_bt_r_rx_srcup_fifo_clr_START (7)
#define SOC_ASP_CODEC_SRCUP_CTRL_bt_r_rx_srcup_fifo_clr_END (7)
#define SOC_ASP_CODEC_SRCUP_CTRL_bt_l_rx_srcup_src_mode_START (8)
#define SOC_ASP_CODEC_SRCUP_CTRL_bt_l_rx_srcup_src_mode_END (10)
#define SOC_ASP_CODEC_SRCUP_CTRL_bt_l_rx_srcup_fifo_clr_START (11)
#define SOC_ASP_CODEC_SRCUP_CTRL_bt_l_rx_srcup_fifo_clr_END (11)
#define SOC_ASP_CODEC_SRCUP_CTRL_audio_r_up_srcup_src_mode_START (12)
#define SOC_ASP_CODEC_SRCUP_CTRL_audio_r_up_srcup_src_mode_END (14)
#define SOC_ASP_CODEC_SRCUP_CTRL_audio_r_up_srcup_fifo_clr_START (15)
#define SOC_ASP_CODEC_SRCUP_CTRL_audio_r_up_srcup_fifo_clr_END (15)
#define SOC_ASP_CODEC_SRCUP_CTRL_audio_l_up_srcup_src_mode_START (16)
#define SOC_ASP_CODEC_SRCUP_CTRL_audio_l_up_srcup_src_mode_END (18)
#define SOC_ASP_CODEC_SRCUP_CTRL_audio_l_up_srcup_fifo_clr_START (19)
#define SOC_ASP_CODEC_SRCUP_CTRL_audio_l_up_srcup_fifo_clr_END (19)
#define SOC_ASP_CODEC_SRCUP_CTRL_dacr_srcup_src_mode_START (20)
#define SOC_ASP_CODEC_SRCUP_CTRL_dacr_srcup_src_mode_END (22)
#define SOC_ASP_CODEC_SRCUP_CTRL_dacr_srcup_fifo_clr_START (23)
#define SOC_ASP_CODEC_SRCUP_CTRL_dacr_srcup_fifo_clr_END (23)
#define SOC_ASP_CODEC_SRCUP_CTRL_dacl_srcup_src_mode_START (24)
#define SOC_ASP_CODEC_SRCUP_CTRL_dacl_srcup_src_mode_END (26)
#define SOC_ASP_CODEC_SRCUP_CTRL_dacl_srcup_fifo_clr_START (27)
#define SOC_ASP_CODEC_SRCUP_CTRL_dacl_srcup_fifo_clr_END (27)
#define SOC_ASP_CODEC_SRCUP_CTRL_voice_l_dn_srcup_src_mode_START (28)
#define SOC_ASP_CODEC_SRCUP_CTRL_voice_l_dn_srcup_src_mode_END (30)
#define SOC_ASP_CODEC_SRCUP_CTRL_voice_l_dn_srcup_fifo_clr_START (31)
#define SOC_ASP_CODEC_SRCUP_CTRL_voice_l_dn_srcup_fifo_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int echo_r_up_srcdn_src_mode : 3;
        unsigned int echo_r_up_srcdn_fifo_clr : 1;
        unsigned int echo_l_up_srcdn_src_mode : 3;
        unsigned int echo_l_up_srcdn_fifo_clr : 1;
        unsigned int bt_l_tx_srcdn_src_mode : 3;
        unsigned int bt_l_tx_srcdn_fifo_clr : 1;
        unsigned int bt_r_rx_srcdn_src_mode : 3;
        unsigned int bt_r_rx_srcdn_fifo_clr : 1;
        unsigned int bt_l_rx_srcdn_src_mode : 3;
        unsigned int bt_l_rx_srcdn_fifo_clr : 1;
        unsigned int mic3_up_srcdn_src_mode : 3;
        unsigned int mic3_up_srcdn_fifo_clr : 1;
        unsigned int voice_r_up_srcdn_src_mode : 3;
        unsigned int voice_r_up_srcdn_fifo_clr : 1;
        unsigned int voice_l_up_srcdn_src_mode : 3;
        unsigned int voice_l_up_srcdn_fifo_clr : 1;
    } reg;
} SOC_ASP_CODEC_SRCDN_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_SRCDN_CTRL_echo_r_up_srcdn_src_mode_START (0)
#define SOC_ASP_CODEC_SRCDN_CTRL_echo_r_up_srcdn_src_mode_END (2)
#define SOC_ASP_CODEC_SRCDN_CTRL_echo_r_up_srcdn_fifo_clr_START (3)
#define SOC_ASP_CODEC_SRCDN_CTRL_echo_r_up_srcdn_fifo_clr_END (3)
#define SOC_ASP_CODEC_SRCDN_CTRL_echo_l_up_srcdn_src_mode_START (4)
#define SOC_ASP_CODEC_SRCDN_CTRL_echo_l_up_srcdn_src_mode_END (6)
#define SOC_ASP_CODEC_SRCDN_CTRL_echo_l_up_srcdn_fifo_clr_START (7)
#define SOC_ASP_CODEC_SRCDN_CTRL_echo_l_up_srcdn_fifo_clr_END (7)
#define SOC_ASP_CODEC_SRCDN_CTRL_bt_l_tx_srcdn_src_mode_START (8)
#define SOC_ASP_CODEC_SRCDN_CTRL_bt_l_tx_srcdn_src_mode_END (10)
#define SOC_ASP_CODEC_SRCDN_CTRL_bt_l_tx_srcdn_fifo_clr_START (11)
#define SOC_ASP_CODEC_SRCDN_CTRL_bt_l_tx_srcdn_fifo_clr_END (11)
#define SOC_ASP_CODEC_SRCDN_CTRL_bt_r_rx_srcdn_src_mode_START (12)
#define SOC_ASP_CODEC_SRCDN_CTRL_bt_r_rx_srcdn_src_mode_END (14)
#define SOC_ASP_CODEC_SRCDN_CTRL_bt_r_rx_srcdn_fifo_clr_START (15)
#define SOC_ASP_CODEC_SRCDN_CTRL_bt_r_rx_srcdn_fifo_clr_END (15)
#define SOC_ASP_CODEC_SRCDN_CTRL_bt_l_rx_srcdn_src_mode_START (16)
#define SOC_ASP_CODEC_SRCDN_CTRL_bt_l_rx_srcdn_src_mode_END (18)
#define SOC_ASP_CODEC_SRCDN_CTRL_bt_l_rx_srcdn_fifo_clr_START (19)
#define SOC_ASP_CODEC_SRCDN_CTRL_bt_l_rx_srcdn_fifo_clr_END (19)
#define SOC_ASP_CODEC_SRCDN_CTRL_mic3_up_srcdn_src_mode_START (20)
#define SOC_ASP_CODEC_SRCDN_CTRL_mic3_up_srcdn_src_mode_END (22)
#define SOC_ASP_CODEC_SRCDN_CTRL_mic3_up_srcdn_fifo_clr_START (23)
#define SOC_ASP_CODEC_SRCDN_CTRL_mic3_up_srcdn_fifo_clr_END (23)
#define SOC_ASP_CODEC_SRCDN_CTRL_voice_r_up_srcdn_src_mode_START (24)
#define SOC_ASP_CODEC_SRCDN_CTRL_voice_r_up_srcdn_src_mode_END (26)
#define SOC_ASP_CODEC_SRCDN_CTRL_voice_r_up_srcdn_fifo_clr_START (27)
#define SOC_ASP_CODEC_SRCDN_CTRL_voice_r_up_srcdn_fifo_clr_END (27)
#define SOC_ASP_CODEC_SRCDN_CTRL_voice_l_up_srcdn_src_mode_START (28)
#define SOC_ASP_CODEC_SRCDN_CTRL_voice_l_up_srcdn_src_mode_END (30)
#define SOC_ASP_CODEC_SRCDN_CTRL_voice_l_up_srcdn_fifo_clr_START (31)
#define SOC_ASP_CODEC_SRCDN_CTRL_voice_l_up_srcdn_fifo_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int dacl_mixer4_gain1 : 2;
        unsigned int dacl_mixer4_gain2 : 2;
        unsigned int dacl_mixer4_gain3 : 2;
        unsigned int dacl_mixer4_gain4 : 2;
        unsigned int dacl_mixer4_in1_mute : 1;
        unsigned int dacl_mixer4_in2_mute : 1;
        unsigned int dacl_mixer4_in3_mute : 1;
        unsigned int dacl_mixer4_in4_mute : 1;
        unsigned int dacl_mixer4_in1_id : 2;
        unsigned int dacl_mixer4_in2_id : 2;
        unsigned int dacl_mixer4_in3_id : 2;
        unsigned int dacl_mixer4_in4_id : 2;
    } reg;
} SOC_ASP_CODEC_DACL_MIXER4_CTRL0_UNION;
#endif
#define SOC_ASP_CODEC_DACL_MIXER4_CTRL0_dacl_mixer4_gain1_START (12)
#define SOC_ASP_CODEC_DACL_MIXER4_CTRL0_dacl_mixer4_gain1_END (13)
#define SOC_ASP_CODEC_DACL_MIXER4_CTRL0_dacl_mixer4_gain2_START (14)
#define SOC_ASP_CODEC_DACL_MIXER4_CTRL0_dacl_mixer4_gain2_END (15)
#define SOC_ASP_CODEC_DACL_MIXER4_CTRL0_dacl_mixer4_gain3_START (16)
#define SOC_ASP_CODEC_DACL_MIXER4_CTRL0_dacl_mixer4_gain3_END (17)
#define SOC_ASP_CODEC_DACL_MIXER4_CTRL0_dacl_mixer4_gain4_START (18)
#define SOC_ASP_CODEC_DACL_MIXER4_CTRL0_dacl_mixer4_gain4_END (19)
#define SOC_ASP_CODEC_DACL_MIXER4_CTRL0_dacl_mixer4_in1_mute_START (20)
#define SOC_ASP_CODEC_DACL_MIXER4_CTRL0_dacl_mixer4_in1_mute_END (20)
#define SOC_ASP_CODEC_DACL_MIXER4_CTRL0_dacl_mixer4_in2_mute_START (21)
#define SOC_ASP_CODEC_DACL_MIXER4_CTRL0_dacl_mixer4_in2_mute_END (21)
#define SOC_ASP_CODEC_DACL_MIXER4_CTRL0_dacl_mixer4_in3_mute_START (22)
#define SOC_ASP_CODEC_DACL_MIXER4_CTRL0_dacl_mixer4_in3_mute_END (22)
#define SOC_ASP_CODEC_DACL_MIXER4_CTRL0_dacl_mixer4_in4_mute_START (23)
#define SOC_ASP_CODEC_DACL_MIXER4_CTRL0_dacl_mixer4_in4_mute_END (23)
#define SOC_ASP_CODEC_DACL_MIXER4_CTRL0_dacl_mixer4_in1_id_START (24)
#define SOC_ASP_CODEC_DACL_MIXER4_CTRL0_dacl_mixer4_in1_id_END (25)
#define SOC_ASP_CODEC_DACL_MIXER4_CTRL0_dacl_mixer4_in2_id_START (26)
#define SOC_ASP_CODEC_DACL_MIXER4_CTRL0_dacl_mixer4_in2_id_END (27)
#define SOC_ASP_CODEC_DACL_MIXER4_CTRL0_dacl_mixer4_in3_id_START (28)
#define SOC_ASP_CODEC_DACL_MIXER4_CTRL0_dacl_mixer4_in3_id_END (29)
#define SOC_ASP_CODEC_DACL_MIXER4_CTRL0_dacl_mixer4_in4_id_START (30)
#define SOC_ASP_CODEC_DACL_MIXER4_CTRL0_dacl_mixer4_in4_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 16;
        unsigned int dacl_mixer4_zero_num : 5;
        unsigned int dacl_mixer4_fade_out : 5;
        unsigned int dacl_mixer4_fade_in : 5;
        unsigned int dacl_mixer4_fade_en : 1;
    } reg;
} SOC_ASP_CODEC_DACL_MIXER4_CTRL1_UNION;
#endif
#define SOC_ASP_CODEC_DACL_MIXER4_CTRL1_dacl_mixer4_zero_num_START (16)
#define SOC_ASP_CODEC_DACL_MIXER4_CTRL1_dacl_mixer4_zero_num_END (20)
#define SOC_ASP_CODEC_DACL_MIXER4_CTRL1_dacl_mixer4_fade_out_START (21)
#define SOC_ASP_CODEC_DACL_MIXER4_CTRL1_dacl_mixer4_fade_out_END (25)
#define SOC_ASP_CODEC_DACL_MIXER4_CTRL1_dacl_mixer4_fade_in_START (26)
#define SOC_ASP_CODEC_DACL_MIXER4_CTRL1_dacl_mixer4_fade_in_END (30)
#define SOC_ASP_CODEC_DACL_MIXER4_CTRL1_dacl_mixer4_fade_en_START (31)
#define SOC_ASP_CODEC_DACL_MIXER4_CTRL1_dacl_mixer4_fade_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int dacr_mixer4_gain1 : 2;
        unsigned int dacr_mixer4_gain2 : 2;
        unsigned int dacr_mixer4_gain3 : 2;
        unsigned int dacr_mixer4_gain4 : 2;
        unsigned int dacr_mixer4_in1_mute : 1;
        unsigned int dacr_mixer4_in2_mute : 1;
        unsigned int dacr_mixer4_in3_mute : 1;
        unsigned int dacr_mixer4_in4_mute : 1;
        unsigned int dacr_mixer4_in1_id : 2;
        unsigned int dacr_mixer4_in2_id : 2;
        unsigned int dacr_mixer4_in3_id : 2;
        unsigned int dacr_mixer4_in4_id : 2;
    } reg;
} SOC_ASP_CODEC_DACR_MIXER4_CTRL0_UNION;
#endif
#define SOC_ASP_CODEC_DACR_MIXER4_CTRL0_dacr_mixer4_gain1_START (12)
#define SOC_ASP_CODEC_DACR_MIXER4_CTRL0_dacr_mixer4_gain1_END (13)
#define SOC_ASP_CODEC_DACR_MIXER4_CTRL0_dacr_mixer4_gain2_START (14)
#define SOC_ASP_CODEC_DACR_MIXER4_CTRL0_dacr_mixer4_gain2_END (15)
#define SOC_ASP_CODEC_DACR_MIXER4_CTRL0_dacr_mixer4_gain3_START (16)
#define SOC_ASP_CODEC_DACR_MIXER4_CTRL0_dacr_mixer4_gain3_END (17)
#define SOC_ASP_CODEC_DACR_MIXER4_CTRL0_dacr_mixer4_gain4_START (18)
#define SOC_ASP_CODEC_DACR_MIXER4_CTRL0_dacr_mixer4_gain4_END (19)
#define SOC_ASP_CODEC_DACR_MIXER4_CTRL0_dacr_mixer4_in1_mute_START (20)
#define SOC_ASP_CODEC_DACR_MIXER4_CTRL0_dacr_mixer4_in1_mute_END (20)
#define SOC_ASP_CODEC_DACR_MIXER4_CTRL0_dacr_mixer4_in2_mute_START (21)
#define SOC_ASP_CODEC_DACR_MIXER4_CTRL0_dacr_mixer4_in2_mute_END (21)
#define SOC_ASP_CODEC_DACR_MIXER4_CTRL0_dacr_mixer4_in3_mute_START (22)
#define SOC_ASP_CODEC_DACR_MIXER4_CTRL0_dacr_mixer4_in3_mute_END (22)
#define SOC_ASP_CODEC_DACR_MIXER4_CTRL0_dacr_mixer4_in4_mute_START (23)
#define SOC_ASP_CODEC_DACR_MIXER4_CTRL0_dacr_mixer4_in4_mute_END (23)
#define SOC_ASP_CODEC_DACR_MIXER4_CTRL0_dacr_mixer4_in1_id_START (24)
#define SOC_ASP_CODEC_DACR_MIXER4_CTRL0_dacr_mixer4_in1_id_END (25)
#define SOC_ASP_CODEC_DACR_MIXER4_CTRL0_dacr_mixer4_in2_id_START (26)
#define SOC_ASP_CODEC_DACR_MIXER4_CTRL0_dacr_mixer4_in2_id_END (27)
#define SOC_ASP_CODEC_DACR_MIXER4_CTRL0_dacr_mixer4_in3_id_START (28)
#define SOC_ASP_CODEC_DACR_MIXER4_CTRL0_dacr_mixer4_in3_id_END (29)
#define SOC_ASP_CODEC_DACR_MIXER4_CTRL0_dacr_mixer4_in4_id_START (30)
#define SOC_ASP_CODEC_DACR_MIXER4_CTRL0_dacr_mixer4_in4_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 16;
        unsigned int dacr_mixer4_zero_num : 5;
        unsigned int dacr_mixer4_fade_out : 5;
        unsigned int dacr_mixer4_fade_in : 5;
        unsigned int dacr_mixer4_fade_en : 1;
    } reg;
} SOC_ASP_CODEC_DACR_MIXER4_CTRL1_UNION;
#endif
#define SOC_ASP_CODEC_DACR_MIXER4_CTRL1_dacr_mixer4_zero_num_START (16)
#define SOC_ASP_CODEC_DACR_MIXER4_CTRL1_dacr_mixer4_zero_num_END (20)
#define SOC_ASP_CODEC_DACR_MIXER4_CTRL1_dacr_mixer4_fade_out_START (21)
#define SOC_ASP_CODEC_DACR_MIXER4_CTRL1_dacr_mixer4_fade_out_END (25)
#define SOC_ASP_CODEC_DACR_MIXER4_CTRL1_dacr_mixer4_fade_in_START (26)
#define SOC_ASP_CODEC_DACR_MIXER4_CTRL1_dacr_mixer4_fade_in_END (30)
#define SOC_ASP_CODEC_DACR_MIXER4_CTRL1_dacr_mixer4_fade_en_START (31)
#define SOC_ASP_CODEC_DACR_MIXER4_CTRL1_dacr_mixer4_fade_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 6;
        unsigned int bt_tx_mixer2_zero_num : 5;
        unsigned int bt_tx_mixer2_fade_out : 5;
        unsigned int bt_tx_mixer2_fade_in : 5;
        unsigned int bt_tx_mixer2_fade_en : 1;
        unsigned int bt_tx_mixer2_gain1 : 2;
        unsigned int bt_tx_mixer2_gain2 : 2;
        unsigned int bt_tx_mixer2_in1_mute : 1;
        unsigned int bt_tx_mixer2_in2_mute : 1;
        unsigned int bt_tx_mixer2_in1_id : 2;
        unsigned int bt_tx_mixer2_in2_id : 2;
    } reg;
} SOC_ASP_CODEC_BT_TX_MIXER2_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_BT_TX_MIXER2_CTRL_bt_tx_mixer2_zero_num_START (6)
#define SOC_ASP_CODEC_BT_TX_MIXER2_CTRL_bt_tx_mixer2_zero_num_END (10)
#define SOC_ASP_CODEC_BT_TX_MIXER2_CTRL_bt_tx_mixer2_fade_out_START (11)
#define SOC_ASP_CODEC_BT_TX_MIXER2_CTRL_bt_tx_mixer2_fade_out_END (15)
#define SOC_ASP_CODEC_BT_TX_MIXER2_CTRL_bt_tx_mixer2_fade_in_START (16)
#define SOC_ASP_CODEC_BT_TX_MIXER2_CTRL_bt_tx_mixer2_fade_in_END (20)
#define SOC_ASP_CODEC_BT_TX_MIXER2_CTRL_bt_tx_mixer2_fade_en_START (21)
#define SOC_ASP_CODEC_BT_TX_MIXER2_CTRL_bt_tx_mixer2_fade_en_END (21)
#define SOC_ASP_CODEC_BT_TX_MIXER2_CTRL_bt_tx_mixer2_gain1_START (22)
#define SOC_ASP_CODEC_BT_TX_MIXER2_CTRL_bt_tx_mixer2_gain1_END (23)
#define SOC_ASP_CODEC_BT_TX_MIXER2_CTRL_bt_tx_mixer2_gain2_START (24)
#define SOC_ASP_CODEC_BT_TX_MIXER2_CTRL_bt_tx_mixer2_gain2_END (25)
#define SOC_ASP_CODEC_BT_TX_MIXER2_CTRL_bt_tx_mixer2_in1_mute_START (26)
#define SOC_ASP_CODEC_BT_TX_MIXER2_CTRL_bt_tx_mixer2_in1_mute_END (26)
#define SOC_ASP_CODEC_BT_TX_MIXER2_CTRL_bt_tx_mixer2_in2_mute_START (27)
#define SOC_ASP_CODEC_BT_TX_MIXER2_CTRL_bt_tx_mixer2_in2_mute_END (27)
#define SOC_ASP_CODEC_BT_TX_MIXER2_CTRL_bt_tx_mixer2_in1_id_START (28)
#define SOC_ASP_CODEC_BT_TX_MIXER2_CTRL_bt_tx_mixer2_in1_id_END (29)
#define SOC_ASP_CODEC_BT_TX_MIXER2_CTRL_bt_tx_mixer2_in2_id_START (30)
#define SOC_ASP_CODEC_BT_TX_MIXER2_CTRL_bt_tx_mixer2_in2_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 2;
        unsigned int sif_spa_adc_en : 1;
        unsigned int sif_spa_dac_en : 1;
        unsigned int sif_mst_dac_ultr_en : 1;
        unsigned int sif_mst_adc_edge_sel : 1;
        unsigned int sif_mst_dac_edge_sel : 1;
        unsigned int sif_mst_adc_mic3_en : 1;
        unsigned int sif_mst_adcl_en : 1;
        unsigned int sif_mst_adcr_en : 1;
        unsigned int sif_mst_dacl_en : 1;
        unsigned int sif_mst_dacr_en : 1;
        unsigned int sif_mst_p2s_loopback : 2;
        unsigned int sif_mst_s2p_loopback : 2;
        unsigned int sdm_r_calt_vld : 1;
        unsigned int sdm_r_dither : 1;
        unsigned int sdm_l_calt_vld : 1;
        unsigned int sdm_l_dither : 1;
        unsigned int reserved_1 : 8;
        unsigned int dacr_fir2d_bypass_en : 1;
        unsigned int dacr_fir2c_bypass_en : 1;
        unsigned int dacl_fir2d_bypass_en : 1;
        unsigned int dacl_fir2c_bypass_en : 1;
    } reg;
} SOC_ASP_CODEC_DAC_FILTER_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sif_spa_adc_en_START (2)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sif_spa_adc_en_END (2)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sif_spa_dac_en_START (3)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sif_spa_dac_en_END (3)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sif_mst_dac_ultr_en_START (4)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sif_mst_dac_ultr_en_END (4)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sif_mst_adc_edge_sel_START (5)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sif_mst_adc_edge_sel_END (5)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sif_mst_dac_edge_sel_START (6)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sif_mst_dac_edge_sel_END (6)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sif_mst_adc_mic3_en_START (7)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sif_mst_adc_mic3_en_END (7)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sif_mst_adcl_en_START (8)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sif_mst_adcl_en_END (8)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sif_mst_adcr_en_START (9)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sif_mst_adcr_en_END (9)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sif_mst_dacl_en_START (10)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sif_mst_dacl_en_END (10)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sif_mst_dacr_en_START (11)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sif_mst_dacr_en_END (11)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sif_mst_p2s_loopback_START (12)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sif_mst_p2s_loopback_END (13)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sif_mst_s2p_loopback_START (14)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sif_mst_s2p_loopback_END (15)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sdm_r_calt_vld_START (16)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sdm_r_calt_vld_END (16)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sdm_r_dither_START (17)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sdm_r_dither_END (17)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sdm_l_calt_vld_START (18)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sdm_l_calt_vld_END (18)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sdm_l_dither_START (19)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sdm_l_dither_END (19)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_dacr_fir2d_bypass_en_START (28)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_dacr_fir2d_bypass_en_END (28)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_dacr_fir2c_bypass_en_START (29)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_dacr_fir2c_bypass_en_END (29)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_dacl_fir2d_bypass_en_START (30)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_dacl_fir2d_bypass_en_END (30)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_dacl_fir2c_bypass_en_START (31)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_dacl_fir2c_bypass_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 2;
        unsigned int adc_mic3_hpf_bypass_en : 1;
        unsigned int adc_mic3_hbfvd_bypass_en : 1;
        unsigned int adc_mic3_hbf2d_bypass_en : 1;
        unsigned int adc_mic3_compd_bypass_en : 1;
        unsigned int adc_mic3_cic_gain : 6;
        unsigned int adcr_hpf_bypass_en : 1;
        unsigned int adcr_hbfvd_bypass_en : 1;
        unsigned int adcr_hbf2d_bypass_en : 1;
        unsigned int adcr_compd_bypass_en : 1;
        unsigned int adcr_cic_gain : 6;
        unsigned int adcl_hpf_bypass_en : 1;
        unsigned int adcl_hbfvd_bypass_en : 1;
        unsigned int adcl_hbf2d_bypass_en : 1;
        unsigned int adcl_compd_bypass_en : 1;
        unsigned int adcl_cic_gain : 6;
    } reg;
} SOC_ASP_CODEC_ADC_FILTER_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_ADC_FILTER_CTRL_adc_mic3_hpf_bypass_en_START (2)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL_adc_mic3_hpf_bypass_en_END (2)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL_adc_mic3_hbfvd_bypass_en_START (3)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL_adc_mic3_hbfvd_bypass_en_END (3)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL_adc_mic3_hbf2d_bypass_en_START (4)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL_adc_mic3_hbf2d_bypass_en_END (4)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL_adc_mic3_compd_bypass_en_START (5)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL_adc_mic3_compd_bypass_en_END (5)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL_adc_mic3_cic_gain_START (6)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL_adc_mic3_cic_gain_END (11)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL_adcr_hpf_bypass_en_START (12)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL_adcr_hpf_bypass_en_END (12)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL_adcr_hbfvd_bypass_en_START (13)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL_adcr_hbfvd_bypass_en_END (13)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL_adcr_hbf2d_bypass_en_START (14)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL_adcr_hbf2d_bypass_en_END (14)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL_adcr_compd_bypass_en_START (15)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL_adcr_compd_bypass_en_END (15)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL_adcr_cic_gain_START (16)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL_adcr_cic_gain_END (21)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL_adcl_hpf_bypass_en_START (22)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL_adcl_hpf_bypass_en_END (22)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL_adcl_hbfvd_bypass_en_START (23)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL_adcl_hbfvd_bypass_en_END (23)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL_adcl_hbf2d_bypass_en_START (24)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL_adcl_hbf2d_bypass_en_END (24)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL_adcl_compd_bypass_en_START (25)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL_adcl_compd_bypass_en_END (25)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL_adcl_cic_gain_START (26)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL_adcl_cic_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 5;
        unsigned int audio_r_dn_fifo_aempty_th : 5;
        unsigned int audio_r_dn_fifo_afull_th : 5;
        unsigned int audio_r_dn_fifo_clr : 1;
        unsigned int reserved_1 : 5;
        unsigned int audio_l_dn_fifo_aempty_th : 5;
        unsigned int audio_l_dn_fifo_afull_th : 5;
        unsigned int audio_l_dn_fifo_clr : 1;
    } reg;
} SOC_ASP_CODEC_AUDIO_DN_AFIFO_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_AUDIO_DN_AFIFO_CTRL_audio_r_dn_fifo_aempty_th_START (5)
#define SOC_ASP_CODEC_AUDIO_DN_AFIFO_CTRL_audio_r_dn_fifo_aempty_th_END (9)
#define SOC_ASP_CODEC_AUDIO_DN_AFIFO_CTRL_audio_r_dn_fifo_afull_th_START (10)
#define SOC_ASP_CODEC_AUDIO_DN_AFIFO_CTRL_audio_r_dn_fifo_afull_th_END (14)
#define SOC_ASP_CODEC_AUDIO_DN_AFIFO_CTRL_audio_r_dn_fifo_clr_START (15)
#define SOC_ASP_CODEC_AUDIO_DN_AFIFO_CTRL_audio_r_dn_fifo_clr_END (15)
#define SOC_ASP_CODEC_AUDIO_DN_AFIFO_CTRL_audio_l_dn_fifo_aempty_th_START (21)
#define SOC_ASP_CODEC_AUDIO_DN_AFIFO_CTRL_audio_l_dn_fifo_aempty_th_END (25)
#define SOC_ASP_CODEC_AUDIO_DN_AFIFO_CTRL_audio_l_dn_fifo_afull_th_START (26)
#define SOC_ASP_CODEC_AUDIO_DN_AFIFO_CTRL_audio_l_dn_fifo_afull_th_END (30)
#define SOC_ASP_CODEC_AUDIO_DN_AFIFO_CTRL_audio_l_dn_fifo_clr_START (31)
#define SOC_ASP_CODEC_AUDIO_DN_AFIFO_CTRL_audio_l_dn_fifo_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 5;
        unsigned int audio_r_up_fifo_aempty_th : 5;
        unsigned int audio_r_up_fifo_afull_th : 5;
        unsigned int audio_r_up_fifo_clr : 1;
        unsigned int reserved_1 : 5;
        unsigned int audio_l_up_fifo_aempty_th : 5;
        unsigned int audio_l_up_fifo_afull_th : 5;
        unsigned int audio_l_up_fifo_clr : 1;
    } reg;
} SOC_ASP_CODEC_AUDIO_UP_AFIFO_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_AUDIO_UP_AFIFO_CTRL_audio_r_up_fifo_aempty_th_START (5)
#define SOC_ASP_CODEC_AUDIO_UP_AFIFO_CTRL_audio_r_up_fifo_aempty_th_END (9)
#define SOC_ASP_CODEC_AUDIO_UP_AFIFO_CTRL_audio_r_up_fifo_afull_th_START (10)
#define SOC_ASP_CODEC_AUDIO_UP_AFIFO_CTRL_audio_r_up_fifo_afull_th_END (14)
#define SOC_ASP_CODEC_AUDIO_UP_AFIFO_CTRL_audio_r_up_fifo_clr_START (15)
#define SOC_ASP_CODEC_AUDIO_UP_AFIFO_CTRL_audio_r_up_fifo_clr_END (15)
#define SOC_ASP_CODEC_AUDIO_UP_AFIFO_CTRL_audio_l_up_fifo_aempty_th_START (21)
#define SOC_ASP_CODEC_AUDIO_UP_AFIFO_CTRL_audio_l_up_fifo_aempty_th_END (25)
#define SOC_ASP_CODEC_AUDIO_UP_AFIFO_CTRL_audio_l_up_fifo_afull_th_START (26)
#define SOC_ASP_CODEC_AUDIO_UP_AFIFO_CTRL_audio_l_up_fifo_afull_th_END (30)
#define SOC_ASP_CODEC_AUDIO_UP_AFIFO_CTRL_audio_l_up_fifo_clr_START (31)
#define SOC_ASP_CODEC_AUDIO_UP_AFIFO_CTRL_audio_l_up_fifo_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 5;
        unsigned int voice_r_up_fifo_aempty_th : 5;
        unsigned int voice_r_up_fifo_afull_th : 5;
        unsigned int voice_r_up_fifo_clr : 1;
        unsigned int reserved_1 : 5;
        unsigned int voice_l_up_fifo_aempty_th : 5;
        unsigned int voice_l_up_fifo_afull_th : 5;
        unsigned int voice_l_up_fifo_clr : 1;
    } reg;
} SOC_ASP_CODEC_VOICE_UP_AFIFO_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_VOICE_UP_AFIFO_CTRL_voice_r_up_fifo_aempty_th_START (5)
#define SOC_ASP_CODEC_VOICE_UP_AFIFO_CTRL_voice_r_up_fifo_aempty_th_END (9)
#define SOC_ASP_CODEC_VOICE_UP_AFIFO_CTRL_voice_r_up_fifo_afull_th_START (10)
#define SOC_ASP_CODEC_VOICE_UP_AFIFO_CTRL_voice_r_up_fifo_afull_th_END (14)
#define SOC_ASP_CODEC_VOICE_UP_AFIFO_CTRL_voice_r_up_fifo_clr_START (15)
#define SOC_ASP_CODEC_VOICE_UP_AFIFO_CTRL_voice_r_up_fifo_clr_END (15)
#define SOC_ASP_CODEC_VOICE_UP_AFIFO_CTRL_voice_l_up_fifo_aempty_th_START (21)
#define SOC_ASP_CODEC_VOICE_UP_AFIFO_CTRL_voice_l_up_fifo_aempty_th_END (25)
#define SOC_ASP_CODEC_VOICE_UP_AFIFO_CTRL_voice_l_up_fifo_afull_th_START (26)
#define SOC_ASP_CODEC_VOICE_UP_AFIFO_CTRL_voice_l_up_fifo_afull_th_END (30)
#define SOC_ASP_CODEC_VOICE_UP_AFIFO_CTRL_voice_l_up_fifo_clr_START (31)
#define SOC_ASP_CODEC_VOICE_UP_AFIFO_CTRL_voice_l_up_fifo_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 5;
        unsigned int echo_r_up_fifo_aempty_th : 5;
        unsigned int echo_r_up_fifo_afull_th : 5;
        unsigned int echo_r_up_fifo_clr : 1;
        unsigned int reserved_1 : 5;
        unsigned int echo_l_up_fifo_aempty_th : 5;
        unsigned int echo_l_up_fifo_afull_th : 5;
        unsigned int echo_l_up_fifo_clr : 1;
    } reg;
} SOC_ASP_CODEC_ECHO_UP_AFIFO_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_ECHO_UP_AFIFO_CTRL_echo_r_up_fifo_aempty_th_START (5)
#define SOC_ASP_CODEC_ECHO_UP_AFIFO_CTRL_echo_r_up_fifo_aempty_th_END (9)
#define SOC_ASP_CODEC_ECHO_UP_AFIFO_CTRL_echo_r_up_fifo_afull_th_START (10)
#define SOC_ASP_CODEC_ECHO_UP_AFIFO_CTRL_echo_r_up_fifo_afull_th_END (14)
#define SOC_ASP_CODEC_ECHO_UP_AFIFO_CTRL_echo_r_up_fifo_clr_START (15)
#define SOC_ASP_CODEC_ECHO_UP_AFIFO_CTRL_echo_r_up_fifo_clr_END (15)
#define SOC_ASP_CODEC_ECHO_UP_AFIFO_CTRL_echo_l_up_fifo_aempty_th_START (21)
#define SOC_ASP_CODEC_ECHO_UP_AFIFO_CTRL_echo_l_up_fifo_aempty_th_END (25)
#define SOC_ASP_CODEC_ECHO_UP_AFIFO_CTRL_echo_l_up_fifo_afull_th_START (26)
#define SOC_ASP_CODEC_ECHO_UP_AFIFO_CTRL_echo_l_up_fifo_afull_th_END (30)
#define SOC_ASP_CODEC_ECHO_UP_AFIFO_CTRL_echo_l_up_fifo_clr_START (31)
#define SOC_ASP_CODEC_ECHO_UP_AFIFO_CTRL_echo_l_up_fifo_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 5;
        unsigned int voice_r_dn_fifo_aempty_th : 5;
        unsigned int voice_r_dn_fifo_afull_th : 5;
        unsigned int voice_r_dn_fifo_clr : 1;
        unsigned int reserved_1 : 5;
        unsigned int voice_l_dn_fifo_aempty_th : 5;
        unsigned int voice_l_dn_fifo_afull_th : 5;
        unsigned int voice_l_dn_fifo_clr : 1;
    } reg;
} SOC_ASP_CODEC_VOICE_DN_AFIFO_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_VOICE_DN_AFIFO_CTRL_voice_r_dn_fifo_aempty_th_START (5)
#define SOC_ASP_CODEC_VOICE_DN_AFIFO_CTRL_voice_r_dn_fifo_aempty_th_END (9)
#define SOC_ASP_CODEC_VOICE_DN_AFIFO_CTRL_voice_r_dn_fifo_afull_th_START (10)
#define SOC_ASP_CODEC_VOICE_DN_AFIFO_CTRL_voice_r_dn_fifo_afull_th_END (14)
#define SOC_ASP_CODEC_VOICE_DN_AFIFO_CTRL_voice_r_dn_fifo_clr_START (15)
#define SOC_ASP_CODEC_VOICE_DN_AFIFO_CTRL_voice_r_dn_fifo_clr_END (15)
#define SOC_ASP_CODEC_VOICE_DN_AFIFO_CTRL_voice_l_dn_fifo_aempty_th_START (21)
#define SOC_ASP_CODEC_VOICE_DN_AFIFO_CTRL_voice_l_dn_fifo_aempty_th_END (25)
#define SOC_ASP_CODEC_VOICE_DN_AFIFO_CTRL_voice_l_dn_fifo_afull_th_START (26)
#define SOC_ASP_CODEC_VOICE_DN_AFIFO_CTRL_voice_l_dn_fifo_afull_th_END (30)
#define SOC_ASP_CODEC_VOICE_DN_AFIFO_CTRL_voice_l_dn_fifo_clr_START (31)
#define SOC_ASP_CODEC_VOICE_DN_AFIFO_CTRL_voice_l_dn_fifo_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 21;
        unsigned int mic3_up_fifo_aempty_th : 5;
        unsigned int mic3_up_fifo_afull_th : 5;
        unsigned int mic3_up_fifo_clr : 1;
    } reg;
} SOC_ASP_CODEC_MIC3_UP_AFIFO_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_MIC3_UP_AFIFO_CTRL_mic3_up_fifo_aempty_th_START (21)
#define SOC_ASP_CODEC_MIC3_UP_AFIFO_CTRL_mic3_up_fifo_aempty_th_END (25)
#define SOC_ASP_CODEC_MIC3_UP_AFIFO_CTRL_mic3_up_fifo_afull_th_START (26)
#define SOC_ASP_CODEC_MIC3_UP_AFIFO_CTRL_mic3_up_fifo_afull_th_END (30)
#define SOC_ASP_CODEC_MIC3_UP_AFIFO_CTRL_mic3_up_fifo_clr_START (31)
#define SOC_ASP_CODEC_MIC3_UP_AFIFO_CTRL_mic3_up_fifo_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mem_ctrl_d1w2r : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ASP_CODEC_MEM_CTRL_CFG_UNION;
#endif
#define SOC_ASP_CODEC_MEM_CTRL_CFG_mem_ctrl_d1w2r_START (0)
#define SOC_ASP_CODEC_MEM_CTRL_CFG_mem_ctrl_d1w2r_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 15;
        unsigned int bt_r_tx_srcdn_rdy : 1;
        unsigned int voice_r_dn_srcup_rdy : 1;
        unsigned int echo_r_up_srcdn_rdy : 1;
        unsigned int echo_l_up_srcdn_rdy : 1;
        unsigned int bt_tx_srcdn_rdy : 1;
        unsigned int bt_r_rx_srcdn_rdy : 1;
        unsigned int bt_l_rx_srcdn_rdy : 1;
        unsigned int bt_r_rx_srcup_rdy : 1;
        unsigned int bt_l_rx_srcup_rdy : 1;
        unsigned int mic3_up_srcdn_rdy : 1;
        unsigned int voice_r_up_srcdn_rdy : 1;
        unsigned int voice_l_up_srcdn_rdy : 1;
        unsigned int audio_r_up_srcup_rdy : 1;
        unsigned int audio_l_up_srcup_rdy : 1;
        unsigned int dacr_srcup_rdy : 1;
        unsigned int dacl_srcup_rdy : 1;
        unsigned int voice_l_dn_srcup_rdy : 1;
    } reg;
} SOC_ASP_CODEC_CODEC_STAT0_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_STAT0_bt_r_tx_srcdn_rdy_START (15)
#define SOC_ASP_CODEC_CODEC_STAT0_bt_r_tx_srcdn_rdy_END (15)
#define SOC_ASP_CODEC_CODEC_STAT0_voice_r_dn_srcup_rdy_START (16)
#define SOC_ASP_CODEC_CODEC_STAT0_voice_r_dn_srcup_rdy_END (16)
#define SOC_ASP_CODEC_CODEC_STAT0_echo_r_up_srcdn_rdy_START (17)
#define SOC_ASP_CODEC_CODEC_STAT0_echo_r_up_srcdn_rdy_END (17)
#define SOC_ASP_CODEC_CODEC_STAT0_echo_l_up_srcdn_rdy_START (18)
#define SOC_ASP_CODEC_CODEC_STAT0_echo_l_up_srcdn_rdy_END (18)
#define SOC_ASP_CODEC_CODEC_STAT0_bt_tx_srcdn_rdy_START (19)
#define SOC_ASP_CODEC_CODEC_STAT0_bt_tx_srcdn_rdy_END (19)
#define SOC_ASP_CODEC_CODEC_STAT0_bt_r_rx_srcdn_rdy_START (20)
#define SOC_ASP_CODEC_CODEC_STAT0_bt_r_rx_srcdn_rdy_END (20)
#define SOC_ASP_CODEC_CODEC_STAT0_bt_l_rx_srcdn_rdy_START (21)
#define SOC_ASP_CODEC_CODEC_STAT0_bt_l_rx_srcdn_rdy_END (21)
#define SOC_ASP_CODEC_CODEC_STAT0_bt_r_rx_srcup_rdy_START (22)
#define SOC_ASP_CODEC_CODEC_STAT0_bt_r_rx_srcup_rdy_END (22)
#define SOC_ASP_CODEC_CODEC_STAT0_bt_l_rx_srcup_rdy_START (23)
#define SOC_ASP_CODEC_CODEC_STAT0_bt_l_rx_srcup_rdy_END (23)
#define SOC_ASP_CODEC_CODEC_STAT0_mic3_up_srcdn_rdy_START (24)
#define SOC_ASP_CODEC_CODEC_STAT0_mic3_up_srcdn_rdy_END (24)
#define SOC_ASP_CODEC_CODEC_STAT0_voice_r_up_srcdn_rdy_START (25)
#define SOC_ASP_CODEC_CODEC_STAT0_voice_r_up_srcdn_rdy_END (25)
#define SOC_ASP_CODEC_CODEC_STAT0_voice_l_up_srcdn_rdy_START (26)
#define SOC_ASP_CODEC_CODEC_STAT0_voice_l_up_srcdn_rdy_END (26)
#define SOC_ASP_CODEC_CODEC_STAT0_audio_r_up_srcup_rdy_START (27)
#define SOC_ASP_CODEC_CODEC_STAT0_audio_r_up_srcup_rdy_END (27)
#define SOC_ASP_CODEC_CODEC_STAT0_audio_l_up_srcup_rdy_START (28)
#define SOC_ASP_CODEC_CODEC_STAT0_audio_l_up_srcup_rdy_END (28)
#define SOC_ASP_CODEC_CODEC_STAT0_dacr_srcup_rdy_START (29)
#define SOC_ASP_CODEC_CODEC_STAT0_dacr_srcup_rdy_END (29)
#define SOC_ASP_CODEC_CODEC_STAT0_dacl_srcup_rdy_START (30)
#define SOC_ASP_CODEC_CODEC_STAT0_dacl_srcup_rdy_END (30)
#define SOC_ASP_CODEC_CODEC_STAT0_voice_l_dn_srcup_rdy_START (31)
#define SOC_ASP_CODEC_CODEC_STAT0_voice_l_dn_srcup_rdy_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 5;
        unsigned int fs_audio_r_up_srcup_in : 2;
        unsigned int fs_audio_l_up_srcup_in : 2;
        unsigned int fs_dacr_srcup_in : 2;
        unsigned int fs_dacl_srcup_in : 2;
        unsigned int reserved_1 : 2;
        unsigned int fs_echo_r_uplink : 3;
        unsigned int fs_echo_l_uplink : 3;
        unsigned int fs_mic3_uplink : 3;
        unsigned int fs_voice_r_uplink : 2;
        unsigned int fs_voice_l_uplink : 2;
        unsigned int fs_audio_r_uplink : 1;
        unsigned int fs_audio_l_uplink : 1;
        unsigned int fs_voice_l_dlink : 2;
    } reg;
} SOC_ASP_CODEC_FS_CTRL0_UNION;
#endif
#define SOC_ASP_CODEC_FS_CTRL0_fs_audio_r_up_srcup_in_START (5)
#define SOC_ASP_CODEC_FS_CTRL0_fs_audio_r_up_srcup_in_END (6)
#define SOC_ASP_CODEC_FS_CTRL0_fs_audio_l_up_srcup_in_START (7)
#define SOC_ASP_CODEC_FS_CTRL0_fs_audio_l_up_srcup_in_END (8)
#define SOC_ASP_CODEC_FS_CTRL0_fs_dacr_srcup_in_START (9)
#define SOC_ASP_CODEC_FS_CTRL0_fs_dacr_srcup_in_END (10)
#define SOC_ASP_CODEC_FS_CTRL0_fs_dacl_srcup_in_START (11)
#define SOC_ASP_CODEC_FS_CTRL0_fs_dacl_srcup_in_END (12)
#define SOC_ASP_CODEC_FS_CTRL0_fs_echo_r_uplink_START (15)
#define SOC_ASP_CODEC_FS_CTRL0_fs_echo_r_uplink_END (17)
#define SOC_ASP_CODEC_FS_CTRL0_fs_echo_l_uplink_START (18)
#define SOC_ASP_CODEC_FS_CTRL0_fs_echo_l_uplink_END (20)
#define SOC_ASP_CODEC_FS_CTRL0_fs_mic3_uplink_START (21)
#define SOC_ASP_CODEC_FS_CTRL0_fs_mic3_uplink_END (23)
#define SOC_ASP_CODEC_FS_CTRL0_fs_voice_r_uplink_START (24)
#define SOC_ASP_CODEC_FS_CTRL0_fs_voice_r_uplink_END (25)
#define SOC_ASP_CODEC_FS_CTRL0_fs_voice_l_uplink_START (26)
#define SOC_ASP_CODEC_FS_CTRL0_fs_voice_l_uplink_END (27)
#define SOC_ASP_CODEC_FS_CTRL0_fs_audio_r_uplink_START (28)
#define SOC_ASP_CODEC_FS_CTRL0_fs_audio_r_uplink_END (28)
#define SOC_ASP_CODEC_FS_CTRL0_fs_audio_l_uplink_START (29)
#define SOC_ASP_CODEC_FS_CTRL0_fs_audio_l_uplink_END (29)
#define SOC_ASP_CODEC_FS_CTRL0_fs_voice_l_dlink_START (30)
#define SOC_ASP_CODEC_FS_CTRL0_fs_voice_l_dlink_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 10;
        unsigned int fs_echo_r_up_srcdn_out : 2;
        unsigned int fs_echo_l_up_srcdn_out : 2;
        unsigned int fs_mic3_up_srcdn_out : 2;
        unsigned int fs_voice_r_up_srcdn_out : 2;
        unsigned int fs_voice_l_up_srcdn_out : 2;
        unsigned int fs_bt_r_rx_srcup_out : 3;
        unsigned int fs_bt_r_rx_srcup_in : 3;
        unsigned int fs_bt_l_rx_srcup_out : 3;
        unsigned int fs_bt_l_rx_srcup_in : 3;
    } reg;
} SOC_ASP_CODEC_FS_CTRL1_UNION;
#endif
#define SOC_ASP_CODEC_FS_CTRL1_fs_echo_r_up_srcdn_out_START (10)
#define SOC_ASP_CODEC_FS_CTRL1_fs_echo_r_up_srcdn_out_END (11)
#define SOC_ASP_CODEC_FS_CTRL1_fs_echo_l_up_srcdn_out_START (12)
#define SOC_ASP_CODEC_FS_CTRL1_fs_echo_l_up_srcdn_out_END (13)
#define SOC_ASP_CODEC_FS_CTRL1_fs_mic3_up_srcdn_out_START (14)
#define SOC_ASP_CODEC_FS_CTRL1_fs_mic3_up_srcdn_out_END (15)
#define SOC_ASP_CODEC_FS_CTRL1_fs_voice_r_up_srcdn_out_START (16)
#define SOC_ASP_CODEC_FS_CTRL1_fs_voice_r_up_srcdn_out_END (17)
#define SOC_ASP_CODEC_FS_CTRL1_fs_voice_l_up_srcdn_out_START (18)
#define SOC_ASP_CODEC_FS_CTRL1_fs_voice_l_up_srcdn_out_END (19)
#define SOC_ASP_CODEC_FS_CTRL1_fs_bt_r_rx_srcup_out_START (20)
#define SOC_ASP_CODEC_FS_CTRL1_fs_bt_r_rx_srcup_out_END (22)
#define SOC_ASP_CODEC_FS_CTRL1_fs_bt_r_rx_srcup_in_START (23)
#define SOC_ASP_CODEC_FS_CTRL1_fs_bt_r_rx_srcup_in_END (25)
#define SOC_ASP_CODEC_FS_CTRL1_fs_bt_l_rx_srcup_out_START (26)
#define SOC_ASP_CODEC_FS_CTRL1_fs_bt_l_rx_srcup_out_END (28)
#define SOC_ASP_CODEC_FS_CTRL1_fs_bt_l_rx_srcup_in_START (29)
#define SOC_ASP_CODEC_FS_CTRL1_fs_bt_l_rx_srcup_in_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 5;
        unsigned int bm_26to24_echo_r_up_din_sel : 2;
        unsigned int bm_26to24_echo_l_up_din_sel : 2;
        unsigned int adc_mic3_din_sel : 2;
        unsigned int adcr_din_sel : 2;
        unsigned int adcl_din_sel : 2;
        unsigned int mic3_up_afifo_din_sel : 1;
        unsigned int bm_26to24_voice_r_up_din_sel : 1;
        unsigned int bm_26to24_voice_l_up_din_sel : 1;
        unsigned int audio_r_up_afifo_din_sel : 1;
        unsigned int audio_l_up_afifo_din_sel : 1;
        unsigned int bm_26to24_audio_r_up_din_sel : 2;
        unsigned int bm_26to24_audio_l_up_din_sel : 2;
        unsigned int sidetone_pga_din_sel : 2;
        unsigned int dacr_srcup_din_sel : 2;
        unsigned int dacl_srcup_din_sel : 2;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_ASP_CODEC_CODEC_DIN_MUX_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_DIN_MUX_bm_26to24_echo_r_up_din_sel_START (5)
#define SOC_ASP_CODEC_CODEC_DIN_MUX_bm_26to24_echo_r_up_din_sel_END (6)
#define SOC_ASP_CODEC_CODEC_DIN_MUX_bm_26to24_echo_l_up_din_sel_START (7)
#define SOC_ASP_CODEC_CODEC_DIN_MUX_bm_26to24_echo_l_up_din_sel_END (8)
#define SOC_ASP_CODEC_CODEC_DIN_MUX_adc_mic3_din_sel_START (9)
#define SOC_ASP_CODEC_CODEC_DIN_MUX_adc_mic3_din_sel_END (10)
#define SOC_ASP_CODEC_CODEC_DIN_MUX_adcr_din_sel_START (11)
#define SOC_ASP_CODEC_CODEC_DIN_MUX_adcr_din_sel_END (12)
#define SOC_ASP_CODEC_CODEC_DIN_MUX_adcl_din_sel_START (13)
#define SOC_ASP_CODEC_CODEC_DIN_MUX_adcl_din_sel_END (14)
#define SOC_ASP_CODEC_CODEC_DIN_MUX_mic3_up_afifo_din_sel_START (15)
#define SOC_ASP_CODEC_CODEC_DIN_MUX_mic3_up_afifo_din_sel_END (15)
#define SOC_ASP_CODEC_CODEC_DIN_MUX_bm_26to24_voice_r_up_din_sel_START (16)
#define SOC_ASP_CODEC_CODEC_DIN_MUX_bm_26to24_voice_r_up_din_sel_END (16)
#define SOC_ASP_CODEC_CODEC_DIN_MUX_bm_26to24_voice_l_up_din_sel_START (17)
#define SOC_ASP_CODEC_CODEC_DIN_MUX_bm_26to24_voice_l_up_din_sel_END (17)
#define SOC_ASP_CODEC_CODEC_DIN_MUX_audio_r_up_afifo_din_sel_START (18)
#define SOC_ASP_CODEC_CODEC_DIN_MUX_audio_r_up_afifo_din_sel_END (18)
#define SOC_ASP_CODEC_CODEC_DIN_MUX_audio_l_up_afifo_din_sel_START (19)
#define SOC_ASP_CODEC_CODEC_DIN_MUX_audio_l_up_afifo_din_sel_END (19)
#define SOC_ASP_CODEC_CODEC_DIN_MUX_bm_26to24_audio_r_up_din_sel_START (20)
#define SOC_ASP_CODEC_CODEC_DIN_MUX_bm_26to24_audio_r_up_din_sel_END (21)
#define SOC_ASP_CODEC_CODEC_DIN_MUX_bm_26to24_audio_l_up_din_sel_START (22)
#define SOC_ASP_CODEC_CODEC_DIN_MUX_bm_26to24_audio_l_up_din_sel_END (23)
#define SOC_ASP_CODEC_CODEC_DIN_MUX_sidetone_pga_din_sel_START (24)
#define SOC_ASP_CODEC_CODEC_DIN_MUX_sidetone_pga_din_sel_END (25)
#define SOC_ASP_CODEC_CODEC_DIN_MUX_dacr_srcup_din_sel_START (26)
#define SOC_ASP_CODEC_CODEC_DIN_MUX_dacr_srcup_din_sel_END (27)
#define SOC_ASP_CODEC_CODEC_DIN_MUX_dacl_srcup_din_sel_START (28)
#define SOC_ASP_CODEC_CODEC_DIN_MUX_dacl_srcup_din_sel_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dacl_dc_offset : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_CODEC_CODEC_DACL_DC_OFFSET_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_DACL_DC_OFFSET_dacl_dc_offset_START (0)
#define SOC_ASP_CODEC_CODEC_DACL_DC_OFFSET_dacl_dc_offset_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dacr_dc_offset : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_CODEC_CODEC_DACR_DC_OFFSET_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_DACR_DC_OFFSET_dacr_dc_offset_START (0)
#define SOC_ASP_CODEC_CODEC_DACR_DC_OFFSET_dacr_dc_offset_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int adcl_dc_offset : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_CODEC_CODEC_ADCL_DC_OFFSET_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_ADCL_DC_OFFSET_adcl_dc_offset_START (0)
#define SOC_ASP_CODEC_CODEC_ADCL_DC_OFFSET_adcl_dc_offset_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int adcr_dc_offset : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_CODEC_CODEC_ADCR_DC_OFFSET_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_ADCR_DC_OFFSET_adcr_dc_offset_START (0)
#define SOC_ASP_CODEC_CODEC_ADCR_DC_OFFSET_adcr_dc_offset_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int adc_mic3_dc_offset : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_CODEC_CODEC_ADC_MIC3_DC_OFFSET_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_ADC_MIC3_DC_OFFSET_adc_mic3_dc_offset_START (0)
#define SOC_ASP_CODEC_CODEC_ADC_MIC3_DC_OFFSET_adc_mic3_dc_offset_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fs_i2s3 : 3;
        unsigned int i2s3_if_tx_ena : 1;
        unsigned int i2s3_if_rx_ena : 1;
        unsigned int i2s3_mst_slv : 1;
        unsigned int i2s3_direct_loop : 2;
        unsigned int i2s3_func_mode : 3;
        unsigned int i2s3_frame_mode : 1;
        unsigned int i2s3_lrclk_mode : 1;
        unsigned int i2s3_chnnl_mode : 1;
        unsigned int i2s3_codec_data_format : 1;
        unsigned int reserved_0 : 1;
        unsigned int i2s3_codec_io_wordlength : 2;
        unsigned int i2s3_tx_clk_sel : 1;
        unsigned int i2s3_rx_clk_sel : 1;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_ASP_CODEC_I2S3_PCM_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_fs_i2s3_START (0)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_fs_i2s3_END (2)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_if_tx_ena_START (3)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_if_tx_ena_END (3)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_if_rx_ena_START (4)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_if_rx_ena_END (4)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_mst_slv_START (5)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_mst_slv_END (5)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_direct_loop_START (6)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_direct_loop_END (7)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_func_mode_START (8)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_func_mode_END (10)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_frame_mode_START (11)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_frame_mode_END (11)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_lrclk_mode_START (12)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_lrclk_mode_END (12)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_chnnl_mode_START (13)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_chnnl_mode_END (13)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_codec_data_format_START (14)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_codec_data_format_END (14)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_codec_io_wordlength_START (16)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_codec_io_wordlength_END (17)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_tx_clk_sel_START (18)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_tx_clk_sel_END (18)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_rx_clk_sel_START (19)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_rx_clk_sel_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 1;
        unsigned int voice_r_dn_pga_linear_sel : 1;
        unsigned int voice_r_dn_pga_zero_num : 5;
        unsigned int voice_r_dn_pga_thre_id : 2;
        unsigned int voice_r_dn_pga_noise_en : 1;
        unsigned int voice_r_dn_pga_bypass : 1;
        unsigned int voice_r_dn_pga_fade_out : 5;
        unsigned int voice_r_dn_pga_fade_in : 5;
        unsigned int voice_r_dn_pga_cfg : 3;
        unsigned int voice_r_dn_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_VOICE_R_DN_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_VOICE_R_DN_PGA_CTRL_voice_r_dn_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_VOICE_R_DN_PGA_CTRL_voice_r_dn_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_VOICE_R_DN_PGA_CTRL_voice_r_dn_pga_zero_num_START (2)
#define SOC_ASP_CODEC_VOICE_R_DN_PGA_CTRL_voice_r_dn_pga_zero_num_END (6)
#define SOC_ASP_CODEC_VOICE_R_DN_PGA_CTRL_voice_r_dn_pga_thre_id_START (7)
#define SOC_ASP_CODEC_VOICE_R_DN_PGA_CTRL_voice_r_dn_pga_thre_id_END (8)
#define SOC_ASP_CODEC_VOICE_R_DN_PGA_CTRL_voice_r_dn_pga_noise_en_START (9)
#define SOC_ASP_CODEC_VOICE_R_DN_PGA_CTRL_voice_r_dn_pga_noise_en_END (9)
#define SOC_ASP_CODEC_VOICE_R_DN_PGA_CTRL_voice_r_dn_pga_bypass_START (10)
#define SOC_ASP_CODEC_VOICE_R_DN_PGA_CTRL_voice_r_dn_pga_bypass_END (10)
#define SOC_ASP_CODEC_VOICE_R_DN_PGA_CTRL_voice_r_dn_pga_fade_out_START (11)
#define SOC_ASP_CODEC_VOICE_R_DN_PGA_CTRL_voice_r_dn_pga_fade_out_END (15)
#define SOC_ASP_CODEC_VOICE_R_DN_PGA_CTRL_voice_r_dn_pga_fade_in_START (16)
#define SOC_ASP_CODEC_VOICE_R_DN_PGA_CTRL_voice_r_dn_pga_fade_in_END (20)
#define SOC_ASP_CODEC_VOICE_R_DN_PGA_CTRL_voice_r_dn_pga_cfg_START (21)
#define SOC_ASP_CODEC_VOICE_R_DN_PGA_CTRL_voice_r_dn_pga_cfg_END (23)
#define SOC_ASP_CODEC_VOICE_R_DN_PGA_CTRL_voice_r_dn_pga_gain_START (24)
#define SOC_ASP_CODEC_VOICE_R_DN_PGA_CTRL_voice_r_dn_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 3;
        unsigned int codec3_r_dn_fifo_aempty_th : 6;
        unsigned int codec3_r_dn_fifo_afull_th : 6;
        unsigned int codec3_r_dn_fifo_clr : 1;
        unsigned int reserved_1 : 3;
        unsigned int codec3_l_dn_fifo_aempty_th : 6;
        unsigned int codec3_l_dn_fifo_afull_th : 6;
        unsigned int codec3_l_dn_fifo_clr : 1;
    } reg;
} SOC_ASP_CODEC_CODEC3_DN_AFIFO_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_CODEC3_DN_AFIFO_CTRL_codec3_r_dn_fifo_aempty_th_START (3)
#define SOC_ASP_CODEC_CODEC3_DN_AFIFO_CTRL_codec3_r_dn_fifo_aempty_th_END (8)
#define SOC_ASP_CODEC_CODEC3_DN_AFIFO_CTRL_codec3_r_dn_fifo_afull_th_START (9)
#define SOC_ASP_CODEC_CODEC3_DN_AFIFO_CTRL_codec3_r_dn_fifo_afull_th_END (14)
#define SOC_ASP_CODEC_CODEC3_DN_AFIFO_CTRL_codec3_r_dn_fifo_clr_START (15)
#define SOC_ASP_CODEC_CODEC3_DN_AFIFO_CTRL_codec3_r_dn_fifo_clr_END (15)
#define SOC_ASP_CODEC_CODEC3_DN_AFIFO_CTRL_codec3_l_dn_fifo_aempty_th_START (19)
#define SOC_ASP_CODEC_CODEC3_DN_AFIFO_CTRL_codec3_l_dn_fifo_aempty_th_END (24)
#define SOC_ASP_CODEC_CODEC3_DN_AFIFO_CTRL_codec3_l_dn_fifo_afull_th_START (25)
#define SOC_ASP_CODEC_CODEC3_DN_AFIFO_CTRL_codec3_l_dn_fifo_afull_th_END (30)
#define SOC_ASP_CODEC_CODEC3_DN_AFIFO_CTRL_codec3_l_dn_fifo_clr_START (31)
#define SOC_ASP_CODEC_CODEC3_DN_AFIFO_CTRL_codec3_l_dn_fifo_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fs_voice_r_dlink : 2;
        unsigned int fs_voice_r_dn_srcup_in : 2;
        unsigned int fs_codec3_r_dlink : 3;
        unsigned int reserved_0 : 1;
        unsigned int fs_codec3_l_dlink : 3;
        unsigned int fs_voice_l_dn_srcup_in : 2;
        unsigned int fs_voice_r_dn_srcup_dout : 2;
        unsigned int fs_voice_l_dn_srcup_dout : 2;
        unsigned int fs_bt_r_rx_srcdn_out : 3;
        unsigned int fs_bt_r_rx_srcdn_in : 3;
        unsigned int fs_bt_l_rx_srcdn_out : 3;
        unsigned int fs_bt_l_rx_srcdn_in : 3;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ASP_CODEC_FS_CTRL2_UNION;
#endif
#define SOC_ASP_CODEC_FS_CTRL2_fs_voice_r_dlink_START (0)
#define SOC_ASP_CODEC_FS_CTRL2_fs_voice_r_dlink_END (1)
#define SOC_ASP_CODEC_FS_CTRL2_fs_voice_r_dn_srcup_in_START (2)
#define SOC_ASP_CODEC_FS_CTRL2_fs_voice_r_dn_srcup_in_END (3)
#define SOC_ASP_CODEC_FS_CTRL2_fs_codec3_r_dlink_START (4)
#define SOC_ASP_CODEC_FS_CTRL2_fs_codec3_r_dlink_END (6)
#define SOC_ASP_CODEC_FS_CTRL2_fs_codec3_l_dlink_START (8)
#define SOC_ASP_CODEC_FS_CTRL2_fs_codec3_l_dlink_END (10)
#define SOC_ASP_CODEC_FS_CTRL2_fs_voice_l_dn_srcup_in_START (11)
#define SOC_ASP_CODEC_FS_CTRL2_fs_voice_l_dn_srcup_in_END (12)
#define SOC_ASP_CODEC_FS_CTRL2_fs_voice_r_dn_srcup_dout_START (13)
#define SOC_ASP_CODEC_FS_CTRL2_fs_voice_r_dn_srcup_dout_END (14)
#define SOC_ASP_CODEC_FS_CTRL2_fs_voice_l_dn_srcup_dout_START (15)
#define SOC_ASP_CODEC_FS_CTRL2_fs_voice_l_dn_srcup_dout_END (16)
#define SOC_ASP_CODEC_FS_CTRL2_fs_bt_r_rx_srcdn_out_START (17)
#define SOC_ASP_CODEC_FS_CTRL2_fs_bt_r_rx_srcdn_out_END (19)
#define SOC_ASP_CODEC_FS_CTRL2_fs_bt_r_rx_srcdn_in_START (20)
#define SOC_ASP_CODEC_FS_CTRL2_fs_bt_r_rx_srcdn_in_END (22)
#define SOC_ASP_CODEC_FS_CTRL2_fs_bt_l_rx_srcdn_out_START (23)
#define SOC_ASP_CODEC_FS_CTRL2_fs_bt_l_rx_srcdn_out_END (25)
#define SOC_ASP_CODEC_FS_CTRL2_fs_bt_l_rx_srcdn_in_START (26)
#define SOC_ASP_CODEC_FS_CTRL2_fs_bt_l_rx_srcdn_in_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int spa1_up_afifo_clken : 1;
        unsigned int spa2_up_afifo_clken : 1;
        unsigned int spa3_up_afifo_clken : 1;
        unsigned int spa4_up_afifo_clken : 1;
        unsigned int ultr_up_afifo_clken : 1;
        unsigned int ultr_dn_afifo_clken : 1;
        unsigned int ultr_dn_pga_clken : 1;
        unsigned int codec3_l_dn_pga_clken : 1;
        unsigned int codec3_r_dn_pga_clken : 1;
        unsigned int dacml_mixer2_clken : 1;
        unsigned int dacmr_mixer2_clken : 1;
        unsigned int ultr_mixer2_clken : 1;
        unsigned int dacml_clken : 1;
        unsigned int adc_ultr_clken : 1;
        unsigned int dacml_up16_clken : 1;
        unsigned int sdm_ultr_clken : 1;
        unsigned int bt_tx_l_srcdn_clken : 1;
        unsigned int dmic1_clken : 1;
        unsigned int dmic2_clken : 1;
        unsigned int bt_tx_r_srcdn_clken : 1;
        unsigned int classh_clken : 1;
        unsigned int adc_spi_clken : 1;
        unsigned int adc_spv_clken : 1;
        unsigned int reserved : 9;
    } reg;
} SOC_ASP_CODEC_CODEC_CLK_EN3_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_CLK_EN3_spa1_up_afifo_clken_START (0)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_spa1_up_afifo_clken_END (0)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_spa2_up_afifo_clken_START (1)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_spa2_up_afifo_clken_END (1)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_spa3_up_afifo_clken_START (2)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_spa3_up_afifo_clken_END (2)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_spa4_up_afifo_clken_START (3)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_spa4_up_afifo_clken_END (3)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_ultr_up_afifo_clken_START (4)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_ultr_up_afifo_clken_END (4)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_ultr_dn_afifo_clken_START (5)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_ultr_dn_afifo_clken_END (5)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_ultr_dn_pga_clken_START (6)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_ultr_dn_pga_clken_END (6)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_codec3_l_dn_pga_clken_START (7)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_codec3_l_dn_pga_clken_END (7)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_codec3_r_dn_pga_clken_START (8)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_codec3_r_dn_pga_clken_END (8)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_dacml_mixer2_clken_START (9)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_dacml_mixer2_clken_END (9)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_dacmr_mixer2_clken_START (10)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_dacmr_mixer2_clken_END (10)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_ultr_mixer2_clken_START (11)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_ultr_mixer2_clken_END (11)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_dacml_clken_START (12)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_dacml_clken_END (12)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc_ultr_clken_START (13)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc_ultr_clken_END (13)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_dacml_up16_clken_START (14)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_dacml_up16_clken_END (14)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_sdm_ultr_clken_START (15)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_sdm_ultr_clken_END (15)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_bt_tx_l_srcdn_clken_START (16)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_bt_tx_l_srcdn_clken_END (16)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_dmic1_clken_START (17)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_dmic1_clken_END (17)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_dmic2_clken_START (18)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_dmic2_clken_END (18)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_bt_tx_r_srcdn_clken_START (19)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_bt_tx_r_srcdn_clken_END (19)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_classh_clken_START (20)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_classh_clken_END (20)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc_spi_clken_START (21)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc_spi_clken_END (21)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc_spv_clken_START (22)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc_spv_clken_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ultr_dn_pga_gainoffset : 8;
        unsigned int codec3_r_dn_pga_gainoffset : 8;
        unsigned int codec3_l_dn_pga_gainoffset : 8;
        unsigned int mic4_up_pga_gain_offset : 8;
    } reg;
} SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL3_UNION;
#endif
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL3_ultr_dn_pga_gainoffset_START (0)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL3_ultr_dn_pga_gainoffset_END (7)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL3_codec3_r_dn_pga_gainoffset_START (8)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL3_codec3_r_dn_pga_gainoffset_END (15)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL3_codec3_l_dn_pga_gainoffset_START (16)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL3_codec3_l_dn_pga_gainoffset_END (23)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL3_mic4_up_pga_gain_offset_START (24)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL3_mic4_up_pga_gain_offset_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 1;
        unsigned int ultr_dn_pga_linear_sel : 1;
        unsigned int ultr_dn_pga_zero_num : 5;
        unsigned int ultr_dn_pga_thre_id : 2;
        unsigned int ultr_dn_pga_noise_en : 1;
        unsigned int ultr_dn_pga_bypass : 1;
        unsigned int ultr_dn_pga_fade_out : 5;
        unsigned int ultr_dn_pga_fade_in : 5;
        unsigned int ultr_dn_pga_cfg : 3;
        unsigned int ultr_dn_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ultr_dn_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ultr_dn_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ultr_dn_pga_zero_num_START (2)
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ultr_dn_pga_zero_num_END (6)
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ultr_dn_pga_thre_id_START (7)
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ultr_dn_pga_thre_id_END (8)
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ultr_dn_pga_noise_en_START (9)
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ultr_dn_pga_noise_en_END (9)
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ultr_dn_pga_bypass_START (10)
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ultr_dn_pga_bypass_END (10)
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ultr_dn_pga_fade_out_START (11)
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ultr_dn_pga_fade_out_END (15)
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ultr_dn_pga_fade_in_START (16)
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ultr_dn_pga_fade_in_END (20)
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ultr_dn_pga_cfg_START (21)
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ultr_dn_pga_cfg_END (23)
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ultr_dn_pga_gain_START (24)
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ultr_dn_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 1;
        unsigned int codec3_l_dn_pga_linear_sel : 1;
        unsigned int codec3_l_dn_pga_zero_num : 5;
        unsigned int codec3_l_dn_pga_thre_id : 2;
        unsigned int codec3_l_dn_pga_noise_en : 1;
        unsigned int codec3_l_dn_pga_bypass : 1;
        unsigned int codec3_l_dn_pga_fade_out : 5;
        unsigned int codec3_l_dn_pga_fade_in : 5;
        unsigned int codec3_l_dn_pga_cfg : 3;
        unsigned int codec3_l_dn_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_CODEC3_L_DN_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_CODEC3_L_DN_PGA_CTRL_codec3_l_dn_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_CODEC3_L_DN_PGA_CTRL_codec3_l_dn_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_CODEC3_L_DN_PGA_CTRL_codec3_l_dn_pga_zero_num_START (2)
#define SOC_ASP_CODEC_CODEC3_L_DN_PGA_CTRL_codec3_l_dn_pga_zero_num_END (6)
#define SOC_ASP_CODEC_CODEC3_L_DN_PGA_CTRL_codec3_l_dn_pga_thre_id_START (7)
#define SOC_ASP_CODEC_CODEC3_L_DN_PGA_CTRL_codec3_l_dn_pga_thre_id_END (8)
#define SOC_ASP_CODEC_CODEC3_L_DN_PGA_CTRL_codec3_l_dn_pga_noise_en_START (9)
#define SOC_ASP_CODEC_CODEC3_L_DN_PGA_CTRL_codec3_l_dn_pga_noise_en_END (9)
#define SOC_ASP_CODEC_CODEC3_L_DN_PGA_CTRL_codec3_l_dn_pga_bypass_START (10)
#define SOC_ASP_CODEC_CODEC3_L_DN_PGA_CTRL_codec3_l_dn_pga_bypass_END (10)
#define SOC_ASP_CODEC_CODEC3_L_DN_PGA_CTRL_codec3_l_dn_pga_fade_out_START (11)
#define SOC_ASP_CODEC_CODEC3_L_DN_PGA_CTRL_codec3_l_dn_pga_fade_out_END (15)
#define SOC_ASP_CODEC_CODEC3_L_DN_PGA_CTRL_codec3_l_dn_pga_fade_in_START (16)
#define SOC_ASP_CODEC_CODEC3_L_DN_PGA_CTRL_codec3_l_dn_pga_fade_in_END (20)
#define SOC_ASP_CODEC_CODEC3_L_DN_PGA_CTRL_codec3_l_dn_pga_cfg_START (21)
#define SOC_ASP_CODEC_CODEC3_L_DN_PGA_CTRL_codec3_l_dn_pga_cfg_END (23)
#define SOC_ASP_CODEC_CODEC3_L_DN_PGA_CTRL_codec3_l_dn_pga_gain_START (24)
#define SOC_ASP_CODEC_CODEC3_L_DN_PGA_CTRL_codec3_l_dn_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 1;
        unsigned int codec3_r_dn_pga_linear_sel : 1;
        unsigned int codec3_r_dn_pga_zero_num : 5;
        unsigned int codec3_r_dn_pga_thre_id : 2;
        unsigned int codec3_r_dn_pga_noise_en : 1;
        unsigned int codec3_r_dn_pga_bypass : 1;
        unsigned int codec3_r_dn_pga_fade_out : 5;
        unsigned int codec3_r_dn_pga_fade_in : 5;
        unsigned int codec3_r_dn_pga_cfg : 3;
        unsigned int codec3_r_dn_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_CODEC3_R_DN_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_CODEC3_R_DN_PGA_CTRL_codec3_r_dn_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_CODEC3_R_DN_PGA_CTRL_codec3_r_dn_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_CODEC3_R_DN_PGA_CTRL_codec3_r_dn_pga_zero_num_START (2)
#define SOC_ASP_CODEC_CODEC3_R_DN_PGA_CTRL_codec3_r_dn_pga_zero_num_END (6)
#define SOC_ASP_CODEC_CODEC3_R_DN_PGA_CTRL_codec3_r_dn_pga_thre_id_START (7)
#define SOC_ASP_CODEC_CODEC3_R_DN_PGA_CTRL_codec3_r_dn_pga_thre_id_END (8)
#define SOC_ASP_CODEC_CODEC3_R_DN_PGA_CTRL_codec3_r_dn_pga_noise_en_START (9)
#define SOC_ASP_CODEC_CODEC3_R_DN_PGA_CTRL_codec3_r_dn_pga_noise_en_END (9)
#define SOC_ASP_CODEC_CODEC3_R_DN_PGA_CTRL_codec3_r_dn_pga_bypass_START (10)
#define SOC_ASP_CODEC_CODEC3_R_DN_PGA_CTRL_codec3_r_dn_pga_bypass_END (10)
#define SOC_ASP_CODEC_CODEC3_R_DN_PGA_CTRL_codec3_r_dn_pga_fade_out_START (11)
#define SOC_ASP_CODEC_CODEC3_R_DN_PGA_CTRL_codec3_r_dn_pga_fade_out_END (15)
#define SOC_ASP_CODEC_CODEC3_R_DN_PGA_CTRL_codec3_r_dn_pga_fade_in_START (16)
#define SOC_ASP_CODEC_CODEC3_R_DN_PGA_CTRL_codec3_r_dn_pga_fade_in_END (20)
#define SOC_ASP_CODEC_CODEC3_R_DN_PGA_CTRL_codec3_r_dn_pga_cfg_START (21)
#define SOC_ASP_CODEC_CODEC3_R_DN_PGA_CTRL_codec3_r_dn_pga_cfg_END (23)
#define SOC_ASP_CODEC_CODEC3_R_DN_PGA_CTRL_codec3_r_dn_pga_gain_START (24)
#define SOC_ASP_CODEC_CODEC3_R_DN_PGA_CTRL_codec3_r_dn_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bt_tx_r_srcdn_src_mode : 3;
        unsigned int bt_tx_r_srcdn_fifo_clr : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_ASP_CODEC_SRCDN_CTRL1_UNION;
#endif
#define SOC_ASP_CODEC_SRCDN_CTRL1_bt_tx_r_srcdn_src_mode_START (0)
#define SOC_ASP_CODEC_SRCDN_CTRL1_bt_tx_r_srcdn_src_mode_END (2)
#define SOC_ASP_CODEC_SRCDN_CTRL1_bt_tx_r_srcdn_fifo_clr_START (3)
#define SOC_ASP_CODEC_SRCDN_CTRL1_bt_tx_r_srcdn_fifo_clr_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 6;
        unsigned int ultr_mixer2_zero_num : 5;
        unsigned int ultr_mixer2_fade_out : 5;
        unsigned int ultr_mixer2_fade_in : 5;
        unsigned int ultr_mixer2_fade_en : 1;
        unsigned int ultr_mixer2_gain1 : 2;
        unsigned int ultr_mixer2_gain2 : 2;
        unsigned int ultr_mixer2_in1_mute : 1;
        unsigned int ultr_mixer2_in2_mute : 1;
        unsigned int ultr_mixer2_in1_id : 2;
        unsigned int ultr_mixer2_in2_id : 2;
    } reg;
} SOC_ASP_CODEC_ULTR_MIXER2_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_ULTR_MIXER2_CTRL_ultr_mixer2_zero_num_START (6)
#define SOC_ASP_CODEC_ULTR_MIXER2_CTRL_ultr_mixer2_zero_num_END (10)
#define SOC_ASP_CODEC_ULTR_MIXER2_CTRL_ultr_mixer2_fade_out_START (11)
#define SOC_ASP_CODEC_ULTR_MIXER2_CTRL_ultr_mixer2_fade_out_END (15)
#define SOC_ASP_CODEC_ULTR_MIXER2_CTRL_ultr_mixer2_fade_in_START (16)
#define SOC_ASP_CODEC_ULTR_MIXER2_CTRL_ultr_mixer2_fade_in_END (20)
#define SOC_ASP_CODEC_ULTR_MIXER2_CTRL_ultr_mixer2_fade_en_START (21)
#define SOC_ASP_CODEC_ULTR_MIXER2_CTRL_ultr_mixer2_fade_en_END (21)
#define SOC_ASP_CODEC_ULTR_MIXER2_CTRL_ultr_mixer2_gain1_START (22)
#define SOC_ASP_CODEC_ULTR_MIXER2_CTRL_ultr_mixer2_gain1_END (23)
#define SOC_ASP_CODEC_ULTR_MIXER2_CTRL_ultr_mixer2_gain2_START (24)
#define SOC_ASP_CODEC_ULTR_MIXER2_CTRL_ultr_mixer2_gain2_END (25)
#define SOC_ASP_CODEC_ULTR_MIXER2_CTRL_ultr_mixer2_in1_mute_START (26)
#define SOC_ASP_CODEC_ULTR_MIXER2_CTRL_ultr_mixer2_in1_mute_END (26)
#define SOC_ASP_CODEC_ULTR_MIXER2_CTRL_ultr_mixer2_in2_mute_START (27)
#define SOC_ASP_CODEC_ULTR_MIXER2_CTRL_ultr_mixer2_in2_mute_END (27)
#define SOC_ASP_CODEC_ULTR_MIXER2_CTRL_ultr_mixer2_in1_id_START (28)
#define SOC_ASP_CODEC_ULTR_MIXER2_CTRL_ultr_mixer2_in1_id_END (29)
#define SOC_ASP_CODEC_ULTR_MIXER2_CTRL_ultr_mixer2_in2_id_START (30)
#define SOC_ASP_CODEC_ULTR_MIXER2_CTRL_ultr_mixer2_in2_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 6;
        unsigned int dacml_mixer2_zero_num : 5;
        unsigned int dacml_mixer2_fade_out : 5;
        unsigned int dacml_mixer2_fade_in : 5;
        unsigned int dacml_mixer2_fade_en : 1;
        unsigned int dacml_mixer2_gain1 : 2;
        unsigned int dacml_mixer2_gain2 : 2;
        unsigned int dacml_mixer2_in1_mute : 1;
        unsigned int dacml_mixer2_in2_mute : 1;
        unsigned int dacml_mixer2_in1_id : 2;
        unsigned int dacml_mixer2_in2_id : 2;
    } reg;
} SOC_ASP_CODEC_DACML_MIXER2_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_DACML_MIXER2_CTRL_dacml_mixer2_zero_num_START (6)
#define SOC_ASP_CODEC_DACML_MIXER2_CTRL_dacml_mixer2_zero_num_END (10)
#define SOC_ASP_CODEC_DACML_MIXER2_CTRL_dacml_mixer2_fade_out_START (11)
#define SOC_ASP_CODEC_DACML_MIXER2_CTRL_dacml_mixer2_fade_out_END (15)
#define SOC_ASP_CODEC_DACML_MIXER2_CTRL_dacml_mixer2_fade_in_START (16)
#define SOC_ASP_CODEC_DACML_MIXER2_CTRL_dacml_mixer2_fade_in_END (20)
#define SOC_ASP_CODEC_DACML_MIXER2_CTRL_dacml_mixer2_fade_en_START (21)
#define SOC_ASP_CODEC_DACML_MIXER2_CTRL_dacml_mixer2_fade_en_END (21)
#define SOC_ASP_CODEC_DACML_MIXER2_CTRL_dacml_mixer2_gain1_START (22)
#define SOC_ASP_CODEC_DACML_MIXER2_CTRL_dacml_mixer2_gain1_END (23)
#define SOC_ASP_CODEC_DACML_MIXER2_CTRL_dacml_mixer2_gain2_START (24)
#define SOC_ASP_CODEC_DACML_MIXER2_CTRL_dacml_mixer2_gain2_END (25)
#define SOC_ASP_CODEC_DACML_MIXER2_CTRL_dacml_mixer2_in1_mute_START (26)
#define SOC_ASP_CODEC_DACML_MIXER2_CTRL_dacml_mixer2_in1_mute_END (26)
#define SOC_ASP_CODEC_DACML_MIXER2_CTRL_dacml_mixer2_in2_mute_START (27)
#define SOC_ASP_CODEC_DACML_MIXER2_CTRL_dacml_mixer2_in2_mute_END (27)
#define SOC_ASP_CODEC_DACML_MIXER2_CTRL_dacml_mixer2_in1_id_START (28)
#define SOC_ASP_CODEC_DACML_MIXER2_CTRL_dacml_mixer2_in1_id_END (29)
#define SOC_ASP_CODEC_DACML_MIXER2_CTRL_dacml_mixer2_in2_id_START (30)
#define SOC_ASP_CODEC_DACML_MIXER2_CTRL_dacml_mixer2_in2_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 6;
        unsigned int dacmr_mixer2_zero_num : 5;
        unsigned int dacmr_mixer2_fade_out : 5;
        unsigned int dacmr_mixer2_fade_in : 5;
        unsigned int dacmr_mixer2_fade_en : 1;
        unsigned int dacmr_mixer2_gain1 : 2;
        unsigned int dacmr_mixer2_gain2 : 2;
        unsigned int dacmr_mixer2_in1_mute : 1;
        unsigned int dacmr_mixer2_in2_mute : 1;
        unsigned int dacmr_mixer2_in1_id : 2;
        unsigned int dacmr_mixer2_in2_id : 2;
    } reg;
} SOC_ASP_CODEC_DACMR_MIXER2_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_DACMR_MIXER2_CTRL_dacmr_mixer2_zero_num_START (6)
#define SOC_ASP_CODEC_DACMR_MIXER2_CTRL_dacmr_mixer2_zero_num_END (10)
#define SOC_ASP_CODEC_DACMR_MIXER2_CTRL_dacmr_mixer2_fade_out_START (11)
#define SOC_ASP_CODEC_DACMR_MIXER2_CTRL_dacmr_mixer2_fade_out_END (15)
#define SOC_ASP_CODEC_DACMR_MIXER2_CTRL_dacmr_mixer2_fade_in_START (16)
#define SOC_ASP_CODEC_DACMR_MIXER2_CTRL_dacmr_mixer2_fade_in_END (20)
#define SOC_ASP_CODEC_DACMR_MIXER2_CTRL_dacmr_mixer2_fade_en_START (21)
#define SOC_ASP_CODEC_DACMR_MIXER2_CTRL_dacmr_mixer2_fade_en_END (21)
#define SOC_ASP_CODEC_DACMR_MIXER2_CTRL_dacmr_mixer2_gain1_START (22)
#define SOC_ASP_CODEC_DACMR_MIXER2_CTRL_dacmr_mixer2_gain1_END (23)
#define SOC_ASP_CODEC_DACMR_MIXER2_CTRL_dacmr_mixer2_gain2_START (24)
#define SOC_ASP_CODEC_DACMR_MIXER2_CTRL_dacmr_mixer2_gain2_END (25)
#define SOC_ASP_CODEC_DACMR_MIXER2_CTRL_dacmr_mixer2_in1_mute_START (26)
#define SOC_ASP_CODEC_DACMR_MIXER2_CTRL_dacmr_mixer2_in1_mute_END (26)
#define SOC_ASP_CODEC_DACMR_MIXER2_CTRL_dacmr_mixer2_in2_mute_START (27)
#define SOC_ASP_CODEC_DACMR_MIXER2_CTRL_dacmr_mixer2_in2_mute_END (27)
#define SOC_ASP_CODEC_DACMR_MIXER2_CTRL_dacmr_mixer2_in1_id_START (28)
#define SOC_ASP_CODEC_DACMR_MIXER2_CTRL_dacmr_mixer2_in1_id_END (29)
#define SOC_ASP_CODEC_DACMR_MIXER2_CTRL_dacmr_mixer2_in2_id_START (30)
#define SOC_ASP_CODEC_DACMR_MIXER2_CTRL_dacmr_mixer2_in2_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 18;
        unsigned int sdm_ultr_calt_vld : 1;
        unsigned int sdm_ultr_dither : 1;
        unsigned int reserved_1 : 8;
        unsigned int dacml_hbf1i_bypass_en : 1;
        unsigned int dacml_hbf2i_bypass_en : 1;
        unsigned int dacml_compi_bypass_en : 1;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_ASP_CODEC_DACML_FILTER_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_DACML_FILTER_CTRL_sdm_ultr_calt_vld_START (18)
#define SOC_ASP_CODEC_DACML_FILTER_CTRL_sdm_ultr_calt_vld_END (18)
#define SOC_ASP_CODEC_DACML_FILTER_CTRL_sdm_ultr_dither_START (19)
#define SOC_ASP_CODEC_DACML_FILTER_CTRL_sdm_ultr_dither_END (19)
#define SOC_ASP_CODEC_DACML_FILTER_CTRL_dacml_hbf1i_bypass_en_START (28)
#define SOC_ASP_CODEC_DACML_FILTER_CTRL_dacml_hbf1i_bypass_en_END (28)
#define SOC_ASP_CODEC_DACML_FILTER_CTRL_dacml_hbf2i_bypass_en_START (29)
#define SOC_ASP_CODEC_DACML_FILTER_CTRL_dacml_hbf2i_bypass_en_END (29)
#define SOC_ASP_CODEC_DACML_FILTER_CTRL_dacml_compi_bypass_en_START (30)
#define SOC_ASP_CODEC_DACML_FILTER_CTRL_dacml_compi_bypass_en_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 2;
        unsigned int adc_ultr_hpf_bypass_en : 1;
        unsigned int adc_ultr_hbfvd_bypass_en : 1;
        unsigned int adc_ultr_hbf2d_bypass_en : 1;
        unsigned int adc_ultr_compd_bypass_en : 1;
        unsigned int adc_ultr_cic_gain : 6;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_ASP_CODEC_ADC_ULTR_FILTER_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_ADC_ULTR_FILTER_CTRL_adc_ultr_hpf_bypass_en_START (2)
#define SOC_ASP_CODEC_ADC_ULTR_FILTER_CTRL_adc_ultr_hpf_bypass_en_END (2)
#define SOC_ASP_CODEC_ADC_ULTR_FILTER_CTRL_adc_ultr_hbfvd_bypass_en_START (3)
#define SOC_ASP_CODEC_ADC_ULTR_FILTER_CTRL_adc_ultr_hbfvd_bypass_en_END (3)
#define SOC_ASP_CODEC_ADC_ULTR_FILTER_CTRL_adc_ultr_hbf2d_bypass_en_START (4)
#define SOC_ASP_CODEC_ADC_ULTR_FILTER_CTRL_adc_ultr_hbf2d_bypass_en_END (4)
#define SOC_ASP_CODEC_ADC_ULTR_FILTER_CTRL_adc_ultr_compd_bypass_en_START (5)
#define SOC_ASP_CODEC_ADC_ULTR_FILTER_CTRL_adc_ultr_compd_bypass_en_END (5)
#define SOC_ASP_CODEC_ADC_ULTR_FILTER_CTRL_adc_ultr_cic_gain_START (6)
#define SOC_ASP_CODEC_ADC_ULTR_FILTER_CTRL_adc_ultr_cic_gain_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dmic1_sw_dmic_mode : 1;
        unsigned int dmic1_reverse : 1;
        unsigned int dmic2_sw_dmic_mode : 1;
        unsigned int dmic2_reverse : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_ASP_CODEC_DMIC_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_DMIC_CTRL_dmic1_sw_dmic_mode_START (0)
#define SOC_ASP_CODEC_DMIC_CTRL_dmic1_sw_dmic_mode_END (0)
#define SOC_ASP_CODEC_DMIC_CTRL_dmic1_reverse_START (1)
#define SOC_ASP_CODEC_DMIC_CTRL_dmic1_reverse_END (1)
#define SOC_ASP_CODEC_DMIC_CTRL_dmic2_sw_dmic_mode_START (2)
#define SOC_ASP_CODEC_DMIC_CTRL_dmic2_sw_dmic_mode_END (2)
#define SOC_ASP_CODEC_DMIC_CTRL_dmic2_reverse_START (3)
#define SOC_ASP_CODEC_DMIC_CTRL_dmic2_reverse_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fs_dmic1 : 4;
        unsigned int fs_dmic2 : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_ASP_CODEC_DMIC_DIV_UNION;
#endif
#define SOC_ASP_CODEC_DMIC_DIV_fs_dmic1_START (0)
#define SOC_ASP_CODEC_DMIC_DIV_fs_dmic1_END (3)
#define SOC_ASP_CODEC_DMIC_DIV_fs_dmic2_START (4)
#define SOC_ASP_CODEC_DMIC_DIV_fs_dmic2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dacml_dc_offset : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_CODEC_CODEC_DACML_DC_OFFSET_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_DACML_DC_OFFSET_dacml_dc_offset_START (0)
#define SOC_ASP_CODEC_CODEC_DACML_DC_OFFSET_dacml_dc_offset_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int adc_ultr_dc_offset : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_CODEC_CODEC_ADC_ULTR_DC_OFFSET_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_ADC_ULTR_DC_OFFSET_adc_ultr_dc_offset_START (0)
#define SOC_ASP_CODEC_CODEC_ADC_ULTR_DC_OFFSET_adc_ultr_dc_offset_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 5;
        unsigned int spa1_up_fifo_aempty_th : 5;
        unsigned int spa1_up_fifo_afull_th : 5;
        unsigned int spa1_up_fifo_clr : 1;
        unsigned int reserved_1 : 5;
        unsigned int spa2_up_fifo_aempty_th : 5;
        unsigned int spa2_up_fifo_afull_th : 5;
        unsigned int spa2_up_fifo_clr : 1;
    } reg;
} SOC_ASP_CODEC_SPA12_UP_AFIFO_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_SPA12_UP_AFIFO_CTRL_spa1_up_fifo_aempty_th_START (5)
#define SOC_ASP_CODEC_SPA12_UP_AFIFO_CTRL_spa1_up_fifo_aempty_th_END (9)
#define SOC_ASP_CODEC_SPA12_UP_AFIFO_CTRL_spa1_up_fifo_afull_th_START (10)
#define SOC_ASP_CODEC_SPA12_UP_AFIFO_CTRL_spa1_up_fifo_afull_th_END (14)
#define SOC_ASP_CODEC_SPA12_UP_AFIFO_CTRL_spa1_up_fifo_clr_START (15)
#define SOC_ASP_CODEC_SPA12_UP_AFIFO_CTRL_spa1_up_fifo_clr_END (15)
#define SOC_ASP_CODEC_SPA12_UP_AFIFO_CTRL_spa2_up_fifo_aempty_th_START (21)
#define SOC_ASP_CODEC_SPA12_UP_AFIFO_CTRL_spa2_up_fifo_aempty_th_END (25)
#define SOC_ASP_CODEC_SPA12_UP_AFIFO_CTRL_spa2_up_fifo_afull_th_START (26)
#define SOC_ASP_CODEC_SPA12_UP_AFIFO_CTRL_spa2_up_fifo_afull_th_END (30)
#define SOC_ASP_CODEC_SPA12_UP_AFIFO_CTRL_spa2_up_fifo_clr_START (31)
#define SOC_ASP_CODEC_SPA12_UP_AFIFO_CTRL_spa2_up_fifo_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 5;
        unsigned int spa3_up_fifo_aempty_th : 5;
        unsigned int spa3_up_fifo_afull_th : 5;
        unsigned int spa3_up_fifo_clr : 1;
        unsigned int reserved_1 : 5;
        unsigned int spa4_up_fifo_aempty_th : 5;
        unsigned int spa4_up_fifo_afull_th : 5;
        unsigned int spa4_up_fifo_clr : 1;
    } reg;
} SOC_ASP_CODEC_SPA34_UP_AFIFO_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_SPA34_UP_AFIFO_CTRL_spa3_up_fifo_aempty_th_START (5)
#define SOC_ASP_CODEC_SPA34_UP_AFIFO_CTRL_spa3_up_fifo_aempty_th_END (9)
#define SOC_ASP_CODEC_SPA34_UP_AFIFO_CTRL_spa3_up_fifo_afull_th_START (10)
#define SOC_ASP_CODEC_SPA34_UP_AFIFO_CTRL_spa3_up_fifo_afull_th_END (14)
#define SOC_ASP_CODEC_SPA34_UP_AFIFO_CTRL_spa3_up_fifo_clr_START (15)
#define SOC_ASP_CODEC_SPA34_UP_AFIFO_CTRL_spa3_up_fifo_clr_END (15)
#define SOC_ASP_CODEC_SPA34_UP_AFIFO_CTRL_spa4_up_fifo_aempty_th_START (21)
#define SOC_ASP_CODEC_SPA34_UP_AFIFO_CTRL_spa4_up_fifo_aempty_th_END (25)
#define SOC_ASP_CODEC_SPA34_UP_AFIFO_CTRL_spa4_up_fifo_afull_th_START (26)
#define SOC_ASP_CODEC_SPA34_UP_AFIFO_CTRL_spa4_up_fifo_afull_th_END (30)
#define SOC_ASP_CODEC_SPA34_UP_AFIFO_CTRL_spa4_up_fifo_clr_START (31)
#define SOC_ASP_CODEC_SPA34_UP_AFIFO_CTRL_spa4_up_fifo_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 5;
        unsigned int ultr_up_fifo_aempty_th : 5;
        unsigned int ultr_up_fifo_afull_th : 5;
        unsigned int ultr_up_fifo_clr : 1;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_ASP_CODEC_ULTR_UP_AFIFO_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_ULTR_UP_AFIFO_CTRL_ultr_up_fifo_aempty_th_START (5)
#define SOC_ASP_CODEC_ULTR_UP_AFIFO_CTRL_ultr_up_fifo_aempty_th_END (9)
#define SOC_ASP_CODEC_ULTR_UP_AFIFO_CTRL_ultr_up_fifo_afull_th_START (10)
#define SOC_ASP_CODEC_ULTR_UP_AFIFO_CTRL_ultr_up_fifo_afull_th_END (14)
#define SOC_ASP_CODEC_ULTR_UP_AFIFO_CTRL_ultr_up_fifo_clr_START (15)
#define SOC_ASP_CODEC_ULTR_UP_AFIFO_CTRL_ultr_up_fifo_clr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ultr_dn_fifo_aempty_th : 6;
        unsigned int reserved_0 : 3;
        unsigned int ultr_dn_fifo_afull_th : 6;
        unsigned int ultr_dn_fifo_clr : 1;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_ASP_CODEC_ULTR_DN_AFIFO_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_ULTR_DN_AFIFO_CTRL_ultr_dn_fifo_aempty_th_START (0)
#define SOC_ASP_CODEC_ULTR_DN_AFIFO_CTRL_ultr_dn_fifo_aempty_th_END (5)
#define SOC_ASP_CODEC_ULTR_DN_AFIFO_CTRL_ultr_dn_fifo_afull_th_START (9)
#define SOC_ASP_CODEC_ULTR_DN_AFIFO_CTRL_ultr_dn_fifo_afull_th_END (14)
#define SOC_ASP_CODEC_ULTR_DN_AFIFO_CTRL_ultr_dn_fifo_clr_START (15)
#define SOC_ASP_CODEC_ULTR_DN_AFIFO_CTRL_ultr_dn_fifo_clr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int i2s1_pcm_tx_l_din_sel : 2;
        unsigned int i2s1_pcm_tx_r_din_sel : 2;
        unsigned int adc_ultr_din_sel : 3;
        unsigned int ultr_dn_pga_din_sel : 1;
        unsigned int dacml_din_sel : 1;
        unsigned int reserved_0 : 1;
        unsigned int i2s2_tx_l_srcdn_din_sel : 1;
        unsigned int i2s2_tx_r_din_sel : 1;
        unsigned int i2s3_tx_l_din_sel : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int ultr_up16_din_sel : 2;
        unsigned int spai_adc_din_sel : 3;
        unsigned int spav_adc_din_sel : 3;
        unsigned int reserved_3 : 9;
    } reg;
} SOC_ASP_CODEC_CODEC_DIN_MUX1_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_i2s1_pcm_tx_l_din_sel_START (0)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_i2s1_pcm_tx_l_din_sel_END (1)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_i2s1_pcm_tx_r_din_sel_START (2)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_i2s1_pcm_tx_r_din_sel_END (3)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_adc_ultr_din_sel_START (4)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_adc_ultr_din_sel_END (6)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_ultr_dn_pga_din_sel_START (7)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_ultr_dn_pga_din_sel_END (7)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_dacml_din_sel_START (8)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_dacml_din_sel_END (8)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_i2s2_tx_l_srcdn_din_sel_START (10)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_i2s2_tx_l_srcdn_din_sel_END (10)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_i2s2_tx_r_din_sel_START (11)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_i2s2_tx_r_din_sel_END (11)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_i2s3_tx_l_din_sel_START (12)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_i2s3_tx_l_din_sel_END (12)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_ultr_up16_din_sel_START (15)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_ultr_up16_din_sel_END (16)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_spai_adc_din_sel_START (17)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_spai_adc_din_sel_END (19)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_spav_adc_din_sel_START (20)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_spav_adc_din_sel_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fs_spa1_uplink : 1;
        unsigned int fs_spa3_uplink : 1;
        unsigned int fs_ultr_uplink : 2;
        unsigned int fs_ultr_dlink : 2;
        unsigned int fs_ultr_dn_pga : 2;
        unsigned int fs_codec3_l_dn_pga : 3;
        unsigned int fs_codec3_r_dn_pga : 3;
        unsigned int fs_i2s2_tx_r_srcdn_din : 1;
        unsigned int fs_i2s2_tx_r_srcdn_dout : 3;
        unsigned int fs_i2s2_tx_l_srcdn_din : 1;
        unsigned int fs_i2s2_tx_l_srcdn_dout : 3;
        unsigned int fs_i2s1_tdm : 2;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_CODEC_FS_CTRL3_UNION;
#endif
#define SOC_ASP_CODEC_FS_CTRL3_fs_spa1_uplink_START (0)
#define SOC_ASP_CODEC_FS_CTRL3_fs_spa1_uplink_END (0)
#define SOC_ASP_CODEC_FS_CTRL3_fs_spa3_uplink_START (1)
#define SOC_ASP_CODEC_FS_CTRL3_fs_spa3_uplink_END (1)
#define SOC_ASP_CODEC_FS_CTRL3_fs_ultr_uplink_START (2)
#define SOC_ASP_CODEC_FS_CTRL3_fs_ultr_uplink_END (3)
#define SOC_ASP_CODEC_FS_CTRL3_fs_ultr_dlink_START (4)
#define SOC_ASP_CODEC_FS_CTRL3_fs_ultr_dlink_END (5)
#define SOC_ASP_CODEC_FS_CTRL3_fs_ultr_dn_pga_START (6)
#define SOC_ASP_CODEC_FS_CTRL3_fs_ultr_dn_pga_END (7)
#define SOC_ASP_CODEC_FS_CTRL3_fs_codec3_l_dn_pga_START (8)
#define SOC_ASP_CODEC_FS_CTRL3_fs_codec3_l_dn_pga_END (10)
#define SOC_ASP_CODEC_FS_CTRL3_fs_codec3_r_dn_pga_START (11)
#define SOC_ASP_CODEC_FS_CTRL3_fs_codec3_r_dn_pga_END (13)
#define SOC_ASP_CODEC_FS_CTRL3_fs_i2s2_tx_r_srcdn_din_START (14)
#define SOC_ASP_CODEC_FS_CTRL3_fs_i2s2_tx_r_srcdn_din_END (14)
#define SOC_ASP_CODEC_FS_CTRL3_fs_i2s2_tx_r_srcdn_dout_START (15)
#define SOC_ASP_CODEC_FS_CTRL3_fs_i2s2_tx_r_srcdn_dout_END (17)
#define SOC_ASP_CODEC_FS_CTRL3_fs_i2s2_tx_l_srcdn_din_START (18)
#define SOC_ASP_CODEC_FS_CTRL3_fs_i2s2_tx_l_srcdn_din_END (18)
#define SOC_ASP_CODEC_FS_CTRL3_fs_i2s2_tx_l_srcdn_dout_START (19)
#define SOC_ASP_CODEC_FS_CTRL3_fs_i2s2_tx_l_srcdn_dout_END (21)
#define SOC_ASP_CODEC_FS_CTRL3_fs_i2s1_tdm_START (22)
#define SOC_ASP_CODEC_FS_CTRL3_fs_i2s1_tdm_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mem_ctrl_s : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_ASP_CODEC_MEM_CTRL_S_CFG_UNION;
#endif
#define SOC_ASP_CODEC_MEM_CTRL_S_CFG_mem_ctrl_s_START (0)
#define SOC_ASP_CODEC_MEM_CTRL_S_CFG_mem_ctrl_s_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int i2s3_fifo_clr : 1;
        unsigned int i2s2_fifo_clr : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ASP_CODEC_I2S_FIFO_CLR_UNION;
#endif
#define SOC_ASP_CODEC_I2S_FIFO_CLR_i2s3_fifo_clr_START (0)
#define SOC_ASP_CODEC_I2S_FIFO_CLR_i2s3_fifo_clr_END (0)
#define SOC_ASP_CODEC_I2S_FIFO_CLR_i2s2_fifo_clr_START (1)
#define SOC_ASP_CODEC_I2S_FIFO_CLR_i2s2_fifo_clr_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int adc_spai_hpf_bypass_en : 1;
        unsigned int adc_spai_hbfvd_bypass_en : 1;
        unsigned int adc_spai_hbf2d_bypass_en : 1;
        unsigned int adc_spai_compd_bypass_en : 1;
        unsigned int adc_spai_cic_gain : 6;
        unsigned int adc_spav_hpf_bypass_en : 1;
        unsigned int adc_spav_hbfvd_bypass_en : 1;
        unsigned int adc_spav_hbf2d_bypass_en : 1;
        unsigned int adc_spav_compd_bypass_en : 1;
        unsigned int adc_spav_cic_gain : 6;
    } reg;
} SOC_ASP_CODEC_SPAIV_ADC_FILTER_UNION;
#endif
#define SOC_ASP_CODEC_SPAIV_ADC_FILTER_adc_spai_hpf_bypass_en_START (12)
#define SOC_ASP_CODEC_SPAIV_ADC_FILTER_adc_spai_hpf_bypass_en_END (12)
#define SOC_ASP_CODEC_SPAIV_ADC_FILTER_adc_spai_hbfvd_bypass_en_START (13)
#define SOC_ASP_CODEC_SPAIV_ADC_FILTER_adc_spai_hbfvd_bypass_en_END (13)
#define SOC_ASP_CODEC_SPAIV_ADC_FILTER_adc_spai_hbf2d_bypass_en_START (14)
#define SOC_ASP_CODEC_SPAIV_ADC_FILTER_adc_spai_hbf2d_bypass_en_END (14)
#define SOC_ASP_CODEC_SPAIV_ADC_FILTER_adc_spai_compd_bypass_en_START (15)
#define SOC_ASP_CODEC_SPAIV_ADC_FILTER_adc_spai_compd_bypass_en_END (15)
#define SOC_ASP_CODEC_SPAIV_ADC_FILTER_adc_spai_cic_gain_START (16)
#define SOC_ASP_CODEC_SPAIV_ADC_FILTER_adc_spai_cic_gain_END (21)
#define SOC_ASP_CODEC_SPAIV_ADC_FILTER_adc_spav_hpf_bypass_en_START (22)
#define SOC_ASP_CODEC_SPAIV_ADC_FILTER_adc_spav_hpf_bypass_en_END (22)
#define SOC_ASP_CODEC_SPAIV_ADC_FILTER_adc_spav_hbfvd_bypass_en_START (23)
#define SOC_ASP_CODEC_SPAIV_ADC_FILTER_adc_spav_hbfvd_bypass_en_END (23)
#define SOC_ASP_CODEC_SPAIV_ADC_FILTER_adc_spav_hbf2d_bypass_en_START (24)
#define SOC_ASP_CODEC_SPAIV_ADC_FILTER_adc_spav_hbf2d_bypass_en_END (24)
#define SOC_ASP_CODEC_SPAIV_ADC_FILTER_adc_spav_compd_bypass_en_START (25)
#define SOC_ASP_CODEC_SPAIV_ADC_FILTER_adc_spav_compd_bypass_en_END (25)
#define SOC_ASP_CODEC_SPAIV_ADC_FILTER_adc_spav_cic_gain_START (26)
#define SOC_ASP_CODEC_SPAIV_ADC_FILTER_adc_spav_cic_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dn_cfg : 4;
        unsigned int fall_delay_en : 1;
        unsigned int reserved_0 : 3;
        unsigned int do_cfg : 4;
        unsigned int reserved_1 : 4;
        unsigned int fall_delay_df_cfg : 15;
        unsigned int classh_bypass : 1;
    } reg;
} SOC_ASP_CODEC_CLASSH_CTRL1_UNION;
#endif
#define SOC_ASP_CODEC_CLASSH_CTRL1_dn_cfg_START (0)
#define SOC_ASP_CODEC_CLASSH_CTRL1_dn_cfg_END (3)
#define SOC_ASP_CODEC_CLASSH_CTRL1_fall_delay_en_START (4)
#define SOC_ASP_CODEC_CLASSH_CTRL1_fall_delay_en_END (4)
#define SOC_ASP_CODEC_CLASSH_CTRL1_do_cfg_START (8)
#define SOC_ASP_CODEC_CLASSH_CTRL1_do_cfg_END (11)
#define SOC_ASP_CODEC_CLASSH_CTRL1_fall_delay_df_cfg_START (16)
#define SOC_ASP_CODEC_CLASSH_CTRL1_fall_delay_df_cfg_END (30)
#define SOC_ASP_CODEC_CLASSH_CTRL1_classh_bypass_START (31)
#define SOC_ASP_CODEC_CLASSH_CTRL1_classh_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh_pga_gain : 9;
        unsigned int classh_dym_en : 1;
        unsigned int classh_en : 1;
        unsigned int reserved_0 : 5;
        unsigned int reg_vctrl1 : 8;
        unsigned int fall_step : 6;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_ASP_CODEC_CLASSH_CTRL2_UNION;
#endif
#define SOC_ASP_CODEC_CLASSH_CTRL2_classh_pga_gain_START (0)
#define SOC_ASP_CODEC_CLASSH_CTRL2_classh_pga_gain_END (8)
#define SOC_ASP_CODEC_CLASSH_CTRL2_classh_dym_en_START (9)
#define SOC_ASP_CODEC_CLASSH_CTRL2_classh_dym_en_END (9)
#define SOC_ASP_CODEC_CLASSH_CTRL2_classh_en_START (10)
#define SOC_ASP_CODEC_CLASSH_CTRL2_classh_en_END (10)
#define SOC_ASP_CODEC_CLASSH_CTRL2_reg_vctrl1_START (16)
#define SOC_ASP_CODEC_CLASSH_CTRL2_reg_vctrl1_END (23)
#define SOC_ASP_CODEC_CLASSH_CTRL2_fall_step_START (24)
#define SOC_ASP_CODEC_CLASSH_CTRL2_fall_step_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lut_reg0 : 7;
        unsigned int reserved_0: 1;
        unsigned int lut_reg1 : 7;
        unsigned int reserved_1: 1;
        unsigned int lut_reg2 : 7;
        unsigned int reserved_2: 1;
        unsigned int lut_reg3 : 7;
        unsigned int reserved_3: 1;
    } reg;
} SOC_ASP_CODEC_LUT_REG0_3_UNION;
#endif
#define SOC_ASP_CODEC_LUT_REG0_3_lut_reg0_START (0)
#define SOC_ASP_CODEC_LUT_REG0_3_lut_reg0_END (6)
#define SOC_ASP_CODEC_LUT_REG0_3_lut_reg1_START (8)
#define SOC_ASP_CODEC_LUT_REG0_3_lut_reg1_END (14)
#define SOC_ASP_CODEC_LUT_REG0_3_lut_reg2_START (16)
#define SOC_ASP_CODEC_LUT_REG0_3_lut_reg2_END (22)
#define SOC_ASP_CODEC_LUT_REG0_3_lut_reg3_START (24)
#define SOC_ASP_CODEC_LUT_REG0_3_lut_reg3_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lut_reg4 : 7;
        unsigned int reserved_0: 1;
        unsigned int lut_reg5 : 7;
        unsigned int reserved_1: 1;
        unsigned int lut_reg6 : 7;
        unsigned int reserved_2: 1;
        unsigned int lut_reg7 : 7;
        unsigned int reserved_3: 1;
    } reg;
} SOC_ASP_CODEC_LUT_REG4_7_UNION;
#endif
#define SOC_ASP_CODEC_LUT_REG4_7_lut_reg4_START (0)
#define SOC_ASP_CODEC_LUT_REG4_7_lut_reg4_END (6)
#define SOC_ASP_CODEC_LUT_REG4_7_lut_reg5_START (8)
#define SOC_ASP_CODEC_LUT_REG4_7_lut_reg5_END (14)
#define SOC_ASP_CODEC_LUT_REG4_7_lut_reg6_START (16)
#define SOC_ASP_CODEC_LUT_REG4_7_lut_reg6_END (22)
#define SOC_ASP_CODEC_LUT_REG4_7_lut_reg7_START (24)
#define SOC_ASP_CODEC_LUT_REG4_7_lut_reg7_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lut_reg8 : 7;
        unsigned int reserved_0: 1;
        unsigned int lut_reg9 : 7;
        unsigned int reserved_1: 1;
        unsigned int lut_reg10 : 7;
        unsigned int reserved_2: 1;
        unsigned int lut_reg11 : 7;
        unsigned int reserved_3: 1;
    } reg;
} SOC_ASP_CODEC_LUT_REG8_11_UNION;
#endif
#define SOC_ASP_CODEC_LUT_REG8_11_lut_reg8_START (0)
#define SOC_ASP_CODEC_LUT_REG8_11_lut_reg8_END (6)
#define SOC_ASP_CODEC_LUT_REG8_11_lut_reg9_START (8)
#define SOC_ASP_CODEC_LUT_REG8_11_lut_reg9_END (14)
#define SOC_ASP_CODEC_LUT_REG8_11_lut_reg10_START (16)
#define SOC_ASP_CODEC_LUT_REG8_11_lut_reg10_END (22)
#define SOC_ASP_CODEC_LUT_REG8_11_lut_reg11_START (24)
#define SOC_ASP_CODEC_LUT_REG8_11_lut_reg11_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lut_reg12 : 7;
        unsigned int reserved_0: 1;
        unsigned int lut_reg13 : 7;
        unsigned int reserved_1: 1;
        unsigned int lut_reg14 : 7;
        unsigned int reserved_2: 1;
        unsigned int lut_reg15 : 7;
        unsigned int reserved_3: 1;
    } reg;
} SOC_ASP_CODEC_LUT_REG12_15_UNION;
#endif
#define SOC_ASP_CODEC_LUT_REG12_15_lut_reg12_START (0)
#define SOC_ASP_CODEC_LUT_REG12_15_lut_reg12_END (6)
#define SOC_ASP_CODEC_LUT_REG12_15_lut_reg13_START (8)
#define SOC_ASP_CODEC_LUT_REG12_15_lut_reg13_END (14)
#define SOC_ASP_CODEC_LUT_REG12_15_lut_reg14_START (16)
#define SOC_ASP_CODEC_LUT_REG12_15_lut_reg14_END (22)
#define SOC_ASP_CODEC_LUT_REG12_15_lut_reg15_START (24)
#define SOC_ASP_CODEC_LUT_REG12_15_lut_reg15_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lut_reg16 : 7;
        unsigned int reserved_0: 1;
        unsigned int lut_reg17 : 7;
        unsigned int reserved_1: 1;
        unsigned int lut_reg18 : 7;
        unsigned int reserved_2: 1;
        unsigned int lut_reg19 : 7;
        unsigned int reserved_3: 1;
    } reg;
} SOC_ASP_CODEC_LUT_REG16_19_UNION;
#endif
#define SOC_ASP_CODEC_LUT_REG16_19_lut_reg16_START (0)
#define SOC_ASP_CODEC_LUT_REG16_19_lut_reg16_END (6)
#define SOC_ASP_CODEC_LUT_REG16_19_lut_reg17_START (8)
#define SOC_ASP_CODEC_LUT_REG16_19_lut_reg17_END (14)
#define SOC_ASP_CODEC_LUT_REG16_19_lut_reg18_START (16)
#define SOC_ASP_CODEC_LUT_REG16_19_lut_reg18_END (22)
#define SOC_ASP_CODEC_LUT_REG16_19_lut_reg19_START (24)
#define SOC_ASP_CODEC_LUT_REG16_19_lut_reg19_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lut_reg20 : 7;
        unsigned int reserved_0: 1;
        unsigned int lut_reg21 : 7;
        unsigned int reserved_1: 1;
        unsigned int lut_reg22 : 7;
        unsigned int reserved_2: 1;
        unsigned int lut_reg23 : 7;
        unsigned int reserved_3: 1;
    } reg;
} SOC_ASP_CODEC_LUT_REG20_23_UNION;
#endif
#define SOC_ASP_CODEC_LUT_REG20_23_lut_reg20_START (0)
#define SOC_ASP_CODEC_LUT_REG20_23_lut_reg20_END (6)
#define SOC_ASP_CODEC_LUT_REG20_23_lut_reg21_START (8)
#define SOC_ASP_CODEC_LUT_REG20_23_lut_reg21_END (14)
#define SOC_ASP_CODEC_LUT_REG20_23_lut_reg22_START (16)
#define SOC_ASP_CODEC_LUT_REG20_23_lut_reg22_END (22)
#define SOC_ASP_CODEC_LUT_REG20_23_lut_reg23_START (24)
#define SOC_ASP_CODEC_LUT_REG20_23_lut_reg23_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lut_reg24 : 7;
        unsigned int reserved_0: 1;
        unsigned int lut_reg25 : 7;
        unsigned int reserved_1: 1;
        unsigned int lut_reg26 : 7;
        unsigned int reserved_2: 1;
        unsigned int lut_reg27 : 7;
        unsigned int reserved_3: 1;
    } reg;
} SOC_ASP_CODEC_LUT_REG24_27_UNION;
#endif
#define SOC_ASP_CODEC_LUT_REG24_27_lut_reg24_START (0)
#define SOC_ASP_CODEC_LUT_REG24_27_lut_reg24_END (6)
#define SOC_ASP_CODEC_LUT_REG24_27_lut_reg25_START (8)
#define SOC_ASP_CODEC_LUT_REG24_27_lut_reg25_END (14)
#define SOC_ASP_CODEC_LUT_REG24_27_lut_reg26_START (16)
#define SOC_ASP_CODEC_LUT_REG24_27_lut_reg26_END (22)
#define SOC_ASP_CODEC_LUT_REG24_27_lut_reg27_START (24)
#define SOC_ASP_CODEC_LUT_REG24_27_lut_reg27_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lut_reg28 : 7;
        unsigned int reserved_0: 1;
        unsigned int lut_reg29 : 7;
        unsigned int reserved_1: 1;
        unsigned int lut_reg30 : 7;
        unsigned int reserved_2: 1;
        unsigned int lut_reg31 : 7;
        unsigned int reserved_3: 1;
    } reg;
} SOC_ASP_CODEC_LUT_REG28_31_UNION;
#endif
#define SOC_ASP_CODEC_LUT_REG28_31_lut_reg28_START (0)
#define SOC_ASP_CODEC_LUT_REG28_31_lut_reg28_END (6)
#define SOC_ASP_CODEC_LUT_REG28_31_lut_reg29_START (8)
#define SOC_ASP_CODEC_LUT_REG28_31_lut_reg29_END (14)
#define SOC_ASP_CODEC_LUT_REG28_31_lut_reg30_START (16)
#define SOC_ASP_CODEC_LUT_REG28_31_lut_reg30_END (22)
#define SOC_ASP_CODEC_LUT_REG28_31_lut_reg31_START (24)
#define SOC_ASP_CODEC_LUT_REG28_31_lut_reg31_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lut_reg32 : 7;
        unsigned int reserved_0: 1;
        unsigned int lut_reg33 : 7;
        unsigned int reserved_1: 1;
        unsigned int lut_reg34 : 7;
        unsigned int reserved_2: 1;
        unsigned int lut_reg35 : 7;
        unsigned int reserved_3: 1;
    } reg;
} SOC_ASP_CODEC_LUT_REG32_35_UNION;
#endif
#define SOC_ASP_CODEC_LUT_REG32_35_lut_reg32_START (0)
#define SOC_ASP_CODEC_LUT_REG32_35_lut_reg32_END (6)
#define SOC_ASP_CODEC_LUT_REG32_35_lut_reg33_START (8)
#define SOC_ASP_CODEC_LUT_REG32_35_lut_reg33_END (14)
#define SOC_ASP_CODEC_LUT_REG32_35_lut_reg34_START (16)
#define SOC_ASP_CODEC_LUT_REG32_35_lut_reg34_END (22)
#define SOC_ASP_CODEC_LUT_REG32_35_lut_reg35_START (24)
#define SOC_ASP_CODEC_LUT_REG32_35_lut_reg35_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lut_reg36 : 7;
        unsigned int reserved_0: 1;
        unsigned int lut_reg37 : 7;
        unsigned int reserved_1: 1;
        unsigned int lut_reg38 : 7;
        unsigned int reserved_2: 1;
        unsigned int lut_reg39 : 7;
        unsigned int reserved_3: 1;
    } reg;
} SOC_ASP_CODEC_LUT_REG36_39_UNION;
#endif
#define SOC_ASP_CODEC_LUT_REG36_39_lut_reg36_START (0)
#define SOC_ASP_CODEC_LUT_REG36_39_lut_reg36_END (6)
#define SOC_ASP_CODEC_LUT_REG36_39_lut_reg37_START (8)
#define SOC_ASP_CODEC_LUT_REG36_39_lut_reg37_END (14)
#define SOC_ASP_CODEC_LUT_REG36_39_lut_reg38_START (16)
#define SOC_ASP_CODEC_LUT_REG36_39_lut_reg38_END (22)
#define SOC_ASP_CODEC_LUT_REG36_39_lut_reg39_START (24)
#define SOC_ASP_CODEC_LUT_REG36_39_lut_reg39_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lut_reg40 : 7;
        unsigned int reserved_0: 1;
        unsigned int lut_reg41 : 7;
        unsigned int reserved_1: 1;
        unsigned int lut_reg42 : 7;
        unsigned int reserved_2: 1;
        unsigned int lut_reg43 : 7;
        unsigned int reserved_3: 1;
    } reg;
} SOC_ASP_CODEC_LUT_REG40_43_UNION;
#endif
#define SOC_ASP_CODEC_LUT_REG40_43_lut_reg40_START (0)
#define SOC_ASP_CODEC_LUT_REG40_43_lut_reg40_END (6)
#define SOC_ASP_CODEC_LUT_REG40_43_lut_reg41_START (8)
#define SOC_ASP_CODEC_LUT_REG40_43_lut_reg41_END (14)
#define SOC_ASP_CODEC_LUT_REG40_43_lut_reg42_START (16)
#define SOC_ASP_CODEC_LUT_REG40_43_lut_reg42_END (22)
#define SOC_ASP_CODEC_LUT_REG40_43_lut_reg43_START (24)
#define SOC_ASP_CODEC_LUT_REG40_43_lut_reg43_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lut_reg44 : 7;
        unsigned int reserved_0: 1;
        unsigned int lut_reg45 : 7;
        unsigned int reserved_1: 1;
        unsigned int lut_reg46 : 7;
        unsigned int reserved_2: 1;
        unsigned int lut_reg47 : 7;
        unsigned int reserved_3: 1;
    } reg;
} SOC_ASP_CODEC_LUT_REG44_47_UNION;
#endif
#define SOC_ASP_CODEC_LUT_REG44_47_lut_reg44_START (0)
#define SOC_ASP_CODEC_LUT_REG44_47_lut_reg44_END (6)
#define SOC_ASP_CODEC_LUT_REG44_47_lut_reg45_START (8)
#define SOC_ASP_CODEC_LUT_REG44_47_lut_reg45_END (14)
#define SOC_ASP_CODEC_LUT_REG44_47_lut_reg46_START (16)
#define SOC_ASP_CODEC_LUT_REG44_47_lut_reg46_END (22)
#define SOC_ASP_CODEC_LUT_REG44_47_lut_reg47_START (24)
#define SOC_ASP_CODEC_LUT_REG44_47_lut_reg47_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lut_reg48 : 7;
        unsigned int reserved_0: 1;
        unsigned int lut_reg49 : 7;
        unsigned int reserved_1: 1;
        unsigned int lut_reg50 : 7;
        unsigned int reserved_2: 1;
        unsigned int lut_reg51 : 7;
        unsigned int reserved_3: 1;
    } reg;
} SOC_ASP_CODEC_LUT_REG48_51_UNION;
#endif
#define SOC_ASP_CODEC_LUT_REG48_51_lut_reg48_START (0)
#define SOC_ASP_CODEC_LUT_REG48_51_lut_reg48_END (6)
#define SOC_ASP_CODEC_LUT_REG48_51_lut_reg49_START (8)
#define SOC_ASP_CODEC_LUT_REG48_51_lut_reg49_END (14)
#define SOC_ASP_CODEC_LUT_REG48_51_lut_reg50_START (16)
#define SOC_ASP_CODEC_LUT_REG48_51_lut_reg50_END (22)
#define SOC_ASP_CODEC_LUT_REG48_51_lut_reg51_START (24)
#define SOC_ASP_CODEC_LUT_REG48_51_lut_reg51_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lut_reg52 : 7;
        unsigned int reserved_0: 1;
        unsigned int lut_reg53 : 7;
        unsigned int reserved_1: 1;
        unsigned int lut_reg54 : 7;
        unsigned int reserved_2: 1;
        unsigned int lut_reg55 : 7;
        unsigned int reserved_3: 1;
    } reg;
} SOC_ASP_CODEC_LUT_REG52_55_UNION;
#endif
#define SOC_ASP_CODEC_LUT_REG52_55_lut_reg52_START (0)
#define SOC_ASP_CODEC_LUT_REG52_55_lut_reg52_END (6)
#define SOC_ASP_CODEC_LUT_REG52_55_lut_reg53_START (8)
#define SOC_ASP_CODEC_LUT_REG52_55_lut_reg53_END (14)
#define SOC_ASP_CODEC_LUT_REG52_55_lut_reg54_START (16)
#define SOC_ASP_CODEC_LUT_REG52_55_lut_reg54_END (22)
#define SOC_ASP_CODEC_LUT_REG52_55_lut_reg55_START (24)
#define SOC_ASP_CODEC_LUT_REG52_55_lut_reg55_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lut_reg56 : 7;
        unsigned int reserved_0: 1;
        unsigned int lut_reg57 : 7;
        unsigned int reserved_1: 1;
        unsigned int lut_reg58 : 7;
        unsigned int reserved_2: 1;
        unsigned int lut_reg59 : 7;
        unsigned int reserved_3: 1;
    } reg;
} SOC_ASP_CODEC_LUT_REG56_59_UNION;
#endif
#define SOC_ASP_CODEC_LUT_REG56_59_lut_reg56_START (0)
#define SOC_ASP_CODEC_LUT_REG56_59_lut_reg56_END (6)
#define SOC_ASP_CODEC_LUT_REG56_59_lut_reg57_START (8)
#define SOC_ASP_CODEC_LUT_REG56_59_lut_reg57_END (14)
#define SOC_ASP_CODEC_LUT_REG56_59_lut_reg58_START (16)
#define SOC_ASP_CODEC_LUT_REG56_59_lut_reg58_END (22)
#define SOC_ASP_CODEC_LUT_REG56_59_lut_reg59_START (24)
#define SOC_ASP_CODEC_LUT_REG56_59_lut_reg59_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lut_reg60 : 7;
        unsigned int reserved_0: 1;
        unsigned int lut_reg61 : 7;
        unsigned int reserved_1: 1;
        unsigned int lut_reg62 : 7;
        unsigned int reserved_2: 1;
        unsigned int lut_reg63 : 7;
        unsigned int reserved_3: 1;
    } reg;
} SOC_ASP_CODEC_LUT_REG60_63_UNION;
#endif
#define SOC_ASP_CODEC_LUT_REG60_63_lut_reg60_START (0)
#define SOC_ASP_CODEC_LUT_REG60_63_lut_reg60_END (6)
#define SOC_ASP_CODEC_LUT_REG60_63_lut_reg61_START (8)
#define SOC_ASP_CODEC_LUT_REG60_63_lut_reg61_END (14)
#define SOC_ASP_CODEC_LUT_REG60_63_lut_reg62_START (16)
#define SOC_ASP_CODEC_LUT_REG60_63_lut_reg62_END (22)
#define SOC_ASP_CODEC_LUT_REG60_63_lut_reg63_START (24)
#define SOC_ASP_CODEC_LUT_REG60_63_lut_reg63_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lut_reg64 : 7;
        unsigned int reserved_0: 1;
        unsigned int lut_reg65 : 7;
        unsigned int reserved_1: 1;
        unsigned int lut_reg66 : 7;
        unsigned int reserved_2: 1;
        unsigned int lut_reg67 : 7;
        unsigned int reserved_3: 1;
    } reg;
} SOC_ASP_CODEC_LUT_REG64_67_UNION;
#endif
#define SOC_ASP_CODEC_LUT_REG64_67_lut_reg64_START (0)
#define SOC_ASP_CODEC_LUT_REG64_67_lut_reg64_END (6)
#define SOC_ASP_CODEC_LUT_REG64_67_lut_reg65_START (8)
#define SOC_ASP_CODEC_LUT_REG64_67_lut_reg65_END (14)
#define SOC_ASP_CODEC_LUT_REG64_67_lut_reg66_START (16)
#define SOC_ASP_CODEC_LUT_REG64_67_lut_reg66_END (22)
#define SOC_ASP_CODEC_LUT_REG64_67_lut_reg67_START (24)
#define SOC_ASP_CODEC_LUT_REG64_67_lut_reg67_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int adc_spai_dc_offset : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_CODEC_CODEC_ADC_SPI_DC_OFFSET_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_ADC_SPI_DC_OFFSET_adc_spai_dc_offset_START (0)
#define SOC_ASP_CODEC_CODEC_ADC_SPI_DC_OFFSET_adc_spai_dc_offset_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int adc_spav_dc_offset : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_CODEC_CODEC_ADC_SPA_DC_OFFSET_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_ADC_SPA_DC_OFFSET_adc_spav_dc_offset_START (0)
#define SOC_ASP_CODEC_CODEC_ADC_SPA_DC_OFFSET_adc_spav_dc_offset_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int adc2_spi_up_afifo_clken : 1;
        unsigned int adc2_spv_up_afifo_clken : 1;
        unsigned int adc3_spi_up_afifo_clken : 1;
        unsigned int adc3_spv_up_afifo_clken : 1;
        unsigned int mic4_up_afifo_clken : 1;
        unsigned int spa1_dac_filter_clken : 1;
        unsigned int spa1_up16_clken : 1;
        unsigned int spa1_sdm_clken : 1;
        unsigned int classh2_clken : 1;
        unsigned int adc2_spai_clken : 1;
        unsigned int adc2_spav_clken : 1;
        unsigned int spa2_dac_filter_clken : 1;
        unsigned int spa2_up16_clken : 1;
        unsigned int spa2_sdm_clken : 1;
        unsigned int classh3_clken : 1;
        unsigned int adc3_spai_clken : 1;
        unsigned int adc3_spav_clken : 1;
        unsigned int spa3_dac_filter_clken : 1;
        unsigned int spa3_up16_clken : 1;
        unsigned int spa3_sdm_clken : 1;
        unsigned int mic4_up_srcdn_clken : 1;
        unsigned int mic4_up_pga_clken : 1;
        unsigned int mic4_adc_filter_clken : 1;
        unsigned int sif2_mst_clken : 1;
        unsigned int sif3_mst_clken : 1;
        unsigned int dac_ultr_clken : 1;
        unsigned int sif2_mst_dac_edge_sel : 1;
        unsigned int sif2_mst_adc_edge_sel : 1;
        unsigned int sif3_mst_dac_edge_sel : 1;
        unsigned int sif3_mst_adc_edge_sel : 1;
        unsigned int rst_4mic_audio_irq : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_ASP_CODEC_CODEC_CLK_EN2_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_CLK_EN2_adc2_spi_up_afifo_clken_START (0)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_adc2_spi_up_afifo_clken_END (0)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_adc2_spv_up_afifo_clken_START (1)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_adc2_spv_up_afifo_clken_END (1)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_adc3_spi_up_afifo_clken_START (2)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_adc3_spi_up_afifo_clken_END (2)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_adc3_spv_up_afifo_clken_START (3)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_adc3_spv_up_afifo_clken_END (3)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_mic4_up_afifo_clken_START (4)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_mic4_up_afifo_clken_END (4)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_spa1_dac_filter_clken_START (5)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_spa1_dac_filter_clken_END (5)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_spa1_up16_clken_START (6)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_spa1_up16_clken_END (6)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_spa1_sdm_clken_START (7)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_spa1_sdm_clken_END (7)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_classh2_clken_START (8)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_classh2_clken_END (8)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_adc2_spai_clken_START (9)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_adc2_spai_clken_END (9)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_adc2_spav_clken_START (10)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_adc2_spav_clken_END (10)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_spa2_dac_filter_clken_START (11)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_spa2_dac_filter_clken_END (11)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_spa2_up16_clken_START (12)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_spa2_up16_clken_END (12)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_spa2_sdm_clken_START (13)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_spa2_sdm_clken_END (13)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_classh3_clken_START (14)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_classh3_clken_END (14)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_adc3_spai_clken_START (15)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_adc3_spai_clken_END (15)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_adc3_spav_clken_START (16)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_adc3_spav_clken_END (16)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_spa3_dac_filter_clken_START (17)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_spa3_dac_filter_clken_END (17)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_spa3_up16_clken_START (18)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_spa3_up16_clken_END (18)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_spa3_sdm_clken_START (19)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_spa3_sdm_clken_END (19)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_mic4_up_srcdn_clken_START (20)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_mic4_up_srcdn_clken_END (20)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_mic4_up_pga_clken_START (21)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_mic4_up_pga_clken_END (21)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_mic4_adc_filter_clken_START (22)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_mic4_adc_filter_clken_END (22)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_sif2_mst_clken_START (23)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_sif2_mst_clken_END (23)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_sif3_mst_clken_START (24)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_sif3_mst_clken_END (24)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_dac_ultr_clken_START (25)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_dac_ultr_clken_END (25)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_sif2_mst_dac_edge_sel_START (26)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_sif2_mst_dac_edge_sel_END (26)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_sif2_mst_adc_edge_sel_START (27)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_sif2_mst_adc_edge_sel_END (27)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_sif3_mst_dac_edge_sel_START (28)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_sif3_mst_dac_edge_sel_END (28)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_sif3_mst_adc_edge_sel_START (29)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_sif3_mst_adc_edge_sel_END (29)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_rst_4mic_audio_irq_START (30)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_rst_4mic_audio_irq_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mic4_up_srcdn_src_mode : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_ASP_CODEC_MIC4_SRCDN_CTRL1_UNION;
#endif
#define SOC_ASP_CODEC_MIC4_SRCDN_CTRL1_mic4_up_srcdn_src_mode_START (0)
#define SOC_ASP_CODEC_MIC4_SRCDN_CTRL1_mic4_up_srcdn_src_mode_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 1;
        unsigned int mic4_up_pga_linear_sel : 1;
        unsigned int mic4_up_pga_zero_num : 5;
        unsigned int mic4_up_pga_thre_id : 2;
        unsigned int mic4_up_pga_noise_en : 1;
        unsigned int mic4_up_pga_bypass : 1;
        unsigned int mic4_up_pga_fade_out : 5;
        unsigned int mic4_up_pga_fade_in : 5;
        unsigned int mic4_up_pga_cfg : 3;
        unsigned int mic4_up_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_MIC4_PGA_UNION;
#endif
#define SOC_ASP_CODEC_MIC4_PGA_mic4_up_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_MIC4_PGA_mic4_up_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_MIC4_PGA_mic4_up_pga_zero_num_START (2)
#define SOC_ASP_CODEC_MIC4_PGA_mic4_up_pga_zero_num_END (6)
#define SOC_ASP_CODEC_MIC4_PGA_mic4_up_pga_thre_id_START (7)
#define SOC_ASP_CODEC_MIC4_PGA_mic4_up_pga_thre_id_END (8)
#define SOC_ASP_CODEC_MIC4_PGA_mic4_up_pga_noise_en_START (9)
#define SOC_ASP_CODEC_MIC4_PGA_mic4_up_pga_noise_en_END (9)
#define SOC_ASP_CODEC_MIC4_PGA_mic4_up_pga_bypass_START (10)
#define SOC_ASP_CODEC_MIC4_PGA_mic4_up_pga_bypass_END (10)
#define SOC_ASP_CODEC_MIC4_PGA_mic4_up_pga_fade_out_START (11)
#define SOC_ASP_CODEC_MIC4_PGA_mic4_up_pga_fade_out_END (15)
#define SOC_ASP_CODEC_MIC4_PGA_mic4_up_pga_fade_in_START (16)
#define SOC_ASP_CODEC_MIC4_PGA_mic4_up_pga_fade_in_END (20)
#define SOC_ASP_CODEC_MIC4_PGA_mic4_up_pga_cfg_START (21)
#define SOC_ASP_CODEC_MIC4_PGA_mic4_up_pga_cfg_END (23)
#define SOC_ASP_CODEC_MIC4_PGA_mic4_up_pga_gain_START (24)
#define SOC_ASP_CODEC_MIC4_PGA_mic4_up_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bm_i2s2_tx_data_sel : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_ASP_CODEC_CODEC_DIN_MUX2_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_DIN_MUX2_bm_i2s2_tx_data_sel_START (0)
#define SOC_ASP_CODEC_CODEC_DIN_MUX2_bm_i2s2_tx_data_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fs_mic4_up_srcdn_dout : 2;
        unsigned int fs_mic4_up_afifo : 2;
        unsigned int reserved : 28;
    } reg;
} SOC_ASP_CODEC_FS_CTRL4_UNION;
#endif
#define SOC_ASP_CODEC_FS_CTRL4_fs_mic4_up_srcdn_dout_START (0)
#define SOC_ASP_CODEC_FS_CTRL4_fs_mic4_up_srcdn_dout_END (1)
#define SOC_ASP_CODEC_FS_CTRL4_fs_mic4_up_afifo_START (2)
#define SOC_ASP_CODEC_FS_CTRL4_fs_mic4_up_afifo_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int adc2_spai_hpf_bypass_en : 1;
        unsigned int adc2_spai_hbfvd_bypass_en : 1;
        unsigned int adc2_spai_hbf2d_bypass_en : 1;
        unsigned int adc2_spai_compd_bypass_en : 1;
        unsigned int adc2_spai_cic_gain : 6;
        unsigned int adc2_spav_hpf_bypass_en : 1;
        unsigned int adc2_spav_hbfvd_bypass_en : 1;
        unsigned int adc2_spav_hbf2d_bypass_en : 1;
        unsigned int adc2_spav_compd_bypass_en : 1;
        unsigned int adc2_spav_cic_gain : 6;
    } reg;
} SOC_ASP_CODEC_SPA2_ADC_FILTER_UNION;
#endif
#define SOC_ASP_CODEC_SPA2_ADC_FILTER_adc2_spai_hpf_bypass_en_START (12)
#define SOC_ASP_CODEC_SPA2_ADC_FILTER_adc2_spai_hpf_bypass_en_END (12)
#define SOC_ASP_CODEC_SPA2_ADC_FILTER_adc2_spai_hbfvd_bypass_en_START (13)
#define SOC_ASP_CODEC_SPA2_ADC_FILTER_adc2_spai_hbfvd_bypass_en_END (13)
#define SOC_ASP_CODEC_SPA2_ADC_FILTER_adc2_spai_hbf2d_bypass_en_START (14)
#define SOC_ASP_CODEC_SPA2_ADC_FILTER_adc2_spai_hbf2d_bypass_en_END (14)
#define SOC_ASP_CODEC_SPA2_ADC_FILTER_adc2_spai_compd_bypass_en_START (15)
#define SOC_ASP_CODEC_SPA2_ADC_FILTER_adc2_spai_compd_bypass_en_END (15)
#define SOC_ASP_CODEC_SPA2_ADC_FILTER_adc2_spai_cic_gain_START (16)
#define SOC_ASP_CODEC_SPA2_ADC_FILTER_adc2_spai_cic_gain_END (21)
#define SOC_ASP_CODEC_SPA2_ADC_FILTER_adc2_spav_hpf_bypass_en_START (22)
#define SOC_ASP_CODEC_SPA2_ADC_FILTER_adc2_spav_hpf_bypass_en_END (22)
#define SOC_ASP_CODEC_SPA2_ADC_FILTER_adc2_spav_hbfvd_bypass_en_START (23)
#define SOC_ASP_CODEC_SPA2_ADC_FILTER_adc2_spav_hbfvd_bypass_en_END (23)
#define SOC_ASP_CODEC_SPA2_ADC_FILTER_adc2_spav_hbf2d_bypass_en_START (24)
#define SOC_ASP_CODEC_SPA2_ADC_FILTER_adc2_spav_hbf2d_bypass_en_END (24)
#define SOC_ASP_CODEC_SPA2_ADC_FILTER_adc2_spav_compd_bypass_en_START (25)
#define SOC_ASP_CODEC_SPA2_ADC_FILTER_adc2_spav_compd_bypass_en_END (25)
#define SOC_ASP_CODEC_SPA2_ADC_FILTER_adc2_spav_cic_gain_START (26)
#define SOC_ASP_CODEC_SPA2_ADC_FILTER_adc2_spav_cic_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int adc2_spai_dc_offset : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_CODEC_CODEC_ADC2_SPI_DC_OFFSET_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_ADC2_SPI_DC_OFFSET_adc2_spai_dc_offset_START (0)
#define SOC_ASP_CODEC_CODEC_ADC2_SPI_DC_OFFSET_adc2_spai_dc_offset_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int adc2_spav_dc_offset : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_CODEC_CODEC_ADC2_SPA_DC_OFFSET_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_ADC2_SPA_DC_OFFSET_adc2_spav_dc_offset_START (0)
#define SOC_ASP_CODEC_CODEC_ADC2_SPA_DC_OFFSET_adc2_spav_dc_offset_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int adc3_spai_hpf_bypass_en : 1;
        unsigned int adc3_spai_hbfvd_bypass_en : 1;
        unsigned int adc3_spai_hbf2d_bypass_en : 1;
        unsigned int adc3_spai_compd_bypass_en : 1;
        unsigned int adc3_spai_cic_gain : 6;
        unsigned int adc3_spav_hpf_bypass_en : 1;
        unsigned int adc3_spav_hbfvd_bypass_en : 1;
        unsigned int adc3_spav_hbf2d_bypass_en : 1;
        unsigned int adc3_spav_compd_bypass_en : 1;
        unsigned int adc3_spav_cic_gain : 6;
    } reg;
} SOC_ASP_CODEC_SPA3_ADC_FILTER_UNION;
#endif
#define SOC_ASP_CODEC_SPA3_ADC_FILTER_adc3_spai_hpf_bypass_en_START (12)
#define SOC_ASP_CODEC_SPA3_ADC_FILTER_adc3_spai_hpf_bypass_en_END (12)
#define SOC_ASP_CODEC_SPA3_ADC_FILTER_adc3_spai_hbfvd_bypass_en_START (13)
#define SOC_ASP_CODEC_SPA3_ADC_FILTER_adc3_spai_hbfvd_bypass_en_END (13)
#define SOC_ASP_CODEC_SPA3_ADC_FILTER_adc3_spai_hbf2d_bypass_en_START (14)
#define SOC_ASP_CODEC_SPA3_ADC_FILTER_adc3_spai_hbf2d_bypass_en_END (14)
#define SOC_ASP_CODEC_SPA3_ADC_FILTER_adc3_spai_compd_bypass_en_START (15)
#define SOC_ASP_CODEC_SPA3_ADC_FILTER_adc3_spai_compd_bypass_en_END (15)
#define SOC_ASP_CODEC_SPA3_ADC_FILTER_adc3_spai_cic_gain_START (16)
#define SOC_ASP_CODEC_SPA3_ADC_FILTER_adc3_spai_cic_gain_END (21)
#define SOC_ASP_CODEC_SPA3_ADC_FILTER_adc3_spav_hpf_bypass_en_START (22)
#define SOC_ASP_CODEC_SPA3_ADC_FILTER_adc3_spav_hpf_bypass_en_END (22)
#define SOC_ASP_CODEC_SPA3_ADC_FILTER_adc3_spav_hbfvd_bypass_en_START (23)
#define SOC_ASP_CODEC_SPA3_ADC_FILTER_adc3_spav_hbfvd_bypass_en_END (23)
#define SOC_ASP_CODEC_SPA3_ADC_FILTER_adc3_spav_hbf2d_bypass_en_START (24)
#define SOC_ASP_CODEC_SPA3_ADC_FILTER_adc3_spav_hbf2d_bypass_en_END (24)
#define SOC_ASP_CODEC_SPA3_ADC_FILTER_adc3_spav_compd_bypass_en_START (25)
#define SOC_ASP_CODEC_SPA3_ADC_FILTER_adc3_spav_compd_bypass_en_END (25)
#define SOC_ASP_CODEC_SPA3_ADC_FILTER_adc3_spav_cic_gain_START (26)
#define SOC_ASP_CODEC_SPA3_ADC_FILTER_adc3_spav_cic_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int adc3_spai_dc_offset : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_CODEC_CODEC_ADC3_SPI_DC_OFFSET_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_ADC3_SPI_DC_OFFSET_adc3_spai_dc_offset_START (0)
#define SOC_ASP_CODEC_CODEC_ADC3_SPI_DC_OFFSET_adc3_spai_dc_offset_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int adc3_spav_dc_offset : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_CODEC_CODEC_ADC3_SPA_DC_OFFSET_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_ADC3_SPA_DC_OFFSET_adc3_spav_dc_offset_START (0)
#define SOC_ASP_CODEC_CODEC_ADC3_SPA_DC_OFFSET_adc3_spav_dc_offset_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int spa1_sdm_dither : 1;
        unsigned int spa1_sdm_calm_vld : 1;
        unsigned int spa2_sdm_dither : 1;
        unsigned int spa2_sdm_calm_vld : 1;
        unsigned int spa3_sdm_dither : 1;
        unsigned int spa3_sdm_calm_vld : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_ASP_CODEC_SPA_SDM_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_SPA_SDM_CTRL_spa1_sdm_dither_START (0)
#define SOC_ASP_CODEC_SPA_SDM_CTRL_spa1_sdm_dither_END (0)
#define SOC_ASP_CODEC_SPA_SDM_CTRL_spa1_sdm_calm_vld_START (1)
#define SOC_ASP_CODEC_SPA_SDM_CTRL_spa1_sdm_calm_vld_END (1)
#define SOC_ASP_CODEC_SPA_SDM_CTRL_spa2_sdm_dither_START (2)
#define SOC_ASP_CODEC_SPA_SDM_CTRL_spa2_sdm_dither_END (2)
#define SOC_ASP_CODEC_SPA_SDM_CTRL_spa2_sdm_calm_vld_START (3)
#define SOC_ASP_CODEC_SPA_SDM_CTRL_spa2_sdm_calm_vld_END (3)
#define SOC_ASP_CODEC_SPA_SDM_CTRL_spa3_sdm_dither_START (4)
#define SOC_ASP_CODEC_SPA_SDM_CTRL_spa3_sdm_dither_END (4)
#define SOC_ASP_CODEC_SPA_SDM_CTRL_spa3_sdm_calm_vld_START (5)
#define SOC_ASP_CODEC_SPA_SDM_CTRL_spa3_sdm_calm_vld_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh2_dn_cfg : 4;
        unsigned int classh2_fall_delay_en : 1;
        unsigned int reserved_0 : 3;
        unsigned int classh2_do_cfg : 4;
        unsigned int reserved_1 : 4;
        unsigned int classh2_fall_delay_df_cfg : 15;
        unsigned int classh2_bypass : 1;
    } reg;
} SOC_ASP_CODEC_CLASSH2_CTRL1_UNION;
#endif
#define SOC_ASP_CODEC_CLASSH2_CTRL1_classh2_dn_cfg_START (0)
#define SOC_ASP_CODEC_CLASSH2_CTRL1_classh2_dn_cfg_END (3)
#define SOC_ASP_CODEC_CLASSH2_CTRL1_classh2_fall_delay_en_START (4)
#define SOC_ASP_CODEC_CLASSH2_CTRL1_classh2_fall_delay_en_END (4)
#define SOC_ASP_CODEC_CLASSH2_CTRL1_classh2_do_cfg_START (8)
#define SOC_ASP_CODEC_CLASSH2_CTRL1_classh2_do_cfg_END (11)
#define SOC_ASP_CODEC_CLASSH2_CTRL1_classh2_fall_delay_df_cfg_START (16)
#define SOC_ASP_CODEC_CLASSH2_CTRL1_classh2_fall_delay_df_cfg_END (30)
#define SOC_ASP_CODEC_CLASSH2_CTRL1_classh2_bypass_START (31)
#define SOC_ASP_CODEC_CLASSH2_CTRL1_classh2_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh2_pga_gain : 9;
        unsigned int classh2_dym_en : 1;
        unsigned int classh2_en : 1;
        unsigned int reserved_0 : 5;
        unsigned int classh2_reg_vctrl1 : 8;
        unsigned int classh2_fall_step : 6;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_ASP_CODEC_CLASSH2_CTRL2_UNION;
#endif
#define SOC_ASP_CODEC_CLASSH2_CTRL2_classh2_pga_gain_START (0)
#define SOC_ASP_CODEC_CLASSH2_CTRL2_classh2_pga_gain_END (8)
#define SOC_ASP_CODEC_CLASSH2_CTRL2_classh2_dym_en_START (9)
#define SOC_ASP_CODEC_CLASSH2_CTRL2_classh2_dym_en_END (9)
#define SOC_ASP_CODEC_CLASSH2_CTRL2_classh2_en_START (10)
#define SOC_ASP_CODEC_CLASSH2_CTRL2_classh2_en_END (10)
#define SOC_ASP_CODEC_CLASSH2_CTRL2_classh2_reg_vctrl1_START (16)
#define SOC_ASP_CODEC_CLASSH2_CTRL2_classh2_reg_vctrl1_END (23)
#define SOC_ASP_CODEC_CLASSH2_CTRL2_classh2_fall_step_START (24)
#define SOC_ASP_CODEC_CLASSH2_CTRL2_classh2_fall_step_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh2_lut_reg0 : 7;
        unsigned int reserved_0 : 1;
        unsigned int classh2_lut_reg1 : 7;
        unsigned int reserved_1 : 1;
        unsigned int classh2_lut_reg2 : 7;
        unsigned int reserved_2 : 1;
        unsigned int classh2_lut_reg3 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ASP_CODEC_CLASS2_LUT_REG0_3_UNION;
#endif
#define SOC_ASP_CODEC_CLASS2_LUT_REG0_3_classh2_lut_reg0_START (0)
#define SOC_ASP_CODEC_CLASS2_LUT_REG0_3_classh2_lut_reg0_END (6)
#define SOC_ASP_CODEC_CLASS2_LUT_REG0_3_classh2_lut_reg1_START (8)
#define SOC_ASP_CODEC_CLASS2_LUT_REG0_3_classh2_lut_reg1_END (14)
#define SOC_ASP_CODEC_CLASS2_LUT_REG0_3_classh2_lut_reg2_START (16)
#define SOC_ASP_CODEC_CLASS2_LUT_REG0_3_classh2_lut_reg2_END (22)
#define SOC_ASP_CODEC_CLASS2_LUT_REG0_3_classh2_lut_reg3_START (24)
#define SOC_ASP_CODEC_CLASS2_LUT_REG0_3_classh2_lut_reg3_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh2_lut_reg4 : 7;
        unsigned int reserved_0 : 1;
        unsigned int classh2_lut_reg5 : 7;
        unsigned int reserved_1 : 1;
        unsigned int classh2_lut_reg6 : 7;
        unsigned int reserved_2 : 1;
        unsigned int classh2_lut_reg7 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ASP_CODEC_CLASS2_LUT_REG4_7_UNION;
#endif
#define SOC_ASP_CODEC_CLASS2_LUT_REG4_7_classh2_lut_reg4_START (0)
#define SOC_ASP_CODEC_CLASS2_LUT_REG4_7_classh2_lut_reg4_END (6)
#define SOC_ASP_CODEC_CLASS2_LUT_REG4_7_classh2_lut_reg5_START (8)
#define SOC_ASP_CODEC_CLASS2_LUT_REG4_7_classh2_lut_reg5_END (14)
#define SOC_ASP_CODEC_CLASS2_LUT_REG4_7_classh2_lut_reg6_START (16)
#define SOC_ASP_CODEC_CLASS2_LUT_REG4_7_classh2_lut_reg6_END (22)
#define SOC_ASP_CODEC_CLASS2_LUT_REG4_7_classh2_lut_reg7_START (24)
#define SOC_ASP_CODEC_CLASS2_LUT_REG4_7_classh2_lut_reg7_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh2_lut_reg8 : 7;
        unsigned int reserved_0 : 1;
        unsigned int classh2_lut_reg9 : 7;
        unsigned int reserved_1 : 1;
        unsigned int classh2_lut_reg10 : 7;
        unsigned int reserved_2 : 1;
        unsigned int classh2_lut_reg11 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ASP_CODEC_CLASS2_LUT_REG8_11_UNION;
#endif
#define SOC_ASP_CODEC_CLASS2_LUT_REG8_11_classh2_lut_reg8_START (0)
#define SOC_ASP_CODEC_CLASS2_LUT_REG8_11_classh2_lut_reg8_END (6)
#define SOC_ASP_CODEC_CLASS2_LUT_REG8_11_classh2_lut_reg9_START (8)
#define SOC_ASP_CODEC_CLASS2_LUT_REG8_11_classh2_lut_reg9_END (14)
#define SOC_ASP_CODEC_CLASS2_LUT_REG8_11_classh2_lut_reg10_START (16)
#define SOC_ASP_CODEC_CLASS2_LUT_REG8_11_classh2_lut_reg10_END (22)
#define SOC_ASP_CODEC_CLASS2_LUT_REG8_11_classh2_lut_reg11_START (24)
#define SOC_ASP_CODEC_CLASS2_LUT_REG8_11_classh2_lut_reg11_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh2_lut_reg12 : 7;
        unsigned int reserved_0 : 1;
        unsigned int classh2_lut_reg13 : 7;
        unsigned int reserved_1 : 1;
        unsigned int classh2_lut_reg14 : 7;
        unsigned int reserved_2 : 1;
        unsigned int classh2_lut_reg15 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ASP_CODEC_CLASS2_LUT_REG12_15_UNION;
#endif
#define SOC_ASP_CODEC_CLASS2_LUT_REG12_15_classh2_lut_reg12_START (0)
#define SOC_ASP_CODEC_CLASS2_LUT_REG12_15_classh2_lut_reg12_END (6)
#define SOC_ASP_CODEC_CLASS2_LUT_REG12_15_classh2_lut_reg13_START (8)
#define SOC_ASP_CODEC_CLASS2_LUT_REG12_15_classh2_lut_reg13_END (14)
#define SOC_ASP_CODEC_CLASS2_LUT_REG12_15_classh2_lut_reg14_START (16)
#define SOC_ASP_CODEC_CLASS2_LUT_REG12_15_classh2_lut_reg14_END (22)
#define SOC_ASP_CODEC_CLASS2_LUT_REG12_15_classh2_lut_reg15_START (24)
#define SOC_ASP_CODEC_CLASS2_LUT_REG12_15_classh2_lut_reg15_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh2_lut_reg16 : 7;
        unsigned int reserved_0 : 1;
        unsigned int classh2_lut_reg17 : 7;
        unsigned int reserved_1 : 1;
        unsigned int classh2_lut_reg18 : 7;
        unsigned int reserved_2 : 1;
        unsigned int classh2_lut_reg19 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ASP_CODEC_CLASS2_LUT_REG16_19_UNION;
#endif
#define SOC_ASP_CODEC_CLASS2_LUT_REG16_19_classh2_lut_reg16_START (0)
#define SOC_ASP_CODEC_CLASS2_LUT_REG16_19_classh2_lut_reg16_END (6)
#define SOC_ASP_CODEC_CLASS2_LUT_REG16_19_classh2_lut_reg17_START (8)
#define SOC_ASP_CODEC_CLASS2_LUT_REG16_19_classh2_lut_reg17_END (14)
#define SOC_ASP_CODEC_CLASS2_LUT_REG16_19_classh2_lut_reg18_START (16)
#define SOC_ASP_CODEC_CLASS2_LUT_REG16_19_classh2_lut_reg18_END (22)
#define SOC_ASP_CODEC_CLASS2_LUT_REG16_19_classh2_lut_reg19_START (24)
#define SOC_ASP_CODEC_CLASS2_LUT_REG16_19_classh2_lut_reg19_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh2_lut_reg20 : 7;
        unsigned int reserved_0 : 1;
        unsigned int classh2_lut_reg21 : 7;
        unsigned int reserved_1 : 1;
        unsigned int classh2_lut_reg22 : 7;
        unsigned int reserved_2 : 1;
        unsigned int classh2_lut_reg23 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ASP_CODEC_CLASS2_LUT_REG20_23_UNION;
#endif
#define SOC_ASP_CODEC_CLASS2_LUT_REG20_23_classh2_lut_reg20_START (0)
#define SOC_ASP_CODEC_CLASS2_LUT_REG20_23_classh2_lut_reg20_END (6)
#define SOC_ASP_CODEC_CLASS2_LUT_REG20_23_classh2_lut_reg21_START (8)
#define SOC_ASP_CODEC_CLASS2_LUT_REG20_23_classh2_lut_reg21_END (14)
#define SOC_ASP_CODEC_CLASS2_LUT_REG20_23_classh2_lut_reg22_START (16)
#define SOC_ASP_CODEC_CLASS2_LUT_REG20_23_classh2_lut_reg22_END (22)
#define SOC_ASP_CODEC_CLASS2_LUT_REG20_23_classh2_lut_reg23_START (24)
#define SOC_ASP_CODEC_CLASS2_LUT_REG20_23_classh2_lut_reg23_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh2_lut_reg24 : 7;
        unsigned int reserved_0 : 1;
        unsigned int classh2_lut_reg25 : 7;
        unsigned int reserved_1 : 1;
        unsigned int classh2_lut_reg26 : 7;
        unsigned int reserved_2 : 1;
        unsigned int classh2_lut_reg27 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ASP_CODEC_CLASS2_LUT_REG24_27_UNION;
#endif
#define SOC_ASP_CODEC_CLASS2_LUT_REG24_27_classh2_lut_reg24_START (0)
#define SOC_ASP_CODEC_CLASS2_LUT_REG24_27_classh2_lut_reg24_END (6)
#define SOC_ASP_CODEC_CLASS2_LUT_REG24_27_classh2_lut_reg25_START (8)
#define SOC_ASP_CODEC_CLASS2_LUT_REG24_27_classh2_lut_reg25_END (14)
#define SOC_ASP_CODEC_CLASS2_LUT_REG24_27_classh2_lut_reg26_START (16)
#define SOC_ASP_CODEC_CLASS2_LUT_REG24_27_classh2_lut_reg26_END (22)
#define SOC_ASP_CODEC_CLASS2_LUT_REG24_27_classh2_lut_reg27_START (24)
#define SOC_ASP_CODEC_CLASS2_LUT_REG24_27_classh2_lut_reg27_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh2_lut_reg28 : 7;
        unsigned int reserved_0 : 1;
        unsigned int classh2_lut_reg29 : 7;
        unsigned int reserved_1 : 1;
        unsigned int classh2_lut_reg30 : 7;
        unsigned int reserved_2 : 1;
        unsigned int classh2_lut_reg31 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ASP_CODEC_CLASS2_LUT_REG28_31_UNION;
#endif
#define SOC_ASP_CODEC_CLASS2_LUT_REG28_31_classh2_lut_reg28_START (0)
#define SOC_ASP_CODEC_CLASS2_LUT_REG28_31_classh2_lut_reg28_END (6)
#define SOC_ASP_CODEC_CLASS2_LUT_REG28_31_classh2_lut_reg29_START (8)
#define SOC_ASP_CODEC_CLASS2_LUT_REG28_31_classh2_lut_reg29_END (14)
#define SOC_ASP_CODEC_CLASS2_LUT_REG28_31_classh2_lut_reg30_START (16)
#define SOC_ASP_CODEC_CLASS2_LUT_REG28_31_classh2_lut_reg30_END (22)
#define SOC_ASP_CODEC_CLASS2_LUT_REG28_31_classh2_lut_reg31_START (24)
#define SOC_ASP_CODEC_CLASS2_LUT_REG28_31_classh2_lut_reg31_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh2_lut_reg32 : 7;
        unsigned int reserved_0 : 1;
        unsigned int classh2_lut_reg33 : 7;
        unsigned int reserved_1 : 1;
        unsigned int classh2_lut_reg34 : 7;
        unsigned int reserved_2 : 1;
        unsigned int classh2_lut_reg35 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ASP_CODEC_CLASS2_LUT_REG32_35_UNION;
#endif
#define SOC_ASP_CODEC_CLASS2_LUT_REG32_35_classh2_lut_reg32_START (0)
#define SOC_ASP_CODEC_CLASS2_LUT_REG32_35_classh2_lut_reg32_END (6)
#define SOC_ASP_CODEC_CLASS2_LUT_REG32_35_classh2_lut_reg33_START (8)
#define SOC_ASP_CODEC_CLASS2_LUT_REG32_35_classh2_lut_reg33_END (14)
#define SOC_ASP_CODEC_CLASS2_LUT_REG32_35_classh2_lut_reg34_START (16)
#define SOC_ASP_CODEC_CLASS2_LUT_REG32_35_classh2_lut_reg34_END (22)
#define SOC_ASP_CODEC_CLASS2_LUT_REG32_35_classh2_lut_reg35_START (24)
#define SOC_ASP_CODEC_CLASS2_LUT_REG32_35_classh2_lut_reg35_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh2_lut_reg36 : 7;
        unsigned int reserved_0 : 1;
        unsigned int classh2_lut_reg37 : 7;
        unsigned int reserved_1 : 1;
        unsigned int classh2_lut_reg38 : 7;
        unsigned int reserved_2 : 1;
        unsigned int classh2_lut_reg39 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ASP_CODEC_CLASS2_LUT_REG36_39_UNION;
#endif
#define SOC_ASP_CODEC_CLASS2_LUT_REG36_39_classh2_lut_reg36_START (0)
#define SOC_ASP_CODEC_CLASS2_LUT_REG36_39_classh2_lut_reg36_END (6)
#define SOC_ASP_CODEC_CLASS2_LUT_REG36_39_classh2_lut_reg37_START (8)
#define SOC_ASP_CODEC_CLASS2_LUT_REG36_39_classh2_lut_reg37_END (14)
#define SOC_ASP_CODEC_CLASS2_LUT_REG36_39_classh2_lut_reg38_START (16)
#define SOC_ASP_CODEC_CLASS2_LUT_REG36_39_classh2_lut_reg38_END (22)
#define SOC_ASP_CODEC_CLASS2_LUT_REG36_39_classh2_lut_reg39_START (24)
#define SOC_ASP_CODEC_CLASS2_LUT_REG36_39_classh2_lut_reg39_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh2_lut_reg40 : 7;
        unsigned int reserved_0 : 1;
        unsigned int classh2_lut_reg41 : 7;
        unsigned int reserved_1 : 1;
        unsigned int classh2_lut_reg42 : 7;
        unsigned int reserved_2 : 1;
        unsigned int classh2_lut_reg43 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ASP_CODEC_CLASS2_LUT_REG40_43_UNION;
#endif
#define SOC_ASP_CODEC_CLASS2_LUT_REG40_43_classh2_lut_reg40_START (0)
#define SOC_ASP_CODEC_CLASS2_LUT_REG40_43_classh2_lut_reg40_END (6)
#define SOC_ASP_CODEC_CLASS2_LUT_REG40_43_classh2_lut_reg41_START (8)
#define SOC_ASP_CODEC_CLASS2_LUT_REG40_43_classh2_lut_reg41_END (14)
#define SOC_ASP_CODEC_CLASS2_LUT_REG40_43_classh2_lut_reg42_START (16)
#define SOC_ASP_CODEC_CLASS2_LUT_REG40_43_classh2_lut_reg42_END (22)
#define SOC_ASP_CODEC_CLASS2_LUT_REG40_43_classh2_lut_reg43_START (24)
#define SOC_ASP_CODEC_CLASS2_LUT_REG40_43_classh2_lut_reg43_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh2_lut_reg44 : 7;
        unsigned int reserved_0 : 1;
        unsigned int classh2_lut_reg45 : 7;
        unsigned int reserved_1 : 1;
        unsigned int classh2_lut_reg46 : 7;
        unsigned int reserved_2 : 1;
        unsigned int classh2_lut_reg47 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ASP_CODEC_CLASS2_LUT_REG44_47_UNION;
#endif
#define SOC_ASP_CODEC_CLASS2_LUT_REG44_47_classh2_lut_reg44_START (0)
#define SOC_ASP_CODEC_CLASS2_LUT_REG44_47_classh2_lut_reg44_END (6)
#define SOC_ASP_CODEC_CLASS2_LUT_REG44_47_classh2_lut_reg45_START (8)
#define SOC_ASP_CODEC_CLASS2_LUT_REG44_47_classh2_lut_reg45_END (14)
#define SOC_ASP_CODEC_CLASS2_LUT_REG44_47_classh2_lut_reg46_START (16)
#define SOC_ASP_CODEC_CLASS2_LUT_REG44_47_classh2_lut_reg46_END (22)
#define SOC_ASP_CODEC_CLASS2_LUT_REG44_47_classh2_lut_reg47_START (24)
#define SOC_ASP_CODEC_CLASS2_LUT_REG44_47_classh2_lut_reg47_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh2_lut_reg48 : 7;
        unsigned int reserved_0 : 1;
        unsigned int classh2_lut_reg49 : 7;
        unsigned int reserved_1 : 1;
        unsigned int classh2_lut_reg50 : 7;
        unsigned int reserved_2 : 1;
        unsigned int classh2_lut_reg51 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ASP_CODEC_CLASS2_LUT_REG48_51_UNION;
#endif
#define SOC_ASP_CODEC_CLASS2_LUT_REG48_51_classh2_lut_reg48_START (0)
#define SOC_ASP_CODEC_CLASS2_LUT_REG48_51_classh2_lut_reg48_END (6)
#define SOC_ASP_CODEC_CLASS2_LUT_REG48_51_classh2_lut_reg49_START (8)
#define SOC_ASP_CODEC_CLASS2_LUT_REG48_51_classh2_lut_reg49_END (14)
#define SOC_ASP_CODEC_CLASS2_LUT_REG48_51_classh2_lut_reg50_START (16)
#define SOC_ASP_CODEC_CLASS2_LUT_REG48_51_classh2_lut_reg50_END (22)
#define SOC_ASP_CODEC_CLASS2_LUT_REG48_51_classh2_lut_reg51_START (24)
#define SOC_ASP_CODEC_CLASS2_LUT_REG48_51_classh2_lut_reg51_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh2_lut_reg52 : 7;
        unsigned int reserved_0 : 1;
        unsigned int classh2_lut_reg53 : 7;
        unsigned int reserved_1 : 1;
        unsigned int classh2_lut_reg54 : 7;
        unsigned int reserved_2 : 1;
        unsigned int classh2_lut_reg55 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ASP_CODEC_CLASS2_LUT_REG52_55_UNION;
#endif
#define SOC_ASP_CODEC_CLASS2_LUT_REG52_55_classh2_lut_reg52_START (0)
#define SOC_ASP_CODEC_CLASS2_LUT_REG52_55_classh2_lut_reg52_END (6)
#define SOC_ASP_CODEC_CLASS2_LUT_REG52_55_classh2_lut_reg53_START (8)
#define SOC_ASP_CODEC_CLASS2_LUT_REG52_55_classh2_lut_reg53_END (14)
#define SOC_ASP_CODEC_CLASS2_LUT_REG52_55_classh2_lut_reg54_START (16)
#define SOC_ASP_CODEC_CLASS2_LUT_REG52_55_classh2_lut_reg54_END (22)
#define SOC_ASP_CODEC_CLASS2_LUT_REG52_55_classh2_lut_reg55_START (24)
#define SOC_ASP_CODEC_CLASS2_LUT_REG52_55_classh2_lut_reg55_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh2_lut_reg56 : 7;
        unsigned int reserved_0 : 1;
        unsigned int classh2_lut_reg57 : 7;
        unsigned int reserved_1 : 1;
        unsigned int classh2_lut_reg58 : 7;
        unsigned int reserved_2 : 1;
        unsigned int classh2_lut_reg59 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ASP_CODEC_CLASS2_LUT_REG56_59_UNION;
#endif
#define SOC_ASP_CODEC_CLASS2_LUT_REG56_59_classh2_lut_reg56_START (0)
#define SOC_ASP_CODEC_CLASS2_LUT_REG56_59_classh2_lut_reg56_END (6)
#define SOC_ASP_CODEC_CLASS2_LUT_REG56_59_classh2_lut_reg57_START (8)
#define SOC_ASP_CODEC_CLASS2_LUT_REG56_59_classh2_lut_reg57_END (14)
#define SOC_ASP_CODEC_CLASS2_LUT_REG56_59_classh2_lut_reg58_START (16)
#define SOC_ASP_CODEC_CLASS2_LUT_REG56_59_classh2_lut_reg58_END (22)
#define SOC_ASP_CODEC_CLASS2_LUT_REG56_59_classh2_lut_reg59_START (24)
#define SOC_ASP_CODEC_CLASS2_LUT_REG56_59_classh2_lut_reg59_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh2_lut_reg60 : 7;
        unsigned int reserved_0 : 1;
        unsigned int classh2_lut_reg61 : 7;
        unsigned int reserved_1 : 1;
        unsigned int classh2_lut_reg62 : 7;
        unsigned int reserved_2 : 1;
        unsigned int classh2_lut_reg63 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ASP_CODEC_CLASS2_LUT_REG60_63_UNION;
#endif
#define SOC_ASP_CODEC_CLASS2_LUT_REG60_63_classh2_lut_reg60_START (0)
#define SOC_ASP_CODEC_CLASS2_LUT_REG60_63_classh2_lut_reg60_END (6)
#define SOC_ASP_CODEC_CLASS2_LUT_REG60_63_classh2_lut_reg61_START (8)
#define SOC_ASP_CODEC_CLASS2_LUT_REG60_63_classh2_lut_reg61_END (14)
#define SOC_ASP_CODEC_CLASS2_LUT_REG60_63_classh2_lut_reg62_START (16)
#define SOC_ASP_CODEC_CLASS2_LUT_REG60_63_classh2_lut_reg62_END (22)
#define SOC_ASP_CODEC_CLASS2_LUT_REG60_63_classh2_lut_reg63_START (24)
#define SOC_ASP_CODEC_CLASS2_LUT_REG60_63_classh2_lut_reg63_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh2_lut_reg64 : 7;
        unsigned int reserved_0 : 1;
        unsigned int classh2_lut_reg65 : 7;
        unsigned int reserved_1 : 1;
        unsigned int classh2_lut_reg66 : 7;
        unsigned int reserved_2 : 1;
        unsigned int classh2_lut_reg67 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ASP_CODEC_CLASS2_LUT_REG64_67_UNION;
#endif
#define SOC_ASP_CODEC_CLASS2_LUT_REG64_67_classh2_lut_reg64_START (0)
#define SOC_ASP_CODEC_CLASS2_LUT_REG64_67_classh2_lut_reg64_END (6)
#define SOC_ASP_CODEC_CLASS2_LUT_REG64_67_classh2_lut_reg65_START (8)
#define SOC_ASP_CODEC_CLASS2_LUT_REG64_67_classh2_lut_reg65_END (14)
#define SOC_ASP_CODEC_CLASS2_LUT_REG64_67_classh2_lut_reg66_START (16)
#define SOC_ASP_CODEC_CLASS2_LUT_REG64_67_classh2_lut_reg66_END (22)
#define SOC_ASP_CODEC_CLASS2_LUT_REG64_67_classh2_lut_reg67_START (24)
#define SOC_ASP_CODEC_CLASS2_LUT_REG64_67_classh2_lut_reg67_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh3_dn_cfg : 4;
        unsigned int classh3_fall_delay_en : 1;
        unsigned int reserved_0 : 3;
        unsigned int classh3_do_cfg : 4;
        unsigned int reserved_1 : 4;
        unsigned int classh3_fall_delay_df_cfg : 15;
        unsigned int classh3_bypass : 1;
    } reg;
} SOC_ASP_CODEC_CLASSH3_CTRL1_UNION;
#endif
#define SOC_ASP_CODEC_CLASSH3_CTRL1_classh3_dn_cfg_START (0)
#define SOC_ASP_CODEC_CLASSH3_CTRL1_classh3_dn_cfg_END (3)
#define SOC_ASP_CODEC_CLASSH3_CTRL1_classh3_fall_delay_en_START (4)
#define SOC_ASP_CODEC_CLASSH3_CTRL1_classh3_fall_delay_en_END (4)
#define SOC_ASP_CODEC_CLASSH3_CTRL1_classh3_do_cfg_START (8)
#define SOC_ASP_CODEC_CLASSH3_CTRL1_classh3_do_cfg_END (11)
#define SOC_ASP_CODEC_CLASSH3_CTRL1_classh3_fall_delay_df_cfg_START (16)
#define SOC_ASP_CODEC_CLASSH3_CTRL1_classh3_fall_delay_df_cfg_END (30)
#define SOC_ASP_CODEC_CLASSH3_CTRL1_classh3_bypass_START (31)
#define SOC_ASP_CODEC_CLASSH3_CTRL1_classh3_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh3_pga_gain : 9;
        unsigned int classh3_dym_en : 1;
        unsigned int classh3_en : 1;
        unsigned int reserved_0 : 5;
        unsigned int classh3_reg_vctrl1 : 8;
        unsigned int classh3_fall_step : 6;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_ASP_CODEC_CLASSH3_CTRL2_UNION;
#endif
#define SOC_ASP_CODEC_CLASSH3_CTRL2_classh3_pga_gain_START (0)
#define SOC_ASP_CODEC_CLASSH3_CTRL2_classh3_pga_gain_END (8)
#define SOC_ASP_CODEC_CLASSH3_CTRL2_classh3_dym_en_START (9)
#define SOC_ASP_CODEC_CLASSH3_CTRL2_classh3_dym_en_END (9)
#define SOC_ASP_CODEC_CLASSH3_CTRL2_classh3_en_START (10)
#define SOC_ASP_CODEC_CLASSH3_CTRL2_classh3_en_END (10)
#define SOC_ASP_CODEC_CLASSH3_CTRL2_classh3_reg_vctrl1_START (16)
#define SOC_ASP_CODEC_CLASSH3_CTRL2_classh3_reg_vctrl1_END (23)
#define SOC_ASP_CODEC_CLASSH3_CTRL2_classh3_fall_step_START (24)
#define SOC_ASP_CODEC_CLASSH3_CTRL2_classh3_fall_step_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh3_lut_reg0 : 7;
        unsigned int reserved_0 : 1;
        unsigned int classh3_lut_reg1 : 7;
        unsigned int reserved_1 : 1;
        unsigned int classh3_lut_reg2 : 7;
        unsigned int reserved_2 : 1;
        unsigned int classh3_lut_reg3 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ASP_CODEC_CLASSH3_LUT_REG0_3_UNION;
#endif
#define SOC_ASP_CODEC_CLASSH3_LUT_REG0_3_classh3_lut_reg0_START (0)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG0_3_classh3_lut_reg0_END (6)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG0_3_classh3_lut_reg1_START (8)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG0_3_classh3_lut_reg1_END (14)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG0_3_classh3_lut_reg2_START (16)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG0_3_classh3_lut_reg2_END (22)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG0_3_classh3_lut_reg3_START (24)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG0_3_classh3_lut_reg3_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh3_lut_reg4 : 7;
        unsigned int reserved_0 : 1;
        unsigned int classh3_lut_reg5 : 7;
        unsigned int reserved_1 : 1;
        unsigned int classh3_lut_reg6 : 7;
        unsigned int reserved_2 : 1;
        unsigned int classh3_lut_reg7 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ASP_CODEC_CLASSH3_LUT_REG4_7_UNION;
#endif
#define SOC_ASP_CODEC_CLASSH3_LUT_REG4_7_classh3_lut_reg4_START (0)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG4_7_classh3_lut_reg4_END (6)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG4_7_classh3_lut_reg5_START (8)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG4_7_classh3_lut_reg5_END (14)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG4_7_classh3_lut_reg6_START (16)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG4_7_classh3_lut_reg6_END (22)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG4_7_classh3_lut_reg7_START (24)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG4_7_classh3_lut_reg7_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh3_lut_reg8 : 7;
        unsigned int reserved_0 : 1;
        unsigned int classh3_lut_reg9 : 7;
        unsigned int reserved_1 : 1;
        unsigned int classh3_lut_reg10 : 7;
        unsigned int reserved_2 : 1;
        unsigned int classh3_lut_reg11 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ASP_CODEC_CLASSH3_LUT_REG8_11_UNION;
#endif
#define SOC_ASP_CODEC_CLASSH3_LUT_REG8_11_classh3_lut_reg8_START (0)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG8_11_classh3_lut_reg8_END (6)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG8_11_classh3_lut_reg9_START (8)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG8_11_classh3_lut_reg9_END (14)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG8_11_classh3_lut_reg10_START (16)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG8_11_classh3_lut_reg10_END (22)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG8_11_classh3_lut_reg11_START (24)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG8_11_classh3_lut_reg11_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh3_lut_reg12 : 7;
        unsigned int reserved_0 : 1;
        unsigned int classh3_lut_reg13 : 7;
        unsigned int reserved_1 : 1;
        unsigned int classh3_lut_reg14 : 7;
        unsigned int reserved_2 : 1;
        unsigned int classh3_lut_reg15 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ASP_CODEC_CLASSH3_LUT_REG12_15_UNION;
#endif
#define SOC_ASP_CODEC_CLASSH3_LUT_REG12_15_classh3_lut_reg12_START (0)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG12_15_classh3_lut_reg12_END (6)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG12_15_classh3_lut_reg13_START (8)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG12_15_classh3_lut_reg13_END (14)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG12_15_classh3_lut_reg14_START (16)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG12_15_classh3_lut_reg14_END (22)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG12_15_classh3_lut_reg15_START (24)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG12_15_classh3_lut_reg15_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh3_lut_reg16 : 7;
        unsigned int reserved_0 : 1;
        unsigned int classh3_lut_reg17 : 7;
        unsigned int reserved_1 : 1;
        unsigned int classh3_lut_reg18 : 7;
        unsigned int reserved_2 : 1;
        unsigned int classh3_lut_reg19 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ASP_CODEC_CLASSH3_LUT_REG16_19_UNION;
#endif
#define SOC_ASP_CODEC_CLASSH3_LUT_REG16_19_classh3_lut_reg16_START (0)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG16_19_classh3_lut_reg16_END (6)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG16_19_classh3_lut_reg17_START (8)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG16_19_classh3_lut_reg17_END (14)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG16_19_classh3_lut_reg18_START (16)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG16_19_classh3_lut_reg18_END (22)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG16_19_classh3_lut_reg19_START (24)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG16_19_classh3_lut_reg19_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh3_lut_reg20 : 7;
        unsigned int reserved_0 : 1;
        unsigned int classh3_lut_reg21 : 7;
        unsigned int reserved_1 : 1;
        unsigned int classh3_lut_reg22 : 7;
        unsigned int reserved_2 : 1;
        unsigned int classh3_lut_reg23 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ASP_CODEC_CLASSH3_LUT_REG20_23_UNION;
#endif
#define SOC_ASP_CODEC_CLASSH3_LUT_REG20_23_classh3_lut_reg20_START (0)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG20_23_classh3_lut_reg20_END (6)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG20_23_classh3_lut_reg21_START (8)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG20_23_classh3_lut_reg21_END (14)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG20_23_classh3_lut_reg22_START (16)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG20_23_classh3_lut_reg22_END (22)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG20_23_classh3_lut_reg23_START (24)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG20_23_classh3_lut_reg23_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh3_lut_reg24 : 7;
        unsigned int reserved_0 : 1;
        unsigned int classh3_lut_reg25 : 7;
        unsigned int reserved_1 : 1;
        unsigned int classh3_lut_reg26 : 7;
        unsigned int reserved_2 : 1;
        unsigned int classh3_lut_reg27 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ASP_CODEC_CLASSH3_LUT_REG24_27_UNION;
#endif
#define SOC_ASP_CODEC_CLASSH3_LUT_REG24_27_classh3_lut_reg24_START (0)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG24_27_classh3_lut_reg24_END (6)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG24_27_classh3_lut_reg25_START (8)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG24_27_classh3_lut_reg25_END (14)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG24_27_classh3_lut_reg26_START (16)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG24_27_classh3_lut_reg26_END (22)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG24_27_classh3_lut_reg27_START (24)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG24_27_classh3_lut_reg27_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh3_lut_reg28 : 7;
        unsigned int reserved_0 : 1;
        unsigned int classh3_lut_reg29 : 7;
        unsigned int reserved_1 : 1;
        unsigned int classh3_lut_reg30 : 7;
        unsigned int reserved_2 : 1;
        unsigned int classh3_lut_reg31 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ASP_CODEC_CLASSH3_LUT_REG28_31_UNION;
#endif
#define SOC_ASP_CODEC_CLASSH3_LUT_REG28_31_classh3_lut_reg28_START (0)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG28_31_classh3_lut_reg28_END (6)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG28_31_classh3_lut_reg29_START (8)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG28_31_classh3_lut_reg29_END (14)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG28_31_classh3_lut_reg30_START (16)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG28_31_classh3_lut_reg30_END (22)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG28_31_classh3_lut_reg31_START (24)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG28_31_classh3_lut_reg31_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh3_lut_reg32 : 7;
        unsigned int reserved_0 : 1;
        unsigned int classh3_lut_reg33 : 7;
        unsigned int reserved_1 : 1;
        unsigned int classh3_lut_reg34 : 7;
        unsigned int reserved_2 : 1;
        unsigned int classh3_lut_reg35 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ASP_CODEC_CLASSH3_LUT_REG32_35_UNION;
#endif
#define SOC_ASP_CODEC_CLASSH3_LUT_REG32_35_classh3_lut_reg32_START (0)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG32_35_classh3_lut_reg32_END (6)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG32_35_classh3_lut_reg33_START (8)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG32_35_classh3_lut_reg33_END (14)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG32_35_classh3_lut_reg34_START (16)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG32_35_classh3_lut_reg34_END (22)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG32_35_classh3_lut_reg35_START (24)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG32_35_classh3_lut_reg35_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh3_lut_reg36 : 7;
        unsigned int reserved_0 : 1;
        unsigned int classh3_lut_reg37 : 7;
        unsigned int reserved_1 : 1;
        unsigned int classh3_lut_reg38 : 7;
        unsigned int reserved_2 : 1;
        unsigned int classh3_lut_reg39 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ASP_CODEC_CLASSH3_LUT_REG36_39_UNION;
#endif
#define SOC_ASP_CODEC_CLASSH3_LUT_REG36_39_classh3_lut_reg36_START (0)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG36_39_classh3_lut_reg36_END (6)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG36_39_classh3_lut_reg37_START (8)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG36_39_classh3_lut_reg37_END (14)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG36_39_classh3_lut_reg38_START (16)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG36_39_classh3_lut_reg38_END (22)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG36_39_classh3_lut_reg39_START (24)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG36_39_classh3_lut_reg39_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh3_lut_reg40 : 7;
        unsigned int reserved_0 : 1;
        unsigned int classh3_lut_reg41 : 7;
        unsigned int reserved_1 : 1;
        unsigned int classh3_lut_reg42 : 7;
        unsigned int reserved_2 : 1;
        unsigned int classh3_lut_reg43 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ASP_CODEC_CLASSH3_LUT_REG40_43_UNION;
#endif
#define SOC_ASP_CODEC_CLASSH3_LUT_REG40_43_classh3_lut_reg40_START (0)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG40_43_classh3_lut_reg40_END (6)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG40_43_classh3_lut_reg41_START (8)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG40_43_classh3_lut_reg41_END (14)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG40_43_classh3_lut_reg42_START (16)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG40_43_classh3_lut_reg42_END (22)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG40_43_classh3_lut_reg43_START (24)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG40_43_classh3_lut_reg43_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh3_lut_reg44 : 7;
        unsigned int reserved_0 : 1;
        unsigned int classh3_lut_reg45 : 7;
        unsigned int reserved_1 : 1;
        unsigned int classh3_lut_reg46 : 7;
        unsigned int reserved_2 : 1;
        unsigned int classh3_lut_reg47 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ASP_CODEC_CLASSH3_LUT_REG44_47_UNION;
#endif
#define SOC_ASP_CODEC_CLASSH3_LUT_REG44_47_classh3_lut_reg44_START (0)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG44_47_classh3_lut_reg44_END (6)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG44_47_classh3_lut_reg45_START (8)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG44_47_classh3_lut_reg45_END (14)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG44_47_classh3_lut_reg46_START (16)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG44_47_classh3_lut_reg46_END (22)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG44_47_classh3_lut_reg47_START (24)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG44_47_classh3_lut_reg47_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh3_lut_reg48 : 7;
        unsigned int reserved_0 : 1;
        unsigned int classh3_lut_reg49 : 7;
        unsigned int reserved_1 : 1;
        unsigned int classh3_lut_reg50 : 7;
        unsigned int reserved_2 : 1;
        unsigned int classh3_lut_reg51 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ASP_CODEC_CLASSH3_LUT_REG48_51_UNION;
#endif
#define SOC_ASP_CODEC_CLASSH3_LUT_REG48_51_classh3_lut_reg48_START (0)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG48_51_classh3_lut_reg48_END (6)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG48_51_classh3_lut_reg49_START (8)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG48_51_classh3_lut_reg49_END (14)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG48_51_classh3_lut_reg50_START (16)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG48_51_classh3_lut_reg50_END (22)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG48_51_classh3_lut_reg51_START (24)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG48_51_classh3_lut_reg51_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh3_lut_reg52 : 7;
        unsigned int reserved_0 : 1;
        unsigned int classh3_lut_reg53 : 7;
        unsigned int reserved_1 : 1;
        unsigned int classh3_lut_reg54 : 7;
        unsigned int reserved_2 : 1;
        unsigned int classh3_lut_reg55 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ASP_CODEC_CLASSH3_LUT_REG52_55_UNION;
#endif
#define SOC_ASP_CODEC_CLASSH3_LUT_REG52_55_classh3_lut_reg52_START (0)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG52_55_classh3_lut_reg52_END (6)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG52_55_classh3_lut_reg53_START (8)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG52_55_classh3_lut_reg53_END (14)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG52_55_classh3_lut_reg54_START (16)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG52_55_classh3_lut_reg54_END (22)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG52_55_classh3_lut_reg55_START (24)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG52_55_classh3_lut_reg55_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh3_lut_reg56 : 7;
        unsigned int reserved_0 : 1;
        unsigned int classh3_lut_reg57 : 7;
        unsigned int reserved_1 : 1;
        unsigned int classh3_lut_reg58 : 7;
        unsigned int reserved_2 : 1;
        unsigned int classh3_lut_reg59 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ASP_CODEC_CLASSH3_LUT_REG56_59_UNION;
#endif
#define SOC_ASP_CODEC_CLASSH3_LUT_REG56_59_classh3_lut_reg56_START (0)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG56_59_classh3_lut_reg56_END (6)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG56_59_classh3_lut_reg57_START (8)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG56_59_classh3_lut_reg57_END (14)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG56_59_classh3_lut_reg58_START (16)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG56_59_classh3_lut_reg58_END (22)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG56_59_classh3_lut_reg59_START (24)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG56_59_classh3_lut_reg59_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh3_lut_reg60 : 7;
        unsigned int reserved_0 : 1;
        unsigned int classh3_lut_reg61 : 7;
        unsigned int reserved_1 : 1;
        unsigned int classh3_lut_reg62 : 7;
        unsigned int reserved_2 : 1;
        unsigned int classh3_lut_reg63 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ASP_CODEC_CLASSH3_LUT_REG60_63_UNION;
#endif
#define SOC_ASP_CODEC_CLASSH3_LUT_REG60_63_classh3_lut_reg60_START (0)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG60_63_classh3_lut_reg60_END (6)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG60_63_classh3_lut_reg61_START (8)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG60_63_classh3_lut_reg61_END (14)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG60_63_classh3_lut_reg62_START (16)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG60_63_classh3_lut_reg62_END (22)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG60_63_classh3_lut_reg63_START (24)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG60_63_classh3_lut_reg63_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int classh3_lut_reg64 : 7;
        unsigned int reserved_0 : 1;
        unsigned int classh3_lut_reg65 : 7;
        unsigned int reserved_1 : 1;
        unsigned int classh3_lut_reg66 : 7;
        unsigned int reserved_2 : 1;
        unsigned int classh3_lut_reg67 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ASP_CODEC_CLASSH3_LUT_REG64_67_UNION;
#endif
#define SOC_ASP_CODEC_CLASSH3_LUT_REG64_67_classh3_lut_reg64_START (0)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG64_67_classh3_lut_reg64_END (6)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG64_67_classh3_lut_reg65_START (8)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG64_67_classh3_lut_reg65_END (14)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG64_67_classh3_lut_reg66_START (16)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG64_67_classh3_lut_reg66_END (22)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG64_67_classh3_lut_reg67_START (24)
#define SOC_ASP_CODEC_CLASSH3_LUT_REG64_67_classh3_lut_reg67_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 5;
        unsigned int mic4_up_fifo_aempty_th : 5;
        unsigned int mic4_up_fifo_afull_th : 5;
        unsigned int mic4_up_fifo_clr : 1;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_ASP_CODEC_MIC4_UP_AFIFO_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_MIC4_UP_AFIFO_CTRL_mic4_up_fifo_aempty_th_START (5)
#define SOC_ASP_CODEC_MIC4_UP_AFIFO_CTRL_mic4_up_fifo_aempty_th_END (9)
#define SOC_ASP_CODEC_MIC4_UP_AFIFO_CTRL_mic4_up_fifo_afull_th_START (10)
#define SOC_ASP_CODEC_MIC4_UP_AFIFO_CTRL_mic4_up_fifo_afull_th_END (14)
#define SOC_ASP_CODEC_MIC4_UP_AFIFO_CTRL_mic4_up_fifo_clr_START (15)
#define SOC_ASP_CODEC_MIC4_UP_AFIFO_CTRL_mic4_up_fifo_clr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 5;
        unsigned int adc3_spi_up_fifo_aempty_th : 5;
        unsigned int adc3_spi_up_fifo_afull_th : 5;
        unsigned int adc3_spi_up_fifo_clr : 1;
        unsigned int reserved_1 : 5;
        unsigned int adc3_spv_up_fifo_aempty_th : 5;
        unsigned int adc3_spv_up_fifo_afull_th : 5;
        unsigned int adc3_spv_up_fifo_clr : 1;
    } reg;
} SOC_ASP_CODEC_ADC3_SPA_UP_AFIFO_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_ADC3_SPA_UP_AFIFO_CTRL_adc3_spi_up_fifo_aempty_th_START (5)
#define SOC_ASP_CODEC_ADC3_SPA_UP_AFIFO_CTRL_adc3_spi_up_fifo_aempty_th_END (9)
#define SOC_ASP_CODEC_ADC3_SPA_UP_AFIFO_CTRL_adc3_spi_up_fifo_afull_th_START (10)
#define SOC_ASP_CODEC_ADC3_SPA_UP_AFIFO_CTRL_adc3_spi_up_fifo_afull_th_END (14)
#define SOC_ASP_CODEC_ADC3_SPA_UP_AFIFO_CTRL_adc3_spi_up_fifo_clr_START (15)
#define SOC_ASP_CODEC_ADC3_SPA_UP_AFIFO_CTRL_adc3_spi_up_fifo_clr_END (15)
#define SOC_ASP_CODEC_ADC3_SPA_UP_AFIFO_CTRL_adc3_spv_up_fifo_aempty_th_START (21)
#define SOC_ASP_CODEC_ADC3_SPA_UP_AFIFO_CTRL_adc3_spv_up_fifo_aempty_th_END (25)
#define SOC_ASP_CODEC_ADC3_SPA_UP_AFIFO_CTRL_adc3_spv_up_fifo_afull_th_START (26)
#define SOC_ASP_CODEC_ADC3_SPA_UP_AFIFO_CTRL_adc3_spv_up_fifo_afull_th_END (30)
#define SOC_ASP_CODEC_ADC3_SPA_UP_AFIFO_CTRL_adc3_spv_up_fifo_clr_START (31)
#define SOC_ASP_CODEC_ADC3_SPA_UP_AFIFO_CTRL_adc3_spv_up_fifo_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 5;
        unsigned int adc2_spi_up_fifo_aempty_th : 5;
        unsigned int adc2_spi_up_fifo_afull_th : 5;
        unsigned int adc2_spi_up_fifo_clr : 1;
        unsigned int reserved_1 : 5;
        unsigned int adc2_spv_up_fifo_aempty_th : 5;
        unsigned int adc2_spv_up_fifo_afull_th : 5;
        unsigned int adc2_spv_up_fifo_clr : 1;
    } reg;
} SOC_ASP_CODEC_ADC2_SPA_UP_AFIFO_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_ADC2_SPA_UP_AFIFO_CTRL_adc2_spi_up_fifo_aempty_th_START (5)
#define SOC_ASP_CODEC_ADC2_SPA_UP_AFIFO_CTRL_adc2_spi_up_fifo_aempty_th_END (9)
#define SOC_ASP_CODEC_ADC2_SPA_UP_AFIFO_CTRL_adc2_spi_up_fifo_afull_th_START (10)
#define SOC_ASP_CODEC_ADC2_SPA_UP_AFIFO_CTRL_adc2_spi_up_fifo_afull_th_END (14)
#define SOC_ASP_CODEC_ADC2_SPA_UP_AFIFO_CTRL_adc2_spi_up_fifo_clr_START (15)
#define SOC_ASP_CODEC_ADC2_SPA_UP_AFIFO_CTRL_adc2_spi_up_fifo_clr_END (15)
#define SOC_ASP_CODEC_ADC2_SPA_UP_AFIFO_CTRL_adc2_spv_up_fifo_aempty_th_START (21)
#define SOC_ASP_CODEC_ADC2_SPA_UP_AFIFO_CTRL_adc2_spv_up_fifo_aempty_th_END (25)
#define SOC_ASP_CODEC_ADC2_SPA_UP_AFIFO_CTRL_adc2_spv_up_fifo_afull_th_START (26)
#define SOC_ASP_CODEC_ADC2_SPA_UP_AFIFO_CTRL_adc2_spv_up_fifo_afull_th_END (30)
#define SOC_ASP_CODEC_ADC2_SPA_UP_AFIFO_CTRL_adc2_spv_up_fifo_clr_START (31)
#define SOC_ASP_CODEC_ADC2_SPA_UP_AFIFO_CTRL_adc2_spv_up_fifo_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 12;
        unsigned int mic4_adc_hpf_bypass_en : 1;
        unsigned int mic4_adc_hbfvd_bypass_en : 1;
        unsigned int mic4_adc_hbf2d_bypass_en : 1;
        unsigned int mic4_adc_compd_bypass_en : 1;
        unsigned int mic4_adc_cic_gain : 6;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_ASP_CODEC_MIC4_ADC_FILTER_UNION;
#endif
#define SOC_ASP_CODEC_MIC4_ADC_FILTER_mic4_adc_hpf_bypass_en_START (12)
#define SOC_ASP_CODEC_MIC4_ADC_FILTER_mic4_adc_hpf_bypass_en_END (12)
#define SOC_ASP_CODEC_MIC4_ADC_FILTER_mic4_adc_hbfvd_bypass_en_START (13)
#define SOC_ASP_CODEC_MIC4_ADC_FILTER_mic4_adc_hbfvd_bypass_en_END (13)
#define SOC_ASP_CODEC_MIC4_ADC_FILTER_mic4_adc_hbf2d_bypass_en_START (14)
#define SOC_ASP_CODEC_MIC4_ADC_FILTER_mic4_adc_hbf2d_bypass_en_END (14)
#define SOC_ASP_CODEC_MIC4_ADC_FILTER_mic4_adc_compd_bypass_en_START (15)
#define SOC_ASP_CODEC_MIC4_ADC_FILTER_mic4_adc_compd_bypass_en_END (15)
#define SOC_ASP_CODEC_MIC4_ADC_FILTER_mic4_adc_cic_gain_START (16)
#define SOC_ASP_CODEC_MIC4_ADC_FILTER_mic4_adc_cic_gain_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mic4_adc_dc_offset : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_CODEC_CODEC_MIC4_DC_OFFSET_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_MIC4_DC_OFFSET_mic4_adc_dc_offset_START (0)
#define SOC_ASP_CODEC_CODEC_MIC4_DC_OFFSET_mic4_adc_dc_offset_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int spa1_sdm_dc_offset : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_CODEC_SPA1_SDM_DC_OFFSET_UNION;
#endif
#define SOC_ASP_CODEC_SPA1_SDM_DC_OFFSET_spa1_sdm_dc_offset_START (0)
#define SOC_ASP_CODEC_SPA1_SDM_DC_OFFSET_spa1_sdm_dc_offset_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int spa2_sdm_dc_offset : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_CODEC_SPA2_SDM_DC_OFFSET_UNION;
#endif
#define SOC_ASP_CODEC_SPA2_SDM_DC_OFFSET_spa2_sdm_dc_offset_START (0)
#define SOC_ASP_CODEC_SPA2_SDM_DC_OFFSET_spa2_sdm_dc_offset_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int spa3_sdm_dc_offset : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_CODEC_SPA3_SDM_DC_OFFSET_UNION;
#endif
#define SOC_ASP_CODEC_SPA3_SDM_DC_OFFSET_spa3_sdm_dc_offset_START (0)
#define SOC_ASP_CODEC_SPA3_SDM_DC_OFFSET_spa3_sdm_dc_offset_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sif2_spa_dac_en : 1;
        unsigned int sif2_spa_adc_en : 1;
        unsigned int sif3_spa_dac_en : 1;
        unsigned int sif3_spa_adc_en : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_ASP_CODEC_SIF2_3_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_SIF2_3_CTRL_sif2_spa_dac_en_START (0)
#define SOC_ASP_CODEC_SIF2_3_CTRL_sif2_spa_dac_en_END (0)
#define SOC_ASP_CODEC_SIF2_3_CTRL_sif2_spa_adc_en_START (1)
#define SOC_ASP_CODEC_SIF2_3_CTRL_sif2_spa_adc_en_END (1)
#define SOC_ASP_CODEC_SIF2_3_CTRL_sif3_spa_dac_en_START (2)
#define SOC_ASP_CODEC_SIF2_3_CTRL_sif3_spa_dac_en_END (2)
#define SOC_ASP_CODEC_SIF2_3_CTRL_sif3_spa_adc_en_START (3)
#define SOC_ASP_CODEC_SIF2_3_CTRL_sif3_spa_adc_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int spa2_mixer4_gain1 : 2;
        unsigned int spa2_mixer4_gain2 : 2;
        unsigned int spa2_mixer4_gain3 : 2;
        unsigned int spa2_mixer4_gain4 : 2;
        unsigned int spa2_mixer4_in1_mute : 1;
        unsigned int spa2_mixer4_in2_mute : 1;
        unsigned int spa2_mixer4_in3_mute : 1;
        unsigned int spa2_mixer4_in4_mute : 1;
        unsigned int spa2_mixer4_in1_id : 2;
        unsigned int spa2_mixer4_in2_id : 2;
        unsigned int spa2_mixer4_in3_id : 2;
        unsigned int spa2_mixer4_in4_id : 2;
    } reg;
} SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_UNION;
#endif
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_gain1_START (12)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_gain1_END (13)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_gain2_START (14)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_gain2_END (15)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_gain3_START (16)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_gain3_END (17)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_gain4_START (18)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_gain4_END (19)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_in1_mute_START (20)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_in1_mute_END (20)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_in2_mute_START (21)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_in2_mute_END (21)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_in3_mute_START (22)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_in3_mute_END (22)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_in4_mute_START (23)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_in4_mute_END (23)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_in1_id_START (24)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_in1_id_END (25)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_in2_id_START (26)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_in2_id_END (27)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_in3_id_START (28)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_in3_id_END (29)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_in4_id_START (30)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_in4_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 16;
        unsigned int spa2_mixer4_zero_num : 5;
        unsigned int spa2_mixer4_fade_out : 5;
        unsigned int spa2_mixer4_fade_in : 5;
        unsigned int spa2_mixer4_fade_en : 1;
    } reg;
} SOC_ASP_CODEC_SPA2_MIXER4_CTRL1_UNION;
#endif
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL1_spa2_mixer4_zero_num_START (16)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL1_spa2_mixer4_zero_num_END (20)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL1_spa2_mixer4_fade_out_START (21)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL1_spa2_mixer4_fade_out_END (25)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL1_spa2_mixer4_fade_in_START (26)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL1_spa2_mixer4_fade_in_END (30)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL1_spa2_mixer4_fade_en_START (31)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL1_spa2_mixer4_fade_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int spa3_mixer4_gain1 : 2;
        unsigned int spa3_mixer4_gain2 : 2;
        unsigned int spa3_mixer4_gain3 : 2;
        unsigned int spa3_mixer4_gain4 : 2;
        unsigned int spa3_mixer4_in1_mute : 1;
        unsigned int spa3_mixer4_in2_mute : 1;
        unsigned int spa3_mixer4_in3_mute : 1;
        unsigned int spa3_mixer4_in4_mute : 1;
        unsigned int spa3_mixer4_in1_id : 2;
        unsigned int spa3_mixer4_in2_id : 2;
        unsigned int spa3_mixer4_in3_id : 2;
        unsigned int spa3_mixer4_in4_id : 2;
    } reg;
} SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_UNION;
#endif
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_gain1_START (12)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_gain1_END (13)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_gain2_START (14)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_gain2_END (15)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_gain3_START (16)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_gain3_END (17)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_gain4_START (18)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_gain4_END (19)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_in1_mute_START (20)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_in1_mute_END (20)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_in2_mute_START (21)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_in2_mute_END (21)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_in3_mute_START (22)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_in3_mute_END (22)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_in4_mute_START (23)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_in4_mute_END (23)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_in1_id_START (24)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_in1_id_END (25)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_in2_id_START (26)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_in2_id_END (27)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_in3_id_START (28)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_in3_id_END (29)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_in4_id_START (30)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_in4_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 16;
        unsigned int spa3_mixer4_zero_num : 5;
        unsigned int spa3_mixer4_fade_out : 5;
        unsigned int spa3_mixer4_fade_in : 5;
        unsigned int spa3_mixer4_fade_en : 1;
    } reg;
} SOC_ASP_CODEC_SPA3_MIXER4_CTRL1_UNION;
#endif
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL1_spa3_mixer4_zero_num_START (16)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL1_spa3_mixer4_zero_num_END (20)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL1_spa3_mixer4_fade_out_START (21)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL1_spa3_mixer4_fade_out_END (25)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL1_spa3_mixer4_fade_in_START (26)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL1_spa3_mixer4_fade_in_END (30)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL1_spa3_mixer4_fade_en_START (31)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL1_spa3_mixer4_fade_en_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
