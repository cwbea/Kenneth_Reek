// trans.h
// Header file that defines the Trans structure and transaction-related functions

#ifndef TRANS_H
#define TRANS_H

// Define the structure of a transaction
typedef struct {
    int id;           // Unique transaction ID
    float amount;     // Amount of the transaction
} Trans;

// Function declarations:

/**
 * Reads and returns the next transaction from input.
 * Returns NULL when there are no more transactions.
 */
Trans *get_trans();

/**
 * Processes a transaction (e.g., displays it, validates it).
 * Assumes the transaction is not NULL.
 */
void process_trans(Trans *t);

/**
 * Saves all transaction data to a file (e.g., transactions.txt).
 * Called once at the end of the program.
 */
void write_data_to_file();

#endif  // TRANS_H

