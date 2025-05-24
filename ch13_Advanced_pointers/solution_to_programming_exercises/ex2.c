#include <stdio.h>    // For printf
#include <stdlib.h>   // For malloc and free

// Define a Node structure for a singly linked list
typedef struct Node {
    void *data;            // A generic pointer to data stored in the node
    struct Node *next;     // Pointer to the next node in the list
} Node;

// Define a function pointer type for a callback function
// It takes a pointer to a Node and returns nothing (void)
typedef void (*NodeCallback)(Node *node);

// Function to traverse the list and apply the callback to each node
void traverse_list(Node *head, NodeCallback callback) {
    Node *current = head;  // Start from the head node

    // Loop through all nodes until current is NULL (end of list)
    while (current != NULL) {
        callback(current);       // Call the user-supplied function on the node
        current = current->next; // Move to the next node
    }
}

// Sample callback function that prints the data in each node
void print_node(Node *node) {
    // We assume that node->data points to an integer
    int *value = (int *)(node->data);  // Cast void* back to int*
    printf("Node data: %d\n", *value); // Print the integer value
}

int main() {
    // Create some integer values to store in the list
    int *a = malloc(sizeof(int));
    int *b = malloc(sizeof(int));
    int *c = malloc(sizeof(int));
    *a = 10;
    *b = 20;
    *c = 30;

    // Dynamically allocate nodes for the list
    Node *node3 = malloc(sizeof(Node));  // Last node
    Node *node2 = malloc(sizeof(Node));  // Middle node
    Node *node1 = malloc(sizeof(Node));  // Head node

    // Set up node3
    node3->data = c;      // Store pointer to int 30
    node3->next = NULL;   // No next node (end of list)

    // Set up node2
    node2->data = b;      // Store pointer to int 20
    node2->next = node3;  // Point to node3

    // Set up node1
    node1->data = a;      // Store pointer to int 10
    node1->next = node2;  // Point to node2

    // Traverse the list and apply the callback to each node
    traverse_list(node1, print_node);

    // Free all dynamically allocated memory
    free(a);
    free(b);
    free(c);
    free(node1);
    free(node2);
    free(node3);

    return 0; // Exit the program
}




/*  What the traversal function needs to know about the nodes:
Requirement	Why?
next pointer	To move from one node to the next.
Node type	To correctly pass the node to the callback.
Data not required	The traversal function doesn’t care what's inside — only the callback does. */
