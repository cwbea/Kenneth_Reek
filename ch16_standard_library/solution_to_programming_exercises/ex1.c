#include <stdio.h>      // For printf and fprintf
#include <stdlib.h>     // For atoi, strtol, EXIT_SUCCESS, and EXIT_FAILURE
#include <string.h>     // For strlen
#include <ctype.h>      // For isdigit (not used here but useful in general)

// Function to determine if the given age (in base 10)
// appears to be 29 or less when interpreted in a different base
// Parameters:
// - age: the base-10 integer age entered by the user
// - base: the target base to check (from 2 to 36)
// Returns:
// - 1 (true) if the age in the given base looks like 29 or less in base 10
int is_age_29_or_less_in_base(int age, int base) {
    char buffer[100];   // Array to hold the converted number as a string
    int index = 0;      // Position tracker for the buffer
    int n = age;        // Copy of age used for conversion

    // Convert the age to the given base manually
    while (n > 0) {
        int digit = n % base;  // Get the last digit in the current base
        // Convert the digit to a character and store in buffer
        buffer[index++] = digit < 10 ? '0' + digit : 'A' + (digit - 10);
        n /= base;             // Reduce n by dividing with base
    }

    buffer[index] = '\0'; // Null-terminate the string

    // Reverse the string since the digits are in reverse order
    for (int i = 0; i < index / 2; i++) {
        char temp = buffer[i];
        buffer[i] = buffer[index - 1 - i];
        buffer[index - 1 - i] = temp;
    }

    // Convert the buffer string to a base-10 integer
    // We do this to compare the string visually (as base-10 number)
    int value = (int)strtol(buffer, NULL, 10);

    // Return 1 (true) if the base-10 interpretation of the string is <= 29
    return value <= 29;
}

// Main function - entry point of the program
// Parameters:
// - argc: argument count (should be 2: program name + age)
// - argv: argument vector (array of strings)
int main(int argc, char *argv[]) {
    // Check if the user provided exactly one argument (besides program name)
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <age>\n", argv[0]); // Print usage help
        return EXIT_FAILURE; // Exit with error code
    }

    // Convert the argument string to an integer (user's age in base 10)
    int age = atoi(argv[1]);

    // Check if the age is a valid positive number
    if (age <= 0) {
        fprintf(stderr, "Please enter a positive age.\n"); // Error message
        return EXIT_FAILURE; // Exit with failure
    }

    // Loop through all bases from 2 to 36
    for (int base = 2; base <= 36; base++) {
        // Check if age looks like 29 or less in this base
        if (is_age_29_or_less_in_base(age, base)) {
            // If it does, print the base and exit
            printf("Use base %d (age looks like 29 or less)\n", base);
            return EXIT_SUCCESS; // Exit successfully
        }
    }

    // If no base from 2 to 36 makes the age look like 29 or less
    printf("No base from 2 to 36 makes the age appear 29 or less.\n");
    return EXIT_SUCCESS; // Still exit successfully, just no match found
}

