#include <stdio.h>  // Include standard input/output functions

#define MAX_LINE_LENGTH 81  // Max characters per line (80 + 1 for '\0')

int main(void) {
    char line[MAX_LINE_LENGTH];  // Buffer to store one line of input, including newline and '\0'

    // Read lines from standard input until EOF is reached
    while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
        // Write the entire line to standard output
        fputs(line, stdout);
    }

    return 0;  // Successful program termination
}

