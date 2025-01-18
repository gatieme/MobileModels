#ifndef __SOC_TCP_INTERFACE_H__
#define __SOC_TCP_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_TCP_TCPC_CTRL_ADDR(base) ((base) + (0x0UL))
#define SOC_TCP_TCP_FLUSH_ADDR(base) ((base) + (0x4UL))
#define SOC_TCP_TCPC_STAT_ADDR(base) ((base) + (0x8UL))
#define SOC_TCP_PC_STAT_ADDR(base) ((base) + (0xCUL))
#define SOC_TCP_PAUSE_REQ_ADDR(base) ((base) + (0x2cUL))
#define SOC_TCP_CLK_CTRL_ADDR(base) ((base) + (0x30UL))
#define SOC_TCP_AHB_CTRL_ADDR(base) ((base) + (0x34UL))
#define SOC_TCP_ERR_TCPC_STAT_ADDR(base) ((base) + (0x40UL))
#define SOC_TCP_ERR_PC_STAT_ADDR(base) ((base) + (0x44UL))
#define SOC_TCP_ERR_AHB_ADDR_STAT_ADDR(base) ((base) + (0x48UL))
#define SOC_TCP_ERR_AHB_CTRL_STAT_ADDR(base) ((base) + (0x4CUL))
#define SOC_TCP_MEM_CTRL0_ADDR(base) ((base) + (0x60UL))
#define SOC_TCP_MEM_CTRL1_ADDR(base) ((base) + (0x64UL))
#define SOC_TCP_IRAM_LOCK_ADDR(base) ((base) + (0x70UL))
#define SOC_TCP_MOVE_MUTEX_CFG_ADDR(base) ((base) + (0x80UL))
#define SOC_TCP_BASEADDR_ADDR(base) ((base) + (0x84UL))
#define SOC_TCP_INSTR_SIZE_CFG_ADDR(base) ((base) + (0x8CUL))
#define SOC_TCP_IRQ_STAT_ADDR(base) ((base) + (0xA0UL))
#define SOC_TCP_IRQ_MASK_ADDR(base) ((base) + (0xA4UL))
#define SOC_TCP_IRQ_CLR_ADDR(base) ((base) + (0xA8UL))
#define SOC_TCP_TASK_DONE_IRQ_STAT_ADDR(base) ((base) + (0xACUL))
#define SOC_TCP_TASK_DONE_IRQ_MASK_ADDR(base) ((base) + (0xB4UL))
#define SOC_TCP_TASK_DONE_IRQ_CLR_ADDR(base) ((base) + (0xBCUL))
#define SOC_TCP_DBG_CTRL_ADDR(base) ((base) + (0xD0UL))
#define SOC_TCP_DBG_BKP_ADDR(base) ((base) + (0xD4UL))
#define SOC_TCP_DBG_STEP_ADDR(base) ((base) + (0xD8UL))
#define SOC_TCP_DBG_CONTINUE_ADDR(base) ((base) + (0xDCUL))
#define SOC_TCP_WDT_CFG_ADDR(base) ((base) + (0xF0UL))
#define SOC_TCP_WDT_STAT_ADDR(base) ((base) + (0xF4UL))
#define SOC_TCP_TASK_START_ADDR_ADDR(base,TN) ((base) + (0x100+(TN)*4UL))
#define SOC_TCP_EXT_IRQ_TASK_SEL_ADDR(base,EIN) ((base) + (0x200+(EIN)*4UL))
#define SOC_TCP_EXT_IRQ_EN_ADDR(base) ((base) + (0x300UL))
#define SOC_TCP_SOFT_REQ_SET_ADDR(base) ((base) + (0x310UL))
#define SOC_TCP_SOFT_REQ_CLR_ADDR(base) ((base) + (0x314UL))
#define SOC_TCP_ERR_TASK_REQ_CFG_ADDR(base) ((base) + (0x320UL))
#define SOC_TCP_TIM_TASK_REQ_CFG_ADDR(base,TMN) ((base) + (0x400+4*(TMN)))
#define SOC_TCP_GLB_TASK_REQ_STAT_ADDR(base) ((base) + (0x500UL))
#define SOC_TCP_TASK_STAT_ADDR(base) ((base) + (0x510UL))
#define SOC_TCP_TASK_REQ_CLR_ADDR(base) ((base) + (0x514UL))
#define SOC_TCP_TASK_REQ_LOCK_ADDR(base) ((base) + (0x518UL))
#define SOC_TCP_TASK_REQ_UNLOCK_ADDR(base) ((base) + (0x51CUL))
#define SOC_TCP_TASK_REQ_LOCK_STAT_ADDR(base) ((base) + (0x520UL))
#define SOC_TCP_SOFT_IRQ_SET_ADDR(base,SIN) ((base) + (0x600+(SIN)*4UL))
#define SOC_TCP_SOFT_IRQ_CLR_ADDR(base,SIN) ((base) + (0x640+(SIN)*4UL))
#define SOC_TCP_SOFT_IRQ_MASK_ADDR(base,SIN) ((base) + (0x680+(SIN)*4UL))
#define SOC_TCP_SOFT_IRQ_STAT_ADDR(base,SIN) ((base) + (0x6C0+(SIN)*4UL))
#define SOC_TCP_TCPC_AHB_ADDR_CHN_ADDR(base,CHN) ((base) + (0x700+(CHN)*4UL))
#define SOC_TCP_TIM_CFG_ADDR(base,TMN) ((base) + (0x800+4*(TMN)))
#define SOC_TCP_TIM_STAT_ADDR(base,TMN) ((base) + (0x880+4*(TMN)))
#define SOC_TCP_GENERAL_REG_ADDR(base,GRN) ((base) + (0x900+4*(GRN)))
#define SOC_TCP_COMMON_REG_ADDR(base,CRN) ((base) + (0x980+4*(CRN)))
#define SOC_TCP_STACKS_BASELINE_ADDR(base,TN) ((base) + (0xA00+(TN)*4UL))
#define SOC_TCP_STACK_STAT_ADDR(base,TN) ((base) + (0xA80+(TN)*4UL))
#define SOC_TCP_TASK_REQ_STAT_ADDR(base,TN) ((base) + (0xB00+(TN)*4UL))
#else
#define SOC_TCP_TCPC_CTRL_ADDR(base) ((base) + (0x0))
#define SOC_TCP_TCP_FLUSH_ADDR(base) ((base) + (0x4))
#define SOC_TCP_TCPC_STAT_ADDR(base) ((base) + (0x8))
#define SOC_TCP_PC_STAT_ADDR(base) ((base) + (0xC))
#define SOC_TCP_PAUSE_REQ_ADDR(base) ((base) + (0x2c))
#define SOC_TCP_CLK_CTRL_ADDR(base) ((base) + (0x30))
#define SOC_TCP_AHB_CTRL_ADDR(base) ((base) + (0x34))
#define SOC_TCP_ERR_TCPC_STAT_ADDR(base) ((base) + (0x40))
#define SOC_TCP_ERR_PC_STAT_ADDR(base) ((base) + (0x44))
#define SOC_TCP_ERR_AHB_ADDR_STAT_ADDR(base) ((base) + (0x48))
#define SOC_TCP_ERR_AHB_CTRL_STAT_ADDR(base) ((base) + (0x4C))
#define SOC_TCP_MEM_CTRL0_ADDR(base) ((base) + (0x60))
#define SOC_TCP_MEM_CTRL1_ADDR(base) ((base) + (0x64))
#define SOC_TCP_IRAM_LOCK_ADDR(base) ((base) + (0x70))
#define SOC_TCP_MOVE_MUTEX_CFG_ADDR(base) ((base) + (0x80))
#define SOC_TCP_BASEADDR_ADDR(base) ((base) + (0x84))
#define SOC_TCP_INSTR_SIZE_CFG_ADDR(base) ((base) + (0x8C))
#define SOC_TCP_IRQ_STAT_ADDR(base) ((base) + (0xA0))
#define SOC_TCP_IRQ_MASK_ADDR(base) ((base) + (0xA4))
#define SOC_TCP_IRQ_CLR_ADDR(base) ((base) + (0xA8))
#define SOC_TCP_TASK_DONE_IRQ_STAT_ADDR(base) ((base) + (0xAC))
#define SOC_TCP_TASK_DONE_IRQ_MASK_ADDR(base) ((base) + (0xB4))
#define SOC_TCP_TASK_DONE_IRQ_CLR_ADDR(base) ((base) + (0xBC))
#define SOC_TCP_DBG_CTRL_ADDR(base) ((base) + (0xD0))
#define SOC_TCP_DBG_BKP_ADDR(base) ((base) + (0xD4))
#define SOC_TCP_DBG_STEP_ADDR(base) ((base) + (0xD8))
#define SOC_TCP_DBG_CONTINUE_ADDR(base) ((base) + (0xDC))
#define SOC_TCP_WDT_CFG_ADDR(base) ((base) + (0xF0))
#define SOC_TCP_WDT_STAT_ADDR(base) ((base) + (0xF4))
#define SOC_TCP_TASK_START_ADDR_ADDR(base,TN) ((base) + (0x100+(TN)*4))
#define SOC_TCP_EXT_IRQ_TASK_SEL_ADDR(base,EIN) ((base) + (0x200+(EIN)*4))
#define SOC_TCP_EXT_IRQ_EN_ADDR(base) ((base) + (0x300))
#define SOC_TCP_SOFT_REQ_SET_ADDR(base) ((base) + (0x310))
#define SOC_TCP_SOFT_REQ_CLR_ADDR(base) ((base) + (0x314))
#define SOC_TCP_ERR_TASK_REQ_CFG_ADDR(base) ((base) + (0x320))
#define SOC_TCP_TIM_TASK_REQ_CFG_ADDR(base,TMN) ((base) + (0x400+4*(TMN)))
#define SOC_TCP_GLB_TASK_REQ_STAT_ADDR(base) ((base) + (0x500))
#define SOC_TCP_TASK_STAT_ADDR(base) ((base) + (0x510))
#define SOC_TCP_TASK_REQ_CLR_ADDR(base) ((base) + (0x514))
#define SOC_TCP_TASK_REQ_LOCK_ADDR(base) ((base) + (0x518))
#define SOC_TCP_TASK_REQ_UNLOCK_ADDR(base) ((base) + (0x51C))
#define SOC_TCP_TASK_REQ_LOCK_STAT_ADDR(base) ((base) + (0x520))
#define SOC_TCP_SOFT_IRQ_SET_ADDR(base,SIN) ((base) + (0x600+(SIN)*4))
#define SOC_TCP_SOFT_IRQ_CLR_ADDR(base,SIN) ((base) + (0x640+(SIN)*4))
#define SOC_TCP_SOFT_IRQ_MASK_ADDR(base,SIN) ((base) + (0x680+(SIN)*4))
#define SOC_TCP_SOFT_IRQ_STAT_ADDR(base,SIN) ((base) + (0x6C0+(SIN)*4))
#define SOC_TCP_TCPC_AHB_ADDR_CHN_ADDR(base,CHN) ((base) + (0x700+(CHN)*4))
#define SOC_TCP_TIM_CFG_ADDR(base,TMN) ((base) + (0x800+4*(TMN)))
#define SOC_TCP_TIM_STAT_ADDR(base,TMN) ((base) + (0x880+4*(TMN)))
#define SOC_TCP_GENERAL_REG_ADDR(base,GRN) ((base) + (0x900+4*(GRN)))
#define SOC_TCP_COMMON_REG_ADDR(base,CRN) ((base) + (0x980+4*(CRN)))
#define SOC_TCP_STACKS_BASELINE_ADDR(base,TN) ((base) + (0xA00+(TN)*4))
#define SOC_TCP_STACK_STAT_ADDR(base,TN) ((base) + (0xA80+(TN)*4))
#define SOC_TCP_TASK_REQ_STAT_ADDR(base,TN) ((base) + (0xB00+(TN)*4))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp_flush_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_TCP_TCPC_CTRL_UNION;
#endif
#define SOC_TCP_TCPC_CTRL_tcp_flush_en_START (0)
#define SOC_TCP_TCPC_CTRL_tcp_flush_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcpc_flush : 1;
        unsigned int task_req_flush : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_TCP_TCP_FLUSH_UNION;
