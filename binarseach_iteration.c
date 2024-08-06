// C program to implement iterative Binary Search
#include <stdio.h>
#include <stdlib.h>
int binarySearch(int arr[], int low, int high, int x)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;
        // If the element is present at the middle
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x) // for left side of an array

            return binarySearch(arr, low, mid - 1, x);
        else // for right side of an array
            return binarySearch(arr, mid + 1, high, x);
    }
    return -1;
}
int main()
{
    int arr[100], brr[1000], crr[10000];
    int n = sizeof(arr) / sizeof(arr[0]);
    int n1 = sizeof(brr) / sizeof(brr[0]);
    int n2 = sizeof(crr) / sizeof(crr[0]);
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
    }
    for (int i = 0; i < n1; i++)
    {
        brr[i] = rand();
    }
    for (int i = 0; i < n2; i++)
    {
        crr[i] = rand();
    }
    int x = 10;
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
        printf("Element is not present in array");
    else
        printf("Element is present at index %d", result);
    int result1 = binarySearch(brr, 0, n1 - 1, x);
    if (result1 == -1)
        printf("Element is not present in array");
    else
        printf("Element is present at index %d", result1);
    int result2 = binarySearch(crr, 0, n2 - 1, x);
    if (result2 == -1)
        printf("Element is not present in array");
    else
        printf("Element is present at index %d", result2);
    return 0;
}
