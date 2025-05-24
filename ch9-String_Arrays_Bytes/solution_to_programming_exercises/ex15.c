#include <stdio.h>   // For printf
#include <string.h>  // For strlen

// Convert a string of digits (pennies) into formatted dollars and store in dest
void dollars(char *dest, const char *src) {
    const char *s = src;                      // Pointer to input string
    int len = 0;                              // Length of the input string

    // Calculate the length of the input string
    while (*s++) {
        len++;
    }

    // If input is empty, just return "$0.00"
    if (len == 0) {
        strcpy(dest, "$0.00");
        return;
    }

    // Calculate number of dollar digits (everything except last 2 cents)
    int dollar_digits = (len > 2) ? len - 2 : 0;

    // How many commas we need: one for every 3 digits beyond the first group
    int commas = (dollar_digits > 3) ? (dollar_digits - 1) / 3 : 0;

    // Total length of output: 1 ($) + dollar_digits + commas + 1 (.) + 2 + 1 ('\0')
    char *d = dest;           // Destination pointer
    *d++ = '$';               // Add dollar sign

    const char *start = src;  // Start from beginning
    int skip = (len > 2) ? len - 2 : 0;  // Digits before decimal point

    // Skip to the first dollar digit
    s = src;

    // Print dollar part with commas
    for (int i = 0; i < skip; i++) {
        *d++ = *s++; // Copy digit

        int digits_left = skip - i - 1;
        if (digits_left > 0 && digits_left % 3 == 0) {
            *d++ = ','; // Insert comma every 3 digits from the right
        }
    }

    // If less than 1 dollar (i.e., len <= 2), insert "0" before decimal
    if (skip == 0) {
        *d++ = '0';
    }

    *d++ = '.'; // Decimal point

    // Handle cents (last 2 digits)
    if (len == 1) {
        *d++ = '0';
        *d++ = *s; // single digit cent, e.g., "5" -> ".05"
    } else if (len == 0) {
        *d++ = '0';
        *d++ = '0';
    } else {
        *d++ = *s++; // tens place of cents
        *d++ = *s++; // ones place of cents
    }

    *d = '\0'; // Null-terminate the string
}

// Test the dollars() function with various inputs
int main() {
    char output[50]; // Buffer to store formatted result

    const char *tests[] = {
        "", "1", "12", "123", "1234", "12345", "123456", "1234567", "12345678", "123456789"
    };

    for (int i = 0; i < sizeof(tests)/sizeof(tests[0]); i++) {
        dollars(output, tests[i]);
        printf("Input: %-10s  Output: %s\n", tests[i], output);
    }

    return 0;
}