#endif
#define SOC_TCP_TCP_FLUSH_tcpc_flush_START (0)
#define SOC_TCP_TCP_FLUSH_tcpc_flush_END (0)
#define SOC_TCP_TCP_FLUSH_task_req_flush_START (1)
#define SOC_TCP_TCP_FLUSH_task_req_flush_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcpc_busy : 1;
        unsigned int curr_st : 4;
        unsigned int pc_stack_sel_pointer : 3;
        unsigned int step_flag : 1;
        unsigned int tcp_pause_ok : 1;
        unsigned int tcp_pause : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_TCP_TCPC_STAT_UNION;
#endif
#define SOC_TCP_TCPC_STAT_tcpc_busy_START (0)
#define SOC_TCP_TCPC_STAT_tcpc_busy_END (0)
#define SOC_TCP_TCPC_STAT_curr_st_START (1)
#define SOC_TCP_TCPC_STAT_curr_st_END (4)
#define SOC_TCP_TCPC_STAT_pc_stack_sel_pointer_START (5)
#define SOC_TCP_TCPC_STAT_pc_stack_sel_pointer_END (7)
#define SOC_TCP_TCPC_STAT_step_flag_START (8)
#define SOC_TCP_TCPC_STAT_step_flag_END (8)
#define SOC_TCP_TCPC_STAT_tcp_pause_ok_START (9)
#define SOC_TCP_TCPC_STAT_tcp_pause_ok_END (9)
#define SOC_TCP_TCPC_STAT_tcp_pause_START (10)
#define SOC_TCP_TCPC_STAT_tcp_pause_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcpc_pc_stat : 32;
    } reg;
} SOC_TCP_PC_STAT_UNION;
#endif
#define SOC_TCP_PC_STAT_tcpc_pc_stat_START (0)
#define SOC_TCP_PC_STAT_tcpc_pc_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp_pause_req : 1;
        unsigned int tcp_iram_auto_sw_on : 1;
        unsigned int tcp_pause_mode : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_TCP_PAUSE_REQ_UNION;
