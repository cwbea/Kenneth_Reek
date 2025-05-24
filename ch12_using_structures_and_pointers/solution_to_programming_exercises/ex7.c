#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // For isalpha() function

// Define the concordance node structure
typedef struct concordance_node {
    char *word;                      // Word itself
    struct concordance_node *next;    // Pointer to the next node in the primary list
    struct concordance_node *secondary; // Pointer to a secondary list of words starting with the same letter
} ConcordanceNode;

// Function to insert a new word into the concordance list
// rootp is a pointer to the root of the list, and word is the word to insert
// Returns true if the word is inserted successfully, false if the word already exists
int insert_word(ConcordanceNode **rootp, const char *word) {
    if (word == NULL || !isalpha(word[0])) {
        // If the word is NULL or does not start with a letter, return false
        return 0;
    }

    // Search for the word in the primary list
    ConcordanceNode *current = *rootp;
    ConcordanceNode *prev = NULL;
    ConcordanceNode *new_node = NULL;
    int inserted = 0;

    // Traverse the list to find if the word already exists or find the position to insert
    while (current != NULL && current->word[0] < word[0]) {
        prev = current;
        current = current->next;
    }

    if (current != NULL && current->word[0] == word[0]) {
        // Word exists in the primary list, check if it exists in the secondary list
        ConcordanceNode *sec_current = current->secondary;
        while (sec_current != NULL) {
            if (strcmp(sec_current->word, word) == 0) {
                // Word already exists, return false
                return 0;
            }
            sec_current = sec_current->next;
        }

        // Word does not exist in the secondary list, insert it there
        new_node = (ConcordanceNode *)malloc(sizeof(ConcordanceNode));
        if (new_node == NULL) {
            // Memory allocation failed
            return 0;
        }
        new_node->word = strdup(word); // Copy the word into dynamically allocated memory
        new_node->next = NULL; // The new node is the last node in the secondary list

        // Insert the new node into the secondary list in alphabetical order
        ConcordanceNode *sec_prev = NULL;
        sec_current = current->secondary;
        while (sec_current != NULL && strcmp(sec_current->word, word) < 0) {
            sec_prev = sec_current;
            sec_current = sec_current->next;
        }

        if (sec_prev == NULL) {
            // Insert at the beginning of the secondary list
            current->secondary = new_node;
        } else {
            // Insert in the middle or end of the secondary list
            sec_prev->next = new_node;
            new_node->next = sec_current;
        }
        inserted = 1;
    } else {
        // The word does not exist in the primary list, insert it there
        new_node = (ConcordanceNode *)malloc(sizeof(ConcordanceNode));
        if (new_node == NULL) {
            // Memory allocation failed
            return 0;
        }
        new_node->word = strdup(word); // Copy the word into dynamically allocated memory
        new_node->next = current; // Insert it into the primary list
        new_node->secondary = NULL; // No secondary list yet for this word

        // Insert the new node into the primary list in alphabetical order by first letter
        if (prev == NULL) {
            // Insert at the beginning of the primary list
            *rootp = new_node;
        } else {
            // Insert in the middle or end of the primary list
            prev->next = new_node;
        }

        inserted = 1;
    }

    return inserted; // Return 1 if inserted, 0 otherwise
}

// Function to print the concordance list for debugging purposes
void print_concordance(ConcordanceNode *root) {
    ConcordanceNode *current = root;
    while (current != NULL) {
        printf("Primary Word: %s\n", current->word);
        ConcordanceNode *sec_current = current->secondary;
        while (sec_current != NULL) {
            printf("  Secondary Word: %s\n", sec_current->word);
            sec_current = sec_current->next;
        }
        current = current->next;
    }
}

// Main function for testing
int main() {
    ConcordanceNode *root = NULL; // Initialize the root of the concordance list

    // Insert some words into the list
    insert_word(&root, "apple");
    insert_word(&root, "banana");
    insert_word(&root, "apricot");
    insert_word(&root, "avocado");
    insert_word(&root, "ball");

    // Print the concordance list
    printf("Concordance List:\n");
    print_concordance(root);

    return 0;
}

