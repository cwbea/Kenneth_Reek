/*
** Mystery function
** ----------------
** Takes an integer argument in the range 0 through 100,
** processes it, and prints a specific number of asterisks ('*').
*/

#include <stdio.h>  // Required for printf()

/*
** Function: mystery
** -----------------
** Prints a line of asterisks based on the value of the input.
**
** Parameters:
**   n - an integer from 0 to 100
*/
void mystery(int n)
{
    n += 5;            // Add 5 to the input (used for rounding when dividing)
    n /= 10;           // Integer division by 10, effectively rounds n/10

    // Print a substring of "**********" starting at position (10 - n)
    // Example: if n = 3 → 10 - 3 = 7 → print from index 7 → "***"
    printf("%s\n", "**********" + 10 - n);
}

/*
** Main function: entry point of the program
** Calls the mystery function with example values
*/
int main(void)
{
    int i;

    // Test the mystery function with a range of values from 0 to 100 in steps of 10
    for (i = 0; i <= 100; i += 10) {
        printf("Input: %3d → Output: ", i);
        mystery(i);  // Call the mystery function with current value of i
    }

    return 0;  // Indicate successful completion
}

