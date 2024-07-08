#include <linux/io.h>
#include <linux/types.h>
#include <linux/delay.h>
#include <linux/err.h>

#include "hjpg160_debug.h"
#include "hjpg160_cfg_power_reg.h"
#include "hjpgenc160.h"
#include "hjpgenc160_cs.h"
#include "hjpg160_reg_offset.h"
#include "cam_log.h"

#if (POWER_CTRL_INTERFACE==POWER_CTRL_CFG_REGS)
static void __iomem *   viraddr_peri_crg    = NULL;
static void __iomem *   viraddr_sctr        = NULL;
static void __iomem *   viraddr_media_crg   = NULL;
static void __iomem *   viraddr_pmctrl      = NULL;

static int cfg_reg_sets(struct reg_sets* regSets);
static int cfg_reg_sets_array(struct reg_sets* pRegSets, int count);

static void __iomem* get_viraddr(u32 phy_base);
static void reg_op_write_all(void __iomem* base, struct reg_sets* regSets);
static void reg_op_bit_equal(void __iomem* base, struct reg_sets* regSets, int bit);
static void reg_op_status_equal(void __iomem* base, struct reg_sets* regSets);

static void reg_op_write_all(void __iomem* base, struct reg_sets* regSets)
{
    REG_SET(base+regSets->offset, regSets->val);
    if (regSets->wait_us > 0) {
        msleep(regSets->wait_us);
    }
}

static void reg_op_bit_equal(void __iomem* base, struct reg_sets* regSets, int bit)
{
    u32 val = 0;
    if (regSets->wait_us > 0) {
        msleep(regSets->wait_us);
    }
    val = REG_GET(base+regSets->offset) & (1<<bit);
    val = val>>bit;
    if (val != regSets->val) {
        cam_err("[%s] Failed: val(%d) is not equal expected(%d)\n", __func__, val, regSets->val);
        return;
    }
}

static void reg_op_status_equal(void __iomem* base, struct reg_sets* regSets)
{
    u32 val = 0;
    val = REG_GET(base + regSets->offset);
    cam_info("[%s] STAT.%s(0x%x), value(0x%x)\n", __func__, regSets->reg_name, regSets->offset, val);
    if (regSets->wait_us == 0)
    {
        val = ~val;
    }
    val = val & regSets->val;
    if (val != regSets->val)
    {
        cam_err("[%s] Failed: bits(0x%X) of value not expected(%d)\n", __func__, regSets->val, regSets->wait_us);
        return;
    }
}

static void __iomem* get_viraddr(u32 phy_base)
{
    void __iomem * base = NULL;

    switch (phy_base) {
        case REG_BASE_PERI_CRG:
            base = viraddr_peri_crg;
            break;
        case REG_BASE_SCTR:
            base = viraddr_sctr;
            break;
        case REG_BASE_MEDIA_CRG:
            base = viraddr_media_crg;
            break;
        case REG_BASE_PMCTRL:
            base = viraddr_pmctrl;
            break;
        default:
            break;
    }
    return base;
}

static int cfg_reg_sets(struct reg_sets* regSets)
{
    int ret = 0;
    void __iomem * base = get_viraddr(regSets->base);

    if (NULL == base) {
        cam_err("[%s] Failed: base viraddr of %s is NULL.\n", __func__, regSets->reg_name);
        return -EINVAL;
    }

    switch (regSets->op_flag) {
        case OP_WRITE_ALL:
            {
                reg_op_write_all(base, regSets);
            }
            break;
        case OP_READ_BIT15:
            {
                reg_op_bit_equal(base, regSets, 15);
            }
            break;
        case OP_READ_BIT5:
            {
                reg_op_bit_equal(base, regSets, 5);
            }
            break;
        case OP_READ_STATUS:
            {
                msleep(100);
                reg_op_status_equal(base, regSets);
            }
        default:
            break;
    }

    cam_info("%s: set reg %s success!", __func__, regSets->reg_name);

    return ret;
}

static int cfg_reg_sets_array(struct reg_sets* pRegSets, int count)
{
    int ret = 0;
    int i = 0;

    if (NULL == pRegSets) {
        cam_err("[%s] Failed: reg sets is NULL!\n", __func__);
        return -EINVAL;
    }

    for (i = 0; i < count; i++) {
        if ((ret = cfg_reg_sets(pRegSets+i)) != 0) {
            cam_err("[%s] Failed: config reg sets (%d), ret=%d\n", __func__, i, ret);
            break;
        }
    }

    return ret;
}

