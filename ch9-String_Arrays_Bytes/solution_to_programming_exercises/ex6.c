#include <stdio.h>   // For printf

// Function: my_strcpy_end
// Copies the 'src' string into the 'dest' buffer,
// and returns a pointer to the null byte at the end of the copied string.
char *my_strcpy_end(char *dest, const char *src) {
    char *p = dest;  // Pointer used to iterate and write into dest

    // Copy characters from src to dest one by one until we hit the null terminator
    while (*src != '\0') {
        *p = *src;  // Copy current character
        p++;        // Move destination pointer forward
        src++;      // Move source pointer forward
    }

    *p = '\0';  // Add the final null byte to terminate the string

    return p;   // Return pointer to the null byte at the end of dest
}

// Example usage of my_strcpy_end
int main(void) {
    char dest[50];                  // Destination buffer to hold the copied string
    const char *src = "Hello, C!";  // Source string to be copied
    char *end_ptr;                  // Will store the pointer to the end of the copied string

    // Call our function and store the pointer to the end of the copied string
    end_ptr = my_strcpy_end(dest, src);

    // Print the copied string and the distance from the start to the returned pointer
    printf("Copied string: \"%s\"\n", dest);
    printf("End pointer is %ld bytes after dest\n", end_ptr - dest);

    return 0;  // End of program
}

