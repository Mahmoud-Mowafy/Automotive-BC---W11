/*
 * File:   UART_cfg.c
 * Author: Mahmoud Mowafey
 *
 * Created on 10-05-2023, 5:29 PM
 */

/**********************************************************************
* Includes
**********************************************************************/
#include "uart_cfg.h" /* For this modules definitions */
/**********************************************************************
* Module Preprocessor Constants
**********************************************************************/
/**********************************************************************
* Module Preprocessor Macros
**********************************************************************/
/**********************************************************************
* Module Typedefs
**********************************************************************/
/*********************************************************************
* Module Variable Definitions
**********************************************************************/

/**
* Defines a table of pointers to the UART peripheral register on the
* microcontroller.
*/
uint8_t volatile *const uart[NUM_UART] =
        {
                (uint8_t*)UART_U8_UCSRA_REG,    /*USART Control and Status Register A*/
                (uint8_t*)UART_U8_UCSRB_REG,    /*USART Control and Status Register B*/
                (uint8_t*)UART_U8_UCSRC_REG,    /*USART Control and Status Register C*/
                (uint8_t*)UART_U8_UBRRH_REG,   /*USART Baud Rate High Register*/
                (uint8_t*)UART_U8_UBRRL_REG,   /*USART Baud Rate Low Register*/
                (uint8_t*)UART_U8_UDR_REG,     /* PUSART I/O Data Register*/
        };

/**********************************************************************/

/**
 * The following array contains the configuration data for each
 * UART_channel. Each row represents a
 * single UART_channel. Each column is representing a member of the UartConfig_t
 * structure. This table is read in by UART_Init, where each UART_channel is then
 * set up based on this table.
 */
const UartConfig_t UartConfig[] =
{
	/* UART_CH_0_Configurations*/
	{ UART_CH_0, ASYNCH_DOUPLE_SPEED_Mode, UART_BR_9600, UART_TX_RX_MODE,
          UART_PARITY_DISABLED, UART_8_BITS_DATA, UART_ONE_STOP_BIT, 
          UART_DISABLED_WRITE_IT_TO_ZERO_IN_ASYNCH_MODE, UART_MODULE_ENABLED, UART_ISR_DISABLED },				
};

/**********************************************************************
* Function Definitions
**********************************************************************/
/**********************************************************************
* Function : UART_ConfigGet()
*//**
* \b Description:
*
* This function is used to initialize the UART_channels based on the configuration
* table defined in uart_cfg module.
*
* PRE-CONDITION: Configuration table needs to populated (sizeof > 0)
*
* POST-CONDITION: A constant pointer to the first member of the
* configuration table will be returned.
*
* @return A pointer to the configuration table.
*
* \b Example Example:
* @code
* const UART_ConfigType *UartConfig = UART_GetConfig();
*
* UART_Init(UartConfig);
* @endcode
*
* @see UART_Init
* @see UART_sendByte
* @see UART_sendString
* @see UART_receiveByte
* @see UART_receiveString
*
**********************************************************************/
const UartConfig_t * const UART_ConfigGet(void)
{
/*
* The cast is performed to ensure that the address of the first element
* of configuration table is returned as a constant pointer and NOT a
* pointer that can be modified.
*/
 return (const *)uartConfig[0];
}
/*************** END OF FUNCTIONS ********************************/
