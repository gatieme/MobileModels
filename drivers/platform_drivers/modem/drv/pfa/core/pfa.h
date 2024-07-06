/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may
 * *    be used to endorse or promote products derived from this software
 * *    without specific prior written permission.
 *
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */
#ifndef __PFA_H__
#define __PFA_H__

#include <osl_types.h>
#include <linux/spinlock.h>
#include <linux/skbuff.h>
#include <linux/list.h>
#include <linux/smp.h>
#include <linux/dmapool.h>
#include <linux/etherdevice.h>
#include <linux/workqueue.h>
#include <linux/version.h>

#include <product_config.h>
#include <bsp_nvim.h>
#include <securec.h>
#ifdef FEATURE_NVA_ON
#include <nva_stru.h>
#include <nva_id.h>
#endif
#include <bsp_nva.h>

#include <bsp_dra.h>
#include <bsp_pfa.h>
#include "pfa_hal_reg.h"
#include "pfa_hal_desc.h"
#include "pfa_modem_reset.h"
#include <bsp_net_om.h>
#ifdef CONFIG_PFA_FW
#include <linux/pfa/pfa_interface.h>
#endif
#include "bsp_dt.h"

#define PFA_PORT_MAX (32)
#define PFA_PORT_MASK (0x1f)

#define PFA_NORM_PORT(x) (((x)&PFA_PORT_MASK) < PFA_PORT_NUM)
#define PFA_BR_PORT(x) (((x)&PFA_PORT_MASK) >= PFA_PORT_NUM)

#define PFA_MAX_TD 2048
#define PFA_PORT_MAGIC 0x53504500

#define PFA_DFS_T(x) (jiffies + msecs_to_jiffies(x))

/* for ipsec */
#define PFA_DFS_INTERVAL_DEFAULT (50)
#define PFA_DFS_PKT_PER_MS (5)  // when above 80mbit/s pfa ipsec pkt, set ddr freq to max
#define PFA_DFS_IPSEC_THRESHOLE (PFA_DFS_INTERVAL_DEFAULT * PFA_DFS_PKT_PER_MS)
#define PFA_DEFAULT_START_LIMIT (2048)

#define PFA_FLAG_ENABLE BIT(0)
#define PFA_FLAG_SUSPEND BIT(1)

#define PFA_US_TO_32KHZ_CNT(us) ((us)*10 / 305)     /* us -> 32KHz */
#define PFA_S_TO_TIMER_CNT(s) ((s)*1000 * 10 / 312) /* 1 cnt = 31.2 ms */

#define PFA_IP_FW_TIMEOUT (PFA_S_TO_TIMER_CNT(5))       /* 5s, unit:32.768kHz时钟周期的2^10倍（31.2ms） */
#define PFA_MAC_FW_TIMEOUT (PFA_S_TO_TIMER_CNT(100))    /* 100s, unit:32.768kHz时钟周期的2^10倍（31.2ms） */
#define PFA_NCM_WRAP_TIMEOUT (PFA_US_TO_32KHZ_CNT(256)) /* 256us, unit:32khz 时钟周期（30.5us） */
#define PFA_QOS_MAC_LMTTIME (PFA_US_TO_32KHZ_CNT(8 * 1000 * 1000)) /* 8s, unit:32khz 时钟周期（30.5us） */

#define PFA_DUMP_SIZE (1024 * 3) /* pfa Application 3k sieze */
#define PFA_ADQ_INTERVAL_DEFAULT (10)

#ifdef FEATURE_NVA_ON
typedef drv_pfa_feature_s pfa_feature_t;
#else
typedef DRV_PFA_FEATURE pfa_feature_t;
#endif

#define PFA_RD_MAX_GET_TIMES 1
#define PFA_CLKS_MAX_NUM 4

struct desc_result_s {
    unsigned int td_result[TD_RESULT_BOTTOM];          // td result bit 0-1
    unsigned int td_ptk_drop_rsn[TD_DROP_RSN_BOTTOM];  // td result bit 2-5
    unsigned int td_pkt_fw_path[TD_FW_BOTTOM];         // rd desc bit6-16
    unsigned int td_pkt_type[TD_PKT_TYPE_BOTTOM];      // td result bit 17-19
    unsigned int td_warp[TD_WARP_BOTTOM];              // td result bit 20-21
    unsigned int td_unwrap[TD_NCM_UNWRAP_BOTTOM];      // td result bit 22-25

