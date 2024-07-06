/*
 * Copyright(C) 2019-2020 Hisilicon Technologies Co., Ltd. All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include "mm_vsmmuv3.h"
#include <linux/io-pgtable.h>
#include <linux/of_fdt.h>
#include <linux/iommu/mm_svm.h>
#ifdef CONFIG_VM_PRESET
#include "vm_preset.h"
#endif

#define MM_SMMU_DEVICE_MAX      	9
#define MM_SMMU_SID_MAX             64

#define VSMMU_REGISTER_BYTE         1
#define VSMMU_REGISTER_WORD         2
#define VSMMU_REGISTER_LWORD        4
#define VSMMU_REGISTER_QWORD        8

#define VSMMU_CLK_VAL               0x1
#define VSMMU_PW_REG                0x30000

#define VSMMU_STRTAB_BASE			0x80
#define VSMMU_STRTAB_BASE_CFG		0x88

#define VSMMU_CMDQ_BASE				0x90
#define VSMMU_CMDQ_PROD				0x98
#define VSMMU_CMDQ_CONS				0x9c

#define VSMMU_EVTQ_BASE				0xa0
#define VSMMU_EVTQ_PROD				0x100a8
#define VSMMU_EVTQ_CONS				0x100ac

#define STRTAB_STE_DWORDS			8
#define DWORD_BYTES_NUM				3
#define STRTAB_L1_DESC_DWORDS		1

#define STRTAB_BASE_CFG_FMT_SHIFT	16
#define STRTAB_BASE_CFG_FMT_LINEAR	(0 << STRTAB_BASE_CFG_FMT_SHIFT)
#define STRTAB_BASE_CFG_FMT_2LVL	(1 << STRTAB_BASE_CFG_FMT_SHIFT)

#define STRTAB_BASE_ADDR_SHIFT		6
#define STRTAB_BASE_ADDR_MASK		0x3fffffffffffUL
#define STRTAB_BASE_CFG_LOG2SIZE_MASK	0x3f

#define STRTAB_STE_0_V				(1UL << 0)

#define STRTAB_STE_0_CFG_SHIFT      1
#define STRTAB_STE_0_CFG_S2_TRANS	(6UL << STRTAB_STE_0_CFG_SHIFT)

#define Q_BASE_ADDR_SHIFT			5
#define Q_BASE_ADDR_MASK			0xffffffffffffUL
#define Q_BASE_LOG2SIZE_SHIFT		0
#define Q_BASE_LOG2SIZE_MASK		0x1fUL


#define VSMMU_CMDQ_OPSCODE_MASK 	0xFF
#define CMDQ_PREFETCH_1_SIZE_MASK   0x1F

#define VSMMU_GUEST_VMID			60
#define VSMMU_STE_S2_ATTR_MASK      32

#define VSMMU_STE_S2TTB_MASK        0xFFFFFFFFFFFF0
#define VSMMU_STE_S2_ATTR           0x040C2055
#define VSMMU_STE_S2_ATTR_SHIFT     32
#define STRTAB_STE_2_AA64_SHIFT     19
#define STRTAB_STE_2_S2R_SHIFT      26

#define DT_ROOT_TTD_ADDR_CELLS		2
#define DT_ROOT_TTD_SIZE_CELLS		2
#define VSMMU_TTD_NUM_MAX           16
struct vsmmu_strtab_cfg {
	unsigned long			    *strtab;
	unsigned long				strtab_base;
	unsigned int				strtab_base_cfg;
};

struct vsmmu_queue {
	__le64		        *base;
	unsigned long		q_base;
	unsigned int		max_n_shift;
	unsigned int		prve_prod;
	unsigned int		prod;
	unsigned int		prve_cons;
	unsigned int		cons;
	size_t				ent_dwords;
};

struct vsmmu_cmdq {
	struct vsmmu_queue		q;
	spinlock_t			lock;
};

struct arm_vsmmu_device {
	unsigned int smmuid;
	int	status;
	int cnt;
	int cr0_status;
	int irq_ctrl;
	struct vsmmu_strtab_cfg	strtab_cfg;
	struct vsmmu_cmdq		cmdq;
	spinlock_t tcu_lock;
	struct list_head list;
};

static DEFINE_SPINLOCK(vsmmu_list_lock);

static struct arm_smmu_device *smmu_device[MM_SMMU_DEVICE_MAX] = {0};
struct list_head vsmmu_device_list;
struct io_pgtable_cfg pgtbl_cfg = {0};
static unsigned long long g_addr_map[VSMMU_TTD_NUM_MAX][2] = {0};

LIST_HEAD(vsmmu_device_list);

void set_vsmmu_device(struct arm_smmu_device *smmu)
{
	if (!smmu) {
		pr_err("%s, smmu is null\n", __func__);
		return;
	}

	if (smmu->smmuid >= MM_SMMU_DEVICE_MAX) {
		pr_err("%s, smmu id %d is beyond max\n", __func__, smmu->smmuid);
		return;
	}

	smmu_device[smmu->smmuid] = smmu;
	return;
}

void clear_vsmmu_device(struct arm_smmu_device *smmu)
{
	if (!smmu) {
		pr_err("%s, smmu is null\n", __func__);
		return;
	}

	if (smmu->smmuid >= MM_SMMU_DEVICE_MAX) {
		pr_err("%s, smmu id %d is beyond max\n", __func__, smmu->smmuid);
		return;
	}

	smmu_device[smmu->smmuid] = NULL;
	return;
}

struct arm_vsmmu_device *mm_vsmmu_device_find(unsigned int smmuid)
{
	struct arm_vsmmu_device *vsmmu = NULL;
	struct arm_vsmmu_device *tmp = NULL;
	unsigned long flags;

	spin_lock_irqsave(&vsmmu_list_lock, flags);
	list_for_each_entry_safe(vsmmu, tmp, &vsmmu_device_list, list) {
		if (vsmmu->smmuid == smmuid)
			goto vsmmu_find;
	}

	vsmmu = vzalloc(sizeof(*vsmmu));
	if (!vsmmu) {
		pr_err("%s, vzalloc vsmmu failed\n", __func__);
		goto vsmmu_find;
	}

	vsmmu->smmuid = smmuid;
	vsmmu->status = ARM_SMMU_DISABLE;
	vsmmu->cnt = 0;
	spin_lock_init(&vsmmu->tcu_lock);
	list_add_tail(&vsmmu->list, &vsmmu_device_list);

vsmmu_find:
	spin_unlock_irqrestore(&vsmmu_list_lock, flags);
	return vsmmu;
}

struct arm_vsmmu_device *get_vsmmu_by_id(int smmuid)
{
	struct arm_vsmmu_device *vsmmu = NULL;

	if (smmuid >= MM_SMMU_DEVICE_MAX) {
		pr_err("%s, smmu id %d is beyond max\n", __func__, smmuid);
		return NULL;
	}

	vsmmu = mm_vsmmu_device_find(smmuid);
	return vsmmu;
}

static void mm_vsmmu_build_s2ttd(unsigned int smmuid)
{
	struct io_pgtable_ops *pg_ops = NULL;
	struct arm_smmu_device *smmu = smmu_device[smmuid];
	int prot;
	unsigned long addr_size = 0;
	unsigned long iova = 0;
	unsigned long phys = 0;
	int ret;
	int i;

	if (pgtbl_cfg.ias)
		return;

	pgtbl_cfg = (struct io_pgtable_cfg) {
		.pgsize_bitmap	= smmu->pgsize_bitmap,
		.ias		= smmu->ias - 1,
		.oas		= smmu->oas,
		.iommu_dev	= smmu->dev,
	};

	pg_ops = alloc_io_pgtable_ops(ARM_64_LPAE_S2, &pgtbl_cfg, NULL);
	if (!pg_ops) {
		pr_err("%s: io pgtable ops alloc failed\n", __func__);
		return;
	}

	for (i = 0; i < VSMMU_TTD_NUM_MAX; i++) {
		addr_size = g_addr_map[i][1];
		iova = g_addr_map[i][0];
		phys = iova;

		while (addr_size) {
			ret = pg_ops->map(pg_ops, iova, phys, SZ_1G, IOMMU_READ | IOMMU_WRITE, GFP_KERNEL);
			if (ret) {
				pr_err("%s: stage2 map failed! iova 0x%llx\n", __func__, iova);
				return;
			}
			iova += SZ_1G;
			phys += SZ_1G;
			addr_size -= SZ_1G;
		}
	}

	if (!i)
		pr_err("%s: g_addr_map is NULL, s2ttb map failed\n", __func__);

	return;
}

long mm_vsmmu_tcu_poweron_finalise(struct arm_vsmmu_device *vsmmu)
{
	long ret = 0;
	struct arm_smmu_device *smmu = NULL;

	if (vsmmu->status == ARM_SMMU_ENABLE) {
		vsmmu->cnt++;
		pr_info("%s, VSMMU %d already power on, status is %d\n",
				 __func__, vsmmu->smmuid, vsmmu->status);
		return ret;
	}

	smmu = smmu_device[vsmmu->smmuid];
	if (!smmu) {
		pr_err("%s, smmu device %d has not probed.\n", __func__, vsmmu->smmuid);
		return -EINVAL;
	}

	return arm_smmu_tcu_poweron(smmu);
}

long mm_vsmmu_tcu_poweroff_finalise(struct arm_vsmmu_device *vsmmu)
{
	long ret = 0;
	struct arm_smmu_device *smmu = NULL;
	smmu = smmu_device[vsmmu->smmuid];
	if (!smmu) {
		pr_err("%s, smmu device %d has not probed.\n", __func__, vsmmu->smmuid);
		return -EINVAL;
	}

	return arm_smmu_tcu_poweroff(smmu);
}

static unsigned long mm_vsmmu_cmdq_sync_cons(struct arm_vsmmu_device *vsmmu,
			struct arm_smmu_device *smmu)
{
	unsigned long cons, prods, vcons, vprods;
	void __iomem *io_base = smmu->base;
	struct vsmmu_queue *vq = &vsmmu->cmdq.q;
	struct arm_smmu_queue *q = &smmu->cmdq.q;
	unsigned long flags;

	spin_lock_irqsave(&smmu->tcu_lock, flags);
	vprods = Q_WRP(vq, vq->prod) | Q_IDX(vq, vq->prod);
	prods = readl_relaxed(io_base + VSMMU_CMDQ_PROD);
	cons = readl_relaxed(io_base + VSMMU_CMDQ_CONS);
	if ((Q_IDX(q, prods) == Q_IDX(q, prods)) &&
		(Q_WRP(q, cons) == Q_WRP(q, cons)))
		vq->cons = vprods;

	spin_unlock_irqrestore(&smmu->tcu_lock, flags);
	return vq->cons;
}

static unsigned long mm_vsmmu_direct_read(struct arm_smmu_device *smmu,
					unsigned int offset, unsigned int size)
{
	unsigned long ret = 0;
	void __iomem *io_base = NULL;

	io_base = smmu->base;
	if (!io_base) {
		pr_err("%s, smmu io base get failed\n", __func__);
		return ret;
	}

	switch(size) {
	case VSMMU_REGISTER_BYTE:
		ret = (unsigned long)readb_relaxed(io_base + offset);
		break;
	case VSMMU_REGISTER_WORD:
		ret = (unsigned long)readw_relaxed(io_base + offset);
		break;
	case VSMMU_REGISTER_LWORD:
		ret = (unsigned long)readl_relaxed(io_base + offset);
		break;
	case VSMMU_REGISTER_QWORD:
		ret = (unsigned long)readq_relaxed(io_base + offset);
		break;
	default:
		pr_err("%s, vsmmu_info size %d is error\n", __func__, size);
		return ret;
	}

	return ret;
}

long mm_vsmmu_ioc_read_reg(unsigned int smmuid, unsigned int offset,
						unsigned int size, unsigned long *value)
{
	unsigned long ret;
	struct arm_vsmmu_device *vsmmu = NULL;
	struct arm_smmu_device *smmu = NULL;

	vsmmu = get_vsmmu_by_id(smmuid);
	if (!vsmmu || (!vsmmu->status && offset != VSMMU_PW_REG)) {
		pr_err("%s, smmu device [%d] has not power on\n", __func__, smmuid);
		return -EINVAL;
	}

	smmu = smmu_device[vsmmu->smmuid];
	if (!smmu) {
		pr_err("%s, smmu device has not been probed\n", __func__);
		return NULL;
	}

	switch(offset) {
	case VSMMU_CMDQ_CONS:
		ret = mm_vsmmu_cmdq_sync_cons(vsmmu, smmu);
		break;
	case ARM_SMMU_CR0ACK:
		ret = (unsigned long)vsmmu->cr0_status;
		break;
	case ARM_SMMU_IRQ_CTRLACK:
		ret = (unsigned long)vsmmu->irq_ctrl;
		break;
	default:
		ret = mm_vsmmu_direct_read(smmu, offset, size);
	}

	*value = ret;
	return 0;
}
EXPORT_SYMBOL(mm_vsmmu_ioc_read_reg);

static long mm_vsmmu_ioc_poweron(unsigned int smmuid)
{
	struct arm_vsmmu_device *vsmmu = NULL;
	long ret = 0;
	unsigned long flags;

	vsmmu = mm_vsmmu_device_find(smmuid);
	if (!vsmmu)
		return -EINVAL;

	spin_lock_irqsave(&vsmmu->tcu_lock, flags);
	ret = mm_vsmmu_tcu_poweron_finalise(vsmmu);
	if (ret) {
		pr_err("%s, VSMMU %d power on failed.\n", __func__, vsmmu->smmuid);
		goto unlock_power;
	}

	vsmmu->status = ARM_SMMU_ENABLE;
	vsmmu->cnt++;

unlock_power:
	spin_unlock_irqrestore(&vsmmu->tcu_lock, flags);
	return ret;
}

static long mm_vsmmu_ioc_poweroff(unsigned int smmuid)
{
	struct arm_vsmmu_device *vsmmu = NULL;
	long ret;
	unsigned long flags;

	vsmmu = mm_vsmmu_device_find(smmuid);
	if (!vsmmu)
		return -EINVAL;

	spin_lock_irqsave(&vsmmu->tcu_lock, flags);
	if ((vsmmu->status == ARM_SMMU_DISABLE) || --vsmmu->cnt) {
		goto unlock_power;
	}

	vsmmu->status = ARM_SMMU_DISABLE;
	ret = mm_vsmmu_tcu_poweroff_finalise(vsmmu);
	if (ret)
		pr_err("%s, VSMMU %d power off failed.\n", __func__, vsmmu->smmuid);

unlock_power:
	spin_unlock_irqrestore(&vsmmu->tcu_lock, flags);
	return ret;
}

/* When the TCU is powered on, the PW internal register is enabled.
When the TCU is powered off, the PW internal register is disabled.
We can power on and off the TCU on the host based on the PW internal register.
*/
static long mm_vsmmu_power_contrl(unsigned int smmuid, unsigned long value)
{
	unsigned long ret;

	if (value & VSMMU_CLK_VAL) {
		ret = mm_vsmmu_ioc_poweron(smmuid);
	} else {
		ret = mm_vsmmu_ioc_poweroff(smmuid);
	}

	return ret;
}

