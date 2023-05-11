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
#define F_CPU                      1000000UL
//#define USART_BAUDRATE              9600
#define BAUD_PRESCALE        (((F_CPU / (USART_BAUDRATE * 8UL))) - 1)

#define BIT_IS_SET(REG,BIT)         (REG & (1<<BIT) )
#define BIT_IS_CLEAR(REG,BIT)       (!( REG &(1<<BIT) ) )

#define SET_BIT(REG,BIT)            ( REG |=(1<<BIT) )
#define CLEAR_BIT(REG,BIT)          (  REG &=(~(1<<BIT)) )

   /* UCSRA: USART Control and Status Register A Bit_Map*/    
#define MPCM      0           
#define U2X       1
#define PE        2
#define DOR       3
#define FE        4
#define UDRE      5
#define TXC       6 
#define RXC       7

   /* UCSRB: USART Control and Status Register B Bit_Map*/    
#define TXB8      0           
#define RXB8      1
#define UCSZ2     2
#define TXEN      3
#define RXEN      4
#define UDRIE     5
#define TXCIE     6 
#define RXCIE     7

   /* UCSRC: USART Control and Status Register C Bit_Map*/    
#define UCPOL     0           
#define UCSZ0     1
#define UCSZ1     2
#define USBS      3
#define UPM0      4
#define UPM1      5
#define UMSEL     6 
#define URSEL     7

   /* UBRRH: USART Baud Rate Registers*/    
#define URSEL     15   


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

