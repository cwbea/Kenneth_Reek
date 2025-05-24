#include <stdio.h>   // For printf
#include <stddef.h>  // For NULL

// Function: my_strnchr
// Searches for the nth occurrence of character 'ch' in the string 'str'
// Returns a pointer to the nth occurrence or NULL if it doesn't exist
char *my_strnchr(const char *str, int ch, int which) {
    int count = 0;               // Tracks how many matches we've found
    const char *p = str;         // Pointer used to iterate over the string

    // Loop through the string until the null terminator
    while (*p != '\0') {
        if (*p == (char)ch) {    // If current character matches the one we're looking for
            count++;             // Increase the match count
            if (count == which) {
                return (char *)p; // If it's the desired occurrence, return the pointer
            }
        }
        p++;  // Move to the next character
    }

    return NULL;  // If we finish the loop without finding the desired occurrence
}

// Example usage of my_strnchr
int main(void) {
    const char *text = "banana bread is nice";
    char target = 'a';   // Character we're searching for
    int which = 3;       // We want the 3rd occurrence of 'a'

    // Call our custom function
    char *result = my_strnchr(text, target, which);

    // Display the result
    if (result != NULL) {
        printf("The %d%s occurrence of '%c' is at: \"%s\"\n",
               which,
               (which == 1) ? "st" : (which == 2) ? "nd" : (which == 3) ? "rd" : "th",
               target, result);
    } else {
        printf("The %dth occurrence of '%c' was not found.\n", which, target);
    }

    return 0;  // End of program
}

