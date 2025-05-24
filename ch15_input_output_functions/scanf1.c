/*
** Line-oriented input processing using sscanf
** Reads lines from a file (or standard input) and attempts to extract 5 integers using sscanf.
** If the number of successfully extracted integers is not 4, it prints an error message and skips that line.
*/

#include <stdio.h>          // For standard I/O functions like fgets, sscanf, fprintf
#define BUFFER_SIZE 100     // Maximum length of line to read (includes space for null terminator)

/*
** Function: process_input_lines
** -----------------------------
** Reads lines from a given FILE stream and attempts to extract five integers from each line.
** If a line doesn't contain exactly 4 integers (as expected), it is considered bad input and skipped.
**
** Parameters:
** - FILE *input: Pointer to the input stream (e.g., stdin or a file)
*/
void process_input_lines(FILE *input) {
    int a, b, c, d, e;              // Variables to store the integers parsed from each line
    char buffer[BUFFER_SIZE];      // Character buffer to hold each line of input

    // Read each line from the input until end of file or error
    while (fgets(buffer, BUFFER_SIZE, input) != NULL) {
        // Try to extract five integers from the line using sscanf
        // If fewer than 4 are found, treat as invalid input
        if (sscanf(buffer, "%d %d %d %d %d", &a, &b, &c, &d, &e) != 4) {
            // Print a warning to stderr if the line didn't have exactly 4 integers
            fprintf(stderr, "Bad input skipped: %s", buffer);
            continue; // Skip to the next line
        }

        // If we get here, we have valid input: exactly 4 integers
        // You can process the values a, b, c, d, e here (e.g., print or store them)
        printf("Processed: %d %d %d %d %d\n", a, b, c, d, e);
    }
}

/*
** Main function
** -------------
** Demonstrates the use of process_input_lines by reading from standard input.
*/
int main() {
    // Call the function using standard input (keyboard or redirected file)
    printf("Enter lines of integers (expecting 5 integers per line, 4 of which will be validated):\n");
    process_input_lines(stdin);

    return 0; // Indicate successful execution
}

