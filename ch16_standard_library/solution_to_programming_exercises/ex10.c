#include <stdio.h>      // For printf (for optional testing)
#include <stdlib.h>     // For malloc, free, and size_t
#include <string.h>     // For memcpy, memmove

// insertion_sort replicates the behavior of qsort using insertion sort logic
// Parameters:
// - base: pointer to the first element of the array (generic pointer)
// - nitems: number of elements in the array
// - size: size of each element in bytes
// - cmp: a function pointer used to compare two elements
void insertion_sort(void *base, size_t nitems, size_t size,
                    int (*cmp)(const void *, const void *)) {

    // Cast the base pointer to a char pointer so we can do byte arithmetic
    char *array = (char *)base;

    // Allocate memory for a temporary buffer to hold elements during shifting
    char *key = malloc(size);
    if (!key) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    // Loop over each element from the second to the last
    for (size_t i = 1; i < nitems; ++i) {
        // Copy the i-th element into key (the element to be inserted)
        memcpy(key, array + i * size, size);

        // j will track the current index to compare in the sorted portion
        size_t j = i;

        // Shift elements to the right to make space for key
        while (j > 0 && cmp(key, array + (j - 1) * size) < 0) {
            // Move the element at position j - 1 to position j
            memmove(array + j * size, array + (j - 1) * size, size);
            j--;
        }

        // Insert the key element in its correct sorted position
        memmove(array + j * size, key, size);
    }

    // Free the temporary buffer
    free(key);
}

// Example comparator function for integers (ascending order)
int int_compare(const void *a, const void *b) {
    // Cast the void pointers to int pointers and compare the values
    int int_a = *(const int *)a;
    int int_b = *(const int *)b;

    // Return negative if a < b, 0 if a == b, positive if a > b
    return int_a - int_b;
}

// Optional main function to test the insertion_sort function
int main() {
    int numbers[] = {5, 2, 9, 1, 5, 6};
    size_t size = sizeof(numbers) / sizeof(numbers[0]);

    // Call our insertion_sort function
    insertion_sort(numbers, size, sizeof(int), int_compare);

    // Print sorted array
    printf("Sorted array: ");
    for (size_t i = 0; i < size; ++i) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}

