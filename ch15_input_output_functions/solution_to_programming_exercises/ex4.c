#include <stdio.h>     // For standard I/O functions
#include <stdlib.h>    // For exit(), EXIT_FAILURE, etc.
#include <string.h>    // For strtok and newline removal

#define BUFFER_SIZE 80         // Size of chunk to read at a time
#define FILENAME_SIZE 100      // Max length for filenames

int main(void) {
    char input_filename[FILENAME_SIZE];   // Buffer to hold input filename
    char output_filename[FILENAME_SIZE];  // Buffer to hold output filename
    char buffer[BUFFER_SIZE + 1];         // Buffer for line chunks
    FILE *input_file;                     // File pointer for input file
    FILE *output_file;                    // File pointer for output file
    int i;                                // Index to scan for newline

    // Prompt for input file name
    printf("Enter the input file name: ");
    if (fgets(input_filename, sizeof(input_filename), stdin) == NULL) {
        fprintf(stderr, "Failed to read input file name.\n");
        exit(EXIT_FAILURE);
    }

    // Remove trailing newline from input file name if present
    input_filename[strcspn(input_filename, "\n")] = '\0';

    // Prompt for output file name
    printf("Enter the output file name: ");
    if (fgets(output_filename, sizeof(output_filename), stdin) == NULL) {
        fprintf(stderr, "Failed to read output file name.\n");
        exit(EXIT_FAILURE);
    }

    // Remove trailing newline from output file name if present
    output_filename[strcspn(output_filename, "\n")] = '\0';

    // Open the input file in read mode
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    // Open the output file in write mode (create/overwrite)
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        perror("Error opening output file");
        fclose(input_file); // Don't forget to close the input if output fails
        exit(EXIT_FAILURE);
    }

    // Read and write line chunks from input file to output file
    while (fgets(buffer, sizeof(buffer), input_file) != NULL) {
        fputs(buffer, output_file);  // Write chunk to output

        // Check if this chunk ends the line (contains newline)
        for (i = 0; buffer[i] != '\0'; i++) {
            if (buffer[i] == '\n') {
                break;  // Line complete
            }
        }

        // If newline not found, continue reading rest of the line
        while (buffer[i] != '\n' && !feof(input_file)) {
            if (fgets(buffer, sizeof(buffer), input_file) == NULL)
                break;
            fputs(buffer, output_file);

            // Look for newline again
            for (i = 0; buffer[i] != '\0'; i++) {
                if (buffer[i] == '\n') {
                    break;
                }
            }
        }
    }

    // Close both files
    fclose(input_file);
    fclose(output_file);

    printf("File copied successfully.\n");
    return 0; // Successful program termination
}

