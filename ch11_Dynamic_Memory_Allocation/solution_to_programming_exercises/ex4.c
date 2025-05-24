#include <stdio.h>     // For printf
#include <stdlib.h>    // For malloc, free

// Define the structure for a linked list node
struct Node {
    int data;              // This holds the integer value
    struct Node *next;     // Pointer to the next node in the list
};

int main() {
    // Declare a pointer to the first node (head of the list)
    struct Node *head;

    // Dynamically allocate memory for the three nodes
    struct Node *node1 = malloc(sizeof(struct Node));  // Allocate first node
    struct Node *node2 = malloc(sizeof(struct Node));  // Allocate second node
    struct Node *node3 = malloc(sizeof(struct Node));  // Allocate third node

    // Check if memory allocation succeeded
    if (node1 == NULL || node2 == NULL || node3 == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Set data for each node and link them
    node1->data = 5;          // First node stores value 5
    node1->next = node2;      // Point to the second node

    node2->data = 10;         // Second node stores value 10
    node2->next = node3;      // Point to the third node

    node3->data = 15;         // Third node stores value 15
    node3->next = NULL;       // End of list

    // Set head to point to the first node
    head = node1;

    // Print the linked list
    printf("Linked list values:\n");
    struct Node *current = head;      // Start at the head of the list
    while (current != NULL) {
        printf("%d\n", current->data); // Print the value in the current node
        current = current->next;       // Move to the next node
    }

    // Free the memory used by the nodes
    free(node1);
    free(node2);
    free(node3);

    return 0;
}

