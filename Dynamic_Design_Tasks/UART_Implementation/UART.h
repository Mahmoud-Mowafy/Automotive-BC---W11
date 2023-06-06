/*
 * File:   UART.h
 * Author: Mahmoud Mowafey
 *
 * Created on 10-05-2023, 5:29 PM
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef UART_H
#define	UART_H



/**********************************************************************
* Typedefs
**********************************************************************/
typedef  unsigned char              u8 ;
typedef  unsigned int              u16 ;

/**********************************************************************
* Preprocessor Constants
**********************************************************************/


/**********************************************************************
* Function Prototypes
**********************************************************************/

void UART_init();
void UART_sendByte(u8 data);
u8 UART_receiveByte(void);
void UART_sendString(const u8 *str);
void UART_receiveString(u8 *str);
/***End of File****************************************************/

#endif	/* UART_H */

