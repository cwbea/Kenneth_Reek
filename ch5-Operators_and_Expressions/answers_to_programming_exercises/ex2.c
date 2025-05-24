// Include the standard input/output library so we can use functions like getchar and putchar
#include <stdio.h>

// Define a function called rot13 that takes a character and returns its ROT13-encrypted version
char rot13(char c) {
    // Check if the character is an uppercase letter (A to Z)
    if (c >= 'A' && c <= 'Z') {
        // Convert the character to a number from 0–25 (by subtracting 'A'),
        // add 13 to it (for ROT13), use % 26 to wrap around if needed,
        // and convert it back to a character by adding 'A'
        return ((c - 'A' + 13) % 26) + 'A';
    } 
    // Check if the character is a lowercase letter (a to z)
    else if (c >= 'a' && c <= 'z') {
        // Same logic as above, but with lowercase letters
        return ((c - 'a' + 13) % 26) + 'a';
    } 
    else {
        // If it's not a letter (e.g., a number, space, punctuation),
        // return it unchanged
        return c;
    }
}

// Main function - program execution starts here
int main() {
    int ch; // Declare a variable to hold each character read from input

    // Read characters one by one from standard input until end-of-file (EOF)
    while ((ch = getchar()) != EOF) {
        // Convert the character using rot13 and print it
        putchar(rot13((char)ch));
    }

    // Return 0 to signal that the program ended successfully
    return 0;
}

