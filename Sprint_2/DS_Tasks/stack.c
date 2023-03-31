/*
 * stack.cc
 *
 *  Created on: Mar 27, 2023
 *      Author: Mahmoud Mowafey
 *      Sprint_Number : 2
 *      Module_Name : Data_Structures
 *      Task_Name : Stack
 */

#include"stack.h"

/************************************************************************************************************
 * Function : createEmptyStack()
 *//**
 * Description:
 *
 * This function is used to test the createEmptyStack() function, to create the stack and initialize it.
 * This function takes a reference to a stacks type
 * Initialize this stack with Zeros
 * Initialize the top with -1
 *
 *
 * PRE-CONDITION:
 * PRE-CONDITION:
 * PRE-CONDITION:
 * PRE-CONDITION:
 * POST-CONDITION:
 *
 * @param [in]		cardData is a pointer to the ST_cardData_t structure that holding data
 * 					about the card, such as cardHolderName, primaryAccountNumber, cardExpirationDate.
 *
 * @return 			void.
 * \b Example:
 * @code
 *  createEmptyStack(ST_stack_t *stack);
 * @endcode
 *
 * @see getCardHolderNameTest()
 *
 ******************************************************************************************************************************************/
void createEmptyStack(ST_stack_t *stack)
{
	uint8_t i;
	for( i=0; i<STACK_SIZE; i++ )
	{
		stack->elements[i]='0';
	}
	stack->top = -1;
}
/* ******************************************************************************************************************************************/


void deleteStack(ST_stack_t *stack)
{
	stack->top = -1;
}


/******************************************************************************************************************************************
 * Function : getCardHolderName()
 *//**
 * Description:
 *
 * This function is used to test the getHolderName() function, to validate the card data.
 *
 * PRE-CONDITION:
 * PRE-CONDITION:
 * PRE-CONDITION:
 * PRE-CONDITION:
 * POST-CONDITION:
 *
 * @param [in]		cardData is a pointer to the ST_cardData_t structure that holding data
 * 					about the card, such as cardHolderName, primaryAccountNumber, cardExpirationDate.
 *
 * @return 			EN_cardError_t is a enumeration that contains module errors.
 * \b Example:
 * @code
 * uint8_t var = getCardHolderName();
 * @endcode
 *
 * @see getCardHolderNameTest()
 *
 ************************************************************************************************************/

