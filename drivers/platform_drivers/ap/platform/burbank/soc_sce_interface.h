#ifndef __SOC_SCE_INTERFACE_H__
#define __SOC_SCE_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_SCE_MODE_ADDR(base) ((base) + (0x0000))
#define SOC_SCE_RX_DAT_LEN_ADDR(base) ((base) + (0x0004))
#define SOC_SCE_CFG_ADDR(base) ((base) + (0x0008))
#define SOC_SCE_BUSY_DONE_ADDR(base) ((base) + (0x000C))
#define SOC_SCE_FIFO_LINE_ADDR(base) ((base) + (0x0010))
#define SOC_SCE_STR_RUN_ADDR(base) ((base) + (0x0014))
#define SOC_SCE_ALARM_ADDR(base) ((base) + (0x0018))
#define SOC_SCE_ALARM_MASK_EN_ADDR(base) ((base) + (0x001C))
#define SOC_SCE_ALARM_CLR_ADDR(base) ((base) + (0x0020))
#define SOC_SCE_ALARM_MASK_ADDR(base) ((base) + (0x0024))
#define SOC_SCE_TX_DAT_LEN_ADDR(base) ((base) + (0x0030))
#define SOC_SCE_REG_LOCK_ADDR(base) ((base) + (0x0034))
#define SOC_SCE_DIN_ADDR(base,n) ((base) + (0x0040+(n)*4))
#define SOC_SCE_IVIN_ADDR(base,n) ((base) + (0x0080+(n)*4))
#define SOC_SCE_DOUT_ADDR(base,n) ((base) + (0x00C0+(n)*4))
#define SOC_SCE_IVOUT_ADDR(base,n) ((base) + (0x0100+(n)*4))
#define SOC_SCE_POWER_DISTURB_EN_ADDR(base) ((base) + (0x0140))
#define SOC_SCE_POWER_DISTURB_RUN_ADDR(base) ((base) + (0x0144))
#define SOC_SCE_POWER_DISTURB_DIN_ADDR(base,n) ((base) + (0x0180+(n)*4))
#define SOC_SCE_REDROUND_EN_ADDR(base) ((base) + (0x01C0))
#define SOC_SCE_REDROUND_NUM_ADDR(base) ((base) + (0x01C4))
#define SOC_SCE_RNG_ACTIVE_CHECK_EN_ADDR(base) ((base) + (0x01C8))
#define SOC_SCE_HASH_PADDING_EN_ADDR(base) ((base) + (0x01CC))
#define SOC_SCE_EFUSEC_DBG_ADDR(base) ((base) + (0x01D0))
#define SOC_SCE_IP_EN_ADDR(base) ((base) + (0x01D4))
#define SOC_SCE_HASH_DATA_LENTH_ALL_ADDR(base) ((base) + (0x0200))
#define SOC_SCE_CNTIN_ADDR(base,n) ((base) + (0x0240+(n)*4))
#define SOC_SCE_CNTOUT_ADDR(base,n) ((base) + (0x0280+(n)*4))
#define SOC_SCE_SRC_ADDR_ADDR(base) ((base) + (0x02C0))
#define SOC_SCE_DES_ADDR_ADDR(base) ((base) + (0x02C4))
#define SOC_SCE_IV_BYPASS_ADDR(base) ((base) + (0x02CC))
#define SOC_SCE_INT_SCE_MASK_EN_ADDR(base) ((base) + (0x02D0))
#define SOC_SCE_INT_SCE_MASK_ADDR(base) ((base) + (0x02D4))
#define SOC_SCE_INT_SCE_ADDR(base) ((base) + (0x02D8))
#define SOC_SCE_INT_SCE_CLR_ADDR(base) ((base) + (0x02DC))
#define SOC_SCE_FIFO_RX_WDATA_ADDR(base) ((base) + (0x02E0))
#define SOC_SCE_FIFO_RX_RDATA_ADDR(base) ((base) + (0x02E4))
#define SOC_SCE_FIFO_TX_WDATA_ADDR(base) ((base) + (0x02E8))
#define SOC_SCE_FIFO_TX_RDATA_ADDR(base) ((base) + (0x02EC))
#define SOC_SCE_PROT_ADDR(base) ((base) + (0x02F0))
#define SOC_SCE_TP_MUX_ADDR(base) ((base) + (0x02F4))
#define SOC_SCE_CACHE_CTRL_ADDR(base) ((base) + (0x300))
#define SOC_SCE_RX_RES_BURST_ADDR(base) ((base) + (0x304))
#define SOC_SCE_RX_RES_WORD_ADDR(base) ((base) + (0x308))
#define SOC_SCE_TX_REMAIN_BURST_ADDR(base) ((base) + (0x30C))
#define SOC_SCE_TX_REMAIN_WORD_ADDR(base) ((base) + (0x310))
#define SOC_SCE_AAD_LEN_ADDR(base) ((base) + (0x0314))
#define SOC_SCE_T_Q_LENTH_ADDR(base) ((base) + (0x0318))
#define SOC_SCE_CCM_VER_FAIL_ADDR(base) ((base) + (0x031c))
#define SOC_SCE_CCM_VER_FAIL_CLR_ADDR(base) ((base) + (0x0320))
#define SOC_SCE_AES_KEY_PARITY_ADDR(base) ((base) + (0x0324))
#define SOC_SCE_AES_KEY2_PARITY_ADDR(base) ((base) + (0x0328))
#define SOC_SCE_KEY_REG_LOCK_ADDR(base) ((base) + (0x32c))
#define SOC_SCE_gcm_counter0_ADDR(base,n) ((base) + (0x0340+(n)*4))
#define SOC_SCE_ccm_q_ADDR(base,n) ((base) + (0x0380+(n)*4))
#define SOC_SCE_ccm_nonce_ADDR(base,n) ((base) + (0x03c0+(n)*4))
#define SOC_SCE_tweak_value_ADDR(base,n) ((base) + (0x0400+(n)*4))
#define SOC_SCE_xts_multi_data_ADDR(base,n) ((base) + (0x0440+(n)*4))
#define SOC_SCE_previous_ghash_digest_ADDR(base,n) ((base) + (0x0480+(n)*4))
#define SOC_SCE_aes_tag_out_ADDR(base,n) ((base) + (0x04c0+(n)*4))
#define SOC_SCE_ccm_tag_out_4ver_ADDR(base,n) ((base) + (0x0500+(n)*4))
#define SOC_SCE_AES_KEY1_ADDR(base,n) ((base) + (0x0540+(n)*4))
#define SOC_SCE_AESKEY1_MASK_VALUE_ADDR(base) ((base) + (0x0580))
#define SOC_SCE_AES_KEY2_ADDR(base,n) ((base) + (0x05C0+(n)*4))
#define SOC_SCE_AESKEY2_MASK_VALUE_ADDR(base) ((base) + (0x06a0))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sce_rx_dma_mode : 1;
        unsigned int reserved_0 : 3;
        unsigned int sce_ip_sel : 4;
        unsigned int sce_tx_dma_mode : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_SCE_MODE_UNION;
