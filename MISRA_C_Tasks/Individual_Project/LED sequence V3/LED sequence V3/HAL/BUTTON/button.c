/*
 * button.c
 *
 * Created: 4/5/2023 6:22:44 AM
 *  Author: Mahmoud
 */ 


// button configuration ( pin, port, pullup, depouncing,..)
#include "button.h"

int BUT_init(uint8_t butPin, uint8_t butPort)
{
  
	uint8_t butError = Dio_init( butPin, butPort, INPUT );
	int retVal = (int) BUT_WRONG;
	if( butError == DIO_OK )
	{
  		retVal = (int) BUT_OK;
	}
	else
	{
		retVal = (int) BUT_WRONG;
	}
	return retVal;
}




int ButtonPressed(uint8_t butPin, uint8_t butPort)
{
	uint8_t ButtState = 0;
	int retVal = (int) NOT_PRESSED;
	Dio_read(butPin, butPort, &ButtState);
	if(ButtState == 1 )
	{
		//_delay_ms(90);
		Dio_read(butPin, butPort, &ButtState);
		if( ButtState == 1 )
		{
		//	_delay_ms(90);
			retVal = (int) PRESSED;
		}
	}
	else
	{
		retVal = (int) NOT_PRESSED;
	}
	return retVal;
}

