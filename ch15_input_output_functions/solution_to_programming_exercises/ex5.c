#include <stdio.h>      // For standard I/O functions
#include <stdlib.h>     // For exit(), atoi(), etc.
#include <string.h>     // For string manipulation
#include <ctype.h>      // For isspace() and isdigit()

#define BUFFER_SIZE 80          // Chunk size for reading lines
#define FILENAME_SIZE 100       // Max length for filenames

int main(void) {
    char input_filename[FILENAME_SIZE];    // Holds input file name
    char output_filename[FILENAME_SIZE];   // Holds output file name
    char buffer[BUFFER_SIZE + 1];          // Buffer to read chunks of a line
    FILE *input_file, *output_file;        // File pointers
    int sum = 0;                            // To store sum of leading integers
    char line[10000] = "";                 // Temporarily stores a full line
    int line_pos = 0;                      // Position in the line buffer

    // Prompt for input file name
    printf("Enter the input file name: ");
    if (fgets(input_filename, sizeof(input_filename), stdin) == NULL) {
        fprintf(stderr, "Failed to read input file name.\n");
        exit(EXIT_FAILURE);
    }
    input_filename[strcspn(input_filename, "\n")] = '\0'; // Remove newline

    // Prompt for output file name
    printf("Enter the output file name: ");
    if (fgets(output_filename, sizeof(output_filename), stdin) == NULL) {
        fprintf(stderr, "Failed to read output file name.\n");
        exit(EXIT_FAILURE);
    }
    output_filename[strcspn(output_filename, "\n")] = '\0'; // Remove newline

    // Open input file for reading
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    // Open output file for writing
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        perror("Error opening output file");
        fclose(input_file);
        exit(EXIT_FAILURE);
    }

    // Read and process file line by line
    while (fgets(buffer, sizeof(buffer), input_file) != NULL) {
        // Append this chunk to the current line
        strcat(line, buffer);

        // If line ends with newline, it's complete
        if (strchr(buffer, '\n') != NULL) {
            // Copy the line to output file
            fputs(line, output_file);

            // Skip leading whitespace
            int i = 0;
            while (isspace(line[i])) i++;

            // Check if line starts with a digit (i.e., an integer)
            if (isdigit(line[i]) || (line[i] == '-' && isdigit(line[i + 1]))) {
                int value;
                if (sscanf(&line[i], "%d", &value) == 1) {
                    sum += value;  // Add to sum
                }
            }

            // Reset for the next line
            line[0] = '\0';
        }
    }

    // Append the total sum to the output file
    fprintf(output_file, "\nTotal sum of integers at the start of lines: %d\n", sum);

    // Close files
    fclose(input_file);
    fclose(output_file);

    printf("File copied with total sum written at the end.\n");
    return 0;
}

