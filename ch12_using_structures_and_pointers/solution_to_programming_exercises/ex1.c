// Define the structure for a node in the singly linked list
typedef struct Node {
    int value;           // The data stored in the node
    struct Node* link;   // Pointer to the next node in the list
} Node;

// Function to count the number of nodes in a singly linked list
int count_nodes(Node* head) {
    int count = 0;           // Initialize a counter to keep track of number of nodes
    Node* current = head;    // Start traversing from the head (first node) of the list

    // Loop through the list until we reach the end (NULL)
    while (current != NULL) {
        count++;                 // Increment count for each node visited
        current = current->link; // Move to the next node in the list
    }

    return count;  // Return the total number of nodes found
}

