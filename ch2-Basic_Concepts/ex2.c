/*
** This program reads C source code from standard input and checks
** that all braces '{' and '}' are correctly paired.
**
** It ignores braces inside:
** - block comments (* ... *),
** - string literals ("..."),
** - character constants ('...').
**
** The program prints a message saying whether the braces are balanced.
*/

#include <stdio.h>      // For standard I/O functions
#include <stdbool.h>    // For using true/false values
#include <stddef.h>

int main(void) {
    int ch;                 // Character read from input
    int brace_count = 0;    // Tracks number of unmatched '{' braces
    bool in_comment = false;        // Are we inside a / ... / comment?
    bool in_string = false;         // Are we inside a "..." string literal?
    bool in_char = false;           // Are we inside a '...' char constant?
    int prev = 0;                   // Stores the previous character

    // Read input one character at a time until end-of-file (EOF)
    while ((ch = getchar()) != EOF) {

        // Check if we're entering or leaving a comment
        if (!in_string && !in_char) {
            if (!in_comment && prev == '/' && ch == '*') {
                in_comment = true;   // Start of comment
            } else if (in_comment && prev == '*' && ch == '/') {
                in_comment = false;  // End of comment
            }
        }

        // Toggle string state if quote is not escaped and not in comment or char
        if (!in_comment && !in_char && ch == '"' && prev != '\\') {
            in_string = !in_string;  // Enter/exit string literal
        }

        // Toggle char state if single quote is not escaped and not in comment or string
        if (!in_comment && !in_string && ch == '\'' && prev != '\\') {
            in_char = !in_char;      // Enter/exit char literal
        }

        // Count braces only when not inside comment, string, or char
        if (!in_comment && !in_string && !in_char) {
            if (ch == '{') {
                brace_count++;   // Opening brace found
            } else if (ch == '}') {
                brace_count--;   // Closing brace found

                if (brace_count < 0) {
                    // More closing braces than opening
                    printf("Unmatched closing brace detected.\n");
                    return 1;
                }
            }
        }

        prev = ch;  // Update previous character
    }

    // After reading all input, check if any unmatched opening braces remain
    if (brace_count == 0) {
        printf("All braces are correctly paired.\n");
    } else {
        printf("Unmatched opening brace(s) detected.\n");
    }

    return 0;   // Program finished successfully
}

