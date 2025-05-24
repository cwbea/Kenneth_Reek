/*
** Program to copy lines from standard input to standard output.
** Reads input line by line and prints it as-is.
*/

#include <stdio.h>              // For FILE, fgets, fputs, stdin, stdout

#define MAX_LINE_LENGTH 1024   // Define the maximum length of a line to read (buffer size)

/*
** Function: copylines
** --------------------
** Copies all lines from the input file stream to the output file stream.
**
** Parameters:
** - FILE *input:  A pointer to the input stream (e.g., stdin or a file)
** - FILE *output: A pointer to the output stream (e.g., stdout or a file)
**
** This function reads each line using fgets into a buffer and writes it to the output using fputs.
*/
void copylines(FILE *input, FILE *output) {
    char buffer[MAX_LINE_LENGTH];  // Buffer to hold each line read from input

    // Loop until end of file or error: fgets reads a line from input and stores it in buffer
    while (fgets(buffer, MAX_LINE_LENGTH, input) != NULL) {
        // Write the buffer (line) to the output stream
        fputs(buffer, output);
    }
}

/*
** Main function
** -------------
** Demonstrates the use of the copylines function by copying from standard input to standard output.
*/
int main() {
    // Call copylines with stdin (standard input) and stdout (standard output)
    copylines(stdin, stdout);

    return 0; // Return 0 to indicate successful completion
}

