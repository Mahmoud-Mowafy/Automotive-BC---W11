/*
 * main.c
 *
 *  Created on: Mar 26, 2023
 *      Author: Mahmoud Mowafey
 *      Sprint_Number : 2
 *      Module_Name : C_Syntax
 *      Task_Name : X-O Game
 */

#include "main.h"

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




int main(void)
{
	printf("******************************************************************************************\n");
	printf("_______________________________________X_O_Game______________________________________________\n\n");
	printf("******************************************************************************************\n");
	/*Create and intialize the GameState var to start playing*/
	uint8_t GameState = 2, WinnerPlayerNum;
	/*Initalizing the board*/
	drawBoard(board);
	setPlayerConfig(playerSymbol);
	//gamePlay();
	/*Start Playing*/
	while( GameState == 2 )
		{
			loadAndUpdate(0);
			getGameState(board, &GameState);
			if(GameState == 0)
			{
				WinnerPlayerNum = 1;
				printf("Player_%d wins\n",WinnerPlayerNum);
				break;
			}
			else if( GameState == 1)
			{
				printf("Draw\n");
				break;
			}
			loadAndUpdate(1);
			getGameState(board, &GameState);
			if(GameState == 0)
			{
				WinnerPlayerNum = 2;
				printf("Player_%d wins\n",WinnerPlayerNum);
				break;
			}
		}
	return 0;
}

/*void gamePlay()
{

	uint8_t GameState = 2, i, WinnerPlayerNum;
	for(i=0; i<9; i++)
	{
		board[i] = ' ';
	}
	while( GameState == 2 )
		{
			loadAndUpdate(0);
			getGameState(&board, &GameState);
			if(GameState == 0)
			{
				WinnerPlayerNum = 1;
				printf("Player_%d wins\n",WinnerPlayerNum);
				break;
			}
			else if( GameState == 1)
			{
				printf("Draw\n");
				printf("Player_%d wins\n",WinnerPlayerNum);
				break;
			}
			loadAndUpdate(1);
			getGameState(&board, &GameState);
			if(GameState == 0)
			{
				WinnerPlayerNum = 2;
				printf("Player_%d wins\n",WinnerPlayerNum);
				break;
			}
		}
	if( GameState == 0 || GameState == 1  )
	{
		if(startNewGame() == 'y')
			gamePlay();
	}
}
uint8_t startNewGame(void)
{
	uint8_t ch;
	printf("\t\tDo you want to start a new game ? (y or n)\n");
	scanf(" %c",&ch);
	return ch;
}*/

