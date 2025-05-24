#include <stdio.h>      // For input/output functions
#include <stdlib.h>     // For standard functions like exit()
#include <string.h>     // For string manipulation functions like strstr()

#define MAX_LINE 512    // Maximum length of each line (including the null terminator)

/*
 * Function: search_file
 * ---------------------
 * Searches for a target string in each line of the given file.
 *
 * Parameters:
 *  - FILE *fp: Pointer to the file being searched
 *  - const char *filename: Name of the file (for output purposes)
 *  - const char *target: The string to search for
 *  - int show_filename: Whether to prefix matched lines with filename (1 = yes, 0 = no)
 */
void search_file(FILE *fp, const char *filename, const char *target, int show_filename) {
    char line[MAX_LINE];  // Buffer to hold each line read from the file

    // Read the file line by line
    while (fgets(line, MAX_LINE, fp) != NULL) {
        // Check if the target string is found in the current line
        if (strstr(line, target) != NULL) {
            // If show_filename is true, print the filename and colon
            if (show_filename) {
                printf("%s: %s", filename, line);
            } else {
                // If reading from stdin, don't print the filename
                printf("%s", line);
            }
        }
    }
}

/*
 * Function: main
 * --------------
 * Entry point of the program. Parses command line arguments and searches
 * through files (or stdin) for a given string.
 *
 * Usage:
 *   ./ex9 <search-string> [file1 file2 ...]
 */
int main(int argc, char *argv[]) {
    // Ensure at least the search string is provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <search-string> [file1 file2 ...]\n", argv[0]);
        return 1;  // Exit with error code
    }

    const char *target = argv[1];  // The string to search for

    // If only the search string is provided, read from standard input
    if (argc == 2) {
        search_file(stdin, NULL, target, 0);  // No filename shown
    } else {
        // Loop through each file provided in the command-line arguments
        for (int i = 2; i < argc; i++) {
            FILE *fp = fopen(argv[i], "r");  // Try to open the file for reading
            if (fp == NULL) {
                // If the file can't be opened, print an error and continue with next
                perror(argv[i]);
                continue;
            }
            // Search this file and show its name in output
            search_file(fp, argv[i], target, 1);
            fclose(fp);  // Close the file after use
        }
    }

    return 0;  // Exit with success
}