static void vsmmu_strtab_map(struct arm_vsmmu_device *vsmmu)
{
	unsigned long addr_base;
	unsigned long addr_size;
	unsigned int size;
	unsigned int vsmmu_strtab_cfg = vsmmu->strtab_cfg.strtab_base_cfg;

	size = vsmmu_strtab_cfg & STRTAB_BASE_CFG_LOG2SIZE_MASK;
	if (vsmmu_strtab_cfg & STRTAB_BASE_CFG_FMT_2LVL) {
		addr_size =(1 << size) * (STRTAB_L1_DESC_DWORDS << DWORD_BYTES_NUM);
	} else {
		addr_size = (1 << size) * (STRTAB_STE_DWORDS << DWORD_BYTES_NUM);
	}

	addr_base = vsmmu->strtab_cfg.strtab_base &
				STRTAB_BASE_ADDR_MASK << STRTAB_BASE_ADDR_SHIFT;
	vsmmu->strtab_cfg.strtab = ioremap(addr_base, addr_size);
	return;
}

static long mm_vsmmu_strtab(unsigned int smmuid, unsigned int offset,
						unsigned long value)
{
	struct arm_vsmmu_device *vsmmu = NULL;

	vsmmu = mm_vsmmu_device_find(smmuid);
	if (!vsmmu)
		return -EINVAL;

	switch(offset) {
	case VSMMU_STRTAB_BASE:
		vsmmu->strtab_cfg.strtab_base = (unsigned long)value;
		break;
	case VSMMU_STRTAB_BASE_CFG:
		vsmmu->strtab_cfg.strtab_base_cfg = (unsigned int)value;
		vsmmu_strtab_map(vsmmu);
		break;
	default:
		pr_err("%s: reg offset is invalid\n", __func__);
		break;
	}

	return 0;
}

