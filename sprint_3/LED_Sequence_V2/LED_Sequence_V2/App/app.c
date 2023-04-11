/*
 * app.c
 *
 * Created: 4/7/2023 10:57:30 PM
 *  Author: Mahmoud Mowafey
 */ 
#include "app.h"

static  uint8_t pressCounter = 0;
void App_init(void)
{
	//Define the required button pin ---> pin 2 in port D
	BUT_init(BUTT_PIN, BUTT_PORT);
	Dio_write(BUTT_PIN, BUTT_PORT, HIGH);
	//Defines the required led pins---> 4 pins
	LEDs_Initialization(LEDS_NUMBER, LEDS_PORT);
	//Initially, all LEDs are OFF
	LEDs_off(LEDS_NUMBER, LEDS_PORT);
	interrupt_enable();
	extInterrupt_init();	
}

void App_start(void)
{
	while (1)
	{
		switch(pressCounter)
		{
			case 1:
			LED_on(0, PORT_A);
			break;
			case 2:
			LED_on(1, PORT_A);
			break;
			case 3:
			LED_on(2, PORT_A);
			break;
			case 4:
			LED_on(3, PORT_A);
			break;
			
			case 5:
			LED_off(0, PORT_A);
			break;
			case 6:
			LED_off(1, PORT_A);
			break;
			case 7:
			LED_off(2, PORT_A);
			break;
			case 8:
			LED_off(3, PORT_A);
			pressCounter = 0;
			break;
		}
	}
}


ISR( EXT_INT0 )
{
	pressCounter++;
}