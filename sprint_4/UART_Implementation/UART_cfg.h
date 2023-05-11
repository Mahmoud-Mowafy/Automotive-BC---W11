/*
 * File:   UART_cfg.h
 * Author: Mahmoud Mowafey
 *
 * Created on 10-05-2023, 5:29 PM
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef UART_CFG_H
#define	UART_CFG_H
/**********************************************************************
* Includes
**********************************************************************/
/**********************************************************************
* Preprocessor Constants
**********************************************************************/
#define    UART_U8_UCSRA_REG        *( ( volatile  u8 * ) 0x2B )
#define    UART_U8_UCSRB_REG        *( ( volatile  u8 * ) 0x2A )
#define    UART_U8_UCSRC_REG        *( ( volatile  u8 * ) 0x40 )
#define    UART_U8_UBRRH_REG        *( ( volatile  u8 * ) 0x40 )
#define    UART_U8_UBRRL_REG        *( ( volatile  u8 * ) 0x29 )
#define    UART_U8_UDR_REG          *( ( volatile  u16 *) 0x2C )

#define NUM_UART        1
/**********************************************************************
* Typedefs
**********************************************************************/

/**
 * Defines an enumerated list of all the UART channels  on the MCU
* device. The last element is used to specify the maximum number of
* enumerated labels.
 */
typedef enum
{
 /* available UART modules in MC */
   /*******UART_Channels**************/ 
	 UART_CH_0, /**< Channel_0 */ 	 
	 UART_MAX_CHANNEL_NUMBER /**< MAX CHANNELS */ 
}uartChannel_t;

/**
 * Defines the possible Operating Mode for the UART module. The datasheet
 * should be reviewed for proper mode options.
 */
typedef enum
{
	 /* TODO: Populate with possible mode options */
	 ASYNCH_NORMAL_Mode,
	 ASYNCH_DOUPLE_SPEED_Mode, 
	 SYNCH_MASTER_Mode 
}UartOperationMode_t;

/**
 * Defines the possible Clock Source for the UART module. The datasheet
 * should be reviewed for proper mode options.
 */
/*
typedef enum
{
    UART_CLK_SOURCE_INTERNAL,
    UART_CLK_SOURCE_EXTERNAL
}UartClockSource_t;
*/
/**
 * Defines the interrupt flag of the UART Module if it is eneabled or not.
 */
typedef enum {
    UART_ISR_DISABLED,
    UART_ISR_ENABLED
}UartISREnable_t;

/**
 * Defines the UART Module status if it is eneabled or not. The datasheet
 * should be reviewed for proper mode options.
 */
typedef enum {
    UART_MODULE_DISABLED,
    UART_MODULE_ENABLED
}UartModuleEnable_t;

/**
 * Defines the possible Clock Polarity source for the UART module. used for Synchronous mode only.
 */
typedef enum {
    UART_XCK_RISING_EDGE,
    UART_XCK_FALLING_EDGE,
    UART_DISABLED_WRITE_IT_TO_ZERO_IN_ASYNCH_MODE
}UartClockPolarityMode_t;

/**
 * Defines the possible TX_RX modes of the UART module.
 */
typedef enum
{
    UART_TX_MODE,   /*< Used to enable the only transmitter  mode */
    UART_rX_MODE,   /*< Used to enable the only receiver mode*/
    UART_TX_RX_MODE /*  Used to enable both the transimitter receiver mode*/ 
}UartTxRxMode_t;


/**
 * Defines the possible Baud Rates available of the UART module using F_CPU1MHZ frequency.
 */
typedef enum 
{
	UART_BR_2400 = 2400,
    UART_BR_4800 = 4800,
    UART_BR_9600 = 9600,
    UART_BR_14400 = 14400,
    UART_BR_19200 = 19200,
    UART_BR_28800 = 28800,
    UART_BR_38400 = 38400,
    UART_BR_57600 = 57600,
    UART_BR_76800 = 76800,
    UART_BR_115200 = 115200,
    UART_BR_230400 = 230400,
    UART_BR_250000 = 250000
}UartBaudRate_t;

/**
 * Defines the digital input/output configuration table�s elements that are used
 * by Dio_Init to configure the Dio peripheral.
 */
typedef enum 
{
	UART_PARITY_DISABLED,
	UART_EVEN_PARITY,
    UART_ODD_PARITY
}UartParityMode_t;

typedef enum 
{
	UART_ONE_STOP_BIT,
	UART_TWO_STOP_BITS,
}UartStopBitsMode_t;

typedef enum 
{
	UART_5_BITS_DATA,
    UART_6_BITS_DATA,
    UART_7_BITS_DATA,
    UART_8_BITS_DATA,
    UART_9_BITS_DATA
}UartCharacterSizeMode_t;

typedef struct
{
	 /* TODO: Add additional members for the MCU peripheral */
	 uartChannel_t UART_Channel; /**< The I/O pin */
	 UartOperationMode_t UART_OpMode; /**< ENABLED or DISABLED */
	 UartBaudRate_t UART_BaudRate; /**< OUTPUT or INPUT */
	 UartTxRxMode_t UART_TxRxMode; /**<HIGH or LOW */
	 UartParityMode_t UART_ParityMode; /**< Mux Function - Dio_Peri_Select*/
     UartCharacterSizeMode_t UART_CharacterSize; /**< Mux Function - Dio_Peri_Select*/
     UartStopBitsMode_t UART_stopBits;
     UartClockPolarityMode_t UART_ClkPol;
     UartModuleEnable_t UART_Enable;
     UartISREnable_t UART_ISR;
}UartConfig_t;

/**********************************************************************
* Function Prototypes
**********************************************************************/
	const UartConfig_t * const UART_ConfigGet(void);
/***End of File****************************************************/

#endif	/* UART_CFG_H */

