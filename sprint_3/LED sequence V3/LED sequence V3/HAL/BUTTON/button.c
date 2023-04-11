/*
 * button.c
 *
 * Created: 4/5/2023 6:22:44 AM
 *  Author: Mahmoud
 */ 


// button configuration ( pin, port, pullup, depouncing,..)
#include "button.h"

EN_butError_t BUT_init(uint8_t butPin, uint8_t butPort)
{
  
	uint8_t butError = Dio_init( butPin, butPort, INPUT );
	if( butError == DIO_OK )
	{
  		return BUT_OK;
	}
	return BUT_WRONG;
}


/*
EN_butStatus_t BUT_status(uint8_t butPin, uint8_t butPort)
{
  uint8_t butStatus = 0, debounced =0;
  uint32_t ButtonPressed = 0;
  uint8_t flag = 0;
  Dio_read(butPin, butPort, &butStatus);
  if( butStatus == 0 )
  {
    debounced++;
  }
  else
  {
    debounced = 0;
    flag = 0;
    ButtonPressed = 0;
  }
  if(debounced >= 500)
  {
    ButtonPressed = 1;
  }
  if( butStatus == 0  && flag == 0)
  {
    flag = 1;
  }

  return flag;
}*/

/*
EN_butStatus_t ButtonPress(uint8_t butPin, uint8_t butPort)
{
  static uint32_t buttonState = 0;
  static uint8_t buttonPressEnabled = 1;
	uint8_t status;
  Dio_read(butPin, butPort, &status);
#ifdef DOWN_CONFIG

  if( status == 1 )
  {
    if(buttonState < BUTTON_DEBOUNCE_CHECKS)
    {
      buttonState++;
    }
    else if(buttonPressEnabled)
    {
      buttonPressEnabled = 0;
      return PRESSED;
    }
  }
  else if(buttonState > 0 )
  {
    buttonState--;
  }
  else
  {
    buttonPressEnabled = 1;
  }

#else

  if( status == 0 )
  {
    if(buttonState < BUTTON_DEBOUNCE_CHECKS)
    {
      buttonState++;
    }
    else if(buttonPressEnabled)
    {
      buttonPressEnabled = 0;
      return 1;
    }
  }
  else if(buttonState > 0 )
  {
    buttonState--;
  }
  else
  {
    buttonPressEnabled = 1;
  }


#endif


  return NOT_PRESSED;
}

*/

EN_butStatus_t ButtonPressed(uint8_t butPin, uint8_t butPort)
{
	uint8_t ButtState = 0;
	Dio_read(butPin, butPort, &ButtState);
	if(ButtState == 1 )
	{
		//_delay_ms(90);
		Dio_read(butPin, butPort, &ButtState);
		if( ButtState == 1 )
		{
		//	_delay_ms(90);
			return PRESSED;
		}
	}
	return NOT_PRESSED;
}

