#include <stdio.h>      // Includes standard input/output functions like printf
#include <string.h>     // Includes string handling functions like strlen

// Function to extract a substring from a given string
// Parameters:
//   dst   - destination array to store the substring
//   src   - source string from which to extract the substring
//   start - starting position (index) in src to begin copying
//   len   - number of characters to copy
int substr(char dst[], char src[], int start, int len) {
    int i;  // Loop variable to track how many characters we copy

    // Step 1: Check if the inputs are valid
    // Invalid if start or len is negative, or start is beyond the end of the source string
    if (start < 0 || len < 0 || start >= strlen(src)) {
        dst[0] = '\0';  // Set the destination string to be empty
        return 0;       // Return 0 to indicate nothing was copied
    }

    // Step 2: Copy up to 'len' characters from src, starting at position 'start'
    // Make sure not to go past the end of the source string (check for '\0')
    for (i = 0; i < len && src[start + i] != '\0'; i++) {
        dst[i] = src[start + i];  // Copy character from src to dst
    }

    dst[i] = '\0';  // Step 3: Add null terminator to end the string properly

    return i;  // Step 4: Return the number of characters copied into dst
}

