#if (defined PMU_CHIP_V600) || (defined CONFIG_PMIC_55V600_PMU) || (defined CONFIG_PMU_CHIP_V600)
#include "pmic_interface_6555v600.h"
#else
#include "pmic_interface_6555v500.h"
#include "pmic_interface_6563v350.h"
#endif
