#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

/*
* selectionSort declaration.
*/
void selectionsort(int* array, int size);

/*
* findMin declaration.
* receives a third argument, a pointer
* to a "min" function, that is to be called by the sort implementation
*/
int* selectionsortQ11(int* array, int size, int* (*findminPtr)(int* arr, int size));

#endif