#endif
#define SOC_TCP_PAUSE_REQ_tcp_pause_req_START (0)
#define SOC_TCP_PAUSE_REQ_tcp_pause_req_END (0)
#define SOC_TCP_PAUSE_REQ_tcp_iram_auto_sw_on_START (1)
#define SOC_TCP_PAUSE_REQ_tcp_iram_auto_sw_on_END (1)
#define SOC_TCP_PAUSE_REQ_tcp_pause_mode_START (2)
#define SOC_TCP_PAUSE_REQ_tcp_pause_mode_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp_clk_on : 1;
        unsigned int hw_clk_byp : 1;
        unsigned int sync_cg_off : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_TCP_CLK_CTRL_UNION;
#endif
#define SOC_TCP_CLK_CTRL_tcp_clk_on_START (0)
#define SOC_TCP_CLK_CTRL_tcp_clk_on_END (0)
#define SOC_TCP_CLK_CTRL_hw_clk_byp_START (1)
#define SOC_TCP_CLK_CTRL_hw_clk_byp_END (1)
#define SOC_TCP_CLK_CTRL_sync_cg_off_START (2)
#define SOC_TCP_CLK_CTRL_sync_cg_off_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hprot_ctrl : 4;
        unsigned int hsel_ctrl : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_TCP_AHB_CTRL_UNION;