    unsigned int rd_result[RD_RESULT_BOTTOM];          // rd desc bit0-1
    unsigned int rd_pkt_drop_rsn[RD_DROP_RSN_BOTTOM];  // rd desc bit2-5
    unsigned int rd_pkt_fw_path[RD_INDICATE_BOTTOM];   // rd desc bit6-16
    unsigned int rd_pkt_type[RD_PKT_TYPE_BOTTOM];      // rd desc bit17-19
    unsigned int rd_finsh_wrap_rsn[RD_WRAP_BOTTOM];    // rd desc bit20-22
    unsigned int rd_send_cpu_rsn[RD_CPU_BOTTOM];       // rd desc bit23-26
    unsigned int rd_sport_cnt[PFA_PORT_NUM];           // rd desc bit0-1
};

#define DIRECT_FW_HP_PORT_WEIGHT 40000000
#define DIRECT_FW_MP_PORT_WEIGHT 20000000
#define DIRECT_FW_PE_PORT_WEIGHT 10000000

struct pfa_direct_fw_ctx {
    unsigned int enable : 1;
    unsigned int alloced : 1;
    unsigned int reserve : 30;
    unsigned int port_no;
    unsigned int port_weight;
    unsigned int stream_cnt;
    struct list_head stream_list;
};

struct pfa_port_ctrl_flags {
    unsigned int enable : 1;
    unsigned int enable_after_modem_reset : 1;
    unsigned int alloced : 1;
    unsigned int rd_not_empty : 1;
    unsigned int hids_upload : 1;
    unsigned int copy_port : 1;
    unsigned int mac_to_ip_enable : 1;
    unsigned int reserve : 25;
};

struct pfa_port_smp_ctx {
    unsigned long status;
    unsigned int def_cpu;
    call_single_data_t csd ____cacheline_aligned_in_smp;
    struct tasklet_struct ini_bh_tasklet;
};

struct net_device_to_vir_port {
    struct net_device *net;
    unsigned int portno;
    struct pfa_ops ops;
    unsigned int pkt_cnt;
};

struct pfa_port_ctrl {
    unsigned int portno;
    pfa_port_prop_t property;
    struct pfa_port_ctrl_flags port_flags;
    struct net_device_to_vir_port net_map[PFA_PORT_NUM];
    struct net_device *net;
    struct pfa_ops ops;
    struct pfa_direct_fw_ctx direct_fw_ctx;
    struct pfa_port_smp_ctx smp;

    void *port_priv;
    spinlock_t lock;
    unsigned int ext_desc;

    /* td */
    struct sk_buff **td_param;
    void *td_addr;
    unsigned int td_depth;
    unsigned int td_evt_gap;
    dma_addr_t td_dma;
    unsigned int td_free; /* to be fill by software next time */
    unsigned int td_busy; /* filled by software last time */
    spinlock_t td_lock;
    struct pfa_td_desc *axi_td;
    dma_addr_t td_axi_buf_dma;
    /* rd */
    void *rd_addr;
    unsigned int rd_depth;
    unsigned int rd_evt_gap;
    dma_addr_t rd_dma;
    unsigned int rd_busy; /* filled by software last time */
    unsigned int rd_free; /* to be fill by software next time */
    spinlock_t rd_lock;
    void *rd_long_buf;
    struct pfa_rd_desc *axi_rd;
    dma_addr_t rd_axi_buf_dma;

    /* rate limit */
    unsigned int udp_limit_time;
    unsigned int udp_limit_cnt;
    unsigned int rate_limit_time;
    unsigned int rate_limit_byte;

    unsigned int bypassport;
    unsigned int bypassport_en;
    unsigned int priority;

    unsigned int td_copy_en;
    unsigned int stick_en;
    unsigned int with_mac_pdu;

    unsigned int dfs_speed_multiple_en;
    unsigned int dfs_speed_multiple;

