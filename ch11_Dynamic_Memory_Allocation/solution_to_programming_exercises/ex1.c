#include <stdio.h>   // For printf (optional for testing)
#include <stdlib.h>  // For malloc
#include <string.h>  // For memset

// my_calloc: Allocate memory for an array and initialize it to zero
void *my_calloc(size_t num_elements, size_t element_size) {
    // Calculate the total number of bytes needed
    size_t total_size = num_elements * element_size;

    // Use malloc to allocate the required memory
    void *ptr = malloc(total_size);

    // Check if malloc succeeded
    if (ptr == NULL) {
        // Return NULL if memory allocation failed
        return NULL;
    }

    // Use memset to set all bytes in the memory block to 0
    // This mimics the zero-initialization behavior of calloc
    memset(ptr, 0, total_size);

    // Return the pointer to the allocated and zeroed memory
    return ptr;
}

// Example usage of my_calloc
int main() {
    int i;
    int n = 5;

    // Allocate an array of 5 integers using my_calloc
    int *arr = (int *)my_calloc(n, sizeof(int));

    // Check if allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Print the initialized array values (should all be 0)
    for (i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    // Free the allocated memory
    free(arr);

    return 0;
}

