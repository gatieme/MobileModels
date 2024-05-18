#ifndef _DRIVER_BRIGE_H_
#define _DRIVER_BRIGE_H_
#include "../devkit/lcdkit/lcdkit3.0/kernel/common/include/lcd_kit_core.h"
#include "../devkit/tpkit/hostprocessing/tp_lcd_kit_core.h"

struct ud_fp_lcd_ops {
        void (*ud_fp_on_hbm_completed)(void);
};

#endif