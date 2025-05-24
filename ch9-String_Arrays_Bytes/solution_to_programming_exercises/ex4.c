#include <stdio.h>    // For printf
#include <string.h>   // For strlen

// Function: my_strcat
// Safely appends the string in 'src' to the end of 'dest',
// ensuring the result doesn't exceed 'dest_size' and is null-terminated.
void my_strcat(char *dest, const char *src, size_t dest_size) {
    size_t dest_len = 0;  // This will store the length of the destination string
    size_t i = 0;         // Index for iterating over characters in 'src'

    // Find current length of dest (up to dest_size to avoid reading beyond array)
    while (dest_len < dest_size && dest[dest_len] != '\0') {
        dest_len++;  // Count characters until we find the null terminator
    }

    // Append characters from src to dest until:
    //  - we reach the end of src
    //  - OR we reach the maximum safe size in dest (leaving room for '\0')
    while (dest_len + i < dest_size - 1 && src[i] != '\0') {
        dest[dest_len + i] = src[i];  // Copy character from src to the end of dest
        i++;  // Move to the next character
    }

    // Make sure the final string is null-terminated
    dest[dest_len + i] = '\0';
}

// Example usage of my_strcat
int main(void) {
    char dest[30] = "Hello";  // Destination buffer, initialized with a short string
    const char *src = ", world! Welcome to C.";  // Source string to append

    // Use the safe my_strcat to append 'src' to 'dest' without overflowing
    my_strcat(dest, src, sizeof(dest));

    // Print the final result
    printf("Concatenated string: \"%s\"\n", dest);

    return 0;  // End of program
}

