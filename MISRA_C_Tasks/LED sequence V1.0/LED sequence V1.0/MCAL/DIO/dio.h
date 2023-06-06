/*
 * dio.h
 *
 * Created: 4/4/2023 1:19:18 PM
 *  Author: Mahmoud Mowafey
 */ 


#ifndef DIO_H_
#define DIO_H_

/****************************** all driver header files *****************************************************/
#include "../../Utilities/Register_file.h"
#include "../../Utilities/types.h"

/****************************** all internal driver typedefs *****************************************************/
// enum definition for direction
typedef enum dir{
	INPUT, OUTPUT
}Direction_t;

// enum definition for Errors types
typedef enum Dio_error {
	DIO_OK, WRONG_DIR, WRONG_PORT, WRONG_PIN, WRITE_OK, WRONG_VAL, TOGGLE_OK, READ_OK
}EN_dioError_t;

// enum definition for value
typedef enum pin_val{
	LOW,HIGH
}pin_val;


// enum definition for boolean type
typedef enum{
	FALSE, 
	TRUE
}enu_boolean_expression;
/****************************** all driver macros *****************************************************/
#define PORT_A	'A'
#define PORT_B  'B'
#define PORT_C  'C'
#define PORT_D  'D'
#define PORTWIDTH  8U   //according to register width in ATmega32

/****************************** all function prototypes *****************************************************/
EN_dioError_t Dio_init(uint8_t pinNumber, uint8_t portNumber, uint8_t pinDirection);

EN_dioError_t Dio_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value);

EN_dioError_t Dio_toggle(uint8_t pinNumber, uint8_t portNumber);

EN_dioError_t Dio_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value);


#endif /* DIO_H_ */



