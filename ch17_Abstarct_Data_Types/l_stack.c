/*
** A stack implemented with a linked list.
** This stack has no predefined size limit — it can grow dynamically.
*/

#include "stack.h"     // Stack interface definition
#include <stdio.h>     // Standard I/O (not directly used here)
#include <stdlib.h>    // For malloc and free
#include <assert.h>    // For runtime checks

#define FALSE 0        // Define FALSE as 0 (for clarity in is_full())

/*
** Define a structure to represent each node in the stack.
** Each node holds a value and a pointer to the next node (link).
*/
typedef struct STACK_NODE {
    STACK_TYPE value;            // The value stored in the node
    struct STACK_NODE *next;     // Pointer to the next node (below in the stack)
} StackNode;

/*
** A pointer to the topmost node of the stack.
** This is our main reference to the stack.
*/
static StackNode *stack = NULL;

/*
** create_stack
** Not needed for linked list stacks, but kept for interface consistency.
** Accepts a size parameter, but does nothing in this version.
*/
void create_stack(size_t size)
{
    // No action needed for linked list stack
    (void)size; // Avoid "unused parameter" warning
}

/*
** destroy_stack
** Frees all memory used by the stack.
** Calls pop repeatedly until the stack is empty.
*/
void destroy_stack(void)
{
    while (!is_empty()) {
        pop();  // Remove and free each node
    }
}

/*
** push
** Adds a new value to the top of the stack.
*/
void push(STACK_TYPE value)
{
    StackNode *new_node;

    // Allocate memory for a new stack node
    new_node = malloc(sizeof(StackNode));
    assert(new_node != NULL);  // Ensure memory allocation succeeded

    // Initialize the new node
    new_node->value = value;     // Set its value
    new_node->next = stack;      // Link to the current top of stack

    // Make this new node the new top of the stack
    stack = new_node;
}

/*
** pop
** Removes the top value from the stack and frees its memory.
*/
void pop(void)
{
    StackNode *first_node;

    assert(!is_empty());       // Ensure the stack is not empty

    first_node = stack;        // Save the current top node
    stack = first_node->next;  // Update the top to the next node
    free(first_node);          // Free memory of the old top node
}

/*
** top
** Returns the top value from the stack without removing it.
*/
STACK_TYPE top(void)
{
    assert(!is_empty());         // Ensure the stack is not empty
    return stack->value;         // Return the value at the top
}

/*
** is_empty
** Returns 1 (true) if the stack is empty, otherwise 0 (false).
*/
int is_empty(void)
{
    return stack == NULL;        // Stack is empty if top is NULL
}

/*
** is_full
** A linked list stack is never "full" (unless memory runs out),
** so this always returns FALSE.
*/
int is_full(void)
{
    return FALSE;  // A linked list stack doesn't have a maximum size
}

