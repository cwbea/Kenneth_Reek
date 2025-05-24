#include <stdio.h>   // For printf function
#include <string.h>  // For strtok function

/*
 * Function: print_tokens
 * ----------------------
 * This function extracts and prints individual words (tokens) from a string.
 * Words are separated by whitespace characters like spaces, tabs, and newlines.
 *
 * Parameters:
 *   line - A string (character array) that contains words separated by whitespace.
 *          This string will be modified during tokenization.
 */
void print_tokens(char *line)
{
    // Define a static array of whitespace characters.
    // These characters will be used as delimiters to split the string.
    // static means this array is preserved between function calls,
    // though here it’s not strictly necessary.
    static char whitespace[] = " \t\f\r\v\n";

    // Declare a pointer to hold each extracted token (word).
    char *token;

    // strtok() splits the string 'line' into tokens based on the delimiters in 'whitespace'.
    // On the first call, we pass the full string 'line'.
    // On subsequent calls, we pass NULL to continue from where we left off.
    for (token = strtok(line, whitespace);  // Get the first token
         token != NULL;                     // Keep looping until no more tokens are found
         token = strtok(NULL, whitespace))  // Get the next token
    {
        // Print the current token to the screen.
        printf("Next token is %s\n", token);
    }
}

