#include <stdio.h>

/*
** Static initialization
** This variable is globally visible and retains its value between function calls.
*/
int static_variable = 5;

/*
** This function returns an int, used to test function return protocols.
*/
int func_ret_int(int a, int b, register int c) {
    int d;
    d = b - 6;  // Simple arithmetic operation
    return a + b + c;  // Returns the sum of parameters
}

/*
** This function returns a double value (used to test double return type).
*/
double func_ret_double() {
    return 3.14;  // Constant double value returned
}

/*
** This function returns a pointer to a character (char *).
*/
char *func_ret_char_ptr(char *cp) {
    return cp + 1;  // Moves the pointer forward by one character
}

/*
** This function f() is used to test:
** - Register variables
** - External names
** - Pointer initialization
** - Function calling and return behavior
*/
void f() {
    // Register variables: stored in CPU registers for faster access (if available)
    register int i1, i2, i3, i4, i5,
                 i6, i7, i8, i9, i10;

    // Character pointers used to test pointer values and memory addressing
    char *c1, *c2, *c3, *c4, *c5,
         *c6, *c7, *c8, *c9, *c10;

    // Variable with a very long name to test compiler limits
    int a_very_long_name_to_see_how_long_they_can_be;

    // Normal integer and double variable declarations
    int dbl;

    // Assign values to register integers (demonstrates capacity)
    i1 = 1; i2 = 2; i3 = 3; i4 = 4; i5 = 5;
    i6 = 6; i7 = 7; i8 = 8; i9 = 9; i10 = 10;

    // Assigning addresses to character pointers (for illustration, not safe in practice)
    c1 = (char *)110; c2 = (char *)120;
    c3 = (char *)130; c4 = (char *)140;
    c5 = (char *)150; c6 = (char *)160;
    c7 = (char *)170; c8 = (char *)180;
    c9 = (char *)190; c10 = (char *)200;

    // Assign a value to the external-style variable
    a_very_long_name_to_see_how_long_they_can_be = 1;

    // Function calling and return tests:
    i2 = func_ret_int(10, i1, i10);         // Call int function
    dbl = func_ret_double();               // Call double function
    c1 = func_ret_char_ptr(c1);            // Call char* function
}

/*
** Entry point of the program
*/
int main() {
    f();  // Call the function to run all checks
    printf("Program completed.\n");
    return 0;
}

