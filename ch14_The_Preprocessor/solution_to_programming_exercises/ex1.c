#include <stdio.h>

// Dummy declarations (to be implemented elsewhere)
void print_ledger_long(void);
void print_ledger_detailed(void);
void print_ledger_default(void);

// Function that selects the correct ledger format to print
void print_ledger(int arg) {
    // Use preprocessor directives to choose implementation at compile time
#ifdef OPTION_LONG
    print_ledger_long();
#elif defined(OPTION_DETAILED)
    print_ledger_detailed();
#else
    print_ledger_default();
#endif
}


  /* How to Compile for Different Editions

Use the -D compiler flag to define the appropriate symbol:

    For long version:

gcc -DOPTION_LONG main.c -o program

For detailed version:

gcc -DOPTION_DETAILED main.c -o program

For default version (neither defined):

gcc main.c -o program    */
