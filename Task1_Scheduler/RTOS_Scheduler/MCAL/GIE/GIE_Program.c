
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "GIE_Interface.h"
#include "GIE_Private.h"
#include "GIE_Config.h"

void GIE_voidEnableInterruptGlobal (void)
{
     SET_BIT(SREG_REG , 7);
}

void GIE_voidDisableInterruptGlobal (void)
{
	 CLR_BIT(SREG_REG , 7);
}
