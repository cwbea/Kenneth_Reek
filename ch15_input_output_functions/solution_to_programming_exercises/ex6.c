#include <stdio.h>   // For input/output functions like printf

// Function prototype: declares a function that checks if an integer is a palindrome
int numeric_palindrome(int value);

// This function checks whether the given integer is a palindrome.
// A palindrome number is the same when its digits are reversed.
int numeric_palindrome(int value) {
    int original = value;     // Store the original value for comparison later
    int reversed = 0;         // This will hold the reversed number
    int digit;                // To extract each digit from the number

    // Reverse the number
    while (value > 0) {
        digit = value % 10;          // Get the last digit (e.g., 123 % 10 = 3)
        reversed = reversed * 10 + digit; // Append the digit to reversed number
        value = value / 10;          // Remove the last digit (e.g., 123 / 10 = 12)
    }

    // If the reversed number is the same as the original, it's a palindrome
    if (reversed == original) {
        return 1;  // Return 1 (true)
    } else {
        return 0;  // Return 0 (false)
    }
}

// Main function to test numeric_palindrome
int main() {
    int number;

    // Ask the user to enter a number
    printf("Enter an integer: ");
    scanf("%d", &number);  // Read the number from the user

    // Call the function to check if the number is a palindrome
    if (numeric_palindrome(number)) {
        // If it returns true
        printf("%d is a palindrome.\n", number);
    } else {
        // If it returns false
        printf("%d is not a palindrome.\n", number);
    }

    return 0;  // End of the program
}

