/*
 * led.h
 *
 * Created: 4/5/2023 12:05:24 AM
 *  Author: Mahmoud
 */ 


#ifndef LED_H_
#define LED_H_


#include "../../MCAL/DIO/dio.h"

// enum definition for Errors types
typedef enum LED_error {
	LED_OK, LED_WRONG
}EN_ledError_t;

int LED_init(uint8_t ledPin, uint8_t ledPort);
int LED_on(uint8_t ledPin, uint8_t ledPort);
int LED_off(uint8_t ledPin, uint8_t ledPort);
int LED_toggle(uint8_t ledPin, uint8_t ledPort);
int LEDs_Initialization(uint8_t ledsNumber, uint8_t ledPort);
int LEDs_on(uint8_t ledsNumber, uint8_t ledPort);
int LEDs_off(uint8_t ledsNumber, uint8_t ledPort);

#endif /* LED_H_ */