#include <stdio.h>     // For input/output functions like getchar() and printf()
#include <ctype.h>     // For character classification functions like isdigit(), isspace(), etc.

#define NUM_CATEGORIES 7  // Define the number of categories we're going to analyze

int main(void) {
    // Array to keep track of how many characters fall into each category
    int counts[NUM_CATEGORIES] = {0};  // Initialize all counts to 0
    int total = 0;                     // Keep track of total number of characters read
    int ch;                            // Variable to hold each character read from input

    // Array of function pointers to classify characters into categories.
    // Each function takes an int (character) and returns a non-zero value if it matches the category.
    int (*classifiers[NUM_CATEGORIES])(int) = {
        iscntrl,      // Checks if character is a control character (like '\n', '\t', etc.)
        isspace,      // Checks if character is whitespace (space, tab, newline, etc.)
        isdigit,      // Checks if character is a digit (0-9)
        islower,      // Checks if character is a lowercase letter (a-z)
        isupper,      // Checks if character is an uppercase letter (A-Z)
        ispunct,      // Checks if character is punctuation (e.g., '.', '!', '?')
        NULL          // Placeholder for non-printable characters — handled separately
    };

    // Names of each category for easy printing
    const char *category_names[NUM_CATEGORIES] = {
        "Control characters",
        "Whitespace characters",
        "Digits",
        "Lowercase letters",
        "Uppercase letters",
        "Punctuation characters",
        "Non-printable characters"
    };

    // Read characters from standard input until end-of-file (Ctrl+D on Linux/macOS or Ctrl+Z on Windows)
    while ((ch = getchar()) != EOF) {
        total++;  // Count this character in the total

        int categorized = 0;  // Flag to know if the character was matched to a category

        // Check the character against the first 6 categories
        for (int i = 0; i < NUM_CATEGORIES - 1; i++) {
            if (classifiers[i](ch)) { // Call the function for this category
                counts[i]++;          // Increment that category's count
                categorized = 1;      // Mark as categorized
                break;                // No need to check further categories
            }
        }

        // If not categorized and not printable, it's considered non-printable
        if (!categorized && !isprint(ch)) {
            counts[NUM_CATEGORIES - 1]++;  // Increment non-printable count
        }
    }

    // If nothing was entered, avoid division by zero
    if (total == 0) {
        printf("No input provided.\n");
        return 0;
    }

    // Display the results
    printf("Character category percentages:\n\n");

    // Loop over each category and print its percentage of the total
    for (int i = 0; i < NUM_CATEGORIES; i++) {
        // %-25s means print the name left-justified in 25 character spaces
        // %.2f means print percentage with 2 digits after the decimal point
        printf("%-25s: %.2f%%\n", category_names[i], 100.0 * counts[i] / total);
    }

    return 0;  // Program finished successfully
}

