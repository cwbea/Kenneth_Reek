#include <stdio.h>   // For printf, scanf
#include <stdlib.h>  // For malloc, realloc

// Function to read integers from input and store them in a dynamic array
// The first element of the returned array contains the count
int *read_int_list() {
    int *array = NULL;        // Pointer to the array of integers
    int capacity = 10;        // Initial capacity of the array
    int count = 0;            // Number of integers read (excluding the count itself)
    int value;                // Variable to hold each input value

    // Allocate initial memory with room for count + 10 integers
    array = malloc(sizeof(int) * (capacity + 1)); // +1 for the count at index 0
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    // Reserve index 0 for the count, start storing values from index 1
    while (scanf("%d", &value) == 1) { // Read integers until EOF
        if (count >= capacity) {
            // Need more space, so double the capacity
            capacity *= 2;
            int *temp = realloc(array, sizeof(int) * (capacity + 1));
            if (temp == NULL) {
                printf("Memory reallocation failed.\n");
                free(array);
                return NULL;
            }
            array = temp;
        }

        // Store the value in the array at index (count + 1)
        array[count + 1] = value;
        count++;
    }

    // Store the count in the first element
    array[0] = count;

    // Return the pointer to the array
    return array;
}

// Example usage
int main() {
    printf("Enter integers (Ctrl+D or Ctrl+Z to end):\n");

    int *list = read_int_list(); // Get the dynamically allocated array
    if (list == NULL) return 1;

    int count = list[0]; // First element holds the count
    printf("You entered %d values:\n", count);
    for (int i = 1; i <= count; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    free(list); // Free the dynamically allocated memory
    return 0;
}