#endif
#define SOC_TCP_AHB_CTRL_hprot_ctrl_START (0)
#define SOC_TCP_AHB_CTRL_hprot_ctrl_END (3)
#define SOC_TCP_AHB_CTRL_hsel_ctrl_START (4)
#define SOC_TCP_AHB_CTRL_hsel_ctrl_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int err_stat_tcpc_busy : 1;
        unsigned int err_stat_curr_st : 4;
        unsigned int err_stat_pc_stack_sel_pointer : 3;
        unsigned int err_stat_step_flag : 1;
        unsigned int err_stat_tcp_pause_ok : 1;
        unsigned int err_stat_tcp_pause : 1;
        unsigned int err_stat_sel_sp_cnt : 8;
        unsigned int reserved : 13;
    } reg;
} SOC_TCP_ERR_TCPC_STAT_UNION;
#endif
#define SOC_TCP_ERR_TCPC_STAT_err_stat_tcpc_busy_START (0)
#define SOC_TCP_ERR_TCPC_STAT_err_stat_tcpc_busy_END (0)
#define SOC_TCP_ERR_TCPC_STAT_err_stat_curr_st_START (1)
#define SOC_TCP_ERR_TCPC_STAT_err_stat_curr_st_END (4)
#define SOC_TCP_ERR_TCPC_STAT_err_stat_pc_stack_sel_pointer_START (5)
#define SOC_TCP_ERR_TCPC_STAT_err_stat_pc_stack_sel_pointer_END (7)
#define SOC_TCP_ERR_TCPC_STAT_err_stat_step_flag_START (8)
#define SOC_TCP_ERR_TCPC_STAT_err_stat_step_flag_END (8)
#define SOC_TCP_ERR_TCPC_STAT_err_stat_tcp_pause_ok_START (9)
#define SOC_TCP_ERR_TCPC_STAT_err_stat_tcp_pause_ok_END (9)
#define SOC_TCP_ERR_TCPC_STAT_err_stat_tcp_pause_START (10)
#define SOC_TCP_ERR_TCPC_STAT_err_stat_tcp_pause_END (10)
#define SOC_TCP_ERR_TCPC_STAT_err_stat_sel_sp_cnt_START (11)
#define SOC_TCP_ERR_TCPC_STAT_err_stat_sel_sp_cnt_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int err_pc_stat : 32;
    } reg;
} SOC_TCP_ERR_PC_STAT_UNION;
#endif
#define SOC_TCP_ERR_PC_STAT_err_pc_stat_START (0)
#define SOC_TCP_ERR_PC_STAT_err_pc_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int err_haddr_stat : 32;
    } reg;
} SOC_TCP_ERR_AHB_ADDR_STAT_UNION;
#endif
#define SOC_TCP_ERR_AHB_ADDR_STAT_err_haddr_stat_START (0)
#define SOC_TCP_ERR_AHB_ADDR_STAT_err_haddr_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hwrite : 1;
        unsigned int htrans : 2;
        unsigned int hsize : 3;
        unsigned int reserved : 26;
    } reg;
} SOC_TCP_ERR_AHB_CTRL_STAT_UNION;
#endif
#define SOC_TCP_ERR_AHB_CTRL_STAT_hwrite_START (0)
#define SOC_TCP_ERR_AHB_CTRL_STAT_hwrite_END (0)
#define SOC_TCP_ERR_AHB_CTRL_STAT_htrans_START (1)
#define SOC_TCP_ERR_AHB_CTRL_STAT_htrans_END (2)
#define SOC_TCP_ERR_AHB_CTRL_STAT_hsize_START (3)
#define SOC_TCP_ERR_AHB_CTRL_STAT_hsize_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mem_ctrl : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_TCP_MEM_CTRL0_UNION;
#endif
#define SOC_TCP_MEM_CTRL0_mem_ctrl_START (0)
#define SOC_TCP_MEM_CTRL0_mem_ctrl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ram_ls : 8;
        unsigned int ram_ds : 8;
        unsigned int ram_sd : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_TCP_MEM_CTRL1_UNION;
#endif
#define SOC_TCP_MEM_CTRL1_ram_ls_START (0)
#define SOC_TCP_MEM_CTRL1_ram_ls_END (7)
#define SOC_TCP_MEM_CTRL1_ram_ds_START (8)
#define SOC_TCP_MEM_CTRL1_ram_ds_END (15)
#define SOC_TCP_MEM_CTRL1_ram_sd_START (16)
#define SOC_TCP_MEM_CTRL1_ram_sd_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iram_lock : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_TCP_IRAM_LOCK_UNION;
#endif
#define SOC_TCP_IRAM_LOCK_iram_lock_START (0)
#define SOC_TCP_IRAM_LOCK_iram_lock_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int en_reg_offset : 8;
        unsigned int dis_reg_offset : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_TCP_MOVE_MUTEX_CFG_UNION;
