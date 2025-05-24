/*
** A client that uses the generic stack module to create two stacks
** holding different types of data.
*/

#include <stdlib.h>
#include <stdio.h>
#include "g_stack.h"  // Assumed header file that defines GENERIC_STACK macro

/*
** Create two stacks: one for integers and one for floats.
*/
GENERIC_STACK(int, _int, 10)
GENERIC_STACK(float, _float, 5)

int main() {
    /*
    ** Push several values on each stack.
    */
    push_int(5);
    push_int(22);
    push_int(15);

    push_float(25.3f);
    push_float(-40.5f);

    /*
    ** Empty the integer stack and print the values.
    */
    while (!is_empty_int()) {
        printf("Popping %d\n", top_int());
        pop_int();
    }

    /*
    ** Empty the float stack and print the values.
    */
    while (!is_empty_float()) {
        printf("Popping %f\n", top_float());
        pop_float();
    }

    return EXIT_SUCCESS;
}

