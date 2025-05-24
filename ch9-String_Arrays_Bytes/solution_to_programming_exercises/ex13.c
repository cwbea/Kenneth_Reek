#include <stdio.h>      // For printf
#include <ctype.h>      // For isalpha, toupper, tolower, isupper
#include <string.h>     // For strlen, strcpy

#define ALPHABET_LEN 26

// Function to prepare the cipher key based on a keyword
int prepare_key(char *key) {
    if (key == NULL || key[0] == '\0') {
        return 0; // Return false if key is NULL or empty
    }

    int used[26] = {0};                 // Tracks letters already used
    char result[ALPHABET_LEN + 1];      // Resulting cipher key
    int i, j = 0;                       // j: index into result

    // Step 1: Build key with unique uppercase letters from input
    for (i = 0; key[i] != '\0'; i++) {
        char ch = toupper((unsigned char)key[i]); // Convert to uppercase

        if (!isalpha(ch)) {
            continue; // Skip non-alphabetic characters (e.g., '-')
        }

        int index = ch - 'A'; // A=0, B=1, ..., Z=25

        if (!used[index]) {
            result[j++] = ch;
            used[index] = 1; // Mark letter as used
        }
    }

    // Step 2: Fill in unused letters of the alphabet
    for (i = 0; i < ALPHABET_LEN; i++) {
        if (!used[i]) {
            result[j++] = 'A' + i;
        }
    }

    result[j] = '\0';         // Null-terminate the result string
    strcpy(key, result);      // Copy result into original key buffer

    return 1; // Key successfully prepared
}

// Function to encrypt the data using the key
void encrypt(char *data, const char *key) {
    for (int i = 0; data[i] != '\0'; i++) {
        char ch = data[i];

        if (isalpha(ch)) {
            int index = isupper(ch) ? (ch - 'A') : (ch - 'a');
            data[i] = isupper(ch) ? key[index] : tolower(key[index]);
        }
        // Non-alphabetic characters are unchanged
    }
}

// Demonstrates preparing the key and encrypting a message
int main() {
    char key_buffer[27] = "TRAIL-BLAZERS"; // User-provided keyword
    char message[] = "Attack at dawn!";    // Message to encrypt

    if (prepare_key(key_buffer)) {
        printf("Prepared key: %s\n", key_buffer);

        encrypt(message, key_buffer);
        printf("Encrypted message: %s\n", message);
    } else {
        printf("Invalid key input.\n");
    }

    return 0;
}

