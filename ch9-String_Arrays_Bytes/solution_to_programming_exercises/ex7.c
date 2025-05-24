#include <stdio.h>   // For printf
#include <stddef.h>  // For NULL

// Function: my_strrchr
// Searches for the last occurrence of the character 'ch' in the string 'str'.
// Returns a pointer to the last occurrence, or NULL if not found.
char *my_strrchr(const char *str, int ch) {
    char *last_occurrence = NULL;  // Will store the address of the last match found

    // Loop through the entire string until the null terminator
    while (*str != '\0') {
        if (*str == (char)ch) {
            last_occurrence = (char *)str;  // Save the pointer to the current match
        }
        str++;  // Move to the next character
    }

    // If the last character is the one we’re searching for (e.g., null byte), check it too
    if ((char)ch == '\0') {
        return (char *)str;  // Return pointer to null terminator
    }

    // Return the pointer to the last match, or NULL if not found
    return last_occurrence;
}

// Example usage of my_strrchr
int main(void) {
    const char *text = "The rain in Spain falls mainly.";
    char search = 'i';  // Character we want to find

    // Call our function to get a pointer to the last 'i'
    char *result = my_strrchr(text, search);

    // Print result if found
    if (result != NULL) {
        printf("Last occurrence of '%c' is at: \"%s\"\n", search, result);
    } else {
        printf("Character '%c' not found.\n", search);
    }

    return 0;  // End of program
}

