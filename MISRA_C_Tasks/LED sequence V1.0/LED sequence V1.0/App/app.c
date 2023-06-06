/*
 * app.c
 *
 * Created: 4/7/2023 10:57:30 PM
 *  Author: Mahmoud Mowafey
 */ 
#include "app.h"

void App_init(void)
{
   /*Defines the required led pins---> 4 pins*/
   LEDs_Initialization(LEDS_NUMBER, LEDS_PORT);
   /*Define the required button pin ---> pin 0 in port D*/
   BUT_init(BUTT_PIN, BUTT_PORT);
   /*Initially, all LEDs are OFF*/
   LEDs_off(LEDS_NUMBER, LEDS_PORT);
    
}


void App_start(void)
{
	static uint8_t pressCounter = 0;
	uint8_t Button_Status = ButtonPressed(BUTT_PIN, BUTT_PORT); 
	if( Button_Status == PRESSED )
	{
		pressCounter++;
			 switch(pressCounter)
			 {
				 case 1:
				 LED_on(0, LEDS_PORT);
				 break;
				 case 2:
				 LED_on(1, LEDS_PORT);
				 break;
				 case 3:
				 LED_on(2, LEDS_PORT);
				 break;
				 case 4:
				 LED_on(3, LEDS_PORT);
				 break;
				 
				 case 5:
				 LED_off(0, LEDS_PORT);
				 break;
				 case 6:
				 LED_off(1, LEDS_PORT);
				 break;
				 case 7:
				 LED_off(2, LEDS_PORT);
				 break;
				 case 8:
				 LED_off(3, LEDS_PORT);
				 pressCounter = 0;
				 break;	
				 
				 default:
				 
				 break;	
		}
		 		 
	} 
   
   
}
