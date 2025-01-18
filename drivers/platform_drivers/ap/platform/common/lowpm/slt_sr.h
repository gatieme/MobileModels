#ifndef __H_SLT_SR_H__
#define __H_SLT_SR_H__ 
#include <soc_sctrl_interface.h>
#define SLT_SR_FLAG 0x7D
#define SLT_SR_SYS_FLAG (0xAE << 8)
#define SLT_SR_STATE_SHIFT 28
#define SLT_SR_STATE_MASK 0xF0000000
#define SLT_SR_STATE_STANDBY 0x10000000
#define SLT_SR_STATE_DEEPSLEEP 0x20000000
#define SLT_SR_STATE_LIGHTSLEEP 0x30000000
#define SLT_SR_STATE_DOZE1 0x40000000
#define SLT_SR_STATE_DOZE2 0x50000000
#define SLT_SR_STATE_PARA_MAX 4
#if defined(UEFI_SOCBENCH_VERSION)
#include <Library/IoLib.h>
#define SLT_SR_BASE_ADDR SOC_SCTRL_SCBAKDATA23_ADDR(SOC_ACPU_SCTRL_BASE_ADDR)
#define REG32_READ(addr) MmioRead32(addr)
#define REG32_WRITE(addr,val) MmioWrite32(addr, val)
#elif defined(__LPMCU__)
#define SLT_SR_BASE_ADDR SOC_SCTRL_SCBAKDATA23_ADDR(SOC_LPMCU_SCTRL_BASE_ADDR)
#define REG32_READ(addr) readl(addr)
#define REG32_WRITE(addr,val) writel(val, addr)
#else
#error "slt sr not support this image!"
#endif
#define SLT_TST_SR_FLG(x) ((REG32_READ(SLT_SR_BASE_ADDR) & 0xFF) == (x))
#define SLT_TST_SR_SYS_FLG(x) ((REG32_READ(SLT_SR_BASE_ADDR) & 0xFF00) == (x))
#define SLT_TST_SR_STATE(x) ((REG32_READ(SLT_SR_BASE_ADDR) & SLT_SR_STATE_MASK) == (x))
#define SLT_GET_SUSPENDFLG() (REG32_READ(SLT_SR_BASE_ADDR) & SLT_SR_STATE_MASK)
#define SLT_SET_SUSPENDFLG(x) do {REG32_WRITE(SLT_SR_BASE_ADDR, (REG32_READ(SLT_SR_BASE_ADDR) | (x)));} while (0)
#define SLT_CLR_SUSPENDFLG(x) do {REG32_WRITE(SLT_SR_BASE_ADDR, (REG32_READ(SLT_SR_BASE_ADDR) & (~(x))));} while (0)
#endif
