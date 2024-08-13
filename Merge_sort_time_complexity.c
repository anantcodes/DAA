#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to merge two subarrays
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// Function to measure the time taken by Merge Sort
double measureTime(int arr[], int n) {
    clock_t start, end;
    start = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

// Function to generate a random array
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;
    }
}

int main() {
    int sizes[] = {100, 1000, 10000, 100000};
    int nSizes = sizeof(sizes) / sizeof(sizes[0]);

    printf("%-10s %-20s %-10s\n", "Array Size", "Observed Time (s)", "Theoretical O(n log n)");

    for (int i = 0; i < nSizes; i++) {
        int n = sizes[i];
        int arr[n];
        generateRandomArray(arr, n);

        double elapsedTime = measureTime(arr, n);
        double nLogN = n * (log(n) / log(2)); // Calculating n * log2(n)

        printf("%-10d %-20lf %-20lf\n", n, elapsedTime, nLogN);
    }

    return 0;
}
