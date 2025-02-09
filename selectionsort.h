#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <math.h>

/*
* findmin declaration for Q10, 
* INTERNAL LINKAGE.
* EITHER STATIC OR NO DECLARATION IN .H
*/
static int* findminQ10(int* arr, int size);

/*
* selectionSort declaration.
*/
void selectionsort(int* array, int size);

/*
* findMin declaration.
* receives a third argument, a pointer
* to a "min" function, that is to be called by the sort implementation
*/
void selectionsortQ11(int* array, int size, void* (*findminPtr)(int* arr, int size));

/*
* function declaration for Q12 (local functions).
* read an array of n integers, sorts them in both ascending and descending order,
* and prints the sorted arrays, along with the minimum, maximum, average, and the standard deviation
* findmax function is to be implemented locally in the main program.
* INTERNAL LINKAGE FOR ALL EXCEPT question12Output BELOW EITHER STATIC OR NO DECLARATION IN .H
*/
void question12Output(int* array, int size); //will call all functions below
static int* findmax(int* arr, int size); //and findmin is in Q9 files.
static void selectionsortInverse(int* array, int size, void* (*findminPtr)(int* arr, int size)); //and selectionsortQ11 is in Q11 files
static float findAvg(int* array, int size);
static float findSD(int* array, int size);

#endif