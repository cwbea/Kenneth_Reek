/*
** Program to process command-line arguments.
** It supports options like -a and -b, and can process files or standard input.
*/

#include <stdio.h>  // Standard I/O library for input/output functions

#define TRUE 1      // Define TRUE as 1 (used for setting options)

/* ---------------------------------------------------
   Function prototypes for functions that will do the 
   actual processing. Definitions should be elsewhere.
--------------------------------------------------- */
void process_standard_input(void);         // Function to handle standard input
void process_file(char *file_name);        // Function to process an individual file

/* ---------------------------------------------------
   Option flags (global variables).
   These will be turned ON (TRUE) if the corresponding
   command-line option (-a, -b, etc.) is given.
   By default, they are FALSE (off).
--------------------------------------------------- */
int option_a = 0;
int option_b = 0;
// Add more option flags here as needed

/* ---------------------------------------------------
   Main function - program execution starts here.
   Parameters:
   - argc: number of command-line arguments
   - argv: array of strings holding each argument
--------------------------------------------------- */
int main(int argc, char **argv)
{
    /*
    ** Process option arguments first.
    ** Skip the program name (argv[0]) and loop over the
    ** rest of the arguments as long as they start with '-'.
    */
    while (*++argv != NULL && **argv == '-') {

        /*
        ** Move to the option letter (after the dash)
        ** and check what option it is.
        */
        switch (*++*argv) {   // Get the character after '-'

            case 'a':         // If the option is '-a'
                option_a = TRUE;
                break;

            case 'b':         // If the option is '-b'
                option_b = TRUE;
                break;

            // Add more options (e.g., case 'c': ...) here as needed

            default:
                // Optional: handle invalid options
                printf("Unknown option: -%c\n", **argv);
                break;
        }
    }

    /*
    ** After options are processed, check if there are
    ** any file names left to process.
    */
    if (*argv == NULL) {
        // No files were provided, so process standard input
        process_standard_input();
    } else {
        // Process each file provided in the arguments
        do {
            process_file(*argv);
        } while (*++argv != NULL);  // Move to next file
    }

    return 0; // Return success
}

/*
** Process command-line arguments
** This program handles options like `-a`, `-b`, etc.,
** and processes either standard input or listed files.
*/

#include <stdio.h>  // For printf, standard input/output

#define TRUE 1      // Define TRUE as 1
#define FALSE 0     // Define FALSE as 0

// Option flags, initialized to FALSE by default
int option_a = FALSE;
int option_b = FALSE;
/* You can add more option flags as needed */

// Prototypes for functions that do the actual work
void process_standard_input(void);         // Handles standard input
void process_file(char *file_name);        // Handles file input

// Main function: Entry point of the program
int main(int argc, char **argv)
{
    /*
    ** Process option arguments:
    ** Skip to the next argument and check that it starts with a dash '-'
    */
    while (*++argv != NULL && **argv == '-') {
        /*
        ** Check the character after the dash to determine the option
        ** *++*argv means:
        **   - *argv: current argument (like "-a")
        **   - ++*argv: move past the '-' to point to 'a'
        **   - *++*argv: dereference to get the character 'a'
        */
        switch (*++*argv) {
            case 'a':
                option_a = TRUE;
                break;
            case 'b':
                option_b = TRUE;
                break;
            // Add more options here if needed
            default:
                printf("Unknown option: -%c\n", **argv);
                break;
        }
    }

    /*
    ** Process file name arguments
    ** If no more arguments are provided, use standard input
    */
    if (*argv == NULL) {
        process_standard_input();  // No files provided
    } else {
        // Process each file name argument
        do {
            process_file(*argv);
        } while (*++argv != NULL);
    }

    return 0;  // Successful execution
}

/*
** Dummy implementation of processing standard input
*/
void process_standard_input(void) {
    printf("Processing standard input...\n");
    // Add logic for reading from stdin here
}

/*
** Dummy implementation of processing a file
*/
void process_file(char *file_name) {
    printf("Processing file: %s\n", file_name);
    // Add logic for reading from the file here
}


//   (*++argv means "Dereference the result of pre-incrementing the value pointed to by argv, and check that it is not null.
//  (*++*argv also means "Advance to the next character in the current argument string and check if it's not null."

/* when running e.g  ./program -a

Then:

    *argv initially points to "-a".

    ++*argv increments the pointer to point to "a".

    *++*argv gets 'a'.

    If this is not '\0', we can continue processing.
*/
