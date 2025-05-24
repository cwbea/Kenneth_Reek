#include <stdio.h>      // For printf (used in main to print results)
#include <stdlib.h>     // For rand() and srand()
#include <time.h>       // For time() to get the current time of day

// Function: roll_die
// ------------------
// Simulates rolling a fair six-sided die.
// Returns a random number between 1 and 6, inclusive.
// The first time it's called, it seeds the random number generator
// with the current time, so results are different each time the program runs.
int roll_die() {
    // 'static' means this variable retains its value between function calls
    // It's used to make sure we only seed the random number generator once
    static int seeded = 0;

    // If this is the first time the function is being called, seed the RNG
    if (!seeded) {
        // Seed the random number generator with the current time
        // This ensures a different sequence of random numbers each time the program runs
        srand((unsigned int)time(NULL));

        // Mark that we’ve seeded it, so we don’t do it again
        seeded = 1;
    }

    // rand() generates a random integer. We use modulo 6 and add 1 to get range 1–6.
    // Example: rand() % 6 gives 0–5, so we add 1 → final range is 1–6
    return (rand() % 6) + 1;
}

// Main function to demonstrate how the roll_die function works
int main() {
    printf("Rolling a six-sided die 10 times:\n");

    // Roll the die 10 times and print the result
    for (int i = 0; i < 10; i++) {
        int result = roll_die();  // Call our function to get a die roll
        printf("Roll %d: %d\n", i + 1, result);  // Print the result
    }

    return 0;  // Exit the program successfully
}

