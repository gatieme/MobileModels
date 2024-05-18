# Audiokit driver

obj-$(CONFIG_HONOR_DSM_AUDIO) += dsm_audio/
obj-$(CONFIG_HONOR_DEVICEBOX_AUDIO) += boxid/
obj-$(CONFIG_HONOR_SMARTPAKIT_AUDIO) += smartpakit/
obj-$(CONFIG_HONOR_ANA_HS_KIT_AUDIO) += ana_hs_kit/
obj-$(CONFIG_HONOR_ADSP_MISC) += adsp_misc/
obj-$(CONFIG_HONOR_ADSP_CHR) += adsp_chr/
ifneq ($(TARGET_BUILD_VARIANT), user)
	obj-y += headset_debug/
endif
