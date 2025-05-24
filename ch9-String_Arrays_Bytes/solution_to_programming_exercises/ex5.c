#include <stdio.h>    // For printf
#include <string.h>   // For strlen (used in example)

// Function: my_strncat
// Safely appends the 'src' string to the end of 'dest',
// without exceeding the 'dest_len' buffer size, and ensures null termination.
void my_strncat(char *dest, char *src, int dest_len) {
    int dest_index = 0;  // Index to find the current end of 'dest'
    int i = 0;           // Index to loop through 'src'

    // First, find the current length of the destination string (up to dest_len)
    while (dest_index < dest_len && dest[dest_index] != '\0') {
        dest_index++;  // Move to the next character in 'dest'
    }

    // Append characters from 'src' to 'dest'
    // Make sure we don't exceed dest_len - 1 (leave space for '\0')
    while (dest_index < dest_len - 1 && src[i] != '\0') {
        dest[dest_index] = src[i];  // Copy character from 'src' to 'dest'
        dest_index++;  // Move to the next position in 'dest'
        i++;           // Move to the next character in 'src'
    }

    // Always null-terminate the result to make it a valid string
    if (dest_index < dest_len) {
        dest[dest_index] = '\0';
    } else {
        // In the rare case that dest_index == dest_len (full),
        // overwrite the last byte just to ensure null-termination
        dest[dest_len - 1] = '\0';
    }
}

// Example usage of my_strncat
int main(void) {
    char dest[25] = "Good ";  // Destination buffer with initial content
    char src[] = "morning! Hope you're well.";  // String to append

    // Call our safe concatenation function
    my_strncat(dest, src, sizeof(dest));  // Append safely within the buffer size

    // Print the result
    printf("Concatenated string: \"%s\"\n", dest);

    return 0;  // End of program
}

