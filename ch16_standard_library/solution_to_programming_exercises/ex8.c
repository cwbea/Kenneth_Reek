#include <stdio.h>    // For file I/O functions: fopen, fgets, fclose, printf
#include <stdlib.h>   // For atoi, exit
#include <string.h>   // For strtok, strcpy

#define MAX_LINE_LENGTH 512   // Maximum length of a line we can read from the file

int main(int argc, char *argv[]) {
    char line[MAX_LINE_LENGTH];       // Buffer to store one line from the file
    char line_copy[MAX_LINE_LENGTH];  // Copy of the line to print after processing
    int age;        // Variable to hold each age parsed from the line
    int total;      // Total sum of ages for current family
    int count;      // Number of members in the current family
    char *token;    // Used to walk through each word (age) in the line
    FILE *file;     // Pointer to the file to read from

    // Make sure the user provides a file name as a command-line argument
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]); // Print usage if incorrect
        return 1; // Exit with error code
    }

    // Try to open the file for reading
    file = fopen(argv[1], "r");

    // Check if the file opened successfully
    if (file == NULL) {
        perror("Error opening file"); // Show system error message
        return 1; // Exit with error code
    }

    // Read each line from the file
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        strcpy(line_copy, line); // Save a copy of the original line for printing later

        total = 0;   // Reset total sum of ages for this family
        count = 0;   // Reset number of members in this family

        // Start breaking up the line using space, tab, or newline as delimiters
        token = strtok(line, " \t\n");

        // Continue parsing as long as we have tokens
        while (token != NULL) {
            age = atoi(token);     // Convert string to integer
            total += age;          // Add age to running total
            count++;               // Count how many members we've processed
            token = strtok(NULL, " \t\n"); // Move to the next token
        }

        // Only print if the line had valid numbers (avoid divide-by-zero)
        if (count > 0) {
            printf("%5.2f : %s", (double)total / count, line_copy);
        }
    }

    // Close the file after finishing
    fclose(file);

    return 0; // Indicate successful execution
}

