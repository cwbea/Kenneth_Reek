#include <stdio.h>  // Include standard input/output library

int main(void) {
    int ch;  // Variable to hold each character read from input; must be int to hold EOF

    // Read characters one by one from standard input until EOF is reached
    while ((ch = getchar()) != EOF) {
        // Write the character read to standard output
        putchar(ch);
    }

    return 0;  // Return 0 indicating successful program termination
}

