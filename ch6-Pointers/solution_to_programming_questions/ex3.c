#include <stdio.h>


void reverse_string(char *string) {
    // Check for NULL pointer (invalid input)
    if (string == NULL) return;

    // Create two pointers: one at the beginning, one at the end
    char *start = string;        // start points to the first character
    char *end = string;          // end will move to the last character

    // Move 'end' to point to the null terminator at the end of the string
    while (*end != '\0') {
        end++;  // walk to the end
    }

    end--;  // step back to the last actual character (not '\0')

    // Swap characters from start and end, and move pointers inward
    while (start < end) {
        // Swap characters pointed to by start and end
        char temp = *start;
        *start = *end;
        *end = temp;

        // Move start forward and end backward
        start++;
        end--;
    }
}

