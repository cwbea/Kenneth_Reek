#include <stdio.h>
#include <stdarg.h>  // For va_list and related functions

// Function to find the largest integer in a list of integers
int max_list(int first, ...) {
    va_list args;  // Declare a variable to store the list of arguments
    int max = first;  // Initialize max with the first argument

    va_start(args, first);  // Initialize the va_list to process arguments

    int current = first;
    
    // Loop through the remaining arguments until a negative value is encountered
    while ((current = va_arg(args, int)) >= 0) {
        if (current > max) {  // If the current argument is larger than max, update max
            max = current;
        }
    }

    va_end(args);  // Clean up the va_list

    return max;  // Return the largest value found
}

int main() {
    // Sample usage of the max_list function
    int largest = max_list(3, 5, 7, 2, 9, -1);  // The list ends with -1

    printf("The largest number is: %d\n", largest);  // Should print 9

    return 0;
}

