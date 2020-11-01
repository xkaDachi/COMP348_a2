#pragma once

int* findmin(int* arr, int size) {
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
