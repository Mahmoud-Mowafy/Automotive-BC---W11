/*
 * timer.c
 *
 * Created: 4/6/2023 10:15:09 PM
 *  Author: Mahmoud
 */ 
#include "timer.h"
/*Counts to reach one second without prescaler*/
uint32_t OVFs = 0;
uint8_t timer_Initial = 0;
void timer0_init(void)
{
	SREG |=(1<<7);                              //Enable the global interrupt enable bit.
	/*initial value for the timer/counter register.*/
	/* select the normal mode for the timer, timer is not start yet.*/
	TCCR0 &= ~(1<<WGM00);
	TCCR0 &= ~(1<<WGM01); 
	/*must be set for the non_PWM mode*/
	TCCR0 |= (1<<FOC0);
	/* Enable the interrupt for timer0 overflow.*/
	TIMSK |=(1<<TOIE0);
}


void timer_delay(double interval)
{
	TCCR0 =0x00;
	double maxDelay = 0.032768;
	double delay = ( interval /1000.0f);
	if( (delay < maxDelay) == TRUE )
	{
		TCNT0 = (uint8_t) (  ( maxDelay - delay ) / 0.000128f );
	}
	else if(  (delay  ==  maxDelay) == TRUE )
	{
		TCNT0 = 0x00;
	}
	else
	{
		OVFs = ceil( delay / maxDelay );
		TCNT0 = (uint8_t) ( MAX_COUNTS - ( ( delay / 0.000128f ) / OVFs )  );
	}
   /* while (OVFs != g_tick);
    g_tick = 0;*/
	timer_start(1024);
}

void timer_start(uint16_t prescaler)
{
	if(prescaler == 1)
	{
		TCCR0 &=~(1<<CS01);
		TCCR0 &=~(1<<CS02);
		TCCR0 |=(1<<CS00);		
	}
	else if(prescaler == 8)
	{
		TCCR0 &=~(1<<CS00);
		TCCR0 &=~(1<<CS02);
		TCCR0 |=(1<<CS01);		
	}
	else if(prescaler == 64)
	{
		TCCR0 &=~(1<<CS02);
		TCCR0 |=(1<<CS01);
		TCCR0 |=(1<<CS00);		
	}
	else if(prescaler == 256)
	{
		TCCR0 &=~(1<<CS00);
		TCCR0 &=~(1<<CS01);
		TCCR0 |=(1<<CS02);		
	}
	else if(prescaler == 1024)
	{
		TCCR0 &=~(1<<CS01);
		TCCR0 |=(1<<CS00);
		TCCR0 |=(1<<CS02);		
	}
	else
	{
		TCCR0 &=~(1<<CS01);
		TCCR0 &=~(1<<CS02);
		TCCR0 |=(1<<CS00);
	}
}

void timer_stop(void)
{
	/* Stop the timer by clearing the prescaler*/
	TCCR0 &=~(1<<CS00);
	TCCR0 &=~(1<<CS01);
	TCCR0 &=~(1<<CS02);
}
