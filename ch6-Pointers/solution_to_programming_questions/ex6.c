#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Define the maximum value to which we want to find primes.
#define MAX_LIMIT 1000000 // We set a limit of 1,000,000 for finding primes.

#define BIT_INDEX(n) ((n) / 8) // Calculate the byte index for the bit representing number n
#define BIT_POS(n) ((n) % 8)   // Calculate the position of the bit within the byte for number n

// Function to set a specific bit to 1 (indicating 'true' or 'prime')
void set_bit(unsigned char *bit_array, int n) {
    bit_array[BIT_INDEX(n)] |= (1 << BIT_POS(n));  // Set the bit at position n to 1
}

// Function to clear a specific bit to 0 (indicating 'false' or 'not prime')
void clear_bit(unsigned char *bit_array, int n) {
    bit_array[BIT_INDEX(n)] &= ~(1 << BIT_POS(n)); // Set the bit at position n to 0 (clear)
}

// Function to check if a specific bit is set (indicating whether it's prime or not)
bool check_bit(unsigned char *bit_array, int n) {
    return (bit_array[BIT_INDEX(n)] & (1 << BIT_POS(n))) != 0; // Return true if the bit is 1, indicating prime
}

// The sieve algorithm that marks non-primes in the array
void sieve_of_eratosthenes(unsigned char *bit_array) {
    clear_bit(bit_array, 0); // Mark 0 as non-prime
    clear_bit(bit_array, 1); // Mark 1 as non-prime

    // Start the sieve process. We only need to go up to sqrt(MAX_LIMIT)
    for (int i = 2; i * i <= MAX_LIMIT; i++) { 
        if (check_bit(bit_array, i)) { // If 'i' is still marked as prime
            for (int j = i * i; j <= MAX_LIMIT; j += i) {
                clear_bit(bit_array, j); // Mark multiples of 'i' as non-prime
            }
        }
    }
}

// Function to count how many prime numbers exist within a specific range
int count_primes_in_range(unsigned char *bit_array, int start, int end) {
    int count = 0;  // Initialize the counter for primes
    for (int i = start; i <= end; i++) {
        if (check_bit(bit_array, i)) { // If the bit for i is set (prime)
            count++;  // Increment the prime counter
        }
    }
    return count;  // Return the total number of primes found in this range
}

// Function to count the primes in all ranges of 1000 numbers up to MAX_LIMIT
void count_primes_in_ranges(unsigned char *bit_array) {
    // Loop through ranges from 0 to MAX_LIMIT in steps of 1000
    for (int i = 0; i < MAX_LIMIT; i += 1000) {
        int end = i + 999;  // The end of the current range
        if (end > MAX_LIMIT) {
            end = MAX_LIMIT;  // Ensure that the last range ends at MAX_LIMIT
        }

        int prime_count = count_primes_in_range(bit_array, i, end); // Count primes in the current range
        // Print the number of primes found in this range
        printf("Primes between %d and %d: %d\n", i, end, prime_count);
    }
}

// The main function that initializes the sieve and performs the counting
int main() {
    unsigned char bit_array[MAX_LIMIT / 8 + 1]; // Array of bits to mark primes. One byte (8 bits) per 8 numbers.

    // Initialize the bit array to 0 (meaning all numbers are marked as 'non-prime' initially)
    for (int i = 0; i < MAX_LIMIT / 8 + 1; i++) {
        bit_array[i] = 0;  // Set all bits to 0 (indicating 'not prime')
    }

    // Apply the Sieve of Eratosthenes to mark the primes in the bit array
    sieve_of_eratosthenes(bit_array);

    // Count and display the primes in ranges of 1000 numbers
    count_primes_in_ranges(bit_array);

    return 0;  // Return from main, ending the program
}

