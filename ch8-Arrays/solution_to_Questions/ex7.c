#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000  // Array size of several thousand elements

// Function 1: Using array indexing
int try1(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

// Function 2: Using pointer arithmetic
int try2(int *arr, int n) {
    int sum = 0;
    while (n--) {
        sum += *arr++;
    }
    return sum;
}

int main() {
    int *arr = (int *)malloc(SIZE * sizeof(int));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i + 1;  // Initialize the array with values
    }

    // Timing variables
    clock_t start, end;
    double time_taken;

    // Run test without optimization
    printf("Running without optimization:\n");
    start = clock();
    for (int i = 0; i < 1000; i++) {
        try1(arr, SIZE);
        try2(arr, SIZE);
    }
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Total time: %f seconds\n", time_taken);

    // Run test with optimization
    printf("Running with optimization (gcc -O2):\n");
    start = clock();
    for (int i = 0; i < 1000; i++) {
        try1(arr, SIZE);
        try2(arr, SIZE);
    }
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Total time: %f seconds\n", time_taken);

    free(arr);
    return 0;
}