int cfg_map_reg_base(void)
{
    int ret = 0;
    viraddr_peri_crg = ioremap_nocache(REG_BASE_PERI_CRG, 4096);
    if (IS_ERR_OR_NULL(viraddr_peri_crg)){
        cam_err("%s (%d) remap peri_crg viraddr failed",__func__, __LINE__);
        ret = -ENXIO;
        goto fail;
    }

    viraddr_media_crg = ioremap_nocache(REG_BASE_MEDIA_CRG, 4096);
    if (IS_ERR_OR_NULL(viraddr_media_crg)){
        cam_err("%s (%d) remap media_crg viraddr failed",__func__, __LINE__);
        ret = -ENXIO;
        goto fail;
    }

    viraddr_sctr = ioremap_nocache(REG_BASE_SCTR, 4096);
    if (IS_ERR_OR_NULL(viraddr_sctr)){
        cam_err("%s (%d) remap sctr viraddr failed",__func__, __LINE__);
        ret = -ENXIO;
        goto fail;
    }

    viraddr_pmctrl = ioremap_nocache(REG_BASE_PMCTRL, 4096);
    if (IS_ERR_OR_NULL(viraddr_pmctrl)){
        cam_err("%s (%d) remap pmctrl viraddr failed",__func__, __LINE__);
        ret = -ENXIO;
        goto fail;
    }

fail:
    cfg_unmap_reg_base();

    return ret;
}
int cfg_unmap_reg_base(void)
{
    if (viraddr_media_crg) {
        iounmap((void*)viraddr_media_crg);
    }

    if (viraddr_peri_crg) {
        iounmap((void*)viraddr_peri_crg);
    }

    if (viraddr_sctr) {
        iounmap((void*)viraddr_sctr);
    }

    if (viraddr_pmctrl) {
        iounmap((void*)viraddr_pmctrl);
    }

    return 0;
}

int cfg_powerup_regs(void)
{
    int ret = 0;
    cam_info("%s: enter\n", __func__);

    ret |= cfg_reg_sets_array(media_subsys_powerup, sizeof(media_subsys_powerup)/sizeof(struct reg_sets));
    if (0 != ret) {
        cam_err("[%s] Failed: media subsys power up, ret=%d\n", __func__, ret);
    }
    ret |= cfg_reg_sets_array(vivobus_reg_sets_powerup, sizeof(vivobus_reg_sets_powerup)/sizeof(struct reg_sets));
    if (0 != ret) {
        cam_err("[%s] Failed: vivobus power up, ret=%d\n", __func__, ret);
    }
    ret |= cfg_reg_sets_array(isp_reg_sets_powerup, sizeof(isp_reg_sets_powerup)/sizeof(struct reg_sets));
    if (0 != ret) {
        cam_err("[%s] Failed: isp power up, ret=%d\n", __func__, ret);
    }

    return ret;
}

int cfg_powerdn_regs(void)
{
    int ret = 0;
    ret |= cfg_reg_sets_array(isp_reg_sets_powerdown, sizeof(isp_reg_sets_powerdown)/sizeof(struct reg_sets));
    if (0 != ret) {
        cam_err("[%s] Failed: isp power down, ret=%d\n", __func__, ret);
    }
#if 0
    ret |= cfg_reg_sets_array(vivobus_reg_sets_powerdown, sizeof(vivobus_reg_sets_powerdown)/sizeof(struct reg_sets));
    if (0 != ret) {
        cam_err("[%s] Failed: vivobus power down, ret=%d\n", __func__, ret);
    }
    ret |= cfg_reg_sets_array(media_subsys_powerdown, sizeof(media_subsys_powerdown)/sizeof(struct reg_sets));
    if (0 != ret) {
        cam_err("[%s] Failed: media subsys power down, ret=%d\n", __func__, ret);
    }
#endif

    return 0;
}
#endif//(POWER_CTRL_INTERFACE==POWER_CTRL_CFG_REGS)

