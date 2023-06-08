/*
 * led.c
 *
 * Created: 4/5/2023 12:05:11 AM
 *  Author: Mahmoud
 */ 

// including .h
#include "led.h"

// all global variables


// function definitions
int LED_init(uint8_t ledPin, uint8_t ledPort)
{
	uint8_t LedError = Dio_init( ledPin, ledPort, OUTPUT );
	int retVal = (int) LED_WRONG;
	if( LedError == DIO_OK )
	{
		retVal = (int) LED_OK;
	}
	return retVal;
}

int LEDs_Initialization(uint8_t ledsNumber, uint8_t ledPort)
{
  uint8_t loopCounter =0;
  int8_t LedError;
  int retVal = (int) LED_OK;
  for(loopCounter=0; loopCounter < ledsNumber; loopCounter++)
  {
    LedError = LED_init(loopCounter, ledPort);
    if( LedError == LED_WRONG )
    {
      retVal = (int) LED_WRONG;
    }
  }
  return retVal;
}


int LEDs_on(uint8_t ledsNumber, uint8_t ledPort)
{
  uint8_t loopCounter =0;
  int8_t LedError;
  int retVal = (int) LED_OK;
  for(loopCounter=0; loopCounter < ledsNumber; loopCounter++)
  {
    LedError = LED_on(loopCounter, ledPort);
    if( LedError == LED_WRONG )
    {
      retVal = (int) LED_WRONG;
    }
  }
  return retVal;
}

int LEDs_off(uint8_t ledsNumber, uint8_t ledPort)
{
  uint8_t loopCounter =0;
  int8_t LedError;
  int retVal = (int) LED_OK;
  for(loopCounter=0; loopCounter < ledsNumber; loopCounter++)
  {
    LedError = LED_off(loopCounter, ledPort);
    if( LedError == LED_WRONG )
    {
      retVal = (int) LED_WRONG;
    }
  }
  return retVal;

}

int LEDs_toggle(uint8_t pins, uint8_t portNumber)
{
  uint8_t loopCounter =0;
  int8_t LedError;
  int retVal = (int) LED_OK;
  for(loopCounter=0; loopCounter < pins; loopCounter++)
  {
	  LedError = LED_toggle(loopCounter, portNumber);
	  if( LedError == LED_WRONG )
	  {
		  retVal = (int) LED_WRONG;
	  }
  }
  return retVal;	
	
}



int LED_on(uint8_t ledPin, uint8_t ledPort)
{
	uint8_t LedError = Dio_write( ledPin, ledPort, HIGH );
	int retVal = (int) LED_WRONG;
	if( LedError == WRITE_OK )
	{
		retVal = (int) LED_OK;
	}
	else
	{
		retVal = (int) LED_WRONG;
	}
	return retVal;
}

int LED_off(uint8_t ledPin, uint8_t ledPort)
{
	uint8_t LedError = Dio_write( ledPin, ledPort, LOW );
	int retVal = (int) LED_WRONG;
	if( LedError == WRITE_OK )
	{
		retVal = (int) LED_OK;
	}
	else
	{
		retVal = (int) LED_WRONG;
	}
	return retVal;
}

int LED_toggle(uint8_t ledPin, uint8_t ledPort)
{
	uint8_t LedError = Dio_toggle( ledPin, ledPort);
	int retVal = (int) LED_WRONG;
	if( LedError == WRITE_OK )
	{
		retVal = (int) LED_OK;
	}
	else
	{
		retVal = (int) LED_WRONG;
	}
	return retVal;
}

int LEDs_bitMask(uint8_t portNumber, uint8_t mask)
{
	
	uint8_t LedError = Dio_writeBits( portNumber,  mask);
	int retVal = (int) LED_WRONG;
	if( LedError == WRITE_OK )
	{
		retVal = (int) LED_OK;
	}
	else
	{
		retVal = (int) LED_WRONG;
	}
	return retVal;
}