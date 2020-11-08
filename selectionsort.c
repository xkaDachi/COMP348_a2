#pragma once
#include "selectionsort.h"

/*
* selectionSort definition.
*/
void selectionsort(int* array, int size) {
    int* minPtr;
    int temp;
    int indexMin = 0;
    int indexCurrent = 0;
    //iteration through the whole list/array
    while (size != 0) {
        //finds pointer to the smallest value
        minPtr = findmin(array, size);
        //finds index of smallest value given by findmin()
        for (int i = 0; i < size; i++) {
            if (&array[i] == minPtr) {
                indexMin = i;
            }
        }
        //swapping occurs
        temp = array[indexCurrent];
        array[indexCurrent] = array[indexMin];
        array[indexMin] = temp;
        //to be used in the next iteration of selectionsort
        array = array + 1;
        size--;
    }
}