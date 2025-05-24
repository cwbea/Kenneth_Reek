#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_SIZE 100  // Maximum number of nodes the tree can hold
#define MAX_QUEUE_SIZE 100 // Maximum number of items in the queue

// ----------------------------
// Queue data structure for holding integer indices (used for BFS)
// ----------------------------

// This structure represents a queue used to store indices of the tree nodes.
// The queue helps us visit nodes level by level (Breadth-First Search).
typedef struct {
    int items[MAX_QUEUE_SIZE]; // Array to hold queue elements (each is an index in the tree)
    int front;  // Index of the front of the queue
    int rear;   // Index of the rear of the queue
} Queue;

// Initialize the queue: this sets it up to be empty initially
// Parameter:
//   q - a pointer to a Queue structure; allows us to modify the queue directly
void init_queue(Queue *q) {
    // Queue *q is a pointer to a Queue object.
    // It gives us access to modify the actual queue instance (not a copy).
    q->front = 0;  // Start of queue
    q->rear = -1;  // Rear is before front when empty
}

// Check if the queue is empty
// Returns 1 (true) if empty, 0 (false) otherwise
int is_empty(Queue *q) {
    return q->front > q->rear;
}

// Add an item to the end (rear) of the queue
void enqueue(Queue *q, int value) {
    if (q->rear < MAX_QUEUE_SIZE - 1) {
        q->rear++;                    // Move rear to next position
        q->items[q->rear] = value;   // Add value at the rear of the queue
    } else {
        printf("Queue overflow!\n"); // Queue is full
    }
}

// Remove and return the item at the front of the queue
int dequeue(Queue *q) {
    if (!is_empty(q)) {
        return q->items[q->front++];  // Return front item and move front forward
    } else {
        printf("Queue underflow!\n"); // Queue is empty
        return -1;
    }
}

// ----------------------------
// Breadth-First Traversal of an Array-Based Binary Tree
// ----------------------------
// This function performs a level-order (breadth-first) traversal of a binary tree
// stored as an array.
// Parameters:
//   tree[] - the array-based binary search tree
//   size   - number of elements currently in the tree
void breadth_first_traversal(int tree[], int size) {
    Queue q;             // Declare a queue to hold node indices during traversal
    init_queue(&q);      // Initialize the queue. '&q' means we're passing the address of q.

    enqueue(&q, 0);      // Start traversal at root node (index 0)

    // Loop while the queue is not empty
    while (!is_empty(&q)) {
        int current = dequeue(&q);  // Get the index of the next node to process

        // Ensure the index is within bounds and the node exists
        if (current >= size || tree[current] == -1) {
            continue;  // Skip if the slot is invalid or empty
        }

        // Print the current node's value
        printf("%d ", tree[current]);

        // Compute and enqueue the left child index: 2*i + 1
        int left_index = 2 * current + 1;
        if (left_index < size && tree[left_index] != -1) {
            enqueue(&q, left_index);
        }

        // Compute and enqueue the right child index: 2*i + 2
        int right_index = 2 * current + 2;
        if (right_index < size && tree[right_index] != -1) {
            enqueue(&q, right_index);
        }
    }

    printf("\n");  // Newline after traversal output
}

// ----------------------------
// Main Function: Entry Point
// ----------------------------
int main() {
    // Manually create a binary search tree in an array
    // Layout:
    //        20
    //       /  \
    //     10    30
    //    / \    / \
    //   5  15  25 35

    int tree[MAX_TREE_SIZE];

    // Fill entire array with -1 (means "empty node")
    for (int i = 0; i < MAX_TREE_SIZE; i++) {
        tree[i] = -1;
    }

    // Manually assign values to build the tree
    tree[0] = 20;
    tree[1] = 10;
    tree[2] = 30;
    tree[3] = 5;
    tree[4] = 15;
    tree[5] = 25;
    tree[6] = 35;

    int size = 7;  // Number of valid tree elements

    // Perform breadth-first traversal
    printf("Breadth-First Traversal of Tree: ");
    breadth_first_traversal(tree, size);

    return 0;  // Exit the program
}

