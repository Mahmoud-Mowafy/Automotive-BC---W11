/*
 * app.h
 *
 * Created: 4/7/2023 10:57:42 PM
 *  Author: Mahmoud
 */ 


#ifndef APP_H_
#define APP_H_



#include "../HAL/LED/led.h"
#include "../HAL/BUTTON/button.h"
#include "../MCAL/EXTI/EXTI.h"

#define LEDS_NUMBER   4
#define LEDS_PORT  PORT_A


#define BUTT_PORT  PORT_D
#define BUTT_PIN	  2

void App_init(void);
void App_start(void);

#endif /* APP_H_ */