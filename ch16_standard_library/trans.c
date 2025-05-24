// trans.c
// Implementation of transaction-related functions

#include "trans.h"
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Static transaction ID counter (increments with each new transaction)
static int transaction_id = 1;

// Dummy data source: we simulate input by returning a fixed number of transactions
#define MAX_TRANSACTIONS 5
static int current_count = 0;

// Function to simulate getting a transaction
Trans *get_trans() {
    if (current_count >= MAX_TRANSACTIONS) {
        return NULL;  // No more transactions
    }

    // Allocate memory for a new transaction
    Trans *t = malloc(sizeof(Trans));
    if (!t) {
        perror("Failed to allocate memory for transaction");
        return NULL;
    }

    // Populate the transaction with sample data
    t->id = transaction_id++;
    t->amount = (float)(rand() % 10000) / 100.0f;  // Random amount between 0.00 and 99.99

    current_count++;
    return t;
}

// Function to process a transaction (dummy example)
void process_trans(Trans *t) {
    if (!t) return;

    // Simple validation: reject negative or zero amounts
    if (t->amount <= 0) {
        fprintf(stderr, "Error: Invalid transaction amount: %.2f\n", t->amount);
        free(t);  // Free memory even on error
        // Jump back to setjmp point with error code 1
        extern jmp_buf restart;
        longjmp(restart, 1);
    }

    // Print the transaction
    printf("Processing Transaction ID %d: $%.2f\n", t->id, t->amount);
    free(t);  // Free after processing
}

// Function to simulate saving transaction results to a file
void write_data_to_file() {
    FILE *file = fopen("transactions.txt", "w");
    if (!file) {
        perror("Could not open file for writing");
        return;
    }

    // Write summary or log message (in a real system, would write each transaction)
    fprintf(file, "All transactions have been processed and saved.\n");
    fclose(file);
}