static unsigned long *vsmmu_get_step_by_sid(struct arm_vsmmu_device *vsmmu,
									unsigned int sid)
{
	unsigned long *step = NULL;
	unsigned int size;
	unsigned long *strtab;
	unsigned int vsmmu_strtab_cfg;

	vsmmu_strtab_cfg = vsmmu->strtab_cfg.strtab_base_cfg;
	strtab = (unsigned long *)vsmmu->strtab_cfg.strtab;
	if (!strtab) {
		pr_err("%s, vsmmu %d strtab is NULL!!!\n", __func__, vsmmu->smmuid);
		return NULL;
	}

	if (vsmmu_strtab_cfg & STRTAB_BASE_CFG_FMT_2LVL) {
		// not support, do nothing
	} else {
		/* Simple linear lookup */
		step = &strtab[sid * STRTAB_STE_DWORDS];
	}

	return step;
}

static void build_vsmmu_stab_s2(unsigned long *strsrc, unsigned long *strdest)
{
	unsigned int len;
	unsigned long vsmmu_vtcr = 0;
	typeof(&pgtbl_cfg.arm_lpae_s2_cfg.vtcr) vtcr = &pgtbl_cfg.arm_lpae_s2_cfg.vtcr;

	len = STRTAB_STE_DWORDS << DWORD_BYTES_NUM;
	memcpy_s(strdest, len, strsrc, len);

	vsmmu_vtcr   =  FIELD_PREP(STRTAB_STE_2_VTCR_S2T0SZ, vtcr->tsz) |
					FIELD_PREP(STRTAB_STE_2_VTCR_S2SL0, vtcr->sl) |
					FIELD_PREP(STRTAB_STE_2_VTCR_S2IR0, vtcr->irgn) |
					FIELD_PREP(STRTAB_STE_2_VTCR_S2OR0, vtcr->orgn) |
					FIELD_PREP(STRTAB_STE_2_VTCR_S2SH0, vtcr->sh) |
					FIELD_PREP(STRTAB_STE_2_VTCR_S2TG, vtcr->tg) |
					FIELD_PREP(STRTAB_STE_2_VTCR_S2PS, vtcr->ps);

	vsmmu_vtcr |= (1 << STRTAB_STE_2_AA64_SHIFT | 1 << STRTAB_STE_2_S2R_SHIFT);
	strdest[0] |= STRTAB_STE_0_CFG_S2_TRANS;
	strdest[2] = VSMMU_GUEST_VMID | (vsmmu_vtcr << VSMMU_STE_S2_ATTR_MASK);
	strdest[3] = pgtbl_cfg.arm_lpae_s2_cfg.vttbr & VSMMU_STE_S2TTB_MASK;

	return;
}

