#pragma once
#include <math.h>
#include "Q9.h"
#include "Q10.h"
#include "Q11.h"

//Find the biggest Value
int* findmax(int* arr, int size) {
    int biggestAddress = &arr[0];
    int biggestValue = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > biggestValue) {
            biggestAddress = &arr[i];
            biggestValue = arr[i];
        }
    }
    return biggestAddress;
}

//Sort by Descending Order
int* selectionSortQ11Inverse(int* array, int size, int* (*findminPtr)(int* arr, int size)) {
	int* maxPtr;
	int temp;
	int indexMax = 0;
	int indexCurrent = 0;
	int originalSize = size;

	if (findminPtr == NULL) {
		return maxPtr = findmax(array, size);
	}
	else {
		while (size != 0) {

			maxPtr = findmax(array, size);

			for (int i = 0; i < size; i++) {
				if (&array[i] == maxPtr) {
					indexMax = i;
				}
			}
			temp = array[indexCurrent];
			array[indexCurrent] = array[indexMax];
			array[indexMax] = temp;
			array = array + 1;
			size--;
		}
		return array = array - originalSize;
	}
}

//Calculates Average
float findAvg(int* array, int size) {

	float avg = 0;

	for (int i = 0; i < size; i++) {
		avg = avg + array[i];
	}
	avg = avg / size;
	return avg;
}

//Calculates Standard Deviation
float findSD(int* array, int size) {
	float sum = 0.0, mean, SD = 0.0;
	int i;
	for (i = 0; i < size; ++i) {
		sum += array[i];
	}
	mean = sum / size;
	for (i = 0; i < size; ++i)
		SD += pow(array[i] - mean, 2);
	return sqrt(SD / size);
}

//Function for question 12
void question12Function(int* array, int size) {
	int* ascendingArr;
	int* ascendingFctPter = &findmin;
	int* descendingArr;
	int* descendingFctPter = &findmax;
	int* minValue;
	int* maxValue;
	float average;
	float sD;

	ascendingArr = selectionSortQ11(array, size, ascendingFctPter);
	printf("Array Sorted in Ascending Order: ");
	for (int i = 0; i < size; i++)
		printf("%d ", ascendingArr[i]);
	printf("\n");

	descendingArr = selectionSortQ11Inverse(array, size, descendingFctPter);
	printf("Array Sorted in Descending Order: ");
	for (int i = 0; i < size; i++)
		printf("%d ", descendingArr[i]);
	printf("\n");

	minValue = findmin(array, size);
	printf("Minimum Value is: %d", *minValue);
	printf("\n");

	maxValue = findmax(array, size);
	printf("Maximum Value is: %d", *maxValue);
	printf("\n");

	average = findAvg(array, size);
	printf("Average is: %f", average);
	printf("\n");

	sD = findSD(array, size);
	printf("Standard Deviation is: %f", sD);
	printf("\n");
}