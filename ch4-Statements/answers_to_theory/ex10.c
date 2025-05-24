#include <stdio.h>

int main() {
    int n;  // Declare an integer variable to hold the input

    // Read an integer value from standard input
    printf("Enter the number of blank lines: ");
    scanf("%d", &n);  // scanf reads an integer from the user input and stores it in 'n'

    // Print 'n' blank lines
    for (int i = 0; i < n; i++) {
        printf("\n");  // Print a blank line
    }

    return 0;
}

