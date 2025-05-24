#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Define a type for the stack elements (change this for other types)
typedef int STACK_TYPE;

// Global variables to represent the stack
static STACK_TYPE *stack = NULL; // Pointer to the dynamic array
static int top_element = -1;     // Index of the top element
static int stack_size = 0;       // Current capacity of the stack

// Function to create a new stack of given initial size
void create_stack(int initial_size) {
    assert(initial_size > 0); // Ensure size is valid
    stack = (STACK_TYPE *)malloc(initial_size * sizeof(STACK_TYPE));
    assert(stack != NULL);    // Check that memory was successfully allocated
    stack_size = initial_size;
    top_element = -1;         // Stack starts empty
}

// Function to check if the stack is empty
int is_empty() {
    return top_element == -1;
}

// Function to check if the stack is full
int is_full() {
    return top_element == stack_size - 1;
}

// Function to push a value onto the stack
void push(STACK_TYPE value) {
    if (is_full()) {
        printf("Stack full! Cannot push.\n");
        return;
    }
    top_element++;
    stack[top_element] = value;
}

// Function to pop the top value off the stack
void pop() {
    if (is_empty()) {
        printf("Stack empty! Cannot pop.\n");
        return;
    }
    top_element--;
}

// Function to get the top value without removing it
STACK_TYPE top() {
    assert(!is_empty()); // Ensure the stack isn't empty
    return stack[top_element];
}

// Function to resize the stack to a new size
void resize_stack(int new_size) {
    assert(new_size > 0); // Ensure the new size is valid

    // Allocate new memory
    STACK_TYPE *new_stack = (STACK_TYPE *)malloc(new_size * sizeof(STACK_TYPE));
    assert(new_stack != NULL);

    // Copy old data to new stack (up to the smaller of old size or new size)
    int elements_to_copy = (top_element + 1 < new_size) ? (top_element + 1) : new_size;
    for (int i = 0; i < elements_to_copy; i++) {
        new_stack[i] = stack[i];
    }

    // Update top_element if we've shrunk the stack
    if (new_size <= top_element) {
        top_element = new_size - 1;
    }

    // Free old stack and update global pointers
    free(stack);
    stack = new_stack;
    stack_size = new_size;
    printf("Stack resized to %d elements.\n", new_size);
}

// Function to destroy the stack and free memory
void destroy_stack() {
    free(stack);
    stack = NULL;
    stack_size = 0;
    top_element = -1;
}

// Main function to demonstrate stack usage
int main() {
    // Create a stack of size 5
    create_stack(5);

    // Push a few values
    push(10);
    push(20);
    push(30);

    printf("Top of stack: %d\n", top());

    // Resize stack to a larger size
    resize_stack(10);
    push(40);
    push(50);

    // Resize stack to a smaller size
    resize_stack(3);

    // Try pushing after resize
    push(60); // This will fail because the stack is now full

    // Pop and print all values
    while (!is_empty()) {
        printf("Popping: %d\n", top());
        pop();
    }

    // Clean up memory
    destroy_stack();

    return 0;
}

