#include <stdlib.h>     // For malloc
#include <stdio.h>      // Optional: For debugging/printing
#include "sll_node.h"   // Definition of Node

#define FALSE 0
#define TRUE 1

/*
** Insert into an ordered, singly linked list.
** Arguments:
**   - linkp: pointer to the pointer to the first node
**   - new_value: the integer value to insert in order
** Returns:
**   - TRUE (1) if insertion is successful
**   - FALSE (0) if memory allocation fails
*/
int sll_insert(register Node **linkp, int new_value)
{
    register Node *current;
    register Node *new;

    // Walk through the list to find the right spot for the new value
    while ((current = *linkp) != NULL && current->value < new_value) {
        linkp = &current->link;
    }

    // Allocate memory for the new node
    new = (Node *)malloc(sizeof(Node));
    if (new == NULL)
        return FALSE;  // Allocation failed

    // Fill in the new node
    new->value = new_value;
    new->link = current;

    // Link the new node into the list
    *linkp = new;

    return TRUE;  // Insertion successful
}

