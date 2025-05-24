/*
** Program to read a series of digit characters from standard input
** and convert them into an integer.
*/

#include <stdio.h>   // For getchar(), ungetc(), printf()
#include <ctype.h>   // For isdigit()

/*
** Function: read_int
** Purpose: Reads digit characters from standard input and converts them to an integer.
** Stops reading when a non-digit character is encountered.
** Returns: The integer value read from the input.
*/
int read_int() {
    int ch;           // Variable to store the character read from input
    int value = 0;    // Accumulator for the integer value

    /*
    ** Read and process characters while they are digits
    */
    while ((ch = getchar()) != EOF && isdigit(ch)) {
        value *= 10;          // Shift existing digits left by multiplying by 10
        value += ch - '0';    // Convert character to integer and add to value
    }

    /*
    ** Push back the non-digit character into the input buffer
    ** so it's not lost for future reading.
    */
    if (ch != EOF) {
        ungetc(ch, stdin);
    }

    return value; // Return the integer read
}

/*
** Main function for testing read_int
*/
int main() {
    int result;

    printf("Enter a number: ");
    result = read_int(); // Call the function to read an integer

    printf("You entered: %d\n", result); // Output the result

    return 0;
}

