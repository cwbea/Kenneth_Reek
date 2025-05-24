#include <stdio.h>      // For printf
#include <ctype.h>      // For isalpha, toupper
#include <string.h>     // For strlen, strcpy

#define ALPHABET_LEN 26 // Total letters in the English alphabet

// Function to prepare the cipher key based on a keyword
int prepare_key(char *key) {
    if (key == NULL || key[0] == '\0') {
        return 0; // Return false if key is NULL or empty
    }

    int used[ALPHABET_LEN] = {0};         // Array to mark which letters are already used
    char result[ALPHABET_LEN + 1];        // Final result buffer (26 letters + '\0')
    int i, j = 0;

    // Step 1: Process the original keyword
    for (i = 0; key[i] != '\0'; i++) {
        char ch = toupper((unsigned char)key[i]); // Convert character to uppercase

        if (!isalpha(ch)) {
            continue; // Skip non-alphabetic characters instead of failing
        }

        int index = ch - 'A'; // Convert 'A'-'Z' to 0-25 index

        if (!used[index]) {
            result[j++] = ch;    // Add to result if not already used
            used[index] = 1;     // Mark letter as used
        }
    }

    // Step 2: Append remaining unused alphabet letters
    for (i = 0; i < ALPHABET_LEN; i++) {
        if (!used[i]) {
            result[j++] = 'A' + i; // Append unused letter
        }
    }

    result[j] = '\0'; // Null-terminate the final key string

    // Step 3: Copy final result back to the provided key buffer
    strcpy(key, result); // Replace the original content with the full key

    return 1; // Return success (true)
}

// Main function to test the prepare_key logic
int main() {
    char key_buffer[ALPHABET_LEN + 1] = "TRAIL-BLAZERS"; 
    // Buffer with space for 26 letters + null character
    // Input includes duplicate and non-alphabetic characters

    if (prepare_key(key_buffer)) {
        // If prepare_key returned true, show the result
        printf("Prepared key: %s\n", key_buffer);
    } else {
        // If input was invalid, display error
        printf("Invalid key input.\n");
    }

    return 0; // Exit the program
}