#endif
#define SOC_SCE_MODE_sce_rx_dma_mode_START (0)
#define SOC_SCE_MODE_sce_rx_dma_mode_END (0)
#define SOC_SCE_MODE_sce_ip_sel_START (4)
#define SOC_SCE_MODE_sce_ip_sel_END (7)
#define SOC_SCE_MODE_sce_tx_dma_mode_START (8)
#define SOC_SCE_MODE_sce_tx_dma_mode_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sce_rx_dat_len : 32;
    } reg;
} SOC_SCE_RX_DAT_LEN_UNION;
#endif
#define SOC_SCE_RX_DAT_LEN_sce_rx_dat_len_START (0)
#define SOC_SCE_RX_DAT_LEN_sce_rx_dat_len_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lowpower_en : 1;
        unsigned int reserved_0 : 3;
        unsigned int sce_decrypt : 1;
        unsigned int reserved_1 : 3;
        unsigned int sce_mode : 4;
        unsigned int sce_key_length : 2;
        unsigned int reserved_2 : 2;
        unsigned int mask_disable : 1;
        unsigned int reserved_3 : 3;
        unsigned int sce_dfa_en : 1;
        unsigned int reserved_4 : 3;
        unsigned int tdes : 1;
        unsigned int reserved_5 : 3;
        unsigned int tx_big_little_end : 1;
        unsigned int rx_big_little_end : 1;
        unsigned int sce_padding_sel : 1;
        unsigned int reserved_6 : 1;
    } reg;
} SOC_SCE_CFG_UNION;
#endif
#define SOC_SCE_CFG_lowpower_en_START (0)
#define SOC_SCE_CFG_lowpower_en_END (0)
#define SOC_SCE_CFG_sce_decrypt_START (4)
#define SOC_SCE_CFG_sce_decrypt_END (4)
#define SOC_SCE_CFG_sce_mode_START (8)
#define SOC_SCE_CFG_sce_mode_END (11)
#define SOC_SCE_CFG_sce_key_length_START (12)
#define SOC_SCE_CFG_sce_key_length_END (13)
#define SOC_SCE_CFG_mask_disable_START (16)
#define SOC_SCE_CFG_mask_disable_END (16)
#define SOC_SCE_CFG_sce_dfa_en_START (20)
#define SOC_SCE_CFG_sce_dfa_en_END (20)
#define SOC_SCE_CFG_tdes_START (24)
#define SOC_SCE_CFG_tdes_END (24)
#define SOC_SCE_CFG_tx_big_little_end_START (28)
#define SOC_SCE_CFG_tx_big_little_end_END (28)
#define SOC_SCE_CFG_rx_big_little_end_START (29)
#define SOC_SCE_CFG_rx_big_little_end_END (29)
#define SOC_SCE_CFG_sce_padding_sel_START (30)
#define SOC_SCE_CFG_sce_padding_sel_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 4;
        unsigned int sce_busy_reg : 1;
        unsigned int reserved_1 : 3;
        unsigned int sce_done_reg : 1;
        unsigned int reserved_2 : 3;
        unsigned int ctrl_rx_busy : 1;
        unsigned int reserved_3 : 3;
        unsigned int ctrl_tx_busy : 1;
        unsigned int reserved_4 : 15;
    } reg;
} SOC_SCE_BUSY_DONE_UNION;
#endif
#define SOC_SCE_BUSY_DONE_sce_busy_reg_START (4)
#define SOC_SCE_BUSY_DONE_sce_busy_reg_END (4)
#define SOC_SCE_BUSY_DONE_sce_done_reg_START (8)
#define SOC_SCE_BUSY_DONE_sce_done_reg_END (8)
#define SOC_SCE_BUSY_DONE_ctrl_rx_busy_START (12)
#define SOC_SCE_BUSY_DONE_ctrl_rx_busy_END (12)
#define SOC_SCE_BUSY_DONE_ctrl_tx_busy_START (16)
#define SOC_SCE_BUSY_DONE_ctrl_tx_busy_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 4;
        unsigned int fifo_rx_afull : 1;
        unsigned int fifo_rx_aempty : 1;
        unsigned int fifo_rx_empty : 1;
        unsigned int fifo_rx_full : 1;
        unsigned int fifo_rx_cnt : 8;
        unsigned int fifo_tx_afull : 1;
        unsigned int fifo_tx_aempty : 1;
        unsigned int fifo_tx_empty : 1;
        unsigned int fifo_tx_full : 1;
        unsigned int fifo_tx_cnt : 8;
    } reg;
} SOC_SCE_FIFO_LINE_UNION;
#endif
#define SOC_SCE_FIFO_LINE_fifo_rx_afull_START (8)
#define SOC_SCE_FIFO_LINE_fifo_rx_afull_END (8)
#define SOC_SCE_FIFO_LINE_fifo_rx_aempty_START (9)
#define SOC_SCE_FIFO_LINE_fifo_rx_aempty_END (9)
#define SOC_SCE_FIFO_LINE_fifo_rx_empty_START (10)
#define SOC_SCE_FIFO_LINE_fifo_rx_empty_END (10)
#define SOC_SCE_FIFO_LINE_fifo_rx_full_START (11)
#define SOC_SCE_FIFO_LINE_fifo_rx_full_END (11)
#define SOC_SCE_FIFO_LINE_fifo_rx_cnt_START (12)
#define SOC_SCE_FIFO_LINE_fifo_rx_cnt_END (19)
#define SOC_SCE_FIFO_LINE_fifo_tx_afull_START (20)
#define SOC_SCE_FIFO_LINE_fifo_tx_afull_END (20)
#define SOC_SCE_FIFO_LINE_fifo_tx_aempty_START (21)
#define SOC_SCE_FIFO_LINE_fifo_tx_aempty_END (21)
#define SOC_SCE_FIFO_LINE_fifo_tx_empty_START (22)
#define SOC_SCE_FIFO_LINE_fifo_tx_empty_END (22)
#define SOC_SCE_FIFO_LINE_fifo_tx_full_START (23)
#define SOC_SCE_FIFO_LINE_fifo_tx_full_END (23)
#define SOC_SCE_FIFO_LINE_fifo_tx_cnt_START (24)
#define SOC_SCE_FIFO_LINE_fifo_tx_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sce_run : 1;
        unsigned int reserved_0: 3;
        unsigned int sce_str : 1;
        unsigned int reserved_1: 3;
        unsigned int reserved_2: 24;
    } reg;
} SOC_SCE_STR_RUN_UNION;
#endif
#define SOC_SCE_STR_RUN_sce_run_START (0)
#define SOC_SCE_STR_RUN_sce_run_END (0)
#define SOC_SCE_STR_RUN_sce_str_START (4)
#define SOC_SCE_STR_RUN_sce_str_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aes_alarm : 4;
        unsigned int sm4_alarm : 4;
        unsigned int des_alarm : 4;
        unsigned int sce_alarm : 1;
        unsigned int reg_check_alarm : 1;
        unsigned int reg_access_alarm : 1;
        unsigned int rx_response_alarm : 1;
        unsigned int tx_response_alarm : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_SCE_ALARM_UNION;
