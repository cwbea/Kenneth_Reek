/*
** Insert a value into a doubly linked list.
** rootp is a pointer to the root node (not a real list node).
** value is the new value to insert.
**
** Returns:
**   0  - if the value already exists in the list.
**  -1  - if memory allocation fails.
**   1  - if the value is inserted successfully.
*/

#include <stdlib.h>
#include <stdio.h>
#include "dll_node.h"

int dll_insert(register Node *rootp, int value) {
    register Node *this;      // Pointer to current node (used to find insertion point)
    register Node *next;      // Pointer to the next node after current
    register Node *newnode;   // Pointer to the new node to be inserted

    // Traverse the list to find the right place for insertion
    for (this = rootp; (next = this->fwd) != NULL; this = next) {
        if (next->value == value)
            return 0;  // Value already exists, do not insert
        if (next->value > value)
            break;     // Found where to insert (before a larger value)
    }

    // Allocate memory for the new node
    newnode = (Node *)malloc(sizeof(Node));
    if (newnode == NULL)
        return -1; // Memory allocation failed

    newnode->value = value; // Set the value of the new node

    // ----- Begin linking the new node into the list -----

    newnode->fwd = next;   // Point new node forward to 'next'
    this->fwd = newnode;   // Link previous node ('this') to new node

    if (this != rootp)
        newnode->bwd = this;    // Link back from new node to 'this'
    else
        newnode->bwd = NULL;    // If at front, there's no previous node

    if (next != NULL)
        next->bwd = newnode;    // Link back from 'next' to new node
    else
        rootp->bwd = newnode;   // If at end, update root's back pointer

    return 1; // Insertion successful
}

