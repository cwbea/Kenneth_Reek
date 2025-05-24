#include <stdio.h>      // For standard input/output functions
#include <string.h>     // For string comparison and tokenizing
#include <ctype.h>      // For character case functions like tolower

#define MAX_LINE 100    // Define the maximum input line length

// This function converts a string to lowercase (modifies it in place)
void to_lowercase(char *str) {
    while (*str) {
        *str = tolower(*str); // Convert each character to lowercase
        str++;
    }
}

int main() {
    char line[MAX_LINE];       // Array to store each input line
    int the_count = 0;         // Counter for the number of "the" words

    // Read lines from standard input until end-of-file (Ctrl+D in Linux)
    while (fgets(line, sizeof(line), stdin)) {
        to_lowercase(line);    // Convert the line to lowercase for case-insensitive comparison

        // Break the line into words using space/tab/newline as delimiters
        char *word = strtok(line, " \t\n");

        // Loop through each word in the line
        while (word != NULL) {
            if (strcmp(word, "the") == 0) {
                the_count++;   // If word is exactly "the", increment the counter
            }
            word = strtok(NULL, " \t\n"); // Move to the next word
        }
    }

    // Print the final count
    printf("The word \"the\" appeared %d times.\n", the_count);

    return 0; // Exit the program
}

