/*
 * LCS.c
 *
 *  Created on: Mar 29, 2023
 *      Author: Mahmoud
 */

#include"lcs.h"

/* Description:
 * - This function takes a reference to an array,
 * - array size, and
 * - reference to store the size of the LCS
 * - Using the insertion sort algorithm
 * - The function will search for the LCS in the array and
 * - stores its size
 * Return:
 * - returns -1 if the array is empty
 * - returns -2 if the array size is 0 or >10
 * - returns -3 if there is no LCS,
 * (i.e all array elements are not consecutive at all)
 * - returns 0 otherwise
 */
int8_t lcsGetSize(int32_t *array, uint8_t arraySize, uint8_t *sizeofLCS)
{
	uint8_t  i , maxConsLength = 0, LCS = 1;
	int32_t arrayEmpty =0;
	/*1-the array is Sorted*/
	if( ( arraySize < 0 ) || ( arraySize > 10 ) )
		return -2;
	/*2-increment the sizeOfLCS when array[i] = array[i-1]+1, otherwise set the sizeOfLCS to be equal 1 */
	for(i=0; i<arraySize; i++)
	{
		arrayEmpty += array[i];
		if( i > 0 && (array[i]) == (array[i-1]+1) )
			LCS += 1;
		else
			LCS = 1;
		maxConsLength = ( LCS > maxConsLength ? LCS : maxConsLength );
	}
	*sizeofLCS = maxConsLength;
	/*if the array is empty*/
	if( arrayEmpty == 0 )
		return -1;
	/*if there is no LCS*/
	else if( maxConsLength == 1 )
		return -3;
	else
		return 0;
}

void lcsGetSizeTest(void)
{
	static uint8_t x=0;
	printf("\nTester Name: Mahmoud_Mowafey");
	printf("\nFunction Name: lcsGetSize\n");
	printf("Test Case_%d: \n",x++);
	printf("\nEnter elements of the array separated by comma','   :\n");
	int32_t  ArraySize, string[20], i=0;
	int8_t IsSorted=0, isLCS=0;
	uint8_t sizeofLCS =0;
	int32_t array[10];
	int8_t *pt;
	fflush(stdin);
	fflush(stdout);
	scanf("%s",string);
	/***********************Parsing the Entered string and storing new array*********************/
    pt = strtok (&string,",");
    while (pt != NULL)
    {
    	int32_t a =  atoi(pt);
    	array[i] = a;
        pt = strtok (NULL, ",");
        i++;
    }
    //printf("%d",i);
    ArraySize = i;
    /***********************************************************************/
    IsSorted = insertionSort(array, ArraySize);
    isLCS = lcsGetSize(array, ArraySize  , &sizeofLCS);
    if(isLCS == -1)
    	printf("The entered array is empty");
    else if(isLCS == -2)
    	printf("The array size is <0 or >10 ");
    else if(isLCS == -3)
    	printf("there is no LCS");
    else if( isLCS == 0)
    	printf("The LCS is equal: %d",sizeofLCS);
}
