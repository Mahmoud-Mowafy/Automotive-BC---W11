/*
 * dio.c
 *
 * Created: 4/4/2023 1:19:06 PM
 *  Author: Mahmoud Mowafey
 */ 

// including .h
// all global variables
// function definitions

#include "dio.h"

EN_dioError_t Dio_init(uint8_t pinNumber, uint8_t portNumber, uint8_t pinDirection)
{
	if( pinNumber >= PORTWIDTH )
		return WRONG_PIN;
	switch(portNumber)
	{
		case 'A':
		if(pinDirection == INPUT)
		{
			CLEARE_BIT(DDRA, pinNumber);
		}
		else if(pinDirection == OUTPUT)
		{
			SET_BIT(DDRA, pinNumber);
		}
		else
			return WRONG_DIR;
		break;
		
		case 'B':
		if(pinDirection == INPUT)
		{
			CLEARE_BIT(DDRB, pinNumber);
		}
		else if(pinDirection == OUTPUT)
		{
			SET_BIT(DDRB, pinNumber);
		}
		else
			return WRONG_DIR;
		break;
		
		case 'C':
		if(pinDirection == INPUT)
		{
			CLEARE_BIT(DDRC, pinNumber);
		}
		else if(pinDirection == OUTPUT)
		{
			SET_BIT(DDRC, pinNumber);
		}
		else
			return WRONG_DIR;
		break;
		
		case 'D':
		if(pinDirection == INPUT)
		{
			CLEARE_BIT(DDRD, pinNumber);
		}
		else if(pinDirection == OUTPUT)
		{
			SET_BIT(DDRD, pinNumber);
		}
		else
			return WRONG_DIR;
		break;
		
		default:
			return WRONG_PORT;
	}
	return DIO_OK;
}

EN_dioError_t Dio_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value)
{
	if( pinNumber >= PORTWIDTH )
		return WRONG_PIN;
	switch(portNumber)
	{
		case 'A':
            if( value == LOW)
			{
				CLEARE_BIT(PORTA, pinNumber); // write 0 
			}
			else if( value == HIGH)
			{
				SET_BIT(PORTA, pinNumber); // write 1 
			}
			else 
				return WRONG_VAL;
		break;
		
		case 'B':
            if( value == LOW)
            {
	            CLEARE_BIT(PORTB, pinNumber); // write 0 
            }
            else if( value == HIGH)
            {
	            SET_BIT(PORTB, pinNumber); // write 1 
            }
            else
				return WRONG_VAL;
		break;
		
		case 'C':
            if( value == LOW)
            {
	            CLEARE_BIT(PORTC, pinNumber); // write 0 
            }
            else if( value == HIGH)
            {
	            SET_BIT(PORTC, pinNumber); // write 1 
            }
            else
				return WRONG_VAL;
		break;
		
		case 'D':
            if( value == LOW)
            {
	            CLEARE_BIT(PORTD, pinNumber); // write 0  
            }
            else if( value == HIGH)
            {
	            SET_BIT(PORTD, pinNumber); // write 1  
            }
            else
				return WRONG_VAL;
		break;
		
		default:
			return WRONG_PORT;
	}
	return WRITE_OK;	
}

EN_dioError_t Dio_toggle(uint8_t pinNumber, uint8_t portNumber)
{
	if( pinNumber >= PORTWIDTH )
		return WRONG_PIN;
	switch(portNumber)
	{
		case 'A':
			TOGGLE_BIT( PORTA, pinNumber);
		break;
		
		case 'B':
			TOGGLE_BIT( PORTB, pinNumber);
		break;
		
		case 'C':
			TOGGLE_BIT( PORTC, pinNumber);
		break;
		
		case 'D':
			TOGGLE_BIT( PORTD, pinNumber);
		break;
		
		default:
			return WRONG_PORT;
	}
	return TOGGLE_OK;	
}

EN_dioError_t Dio_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value)
{
	if( pinNumber >= PORTWIDTH )
		return WRONG_PIN;
	switch(portNumber)
	{
		case 'A' :
			*value = IS_SET( PINA, pinNumber);
		break;
		
		case 'B':
			*value = IS_SET( PINB, pinNumber);
		break;
		
		case 'C':
			*value = IS_SET( PINC, pinNumber);
		break;
		
		case 'D':
			*value = IS_SET( PIND, pinNumber);
		break;
		
		default:
			return WRONG_PORT;
	}
	return READ_OK;	
}