    unsigned int port_multiple_en;
    unsigned int port_net_br_map;
};

struct pfa_port_stat {
    struct desc_result_s result;
    unsigned int rd_config;
    unsigned int rd_finished;
    unsigned int rd_finished_bytes;
    unsigned int rd_finsh_intr_complete;
    unsigned int rd_finsh_intr_complete_called;
    unsigned int rd_finsh_pkt_num;
    unsigned int rd_droped;
    unsigned int rd_sended;
    unsigned int rd_dra_zero;
    unsigned int rewind_th_cpy_fail;

    unsigned int td_config;
    unsigned int td_kick;
    unsigned int td_config_bytes;
    unsigned int td_port_disabled;
    unsigned int td_full;
    unsigned int td_dma_null;
    unsigned int td_finsh_intr_complete;
    unsigned int td_desc_complete;
    unsigned int td_desc_fail_drop;
    unsigned int td_pkt_complete;

    unsigned int free_disable_fail;
    unsigned int free_busy;
    unsigned int disable_timeout;
    unsigned int free_td_idle;
    unsigned int free_tdq;
    unsigned int free_rd_idle;
    unsigned int free_rdq;
    unsigned int recycle_port_idle;
    unsigned int recycle_port_emtpy;
    unsigned int dra_to_skb_fail;
    unsigned int skb_err;
};

struct pfa_port_ctx {
    struct pfa_port_ctrl ctrl;
    struct pfa_port_stat stat;
};

struct pfa_mac_fw_ctx {
    struct list_head pending;
    struct list_head backups;
    struct kmem_cache *slab;
    spinlock_t lock;
    unsigned short macfw_timeout;
    unsigned int macfw_add_fail;
    unsigned int macfw_del_fail;
    unsigned int macfw_dev_add;
    unsigned int macfw_br_add;
    unsigned int macfw_br_del;
    unsigned int macfw_fdb_dev_add;
    unsigned int macfw_fdb_dev_del;
};

struct pfa_ip_fw_ctx {
    void *hbucket;
    void *hbucket_empty;
    dma_addr_t hbucket_dma;
    dma_addr_t hbucket_dma_empty;
    struct dma_pool *hslab;
    struct list_head free_list;
    struct list_head wan_entry_list;
    spinlock_t free_lock;
    unsigned int free_cnt;
    unsigned int free_threhold;
    unsigned int deadtime;
    unsigned int hlist_size;
    unsigned int hitem_width;
    unsigned int hzone;
    unsigned int hrand;
    spinlock_t lock;
    unsigned short ipfw_timeout;
    unsigned int ip_fw_not_add;
};

struct pfa_cpuport_ctx {
    unsigned int portno;
    unsigned int alloced;
    unsigned int cpu_pktnum_per_interval;
    unsigned int cpu_pkt_max_rate;

    unsigned int cpu_wan_drop_stub;
    unsigned int cpu_wan_drop_cnt;
    unsigned int cpu_updonly;
    unsigned int cpu_updonly_comp;
    unsigned int cpu_rd_num;
    unsigned int cpu_rd_udp_drop;
    unsigned int cpu_rd_dfw_updonly_drop;
    unsigned int cpu_rd_to_wan;
    unsigned int cpu_rd_to_wan_fail;
    unsigned int cpu_rd_to_nic;
    unsigned int cpu_rd_to_nic_fail;
    unsigned int cpu_rd_to_netif_rx;
    unsigned int cpu_rd_to_netif_rx_succ;
    unsigned int cpu_rd_to_netif_rx_fail;
};

struct pfa_pfa_tftport_ctx {
    unsigned int portno;
    unsigned int alloced;
    unsigned int porten;
    unsigned int extend_desc;
    void *pfa_push_addr;
    dma_addr_t pfa_push_dma;
    void *pfa_tft_rd_rptr_addr;
    struct ethhdr pfa_tft_eth_head;
    struct pfa_tft_port_attr attr;
    void (*check_pfa_tft_bd)(void);
    unsigned int td_fail;
};

struct pfa_usbport_ctx {
    unsigned int portno;
    unsigned int alloced;
    unsigned int bypass_mode;
    struct pfa_usbport_attr attr;
};

