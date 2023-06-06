/*
 * button.h
 *
 * Created: 4/5/2023 6:22:56 AM
 *  Author: Mahmoud
 */ 



#ifndef BUTTON_H_
#define BUTTON_H_

#define F_CPU					1000000U
#include <util/delay.h>

#include "../../MCAL/DIO/dio.h"

#define DOWN_CONFIG              //Configure the button to be pressed when change pin level from low to high using the pull-down resistor

#define BUTTON_DEBOUNCE_CHECKS		100


// enum definition for Errors types
typedef enum but_error {
  BUT_OK, BUT_WRONG
}EN_butError_t;

// enum definition for Button Status
typedef enum but_status {
  PRESSED,
  NOT_PRESSED
}EN_butStatus_t;



EN_butError_t BUT_init(uint8_t butPin, uint8_t butPort);
EN_butStatus_t BUT_status(uint8_t butPin, uint8_t butPort);
EN_butStatus_t ButtonPress(uint8_t butPin, uint8_t butPort);

EN_butStatus_t ButtonPressed(uint8_t butPin, uint8_t butPort);

#endif /* BUTTON_H_ */