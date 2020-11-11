#include <stdio.h>
#include "selectionsort.h" //#include "selectionsort.h"
#include "selectionsort.h" //#include "selectionsort.h" // included twice
#include <math.h>
#include "Q13.h"

//								 ----------------------------------
//								 | INTERNAL FUNCTION DECLARATIONS |
//								 ----------------------------------
/*
* findmin declaration for Q9
*/
int* findmin(int* arr, int size);

/*
* function declaration for Q12 (local functions).
* read an array of n integers, sorts them in both ascending and descending order, 
* and prints the sorted arrays, along with the minimum, maximum, average, and the standard deviation
* findmax function is to be implemented locally in the main program.
*/
void question12Output(int* array, int size); //will call all functions
int* findmax(int* arr, int size); //and findmin is in Q9 files.
int* selectionsortInverse(int* array, int size, int* (*findminPtr)(int* arr, int size)); //and selectionsortQ11 is in Q11 files
float findAvg(int* array, int size);
float findSD(int* array, int size);

//										-----------------
//										| MAIN FUNCTION |
//										-----------------
//----------------------------------------------------------------------------------------------------l
int main() {
    
    //Question Q9
    printf("Question 9: \n");
    int arr[] = { 1, 4, 5, 6, -1 };
    int* m = findmin(arr, 5);
    printf("%d", *m); // -1

    printf("\n");
    printf("\n");

   //----------------------------------------------------------------------------------------------------
   //Question 10
   printf("Question 10: \n");
   int i;
   selectionsort(arr, 5);
   for (i = 0; i < 5; i++) 
     printf("%d ", arr[i]);

   printf("\n");
   printf("\n");

   //----------------------------------------------------------------------------------------------------
   //Question 11
   printf("Question 11: \n");
   int arr2[] = { 1, 4, 5, 6, -1 };
   int* aFctPtr = NULL;
   int* aPtr;
   aPtr = selectionsortQ11(arr2, 5, aFctPtr); //will give garbage value because aFctPtr = NULL
   for (i = 0; i < 5; i++)
       printf("%d ", aPtr[i]);
   printf("\n");
   aFctPtr = &findmin;
   aPtr = selectionsortQ11(arr2, 5, aFctPtr); //will not give garbage value because aFctPtr = &findmin
   for (i = 0; i < 5; i++)
       printf("%d ", aPtr[i]);

   printf("\n");
   printf("\n");

   //----------------------------------------------------------------------------------------------------
   //Question 12
   printf("Question 12: \n");
   int* dynamicArray;
   dynamicArray = (int*)malloc(sizeof(int)*5);      // allocate 5 ints
   if (dynamicArray == NULL) {
	   printf("Unable to allocate memory for a dynamic array.");
   } else {
   dynamicArray[0] = 1;
   dynamicArray[1] = 4;
   dynamicArray[2] = 5;
   dynamicArray[3] = 6;
   dynamicArray[4] = -1;
   question12Output(dynamicArray, 5);
   }
   //delete/free dynamic array memory on Heap
   free(dynamicArray);

   printf("\n");

   //----------------------------------------------------------------------------------------------------
   //Question 13
   printf("Question 13: \n");
   //stores each word
   char word[SIZE] = { '\0' };
   char input[SIZE] = { '\0' };
   //stores a pointer to the 1st node in the linked list
   NodePointer head = NULL;
   //keep inserting until user enters "quit"
   while (0 != strcmp(input, QUIT)) {
	   printf("Enter a word to INSERT into linked list (enter '.' to quit): ");
	   gets(word);
	   strcpy(input, word);
	   char* token = strtok(word, " "); // Extract the first token
	   while (token != NULL) { // loop through the string to extract all other tokens
		   insert_dictionary_order(token, &head);
		   print_list(head);
		   token = strtok(NULL, " ");
	   }
   }//end of while
    return 0;
}
//----------------------------------------------------------------------------------------------------