#endif
#define SOC_TCP_MOVE_MUTEX_CFG_en_reg_offset_START (0)
#define SOC_TCP_MOVE_MUTEX_CFG_en_reg_offset_END (7)
#define SOC_TCP_MOVE_MUTEX_CFG_dis_reg_offset_START (8)
#define SOC_TCP_MOVE_MUTEX_CFG_dis_reg_offset_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 15;
        unsigned int tcp_base_addr : 17;
    } reg;
} SOC_TCP_BASEADDR_UNION;
#endif
#define SOC_TCP_BASEADDR_tcp_base_addr_START (15)
#define SOC_TCP_BASEADDR_tcp_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int instr_code_size : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_TCP_INSTR_SIZE_CFG_UNION;
#endif
#define SOC_TCP_INSTR_SIZE_CFG_instr_code_size_START (0)
#define SOC_TCP_INSTR_SIZE_CFG_instr_code_size_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int inval_instr_stat : 1;
        unsigned int tcpcaddr_err_stat : 1;
        unsigned int add_carry_stat : 1;
        unsigned int task_timeout_stat : 1;
        unsigned int ahb_err_stat : 1;
        unsigned int ahb_addr_err_stat : 1;
        unsigned int pc_stack_err_stat : 1;
        unsigned int sp_err_stat : 1;
        unsigned int reserved_0 : 8;
        unsigned int soft_irq_stat : 4;
        unsigned int reserved_1 : 11;
        unsigned int glb_task_done_stat : 1;
    } reg;
} SOC_TCP_IRQ_STAT_UNION;
#endif
#define SOC_TCP_IRQ_STAT_inval_instr_stat_START (0)
#define SOC_TCP_IRQ_STAT_inval_instr_stat_END (0)
#define SOC_TCP_IRQ_STAT_tcpcaddr_err_stat_START (1)
#define SOC_TCP_IRQ_STAT_tcpcaddr_err_stat_END (1)
#define SOC_TCP_IRQ_STAT_add_carry_stat_START (2)
#define SOC_TCP_IRQ_STAT_add_carry_stat_END (2)
#define SOC_TCP_IRQ_STAT_task_timeout_stat_START (3)
#define SOC_TCP_IRQ_STAT_task_timeout_stat_END (3)
#define SOC_TCP_IRQ_STAT_ahb_err_stat_START (4)
#define SOC_TCP_IRQ_STAT_ahb_err_stat_END (4)
#define SOC_TCP_IRQ_STAT_ahb_addr_err_stat_START (5)
#define SOC_TCP_IRQ_STAT_ahb_addr_err_stat_END (5)
#define SOC_TCP_IRQ_STAT_pc_stack_err_stat_START (6)
#define SOC_TCP_IRQ_STAT_pc_stack_err_stat_END (6)
#define SOC_TCP_IRQ_STAT_sp_err_stat_START (7)
#define SOC_TCP_IRQ_STAT_sp_err_stat_END (7)
#define SOC_TCP_IRQ_STAT_soft_irq_stat_START (16)
#define SOC_TCP_IRQ_STAT_soft_irq_stat_END (19)
#define SOC_TCP_IRQ_STAT_glb_task_done_stat_START (31)
#define SOC_TCP_IRQ_STAT_glb_task_done_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int inval_instr_mask : 1;
        unsigned int tcpcaddr_err_mask : 1;
        unsigned int add_carry_mask : 1;
        unsigned int task_timeout_mask : 1;
        unsigned int ahb_err_mask : 1;
        unsigned int ahb_addr_err_mask : 1;
        unsigned int pc_stack_err_mask : 1;
        unsigned int sp_err_mask : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_TCP_IRQ_MASK_UNION;
#endif
#define SOC_TCP_IRQ_MASK_inval_instr_mask_START (0)
#define SOC_TCP_IRQ_MASK_inval_instr_mask_END (0)
#define SOC_TCP_IRQ_MASK_tcpcaddr_err_mask_START (1)
#define SOC_TCP_IRQ_MASK_tcpcaddr_err_mask_END (1)
#define SOC_TCP_IRQ_MASK_add_carry_mask_START (2)
#define SOC_TCP_IRQ_MASK_add_carry_mask_END (2)
#define SOC_TCP_IRQ_MASK_task_timeout_mask_START (3)
#define SOC_TCP_IRQ_MASK_task_timeout_mask_END (3)
#define SOC_TCP_IRQ_MASK_ahb_err_mask_START (4)
#define SOC_TCP_IRQ_MASK_ahb_err_mask_END (4)
#define SOC_TCP_IRQ_MASK_ahb_addr_err_mask_START (5)
#define SOC_TCP_IRQ_MASK_ahb_addr_err_mask_END (5)
#define SOC_TCP_IRQ_MASK_pc_stack_err_mask_START (6)
#define SOC_TCP_IRQ_MASK_pc_stack_err_mask_END (6)
#define SOC_TCP_IRQ_MASK_sp_err_mask_START (7)
#define SOC_TCP_IRQ_MASK_sp_err_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int inval_instr_clr : 1;
        unsigned int tcpcaddr_err_clr : 1;
        unsigned int add_carry_clr : 1;
        unsigned int task_timeout_clr : 1;
        unsigned int ahb_err_clr : 1;
        unsigned int ahb_addr_err_clr : 1;
        unsigned int pc_stack_err_clr : 1;
        unsigned int sp_err_clr : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_TCP_IRQ_CLR_UNION;
