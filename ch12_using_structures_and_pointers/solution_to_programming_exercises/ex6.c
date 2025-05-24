#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list_node.h" // Include the node structure definition

// Function to remove a node from a doubly linked list
// rootp is a pointer to the node containing the root pointers for the list (head/tail)
// node is a pointer to the node that we need to remove
// Returns 1 if the node is successfully removed, or 0 if the node was not found
int dll_remove(Node **rootp, Node *node) {
    // Check if the list is empty (i.e., rootp or node is NULL)
    if (*rootp == NULL || node == NULL) {
        return 0; // List is empty or node is NULL, so we cannot remove anything
    }

    // If the node to be removed is the first node
    if (node == *rootp) {
        // If there's a node after the one being removed
        if (node->fwd != NULL) {
            node->fwd->bwd = NULL; // Set the backward link of the next node to NULL
            *rootp = node->fwd;    // Update the root pointer to the next node
        }
        else {
            *rootp = NULL;         // If there was no next node, the list becomes empty
        }
    }
    // If the node to be removed is not the first node (middle or last node)
    else {
        if (node->fwd != NULL) {
            node->fwd->bwd = node->bwd; // Set the backward link of the next node
        }
        if (node->bwd != NULL) {
            node->bwd->fwd = node->fwd; // Set the forward link of the previous node
        }
    }

    // Free the memory allocated for the node that is being removed
    free(node);

    return 1; // Successfully removed the node
}

// Function to print the list for debugging purposes
void print_list(Node *root) {
    Node *current = root;
    while (current != NULL) {
        printf("%d <-> ", current->value);
        current = current->fwd;
    }
    printf("NULL\n");
}

int main() {
    Node *root = NULL; // Initialize the list to be empty

    // Create and insert nodes (using malloc to allocate memory)
    Node *node1 = (Node *)malloc(sizeof(Node));
    node1->value = 10;
    node1->fwd = NULL;
    node1->bwd = NULL;

    Node *node2 = (Node *)malloc(sizeof(Node));
    node2->value = 20;
    node2->fwd = NULL;
    node2->bwd = node1;

    Node *node3 = (Node *)malloc(sizeof(Node));
    node3->value = 30;
    node3->fwd = NULL;
    node3->bwd = node2;

    // Connect the nodes to form a doubly linked list
    node1->fwd = node2;
    node2->fwd = node3;

    // Set the root pointer to the first node
    root = node1;

    // Print the list before removing a node
    printf("Original list:\n");
    print_list(root);

    // Remove node2 (the node with value 20)
    dll_remove(&root, node2);

    // Print the list after removing a node
    printf("List after removing node with value 20:\n");
    print_list(root);

    // Free remaining nodes
    free(node1);
    free(node3);

    return 0; // Return 0 to indicate successful execution
}

