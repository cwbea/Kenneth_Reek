#include <stdio.h>   // For printf
#include <string.h>  // For strstr

/*
** This function searches for the rightmost (last) occurrence of the string `s2` in the string `s1`.
** If found, it returns a pointer to the beginning of that occurrence in `s1`.
** If not found, it returns NULL.
*/
char *my_strrstr(const char *s1, const char *s2) {
    // Declare a pointer to store the last match found
    char *last = NULL;
    
    // Declare a pointer to store the current match found
    char *current;

    // Only proceed if the string s2 is not empty
    if (*s2 != '\0') {
        // Find the first occurrence of s2 in s1
        current = strstr(s1, s2);

        // Keep searching until no more occurrences are found
        while (current != NULL) {
            // Save the latest occurrence
            last = current;
            // Look for the next occurrence after the current one
            current = strstr(last + 1, s2);
        }
    }

    // Return the pointer to the last occurrence of s2 in s1 (or NULL if not found)
    return last;
}

/*
** Main function to test the my_strrstr function.
*/
int main() {
    // Sample input strings
    const char *text = "This is a test. This test is only a test.";
    const char *search = "test";

    // Call the function to find the last occurrence
    char *result = my_strrstr(text, search);

    // Check if the substring was found and print the result
    if (result != NULL) {
        printf("Last occurrence of \"%s\" found at position: %ld\n", search, result - text);
        printf("Text from that point: \"%s\"\n", result);
    } else {
        printf("Substring \"%s\" not found in the text.\n", search);
    }

    return 0;
}

