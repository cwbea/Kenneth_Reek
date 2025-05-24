/*
** Program to process each file whose name is provided on the command line.
** It attempts to open each file, and closes it after processing (actual processing not shown).
*/

#include <stdlib.h>  // For EXIT_SUCCESS, EXIT_FAILURE
#include <stdio.h>   // For FILE operations, perror, fopen, fclose, printf

int main(int ac, char **av) {
    int exit_status = EXIT_SUCCESS; // Will be EXIT_SUCCESS unless a file can't be opened
    FILE *input;                    // File pointer for reading input files

    /*
    ** Iterate through each command-line argument (skipping argv[0], the program name)
    */
    while (*++av != NULL) { // Increment av, then check if it's not NULL (end of args)
        
        /*
        ** Try to open the file in read mode ("r")
        */
        input = fopen(*av, "r");
        if (input == NULL) {
            // If fopen fails, print the error associated with the file
            perror(*av);
            // Indicate failure occurred (but continue with next files)
            exit_status = EXIT_FAILURE;
            continue; // Skip the rest and go to next file
        }

        /*
        ** Place to process the opened file
        ** For now, this section is left empty and should be filled with file logic
        */

        /*
        ** Close the file. We generally don't expect fclose to fail, but check anyway.
        */
        if (fclose(input) != 0) {
            // If fclose fails, print error and exit immediately
            perror("fclose");
            exit(EXIT_FAILURE);
        }
    }

    // Return final exit status: success unless at least one file couldn't be opened
    return exit_status;
}

