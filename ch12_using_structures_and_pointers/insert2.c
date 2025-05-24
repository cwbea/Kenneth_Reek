#include <stdlib.h>     // For malloc
#include <stdio.h>      // For printf (optional)
#include "sll_node.h"   // For the Node structure

#define FALSE 0
#define TRUE 1

/*
** Insert into an ordered, singly linked list.
** Arguments:
**   - rootp: a pointer to the pointer to the first node (head of the list)
**   - new_value: the value to insert
** Returns:
**   - TRUE (1) if insertion is successful
**   - FALSE (0) if memory allocation fails
*/
int sll_insert(Node **rootp, int new_value)
{
    Node *current = *rootp;   // Start at the head of the list
    Node *previous = NULL;    // Keep track of the previous node
    Node *new;                // Will point to the new node being inserted

    // Find the correct position to insert the new value
    while (current != NULL && current->value < new_value) {
        previous = current;
        current = current->link;
    }

    // Allocate memory for the new node
    new = (Node *)malloc(sizeof(Node));
    if (new == NULL)
        return FALSE;  // Allocation failed

    new->value = new_value;   // Store the value
    new->link = current;      // Link new node to the rest of the list

    // Insert at the beginning if there's no previous node
    if (previous == NULL)
        *rootp = new;
    else
        previous->link = new;

    return TRUE;  // Insertion successful
}

