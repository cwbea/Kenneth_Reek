/*
** This program converts an unsigned integer into its ASCII decimal representation
** and prints it character by character without leading zeros.
** It uses recursion to print digits in the correct order.
*/

#include <stdio.h> // Includes the standard I/O library for putchar and printf

/*
** Function: binary_to_ascii
** -------------------------
** Recursively prints an unsigned integer as a sequence of ASCII characters.
** Parameters:
**   value - an unsigned integer to be converted and printed.
*/
void binary_to_ascii(unsigned int value)
{
    unsigned int quotient;             // Variable to store the result of value / 10 (i.e., remaining digits)

    quotient = value / 10;             // Divide the number by 10 to shift digits to the right

    if (quotient != 0)                 // If there are more digits to process
        binary_to_ascii(quotient);     // Recursively call function to print higher-order digits first

    putchar(value % 10 + '0');         // Print the last digit (in ASCII): '0' is ASCII 48, so this turns 0→'0', 1→'1', etc.
}

/*
** Main function: entry point of the program
*/
int main(void)
{
    unsigned int number = 12345;  // Example number to convert and print

    printf("The number is: ");   // Output label
    binary_to_ascii(number);     // Call the function to print the number
    putchar('\n');               // Print a newline for clean output formatting

    return 0; // Indicate that the program ended successfully
}

