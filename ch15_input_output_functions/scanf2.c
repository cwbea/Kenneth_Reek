/*
** Variable format input processing with sscanf.
** This function attempts to parse up to 3 integers from a string.
** If any of the values are missing, defaults are used.
*/

#include <stdio.h>   // For standard I/O functions like printf, fprintf
#include <stdlib.h>  // For exit() and EXIT_FAILURE

// Default values for a and b if they are not provided in the input
#define DEFAULT_A 1  // Default value for 'a'
#define DEFAULT_B 2  // Default value for 'b'

/*
** Function: parse_input
** ---------------------
** Attempts to extract up to three integers from a string.
** If fewer than three integers are present, it fills in the rest with defaults.
**
** Parameters:
** - char *buffer: A pointer to a string that may contain up to 3 integers.
*/
void parse_input(char *buffer) {
    int a, b, c;  // Variables to store the three integer values

    // Try to extract three integers from the input buffer
    if (sscanf(buffer, "%d %d %d", &a, &b, &c) != 3) {
        // If not all three are found, set a to DEFAULT_A and try to read b and c
        a = DEFAULT_A;

        if (sscanf(buffer, "%d %d", &b, &c) != 2) {
            // If b and c are not found, set b to DEFAULT_B and try to read only c
            b = DEFAULT_B;

            if (sscanf(buffer, "%d", &c) != 1) {
                // If no valid integer is found, print an error and exit
                fprintf(stderr, "Bad input: %s", buffer);
                exit(EXIT_FAILURE);
            }
        }
    }

    // If we reach here, a, b, and c all have values (some may be defaults)
    printf("Parsed values: a = %d, b = %d, c = %d\n", a, b, c);
}

/*
** Main function
** -------------
** Demonstrates usage of parse_input with different types of input.
*/
int main() {
    char input1[] = "10 20 30";      // All three values present
    char input2[] = "40 50";         // Missing a, should use DEFAULT_A
    char input3[] = "60";            // Missing a and b, use both defaults
    char input4[] = "abc";           // Invalid input, should trigger error

    printf("Input: \"%s\"\n", input1);
    parse_input(input1);  // Expected: 10 20 30

    printf("Input: \"%s\"\n", input2);
    parse_input(input2);  // Expected: 1 40 50

    printf("Input: \"%s\"\n", input3);
    parse_input(input3);  // Expected: 1 2 60

    printf("Input: \"%s\"\n", input4);
    parse_input(input4);  // Expected: error

    return 0;
}

