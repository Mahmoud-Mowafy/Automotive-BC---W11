/*
 * app.h
 *
 * Created: 4/7/2023 10:57:42 PM
 *  Author: Mahmoud
 */ 


#ifndef APP_H_
#define APP_H_



#include "../HAL/LED/led.h"
#include "../HAL/BUTTON/button.h"
#include "../MCAL/EXTI/EXTI.h"
#include "../MCAL/Timer/timer.h"


#define LEDS_NUMBER   4
#define LEDS_PORT  PORT_A


#define BUTT_PORT  PORT_D
#define BUTT_PIN_0	  2
#define BUTT_PIN_1	  3

typedef struct Blinking
{
	/*uint8_t blinkMode;
	uint8_t leds;*/
	uint16_t onDuration;
	uint16_t offDuration;
	}ST_blinkModeConfig_t;
	
typedef enum{
	APP_OK,
	APP_ERROR
	}EN_appError_t;
EN_appError_t App_init(void);
EN_appError_t App_start(void);

EN_appError_t executeBlinking(void);
void blinkMode(uint8_t BlinkMode);
void ledBlinkingMask( uint8_t portNumber, uint8_t leds, uint16_t on, uint16_t off  );

#endif /* APP_H_ */