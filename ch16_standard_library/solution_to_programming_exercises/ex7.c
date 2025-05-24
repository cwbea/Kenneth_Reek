#include <stdio.h>      // Includes standard input/output functions like printf
#include <stdlib.h>     // Includes functions for random numbers (rand, srand) and atoi (string to int)
#include <time.h>       // Includes time functions to get the current time for seeding the random number generator

// Define a constant for how many random numbers we want to generate
#define NUM_RANDOMS 10000

// Define the maximum divisor for our modulo tests (we'll test mod 2 through mod 10)
#define MAX_MOD 10

// Main function — entry point of the program
int main(int argc, char *argv[]) {
    int seed;  // Variable to store the random seed

    // Check if a seed is provided as a command-line argument
    if (argc > 1) {
        seed = atoi(argv[1]); // Convert the string argument to an integer and use it as the seed
    } else {
        // If no seed is given, use the current time as a seed (this makes the results different each time)
        seed = (int)time(NULL);
    }

    srand(seed); // Seed the random number generator with the selected seed

    // Show the user what seed was used
    printf("Using seed: %d\n", seed);

    // Declare a 2D array to hold the count of remainders for each modulus (frequency test)
    // frequency[mod][remainder] keeps count of how often a remainder appears when random numbers are taken modulo `mod`
    int frequency[MAX_MOD + 1][MAX_MOD];

    // Declare a 3D array to track pairs of remainders (cyclic frequency test)
    // cyclic_frequency[mod][previous_remainder][current_remainder]
    int cyclic_frequency[MAX_MOD + 1][MAX_MOD][MAX_MOD];

    // Initialize all entries in both arrays to zero before we start counting
    for (int mod = 2; mod <= MAX_MOD; mod++) { // Loop over each modulus from 2 to 10
        for (int i = 0; i < mod; i++) {        // Loop over each possible remainder for the current modulus
            frequency[mod][i] = 0;             // Set the frequency count to 0
            for (int j = 0; j < mod; j++) {
                cyclic_frequency[mod][i][j] = 0; // Set all cyclic frequency counts to 0
            }
        }
    }

    int prev = rand(); // Generate the first random number to serve as the "previous" value for cyclic comparisons

    // Generate the rest of the random numbers (10,000 total)
    for (int i = 1; i < NUM_RANDOMS; i++) {
        int current = rand(); // Generate a new random number

        // Loop over all modulus values from 2 to 10
        for (int mod = 2; mod <= MAX_MOD; mod++) {
            int rem = current % mod; // Get the remainder when current number is divided by mod
            int prem = prev % mod;   // Get the remainder for the previous number

            frequency[mod][rem]++; // Count how many times this remainder occurs for this modulus

            // Count how often the pair (previous_remainder -> current_remainder) occurs
            cyclic_frequency[mod][prem][rem]++;
        }

        prev = current; // Set current number as previous for the next loop
    }

    // ---------- Output results ----------

    // Print frequency test results
    printf("\n--- Frequency Test ---\n");
    for (int mod = 2; mod <= MAX_MOD; mod++) {
        printf("Modulo %d: ", mod); // Show the current modulus
        for (int i = 0; i < mod; i++) {
            printf("%d=%d ", i, frequency[mod][i]); // Print the count of each remainder
        }
        printf("\n");
    }

    // Print cyclic frequency test results
    printf("\n--- Cyclic Frequency Test ---\n");
    for (int mod = 2; mod <= MAX_MOD; mod++) {
        printf("Modulo %d:\n", mod); // Show the current modulus
        for (int i = 0; i < mod; i++) {           // Loop over all previous remainders
            for (int j = 0; j < mod; j++) {       // Loop over all current remainders
                // Print how many times we saw the pattern (previous -> current)
                printf("(%d->%d)=%d  ", i, j, cyclic_frequency[mod][i][j]);
            }
            printf("\n"); // New line for next row of remainder pairs
        }
        printf("\n"); // Extra line between moduli for clarity
    }

    return 0; // End of program
}