#if DUMP_REGS
int dump_cvdr_reg(u32 chip_type, void __iomem * viraddr)
{
    if (NULL==viraddr) {
        cam_err("%s: viraddr is NULL", __func__);
        return -1;
    }

    if (chip_type == CT_ES) {
        cam_info("%s: CVDR reg: 0x%08x=0x%08x", __func__,
            CVDR_SRT_BASE+CVDR_SRT_VP_WR_CFG_25_OFFSET,
            REG_GET(viraddr+CVDR_SRT_VP_WR_CFG_25_OFFSET));
        cam_info("%s: CVDR reg: 0x%08x=0x%08x", __func__,
            CVDR_SRT_BASE+CVDR_SRT_VP_WR_AXI_FS_25_OFFSET,
            REG_GET(viraddr+CVDR_SRT_VP_WR_AXI_FS_25_OFFSET));
        cam_info("%s: CVDR reg: 0x%08x=0x%08x", __func__,
            CVDR_SRT_BASE+CVDR_SRT_VP_WR_AXI_LINE_25_OFFSET,
            REG_GET(viraddr+CVDR_SRT_VP_WR_AXI_LINE_25_OFFSET));
        cam_info("%s: CVDR reg: 0x%08x=0x%08x", __func__,
            CVDR_SRT_BASE+CVDR_SRT_VP_WR_IF_CFG_25_OFFSET,
            REG_GET(viraddr+CVDR_SRT_VP_WR_IF_CFG_25_OFFSET));
        cam_info("%s: CVDR reg: 0x%08x=0x%08x", __func__,
            CVDR_SRT_BASE+CVDR_SRT_NR_RD_CFG_1_OFFSET,
            REG_GET(viraddr+CVDR_SRT_NR_RD_CFG_1_OFFSET));
        cam_info("%s: CVDR reg: 0x%08x=0x%08x", __func__,
            CVDR_SRT_BASE+CVDR_SRT_LIMITER_NR_RD_1_OFFSET,
            REG_GET(viraddr+CVDR_SRT_LIMITER_NR_RD_1_OFFSET));
        cam_info("%s: CVDR reg: 0x%08x=0x%08x", __func__,
            CVDR_SRT_BASE+CVDR_SRT_LIMITER_VP_WR_25_OFFSET,
            REG_GET(viraddr+CVDR_SRT_LIMITER_VP_WR_25_OFFSET));
    } else if (chip_type == CT_CS) {
        cam_info("%s: CVDR reg: 0x%08x=0x%08x", __func__,
            REG_BASE_CVDR+CVDR_AXI_JPEG_VP_WR_CFG_0_OFFSET,
            REG_GET(viraddr+CVDR_AXI_JPEG_VP_WR_CFG_0_OFFSET));
        cam_info("%s: CVDR reg: 0x%08x=0x%08x", __func__,
            REG_BASE_CVDR+CVDR_AXI_JPEG_VP_WR_AXI_FS_0_OFFSET,
            REG_GET(viraddr+CVDR_AXI_JPEG_VP_WR_AXI_FS_0_OFFSET));
        cam_info("%s: CVDR reg: 0x%08x=0x%08x", __func__,
            REG_BASE_CVDR+CVDR_AXI_JPEG_VP_WR_AXI_LINE_0_OFFSET,
            REG_GET(viraddr+CVDR_AXI_JPEG_VP_WR_AXI_LINE_0_OFFSET));
        cam_info("%s: CVDR reg: 0x%08x=0x%08x", __func__,
            REG_BASE_CVDR+CVDR_AXI_JPEG_VP_WR_IF_CFG_0_OFFSET,
            REG_GET(viraddr+CVDR_AXI_JPEG_VP_WR_IF_CFG_0_OFFSET));
        cam_info("%s: CVDR reg: 0x%08x=0x%08x", __func__,
            REG_BASE_CVDR+CVDR_AXI_JPEG_LIMITER_VP_WR_0_OFFSET,
            REG_GET(viraddr+CVDR_AXI_JPEG_LIMITER_VP_WR_0_OFFSET));
        cam_info("%s: CVDR reg: 0x%08x=0x%08x", __func__,
            REG_BASE_CVDR+CVDR_AXI_JPEG_NR_RD_CFG_0_OFFSET,
            REG_GET(viraddr+CVDR_AXI_JPEG_NR_RD_CFG_0_OFFSET));
        cam_info("%s: CVDR reg: 0x%08x=0x%08x", __func__,
            REG_BASE_CVDR+CVDR_AXI_JPEG_LIMITER_NR_RD_0_OFFSET,
            REG_GET(viraddr+CVDR_AXI_JPEG_LIMITER_NR_RD_0_OFFSET));
    }
    return 0;
}
int dump_jpeg_reg(u32 chip_type, void __iomem * viraddr)
{
    int i;

    for (i = 0 ; i <= JPGENC_FORCE_CLK_ON_CFG_REG;) {
        cam_info("%s: jpeg reg 0x%x = 0x%x", __func__, i, REG_GET(viraddr + i));
        i += 4;
    }
    for (i = JPGENC_DBG_0_REG ; i <= JPGENC_DBG_13_REG;) {
        cam_info("%s: dbg reg 0x%x = 0x%x", __func__, i, REG_GET(viraddr + i));
        i += 4;
    }
    return 0;
}
#endif // DUMP_REGS
