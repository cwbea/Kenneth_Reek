#include <stdio.h>   // For input/output functions like printf
#include <string.h>  // For string handling functions like strchr

// Function prototype for argument parser
// argc: number of command-line arguments
// argv: array of argument strings
// control: string defining valid options and which ones need values
// do_arg: callback for valid options
// illegal_arg: callback for invalid options
char **do_args(
    int argc,
    char **argv,
    char *control,
    void (*do_arg)(int ch, char *value),
    void (*illegal_arg)(int ch)
) {
    int i = 1; // Start processing from argv[1], skip argv[0] which is program name

    // Loop while arguments start with '-'
    while (i < argc && argv[i][0] == '-') {
        char *arg = argv[i] + 1; // Skip the leading '-' and point to the first character

        // Process each character after '-' in the argument
        while (*arg) {
            char ch = *arg; // Current flag character (like x, y, etc.)
            char *pos = strchr(control, ch); // Find if character exists in control string

            if (!pos) {
                // Character not found in control string — illegal argument
                illegal_arg(ch); // Call the illegal argument handler
                arg++; // Move to next character
                continue; // Continue to next character in this arg
            }

            if (*(pos + 1) == '+') {
                // If the character is followed by '+' in control, it requires a value
                char *value = NULL; // Initialize value pointer

                if (*(arg + 1)) {
                    // If value is right after the option character (e.g., -x123)
                    value = arg + 1;
                    do_arg(ch, value); // Call do_arg with the value
                    break; // Done with this argv[i], move to next
                } else if ((i + 1) < argc && argv[i + 1][0] != '-') {
                    // If value is in the next argument and it's not another option
                    value = argv[i + 1];
                    do_arg(ch, value); // Call do_arg with the value
                    i++; // Skip value in next loop iteration
                } else {
                    // Expected value is missing
                    illegal_arg(ch); // Call illegal_arg since value is missing
                }
                break; // Done with this argv[i], move to next
            } else {
                // Character does not require a value (flag only)
                do_arg(ch, NULL); // Call do_arg with NULL value
                arg++; // Move to next character in this argument string
            }
        }
        i++; // Move to the next argv[i] argument
    }

    return &argv[i]; // Return pointer to remaining (non-option) arguments
}

// Sample callback function to handle valid options
// ch: option character
// value: associated value if any
void handle_arg(int ch, char *value) {
    if (value)
        printf("Option -%c with value: %s\n", ch, value); // Print option with value
    else
        printf("Option -%c with no value\n", ch); // Print flag option with no value
}

// Sample callback function to handle illegal/unknown options
// ch: illegal option character
void handle_illegal(int ch) {
    printf("Illegal option: -%c\n", ch); // Print message for illegal option
}

// Main function to demonstrate how do_args works
int main(int argc, char *argv[]) {
    // Define the control string:
    // 'x' and 'y' require values (followed by '+'), 'z' is just a flag
    char control[] = "x+y+z";

    // Call do_args with control string and callbacks
    char **remaining = do_args(argc, argv, control, handle_arg, handle_illegal);

    // Print remaining arguments that were not processed as options
    printf("Remaining arguments:\n");
    while (*remaining) {
        printf("%s\n", *remaining); // Print each remaining argument
        remaining++;
    }

    return 0; // Exit program successfully
}