static void enable_smmu_stab_s2(struct arm_smmu_device *smmu,
					unsigned long *strentry, unsigned int sid)
{
	unsigned int len;
	unsigned long *step = NULL;
	unsigned long *strtab = (unsigned long *)smmu->strtab_cfg.strtab;

	step = &strtab[sid * STRTAB_STE_DWORDS];
	len = STRTAB_STE_DWORDS << DWORD_BYTES_NUM;
	memcpy_s(step, len, strentry, len);

	return;
}

static long scan_vsmmu_cmd_info(struct arm_vsmmu_device *vsmmu)
{
	long ret = 0;
	struct arm_smmu_device *smmu = NULL;
	unsigned long entry[STRTAB_STE_DWORDS];
	unsigned int sid;
	unsigned long *step = NULL;

	smmu = smmu_device[vsmmu->smmuid];
	if (!smmu) {
		pr_err("%s, smmu device %d has not probed.\n", __func__, vsmmu->smmuid);
		return -EINVAL;
	}

	for(sid = 0; sid < MM_SMMU_SID_MAX; sid++) {
		step = vsmmu_get_step_by_sid(vsmmu, sid);
		if (!step)
			return -EINVAL;

		if (!(step[0] & STRTAB_STE_0_V))
			continue;

		memset_s(entry, sizeof(entry), 0, sizeof(entry));
		build_vsmmu_stab_s2(step, entry);
		enable_smmu_stab_s2(smmu, entry, sid);
	}

	return ret;
}

