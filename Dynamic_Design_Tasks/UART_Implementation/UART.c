/*
 * File:   UART_cfg.c
 * Author: Mahmoud Mowafey
 *
 * Created on 10-05-2023, 5:29 PM
 */

#include"UART.h"


void UART_init(const UartConfig_t * Config)
{
    /* TODO: Define implementation */
    uint8_t i = 0;           //loop counter variable
    // Loop through all pins, set the data register bit and the data-direction
    // register bit according to the dio configuration table values
    for (i = 0; i < UART_MAX_CHANNEL_NUMBER; i++)
    {
        switch( Config[i].UART_OpMode)
        {
            case ASYNCH_NORMAL_Mode:
                 CLEAR_BIT( UART_U8_UCSRC_REG,UMSEL); 
            break;
            case ASYNCH_DOUPLE_SPEED_Mode:
                 CLEAR_BIT( UART_U8_UCSRC_REG,UMSEL); 
                 SET_BIT( UART_U8_UCSRA_REG,U2X); 
            break;
            case SYNCH_MASTER_Mode:
                 SET_BIT( UART_U8_UCSRC_REG,UMSEL);
            break;
        }

        switch( Config[i].UART_BaudRate)
        {
            case UART_BR_2400:
	            UART_U8_UBRRH_REG = BAUD_PRESCALE >> 8;
	            UART_U8_UBRRL_REG = BAUD_PRESCALE;
            break;
            case UART_BR_4800:
	            UART_U8_UBRRH_REG = BAUD_PRESCALE >> 8;
	            UART_U8_UBRRL_REG = BAUD_PRESCALE;
            break;
            case UART_BR_9600:
	            UART_U8_UBRRH_REG = BAUD_PRESCALE >> 8;
	            UART_U8_UBRRL_REG = BAUD_PRESCALE;
            break;
            case UART_BR_14400:
	            UART_U8_UBRRH_REG = BAUD_PRESCALE >> 8;
	            UART_U8_UBRRL_REG = BAUD_PRESCALE;
            break;
            case UART_BR_19200:
	            UART_U8_UBRRH_REG = BAUD_PRESCALE >> 8;
	            UART_U8_UBRRL_REG = BAUD_PRESCALE;
            break;
            case UART_BR_28800:
	            UART_U8_UBRRH_REG = BAUD_PRESCALE >> 8;
	            UART_U8_UBRRL_REG = BAUD_PRESCALE;
            break;
            case UART_BR_38400:
	            UART_U8_UBRRH_REG = BAUD_PRESCALE >> 8;
	            UART_U8_UBRRL_REG = BAUD_PRESCALE;
            break;
            case UART_BR_57600:
	            UART_U8_UBRRH_REG = BAUD_PRESCALE >> 8;
	            UART_U8_UBRRL_REG = BAUD_PRESCALE;
            break;
            case UART_BR_76800:
	            UART_U8_UBRRH_REG = BAUD_PRESCALE >> 8;
	            UART_U8_UBRRL_REG = BAUD_PRESCALE;
            break;
            case UART_BR_115200:
	            UART_U8_UBRRH_REG = BAUD_PRESCALE >> 8;
	            UART_U8_UBRRL_REG = BAUD_PRESCALE;
            break;
            case UART_BR_230400:
	            UART_U8_UBRRH_REG = BAUD_PRESCALE >> 8;
	            UART_U8_UBRRL_REG = BAUD_PRESCALE;
            break;
            case UART_BR_250000:
	            UART_U8_UBRRH_REG = BAUD_PRESCALE >> 8;
	            UART_U8_UBRRL_REG = BAUD_PRESCALE;
            break;            

        }
        switch( Config[i].UART_TxRxMode)
        { 
            case UART_TX_MODE:
                SET_BIT( UART_U8_UCSRC_REG,TXEN); 
            break;
            case UART_rX_MODE:
                 SET_BIT( UART_U8_UCSRC_REG,RXEN); 
            break;
            case UART_TX_RX_MODE:
                 SET_BIT( UART_U8_UCSRC_REG,RXEN); 
                 SET_BIT( UART_U8_UCSRC_REG,TXEN);   
            break;
        }   
        switch( Config[i].UART_ParityMode)
        { 
            case UART_PARITY_DISABLED:
                 CLEAR_BIT( UART_U8_UCSRC_REG,UPM0); 
                 CLEAR_BIT( UART_U8_UCSRC_REG,UPM1); 
            break;
            case UART_EVEN_PARITY:
                 CLEAR_BIT( UART_U8_UCSRC_REG,UPM0); 
                 SET_BIT( UART_U8_UCSRC_REG,UPM1); 
            break;
            case UART_ODD_PARITY:
                 SET_BIT( UART_U8_UCSRC_REG,UPM0); 
                 SET_BIT( UART_U8_UCSRC_REG,UPM1); 
            break;
        }     
        switch( Config[i].UART_CharacterSize)
        {   
            SET_BIT( UART_U8_UCSRC_REG,URSEL);            /*to use the UCSRC register*/ 
            case UART_5_BITS_DATA:
                 CLEAR_BIT( UART_U8_UCSRC_REG,UCSZ0); 
                 CLEAR_BIT( UART_U8_UCSRC_REG,UCSZ1); 
            break;
            case UART_6_BITS_DATA:
                 SET_BIT( UART_U8_UCSRC_REG,UCSZ0); 
                 CLEAR_BIT( UART_U8_UCSRC_REG,UCSZ1); 
            break;
            case UART_7_BITS_DATA:
                 CLEAR_BIT( UART_U8_UCSRC_REG,UCSZ0); 
                 SET_BIT( UART_U8_UCSRC_REG,UCSZ1); 
            break;
            case UART_8_BITS_DATA:
                 SET_BIT( UART_U8_UCSRC_REG,UCSZ0); 
                 SET_BIT( UART_U8_UCSRC_REG,UCSZ1);
            break;
            case UART_9_BITS_DATA:
                 SET_BIT( UART_U8_UCSRC_REG,UCSZ0); 
                 SET_BIT( UART_U8_UCSRC_REG,UCSZ1);
                 SET_BIT( UART_U8_UCSRB_REG,UCSZ2);
            break;
        }     
        switch( Config[i].UART_stopBits)
        { 
            case UART_ONE_STOP_BIT:
                 CLEAR_BIT( UART_U8_UCSRC_REG,USBS); 
            break;
            case UART_TWO_STOP_BITS:
                 SET_BIT( UART_U8_UCSRC_REG,USBS);
            break;
        }     
        switch( Config[i].UART_ClkPol)
        { 
            case UART_XCK_RISING_EDGE:
                 CLEAR_BIT( UART_U8_UCSRC_REG,UCPOL);
            break;
            case UART_XCK_FALLING_EDGE:
                 SET_BIT( UART_U8_UCSRC_REG,UCPOL);
            break;
            case UART_DISABLED_WRITE_IT_TO_ZERO_IN_ASYNCH_MODE:
                 CLEAR_BIT( UART_U8_UCSRC_REG,UCPOL);
            break;
        }    
        switch( Config[i].UART_Enable)
        { 
            case UART_MODULE_DISABLED:

            break;
            case UART_MODULE_ENABLED:

            break;
        }  
        switch( Config[i].UART_ISR)
        { 
            case UART_ISR_DISABLED:

            break;
            case UART_ISR_ENABLED:

            break;
        }         
    }
}

void UART_sendByte(const uint8 data)
{
    /*check the UART Data empty flag */
    while(BIT_IS_CLEAR(UCSRA,UDRE));  
    /*load the UDR with the required data*/
    UDR = data;
}

uint8 UART_receiveByte(void)
{
    /*check the RX complete flag */
    while(BIT_IS_CLEAR(UCSRA,RXC));
    /*return the content of UDR */
    return UDR ;  
}

void UART_sendString(const uint8 *str)
{
    while(*str !='\0')
    {
        UART_sendByte(*str);
        str++;
    }
}

void UART_receiveString(uint8 *str)
{
    uint8 i=0;
    str[i] = UART_receiveByte();
    while(str[i] != '#')
    {
        i++;
        str[i] = UART_receiveByte();
    }
    str[i] = '\0';
}

