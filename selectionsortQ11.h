#pragma once
#include "findmin.h"

/*
* findMin declaration.
* receives a third argument, a pointer
* to a "min" function, that is to be called by the sort implementation
*/
int* selectionsortQ11(int* array, int size, int* (*findminPtr)(int* arr, int size));
