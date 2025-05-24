#include <stdlib.h>  // for NULL
#include <stdbool.h> // for using the 'bool' type
#include <stdio.h>

// Function to format a string (pattern) using the provided digits.
// It mimics formatting seen on checks, with optional fill characters, commas, etc.
char *edit(char *pattern, char const *digits) {
    // If either argument is NULL, we cannot proceed; return NULL as an error signal.
    if (pattern == NULL || digits == NULL) return NULL;

    // Save the fill character. It's the very first character of the pattern.
    char fill = *pattern;

    // Pointers to traverse the pattern and digit strings.
    char *p = pattern + 1;        // Move past the fill character
    char const *d = digits;       // Start at the beginning of the digits string
    char *result = NULL;          // Will store the pointer to the first significant digit
    bool significant = false;     // Tracks if we've seen a non-zero digit (i.e., significant digit)

    // Loop through the pattern until we hit the null terminator (end of string)
    while (*p != '\0') {
        switch (*p) {
            case '#':   // '#' means place a digit here if significant
                // If the current digit is not null and we've already seen significance,
                // OR it's a non-zero digit that starts significance...
                if (*d != '\0' && (significant || *d != '0')) {
                    *p = *d;  // Copy the digit to the pattern
                    if (!significant && *d != '0') {
                        significant = true; // Mark the start of significance
                        result = p;         // Save this location to return later
                    }
                    d++; // Move to the next digit
                } else {
                    *p = fill; // If not significant, replace with fill character
                    if (*d != '\0') d++; // Only advance if not end of digit string
                }
                break;

            case '!':   // '!' means always print the next digit
                // If we still have digits to print
                if (*d != '\0') {
                    *p = *d;  // Copy the digit
                    if (!significant && *d != '0') {
                        significant = true; // Mark significance
                        result = p;         // Save location
                    }
                    d++; // Move to next digit
                } else {
                    // No more digits, replace with null
                    *p = '\0';
                    return result;  // Return the saved pointer
                }
                break;

            default:
                // For all other characters, just print them if we're past significance
                // If we haven’t hit significance yet, fill with the fill character
                if (significant) {
                    // Leave character unchanged (e.g., commas, decimals, etc.)
                } else {
                    *p = fill;  // Replace with fill if not significant
                }
                break;
        }

        p++; // Move to the next character in the pattern
    }

    return result; // Return pointer to where the first significant digit was placed
}


int main() {
    char pattern[] = "###,###.##";         // formatting pattern
    const char *digits = "12345";          // digits to format

    if (edit(pattern, digits)) {
        printf("Formatted output: %s\n", pattern);
    } else {
        printf("Error: Could not format the digits.\n");
    }

    return 0;
}
