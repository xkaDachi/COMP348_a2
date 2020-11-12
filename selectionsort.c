#include "selectionsort.h"

/*
* findminQ10 definition. 
* INTERNAL LINKAGE.
* receives an array of integers and returns a pointer to its smallest element
*/
static int* findminQ10(int* arr, int size) {
    int smallestAddress = &arr[0];
    int smallestValue = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < smallestValue) {
            smallestAddress = &arr[i];
            smallestValue = arr[i];
        }
    }
    return smallestAddress;
}

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
        minPtr = findminQ10(array, size);
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
    if (findminPtr == NULL) {
        while (size != 0) {

            minPtr = findminQ10(array, size);

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

/*
* findmax definition.
* receives an array of integers and returns a pointer to its biggest element
*/
static int* findmax(int* arr, int size) {
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

/*
* SelectionSort, biggest to smallest. Hence, inverse.
*/
static int* selectionsortInverse(int* array, int size, int* (*findminPtr)(int* arr, int size)) {
	int* maxPtr;
	int temp;
	int indexMax = 0;
	int indexCurrent = 0;
	int originalSize = size;

	if (findminPtr == 0) {
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

/*
* findAvg definition.
* Takes an array and its size and
* the avg of all the numbers of the array
*/
static float findAvg(int* array, int size) {

	float avg = 0;

	for (int i = 0; i < size; i++) {
		avg = avg + array[i];
	}
	avg = avg / size;
	return avg;
}

/*
* findSD definition.
* finds the standard deviation from a given array and its size
*/
static float findSD(int* array, int size) {
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

/*
* question12Output definition.
* calls all other helper functions to output what Q12 asks for
* can be exported
*/
void question12Output(int* array, int size) {
	int* ascendingArr;
	int* ascendingFctPter = &findminQ10;
	int* descendingArr;
	int* descendingFctPter = &findmax;
	int* minValue;
	int* maxValue;
	float average;
	float sD;

	//outputs array in ascending order
	ascendingArr = selectionsortQ11(array, size, ascendingFctPter);
	printf("Array Sorted in Ascending Order: ");
	for (int i = 0; i < size; i++)
		printf("%d ", ascendingArr[i]);
	printf("\n");

	//outputs array in descending order
	descendingArr = selectionsortInverse(array, size, descendingFctPter);
	printf("Array Sorted in Descending Order: ");
	for (int i = 0; i < size; i++)
		printf("%d ", descendingArr[i]);
	printf("\n");

	//finds the smallest integer in the array
	minValue = findminQ9(array, size);
	printf("Minimum Value is: %d", *minValue);
	printf("\n");

	//finds the biggest integer in the array
	maxValue = findmax(array, size);
	printf("Maximum Value is: %d", *maxValue);
	printf("\n");

	//finds the avg
	average = findAvg(array, size);
	printf("Average is: %f", average);
	printf("\n");

	//finds the standard deviation
	sD = findSD(array, size);
	printf("Standard Deviation is: %f", sD);
	printf("\n");
}