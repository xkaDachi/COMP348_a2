#pragma once
#include "selectionsortQ11.h"
/*
* findMin definition with 3 arguments
* In case the pointer is NULL,
* the default function (the original findmin) is to be called.
*/
int* selectionsortQ11(int* array, int size, int* (*findminPtr)(int* arr, int size)) {
    int* minPtr;
    int temp;
    int indexMin = 0;
    int indexCurrent = 0;
    int originalSize = size;

    //If it's a NULL function pointer
    if (findminPtr == 0) {
        while (size != 0) {

            minPtr = findmin(array, size);

            for (int i = 0; i < size; i++) {
                if (&array[i] == minPtr) {
                    indexMin = i;
                }
            }
            temp = array[indexCurrent];
            array[indexCurrent] = array[indexMin];
            array[indexMin] = temp;
            array = array + 1;
            size--;
        }
        return array = array - originalSize;
    }
    //else is not a NULL function pointer
    else {
        while (size != 0) {

            for (int i = 0; i < size; i++) {
                if (&array[i] == findminPtr) {
                    indexMin = i;
                }
            }
            temp = array[indexCurrent];
            array[indexCurrent] = array[indexMin];
            array[indexMin] = temp;
            array = array + 1;
            size--;
        }
        return array = array - originalSize;
    }
}