/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: ddic ram interface definitions.
 * Author: mapeng 00833051
 * Create: 2023-04-28
 */

#ifndef __LCD_KIT_DDIC_RAM_H__
#define __LCD_KIT_DDIC_RAM_H__

int32_t lcd_kit_ddic_ram_write_bin(uint32_t head_addr, uint32_t write_len);
int32_t lcd_kit_ddic_ram_read_bin(uint32_t head_addr, uint32_t read_len);
#endif