static long  vsmmu_cmdq_build_ent(struct arm_vsmmu_device *vsmmu,
						struct vsmmu_queue *q, unsigned int prod)
{
	struct arm_smmu_cmdq_ent entry = {0};
	long ret = 0;
	u64 cmd[CMDQ_ENT_DWORDS] = {0};
	u8 opcode = 0;
	struct arm_smmu_device *smmu = NULL;

	memcpy_s(cmd, CMDQ_ENT_DWORDS << DWORD_BYTES_NUM, Q_ENT(q, prod), CMDQ_ENT_DWORDS << DWORD_BYTES_NUM);
	opcode = cmd[0] & VSMMU_CMDQ_OPSCODE_MASK;

	entry.opcode = opcode;
	switch (opcode) {
	case CMDQ_OP_TLBI_EL2_ALL:
	case CMDQ_OP_TLBI_NSNH_ALL:
		break;
	case CMDQ_OP_PREFETCH_CFG:
		entry.prefetch.sid = (u32)((cmd[0] >> CMDQ_PREFETCH_0_SID_SHIFT) & CMDQ_CFGI_0_SID_MASK);
		entry.prefetch.size = cmd[1] & CMDQ_PREFETCH_1_SIZE_MASK;
		entry.prefetch.addr = cmd[1] & CMDQ_PREFETCH_1_ADDR_MASK;
		break;
	case CMDQ_OP_CFGI_STE:
		entry.cfgi.sid = (u32)((cmd[0] >> CMDQ_PREFETCH_0_SID_SHIFT) & CMDQ_CFGI_0_SID_MASK);
		entry.cfgi.leaf = cmd[1] & CMDQ_CFGI_1_LEAF;
		break;
	case CMDQ_OP_CFGI_ALL:
		break;
	case CMDQ_OP_CFGI_CD:
		entry.cfgi.sid = (u32)((cmd[0] >> CMDQ_PREFETCH_0_SID_SHIFT) & CMDQ_CFGI_0_SID_MASK);
		entry.cfgi.ssid = (u32)((cmd[0] >> CMDQ_CFGI_0_CD_SHIFT) & 0xFFFFF);
		entry.cfgi.leaf = cmd[1] & CMDQ_CFGI_1_LEAF;
		break;
	case CMDQ_OP_TLBI_NH_VA:
		entry.tlbi.asid = (cmd[0] >> CMDQ_TLBI_0_ASID_SHIFT) & 0xFFFF;
		entry.tlbi.vmid = ((cmd[0] >> CMDQ_TLBI_0_VMID_SHIFT) & 0xFFFF) ? VSMMU_GUEST_VMID : 0;
		entry.tlbi.leaf = cmd[1] & CMDQ_CFGI_1_LEAF;
		entry.tlbi.addr = cmd[1] & CMDQ_TLBI_1_VA_MASK;
		break;
	case CMDQ_OP_TLBI_S2_IPA:
		entry.tlbi.vmid = VSMMU_GUEST_VMID;
		entry.tlbi.leaf = cmd[1] & CMDQ_CFGI_1_LEAF;
		entry.tlbi.addr = cmd[1] & CMDQ_TLBI_1_VA_MASK;
		break;
	case CMDQ_OP_TLBI_NH_ASID:
		entry.tlbi.asid = (cmd[0] >> CMDQ_TLBI_0_ASID_SHIFT) & 0xFFFF;
		/* Fallthrough */
	case CMDQ_OP_TLBI_S12_VMALL:
		entry.tlbi.vmid = VSMMU_GUEST_VMID;
		break;
	case CMDQ_OP_CMD_SYNC:
		break;
	default:
		pr_err("%s: opcode %u is invalid!\n", __func__, opcode);
		return -ENOENT;
	}

