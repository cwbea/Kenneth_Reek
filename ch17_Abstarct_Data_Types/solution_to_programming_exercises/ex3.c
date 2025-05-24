#include <stdio.h>      // For printf()
#include <stdlib.h>     // For malloc() and free()
#include <assert.h>     // For assert()

// Define the type of data to be stored in the queue
// You can change this to float, double, struct, etc. as needed
typedef int QUEUE_TYPE;

// Structure to represent one node in the linked list
typedef struct Node {
    QUEUE_TYPE value;     // Holds the data of the node
    struct Node* next;    // Points to the next node in the list
} Node;

// Pointers to keep track of the front (head) and rear (tail) of the queue
static Node* front = NULL;   // Points to the first element (to be dequeued next)
static Node* rear = NULL;    // Points to the last element (where new data is enqueued)

// Function to check if the queue is empty
// Returns 1 (true) if the queue is empty, 0 (false) otherwise
int is_empty() {
    return front == NULL;
}

// Function to add a value to the end (rear) of the queue
// Takes one argument: the value to be added
void enqueue(QUEUE_TYPE value) {
    // Allocate memory for a new node
    Node* new_node = (Node*)malloc(sizeof(Node));

    // If malloc fails, terminate the program with an error
    assert(new_node != NULL);

    // Assign the given value to the node's value field
    new_node->value = value;

    // Since this is going to be the last node, set its next pointer to NULL
    new_node->next = NULL;

    if (is_empty()) {
        // If the queue is empty, both front and rear point to the new node
        front = rear = new_node;
    } else {
        // Otherwise, link the new node to the end of the current queue
        rear->next = new_node;

        // Update the rear pointer to point to the new last node
        rear = new_node;
    }
}

// Function to remove a value from the front of the queue
// It returns nothing but removes the front element
void dequeue() {
    // If queue is empty, we cannot remove anything
    if (is_empty()) {
        printf("Queue is empty! Cannot dequeue.\n");
        return;
    }

    // Temporary pointer to hold the node that will be removed
    Node* temp = front;

    // Move the front pointer to the next node in the queue
    front = front->next;

    // If the queue becomes empty after the removal, update rear as well
    if (front == NULL) {
        rear = NULL;
    }

    // Free the memory for the removed node
    free(temp);
}

// Function to get the value at the front of the queue without removing it
// Returns the value stored in the front node
QUEUE_TYPE first() {
    // Ensure the queue is not empty before accessing
    assert(!is_empty());

    // Return the value at the front node
    return front->value;
}

// Function to destroy (empty) the entire queue
// It removes and frees every node one by one
void destroy_queue() {
    while (!is_empty()) {
        dequeue();  // Each call removes and frees one node
    }
}

// Main function to demonstrate queue usage
int main() {
    // Add three values to the queue
    enqueue(10);   // Queue: 10
    enqueue(20);   // Queue: 10 -> 20
    enqueue(30);   // Queue: 10 -> 20 -> 30

    // Print the value at the front of the queue (should be 10)
    printf("Front value: %d\n", first());

    // Dequeue all elements and print them one by one
    while (!is_empty()) {
        printf("Dequeuing: %d\n", first());
        dequeue();
    }

    // Try to dequeue from an empty queue to see the error message
    dequeue();

    // Optional cleanup (redundant here since queue is already empty)
    destroy_queue();

    // Return success status
    return 0;
}