struct pfa_wanport_ctx {
    unsigned int portno;
    struct list_head wan_dev_list;  // direct_fw use
    struct wan_dev_info_s *(*get_wan_info)(struct net_device *dev);
};

struct pfa_adq_ctrl {
    /* ad */
    void *ad_base_addr;
    dma_addr_t ad_dma_addr;
    unsigned int adq_size;
    unsigned int adq_size_sel;
    unsigned int adbuf_len;
    unsigned int dra_ipip_type;

    void *dra_wptr_stub_addr;
    dma_addr_t dra_wptr_stub_dma_addr;

    spinlock_t ad_lock;
};

struct pfa_adq_ctx {
    struct pfa_adq_ctrl ctrl;
};

enum pfa_adq_num {
    PFA_ADQ0,
    PFA_ADQ_BOTTOM
};

struct pfa_dev_stat {
    unsigned int evt_td;
    unsigned int evt_td_complt[PFA_PORT_NUM];
    unsigned int evt_td_full[PFA_PORT_NUM];
    unsigned int evt_ad_empty[PFA_ADQ_BOTTOM];
    unsigned int evt_td_errport;
    unsigned int evt_rd;
    unsigned int evt_rd_complt[PFA_PORT_NUM];
    unsigned int evt_rd_full[PFA_PORT_NUM];
    unsigned int evt_rd_empty[PFA_PORT_NUM];
    // unsigned int wait_ready;
    unsigned int wait_idle;
    unsigned int ipfw_del;
    unsigned int ipfw_del_enter;
    unsigned int ipfw_del_leave;
    unsigned int ipfw_del_nothing_leave;
    unsigned int ipfw_add;
    unsigned int ipfw_add_enter;
    unsigned int ipfw_add_leave;
    unsigned int disable_timeout;
    unsigned int int_time;
    unsigned int rd_int_time;
    unsigned int task_delay_max;
    unsigned int wq_task_begin_time;
    unsigned int wq_task_end_time;
};

struct pfa_om_info {
    struct pfa_cpu_port_om_info cpu;
    struct pfa_port_om_info port[PFA_PORT_NUM];
    struct pfa_rd_to_cpu_rsn to_cpu_rsn;
    struct pfa_task_time task_time;
};

struct pfa_direct_fw_flags {
    unsigned int enable : 1;
    unsigned int reserve : 31;
};

struct pfa_direct_fw_ctrl {
    struct pfa_direct_fw_flags dfw_flags;
    struct timer_list direct_fw_timer;
    struct list_head wan_dev_list;
    int entry_cnt;
    unsigned int port_cnt;
    unsigned int port_nums[PFA_PORT_NUM];
    unsigned char fw_port_mac[ETH_ALEN];
    unsigned int direct_fw_time_interval;  // by ms
    unsigned int direct_fw_timer_add;

    unsigned int entry_add;
    unsigned int entry_add_max;
    unsigned int entry_add_skb_null;
    unsigned int entry_add_l3dra_null;
    unsigned int not_tcp_udp;
    unsigned int entry_add_pkt_err_total;
    unsigned int entry_add_dfw_disabled;

    unsigned int entry_add_success;
    unsigned int ipfw_node_get_fail;
    unsigned int ip_fw_node_get_fail;
    unsigned int iph_len_err;
    unsigned int iph_frag;
    unsigned int ipproto_err;
    unsigned int add_tuple_fail;
    unsigned int no_wan_info;
    unsigned int no_packet_info;
    unsigned int entry_exist;
};

struct pfa_dfs_freq {
    unsigned int freq;
    unsigned int freq_min;
    unsigned int freq_max;
};

enum pfa_ports_type {
    PFA_PORTS_NOMARL,
    PFA_PORTS_BR,
    PFA_PORTS_BOTTOM
};

struct pfa_enc_type_property_table {
    enum pfa_enc_type enc_type;
    unsigned int port_weight;
};

struct pfa_pericrg {
    void __iomem *crg_addr;
    unsigned int complete_flag;
    unsigned int crg_phy_addr;
    unsigned int crg_len;
    unsigned int crg_rst_en;
    unsigned int crg_rst_dis;
    unsigned int crg_rst_stat;
    unsigned int crg_rst_mask;
};

