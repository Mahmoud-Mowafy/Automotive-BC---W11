/*
 * stack.cc
 *
 *  Created on: Mar 27, 2023
 *      Author: Mahmoud Mowafey
 *      Sprint_Number : 2
 *      Module_Name : Data_Structures
 *      Task_Name : Balanced
 */

 /************************************************************************************************************
  * Function : isBalancedParanthethes()
  *//**
  * Description:
  *
  * This function is used to check the pranthethes balance
  *
  *
  * PRE-CONDITION:   the expression is entered by the user.
  * POST-CONDITION:  store the pranthethes inside a stack and check its balance.
  *
  * @param [in]		expression is a pointer to the string that holding the expression.
  *
  * @return 			int8_t.
  * \b Example:
  * @code
  * int8_t var = isBalancedParanthethes(uint8_t *expression)';;
  * @endcode
  *
  ******************************************************************************************************************************************/

#include"isBalanced.h"

int8_t isBalancedParanthethes(uint8_t *expression)
{
	ST_stack_t newStack;
	createEmptyStack(&newStack);
	uint8_t i, StackFull=0, parentheses =0, counter=0;
	uint8_t newStackElements =0;
	uint8_t currentStackSize =0;
	int8_t pushed[20]={0},pushedCounter=0;
	newStackElements = strlen(expression);
	printf("newStackElements === %d\n",newStackElements);
	/* check if the neither (),{} of parentheses  is used, will push them to the stack  */
	for( i=0; i < newStackElements; i++ )
	{
		if( expression[i] == ')' )
		{
			parentheses++;
			StackFull = push(&newStack,expression[i]);
			pushed[i]=1;
			if( StackFull == -1 )
			{
				printf("Your stack is full, please remove a character and try again \n");
				break;
			}
		}

		else if( expression[i] == '(' )
		{
			parentheses++;
			StackFull = push(&newStack,expression[i]);
			pushed[i]=-1;
			if( StackFull == -1 )
			{
				printf("Your stack is full, please remove a character and try again \n");
				break;
			}
		}
		else if( expression[i] == '}' )
		{
			parentheses++;
			StackFull = push(&newStack,expression[i]);
			pushed[i]=2;
			if( StackFull == -1 )
			{
				printf("Your stack is full, please remove a character and try again \n");
				break;
			}
		}
		else if( expression[i] == '{' )
		{
			parentheses++;
			StackFull = push(&newStack,expression[i]);
			pushed[i]=-2;
			if( StackFull == -1 )
			{
				printf("Your stack is full, please remove a character and try again \n");
				break;
			}
		}
	}
	printf("Number of entered parentheses  === %d\n",parentheses );
	if( (parentheses  == 0 ) && (counter != 0 ) )
		return -2;
	/* Check if the expression is balanced or not*/
	currentStackSize = newStack.top + 1;
	printf("currentStackSize === %d\n",currentStackSize);
	/*Adding the Stack elements if =0 -> Balanced, else not balanced*/
	int8_t Adding=0;
	Adding = pushed[0];
	for(pushedCounter=1; pushedCounter < newStackElements; pushedCounter++)
	{
		Adding += pushed[pushedCounter];
	}
	if( Adding == 0)
		return 0;
	else
		return -1;
}

/********************  isBalanced function test  *******************************************************/
void isBalancedParanthethesTest()
{

	uint8_t string [STACK_SIZE], arr[STACK_SIZE], i, j, StringLength;
	int8_t IsBalanced = 0;
	printf("/*********************************isBalancedParanthethes Test**********************************/ \n");
	for(j=0; j<10; j++)
	{
		printf("\n********************************Enter your expression***************************\n");
		printf("********************************Test Case_%d***************************\n",j);
		do
		{
			fflush(stdin);
			fflush(stdout);
			scanf("%s",string);
			StringLength = strlen(string);
		}while(StringLength > STACK_SIZE );
		for(i=0; i<STACK_SIZE; i++)
		{
			arr[i] = string[i];
		}
		IsBalanced = isBalancedParanthethes(arr);
		if(IsBalanced == 0)
			printf(" Your expression is balanced\n");
		if(IsBalanced == -1)
			printf(" Your expression is not balanced\n");
		if(IsBalanced == -2)
			printf(" the neither (),{} of paranthethes is used \n");
		printf("\n_________________________________Test Case_%d is passed_____________________________\n",j);
	}


}
