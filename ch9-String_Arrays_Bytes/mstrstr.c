#include <string.h>  // For strstr function

/*
 * Function: my_strrstr
 * --------------------
 * Finds the rightmost (last) occurrence of substring s2 in string s1.
 *
 * Parameters:
 *   s1 - The string to search in.
 *   s2 - The substring to search for.
 *
 * Returns:
 *   A pointer to the beginning of the last occurrence of s2 in s1,
 *   or NULL if s2 is not found or if s2 is an empty string.
 */
char *my_strrstr(const char *s1, const char *s2)
{
    // Declare pointers to track the last and current match positions
    char *last = NULL;
    char *current;

    // Only search if s2 is not empty
    if (*s2 != '\0') {
        // Find the first occurrence of s2 in s1
        current = strstr(s1, s2);

        // Loop as long as we find s2 in s1
        while (current != NULL) {
            // Save the pointer to the current match
            last = current;

            // Search for the next occurrence starting just after the current match
            current = strstr(last + 1, s2);
        }
    }

    // Return the pointer to the last match found (or NULL if none was found)
    return last;
}

