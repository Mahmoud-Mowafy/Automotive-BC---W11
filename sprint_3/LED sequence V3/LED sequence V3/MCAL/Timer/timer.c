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
	TCCR0 &= ~(1<<WGM00) & ~(1<<WGM01);
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
	if( delay < maxDelay )
	{
		TCNT0 = (uint8_t) (  ( maxDelay - delay ) / 0.000128f );
	}
	else if(  delay  ==  maxDelay )
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
	switch(prescaler)
	{
		case 1:
		TCCR0 &=~(1<<CS01) & ~(1<<CS02);
		TCCR0 |=(1<<CS00);
		break;
		case 8 :
		TCCR0 &=~(1<<CS00) & ~(1<<CS02);
		TCCR0 |=(1<<CS01);
		break;
		case 64 :
		TCCR0 &=~(1<<CS02);
		TCCR0 |=(1<<CS01) | (1<<CS00);
		break;
		case 256 :
		TCCR0 &=~(1<<CS00) & ~(1<<CS01);
		TCCR0 |=(1<<CS02);
		break;
		case 1024 :
		TCCR0 &=~(1<<CS01);
		TCCR0 |=(1<<CS00) | (1<<CS02);
		break;
	}
}

void timer_stop(void)
{
	/* Stop the timer by clearing the prescaler*/
	TCCR0 &=~(1<<CS00) & ~(1<<CS01) & ~(1<<CS02);
}

void timer0_init_CTC_mode(uint16_t out_compare , uint16_t prescaler)
{
    /*load the out compare value with the OCR0*/
    OCR0 = out_compare;
    /*initial value for the timer/counter register.*/
    TCNT0 = 0x00;                            
    /* select the CTC mode for the timer0.*/
    TCCR0 &= ~(1<<WGM00);     
    TCCR0 |=(1<<WGM01);
    /*must be set for the non_PWM mode;*/
    TCCR0 |= (1<<FOC0); 
    /*select the required prescaler value*/
    switch(prescaler)
    {
        case 0:
            TCCR0 &=~(1<<CS00) & ~(1<<CS01) & ~(1<<CS02);
            break;
        case 1:
            TCCR0 &=~(1<<CS01) & ~(1<<CS02);
            TCCR0 |=(1<<CS00);
            break;
        case 8 :
            TCCR0 &=~(1<<CS00) & ~(1<<CS02);
            TCCR0 |=(1<<CS01);
            break;
        case 64 :
            TCCR0 &=~(1<<CS02);
            TCCR0 |=(1<<CS01) | (1<<CS00);
            break;
        case 256 :
            TCCR0 &=~(1<<CS00) & ~(1<<CS01);
            TCCR0 |=(1<<CS02);
            break;
        case 1024 :
            TCCR0 &=~(1<<CS01);
            TCCR0 |=(1<<CS00) | (1<<CS02);
            break;
    }
}


void timer0_init_pwm_mode(uint8_t out_compare , uint16_t prescaler)
{
    /* initiate the timer counter register to count from 0*/
    TCNT0 = 0x00;
    /* adjust the waveform generation bits to work in fast_PWM mode*/
    TCCR0 |=(1<<WGM00) |(1<<WGM01);
    /* load the output compare register with the out_compare value */
    OCR0 = out_compare;
    /* define the OC0 pin as output pin */
    OC0_PIN_DIR |=(1<<OC0_PIN);
    /* Set the required prescaler*/
    switch(prescaler)
    {
        case 0:
            TCCR0 &=~(1<<CS00) & ~(1<<CS01) & ~(1<<CS02);
            break;
        case 1:
            TCCR0 &=~(1<<CS01) & ~(1<<CS02);
            TCCR0 |=(1<<CS00);
            break;
        case 8 :
            TCCR0 &=~(1<<CS00) & ~(1<<CS02);
            TCCR0 |=(1<<CS01);
            break;
        case 64 :
            TCCR0 &=~(1<<CS02);
            TCCR0 |=(1<<CS01) | (1<<CS00);
            break;
        case 256 :
            TCCR0 &=~(1<<CS00) & ~(1<<CS01);
            TCCR0 |=(1<<CS02);
            break;
        case 1024 :
            TCCR0 &=~(1<<CS01);
            TCCR0 |=(1<<CS00) | (1<<CS02);
            break; 
    }
}
