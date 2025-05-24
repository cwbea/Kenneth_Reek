#include <stdio.h>      // For file I/O functions
#include <stdlib.h>     // For exit(), EXIT_FAILURE, etc.
#include <string.h>     // For strcmp(), strcat()
#include <ctype.h>      // For isprint()

// Function: compute_checksum
// ---------------------------
// Reads characters from the given file pointer and adds their values
// to a 16-bit unsigned integer to compute the checksum.
//
// Parameters:
//   FILE *fp     : Pointer to the file to read from
//
// Returns:
//   unsigned int : The computed checksum
unsigned int compute_checksum(FILE *fp) {
    unsigned int sum = 0;   // Variable to hold the checksum
    int ch;                 // Variable to hold each character

    // Read each character from the file until EOF (end of file)
    while ((ch = fgetc(fp)) != EOF) {
        sum += (unsigned char)ch;  // Add the character to the checksum
    }

    return sum;  // Return the total checksum
}

// Function: process_file
// ----------------------
// Processes a single file to compute and either print or save its checksum.
//
// Parameters:
//   const char *filename : Name of the file to process
//   int write_to_file     : Flag (1 = write checksum to file, 0 = print to stdout)
void process_file(const char *filename, int write_to_file) {
    FILE *fp = fopen(filename, "r");  // Try to open the file in read mode
    if (!fp) {
        perror(filename);             // Print error if file can't be opened
        return;
    }

    unsigned int sum = compute_checksum(fp);  // Compute the checksum
    fclose(fp);  // Close the file

    if (write_to_file) {
        // Checksum should be written to a file named filename.cks
        char out_filename[256];              // Buffer to hold output file name
        snprintf(out_filename, sizeof(out_filename), "%s.cks", filename);

        FILE *out_fp = fopen(out_filename, "w");  // Open output file to write
        if (!out_fp) {
            perror(out_filename);
            return;
        }

        fprintf(out_fp, "%u\n", sum);  // Write checksum to output file
        fclose(out_fp);
    } else {
        printf("%u\n", sum);  // Print checksum to stdout
    }
}

// Function: main
// --------------
// Entry point of the program.
// Parses command-line arguments and processes each file or standard input.
//
// Usage:
//   ./sum [-f] [file1 file2 ...]
//
// If -f is present, checksums are saved in "filename.cks".
// If no filenames are given, stdin is processed and printed.
int main(int argc, char *argv[]) {
    int write_to_file = 0;     // Flag to indicate -f option
    int file_start = 1;        // Index of the first filename

    // Check if -f option is used
    if (argc > 1 && strcmp(argv[1], "-f") == 0) {
        write_to_file = 1;     // Enable file output
        file_start = 2;        // Files start after -f option
    }

    // No files given - process standard input
    if (file_start >= argc) {
        if (write_to_file) {
            // -f is illegal when reading from stdin
            fprintf(stderr, "-f illegal when reading standard input\n");
            return EXIT_FAILURE;
        } else {
            unsigned int sum = compute_checksum(stdin);  // Compute checksum from stdin
            printf("%u\n", sum);                         // Print it
        }
    } else {
        // Process each file listed in command-line arguments
        for (int i = file_start; i < argc; i++) {
            process_file(argv[i], write_to_file);
        }
    }

    return 0;  // Exit successfully
}

