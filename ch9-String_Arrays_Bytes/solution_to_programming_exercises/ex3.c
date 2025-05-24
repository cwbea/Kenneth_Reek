#include <stdio.h>    // For input/output functions like printf
#include <string.h>   // For strlen (used in the example)

// Function: my_strcpy
// Copies a string from 'src' to 'dest', up to 'dest_size - 1' characters,
// and ensures that 'dest' is null-terminated to make it a valid C string.
void my_strcpy(char *dest, const char *src, size_t dest_size) {
    size_t i = 0;  // Counter for indexing characters

    // Copy characters from 'src' to 'dest' until:
    //  - we reach the end of the source string ('\0')
    //  - OR we reach dest_size - 1 (so we leave space for '\0')
    while (i < dest_size - 1 && src[i] != '\0') {
        dest[i] = src[i];  // Copy one character
        i++;               // Move to next index
    }

    dest[i] = '\0';  // Make sure the destination string is null-terminated
}

// Example usage of my_strcpy
int main(void) {
    char src[] = "This is a very long string that could overflow!"; // The source string
    char dest[20];  // Destination array with fixed size (only 20 bytes)

    // Use our safe string copy function to prevent overflow
    my_strcpy(dest, src, sizeof(dest));  // sizeof(dest) gives the size of the array (20)

    // Print the copied result
    printf("Copied string: \"%s\"\n", dest);
    printf("Original length: %lu, Copied length: %lu\n", strlen(src), strlen(dest));

    return 0;  // End of program
}