struct pfa_smp_ctx {
    void (*process_desc)(void *pfa, unsigned int evt_rd_done, unsigned int evt_td_done);
    unsigned int sch_fail;
    unsigned int intr_core;
    unsigned int cpuport_core;
    unsigned int def_cpuport_core;
    unsigned int hp_cpuport_core;
    unsigned int use_hp_cpu_thr;
    struct workqueue_struct *workqueue;
    struct work_struct work;
};

struct pfa;
struct pfa_hal {
    void (*transfer_ctx_init)(struct pfa *pfa);
    void (*config_tft_bd_rd_ip_head)(struct pfa *pfa);
    void (*tft_config_rd_ip_head)(unsigned int ext_desc_en);
    void (*config_tft_bd_rd_ptr_update)(struct pfa *pfa, struct iport_pfa_tft_addr *pfa_tft_reg);
    unsigned int (*get_tdq_rptr)(struct pfa *pfa, unsigned int portno);
    unsigned int (*get_tdq_wptr)(struct pfa *pfa, unsigned int portno);
    unsigned int (*get_rdq_rptr)(struct pfa *pfa, unsigned int portno);
    unsigned int (*get_rdq_wptr)(struct pfa *pfa, unsigned int portno);
    void (*set_tdq_wptr)(struct pfa *pfa, unsigned int ptr, unsigned int portno);
    void (*set_rdq_rptr)(struct pfa *pfa, unsigned int ptr, unsigned int portno);
    void (*set_rdq_wptr)(struct pfa *pfa, unsigned int ptr, unsigned int portno);
    void (*queue_portx_save)(struct pfa *pfa_ctx, unsigned int portno, struct pfa_queue_stash *queue_regs);
    void (*queue_portx_restore)(struct pfa *pfa_ctx, unsigned int portno, struct pfa_queue_stash *queue_regs);
    void (*config_hash_cache_en)(struct pfa *pfa, unsigned int enable);
    void (*config_hash_value)(struct pfa *pfa, unsigned int hash);
    void (*config_adq_threshold_and_len)(struct pfa *pfa, unsigned int size);
    void (*config_qos_lmttime)(struct pfa *pfa, unsigned int value);
    void (*config_eth_vlan_tag_sel)(struct pfa *pfa, unsigned int flag);
    void (*config_dport_adq_core_type)(struct pfa *pfa, unsigned int port_num, unsigned int type);
    void (*set_update_only_produce_mod)(struct pfa *pfa);
    void (*enable_macfw_to_ip)(struct pfa *pfa, unsigned int portno, unsigned int enable);
};
extern struct pfa_hal g_pfa_hal;

struct enc_type_to_port_map {
    enum pfa_enc_type type;
    unsigned int vir_portno;
    unsigned int port_multiple_en;
    unsigned int alloced;
};
struct pfa {
    unsigned int pfa_version;
    unsigned int flags;
    unsigned int print_once_flags;
    unsigned int mask_flags;  // 0: not mask,can add entry; 1: mask add entry will succ without add one to pfa hardware.
    unsigned int bugon_flag;
    unsigned int pfa_mode;
    unsigned int soft_push;
    struct pfa_hal *hal;
    struct device *dev;
    device_node_s *np;
    struct clk **clks;
    unsigned int clks_num;
    unsigned int clk_div;
    unsigned int irq;
    unsigned int irq_interval;
    unsigned int wake_irq;
    dma_addr_t res;
    void __iomem *regs;
    unsigned int rsv_port_map[PFA_RSV_PORT_VIR_ID_MAX];
    unsigned long portmap[PFA_PORTS_BOTTOM];
    struct pfa_enc_type_property_table type_property_table[PFA_ENC_BOTTOM];

    struct pfa_pericrg peri;
    unsigned int td_fail_generate_rd;
    struct pfa_port_ctx ports[PFA_PORT_NUM];
    struct pfa_adq_ctx adqs_ctx;

    struct pfa_cpuport_ctx cpuport;
    struct pfa_pfa_tftport_ctx pfa_tftport;
    struct pfa_wanport_ctx wanport;
    struct pfa_usbport_ctx usbport;
    struct pfa_smp_ctx smp;

