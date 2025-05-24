#include <stdio.h>

// Function to compute the greatest common divisor (GCD) of M and N
int gcd(int M, int N) {
    // If either M or N is less than or equal to zero, return 0
    if (M <= 0 || N <= 0) {
        return 0;
    }

    // Base case: If M is divisible by N, then gcd(M, N) is N
    if (M % N == 0) {
        return N;
    }

    // Recursive case: gcd(N, M % N)
    return gcd(N, M % N);
}

int main() {
    int M, N;

    // Input two integers M and N
    printf("Enter two positive integers: ");
    scanf("%d %d", &M, &N);

    // Calculate and print the GCD of M and N
    int result = gcd(M, N);
    if (result == 0) {
        printf("GCD cannot be calculated as one or both numbers are non-positive.\n");
    } else {
        printf("The GCD of %d and %d is %d\n", M, N, result);
    }

    return 0;
}

