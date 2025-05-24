#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list_node.h"

/*
** Function to remove a given node from a singly linked list.
**
** Parameters:
**   rootp - pointer to the pointer to the head of the list
**   node  - pointer to the node that should be removed
**
** Returns:
**   1 (true) if the node was found and removed,
**   0 (false) if the node was not found in the list
*/
int sll_remove(Node **rootp, Node *node) {
    Node *current = *rootp; // Start from the head of the list
    Node *prev = NULL;      // Will keep track of the previous node

    // Traverse the list to find the node to remove
    while (current != NULL) {
        if (current == node) { // We found the node to remove
            if (prev == NULL) {
                // Removing the first node in the list
                *rootp = current->link;
            } else {
                // Bypass the node to remove it from the list
                prev->link = current->link;
            }
            free(current); // Free the memory used by the node
            return 1;      // Node removed successfully
        }

        // Move to the next node
        prev = current;
        current = current->link;
    }

    return 0; // Node was not found in the list
}

// Helper function to create a new node
Node* create_node(int value) {
    Node *newnode = (Node*)malloc(sizeof(Node));
    if (newnode != NULL) {
        newnode->value = value;
        newnode->link = NULL;
    }
    return newnode;
}

// Helper function to print the list
void print_list(Node *head) {
    printf("List: ");
    while (head != NULL) {
        printf("%d -> ", head->value);
        head = head->link;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;

    // Create a simple list: 10 -> 20 -> 30
    Node *n1 = create_node(10);
    Node *n2 = create_node(20);
    Node *n3 = create_node(30);

    head = n1;
    n1->link = n2;
    n2->link = n3;

    printf("Before removal:\n");
    print_list(head);

    // Try to remove node n2 (value 20)
    if (sll_remove(&head, n2)) {
        printf("Node with value 20 removed.\n");
    } else {
        printf("Node not found.\n");
    }

    printf("After removal:\n");
    print_list(head);

    // Clean up remaining nodes
    sll_remove(&head, n1);
    sll_remove(&head, n3);

    return 0;
}

