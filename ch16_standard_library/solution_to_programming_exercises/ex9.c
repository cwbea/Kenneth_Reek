#include <stdio.h>      // For input/output functions like printf
#include <stdlib.h>     // For rand(), malloc(), free(), atoi()
#include <time.h>       // For time() to seed the random number generator
#include <stdbool.h>    // For using bool type (true/false)

// Define how many times we simulate (the more, the more accurate the estimate)
#define TRIALS 10000

// Function to run the birthday simulation
// Parameters:
// - groupSize: number of people in the group
// Returns: 1 if any two people share a birthday, 0 otherwise
int birthday_simulation(int groupSize) {
    bool birthdays[365] = { false }; // Array to track which birthdays have occurred

    for (int i = 0; i < groupSize; i++) {
        int birthday = rand() % 365; // Generate a random day of the year (0 to 364)

        if (birthdays[birthday]) {
            // If we've already seen this birthday, return success (a match)
            return 1;
        }

        birthdays[birthday] = true; // Mark this birthday as seen
    }

    return 0; // No shared birthday found
}

int main(int argc, char *argv[]) {
    int groupSize = 30; // Default group size is 30

    // If user provides group size as a command line argument, use it
    if (argc == 2) {
        groupSize = atoi(argv[1]); // Convert string to integer
    }

    // Seed the random number generator with the current time
    srand(time(NULL));

    int successCount = 0; // Counter for how many times a shared birthday occurred

    // Run the birthday simulation multiple times
    for (int i = 0; i < TRIALS; i++) {
        if (birthday_simulation(groupSize)) {
            successCount++; // Increment if there was at least one shared birthday
        }
    }

    // Calculate the estimated probability (as a percentage)
    double probability = (double)successCount / TRIALS * 100.0;

    // Print the result
    printf("In a group of %d people, the probability of a shared birthday is approximately %.2f%%\n", groupSize, probability);

    return 0; // Program finished successfully
}

