#include <stdio.h>    // For printf
#include <ctype.h>    // For isalpha and tolower functions

// Function: palindrome
// Checks if the input string is a palindrome by ignoring non-alphabetic characters
// and performing case-insensitive character comparisons
int palindrome(char *string) {
    char *start = string;             // Pointer to the start of the string
    char *end = string;               // Pointer to the end of the string

    // Move the 'end' pointer to the last valid character in the string
    while (*end != '\0') {
        end++;  // Move 'end' forward to the next character
    }
    end--;  // Move 'end' back to the last character (before null terminator)

    // Loop through the string from both ends
    while (start < end) {
        // Skip non-alphabetic characters from the start
        while (*start != '\0' && !isalpha((unsigned char)*start)) {
            start++;  // Move start pointer to the next character
        }
        // Skip non-alphabetic characters from the end
        while (end > start && !isalpha((unsigned char)*end)) {
            end--;  // Move end pointer to the previous character
        }

        // Compare characters from both ends (case-insensitive)
        if (tolower((unsigned char)*start) != tolower((unsigned char)*end)) {
            return 0;  // If characters don't match, return false (0)
        }

        start++;  // Move start pointer forward
        end--;    // Move end pointer backward
    }

    return 1;  // If all characters match, return true (1)
}

// Example usage of palindrome function
int main(void) {
    char test_string[] = "A man, a plan, a canal, Panama!";

    // Call palindrome function
    int result = palindrome(test_string);

    // Print the result
    if (result) {
        printf("\"%s\" is a palindrome!\n", test_string);
    } else {
        printf("\"%s\" is NOT a palindrome.\n", test_string);
    }

    return 0;  // End of program
}

