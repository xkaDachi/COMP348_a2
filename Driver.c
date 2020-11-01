#pragma once
#include <stdio.h>
#include "Q9.h"
#include "Q10.h"

int arr[] = { 1, 4, 5, 6, -1 };

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
  


    return 0;
}