#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int QUEUE_TYPE; // Change this type to store other kinds of data

// Global variables for the queue
static QUEUE_TYPE *queue = NULL; // Pointer to the queue array
static int front = 0;            // Index of the front element
static int rear = 0;             // Index for inserting new elements
static int size = 0;             // Number of elements in the queue
static int capacity = 0;         // Capacity of the queue

// Create a queue with initial capacity
void create_queue(int initial_capacity) {
    assert(initial_capacity > 0);
    queue = (QUEUE_TYPE *)malloc(initial_capacity * sizeof(QUEUE_TYPE));
    assert(queue != NULL);
    capacity = initial_capacity;
    front = 0;
    rear = 0;
    size = 0;
}

// Check if the queue is empty
int is_empty() {
    return size == 0;
}

// Check if the queue is full
int is_full() {
    return size == capacity;
}

// Enqueue: Add value to the rear of the queue
void enqueue(QUEUE_TYPE value) {
    if (is_full()) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }

    queue[rear] = value;
    rear = (rear + 1) % capacity; // Wrap around using modulo
    size++;
}

// Dequeue: Remove value from the front of the queue
void dequeue() {
    if (is_empty()) {
        printf("Queue is empty! Cannot dequeue.\n");
        return;
    }

    front = (front + 1) % capacity;
    size--;
}

// Return the value at the front of the queue
QUEUE_TYPE first() {
    assert(!is_empty());
    return queue[front];
}

// Resize the queue to a new capacity
void resize_queue(int new_capacity) {
    assert(new_capacity > 0);
    
    QUEUE_TYPE *new_queue = (QUEUE_TYPE *)malloc(new_capacity * sizeof(QUEUE_TYPE));
    assert(new_queue != NULL);

    // Copy existing elements to the new queue (in correct order)
    for (int i = 0; i < size; i++) {
        new_queue[i] = queue[(front + i) % capacity];
    }

    free(queue); // Free old queue memory

    queue = new_queue;
    front = 0;
    rear = size;
    capacity = new_capacity;

    printf("Queue resized to capacity %d.\n", capacity);
}

// Destroy the queue and free memory
void destroy_queue() {
    free(queue);
    queue = NULL;
    size = 0;
    front = rear = capacity = 0;
}

// Main function to demonstrate the dynamic queue
int main() {
    // Create a queue with initial capacity of 4
    create_queue(4);

    // Enqueue some values
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    // Queue is full now
    enqueue(50); // Will fail

    // Dequeue two elements
    dequeue();
    dequeue();

    // Enqueue more values
    enqueue(50);
    enqueue(60); // Works because we made space

    // Resize queue to larger size
    resize_queue(8);

    // Enqueue more values
    enqueue(70);
    enqueue(80);

    // Print all values in the queue
    printf("Current queue:\n");
    while (!is_empty()) {
        printf("Dequeuing: %d\n", first());
        dequeue();
    }

    destroy_queue(); // Free the memory
    return 0;
}

