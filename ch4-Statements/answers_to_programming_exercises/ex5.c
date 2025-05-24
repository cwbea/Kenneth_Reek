#include <stdio.h>      // For input and output functions like printf and fgets
#include <string.h>     // For string functions like strcmp, strcpy, and strcspn

#define MAX_LEN 128     // Define the maximum length of each input line (including newline)

// Main function - where the program starts execution
int main(void) {
    char prev[MAX_LEN] = "";  // Store the previous line read, initialized to an empty string
    char curr[MAX_LEN];       // Store the current line being read
    int duplicate = 0;        // Flag to track if we are in a group of duplicate lines

    // Loop to read each line from standard input
    while (fgets(curr, MAX_LEN, stdin) != NULL) {
        // Remove the newline character at the end of the line, if it exists
        curr[strcspn(curr, "\n")] = '\0';

        // Compare the current line with the previous one
        if (strcmp(curr, prev) == 0) {
            // If the lines are the same, mark that we found a duplicate
            duplicate = 1;
        } else {
            // If the current line is different and we were in a duplicate group before
            if (duplicate) {
                printf("%s\n", prev);  // Print the previous line only once
                duplicate = 0;         // Reset the duplicate flag
            }
        }

        // Update previous line to be the current line for next comparison
        strcpy(prev, curr);
    }

    // After the loop, check if the last lines were duplicates
    // If so, print the last duplicate line
    if (duplicate) {
        printf("%s\n", prev);
    }

    return 0;  // End of program
}

