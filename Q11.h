#pragma once
#include "Q9.h" //to use findmin()

int* selectionSortQ11(int* array, int size, int* (*findminPtr)(int* arr, int size)) {
	int* minPtr;
	int temp;
	int indexMin = 0;
	int indexCurrent = 0;
	int originalSize = size;

	if (findminPtr == NULL) {
		return minPtr = findmin(array, size);
	}
	else {
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
}