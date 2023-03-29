
/*
 * @Title      	: X_O Game
 * @Filename   	: X_O_Functions.c
 * @Author     	: Mahmoud Mowafey
 * @Origin Date	: Mar 26, 2023
 * @Version		: 1.0.0
 * @Compiler	: MinGW
 * @Target     	: General Purpose Processor / PCs
 * @Notes		: The code is written with ANSI_C Standard.
 *
 * THIS SOFTWARE IS PROVIDED BY HACKER KERMIT- TEAM_1 at Sprints_Automotiv_BC_W11.
 *
 *
 */

#ifndef X_O_FUNCTIONS_H_
#define X_O_FUNCTIONS_H_

#include<stdio.h>
#include<string.h>
/***************************************************************************************************************************************/
/*
*						Defines the user defined data types.
*/
/**************************************************************************************************************************************/

#define uint8_t unsigned char

typedef enum{
	X = 88,
	O = 79
}Player_Sign;

typedef enum{
	False,True
}en;

/**********************************************************************************************************************/

/**************************************************************************************************************************************/
/*
*							Prototypes for all used functions inside the X_O Game.
*/
/**************************************************************************************************************************************/
void createBoard(void);

void drawBoard(uint8_t *board);

void updateBoard (uint8_t *board, uint8_t position, uint8_t value);

uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t * symbol);

void setPlayerConfig(uint8_t *configArray);

void loadAndUpdate(uint8_t playerNumber);

void getGameState(uint8_t *board, uint8_t *gameState);


/************************************************************************************************************************/

/**
 * Player Configuration
 */

typedef struct{
	uint8_t PlayerName[20];
	uint8_t PlayerSymbol;
}Player_Config;


#endif /* X_O_FUNCTIONS_H_ */
