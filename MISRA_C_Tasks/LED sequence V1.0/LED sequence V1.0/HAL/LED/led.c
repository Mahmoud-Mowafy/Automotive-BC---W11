/*
 * led.c
 *
 * Created: 4/5/2023 12:05:11 AM
 *  Author: Mahmoud Mowafey
 */ 

// including .h
#include "led.h"

// all global variables


// function definitions
EN_ledError_t LED_init(uint8_t ledPin, uint8_t ledPort)
{
	uint8_t LedError = Dio_init( ledPin, ledPort, OUTPUT );
	if( LedError == DIO_OK )
	{
		return LED_OK;
	}
	return LED_WRONG;
}

EN_ledError_t LEDs_Initialization(uint8_t ledsNumber, uint8_t ledPort)
{
  uint8_t loopCounter =0;
  int8_t LedError;
  for(loopCounter=0; loopCounter < ledsNumber; loopCounter++)
  {
    LedError = LED_init(loopCounter, ledPort);
    if( LedError == LED_WRONG )
    {
      return LED_WRONG;
    }
  }
  return LED_OK;
}


EN_ledError_t LEDs_on(uint8_t ledsNumber, uint8_t ledPort)
{
  uint8_t loopCounter =0;
  int8_t LedError;
  for(loopCounter=0; loopCounter < ledsNumber; loopCounter++)
  {
    LedError = LED_on(loopCounter, ledPort);
    if( LedError == LED_WRONG )
    {
      return LED_WRONG;
    }
  }
  return LED_OK;
}

EN_ledError_t LEDs_off(uint8_t ledsNumber, uint8_t ledPort)
{
  uint8_t loopCounter =0;
  int8_t LedError;
  for(loopCounter=0; loopCounter < ledsNumber; loopCounter++)
  {
    LedError = LED_off(loopCounter, ledPort);
    if( LedError == LED_WRONG )
    {
      return LED_WRONG;
    }
  }
  return LED_OK;
}

EN_ledError_t LED_on(uint8_t ledPin, uint8_t ledPort)
{
	uint8_t LedError = Dio_write( ledPin, ledPort, HIGH );
	if( LedError == READ_OK )
	{
		return LED_OK;
	}
	return LED_WRONG;	
}

EN_ledError_t LED_off(uint8_t ledPin, uint8_t ledPort)
{
	uint8_t LedError = Dio_write( ledPin, ledPort, LOW );
	if( LedError == READ_OK )
	{
		return LED_OK;
	}
	return LED_WRONG;	
}

EN_ledError_t LED_toggle(uint8_t ledPin, uint8_t ledPort)
{
	uint8_t LedError = Dio_toggle( ledPin, ledPort);
	if( LedError == READ_OK )
	{
		return LED_OK;
	}
	return LED_WRONG;	
}