#endif
#define SOC_SCE_ALARM_aes_alarm_START (0)
#define SOC_SCE_ALARM_aes_alarm_END (3)
#define SOC_SCE_ALARM_sm4_alarm_START (4)
#define SOC_SCE_ALARM_sm4_alarm_END (7)
#define SOC_SCE_ALARM_des_alarm_START (8)
#define SOC_SCE_ALARM_des_alarm_END (11)
#define SOC_SCE_ALARM_sce_alarm_START (12)
#define SOC_SCE_ALARM_sce_alarm_END (12)
#define SOC_SCE_ALARM_reg_check_alarm_START (13)
#define SOC_SCE_ALARM_reg_check_alarm_END (13)
#define SOC_SCE_ALARM_reg_access_alarm_START (14)
#define SOC_SCE_ALARM_reg_access_alarm_END (14)
#define SOC_SCE_ALARM_rx_response_alarm_START (15)
#define SOC_SCE_ALARM_rx_response_alarm_END (15)
#define SOC_SCE_ALARM_tx_response_alarm_START (16)
#define SOC_SCE_ALARM_tx_response_alarm_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aes_alaram_mask_en : 4;
        unsigned int sm4_alaram_mask_en : 4;
        unsigned int des_alaram_mask_en : 4;
        unsigned int alarm_mask_en : 4;
        unsigned int reg_check_alarm_mask_en : 4;
        unsigned int reg_access_alarm_mask_en : 4;
        unsigned int rx_response_alarm_mask_en : 4;
        unsigned int tx_response_alarm_mask_en : 4;
    } reg;
} SOC_SCE_ALARM_MASK_EN_UNION;
#endif
#define SOC_SCE_ALARM_MASK_EN_aes_alaram_mask_en_START (0)
#define SOC_SCE_ALARM_MASK_EN_aes_alaram_mask_en_END (3)
#define SOC_SCE_ALARM_MASK_EN_sm4_alaram_mask_en_START (4)
#define SOC_SCE_ALARM_MASK_EN_sm4_alaram_mask_en_END (7)
#define SOC_SCE_ALARM_MASK_EN_des_alaram_mask_en_START (8)
#define SOC_SCE_ALARM_MASK_EN_des_alaram_mask_en_END (11)
#define SOC_SCE_ALARM_MASK_EN_alarm_mask_en_START (12)
#define SOC_SCE_ALARM_MASK_EN_alarm_mask_en_END (15)
#define SOC_SCE_ALARM_MASK_EN_reg_check_alarm_mask_en_START (16)
#define SOC_SCE_ALARM_MASK_EN_reg_check_alarm_mask_en_END (19)
#define SOC_SCE_ALARM_MASK_EN_reg_access_alarm_mask_en_START (20)
#define SOC_SCE_ALARM_MASK_EN_reg_access_alarm_mask_en_END (23)
#define SOC_SCE_ALARM_MASK_EN_rx_response_alarm_mask_en_START (24)
#define SOC_SCE_ALARM_MASK_EN_rx_response_alarm_mask_en_END (27)
#define SOC_SCE_ALARM_MASK_EN_tx_response_alarm_mask_en_START (28)
#define SOC_SCE_ALARM_MASK_EN_tx_response_alarm_mask_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aes_alaram_clr : 4;
        unsigned int sm4_alaram_clr : 4;
        unsigned int des_alaram_clr : 4;
        unsigned int alaram_clr : 4;
        unsigned int reg_check_alarm_clr : 4;
        unsigned int reg_access_alarm_clr : 4;
        unsigned int rx_response_alarm_clr : 4;
        unsigned int tx_response_alarm_clr : 4;
    } reg;
} SOC_SCE_ALARM_CLR_UNION;
#endif
#define SOC_SCE_ALARM_CLR_aes_alaram_clr_START (0)
#define SOC_SCE_ALARM_CLR_aes_alaram_clr_END (3)
#define SOC_SCE_ALARM_CLR_sm4_alaram_clr_START (4)
#define SOC_SCE_ALARM_CLR_sm4_alaram_clr_END (7)
#define SOC_SCE_ALARM_CLR_des_alaram_clr_START (8)
#define SOC_SCE_ALARM_CLR_des_alaram_clr_END (11)
#define SOC_SCE_ALARM_CLR_alaram_clr_START (12)
#define SOC_SCE_ALARM_CLR_alaram_clr_END (15)
#define SOC_SCE_ALARM_CLR_reg_check_alarm_clr_START (16)
#define SOC_SCE_ALARM_CLR_reg_check_alarm_clr_END (19)
#define SOC_SCE_ALARM_CLR_reg_access_alarm_clr_START (20)
#define SOC_SCE_ALARM_CLR_reg_access_alarm_clr_END (23)
#define SOC_SCE_ALARM_CLR_rx_response_alarm_clr_START (24)
#define SOC_SCE_ALARM_CLR_rx_response_alarm_clr_END (27)
#define SOC_SCE_ALARM_CLR_tx_response_alarm_clr_START (28)
#define SOC_SCE_ALARM_CLR_tx_response_alarm_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aes_alaram_mask : 4;
        unsigned int sm4_alaram_mask : 4;
        unsigned int des_alaram_mask : 4;
        unsigned int sce_alarm_mask : 1;
        unsigned int reg_check_alarm_mask : 1;
        unsigned int reg_access_alarm_mask : 1;
        unsigned int rx_response_alarm_mask : 1;
        unsigned int tx_response_alarm_mask : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_SCE_ALARM_MASK_UNION;
