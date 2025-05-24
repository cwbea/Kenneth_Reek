#include <stdio.h>    // For getchar, printf
#include <stdlib.h>   // For malloc, realloc, free

// Function to read an unlimited-length string from stdin
// Returns a pointer to a dynamically allocated string
char *read_string() {
    int capacity = 10;              // Initial capacity of the string buffer
    int length = 0;                 // Current length of the string
    char *str = malloc(capacity);  // Allocate initial memory

    if (str == NULL) {
        printf("Initial memory allocation failed.\n");
        return NULL;
    }

    int ch;  // Character variable to hold each input character

    // Read characters one at a time until newline or EOF
    while ((ch = getchar()) != '\n' && ch != EOF) {
        // If buffer is full, double the capacity
        if (length + 1 >= capacity) {  // +1 to leave room for the null terminator
            capacity *= 2;
            char *temp = realloc(str, capacity);
            if (temp == NULL) {
                printf("Memory reallocation failed.\n");
                free(str);
                return NULL;
            }
            str = temp;
        }

        // Store the character in the buffer
        str[length++] = ch;
    }

    str[length] = '\0';  // Add null terminator to mark end of string
    return str;          // Return the dynamically allocated string
}

// Example usage
int main() {
    printf("Enter a string: ");

    char *input = read_string();  // Call function to read input
    if (input == NULL) return 1;  // Exit if allocation failed

    printf("You entered: %s\n", input);

    free(input);  // Free the dynamically allocated memory
    return 0;
}

