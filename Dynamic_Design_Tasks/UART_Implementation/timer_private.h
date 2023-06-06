/*
 * uart_private.h
 *
 *     Created on: Apr 10, 2023
 *         Author: Mahmoud Mowafey - https://github.com/Mahmoud-Mowafy
 *    Description: This file contains all Timer (TMR) registers' locations.
 *		MCU Datasheet: AVR ATmega32
 *                  https://ww1.microchip.com/downloads/en/DeviceDoc/Atmega32A-DataSheet-Complete-DS40002072A.pdf
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

 /**********************************************************/
 /**           UART PORTS Registers Locations              **/
 /**********************************************************/
  #define    UART_U8_UCSRA_REG        *( ( volatile  u8 * ) 0x2B )
  #define    UART_U8_UCSRB_REG        *( ( volatile  u8 * ) 0x2A )
  #define    UART_U8_UCSRC_REG        *( ( volatile  u8 * ) 0x40 )
  #define    UART_U8_UBRRH_REG        *( ( volatile  u8 * ) 0x40 )
  #define    UART_U8_UBRRL_REG        *( ( volatile  u8 * ) 0x29 )
  #define    UART_U8_UDR_REG          *( ( volatile  u16 *) 0x2C )
 /*******************************************************************************************************************************************************************/
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

/* S-REG */
#define TMR_U8_SREG_REG		    *( ( volatile u8 * ) 0x5F )

/*******************************************************************************************************************************************************************/

#endif /* UART_PRIVATE_H_ */