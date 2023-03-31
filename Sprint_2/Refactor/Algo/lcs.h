/*
 * LCS.h
 *
 *  Created on: Mar 29, 2023
 *      Author: Mahmoud
 */

#ifndef LCS_H_
#define LCS_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include"sort.h"

typedef  char int8_t;

typedef  int int32_t;

typedef  unsigned char uint8_t;


#define MAX(i, j) (((i) > (j)) ? (i) : (j))

int8_t lcsGetSize(int32_t *array, uint8_t arraySize, uint8_t *sizeofLCS);

void lcsGetSizeTest(void);

#endif /* LCS_H_ */
