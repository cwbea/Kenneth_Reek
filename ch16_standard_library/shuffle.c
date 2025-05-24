#include <stdlib.h>  // For rand(), srand()
#include <time.h>    // For time()
#include <stdio.h>

// Define boolean-style constants for TRUE and FALSE
#define TRUE 1
#define FALSE 0

/**
 * This function randomly shuffles an array of integers (simulating a deck of cards).
 * 
 * @param deck    Pointer to an array of integers representing the deck.
 * @param n_cards The total number of cards in the deck (i.e., size of the array).
 */
void shuffle(int *deck, int n_cards)
{
    int i; // Loop counter for traversing the array during shuffle

    // This static variable is initialized only once, and keeps track if it's the first call.
    static int first_time = TRUE;

    /*
     * If this is the first time we are calling shuffle,
     * seed the random number generator using the current time.
     * This ensures a different shuffle each time the program runs.
     */
    if (first_time) {
        first_time = FALSE;                     // Mark that we've seeded already
        srand((unsigned int)time(NULL));        // Seed random number generator with current time
    }

    /*
     * Perform a Fisher-Yates shuffle.
     * Start from the end of the array and swap each element with a randomly chosen earlier element.
     */
    for (i = n_cards - 1; i > 0; i -= 1) {
        int where; // Index to swap with
        int temp;  // Temporary variable for swapping

        where = rand() % i;          // Pick a random index from 0 to i-1
        temp = deck[where];         // Save the value at the random index
        deck[where] = deck[i];      // Move the value at the current index to the random index
        deck[i] = temp;             // Move the saved value to the current index
    }
}

/**
 * Main function to demonstrate the shuffle function.
 */
int main() {
    int i;
    const int NUM_CARDS = 10;            // Number of cards in the deck
    int deck[NUM_CARDS];                 // Array to hold the "deck" of cards

    // Initialize deck with values 0 to 9
    for (i = 0; i < NUM_CARDS; i++) {
        deck[i] = i;
    }

    // Print original deck
    printf("Original deck:\n");
    for (i = 0; i < NUM_CARDS; i++) {
        printf("%d ", deck[i]);
    }
    printf("\n");

    // Shuffle the deck
    shuffle(deck, NUM_CARDS);

    // Print shuffled deck
    printf("Shuffled deck:\n");
    for (i = 0; i < NUM_CARDS; i++) {
        printf("%d ", deck[i]);
    }
    printf("\n");

    return 0;  // Program ends successfully
}

