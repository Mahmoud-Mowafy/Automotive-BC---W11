/*
 * sort.h
 *
 *  Created on: Mar 29, 2023
 *      Author: Mahmoud
 */

#ifndef SORT_H_
#define SORT_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef  char int8_t;

typedef  int int32_t;

typedef  unsigned char uint8_t;

int8_t insertionSort(int32_t *array, uint8_t arraySize);
void printArray(int32_t *array, uint8_t arraySize);
void insertionSortTest(void);

#endif /* SORT_H_ */
