#include <stdio.h>      // For standard I/O functions
#include <stdlib.h>     // For exit() and EXIT_FAILURE
#include <ctype.h>      // For isprint() to check if a character is printable
#include <string.h>     // For strlen()

// This function prints a line of the hex dump
void print_hex_line(unsigned char *buffer, int offset, int length) {
    // Print the offset in hexadecimal with leading zeros (6 digits wide)
    printf("%06X  ", offset);

    // Print the hex representation in 4 groups of 4 bytes (total 16 bytes)
    for (int i = 0; i < 16; i++) {
        if (i < length) {
            // Print each byte as a two-digit uppercase hex value
            printf("%02X", buffer[i]);
        } else {
            // Print spaces for missing bytes at the end of the file
            printf("  ");
        }

        // Add space between 4-byte groups
        if ((i + 1) % 4 == 0) printf(" ");
    }

    // Print an asterisk before the character representation
    printf("*");

    // Print the character representation (printable characters or '.' for non-printables)
    for (int i = 0; i < length; i++) {
        // Print character if it's printable or space; otherwise, print a dot
        printf("%c", isprint(buffer[i]) ? buffer[i] : '.');
    }

    // Print a trailing asterisk and newline
    printf("*\n");
}

// Main function: entry point of the program
int main(int argc, char *argv[]) {
    FILE *fp;                    // File pointer
    unsigned char buffer[16];    // Buffer to store 16 bytes at a time
    int offset = 0;              // Keeps track of the file offset
    int bytesRead;               // Number of bytes read in each block

    // If a filename is provided as an argument, open the file
    if (argc > 1) {
        fp = fopen(argv[1], "rb");  // Open file in binary mode

        // If file couldn't be opened, show error and exit
        if (fp == NULL) {
            perror("Error opening file");
            return EXIT_FAILURE;
        }
    } else {
        // If no filename is given, use standard input
        fp = stdin;
    }

    // Read the file in chunks of 16 bytes
    while ((bytesRead = fread(buffer, 1, 16, fp)) > 0) {
        // Print the hex dump for the current 16-byte block
        print_hex_line(buffer, offset, bytesRead);

        // Increment offset by number of bytes read
        offset += bytesRead;
    }

    // Close the file if it's not standard input
    if (fp != stdin) {
        fclose(fp);
    }

    return 0;  // Indicate successful completion
}

