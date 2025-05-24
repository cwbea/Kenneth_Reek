#include <stdio.h>      // For input/output functions like printf
#include <string.h>     // For string functions like strlen
#include <stdbool.h>    // For using true/false with 'bool' type

// This function formats a digit string using a formatting template string.
// It returns 1 (true) if formatting was successful, or 0 (false) if there was an error.
int format(char *format_string, const char *digit_string) {
    // If the digit string is empty (i.e., no digits), return an error.
    if (*digit_string == '\0') {
        return 0; // FALSE
    }

    // Find the pointer to the last character of the format string
    char *f_end = format_string + strlen(format_string) - 1;

    // Find the pointer to the last character of the digit string
    const char *d_end = digit_string + strlen(digit_string) - 1;

    // Set working pointers to end of format string and digit string
    char *f = f_end;
    const char *d = d_end;

    // Loop from right to left through the format string
    while (f >= format_string) {
        if (*f == '#') {
            // If the current format character is '#'
            if (d >= digit_string) {
                // If there are still digits left, copy the current digit into the format
                *f = *d;
                d--; // Move to the next digit to the left
            } else {
                // No more digits left — replace # with a space
                *f = ' ';
            }
        } else if (*f == ',') {
            // If the current character is a comma
            // Check if we need to keep it or change it to a space

            // Start from the character just to the left of the comma
            char *look = f - 1;

            // Move left to find a digit placeholder or a period
            while (look >= format_string && *look != '#' && *look != '.') {
                look--; // Skip over spaces and non-digit symbols
            }

            if (look >= format_string && *look != ' ') {
                // If we find a digit to the left, keep the comma
            } else {
                // No digit to the left — remove the comma
                *f = ' ';
            }
        } else if (*f == '.') {
            // If the current character is a decimal point
            // Fill in zeros to the left if digits have run out

            if (d < digit_string) {
                // If we already finished all digits
                char *left = f - 1;

                // Replace spaces before the decimal with zeroes
                while (left >= format_string && *left == ' ') {
                    *left = '0';
                    left--;
                }
            }
        }
        f--; // Move to the next character to the left in format string
    }

    // After replacing, if there are still digits left (too many for format)
    if (d >= digit_string) {
        return 0; // FALSE — too many digits for the format string
    }

    // All formatting completed successfully
    return 1; // TRUE
}

int main() {
    char pattern[] = "###,###.##";         // formatting pattern
    const char *digits = "12345";          // digits to format

    if (format(pattern, digits)) {
        printf("Formatted output: %s\n", pattern);
    } else {
        printf("Error: Could not format the digits.\n");
    }

    return 0;
}
