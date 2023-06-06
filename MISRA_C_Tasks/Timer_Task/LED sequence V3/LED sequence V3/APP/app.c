/*
 * app.c
 *
 * Created: 4/7/2023 10:57:30 PM
 *  Author: Mahmoud Mowafey
 */ 
#include "app.h"

uint32_t pressCounter = 0;
uint8_t BlinkMode = 0;
extern 	uint32_t OVFs ;
uint32_t g_tick=0  ;
double onTime , offTime, mask;
EN_appError_t App_init(void)
{
	//Define the required button pin ---> pin 2 in port D for Ext_interrupt_0
	BUT_init(BUTT_PIN_0, BUTT_PORT);
	Dio_write(BUTT_PIN_0, BUTT_PORT, HIGH);
	
	//Define the required button pin ---> pin 3 in port D for Ext_interrupt_1
	BUT_init(BUTT_PIN_1, BUTT_PORT);
	Dio_write(BUTT_PIN_1, BUTT_PORT, HIGH);
		
	//Defines the required led pins---> 4 pins
	LEDs_Initialization(LEDS_NUMBER, LEDS_PORT);
	//Initially, all LEDs are OFF
	LEDs_off(LEDS_NUMBER, LEDS_PORT);
	
	//Initializing the used interrupts
	interrupt_enable();
	/*For Presses Counts*/
	extInterrupt_0_init();
	/*For Blink Switching */
	extInterrupt_1_init();
	
	timer0_init();
	return APP_OK;
}

EN_appError_t App_start(void)
{
	executeBlinking();
	return APP_OK;
}

EN_appError_t executeBlinking(void)
{
	switch(pressCounter)
	{
		case 1:
	LED_on(0, PORT_A);
	timer_stop();
	timer_delay(onTime);
	while(  g_tick != OVFs );
	g_tick=0;
	LEDs_off(4, PORT_A);
	timer_stop();
	timer_delay(onTime);
	while(  g_tick != OVFs );
	g_tick=0;	
	break;
		case 2:
		LED_on(0, PORT_A);
		LED_on(1, PORT_A);
		timer_stop();
		timer_delay( onTime);
		while(  g_tick != OVFs );
		g_tick=0;
		LEDs_off(4, PORT_A);
		timer_stop();
		timer_delay( offTime);
		while(  g_tick != OVFs );
		g_tick=0;
		break;
		
		case 3:
		LED_on(0, PORT_A);
		LED_on(1, PORT_A);
		LED_on(2, PORT_A);
		timer_stop();
		timer_delay( onTime);
		while(  g_tick != OVFs );
		g_tick=0;
		LEDs_off(4, PORT_A);
		timer_stop();
		timer_delay( offTime);
		while(  g_tick != OVFs );
		g_tick=0;
		break;
		
		case 4:
		LED_on(0, PORT_A);
		LED_on(1, PORT_A);
		LED_on(2, PORT_A);
		LED_on(3, PORT_A);
		timer_stop();
		timer_delay( onTime);
		while(  g_tick != OVFs );
		g_tick=0;
		LEDs_off(4, PORT_A);
		timer_stop();
		timer_delay( offTime);
		while(  g_tick != OVFs );
		g_tick=0;
		break;

		case 5:
		LED_on(1, PORT_A);
		LED_on(2, PORT_A);
		LED_on(3, PORT_A);
		timer_stop();
		timer_delay( onTime);
		while(  g_tick != OVFs );
		g_tick=0;
		LEDs_off(4, PORT_A);
		timer_stop();
		timer_delay( offTime);
		while(  g_tick != OVFs );
		g_tick=0;
		break;
		
		case 6:
		LED_on(2, PORT_A);
		LED_on(3, PORT_A);
		timer_stop();
		timer_delay( onTime);
		while(  g_tick != OVFs );
		g_tick=0;
		LEDs_off(4, PORT_A);
		timer_stop();
		timer_delay( offTime);
		while(  g_tick != OVFs );
		g_tick=0;
		break;
		
		case 7:
		LED_on(3, PORT_A);
		timer_stop();
		timer_delay( onTime);
		while(  g_tick != OVFs );
		g_tick=0;
		LEDs_off(4, PORT_A);
		timer_stop();
		timer_delay(offTime);
		while(  g_tick != OVFs );
		g_tick=0;
		break;
		
		case 8:
		LEDs_off(4, PORT_A);
		timer_stop();
		timer_delay( offTime);
		while(  g_tick != OVFs );
		g_tick=0;
		pressCounter = 0;
		break;
	}	
	return APP_OK;
}

ISR( EXT_INT0 )
{
	BlinkMode++;
	switch(BlinkMode)
	{
		case 1:
		onTime = 100.0f;
		offTime = 900.0f;
		break;
		case 2:
		onTime = 200.0f;
		offTime = 800.0f;
		break;
		case 3:
		onTime = 300.0f;
		offTime = 700.0f;
		break;
		case 4:
		onTime = 500;
		offTime = 500;
		break;
		case 5:
		onTime = 800;
		offTime = 200;
		break;
		default:
		BlinkMode=0;
		break;
	}
}

ISR( EXT_INT1 )
{
	pressCounter++;
}
ISR( TIMER0_OVF )
{
	g_tick++;
}