	smmu = smmu_device[vsmmu->smmuid];
	if (!smmu) {
		pr_err("%s, smmu device has not been probed\n", __func__);
		return NULL;
	}

	arm_smmu_cmdq_issue_cmd(smmu, &entry);
	return ret;
}

static long vsmmu_cmd_sync(struct arm_vsmmu_device *vsmmu, struct vsmmu_queue *q)
{
	long ret = 0;
	unsigned int prod_index, prod_start, prod_end, temp;

	prod_start = Q_WRP(q, q->prve_prod) | Q_IDX(q, q->prve_prod);
	prod_end = Q_WRP(q, q->prod) | Q_IDX(q, q->prod);

	while (prod_start != prod_end) {
		ret = vsmmu_cmdq_build_ent(vsmmu, q, prod_start);
		if (ret)
			return ret;

		temp = (Q_WRP(q, q->prve_prod) | Q_IDX(q, q->prve_prod)) + 1;
		q->prve_prod = Q_OVF(q, q->prve_prod) | Q_WRP(q, temp) | Q_IDX(q, temp);
		prod_start = Q_WRP(q, q->prve_prod) | Q_IDX(q, q->prve_prod);
	}

	return ret;
}

static void vsmmu_cmqbase_map(struct arm_vsmmu_device *vsmmu)
{
	unsigned long base;
	unsigned long size;

	base = vsmmu->cmdq.q.q_base;
	size = ((1 << vsmmu->cmdq.q.max_n_shift) * CMDQ_ENT_DWORDS) << DWORD_BYTES_NUM;
	vsmmu->cmdq.q.base = ioremap(base, size);

	return;
}

