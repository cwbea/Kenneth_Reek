#include <stdio.h>      // For printf
#include <ctype.h>      // For isalpha, toupper, tolower, isupper
#include <string.h>     // For strlen, strcpy

#define ALPHABET_LEN 26

// Function to prepare the cipher key from a keyword
int prepare_key(char *key) {
    if (key == NULL || key[0] == '\0') {
        return 0; // Return false if key is NULL or empty
    }

    int used[26] = {0};                 // Track which letters have been used
    char result[ALPHABET_LEN + 1];      // Final key result
    int i, j = 0;                       // i: loop for input, j: index into result

    // Step 1: Add unique alphabetic characters from the key
    for (i = 0; key[i] != '\0'; i++) {
        char ch = toupper((unsigned char)key[i]);

        if (!isalpha(ch)) {
            continue; // Skip non-alphabetic characters
        }

        int index = ch - 'A'; // Convert A-Z to 0–25
        if (!used[index]) {
            result[j++] = ch;
            used[index] = 1;
        }
    }

    // Step 2: Add remaining letters of the alphabet
    for (i = 0; i < ALPHABET_LEN; i++) {
        if (!used[i]) {
            result[j++] = 'A' + i;
        }
    }

    result[j] = '\0';       // Null-terminate the string
    strcpy(key, result);    // Copy result back to the key buffer

    return 1; // Success
}

// Function to encrypt alphabetic characters in the data using the key
void encrypt(char *data, const char *key) {
    for (int i = 0; data[i] != '\0'; i++) {
        char ch = data[i];

        if (isalpha(ch)) {
            int index = isupper(ch) ? ch - 'A' : ch - 'a';
            data[i] = isupper(ch) ? key[index] : tolower(key[index]);
        }
    }
}

// Function to decrypt alphabetic characters in the data using the key
void decrypt(char *data, const char *key) {
    for (int i = 0; data[i] != '\0'; i++) {
        char ch = data[i];

        if (isalpha(ch)) {
            // Convert encrypted character to uppercase for lookup
            char upper_ch = toupper((unsigned char)ch);

            // Find its index in the key (i.e., reverse mapping)
            int index = -1;
            for (int j = 0; j < ALPHABET_LEN; j++) {
                if (key[j] == upper_ch) {
                    index = j;
                    break;
                }
            }

            if (index != -1) {
                data[i] = isupper(ch) ? ('A' + index) : tolower('A' + index);
            }
        }
    }
}

// Main function demonstrating usage
int main() {
    char key_buffer[27] = "TRAIL-BLAZERS";    // Input keyword
    char message[] = "Attack at dawn!";       // Original message
    char encrypted[100];                      // Buffer for encrypted text
    char decrypted[100];                      // Buffer for decrypted text

    // Prepare the cipher key
    if (prepare_key(key_buffer)) {
        printf("Prepared key: %s\n", key_buffer);

        // Copy original message before encrypting
        strcpy(encrypted, message);
        encrypt(encrypted, key_buffer);
        printf("Encrypted message: %s\n", encrypted);

        // Copy encrypted message before decrypting
        strcpy(decrypted, encrypted);
        decrypt(decrypted, key_buffer);
        printf("Decrypted message: %s\n", decrypted);
    } else {
        printf("Invalid key input.\n");
    }

    return 0;
}

