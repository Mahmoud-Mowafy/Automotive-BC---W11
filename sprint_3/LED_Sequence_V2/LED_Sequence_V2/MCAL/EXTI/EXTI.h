/*
 * EXTI.h
 *
 * Created: 4/8/2023 6:53:12 AM
 *  Author: Mahmoud Mowafey
 */ 


#ifndef EXTI_H_
#define EXTI_H_

#include "../../Utilities/Register_file.h"
#include "../../Utilities/types.h"
#include "../DIO/dio.h"
#include "../../HAL/BUTTON/button.h"


#define GENERAL_INT_ENABLE				     7         

#define EXTERNAL_INTERRUPT_REQUEST_1         7
#define EXTERNAL_INTERRUPT_REQUEST_0         6

#define INTERRUPT_SENSE_CONTROL_0_BIT_1      1

#define INTERRUPT_SENSE_CONTROL_0_BIT_0      0

#define INTERRUPT_SENSE_CONTROL_1_BIT_1      3

#define INTERRUPT_SENSE_CONTROL_1_BIT_0      2

void interrupt_enable(void);


void extInterrupt_init(void);

#endif /* EXTI_H_ */