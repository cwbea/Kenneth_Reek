#include <stdio.h>

// Recursive function to compute Hermite polynomial Hn(x)
int hermite(int n, int x) {
    // Base case for H0(x)
    if (n == 0) {
        return 1;
    }
    // Base case for H1(x)
    else if (n == 1) {
        return 2 * x;
    }
    // Recursive case for n >= 2
    else {
        return 2 * x * hermite(n - 1, x) - 2 * (n - 1) * hermite(n - 2, x);
    }
}

int main() {
    int n = 3;  // For example, compute H3(x)
    int x = 2;  // For example, evaluate at x = 2
    
    // Compute and print the value of H3(2)
    printf("H%d(%d) = %d\n", n, x, hermite(n, x));
    
    return 0;
}

