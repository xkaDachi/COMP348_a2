#pragma once
#include <stdio.h>
#include "Q9.h"
#include "Q10.h"
#include "Q11.h"

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
   //something goes here

   printf("\n");

   //Question 13
   //something goes here

    return 0;
}