#endif
#define SOC_SCE_ALARM_MASK_aes_alaram_mask_START (0)
#define SOC_SCE_ALARM_MASK_aes_alaram_mask_END (3)
#define SOC_SCE_ALARM_MASK_sm4_alaram_mask_START (4)
#define SOC_SCE_ALARM_MASK_sm4_alaram_mask_END (7)
#define SOC_SCE_ALARM_MASK_des_alaram_mask_START (8)
#define SOC_SCE_ALARM_MASK_des_alaram_mask_END (11)
#define SOC_SCE_ALARM_MASK_sce_alarm_mask_START (12)
#define SOC_SCE_ALARM_MASK_sce_alarm_mask_END (12)
#define SOC_SCE_ALARM_MASK_reg_check_alarm_mask_START (13)
#define SOC_SCE_ALARM_MASK_reg_check_alarm_mask_END (13)
#define SOC_SCE_ALARM_MASK_reg_access_alarm_mask_START (14)
#define SOC_SCE_ALARM_MASK_reg_access_alarm_mask_END (14)
#define SOC_SCE_ALARM_MASK_rx_response_alarm_mask_START (15)
#define SOC_SCE_ALARM_MASK_rx_response_alarm_mask_END (15)
#define SOC_SCE_ALARM_MASK_tx_response_alarm_mask_START (16)
#define SOC_SCE_ALARM_MASK_tx_response_alarm_mask_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sce_tx_dat_len : 32;
    } reg;
} SOC_SCE_TX_DAT_LEN_UNION;
#endif
#define SOC_SCE_TX_DAT_LEN_sce_tx_dat_len_START (0)
#define SOC_SCE_TX_DAT_LEN_sce_tx_dat_len_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sce_reg_lock : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_SCE_REG_LOCK_UNION;
#endif
#define SOC_SCE_REG_LOCK_sce_reg_lock_START (0)
#define SOC_SCE_REG_LOCK_sce_reg_lock_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sce_din : 32;
    } reg;
} SOC_SCE_DIN_UNION;
#endif
#define SOC_SCE_DIN_sce_din_START (0)
#define SOC_SCE_DIN_sce_din_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sce_ivin : 32;
    } reg;
} SOC_SCE_IVIN_UNION;
#endif
#define SOC_SCE_IVIN_sce_ivin_START (0)
#define SOC_SCE_IVIN_sce_ivin_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sce_dout : 32;
    } reg;
} SOC_SCE_DOUT_UNION;
#endif
#define SOC_SCE_DOUT_sce_dout_START (0)
#define SOC_SCE_DOUT_sce_dout_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sce_ivout : 32;
    } reg;
} SOC_SCE_IVOUT_UNION;
#endif
#define SOC_SCE_IVOUT_sce_ivout_START (0)
#define SOC_SCE_IVOUT_sce_ivout_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int power_disturb_en : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_SCE_POWER_DISTURB_EN_UNION;
#endif
#define SOC_SCE_POWER_DISTURB_EN_power_disturb_en_START (0)
#define SOC_SCE_POWER_DISTURB_EN_power_disturb_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int power_disturb_run : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SCE_POWER_DISTURB_RUN_UNION;
#endif
#define SOC_SCE_POWER_DISTURB_RUN_power_disturb_run_START (0)
#define SOC_SCE_POWER_DISTURB_RUN_power_disturb_run_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int power_disturb_din : 32;
    } reg;
} SOC_SCE_POWER_DISTURB_DIN_UNION;
#endif
#define SOC_SCE_POWER_DISTURB_DIN_power_disturb_din_START (0)
#define SOC_SCE_POWER_DISTURB_DIN_power_disturb_din_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sce_redround_en : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_SCE_REDROUND_EN_UNION;
#endif
#define SOC_SCE_REDROUND_EN_sce_redround_en_START (0)
#define SOC_SCE_REDROUND_EN_sce_redround_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sce_redround_num : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_SCE_REDROUND_NUM_UNION;
#endif
#define SOC_SCE_REDROUND_NUM_sce_redround_num_START (0)
#define SOC_SCE_REDROUND_NUM_sce_redround_num_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rng_active_check_en : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_SCE_RNG_ACTIVE_CHECK_EN_UNION;
#endif
#define SOC_SCE_RNG_ACTIVE_CHECK_EN_rng_active_check_en_START (0)
#define SOC_SCE_RNG_ACTIVE_CHECK_EN_rng_active_check_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hash_padding_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SCE_HASH_PADDING_EN_UNION;
#endif
#define SOC_SCE_HASH_PADDING_EN_hash_padding_en_START (0)
#define SOC_SCE_HASH_PADDING_EN_hash_padding_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_disable : 4;
        unsigned int tdes_disable : 1;
        unsigned int des_disable : 1;
        unsigned int sm4_disable : 1;
        unsigned int sm3_disable : 1;
        unsigned int sha1_disable : 1;
        unsigned int md5_disable : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_SCE_EFUSEC_DBG_UNION;
