#include <stdio.h>

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

int main()
{
    int arr[] = { 1, 4, 5, 6, -1 };
    int* m = findmin(arr, 5);
    printf("%d", *m); // -1

    return 0;
}
