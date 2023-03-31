/*
 * main.c
 *
 *  Created on: Mar 27, 2023
 *      Author: Mahmoud Mowafey
 *      Sprint_Number : 2
 *      Module_Name : Data_Structures
 *      Task_Name : Stack
 */


#include"main.h"



int main(void)
{
	ST_stack_t stack;
	uint8_t i, element, StackTop;
	int8_t StackFull =0, StackEmpty =0, PrintStatus =0;
	createEmptyStack(&stack);
	uint8_t temp;
	uint8_t str[]="Mahoud Mowafey";
	for( i=0; str[i] !=0; i++ )
	{
		push(&stack,str[i]);
	}
	//stackTestFunction(&stack);

	isBalancedParanthethesTest();
}




