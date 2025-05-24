#include <stdio.h>      // For printf
#include <stdlib.h>     // For malloc, free
#include <string.h>     // For memcpy

// The sort function
// This function sorts a generic array using a comparison callback
void sort(void *array,             // Pointer to the array to be sorted
          int n_elements,          // Number of elements in the array
          size_t element_size,     // Size of each element in bytes
          int (*compare)(const void *, const void *)) // Comparison callback
{
    // Cast the void pointer to a char pointer so we can do byte-wise pointer arithmetic
    char *arr = (char *)array;

    // Temporary buffer to hold one element during swap
    char *temp = malloc(element_size);

    // Outer loop: from first element to second last
    for (int i = 0; i < n_elements - 1; i++) {
        // Inner loop: from i+1 to last element
        for (int j = i + 1; j < n_elements; j++) {
            // Calculate the pointers to the ith and jth elements
            char *elem_i = arr + i * element_size;
            char *elem_j = arr + j * element_size;

            // If elem_i > elem_j based on compare function, swap them
            if (compare(elem_i, elem_j) > 0) {
                // Swap elements byte-by-byte using temp buffer
                memcpy(temp, elem_i, element_size);     // temp = elem_i
                memcpy(elem_i, elem_j, element_size);   // elem_i = elem_j
                memcpy(elem_j, temp, element_size);     // elem_j = temp (original elem_i)
            }
        }
    }

    // Free the temporary buffer
    free(temp);
}

// Comparison function for integers (used as a callback)
// Returns negative if a < b, 0 if equal, positive if a > b
int compare_ints(const void *a, const void *b) {
    // Cast input pointers to int pointers and dereference
    int int_a = *(int *)a;
    int int_b = *(int *)b;

    return int_a - int_b;
}

// Comparison function for floats
int compare_floats(const void *a, const void *b) {
    float fa = *(float *)a;
    float fb = *(float *)b;

    if (fa < fb) return -1;
    if (fa > fb) return 1;
    return 0;
}

// Function to print an array of integers
void print_int_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// MAIN function to demonstrate usage of the sort function
int main() {
    // Example: sorting an array of integers
    int nums[] = {42, 17, 8, 99, 5};
    int n = sizeof(nums) / sizeof(nums[0]); // Calculate number of elements

    printf("Before sorting: ");
    print_int_array(nums, n); // Show unsorted array

    // Call generic sort function with integer array and compare_ints callback
    sort(nums, n, sizeof(int), compare_ints);

    printf("After sorting: ");
    print_int_array(nums, n); // Show sorted array

    return 0;
}