static long mm_vsmmu_cmdq(unsigned int smmuid, unsigned int offset,
						unsigned long value)
{
	struct arm_vsmmu_device *vsmmu = NULL;
	long ret = 0;

	vsmmu = mm_vsmmu_device_find(smmuid);
	if (!vsmmu)
		return -EINVAL;

	switch(offset) {
	case VSMMU_CMDQ_BASE:
		vsmmu->cmdq.q.q_base = value & Q_BASE_ADDR_MASK << Q_BASE_ADDR_SHIFT;
		vsmmu->cmdq.q.max_n_shift = value & Q_BASE_LOG2SIZE_MASK << Q_BASE_LOG2SIZE_SHIFT;
		vsmmu->cmdq.q.ent_dwords = CMDQ_ENT_DWORDS;
		vsmmu->cmdq.q.prve_prod = 0;
		vsmmu->cmdq.q.prve_cons = 0;
		vsmmu_cmqbase_map(vsmmu);
		/* scan vste entry for adding stage2 configuration when in tcu poweron */
		ret = scan_vsmmu_cmd_info(vsmmu);
		break;
	case VSMMU_CMDQ_PROD:
		vsmmu->cmdq.q.prod = (unsigned int)value;
		ret = vsmmu_cmd_sync(vsmmu, &vsmmu->cmdq.q);
		break;
	case VSMMU_CMDQ_CONS:
		vsmmu->cmdq.q.cons = (unsigned int)value;
		break;
	default:
		break;
	}

	return ret;
}

static long mm_vsmmu_write_cr0(unsigned int smmuid, unsigned long value)
{
	struct arm_vsmmu_device *vsmmu = NULL;

	vsmmu = mm_vsmmu_device_find(smmuid);
	if (!vsmmu)
		return -EINVAL;

	vsmmu->cr0_status = (int)value;
	return 0;
}

static long mm_vsmmu_write_irqctrl(unsigned int smmuid, unsigned long value)
{
	struct arm_vsmmu_device *vsmmu = NULL;

	vsmmu = mm_vsmmu_device_find(smmuid);
	if (!vsmmu)
		return -EINVAL;

	vsmmu->irq_ctrl = (int)value;
	return 0;
}

long mm_vsmmu_ioc_write_reg(unsigned int smmuid, unsigned int offset,
						unsigned int size, unsigned long value)
{
	long ret = 0;

	switch(offset) {
	case VSMMU_PW_REG:
		ret = mm_vsmmu_power_contrl(smmuid, value);
		break;
	case VSMMU_STRTAB_BASE:
	case VSMMU_STRTAB_BASE_CFG:
		ret = mm_vsmmu_strtab(smmuid, offset, value);
		mm_vsmmu_build_s2ttd(smmuid);
		break;
	case VSMMU_CMDQ_BASE:
	case VSMMU_CMDQ_PROD:
	case VSMMU_CMDQ_CONS:
		ret = mm_vsmmu_cmdq(smmuid, offset, value);
		break;
	case VSMMU_EVTQ_BASE:
	case VSMMU_EVTQ_PROD:
	case VSMMU_EVTQ_CONS:
		pr_info("%s: vsmmu evtq do nothing!!!\n", __func__);
		break;
	case ARM_SMMU_CR0:
		ret = mm_vsmmu_write_cr0(smmuid, value);
		break;
	case ARM_SMMU_IRQ_CTRL:
		ret = mm_vsmmu_write_irqctrl(smmuid, value);
		break;
	default:
		break;
	}

	return ret;
}
EXPORT_SYMBOL(mm_vsmmu_ioc_write_reg);

