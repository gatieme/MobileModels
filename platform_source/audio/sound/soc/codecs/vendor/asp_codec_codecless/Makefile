GCOV_PROFILE := $(CONFIG_GCOV_KERNEL)
EXTRA_CFLAGS += -I$(srctree)/platform_source/audio/sound/soc/codecs/vendor/
EXTRA_CFLAGS += -I$(srctree)/include/linux/platform_drivers/
EXTRA_CFLAGS += -I$(srctree)/platform_source/audio/sound/soc/platforms/common_image/
EXTRA_CFLAGS += -I$(srctree)/platform_source/audio/sound/soc/codecs/vendor/asp_codec_ana/
EXTRA_CFLAGS += -I$(srctree)/platform_source/audio/include/
EXTRA_CFLAGS += -I$(srctree)/platform_source/audio/drivers/soc_mad/

snd-soc-asp-codec-utils-objs :=asp_codec_utils.o
snd-soc-asp-codec-store-objs :=asp_codec_store.o
snd-soc-asp-codec-v1-objs :=asp_codec_v1.o
snd-soc-asp-codec-control-objs :=asp_codec_control.o
snd-soc-asp-codec-play-path-objs :=asp_codec_play_path.o
snd-soc-asp-codec-8pa-path-objs :=asp_codec_8pa_path.o
snd-soc-asp-codec-uplink-path-objs :=asp_codec_uplink_path.o
snd-soc-asp-codec-au_pa-path-objs :=asp_codec_au_pa_path.o
snd-soc-asp-codec-btfm-path-objs :=asp_codec_btfm_path.o
snd-soc-asp-codec-sidetone-path-objs :=asp_codec_sidetone_path.o
snd-soc-asp-codec-rda-proxy-objs :=asp_codec_rda_proxy.o

obj-$(CONFIG_SND_SOC_ASP_CODEC_UTILS) += snd-soc-asp-codec-utils.o
obj-$(CONFIG_SND_SOC_ASP_CODEC_STORE) += snd-soc-asp-codec-store.o
obj-$(CONFIG_SND_SOC_ASP_CODEC_V1) += snd-soc-asp-codec-v1.o
obj-$(CONFIG_SND_SOC_ASP_CODEC_CONTROL) += snd-soc-asp-codec-control.o
obj-$(CONFIG_SND_SOC_ASP_CODEC_PLAY_PATH) += snd-soc-asp-codec-play-path.o
obj-$(CONFIG_SND_SOC_ASP_CODEC_8PA_PATH) += snd-soc-asp-codec-8pa-path.o
obj-$(CONFIG_SND_SOC_ASP_CODEC_UPLINK_PATH) += snd-soc-asp-codec-uplink-path.o
obj-$(CONFIG_SND_SOC_ASP_CODEC_AU_PA_PATH) += snd-soc-asp-codec-au_pa-path.o
obj-$(CONFIG_SND_SOC_ASP_CODEC_BTFM_PATH) += snd-soc-asp-codec-btfm-path.o
obj-$(CONFIG_SND_SOC_ASP_CODEC_SIDETONE_PATH) += snd-soc-asp-codec-sidetone-path.o

snd-soc-asp-codec-v2-objs :=asp_codec_v2.o
snd-soc-asp-codec-uplink-v2-path-objs :=asp_codec_uplink_v2_path.o
snd-soc-asp-codec-mad-path-objs :=asp_codec_mad_path.o
snd-soc-asp-codec-axi2tdm-path-objs :=asp_codec_axi2tdm_path.o
snd-soc-asp-codec-mad-v2-path-objs :=asp_codec_mad_v2_path.o

obj-$(CONFIG_SND_SOC_ASP_CODEC_V2N) += snd-soc-asp-codec-utils.o
obj-$(CONFIG_SND_SOC_ASP_CODEC_V2N) += snd-soc-asp-codec-store.o
obj-$(CONFIG_SND_SOC_ASP_CODEC_V2N) += snd-soc-asp-codec-control.o
obj-$(CONFIG_SND_SOC_ASP_CODEC_V2N) += snd-soc-asp-codec-v2.o
obj-$(CONFIG_SND_SOC_ASP_CODEC_V2N) += snd-soc-asp-codec-uplink-v2-path.o
obj-$(CONFIG_SND_SOC_ASP_CODEC_V2N) += snd-soc-asp-codec-play-path.o
obj-$(CONFIG_SND_SOC_ASP_CODEC_V2N) += snd-soc-asp-codec-btfm-path.o

obj-$(CONFIG_SND_SOC_ASP_CODEC_V2C) += snd-soc-asp-codec-utils.o
obj-$(CONFIG_SND_SOC_ASP_CODEC_V2C) += snd-soc-asp-codec-store.o
obj-$(CONFIG_SND_SOC_ASP_CODEC_V2C) += snd-soc-asp-codec-control.o
obj-$(CONFIG_SND_SOC_ASP_CODEC_V2C) += snd-soc-asp-codec-v2.o
obj-$(CONFIG_SND_SOC_ASP_CODEC_V2C) += snd-soc-asp-codec-uplink-v2-path.o
obj-$(CONFIG_SND_SOC_ASP_CODEC_V2C) += snd-soc-asp-codec-play-path.o
obj-$(CONFIG_SND_SOC_ASP_CODEC_V2C) += snd-soc-asp-codec-btfm-path.o
obj-$(CONFIG_SND_SOC_ASP_CODEC_V2C) += snd-soc-asp-codec-sidetone-path.o

obj-$(CONFIG_SND_SOC_ASP_CODEC_V2CP) += snd-soc-asp-codec-utils.o
obj-$(CONFIG_SND_SOC_ASP_CODEC_V2CP) += snd-soc-asp-codec-store.o
obj-$(CONFIG_SND_SOC_ASP_CODEC_V2CP) += snd-soc-asp-codec-control.o
obj-$(CONFIG_SND_SOC_ASP_CODEC_V2CP) += snd-soc-asp-codec-v2.o
obj-$(CONFIG_SND_SOC_ASP_CODEC_V2CP) += snd-soc-asp-codec-uplink-v2-path.o
obj-$(CONFIG_SND_SOC_ASP_CODEC_V2CP) += snd-soc-asp-codec-play-path.o
obj-$(CONFIG_SND_SOC_ASP_CODEC_V2CP) += snd-soc-asp-codec-btfm-path.o
obj-$(CONFIG_SND_SOC_ASP_CODEC_V2CP) += snd-soc-asp-codec-sidetone-path.o
obj-$(CONFIG_SND_SOC_ASP_CODEC_V2CP) += snd-soc-asp-codec-rda-proxy.o

obj-$(CONFIG_SND_SOC_ASP_CODEC_AXI2TDM) += snd-soc-asp-codec-axi2tdm-path.o
obj-$(CONFIG_SND_SOC_ASP_CODEC_MAD) += snd-soc-asp-codec-mad-path.o
obj-$(CONFIG_SND_SOC_ASP_CODEC_MAD_V2) += snd-soc-asp-codec-mad-v2-path.o