#endif
#define SOC_TCP_IRQ_CLR_inval_instr_clr_START (0)
#define SOC_TCP_IRQ_CLR_inval_instr_clr_END (0)
#define SOC_TCP_IRQ_CLR_tcpcaddr_err_clr_START (1)
#define SOC_TCP_IRQ_CLR_tcpcaddr_err_clr_END (1)
#define SOC_TCP_IRQ_CLR_add_carry_clr_START (2)
#define SOC_TCP_IRQ_CLR_add_carry_clr_END (2)
#define SOC_TCP_IRQ_CLR_task_timeout_clr_START (3)
#define SOC_TCP_IRQ_CLR_task_timeout_clr_END (3)
#define SOC_TCP_IRQ_CLR_ahb_err_clr_START (4)
#define SOC_TCP_IRQ_CLR_ahb_err_clr_END (4)
#define SOC_TCP_IRQ_CLR_ahb_addr_err_clr_START (5)
#define SOC_TCP_IRQ_CLR_ahb_addr_err_clr_END (5)
#define SOC_TCP_IRQ_CLR_pc_stack_err_clr_START (6)
#define SOC_TCP_IRQ_CLR_pc_stack_err_clr_END (6)
#define SOC_TCP_IRQ_CLR_sp_err_clr_START (7)
#define SOC_TCP_IRQ_CLR_sp_err_clr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_done_stat : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TCP_TASK_DONE_IRQ_STAT_UNION;
#endif
#define SOC_TCP_TASK_DONE_IRQ_STAT_task_done_stat_START (0)
#define SOC_TCP_TASK_DONE_IRQ_STAT_task_done_stat_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_done_mask : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TCP_TASK_DONE_IRQ_MASK_UNION;
#endif
#define SOC_TCP_TASK_DONE_IRQ_MASK_task_done_mask_START (0)
#define SOC_TCP_TASK_DONE_IRQ_MASK_task_done_mask_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_done_clr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TCP_TASK_DONE_IRQ_CLR_UNION;
#endif
#define SOC_TCP_TASK_DONE_IRQ_CLR_task_done_clr_START (0)
#define SOC_TCP_TASK_DONE_IRQ_CLR_task_done_clr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_TCP_DBG_CTRL_UNION;
#endif
#define SOC_TCP_DBG_CTRL_dbg_en_START (0)
#define SOC_TCP_DBG_CTRL_dbg_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_bk_addr : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_TCP_DBG_BKP_UNION;
#endif
#define SOC_TCP_DBG_BKP_dbg_bk_addr_START (0)
#define SOC_TCP_DBG_BKP_dbg_bk_addr_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_step : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_TCP_DBG_STEP_UNION;
#endif
#define SOC_TCP_DBG_STEP_dbg_step_START (0)
#define SOC_TCP_DBG_STEP_dbg_step_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_continue : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_TCP_DBG_CONTINUE_UNION;
#endif
#define SOC_TCP_DBG_CONTINUE_dbg_continue_START (0)
#define SOC_TCP_DBG_CONTINUE_dbg_continue_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdt_cnt : 18;
        unsigned int reserved_0: 6;
        unsigned int wdt_en : 1;
        unsigned int reserved_1: 7;
    } reg;
} SOC_TCP_WDT_CFG_UNION;
#endif
#define SOC_TCP_WDT_CFG_wdt_cnt_START (0)
#define SOC_TCP_WDT_CFG_wdt_cnt_END (17)
#define SOC_TCP_WDT_CFG_wdt_en_START (24)
#define SOC_TCP_WDT_CFG_wdt_en_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdt_cnt_stat : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_TCP_WDT_STAT_UNION;
#endif
#define SOC_TCP_WDT_STAT_wdt_cnt_stat_START (0)
#define SOC_TCP_WDT_STAT_wdt_cnt_stat_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_start_addr : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_TCP_TASK_START_ADDR_UNION;
#endif
#define SOC_TCP_TASK_START_ADDR_task_start_addr_START (0)
#define SOC_TCP_TASK_START_ADDR_task_start_addr_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_sel_ext_irq : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_TCP_EXT_IRQ_TASK_SEL_UNION;
#endif
#define SOC_TCP_EXT_IRQ_TASK_SEL_task_sel_ext_irq_START (0)
#define SOC_TCP_EXT_IRQ_TASK_SEL_task_sel_ext_irq_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ext_irq_en : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TCP_EXT_IRQ_EN_UNION;
#endif
#define SOC_TCP_EXT_IRQ_EN_ext_irq_en_START (0)
#define SOC_TCP_EXT_IRQ_EN_ext_irq_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int set_soft_req : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TCP_SOFT_REQ_SET_UNION;
#endif
#define SOC_TCP_SOFT_REQ_SET_set_soft_req_START (0)
#define SOC_TCP_SOFT_REQ_SET_set_soft_req_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clr_soft_req : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TCP_SOFT_REQ_CLR_UNION;
#endif
#define SOC_TCP_SOFT_REQ_CLR_clr_soft_req_START (0)
#define SOC_TCP_SOFT_REQ_CLR_clr_soft_req_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_sel_err_irq : 4;
        unsigned int reserved_0 : 4;
        unsigned int inval_instr_task_req_en : 1;
        unsigned int tcpcaddr_err_task_req_en : 1;
        unsigned int add_carry_task_req_en : 1;
        unsigned int task_timeout_task_req_en : 1;
        unsigned int ahb_err_task_req_en : 1;
        unsigned int ahb_addr_err_task_req_en : 1;
        unsigned int pc_stack_err_task_req_en : 1;
        unsigned int sp_err_task_req_en : 1;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_TCP_ERR_TASK_REQ_CFG_UNION;
