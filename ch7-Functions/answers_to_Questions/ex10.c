#include <stdio.h>

// Global variable to count the number of function calls
int call_count = 0;

// Recursive Fibonacci function
int fibonacci(int n) {
    // Increment the call counter each time the function is called
    call_count++;

    // Base cases
    if (n == 0) return 0;
    if (n == 1) return 1;

    // Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    // Compute fibonacci(1) through fibonacci(10) and count the calls
    for (int i = 1; i <= 10; i++) {
        // Reset the call counter before each computation
        call_count = 0;

        // Calculate fibonacci and print the number of calls made
        printf("fibonacci(%d) = %d, Function calls: %d\n", i, fibonacci(i), call_count);
    }
    return 0;
}