#endif
#define SOC_SCE_EFUSEC_DBG_debug_disable_START (0)
#define SOC_SCE_EFUSEC_DBG_debug_disable_END (3)
#define SOC_SCE_EFUSEC_DBG_tdes_disable_START (4)
#define SOC_SCE_EFUSEC_DBG_tdes_disable_END (4)
#define SOC_SCE_EFUSEC_DBG_des_disable_START (5)
#define SOC_SCE_EFUSEC_DBG_des_disable_END (5)
#define SOC_SCE_EFUSEC_DBG_sm4_disable_START (6)
#define SOC_SCE_EFUSEC_DBG_sm4_disable_END (6)
#define SOC_SCE_EFUSEC_DBG_sm3_disable_START (7)
#define SOC_SCE_EFUSEC_DBG_sm3_disable_END (7)
#define SOC_SCE_EFUSEC_DBG_sha1_disable_START (8)
#define SOC_SCE_EFUSEC_DBG_sha1_disable_END (8)
#define SOC_SCE_EFUSEC_DBG_md5_disable_START (9)
#define SOC_SCE_EFUSEC_DBG_md5_disable_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aes_en : 4;
        unsigned int sm4_en : 4;
        unsigned int des_en : 4;
        unsigned int reserved : 20;
    } reg;
} SOC_SCE_IP_EN_UNION;
#endif
#define SOC_SCE_IP_EN_aes_en_START (0)
#define SOC_SCE_IP_EN_aes_en_END (3)
#define SOC_SCE_IP_EN_sm4_en_START (4)
#define SOC_SCE_IP_EN_sm4_en_END (7)
#define SOC_SCE_IP_EN_des_en_START (8)
#define SOC_SCE_IP_EN_des_en_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hash_data_lenth_all : 32;
    } reg;
} SOC_SCE_HASH_DATA_LENTH_ALL_UNION;
#endif
#define SOC_SCE_HASH_DATA_LENTH_ALL_hash_data_lenth_all_START (0)
#define SOC_SCE_HASH_DATA_LENTH_ALL_hash_data_lenth_all_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sce_cntin : 32;
    } reg;
} SOC_SCE_CNTIN_UNION;
#endif
#define SOC_SCE_CNTIN_sce_cntin_START (0)
#define SOC_SCE_CNTIN_sce_cntin_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sce_cntout : 32;
    } reg;
} SOC_SCE_CNTOUT_UNION;
#endif
#define SOC_SCE_CNTOUT_sce_cntout_START (0)
#define SOC_SCE_CNTOUT_sce_cntout_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sce_src_addr_low : 32;
    } reg;
} SOC_SCE_SRC_ADDR_UNION;
#endif
#define SOC_SCE_SRC_ADDR_sce_src_addr_low_START (0)
#define SOC_SCE_SRC_ADDR_sce_src_addr_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sce_des_addr_low : 32;
    } reg;
} SOC_SCE_DES_ADDR_UNION;
#endif
#define SOC_SCE_DES_ADDR_sce_des_addr_low_START (0)
#define SOC_SCE_DES_ADDR_sce_des_addr_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int plaintext_en : 4;
        unsigned int iv_sel : 4;
        unsigned int sce_src_addr_high : 5;
        unsigned int sce_des_addr_high : 5;
        unsigned int reserved : 14;
    } reg;
} SOC_SCE_IV_BYPASS_UNION;
#endif
#define SOC_SCE_IV_BYPASS_plaintext_en_START (0)
#define SOC_SCE_IV_BYPASS_plaintext_en_END (3)
#define SOC_SCE_IV_BYPASS_iv_sel_START (4)
#define SOC_SCE_IV_BYPASS_iv_sel_END (7)
#define SOC_SCE_IV_BYPASS_sce_src_addr_high_START (8)
#define SOC_SCE_IV_BYPASS_sce_src_addr_high_END (12)
#define SOC_SCE_IV_BYPASS_sce_des_addr_high_START (13)
#define SOC_SCE_IV_BYPASS_sce_des_addr_high_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sce_int_mask_en : 4;
        unsigned int reserved_0 : 12;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_SCE_INT_SCE_MASK_EN_UNION;