#endif
#define SOC_TCP_ERR_TASK_REQ_CFG_task_sel_err_irq_START (0)
#define SOC_TCP_ERR_TASK_REQ_CFG_task_sel_err_irq_END (3)
#define SOC_TCP_ERR_TASK_REQ_CFG_inval_instr_task_req_en_START (8)
#define SOC_TCP_ERR_TASK_REQ_CFG_inval_instr_task_req_en_END (8)
#define SOC_TCP_ERR_TASK_REQ_CFG_tcpcaddr_err_task_req_en_START (9)
#define SOC_TCP_ERR_TASK_REQ_CFG_tcpcaddr_err_task_req_en_END (9)
#define SOC_TCP_ERR_TASK_REQ_CFG_add_carry_task_req_en_START (10)
#define SOC_TCP_ERR_TASK_REQ_CFG_add_carry_task_req_en_END (10)
#define SOC_TCP_ERR_TASK_REQ_CFG_task_timeout_task_req_en_START (11)
#define SOC_TCP_ERR_TASK_REQ_CFG_task_timeout_task_req_en_END (11)
#define SOC_TCP_ERR_TASK_REQ_CFG_ahb_err_task_req_en_START (12)
#define SOC_TCP_ERR_TASK_REQ_CFG_ahb_err_task_req_en_END (12)
#define SOC_TCP_ERR_TASK_REQ_CFG_ahb_addr_err_task_req_en_START (13)
#define SOC_TCP_ERR_TASK_REQ_CFG_ahb_addr_err_task_req_en_END (13)
#define SOC_TCP_ERR_TASK_REQ_CFG_pc_stack_err_task_req_en_START (14)
#define SOC_TCP_ERR_TASK_REQ_CFG_pc_stack_err_task_req_en_END (14)
#define SOC_TCP_ERR_TASK_REQ_CFG_sp_err_task_req_en_START (15)
#define SOC_TCP_ERR_TASK_REQ_CFG_sp_err_task_req_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_sel_tim_tick : 4;
        unsigned int reserved_0 : 4;
        unsigned int tim_tick_req_en : 1;
        unsigned int tim_tick_req_clr : 1;
        unsigned int reserved_1 : 22;
    } reg;
} SOC_TCP_TIM_TASK_REQ_CFG_UNION;
#endif
#define SOC_TCP_TIM_TASK_REQ_CFG_task_sel_tim_tick_START (0)
#define SOC_TCP_TIM_TASK_REQ_CFG_task_sel_tim_tick_END (3)
#define SOC_TCP_TIM_TASK_REQ_CFG_tim_tick_req_en_START (8)
#define SOC_TCP_TIM_TASK_REQ_CFG_tim_tick_req_en_END (8)
#define SOC_TCP_TIM_TASK_REQ_CFG_tim_tick_req_clr_START (9)
#define SOC_TCP_TIM_TASK_REQ_CFG_tim_tick_req_clr_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_glb_req_stat : 32;
    } reg;
} SOC_TCP_GLB_TASK_REQ_STAT_UNION;
#endif
#define SOC_TCP_GLB_TASK_REQ_STAT_task_glb_req_stat_START (0)
#define SOC_TCP_GLB_TASK_REQ_STAT_task_glb_req_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_stat : 32;
    } reg;
} SOC_TCP_TASK_STAT_UNION;
#endif
#define SOC_TCP_TASK_STAT_task_stat_START (0)
#define SOC_TCP_TASK_STAT_task_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_req_clr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TCP_TASK_REQ_CLR_UNION;
#endif
#define SOC_TCP_TASK_REQ_CLR_task_req_clr_START (0)
#define SOC_TCP_TASK_REQ_CLR_task_req_clr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_req_lock : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TCP_TASK_REQ_LOCK_UNION;
#endif
#define SOC_TCP_TASK_REQ_LOCK_task_req_lock_START (0)
#define SOC_TCP_TASK_REQ_LOCK_task_req_lock_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_req_unlock : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TCP_TASK_REQ_UNLOCK_UNION;
#endif
#define SOC_TCP_TASK_REQ_UNLOCK_task_req_unlock_START (0)
#define SOC_TCP_TASK_REQ_UNLOCK_task_req_unlock_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_req_lock_stat : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TCP_TASK_REQ_LOCK_STAT_UNION;
#endif
#define SOC_TCP_TASK_REQ_LOCK_STAT_task_req_lock_stat_START (0)
#define SOC_TCP_TASK_REQ_LOCK_STAT_task_req_lock_stat_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_soft_irq_set : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_TCP_SOFT_IRQ_SET_UNION;
#endif
#define SOC_TCP_SOFT_IRQ_SET_l2_soft_irq_set_START (0)
#define SOC_TCP_SOFT_IRQ_SET_l2_soft_irq_set_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_soft_irq_clr : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_TCP_SOFT_IRQ_CLR_UNION;
#endif
#define SOC_TCP_SOFT_IRQ_CLR_l2_soft_irq_clr_START (0)
#define SOC_TCP_SOFT_IRQ_CLR_l2_soft_irq_clr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_soft_irq_mask : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_TCP_SOFT_IRQ_MASK_UNION;
#endif
#define SOC_TCP_SOFT_IRQ_MASK_l2_soft_irq_mask_START (0)
#define SOC_TCP_SOFT_IRQ_MASK_l2_soft_irq_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_soft_irq_stat : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_TCP_SOFT_IRQ_STAT_UNION;
#endif
#define SOC_TCP_SOFT_IRQ_STAT_l2_soft_irq_stat_START (0)
#define SOC_TCP_SOFT_IRQ_STAT_l2_soft_irq_stat_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_chn_en : 1;
        unsigned int reserved : 18;
        unsigned int addr_chn_base : 13;
    } reg;
} SOC_TCP_TCPC_AHB_ADDR_CHN_UNION;
#endif
#define SOC_TCP_TCPC_AHB_ADDR_CHN_addr_chn_en_START (0)
#define SOC_TCP_TCPC_AHB_ADDR_CHN_addr_chn_en_END (0)
#define SOC_TCP_TCPC_AHB_ADDR_CHN_addr_chn_base_START (19)
#define SOC_TCP_TCPC_AHB_ADDR_CHN_addr_chn_base_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tim_cnt : 16;
        unsigned int tim_en : 1;
        unsigned int tim_mode : 1;
        unsigned int reserved_0 : 6;
        unsigned int tim_clk_div_sel : 2;
        unsigned int tim_clk_on : 1;
        unsigned int tim_clk_sel : 1;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_TCP_TIM_CFG_UNION;
