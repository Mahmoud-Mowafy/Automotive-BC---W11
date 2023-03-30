/*
 * sort.c
 *
 *  Created on: Mar 29, 2023
 *      Author: Mahmoud
 */



#include"sort.h"

/* Description:
 * - This function takes a reference to an array of integers
 * - Sorts the array in ascending order
 * - Using the insertion sort algorithm
 * Return:
 * - returns -1 if the array is empty
 * - returns -2 if the array size is 0 or >10
 * - returns 0 if sorting is done without errors
 */
int8_t insertionSort(int32_t *array, uint8_t arraySize)
{
	uint8_t i,hole;
	int32_t value;
	int32_t arrayEmpty = array[0];

	if( ( arraySize < 0 ) || ( arraySize > 10 ) )
		return -2;
	/*Accessing the array*/
	for(i=1; i < arraySize; i++)
	{

		arrayEmpty += array[i];
		/*Start from the second element*/
		value = array[i];
		hole= i;
		/*Check if the element is smaller than all previous elements*/
        while(hole>0 && value < array[hole-1])
        {
        	array[hole] = array[hole-1];
        	hole = hole-1;
        }
        array[hole] = value;
	}
	if( arrayEmpty == 0 )
		return -1;
	else
		return 0;
}

/* Description:
 * - This function takes a reference to an array of integers
 * - Prints all array elements
 * Return:
 * - Nothing to return
 */
void printArray(int32_t *array, uint8_t arraySize)
{
	uint8_t i;
	for(i=0; i<arraySize; i++)
	{
		printf("%d\n",array[i]);
	}
}

/*Test Function*/

void insertionSortTest(void)
{
	static uint8_t x=0;
	printf("\nTester Name: Mahmoud_Mowafey");
	printf("Function Name: insertionSort\n");
	printf("Test Case_%d: \n",x++);
	printf("Enter elements of the array separated by comma','   :\n");
	int32_t  ArraySize, string[20], i=0;
	int8_t IsSorted=0;
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
    ArraySize = i;

    /***********************************************************************/
    IsSorted = insertionSort(array, ArraySize);
    if(IsSorted == -1)
    	printf("The entered array is empty");
    else if(IsSorted == -2)
    	printf("The array size is <0 or >10 ");
    else if( IsSorted == 0)
    {
    	printArray(array, ArraySize);
    	printf("Sorting is done without errors");
    }
}