int __init early_init_rda_ttd(unsigned long node, const char *uname,
				     int depth, void *data)
{
	const __be32 *prop;
	int len = 0;
	unsigned long base;
	unsigned long size;
	int i = 0;
	const char *type = of_get_flat_dt_prop(node, "compatible", NULL);

	if (type == NULL || strcmp(type, "rda,smmu-v3-ttd") != 0)
		return 0;

	prop = of_get_flat_dt_prop(node, "reg", &len);
	if (!prop || !len) {
		pr_err("%s: get dt prop failed! prop is %p, len is %d!\n", __func__, prop, len);
		return -EINVAL;
	}

	while (len) {
		base = dt_mem_next_cell(DT_ROOT_TTD_ADDR_CELLS, &prop);
		size = dt_mem_next_cell(DT_ROOT_TTD_SIZE_CELLS, &prop);

		g_addr_map[i][0] = base;
		g_addr_map[i][1] = size;
		i++;
		len -= sizeof(int) * DT_ROOT_TTD_ADDR_CELLS * 2;

		if (i == VSMMU_TTD_NUM_MAX) {
			pr_err("%s: g_addr_map is too small!\n", __func__);
			return -EINVAL;
		}
	}

	return 0;
}

#ifdef CONFIG_VM_PRESET
static int vsmmuv3_preset_handler(void)
{
	pr_info("in %s process\n", __func__);
	return 0;
}

static int vsmmuv3_release_handler(void)
{
	pr_info("in %s process\n", __func__);
	struct arm_vsmmu_device *vsmmu = NULL;
	struct arm_vsmmu_device *tmp = NULL;
	unsigned long flags;
	long ret;

	spin_lock_irqsave(&vsmmu_list_lock, flags);
	list_for_each_entry_safe(vsmmu, tmp, &vsmmu_device_list, list) {
		if (vsmmu->cnt) {
			ret = mm_vsmmu_tcu_poweroff_finalise(vsmmu);
			if (ret)
				pr_err("%s, VSMMU %d power off failed.\n", __func__, vsmmu->smmuid);

			/* When a component of the media subsystem is powered on using the regulator_enable
			command, the regulator first invokes the tcu_poweron interface in the host domain
			and then invokes the tcu_poweron interface in the guest domain.
			Therefore, in the release function, besides reducing the smmu->cnt, the power count
			of atf sec_smmuv3 also needs to be reduced. */
			if (vsmmu->smmuid == SMMU_MEDIA1 || vsmmu->smmuid == SMMU_MEDIA2)
				sec_smmu_ops(vsmmu->smmuid, MM_TCU_CLK_OFF, SMC_DEFAULT_CMD);
		}

		list_del(&vsmmu->list);
		vfree(vsmmu);
	}
	spin_unlock_irqrestore(&vsmmu_list_lock, flags);

	return 0;
}
#endif

static int __init arm_smmu_ttd_probe(struct platform_device *pdev)
{
	of_scan_flat_dt(early_init_rda_ttd, NULL);

	return 0;
}

static const struct of_device_id rda_smmu_ttd_of_match[] = {
	{ .compatible = "rda,smmu-v3-ttd", },
	{ },
};
MODULE_DEVICE_TABLE(of, rda_smmu_ttd_of_match);

static struct platform_driver rda_smmu_ttd_driver = {
	.driver	= {
		.name		= "smmu-v3-ttd",
		.of_match_table	= of_match_ptr(rda_smmu_ttd_of_match),
	},
	.probe	= arm_smmu_ttd_probe,
	.remove	= NULL,
};

static int __init mm_smmuv3_ttd_init(void)
{
	int ret = 0;

	ret = platform_driver_register(&rda_smmu_ttd_driver);
	if (ret) {
		pr_err("%s failed, ret:%d\n", __func__, ret);
		return -EINVAL;
	}

	return 0;
}
module_init(mm_smmuv3_ttd_init);

#ifdef CONFIG_VM_PRESET
static int __init mm_smmuv3_vm_reset_init(void)
{
	int ret = 0;
	pr_info("%s start!\n", __func__);

	ret = module_register_vm_preset_handler("vsmmuv3", vsmmuv3_preset_handler,
			vsmmuv3_release_handler);
	if (ret) {
		pr_err("%s vm_preset register failed, ret:%d\n", __func__, ret);
		return -EINVAL;
	}

	return 0;
}

late_initcall_sync(mm_smmuv3_vm_reset_init);
#endif