#endif
#define SOC_TCP_TIM_CFG_tim_cnt_START (0)
#define SOC_TCP_TIM_CFG_tim_cnt_END (15)
#define SOC_TCP_TIM_CFG_tim_en_START (16)
#define SOC_TCP_TIM_CFG_tim_en_END (16)
#define SOC_TCP_TIM_CFG_tim_mode_START (17)
#define SOC_TCP_TIM_CFG_tim_mode_END (17)
#define SOC_TCP_TIM_CFG_tim_clk_div_sel_START (24)
#define SOC_TCP_TIM_CFG_tim_clk_div_sel_END (25)
#define SOC_TCP_TIM_CFG_tim_clk_on_START (26)
#define SOC_TCP_TIM_CFG_tim_clk_on_END (26)
#define SOC_TCP_TIM_CFG_tim_clk_sel_START (27)
#define SOC_TCP_TIM_CFG_tim_clk_sel_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tim_cnt_stat : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TCP_TIM_STAT_UNION;
#endif
#define SOC_TCP_TIM_STAT_tim_cnt_stat_START (0)
#define SOC_TCP_TIM_STAT_tim_cnt_stat_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int greg_stat : 32;
    } reg;
} SOC_TCP_GENERAL_REG_UNION;
#endif
#define SOC_TCP_GENERAL_REG_greg_stat_START (0)
#define SOC_TCP_GENERAL_REG_greg_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int common_reg : 32;
    } reg;
} SOC_TCP_COMMON_REG_UNION;
#endif
#define SOC_TCP_COMMON_REG_common_reg_START (0)
#define SOC_TCP_COMMON_REG_common_reg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_stacks_baseline : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_TCP_STACKS_BASELINE_UNION;
#endif
#define SOC_TCP_STACKS_BASELINE_task_stacks_baseline_START (0)
#define SOC_TCP_STACKS_BASELINE_task_stacks_baseline_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sp_stat : 8;
        unsigned int pc_stat : 3;
        unsigned int reserved : 21;
    } reg;
} SOC_TCP_STACK_STAT_UNION;
#endif
#define SOC_TCP_STACK_STAT_sp_stat_START (0)
#define SOC_TCP_STACK_STAT_sp_stat_END (7)
#define SOC_TCP_STACK_STAT_pc_stat_START (8)
#define SOC_TCP_STACK_STAT_pc_stat_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sw_req_stat : 1;
        unsigned int tim_req_stat : 1;
        unsigned int ext_req_stat : 1;
        unsigned int err_req_stat : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_TCP_TASK_REQ_STAT_UNION;
#endif
#define SOC_TCP_TASK_REQ_STAT_sw_req_stat_START (0)
#define SOC_TCP_TASK_REQ_STAT_sw_req_stat_END (0)
#define SOC_TCP_TASK_REQ_STAT_tim_req_stat_START (1)
#define SOC_TCP_TASK_REQ_STAT_tim_req_stat_END (1)
#define SOC_TCP_TASK_REQ_STAT_ext_req_stat_START (2)
#define SOC_TCP_TASK_REQ_STAT_ext_req_stat_END (2)
#define SOC_TCP_TASK_REQ_STAT_err_req_stat_START (3)
#define SOC_TCP_TASK_REQ_STAT_err_req_stat_END (3)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
