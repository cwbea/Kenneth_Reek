#include <stdio.h>
#include <stdbool.h>  // To use the boolean data type (true/false)
#include <math.h>     // To use math functions like sqrt() for optimization

#define MAX_LIMIT 1000 // Define the maximum number to check for primes (you can change this)

void sieve_of_eratosthenes(bool *sieve) {
    // The sieve function is responsible for marking non-prime numbers

    sieve[0] = false; // 0 is not a prime number, so we mark it as false
    sieve[1] = false; // 1 is not a prime number, so we mark it as false

    // Start with the first prime (2) and cross out its multiples
    for (int i = 2; i * i <= MAX_LIMIT; i++) {  // Loop through numbers from 2 up to sqrt(MAX_LIMIT)
        if (sieve[i]) {  // If the number at index i is still marked as prime (true)
            // Now, cross out multiples of i starting from i*i (optimization: start from i*i)
            for (int j = i * i; j <= MAX_LIMIT; j += i) {  // Start crossing out numbers from i*i
                sieve[j] = false;  // Mark this number as non-prime (false)
            }
        }
    }
}

void print_primes(bool *sieve) {
    // Function to print all the prime numbers found in the sieve

    printf("Prime numbers up to %d are:\n", MAX_LIMIT);  // Print the limit for prime numbers
    for (int i = 2; i <= MAX_LIMIT; i++) {  // Loop through all numbers from 2 to MAX_LIMIT
        if (sieve[i]) {  // If sieve[i] is true, it means 'i' is prime
            printf("%d ", i);  // Print the prime number
        }
    }
    printf("\n");  // Print a newline after all the prime numbers are printed
}

int main() {
    // The main function where the program starts

    bool sieve[MAX_LIMIT + 1];  // Declare an array of boolean values (size MAX_LIMIT + 1)
                                // Each index represents a number, and the value indicates whether it's prime

    // Initially, assume all numbers are prime, so set them all to true
    for (int i = 0; i <= MAX_LIMIT; i++) {
        sieve[i] = true;  // Set all elements to true (assuming all numbers are prime)
    }

    // Apply the Sieve of Eratosthenes algorithm to find primes
    sieve_of_eratosthenes(sieve);  // Call the sieve function, passing the sieve array

    // Print the primes found using the sieve
    print_primes(sieve);  // Call the print function to display prime numbers

    return 0;  // Return 0 to indicate successful execution of the program
}

