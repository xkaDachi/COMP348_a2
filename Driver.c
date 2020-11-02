#pragma once
#include <stdio.h>
#include "Q9.h"
#include "Q10.h"
#include "Q11.h"
#include "Q12.h"
#include "Q13.h"

int main() {
    
    //Question Q9
    printf("Question 9: \n");
    int arr[] = { 1, 4, 5, 6, -1 };
    int* m = findmin(arr, 5);
    printf("%d", *m); // -1

    printf("\n");

   //Question 10
    printf("Question 10: \n");
   int i;
   selectionSort(arr, 5);
   for (i = 0; i < 5; i++) 
     printf("%d ", arr[i]);

   printf("\n");

   //Question 11
   printf("Question 11: \n");
   int arr2[] = { 1, 4, 5, 6, -1 };
   int* aFctPtr = NULL;
   int* aPtr;
   aPtr = selectionSortQ11(arr2, 5, aFctPtr);
   for (i = 0; i < 5; i++)
       printf("%d", aPtr[i]);

   aFctPtr = &findmin;
   aPtr = selectionSortQ11(arr2, 5, aFctPtr);
   for (i = 0; i < 5; i++)
       printf(" %d", aPtr[i]);

   printf("\n");

   //Question 12
   printf("Question 12: \n");
   int* dynamicArray;
   dynamicArray = (int*)malloc(sizeof(int) * 5);      // allocate 5 ints
   dynamicArray[0] = 1;
   dynamicArray[1] = 4;
   dynamicArray[2] = 5;
   dynamicArray[3] = 6;
   dynamicArray[4] = -1;
   question12Function(dynamicArray, 5);
   //delete dynamic array here...
   dynamicArray = NULL;

   printf("\n");

   //Question 13
   //stores each word
   char word[MAX] = { '\0' };
   //stores a pointer to the 1st node in the linked list
   NodePointer head = NULL;
   //keep inserting until user enters "quit"
   while (0 != strcmp(word, QUIT)) {
       printf("Enter a word to INSERT into linked list (enter \"%s\" to quit): ", QUIT);
       getline2(word, MAX);
       if (0 != strcmp(word, QUIT)) {
           //&head: send the address of the pointer to the 1st node in list
           insert_dictionary_order(word, &head);
           print_list(head);
       }
   }//end of while

    return 0;
}