    struct pfa_ip_fw_ctx ipfw;
    struct pfa_mac_fw_ctx macfw;
    struct pfa_direct_fw_ctrl direct_fw;
    spinlock_t port_alloc_lock;

#define DFS_MAX_LEVEL 10
    struct pfa_dfs_freq freq_grade_array[DFS_MAX_LEVEL];
    struct timer_list pfa_dfs_timer;
    unsigned int pfa_dfs_enable;
    unsigned int pfa_dfs_div_enable;
    int cur_dfs_grade;
    int last_dfs_grade;
    unsigned int pfa_fre_grade_max;
    unsigned int dfs_timer_cnt;
    unsigned int dfs_cnt;
    unsigned int dfs_div_cnt;
    unsigned int dfs_div_fail_cnt;
    unsigned int dfs_div_threshold_pktnum;
    unsigned int byte;
    unsigned int last_byte;
    unsigned int start_byte_limit;
    unsigned int total_byte;
    unsigned int dfs_td_count;
    unsigned int dfs_td_count_last;
    unsigned int dfs_rd_count;
    unsigned int dfs_rd_count_last;
    int pfa_dfs_time_interval;
    int dfs_reg_acore_id;
    int dfs_reg_ddr_id;
    int ddr_freq_requested;
    unsigned int cpu_profile[DFS_MAX_LEVEL];
    unsigned int ddr_profile[DFS_MAX_LEVEL];
    unsigned int div_profile[DFS_MAX_LEVEL];
    unsigned int xfrm_dfs_cnt;
    unsigned int div_pmctrl;
    unsigned int clk_div_default;

    struct pfa_dev_stat stat;
    struct net_om_info report_info;
    struct pfa_om_info hds_info;

    unsigned int min_pkt_len;
    unsigned int msg_level;
    unsigned int dbg_level;
    unsigned int *entry_bak;
    unsigned int porten_bak;
    unsigned int not_idle;
    unsigned int suspend_count;
    unsigned int resume_count;
    unsigned int modem_reset_count;
    unsigned int modem_unreset_count;
    unsigned int modem_noreset_count;
    unsigned int halt;
    pfa_feature_t pfa_feature;
    spinlock_t pm_lock;
    unsigned int pfa_rd_pkt_cnt;
    bool wakeup_flag;
    unsigned int *dump_base;
    struct timer_list pfa_adq_timer;
    int pfa_adq_time_interval;
    spinlock_t pfa_ad_lock;
    wait_queue_head_t wqueue;
    unsigned int event;
    unsigned int modem_resetting;
    spinlock_t reset_lock;
    unsigned int drop_stub;
    unsigned int clock_gate_en;
    unsigned int rd_loop_cnt;
    unsigned int rd_done_mask;

    struct enc_type_to_port_map enc_type_map[PFA_ENC_BOTTOM];
};

extern struct pfa g_pfa;

#define PFA_EVENT_RESETTING_BIT 0
#define PFA_EVENT_THREAD_STOPING_BIT 1
#define PFA_EVENT_THREAD_STOPED_BIT 2
#define PFA_EVENT_FW_TIMER_STOPING_BIT 3
#define PFA_EVENT_FW_TIMER_STOPED_BIT 4

#define PFA_EVENT_RESETTING BIT(PFA_EVENT_RESETTING_BIT)
#define PFA_EVENT_THREAD_STOPING BIT(PFA_EVENT_THREAD_STOPING_BIT)
#define PFA_EVENT_THREAD_STOPED BIT(PFA_EVENT_THREAD_STOPED_BIT)
#define PFA_EVENT_FW_TIMER_STOPING BIT(PFA_EVENT_FW_TIMER_STOPING_BIT)
#define PFA_EVENT_FW_TIMER_STOPED BIT(PFA_EVENT_FW_TIMER_STOPED_BIT)

#define PFA_EVENT_VALUE_DEFAULT (PFA_EVENT_THREAD_STOPED | PFA_EVENT_FW_TIMER_STOPED)

#endif /* __PFA_H__ */
