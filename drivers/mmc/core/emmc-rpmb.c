#include <linux/mmc/host.h>
#include <linux/mmc/card.h>
#include <linux/mmc/mmc.h>
#include "emmc-rpmb.h"
#ifdef CONFIG_HISI_BOOTDEVICE
#include <linux/bootdevice.h>
#endif

/**
 * emmc_get_rpmb_info - get rpmb info from emmc device and set the rpmb config
 *
 */
void emmc_get_rpmb_info(struct mmc_card *card, u8 *ext_csd)
{
		struct rpmb_config_info rpmb_config = {0};

		/*according to WR_REL_PARAM bit 4 to set max rpmb frames*/
		card->ext_csd.raw_wr_rel_param = ext_csd[EXT_CSD_WR_REL_PARAM];
		if(((card->ext_csd.raw_wr_rel_param >> 4) & 0x1) == 1)
			rpmb_config.rpmb_write_frame_support = ((uint64_t)1 << 31) | ((uint64_t)1 << 1) | ((uint64_t)1 << 0);
		else
			rpmb_config.rpmb_write_frame_support = ((uint64_t)1 << 1) | ((uint64_t)1 << 0);
		set_rpmb_write_frame_support(rpmb_config.rpmb_write_frame_support);
		set_rpmb_config_ready_status();
}