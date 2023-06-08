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

// typedef enum {
// 	FALSE,
// 	TRUE
// }enu_dio;
// enum definition for Errors types
typedef enum Dio_error {
	DIO_OK, WRONG_DIR, WRONG_PORT, WRONG_PIN, WRITE_OK, WRONG_VAL, TOGGLE_OK, READ_OK
}EN_dioError_t;

// enum definition for value
typedef enum pin_val{
	LOW,HIGH
}pin_val;

/****************************** all driver macros *****************************************************/
#define PORT_A	'A'
#define PORT_B  'B'
#define PORT_C  'C'
#define PORT_D  'D'
#define PORTWIDTH  8   //according to register width in ATmega32

/****************************** all function prototypes *****************************************************/
int Dio_init(uint8_t pinNumber, uint8_t portNumber, uint8_t pinDirection);

int Dio_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value);

int Dio_toggle(uint8_t pinNumber, uint8_t portNumber);

int Dio_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value);

int Dio_writeBits(uint8_t portNumber, uint8_t mask);


#endif /* DIO_H_ */



