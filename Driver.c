#pragma once
#include <stdio.h>
#include "Q9.h"
#include "Q10.h"
#include "Q11.h"
#include "Q12.h"

int main() {
    
    //Question Q9
    int arr[] = { 1, 4, 5, 6, -1 };
    int* m = findmin(arr, 5);
    printf("%d", *m); // -1

    printf("\n");

   //Question 10
   int i;
   selectionSort(arr, 5);
   for (i = 0; i < 5; i++) 
     printf("%d ", arr[i]);

   printf("\n");

   //Question 11
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
   //testing functions
   int arr3[] = { 1, 4, 5, 6, -1 };
   int* n = findmax(arr3, 5);
   printf("%d ", *n); // 6

   float average = findAvg(arr3, 5);
   printf("%f ", average);

   aFctPtr = &findmax;
   aPtr = selectionSortQ11Inverse(arr3, 5, aFctPtr);
   for (i = 0; i < 5; i++)
       printf(" %d", aPtr[i]);

   //actual Q12
   int* dynamicArray;
   dynamicArray = (int*)malloc(sizeof(int) * 5);      // allocate 5 ints
   dynamicArray[0] = 1;
   dynamicArray[1] = 4;
   dynamicArray[2] = 5;
   dynamicArray[3] = 6;
   dynamicArray[4] = -1;
   printf("\n");
   question12Function(dynamicArray, 5);
   //delete dynamic array here...
   dynamicArray = NULL;

   printf("\n");

   //Question 13
   //something goes here

    return 0;
}