#endif
#define SOC_SCE_INT_SCE_MASK_EN_sce_int_mask_en_START (0)
#define SOC_SCE_INT_SCE_MASK_EN_sce_int_mask_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sce_int_mask : 4;
        unsigned int reserved_0 : 12;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_SCE_INT_SCE_MASK_UNION;
#endif
#define SOC_SCE_INT_SCE_MASK_sce_int_mask_START (0)
#define SOC_SCE_INT_SCE_MASK_sce_int_mask_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sce_int : 4;
        unsigned int reserved_0: 12;
        unsigned int reserved_1: 16;
    } reg;
} SOC_SCE_INT_SCE_UNION;
#endif
#define SOC_SCE_INT_SCE_sce_int_START (0)
#define SOC_SCE_INT_SCE_sce_int_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sce_int_clr : 4;
        unsigned int reserved_0 : 12;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_SCE_INT_SCE_CLR_UNION;
#endif
#define SOC_SCE_INT_SCE_CLR_sce_int_clr_START (0)
#define SOC_SCE_INT_SCE_CLR_sce_int_clr_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fifo_rx_wdata : 32;
    } reg;
} SOC_SCE_FIFO_RX_WDATA_UNION;
#endif
#define SOC_SCE_FIFO_RX_WDATA_fifo_rx_wdata_START (0)
#define SOC_SCE_FIFO_RX_WDATA_fifo_rx_wdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fifo_rx_rdata : 32;
    } reg;
} SOC_SCE_FIFO_RX_RDATA_UNION;
#endif
#define SOC_SCE_FIFO_RX_RDATA_fifo_rx_rdata_START (0)
#define SOC_SCE_FIFO_RX_RDATA_fifo_rx_rdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fifo_tx_wdata : 32;
    } reg;
} SOC_SCE_FIFO_TX_WDATA_UNION;
#endif
#define SOC_SCE_FIFO_TX_WDATA_fifo_tx_wdata_START (0)
#define SOC_SCE_FIFO_TX_WDATA_fifo_tx_wdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fifo_tx_rdata : 32;
    } reg;
} SOC_SCE_FIFO_TX_RDATA_UNION;
#endif
#define SOC_SCE_FIFO_TX_RDATA_fifo_tx_rdata_START (0)
#define SOC_SCE_FIFO_TX_RDATA_fifo_tx_rdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dw_axi_gm_prot : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_SCE_PROT_UNION;
#endif
#define SOC_SCE_PROT_dw_axi_gm_prot_START (0)
#define SOC_SCE_PROT_dw_axi_gm_prot_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sce_tp_mux : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_SCE_TP_MUX_UNION;
#endif
#define SOC_SCE_TP_MUX_sce_tp_mux_START (0)
#define SOC_SCE_TP_MUX_sce_tp_mux_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mcache_wr : 4;
        unsigned int mcache_rd : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_SCE_CACHE_CTRL_UNION;
