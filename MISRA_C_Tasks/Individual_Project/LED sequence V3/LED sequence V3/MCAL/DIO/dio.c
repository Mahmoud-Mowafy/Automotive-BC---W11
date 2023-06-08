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

int Dio_init(uint8_t pinNumber, uint8_t portNumber, uint8_t pinDirection)
{
	int retVal = (int) DIO_OK;
	if( ( pinNumber >= PORTWIDTH ) )
	{
		retVal = (int)  WRONG_PIN;
	}
	else
	{
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
				retVal = (int)  WRONG_DIR;
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
				retVal = (int)  WRONG_DIR;
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
				retVal = (int)  WRONG_DIR;
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
				retVal = (int)  WRONG_DIR;
			break;
		
			default:
				retVal = (int) WRONG_PORT;
		}
		
	}
	return retVal;
}

int Dio_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value)
{
	int retVal = (int) WRITE_OK;
	if( ( pinNumber >= PORTWIDTH )  )
	{
		retVal = (int) WRONG_PIN;
	}
	else
	{
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
					retVal = (int) WRONG_VAL;
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
					retVal = (int) WRONG_VAL;
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
					retVal = (int) WRONG_VAL;
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
					retVal = (int) WRONG_VAL;
			break;
		
			default:
				retVal = (int) WRONG_PORT;
		}
		
	}
	return retVal;
}

int Dio_toggle(uint8_t pinNumber, uint8_t portNumber)
{
	int retVal = (int) TOGGLE_OK;
	if( ( pinNumber >= PORTWIDTH )  )
	{
		retVal = (int) WRONG_PIN;
	}
	else
	{
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
				retVal = (int) WRONG_PORT;
		}
			
	}
	return retVal;
}

int Dio_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value)
{
	int retVal = (int) READ_OK;
	if( ( pinNumber >= PORTWIDTH )  )
	{
		retVal = (int) WRONG_PIN;
	}
	else
	{
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
				retVal = (int) WRONG_PORT;
		}
		
	}
	return retVal;
}

