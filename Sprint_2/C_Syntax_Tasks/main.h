/*
  * @Title      	: X_O Game
  * @Filename   	: main.h
  * @Author     	: Mahmoud Mowafey
  * @Origin Date	: Mar 28, 2023
  * @Version		: 1.0.0
  * @Compiler		: MinGW
  * @Target     	: General Purpose Processor / PCs
  * @Notes			: The code is written with ANSI_C Standard.
  *
  * THIS SOFTWARE IS PROVIDED BY HACKER KERMIT- TEAM_1 at Sprints_Automotiv_BC_W11.
  *
  */


#ifndef MAIN_H_
#define MAIN_H_

  /**************************************************************************************************************************************/
  /*
  *						Include the module header files
  */
  /**************************************************************************************************************************************/
#include<stdio.h>
#include<string.h>

#include "X-O_Functions.h"


extern uint8_t board[9];
extern uint8_t playerSymbol[2];

uint8_t startNewGame(void);
void gamePlay();


#endif /* MAIN_H_ */
