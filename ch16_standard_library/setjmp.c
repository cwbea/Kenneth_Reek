/*
 * A program to demonstrate the use of setjmp and longjmp
 * These functions allow jumping back to a saved execution point (like error recovery).
 */

#include "trans.h"     // Custom header file that defines the Trans struct and related functions
#include <stdio.h>     // For input/output functions like printf, fputs
#include <stdlib.h>    // For EXIT_SUCCESS, EXIT_FAILURE
#include <setjmp.h>    // For setjmp() and longjmp()

// Declare a variable to store the program state (execution context) for recovery
// setjmp() saves the program state into this buffer
// longjmp() later jumps back to this saved state
jmp_buf restart;

/**
 * Main function: program entry point.
 */
int main() {
    int value;                // Holds the return value of setjmp to determine how we got here
    Trans *transaction;       // Pointer to a transaction (defined in trans.h)

    /**
     * Save the current program state (like a checkpoint).
     * If setjmp is returning normally, it returns 0.
     * If longjmp later jumps back here, setjmp returns the value passed to longjmp.
     */
    value = setjmp(restart);

    /**
     * Use a switch statement to handle different types of returns from setjmp:
     * - 0: means this is the first time we've reached here (normal execution).
     * - 1: means we jumped back here from an error condition (minor error).
     * - default: means we jumped back here from a serious error.
     */
    switch (value) {
        default:
            // Any value other than 0 or 1 means a serious (fatal) error occurred.
            fputs("Fatal error.\n", stderr);  // Print error message to standard error
            break;

        case 1:
            // longjmp returned 1 => minor error occurred (e.g., invalid transaction)
            fputs("Invalid transaction.\n", stderr);  // Notify the user
            // No break: we deliberately fall through to continue processing

        case 0:
            // Normal execution or recovery from minor error.
            // Repeatedly get transactions and process them.
            while ((transaction = get_trans()) != NULL) {
                process_trans(transaction);  // Process each transaction
            }
            break;
    }

    /**
     * After processing is done (or after an error), save the data and clean up.
     * This function is assumed to be defined in trans.h and writes final data to a file.
     */
    write_data_to_file();

    /**
     * Return appropriate status:
     * - EXIT_SUCCESS if value == 0 (normal execution)
     * - EXIT_FAILURE if value != 0 (error occurred)
     */
    return value == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}

