#include <stdio.h>                         // For printf (optional, for debugging)
#include "singly_linked_list_node.h"       // Include the node structure definition

// Function to reverse a singly linked list
// Takes a pointer to the first node of the list
// Returns a pointer to the new head of the reversed list
Node *sll_reverse(Node *first) {
    Node *prev = NULL;     // Pointer to the previous node; initially set to NULL
    Node *current = first; // Pointer to the current node; starts at the head of the list
    Node *next = NULL;     // Temporary pointer to store the next node

    // Traverse the list and reverse the links one by one
    while (current != NULL) {
        next = current->link;   // Save the next node before breaking the link

        current->link = prev;   // Reverse the link: point current node to the previous one

        prev = current;         // Move prev one step forward (to current)
        current = next;         // Move current one step forward (to original next)
    }

    // When the loop finishes, prev points to the new head of the reversed list
    return prev;
}

