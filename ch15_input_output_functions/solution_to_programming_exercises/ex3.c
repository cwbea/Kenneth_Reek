#include <stdio.h>  // Standard I/O functions

#define BUFFER_SIZE 80  // Read input in chunks of 80 chars

int main(void) {
    char buffer[BUFFER_SIZE + 1];  // Buffer to hold chunk + null terminator
    int i;                        // Index to scan the buffer

    // Read from stdin until EOF
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        // Print the chunk read
        fputs(buffer, stdout);

        // Check if the chunk contained a newline
        for (i = 0; buffer[i] != '\0'; i++) {
            if (buffer[i] == '\n') {
                // Found newline: end of this line
                break;
            }
        }
        // If no newline found in chunk, the line continues,
        // so keep reading and printing chunks until newline or EOF
        while (buffer[i] != '\n' && !feof(stdin)) {
            if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
                break;  // EOF or error
            }
            fputs(buffer, stdout);
            // Reset i and scan new buffer for newline again
            for (i = 0; buffer[i] != '\0'; i++) {
                if (buffer[i] == '\n') {
                    break;
                }
            }
        }
    }

    return 0;  // Successful exit
}

