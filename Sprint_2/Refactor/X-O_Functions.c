/*
 * X-O_Functions.c
 *
 *  Created on: Mar 26, 2023
 *      Author: Mahmoud Mowafey
 *      Sprint_Number : 2
 *      Module_Name : C_Syntax
 *      Task_Name : X-O Game
 */

#include "X-O_Functions.h"

uint8_t playerSymbol[2];
uint8_t board[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
uint8_t SignOnBoard;

/*
 * This function will take a board as an input and prints it on the console
 * Creating and  the Board, initializing it with numbers from 1:9 which state each position number on the board.
 * Accessing the array values as if it was a 2D array
 */

/************************************************************************************************************
 * Function : drawBoard()
 *//**
 * Description:
 * This function will take a board as an input and prints it on the console
 * Creating and  the Board, initializing it with numbers from 1:9 which state each position number on the board.
 * Accessing the array values as if it was a 2D array
 *
 * @param [in]		board is a pointer to 2D array
 *
 * @return 			void
 * \b Example:
 * @code
 *  drawBoard();
 * @endcode
 *
 *
 ************************************************************************************************************/


void drawBoard(uint8_t *board)
{
	uint8_t i,j,counter=1;
	printf("******************************************************************************************");
	printf("\n\n\t  ");
	static uint8_t BoardInit =0;
	/*Draw the board using by simple way */
	for ( i = 0; i < 3; i++)
	{
		for ( j = 0; j < 3; j++)
		{
			if(BoardInit == 0)
				printf("%d",counter++);
			else
				printf("%c",board[i*3+j]);
			if (j < 2)
			{
				printf("  |  ");
			}
		}
		if (i < 2)
			printf("\n\t----------------\n\t  ");
	}
	printf("\n\n******************************************************************************************\n");
	BoardInit = 1;
}


/************************************************************************************************************
 * Function : updateBoard()
 *//**
 * Description:
 *
 * This function will take the board, position to update and value to set in this position
 * 1- Check if the position is not selected before
 * 2- Check if the position in the boundary of board (1:9)
 *
 *
 * @param [in]		board is a pointer to 2D array, position on the board, the player sign.
 *
 * @return 			void
 * \b Example:
 * @code
 * updateBoard();
 * @endcode
 *
 *
 ************************************************************************************************************/


void updateBoard (uint8_t *board, uint8_t position, uint8_t value)
{

	if( (board[position-1] !=' ' ) || ( !( ( (position-1) >= 0  ) && ( (position-1 <= 9)  ) ) ))
	{
		printf("The entered position is selected before or it is out of boundary, please choose another position!");
		if(value == playerSymbol[0])
			loadAndUpdate(0);
		else
			loadAndUpdate(1);
	}
	else
	{
		board[position-1] = value;
		drawBoard(board);

	}
}

/************************************************************************************************************
 * Function : getPlayerSymbol()
 *//**
 * Description:
 *  This function will take the player's number and asks the player to choose between X and O (case insensitive)
 *  This function will return 0 when the input symbol is not wrong and/or was not chosen before
 *  This function will return 1 when the input symbol is wrong and/or was chosen before
 *
 *
 * \b Example:
 * @code
 * uint8_t var = getPlayerSymbol();
 * @endcode
 *
 *
 ************************************************************************************************************/


uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t *symbol)
{
	if( ( *( symbol - 1) != *symbol ) && ( (*symbol == 'X') || (*symbol == 'O') || (*symbol == 'x') || (*symbol == 'o')  ) )
		return False;
	else
		return True;
}



/************************************************************************************************************
 * Function : setPlayerConfig()
 *//**
 *
 *  This function will prompt and asks each user about their preferred symbols and saves it in the configArray
 *
 * \b Example:
 * @code
 *  setPlayerConfig();
 * @endcode
 *
 *
 ************************************************************************************************************/


void setPlayerConfig(uint8_t *configArray)
{
	uint8_t i,WrongSymbol = 0;
	for(i=0;i<2;i++)
	{
		printf("Enter a sign for player number_%d ( choose between X and O ) :\t",i);
		fflush(stdin);
		fflush(stdout);
		scanf("%c", &configArray[i]);
		WrongSymbol = getPlayerSymbol(i,&configArray[i]);
		if( WrongSymbol == 1)
		{
			printf("Your Sign is Wrong and/or was chosen before, Please Enter a correct one.\n");
			i--;
		}
	}

}


/************************************************************************************************************
 * Function : loadAndUpdate()
 *//**
 * Description:
 *
 *This function will take the player's number then load his config, ask him for the position then updates the board
 * \b Example:
 * @code
 *  loadAndUpdate();
 * @endcode
 *
 ************************************************************************************************************/


void loadAndUpdate(uint8_t playerNumber)
{
	SignOnBoard = 0;
	uint8_t position;
	int entered;
	switch(playerNumber)
	{
	case 0:
		SignOnBoard = playerSymbol[0];// for array config
		printf("\t\tPlayer One Movement\n");
		//SignOnBoard = configArray[0].PlayerSymbol;
		break;
	case 1:
		SignOnBoard = playerSymbol[1]; //for array config
		printf("\t\tPlayer Two Movement\n");
		//SignOnBoard = configArray[1].PlayerSymbol;
		break;
	}
	printf("Please enter the position for your move");
	fflush(stdin);
	fflush(stdout);
	scanf("%d", &entered);
	position = (uint8_t) entered;
	/*Check if the position is selected before*/
	updateBoard(board,position, SignOnBoard);
}





/************************************************************************************************************
 * Function : getGameState()
 *//**
 * Description:
 *
 * Implement a function to check if there is a winning, draw, or continue playing.
 * This function will check after each move if there is a win, draw or continue playing.
 * Returns 0 for winning
 * Returns 1 for a draw
 * Returns 2 to continue
 * \b Example:
 * @code
 *  getGameState();
 * @endcode
 *
 ************************************************************************************************************/


void getGameState(uint8_t *board, uint8_t *gameState)
{
    /* Check for empty cells and Draw*/
    uint8_t i, IsCellsCompleted = 0;
    for(i=0;i<9;i++)
    {
    	if( board[i] !=' ' )
    	{
    		IsCellsCompleted++;
    	}
    	else
    	{
    		*gameState = 2;
    	}
    }

    // check all rows
    if ((board[0] == SignOnBoard && board[1] == SignOnBoard && board[2] == SignOnBoard )||
      (board[3] == SignOnBoard && board[4] == SignOnBoard && board[5] == SignOnBoard )||
      (board[6] == SignOnBoard && board[7] == SignOnBoard && board[8] == SignOnBoard))
    {
    	*gameState = 0;
      }
      // check all columns
    else if ( (board[0] == SignOnBoard && board[3] == SignOnBoard && board[6] == SignOnBoard) ||
           (board[1] == SignOnBoard && board[4] == SignOnBoard && board[7] == SignOnBoard) ||
           (board[2] == SignOnBoard && board[5] == SignOnBoard && board[8] == SignOnBoard))
    {
    	*gameState = 0;
    }
    // check both diagonals
    else if ((board[0] == SignOnBoard && board[4] == SignOnBoard && board[8] == SignOnBoard) ||
           (board[2] == SignOnBoard && board[4] == SignOnBoard && board[6] == SignOnBoard))
    {
        *gameState = 0;
    }
    else if( IsCellsCompleted == 9 )
    {
    	*gameState = 1;
    }
}




