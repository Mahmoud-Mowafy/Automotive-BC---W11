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
    if( portNumber == 'A' )
	{
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
	}
	else if( portNumber == 'B' )
	{
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
	}
	else if( portNumber == 'C' )
	{
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
	}
	else if( portNumber == 'D' )
	{
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
	}
	else 
	{
		retVal = (int) WRONG_PORT;
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

			if(portNumber == 'A') 
			{
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
			}
		
			else if(portNumber == 'B')
			{
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
			}
		
			else if(portNumber == 'C')
			{
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
			}
		
			else if(portNumber == 'D')
			{
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
			}
			else
			{
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
		if(portNumber == 'A')
		{
			TOGGLE_BIT( PORTA, pinNumber);
		}
		else if(portNumber == 'B')
		{
			TOGGLE_BIT( PORTB, pinNumber);
		}
		else if(portNumber == 'C')
		{
			TOGGLE_BIT( PORTC, pinNumber);
		}
		else if(portNumber == 'D')
		{
			TOGGLE_BIT( PORTD, pinNumber);
		}
		else
		{
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
		if(portNumber == 'A')
		{
			*value = IS_SET( PINA, pinNumber);
		}
		else if(portNumber == 'B')
		{
			*value = IS_SET( PINB, pinNumber);
		}
		else if(portNumber == 'C')
		{
			*value = IS_SET( PINC, pinNumber);
		}
		else if(portNumber == 'D')
		{
			*value = IS_SET( PIND, pinNumber);
		}
		else
		{
			retVal = (int) WRONG_PORT;
		}
	}	
	return retVal;
}

