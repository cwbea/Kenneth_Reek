#include <stdio.h>  // For printf
#include <string.h> // For strchr (used to search for a character in a string)

// Function: count_chars
// Counts how many characters in 'str' are also found in 'chars'
int count_chars(const char *str, const char *chars) {
    int count = 0;        // This will store the total number of matches
    const char *p = str;  // Pointer to go through the 'str' string

    // Loop through each character in 'str'
    while (*p != '\0') {
        // Use strchr to check if the character is in the 'chars' string
        // strchr returns a pointer to the first match, or NULL if no match
        if (strchr(chars, *p) != NULL) {
            count++;  // If it's a match, increment the counter
        }
        p++;  // Move to the next character in 'str'
    }

    return count;  // Return the total number of matches
}

// Example usage of count_chars
int main(void) {
    const char *text = "hello, world!";
    const char *vowels = "aeiou";

    // Count how many vowels are in 'text'
    int result = count_chars(text, vowels);

    printf("Number of vowels in \"%s\": %d\n", text, result);

    return 0;  // End of program
}

