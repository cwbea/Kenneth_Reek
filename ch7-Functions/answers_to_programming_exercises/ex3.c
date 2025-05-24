#include <stdio.h>
#include <ctype.h>  // For the isdigit function

// Function to convert ASCII string to integer
int ascii_to_integer(char *string) {
    int result = 0;  // Initialize result to 0

    // Iterate through each character of the string
    while (*string != '\0') {  // Continue until we reach the null terminator
        // Check if the character is a digit
        if (isdigit(*string)) {
            // Multiply the current result by 10 and add the integer value of the current digit
            result = result * 10 + (*string - '0');
        } else {
            // If a non-digit character is found, return 0
            return 0;
        }
        string++;  // Move to the next character in the string
    }

    return result;  // Return the final result
}

int main() {
    char input[100];

    // Get input string from the user
    printf("Enter a string of digits: ");
    fgets(input, sizeof(input), stdin);

    // Remove the newline character if it's present in the string
    int i = 0;
    while (input[i] != '\0') {
        if (input[i] == '\n') {
            input[i] = '\0';  // Replace newline with null terminator
            break;
        }
        i++;
    }

    // Call the function and print the result
    int result = ascii_to_integer(input);
    printf("Converted integer: %d\n", result);

    return 0;
}