/* Description:
 * - This function takes a reference to the stack and data to store
 * - Stores the data passed into the stack
 * Return:
 * - returns -1 if the stack is full
 * - returns 0 otherwise
 */
 int8_t push(ST_stack_t *stack, uint8_t data)
 {
	 if( stack->top == (STACK_SIZE-1) )
		 return -1;
	 else
	 {
		 stack->elements[++(stack->top)] = data;
		 return 0;
	 }

 }
 /************************************************************************************************************
  * Function : getCardHolderName()
  *//**
  * Description:
  *
  * This function is used to test the getHolderName() function, to validate the card data.
  *
  * PRE-CONDITION:
  * PRE-CONDITION:
  * PRE-CONDITION:
  * PRE-CONDITION:
  * POST-CONDITION:  Deleting an element from the stack.
  *
  * @param [in]		cardData is a pointer to the ST_cardData_t structure that holding data
  * 					about the card, such as cardHolderName, primaryAccountNumber, cardExpirationDate.
  *
  * @return 			EN_cardError_t is a enumeration that contains module errors.
  * \b Example:
  * @code
  * uint8_t var = getCardHolderName();
  * @endcode
  *
  * @see getCardHolderNameTest()
  *
  ************************************************************************************************************/

 /* Description:
  * - This function takes a reference to the stack
  * - Stores the data popped from the stack in a data variable
  * Return:
  * - returns -2 if the stack is empty
  * - returns 0 otherwise
  */
  int8_t pop(ST_stack_t *stack, uint8_t *data)
  {
	  if( stack->top == -1)
		  return -2;
	  else
	  {
		  *data = stack->elements[stack->top--];
		  return 0;
	  }
  }

  /************************************************************************************************************
   * Function : getCardHolderName()
   *//**
   * Description:
   *  This function takes a reference to the stack
   * - Prints all stack's data starting from the top
   * Return:
   * - returns -1 if the stack is full
   * - returns -2 if the stack is empty
   * - returns 0 otherwise
   *
   *
   * PRE-CONDITION:
   * PRE-CONDITION:
   * PRE-CONDITION:
   * PRE-CONDITION:
   * POST-CONDITION:
   *
   * @param [in]		stack is a pointer to the ST_cardData_t structure that holding data
   * 					about the card, such as cardHolderName, primaryAccountNumber, cardExpirationDate.
   *
   * @return 			EN_cardError_t is a enumeration that contains module errors.
   * \b Example:
   * @code
   * uint8_t var = printStack();
   * @endcode
   *
   ************************************************************************************************************/

  int8_t printStack(ST_stack_t *stack)
  {
     int i;
     if( ( stack->top )== (STACK_SIZE-1) )
    	 return -1;
     if( stack->top == -1 )
     		  return -2;
     for (i = stack->top; i >= 0; i--)
        printf("%c\n", stack->elements[i]);
     return 0;
  }

  /************************************************************************************************************
   * Function : getCardHolderName()
   *//**
   * Description:
   *
   * This function is used to test the getHolderName() function, to validate the card data.
   *
   * PRE-CONDITION:
   * PRE-CONDITION:
   * PRE-CONDITION:
   * PRE-CONDITION:
   * POST-CONDITION:
   *
   * @param [in]		cardData is a pointer to the ST_cardData_t structure that holding data
   * 					about the card, such as cardHolderName, primaryAccountNumber, cardExpirationDate.
   *
   * @return 			EN_cardError_t is a enumeration that contains module errors.
   * \b Example:
   * @code
   * uint8_t var = getCardHolderName();
   * @endcode
   *
   * @see getCardHolderNameTest()
   *
   ************************************************************************************************************/


 /* Description:
  * - This function takes a reference to the stack
  * - Stores its top data into a variable
  * Return:
  * - returns -2 if the stack is empty
  * - 0 otherwise
  */
 int8_t getStackTop(ST_stack_t *stack, uint8_t *topData)
 {
	  if( stack->top == -1)
		  return -2;
	  else
	  {
		  *topData = stack->elements[stack->top];
		  return 0;
	  }
 }

 /************************************************************************************************************
  * Function : getCardHolderName()
  *//**
  * Description:
  *
  * This function is used to test the getHolderName() function, to validate the card data.
  *
  * PRE-CONDITION:
  * PRE-CONDITION:
  * PRE-CONDITION:
  * PRE-CONDITION:
  * POST-CONDITION:
  *
  * @param [in]		cardData is a pointer to the ST_cardData_t structure that holding data
  * 					about the card, such as cardHolderName, primaryAccountNumber, cardExpirationDate.
  *
  * @return 			EN_cardError_t is a enumeration that contains module errors.
  * \b Example:
  * @code
  * uint8_t var = getCardHolderName();
  * @endcode
  *
  * @see getCardHolderNameTest()
  *
  ************************************************************************************************************/


 /* Description:
  * - This function takes a reference to the stack
  * - Checks if the stack is full or not
  * Return:
  * - returns -1 if the stack is full
  * - 0 otherwise
  */
 int8_t isFull(ST_stack_t *stack)
 {
	  if( stack->top == (STACK_SIZE-1) )
		  return -1;
	  else
		  return 0;
 }

 /************************************************************************************************************
  * Function : getCardHolderName()
  *//**
  * Description:
  *
  * This function is used to test the getHolderName() function, to validate the card data.
  *
  * PRE-CONDITION:
  * PRE-CONDITION:
  * PRE-CONDITION:
  * PRE-CONDITION:
  * POST-CONDITION:
  *
  * @param [in]		cardData is a pointer to the ST_cardData_t structure that holding data
  * 					about the card, such as cardHolderName, primaryAccountNumber, cardExpirationDate.
  *
  * @return 			EN_cardError_t is a enumeration that contains module errors.
  * \b Example:
  * @code
  * uint8_t var = getCardHolderName();
  * @endcode
  *
  * @see getCardHolderNameTest()
  *
  ************************************************************************************************************/

 /* Description:
  * - This function takes a reference to the stack
  * - Checks if the stack is empty or not
  * Return:
  * - returns -2 if the stack is empty
  * - 0 otherwise
  */
 int8_t isEmpty(ST_stack_t *stack)
 {
	  if( stack->top == -1 )
		  return -2;
	  else
		  return 0;
 }



 void stackTestFunction(ST_stack_t *stack)
 {
 	uint8_t string [10], i, element, StackTop;
 	int8_t StackFull =0, StackEmpty =0, PrintStatus =0;
 	/*Create an empty stack, check the stack data*/
 	createEmptyStack(&stack);
 	printStack(&stack);
 	/*Push 5 different characters to the stack, Print all stack data*/
 	printf("Push 5 different characters \n");
 	gets(&string);
 	for( i=0; string[i] !=0; i++ )
 	{
 		StackFull = push(&stack,string[i]);
 		if( StackFull == -1 )
 		{
 			printf("Your stack is full, please remove a character and try again \n");
 			break;
 		}
 	}
 	PrintStatus = printStack(&stack);
 	if( PrintStatus == -1 )
 		printf("Your stack is full, please remove a character \n");
 	else if( PrintStatus == -2 )
 		printf("Your stack is empty, please push a character \n");
 	/*Pop one character from the stack, Print the stack's top*/
 	StackEmpty = pop(&stack, &element);
 	if( StackEmpty == -2 )
 		printf("Your stack is empty, please push a character \n");
 	PrintStatus = getStackTop(&stack, &StackTop);
 	if( PrintStatus == -2 )
 		printf("Your stack is empty, please push a character \n");
 	/**********************************************************************************************************/
 	/*Push 7 different characters to the stack, Print all stack data*/
 	printf("Push 5 different characters \n");
 	gets(&string);
 	for( i=0; string[i] !=0; i++ )
 	{
 		StackFull = push(&stack,string[i]);
 		if( StackFull == -1 )
 		{
 			printf("Your stack is full, please remove a character and try again \n");
 			break;
 		}
 	}
 	PrintStatus = printStack(&stack);
 	if( PrintStatus == -1 )
 		printf("Your stack is full, please remove a character \n");
 	else if( PrintStatus == -2 )
 		printf("Your stack is empty, please push a character \n");
 	/*Pop one character from the stack, Print the stack's top*/
 	StackEmpty = pop(&stack, &element);
 	if( StackEmpty == -2 )
 		printf("Your stack is empty, please push a character \n");
 	PrintStatus = getStackTop(&stack, &StackTop);
 	if( PrintStatus == -2 )
 		printf("Your stack is empty, please push a character \n");
 	PrintStatus = printStack(&stack);
 	if( PrintStatus == -1 )
 		printf("Your stack is full, please remove a character \n");
 	else if( PrintStatus == -2 )
 		printf("Your stack is empty, please push a character \n");
 	/*Pop 4 characters from the stack, Print the stack's top, Print all stack data*/
 	for( i=0; string[i] !=0; i++ )
 	{
 		StackEmpty = pop(&stack, &element);
 		if( StackEmpty == -2 )
 		{
 			printf("Your stack is empty, please push a character \n");
 			break;
 		}
 	}
 	PrintStatus = getStackTop(&stack, &StackTop);
 	if( PrintStatus == -2 )
 		printf("Your stack is empty, please push a character \n");
 	PrintStatus = printStack(&stack);
 	if( PrintStatus == -1 )
 		printf("Your stack is full, please remove a character \n");
 	else if( PrintStatus == -2 )
 		printf("Your stack is empty, please push a character \n");

 	/*Pop 7 characters from the stack, Print the stack's top, Print all stack data*/
 	for( i=0; string[i] !=0; i++ )
 	{
 		StackEmpty = pop(&stack, &element);
 		if( StackEmpty == -2 )
 		{
 			printf("Your stack is empty, please push a character \n");
 			break;
 		}
 	}
 	PrintStatus = getStackTop(&stack, &StackTop);
 	if( PrintStatus == -2 )
 		printf("Your stack is empty, please push a character \n");
 	PrintStatus = printStack(&stack);
 	if( PrintStatus == -1 )
 		printf("Your stack is full, please remove a character \n");
 	else if( PrintStatus == -2 )
 		printf("Your stack is empty, please push a character \n");


 }
