// Include standard library for malloc and NULL
#include <stdlib.h>

// Include standard I/O (not actually used in this function, but kept for consistency)
#include <stdio.h>

// Include the definition of the Node structure from your custom header file
#include "dll_node.h"

/*
 * Function: dll_insert
 * --------------------
 * Inserts a new value into an ordered doubly linked list.
 *
 * Parameters:
 *   rootp - A pointer to the root (dummy) node of the list.
 *   value - The integer value to be inserted into the list.
 *
 * Returns:
 *   1  if the value was inserted successfully,
 *   0  if the value is already in the list (no insertion),
 *  -1  if memory allocation for a new node fails.
 */
int dll_insert(Node *rootp, int value)
{
    // 'this' will point to the node currently being checked
    Node *this;

    // 'next' will point to the node that follows 'this'
    Node *next;

    // 'newnode' will point to the newly created node
    Node *newnode;

    /*
     * This loop walks through the list, starting from the root,
     * to find the correct place to insert the new value.
     * It stops if the value already exists, or if we find where it should go.
     */
    for (this = rootp; (next = this->fwd) != NULL; this = next) {
        // If the next node already has the value, don't insert and return 0
        if (next->value == value)
            return 0;

        // If the next node's value is greater, we found the insert position
        if (next->value > value)
            break;
    }

    // Allocate memory for a new node
    newnode = (Node *)malloc(sizeof(Node));

    // If malloc fails, return -1 to indicate memory error
    if (newnode == NULL)
        return -1;

    // Store the value to be inserted in the new node
    newnode->value = value;

    /*
     * If we are not at the end of the list, we are inserting in the middle or front.
     * Set the new node’s forward link to point to the next node in the list.
     * Also update the backward link of the next node to point back to the new node.
     */
    if (next != NULL) {
        newnode->fwd = next;      // New node's forward pointer = next
        next->bwd = newnode;      // Next node's backward pointer = new node

        // If we're not inserting at the very front of the list
        if (this != rootp) {
            this->fwd = newnode;  // Link the previous node to the new node
            newnode->bwd = this;  // New node's backward pointer = previous node
        } else {
            // We're inserting at the front of the list (after root)
            rootp->fwd = newnode; // Root's forward pointer = new node
            newnode->bwd = NULL;  // New node is now the first real node (no backward link)
        }
    }
    /*
     * If 'next' is NULL, we've reached the end of the list.
     * We insert the new node at the end.
     */
    else {
        newnode->fwd = NULL;       // New node has no next node (it's the last)

        rootp->bwd = newnode;      // Root's backward pointer = new node (last node in list)

        // If the list has other elements
        if (this != rootp) {
            this->fwd = newnode;   // Previous node's forward pointer = new node
            newnode->bwd = this;   // New node's backward pointer = previous node
        } else {
            // The list is empty (only root node exists)
            rootp->fwd = newnode;  // Root's forward pointer = new node
            newnode->bwd = NULL;   // New node is first and only element
        }
    }

    // Return 1 to indicate successful insertion
    return 1;
}

