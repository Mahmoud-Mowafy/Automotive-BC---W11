/*
 * Register_file.h
 *
 * Created: 4/4/2023 12:25:03 AM
 *  Author: Mahmoud
 */ 

//#include <avr/interrupt.h>

#ifndef REGISTER_FILE_H_
#define REGISTER_FILE_H_

#include "types.h"

#define TIMER0_OVF __vector_11
#define EXT_INT0 __vector_1

#define ISR(INT_VECT)	void INT_VECT(void) __attribute__((signal,used));\
void INT_VECT(void)


//void __vector_2( void )		__attribute__((signal));

#define SFIOR   *((volatile uint8_t*)0x50)
/*******************  PORTA Registers  ************************/
#define PORTA  *((volatile uint8_t*)0x3B)   // 8-bit register 
#define DDRA   *((volatile uint8_t*)0x3A)
#define PINA   *((volatile uint8_t*)0x39)

/*******************  PORTB Registers  ************************/
#define PORTB  *((volatile uint8_t*)0x38)  
#define DDRB   *((volatile uint8_t*)0x37)
#define PINB   *((volatile uint8_t*)0x36)

/*******************  PORTC Registers  ************************/
#define PORTC  *((volatile uint8_t*)0x35)   
#define DDRC   *((volatile uint8_t*)0x34)
#define PINC   *((volatile uint8_t*)0x33)

/*******************  PORTD Registers  ************************/
#define PORTD  *((volatile uint8_t*)0x32)   
#define DDRD   *((volatile uint8_t*)0x31)
#define PIND   *((volatile uint8_t*)0x30)

/*******************  Status & Stack Pointer Registers  ************************/
#define SREG   *((volatile uint8_t*)0x5F)
#define SPH    *((volatile uint8_t*)0x5E)
#define SPL    *((volatile uint8_t*)0x5D)

/*******************  Timer Registers  ************************/
#define OCR0   *((volatile uint8_t*)0x5C)
#define GICR   *((volatile uint8_t*)0x5B)
#define GIFR   *((volatile uint8_t*)0x5A)
#define TIMSK  *((volatile uint8_t*)0x59)
#define TIFR   *((volatile uint8_t*)0x58)
#define SPMCR  *((volatile uint8_t*)0x57)
#define TWCR   *((volatile uint8_t*)0x56)
#define MCUCR  *((volatile uint8_t*)0x55)
#define MCUCSR *((volatile uint8_t*)0x54)
#define TCCR0  *((volatile uint8_t*)0x53)
#define TCNT0  *((volatile uint8_t*)0x52)
#define TCCR1A *((volatile uint8_t*)0x4F)
#define TCCR1B *((volatile uint8_t*)0x4E)
#define TCNT1H *((volatile uint8_t*)0x4D)
#define TCNT1L *((volatile uint8_t*)0x4C)
#define OCR1AH *((volatile uint8_t*)0x4B)
#define OCR1AL *((volatile uint8_t*)0x4A)
#define OCR1BH *((volatile uint8_t*)0x49)
#define OCR1BL *((volatile uint8_t*)0x48)
#define ICR1H  *((volatile uint8_t*)0x47)
#define ICR1L  *((volatile uint8_t*)0x46)
#define TCCR2  *((volatile uint8_t*)0x45)
#define TCNT2  *((volatile uint8_t*)0x44)
#define OCR2   *((volatile uint8_t*)0x43)
#define ASSR   *((volatile uint8_t*)0x42)



#endif /* REGISTER_FILE_H_ */