#endif
#define SOC_SCE_CACHE_CTRL_mcache_wr_START (0)
#define SOC_SCE_CACHE_CTRL_mcache_wr_END (3)
#define SOC_SCE_CACHE_CTRL_mcache_rd_START (4)
#define SOC_SCE_CACHE_CTRL_mcache_rd_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cnt_res_burst : 32;
    } reg;
} SOC_SCE_RX_RES_BURST_UNION;
#endif
#define SOC_SCE_RX_RES_BURST_cnt_res_burst_START (0)
#define SOC_SCE_RX_RES_BURST_cnt_res_burst_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cnt_res_word : 32;
    } reg;
} SOC_SCE_RX_RES_WORD_UNION;
#endif
#define SOC_SCE_RX_RES_WORD_cnt_res_word_START (0)
#define SOC_SCE_RX_RES_WORD_cnt_res_word_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cnt_remain_burst : 32;
    } reg;
} SOC_SCE_TX_REMAIN_BURST_UNION;
#endif
#define SOC_SCE_TX_REMAIN_BURST_cnt_remain_burst_START (0)
#define SOC_SCE_TX_REMAIN_BURST_cnt_remain_burst_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cnt_remain_word : 32;
    } reg;
} SOC_SCE_TX_REMAIN_WORD_UNION;
#endif
#define SOC_SCE_TX_REMAIN_WORD_cnt_remain_word_START (0)
#define SOC_SCE_TX_REMAIN_WORD_cnt_remain_word_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aad_lenth : 32;
    } reg;
} SOC_SCE_AAD_LEN_UNION;
#endif
#define SOC_SCE_AAD_LEN_aad_lenth_START (0)
#define SOC_SCE_AAD_LEN_aad_lenth_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ccm_t_lenth : 5;
        unsigned int reserved_0 : 3;
        unsigned int ccm_q_lenth : 3;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 20;
    } reg;
} SOC_SCE_T_Q_LENTH_UNION;
#endif
#define SOC_SCE_T_Q_LENTH_ccm_t_lenth_START (0)
#define SOC_SCE_T_Q_LENTH_ccm_t_lenth_END (4)
#define SOC_SCE_T_Q_LENTH_ccm_q_lenth_START (8)
#define SOC_SCE_T_Q_LENTH_ccm_q_lenth_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ccm_fail : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SCE_CCM_VER_FAIL_UNION;
#endif
#define SOC_SCE_CCM_VER_FAIL_ccm_fail_START (0)
#define SOC_SCE_CCM_VER_FAIL_ccm_fail_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ccm_fail_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SCE_CCM_VER_FAIL_CLR_UNION;
#endif
#define SOC_SCE_CCM_VER_FAIL_CLR_ccm_fail_clr_START (0)
#define SOC_SCE_CCM_VER_FAIL_CLR_ccm_fail_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aes_key_parity : 32;
    } reg;
} SOC_SCE_AES_KEY_PARITY_UNION;
#endif
#define SOC_SCE_AES_KEY_PARITY_aes_key_parity_START (0)
#define SOC_SCE_AES_KEY_PARITY_aes_key_parity_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aes_key2_parity : 32;
    } reg;
} SOC_SCE_AES_KEY2_PARITY_UNION;
#endif
#define SOC_SCE_AES_KEY2_PARITY_aes_key2_parity_START (0)
#define SOC_SCE_AES_KEY2_PARITY_aes_key2_parity_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int key_reg_lock : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_SCE_KEY_REG_LOCK_UNION;
#endif
#define SOC_SCE_KEY_REG_LOCK_key_reg_lock_START (0)
#define SOC_SCE_KEY_REG_LOCK_key_reg_lock_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gcm_counter0 : 32;
    } reg;
} SOC_SCE_gcm_counter0_UNION;
#endif
#define SOC_SCE_gcm_counter0_gcm_counter0_START (0)
#define SOC_SCE_gcm_counter0_gcm_counter0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ccm_q : 32;
    } reg;
} SOC_SCE_ccm_q_UNION;
#endif
#define SOC_SCE_ccm_q_ccm_q_START (0)
#define SOC_SCE_ccm_q_ccm_q_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ccm_nonce : 32;
    } reg;
} SOC_SCE_ccm_nonce_UNION;
#endif
#define SOC_SCE_ccm_nonce_ccm_nonce_START (0)
#define SOC_SCE_ccm_nonce_ccm_nonce_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tweak_value : 32;
    } reg;
} SOC_SCE_tweak_value_UNION;
#endif
#define SOC_SCE_tweak_value_tweak_value_START (0)
#define SOC_SCE_tweak_value_tweak_value_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int xts_multi_data : 32;
    } reg;
} SOC_SCE_xts_multi_data_UNION;
#endif
#define SOC_SCE_xts_multi_data_xts_multi_data_START (0)
#define SOC_SCE_xts_multi_data_xts_multi_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int previous_ghash_digest : 32;
    } reg;
} SOC_SCE_previous_ghash_digest_UNION;
#endif
#define SOC_SCE_previous_ghash_digest_previous_ghash_digest_START (0)
#define SOC_SCE_previous_ghash_digest_previous_ghash_digest_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aes_tag_out : 32;
    } reg;
} SOC_SCE_aes_tag_out_UNION;
#endif
#define SOC_SCE_aes_tag_out_aes_tag_out_START (0)
#define SOC_SCE_aes_tag_out_aes_tag_out_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ccm_tag_out_4ver : 32;
    } reg;
} SOC_SCE_ccm_tag_out_4ver_UNION;
#endif
#define SOC_SCE_ccm_tag_out_4ver_ccm_tag_out_4ver_START (0)
#define SOC_SCE_ccm_tag_out_4ver_ccm_tag_out_4ver_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AES_KEY1 : 32;
    } reg;
} SOC_SCE_AES_KEY1_UNION;
#endif
#define SOC_SCE_AES_KEY1_AES_KEY1_START (0)
#define SOC_SCE_AES_KEY1_AES_KEY1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aes_key1_mask_value : 32;
    } reg;
} SOC_SCE_AESKEY1_MASK_VALUE_UNION;
#endif
#define SOC_SCE_AESKEY1_MASK_VALUE_aes_key1_mask_value_START (0)
#define SOC_SCE_AESKEY1_MASK_VALUE_aes_key1_mask_value_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AES_KEY2 : 32;
    } reg;
} SOC_SCE_AES_KEY2_UNION;
#endif
#define SOC_SCE_AES_KEY2_AES_KEY2_START (0)
#define SOC_SCE_AES_KEY2_AES_KEY2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aes_key2_mask_value : 32;
    } reg;
} SOC_SCE_AESKEY2_MASK_VALUE_UNION;
#endif
#define SOC_SCE_AESKEY2_MASK_VALUE_aes_key2_mask_value_START (0)
#define SOC_SCE_AESKEY2_MASK_VALUE_aes_key2_mask_value_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
