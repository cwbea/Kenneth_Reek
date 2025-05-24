#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX_LIMIT 1000 // Define the maximum number to check for primes

// This macro returns the index of a bit in the array for a given number
#define BIT_INDEX(n) ((n) / 8)

// This macro returns the bit position within a byte for a given number
#define BIT_POS(n) ((n) % 8)

// Function to set the bit (mark as true)
void set_bit(unsigned char *bit_array, int n) {
    bit_array[BIT_INDEX(n)] |= (1 << BIT_POS(n)); // Set the nth bit to 1 (true)
}

// Function to clear the bit (mark as false)
void clear_bit(unsigned char *bit_array, int n) {
    bit_array[BIT_INDEX(n)] &= ~(1 << BIT_POS(n)); // Set the nth bit to 0 (false)
}

// Function to check the bit (if it is set to true)
bool check_bit(unsigned char *bit_array, int n) {
    return (bit_array[BIT_INDEX(n)] & (1 << BIT_POS(n))) != 0; // Check if the nth bit is 1 (true)
}

void sieve_of_eratosthenes(unsigned char *bit_array) {
    // Initialize 0 and 1 as not prime (clear their bits)
    clear_bit(bit_array, 0);
    clear_bit(bit_array, 1);

    // Start with the first prime (2) and cross out its multiples
    for (int i = 2; i * i <= MAX_LIMIT; i++) {
        if (check_bit(bit_array, i)) {  // If the number at index i is still marked as prime (true)
            // Now, cross out multiples of i starting from i*i (optimization: start from i*i)
            for (int j = i * i; j <= MAX_LIMIT; j += i) {
                clear_bit(bit_array, j);  // Mark this number as non-prime (false)
            }
        }
    }
}

void print_primes(unsigned char *bit_array) {
    // Function to print all the prime numbers found in the bit array

    printf("Prime numbers up to %d are:\n", MAX_LIMIT);  // Print the limit for prime numbers
    for (int i = 2; i <= MAX_LIMIT; i++) {  // Loop through all numbers from 2 to MAX_LIMIT
        if (check_bit(bit_array, i)) {  // If bit_array[i] is true, it means 'i' is prime
            printf("%d ", i);  // Print the prime number
        }
    }
    printf("\n");  // Print a newline after all the prime numbers are printed
}

int main() {
    // The main function where the program starts

    // Create a bit array with size enough to cover all numbers up to MAX_LIMIT.
    unsigned char bit_array[MAX_LIMIT / 8 + 1];  // We divide by 8 because each byte holds 8 bits

    // Initialize the bit array to 0 (all bits are false)
    for (int i = 0; i < MAX_LIMIT / 8 + 1; i++) {
        bit_array[i] = 0;  // Set all bits to 0 (false)
    }

    // Apply the Sieve of Eratosthenes algorithm to find primes
    sieve_of_eratosthenes(bit_array);  // Call the sieve function, passing the bit array

    // Print the primes found using the sieve
    print_primes(bit_array);  // Call the print function to display prime numbers

    return 0;  // Return 0 to indicate successful execution of the program
}

