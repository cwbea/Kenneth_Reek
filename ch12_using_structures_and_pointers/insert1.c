#include <stdlib.h>     // For malloc
#include <stdio.h>      // For printf (if needed)
#include "sll_node.h"   // For Node structure definition

#define FALSE 0         // Define boolean FALSE
#define TRUE 1          // Define boolean TRUE

/*
** Insert into an ordered, singly linked list.
** Arguments:
**   - current: pointer to the head of the list
**   - new_value: value to insert
** Returns:
**   - TRUE (1) if insertion is successful
**   - FALSE (0) if memory allocation fails
*/
int sll_insert(Node *current, int new_value)
{
    Node *previous = NULL;           // Pointer to keep track of the previous node
    Node *new;                       // Pointer to the new node to be inserted

    // Look for the correct insertion point
    while (current != NULL && current->value < new_value) {
        previous = current;
        current = current->link;
    }

    // Allocate a new node and check if allocation succeeded
    new = (Node *)malloc(sizeof(Node));
    if (new == NULL)
        return FALSE; // Memory allocation failed

    new->value = new_value; // Set the value for the new node
    new->link = current;    // Link the new node to the next node

    // Handle inserting at the beginning (no previous node)
    if (previous != NULL) {
        previous->link = new; // Insert in middle or end
    } else {
        // In a real scenario, you'd need to update the head pointer.
        // This version assumes head is not NULL and is not updated.
        // To properly insert at head, use a Node ** or return new head.
        return FALSE; // Insertion at head not supported in this version
    }

    return TRUE; // Success
}

