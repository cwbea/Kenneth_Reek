#include <stdio.h>      // For standard input/output functions
#include <ctype.h>      // For isspace(), which checks for whitespace characters

// Function to remove extra whitespace and leave only single spaces between words
void deblank(char string[]) {
    int read = 0;       // Index for reading characters from the original string
    int write = 0;      // Index for writing characters to remove extra spaces
    int in_space = 0;   // Flag to track if we're currently inside a run of spaces

    // Loop through the string until we hit the null terminator '\0'
    while (string[read] != '\0') {

        // Check if the current character is a whitespace (space, tab, newline, etc.)
        if (isspace((unsigned char)string[read])) {
            // If we're not already in a space block, write one space to the result
            if (!in_space) {
                string[write++] = ' ';  // Write one space character
                in_space = 1;           // Set the flag to indicate we're in a space run
            }
            // If we're already in a space block, skip writing this character
        } else {
            // If it's not a space, write it to the output position
            string[write++] = string[read];
            in_space = 0;  // We're no longer in a space block
        }

        read++; // Move to the next character
    }

    // If the last character written was a space, remove it (trim trailing space)
    if (write > 0 && string[write - 1] == ' ') {
        write--; // Decrease write index to overwrite the trailing space
    }

    // Add the null terminator at the end to complete the cleaned-up string
    string[write] = '\0';
}

