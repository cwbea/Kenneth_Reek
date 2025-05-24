/*
** Implementation for a less error-prone memory allocator.
*/

#include <stdio.h>
#include <stdlib.h>
#include "alloc.h"

#undef malloc  // Prevent direct use of malloc

void *alloc(size_t size)
{
    void *new_mem;

    /*
    ** Ask for the requested memory, and check that we really
    ** got it.
    */
    new_mem = malloc(size);
    if (new_mem == NULL) {
        printf("Out of memory!\n");
        exit(1);
    }

    return new_mem;
}