//								 ---------------------------------
//								 | INTERNAL FUNCTION DEFINITIONS |
//								 ---------------------------------
/*
* findmin definition.
* receives an array of integers and returns a pointer to its smallest element
*/
int* findmin(int* arr, int size) {
	int smallestAddress = &arr[0];
	int smallestValue = arr[0];

	for (int i = 1; i < size; i++) {
		if (arr[i] < smallestValue) {
			smallestAddress = &arr[i];
			smallestValue = arr[i];
		}
	}
	return smallestAddress;
}

/*
* findmax definition.
* receives an array of integers and returns a pointer to its biggest element
*/
int* findmax(int* arr, int size) {
	int biggestAddress = &arr[0];
	int biggestValue = arr[0];

	for (int i = 1; i < size; i++) {
		if (arr[i] > biggestValue) {
			biggestAddress = &arr[i];
			biggestValue = arr[i];
		}
	}
	return biggestAddress;
}

/*
* SelectionSort, biggest to smallest. Hence, inverse.
*/
int* selectionsortInverse(int* array, int size, int* (*findminPtr)(int* arr, int size)) {
	int* maxPtr;
	int temp;
	int indexMax = 0;
	int indexCurrent = 0;
	int originalSize = size;

	if (findminPtr == NULL) {
		return maxPtr = findmax(array, size);
	}
	else {
		while (size != 0) {

			maxPtr = findmax(array, size);

			for (int i = 0; i < size; i++) {
				if (&array[i] == maxPtr) {
					indexMax = i;
				}
			}
			temp = array[indexCurrent];
			array[indexCurrent] = array[indexMax];
			array[indexMax] = temp;
			array = array + 1;
			size--;
		}
		return array = array - originalSize;
	}
}

/*
* findAvg definition.
* Takes an array and its size and 
* the avg of all the numbers of the array
*/
float findAvg(int* array, int size) {

	float avg = 0;

	for (int i = 0; i < size; i++) {
		avg = avg + array[i];
	}
	avg = avg / size;
	return avg;
}

/*
* findSD definition.
* finds the standard deviation from a given array and its size
*/
float findSD(int* array, int size) {
	float sum = 0.0, mean, SD = 0.0;
	int i;
	for (i = 0; i < size; ++i) {
		sum += array[i];
	}
	mean = sum / size;
	for (i = 0; i < size; ++i)
		SD += pow(array[i] - mean, 2);
	return sqrt(SD / size);
}

/*
* question12Output definition.
* calls all other helper functions to output what Q12 asks for
*/
void question12Output(int* array, int size) {
	int* ascendingArr;
	int* ascendingFctPter = &findmin;
	int* descendingArr;
	int* descendingFctPter = &findmax;
	int* minValue;
	int* maxValue;
	float average;
	float sD;

	//outputs array in ascending order
	ascendingArr = selectionsortQ11(array, size, ascendingFctPter);
	printf("Array Sorted in Ascending Order: ");
	for (int i = 0; i < size; i++)
		printf("%d ", ascendingArr[i]);
	printf("\n");

	//outputs array in descending order
	descendingArr = selectionsortInverse(array, size, descendingFctPter);
	printf("Array Sorted in Descending Order: ");
	for (int i = 0; i < size; i++)
		printf("%d ", descendingArr[i]);
	printf("\n");

	//finds the smallest integer in the array
	minValue = findmin(array, size);
	printf("Minimum Value is: %d", *minValue);
	printf("\n");

	//finds the biggest integer in the array
	maxValue = findmax(array, size);
	printf("Maximum Value is: %d", *maxValue);
	printf("\n");

	//finds the avg
	average = findAvg(array, size);
	printf("Average is: %f", average);
	printf("\n");

	//finds the standard deviation
	sD = findSD(array, size);
	printf("Standard Deviation is: %f", sD);
	printf("\n");
}