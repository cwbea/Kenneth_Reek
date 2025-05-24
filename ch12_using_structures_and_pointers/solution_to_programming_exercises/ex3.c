#include <stdlib.h>   // Required for malloc (memory allocation)
#include <stdio.h>    // Required for input/output (not used here but common in C programs)
#include "dll_node.h" // Contains the definition of the Node structure

/*
** This function inserts a value into a doubly linked list
** where the list is maintained in ascending order.
**
** Parameters:
**   headp - a pointer to a pointer to the first (head) node in the list
**   tailp - a pointer to a pointer to the last (tail) node in the list
**   value - the integer value to insert into the list
**
** Returns:
**   0  - if the value already exists in the list (no duplicates allowed)
**  -1  - if memory allocation for the new node fails
**   1  - if the value is inserted successfully
*/
int dll_insert_separate(Node **headp, Node **tailp, int value) {
    Node *current = *headp;  // Start from the head of the list
    Node *prev = NULL;       // Pointer to keep track of the previous node during traversal
    Node *newnode;           // Pointer for the new node to be inserted

    // Traverse the list to find the correct place for insertion
    // Stop if we find a node with value >= the one we're inserting
    while (current != NULL && current->value < value) {
        if (current->value == value)
            return 0;  // Value already exists, no insertion needed
        prev = current;      // Move prev one node forward
        current = current->fwd; // Move current one node forward
    }

    // Check again in case current node has the value (edge case for first node)
    if (current != NULL && current->value == value)
        return 0;  // Duplicate found, don't insert

    // Allocate memory for the new node
    newnode = (Node *)malloc(sizeof(Node));
    if (newnode == NULL)
        return -1;  // Memory allocation failed

    newnode->value = value;  // Set the value field of the new node

    // Now we insert the new node at the correct place
    if (prev == NULL) {
        // Inserting at the very beginning of the list (before the head)
        newnode->fwd = *headp; // Point forward to the old head
        newnode->bwd = NULL;   // There's no node before the new head

        if (*headp != NULL)
            (*headp)->bwd = newnode; // Old head's backward pointer now points to new node
        else
            *tailp = newnode; // List was empty, so this new node is also the tail

        *headp = newnode; // Update the head pointer to the new node
    } else {
        // Inserting in the middle or end of the list
        newnode->fwd = current; // Point new node forward to current
        newnode->bwd = prev;    // Point new node backward to previous node
        prev->fwd = newnode;    // Previous node now points forward to the new node

        if (current != NULL)
            current->bwd = newnode; // If not inserting at end, update next node's back pointer
        else
            *tailp = newnode; // If at end, update tail pointer to new node
    }

    return 1; // Insertion successful
}

