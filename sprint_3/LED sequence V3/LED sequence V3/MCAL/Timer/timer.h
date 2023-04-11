/*
 * timer.h
 *
 * Created: 4/6/2023 10:15:34 PM
 *  Author: Mahmoud
 */ 


#ifndef TIMER_H_
#define TIMER_H_


#include "../../Utilities/Register_file.h"
#include "../../Utilities/types.h"

#include<math.h>

#ifndef F_CPU
#define F_CPU 8000000UL // telling controller crystal frequency (16 MHz AVR ATMega328P)
#endif

//SFIOR – Special Function IO Register, pin definitions
#define PSR10   0
#define PSR2    1
#define PUD     2
//#define –       3
#define ACME    4
#define ADTS0   5
#define ADTS1   6
#define ADTS2   7

//TCCR0- Timer/Counter Control Register, pin definitions
#define CS00     0
#define CS01     1
#define CS02     2
#define WGM01    3
#define COM00    4
#define COM01    5
#define WGM00    6
#define FOC0     7

// TIMSK - Timer/Counter Interrupt Mask Registe, pin definitions
#define TOIE0     0
#define OCIE0     1
#define TOIE1     2
#define OCIE1B    3
#define OCIE1A    4
#define TICIE1    5
#define TOIE2     6
#define OCIE2     7

// TIFR – Timer/Counter Interrupt Flag Register, pin definitions
#define TOV0     0
#define OCF0     1
#define TOV1     2
#define OCF1B    3
#define OCF1A    4
#define ICF1     5
#define TOV2     6
#define OCF2     7

//TCCR2 - Timer/Counter Control Register, pin definitions
#define CS20     0
#define CS21     1
#define CS22     2
#define WGM21    3
#define COM20    4
#define COM21    5
#define WGM20    6
#define FOC2     7

//TCCR1A – Timer/Counter1 Control Register A, pin definitions
#define WGM10     0
#define WGM11     1
#define FOC1B     2
#define FOC1A     3
#define COM1B0    4
#define COM1B1    5
#define COM1A0    6
#define COM1A1     7
//TCCR1B – Timer/Counter1 Control Register B, pin definitions
#define CS10     0
#define CS11     1
#define CS12     2
#define WGM12    3
#define WGM13    4
//#define –     5
#define ICES1    6
#define CNC1     7


#define OC0_PIN_DIR                         DDRB
#define OC0_PIN                              3

#define NEEDED_OVERFLOWS       2000
#define MAX_DELAY       255
#define MAX_COUNTS      255
#define TICK_TIME      (0.000128)




void timer0_init(void);
void timer_delay(double interval);
void timer_start(uint16_t prescaler);
void timer_stop(void);




#endif /* TIMER_H_ */