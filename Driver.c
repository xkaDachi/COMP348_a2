#include <stdio.h>
#include "selectionsort.h" //#include "selectionsort.h"
#include "selectionsort.h" //#include "selectionsort.h" // included twice
#include <math.h>
#include "Q13.h"

//									 --------------------------
//									 |  FUNCTION DECLARATIONS |
//									 --------------------------
/*
* findmin declaration for Q9
*/
int* findminQ9(int* arr, int size);

//										-----------------
//										| MAIN FUNCTION |
//										-----------------
//----------------------------------------------------------------------------------------------------l
int main() {
    
    //Question Q9
    printf("Question 9: \n");
    int arr[] = { 1, 4, 5, 6, -1 };
    int* m = findminQ9(arr, 5);
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
   aPtr = selectionsortQ11(arr2, 5, aFctPtr); //Null Pointer
   for (i = 0; i < 5; i++)
       printf("%d ", aPtr[i]);

   printf("\n");

   aFctPtr = &findminQ9;
   aPtr = selectionsortQ11(arr2, 5, aFctPtr); //Non-Null Pointer
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
   //stores a pointer to the 1st node in the dictionary linked list
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

//								 --------------------------
//								 |  FUNCTION DEFINITIONS  |
//								 --------------------------
/*
* findminQ9 definition, TO SHOW FOR DEMO
* Q10 and onwards will use the one defined in selection.c (Internal)
* receives an array of integers and returns a pointer to its smallest element
*/
int* findminQ9(int* arr, int size) {
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