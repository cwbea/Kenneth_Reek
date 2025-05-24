#include <stdio.h>      // For printf()
#include <stdlib.h>     // For malloc() and free()
#include <assert.h>     // For assert()

#define MAX_STACKS 10   // Maximum number of separate stacks we can manage

// Type of data stored in the stack
typedef int STACK_TYPE;

// Structure to represent one stack
typedef struct {
    STACK_TYPE* data;  // Dynamic array to store stack elements
    int top;           // Index of the top element
    int size;          // Maximum capacity of the stack
} Stack;

// Array to hold up to 10 stacks
static Stack stacks[MAX_STACKS];

// Function to initialize a stack at a specific index
// Parameters:
//   index: the stack number (0 to MAX_STACKS-1)
//   size: how many elements the stack can hold
void initialize_stack(int index, int size) {
    assert(index >= 0 && index < MAX_STACKS);  // Ensure index is valid

    stacks[index].data = (STACK_TYPE*)malloc(sizeof(STACK_TYPE) * size);
    assert(stacks[index].data != NULL);  // Ensure memory allocation succeeded

    stacks[index].top = -1;              // Start with an empty stack
    stacks[index].size = size;
}

// Function to check if a specific stack is empty
int is_empty(int index) {
    return stacks[index].top == -1;
}

// Function to check if a specific stack is full
int is_full(int index) {
    return stacks[index].top == stacks[index].size - 1;
}

// Push a value onto a specific stack
void push(int index, STACK_TYPE value) {
    assert(!is_full(index)); // Make sure stack is not full
    stacks[index].top += 1;  // Move top pointer up
    stacks[index].data[stacks[index].top] = value; // Place value
}

// Pop a value from a specific stack
void pop(int index) {
    assert(!is_empty(index)); // Make sure stack is not empty
    stacks[index].top -= 1;   // Just move the top pointer down
}

// Get the top value of a specific stack without removing it
STACK_TYPE top(int index) {
    assert(!is_empty(index)); // Make sure stack is not empty
    return stacks[index].data[stacks[index].top];
}

// Destroy a specific stack (free memory)
void destroy_stack(int index) {
    free(stacks[index].data);     // Free the array
    stacks[index].data = NULL;    // Nullify pointer to avoid dangling references
    stacks[index].top = -1;       // Reset top
    stacks[index].size = 0;       // Reset size
}

// Main function demonstrating usage of multiple stacks
int main() {
    // Initialize two stacks of different sizes
    initialize_stack(0, 5);   // Stack 0 with capacity 5
    initialize_stack(1, 3);   // Stack 1 with capacity 3

    // Push some values onto stack 0
    push(0, 10);
    push(0, 20);
    push(0, 30);

    // Push some values onto stack 1
    push(1, 100);
    push(1, 200);

    // Pop and print from stack 0
    printf("Stack 0:\n");
    while (!is_empty(0)) {
        printf("Popped from stack 0: %d\n", top(0));
        pop(0);
    }

    // Pop and print from stack 1
    printf("Stack 1:\n");
    while (!is_empty(1)) {
        printf("Popped from stack 1: %d\n", top(1));
        pop(1);
    }

    // Clean up memory
    destroy_stack(0);
    destroy_stack(1);

    return 0;
}

