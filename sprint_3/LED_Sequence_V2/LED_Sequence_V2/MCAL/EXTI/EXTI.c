/*
 * EXTI.c
 *
 * Created: 4/8/2023 6:52:58 AM
 *  Author: Mahmoud Mowafey
 */ 

#include "EXTI.h"


void interrupt_enable(void)
{
	SET_BIT(SREG, GENERAL_INT_ENABLE);
}


void extInterrupt_init(void)
{
 	SET_BIT(SFIOR, PUD);
 	SET_BIT(GICR, EXTERNAL_INTERRUPT_REQUEST_0);
 	CLEARE_BIT(MCUCR, INTERRUPT_SENSE_CONTROL_0_BIT_0);
 	SET_BIT(MCUCR, INTERRUPT_SENSE_CONTROL_0_BIT_1);
}
